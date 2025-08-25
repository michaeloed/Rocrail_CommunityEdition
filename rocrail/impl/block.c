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
#include <time.h>

#include "rocrail/impl/block_impl.h"
#include "rocrail/public/app.h"
#include "rocrail/public/fback.h"
#include "rocrail/public/route.h"
#include "rocrail/public/control.h"
#include "rocrail/public/modplan.h"
#include "rocrail/public/action.h"
#include "rocrail/public/location.h"

#include "rocs/public/doc.h"
#include "rocs/public/trace.h"
#include "rocs/public/node.h"
#include "rocs/public/mem.h"
#include "rocs/public/str.h"
#include "rocs/public/strtok.h"
#include "rocs/public/system.h"

#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/Ctrl.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/FeedbackEvent.h"
#include "rocrail/wrapper/public/PermInclude.h"
#include "rocrail/wrapper/public/PermExclude.h"
#include "rocrail/wrapper/public/Ctrl.h"
#include "rocrail/wrapper/public/FreeRail.h"
#include "rocrail/wrapper/public/Action.h"
#include "rocrail/wrapper/public/ActionCtrl.h"
#include "rocrail/wrapper/public/Item.h"


static int instCnt = 0;

static Boolean __isElectricallyFree(iOBlock inst);
static void __dumpFiFo(iIBlockBase inst);


/*
 ***** OBase functions.
 */
static const char* __id( void* inst ) {
  iOBlockData data = Data(inst);
  return data->id;
}

static void* __event( void* inst, const void* evt ) {
  iOBlockData data = Data(inst);
  iONode node = (iONode)evt;
  if( StrOp.equals( wBlock.name(), NodeOp.getName( node ) ) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "block [%s] event: %s", data->id, wBlock.getstate(node) );

    if( StrOp.equals(wBlock.getstate( node ), wBlock.shortcut) ) {
      wBlock.setprevstate(data->props, wBlock.getstate(data->props) );
      wBlock.setstate(data->props, wBlock.getstate(node) );
    }
    else if( StrOp.equals(wBlock.getstate( node ), wBlock.shortcutcleared) ) {
      if( StrOp.equals(wBlock.getstate( data->props ), wBlock.shortcut) ) {
        wBlock.setstate(data->props, wBlock.getprevstate(data->props) );
      }
    }

    /* Broadcast to clients. */
    AppOp.broadcastEvent( (iONode)NodeOp.base.clone( data->props ) );
  }
  else if( StrOp.equals( wFeedback.name(), NodeOp.getName( node ) ) ) {
    if( BlockOp.event( (iIBlockBase)inst, wFeedback.isstate(node), wFeedback.getid(node), wFeedback.getidentifier(node), wFeedback.getidentifier2(node),
        wFeedback.getidentifier3(node), wFeedback.getidentifier4(node), wFeedback.getval(node), wFeedback.getwheelcount(node), NULL, wFeedback.isdirection(node) ) ) {
      if( wFeedback.getwheelcount(node) > 0 ) {
        data->wheelcount = wFeedback.getwheelcount(node);
        data->wheelcounterId = wFeedback.getid(node);
      }
    }

    if( data->pendingFree ) {
      if( __isElectricallyFree((iOBlock)inst) ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "block [%s] is finally unlocked", data->id );
        data->pendingFree = False;
      }
    }
  }

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
  iOBlockData data = Data(inst);
  return (char*)data->id;
}
static void __del(void* inst) {
  iOBlockData data = Data(inst);
  freeMem( data );
  freeMem( inst );
  instCnt--;
}
static void* __properties(void* inst) {
  iOBlockData data = Data(inst);
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


static void _resetTD(iIBlockBase inst) {
  iOBlockData data   = Data(inst);
  if( wBlock.istd(data->props) ) {
    iOControl control = AppOp.getControl();
    iONode cmd = NodeOp.inst( wSysCmd.name(), NULL, ELEMENT_NODE );
    wSysCmd.setcmd(cmd, wSysCmd.resetblock);
    wSysCmd.setvalA(cmd, wBlock.getport( data->props ));
    wSysCmd.setiid( cmd, wBlock.getiid( data->props ) );
    wSysCmd.setid( cmd, wBlock.getid( data->props ) );
    wSysCmd.setaddr( cmd, wBlock.getaddr( data->props ) );
    wSysCmd.setport( cmd, wBlock.getport( data->props ) );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
             "reset trackdriver block [%s]", data->id );
    ControlOp.cmd( control, cmd, NULL );
  }
}

static Boolean _isTD(iIBlockBase inst) {
  iOBlockData data   = Data(inst);
  return wBlock.istd(data->props);
}

static void __checkAction( iOBlock inst, const char* state ) {
  iOBlockData data   = Data(inst);
  iOModel     model  = AppOp.getModel();
  iONode      action = wBlock.getactionctrl( data->props );

  /* loop over all actions */
  while( action != NULL ) {
    int counter = atoi(wActionCtrl.getstate( action ));

    if( StrOp.len(wActionCtrl.getstate( action )) == 0 || StrOp.equals(state, wActionCtrl.getstate( action )) )
    {

      iOAction Action = ModelOp.getAction(model, wActionCtrl.getid( action ));
      if( Action != NULL ) {
        iOLoc lc = ModelOp.getLoc( AppOp.getModel(), data->locId, NULL, False );
        if( lc != NULL ) {
          wActionCtrl.setlcclass(action, LocOp.getClass(lc));
        }
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "block action [%s-%s]", data->id, data->locId );
        wActionCtrl.setbkid(action, data->id);
        wActionCtrl.setlcid(action, data->locId);
        wActionCtrl.setstid(action, data->byRouteId);

        ActionOp.exec(Action, action);
      }
    }
    else {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "%s action state does not match: [%s-%s]",
          data->id, wActionCtrl.getstate( action ), state );
    }

    action = wBlock.nextactionctrl( data->props, action );
  }
}




static void _setDefaultAspect(iIBlockBase inst, Boolean signalpair) {
  iOBlockData data = Data(inst);
  /* set default signal aspect */
  int aspect = 0;
  const char* defaspect = wCtrl.getdefaspect( AppOp.getIniNode( wCtrl.name() ) );
  if( StrOp.equals( wSignal.green, defaspect) )
    aspect = 1;
  else if( StrOp.equals( wSignal.yellow, defaspect) )
    aspect = 2;
  else if( StrOp.equals( wSignal.white, defaspect) )
    aspect = 3;

  switch( aspect ) {
    case 0:
      BlockOp.red( inst, False, signalpair );
      BlockOp.red( inst, True, signalpair );
      break;
    case 1:
      BlockOp.green( inst, False, signalpair );
      BlockOp.green( inst, True, signalpair );
      break;
    case 2:
      BlockOp.yellow( inst, False, signalpair );
      BlockOp.yellow( inst, True, signalpair );
      break;
    case 3:
      BlockOp.white( inst, False, signalpair );
      BlockOp.white( inst, True, signalpair );
      break;
  }
}



static Boolean __acceptGhost( obj inst ) {
  iOBlockData data = Data(inst);

  if( wBlock.isvirtual( data->props ) )
    return True;

  if( ( data->locId == NULL || StrOp.equals( data->locId, "") || StrOp.equals( data->locId, "?") ||
      StrOp.equals( data->locId, "GHOST")) && wBlock.isacceptghost( data->props ) ) {
    data->locId = "GHOST";
    data->ghost = True;
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Block:%s accepted a Ghosttrain", data->id );
    {
      iONode node = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
      wBlock.setid( node, data->id );
      wBlock.setlocid( node, data->locId );
      wBlock.setfifoids(node, wBlock.getfifoids(data->props));
      wBlock.setacceptident(node, data->acceptident);
      wBlock.setmasterid(node, wBlock.getmasterid(data->props));
      AppOp.broadcastEvent( node );
    }
    return True;
  }
  return False;
}


/**
 * translate the event name to an event code
 */
static int _getEventCode( iOBlock inst, const char* evtname ) {
  if( inst != NULL ) {
    iOBlockData data = Data(inst);
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "event [%s] in block [%s]", evtname, data->id );
  }

  if( StrOp.equals( evtname, wFeedbackEvent.free_event ) ) {
    return free_event;
  }
  else if( StrOp.equals( evtname, wFeedbackEvent.enter_event ) ) {
    return enter_event;
  }
  else if( StrOp.equals( evtname, wFeedbackEvent.enter2in_event ) ) {
    return enter2in_event;
  }
  else if( StrOp.equals( evtname, wFeedbackEvent.enter2shortin_event ) ) {
    return enter2shortin_event;
  }
  else if( StrOp.equals( evtname, wFeedbackEvent.enter2pre_event ) ) {
    return enter2pre_event;
  }
  else if( StrOp.equals( evtname, wFeedbackEvent.in_event ) ) {
    return in_event;
  }
  else if( StrOp.equals( evtname, wFeedbackEvent.exit_event ) ) {
    return exit_event;
  }
  else if( StrOp.equals( evtname, wFeedbackEvent.pre2in_event ) ) {
    return pre2in_event;
  }
  else if( StrOp.equals( evtname, wFeedbackEvent.occupied_event ) )
    return occupied_event;
  else if( StrOp.equals( evtname, wFeedbackEvent.ident_event ) )
    return ident_event;
  else if( StrOp.equals( evtname, wFeedbackEvent.shortin_event ) ) {
    return shortin_event;
  }
  else {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "unknown event=%s", evtname );
    return 0;
  }

}


/**
 * event listener callback for turntable events
 */
static void __TurntableEvent( obj inst, const char* event, const char* id ) {
  iOBlockData data = Data(inst);
  iOLoc loc = NULL;
  int evt = _getEventCode( (iOBlock)inst, event );

  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "Block:%s: ttid=%s event=%s",
      data->id, id, event );

  if( data->locId != NULL && StrOp.len( data->locId ) > 0 ) {
    iOModel model = AppOp.getModel();
    loc = ModelOp.getLoc( model, data->locId, NULL, False );
    if( loc != NULL )
      LocOp.event( loc, inst, evt, data->forceblocktimer?data->timer:0, data->forceblocktimer, NULL );
  }

}


static void __measureVelocity( iOBlock inst, int event ) {
  iOBlockData data = Data(inst);

  /*if( !wBlock.ismvactive( data->props ) )*/
  if( wBlock.getmvdistance(data->props) == 0 || wBlock.getmvscale(data->props) == 0 )
  {
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "measure velocity not set...");
    return;
  }
  else {
    time_t     t = time(NULL);
    int        ms = SystemOp.getMillis();

    if( event == enter_event ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "measure velocity enter event...");
      data->mvMillis = ms;
      data->mvTime   = t;
    }
    else if( event == in_event ) {
      int seconds = t - data->mvTime;
      int millis = seconds * 1000 + (ms - data->mvMillis);

      if( millis > 0 ) {
        float distanceMM = wBlock.getmvdistance(data->props) * wBlock.getmvscale(data->props);
        float factor = 3600000 / millis;
        float kmh =  (factor * distanceMM) / (1000*1000);

        if( wBlock.ismvmph( data->props ) ) {
        /* kmh * 0.621371192 = mph */
          data->mvspeed = kmh * 0.621371192;
          TraceOp.trc( name, TRCLEVEL_CALC, __LINE__, 9999,
              "average velocity of [%s] in block [%s] was %.1f MPH",
              data->locId, data->id, data->mvspeed);
        }
        else {
          data->mvspeed = kmh;
          TraceOp.trc( name, TRCLEVEL_CALC, __LINE__, 9999,
              "average velocity of [%s] in block [%s] was %.1f KM/H",
              data->locId, data->id, data->mvspeed);
        }
      }
    }
  }

}


static void _setGhostDetected(iIBlockBase inst, const char* key, const char* ident) {
  iOBlockData data = Data(inst);
  /* ghost train! */

  if( ModelOp.isAuto( AppOp.getModel() ) ) {
    if( !__acceptGhost((obj)inst) && !wBlock.isvirtual(data->props) ) {
      int tl = TRCLEVEL_USER1;
      data->ghost = True;

      if( wCtrl.ispoweroffatghost( AppOp.getIniNode( wCtrl.name() ) ) ) {
        iOControl control = AppOp.getControl();
        /* power off */
        if( !ControlOp.power4Block(control, data->id, False) )
          AppOp.stop();
        if( wCtrl.iscloseonghost(wFreeRail.getctrl( AppOp.getIni() ) ) )
          wBlock.setstate( data->props, wBlock.closed );
      }
      if( wCtrl.isebreakatghost( AppOp.getIniNode( wCtrl.name() ) ) ) {
        /* power off */
        AppOp.ebreak();
      }

      _resetTD(inst);

      /* broadcast ghost state */
      {
        iONode nodeD = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
        wBlock.setid( nodeD, data->id );
        wBlock.setstate( nodeD, wBlock.ghost );
        wBlock.setlocid( nodeD, data->locId );
        wBlock.setfifoids(nodeD, wBlock.getfifoids(data->props));
        wBlock.setacceptident(nodeD, data->acceptident);
        wBlock.setmasterid(nodeD, wBlock.getmasterid(data->props));
        AppOp.broadcastEvent( nodeD );
        __checkAction((iOBlock)inst, "ghost");
      }
      tl = TRCLEVEL_EXCEPTION;

      TraceOp.trc( name, tl, __LINE__, 9999, "Ghost train in block %s, fbid=%s, ident=%s",
          data->id, key, ident );

    }
  }

}


/**
 * event listener callback for all fbevents
 */
