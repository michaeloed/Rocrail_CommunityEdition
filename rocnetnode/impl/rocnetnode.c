/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 


 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/trace.h"
#include "rocs/public/doc.h"
#include "rocs/public/node.h"
#include "rocs/public/thread.h"
#include "rocs/public/file.h"
#include "rocs/public/mem.h"
#include "rocs/public/str.h"
#include "rocs/public/strtok.h"
#include "rocs/public/cmdln.h"
#include "rocs/public/stats.h"
#include "rocs/public/system.h"
#include "rocs/public/lib.h"

#include "rocrail/wrapper/public/Cmdline.h"
#include "rocrail/wrapper/public/ConCmd.h"
#include "rocrail/wrapper/public/RocNet.h"
#include "rocrail/wrapper/public/PortSetup.h"
#include "rocrail/wrapper/public/ChannelSetup.h"
#include "rocrail/wrapper/public/RocNetNodeOptions.h"
#include "rocrail/wrapper/public/Trace.h"
#include "rocrail/wrapper/public/DigInt.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/FunCmd.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/Program.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Macro.h"
#include "rocrail/wrapper/public/MacroLine.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/Output.h"

#include "rocnetnode/impl/rocnetnode_impl.h"

#include "rocint/public/digint.h"

#include "rocdigs/impl/rocnet/rocnet-const.h"
#include "rocdigs/impl/rocnet/rn-utils.h"

#include "rocnetnode/public/io.h"
#include "rocnetnode/public/i2c.h"
#include "rocnetnode/public/ip.h"

#include "common/version.h"

#define ROCNETNODEINI "rocnetnode.ini"

static int instCnt = 0;

/*
 * LED1: GPIO 23, normal operation
 * LED2: GPIO 24, alert
 * PB1 : GPIO 25, identify
 */

typedef iIDigInt (* LPFNROCGETDIGINT)( const iONode ,const iOTrace );

static void __sendRN( iORocNetNode rocnetnode, byte* rn );
static iONode __findPort(iORocNetNode inst, int port);
static void __initI2C(iORocNetNode inst, int iotype);
static void __initI2CPWM(iORocNetNode inst);
static void __writePort(iORocNetNode rocnetnode, int port, int value, int iotype);
static void __writeChannel(iORocNetNode rocnetnode, int channel, int value);
static int __readPort(iORocNetNode rocnetnode, int port, int iotype);
static void __saveIni(iORocNetNode rocnetnode);
static void __initControl(iORocNetNode inst);
static void __initIO(iORocNetNode rocnetnode);
static iONode __findMacro(iORocNetNode inst, int nr);
static Boolean __initDigInt(iORocNetNode inst);
static void __unloadDigInt(iORocNetNode inst, int prevcstype);
static void __errorReport( iORocNetNode inst, int rc, int rs, int addr);
static iONode __findChannel(iORocNetNode inst, int channel);
static int __checkI2C(iORocNetNode inst, int group);
static void __initThreads(iORocNetNode inst);


/** ----- OBase ----- */
static void __del( void* inst ) {
  if( inst != NULL ) {
    iORocNetNodeData data = Data(inst);
    /* Cleanup data->xxx members...*/
    
    freeMem( data );
    freeMem( inst );
    instCnt--;
  }
  return;
}

static const char* __name( void ) {
  return name;
}

static unsigned char* __serialize( void* inst, long* size ) {
  return NULL;
}

static void __deserialize( void* inst,unsigned char* bytestream ) {
  return;
}

static char* __toString( void* inst ) {
  return NULL;
}

static int __count( void ) {
  return instCnt;
}

static struct OBase* __clone( void* inst ) {
  return NULL;
}

static Boolean __equals( void* inst1, void* inst2 ) {
  return False;
}

static void* __properties( void* inst ) {
  return NULL;
}

static const char* __id( void* inst ) {
  return NULL;
}

static void* __event( void* inst, const void* evt ) {
  return NULL;
}

/** ----- ORocNetNode ----- */

static Boolean bShutdown = False;
static iORocNetNode __RocNetNode = NULL;

static Boolean __isThis( iORocNetNode rocnetnode, byte* rn ) {
  iORocNetNodeData data = Data(rocnetnode);
  return (rnSenderAddrFromPacket(rn, 0) == data->id);
}

static byte* __handleClock( iORocNetNode rocnetnode, byte* rn ) {
  iORocNetNodeData data       = Data(rocnetnode);
  int rcpt       = 0;
  int sndr       = 0;
  int action     = rnActionFromPacket(rn);
  int actionType = rnActionTypeFromPacket(rn);
  byte* msg = NULL;

  rcpt = rnReceipientAddrFromPacket(rn, 0);
  sndr = rnSenderAddrFromPacket(rn, 0);

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Clock request %d from %d to %d", action, sndr, rcpt );

  switch( action ) {
    case RN_CLOCK_SET:
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
          "Clock set to %02d:%02d divider=%d", rn[RN_PACKET_DATA + 4], rn[RN_PACKET_DATA + 5], rn[RN_PACKET_DATA + 7] );
      break;
    case RN_CLOCK_SYNC:
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
          "Clock sync to %02d:%02d divider=%d", rn[RN_PACKET_DATA + 4], rn[RN_PACKET_DATA + 5], rn[RN_PACKET_DATA + 7] );
      break;
  }

  return msg;
}


static byte* __handleDisplay( iORocNetNode rocnetnode, byte* rn ) {
  iORocNetNodeData data       = Data(rocnetnode);
  int rcpt       = 0;
  int sndr       = 0;
  int action     = rnActionFromPacket(rn);
  int actionType = rnActionTypeFromPacket(rn);
  byte* msg = NULL;

  rcpt = rnReceipientAddrFromPacket(rn, 0);
  sndr = rnSenderAddrFromPacket(rn, 0);

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Display request %d from %d to %d", action, sndr, rcpt );

  switch( action ) {
    case RN_DISPLAY_TEXT:
    {
      const char* text = (const char*)&rn[RN_PACKET_DATA + 2];
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Display %d:%d set to [%s]",
          rn[RN_PACKET_DATA + 0], rn[RN_PACKET_DATA + 1], text );
      MutexOp.wait( data->i2cmux );
      raspiWriteRegArrayI2C(data->i2cdescriptor, rn[RN_PACKET_DATA + 0], rn[RN_PACKET_DATA + 1], text, StrOp.len(text) );
      MutexOp.post( data->i2cmux );
    }
    break;
  }

  return msg;
}


static byte* __handleMobile( iORocNetNode rocnetnode, byte* rn ) {
  iORocNetNodeData data       = Data(rocnetnode);
  int rcpt       = 0;
  int sndr       = 0;
  int action     = rnActionFromPacket(rn);
  int actionType = rnActionTypeFromPacket(rn);
  byte* msg = NULL;
  int i = 0;

  iONode rocnet = NodeOp.findNode(data->ini, wRocNet.name());
  iONode optionsini = NodeOp.findNode(rocnet, wRocNetNodeOptions.name());

  rcpt = rnReceipientAddrFromPacket(rn, 0);
  sndr = rnSenderAddrFromPacket(rn, 0);

  if( actionType == RN_ACTIONTYPE_EVENT ) {
    return NULL;
  }

  switch( action ) {
    case RN_MOBILE_VELOCITY:
      if( data->id == rcpt ) {
        data->Vraw  = rn[RN_PACKET_DATA + 0];
        data->Vdir  = rn[RN_PACKET_DATA + 1]?True:False;
        data->fn[0] = rn[RN_PACKET_DATA + 2]?True:False;
        data->Vmass = rn[RN_PACKET_DATA + 3];
        data->Vmax  = rn[RN_PACKET_DATA + 4];
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "mobile V=%d dir=%d lights=%d", data->Vraw, data->Vdir, data->fn[0] );
        /* always acknowledge */
        msg = allocMem(128);
        msg[RN_PACKET_NETID] = data->location;
        msg[RN_PACKET_GROUP] = RN_GROUP_MOBILE;
        rnSenderAddresToPacket( data->id, msg, 0 );
        msg[RN_PACKET_ACTION] = RN_MOBILE_VELOCITY;
        msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
        msg[RN_PACKET_LEN] = rn[RN_PACKET_LEN];
        MemOp.copy(msg+RN_PACKET_DATA, rn+RN_PACKET_DATA, rn[RN_PACKET_LEN]);
      }
      break;

    case RN_MOBILE_FUNCTIONS:
      if( data->id == rcpt ) {
        data->fchanged = rn[RN_PACKET_DATA + 3];
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "mobile fchanged=%d", data->fchanged );
        for( i = 0; i < 8; i++ ) {
          data->fn[i+1] = (rn[RN_PACKET_DATA + 0] & (1 << i)) ? True:False;
          data->fn[i+8+1] = (rn[RN_PACKET_DATA + 1] & (1 << i)) ? True:False;
          data->fn[i+16+1] = (rn[RN_PACKET_DATA + 2] & (1 << i)) ? True:False;
        }
        if( data->fchanged > 0 && data->fchanged <= 16 && data->channels[data->fchanged] != NULL ) {
          data->channels[data->fchanged]->state = data->fn[data->fchanged] ? 1:0;
          data->channels[data->fchanged]->blink = data->fn[data->fchanged] ? True:False;
          data->channels[data->fchanged]->ready = False;
          data->channels[data->fchanged]->sleep = False;
          data->channels[data->fchanged]->idle  = 0;
        }

        /* always acknowledge */
        msg = allocMem(128);
        msg[RN_PACKET_NETID] = data->location;
        msg[RN_PACKET_GROUP] = RN_GROUP_MOBILE;
        rnSenderAddresToPacket( data->id, msg, 0 );
        msg[RN_PACKET_ACTION] = RN_MOBILE_FUNCTIONS;
        msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
        msg[RN_PACKET_LEN] = rn[RN_PACKET_LEN];
        MemOp.copy(msg+RN_PACKET_DATA, rn+RN_PACKET_DATA, rn[RN_PACKET_LEN]);
      }
      break;

    case RN_MOBILE_ROCMOUSE_BIND:
    {
      int mouseaddr = rn[RN_PACKET_DATA + 0];
      int lcaddr = rn[RN_PACKET_DATA + 1] * 256 + rn[RN_PACKET_DATA + 2];
      int idx = 0;
      for( idx = 0; idx < 8; idx++) {
        if( data->rocmouses[idx] != NULL && data->rocmouses[idx]->ioaddr == mouseaddr ) {
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "bind RocMouse 0x%02X to loco %d", mouseaddr, lcaddr );
          data->rocmouses[idx]->lcaddr = lcaddr;
        }
      }
    }
    break;
  }

  return msg;
}


static byte* __handleSound( iORocNetNode rocnetnode, byte* rn ) {
  iORocNetNodeData data       = Data(rocnetnode);
  int rcpt       = 0;
  int sndr       = 0;
  int action     = rnActionFromPacket(rn);
  int actionType = rnActionTypeFromPacket(rn);
  byte* msg = NULL;

  iONode rocnet = NodeOp.findNode(data->ini, wRocNet.name());
  iONode optionsini = NodeOp.findNode(rocnet, wRocNetNodeOptions.name());

  rcpt = rnReceipientAddrFromPacket(rn, 0);
  sndr = rnSenderAddrFromPacket(rn, 0);

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Sound request %d from %d to %d", action, sndr, rcpt );

  switch( action ) {
    case RN_SOUND_PLAY:
    {
      char soundfile[128] = {'\0'};
      int i = 0;
      for( i = 0; i < rn[RN_PACKET_LEN]; i++ ) {
        soundfile[i] = rn[RN_PACKET_DATA + i];
      }
      soundfile[i] = '\0';
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Play sound [%s]", soundfile );

      if( optionsini != NULL ) {
        const char* soundpath   = wRocNetNodeOptions.getsoundpath(optionsini);
        const char* soundplayer = wRocNetNodeOptions.getsoundplayer(optionsini);
        /* play */
        char* s = StrOp.fmt("%s \"%s%c%s\"", soundplayer, soundpath, SystemOp.getFileSeparator(), soundfile );
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "executing [%s]", s );
        SystemOp.system( s, True, False );
        StrOp.free(s);
      }

      break;
    }
  }

  return msg;
}


static byte* __handleCS( iORocNetNode rocnetnode, byte* rn ) {
  iORocNetNodeData data       = Data(rocnetnode);
  int rcpt       = 0;
  int sndr       = 0;
  int action     = rnActionFromPacket(rn);
  int actionType = rnActionTypeFromPacket(rn);
  byte* msg = NULL;
  int addr = 0;
  int V = 0;
  int dir = 0;
  int lights = 0;
  int prot = 0;
  int spcnt = 0;
  int i = 0;

  rcpt = rnReceipientAddrFromPacket(rn, 0);
  sndr = rnSenderAddrFromPacket(rn, 0);

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
      "CS %s %d from %d to %d", (actionType == RN_ACTIONTYPE_EVENT)?"event":"request", action, sndr, rcpt );

  switch( action ) {
    case RN_CS_TRACKPOWER:
      if( actionType == RN_ACTIONTYPE_EVENT ) {
        break;
      }
      if( (rn[RN_PACKET_DATA + 0] & 0x01) == 0x00) {
        /* save at power off to persistent the output state */
        __saveIni(rocnetnode);
      }

      if(data->cstype > 0 && data->pDI != NULL) {
        iONode cmd = NodeOp.inst( wSysCmd.name(), NULL, ELEMENT_NODE);
        wSysCmd.setcmd(cmd, rn[RN_PACKET_DATA + 0] & 0x01 ? wSysCmd.go:wSysCmd.stop);
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "CS track power %s", rn[RN_PACKET_DATA + 0] & 0x01 ? "ON":"OFF" );
        data->pDI->cmd( (obj)data->pDI, cmd );
        data->power = rn[RN_PACKET_DATA + 0] & 0x01 ? True:False;
        msg = allocMem(128);
        msg[RN_PACKET_NETID] = data->location;
        msg[RN_PACKET_GROUP] = RN_GROUP_CS;
        rnSenderAddresToPacket( data->id, msg, 0 );
        msg[RN_PACKET_ACTION] = RN_CS_TRACKPOWER;
        msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
        msg[RN_PACKET_LEN] = 1;
        msg[RN_PACKET_DATA + 0] = data->power;
      }
      break;

    case RN_CS_POM:
      if(data->cstype > 0 && data->pDI != NULL) {
        iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE);
        int cv = rn[RN_PACKET_DATA + 2] * 256 + rn[RN_PACKET_DATA + 3];
        addr = rn[RN_PACKET_DATA + 0] * 256 + rn[RN_PACKET_DATA + 1];
        wProgram.setaddr(cmd, addr);
        wProgram.setlongaddr(cmd, addr > 127 ? True:False);
        wProgram.setcv(cmd, cv );
        wProgram.setvalue(cmd, rn[RN_PACKET_DATA + 4]);
        wProgram.setpom(cmd, True);
        wProgram.setcmd(cmd, rn[RN_PACKET_DATA + 5] == 0 ? wProgram.get:wProgram.set );
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
            "CS POM %s loco=%d cv=%d value=%d", rn[RN_PACKET_DATA + 5] == 0 ? "read":"write" ,addr, cv, rn[RN_PACKET_DATA + 4] );
        data->pDI->cmd( (obj)data->pDI, cmd );
      }
      break;

    case RN_CS_VELOCITY:
      if(data->cstype > 0 && data->pDI != NULL) {
        addr = rn[RN_PACKET_DATA + 0] * 256 + rn[RN_PACKET_DATA + 1];
        V = rn[RN_PACKET_DATA + 2];
        dir = rn[RN_PACKET_DATA + 3];
        lights = rn[RN_PACKET_DATA + 4];
        prot = rn[RN_PACKET_DATA + 5];
        spcnt = rn[RN_PACKET_DATA + 6];
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "loco bus=%d addr=%d V=%d dir=%d lights=%d spcnt=%d", rcpt, addr, V, dir, lights, spcnt );
        if(data->pDI != NULL) {
          iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE);
          wLoc.setaddr(cmd, addr);
          wLoc.setV(cmd, V);
          wLoc.setspcnt(cmd, spcnt);
          wLoc.setdir(cmd, dir);
          wLoc.setfn(cmd, lights);
          data->pDI->cmd( (obj)data->pDI, cmd );
        }
      }
      break;

    case RN_CS_FUNCTION:
      if(data->cstype > 0 && data->pDI != NULL) {
        addr = rn[RN_PACKET_DATA + 0] * 256 + rn[RN_PACKET_DATA + 1];
        if(data->pDI != NULL) {
          iONode cmd = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE);
          int fnchanged = rn[RN_PACKET_DATA + 6] & 0x7F;
          Boolean lights = (rn[RN_PACKET_DATA + 6] & 0x80 ? True:False);
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
              "loco function bus=%d addr=%d lights=%d fnchanged=%d", rcpt, addr, lights, fnchanged );
          wFunCmd.setaddr(cmd, addr);
          wFunCmd.setf0(cmd, lights);
          for( i = 0; i < 8; i++ ) {
            char key[32];
            StrOp.fmtb(key, "f%d", i+1);
            NodeOp.setBool(cmd, key, (rn[RN_PACKET_DATA + 2] & (1 << i)) ? True:False);
          }
          for( i = 0; i < 8; i++ ) {
            char key[32];
            StrOp.fmtb(key, "f%d", i+9);
            NodeOp.setBool(cmd, key, (rn[RN_PACKET_DATA + 3] & (1 << i)) ? True:False);
          }
          for( i = 0; i < 8; i++ ) {
            char key[32];
            StrOp.fmtb(key, "f%d", i+17);
            NodeOp.setBool(cmd, key, (rn[RN_PACKET_DATA + 4] & (1 << i)) ? True:False);
          }
          wFunCmd.setfnchanged(cmd, fnchanged);
          wFunCmd.setgroup(cmd, fnchanged/4 + 1);
          data->pDI->cmd( (obj)data->pDI, cmd );
        }
      }
      break;

    case RN_CS_SWITCH:
      if(data->cstype > 0 && data->pDI != NULL) {
        iONode cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE);
        wSwitch.setaddr1( cmd, rn[RN_PACKET_DATA + 3]);
        wSwitch.setcmd( cmd, rn[RN_PACKET_DATA + 0] == 1 ? wSwitch.turnout:wSwitch.straight);
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "CS switch %d %s", wSwitch.getaddr1(cmd), wSwitch.getcmd(cmd) );
        data->pDI->cmd( (obj)data->pDI, cmd );
      }
      break;

    case RN_CS_OUTPUT:
      if(data->cstype > 0 && data->pDI != NULL) {
        iONode cmd = NodeOp.inst( wOutput.name(), NULL, ELEMENT_NODE);
        wOutput.setaddr( cmd, rn[RN_PACKET_DATA + 3]);
        wOutput.setcmd( cmd, rn[RN_PACKET_DATA + 0] == 1 ? wOutput.on:wOutput.off);
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "CS output %d %s", wOutput.getaddr(cmd), wOutput.getcmd(cmd) );
        data->pDI->cmd( (obj)data->pDI, cmd );
      }
      break;

  }

  return msg;
}

