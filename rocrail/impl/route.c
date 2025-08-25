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

#include "rocrail/impl/route_impl.h"
#include "rocrail/public/app.h"
#include "rocrail/public/model.h"
#include "rocrail/public/switch.h"
#include "rocrail/public/signal.h"
#include "rocrail/public/output.h"
#include "rocrail/public/tt.h"
#include "rocrail/public/seltab.h"
#include "rocrail/public/r2rnet.h"
#include "rocrail/public/var.h"

#include "rocs/public/doc.h"
#include "rocs/public/trace.h"
#include "rocs/public/node.h"
#include "rocs/public/mem.h"
#include "rocs/public/str.h"
#include "rocs/public/strtok.h"
#include "rocs/public/thread.h"


#include "rocrail/wrapper/public/Action.h"
#include "rocrail/wrapper/public/Route.h"
#include "rocrail/wrapper/public/RouteCondition.h"
#include "rocrail/wrapper/public/SwitchCmd.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/Turntable.h"
#include "rocrail/wrapper/public/SelTab.h"
#include "rocrail/wrapper/public/FeedbackEvent.h"
#include "rocrail/wrapper/public/Ctrl.h"
#include "rocrail/wrapper/public/FreeRail.h"
#include "rocrail/wrapper/public/ActionCtrl.h"
#include "rocrail/wrapper/public/PermInclude.h"
#include "rocrail/wrapper/public/PermExclude.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Item.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/SpeedCondition.h"
#include "rocrail/wrapper/public/Variable.h"

static int instCnt = 0;
static iOMutex __routeSem = NULL;

static Boolean __checkClass(iORoute inst, const char* classStr,  iOLoc loc);

/*
 ***** OBase functions.
 */
static const char* __id( void* inst ) {
  iORouteData o = Data(inst);
  return wRoute.getid( o->props );
}

static void __ctcAction( void* inst, iONode evt ) {
  iORouteData data = Data(inst);


  if( StrOp.equals( wFeedback.name(), NodeOp.getName( (iONode)evt ) ) ) {
    Boolean state = wFeedback.isstate(evt);

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "ctc action %d", wFeedback.getaddr(evt));

    if( wFeedback.getaddr(evt) == wRoute.getctcaddr1(data->props) ) {
      data->ctc1 = state;
    }
    else if( wFeedback.getaddr(evt) == wRoute.getctcaddr2(data->props) ) {
      data->ctc2 = state;
    }
    else if( wFeedback.getaddr(evt) == wRoute.getctcaddr3(data->props) ) {
      data->ctc3 = state;
    }
  }
  else if( StrOp.equals( wOutput.name(), NodeOp.getName( (iONode)evt ) ) ) {
    Boolean state = StrOp.equals( wSwitch.turnout, wSwitch.getstate(evt)) | StrOp.equals( wOutput.on, wItem.getstate(evt));

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "ctc action %s=%s", wOutput.getid(evt), wItem.getstate(evt));

    if( wRoute.getctcoutput1(data->props) != NULL && StrOp.equals( wOutput.getid(evt), wRoute.getctcoutput1(data->props) ) ) {
      data->ctc1 = state;
    }
    if( wRoute.getctcoutput2(data->props) != NULL && StrOp.equals( wOutput.getid(evt), wRoute.getctcoutput2(data->props) ) ) {
      data->ctc2 = state;
    }
    if( wRoute.getctcoutput3(data->props) != NULL && StrOp.equals( wOutput.getid(evt), wRoute.getctcoutput3(data->props) ) ) {
      data->ctc3 = state;
    }
  }

  if( data->ctc2 && data->ctc3 ) {
    /* clear */
    RouteOp.unLock( (iORoute)inst, wRoute.getid( data->props ), NULL, True, False );
  }

  if( data->ctc1 && data->ctc2 && !data->ctc3 ) {
    if( RouteOp.lock( (iORoute)inst, wRoute.getid( data->props ), False, True ) ) {
      RouteOp.go((iORoute)inst);
    }
  }
}


static void* __event( void* inst, const void* evt ) {
  iORouteData data = Data(inst);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
      "ctc event [%s] for route [%s] with status %s",
      wItem.getid((iONode)evt), wRoute.getid( data->props ), wItem.getstate((iONode)evt));

  if( StrOp.equals( wFeedback.name(), NodeOp.getName( (iONode)evt ) ) ) {
    __ctcAction(inst, (iONode)evt);
  }
  else if( StrOp.equals( wOutput.name(), NodeOp.getName( (iONode)evt ) ) ) {
    __ctcAction(inst, (iONode)evt);
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
  iORouteData data = Data(inst);
  return (char*)RouteOp.getId( (iORoute)inst );
}
static void __del(void* inst) {
  iORouteData data = Data(inst);
  freeMem( data );
  freeMem( inst );
  instCnt--;
}
static void* __properties(void* inst) {
  iORouteData data = Data(inst);
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


static void __initCTC(iORoute inst, Boolean remove) {
  iORouteData data  = Data(inst);
  iOModel      model = AppOp.getModel();

  if( wRoute.getctcaddr1(data->props) > 0 ) {
    char* key = FBackOp.createAddrKey(wRoute.getctcbus1(data->props), wRoute.getctcaddr1(data->props), wRoute.getctciid1(data->props));
    if( remove )
      ModelOp.removeFbKey( model, key, (obj)inst );
    else
      ModelOp.addFbKey( model, key, (obj)inst );
    StrOp.free(key);
  }

  if( wRoute.getctcaddr2(data->props) > 0 ) {
    char* key = FBackOp.createAddrKey(wRoute.getctcbus2(data->props), wRoute.getctcaddr2(data->props), wRoute.getctciid2(data->props));
    if( remove )
      ModelOp.removeFbKey( model, key, (obj)inst );
    else
      ModelOp.addFbKey( model, key, (obj)inst );
    StrOp.free(key);
  }

  if( wRoute.getctcaddr3(data->props) > 0 ) {
    char* key = FBackOp.createAddrKey(wRoute.getctcbus3(data->props), wRoute.getctcaddr3(data->props), wRoute.getctciid3(data->props));
    if( remove )
      ModelOp.removeFbKey( model, key, (obj)inst );
    else
      ModelOp.addFbKey( model, key, (obj)inst );
    StrOp.free(key);
  }

  if( wRoute.getctcoutput1(data->props) != NULL && StrOp.len(wRoute.getctcoutput1(data->props)) > 0 ) {
    iOOutput co = ModelOp.getOutput(model, wRoute.getctcoutput1(data->props));
    if( co != NULL ) {
      if( remove )
        OutputOp.removeListener(co, (obj)inst);
      else
        OutputOp.addListener(co, (obj)inst);
    }
  }
  if( wRoute.getctcoutput2(data->props) != NULL && StrOp.len(wRoute.getctcoutput2(data->props)) > 0 ) {
    iOOutput co = ModelOp.getOutput(model, wRoute.getctcoutput2(data->props));
    if( co != NULL ) {
      if( remove )
        OutputOp.removeListener(co, (obj)inst);
      else
        OutputOp.addListener(co, (obj)inst);
    }
  }
  if( wRoute.getctcoutput3(data->props) != NULL && StrOp.len(wRoute.getctcoutput3(data->props)) > 0 ) {
    iOOutput co = ModelOp.getOutput(model, wRoute.getctcoutput3(data->props));
    if( co != NULL ) {
      if( remove )
        OutputOp.removeListener(co, (obj)inst);
      else
        OutputOp.addListener(co, (obj)inst);
    }
  }

}


static void __broadcast(iORoute inst) {
  iORouteData o = Data(inst);
  /* Broadcast to clients. */
  iOModel model = AppOp.getModel(  );
  iONode nodeD = NodeOp.inst( wRoute.name(), NULL, ELEMENT_NODE );
  const char* routeId = wRoute.getid(o->props);
  iOList aliases = ModelOp.getRouteAliases( model, routeId );

  wRoute.setlocid(nodeD, o->lockedId );

  if( wRoute.getstatus(o->props) != wRoute.status_closed ) {
    if( o->testlocked ) {
      wRoute.setstatus( nodeD, wRoute.status_locked);
      o->testlocked = False;
    }
    else if( o->lockedId == NULL || StrOp.len(o->lockedId) == 0 )
      wRoute.setstatus( nodeD, wRoute.status_free);
    else if( o->lockedId != NULL && StrOp.len(o->lockedId) > 0 )
      wRoute.setstatus( nodeD, wRoute.status_locked);
  }
  else if( wRoute.getstatus(o->props) == wRoute.status_closed && RouteOp.isLocked(inst) ) {
    /* only signal closed if the route is no longer locked */
    wRoute.setstatus( nodeD, wRoute.status_locked);
  }
  else {
    wRoute.setstatus( nodeD, wRoute.getstatus(o->props));
  }
  wRoute.setshow( nodeD, wRoute.isshow(o->props));

  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "status of route %s is %d, locked by %s",
      wRoute.getid(o->props), wRoute.getstatus( nodeD), o->lockedId == NULL ? "-":o->lockedId );

  if( aliases == NULL ) {
    wRoute.setid( nodeD, routeId );
    AppOp.broadcastEvent( nodeD );
  }
  else {
    int i = 0;
    for( i = 0; i < ListOp.size(aliases); i++ ) {
      iONode routeseg = (iONode)ListOp.get( aliases, i );
      wRoute.setid( nodeD, wRoute.getid(routeseg) );
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "broadcast alias [%s] for route [%s] with status %d",
          wRoute.getid(routeseg), wRoute.getid(o->props), wRoute.getstatus( nodeD) );
      AppOp.broadcastEvent( (iONode)NodeOp.base.clone(nodeD) );
    }
    NodeOp.base.del(nodeD);
  }

}


