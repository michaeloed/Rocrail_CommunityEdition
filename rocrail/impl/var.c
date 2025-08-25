/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/


#include "rocrail/impl/var_impl.h"

#include "rocrail/public/action.h"
#include "rocrail/public/app.h"
#include "rocrail/public/model.h"
#include "rocrail/public/text.h"

#include "rocrail/wrapper/public/ActionCtrl.h"
#include "rocrail/wrapper/public/Variable.h"

#include "rocs/public/mem.h"
#include "rocs/public/strtok.h"

static int instCnt = 0;

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

/** ----- OVar ----- */


/*
 * Separator: blank
 * #: variable prefix
 * $: text prefix
 */
#define OP_NONE 0
#define OP_PLUS 1
#define OP_MIN  2
#define OP_MULT 3
#define OP_DIVI 4


static Boolean _setRandom(iONode var) {
  Boolean ok = False;

  if( wVariable.getmax(var) > wVariable.getmin(var) ) {
    int rval = wVariable.getmin(var) + (rand() % wVariable.getmax(var) );
    wVariable.setvalue(var, rval);
    TraceOp.trc( name, TRCLEVEL_CALC, __LINE__, 9999, "variable [%s] cmd=[%s] new random value=%d",
        wVariable.getid(var), wVariable.op_random, wVariable.getvalue(var) );
    ok = True;
  }
  else {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "variable [%s] cmd=[%s] not possible; max. must be greater then min.",
        wVariable.getid(var), wVariable.op_random );
  }
  return ok;
}

static char* _getText( const char* p_ValStr, iOMap map, char separator ) {
  iOModel model = AppOp.getModel();
  char* valStr = NULL;
  char* retVal = NULL;
  int   tokCnt = 0;
  char sepStr[4];
  sepStr[0] = separator;
  sepStr[1] = '\0';

  if( map != NULL )
    valStr = TextOp.replaceAllSubstitutions(p_ValStr, map);
  else
    valStr = StrOp.dup(p_ValStr);

  iOStrTok tok = StrTokOp.inst(valStr, separator);

  while( StrTokOp.hasMoreTokens(tok) ) {
    const char* v = StrTokOp.nextToken(tok);
    tokCnt++;
    if( v[0] == '#' ) { /* variable */
      iONode valVar = ModelOp.getVariable(model, v+1);
      if( valVar != NULL ) {
        char* sV = NULL;
        if( StrTokOp.hasMoreTokens(tok))
          sV = StrOp.fmt( "%d%c", wVariable.getvalue(valVar), separator );
        else
          sV = StrOp.fmt( "%d", wVariable.getvalue(valVar) );
        retVal = StrOp.cat( retVal, sV );
        StrOp.free(sV);
      }
      else {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "no such variable: [%s]", v+1 );
      }
    }
    else if( v[0] == '@' ) { /* variable */
      iONode valVar = ModelOp.getVariable(model, v+1);
      if( valVar != NULL ) {
        char* sV = NULL;
        if( StrTokOp.hasMoreTokens(tok))
          sV = StrOp.fmt( "%s%c", wVariable.gettext(valVar), separator );
        else
          sV = StrOp.fmt( "%s", wVariable.gettext(valVar) );
        retVal = StrOp.cat( retVal, sV );
        StrOp.free(sV);
      }
      else {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "no such variable: [%s]", v+1 );
      }
    }
    else if( v[0] == '$' ) { /* text */
      iOText text = ModelOp.getText(model, v+1);
      if( text != NULL ) {
        retVal = StrOp.cat( retVal, TextOp.getText(text) );
        if( StrTokOp.hasMoreTokens(tok))
          retVal = StrOp.cat( retVal, sepStr );
      }
    }
    else if( v[0] == '&' ) { /* system variable */
      char* varval = ModelOp.getSysVar(model, v+1);
      if( varval != NULL ) {
        retVal = StrOp.cat( retVal, varval );
        if( StrTokOp.hasMoreTokens(tok))
          retVal = StrOp.cat( retVal, sepStr );
        StrOp.free(varval);
      }
    }
    else {
      retVal = StrOp.cat( retVal, v );
      if( StrTokOp.hasMoreTokens(tok) )
        retVal = StrOp.cat( retVal, sepStr );
    }
  }

  StrTokOp.base.del(tok);
  StrOp.free(valStr);

  return retVal;
}


