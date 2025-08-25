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
20051115 rjv

After long trying and testing it seems the HSI88 has a timing problem when reading
from the RS232 interface.
It looks like it helps a lot when bytes are sended separatly with an interval of
50 ms and when the CTS is checked before sending.
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "rocdigs/impl/hsi88_impl.h"

#include "rocs/public/trace.h"
#include "rocs/public/node.h"
#include "rocs/public/attr.h"
#include "rocs/public/mem.h"
#include "rocs/public/str.h"
#include "rocs/public/system.h"


#include "rocrail/wrapper/public/DigInt.h"
#include "rocrail/wrapper/public/HSI88.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/FunCmd.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Response.h"
#include "rocrail/wrapper/public/CustomCmd.h"


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
    iOHSI88Data data = Data(inst);
    /* Cleanup data->xxx members...*/

    freeMem( data->fbstate );
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

/** ----- OHSI88 ----- */


static int __availBytes(iOHSI88Data o) {
  if( o->usb ) {
    /*return FileOp.size(o->usbh);*/
    /*return SystemOp.availDevice(o->devh);*/
    return 1;
  }
  else
    return SerialOp.available(o->serial);
}

static Boolean __readBytes(iOHSI88Data o, char* buffer, int cnt) {
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "reading %d bytes from %s", cnt, o->usb?"USB":"RS232" );
  if( o->usb ) {
    /*
    FileOp.setpos( o->usbh, 0 );
    return FileOp.read( o->usbh, (char*)buffer, cnt );
    */
    return SystemOp.readDevice( o->devh, buffer, cnt);
  }
  else
    return SerialOp.read( o->serial, buffer, cnt );
}

static Boolean __writeBytes(iOHSI88Data o, char* buffer, int cnt) {
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "writing %d bytes to %s", cnt, o->usb?"USB":"RS232" );
  if( o->usb ) {
    /*return FileOp.write( o->usbh, (char*)buffer, cnt );*/
    return SystemOp.writeDevice( o->devh, buffer, cnt);
  }
  else
    return SerialOp.write( o->serial, buffer, cnt );
}

static int __getRC(iOHSI88Data o) {
  if( o->usb ) {
    /*return FileOp.getRc(o->usbh);*/
    return 0;
  }
  else
    return SerialOp.getRc(o->serial);
}




/* Check if CTS is set. Retry configured times */
static Boolean CheckCTS( iOHSI88Data o ) {
  int wait4cts = 0;
  if( o->flow == none ) {
    return True;
  }
  if( o->usb ) {
    return True;
  }

  while( wait4cts < o->ctsretry ) {
    if( SerialOp.isCTS( o->serial ) ) {
      return True;
    }
    ThreadOp.sleep( 10 );
    wait4cts++;
  };
  return False;
}


static Boolean __sendHSI88( iOHSI88 inst, char* out, int size ) {
  iOHSI88Data o = Data(inst);
  Boolean ok = True;
  int i = 0;

  TraceOp.dump( name, TRCLEVEL_BYTE, (char*)out, size );

  if( CheckCTS(o) ) {
    int rc = 0;
    ok = __writeBytes( o, out, size );
    rc = __getRC(o);

    if( !ok ) {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Problem writing data, rc=%d", rc );
      return False;
    }
    ThreadOp.sleep(50);
  }
  else {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "CTS timeout, check the connection." );
    return False;
  }
  return True;
}


/*
offset: 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F |ASCII...........|
--------------------------------------------------------- |----------------|
00000000: 69 0D 01 00 00 02 00 00 03 00 00 04 00 00 05 00 |i...............|
00000010: 00 06 00 00 07 00 00 08 00 00 09 00 00 0A 00 00 |................|
00000020: 0B 00 00 0C 00 00 0D 00 00 0D 56 65 72 2E 20 30 |..........Ver. 0|
00000030: 2E 36 32 20 2F 20 30 38 2E 30 37 2E 30 32 20 2F |.62 / 08.07.02 /|
00000040: 20 48 53 49 2D 38 38 20 2F 20 28 63 29 20 4C 44 | HSI-88 / (c) LD|
00000050: 54 0D |T. |
 */