static void __saveIni(iORocNetNode rocnetnode) {
  iORocNetNodeData data = Data(rocnetnode);
  iONode rocnet = NodeOp.findNode(data->ini, wRocNet.name());
  iOFile iniFile = NULL;

  int i = 0;

  if( rocnet == NULL ) {
    rocnet = NodeOp.inst(wRocNet.name(), data->ini, ELEMENT_NODE);
    NodeOp.addChild( data->ini, rocnet );
  }
  wRocNet.setid(rocnet, data->id);
  wRocNet.setnet(rocnet, data->location);

  for( i = 0; i < 129; i++ ) {
    if( data->ports[i] != NULL && (data->ports[i]->type&IO_TYPE) == 0 ) {
      iONode portsetup = __findPort(rocnetnode, i);
      if( portsetup != NULL ) {
        wPortSetup.setstate(portsetup, data->ports[i]->state);
      }
    }
    if( data->channels[i] != NULL ) {
      iONode channelsetup = __findChannel(rocnetnode, i);
      if( channelsetup != NULL ) {
        wChannelSetup.setstate(channelsetup, data->channels[i]->state);
      }
    }
  }

  for( i = 1; i < 129; i++ ) {
    if( data->macro[i] != NULL ) {
      iONode macro = __findMacro(rocnetnode, i);
      if( macro == NULL ) {
        macro = NodeOp.inst(wMacro.name(), data->ini, ELEMENT_NODE);
        wMacro.setnr(macro, i);
        NodeOp.addChild(data->ini, macro);
      }
      if( macro != NULL ) {
        int n = 0;
        for( n = 0; n < 8; n++ ) {
          iONode line = wMacro.getmacroline(macro);
          if( line != NULL )
            NodeOp.removeChild(macro, line);
        }
        for( n = 0; n < 8; n++ ) {
          if( data->macro[i]->line[n].port > 0 ) {
            iONode line = NodeOp.inst(wMacroLine.name(), macro, ELEMENT_NODE);
            NodeOp.addChild(macro, line);
            wMacroLine.setport(line, data->macro[i]->line[n].port);
            wMacroLine.setporttype(line, data->macro[i]->line[n].type);
            wMacroLine.setdelay(line, data->macro[i]->line[n].delay);
            wMacroLine.setstatus(line, data->macro[i]->line[n].value);
            wMacroLine.setblink(line, data->macro[i]->line[n].blink);
          }
        }
      }
    }
  }


  TraceOp.setLevel( NULL, TraceOp.getLevel( NULL ) & ~TRCLEVEL_INFO );
  if( data->tl_info )
    TraceOp.setLevel( NULL, TraceOp.getLevel( NULL ) | TRCLEVEL_INFO );

  TraceOp.setLevel( NULL, TraceOp.getLevel( NULL ) & ~TRCLEVEL_MONITOR );
  if( data->tl_monitor )
    TraceOp.setLevel( NULL, TraceOp.getLevel( NULL ) | TRCLEVEL_MONITOR );

  if( NodeOp.findNode(data->ini, wTrace.name()) == NULL ) {
    iONode traceini = NodeOp.inst(wTrace.name(), data->ini, ELEMENT_NODE);
    NodeOp.addChild(data->ini, traceini);
  }

  if( NodeOp.findNode(data->ini, wTrace.name()) != NULL ) {
    iONode traceini = NodeOp.findNode(data->ini, wTrace.name());
    wTrace.setinfo(traceini, TraceOp.getLevel( NULL ) & TRCLEVEL_INFO );
    wTrace.setmonitor(traceini, TraceOp.getLevel( NULL ) & TRCLEVEL_MONITOR );
  }

  /* backup existing ini: */
  if( FileOp.exist(data->inifile) && FileOp.fileSize(data->inifile) > 0 ) {
    char* backupfile = StrOp.fmt( "%s.bak", data->inifile );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "backing up %s to %s...", data->inifile, backupfile );
    if( FileOp.exist(backupfile) )
      FileOp.remove( backupfile );
    FileOp.rename( data->inifile, backupfile );
    StrOp.free( backupfile );
  }

  iniFile = FileOp.inst( data->inifile, OPEN_WRITE );
  if( iniFile != NULL ) {
    char* iniStr = NodeOp.base.toString( data->ini );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "saving ini %s...", data->inifile );
    FileOp.write( iniFile, iniStr, StrOp.len( iniStr ) );
    FileOp.flush( iniFile );
    FileOp.close( iniFile );
    FileOp.base.del(iniFile);
    StrOp.free(iniStr);
  }
}


static byte* __handlePTStationary( iORocNetNode rocnetnode, byte* rn ) {
  iORocNetNodeData data       = Data(rocnetnode);
  int port       = rn[RN_PACKET_DATA + 3];
  int rcpt       = 0;
  int sndr       = 0;
  int action     = rnActionFromPacket(rn);
  int actionType = rnActionTypeFromPacket(rn);
  Boolean isThis = __isThis( rocnetnode, rn);
  byte* msg = NULL;
  int i = 0;
  int from = 0;
  int to = 0;
  int idx = 0;

  rcpt = rnReceipientAddrFromPacket(rn, 0);
  sndr = rnSenderAddrFromPacket(rn, 0);

  switch( action ) {
  case RN_PROGRAMMING_WRNID:
    if( rcpt != data->id || (rn[RN_PACKET_LEN] > 2 &&  rn[RN_PACKET_DATA+2] != data->ip[data->ipsize-2]) || rn[RN_PACKET_DATA+3] != data->ip[data->ipsize-1] )
    {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "new ID %d not for me", rn[RN_PACKET_DATA + 0] * 256 + rn[RN_PACKET_DATA + 1] );
      break;
    }

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "new ID %d Location %d for me", rn[RN_PACKET_DATA + 0] * 256 + rn[RN_PACKET_DATA + 1], rn[RN_PACKET_DATA + 4] );
    msg = allocMem(128);
    msg[RN_PACKET_NETID] = data->location;
    msg[RN_PACKET_GROUP] = RN_GROUP_STATIONARY;
    rnReceipientAddresToPacket( 0, msg, 0 );
    rnSenderAddresToPacket( data->id, msg, 0 );
    msg[RN_PACKET_ACTION] = RN_STATIONARY_SHUTDOWN;
    msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
    msg[RN_PACKET_LEN] = 0;

    data->id = rn[RN_PACKET_DATA + 0] * 256 + rn[RN_PACKET_DATA + 1];
    data->location = rn[RN_PACKET_DATA + 4];
    if( data->id < 2 ) {
      data->id = 65535;
    }

    if( rn[RN_PACKET_LEN] > 5 ) {
      iONode rocnet = NodeOp.findNode(data->ini, wRocNet.name());
      iONode optionsini = NodeOp.findNode(rocnet, wRocNetNodeOptions.name());
      int i = 0;
      for( i = 0; i < (rn[RN_PACKET_LEN] - 5); i++ ) {
        data->nickname[i] = rn[RN_PACKET_DATA + 5 + i];
      }
      data->nickname[i] = '\0';
      wRocNetNodeOptions.setnickname( optionsini, data->nickname );
    }

    /* Save the rocnetnode.ini to persistent the new ID. */
    {
      iONode rocnet = NodeOp.findNode(data->ini, wRocNet.name());
      wRocNet.setid(rocnet, data->id);
      __saveIni(rocnetnode);
    }
    data->identack = False;
    break;

  case RN_PROGRAMMING_WMACRO:
  {
    int i = 0;
    int nr = rn[RN_PACKET_DATA+0];
    iOMacro macro = data->macro[nr];
    if( macro == NULL ) {
      data->macro[nr] = allocMem(sizeof(struct Macro));
      macro = data->macro[nr];
    }

    for( i = 0; i < 8; i++ ) {
      macro->line[i].port  = rn[RN_PACKET_DATA+1+i*4];
      macro->line[i].delay = rn[RN_PACKET_DATA+2+i*4];
      macro->line[i].type  = (rn[RN_PACKET_DATA+3+i*4]&IO_TYPE);
      macro->line[i].blink = ((rn[RN_PACKET_DATA+3+i*4]&IO_BLINK)?True:False);
      macro->line[i].value = rn[RN_PACKET_DATA+4+i*4];
    }
    __saveIni(rocnetnode);
  }
  break;

  case RN_PROGRAMMING_RMACRO:
  {
    int i = 0;
    int nr = rn[RN_PACKET_DATA+0];
    iOMacro macro = data->macro[nr];
    if( macro == NULL ) {
      data->macro[nr] = allocMem(sizeof(struct Macro));
      macro = data->macro[nr];
    }

    msg = allocMem(128);
    msg[RN_PACKET_NETID] = data->location;
    msg[RN_PACKET_GROUP] = RN_GROUP_PT_STATIONARY;
    rnReceipientAddresToPacket( sndr, msg, 0 );
    rnSenderAddresToPacket( data->id, msg, 0 );
    msg[RN_PACKET_ACTION] = RN_PROGRAMMING_RMACRO;
    msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
    msg[RN_PACKET_LEN] = 1 + 8*4;
    msg[RN_PACKET_DATA+0] = nr;
    for( i = 0; i < 8; i++ ) {
      msg[RN_PACKET_DATA+1+i*4] = macro->line[i].port ;
      msg[RN_PACKET_DATA+2+i*4] = macro->line[i].delay;
      msg[RN_PACKET_DATA+3+i*4] = macro->line[i].type + (macro->line[i].blink?IO_BLINK:0x00);
      msg[RN_PACKET_DATA+4+i*4] = macro->line[i].value;
    }
  }
  break;

  case RN_PROGRAMMING_WPORT:
  {
    iONode rocnet = NodeOp.findNode(data->ini, wRocNet.name());
    int i = 0;

    if( rocnet == NULL ) {
      rocnet = NodeOp.inst( wRocNet.name(), data->ini, ELEMENT_NODE);
      NodeOp.addChild( data->ini, rocnet );
    }

    for( i = 0; i < 8; i++ ) {
      int port  = rn[RN_PACKET_DATA+0+i*4];
      int res   = rn[RN_PACKET_DATA+1+i*4];
      int type  = rn[RN_PACKET_DATA+2+i*4];
      int delay = rn[RN_PACKET_DATA+3+i*4];
      iONode portsetup = __findPort(rocnetnode, port);
      if( portsetup == NULL ) {
        portsetup = NodeOp.inst( wPortSetup.name(), rocnet, ELEMENT_NODE);
        wPortSetup.setport( portsetup, port);
        NodeOp.addChild( rocnet, portsetup );
      }
      wPortSetup.settype( portsetup, type);
      wPortSetup.setdelay( portsetup, delay);
    }
    __saveIni(rocnetnode);
    __initIO(rocnetnode);
  }
  break;

  case RN_PROGRAMMING_SETCHANNEL:
  {
    int channel = rn[RN_PACKET_DATA+0];
    int pos     = rn[RN_PACKET_DATA+1]*256 + rn[RN_PACKET_DATA+2];
    int type    = rn[RN_PACKET_DATA+3];
    if( channel < 129 && data->channels[channel] != NULL ) {
      data->channels[channel]->ready = False;
      data->channels[channel]->sleep = False;
      data->channels[channel]->idle  = 0;
      if( type == 0 ) {
        data->channels[channel]->offpos = pos;
        data->channels[channel]->state  = 0;
      }
      else {
        data->channels[channel]->onpos = pos;
        data->channels[channel]->state  = 1;
      }
    }
  }
  break;

  case RN_PROGRAMMING_WCHANNEL:
  {
    iONode rocnet = NodeOp.findNode(data->ini, wRocNet.name());
    int i = 0;

    if( rocnet == NULL ) {
      rocnet = NodeOp.inst( wRocNet.name(), data->ini, ELEMENT_NODE);
      NodeOp.addChild( data->ini, rocnet );
    }

    for( i = 0; i < 8; i++ ) {
      int channel    = rn[RN_PACKET_DATA+0+i*8];
      int offpos   = rn[RN_PACKET_DATA+1+i*8]*256 + rn[RN_PACKET_DATA+2+i*8];
      int onpos    = rn[RN_PACKET_DATA+3+i*8]*256 + rn[RN_PACKET_DATA+4+i*8];
      int offsteps = rn[RN_PACKET_DATA+5+i*8];
      int onsteps  = rn[RN_PACKET_DATA+6+i*8];
      int options  = rn[RN_PACKET_DATA+7+i*8];
      iONode channelsetup = __findChannel(rocnetnode, channel);
      if( channelsetup == NULL ) {
        channelsetup = NodeOp.inst( wChannelSetup.name(), rocnet, ELEMENT_NODE);
        wChannelSetup.setchannel( channelsetup, channel);
        NodeOp.addChild( rocnet, channelsetup );
      }
      wChannelSetup.setoffpos( channelsetup, offpos);
      wChannelSetup.setonpos( channelsetup, onpos);
      wChannelSetup.setoffsteps( channelsetup, offsteps);
      wChannelSetup.setonsteps( channelsetup, onsteps);
      wChannelSetup.setoptions( channelsetup, options);
    }
    __saveIni(rocnetnode);
    __initIO(rocnetnode);
  }
  break;

  case RN_PROGRAMMING_RMPORT:
  {
    iONode rocnet = NodeOp.findNode(data->ini, wRocNet.name());
    int i = 0;

    if( rocnet == NULL ) {
      rocnet = NodeOp.inst( wRocNet.name(), data->ini, ELEMENT_NODE);
      NodeOp.addChild( data->ini, rocnet );
    }

    for( i = 0; i < 8; i++ ) {
      int port  = rn[RN_PACKET_DATA+0+i];
      iONode portsetup = __findPort(rocnetnode, port);
      if( portsetup != NULL ) {
        iOPort portdef = data->ports[port];
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "removing port %d", port);
        NodeOp.removeChild( rocnet, portsetup );
        NodeOp.base.del(portsetup);

        if( portdef != NULL ) {
          data->ports[port] = NULL;
          freeMem(portdef);
        }
      }
    }
    __saveIni(rocnetnode);
    __initIO(rocnetnode);
  }
  break;

  case RN_PROGRAMMING_RMCHANNEL:
  {
    iONode rocnet = NodeOp.findNode(data->ini, wRocNet.name());
    int i = 0;

    if( rocnet == NULL ) {
      rocnet = NodeOp.inst( wRocNet.name(), data->ini, ELEMENT_NODE);
      NodeOp.addChild( data->ini, rocnet );
    }

    for( i = 0; i < 8; i++ ) {
      int channel  = rn[RN_PACKET_DATA+0+i];
      iONode channelsetup = __findChannel(rocnetnode, channel);
      if( channelsetup != NULL ) {
        iOChannel channeldef = data->channels[channel];
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "removing channel %d", channel);
        NodeOp.removeChild( rocnet, channelsetup );
        NodeOp.base.del(channelsetup);

        if( channeldef != NULL ) {
          data->channels[channel] = NULL;
          freeMem(channeldef);
        }
      }
    }
    __saveIni(rocnetnode);
    __initIO(rocnetnode);
  }
  break;

  case RN_PROGRAMMING_WPORTEVENT:
  {
    iONode rocnet = NodeOp.findNode(data->ini, wRocNet.name());
    int i = 0;

    if( rocnet == NULL ) {
      rocnet = NodeOp.inst( wRocNet.name(), data->ini, ELEMENT_NODE);
      NodeOp.addChild( data->ini, rocnet );
    }

    for( i = 0; i < 8; i++ ) {
      int port  = rn[RN_PACKET_DATA+0+i*4];
      int eventid = rn[RN_PACKET_DATA+1+i*4]*256+rn[RN_PACKET_DATA+2+i*4];
      int eventport = rn[RN_PACKET_DATA+3+i*4];
      iONode portsetup = __findPort(rocnetnode, port);
      if( portsetup == NULL ) {
        portsetup = NodeOp.inst( wPortSetup.name(), rocnet, ELEMENT_NODE);
        wPortSetup.setport( portsetup, port);
        NodeOp.addChild( rocnet, portsetup );
      }
      wPortSetup.seteventid( portsetup, eventid);
      wPortSetup.seteventport( portsetup, eventport);

      if( data->ports[port] != NULL ) {
        data->ports[port]->eventid= eventid;
        data->ports[port]->eventport= eventport;
      }

    }
    __saveIni(rocnetnode);
  }
  break;

  case RN_PROGRAMMING_RPORT:
    from = rn[RN_PACKET_DATA+0];
    to   = rn[RN_PACKET_DATA+1];
    if( from > to ) {
      from = rn[RN_PACKET_DATA+1];
      to   = rn[RN_PACKET_DATA+0];
    }
    if( to - from > 7 ) {
      to = from + 7;
    }

    msg = allocMem(128);
    msg[RN_PACKET_NETID] = data->location;
    msg[RN_PACKET_GROUP] = RN_GROUP_PT_STATIONARY;
    rnReceipientAddresToPacket( sndr, msg, 0 );
    rnSenderAddresToPacket( data->id, msg, 0 );
    msg[RN_PACKET_ACTION] = RN_PROGRAMMING_RPORT;
    msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
    msg[RN_PACKET_LEN] = ((to-from)+1)*4;
    for( i = from; i <= to; i++ ) {
      if( data->ports[i] != NULL ) {
        msg[RN_PACKET_DATA + 0 + idx * 4] = i;
        msg[RN_PACKET_DATA + 1 + idx * 4] = data->ports[i]->state;
        msg[RN_PACKET_DATA + 2 + idx * 4] = data->ports[i]->type;
        msg[RN_PACKET_DATA + 3 + idx * 4] = data->ports[i]->delay;
      }
      idx++;
    }
    break;

  case RN_PROGRAMMING_RCHANNEL:
    from = rn[RN_PACKET_DATA+0];
    to   = rn[RN_PACKET_DATA+1];
    if( from > to ) {
      from = rn[RN_PACKET_DATA+1];
      to   = rn[RN_PACKET_DATA+0];
    }
    if( to - from > 7 ) {
      to = from + 7;
    }

    msg = allocMem(128);
    msg[RN_PACKET_NETID] = data->location;
    msg[RN_PACKET_GROUP] = RN_GROUP_PT_STATIONARY;
    rnReceipientAddresToPacket( sndr, msg, 0 );
    rnSenderAddresToPacket( data->id, msg, 0 );
    msg[RN_PACKET_ACTION] = RN_PROGRAMMING_RCHANNEL;
    msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
    msg[RN_PACKET_LEN] = ((to-from)+1)*8;
    for( i = from; i <= to; i++ ) {
      if( data->channels[i] != NULL ) {
        msg[RN_PACKET_DATA + 0 + idx * 8] = i;
        msg[RN_PACKET_DATA + 1 + idx * 8] = data->channels[i]->offpos/256;
        msg[RN_PACKET_DATA + 2 + idx * 8] = data->channels[i]->offpos%256;
        msg[RN_PACKET_DATA + 3 + idx * 8] = data->channels[i]->onpos/256;
        msg[RN_PACKET_DATA + 4 + idx * 8] = data->channels[i]->onpos%256;
        msg[RN_PACKET_DATA + 5 + idx * 8] = data->channels[i]->offsteps;
        msg[RN_PACKET_DATA + 6 + idx * 8] = data->channels[i]->onsteps;
        msg[RN_PACKET_DATA + 7 + idx * 8] = data->channels[i]->options;
      }
      idx++;
    }
    break;

  case RN_PROGRAMMING_RPORTEVENT:
    from = rn[RN_PACKET_DATA+0];
    to   = rn[RN_PACKET_DATA+1];
    if( from > to ) {
      from = rn[RN_PACKET_DATA+1];
      to   = rn[RN_PACKET_DATA+0];
    }
    if( to - from > 7 ) {
      to = from + 7;
    }

    msg = allocMem(128);
    msg[RN_PACKET_NETID] = data->location;
    msg[RN_PACKET_GROUP] = RN_GROUP_PT_STATIONARY;
    rnReceipientAddresToPacket( sndr, msg, 0 );
    rnSenderAddresToPacket( data->id, msg, 0 );
    msg[RN_PACKET_ACTION] = RN_PROGRAMMING_RPORTEVENT;
    msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
    msg[RN_PACKET_LEN] = ((to-from)+1)*4;
    for( i = from; i <= to; i++ ) {
      if( data->ports[i] != NULL ) {
        msg[RN_PACKET_DATA + 0 + idx * 4] = i;
        msg[RN_PACKET_DATA + 1 + idx * 4] = data->ports[i]->eventid/256;
        msg[RN_PACKET_DATA + 2 + idx * 4] = data->ports[i]->eventid%256;
        msg[RN_PACKET_DATA + 3 + idx * 4] = data->ports[i]->eventport;
      }
      idx++;
    }
    break;

  case RN_PROGRAMMING_UPDATE:
    RocNetNodeOp.sysUpdate( rn[RN_PACKET_DATA + 0] * 256 + rn[RN_PACKET_DATA + 1], rn[RN_PACKET_DATA + 2] );
    break;

  case RN_PROGRAMMING_RDOPT:
  {
    int i2ccheck = 0;
    msg = allocMem(128);
    msg[RN_PACKET_NETID] = data->location;
    msg[RN_PACKET_GROUP] = RN_GROUP_PT_STATIONARY;
    rnReceipientAddresToPacket( sndr, msg, 0 );
    rnSenderAddresToPacket( data->id, msg, 0 );
    msg[RN_PACKET_ACTION] = RN_PROGRAMMING_RDOPT;
    msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
    msg[RN_PACKET_LEN] = 11;
    msg[RN_PACKET_DATA + 0] = data->iotype;
    msg[RN_PACKET_DATA + 1] = (data->sack ? 0x01:0x00) | (data->rfid ? 0x02:0x00) | (data->usepb ? 0x04:0x00) | (data->adcsensor ? 0x08:0x00);
    msg[RN_PACKET_DATA + 1] |= (data->tl_info ? 0x10:0x00) | (data->tl_monitor ? 0x20:0x00) | (data->ismobile ? 0x40:0x00);
    msg[RN_PACKET_DATA + 2] = data->cstype;
    msg[RN_PACKET_DATA + 3] = data->csdevice;
    i2ccheck = __checkI2C(rocnetnode, 0x20);
    msg[RN_PACKET_DATA + 4] = (i2ccheck/256)&0xFF;
    msg[RN_PACKET_DATA + 5] = (i2ccheck%256)&0xFF;
    i2ccheck = __checkI2C(rocnetnode, 0x30);
    msg[RN_PACKET_DATA + 6] = (i2ccheck/256)&0xFF;
    msg[RN_PACKET_DATA + 7] = (i2ccheck%256)&0xFF;
    i2ccheck = __checkI2C(rocnetnode, 0x40);
    msg[RN_PACKET_DATA + 8] = (i2ccheck/256)&0xFF;
    msg[RN_PACKET_DATA + 9] = (i2ccheck%256)&0xFF;
    msg[RN_PACKET_DATA + 10] = data->adcthreshold&0xFF;
  }
  break;

  case RN_PROGRAMMING_WROPT:
  {
    int i2ccheck = 0;
    int prevcstype = data->csdevice;
    data->iotype = rn[RN_PACKET_DATA + 0];
    data->sack   = (rn[RN_PACKET_DATA + 1] & 0x01) ? True:False;
    data->rfid   = (rn[RN_PACKET_DATA + 1] & 0x02) ? True:False;
    data->adcsensor = (rn[RN_PACKET_DATA + 1] & 0x08) ? True:False;
    data->adcthreshold = rn[RN_PACKET_DATA + 4];
    data->ismobile = (rn[RN_PACKET_DATA + 1] & 0x40) ? True:False;
    data->usepb = (rn[RN_PACKET_DATA + 1] & 0x04) ? True:False;
    data->tl_info = (rn[RN_PACKET_DATA + 1] & 0x10) ? True:False;
    data->tl_monitor = (rn[RN_PACKET_DATA + 1] & 0x20) ? True:False;
    data->cstype   = rn[RN_PACKET_DATA + 2];
    data->csdevice = rn[RN_PACKET_DATA + 3];
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "options: iotype=%d cstype=%d csdevice=%d", data->iotype, data->cstype, data->csdevice );
    msg = allocMem(128);
    msg[RN_PACKET_NETID] = data->location;
    msg[RN_PACKET_GROUP] = RN_GROUP_PT_STATIONARY;
    rnReceipientAddresToPacket( sndr, msg, 0 );
    rnSenderAddresToPacket( data->id, msg, 0 );
    msg[RN_PACKET_ACTION] = RN_PROGRAMMING_WROPT;
    msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
    msg[RN_PACKET_LEN] = 5;
    msg[RN_PACKET_DATA + 0] = data->iotype;
    msg[RN_PACKET_DATA + 1] = (data->sack ? 0x01:0x00) | (data->rfid ? 0x02:0x00) | (data->usepb ? 0x04:0x00) | (data->adcsensor ? 0x08:0x00);
    msg[RN_PACKET_DATA + 1] |= (data->tl_info ? 0x10:0x00) | (data->tl_monitor ? 0x20:0x00) | (data->ismobile ? 0x40:0x00);
    msg[RN_PACKET_DATA + 2] = data->cstype;
    msg[RN_PACKET_DATA + 3] = data->csdevice;
    i2ccheck = __checkI2C(rocnetnode, 0x20);
    msg[RN_PACKET_DATA + 4] = (i2ccheck/256)&0xFF;
    msg[RN_PACKET_DATA + 5] = (i2ccheck%256)&0xFF;
    i2ccheck = __checkI2C(rocnetnode, 0x30);
    msg[RN_PACKET_DATA + 6] = (i2ccheck/256)&0xFF;
    msg[RN_PACKET_DATA + 7] = (i2ccheck%256)&0xFF;
    i2ccheck = __checkI2C(rocnetnode, 0x40);
    msg[RN_PACKET_DATA + 8] = (i2ccheck/256)&0xFF;
    msg[RN_PACKET_DATA + 9] = (i2ccheck%256)&0xFF;
    msg[RN_PACKET_DATA + 10] = data->adcthreshold;
    /* Save the rocnetnode.ini to persistent the new ID. */
    {
      iONode rocnet = NodeOp.findNode(data->ini, wRocNet.name());
      iONode optionsini = NodeOp.findNode(rocnet, wRocNetNodeOptions.name());

      if( wRocNetNodeOptions.getiotype(optionsini) != data->iotype )
        __initIO(rocnetnode);

      wRocNetNodeOptions.setiotype( optionsini, data->iotype );
      wRocNetNodeOptions.setsack( optionsini, data->sack );
      wRocNetNodeOptions.setrfid( optionsini, data->rfid );
      wRocNetNodeOptions.setadcsensor( optionsini, data->adcsensor );
      wRocNetNodeOptions.setadcthreshold( optionsini, data->adcthreshold );
      wRocNetNodeOptions.setmobile( optionsini, data->ismobile );
      wRocNetNodeOptions.setusepb( optionsini, data->usepb );
      wRocNetNodeOptions.setnickname( optionsini, data->nickname );

      if( !data->rfid || data->cstype !=  prevcstype ) {
        __unloadDigInt(rocnetnode, prevcstype);
        if( data->cstype == 0 && data->digintini != NULL ) {
          NodeOp.removeChild(data->ini, data->digintini );
          NodeOp.base.del(data->digintini);
          data->digintini = NULL;
        }
      }

      if( data->cstype > 0) {
        if( data->digintini == NULL ) {
          data->digintini = NodeOp.inst(wDigInt.name(), data->ini, ELEMENT_NODE);
          NodeOp.addChild(data->ini, data->digintini);
        }

        wDigInt.setiid(data->digintini, "dcc");

        if( data->cstype==1 )
          wDigInt.setlib(data->digintini, wDigInt.dcc232);
        else if( data->cstype==2 )
          wDigInt.setlib(data->digintini, wDigInt.sprog);

        if( data->csdevice==1 )
          wDigInt.setdevice(data->digintini, "/dev/ttyUSB1");
        else if( data->csdevice==2 )
          wDigInt.setdevice(data->digintini, "/dev/ttyACM0");
        else
          wDigInt.setdevice(data->digintini, "/dev/ttyUSB0");

        __initDigInt(rocnetnode);
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
            "%s: lib=%s device=%s", wDigInt.getiid(data->digintini), wDigInt.getlib(data->digintini), wDigInt.getdevice(data->digintini) );
      }
    }
    __saveIni(rocnetnode);
    __initThreads(rocnetnode);
  }
  break;


  }

  return msg;
}


