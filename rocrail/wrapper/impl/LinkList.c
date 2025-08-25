/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/LinkList.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.LinkList
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_linklist = {
  "linklist",  "Block Link table",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_linklist.name;
}
static const char* _node_remark(void) {
  return RocsWgen_linklist.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_linklist.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_linklist.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * link
 */
static struct __nodedef RocsWgen_link = {
  "link",  "in case of critsect the src is ignored and all blocks listed in dst are group members",  False,  "n",};
static iONode _getlink(iONode node) {
  xNode( RocsWgen_linklist, node );
  return NodeOp.findNode( node, "link");
}


static iONode _nextlink(iONode node, iONode child) {
  xNode( RocsWgen_linklist, node );
  return NodeOp.findNextNode( node, child);
}
static void _setlink(iONode node, iONode p_link) {
  xNode( RocsWgen_linklist, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_linklist.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node linklist not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node linklist not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_link;
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


struct __wLinkList wLinkList = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getlink,
  _nextlink,
  _setlink,
  _node_dump,
};
