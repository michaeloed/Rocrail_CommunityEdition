 /*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2015 Rob Versluis, Rocrail.net

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


#include "rocdigs/impl/massoth_impl.h"

#include "rocs/public/string.h"
#include "rocs/public/system.h"
#include "rocs/public/strtok.h"

#include "rocrail/wrapper/public/DigInt.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/FunCmd.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/Program.h"
#include "rocrail/wrapper/public/State.h"
#include "rocrail/wrapper/public/Response.h"
#include "rocrail/wrapper/public/FbInfo.h"
#include "rocrail/wrapper/public/FbMods.h"

#include "rocdigs/impl/massoth/massoth_const.h"

#include "rocutils/public/addr.h"

static int instCnt = 0;

/* declarations */
static void __evaluatePacket(iOMassoth inst, byte* in);
static void __handleSystem(iOMassoth inst, byte* in);
static void __flush( iOMassoth inst );


/** ----- OBase ----- */
static void __del( void* inst ) {
  if( inst != NULL ) {
    iOMassothData data = Data(inst);
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

/** ----- OMassoth ----- */
static int __addChecksum(byte* out) {
  int len = out[0] >> 5;
  int i = 0;
  byte bXor = out[0];

  for ( i = 0; i < len; i++ ) {
    bXor ^= out[i+2];
  }
  out[1] = bXor;

  return len;
}


static Boolean __checkChecksum(byte* in, int len) {
  //int len = in[2] + 1;
  int i = 0;
  byte bXor = in[0];

  for ( i = 0; i < len-2; i++ ) {
    bXor ^= in[i+2];
  }
  if( bXor != in[1] ) {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "checksum error in packet 0x%02X: in[1]=0x%02X bXor=0x%02X", in[0], in[1], bXor );
    TraceOp.dump( name, TRCLEVEL_INFO, (char*)in, len );
    return False;
  }
  return True;
}


static Boolean __readPacket( iOMassoth inst, byte* in ) {
  iOMassothData data = Data(inst);
  Boolean rc = data->dummyio;

  if( !data->dummyio ) {
    Boolean isInfo = False;
    int insize = 0;
    int offset = 0;
    int totallen = 0;
    rc = SerialOp.read( data->serial, (char*)in, 1 );
    totallen = 1;
    if( rc ) {

      if( (in[0] & 0x1F) == 0 ) {
        /* info or answer received */
        rc = SerialOp.read( data->serial, (char*)(in+1), 2 );
        totallen += 2;
        insize = in[2];
        totallen += insize;
        offset = 3;
        isInfo = True;
      }
      else {
        /* command received */
        insize = in[0] >> 5;
        insize++; /* XOR byte */
        totallen += insize;
        offset = 1;
      }

      if( insize > 8 ) {
        TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "invalid packet size=%d", insize );
        TraceOp.dump( name, TRCLEVEL_INFO, (char*)in, offset );
        __flush(inst);
        return False;
      }

      if( rc ) {
        rc = SerialOp.read( data->serial, (char*)(in+offset), insize );
        if( rc ) {
          TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999, "%s packet read:", isInfo ? "info":"command" );
          TraceOp.dump( name, TRCLEVEL_BYTE, (char*)in, insize+offset );
          rc = __checkChecksum(in, totallen);
          if( !rc )
            __flush(inst);
        }
        else {
          /* error reading data */
          TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "error reading data" );
          TraceOp.dump( name, TRCLEVEL_INFO, (char*)in, insize+offset );
        }
      }
    }
    else {
      /* error reading header */
      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "error reading header" );
      data->serialOK = False;
    }


  }

  return rc;
}


static Boolean __transact( iOMassoth inst, byte* out, byte* in, byte id, Boolean *gotid ) {
  iOMassothData data = Data(inst);
  Boolean rc = data->dummyio;

  if( MutexOp.trywait( data->mux, 2500 ) ) {
    int outsize = (out[0] >> 5) + 2;
    int insize  = 0;
    __addChecksum(out);

    TraceOp.dump( name, TRCLEVEL_BYTE, (char*)out, outsize );
    if( !data->dummyio ) {
      if( (rc = SerialOp.write( data->serial, (char*)out, outsize )) ) {
        if( in != NULL ) {
          int wait = 0;
          do {
            if( SerialOp.available( data->serial ) ) {
              if( __readPacket( inst, in ) ) {
                if( in[0] == id ) {
                  /* id match */
                  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "got wanted id[0x%02X]", id );
                  *gotid = True;
                  break;
                }
                /* evaluate response */
                __evaluatePacket(inst, in);
              }
            }
            else {
              ThreadOp.sleep(100);
            }
            wait++;
          } while( wait < 5 );
          if( wait > 4 ) {
            TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "wanted id[0x%02X] not seen within 5 read tries", id );
            *gotid = False;
          }

        }
        ThreadOp.sleep(10);
      }
    }
    MutexOp.post( data->mux );
  }
  return rc;
}


static int __normalizeSteps(int insteps ) {
  /* SPEEDSTEPS: vaild: 14, 28, 128 */
  if( insteps < 20 )
    return 14;
  if( insteps > 100 )
    return 128;
  return 28;
}

