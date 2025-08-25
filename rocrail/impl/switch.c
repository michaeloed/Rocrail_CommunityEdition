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

#include "rocrail/impl/switch_impl.h"
#include "rocrail/public/app.h"
#include "rocrail/public/action.h"
#include "rocrail/public/route.h"

#include "rocrail/wrapper/public/FreeRail.h"
#include "rocrail/wrapper/public/Ctrl.h"

#include "rocs/public/doc.h"
#include "rocs/public/trace.h"
#include "rocs/public/node.h"
#include "rocs/public/mem.h"
#include "rocs/public/str.h"
#include "rocs/public/thread.h"
#include "rocs/public/strtok.h"

#include "rocrail/wrapper/public/Action.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/ActionCtrl.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/DigInt.h"
#include "rocrail/wrapper/public/Schedule.h"
#include "rocrail/wrapper/public/Route.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/DigInt.h"
#include "rocrail/wrapper/public/AutoCmd.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/AccessoryCtrl.h"
#include "rocrail/wrapper/public/Item.h"

static int instCnt = 0;

static Boolean __unregisterCallback( iOSwitch inst );
static void __polariseFrog(iOSwitch inst, int frog, Boolean relays1, Boolean relays2);
static void __testThread( void* threadinst );
static void __accThread( void* threadinst );


/*
 ***** OBase functions.
 */
static const char* __id( void* inst ) {
  iOSwitchData data  = Data(inst);
  return data->id;
}

static void __initCTC(iOSwitch inst, Boolean remove) {
  iOSwitchData data  = Data(inst);
  iOModel      model = AppOp.getModel();

  if( wSwitch.getctcaddr1(data->props) > 0 ) {
    char* key = FBackOp.createAddrKey(wSwitch.getctcbus1(data->props), wSwitch.getctcaddr1(data->props), wSwitch.getctciid1(data->props));
    if( remove )
      ModelOp.removeFbKey( model, key, (obj)inst );
    else
      ModelOp.addFbKey( model, key, (obj)inst );
    StrOp.free(key);
  }

  if( wSwitch.getctcaddr2(data->props) > 0 ) {
    char* key = FBackOp.createAddrKey(wSwitch.getctcbus2(data->props), wSwitch.getctcaddr2(data->props), wSwitch.getctciid2(data->props));
    if( remove )
      ModelOp.removeFbKey( model, key, (obj)inst );
    else
      ModelOp.addFbKey( model, key, (obj)inst );
    StrOp.free(key);
  }
}



static void __ctcAction( void* inst, iONode evt ) {
  iOSwitchData data = Data(inst);
  Boolean state = wFeedback.isstate(evt);
  const char* type = wSwitch.gettype( data->props );
  Boolean twoMotors = False;

  if( StrOp.equals( wSwitch.dcrossing, type ) || StrOp.equals( wSwitch.threeway, type ) )
    twoMotors = True;

  if( wFeedback.getaddr(evt) == wSwitch.getctcaddr1(data->props) ) {
    Boolean flip = wSwitch.isctcflip1(data->props);
    data->ctc1 = state;
    if( flip && !state )
      return;
    else {
      int error = 0;
      iONode node = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      wSwitch.setmanualcmd( node, True);
      if( flip ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "CTC action: %s", wSwitch.flip);
        wSwitch.setcmd( node, wSwitch.flip );
        wSwitch.setid( node, SwitchOp.getId( inst ) );
      }
      else {
        state = wSwitch.isctccmdon1(data->props) ? state:!state;
        wSwitch.setcmd( node, state ? wSwitch.straight:wSwitch.turnout );
        wSwitch.setid( node, SwitchOp.getId( inst ) );
      }
      SwitchOp.cmd( inst, node, True, 0, &error, NULL );
    }
  }
  else if( wFeedback.getaddr(evt) == wSwitch.getctcaddr2(data->props) ) {
    Boolean flip = wSwitch.isctcflip2(data->props);
    data->ctc2 = state;
    if( flip && !state )
      return;
    else {
      int error = 0;
      iONode node = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      wSwitch.setmanualcmd( node, True);
      if( flip ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "CTC action: %s", wSwitch.flip);
        wSwitch.setcmd( node, wSwitch.flip );
        wSwitch.setid( node, SwitchOp.getId( inst ) );
      }
      else {
        state = wSwitch.isctccmdon2(data->props) ? state:!state;
        wSwitch.setcmd( node, state ? wSwitch.straight:wSwitch.turnout );
        wSwitch.setid( node, SwitchOp.getId( inst ) );
      }
      SwitchOp.cmd( inst, node, True, 0, &error, NULL );
    }
  }

}


static void __ctcActionLED( void* inst ) {
  iOSwitchData data = Data(inst);
  iOModel     model = AppOp.getModel();
  iOControl control = AppOp.getControl(  );
  const char* type = wSwitch.gettype( data->props );

  Boolean m1 = False;
  Boolean m2 = False;
  Boolean twoMotors = False;

  if( StrOp.equals( wSwitch.dcrossing, type ) || StrOp.equals( wSwitch.threeway, type ) )
    twoMotors = True;



  if( control == NULL )
    return;

  if( twoMotors ) {
    m1 = StrOp.equals( wSwitch.getstate(data->props), wSwitch.turnout );
    m2 = StrOp.equals( wSwitch.getstate(data->props), wSwitch.left );
  }
  else {
    m1 = StrOp.equals( wSwitch.getstate(data->props), wSwitch.turnout );
  }


  if( wSwitch.getctcaddrled1( data->props ) > 0 || wSwitch.getctcportled1( data->props ) ) {
    iONode node = NULL;
    if( wSwitch.isctcasswitchled1(data->props) ) {
      node = NodeOp.inst(wSwitch.name(), NULL, ELEMENT_NODE );
      if( wSwitch.getctciidled1( data->props ) != NULL )
        wSwitch.setiid( node, wSwitch.getctciidled1( data->props ) );
      wSwitch.setbus( node, wSwitch.getctcbusled1( data->props ) );
      wItem.setuidname( node, wItem.getuidname( data->props ) );
      wSwitch.setaddr1( node, wSwitch.getctcaddrled1( data->props ) );
      wSwitch.setport1( node, wSwitch.getctcportled1( data->props ) );
      wSwitch.setgate1( node, wSwitch.getctcgateled1( data->props ) );
      wSwitch.setcmd( node, m1 ? wSwitch.straight:wSwitch.turnout );
    }
    else {
      node = NodeOp.inst(wOutput.name(), NULL, ELEMENT_NODE );
      if( wSwitch.getctciidled1( data->props ) != NULL )
        wOutput.setiid( node, wSwitch.getctciidled1( data->props ) );
      wOutput.setbus( node, wSwitch.getctcbusled1( data->props ) );
      wItem.setuidname( node, wItem.getuidname( data->props ) );
      wOutput.setaddr( node, wSwitch.getctcaddrled1( data->props ) );
      wOutput.setport( node, wSwitch.getctcportled1( data->props ) );
      wOutput.setgate( node, wSwitch.getctcgateled1( data->props ) );
      wOutput.setcmd( node, m1 ? wOutput.on:wOutput.off );
    }
    ControlOp.cmd( control, node, NULL );
  }


  if( wSwitch.getctcaddrled2( data->props ) > 0 || wSwitch.getctcportled2( data->props ) ) {
    iONode node = NULL;
    if( wSwitch.isctcasswitchled2(data->props) ) {
      node = NodeOp.inst(wSwitch.name(), NULL, ELEMENT_NODE );
      if( wSwitch.getctciidled2( data->props ) != NULL )
        wSwitch.setiid( node, wSwitch.getctciidled2( data->props ) );
      wSwitch.setbus( node, wSwitch.getctcbusled2( data->props ) );
      wItem.setuidname( node, wItem.getuidname( data->props ) );
      wSwitch.setaddr1( node, wSwitch.getctcaddrled2( data->props ) );
      wSwitch.setport1( node, wSwitch.getctcportled2( data->props ) );
      wSwitch.setgate1( node, wSwitch.getctcgateled2( data->props ) );
      wSwitch.setcmd( node, m2 ? wSwitch.straight:wSwitch.turnout );
    }
    else {
      node = NodeOp.inst(wOutput.name(), NULL, ELEMENT_NODE );
      if( wSwitch.getctciidled2( data->props ) != NULL )
        wOutput.setiid( node, wSwitch.getctciidled2( data->props ) );
      wOutput.setbus( node, wSwitch.getctcbusled2( data->props ) );
      wItem.setuidname( node, wItem.getuidname( data->props ) );
      wOutput.setaddr( node, wSwitch.getctcaddrled2( data->props ) );
      wOutput.setport( node, wSwitch.getctcportled2( data->props ) );
      wOutput.setgate( node, wSwitch.getctcgateled2( data->props ) );
      wOutput.setcmd( node, m2 ? wOutput.on:wOutput.off );
    }
    ControlOp.cmd( control, node, NULL );
  }


}


