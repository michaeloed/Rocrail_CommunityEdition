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
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "rocrail/impl/tt_impl.h"
#include "rocrail/public/app.h"
#include "rocrail/public/model.h"
#include "rocrail/public/switch.h"
#include "rocrail/public/action.h"

#include "rocrail/wrapper/public/Action.h"
#include "rocrail/wrapper/public/ActionCtrl.h"

#include "rocs/public/doc.h"
#include "rocs/public/trace.h"
#include "rocs/public/node.h"
#include "rocs/public/mem.h"
#include "rocs/public/str.h"
#include "rocs/public/system.h"


#include "rocrail/wrapper/public/Turntable.h"
#include "rocrail/wrapper/public/TTTrack.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/FunCmd.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/FeedbackEvent.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/Program.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/Route.h"
#include "rocrail/wrapper/public/SwitchCmd.h"
#include "rocrail/wrapper/public/Item.h"

static int instCnt = 0;

static int __getMappedTrack( iOTT inst, int tracknr );
static int __getOppositeTrack( iOTT inst, int tracknr );
static int __getNextTrack( iOTT inst, int tracknr );
static int __getPrevTrack( iOTT inst, int tracknr );
static void __polarize(obj inst, int pos, Boolean polarization);
static void __sortTracks(iOTT tt);
static void __cpFn2Node( iOTT inst, iONode fcmd );
static Boolean __isElectricallyFree( iOTT inst );
static int __getOppositeTrackNr(int pos);

/*
 ***** OBase functions.
 */
static const char* __id( void* inst ) {
  iOTTData data = Data(inst);
  return wTurntable.getid( data->props );
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
  iOTTData data = Data(inst);
  iOTT     tt   = (iOTT)inst;

  return (char*)tt->base.id(tt);
}
static void __del(void* inst) {
  iOTTData data = Data(inst);
  MutexOp.base.del(data->muxLock);
  freeMem( data );
  freeMem( inst );
  instCnt--;
}
static void* __properties(void* inst) {
  iOTTData data = Data(inst);
  return data->props;
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
 ***** _Public functions.
 */

static void _depart(iIBlockBase inst) {
}


static void __checkAction( iOTT inst, const char* cmd ) {

  iOTTData data     = Data(inst);
  iOModel  model    = AppOp.getModel();
  iONode   ttaction = wTurntable.getactionctrl( data->props );

  while( ttaction != NULL) {
    if( StrOp.len( wActionCtrl.getstate(ttaction) ) == 0 ||
        StrOp.equals(wActionCtrl.getstate(ttaction), cmd ) )
    {
      iOAction action = ModelOp.getAction( AppOp.getModel(), wActionCtrl.getid( ttaction ));
      if( action != NULL ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "turntable action: %s", wActionCtrl.getid( ttaction ));

        if( wAction.getoid( ttaction) == NULL || StrOp.len(wAction.getoid( ttaction)) == 0 ) {
          wActionCtrl.setlcid( ttaction, data->lockedId );
          if(data->lockedId != NULL && StrOp.len(data->lockedId) > 0 ) {
            iOLoc lc = ModelOp.getLoc( AppOp.getModel(), data->lockedId, NULL, False );
            if( lc != NULL ) {
              wActionCtrl.setlcclass(ttaction, LocOp.getClass(lc));
            }
          }
        }

        wActionCtrl.setbkid(ttaction, wTurntable.getid( data->props ));

        ActionOp.exec(action, ttaction);
      }
    }
    else {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "%s action state does not match: [%s-%s]",
          wTurntable.getid(data->props), wActionCtrl.getstate( ttaction ), cmd );
    }
    ttaction = wTurntable.nextactionctrl( data->props, ttaction );
  } /* end loop */

  ttaction = NULL;

}



/**
 * Checks for property changes.
 * todo: Range checking?
 */
static void _modify( iOTT inst, iONode props ) {
  iOTTData o = Data(inst);
  Boolean move = StrOp.equals( wModelCmd.getcmd( props ), wModelCmd.move );
  int cnt = NodeOp.getAttrCnt( props );
  int i = 0;
  for( i = 0; i < cnt; i++ ) {
    iOAttr attr = NodeOp.getAttr( props, i );
    const char* name  = AttrOp.getName( attr );
    const char* value = AttrOp.getVal( attr );

    if( StrOp.equals("id", name) && StrOp.equals( value, wTurntable.getid(o->props) ) )
      continue; /* skip to avoid making invalid pointers */

    NodeOp.setStr( o->props, name, value );
  }

  if( !move ) {
    cnt = NodeOp.getChildCnt( o->props );
    while( cnt > 0 ) {
      iONode child = NodeOp.getChild( o->props, 0 );
      iONode removedChild = NodeOp.removeChild( o->props, child );
      if( removedChild != NULL) {
        NodeOp.base.del(removedChild);
      }
      cnt = NodeOp.getChildCnt( o->props );
    }
    cnt = NodeOp.getChildCnt( props );
    for( i = 0; i < cnt; i++ ) {
      iONode child = NodeOp.getChild( props, i );
      NodeOp.addChild( o->props, (iONode)NodeOp.base.clone(child) );
      __sortTracks(inst);
    }
  }
  else {
    NodeOp.removeAttrByName(o->props, "cmd");
  }

  /* Broadcast to clients. */
  {
    iONode clone = (iONode)NodeOp.base.clone( o->props );
    if( o->lockedId != NULL )
      wTurntable.setlocid( clone, o->lockedId );
    AppOp.broadcastEvent( clone );
  }
  props->base.del(props);
}


static iONode __getTrackNode( iOTT inst, int tracknr ) {
  iOTTData data = Data(inst);

  iONode track = wTurntable.gettrack( data->props );
  while( track != NULL ) {
    if( tracknr == wTTTrack.getnr( track ) ) {
      if( wTTTrack.getnr( track ) == tracknr ) {
        return track;
      }
    }
    track = wTurntable.nexttrack( data->props, track );
  }

  return NULL;
}



/*
 * calculate direction
 *
 */
static const Boolean CCW = True;
static const Boolean CW  = False;
static Boolean __bridgeDir( iOTT inst, int destpos, Boolean* ttdir, Boolean byroute ) {
  iOTTData data = Data(inst);
  Boolean swap = wTurntable.isswaprotation(data->props);
  Boolean move4opp = wTurntable.ismove4opp(data->props);

  data->lcdir = True;

  if( !byroute ) {
    byroute = move4opp;
  }

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "from track[%d] to track[%d]", data->tablepos, destpos );

  if( data->tablepos == destpos ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "wanted destination position[%d] equals the table position[%d]", destpos, data->tablepos );
    return False;
  }

  if( !byroute && ((data->tablepos + 24 == destpos) || (destpos + 24 == data->tablepos)) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "wanted destination position[%d] is the opposite of the table position[%d]", destpos, data->tablepos );
    if( destpos != data->tablepos )
      data->lcdir = False;
    return False;
  }

  if( destpos > data->tablepos && destpos - data->tablepos <= 24 )
    *ttdir = swap?CW:CCW;
  else if( destpos < data->tablepos && data->tablepos - destpos >= 24 )
    *ttdir = swap?CW:CCW;
  else
    *ttdir = swap?CCW:CW;

  return True;
}


/** DIGITALBAHN
 * function offset  red      green
 * -------- ------- -------- --------
 * lights   0       off      on
 * step     1       right    left
 * turn     2       right    left
 * dir      3       CW       CCW
 * pos      4       #1       #2
 * pos      5       #3       #4
 * pos      6       #5       #6
 * pos      7       #7       #8
 * pos      8       #9       #10
 * pos      9       #11      #12
 * pos      10      #13      #14
 * pos      11      #15      #16
 * pos      12      #17      #18
 * pos      13      #19      #20
 * pos      14      #21      #22
 * pos      15      #23      #24
 */
static const int DIGITALBAHN_LIGHT = 0;
static const int DIGITALBAHN_STEP  = 1;
static const int DIGITALBAHN_TURN  = 2;
static const int DIGITALBAHN_DIR   = 3;
static const int DIGITALBAHN_POS   = 4;

static const char* DIGITALBAHN_DIR_CW  = "turnout";
static const char* DIGITALBAHN_DIR_CCW = "straight";

static Boolean __cmd_digitalbahn( iOTT inst, iONode nodeA ) {
  iOTTData data = Data(inst);
  Boolean ok = True;
  iOControl control = AppOp.getControl();
  const char* cmdStr = wTurntable.getcmd( nodeA );
  Boolean ttdir = True;
  Boolean doDirCmd = False;
  int port = 0;
  const char* cmdstr = NULL;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "TT command = [%s]", cmdStr );

  if( StrOp.equals( wTurntable.next, cmdStr ) ) {
    port = DIGITALBAHN_STEP;
    cmdstr = wSwitch.straight;
    data->pending = True;
    /* set gotopos for previous track */
    data->gotopos = __getNextTrack(inst, wTurntable.getbridgepos( data->props));
  }
  else if( StrOp.equals( wTurntable.prev, cmdStr ) ) {
    port = DIGITALBAHN_STEP;
    cmdstr = wSwitch.turnout;
    data->pending = True;
    /* set gotopos for previous track */
    data->gotopos = __getPrevTrack(inst, wTurntable.getbridgepos( data->props));
  }
  else if( StrOp.equals( wTurntable.turn180, cmdStr ) ) {
    port = DIGITALBAHN_TURN;
    cmdstr = wSwitch.straight;
    data->pending = True;
  }
  else if( StrOp.equals( wTurntable.lighton, cmdStr ) ) {
    port = DIGITALBAHN_LIGHT;
    data->light = !data->light;
    cmdstr = data->light?wSwitch.straight:wSwitch.turnout;
  }
  else if( StrOp.equals( wTurntable.lightoff, cmdStr ) ) {
    port = DIGITALBAHN_LIGHT;
    cmdstr = wSwitch.turnout;
  }
  else if( StrOp.equals( wTurntable.calibrate, cmdStr ) ) {
  }
  else if( StrOp.equals(wTurntable.fon, cmdStr ) || StrOp.equals( wTurntable.foff, cmdStr )) {
  }
  else {
    /* Tracknumber */
    int tracknr = atoi( cmdStr );
    /* DA Save tracknumber for 180 degrees turn */
    int orig_tracknr = tracknr;

    Boolean move = __bridgeDir(inst, tracknr, &ttdir, wTurntable.iscmdbyroute(nodeA) );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "Goto track %d, current pos=%d", tracknr, data->tablepos );

    if( move ) {
      /* check for a mapping of the track number */
      data->gotopos = tracknr;
      tracknr = __getMappedTrack( inst, tracknr );

      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Goto decoder track [%d] in direction [%s]", tracknr, ttdir ? "CCW":"CW" );
      data->pending = True;

      doDirCmd = True;

      port = DIGITALBAHN_POS + ((tracknr-1)/2);
      if( (tracknr-1) % 2 == 0 )
        cmdstr = wSwitch.turnout;
      else
        cmdstr = wSwitch.straight;

      /* DA check whether 180 degrees turn is required */
      if( (data->tablepos-orig_tracknr) == 24)
      {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
            "Turn 180 ---> Goto track [%d], current pos=[%d]", tracknr, data->tablepos );
        port   = DIGITALBAHN_TURN;
        cmdstr = wSwitch.straight;
      }
      else if( (data->tablepos-orig_tracknr) == -24)
      {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
            "Turn 180 ---> Goto track [%d], current pos=[%d]", tracknr, data->tablepos );
        port   = DIGITALBAHN_TURN;
        cmdstr = wSwitch.straight;
      }
      /* DA check whether 180 degrees turn is required */

    }
    else {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "bridge already at track %d", tracknr );
      __polarize((obj)inst, tracknr, False);
    }
  }

 /* Broadcast to clients. */
  if (port == DIGITALBAHN_STEP || port >= DIGITALBAHN_POS)
  {
    iONode track = wTurntable.gettrack( data->props );
    while ( track != NULL ) {
      if  ( wTTTrack.getnr( track ) == data->gotopos){
        if ( (( wTTTrack.getposfb( track) == NULL) || StrOp.equals( wTTTrack.getposfb( track), "\0"))
        && (( wTurntable.getpsen( data->props ) == NULL) || StrOp.equals( wTurntable.getpsen( data->props ), "\0")))
        {
          /* Only if no fb for track or position reached is defined */
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "draw bridge position %d", data->gotopos );
          iONode event = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
          wTurntable.setid( event, wTurntable.getid( data->props ) );
          wTurntable.setbridgepos( event, data->gotopos );
          if( data->lockedId != NULL )
            wTurntable.setlocid( event, data->lockedId );
          if( wTurntable.getiid( data->props ) != NULL )
            wTurntable.setiid( event, wTurntable.getiid( data->props ) );
          AppOp.broadcastEvent( event );
        }
        else
        {
          /* Delete position if fb for track or bridge in position available to improve visual feedback on display*/
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "position deleted waiting for fb event" );
          iONode event = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
          wTurntable.setid( event, wTurntable.getid( data->props ) );
          wTurntable.setbridgepos( event, -1 );
          if( data->lockedId != NULL )
            wTurntable.setlocid( event, data->lockedId );
          if( wTurntable.getiid( data->props ) != NULL )
            wTurntable.setiid( event, wTurntable.getiid( data->props ) );
          AppOp.broadcastEvent( event );
        }
      }
      track = wTurntable.nexttrack( data->props, track );
    }
  }

  if( cmdstr != NULL && control != NULL )
  {
    /* Direction */
    if( doDirCmd ) {
      iONode cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );

      int addr = wTurntable.getaddr( data->props );
      const char* iid = wTurntable.getiid( data->props );
      if( iid != NULL )
        wSwitch.setiid( cmd, iid );

      wOutput.setbus( cmd, wTurntable.getbus( data->props ) );
      wOutput.setaccessory( cmd, True );
      wSwitch.setprot( cmd, wTurntable.getprot( data->props ) );

      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "set direction address=%d, port=%d, gate=%s",
          addr, DIGITALBAHN_DIR, ttdir ? DIGITALBAHN_DIR_CCW:DIGITALBAHN_DIR_CW );
      int addrCmd = (addr-1 + DIGITALBAHN_DIR) / 4 + 1; /* address bug correction */
      int portCmd = (addr-1 + DIGITALBAHN_DIR) % 4 + 1; /* address bug correction */
      wSwitch.setaddr1( cmd, addrCmd );
      wSwitch.setport1( cmd, portCmd );
      wSwitch.setcmd  ( cmd, ttdir ? DIGITALBAHN_DIR_CCW:DIGITALBAHN_DIR_CW );
      wSwitch.setprot( cmd, wTurntable.getprot( data->props ) );

      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "sending switch command [%d,%d,%s]...",
                   addrCmd, portCmd, ttdir ? DIGITALBAHN_DIR_CCW:DIGITALBAHN_DIR_CW);

      ControlOp.cmd( control, cmd, NULL );
      /* give the decoder some time to think... */
      ThreadOp.sleep( wTurntable.getpause( data->props ) * 1000 );
    }


    /* Command */
    iONode cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );

    int addr = wTurntable.getaddr( data->props );
    const char* iid = wTurntable.getiid( data->props );
    if( iid != NULL )
      wSwitch.setiid( cmd, iid );

    wOutput.setbus( cmd, wTurntable.getbus( data->props ) );
    wOutput.setaccessory( cmd, True );
    wSwitch.setprot( cmd, wTurntable.getprot( data->props ) );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "set position address=%d, port=%d, gate=%s",
        addr, port, cmdstr );

    int addrCmd = (addr-1 + port) / 4 + 1; /* address bug correction */
    int portCmd = (addr-1 + port) % 4 + 1; /* address bug correction */
    wSwitch.setaddr1( cmd, addrCmd );
    wSwitch.setport1( cmd, portCmd );
    wSwitch.setcmd  ( cmd, cmdstr );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "sending switch command [%d,%d]...", addrCmd, portCmd );

    wSwitch.setprot( cmd, wTurntable.getprot( data->props ) );
    ControlOp.cmd( control, cmd, NULL );
    /* give the decoder some time to think... */
    ThreadOp.sleep(100);

    /* set tablepos optimistic predicted, if fb is not defined for destination track */
    iONode track = wTurntable.gettrack( data->props );
    while ( track != NULL ) {
      if ( ( wTTTrack.getnr( track ) == data->gotopos)
        && ( ( wTTTrack.getposfb( track) == NULL) || StrOp.equals( wTTTrack.getposfb( track), "\0"))) {
        data->tablepos = data->gotopos; /* lines switched in order to get correct trace */
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "set optimistic tablepos %d", data->tablepos ); /* lines switched in order to get correct trace */

        wTurntable.setbridgepos( data->props, data->tablepos );
      }
      track = wTurntable.nexttrack( data->props, track );
    }
  }
  else {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "no command sent" );
  }

  /* Cleanup Node1 */
  nodeA->base.del(nodeA);
  return ok;
}


