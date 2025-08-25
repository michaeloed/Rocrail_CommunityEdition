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

#define MIN_IB_VERSION_FOR_EXTENDED_FUNCTIONS          0x2000L /* 2.000 */
#define MIN_OPENDCC_VERSION_FOR_EXTENDED_FUNCTIONS     0x1708L /* 23.08 */
#define MIN_TAMS_VERSION_FOR_EXTENDED_FUNCTIONS    0x01040666L /* 1.4.6f */
#define MAX_FB 128


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "rocdigs/impl/p50x_impl.h"

#include "rocs/public/trace.h"
#include "rocs/public/node.h"
#include "rocs/public/attr.h"
#include "rocs/public/mem.h"
#include "rocs/public/str.h"
#include "rocs/public/system.h"

#include "rocrail/wrapper/public/DigInt.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/FunCmd.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Response.h"
#include "rocrail/wrapper/public/Program.h"
#include "rocrail/wrapper/public/State.h"
#include "rocrail/wrapper/public/BinCmd.h"

#include "rocutils/public/addr.h"


static int instCnt = 0;

/*
 ***** OBase functions.
 */
static const char* __id( void* inst ) {
  return NULL;
}

static void* __event( void* inst, const void* evt ) {
  return NULL;
}

static const char* __name(void) {
  return name;
}
static unsigned char* __serialize(void* inst, long* size) {
  return NULL;
}
static void __deserialize(void* inst, unsigned char* a) {
}
static char* __toString(void* inst) {
  iOP50xData data = Data(inst);
  return (char*)data->iid;
}
static void __del(void* inst) {
  iOP50xData data = Data(inst);
  freeMem( data );
  freeMem( inst );
  instCnt--;
}
static void* __properties(void* inst) {
  return NULL;
}
static struct OBase* __clone( void* inst ) {
  return NULL;
}
static Boolean __equals( void* inst1, void* inst2 ) {
  return False;
}
static int __count(void) {
  return instCnt;
}


/*
 ***** Private functions.
 */
static void __recoverCom(iOP50xData data) {
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "trying to recover communication...");
  if( data->serial != NULL )
    SerialOp.base.del( data->serial );
  data->serial = SerialOp.inst( data->device );
  SerialOp.setFlow( data->serial, data->flow );
  SerialOp.setLine( data->serial, data->bps, data->bits, data->stopBits, data->parity, wDigInt.isrtsdisabled( data->ini ) );
  SerialOp.setTimeout( data->serial, data->timeout, data->timeout );
  data->serialOK = SerialOp.open( data->serial );

}

static Boolean __flushP50x( iOP50xData o ) {
  Boolean ok = False;
  /* Read all pending information on serial port. Interface Hickups if data is pending from previous init! */
  if( !o->dummyio && MutexOp.trywait( o->mux, o->timeout ) ) {
    byte buffer[256];
    int bAvail = SerialOp.available(o->serial);
    if( bAvail > 0 && bAvail < 256 ) {
      TraceOp.trc(name, TRCLEVEL_WARNING, __LINE__, 9999, "Flushing %d bytes...", bAvail);
      SerialOp.read( o->serial, (char*)buffer, bAvail );
      TraceOp.dump( NULL, TRCLEVEL_WARNING, (char*)buffer, bAvail );
    }
    else if(bAvail >= 256) {
      TraceOp.trc(name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Can not flush %d bytes, check your hardware!", bAvail);
      ok = False;
    }
    else {
      TraceOp.trc(name, TRCLEVEL_DEBUG, __LINE__, 9999, "flushed");
      ok = True;
    }
    MutexOp.post( o->mux );
  }
  return ok;
}



static Boolean __transact( iOP50xData o, char* out, int outsize, char* in, int insize, int inendbyte ) {
  if( MutexOp.trywait( o->mux, o->timeout ) ) {
    Boolean rc = False;
    p50state state = P50_OK;

    TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999, "outsize=%d insize=%d inendbyte=0x%02X", outsize, insize, inendbyte);
    TraceOp.dump( NULL, TRCLEVEL_BYTE, out, outsize );

    if( !o->serialOK ) {
      MutexOp.post( o->mux );
      return False;
    }

    if( state == P50_OK ) {

      if( o->dummyio ) {
        MutexOp.post( o->mux );
        return True;
      }


      if( SerialOp.write( o->serial, out, outsize ) ) {
        state = P50_OK;
        if( insize == -1 ) {
          /* First in byte tells how much bytes are comming. */
          if( SerialOp.read( o->serial, in, 1 ) ) {
            state = P50_OK;
            insize = in[0];
          }
          else {
            state = P50_RCVERR;
            TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "unable to read first byte of %d", insize);
          }
        }
        if( insize > 0 ) {
          TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999, "insize=%d, inendbyte=0x%02X", insize, inendbyte);
          if( inendbyte != -1 ) {
            int readCnt = 0;
            while( state == P50_OK && readCnt < insize ) {
              Boolean readOK = SerialOp.read( o->serial, in+readCnt, 1 );
              state = (readOK ? P50_OK:P50_RCVERR);
              if( in[readCnt] == inendbyte ) {
                TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999, "inendbyte detected at position %d", readCnt);
                TraceOp.dump( NULL, TRCLEVEL_BYTE, in, readCnt+1 );
                break;
              }
              readCnt++;
            }
            TraceOp.dump( NULL, TRCLEVEL_BYTE, in, readCnt );

            if( state == P50_RCVERR ) {
              TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "unable to read in end byte [0x%02X]", inendbyte);
            }
          }
          else {
            if( SerialOp.read( o->serial, in, insize ) ) {
              TraceOp.dump( NULL, TRCLEVEL_BYTE, in, insize );
              state = P50_OK;
            }
            else {
              state = P50_RCVERR;
              TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "unable to read %d bytes", insize);
            }
          }
        }
      }
      else {
        /* error: try to recover? */
        state = P50_SNDERR;
        TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "communication error");
        ThreadOp.sleep(1000);
        __recoverCom(o);
      }
    }
    if( state != P50_OK ) {
      const char* strState = state == P50_RCVERR?"RCVERR":"SNDERR";
      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999,
        "ERROR in transact!!! rc=%d state=%s\n", SerialOp.getRc( o->serial ), strState );
    }
    MutexOp.post( o->mux );

    if( state != o->state ) {
      /* inform listener: Node3 */
      int errLevel = TRCLEVEL_INFO;
      iONode nodeC = NodeOp.inst( wDigInt.name(), NULL, ELEMENT_NODE );
      wResponse.setsender( nodeC, o->device );

      switch( state ) {
      case P50_OK:
        wResponse.setmsg( nodeC, "OK." );
        wResponse.setstate( nodeC, wResponse.ok );
        errLevel = TRCLEVEL_INFO;
        break;
      case P50_CTSERR:
        wResponse.setmsg( nodeC, "CTS error." );
        wResponse.setstate( nodeC, wResponse.ctserr );
        errLevel = TRCLEVEL_EXCEPTION;
        break;
      case P50_SNDERR:
        wResponse.setmsg( nodeC, "Write error." );
        wResponse.setstate( nodeC, wResponse.snderr );
        errLevel = TRCLEVEL_EXCEPTION;
        break;
      case P50_RCVERR:
        wResponse.setmsg( nodeC, "Read error." );
        wResponse.setstate( nodeC, wResponse.rcverr );
        errLevel = TRCLEVEL_EXCEPTION;
        break;
      case P50_ERROR:
        break;
      }

      if( o->listenerFun != NULL && o->listenerObj != NULL )
        o->listenerFun( o->listenerObj, nodeC, errLevel );
      o->state = state;
    }

    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "_transact state=%d outsize=%d insize=%d",
                   state, outsize, insize );
    return state == P50_OK ? True:False;
  }
  return False;
}

/**
 * @param node <sw unit="1" pin="1" cmd="straight"/>
 * @param node <lc addr="1" speed="0" fn="false" sw="false"/>
 * @param node <fn addr="1" f1="false" f2="false" f3="false" f4="false"/>
 * @param node <fb unit="1"/>
 * @param node <sys cmd="stop"/>
 * @param p50 Request buffer.
 * @param insize Responce size.
 * @return Request size.
 */
