/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/LocationList.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.LocationList
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_locationlist = {
  "locationlist",  "Location table",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_locationlist.name;
}
static const char* _node_remark(void) {
  return RocsWgen_locationlist.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_locationlist.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_locationlist.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * location
 */
static struct __nodedef RocsWgen_location = {
  "location",  "",  False,  "n",};
static iONode _getlocation(iONode node) {
  xNode( RocsWgen_locationlist, node );
  return NodeOp.findNode( node, "location");
}


static iONode _nextlocation(iONode node, iONode child) {
  xNode( RocsWgen_locationlist, node );
  return NodeOp.findNextNode( node, child);
}
static void _setlocation(iONode node, iONode p_location) {
  xNode( RocsWgen_locationlist, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_locationlist.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node locationlist not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node locationlist not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_location;
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


struct __wLocationList wLocationList = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getlocation,
  _nextlocation,
  _setlocation,
  _node_dump,
};
