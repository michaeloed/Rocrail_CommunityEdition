/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#include "rocview/wrapper/public/Release.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.Release
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_release = {
  "release",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_release.name;
}
static const char* _node_remark(void) {
  return RocsWgen_release.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_release.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_release.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * alias
 */
static struct __attrdef RocsWgen_alias = {
  "alias",  "",  "",  "string",  "Harvest",  "",  False,
};
static const char* _getalias(iONode node) {
  const char* defval = xStr( RocsWgen_alias );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_release, node );
  return NodeOp.getStr( node, "alias", defval );
}
static void _setalias(iONode node, const char* p_alias) {
  if( node == NULL ) return;
  xNode( RocsWgen_release, node );
  NodeOp.setStr( node, "alias", p_alias );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * remark
 */
static struct __attrdef RocsWgen_remark = {
  "remark",  "",  "",  "string",  "",  "",  False,
};
static const char* _getremark(iONode node) {
  const char* defval = xStr( RocsWgen_remark );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_release, node );
  return NodeOp.getStr( node, "remark", defval );
}
static void _setremark(iONode node, const char* p_remark) {
  if( node == NULL ) return;
  xNode( RocsWgen_release, node );
  NodeOp.setStr( node, "remark", p_remark );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timestamp
 */
static struct __attrdef RocsWgen_timestamp = {
  "timestamp",  "",  "",  "long",  "0",  "",  False,
};
static long _gettimestamp(iONode node) {
  long defval = xLong( RocsWgen_timestamp );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_release, node );
  return NodeOp.getLong( node, "timestamp", defval );
}
static void _settimestamp(iONode node, long p_timestamp) {
  if( node == NULL ) return;
  xNode( RocsWgen_release, node );
  NodeOp.setLong( node, "timestamp", p_timestamp );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * version
 */
static struct __attrdef RocsWgen_version = {
  "version",  "",  "",  "string",  "1.0",  "",  False,
};
static const char* _getversion(iONode node) {
  const char* defval = xStr( RocsWgen_version );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_release, node );
  return NodeOp.getStr( node, "version", defval );
}
static void _setversion(iONode node, const char* p_version) {
  if( node == NULL ) return;
  xNode( RocsWgen_release, node );
  NodeOp.setStr( node, "version", p_version );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * patch
 */
static struct __nodedef RocsWgen_patch = {
  "patch",  "",  False,  "n",};
static iONode _getpatch(iONode node) {
  xNode( RocsWgen_release, node );
  return NodeOp.findNode( node, "patch");
}


static iONode _nextpatch(iONode node, iONode child) {
  xNode( RocsWgen_release, node );
  return NodeOp.findNextNode( node, child);
}
static void _setpatch(iONode node, iONode p_patch) {
  xNode( RocsWgen_release, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[5] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_release.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node release not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node release not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_alias;
  attrList[1] = &RocsWgen_remark;
  attrList[2] = &RocsWgen_timestamp;
  attrList[3] = &RocsWgen_version;
  attrList[4] = NULL;
  nodeList[0] = &RocsWgen_patch;
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


struct __wRelease wRelease = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getalias,
  _setalias,
  _getremark,
  _setremark,
  _gettimestamp,
  _settimestamp,
  _getversion,
  _setversion,
  _getpatch,
  _nextpatch,
  _setpatch,
  _node_dump,
};
