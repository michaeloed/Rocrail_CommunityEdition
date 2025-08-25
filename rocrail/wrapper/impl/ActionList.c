/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/ActionList.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.ActionList
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_aclist = {
  "aclist",  "timed action table",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_aclist.name;
}
static const char* _node_remark(void) {
  return RocsWgen_aclist.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_aclist.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_aclist.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * ac
 */
static struct __nodedef RocsWgen_ac = {
  "ac",  "",  False,  "n",};
static iONode _getac(iONode node) {
  xNode( RocsWgen_aclist, node );
  return NodeOp.findNode( node, "ac");
}


static iONode _nextac(iONode node, iONode child) {
  xNode( RocsWgen_aclist, node );
  return NodeOp.findNextNode( node, child);
}
static void _setac(iONode node, iONode p_ac) {
  xNode( RocsWgen_aclist, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_aclist.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node aclist not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node aclist not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_ac;
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


struct __wActionList wActionList = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getac,
  _nextac,
  _setac,
  _node_dump,
};
