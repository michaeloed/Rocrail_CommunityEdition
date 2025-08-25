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

#include "rocrail/impl/action_impl.h"
#include "rocrail/public/route.h"
#include "rocrail/public/app.h"
#include "rocrail/public/model.h"
#include "rocrail/public/control.h"
#include "rocrail/public/output.h"
#include "rocrail/public/text.h"
#include "rocrail/public/loc.h"
#include "rocrail/public/fback.h"
#include "rocrail/public/car.h"
#include "rocrail/public/var.h"
#include "rocrail/public/location.h"
#include "rocrail/public/weather.h"
#include "rocrail/public/xmlscript.h"

#include "rocs/public/system.h"
#include "rocs/public/mem.h"
#include "rocs/public/str.h"
#include "rocs/public/strtok.h"

#include "rocrail/wrapper/public/Action.h"
#include "rocrail/wrapper/public/ActionCtrl.h"
#include "rocrail/wrapper/public/ActionCond.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/Schedule.h"
#include "rocrail/wrapper/public/Tour.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/Route.h"
#include "rocrail/wrapper/public/DigInt.h"
#include "rocrail/wrapper/public/AutoCmd.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/FunCmd.h"
#include "rocrail/wrapper/public/Car.h"
#include "rocrail/wrapper/public/Turntable.h"
#include "rocrail/wrapper/public/SelTab.h"
#include "rocrail/wrapper/public/Text.h"
#include "rocrail/wrapper/public/State.h"
#include "rocrail/wrapper/public/Stage.h"
#include "rocrail/wrapper/public/Operator.h"
#include "rocrail/wrapper/public/BinStateCmd.h"
#include "rocrail/wrapper/public/Variable.h"
#include "rocrail/wrapper/public/Location.h"
#include "rocrail/wrapper/public/Weather.h"
#include "rocrail/wrapper/public/Clock.h"
#include "rocrail/wrapper/public/Ctrl.h"
#include "rocrail/wrapper/public/FreeRail.h"
#include "rocrail/wrapper/public/Program.h"

static int instCnt = 0;
static int levelCnt = 0;
static void __doFunction(iOActionData data, iOLoc lc, Boolean fon, int fnaction, int duration);
static void __doCarFunction(iOActionData data, iOCar car, Boolean fon, int fnaction, int duration);
static void __doOperatorFunction(iOActionData data, iOOperator opr, Boolean flip, Boolean fon, const char* desc, int fnaction, int duration);
static void __setFunctionCmd(iOActionData data, iONode cmd, Boolean fon, int fnaction, int duration);

/** ----- OBase ----- */
static void __del( void* inst ) {
  if( inst != NULL ) {
    iOActionData data = Data(inst);
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
  iOActionData data = Data(inst);
  return data->action;
}

static const char* __id( void* inst ) {
  return NULL;
}

static void* __event( void* inst, const void* evt ) {
  return NULL;
}

/** ----- OAction ----- */

static Boolean __checkLocoState(const char* locoid, const char* id, const char* state, iONode actionctrl, iONode actionCond, const char* trainID) {
  iOModel model = AppOp.getModel();
  Boolean automode = ModelOp.isAuto(model);
  iOLoc lc = ModelOp.getLoc(model, locoid, NULL, False);
  Boolean rc = False;

  if( lc != NULL && state[0] == '#' ) {
    iOStrTok tok = StrTokOp.inst(state, ',');
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
        "check if loco address %d fits in [%s]", LocOp.getAddress(lc), state );
    while( StrTokOp.hasMoreTokens(tok) ) {
      const char* sAddr = StrTokOp.nextToken(tok);
      char* sHAddr = StrOp.find( sAddr, "-" );
      if( sHAddr != NULL ) {
        int addr = 0;
        int hAddr = atoi(sHAddr+1);
        *sHAddr = '\0';
        addr = atoi(sAddr+1);
        if( LocOp.getAddress(lc) >= addr && LocOp.getAddress(lc) <= hAddr ) {
          rc = True;
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
              "loco address %d fits in range [%d-%d]", LocOp.getAddress(lc), addr, hAddr );
          break; /* break out the while loop */
        }
      }
      else {
        int addr = atoi(sAddr+1);
        if( addr == LocOp.getAddress(lc) ) {
          rc = True;
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
              "loco address %d equals [%d]", LocOp.getAddress(lc), addr );
          break; /* break out the while loop */
        }
      }
    };
    StrTokOp.base.del(tok);
  }
  else if( lc != NULL && state[0] == 'x' ) {
    iOStrTok tok = StrTokOp.inst(state, ',');
    rc = True;
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
        "check if loco address %d does not match [%s]", LocOp.getAddress(lc), state );
    while( StrTokOp.hasMoreTokens(tok) ) {
      const char* sAddr = StrTokOp.nextToken(tok);
      char* sHAddr = StrOp.find( sAddr, "-" );
      if( sHAddr != NULL ) {
        int addr = 0;
        int hAddr = atoi(sHAddr+1);
        *sHAddr = '\0';
        addr = atoi(sAddr+1);
        if( LocOp.getAddress(lc) >= addr && LocOp.getAddress(lc) <= hAddr ) {
          rc = False;
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
              "loco address %d falls in excluded range [%d-%d]", LocOp.getAddress(lc), addr, hAddr );
          break; /* break out the while loop */
        }
      }
      else {
        int addr = atoi(sAddr+1);
        if( addr == LocOp.getAddress(lc) ) {
          rc = False;
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
              "loco address %d equals exclusion [%d]", LocOp.getAddress(lc), addr );
          break; /* break out the while loop */
        }
      }
    };
    StrTokOp.base.del(tok);
  }

  /* Loco engine */
  else if( lc != NULL && ( StrOp.equals( state, "diesel" ) || StrOp.equals( state, "steam" ) || StrOp.equals( state, "electric" ) ) )
  {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "check engine of loco id [%s]", LocOp.getId(lc) );
    rc = StrOp.equals( state, LocOp.getEngine(lc) );
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
        "loco engine [%s] does %smatch condtion [%s]", LocOp.getEngine(lc), rc?"":"not ", state );
  }

  /* Loco type */
  else if( lc != NULL && ( StrOp.equals(state, "ice") || StrOp.equals(state, "mixed") || StrOp.equals(state, "post") ||
      StrOp.equals(state, "mixed") || StrOp.equals(state, "goods") || StrOp.equals(state, "person") ||
      StrOp.equals(state, "regional") || StrOp.equals(state, "light") || StrOp.equals(state, "lightgoods") ) )
  {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "check type of loco id [%s]", LocOp.getId(lc) );
    rc = StrOp.equals( state, LocOp.getCargo(lc) );
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
        "loco type [%s] does %smatch condtion [%s]", LocOp.getEngine(lc), rc?"":"not ", state );
  }

  /* Loco schedule */
  else if( lc != NULL && ( StrOp.startsWithi( state, "schedule" ) ) ) {
    iOStrTok tok = StrTokOp.inst(state, ':');
    const char* scstate = NULL;
    const char* scid = NULL;
    int scidx = -1;
    if( StrTokOp.hasMoreTokens(tok) )
      scstate = StrTokOp.nextToken(tok);
    if( StrTokOp.hasMoreTokens(tok) )
      scid = StrTokOp.nextToken(tok);
    if( StrTokOp.hasMoreTokens(tok) )
      scidx = atoi(StrTokOp.nextToken(tok));
    rc = False;
    if( scid != NULL ) {
      int lcscidx = 0;
      const char* lcscid = LocOp.getSchedule(lc, &lcscidx);
      if( StrOp.equals(scid, lcscid) && (scidx == -1 || scidx == lcscidx) ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "loco id [%s] is in schedule %s:%d", LocOp.getId(lc), lcscid, lcscidx );
        rc = True;
      }
      else {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
            "loco id [%s] is not in schedule %s(%s):%d(%d)", LocOp.getId(lc), scid, lcscid, scidx, lcscidx );
      }
    }
    StrTokOp.base.del(tok);
  }
  else {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
        "check if loco id [%s] equals [%s]", id, wActionCtrl.getlcid(actionctrl) );
    if( StrOp.equals("*", id ) || StrOp.equals( wActionCtrl.getlcid(actionctrl), id ) ) {
      iOLoc lc = ModelOp.getLoc(model, wActionCtrl.getlcid(actionctrl), NULL, False);
      if( lc != NULL ) {
        Boolean dir = LocOp.getDir(lc);
        Boolean enterside = LocOp.getBlockEnterSide(lc);
        Boolean placing = LocOp.getPlacing(lc);
        if( !placing )
          dir = !dir;
        rc = True;
        if( StrOp.equals( "forwards", wActionCond.getstate(actionCond) ) && !dir ) {
          rc = False;
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
              "loco %s direction %s does not match [%s]", LocOp.getId(lc),
              dir?"forwards":"reverse", wActionCond.getstate(actionCond) );
        }
        else if( StrOp.equals( "reverse", wActionCond.getstate(actionCond) ) && dir ) {
          rc = False;
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
              "loco %s direction %s does not match [%s]", LocOp.getId(lc),
              dir?"forwards":"reverse", wActionCond.getstate(actionCond) );
        }
        else if(StrOp.equals( "+", wActionCond.getstate(actionCond) ) && !enterside ) {
          rc = False;
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
              "loco %s block enter side %s does not match [%s]", LocOp.getId(lc),
              enterside?"+":"-", wActionCond.getstate(actionCond) );
        }
        else if(StrOp.equals( "-", wActionCond.getstate(actionCond) ) && enterside ) {
          rc = False;
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
              "loco %s block enter side %s does not match [%s]", LocOp.getId(lc),
              enterside?"+":"-", wActionCond.getstate(actionCond) );
        }
        else if( StrOp.equals( wActionCond.getstate(actionCond), wLoc.min ) || StrOp.equals( wActionCond.getstate(actionCond), wLoc.mid )
              || StrOp.equals( wActionCond.getstate(actionCond), wLoc.cruise ) || StrOp.equals( wActionCond.getstate(actionCond), wLoc.max ) ) {
          if( !StrOp.equals( wActionCond.getstate(actionCond), LocOp.getV_hint(lc) ) ) {
            rc = False;
            TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                "loco %s speed %s does not match [%s]", LocOp.getId(lc),
                LocOp.getV_hint(lc), wActionCond.getstate(actionCond) );
          } else {
            TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                "loco %s speed %s matches [%s]", LocOp.getId(lc),
                LocOp.getV_hint(lc), wActionCond.getstate(actionCond) );
          }
        }

        else if( StrOp.startsWith( wActionCond.getstate(actionCond), "class" ) && StrOp.len(wActionCond.getstate(actionCond)) > 6) {
          const char* statusStr = wActionCond.getstate(actionCond);
          const char* statusClass = statusStr + 6;
          iOOperator opr = NULL;

          if( trainID != NULL && ModelOp.getOperator( model, trainID) != NULL) {
            opr = ModelOp.getOperator( model, trainID);
            /* Check train first. */
            if( !StrOp.equals(statusClass, OperatorOp.getClass(opr)) && !OperatorOp.hasClass(opr, statusClass) ) {
              rc = False;
              TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                  "train %s class %s does not matches [%s]", trainID,
                  OperatorOp.getClass(opr), statusClass );
            }
            else {
              TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                  "train %s class %s matches [%s]", trainID,
                  OperatorOp.getClass(opr), statusClass );
            }
          }

          else if( !StrOp.equals(statusClass, LocOp.getClass(lc)) && !LocOp.hasClass(lc, statusClass) ) {
            rc = False;
            TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                "loco %s class %s does not matches [%s]", LocOp.getId(lc),
                LocOp.getClass(lc), statusClass );
          }
          else {
            TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                "loco %s class %s matches [%s]", LocOp.getId(lc),
                LocOp.getClass(lc), statusClass );
          }
        }

        else if( StrOp.startsWith( wActionCond.getstate(actionCond), "fon" ) || StrOp.startsWith( wActionCond.getstate(actionCond), "foff" ) ) {
          iOStrTok tok = StrTokOp.inst(wActionCond.getstate(actionCond), ',');
          const char* fonoff = NULL;
          const char* fnumber = NULL;
          if(StrTokOp.hasMoreTokens(tok))
            fonoff = StrTokOp.nextToken(tok);
          if(StrTokOp.hasMoreTokens(tok))
            fnumber = StrTokOp.nextToken(tok);

          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
              "checking function of loco %s", LocOp.getId(lc) );

          if( fonoff != NULL && fnumber != NULL ) {
            int nr = atoi(fnumber);
            int fx = wLoc.getfx(LocOp.base.properties(lc));
            Boolean lights = wLoc.isfn(LocOp.base.properties(lc));
            rc = False;
            if( StrOp.equals( "fon", fonoff ) && nr == 0 )
              rc = lights;
            else if( StrOp.equals( "foff", fonoff ) && nr == 0 )
              rc = !lights;
            else if( StrOp.equals( "fon", fonoff ) && nr != 0 )
              rc = ( fx & (1 << (nr-1)) );
            else if( StrOp.equals( "foff", fonoff ) && nr != 0 )
              rc = ( !(fx & (1 << (nr-1)) ) );

            if( !rc ) {
              TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                  "loco %s function %d does not match state [%s]", LocOp.getId(lc), nr, fonoff );
            }
            else {
              TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                  "loco %s function %d does match state [%s]", LocOp.getId(lc), nr, fonoff );
            }

          }
          else {
            rc = False;
          }
          StrTokOp.base.del(tok);

        }
      }
      else {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
            "loco id [%s] not found", wActionCtrl.getlcid(actionctrl) );
        rc = False;
      }
    }
    else
      rc = StrOp.equals(id, wActionCtrl.getlcid(actionctrl) );
  }

  return rc;
}