static Boolean __cmd_dsm( iOTT inst, iONode nodeA ) {
  iOTTData data = Data(inst);
  Boolean ok = True;
  iOControl control = AppOp.getControl();
  const char* cmdStr = wTurntable.getcmd( nodeA );
  Boolean ttdir = True;
  Boolean doDirCmd = False;
  int port = -1;
  int tracknr = -1;
  iONode cmd = NULL;
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "TT command = [%s]", cmdStr );


  if( StrOp.equals( wTurntable.next, cmdStr ) ) {
    port = 1;
  }
  else if( StrOp.equals( wTurntable.prev, cmdStr ) ) {
    port = 2;
  }
  else if( StrOp.equals( wTurntable.turn180, cmdStr ) ) {
    port = ttdir?3:4;
  }
  else if( StrOp.equals( wTurntable.calibrate, cmdStr ) ) {
  }
  else if( StrOp.equals( wTurntable.lighton, cmdStr ) ) {
  }
  else if( StrOp.equals( wTurntable.lightoff, cmdStr ) ) {
  }
  else if( StrOp.equals(wTurntable.fon, cmdStr ) || StrOp.equals( wTurntable.foff, cmdStr )) {
  }
  else {
    /* Tracknumber */
    tracknr = atoi( cmdStr );
  }

  if( port != -1 ) {
    cmd = NodeOp.inst( wOutput.name(), NULL, ELEMENT_NODE );
    wOutput.setbus( cmd, wTurntable.getbus( data->props ) );
    wItem.setuidname( cmd, wItem.getuidname(data->props) );
    wOutput.setaddr( cmd, wTurntable.getaddr( data->props ) );

    wOutput.setport( cmd, 8 );
    wOutput.setcmd( cmd, wOutput.off );
    ControlOp.cmd( control, (iONode)NodeOp.base.clone(cmd), NULL );
    wOutput.setport( cmd, 7 );
    wOutput.setcmd( cmd, wOutput.off );
    ControlOp.cmd( control, (iONode)NodeOp.base.clone(cmd), NULL );
    ThreadOp.sleep( 100 );


    wOutput.setport( cmd, port );
    wOutput.setcmd( cmd, wOutput.on );

    const char* iid = wTurntable.getiid( data->props );
    if( iid != NULL )
      wOutput.setiid( cmd, iid );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "dsm (%s): sending output command [%d,%d,%s]",
        cmdStr, wOutput.getaddr(cmd), wOutput.getport(cmd), wOutput.getcmd(cmd) );

    ControlOp.cmd( control, (iONode)NodeOp.base.clone(cmd), NULL );
    ThreadOp.sleep( 500 );
    wOutput.setcmd( cmd, wOutput.off );
    ControlOp.cmd( control, cmd, NULL );
  }

  else if( tracknr != -1 ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "dsm: goto track %d", tracknr );
    data->gotopos = tracknr;

    tracknr = __getMappedTrack( inst, tracknr );

    cmd = NodeOp.inst( wOutput.name(), NULL, ELEMENT_NODE );
    wOutput.setbus( cmd, wTurntable.getbus( data->props ) );
    wItem.setuidname( cmd, wItem.getuidname(data->props) );
    wOutput.setaddr( cmd, wTurntable.getaddr( data->props ) );
    const char* iid = wTurntable.getiid( data->props );
    if( iid != NULL )
      wOutput.setiid( cmd, iid );

    wOutput.setport( cmd, 8 );
    wOutput.setcmd( cmd, wOutput.off );
    ControlOp.cmd( control, (iONode)NodeOp.base.clone(cmd), NULL );
    wOutput.setport( cmd, 7 );
    wOutput.setcmd( cmd, wOutput.on );
    ControlOp.cmd( control, (iONode)NodeOp.base.clone(cmd), NULL );

    ThreadOp.sleep( 100 );
    wOutput.setport( cmd, 1 );
    wOutput.setcmd( cmd, (tracknr&0x01) ? wOutput.on:wOutput.off );
    ControlOp.cmd( control, (iONode)NodeOp.base.clone(cmd), NULL );
    wOutput.setport( cmd, 2 );
    wOutput.setcmd( cmd, (tracknr&0x02) ? wOutput.on:wOutput.off );
    ControlOp.cmd( control, (iONode)NodeOp.base.clone(cmd), NULL );
    wOutput.setport( cmd, 3 );
    wOutput.setcmd( cmd, (tracknr&0x04) ? wOutput.on:wOutput.off );
    ControlOp.cmd( control, (iONode)NodeOp.base.clone(cmd), NULL );
    wOutput.setport( cmd, 4 );
    wOutput.setcmd( cmd, (tracknr&0x08) ? wOutput.on:wOutput.off );
    ControlOp.cmd( control, (iONode)NodeOp.base.clone(cmd), NULL );
    wOutput.setport( cmd, 5 );
    wOutput.setcmd( cmd, (tracknr&0x10) ? wOutput.on:wOutput.off );
    ControlOp.cmd( control, (iONode)NodeOp.base.clone(cmd), NULL );
    wOutput.setport( cmd, 6 );
    wOutput.setcmd( cmd, (tracknr&0x20) ? wOutput.on:wOutput.off );
    ControlOp.cmd( control, (iONode)NodeOp.base.clone(cmd), NULL );

    ThreadOp.sleep( 100 );
    data->pending = True;
    wOutput.setport( cmd, 8 );
    wOutput.setcmd( cmd, wOutput.on );
    ControlOp.cmd( control, cmd, NULL );

    /* ToDo: Get reported position. */
    wTurntable.setbridgepos( data->props, tracknr );

  }

  /* Cleanup Node1 */
  nodeA->base.del(nodeA);
  return ok;
}



/** TTDEC
 * function offset  red      green
 * -------- ------- -------- --------
 * End/Input  0     End      Input
 * Clear/Turn 1     Clear    Turn
 * Step       2     right    left
 * dir        3     CW       CCW
 * pos        4     #1       #2
 * pos        5     #3       #4
 * pos        6     #5       #6
 * pos        7     #7       #8
 * pos        8     #9       #10
 * pos        9     #11      #12
 * pos       10     #13      #14
 * pos       11     #15      #16
 * pos       12     #17      #18
 * pos       13     #19      #20
 * pos       14     #21      #22
 * pos       15     #23      #24
 */
static const int TTDEC_STEP = 2;
static const int TTDEC_TURN = 1;
static const int TTDEC_DIR  = 3;
static const int TTDEC_POS  = 4;
static const char* TTDEC_DIR_CW  = "straight";
static const char* TTDEC_DIR_CCW = "turnout";

static Boolean __cmd_ttdec( iOTT inst, iONode nodeA ) {
  iOTTData data = Data(inst);
  Boolean ok = True;
  iOControl control = AppOp.getControl();
  const char* cmdStr = wTurntable.getcmd( nodeA );
  Boolean ttdir = True;
  Boolean doDirCmd = False;
  int port = 0;
  const char* cmdstr = NULL;
  Boolean inv = wSwitch.isinv( data->props );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "TT command = [%s]", cmdStr );
  if( StrOp.equals( wTurntable.next, cmdStr ) ) {
    port = TTDEC_STEP;
    cmdstr = inv?wSwitch.turnout:wSwitch.straight;
    data->pending = True;
    /* set gotopos for next track */
    data->gotopos = __getNextTrack(inst, wTurntable.getbridgepos( data->props));
  }
  else if( StrOp.equals( wTurntable.prev, cmdStr ) ) {
    port = TTDEC_STEP;
    cmdstr = inv?wSwitch.straight:wSwitch.turnout;
    data->pending = True;
    /* set gotopos for previous track */
    data->gotopos = __getPrevTrack(inst, wTurntable.getbridgepos( data->props));
  }
  else if( StrOp.equals( wTurntable.turn180, cmdStr ) ) {
    port = TTDEC_TURN;
    cmdstr = inv?wSwitch.turnout:wSwitch.straight;
    data->gotopos = __getOppositeTrackNr(data->tablepos);
    data->pending = True;
  }
  else if( StrOp.equals( wTurntable.calibrate, cmdStr ) ) {
  }
  else if( StrOp.equals( wTurntable.lighton, cmdStr ) ) {
  }
  else if( StrOp.equals( wTurntable.lightoff, cmdStr ) ) {
  }
  else if( StrOp.equals(wTurntable.fon, cmdStr ) || StrOp.equals( wTurntable.foff, cmdStr )) {
  }
  else {
    /* Tracknumber */
    int tracknr = atoi( cmdStr );
    /* DA Save tracknumber for 180 degrees turn */
    int orig_tracknr = tracknr;

    Boolean move = __bridgeDir(inst, tracknr, &ttdir, wTurntable.iscmdbyroute(nodeA) );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "Goto track %d, current pos=%d", tracknr, data->tablepos );

    if( move ) {
      /* check for a mapping of the track number */
      data->gotopos = tracknr;
      tracknr = __getMappedTrack( inst, tracknr );

      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Goto decoder track [%d] in direction [%s]", tracknr, ttdir ? "CCW":"CW" );
      data->pending = True;

      doDirCmd = True;

      port = TTDEC_POS + ((tracknr-1)/2);
      if( (tracknr-1) % 2 == 0 )
        cmdstr = inv?wSwitch.straight:wSwitch.turnout;
      else
        cmdstr = inv?wSwitch.turnout:wSwitch.straight;

      /* DA check whether 180 degrees turn is required */
      if( (data->tablepos-orig_tracknr) == 24)
      {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
            "Turn 180 ---> Goto track [%d], current pos=[%d]", tracknr, data->tablepos );
        port   = TTDEC_TURN;
        cmdstr = inv?wSwitch.turnout:wSwitch.straight;
      }
      else if( (data->tablepos-orig_tracknr) == -24)
      {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
            "Turn 180 ---> Goto track [%d], current pos=[%d]", tracknr, data->tablepos );
        port   = TTDEC_TURN;
        cmdstr = inv?wSwitch.turnout:wSwitch.straight;
      }
      /* DA check whether 180 degrees turn is required */

    }
    else {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "bridge already at track %d", tracknr );
      __polarize((obj)inst, tracknr, False);
    }
  }

  /* Broadcast to clients. */
  if (port == TTDEC_STEP || port >= TTDEC_POS)
  {
    iONode track = wTurntable.gettrack( data->props );
    while ( track != NULL ) {
      if  ( wTTTrack.getnr( track ) == data->gotopos){
        if ( (( wTTTrack.getposfb( track) == NULL) || StrOp.equals( wTTTrack.getposfb( track), "\0"))
        && (( wTurntable.getpsen( data->props ) == NULL) || StrOp.equals( wTurntable.getpsen( data->props ), "\0")))
        {
          /* Only if no fb for track or position reached is defined */
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "draw bridge position %d", data->gotopos );
          iONode event = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
          wTurntable.setid( event, wTurntable.getid( data->props ) );
          wTurntable.setbridgepos( event, data->gotopos );
          if( data->lockedId != NULL )
            wTurntable.setlocid( event, data->lockedId );
          if( wTurntable.getiid( data->props ) != NULL )
            wTurntable.setiid( event, wTurntable.getiid( data->props ) );
          AppOp.broadcastEvent( event );
        }
        else
        {
          /* Delete position if fb for track or bridge in position available to improve visual feedback on display*/
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "position deleted waiting for fb event" );
          iONode event = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
          wTurntable.setid( event, wTurntable.getid( data->props ) );
          wTurntable.setbridgepos( event, -1 );
          if( data->lockedId != NULL )
            wTurntable.setlocid( event, data->lockedId );
          if( wTurntable.getiid( data->props ) != NULL )
            wTurntable.setiid( event, wTurntable.getiid( data->props ) );
          AppOp.broadcastEvent( event );
        }
      }
      track = wTurntable.nexttrack( data->props, track );
    }
  }


  if( cmdstr != NULL && control != NULL )
  {
    /* Direction */
    if( doDirCmd ) {
      iONode cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );

      int addr = wTurntable.getaddr( data->props );
      const char* iid = wTurntable.getiid( data->props );
      if( iid != NULL )
        wSwitch.setiid( cmd, iid );

      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "set direction address=%d, port=%d, gate=%s",
          addr, TTDEC_DIR, ttdir ? TTDEC_DIR_CCW:TTDEC_DIR_CW );
      int addrCmd = (addr-1 + TTDEC_DIR) / 4 + 1; /*address bug correction */
      int portCmd = (addr-1 + TTDEC_DIR) % 4 + 1; /*address bug correction */
      wSwitch.setaddr1( cmd, addrCmd );
      wSwitch.setport1( cmd, portCmd );
      wSwitch.setcmd  ( cmd, ttdir ? TTDEC_DIR_CCW:TTDEC_DIR_CW );
      wSwitch.setprot( cmd, wTurntable.getprot( data->props ) );

      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "sending switch command [%d,%d,%s]...",
                   addrCmd, portCmd, ttdir ? TTDEC_DIR_CCW:TTDEC_DIR_CW);

      ControlOp.cmd( control, cmd, NULL );
      /* give the decoder some time to think... */
      ThreadOp.sleep( wTurntable.getpause( data->props ) * 1000 );
    }


    /* Command */
    iONode cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );

    int addr = wTurntable.getaddr( data->props );
    const char* iid = wTurntable.getiid( data->props );
    if( iid != NULL )
      wSwitch.setiid( cmd, iid );


    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "set position address=%d, port=%d, gate=%s",
        addr, port, cmdstr );

    int addrCmd = (addr-1 + port) / 4 + 1; /*address bug correction */
    int portCmd = (addr-1 + port) % 4 + 1; /*address bug correction */
    wSwitch.setaddr1( cmd, addrCmd );
    wSwitch.setport1( cmd, portCmd );
    wSwitch.setcmd  ( cmd, cmdstr );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "sending switch command [%d,%d]...", addrCmd, portCmd );

    wSwitch.setprot( cmd, wTurntable.getprot( data->props ) );
    ControlOp.cmd( control, cmd, NULL );
    /* give the decoder some time to think... */
    ThreadOp.sleep(100);

    /* set tablepos optimistic predicted, if fb is not defined for destination track */
    iONode track = wTurntable.gettrack( data->props );
    while ( track != NULL ) {
      if ( ( wTTTrack.getnr( track ) == data->gotopos)
        && ( ( wTTTrack.getposfb( track) == NULL) || StrOp.equals( wTTTrack.getposfb( track), "\0"))) {

        data->tablepos = data->gotopos; /* lines switched in order to get correct trace */
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "set optimistic tablepos %d", data->tablepos ); /* lines switched in order to get correct trace */

        wTurntable.setbridgepos( data->props, data->tablepos );
      }
      track = wTurntable.nexttrack( data->props, track );
    }
  }
  else {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "no command sent" );
  }


  /* Cleanup Node1 */
  nodeA->base.del(nodeA);
  return ok;
}