static Boolean _event( iIBlockBase inst, Boolean puls, const char* id, const char* ident, const char* ident2, const char* ident3, const char* ident4, int val, int wheelcount, iONode fbevt, Boolean dir ) {
  iOBlockData data = Data(inst);
  iOLoc        loc = NULL;
  obj      manager = (obj)(data->manager == NULL ? inst:data->manager);
  Boolean blockSide = False;
  Boolean countwheels = True;
  Boolean convertEnter2In = False;
  /* The use blockside option works only with one way type, so both directions will fail. */
  char    key[256] = {'\0'};

  if( StrOp.equals( wBlock.closed, wBlock.getstate( data->props ) ) && wBlock.issleeponclosed( data->props ) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "ignore event in sleep on closed block %s", data->id );
    return 0;
  }

  if( fbevt == NULL && data->byRouteId != NULL && StrOp.len(data->byRouteId) > 0 ) {
    iORoute byRoute = ModelOp.getRoute( AppOp.getModel(), data->byRouteId );
    blockSide = RouteOp.getToBlockSide(byRoute);

    StrOp.fmtb( key, "%s%s-%s-%s", id, puls?"":"-ep", data->fromBlockId != NULL ? data->fromBlockId:"", data->byRouteId );
    fbevt = (iONode)MapOp.get( data->fbEvents, key );
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "%sfbevent found by key %s", fbevt != NULL ? "":"no ", key);
  }

  if( fbevt == NULL ) {
    StrOp.fmtb( key, "%s%s-%s", id, puls?"":"-ep", data->fromBlockId != NULL ? data->fromBlockId:"" );
    /* event without description; look up in map */
    fbevt = (iONode)MapOp.get( data->fbEvents, key );
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "%sfbevent found by key %s", fbevt != NULL ? "":"no ", key);
  }


  if( fbevt == NULL ) {
    /* event without description; look up in map */
    if( ident != NULL && StrOp.len(ident) > 0 )
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "%s reports ident=[%s]", id, ident!=NULL?ident:"-");
    fbevt = ModPlanOp.getEvent4Block( NULL, NULL , data->props, data->fromBlockId, id);
  }

  if( fbevt == NULL ) {
    if ( blockSide )
      StrOp.fmtb( key, "%s%s-%s", id, puls?"":"-ep", wFeedbackEvent.from_all );
    else
      StrOp.fmtb( key, "%s%s-%s", id, puls?"":"-ep", wFeedbackEvent.from_all_reverse );
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "Block [%s] no event found for fromBlockId [%s], try to find one for all with key [%s]...",
        data->id, data->fromBlockId?data->fromBlockId:"?", key );
    fbevt = (iONode)MapOp.get( data->fbEvents, key );
  }

  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "Block[%s] id=%s fbid=%s state=%s ident=%s fbfrom=%s fbaction=%s from=%s byroute=%s",
      data->id, id, key, puls?"true":"false", ident != NULL ? ident:"-",
                 fbevt != NULL ? wFeedbackEvent.getfrom(fbevt):"NULL",
                 fbevt != NULL ? wFeedbackEvent.getaction(fbevt):"?",
                 data->fromBlockId?data->fromBlockId:"?",
                 data->byRouteId?data->byRouteId:"?" );

  if( data->crossing ) {
    /* ignore all events */
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "ignore events for crossing block %s", data->id );
    return False;
  }

  if( data->locId != NULL && StrOp.len( data->locId ) > 0 ) {
    iOModel model = AppOp.getModel(  );
    int evt = 0;
    if( wBlock.getfifosize(data->props) > 0 && ListOp.size(data->fifoList) > 1 ) {
      if( fbevt != NULL ) {
        evt = _getEventCode( (iOBlock)inst, wFeedbackEvent.getaction( fbevt ) );
      }

      if( evt == in_event ) {
        loc = ModelOp.getLoc( model, (const char*)ListOp.get(data->fifoList, 0), NULL, False );
        if( loc != NULL ) {
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "in event for fifo automobile %s in block %s", LocOp.getId(loc), data->id );
        }
      }
      else {
        iOLoc loc1 = ModelOp.getLoc( model, (const char*)ListOp.get(data->fifoList, 0), NULL, False );
        loc = ModelOp.getLoc( model, (const char*)ListOp.get(data->fifoList, ListOp.size(data->fifoList)-1), NULL, False );
        __dumpFiFo(inst);
        if( loc != NULL ) {
          Boolean oppwait = False;
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "event for fifo automobile %s in block %s (Vmid)", LocOp.getId(loc), data->id );
          convertEnter2In = True;
          LocOp.stop(loc, False);

          if( BlockOp.wait( inst, loc, False, &oppwait ) || ( loc1!=NULL && StrOp.equals(wLoc.mode_wait, wLoc.getmode( LocOp.base.properties(loc1))) )  ) {
            iONode cmd = NodeOp.inst(wLoc.name(), NULL, ELEMENT_NODE);
            wLoc.setcmd(cmd, wLoc.velocity);
            wLoc.setV_hint(cmd, wLoc.mid);
            LocOp.cmd(loc, cmd);
          }
        }
      }
    }
    else
      loc = ModelOp.getLoc( model, data->locId, NULL, False );
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "loco [%s] %sfound", data->locId, loc==NULL?"NOT ":"" );
  }
  else {
    TraceOp.trc( name, puls?TRCLEVEL_INFO:TRCLEVEL_USER1, __LINE__, 9999, "locId not set in block %s", data->id );
  }

  /* handle a dedicated ident event */
  if( wCtrl.isusebicom( wFreeRail.getctrl( AppOp.getIni())) ) {
    /*if( fbevt != NULL && _getEventCode( wFeedbackEvent.getaction( fbevt ) ) == ident_event ) {*/
    /*if( fbevt != NULL && ident > 0 ) {*/
    if( ident != NULL && StrOp.len(ident) > 0 ) {
      /* Set in block if a loco was found with the ident. */
      if( wCtrl.isuseident( wFreeRail.getctrl( AppOp.getIni())) ) {
        iOModel model = AppOp.getModel(  );
        iOLoc identLoc = ModelOp.getLocByIdent(model, ident, NULL, NULL, NULL, dir);
        if( (identLoc != NULL && data->acceptident ) || (identLoc != NULL && !ModelOp.isAuto(model)) ) {
            iONode cmd = NULL;
            iONode locoProps = LocOp.base.properties(identLoc);
            if( !ModelOp.isAuto(model) && !LocOp.isAutomode(identLoc) && !wItem.isgenerated(locoProps) ) {
              if(wCtrl.isusebididir(wFreeRail.getctrl( AppOp.getIni()))) {
                /* set bidi direction flag */
                TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "set loco %s bidi direction to %s", LocOp.getId(identLoc), dir?"fwd":"rev" );
                wLoc.setplacing(locoProps, dir);
              }
            }

            if( !StrOp.equals( LocOp.getId(identLoc), data->locId ) && !LocOp.isAutomode(identLoc) ) {
              if( loc != NULL ) {
                iONode cmd = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
                wBlock.setid( cmd, data->id );
                wBlock.setlocid( cmd, "" );
                wBlock.setcmd( cmd, wBlock.loc );
                TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "remove loco %s from block %s", LocOp.getId(loc), data->id );
                inst->cmd(inst, cmd);
              }

              /* broadcast end of acceptident */
              if( data->acceptident != wBlock.isacceptident(data->props) ) {
                iONode nodeD = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
                wBlock.setid( nodeD, data->id );
                wBlock.setacceptident(nodeD, data->acceptident);
                wBlock.setmasterid(nodeD, wBlock.getmasterid(data->props));
                AppOp.broadcastEvent( nodeD );

                wBlock.setacceptident(data->props, data->acceptident);
              }

              /* Inform Rocrail... */
              cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
              wLoc.setid( cmd, LocOp.getId(identLoc) );
              wLoc.setcmd( cmd, wLoc.block );
              wLoc.setblockid( cmd, data->id );
              TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "set loco %s in block %s", LocOp.getId(identLoc), data->id );
              LocOp.cmd( identLoc, cmd );
              loc = identLoc;
              __checkAction((iOBlock)inst, "acceptident");
            }

          /*}*/
        }


        /* check for a car */
        if( identLoc == NULL ) {
          iOCar identCar = ModelOp.getCarByIdent(model, ident);
          if( identCar != NULL ) {
            CarOp.setLocality( identCar, data->id );
          }
        }

      }
      else {
        iONode nodeD = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
        wBlock.setid( nodeD, data->id );
        wBlock.setlocid( nodeD, puls ? ident:data->locId );
        wBlock.setfifoids(nodeD, wBlock.getfifoids(data->props));
        wBlock.setacceptident(nodeD, data->acceptident);
        wBlock.setmasterid(nodeD, wBlock.getmasterid(data->props));
        AppOp.broadcastEvent( nodeD );
      }
    }

  }
  else if( StrOp.len(ident) > 0 ){
    /* reset ident */
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "reset ident[%s] in block[%s] to zero; bi-com is disabled", ident, data->id);
    ident = "";
  }

  if( fbevt != NULL && puls == !wFeedbackEvent.isendpuls( fbevt ) && loc != NULL ) {
    int evt = _getEventCode( (iOBlock)inst, wFeedbackEvent.getaction( fbevt ) );
    const char* locident = LocOp.getIdent(loc);

    __measureVelocity( (iOBlock)inst, evt );

    if( (StrOp.len(ident) > 0 && StrOp.len(locident) > 0 && !StrOp.equals(ident, locident)) ||
        (StrOp.len(ident) > 0 && StrOp.len(locident) == 0) )
    {
      /* TODO: Check MU consist */
      if( LocOp.matchIdent(loc, ident, ident2, ident3, ident4) ) {
        TraceOp.trc( name, TRCLEVEL_CALC, __LINE__, 9999, "ident matched: block=%s loc(MU)=[%s] ident=[%s]",
            data->id, locident, ident );
      }
      else if (StrOp.len(ident) > 0 && atoi(ident) > 0) {
        TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Loc identifier does not match! block=%s locident=[%s] ident=[%s]",
            data->id, locident, ident );
        /* Power off? */
        if( wCtrl.ispoweroffonidentmismatch( AppOp.getIniNode( wCtrl.name() ) ) ) {
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "power off for mismatching ident" );
          AppOp.stop();
        }
      }
    }
    else if( StrOp.len(ident) > 0 && StrOp.len(locident) > 0 && StrOp.equals(ident, locident) ) {
      TraceOp.trc( name, TRCLEVEL_CALC, __LINE__, 9999, "ident matched: block=%s locident=[%s] ident=[%s]",
          data->id, locident, ident );
    }

    if( convertEnter2In && evt == enter_event ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "convert the enter event to a enter2in event" );
      evt = enter2in_event;
    }

    if( evt == enter2in_event ) {
      int timing = wFeedbackEvent.isuse_timer2( fbevt ) ? data->timer2:data->timer;
      LocOp.event( loc, manager, enter_event, 0, data->forceblocktimer, wFeedbackEvent.getid(fbevt) );
      if( data->indelay > 0 )
        LocOp.event( loc, manager, in_event, data->indelay, data->forceblocktimer, wFeedbackEvent.getid(fbevt) );
      else
        LocOp.event( loc, manager, in_event, timing > 0 ? timing:1, data->forceblocktimer, wFeedbackEvent.getid(fbevt) );
    }
    if( evt == enter2shortin_event ) {
      int timing = wFeedbackEvent.isuse_timer2( fbevt ) ? data->timer2:data->timer;
      LocOp.event( loc, manager, enter_event, 0, data->forceblocktimer, wFeedbackEvent.getid(fbevt) );
      if( data->indelay > 0 )
        LocOp.event( loc, manager, shortin_event, data->indelay, data->forceblocktimer, wFeedbackEvent.getid(fbevt) );
      else
        LocOp.event( loc, manager, shortin_event, timing > 0 ? timing:1, data->forceblocktimer, wFeedbackEvent.getid(fbevt) );
    }
    else if(evt == enter2pre_event ) {
      int timing = wFeedbackEvent.isuse_timer2( fbevt ) ? data->timer2:data->timer;
      LocOp.event( loc, manager, enter_event, 0, data->forceblocktimer, wFeedbackEvent.getid(fbevt) );
      if( data->indelay > 0 )
        LocOp.event( loc, manager, pre2in_event, data->indelay, data->forceblocktimer, wFeedbackEvent.getid(fbevt) );
      else
        LocOp.event( loc, manager, pre2in_event, timing > 0 ? timing:1, data->forceblocktimer, wFeedbackEvent.getid(fbevt) );
    }
    else if( evt == pre2in_event ) {
      int timing = wFeedbackEvent.isuse_timer2( fbevt ) ? data->timer2:data->timer;
      LocOp.event( loc, manager, pre2in_event, timing, data->forceblocktimer, wFeedbackEvent.getid(fbevt) );
    }
    else if( evt == in_event ) {
      int timing = wFeedbackEvent.isuse_timer2( fbevt ) ? data->timer2:data->timer;
      if( data->indelay > 0 ){
        /* an in event delay can be set with lock for a schedule entry */
        LocOp.event( loc, manager, in_event, data->indelay, data->forceblocktimer, wFeedbackEvent.getid(fbevt) );
        data->indelay = 0;
      }
      else {
        LocOp.event( loc, manager, in_event, timing, data->forceblocktimer, wFeedbackEvent.getid(fbevt) );
      }
      /* reset wheel counter */
      {
        iOFBack fb = ModelOp.getFBack( AppOp.getModel(), data->wheelcounterId );
        if( fb != NULL ) {
          FBackOp.resetCounter(fb);
        }
      }
      countwheels = False;
    }
    else
      LocOp.event( loc, manager, evt, 0, data->forceblocktimer, wFeedbackEvent.getid(fbevt) );

    if( evt == enter2shortin_event || evt == enter2in_event || evt == in_event ) {
      /* TODO: check if the shortin_event does not ruin the auto mode */
      data->fromBlockId = data->id;
    }

    if( evt == shortin_event && LocOp.isShortin(loc) ) {
      data->fromBlockId = data->id;
    }

  }
  else if( data->fromBlockId == NULL && puls && loc == NULL ) {
    /* ghost train! */
    _setGhostDetected(inst, key, ident);
  }
  else if( data->fromBlockId == NULL && !puls && loc == NULL && data->ghost ) {
    /* ghost train! */
    /* broadcast ghost state */
    if( __isElectricallyFree((iOBlock)inst) ) {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Ghost train no longer in block %s, fbid=%s, ident=%s",
          data->id, key, ident );

      if( !wCtrl.iskeepghost( AppOp.getIniNode( wCtrl.name() ) ) ) {

        data->ghost = False;

        if(StrOp.equals( data->locId, "GHOST")) {
          data->locId = NULL;
        }

        {
          iONode nodeD = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
          wBlock.setid( nodeD, data->id );
          wBlock.setstate( nodeD, wBlock.getstate(data->props) );
          wBlock.setlocid( nodeD, data->locId );
          wBlock.setfifoids(nodeD, wBlock.getfifoids(data->props));
          wBlock.setacceptident(nodeD, data->acceptident);
          wBlock.setmasterid(nodeD, wBlock.getmasterid(data->props));
          AppOp.broadcastEvent( nodeD );
        }
      }
    }
    else {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Ghost train still remains in block %s, fbid=%s, ident=%s",
          data->id, key, ident );
    }
  }
  else if( fbevt == NULL && data->fromBlockId != NULL ) {
    /* undefined event! */
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "Sensor %s in block %s is undefined! ident=%s fromBlockId=%s",
                   key, data->id, ident, data->fromBlockId );
    countwheels = False;
  }
  else {
    /* unhandled event! */
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "unhandled sensor [%s] in block [%s]! puls=[%d], ident=[%s], ghost=[%d], loc=[%s], fromBlockId=[%s]",
                   key, data->id, puls, ident, data->ghost,
                   (loc == NULL ? "NULL":LocOp.getId(loc)),
                   (data->fromBlockId == NULL ? "NULL":data->fromBlockId) );
    countwheels = False;
  }
  return countwheels;
}