static Boolean __checkConditions(struct OAction* inst, iONode actionctrl) {
  iOActionData data = Data(inst);
  iOModel model = AppOp.getModel();
  Boolean automode = ModelOp.isAuto(model);
  Boolean rc = True;
  Boolean oneconditiontrue = False;
  Boolean hasconditions    = False;
  Boolean allconditions    = wActionCtrl.isallconditions(actionctrl);

  if( actionctrl != NULL ) {
    iONode actionCond = wActionCtrl.getactioncond(actionctrl);
    if( (automode && wActionCtrl.isauto(actionctrl)) || (!automode && wActionCtrl.ismanual(actionctrl)) ) {
      while( actionCond != NULL && (rc || !allconditions) ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Action condition: [%s-%s:%s] ",
            wActionCond.gettype(actionCond),
            wActionCond.getid(actionCond),
            wActionCond.getstate(actionCond) );

        hasconditions = True;

        if( !allconditions )
          rc = True;

        /* Block */
        if( StrOp.equals( wBlock.name(), wActionCond.gettype(actionCond) ) ) {
          const char* id = wActionCond.getid( actionCond );
          iIBlockBase bk = ModelOp.getBlock( model, id );
          if( bk != NULL ) {
            rc = bk->isState(bk, wActionCond.getstate(actionCond) );
          }
          else
            TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "block not found [%s]", id );
        }

        /* Text */
        else if( StrOp.equals( wText.name(), wActionCond.gettype(actionCond) ) ) {
          const char* id = wActionCond.getid( actionCond );
          iOText text = ModelOp.getText( model, id);
          if( text != NULL ) {
            rc = StrOp.equals(TextOp.getText(text), wActionCond.getstate(actionCond) );
          }
          else
            TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "text not found [%s]", id );
        }

        /* Variable */
        else if( StrOp.equals( wVariable.name(), wActionCond.gettype(actionCond) ) ) {
          const char* id = wActionCond.getid( actionCond );
          const char* subid = wActionCond.getsubid( actionCond );
          iONode var = NULL;
          if( subid != NULL && StrOp.len(subid) > 0 ) {
            char* key = StrOp.fmt( "%s-%s", id, subid );
            iOMap map = MapOp.inst();
            MapOp.put(map, "lcid", (obj)wActionCtrl.getlcid(actionctrl));
            MapOp.put(map, "lcclass", (obj)wActionCtrl.getlcclass(actionctrl));
            MapOp.put(map, "bkid", (obj)wActionCtrl.getbkid(actionctrl));
            char* resolvedKey = TextOp.replaceAllSubstitutions(key, map);
            StrOp.free(key);
            var = ModelOp.getVariable( model, resolvedKey );
            StrOp.free(resolvedKey);
            MapOp.base.del(map);
          }
          else {
            var = ModelOp.getVariable( model, id );
          }

          if( var != NULL ) {
            const char* state = wActionCond.getstate(actionCond);
            if( StrOp.len(state) > 0 ) {
              iOMap map = MapOp.inst();
              MapOp.put(map, "lcid", (obj)wActionCtrl.getlcid(actionctrl));
              MapOp.put(map, "lcclass", (obj)wActionCtrl.getlcclass(actionctrl));
              MapOp.put(map, "bkid", (obj)wActionCtrl.getbkid(actionctrl));
              int stateVal = VarOp.getValue(state+1, map);
              MapOp.base.del(map);

              if( state[0] == '=' )
                rc = wVariable.getvalue(var) == stateVal;
              else if( state[0] == '>' )
                rc = wVariable.getvalue(var) > stateVal;
              else if( state[0] == '<' )
                rc = wVariable.getvalue(var) < stateVal;
              else if( state[0] == '!' )
                rc = wVariable.getvalue(var) != stateVal;
              /* Text compare */
              else if( state[0] == '#' )
                rc = StrOp.equals(wVariable.gettext(var), state+1);
              else if( state[0] == '?' )
                rc = !StrOp.equals(wVariable.gettext(var), state+1);
            }
          }
          else
            TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "variable not found [%s]", id );
        }


        /* System */
        else if( StrOp.equals( wSysCmd.name(), wActionCond.gettype(actionCond) ) ) {
          iONode state = ControlOp.getState(AppOp.getControl());
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "check system: power=%s", wState.ispower(state)?"go":"stop" );
          if( wState.ispower(state) && !StrOp.equalsi( wSysCmd.go, wActionCond.getstate(actionCond) ) )
            rc = False;
          else if( !wState.ispower(state) && !StrOp.equalsi( wSysCmd.stop, wActionCond.getstate(actionCond) ) )
            rc = False;
          /* clean up */
          NodeOp.base.del(state);
        }

        /* Output */
        else if( StrOp.equals( wOutput.name(), wActionCond.gettype(actionCond) ) ) {
          const char* id = wActionCond.getid( actionCond );
          iOOutput co = ModelOp.getOutput( model, id );
          if( co != NULL ) {
            rc = OutputOp.isState(co, wActionCond.getstate(actionCond) );
          }
          else
            TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "output not found [%s]", id );
        }

        /* Switch */
        else if( StrOp.equals( wSwitch.name(), wActionCond.gettype(actionCond) ) ) {
          const char* id = wActionCond.getid( actionCond );
          iOSwitch sw = ModelOp.getSwitch( model, id );
          if( sw != NULL ) {
            rc = SwitchOp.isState(sw, wActionCond.getstate(actionCond) );
          }
          else
            TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "object not found [%s]", id );
        }
        else if( StrOp.equals( wSignal.name(), wActionCond.gettype(actionCond) ) ) {
          const char* id = wActionCond.getid( actionCond );
          iOSignal sg = ModelOp.getSignal( model, id );
          if( sg != NULL ) {
            iOStrTok tok = StrTokOp.inst(wActionCond.getstate(actionCond), ',');
            while( StrTokOp.hasMoreTokens(tok) ) {
              rc = SignalOp.isState(sg, StrTokOp.nextToken(tok) );
              if( rc )
                break;
            }
            StrTokOp.base.del(tok);
          }
          else
            TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "object not found [%s]", id );
        }

        /* Route */
        else if( StrOp.equals( wRoute.name(), wActionCond.gettype(actionCond) ) ) {
          const char* stid = wActionCtrl.getstid(actionctrl);
          const char* id = wActionCond.getid( actionCond );
          iORoute st = ModelOp.getRoute( model, id );
          if( st != NULL ) {
            const char* state = wActionCond.getstate(actionCond);
            if( RouteOp.isLocked(st) && StrOp.equals(state, "unlocked") ) {
              rc = False;
            }
            else if( !RouteOp.isLocked(st) && StrOp.equals(state, "locked") ) {
              rc = False;
            }
            else if( !RouteOp.isClosed(st) && StrOp.equals(state, "closed") ) {
              rc = False;
            }
            else if( RouteOp.isClosed(st) && StrOp.equals(state, "open") ) {
              rc = False;
            }
            else if( StrOp.equals(state, "=") && !StrOp.equals(id, stid) ) {
              TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "route condition [%s] != [%s]", id, stid );
              rc = False;
            }
          }
        }

        /* Sensor */
        else if( StrOp.equals( wFeedback.name(), wActionCond.gettype(actionCond) ) ) {
          const char* id = wActionCond.getid( actionCond );
          iOLoc lc = ModelOp.getLoc(model, wActionCtrl.getlcid(actionctrl), NULL, False);
          iOFBack fb = ModelOp.getFBack( model, id );
          const char* state = "";
          const char* direction = NULL;

          if( lc == NULL ) {
            lc = ModelOp.getLocByIdent(model, wActionCtrl.getlcid(actionctrl), NULL, NULL, NULL, True);
          }

          iOStrTok tok = StrTokOp.inst(wActionCond.getstate(actionCond), ',');
          if(StrTokOp.hasMoreTokens(tok))
            state = StrTokOp.nextToken(tok);
          if(StrTokOp.hasMoreTokens(tok))
            direction = StrTokOp.nextToken(tok);
          StrTokOp.base.del(tok);

          if( fb != NULL ) {
            if( StrOp.len(state) > 0 && StrOp.equals(state, FBackOp.getIdentifier(fb)) )
              rc = True;
            else
              rc = FBackOp.isState(fb, state );

            if( rc && direction != NULL && lc != NULL ) {
              /**/
              Boolean dir = LocOp.getDir(lc);
              Boolean placing = LocOp.getPlacing(lc);
              if( !placing )
                dir = !dir;
              if( StrOp.equals( "forwards", direction ) && !dir ) {
                rc = False;
                TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                    "loco %s direction %s does not match [%s] dir=%d(%d) placing=%d",
                    LocOp.getId(lc), dir?"forwards":"reverse", direction, dir, LocOp.getDir(lc), placing );
              }
              else if( StrOp.equals( "reverse", direction ) && dir ) {
                rc = False;
                TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                    "loco %s direction %s does not match [%s] dir=%d(%d) placing=%d",
                    LocOp.getId(lc), dir?"forwards":"reverse", direction, dir, LocOp.getDir(lc), placing );
              }
            }
          }
          else
            TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "object not found [%s]", id );
        }

        /* train (operator) */
        else if( StrOp.equals( wOperator.name(), wActionCond.gettype(actionCond) ) ) {
          const char* id = wActionCond.getid( actionCond );
          const char* state = wActionCond.getstate(actionCond);
          iOLoc lc = ModelOp.getLoc(model, wActionCtrl.getlcid(actionctrl), NULL, False);
          iOOperator opr = ModelOp.getOperator( model, id);
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "train ID [%s] match with loco [%s]", id, wActionCtrl.getlcid(actionctrl));

          if( lc != NULL && opr == NULL && StrOp.equals(id, "*") ) {
            const char* train = wLoc.gettrain(LocOp.base.properties(lc));
            if( train != NULL && StrOp.len(train) > 0 ) {
              opr = ModelOp.getOperator( model, train);
            }
          }

          rc = False;
          if( lc != NULL && opr != NULL ) {
            const char* train = wLoc.gettrain(LocOp.base.properties(lc));
            if( train != NULL && (StrOp.equals(train, id) || StrOp.equals(id, "*")) ) {
              TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "train ID [%s] match with loco [%s]", id, LocOp.getId(lc));
              rc = True;
              if( state != NULL && StrOp.len(state) > 0 ) {
                rc = __checkLocoState(LocOp.getId(lc), LocOp.getId(lc), state, actionctrl, actionCond, train);
              }
            }
            else {
              TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "train ID [%s] does not match with loco [%s]-[%s]", id, LocOp.getId(lc), train);
            }
          }
        }

        /* loco */
        else if( StrOp.equals( wLoc.name(), wActionCond.gettype(actionCond) ) ) {
          const char* id = wActionCond.getid( actionCond );
          const char* state = wActionCond.getstate(actionCond);
          rc = __checkLocoState(wActionCtrl.getlcid(actionctrl), id, state, actionctrl, actionCond, NULL);
        }

        /* */
        if( !allconditions && rc ) {
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "One condition is true." );
          if( !wActionCond.ismustbetrue(actionCond) )
            oneconditiontrue = True;
        }
        else if( !allconditions && !rc && wActionCond.ismustbetrue(actionCond) ) {
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "One 'must' condition is not true; Skip action." );
          oneconditiontrue = False;
          break;
        }
        else {
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "%s%s", rc?"Condition is true.":"Condition is not true", allconditions?"; Skip action.":"." );
        }

        actionCond = wActionCtrl.nextactioncond(actionctrl, actionCond);
      }
    }
    else {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "%s%s%s mode action, running in %s mode, skip action %s",
          wActionCtrl.isauto(actionctrl)?"Auto":"",
          wActionCtrl.isauto(actionctrl)&&wActionCtrl.ismanual(actionctrl)?"/":"",
          wActionCtrl.ismanual(actionctrl)?"Manual":"",
          ModelOp.isAuto(model)?"auto":"manual",
          wActionCtrl.getid(actionctrl) );
      rc = False;
    }
  }

  if( hasconditions && !allconditions && !oneconditiontrue ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "No 'or' condition is not true; Skip action." );
    rc = False;
  }

  return (oneconditiontrue | rc);
}