static void* __event( void* inst, const void* evt ) {
  if( StrOp.equals( wSwitch.name(), NodeOp.getName( (iONode)evt ) ) ) {
    SwitchOp.event((iOSwitch)inst, (iONode)evt);
  }
  else if( StrOp.equals( wFeedback.name(), NodeOp.getName( (iONode)evt ) ) ) {
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
  return (char*)SwitchOp.getId( (iOSwitch)inst );
}
static void __del(void* inst) {
  iOSwitchData data = Data(inst);
  int waitcnt = 0;
  /* Cleanup data->xxx members...*/
  data->run = False;
  while( data->accrun && waitcnt < 10 ) {
    ThreadOp.sleep(100);
    waitcnt++;
  }
  data->accctrl = NULL;
  __unregisterCallback(inst);
  freeMem( data );
  freeMem( inst );
  instCnt--;
}
static void* __properties(void* inst) {
  iOSwitchData data = Data(inst);
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

static Boolean _addListener( iOSwitch inst, obj listener ) {
  iOSwitchData data = Data(inst);
  ListOp.add( data->listeners, listener );
  return True;
}
static Boolean _removeListener( iOSwitch inst, obj listener ) {
  iOSwitchData data = Data(inst);
  ListOp.removeObj( data->listeners, listener );
  return True;
}


static void __checkAction( iOSwitch inst, Boolean event ) {

  iOSwitchData data     = Data(inst);
  iOModel      model    = AppOp.getModel();
  iONode       swaction = wSwitch.getactionctrl( data->props );

  while( swaction != NULL) {
    Boolean atcmd = wActionCtrl.isatcmd(swaction);
    Boolean atevt = wActionCtrl.isatevt(swaction);

    if( (!event && atcmd) || (event && atevt) ) {
      if( StrOp.len( wActionCtrl.getstate(swaction) ) == 0 || StrOp.equals(wActionCtrl.getstate(swaction), wSwitch.getstate(data->props) ) )
      {
        iOAction action = ModelOp.getAction( AppOp.getModel(), wActionCtrl.getid( swaction ));
        if( action != NULL ) {
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "switch action: %s", wActionCtrl.getid( swaction ));

          if( wAction.getoid( swaction) == NULL || StrOp.len(wAction.getoid( swaction)) == 0 ) {
            wActionCtrl.setlcid( swaction, data->lockedId );
            if(data->lockedId != NULL && StrOp.len(data->lockedId) > 0 ) {
              iOLoc lc = ModelOp.getLoc( AppOp.getModel(), data->lockedId, NULL, False );
              if( lc != NULL ) {
                wActionCtrl.setlcclass(swaction, LocOp.getClass(lc));
              }
            }
          }
          ActionOp.exec(action, swaction);
        }
      }
      else {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "%s action state does not match: [%s-%s]",
            wSwitch.getid(data->props), wActionCtrl.getstate( swaction ), wSwitch.getstate(data->props) );
      }
    }
    swaction = wSwitch.nextactionctrl( data->props, swaction );
  } /* end loop */

  swaction = NULL;

}

static void __normalizeAddr( int* addr, int* port ) {
  int l_addr = *addr;
  int l_port = *port;

  if( *addr > 0 && *port == 0 ) {
    /* flat */
    l_addr = (*addr / 8) + 1;
    l_port = (*addr % 8) / 4 + 1;
    l_port += (*addr % 8) % 4;
  }
  else if( *addr == 0 && *port > 0 ) {
    /* port */
    l_addr = (*port-1) / 4 +1;
    l_port = (*port-1) % 4 +1;
  }

  *addr = l_addr;
  *port = l_port;
}


static char* _createAddrKey( int bus, int addr, int port, int type, const char* iid ) {
  iONode node = AppOp.getIniNode( wDigInt.name() );
  const char* def_iid = wDigInt.getiid( node );

  int l_addr = addr;
  int l_port = port;

  if( addr == 0 && port == 0 ) {
    /* undef */
    return NULL;
  }

  __normalizeAddr(&l_addr, &l_port);

  return StrOp.fmt( "%d_%d_%d_%d_%s", bus, l_addr, l_port, type, (iid != NULL && StrOp.len( iid ) > 0) ? iid:def_iid );
}

static const char* __checkFbState( iOSwitch inst ) {
  iOSwitchData data = Data(inst);
  const char* currentState = "-";
  Boolean  fbG = False;
  Boolean  fbR = False;
  Boolean fb2G = False;
  Boolean fb2R = False;
  if( data->fbG ) {
    fbG = FBackOp.getState( data->fbG );
    if( data->fbGinv ) fbG = !fbG;
  }
  if( data->fbR ) {
    fbR = FBackOp.getState( data->fbR );
    if( data->fbRinv ) fbR = !fbR;
  }
  if( data->fb2G ) {
    fb2G = FBackOp.getState( data->fb2G );
    if( data->fb2Ginv ) fb2G = !fb2G;
  }
  if( data->fb2R ) {
    fb2R = FBackOp.getState( data->fb2R );
    if( data->fb2Rinv ) fb2R = !fb2R;
  }

  if( data->fbR && data->fbG && ( (fbR && fbG) || (!fbR && !fbG) ) ) {
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
      "Switch:%s: fbG[%d] && fbR[%d] have the same state!",
      SwitchOp.getId( inst ), fbG, fbR );
  }
  if( data->fb2R && data->fb2G && ( (fb2R && fb2G) || (!fb2R && !fb2G) ) ) {
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
      "Switch:%s: fb2G[%d] && fb2R[%d] have the same state!",
      SwitchOp.getId( inst ), fb2G, fb2R );
  }

  if( StrOp.equals( wSwitch.gettype( data->props ), wSwitch.threeway ) ) {
    if( !fbR && fbG && !fb2R && fb2G )
      data->fbstate = SW_STRAIGHT;
    else if( fbR && !fbG && !fb2R && fb2G )
      data->fbstate = SW_LEFT;
    else if( !fbR && fbG && fb2R && !fb2G )
      data->fbstate = SW_RIGHT;
  }
  else if( StrOp.equals( wSwitch.gettype( data->props ), wSwitch.dcrossing ) ) {
    if( !fbR && fbG && !fb2R && fb2G )
      data->fbstate = SW_STRAIGHT;
    else if( fbR && !fbG && !fb2R && fb2G )
      data->fbstate = SW_LEFT;
    else if( !fbR && fbG && fb2R && !fb2G )
      data->fbstate = SW_RIGHT;
    else if( fbR && !fbG && fb2R && !fb2G )
      data->fbstate = SW_TURNOUT;
  }
  else {
    if( !fbR && fbG )
      data->fbstate = SW_STRAIGHT;
    else if( fbR && !fbG )
      data->fbstate = SW_TURNOUT;
  }

  if( data->fbstate == SW_STRAIGHT )
    currentState = wSwitch.straight;
  else if( data->fbstate == SW_TURNOUT )
    currentState = wSwitch.turnout;
  else if( data->fbstate == SW_LEFT )
    currentState = wSwitch.left;
  else if( data->fbstate == SW_RIGHT )
    currentState = wSwitch.right;

  /* report */
  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
    "Switch[%s] current state [%s], reported state [%s]",
    SwitchOp.getId( inst ), wSwitch.getstate( data->props), currentState );

  /* Not Reached. */
  return currentState;
}

static Boolean __isSet(obj inst, const char* strState) {
  iOSwitchData data = Data(inst);
  Boolean isSet = True;

  if( !StrOp.equals( strState, wSwitch.getwantedstate( data->props) ) ) {
    if( wSwitch.isfbset(data->props) ) {
      wSwitch.setstate( data->props, strState);
    }
    else {
      isSet = False;
    }
  }

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
    "switch[%s] isSet=%s wanted state [%s], reported state [%s] isfbset=%s",
    SwitchOp.getId( (iOSwitch)inst ), isSet?"true":"false", wSwitch.getwantedstate( data->props), strState, wSwitch.isfbset(data->props)?"true":"false" );

  return isSet;
}


static void __fbEvent( obj inst, Boolean puls, const char* id, const char* ident, const char* ident2, const char* ident3, const char* ident4, int val, int wheelcount, Boolean dir ) {
  iOSwitchData data = Data(inst);
  const char* strState = __checkFbState( (iOSwitch)inst );
  Boolean isSet = __isSet(inst, strState);

  if( isSet ) {
    __polariseFrog((iOSwitch)inst, 0, StrOp.equals(wSwitch.straight, strState), StrOp.equals(wSwitch.turnout, strState));
    __polariseFrog((iOSwitch)inst, 1, StrOp.equals(wSwitch.left, strState), StrOp.equals(wSwitch.right, strState));
  }

  {
    iONode nodeF = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    wSwitch.setid( nodeF, SwitchOp.getId( (iOSwitch)inst ) );
    wSwitch.setset( nodeF, isSet );
    wSwitch.setstate( nodeF, strState );
    wSwitch.setswitched( nodeF, wSwitch.getswitched( data->props ) );
    if( wSwitch.getiid( data->props ) != NULL )
      wSwitch.setiid( nodeF, wSwitch.getiid( data->props ) );
    if( data->lockedId != NULL )
      wSwitch.setlocid( nodeF, data->lockedId );
    AppOp.broadcastEvent( nodeF );
  }
}


static Boolean __unregisterCallback( iOSwitch inst ) {
  iOSwitchData data = Data(inst);
  iOModel model = AppOp.getModel(  );
  iOFBack  fbR = ModelOp.getFBack( model, wSwitch.getfbR( data->props ) );
  iOFBack  fbG = ModelOp.getFBack( model, wSwitch.getfbG( data->props ) );
  iOFBack fb2R = ModelOp.getFBack( model, wSwitch.getfb2R( data->props ) );
  iOFBack fb2G = ModelOp.getFBack( model, wSwitch.getfb2G( data->props ) );
  if( fbR != NULL ) {
    FBackOp.setListener( fbR, (obj)NULL, NULL );
  }
  if( fbG != NULL ) {
    FBackOp.setListener( fbG, (obj)NULL, NULL );
  }
  if( fb2R != NULL ) {
    FBackOp.setListener( fb2R, (obj)NULL, NULL );
  }
  if( fb2G != NULL ) {
    FBackOp.setListener( fb2G, (obj)NULL, NULL );
  }
  return True;
}


static Boolean __initCallback( iOSwitch inst ) {
  iOSwitchData data = Data(inst);
  Boolean hasFb = False;
  iOModel model  = AppOp.getModel(  );
  iOFBack fbR    = ModelOp.getFBack( model, wSwitch.getfbR( data->props ) );
  iOFBack fbG    = ModelOp.getFBack( model, wSwitch.getfbG( data->props ) );
  iOFBack fb2R   = ModelOp.getFBack( model, wSwitch.getfb2R( data->props ) );
  iOFBack fb2G   = ModelOp.getFBack( model, wSwitch.getfb2G( data->props ) );
  iOFBack fbOcc  = ModelOp.getFBack( model, wSwitch.getfbOcc( data->props ) );
  iOFBack fbOcc2 = ModelOp.getFBack( model, wSwitch.getfbOcc2( data->props ) );

  data->fbR    = NULL;
  data->fbG    = NULL;
  data->fb2R   = NULL;
  data->fb2G   = NULL;
  data->fbOcc  = NULL;
  data->fbOcc2 = NULL;


  if( fbR != NULL ) {
    FBackOp.setListener( fbR, (obj)inst, &__fbEvent );
    data->hasFbSignal = True;
    data->fbR = fbR;
    data->fbRinv = wSwitch.isfbRinv(data->props);
    hasFb = True;
  }
  if( fbG != NULL ) {
    FBackOp.setListener( fbG, (obj)inst, &__fbEvent );
    data->hasFbSignal = True;
    data->fbG = fbG;
    data->fbGinv = wSwitch.isfbGinv(data->props);
    hasFb = True;
  }
  if( fb2R != NULL ) {
    FBackOp.setListener( fb2R, (obj)inst, &__fbEvent );
    data->hasFbSignal = True;
    data->fb2R = fb2R;
    data->fb2Rinv = wSwitch.isfb2Rinv(data->props);
    hasFb = True;
  }
  if( fb2G != NULL ) {
    FBackOp.setListener( fb2G, (obj)inst, &__fbEvent );
    data->hasFbSignal = True;
    data->fb2G = fb2G;
    data->fb2Ginv = wSwitch.isfb2Ginv(data->props);
    hasFb = True;
  }
  if( fbOcc != NULL ) {
    data->fbOcc = fbOcc;
  }

  if( fbOcc2 != NULL ) {
    data->fbOcc2 = fbOcc2;
  }

  return hasFb;
}

