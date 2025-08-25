/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/HUEConfig.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.HUEConfig
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_hueconfig = {
  "hueconfig",  "Philips HUE",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_hueconfig.name;
}
static const char* _node_remark(void) {
  return RocsWgen_hueconfig.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_hueconfig.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_hueconfig.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bridgeAPIversion
 */
static struct __attrdef RocsWgen_bridgeAPIversion = {
  "bridgeAPIversion",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getbridgeAPIversion(iONode node) {
  const char* defval = xStr( RocsWgen_bridgeAPIversion );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_hueconfig, node );
  return NodeOp.getStr( node, "bridgeAPIversion", defval );
}
static void _setbridgeAPIversion(iONode node, const char* p_bridgeAPIversion) {
  if( node == NULL ) return;
  xNode( RocsWgen_hueconfig, node );
  NodeOp.setStr( node, "bridgeAPIversion", p_bridgeAPIversion );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bridgename
 */
static struct __attrdef RocsWgen_bridgename = {
  "bridgename",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getbridgename(iONode node) {
  const char* defval = xStr( RocsWgen_bridgename );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_hueconfig, node );
  return NodeOp.getStr( node, "bridgename", defval );
}
static void _setbridgename(iONode node, const char* p_bridgename) {
  if( node == NULL ) return;
  xNode( RocsWgen_hueconfig, node );
  NodeOp.setStr( node, "bridgename", p_bridgename );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bridgeversion
 */
static struct __attrdef RocsWgen_bridgeversion = {
  "bridgeversion",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getbridgeversion(iONode node) {
  const char* defval = xStr( RocsWgen_bridgeversion );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_hueconfig, node );
  return NodeOp.getStr( node, "bridgeversion", defval );
}
static void _setbridgeversion(iONode node, const char* p_bridgeversion) {
  if( node == NULL ) return;
  xNode( RocsWgen_hueconfig, node );
  NodeOp.setStr( node, "bridgeversion", p_bridgeversion );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[4] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_hueconfig.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node hueconfig not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node hueconfig not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_bridgeAPIversion;
  attrList[1] = &RocsWgen_bridgename;
  attrList[2] = &RocsWgen_bridgeversion;
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


struct __wHUEConfig wHUEConfig = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getbridgeAPIversion,
  _setbridgeAPIversion,
  _getbridgename,
  _setbridgename,
  _getbridgeversion,
  _setbridgeversion,
  _node_dump,
};