static int __translate( iOP50xData o, iONode node, unsigned char* p50, int* insize, int* inendbyte, iONode* rsp ) {
  *insize = 0;
  /* BinCmd command. */
  if( StrOp.equals( NodeOp.getName( node ), wBinCmd.name() ) ) {
    *insize = wBinCmd.getinlen(node);
    *inendbyte = wBinCmd.getinendbyte(node);
    int outLen = wBinCmd.getoutlen(node);
    byte* outBytes = StrOp.strToByte( wBinCmd.getout(node));
    MemOp.copy( p50, outBytes, outLen );
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "bin command: outlen=%d inlen=%d", outLen, *insize );
    return outLen;

  }
  /* Switch command. */
  else if( StrOp.equals( NodeOp.getName( node ), wSwitch.name() ) ) {
    int mod = wSwitch.getaddr1( node );
    int pin = wSwitch.getport1( node );
    byte cmd = 0x80;
    const char* cmdstr = "straight";
    int addr = 0;
    int gate = wSwitch.getgate1( node );

    if( pin == 0 )
      AddrOp.fromFADA( mod, &mod, &pin, &gate );
    else if( mod == 0 && pin > 0 )
      AddrOp.fromPADA( pin, &mod, &pin );

    addr = (mod-1) * 4 + pin;

    if( addr < 1 )
      return 0;

    if( StrOp.equals( wSwitch.getcmd( node ), wSwitch.turnout ) ) {
      cmd = 0x00;
      cmdstr = "thrown";
    }

    /* to get two decouples at one address: */
    if( StrOp.equals( wSwitch.gettype(node), wSwitch.decoupler ) )
      cmd = wSwitch.getgate1( node )==0?0x00:0x80;

    p50[0] = (byte)'x';
    p50[1] = 0x90;
    p50[2] = (byte)(addr&0xFF);
    p50[3] = (addr >> 8) & 0x07;
    p50[3] |= cmd;
    p50[3] |= (wSwitch.isactivate( node )?0x40:0x00); /* Set active */
    *insize = 1; /* Return code from P50x. */
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "turnout %d %s", addr, cmdstr );

    if( o->echoswcmds ){
      iONode nodeC = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      wSwitch.setbus( nodeC, wSwitch.getbus( node ) );
      wSwitch.setaddr1( nodeC, wSwitch.getaddr1( node ) );
      wSwitch.setport1( nodeC, wSwitch.getport1( node ) );
      if( wSwitch.getiid(node) != NULL )
        wSwitch.setiid( nodeC, wSwitch.getiid(node) );
      wSwitch.setstate( nodeC, wSwitch.getcmd( node ) );
      o->listenerFun( o->listenerObj, nodeC, TRCLEVEL_INFO );
    }
    return 4;
  }

  /* Output command. */
  else if( StrOp.equals( NodeOp.getName( node ), wOutput.name() ) ) {
    int mod = wOutput.getaddr( node );
    int pin = wOutput.getport( node );
    int addr = 0;
    int gate = wOutput.getgate( node );
    byte action = 0;
    byte cmd = 0;
    const char* cmdstr = NULL;

    if( pin == 0 )
      AddrOp.fromFADA( mod, &mod, &pin, &gate );
    else if( mod == 0 && pin > 0 )
      AddrOp.fromPADA( pin, &mod, &pin );

    action = StrOp.equals( wOutput.getcmd( node ), wOutput.on ) ? 0x40:0x00;
    cmd = gate==0?0x00:0x80;
    cmdstr = action?"on":"off";

    addr = (mod-1) * 4 + pin;

    if( addr < 1 )
      return 0;

    p50[0] = (byte)'x';
    p50[1] = 0x90;
    p50[2] = (byte)(addr&0xFF);
    p50[3] = (addr >> 8) & 0x07;
    p50[3] |= cmd;
    p50[3] |= action; /* Set active */
    *insize = 1; /* Return code from P50x. */
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "output %d at gate %d %s", addr, gate, cmdstr );
    return 4;
  }


  /* Signal command. */
  else if( StrOp.equals( NodeOp.getName( node ), wSignal.name() ) ) {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
        "Signal commands are no longer supported at this level." );
    return 0;
  }


  /* Loc command. */
  else if( StrOp.equals( NodeOp.getName( node ), wLoc.name() ) ) {
    int   addr = wLoc.getaddr( node );
    int  speed = 0;
    Boolean fn = wLoc.isfn( node );
    int    dir = wLoc.isdir( node );

    if( wLoc.getV( node ) != -1 ) {
      if( StrOp.equals( wLoc.getV_mode( node ), wLoc.V_mode_percent ) )
        speed = (wLoc.getV( node ) * 126) / 100;
      else if( wLoc.getV_max( node ) > 0 )
        speed = (wLoc.getV( node ) * 126) / wLoc.getV_max( node );
    }
    if( speed > 0 ) {
      /* skip step 1: emergency break */
      speed++;
    }

    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "loc %d speed=%d lights=%s dir=%s",
        addr, speed, fn?"on":"off", dir?"forwards":"reverse" );

    p50[0] = (byte)'x';
    p50[1] = 0x80;
    p50[2] = (byte)(addr&0xFF);
    p50[3] = (addr >> 8) & 0xFF;
    p50[4] = speed;
    p50[5] = 0; /* reset */
    p50[5] |= fn?0x10:0x00;
    p50[5] |= dir?0x20:0x00;
    p50[5] |= (o->force?0x40:0x00); /* Force */
    *insize = 1; /* Return code from P50x. */
    return 6;
  }
  /* Function command. */
  else if( StrOp.equals( NodeOp.getName( node ), wFunCmd.name() ) ) {
    int   addr = wFunCmd.getaddr( node );
    int group = wFunCmd.getgroup(node);
    if( group > 4 ) {
      Boolean f1 = wFunCmd.isf17 ( node );
      Boolean f2 = wFunCmd.isf18( node );
      Boolean f3 = wFunCmd.isf19( node );
      Boolean f4 = wFunCmd.isf20( node );
      Boolean f5 = wFunCmd.isf21( node );
      Boolean f6 = wFunCmd.isf22( node );
      Boolean f7 = wFunCmd.isf23( node );
      Boolean f8 = wFunCmd.isf24( node );
      Boolean f9  = wFunCmd.isf25( node );
      Boolean f10 = wFunCmd.isf26( node );
      Boolean f11 = wFunCmd.isf27( node );
      Boolean f12 = wFunCmd.isf28( node );
      int   info  = (f1?0x01:0) + (f2?0x02:0) + (f3?0x04:0) + (f4?0x08:0) + (f5?0x10:0) + (f6?0x20:0) + (f7?0x40:0) + (f8?0x80:0);
      int   info2 = (f9?0x01:0) + (f10?0x02:0) + (f11?0x04:0) + (f12?0x08:0);
      p50[0] = (byte)'x';
      p50[1] = 0x8A;
      p50[2] = (byte)(addr&0xFF);
      p50[3] = (addr >> 8) & 0xFF;
      p50[4] = (unsigned char)info;
      p50[5] = (unsigned char)info2;
      *insize = 1; /* Return code from P50x. */
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999,
              "loc %d f17=%s f18=%s f19=%s f20=%s f21=%s f22=%s f23=%s f24=%s f25=%s f26=%s f27=%s f28=%s",
              addr, f1?"on":"off", f2?"on":"off", f3?"on":"off", f4?"on":"off",
              f5?"on":"off", f6?"on":"off", f7?"on":"off", f8?"on":"off",
              f9?"on":"off", f10?"on":"off", f11?"on":"off", f12?"on":"off");
      return 6;
    }
    else if( group > 2 ) {
      Boolean f1 = wFunCmd.isf9 ( node );
      Boolean f2 = wFunCmd.isf10( node );
      Boolean f3 = wFunCmd.isf11( node );
      Boolean f4 = wFunCmd.isf12( node );
      Boolean f5 = wFunCmd.isf13( node );
      Boolean f6 = wFunCmd.isf14( node );
      Boolean f7 = wFunCmd.isf15( node );
      Boolean f8 = wFunCmd.isf16( node );
      int   info = (f1?0x01:0) + (f2?0x02:0) + (f3?0x04:0) + (f4?0x08:0) + (f5?0x10:0) + (f6?0x20:0) + (f7?0x40:0) + (f8?0x80:0);
      p50[0] = (byte)'x';
      p50[1] = 0x89;
      p50[2] = (byte)(addr&0xFF);
      p50[3] = (addr >> 8) & 0xFF;
      p50[4] = (unsigned char)info;
      *insize = 1; /* Return code from P50x. */
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999,
              "loc %d f9=%s f10=%s f11=%s f12=%s f13=%s f14=%s f15=%s f16=%s",
              addr, f1?"on":"off", f2?"on":"off", f3?"on":"off", f4?"on":"off",
              f5?"on":"off", f6?"on":"off", f7?"on":"off", f8?"on":"off" );
      return 5;
    }
    else {
      Boolean f1 = wFunCmd.isf1( node );
      Boolean f2 = wFunCmd.isf2( node );
      Boolean f3 = wFunCmd.isf3( node );
      Boolean f4 = wFunCmd.isf4( node );
      Boolean f5 = wFunCmd.isf5( node );
      Boolean f6 = wFunCmd.isf6( node );
      Boolean f7 = wFunCmd.isf7( node );
      Boolean f8 = wFunCmd.isf8( node );
      int   info = (f1?0x01:0) + (f2?0x02:0) + (f3?0x04:0) + (f4?0x08:0) + (f5?0x10:0) + (f6?0x20:0) + (f7?0x40:0) + (f8?0x80:0);
      p50[0] = (byte)'x';
      p50[1] = 0x88;
      p50[2] = (byte)(addr&0xFF);
      p50[3] = (addr >> 8) & 0xFF;
      p50[4] = (unsigned char)info;
      *insize = 1; /* Return code from P50x. */
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999,
              "loc %d f1=%s f2=%s f3=%s f4=%s f5=%s f6=%s f7=%s f8=%s",
              addr, f1?"on":"off", f2?"on":"off", f3?"on":"off", f4?"on":"off",
              f5?"on":"off", f6?"on":"off", f7?"on":"off", f8?"on":"off" );
      return 5;
    }
  }
  /* System command. */
  else if( StrOp.equals( NodeOp.getName( node ), wSysCmd.name() ) ) {
    const char* cmd = wSysCmd.getcmd( node );
    if( StrOp.equals( cmd, wSysCmd.enablecom ) ) {
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "%s: %s communication", o->iid, wSysCmd.getval(node) == 1 ? "enable":"disable" );
      o->dummyio = wSysCmd.getval(node) == 0 ? True:False;
    }
    else if( StrOp.equals( cmd, wSysCmd.stop ) ) {
      p50[0] = (byte)'x';
      p50[1] = 0xa6;
      *insize = 1; /* Return code from P50x. */
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "Power OFF" );
      return 2;
    }
    else if( StrOp.equals( cmd, wSysCmd.ebreak ) ) {
      p50[0] = (byte)'x';
      p50[1] = 0xa5;
      *insize = 1; /* Return code from P50x. */
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "Emergency Break" );
      return 2;
    }
    else if( StrOp.equals( cmd, wSysCmd.go ) ) {
      p50[0] = (byte)'x';
      p50[1] = 0xa7;
      *insize = 1; /* Return code from P50x. */
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "Power ON" );
      return 2;
    }
    else if( StrOp.equals( cmd, wSysCmd.loccnfg ) ) {
      int addr = wSysCmd.getval( node );
      int decformat = wSysCmd.getvalA( node );
      int speedsteps = wSysCmd.getvalB( node );
      if( speedsteps == 128 )
        speedsteps = 126;
      p50[0] = (byte)'x';
      p50[1] = 0x86;
      p50[2] = addr & 0x00FF;
      p50[3] = ((addr & 0xFF00) >> 8 );
      p50[4] = decformat;
      p50[5] = speedsteps;
      *insize = 1; /* Return code from P50x. */
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "Loc[%d] Config: format=%d, steps=%d", addr, decformat, speedsteps  );
      return 6;
    }
  }
  /* Feedback command. */
  else if( StrOp.equals( NodeOp.getName( node ), wFeedback.name() ) ) {
    int addr = wFeedback.getaddr( node );
    Boolean state = wFeedback.isstate( node );

    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "simulate fb addr=%d state=%s", addr, state?"true":"false" );
    *rsp = (iONode)NodeOp.base.clone( node );
    return 0;
  }
  /* Program command. */
  else if( StrOp.equals( NodeOp.getName( node ), wProgram.name() ) ) {
    if(  wProgram.getcmd( node ) == wProgram.ptstat ) {
      p50[0] = (byte)'x';
      p50[1] = 0xE0;
      *insize = 1;
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "PT stat" );
      return 2;
    }
    else if(  wProgram.getcmd( node ) == wProgram.pton ) {
      p50[0] = (byte)'x';
      p50[1] = 0xE1;
      *insize = 1;
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "PT ON" );
      return 2;
    }
    else if( wProgram.getcmd( node ) == wProgram.ptoff ) {
      p50[0] = (byte)'x';
      p50[1] = 0xE2;
      *insize = 1;
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "PT OFF" );
      return 2;
    }
    else if( wProgram.getcmd( node ) == wProgram.get ) {
      int cv = wProgram.getcv( node );
      o->cv_nr = cv;
      p50[0] = (byte)'x';
      p50[1] = 0xF0;
      p50[2] = cv & 0xFF;
      p50[3] = cv >> 8;
      *insize = 1;
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "get CV%d", cv );
      return 4;
    }
    else if( wProgram.getcmd( node ) == wProgram.set ) {
      int addr = wProgram.getaddr( node );
      int cv = wProgram.getcv( node );
      int val = wProgram.getvalue( node );
      o->cv_nr = cv;
      o->cv_val = val;
      if( wProgram.ispom(node) ) {
        /*
        XDCC_PD (0xDE)- Länge = 1+5 Bytes
                0: 0xDE XDCC_PD (= Lok-Programmieren auf dem Hauptgleis = POM)
                1: LSB der Lokadresse
                2: MSB der Lokadresse (1-10239)
                3: Low Byte der CV-Adresse, welche zu schreiben ist.
                4: High Byte der CV-Adresse, welche zu schreiben ist. (1..1024)
                5: Wert

        Antwort: 0 = Ok, accepted
                 0x80 = busy, command ignored
        */
        p50[0] = (byte)'x';
        p50[1] = 0xDE;
        p50[2] = addr & 0xFF;
        p50[3] = addr >> 8;
        p50[4] = cv & 0xFF;
        p50[5] = cv >> 8;
        p50[6] = val;
        *insize = 1;
        TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "POM: set CV%d to %d", cv, val );
        return 7;
      }
      else {
        p50[0] = (byte)'x';
        p50[1] = 0xF1;
        p50[2] = cv & 0xFF;
        p50[3] = cv >> 8;
        p50[4] = val;
        *insize = 1;
        TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "set CV%d to %d", cv, val );
        return 5;
      }
    }
  }

  return 0;
}


