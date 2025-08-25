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




#include "rocdigs/impl/easydcc_impl.h"
#include "rocdigs/impl/nmra/nmrapacket.h"

#include "rocs/public/mem.h"
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

#include "rocutils/public/addr.h"

static int instCnt = 0;

#define BUFFERSIZE 32

/** ----- OBase ----- */
static void __del( void* inst ) {
  if( inst != NULL ) {
    iOEasyDCCData data = Data(inst);
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

/** ----- OEasyDCC ----- */

static void __reportState(iOEasyDCCData data) {
  if( data->listenerFun != NULL && data->listenerObj != NULL ) {
    iONode node = NodeOp.inst( wState.name(), NULL, ELEMENT_NODE );

    if( data->iid != NULL )
      wState.setiid( node, data->iid );
    wState.setpower( node, data->power );

    data->listenerFun( data->listenerObj, node, TRCLEVEL_INFO );
  }
}



static void __sendCommand(iOEasyDCCData data, char* cmd) {
  if( !data->dummyio ) {
    byte* out = allocMem(StrOp.len(cmd) + 2);
    out[0] = StrOp.len(cmd) & 0xFF;
    MemOp.copy(out+1, cmd, StrOp.len(cmd));
    ThreadOp.post(data->writer, (obj)out);
  }
}


static int __normalizeSteps(int insteps ) {
  /* SPEEDSTEPS: vaild: 14, 28, 127 */
  if( insteps < 20 )
    return 14;
  if( insteps > 100 )
    return 127;
  return 28;
}

static void __makeMessage(char* buffer, char* cmd, byte* retVal, int len) {
  char* s;
  int idx = 0;
  int i = 0;

  for( i = 0; i < StrOp.len(cmd); i++) {
    buffer[idx] = cmd[i];
    idx++;
  }

  TraceOp.dump( name, TRCLEVEL_BYTE, (char*)retVal, len );

  for( i = 0; i < len; i++ ) {
    buffer[idx] = ' ';
    idx++;
    s = StrOp.byteToStr( &retVal[i], 1);
    buffer[idx] = s[0];
    idx++;
    buffer[idx] = s[1];
    idx++;
    StrOp.free(s);
  }
  buffer[idx] = '\r';
  idx++;
  buffer[idx] = '\0';
  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "message: [%s]", buffer );
}


static iONode __translate( iOEasyDCCData data, iONode node ) {
  iONode rsp = NULL;
  const char* cmd = wSysCmd.getcmd( node );
  char buffer[256];

  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "translate command: %s:%s", NodeOp.getName(node), cmd );

  /* System command. */
  if( StrOp.equals( NodeOp.getName( node ), wSysCmd.name() ) ) {
    if( StrOp.equals( cmd, wSysCmd.stop ) || StrOp.equals( cmd, wSysCmd.ebreak ) ) {
      StrOp.fmtb( buffer, "K\r" );
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "Kill main track" );
      __sendCommand(data, buffer);
      data->power = False;
      __reportState(data);
    }
    else if( StrOp.equals( cmd, wSysCmd.go ) ) {
      StrOp.fmtb( buffer, "E\r" );
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "Enable main track" );
      __sendCommand(data, buffer);
      data->power = True;
      __reportState(data);
    }
  }

  /* Switch command. */
  else if( StrOp.equals( NodeOp.getName( node ), wSwitch.name() ) ) {
    int addr = wSwitch.getaddr1(node);
    int port = wSwitch.getport1( node );
    int gate = wSwitch.getgate1( node );
    int fada = 0;
    int pada = 0;
    int dir  = 1;
    int action = 1;
    int len = 0;
    byte dcc[BUFFERSIZE];

    if( port == 0 ) {
      fada = addr;
      AddrOp.fromFADA( addr, &addr, &port, &gate );
    }
    else if( addr == 0 && port > 0 ) {
      pada = port;
      AddrOp.fromPADA( port, &addr, &port );
    }

    if( fada == 0 )
      fada = AddrOp.toFADA( addr, port, gate );
    if( pada == 0 )
      pada = AddrOp.toPADA( addr, port );

    if( StrOp.equals( wSwitch.getcmd( node ), wSwitch.turnout ) )
      dir = 0; /* thrown */

    if( wSwitch.issinglegate( node ) ) {
      dir = gate;
      if( StrOp.equals( wSwitch.getcmd( node ), wSwitch.straight ) )
        action = 0;
    }

    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999,
        "turnout %04d %d %-10.10s fada=%04d pada=%04d addr=%d port=%d gate=%d dir=%d action=%d",
        addr, port, wSwitch.getcmd( node ), fada, pada, addr, port, gate, dir, action );

    len = accDecoderPkt2(dcc, addr, action, (port-1)*2+dir);

    __makeMessage(buffer, "S 02", dcc, len);

    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "turnout %d %s", addr, wSwitch.getcmd(node) );
    __sendCommand(data, buffer);
  }

  /* Output command. */
  else if( StrOp.equals( NodeOp.getName( node ), wOutput.name() ) ) {
    int addr = wOutput.getaddr( node );
    int port = wOutput.getport( node );
    int gate = wOutput.getgate( node );
    int fada = 0;
    int pada = 0;
    int cmdsize = 0;
    int len = 0;
    byte dcc[BUFFERSIZE];
    int action = StrOp.equals( wOutput.getcmd( node ), wOutput.on ) ? 0x01:0x00;

    if( port == 0 ) {
      fada = addr;
      AddrOp.fromFADA( addr, &addr, &port, &gate );
    }
    else if( addr == 0 && port > 0 ) {
      pada = port;
      AddrOp.fromPADA( port, &addr, &port );
    }

    if( fada == 0 )
      fada = AddrOp.toFADA( addr, port, gate );
    if( pada == 0 )
      pada = AddrOp.toPADA( addr, port );

    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "output %04d %d %d fada=%04d pada=%04d",
        addr, port, gate, fada, pada );


    len = accDecoderPkt2(dcc, addr, action, (port-1)*2+gate);

    __makeMessage(buffer, "S 02", dcc, len);

    __sendCommand(data, buffer);
  }

  /* Sensor command. */
  else if( StrOp.equals( NodeOp.getName( node ), wFeedback.name() ) ) {
    int addr = wFeedback.getaddr( node );
    Boolean state = wFeedback.isstate( node );

    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "simulate fb addr=%d state=%s", addr, state?"true":"false" );
    rsp = (iONode)NodeOp.base.clone( node );
  }

  /* Loc command. */
  else if( StrOp.equals( NodeOp.getName( node ), wLoc.name() ) ) {
    int     steps = __normalizeSteps( wLoc.getspcnt(node) );
    int     addr  = wLoc.getaddr(node);
    Boolean fn    = wLoc.isfn( node );
    Boolean longAddr = StrOp.equals( wLoc.getprot( node ), wLoc.prot_L );
    int     dir   = wLoc.isdir( node );

    int len = 0;
    byte retVal[BUFFERSIZE];
    int  speed = 0;

    if( wLoc.getV( node ) != -1 ) {
      if( StrOp.equals( wLoc.getV_mode( node ), wLoc.V_mode_percent ) )
        speed = (wLoc.getV( node ) * steps) / 100;
      else if( wLoc.getV_max( node ) > 0 )
        speed = (wLoc.getV( node ) * steps) / wLoc.getV_max( node );
    }
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "loco addr=%d speed=%d steps=%d dir=%s",
        addr, speed, steps, dir?"forwards":"reverse" );

    if( steps == 127 )
      len = speedStep128Packet( retVal, addr, longAddr, speed, dir );
    else if( steps == 28 )
      len = speedStep28Packet( retVal, addr, longAddr, speed, dir );
    else
      len = speedStep14Packet( retVal, addr, longAddr, speed, dir, fn );

    if( len > 0 ) {
      __makeMessage(buffer, "Q", retVal, len);
      __sendCommand(data, buffer);
    }

  }

  /* Function command. */
  else if( StrOp.equals( NodeOp.getName( node ), wFunCmd.name() ) ) {
    int addr  = wLoc.getaddr(node);
    Boolean longAddr = StrOp.equals( wLoc.getprot( node ), wLoc.prot_L );
    int fg = wFunCmd.getgroup(node);
    int len = 0;
    byte retVal[BUFFERSIZE];

    if( fg <= 1 )
      len = function0Through4Packet( retVal, addr, longAddr, wFunCmd.isf0(node), wFunCmd.isf1(node), wFunCmd.isf2(node), wFunCmd.isf3(node), wFunCmd.isf4(node) );
    else if( fg == 2 ) {
      len = function5Through8Packet(retVal, addr, longAddr,
          wFunCmd.isf5(node), wFunCmd.isf6(node), wFunCmd.isf7(node), wFunCmd.isf8(node) );
    }
    else if( fg == 3 ) {
      len = function9Through12Packet(retVal, addr, longAddr,
          wFunCmd.isf9(node), wFunCmd.isf10(node), wFunCmd.isf11(node), wFunCmd.isf12(node) );
    }
    else if( fg == 4 || fg == 5 ) {
      len = function13Through20Packet(retVal, addr, longAddr,
          wFunCmd.isf13(node), wFunCmd.isf14(node), wFunCmd.isf15(node), wFunCmd.isf16(node),
          wFunCmd.isf17(node), wFunCmd.isf18(node), wFunCmd.isf19(node), wFunCmd.isf20(node));
    }
    else if( fg == 6 || fg == 7 ) {
      len = function21Through28Packet(retVal, addr, longAddr,
          wFunCmd.isf21(node), wFunCmd.isf22(node), wFunCmd.isf23(node), wFunCmd.isf24(node),
          wFunCmd.isf25(node), wFunCmd.isf26(node), wFunCmd.isf27(node), wFunCmd.isf28(node));
    }

    __makeMessage(buffer, "S 01", retVal, len);

    __sendCommand(data, buffer);
  }

  /* Program command. */
  else if( StrOp.equals( NodeOp.getName( node ), wProgram.name() ) ) {
    Boolean pom = wProgram.ispom( node );

    if( wProgram.getcmd( node ) == wProgram.pton ) {
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "programming mode ON" );
      __sendCommand(data, "M\r");
    }
    else if( wProgram.getcmd( node ) == wProgram.ptoff ) {
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "programming mode OFF" );
      __sendCommand(data, "X\r");
    }
    else if( !pom && wProgram.getcmd( node ) == wProgram.get ) {
      char cmd[BUFFERSIZE] = {0};
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "CV %d get", wProgram.getcv(node) );
      StrOp.fmtb( cmd, "R %03X\r", wProgram.getcv(node) );
      data->lastcmd = CV_READ;
      data->lastvalue = 0;
      __sendCommand(data, cmd);
    }
    else if( pom && wProgram.getcmd( node ) == wProgram.get ) {
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "POM CV %d get is not supported", wProgram.getcv(node) );
    }
    else if( !pom && wProgram.getcmd( node ) == wProgram.set ) {
      char cmd[BUFFERSIZE] = {0};
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "CV %d set %d", wProgram.getcv(node), wProgram.getvalue(node) );
      StrOp.fmtb( cmd, "P %03X %02X\r", wProgram.getcv(node), wProgram.getvalue(node) & 0xFF );
      data->lastcmd = CV_WRITE;
      data->lastcv = wProgram.getcv(node);
      data->lastvalue = wProgram.getvalue(node);
      __sendCommand(data, cmd);
    }
    else if(pom && wProgram.getcmd( node ) == wProgram.set) {
      int len = 0;
      byte retVal[BUFFERSIZE];
      len = opsCvWriteByte(retVal, wProgram.getaddr(node), wProgram.islongaddr(node), wProgram.getcv(node), wProgram.getvalue(node) );
      __makeMessage(buffer, "S 05", retVal, len);
      __sendCommand(data, buffer);
    }
  }



  return rsp;
}