static Boolean __cmd_multiport( iOTT inst, iONode nodeA ) {
  iOTTData data = Data(inst);
  Boolean ok = True;
  iOControl control = AppOp.getControl();
  const char* cmdStr = wTurntable.getcmd( nodeA );
  Boolean ttdir = True;
  iONode cmd = NULL;
  int tracknr = 0;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "%s", cmdStr );

  if( StrOp.equals( wTurntable.next, cmdStr ) ) {
    tracknr = __getNextTrack(inst, data->tablepos );
    if( tracknr != -1 ) {
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      data->gotopos = tracknr;
      data->skippos = -1;
    }
  }
  else if( StrOp.equals( wTurntable.prev, cmdStr ) ) {
    tracknr = __getPrevTrack(inst, data->tablepos );
    if( tracknr != -1 ) {
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      data->gotopos = tracknr;
      data->skippos = -1;
    }
  }
  else if( StrOp.equals( wTurntable.turn180, cmdStr ) ) {
    cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    tracknr = __getOppositeTrack( inst, data->tablepos );

    if( tracknr == -1 ) {
      data->gotopos = __getOppositeTrackNr(data->tablepos);
      tracknr = data->gotopos;
    }
    else {
      data->gotopos = tracknr;
    }
    data->skippos = -1;
  }
  else if( StrOp.equals( wTurntable.calibrate, cmdStr ) ) {
    tracknr = 0x3F;
    cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
  }
  else if( StrOp.equals( wTurntable.lighton, cmdStr ) ) {
  }
  else if( StrOp.equals( wTurntable.lightoff, cmdStr ) ) {
  }
  else if( StrOp.equals(wTurntable.fon, cmdStr ) || StrOp.equals( wTurntable.foff, cmdStr )) {
  }
  else {
    /* Tracknumber */
    tracknr = atoi( cmdStr );
    Boolean move = __bridgeDir(inst, tracknr, &ttdir, wTurntable.iscmdbyroute(nodeA) );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "Goto track %d, current pos=%d", tracknr, data->tablepos );

    if( move ) {
      data->gotopos = tracknr;
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    }
    else {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "bridge already at track %d", tracknr );
      __polarize((obj)inst, tracknr, False);
    }

  }

  if( cmd != NULL && control != NULL )
  {
    const char* iid = wTurntable.getiid( data->props );
    if( iid != NULL )
      wTurntable.setiid( cmd, iid );

    tracknr = __getMappedTrack( inst, tracknr );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "goto track[%d], mapped=[%d]", data->gotopos, tracknr );

    /* pending move operation */
    data->pending = True;

    if( StrOp.equals( wTurntable.prot_MP, wTurntable.getprot(data->props) ) ) {
      Boolean ttdir = True;
      Boolean move = __bridgeDir(inst, tracknr, &ttdir, wTurntable.iscmdbyroute(nodeA) );
      /* rename node to program */
      NodeOp.setName( cmd, wProgram.name() );
      /* set type to multiport */
      wProgram.setiid( cmd, wTurntable.getiid(data->props) );
      wProgram.setlntype( cmd, wProgram.lntype_mp );
      wProgram.setcmd( cmd, wProgram.lncvset );
      wProgram.setaddr( cmd, wTurntable.getaddr0(data->props) );
      wProgram.setmodid( cmd, wTurntable.getaddr1(data->props) );
      wProgram.setcv( cmd, 0x000F ); /* mask */
      wProgram.setvalue( cmd, tracknr ); /* value */
      wProgram.setval1( cmd, ttdir?1:2 ); /* direction */
      ControlOp.cmd( control, cmd, NULL );

    }
    else {
      iONode lcmd = NULL;
      Boolean invpos = wTurntable.isinvpos(data->props);
      Boolean invnew = wTurntable.isinvnew(data->props);

      NodeOp.setName( cmd, wSwitch.name() );

      wSwitch.setiid( cmd, wTurntable.getiid(data->props) );
      wSwitch.setbus( cmd, wTurntable.getbus(data->props) );
      /* set the protocol */
      wSwitch.setprot( cmd, wTurntable.getprot(data->props) );
      wSwitch.setsinglegate( cmd, wTurntable.issinglegatepos(data->props) );

      /* signal new position will be set: */
      wSwitch.setaddr1( cmd, wTurntable.getaddr5(data->props) );
      wSwitch.setport1( cmd, wTurntable.getport5(data->props) );
      wSwitch.setcmd( cmd, invnew ? wSwitch.straight:wSwitch.turnout );
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "reset position flag %d:%d:%d %s",
          wSwitch.getbus(cmd), wSwitch.getaddr1(cmd), wSwitch.getport1(data->props), wSwitch.getcmd(cmd) );
      lcmd = (iONode)NodeOp.base.clone(cmd);
      ControlOp.cmd( control, lcmd, NULL );
      ThreadOp.sleep(10);

      wSwitch.setaddr1( cmd, wTurntable.getaddr0(data->props) );
      wSwitch.setport1( cmd, wTurntable.getport0(data->props) );
      if( invpos )
        wSwitch.setcmd( cmd, tracknr & 0x01 ? wSwitch.straight:wSwitch.turnout );
      else
        wSwitch.setcmd( cmd, tracknr & 0x01 ? wSwitch.turnout:wSwitch.straight );
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "position 0 %d:%d:%d %s",
          wSwitch.getbus(cmd), wSwitch.getaddr1(cmd), wSwitch.getport1(data->props), wSwitch.getcmd(cmd) );
      lcmd = (iONode)NodeOp.base.clone(cmd);
      ControlOp.cmd( control, lcmd, NULL );
      ThreadOp.sleep(10);

      wSwitch.setaddr1( cmd, wTurntable.getaddr1(data->props) );
      wSwitch.setport1( cmd, wTurntable.getport1(data->props) );
      if( invpos )
        wSwitch.setcmd( cmd, tracknr & 0x02 ? wSwitch.straight:wSwitch.turnout );
      else
        wSwitch.setcmd( cmd, tracknr & 0x02 ? wSwitch.turnout:wSwitch.straight );
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "position 1 %d:%d:%d %s",
          wSwitch.getbus(cmd), wSwitch.getaddr1(cmd), wSwitch.getport1(data->props), wSwitch.getcmd(cmd) );
      lcmd = (iONode)NodeOp.base.clone(cmd);
      ControlOp.cmd( control, lcmd, NULL );
      ThreadOp.sleep(10);

      wSwitch.setaddr1( cmd, wTurntable.getaddr2(data->props) );
      wSwitch.setport1( cmd, wTurntable.getport2(data->props) );
      if( invpos )
        wSwitch.setcmd( cmd, tracknr & 0x04 ? wSwitch.straight:wSwitch.turnout );
      else
        wSwitch.setcmd( cmd, tracknr & 0x04 ? wSwitch.turnout:wSwitch.straight );
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "position 2 %d:%d:%d %s",
          wSwitch.getbus(cmd), wSwitch.getaddr1(cmd), wSwitch.getport1(data->props), wSwitch.getcmd(cmd) );
      lcmd = (iONode)NodeOp.base.clone(cmd);
      ControlOp.cmd( control, lcmd, NULL );
      ThreadOp.sleep(10);

      wSwitch.setaddr1( cmd, wTurntable.getaddr3(data->props) );
      wSwitch.setport1( cmd, wTurntable.getport3(data->props) );
      if( invpos )
        wSwitch.setcmd( cmd, tracknr & 0x08 ? wSwitch.straight:wSwitch.turnout );
      else
        wSwitch.setcmd( cmd, tracknr & 0x08 ? wSwitch.turnout:wSwitch.straight );
      lcmd = (iONode)NodeOp.base.clone(cmd);
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "position 3 %d:%d:%d %s",
          wSwitch.getbus(cmd), wSwitch.getaddr1(cmd), wSwitch.getport1(data->props), wSwitch.getcmd(cmd) );
      ControlOp.cmd( control, lcmd, NULL );
      ThreadOp.sleep(10);

      wSwitch.setaddr1( cmd, wTurntable.getaddr4(data->props) );
      wSwitch.setport1( cmd, wTurntable.getport4(data->props) );
      if( invpos )
        wSwitch.setcmd( cmd, tracknr & 0x10 ? wSwitch.straight:wSwitch.turnout );
      else
        wSwitch.setcmd( cmd, tracknr & 0x10 ? wSwitch.turnout:wSwitch.straight );
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "position 4 %d:%d:%d %s",
          wSwitch.getbus(cmd), wSwitch.getaddr1(cmd), wSwitch.getport1(data->props), wSwitch.getcmd(cmd) );
      lcmd = (iONode)NodeOp.base.clone(cmd);
      ControlOp.cmd( control, lcmd, NULL );
      ThreadOp.sleep(10);

      if( wTurntable.getaddr6(data->props) > 0 || wTurntable.getport6(data->props) > 0 ) {
        wSwitch.setaddr1( cmd, wTurntable.getaddr6(data->props) );
        wSwitch.setport1( cmd, wTurntable.getport6(data->props) );
        if( invpos )
          wSwitch.setcmd( cmd, tracknr & 0x20 ? wSwitch.straight:wSwitch.turnout );
        else
          wSwitch.setcmd( cmd, tracknr & 0x20 ? wSwitch.turnout:wSwitch.straight );
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "position 5 %d:%d:%d %s",
            wSwitch.getbus(cmd), wSwitch.getaddr1(cmd), wSwitch.getport1(data->props), wSwitch.getcmd(cmd) );
        lcmd = (iONode)NodeOp.base.clone(cmd);
        ControlOp.cmd( control, lcmd, NULL );
        ThreadOp.sleep(10);
      }

      /* signal new position is set: */
      wSwitch.setaddr1( cmd, wTurntable.getaddr5(data->props) );
      wSwitch.setport1( cmd, wTurntable.getport5(data->props) );
      wSwitch.setsinglegate( cmd, wTurntable.issinglegatenew(data->props) );
      wOutput.setcmd( cmd, invnew ? wSwitch.turnout:wSwitch.straight );
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "set position flag %d:%d:%d %s",
          wSwitch.getbus(cmd), wSwitch.getaddr1(cmd), wSwitch.getport1(data->props), wSwitch.getcmd(cmd) );
      lcmd = (iONode)NodeOp.base.clone(cmd);
      ControlOp.cmd( control, lcmd, NULL );
      ThreadOp.sleep(10);

    }

    data->dir = ttdir;
  }



  /* Cleanup Node1 */
  nodeA->base.del(nodeA);


  return ok;
}


static Boolean __cmd_f6915( iOTT inst, iONode nodeA ) {
  iOTTData data = Data(inst);
  Boolean ok = True;
  iOControl control = AppOp.getControl();
  const char* cmdStr = wTurntable.getcmd( nodeA );
  Boolean ttdir = True;
  iONode cmd = NULL;
  int tracknr = 0;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "%s", cmdStr );

  if( StrOp.equals( wTurntable.next, cmdStr ) ) {
    tracknr = __getNextTrack(inst, data->tablepos );
    if( tracknr != -1 ) {
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      data->gotopos = tracknr;
      data->skippos = -1;
    }
  }
  else if( StrOp.equals( wTurntable.prev, cmdStr ) ) {
    tracknr = __getPrevTrack(inst, data->tablepos );
    if( tracknr != -1 ) {
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      data->gotopos = tracknr;
      data->skippos = -1;
    }
  }
  else if( StrOp.equals( wTurntable.turn180, cmdStr ) ) {
    cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    tracknr = __getOppositeTrack( inst, data->tablepos );

    if( tracknr == -1 ) {
      data->gotopos = __getOppositeTrackNr(data->tablepos);
      tracknr = data->gotopos;
    }
    else {
      data->gotopos = tracknr;
    }
    data->skippos = -1;
  }
  else if( StrOp.equals( wTurntable.calibrate, cmdStr ) ) {
  }
  else if( StrOp.equals( wTurntable.lighton, cmdStr ) ) {
  }
  else if( StrOp.equals( wTurntable.lightoff, cmdStr ) ) {
  }
  else if( StrOp.equals(wTurntable.fon, cmdStr ) || StrOp.equals( wTurntable.foff, cmdStr )) {
  }
  else {
    /* Tracknumber */
    tracknr = atoi( cmdStr );
    Boolean move = __bridgeDir(inst, tracknr, &ttdir, wTurntable.iscmdbyroute(nodeA) );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "Goto track %d, current pos=%d", tracknr, data->tablepos );

    if( move ) {
      data->gotopos = tracknr;
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    }

  }

  if( cmd != NULL && control != NULL )
  {
    int rrtracknr = tracknr;
    const char* iid = wTurntable.getiid( data->props );
    if( iid != NULL )
      wTurntable.setiid( cmd, iid );

    tracknr = __getMappedTrack( inst, tracknr );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "goto track[%d], mapped=[%d]", data->gotopos, tracknr );

    /* pending move operation */
    data->pending = True;

    /* Broadcast to clients. */
    {
      iONode event = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
      wTurntable.setid( event, wTurntable.getid( data->props ) );
      wTurntable.setbridgepos( event, rrtracknr );
      wTurntable.setstate1( event, wTurntable.isstate1(data->props) );
      wTurntable.setstate2( event, wTurntable.isstate2(data->props) );
      if( data->lockedId != NULL )
        wTurntable.setlocid( event, data->lockedId );
      if( wTurntable.getiid( data->props ) != NULL )
        wTurntable.setiid( event, wTurntable.getiid( data->props ) );
      AppOp.broadcastEvent( event );
    }


    /* set the protocol */
    wSwitch.setprot( cmd, wTurntable.getprot(data->props) );
    wSwitch.setport1( cmd, tracknr );
    wOutput.setcmd( cmd, wSwitch.turnout ); /* the 'red' command moves the hut side to this position */
    ControlOp.cmd( control, cmd, NULL );

    /* no feedback for 'position reached' so set it as reached */
    data->tablepos = data->gotopos;

    /* bridge is in position */
    data->pending = False;
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "bridge at position pos=%d ", data->tablepos );
    wTurntable.setbridgepos( data->props, data->tablepos );

    if( wTurntable.getdelay( data->props) > 0 ) {
      data->delaytick = SystemOp.getTick();
    }
    else {
      data->delaytick = 0;
    }
  }


  /* Cleanup Node1 */
  nodeA->base.del(nodeA);


  return ok;
}