static void __checkAction( iORoute inst, const char* state ) {
  iORouteData data   = Data(inst);
  iOModel     model  = AppOp.getModel();
  iONode      action = wRoute.getactionctrl( data->props );

  /* loop over all actions */
  while( action != NULL ) {

    if( StrOp.len(wActionCtrl.getstate( action )) == 0 ||
        StrOp.equals(state, wActionCtrl.getstate( action )) )
    {

      iOAction Action = ModelOp.getAction(model, wActionCtrl.getid( action ));
      if( Action != NULL ) {
        wActionCtrl.setlcid(action, data->lockedId);
        if(data->lockedId != NULL && StrOp.len(data->lockedId) > 0 ) {
          iOLoc lc = ModelOp.getLoc( AppOp.getModel(), data->lockedId, NULL, False );
          if( lc != NULL ) {
            wActionCtrl.setlcclass(action, LocOp.getClass(lc));
          }
        }
        ActionOp.exec(Action, action);
      }
    }
    else {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "%s action state does not match: [%s-%s]",
          wRoute.getid(data->props), wActionCtrl.getstate( action ), state );
    }

    action = wRoute.nextactionctrl( data->props, action );
  }
}






/*
 ***** _Public functions.
 */
static Boolean __syncGo( iORoute inst, Boolean unlock ) {
  iORouteData o = Data(inst);
  iOModel model = AppOp.getModel(  );
  iONode sw = wRoute.getswcmd( o->props );
  int error = 0;
  int retry = 0;
  iONode sw_retry = NULL;
  int swdelay = 0;


  __checkAction(inst, "go");

  while( sw != NULL ) {
    const char* swId  = wSwitchCmd.getid( sw );
    const char* swCmd = wSwitchCmd.getcmd( sw );
    Boolean     lock  = wSwitchCmd.islock(sw);
    Boolean   atfree  = wSwitchCmd.isatfree(sw);
    Boolean   isState = False;

    if( atfree != unlock ) {
      sw = wRoute.nextswcmd( o->props, sw );
      ThreadOp.sleep(0);
      continue;
    }

    if( atfree ) {
      lock = False;
    }

    if( StrOp.equals( wSwitchCmd.cmd_track, swCmd ) ) {
      iOTT isw = ModelOp.getTurntable( model, swId );
      iOSelTab iseltab = ModelOp.getSelectiontable( model, swId );
      if( isw != NULL ) {
        iONode cmd = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
        wTurntable.setcmd( cmd,  NodeOp.getStr( sw, "track", "0") );

        /* The byroute flag will disable the option to check if the wanted track is opposite of the bridge
         * which will lead to wrong loco placing.
         * ToDo: Try to make it possibel.
         * */
        wTurntable.setcmdbyroute( cmd,  True );

        TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "go() %s:%s.%d", swId, swCmd, wSwitchCmd.gettrack(sw) );
        if( !TTOp.cmd( (iIBlockBase)isw, cmd ) ) {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Turntable could not process command." );
          return False;
        }
        else {
          if( !TTOp.getRunDir(isw) ) {
            TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "Turntable 180 route..." );
            iOLoc lc = ModelOp.getLoc(model, o->lockedId, NULL, False );
            TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "[%s] must (re)swap placing on the turntable.", o->lockedId );
            if( lc != NULL ) {
              LocOp.swapBlockEnterSide(lc, NULL);
              LocOp.swapPlacing(lc, NULL, False, True);
            }
          }
        }
      }
      else if( iseltab != NULL ) {
        iONode cmd = NodeOp.inst( wSelTab.name(), NULL, ELEMENT_NODE );
        wSelTab.setcmd( cmd,  NodeOp.getStr( sw, "track", "0") );
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "go() %s:%s.%d", swId, swCmd, wSwitchCmd.gettrack(sw) );
        if( !SelTabOp.cmd( (iIBlockBase)iseltab, cmd ) ) {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Seltabtable could not process command." );
          return False;
        }
      }
      else
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "*PANIC* No turntable object found for %s:%s", swId, swCmd );
    }
    else if( StrOp.equals( wSignal.aspect, swCmd ) )
    {
      iOSignal isg = ModelOp.getSignal( model, swId );

      if( isg != NULL ) {
        iONode cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
        wSignal.setcmd( cmd, wSignal.aspect );
        wSignal.setaspect( cmd, NodeOp.getInt( sw, "track", 0) );
        wSignal.setpause( cmd, wCtrl.getrouteswtime( wFreeRail.getctrl( AppOp.getIni() ) ) * swdelay );
        swdelay++;
        SignalOp.cmd(isg, cmd, True);
      }
    }
    else if( StrOp.equals( wSignal.red, swCmd ) ||
             StrOp.equals( wSignal.green, swCmd ) ||
             StrOp.equals( wSignal.yellow, swCmd ) ||
             StrOp.equals( wSignal.white, swCmd ) )
    {
      iOSignal isg = ModelOp.getSignal( model, swId );

      if( isg != NULL ) {
        iONode cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
        wSignal.setcmd( cmd, swCmd );
        wSignal.setpause( cmd, wCtrl.getrouteswtime( wFreeRail.getctrl( AppOp.getIni() ) ) * swdelay );
        swdelay++;
        SignalOp.cmd(isg, cmd, True);
      }
    }
    else if( StrOp.equals( wOutput.on   , swCmd ) ||
             StrOp.equals( wOutput.off , swCmd ) )
    {
      iOOutput ico = ModelOp.getOutput( model, swId );

      if( ico != NULL ) {
        iONode cmd = NodeOp.inst( wOutput.name(), NULL, ELEMENT_NODE );
        wOutput.setcmd( cmd, swCmd );
        wOutput.setpause( cmd, wCtrl.getrouteswtime( wFreeRail.getctrl( AppOp.getIni() ) ) * swdelay );
        swdelay++;
        OutputOp.cmd(ico, cmd, True);
      }
    }
    else {
      iOSwitch isw = ModelOp.getSwitch( model, swId );

      if( isw == NULL ) {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "*PANIC* No switch object found for %s:%s", swId, swCmd );
      }
      else if( SwitchOp.isState( isw, swCmd ) && wCtrl.isskipsetsw( wFreeRail.getctrl(AppOp.getIni())) ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "switch[%s] already in position [%s]; skip command", swId, swCmd );
      }
      else {
        iONode cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
        wSwitch.setcmd( cmd, swCmd );
        wSwitch.setpause( cmd, wCtrl.getrouteswtime( wFreeRail.getctrl( AppOp.getIni() ) ) * swdelay );
        TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "go() %s:%s", swId, swCmd );
        swdelay++;
        if( SwitchOp.has2Units(isw) )
          swdelay++;

        if( !SwitchOp.cmd( isw, cmd, True, 0, &error, o->lockedId ) && lock ) {
          if( error == CMD_ERROR ) {
            TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "unable to switch %s:%s", swId, swCmd );
            return False;
          }
          else if( error == CMD_RETRY ) {
            TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "retry on %s:%s", swId, swCmd );
            ThreadOp.sleep( 10 );

            if( sw == sw_retry ) {
              retry++;
            }
            else {
              sw_retry = sw;
              retry = 0;
            }

            if( retry > 9 ) {
              TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "retry did not work on %s:%s", swId, swCmd );
              return False;
            }
            else
              continue;
          }
          else {
            TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Error on switching %s:%s", swId, swCmd );
            return False;
          }
        }
        ThreadOp.sleep( 10 );
      }
    }

    sw = wRoute.nextswcmd( o->props, sw );

  };

  /* Inform bka. */
  {
    iOModel model = AppOp.getModel(  );
    iIBlockBase bka = ModelOp.getBlock( model, RouteOp.getFromBlock( inst ) );
    iIBlockBase bkb = ModelOp.getBlock( model, RouteOp.getToBlock( inst ) );
  }

  __broadcast(inst);

  return True;
}


