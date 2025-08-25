/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/StageList.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.StageList
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_sblist = {
  "sblist",  "Staging Yard Table",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_sblist.name;
}
static const char* _node_remark(void) {
  return RocsWgen_sblist.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_sblist.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_sblist.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * sb
 */
static struct __nodedef RocsWgen_sb = {
  "sb",  "",  False,  "n",};
static iONode _getsb(iONode node) {
  xNode( RocsWgen_sblist, node );
  return NodeOp.findNode( node, "sb");
}


static iONode _nextsb(iONode node, iONode child) {
  xNode( RocsWgen_sblist, node );
  return NodeOp.findNextNode( node, child);
}
static void _setsb(iONode node, iONode p_sb) {
  xNode( RocsWgen_sblist, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_sblist.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node sblist not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node sblist not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_sb;
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


struct __wStageList wStageList = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getsb,
  _nextsb,
  _setsb,
  _node_dump,
};