static void __setLocDecFn( iONode cmd, int fn, Boolean state ) {
  char fStr[32];
  StrOp.fmtb( fStr, "f%d", fn );
  NodeOp.setBool( cmd, fStr, state );
}


/*
 * bit 1-5 bridge position (0-31) 0x1F
 * bit 6 opposite position        0x20
 * bit 7/8 step to right/left     0x40/0x80
 *
 * the command type is wProgram.lntype_mp which must be implemented in the slx library(ies)
 */
static Boolean __cmd_muet( iOTT inst, iONode nodeA ) {
  iOTTData data = Data(inst);
  Boolean ok = True;
  iOControl control = AppOp.getControl();
  const char* cmdStr = wTurntable.getcmd( nodeA );
  Boolean ttdir = True;
  iONode cmd = NULL;
  int tracknr = 0;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "%s", cmdStr );

  if( StrOp.equals( wTurntable.next, cmdStr ) ) {
    tracknr = __getNextTrack(inst, data->tablepos );
    if( tracknr != -1 ) {
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      data->gotopos = tracknr;
      data->skippos = -1;
    }
  }
  else if( StrOp.equals( wTurntable.prev, cmdStr ) ) {
    tracknr = __getPrevTrack(inst, data->tablepos );
    if( tracknr != -1 ) {
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      data->gotopos = tracknr;
      data->skippos = -1;
    }
  }
  else if( StrOp.equals( wTurntable.turn180, cmdStr ) ) {
    cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    tracknr = __getOppositeTrack( inst, data->tablepos );

    if( tracknr == -1 ) {
      data->gotopos = __getOppositeTrackNr(data->tablepos);
      tracknr = data->gotopos;
    }
    else {
      data->gotopos = tracknr;
    }
    data->skippos = -1;
  }
  else if( StrOp.equals( wTurntable.calibrate, cmdStr ) ) {
  }
  else if( StrOp.equals( wTurntable.lighton, cmdStr ) ) {
  }
  else if( StrOp.equals( wTurntable.lightoff, cmdStr ) ) {
  }
  else if( StrOp.equals(wTurntable.fon, cmdStr ) || StrOp.equals( wTurntable.foff, cmdStr )) {
  }
  else {
    /* Tracknumber */
    tracknr = atoi( cmdStr );
    Boolean move = __bridgeDir(inst, tracknr, &ttdir, wTurntable.iscmdbyroute(nodeA) );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "Goto track %d, current pos=%d", tracknr, data->tablepos );

    if( move ) {
      data->gotopos = tracknr;
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    }
    else {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "bridge already at track %d", tracknr );
      __polarize((obj)inst, tracknr, False);
    }

  }

  if( cmd != NULL && control != NULL )
  {
    const char* iid = wTurntable.getiid( data->props );
    if( iid != NULL )
      wTurntable.setiid( cmd, iid );

    tracknr = __getMappedTrack( inst, tracknr );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "goto track[%d], mapped=[%d]", data->gotopos, tracknr );

    /* pending move operation */
    data->pending = True;

    /* rename node to program */
    NodeOp.setName( cmd, wProgram.name() );
    /* set type to multiport */
    wProgram.setlntype( cmd, wProgram.lntype_mp );
    wProgram.setcmd( cmd, wProgram.lncvset );
    wProgram.setaddr( cmd, wTurntable.getaddr(data->props) );
    wProgram.setcv( cmd, 0x001F ); /* mask */
    wProgram.setvalue( cmd, tracknr ); /* value */
    ControlOp.cmd( control, cmd, NULL );


    data->dir = ttdir;

  }



  /* Cleanup Node1 */
  nodeA->base.del(nodeA);


  return ok;
}



/*
 * Bitwertigkeit 0-7, Rückmeldung an die Ansteueradresse.
 *
 * Bit 7 = Startbit: 0 = Ruhelage bzw. Nothalt, wenn gesetzt war. 1 = Start.
 * Bit 6 muss stets gesetzt sein. 0= Handsteuerung, 1= PC-Steuerung
 * Bit 0 bis 5: Drehposition 0 bis 47, entsprechend Wertigkeit. 00 0000 = Stellung 0, 10 1111 = Stellung 47
 * Nach Erreichen der Sollposition Rückmeldung der Istposition (= Sollposition) in Bit 0 bis 5 und Rücksetzen von Bit 7: 01xx xxxx
 * Abfrage der Drehposition: Drehposition 48 = 11 0000, Start durch Bit 7 = 1.
 * Rückmeldung. 01xx xxxx, wobei xx xxxx die Drehposition beinhaltet.
 *
 * the command type is wProgram.lntype_mp which must be implemented in the slx library(ies)
 */
static Boolean __cmd_slx815( iOTT inst, iONode nodeA ) {
  iOTTData data = Data(inst);
  Boolean ok = True;
  iOControl control = AppOp.getControl();
  const char* cmdStr = wTurntable.getcmd( nodeA );
  Boolean ttdir = True;
  iONode cmd = NULL;
  int tracknr = 0;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "%s", cmdStr );

  if( StrOp.equals( wTurntable.next, cmdStr ) ) {
    tracknr = __getNextTrack(inst, data->tablepos );
    if( tracknr != -1 ) {
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      data->gotopos = tracknr;
      data->skippos = -1;
    }
  }
  else if( StrOp.equals( wTurntable.prev, cmdStr ) ) {
    tracknr = __getPrevTrack(inst, data->tablepos );
    if( tracknr != -1 ) {
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      data->gotopos = tracknr;
      data->skippos = -1;
    }
  }
  else if( StrOp.equals( wTurntable.turn180, cmdStr ) ) {
    cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    tracknr = __getOppositeTrack( inst, data->tablepos );

    if( tracknr == -1 ) {
      data->gotopos = __getOppositeTrackNr(data->tablepos);
      tracknr = data->gotopos;
    }
    else {
      data->gotopos = tracknr;
    }
    data->skippos = -1;
  }
  else if( StrOp.equals( wTurntable.calibrate, cmdStr ) ) {
  }
  else if( StrOp.equals( wTurntable.lighton, cmdStr ) ) {
  }
  else if( StrOp.equals( wTurntable.lightoff, cmdStr ) ) {
  }
  else if( StrOp.equals(wTurntable.fon, cmdStr ) || StrOp.equals( wTurntable.foff, cmdStr )) {
  }
  else {
    /* Tracknumber */
    tracknr = atoi( cmdStr );
    Boolean move = __bridgeDir(inst, tracknr, &ttdir, wTurntable.iscmdbyroute(nodeA) );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "Goto track %d, current pos=%d", tracknr, data->tablepos );

    if( move ) {
      data->gotopos = tracknr;
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    }
    else {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "bridge already at track %d", tracknr );
      __polarize((obj)inst, tracknr, False);
    }

  }

  if( cmd != NULL && control != NULL )
  {
    const char* iid = wTurntable.getiid( data->props );
    if( iid != NULL )
      wTurntable.setiid( cmd, iid );

    tracknr = __getMappedTrack( inst, tracknr );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "goto track[%d], mapped=[%d]", data->gotopos, tracknr );

    /* pending move operation */
    data->pending = True;

    /* rename node to program */
    NodeOp.setName( cmd, wProgram.name() );
    /* set type to multiport */
    wProgram.setlntype( cmd, wProgram.lntype_mp );
    wProgram.setcmd( cmd, wProgram.lncvset );
    wProgram.setaddr( cmd, wTurntable.getaddr(data->props) );
    wProgram.setcv( cmd, 0x00FF ); /* mask */
    wProgram.setvalue( cmd, tracknr | 0xC0 ); /* value */
    ControlOp.cmd( control, cmd, NULL );


    data->dir = ttdir;

  }



  /* Cleanup Node1 */
  nodeA->base.del(nodeA);


  return ok;
}



static Boolean __cmd_accdec( iOTT inst, iONode nodeA ) {
  iOTTData data = Data(inst);
  Boolean ok = True;
  iOControl control = AppOp.getControl();
  const char* cmdStr = wTurntable.getcmd( nodeA );
  Boolean ttdir = True;
  iONode swcmd = NULL;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "accdec: %s", cmdStr );

  if( StrOp.equals( wTurntable.next, cmdStr ) ) {
    swcmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    ttdir = False;
    data->gotopos = -1;
    data->skippos = -1;
  }
  else if( StrOp.equals( wTurntable.prev, cmdStr ) ) {
    swcmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    ttdir = True;
    data->gotopos = -1;
    data->skippos = -1;
  }
  else if( StrOp.equals( wTurntable.turn180, cmdStr ) ) {
    swcmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    data->gotopos = __getOppositeTrackNr(data->tablepos);
    data->skippos = data->tablepos;
  }
  else if( StrOp.equals( wTurntable.calibrate, cmdStr ) ) {
  }
  else if( StrOp.equals( wTurntable.lighton, cmdStr ) ) {
  }
  else if( StrOp.equals( wTurntable.lightoff, cmdStr ) ) {
  }
  else if( StrOp.equals(wTurntable.fon, cmdStr ) || StrOp.equals( wTurntable.foff, cmdStr )) {
  }
  else {
    /* Tracknumber */
    int tracknr = atoi( cmdStr );
    Boolean move = __bridgeDir(inst, tracknr, &ttdir, wTurntable.iscmdbyroute(nodeA) );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "Goto track %d, current pos=%d direction=%s", tracknr, data->tablepos, ttdir?"CCW":"CW" );

    if( move ) {
      data->gotopos = tracknr;
      swcmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    }
    else {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "bridge already at track %d", tracknr );
      __polarize((obj)inst, tracknr, False);
    }


  }

  if( swcmd != NULL && control != NULL )
  {
    iONode dircmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    const char* iid = wTurntable.getiid( data->props );
    if( iid != NULL )
      wSwitch.setiid( swcmd, iid );

    /* pending move operation */
    data->pending = True;

    wSwitch.setaddr1( dircmd, wTurntable.getdiraddr( data->props ) );
    wSwitch.setprot( dircmd, wTurntable.getprot( data->props ) );
    wSwitch.setcmd( dircmd, ttdir? wSwitch.turnout:wSwitch.straight );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "accdec: set direction to %s...", ttdir?"turnout":"straight" );
    ControlOp.cmd( control, dircmd, NULL );
    data->dir = ttdir;

    wSwitch.setaddr1( swcmd, wTurntable.getaddr( data->props ) );
    wSwitch.setprot( swcmd, wTurntable.getprot( data->props ) );
    wSwitch.setcmd( swcmd, wSwitch.turnout );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "accdec: turn motor on..." );
    ControlOp.cmd( control, swcmd, NULL );

  }

  /* Cleanup Node1 */
  nodeA->base.del(nodeA);
  return ok;
}


static Boolean __cmd_d15( iOTT inst, iONode nodeA ) {
  iOTTData data = Data(inst);
  Boolean ok = True;
  iOControl control = AppOp.getControl();
  const char* cmdStr = wTurntable.getcmd( nodeA );
  Boolean ttdir = True;
  iONode cmd = NULL;
  int tracknr = 0;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "draai15: %s", cmdStr );

  if( StrOp.equals( wTurntable.next, cmdStr ) ) {
    tracknr = __getNextTrack(inst, data->tablepos );
    if( tracknr != -1 ) {
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      data->gotopos = tracknr;
      data->skippos = -1;
    }
  }
  else if( StrOp.equals( wTurntable.prev, cmdStr ) ) {
    tracknr = __getPrevTrack(inst, data->tablepos );
    if( tracknr != -1 ) {
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      data->gotopos = tracknr;
      data->skippos = -1;
    }
  }
  else if( StrOp.equals( wTurntable.turn180, cmdStr ) ) {
    /* turn command */
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "new position" );
    cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    wSwitch.setaddr1( cmd, wTurntable.getaddr5(data->props) );
    wSwitch.setport1( cmd, wTurntable.getport5(data->props) );
    wSwitch.setcmd  ( cmd, data->dir ? wSwitch.straight:wSwitch.turnout );
    wSwitch.setprot( cmd, wTurntable.getprot( data->props ) );
    ControlOp.cmd( control, cmd, NULL );
    ThreadOp.sleep(2000);
    cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    wSwitch.setaddr1( cmd, wTurntable.getaddr5(data->props) );
    wSwitch.setport1( cmd, wTurntable.getport5(data->props) );
    wSwitch.setcmd  ( cmd, data->dir ? wSwitch.straight:wSwitch.turnout );
    wSwitch.setprot( cmd, wTurntable.getprot( data->props ) );
    ControlOp.cmd( control, cmd, NULL );
    data->gotopos = __getOppositeTrackNr(data->tablepos);
    data->pending = True;
    cmd = NULL;
  }
  else if( StrOp.equals( wTurntable.calibrate, cmdStr ) ) {
  }
  else if( StrOp.equals( wTurntable.lighton, cmdStr ) ) {
  }
  else if( StrOp.equals( wTurntable.lightoff, cmdStr ) ) {
  }
  else if( StrOp.equals(wTurntable.fon, cmdStr ) || StrOp.equals( wTurntable.foff, cmdStr )) {
  }
  else {
    /* Tracknumber */
    tracknr = atoi( cmdStr );
    Boolean move = __bridgeDir(inst, tracknr, &ttdir, wTurntable.iscmdbyroute(nodeA) );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "Goto track %d, current pos=%d", tracknr, data->tablepos );

    if( move ) {
      data->gotopos = tracknr;
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    }
    else {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "bridge already at track %d", tracknr );
      __polarize((obj)inst, tracknr, False);
    }

  }

  if( cmd != NULL && control != NULL )
  {
    const char* iid = wTurntable.getiid( data->props );
    if( iid != NULL )
      wTurntable.setiid( cmd, iid );

    tracknr = __getMappedTrack( inst, tracknr );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "goto track[%d], mapped=[%d], mask=[0x%02X]", data->gotopos, tracknr, tracknr );

    /* pending move operation */
    data->pending = True;


    /* reset */
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "reset" );
    wSwitch.setaddr1( cmd, wTurntable.getresetaddr(data->props) );
    wSwitch.setport1( cmd, wTurntable.getresetport(data->props) );
    wSwitch.setcmd  ( cmd, wTurntable.getresetbitcmd(data->props) == 0 ? wSwitch.straight:wSwitch.turnout );
    wSwitch.setprot( cmd, wTurntable.getprot( data->props ) );
    ControlOp.cmd( control, cmd, NULL );
    ThreadOp.sleep( wTurntable.getmotoroffdelay( data->props ) );

    if( tracknr&0x01 ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "bit 0" );
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      wSwitch.setaddr1( cmd, wTurntable.getaddr0(data->props) );
      wSwitch.setport1( cmd, wTurntable.getport0(data->props) );
      wSwitch.setcmd  ( cmd, wTurntable.getbit0cmd(data->props) == 0 ? wSwitch.straight:wSwitch.turnout );
      wSwitch.setprot( cmd, wTurntable.getprot( data->props ) );
      ControlOp.cmd( control, cmd, NULL );
      ThreadOp.sleep( wTurntable.getmotoroffdelay( data->props ) );
    }

    if( tracknr&0x02 ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "bit 1" );
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      wSwitch.setaddr1( cmd, wTurntable.getaddr1(data->props) );
      wSwitch.setport1( cmd, wTurntable.getport1(data->props) );
      wSwitch.setcmd  ( cmd, wTurntable.getbit1cmd(data->props) == 0 ? wSwitch.straight:wSwitch.turnout );
      wSwitch.setprot( cmd, wTurntable.getprot( data->props ) );
      ControlOp.cmd( control, cmd, NULL );
      ThreadOp.sleep( wTurntable.getmotoroffdelay( data->props ) );
    }

    if( tracknr&0x04 ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "bit 2" );
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      wSwitch.setaddr1( cmd, wTurntable.getaddr2(data->props) );
      wSwitch.setport1( cmd, wTurntable.getport2(data->props) );
      wSwitch.setcmd  ( cmd, wTurntable.getbit2cmd(data->props) == 0 ? wSwitch.straight:wSwitch.turnout );
      wSwitch.setprot( cmd, wTurntable.getprot( data->props ) );
      ControlOp.cmd( control, cmd, NULL );
      ThreadOp.sleep( wTurntable.getmotoroffdelay( data->props ) );
    }

    if( tracknr&0x08 ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "bit 3" );
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      wSwitch.setaddr1( cmd, wTurntable.getaddr3(data->props) );
      wSwitch.setport1( cmd, wTurntable.getport3(data->props) );
      wSwitch.setcmd  ( cmd, wTurntable.getbit3cmd(data->props) == 0 ? wSwitch.straight:wSwitch.turnout );
      wSwitch.setprot( cmd, wTurntable.getprot( data->props ) );
      ControlOp.cmd( control, cmd, NULL );
      ThreadOp.sleep( wTurntable.getmotoroffdelay( data->props ) );
    }

    /* turn command */
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "new position" );
    cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    wSwitch.setaddr1( cmd, wTurntable.getaddr5(data->props) );
    wSwitch.setport1( cmd, wTurntable.getport5(data->props) );
    wSwitch.setcmd  ( cmd,ttdir ? wSwitch.straight:wSwitch.turnout );
    wSwitch.setprot( cmd, wTurntable.getprot( data->props ) );
    ControlOp.cmd( control, cmd, NULL );

    data->dir = ttdir;

  }



  /* Cleanup Node1 */
  nodeA->base.del(nodeA);


  return ok;
}