/*
2.030 command
                        Header    Xor       Data1     Data2     Data3     Data4
Vehicle configuration : 1000 0101 xxxx xxxx T0AA AAAA AAAA AAAA kkkk kkkk tttt tttt
Delete Vehicle :        0100 0101 xxxx xxxx 00AA AAAA AAAA AAAA
Configuration of announced vehicles
packet size = 4 (6) - Header = 5
packet size = 2 (4) - Header = 5
A13 .. A0 = vehicle address (0..10239) –
k7 [1] store vehilce config in non volatile memory, [0] temporaly in RAM –
k6 = unused –
k5 = unused –
k4 = unused -
k3 = vehicle address NMRA [0], Motorola [1] -
k2 = Funktion parallel [1], serial [0] –
k1..k0 = Speedsteps [00] = 14, [01] = 28, [10] = 128 -
t7 .. t0 = picture of vehicle -
T = [1] loko part of traction, [0] not part [future use, data ignored]

Notes for handling the 'Delete Vehicle' command: The PC may only delete vehicle they:
1st. actually announced by the PC itself or, 2nd not announced by another bus device.
If the command is used, and the loko is occupied from the PC, the vehilce must be logged out before [use command 2.020].
To recognize the vehilce announcement, the PC can monitor all the reflected commands which sent from the interface to PC.

*/
static iOSlot __configureVehicle(iOMassoth inst, iONode node) {
  iOMassothData data = Data(inst);
  /* configure vehicle */
  byte cmd[32] = {0};
  iOSlot slot = NULL;
  int steps  = wLoc.getspcnt(node);
  int addr  = wLoc.getaddr(node);
  int nsteps = __normalizeSteps(steps);
  int protver = wLoc.getprotver(node);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "%s not configured", wLoc.getid(node) );
  cmd[0] = LC_CONFIGURE;
  cmd[1] = 0; /*xor*/
  cmd[2] = addr >> 8;
  cmd[3] = addr & 0x00FF;
  if( nsteps == 128 )
    cmd[4] = 0x02;
  else if( nsteps == 28 )
    cmd[4] = 0x01;
  else
    cmd[4] = 0x00;
  cmd[4] |= (protver == 1) ? 0x04:0x00;
  cmd[4] |= 0x80; /* store */
  cmd[5] = wLoc.getimagenr(node);

  if( __transact( inst, cmd, NULL, 0, NULL ) ) {
    slot = allocMem( sizeof( struct slot) );
    slot->addr = addr;
    slot->steps = __normalizeSteps(steps);
    slot->id = StrOp.dup(wLoc.getid(node));
    slot->idle = SystemOp.getTick();
    if( MutexOp.wait( data->lcmux ) ) {
      MapOp.put( data->lcmap, wLoc.getid(node), (obj)slot);
      MutexOp.post(data->lcmux);
    }
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "slot created for %s, protver=%d locoimage=%d",
        wLoc.getid(node), protver, wLoc.getimagenr(node) );
  }

  return slot;

}


static void __releaseSlot(iOMassoth inst, iOSlot slot) {
  iOMassothData data = Data(inst);
  byte cmd[32] = {0};

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "release slot for %s", slot->id );

  if( MutexOp.wait( data->lcmux ) ) {
    MapOp.remove(data->lcmap, slot->id);
    MutexOp.post(data->lcmux);
  }

  cmd[0] = 0x64;
  cmd[1] = 0; /*xor*/
  cmd[2] = slot->addr >> 8;
  cmd[3] = slot->addr & 0x00FF;
  cmd[4] = 0x00;

  __transact( inst, cmd, NULL, 0, NULL );
}


static iOSlot __getSlotByAddr(iOMassoth inst, int addr) {
  iOMassothData data = Data(inst);
  iOSlot foundSlot = NULL;

  if( MutexOp.wait( data->lcmux ) ) {
    iOSlot slot = (iOSlot)MapOp.first(data->lcmap);
    while( slot != NULL ) {
      if( slot->addr == addr ) {
        foundSlot = slot;
        break;
      }
      slot = (iOSlot)MapOp.next(data->lcmap);
    }
    MutexOp.post(data->lcmux);
  }

  return foundSlot;
}


static iOSlot __getSlot(iOMassoth inst, iONode node) {
  iOMassothData data = Data(inst);
  int steps = wLoc.getspcnt(node);
  int addr  = wLoc.getaddr(node);
  int fncnt = wLoc.getfncnt(node);
  iOSlot slot = NULL;
  byte rsp[32] = {0};
  byte cmd[32] = {0};
  Boolean gotid = False;

  if( MutexOp.wait( data->lcmux ) ) {
    slot = (iOSlot)MapOp.get( data->lcmap, wLoc.getid(node) );
    MutexOp.post(data->lcmux);
  }

  if( slot != NULL ) {
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "slot exist for %s", wLoc.getid(node) );
    return slot;
  }
  cmd[0] = 0x64;
  cmd[1] = 0; /*xor*/
  cmd[2] = addr >> 8;
  cmd[3] = addr & 0x00FF;
  cmd[4] = 0x90 + (wDigInt.isoverrule(data->ini)?0x40:0x00);

  if( __transact( inst, cmd, rsp, 0x40, &gotid ) ) {
    if( gotid ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "announcement response for addr %d [%s]", addr, wLoc.getid(node) );

      if( rsp[2] == 0x04 && rsp[3] == 0x81 ) {
        /* 3.110 address unknown */
        int rspAddr = (rsp[4] << 8) + rsp[5];
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "vehicle %d [%s] unknown...", rspAddr, wLoc.getid(node) );
        slot = __configureVehicle(inst, node);
      }
      else if( rsp[2] == 0x04 && rsp[3] == 0x82 ) {
        /* 3.110 address in use */
        int rspAddr = (rsp[4] << 8) + rsp[5];
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "vehicle %d [%s] in use, delete...", rspAddr, wLoc.getid(node) );
        cmd[0] = 0x45;
        cmd[1] = 0; /*xor*/
        cmd[2] = addr >> 8;
        cmd[3] = addr & 0x00FF;
				if( __transact( inst, cmd, NULL, 0, NULL ) ) {
          slot = __configureVehicle(inst, node);
        }
      }
      else if( rsp[2] == 0x04 ) {
        int rspAddr = (rsp[4] << 8) + rsp[5];
        /*
         * 40 C3 04 80 00 63 64
         */
        if( rsp[3] == 0x80 ) {
          TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "number of max. active locos reached; addr=%d", rspAddr );
        }
        else if( rsp[3] == 0x81 ) {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "unknown loco addr=%d", rspAddr );
        }
        else if( rsp[3] == 0x82 ) {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "addr=%d already in use", rspAddr );
        }
        else if( rsp[3] == 0x83 ) {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "loco list full; addr=%d", rspAddr );
        }
      }
      else if( rsp[2] == 0x08 ) {
        /* 3.100 */
        /* 64 C7 00 33 90 */
        /* 40 1A 08 00 33 85 00 80 00 00 64 */
        int rspAddr = (rsp[3] << 8) + rsp[4];
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "answer for vehicle announcement %d [%s]", rspAddr, wLoc.getid(node) );
        slot = allocMem( sizeof( struct slot) );
        slot->addr = addr;
        if( (rsp[5] & 0x03) == 0x01 )
          slot->steps = 28;
        else if( (rsp[5] & 0x03) == 0x02 )
          slot->steps = 128;
        else
          slot->steps = 14;
        /* address in use */
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "using %d reported speed steps for %d [%s]", slot->steps, rspAddr, wLoc.getid(node) );

        slot->id = StrOp.dup(wLoc.getid(node));
        slot->idle = SystemOp.getTick();
        if( MutexOp.wait( data->lcmux ) ) {
          MapOp.put( data->lcmap, wLoc.getid(node), (obj)slot);
          MutexOp.post(data->lcmux);
        }
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "slot created for %s", wLoc.getid(node) );
      }
      else {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "unknown response for loco %s", wLoc.getid(node) );
        TraceOp.dump( name, TRCLEVEL_INFO, (char*)rsp, 3 + rsp[2] );
      }
    }
    else {
      /* configure vehicle */
      slot = __configureVehicle(inst, node);
    }
  }

  return slot;
}

