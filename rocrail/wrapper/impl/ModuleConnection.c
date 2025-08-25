/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/ModuleConnection.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.ModuleConnection
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_connection = {
  "connection",  "Connection specification",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_connection.name;
}
static const char* _node_remark(void) {
  return RocsWgen_connection.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_connection.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_connection.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "Module ID; for internal use only.",  "",  "string",  "",  "*",  False,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_connection, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_connection, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * modid
 */
static struct __attrdef RocsWgen_modid = {
  "modid",  "Module ID which connects to this module.",  "",  "string",  "",  "*",  False,
};
static const char* _getmodid(iONode node) {
  const char* defval = xStr( RocsWgen_modid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_connection, node );
  return NodeOp.getStr( node, "modid", defval );
}
static void _setmodid(iONode node, const char* p_modid) {
  if( node == NULL ) return;
  xNode( RocsWgen_connection, node );
  NodeOp.setStr( node, "modid", p_modid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * side
 */
static struct __attrdef RocsWgen_side = {
  "side",  "connection side",  "",  "string",  "",  "point-n,point-e,point-s,point-w",  False,
};
static const char* _getside(iONode node) {
  const char* defval = xStr( RocsWgen_side );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_connection, node );
  return NodeOp.getStr( node, "side", defval );
}
static void _setside(iONode node, const char* p_side) {
  if( node == NULL ) return;
  xNode( RocsWgen_connection, node );
  NodeOp.setStr( node, "side", p_side );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[4] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_connection.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node connection not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node connection not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_id;
  attrList[1] = &RocsWgen_modid;
  attrList[2] = &RocsWgen_side;
  attrList[3] = NULL;
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


struct __wModuleConnection wModuleConnection = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "point-e",
  "point-n",
  "point-s",
  "point-w",
  _getid,
  _setid,
  _getmodid,
  _setmodid,
  _getside,
  _setside,
  _node_dump,
};