static Boolean _go( iORoute inst ) {
  Boolean ok = False;
  if( __routeSem == NULL ) {
    __routeSem = MutexOp.inst(NULL, True);
  }

  if( wCtrl.issyncroutes( wFreeRail.getctrl(AppOp.getIni())) ) {
    if( MutexOp.trywait( __routeSem, wCtrl.getsyncroutetimeout( wFreeRail.getctrl(AppOp.getIni())) ) ) {
      ok = __syncGo(inst, False);
      MutexOp.post( __routeSem );
    }
    else {
      ok = __syncGo(inst, False);
    }
  }
  else {
    ok = __syncGo(inst, False);
  }

  return ok;
}



static Boolean _cmd( iORoute inst, iONode nodeA ) {
  iORouteData o = Data(inst);
  Boolean ok = False;
  const char* cmdStr = wRoute.getcmd( nodeA );
  const char* state  = wBlock.getstate( nodeA );

  if( StrOp.equals( wRoute.go, cmdStr ) ) {
    ok = _go( inst );
  }
  else if( StrOp.equals( wRoute.classset, cmdStr ) ) {
    RouteOp.setClass(inst, wRoute.getclass(nodeA));
  }
  else if( StrOp.equals( wSwitch.unlock, cmdStr ) ) {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "reset route %s", RouteOp.getId(inst) );
    RouteOp.reset(inst);
  }
  else if( state != NULL && StrOp.equals( wBlock.closed, state ) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "close route %s", RouteOp.getId(inst) );
    wRoute.setstatus(o->props, wRoute.status_closed);
    __broadcast(inst);
  }
  else if( state != NULL && StrOp.equals( wBlock.open, state ) && wRoute.getstatus(o->props) == wRoute.status_closed ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "open route %s", RouteOp.getId(inst) );
    wRoute.setstatus(o->props, wRoute.status_free);
    __broadcast(inst);
  }
  else if( StrOp.equals( wRoute.force, cmdStr ) ) {
    if( !RouteOp.isFree(inst, "__manualcommand__") )
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Route %s is locked and will be switched forced by hand.", RouteOp.getId(inst) );
    ok = _go( inst );
  }
  else if( StrOp.equals( wRoute.test, cmdStr ) ) {
    if( RouteOp.isFree(inst, "__manualcommand__") ) {
      o->testlocked = (wRoute.getstatus(nodeA) == wRoute.status_locked);
      ok = _go( inst );
    }
    else
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Route %s is locked and cannot be switched by hand.", RouteOp.getId(inst) );
  }

  /* Cleanup Node1 */
  nodeA->base.del(nodeA);
  return ok;
}

static const char* _getId( iORoute inst ) {
  iORouteData o = Data(inst);
  return wRoute.getid( o->props );
}

static void* _getProperties( void* inst ) {
  iORouteData o = Data((iORoute)inst);
  return o->props;
}

static const char* _getFromBlock( iORoute inst ) {
  iORouteData o = Data(inst);
  return wRoute.getbka( o->props );
}

static const char* _getToBlock( iORoute inst ) {
  iORouteData o = Data(inst);
  return wRoute.getbkb( o->props );
}

static Boolean _getBlockSignalSide( iORoute inst, const char* bkid ) {
  iORouteData o = Data(inst);
  if( StrOp.equals( wRoute.getbka(o->props), bkid)) {
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "blockid [%s] in route [%s] is %s (from)", bkid, RouteOp.getId(inst), wRoute.isbkaside( o->props )?"+":"-" );
    return wRoute.isbkaside( o->props );
  }
  else {
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "blockid [%s] in route [%s] is %s (to)", bkid, RouteOp.getId(inst), wRoute.isbkaside( o->props )?"+":"-" );
    return !wRoute.isbkbside( o->props );
  }
}

static Boolean _getToBlockSide( iORoute inst ) {
  iORouteData o = Data(inst);
  return wRoute.isbkbside( o->props );
}

static Boolean _getFromBlockSide( iORoute inst ) {
  iORouteData o = Data(inst);
  return wRoute.isbkaside( o->props );
}

static Boolean _getDirection( iORoute inst, const char* blockid, Boolean* fromto ) {
  iORouteData o = Data(inst);

  /* in case of a managed block of a fiddle yard the manager ID is needed */
  blockid = ModelOp.getManagedID( AppOp.getModel(), blockid );

  if( R2RnetOp.compare( blockid, wRoute.getbka( o->props ) ) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "blockid [%s] in route [%s] is --from--", blockid, RouteOp.getId(inst) );
    *fromto = True;
    return True;
  }
  else if( R2RnetOp.compare( blockid, wRoute.getbkb( o->props ) ) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "blockid [%s] in route [%s] is --to--", blockid, RouteOp.getId(inst) );
    *fromto = False;
    return False;
  }
  else {
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "blockid [%s] is not part of this route", blockid );
    return False;
  }
}