static void _fbEvent( obj inst, Boolean puls, const char* id, const char* ident, const char* ident2, const char* ident3, const char* ident4, int val, int wheelcount, Boolean dir ) {
  iOBlockData data = Data(inst);

  if( _event( (iIBlockBase)inst, puls, id, ident, ident2, ident3, ident4, val, wheelcount, NULL, dir ) ) {
    if( wheelcount > 0 ) {
      data->wheelcount = wheelcount;
      data->wheelcounterId = id;
    }
  }

  if( data->pendingFree ) {
    if( __isElectricallyFree((iOBlock)inst) ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "block [%s] is finally unlocked", data->id );
      data->pendingFree = False;
    }
  }
}


static void _setCarCount( iIBlockBase inst, int count ) {
  iOBlockData data = Data(inst);
  iOModel model = AppOp.getModel();
  iONode fbevt = wBlock.getfbevent( data->props );

  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "[%s] CAR COUNT = %d", data->id, count );

  while( fbevt != NULL ) {
    const char* fbid = wFeedbackEvent.getid( fbevt );
    const char* byroute = wFeedbackEvent.getbyroute( fbevt );
    iOFBack fb = ModelOp.getFBack( model, fbid );
    if( fb != NULL ) {
      FBackOp.setCarCount( fb, count );
    }
    else {
      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "block[%s]: feedback[%s] does not exist", data->id, fbid );
    }
    fbevt = wBlock.nextfbevent( data->props, fbevt );
  };
}


/**
 * map all fbevent's and set the listener to the common __fbEvent
 */
static void __resetFeedbackEvents( iOBlock inst ) {
  iOBlockData data = Data(inst);
  iOModel model = AppOp.getModel();
  char key[256] = {'\0'};
  iONode fbevt = wBlock.getfbevent( data->props );

  MapOp.clear( data->fbEvents );

  while( fbevt != NULL ) {
    const char* fbid = wFeedbackEvent.getid( fbevt );
    const char* byroute = wFeedbackEvent.getbyroute( fbevt );
    Boolean endpuls = wFeedbackEvent.isendpuls( fbevt );
    iOFBack fb = ModelOp.getFBack( model, fbid );

    if( fb != NULL )
      FBackOp.removeListener( fb, (obj)inst );

    fbevt = wBlock.nextfbevent( data->props, fbevt );
  }
}

static void __initFeedbackEvents( iOBlock inst ) {
  iOBlockData data = Data(inst);
  iOModel model = AppOp.getModel();
  char key[256] = {'\0'};
  iONode fbevt = wBlock.getfbevent( data->props );

  MapOp.clear( data->fbEvents );

  while( fbevt != NULL ) {
    const char* fbid = wFeedbackEvent.getid( fbevt );
    const char* byroute = wFeedbackEvent.getbyroute( fbevt );
    Boolean endpuls = wFeedbackEvent.isendpuls( fbevt );
    iOFBack fb = ModelOp.getFBack( model, fbid );

    if( StrOp.len( fbid ) > 0 && fb != NULL ) {
      iOStrTok tok = StrTokOp.inst( wFeedbackEvent.getfrom( fbevt ), ',' );

      /* put all blockid's in the map */
      while( StrTokOp.hasMoreTokens(tok) ) {
        const char* fromblockid = StrTokOp.nextToken( tok );
        if( byroute != NULL && StrOp.len( byroute ) > 0 && !StrOp.equals( wFeedbackEvent.from_all, byroute) && !StrOp.equals( wFeedbackEvent.from_all_reverse, byroute) )
          StrOp.fmtb( key, "%s%s-%s-%s", fbid, endpuls?"-ep":"", fromblockid, byroute );
        else
          StrOp.fmtb( key, "%s%s-%s", fbid, endpuls?"-ep":"", fromblockid );
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "fbevent added by key [%s]", key);
        MapOp.put( data->fbEvents, key, (obj)fbevt );
      };
      StrTokOp.base.del(tok);

      /*FBackOp.setListener( fb, (obj)inst, &_fbEvent );*/
      FBackOp.addListener( fb, (obj)inst );
    }
    fbevt = wBlock.nextfbevent( data->props, fbevt );
  };

  if( wBlock.getttid(data->props) != NULL && StrOp.len(wBlock.getttid(data->props)) > 0 ) {
    iOTT tt = ModelOp.getTurntable( model, wBlock.getttid(data->props) );
    if( tt != NULL )
      TTOp.setListener( tt, (obj)inst, &__TurntableEvent );
  }

}


/*
 ***** _Public functions.
 */
static Boolean _setListener( iOBlock inst, obj listenerObj, const block_listener listenerFun ) {
  iOBlockData data = Data(inst);
  data->listenerObj = listenerObj;
  data->listenerFun = listenerFun;
  return True;
}

static const char* _getFromBlockId( iIBlockBase inst ) {
  iOBlockData data = Data(inst);
  return data->fromBlockId;
}


static const char* _getTDiid( iIBlockBase inst ) {
  iOBlockData data = Data(inst);
  return wBlock.getiid( data->props );
}


static int _getTDaddress( iIBlockBase inst ) {
  iOBlockData data = Data(inst);
  return wBlock.getaddr( data->props );
}


static int _getTDport( iIBlockBase inst ) {
  iOBlockData data = Data(inst);
  return wBlock.getport( data->props );
}


static void _setAnalog( iIBlockBase inst, Boolean analog ) {
  iOBlockData data = Data(inst);
  iOControl control = AppOp.getControl();
  /* setAlalog */
  iONode cmd = NodeOp.inst( wSysCmd.name(), NULL, ELEMENT_NODE );
  wSysCmd.setcmd( cmd, analog?wSysCmd.analog:wSysCmd.dcc );
  wSysCmd.setiid( cmd, wBlock.getiid( data->props ) );
  wSysCmd.setid( cmd, wBlock.getid( data->props ) );
  wSysCmd.setaddr( cmd, wBlock.getaddr( data->props ) );
  wSysCmd.setport( cmd, wBlock.getport( data->props ) );
  ControlOp.cmd( control, cmd, NULL );
}


static Boolean _setManual( iOBlock inst, Boolean manual ) {
  iOBlockData data = Data(inst);
  iOControl control = AppOp.getControl();
  /* setManual TODO: check if block is already used for auto-mode... */
  wBlock.setmanual( data->props, manual );
  return True;
}


static void _setManager( iIBlockBase inst, iIBlockBase manager ) {
  iOBlockData data = Data(inst);
  data->manager = manager;
  if( manager != NULL )
    wBlock.setmanagerid( data->props, manager->base.id(manager) );
  else
    wBlock.setmanagerid( data->props, "" );
}


static iIBlockBase _getManager( iIBlockBase inst ) {
  iOBlockData data = Data(inst);
  return data->manager;
}


static Boolean _isReady( iIBlockBase inst ) {
  iOBlockData data = Data(inst);
  return True;
}


static Boolean _isFreeBlockOnEnter( iIBlockBase inst ) {
  iOBlockData data = Data(inst);
  return wBlock.isfreeblockonenter( data->props );
}


static Boolean _hasExtStop( iIBlockBase inst, const char* locoid ) {
  iOBlockData data = Data(inst);
  if( wBlock.getfifosize(data->props) > 0 && ListOp.size(data->fifoList) > 1 ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "fifo block [%s] fifo0departing=%s inPending=%s",
        data->id, data->fifo0departing ? "false":"true", data->inPending ? "true":"false");
    if( data->inPending && locoid != NULL ) {
      const char* firstFifo = (const char*)ListOp.get(data->fifoList, 0);
      if( StrOp.equals(locoid, firstFifo) ) {
        data->inPending = False;
        return False;
      }
    }
    return (data->fifo0departing ? False:True);
  }
  return wBlock.isextstop(data->props);
}


static Boolean _allowBBT( iIBlockBase inst ) {
  iOBlockData data = Data(inst);
  return wBlock.isallowbbt(data->props);
}


static Boolean __isElectricallyFree(iOBlock inst) {
  iOBlockData data = Data(inst);
  /* check all sensors... */

  iONode fbevt = wBlock.getfbevent( data->props );
  Boolean shunting = StrOp.equals( wBlock.type_shunting, wBlock.gettype(data->props) );


  while( fbevt != NULL ) {
    iOFBack fb = ModelOp.getFBack( AppOp.getModel(), wFeedbackEvent.getid(fbevt));
    if( fb != NULL && FBackOp.getState(fb) && _getEventCode( inst, wFeedbackEvent.getaction( fbevt ) ) != ident_event ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 5001,
                     "Block [%s] is electrically occupied by sensor [%s]. %s",
                     data->id, FBackOp.getId(fb), shunting ? "(ignored for shunting)":"" );

      if( !shunting )
        return False;
    }
    fbevt = wBlock.nextfbevent( data->props, fbevt );
  };

  return True;
}


static Boolean _isState( iIBlockBase inst, const char* state ) {
  iOBlockData data = Data(inst);
  if( StrOp.equals( "free", state ) ) {
    if( data->locId == NULL || StrOp.len( data->locId ) == 0 )
      return True;
  }

  if( StrOp.equals( "!free", state ) || StrOp.equals( "occupied", state ) ) {
    if( data->locId != NULL && StrOp.len( data->locId ) > 0 )
      return True;
  }

  if( StrOp.equals( wBlock.closed, state ) ) {
      return StrOp.equals( wBlock.closed, wBlock.getstate( data->props ) );
  }

  if( StrOp.equals( wBlock.open, state ) ) {
      return StrOp.equals( wBlock.open, wBlock.getstate( data->props ) );
  }

  return False;
}


static Boolean __hasShortcut(iIBlockBase inst) {
  iOBlockData data = Data(inst);
  Boolean shortcut = False;
  iONode fbevt = wBlock.getfbevent( data->props );

  while( fbevt != NULL ) {
    const char* fbid = wFeedbackEvent.getid( fbevt );
    iOFBack fb = ModelOp.getFBack( AppOp.getModel(), fbid );
    if(fb != NULL && FBackOp.hasShortcut(fb)) {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Sensor [%s] is short-circuited", fbid );
      shortcut = True;
    }
    fbevt = wBlock.nextfbevent( data->props, fbevt );
  };
  return shortcut;
}

static Boolean _isFree( iIBlockBase inst, const char* locId ) {
  iOBlockData data = Data(inst);

  if( wBlock.getfifosize(data->props) > 0 && !data->arrivalPending && locId != NULL && !StrOp.equals( wBlock.getstate( data->props ), wBlock.closed ) ) {
    iOLoc lc = ModelOp.getLoc( AppOp.getModel(), locId, NULL, False );
    if( lc != NULL && StrOp.equals( wLoc.engine_automobile, LocOp.getEngine(lc)) && ListOp.size(data->fifoList) < wBlock.getfifosize(data->props) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
          "fifo block [%s] has room free for automobile [%s] idx=%d", data->id, LocOp.getId(lc), ListOp.size(data->fifoList) );
      __dumpFiFo(inst);
      return True;
    }
  }

  if( data->pendingFree ) {
    if( !__isElectricallyFree((iOBlock)inst) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "block [%s] waits to get electrically free", data->id );
      return False;
    }
    else {
      data->pendingFree = False;
    }
  }

  if( wBlock.isvirtual(data->props) ) {
    Boolean Free = True;
    iOStrTok tok = StrTokOp.inst( wBlock.getslaveblocks(data->props), ',' );

    while( StrTokOp.hasMoreTokens(tok) ) {
      const char* blockid = StrTokOp.nextToken( tok );
      iIBlockBase bk = ModelOp.getBlock( AppOp.getModel(), blockid);
      if( bk != NULL ) {
        if( !bk->isFree( bk, locId ) ) {
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "virtual block [%s] slave block [%s] is not free", wBlock.getid(data->props), blockid );
          Free = False;
          break;
        }
      }
    };
    StrTokOp.base.del(tok);
    if(!Free) {
      return False;
    }
  }



  if( wBlock.getfbevent( data->props ) == NULL && data->manager == NULL && wCtrl.isclosenoevents(wFreeRail.getctrl( AppOp.getIni() ) ) ) {
    iONode nodeD = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
    wBlock.setstate(data->props, wBlock.closed);

    wBlock.setid( nodeD, data->id );
    wBlock.setfifoids(nodeD, wBlock.getfifoids(data->props));
    wBlock.setstate( nodeD, wBlock.getstate(data->props) );
    wBlock.setmasterid(nodeD, wBlock.getmasterid(data->props));
    AppOp.broadcastEvent( nodeD );

    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "No events defined for block [%s]; Closed.", data->id );
    return False;
  }

  if( wBlock.isremote(data->props) ) {
    iOR2Rnet r2rnet = ControlOp.getR2Rnet(AppOp.getControl());
    if( r2rnet != NULL ) {
      iOLoc lc = ModelOp.getLoc( AppOp.getModel(), locId, NULL, False );
      return R2RnetOp.reserveBlock(r2rnet, wBlock.getrrid(data->props), wBlock.getid(data->props), NULL, lc->base.properties(lc), NULL, True );
    }
  }
  else {
    if( StrOp.equals( wBlock.getstate( data->props ), wBlock.closed ) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "Block [%s] is closed!.", data->id );
      return False;
    }

    if( locId != NULL && StrOp.equals( locId, data->locId ) )
      return True;

  /* check all sensors... */
    if( __hasShortcut(inst) ) {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
                     "Block [%s] has a short circuit reported.",
                     data->id );
      return False;
    }

    if( !__isElectricallyFree((iOBlock)inst) ) {
      if( data->locId == NULL || StrOp.len( data->locId ) == 0 ) {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Block [%s] is electrically occupied without locId set!", data->id );

        /* Broadcast to clients. */
        if( !wBlock.isacceptghost( data->props ) && wCtrl.iscloseonghost(wFreeRail.getctrl( AppOp.getIni() ))) {
          iONode nodeD = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
          wBlock.setstate(data->props, wBlock.closed);
          wBlock.setid( nodeD, data->id );
          wBlock.setstate( nodeD, wBlock.getstate(data->props) );
          wBlock.setmasterid(nodeD, wBlock.getmasterid(data->props));
          AppOp.broadcastEvent( nodeD );
        }
      }
      return False;
    }

    if( !StrOp.equals( wBlock.type_shunting, wBlock.gettype(data->props) ) ) {
      if( ModelOp.hasBlockCars( AppOp.getModel(), data->id ) ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Block [%s] is occupied by cars", data->id);
      }
    }

    if( data->locId == NULL || StrOp.len( data->locId ) == 0 || StrOp.equals( "(null)", data->locId ) )
      return True;
    else if( data->locId != NULL ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "Block [%s] is reserved by [%s]", data->id, data->locId );
    }

    return False;
  }

  return False;
}