static Boolean __getFunState(iONode node) {
  int fnchanged = wFunCmd.getfnchanged(node);

  switch( fnchanged ) {
  case  0: return wFunCmd.isf0(node);
  case  1: return wFunCmd.isf1(node);
  case  2: return wFunCmd.isf2(node);
  case  3: return wFunCmd.isf3(node);
  case  4: return wFunCmd.isf4(node);
  case  5: return wFunCmd.isf5(node);
  case  6: return wFunCmd.isf6(node);
  case  7: return wFunCmd.isf7(node);
  case  8: return wFunCmd.isf8(node);
  case  9: return wFunCmd.isf9(node);
  case 10: return wFunCmd.isf10(node);
  case 11: return wFunCmd.isf11(node);
  case 12: return wFunCmd.isf12(node);
  case 13: return wFunCmd.isf13(node);
  case 14: return wFunCmd.isf14(node);
  case 15: return wFunCmd.isf15(node);
  case 16: return wFunCmd.isf16(node);
  case 17: return wFunCmd.isf17(node);
  case 18: return wFunCmd.isf18(node);
  case 19: return wFunCmd.isf19(node);
  case 20: return wFunCmd.isf20(node);
  case 21: return wFunCmd.isf21(node);
  case 22: return wFunCmd.isf22(node);
  case 23: return wFunCmd.isf23(node);
  case 24: return wFunCmd.isf24(node);
  case 25: return wFunCmd.isf25(node);
  case 26: return wFunCmd.isf26(node);
  case 27: return wFunCmd.isf27(node);
  case 28: return wFunCmd.isf28(node);
  }

  return False;
}