/**  */
static iONode _cmd( obj inst ,const iONode cmd ) {
  iOEasyDCCData data = Data(inst);
  char out[BUFFERSIZE];
  char in [BUFFERSIZE];
  iONode reply = NULL;

  if( cmd != NULL ) {
    reply = __translate( data, cmd );
  }

  /* Cleanup Node1 */
  cmd->base.del(cmd);

  return reply;
}


/**  */
static byte* _cmdRaw( obj inst ,const byte* cmd ) {
  return 0;
}


/**  */
static void _halt( obj inst ,Boolean poweroff, Boolean shutdown ) {
  iOEasyDCCData data = Data(inst);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "shutting down <%s>...", data->iid );
  if( poweroff ) {
    __sendCommand(data, "K\r");
  }
  ThreadOp.sleep(100);
  data->run = False;
  ThreadOp.sleep(100);
  if( data->serial != NULL )
    SerialOp.close( data->serial );
}


/**  */
static Boolean _setListener( obj inst ,obj listenerObj ,const digint_listener listenerFun ) {
  iOEasyDCCData data = Data(inst);
  data->listenerObj = listenerObj;
  data->listenerFun = listenerFun;
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "listener set" );
  return True;
}


/**  */
static Boolean _setRawListener( obj inst ,obj listenerObj ,const digint_rawlistener listenerRawFun ) {
  return 0;
}


