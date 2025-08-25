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

#include "rocdigs/impl/esunavi_impl.h"

#include "rocs/public/trace.h"
#include "rocs/public/node.h"
#include "rocs/public/attr.h"
#include "rocs/public/mem.h"
#include "rocs/public/str.h"
#include "rocs/public/strtok.h"
#include "rocs/public/system.h"

#include "rocrail/wrapper/public/DigInt.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/Command.h"
#include "rocrail/wrapper/public/FunCmd.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/Item.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Response.h"
#include "rocrail/wrapper/public/FbInfo.h"
#include "rocrail/wrapper/public/FbMods.h"
#include "rocrail/wrapper/public/Program.h"
#include "rocrail/wrapper/public/State.h"
#include "rocrail/wrapper/public/Clock.h"
#include "rocrail/wrapper/public/Accessory.h"

#include "rocutils/public/addr.h"

static int instCnt = 0;

/** ----- OBase ----- */
static void __del( void* inst ) {
  if( inst != NULL ) {
    iOESUNaviData data = Data(inst);
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

/** ----- OESUNavi ----- */
static iOSlot __getSlotByAddr(iOESUNavi inst, int addr) {
  iOESUNaviData data = Data(inst);
  iOSlot slot = NULL;
  if( MutexOp.wait( data->lcmux ) ) {
    slot = (iOSlot)MapOp.first( data->lcmap);
    while( slot != NULL ) {
      if( slot->addr == addr ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "slot found for %s by address %d", slot->id, addr );
        break;
      }
      slot = (iOSlot)MapOp.next( data->lcmap);
    };
    MutexOp.post(data->lcmux);
  }
  return slot;
}


static iOSlot __getSlot(iOESUNavi inst, iONode node) {
  iOESUNaviData data = Data(inst);
  int    addr  = wLoc.getaddr(node);
  iOSlot slot  = NULL;
  char msg[256];

  slot = (iOSlot)MapOp.get( data->lcmap, wLoc.getid(node) );
  if( slot != NULL ) {
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "slot exist for %s", wLoc.getid(node) );
    return slot;
  }

  slot = allocMem( sizeof( struct slot) );
  slot->addr    = addr;
  slot->id      = StrOp.dup(wLoc.getid(node));
  slot->dir     = wLoc.isdir(node);
  slot->steps   = wLoc.getspcnt(node);
  slot->fncnt   = wLoc.getfncnt(node);

  if( StrOp.equals( wLoc.prot_M, wLoc.getprot( node ) ) ) {
    /* Motorola */
    slot->prot = 2;
  }
  else /* Default DCC */
    slot->prot = 1;

  if( MutexOp.wait( data->lcmux ) ) {
    MapOp.put( data->lcmap, wLoc.getid(node), (obj)slot);
    MutexOp.post(data->lcmux);
  }

  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "configure loco %d %s%d %s", addr, slot->prot==2?"m":"d", slot->steps, slot->id );
  StrOp.fmtb(msg, "L %d %s%d \"%s\"\r\n", addr, slot->prot==2?"m":"d", slot->steps, slot->id);
  SerialOp.write( data->serial, msg, StrOp.len(msg) );

  return slot;
}