static Boolean __translate( iOMassoth inst, iONode node, byte* out ) {
  iOMassothData data = Data(inst);
  /* System command. */
  if( StrOp.equals( NodeOp.getName( node ), wSysCmd.name() ) ) {
    const char* cmd = wSysCmd.getcmd( node );
    if( StrOp.equals( cmd, wSysCmd.stop ) || StrOp.equals( cmd, wSysCmd.ebreak ) ) {
      out[0] = 0x11;
      data->power = False;
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "Power OFF" );
      return True;
    }
    else if( StrOp.equals( cmd, wSysCmd.go ) ) {
      out[0] = 0x10;
      data->power = True;
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "Power ON" );
      return True;
    }
  }


  /* Switch command. */
  else if( StrOp.equals( NodeOp.getName( node ), wSwitch.name() ) ) {
    int addr  = wSwitch.getaddr1( node );
    int port  = wSwitch.getport1( node );

    if( port > 0 ) {
      addr = AddrOp.toPADA( addr, port );
    }

    out[0] = 0x4A;
    out[1] = 0; /*xor*/
    out[2] = (addr >> 6);
    out[3] = (addr << 2) & 0xFC;
    if( StrOp.equals( wSwitch.getcmd( node ), wSwitch.straight ) )
      out[3] |= 1;
    out[3] |= 0x02; /* port on */

    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999,
        "switch addr %d, cmd %s", addr, wSwitch.getcmd( node ) );
    return True;
  }

  /* Output command */
  else if( StrOp.equals( NodeOp.getName( node ), wOutput.name() ) ) {
    int addr   = wOutput.getaddr( node );
    int port   = wOutput.getport( node );
    int gate   = wOutput.getgate( node );
    int action = StrOp.equals( wOutput.getcmd( node ), wOutput.on ) ? 0x01:0x00;

    if( port > 0 ) {
      addr = AddrOp.toPADA( addr, port );
    }

    out[0] = 0x4A;
    out[1] = 0; /*xor*/
    out[2] = (addr >> 6);
    out[3] = (addr << 2) & 0xFC;
    if( StrOp.equals( wOutput.getcmd( node ), wOutput.on ) )
      out[3] |= 0x02;
    out[3] |= gate;

    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999,
        "output addr %d, gate %d, cmd %s", addr, gate, wSwitch.getcmd( node ) );
    return True;
  }


  /* Loc release command. */
  else if( StrOp.equals( NodeOp.getName( node ), wLoc.name() ) && StrOp.equals(wLoc.release, wLoc.getcmd(node)) ) {
    iOSlot slot = __getSlot(inst, node );
    if( slot != NULL ) {
      __releaseSlot(inst, slot );
    }
  }

  /* Loc command.*/
  else if( StrOp.equals( NodeOp.getName( node ), wLoc.name() ) ) {
    int  speed = 0;
    Boolean fn = wLoc.isfn( node );
    int    dir = wLoc.isdir( node );
    int  spcnt = wLoc.getspcnt( node );

    int index = 0;

    iOSlot slot = __getSlot(inst, node );

    if( slot == NULL ) {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "could not get slot for loco %s", wLoc.getid(node) );
      return False;
    }

    spcnt = slot->steps;

    /* Wegen eines Problems bei Lenz Zentralen haben wir bei uns nur einen Regelbereich von 0-126!
     * Den Wert 127 gibt es nicht.
     * Denn bei 100% auf dem Regler bleibt die Lok dann stehen.
     */
    if( spcnt > 126 ) {
      /* correction */
      spcnt = 126;
    }

    if( wLoc.getV( node ) != -1 ) {
      if( StrOp.equals( wLoc.getV_mode( node ), wLoc.V_mode_percent ) )
        speed = (wLoc.getV( node ) * spcnt) / 100;
      else if( wLoc.getV_max( node ) > 0 )
        speed = (wLoc.getV( node ) * spcnt) / wLoc.getV_max( node );
    }

    if( spcnt == 28 && speed > 0 )
      speed += 3; /* 0+1=halt, 2+3=emergency break, 4-31=speed step 1..28 */
    else if( spcnt == 14 && speed > 0 )
      speed += 1; /* 0=halt, 1=emergency break, 2-15=speed step 1..14 */

    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "loc=%s addr=%d speed=%d steps=%d lights=%s dir=%s",
        wLoc.getid(node), wLoc.getaddr(node), speed, spcnt, fn?"on":"off", dir?"forwards":"reverse" );

    slot->speed = speed;
    slot->idle = SystemOp.getTick();

    out[0] = 0x61;
    out[1] = 0; /*xor*/
    out[2] = slot->addr >> 8;
    out[3] = slot->addr & 0x00FF;
    out[4] = speed;
    out[4] |= dir ? 0x80:0x00;

    if( slot->lights != fn ) {
      if( __transact( inst, out, NULL, 0, NULL ) ) {
        out[0] = 0x62;
        out[1] = 0; /*xor*/
        out[2] = slot->addr >> 8;
        out[3] = slot->addr & 0x00FF;
        out[4] = fn ? 0x80:0x00;
        slot->lights = fn;
      }
    }

    return True;

  }

  /* Function command. */
  else if( StrOp.equals( NodeOp.getName( node ), wFunCmd.name() ) ) {
    int fnchanged = wFunCmd.getfnchanged(node);
    int addr      = wFunCmd.getaddr(node);
    Boolean fon   = False;

    TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999, "function %d command for %s", fnchanged, wLoc.getid(node) );
    iOSlot slot = __getSlot(inst, node );

    if( slot == NULL ) {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "could not get slot for loco %s", wLoc.getid(node) );
      return 0;
    }

    if( fnchanged == -1 ) {
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "invalid function %d command for %s", fnchanged, wLoc.getid(node) );
      return False;
    }

    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "function %d command for %s", fnchanged, wLoc.getid(node) );

    slot->idle = SystemOp.getTick();

    fon = __getFunState(node);

    out[0] = 0x62;
    out[1] = 0; /*xor*/
    out[2] = slot->addr >> 8;
    out[3] = slot->addr & 0x00FF;
    out[4] = fnchanged;
    out[4] |= fon ? 0x20:0x00;

    return True;

  }

  /* Programming command. */
  else if( StrOp.equals( NodeOp.getName( node ), wProgram.name() ) ) {
    /* save the cv and value because the write response does not provide them */
    data->ptcv = wProgram.getcv(node);
    data->ptval =wProgram.getvalue(node);

    if(  wProgram.getcmd( node ) == wProgram.set && wProgram.ispom( node )) {
      out[0] = 0xB5;
      out[1] = 0; /*xor*/
      /* CV */
      out[2] = (wProgram.getcv(node)-1) >> 8;
      out[3] = (wProgram.getcv(node)-1) & 0x00FF;
      /* Value*/
      out[4] = wProgram.getvalue(node);
      /* Loco address */
      out[5] = wProgram.getaddr(node) >> 8;
      out[6] = wProgram.getaddr(node) & 0x00FF;
      return True;
    }
    else if(  wProgram.getcmd( node ) == wProgram.set ) {
      out[0] = 0x75;
      out[1] = 0; /*xor*/
      /* CV */
      out[2] = (wProgram.getcv(node)-1) >> 8;
      out[3] = (wProgram.getcv(node)-1) & 0x00FF;
      /* Value*/
      out[4] = wProgram.getvalue(node);
      return True;
    }
    else if(  wProgram.getcmd( node ) == wProgram.get ) {
      out[0] = 0x56;
      out[1] = 0; /*xor*/
      /* CV */
      out[2] = (wProgram.getcv(node)-1) >> 8;
      out[3] = (wProgram.getcv(node)-1) & 0x00FF;
      return True;
    }
  }

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "command [%s] not supported", NodeOp.getName( node ) );


  return False;
}

/**  */
static iONode _cmd( obj inst ,const iONode cmd ) {
  iOMassothData data = Data(inst);
  byte out[256];
  iONode reply = NULL;

  if( cmd != NULL ) {
    byte opcode = 0;
    if( __translate( (iOMassoth)inst, cmd, out ) ) {
      if( __transact( (iOMassoth)inst, out, NULL, 0, NULL ) ) {
      }
    }
  }

  /* Cleanup Node1 */
  cmd->base.del(cmd);

  return reply;
}


