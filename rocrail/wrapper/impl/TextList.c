/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/TextList.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.TextList
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_txlist = {
  "txlist",  "text symbols table",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_txlist.name;
}
static const char* _node_remark(void) {
  return RocsWgen_txlist.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_txlist.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_txlist.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * tx
 */
static struct __nodedef RocsWgen_tx = {
  "tx",  "",  False,  "n",};
static iONode _gettx(iONode node) {
  xNode( RocsWgen_txlist, node );
  return NodeOp.findNode( node, "tx");
}


static iONode _nexttx(iONode node, iONode child) {
  xNode( RocsWgen_txlist, node );
  return NodeOp.findNextNode( node, child);
}
static void _settx(iONode node, iONode p_tx) {
  xNode( RocsWgen_txlist, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_txlist.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node txlist not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node txlist not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_tx;
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


struct __wTextList wTextList = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _gettx,
  _nexttx,
  _settx,
  _node_dump,
};
