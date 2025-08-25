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

#include "rocrail/impl/xmlscript_impl.h"

#include "rocrail/public/app.h"
#include "rocrail/public/control.h"
#include "rocrail/public/model.h"
#include "rocrail/public/text.h"
#include "rocrail/public/var.h"
#include "rocrail/public/loc.h"
#include "rocrail/public/signal.h"
#include "rocrail/public/switch.h"
#include "rocrail/public/text.h"
#include "rocrail/public/fback.h"
#include "rocrail/public/switch.h"
#include "rocrail/public/signal.h"
#include "rocrail/public/route.h"
#include "rocrail/public/output.h"
#include "rocrail/public/action.h"
#include "rocrail/public/operator.h"
#include "rocrail/public/car.h"

#include "rocrail/wrapper/public/Item.h"
#include "rocrail/wrapper/public/FunCmd.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/Variable.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/Text.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/Route.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/Global.h"
#include "rocrail/wrapper/public/Action.h"
#include "rocrail/wrapper/public/ActionCtrl.h"
#include "rocrail/wrapper/public/Operator.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/Car.h"


#include "rocs/public/mem.h"
#include "rocs/public/trace.h"
#include "rocs/public/node.h"
#include "rocs/public/strtok.h"
#include "rocs/public/system.h"

static int instCnt = 0;

static Boolean __doIf(iONode nodeScript, iOMap map);
static Boolean __doForEach(iONode nodeScript, iOMap map);



/** ----- OBase ----- */
static void __del( void* inst ) {
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

/** ----- OXmlScript ----- */

/* class="bk b21 = AB"  */
static Boolean __isClass(const char* classRes) {
  Boolean ok = True;

  const char* objType    = NULL;
  const char* objId      = NULL;
  const char* comparator = NULL;
  const char* value      = NULL;
  iOStrTok tok = StrTokOp.inst(classRes, ' ');

  if( StrTokOp.hasMoreTokens(tok) ) {
    objType = StrTokOp.nextToken(tok);
  }
  if( StrTokOp.hasMoreTokens(tok) ) {
    objId = StrTokOp.nextToken(tok);
  }
  if( StrTokOp.hasMoreTokens(tok) ) {
    comparator = StrTokOp.nextToken(tok);
  }
  if( StrTokOp.hasMoreTokens(tok) ) {
    value = StrTokOp.nextToken(tok);
  }

  if( objType != NULL && objId != NULL && comparator != NULL && value != NULL ) {
    iOModel model = AppOp.getModel();
    ok = False;

    /* block */
    if( StrOp.equals(wBlock.name(), objType) ) {
      iIBlockBase bk = ModelOp.getBlock(model, objId);
      if( bk != NULL ) {
        if( comparator[0] == '=' && bk->hasClass(bk, value) ) {
          ok = True;
        }
      }
    }

    /* loco */
    else if( StrOp.equals(wLoc.name(), objType) ) {
      iOLoc lc = ModelOp.getLoc(model, objId, NULL, False);
      if( lc != NULL ) {
        if( comparator[0] == '=' && LocOp.hasClass(lc, value) ) {
          ok = True;
        }
      }
    }

  }

  return ok;
}


/* state="sg sem3 = green"  */
static Boolean __isState(const char* stateRes) {
  Boolean ok = True;
  const char* objType    = NULL;
  const char* objId      = NULL;
  const char* comparator = NULL;
  const char* value      = NULL;
  iOStrTok tok = StrTokOp.inst(stateRes, ' ');

  if( StrTokOp.hasMoreTokens(tok) ) {
    objType = StrTokOp.nextToken(tok);
  }
  if( StrTokOp.hasMoreTokens(tok) ) {
    objId = StrTokOp.nextToken(tok);
  }
  if( StrTokOp.hasMoreTokens(tok) ) {
    comparator = StrTokOp.nextToken(tok);
  }
  if( StrTokOp.hasMoreTokens(tok) ) {
    value = StrTokOp.nextToken(tok);
  }

  if( objType != NULL && objId != NULL && comparator != NULL && value != NULL ) {
    iOModel model = AppOp.getModel();
    ok = False;
    /* signal */
    if( StrOp.equals(wSignal.name(), objType) ) {
      iOSignal sg = ModelOp.getSignal(model, objId);
      if( sg != NULL ) {
        if( comparator[0] == '=' && SignalOp.isState(sg, value) ) {
          ok = True;
        }
      }
    }

    /* switch */
    else if( StrOp.equals(wSwitch.name(), objType) ) {
      iOSwitch sw = ModelOp.getSwitch(model, objId);
      if( sw != NULL ) {
        if( comparator[0] == '=' && SwitchOp.isState(sw, value) ) {
          ok = True;
        }
      }
    }

    /* sensor */
    else if( StrOp.equals(wFeedback.name(), objType) ) {
      iOFBack fb = ModelOp.getFBack(model, objId);
      if( fb != NULL ) {
        if( comparator[0] == '=' && FBackOp.isState(fb, value) ) {
          ok = True;
        }
      }
    }

    /* output */
    else if( StrOp.equals(wOutput.name(), objType) ) {
      iOOutput co = ModelOp.getOutput(model, objId);
      if( co != NULL ) {
        if( comparator[0] == '=' && OutputOp.isState(co, value) ) {
          ok = True;
        }
      }
    }

    /* block */
    else if( StrOp.equals(wBlock.name(), objType) ) {
      iIBlockBase bk = ModelOp.getBlock(model, objId);
      if( bk != NULL ) {
        if( comparator[0] == '=' && bk->isState(bk, value) ) {
          ok = True;
        }
      }
    }

    /* route */
    else if( StrOp.equals(wRoute.name(), objType) ) {
      iORoute st = ModelOp.getRoute(model, objId);
      if( st != NULL ) {
        if( comparator[0] == '=' && RouteOp.isState(st, value) ) {
          ok = True;
        }
      }
    }

  }

  StrTokOp.base.del(tok);

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "state [%s] is %s", stateRes, ok?"true":"false" );
  return ok;
}