static const char* _getVelocity( iIBlockBase inst, int* percent, Boolean onexit, Boolean reverse, Boolean onstop ) {
  iOBlockData data    = Data(inst);
  iOSignal    signal  = (iOSignal)inst->hasManualSignal(inst, False, reverse );
  iOSignal    distand = (iOSignal)inst->hasManualSignal(inst, True, reverse );
  const char* V_hint  = wBlock.getspeed(data->props);

  *percent = wBlock.getspeedpercent(data->props);

  if( onexit ) {
    V_hint  = wBlock.getexitspeed(data->props);
    *percent = wBlock.getexitspeedpercent(data->props);
  }
  else if( onstop ) {
    if( !StrOp.equals( V_hint, wBlock.min ) )
      V_hint  = wBlock.getstopspeed(data->props);
    *percent = wBlock.getspeedpercent(data->props);
  }


  /* check for manual operated signals */
  if( onexit && signal != NULL && SignalOp.isState( signal, wSignal.yellow) ) {
    if( !StrOp.equals( wBlock.getspeed( data->props ), wBlock.min ) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
          "set block %s velocity to Vmid for %s aspect of signal %s",
          inst->base.id(inst),
          wSignal.yellow,
          signal->base.id(signal) );
      return wBlock.mid;
    }
  }
  else if( !onexit && distand != NULL && SignalOp.isState( distand, wSignal.red) ) {
    if( !StrOp.equals( wBlock.getspeed( data->props ), wBlock.min ) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
          "set block %s velocity to Vmid for %s aspect of signal %s",
          inst->base.id(inst),
          wSignal.red,
          distand->base.id(distand) );
      return wBlock.mid;
    }
  }
  return V_hint;
}


static int _getDepartDelay( iIBlockBase inst ) {
  iOBlockData data = Data(inst);
  return wBlock.getdepartdelay(data->props) ;
}

static float _getmvspeed( iIBlockBase inst ) {
  iOBlockData data = Data(inst);
  return data->mvspeed;
}

static int _getMaxKmh( iIBlockBase inst ) {
  iOBlockData data = Data(inst);
  return wBlock.getmaxkmh(data->props);
}


static int _getWait( iIBlockBase inst, iOLoc loc, Boolean reverse, int* oppwait ) {
  iOBlockData data = Data(inst);
  iOSignal signal = NULL;
  iOSignal oppsignal = NULL;

  Boolean bkeside = wLoc.isblockenterside( (iONode)loc->base.properties( loc ) );
  signal = (iOSignal)inst->hasManualSignal(inst, False, !bkeside );
  oppsignal = (iOSignal)inst->hasManualSignal(inst, False, bkeside );

  /* check the manual operated signal */
  if( oppsignal != NULL && SignalOp.isState(oppsignal, wSignal.red) ) {
    *oppwait = -1; /* wait until it is set to green */
  }
  else if( oppsignal != NULL ) {
    *oppwait = 0;
  }

  if( signal != NULL && SignalOp.isState(signal, wSignal.red) ) {
    if( oppsignal == NULL )
      *oppwait = -1;
    return -1; /* wait until it is set to green */
  }
  else if( signal != NULL ) {
    if( oppsignal == NULL )
      *oppwait = 0;
    return 0;
  }

  if( StrOp.equals( wLoc.cargo_cleaning, LocOp.getCargo(loc) ) ){
    return (data->tempwait?1:0);
  }
  else if( LocOp.isGoManual(loc) && wCtrl.isdisableblockwait4gomanual( AppOp.getIniNode( wCtrl.name() ) ) ){
    return (data->tempwait?1:0);
  }
  else if( wLoc.isuseownwaittime( (iONode)loc->base.properties( loc ) ) ) {
    return wLoc.getblockwaittime( (iONode)loc->base.properties( loc ) );
  }
  else if( StrOp.equals( wBlock.wait_random, wBlock.getwaitmode( data->props ) ) ) {
    /* Random between 1 and 30. */
    int min = wBlock.getminwaittime( data->props );
    int max = wBlock.getmaxwaittime( data->props );
    float fmax = max;
    int rwait = 0;
    if( max < min ) {
      fmax = min;
      min = max;
    }
    rwait = min + (int) (fmax*rand()/(RAND_MAX+1.0));
    return rwait;
  }
  else if( StrOp.equals( wBlock.wait_loc, wBlock.getwaitmode( data->props ) ) ) {
    if( data->tempwait && wLoc.getblockwaittime( (iONode)loc->base.properties( loc ) ) == 0 )
      return 1;
    return wLoc.getblockwaittime( (iONode)loc->base.properties( loc ) );
  }
  else {
    if( data->tempwait && wBlock.getwaittime( data->props ) == 0 )
      return 1;
    return wBlock.getwaittime( data->props ) ;
  }
}

static Boolean _isTTBlock( iIBlockBase inst ) {
  iOBlockData data = Data(inst);
  const char* ttId = wBlock.getttid( data->props );
  if( ttId != NULL && StrOp.len( ttId ) > 0 )
    return True;
  return False;
}


static void _setTempWait(iIBlockBase inst, Boolean wait) {
  iOBlockData data = Data(inst);
  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "set tempwait=%d in block [%s]", wait, data->id );
  data->tempwait = wait;
}

/* cross checking block and train types */
static block_suits __crossCheckType(iOBlock block, iOLoc loc, Boolean* wait, Boolean checkPrev) {
  iOBlockData data = Data(block);
  const char* traintype = LocOp.getCargo(loc);
  const char* blocktype = wBlock.gettype( BlockOp.base.properties(block) );
  Boolean     blockwait = (wBlock.iswait(BlockOp.base.properties(block) ) | data->tempwait);
  Boolean     ttwait    = False;
  const char* ttId = wBlock.getttid( BlockOp.base.properties(block) );

  /* always wait in block if it contains a turntable */
  if( ttId != NULL && StrOp.len( ttId ) > 0 ) {
    blockwait = True;
    ttwait    = True;
  }

  if( wait != NULL )
    *wait = blockwait;

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
                 "wait in block \"%s\" is %s",
                 data->id, blockwait?"true":"false" );

  /* first handle the special train types */
  /* cleaning should go through all blocks and not wait */
  if( StrOp.equals( wLoc.cargo_cleaning, traintype ) ) {
    if( wait != NULL )
      *wait = ttwait;
    if( checkPrev && data->prevLocId != NULL ) {
      const char* locid = LocOp.getId( loc );
      if( StrOp.equals( data->prevLocId, locid ) ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                       "Block \"%s\" is last visited by \"%s\"",
                       data->id, locid );
        return suits_ok;
      }
      else
        return suits_well;
    }
    else
      return suits_well;
  }
  /* all (hidden cleaning) should go through all blocks and wait */
  if( StrOp.equals( wLoc.cargo_all, traintype ) ) {
    if( wait != NULL )
      *wait = blockwait;
    return suits_well;
  }


  /* undefined block type */
  if( StrOp.equals( wBlock.type_none, blocktype ) || ( ttId != NULL && StrOp.len( ttId ) > 0 ) ) {
    return suits_well;
  }

  /* first check for best destinations */
  if( StrOp.equals( wBlock.type_local, blocktype ) && (
        StrOp.equals( wLoc.cargo_person, traintype ) ||
        StrOp.equals( wLoc.cargo_mixed, traintype ) ) )
    return suits_well;

  if( StrOp.equals( wBlock.type_ice, blocktype ) &&
        StrOp.equals( wLoc.cargo_ice, traintype ) )
    return suits_well;

  if( StrOp.equals( wBlock.type_goods, blocktype ) && (
        StrOp.equals( wLoc.cargo_goods, traintype ) ||
        StrOp.equals( wLoc.cargo_mixed, traintype ) ) )
    return suits_well;

  if( StrOp.equals( wBlock.type_shunting, blocktype ) &&
        StrOp.equals( wLoc.cargo_none, traintype ) )
    return suits_well;

  if( StrOp.equals( wBlock.type_regional, blocktype ) &&
        StrOp.equals( wLoc.cargo_regional, traintype ) )
    return suits_well;

  if( StrOp.equals( wBlock.type_light, blocktype ) &&
        StrOp.equals( wLoc.cargo_light, traintype ) )
    return suits_well;

  if( StrOp.equals( wBlock.type_lightgoods, blocktype ) &&
        StrOp.equals( wLoc.cargo_lightgoods, traintype ) )
    return suits_well;

  if( StrOp.equals( wBlock.type_post, blocktype ) &&
        StrOp.equals( wLoc.cargo_post, traintype ) )
    return suits_well;

  /* then check for alternative destinations that are compatible enough for a wait */
  if( StrOp.equals( wBlock.type_local, blocktype ) && (
        StrOp.equals( wLoc.cargo_light, traintype ) ||
        StrOp.equals( wLoc.cargo_regional, traintype ) ) )
    return suits_ok;

  if( StrOp.equals( wBlock.type_ice, blocktype ) &&
        StrOp.equals( wLoc.cargo_regional, traintype ) )
    return suits_ok;

  if( StrOp.equals( wBlock.type_goods, blocktype ) &&
        StrOp.equals( wLoc.cargo_lightgoods, traintype ) )
    return suits_ok;

  if( StrOp.equals( wBlock.type_regional, blocktype ) && (
        StrOp.equals( wLoc.cargo_ice, traintype ) ||
        StrOp.equals( wLoc.cargo_light, traintype ) ||
        StrOp.equals( wLoc.cargo_person, traintype ) ) )
    return suits_ok;

  if( StrOp.equals( wBlock.type_light, blocktype ) &&
        StrOp.equals( wLoc.cargo_person, traintype ) )
    return suits_ok;

  if( StrOp.equals( wBlock.type_lightgoods, blocktype ) &&
        StrOp.equals( wLoc.cargo_goods, traintype ) )
    return suits_ok;

  /* all other alternative destinations are not compatible enough for a wait */
  if( wait != NULL )
    *wait = False;

  return suits_ok;
}