static void _sysHalt(void) {
  iORocNetNodeData data = Data(__RocNetNode);
  TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "shutdown the system...");
  SystemOp.system("halt -p", True, True);
}


static void _sysUpdate(int revision, int offline) {
  iORocNetNodeData data = Data(__RocNetNode);
  char cmd[256] = {'\0'};
  TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "update the software to revision %d...", revision);
  StrOp.fmtb(cmd, "nohup /opt/rocnet/update%s.sh %d &", offline?"-offline":"", revision );
  SystemOp.system(cmd, True, True);
}


static void __macro(iORocNetNode rocnetnode, int macro, Boolean on, int offset) {
  iORocNetNodeData data = Data(rocnetnode);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "macro %d %s", macro, on?"ON":"OFF");
  if( offset > 0 )
    offset--;
  if( on && data->macro[macro] != NULL ) {
    int i = 0;
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "processing macro %d %s offset=%d", macro, on?"ON":"OFF", offset);
    for( i = 0; i < 8; i++ ) {
      if( data->macro[macro]->line[i].port > 0) {
        int port = data->macro[macro]->line[i].port;
        port += offset;

        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
            "processing macro line %d port=%d type=%d delay=%d value=%d blink=%d", i,
            data->macro[macro]->line[i].port, data->macro[macro]->line[i].type&IO_TYPE,
            data->macro[macro]->line[i].delay, data->macro[macro]->line[i].value, data->macro[macro]->line[i].blink);

        if((data->macro[macro]->line[i].type&IO_TYPE) == 0) {
          if( on && data->macro[macro]->line[i].blink ) {
            if( data->ports[port] != NULL ) {
              data->ports[port]->type |= IO_BLINK;
              data->ports[port]->offtimer = SystemOp.getTick();
              data->ports[port]->delay = data->macro[macro]->line[i].delay;
            }
          }
          else {
            if( data->ports[port] != NULL ) {
              data->ports[port]->type &= IO_TYPE;
              data->ports[port]->delay = 0;
              ThreadOp.sleep( data->macro[macro]->line[i].delay * 10);
            }
          }
        }

        if( (data->macro[macro]->line[i].type&IO_TYPE) == 0 && data->ports[port] != NULL ) {
          __writePort( rocnetnode, port, data->macro[macro]->line[i].value, 2);
          data->ports[port]->state = (data->macro[macro]->line[i].value);
        }
        else if( (data->macro[macro]->line[i].type&IO_TYPE) == 2 && data->channels[port] != NULL) {
          int pos = (data->macro[macro]->line[i].value ? data->channels[port]->onpos:data->channels[port]->offpos);
          if( data->macro[macro]->line[i].value > 1 ) {
              data->channels[port]->onpos = data->macro[macro]->line[i].value * 16;
          }
          ThreadOp.sleep( data->macro[macro]->line[i].delay * 10);
          data->channels[port]->ready = False;
          data->channels[port]->sleep = False;
          data->channels[port]->idle  = 0;
          data->channels[port]->state = (data->macro[macro]->line[i].value?1:0);
        }
      }

    }
  }

}

static void __macroProcessor( void* threadinst ) {
  iOThread         th         = (iOThread)threadinst;
  iORocNetNode     rocnetnode = (iORocNetNode)ThreadOp.getParm( th );
  iORocNetNodeData data       = Data(rocnetnode);

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "macroProcessor started");
  do {
    byte* post = (byte*)ThreadOp.getPost( th );

    if (post != NULL) {
      __macro(rocnetnode, post[0], post[1], post[2]);
      freeMem( post);
    }
    ThreadOp.sleep(10);
  } while(data->run);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "macroProcessor ended");

}


static byte* __handleStationary( iORocNetNode rocnetnode, byte* rn ) {
  iORocNetNodeData data       = Data(rocnetnode);
  int port       = rn[RN_PACKET_DATA + 3];
  int rcpt       = 0;
  int sndr       = 0;
  int action     = rnActionFromPacket(rn);
  int actionType = rnActionTypeFromPacket(rn);
  Boolean isThis = __isThis( rocnetnode, rn);
  byte* msg = NULL;

  rcpt = rnReceipientAddrFromPacket(rn, 0);
  sndr = rnSenderAddrFromPacket(rn, 0);

  if( actionType == RN_ACTIONTYPE_EVENT ) {
    /* ignore */
    return NULL;
  }

  switch( action ) {
  case RN_STATIONARY_ACK:
    if( rn[RN_PACKET_DATA + 0] == RN_STATIONARY_IDENTIFY ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "queryids acknowleged from %d to %d", sndr, rcpt );
      data->identack = True;
      data->startofday = True;
    }
    else if( rn[RN_PACKET_DATA + 0] == RN_SENSOR_REPORT ) {
      int port = rn[RN_PACKET_DATA + 1];
      if( port < 128 && data->ports[port] != NULL ) {
        data->ports[port]->acktimer = 0;
        data->ports[port]->ackretry = 0;
        data->ports[port]->ackpending = False;
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "sensor %d acknowleged from %d to %d", port, sndr, rcpt );
      }
    }
    else if( rn[RN_PACKET_DATA + 0] == RN_SENSORID_REPORT ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "sensorID acknowleged from %d to %d", sndr, rcpt );
      data->rfidAck = True;
      data->rfidAckRetry = 0;
    }
    break;

  case RN_STATIONARY_IDENTIFY:
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "queryids request from %d to %d", sndr, rcpt );
    msg = allocMem(128);
    msg[RN_PACKET_NETID] = data->location;
    msg[RN_PACKET_GROUP] = RN_GROUP_STATIONARY;
    rnReceipientAddresToPacket( sndr, msg, 0 );
    rnSenderAddresToPacket( data->id, msg, 0 );
    msg[RN_PACKET_ACTION] = RN_STATIONARY_IDENTIFY;
    msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
    msg[RN_PACKET_LEN] = 7 + StrOp.len(data->nickname);
    msg[RN_PACKET_DATA+0] = data->class;
    msg[RN_PACKET_DATA+1] = 70;
    msg[RN_PACKET_DATA+2] = revisionnr/256;
    msg[RN_PACKET_DATA+3] = revisionnr%256;
    msg[RN_PACKET_DATA+4] = 128;
    msg[RN_PACKET_DATA+5] = data->ip[data->ipsize-2];
    msg[RN_PACKET_DATA+6] = data->ip[data->ipsize-1];
    StrOp.copy((char*)&msg[RN_PACKET_DATA+7], data->nickname);
    break;

  case RN_STATIONARY_STARTOFDAY:
    data->startofday = True;
    data->adcstartofday = True;
    break;

  case RN_STATIONARY_SHUTDOWN:
    if( rn[RN_PACKET_LEN] > 0 && rn[RN_PACKET_DATA+0] == 1 ) {
      RocNetNodeOp.sysHalt();
    }
    break;

  case RN_STATIONARY_SHOW:
    /* Flash LED. */
    if( data->show )
      data->show = False;
    else {
      data->LED2timer = 0;
      data->show = True;
    }
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "show LED2 %s", data->show?"on":"off" );
    break;

  }
  return msg;
}