static Boolean __cmd_locdec( iOTT inst, iONode nodeA ) {
  iOTTData data = Data(inst);
  Boolean ok = True;
  iOControl control = AppOp.getControl();
  const char* cmdStr = wTurntable.getcmd( nodeA );
  Boolean ttdir = True;
  iONode vcmd = NULL;
  int tracknr = 0;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "locdec: %s", cmdStr );

  if( StrOp.equals( wTurntable.next, cmdStr ) ) {
    vcmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    ttdir = False;
    data->gotopos = -1;
    data->skippos = -1;
  }
  else if( StrOp.equals( wTurntable.prev, cmdStr ) ) {
    vcmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    ttdir = True;
    data->gotopos = -1;
    data->skippos = -1;
  }
  else if( StrOp.equals( wTurntable.turn180, cmdStr ) ) {
    vcmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    data->gotopos = __getOppositeTrackNr(data->tablepos);
    data->skippos = data->tablepos;
  }
  else if( StrOp.equals( wTurntable.calibrate, cmdStr ) ) {
  }
  else if( StrOp.equals( wTurntable.lighton, cmdStr ) ) {
    int f = wTurntable.getlightsfn( data->props );
    iONode fcmd = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE );
    if( wTurntable.getiid(data->props) != NULL )
      wTurntable.setiid( fcmd, wTurntable.getiid(data->props) );
    wFunCmd.setid( fcmd, wTurntable.getid( data->props ) );
    wFunCmd.setaddr( fcmd, wTurntable.getaddr( data->props ) );
    wFunCmd.setfnchanged( fcmd, f);
    data->f[f] = True;
    __cpFn2Node( (iOTT)inst, fcmd );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "turn lights on");
    ControlOp.cmd( control, fcmd, NULL );
    return ok;
  }
  else if( StrOp.equals( wTurntable.lightoff, cmdStr ) ) {
    int f = wTurntable.getlightsfn( data->props );
    iONode fcmd = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE );
    if( wTurntable.getiid(data->props) != NULL )
      wTurntable.setiid( fcmd, wTurntable.getiid(data->props) );
    wFunCmd.setid( fcmd, wTurntable.getid( data->props ) );
    wFunCmd.setaddr( fcmd, wTurntable.getaddr( data->props ) );
    wFunCmd.setfnchanged( fcmd, f);
    data->f[f] = False;
    __cpFn2Node( (iOTT)inst, fcmd );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "turn lights off");
    ControlOp.cmd( control, fcmd, NULL );
    return ok;
  }
  else if( StrOp.equals(wTurntable.fon, cmdStr ) || StrOp.equals( wTurntable.foff, cmdStr )) {
    int f = wTurntable.getfun(nodeA);
    iONode fcmd = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE );
    if( wTurntable.getiid(data->props) != NULL )
      wTurntable.setiid( fcmd, wTurntable.getiid(data->props) );
    wFunCmd.setid( fcmd, wTurntable.getid( data->props ) );
    wFunCmd.setaddr( fcmd, wTurntable.getaddr( data->props ) );
    wFunCmd.setfnchanged( fcmd, f);
    data->f[f] = StrOp.equals( wTurntable.getcmd(nodeA), wTurntable.fon );
    __cpFn2Node( (iOTT)inst, fcmd );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "turn function %d %s", f, StrOp.equals( wTurntable.getcmd(nodeA), wAction.fun_on )?"on":"off" );
    ControlOp.cmd( control, fcmd, NULL );
    return ok;
  }
  else {
    /* Tracknumber */
    int tracknr = atoi( cmdStr );
    Boolean move = __bridgeDir(inst, tracknr, &ttdir, wTurntable.iscmdbyroute(nodeA) );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "Goto track %d, current pos=%d", tracknr, data->tablepos );

    if( move ) {
      data->gotopos = tracknr;
      vcmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    }
    else {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "bridge already at track %d", tracknr );
      __polarize((obj)inst, tracknr, False);
    }


  }

  if( vcmd != NULL && control != NULL )
  {
    const char* iid = wTurntable.getiid( data->props );
    if( iid != NULL )
      wTurntable.setiid( vcmd, iid );

    /* pending move operation */
    data->pending = True;

    wLoc.setid( vcmd, wTurntable.getid( data->props ) );
    wLoc.setaddr( vcmd, wTurntable.getaddr( data->props ) );

    /* Using the Loc wrapper for the other parameters: */
    wLoc.setV_mode( vcmd, wLoc.V_mode_percent );
    wLoc.setV( vcmd, wTurntable.getV( data->props ) );
    wLoc.setprot( vcmd, wTurntable.getprot( data->props ) );
    wLoc.setfn( vcmd, wTurntable.getactfn( data->props ) == 0 ? True:False );
    wLoc.setdir( vcmd, ttdir );
    data->dir = ttdir;

    ControlOp.cmd( control, vcmd, NULL );

    if(wTurntable.getactfn( data->props ) > 0) {
      iONode fcmd = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE );
      if( iid != NULL )
        wTurntable.setiid( fcmd, iid );
      wFunCmd.setid( fcmd, wTurntable.getid( data->props ) );
      wFunCmd.setaddr( fcmd, wTurntable.getaddr( data->props ) );
      wFunCmd.setfnchanged( fcmd, wTurntable.getactfn( data->props ));
      data->f[wTurntable.getactfn( data->props )] = True;
      __cpFn2Node( inst, fcmd );

      wLoc.setV_mode( fcmd, wLoc.V_mode_percent );
      wLoc.setV( fcmd, wTurntable.getV( data->props ) );
      wLoc.setprot( fcmd, wTurntable.getprot( data->props ) );
      wLoc.setfn( fcmd, wTurntable.getactfn( data->props ) == 0 ? True:False );
      wLoc.setdir( fcmd, ttdir );

      ControlOp.cmd( control, fcmd, NULL );
    }

  }



  /* Cleanup Node1 */
  nodeA->base.del(nodeA);
  return ok;
}


static Boolean _setListener( iOTT inst, obj listenerObj, const tt_listener listenerFun ) {
  iOTTData data = Data(inst);
  data->listenerObj = listenerObj;
  data->listenerFun = listenerFun;
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "%s listener set for %s",
    inst->base.id( inst ),
    listenerObj->toString(listenerObj) );
  return True;
}

static void __cpFn2Node( iOTT inst, iONode fcmd ) {
  iOTTData data = Data(inst);
  int i = 0;
  for( i = 0; i < 28; i++ ) {
    __setLocDecFn( fcmd, i, data->f[i] );
  }
}


static Boolean _cmd( iIBlockBase inst, iONode nodeA ) {
  iOTTData data = Data(inst);
  iOModel model = AppOp.getModel();
  iOControl control = AppOp.getControl();

  const char* locid = wTurntable.getlocid( nodeA );
  const char* state = wTurntable.getstate( nodeA );


  if( wTurntable.isembeddedblock(data->props) ) {
    if( locid != NULL ) {
      if( StrOp.len(locid) == 0 && data->lockedId != NULL && StrOp.len(data->lockedId) > 0 ) {
        /* inform loc */
        iOLoc loc = ModelOp.getLoc( model, data->lockedId, NULL, False );
        if( loc != NULL ) {
          LocOp.setCurBlock( loc, NULL );
        }
      }
      wTurntable.setlocid( data->props, locid );
      ModelOp.setBlockOccupancy( AppOp.getModel(), wTurntable.getid(data->props), locid, False, 0, 0, NULL );
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
          "%s locid=%s", NodeOp.getStr( data->props, "id", "" ), locid );

    }

    if( state != NULL ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "set state to [%s]", state);
      wTurntable.setstate( data->props, state );
    }

    /* Broadcast to clients. */
    NodeOp.setName(nodeA, wTurntable.name());
    if( data->lockedId != NULL )
      wTurntable.setlocid( nodeA, data->lockedId );
    AppOp.broadcastEvent( (iONode)NodeOp.base.clone(nodeA) );
  }


  if( wTurntable.getcmd(nodeA) == NULL ) {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "command not set");
    NodeOp.base.del(nodeA);
    return False;
  }

  if( atoi(wTurntable.getcmd( nodeA )) > 0 || StrOp.equals( wTurntable.getcmd(nodeA), "0" ) ) {
    if( atoi(wTurntable.getcmd( nodeA )) == 180 ) {
      wTurntable.setcmd( nodeA, wTurntable.turn180 );
      __checkAction( (iOTT)inst, wTurntable.turn180);
    }
    else {
      char l_cmd[64] = {'\0'};
      __checkAction( (iOTT)inst, "goto");
      StrOp.fmtb( l_cmd, "goto %s", wTurntable.getcmd( nodeA ) );
      __checkAction( (iOTT)inst, l_cmd);
    }
  }
  else {
    __checkAction( (iOTT)inst, wTurntable.getcmd( nodeA ));
  }


  if( StrOp.equals( wTurntable.getcmd(nodeA), wSwitch.unlock ) ) {
    TTOp.unLock( inst, data->lockedId, NULL );
  }
  else if( StrOp.equals( wTurntable.gettype( data->props ), wTurntable.locdec ) )
    return __cmd_locdec( (iOTT)inst, nodeA );
  else if( StrOp.equals( wTurntable.gettype( data->props ), wTurntable.accdec ) )
    return __cmd_accdec( (iOTT)inst, nodeA );
  else if( StrOp.equals( wTurntable.gettype( data->props ), wTurntable.digitalbahn ) )
    return __cmd_digitalbahn( (iOTT)inst, nodeA );
  else if( StrOp.equals( wTurntable.gettype( data->props ), wTurntable.multiport ) )
    return __cmd_multiport( (iOTT)inst, nodeA );
  else if( StrOp.equals( wTurntable.gettype( data->props ), wTurntable.f6915 ) )
    return __cmd_f6915( (iOTT)inst, nodeA );
  else if( StrOp.equals( wTurntable.gettype( data->props ), wTurntable.muet ) )
    return __cmd_muet( (iOTT)inst, nodeA );
  else if( StrOp.equals( wTurntable.gettype( data->props ), wTurntable.slx815 ) )
    return __cmd_slx815( (iOTT)inst, nodeA );
  else if( StrOp.equals( wTurntable.gettype( data->props ), wTurntable.ttdec ) )
    return __cmd_ttdec( (iOTT)inst, nodeA );
  else if( StrOp.equals( wTurntable.gettype( data->props ), wTurntable.d15 ) )
    return __cmd_d15( (iOTT)inst, nodeA );
  else if( StrOp.equals( wTurntable.gettype( data->props ), wTurntable.dsm ) )
    return __cmd_dsm( (iOTT)inst, nodeA );
  else {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
                 "Unknown turntable type [%s] for [%s]",
                 wTurntable.gettype( data->props ),
                 wTurntable.getid( data->props ) );
    NodeOp.base.del(nodeA);
  }
  return False;
}


static int __evaluatePos( iOTT inst, Boolean puls, const char* id, Boolean* polarization ) {
  iOTTData data = Data(inst);

  iONode track = wTurntable.gettrack( data->props );
  while( track != NULL ) {
    if( StrOp.equals( id, wTTTrack.getposfb( track ) ) ) {
      data->tablepos = wTTTrack.getnr( track );
      *polarization = wTTTrack.ispolarization(track);
      return wTTTrack.getnr( track );
    }
    track = wTurntable.nexttrack( data->props, track );
  }

  return -1;
}


static Boolean __getPolarization( iOTT inst, int tracknr ) {
  iOTTData data = Data(inst);

  iONode track = wTurntable.gettrack( data->props );
  while( track != NULL ) {
    if( wTTTrack.getnr( track ) == tracknr ) {
      return wTTTrack.ispolarization(track);
    }
    track = wTurntable.nexttrack( data->props, track );
  }

  return False;
}


static int __getMappedTrack( iOTT inst, int tracknr ) {
  iOTTData data = Data(inst);

  iONode track = wTurntable.gettrack( data->props );
  while( track != NULL ) {
    if( tracknr == wTTTrack.getnr( track ) ) {
      if( wTTTrack.getdecnr( track ) != -1 ) {
        return wTTTrack.getdecnr( track );
      }
    }
    track = wTurntable.nexttrack( data->props, track );
  }

  return tracknr;
}


static int __getOppositeTrackNr(int pos) {
  int opp = pos + 24;
  if( opp >= 48 )
    opp -= 48;
  return opp;
}


static int __getOppositeTrack( iOTT inst, int tracknr ) {
  iOTTData data = Data(inst);

  iONode track = wTurntable.gettrack( data->props );
  while( track != NULL ) {
    if( tracknr == wTTTrack.getnr( track ) ) {
      if( wTTTrack.getdecnr( track ) != -1 ) {
        return wTTTrack.getoppositetrack( track );
      }
    }
    track = wTurntable.nexttrack( data->props, track );
  }

  return -1;
}


static int __getNextTrack( iOTT inst, int tracknr ) {
  iOTTData data = Data(inst);

  iONode track = wTurntable.gettrack( data->props );
  while( track != NULL ) {
    if( tracknr == wTTTrack.getnr( track ) ) {
      track = wTurntable.nexttrack( data->props, track );
      if( track != NULL ) {
        return wTTTrack.getnr( track );
      }
      else {
        track = wTurntable.gettrack( data->props );
        return wTTTrack.getnr( track );
      }
    }
    track = wTurntable.nexttrack( data->props, track );
  }

  return -1;
}