static Boolean __getversion( iOP50x inst ) {
  iOP50xData data = Data(inst);
  char out[8] = {'x',0xA0};
  char in[256];
  char inVersion[256];
  char inSerno[256];
  char rl = 0;
  int idx = 0;
  int outsize = 2;
  int insize = 0;
  int sizeVersion = 0;
  int sizeSerno = 0;
  p50state state = P50_OK;
  Boolean ok = False;
  memset(in,0,32);

  if( !data->dummyio && MutexOp.trywait( data->mux, data->timeout ) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Sending XNOP..." );
    out[0]= 'x';
    out[1]= 0xC4;

    if( SerialOp.write( data->serial, (char*)out, 2 ) ) {
      if( !SerialOp.read( data->serial, (char*)in, 1 ) )
        state = P50_RCVERR;
    }
    else
      state = P50_SNDERR;

    if( state == P50_OK ) {
      int bAvail = 0;
      ThreadOp.sleep( 500 );
      bAvail = SerialOp.available(data->serial);
      if( bAvail > 0 && bAvail < 32 )
        SerialOp.read( data->serial, (char*)in, bAvail );
      if( bAvail == 1 ) {
        TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Wrong protocol syntax detected! Set the interface syntax to 6050 & IB. (SO2=2)" );
        MutexOp.post( data->mux );
        return False;
      }
    }

    MutexOp.post( data->mux );
  }


  if( !data->dummyio && MutexOp.trywait( data->mux, data->timeout ) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Version info requested..." );
    out[0]= 'x';
    out[1]= 0xA0;

    if( SerialOp.write( data->serial, (char*)out, 2 ) ) {
      /* First in byte tells how much bytes are comming. */
      if( SerialOp.read( data->serial, in, 1 ) ) {
        state = P50_OK;
        sizeVersion = in[0];
      }
      else {
        state = P50_RCVERR;
        MutexOp.post( data->mux );
        return False;
      }

      if( SerialOp.read( data->serial, inVersion, sizeVersion ) ) {
        state = P50_OK;
      }
      else {
        state = P50_RCVERR;
        MutexOp.post( data->mux );
        return False;
      }

      /* Read the rest of the XVer: */
      /* store all into inSerno-buffer, because last item read will be the serno */
      do {
        rl = 0;
        ok = SerialOp.read( data->serial, &rl, 1 );
        if( ok && rl > 0 ) {
          ok = SerialOp.read( data->serial, inSerno, rl );
          if( ok )
            sizeSerno = rl;
          else
            sizeSerno = 0;
        }
        else if( rl == 0 ) {
          /* End of sequence. */
          break;
        }
        idx++;
      } while( ok && rl > 0 && idx < 10 );

      MutexOp.post( data->mux );
    } /* End of reading */

    /*
     * Version Info:
     * IB      6 answers first is 2 Bytes (BCD)
     * OpenDCC 1 answer           1 Bytes (BYTE) (until V0.14, only version)
     * OpenDCC 1 answer           2 Bytes (BYTE) (since V0.15, version+serno combined)
     * OpenDCC 2 answers first is 2 Bytes (BYTE) (since V0.23.8release)
     * Tams    2 answers first is 3 Bytes (BCD) or 4 Bytes (3*BCD + ASCII)
     * MoPi    2 answer           3 Bytes (BYTE) (stores version: major, minor, build)
     */

    TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999, "__getversion sizeVersion %d sizeSerno %d idx %d", sizeVersion, sizeSerno, idx );
    TraceOp.dump( NULL, TRCLEVEL_BYTE, inVersion, sizeVersion );
    TraceOp.dump( NULL, TRCLEVEL_BYTE, inSerno, sizeSerno );

    switch (sizeVersion) {
      case 0:
        if (sizeSerno == 3)
        {
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "MoPi connector --- %d.%d.%d ---",
                                                 (unsigned int) (inSerno[0]),
                                                 (unsigned int) (inSerno[1]),
                                                 (unsigned int) (inSerno[2]));
        }
        break;

      case 1:
        if( idx == 0 ) {
          /* OpenDCC until V0.14, only version (1 byte) */
          data->swversion = ( inVersion[0] & 0xFF ) << 8 ;

          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "OpenDCC version --- 0.%d.0 ---",
                                                                  (unsigned int) (inVersion[0] & 0xFF) );
        }
        break;
      case 2:
        if( idx == 0 ) {
          /* OpenDCC V0.15 until V0.23.8beta, (2 bytes version+serno) */
          data->swversion = ( inVersion[0] & 0xFF ) << 8 ;

          if( (inVersion[0] & 0xFF) == 86 ) {
            TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "MDRRC version --- 0.%d.0 ---",
                                                                    (unsigned int) (inVersion[0] & 0xFF) );
            TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "MDRRC serial# --- %d ---",
                                                                    (unsigned int) (inVersion[1] & 0xFF) );
            data->echoswcmds = True;
          }
          else {
            TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "OpenDCC version --- 0.%d.0 ---",
                                                                    (unsigned int) (inVersion[0] & 0xFF) );
            TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "OpenDCC serial# --- %d ---",
                                                                    (unsigned int) (inVersion[1] & 0xFF) );
          }
        }
        else if( idx == 1 ) {
          /* OpenDCC since V0.23.8 (2 bytes version + 1 byte serno) */
          data->swversion = ( ( inVersion[0] & 0xFF ) << 8 ) + ( inVersion[1] & 0xFF );
          if( data->swversion >= MIN_OPENDCC_VERSION_FOR_EXTENDED_FUNCTIONS ) {
            data->useextfunc = True;
            TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "activated extended function commands" );
          }
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
                   "OpenDCC version --- %d.%d ---%s",
                   (inVersion[0] & 0xFF),
                   (inVersion[1] & 0xFF),
                   data->useextfunc?" extended functions enabled":""
                   );
          TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "OpenDCC version --- %lX (MinVerExt %lX UseExt %s) ---", 
                     data->swversion, (unsigned long) MIN_OPENDCC_VERSION_FOR_EXTENDED_FUNCTIONS, data->useextfunc?"TRUE":"FALSE" );

          if( sizeSerno == 1 ) {
            TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "OpenDCC serial# --- %d ---",
                                                                  (unsigned int) (inSerno[0] & 0xFF) );
          }
        }
        else { /* idx should be 5, I verify/check this only for the serial# */
          /* Intellibox */
          data->swversion = ( ( inVersion[1] & 0xFF ) << 8 ) + ( inVersion[0] & 0xFF );
          if( data->swversion >= MIN_IB_VERSION_FOR_EXTENDED_FUNCTIONS ) {
            data->useextfunc = True;
            TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "activated extended function commands" );
          }
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
                   "Intellibox version --- %c.%c%c%c ---%s",
                   ((inVersion[1] & 0xF0) >> 4) + 0x30,
                   (inVersion[1] & 0x0F) + 0x30,
                   ((inVersion[0] & 0xF0) >> 4) + 0x30,
                   (inVersion[0] & 0x0F) + 0x30,
                   data->useextfunc?" extended functions enabled":""
                   );
          TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Intellibox version --- %lX (MinVerExt %lX UseExt %s) ---", 
                     data->swversion, (unsigned long) MIN_IB_VERSION_FOR_EXTENDED_FUNCTIONS, data->useextfunc?"TRUE":"FALSE" );

          if( idx == 5 && sizeSerno == 5 ) {
            TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
                             "Intellibox serial# --- %c%c%c%c%c%c%c%c%c%c ---",
                             ((inSerno[0] & 0xF0) >> 4) + 0x30,
                             (inSerno[0] & 0x0F) + 0x30,
                             ((inSerno[1] & 0xF0) >> 4) + 0x30,
                             (inSerno[1] & 0x0F) + 0x30,
                             ((inSerno[2] & 0xF0) >> 4) + 0x30,
                             (inSerno[2] & 0x0F) + 0x30,
                             ((inSerno[3] & 0xF0) >> 4) + 0x30,
                             (inSerno[3] & 0x0F) + 0x30,
                             ((inSerno[4] & 0xF0) >> 4) + 0x30,
                             (inSerno[4] & 0x0F) + 0x30
                            );
          }
        }
        break;
      case 3:
      case 4:
        /* Tams */
        inVersion[sizeVersion] = 0x00;
        data->swversion = ( (inVersion[0] & 0xFF) << 24 ) + ( (inVersion[1] & 0xFF) << 16 ) + ( (inVersion[2] & 0xFF) << 8 ) ;
        if (sizeVersion == 4) {
          /* ASCII char ! */
          data->swversion += (inVersion[3] & 0xFF);
        }
        if( data->swversion >= MIN_TAMS_VERSION_FOR_EXTENDED_FUNCTIONS ) {
          data->useextfunc = True;
          TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "TamsMC %s activated extended function commands", data->iid );
        }
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
                   "TamsMC version --- %d.%d.%.d%s ---%s",
                   (inVersion[0] & 0xFF),
                   (inVersion[1] & 0xFF),
                   (inVersion[2] & 0xFF),
                   (sizeVersion == 4) ? inVersion+3 : "",
                   data->useextfunc?" extended functions enabled":""
                   );
        TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "TamsMC version --- %08.8lX (MinVerExt %08.8lX UseExt %s) ---", 
                     data->swversion, (unsigned long) MIN_TAMS_VERSION_FOR_EXTENDED_FUNCTIONS, data->useextfunc?"TRUE":"FALSE" );

        if( idx == 1 && sizeSerno == 4 ) {
        /* Should be sn: */
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
                           "TamsMC serial# --- %02.2X%02.2X%02.2X%02.2X ---",
                           (inSerno[0] & 0xFF), (inSerno[1] & 0xFF), (inSerno[2] & 0xFF), (inSerno[3] & 0xFF)
                          );
        }
        break;
      default:
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "P50X getversion: sizeVersion=%d sizeSerno=%d idx=%d", sizeVersion, sizeSerno, idx );
        break;
    }
  }
  return True;
}