static Boolean __isSubCondition(const char* conditionRes) {
  Boolean ok = True;
  /* ToDo: Check the condition.
   * "#var2%oid% < &time" */
  const char* var  = NULL;
  const char* comparator = NULL;
  const char* value = NULL;

  iOStrTok tok = StrTokOp.inst(conditionRes, ' ');

  if( StrTokOp.hasMoreTokens(tok) ) {
    var = StrTokOp.nextToken(tok);
  }
  if( StrTokOp.hasMoreTokens(tok) ) {
    comparator = StrTokOp.nextToken(tok);
  }
  if( StrTokOp.hasMoreTokens(tok) ) {
    value = StrTokOp.nextToken(tok);
  }

  if( var != NULL && comparator != NULL && value != NULL ) {
    int varValue   = VarOp.getValue(var, NULL);
    int valueValue = VarOp.getValue(value, NULL);
    if( comparator[0] == '<' ) {
      if( varValue >= valueValue )
        ok = False;
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "condition [%s] is %s: %d < %d", conditionRes, ok?"true":"false", varValue, valueValue );
    }
    else if( comparator[0] == '>' ) {
      if( varValue <= valueValue )
        ok = False;
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "condition [%s] is %s: %d > %d", conditionRes, ok?"true":"false", varValue, valueValue );
    }
    else if( comparator[0] == '=' ) {
      if( var[0] == '@' ) {
        char* varText   = VarOp.getText(var, NULL, ' ');
        char* valueText = VarOp.getText(value, NULL, ' ');
        ok = StrOp.equals(varText, valueText);
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "condition [%s] is %s: %s == %s", conditionRes, ok?"true":"false", varText, valueText );
        StrOp.free(varText);
        StrOp.free(valueText);
      }
      else {
        if( varValue != valueValue )
          ok = False;
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "condition [%s] is %s: %d == %d", conditionRes, ok?"true":"false", varValue, valueValue );
      }
    }
    else if( comparator[0] == '#' ) {
      if( StrOp.find(var, ",") != NULL || StrOp.find(value, ",") != NULL ) {
        iOStrTok tokVar = StrTokOp.inst(var, ',');
        ok = False;
        while( StrTokOp.hasMoreTokens(tokVar) && !ok) {
          const char* v = StrTokOp.nextToken(tokVar);
          ok = StrOp.find(v, value) != NULL ? True:False;
        }
        StrTokOp.base.del(tokVar);
      }
      else if( !StrOp.equals(var, value) )
        ok = False;
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "condition [%s] is %s: %s == %s", conditionRes, ok?"true":"false", var, value );
    }
  }

  StrTokOp.base.del(tok);

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "condition [%s] is %s", conditionRes, ok?"true":"false" );
  return ok;
}


