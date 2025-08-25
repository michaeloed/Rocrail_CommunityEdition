/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/DirEntry.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.DirEntry
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_direntry = {
  "direntry",  "Directory",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_direntry.name;
}
static const char* _node_remark(void) {
  return RocsWgen_direntry.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_direntry.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_direntry.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * dir
 */
static struct __attrdef RocsWgen_dir = {
  "dir",  "File name",  "",  "string",  "",  "*",  False,
};
static const char* _getdir(iONode node) {
  const char* defval = xStr( RocsWgen_dir );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_direntry, node );
  return NodeOp.getStr( node, "dir", defval );
}
static void _setdir(iONode node, const char* p_dir) {
  if( node == NULL ) return;
  xNode( RocsWgen_direntry, node );
  NodeOp.setStr( node, "dir", p_dir );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * fileentry
 */
static struct __nodedef RocsWgen_fileentry = {
  "fileentry",  "",  False,  "n",};
static iONode _getfileentry(iONode node) {
  xNode( RocsWgen_direntry, node );
  return NodeOp.findNode( node, "fileentry");
}


static iONode _nextfileentry(iONode node, iONode child) {
  xNode( RocsWgen_direntry, node );
  return NodeOp.findNextNode( node, child);
}
static void _setfileentry(iONode node, iONode p_fileentry) {
  xNode( RocsWgen_direntry, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[2] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_direntry.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node direntry not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node direntry not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_dir;
  attrList[1] = NULL;
  nodeList[0] = &RocsWgen_fileentry;
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


struct __wDirEntry wDirEntry = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getdir,
  _setdir,
  _getfileentry,
  _nextfileentry,
  _setfileentry,
  _node_dump,
};
