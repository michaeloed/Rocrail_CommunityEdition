/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/BlockList.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.BlockList
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_bklist = {
  "bklist",  "Block table",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_bklist.name;
}
static const char* _node_remark(void) {
  return RocsWgen_bklist.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_bklist.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_bklist.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * bk
 */
static struct __nodedef RocsWgen_bk = {
  "bk",  "",  False,  "n",};
static iONode _getbk(iONode node) {
  xNode( RocsWgen_bklist, node );
  return NodeOp.findNode( node, "bk");
}


static iONode _nextbk(iONode node, iONode child) {
  xNode( RocsWgen_bklist, node );
  return NodeOp.findNextNode( node, child);
}
static void _setbk(iONode node, iONode p_bk) {
  xNode( RocsWgen_bklist, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_bklist.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node bklist not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node bklist not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_bk;
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


struct __wBlockList wBlockList = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getbk,
  _nextbk,
  _setbk,
  _node_dump,
};