/*
 ***** _Public functions.
 */
static const char* _getId( iOSwitch inst ) {
  iOSwitchData data = Data(inst);
  return wSwitch.getid( data->props );
}

static void* _getProperties( void* inst ) {
  iOSwitchData data = Data((iOSwitch)inst);
  return data->props;
}


static Boolean _link( iOSwitch inst, int linkto ) {
  if( inst != NULL ) {
    iOSwitchData data = Data(inst);

    if( wSwitch.istd( data->props ) ) {
      iOControl control = AppOp.getControl();
      iONode cmd = NodeOp.inst( wSysCmd.name(), NULL, ELEMENT_NODE );
      wSysCmd.setcmd( cmd, wSysCmd.link );
      wSysCmd.setid( cmd, wSwitch.getid(data->props));
      wSysCmd.setiid( cmd, wSwitch.gettdiid(data->props));
      wSysCmd.setvalA( cmd, wSwitch.gettdport(data->props) );
      wSysCmd.setvalB( cmd, linkto );
      if( ControlOp.cmd( control, cmd, NULL ) ) {
        return True;
      }
    }
  }
  return False;
}


static Boolean _unLink( iOSwitch inst ) {
  if( inst != NULL ) {
    iOSwitchData data = Data(inst);

    if( wSwitch.istd( data->props ) ) {
      iOControl control = AppOp.getControl();
      iONode cmd = NodeOp.inst( wSysCmd.name(), NULL, ELEMENT_NODE );
      wSysCmd.setcmd( cmd, wSysCmd.ulink );
      wSysCmd.setiid( cmd, wSwitch.gettdiid( data->props ) );
      wSysCmd.setid( cmd, wSwitch.getid( data->props ) );
      wSysCmd.setvalA( cmd, wSwitch.gettdport(data->props) );
      if( ControlOp.cmd( control, cmd, NULL ) ) {
        return True;
      }
    }
  }
  return False;
}




static Boolean _lock( iOSwitch inst, const char* id, iORoute route ) {
  iOSwitchData data = Data(inst);
  Boolean ok = False;

  if( data->activated && data->fbstate != SW_UNKNOWN && !SwitchOp.isSet(inst) ) {
    /* pending operation */
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Switch [%s] pending operation...",
                   SwitchOp.getId( inst ) );
    return False;
  }

  /* wait only 10ms for getting the mutex: */
  if( !MutexOp.trywait( data->muxLock, 10 ) ) {
    return False;
  }

  if( data->lockedId == NULL || (StrOp.equals( id, data->lockedId ) && (route != NULL ? (data->route == route):True )) ) {
    data->lockedId = id;
    data->route = route;
    /* Broadcast to clients. Node6 */
    {
      iONode nodeF = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      wSwitch.setid( nodeF, SwitchOp.getId( inst ) );
      wSwitch.setstate( nodeF, wSwitch.getstate( data->props ) );
      wSwitch.setswitched( nodeF, wSwitch.getswitched( data->props ) );
      if( data->lockedId != NULL )
        wSwitch.setlocid( nodeF, data->lockedId );
      AppOp.broadcastEvent( nodeF );
    }
    ok = True;
  }

  /* Unlock the semaphore: */
  MutexOp.post( data->muxLock );

  return ok;
}

static Boolean _unLock( iOSwitch inst, const char* id, iORoute route, Boolean force ) {
  iOSwitchData data = Data(inst);
  if( force || (data->lockedId == NULL && id == NULL) || (StrOp.equals( id, data->lockedId ) && (route != NULL ? (data->route == route):True )) ) {
    data->lockedId = NULL;
    data->route    = NULL;
    data->savepostimer = wCtrl.getsavepostime( wFreeRail.getctrl( AppOp.getIni(  ) ) ) * 10;
    /* Broadcast to clients. Node6 */
    {
      iONode nodeF = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      wSwitch.setid( nodeF, SwitchOp.getId( inst ) );
      wSwitch.setstate( nodeF, wSwitch.getstate( data->props ) );
      wSwitch.setswitched( nodeF, wSwitch.getswitched( data->props ) );
      wSwitch.setlocid( nodeF, wSwitch.unlocked );
      AppOp.broadcastEvent( nodeF );
    }
    return True;
  }
  else {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
        "Switch [%s] is locked by [%s], cannot be unlocked by [%s].",
        SwitchOp.getId( inst ), data->lockedId, id );
    if( data->route != NULL && route != NULL ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
          "Switch [%s] is locked by route [%s] and cannot be unlocked by route [%s]",
          SwitchOp.getId( inst ), RouteOp.base.id(data->route), RouteOp.base.id(route) );
    }
  }
  return False;
}

static Boolean _isLocked( iOSwitch inst, const char* id, Boolean manual ) {
  iOSwitchData data = Data(inst);
  const char* blockid = wSwitch.getblockid(data->props);

  if( data->lockedId != NULL && id == NULL ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "Switch \"%s\" is locked by \"%s\".",
                   SwitchOp.getId( inst ), data->lockedId );
    return True;
  }
  if( data->lockedId != NULL && !StrOp.equals( id, data->lockedId ) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "Switch \"%s\" is locked by \"%s\".",
                   SwitchOp.getId( inst ), data->lockedId );
    return True;
  }
  if( !manual && blockid != NULL && StrOp.len(blockid) > 0 ) {
    iIBlockBase bk = ModelOp.getBlock( AppOp.getModel(), blockid);
    if( bk != NULL && !bk->isFree(bk, id) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "Block [%s] is not free which occupies switch [%s].",
                     blockid, SwitchOp.getId( inst ) );
      return True;
    }
  }
  if( (data->fbOcc != NULL && FBackOp.getState(data->fbOcc)) || (data->fbOcc2 != NULL && FBackOp.getState(data->fbOcc2)) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "Switch [%s] is electrically occupied",
                 SwitchOp.getId( inst ) );

    return True;
  }
  return False;
}

static Boolean _isLeft( iOSwitch inst ) {
  iOSwitchData data = Data(inst);
  return StrOp.equals( wSwitch.left, wSwitch.gettype( data->props ) );
}

static Boolean _isRight( iOSwitch inst ) {
  iOSwitchData data = Data(inst);
  return StrOp.equals( wSwitch.right, wSwitch.gettype( data->props ) );
}

static void _green( iOSwitch inst ) {
  iOSwitchData data = Data(inst);
  int error = 0;
  iONode node = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
  wSwitch.setcmd( node, wSwitch.straight );
  wSwitch.setid( node, SwitchOp.getId( inst ) );
  SwitchOp.cmd( inst, node, True, 0, &error, NULL );
}

static void _red( iOSwitch inst ) {
  iOSwitchData data = Data(inst);
  int error = 0;
  iONode node = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
  wSwitch.setcmd( node, wSwitch.turnout );
  wSwitch.setid( node, SwitchOp.getId( inst ) );
  SwitchOp.cmd( inst, node, True, 0, &error, NULL );
}


static Boolean _isSet( iOSwitch inst ) {
  iOSwitchData data  = Data(inst);
  Boolean      isSet = True;

  if( (data->hasFbSignal && ModelOp.isEnableSwFb(AppOp.getModel())) || wSwitch.isfbusefield(data->props) ) {
    sw_state stateCmd = SW_STRAIGHT;

    if( StrOp.equals( wSwitch.straight, wSwitch.getstate( data->props ) ) )
      stateCmd = SW_STRAIGHT;
    else if( StrOp.equals( wSwitch.turnout, wSwitch.getstate( data->props ) ) )
      stateCmd = SW_TURNOUT;
    else if( StrOp.equals( wSwitch.left, wSwitch.getstate( data->props ) ) )
      stateCmd = SW_LEFT;
    else if( StrOp.equals( wSwitch.right, wSwitch.getstate( data->props ) ) )
      stateCmd = SW_RIGHT;

    if( data->hasFbSignal ) {
      __checkFbState( inst );
      if( stateCmd != data->fbstate )
        isSet = False;
    }
    else {
      /* check fieldstate */
      isSet = StrOp.equals(wSwitch.getwantedstate(data->props), wSwitch.getfieldstate(data->props));
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "switch[%s] isSet=%s wanted=%s field=%s",
          SwitchOp.getId( inst ), isSet?"true":"false", wSwitch.getwantedstate(data->props), wSwitch.getfieldstate(data->props) );
    }
  }
  else {
    return !data->pendingSet;
  }

  return isSet;
}


static void __flipThread( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOSwitch sw = (iOSwitch)ThreadOp.getParm( th );
  iOSwitchData data = Data(sw);
  int error = 0;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Flip thread for \"%s\" started.", data->id );

  ThreadOp.sleep(wSwitch.getdelay(data->props));
  iONode cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
  wSwitch.setcmd( cmd, wSwitch.flip );
  wSwitch.setid( cmd, wSwitch.getid( data->props ) );
  wSwitch.setiid( cmd, wSwitch.getiid( data->props ) );

  SwitchOp.cmd( sw, cmd, True, 0, &error, NULL );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Flip thread for \"%s\" ended.", data->id );
  data->pendingflip = False;
  ThreadOp.base.del(th);
}


