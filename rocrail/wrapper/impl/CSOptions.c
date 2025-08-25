/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/CSOptions.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.CSOptions
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_options = {
  "options",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_options.name;
}
static const char* _node_remark(void) {
  return RocsWgen_options.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_options.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_options.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * opsw
 */
static struct __attrdef RocsWgen_opsw = {
  "opsw",  "zero based options list 0=open 1=set",  "",  "string",  "",  "*",  False,
};
static const char* _getopsw(iONode node) {
  const char* defval = xStr( RocsWgen_opsw );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_options, node );
  return NodeOp.getStr( node, "opsw", defval );
}
static void _setopsw(iONode node, const char* p_opsw) {
  if( node == NULL ) return;
  xNode( RocsWgen_options, node );
  NodeOp.setStr( node, "opsw", p_opsw );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * store
 */
static struct __attrdef RocsWgen_store = {
  "store",  "set by client to signal to store the options in the command station",  "",  "bool",  "false",  "",  False,
};
static Boolean _isstore(iONode node) {
  Boolean defval = xBool( RocsWgen_store );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_options, node );
  return NodeOp.getBool( node, "store", defval );
}
static void _setstore(iONode node, Boolean p_store) {
  if( node == NULL ) return;
  xNode( RocsWgen_options, node );
  NodeOp.setBool( node, "store", p_store );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[3] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_options.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node options not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node options not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_opsw;
  attrList[1] = &RocsWgen_store;
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


struct __wCSOptions wCSOptions = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getopsw,
  _setopsw,
  _isstore,
  _setstore,
  _node_dump,
};