/**  */
static void _halt( obj inst, Boolean poweroff, Boolean shutdown ) {
  iOMassothData data = Data(inst);
  int timeout = 0;
  data->shutdown = True;
  while( !data->allPurged && timeout < 50) {
    ThreadOp.sleep(100);
    timeout++;
  }
  data->run = False;
  ThreadOp.sleep(100);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "shutting down <%s>...", data->iid );
  if( data->serial != NULL && data->serialOK ) {
    if( poweroff ) {
      byte cmd[8] = {0x11};
      __transact( (iOMassoth)inst, cmd, NULL, 0, NULL );
      ThreadOp.sleep(100);
    }
    SerialOp.close( data->serial );
  }
}


/**  */
static Boolean _setListener( obj inst ,obj listenerObj ,const digint_listener listenerFun ) {
  iOMassothData data = Data(inst);
  data->listenerObj = listenerObj;
  data->listenerFun = listenerFun;
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "listener set" );
  return True;
}


static Boolean _setRawListener(obj inst, obj listenerObj, const digint_rawlistener listenerFun ) {
  return True;
}

static byte* _cmdRaw( obj inst, const byte* cmd ) {
  return NULL;
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
  return True;
}

static void __handlePT(iOMassoth inst, byte* in) {
  iOMassothData data = Data(inst);
  Boolean OK = ((in[3] & 0x1C) == 0x10 );

  if( in[2] == 0x02 ) {
    /* write feed back */
    iONode response = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setcv( response, data->ptcv );
    wProgram.setvalue( response, OK?data->ptval:-1 );
    wProgram.setcmd( response, wProgram.datarsp );
    if( data->iid != NULL )
      wProgram.setiid( response, data->iid );

    data->listenerFun( data->listenerObj, response, TRCLEVEL_INFO );
  }
  else if( in[2] == 0x04 ) {
    /* read feed back */
    int cv  = in[4] + ((in[3] & 0x03) << 8);
    int val = in[5];
    iONode response = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
    wProgram.setcv( response, cv+1 );
    wProgram.setvalue( response, OK?val:-1 );
    wProgram.setcmd( response, wProgram.datarsp );
    if( data->iid != NULL )
      wProgram.setiid( response, data->iid );

    data->listenerFun( data->listenerObj, response, TRCLEVEL_INFO );
  }
}


static void __handleVehicle(iOMassoth inst, byte* in) {
  iOMassothData data = Data(inst);
  if( in[0] == CS_LC_LOGOUT ) {
    int addr = in[3] * 256 + in[4];
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "vehicle %d logged out from device %d", addr, in[5] );
  }
  else if( in[0] == CS_LC_INVALID && in[2] == 0x08 ) {
    int addr = in[3] * 256 + in[4];
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "vehicle %d not in use", addr );
  }
  else if( in[0] == CS_LC_INVALID && in[2] == 0x04 ) {
    int addr = in[4] * 256 + in[5];
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "vehicle %d in use by device %d", addr, in[6] );
  }
  else if( in[0] == LC_REGISTER ) {
    /* A13 .. A0 = Lokadresse (0..10239) - k7 = [1] bedingungslose Anmeldung – k6 aktiv (1) / passiv (0) Abmelden - k4 = Anmelden (1) / Abmelden (0) */
    byte reg = in[4];
    int addr = (in[2]&0x3F) * 256 + in[3];
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "vehicle %d did %s", addr, (reg&0x10)?"register":"deregister" );
  }
  else if( in[0] == LC_CONFIGURE ) {
    int addr = (in[2]&0x3F) * 256 + in[3];
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "vehicle %d configured, config=0x%02X type=%d", addr, in[4], in[5] );
  }
}


static void __handleError(iOMassoth inst, byte* in) {
  iOMassothData data = Data(inst);
  if( in[2] == CS_ERROR_XOR_DATA1 && in[3] == CS_ERROR_XOR_DATA2 ) {
    /* XOR error in transmission */
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "XOR error in transmission" );
  }
}

static const char* __getCSString(int cs) {
  if( cs == 1 ) return "DiMAX1200Z";
  if( cs == 2 ) return "DiMAX800Z";
  if( cs == 5 ) return "MZS3";
  if( cs == 9 ) return "XPressNet";
  if( cs == 10 ) return "LocoNet";
  return "unknown CS";
}

static void __handleSystem(iOMassoth inst, byte* in) {
  iOMassothData data = Data(inst);
  if( in[2] == CS_SYSTEM_DATA1 ) {
    data->power = (in[3] & 0x03) == 0x00 ? True:False;

    iONode node = NodeOp.inst( wState.name(), NULL, ELEMENT_NODE );
    if( data->iid != NULL )
      wState.setiid( node, data->iid );
    wState.setpower( node, data->power );
    wState.settrackbus( node, data->power );
    wState.setsensorbus( node, data->power );
    wState.setaccessorybus( node, data->power );
    wState.setload( node, data->load );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "system status=0x%02X power=%s", in[3], data->power?"ON":"OFF" );

    if( data->listenerFun != NULL && data->listenerObj != NULL )
      data->listenerFun( data->listenerObj, node, TRCLEVEL_INFO );
  }
  else if( in[2] == CS_LOAD_DATA1 ) {
    /* extended system info
     * 0x00 0x00 0x05 0x00 0x03 0x00 0x00 0x00 */
    if( !data->didShowInfo || data->freeslots != in[7]) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "system load=%dmA loadMax=%dA version=%d.%d freeSlots=%d CS=%s",
          data->load, in[3]&0x0F, in[6] >> 4, in[6] & 0x0F, in[7], __getCSString(in[5]) );
      data->didShowInfo = True;
      data->freeslots = in[7];
    }
    if( data->load != in[4] * 100 ) {
      data->load = in[4] * 100; /* load in steps of 100mA */

      iONode node = NodeOp.inst( wState.name(), NULL, ELEMENT_NODE );
      if( data->iid != NULL )
        wState.setiid( node, data->iid );
      wState.setpower( node, data->power );
      wState.settrackbus( node, data->power );
      wState.setsensorbus( node, data->power );
      wState.setaccessorybus( node, data->power );
      wState.setload( node, data->load );

      TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999, "system load=%dmA", data->load );

      if( data->listenerFun != NULL && data->listenerObj != NULL )
        data->listenerFun( data->listenerObj, node, TRCLEVEL_INFO );
    }
  }
}


