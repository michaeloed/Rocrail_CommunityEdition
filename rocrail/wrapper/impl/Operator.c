/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/Operator.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Operator
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_operator = {
  "operator",  "Operator consist definition.",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_operator.name;
}
static const char* _node_remark(void) {
  return RocsWgen_operator.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_operator.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_operator.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V_max
 */
static struct __attrdef RocsWgen_V_max = {
  "V_max",  "Maximal train speed.",  "",  "int",  "0",  "*",  False,
};
static int _getV_max(iONode node) {
  int defval = xInt( RocsWgen_V_max );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_operator, node );
  return NodeOp.getInt( node, "V_max", defval );
}
static void _setV_max(iONode node, int p_V_max) {
  if( node == NULL ) return;
  xNode( RocsWgen_operator, node );
  NodeOp.setInt( node, "V_max", p_V_max );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cargo
 */
static struct __attrdef RocsWgen_cargo = {
  "cargo",  "",  "",  "string",  "none",  "",  False,
};
static const char* _getcargo(iONode node) {
  const char* defval = xStr( RocsWgen_cargo );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_operator, node );
  return NodeOp.getStr( node, "cargo", defval );
}
static void _setcargo(iONode node, const char* p_cargo) {
  if( node == NULL ) return;
  xNode( RocsWgen_operator, node );
  NodeOp.setStr( node, "cargo", p_cargo );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * carids
 */
static struct __attrdef RocsWgen_carids = {
  "carids",  "Comma separated car IDs",  "",  "string",  "",  "*",  False,
};
static const char* _getcarids(iONode node) {
  const char* defval = xStr( RocsWgen_carids );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_operator, node );
  return NodeOp.getStr( node, "carids", defval );
}
static void _setcarids(iONode node, const char* p_carids) {
  if( node == NULL ) return;
  xNode( RocsWgen_operator, node );
  NodeOp.setStr( node, "carids", p_carids );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * class
 */
static struct __attrdef RocsWgen_class = {
  "class",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getclass(iONode node) {
  const char* defval = xStr( RocsWgen_class );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_operator, node );
  return NodeOp.getStr( node, "class", defval );
}
static void _setclass(iONode node, const char* p_class) {
  if( node == NULL ) return;
  xNode( RocsWgen_operator, node );
  NodeOp.setStr( node, "class", p_class );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmd
 */
static struct __attrdef RocsWgen_cmd = {
  "cmd",  "Operator command.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getcmd(iONode node) {
  const char* defval = xStr( RocsWgen_cmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_operator, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_operator, node );
  NodeOp.setStr( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "",  "",  "string",  "",  "*",  True,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_operator, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_operator, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lcid
 */
static struct __attrdef RocsWgen_lcid = {
  "lcid",  "",  "",  "string",  "",  "*",  True,
};
static const char* _getlcid(iONode node) {
  const char* defval = xStr( RocsWgen_lcid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_operator, node );
  return NodeOp.getStr( node, "lcid", defval );
}
static void _setlcid(iONode node, const char* p_lcid) {
  if( node == NULL ) return;
  xNode( RocsWgen_operator, node );
  NodeOp.setStr( node, "lcid", p_lcid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * location
 */
static struct __attrdef RocsWgen_location = {
  "location",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getlocation(iONode node) {
  const char* defval = xStr( RocsWgen_location );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_operator, node );
  return NodeOp.getStr( node, "location", defval );
}
static void _setlocation(iONode node, const char* p_location) {
  if( node == NULL ) return;
  xNode( RocsWgen_operator, node );
  NodeOp.setStr( node, "location", p_location );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[9] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_operator.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node operator not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node operator not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_V_max;
  attrList[1] = &RocsWgen_cargo;
  attrList[2] = &RocsWgen_carids;
  attrList[3] = &RocsWgen_class;
  attrList[4] = &RocsWgen_cmd;
  attrList[5] = &RocsWgen_id;
  attrList[6] = &RocsWgen_lcid;
  attrList[7] = &RocsWgen_location;
  attrList[8] = NULL;
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


struct __wOperator wOperator = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "addcar",
  "emptycar",
  "loadcar",
  "removecar",
  _getV_max,
  _setV_max,
  _getcargo,
  _setcargo,
  _getcarids,
  _setcarids,
  _getclass,
  _setclass,
  _getcmd,
  _setcmd,
  _getid,
  _setid,
  _getlcid,
  _setlcid,
  _getlocation,
  _setlocation,
  _node_dump,
};