/** external shortcut event */
static void _shortcut( obj inst ) {
  return;
}


/** bit0=power, bit1=programming, bit2=connection */
static int _state( obj inst ) {
  return 0;
}


/**  */
static Boolean _supportPT( obj inst ) {
  return 0;
}


/** vmajor*1000 + vminor*100 + patch */
static int vmajor = 2;
static int vminor = 0;
static int patch  = 99;
static int _version( obj inst ) {
  iOEasyDCCData data = Data(inst);
  return vmajor*10000 + vminor*100 + patch;
}

static void __writer( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOEasyDCC easydcc = (iOEasyDCC)ThreadOp.getParm( th );
  iOEasyDCCData data = Data(easydcc);
  byte * post = NULL;
  int len = 0;
  byte out[64] = {0};

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "EasyDCC writer started." );
  ThreadOp.sleep( 10 );

  while( data->run ) {
    Boolean ok = True;
    post = (byte*)ThreadOp.getPost( th );

    if (post != NULL) {
      /* first byte is the message length */
      len = post[0];
      MemOp.set(out, 0, 64);
      MemOp.copy( out, post+1, len);
      freeMem( post);

      if( !EventOp.trywait(data->readyEvt, 5000) ) {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "can't send command: EasyDCC not ready." );
        EventOp.set(data->readyEvt);
      }
      TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999, "send command: %s", out );
      TraceOp.dump( name, TRCLEVEL_BYTE, (char*)out, len );
      SerialOp.write( data->serial, (char*)out, len );
      EventOp.reset(data->readyEvt);

    }
    ThreadOp.sleep(10);
  }

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "EasyDCC writer ended." );
}