static byte* __handleOutput( iORocNetNode rocnetnode, byte* rn ) {
  iORocNetNodeData data       = Data(rocnetnode);
  int port       = rn[RN_PACKET_DATA + 3];
  int offset     = rn[RN_PACKET_DATA + 4];
  int rcpt       = 0;
  int sndr       = 0;
  int action     = rnActionFromPacket(rn);
  int actionType = rnActionTypeFromPacket(rn);
  Boolean isThis = __isThis( rocnetnode, rn);
  byte* msg = NULL;

  rcpt = rnReceipientAddrFromPacket(rn, 0);
  sndr = rnSenderAddrFromPacket(rn, 0);

  if( actionType == RN_ACTIONTYPE_EVENT ) {
    return NULL;
  }

  switch( action ) {
  case RN_OUTPUT_SWITCH:
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "output SWITCH(%s) port=%d type=%d %s action for %d%s from %d, %d data bytes",
        rnActionTypeString(rn), port, rn[RN_PACKET_DATA + 1], rn[RN_PACKET_DATA + 0] & RN_OUTPUT_ON ? "on":"off",
        rcpt, isThis?"(this)":"", sndr, rn[RN_PACKET_LEN] );
    if( rn[RN_PACKET_DATA + 1] == wProgram.porttype_macro ) {
      byte* post = allocMem(128);
      post[0] = port;
      post[1] = ((rn[RN_PACKET_DATA + 0] & RN_OUTPUT_ON) ?1:0);
      post[2] = offset;
      ThreadOp.post(data->macroprocessor, (obj)post);
    }
    else if( rn[RN_PACKET_DATA + 1] == wProgram.porttype_servo ) {
      if( port < 129 && data->channels[port] != NULL ) {
        data->channels[port]->state = (rn[RN_PACKET_DATA + 0] & RN_OUTPUT_ON) ? 1:0;
        data->channels[port]->blink = (rn[RN_PACKET_DATA + 0] & RN_OUTPUT_ON) ? True:False;
        data->channels[port]->ready = False;
        data->channels[port]->sleep = False;
        data->channels[port]->porttype = rn[RN_PACKET_DATA + 1];
        data->channels[port]->idle  = 0;
      }
    }
    else if( rn[RN_PACKET_DATA + 1] == wProgram.porttype_light ) {
      if( port < 129 && data->channels[port] != NULL ) {
        int brightness = rn[RN_PACKET_DATA + 2] * 16;
        data->channels[port]->state = (rn[RN_PACKET_DATA + 0] & RN_OUTPUT_ON) ? 1:0;
        data->channels[port]->blink = (rn[RN_PACKET_DATA + 0] & RN_OUTPUT_ON) ? True:False;
        data->channels[port]->ready = False;
        data->channels[port]->sleep = False;
        data->channels[port]->onpos = brightness;
        data->channels[port]->offpos = 0;
        data->channels[port]->porttype = rn[RN_PACKET_DATA + 1];
        data->channels[port]->idle  = 0;
      }
    }
    else {
      if( port < 129 && data->ports[port] != NULL ) {
        if( rn[RN_PACKET_DATA + 0] & RN_OUTPUT_ON ) {
          data->ports[port]->offtimer = SystemOp.getTick();
          data->ports[port]->state = 1;
        }
        else {
          data->ports[port]->offtimer = 0;
          data->ports[port]->state = 0;
        }
      }
      if(data->ports[port] != NULL) {
        __writePort(rocnetnode, port, rn[RN_PACKET_DATA + 0] & RN_OUTPUT_ON ? 1:0, data->ports[port]->iotype);

        msg = allocMem(128);
        msg[RN_PACKET_NETID] = data->location;
        msg[RN_PACKET_GROUP] = RN_GROUP_OUTPUT;
        rnReceipientAddresToPacket( 0, msg, 0 );
        rnSenderAddresToPacket( data->id, msg, 0 );
        msg[RN_PACKET_ACTION] = RN_OUTPUT_SWITCH;
        msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
        msg[RN_PACKET_LEN] = 4;
        msg[RN_PACKET_DATA + 0] = rn[RN_PACKET_DATA + 0] & RN_OUTPUT_ON ? 1:0;
        msg[RN_PACKET_DATA + 1] = 0;
        msg[RN_PACKET_DATA + 2] = 0;
        msg[RN_PACKET_DATA + 3] = port;
      }
    }
  break;

  default:
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "unsupported action [%d]", action );
    break;
  }

  return msg;
}


static void __sendRN( iORocNetNode rocnetnode, byte* rn ) {
  iORocNetNodeData data = Data(rocnetnode);
  int rcpt = rnReceipientAddrFromPacket(rn, 0);
  char* str = StrOp.byteToStr(rn, 8 + rn[RN_PACKET_LEN]);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "write %s [%s] to %d", rnActionTypeString(rn), str, rcpt );
  StrOp.free(str);
  SocketOp.sendto( data->writeUDP, (char*)rn, 8 + rn[RN_PACKET_LEN], NULL, 0 );

}


static void __checkPortEvents( iORocNetNode rocnetnode, byte* rn ) {
  iORocNetNodeData data = Data(rocnetnode);
  int group     = rn[RN_PACKET_GROUP];
  int eventidA  = rnSenderAddrFromPacket(rn, 0);
  int eventidB  = rnReceipientAddrFromPacket(rn, 0);
  int eventport = 0;
  int eventval  = 0;

  switch( group ) {
    case RN_GROUP_OUTPUT:
      eventval  = rn[RN_PACKET_DATA + 0];
      eventport = rn[RN_PACKET_DATA + 3];
      break;
    case RN_GROUP_SENSOR:
      eventval  = rn[RN_PACKET_DATA + 2];
      eventport = rn[RN_PACKET_DATA + 3];
      break;
  }

  if( (eventidA > 0 || eventidB > 0) && eventport > 0 ) {
    int i = 0;
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "event: id=%d,%d port=%d val=%d", eventidA, eventidB, eventport, eventval );
    for( i = 0; i < 129; i++ ) {
      if( data->ports[i] != NULL  && data->ports[i]->eventid > 0 && data->ports[i]->eventid > 0 ) {
        if( data->ports[i]->type == IO_OUTPUT &&
            (data->ports[i]->eventid == eventidA || data->ports[i]->eventid == eventidB) && data->ports[i]->eventport == eventport )
        {
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "match port %d event: id=%d port=%d val=%d", i, data->ports[i]->eventid, eventport, eventval );
          __writePort(rocnetnode, i, eventval, data->ports[i]->iotype);
        }
      }
    }
  }

}


static void __evaluateRN( iORocNetNode rocnetnode, byte* rn ) {
  iORocNetNodeData data = Data(rocnetnode);
  int group = rn[RN_PACKET_GROUP];
  byte* rnReply = NULL;
  int action = rnActionFromPacket(rn);
  int actionType = rnActionTypeFromPacket(rn);
  Boolean isThis = __isThis( rocnetnode, rn);
  byte* msg = NULL;

  int rcpt = rnReceipientAddrFromPacket(rn, 0);
  int sndr = rnSenderAddrFromPacket(rn, 0);

  if( isThis ) {
    char* str = StrOp.byteToStr(rn, 8 + rn[RN_PACKET_LEN]);
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "ignore %s [%s] from %d(self) to %d", rnActionTypeString(rn), str, sndr, rcpt );
    StrOp.free(str);
    return;
  }
  else if(rcpt != data->id && rcpt != 0) {
    char* str = StrOp.byteToStr(rn, 8 + rn[RN_PACKET_LEN]);
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "ignore %s [%s] from %d to %d; address does not match", rnActionTypeString(rn), str, sndr, rcpt );
    StrOp.free(str);
    __checkPortEvents(rocnetnode, rn);
    return;
  }
  else {
    char* str = StrOp.byteToStr(rn, 8 + rn[RN_PACKET_LEN]);
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "evaluate %s [%s] from %d to %d", rnActionTypeString(rn), str, sndr, rcpt );
    StrOp.free(str);
  }

  if(rcpt != data->id && rcpt == 0) {
    __checkPortEvents(rocnetnode, rn);
  }

  TraceOp.dump ( name, TRCLEVEL_BYTE, (char*)rn, 8 + rn[RN_PACKET_LEN] );

  switch( group ) {
    case RN_GROUP_HOST:
      if( action == RN_HOST_SHUTDOWN ) {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "host shutdown from %d to %d", sndr, rcpt );
        data->identack = False;
      }
      else if( action == RN_HOST_PING ) {
        rnReply = allocMem(128);
        rnReply[RN_PACKET_NETID] = data->location;
        rnReply[RN_PACKET_GROUP] = RN_GROUP_HOST;
        rnReceipientAddresToPacket( 0, rnReply, 0 );
        rnSenderAddresToPacket( data->id, rnReply, 0 );
        rnReply[RN_PACKET_ACTION] = RN_HOST_PONG;
        rnReply[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
        rnReply[RN_PACKET_LEN] = 0;
      }
      break;

    case RN_GROUP_STATIONARY:
      rnReply = __handleStationary( rocnetnode, rn );
      break;

    case RN_GROUP_PT_STATIONARY:
      rnReply = __handlePTStationary( rocnetnode, rn );
      break;

    case RN_GROUP_OUTPUT:
      rnReply = __handleOutput( rocnetnode, rn );
      break;

    case RN_GROUP_INPUT:
      break;

    case RN_GROUP_CS:
      rnReply = __handleCS( rocnetnode, rn );
      break;

    case RN_GROUP_CLOCK:
      rnReply = __handleClock( rocnetnode, rn );
      break;

    case RN_GROUP_DISPLAY:
      rnReply = __handleDisplay( rocnetnode, rn );
      break;

    case RN_GROUP_SOUND:
      rnReply = __handleSound( rocnetnode, rn );
      break;

    case RN_GROUP_MOBILE:
      rnReply = __handleMobile( rocnetnode, rn );
      break;

    default:
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "unsupported group [%d]", group );
      break;
  }

  if( rnReply != NULL ) {
    __sendRN(rocnetnode, rnReply);
    freeMem(rnReply);
  }

  __checkPortEvents(rocnetnode, rn);
}


static int __readPort(iORocNetNode rocnetnode, int port, int iotype) {
  iORocNetNodeData data = Data(rocnetnode);
  if( iotype == IO_DIRECT ) {
    return (raspiRead(port) ? 0:1);
  }
  else if( data->i2cdescriptor > 0 && port > 0 && port < 129 ) {
    byte rdata = 0;
    /* the __scanI2C must have been called */
    int idx = (port-1)/8;
    byte mask = 1 << (((port-1)%16)%8);
    return (data->iodata[idx] & mask) ? 0:1;
  }
  else {
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "port out of range [%d]", port );
    return 0;
  }
}

static void __scanI2C(iORocNetNode rocnetnode) {
  iORocNetNodeData data = Data(rocnetnode);
  int i = 0;
  int rc = 0;
  MutexOp.wait( data->i2cmux );
  for(i = 0; i < 8; i++) {
    if( !data->i2caddr[i] )
      continue;

    if( data->i2caddrError[i] > 10 ) {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "skip i2c %d errors=%d", i, data->i2caddrError[i] );
      data->i2caddr[i] = False;
      continue;
    }

    if( data->iomap[i] & 0x00FF ) {
      byte iodata = data->iodata[i*2+0];
      rc = raspiReadRegI2C(data->i2cdescriptor, 0x20+i, 0x12, &data->iodata[i*2+0]);
      if( rc < 0 ) {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "could not read from I2C device %sA addr 0x%02X errno=%d retries=%d",
            data->i2cdevice, 0x20+i, errno, data->i2caddrError[i] );
        data->i2caddrError[i]++;
        __errorReport(rocnetnode, RN_ERROR_RC_I2C, RN_ERROR_RS_READ, i);
      }
      else {
        data->i2caddrError[i] = 0;
      }
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "i2c %dA [0x%02X]", i, data->iodata[i*2+0] );
    }
    if( data->iomap[i] & 0xFF00 ) {
      byte iodata = data->iodata[i*2+1];
      rc = raspiReadRegI2C(data->i2cdescriptor, 0x20+i, 0x13, &data->iodata[i*2+1]);
      if( rc < 0 ) {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "could not read from I2C device %sB addr 0x%02X errno=%d retries=%d",
            data->i2cdevice, 0x20+i, errno, data->i2caddrError[i] );
        data->i2caddrError[i]++;
        __errorReport(rocnetnode, RN_ERROR_RC_I2C, RN_ERROR_RS_READ, i);
      }
      else {
        data->i2caddrError[i] = 0;
      }
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "i2c %dB [0x%02X]", i, data->iodata[i*2+1] );
    }
  }
  MutexOp.post( data->i2cmux );
}


static void __writeChannel(iORocNetNode rocnetnode, int channel, int pos) {
  iORocNetNodeData data = Data(rocnetnode);
  int rc  = 0;
  int i2caddr = 0x40;
  int devchannel = 0;

  if( channel > 128 || data->channels[channel] == NULL ) {
    return;
  }

  i2caddr = (data->channels[channel]->channel - 1) / 16;
  devchannel = ((data->channels[channel]->channel - 1) % 16);

  if( data->i2caddr40Error[i2caddr] > 10 ) {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "skip channel %d(%d) to I2C device %s addr 0x%02X errors=%d",
        channel, devchannel, data->i2cdevice, 0x40+i2caddr, data->i2caddr40Error[i2caddr] );
    data->i2caddr40[i2caddr] = False;
    return;
  }

  MutexOp.wait( data->i2cmux );
  rc = pwmSetChannel(data->i2cdescriptor, 0x40+i2caddr, devchannel, -1, pos);
  MutexOp.post( data->i2cmux );

  if( rc < 0 ) {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "could not write channel %d(%d) to I2C device %s addr 0x%02X errno=%d",
        channel, devchannel, data->i2cdevice, 0x40+i2caddr, errno );
    data->i2caddr40Error[i2caddr]++;
    __errorReport(rocnetnode, RN_ERROR_RC_I2C, RN_ERROR_RS_WRITE, 0x40+i2caddr);
  }
  else {
    data->i2caddr40Error[i2caddr] = 0;
  }
}


static void __writePort(iORocNetNode rocnetnode, int port, int value, int iotype) {
  iORocNetNodeData data = Data(rocnetnode);

  if( iotype != IO_DIRECT && data->i2cdescriptor > 0 && port > 0 && port < 129 ) {
    if( data->ports[port] != NULL && (data->ports[port]->type & IO_TOGGLE) ) {
      if( value ) {
        data->ports[port]->toggle = !data->ports[port]->toggle;
        value = data->ports[port]->toggle ? 1:0;
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "toggle port %d value=%d", port, value );
      }
      else {
        /* ignore off */
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "ignore low value for toggle port %d toggle=%d", port, data->ports[port]->toggle );
        return;
      }
    }

    if( data->ports[port] != NULL && (data->ports[port]->type & IO_INVERT)) {
      value ^= 1;
    }
  }

  if( iotype == IO_DIRECT ) {
    /* direct GPIO */
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Direct GPIO writeport %d=%d", port, value );
    raspiWrite(port, value);
  }
  else if( data->i2cdescriptor > 0 && port > 0 && port < 129 ) {
    /* Read the I2C, then write. */
    int i2caddr = (port-1)/16;
    int shift   = (port-1)%16;
    int mask16  = (1 << shift); /* create the port mask */
    int wdata16 = (value << shift); /* shift the new value on its place */
    byte mask8  = 0;
    byte wdata8 = 0;
    byte rdata  = 0;

    if(!data->i2caddr[i2caddr]) {
      /* return; not initialised */
      return;
    }
    /* read the latch byte */
    MutexOp.wait( data->i2cmux );
    raspiReadRegI2C(data->i2cdescriptor, 0x20+i2caddr, (shift > 7) ? 0x15:0x14, &rdata);

    if( shift > 7 ) {
      mask8  = (mask16 >> 8) & 0x00FF;
      wdata8 = (wdata16 >> 8) & 0x00FF;
    }
    else {
      mask8  = mask16 & 0x00FF;
      wdata8 = wdata16 & 0x00FF;
    }

    rdata &= ~mask8; /* fileter out the wanted port */
    wdata8 |= rdata; /* save other port values */

    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
        "I2C writeport %d=0x%02X i2caddr=%d shift=%d mask=0x%02X", port, wdata8, i2caddr, shift, mask8 );
    raspiWriteRegI2C(data->i2cdescriptor, 0x20+i2caddr, (shift > 7) ? 0x13:0x12, wdata8);
    MutexOp.post( data->i2cmux );
  }
}


static void __rfidAckWD( void* threadinst ) {
  iOThread         th         = (iOThread)threadinst;
  iORocNetNode     rocnetnode = (iORocNetNode)ThreadOp.getParm( th );
  iORocNetNodeData data       = Data(rocnetnode);
  data->rfidAckRetry = 0;
  data->rfidAck = True;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "RocNet rfidAckWD started" );
  while( data->run ) {
    if( !data->rfidAck && (SystemOp.getTick() - data->rfidAckTimer) > 25 ) {
      /* resend */
      data->rfidAckRetry++;
      if( data->rfidAckRetry <= 4 ) {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "resend RFID report %s", data->lastrfid );
        __sendRN(rocnetnode, data->rfidMsg);
      }
      else {
        TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "stop the motor; the RFID report %s is not acknowledged", data->lastrfid );
        data->Vraw = 0;
        data->rfidAckRetry = 0;
        data->rfidAck = True;
        __errorReport(rocnetnode, RN_ERROR_RC_RFID, RN_ERROR_RS_ACK, 0);
      }
    }
    ThreadOp.sleep(10);
  }
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "RocNet rfidAckWD stopped" );
}


