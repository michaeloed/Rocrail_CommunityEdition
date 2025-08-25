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

#include "rocrail/impl/fback_impl.h"
#include "rocrail/public/app.h"
#include "rocrail/public/control.h"
#include "rocrail/public/clntcon.h"
#include "rocrail/public/model.h"
#include "rocrail/public/switch.h"
#include "rocrail/public/route.h"
#include "rocrail/public/action.h"

#include "rocint/public/blockbase.h"

#include "rocs/public/doc.h"
#include "rocs/public/trace.h"
#include "rocs/public/node.h"
#include "rocs/public/mem.h"
#include "rocs/public/str.h"
#include "rocs/public/system.h"

#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/FeedbackStatistic.h"
#include "rocrail/wrapper/public/ActionCtrl.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/Schedule.h"
#include "rocrail/wrapper/public/Route.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/DigInt.h"
#include "rocrail/wrapper/public/AutoCmd.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/Ctrl.h"
#include "rocrail/wrapper/public/FreeRail.h"
#include "rocrail/wrapper/public/Item.h"


static int instCnt = 0;

/*
 ***** OBase functions.
 */
static const char* __id( void* inst ) {
  return NULL;
}

static void* __event( void* inst, const void* evt ) {
  if( StrOp.equals( wFeedback.name(), NodeOp.getName( (iONode)evt ) ) ) {
    FBackOp.event(inst, (iONode)evt);
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
  return (char*)FBackOp.getId( (iOFBack)inst );
}
static void __del(void* inst) {
  iOFBackData data = Data(inst);
  freeMem( data );
  freeMem( inst );
  instCnt--;
}
static void* __properties(void* inst) {
  iOFBackData data = Data(inst);
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

static void __ctcAction( iOFBack inst ) {
  iOFBackData data  = Data(inst);
  iOModel     model = AppOp.getModel();
  iOControl control = AppOp.getControl(  );

  if( control == NULL )
    return;

  if( wFeedback.getctcaddr( data->props ) > 0 || wFeedback.getctcport( data->props ) ) {
    iONode node = NULL;
    if( wFeedback.isctcasswitch(data->props) ) {
      node = NodeOp.inst(wSwitch.name(), NULL, ELEMENT_NODE );
      if( wFeedback.getctciid( data->props ) != NULL )
        wSwitch.setiid( node, wFeedback.getctciid( data->props ) );
      wSwitch.setaddr1( node, wFeedback.getctcaddr( data->props ) );
      wSwitch.setport1( node, wFeedback.getctcport( data->props ) );
      wSwitch.setgate1( node, wFeedback.getctcgate( data->props ) );
      wSwitch.setcmd( node, data->state ? wSwitch.straight:wSwitch.turnout );
    }
    else {
      node = NodeOp.inst(wOutput.name(), NULL, ELEMENT_NODE );
      if( wFeedback.getctciid( data->props ) != NULL )
        wOutput.setiid( node, wFeedback.getctciid( data->props ) );
      wOutput.setaddr( node, wFeedback.getctcaddr( data->props ) );
      wOutput.setport( node, wFeedback.getctcport( data->props ) );
      wOutput.setgate( node, wFeedback.getctcgate( data->props ) );
      wOutput.setcmd( node, data->state ? wOutput.on:wOutput.off );
    }
    ControlOp.cmd( control, node, NULL );
  }
}


static void __checkAction( iOFBack inst ) {
  iOFBackData data     = Data(inst);
  iOModel     model    = AppOp.getModel();
  iONode      fbaction = wFeedback.getactionctrl( data->props );

  /* loop over all actions */
  while( fbaction != NULL ) {
    int counter = atoi(wActionCtrl.getstate( fbaction ));
    if( (counter == 0 && StrOp.len(wActionCtrl.getstate( fbaction )) > 0 && wActionCtrl.getstate( fbaction )[0] != '0') ||
        StrOp.len(wActionCtrl.getstate( fbaction )) == 0 )
    {
      counter = -1;
    }

    if( StrOp.equals( data->state?"on":"off"    , wActionCtrl.getstate( fbaction ) ) ||
        StrOp.equals( data->state?"true":"false", wActionCtrl.getstate( fbaction ) ) ||
        (data->state && StrOp.len(wActionCtrl.getstate( fbaction )) == 0) ||
        (counter >= 0 && data->counter == counter) )
    {
      if( data->counter == counter && wActionCtrl.isreset( fbaction ) ) {
        /* reset counter */
        data->counter = 0;
      }
      
      wActionCtrl.setcounter(fbaction, data->counter );
      wActionCtrl.setcarcount(fbaction, data->carcount );
      wActionCtrl.setcountedcars(fbaction, data->countedcars );
      wActionCtrl.setwheelcount(fbaction, data->wheelcount );
      if( FBackOp.getIdentifier(inst) != NULL && StrOp.len(FBackOp.getIdentifier(inst)) > 0 )
        wActionCtrl.setlcid(fbaction, FBackOp.getIdentifier(inst));

      if( data->listenerObj != NULL ) {
        iIBlockBase bk = (iIBlockBase)data->listenerObj;
        if( StrOp.equals( BlockOp.base.name(), data->listenerObj->name() ) )
          wActionCtrl.setlcid(fbaction, bk->getLoc(bk) );
      }
      else if( ListOp.size(data->listeners) > 0 ) {
        obj object = ListOp.first( data->listeners );
        while( object != NULL ) {
          if( StrOp.equals( BlockOp.base.name(), object->name() ) ) {
            iIBlockBase bk = (iIBlockBase)object;
            wActionCtrl.setlcid(fbaction, bk->getLoc(bk) );
            TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "using lc [%s] from block [%s]", bk->getLoc(bk), object->id(object));
            break;
          }
          object = ListOp.next( data->listeners );
        };
      }

      if(wActionCtrl.getlcid(fbaction) != NULL && StrOp.len(wActionCtrl.getlcid(fbaction)) > 0 ) {
        iOLoc lc = ModelOp.getLoc( AppOp.getModel(), wActionCtrl.getlcid(fbaction), NULL, False );
        if( lc != NULL ) {
          wActionCtrl.setlcclass(fbaction, LocOp.getClass(lc));
        }
      }

      iOAction action = ModelOp.getAction(model, wActionCtrl.getid( fbaction ));
      if( action != NULL )
        ActionOp.exec(action, fbaction);

      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "action with counter=%d, carcount=%d, countedcars=%d, wheelcount=%d",
          data->counter, data->carcount, data->countedcars, data->wheelcount );
    }
    else {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "%s action state does not match: [%s-%s] statecounter=%d counter=%d",
          wFeedback.getid( data->props ), wActionCtrl.getstate( fbaction ), data->state?"on/true":"off/false", counter, data->counter );
    }

    fbaction = wFeedback.nextactionctrl( data->props, fbaction );
  }
}