static void __polariseFrog(iOSwitch inst, int frog, Boolean relays1, Boolean relays2) {
  iOSwitchData data = Data(inst);
  iOControl control = AppOp.getControl();
  int error = 0;
  int addrpol1 = 0;
  int portpol1 = 0;
  int gatepol1 = 0;
  int addrpol2 = 0;
  int portpol2 = 0;
  int gatepol2 = 0;

  if( frog == 0 ) {
    addrpol1 = wSwitch.getaddr0pol1(data->props);
    portpol1 = wSwitch.getport0pol1(data->props);
    gatepol1 = wSwitch.getgate0pol1(data->props);
    addrpol2 = wSwitch.getaddr0pol2(data->props);
    portpol2 = wSwitch.getport0pol2(data->props);
    gatepol2 = wSwitch.getgate0pol2(data->props);
  }
  else if( frog == 1 ) {
    addrpol1 = wSwitch.getaddr1pol1(data->props);
    portpol1 = wSwitch.getport1pol1(data->props);
    gatepol1 = wSwitch.getgate1pol1(data->props);
    addrpol2 = wSwitch.getaddr1pol2(data->props);
    portpol2 = wSwitch.getport1pol2(data->props);
    gatepol2 = wSwitch.getgate1pol2(data->props);
  }

  if( addrpol1 > 0 || portpol1 > 0 ) {
    iONode cmd = NULL;
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "polarise: frog=%d addr1=%d:%d addr2=%d:%d relays1=%d relays2=%d", frog, addrpol1, portpol1, addrpol2, portpol2, relays1, relays2 );
    if( wSwitch.isfrogswitch(data->props) ) {
      cmd = NodeOp.inst(  wSwitch.name(), NULL, ELEMENT_NODE );
      wSwitch.setiid( cmd, wSwitch.getfrogiid( data->props ) );
      if( wSwitch.getbuspol(data->props) > 0 )
        wSwitch.setbus( cmd, wSwitch.getbuspol(data->props));
      else
        wSwitch.setbus( cmd, wSwitch.getbus(data->props));
      wItem.setuidname( cmd, wItem.getuidname( data->props ) );
      wSwitch.setaddr1( cmd, addrpol1);
      wSwitch.setport1( cmd, portpol1);
      wItem.setuidname(cmd, wItem.getuidname(data->props));
      wSwitch.setcmd( cmd, relays1?wSwitch.turnout:wSwitch.straight);
    }
    else {
      cmd = NodeOp.inst(  wOutput.name(), NULL, ELEMENT_NODE );
      wOutput.setiid( cmd, wSwitch.getfrogiid( data->props ) );
      if( wSwitch.getbuspol(data->props) > 0 )
        wOutput.setbus( cmd, wSwitch.getbuspol(data->props));
      else
        wOutput.setbus( cmd, wSwitch.getbus(data->props));
      wItem.setuidname(cmd, wItem.getuidname(data->props));
      wOutput.setaddr( cmd, addrpol1);
      wOutput.setport( cmd, portpol1);
      wOutput.setgate( cmd, gatepol1);
      wOutput.setporttype( cmd, wSwitch.getfrogporttype(data->props));
      wOutput.setaccessory( cmd, wSwitch.isfrogaccessory(data->props));
      wOutput.setcmd( cmd, relays1?wOutput.on:wOutput.off);
    }
    ControlOp.cmd( control, cmd, &error );
    ThreadOp.sleep(50);
  }

  if( addrpol2 > 0 || portpol2 > 0 ) {
    iONode cmd = NULL;
    if( wSwitch.isfrogswitch(data->props) ) {
      cmd = NodeOp.inst(  wSwitch.name(), NULL, ELEMENT_NODE );
      wSwitch.setiid( cmd, wSwitch.getfrogiid( data->props ) );
      if( wSwitch.getbuspol(data->props) > 0 )
        wSwitch.setbus( cmd, wSwitch.getbuspol(data->props));
      else
        wSwitch.setbus( cmd, wSwitch.getbus(data->props));
      wItem.setuidname(cmd, wItem.getuidname(data->props));
      wSwitch.setaddr1( cmd, addrpol2);
      wSwitch.setport1( cmd, portpol2);
      wSwitch.setcmd( cmd, relays2?wSwitch.turnout:wSwitch.straight);
    }
    else {
      cmd = NodeOp.inst(  wOutput.name(), NULL, ELEMENT_NODE );
      wOutput.setiid( cmd, wSwitch.getfrogiid( data->props ) );
      if( wSwitch.getbuspol(data->props) > 0 )
        wOutput.setbus( cmd, wSwitch.getbuspol(data->props));
      else
        wOutput.setbus( cmd, wSwitch.getbus(data->props));
      wItem.setuidname(cmd, wItem.getuidname(data->props));
      wOutput.setaddr( cmd, addrpol2);
      wOutput.setport( cmd, portpol2);
      wOutput.setgate( cmd, gatepol2);
      wOutput.setporttype( cmd, wSwitch.getfrogporttype(data->props));
      wOutput.setaccessory( cmd, wSwitch.isfrogaccessory(data->props));
      wOutput.setcmd( cmd, relays2?wOutput.on:wOutput.off);
    }
    ControlOp.cmd( control, cmd, &error );
    ThreadOp.sleep(50);
  }
}

static int __checkCmd( iOSwitch inst, iONode nodeA, Boolean update, int extra, int* error, const char* lcid ) {
  iOSwitchData o = Data(inst);
  if( SwitchOp.isLocked(inst, NULL, wSwitch.ismanualcmd( nodeA )) ) {
    if( lcid == NULL || !StrOp.equals( lcid, o->lockedId ) || StrOp.len(lcid) == 0 ) {
      TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "switch [%s] is locked by [%s]: reject any commands from others",
                   SwitchOp.getId( inst ), o->lockedId != NULL ? o->lockedId:wSwitch.getblockid(o->props));
      if( wSwitch.isforcecmd( nodeA ) || wSwitch.isinitfield(nodeA) ) {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "switch [%s] command [%s] is forced%s",
                     SwitchOp.getId( inst ), wSwitch.getcmd(nodeA), wSwitch.isinitfield(nodeA)?" by init field":"" );
      }
      else {
        NodeOp.base.del(nodeA);
        return 0;
      }
    }
  }

  if( StrOp.equals( wSwitch.unlock, wSwitch.getcmd( nodeA ) ) ) {
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "unlock switch [%s]",
                 SwitchOp.getId( inst ) );
    SwitchOp.unLock( inst, o->lockedId, NULL, False );
    NodeOp.base.del(nodeA);
    return 1;
  }


  if( wSwitch.getaddr1( o->props ) == 0 && wSwitch.getport1( o->props ) == 0 ) {
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "Switch [%s] has no address.",
                   SwitchOp.getId( inst ) );
    NodeOp.base.del(nodeA);
    return 1;
  }

  if( (o->fbOcc != NULL && FBackOp.getState(o->fbOcc)) ||  (o->fbOcc2 != NULL && FBackOp.getState(o->fbOcc2)) ) {
    /* reject command because its electically occupied */
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "reject command because switch [%s] electically occupied",
                 SwitchOp.getId( inst ) );
    return 0;
  }

  /* Test */
  if( StrOp.equals( wSwitch.teston, wSwitch.getcmd( nodeA ) ) && o->testThread == NULL ) {
    o->testThread = ThreadOp.inst( o->id, &__testThread, inst );
    o->testRun = True;
    ThreadOp.start( o->testThread );
    NodeOp.base.del(nodeA);
    wSwitch.settesting( o->props, True);
    return True;
  }
  else if( StrOp.equals( wSwitch.testoff, wSwitch.getcmd( nodeA ) ) ) {
    o->testRun = False;
    NodeOp.base.del(nodeA);
    wSwitch.settesting( o->props, False);
    return True;
  }


  return -1;
}