static void __pwm( void* threadinst ) {
  iOThread         th         = (iOThread)threadinst;
  iORocNetNode     rocnetnode = (iORocNetNode)ThreadOp.getParm( th );
  iORocNetNodeData data       = Data(rocnetnode);
  int i = 0;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "RocNet pwm started" );

  while( data->run ) {
    for( i = 0; i < 129; i++ ) {
      if( data->channels[i] != NULL ) {
        int delay = (data->channels[i]->options & 0x0F);
        if( delay > 0 ) {
          if( data->channels[i]->delay < delay ) {
            data->channels[i]->delay++;
            continue;
          }
          data->channels[i]->delay = 0;
        }

        int gotopos = data->channels[i]->curpos;
        int steps = 0;
        if( data->channels[i]->state && data->channels[i]->curpos != data->channels[i]->onpos ) {
          gotopos = data->channels[i]->onpos;
          steps   = data->channels[i]->onsteps;
        }
        else if( data->channels[i]->state == 0 && data->channels[i]->curpos != data->channels[i]->offpos ) {
          gotopos = data->channels[i]->offpos;
          steps   = data->channels[i]->offsteps;
        }

        if( data->channels[i]->curpos != gotopos ) {
          int oldcurpos = data->channels[i]->curpos;
          TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "adjusting pwm channel %d, curpos=%d gotopos=%d", i, data->channels[i]->curpos, gotopos );
          if( data->channels[i]->curpos > gotopos ) {
            data->channels[i]->curpos -= steps;
            if( data->channels[i]->curpos <= gotopos || steps == 0 ) {
              data->channels[i]->curpos = gotopos;
              if( data->channels[i]->options & PWM_REPORT ) {
                byte* msg = allocMem(128);
                msg[RN_PACKET_NETID] = data->location;
                msg[RN_PACKET_GROUP] = RN_GROUP_OUTPUT;
                rnReceipientAddresToPacket( 0, msg, 0 );
                rnSenderAddresToPacket( data->id, msg, 0 );
                msg[RN_PACKET_ACTION] = RN_STATIONARY_SINGLE_PORT;
                msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
                msg[RN_PACKET_LEN] = 4;
                msg[RN_PACKET_DATA + 0] = 0; /* off */
                msg[RN_PACKET_DATA + 1] = data->channels[i]->porttype; /*wProgram.porttype_servo;*/
                msg[RN_PACKET_DATA + 2] = data->channels[i]->onpos / 16;
                msg[RN_PACKET_DATA + 3] = data->channels[i]->channel;
                __sendRN(rocnetnode, msg);
                data->channels[i]->ready = True;
              }
              if( data->channels[i]->options & PWM_BLINK && data->channels[i]->blink ) {
                data->channels[i]->state = !data->channels[i]->state;
                data->channels[i]->ready = False;
                data->channels[i]->sleep = False;
                data->channels[i]->idle  = 0;
              }
            }
          }
          else {
            data->channels[i]->curpos += steps;
            if( data->channels[i]->curpos >= gotopos || steps == 0 ) {
              data->channels[i]->curpos = gotopos;
              if( data->channels[i]->options & PWM_REPORT ) {
                byte* msg = allocMem(128);
                msg[RN_PACKET_NETID] = data->location;
                msg[RN_PACKET_GROUP] = RN_GROUP_OUTPUT;
                rnReceipientAddresToPacket( 0, msg, 0 );
                rnSenderAddresToPacket( data->id, msg, 0 );
                msg[RN_PACKET_ACTION] = RN_STATIONARY_SINGLE_PORT;
                msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
                msg[RN_PACKET_LEN] = 4;
                msg[RN_PACKET_DATA + 0] = 1; /* off */
                msg[RN_PACKET_DATA + 1] = data->channels[i]->porttype; /*wProgram.porttype_servo;*/
                msg[RN_PACKET_DATA + 2] = data->channels[i]->onpos / 16;
                msg[RN_PACKET_DATA + 3] = data->channels[i]->channel;
                __sendRN(rocnetnode, msg);
                data->channels[i]->ready = True;
              }
              if( data->channels[i]->options & PWM_BLINK && data->channels[i]->blink ) {
                data->channels[i]->state = !data->channels[i]->state;
                data->channels[i]->ready = False;
                data->channels[i]->sleep = False;
                data->channels[i]->idle  = 0;
              }
            }
          }
          TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "set channel %d pwm from %d to %d, gotopos=%d",
              data->channels[i]->channel-1, oldcurpos, data->channels[i]->curpos, gotopos );
          __writeChannel(rocnetnode, data->channels[i]->channel, data->channels[i]->curpos);
          ThreadOp.sleep(0);
        }
        else if( !data->channels[i]->ready ) {
          /* report current state */
          int onoff = (data->channels[i]->curpos >= data->channels[i]->onpos) ? 1:0;
          byte* msg = allocMem(128);
          msg[RN_PACKET_NETID] = data->location;
          msg[RN_PACKET_GROUP] = RN_GROUP_OUTPUT;
          rnReceipientAddresToPacket( 0, msg, 0 );
          rnSenderAddresToPacket( data->id, msg, 0 );
          msg[RN_PACKET_ACTION] = RN_STATIONARY_SINGLE_PORT;
          msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
          msg[RN_PACKET_LEN] = 4;
          msg[RN_PACKET_DATA + 0] = onoff;
          msg[RN_PACKET_DATA + 1] = data->channels[i]->porttype; /*wProgram.porttype_servo;*/
          msg[RN_PACKET_DATA + 2] = data->channels[i]->onpos / 16;
          msg[RN_PACKET_DATA + 3] = data->channels[i]->channel;
          __sendRN(rocnetnode, msg);
          data->channels[i]->ready = True;
        }

        if( data->channels[i]->options & PWM_SERVO && data->channels[i]->ready ) {
          if( data->channels[i]->idle < 100 ) {
            data->channels[i]->idle++;
          }
          if( data->channels[i]->idle >= 100 && !data->channels[i]->sleep ) {
            data->channels[i]->sleep = True;
            __writeChannel(rocnetnode, data->channels[i]->channel, 4095);
          }
        }

      }
    }

    ThreadOp.sleep(10);
  }

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "RocNet pwm stopped" );

}


static void __setLightFunction(iORocNetNode inst, int fnr, Boolean on) {
  iORocNetNodeData data = Data(inst);

  if( data->channels[fnr] != NULL ) {
    data->channels[fnr]->state = on ? 1:0;
    data->channels[fnr]->blink = on ? True:False;
    data->channels[fnr]->ready = False;
    data->channels[fnr]->sleep = False;
    data->channels[fnr]->idle  = 0;
  }
}


/*
 * The RPM Hall input will generate in the test case 3 pulses per wheel rotation.
 */
static void __motorPWM( void* threadinst ) {
  iOThread         th         = (iOThread)threadinst;
  iORocNetNode     rocnetnode = (iORocNetNode)ThreadOp.getParm( th );
  iORocNetNodeData data       = Data(rocnetnode);
  int Vcurr = 0;
  int Vprev = 0;
  int Vloop = 0;
  Boolean Vdir = True;
  Boolean lights = False;

  int hall = 0;
  int rpmticks = 0;
  int rpmtime = 0; /* time in 10ms ticks between the Hall pulse */
  int hallcnt = 0;
  int Vcorr = 0;

  ThreadOp.sleep(1000);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Motor PWM started" );

  /* hard coded ports for motor */
  data->VPWMR = 8;  /* pin 24 */
  data->VPWML = 7;  /* pin 26 */
  data->VPWM  = 22; /* pin 15 */
  data->RPM   = 17; /* pin 11 */

  if( data->iorc != 0 ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Motor PWM stopped because I/O is not initialized" );
    return;
  }

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "init VPWM on port %d", data->VPWM );
  raspiConfigPort(data->VPWM, 0);
  ThreadOp.sleep(100);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "init VPWMR on port %d", data->VPWMR );
  raspiConfigPort(data->VPWMR, 0);
  ThreadOp.sleep(100);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "init VPWML on port %d", data->VPWML );
  raspiConfigPort(data->VPWML, 0);
  ThreadOp.sleep(100);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "init RPM on port %d", data->RPM );
  raspiConfigPort(data->RPM, 1);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "init relais on port %d", IO_RELAIS );
  raspiConfigPort(IO_RELAIS, 0);
  ThreadOp.sleep(100);
  __writePort(rocnetnode, IO_RELAIS, 1, IO_DIRECT );

  /*
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "init GPIO18 as PWM" );
  raspiInitPWM(40);
  */

  ThreadOp.setHigh(th);

  while( data->run && data->ismobile ) {
    int Vraw  = data->Vraw;  /* wanted speed */
    int Vmax  = data->Vmax;  /* max PWM */
    int Vmass = data->Vmass; /* acceleration, deceleration */

    /* light functions
     * ToDo: Do this in another thread?
     */
    if( Vdir != data->Vdir || lights != data->fn[0] ) {
      Vdir   = data->Vdir;
      lights = data->fn[0];
      __setLightFunction(rocnetnode,  9,  Vdir && lights );
      __setLightFunction(rocnetnode, 10,  Vdir && lights );
      __setLightFunction(rocnetnode, 11,  Vdir && lights );
      __setLightFunction(rocnetnode, 12, !Vdir && lights );
      __setLightFunction(rocnetnode, 13, !Vdir && lights );
      __setLightFunction(rocnetnode, 14, !Vdir && lights );
    }

    /* motor rpm Hall
      DC Voltage   Hall Freq.  Rotations   Scale speed
       2V           3Hz         1           10 kmh
       6V          10Hz         3.33        35 kmh
      12V          22Hz         7.33        67 kmh
      18V          33Hz        10          100 kmh
     */
    if( Vraw > 0 && __readPort(rocnetnode, data->RPM, IO_DIRECT ) && hall == 0 ) {
      /* Hall sensor is on */
      hall = 1;
      hallcnt++;
    }
    else {
      hall = 0;
    }

    if( Vcurr > 0 ) {
      /* the loco is running */
      rpmticks++;

      if( rpmticks >= 10 ) {
        /* counted 1000ms all high hall pulses */
        int Vtol = 2; /* tolerance */

        /* calculate the correction */
        int Vhall = (hallcnt * 100) / 33; /* hall speed in kmh */
        if( (Vcurr-Vtol) > Vhall ) {
          /* add some speed */
          Vcorr++;
        }
        else if( (Vcurr+Vtol) < Vhall ) {
          /* subtract some speed */
          Vcorr--;
        }
        rpmticks = 0;
        hallcnt = 0;
      }
    }
    else {
      /* reset all */
      rpmtime = 0;
      rpmticks = 0;
      hallcnt = 0;
      Vcorr = 0;
    }

    /* disable Vcorr */
    Vcorr = 0;

    /* check limits */
    if( Vraw > 100 )
      Vraw = 100;
    if( Vmax > 100 )
      Vmax = 100;

    /* acceleration */
    if( Vloop >= Vmass ) {
      Vloop = 0;
      if( Vcurr < Vraw )
        Vcurr++;
      if( Vcurr > Vraw )
        Vcurr--;
    }

    /* motor direction */
    if( Vcurr == 0 ) {
      __writePort(rocnetnode, data->VPWMR, data->Vdir?1:0, IO_DIRECT );
      __writePort(rocnetnode, data->VPWML, data->Vdir?0:1, IO_DIRECT );
    }

    /*
    if( Vcurr != Vprev || Vcurr == 0 ) {
      raspiSetPWM(Vcurr);
      Vprev = Vcurr;
    }
    ThreadOp.sleep(10);
    */

    if( Vcurr > 0 )
      __writePort(rocnetnode, data->VPWM, 1, IO_DIRECT );
    SystemOp.uBusyWait( (Vcurr+Vcorr) * Vmax );
    __writePort(rocnetnode, data->VPWM, 0, IO_DIRECT );
    SystemOp.uBusyWait( (((100-Vmax)+100) - (Vcurr+Vcorr)) * 100 );

    Vloop++;

  }

  __writePort(rocnetnode, IO_RELAIS, 0, IO_DIRECT );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Motor PWM stopped" );

}


static void __reportADCSensor(iORocNetNode rocnetnode, int port, Boolean sensorState, byte value ) {
  iORocNetNodeData data       = Data(rocnetnode);
  byte msg[256];

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "ADC Sensor %d report %s [%d]", 128 + port + 1, sensorState?"ON":"OFF", value );

  msg[RN_PACKET_NETID] = data->location;
  msg[RN_PACKET_GROUP] = RN_GROUP_SENSOR;
  msg[RN_PACKET_ACTION] = RN_SENSOR_REPORT;
  msg[RN_PACKET_LEN] = 5;
  msg[RN_PACKET_DATA+2] = sensorState;
  msg[RN_PACKET_DATA+3] = 128 + port + 1;
  msg[RN_PACKET_DATA+4] = value;
  rnSenderAddresToPacket( data->id, msg, 0 );
  __sendRN(rocnetnode, msg);
}



static void __adcsensorscanner( void* threadinst ) {
  iOThread         th         = (iOThread)threadinst;
  iORocNetNode     rocnetnode = (iORocNetNode)ThreadOp.getParm( th );
  iORocNetNodeData data       = Data(rocnetnode);

  byte baseadc = 0x48;
  int idx = 0;
  byte ctrl = 0x40;
  Boolean startofday = False;

  ThreadOp.sleep(1000);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "ADC Sensor scanner started" );

  while( data->run && data->adcsensor ) {
    int rc = 0;
    int i = 0;
    byte value = 0;
    Boolean inputON = False;

    baseadc = 0x48 + idx;

    for( i = 0; i < 4; i++ ) {
      rc = raspiWriteI2C(data->i2cdescriptor, baseadc, ctrl+i );
      if( rc >= 0 ) {
        rc = raspiReadI2C( data->i2cdescriptor, baseadc, &value );
        if( rc >= 0 ) {
          /*
           * After writing the control byte to the PCF8591 nothing happens for the selected channel.
           * The data byte read after a write is the channel of the previous control byte...
           */
          int port = 0;
          if( i == 0 )
            port = 3;
          else
            port = i - 1;

          if( value > data->adcthreshold )
            inputON = True;

          if( value > data->adcthreshold && ( startofday || data->adcsensorvalue[idx*4+port] == 0) ) {
            data->adcsensorcounter[idx*4+port]++;
            if( data->adcsensorcounter[idx*4+port] > 3 ) {
              /* report on */
              data->adcsensorcounter[idx*4+port] = 0;
              data->adcsensorvalue[idx*4+port] = value;
              data->adcsensortimer[idx*4+port] = SystemOp.getTick();
              __reportADCSensor(rocnetnode, idx*4+port, True, value );
            }
          }
          else if( value > data->adcthreshold && data->adcsensorvalue[idx*4+port] > 0 && abs(data->adcsensorvalue[idx*4+port] - value) >= 10 ) {
            /* report on changed */
            data->adcsensorvalue[idx*4+port] = value;
            data->adcsensortimer[idx*4+port] = SystemOp.getTick();
            __reportADCSensor(rocnetnode, idx*4+port, True, value );
          }
          else if( value < data->adcthreshold && (startofday || data->adcsensorvalue[idx*4+port] > 0) ) {
            if( startofday || (data->adcsensortimer[idx*4+port] + 200 < SystemOp.getTick()) ) {
              /* report off */
              data->adcsensorvalue[idx*4+port] = 0;
              data->adcsensortimer[idx*4+port] = 0;
              __reportADCSensor(rocnetnode, idx*4+port, False, value );
            }
          }
          else if( value < data->adcthreshold && data->adcsensorvalue[idx*4+port] == 0 ) {
            data->adcsensorcounter[idx*4+port] = 0;
          }
        }
        else
          break;
      }
      else
        break;
    }

    /* Show LED in case one or more inputs are above the threshold. */
    raspiWriteRegI2C( data->i2cdescriptor, baseadc, ctrl, inputON?255:0 );


    idx++;
    if( idx > 7 ) {
      idx = 0;
      if( startofday ) {
        startofday = False;
        data->adcstartofday = False;
      }
      startofday = data->adcstartofday;
    }

    ThreadOp.sleep(25);
  }

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "ADC Sensor scanner ended" );
}