/*
 ***** _Public functions.
 */
static Boolean _setListener( iOFBack inst, obj listenerObj, const fback_listener listenerFun ) {
  iOFBackData data = Data(inst);
  data->listenerObj = listenerObj;
  data->listenerFun = listenerFun;
  if( listenerObj != NULL ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "%s listener set for %s",
      FBackOp.getId( inst ),
      listenerObj->toString(listenerObj) );
  }
  return True;
}

static Boolean _addListener( iOFBack inst, obj listener ) {
  iOFBackData data = Data(inst);
  obj l_listener = ListOp.first( data->listeners );
  while( l_listener != NULL ) {
    if( l_listener == listener ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "%s: listener [%s] already registered", FBackOp.getId( inst ), listener->toString(listener) );
      return True;
    }
    l_listener = ListOp.next( data->listeners );
  };

  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "%s listener added for %s", FBackOp.getId( inst ), listener->toString(listener) );
  ListOp.add( data->listeners, listener );
  return True;
}
static Boolean _removeListener( iOFBack inst, obj listener ) {
  iOFBackData data = Data(inst);
  ListOp.removeObj( data->listeners, listener );
  return True;
}

static Boolean _addBlock( iOFBack inst, iIBlockBase listener ) {
  iOFBackData data = Data(inst);
  return _addListener(inst, (obj)listener);
}
static Boolean _removeBlock( iOFBack inst, iIBlockBase listener ) {
  iOFBackData data = Data(inst);
  /* TODO: use own list? */
  ListOp.removeObj( data->listeners, (obj)listener );
  return True;
}

static const char* _getId( iOFBack inst ) {
  iOFBackData data = Data(inst);
  return wFeedback.getid( data->props );
}

static void* _getProperties( void* inst ) {
  iOFBackData data = Data((iOFBack)inst);
  return data->props;
}

static char* _createAddrKey( int bus, int addr, const char* iid ) {
  iONode node = AppOp.getIniNode( wDigInt.name() );
  const char* def_iid = wDigInt.getiid( node );
  if( def_iid == NULL || StrOp.len(def_iid) == 0 ) {
    def_iid = "vcs-1";
  }
  return StrOp.fmt( "%d_%d_%s", bus, addr, (iid != NULL && StrOp.len( iid ) > 0) ? iid:def_iid );
}