static int __getPrevTrack( iOTT inst, int tracknr ) {
  iOTTData data = Data(inst);

  Boolean useLast = False;
  iONode prevtrack = NULL;
  iONode track = wTurntable.gettrack( data->props );
  while( track != NULL ) {
    if( tracknr == wTTTrack.getnr( track ) ) {
      if( prevtrack != NULL ) {
        return wTTTrack.getnr( prevtrack );
      }
      else {
        useLast = True;
      }
    }
    prevtrack = track;
    track = wTurntable.nexttrack( data->props, track );
  }

  if( useLast && prevtrack != NULL ) {
    return wTTTrack.getnr( prevtrack );
  }

  return -1;
}


static void __fbPositionEvent( obj inst, Boolean puls, const char* id, const char* ident, const char* ident2, const char* ident3, const char* ident4, int val, int wheelcount, Boolean dir ) {
  iOTTData data = Data(inst);
  iOControl control = AppOp.getControl();
  char l_cmd[64] = {'\0'};
  /* TODO: evaluate position event */

  if( puls ) {

    if( data->gotopos != -1 ) {
      data->tablepos = data->gotopos;
      __polarize(inst, -1, __getPolarization((iOTT)inst, data->tablepos) );
    }

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "fbPositionEvent for Turntable [%s] fb=[%s]",
        inst->id(inst), id, data->tablepos );

    /* Broadcast to clients. */
    {
      iONode event = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
      wTurntable.setid( event, wTurntable.getid( data->props ) );
      wTurntable.setbridgepos( event, data->tablepos );
      wTurntable.setstate1( event, wTurntable.isstate1(data->props) );
      wTurntable.setstate2( event, wTurntable.isstate2(data->props) );
      if( data->lockedId != NULL )
        wTurntable.setlocid( event, data->lockedId );
      if( wTurntable.getiid( data->props ) != NULL )
        wTurntable.setiid( event, wTurntable.getiid( data->props ) );
      AppOp.broadcastEvent( event );
    }


    /* bridge is in position */
    data->pending = False;
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "bridge at position pos=%d ", data->tablepos );
    wTurntable.setbridgepos( data->props, data->tablepos );

    __checkAction( (iOTT)inst, "atposition");
    StrOp.fmtb( l_cmd, "atposition %d", data->tablepos );
    __checkAction( (iOTT)inst, l_cmd);

    if( wTurntable.getdelay( data->props) > 0 ) {
      data->delaytick = SystemOp.getTick();
    }
    else {
      data->delaytick = 0;
    }



    if( StrOp.equals( wTurntable.gettype( data->props ), wTurntable.locdec ) ) {
      iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
      const char* iid = wTurntable.getiid( data->props );
      if( iid != NULL )
        wTurntable.setiid( cmd, iid );

      wLoc.setid( cmd, wTurntable.getid( data->props ) );
      wLoc.setaddr( cmd, wTurntable.getaddr( data->props ) );

      /* Using the Loc wrapper for the other parameters: */
      wLoc.setV_mode( cmd, wLoc.V_mode_percent );
      wLoc.setV( cmd, 0 );
      wLoc.setfn( cmd, False );
      wLoc.setdir( cmd, data->dir );

      if(wTurntable.getactfn( data->props ) > 0) {
        iONode fcmd = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE );
        if( iid != NULL )
          wTurntable.setiid( fcmd, iid );
        wFunCmd.setid( fcmd, wTurntable.getid( data->props ) );
        wFunCmd.setaddr( fcmd, wTurntable.getaddr( data->props ) );
        wFunCmd.setfnchanged( fcmd, wTurntable.getactfn( data->props ));
        data->f[wTurntable.getactfn( data->props )] = False;
        __cpFn2Node( (iOTT)inst, fcmd );

        wLoc.setV_mode( fcmd, wLoc.V_mode_percent );
        wLoc.setV( fcmd, wTurntable.getV( data->props ) );
        wLoc.setprot( fcmd, wTurntable.getprot( data->props ) );
        wLoc.setfn( fcmd, wTurntable.getactfn( data->props ) == 0 ? True:False );
        wLoc.setdir( fcmd, data->dir );

        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "turn function %d off...", wTurntable.getactfn( data->props ) );
        ControlOp.cmd( control, fcmd, NULL );
      }

      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "turn motor off..." );
      ControlOp.cmd( control, cmd, NULL );


    }

    else if( StrOp.equals( wTurntable.gettype( data->props ), wTurntable.accdec ) ) {
      iONode swcmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      const char* iid = wTurntable.getiid( data->props );
      if( iid != NULL )
        wSwitch.setiid( swcmd, iid );
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "accdec: turn motor off..." );
      wSwitch.setaddr1( swcmd, wTurntable.getaddr( data->props ) );
      wSwitch.setprot( swcmd, wTurntable.getprot( data->props ) );
      wSwitch.setcmd( swcmd, wSwitch.straight );
      ControlOp.cmd( control, swcmd, NULL );
    }

    /* check managed TT */
    if( wTurntable.ismanager(data->props) && data->lockedId != NULL) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "handle bridge in position event on managed TT %s", TTOp.base.id(inst) );
      /* check if the loco is on the bridge and let it roll to the selected block. */
      if( data->locoOnBridge ) {
        iOModel model = AppOp.getModel();
        iOLoc loc = ModelOp.getLoc( model, data->lockedId, NULL, False );
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "loco %s in on the bridge of managed TT %s", data->lockedId, TTOp.base.id(inst) );
      }
    }

  }

}


static void __fbBridgeEvent( obj inst, Boolean puls, const char* id, const char* ident, const char* ident2, const char* ident3, const char* ident4, int val, int wheelcount, Boolean dir ) {
  iOTTData data = Data(inst);
  const char* event = NULL;
  Boolean state1 = wTurntable.isstate1( data->props );
  Boolean state2 = wTurntable.isstate2( data->props );
  Boolean stateMid1 = wTurntable.isstateMid( data->props );
  Boolean stateMid2 = wTurntable.isstateMid2( data->props );

  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "Turntable:%s: fbid=%s state=%s ident=%d",
                 inst->id(inst), id, puls?"true":"false", ident );

  /* send event to the turntable owner block */
  /* s1 */
  if( StrOp.equals( id, wTurntable.gets1( data->props ) ) ) {
    state1 = puls;
    if( data->triggerS1 && data->triggerS2 ) {
      /* ignore */
    }
    else if( !data->triggerS1 && !data->triggerS2 ) {
      /* enter event */
      data->triggerS1 = True;
      if( wTurntable.gets2( data->props ) == NULL || StrOp.len(wTurntable.gets2( data->props )) == 0 ) {
        data->triggerS2 = True;
        event = wFeedbackEvent.enter2in_event;
      }
      else
        event = wFeedbackEvent.enter_event;
    }
    else if( !data->triggerS1 && data->triggerS2 ) {
      /* in event */
      data->triggerS1 = True;
      event = wFeedbackEvent.in_event;
    }
  }
  /* s2 */
  else if( StrOp.equals( id, wTurntable.gets2( data->props ) ) ) {
    state2 = puls;
    if( data->triggerS1 && data->triggerS2 ) {
      /* ignore */
    }
    else if( !data->triggerS1 && !data->triggerS2 ) {
      /* enter event */
      data->triggerS2 = True;
      event = wFeedbackEvent.enter_event;
    }
    else if( data->triggerS1 && !data->triggerS2 ) {
      /* in event */
      data->triggerS2 = True;
      event = wFeedbackEvent.in_event;
    }
  }

  /* sMid */
  else if( StrOp.equals( id, wTurntable.getsMid( data->props ) ) ) {
    stateMid1 = puls;
    if( (data->triggerSmid2 && !data->triggerSmid1) || (!data->hasMid2 && !data->triggerSmid1) ) {
      /* enter event */
      data->triggerSmid1 = True;
      event = wFeedbackEvent.pre2in_event;
    }
  }

  else if( StrOp.equals( id, wTurntable.getsMid2( data->props ) ) ) {
    stateMid2 = puls;
    if( data->triggerSmid1 && !data->triggerSmid2 ) {
      /* enter event */
      data->triggerSmid2 = True;
      event = wFeedbackEvent.pre2in_event;
    }
  }

  /* check for embedded block */
  if(wTurntable.isembeddedblock(data->props)) {
    if( data->lockedId != NULL && StrOp.len( data->lockedId ) > 0 ) {
      iOModel model = AppOp.getModel();
      iOLoc loc = ModelOp.getLoc( model, data->lockedId, NULL, False );
      if( loc != NULL ) {
        LocOp.event( loc, inst, BlockOp.getEventCode(NULL, event), 0, False, NULL );
      }
    }
  }
  else if( event != NULL && data->listenerFun != NULL ) {
    /* Call listener. */
    data->listenerFun( data->listenerObj, event, inst->id(inst) );
  }

  wTurntable.setstate1( data->props, state1 );
  wTurntable.setstate2( data->props, state2 );
  wTurntable.setstateMid( data->props, stateMid1 );
  wTurntable.setstateMid2( data->props, stateMid2 );

  /* Broadcast to clients. */
  {
    iONode node = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
    wTurntable.setid( node, inst->id(inst) );
    wTurntable.setstate1( node, state1 );
    wTurntable.setstate2( node, state2 );
    wTurntable.setstateMid( node, stateMid1 | stateMid2 );
    wTurntable.setbridgepos( node, wTurntable.getbridgepos( data->props) );
    if( data->lockedId != NULL )
      wTurntable.setlocid( node, data->lockedId );
    if( wTurntable.getiid( data->props ) != NULL )
      wTurntable.setiid( node, wTurntable.getiid( data->props ) );
    AppOp.broadcastEvent( node );
  }

}


static void __polarize(obj inst, int pos, Boolean polarization) {
  iOTTData data = Data(inst);
  iOControl control = AppOp.getControl();

  if( !data->lcdir ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "skipping bridge polarization for opposite position" );
    return;
  }

  if( pos != -1 ) {
    iONode track = wTurntable.gettrack( data->props );
    while( track != NULL ) {
      if( wTTTrack.getnr( track ) == pos ) {
        polarization = wTTTrack.ispolarization(track);
        break;
      }
      track = wTurntable.nexttrack( data->props, track );
    }
  }


  if( wTurntable.getpoladdr( data->props ) > 0 ) {
    iONode cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    int addr = wTurntable.getpoladdr( data->props );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "setting bridge polarization to %d", polarization );

    const char* iid = wTurntable.getiid( data->props );
    if( iid != NULL )
      wSwitch.setiid( cmd, iid );

    wSwitch.setprot( cmd, wTurntable.getprot( data->props ) );

    if( polarization ) {
      wSwitch.setaddr1( cmd, 0 );
      wSwitch.setport1( cmd, addr );
      wSwitch.setcmd( cmd, wSwitch.turnout );
      ControlOp.cmd( control, cmd, NULL );
    }
    else {
      wSwitch.setaddr1( cmd, 0 );
      wSwitch.setport1( cmd, addr );
      wSwitch.setcmd( cmd, wSwitch.straight );
      ControlOp.cmd( control, (iONode)NodeOp.base.clone(cmd), NULL );
    }

  }
  else {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "polarization address is not set" );
  }

}


static void __fbEvent( obj inst, Boolean puls, const char* id, const char* identifier, const char* identifier2, const char* identifier3, const char* identifier4, int val, int wheelcount, Boolean dir ) {
  iOTTData data = Data(inst);
  iOControl control = AppOp.getControl();
  int prevpos = data->tablepos;
  Boolean polarization;
  int pos = data->tablepos;
  Boolean stop = False;

  if( !puls ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "OFF events are not used..." );
    return;
  }

  pos = __evaluatePos( (iOTT)inst, puls, id, &polarization );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "fbEvent for Turntable [%s] fb=[%s] val=[%d] pos=[%d] polarization=[%d] ",
      inst->id(inst), id, val, pos, polarization );

  if( control == NULL ) {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "controller is not initialized..." );
    return;
  }

  /* Broadcast to clients. */
  {
    iONode event = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
    wTurntable.setid( event, wTurntable.getid( data->props ) );
    wTurntable.setbridgepos( event, pos );
    wTurntable.setstate1( event, wTurntable.isstate1(data->props) );
    wTurntable.setstate2( event, wTurntable.isstate2(data->props) );
    if( data->lockedId != NULL )
      wTurntable.setlocid( event, data->lockedId );
    if( wTurntable.getiid( data->props ) != NULL )
      wTurntable.setiid( event, wTurntable.getiid( data->props ) );
    AppOp.broadcastEvent( event );
  }

  if( data->gotopos != -1 ) {
    if( pos == data->gotopos ) {
      stop = True;
      data->gotopos = -1;
    }
    else {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
          "bridge not at position pos=%d goto=%d", pos, data->gotopos );
    }
  }
  else if( puls )
    stop = True;

  if( stop ) {
    char l_cmd[64] = {'\0'};
    /* bridge is in position */
    data->pending = False;
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "bridge at position pos=%d ", pos );

    __checkAction( (iOTT)inst, "atposition");
    StrOp.fmtb( l_cmd, "atposition %d", data->tablepos );
    __checkAction( (iOTT)inst, l_cmd);

    wTurntable.setbridgepos( data->props, pos );

    if( wTurntable.getdelay( data->props) > 0 ) {
      data->delaytick = SystemOp.getTick();
    }
    else {
      data->delaytick = 0;
    }

  }

  if( stop && StrOp.equals( wTurntable.gettype( data->props ), wTurntable.locdec ) ) {
    iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    const char* iid = wTurntable.getiid( data->props );
    if( iid != NULL )
      wTurntable.setiid( cmd, iid );

    wLoc.setprot( cmd, wTurntable.getprot( data->props ) );
    wLoc.setid( cmd, wTurntable.getid( data->props ) );
    wLoc.setaddr( cmd, wTurntable.getaddr( data->props ) );

    /* Using the Loc wrapper for the other parameters: */
    wLoc.setV_mode( cmd, wLoc.V_mode_percent );
    wLoc.setV( cmd, 0 );
    wLoc.setfn( cmd, False );
    wLoc.setdir( cmd, data->dir );

    if(wTurntable.getactfn( data->props ) > 0) {
      iONode fcmd = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE );
      if( iid != NULL )
        wTurntable.setiid( fcmd, iid );
      wFunCmd.setid( fcmd, wTurntable.getid( data->props ) );
      wFunCmd.setaddr( fcmd, wTurntable.getaddr( data->props ) );
      wFunCmd.setfnchanged( fcmd, wTurntable.getactfn( data->props ));
      data->f[wTurntable.getactfn( data->props )] = False;
      __cpFn2Node( (iOTT)inst, fcmd );

      wLoc.setV_mode( fcmd, wLoc.V_mode_percent );
      wLoc.setV( fcmd, wTurntable.getV( data->props ) );
      wLoc.setprot( fcmd, wTurntable.getprot( data->props ) );
      wLoc.setfn( fcmd, wTurntable.getactfn( data->props ) == 0 ? True:False );
      wLoc.setdir( fcmd, data->dir );

      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "turn function %d off...", wTurntable.getactfn( data->props ) );
      ControlOp.cmd( control, fcmd, NULL );
    }

    /* TODO: wait in a thread to prevent blocking the system*/
    ThreadOp.sleep(10 + wTurntable.getmotoroffdelay( data->props ));

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "turn motor off..." );
    ControlOp.cmd( control, cmd, NULL );

  }
  else if( stop && StrOp.equals( wTurntable.gettype( data->props ), wTurntable.accdec ) ) {
    iONode swcmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    const char* iid = wTurntable.getiid( data->props );
    if( iid != NULL )
      wSwitch.setiid( swcmd, iid );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "accdec: turn motor off..." );
    wSwitch.setaddr1( swcmd, wTurntable.getaddr( data->props ) );
    wSwitch.setprot( swcmd, wTurntable.getprot( data->props ) );
    wSwitch.setcmd( swcmd, wSwitch.straight );
    ControlOp.cmd( control, swcmd, NULL );
  }

  __polarize(inst, -1, polarization );

}