static Boolean __doCmd( iOSwitch inst, iONode nodeA, Boolean update, int extra, int* error, const char* lcid ) {
  iOSwitchData o = Data(inst);
  iOControl control = AppOp.getControl();

  const char* state     = wSwitch.getcmd( nodeA );
  const char* prevstate = wSwitch.getcmd( o->props );
  Boolean inv1 = wSwitch.isinv( o->props );
  Boolean inv2 = wSwitch.isinv2( o->props );
  const char* iid = wSwitch.getiid( o->props );
  int pause = wSwitch.getpause(nodeA);

  o->savepostimer = wCtrl.getsavepostime( wFreeRail.getctrl( AppOp.getIni(  ) ) ) * 10;

  if( !MutexOp.trywait( o->muxCmd, 100 ) ) {
    NodeOp.base.del(nodeA);
    return False;
  }

  __polariseFrog(inst, 0, False, False);
  __polariseFrog(inst, 1, False, False);

  /* flip */
  if( StrOp.equals( wSwitch.flip, wSwitch.getcmd( nodeA ) ) ) {
    const char* savedState = wSwitch.getstate( o->props );

    if( StrOp.equals( wSwitch.gettype( o->props ), wSwitch.threeway ) ) {
      if( StrOp.equals( wSwitch.left, savedState ) )
        state = wSwitch.straight;
      else if( StrOp.equals( wSwitch.straight, savedState ) )
        state = wSwitch.right;
      else if( StrOp.equals( wSwitch.right, savedState ) )
        state = wSwitch.left;
      else {
        state = wSwitch.straight;
        wSwitch.setstate( o->props, wSwitch.left );
      }
    }
    else if( StrOp.equals( wSwitch.gettype( o->props ), wSwitch.dcrossing ) && ( wSwitch.getaddr2( o->props ) > 0 || wSwitch.getport2( o->props ) > 0 ) ) {
      if( StrOp.equals( wSwitch.getsubtype(o->props), wSwitch.subleft) ) {
        if( StrOp.equals( wSwitch.straight, savedState ) )
          state = wSwitch.left;
        else if( StrOp.equals( wSwitch.left, savedState ) )
          state = wSwitch.turnout;
        else
          state = wSwitch.straight;
      }
      else if( StrOp.equals( wSwitch.getsubtype(o->props), wSwitch.subright) ) {
        if( StrOp.equals( wSwitch.straight, savedState ) )
          state = wSwitch.right;
        else if( StrOp.equals( wSwitch.right, savedState ) )
          state = wSwitch.turnout;
        else
          state = wSwitch.straight;
      }
      else {
        if( StrOp.equals( wSwitch.left, savedState ) )
          state = wSwitch.straight;
        else if( StrOp.equals( wSwitch.straight, savedState ) )
          state = wSwitch.right;
        else if( StrOp.equals( wSwitch.right, savedState ) )
          state = wSwitch.turnout;
        else if( StrOp.equals( wSwitch.turnout, savedState ) )
          state = wSwitch.left;
        else {
          state = wSwitch.straight;
          wSwitch.setstate( o->props, wSwitch.left );
        }
      }
    }
    else if( StrOp.equals( wSwitch.gettype( o->props ), wSwitch.dcrossing ) && wSwitch.getaddr2( o->props ) == 0 && wSwitch.getport2( o->props ) == 0 ) {
      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Double crossing with one motor \"%s\" is not supported!",
                         SwitchOp.getId( inst ) );
      MutexOp.post( o->muxCmd );
      return False;
    }
    else {
      if( StrOp.equals( wSwitch.straight, savedState ) )
        state = wSwitch.turnout;
      else if( StrOp.equals( wSwitch.turnout, savedState ) )
        state = wSwitch.straight;
      else {
        state = wSwitch.straight;
        wSwitch.setstate( o->props, wSwitch.turnout );
      }
    }
  }

  if( StrOp.equals(wSwitch.left, state ) )
    wSwitch.setstate( o->props, wSwitch.left );
  else if( StrOp.equals(wSwitch.straight, state ) )
    wSwitch.setstate( o->props, wSwitch.straight );
  else if( StrOp.equals(wSwitch.right, state ) )
    wSwitch.setstate( o->props, wSwitch.right );
  else if( StrOp.equals(wSwitch.turnout, state ) )
    wSwitch.setstate( o->props, wSwitch.turnout );

  TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "Switch [%s] will be set to [%s,%d,%d]",
                 SwitchOp.getId( inst ), state, wSwitch.issinglegate( o->props ), wSwitch.getgate1( o->props ) );
  wSwitch.setwantedstate( o->props, state );


  if( iid != NULL )
    wSwitch.setiid( nodeA, iid );

  wSwitch.setprot( nodeA, wSwitch.getprot( o->props ) );
  wItem.setuidname(nodeA, wItem.getuidname(o->props));
  wSwitch.setbus( nodeA, wSwitch.getbus( o->props ) );

  /* three way */
  if( StrOp.equals( wSwitch.gettype( o->props ), wSwitch.threeway ) ) {
    const char* state1 = NULL;
    const char* state2 = NULL;
    /* NodeA is cleaned up by the digint so we need a copy for the second unit. */
    iONode nodeA2 = (iONode)nodeA->base.clone( nodeA );

    if( StrOp.equals( state, wSwitch.left ) ) {
      state1 = inv1?wSwitch.straight:wSwitch.turnout;
      state2 = inv2?wSwitch.turnout:wSwitch.straight;

      wSwitch.setaddr1( nodeA, wSwitch.getaddr2( o->props ) );
      wSwitch.setport1( nodeA, wSwitch.getport2( o->props ) );
      wSwitch.setgate1( nodeA, wSwitch.getgate2( o->props ) );
      wSwitch.setparam1( nodeA, wSwitch.getparam2( o->props ) );
      wSwitch.setvalue1( nodeA, wSwitch.getvalue2( o->props ) );
      wSwitch.setcmd( nodeA, state2 );

      wSwitch.setaddr1( nodeA2, wSwitch.getaddr1( o->props ) );
      wSwitch.setport1( nodeA2, wSwitch.getport1( o->props ) );
      wSwitch.setgate1( nodeA2, wSwitch.getgate1( o->props ) );
      wSwitch.setparam1( nodeA2, wSwitch.getparam1( o->props ) );
      wSwitch.setvalue1( nodeA2, wSwitch.getvalue1( o->props ) );
      wSwitch.setcmd( nodeA2, state1 );
    }
    else if( StrOp.equals( state, wSwitch.right ) ) {
      state1 = inv1?wSwitch.turnout:wSwitch.straight;
      state2 = inv2?wSwitch.straight:wSwitch.turnout;

      wSwitch.setaddr1( nodeA, wSwitch.getaddr1( o->props ) );
      wSwitch.setport1( nodeA, wSwitch.getport1( o->props ) );
      wSwitch.setgate1( nodeA, wSwitch.getgate1( o->props ) );
      wSwitch.setparam1( nodeA, wSwitch.getparam1( o->props ) );
      wSwitch.setvalue1( nodeA, wSwitch.getvalue1( o->props ) );
      wSwitch.setcmd( nodeA, state1 );

      wSwitch.setaddr1( nodeA2, wSwitch.getaddr2( o->props ) );
      wSwitch.setport1( nodeA2, wSwitch.getport2( o->props ) );
      wSwitch.setgate1( nodeA2, wSwitch.getgate2( o->props ) );
      wSwitch.setparam1( nodeA2, wSwitch.getparam2( o->props ) );
      wSwitch.setvalue1( nodeA2, wSwitch.getvalue2( o->props ) );
      wSwitch.setcmd( nodeA2, state2 );
    }
    else {
      state1 = inv1?wSwitch.turnout:wSwitch.straight;
      state2 = inv2?wSwitch.turnout:wSwitch.straight;

      wSwitch.setaddr1( nodeA, wSwitch.getaddr1( o->props ) );
      wSwitch.setport1( nodeA, wSwitch.getport1( o->props ) );
      wSwitch.setgate1( nodeA, wSwitch.getgate1( o->props ) );
      wSwitch.setparam1( nodeA, wSwitch.getparam1( o->props ) );
      wSwitch.setvalue1( nodeA, wSwitch.getvalue1( o->props ) );
      wSwitch.setcmd( nodeA, state1 );

      wSwitch.setaddr1( nodeA2, wSwitch.getaddr2( o->props ) );
      wSwitch.setport1( nodeA2, wSwitch.getport2( o->props ) );
      wSwitch.setgate1( nodeA2, wSwitch.getgate2( o->props ) );
      wSwitch.setparam1( nodeA2, wSwitch.getparam2( o->props ) );
      wSwitch.setvalue1( nodeA2, wSwitch.getvalue2( o->props ) );
      wSwitch.setcmd( nodeA2, state2 );
    }

    wSwitch.setdelay( nodeA, wSwitch.getdelay( o->props ) );
    wSwitch.setactdelay( nodeA, wSwitch.isactdelay( o->props ) );
    wSwitch.setsinglegate( nodeA, wSwitch.issinglegate( o->props ) );
    wSwitch.setaccessory( nodeA, wSwitch.isaccessory(o->props) );
    wSwitch.setporttype( nodeA, wSwitch.getporttype( o->props ) );
    if( !ControlOp.cmd( control, nodeA, error ) ) {
      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Switch \"%s\" could not be switched!",
                     SwitchOp.getId( inst ) );
      MutexOp.post( o->muxCmd );
      return False;
    }

    if( pause > 0 ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "delay command for switch[%s] %dms", o->id, pause );
      if( wSwitch.getdelay( o->props ) > pause )
        ThreadOp.sleep(wSwitch.getdelay( o->props ));
      else
        ThreadOp.sleep(pause);
    }
    else {
      /* sleep the switch delay time */
      ThreadOp.sleep( wSwitch.getdelay( o->props ) );
    }

    wSwitch.setdelay( nodeA2, wSwitch.getdelay( o->props ) );
    wSwitch.setactdelay( nodeA2, wSwitch.isactdelay( o->props ) );
    wSwitch.setsinglegate( nodeA2, wSwitch.issinglegate( o->props ) );
    wSwitch.setaccessory( nodeA2, wSwitch.isaccessory(o->props) );
    wSwitch.setporttype( nodeA2, wSwitch.getporttype( o->props ) );
    if( !ControlOp.cmd( control, nodeA2, error ) ) {
      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Switch \"%s\" could not be switched!",
                     SwitchOp.getId( inst ) );
      MutexOp.post( o->muxCmd );
      return False;
    }
  }

  /* double crossing */
  else if( StrOp.equals( wSwitch.gettype( o->props ), wSwitch.dcrossing ) ) {
    const char* state1 = NULL;
    const char* state2 = NULL;
    Boolean has2Units = ( wSwitch.getaddr2( o->props ) > 0 || wSwitch.getport2( o->props ) > 0 )  ? True:False;
    iONode nodeA2 = NULL;

    /* NodeA is cleaned up by the digint so we need a copy for the second unit. */
    if( has2Units ) {
      nodeA2 = (iONode)nodeA->base.clone( nodeA );
      if( StrOp.equals( state, wSwitch.left ) ) {
        state1 = inv1?wSwitch.straight:wSwitch.turnout;
        state2 = inv2?wSwitch.turnout:wSwitch.straight;
      }
      else if( StrOp.equals( state, wSwitch.right ) ) {
        state1 = inv1?wSwitch.turnout:wSwitch.straight;
        state2 = inv2?wSwitch.straight:wSwitch.turnout;
      }
      else if( StrOp.equals( state, wSwitch.turnout ) ) {
        state1 = inv1?wSwitch.straight:wSwitch.turnout;
        state2 = inv2?wSwitch.straight:wSwitch.turnout;
      }
      else if( StrOp.equals( state, wSwitch.straight ) ) {
        state1 = inv1?wSwitch.turnout:wSwitch.straight;
        state2 = inv2?wSwitch.turnout:wSwitch.straight;
      }

      wSwitch.setaddr1( nodeA, wSwitch.getaddr1( o->props ) );
      wSwitch.setport1( nodeA, wSwitch.getport1( o->props ) );
      wSwitch.setgate1( nodeA, wSwitch.getgate1( o->props ) );
      wSwitch.setparam1( nodeA, wSwitch.getparam1( o->props ) );
      wSwitch.setvalue1( nodeA, wSwitch.getvalue1( o->props ) );
      wSwitch.setdelay( nodeA, wSwitch.getdelay( o->props ) );
      wSwitch.setactdelay( nodeA, wSwitch.isactdelay( o->props ) );
      wSwitch.setsinglegate( nodeA, wSwitch.issinglegate( o->props ) );
      wSwitch.setaccessory( nodeA, wSwitch.isaccessory(o->props) );
      wSwitch.setporttype( nodeA, wSwitch.getporttype( o->props ) );
      wSwitch.setcmd( nodeA, state1 );
      if( !ControlOp.cmd( control, nodeA, error ) ) {
        TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Switch \"%s\" could not be switched!",
                       SwitchOp.getId( inst ) );
        MutexOp.post( o->muxCmd );
        return False;
      }

      if( pause > 0 ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "delay command for switch[%s] %dms", o->id, pause );
        if( wSwitch.getdelay( o->props ) > pause )
          ThreadOp.sleep(wSwitch.getdelay( o->props ));
        else
          ThreadOp.sleep(pause);
      }
      else {
        /* sleep the switch delay time */
        ThreadOp.sleep( wSwitch.getdelay( o->props ) );
      }

      wSwitch.setaddr1( nodeA2, wSwitch.getaddr2( o->props ) );
      wSwitch.setport1( nodeA2, wSwitch.getport2( o->props ) );
      wSwitch.setgate1( nodeA2, wSwitch.getgate2( o->props ) );
      wSwitch.setparam1( nodeA2, wSwitch.getparam2( o->props ) );
      wSwitch.setvalue1( nodeA2, wSwitch.getvalue2( o->props ) );
      wSwitch.setdelay( nodeA2, wSwitch.getdelay( o->props ) );
      wSwitch.setactdelay( nodeA2, wSwitch.isactdelay( o->props ) );
      wSwitch.setsinglegate( nodeA2, wSwitch.issinglegate( o->props ) );
      wSwitch.setaccessory( nodeA2, wSwitch.isaccessory(o->props) );
      wSwitch.setporttype( nodeA2, wSwitch.getporttype( o->props ) );
      wSwitch.setcmd( nodeA2, state2 );
      if( !ControlOp.cmd( control, nodeA2, error ) ) {
        TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Switch \"%s\" could not be switched!",
                       SwitchOp.getId( inst ) );
        MutexOp.post( o->muxCmd );
        return False;
      }
    } else {
      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Double crossing with one motor \"%s\" is not supported!",
                     SwitchOp.getId( inst ) );
      MutexOp.post( o->muxCmd );
      return False;
    }

  }

  /* normal switch */
  else {

    if( inv1 && StrOp.equals( wSwitch.straight, state ) )
      state = wSwitch.turnout;
    else if( inv1 && StrOp.equals( wSwitch.turnout, state ) )
      state = wSwitch.straight;
    else if( inv1 && StrOp.equals( wSwitch.left, state ) )
      state = wSwitch.right;
    else if( inv1 && StrOp.equals( wSwitch.right, state ) )
      state = wSwitch.left;

    wSwitch.setaddr1( nodeA, wSwitch.getaddr1( o->props ) );
    wSwitch.setport1( nodeA, wSwitch.getport1( o->props ) );
    wSwitch.setgate1( nodeA, wSwitch.getgate1( o->props ) );
    wSwitch.setparam1( nodeA, wSwitch.getparam1( o->props ) );
    wSwitch.setvalue1( nodeA, wSwitch.getvalue1( o->props ) );
    wSwitch.setdelay( nodeA, wSwitch.getdelay( o->props ) );
    wSwitch.setactdelay( nodeA, wSwitch.isactdelay( o->props ) );
    wSwitch.setsinglegate( nodeA, wSwitch.issinglegate( o->props ) );
    wSwitch.setaccessory( nodeA, wSwitch.isaccessory(o->props) );
    wSwitch.setporttype( nodeA, wSwitch.getporttype( o->props ) );
    wSwitch.setcmd( nodeA, state );
    if( !ControlOp.cmd( control, nodeA, error ) ) {
      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "Switch \"%s\" could not be switched!",
                     SwitchOp.getId( inst ) );
      MutexOp.post( o->muxCmd );
      return False;
    }
  }

  __checkAction( inst, False );

  /* both strings can be compared by pointer because they both are of qualifier const */
  if( prevstate != state ) {
    /* increase the switch counter */
    int switched = wSwitch.getswitched(o->props);
    switched++;
    wSwitch.setswitched(o->props, switched);
  }

  if( wSwitch.getfrogtimer(o->props) > 0 ) {
    Boolean relays1a = StrOp.equals(wSwitch.straight, state);
    Boolean relays2a = StrOp.equals(wSwitch.turnout, state);
    Boolean relays1b = StrOp.equals(wSwitch.left, state);
    Boolean relays2b = StrOp.equals(wSwitch.right, state);

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "polarise Frog [%s] timer=%d state=%s(%s)",
        SwitchOp.getId(inst), wSwitch.getfrogtimer(o->props), state, wSwitch.getstate( o->props) );
    ThreadOp.sleep(wSwitch.getfrogtimer(o->props));
    __polariseFrog(inst, 0, relays1a, relays2a);
    __polariseFrog(inst, 1, relays1b, relays2b);
  }


  /* Broadcast to clients. Node6 */

  if( update ) {
    iONode nodeF = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    wSwitch.setid( nodeF, SwitchOp.getId( inst ) );
    wSwitch.setstate( nodeF, wSwitch.getstate( o->props ) );
    wSwitch.setswitched( nodeF, wSwitch.getswitched( o->props ) );
    wSwitch.settesting( nodeF, wSwitch.istesting( o->props ) );

    if( o->hasFbSignal && ModelOp.isEnableSwFb(AppOp.getModel()) )
      wSwitch.setset( nodeF, SwitchOp.isSet(inst) );
    else if( wSwitch.isfbusefield( o->props ) )
      wSwitch.setset( nodeF, SwitchOp.isSet(inst) );

    if( wSwitch.getiid( o->props ) != NULL )
      wSwitch.setiid( nodeF, wSwitch.getiid( o->props ) );
    if( o->lockedId != NULL )
      wSwitch.setlocid( nodeF, o->lockedId );
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "broadcasting switch[%s] state [%s]", o->id, wSwitch.getstate( o->props ) );
    AppOp.broadcastEvent( nodeF );

    __ctcActionLED(inst);


    if( !o->pendingflip ) {
      if( StrOp.equals( wSwitch.gettype( o->props ), wSwitch.decoupler ) && wSwitch.getdelay( o->props ) > 0 ) {
        if( StrOp.equals( state, wSwitch.isinv(o->props) ?wSwitch.turnout:wSwitch.straight ) ) {
          o->pendingflip = True;
          iOThread th = ThreadOp.inst( NULL, &__flipThread, inst );
          ThreadOp.start( th );
        }
      }
    }

  }

  o->activated = True;

  MutexOp.post( o->muxCmd );
  return True;
}