static Boolean __isCondition(const char* conditionRes, Boolean alltrue) {
  Boolean ok = False;
  iOStrTok tok = StrTokOp.inst(conditionRes, '|');
  while(StrTokOp.hasMoreTokens(tok)) {
    const char* condition = StrTokOp.nextToken(tok);
    Boolean isTrue = __isSubCondition(condition);
    if( isTrue )
      ok = True;
    else if( alltrue ) {
      ok = False;
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "not all conditions are true [%s]", conditionRes );
      break;
    }
  }
  StrTokOp.base.del(tok);
  return ok;
}


static Boolean __executeCmd(iONode cmd, iOMap map, const char* oid, Boolean* breakloop) {
  Boolean exit = False;
  iOModel model = AppOp.getModel();
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "execute [%s] id[%s] oid[%s]", NodeOp.getName(cmd), wItem.getid(cmd), oid!=NULL?oid:"" );

  /* loco */
  if( StrOp.equals( wFunCmd.name(), NodeOp.getName(cmd)) || StrOp.equals( wLoc.name(), NodeOp.getName(cmd)) || StrOp.equals( wCar.name(), NodeOp.getName(cmd)) ) {
    char* idRes = VarOp.getText(wItem.getid(cmd), map, ' ');
    iOLoc lc    = ModelOp.getLoc(model, idRes, NULL, False);
    iOCar car   = ModelOp.getCar(model, idRes);
    iIBlockBase bk = NULL;
    if( lc == NULL && (bk = ModelOp.getBlock(model, wItem.getid(cmd))) != NULL ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "get loco id from block [%s]", wItem.getid(cmd) );
      lc = ModelOp.getLoc(model, bk->getLoc(bk), NULL, False);
    }
    if( lc == NULL && NodeOp.getStr(cmd, "bkid", NULL) != NULL ) {
      char* bkidRes = VarOp.getText(NodeOp.getStr(cmd, "bkid", NULL), map, ' ');
      bk = ModelOp.getBlock(model, bkidRes);
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "get loco id from block [%s]", bkidRes );
      lc = ModelOp.getLoc(model, bk->getLoc(bk), NULL, False);
      StrOp.free(bkidRes);
    }
    if( lc != NULL ) {
      iONode clone = (iONode)NodeOp.base.clone(cmd);
      wLoc.setid(clone, LocOp.getId(lc));

      if( wLoc.getblockid(clone) != NULL && StrOp.len(wLoc.getblockid(clone)) > 0 ) {
        char* bkidRes = VarOp.getText(wLoc.getblockid(clone), map, ' ');
        wLoc.setblockid(clone, bkidRes);
        StrOp.free(bkidRes);
      }
      if( wLoc.getscheduleid(clone) != NULL && StrOp.len(wLoc.getscheduleid(clone)) > 0 ) {
        char* scidRes = VarOp.getText(wLoc.getscheduleid(clone), map, ' ');
        wLoc.setscheduleid(clone, scidRes);
        StrOp.free(scidRes);
      }
      LocOp.cmd(lc, clone);
    }
    if( car != NULL ) {
      iONode clone = (iONode)NodeOp.base.clone(cmd);
      wCar.setid(clone, wCar.getid(CarOp.base.properties(car)));
      CarOp.cmd(car, clone);
    }
    StrOp.free(idRes);
  }

  /* operator */
  else if( StrOp.equals( wOperator.name(), NodeOp.getName(cmd)) ) {
    char* idRes = VarOp.getText(wItem.getid(cmd), map, ' ');
    iOOperator op = ModelOp.getOperator(model, idRes);
    if( op != NULL ) {
      OperatorOp.cmd(op, (iONode)NodeOp.base.clone(cmd));
    }
    StrOp.free(idRes);
  }

  /* block */
  else if( StrOp.equals( wBlock.name(), NodeOp.getName(cmd)) ) {
    char* idRes = VarOp.getText(wItem.getid(cmd), map, ' ');
    iIBlockBase bk = ModelOp.getBlock(model, idRes);
    if( bk != NULL ) {
      if( StrOp.equals(wAction.block_reserve, wBlock.getcmd(cmd) ) ) {
        char* lcidRes = VarOp.getText(wActionCtrl.getlcid(cmd), map, ' ');
        bk->lock( bk, lcidRes, NULL, NULL, False, False, False, 0, NULL, True);
        StrOp.free(lcidRes);
      }
      else {
        bk->cmd(bk, (iONode)NodeOp.base.clone(cmd));
      }
    }
    StrOp.free(idRes);
  }

  /* switch */
  else if( StrOp.equals( wSwitch.name(), NodeOp.getName(cmd)) ) {
    char* idRes = VarOp.getText(wItem.getid(cmd), map, ' ');
    iOSwitch sw = ModelOp.getSwitch(model, idRes);
    if( sw != NULL ) {
      SwitchOp.cmd(sw, (iONode)NodeOp.base.clone(cmd), True, 0, NULL, NULL);
    }
    StrOp.free(idRes);
  }

  /* signal */
  else if( StrOp.equals( wSignal.name(), NodeOp.getName(cmd)) ) {
    char* idRes = VarOp.getText(wItem.getid(cmd), map, ' ');
    iOSignal sg = ModelOp.getSignal(model, idRes);
    if( sg != NULL ) {
      SignalOp.cmd(sg, (iONode)NodeOp.base.clone(cmd), True);
    }
    StrOp.free(idRes);
  }

  /* route */
  else if( StrOp.equals( wRoute.name(), NodeOp.getName(cmd)) ) {
    char* idRes = VarOp.getText(wItem.getid(cmd), map, ' ');
    iORoute st = ModelOp.getRoute(model, idRes);
    if( st != NULL ) {
      RouteOp.cmd(st, (iONode)NodeOp.base.clone(cmd));
    }
    StrOp.free(idRes);
  }

  /* output */
  else if( StrOp.equals( wOutput.name(), NodeOp.getName(cmd)) ) {
    char* idRes = VarOp.getText(wItem.getid(cmd), map, ' ');
    iOOutput co = ModelOp.getOutput(model, idRes);
    if( co != NULL ) {
      OutputOp.cmd(co, (iONode)NodeOp.base.clone(cmd), True);
    }
    StrOp.free(idRes);
  }

  /* sensor */
  else if( StrOp.equals( wFeedback.name(), NodeOp.getName(cmd)) ) {
    char* idRes = VarOp.getText(wItem.getid(cmd), map, ' ');
    iOFBack fb = ModelOp.getFBack(model, idRes);
    if( fb != NULL ) {
      if( StrOp.equals(wOutput.flip, wFeedback.getcmd(cmd)) ) {
        Boolean state = FBackOp.getState(fb);
        wFeedback.setstate( cmd, !state );
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "setting sensor [%s] to [%s]", idRes, state?"off":"on" );
        FBackOp.event( fb, (iONode)NodeOp.base.clone(cmd) );
      }
      else if( StrOp.equals(wOutput.on, wFeedback.getcmd(cmd)) || StrOp.equals(wOutput.off, wFeedback.getcmd(cmd)) ) {
        wFeedback.setstate( cmd, StrOp.equals(wOutput.on, wFeedback.getcmd(cmd)) ? True:False);
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "setting sensor [%s] to [%s]", idRes, wFeedback.getcmd(cmd) );
        FBackOp.event( fb, (iONode)NodeOp.base.clone(cmd) );
      }
      else {
        FBackOp.cmd(fb, (iONode)NodeOp.base.clone(cmd), True);
      }
    }
    StrOp.free(idRes);
  }

  /* actionctrl */
  else if( StrOp.equals( wActionCtrl.name(), NodeOp.getName(cmd)) ) {
    iOAction Action = ModelOp.getAction(model, wActionCtrl.getid( cmd ));
    if( Action != NULL ) {
      ActionOp.exec(Action, cmd);
    }
    else
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "action [%s] not found", wActionCtrl.getid( cmd ) );
  }

  /* system */
  else if( StrOp.equals( wSysCmd.name(), NodeOp.getName(cmd)) ) {
    int error = 0;
    ControlOp.cmd( AppOp.getControl(), (iONode)NodeOp.base.clone(cmd), &error );
  }

  /* sleep */
  else if( StrOp.equals( "sleep", NodeOp.getName(cmd)) ) {
    int sleep = VarOp.getValue(NodeOp.getStr(cmd, "time", "0"), NULL );
    if( sleep > 100 ) {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "a sleep > 100ms, %d, is not permitted; Sleep 100ms...", sleep );
      sleep = 100;
    }
    ThreadOp.sleep(sleep);
  }

  /* exit */
  else if( StrOp.equals( "exit", NodeOp.getName(cmd)) ) {
    exit = True;
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "exit script: %s", NodeOp.getStr(cmd, "cmt", "?") );
  }

  /* break */
  else if( StrOp.equals( "break", NodeOp.getName(cmd)) ) {
    if( breakloop != NULL ) {
      const char* condition = NodeOp.getStr(cmd, "condition", NULL);
      char* conditionRes = NULL;
      if( condition != NULL ) {
        conditionRes = TextOp.replaceAllSubstitutions(condition, map);
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "break condition [%s]", conditionRes );
      }
      if( conditionRes == NULL || __isCondition(conditionRes, NodeOp.getBool(cmd, "alltrue", True)) ) {
        *breakloop = True;
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "break: %s", NodeOp.getStr(cmd, "cmt", "?") );
      }
    }
  }

  /* sub */
  else if( StrOp.equals( "sub", NodeOp.getName(cmd)) ) {
    const char* scriptFile = NodeOp.getStr(cmd, "file", "");
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "sub xmlscript: [%s]", scriptFile );
    if( FileOp.exist(scriptFile) ) {
      int size = FileOp.fileSize(scriptFile);
      char* xmlscript = allocMem( size + 1);
      iOFile f = FileOp.inst( scriptFile, OPEN_READONLY);
      if( f != NULL ) {
        FileOp.read( f, xmlscript, size);
        FileOp.base.del(f);
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "run sub xmlscript file [%s], size=%d", scriptFile, size );
        XmlScriptOp.run( xmlscript, map );
        freeMem(xmlscript);
      }
    }
  }

  /* var */
  else if( StrOp.equals( wVariable.name(), NodeOp.getName(cmd)) ) {
    iOMap map = MapOp.inst();
    const char* id = wItem.getid(cmd);
    MapOp.put(map, "oid", (obj)oid);
    char* varRes = TextOp.replaceAllSubstitutions(id, map);
    MapOp.base.del(map);

    iONode var = ModelOp.getVariable(model, varRes);
    if( var == NULL )
      var = ModelOp.addVariable( model, varRes );

    if( var != NULL ) {
      if( NodeOp.findAttr(cmd, "text") != NULL) {
        wVariable.settext(var, VarOp.getText(wVariable.gettext(cmd), NULL, ' '));
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "var [%s] = [%s]", varRes, wVariable.gettext(var) );
      }
      if( NodeOp.findAttr(cmd, "value") != NULL ) {
        wVariable.setvalue(var, VarOp.getValue(NodeOp.getStr(cmd, "value", ""), NULL));
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "var [%s] = %d", varRes, wVariable.getvalue(var) );
      }
      if( NodeOp.findAttr(cmd, "min") != NULL ) {
        wVariable.setmin(var, NodeOp.getInt(cmd, "min", 0));
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "var [%s] min = %d", varRes, wVariable.getmin(var) );
      }
      if( NodeOp.findAttr(cmd, "max") != NULL ) {
        wVariable.setmax(var, NodeOp.getInt(cmd, "max", 0));
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "var [%s] max = %d", varRes, wVariable.getmax(var) );
      }
      if( NodeOp.findAttr(cmd, "cmd") != NULL ) {
        if( StrOp.equals(NodeOp.getStr(cmd, "cmd", ""), wVariable.op_random ) ) {
          VarOp.setRandom(var);
        }
        else if( StrOp.equals(NodeOp.getStr(cmd, "cmd", ""), wVariable.op_start ) ) {
          wVariable.settimer(var, True);
          TraceOp.trc( name, TRCLEVEL_CALC, __LINE__, 9999, "variable [%s] cmd=[%s] timer started with value %d",
              wVariable.getid(var), wVariable.op_start, wVariable.getvalue(var) );
        }
        else if( StrOp.equals(NodeOp.getStr(cmd, "cmd", ""), wVariable.op_stop ) ) {
          wVariable.settimer(var, False);
          TraceOp.trc( name, TRCLEVEL_CALC, __LINE__, 9999, "variable [%s] cmd=[%s] timer stopped with value %d",
              wVariable.getid(var), wVariable.op_stop, wVariable.getvalue(var) );
        }
      }
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
    StrOp.free( varRes );
  }


  /* text */
  else if( StrOp.equals( wText.name(), NodeOp.getName(cmd)) ) {
    const char* oid = wItem.getid(cmd);
    iOText text = ModelOp.getText( model, oid );
    if( text != NULL && wText.getformat(cmd) != NULL ) {
      iONode evt = NodeOp.inst( wText.name(), NULL, ELEMENT_NODE );
      wText.setformat(evt, wText.getformat(cmd));
      if( map != NULL ) {
        if( MapOp.haskey(map, "lcid") )
          wText.setreflcid(evt, (const char*)MapOp.get(map, "lcid"));
        if( MapOp.haskey(map, "bkid") )
          wText.setrefbkid(evt, (const char*)MapOp.get(map, "bkid"));
      }
      TextOp.base.event(text, evt);
    }
    else if( text != NULL && wText.getformat(cmd) == NULL ) {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "text [%s] format is missing", oid);
    }
  }

  /* if */
  else if( StrOp.equals( "if", NodeOp.getName(cmd)) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "nested if...");
    exit = __doIf(cmd, map);
  }

  /* foreach */
  else if( StrOp.equals( "foreach", NodeOp.getName(cmd)) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "nested foreach...");
    exit = __doForEach(cmd, map);
  }

  return exit;
}


