/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:52 2018
  */

#include "rocview/wrapper/public/WorkSpace.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.WorkSpace
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_workspace = {
  "workspace",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_workspace.name;
}
static const char* _node_remark(void) {
  return RocsWgen_workspace.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_workspace.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_workspace.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * path
 */
static struct __attrdef RocsWgen_path = {
  "path",  "",  "",  "string",  "",  "",  False,
};
static const char* _getpath(iONode node) {
  const char* defval = xStr( RocsWgen_path );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_workspace, node );
  return NodeOp.getStr( node, "path", defval );
}
static void _setpath(iONode node, const char* p_path) {
  if( node == NULL ) return;
  xNode( RocsWgen_workspace, node );
  NodeOp.setStr( node, "path", p_path );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * title
 */
static struct __attrdef RocsWgen_title = {
  "title",  "",  "",  "string",  "New",  "",  False,
};
static const char* _gettitle(iONode node) {
  const char* defval = xStr( RocsWgen_title );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_workspace, node );
  return NodeOp.getStr( node, "title", defval );
}
static void _settitle(iONode node, const char* p_title) {
  if( node == NULL ) return;
  xNode( RocsWgen_workspace, node );
  NodeOp.setStr( node, "title", p_title );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[3] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_workspace.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node workspace not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node workspace not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_path;
  attrList[1] = &RocsWgen_title;
  attrList[2] = NULL;
  nodeList[0] = NULL;
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


struct __wWorkSpace wWorkSpace = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getpath,
  _setpath,
  _gettitle,
  _settitle,
  _node_dump,
};
