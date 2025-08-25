/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/VariableList.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.VariableList
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_vrlist = {
  "vrlist",  "variable list",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_vrlist.name;
}
static const char* _node_remark(void) {
  return RocsWgen_vrlist.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_vrlist.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_vrlist.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * vr
 */
static struct __nodedef RocsWgen_vr = {
  "vr",  "",  False,  "n",};
static iONode _getvr(iONode node) {
  xNode( RocsWgen_vrlist, node );
  return NodeOp.findNode( node, "vr");
}


static iONode _nextvr(iONode node, iONode child) {
  xNode( RocsWgen_vrlist, node );
  return NodeOp.findNextNode( node, child);
}
static void _setvr(iONode node, iONode p_vr) {
  xNode( RocsWgen_vrlist, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_vrlist.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node vrlist not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node vrlist not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_vr;
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


struct __wVariableList wVariableList = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getvr,
  _nextvr,
  _setvr,
  _node_dump,
};