static int __recvHSI88( iOHSI88 inst, char* in, const char* cmd ) {
  iOHSI88Data o = Data(inst);
  int waitcounter = 0;
  int idx = 0;
  int data2read = 2;
  
  while( waitcounter < 50 && idx < 256 ) {
    /* check for waiting bytes: */
    int avail = 0;
    Boolean OK = False;

    avail = __availBytes(o);

    if( avail <= 0 ) {
       ThreadOp.sleep( 100 );
       waitcounter++;
       continue;
    }

    /* read the byte: */
    OK = __readBytes( o, &in[idx], 1 );

    if( OK ) {
      waitcounter = 0;
      in[idx+1] = '\0';

      if( idx == 0 && in[0] == 's' ) {
        /* Total number of modules. */
        data2read = 3;
      }
      else if( idx == 0 && in[0] == 'V' ) {
        /* Version string: Read ASCII until <CR>. */
        data2read = 0;
      }
      else if( idx == 0 && ( in[0] == 'i' || in[0] == 'm' ) ) {
        /* Report: At least 3 bytes in case of zero modules. */
        data2read = 3;
      }

      if( idx == 1 && (in[0] == 'i' || in[0] == 'm') ) {
        /* Report. */
        data2read = 3 + (3 * in[1]);
      }

      if( ((idx+1) >= data2read || data2read == 0) && in[idx] == '\r' ) {
        /* End of data. */
        TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999, "end of data: [%c] expected length: %d idx=%d", in[0], data2read, idx );
        TraceOp.dump( name, TRCLEVEL_BYTE, (char*)in, idx+1 );
        idx++;
        break;
      }

      if( idx == 0 ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "response: [%c] expected length: %d", in[0], data2read );
      }

      idx++;
    }
    else {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Read error; check the connection." );
      idx = 0;
      break;
    }

  }

  /* check for echo: */
  if( idx > 0 && cmd != NULL && StrOp.equals( in, cmd ) ) {
    TraceOp.dump( name, TRCLEVEL_WARNING, (char*)in, idx );
    return __recvHSI88( inst, in, NULL );
  }

  return idx;
}


/**  */
static Boolean _setListener( obj inst ,obj listenerObj ,
                             const digint_listener listenerFun)
{
  iOHSI88Data data = Data(inst);
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
static iONode _cmd( obj inst ,const iONode cmd )
{
  iOHSI88Data o = Data(inst);
  const char* cmdName = NodeOp.getName( cmd );
  const char* cmdVal  = wCustomCmd.getcmd( cmd );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "%s: %s", cmdName, cmdVal );

  if (StrOp.equals( cmdVal, "fb" )) /* simulate feedback */
  {
      int unit = 0, pin = 0;
      Boolean newstate = False;
      iONode nodeC = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );

      unit = atoi(wCustomCmd.getarg1(cmd));
      pin = atoi(wCustomCmd.getarg2(cmd));
      newstate = atoi(wCustomCmd.getarg3(cmd));


      wFeedback.setaddr( nodeC, unit*16 + pin );
      wFeedback.setstate( nodeC, newstate );
      if( o->iid != NULL )
        wFeedback.setiid( nodeC, o->iid );

      if( o->listenerFun != NULL )
        o->listenerFun( o->listenerObj, nodeC, TRCLEVEL_INFO );
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Feedback %d.%d simulated",unit,pin);
    }
   else {
     /* unsupported command */
   }

    /* Cleanup cmd node to avoid memory leak. */
    cmd->base.del(cmd);

    return NULL;
}


/**  */
static void _halt( obj inst, Boolean poweroff, Boolean shutdown ) {
  iOHSI88Data data = Data(inst);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Shutting down <%s>...", data->iid );
  data->run = False;
  ThreadOp.sleep(100);
  if( data->usb && data->usbh != NULL )
    FileOp.close( data->usbh );
  else if( !data->usb && data->serial != NULL )
    SerialOp.close( data->serial );
  return;
}


static Boolean _supportPT( obj inst ) {
  iOHSI88Data data = Data(inst);
  return False;
}




/** ------------------------------------------------------------
  * __fbstatetrigger()
  * Checks if the the low state is for 100ms stable.
  *
  * @param  fbstate  FBState array.
  * @param  fbnode   The changed fbnode, maybe NULL.
  * @return True on changed.
  */