static void __rocmousescanner( void* threadinst ) {
  iOThread         th         = (iOThread)threadinst;
  iORocNetNode     rocnetnode = (iORocNetNode)ThreadOp.getParm( th );
  iORocNetNodeData data       = Data(rocnetnode);
  Boolean init[8] = {False,False,False,False,False,False,False,False};
  byte msg[256];
  byte baseio  = 0x3F;
  byte baseadc = 0x4F;
  int idx = 0;

  ThreadOp.sleep(1000);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "RocMouse scanner started" );

  while( data->run && !data->adcsensor ) {
    int rc = 0;
    byte fnLEDs  = 0;
    Boolean buttonLights = False;
    Boolean buttonFGroup = False;
    int changedFn = 0;
    Boolean dirHalt = False;

    MutexOp.wait( data->i2cmux );

    /*
     * The I/O expander and ADC do not need any configuration.
     * Try to read the known I2C addresses.
     *
     * PCF8574
     * 0x01 D0 = LED1 0x04
     * 0x02 D1 = LED2 0x02
     * 0x04 D2 = LED3 0x01
     * 0x08 D3 = S5 fgroup
     * 0x10 D4 = S4 fn4
     * 0x20 D5 = S3 fn3
     * 0x40 D6 = S2 fn2
     * 0x80 D7 = S1 fn1
     *
     * PCF8591:
     * AIN0 = P1  Velocity
     * AIN1 = RS1 Direction
     * AIN2 = S6  Lights
     * AIN3 =
     * AOUT = LED4 Run
     */
#define RM_P1  0
#define RM_RS1 1
#define RM_S6  2

    /*
     * After writing the control byte to the PCF8591 nothing happens for the selected channel.
     * The data byte read after a write is the channel of the previous control byte...
     * Thats why the read is done twice after a control byte write.
     */

    baseio  = 0x38 + idx;
    baseadc = 0x48 + idx;
    /* write outputs (LED1-LED3) */
    if( !init[idx] )
      rc = raspiWriteI2C(data->i2cdescriptor, baseio, 0xFF );

    if( rc >= 0 ) {
      byte ctrl     = 0x40; /* analog out active and auto increment */
      byte valueP1  = 0;
      byte valueRS1 = 0;
      byte valueS6  = 0;

      if( data->rocmouses[idx] == NULL ) {
        data->rocmouses[idx] = allocMem(sizeof( struct RocMouse));
        data->rocmouses[idx]->ioaddr = baseio;
        data->rocmouses[idx]->adaddr = baseadc;
      }


      /*
       * All I/O.
       */
      if( rc >= 0 ) /* write function group LEDs */
        rc = raspiWriteI2C(data->i2cdescriptor, baseio, 0xF8 + (0x07^(data->rocmouses[idx]->fgroup+1)) );
      if( rc >= 0 ) /* read inputs (S1-S5) */
        rc = raspiReadI2C(data->i2cdescriptor, baseio, &data->rocmouses[idx]->io);
      if( rc >= 0 ) /* write control register for P1 */
        rc = raspiWriteI2C(data->i2cdescriptor, baseadc, ctrl+RM_P1 );
      if( rc >= 0 ) /* read previous */
        rc = raspiReadI2C( data->i2cdescriptor, baseadc, &valueP1 );
      if( rc >= 0 ) /* read P1 */
        rc = raspiReadI2C( data->i2cdescriptor, baseadc, &valueP1 );
      if( rc >= 0 ) /* write control register for RS1 */
        rc = raspiWriteI2C(data->i2cdescriptor, baseadc, ctrl+RM_RS1 );
      if( rc >= 0 ) /* read previous */
        rc = raspiReadI2C( data->i2cdescriptor, baseadc, &valueRS1 );
      if( rc >= 0 ) /* read RS1 */
        rc = raspiReadI2C( data->i2cdescriptor, baseadc, &valueRS1 );
      if( rc >= 0 ) /* write control register for RS1 */
        rc = raspiWriteI2C(data->i2cdescriptor, baseadc, ctrl+RM_S6 );
      if( rc >= 0 ) /* read previous */
        rc = raspiReadI2C( data->i2cdescriptor, baseadc, &valueS6 );
      if( rc >= 0 ) /* read RS1 */
        rc = raspiReadI2C( data->i2cdescriptor, baseadc, &valueS6 );

      if( rc >= 0 ) { /* running LED */
        int flashfreq = (data->rocmouses[idx]->lcaddr > 0) ? 10:4;
        data->rocmouses[idx]->runLEDcnt++;
        if(  data->rocmouses[idx]->runLEDcnt >= flashfreq ) {
          data->rocmouses[idx]->runLEDcnt = 0;
          rc = raspiWriteRegI2C( data->i2cdescriptor, baseadc, ctrl, data->rocmouses[idx]->runLED?255:0 );
          data->rocmouses[idx]->runLED = !data->rocmouses[idx]->runLED;
        }
      }


      if( rc == -1 ) {
        init[idx] = False;
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "error during I/O operations with the RocMouse %d", idx);
      }
      else {
        int i = 0;
        float V = 0.0;
        float min0 = 5.0;
        float max255 = 250.0;
        float steps = 50.0;

        init[idx] = True;
        /* Velocity
         *
         * Moving average
         * (2 x old value + new value) / 3
         *   or
         * (3 x old value + new value) / 4
         *
         * */
        data->rocmouses[idx]->P1 = ((data->rocmouses[idx]->P1 * 2) + valueP1) / 3;
        valueP1 = data->rocmouses[idx]->P1;
        /* P1 range is 0-255 */
        if( valueP1 < min0 )
          min0 = valueP1;
        if( valueP1 > max255 )
          max255 = valueP1;
        V = valueP1 - min0;
        V = (steps / (max255-min0)) * V;
        data->rocmouses[idx]->V_raw = (int)V;


        /* Direction */
        if( valueRS1 < 40 )
          data->rocmouses[idx]->dir = True;
        else if( valueRS1 > 200 ) {
          data->rocmouses[idx]->V_raw = 0;
          dirHalt = True;
        }
        else
          data->rocmouses[idx]->dir = False;

        /* Lights */
        if( data->rocmouses[idx]->lightstrig == 0) {
          if( valueS6 < 40 ) {
            if( dirHalt ) {
              buttonLights = True;
            }
            else {
              data->rocmouses[idx]->lightstrig = 5;
              data->rocmouses[idx]->lights = !data->rocmouses[idx]->lights;
              changedFn = 1;
            }
          }
        }
        else {
          if(data->rocmouses[idx]->lightstrig > 0)
            data->rocmouses[idx]->lightstrig--;
        }

        /* Invert digital input */
        data->rocmouses[idx]->io = ~data->rocmouses[idx]->io;
        TraceOp.trc( name, data->stress ? TRCLEVEL_INFO:TRCLEVEL_DEBUG, __LINE__, 9999,
            "base=0x%02X,0x%02X idx=%d P1=%d, RS1=%d, S6=%d IO=0x%02X fgroup=%d",
            baseio, baseadc, idx, valueP1, valueRS1, valueS6, data->rocmouses[idx]->io, data->rocmouses[idx]->fgroup );

        /* S5 function group selection */
        if( data->rocmouses[idx]->io & 0x08 ) {
          if(data->rocmouses[idx]->fgtrig == 0) {
            data->rocmouses[idx]->fgtrig = 5;
            if( dirHalt ) {
              buttonFGroup = True;
            }
            else {
              data->rocmouses[idx]->fgroup++;
              if(data->rocmouses[idx]->fgroup > 6 )
                data->rocmouses[idx]->fgroup = 0;
            }
          }
          else {
            data->rocmouses[idx]->fgtrig--;
          }
        }
        else {
          if( data->rocmouses[idx]->fgtrig > 0 )
            data->rocmouses[idx]->fgtrig--;
        }

        /* S1-S4 functions */
        for( i = 0; i < 4; i++ ) {
          if( data->rocmouses[idx]->io & (0x80>>i) ) {
            if(data->rocmouses[idx]->strig[i] == 0) {
              data->rocmouses[idx]->strig[i] = 5;
              data->rocmouses[idx]->fn[data->rocmouses[idx]->fgroup] ^= (0x01 << i);
              changedFn = data->rocmouses[idx]->fgroup * 4 + i + 1;
            }
            else {
              data->rocmouses[idx]->strig[i]--;
            }
          }
          else {
            if(data->rocmouses[idx]->strig[i] > 0)
              data->rocmouses[idx]->strig[i]--;
          }
        }


        if( data->rocmouses[idx]->V_raw != data->rocmouses[idx]->prev_V_raw ||
            data->rocmouses[idx]->dir != data->rocmouses[idx]->prev_dir ||
            data->rocmouses[idx]->lights != data->rocmouses[idx]->prev_lights ||
            !MemOp.cmp(data->rocmouses[idx]->fn, data->rocmouses[idx]->prev_fn, 8 * sizeof(int))
            )
        {
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
              "RocMouse 0x%02X V=%d dir=%d lights=%d", baseio, data->rocmouses[idx]->V_raw, data->rocmouses[idx]->dir, data->rocmouses[idx]->lights );
          msg[RN_PACKET_NETID] = data->location;
          msg[RN_PACKET_GROUP] = RN_GROUP_MOBILE;
          rnSenderAddresToPacket( data->id, msg, 0 );
          msg[RN_PACKET_ACTION] = RN_MOBILE_ROCMOUSE;
          msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
          msg[RN_PACKET_LEN] = 9;
          msg[RN_PACKET_DATA + 0] = baseio & 0xFF; /* base address */
          msg[RN_PACKET_DATA + 1] = data->rocmouses[idx]->V_raw & 0x7F;
          msg[RN_PACKET_DATA + 2] = data->rocmouses[idx]->dir + (data->rocmouses[idx]->lights << 1);
          msg[RN_PACKET_DATA + 3] = data->rocmouses[idx]->fn[0] + (data->rocmouses[idx]->fn[1] << 4);
          msg[RN_PACKET_DATA + 4] = data->rocmouses[idx]->fn[2] + (data->rocmouses[idx]->fn[3] << 4);
          msg[RN_PACKET_DATA + 5] = data->rocmouses[idx]->fn[4] + (data->rocmouses[idx]->fn[5] << 4);
          msg[RN_PACKET_DATA + 6] = data->rocmouses[idx]->fn[6] + (data->rocmouses[idx]->fn[7] << 4);
          msg[RN_PACKET_DATA + 7] = changedFn & 0xFF;
          msg[RN_PACKET_DATA + 8] = (((int)steps) & 0x7F);
          __sendRN(rocnetnode, msg);

          data->rocmouses[idx]->prev_V_raw  = data->rocmouses[idx]->V_raw;
          data->rocmouses[idx]->prev_dir    = data->rocmouses[idx]->dir;
          data->rocmouses[idx]->prev_lights = data->rocmouses[idx]->lights;
          MemOp.copy(data->rocmouses[idx]->prev_fn, data->rocmouses[idx]->fn, 8 * sizeof(int));
        }

        /* Release loco. */
        if( dirHalt && buttonLights && buttonFGroup ) {
          freeMem(data->rocmouses[idx]);
          data->rocmouses[idx] = NULL;

          init[idx] = False;

          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "rocmouse detached");

          msg[RN_PACKET_NETID] = data->location;
          msg[RN_PACKET_GROUP] = RN_GROUP_MOBILE;
          rnSenderAddresToPacket( data->id, msg, 0 );
          msg[RN_PACKET_ACTION] = RN_MOBILE_ROCMOUSE;
          msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
          msg[RN_PACKET_LEN] = 8;
          msg[RN_PACKET_DATA + 0] = (baseio+0x80) & 0xFF; /* base address */
          msg[RN_PACKET_DATA + 1] = 0;
          msg[RN_PACKET_DATA + 2] = 0;
          msg[RN_PACKET_DATA + 3] = 0;
          msg[RN_PACKET_DATA + 4] = 0;
          msg[RN_PACKET_DATA + 5] = 0;
          msg[RN_PACKET_DATA + 6] = 0;
          msg[RN_PACKET_DATA + 7] = 0;
          __sendRN(rocnetnode, msg);
        }

      }

    }

    MutexOp.post( data->i2cmux );

    idx++;
    if( idx > 7 ) {
      idx = 0;
      ThreadOp.sleep( 20 );
    }

    ThreadOp.sleep( 10 );
  }

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "RocMouse scanner stopped" );
}




static void __scanner( void* threadinst ) {
  iOThread         th         = (iOThread)threadinst;
  iORocNetNode     rocnetnode = (iORocNetNode)ThreadOp.getParm( th );
  iORocNetNodeData data       = Data(rocnetnode);
  int inputVal[128];
  byte msg[256];
  int identwait = 0;
  Boolean LED1 = False;
  Boolean LED2 = False;


  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "RocNet scanner started" );

  MemOp.set( inputVal, 0, sizeof(inputVal) );
  /* negative logic level */
  MemOp.set( data->iodata, 0xFF, sizeof(data->iodata) );

  __writePort(rocnetnode, data->LED1, 1, IO_DIRECT );
  __writePort(rocnetnode, data->LED2, 1, IO_DIRECT );

  while( data->run ) {
    int i;
    int nrios = 128;
    Boolean startofday = data->startofday;

    data->LED1timer++;
    if( data->LED1timer >= 50 || (data->pendingHalt && data->LED1timer >= 10) ) {
      data->LED1timer = 0;
      LED1 = !LED1;
      __writePort(rocnetnode, data->LED1, LED1?1:0, IO_DIRECT );
    }

    if( data->show ) {
      data->LED2timer++;
      if( data->LED2timer >= 10 ) {
        data->LED2timer = 0;
        LED2 = !LED2;
        __writePort(rocnetnode, data->LED2, LED2?1:0, IO_DIRECT );
      }
    }
    else
      __writePort(rocnetnode, data->LED2, 1, IO_DIRECT );

    if( data->iorc == 0 ) {
      __scanI2C(rocnetnode);

      for( i = 0; i < nrios; i++ ) {
        if( data->ports[i] != NULL && (data->ports[i]->type&IO_TYPE) == 0 ) {
          if( (data->ports[i]->type & IO_BLINK)  && data->ports[i]->state && data->ports[i]->delay > 0 ) {
            if( data->ports[i]->offtimer + data->ports[i]->delay <= SystemOp.getTick() ) {
              data->ports[i]->offtimer = SystemOp.getTick();
              data->ports[i]->blink = !data->ports[i]->blink;
              __writePort(rocnetnode, i, data->ports[i]->blink?1:0, data->ports[i]->iotype);
            }
          }
          else if( data->ports[i]->delay > 0 && data->ports[i]->state ) {
            if( data->ports[i]->offtimer + data->ports[i]->delay <= SystemOp.getTick() ) {
              TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "pulse off port %d", i );
              data->ports[i]->state = 0;
              __writePort(rocnetnode, i, 0, data->ports[i]->iotype);

              msg[RN_PACKET_NETID] = data->location;
              msg[RN_PACKET_GROUP] = RN_GROUP_OUTPUT;
              rnSenderAddresToPacket( data->id, msg, 0 );
              msg[RN_PACKET_ACTION] = RN_STATIONARY_SINGLE_PORT;
              msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
              msg[RN_PACKET_LEN] = 4;
              msg[RN_PACKET_DATA + 0] = 0; /* off */
              msg[RN_PACKET_DATA + 1] = 0;
              msg[RN_PACKET_DATA + 2] = 0;
              msg[RN_PACKET_DATA + 3] = i;
              __sendRN(rocnetnode, msg);

            }
          }
        }

        /* Check for pending Ack */
        if( data->sack && data->ports[i] != NULL && (data->ports[i]->type&IO_TYPE) == 1 && data->ports[i]->ackpending) {
          data->ports[i]->acktimer++;
          if( data->ports[i]->acktimer > 50 ) {
            data->ports[i]->ackretry++;
            data->ports[i]->acktimer = 0;
            if( data->ports[i]->ackretry <= 10 ) {
              TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "no ack for port %d; resend", i );
              msg[RN_PACKET_NETID] = data->location;
              msg[RN_PACKET_GROUP] = RN_GROUP_SENSOR;
              msg[RN_PACKET_ACTION] = RN_SENSOR_REPORT;
              msg[RN_PACKET_LEN] = 4;
              msg[RN_PACKET_DATA+2] = data->ports[i]->state;
              msg[RN_PACKET_DATA+3] = i;
              rnSenderAddresToPacket( data->id, msg, 0 );
              __sendRN(rocnetnode, msg);
            }
            else {
              /* giving up */
              data->ports[i]->ackpending = False;
              data->ports[i]->ackretry = 0;
              data->ports[i]->acktimer = 0;
              TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "no ack for port %d", i );
            }
          }
        }

        /* reset input values to zero to trigger a start of day */
        if( data->ports[i] != NULL && (data->ports[i]->type&IO_TYPE) == 1 && startofday ) {
          inputVal[i] = 0;
        }

        if( data->ports[i] != NULL && (data->ports[i]->type&IO_TYPE) == 1 && (!data->sack || !data->ports[i]->ackpending) ) {
          int val = 0;
          if( data->ports[i]->iotype == IO_DIRECT )
            val = __readPort(rocnetnode, data->ports[i]->ionr, data->ports[i]->iotype);
          else
            val = __readPort(rocnetnode, i, data->ports[i]->iotype);

          Boolean report = inputVal[i] != val;

          if( data->ports[i]->delay > 0 ) {
            report = False;
            if( val > 0 ) {
              data->ports[i]->offtimer = SystemOp.getTick();
              if( !data->ports[i]->state ) {
                data->ports[i]->state = 1;
                TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "delayed on port %d", i );
                report = True;
              }
            }
            else if( data->ports[i]->state && data->ports[i]->offtimer + data->ports[i]->delay <= SystemOp.getTick() ) {
              TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "delayed off port %d", i );
              data->ports[i]->state = 0;
              report = True;
            }
          }

          /* Check PB1 for a 5 second ON */
          if( i == 0 ) {
            if( inputVal[i] > 0 && data->usepb ) {
              data->PB1timer++;
              if( data->PB1timer >= 500 ) {
                /* Shutdown */
                RocNetNodeOp.sysHalt();
                data->PB1timer = 0;
                report = False;
              }
              else if( data->PB1timer >= 100 ) {
                data->pendingHalt = True;
              }
            }
            else {
              data->PB1timer = 0;
              data->pendingHalt = False;
            }
          }

          /* Report the changed port */
          if( report ) {
            if( i == 0 ) {
              /* Normal PB1 handling */
              inputVal[i] = val;
              if( val && ! data->pendingHalt && data->usepb ) {
                if( data->show ) {
                  data->show = False;
                }
                else {
                  msg[RN_PACKET_NETID] = data->location;
                  msg[RN_PACKET_GROUP] = RN_GROUP_STATIONARY;
                  msg[RN_PACKET_ACTION] = RN_STATIONARY_SHOW;
                  msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
                  msg[RN_PACKET_LEN] = 0;
                  rnSenderAddresToPacket( data->id, msg, 0 );
                  __sendRN(rocnetnode, msg);
                }
              }
            }
            else {
              data->ports[i]->ackpending = True;
              data->ports[i]->ackretry = 0;
              data->ports[i]->acktimer = 0;
              inputVal[i] = val;
              if( data->ports[i]->type & IO_INVERT ) {
                val ^= 1;
              }
              msg[RN_PACKET_NETID] = data->location;
              msg[RN_PACKET_GROUP] = RN_GROUP_SENSOR;
              msg[RN_PACKET_ACTION] = RN_SENSOR_REPORT;
              msg[RN_PACKET_LEN] = 4;
              msg[RN_PACKET_DATA+2] = val;
              msg[RN_PACKET_DATA+3] = i;
              rnSenderAddresToPacket( data->id, msg, 0 );
              __sendRN(rocnetnode, msg);
            }
            ThreadOp.sleep(raspiDummy()?500:10);
          }
        }
      }

      if( startofday )
        data->startofday = False;

    }

    if( !data->identack ) {
      identwait++;
      if( identwait > 100 ) {
        identwait = 0;
        msg[RN_PACKET_NETID] = data->location;
        msg[RN_PACKET_GROUP] = RN_GROUP_STATIONARY;
        rnReceipientAddresToPacket( 0, msg, 0 );
        rnSenderAddresToPacket( data->id, msg, 0 );
        msg[RN_PACKET_ACTION] = RN_STATIONARY_IDENTIFY;
        msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
        msg[RN_PACKET_LEN] = 7 + StrOp.len(data->nickname);
        msg[RN_PACKET_DATA+0] = data->class;
        msg[RN_PACKET_DATA+1] = 70;
        msg[RN_PACKET_DATA+2] = revisionnr/256;
        msg[RN_PACKET_DATA+3] = revisionnr%256;
        msg[RN_PACKET_DATA+4] = 128;
        msg[RN_PACKET_DATA+5] = data->ip[data->ipsize-2];
        msg[RN_PACKET_DATA+6] = data->ip[data->ipsize-1];
        StrOp.copy((char*)&msg[RN_PACKET_DATA+7], data->nickname);
        __sendRN(rocnetnode, msg);
      }
    }

    ThreadOp.sleep(10);
  }

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "RocNet scanner stopped" );
}