/**  */
static void __executeAction( struct OAction* inst, iONode actionctrl ) {
  iOActionData data = Data(inst);
  iOModel model = AppOp.getModel();

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Action execution %s [%s-%s:%s] ",
      wAction.getid(data->action),
      wAction.gettype(data->action),
      wAction.getoid(data->action),
      wAction.getcmd(data->action) );

  /* output action */
  if( StrOp.equals( wOutput.name(), wAction.gettype( data->action ) ) ) {
    const char* id = wAction.getoid( data->action );
    iOOutput co = ModelOp.getOutput( model, id );
    if( co != NULL ) {
      iONode cmd = NodeOp.inst( wOutput.name(), NULL, ELEMENT_NODE );
      const char* cmdStr = wAction.getcmd( data->action );
      wOutput.setcmd( cmd, cmdStr );
      wOutput.setvalue( cmd, atoi(wAction.getparam(data->action)) );
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "setting output [%s] to [%s] [%d]",
          id, cmdStr, atoi(wAction.getparam(data->action)) );
      OutputOp.cmd( co, cmd, True );
    }
  }

  /* operator action */
  if( StrOp.equals( wOperator.name(), wAction.gettype( data->action ) ) ) {
    const char* id = wAction.getoid( data->action );
    iOOperator op = ModelOp.getOperator( model, id );
    if( op != NULL ) {
      if( StrOp.equals( wAction.loco_class, wAction.getcmd( data->action ) ) ) {
        OperatorOp.setClass(op, wAction.getparam( data->action ));
      }
      else {
        iONode cmd = NodeOp.inst( wOperator.name(), NULL, ELEMENT_NODE );
        const char* cmdStr = wAction.getcmd( data->action );
        wOperator.setcmd( cmd, cmdStr );
        wOperator.setcarids( cmd, wAction.getparam(data->action) );
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "operator[%s], [%s] [%s]",
            id, cmdStr, wAction.getparam(data->action) );
        OperatorOp.cmd( op, cmd );
      }
    }
  }


  /* car action */
  if( StrOp.equals( wCar.name(), wAction.gettype( data->action ) ) ) {
    const char* id = wAction.getoid( data->action );
    iOCar car = ModelOp.getCar( model, id );
    if( car != NULL ) {
      iONode cmd = NodeOp.inst( wCar.name(), NULL, ELEMENT_NODE );
      const char* cmdStr = wAction.getcmd( data->action );
      wCar.setcmd( cmd, cmdStr );
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "car[%s], [%s] [%s]",
          id, cmdStr, wAction.getparam(data->action) );
      CarOp.cmd( car, cmd );
    }
  }


  /* location action */
  if( StrOp.equals( wLocation.name(), wAction.gettype( data->action ) ) ) {
    const char* id = wAction.getoid( data->action );
    iOLocation location = ModelOp.getLocation( model, id );
    if( location != NULL ) {
      iONode cmd = NodeOp.inst( wLocation.name(), NULL, ELEMENT_NODE );
      const char* cmdStr = wAction.getcmd( data->action );
      wLocation.setcmd( cmd, cmdStr );
      wLocation.setvalue( cmd, atoi(wAction.getparam(data->action)) );
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "location[%s], [%s] [%s]",
          id, cmdStr, wAction.getparam(data->action) );
      LocationOp.cmd( location, cmd );
    }
  }


  /* weather action */
  if( StrOp.equals( wWeather.name(), wAction.gettype( data->action ) ) ) {
    const char* id     = wAction.getoid( data->action );
    if( StrOp.equals( wAction.weather_set, wAction.getcmd( data->action ) ) ) {
      iOWeather weather = AppOp.getWeather();
      if( weather != NULL ) {
        wFreeRail.setweatherid(AppOp.getIni(), id);
        WeatherOp.setWeather(weather, id, wAction.getparam(data->action));
        wCtrl.setweather(wFreeRail.getctrl(AppOp.getIni()), StrOp.len(id) > 0 );
      }
    }
    else if( StrOp.equals( wAction.weather_theme, wAction.getcmd( data->action ) ) ) {
      iOWeather weather = AppOp.getWeather();
      if( weather != NULL ) {
        WeatherOp.setTheme(weather, id);
      }
    }
  }


  /* variable action */
  if( StrOp.equals( wVariable.name(), wAction.gettype( data->action ) ) ) {
    const char* id = wAction.getid(data->action);
    const char* oid = wAction.getoid( data->action );
    const char* suboid = wAction.getsuboid( data->action );
    const char* cmdStr = wAction.getcmd( data->action );
    Boolean checkActions = False;
    iONode var = NULL;

    if( suboid != NULL && StrOp.len(suboid) > 0 ) {
      char* key = StrOp.fmt( "%s%s", oid, suboid );
      iOMap map = MapOp.inst();
      MapOp.put(map, "lcid", (obj)wActionCtrl.getlcid(actionctrl));
      MapOp.put(map, "lcclass", (obj)wActionCtrl.getlcclass(actionctrl));
      MapOp.put(map, "bkid", (obj)wActionCtrl.getbkid(actionctrl));
      char* resolvedKey = TextOp.replaceAllSubstitutions(key, map);
      StrOp.free(key);
      var = ModelOp.getVariable( model, resolvedKey );
      if( var == NULL )
        var = ModelOp.addVariable( model, resolvedKey );
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "variable [%s] resolved=[%s]", id, resolvedKey );
      StrOp.free(resolvedKey);
      MapOp.base.del(map);
    }
    else {
      var = ModelOp.getVariable( model, oid );
    }

    if( var != NULL ) {
      int oldval = wVariable.getvalue(var);
      int newval = VarOp.getValue(wAction.getparam(data->action), NULL);
      if( StrOp.equals( wVariable.op_value, wAction.getcmd( data->action ) ) ) {
        wVariable.setvalue(var, newval);
        TraceOp.trc( name, TRCLEVEL_CALC, __LINE__, 9999, "variable [%s] cmd=[%s] param=[%s] new value=%d, old value=%d",
            wVariable.getid(var), cmdStr, wAction.getparam(data->action), wVariable.getvalue(var), oldval );
        checkActions = True;
      }
      else if( StrOp.equals( wVariable.op_add, wAction.getcmd( data->action ) ) ) {
        wVariable.setvalue(var, wVariable.getvalue(var) + newval );
        TraceOp.trc( name, TRCLEVEL_CALC, __LINE__, 9999, "variable [%s] cmd=[%s] param=[%s] new value=%d",
            wVariable.getid(var), cmdStr, wAction.getparam(data->action), wVariable.getvalue(var) );
        checkActions = True;
      }
      else if( StrOp.equals( wVariable.op_subtract, wAction.getcmd( data->action ) ) ) {
        wVariable.setvalue(var, wVariable.getvalue(var) - newval );
        TraceOp.trc( name, TRCLEVEL_CALC, __LINE__, 9999, "variable [%s] cmd=[%s] param=[%s] new value=%d",
            wVariable.getid(var), cmdStr, wAction.getparam(data->action), wVariable.getvalue(var) );
        checkActions = True;
      }
      else if( StrOp.equals( wVariable.op_text, wAction.getcmd( data->action ) ) ) {
        char* newText = VarOp.getText( wAction.getparam(data->action), NULL, ' ');
        wVariable.settext(var, newText);
        StrOp.free(newText);
        TraceOp.trc( name, TRCLEVEL_CALC, __LINE__, 9999, "variable [%s] cmd=[%s] param=[%s] new text=[%s]",
            wVariable.getid(var), cmdStr, wAction.getparam(data->action), wVariable.gettext(var) );
      }
      else if( StrOp.equals( wVariable.op_min, wAction.getcmd( data->action ) ) ) {
        wVariable.setmin(var, newval );
        TraceOp.trc( name, TRCLEVEL_CALC, __LINE__, 9999, "variable [%s] cmd=[%s] param=[%s] new min=%d",
            wVariable.getid(var), cmdStr, wAction.getparam(data->action), wVariable.getmin(var) );
      }
      else if( StrOp.equals( wVariable.op_max, wAction.getcmd( data->action ) ) ) {
        wVariable.setmax(var, newval );
        TraceOp.trc( name, TRCLEVEL_CALC, __LINE__, 9999, "variable [%s] cmd=[%s] param=[%s] new max=%d",
            wVariable.getid(var), cmdStr, wAction.getparam(data->action), wVariable.getmax(var) );
      }
      else if( StrOp.equals( wVariable.op_random, wAction.getcmd( data->action ) ) ) {
        checkActions = VarOp.setRandom(var);
      }
      else if( StrOp.equals( wVariable.op_start, wAction.getcmd( data->action ) ) ) {
        int startval = atoi(wAction.getparam(data->action));
        wVariable.settimer(var, True);
        if( startval != -1 )
          wVariable.setvalue(var, startval);
        TraceOp.trc( name, TRCLEVEL_CALC, __LINE__, 9999, "variable [%s] cmd=[%s] timer started with value %d",
            wVariable.getid(var), cmdStr, wVariable.getvalue(var) );
      }
      else if( StrOp.equals( wVariable.op_stop, wAction.getcmd( data->action ) ) ) {
        wVariable.settimer(var, False);
        TraceOp.trc( name, TRCLEVEL_CALC, __LINE__, 9999, "variable [%s] cmd=[%s] timer stopped with value %d",
            wVariable.getid(var), cmdStr, wVariable.getvalue(var) );
      }

      if( checkActions )
        VarOp.checkActions(var);

      /* Broadcast to clients. */
      {
        iONode node = NodeOp.inst( wVariable.name(), NULL, ELEMENT_NODE );
        wVariable.setid( node, wVariable.getid( var ) );
        wVariable.settext( node, wVariable.gettext( var ) );
        wVariable.setvalue( node, wVariable.getvalue( var ) );
        wVariable.setmin( node, wVariable.getmin( var ) );
        wVariable.setmax( node, wVariable.getmax( var ) );
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "broadcast variable %s [%d, \"%s\"]",
            wVariable.getid(var), wVariable.getvalue(var), wVariable.gettext(var));
        AppOp.broadcastEvent( node );
      }
    }
    else {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "variable [%s%s] not found", oid, suboid );
    }
  }

  /* sound action */
  if( StrOp.equals( wAction.type_sound, wAction.gettype( data->action ) ) ) {
    clntcon_callback pfun = ControlOp.getCallback(AppOp.getControl());
    int addr = wAction.getaddr( data->action );
    int port = wAction.getport( data->action );
    iONode cmd = NULL;

    if( StrOp.equals( wAction.sound_play, wAction.getcmd( data->action ) ) ) {
      cmd = NodeOp.inst( wAction.name(), NULL, ELEMENT_NODE );
      wAction.setcmd( cmd, wAction.getcmd( data->action ) );
      wAction.setiid( cmd, wAction.getiid( data->action ) );
      wAction.setbus( cmd, wAction.getbus( data->action ) );
      wAction.setaddr( cmd, wAction.getaddr( data->action ) );
      wAction.setport( cmd, wAction.getport( data->action ) );
      wAction.setsndfile( cmd, wAction.getparam(data->action) );
      wAction.setsndvolume( cmd, wAction.getsndvolume( data->action ) );
    }
    else {
      cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      wSwitch.setcmd( cmd, wAction.getcmd( data->action ) );
      wSwitch.setiid( cmd, wAction.getiid( data->action ) );
      wSwitch.setbus( cmd, wAction.getbus( data->action ) );
      wSwitch.setaddr1( cmd, wAction.getaddr( data->action ) );
      wSwitch.setport1( cmd, wAction.getport( data->action ) );
    }
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "%s sound [%s]",
        wAction.getcmd( data->action ), wAction.getparam(data->action));
    pfun( (obj)AppOp.getControl(), cmd );
  }

  /* sensor action */
  else if( StrOp.equals( wFeedback.name(), wAction.gettype( data->action ) ) ) {
    const char* id = wAction.getoid( data->action );
    iOFBack fb = ModelOp.getFBack( model, id );
    if( fb != NULL ) {
      iONode cmd = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
      const char* cmdStr = wAction.getcmd( data->action );
      int error = 0;
      wFeedback.setid( cmd, id );
      if( StrOp.equals(wFeedback.reset, cmdStr) ) {
        wFeedback.setcmd( cmd, wFeedback.reset );
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "resetting counter sensor [%s]", id );
        FBackOp.cmd( fb, cmd, True );
      }
      else if( StrOp.equals(wFeedback.setcounterval, cmdStr) ) {
        int counter = FBackOp.getCounter(fb);
        wFeedback.setcmd( cmd, wFeedback.setcounterval );
        if( wAction.getparam(data->action)[0] == '-' || wAction.getparam(data->action)[0] == '+' ) {
          counter += atoi(wAction.getparam(data->action));
        }
        else {
          counter = atoi(wAction.getparam(data->action));
        }
        if( counter < 0 ) {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "negative counter value %d for sensor [%s] is reset to zero", counter, id );
          counter = 0;
        }
        wFeedback.setcounter( cmd, counter );
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "set counter sensor [%s] to %d", id, counter );
        FBackOp.cmd( fb, cmd, True );
      }
      else if( StrOp.equals(wOutput.flip, cmdStr) ) {
        Boolean state = FBackOp.getState(fb);
        wFeedback.setstate( cmd, !state );
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "setting sensor [%s] to [%s]", id, state?"off":"on" );
        FBackOp.event( fb, cmd );
      }
      else {
        wFeedback.setstate( cmd, StrOp.equals(wOutput.on, cmdStr) ? True:False);
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "setting sensor [%s] to [%s]", id, cmdStr );
        FBackOp.event( fb, cmd );
      }
    }
  }

  /* text action */
  else if( StrOp.equals( wText.name(), wAction.gettype( data->action ) ) ) {
    const char* id = wAction.getoid( data->action );
    iOText tx = ModelOp.getText( model, id );
    if( tx != NULL ) {
      iONode cmd = NodeOp.inst( wText.name(), NULL, ELEMENT_NODE );
      const char* cmdStr = wAction.getcmd( data->action );
      wText.setcmd( cmd, cmdStr );
      wText.setformat(cmd, wAction.getparam(data->action));
      wText.setreflcid(cmd, wActionCtrl.getlcid(actionctrl));
      wText.setrefbkid(cmd, wActionCtrl.getbkid(actionctrl));
      wText.setcounter(cmd, wActionCtrl.getcounter(actionctrl));
      wText.setcarcount(cmd, wActionCtrl.getcarcount(actionctrl));
      wText.setcountedcars(cmd, wActionCtrl.getcountedcars(actionctrl));
      wText.setwheelcount(cmd, wActionCtrl.getwheelcount(actionctrl));
      wText.setmvspeed(cmd, wActionCtrl.getmvspeed(actionctrl));
      wText.setload(cmd, wActionCtrl.getload(actionctrl));
      wText.setvolt(cmd, wActionCtrl.getvolt(actionctrl));
      wText.settemp(cmd, wActionCtrl.gettemp(actionctrl));
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "setting text [%s] to [%s] lcid=[%s]", id, cmdStr, wActionCtrl.getlcid(actionctrl) );
      TextOp.base.event( tx, cmd );
    }
  }

  /* ext action */
  else if( StrOp.equals( "ext", wAction.gettype( data->action ) ) ) {
    /* check for a external action */
    const char* extaction = wAction.getcmd( data->action );
    const char* extparam  = wAction.getparam( data->action );
    const char* quote = "";

    if(wAction.isdoublequote(data->action) && SystemOp.isWindows()) {
      quote = "\"";
    }

    if( extaction != NULL && StrOp.len(extaction) > 0 ) {
      if( StrOp.endsWithi(extaction, ".txt") ) {
        /* cmd recording */
        if( FileOp.exist(extaction) ) {
          int size = FileOp.fileSize(extaction);
          char* record = allocMem( size + 1);
          iOFile f = FileOp.inst( extaction, OPEN_READONLY);
          if( f != NULL ) {
            FileOp.read( f, record, size);
            FileOp.base.del(f);
            TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "play record file [%s], size=%d", extaction, size );
            AppOp.play( record );
            freeMem(record);
          }
        }
        else {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "record file [%s] not found", extaction );
        }
      }
      else if( StrOp.endsWithi(extaction, ".xml") ) {
        /* xmlscript */
        if( FileOp.exist(extaction) ) {
          int size = FileOp.fileSize(extaction);
          char* xmlscript = allocMem( size + 1);
          iOFile f = FileOp.inst( extaction, OPEN_READONLY);
          if( f != NULL ) {
            FileOp.read( f, xmlscript, size);
            FileOp.base.del(f);
            TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "run xmlscript file [%s], size=%d", extaction, size );
            iOMap map = MapOp.inst();
            MapOp.put(map, "lcid", (obj)wActionCtrl.getlcid(actionctrl));
            MapOp.put(map, "lcclass", (obj)wActionCtrl.getlcclass(actionctrl));
            MapOp.put(map, "bkid", (obj)wActionCtrl.getbkid(actionctrl));
            XmlScriptOp.run( xmlscript, map );
            freeMem(xmlscript);
            MapOp.base.del(map);
          }
        }
        else {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "xmlscript file [%s] not found", extaction );
        }
      }
      else if( wActionCtrl.getparam(actionctrl) != NULL && StrOp.len(wActionCtrl.getparam(actionctrl)) > 0 ) {
        char* s = NULL;
        if( extparam != NULL && StrOp.len(extparam) > 0 ) {
          s = StrOp.fmt("%s\"%s\" %s %s%s", quote, extaction, extparam, wActionCtrl.getparam(actionctrl), quote );
        }
        else {
          s = StrOp.fmt("%s\"%s\" %s%s", quote, extaction, wActionCtrl.getparam(actionctrl), quote );
        }
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "executing [%s]", s );
        SystemOp.system( s, True, False );
        StrOp.free(s);
      }
      else {
        char* s = NULL;
        if( extparam != NULL && StrOp.len(extparam) > 0 )
          s = StrOp.fmt("%s\"%s\" %s%s", quote, extaction, extparam, quote );
        else
          s = StrOp.fmt("\"%s\"", extaction );
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "executing [%s]", s );
        SystemOp.system( s, True, False );
        StrOp.free(s);
      }
    }
  }

  /* switch action */
  else if( StrOp.equals( wSwitch.name(), wAction.gettype( data->action ) ) ) {
    iOSwitch sw = ModelOp.getSwitch( model, wAction.getoid( data->action ) );
    int error = 0;
    if( sw != NULL ) {
      iONode cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      if( StrOp.equals( wAction.getcmd( data->action ), wAction.switch_flip )) {
        if( SwitchOp.isState(sw, wSwitch.turnout )) {
          wSwitch.setcmd( cmd, wSwitch.straight );
        } else {
          wSwitch.setcmd( cmd, wSwitch.turnout );
        }
        SwitchOp.cmd( sw, cmd, True, 0, &error, NULL );
      } else {
        wSwitch.setcmd( cmd, wAction.getcmd( data->action ) );
        wSwitch.setforcecmd( cmd,  StrOp.equals( wAction.getparam( data->action ), "force" ));
        SwitchOp.cmd( sw, cmd, True, 0, &error, NULL );
      }
    }
  }

  /* signal action */
  else if( StrOp.equals( wSignal.name(), wAction.gettype( data->action ) ) ) {
    iOSignal sg = ModelOp.getSignal( model, wAction.getoid( data->action ) );
    if( sg != NULL ) {
      int error = 0;
      iONode cmd = NodeOp.inst( wSignal.name(), NULL, ELEMENT_NODE );
      wSignal.setcmd( cmd, wAction.getcmd( data->action ) );
      wSignal.setaspect( cmd, atoi(wAction.getparam( data->action )) );
      SignalOp.cmd( sg, cmd, True );
    }
  }

  /* block action */
  else if( StrOp.equals( wBlock.name(), wAction.gettype( data->action ) ) ) {
    iIBlockBase bl = ModelOp.getBlock( model, wAction.getoid( data->action ) );
    if( bl != NULL ) {
      if( StrOp.equals( wAction.block_class, wAction.getcmd( data->action ) ) ) {
        bl->setClass(bl, wAction.getparam( data->action ));
      }
      else if( StrOp.equals( wAction.block_unlock, wAction.getcmd( data->action ) ) ) {
        bl->unLock(bl, wAction.getparam( data->action ), NULL);
      }
      else if( StrOp.equals( wAction.block_event, wAction.getcmd( data->action ) ) ) {
        bl->event(bl, True, wAction.getparam( data->action ), NULL, NULL, NULL, NULL, 0, 0, NULL, True);
        bl->event(bl, False, wAction.getparam( data->action ), NULL, NULL, NULL, NULL, 0, 0, NULL, True);
      }
      else if( StrOp.equals( wBlock.closed, wAction.getcmd( data->action ) ) ) {
        iONode cmd = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
        wBlock.setstate( cmd, wBlock.closed );
        bl->cmd(bl, cmd);
      }
      else if( StrOp.equals( wBlock.open, wAction.getcmd( data->action ) ) ) {
        iONode cmd = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
        wBlock.setstate( cmd, wBlock.open );
        bl->cmd(bl, cmd);
      }
      else if( StrOp.equals( wSignal.white, wAction.getcmd( data->action ) ) ) {
        bl->white(bl, False, False);
      }
      else if( StrOp.equals( wSignal.yellow, wAction.getcmd( data->action ) ) ) {
        bl->yellow(bl, False, False);
      }
      else if( StrOp.equals( wSignal.green, wAction.getcmd( data->action ) ) ) {
        bl->green(bl, False, False);
      }
      else if( StrOp.equals( wSignal.red, wAction.getcmd( data->action ) ) ) {
        bl->red(bl, False, False);
      }
      else if( StrOp.equals( wAction.block_schedule, wAction.getcmd( data->action ) ) ) {
        bl->setLocSchedule(bl, wAction.getparam( data->action ), False);
      }
      else if( StrOp.equals( wAction.block_schedule_manual, wAction.getcmd( data->action ) ) ) {
        bl->setLocSchedule(bl, wAction.getparam( data->action ), True);
      }
      else if( StrOp.equals( wTour.name(), wAction.getcmd( data->action ) ) ) {
        bl->setLocTour(bl, wAction.getparam( data->action ), False);
      }
      else if( StrOp.equals( wAction.block_acceptident, wAction.getcmd( data->action ) ) ) {
        bl->acceptIdent(bl, True);
      }
      else if( StrOp.equals( wAction.block_setloc, wAction.getcmd( data->action ) ) ) {
        iOLoc lc = ModelOp.getLoc( model, wAction.getparam( data->action ), NULL, False);
        if( lc != NULL ) {
          iONode cmd = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
          wBlock.setlocid(cmd, "");
          bl->cmd(bl, cmd);
          cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
          wLoc.setid( cmd, wAction.getparam( data->action ) );
          wLoc.setcmd( cmd, wLoc.block );
          wLoc.setblockid( cmd, wAction.getoid( data->action ) );
          LocOp.cmd(lc, cmd);
        }
      }
      else if( StrOp.equals( wAction.loco_go, wAction.getcmd( data->action ) ) ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "action: loco_go %s ", bl->getLoc(bl));

        iOLoc lc = ModelOp.getLoc( model, bl->getLoc(bl), NULL, False);
        if( lc != NULL ) {
          iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
          wLoc.setid( cmd, bl->getLoc(bl) );
          wLoc.setcmd( cmd, wLoc.go );
          LocOp.cmd(lc, cmd);
        }

      }
      else if( StrOp.equals(wLoc.dispatch, wAction.getcmd(data->action) ) ) {
        iOLoc lc = ModelOp.getLoc( model, bl->getLoc(bl), NULL, False);
        if( lc != NULL ) {
          LocOp.dispatch(lc);
        }
      }
      else if( StrOp.equals(wAction.block_reserve, wAction.getcmd(data->action) ) ) {
        bl = ModelOp.getBlock( model, wAction.getoid( data->action ) );
        if( bl != NULL ) {
          bl->lock( bl, wActionCtrl.getlcid(actionctrl), NULL, NULL, False, False, False, 0, NULL, True);
        }
      }
    }
  }

  /* stageblock action */
  else if( StrOp.equals( wStage.name(), wAction.gettype( data->action ) ) ) {
    iIBlockBase bl = ModelOp.getBlock( model, wAction.getoid( data->action ) );
    if( bl != NULL ) {
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "stageblock: cmd %s",
          wAction.getcmd( data->action ) );
      if( StrOp.equals( wAction.block_unlock, wAction.getcmd( data->action ) ) ) {
        bl->unLock(bl, wAction.getparam( data->action ), NULL);
      }
      else if( StrOp.equals( wStage.closed, wAction.getcmd( data->action ) ) ) {
        iONode cmd = NodeOp.inst( wStage.name(), NULL, ELEMENT_NODE );
        wStage.setstate( cmd, wStage.closed );
        bl->cmd(bl, cmd);
      }
      else if( StrOp.equals( wStage.open, wAction.getcmd( data->action ) ) ) {
        iONode cmd = NodeOp.inst( wStage.name(), NULL, ELEMENT_NODE );
        wStage.setstate( cmd, wStage.open );
        bl->cmd(bl, cmd);
      }
      else if( StrOp.equals( wStage.exitclosed, wAction.getcmd( data->action ) ) ) {
        iONode cmd = NodeOp.inst( wStage.name(), NULL, ELEMENT_NODE );
        wStage.setexitstate( cmd, wStage.closed );
        bl->cmd(bl, cmd);
      }
      else if( StrOp.equals( wStage.exitopen, wAction.getcmd( data->action ) ) ) {
        iONode cmd = NodeOp.inst( wStage.name(), NULL, ELEMENT_NODE );
        wStage.setexitstate( cmd, wStage.open );
        bl->cmd(bl, cmd);
      }
      else if( StrOp.equals( wSignal.white, wAction.getcmd( data->action ) ) ) {
        bl->white(bl, False, False);
      }
      else if( StrOp.equals( wSignal.yellow, wAction.getcmd( data->action ) ) ) {
        bl->yellow(bl, False, False);
      }
      else if( StrOp.equals( wSignal.green, wAction.getcmd( data->action ) ) ) {
        bl->green(bl, False, False);
      }
      else if( StrOp.equals( wSignal.red, wAction.getcmd( data->action ) ) ) {
        bl->red(bl, False, False);
      }
      else if( StrOp.equals( wStage.compress, wAction.getcmd( data->action ) ) ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "stageblock: actoion COMPRESS");
        iONode cmd = NodeOp.inst( wStage.name(), NULL, ELEMENT_NODE );
        wStage.setcmd( cmd, wStage.compress );
        bl->cmd(bl, cmd);
      }
      else {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "stageblock: unsupported cmd: %s",
            wAction.getcmd( data->action ) );
      }
    }
  }

  /* route action */
  else if( StrOp.equals( wRoute.name(), wAction.gettype( data->action ) ) ) {
    iORoute st = ModelOp.getRoute( model, wAction.getoid( data->action ) );
    if( st != NULL ) {
      if( StrOp.equals( wAction.block_class, wAction.getcmd( data->action ) ) ) {
        RouteOp.setClass(st, wAction.getparam( data->action ));
      }
      else if( StrOp.equals( wAction.route_set, wAction.getcmd( data->action ) ) ) {
        RouteOp.go( st );
      }
      else if( StrOp.equals( wAction.route_lockset, wAction.getcmd( data->action ) ) ) {
        const char* lockid = ModelOp.getResolvedRouteID(model, wAction.getparam(data->action) );
        if( lockid == NULL || StrOp.len( lockid ) == 0 )
          lockid = wAction.getid( data->action );
        if( RouteOp.lock(st, lockid, False, True) )
          RouteOp.go( st );
      }
      else if( StrOp.equals( wAction.route_lock, wAction.getcmd( data->action ) ) ) {
        const char* lockid = ModelOp.getResolvedRouteID(model, wAction.getparam(data->action) );
        if( lockid == NULL || StrOp.len( lockid ) == 0 )
          lockid = wAction.getid( data->action );
        RouteOp.lock(st, lockid, False, True);
      }
      else if( StrOp.equals( wAction.route_unlock, wAction.getcmd( data->action ) ) ) {
        const char* lockid = ModelOp.getResolvedRouteID(model, wAction.getparam(data->action) );
        if( lockid == NULL || StrOp.len( lockid ) == 0 )
          lockid = wAction.getid( data->action );
        RouteOp.unLock(st, lockid, NULL, True, False);
      }
      else if( StrOp.equals( wBlock.closed, wAction.getcmd( data->action ) ) ) {
        iONode cmd = NodeOp.inst( wRoute.name(), NULL, ELEMENT_NODE );
        wBlock.setstate( cmd, wBlock.closed );
        RouteOp.cmd(st, cmd);
      }
      else if( StrOp.equals( wBlock.open, wAction.getcmd( data->action ) ) ) {
        iONode cmd = NodeOp.inst( wRoute.name(), NULL, ELEMENT_NODE );
        wBlock.setstate( cmd, wBlock.open );
        RouteOp.cmd(st, cmd);
      }
      else {
        RouteOp.go( st );
      }
    }
  }

  /* turntable action */
  else if( StrOp.equals( wTurntable.name(), wAction.gettype( data->action ) ) ) {
    iOTT tt = ModelOp.getTurntable( model, wAction.getoid( data->action ) );
    if( tt != NULL ) {
      iONode cmd = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
      if( StrOp.equals( wAction.tt_goto, wAction.getcmd( data->action ) ) )
        wTurntable.setcmd( cmd, wAction.getparam(data->action) );
      else if( StrOp.equals( wAction.fun_on, wAction.getcmd( data->action ) ) ) {
        wTurntable.setcmd( cmd, wAction.fun_on );
        wTurntable.setfun( cmd, atoi(wAction.getparam(data->action)) );
      }
      else if( StrOp.equals( wAction.fun_off, wAction.getcmd( data->action ) ) ) {
        wTurntable.setcmd( cmd, wAction.fun_off );
        wTurntable.setfun( cmd, atoi(wAction.getparam(data->action)) );
      }
      else
        wTurntable.setcmd( cmd, wAction.getcmd( data->action ) );
      TTOp.cmd( (iIBlockBase)tt, cmd );
    }
  }

  /* fiddle yard action */
  else if( StrOp.equals( wSelTab.name(), wAction.gettype( data->action ) ) ) {
    iOSelTab fy = ModelOp.getSelectiontable( model, wAction.getoid( data->action ) );
    if( fy != NULL ) {
      iONode cmd = NodeOp.inst( wSelTab.name(), NULL, ELEMENT_NODE );
      wSelTab.setcmd( cmd, wAction.getparam(data->action) );
      SelTabOp.cmd( (iIBlockBase)fy, cmd );
    }
  }


  /* clock action */
  else if( StrOp.equals( wClock.name(), wAction.gettype( data->action ) ) ) {
    long ltime = time(NULL);
    struct tm* ltm = localtime( &ltime );
    int div  = 0;
    int hour = 0;
    int min  = 0;
    iOStrTok tok = StrTokOp.inst(wAction.getparam(data->action), ',');
    if( StrTokOp.hasMoreTokens(tok) )
      div = atoi(StrTokOp.nextToken(tok));
    if( StrTokOp.hasMoreTokens(tok) )
      hour = atoi(StrTokOp.nextToken(tok));
    if( StrTokOp.hasMoreTokens(tok) )
      min = atoi(StrTokOp.nextToken(tok));
    StrTokOp.base.del(tok);

    ltm->tm_hour = hour;
    ltm->tm_min  = min;
    ltm->tm_sec  = 0;
    ltime = mktime(ltm);

    {
      clntcon_callback pfun = ControlOp.getCallback(AppOp.getControl());
      iONode cmd = NodeOp.inst( wClock.name(), NULL, ELEMENT_NODE );
      wClock.setdivider( cmd, div );
      wClock.settime( cmd, ltime );
      pfun( (obj)AppOp.getControl(), cmd );
    }
  }


  /* system action */
  else if( StrOp.equals( wSysCmd.name(), wAction.gettype( data->action ) ) ) {
    int error = 0;
    if( StrOp.equals( wSysCmd.stoplocs, wAction.getcmd( data->action ) ) ) {
      /* re-map syscmd stoplocs to autocmd stop: */
      clntcon_callback pfun = ControlOp.getCallback(AppOp.getControl());
      iONode cmd = NodeOp.inst( wAutoCmd.name(), NULL, ELEMENT_NODE );
      wAutoCmd.setcmd( cmd, wAutoCmd.stop );
      pfun( (obj)AppOp.getControl(), cmd );
    }
    else if( StrOp.equals( wAutoCmd.resume, wAction.getcmd( data->action ) ) ) {
      clntcon_callback pfun = ControlOp.getCallback(AppOp.getControl());
      iONode cmd = NodeOp.inst( wAutoCmd.name(), NULL, ELEMENT_NODE );
      wAutoCmd.setcmd( cmd, wAutoCmd.resume );
      pfun( (obj)AppOp.getControl(), cmd );
    }
    else if( StrOp.equals( wAutoCmd.v0locos, wAction.getcmd( data->action ) ) ) {
      clntcon_callback pfun = ControlOp.getCallback(AppOp.getControl());
      iONode cmd = NodeOp.inst( wAutoCmd.name(), NULL, ELEMENT_NODE );
      wAutoCmd.setcmd( cmd, wAutoCmd.v0locos );
      pfun( (obj)AppOp.getControl(), cmd );
    }
    else if( StrOp.equals( wAutoCmd.vrestorelocos, wAction.getcmd( data->action ) ) ) {
      clntcon_callback pfun = ControlOp.getCallback(AppOp.getControl());
      iONode cmd = NodeOp.inst( wAutoCmd.name(), NULL, ELEMENT_NODE );
      wAutoCmd.setcmd( cmd, wAutoCmd.vrestorelocos );
      pfun( (obj)AppOp.getControl(), cmd );
    }
    else if( StrOp.equals( wAutoCmd.on, wAction.getcmd( data->action ) ) ) {
      clntcon_callback pfun = ControlOp.getCallback(AppOp.getControl());
      iONode cmd = NodeOp.inst( wAutoCmd.name(), NULL, ELEMENT_NODE );
      wAutoCmd.setcmd( cmd, wAutoCmd.on );
      pfun( (obj)AppOp.getControl(), cmd );
    }
    else if( StrOp.equals( wAutoCmd.off, wAction.getcmd( data->action ) ) ) {
      clntcon_callback pfun = ControlOp.getCallback(AppOp.getControl());
      iONode cmd = NodeOp.inst( wAutoCmd.name(), NULL, ELEMENT_NODE );
      wAutoCmd.setcmd( cmd, wAutoCmd.off );
      pfun( (obj)AppOp.getControl(), cmd );
    }
    else if( StrOp.equals( wModelCmd.initfield, wAction.getcmd( data->action ) ) ) {
      clntcon_callback pfun = ControlOp.getCallback(AppOp.getControl());
      iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
      wModelCmd.setcmd( cmd, wModelCmd.initfield );
      pfun( (obj)AppOp.getControl(), cmd );
    }
    else {
      iONode cmd = NodeOp.inst( wSysCmd.name(), NULL, ELEMENT_NODE );
      wSysCmd.setcmd( cmd, wAction.getcmd( data->action ) );
      wSysCmd.setvalA( cmd, atoi(wAction.getparam(data->action)) );
      ControlOp.cmd( AppOp.getControl(), cmd, &error );
    }
  }

  /* check for a locomotive action */
  else if( StrOp.equals( wLoc.name(), wAction.gettype( data->action ) ) ) {
    if( StrOp.equals( wAction.loco_x_go, wAction.getcmd( data->action ) ) ) {
      char* locos = VarOp.getText(wAction.getparam(data->action), NULL, ',');
      iOStrTok tok = StrTokOp.inst(locos, ',');
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "x-go: [%s]->[%s]", wAction.getparam(data->action), locos );

      while( StrTokOp.hasMoreTokens(tok) ) {
        const char* id = StrTokOp.nextToken(tok);
        iOLoc lc = ModelOp.getLoc( model, id, NULL, False);
        if( lc == NULL && atoi(id) > 0 )
          lc = ModelOp.getLocByAddress( model, atoi(id), NULL);
        if( lc != NULL ) {
          LocOp.go(lc);
        }
        else {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "x-go: no loco found by id/address [%s]", id );
        }
      }
      StrTokOp.base.del(tok);
      StrOp.free(locos);
    }
    else {
      int addr = VarOp.getValue(wAction.getparam(data->action), NULL);
      iOLoc lc = ModelOp.getLoc( model, wAction.getoid( data->action ), NULL, False);

      if( lc == NULL && wActionCtrl.getlcid(actionctrl) != NULL) {
        lc = ModelOp.getLoc( model, wActionCtrl.getlcid(actionctrl), NULL, False );
        if( lc != NULL )
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "found loco [%s] by ID", LocOp.getId(lc) );
      }

      if( lc == NULL && addr > 0 ) {
        lc = ModelOp.getLocByAddress( model, addr, NULL);
        if( lc != NULL )
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "found loco [%s] by variable address %d", LocOp.getId(lc), addr );
      }

      if( lc != NULL ) {
        if( StrOp.equals( wLoc.pomwrite, wAction.getcmd( data->action ) ) ) {
          iONode props = LocOp.base.properties(lc);
          iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
          iOStrTok tok = StrTokOp.inst(wAction.getparam(data->action), ',');
          int cv  = 0;
          int val = 0;
          if( StrTokOp.hasMoreTokens(tok) )
            cv = atoi(StrTokOp.nextToken(tok));
          if( StrTokOp.hasMoreTokens(tok) )
            val = atoi(StrTokOp.nextToken(tok));
          StrTokOp.base.del(tok);

          wProgram.setcmd( cmd, wProgram.set );
          wProgram.setiid( cmd, wLoc.getiid(props) );
          wProgram.setaddr( cmd, wLoc.getaddr(props) );
          wProgram.setlongaddr( cmd, (wLoc.getaddr(props) > 127) ? True:False );
          wProgram.setdecaddr( cmd, wLoc.getaddr(props) );
          wProgram.setcv( cmd, cv );
          wProgram.setvalue( cmd, val );
          wProgram.setpom( cmd, True );
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "write pom for loco [%s] %d=%d", LocOp.getId(lc), cv, val );
          ControlOp.cmd( AppOp.getControl(), cmd, NULL );
        }
        else if( StrOp.equals( wAction.loco_class, wAction.getcmd( data->action ) ) ) {
          LocOp.setClass(lc, wAction.getparam( data->action ));
        }
        else if( StrOp.equals(wLoc.consist, wAction.getcmd(data->action) ) ) {
          iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE);
          wLoc.setcmd(cmd, wLoc.consist);
          wLoc.setconsist(cmd, wAction.getparam(data->action));
          LocOp.cmd(lc, cmd);
          ModelOp.initMasterLocMap(model);
        }
        else if( StrOp.equals(wLoc.go, wAction.getcmd(data->action) ) ) {
          if( wAction.getparam(data->action) != NULL && StrOp.len( wAction.getparam(data->action) ) > 0 ) {
            const char* destname = wAction.getparam(data->action);
            char* varval = NULL;
            iOMap map = MapOp.inst();
            MapOp.put(map, "lcid", (obj)LocOp.getId(lc));
            MapOp.put(map, "lcclass", (obj)wActionCtrl.getlcclass(actionctrl));
            MapOp.put(map, "bkid", (obj)wActionCtrl.getbkid(actionctrl));
            varval = VarOp.getText(wAction.getparam(data->action), map, '-');
            MapOp.base.del(map);

            if( varval != NULL ) {
              destname = varval;
              TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "loco [%s] goto (%s)=[%s]", LocOp.getId(lc), wAction.getparam(data->action), destname);
            }

            iONode tour = ModelOp.getTour(model, destname);
            iONode schedule = ModelOp.getSchedule(model, destname);
            iIBlockBase block = ModelOp.getBlock(model, destname);
            iOLocation location = ModelOp.getLocation(model, destname);
            TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "loco [%s] goto [%s] tour=%X schedule=%X block=%X location=%X",
                LocOp.getId(lc), destname, tour, schedule, block, location );

            if( varval != NULL ) {
              StrOp.free(varval);
            }

            if( tour != NULL ) {
              LocOp.useTour( lc, destname);
            }
            else if( schedule != NULL ) {
              LocOp.useSchedule( lc, destname);
            }
            else if( block != NULL ) {
              LocOp.gotoBlock(lc, destname);
            }
            else if( location != NULL ) {
              LocOp.gotoBlock(lc, destname);
            }

          }
          LocOp.go(lc);
        }
        else if( StrOp.equals(wAction.loco_carcount, wAction.getcmd(data->action) ) ) {
          LocOp.setCarCount(lc, atoi(wAction.getparam(data->action)));
        }
        else if( StrOp.equals(wLoc.assigntrain, wAction.getcmd(data->action) ) ) {
          iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE);
          wLoc.setcmd( cmd, wLoc.assigntrain );
          wLoc.settrain( cmd, wAction.getparam(data->action) );
          LocOp.cmd(lc, cmd);
        }
        else if( StrOp.equals(wLoc.releasetrain, wAction.getcmd(data->action) ) ) {
          iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE);
          wLoc.setcmd( cmd, wLoc.releasetrain );
          LocOp.cmd(lc, cmd);
        }
        else if( StrOp.equals(wLoc.stop, wAction.getcmd(data->action) ) ) {
          LocOp.stop(lc, False);
        }
        else if( StrOp.equals(wAction.loco_velocity, wAction.getcmd(data->action) ) ) {
          int v = atoi(wAction.getparam(data->action));
          iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE);
          if( v<0 || wAction.getparam(data->action)[0] == '-' ) {
              wLoc.setdir( cmd, !LocOp.getDir( lc ) );
              v = abs( v );
          }
          wLoc.setV( cmd, v );
          LocOp.cmd(lc, cmd);
        }
        else if( StrOp.equals(wAction.loco_velocity2, wAction.getcmd(data->action) ) ) {
          int v = atoi(wAction.getparam(data->action));
          iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE);
          if( v<0 || wAction.getparam(data->action)[0] == '-' ) {
              wLoc.setdir( cmd, !LocOp.getDir( lc ) );
              v = abs( v );
          }
          wLoc.setusesecaddr( cmd, True );
          wLoc.setV( cmd, v );
          LocOp.cmd(lc, cmd);
        }
        else if( StrOp.equals(wAction.loco_binstate_on, wAction.getcmd(data->action) ) || StrOp.equals(wAction.loco_binstate_off, wAction.getcmd(data->action) ) ) {
          int nr = atoi(wAction.getparam(data->action));
          iONode cmd = NodeOp.inst( wBinStateCmd.name(), NULL, ELEMENT_NODE);
          wBinStateCmd.setnr( cmd, nr );
          wBinStateCmd.setdata( cmd, StrOp.equals(wAction.loco_binstate_on, wAction.getcmd(data->action) )?1:0 );
          wBinStateCmd.settimer( cmd, wAction.getactiontime(data->action) );
          LocOp.cmd(lc, cmd);
        }
        else if( StrOp.equals(wAction.loco_percent, wAction.getcmd(data->action) ) ) {
          int v = atoi(wAction.getparam(data->action));
          iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE);
          if( v<0 || wAction.getparam(data->action)[0] == '-' ) {
              wLoc.setdir( cmd, !LocOp.getDir( lc ) );
              v = abs( v );
          }
          v = v * LocOp.getV( lc ) /100;
          wLoc.setV( cmd, v );
          LocOp.cmd(lc, cmd);
        }
        else if( StrOp.equals(wLoc.min, wAction.getcmd(data->action) )    || StrOp.equals(wLoc.mid, wAction.getcmd(data->action) ) ||
                 StrOp.equals(wLoc.cruise, wAction.getcmd(data->action) ) || StrOp.equals(wLoc.max, wAction.getcmd(data->action) )) {
          iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE);
          wLoc.setV_hint( cmd, wAction.getcmd(data->action) );
          wLoc.setdir( cmd, LocOp.getDir(lc) );
          LocOp.cmd(lc, cmd);
        }
        else if( StrOp.equals(wLoc.dispatch, wAction.getcmd(data->action) ) ) {
          LocOp.dispatch(lc);
        }
        else if( StrOp.equals(wLoc.swap, wAction.getcmd(data->action) ) ) {
          iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE);
          wLoc.setcmd( cmd, wLoc.swap );
          LocOp.cmd(lc, cmd);
        }
        else if( StrOp.equals(wLoc.blockside, wAction.getcmd(data->action) ) ) {
          iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE);
          wLoc.setcmd( cmd, wLoc.blockside );
          LocOp.cmd(lc, cmd);
        }
        else if( StrOp.equals(wLoc.setmanualmode, wAction.getcmd(data->action) ) ) {
          iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE);
          wLoc.setcmd( cmd, wLoc.setmanualmode );
          LocOp.cmd(lc, cmd);
        }
        else if( StrOp.equals(wLoc.resetmanualmode, wAction.getcmd(data->action) ) ) {
          iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE);
          wLoc.setcmd( cmd, wLoc.resetmanualmode );
          LocOp.cmd(lc, cmd);
        }
      }
    }
  }

  /* check for a function command */
  else if( StrOp.equals( wFunCmd.name(), wAction.gettype( data->action ) ) ) {
    iOLoc lc = ModelOp.getLoc( model, wAction.getoid( data->action ), NULL, False);
    Boolean fon = StrOp.equals( "on", wAction.getcmd( data->action ) );
    Boolean random = StrOp.startsWith(wAction.getparam(data->action), "?");
    int duration = wActionCtrl.getduration(actionctrl);
    iOStrTok tok = StrTokOp.inst(wAction.getparam(data->action)+(random?1:0), ',');
    int fncnt = StrTokOp.countTokens(tok);
    int fnpick = 0;
    int fnidx = 0;

    if( random && fncnt > 1 ) {
      int randNumber = rand();
      fnpick = randNumber % fncnt;
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "random function index %d of %d", fnpick, fncnt);
    }

    if( lc == NULL && wActionCtrl.getlcid(actionctrl) != NULL) {
      lc = ModelOp.getLoc( model, wActionCtrl.getlcid(actionctrl), NULL, False );
    }

    if( lc != NULL ) {
      while( StrTokOp.hasMoreTokens(tok) ) {
        int fnaction = LocOp.getFnNrByDesc(lc, StrTokOp.nextToken(tok));
        if( fnaction != -1 )
          if( !random || fnpick == fnidx )
            __doFunction(data, lc, fon, fnaction, duration);
        fnidx++;
      }
    }
    else {
      iOCar car = ModelOp.getCar( model, wAction.getoid( data->action ));
      if( car != NULL ) {
        while( StrTokOp.hasMoreTokens(tok) ) {
          int fnaction = CarOp.getFnNrByDesc(car, StrTokOp.nextToken(tok));
          if( fnaction != -1 )
            if( !random || fnpick == fnidx )
              __doCarFunction(data, car, fon, fnaction, duration);
          fnidx++;
        }
      }
      else {
        iOOperator opr = ModelOp.getOperator( model, wAction.getoid( data->action ));
        if( opr != NULL ) {
          while( StrTokOp.hasMoreTokens(tok) ) {
            const char* fndesc = StrTokOp.nextToken(tok);
            int fnaction = atoi(fndesc);
            if( !random || fnpick == fnidx )
              __doOperatorFunction(data, opr, StrOp.equals( wOutput.flip, wAction.getcmd( data->action ) ), fon, fndesc, fnaction, duration);
            fnidx++;
          }
        }
      }
    }
    StrTokOp.base.del(tok);
  }

}


