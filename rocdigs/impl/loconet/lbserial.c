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

#include "rocdigs/impl/loconet_impl.h"

#include "rocdigs/impl/loconet/lbserial.h"
#include "rocdigs/impl/loconet/lnmon.h"

#include "rocs/public/trace.h"
#include "rocs/public/mem.h"
#include "rocs/public/str.h"
#include "rocs/public/strtok.h"
#include "rocs/public/thread.h"
#include "rocs/public/serial.h"
#include "rocs/public/system.h"

#include "rocrail/wrapper/public/DigInt.h"


Boolean lbserialConnect( obj inst ) {
  iOLocoNetData data = Data(inst);

  Boolean native = StrOp.equals( wDigInt.sublib_native, wDigInt.getsublib( data->ini ) );
  Boolean pr3    = StrOp.equals( wDigInt.sublib_digitrax_pr3, wDigInt.getsublib( data->ini ) );

  data->cts      = StrOp.equals( wDigInt.cts, wDigInt.getflow( data->ini ) );
  data->ctsretry = wDigInt.getctsretry( data->ini );
  data->bps      = wDigInt.getbps( data->ini );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "device  =%s", data->device );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "bps     =%d", data->bps );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "flow    =%s", data->cts ? "cts":"none" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "ctsretry=%d", data->ctsretry );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );


  data->serial = SerialOp.inst( data->device );
  if( native ) {
    /* MS100 bps=16457 */
    SerialOp.setFlow( data->serial, 0 );
    if( SystemOp.isWindows() ) {
      SerialOp.setLine( data->serial, 16457, 8, 1, none, wDigInt.isrtsdisabled( data->ini ) );
    }
    else {
      SerialOp.setLine( data->serial, 57600, 8, 1, none, wDigInt.isrtsdisabled( data->ini ) );
      SerialOp.setDivisor( data->serial, 7 );
    }
    // set RTS high, DTR low to power the MS100
    SerialOp.setRTS(data->serial, True);    // not connected in some serial ports and adapters
    SerialOp.setDTR(data->serial, False);   // pin 1 in DIN8; on main connector, this is DTR
  }
  else if( pr3 ) {
    /* PR3 bps=57600 Always use flow control. */
    SerialOp.setFlow( data->serial, data->cts? cts:0 );
    SerialOp.setLine( data->serial, data->bps, 8, 1, none, wDigInt.isrtsdisabled( data->ini ) );
    SerialOp.setRTS(data->serial, True);    // not connected in some serial ports and adapters
    SerialOp.setDTR(data->serial, True);   // pin 1 in DIN8; on main connector, this is DTR

    /* set PR2 mode
    */
    data->initPacket[0] = 6;
    data->initPacket[1] = 0xD3;
    data->initPacket[2] = 0x10;
    data->initPacket[3] = 0x01; /* PR2 mode */
    data->initPacket[4] = 0x00;
    data->initPacket[5] = 0x00;
    data->initPacket[6] = LocoNetOp.checksum( data->initPacket+1, 5 );
  }
  else {
    SerialOp.setFlow( data->serial, data->cts? cts:0 );
    SerialOp.setLine( data->serial, data->bps, 8, 1, none, wDigInt.isrtsdisabled( data->ini ) );
  }
  SerialOp.setTimeout( data->serial, wDigInt.gettimeout( data->ini ), wDigInt.gettimeout( data->ini ) );

  if( SerialOp.open( data->serial ) ) {
    return True;
  }
  else {
    SerialOp.base.del( data->serial );
    return False;
  }
}

void lbserialDisconnect( obj inst ) {
  iOLocoNetData data = Data(inst);

  if( data->serial != NULL ) {
    SerialOp.close( data->serial );
    SerialOp.base.del( data->serial );
    data->serial = NULL;
  }
}

Boolean lbserialAvailable ( obj inst ) {
  iOLocoNetData data = Data(inst);
  return SerialOp.available(data->serial);
  /*
  if( data->comm ) {
    int rc = SerialOp.available(data->serial);
    if( rc == -1 ) {
      data->comm = False;
      LocoNetOp.stateChanged((iOLocoNet)inst);
    }
    return rc >= 0;
  }
  return False;
  */
}