static int _isSuited( iIBlockBase inst, iOLoc loc, int* restlen, Boolean checkPrev ) {
  iOBlockData data = Data(inst);
  /* ToDo: Check if loc can run in this block. */

  int bklen = wBlock.getlen( data->props );
  int lclen = LocOp.getLen( loc );
  const char* id    = LocOp.getId( loc );
  const char* train = LocOp.getTrain( loc );

  /* Permissions */
  iONode incl = wBlock.getincl( data->props );
  iONode excl = wBlock.getexcl( data->props );

  if( restlen != NULL ) {
    *restlen = 0;
    if( bklen > 0 && lclen > 0 && lclen < bklen )
      *restlen = bklen - lclen;
  }

  /* test if the id is included: */
  if( incl != NULL ) {
    Boolean included = False;
    while( incl != NULL ) {
      if( StrOp.len( wPermInclude.getid(incl) ) > 0 ) {
        if( StrOp.equals( id, wPermInclude.getid(incl) ) || StrOp.equals( train, wPermInclude.getid(incl) ) ) {
          included = True;
          break;
        }
      }
      else {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "empty include permission in block [%s]", data->id );
      }
      incl = wBlock.nextincl( data->props, incl );
    };
    if( !included ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                     "Loc [%s] has no permission to enter block [%s]",
                     id, data->id );
      return suits_not;
    }
  }

  /* test if the id is excluded: */
  if( excl != NULL ) {
    Boolean excluded = False;
    while( excl != NULL ) {
      if( StrOp.len( wPermExclude.getid(excl) ) > 0 ) {
        if( StrOp.equals( id, wPermExclude.getid(excl) ) || StrOp.equals( train, wPermExclude.getid(excl) ) ) {
          excluded = True;
          break;
        }
      }
      else {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "empty exclude permission in block [%s]", data->id );
      }
      excl = wBlock.nextexcl( data->props, excl );
    };
    if( excluded ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                     "Loc [%s] has no permission to enter block [%s]",
                     id, data->id );
      return suits_not;
    }
  }

  /* test if the cargo type is permitted */
  {
    const char* permtype = wBlock.gettypeperm(data->props);
    if( permtype != NULL && StrOp.len(permtype) > 0 && !StrOp.equals( permtype, wLoc.cargo_all) ) {
      iONode lc = LocOp.base.properties(loc);
      const char* cargo = LocOp.getCargo(loc);
      Boolean hasCargoType = False;
      iOStrTok tok = StrTokOp.inst( permtype, ',' );
      while( StrTokOp.hasMoreTokens(tok) ) {
        const char* permsubtype = StrTokOp.nextToken( tok );
        if( StrOp.equals( permsubtype, cargo)) {
          hasCargoType = True;
          break;
        }
      }
      StrTokOp.base.del(tok);
      if( !hasCargoType ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                       "Loc [%s] has no permission to enter block [%s]; type does not fit. (block=[%s] loco/train=[%s])",
                       id, data->id, permtype, cargo);
        return suits_not;
      }
    }
  }


  if( wBlock.ismanual( data->props ) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                   "Block \"%s\" is in manual-mode: not chooseable for auto-mode!",
                   data->id );
    return suits_not;
  }

  if( wLoc.getaddr( loc->base.properties( loc ) ) == 0 && !wBlock.istd( data->props ) ) {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 5002,
                   "Block [%s] does not support analog locos like [%s]. (%d, %d)",
                   data->id, LocOp.getId( loc ), bklen, lclen );
    return suits_not;
  }

  if( bklen > 0 && lclen > 0 ) {
    if( lclen + data->minbklc > bklen ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                     "Block \"%s\" is too short for \"%s\". (%d, %d)",
                     data->id, LocOp.getId( loc ), bklen, lclen );
      return suits_not;
    }
  }

  if( StrOp.equals( wBlock.commuter_no, wBlock.getcommuter( data->props ) ) && LocOp.isCommuter( loc ) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                   "Block \"%s\" does not allow commuter train type for \"%s\".",
                   data->id, LocOp.getId( loc ) );
    return suits_not;
  }
  else if( StrOp.equals( wBlock.commuter_only, wBlock.getcommuter( data->props ) ) && !LocOp.isCommuter( loc ) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                   "Block \"%s\" only allows commuter train type for \"%s\".",
                   data->id, LocOp.getId( loc ) );
    return suits_not;
  }

  /* Check all other loc properties if it realy suits. */
  if( StrOp.equals( wLoc.engine_electric, wLoc.getengine( loc->base.properties( loc ) ) ) && !wBlock.iselectrified( data->props ) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                   "Block [%s] is not electrified; E-Loco [%s] can not use it.",
                   data->id, LocOp.getId( loc ) );
    return suits_not;
  }


  /* Check if the locos class fits. */
  if( wBlock.getclass(data->props) != NULL && StrOp.len(wBlock.getclass(data->props)) > 0 ) {
    Boolean classFits = False;
    const char* locoClass = LocOp.getClass(loc);
    iOStrTok tok = StrTokOp.inst(wBlock.getclass(data->props), ',');
    while( StrTokOp.hasMoreTokens(tok) ) {
      if( StrOp.equals( StrTokOp.nextToken(tok), locoClass) ) {
        classFits = True;
        break;
      }
    }
    StrTokOp.base.del(tok);
    if( !classFits ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                     "Block [%s] does not allow class [%s] from loco [%s]",
                     data->id, locoClass, LocOp.getId( loc ) );
      return suits_not;
    }
  }


  /* this only returns suits_ok or suits_well */
  return __crossCheckType((iOBlock)inst, loc, NULL, checkPrev);
}

static Boolean _wait( iIBlockBase inst, iOLoc loc, Boolean reverse, Boolean* oppwait ) {
  iOBlockData data = Data(inst);
  Boolean wait = False;
  iOSignal signal = NULL;
  iOSignal oppsignal = NULL;

  Boolean bkeside = wLoc.isblockenterside( (iONode)loc->base.properties( loc ) );
  signal = (iOSignal)inst->hasManualSignal(inst, False, !bkeside );
  oppsignal = (iOSignal)inst->hasManualSignal(inst, False, bkeside );

  if( oppsignal != NULL && SignalOp.isState(oppsignal, wSignal.red) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "block %s has an oppwait red manual signal", inst->base.id(inst) );
    *oppwait = True;
  }
  else if( oppsignal != NULL && SignalOp.isState(oppsignal, wSignal.yellow) && StrOp.equals( wLoc.engine_automobile, LocOp.getEngine(loc) ) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "block %s has an oppwait yellow manual signal", inst->base.id(inst) );
    *oppwait = True;
  }
  else if( oppsignal != NULL ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "block %s has a NONE oppwait red manual signal", inst->base.id(inst) );
    *oppwait = data->tempwait;
  }

  if( signal != NULL && SignalOp.isState(signal, wSignal.red) ) {
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "block %s has a red manual signal", inst->base.id(inst) );
    return True; /* wait until it is set to green */
  }
  else if( signal != NULL && SignalOp.isState(signal, wSignal.yellow) && StrOp.equals( wLoc.engine_automobile, LocOp.getEngine(loc) ) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "block %s has a yellow manual signal", inst->base.id(inst) );
    return True; /* wait until it is set to green */
  }
  else if( signal != NULL ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "block %s has a NONE red manual signal", inst->base.id(inst) );
    return data->tempwait;
  }


  if( StrOp.equals( wLoc.cargo_cleaning, LocOp.getCargo(loc) ) ){
    return data->tempwait;
  }
  __crossCheckType( (iOBlock)inst, loc, &wait, True);
  *oppwait = (wait | data->tempwait);
  return (wait | data->tempwait);
}

static void _enterBlock( iIBlockBase inst, const char* id ) {
  iOBlockData data = Data(inst);
  wBlock.setlocid( data->props, id );
  if( id != NULL ) {
    iONode nodeD = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
    wBlock.setid( nodeD, data->id );
    wBlock.setentering( nodeD, True );
    wBlock.setlocid( nodeD, id );
    wBlock.setfifoids(nodeD, wBlock.getfifoids(data->props));
    wBlock.setacceptident(nodeD, data->acceptident);
    wBlock.setmasterid(nodeD, wBlock.getmasterid(data->props));
    AppOp.broadcastEvent( nodeD );
    if( !data->crossing )
      __checkAction((iOBlock)inst, "enter");
  }

  if( wBlock.getfifosize(data->props) > 0 && wBlock.isfreeblockonenter(data->props) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "reset arrivalPending in block [%s] for FiFo", data->id );
    data->arrivalPending = False;
  }

  if( !data->crossing && wBlock.isvirtual(data->props) ) {
    iOStrTok tok = StrTokOp.inst( wBlock.getslaveblocks(data->props), ',' );

    while( StrTokOp.hasMoreTokens(tok) ) {
      const char* blockid = StrTokOp.nextToken( tok );
      iIBlockBase bk = ModelOp.getBlock( AppOp.getModel(), blockid);
      if( bk != NULL ) {
        bk->enterBlock( bk, id );
      }
    };
    StrTokOp.base.del(tok);
  }


}


static void _exitBlock( iIBlockBase inst, const char* id, Boolean unexpected ) {
  iOBlockData data = Data(inst);
  if( id != NULL ) {
    __checkAction((iOBlock)inst, "exit");
  }
}


static void _inBlock( iIBlockBase inst, const char* id ) {
  iOBlockData data = Data(inst);
  wBlock.setlocid( data->props, id );
  if( id != NULL ) {
    iOLocation location = ModelOp.getBlockLocation(AppOp.getModel(), data->id );
    iONode nodeD = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
    wBlock.setid( nodeD, data->id );
    wBlock.setreserved( nodeD, False );
    wBlock.setreserved( data->props, False );
    wBlock.setlocid( nodeD, id );
    wBlock.setfifoids(nodeD, wBlock.getfifoids(data->props));
    wBlock.setacceptident(nodeD, data->acceptident);
    wBlock.setmasterid(nodeD, wBlock.getmasterid(data->props));
    AppOp.broadcastEvent( nodeD );
    if( !data->crossing )
      __checkAction((iOBlock)inst, "occupied");

    if( !data->crossing && location != NULL ) {
      LocationOp.locoDidArrive(location, id);
    }
  }
  data->arrivalPending = False;

  if( !data->crossing && wBlock.isvirtual(data->props) ) {
    iOStrTok tok = StrTokOp.inst( wBlock.getslaveblocks(data->props), ',' );

    while( StrTokOp.hasMoreTokens(tok) ) {
      const char* blockid = StrTokOp.nextToken( tok );
      iIBlockBase bk = ModelOp.getBlock( AppOp.getModel(), blockid);
      if( bk != NULL ) {
        bk->inBlock( bk, id );
      }
    };
    StrTokOp.base.del(tok);
  }
}


static int _getVisitCnt( iIBlockBase inst, const char* id ) {
  iOBlockData data = Data(inst);
  if( data->prevLocId != NULL && StrOp.equals( id, data->prevLocId ) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                   "Block \"%s\" is %d visited by \"%s\"",
                   data->id, data->prevLocIdCnt, id );
    return data->prevLocIdCnt;
  }
  else {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                   "Block \"%s\" is not visited by \"%s\"",
                   data->id, id );
    return 0;
  }
}


static int _getOccTime( iIBlockBase inst ) {
  iOBlockData data  = Data(inst);
  iOModel     model = AppOp.getModel();
  /* check if the loco is in auto mode */
  if( data->locId != NULL && StrOp.len( data->locId ) > 0 ) {
    iOLoc loc = ModelOp.getLoc( model, data->locId, NULL, False );
    if( loc != NULL && LocOp.isAutomode(loc)) {
      return data->occtime;
    }
  }
  return 0;
}


static Boolean _link( iIBlockBase inst, iIBlockBase linkto ) {
  iOBlockData data = NULL;

  if( inst == NULL ) {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "BlockOp._link( NULL, ... )" );
    return False;
  }

  data = Data(inst);

  if( linkto != NULL ) {
    iOControl control = AppOp.getControl();
    iONode cmd = NodeOp.inst( wSysCmd.name(), NULL, ELEMENT_NODE );
    wSysCmd.setcmd( cmd, wSysCmd.link );
    wSysCmd.setid( cmd, wBlock.getid(data->props));
    wSysCmd.setiid( cmd, wBlock.getiid(data->props));
    wSysCmd.setvalA( cmd, inst->getTDport( inst ) );
    wSysCmd.setvalB( cmd, linkto->getTDport( linkto ) );
    if( ControlOp.cmd( control, cmd, NULL ) ) {
      data->linkto = linkto;
      return True;
    }
  }
  return False;
}


static void __broadcastLockState(iIBlockBase inst, const char* id) {
  iOBlockData data = Data(inst);

  iONode nodeD = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
  wBlock.setid( nodeD, data->id );
  wBlock.setmasterid(nodeD, wBlock.getmasterid(data->props));
  wBlock.setreserved( nodeD, True );
  wBlock.setlocid( nodeD, id );
  wBlock.setfifoids(nodeD, wBlock.getfifoids(data->props));
  wBlock.setacceptident(nodeD, data->acceptident);
  AppOp.broadcastEvent( nodeD );
}

/**
 * Ignore all events wenn the crossing flag is set.
 */
static Boolean _lock( iIBlockBase inst, const char* id, const char* blockid, const char* routeid,
    Boolean crossing, Boolean reset, Boolean reverse, int indelay, const char* masterId, Boolean force )
{
  iOBlockData data = NULL;
  Boolean ok = False;
  Boolean fifo = False;
  iOLoc lc = ModelOp.getLoc( AppOp.getModel(), id, NULL, False );

  if( inst == NULL ) {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "BlockOp.lock( NULL, %s )", id );
    return False;
  }

  data = Data(inst);

  if( id != NULL && data->locId != NULL && StrOp.equals( id, data->locId ) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "block [%s] already locked for loco [%s]", data->id, id );

    if( StrOp.equals(LocOp.getCurBlock(lc), data->id) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "looping loco %s in block %s", id, data->id);
      __broadcastLockState(inst, id);
      return True;
    }

    if( !crossing ) {
      if( !StrOp.equals(data->fromBlockId, blockid) || !StrOp.equals(data->byRouteId, routeid) || data->crossing != crossing ) {
        if( !force && !data->forcelock) {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "second lock by loco [%s] block [%s] differs with settings", id, data->id );
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "block [%s]-[%s] route [%s]-[%s] crossing %d-%d", data->fromBlockId, blockid, data->byRouteId, routeid, data->crossing, crossing );
          return True;
        }
      }
    }
    if( !force && !data->forcelock )
      return True;
  }

  data->forcelock = force;


  if( wBlock.isremote(data->props) ) {
    iOR2Rnet r2rnet = ControlOp.getR2Rnet(AppOp.getControl());
    if( r2rnet != NULL ) {
      iOLoc lc = ModelOp.getLoc( AppOp.getModel(), id, NULL, False );
      iIBlockBase curblock = ModelOp.getBlock( AppOp.getModel(), blockid );
      return R2RnetOp.reserveBlock(r2rnet, wBlock.getrrid(data->props),
              wBlock.getid(data->props), routeid, lc->base.properties(lc), curblock->base.properties(curblock), False );
    }
  }
  else {
    iOControl control = AppOp.getControl();
    if( !ControlOp.hasBlockPower(control, data->id) ) {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "block [%s] has no power; locking is rejected", data->id );
      return False;
    }

    /* wait only 10ms for getting the mutex: */
    if( !MutexOp.trywait( data->muxLock, 10 ) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "timeout in locking [%s]", data->id );
      return False;
    }

    if( !BlockOp.isFree( inst, id ) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
          "block [%s] is not free for [%s], already locked by [%s]", data->id, id, data->locId );
      MutexOp.post( data->muxLock );
      return False;
    }

    if( wBlock.isvirtual(data->props) ) {
      Boolean Locked = True;
      iOStrTok tok = StrTokOp.inst( wBlock.getslaveblocks(data->props), ',' );

      while( StrTokOp.hasMoreTokens(tok) ) {
        const char* blockid = StrTokOp.nextToken( tok );
        iIBlockBase bk = ModelOp.getBlock( AppOp.getModel(), blockid);
        if( bk != NULL ) {
          if( !bk->lock( bk, id, blockid, routeid, True, reset, reverse, indelay, wBlock.getid(data->props) , force) ) {
            TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "virtual block [%s] could not lock slave block [%s]", wBlock.getid(data->props), blockid );
            Locked = False;
            break;
          }
        }
      };
      StrTokOp.base.del(tok);
      if(!Locked) {
        MutexOp.post( data->muxLock );
        return False;
      }
    }

    /* check group lock */
    if( data->locIdGroup != NULL && !StrOp.equals( data->locIdGroup, id ) ) {
      if( !ModelOp.isBlockGroupLockedForLoco(AppOp.getModel(), data->id, id) ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "block already has a group lock by [%s]", data->locIdGroup );
        MutexOp.post( data->muxLock );
        return False;
      }
    }

    if( wBlock.getfifosize(data->props) > 0 && !data->arrivalPending && lc != NULL && StrOp.equals( wLoc.engine_automobile, LocOp.getEngine(lc)) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
          "fifo block [%s] automobile [%s] idx=%d", data->id, LocOp.getId(lc), ListOp.size(data->fifoList) );
      ListOp.add(data->fifoList, (obj)LocOp.getId(lc));
      __dumpFiFo(inst);
      if( ListOp.size(data->fifoList) == 1 ) {
        data->locId = id;
        wBlock.setlocid(data->props, id);
        ModelOp.setBlockOccupancy( AppOp.getModel(), data->id, data->locId, False, 0, 0, NULL );
        data->inPending = True;
      }
      else {
        LocOp.stop(lc, False);
        fifo = True;
      }
      data->crossing = crossing;
      ok = True;
    }
    else if( data->locId == NULL || StrOp.len( data->locId ) == 0 || StrOp.equals( "(null)", data->locId) ) {
      data->locId = id;
      data->crossing = crossing;
      ok = True;
      wBlock.setlocid(data->props, id);
      ModelOp.setBlockOccupancy( AppOp.getModel(), data->id, data->locId, False, 0, 0, NULL );
    }
    else if( StrOp.equals( id, data->locId ) ) {
      data->locId = id;
      data->crossing = crossing;
      ok = True;
    }

    if( ok && !fifo ) {
      if( data->prevLocId != NULL && StrOp.equals( id, data->prevLocId ) ) {
        data->prevLocIdCnt++;
      }
      else {
        data->prevLocId = id;
        data->prevLocIdCnt = 1;
      }
    }

    if( masterId != NULL )
      wBlock.setmasterid(data->props, masterId);
    else
      wBlock.setmasterid(data->props, "");

    /* Broadcast to clients. */
    if( ok && !fifo ) {
      __broadcastLockState(inst, id);
      wBlock.setreserved( data->props, True );
    }
    else if(!ok) {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
                   "Block \"%s\" already locked by \"%s\".",
                   data->id, data->locId );
    }

    if( ok && !fifo ) {
      /* in case of a managed block of a fiddle yard the manager ID is needed */
      blockid = ModelOp.getManagedID( AppOp.getModel(), blockid );

      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
          "block %s locked for [%s][%s][%s] in [%s] direction, indelay=%d",
          data->id, id, data->locId, blockid, reverse?"reverse":"normal", indelay );
      data->reverse     = reverse;
      data->fromBlockId = blockid;
      data->byRouteId   = routeid;
      __checkAction((iOBlock)inst, "reserved");
      if( reset )
        BlockOp.resetTrigs( inst );
    }

    if( ok && !fifo ) {
      /* reset occupancy ticker */
      data->occtime = SystemOp.getTick();
      data->indelay = indelay;
    }

    /* Unlock the semaphore: */
    MutexOp.post( data->muxLock );

    data->arrivalPending = ok;

    return ok;
  }
  return False;
}