/*
 ***** Public functions.
 */
static Boolean _setListener( obj inst, obj listenerObj,
                             const digint_listener listenerFun ) {
  iOP50xData data = Data(inst);
  data->listenerObj = listenerObj;
  data->listenerFun = listenerFun;
  return True;
}

static Boolean _setRawListener(obj inst, obj listenerObj, const digint_rawlistener listenerFun ) {
  return True;
}

static byte* _cmdRaw( obj inst, const byte* cmd ) {
  return NULL;
}

static iONode _cmd( obj inst, const iONode nodeA ) {
  iOP50xData o = Data(inst);
  unsigned char out[256];
  unsigned char in [512];
  int    insize    = 0;
  int    inendbyte = -1;
  iONode nodeB     = NULL;

  MemOp.set( in, 0x00, sizeof( in ) );

  if( nodeA != NULL ) {
    int size = __translate( o, nodeA, out, &insize, &inendbyte, &nodeB );

    if( StrOp.equals( NodeOp.getName( nodeA ), wSysCmd.name() ) && StrOp.equals( wSysCmd.getcmd( nodeA ), "stopio" ) ) {
      o->stopio = True;
    }
    else if( StrOp.equals( NodeOp.getName( nodeA ), wSysCmd.name() ) && StrOp.equals( wSysCmd.getcmd( nodeA ), "startio" ) ) {
      o->stopio = False;
    }

    else if( size > 0 && __transact( o, (char*)out, size, (char*)in, insize, inendbyte ) ) {
      /* inform listener */
      if( insize > 0 ) {
        if( StrOp.equals( NodeOp.getName( nodeA ), wSwitch.name() ) ) {
          if( in[0] == 0x10 || in[0] == 0x09 ) {
            /* XNOISPC: resend later... */
            TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "XTrnt rc=%02Xh; fifo buffer full", in[0] );
            nodeB = (iONode)NodeOp.base.clone( nodeA );
            wResponse.setretry( nodeB, True );
          }
          else if( in[0] != 0 ) {
            /* Error / Warning */
            TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "XTrnt rc=%02Xh", in[0] );
            TraceOp.dump( NULL, TRCLEVEL_EXCEPTION, (char*)out, size );
            nodeB = NodeOp.inst( NodeOp.getName( nodeA ), NULL, ELEMENT_NODE );
            wResponse.setrc( nodeB, 0 );
            /*wResponse.setrc( nodeB, (int)in[0] );*/
            /*wResponse.seterror( nodeB, True );*/
          }
        }
        else if( !StrOp.equals( NodeOp.getName( nodeA ), wProgram.name() ) ) {
          char* s = StrOp.byteToStr( in, insize );
          nodeB = NodeOp.inst( NodeOp.getName( nodeA ), NULL, ELEMENT_NODE );
          wResponse.setdata( nodeB, s );
          StrOp.free(s);
        }
      }
    }
    /* Cleanup Node1 */
    nodeA->base.del(nodeA);
  }
  /* return Node2 */
  return nodeB;
}

