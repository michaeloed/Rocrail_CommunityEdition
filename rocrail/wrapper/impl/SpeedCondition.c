/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/SpeedCondition.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.SpeedCondition
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_speedcondition = {
  "speedcondition",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_speedcondition.name;
}
static const char* _node_remark(void) {
  return RocsWgen_speedcondition.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_speedcondition.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_speedcondition.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * class
 */
static struct __attrdef RocsWgen_class = {
  "class",  "Classes",  "",  "string",  "",  "",  False,
};
static const char* _getclass(iONode node) {
  const char* defval = xStr( RocsWgen_class );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_speedcondition, node );
  return NodeOp.getStr( node, "class", defval );
}
static void _setclass(iONode node, const char* p_class) {
  if( node == NULL ) return;
  xNode( RocsWgen_speedcondition, node );
  NodeOp.setStr( node, "class", p_class );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * desc
 */
static struct __attrdef RocsWgen_desc = {
  "desc",  "Condition description",  "",  "string",  "",  "",  False,
};
static const char* _getdesc(iONode node) {
  const char* defval = xStr( RocsWgen_desc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_speedcondition, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_speedcondition, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * percent
 */
static struct __attrdef RocsWgen_percent = {
  "percent",  "Speed in percent.",  "%",  "int",  "0",  "0-100",  False,
};
static int _getpercent(iONode node) {
  int defval = xInt( RocsWgen_percent );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_speedcondition, node );
  return NodeOp.getInt( node, "percent", defval );
}
static void _setpercent(iONode node, int p_percent) {
  if( node == NULL ) return;
  xNode( RocsWgen_speedcondition, node );
  NodeOp.setInt( node, "percent", p_percent );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * type
 */
static struct __attrdef RocsWgen_type = {
  "type",  "Train type",  "",  "string",  "",  "",  False,
};
static const char* _gettype(iONode node) {
  const char* defval = xStr( RocsWgen_type );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_speedcondition, node );
  return NodeOp.getStr( node, "type", defval );
}
static void _settype(iONode node, const char* p_type) {
  if( node == NULL ) return;
  xNode( RocsWgen_speedcondition, node );
  NodeOp.setStr( node, "type", p_type );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * value
 */
static struct __attrdef RocsWgen_value = {
  "value",  "Variable value",  "",  "string",  "=0",  "",  False,
};
static const char* _getvalue(iONode node) {
  const char* defval = xStr( RocsWgen_value );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_speedcondition, node );
  return NodeOp.getStr( node, "value", defval );
}
static void _setvalue(iONode node, const char* p_value) {
  if( node == NULL ) return;
  xNode( RocsWgen_speedcondition, node );
  NodeOp.setStr( node, "value", p_value );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * variable
 */
static struct __attrdef RocsWgen_variable = {
  "variable",  "Variable ID",  "",  "string",  "",  "",  False,
};
static const char* _getvariable(iONode node) {
  const char* defval = xStr( RocsWgen_variable );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_speedcondition, node );
  return NodeOp.getStr( node, "variable", defval );
}
static void _setvariable(iONode node, const char* p_variable) {
  if( node == NULL ) return;
  xNode( RocsWgen_speedcondition, node );
  NodeOp.setStr( node, "variable", p_variable );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * varsub
 */
static struct __attrdef RocsWgen_varsub = {
  "varsub",  "Variable sub ID",  "",  "string",  "",  "",  False,
};
static const char* _getvarsub(iONode node) {
  const char* defval = xStr( RocsWgen_varsub );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_speedcondition, node );
  return NodeOp.getStr( node, "varsub", defval );
}
static void _setvarsub(iONode node, const char* p_varsub) {
  if( node == NULL ) return;
  xNode( RocsWgen_speedcondition, node );
  NodeOp.setStr( node, "varsub", p_varsub );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[8] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_speedcondition.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node speedcondition not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node speedcondition not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_class;
  attrList[1] = &RocsWgen_desc;
  attrList[2] = &RocsWgen_percent;
  attrList[3] = &RocsWgen_type;
  attrList[4] = &RocsWgen_value;
  attrList[5] = &RocsWgen_variable;
  attrList[6] = &RocsWgen_varsub;
  attrList[7] = NULL;
  nodeList[0] = NULL;
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


struct __wSpeedCondition wSpeedCondition = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getclass,
  _setclass,
  _getdesc,
  _setdesc,
  _getpercent,
  _setpercent,
  _gettype,
  _settype,
  _getvalue,
  _setvalue,
  _getvariable,
  _setvariable,
  _getvarsub,
  _setvarsub,
  _node_dump,
};