static int __getSpeedCondPercent(iORoute inst, iOLoc loco) {
  iORouteData data = Data(inst);
  iOModel    model = AppOp.getModel();
  if( loco != NULL ) {
    iONode spcond = wRoute.getspeedcondition(data->props);
    while( spcond != NULL ) {
      if( wSpeedCondition.gettype(spcond) != NULL && StrOp.len(wSpeedCondition.gettype(spcond)) > 0 && !StrOp.equals( wSpeedCondition.gettype(spcond), wLoc.cargo_all)) {
        if( !StrOp.equals( wSpeedCondition.gettype(spcond), LocOp.getCargo(loco) ) ) {
          spcond = wRoute.nextspeedcondition(data->props, spcond);
          continue;
        }
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "speed condition %s fits to the loco %s type: %s",
            wSpeedCondition.getdesc(spcond), LocOp.getId(loco), wSpeedCondition.gettype(spcond) );
      }

      if( __checkClass(inst, wSpeedCondition.getclass(spcond), loco) ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "speed condition %s fits to the loco %s class: %s",
            wSpeedCondition.getdesc(spcond), LocOp.getId(loco), wSpeedCondition.getclass(spcond) );
      }
      else {
        spcond = wRoute.nextspeedcondition(data->props, spcond);
        continue;
      }

      if( wSpeedCondition.getvariable(spcond) != NULL && StrOp.len(wSpeedCondition.getvariable(spcond)) > 0 ) {
        const char* varid = wSpeedCondition.getvariable(spcond);
        const char* subid = wSpeedCondition.getvarsub(spcond);
        iONode var = NULL;

        if( subid != NULL && StrOp.len(subid) > 0 ) {
          char* key = StrOp.fmt( "%s%s", varid, subid );
          iOMap map = MapOp.inst();
          MapOp.put(map, "lcid", (obj)LocOp.getId(loco));
          MapOp.put(map, "lcclass", (obj)LocOp.getClass(loco));
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "speed condition variable key: [%s]", key);
          char* resolvedKey = TextOp.replaceAllSubstitutions(key, map);
          StrOp.free(key);
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "speed condition variable resolved key: [%s]", resolvedKey);
          var = ModelOp.getVariable( model, resolvedKey );
          StrOp.free(resolvedKey);
          MapOp.base.del(map);
        }
        else {
          var = ModelOp.getVariable( model, varid );
        }


        if( var != NULL ) {
          Boolean rc = True;
          const char* condvalStr = wSpeedCondition.getvalue(spcond);

          if( StrOp.len(condvalStr) > 0 ) {
            int condval = atoi(condvalStr+1);
            int varval  = wVariable.getvalue(var);

            if( condvalStr[0] == '=' )
              rc = varval == condval;
            else if( condvalStr[0] == '>' )
              rc = varval > condval;
            else if( condvalStr[0] == '<' )
              rc = varval < condval;
            else if( condvalStr[0] == '!' )
              rc = varval != condval;
            /* Text compare */
            else if( condvalStr[0] == '#' )
              rc = StrOp.equals(wVariable.gettext(var), condvalStr+1);
            else if( condvalStr[0] == '?' )
              rc = !StrOp.equals(wVariable.gettext(var), condvalStr+1);

            if( rc )
              TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "speed condition variable value [%d]%c[%d]", condval, condvalStr[0], varval);
          }

          if( !rc ) {
            spcond = wRoute.nextspeedcondition(data->props, spcond);
            continue;
          }

        }
        else {
          spcond = wRoute.nextspeedcondition(data->props, spcond);
          continue;
        }
      }
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "speed condition %s use %d percent speed for loco %s",
          wSpeedCondition.getdesc(spcond), wSpeedCondition.getpercent(spcond), LocOp.getId(loco) );
      return wSpeedCondition.getpercent(spcond);
    }
  }
  return wRoute.getspeedpercent(data->props);
}

static const char* _getVelocity( iORoute inst, int* percent, iOLoc loco ) {
  iORouteData data = Data(inst);
  const char* V_hint = wRoute.getspeed(data->props);
  *percent = __getSpeedCondPercent(inst, loco);
  return V_hint;
}

static int _getMaxKmh( iORoute inst ) {
  iORouteData data = Data(inst);
  return wRoute.getmaxkmh(data->props);
}


static Boolean _isSwapPost( iORoute inst ) {
  iORouteData o = Data(inst);
  return wRoute.isswappost( o->props );
}


static Boolean _hasSwitchCommands( iORoute inst ) {
  iORouteData data = Data(inst);
  iONode        sw = wRoute.getswcmd( data->props );
  return (sw != NULL ? True:False);
}


static Boolean _hasThrownSwitch( iORoute inst ) {
  iORouteData o = Data(inst);
  iOModel    model = AppOp.getModel(  );
  iONode        sw = wRoute.getswcmd( o->props );
  Boolean noreduce = wCtrl.isdisablerouteVreduce( wFreeRail.getctrl( AppOp.getIni() ) );

  if( noreduce )
    return False;

  if( wRoute.isreduceV(o->props) ) {
    while( sw != NULL ) {
      iOSwitch isw = ModelOp.getSwitch( model, wSwitchCmd.getid(sw) );

      if( isw != NULL && wSwitchCmd.isreduceV(sw) ) {
        iONode swProps = SwitchOp.base.properties(isw);
        if( StrOp.equals( wItem.gettype(swProps), wSwitch.dcrossing ) &&
            ( StrOp.equals( wSwitch.straight, wSwitchCmd.getcmd(sw) ) || StrOp.equals( wSwitch.turnout, wSwitchCmd.getcmd(sw) ) ) )
        {
          /* turnout on dcrossing is like straight -> do nothing */
        }
        else if( StrOp.equals( wItem.gettype(swProps), wSwitch.dcrossing ) &&
            ( StrOp.equals( wSwitch.left, wSwitchCmd.getcmd(sw) ) || StrOp.equals( wSwitch.right, wSwitchCmd.getcmd(sw) ) ) )
        {
          return True;
        }
        else if( StrOp.equals( wItem.gettype(swProps), wSwitch.twoway )) {
          /* twoway always -> reduce speed */
          return True;
        }
        else if( !StrOp.equals( wSwitch.straight, wSwitchCmd.getcmd(sw) ) ) {
          if( !wSwitch.isswapstraight(swProps) ) {
            /* everything not straight on all others -> reduce speed */
            return True;
          }
        }
        else if( StrOp.equals( wSwitch.straight, wSwitchCmd.getcmd(sw) ) ) {
          if( wSwitch.isswapstraight(swProps) ) {
            /* everything not straight on all others -> reduce speed */
            return True;
          }
        }
      }
      sw = wRoute.nextswcmd( o->props, sw );
    };
  }

  return False;
}

static Boolean __checkSwitches( iORoute inst, const char* id ) {
  iORouteData o = Data(inst);
  iOModel  model = AppOp.getModel(  );
  iONode      sw = wRoute.getswcmd( o->props );
  while( sw != NULL ) {
    const char* swId  = wSwitchCmd.getid( sw );
    const char* swCmd = wSwitchCmd.getcmd( sw );
    Boolean tt = StrOp.equals( wSwitchCmd.cmd_track, swCmd );
    Boolean output = StrOp.equals( wOutput.on, swCmd ) || StrOp.equals( wOutput.off, swCmd );
    Boolean lock = wSwitchCmd.islock(sw);

    if( StrOp.equals( wSignal.red, swCmd ) || StrOp.equals( wSignal.green, swCmd ) ||
        StrOp.equals( wSignal.yellow, swCmd ) || StrOp.equals( wSignal.white, swCmd ) || StrOp.equals( wSignal.aspect, swCmd ) )
    {
      iOSignal isw = ModelOp.getSignal( model, swId );
      if( isw == NULL ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "*PANIC* No signal object found for %s in route %s", swId, wRoute.getid(o->props) );
        return False;
      }
    }
    else if( tt ) {
      iOSelTab iseltab = ModelOp.getSelectiontable( model, swId );
      iOTT itt = ModelOp.getTurntable( model, swId );
      if( itt != NULL ) {
        if( TTOp.isLocked( itt, id ) )
          return False;
      }
      else if( iseltab != NULL ) {
        if( SelTabOp.isLocked( iseltab, id ) )
          return False;
      }
      else {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "*PANIC* No turntable object found for %s in route %s", swId, wRoute.getid(o->props) );
        return False;
      }
    }
    else if( output ) {

    }
    else {
      iOSwitch isw = ModelOp.getSwitch( model, swId );
      if( isw != NULL ) {
        if( lock && SwitchOp.isLocked( isw, id, False ) )
          return False;
      }
      else {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "*PANIC* No switch object found for %s in route %s", swId, wRoute.getid(o->props) );
        return False;
      }
    }

    sw = wRoute.nextswcmd( o->props, sw );
  };

  return True;
}

