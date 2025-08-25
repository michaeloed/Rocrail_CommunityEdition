/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:52 2018
  */

#include "rocview/wrapper/public/WorkSpaces.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.WorkSpaces
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_workspaces = {
  "workspaces",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_workspaces.name;
}
static const char* _node_remark(void) {
  return RocsWgen_workspaces.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_workspaces.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_workspaces.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * workspace
 */
static struct __nodedef RocsWgen_workspace = {
  "workspace",  "",  False,  "n",};
static iONode _getworkspace(iONode node) {
  xNode( RocsWgen_workspaces, node );
  return NodeOp.findNode( node, "workspace");
}


static iONode _nextworkspace(iONode node, iONode child) {
  xNode( RocsWgen_workspaces, node );
  return NodeOp.findNextNode( node, child);
}
static void _setworkspace(iONode node, iONode p_workspace) {
  xNode( RocsWgen_workspaces, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_workspaces.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node workspaces not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node workspaces not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_workspace;
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


struct __wWorkSpaces wWorkSpaces = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getworkspace,
  _nextworkspace,
  _setworkspace,
  _node_dump,
};