static const char* _getAddrKey( iOFBack inst ) {
  iOFBackData data = Data(inst);
  return data->addrKey;
}

static Boolean _getState( iOFBack inst ) {
  iOFBackData data = Data(inst);
  return data->state;
}

static int _getCounter( iOFBack inst ) {
  iOFBackData data = Data(inst);
  return data->counter;
}

static void _resetWheelCount( iOFBack inst ) {
  iOFBackData data = Data(inst);
  if( wFeedback.getfbtype(data->props) == wFeedback.fbtype_wheelcounter ) {
    FBackOp.resetCounter(inst);
  }
}


static void _resetCounter( iOFBack inst ) {
  iOFBackData data = Data(inst);
  data->counter = 0;
  data->wheelcount = 0;
  if( wFeedback.getfbtype(data->props) == wFeedback.fbtype_wheelcounter && wFeedback.isresetwc(data->props) ) {
    /* TODO: send switch command */
    iONode node = NodeOp.inst(wSwitch.name(), NULL, ELEMENT_NODE);
    wSwitch.setport1( node, wFeedback.getaddr( data->props ) );
    wSwitch.setcmd( node, wSwitch.turnout );
    ControlOp.cmd( AppOp.getControl(), node, NULL );

    data->state = False;
  }
  /* Broadcast to clients. Node4 */
  {
    iONode nodeD = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
    wFeedback.setid( nodeD, FBackOp.getId( inst ) );
    wFeedback.setstate( nodeD, data->state );
    wFeedback.setaddr( nodeD, wFeedback.getaddr( data->props ) );
    wFeedback.setbus( nodeD, wFeedback.getbus( data->props ) );
    wFeedback.setfbtype( nodeD, wFeedback.getfbtype( data->props ) );
    wFeedback.setcounter( data->props, data->counter );
    wFeedback.setcarcount( nodeD, data->carcount );
    wFeedback.setcountedcars( nodeD, data->countedcars );
    wFeedback.setwheelcount( nodeD, data->wheelcount );
    wFeedback.setload( nodeD, wFeedback.getload(data->props) );
    wFeedback.setmaxload( nodeD, wFeedback.getmaxload(data->props) );
    AppOp.broadcastEvent( nodeD );
  }
}

static void _setCarCount( iOFBack inst, int count ) {
  iOFBackData data = Data(inst);
  data->carcount = count;
  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "[%s] CAR COUNT = %d", FBackOp.getId(inst), data->carcount );
}

static const char* _getIdentifier( iOFBack inst ) {
  iOFBackData data = Data(inst);
  return wFeedback.getidentifier( data->props );
}

static void _setState( iOFBack inst, Boolean state ) {
  iOFBackData data = Data(inst);
  data->state = state;
  wFeedback.setstate( data->props, data->state );
  /* Broadcast to clients. Node4 */
  {
    iONode nodeD = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
    wFeedback.setid( nodeD, FBackOp.getId( inst ) );
    wFeedback.setstate( nodeD, data->state );
    wFeedback.setaddr( nodeD, wFeedback.getaddr( data->props ) );
    wFeedback.setbus( nodeD, wFeedback.getbus( data->props ) );
    wFeedback.setfbtype( nodeD, wFeedback.getfbtype( data->props ) );
    wFeedback.setcounter( data->props, data->counter );
    wFeedback.setcarcount( nodeD, data->carcount );
    wFeedback.setcountedcars( nodeD, data->countedcars );
    wFeedback.setwheelcount( nodeD, data->wheelcount );
    wFeedback.setload( nodeD, wFeedback.getload(data->props) );
    wFeedback.setmaxload( nodeD, wFeedback.getmaxload(data->props) );
    AppOp.broadcastEvent( nodeD );
  }
}


