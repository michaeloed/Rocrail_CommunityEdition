/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/FbMods.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.FbMods
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_fbmods = {
  "fbmods",  "feedback module listing",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_fbmods.name;
}
static const char* _node_remark(void) {
  return RocsWgen_fbmods.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_fbmods.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_fbmods.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bus
 */
static struct __attrdef RocsWgen_bus = {
  "bus",  "bus number",  "",  "int",  "0",  "0-*",  False,
};
static int _getbus(iONode node) {
  int defval = xInt( RocsWgen_bus );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fbmods, node );
  return NodeOp.getInt( node, "bus", defval );
}
static void _setbus(iONode node, int p_bus) {
  if( node == NULL ) return;
  xNode( RocsWgen_fbmods, node );
  NodeOp.setInt( node, "bus", p_bus );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * modules
 */
static struct __attrdef RocsWgen_modules = {
  "modules",  "comma separated list of connected feedback module addresses",  "",  "string",  "",  "*",  False,
};
static const char* _getmodules(iONode node) {
  const char* defval = xStr( RocsWgen_modules );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fbmods, node );
  return NodeOp.getStr( node, "modules", defval );
}
static void _setmodules(iONode node, const char* p_modules) {
  if( node == NULL ) return;
  xNode( RocsWgen_fbmods, node );
  NodeOp.setStr( node, "modules", p_modules );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[3] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_fbmods.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node fbmods not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node fbmods not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_bus;
  attrList[1] = &RocsWgen_modules;
  attrList[2] = NULL;
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


struct __wFbMods wFbMods = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getbus,
  _setbus,
  _getmodules,
  _setmodules,
  _node_dump,
};