static Boolean _lockForGroup( iIBlockBase inst, const char* id ) {
  iOBlockData data = NULL;
  Boolean ok = False;
  Boolean broadcast = False;

  if( inst == NULL ) {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "lockForGroup( NULL, %s )", id );
    return False;
  }

  /* should we use a mutex here? */

  data = Data(inst);

  /* wait only 10ms for getting the mutex: */
  if( !MutexOp.trywait( data->muxLock, 10 ) ) {
    return False;
  }

  if( !BlockOp.isFree( inst, id ) ) {
    MutexOp.post( data->muxLock );
    return False;
  }

  if( data->locIdGroup == NULL || StrOp.len( data->locIdGroup ) == 0 || StrOp.equals( "(null)", data->locIdGroup ) ) {
    if( data->locId == NULL || StrOp.len( data->locId ) == 0 || StrOp.equals( id, data->locId ) ) {
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
    iONode nodeD = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
    wBlock.setid( nodeD, data->id );
    if( data->locId != NULL && StrOp.equals( id, data->locId ) )
      wBlock.setreserved( nodeD, False );
    else
      wBlock.setreserved( nodeD, True );
    wBlock.setmasterid(nodeD, wBlock.getmasterid(data->props));
    wBlock.setlocid( nodeD, id );
    wBlock.setfifoids(nodeD, wBlock.getfifoids(data->props));
    wBlock.setacceptident(nodeD, data->acceptident);
    AppOp.broadcastEvent( nodeD );
  }

  if( !ok ) {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
                 "block \"%s\" already group locked by \"%s\".",
                 data->id, data->locIdGroup );
  }

  if( ok ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
        "block [%s] group locked for [%s]", data->id, id );
  }

  /* Unlock the semaphore: */
  MutexOp.post( data->muxLock );

  return ok;
}


static Boolean _isLinked( iIBlockBase inst ) {
  iOBlockData data = Data(inst);
  return data->linkto != NULL ? True:False;
}


static const char* _getGroup( iOBlock inst ) {
  iOBlockData data = Data(inst);
  return data->group;
}

static const char* _getLoc( iIBlockBase inst ) {
  iOBlockData data = Data(inst);
  return data->locId;
}

static const char* _getInLoc( iIBlockBase inst ) {
  iOBlockData data = Data(inst);
  return wBlock.getlocid( data->props );
}

static void _setGroup( iIBlockBase inst, const char* group ) {
  iOBlockData data = Data(inst);
  data->group = group;
}


static void _resetTrigs( iIBlockBase inst ) {
  iOBlockData data = Data(inst);
  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                 "Block \"%s\" reset counters.",
                 data->id );

  /* reset wheel counters */
  {
    iONode fbevt = wBlock.getfbevent( data->props );

    while( fbevt != NULL ) {
      const char* fbid = wFeedbackEvent.getid( fbevt );
      iOFBack fb = ModelOp.getFBack( AppOp.getModel(), fbid );
      if(fb != NULL)
        FBackOp.resetWheelCount(fb);
      fbevt = wBlock.nextfbevent( data->props, fbevt );
    };
  }
}


static int _getWheelCount( iIBlockBase inst ) {
  iOBlockData data = Data(inst);
  return data->wheelcount;
}


static int _getRandomRate( iIBlockBase inst, const char* lcid ) {
  iOBlockData data = Data(inst);
  if( lcid != NULL ) {
    iONode incl = wBlock.getincl( data->props );
    /* test if the id is included: */
    while( incl != NULL ) {
      if( StrOp.equals( lcid, wPermInclude.getid(incl) ) ) {
        if( wPermInclude.getrandomrate(incl) > 0 )
          return wPermInclude.getrandomrate(incl);
      }
      incl = wBlock.nextincl( data->props, incl );
    };
  }
  return wBlock.getrandomrate(data->props);
}


static Boolean _unLink( iIBlockBase inst ) {
  if( inst != NULL ) {
    iOBlockData data = Data(inst);

    if( data->linkto != NULL ) {
      iOControl control = AppOp.getControl();
      iONode cmd = NodeOp.inst( wSysCmd.name(), NULL, ELEMENT_NODE );
      wSysCmd.setcmd( cmd, wSysCmd.ulink );
      wSysCmd.setiid( cmd, wBlock.getiid( data->props ) );
      wSysCmd.setid( cmd, wBlock.getid( data->props ) );
      wSysCmd.setvalA( cmd, BlockOp.getTDport( inst ) );
      if( ControlOp.cmd( control, cmd, NULL ) ) {
        data->linkto = NULL;
        return True;
      }
    }
  }
  return False;
}

static Boolean _setLocSchedule( iIBlockBase inst, const char* scid, Boolean manual ) {
  Boolean ok = False;
  if( inst != NULL && scid != NULL ) {
    iOBlockData data = Data(inst);

    if( data->locId != NULL && StrOp.len( data->locId ) > 0 ) {
      iOModel model = AppOp.getModel();
      iOLoc loc = ModelOp.getLoc( model, data->locId, NULL, False );
      if( loc != NULL ) {
        LocOp.useSchedule( loc, scid );
        if(manual)
          LocOp.gomanual(loc);
        else
          LocOp.go(loc);
      }
    }

  }
  return ok;
}

static Boolean _setLocTour( iIBlockBase inst, const char* tourid, Boolean manual ) {
  Boolean ok = False;
  if( inst != NULL && tourid != NULL ) {
    iOBlockData data = Data(inst);

    if( data->locId != NULL && StrOp.len( data->locId ) > 0 ) {
      iOModel model = AppOp.getModel();
      iOLoc loc = ModelOp.getLoc( model, data->locId, NULL, False );
      if( loc != NULL ) {
        LocOp.useTour( loc, tourid );
        if(manual)
          LocOp.gomanual(loc);
        else
          LocOp.go(loc);
      }
    }

  }
  return ok;
}

static Boolean _isDepartureAllowed( iIBlockBase inst, const char* id, Boolean force ) {
  iOBlockData data = Data(inst);
  iOLocation location = ModelOp.getBlockLocation(AppOp.getModel(), data->id );

  if( wBlock.ismainline(data->props) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "block [%s] is mainline; allow departure", wBlock.getid(data->props));
    return True;
  }

  if( force ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "block [%s] is forced; allow departure", wBlock.getid(data->props));
    return True;
  }

  if( location != NULL ) {
    return LocationOp.isDepartureAllowed( location, id );
  }
  return True;
}

static void _didNotDepart( iIBlockBase inst, const char* id ) {
  iOBlockData data = Data(inst);
  iOLocation location = ModelOp.getBlockLocation(AppOp.getModel(), data->id );

  if( location != NULL ) {
    LocationOp.didNotDepart( location, id );
  }
}

static Boolean _unLock( iIBlockBase inst, const char* id, const char* routeId ) {
  if( inst != NULL && id != NULL ) {
    iOBlockData data = Data(inst);
    Boolean ok = False;

    if( wBlock.isremote(data->props) ) {
      iOR2Rnet r2rnet = ControlOp.getR2Rnet(AppOp.getControl());
      if( r2rnet != NULL ) {
        return R2RnetOp.unlockBlock(r2rnet, wBlock.getrrid(data->props), wBlock.getid(data->props), id );
      }
    }
    else {


      /* wait only 10ms for getting the mutex: */
      if( !MutexOp.trywait( data->muxLock, 10 ) ) {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
                       "time out on unlocking block \"%s\" by \"%s\"",
                       data->id, id );
        return False;
      }


      if( wBlock.isvirtual(data->props) ) {
        Boolean unLocked = True;
        iOStrTok tok = StrTokOp.inst( wBlock.getslaveblocks(data->props), ',' );

        while( StrTokOp.hasMoreTokens(tok) ) {
          const char* blockid = StrTokOp.nextToken( tok );
          iIBlockBase bk = ModelOp.getBlock( AppOp.getModel(), blockid);
          if( bk != NULL ) {
            if( !bk->unLock( bk, id, routeId ) ) {
              TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "virtual block [%s] could not unlock slave block [%s]", wBlock.getid(data->props), blockid );
              unLocked = False;
              break;
            }
          }
        };
        StrTokOp.base.del(tok);
        if(!unLocked) {
          return False;
        }
      }

      wBlock.setmasterid(data->props, "");

      /* FiFO */
      if( wBlock.getfifosize(data->props) > 0 && ListOp.size(data->fifoList) > 0 ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
            "fifo unlock block [%s] automobile [%s]", data->id, (const char*)ListOp.get(data->fifoList, 0) );
        ListOp.remove(data->fifoList, 0);
        __dumpFiFo(inst);
        if( ListOp.size(data->fifoList) > 0 ) {
          iOLoc loc = NULL;
          data->locId = (const char*)ListOp.get(data->fifoList, 0);
          loc = ModelOp.getLoc( AppOp.getModel(), data->locId, NULL, False );
          if( loc != NULL ) {
            Boolean oppwait = False;
            if( inst->wait( inst, loc, False, &oppwait ) ) {
              iONode cmd = NodeOp.inst(wLoc.name(), NULL, ELEMENT_NODE);
              wLoc.setcmd(cmd, wLoc.velocity);
              wLoc.setV(cmd, 0);
              LocOp.cmd(loc, cmd);
            }
            TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                "fifo block [%s] setting automobile [%s] to front", data->id, data->locId );
            LocOp.go(loc);
            wBlock.setlocid(data->props, LocOp.getId(loc));
            /* Broadcast to clients. */
            {
              iONode nodeD = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
              wBlock.setid( nodeD, data->id );
              wBlock.setmasterid(nodeD, wBlock.getmasterid(data->props));
              wBlock.setreserved( nodeD, False );
              wBlock.setreserved( data->props, False );
              wBlock.setlocid( nodeD, data->locId );
              wBlock.setfifoids( nodeD, wBlock.getfifoids(data->props) );
              wBlock.setacceptident(nodeD, data->acceptident);
              AppOp.broadcastEvent( nodeD );
            }
            MutexOp.post( data->muxLock );
            return True;
          }
        }
        data->fifo0departing = False;
      }


      if( data->locId == NULL || StrOp.len(data->locId) == 0 || StrOp.equals( id, data->locId ) || StrOp.equals( id, "*" ) ) {
        iOLocation location = ModelOp.getBlockLocation(AppOp.getModel(), data->id );
        if( data->locId != NULL && StrOp.equals( id, "*" ) ) {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
              "block [%s] is forced unlocked by [%s]; zomby loco is [%s]", data->id, id, data->locId!=NULL?data->locId:"-" );
        }

        if( data->byRouteId != NULL && routeId != NULL && !StrOp.equals(data->byRouteId, routeId) ) {
          /* same loco did locked it for another route */
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "keep [%s] locked for route [%s]!=[%s]", data->id, data->byRouteId, routeId );
          MutexOp.post( data->muxLock );
          return True;
        }

        data->locId = NULL;
        data->fromBlockId = NULL;
        BlockOp.resetTrigs( inst );
        wBlock.setlocid(data->props, "");
        data->crossing = False;
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "reset tempwait in block [%s]", data->id );
        data->tempwait = False;

        if( location != NULL && id != NULL ) {
          LocationOp.locoDidDepart(location, id);
        }

        if( data->closereq ) {
          wBlock.setstate( data->props, wBlock.closed );
          data->closereq = False;
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "set block to close: requested" );
          __checkAction((iOBlock)inst, "closed");
        }

        if( !__isElectricallyFree((iOBlock)inst) ) {
          data->pendingFree = True;
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "block %s: pending unlock -> still electrically occupied", data->id );
        }

        ModelOp.setBlockOccupancy( AppOp.getModel(), data->id, "", False, 0, 0, NULL );
        wBlock.setlocid( data->props, "" );

        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                   "Block \"%s\" unlock %s, group lock=[%s]",
                   data->id, id, data->locIdGroup!=NULL?data->locIdGroup:"" );

        /* Broadcast to clients. */
        {
          iONode nodeD = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
          wBlock.setid( nodeD, data->id );
          wBlock.setstate( nodeD, wBlock.getstate(data->props) );

          if( data->locIdGroup == NULL ) {
            wBlock.setlocid( nodeD, "" );
            __checkAction((iOBlock)inst, "free");
          }
          else {
            wBlock.setlocid( nodeD, data->locIdGroup );
            wBlock.setreserved( nodeD, True );
            __checkAction((iOBlock)inst, "reserved");
          }
          wBlock.setacceptident(nodeD, data->acceptident);
          wBlock.setmasterid(nodeD, wBlock.getmasterid(data->props));
          AppOp.broadcastEvent( nodeD );
        }
        /* Set signal. */

        /* TODO: Needed here? _setDefaultAspect(inst);*/

        ok = True;
      }
      else {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
                       "\"%s\" tried to unlock block \"%s\" but \"%s\" owns it!",
                       id, data->id, data->locId==NULL?"?":data->locId );
      }

      data->occtime = 0;

      /* Unlock the semaphore: */
      MutexOp.post( data->muxLock );
    }

    if( ok )
      data->wheelcount = 0;

    return ok;
  }

  return False;
}