static void __setFunctionCmd(iOActionData data, iONode cmd, Boolean fon, int fnaction, int duration) {
  if( StrOp.equals( wOutput.flip, wAction.getcmd( data->action ) ) ) {
    wFunCmd.setf0 ( cmd, fnaction== 0?!wFunCmd.isf0 ( cmd ):wFunCmd.isf0 ( cmd ) );
    wFunCmd.setf1 ( cmd, fnaction== 1?!wFunCmd.isf1 ( cmd ):wFunCmd.isf1 ( cmd ) );
    wFunCmd.setf2 ( cmd, fnaction== 2?!wFunCmd.isf2 ( cmd ):wFunCmd.isf2 ( cmd ) );
    wFunCmd.setf3 ( cmd, fnaction== 3?!wFunCmd.isf3 ( cmd ):wFunCmd.isf3 ( cmd ) );
    wFunCmd.setf4 ( cmd, fnaction== 4?!wFunCmd.isf4 ( cmd ):wFunCmd.isf4 ( cmd ) );
    wFunCmd.setf5 ( cmd, fnaction== 5?!wFunCmd.isf5 ( cmd ):wFunCmd.isf5 ( cmd ) );
    wFunCmd.setf6 ( cmd, fnaction== 6?!wFunCmd.isf6 ( cmd ):wFunCmd.isf6 ( cmd ) );
    wFunCmd.setf7 ( cmd, fnaction== 7?!wFunCmd.isf7 ( cmd ):wFunCmd.isf7 ( cmd ) );
    wFunCmd.setf8 ( cmd, fnaction== 8?!wFunCmd.isf8 ( cmd ):wFunCmd.isf8 ( cmd ) );
    wFunCmd.setf9 ( cmd, fnaction== 9?!wFunCmd.isf9 ( cmd ):wFunCmd.isf9 ( cmd ) );
    wFunCmd.setf10( cmd, fnaction==10?!wFunCmd.isf10( cmd ):wFunCmd.isf10( cmd ) );
    wFunCmd.setf11( cmd, fnaction==11?!wFunCmd.isf11( cmd ):wFunCmd.isf11( cmd ) );
    wFunCmd.setf12( cmd, fnaction==12?!wFunCmd.isf12( cmd ):wFunCmd.isf12( cmd ) );
    wFunCmd.setf13( cmd, fnaction==13?!wFunCmd.isf13( cmd ):wFunCmd.isf13( cmd ) );
    wFunCmd.setf14( cmd, fnaction==14?!wFunCmd.isf14( cmd ):wFunCmd.isf14( cmd ) );
    wFunCmd.setf15( cmd, fnaction==15?!wFunCmd.isf15( cmd ):wFunCmd.isf15( cmd ) );
    wFunCmd.setf16( cmd, fnaction==16?!wFunCmd.isf16( cmd ):wFunCmd.isf16( cmd ) );
    wFunCmd.setf17( cmd, fnaction==17?!wFunCmd.isf17( cmd ):wFunCmd.isf17( cmd ) );
    wFunCmd.setf18( cmd, fnaction==18?!wFunCmd.isf18( cmd ):wFunCmd.isf18( cmd ) );
    wFunCmd.setf19( cmd, fnaction==19?!wFunCmd.isf19( cmd ):wFunCmd.isf19( cmd ) );
    wFunCmd.setf20( cmd, fnaction==20?!wFunCmd.isf20( cmd ):wFunCmd.isf20( cmd ) );
    wFunCmd.setf21( cmd, fnaction==21?!wFunCmd.isf21( cmd ):wFunCmd.isf21( cmd ) );
    wFunCmd.setf22( cmd, fnaction==22?!wFunCmd.isf22( cmd ):wFunCmd.isf22( cmd ) );
    wFunCmd.setf23( cmd, fnaction==23?!wFunCmd.isf23( cmd ):wFunCmd.isf23( cmd ) );
    wFunCmd.setf24( cmd, fnaction==24?!wFunCmd.isf24( cmd ):wFunCmd.isf24( cmd ) );
    wFunCmd.setf25( cmd, fnaction==25?!wFunCmd.isf25( cmd ):wFunCmd.isf25( cmd ) );
    wFunCmd.setf26( cmd, fnaction==26?!wFunCmd.isf26( cmd ):wFunCmd.isf26( cmd ) );
    wFunCmd.setf27( cmd, fnaction==27?!wFunCmd.isf27( cmd ):wFunCmd.isf27( cmd ) );
    wFunCmd.setf28( cmd, fnaction==28?!wFunCmd.isf28( cmd ):wFunCmd.isf28( cmd ) );
  } else {
    wFunCmd.setf0 ( cmd, fnaction== 0?fon:wFunCmd.isf0 ( cmd ) );
    wFunCmd.setf1 ( cmd, fnaction== 1?fon:wFunCmd.isf1 ( cmd ) );
    wFunCmd.setf2 ( cmd, fnaction== 2?fon:wFunCmd.isf2 ( cmd ) );
    wFunCmd.setf3 ( cmd, fnaction== 3?fon:wFunCmd.isf3 ( cmd ) );
    wFunCmd.setf4 ( cmd, fnaction== 4?fon:wFunCmd.isf4 ( cmd ) );
    wFunCmd.setf5 ( cmd, fnaction== 5?fon:wFunCmd.isf5 ( cmd ) );
    wFunCmd.setf6 ( cmd, fnaction== 6?fon:wFunCmd.isf6 ( cmd ) );
    wFunCmd.setf7 ( cmd, fnaction== 7?fon:wFunCmd.isf7 ( cmd ) );
    wFunCmd.setf8 ( cmd, fnaction== 8?fon:wFunCmd.isf8 ( cmd ) );
    wFunCmd.setf9 ( cmd, fnaction== 9?fon:wFunCmd.isf9 ( cmd ) );
    wFunCmd.setf10( cmd, fnaction==10?fon:wFunCmd.isf10( cmd ) );
    wFunCmd.setf11( cmd, fnaction==11?fon:wFunCmd.isf11( cmd ) );
    wFunCmd.setf12( cmd, fnaction==12?fon:wFunCmd.isf12( cmd ) );
    wFunCmd.setf13( cmd, fnaction==13?fon:wFunCmd.isf13( cmd ) );
    wFunCmd.setf14( cmd, fnaction==14?fon:wFunCmd.isf14( cmd ) );
    wFunCmd.setf15( cmd, fnaction==15?fon:wFunCmd.isf15( cmd ) );
    wFunCmd.setf16( cmd, fnaction==16?fon:wFunCmd.isf16( cmd ) );
    wFunCmd.setf17( cmd, fnaction==17?fon:wFunCmd.isf17( cmd ) );
    wFunCmd.setf18( cmd, fnaction==18?fon:wFunCmd.isf18( cmd ) );
    wFunCmd.setf19( cmd, fnaction==19?fon:wFunCmd.isf19( cmd ) );
    wFunCmd.setf20( cmd, fnaction==20?fon:wFunCmd.isf20( cmd ) );
    wFunCmd.setf21( cmd, fnaction==21?fon:wFunCmd.isf21( cmd ) );
    wFunCmd.setf22( cmd, fnaction==22?fon:wFunCmd.isf22( cmd ) );
    wFunCmd.setf23( cmd, fnaction==23?fon:wFunCmd.isf23( cmd ) );
    wFunCmd.setf24( cmd, fnaction==24?fon:wFunCmd.isf24( cmd ) );
    wFunCmd.setf25( cmd, fnaction==25?fon:wFunCmd.isf25( cmd ) );
    wFunCmd.setf26( cmd, fnaction==26?fon:wFunCmd.isf26( cmd ) );
    wFunCmd.setf27( cmd, fnaction==27?fon:wFunCmd.isf27( cmd ) );
    wFunCmd.setf28( cmd, fnaction==28?fon:wFunCmd.isf28( cmd ) );
  }

  wFunCmd.setfnchanged( cmd, fnaction );
  wFunCmd.settimedfn( cmd, fon?fnaction:-1 );
  wFunCmd.setgroup( cmd, fnaction/4 + ((fnaction%4 > 0) ? 1:0) );
  if( fon ) {
    if( duration > 0 )
      wFunCmd.settimer( cmd, duration );
    else
      wFunCmd.settimer( cmd, wAction.getactiontime(data->action) );
  }
}