static Boolean __doIf(iONode nodeScript, iOMap map) {
  Boolean exit = False;
  const char* condition = NodeOp.getStr(nodeScript, "condition", NULL);
  const char* state = NodeOp.getStr(nodeScript, "state", NULL);
  const char* class = NodeOp.getStr(nodeScript, "class", NULL);

  if( condition == NULL && state == NULL && class == NULL) {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "skip: condition and/or state and/or class is missing in the if statement" );
    return exit;
  }

  char* conditionRes = NULL;
  char* stateRes = NULL;
  char* classRes = NULL;
  Boolean conditionOK = True;
  Boolean stateOK = True;
  Boolean classOK = True;

  if( condition != NULL ) {
    char* conditionRes = TextOp.replaceAllSubstitutions(condition, map);
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "if condition [%s]", conditionRes );
    conditionOK = __isCondition(conditionRes, NodeOp.getBool(nodeScript, "alltrue", True));
  }
  if( state != NULL ) {
    stateRes = TextOp.replaceAllSubstitutions(state, map);
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "if state [%s]", stateRes );
    stateOK = __isState(stateRes);
  }
  if( class != NULL ) {
    classRes = TextOp.replaceAllSubstitutions(class, map);
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "if class [%s]", classRes );
    classOK = __isClass(classRes);
  }

  if( conditionOK && stateOK && classOK ) {
    iONode thenNode = NodeOp.findNode(nodeScript, "then");
    if( thenNode != NULL ) {
      int cmds = NodeOp.getChildCnt(thenNode);
      int n = 0;
      for( n = 0; n < cmds && exit == False; n++ ) {
        iONode cmd = NodeOp.getChild(thenNode, n);
        char* id = VarOp.getText(wItem.getid(cmd), map, ' ');
        wItem.setid(cmd, id);
        exit = __executeCmd(cmd, map, NULL, NULL);
        StrOp.free(id);
      }
    }
    else
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "then is missing in the if statement" );
  }
  else {
    iONode elseNode = NodeOp.findNode(nodeScript, "else");
    if( elseNode != NULL ) {
      int cmds = NodeOp.getChildCnt(elseNode);
      int n = 0;
      for( n = 0; n < cmds && exit == False; n++ ) {
        iONode cmd = NodeOp.getChild(elseNode, n);
        char* id = TextOp.replaceAllSubstitutions(wItem.getid(cmd), map);
        wItem.setid(cmd, id);
        exit = __executeCmd(cmd, map, NULL, NULL);
        StrOp.free(id);
      }
    }
  }

  StrOp.free(conditionRes);
  return exit;
}