static Boolean _cmd( iOFBack inst, iONode cmd, Boolean update ) {
  iOFBackData data = Data(inst);
  iOControl control = AppOp.getControl();
  int error = 0;
  if( StrOp.equals(wFeedback.reset, wFeedback.getcmd(cmd))) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "reset sensor counters [%s]", FBackOp.getId(inst));
    FBackOp.resetCounter(inst);
    iONode clone = (iONode)NodeOp.base.clone( data->props );
    AppOp.broadcastEvent( clone );
  }
  else if( StrOp.equals(wFeedback.resetstatus, wFeedback.getcmd(cmd))) {
    data->state = False;
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "reset sensor status [%s]", FBackOp.getId(inst));
    wFeedback.setstate( data->props, data->state );
    iONode clone = (iONode)NodeOp.base.clone( data->props );
    AppOp.broadcastEvent( clone );
  }
  else if( StrOp.equals(wFeedback.setcounterval, wFeedback.getcmd(cmd))) {
    data->counter = wFeedback.getcounter(cmd);
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "set sensor [%s] counter to %d", FBackOp.getId(inst), data->counter);
    iONode clone = (iONode)NodeOp.base.clone( data->props );
    wFeedback.setcounter( clone, data->counter);
    AppOp.broadcastEvent( clone );
    __checkAction(inst);
  }
  else {
    if( wFeedback.getfbtype(data->props) == wFeedback.fbtype_wheelcounter && wFeedback.isstate(cmd) )
      data->wheelcount++;

    wFeedback.setiid( cmd, wFeedback.getiid( data->props ) );
    wItem.setuidname( cmd, wItem.getuidname( data->props ) );
    wFeedback.setbus( cmd, wFeedback.getbus( data->props ) );
    wFeedback.setfbtype( cmd, wFeedback.getfbtype( data->props ) );
    wFeedback.setaddr( cmd, wFeedback.getaddr( data->props ) );
    wFeedback.setactivelow( cmd, wFeedback.isactivelow( data->props ) );
    wFeedback.setcounter( cmd, data->counter );
    wFeedback.setcarcount( cmd, data->carcount );
    wFeedback.setcountedcars( cmd, data->countedcars );
    ControlOp.cmd( control, cmd, &error );
  }
  return True;
}


static void __processSignalQuality(iOFBack inst, int signalquality, const char* locoid ) {
  iOFBackData data = Data(inst);
  Boolean l_NewQuality = False;
  Boolean l_NotFound   = True;
  iONode   fbstatistic = wFeedback.getfbstatistic( data->props );

  /* loop over all actions */
  while( fbstatistic != NULL ) {
    if( StrOp.equals(wFeedbackStatistic.getlcid(fbstatistic), locoid) ) {
      l_NotFound = False;
      if( wFeedbackStatistic.getquality(fbstatistic) < signalquality ) {
        wFeedbackStatistic.setquality(fbstatistic, signalquality);
        l_NewQuality = True;
      }
    }
    fbstatistic = wFeedback.nextfbstatistic( data->props, fbstatistic );
  };

  if( l_NotFound ) {
    iONode fbstatistic = NodeOp.inst(wFeedbackStatistic.name(), data->props, ELEMENT_NODE);
    wFeedbackStatistic.setlcid(fbstatistic, locoid);
    wFeedbackStatistic.setquality(fbstatistic, signalquality);
    NodeOp.addChild( data->props, fbstatistic);
    l_NewQuality = True;
  }

  if(l_NewQuality) {
    iONode clone = (iONode)NodeOp.base.clone(data->props);
    wFeedback.setcmd(clone, wFeedback.signalquality);
    AppOp.broadcastEvent( clone );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "signal quality is %d reported by %s", signalquality, locoid );
  }
}