static iONode __translate( iOESUNavi inst, iONode node ) {
  iOESUNaviData data = Data(inst);
  iONode rsp = NULL;
  char msg[256];

  if( !MutexOp.wait( data->mux ) ) {
    return rsp;
  }

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "cmd=%s", NodeOp.getName( node ) );

  /* System command. */
  if( StrOp.equals( NodeOp.getName( node ), wSysCmd.name() ) ) {
    const char* cmd = wSysCmd.getcmd( node );
    if( StrOp.equals( cmd, wSysCmd.stop ) ) {
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "Power OFF" );
      StrOp.fmtb(msg, "S stop\r\n" );
      SerialOp.write( data->serial, msg, StrOp.len(msg) );
    }
    else if( StrOp.equals( cmd, wSysCmd.ebreak ) ) {
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "EBreak" );
      StrOp.fmtb(msg, "S stopall\r\n" );
      SerialOp.write( data->serial, msg, StrOp.len(msg) );
    }
    else if( StrOp.equals( cmd, wSysCmd.go ) ) {
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "Power ON" );
      StrOp.fmtb(msg, "S go\r\n" );
      SerialOp.write( data->serial, msg, StrOp.len(msg) );
    }
  }

  /* Switch command.
   * ToDo: Timed off.
   */
  else if( StrOp.equals( NodeOp.getName( node ), wSwitch.name() ) ) {
    int addr  = wSwitch.getaddr1( node );
    int state = StrOp.equals( wSwitch.getcmd( node ), wSwitch.straight ) ? 1:0;
    int port  = wSwitch.getport1( node );
    int delay = wSwitch.getdelay(node) > 0 ? wSwitch.getdelay(node):data->swtime;
    if( port > 0 ) {
      addr = AddrOp.toPADA( addr, port );
    }
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "switch %d %s", addr, wSwitch.getcmd(node) );
    StrOp.fmtb(msg, "a a%d %d %s\r\n", addr, state, "on");
    SerialOp.write( data->serial, msg, StrOp.len(msg) );

    /* deactivate the gate to be used */
    iQCmd cmd = allocMem(sizeof(struct QCmd));
    cmd->time   = SystemOp.getTick();
    cmd->delay  = delay / 10;
    StrOp.fmtb(cmd->msg, "a a%d %d %s\r\n", addr, state, "off");
    ThreadOp.post( data->timedQueue, (obj)cmd );
  }

  /* Output command */
  else if( StrOp.equals( NodeOp.getName( node ), wOutput.name() ) ) {
    int addr   = wOutput.getaddr( node );
    int port   = wOutput.getport( node );
    int gate   = wOutput.getgate( node );
    const char* action = StrOp.equals( wOutput.getcmd( node ), wOutput.on ) ? "on":"off";
    if( port > 0 ) {
      addr = AddrOp.toPADA( addr, port );
    }
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "output %d:%d %s", addr, gate, action );
    StrOp.fmtb(msg, "a a%d %d %s\r\n", addr, gate, action);
    SerialOp.write( data->serial, msg, StrOp.len(msg) );
  }

  /* Loc command.*/
  else if( StrOp.equals( NodeOp.getName( node ), wLoc.name() ) ) {
    iOSlot slot = __getSlot(inst, node);
    int   addr = wLoc.getaddr( node );
    slot->dir = wLoc.isdir( node );

    if( wLoc.getV( node ) != -1 ) {
      if( StrOp.equals( wLoc.getV_mode( node ), wLoc.V_mode_percent ) )
        slot->V = (wLoc.getV( node ) * 128) / 100;
      else if( wLoc.getV_max( node ) > 0 )
        slot->V = (wLoc.getV( node ) * 128) / wLoc.getV_max( node );
    }
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "loco %d %s%d", addr, slot->dir?"":"-", slot->V );
    StrOp.fmtb(msg, "l %d %s%d\r\n", addr, slot->dir?"":"-", slot->V);
    SerialOp.write( data->serial, msg, StrOp.len(msg) );
  }

  /* Function command. */
  else if( StrOp.equals( NodeOp.getName( node ), wFunCmd.name() ) ) {
    iOSlot slot = __getSlot(inst, node);
    int addr     = wFunCmd.getaddr(node);
    int fun0_12  = 0;
    int fun13_20 = 0;

    fun0_12 |= wFunCmd.isf0 (node) ? 0x0001:0x0000;
    fun0_12 |= wFunCmd.isf1 (node) ? 0x0002:0x0000;
    fun0_12 |= wFunCmd.isf2 (node) ? 0x0004:0x0000;
    fun0_12 |= wFunCmd.isf3 (node) ? 0x0008:0x0000;
    fun0_12 |= wFunCmd.isf4 (node) ? 0x0010:0x0000;
    fun0_12 |= wFunCmd.isf5 (node) ? 0x0020:0x0000;
    fun0_12 |= wFunCmd.isf6 (node) ? 0x0040:0x0000;
    fun0_12 |= wFunCmd.isf7 (node) ? 0x0080:0x0000;
    fun0_12 |= wFunCmd.isf8 (node) ? 0x0100:0x0000;
    fun0_12 |= wFunCmd.isf9 (node) ? 0x0200:0x0000;
    fun0_12 |= wFunCmd.isf10(node) ? 0x0400:0x0000;
    fun0_12 |= wFunCmd.isf11(node) ? 0x0800:0x0000;
    fun0_12 |= wFunCmd.isf12(node) ? 0x1000:0x0000;

    fun13_20 |= wFunCmd.isf13(node) ? 0x0001:0x0000;
    fun13_20 |= wFunCmd.isf14(node) ? 0x0002:0x0000;
    fun13_20 |= wFunCmd.isf15(node) ? 0x0004:0x0000;
    fun13_20 |= wFunCmd.isf16(node) ? 0x0008:0x0000;
    fun13_20 |= wFunCmd.isf17(node) ? 0x0010:0x0000;
    fun13_20 |= wFunCmd.isf18(node) ? 0x0020:0x0000;
    fun13_20 |= wFunCmd.isf19(node) ? 0x0040:0x0000;
    fun13_20 |= wFunCmd.isf20(node) ? 0x0080:0x0000;

    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "loco functions %d %s%d 0x%X 0x%X", addr, slot->dir?"":"-", slot->V, fun0_12, fun13_20 );
    StrOp.fmtb(msg, "l %d %s%d 0x%X 0x%X\r\n", addr, slot->dir?"":"-", slot->V, fun0_12, fun13_20);
    SerialOp.write( data->serial, msg, StrOp.len(msg) );
}

  else {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "command [%s] not supported", NodeOp.getName( node ) );
  }

  MutexOp.post(data->mux);

  return rsp;
}


