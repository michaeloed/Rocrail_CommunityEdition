/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/WaybillList.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.WaybillList
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_waybilllist = {
  "waybilllist",  "Waybill table",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_waybilllist.name;
}
static const char* _node_remark(void) {
  return RocsWgen_waybilllist.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_waybilllist.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_waybilllist.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * waybill
 */
static struct __nodedef RocsWgen_waybill = {
  "waybill",  "Waybill definition.",  False,  "n",};
static iONode _getwaybill(iONode node) {
  xNode( RocsWgen_waybilllist, node );
  return NodeOp.findNode( node, "waybill");
}


static iONode _nextwaybill(iONode node, iONode child) {
  xNode( RocsWgen_waybilllist, node );
  return NodeOp.findNextNode( node, child);
}
static void _setwaybill(iONode node, iONode p_waybill) {
  xNode( RocsWgen_waybilllist, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_waybilllist.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node waybilllist not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node waybilllist not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_waybill;
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


struct __wWaybillList wWaybillList = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getwaybill,
  _nextwaybill,
  _setwaybill,
  _node_dump,
};