static Boolean __checkCrossingBlocks( iORoute inst, const char* id ) {
  iORouteData o = Data(inst);
  iOModel  model = AppOp.getModel(  );
  const char* bkc = wRoute.getbkc( o->props );
  if( bkc != NULL && StrOp.len( bkc ) > 0 ) {
    iOStrTok tok = StrTokOp.inst( bkc, ',' );

    while( StrTokOp.hasMoreTokens(tok) ) {
      const char* bk = StrTokOp.nextToken( tok );
      iIBlockBase block = ModelOp.getBlock( model, bk );
      if( block != NULL ) {
        if( !block->isFree( block, id ) ) {
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
              "route %s: crossing block [%s] is not free or closed.", wRoute.getid(o->props), bk );
          StrTokOp.base.del(tok);
          return False;
        }
      }
      else {
        TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "crossing block [%s] in route [%s] does not exist", bk, wRoute.getid(o->props) );
        StrTokOp.base.del(tok);
        return False;
      }
    };
    StrTokOp.base.del(tok);


  }

  return True;
}

static Boolean __unlockCrossingBlocks( iORoute inst, const char* id, const char** resblocks, Boolean force );
static Boolean __lockCrossingBlocks( iORoute inst, const char* id ) {
  iORouteData o = Data(inst);
  iOModel  model = AppOp.getModel(  );
  const char* bkc = wRoute.getbkc( o->props );
  if( bkc != NULL && StrOp.len( bkc ) > 0 ) {
    iOStrTok tok = StrTokOp.inst( bkc, ',' );

    while( StrTokOp.hasMoreTokens(tok) ) {
      const char* bk = StrTokOp.nextToken( tok );
      iIBlockBase block = ModelOp.getBlock( model, bk );
      if( block != NULL ) {
        if( !block->lock( block, id, "", wRoute.getid(o->props), True, False, False, 0, NULL, False ) ) {
          StrTokOp.base.del(tok);
          return False;
        }
      }
      else {
        TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "crossing block [%s] in route [%s] does not exist", bk, wRoute.getid(o->props) );
        StrTokOp.base.del(tok);
        return False;
      }
    };
    StrTokOp.base.del(tok);

  }

  return True;
}


static Boolean __isReservedBlock(const char* id, const char** resblocks) {
  int i = 0;
  if( resblocks != NULL ) {
    while( resblocks[i] != NULL ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
          "compare crossing block[%s] with reserved block[%s]", id, resblocks[i] );
      if( StrOp.equals(id, resblocks[i]) ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
            "crossing block[%s] equals reserved block[%s]", id, resblocks[i] );
        return True;
      }
      i++;
    }
  }
  return False;
}

static Boolean __unlockCrossingBlocks( iORoute inst, const char* id, const char** resblocks, Boolean force ) {
  iORouteData  o = Data(inst);
  Boolean      ok = True;
  iOModel   model = AppOp.getModel(  );
  const char* bkc = wRoute.getbkc( o->props );

  if( bkc != NULL && StrOp.len( bkc ) > 0 ) {
    iOStrTok tok = StrTokOp.inst( bkc, ',' );
    TraceOp.trc( name, force?TRCLEVEL_WARNING:TRCLEVEL_USER1, __LINE__, 9999, "%sunlocking crossing blocks [%s]", force?"Force ":"", bkc );

    while( StrTokOp.hasMoreTokens(tok) ) {
      const char* bk = StrTokOp.nextToken( tok );
      if( !__isReservedBlock(bk, resblocks) ) {
        iIBlockBase block = ModelOp.getBlock( model, bk );
        if( block != NULL ) {
          if( !block->unLock( block, id, wRoute.getid( o->props ) ) )
            ok = False;
        }
        else {
          TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "crossing block [%s] in route [%s] does not exist", bk, wRoute.getid(o->props) );
          ok = False;
        }
      }
    };
    StrTokOp.base.del(tok);

  }

  return ok;
}




static Boolean __unlockSwitches( iORoute inst, const char* locId, Boolean force );
static Boolean __lockSwitches( iORoute inst, const char* locId ) {
  iORouteData o = Data(inst);
  iOModel  model = AppOp.getModel(  );
  iONode      sw = wRoute.getswcmd( o->props );

  while( sw != NULL ) {
    const char* swId  = wSwitchCmd.getid( sw );
    const char* cmd  = wSwitchCmd.getcmd( sw );
    if( StrOp.equals( wSwitchCmd.cmd_track, cmd ) ) {
      iOSelTab iseltab = ModelOp.getSelectiontable( model, swId );
      iOTT itt = ModelOp.getTurntable( model, swId );
      if( itt != NULL ) {
        if( !TTOp.lock( (iIBlockBase)itt, locId, NULL, NULL, False, False,
            wRoute.isswappost( o->props ) ? !o->reverse : o->reverse, 0, NULL, False ) )
        {
          /* Rewind. */
          __unlockSwitches( inst, locId, False );
          return False;
        }
      }
      else if( iseltab != NULL ) {
        StrOp.free(o->routeLockId);
        o->routeLockId = StrOp.fmt( "%s%s%s", wRoute.routelock, wRoute.getid(o->props), locId );
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,"lock FY for route [%s]", o->routeLockId );
        Boolean reverse = False;
        reverse = ! wRoute.isbkbside( o->props );
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,"lock FY for route [%s] with reverse[%s]", o->routeLockId, reverse?"True":"False" );
        /* useBlockSide?!wRoute.isbkbside( o->props ):wRoute.isswappost( o->props ) ? !o->reverse : o->reverse */
        if( !SelTabOp.lock( (iIBlockBase)iseltab,
                locId,
                SelTabOp.isManager( iseltab)?o->routeLockId:locId,
                wRoute.getid(o->props),
                False,
                False,
                reverse, 0, NULL, False) ) {
          /* Rewind. */
          __unlockSwitches( inst, locId, False );
          return False;
        }
      }
    }
    else {
      iOSwitch isw = ModelOp.getSwitch( model, swId );
      if( isw != NULL ) {
        if( wSwitchCmd.islock( sw ) ) {
          if( !SwitchOp.lock( isw, locId, inst ) ) {
            /* Rewind. */
            __unlockSwitches( inst, locId, False );
            return False;
          }
        }
        else {
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
              "***** no locking wanted for switch [%s] for route [%s]", SwitchOp.getId(isw) , o->routeLockId );
        }
      }
    }

    sw = wRoute.nextswcmd( o->props, sw );
  };

  return True;
}

static Boolean __unlockSwitches( iORoute inst, const char* locId, Boolean force ) {
  iORouteData o = Data(inst);
  iOModel  model = AppOp.getModel(  );
  iONode      sw = wRoute.getswcmd( o->props );
  Boolean ok = True;
  while( sw != NULL ) {
    const char* swId  = wSwitchCmd.getid( sw );
    const char* cmd  = wSwitchCmd.getcmd( sw );
    if( StrOp.equals( wSwitchCmd.cmd_track, cmd ) ) {
      iOSelTab iseltab = ModelOp.getSelectiontable( model, swId );
      iOTT itt = ModelOp.getTurntable( model, swId );
      if( itt != NULL ) {
        if( !TTOp.unLock( (iIBlockBase)itt, locId, wRoute.getid( o->props ) ) ) {
          ok = False;
        }
      }
      else if( iseltab != NULL ) {
        StrOp.free(o->routeLockId);
        o->routeLockId = StrOp.fmt( "%s%s%s", wRoute.routelock, wRoute.getid(o->props), locId );
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,"unlock FY for route [%s]", o->routeLockId );
        if( !SelTabOp.unLock( (iIBlockBase)iseltab, SelTabOp.isManager( iseltab)?o->routeLockId:locId, wRoute.getid( o->props ) ) ) {
          ok = False;
        }
      }
    }
    else {
      iOSwitch isw = ModelOp.getSwitch( model, swId );
      if( isw != NULL ) {
        if( !SwitchOp.unLock( isw, locId, inst, force ) )
          ok = False;
      }
    }
    sw = wRoute.nextswcmd( o->props, sw );
  };

  return ok;
}