/* Initialize a managed track.
 *   Add a generated route from the track block to the TT.
 */
static void __initTTTrack(iOTT inst, iONode track) {
  iOModel model = AppOp.getModel();
  iONode route = NodeOp.inst(wRoute.name(), NULL, ELEMENT_NODE);
  iONode swcmd = NodeOp.inst(wSwitchCmd.name(), NULL, ELEMENT_NODE);

  wItem.setgenerated( route, True );

  wRoute.setbka( route, wTTTrack.getbkid(track) );
  wRoute.setbkaside( route, False );
  wRoute.setbkb( route, TTOp.base.id(inst) );
  wRoute.setbkbside( route, True );
  wRoute.setspeed( route, wBlock.min );
  wRoute.setdesc( route, "TT Manager generated route.");

  /* Add TT command */
  wSwitchCmd.setid( swcmd, TTOp.base.id(inst) );
  wSwitchCmd.setcmd( swcmd, wSwitchCmd.cmd_track );
  wSwitchCmd.settrack( swcmd, wTTTrack.getnr(track) );
  NodeOp.addChild( route, swcmd );

  char* routeId = StrOp.fmt( "autogen-[%s%s]-[%s%s]",
      wRoute.getbka(route), wRoute.isbkaside(route)?"+":"-", wRoute.getbkb(route), wRoute.isbkbside(route)?"+":"-" );
  wRoute.setid(route, routeId );
  StrOp.free(routeId);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "TTTrack route added: %s", wRoute.getid(route) );

  ModelOp.addItem(model, route);
  NodeOp.base.del(route);

  route = NodeOp.inst(wRoute.name(), NULL, ELEMENT_NODE);
  swcmd = NodeOp.inst(wSwitchCmd.name(), NULL, ELEMENT_NODE);

  wItem.setgenerated( route, True );

  wRoute.setbka( route, TTOp.base.id(inst) );
  wRoute.setbkaside( route, True );
  wRoute.setbkb( route, wTTTrack.getbkid(track) );
  wRoute.setbkbside( route, False );
  wRoute.setspeed( route, wBlock.min );
  wRoute.setdesc( route, "TT Manager generated route.");

  /* Add TT command */
  wSwitchCmd.setid( swcmd, TTOp.base.id(inst) );
  wSwitchCmd.setcmd( swcmd, wSwitchCmd.cmd_track );
  wSwitchCmd.settrack( swcmd, wTTTrack.getnr(track) );
  NodeOp.addChild( route, swcmd );

  routeId = StrOp.fmt( "autogen-[%s%s]-[%s%s]",
      wRoute.getbka(route), wRoute.isbkaside(route)?"+":"-", wRoute.getbkb(route), wRoute.isbkbside(route)?"+":"-" );
  wRoute.setid(route, routeId );
  StrOp.free(routeId);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "TTTrack route added: %s", wRoute.getid(route) );

  ModelOp.addItem(model, route);
  NodeOp.base.del(route);

}


static Boolean __isElectricallyFree( iOTT inst ) {
  iOTTData data = Data(inst);
  iOModel model = AppOp.getModel();
  iONode track = wTurntable.gettrack( data->props );

  const char* s1    = wTurntable.gets1( data->props );
  const char* s2    = wTurntable.gets2( data->props );
  const char* sMid  = wTurntable.getsMid( data->props );
  const char* sMid2 = wTurntable.getsMid2( data->props );

  if( s1 != NULL && StrOp.len( s1 ) > 0 ) {
    iOFBack fb = ModelOp.getFBack( model, s1 );
    if( fb != NULL && FBackOp.getState(fb) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                     "TT [%s] is electrically occupied by sensor [%s]", TTOp.base.id(inst), FBackOp.getId(fb) );
      return False;
    }
  }

  if( s2 != NULL && StrOp.len( s2 ) > 0 ) {
    iOFBack fb = ModelOp.getFBack( model, s2 );
    if( fb != NULL && FBackOp.getState(fb) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                     "TT [%s] is electrically occupied by sensor [%s]", TTOp.base.id(inst), FBackOp.getId(fb) );
      return False;
    }
  }

  if( sMid != NULL && StrOp.len( sMid ) > 0 ) {
    iOFBack fb = ModelOp.getFBack( model, sMid );
    if( fb != NULL && FBackOp.getState(fb) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                     "TT [%s] is electrically occupied by sensor [%s]", TTOp.base.id(inst), FBackOp.getId(fb) );
      return False;
    }
  }

  if( sMid2 != NULL && StrOp.len( sMid2 ) > 0 ) {
    iOFBack fb = ModelOp.getFBack( model, sMid2 );
    if( fb != NULL && FBackOp.getState(fb) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                     "TT [%s] is electrically occupied by sensor [%s]", TTOp.base.id(inst), FBackOp.getId(fb) );
      return False;
    }
  }


  return True;
}

static void __initCallback( iOTT inst ) {
  iOTTData data = Data(inst);
  iOModel model = AppOp.getModel();
  iONode track = wTurntable.gettrack( data->props );

  const char* s1    = wTurntable.gets1( data->props );
  const char* s2    = wTurntable.gets2( data->props );
  const char* sMid  = wTurntable.getsMid( data->props );
  const char* sMid2 = wTurntable.getsMid2( data->props );
  const char* psen  = wTurntable.getpsen( data->props );

  data->hasMid2 = False;

  if( s1 != NULL && StrOp.len( s1 ) > 0 ) {
    iOFBack bridgefb = ModelOp.getFBack( model, s1 );
    if( bridgefb != NULL ) {
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Setting bridge listener [%s]", s1 );
      FBackOp.setListener( bridgefb, (obj)inst, &__fbBridgeEvent );
    }
    else
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "bridge s1 [%s] not found!", s1 );
  }

  if( s2 != NULL && StrOp.len( s2 ) > 0 ) {
    iOFBack bridgefb = ModelOp.getFBack( model, s2 );
    if( bridgefb != NULL ) {
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Setting bridge listener [%s]", s2 );
      FBackOp.setListener( bridgefb, (obj)inst, &__fbBridgeEvent );
    }
    else
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "bridge s2 [%s] not found!", s2 );
  }

  if( sMid != NULL && StrOp.len( sMid ) > 0 ) {
    iOFBack bridgefb = ModelOp.getFBack( model, sMid );
    if( bridgefb != NULL ) {
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Setting bridge listener [%s]", sMid );
      FBackOp.setListener( bridgefb, (obj)inst, &__fbBridgeEvent );
    }
    else
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "bridge sMid [%s] not found!", sMid );
  }

  if( sMid2 != NULL && StrOp.len( sMid2 ) > 0 ) {
    iOFBack bridgefb = ModelOp.getFBack( model, sMid2 );
    if( bridgefb != NULL ) {
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Setting bridge listener [%s]", sMid2 );
      FBackOp.setListener( bridgefb, (obj)inst, &__fbBridgeEvent );
      data->hasMid2 = True;
    }
    else
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "bridge sMid [%s] not found!", sMid );
  }

  if( psen != NULL && StrOp.len( psen ) > 0 ) {
    iOFBack posfb = ModelOp.getFBack( model, psen );
    if( posfb != NULL ) {
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Setting position listener [%s]", psen );
      FBackOp.setListener( posfb, (obj)inst, &__fbPositionEvent );
    }
    else
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "position sensor [%s] not found!", psen );
  }


  if( track == NULL )
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "No tracks defined for TT [%s]", inst->base.id(inst)  );

  while( track != NULL ) {
    const char* posfbid = wTTTrack.getposfb( track );

    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "track [%d]", wTTTrack.getnr( track ) );

    if( posfbid != NULL && StrOp.len( posfbid ) > 0 ) {
      iOFBack posfb = ModelOp.getFBack( model, posfbid );
      if( posfb != NULL ) {
        TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Setting listener [%s]", posfbid );
        FBackOp.setListener( posfb, (obj)inst, &__fbEvent );
      }
      else
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "posfb [%s] not found!", posfbid );
    }

    /* TT manager */
    if( wTurntable.ismanager(data->props ) && wTTTrack.getbkid(track) != NULL ) {
      __initTTTrack(inst, track);
    }

    track = wTurntable.nexttrack( data->props, track );
  }
}


/**
 * Search free track.
 *
 */
static iONode __findFreeTrack(iIBlockBase inst, const char* locId) {
  iOTTData data = Data(inst);
  iOModel model = AppOp.getModel();
  iONode track = wTurntable.gettrack( data->props );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "find free Turntable %s block...", wTurntable.getid(data->props));
  while( track != NULL ) {
    const char* bkid = wTTTrack.getbkid( track );
    iIBlockBase block = ModelOp.getBlock(model, bkid );
    if( block != NULL && block->isFree(block, locId ) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
          "free track[%d], block[%s], found for %s", wTTTrack.getnr(track), bkid , locId );
      return track;
    }
    track = wTurntable.nexttrack( data->props, track );
  }
  return NULL;
}

/**
 * Lock the bridge block and also lock a free track block in case the manager option is activated.
 */
static Boolean _lock( iIBlockBase inst, const char* id, const char* blockid, const char* routeid, Boolean crossing, Boolean reset, Boolean reverse, int indelay, const char* masterId, Boolean force ) {
  iOTTData data = Data(inst);
  Boolean ok = False;
  iOControl control = AppOp.getControl();

  if( !ControlOp.hasBlockPower(control, wTurntable.getid(data->props)) ) {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "turntable [%s] has no power; locking is rejected", wTurntable.getid(data->props) );
    return False;
  }

  /* wait only 10ms for getting the mutex: */
  if( !MutexOp.trywait( data->muxLock, 10 ) ) {
    return False;
  }

  if( TTOp.isFree(inst, id) ) {
    data->lockedId = id;
    ok = True;

    data->selectedTrack = NULL;

    /* Broadcast to clients. Node6 */
    if( ok ) {
      iONode nodeF = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
      wTurntable.setid( nodeF, inst->base.id(inst) );
      wTurntable.setbridgepos( nodeF, wTurntable.getbridgepos( data->props) );
      wTurntable.setstate1( nodeF, wTurntable.isstate1(data->props) );
      wTurntable.setstate2( nodeF, wTurntable.isstate2(data->props) );
      if( data->lockedId != NULL )
        wTurntable.setlocid( nodeF, data->lockedId );
      if( wTurntable.getiid( data->props ) != NULL )
        wTurntable.setiid( nodeF, wTurntable.getiid( data->props ) );
      ModelOp.setBlockOccupancy( AppOp.getModel(), TTOp.base.id(inst), data->lockedId, False, 0, 0, NULL );
      AppOp.broadcastEvent( nodeF );
    }

  }

  /* Unlock the semaphore: */
  MutexOp.post( data->muxLock );

  return ok;
}


static Boolean _setLocSchedule( iIBlockBase inst, const char* scid, Boolean manual ) {
  Boolean ok = False;
  if( inst != NULL && scid != NULL ) {
    iOTTData data = Data(inst);
  }
  return ok;
}


static Boolean _setLocTour( iIBlockBase inst, const char* tourid, Boolean manual ) {
  Boolean ok = False;
  if( inst != NULL && tourid != NULL ) {
    iOTTData data = Data(inst);
  }
  return ok;
}



static Boolean _unLock( iIBlockBase inst, const char* id, const char* routeid ) {
  iOTTData data = Data(inst);

  if( wTurntable.isembeddedblock(data->props) && routeid != NULL ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "ignore unlock turntable %s by route %s", inst->base.id(inst), routeid==NULL?"-":routeid );
    return True;
  }

  if( StrOp.equals( id, data->lockedId ) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "unlock turntable %s by [%s] route=%s", inst->base.id(inst), data->lockedId, routeid==NULL?"-":routeid );
    data->lockedId = NULL;
    /* Broadcast to clients. Node6 */
    {
      iONode nodeF = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
      wTurntable.setid( nodeF, TTOp.base.id(inst) );
      wTurntable.setbridgepos( nodeF, wTurntable.getbridgepos( data->props) );
      wTurntable.setlocid( nodeF, NULL );
      wTurntable.setstate1( nodeF, wTurntable.isstate1(data->props) );
      wTurntable.setstate2( nodeF, wTurntable.isstate2(data->props) );
      if( wTurntable.getiid( data->props ) != NULL )
        wTurntable.setiid( nodeF, wTurntable.getiid( data->props ) );
      ModelOp.setBlockOccupancy( AppOp.getModel(), TTOp.base.id(inst), "", False, 0, 0, NULL );
      AppOp.broadcastEvent( nodeF );
    }
    data->triggerS1 = False;
    data->triggerS2 = False;
    data->triggerSmid1 = False;
    data->triggerSmid2 = False;
    data->locoOnBridge = False;
    return True;
  }
  return False;
}

static Boolean _isLocked( iOTT inst, const char* id ) {
  iOTTData data = Data(inst);
  if( data->lockedId == NULL || StrOp.len(data->lockedId) == 0 ) {
    return False;
  }

  if( !StrOp.equals( id, data->lockedId ) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Turntable %s is locked by [%s].",
        inst->base.id(inst), data->lockedId );
    return True;
  }
  return False;
}


static Boolean _isSet( iOTT inst ) {
  iOTTData data = Data(inst);

  if( !data->pending && data->delaytick > 0 ) {
    unsigned long delay = wTurntable.getdelay( data->props) * 100;
    if( data->delaytick + delay <= SystemOp.getTick() ) {
      data->delaytick = 0;
      return True;
    }
    else
      return False;
  }

  return data->pending ? False:True;
}


static Boolean _getRunDir( iOTT inst ) {
  iOTTData data = Data(inst);

  return data->lcdir;
}


static void _reset( iIBlockBase inst, Boolean saveCurBlock ) {
  iOTTData data = Data(inst);
  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
             "reset turntable [%s]", inst->base.id(inst) );
  TTOp.unLock( inst, data->lockedId, NULL );
}


static int __compTrackNr(obj* _a, obj* _b)
{
    iONode a = (iONode)*_a;
    iONode b = (iONode)*_b;
    int nrA = wTTTrack.getnr( a );
    int nrB = wTTTrack.getnr( b );
    if( nrA == nrB )
      return 0;
    if( nrA > nrB )
      return 1;
    return -1;
}


static void __sortTracks(iOTT tt) {
  iOTTData data = Data(tt);
  iOList list = ListOp.inst();

  iONode track = wTurntable.gettrack( data->props );
  while( track != NULL ) {
    ListOp.add(list, (obj)track );
    NodeOp.removeChild( data->props, track);
    track = wTurntable.gettrack( data->props );
  }

  ListOp.sort(list, &__compTrackNr);
  int i = 0;
  for( i = 0; i < ListOp.size(list); i++) {
    NodeOp.addChild(data->props, (iONode)ListOp.get( list, i));
  }

  ListOp.base.del(list);
}