static void __reader( void* threadinst ) {
  iOThread         th         = (iOThread)threadinst;
  iORocNetNode     rocnetnode = (iORocNetNode)ThreadOp.getParm( th );
  iORocNetNodeData data       = Data(rocnetnode);
  byte msg[256];
  int idx = 0;
  iOStrTok tok = StrTokOp.inst(getLocalIP(), '.');
  while( StrTokOp.hasMoreTokens(tok) ) {
    data->ip[idx] = atoi(StrTokOp.nextToken( tok ));
    idx++;
  }
  StrTokOp.base.del(tok);
  data->ipsize = idx;

  if( data->ip[2] == 0 && data->ip[3] == 0 ) {
    int subip = SystemOp.getMillis() + SystemOp.getpid();
    data->ipsize = 4;
    data->ip[2] = (subip / 256) % 256;
    data->ip[3] = subip % 256;
  }

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "RocNet reader started on: %d.%d.%d.%d",
      data->ip[0], data->ip[1], data->ip[2], data->ip[3] );

  while( data->run ) {
    SocketOp.recvfrom( data->readUDP, (char*)msg, 0x7F, NULL, NULL );
    __evaluateRN(rocnetnode, msg);
    ThreadOp.sleep(10);
  }

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "RocNet reader stopped" );
}


static void __listener( obj inst, iONode nodeC, int level ) {
  iORocNetNodeData data = Data(inst);
  if( nodeC != NULL ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "listener: %s", NodeOp.getName(nodeC) );
    if(StrOp.equals(NodeOp.getName(nodeC), wFeedback.name())) {
      byte msg[256];
      const char* ident = wFeedback.getidentifier(nodeC);
      msg[RN_PACKET_NETID] = data->location;
      msg[RN_PACKET_GROUP] = RN_GROUP_SENSOR;
      msg[RN_PACKET_ACTION] = RN_SENSORID_REPORT;
      msg[RN_PACKET_LEN] = 4;
      msg[RN_PACKET_DATA+2] = wFeedback.isstate(nodeC);
      msg[RN_PACKET_DATA+3] = wFeedback.getaddr(nodeC);
      rnSenderAddresToPacket( data->id, msg, 0 );

      if( !wFeedback.isstate(nodeC) && StrOp.len(data->lastrfid) > 0 ) {
        /* report off state of last seen RFID tag */
        ident = data->lastrfid;
      }

      if( ident != NULL ) {
        int len = StrOp.len(ident);
        int i = 0;
        msg[RN_PACKET_LEN] += len;
        for( i = 0; i < len; i++ )
          msg[RN_PACKET_DATA+4+i] = ident[i];
        StrOp.fmtb(data->lastrfid, "%s", ident);
      }

      if( wFeedback.isstate(nodeC) ) {
        MemOp.copy( data->rfidMsg, msg, 128);
        data->rfidAckTimer = SystemOp.getTick();
        data->rfidAck = False;
        data->rfidAckRetry = 0;
      }

      __sendRN((iORocNetNode)inst, msg);
    }
    NodeOp.base.del(nodeC);
  }
}

static void __unloadDigInt(iORocNetNode inst, int prevcstype) {
  iORocNetNodeData data = Data(inst);

  if( !data->rfid && data->pRFID != NULL ) {
    iIDigInt pRFID = data->pRFID;
    data->pRFID = NULL;
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "unloading RFID..." );
    pRFID->halt((obj)pRFID, True, False);
    ThreadOp.sleep(100);
    pRFID->base.del(pRFID);
    data->class = (data->class & ~RN_CLASS_RFID);
  }

  if( data->cstype != prevcstype && data->pDI != NULL && data->digintini != NULL) {
    iIDigInt pDI = data->pDI;
    data->pDI = NULL;
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "unloading %s...", wDigInt.getlib(data->digintini) );
    pDI->halt((obj)pDI, True, False);
    ThreadOp.sleep(100);
    pDI->base.del(pDI);
    data->class = (data->class & ~RN_CLASS_DCC);
  }
}

static Boolean __initDigInt(iORocNetNode inst) {
  iORocNetNodeData data = Data(inst);

  if( data->rfid && data->pRFID == NULL ) {
    iOLib    pLib = NULL;
    LPFNROCGETDIGINT pInitFun = (void *) NULL;
    char* libpath = StrOp.fmt( "%s%c%s", data->libpath, SystemOp.getFileSeparator(), "rfid12" );
    pLib = LibOp.inst( libpath );
    StrOp.free( libpath );
    if (pLib != NULL) {
      pInitFun = (LPFNROCGETDIGINT)LibOp.getProc(pLib,"rocGetDigInt");
      if (pInitFun != NULL) {
        iONode digintini = NodeOp.inst(wDigInt.name(), NULL, ELEMENT_NODE);
        wDigInt.setiid(digintini, "rfid-1");
        wDigInt.setdevice(digintini, "/dev/ttyAMA0"); /* on every RasPi? */
        wDigInt.setfboffset( digintini, 129 );
        data->pRFID = pInitFun(digintini,TraceOp.get());
        data->pRFID->setListener( (obj)data->pRFID, (obj)inst, &__listener );
        data->class |= RN_CLASS_RFID;
      }
    }
  }

  if( data->cstype > 0 && data->pDI == NULL && data->digintini != NULL ) {
    const char*  lib = wDigInt.getlib( data->digintini );
    const char*  iid = wDigInt.getiid( data->digintini );
    iOLib    pLib = NULL;
    LPFNROCGETDIGINT pInitFun = (void *) NULL;
    char* libpath = StrOp.fmt( "%s%c%s", data->libpath, SystemOp.getFileSeparator(), lib );
    pLib = LibOp.inst( libpath );
    StrOp.free( libpath );
    if (pLib == NULL)
      return False;
    pInitFun = (LPFNROCGETDIGINT)LibOp.getProc(pLib,"rocGetDigInt");
    if (pInitFun == NULL)
      return False;
    data->pDI = pInitFun(data->digintini,TraceOp.get());
    data->pDI->setListener( (obj)data->pDI, (obj)inst, &__listener );
    data->class |= RN_CLASS_DCC;

    return True;
  }
  return False;
}

static iONode __findPort(iORocNetNode inst, int port) {
  iORocNetNodeData data = Data(inst);
  iONode rocnet = NodeOp.findNode(data->ini, wRocNet.name());
  iONode portsetup = NULL;

  if( rocnet != NULL ) {
    iONode portsetup = wRocNet.getportsetup(rocnet);
    while( portsetup != NULL ) {
      if( wPortSetup.getport(portsetup) == port ) {
        return portsetup;
      }
      portsetup = wRocNet.nextportsetup(rocnet, portsetup);
    }
  }

  return portsetup;
}

static iONode __findChannel(iORocNetNode inst, int channel) {
  iORocNetNodeData data = Data(inst);
  iONode rocnet = NodeOp.findNode(data->ini, wRocNet.name());
  iONode channelsetup = NULL;

  if( rocnet != NULL ) {
    iONode channelsetup = wRocNet.getchannelsetup(rocnet);
    while( channelsetup != NULL ) {
      if( wChannelSetup.getchannel(channelsetup) == channel ) {
        return channelsetup;
      }
      channelsetup = wRocNet.nextchannelsetup(rocnet, channelsetup);
    }
  }

  return channelsetup;
}

static iONode __findMacro(iORocNetNode inst, int nr) {
  iORocNetNodeData data = Data(inst);
  iONode macro = wRocNet.getmacro(data->ini);

  while( macro != NULL ) {
    if( wMacro.getnr(macro) == nr ) {
      return macro;
    }
    macro = wRocNet.nextmacro(data->ini, macro);
  }

  return NULL;
}

static void __errorReport( iORocNetNode inst, int rc, int rs, int addr) {
  iORocNetNodeData data = Data(inst);
  byte msg[32];
  msg[RN_PACKET_NETID] = data->location;
  msg[RN_PACKET_GROUP] = RN_GROUP_STATIONARY;
  rnReceipientAddresToPacket( 0, msg, 0 );
  rnSenderAddresToPacket( data->id, msg, 0 );
  msg[RN_PACKET_ACTION] = RN_STATIONARY_ERROR;
  msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
  msg[RN_PACKET_LEN] = 4;
  msg[RN_PACKET_DATA+0] = rc;
  msg[RN_PACKET_DATA+1] = rs;
  msg[RN_PACKET_DATA+2] = addr/256;
  msg[RN_PACKET_DATA+3] = addr%256;
  __sendRN(inst, msg);
}

static int __checkI2C(iORocNetNode inst, int group) {
  iORocNetNodeData data = Data(inst);
  int result = 0;

  if( data->i2cdescriptor >= 0 ) {
    int i = 0;
    byte b = 0;
    MutexOp.wait( data->i2cmux );
    for( i = 0; i < 16; i++ ) {
      if( raspiReadI2C(data->i2cdescriptor, group + i, &b) >= 0 ) {
        result |= (0x0001 << i);
      }
      else if( raspiReadRegI2C(data->i2cdescriptor, group + i, 0, &b) >= 0 ) {
        result |= (0x0001 << i);
      }
    }
    MutexOp.post( data->i2cmux );
  }
  return result;
}


static void __initI2CPWM(iORocNetNode inst) {
  iORocNetNodeData data = Data(inst);
  iONode rocnet = NodeOp.findNode(data->ini, wRocNet.name());
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "init I2C PWM [%s]", data->i2cdevice );

  if( data->i2cdescriptor < 0 ) {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "I2C device %s is not initialized", data->i2cdevice );
  }

  MutexOp.wait( data->i2cmux );

  MemOp.set(data->i2caddr40, 0, sizeof(data->i2caddr40));

  if( rocnet != NULL ) {
    int i2caddr = 0;
    iONode channelsetup = wRocNet.getchannelsetup(rocnet);
    while( channelsetup != NULL ) {
      int channelnr = wChannelSetup.getchannel(channelsetup);

      if( channelnr < 129 ) {
        iOChannel channel = data->channels[channelnr];
        if( channel == NULL ) {
          channel = allocMem( sizeof( struct Channel) );
          data->channels[channelnr] = channel;
        }

        channel->channel  = channelnr;
        channel->options  = wChannelSetup.getoptions(channelsetup);
        channel->offsteps = wChannelSetup.getoffsteps(channelsetup);
        channel->onsteps  = wChannelSetup.getonsteps(channelsetup);
        channel->offpos   = wChannelSetup.getoffpos(channelsetup);
        channel->onpos    = wChannelSetup.getonpos(channelsetup);
        channel->state    = wChannelSetup.getstate(channelsetup);

        i2caddr = (channelnr-1) / 16;
        if( i2caddr >= 0 && i2caddr < 8 ) {
          int rc = 0;

          if( !data->i2caddr40[i2caddr] ) {
            data->i2caddr40[i2caddr] = True;
            rc = pwmStop(data->i2cdescriptor, 0x40+i2caddr);
            if( rc < 0 ) {
              TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "could not write to I2C device %s addr 0x%02X errno=%d", data->i2cdevice, 0x40+i2caddr, errno );
              data->i2caddr40[i2caddr] = False;
              __errorReport(inst, RN_ERROR_RC_I2C, RN_ERROR_RS_WRITE, 0x40+i2caddr);
            }
          }

          if( data->i2caddr40[i2caddr] ) {
            channel->curpos = channel->state ? channel->onpos:channel->offpos;
            rc = pwmSetChannel(data->i2cdescriptor, 0x40+i2caddr, (channel->channel%16)-1, 0, channel->curpos);
            if( rc < 0 ) {
              TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "could not write to I2C device %s addr 0x%02X errno=%d", data->i2cdevice, 0x40+i2caddr, errno );
              data->i2caddr40[i2caddr] = False;
              __errorReport(inst, RN_ERROR_RC_I2C, RN_ERROR_RS_WRITE, 0x40+i2caddr);
            }
            TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
                "channelsetup: channel=%d i2caddr=0x%02X offpos=%d onpos=%d offsteps=%d onsteps=%d options=0s%02X state=%d",
                channel->channel, i2caddr + 0x40, channel->offpos, channel->onpos, channel->offsteps, channel->onsteps, channel->options, channel->state );
          }

        }
      }

      channelsetup = wRocNet.nextchannelsetup(rocnet, channelsetup);
    }

    for( i2caddr = 0; i2caddr < 8; i2caddr++ ) {
      if( data->i2caddr40[i2caddr] ) {
        int rc = pwmSetFreq(data->i2cdescriptor, 0x40+i2caddr, 60);
        if( rc < 0 ) {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "could not write to I2C device %s addr 0x%02X errno=%d", data->i2cdevice, 0x40+i2caddr, errno );
          data->i2caddr40[i2caddr] = False;
          __errorReport(inst, RN_ERROR_RC_I2C, RN_ERROR_RS_WRITE, 0x40+i2caddr);
        }
      }
    }

  }

  MutexOp.post( data->i2cmux );
}


static void __initI2C(iORocNetNode inst, int iotype) {
  iORocNetNodeData data = Data(inst);
  iONode rocnet = NodeOp.findNode(data->ini, wRocNet.name());
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "init I2C [%s]", data->i2cdevice );

  MutexOp.wait( data->i2cmux );

  if( data->iotype == IO_I2C_0 ) {
    /* hardware revision 1 */
  }
  else if( data->iotype == IO_I2C_2 ) {
    /* BBB? */
  }
  else {
    /* hardware revision 2 */
    raspiGPIOAlt(2, 0);
    raspiGPIOAlt(3, 0);
  }
  ThreadOp.sleep(100);

  MemOp.set(data->iomap, 0, sizeof(data->iomap));
  MemOp.set(data->i2caddr, 0, sizeof(data->i2caddr));

  if( rocnet != NULL ) {
    int i = 0;
    int i2caddr = 0;
    int shift = 0;
    iONode portsetup = wRocNet.getportsetup(rocnet);
    MemOp.set( data->iomap, 0, sizeof(data->iomap));
    while( portsetup != NULL ) {
      int portnr = wPortSetup.getport(portsetup);

      if( portnr < 129 ) {
        iOPort port = data->ports[portnr];
        if( port == NULL ) {
          port = allocMem( sizeof( struct Port) );
          data->ports[portnr] = port;
        }

        port->port = portnr;
        port->delay = wPortSetup.getdelay(portsetup);
        port->iotype = iotype;
        port->type = wPortSetup.gettype(portsetup);
        port->eventid = wPortSetup.geteventid(portsetup);
        port->eventport = wPortSetup.geteventport(portsetup);
        if( (port->type&IO_TYPE) == 0 )
          port->state = wPortSetup.getstate(portsetup);
        if( (port->type&IO_TYPE) == 1 && port->delay == 0 )
          port->delay = 10;

        i2caddr = (portnr-1) / 16;
        shift = (portnr-1) % 16;
        if( i2caddr >= 0 && i2caddr < 8 ) {
          data->i2caddr[i2caddr] = True;
          if( wPortSetup.gettype(portsetup) == 1 )
            data->iomap[i2caddr] |= (1 << shift );

          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
              "portsetup: port=%d i2caddr=0x%02X shift=%d mask=0x%02X type=%d delay=%d blink=%d",
              port->port, i2caddr + 0x20, shift, data->iomap[i2caddr], (port->type&IO_TYPE), port->delay, (port->type&IO_BLINK)?1:0 );
        }
      }
      portsetup = wRocNet.nextportsetup(rocnet, portsetup);
    }

    for( i = 0; i < 8; i++ ) {
      if( data->i2caddr[i] )
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
            "i2c addr=%d A=0x%02X B=0x%02X", i, data->iomap[i]&0x00FF, (data->iomap[i]&0xFF00) >> 8 );
    }

    data->i2cdescriptor = raspiOpenI2C(data->i2cdevice);
    if( data->i2cdescriptor < 0 ) {
      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "could not open I2C device %s errno=%d", data->i2cdevice, errno );
      MutexOp.post( data->i2cmux );
      return;
    }
    for( i = 0; i < 8; i++ ) {
      int rc = 0;
      if( data->i2caddr[i] ) {
        ThreadOp.sleep(50);
        rc = raspiWriteRegI2C(data->i2cdescriptor, 0x20+i, 0x00, data->iomap[i]&0x00FF);
        if( rc < 0 ) {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "could not write to I2C device %s addr 0x%02X errno=%d", data->i2cdevice, 0x20+i, errno );
          data->i2caddr[i] = False;
          __errorReport(inst, RN_ERROR_RC_I2C, RN_ERROR_RS_WRITE, i+0x20);
          continue;
        }
        ThreadOp.sleep(50);
        rc = raspiWriteRegI2C(data->i2cdescriptor, 0x20+i, 0x01, (data->iomap[i]&0xFF00) >> 8);
        if( rc < 0 ) {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "could not write to I2C device %s addr 0x%02X errno=%d", data->i2cdevice, 0x20+i, errno );
          data->i2caddr[i] = False;
          __errorReport(inst, RN_ERROR_RC_I2C, RN_ERROR_RS_WRITE, i+0x20);
          continue;
        }
      }
    }
  }

  MutexOp.post( data->i2cmux );

}