/**  */
static iONode _cmd( obj inst ,const iONode cmd ) {
  iOESUNaviData data = Data(inst);
  iONode rsp = NULL;

  if( cmd != NULL ) {
    rsp = __translate((iOESUNavi)inst, cmd);
    cmd->base.del(cmd);
  }
  return rsp;
}


/**  */
static byte* _cmdRaw( obj inst ,const byte* cmd ) {
  iOESUNaviData data = Data(inst);
  return 0;
}


/**  */
static void _halt( obj inst ,Boolean poweroff, Boolean shutdown ) {
  iOESUNaviData data = Data(inst);
  data->run = False;
  ThreadOp.sleep(500);
}


/**  */
static Boolean _setListener( obj inst ,obj listenerObj ,const digint_listener listenerFun ) {
  iOESUNaviData data = Data(inst);
  data->listenerObj = listenerObj;
  data->listenerFun = listenerFun;
  return True;
}


/**  */
static Boolean _setRawListener( obj inst ,obj listenerObj ,const digint_rawlistener listenerRawFun ) {
  iOESUNaviData data = Data(inst);
  return True;
}


/** external shortcut event */
static void _shortcut( obj inst ) {
  iOESUNaviData data = Data(inst);
}


/** bit0=power, bit1=programming, bit2=connection */
static int _state( obj inst ) {
  iOESUNaviData data = Data(inst);
  return 0;
}


/**  */
static Boolean _supportPT( obj inst ) {
  iOESUNaviData data = Data(inst);
  return 0;
}

static void __reportState(iOESUNaviData data) {
  iONode node = NodeOp.inst( wState.name(), NULL, ELEMENT_NODE );
  if( data->iid != NULL )
    wState.setiid( node, data->iid );
  wState.setpower( node, data->power );
  wState.setload( node, data->A );
  wState.setvolt( node, data->V );
  wState.settemp( node, data->T );

  if( data->listenerFun != NULL && data->listenerObj != NULL )
    data->listenerFun( data->listenerObj, node, TRCLEVEL_INFO );
}

/*
   1 Interner Fehler
   5 Nicht machbar (für Navi)
   6 Unbekanntes Objekt
   7 Fehler beim Anlegen der Lok
   8 Fehler beim Anlegen eines Consist
  14 Adressfehler
  15 Consist-Operation Fehler
 128 Zeile zu lang
 129 Syntax Error
 130 Unbekannter Befehl
 131 Ungültiger/fehlender Parameter
  */
static const char* __getErrorString(int error) {
  switch( error ) {
  case 1: return "Internal error";
  case 5: return "Not possible";
  case 6: return "Unknown object";
  case 7: return "Error on creating a loco";
  case 8: return "Error on creating a consist";
  case 14: return "Address out of range";
  case 15: return "Consist operating error";
  case 128: return "Line too long";
  case 129: return "Syntax error";
  case 130: return "Unknown command";
  case 131: return "Invalid/missing parameter";
  }
  return "Unknown";
}


