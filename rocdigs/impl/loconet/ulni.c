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

/*
 * USB-LocoNet-Interface 63120 
 */

/*
**Kommunikation PC - LocoNet**

Die Kommunikation zwischen PC und LocoNet muss nach folgendem Schema ablaufen:

Message über USB aussenden und anschließend warten bis die gesendete Message wieder empfangen
wurde, bevor eine neue Message gesendet wird. Falls andere Messages in der Wartezeit empfangen werden,
diese bearbeiten.

LACK (Long Acknowledge Message) Bearbeitung: 
Falls auf eine Message ein LACK folgen kann (siehe LocoNet-
Dokumentation, auf welche Messages ein LACK folgen kann), muss nach dem Sende- und Empfangsvorgang
per ComPort ein Flag gesetzt werden. Ist dieses Flag gesetzt und die nächste empfangene Message ist eine
LACK-Message, so muss diese bearbeitet werden, weil sie eine Antwort auf die gesendete Message ist. Ist
die nächste emfangene Message kein LACK, so wird das gesetzte Flag zurückgenommen. Aus diese Weise
ist gewährleistet, dass ein LACK nicht einer falschen Message zugeordnet wird.

Empfangene Messages auswerten und bearbeiten.

Durch den Wiederempfang gesendeter Messages müssen vom PC initiierte Aktionen nicht getrennt bearbeitet
werden, da sie nach der Übertragung an LocoNet wieder im Eingangspuffer liegen und durch die Empfangs-
routine bearbeitet werden.

----------
All send packets will go in the sendqueue.
All read packets will go in the readqueue.

The last send packet will be copied to compare with the read packets.
After a match, or timeout, the next packet may be send.

Needed instance variables:
  - Two queues.
  - Flag for send next packet.
  - Time counter for trigger a timeout.
  - 128 byte memory block for the last send packet copy.


*/

#include "rocdigs/impl/loconet_impl.h"

#include "rocdigs/impl/loconet/ulni.h"

#include "rocs/public/trace.h"
#include "rocs/public/mem.h"
#include "rocs/public/str.h"
#include "rocs/public/strtok.h"

#include "rocrail/wrapper/public/DigInt.h"

#include "rocdigs/impl/loconet/lnconst.h"

#ifndef max
  #define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#endif

#ifndef min
  #define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#endif


static Boolean __Connect( iOLocoNet inst ) {
  iOLocoNetData data = Data(inst);
  iOSerial serial = NULL;

  data->subSendEcho = True;

  serial = SerialOp.inst( data->device );
  SerialOp.setFlow( serial, 0 );
  SerialOp.setLine( serial, data->bps, 8, 1, none, wDigInt.isrtsdisabled( data->ini ) );
  SerialOp.setTimeout( serial, wDigInt.gettimeout( data->ini ), wDigInt.gettimeout( data->ini ) );

  if( SerialOp.open( serial ) ) {
    data->serial = serial;
    return True;
  }
  else {
    SerialOp.base.del( serial );
    data->serial = NULL;
    return False;
  }
}