static void _event( iOFBack inst, iONode nodeC ) {
  iOFBackData data = Data(inst);
  Boolean hasListener = False;
  Boolean state = wFeedback.isstate( nodeC );
  Boolean stateDidChange = True;

  if( TraceOp.getLevel(NULL) & TRCLEVEL_DEBUG ) {
    char* strNode = (char*)NodeOp.base.toString( nodeC );
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "event %s", strNode );
    StrOp.free( strNode );
  }

  if( StrOp.equals(wFeedback.getcmd(nodeC), wFeedback.signalquality) ) {
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "signal quality..." );
    __processSignalQuality(inst, wFeedback.getsignal(nodeC), wFeedback.getlocoid(nodeC) );
    nodeC->base.del(nodeC);
    return;
  }

  if( wFeedback.getcutoutaddr(data->props) > 0 && wFeedback.getaddr(nodeC) == wFeedback.getcutoutaddr(data->props) ) {
    data->shortcut = state;
    wFeedback.setshortcut(data->props, state);
    TraceOp.trc( name, state ? TRCLEVEL_EXCEPTION:TRCLEVEL_INFO, __LINE__, 9999,
        "Sensor [%s] report: %s", wFeedback.getid(data->props), state?"short circuit detected":"Cutout is OK" );
    AppOp.broadcastEvent( (iONode)NodeOp.base.clone(data->props) );
    nodeC->base.del(nodeC);
    return;
  }


  /* check for active low */
  if( wFeedback.isactivelow( data->props ) )
    state = !state;

  /* check for a timed off sensor */
  if( data->timedoff > 0 ) {
    if( !state ) {
      data->timer = data->timedoff;
      /* Cleanup Node3 */
      nodeC->base.del(nodeC);
      return;
    }
  }

  if( data->state == state )
    stateDidChange = False;
  data->state = state;

  if( wFeedback.getfbtype(data->props) == wFeedback.fbtype_wheelcounter ) {
    if(wFeedback.getwheelcount(nodeC) == 0 && state) {
      /* using a HAL sensor for 'wheel'(Magnet) counting */
      data->wheelcount++;
    }
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "[%s] COUNTING WHEELS: countedwheels=%d",
        FBackOp.getId(inst), wFeedback.getwheelcount(nodeC) + data->wheelcount );
    /* the plus data->wheelcount is for simulation */
  }

  if(data->state) {
    data->timer = -1;
    data->counter++;

    if( data->carcount > 0 ) {
      data->countedcars++;
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "[%s] COUNTING CARS: carcount=%d countedcars=%d",
          FBackOp.getId(inst), data->carcount, data->countedcars );
      __checkAction( inst );
    }
  }

  if( data->carcount > 0 && data->countedcars <= data->carcount ) {
    /* Cleanup Node3 */
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "COUNTING CARS: fb[%s] state=%s ident=%d val=%d carcount=%d countedcars=%d",
                 FBackOp.getId(inst), data->state?"ON":"OFF", wFeedback.getidentifier( nodeC ),
                 wFeedback.getval( nodeC ), data->carcount, data->countedcars );

    /* Broadcast to clients. Node4 */
    if( data->state || data->timedoff == 0 ) {
      iONode nodeD = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
      wFeedback.setid( nodeD, FBackOp.getId( inst ) );
      wFeedback.setcounter( data->props, data->counter );
      wFeedback.setcarcount( nodeD, data->carcount );
      wFeedback.setcountedcars( nodeD, data->countedcars );
      wFeedback.setstate( nodeD, data->state );
      wFeedback.setval( nodeD, wFeedback.getval( nodeC ) );
      wFeedback.setaddr( nodeD, wFeedback.getaddr( data->props ) );
      wFeedback.setbus( nodeD, wFeedback.getbus( data->props ) );
      wFeedback.setfbtype( nodeD, wFeedback.getfbtype( data->props ) );
      wFeedback.setidentifier( nodeD, wFeedback.getidentifier( nodeC ) );
      wFeedback.setwheelcount( nodeD, wFeedback.getwheelcount( nodeC ) + data->wheelcount );
      wFeedback.setload( nodeD, wFeedback.getload(data->props) );
      wFeedback.setmaxload( nodeD, wFeedback.getmaxload(data->props) );
      AppOp.broadcastEvent( nodeD );
    }
    nodeC->base.del(nodeC);
    return;
  }

  /* reset car counting */
  data->carcount    = 0;
  data->countedcars = 0;


  wFeedback.setstate( data->props, data->state );
  wFeedback.setcounter( data->props, data->counter );
  wFeedback.setidentifier( data->props, wFeedback.getidentifier( nodeC ) );
  wFeedback.setdirection( data->props, wFeedback.isdirection( nodeC ) );
  wFeedback.setload( data->props, wFeedback.getload( nodeC ) );

  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "fb[%s] state=%s ident=%s dir=%s val=%d count=%d",
               FBackOp.getId(inst), data->state?"ON":"OFF", wFeedback.getidentifier( nodeC ), wFeedback.isdirection( nodeC )?"fwd":"rev",
               wFeedback.getval( nodeC ), data->counter );

  /* Call listener. */
  if( data->listenerFun != NULL ) {
    data->listenerFun( data->listenerObj, data->state, FBackOp.getId( inst ),
        wFeedback.getidentifier( nodeC ), wFeedback.getidentifier2( nodeC ), wFeedback.getidentifier3( nodeC ), wFeedback.getidentifier4( nodeC ),
        wFeedback.getval( nodeC ), wFeedback.getwheelcount( nodeC ) + data->wheelcount, wFeedback.isdirection(nodeC) );
    hasListener = True;
  }

  {
    obj listener = ListOp.first( data->listeners );
    iONode node = (iONode)NodeOp.base.clone(data->props);
    wFeedback.setstate(node, data->state);
    wFeedback.setidentifier(node, wFeedback.getidentifier( nodeC ));
    wFeedback.setidentifier2(node, wFeedback.getidentifier2( nodeC ) );
    wFeedback.setidentifier3(node, wFeedback.getidentifier3( nodeC ) );
    wFeedback.setidentifier4(node, wFeedback.getidentifier4( nodeC ) );
    wFeedback.setval(node, wFeedback.getval( nodeC ) );
    wFeedback.setwheelcount(node, wFeedback.getwheelcount( nodeC ) + data->wheelcount);
    wFeedback.setdirection(node, wFeedback.isdirection(nodeC) );
    while( listener != NULL ) {
      hasListener = True;
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "fb [%s](%s) ident=%s val=%d count=%d call listener 0x%08X...",
                   FBackOp.getId(inst), data->state?"ON":"OFF", wFeedback.getidentifier( nodeC ),
                   wFeedback.getval( nodeC ), data->counter, listener );
      listener->event( listener, node );
      listener = ListOp.next( data->listeners );
    };
    NodeOp.base.del(node);
  }

  __ctcAction( inst );
  if( stateDidChange )
    __checkAction( inst );

  if(!hasListener) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "fb[%s] (%s) ident=%s val=%d count=%d has no listener...",
                 FBackOp.getId(inst), data->state?"ON":"OFF",
                 wFeedback.getidentifier( nodeC ), wFeedback.getval( nodeC ), data->counter );
  }

  /* Broadcast to clients. Node4 */
  if( data->state || data->timedoff == 0 ) {
    iONode nodeD = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
    wFeedback.setiid( nodeD, wFeedback.getiid( data->props ) );
    wFeedback.setid( nodeD, FBackOp.getId( inst ) );
    wFeedback.setstate( nodeD, data->state );
    wFeedback.setval( nodeD, wFeedback.getval( nodeC ) );
    wFeedback.setaddr( nodeD, wFeedback.getaddr( data->props ) );
    wFeedback.setbus( nodeD, wFeedback.getbus( data->props ) );
    wFeedback.setfbtype( nodeD, wFeedback.getfbtype( data->props ) );
    wFeedback.setidentifier( nodeD, wFeedback.getidentifier( nodeC ) );
    wFeedback.setcounter( nodeD, data->counter );
    wFeedback.setcarcount( nodeD, data->carcount );
    wFeedback.setcountedcars( nodeD, data->countedcars );
    wFeedback.setwheelcount( nodeD, wFeedback.getwheelcount( nodeC ) + data->wheelcount );
    wFeedback.setload( nodeD, wFeedback.getload(data->props) );
    wFeedback.setmaxload( nodeD, wFeedback.getmaxload(data->props) );
    AppOp.broadcastEvent( nodeD );
  }

  if( data->state && wFeedback.getfbtype(data->props) == wFeedback.fbtype_lissy ) {
    /* timed off */
    data->state = False;
    data->timer = data->timedoff;
  }

  /* Cleanup Node3 */
  nodeC->base.del(nodeC);
}

