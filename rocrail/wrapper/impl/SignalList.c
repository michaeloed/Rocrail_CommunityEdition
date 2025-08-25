/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/SignalList.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.SignalList
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_sglist = {
  "sglist",  "Signal table",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_sglist.name;
}
static const char* _node_remark(void) {
  return RocsWgen_sglist.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_sglist.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_sglist.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * sg
 */
static struct __nodedef RocsWgen_sg = {
  "sg",  "Signal definition.",  False,  "n",};
static iONode _getsg(iONode node) {
  xNode( RocsWgen_sglist, node );
  return NodeOp.findNode( node, "sg");
}


static iONode _nextsg(iONode node, iONode child) {
  xNode( RocsWgen_sglist, node );
  return NodeOp.findNextNode( node, child);
}
static void _setsg(iONode node, iONode p_sg) {
  xNode( RocsWgen_sglist, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_sglist.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node sglist not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node sglist not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_sg;
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


struct __wSignalList wSignalList = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getsg,
  _nextsg,
  _setsg,
  _node_dump,
};
