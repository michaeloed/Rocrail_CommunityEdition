/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/OutputList.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.OutputList
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_colist = {
  "colist",  "Common Output table",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_colist.name;
}
static const char* _node_remark(void) {
  return RocsWgen_colist.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_colist.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_colist.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * co
 */
static struct __nodedef RocsWgen_co = {
  "co",  "Common Output definition.",  False,  "n",};
static iONode _getco(iONode node) {
  xNode( RocsWgen_colist, node );
  return NodeOp.findNode( node, "co");
}


static iONode _nextco(iONode node, iONode child) {
  xNode( RocsWgen_colist, node );
  return NodeOp.findNextNode( node, child);
}
static void _setco(iONode node, iONode p_co) {
  xNode( RocsWgen_colist, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_colist.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node colist not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node colist not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_co;
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


struct __wOutputList wOutputList = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getco,
  _nextco,
  _setco,
  _node_dump,
};