static void __doCmdThread( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOSwitch sw = (iOSwitch)ThreadOp.getParm( th );
  iOSwitchData data = Data(sw);

  iONode nodeA = (iONode)ThreadOp.getPost(th);
  data->pendingSet = True;
  if( nodeA != NULL ) {
    Boolean update = wSwitch.iscmd_update(nodeA);
    int extra = wSwitch.getcmd_extra(nodeA);
    const char* lcid = wSwitch.getcmd_lcid(nodeA);
    int error = 0;
    if( wSwitch.getpause(nodeA) > 0 ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "delay command for switch[%s] %dms", data->id, wSwitch.getpause(nodeA) );
      ThreadOp.sleep(wSwitch.getpause(nodeA));
    }
    __doCmd(sw, nodeA, update, extra, &error, lcid);
    if( wSwitch.issyncdelay(data->props) ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "switch[%s] sync. delay %dms", data->id, wSwitch.getdelay(data->props) );
      ThreadOp.sleep(wSwitch.getdelay(data->props));
    }
  }
  data->pendingSet = False;
  ThreadOp.base.del(th);
}

static Boolean _cmd(iOSwitch inst, iONode nodeA, Boolean update, int extra, int* error, const char* lcid) {
  iOSwitchData data = Data(inst);

  int rc = __checkCmd( inst, nodeA, update, extra, error, lcid );
  if( rc != -1 ) {
    return (rc==1?True:False);
  }

  if( !wSwitch.isinitfield(nodeA) && (wSwitch.getpause(nodeA) > 0 || wSwitch.issyncdelay(data->props) ) ) {
    iOThread th = ThreadOp.inst(NULL, &__doCmdThread, inst);
    wSwitch.setcmd_update(nodeA, update);
    wSwitch.setcmd_extra(nodeA, extra);
    wSwitch.setcmd_lcid(nodeA, lcid);
    data->pendingSet = True;
    ThreadOp.post(th, (obj)nodeA);
    ThreadOp.start(th);
  }
  else {
    return __doCmd(inst, nodeA, update, extra, error, lcid);
  }

  return True;
}


static Boolean _has2Units(iOSwitch inst) {
  iOSwitchData o = Data(inst);
  Boolean has2Units = ( wSwitch.getaddr2( o->props ) > 0 || wSwitch.getport2( o->props ) > 0 )  ? True:False;
  return has2Units;
}

/**
 * Checks for property changes.
 * todo: Range checking?
 */