static void __evaluateCV(iOEasyDCCData data, char* buffer) {
  /* 0123456 */
  /* CVxxxyy */
  int cv = 0;
  int value = 0;
  char tmp[8];
  iONode node = NULL;

  tmp[0] = buffer[2];
  tmp[1] = buffer[3];
  tmp[2] = buffer[4];
  tmp[3] = '\0';
  cv    = strtol(tmp, NULL, 16);

  tmp[0] = buffer[5];
  tmp[1] = buffer[6];
  tmp[2] = '\0';
  value = strtol(tmp, NULL, 16);

  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "cv %d has a value of %d", cv, value );

  node = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
  wProgram.setcv( node, cv );
  wProgram.setvalue( node, value );
  wProgram.setcmd( node, wProgram.datarsp );
  if( data->iid != NULL )
    wProgram.setiid( node, data->iid );

  if( data->listenerFun != NULL && data->listenerObj != NULL )
    data->listenerFun( data->listenerObj, node, TRCLEVEL_INFO );
}

static int __readResponse( iOEasyDCCData data, char* buffer) {
  int i = 0;
  for( i = 0; i < BUFFERSIZE; i++ ) {
    if( SerialOp.read( data->serial, buffer + i, 1 ) ) {
      if( buffer[i] == '\r' ) {
        TraceOp.dump( name, TRCLEVEL_BYTE, buffer, i+1 );
        buffer[i] = '\0';
        return i;
      }
    }
    else {
      break;
    }
  }
  TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "no valid response:" );
  if( i > 0 )
    TraceOp.dump( name, TRCLEVEL_BYTE, buffer, i );
  return 0;
}