static void __handleSwitch(iOMassoth inst, byte* in) {
  iOMassothData data = Data(inst);
  iONode nodeC = NULL;
  Boolean straight = (in[3] & 0x01) ? True:False;
  int addr = in[2] << 6;
  addr += in[3] >> 2;

  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "switch report: addr=%d state=%s", addr, straight?"straight":"turnout" );
  nodeC = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
  wSwitch.setaddr1( nodeC, addr );
  wSwitch.setstate( nodeC, straight ? wSwitch.straight:wSwitch.turnout);
  if( data->iid != NULL )
    wSwitch.setiid( nodeC, data->iid );

  data->listenerFun( data->listenerObj, nodeC, TRCLEVEL_INFO );

}


/*
  feedback data :
  Header     Xor       Data1     Data2
  010 01 011 xxxx xxxx 00ss ssss ssss sssf
 */
static void __handleSensor(iOMassoth inst, byte* in) {
  iOMassothData data = Data(inst);
  iONode nodeC = NULL;
  Boolean state = in[3] & 0x01 ? False:True;
  int addr = in[2] << 7;
  addr += in[3] >> 1;

  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "sensor report: addr=%d state=%s", addr, state?"occupied":"free" );
  nodeC = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
  wFeedback.setaddr( nodeC, addr );
  wFeedback.setstate( nodeC, state );
  if( data->iid != NULL )
    wFeedback.setiid( nodeC, data->iid );

  data->listenerFun( data->listenerObj, nodeC, TRCLEVEL_INFO );

}


static void __handleContact(iOMassoth inst, byte* in) {
  iOMassothData data = Data(inst);
  iONode nodeC = NULL;
  iONode nodeD = NULL;
  Boolean state = in[3] & 0x01 ? True:False;
  int addr = in[2] << 6;
  addr += in[3] >> 2;
  addr = addr * 2 - 1 + state;

  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "contact report: addr=%d state=true (set)", addr );
  nodeC = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
  wFeedback.setaddr( nodeC, addr );
  wFeedback.setstate( nodeC, True );
  if( data->iid != NULL )
    wFeedback.setiid( nodeC, data->iid );

  nodeD = (iONode)NodeOp.base.clone(nodeC);

  data->listenerFun( data->listenerObj, nodeC, TRCLEVEL_INFO );

  NodeOp.setLong(nodeD, "tick", SystemOp.getTick() );
  ThreadOp.post( data->ticker, (obj)(nodeD) );
}


static void __handleLocoSpeed( iOMassoth inst, byte* in) {
  iOMassothData data = Data(inst);
  int     addr  = in[2] * 256 + in[3];
  int     speed = in[4] & 0x7F;
  Boolean dir   = (in[4] & 0x80) ? True:False;
  iOSlot  slot  = __getSlotByAddr(inst, addr);
  iONode  nodeC = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );

  if( slot != NULL ) {
    /* update slot */
    slot->speed = speed;
    slot->dir   = dir;
  }

  if( data->iid != NULL )
    wLoc.setiid( nodeC, data->iid );
  if( slot != NULL )
    wLoc.setid( nodeC, slot->id );

  wLoc.setaddr( nodeC, addr );
  wLoc.setV_raw( nodeC, speed );
  wLoc.setdir( nodeC, dir );
  wLoc.setcmd( nodeC, wLoc.velocity );
  wLoc.setthrottleid( nodeC, "dimax" );

  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999,
      "loco=%s addr=%d speed=%d dir=%s", slot!=NULL?slot->id:"-", addr, speed, dir?"fwd":"rev" );

  data->listenerFun( data->listenerObj, nodeC, TRCLEVEL_INFO );

}


static void __handleLocoFunctions( iOMassoth inst, byte* in) {
  iOMassothData data = Data(inst);
  int     addr   = in[2] * 256 + in[3];
  Boolean lights = (in[4] & 0x80) ? True:False;
  int     fn     = (in[4] & 0x18);
  Boolean on     = (in[4] & 0x20) ? True:False;
  iOSlot  slot  = __getSlotByAddr(inst, addr);
  iONode  nodeD  = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE );

  int group = fn / 4;
  if( fn % 4 != 0 )
    group++;

  if( slot != NULL ) {
    /* update slot */
    slot->lights = lights;
  }

  if( data->iid != NULL )
    wLoc.setiid( nodeD, data->iid );
  if( slot != NULL )
    wFunCmd.setid( nodeD, slot->id );
  wFunCmd.setaddr( nodeD, addr );
  wLoc.setthrottleid( nodeD, "dimax" );

  wLoc.setfn( nodeD, lights );
  wFunCmd.setf0( nodeD, lights );
  wFunCmd.setfnchanged(nodeD, fn);
  wFunCmd.setgroup( nodeD, group );
  char f[32];
  StrOp.fmtb(f, "f%d", fn);
  NodeOp.setBool(nodeD, f, on?True:False);
  data->listenerFun( data->listenerObj, nodeD, TRCLEVEL_INFO );
}


