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

#include "rocdigs/impl/om32_impl.h"

#include "rocs/public/mem.h"
#include "rocs/public/system.h"

#include "rocrail/wrapper/public/DigInt.h"
#include "rocrail/wrapper/public/Response.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/Program.h"

static int instCnt = 0;

/** ----- OBase ----- */
static const char* __id( void* inst ) {
  return NULL;
}

static void* __event( void* inst, const void* evt ) {
  return NULL;
}

static void __del( void* inst ) {
  if( inst != NULL ) {
    iOOM32Data data = Data(inst);
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
  iOOM32Data data = Data(inst);
  return data->ini;
}

/** ----- OOM32 ----- */

/** ------------------------------------------------------------
 * csum = 128 | (128 - (sum(all_other_bytes) mod 128))
 */
static int __generateChecksum( byte* datagram ) {
  /* csum = 128 | (128 - (sum(all_other_bytes) mod 128)) */
  int cnt = 3;
  int checksum = 0;
  int i = 0;

  checksum = datagram[0];

  /* add the data bytes: */
  for( i = 0; i < cnt; i++ ) {
    checksum += datagram[i+1];
    datagram[i+1] |= 0x80; /* mark as data byte */
  }
  /* calculate the checksum: */
  checksum = 128 | (128 - (checksum % 128));

  return checksum | 0x80;
}


static int __translate(  iOOM32 inst, iONode node, byte* datagram ) {
  iOOM32Data data = Data(inst);
  int size = 0;

  /* Switch command. */
  if( StrOp.equals( NodeOp.getName( node ), wSwitch.name() ) ) {
    int  addr    = wSwitch.getaddr1( node ) - 1;
    int  port    = wSwitch.getport1( node ) - 1;
    int  delay   = wSwitch.getdelay( node );
    int  param   = wSwitch.getparam1( node );
    int  value   = wSwitch.getvalue1( node );
    int  command = 0;
    int  nr      = addr * 4 + port;

    if( delay == 0 )
      delay = wDigInt.getswtime(data->ini);

    delay = delay / 16; /* units of 1/60 sec. */
    if( !wSwitch.isactdelay( node ) )
      delay = 0; /* use default of 200 ms */

    if( wSwitch.issinglegate( node ) ) {
      command = StrOp.equals( wSwitch.getcmd( node ), wSwitch.turnout ) ? 9:8;
      delay = 0;
    }
    else {
      command = 9; /* ON */
      if( StrOp.equals( wSwitch.getcmd( node ), wSwitch.turnout ) )
        port++;
    }

    if( !wSwitch.isaccessory(node) && wSwitch.getporttype(node) == wProgram.porttype_servo ) {
      datagram[1] = 0x26;
      datagram[3] = StrOp.equals( wSwitch.getcmd( node ), wSwitch.turnout ) ? value:param;
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "om32 switch servo [%d-%d] position=%d", addr+1, port+1, datagram[3]);
    }
    else if( !wSwitch.isaccessory(node) && wSwitch.getporttype(node) == wProgram.porttype_motor ) {
      datagram[1] = 0x27;
      datagram[3] = StrOp.equals( wSwitch.getcmd( node ), wSwitch.turnout ) ? value:param;
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "om32 switch motor [%d-%d] PWM=%d", addr+1, port+1, datagram[3]);
    }
    else if( !wSwitch.isaccessory(node) && wSwitch.getporttype(node) == wProgram.porttype_light ) {
      datagram[1] = 0x01;
      datagram[3] = StrOp.equals( wSwitch.getcmd( node ), wSwitch.turnout ) ? value:param;
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "om32 switch lights [%d-%d] aspect=%d", addr+1, port+1, datagram[3]);
    }
    else {
      datagram[1] = command;
      datagram[3] = delay;
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "om32 switch %s [%d-%d] %s",
          wSwitch.getcmd( node ), addr+1, port+1, wSwitch.issinglegate( node )?" (single gate)":"" );
    }

    datagram[0] = (addr << 2) | FIXED_FLAG;
    datagram[2] = port;
    datagram[4] = (byte)__generateChecksum( datagram );
    size = 5;
  }

  /* Output command. */
  else if( StrOp.equals( NodeOp.getName( node ), wOutput.name() ) ) {
    int  module = wOutput.getaddr( node ) - 1;
    int  port   = wOutput.getport( node ) - 1;
    int  gain   = wOutput.getparam( node );
    int  value  = wOutput.getvalue( node );
    Boolean blink = wOutput.isblink( node );
    Boolean on    = StrOp.equals( wOutput.on, wOutput.getcmd( node ) );

    if( gain == 0 )
      gain = 10;

    byte param   = on ? gain:0;
    byte command = blink ? 10:5;

    if( !wOutput.isaccessory(node) && wOutput.getporttype(node) == wProgram.porttype_motor ) {
      /* PWM value */
      command = 0x27;
      param = on ? value:wOutput.getparam( node );
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "om32 output motor [%d-%d] PWM=%d", module+1, port+1, param);
    }

    else if( on && !wOutput.isaccessory(node) && wOutput.getporttype(node) == wProgram.porttype_light ) {
      /* param = Aspect */
      command = 0x01;
      param = on ? value:wOutput.getparam( node );
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "om32 output lights [%d-%d] aspect=%d", module+1, port+1, param);
    }

    else if( !wOutput.isaccessory(node) && wOutput.getporttype(node) == wProgram.porttype_servo ) {
      /* param = position */
      command = 0x26;
      param = on ? value:wOutput.getparam( node );
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "om32 output servo [%d-%d] position=%d", module+1, port+1, param);
    }
    else {
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "om32 output %s %s [%d-%d] gain=%d",
          blink?"blink":"lnear", wOutput.getcmd( node ), module+1, port+1, gain );
    }

    datagram[0] = (module << 2) | FIXED_FLAG;
    datagram[1] = command;
    datagram[2] = port;
    datagram[3] = param;
    datagram[4] = (byte)__generateChecksum( datagram );
    size = 5;
  }

  /* Signal command. */
  else if( StrOp.equals( NodeOp.getName( node ), wSignal.name() ) ) {
    int module = wSignal.getaddr( node ) - 1;
    int port   = wSignal.getport1( node ) - 1;
    int aspect = wSignal.getaspect(node);

    datagram[0] = (module << 2) | FIXED_FLAG;
    datagram[1] = 0x01;
    datagram[2] = port;
    datagram[3] = aspect;
    datagram[4] = (byte)__generateChecksum( datagram );
    size = 5;
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "oc32 signal cmd=%s [%d-%d] aspect=%d",
        wOutput.getcmd( node ), module+1, port+1, aspect );
  }

  return size;
}