static void __doOperatorFunction(iOActionData data, iOOperator opr, Boolean flip, Boolean fon, const char* desc, int fnaction, int duration) {

  if( !OperatorOp.setFnByDesc( opr, desc, flip, fon, duration) ) {
    iONode cmd = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "operator function [%d] %s", fnaction, fon?"ON":"OFF" );
    wFunCmd.setid( cmd, wAction.getid( data->action ) );
    __setFunctionCmd(data, cmd, fon, fnaction, duration);
    OperatorOp.cmd( opr, cmd);
  }
}

static void __doCarFunction(iOActionData data, iOCar car, Boolean fon, int fnaction, int duration) {
  iONode cmd = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "car function [%d] %s", fnaction, fon?"ON":"OFF" );
  wFunCmd.setid( cmd, wAction.getid( data->action ) );
  CarOp.getFunctionStatus(car, cmd);

  __setFunctionCmd(data, cmd, fon, fnaction, duration);

  CarOp.cmd( car, cmd);
}


static void __doFunction(iOActionData data, iOLoc lc, Boolean fon, int fnaction, int duration) {
  iONode cmd = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "loco function [%d] %s", fnaction, fon?"ON":"OFF" );
  wFunCmd.setid( cmd, wAction.getid( data->action ) );
  LocOp.getFunctionStatus(lc, cmd);

  __setFunctionCmd(data, cmd, fon, fnaction, duration);

  LocOp.cmd( lc, cmd);

}