static void _halt( obj inst, Boolean poweroff, Boolean shutdown ) {
  iOP50xData data = Data(inst);
  unsigned char p50[2];

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Shutting down <%s>...", data->iid );
  data->run = False;
  if( poweroff ) {
    p50[0] = (unsigned char)97;
    __transact( data, (char*)p50, 1, NULL, 0, -1 );
  }
  ThreadOp.sleep(100);
  SerialOp.close( data->serial );
}


static Boolean _supportPT( obj inst ) {
  iOP50xData data = Data(inst);
  return True;
}


static void __evaluateState( iOP50xData o, unsigned char* fb1, unsigned char* fb2, int size ) {
  int i = 0;
  for( i = 0; i < size && i < MAX_FB; i++ ) {
    if( fb1[i] != fb2[i] ) {
      int n = 0;
      int addr = 0;
      int state = 0;
      for( n = 0; n < 8; n++ ) {
        if( (fb1[i] & (0x01 << n)) != (fb2[i] & (0x01 << n)) ) {
          addr = i * 8 + (7-n);
          state = (fb2[i] & (0x01 << n)) ? 1:0;
          /*
          TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999, "fb2[%d] i=%d, n=%d", i - i%2, i, n );
          TraceOp.dump ( name, TRCLEVEL_BYTE, &fb2[i-i%2], 2 );
          */
          addr++;
          TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "fb %d = %d", addr, state );
          {
            /* inform listener: Node3 */
            iONode nodeC = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
            wFeedback.setaddr( nodeC, addr );
            wFeedback.setstate( nodeC, state?True:False );
            if( o->iid != NULL )
              wFeedback.setiid( nodeC, o->iid );

            if( o->listenerFun != NULL && o->listenerObj != NULL )
              o->listenerFun( o->listenerObj, nodeC, TRCLEVEL_INFO );
          }
        }
      }
    }
  }
}


static void __evaluateLocoNet( iOP50xData o, int module, byte* value ) {
  /* assuming Lissy */
  char ident[32];
  int identifier = (value[1] << 8) + value[0];
  iONode nodeC = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
  wFeedback.setaddr( nodeC, module );
  wFeedback.setstate( nodeC, identifier > 0 ? True:False );
  StrOp.fmtb(ident, "%d", identifier);
  wFeedback.setidentifier( nodeC, ident );
  if( o->iid != NULL )
    wFeedback.setiid( nodeC, o->iid );

  if( o->listenerFun != NULL && o->listenerObj != NULL )
    o->listenerFun( o->listenerObj, nodeC, TRCLEVEL_INFO );
}


static void __evaluatePTevent( iOP50x p50, byte* in, int size ) {
  iOP50xData o = Data(p50);

  if( size >= 1 ) {
    int cmd = 0;
    int status = in[0];
    int val = -1;

    if( size == 1 ) {
      char* statusstring = "-";
      switch( status ) {
        case 0xFF:
          statusstring = "Timeout";
          break;
        case 0xFE:
          statusstring = "No acknowledge";
          break;
        case 0xFD:
          statusstring = "Short cut!";
          break;
        case 0xFC:
          statusstring = "No decoder detected";
          break;
        case 0xFB:
          statusstring = "Generic error";
          break;
        case 0xFA:
          statusstring = "Error during DCC direct bit mode operation";
          break;
        case 0xF5:
          statusstring = "No PT event to report or pending operation...";
          break;
        case 0xF4:
          statusstring = "Task terminated";
          break;
        case 0x00:
          statusstring = "Command completed, no errors";
          val = o->cv_val;
          break;
        default:
          statusstring = "**Check manual for meaning of status**";
          break;
      }
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "PT [%s] status=%d", statusstring, status );
      cmd = wProgram.statusrsp;
    }
    else {
      val = in[1]; /* cv value or status */
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "CV[%d] value=%d", o->cv_nr, val );
      cmd = wProgram.datarsp;
    }

    /* inform listener */
    iONode node = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setcv( node, o->cv_nr );
    wProgram.setvalue( node, val );
    wProgram.setcmd( node, cmd );
    if( o->iid != NULL )
      wProgram.setiid( node, o->iid );

    if( o->listenerFun != NULL && o->listenerObj != NULL )
      o->listenerFun( o->listenerObj, node, TRCLEVEL_INFO );

  }
}


static void __PTeventReader( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOP50x p50 = (iOP50x)ThreadOp.getParm( th );
  iOP50xData o = Data(p50);
  p50state state = P50_OK;
  byte out[8];
  byte in [32];

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "PTevent reader started." );
  ThreadOp.sleep(500);
  do {

    ThreadOp.sleep( o->psleep );

    out[0] = (byte)'x';
    out[1] = 0xCE;

    if( !o->stopio && !o->dummyio && MutexOp.trywait( o->mux, o->timeout ) ) {
      Boolean ptEvent   = False;
      Boolean bidiEvent = False;
      out[1] = 0xC8;
      if( state == P50_OK ) {
        if( SerialOp.write( o->serial, (char*)out, 2 ) ) {
          byte evt[3] = {0,0,0};
          if( SerialOp.read( o->serial, (char*)&evt[0], 1 ) ) {
            /* 1st flag TODO: evaulate
            TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
                "1st event flags = 0x%02X", evt[0] ); */
            if( evt[0] & 0x80 ) {
              if( SerialOp.read( o->serial, (char*)&evt[1], 1 ) ) {
                /* 2nd flag TODO: evaulate */
                TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
                    "2nd event flags = 0x%02X", evt[1] );
                if( evt[1] & 0x80 ) {
                  if( SerialOp.read( o->serial, (char*)&evt[2], 1 ) ) {
                    /* 3rd flag TODO: evaulate */
                    ptEvent = (evt[2] & 0x21) ? True:False;
                    bidiEvent = (evt[2] & 0x40) ? True:False;
                    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
                        "3rd event flags = 0x%02X", evt[2] );
                  }
                }
              }
            }
          }
        }
        else {
          /* error: try to recover? */
          TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "communication error");
          ThreadOp.sleep(1000);
          __recoverCom(o);
        }
      }

      if( ptEvent ) {
        out[1] = 0xCE;
        if( state == P50_OK ) {
          if( SerialOp.write( o->serial, (char*)out, 2 ) ) {
            byte evt = 0;
            if( SerialOp.read( o->serial, (char*)&evt, 1 ) ) {
              if( evt != 0xF5 && evt < 32 ) {
                if( SerialOp.read( o->serial, (char*)in, evt ) ) {
                  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "PT Event." );
                  TraceOp.dump( NULL, TRCLEVEL_BYTE, (char*)in, evt );
                  __evaluatePTevent( p50, in, evt );
                }
              }
              else {
                TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "PT status = %d (0x%02X)", evt, evt );
              }
            }
          }
        }
      }

      MutexOp.post( o->mux );
    }

  } while( o->run );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Event reader ended." );
}


static void __handleSwitch(iOP50x p50x, int pada, int state) {
  iOP50xData data = Data(p50x);

  int port = 0;
  int addr = 0;
  Boolean value = False;

  if( state & 0x80)
    value = True;

  AddrOp.fromPADA( pada, &addr, &port );

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "sw %d %d = %s", addr, port, value?"straight":"thrown" );

  {
    iONode nodeC = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );

    wSwitch.setaddr1( nodeC, ( addr  ));
    wSwitch.setport1( nodeC, ( port  ));

    if( data->iid != NULL )
      wSwitch.setiid( nodeC, data->iid );

    wSwitch.setstate( nodeC, value?"straight":"turnout" );

    data->listenerFun( data->listenerObj, nodeC, TRCLEVEL_INFO );
  }
}