static int _getValue( const char* p_ValStr, iOMap map ) {
  iOModel model = AppOp.getModel();
  int retVal = 0;
  int operator = OP_NONE;
  char* valStr = NULL;

  if( map != NULL )
    valStr = TextOp.replaceAllSubstitutions(p_ValStr, map);
  else
    valStr = StrOp.dup(p_ValStr);

  iOStrTok tok = StrTokOp.inst(valStr, ' ');

  while( StrTokOp.hasMoreTokens(tok) ) {
    const char* v = StrTokOp.nextToken(tok);
    if( StrOp.len(v) > 0 ) {

      if( v[0] == '+' ) {
        operator = OP_PLUS;
        TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "operation=PLUS" );
        continue;
      }

      if( v[0] == '-' ) {
        operator = OP_MIN;
        TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "operation=MIN" );
        continue;
      }

      if( v[0] == '*' ) {
        operator = OP_MULT;
        TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "operation=MULT" );
        continue;
      }

      if( v[0] == '/' ) {
        operator = OP_DIVI;
        TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "operation=DIVI" );
        continue;
      }

      if( v[0] == '#' ) { /* variable */
        iONode valVar = ModelOp.getVariable(model, v+1);
        if( valVar != NULL ) {
          TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "variable %s is %d", v+1, wVariable.getvalue(valVar) );
          if( operator == OP_NONE ) retVal  = wVariable.getvalue(valVar);
          if( operator == OP_PLUS ) retVal += wVariable.getvalue(valVar);
          if( operator == OP_MIN  ) retVal -= wVariable.getvalue(valVar);
          if( operator == OP_MULT ) retVal *= wVariable.getvalue(valVar);
          if( operator == OP_DIVI ) retVal /= wVariable.getvalue(valVar);
        }
        continue;
      }

      if( v[0] == '$' ) { /* text */
        iOText text = ModelOp.getText(model, v+1);
        if( text != NULL ) {
          TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "text %s is %d (%s)", v+1, atoi(TextOp.getText(text)), TextOp.getText(text) );
          if( operator == OP_NONE ) retVal  = atoi(TextOp.getText(text));
          if( operator == OP_PLUS ) retVal += atoi(TextOp.getText(text));
          if( operator == OP_MIN  ) retVal -= atoi(TextOp.getText(text));
          if( operator == OP_MULT ) retVal *= atoi(TextOp.getText(text));
          if( operator == OP_DIVI ) retVal /= atoi(TextOp.getText(text));
        }
        continue;
      }

      if( v[0] == '&' ) { /* system variable */
        char* varval = ModelOp.getSysVar(model, v+1);
        if( varval != NULL ) {
          TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "sysvar %s is %d (%s)", v+1, atoi(varval), varval );
          if( operator == OP_NONE ) retVal  = atoi(varval);
          if( operator == OP_PLUS ) retVal += atoi(varval);
          if( operator == OP_MIN  ) retVal -= atoi(varval);
          if( operator == OP_MULT ) retVal *= atoi(varval);
          if( operator == OP_DIVI ) retVal /= atoi(varval);
          StrOp.free(varval);
        }
        continue;
      }

      /* number */
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "number is %d", atoi(v) );
      if( operator == OP_NONE ) retVal  = atoi(v);
      if( operator == OP_PLUS ) retVal += atoi(v);
      if( operator == OP_MIN  ) retVal -= atoi(v);
      if( operator == OP_MULT ) retVal *= atoi(v);
      if( operator == OP_DIVI ) retVal /= atoi(v);

    }
  }

  StrTokOp.base.del(tok);
  StrOp.free(valStr);

  return retVal;
}

/**  */
static void _checkActions( iONode var ) {
  iOModel model = AppOp.getModel();
  int idx = 0;
  Boolean rc = False;
  iONode actionctrl = wVariable.getactionctrl( var );

  /* loop over all actions */
  while( actionctrl != NULL ) {
    const char* state = wActionCtrl.getstate(actionctrl);
    int stateVal = VarOp.getValue(state+1, NULL);

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


    if( rc ) {
      iOAction action = ModelOp.getAction(model, wActionCtrl.getid( actionctrl ));
      if( action != NULL )
        ActionOp.exec(action, actionctrl);

      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "action %d with value=%d", idx, wVariable.getvalue(var) );
    }
    else {
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "action %d state is not true: %d != %d (var != state)",
          idx, wVariable.getvalue(var), stateVal );
    }
    idx++;
    actionctrl = wVariable.nextactionctrl( var, actionctrl );
  }
  return;
}


/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocrail/impl/var.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
