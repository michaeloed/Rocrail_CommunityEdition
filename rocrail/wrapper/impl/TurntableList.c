/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/TurntableList.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.TurntableList
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_ttlist = {
  "ttlist",  "Turntable",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_ttlist.name;
}
static const char* _node_remark(void) {
  return RocsWgen_ttlist.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_ttlist.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_ttlist.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * tt
 */
static struct __nodedef RocsWgen_tt = {
  "tt",  "Turntable definition.",  False,  "n",};
static iONode _gettt(iONode node) {
  xNode( RocsWgen_ttlist, node );
  return NodeOp.findNode( node, "tt");
}


static iONode _nexttt(iONode node, iONode child) {
  xNode( RocsWgen_ttlist, node );
  return NodeOp.findNextNode( node, child);
}
static void _settt(iONode node, iONode p_tt) {
  xNode( RocsWgen_ttlist, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_ttlist.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node ttlist not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node ttlist not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_tt;
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


struct __wTurntableList wTurntableList = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _gettt,
  _nexttt,
  _settt,
  _node_dump,
};