static void __handleLoco(iOP50x p50x, byte* status) {
  iOP50xData data = Data(p50x);

  iONode nodeC = NULL;

  int addrL = status[2];
  int addrH = status[3] & 0x3F;
  int addr  = addrL + (addrH << 8);

  TraceOp.dump( NULL, TRCLEVEL_BYTE, (char*)status, 5 );

  /* inform listener: Node3 */
  nodeC = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  if( data->iid != NULL )
    wLoc.setiid( nodeC, data->iid );
  wLoc.setaddr( nodeC, addr );
  wLoc.setV_raw( nodeC, status[0] );
  wLoc.setV_rawMax( nodeC, 127 );
  wLoc.setfn( nodeC, (status[3] & 0x40) ? True:False);
  wLoc.setdir( nodeC, (status[3] & 0x80) ? True:False );
  wLoc.setthrottleid( nodeC, "p50x" );
  wLoc.setcmd( nodeC, wLoc.direction );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "addr=%d V_raw=%d dir=%s fn=%s [%02X]",
      addr, status[0], wLoc.isdir(nodeC)?"fwd":"rev", wLoc.isfn(nodeC)?"on":"off", status[3] );
  data->listenerFun( data->listenerObj, nodeC, TRCLEVEL_INFO );

  nodeC = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE );
  if( data->iid != NULL )
    wLoc.setiid( nodeC, data->iid );
  wFunCmd.setaddr( nodeC, addr );
  wFunCmd.setf0( nodeC, (status[3] & 0x40) ? True:False );
  wFunCmd.setf1( nodeC, (status[1] & 0x01) ? True:False );
  wFunCmd.setf2( nodeC, (status[1] & 0x02) ? True:False );
  wFunCmd.setf3( nodeC, (status[1] & 0x04) ? True:False );
  wFunCmd.setf4( nodeC, (status[1] & 0x08) ? True:False );
  wFunCmd.setf5( nodeC, (status[1] & 0x10) ? True:False );
  wFunCmd.setf6( nodeC, (status[1] & 0x20) ? True:False );
  wFunCmd.setf7( nodeC, (status[1] & 0x40) ? True:False );
  wFunCmd.setf8( nodeC, (status[1] & 0x80) ? True:False );
  wLoc.setthrottleid( nodeC, "p50x" );
  wFunCmd.setgroup(nodeC, 0 );

  if( data->useextfunc ) {
    byte out[8];
    byte in[512];

    if( !data->stopio && !data->dummyio && MutexOp.trywait( data->mux, data->timeout ) ) {
      /* XFunc2Sts / XFuncXSts */
      out[0] = (byte)'x';
      out[1] = 0x8D;
      out[2] = (byte)(addr&0xFF);
      out[3] = (addr >> 8) & 0x07;

      /* ask for F9 to F16 */
      TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999, "check for XFuncXSts F9-F16 of %d", addr );
      TraceOp.dump( name, TRCLEVEL_BYTE, (char*)out, 4 );
      if( SerialOp.write( data->serial, (char*)out, 4 ) ) {
        Boolean read = SerialOp.read( data->serial, (char*)&in[0], 1 ) ;
        if( read ) {
          TraceOp.dump( name, TRCLEVEL_DEBUG, (char*)in, 1 );
          if (in[0] == 0x00 ) {
            if( SerialOp.read( data->serial, (char*)in+1, 1 ) ) {
              TraceOp.dump( name, TRCLEVEL_BYTE, (char*)in, 2 );

              wFunCmd.setf9(  nodeC, (in[1] & 0x01) ? True:False );
              wFunCmd.setf10( nodeC, (in[1] & 0x02) ? True:False );
              wFunCmd.setf11( nodeC, (in[1] & 0x04) ? True:False );
              wFunCmd.setf12( nodeC, (in[1] & 0x08) ? True:False );
              wFunCmd.setf13( nodeC, (in[1] & 0x10) ? True:False );
              wFunCmd.setf14( nodeC, (in[1] & 0x20) ? True:False );
              wFunCmd.setf15( nodeC, (in[1] & 0x40) ? True:False );
              wFunCmd.setf16( nodeC, (in[1] & 0x80) ? True:False );
            }
            else {
              TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "unable to read loco event");
            }
          }
          else {
            /* 
               0x02 XBADPRM - Lokadresse ausserhalb des Bereichs (1 .. 10239)
               0x0A XNODATA - Es liegen keine Lokdaten vor (Lok nicht in Refresh-Queue)
            */
            TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "XFuncXSts ERR %02.2X", (int) in[0] );
          }
        }
        else {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "no XFuncXSts reply for addr %d", addr );
        }
      }

      /* XFunc34Sts */
      out[0] = (byte)'x';
      out[1] = 0x8E;
      out[2] = (byte)(addr&0xFF);
      out[3] = (addr >> 8) & 0x07;

      /* ask for F17 to F28 */
      TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999, "check for XFunc34Sts F17-F28 of %d", addr );
      TraceOp.dump( name, TRCLEVEL_BYTE, (char*)out, 4 );
      if( SerialOp.write( data->serial, (char*)out, 4 ) ) {
        Boolean read = SerialOp.read( data->serial, (char*)&in[0], 1 ) ;
        if( read ) {
          TraceOp.dump( name, TRCLEVEL_DEBUG, (char*)in, 1 );
          if (in[0] == 0x00 ) {
            if( SerialOp.read( data->serial, (char*)in+1, 2 ) ) {
              TraceOp.dump( name, TRCLEVEL_BYTE, (char*)in, 3 );

              wFunCmd.setf17( nodeC, (in[1] & 0x01) ? True:False );
              wFunCmd.setf18( nodeC, (in[1] & 0x02) ? True:False );
              wFunCmd.setf19( nodeC, (in[1] & 0x04) ? True:False );
              wFunCmd.setf20( nodeC, (in[1] & 0x08) ? True:False );
              wFunCmd.setf21( nodeC, (in[1] & 0x10) ? True:False );
              wFunCmd.setf22( nodeC, (in[1] & 0x20) ? True:False );
              wFunCmd.setf23( nodeC, (in[1] & 0x40) ? True:False );
              wFunCmd.setf24( nodeC, (in[1] & 0x80) ? True:False );
              wFunCmd.setf25( nodeC, (in[2] & 0x01) ? True:False );
              wFunCmd.setf26( nodeC, (in[2] & 0x02) ? True:False );
              wFunCmd.setf27( nodeC, (in[2] & 0x04) ? True:False );
              wFunCmd.setf28( nodeC, (in[2] & 0x08) ? True:False );
            }
            else {
              TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "unable to read loco event");
            }
          }
          else {
            /* 
               0x02 XBADPRM - Lokadresse ausserhalb des Bereichs (1 .. 10239)
               0x0A XNODATA - Es liegen keine Lokdaten vor (Lok nicht in Refresh-Queue)
            */
            TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "XFunc34Sts ERR %02.2X", (int) in[0] );
          }
        }
        else {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "no XFunc34Sts reply for addr %d", addr );
        }
      }
      MutexOp.post( data->mux );
    }
  }
  data->listenerFun( data->listenerObj, nodeC, TRCLEVEL_INFO );
}

static void __dummy( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOP50x p50 = (iOP50x)ThreadOp.getParm( th );
  iOP50xData data = Data(p50);
  iONode nodeC = NULL;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "tester started." );
  ThreadOp.sleep( 2000 );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "sending throttle event..." );
  nodeC = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  if( data->iid != NULL )
    wLoc.setiid( nodeC, data->iid );
  wLoc.setaddr( nodeC, 1 );
  wLoc.setV_raw( nodeC, 10 );
  wLoc.setV_rawMax( nodeC, 127 );
  wLoc.setthrottleid( nodeC, "dummy" );
  wLoc.setcmd( nodeC, wLoc.direction );
  data->listenerFun( data->listenerObj, nodeC, TRCLEVEL_INFO );

  ThreadOp.sleep( 1000 );
  nodeC = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  if( data->iid != NULL )
    wLoc.setiid( nodeC, data->iid );
  wLoc.setaddr( nodeC, 1 );
  wLoc.setV_raw( nodeC, 77 );
  wLoc.setV_rawMax( nodeC, 127 );
  wLoc.setthrottleid( nodeC, "dummy" );
  wLoc.setcmd( nodeC, wLoc.direction );
  data->listenerFun( data->listenerObj, nodeC, TRCLEVEL_INFO );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "tester ended." );
}