static void __evaluatePacket(iOMassoth inst, byte* in) {
  iOMassothData data = Data(inst);
  switch( in[0] ) {
  case CS_SYSTEM:
    /* system status */
    __handleSystem(inst, in);
    break;
  case CS_ERROR_XOR:
    /* error */
    __handleError(inst, in);
    break;
  case SW_COMMAND:
    __handleSwitch(inst, in);
    break;
  case CS_LC_FREE:
  case CS_LC_LOGOUT:
  case LC_REGISTER:
  case LC_CONFIGURE:
    /* vehicle report */
    __handleVehicle(inst, in);
    break;
  case LC_SPEEDDATA:
    /* loco speed */
    __handleLocoSpeed(inst, in);
    break;
  case LC_FUNCTIONDATA:
    /* loco functions */
    __handleLocoFunctions(inst, in);
    break;
  case FB_EVENT:
    /* sensor report */
    if( data->fbreset)
      __handleContact(inst, in);
    else
      __handleSensor(inst, in);
    break;
  case CS_PROG_ACK:
    /* programming report */
    __handlePT(inst, in);
    break;
  case EBREAK_SET:
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "emergency break set" );
    break;
  case EBREAK_RESET:
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "emergency break reset" );
    break;
  case EBREAK_RESET_PACKET:
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "emergency break reset packet" );
    break;
  default:
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "message 0x%02X not evaluated", in[0] );
    TraceOp.dump( name, TRCLEVEL_INFO, (char*)in, 32 );
    break;
  }
}


static void __reader( void* threadinst ) {
  iOThread      th      = (iOThread)threadinst;
  iOMassoth     massoth = (iOMassoth)ThreadOp.getParm( th );
  iOMassothData data    = Data(massoth);

  byte out[256];
  byte test[] = {0x4B, 0x5B, 0x00, 0x05};
  data->initialized = False;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "DiMAX reader started." );
  ThreadOp.sleep( 100 );


  /* sending the interface configuration: must be the first packet */
  out[0] = INTERFACE_REGISTER;
  out[1] = 0x00; /* XOR */
  out[2] = data->systeminfo ? 0x01:0x00; /* extended info */
  out[3] = 0x00;
  out[4] = 0x00;
  out[5] = 0x39;
  out[6] = 0xF4;

  while( data->run ) {

    if( !data->serialOK ) {
      data->serial = SerialOp.inst( data->device );
      SerialOp.setFlow( data->serial, cts );
      SerialOp.setLine( data->serial, 57600, 8, 1, none, wDigInt.isrtsdisabled( data->ini ) );
      SerialOp.setTimeout( data->serial, wDigInt.gettimeout(data->ini), wDigInt.gettimeout(data->ini) );
      data->serialOK = SerialOp.open( data->serial );
      if( !data->serialOK ) {
        SerialOp.base.del(data->serial);
        data->serial = NULL;
        data->initialized = False;
        ThreadOp.sleep(2500);
        continue;
      }
      else {
        __flush(massoth);
      }
    }


    if( !data->initialized ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "sending interface configuration..." );
      data->initialized = __transact( massoth, out, NULL, 0, NULL );
      if( !data->initialized ) {
        ThreadOp.sleep( 1000 );
        continue;
      }
      else {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "interface configuration successfully send" );
        /*__evaluatePacket(data, test);*/
      }
    }

    /* normal reading processing */
    if( data->run && data->serial != NULL ) {

      if( MutexOp.wait( data->mux ) ) {
        Boolean evaluate = False;
        byte in[256];

        if( SerialOp.available( data->serial ) ) {
          evaluate = __readPacket(massoth, in);
          if( !data->serialOK ) {
            SerialOp.base.del(data->serial);
            data->serial = NULL;
            data->initialized = False;
            evaluate = False;
          }
        }

        MutexOp.post( data->mux );
        if( evaluate )
          __evaluatePacket(massoth, in);
      }
    }

    ThreadOp.sleep( 10 );
  }

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "DiMAX reader ended." );
}



/** vmajor*1000 + vminor*100 + patch */
static int vmajor = 2;
static int vminor = 0;
static int patch  = 0;
static int _version( obj inst ) {
  iOMassothData data = Data(inst);
  return vmajor*10000 + vminor*100 + patch;
}


static void __ContactTicker( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOMassoth inst = (iOMassoth)ThreadOp.getParm( th );
  iOMassothData data = Data(inst);
  iOList list = ListOp.inst();

  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "contact ticker started." );
  ThreadOp.sleep(1000);

  while( data->run ) {
    int i = 0;
    obj post = ThreadOp.getPost( th );
    if (post != NULL) {
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "post: contact addr=%d", wFeedback.getaddr((iONode)post) );
      ListOp.add(list, post);
    }

    for( i = 0; i < ListOp.size(list); i++ ) {
      iONode node = (iONode)ListOp.get(list, i);
      if( SystemOp.getTick() - NodeOp.getLong( node, "tick", 0 ) > 250 ) {
        iONode evt = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
        wFeedback.setstate( evt, False );
        wFeedback.setaddr( evt, wFeedback.getaddr(node) );
        if( data->iid != NULL )
          wFeedback.setiid( evt, data->iid );

        TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "contact addr=%d state=false (reset)", wFeedback.getaddr(evt) );
        data->listenerFun( data->listenerObj, evt, TRCLEVEL_INFO );
        ListOp.removeObj(list, (obj)node);
        NodeOp.base.del(node);
        break;
      }
      ThreadOp.sleep(10);
    }

    ThreadOp.sleep(100);
  };

  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "contact ticker ended." );
}


