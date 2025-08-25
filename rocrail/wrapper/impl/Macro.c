/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Macro.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Macro
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_macro = {
  "macro",  "Macro definition for accessories.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_macro.name;
}
static const char* _node_remark(void) {
  return RocsWgen_macro.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_macro.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_macro.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * class
 */
static struct __attrdef RocsWgen_class = {
  "class",  "Module class in case of an export.",  "",  "int",  "0",  "",  False,
};
static int _getclass(iONode node) {
  int defval = xInt( RocsWgen_class );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_macro, node );
  return NodeOp.getInt( node, "class", defval );
}
static void _setclass(iONode node, int p_class) {
  if( node == NULL ) return;
  xNode( RocsWgen_macro, node );
  NodeOp.setInt( node, "class", p_class );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * hours
 */
static struct __attrdef RocsWgen_hours = {
  "hours",  "",  "",  "int",  "0",  "",  False,
};
static int _gethours(iONode node) {
  int defval = xInt( RocsWgen_hours );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_macro, node );
  return NodeOp.getInt( node, "hours", defval );
}
static void _sethours(iONode node, int p_hours) {
  if( node == NULL ) return;
  xNode( RocsWgen_macro, node );
  NodeOp.setInt( node, "hours", p_hours );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * minutes
 */
static struct __attrdef RocsWgen_minutes = {
  "minutes",  "",  "",  "int",  "0",  "",  False,
};
static int _getminutes(iONode node) {
  int defval = xInt( RocsWgen_minutes );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_macro, node );
  return NodeOp.getInt( node, "minutes", defval );
}
static void _setminutes(iONode node, int p_minutes) {
  if( node == NULL ) return;
  xNode( RocsWgen_macro, node );
  NodeOp.setInt( node, "minutes", p_minutes );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nr
 */
static struct __attrdef RocsWgen_nr = {
  "nr",  "Macro number in case of export.",  "",  "int",  "0",  "",  False,
};
static int _getnr(iONode node) {
  int defval = xInt( RocsWgen_nr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_macro, node );
  return NodeOp.getInt( node, "nr", defval );
}
static void _setnr(iONode node, int p_nr) {
  if( node == NULL ) return;
  xNode( RocsWgen_macro, node );
  NodeOp.setInt( node, "nr", p_nr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * repeat
 */
static struct __attrdef RocsWgen_repeat = {
  "repeat",  "",  "",  "int",  "0",  "",  False,
};
static int _getrepeat(iONode node) {
  int defval = xInt( RocsWgen_repeat );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_macro, node );
  return NodeOp.getInt( node, "repeat", defval );
}
static void _setrepeat(iONode node, int p_repeat) {
  if( node == NULL ) return;
  xNode( RocsWgen_macro, node );
  NodeOp.setInt( node, "repeat", p_repeat );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * slowdown
 */
static struct __attrdef RocsWgen_slowdown = {
  "slowdown",  "",  "",  "int",  "0",  "",  False,
};
static int _getslowdown(iONode node) {
  int defval = xInt( RocsWgen_slowdown );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_macro, node );
  return NodeOp.getInt( node, "slowdown", defval );
}
static void _setslowdown(iONode node, int p_slowdown) {
  if( node == NULL ) return;
  xNode( RocsWgen_macro, node );
  NodeOp.setInt( node, "slowdown", p_slowdown );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * uid
 */
static struct __attrdef RocsWgen_uid = {
  "uid",  "The unique ID in case of an export.",  "",  "int",  "0",  "",  False,
};
static int _getuid(iONode node) {
  int defval = xInt( RocsWgen_uid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_macro, node );
  return NodeOp.getInt( node, "uid", defval );
}
static void _setuid(iONode node, int p_uid) {
  if( node == NULL ) return;
  xNode( RocsWgen_macro, node );
  NodeOp.setInt( node, "uid", p_uid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * wday
 */
static struct __attrdef RocsWgen_wday = {
  "wday",  "",  "",  "int",  "0",  "",  False,
};
static int _getwday(iONode node) {
  int defval = xInt( RocsWgen_wday );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_macro, node );
  return NodeOp.getInt( node, "wday", defval );
}
static void _setwday(iONode node, int p_wday) {
  if( node == NULL ) return;
  xNode( RocsWgen_macro, node );
  NodeOp.setInt( node, "wday", p_wday );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * macroline
 */
static struct __nodedef RocsWgen_macroline = {
  "macroline",  "",  False,  "n",};
static iONode _getmacroline(iONode node) {
  xNode( RocsWgen_macro, node );
  return NodeOp.findNode( node, "macroline");
}


static iONode _nextmacroline(iONode node, iONode child) {
  xNode( RocsWgen_macro, node );
  return NodeOp.findNextNode( node, child);
}
static void _setmacroline(iONode node, iONode p_macroline) {
  xNode( RocsWgen_macro, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[9] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_macro.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node macro not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node macro not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_class;
  attrList[1] = &RocsWgen_hours;
  attrList[2] = &RocsWgen_minutes;
  attrList[3] = &RocsWgen_nr;
  attrList[4] = &RocsWgen_repeat;
  attrList[5] = &RocsWgen_slowdown;
  attrList[6] = &RocsWgen_uid;
  attrList[7] = &RocsWgen_wday;
  attrList[8] = NULL;
  nodeList[0] = &RocsWgen_macroline;
  nodeList[1] = NULL;
  {
    int i = 0;
    Boolean err = False;
    xAttrTest( attrList, node );
    xNodeTest( nodeList, node );
    while( attrList[i] ) {
      err |= !xAttr( attrList[i], node );
      i++;
    };
    return !err;
  }
  
}


struct __wMacro wMacro = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getclass,
  _setclass,
  _gethours,
  _sethours,
  _getminutes,
  _setminutes,
  _getnr,
  _setnr,
  _getrepeat,
  _setrepeat,
  _getslowdown,
  _setslowdown,
  _getuid,
  _setuid,
  _getwday,
  _setwday,
  _getmacroline,
  _nextmacroline,
  _setmacroline,
  _node_dump,
};
