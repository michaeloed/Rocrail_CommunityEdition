/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#include "rocview/wrapper/public/Patch.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.Patch
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_patch = {
  "patch",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_patch.name;
}
static const char* _node_remark(void) {
  return RocsWgen_patch.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_patch.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_patch.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * download
 */
static struct __attrdef RocsWgen_download = {
  "download",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isdownload(iONode node) {
  Boolean defval = xBool( RocsWgen_download );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_patch, node );
  return NodeOp.getBool( node, "download", defval );
}
static void _setdownload(iONode node, Boolean p_download) {
  if( node == NULL ) return;
  xNode( RocsWgen_patch, node );
  NodeOp.setBool( node, "download", p_download );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * file
 */
static struct __attrdef RocsWgen_file = {
  "file",  "",  "",  "string",  "",  "",  False,
};
static const char* _getfile(iONode node) {
  const char* defval = xStr( RocsWgen_file );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_patch, node );
  return NodeOp.getStr( node, "file", defval );
}
static void _setfile(iONode node, const char* p_file) {
  if( node == NULL ) return;
  xNode( RocsWgen_patch, node );
  NodeOp.setStr( node, "file", p_file );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nr
 */
static struct __attrdef RocsWgen_nr = {
  "nr",  "",  "",  "int",  "0",  "",  False,
};
static int _getnr(iONode node) {
  int defval = xInt( RocsWgen_nr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_patch, node );
  return NodeOp.getInt( node, "nr", defval );
}
static void _setnr(iONode node, int p_nr) {
  if( node == NULL ) return;
  xNode( RocsWgen_patch, node );
  NodeOp.setInt( node, "nr", p_nr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * os
 */
static struct __attrdef RocsWgen_os = {
  "os",  "",  "",  "string",  "",  "",  False,
};
static const char* _getos(iONode node) {
  const char* defval = xStr( RocsWgen_os );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_patch, node );
  return NodeOp.getStr( node, "os", defval );
}
static void _setos(iONode node, const char* p_os) {
  if( node == NULL ) return;
  xNode( RocsWgen_patch, node );
  NodeOp.setStr( node, "os", p_os );
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
  xNode( RocsWgen_patch, node );
  return NodeOp.getStr( node, "remark", defval );
}
static void _setremark(iONode node, const char* p_remark) {
  if( node == NULL ) return;
  xNode( RocsWgen_patch, node );
  NodeOp.setStr( node, "remark", p_remark );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[6] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_patch.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node patch not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node patch not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_download;
  attrList[1] = &RocsWgen_file;
  attrList[2] = &RocsWgen_nr;
  attrList[3] = &RocsWgen_os;
  attrList[4] = &RocsWgen_remark;
  attrList[5] = NULL;
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


struct __wPatch wPatch = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isdownload,
  _setdownload,
  _getfile,
  _setfile,
  _getnr,
  _setnr,
  _getos,
  _setos,
  _getremark,
  _setremark,
  _node_dump,
};