static void __reader( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOEasyDCC easydcc = (iOEasyDCC)ThreadOp.getParm( th );
  iOEasyDCCData data = Data(easydcc);
  char buffer[BUFFERSIZE];
  int retry = 0;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "EasyDCC reader started." );
  ThreadOp.sleep( 100 );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "trying to get the version..." );
  __sendCommand(data, "V\r");
  ThreadOp.sleep( 100 );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "programming off at initial start" );
  __sendCommand(data, "X\r");
  ThreadOp.sleep( 100 );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "power off at initial start" );
  __sendCommand(data, "K\r");
  ThreadOp.sleep( 100 );

  while( data->run ) {
    Boolean ok = True;

    int available = SerialOp.available(data->serial);

    if( data->serialOK ) {
      if( available > 0 ) {
        if( __readResponse(data, buffer) > 0 ) {
          TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999, "read response: [%s]", buffer );
          if( buffer[0] == 'O' ) {
            TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "EasyDCC is ready" );
          }
          else if( buffer[0] == 'P' ) {
            TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "programming is ready" );
            if( data->lastcmd == CV_WRITE ) {
              iONode node = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
              TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "programming write response" );
              wProgram.setcv( node, data->lastcv );
              wProgram.setvalue( node, data->lastvalue );
              wProgram.setcmd( node, wProgram.datarsp );
              if( data->iid != NULL )
                wProgram.setiid( node, data->iid );

              if( data->listenerFun != NULL && data->listenerObj != NULL )
                data->listenerFun( data->listenerObj, node, TRCLEVEL_INFO );

              data->lastcmd = 0;
            }
          }
          else if( buffer[0] == '?' ) {
            TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "unknown command" );
          }
          else if( buffer[0] == 'C' ) {
            /* CVxxxyy<CR>
             * R 012
             * [3-4 second delay]
             * CV012EA
             * */
            TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Programming response: %s", buffer );
            __evaluateCV(data, buffer);
          }

          EventOp.set(data->readyEvt);
        }
      }
      else if( available == -1 || SerialOp.getRc(data->serial) > 0 ) {
        /* device error */
        data->serialOK = False;
        SerialOp.close(data->serial);
        TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "device error" );
      }
    }
    else {
      ThreadOp.sleep(100);
      retry++;
      if( retry >= 50 ) {
        retry = 0;
        data->serialOK = SerialOp.open( data->serial );
        if(data->serialOK)
          SerialOp.flush(data->serial);
      }
    }

    ThreadOp.sleep( 10 );
  }

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "EasyDCC reader ended." );
}



/**  */
static struct OEasyDCC* _inst( const iONode ini ,const iOTrace trc ) {
  iOEasyDCC __EasyDCC = allocMem( sizeof( struct OEasyDCC ) );
  iOEasyDCCData data = allocMem( sizeof( struct OEasyDCCData ) );
  MemOp.basecpy( __EasyDCC, &EasyDCCOp, 0, sizeof( struct OEasyDCC ), data );

  /* Initialize data->xxx members... */
  TraceOp.set( trc );
  SystemOp.inst();

  data->ini  = ini;
  data->iid  = StrOp.dup( wDigInt.getiid( ini ) );
  data->dummyio  = wDigInt.isdummyio(ini);

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "EasyDCC %d.%d.%d", vmajor, vminor, patch );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "iid      = %s", data->iid );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "device   = %s", wDigInt.getdevice( ini )  );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "bps      = %d", wDigInt.getbps( ini )  );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "flow     = %s", wDigInt.getflow( ini )  );


  data->serialOK = False;
  if( !data->dummyio ) {
    data->serial = SerialOp.inst( wDigInt.getdevice( ini ) );
    SerialOp.setFlow( data->serial, 0 );
    if( StrOp.equals( wDigInt.dsr, wDigInt.getflow(ini) ) )
      SerialOp.setFlow( data->serial, dsr );
    else if( StrOp.equals( wDigInt.cts, wDigInt.getflow(ini) ) )
      SerialOp.setFlow( data->serial, cts );
    else if( StrOp.equals( wDigInt.xon, wDigInt.getflow(ini) ) )
      SerialOp.setFlow( data->serial, xon );
    SerialOp.setLine( data->serial, wDigInt.getbps(ini), 8, 1, none, wDigInt.isrtsdisabled( ini ) );
    SerialOp.setTimeout( data->serial, wDigInt.gettimeout(ini), wDigInt.gettimeout(ini) );
    data->serialOK = SerialOp.open( data->serial );
  }

  if(data->serialOK) {
    data->run = True;
    data->readyEvt = EventOp.inst( "easydccevt", True );
    EventOp.set(data->readyEvt);


    data->writer = ThreadOp.inst( "easyWriter", &__writer, __EasyDCC );
    ThreadOp.start( data->writer );
    data->reader = ThreadOp.inst( "easyReader", &__reader, __EasyDCC );
    ThreadOp.start( data->reader );
  }
  else {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "unable to initialize device; switch to dummy mode" );
    data->dummyio = True;
  }


  instCnt++;
  return __EasyDCC;
}


iIDigInt rocGetDigInt( const iONode ini ,const iOTrace trc )
{
  return (iIDigInt)_inst(ini,trc);
}


/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocdigs/impl/easydcc.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