static void _modify( iOSwitch inst, iONode props ) {
  iOSwitchData o = Data(inst);
  iOModel model = AppOp.getModel(  );
  Boolean move = StrOp.equals( wModelCmd.getcmd( props ), wModelCmd.move );

  int cnt = NodeOp.getAttrCnt( props );
  int i = 0;

  __initCTC(inst, True);
  __unregisterCallback(inst);

  for( i = 0; i < cnt; i++ ) {
    iOAttr attr = NodeOp.getAttr( props, i );
    const char* name  = AttrOp.getName( attr );
    const char* value = AttrOp.getVal( attr );

    if( StrOp.equals("id", name) && StrOp.equals( value, wSwitch.getid(o->props) ) )
      continue; /* skip to avoid making invalid pointers */

    NodeOp.setStr( o->props, name, value );
  }

  if(!move) {
    Boolean has2Units = ( wSwitch.getaddr2( o->props ) > 0 || wSwitch.getport2( o->props ) > 0 )  ? True:False;

    /* initCallback */
    if( __initCallback( inst ) ) {

    }

    if( o->addrKey != NULL )
      ModelOp.removeSwKey( model, o->addrKey );
    o->addrKey = _createAddrKey(
      wSwitch.getbus( o->props ),
      wSwitch.getaddr1( o->props ),
      wSwitch.getport1( o->props ),
      wSwitch.getporttype( o->props ),
      wSwitch.getiid( o->props )
      );
    if( o->addrKey != NULL )
      ModelOp.addSwKey( model, o->addrKey, inst );


    if( has2Units ) {
      if( o->addrKey2 != NULL )
        ModelOp.removeSwKey( model, o->addrKey2 );
      o->addrKey2 = _createAddrKey(
        wSwitch.getbus( o->props ),
        wSwitch.getaddr2( o->props ),
        wSwitch.getport2( o->props ),
        wSwitch.getporttype( o->props ),
        wSwitch.getiid( o->props )
        );
      if( o->addrKey2 != NULL )
        ModelOp.addSwKey( model, o->addrKey2, inst );
    }

    {
      /* delete all childs to make 'room' for the new ones: */
      iONode accctrl = NULL;
      cnt = NodeOp.getChildCnt( o->props );
      while( cnt > 0 ) {
        iONode child = NodeOp.getChild( o->props, 0 );
        iONode removedChild = NodeOp.removeChild( o->props, child );
        if( StrOp.equals( wAccessoryCtrl.name(), NodeOp.getName(child) ) ) {
          /* keep this node because it is referenced by the accessory thread */
          accctrl = child;
        }
        else if( removedChild != NULL) {
          NodeOp.base.del(removedChild);
        }
        cnt = NodeOp.getChildCnt( o->props );
      }

      if( accctrl != NULL )
        NodeOp.addChild( o->props, accctrl );


      /* add the new or modified childs: */
      cnt = NodeOp.getChildCnt( props );
      for( i = 0; i < cnt; i++ ) {
        iONode child = NodeOp.getChild( props, i );
        if( StrOp.equals( wAccessoryCtrl.name(), NodeOp.getName(child) ) && accctrl != NULL) {
          int cnt = NodeOp.getAttrCnt( child );
          int n = 0;
          for( n = 0; n < cnt; n++ ) {
            iOAttr attr = NodeOp.getAttr( child, n );
            const char* name  = AttrOp.getName( attr );
            const char* value = AttrOp.getVal( attr );
            NodeOp.setStr( accctrl, name, value );
          }
        }
        else
          NodeOp.addChild( o->props, (iONode)NodeOp.base.clone(child) );
      }
    }
  }
  else {
    NodeOp.removeAttrByName(o->props, "cmd");
  }

  __initCTC(inst, False);

  if( o->accctrl == NULL ) {
    o->accctrl = wSwitch.getaccessoryctrl(o->props);
  }

  if( o->accctrl != NULL ) {
    o->run = wAccessoryCtrl.isactive(o->accctrl);
    if( o->run && o->accThread == NULL ) {
      o->accThread = ThreadOp.inst( o->id, &__accThread, inst );
      ThreadOp.start( o->accThread );
    }
  }

  /* Broadcast to clients. */
  {
    iONode clone = (iONode)NodeOp.base.clone( o->props );
    AppOp.broadcastEvent( clone );
  }
  props->base.del(props);
}

static const char* _tableHdr(void) {
  return "<tr bgcolor=\"#CCCCCC\"><th>ID</th><th>Address</th><th>Port</th><th>Invert</th><th>type</th><th>x</th><th>y</th><th>z</th></tr>\n";
}

static char* _toHtml( void* inst ) {
  iOSwitchData data = Data((iOSwitch)inst);
  return StrOp.fmt( "<tr><td>%s</td><td align=\"right\">%d</td><td align=\"right\">%d</td><td>%d</td><td>%s</td><td align=\"right\">%d</td><td align=\"right\">%d</td><td align=\"right\">%d</td></tr>\n",
      NodeOp.getStr( data->props, "id", "?" ),
      NodeOp.getInt( data->props, "addr1", 0 ),
      NodeOp.getInt( data->props, "port1", 0 ),
      NodeOp.getBool( data->props, "inv", False ),
      NodeOp.getStr( data->props, "type", "?" ),
      NodeOp.getInt( data->props, "x", 0 ),
      NodeOp.getInt( data->props, "y", 0 ),
      NodeOp.getInt( data->props, "z", 0 )
      );
}

static char* _getForm( void* inst ) {
  iOSwitchData data = Data((iOSwitch)inst);
  return NULL;
}


static char* _postForm( void* inst, const char* postdata ) {
  iOSwitchData data = Data((iOSwitch)inst);
  char* reply = StrOp.fmt( "Thanks!<br>" );
  return reply;
}


static void _reset( iOSwitch inst ) {
  iOSwitchData data = Data(inst);
  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
             "reset switch [%s]", SwitchOp.getId( inst ) );
  SwitchOp.unLock( inst, data->lockedId, NULL, False );
}


static void _event( iOSwitch inst, iONode nodeC ) {
  iOSwitchData data = Data(inst);
  Boolean has2Units = ( wSwitch.getaddr2( data->props ) > 0 || wSwitch.getport2( data->props ) > 0 )  ? True:False;

  if( !wSwitch.issinglegate(data->props) && wSwitch.getgatevalue(nodeC) == 0 ) {
    /* Port off command is only processed for single gate switches only. */
    if( nodeC != NULL )
      NodeOp.base.del(nodeC);
    return;
  }


  if( !data->hasFbSignal ) {
    Boolean inv  = wSwitch.isinv( data->props );
    Boolean inv2 = wSwitch.isinv2( data->props );
    const char* state = wSwitch.getstate( nodeC );

    if( TraceOp.getLevel(NULL) & TRCLEVEL_DEBUG ) {
      char* strNode = (char*)NodeOp.base.toString( nodeC );
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "event %s", strNode );
      StrOp.free( strNode );
    }

    if( has2Units ) {
      /* dual motor */
      int addr = wSwitch.getaddr1( nodeC );
      int port = wSwitch.getport1( nodeC );
      __normalizeAddr( &addr, &port );

      int addr1 = wSwitch.getaddr1( data->props );
      int port1 = wSwitch.getport1( data->props );
      int addr2 = wSwitch.getaddr2( data->props );
      int port2 = wSwitch.getport2( data->props );
      __normalizeAddr( &addr1, &port1 );
      __normalizeAddr( &addr2, &port2 );

      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
          "switch [%s] reported addr=%d port=%d state=%s (addr1=%d(%d) port1=%d(%d) addr2=%d(%d) port2=%d(%d))", SwitchOp.getId(inst),
          addr, port, state, addr1, wSwitch.getaddr1( data->props ), port1, wSwitch.getport1( data->props ),
          addr2, wSwitch.getaddr2( data->props ), port2, wSwitch.getport2( data->props ) );
      if( addr == addr1 && port == port1 ) {
        if( inv )
          data->fieldState1 = StrOp.equals( state, wSwitch.turnout ) ? 0:1;
        else
          data->fieldState1 = StrOp.equals( state, wSwitch.turnout ) ? 1:0;

        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "switch [%s] fieldState1=%d", SwitchOp.getId(inst), data->fieldState1 );
      }
      if( addr == addr2 && port == port2 ) {
        if( inv2 )
          data->fieldState2 = StrOp.equals( state, wSwitch.turnout ) ? 0:1;
        else
          data->fieldState2 = StrOp.equals( state, wSwitch.turnout ) ? 1:0;

        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "switch [%s] fieldState2=%d", SwitchOp.getId(inst), data->fieldState2 );
      }

      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "switch [%s] fieldState1=%d, fieldState2=%d", SwitchOp.getId(inst), data->fieldState1, data->fieldState2 );

      if( StrOp.equals( wSwitch.gettype( data->props ), wSwitch.threeway ) ) {
        if( data->fieldState1 == 0 && data->fieldState2 == 0)
          wSwitch.setstate( data->props, wSwitch.straight );
        else if( data->fieldState1 == 1 && data->fieldState2 == 0)
          wSwitch.setstate( data->props, wSwitch.left );
        else if( data->fieldState1 == 0 && data->fieldState2 == 1)
          wSwitch.setstate( data->props, wSwitch.right );
      }
      else {
        /* double crossing */
        if( data->fieldState1 == 0 && data->fieldState2 == 0)
          wSwitch.setstate( data->props, wSwitch.straight );
        else if( data->fieldState1 == 1 && data->fieldState2 == 0)
          wSwitch.setstate( data->props, wSwitch.left );
        else if( data->fieldState1 == 0 && data->fieldState2 == 1)
          wSwitch.setstate( data->props, wSwitch.right );
        else if( data->fieldState1 == 1 && data->fieldState2 == 1)
          wSwitch.setstate( data->props, wSwitch.turnout );
      }
    }
    else {
      /* single motor */
      if( wSwitch.issinglegate(data->props) && wSwitch.getgatevalue(nodeC) != -1 ) {
        if( inv ) {
          if( wSwitch.getgatevalue(nodeC) < 2 )
            wSwitch.setstate( data->props, wSwitch.getgatevalue(nodeC) ? wSwitch.straight:wSwitch.turnout );
          else {
            if( StrOp.equals( state, wSwitch.turnout ) )
              wSwitch.setstate( data->props, wSwitch.straight );
            else if( StrOp.equals( state, wSwitch.straight ) )
              wSwitch.setstate( data->props, wSwitch.turnout );
          }
        }
        else {
          if( wSwitch.getgatevalue(nodeC) < 2 )
            wSwitch.setstate( data->props, wSwitch.getgatevalue(nodeC) ? wSwitch.turnout:wSwitch.straight );
          else
            wSwitch.setstate( data->props, state );
        }
      }
      else if( !inv ) {
        if( StrOp.equals(wSwitch.left, state ) )
          wSwitch.setstate( data->props, wSwitch.left );
        else if( StrOp.equals(wSwitch.straight, state ) )
          wSwitch.setstate( data->props, wSwitch.straight );
        else if( StrOp.equals(wSwitch.right, state ) )
          wSwitch.setstate( data->props, wSwitch.right );
        else if( StrOp.equals(wSwitch.turnout, state ) )
          wSwitch.setstate( data->props, wSwitch.turnout );
      }
      else {
        if( StrOp.equals( state, wSwitch.turnout ) )
          wSwitch.setstate( data->props, wSwitch.straight );
        else if( StrOp.equals( state, wSwitch.straight ) )
          wSwitch.setstate( data->props, wSwitch.turnout );
      }
    }

    wSwitch.setfieldstate( data->props, wSwitch.getstate(data->props) );

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "switch [%s] field state=%s(%s) gatevalue=%d inv=%d state=%s",
        SwitchOp.getId(inst), wSwitch.getstate( data->props), wSwitch.getstate(nodeC), wSwitch.getgatevalue(nodeC), inv, state );

    __checkAction( inst, True );

    /* Broadcast to clients. Node4 */
    {
      iONode nodeD = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      wSwitch.setid( nodeD, SwitchOp.getId( inst ) );
      wSwitch.setstate( nodeD, wSwitch.getstate( data->props) );
      wSwitch.setswitched( nodeD, wSwitch.getswitched( data->props ) );
      wSwitch.setaddr1( nodeD, wSwitch.getaddr1( data->props ) );
      wSwitch.setport1( nodeD, wSwitch.getport1( data->props ) );
      if( has2Units ) {
        wSwitch.setaddr2( nodeD, wSwitch.getaddr2( data->props ) );
        wSwitch.setport2( nodeD, wSwitch.getport2( data->props ) );
      }

      if( wSwitch.isfbusefield(data->props ) ) {
        /*const char* strState = wSwitch.getstate( data->props);*/
        Boolean isSet = __isSet((obj)inst, wSwitch.getstate( data->props));
        wSwitch.setset( nodeD, isSet );

        if( isSet ) {
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "polarise Frog [%s] state=%s(%s)",
              SwitchOp.getId(inst), state, wSwitch.getstate( data->props) );
          __polariseFrog(inst, 0, StrOp.equals(wSwitch.straight, state), StrOp.equals(wSwitch.turnout, state));
          __polariseFrog(inst, 1, StrOp.equals(wSwitch.left, state), StrOp.equals(wSwitch.right, state));
        }
      }

      if( data->lockedId != NULL )
        wSwitch.setlocid( nodeD, data->lockedId );
      AppOp.broadcastEvent( nodeD );
    }


    {
      obj listener = ListOp.first( data->listeners );
      while( listener != NULL ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
            "switch [%s] informs listener=%s", SwitchOp.getId(inst), listener->id(listener)!=NULL?listener->id(listener):"?" );
        listener->event( listener, data->props );
        listener = ListOp.next( data->listeners );
      };
    }

  }

  /* Cleanup Node3 */
  if( nodeC != NULL )
    NodeOp.base.del(nodeC);

}