static void __initCutout(iOFBack inst) {
  iOFBackData data  = Data(inst);
  iOModel     model = AppOp.getModel();

  if( wFeedback.getcutoutaddr(data->props) > 0 ) {
    data->cutoutAddrKey = FBackOp.createAddrKey( wFeedback.getcutoutbus(data->props),
                                           wFeedback.getcutoutaddr(data->props),
                                           wFeedback.getiid(data->props) );
    /* inform model with new addrkey to add to map. */
    ModelOp.addFbKey( model, data->cutoutAddrKey, (obj)inst );
  }
}

/**
 * Checks for property changes.
 * todo: Range checking?
 */
static void _modify( iOFBack inst, iONode props ) {
  iOFBackData data  = Data(inst);
  iOModel     model = AppOp.getModel();
  Boolean move    = StrOp.equals( wModelCmd.getcmd( props ), wModelCmd.move );
  Boolean newaddr = (wFeedback.getaddr( data->props ) != wFeedback.getaddr( props ));

  int cnt = NodeOp.getAttrCnt( props );
  int i = 0;
  

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "modify %s", wFeedback.getid(data->props) );
  /* TODO: inform model with current addrkey to remove from map. */

  for( i = 0; i < cnt; i++ ) {
    iOAttr attr = NodeOp.getAttr( props, i );
    const char* name  = AttrOp.getName( attr );
    const char* value = AttrOp.getVal( attr );

    if( StrOp.equals("id", name) && StrOp.equals( value, wFeedback.getid(data->props) ) )
      continue; /* skip to avoid making invalid pointers */

    NodeOp.setStr( data->props, name, value );
  }

  if(!move) {
    /* delete all childs to make 'room' for the new ones: */
    cnt = NodeOp.getChildCnt( data->props );
    while( cnt > 0 ) {
      iONode child = NodeOp.getChild( data->props, 0 );
      iONode removedChild = NodeOp.removeChild( data->props, child );
      if( removedChild != NULL) {
        NodeOp.base.del(removedChild);
      }
      cnt = NodeOp.getChildCnt( data->props );
    }

    /* add the new or modified childs: */
    cnt = NodeOp.getChildCnt( props );
    for( i = 0; i < cnt; i++ ) {
      iONode child = NodeOp.getChild( props, i );
      NodeOp.addChild( data->props, (iONode)NodeOp.base.clone(child) );
    }

    /* TODO: addrkey changed!!! */
    ModelOp.removeFbKey( model, data->addrKey, (obj)inst );
    StrOp.free( data->addrKey );
    data->addrKey = FBackOp.createAddrKey( wFeedback.getbus(data->props),
                                           wFeedback.getaddr(data->props),
                                           wFeedback.getiid(data->props) );
    /* inform model with new addrkey to add to map. */
    ModelOp.addFbKey( model, data->addrKey, (obj)inst );
    
    if( data->cutoutAddrKey != NULL ) {
      ModelOp.removeFbKey( model, data->cutoutAddrKey, (obj)inst );
      StrOp.free( data->cutoutAddrKey );
    }

    __initCutout(inst);

  }
  else {
    NodeOp.removeAttrByName(data->props, "cmd");
  }

  if( wCtrl.istimedsensors( wFreeRail.getctrl( AppOp.getIni() ) ) ) {
    data->timedoff = wFeedback.gettimer(data->props);
  }

  /* Broadcast to clients. */
  {
    iONode clone = (iONode)props->base.clone( props );
    AppOp.broadcastEvent( clone );
  }
  props->base.del(props);
}