static iOTT _inst( iONode props ) {
  iOTT     tt    = allocMem( sizeof( struct OTT ) );
  iOTTData data  = allocMem( sizeof( struct OTTData ) );

  /* OBase operations */
  MemOp.basecpy( tt, &TTOp, 0, sizeof( struct OTT ), data );

  data->props = props;
  data->muxLock = MutexOp.inst( NULL, True );

  if( wTurntable.ismanager(data->props) ) {
    wTurntable.setembeddedblock(data->props, True);
  }

  __initCallback( tt );
  data->tablepos = wTurntable.getbridgepos(data->props);
  data->gotopos = -1;
  data->lcdir = True;

  NodeOp.removeAttrByName(data->props, "cmd");

  __sortTracks(tt);

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
      "turntable [%s] initialized at position [%d]", tt->base.id(tt), data->tablepos );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
      "turntable [%s] manager=%s embeddedblock=%s", tt->base.id(tt),
      wTurntable.ismanager(data->props)?"yes":"no", wTurntable.isembeddedblock(data->props)?"yes":"no" );

  instCnt++;

  return tt;
}

static const char* _getLoc( iIBlockBase inst ) {
  iOTTData data = Data(inst);
  /* TODO: dispatch to active tracke block */
  return "";
}

static const char* _getState( iIBlockBase inst ) {
  iOTTData data = Data(inst);
  return "";
}


static const char* _getInLoc( iIBlockBase inst ) {
  iOTTData data = Data(inst);
  /* TODO: dispatch to active tracke block */
  return "";
}

static Boolean _event( iIBlockBase inst, Boolean puls, const char* id, const char* ident, const char* ident2, const char* ident3, const char* ident4, int val, int wheelcount, iONode fbevt, Boolean dir ) {
  iOTTData data = Data(inst);
  /* TODO: dispatch to active tracke block */
  return False;
}

static const char* _getFromBlockId( iIBlockBase inst ) {
  iOTTData data = Data(inst);
  /* TODO: dispatch to active tracke block */
  return "";
}

static const char* _getTDiid( iIBlockBase inst ) {
  iOTTData data = Data(inst);
  /* TODO: dispatch to active tracke block */
  return "";
}


static int _getTDaddress( iIBlockBase inst ) {
  iOTTData data = Data(inst);
  /* TODO: dispatch to active tracke block */
  return 0;
}


static int _getTDport( iIBlockBase inst ) {
  iOTTData data = Data(inst);
  /* TODO: dispatch to active tracke block */
  return 0;
}


static void _setAnalog( iIBlockBase inst, Boolean analog ) {
  iOTTData data = Data(inst);
  /* TODO: dispatch to active tracke block */
}


static Boolean _isLinked( iIBlockBase inst ) {
  iOTTData data = Data(inst);
  /* TODO: dispatch to active tracke block */
  return False;
}

static void _setGroup( iIBlockBase inst, const char* group ) {
  iOTTData data = Data(inst);
  /* TODO: dispatch to active tracke block */
}

static void _enterBlock( iIBlockBase inst, const char* id ) {
  iOTTData data = Data(inst);
  if( wTurntable.isembeddedblock(data->props) ) {
    wTurntable.setlocid( data->props, id );
    if( id != NULL ) {
      iONode nodeD = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
      wTurntable.setid( nodeD, wTurntable.getid(data->props) );
      wTurntable.setentering( nodeD, True );
      data->lockedId = id;
      wTurntable.setlocid( nodeD, data->lockedId );
      if( wTurntable.getiid( data->props ) != NULL )
        wTurntable.setiid( nodeD, wTurntable.getiid( data->props ) );
      AppOp.broadcastEvent( nodeD );
    }
  }
}

static void _exitBlock( iIBlockBase inst, const char* id, Boolean unexpected ) {
}


static const char* _getVelocity( iIBlockBase inst, int* percent, Boolean onexit, Boolean reverse, Boolean onstop ) {
  iOTTData data = Data(inst);
  return wBlock.min;
}


static int _getDepartDelay( iIBlockBase inst ) {
  return 0;
}

static float _getmvspeed( iIBlockBase inst ) {
  return 0;
}

static int _getMaxKmh( iIBlockBase inst ) {
  return 0;
}


static int _getWait( iIBlockBase inst, iOLoc loc, Boolean reverse, int* oppwait ) {
  iOTTData data = Data(inst);
  *oppwait = 1;
  return 1; /* always wait on the bridge */
}

static Boolean _green( iIBlockBase inst, Boolean distant, Boolean reverse ) {
  iOTTData data = Data(inst);
  /* TODO: dispatch to active tracke block */
  return False;
}

static Boolean _red( iIBlockBase inst, Boolean distant, Boolean reverse ) {
  iOTTData data = Data(inst);
  /* TODO: dispatch to active tracke block */
  return False;
}

static Boolean _yellow( iIBlockBase inst, Boolean distant, Boolean reverse ) {
  iOTTData data = Data(inst);
  /* TODO: dispatch to active tracke block */
  return False;
}

static Boolean _white( iIBlockBase inst, Boolean distant, Boolean reverse ) {
  iOTTData data = Data(inst);
  /* TODO: dispatch to active tracke block */
  return False;
}

static void _setDefaultAspect(iIBlockBase inst, Boolean signalpair) {
}


static obj _hasManualSignal( iIBlockBase inst, Boolean distant, Boolean reverse ) {
  iOTTData data = Data(inst);
  /* TODO: dispatch to active tracke block */
  return NULL;
}


static Boolean _hasEnter2Route( iIBlockBase inst, const char* fromBlockID ) {
  iOTTData data = Data(inst);
  /* TODO: dispatch to active tracke block */
  return False;
}

static Boolean _hasPre2In( iIBlockBase inst, const char* fromBlockID ) {
  iOTTData data = Data(inst);
  /* TODO: dispatch to active tracke block */
  return False;
}

static void _inBlock( iIBlockBase inst, const char* id ) {
  iOTTData data = Data(inst);
  if( wTurntable.isembeddedblock(data->props) ) {
    wTurntable.setlocid( data->props, id );
    if( id != NULL ) {
      iONode nodeD = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
      wTurntable.setid( nodeD, wTurntable.getid(data->props) );
      wTurntable.setentering( nodeD, False );
      data->lockedId = id;
      wTurntable.setlocid( nodeD, data->lockedId );
      if( wTurntable.getiid( data->props ) != NULL )
        wTurntable.setiid( nodeD, wTurntable.getiid( data->props ) );
      AppOp.broadcastEvent( nodeD );
    }
  }
}

static Boolean _isTerminalStation( iIBlockBase inst ) {
  iOTTData data = Data(inst);
  /* TODO: dispatch to active tracke block */
  return False;
}

static Boolean _link( iIBlockBase inst, iIBlockBase linkto ) {
  iOTTData data = Data(inst);
  TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "link not supported" );
  return False;
}

static Boolean _unLink( iIBlockBase inst ) {
  iOTTData data = Data(inst);
  TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "unlink not supported" );
  return False;
}


static Boolean _lockForGroup( iIBlockBase inst, const char* id ) {
  iOTTData data = Data(inst);
  Boolean ok = False;
  Boolean broadcast = False;

  if( wTurntable.isembeddedblock(data->props) ) {

    if( !inst->isFree( inst, id ) ) {
      return False;
    }

    if( data->locIdGroup == NULL || StrOp.len( data->locIdGroup ) == 0 || StrOp.equals( "(null)", data->locIdGroup ) ) {
      if( data->lockedId == NULL || StrOp.len( data->lockedId ) == 0 || StrOp.equals( id, data->lockedId ) ) {
        data->locIdGroup = id;
        ok = True;
        broadcast = True;
      }
    }
    else if( StrOp.equals( id, data->locIdGroup ) ) {
      ok = True;
      broadcast = False;
    }


    /* Broadcast to clients. */
    if( ok && broadcast ) {
      iONode nodeD = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
      wTurntable.setid( nodeD, wTurntable.getid(data->props) );
      if( data->lockedId != NULL && StrOp.equals( id, data->lockedId ) )
        wTurntable.setreserved( nodeD, False );
      else
        wTurntable.setreserved( nodeD, True );
      wTurntable.setlocid( nodeD, id );
      AppOp.broadcastEvent( nodeD );
    }
  }

  return ok;
}


static Boolean _unLockForGroup( iIBlockBase inst, const char* id ) {
  iOTTData data = Data(inst);
  Boolean ok = False;

  if( wTurntable.isembeddedblock(data->props) ) {
    if( StrOp.equals( id, data->locIdGroup ) ) {
      data->locIdGroup = NULL;

      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                 "Turntable [%s] unlockForGroup [%s].",
                 wTurntable.getid(data->props), id );

      ok = True;
      /* Broadcast to clients only if the block is not locked. */
      if( data->lockedId == NULL || StrOp.len(data->lockedId) == 0 ) {
        iONode nodeD = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
        wTurntable.setid( nodeD, wTurntable.getid(data->props) );
        wTurntable.setlocid( nodeD, "" );
        AppOp.broadcastEvent( nodeD );
      }

    }
  }
  else
    ok = True;

  return ok;
}


static void _resetTrigs( iIBlockBase inst ) {
  iOTTData data = Data(inst);
  iOModel model = AppOp.getModel();
  data->triggerS1 = False;
  data->triggerS2 = False;
  data->triggerSmid1 = False;
  data->triggerSmid2 = False;

  if( wTurntable.ismanager(data->props) ) {
    /* dispatch to all track blocks */
    iONode pos = wTurntable.gettrack( data->props );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Reset Turntable %s blocks...", wTurntable.getid(data->props));
    while( pos != NULL ) {
      iIBlockBase block = ModelOp.getBlock( model, wTTTrack.getbkid(pos) );
      if( block != NULL ) {
        block->resetTrigs(block);
      }
      pos = wTurntable.nexttrack( data->props, pos );
    };
  }
}





static iIBlockBase __getBlock4Loc(iIBlockBase inst, const char* locid) {
  iOTTData data = Data(inst);
  iOModel model = AppOp.getModel();

  iONode pos = wTurntable.gettrack( data->props );
  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "get block for locid %s...", locid );
  while( pos != NULL ) {
    iIBlockBase block = ModelOp.getBlock( model, wTTTrack.getbkid(pos) );
    if( block != NULL && StrOp.equals( locid, block->getLoc(block) ) ) {
      return block;
    }
    else {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "block=0x%08X does not have set locid to %s...", locid );
    }
    pos = wTurntable.nexttrack( data->props, pos );
  };
  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "no block found for [%s].", locid );
  return NULL;
}


static Boolean _wait( iIBlockBase inst, iOLoc loc, Boolean reverse, Boolean* oppwait ) {
  iOTTData data = Data(inst);

  if( wTurntable.isembeddedblock(data->props) ) {
    return True;
  }

  if( wTurntable.ismanager(data->props) ) {
    iIBlockBase block = __getBlock4Loc(inst, LocOp.getId(loc));
    return block != NULL ? block->wait( block, loc, reverse, oppwait ) : False;
  }

  return False;
}


static void _init( iIBlockBase inst ) {
  iOTTData data = Data(inst);
  iOModel model = AppOp.getModel();

  if( wTurntable.isembeddedblock(data->props) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "init tt %s", wTurntable.getid(data->props) );
    /* this string pointer is not persistent! */
    data->lockedId = wTurntable.getlocid( data->props );

    if( data->lockedId != NULL && StrOp.len( data->lockedId ) > 0 ) {
      iOLoc loc = ModelOp.getLoc( model, data->lockedId, NULL, False );
      if( loc != NULL ) {
        LocOp.setCurBlock( loc, wTurntable.getid(data->props) );
        /* overwrite data->locId with the static id from the loc object: */
        data->lockedId = LocOp.getId( loc );

      }
      else
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "init() unknown locId: %s", data->lockedId );
    }

    inst->resetTrigs(inst);

  }

  if( wTurntable.ismanager(data->props) ) {
    /* All blocks are initialized by the Model. */
  }
}



static Boolean _isReady( iIBlockBase inst ) {
  iOTTData data = Data(inst);
  return !data->pending;
}


static Boolean _isFreeBlockOnEnter( iIBlockBase inst ) {
  iOTTData data = Data(inst);
  return False;
}


static Boolean _hasExtStop( iIBlockBase inst, const char* locoid ) {
  return False;
}

static Boolean _allowBBT( iIBlockBase inst ) {
  iOTTData data = Data(inst);
  return False;
}



static void _setManager( iIBlockBase inst, iIBlockBase manager ) {
  iOTTData data = Data(inst);
}


static iIBlockBase _getManager( iIBlockBase inst ) {
  iOTTData data = Data(inst);
  return NULL;
}


static Boolean _isState( iIBlockBase inst, const char* state ) {
  return False;
}

static Boolean _isTTBlock( iIBlockBase inst ) {
  return True;
}

static Boolean _isTD( iIBlockBase inst ) {
  return False;
}

static void _resetTD( iIBlockBase inst ) {
}


/*
 * Check for a free track block in case of an activated manager.
 */
static Boolean _isFree( iIBlockBase inst, const char* locId ) {
  iOTTData data = Data(inst);
  iOModel model = AppOp.getModel();

  if( data->lockedId == NULL || StrOp.len( data->lockedId ) == 0 || StrOp.equals( locId, data->lockedId ) )
  {
    if( wTurntable.ismanager(data->props) ) {
      if( !__isElectricallyFree((iOTT)inst) ) {
        return False;
      }
      /* check if a track block is available */
      return __findFreeTrack(inst, locId) != NULL ? True:False ;
    }
    else {
      return True;
    }
  }

  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "turntable is already locked by [%s]", data->lockedId );
  return False;
}

static int _isSuited( iIBlockBase inst, iOLoc loc, int* restlen, Boolean checkprev ) {
  iOTTData data = Data(inst);
  return 1;
}

static int _getVisitCnt( iIBlockBase inst, const char* id ) {
  iOTTData data = Data(inst);
  return 0;
}

static int _getOccTime( iIBlockBase inst ) {
  iOTTData data = Data(inst);
  return 0;
}

static int _getWheelCount( iIBlockBase inst ) {
  return 0;
}

static int _getRandomRate( iIBlockBase inst, const char* lcid ) {
  iOTTData data = Data(inst);
  return wTurntable.getrandomrate(data->props);
}

static void _setCarCount( iIBlockBase inst, int count ) {
}

static void _acceptIdent( iIBlockBase inst, Boolean accept ) {
}

static void _didNotDepart( iIBlockBase inst, const char* id ) {
}

static Boolean _isDepartureAllowed( iIBlockBase inst, const char* id, Boolean force ) {
  return True;
}

static void _setTempWait(iIBlockBase inst, Boolean wait) {
}

static void _setGhostDetected(iIBlockBase inst, const char* key, const char* ident) {
  iOTTData data = Data(inst);
}

static void _setClass( iIBlockBase inst, const char* p_Class ) {
}

static Boolean _hasClass( iIBlockBase inst, const char* class ) {
  return False;
}

static void _setMasterID( iIBlockBase inst, const char* masterid ) {
}


/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocrail/impl/tt.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/