static void __dumpFiFo(iIBlockBase inst) {
  iOBlockData data = Data(inst);

  if(wBlock.getfifosize(data->props) > 0 && ListOp.size( data->fifoList) > 0 ) {
    int i = 0;
    char* fifoids = NULL;
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "fifo dump block [%s]", data->id );
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "----------------------------------------begin", data->id );
    for( i = 0; i < ListOp.size( data->fifoList); i++ ) {
      iOLoc loc = ModelOp.getLoc( AppOp.getModel(), (const char*)ListOp.get(data->fifoList, i), NULL, False );
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "fifo[%d] = %s", i, LocOp.getId(loc) );
      if( i > 0 )
        fifoids = StrOp.cat(fifoids, ",");
      fifoids = StrOp.cat(fifoids, LocOp.getId(loc));
    }
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "fifoids = %s", fifoids );
    wBlock.setfifoids(data->props, fifoids);
    StrOp.free(fifoids);
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "----------------------------------------end", data->id );
  }
}


static void _depart(iIBlockBase inst) {
  iOBlockData data = Data(inst);
  __checkAction((iOBlock)inst, "depart");

  if(wBlock.getfifosize(data->props) > 0 && ListOp.size( data->fifoList) > 1 ) {
    iOLoc loc = ModelOp.getLoc( AppOp.getModel(), (const char*)ListOp.get(data->fifoList, 1), NULL, False );
    __dumpFiFo(inst);
    if( loc != NULL ) {
      if( StrOp.equals( data->id, LocOp.getCurBlock(loc) ) ) {
        obj  manager = (obj)(data->manager == NULL ? inst:data->manager);
        iONode cmd = NodeOp.inst(wLoc.name(), NULL, ELEMENT_NODE);
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "inform fifo [%s] of the departure of the first", LocOp.getId(loc) );
        Boolean oppwait = False;
        if( inst->wait( inst, loc, False, &oppwait ) ) {
          wLoc.setcmd(cmd, wLoc.velocity);
          wLoc.setV(cmd, 0);
          LocOp.cmd(loc, cmd);
        }
        LocOp.go(loc);
      }
    }
  }
  if(wBlock.getfifosize(data->props) > 0 ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "fifo block [%s] fifo0departing", data->id );
    data->fifo0departing = True;
  }

}


static Boolean _unLockForGroup( iIBlockBase inst, const char* id ) {
  Boolean ok = False;
  iOBlockData data = Data(inst);
  if( data->locIdGroup != NULL && id != NULL ) {

    /* wait only 10ms for getting the mutex: */
    if( !MutexOp.trywait( data->muxLock, 10 ) ) {
      return False;
    }

    if( StrOp.equals( id, data->locIdGroup ) ) {
      data->locIdGroup = NULL;

      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                 "Block [%s] unlockForGroup [%s].",
                 data->id, id );


      ok = True;
      /* Broadcast to clients only if the block is not locked. */
      if( data->locId == NULL || StrOp.len(data->locId) == 0 ) {
        iONode nodeD = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
        wBlock.setid( nodeD, data->id );
        wBlock.setlocid( nodeD, "" );
        wBlock.setacceptident(nodeD, data->acceptident);
        wBlock.setstate( nodeD, wBlock.getstate( data->props ) );
        wBlock.setmasterid(nodeD, wBlock.getmasterid(data->props));
        AppOp.broadcastEvent( nodeD );
      }

    }
    else {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
                 "unmatching lockID: block [%s] unlockForGroup [%s] by [%s].",
                 data->id, data->locIdGroup, id );
    }

    /* Unlock the semaphore: */
    MutexOp.post( data->muxLock );

  }
  return ok;
}


static void _init( iIBlockBase inst ) {
  iOBlockData data = Data(inst);
  iOModel model = AppOp.getModel(  );
  Boolean slaveBlock = False;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "init block %s", data->id );
  /* ToDo: This string pointer is not persistent! */
  data->locId = wBlock.getlocid( data->props );
  data->ghost = False;

  if( wBlock.getmasterid(data->props) != NULL && StrOp.len( wBlock.getmasterid(data->props) ) > 0 ) {
    slaveBlock = True;
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "init slave block [%s] from master [%s]", data->id, wBlock.getmasterid(data->props)  );
  }


  if( data->locId != NULL && StrOp.len( data->locId ) > 0 ) {
    iOLoc loc = ModelOp.getLoc( model, data->locId, NULL, False );
    if( loc != NULL ) {
      if( LocOp.isAutomode(loc) ) {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
            "reject init block [%s] because loco [%s] is still in automode", data->id, LocOp.getId( loc ) );
        return;
      }

      if( !slaveBlock )
        LocOp.setCurBlock( loc, data->id );

      /* overwrite data->locId with the static id from the loc object: */
      data->locId = LocOp.getId( loc );
      data->occtime = SystemOp.getTick();

      BlockOp.red( inst, False, False );
      BlockOp.red( inst, True, False );
      BlockOp.red( inst, False, True );
      BlockOp.red( inst, True, True );
    }
    else
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "init() unknown locId: %s", data->locId );
  }
  else {
    _setDefaultAspect(inst, False);
    _setDefaultAspect(inst, True);
  }

  _setCarCount(inst, 0);
}

static Boolean _cmd( iIBlockBase inst, iONode nodeA ) {
  iOBlockData data = Data(inst);
  iOModel model = AppOp.getModel(  );
  Boolean occUpdate  = False;
  Boolean slaveBlock = False;

  /* Cmds: lcid="" state="" */
  const char* locid = wBlock.getlocid( nodeA );
  const char* state = wBlock.getstate( nodeA );
  const char* cmd   = wBlock.getcmd( nodeA );

  if( wBlock.getmasterid(data->props) != NULL && StrOp.len( wBlock.getmasterid(data->props) ) > 0 ) {
    if( !wBlock.ismastercmd(nodeA) )
      slaveBlock = True;
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "slave block [%s] cmd=%s", data->id, slaveBlock?"slave":"normal");
  }

  if( cmd != NULL && (StrOp.equals(cmd, wBlock.nop) || StrOp.equals(cmd, wBlock.bsp) || StrOp.equals(cmd, wBlock.bsm) ) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "block [%s] cmd=%s", data->id, cmd);
    NodeOp.base.del(nodeA);
    return True;
  }

  if( !slaveBlock && cmd != NULL && StrOp.equals(cmd, wBlock.resetwc) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "reset wheel count in [%s] from %d to 0", data->id, data->wheelcount);
    data->wheelcount = 0;
    NodeOp.base.del(nodeA);
    return True;
  }

  if( !slaveBlock && cmd != NULL && StrOp.equals(cmd, wBlock.classset) ) {
    inst->setClass(inst, wBlock.getclass(nodeA));
    NodeOp.base.del(nodeA);
    return True;
  }

  if( !slaveBlock && cmd != NULL && StrOp.equals( wBlock.classadd, cmd ) ) {
    char* newclass = NULL;
    Boolean isNew = True;

    iOStrTok tok = StrTokOp.inst(wBlock.getclass(data->props), ',');
    while( StrTokOp.hasMoreTokens(tok) ) {
      const char* c = StrTokOp.nextToken(tok);
      if( StrOp.equals(c, wBlock.getclass(nodeA)) ) {
        isNew = False;
        break;
      }
    }
    StrTokOp.base.del(tok);

    if( isNew ) {
      if( StrOp.len(wBlock.getclass(data->props)) > 0 )
        newclass = StrOp.fmt("%s,%s", wBlock.getclass(data->props), wBlock.getclass(nodeA));
      else
        newclass = StrOp.fmt("%s", wBlock.getclass(nodeA));
      inst->setClass(inst, newclass);
      StrOp.free(newclass);
    }
    NodeOp.base.del(nodeA);
    return True;
  }

  if( !slaveBlock && cmd != NULL && StrOp.equals( wBlock.classdel, cmd ) ) {
    char* newclass = NULL;
    int idx = 0;
    iOStrTok tok = StrTokOp.inst(wBlock.getclass(data->props), ',');
    while( StrTokOp.hasMoreTokens(tok) ) {
      const char* c = StrTokOp.nextToken(tok);
      if( StrOp.equals(c, wBlock.getclass(nodeA)) )
        continue;
      if( idx > 0 )
        newclass = StrOp.cat(newclass, ",");
      newclass = StrOp.cat(newclass, c);
      idx++;
    }
    StrTokOp.base.del(tok);
    inst->setClass(inst, newclass);
    StrOp.free(newclass);
    NodeOp.base.del(nodeA);
    return True;
  }



  if( !slaveBlock && cmd != NULL && StrOp.equals(cmd, wBlock.resetfifo) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "reset FiFo list in [%s]", data->id);
    ListOp.clear(data->fifoList);
    __dumpFiFo(inst);
    wBlock.setfifoids(data->props, "");
    NodeOp.base.del(nodeA);
    return True;
  }

  if( NodeOp.findAttr(nodeA, wAction.block_acceptident) != NULL ) {
    if( data->acceptident && wBlock.isacceptident(nodeA) )
      inst->acceptIdent(inst, False);
    else
      inst->acceptIdent(inst, wBlock.isacceptident(nodeA));
  }
  else if( !slaveBlock && locid != NULL ) {
    iOLocation location = ModelOp.getBlockLocation( AppOp.getModel(), data->id);
    iOLoc loco = NULL;

    if( StrOp.len(locid) == 0 && data->locId != NULL && StrOp.len(data->locId) > 0 ) {
      /* inform loc */
      iOLoc loc = ModelOp.getLoc( model, data->locId, NULL, False );
      if( loc != NULL ) {
        LocOp.setCurBlock( loc, NULL );
        data->occtime = SystemOp.getTick();

        /* depart from location */
        if( location != NULL ) {
          LocationOp.locoDidDepart(location, data->locId);
        }

      }
    }
    else if(StrOp.len(locid) > 0) {
      loco = ModelOp.getLoc( model, locid, NULL, False );
      /* arrive in location */
      if( location != NULL ) {
        LocationOp.locoDidArrive(location, locid);
      }
    }

    wBlock.setlocid( data->props, locid );
    /* reset ghost flag */
    data->ghost = False;

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,"block %s set locid=%s", wBlock.getid(data->props), locid );
    ModelOp.setBlockOccupancy( AppOp.getModel(), data->id, locid, False, 0, 0, NULL );
    occUpdate = True;

    if( wBlock.getfifosize(data->props) > 0 && !data->arrivalPending && loco != NULL && StrOp.equals( wLoc.engine_automobile, LocOp.getEngine(loco)) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
          "fifo block [%s] automobile [%s] idx=%d", data->id, LocOp.getId(loco), ListOp.size(data->fifoList) );
      ListOp.add(data->fifoList, (obj)LocOp.getId(loco));
      __dumpFiFo(inst);
    }

    if( wBlock.isvirtual(data->props) ) {
      iOStrTok tok = StrTokOp.inst( wBlock.getslaveblocks(data->props), ',' );

      while( StrTokOp.hasMoreTokens(tok) ) {
        const char* blockid = StrTokOp.nextToken( tok );
        iIBlockBase bk = ModelOp.getBlock( AppOp.getModel(), blockid);
        if( bk != NULL ) {
          iONode slaveCmd = (iONode)NodeOp.base.clone(nodeA);
          wBlock.setmastercmd(slaveCmd, True);
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,"inform slave block [%s]", blockid);
          bk->setMasterID(bk, data->id);
          bk->cmd(bk, slaveCmd);

        }
      };
      StrTokOp.base.del(tok);
    }

  }

  if( !slaveBlock && ( locid == NULL || StrOp.len(locid) == 0 ) ) {
    _resetTD(inst);
  }

  if( !slaveBlock && state != NULL ) {
    if( StrOp.equals( wBlock.closed, state ) ) {
      if( data->locId != NULL && StrOp.len( data->locId ) > 0 ) {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "close block request; already reserved by [%s]", data->locId );
        NodeOp.base.del(nodeA);
        data->closereq = True;
        return False;
      }

      if( data->closereq ) {
        state = wBlock.closed;
        wBlock.setstate( nodeA, state );
        data->closereq = False;
        __checkAction((iOBlock)inst, "closed");
      }
    }
    wBlock.setstate( data->props, state );
    ModelOp.setBlockOccupancy( AppOp.getModel(), data->id, locid, StrOp.equals( wBlock.closed, state ), 0, 0, NULL );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "%s state=%s", NodeOp.getStr( data->props, "id", "" ), state );
  }

  if( !slaveBlock ) {
    _init( inst );
  }

  /* Broadcast to clients. */
  wBlock.setid(nodeA, data->id );
  wBlock.setacceptident(nodeA, data->acceptident );
  wBlock.setstate( nodeA, wBlock.getstate( data->props ) );
  if( occUpdate )
    wBlock.setcmd(nodeA, wBlock.loc);
  wBlock.setmasterid(nodeA, wBlock.getmasterid(data->props));
  AppOp.broadcastEvent( nodeA );

  if( occUpdate )
    __checkAction((iOBlock)inst, "occupied");

  return True;
}