static void __reader( void* threadinst ) {
  iOThread      th      = (iOThread)threadinst;
  iOLocoNet     loconet = (iOLocoNet)ThreadOp.getParm( th );
  iOLocoNetData data    = Data(loconet);

  TraceOp.trc( "ulni", TRCLEVEL_INFO, __LINE__, 9999, "ULNI reader started." );

  do {
    byte msg[0x7F];

    int  msglen = 0;
    int   index = 0;
    int garbage = 0;
    byte bucket[32];
    byte c = 0;
    Boolean  ok = True;
    Boolean  ignore = False;

    if( data->serial == NULL ) {
      if( !__Connect(loconet) ) {
        ThreadOp.sleep(1000);
        continue;
      }
    }

    do {
      if( data->serial != NULL ) {
        int available = SerialOp.available(data->serial);
        if( available > 0 ) {
          ok = SerialOp.read(data->serial, (char*)&c, 1);
          if(c <= 0x80) {
            ThreadOp.sleep(10);
            bucket[garbage] = c;
            garbage++;
          }
        }
        else if( available == -1 || SerialOp.getRc(data->serial) > 0 ) {
          /* device error */
          iOSerial serial = data->serial;
          data->serial = NULL;
          SerialOp.close( serial );
          SerialOp.base.del( serial );
          TraceOp.trc( "ulni", TRCLEVEL_EXCEPTION, __LINE__, 9999, "device error" );
        }
        else {
          ThreadOp.sleep(10);
        }
      }
      else {
        ok = False;
      }
		} while (ok && data->run && c <= 0x80 && garbage < 10);


		if( !data->run || !ok ) {
		  if( data->comm ) {
		    data->comm = False;
        TraceOp.trc( "ulni", TRCLEVEL_INFO, __LINE__, 9999, "stateChanged: run=%d ok=%d", data->run, ok );
        LocoNetOp.stateChanged(loconet);
		  }
      ThreadOp.sleep(10);
		  continue;
		}

		if( !data->comm ) {
		  data->comm = True;
      TraceOp.trc( "ulni", TRCLEVEL_INFO, __LINE__, 9999, "stateChanged: comm=%d", data->comm );
		  LocoNetOp.stateChanged(loconet);
		}

		if( garbage > 0 ) {
       TraceOp.trc( "ulni", TRCLEVEL_INFO, __LINE__, 9999, "garbage=%d", garbage );
       TraceOp.dump ( "ulni", TRCLEVEL_BYTE, (char*)bucket, garbage );
    }

		msg[0] = c;
    ignore = False;


		if( c == 0xE0 || c == 0xC0 ) {
		  /* Uhli exceptions */
      TraceOp.trc( "ulni", TRCLEVEL_WARNING, __LINE__, 9999, "undocumented message: start=0x%02X", msg[0] );
      ThreadOp.sleep(0);
      continue;
		}
		else {
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
          msglen = 6;
          index = 1;
          break;
      case 0xd0:
          msglen = 6;
          index = 1;
          break;
      case 0xe0:
          SerialOp.read(data->serial, (char*)&c, 1);
          msg[1] = c & 0x7F;
          index = 2;
          msglen = (c & 0x7F);
          break;
      default:
        TraceOp.trc( "ulni", TRCLEVEL_WARNING, __LINE__, 9999, "undocumented message: start=0x%02X", msg[0] );
        ThreadOp.sleep(10);
        continue;
      }
		}
		TraceOp.trc( "ulni", TRCLEVEL_BYTE, __LINE__, 9999, "message 0x%02X length=%d", msg[0], msglen );

    ok = False;
    if( msglen > 0 && msglen <= 0x7F && msglen >= index ) {
  		ok = SerialOp.read(data->serial, (char*)&msg[index], msglen - index);
    }

    if( ok && msglen > 0 && !ignore ) {
      Boolean echoCatched = False;

      data->busy = (msg[0]==0x81) ? True:False;

      if( !data->subSendEcho ) {
        data->subSendEcho = MemOp.cmp(data->subSendPacket, msg, data->subSendLen );
        echoCatched = data->subSendEcho;
      }

      if( msg[0] == OPC_GPOFF || msg[0] == OPC_GPON || (msg[0]!=0x81 && !echoCatched)) {
        byte* p = allocMem(msglen+1);
        p[0] = msglen;
        MemOp.copy( p+1, msg, min(msglen,127));
        QueueOp.post( data->subReadQueue, (obj)p, normal);
        TraceOp.dump ( "ulni", TRCLEVEL_BYTE, (char*)msg, msglen );
      }
      else if( msg[0]==0x81 ) {
        TraceOp.trc( "ulni", TRCLEVEL_INFO, __LINE__, 9999, "CS busy" );
      }

      ThreadOp.sleep(0);
    }
    else {
      TraceOp.trc( "ulni", TRCLEVEL_WARNING, __LINE__, 9999, ignore ? "ignoring unknown packet":"could not read rest of packet" );
      if( msglen > 0 ) {
		   TraceOp.dump ( "ulni", TRCLEVEL_BYTE, (char*)msg, msglen );
      }
      ThreadOp.sleep(10);
    }

  } while( data->run );

  TraceOp.trc( "ulni", TRCLEVEL_INFO, __LINE__, 9999, "ULNI reader stopped." );
}


