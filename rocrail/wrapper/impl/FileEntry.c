/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/FileEntry.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.FileEntry
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_fileentry = {
  "fileentry",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_fileentry.name;
}
static const char* _node_remark(void) {
  return RocsWgen_fileentry.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_fileentry.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_fileentry.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fname
 */
static struct __attrdef RocsWgen_fname = {
  "fname",  "File name",  "",  "string",  "",  "*",  False,
};
static const char* _getfname(iONode node) {
  const char* defval = xStr( RocsWgen_fname );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fileentry, node );
  return NodeOp.getStr( node, "fname", defval );
}
static void _setfname(iONode node, const char* p_fname) {
  if( node == NULL ) return;
  xNode( RocsWgen_fileentry, node );
  NodeOp.setStr( node, "fname", p_fname );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * size
 */
static struct __attrdef RocsWgen_size = {
  "size",  "File size",  "",  "long",  "0",  "0-*",  False,
};
static long _getsize(iONode node) {
  long defval = xLong( RocsWgen_size );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fileentry, node );
  return NodeOp.getLong( node, "size", defval );
}
static void _setsize(iONode node, long p_size) {
  if( node == NULL ) return;
  xNode( RocsWgen_fileentry, node );
  NodeOp.setLong( node, "size", p_size );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * time
 */
static struct __attrdef RocsWgen_time = {
  "time",  "Time stamp",  "",  "string",  "",  "*",  False,
};
static const char* _gettime(iONode node) {
  const char* defval = xStr( RocsWgen_time );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fileentry, node );
  return NodeOp.getStr( node, "time", defval );
}
static void _settime(iONode node, const char* p_time) {
  if( node == NULL ) return;
  xNode( RocsWgen_fileentry, node );
  NodeOp.setStr( node, "time", p_time );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[4] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_fileentry.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node fileentry not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node fileentry not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_fname;
  attrList[1] = &RocsWgen_size;
  attrList[2] = &RocsWgen_time;
  attrList[3] = NULL;
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


struct __wFileEntry wFileEntry = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getfname,
  _setfname,
  _getsize,
  _setsize,
  _gettime,
  _settime,
  _node_dump,
};