static void __statusReader( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOP50x p50 = (iOP50x)ThreadOp.getParm( th );
  iOP50xData o = Data(p50);
  iOList evtList = ListOp.inst();
  byte out[8];
  byte in[512];
  p50state state = P50_OK;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Status reader started." );
  ThreadOp.sleep( 100 );
  if( !o->dummyio )
    __getversion(p50);

  do {

    ThreadOp.sleep( o->psleep );

    if( !o->stopio && !o->dummyio && MutexOp.trywait( o->mux, o->timeout ) ) {

      out[0] = (byte)'x';
      out[1] = 0xA2; /* xStatus */
      if( SerialOp.write( o->serial, (char*)out, 2 ) ) {
        if( SerialOp.read( o->serial, (char*)in, 1 ) ) {
          Boolean power = (in[0] & 0x08) ? True:False;
          Boolean hot   = (in[0] & 0x04) ? True:False;
          Boolean halt  = (in[0] & 0x10) ? True:False;

          if( power != o->power || hot != o->hot || halt != o->halt ) {
            iONode node = NodeOp.inst( wState.name(), NULL, ELEMENT_NODE );
            if( o->iid != NULL )
              wState.setiid( node, o->iid );
            wState.setpower( node, power );
            wState.settrackbus( node, !halt );
            wState.setsensorbus( node, power );
            wState.setaccessorybus( node, power );
            wState.setenablecom( node, o->dummyio );

            if( o->listenerFun != NULL && o->listenerObj != NULL )
              o->listenerFun( o->listenerObj, node, TRCLEVEL_INFO );

            o->power = power;
            o->hot   = hot;
            o->halt  = halt;
          }
        }
        else {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "no xStatus reply" );
        }
      }



      /* Turnout event */
      out[0] = (byte)'x';
      out[1] = 0xCA; // ask for turnout changes
      if( SerialOp.write( o->serial, (char*)out, 2 ) ) {
        byte ans = 0;
        if( SerialOp.read( o->serial, (char*)&ans, 1 ) ) {
          if (ans > 0x00) {
            if( SerialOp.read( o->serial, (char*)in, (int) ans*2 ) ) {
              int i = 0;
              for ( i = 0; i < ans; i++) {
                 __handleSwitch(p50, in[i*2] + ((in[i*2+1]&0x07) * 256), in[i*2+1]);
              }
            }
            else {
              TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "unable to read switch event");
              TraceOp.dump( name, TRCLEVEL_WARNING, (char*)in, SerialOp.getReadCnt(o->serial) );
            }

          }
        }
        else {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "no XEvtTrnt reply" );
        }
      }


      /* Locomotive 'event' */
      out[0] = (byte)'x';
      out[1] = 0xC9;
      /* ask for locomotive changes */
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "check for XEvtLok..." );
      TraceOp.dump( name, TRCLEVEL_DEBUG, (char*)out, 2 );
      ListOp.clear(evtList);
      if( SerialOp.write( o->serial, (char*)out, 2 ) ) {
        byte* evt = NULL;
        do {
          Boolean read = SerialOp.read( o->serial, (char*)&in[0], 1 ) ;
          if( read ) {
            TraceOp.dump( name, TRCLEVEL_DEBUG, (char*)in, 1 );
            if (in[0] < 0x80 ) {
              if( SerialOp.read( o->serial, (char*)in+1, 4 ) ) {
                TraceOp.dump( name, TRCLEVEL_DEBUG, (char*)in, 5 );
                evt = allocMem(5);
                MemOp.copy( evt, in, 5);
                ListOp.add(evtList, (obj)evt);
              }
              else {
                TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "unable to read loco event");
              }
            }
            else {
              break;
            }
          }
          else {
            TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "no XEvtLok reply" );
            break;
          }
        } while(in[0] != 0x80);
      }
      else {
        /* error: try to recover? */
        TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "communication error");
        ThreadOp.sleep(1000);
        __recoverCom(o);
      }


      MutexOp.post( o->mux );

      /* process the loco events */
      if( ListOp.size(evtList) > 0) {
        int i = 0;
        for( i = 0; i < ListOp.size(evtList); i++ ) {
          byte* evt = (byte*)ListOp.get(evtList, i );
          __handleLoco(p50, evt);
          freeMem(evt);
        }
        ListOp.clear(evtList);
      }

    }

  } while( o->run );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Status reader ended." );

}

static void __feedbackReader( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOP50x p50 = (iOP50x)ThreadOp.getParm( th );
  iOP50xData o = Data(p50);
  byte* fb     = allocMem(MAX_FB);
  byte* s88_in = allocMem(MAX_FB);
  byte out[256];
  byte tmp [8];
  p50state state = P50_OK;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Feedback p50x reader started." );
  /* set byte arrays to a defined state: */
  MemOp.set( out, 0, 256 );
  MemOp.set( s88_in, 0, MAX_FB );

  out[0] = 'x';
  out[1] = 0x99;
  __transact( o, (char*)out, 2, (char*)s88_in, 1, -1 );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Feedback p50x reader initialized." );

  do {
    state = P50_OK;
    ThreadOp.sleep( o->psleep );
    out[0] = (byte)'x';
    out[1] = 0xCB; /*XEvtSen*/

    if( !o->stopio && !o->dummyio && MutexOp.trywait( o->mux, o->timeout ) ) {
      if( state == P50_OK ) {
        TraceOp.dump( NULL, TRCLEVEL_BYTE, (char*)out, 2 );
        if( SerialOp.write( o->serial, (char*)out, 2 ) ) {
          byte module = 0;
          state = P50_OK;
          if( SerialOp.read( o->serial, (char*)&module, 1 ) ) {
            /* modules > 31 are loconet */
            while( module > 0 && module < MAX_FB && state == P50_OK ) {
              TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "fbModule = %d", module );
              TraceOp.dump( NULL, TRCLEVEL_BYTE, (char*)&module, 1 );

              if( !SerialOp.read( o->serial, (char*)tmp, 2 ) ) {
                state = P50_RCVERR;
                break;
              }
              TraceOp.dump( NULL, TRCLEVEL_BYTE, (char*)tmp, 2 );

              if( o->swversion >= MIN_OPENDCC_VERSION_FOR_EXTENDED_FUNCTIONS || module < 32 ) {
                /* s88 */
                s88_in[(module-1)*2] = tmp[0];
                s88_in[((module-1)*2)+1] = tmp[1];
              }
              else {
                /* loconet */
                __evaluateLocoNet( o, module, tmp );
              }

              if( !SerialOp.read( o->serial, (char*)&module, 1 ) ) {
                state = P50_RCVERR;
                break;
              }
            };
          }
          else
            state = P50_RCVERR;
        }
        else {
          /* error: try to recover? */
          state = P50_SNDERR;
          TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "communication error");
          ThreadOp.sleep(1000);
          __recoverCom(o);
        }

      }


      if( state != P50_OK ) {
        const char* strState = state == P50_RCVERR?"RCVERR":"SNDERR";
        TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999,
          "ERROR reading feedbacks!!! rc=%d state=%s\n", SerialOp.getRc( o->serial ), strState );
      }

      MutexOp.post( o->mux );

      /* only compare if communication was OK: */
      if( state == P50_OK ) {
        if( memcmp( fb, s88_in, o->fbmod ) != 0 ) {
          /* inform listener */
          __evaluateState( o, fb, s88_in, o->fbmod);
          memcpy( fb, s88_in, o->fbmod );
        }
      }

    }

    if( o->bidi ) {
      byte bidi_in [32];

      ThreadOp.sleep( 10 );
      out[0] = (byte)'x';
      out[1] = 0xD2; /*XEvtBiDi*/

      if( !o->stopio && !o->dummyio && MutexOp.trywait( o->mux, o->timeout ) ) {
        if( state == P50_OK ) {
          TraceOp.dump( NULL, TRCLEVEL_BYTE, (char*)out, 2 );
          if( SerialOp.write( o->serial, (char*)out, 2 ) ) {
            byte module = 0;
            state = P50_OK;
            if( SerialOp.read( o->serial, (char*)&bidi_in[0], 1 ) ) {
              while( bidi_in[0] & 0x80 ) {
                TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "fbModule = %d", module );
                if( SerialOp.read( o->serial, (char*)&bidi_in[1], 3 ) ) {
                  if( bidi_in[3] & 0x40 ) {
                    if( SerialOp.read( o->serial, (char*)&bidi_in[4], 1 ) ) {
                      /* Speed byte */
                    }
                    else {
                      break;
                    }
                  }
                }
                else {
                  break;
                }

                TraceOp.dump( NULL, TRCLEVEL_BYTE, (char*)bidi_in, 4 );

                /* Report BiDi
                 1. Byte:       bit#   7     6     5     4     3     2     1     0
                                    +-----+-----+-----+-----+-----+-----+-----+-----+
                                    |  LE | res | res | res | D11 | D10 |  D9 |  D8 |
                                    +-----+-----+-----+-----+-----+-----+-----+-----+

                          LE:      0:   Listenende, es folgen keine weiteren Daten.
                                   1:   Es folgen Daten fuer diesen Listeneintrag.
                                   res: reserviert
                          D11-D8:  DID (DID = Detektor-ID), high nibble;

                 2. Byte: D7-D0:   Detektor-ID, Low Byte
                 3. Byte: low byte of Lok# (A7..A0)
                 4. Byte: high byte of Lok#, high byte of Lok#, plus Dir and Speed status, coded as follows:
                                bit#   7     6     5     4     3     2     1     0
                                    +-----+-----+-----+-----+-----+-----+-----+-----+
                                    | Dir | Spd | A13 | A12 | A11 | A10 | A9  | A8  |
                                    +-----+-----+-----+-----+-----+-----+-----+-----+
                          Dir: Lokrichtung
                          Spd: 1: es folgt ein weiteres Byte mit der Istgeschwindigkeit
                 5. Byte: [optional] Speed gemaess der BiDi-Kodierung
                             0..63: speed = value / 2;
                             64..127: speed = value - 32;
                             128..254: speed = value * 4;
                             255: Kennzeichnet eine ungueltige Geschwindkeit (wird u.a. intern verwendet).
                */
                {
                  int bidiAddr = bidi_in[1] + ((bidi_in[0] & 0x0F) << 8) + 1;
                  int locoAddr = bidi_in[2] + ((bidi_in[3] & 0x3F) << 8);
                  char ident[32];
                  Boolean dir = (bidi_in[3] & 0x80) ? True:False;
                  iONode nodeC = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );

                  wFeedback.setaddr( nodeC, bidiAddr );
                  wFeedback.setfbtype( nodeC, wFeedback.fbtype_railcom );

                  if( o->iid != NULL )
                    wFeedback.setiid( nodeC, o->iid );

                  StrOp.fmtb(ident, "%d", locoAddr);
                  wFeedback.setidentifier( nodeC, ident );
                  wFeedback.setstate( nodeC, locoAddr > 0 ?True:False );
                  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999,
                      "BiDi[%d] reports decoder address [%d] %s",
                      bidiAddr, locoAddr, dir?"forwards":"reverse" );

                  o->listenerFun( o->listenerObj, nodeC, TRCLEVEL_INFO );
                }

                /* Next */
                if( !SerialOp.read( o->serial, (char*)&bidi_in[0], 1 ) ) {
                  break;
                }

              }
            }
          }
        }

        MutexOp.post( o->mux );
      }
    }


  } while( o->run );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Feedback p50x reader ended." );
}