static const char* _tableHdr(void) {
  return "<tr bgcolor=\"#CCCCCC\"><th>ID</th><th>Addr</th><th>x</th><th>y</th><th>z</th></tr>\n";
}

static char* _toHtml( void* inst ) {
  iOFBackData data = Data((iOFBack)inst);
  return StrOp.fmt( "<tr><td>%s</td><td align=\"right\">%d</td><td align=\"right\">%d</td><td align=\"right\">%d</td><td align=\"right\">%d</td></tr>\n",
      wFeedback.getid( data->props ),
      wFeedback.getaddr( data->props ),
      wFeedback.getx( data->props ),
      wFeedback.gety( data->props ),
      wFeedback.getz( data->props )
      );
}

static char* _getForm( void* inst ) {
  iOFBackData data = Data((iOFBack)inst);
  return NULL;
}


static char* _postForm( void* inst, const char* postdata ) {
  iOFBackData data = Data((iOFBack)inst);
  char* reply = StrOp.fmt( "Thanks!<br>" );
  return reply;
}


static iOFBack _inst( iONode props ) {
  iOFBack     fback = allocMem( sizeof( struct OFBack ) );
  iOFBackData data  = allocMem( sizeof( struct OFBackData ) );

  /* OBase operations */
  MemOp.basecpy( fback, &FBackOp, 0, sizeof( struct OFBack ), data );

  data->props = props;
  data->timer = -1;
  /* initially the state is off: */
  wFeedback.setstate( props, wFeedback.isactivelow( data->props ) );

  if( wCtrl.istimedsensors( wFreeRail.getctrl( AppOp.getIni() ) ) ) {
    data->timedoff = wFeedback.gettimer( props );
  }

  data->listeners = ListOp.inst();

  data->addrKey = _createAddrKey(
    wFeedback.getbus( props ),
    wFeedback.getaddr( props ),
    wFeedback.getiid( props )
    );

  NodeOp.removeAttrByName(data->props, "cmd");
  wFeedback.setgpssid(data->props, 0);

  __initCutout(fback);

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "inst[%d] for %s, %s",
        instCnt,
        _getId(fback),
        data->addrKey
        );

  instCnt++;

  return fback;
}

static Boolean _isState( iOFBack inst, const char* state ) {
  iOFBackData data = Data(inst);
  if( StrOp.equals( state, "true" ) && data->state )
    return True;
  if( StrOp.equals( state, "false" ) && !data->state )
    return True;

  return False;
}