static void __fbstatetrigger( iOHSI88 inst, iONode fbnode ) {
  iOHSI88Data data = Data(inst);
  int addr = wFeedback.getaddr( fbnode );
  Boolean state = wFeedback.isstate( fbnode );

  if( !data->smooth && fbnode != NULL ) {
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "sensor %d is %s; report", addr, state?"ON":"OFF" );
    if( data->listenerFun != NULL )
      data->listenerFun( data->listenerObj, fbnode, TRCLEVEL_INFO );
    return;
  }

  if( fbnode != NULL ) {
    iOFBState fb = NULL;

    fb = &data->fbstate[ addr-1 ];

    if( state && !fb->state ) {
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "sensor %d is ON and was OFF; report", addr );
      /* Current state is low. */
      fb->hightime = SystemOp.getTick();
      fb->lowtime = SystemOp.getTick();
      fb->state = state;
      if( data->listenerFun != NULL )
        data->listenerFun( data->listenerObj, fbnode, TRCLEVEL_INFO );
    }
    else if( state && fb->state ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "sensor %d is ON and was ON", addr );
      fb->hightime = SystemOp.getTick();
      fb->lowtime = SystemOp.getTick();
      NodeOp.base.del( fbnode );
    }
    else if( !state && fb->state ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "sensor %d is OFF and was ON", addr );
      fb->lowtime = SystemOp.getTick();
      NodeOp.base.del( fbnode );
    }
    else {
      NodeOp.base.del( fbnode );
    }
  }
}


static void __getVersion( iOHSI88 inst ) {
  iOHSI88 pHSI88 = inst;
  iOHSI88Data o = Data(pHSI88);
  char out[] = {'v','\r','\0'};
  char version [256];
  int avail = 0;
  Boolean ok = False;

  /* HSI-88 Version */
  if( __sendHSI88( inst, out, 2 ) ) {

    int len = 0;
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Version info requested..." );
    len = __recvHSI88( inst, version, out );

    if( len == 0 ) {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Timeout waiting for version response." );
      return;
    }
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, version);

  }
  else
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Could not send version-sequence to HSI Device. retrying...");
}


static Boolean __flushHSI88( iOHSI88 inst, Boolean forcetrace ) {
  iOHSI88 pHSI88 = inst;
  iOHSI88Data o = Data(pHSI88);
  tracelevel tl = forcetrace ? TRCLEVEL_INFO:TRCLEVEL_BYTE;

  /* Read all pending information on serial port. Interface Hickups if data is pending from previous init! */
  {
    char tmp[1000];
    int bAvail = 0;

    if( o->usb ) {
      bAvail = 0;
    }
    else {
      bAvail = __availBytes(o);
    }

    if (bAvail > 0 && bAvail < 1000) {
      char c;
      int extra = 0;

      TraceOp.trc(name, TRCLEVEL_WARNING, __LINE__, 9999, "Tossing %d bytes to wastebasket...", bAvail);

      __readBytes( o, tmp, bAvail );

      TraceOp.dump( name, TRCLEVEL_INFO, (char*)tmp, bAvail );

      do {
        ThreadOp.sleep(50);

        bAvail = __availBytes(o);

        if( bAvail > 0 ) {
          __readBytes( o, &c, 1 );
          extra++;
        }
      } while( bAvail > 0 && extra < 100 );

      if( extra > 0 )
        TraceOp.trc(name, TRCLEVEL_WARNING, __LINE__, 9999, "More bytes flushed: %d", extra);

      return True;
    }
    else if(bAvail >= 1000) {
      TraceOp.trc(name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Can not flush %d bytes, check your hardware!", bAvail);
      return False;
    }

  }
  return False;
}


/* The HSI88 interfaces needs some kind of an "hello" handshake. */
static Boolean __preinitHSI88( iOHSI88 inst ) {
  iOHSI88 pHSI88 = inst;
  iOHSI88Data o = Data(pHSI88);
  static char* wakeup = "\r\r\r\r\r\r\r\r\r\r";
  char b;
  int i;
  Boolean ok = True;

  /* Say "hello": */
  if( __sendHSI88( inst, wakeup, StrOp.len( wakeup ) ) ) {

    /* After ten times it should detect at least 1 cr: */
    ok = __readBytes( o, &b, 1 );

    /* Flush all cr's he detected: */
    __flushHSI88( inst, False );
    return ok;
  }
  else {
    TraceOp.trc(name, TRCLEVEL_WARNING, __LINE__, 9999, "preInit failed.");
    return False;
  }
}


static Boolean __initHSI88( iOHSI88 inst ) {
  iOHSI88 pHSI88 = inst;
  iOHSI88Data o = Data(pHSI88);
  char out[] = {'s',o->fbleft,o->fbmiddle,o->fbright,'\r','\0'};
  char in[256] = {'\0'};
  Boolean initOK = False;
  int len = 0;
  int modcnt = o->fbleft + o->fbmiddle + o->fbright;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "HSI-88 init nr of modules");
  if( __sendHSI88( inst, out, 5 ) )
  {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Init sent. Waiting for response...");
    len = __recvHSI88( inst, in, out );


    if ( len == 3 && in[0] == 's' )
    {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Got init response");
      if( modcnt == (int)in[1] ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "S88 connected modules: %d", (int)in[1]);
      }
      else {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
                     "S88 Module count does not match! Should be %d instead of %d", modcnt, (int)in[1]);
        return False;
      }

      if (in[2] != '\r')
      {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Protocol Error: expected 0x0D got 0x%02x", in[2]);
      }
      else
        initOK = True;
    }
    else
    {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
                   "Init response expecting 0x%02X, length 3 but got 0x%02X, length %d", (int)'s', (int)in[0], len);
      TraceOp.dump( NULL, TRCLEVEL_WARNING, in, len );
    }

  }
  else
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Could not send init-sequence to HSI Device. retrying...");

  return initOK;
}