static void __timerThread( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOAction action = (iOAction)ThreadOp.getParm( th );
  iOActionData data = Data(action);

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "action timer started %s [%dms] ",
      wAction.getid(data->action), wAction.gettimer(data->action) );

  if( data->timer > 0 )
    ThreadOp.sleep(data->timer);
  else
    ThreadOp.sleep(wAction.gettimer(data->action));

  data->timerthread = NULL;
  __executeAction( action, data->actionctrl );
  ThreadOp.base.del(th);
}


static Boolean _cmd( iOAction inst, iONode cmd ) {
  iOActionData data = Data(inst);
  Boolean ok = False;
  const char* cmdStr = wAction.getcmd( cmd );

  if( StrOp.equals( wAction.test, cmdStr ) ) {
    iONode actionctrl = NodeOp.inst(wActionCtrl.name(), NULL, ELEMENT_NODE);
    __executeAction( inst, actionctrl );
    NodeOp.base.del(actionctrl);
 }

  /* Cleanup Node1 */
  NodeOp.base.del(cmd);
  return ok;
}


static void _exec( struct OAction* inst, iONode actionctrl ) {
  iOActionData data = Data(inst);
  iOModel model = AppOp.getModel();

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Action %s [%s-%s:%s] ",
      wAction.getid(data->action),
      wAction.gettype(data->action),
      wAction.getoid(data->action),
      wAction.getcmd(data->action) );

  if( levelCnt > 9 ) {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "nested action level 10 detected" );
    return;
  }

  levelCnt++;

  if( !__checkConditions(inst, actionctrl) ) {
    levelCnt--;
    return;
  }

  if( wAction.istimed(data->action) && wAction.isevery(data->action) && actionctrl != NULL) {
    data->enabled = StrOp.equals( wOutput.on, wActionCtrl.getstate(actionctrl) );
    if( !data->enabled ) {
      /* check if its a time */
      const char* l_State = wActionCtrl.getstate(actionctrl);
      if( StrOp.len(l_State) == 5 && l_State[2] == ':' )
        data->enabled = True;
    }
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "%s the timed every action=%s state=%s", data->enabled?"enable":"disable", wAction.getid(data->action), wActionCtrl.getstate(actionctrl) );
    levelCnt--;
    return;
  }

  if( wActionCtrl.gettimer(actionctrl) > 0 )
    data->timer = wActionCtrl.gettimer(actionctrl);
  else
    data->timer = 0;

  if( wAction.gettimer(data->action) == 0 && data->timer == 0 ) {
    __executeAction( inst, actionctrl );
  }
  else {
    if( data->timerthread == NULL ) {
      /* start the timer thread */
      data->actionctrl = actionctrl;
      data->timerthread = ThreadOp.inst( NULL, &__timerThread, inst );
      ThreadOp.start( data->timerthread );
    }
    else {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "action timer for [%s] is already active.", wAction.getid(data->action) );
    }
  }
  levelCnt--;
}

