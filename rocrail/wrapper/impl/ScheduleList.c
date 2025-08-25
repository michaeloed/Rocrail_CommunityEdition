/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/ScheduleList.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.ScheduleList
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_sclist = {
  "sclist",  "Schedule table",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_sclist.name;
}
static const char* _node_remark(void) {
  return RocsWgen_sclist.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_sclist.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_sclist.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * sc
 */
static struct __nodedef RocsWgen_sc = {
  "sc",  "",  False,  "n",};
static iONode _getsc(iONode node) {
  xNode( RocsWgen_sclist, node );
  return NodeOp.findNode( node, "sc");
}


static iONode _nextsc(iONode node, iONode child) {
  xNode( RocsWgen_sclist, node );
  return NodeOp.findNextNode( node, child);
}
static void _setsc(iONode node, iONode p_sc) {
  xNode( RocsWgen_sclist, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_sclist.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node sclist not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node sclist not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_sc;
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


struct __wScheduleList wScheduleList = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getsc,
  _nextsc,
  _setsc,
  _node_dump,
};