static void __delayedOffHandler( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOHSI88 pHSI88 = (iOHSI88)ThreadOp.getParm( th );
  iOHSI88Data data = Data(pHSI88);

  ThreadOp.sleep(1000);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "HSI88 delayed OFF handler started");

  while( data->run ) {
    /* Loop throug all feedbacks to check for low state. */
    int i = 0;
    int modcnt = (data->fbleft + data->fbmiddle + data->fbright) * 16;
    for( i = 0; i < modcnt; i++ ) {
      iOFBState fb = &data->fbstate[ i ];
      if( fb->state && fb->lowtime > fb->hightime && (SystemOp.getTick() - fb->lowtime) >= data->triggertime ) {
        iONode evt = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
        TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "sensor %d delayed OFF; report", i+1 );
        fb->state = False;
        wFeedback.setstate( evt, fb->state );
        wFeedback.setaddr( evt, i+1 );
        if( data->iid != NULL )
          wFeedback.setiid( evt, data->iid );

        if( data->listenerFun != NULL )
          data->listenerFun( data->listenerObj, evt, TRCLEVEL_INFO );
      }
    }
    ThreadOp.sleep(100);
  }
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "HSI88 delayed OFF handler ended");
}


static void __HSI88feedbackReader( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOHSI88 pHSI88 = (iOHSI88)ThreadOp.getParm( th );
  iOHSI88Data o = Data(pHSI88);
  unsigned char* fb = allocMem(256);
  char out[6];
  char buffer [512];
  int k = 0;
  Boolean crDetected = False;
  int waitcounter = 0;
  Boolean ok;
  int avail = 0;
  Boolean l_dummy = True;
  int l_iLoop = 0;

  memset(fb,0,256);

  ThreadOp.sleep(1000);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "HSI88 Reader started");
  if( !o->usb ) {
    __preinitHSI88(pHSI88);
    ThreadOp.sleep(100);
  }

  while( o->run ) {

    if( !o->dummyio && !o->initOK ) {
      __flushHSI88(pHSI88, True);
      __getVersion(pHSI88);
      o->initOK = __initHSI88(pHSI88);
      if( !o->initOK ) {
        ThreadOp.sleep( 1000 );
        continue;
      }
    }

    ThreadOp.sleep(10);


    if( o->dummyio ) {
      l_iLoop++;
      if( l_iLoop > 200 ) {
        iONode nodeC = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
        int addr = 4;
        wFeedback.setaddr( nodeC, addr );
        wFeedback.setstate( nodeC, l_dummy );
        if( o->iid != NULL )
          wFeedback.setiid( nodeC, o->iid );
        TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "sensor %d %s",addr, wFeedback.isstate( nodeC )?"high":"low" );
        __fbstatetrigger( pHSI88, nodeC );
        l_dummy = !l_dummy;
        l_iLoop = 0;
      }
      continue;
    }

    avail = __availBytes(o);

    if( avail > 0 )
      ok = __readBytes( o, buffer, 1 );
    else
      continue;

    if( ok )
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Byte available: 0x%02X", buffer[0]);
    else
      continue;

    if( ok && buffer[0] == 'i' ) {
      int modcnt = 0;
      int i = 0;
      int j = 0;
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Info received, waiting for module count...");
      ok = __readBytes( o, (char*)buffer, 1 );
      buffer[1] = '\0';
      modcnt = buffer[0];
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "%d modules",modcnt);
      for( i = 0; i < modcnt; i++ ) {
        int modnr = 0;
        unsigned char highbyte = 0;
        unsigned char lowbyte = 0;
        TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "reading module data %d...", i);
        ok = __readBytes( o, (char*)buffer, 3 );
        TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999, "module data %d=0x%02X 0x%02X 0x%02X", i,
                     buffer[0], buffer[1], buffer[2] );
        modnr    = buffer[0];
        highbyte = buffer[1];
        lowbyte  = buffer[2];
        for (j = 0; j< 8; j++)
        {
          if ( ( highbyte & (0x01 << j)) != (fb[modnr*2]&(0x01 << j)))
          {
            iONode nodeC = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
            int addr = (modnr-1) * 16 + j+9;
            wFeedback.setaddr( nodeC, addr );
            wFeedback.setstate( nodeC, ( highbyte & (0x01 << j))?True:False );
            if( o->iid != NULL )
              wFeedback.setiid( nodeC, o->iid );

            TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "sensor %d %s",addr, wFeedback.isstate( nodeC )?"high":"low" );
            __fbstatetrigger( pHSI88, nodeC );
          }
          if ( ( lowbyte & (0x01 << j)) != (fb[modnr*2 +1]&(0x01 << j)))
          {
            iONode nodeC = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
            int addr = (modnr-1) * 16 + j+1;
            wFeedback.setaddr( nodeC, addr );
            wFeedback.setstate( nodeC,  (lowbyte & (0x01 << j))?True:False );
            if( o->iid != NULL )
              wFeedback.setiid( nodeC, o->iid );

            TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "sensor %d %s",addr, wFeedback.isstate( nodeC )?"high":"low" );
            __fbstatetrigger( pHSI88, nodeC );
          }

        }
        fb[modnr*2] = highbyte;
        fb[modnr*2+1] = lowbyte;

      }

      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Waiting for CR response...");
      ok = __readBytes( o, (char*)buffer, 1 );
      if (buffer[0] != '\r')
      {
        TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "Protocol Error: expected 0x13 got 0x%02x",(unsigned char)buffer[0]);
      }

      continue;
    }


    /* unmatched response. read until cr */
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "reading unmatched response %d...", k);
    k=0;
    crDetected = False;
    while (ok && !crDetected)
    {
      ok = __readBytes( o, (char*)&buffer[k], 1 );
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "Unmatched response %d=0x%02X", k, buffer[k]);
      if(buffer[k] == '\r')
        crDetected = True;
      k++;
    };

  };

  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "FeedbackReader ended. <%s>", o->iid );
}