static void __feedbackP50Reader( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOP50x p50x = (iOP50x)ThreadOp.getParm( th );
  iOP50xData data = Data(p50x);
  unsigned char* fb = allocMem(MAX_FB);

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Feedback p50 reader started." );
  do {
    unsigned char out[256];
    unsigned char in [MAX_FB];

    ThreadOp.sleep( data->psleep );
    if( data->stopio || data->fbmod == 0 )
      continue;

    out[0] = (unsigned char)(128 + data->fbmod);
    if( __transact( data, (char*)out, 1, (char*)in, data->fbmod, -1 ) ) {
      if( memcmp( fb, in, data->fbmod ) != 0 ) {
        /* inform listener */
        __evaluateState( data, fb, in, data->fbmod);
        memcpy( fb, in, data->fbmod );
      }
    }
  } while( data->run );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Feedback p50 reader ended." );
}

/* Status */
static int _state( obj inst ) {
  iOP50xData data = Data(inst);
  int state = 0;
  return state;
}

/* external shortcut event */
static void _shortcut(obj inst) {
  iOP50xData data = Data( inst );
}


/* VERSION: */
static int vmajor = 2;
static int vminor = 0;
static int patch  = 0;
static int _version( obj inst ) {
  iOP50xData data = Data(inst);
  return vmajor*10000 + vminor*100 + patch;
}

static iOP50x _inst( const iONode settings, const iOTrace trace ) {
  iOP50x     p50x = allocMem( sizeof( struct OP50x ) );
  iOP50xData data = allocMem( sizeof( struct OP50xData ) );
  iOAttr attr = NULL;
  const char* flow = NULL;
  const char* parity = NULL;

  TraceOp.set( trace );

  /* OBase */
  MemOp.basecpy( p50x, &P50xOp, 0, sizeof( struct OP50x ), data );


  data->mux = MutexOp.inst( NULL, True );

  /* Evaluate attributes. */
  data->device   = StrOp.dup( wDigInt.getdevice( settings ) );
  data->iid      = StrOp.dup( wDigInt.getiid( settings ) );
  data->ini      = settings;
  data->force    = wDigInt.isoverrule(settings);

  data->bps      = wDigInt.getbps( settings );
  data->bits     = wDigInt.getbits( settings );
  data->stopBits = wDigInt.getstopbits( settings );
  data->timeout  = wDigInt.gettimeout( settings );
  data->fbmod    = wDigInt.getfbmod( settings );
  data->swtime   = wDigInt.getswtime( settings );
  data->psleep   = wDigInt.getpsleep( settings );
  data->dummyio  = wDigInt.isdummyio( settings );
  data->ctsretry = wDigInt.getctsretry( settings );
  data->readfb   = wDigInt.isreadfb( settings );
  data->run      = True;
  data->bidi     = wDigInt.isreadbidi( settings );

  data->serialOK = False;
  data->initOK = False;


  parity      = wDigInt.getparity( settings );
  flow        = wDigInt.getflow( settings );

  if( StrOp.equals( wDigInt.even, parity ) )
    data->parity = even;
  else if( StrOp.equals( wDigInt.odd, parity ) )
    data->parity = odd;
  else if( StrOp.equals( wDigInt.none, parity ) )
    data->parity = none;

  if( StrOp.equals( wDigInt.dsr, flow ) )
    data->flow = dsr;
  else if( StrOp.equals( wDigInt.cts, flow ) )
    data->flow = cts;
  else if( StrOp.equals( wDigInt.xon, flow ) )
    data->flow = xon;

  if( data->fbmod > MAX_FB )
    data->fbmod = MAX_FB;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "p50x %d.%d.%d", vmajor, vminor, patch );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "iOP50x[%s]: %s,%d,%s,%d,%d,%s",
        wDigInt.getiid( settings ) != NULL ? wDigInt.getiid( settings ):"",
        data->device, data->bps, parity, data->bits, data->stopBits, flow );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "p50x timeout=%d", data->timeout );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "p50x ctsretry=%d", data->ctsretry );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "p50x readbidi=%d", data->bidi );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "p50x readfb=%d", data->readfb );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "p50x fbmod=%d", data->fbmod );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "p50x poll sleep=%d", data->psleep );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "p50x swtime=%d", data->swtime );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );

  data->serial = SerialOp.inst( data->device );
  SerialOp.setFlow( data->serial, data->flow );
  SerialOp.setLine( data->serial, data->bps, data->bits, data->stopBits, data->parity, wDigInt.isrtsdisabled( settings ) );
  SerialOp.setTimeout( data->serial, data->timeout, data->timeout );
  data->serialOK = SerialOp.open( data->serial );

  if( data->serialOK ) {
    __flushP50x(data);

    if( wDigInt.isptsupport( settings ) ) {
      data->eventReader = ThreadOp.inst( "evtreader", &__PTeventReader, p50x );
      ThreadOp.start( data->eventReader );
    }

    data->statusReader = ThreadOp.inst( "statreader", &__statusReader, p50x );
    ThreadOp.start( data->statusReader );

    if( data->readfb && data->fbmod > 0 ) {
      if( wDigInt.isfbpoll( settings ) )
        data->feedbackReader = ThreadOp.inst( "fbreader", &__feedbackP50Reader, p50x );
      else
        data->feedbackReader = ThreadOp.inst( "fbreader", &__feedbackReader, p50x );
      ThreadOp.start( data->feedbackReader );
    }
  }
  else {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Could not init p50x port!" );

    /*
    data->statusReader = ThreadOp.inst( "dummy", &__dummy, p50x );
    ThreadOp.start( data->statusReader );
    */
  }

  instCnt++;

  return p50x;
}

/* Support for dynamic Loading */
iIDigInt rocGetDigInt( const iONode ini ,const iOTrace trc )
{
  return (iIDigInt)_inst(ini,trc);
}
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocdigs/impl/p50x.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