static const char* _getAddrKey( iOSwitch inst ) {
  iOSwitchData data = Data(inst);
  return data->addrKey;
}


static const char* _getAddrKey2( iOSwitch inst ) {
  iOSwitchData data = Data(inst);
  return data->addrKey2;
}


/**
 * check save position and sensors
 * is called every 100ms by the controller
 */
static void _checkSenPos( iOSwitch inst ) {
  iOSwitchData data  = Data(inst);
  iOModel      model = AppOp.getModel();
  Boolean      isSet = True;

  if( data->savepostimer > 0 ) {
    data->savepostimer--;

    if( data->savepostimer == 0 &&
        data->lockedId == NULL &&
        !StrOp.equals( wSwitch.getsavepos(data->props), "none") )
      {
      /* check the savepos */
      if( !StrOp.equals( wSwitch.getsavepos(data->props), wSwitch.getstate( data->props ) ) ) {
        int error = 0;
        iONode cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
        wSwitch.setcmd( cmd, wSwitch.getsavepos(data->props) );
        SwitchOp.cmd( inst, cmd, True, 0, &error, NULL );
      }
    }
  }

}


static void __testThread( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOSwitch sw = (iOSwitch)ThreadOp.getParm( th );
  iOSwitchData data = Data(sw);
  int retry = 0;
  int delay = wAccessoryCtrl.getdelay(data->accctrl);

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Test thread for \"%s\" started.", data->id );

  if( delay == 0 )
    delay = 2;

  do {
    iONode swcmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    wSwitch.setcmd( swcmd, wSwitch.flip );

    retry = 0;
    while( !SwitchOp.isSet(sw) && retry < 60) {
      ThreadOp.sleep(1000);
      retry++;
    }
    /* activate */
    SwitchOp.cmd(sw, (iONode)NodeOp.base.clone(swcmd), True, 0, NULL, NULL );
    /* sleep delay */
    ThreadOp.sleep(delay * 1000);

    retry = 0;
    while( !SwitchOp.isSet(sw) && retry < 60) {
      ThreadOp.sleep(1000);
      retry++;
    }
    /* sleep delay */
    SwitchOp.cmd(sw, swcmd, True, 0, NULL, NULL );
    /* sleep delay */
    ThreadOp.sleep(delay * 1000);


  } while( data->testRun );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Test thread for \"%s\" stopped.", data->id );
  data->testThread = NULL;
  ThreadOp.base.del(threadinst);
}


static void __accThread( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOSwitch sw = (iOSwitch)ThreadOp.getParm( th );
  iOSwitchData data = Data(sw);
  int elapsedinterval = 0;
  int elapseddelay = 0;

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Accessory control thread for \"%s\" started.", data->id );
  data->accrun = True;

  do {
    ThreadOp.sleep(1000);

    if( (data->lockedId == NULL || StrOp.len(data->lockedId) == 0) && wAccessoryCtrl.isactive(data->accctrl) && wAccessoryCtrl.getinterval(data->accctrl) > 0 ) {
      if( elapsedinterval >= wAccessoryCtrl.getinterval(data->accctrl) ) {
        Boolean allBlocksFree = True;

        if( StrOp.len( wAccessoryCtrl.getfreeblocks(data->accctrl) ) >= 0 ) {
          iOStrTok tok = StrTokOp.inst( wAccessoryCtrl.getfreeblocks(data->accctrl) , ',' );
          while( StrTokOp.hasMoreTokens(tok) ) {
            const char* blockid = StrTokOp.nextToken( tok );
            iIBlockBase block = ModelOp.getBlock(AppOp.getModel(), blockid);
            if( block != NULL) {
              if( !block->isFree(block, NULL) ) {
                TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "block %s for accessory \"%s\" is not free", blockid, data->id );
                allBlocksFree = False;
                break;
              }
            }
          }
          StrTokOp.base.del(tok);
        }

        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "activating accessory \"%s\"...", data->id );

        /* try to lock the routes */
        const char* routeid = NULL;
        if( allBlocksFree ) {
          iOStrTok tok = StrTokOp.inst( wAccessoryCtrl.getlockroutes(data->accctrl) , ',' );
          Boolean allRouteesLocked = True;
          /* iterate all routes to lock */
          while( StrTokOp.hasMoreTokens(tok) ) {
            const char* routeid = StrTokOp.nextToken( tok );
            iORoute route = ModelOp.getRoute(AppOp.getModel(), routeid);
            if( route != NULL ) {
              if( !RouteOp.lock(route, data->id, False, False) ) {
                TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "could not lock route %s for accessory \"%s\"", routeid, data->id );
                allRouteesLocked = False;
              }
              else {
                TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "route %s locked for accessory \"%s\"", routeid, data->id );
              }
            }
            else {
              TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "route %s does not exist for accessory \"%s\"", routeid, data->id );
            }
          };
          StrTokOp.base.del(tok);

          if( allRouteesLocked ) {
            int retry = 0;
            TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "all routes are locked; activating accessory \"%s\"...", data->id );

            /* activate */
            SwitchOp.red(sw);
            /* sleep delay */
            ThreadOp.sleep(1000);
            /* deactivate: check if sensors are used for on/off position to wait with the off command until the sensor has reported. */
            while( !SwitchOp.isSet(sw) && retry < 60) {
              ThreadOp.sleep(1000);
              retry++;
            }
            /* sleep delay */
            ThreadOp.sleep(wAccessoryCtrl.getdelay(data->accctrl) * 1000);
            SwitchOp.green(sw);


            /* unlock routes */
            iOStrTok tok = StrTokOp.inst( wAccessoryCtrl.getlockroutes(data->accctrl) , ',' );
            /* iterate all routes to lock */
            while( StrTokOp.hasMoreTokens(tok) ) {
              const char* routeid = StrTokOp.nextToken( tok );
              iORoute route = ModelOp.getRoute(AppOp.getModel(), routeid);
              if( route != NULL ) {
                if( !RouteOp.unLock(route, data->id, NULL, False, False) ) {
                  TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "could not unlock route %s for accessory \"%s\"", routeid, data->id );
                }
                else {
                  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "route %s unlocked for accessory \"%s\"", routeid, data->id );
                }
              }
              else {
                TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "route %s does not exist for accessory \"%s\"", routeid, data->id );
              }
            };
            StrTokOp.base.del(tok);


            /* reset interval */
            elapsedinterval = 0;
          }
        }
        else {
          /* random interval */
          elapsedinterval = rand() % wAccessoryCtrl.getinterval(data->accctrl);
        }


      }
      else {
        elapsedinterval++;
      }
    }


  } while( data->run );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Accessory control thread for \"%s\" ended.", data->id );
  data->accrun = False;

  iOThread t = data->accThread;
  data->accThread = NULL;
  ThreadOp.base.del(t);
}


static iOSwitch _inst( iONode props ) {
  iOSwitch     sw   = allocMem( sizeof( struct OSwitch ) );
  iOSwitchData data = allocMem( sizeof( struct OSwitchData ) );

  /* OBase operations */
  MemOp.basecpy( sw, &SwitchOp, 0, sizeof( struct OSwitch ), data );

  data->props = props;
  data->muxLock = MutexOp.inst( NULL, True );
  data->muxCmd  = MutexOp.inst( NULL, True );
  data->id      = wSwitch.getid( props );
  data->accctrl = wSwitch.getaccessoryctrl(props);
  data->listeners = ListOp.inst();
  data->testThread = NULL;


  if( __initCallback( sw ) ) {
    data->fbstate = SW_UNKNOWN;
  }

  __initCTC(sw, False);

  data->addrKey = _createAddrKey(
    wSwitch.getbus( props ),
    wSwitch.getaddr1( props ),
    wSwitch.getport1( props ),
    wSwitch.getporttype( props ),
    wSwitch.getiid( props )
    );

  data->addrKey2 = _createAddrKey(
    wSwitch.getbus( props ),
    wSwitch.getaddr2( props ),
    wSwitch.getport2( props ),
    wSwitch.getporttype( props ),
    wSwitch.getiid( props )
    );

  wSwitch.settesting( data->props, False);
  wSwitch.setwantedstate( data->props, wSwitch.getstate(data->props) );
  NodeOp.removeAttrByName(data->props, "set");

  if( data->accctrl != NULL && wAccessoryCtrl.isactive(data->accctrl) ) {
    data->accThread = ThreadOp.inst( data->id, &__accThread, sw );
    data->run = True;
    ThreadOp.start( data->accThread );
  }

  NodeOp.removeAttrByName(data->props, "cmd");

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "inst[%d] for %s, %s",
        instCnt,
        _getId(sw),
        data->addrKey
        );

  instCnt++;

  return sw;
}

static Boolean _isState( iOSwitch inst, const char* state ) {
  iOSwitchData data = Data(inst);
  return StrOp.equals( state, wSwitch.getstate(data->props) );
}



/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocrail/impl/switch.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