static void __sendToOM32( iOOM32 inst, iONode cmd ) {
  iOOM32Data data = Data(inst);
  byte datagram[32];
  if( __translate( inst, cmd, datagram ) > 0 ) {
    TraceOp.dump ( name, TRCLEVEL_BYTE, (char*)datagram, 5 );
    SerialOp.write( data->serial, (char*)datagram, 5 );
  }

}


/**  */
static iONode _cmd( obj inst ,const iONode cmd ) {
  iOOM32Data data = Data(inst);
  __sendToOM32( (iOOM32)inst, cmd );
  return 0;
}


/**  */
static void _halt( obj inst, Boolean poweroff, Boolean shutdown ) {
  iOOM32Data data = Data(inst);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "halt command received" );
  return;
}


/**  */
static Boolean _setListener( obj inst ,obj listenerObj ,const digint_listener listenerFun ) {
  iOOM32Data data = Data(inst);
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

/**  */
static Boolean _supportPT( obj inst ) {
  return False;
}


/* Status */
static int _state( obj inst ) {
  iOOM32Data data = Data(inst);
  int state = 0;
  return state;
}

/* external shortcut event */
static void _shortcut(obj inst) {
  iOOM32Data data = Data( inst );
}


/* VERSION: */
static int vmajor = 2;
static int vminor = 0;
static int patch  = 99;
static int _version( obj inst ) {
  iOOM32Data data = Data(inst);
  return vmajor*10000 + vminor*100 + patch;
}

/**  */
static struct OOM32* _inst( const iONode ini ,const iOTrace trc ) {
  iOOM32 __OM32 = allocMem( sizeof( struct OOM32 ) );
  iOOM32Data data = allocMem( sizeof( struct OOM32Data ) );
  MemOp.basecpy( __OM32, &OM32Op, 0, sizeof( struct OOM32 ), data );

  TraceOp.set( trc );

  /* Initialize data->xxx members... */
  data->ini = ini;
  data->iid = StrOp.dup( wDigInt.getiid( ini ) );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Dinamo OM32 RS485 %d.%d.%d", vmajor, vminor, patch );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "iid      = %s", data->iid );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "device   = %s", wDigInt.getdevice( ini ) );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "baudrate = %d", wDigInt.getbps( ini ) );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );


  data->serial = SerialOp.inst( wDigInt.getdevice( ini ) );

  SerialOp.setFlow( data->serial, -1 );
  SerialOp.setLine( data->serial, wDigInt.getbps( ini ), 8, 1, odd , wDigInt.isrtsdisabled( ini ));
  SerialOp.setTimeout( data->serial, wDigInt.gettimeout( ini ), 200 );


  if( SerialOp.open( data->serial ) ) {
    SystemOp.inst();

  }
  else {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Could not init om32 port! (%)", wDigInt.getdevice( ini ) );
  }

  instCnt++;
  return __OM32;
}

/* Support for dynamic Loading */
iIDigInt rocGetDigInt( const iONode ini ,const iOTrace trc )
{
  return (iIDigInt)_inst(ini,trc);
}


/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocdigs/impl/om32.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