static Boolean __checkSensors( iORoute inst ) {
  iORouteData data = Data(inst);
  /* check all sensors... */

  iONode fbevt = wRoute.getfbevent( data->props );

  while( fbevt != NULL ) {
    iOFBack fb = ModelOp.getFBack( AppOp.getModel(), wFeedbackEvent.getid(fbevt));
    if( fb != NULL && FBackOp.getState(fb) ) {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
                     "Route [%s] is electrically occupied by sensor [%s]!",
                     RouteOp.getId( inst ), wFeedbackEvent.getid(fbevt) );

      return False;
    }
    else if( fb == NULL ) {
      iOOutput co = ModelOp.getOutput(AppOp.getModel(), wFeedbackEvent.getid(fbevt));
      if( co != NULL && OutputOp.isState(co, wOutput.on ) ) {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
                       "Route [%s] is electrically occupied by output [%s]!",
                       RouteOp.getId( inst ), wFeedbackEvent.getid(fbevt) );

        return False;
      }
    }
    fbevt = wRoute.nextfbevent( data->props, fbevt );
  };

  return True;
}


static Boolean __checkClass(iORoute inst, const char* classStr,  iOLoc loc) {
  iORouteData data = Data(inst);
  /* Check if the locos class fits. */
  if( classStr != NULL && StrOp.len(classStr) > 0 ) {
    Boolean classFits = False;
    const char* locoClass = LocOp.getClass(loc);
    iOStrTok tok = StrTokOp.inst(classStr, ',');
    while( StrTokOp.hasMoreTokens(tok) ) {
      if( StrOp.equals( StrTokOp.nextToken(tok), locoClass) ) {
        classFits = True;
        break;
      }
    }
    StrTokOp.base.del(tok);
    if( !classFits ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                     "Route [%s]; Class [%s] does not fit for loco [%s]",
                     wRoute.getid(data->props), locoClass, LocOp.getId( loc ) );
      return False;
    }
  }
  return True;
}

static Boolean _hasPermission( iORoute inst, iOLoc loc, const char* prevBlockID, Boolean mustChDir ) {
  iORouteData data = Data(inst);

  const char* id = LocOp.getId( loc );
  const char* train = LocOp.getTrain( loc );

  /* Permissions */
  iONode incl = wRoute.getincl( data->props );
  iONode excl = wRoute.getexcl( data->props );

  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                 "Check if loco [%s] has no permission to use route [%s]", id, wRoute.getid(data->props) );

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
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "empty include permission in route [%s]", wRoute.getid(data->props) );
      }
      incl = wRoute.nextincl( data->props, incl );
    };
    if( !included ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                     "Loc [%s] has no permission to use route [%s]",
                     id, wRoute.getid(data->props) );
      return False;
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
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "empty exclude permission in route [%s]", wRoute.getid(data->props) );
      }
      excl = wRoute.nextexcl( data->props, excl );
    };
    if( excluded ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                     "Loc [%s] has no permission to use route [%s]",
                     id, wRoute.getid(data->props) );
      return False;
    }
  }

  /* test if the cargo type is permitted */
  {
    const char* permtype = wRoute.gettypeperm(data->props);
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
                       "Loc [%s] has no permission to use route [%s]; cargo does not fit. (%s!=%s)",
                       id, wRoute.getid(data->props), permtype, cargo );
        return False;
      }
    }
  }

  /* test if the train length does not exceed the maxlen */
  {
    int maxlen = wRoute.getmaxlen(data->props);
    int minlen = wRoute.getminlen(data->props);
    if( maxlen > 0 ) {
      if( LocOp.getLen(loc) > maxlen ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                       "Loc [%s] has no permission to use route [%s]; train length exceeds the max. allowed length. (%d>%d)",
                       id, wRoute.getid(data->props), LocOp.getLen(loc), maxlen );
        return False;
      }
    }

    if( minlen > 0 ) {
      if( LocOp.getLen(loc) < minlen ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                       "Loc [%s] has no permission to use route [%s]; train length is less then the min. allowed length. (%d<%d)",
                       id, wRoute.getid(data->props), LocOp.getLen(loc), minlen );
        return False;
      }
    }


  }

  if( wRoute.iscommuter(data->props) && !LocOp.isCommuter(loc)) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                   "Loc [%s] has no permission to use route [%s]; only commuter trains are allowed.",
                   id, wRoute.getid(data->props) );
    return False;
  }

  if( wRoute.getplacing(data->props) > 0 ) {
    if( wRoute.getplacing(data->props) == 1 && !LocOp.getPlacing(loc) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                     "Loc [%s] has no permission to use route [%s]; only placing default is allowed.",
                     id, wRoute.getid(data->props) );
      return False;
    }
    else if( wRoute.getplacing(data->props) == 2 && LocOp.getPlacing(loc) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                     "Loc [%s] has no permission to use route [%s]; only placing swapped is allowed.",
                     id, wRoute.getid(data->props) );
      return False;
    }
  }

  if( wRoute.isnocommuter(data->props) && LocOp.isCommuter(loc)) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                   "Loc [%s] has no permission to use route [%s]; commuter trains are not allowed.",
                   id, wRoute.getid(data->props) );
    return False;
  }


  /* Check conditions: Return True if one condition is OK or no conditions are specified. */
  if( wRoute.getstcondition(data->props) != NULL )
  {
    iONode lc = LocOp.base.properties(loc);
    iONode cond = wRoute.getstcondition(data->props);
    
    const char* locoPrevBlockID = LocOp.getPrevBlock(loc);
    const char* locoCurBlockID  = LocOp.getCurBlock(loc);
    
    if( locoPrevBlockID == NULL )
      locoPrevBlockID = locoCurBlockID;

    while( cond != NULL ) {
      const char* prevbkid = wRouteCondition.getprevbkid(cond);
      Boolean notprevbk = wRouteCondition.isnotprevbk(cond);
      const char* traintype = wRouteCondition.gettype(cond);

      if( prevbkid != NULL && StrOp.len(prevbkid) > 0 ) {
        if( locoPrevBlockID != NULL && StrOp.equals(locoPrevBlockID, prevbkid) && notprevbk ) {
          cond = wRoute.nextstcondition(data->props, cond);
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                         "Condition does not match: equal blockID(%s), but should be unequal.", locoPrevBlockID );
          continue;
        }
        if( locoPrevBlockID != NULL && !StrOp.equals(locoPrevBlockID, prevbkid) && !notprevbk ) {
          cond = wRoute.nextstcondition(data->props, cond);
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                         "Condition does not match: unequal blockIDs(%s!=%s), but should be equal.", prevbkid, locoPrevBlockID );
          continue;
        }
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                       "Condition: %sblock %s, Loco prev=%s cur=%s prevcall=%s", notprevbk?"NOT ":"", prevbkid, locoPrevBlockID, locoCurBlockID, prevBlockID );
      }

      if( wRouteCondition.iscommuter(data->props) && !LocOp.isCommuter(loc) ) {
        cond = wRoute.nextstcondition(data->props, cond);
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                       "Condition does not match: must be a commuter train." );
        continue;
      }

      if( wRouteCondition.ischdir(data->props) && !mustChDir ) {
        cond = wRoute.nextstcondition(data->props, cond);
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                       "Condition does not match: must change direction for this route." );
        continue;
      }

      if( !wRouteCondition.ischdir(data->props) && mustChDir ) {
        cond = wRoute.nextstcondition(data->props, cond);
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                       "Condition does not match: should not change direction for this route." );
        continue;
      }

      if( traintype != NULL && StrOp.len(traintype) > 0 ) {
        const char* cargo    = LocOp.getCargo(loc);
        if( !StrOp.equals( traintype, cargo) && !StrOp.equals( traintype, "all") && !StrOp.equals( traintype, "none") && !StrOp.equals( cargo, "cleaning")) {
          cond = wRoute.nextstcondition(data->props, cond);
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                         "Condition does not match: train type must be %s but is %s.", traintype, cargo );
          continue;
        }
      }

      if( !wRouteCondition.isallowschedules(data->props) &&
          (LocOp.getSchedule(loc, NULL) != NULL &&
          StrOp.len(LocOp.getSchedule(loc, NULL)) > 0) )
      {
        cond = wRoute.nextstcondition(data->props, cond);
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                       "Condition does not match: running with schedule is not allowed for this route." );
        continue;
      }

      /**/
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "conditions OK");
      return True;
    };
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "conditions not OK");
    return False;
  }
  else {
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "*****No conditions");
  }

  /* Check if the locos class fits. */
  if( !__checkClass(inst, wRoute.getclass(data->props), loc) ) {
    return False;
  }


  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "*****OK");
  return True;

}