static void __initControl(iORocNetNode inst) {
  iORocNetNodeData data = Data(inst);
  int iomap = 0;
  iOPort port = NULL;

  data->LED1 = IO_LED1;
  data->LED2 = IO_LED2;
  data->PB1  = IO_PB1;

  ThreadOp.sleep(50);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "init LED1 on port %d", data->LED1 );
  raspiGPIOAlt(data->LED1, 0);
  raspiConfigPort(data->LED1, 0);
  ThreadOp.sleep(50);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "init LED2 on port %d", data->LED2 );
  raspiGPIOAlt(data->LED2, 0);
  raspiConfigPort(data->LED2, 0);
  ThreadOp.sleep(50);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "init PB1 on port %d", data->PB1 );
  raspiGPIOAlt(data->PB1, 0);
  raspiConfigPort(data->PB1, 1);

  ThreadOp.sleep(50);
  port = allocMem( sizeof( struct Port) );
  port->port = 0;
  port->ionr = data->PB1;
  port->delay = 50;
  port->iotype = IO_DIRECT;
  port->type = IO_INPUT;
  port->state = 0;
  data->ports[0] = port;
}


static void __initIO(iORocNetNode inst) {
  iORocNetNodeData data = Data(inst);

  data->iorc = raspiSetupIO();

  if( data->iorc != 0 ) {
    __errorReport(inst, RN_ERROR_RC_IO, RN_ERROR_RS_SETUP, 0);
  }

  if(data->iotype == IO_I2C_0) {
    /* i2c-0 Rev. 1*/
    data->i2cdevice = "/dev/i2c-0";
    __initI2C(inst, 1);
  }
  else if(data->iotype == IO_I2C_2) {
    data->i2cdevice = "/dev/i2c-2";
    __initI2C(inst, 2);
  }
  else {
    /* default i2c-1 Rev.2 */
    data->i2cdevice = "/dev/i2c-1";
    __initI2C(inst, 2);
  }

  __initI2CPWM(inst);

  if( data->iorc == 0) {
    data->class |= RN_CLASS_IO;
    __initControl(inst);
  }

}

static void __checkConsole( iORocNetNodeData data ) {
  /* Check for command. */
  int c = getchar();

  if( c == wConCmd.debug ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Toggle debug tracelevel." );
    TraceOp.setLevel( NULL, TraceOp.getLevel( NULL ) ^ TRCLEVEL_DEBUG );
    TraceOp.setLevel( NULL, TraceOp.getLevel( NULL ) ^ TRCLEVEL_XMLH );
  }
  else if( c == wConCmd.byte ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Toggle byte tracelevel." );
    TraceOp.setLevel( NULL, TraceOp.getLevel( NULL ) ^ TRCLEVEL_BYTE );
  }
  else if( c == wConCmd.memtrc ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Toggle memory tracelevel." );
    TraceOp.setLevel( NULL, TraceOp.getLevel( NULL ) ^ TRCLEVEL_MEMORY );
  }
  else if( c == wConCmd.automat ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Toggle auto tracelevel." );
    TraceOp.setLevel( NULL, TraceOp.getLevel( NULL ) ^ TRCLEVEL_USER1 );
  }
  else if( c == wConCmd.monitor ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Toggle monitor tracelevel." );
    TraceOp.setLevel( NULL, TraceOp.getLevel( NULL ) ^ TRCLEVEL_MONITOR );
  }
  else if( c == wConCmd.info ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Toggle info tracelevel." );
    TraceOp.setLevel( NULL, TraceOp.getLevel( NULL ) ^ TRCLEVEL_INFO );
  }
  else if( c == wConCmd.quit ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Shutdown requested." );
    data->consoleMode = False;
    RocNetNodeOp.shutdown();
  }
}


static void __initThreads(iORocNetNode inst) {
  iORocNetNodeData data = Data(inst);

  if( data->adcsensor &&  data->adcsensorscanner == NULL ) {
    data->adcsensorscanner = ThreadOp.inst( "rnadcsens", &__adcsensorscanner, __RocNetNode );
    ThreadOp.start( data->adcsensorscanner );
  }
  else if( !data->adcsensor &&  data->rocmousescanner == NULL ) {
    data->rocmousescanner = ThreadOp.inst( "rocmouse", &__rocmousescanner, __RocNetNode );
    ThreadOp.start( data->rocmousescanner );
  }

  if( data->ismobile &&  data->motorPWM == NULL ) {
    data->motorPWM = ThreadOp.inst( "motorpwm", &__motorPWM, __RocNetNode );
    ThreadOp.start( data->motorPWM );
  }

}

static int _Main( iORocNetNode inst, int argc, char** argv ) {
  iORocNetNodeData data = Data(inst);
  iOTrace trc = NULL;
  Boolean cd = False;
  const char* tf = "rocnetnode";

  /* check commandline arguments */
  iOCmdLn     arg     = CmdLnOp.inst( argc, (const char**)argv );
  tracelevel  debug   = CmdLnOp.hasKey( arg, wCmdline.debug  ) ? TRCLEVEL_DEBUG:0;
  tracelevel  dump    = CmdLnOp.hasKey( arg, wCmdline.byte   ) ? TRCLEVEL_BYTE:0;
  tracelevel  parse   = CmdLnOp.hasKey( arg, wCmdline.parse  ) ? TRCLEVEL_PARSE:0;
  tracelevel  monitor = CmdLnOp.hasKey( arg, wCmdline.monitor) ? TRCLEVEL_MONITOR:0;
  tracelevel  info    = CmdLnOp.hasKey( arg, wCmdline.info   ) ? TRCLEVEL_INFO:0;
  Boolean     console = CmdLnOp.hasKey( arg, wCmdline.console );

  const char* nf     = CmdLnOp.getStr( arg, wCmdline.inifile );
  data->libpath       = CmdLnOp.getStr( arg, wCmdline.libpath );
  data->stress        = CmdLnOp.hasKey( arg, wCmdline.stress );

  if( data->libpath == NULL ) {
    data->libpath = ".";
  }

  if( nf == NULL )
    data->inifile = ROCNETNODEINI;
  else
    data->inifile = nf;

  data->consoleMode = console;

  /* Read the Inifile: */
  {
    char* iniXml = NULL;
    iODoc iniDoc = NULL;
    if( FileOp.exist(data->inifile) && FileOp.fileSize(data->inifile) > 0 ) {
      iOFile iniFile = FileOp.inst( data->inifile, True );
      if( iniFile != NULL ) {
        iniXml = allocMem( FileOp.size( iniFile ) + 1 );
        FileOp.read( iniFile, iniXml, FileOp.size( iniFile ) );
        FileOp.close( iniFile );
        FileOp.base.del(iniFile);
        if( StrOp.len( iniXml ) == 0 ) {
          freeMem(iniXml);
          iniXml = NULL;
        }
      }
    }

    if( iniXml == NULL ) {
      char* backupfile = StrOp.fmt("%s.bak", data->inifile );
      if( FileOp.exist(backupfile) && FileOp.fileSize(backupfile) > 0 ) {
        iOFile iniFile = FileOp.inst( backupfile, True );
        if( iniFile != NULL ) {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "using backup ini file: %s", FileOp.getFilename(iniFile) );
          iniXml = allocMem( FileOp.size( iniFile ) + 1 );
          FileOp.read( iniFile, iniXml, FileOp.size( iniFile ) );
          FileOp.close( iniFile );
          FileOp.base.del(iniFile);
          if( StrOp.len( iniXml ) == 0 ) {
            freeMem(iniXml);
            iniXml = NULL;
          }
        }
      }
      StrOp.free(backupfile);
    }

    if( iniXml == NULL ) {
      iniXml = StrOp.fmt( "<%s/>", "rocnetnode");
    }

    /* Parse the Inifile: */
    iniDoc = DocOp.parse( iniXml );
    if( iniDoc != NULL ) {
      data->ini = DocOp.getRootNode( iniDoc );
    }
    else {
      data->ini = NodeOp.inst( "rocnetnode", NULL, ELEMENT_NODE );
    }
  }

  /* set defaults */
  data->id     = 65535;
  data->addr   = "224.0.0.1";
  data->port   = 4321;
  data->iotype = IO_I2C_1;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Up and running the RocNetNode" );
  if( NodeOp.findNode(data->ini, wRocNet.name()) != NULL ) {
    iONode rocnet = NodeOp.findNode(data->ini, wRocNet.name());
    data->id    = wRocNet.getid(rocnet);
    data->location = wRocNet.getnet(rocnet);
    data->addr  = wRocNet.getaddr(rocnet);
    data->port  = wRocNet.getport(rocnet);
    if( data->id < 2 ) {
      data->id = 65535;
      wRocNet.setid(rocnet, data->id);
    }

    if( NodeOp.findNode(rocnet, wRocNetNodeOptions.name()) != NULL ) {
      iONode optionsini = NodeOp.findNode(rocnet, wRocNetNodeOptions.name());
      data->sack  = wRocNetNodeOptions.issack(optionsini);
      data->rfid  = wRocNetNodeOptions.isrfid(optionsini);
      data->adcsensor = wRocNetNodeOptions.isadcsensor(optionsini);
      data->adcthreshold = wRocNetNodeOptions.getadcthreshold(optionsini);
      data->ismobile = wRocNetNodeOptions.ismobile(optionsini);
      data->usepb = wRocNetNodeOptions.isusepb(optionsini);
      data->iotype = wRocNetNodeOptions.getiotype(optionsini);
      StrOp.copy( data->nickname, wRocNetNodeOptions.getnickname(optionsini) );
    }
    else {
      iONode optionsini = NodeOp.inst(wRocNetNodeOptions.name(), rocnet, ELEMENT_NODE );
      NodeOp.addChild( rocnet, optionsini);
    }

    if( NodeOp.findNode(data->ini, wTrace.name()) != NULL ) {
      iONode traceini = NodeOp.findNode(data->ini, wTrace.name());
      tf = wTrace.getrfile(traceini);
      trc = TraceOp.inst( debug | dump | monitor | (wTrace.ismonitor(traceini)?TRCLEVEL_MONITOR:0) | parse |
                          info | (wTrace.isinfo(traceini)?TRCLEVEL_INFO:0) | TRCLEVEL_CALC, tf, True );
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "using ini setup" );

      if( wTrace.isdebug( traceini ) || debug )
        TraceOp.setLevel( trc, TraceOp.getLevel( trc ) | TRCLEVEL_DEBUG );
      if( wTrace.ismonitor( traceini ) || monitor )
        TraceOp.setLevel( trc, TraceOp.getLevel( trc ) | TRCLEVEL_MONITOR );
      if( wTrace.isbyte( traceini ) || dump )
        TraceOp.setLevel( trc, TraceOp.getLevel( trc ) | TRCLEVEL_BYTE );
      if( wTrace.isparse( traceini ) || parse )
        TraceOp.setLevel( trc, TraceOp.getLevel( trc ) | TRCLEVEL_PARSE );
      if( wTrace.iscalc( traceini ) )
        TraceOp.setLevel( trc, TraceOp.getLevel( trc ) | TRCLEVEL_CALC );
    }
    else {
      trc = TraceOp.inst( debug | dump | monitor | parse | TRCLEVEL_INFO | TRCLEVEL_WARNING | TRCLEVEL_CALC, tf, True );
    }

    data->tl_info = TraceOp.getLevel( trc ) & TRCLEVEL_INFO;
    data->tl_monitor = TraceOp.getLevel( trc ) & TRCLEVEL_MONITOR;

    data->digintini = NodeOp.findNode(data->ini, wDigInt.name());
    if( data->digintini != NULL ) {
      if(StrOp.equals(wDigInt.dcc232, wDigInt.getlib(data->digintini)))
        data->cstype = 1;
      else if(StrOp.equals(wDigInt.sprog, wDigInt.getlib(data->digintini)))
        data->cstype = 2;

      if( StrOp.equals("/dev/ttyUSB0", wDigInt.getdevice(data->digintini)) )
        data->csdevice = 0;
      else if( StrOp.equals("/dev/ttyUSB1", wDigInt.getdevice(data->digintini)) )
        data->csdevice = 1;
      else if( StrOp.equals("/dev/ttyACM0", wDigInt.getdevice(data->digintini)) )
        data->csdevice = 2;

    }
    else {
      data->cstype = 0;
    }

    if( NodeOp.findNode(data->ini, wMacro.name()) != NULL ) {
      iONode macro = NodeOp.findNode(data->ini, wMacro.name());
      while( macro != NULL ) {
        int nr = wMacro.getnr(macro);
        if( nr < 129 && data->macro[nr] == NULL ) {
          iONode line = wMacro.getmacroline(macro);
          int lineIdx = 0;
          data->macro[nr] = allocMem(sizeof(struct Macro));
          data->macro[nr]->slowdown = wMacro.getslowdown(macro);
          data->macro[nr]->repeat   = wMacro.getrepeat(macro);
          data->macro[nr]->hours    = wMacro.gethours(macro);
          data->macro[nr]->minutes  = wMacro.getminutes(macro);
          data->macro[nr]->wday     = wMacro.getwday(macro);
          while( line != NULL && lineIdx < 8 ) {
            data->macro[nr]->line[lineIdx].delay = wMacroLine.getdelay(line);
            data->macro[nr]->line[lineIdx].port  = wMacroLine.getport(line);
            data->macro[nr]->line[lineIdx].type  = wMacroLine.getporttype(line);
            data->macro[nr]->line[lineIdx].value = wMacroLine.getstatus(line);
            data->macro[nr]->line[lineIdx].blink = wMacroLine.isblink(line);
            lineIdx++;
            line = wMacro.nextmacroline(macro, line);
          }
        }
        macro = NodeOp.findNextNode(data->ini, macro);
      }
    }

  }
  else {
    trc = TraceOp.inst( debug | dump | monitor | parse | TRCLEVEL_INFO | TRCLEVEL_WARNING | TRCLEVEL_CALC, tf, True );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "using default setup" );
    data->id    = 65535;
    data->addr  = "224.0.0.1";
    data->port  = 4321;
  }
  TraceOp.setAppID( trc, "r" );

  data->i2cmux = MutexOp.inst( NULL, True );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "  revision [%d]", revisionnr );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "  ID [%d]", data->id );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "  multicast address [%s]", data->addr );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "  multicast port    [%d]", data->port );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "  I/O type [%d]", data->iotype );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "  sensor ack [%s]", data->sack?"ON":"OFF" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "  RFID [%s]", data->rfid?"ON":"OFF" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "  ADC Sensors [%s]", data->adcsensor?"ON":"OFF" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "  motor PWM [%s]", data->ismobile?"ON":"OFF" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );
  data->readUDP = SocketOp.inst( data->addr, data->port, False, True, True );
  SocketOp.bind(data->readUDP);
  data->writeUDP = SocketOp.inst( data->addr, data->port, False, True, True );

  ThreadOp.sleep(500); /* startup sleep */
  data->class = 0;
  __initIO(inst);

  __initDigInt(inst);

  data->run = True;
  data->reader = ThreadOp.inst( "rnreader", &__reader, __RocNetNode );
  ThreadOp.start( data->reader );
  data->scanner = ThreadOp.inst( "rnscanner", &__scanner, __RocNetNode );
  ThreadOp.start( data->scanner );
  data->pwm = ThreadOp.inst( "rnpwm", &__pwm, __RocNetNode );
  ThreadOp.start( data->pwm );
  data->rfidAckWD = ThreadOp.inst( "rfidack", &__rfidAckWD, __RocNetNode );
  ThreadOp.start( data->rfidAckWD );
  data->macroprocessor = ThreadOp.inst( "rnmacro", &__macroProcessor, __RocNetNode );
  ThreadOp.start( data->macroprocessor );

  __initThreads(inst);

  /* Memory watcher */
  while( !bShutdown ) {
    static int cnt1 = 0;
    int cnt2 = MemOp.getAllocCount();
    if( cnt2 > cnt1 ) {
      TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999, "memory allocations old=%u new=%u", cnt1, cnt2 );
    }
    cnt1 = cnt2;
    ThreadOp.sleep( 1000 );

    /* Check for command. */
    if( data->consoleMode )
      __checkConsole( data );
  }

  return 0;
}


static Boolean _shutdown( void ) {
  iORocNetNodeData data = Data(__RocNetNode);
  byte msg[32];
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Shutdown the RocNetNode" );

  MemOp.set( msg, 0, sizeof(msg));
  msg[RN_PACKET_NETID] = data->location;
  msg[RN_PACKET_GROUP] = RN_GROUP_STATIONARY;
  rnReceipientAddresToPacket( 0, msg, 0 );
  rnSenderAddresToPacket( data->id, msg, 0 );
  msg[RN_PACKET_ACTION] = RN_STATIONARY_SHUTDOWN;
  msg[RN_PACKET_ACTION] |= (RN_ACTIONTYPE_EVENT << 5);
  msg[RN_PACKET_LEN] = 0;
  __sendRN(__RocNetNode, msg);

  if(data->pRFID != NULL) {
    data->pRFID->halt((obj)data->pRFID, True, False);
  }

  if(data->pDI != NULL) {
    data->pDI->halt((obj)data->pDI, True, False);
  }

  data->run = False;
  ThreadOp.sleep(1000);
  bShutdown = True;
  __writePort(__RocNetNode, data->LED1, 1, IO_DIRECT );
  __writePort(__RocNetNode, data->LED2, 1, IO_DIRECT );
  return False;
}


static void _stop( void ) {
}

/**  */
static struct ORocNetNode* _inst( iONode ini ) {
  printf( "Initialize the AccNode......\n" );
  if( __RocNetNode == NULL ) {
    __RocNetNode = allocMem( sizeof( struct ORocNetNode ) );
    iORocNetNodeData data = allocMem( sizeof( struct ORocNetNodeData ) );
    MemOp.basecpy( __RocNetNode, &RocNetNodeOp, 0, sizeof( struct ORocNetNode ), data );

    /* Initialize data->xxx members... */
    SystemOp.inst();
    data->libpath = ".";
    data->inifile = ROCNETNODEINI;

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Instance created of the RocNetNode" );

  }
  return __RocNetNode;
}




/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocnetnode/impl/rocnetnode.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