static void __evaluateMsg(iOESUNavi esunavi, char* msg) {
  iOESUNaviData data = Data(esunavi);
  iOStrTok tok = StrTokOp.inst( msg, ' ' );
  const char* cmd = NULL;

  StrOp.replaceAll(msg, '\n', '\0');
  StrOp.replaceAll(msg, '\r', '\0');

  if( StrTokOp.hasMoreTokens( tok ) )
    cmd = StrTokOp.nextToken(tok);

  if( msg[0] == 'S' ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Status message received: %s", msg );
    if( StrOp.find(msg+1, "go")) {
      data->power = True;
      __reportState(data);
    }
    else if( StrOp.find(msg+1, "stop")) {
      data->power = False;
      __reportState(data);
    }
  }
  else if( msg[0] == 'I' ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "ESU Navigator version: %s", msg+2 );
    StrOp.fmtb(msg, "i 0\r\n" );
    SerialOp.write( data->serial, msg, StrOp.len(msg) );
  }
  else if( msg[0] == 'i' ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Device info: %s", msg+2 );
  }
  else if( msg[0] == 'l' ) {
    iONode nodeC = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    iOSlot slot = NULL;
    int addr = 0;
    int speed = 0;
    if( StrTokOp.hasMoreTokens( tok ) )
      addr = atoi(StrTokOp.nextToken(tok));
    if( StrTokOp.hasMoreTokens( tok ) )
      speed = atoi(StrTokOp.nextToken(tok));
    slot = __getSlotByAddr(esunavi, addr);
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Loco: addr=%d speed=%d dir=%s", addr, abs(speed), speed < 0 ? "rev":"fwd" );

    if( data->iid != NULL )
      wLoc.setiid( nodeC, data->iid );
    if( slot != NULL )
      wLoc.setid( nodeC, slot->id );

    wLoc.setaddr( nodeC, addr );
    wLoc.setV_raw( nodeC, abs(speed) );
    wLoc.setV_rawMax( nodeC, 128 );
    wLoc.setdir( nodeC, speed >= 0 ? True:False);
    wLoc.setcmd( nodeC, wLoc.velocity );
    wLoc.setthrottleid( nodeC, "esunavi" );

    data->listenerFun( data->listenerObj, nodeC, TRCLEVEL_INFO );
  }
  else if( msg[0] == 'L' ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Loco configuration: %s", msg+2 );
  }
  else if( msg[0] == 'a' ) {
    iONode nodeC = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    int addr = 0;
    int state = 0;
    const char* onoff = "";
    if( StrTokOp.hasMoreTokens( tok ) )
      addr = atoi(StrTokOp.nextToken(tok)+1);
    if( StrTokOp.hasMoreTokens( tok ) )
      state = atoi(StrTokOp.nextToken(tok));
    if( StrTokOp.hasMoreTokens( tok ) )
      onoff = StrTokOp.nextToken(tok);
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Accessory: addr=%d state=%d %s", addr, state, onoff );

    wSwitch.setaddr1( nodeC, addr );
    if( data->iid != NULL )
      wSwitch.setiid( nodeC, data->iid );
    wSwitch.setstate( nodeC, state==1?wSwitch.straight:wSwitch.turnout );

    data->listenerFun( data->listenerObj, nodeC, TRCLEVEL_INFO );
  }
  else if( msg[0] == 'e' ) {
    const char* cmderr = "";
    int error = 0;
    int pos = 0;
    if( StrTokOp.hasMoreTokens( tok ) )
      cmderr = StrTokOp.nextToken(tok);
    if( StrTokOp.hasMoreTokens( tok ) )
      error = atoi(StrTokOp.nextToken(tok));
    if( StrTokOp.hasMoreTokens( tok ) )
      pos = atoi(StrTokOp.nextToken(tok));
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Error: cmd=%s error=%d position=%d [%s]", cmderr, error, pos, __getErrorString(error) );
  }
  else if( msg[0] == 's' ) {
    if( StrTokOp.hasMoreTokens( tok ) )
      data->A = atoi(StrTokOp.nextToken(tok));
    if( StrTokOp.hasMoreTokens( tok ) )
      data->V = atoi(StrTokOp.nextToken(tok));
    if( StrTokOp.hasMoreTokens( tok ) )
      data->T = atoi(StrTokOp.nextToken(tok));
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Statistics: current=%d voltage=%d temp.=%d", data->A, data->V, data->T );
    __reportState(data);
  }
  else {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Unsupported message received: %s", msg );
  }

  StrTokOp.base.del(tok);

}


