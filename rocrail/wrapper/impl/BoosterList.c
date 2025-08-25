/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/BoosterList.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.BoosterList
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_boosterlist = {
  "boosterlist",  "Booster list for power management",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_boosterlist.name;
}
static const char* _node_remark(void) {
  return RocsWgen_boosterlist.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_boosterlist.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_boosterlist.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * booster
 */
static struct __nodedef RocsWgen_booster = {
  "booster",  "Booster definition",  False,  "n",};
static iONode _getbooster(iONode node) {
  xNode( RocsWgen_boosterlist, node );
  return NodeOp.findNode( node, "booster");
}


static iONode _nextbooster(iONode node, iONode child) {
  xNode( RocsWgen_boosterlist, node );
  return NodeOp.findNextNode( node, child);
}
static void _setbooster(iONode node, iONode p_booster) {
  xNode( RocsWgen_boosterlist, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_boosterlist.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node boosterlist not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node boosterlist not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_booster;
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


struct __wBoosterList wBoosterList = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getbooster,
  _nextbooster,
  _setbooster,
  _node_dump,
};