static void _tick( iOAction inst, int seconds ) {
  iOActionData data = Data(inst);
  iOControl control = AppOp.getControl();
  long l_time = ControlOp.getTime(control);
  struct tm* lTime = localtime( &l_time );

  data->ticker += seconds; /* scale seconds */

  if( wAction.istimed(data->action) ) {
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
        "action [%s] random=%d every=%d enabled=%d action=%d:%02d.%02d local=%d:%02d.%02d ticker=%d randomsecs=%d",
        wAction.getid(data->action), wAction.israndom(data->action), wAction.isevery(data->action), data->enabled,
        wAction.gethour(data->action), wAction.getmin(data->action), wAction.getsec(data->action),
        lTime->tm_hour, lTime->tm_min, lTime->tm_sec, data->ticker, data->randomsecs);

    if( wAction.israndom(data->action) ) {
      if( data->randomsecs <= data->ticker ) {
        _exec( inst, NULL );

        int secs = wAction.gethour(data->action) * 60 * 60 + wAction.getmin(data->action) * 60 + wAction.getsec(data->action);
        if( secs < 1 ) secs = 1;
        data->randomsecs = rand() % secs;
        if( data->randomsecs < 1 )
          data->randomsecs = 1;
        data->ticker = 0;
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "action timer [%s] random scale seconds=%d.",
            wAction.getid(data->action), data->randomsecs );
      }
    }

    else if( wAction.isevery(data->action) && (data->enabled || wAction.isactivated(data->action) ) ) {
      int actsecs = wAction.gethour(data->action) * 60 * 60 + wAction.getmin(data->action) * 60 + wAction.getsec(data->action);
      int secs = lTime->tm_hour * 60 * 60 + lTime->tm_min * 60 + lTime->tm_sec;
      if( secs < data->lastactsec ) {
        data->lastactsec = 86400 - data->lastactsec;
      }
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "action every timer [%s] actionsecs=%d scale seconds=%d lastactsec=%d.",
          wAction.getid(data->action), actsecs, secs, data->lastactsec);
      if( (secs - data->lastactsec) >= actsecs ) {
        data->lastactsec = secs;
        _exec( inst, NULL );
      }
    }

    else if( lTime->tm_hour == wAction.gethour(data->action) && lTime->tm_min == wAction.getmin(data->action) ) {
      if( seconds > 1 ) {
        /* ignore the seconds */
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "action timer [%s] %d:%02d",
            wAction.getid(data->action), wAction.gethour(data->action), wAction.getmin(data->action) );
        _exec( inst, NULL );
      }
      else if(  lTime->tm_sec == wAction.getsec(data->action) ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "action timer [%s] %d:%02d.%02d",
            wAction.getid(data->action), wAction.gethour(data->action), wAction.getmin(data->action), wAction.getsec(data->action) );
        _exec( inst, NULL );
      }
    }
  }

}