/* Status */
static int _state( obj inst ) {
  iOHSI88Data data = Data(inst);
  int state = 0;
  return state;
}

/* external shortcut event */
static void _shortcut(obj inst) {
  iOHSI88Data data = Data( inst );
}


/* VERSION: */
static int vmajor = 2;
static int vminor = 0;
static int patch  = 0;
static int _version( obj inst ) {
  iOHSI88Data data = Data(inst);
  return vmajor*10000 + vminor*100 + patch;
}

/**  */
static struct OHSI88* _inst( const iONode ini ,const iOTrace trc )
{
  iOHSI88 __HSI88 = allocMem( sizeof( struct OHSI88 ) );
  iOHSI88Data data = allocMem( sizeof( struct OHSI88Data ) );

  /* Initialize data->xxx members... */
  iONode hsi88ini = NULL;
  iOAttr attr = NULL;
  data->serialOK = False;
  data->initOK = False;

  MemOp.basecpy( __HSI88, &HSI88Op, 0, sizeof( struct OHSI88 ), data );

  TraceOp.set( trc );

  data->mux = MutexOp.inst( StrOp.fmt( "serialMux%08X", data ), True );

  data->fbstate = allocMem( 31 * 16 * sizeof( struct FBState ) );

  /* Evaluate attributes. */
  data->device   = StrOp.dup( wDigInt.getdevice( ini ) );