int lbserialRead ( obj inst, unsigned char *msg ) {
  iOLocoNetData data = Data(inst);
  int  msglen = 0;
  int   index = 0;
  int garbage = 0;
  byte bucket[32];
  byte c;
  Boolean  ok = False;

  do {
    if( !SerialOp.available(data->serial) )
      return 0;

    ok = SerialOp.read(data->serial, (char*)&c, 1);
    if(c < 0x80) {
      ThreadOp.sleep(10);
      bucket[garbage] = c;
      garbage++;
    }
  } while (ok && data->run && c < 0x80 && garbage < 10);

  if( garbage > 0 ) {
     TraceOp.trc( "lbserial", TRCLEVEL_INFO, __LINE__, 9999, "garbage=%d", garbage );
     TraceOp.dump ( "lbserial", TRCLEVEL_BYTE, (char*)bucket, garbage );
  }

  if( !data->run || !ok ) {
    if( data->comm ) {
      data->comm = False;
      LocoNetOp.stateChanged((iOLocoNet)inst);
    }
    return -1;
  }

  if( !data->comm ) {
    data->comm = True;
    LocoNetOp.stateChanged((iOLocoNet)inst);
  }

  msg[0] = c;

  if( c == 0xE0 ) {
	  /* Uhli exceptions */
    TraceOp.trc( "lbserial", TRCLEVEL_WARNING, __LINE__, 9999, "undocumented message: start=0x%02X", msg[0] );
    return -1;
  }

  switch (c & 0xf0) {
  case 0x80:
      msglen = 2;
      index = 1;
      break;
  case 0xa0:
  case 0xb0:
      msglen = 4;
      index = 1;
      break;
  case 0xc0:
  case 0xd0:
      msglen = 6;
      index = 1;
      break;
  case 0xe0:
      SerialOp.read(data->serial, (char*)&c, 1);
      msg[1] = c & 0x7F;
      index = 2;
      msglen = c & 0x7F;
      break;
  default:
    TraceOp.trc( "lbserial", TRCLEVEL_WARNING, __LINE__, 9999, "undocumented message: start=0x%02X", msg[0] );
    return 0;
  }
  TraceOp.trc( "lbserial", TRCLEVEL_DEBUG, __LINE__, 9999, "message 0x%02X length=%d", msg[0], msglen );

  ok = False;
  if( msglen > 0 && msglen <= 0x7F && msglen >= index ) {
		ok = SerialOp.read(data->serial, (char*)&msg[index], msglen - index);
  }

  if( ok ) {
    return msglen;
  }
  else {
    TraceOp.trc( "lbserial", TRCLEVEL_WARNING, __LINE__, 9999, "could not read!" );
    return -1;
  }

}


static Boolean __isCTS( iOSerial ser, int retries, Boolean handshake ) {
  /* CTS */
  int wait4cts = 0;

  if( !handshake ) {
    return True;
  }

  if( ser == NULL )
    return False;

  while( wait4cts < retries ) {
    if( SerialOp.isCTS( ser ) ) {
      return True;
    }
    ThreadOp.sleep( 10 );
    wait4cts++;
  }
  TraceOp.trc( "lbserial", TRCLEVEL_WARNING, __LINE__, 9999, "CTS has timed out: please check the wiring." );
  return False;
}


Boolean lbserialWrite( obj inst, unsigned char *msg, int len ) {
  iOLocoNetData data = Data(inst);
  // The Intellibox cannot handle messges over 4 bytes without
  // stopping the sender via CTS/RTS hardware handshake
  // While this should work already by using the normal hardware
  // handshake - it doesn't seem to so we need to check/send/flush
  // each byte to make sure we don't overflow the IB input buffer
  Boolean ok = True;

  int i = 0;

  if( !__isCTS( data->serial, data->ctsretry, data->cts ) ) {

    if( data->comm ) {
      data->comm = False;
      LocoNetOp.stateChanged((iOLocoNet)inst);
    }
    TraceOp.trc( "lbserial", TRCLEVEL_WARNING, __LINE__, 9999, "CTS has timed out: please check the wiring." );
    return False;
  }

  for( i = 0; i < len && __isCTS( data->serial, data->ctsretry, data->cts ); i++ ) {
    ok = SerialOp.write( data->serial, (char*)&msg[i], 1 );
  }

  if( i < len ) {
    return False;
    TraceOp.trc( "lbserial", TRCLEVEL_WARNING, __LINE__, 9999, "CTS has timed out: please check the wiring." );
  }

  return ok;
}