static void _modify( iOAction inst, iONode props ) {
  iOActionData data = Data(inst);
  NodeOp.mergeNode( data->action, props, True, True, False );
}


/**  */
static struct OAction* _inst( iONode ini ) {
  iOAction __Action = allocMem( sizeof( struct OAction ) );
  iOActionData data = allocMem( sizeof( struct OActionData ) );
  MemOp.basecpy( __Action, &ActionOp, 0, sizeof( struct OAction ), data );

  /* Initialize data->xxx members... */
  data->action = ini;

  if( wAction.israndom(data->action) ) {
    int secs = wAction.gethour(data->action) * 60 * 60 + wAction.getmin(data->action) * 60 + wAction.getsec(data->action);
    if( secs < 1 ) secs = 1;
    data->randomsecs = rand() % secs;
    if( data->randomsecs < 1 )
      data->randomsecs = 1;
    data->ticker = 0;
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "action timer [%s] random scale seconds=%d.",
        wAction.getid(data->action), data->randomsecs );
  }
  else {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "action timer [%s] %02d:%02d.%02d",
        wAction.getid(data->action), wAction.gethour(data->action), wAction.getmin(data->action), wAction.getsec(data->action) );
  }

  instCnt++;
  return __Action;
}


/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocrail/impl/action.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
