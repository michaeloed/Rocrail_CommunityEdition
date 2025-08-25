/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/DecList.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.DecList
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_declist = {
  "declist",  "Decoder table",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_declist.name;
}
static const char* _node_remark(void) {
  return RocsWgen_declist.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_declist.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_declist.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * dec
 */
static struct __nodedef RocsWgen_dec = {
  "dec",  "DCC Decoder definition.",  False,  "n",};
static iONode _getdec(iONode node) {
  xNode( RocsWgen_declist, node );
  return NodeOp.findNode( node, "dec");
}


static iONode _nextdec(iONode node, iONode child) {
  xNode( RocsWgen_declist, node );
  return NodeOp.findNextNode( node, child);
}
static void _setdec(iONode node, iONode p_dec) {
  xNode( RocsWgen_declist, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_declist.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node declist not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node declist not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_dec;
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


struct __wDecList wDecList = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getdec,
  _nextdec,
  _setdec,
  _node_dump,
};