static Boolean _hasShortcut( iOFBack inst ) {
  iOFBackData data = Data(inst);
  return data->shortcut;
}


static Boolean _isAtGPSPos( iOFBack inst, int sid, int xx, int yy, int zz, Boolean* state ) {
  iOFBackData data = Data(inst);
  if( wFeedback.getfbtype(data->props) == wFeedback.fbtype_gps ) {
    int x = wFeedback.getgpsx(data->props);
    int y = wFeedback.getgpsy(data->props);
    int z = wFeedback.getgpsz(data->props);
    int tolx = wFeedback.getgpstolx(data->props);
    int toly = wFeedback.getgpstoly(data->props);
    int tolz = wFeedback.getgpstolz(data->props);

    if( abs(xx-x) > tolx ) {
      TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999, "X abs(%d-%d)=%d > tolx=%d", xx, x, abs(xx-x), tolx );
      if( sid == wFeedback.getgpssid(data->props) ) {
        wFeedback.setgpssid(data->props, 0);
        wFeedback.setstate(data->props, False);
        FBackOp.event(inst, (iONode)NodeOp.base.clone(data->props));
      }
      return False;
    }
    if( abs(yy-y) > toly ) {
      TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999, "Y abs(%d-%d)=%d > toly=%d", yy, y, abs(yy-y), toly );
      if( sid == wFeedback.getgpssid(data->props) ) {
        wFeedback.setgpssid(data->props, 0);
        wFeedback.setstate(data->props, False);
        FBackOp.event(inst, (iONode)NodeOp.base.clone(data->props));
      }
      return False;
    }
    if( abs(zz-z) > tolz ) {
      TraceOp.trc( name, TRCLEVEL_BYTE, __LINE__, 9999, "Z abs(%d-%d)=%d > tolz=%d", zz, z, abs(zz-z), tolz );
      if( sid == wFeedback.getgpssid(data->props) ) {
        wFeedback.setgpssid(data->props, 0);
        wFeedback.setstate(data->props, False);
        FBackOp.event(inst, (iONode)NodeOp.base.clone(data->props));
      }
      return False;
    }

    if( sid == wFeedback.getgpssid(data->props) ) {
      /* trigger */
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "sid=%d already reported", sid );
      *state = False;
      return False;
    }

    if( sid != wFeedback.getgpssid(data->props) ) {
      /* load trigger */
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "report for sid=%d", sid );
      *state = True;
      wFeedback.setgpssid(data->props, sid);
    }

    return True;
  }
  return False;
}


static void _doTimedOff( iOFBack inst ) {
  iOFBackData data = Data(inst);
  if( data->timedoff > 0 ){

    if( data->timer == 0 ) {
      iONode nodeD = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
      data->state = False;
      data->timer = -1;

      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "timed off event for %s", FBackOp.getId( inst ));

      if( data->listenerFun != NULL ) {
        data->listenerFun( data->listenerObj, data->state, FBackOp.getId( inst ), NULL, NULL, NULL, NULL, 0, 0, True );
      }

      __ctcAction( inst );
      __checkAction( inst );

      /* Broadcast to clients. Node4 */
      wFeedback.setid( nodeD, FBackOp.getId( inst ) );
      wFeedback.setcounter( data->props, data->counter );
      wFeedback.setcarcount( nodeD, data->carcount );
      wFeedback.setcountedcars( nodeD, data->countedcars );
      wFeedback.setstate( nodeD, data->state );
      wFeedback.setaddr( nodeD, wFeedback.getaddr( data->props ) );
      wFeedback.setbus( nodeD, wFeedback.getbus( data->props ) );
      wFeedback.setfbtype( nodeD, wFeedback.getfbtype( data->props ) );
      wFeedback.setload( nodeD, wFeedback.getload(data->props) );
      wFeedback.setmaxload( nodeD, wFeedback.getmaxload(data->props) );
      AppOp.broadcastEvent( nodeD );

      {
        obj listener = ListOp.first( data->listeners );
        wFeedback.setstate( data->props, data->state );
        while( listener != NULL ) {
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "fb [%s](%s) val=%d count=%d call listener %X...",
                       FBackOp.getId(inst), data->state?"ON":"OFF", wFeedback.getval(data->props), data->counter, listener );
          listener->event( listener, data->props );
          listener = ListOp.next( data->listeners );
        };
      }
    }
    else if( data->timer > 0 ) {
      data->timer--;
    }

  }
}



/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocrail/impl/fback.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