static Boolean __doForEach(iONode nodeScript, iOMap map) {
  Boolean exit = False;
  Boolean breakloop = False;
  iOModel model = AppOp.getModel();
  iONode plan = ModelOp.getModel(model);
  iONode table = NodeOp.findNode(plan, NodeOp.getStr(nodeScript, "table", ""));
  const char* condition = NodeOp.getStr(nodeScript, "condition", NULL);
  if( table != NULL ) {
    int childs = NodeOp.getChildCnt(table);
    int i = 0;
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "for each in table [%s] condition [%s]", NodeOp.getName(table), condition!=NULL?condition:"-" );
    for( i = 0; i < childs && breakloop == False; i++ ) {
      iONode child = NodeOp.getChild( table, i);
      const char* oid = wItem.getid(child);
      char* conditionRes = NULL;
      if( condition != NULL ) {
        MapOp.put(map, "oid", (obj)oid);
        if( StrOp.equals( wLoc.name(), NodeOp.getName(child) ) ) {
          iOLoc lc = ModelOp.getLoc(model, wItem.getid(child), NULL, False);
          if( lc != NULL )
            MapOp.put(map, "lcclass", (obj)LocOp.getClass(lc));
          else
            MapOp.put(map, "lcclass", (obj)wLoc.getclass(child));
        }
        if( StrOp.equals( wBlock.name(), NodeOp.getName(child) ) ) {
          iIBlockBase bk = ModelOp.getBlock(model, wItem.getid(child));
          if( bk != NULL )
            MapOp.put(map, "bkclass", (obj)wBlock.getclass(bk->base.properties(bk)));
          else
            MapOp.put(map, "bkclass", (obj)wBlock.getclass(child));
        }
        conditionRes = TextOp.replaceAllSubstitutions(condition, map);
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "for each in table [%s] condition [%s]", NodeOp.getName(table), conditionRes );
      }

      if( conditionRes == NULL || __isCondition(conditionRes, NodeOp.getBool(nodeScript, "alltrue", True)) ) {
        int cmds = NodeOp.getChildCnt(nodeScript);
        int n = 0;
        for( n = 0; n < cmds && exit == False && breakloop == False; n++ ) {
          iONode cmd = NodeOp.getChild(nodeScript, n);
          Boolean emptyId = False;
          /*
          char* xmlStr = NodeOp.base.toString(cmd);
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "%s", xmlStr );
          StrOp.free(xmlStr);
          */
          if( StrOp.len(wItem.getid(cmd)) == 0 ) {
            wItem.setid(cmd, oid);
            emptyId = True;
          }
          exit = __executeCmd(cmd, map, oid, &breakloop);

          if( emptyId ) {
            wItem.setid(cmd, "");
          }

        }
      }

      StrOp.free(conditionRes);
    }
  }
  return exit;
}