static void __serialReader( void* threadinst ) {
  iOThread      th       = (iOThread)threadinst;
  iOESUNavi     esunavi  = (iOESUNavi)ThreadOp.getParm( th );
  iOESUNaviData data     = Data(esunavi);
  Boolean       serialOK = False;

  char msg[256];
  int  idx = 0;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "ESU Navigator serial reader started." );

  ThreadOp.sleep(50); /* resume some time to get it all being setup */

  data->serial = SerialOp.inst( wDigInt.getdevice( data->ini ) );
  SerialOp.setFlow( data->serial, 0 );
  SerialOp.setLine( data->serial, 115200, 8, 1, none, wDigInt.isrtsdisabled( data->ini ) );
  SerialOp.setTimeout( data->serial, wDigInt.gettimeout(data->ini), wDigInt.gettimeout(data->ini) );
  serialOK = SerialOp.open( data->serial );

  if( serialOK ) {
    StrOp.fmtb(msg, "I\r\n" );
    SerialOp.write( data->serial, msg, StrOp.len(msg) );
  }


  while( serialOK && data->run ) {

    if( SerialOp.available( data->serial ) ) {
      int rc = SerialOp.read( data->serial, msg+idx, 1 );
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "read: idx=%d 0x%02X", idx, msg[idx] );
      if( msg[idx] == '\n' ) {
        __evaluateMsg(esunavi, msg);
        idx = 0;
      }
      else {
        idx++;
      }

      if( idx >= 256 ) {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "overflow" );
        idx = 0;
      }

    }

    ThreadOp.sleep(10);
  }

  SerialOp.close( data->serial );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "ESU Navigator serial reader ended." );

}

static void __timedqueue( void* threadinst ) {
  iOThread      th = (iOThread)threadinst;
  iOESUNavi     esunavi = (iOESUNavi)ThreadOp.getParm(th);
  iOESUNaviData data = Data(esunavi);
  int statistics = 0;

  iOList list = ListOp.inst();
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "timed queue started" );

  while( data->run ) {
    iQCmd cmd = (iQCmd)ThreadOp.getPost( th );
    if (cmd != NULL) {
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "new timed command time=%d delay=%d tick=%d", cmd->time, cmd->delay, SystemOp.getTick() );
      ListOp.add(list, (obj)cmd);
    }

    int i = 0;
    for( i = 0; i < ListOp.size(list); i++ ) {
      iQCmd cmd = (iQCmd)ListOp.get(list, i);
      if( (cmd->time + cmd->delay) <= SystemOp.getTick() ) {
        TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "timed command" );
        if( MutexOp.wait( data->mux ) ) {
          SerialOp.write( data->serial, cmd->msg, StrOp.len(cmd->msg) );
          ListOp.removeObj(list, (obj)cmd);
          freeMem(cmd);
          MutexOp.post(data->mux);
        }
        break;
      }
    }

    statistics++;
    if( statistics >= 1000 ) {
      if( MutexOp.wait( data->mux ) ) {
      SerialOp.write( data->serial, "s\r\n", StrOp.len("s\r\n") );
      MutexOp.post(data->mux);
      }
      statistics = 0;
    }

    ThreadOp.sleep(10);
  }

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "timed queue ended" );
}





/** vmajor*1000 + vminor*100 + patch */
static int vmajor = 2;
static int vminor = 0;
static int patch  = 99;
static int _version( obj inst ) {
  iOESUNaviData data = Data(inst);
  return vmajor*10000 + vminor*100 + patch;
}


/**  */
static struct OESUNavi* _inst( const iONode ini ,const iOTrace trc ) {
  iOESUNavi __ESUNavi = allocMem( sizeof( struct OESUNavi ) );
  iOESUNaviData data = allocMem( sizeof( struct OESUNaviData ) );
  MemOp.basecpy( __ESUNavi, &ESUNaviOp, 0, sizeof( struct OESUNavi ), data );

  TraceOp.set( trc );
  SystemOp.inst();
  /* Initialize data->xxx members... */
  data->ini      = ini;
  data->iid      = StrOp.dup( wDigInt.getiid( ini ) );
  data->swtime   = wDigInt.getswtime( ini );
  data->mux      = MutexOp.inst( NULL, True );

  data->lcmap  = MapOp.inst();
  data->lcmux  = MutexOp.inst( NULL, True );

  data->run      = True;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "ESU Navigator %d.%d.%d", vmajor, vminor, patch );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "iid      = %s", data->iid );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "device   = %s", wDigInt.getdevice( data->ini ) );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );

  data->reader = ThreadOp.inst( "esureader", &__serialReader, __ESUNavi );
  ThreadOp.start( data->reader );

  data->timedQueue = ThreadOp.inst( "timedqueue", &__timedqueue, __ESUNavi );
  ThreadOp.start( data->timedQueue );

  instCnt++;
  return __ESUNavi;
}


iIDigInt rocGetDigInt( const iONode ini ,const iOTrace trc )
{
  return (iIDigInt)_inst(ini,trc);
}


/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocdigs/impl/esunavi.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
