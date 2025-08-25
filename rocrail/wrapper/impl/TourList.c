/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/TourList.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.TourList
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_tourlist = {
  "tourlist",  "Tour table",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_tourlist.name;
}
static const char* _node_remark(void) {
  return RocsWgen_tourlist.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_tourlist.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_tourlist.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * tour
 */
static struct __nodedef RocsWgen_tour = {
  "tour",  "",  False,  "n",};
static iONode _gettour(iONode node) {
  xNode( RocsWgen_tourlist, node );
  return NodeOp.findNode( node, "tour");
}


static iONode _nexttour(iONode node, iONode child) {
  xNode( RocsWgen_tourlist, node );
  return NodeOp.findNextNode( node, child);
}
static void _settour(iONode node, iONode p_tour) {
  xNode( RocsWgen_tourlist, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_tourlist.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node tourlist not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node tourlist not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_tour;
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


struct __wTourList wTourList = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _gettour,
  _nexttour,
  _settour,
  _node_dump,
};