static Boolean _isManual( iORoute inst, Boolean* isset ) {
  iORouteData data = Data(inst);
  if( isset != NULL && wRoute.ismanual(data->props) && StrOp.equals( data->lockedId, wRoute.getid(data->props) ) )
    *isset = True;
  else if( isset != NULL )
    *isset = False;

  return wRoute.ismanual(data->props);
}


static Boolean _isLocked( iORoute inst ) {
  iORouteData data = Data(inst);

  if( data->lockedId != NULL && StrOp.len(data->lockedId) > 0 ) {
    return True;
  }
  return False;
}


static Boolean _isClosed( iORoute inst ) {
  iORouteData data = Data(inst);

  if( wRoute.status_closed == wRoute.getstatus(data->props) )
    return True;
  return False;
}


static Boolean _isState( iORoute inst, const char* state ) {
  iORouteData data = Data(inst);
  int l_state = wRoute.getstatus(data->props);
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "route [%s] is %d (%s)",
      RouteOp.getId(inst), l_state, state );
  if( l_state == wRoute.status_free && StrOp.equals("free", state ) )
    return True;
  if( l_state == wRoute.status_locked && StrOp.equals("locked", state ) )
    return True;
  if( l_state == wRoute.status_selected && StrOp.equals("selected", state ) )
    return True;
  if( l_state == wRoute.status_deselected && StrOp.equals("deselected", state ) )
    return True;
  if( l_state == wRoute.status_closed && StrOp.equals("closed", state ) )
    return True;
  return False;
}


static Boolean _isFree( iORoute inst, const char* id ) {
  iORouteData data = Data(inst);
  Boolean isset = False;

  if( wRoute.getstatus(data->props) == wRoute.status_closed ) {
    if( data->requestId == NULL || !StrOp.equals(data->requestId, id) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "route %s is closed (%s)", wRoute.getid(data->props), id!=NULL?id:"-" );
      data->requestId = id;
    }
    else {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "route %s is closed", wRoute.getid(data->props) );
    }

    return False;
  }

  if( data->lockedId != NULL && StrOp.equals(data->lockedId, id ) ) {
    /* it is free for itself */
    return True;
  }

  if( data->lockedId != NULL && StrOp.equals(data->lockedId, RouteOp.getId(inst) ) && RouteOp.isManual(inst, &isset) ) {
    /* it is free for itself */
    return isset ? True:False;
  }

  if( data->lockedId == NULL || StrOp.len( data->lockedId ) == 0 ) {
    /* Check all switches: */
    if( !__checkSensors( inst ) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "route %s sensors check failed", RouteOp.getId(inst) );
      return False;
    }

    if( !__checkSwitches( inst, id ) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "route %s switches check failed", RouteOp.getId(inst) );
      return False;
    }

    if( !__checkCrossingBlocks( inst, id ) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "route %s crossing blocks check failed", RouteOp.getId(inst) );
      return False;
    }

    return True;
  }
  else {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "route %s already locked by %s", RouteOp.getId(inst), data->lockedId );
    return False;
  }
}


static Boolean _lock( iORoute inst, const char* id, Boolean reverse, Boolean lockswitches ) {
  iORouteData o = Data(inst);
  Boolean isset = False;
  iOModel model = AppOp.getModel(  );
  iOLoc lc = NULL;
  o->reverse = reverse;

  if( o->lockedId != NULL && StrOp.equals(o->lockedId, RouteOp.getId(inst) ) && RouteOp.isManual(inst, &isset) ) {
    if( isset ) {
      o->lockedId = NULL;
    }
  }


  if( o->lockedId == NULL || StrOp.len( o->lockedId ) == 0 ) {
    /* Check all switches: */
    if( !__checkSensors( inst ) )
      return False;

    if( lockswitches && !__checkSwitches( inst, id ) )
      return False;

    if( !__checkCrossingBlocks( inst, id ) )
      return False;

    if( lockswitches && !__lockSwitches( inst, id ) )
      return False;

    if( !__lockCrossingBlocks( inst, id ) ) {
      if( lockswitches )
        __unlockSwitches( inst, id, False );
      return False;
    }

    o->lockedId = id;
    __checkAction(inst, "lock");

    __broadcast(inst);

    if( reverse && StrOp.equals( wRoute.reverse, wRoute.getcountcars(o->props) ) ) {
      iIBlockBase bk = ModelOp.getBlock( model, wRoute.getbkb( o->props ) );
      lc = ModelOp.getLoc(model, o->lockedId, NULL, False );
      if( bk != NULL && lc != NULL ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "reverse CAR COUNT = %d", LocOp.getCarCount(lc) );
        bk->setCarCount( bk, LocOp.getCarCount(lc) );
      }
      else {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "loco %s and or block %s undefined", o->lockedId, wRoute.getbkb( o->props ) );
      }
    }
    else if( !reverse && StrOp.equals( wRoute.forwards, wRoute.getcountcars(o->props) ) ) {
      iIBlockBase bk = ModelOp.getBlock( model, wRoute.getbkb( o->props ) );
      lc = ModelOp.getLoc(model, o->lockedId, NULL, False );
      if( bk != NULL && lc != NULL ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "forwards CAR COUNT = %d", LocOp.getCarCount(lc) );
        bk->setCarCount( bk, LocOp.getCarCount(lc) );
      }
      else {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "loco %s and or block %s undefined", o->lockedId, wRoute.getbkb( o->props ) );
      }
    }
    else {
      iIBlockBase bk = ModelOp.getBlock( model, reverse?wRoute.getbka( o->props ):wRoute.getbkb( o->props ) );
      if( bk != NULL )
        bk->setCarCount( bk, 0 );
      else {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "block %s undefined",reverse?wRoute.getbka( o->props ):wRoute.getbkb( o->props ) );
      }
    }


    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "Route [%s] locked by [%s]", RouteOp.getId(inst), o->lockedId );
    return True;
  }
  else if( StrOp.equals( id, o->lockedId ) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "Route [%s] still locked by [%s]", RouteOp.getId(inst), o->lockedId );
    return True;
  }
  else {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Route already locked by %s", o->lockedId );
    return False;
  }
}

static Boolean _unLock( iORoute inst, const char* lcid, const char** resblocks, Boolean unlockswitches, Boolean force ) {
  iORouteData o = Data(inst);
  if( force || StrOp.equals( lcid, o->lockedId ) ) {
    TraceOp.trc( name, force?TRCLEVEL_WARNING:TRCLEVEL_INFO, __LINE__, 9999, "unlocking route %s by %s", RouteOp.getId(inst), force?"**force**":lcid );
    if( !force )
      __checkAction(inst, "unlock");

    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "route %s: run the commands at free", RouteOp.getId(inst) );
    __syncGo(inst, True);

    if( unlockswitches )
      __unlockSwitches( inst, lcid, force );

    __unlockCrossingBlocks( inst, lcid, resblocks, force );
    o->lockedId = NULL;
    o->requestId = NULL;
    __broadcast(inst);
    return True;
  }
  else if(o->lockedId == NULL) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "route %s is not locked", RouteOp.getId(inst) );
    return True;
  }
  else {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "cannot unlock with %s; route %s already locked by %s",
        lcid, RouteOp.getId(inst), o->lockedId );
  }
  return False;
}


static Boolean _link( iORoute inst, int linkto ) {
  if( inst != NULL ) {
    iORouteData data = Data(inst);
    iOModel model = AppOp.getModel(  );
    iONode sw = wRoute.getswcmd( data->props );

    while( sw != NULL ) {
      const char* swId = wSwitchCmd.getid( sw );
      iOSwitch isw = ModelOp.getSwitch( model, swId );
      if( isw != NULL ) {
        SwitchOp.link(isw, linkto);
      }
      sw = wRoute.nextswcmd( data->props, sw );
    }
  }
  return True;
}