  if( wDigInt.getiid( ini ) != NULL )
    data->iid = StrOp.dup( wDigInt.getiid( ini ) );

  data->bps      = 9600;
  data->bits     = 8;
  data->stopBits = 1;
  data->timeout  = wDigInt.gettimeout( ini );
  data->parity   = none;
  data->flow     = 0;
  data->ctsretry = wDigInt.getctsretry( ini );
  data->dummyio  = wDigInt.isdummyio( ini );

  if( StrOp.equals( wDigInt.cts, wDigInt.getflow(ini) ) )
    data->flow = cts;

  hsi88ini = wDigInt.gethsi88(ini);
  if( hsi88ini == NULL ) {
    hsi88ini = NodeOp.inst( wHSI88.name(), ini, ELEMENT_NODE );
    NodeOp.addChild(ini, hsi88ini );
  }

  data->smooth   = wHSI88.issmooth( hsi88ini );
  data->triggertime = wHSI88.gettriggertime( hsi88ini ) / 10;

  if( data->triggertime < 10 )
    data->triggertime = 10;

  /* HSI-88 specific settings */
  data->fbleft   = wHSI88.getfbleft( hsi88ini );
  data->fbmiddle = wHSI88.getfbmiddle( hsi88ini );
  data->fbright  = wHSI88.getfbright( hsi88ini );
  data->usb      = wHSI88.isusb( hsi88ini );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "hsi88 %d.%d.%d", vmajor, vminor, patch );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "iid          = %s", wDigInt.getiid( ini ) != NULL ? wDigInt.getiid( ini ):"");
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "device       = %s", data->device );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "type         = %s", data->usb ? "USB":"RS232" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "handshake    = %s", wDigInt.getflow(ini) );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "fbleft       = %d", data->fbleft );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "fbmiddle     = %d", data->fbmiddle );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "fbright      = %d", data->fbright );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "timeout      = %d", data->timeout );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "trigger      = %s", data->smooth ? "ON":"OFF" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "trigger time = %d", data->triggertime * 10 );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );

  if( data->usb ) {
    /*data->usbh = FileOp.inst( data->device, OPEN_R );*/
    data->devh = SystemOp.openDevice(data->device);

    data->serialOK = (data->devh != 0 ? True:False);
  }
  else {
    data->serial = SerialOp.inst( data->device );
    SerialOp.setFlow( data->serial, data->flow );
    SerialOp.setLine( data->serial, data->bps, data->bits, data->stopBits, data->parity, wDigInt.isrtsdisabled( ini ) );
    SerialOp.setTimeout( data->serial, data->timeout, data->timeout );
    data->serialOK = SerialOp.open( data->serial );
    SerialOp.setDTR(data->serial, True);
  }

  if( data->serialOK ) {
    data->run = True;

    SystemOp.inst();
    data->feedbackReader = ThreadOp.inst( "hsi88fb", &__HSI88feedbackReader, __HSI88 );
    ThreadOp.start( data->feedbackReader );

    if( data->smooth ) {
      data->delayedOffHandler = ThreadOp.inst( "hsi88Off", &__delayedOffHandler, __HSI88 );
      ThreadOp.start( data->delayedOffHandler );
    }
  }
  else
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Could not init HSI88 port!" );

  instCnt++;
  return __HSI88;
}

iIDigInt rocGetDigInt( const iONode ini ,const iOTrace trc )
{
  return (iIDigInt)_inst(ini,trc);
}

/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocdigs/impl/hsi88.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
