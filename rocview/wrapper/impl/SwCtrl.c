/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:52 2018
  */

#include "rocview/wrapper/public/SwCtrl.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.SwCtrl
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_swctrl = {
  "swctrl",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_swctrl.name;
}
static const char* _node_remark(void) {
  return RocsWgen_swctrl.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_swctrl.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_swctrl.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bus
 */
static struct __attrdef RocsWgen_bus = {
  "bus",  "",  "",  "int",  "0",  "",  False,
};
static int _getbus(iONode node) {
  int defval = xInt( RocsWgen_bus );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_swctrl, node );
  return NodeOp.getInt( node, "bus", defval );
}
static void _setbus(iONode node, int p_bus) {
  if( node == NULL ) return;
  xNode( RocsWgen_swctrl, node );
  NodeOp.setInt( node, "bus", p_bus );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iid
 */
static struct __attrdef RocsWgen_iid = {
  "iid",  "",  "",  "string",  "",  "",  False,
};
static const char* _getiid(iONode node) {
  const char* defval = xStr( RocsWgen_iid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_swctrl, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_swctrl, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * module
 */
static struct __attrdef RocsWgen_module = {
  "module",  "",  "",  "int",  "1",  "",  False,
};
static int _getmodule(iONode node) {
  int defval = xInt( RocsWgen_module );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_swctrl, node );
  return NodeOp.getInt( node, "module", defval );
}
static void _setmodule(iONode node, int p_module) {
  if( node == NULL ) return;
  xNode( RocsWgen_swctrl, node );
  NodeOp.setInt( node, "module", p_module );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[4] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_swctrl.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node swctrl not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node swctrl not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_bus;
  attrList[1] = &RocsWgen_iid;
  attrList[2] = &RocsWgen_module;
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


struct __wSwCtrl wSwCtrl = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getbus,
  _setbus,
  _getiid,
  _setiid,
  _getmodule,
  _setmodule,
  _node_dump,
};
