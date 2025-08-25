/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/RouteList.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.RouteList
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_stlist = {
  "stlist",  "Route table",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_stlist.name;
}
static const char* _node_remark(void) {
  return RocsWgen_stlist.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_stlist.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_stlist.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * st
 */
static struct __nodedef RocsWgen_st = {
  "st",  "A street defines a destination fromone block to another including switch positions.",  False,  "n",};
static iONode _getst(iONode node) {
  xNode( RocsWgen_stlist, node );
  return NodeOp.findNode( node, "st");
}


static iONode _nextst(iONode node, iONode child) {
  xNode( RocsWgen_stlist, node );
  return NodeOp.findNextNode( node, child);
}
static void _setst(iONode node, iONode p_st) {
  xNode( RocsWgen_stlist, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_stlist.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node stlist not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node stlist not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_st;
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


struct __wRouteList wRouteList = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getst,
  _nextst,
  _setst,
  _node_dump,
};