static Boolean _unLink( iORoute inst ) {
  if( inst != NULL ) {
    iORouteData data = Data(inst);
    iOModel model = AppOp.getModel(  );
    iONode sw = wRoute.getswcmd( data->props );

    while( sw != NULL ) {
      const char* swId = wSwitchCmd.getid( sw );
      iOSwitch isw = ModelOp.getSwitch( model, swId );
      if( isw != NULL ) {
        SwitchOp.unLink(isw);
      }
      sw = wRoute.nextswcmd( data->props, sw );
    }
  }
  return True;
}


/**
 * Checks for property changes.
 * todo: Range checking?
 */
static void _modify( iORoute inst, iONode props ) {
  iORouteData data = Data(inst);
  int cnt = NodeOp.getAttrCnt( props );
  Boolean move = StrOp.equals( wModelCmd.getcmd( props ), wModelCmd.move );
  int i = 0;

  __initCTC(inst, True);

  for( i = 0; i < cnt; i++ ) {
    iOAttr attr = NodeOp.getAttr( props, i );
    const char* name  = AttrOp.getName( attr );
    const char* value = AttrOp.getVal( attr );

    if( StrOp.equals("id", name) && StrOp.equals( value, wRoute.getid(data->props) ) )
      continue; /* skip to avoid making invalid pointers */

    NodeOp.setStr( data->props, name, value );
  }

  if( !move ) {
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
  }
  else {
    NodeOp.removeAttrByName(data->props, "cmd");
  }

  StrOp.free(data->routeLockId);
  data->routeLockId = StrOp.fmt( "%s%s", wRoute.routelock, wRoute.getid(props) );

  __initCTC(inst, False);

  /* Broadcast to clients. */
  {
    iONode clone = (iONode)NodeOp.base.clone( data->props );
    AppOp.broadcastEvent( clone );
  }
  props->base.del(props);
}

static const char* _tableHdr(void) {
  return "<tr bgcolor=\"#CCCCCC\"><th>StreetID</th><th>bka</th><th>bkb</th><th>switches</th></tr>\n";
}

static char* _toHtml( void* inst ) {
  iORouteData data = Data((iORoute)inst);
  char* str1 = StrOp.fmt( "<tr><td>%s</td><td>%s</td><td>%s</td>\n",
      NodeOp.getStr( data->props, "id", "?" ),
      NodeOp.getStr( data->props, "bka", "?" ),
      NodeOp.getStr( data->props, "bkb", "?" )
      );
  str1 = StrOp.cat( str1, "<td><table border=\"1\" cellpadding=\"4\" cellspacing=\"0\">\n" );
  str1 = StrOp.cat( str1, "<tr bgcolor=\"#CCCCCC\"><th>SwID</th><th>Cmd</th></tr>\n" );
  {
    iONode cmd = NodeOp.findNode( data->props, "swcmd" );
    while( cmd != NULL ) {
      char* str2 = StrOp.fmt( "<tr><td>%s</td><td>%s</td></tr>\n",
        NodeOp.getStr( cmd, "id", "?" ),
        NodeOp.getStr( cmd, "cmd", "?" )
      );
      str1 = StrOp.cat( str1, str2 );
      StrOp.free( str2 );
      cmd = NodeOp.findNextNode( data->props, cmd );
    };
  }
  str1 = StrOp.cat( str1, "</table></td>\n</tr>\n" );

  return str1;
}

static char* _getForm( void* inst ) {
  iORouteData data = Data((iORoute)inst);
  return NULL;
}


static char* _postForm( void* inst, const char* postdata ) {
  iORouteData data = Data((iORoute)inst);
  char* reply = StrOp.fmt( "Thanks!<br>" );
  return reply;
}


static void _reset( iORoute inst ) {
  iORouteData data = Data(inst);
  if( data->lockedId != NULL ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
               "reset route [%s]", RouteOp.getId( inst ) );
    RouteOp.unLock( inst, data->lockedId, NULL, True, False );
    wRoute.setstatus(data->props, wRoute.status_free );
  }
  else if( wRoute.getstatus(data->props) == wRoute.status_closed ) {
    wRoute.setstatus(data->props, wRoute.status_free );
  }
  data->requestId = NULL;
  __broadcast(inst);
}


static void _setClosed( iORoute inst ) {
  iORouteData data = Data(inst);
  wRoute.setstatus(data->props, wRoute.status_closed );
}


static Boolean _isSet( iORoute inst ) {
  iORouteData data  = Data(inst);
  Boolean      isSet = True;

  /* check if all switches are set */
  iOModel model = AppOp.getModel(  );
  iONode  sw    = wRoute.getswcmd( data->props );

  iIBlockBase bka = ModelOp.getBlock( model, wRoute.getbka( data->props ) );
  iIBlockBase bkb = ModelOp.getBlock( model, wRoute.getbkb( data->props ) );

  if( bka != NULL && !bka->isReady(bka) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
               "block [%s] for route [%s] is not ready",
               bka->base.id(bka),
               RouteOp.getId( inst ) );
    return False;
  }

  if( bkb != NULL && !bkb->isReady(bkb) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
               "block [%s] for route [%s] is not ready",
               bkb->base.id(bkb),
               RouteOp.getId( inst ) );
    return False;
  }

  while( sw != NULL ) {
    const char* swId  = wSwitchCmd.getid( sw );
    Boolean tt = StrOp.equals( wSwitchCmd.cmd_track, wSwitchCmd.getcmd(sw) );

    if( tt ) {
      iOSelTab iseltab = ModelOp.getSelectiontable( model, swId );
      iOTT itt = ModelOp.getTurntable( model, swId );
      if( itt != NULL && !TTOp.isSet(itt) ) {
        isSet = False;
        TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
                   "turntable [%s] for route [%s] is not set",
                   swId,
                   RouteOp.getId( inst ) );
      }
      else if( iseltab != NULL && !SelTabOp.isSet(iseltab) ) {
        isSet = False;
        TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
                   "selection table [%s] for route [%s] is not set",
                   swId,
                   RouteOp.getId( inst ) );
      }
    }
    else {
      iOSwitch isw = ModelOp.getSwitch( model, swId );

      if( isw != NULL && !SwitchOp.isSet(isw) ) {
        isSet = False;
        TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
                   "switch [%s] for route [%s] is not set",
                   swId,
                   RouteOp.getId( inst ) );
      }
    }

    sw = wRoute.nextswcmd( data->props, sw );
  };

  return isSet;
}


static Boolean _isSetCrossingblockSignals( iORoute inst ) {
  iORouteData data = Data(inst);
  if( wRoute.iscrossingblocksignals( data->props ) ) {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "automatically setting crossing block signals is obsolete; use route commands" );
  }
  return wRoute.iscrossingblocksignals( data->props );
}


static void _setClass( iORoute inst, const char* p_Class ) {
  iORouteData data = Data(inst);
  wRoute.setclass(data->props, p_Class);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "set class to [%s] in route [%s]", wRoute.getclass(data->props),  wRoute.getid(data->props) );
  /* Broadcast to clients. */
  AppOp.broadcastEvent( (iONode)NodeOp.base.clone( data->props ) );
}


static iORoute _inst( iONode props ) {
  iORoute     route = allocMem( sizeof( struct ORoute ) );
  iORouteData data  = allocMem( sizeof( struct ORouteData ) );

  /* OBase operations */
  MemOp.basecpy( route, &RouteOp, 0, sizeof( struct ORoute ), data );

  data->props = props;
  data->routeLockId = StrOp.fmt( "%s%s", wRoute.routelock, wRoute.getid(props) );

  __initCTC(route, False);

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "inst for %s", _getId(route) );

  instCnt++;

  return route;
}


/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocrail/impl/route.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