static void __purger( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOMassoth inst = (iOMassoth)ThreadOp.getParm( th );
  iOMassothData data = Data(inst);

  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "purger started." );
  ThreadOp.sleep(1000);

  while( data->run ) {
    if( MutexOp.wait( data->lcmux ) ) {
      iOSlot slot = (iOSlot)MapOp.first(data->lcmap);
      while( slot != NULL ) {
        if( (slot->speed == 0 && ( SystemOp.getTick() - slot->idle ) > 3000) || data->shutdown ) {
          byte cmd[32];
          byte rsp[32];
          Boolean gotid = False;
          cmd[0] = 0x64;
          cmd[1] = 0; /*xor*/
          cmd[2] = slot->addr >> 8;
          cmd[3] = slot->addr & 0x00FF;
          cmd[4] = 0x00;

          if( __transact( inst, cmd, rsp, 0x60, &gotid ) ) {
            TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "slot purged for %s speed=%d", slot->id, slot->speed );
            MapOp.remove(data->lcmap, slot->id );
          }
          else {
            TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "could not purge slot for %s", slot->id );
          }
          break;
        }
        slot = (iOSlot)MapOp.next(data->lcmap);
      }
      MutexOp.post(data->lcmux);
    }

    if( data->shutdown && MapOp.size(data->lcmap) == 0 ) {
      break;
    }
    ThreadOp.sleep(100);
  };

  data->allPurged = True;

  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "purger ended." );
}


static void __stressRunner( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOMassoth massoth = (iOMassoth)ThreadOp.getParm( th );
  iOMassothData data = Data(massoth);
  byte out[32] = {0x10,0x00};
  int addr = 136;
  Boolean straight = True;

  ThreadOp.sleep(5000);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "stress runner started." );

  /* try to get the system status: */
  while( data->run ) {
    out[0] = 0x4A;
    out[1] = 0; /*xor*/
    out[2] = (addr >> 6);
    out[3] = (addr << 2) & 0xFC;
    if( straight )
      out[3] |= 1;
    out[3] |= 0x02; /* port on */
    straight = !straight;
    __transact( massoth, out, NULL, 0, NULL );
    ThreadOp.sleep(5);
  };

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "stress runner ended." );
}


static void __flush( iOMassoth inst ) {
  iOMassothData data = Data(inst);
  Boolean ok = False;
  char buffer[256];
  int idx = 0;
  ThreadOp.sleep(100);
  while( SerialOp.available(data->serial) && idx < 256 ) {
    SerialOp.read( data->serial, buffer+idx, 1 );
    idx++;
  }
  if( idx > 0 ) {
    TraceOp.trc(name, TRCLEVEL_INFO, __LINE__, 9999, "Flushing %d bytes", idx);
    TraceOp.dump( name, TRCLEVEL_INFO, buffer, idx );
    if( idx == 256 ) {
      TraceOp.trc(name, TRCLEVEL_WARNING, __LINE__, 9999, "Flushing recursive...");
      __flush(inst);
    }
  }
}


/**  */
static struct OMassoth* _inst( const iONode ini ,const iOTrace trc ) {
  iOMassoth __Massoth = allocMem( sizeof( struct OMassoth ) );
  iOMassothData data = allocMem( sizeof( struct OMassothData ) );
  MemOp.basecpy( __Massoth, &MassothOp, 0, sizeof( struct OMassoth ), data );

  TraceOp.set( trc );
  SystemOp.inst();

  /* Initialize data->xxx members... */
  data->mux     = MutexOp.inst( NULL, True );
  data->lcmux   = MutexOp.inst( NULL, True );
  data->lcmap   = MapOp.inst();

  data->device     = StrOp.dup( wDigInt.getdevice( ini ) );
  data->iid        = StrOp.dup( wDigInt.getiid( ini ) );
  data->dummyio    = wDigInt.isdummyio(ini);
  data->fbreset    = wDigInt.isfbreset(ini);
  data->systeminfo = wDigInt.issysteminfo(ini);
  data->useParallelFunctions = True;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Massoth %d.%d.%d", vmajor, vminor, patch );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "iid           = %s", data->iid );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "device        = %s", data->device );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "baudrate      = 57600 (fix)" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "reset sensors = %s", data->fbreset ? "yes":"no" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "system info   = %s", data->systeminfo ? "yes":"no" );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "----------------------------------------" );

  data->serialOK = False;
  if( !data->dummyio ) {
    data->serial = SerialOp.inst( data->device );
    SerialOp.setFlow( data->serial, cts );
    SerialOp.setLine( data->serial, 57600, 8, 1, none, wDigInt.isrtsdisabled( ini ) );
    SerialOp.setTimeout( data->serial, wDigInt.gettimeout(ini), wDigInt.gettimeout(ini) );
    data->serialOK = SerialOp.open( data->serial );
  }

  if(data->serialOK) {
    __flush(__Massoth);
    data->run = True;
    data->reader = ThreadOp.inst( "dimaxreader", &__reader, __Massoth );
    ThreadOp.start( data->reader );

    data->purger = ThreadOp.inst( "purger", &__purger, __Massoth );
    ThreadOp.start( data->purger );

    if( data->fbreset ) {
      char* thname = StrOp.fmt("massothtick%X", __Massoth);
      data->ticker = ThreadOp.inst( thname, &__ContactTicker, __Massoth );
      StrOp.free(thname),
      ThreadOp.start( data->ticker );
    }

    if( wDigInt.isstress(ini) ) {
      data->stressRunner = ThreadOp.inst( "dimaxstress", &__stressRunner, __Massoth );
      ThreadOp.start( data->stressRunner );
    }
  }
  else {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "unable to initialize device; switch to dummy mode" );
    data->dummyio = True;
    data->serial = NULL;
  }

  instCnt++;
  return __Massoth;
}


iIDigInt rocGetDigInt( const iONode ini ,const iOTrace trc )
{
  return (iIDigInt)_inst(ini,trc);
}


/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocdigs/impl/massoth.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