/*
<foreach table="lclist" condition="#var2%oid% < &time">
  <fn f3="true"/>
  <var id="var2%oid%" val="0"/>
  <lc cmd="go"/>
</foreach>
 */
static void _run(const char* script, iOMap map) {
  iODoc  doc        = DocOp.parse(script);
  iONode nodeScript = NULL;

  /*
  unsigned char* donkey = StrOp.strToByte(AppOp.getdonkey());
  char* decodedKey = SystemOp.decode(donkey, StrOp.len(AppOp.getdonkey())/2, AppOp.getdoneml());

  if( SystemOp.isExpired(decodedKey, NULL, NULL, wGlobal.vmajor, wGlobal.vminor) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "no valid support key found for xmlscript" );
    return;
  }
  */

  if( doc != NULL && DocOp.getRootNode(doc) != NULL) {
    nodeScript = DocOp.getRootNode(doc);
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "script: [%s]", NodeOp.getName(nodeScript) );
    if( StrOp.equals( "foreach", NodeOp.getName(nodeScript) ) ) {
      __doForEach(nodeScript, map);
    }
    else if( StrOp.equals( "if", NodeOp.getName(nodeScript) ) ) {
      __doIf(nodeScript, map);
    }
    else if( StrOp.equals( "xmlscript", NodeOp.getName(nodeScript) ) ) {
      Boolean exit = False;
      int cnt = NodeOp.getChildCnt(nodeScript);
      int i = 0;
      for( i = 0; i < cnt && exit == False; i++ ) {
        iONode cmd = NodeOp.getChild(nodeScript, i);
        if( StrOp.equals( "foreach", NodeOp.getName(cmd) ) )
          exit = __doForEach(cmd, map);
        else if( StrOp.equals( "if", NodeOp.getName(cmd) ) )
          exit = __doIf(cmd, map);
        else
          exit = __executeCmd(cmd, map, NULL, NULL);
      }
    }

    NodeOp.base.del(nodeScript);
  }

  if( doc != NULL)
    DocOp.base.del(doc);

}



/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocrail/impl/xmlscript.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