static Boolean _green( iIBlockBase inst, Boolean distant, Boolean reverse ) {
  iOBlockData data = Data(inst);
  Boolean semaphore = False;
  const char* sgId = NULL;

  if( distant )
    sgId = reverse ? wBlock.getwsignalR( data->props ):wBlock.getwsignal( data->props );
  else
    sgId = reverse ? wBlock.getsignalR( data->props ):wBlock.getsignal( data->props );

  if( sgId != NULL && StrOp.len( sgId ) > 0 ) {
    iOModel model = AppOp.getModel(  );
    iOSignal sg = ModelOp.getSignal( model, sgId );
    if( sg != NULL ) {
      SignalOp.green( sg );
      semaphore = StrOp.equals( wSignal.semaphore, wSignal.gettype(sg->base.properties(sg)) );
    }
  }

  return semaphore;
}

static Boolean _yellow( iIBlockBase inst, Boolean distant, Boolean reverse ) {
  iOBlockData data = Data(inst);
  Boolean semaphore = False;
  const char* sgId = NULL;

  if( distant )
    sgId = reverse ? wBlock.getwsignalR( data->props ):wBlock.getwsignal( data->props );
  else
    sgId = reverse ? wBlock.getsignalR( data->props ):wBlock.getsignal( data->props );

  if( sgId != NULL && StrOp.len( sgId ) > 0 ) {
    iOModel model = AppOp.getModel(  );
    iOSignal sg = ModelOp.getSignal( model, sgId );
    if( sg != NULL ) {
      SignalOp.yellow( sg );
      semaphore = StrOp.equals( wSignal.semaphore, wSignal.gettype(sg->base.properties(sg)) );
    }
  }
  return semaphore;
}

static Boolean _white( iIBlockBase inst, Boolean distant, Boolean reverse ) {
  iOBlockData data = Data(inst);
  Boolean semaphore = False;
  const char* sgId = NULL;

  if( distant )
    sgId = reverse ? wBlock.getwsignalR( data->props ):wBlock.getwsignal( data->props );
  else
    sgId = reverse ? wBlock.getsignalR( data->props ):wBlock.getsignal( data->props );

  if( sgId != NULL && StrOp.len( sgId ) > 0 ) {
    iOModel model = AppOp.getModel(  );
    iOSignal sg = ModelOp.getSignal( model, sgId );
    if( sg != NULL ) {
      SignalOp.white( sg );
      semaphore = StrOp.equals( wSignal.semaphore, wSignal.gettype(sg->base.properties(sg)) );
    }
  }
  return semaphore;
}

static Boolean _red( iIBlockBase inst, Boolean distant, Boolean reverse ) {
  iOBlockData data = Data(inst);
  Boolean semaphore = False;
  const char* sgId = NULL;

  if( distant )
    sgId = reverse ? wBlock.getwsignalR( data->props ):wBlock.getwsignal( data->props );
  else
    sgId = reverse ? wBlock.getsignalR( data->props ):wBlock.getsignal( data->props );
    
  if( sgId != NULL && StrOp.len( sgId ) > 0 ) {
    iOModel model = AppOp.getModel(  );
    iOSignal sg = ModelOp.getSignal( model, sgId );
    if( sg != NULL ) {
      if( !SignalOp.isManualOperated(sg) || (SignalOp.isManualOperated(sg) && SignalOp.isResetManualOperated(sg)) )
        SignalOp.red( sg );
      semaphore = StrOp.equals( wSignal.semaphore, wSignal.gettype(sg->base.properties(sg)) );
    }
  }

  if( !distant ) {
    const char* sgIdW = reverse ? wBlock.getwsignalR( data->props ):wBlock.getwsignal( data->props );
    Boolean blank = reverse ? wBlock.isblankatredsignalR( data->props ):wBlock.isblankatredsignal( data->props );
    if( sgIdW != NULL && blank ) {
		  iOModel model = AppOp.getModel(  );
		  iOSignal sg = ModelOp.getSignal( model, sgIdW );
		  if( sg != NULL ) {
		    SignalOp.blank( sg );
		  }
    }
  }

  return semaphore;

}


static obj _hasManualSignal( iIBlockBase inst, Boolean distant, Boolean reverse ) {
  iOBlockData data = Data(inst);
  const char* sgId = NULL;

  if( distant )
    sgId = reverse ? wBlock.getwsignalR( data->props ):wBlock.getwsignal( data->props );
  else
    sgId = reverse ? wBlock.getsignalR( data->props ):wBlock.getsignal( data->props );

  if( sgId != NULL && StrOp.len( sgId ) > 0 ) {
    iOModel model = AppOp.getModel(  );
    iOSignal sg = ModelOp.getSignal( model, sgId );
    if( sg != NULL && SignalOp.isManualOperated(sg) ) {
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
          "block [%s] has a manual operated signal [%s] blockside=%s", inst->base.id(inst), sgId, reverse?"+":"-" );
      return (obj)sg;
    }
  }
  return NULL;

}

/**
 * Checks for property changes.
 * todo: Range checking?
 */
static void _modify( iOBlock inst, iONode props ) {
  iOBlockData data = Data(inst);
  int cnt = NodeOp.getAttrCnt( props );
  Boolean move = StrOp.equals( wModelCmd.getcmd( props ), wModelCmd.move );

  if( data->props == NULL ) {
    NodeOp.base.del(props);
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "block [%s][%s] properties are empty.", wBlock.getid(props), wItem.getprev_id(props));
    return;
  }

  int i = 0;
  for( i = 0; i < cnt; i++ ) {
    iOAttr attr = NodeOp.getAttr( props, i );
    const char* name  = AttrOp.getName( attr );
    const char* value = AttrOp.getVal( attr );

    if( StrOp.equals("id", name) && StrOp.equals( value, wBlock.getid(data->props) ) )
      continue; /* skip to avoid making invalid pointers */
    if( StrOp.equals("entering", name) )
      continue;
    if( StrOp.equals("reserved", name) )
      continue;
    if( StrOp.equals("updateenterside", name) )
      continue;

    NodeOp.setStr( data->props, name, value );
  }
  data->id = wBlock.getid( data->props );

  if( !move ) {
    __resetFeedbackEvents( inst );

    cnt = NodeOp.getChildCnt( data->props );
    while( cnt > 0 ) {
      iONode child = NodeOp.getChild( data->props, 0 );
      iONode removedChild = NodeOp.removeChild( data->props, child );
      if( removedChild != NULL) {
        NodeOp.base.del(removedChild);
      }
      cnt = NodeOp.getChildCnt( data->props );
    }
    cnt = NodeOp.getChildCnt( props );
    for( i = 0; i < cnt; i++ ) {
      iONode child = NodeOp.getChild( props, i );
      NodeOp.addChild( data->props, (iONode)NodeOp.base.clone(child) );
    }

    /* re-init callback for all feedbacks: */
    __initFeedbackEvents( inst );

    /* re-init timer */
    data->timer  = wBlock.getevttimer( data->props );
    data->timer2 = wBlock.getevttimer2( data->props );
    data->forceblocktimer = wBlock.isforceblocktimer( data->props );
  }
  else {
    NodeOp.removeAttrByName(data->props, "cmd");
  }

  /* Broadcast to clients. */
  {
    iONode clone = (iONode)props->base.clone( data->props );
    AppOp.broadcastEvent( clone );
  }

  props->base.del(props);
}

static const char* _tableHdr(void) {
  return "<tr bgcolor=\"#CCCCCC\"><th>BlockID</th><th>fba</th><th>fbb</th><th>x</th><th>y</th><th>z</th></tr>\n";
}

static char* _toHtml( void* inst ) {
  iOBlockData data = Data((iOBlock)inst);
  return StrOp.fmt( "<tr><td>%s</td><td>%s</td><td>%s</td><td align=\"right\">%d</td><td align=\"right\">%d</td><td align=\"right\">%d</td></tr>\n",
      NodeOp.getStr( data->props, "id", "?" ),
      NodeOp.getStr( data->props, "fba", "?" ),
      NodeOp.getStr( data->props, "fbb", "?" ),
      NodeOp.getInt( data->props, "x", 0 ),
      NodeOp.getInt( data->props, "y", 0 ),
      NodeOp.getInt( data->props, "z", 0 )
      );
}


static const char* _getState( iIBlockBase inst ) {
  iOBlockData data = Data((iOBlock)inst);
  return wBlock.getstate(data->props);
}


static char* _getForm( void* inst ) {
  iOBlockData data = Data((iOBlock)inst);
  return NULL;
}


static char* _postForm( void* inst, const char* postdata ) {
  iOBlockData data = Data((iOBlock)inst);
  char* reply = StrOp.fmt( "Thanks!<br>" );
  return reply;
}


static Boolean _isTerminalStation( iIBlockBase inst ) {
  iOBlockData data = Data(inst);
  return wBlock.isterminalstation( data->props );
}


static Boolean _hasEnter2Route( iIBlockBase inst, const char* fromBlockID ) {
  iOBlockData data = Data(inst);
  iONode fbevt = wBlock.getfbevent( data->props );

  while( fbevt != NULL ) {
    const char* fromid = wFeedbackEvent.getfrom( fbevt );

    if( StrOp.equals( fromid, fromBlockID ) ) {
      if( StrOp.equals( wFeedbackEvent.enter2route_event, wFeedbackEvent.getaction(fbevt) ) )
        return True;
    }
    fbevt = wBlock.nextfbevent( data->props, fbevt );
  };

  return False;
}


static Boolean _hasPre2In( iIBlockBase inst, const char* fromBlockID ) {
  iOBlockData data = Data(inst);
  iONode fbevt = wBlock.getfbevent( data->props );

  while( fbevt != NULL ) {
    const char* fromid = wFeedbackEvent.getfrom( fbevt );

    if( StrOp.equals( fromid, fromBlockID ) ) {
      if( StrOp.equals( wFeedbackEvent.pre2in_event, wFeedbackEvent.getaction(fbevt) ) )
        return True;
    }
    fbevt = wBlock.nextfbevent( data->props, fbevt );
  };

  return False;
}


static void _reset( iIBlockBase inst, Boolean saveCurBlock ) {
  iOBlockData data = Data(inst);
  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
             "reset block [%s]", data->id );
  BlockOp.unLockForGroup(inst, data->locIdGroup );
  /*Unlock the occupying must be done manual */
  /*BlockOp.unLock(inst, data->locId);*/
  BlockOp.resetTrigs(inst);
  if( data->locId != NULL && StrOp.len( data->locId ) > 0 ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
             "reseted block [%s] is reserved by [%s]", data->id, data->locId );
  }

  _resetTD(inst);
  data->arrivalPending = False;
  data->crossing = False;
}

static void _acceptIdent( iIBlockBase inst, Boolean accept ) {
  iOBlockData data = Data(inst);
  data->acceptident = accept;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
               "ACCEPT IDENT for block [%s] is %s", data->id, accept?"ON":"OFF" );

  if( data->acceptident != wBlock.isacceptident(data->props) ) {
    iONode nodeD = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
    wBlock.setid( nodeD, data->id );
    wBlock.setacceptident(nodeD, data->acceptident);
    wBlock.setmasterid(nodeD, wBlock.getmasterid(data->props));
    AppOp.broadcastEvent( nodeD );

    wBlock.setacceptident(data->props, data->acceptident);
  }
}


static void _setClass( iIBlockBase inst, const char* p_Class ) {
  iOBlockData data = Data(inst);
  wBlock.setclass(data->props, p_Class);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "set class to [%s] in block [%s]", wBlock.getclass(data->props),  data->id );
  /* Broadcast to clients. */
  AppOp.broadcastEvent( (iONode)NodeOp.base.clone( data->props ) );
}


static void _setMasterID( iIBlockBase inst, const char* masterid ) {
  iOBlockData data = Data(inst);
  wBlock.setmasterid(data->props, masterid);
}

static Boolean _hasClass( iIBlockBase inst, const char* class ) {
  iOBlockData data = Data(inst);
  const char* l_class = wBlock.getclass(data->props);
  return StrOp.find(l_class, class) != NULL ? True:False;
}




static iOBlock _inst( iONode props ) {
  iOBlock     block = allocMem( sizeof( struct OBlock ) );
  iOBlockData data  = allocMem( sizeof( struct OBlockData ) );

  /* OBase operations */
  MemOp.basecpy( block, &BlockOp, 0, sizeof( struct OBlock ), data );

  data->props = props;
  data->locId = NodeOp.getStr( props, "locid", NULL );
  data->minbklc = wCtrl.getminbklc( AppOp.getIniNode( wCtrl.name() ) );
  data->fbEvents = MapOp.inst();

  data->timer  = wBlock.getevttimer( props );
  data->timer2 = wBlock.getevttimer2( props );

  data->forceblocktimer = wBlock.isforceblocktimer( props );
  data->acceptident = wBlock.isacceptident( props );
  data->id = wBlock.getid( props );

  /*wBlock.setacceptident( data->props, False );*/
  wBlock.setreserved( data->props, False );
  wBlock.setentering( data->props, False );
  wBlock.setupdateenterside( data->props, False );
  wBlock.setmanagerid( data->props, "" );

  data->muxLock = MutexOp.inst( NULL, True );

  data->fifoList = ListOp.inst();
  data->muxFiFO = MutexOp.inst( NULL, True );
  wBlock.setfifoids(data->props, "" );

  NodeOp.removeAttrByName(data->props, "cmd");

  if( StrOp.equals(wBlock.shortcut, wBlock.getstate(props))) {
    wBlock.setstate(props, wBlock.open);
  }

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "inst for %s", data->id );

  if( !wBlock.isremote(props) )
    __initFeedbackEvents(block);

  instCnt++;

  return block;
}


/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocrail/impl/block.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