static void __writer( void* threadinst ) {
  iOThread      th      = (iOThread)threadinst;
  iOLocoNet     loconet = (iOLocoNet)ThreadOp.getParm( th );
  iOLocoNetData data    = Data(loconet);
  char ln[0x7F];
  int echoTimer = 0;
  int busyTimer = 0;

  TraceOp.trc( "ulni", TRCLEVEL_INFO, __LINE__, 9999, "ULNI writer started." );

  while( data->run ) {
    Boolean  ok = False;

    if( data->serial == NULL ) {
      ThreadOp.sleep(1000);
      continue;
    }

    /* TODO: copy packet for the reader to compair */
		if( !data->busy && data->subSendEcho && !QueueOp.isEmpty(data->subWriteQueue) ) {
		  byte* p = (byte*)QueueOp.get(data->subWriteQueue);
		  int size = p[0] & 0x7F;
		  busyTimer = 0;
		  MemOp.copy( ln, &p[1], min(size, 127) );
		  freeMem(p);
      ok = SerialOp.write( data->serial, (char*)ln, size );
      if(ok) {
	      TraceOp.dump ( "ulni", TRCLEVEL_BYTE, (char*)ln, size );
         echoTimer = 0;
        data->subSendLen = size;
		    MemOp.copy( data->subSendPacket, ln, min(size,127) );
		    data->subSendEcho = False;
      }
		}
		else {
		  TraceOp.trc( "ulni", TRCLEVEL_DEBUG, __LINE__, 9999, "could not read queue %d", QueueOp.count(data->subWriteQueue)  );
		}
		
		if( !data->subSendEcho ) {
		  echoTimer++;
		  if( echoTimer >= 100 ) {
  		  TraceOp.trc( "ulni", TRCLEVEL_EXCEPTION, __LINE__, 9999, "echo timer timed out for OPCODE 0x%02X", data->subSendPacket[0] & 0xFF  );
  		  echoTimer = 0;
  		  data->subSendEcho = True;
		  }
		}

    if( data->busy ) {
      busyTimer++;
      if( busyTimer >= 100 ) {
        TraceOp.trc( "ulni", TRCLEVEL_EXCEPTION, __LINE__, 9999, "busy timer timed out" );
        busyTimer = 0;
        data->busy = False;
      }
    }

    ThreadOp.sleep(10);
  };

  TraceOp.trc( "ulni", TRCLEVEL_INFO, __LINE__, 9999, "ULNI writer stopped." );
}


Boolean ulniConnect( obj inst ) {
  iOLocoNetData data = Data(inst);
  data->bps = wDigInt.getbps( data->ini );
  char* threadname = NULL;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "device  =%s", data->device );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "bps     =%d", data->bps );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "timeout =%d", wDigInt.gettimeout( data->ini ) );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );
  //__Connect(inst);

  data->subReadQueue = QueueOp.inst(1000);
  data->subWriteQueue = QueueOp.inst(1000);
  data->run = True;

  threadname = StrOp.fmt("ulnireader%X", inst);
  data->subReader = ThreadOp.inst( threadname, &__reader, inst );
  StrOp.free(threadname);
  ThreadOp.start( data->subReader );

  threadname = StrOp.fmt("ulniwriter%X", inst);
  data->subWriter = ThreadOp.inst( threadname, &__writer, inst );
  StrOp.free(threadname);
  ThreadOp.start( data->subWriter );

  return True;
}

void ulniDisconnect( obj inst ) {
  iOLocoNetData data = Data(inst);
  data->run = False;
  ThreadOp.sleep(50);

  if( data->serial != NULL ) {
    SerialOp.close( data->serial );
    SerialOp.base.del( data->serial );
    data->serial = NULL;
  }
}

int ulniRead ( obj inst, unsigned char *msg ) {
  iOLocoNetData data = Data(inst);
  if( !QueueOp.isEmpty(data->subReadQueue) ) {
    byte* p = (byte*)QueueOp.get(data->subReadQueue);
    int size = p[0] & 0x7F;
    MemOp.copy( msg, &p[1], min(size, 127) );
    freeMem(p);
    return size;
  }
  else {
    TraceOp.trc( "lbtcp", TRCLEVEL_DEBUG, __LINE__, 9999, "could not read queue %d", QueueOp.count(data->subReadQueue)  );
  }
  return 0;
}

Boolean ulniWrite( obj inst, unsigned char *msg, int len ) {
  iOLocoNetData data = Data(inst);
  /* put packet in the write queue */
  if( len > 0 ) {
    byte* p = allocMem(len+1);
    p[0] = len;
    MemOp.copy( p+1, msg, min(len,127));
    QueueOp.post( data->subWriteQueue, (obj)p, normal);
    return True;
  }
  
  return False;
}

Boolean ulniAvailable( obj inst ) {
  iOLocoNetData data = Data(inst);
  if( data->serial != NULL )
    return !QueueOp.isEmpty(data->subReadQueue);
  return False;
}

