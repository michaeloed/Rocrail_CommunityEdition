/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/RocNetNode.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.RocNetNode
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_rocnetnode = {
  "rocnetnode",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_rocnetnode.name;
}
static const char* _node_remark(void) {
  return RocsWgen_rocnetnode.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_rocnetnode.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_rocnetnode.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * class
 */
static struct __attrdef RocsWgen_class = {
  "class",  "Class ID.",  "",  "string",  "",  "",  False,
};
static const char* _getclass(iONode node) {
  const char* defval = xStr( RocsWgen_class );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnode, node );
  return NodeOp.getStr( node, "class", defval );
}
static void _setclass(iONode node, const char* p_class) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnode, node );
  NodeOp.setStr( node, "class", p_class );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "RocNet sender ID.",  "",  "int",  "65535",  "0-*",  False,
};
static int _getid(iONode node) {
  int defval = xInt( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnode, node );
  return NodeOp.getInt( node, "id", defval );
}
static void _setid(iONode node, int p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnode, node );
  NodeOp.setInt( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * location
 */
static struct __attrdef RocsWgen_location = {
  "location",  "RocNet sender ID.",  "",  "int",  "0",  "0-*",  False,
};
static int _getlocation(iONode node) {
  int defval = xInt( RocsWgen_location );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnode, node );
  return NodeOp.getInt( node, "location", defval );
}
static void _setlocation(iONode node, int p_location) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnode, node );
  NodeOp.setInt( node, "location", p_location );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mnemonic
 */
static struct __attrdef RocsWgen_mnemonic = {
  "mnemonic",  "Class Mnemonic.",  "",  "string",  "",  "",  False,
};
static const char* _getmnemonic(iONode node) {
  const char* defval = xStr( RocsWgen_mnemonic );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnode, node );
  return NodeOp.getStr( node, "mnemonic", defval );
}
static void _setmnemonic(iONode node, const char* p_mnemonic) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnode, node );
  NodeOp.setStr( node, "mnemonic", p_mnemonic );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nickname
 */
static struct __attrdef RocsWgen_nickname = {
  "nickname",  "",  "",  "string",  "",  "",  False,
};
static const char* _getnickname(iONode node) {
  const char* defval = xStr( RocsWgen_nickname );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnode, node );
  return NodeOp.getStr( node, "nickname", defval );
}
static void _setnickname(iONode node, const char* p_nickname) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnode, node );
  NodeOp.setStr( node, "nickname", p_nickname );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nrio
 */
static struct __attrdef RocsWgen_nrio = {
  "nrio",  "Number of I/Os",  "",  "int",  "0",  "0-255",  False,
};
static int _getnrio(iONode node) {
  int defval = xInt( RocsWgen_nrio );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnode, node );
  return NodeOp.getInt( node, "nrio", defval );
}
static void _setnrio(iONode node, int p_nrio) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnode, node );
  NodeOp.setInt( node, "nrio", p_nrio );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * pingtick
 */
static struct __attrdef RocsWgen_pingtick = {
  "pingtick",  "",  "",  "long",  "0",  "",  False,
};
static long _getpingtick(iONode node) {
  long defval = xLong( RocsWgen_pingtick );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnode, node );
  return NodeOp.getLong( node, "pingtick", defval );
}
static void _setpingtick(iONode node, long p_pingtick) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnode, node );
  NodeOp.setLong( node, "pingtick", p_pingtick );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * pongtick
 */
static struct __attrdef RocsWgen_pongtick = {
  "pongtick",  "",  "",  "long",  "0",  "",  False,
};
static long _getpongtick(iONode node) {
  long defval = xLong( RocsWgen_pongtick );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnode, node );
  return NodeOp.getLong( node, "pongtick", defval );
}
static void _setpongtick(iONode node, long p_pongtick) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnode, node );
  NodeOp.setLong( node, "pongtick", p_pongtick );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * revision
 */
static struct __attrdef RocsWgen_revision = {
  "revision",  "Repository revision.",  "",  "int",  "0",  "",  False,
};
static int _getrevision(iONode node) {
  int defval = xInt( RocsWgen_revision );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnode, node );
  return NodeOp.getInt( node, "revision", defval );
}
static void _setrevision(iONode node, int p_revision) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnode, node );
  NodeOp.setInt( node, "revision", p_revision );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * subip
 */
static struct __attrdef RocsWgen_subip = {
  "subip",  "Last 16 bits of the IP.",  "",  "int",  "0",  "",  False,
};
static int _getsubip(iONode node) {
  int defval = xInt( RocsWgen_subip );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnode, node );
  return NodeOp.getInt( node, "subip", defval );
}
static void _setsubip(iONode node, int p_subip) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnode, node );
  NodeOp.setInt( node, "subip", p_subip );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * vendor
 */
static struct __attrdef RocsWgen_vendor = {
  "vendor",  "NMRA vendor ID.",  "",  "int",  "0",  "",  False,
};
static int _getvendor(iONode node) {
  int defval = xInt( RocsWgen_vendor );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnode, node );
  return NodeOp.getInt( node, "vendor", defval );
}
static void _setvendor(iONode node, int p_vendor) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnode, node );
  NodeOp.setInt( node, "vendor", p_vendor );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * version
 */
static struct __attrdef RocsWgen_version = {
  "version",  "Software version.",  "",  "string",  "0.0",  "",  False,
};
static const char* _getversion(iONode node) {
  const char* defval = xStr( RocsWgen_version );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnode, node );
  return NodeOp.getStr( node, "version", defval );
}
static void _setversion(iONode node, const char* p_version) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnode, node );
  NodeOp.setStr( node, "version", p_version );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[13] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_rocnetnode.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node rocnetnode not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node rocnetnode not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_class;
  attrList[1] = &RocsWgen_id;
  attrList[2] = &RocsWgen_location;
  attrList[3] = &RocsWgen_mnemonic;
  attrList[4] = &RocsWgen_nickname;
  attrList[5] = &RocsWgen_nrio;
  attrList[6] = &RocsWgen_pingtick;
  attrList[7] = &RocsWgen_pongtick;
  attrList[8] = &RocsWgen_revision;
  attrList[9] = &RocsWgen_subip;
  attrList[10] = &RocsWgen_vendor;
  attrList[11] = &RocsWgen_version;
  attrList[12] = NULL;
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


struct __wRocNetNode wRocNetNode = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getclass,
  _setclass,
  _getid,
  _setid,
  _getlocation,
  _setlocation,
  _getmnemonic,
  _setmnemonic,
  _getnickname,
  _setnickname,
  _getnrio,
  _setnrio,
  _getpingtick,
  _setpingtick,
  _getpongtick,
  _setpongtick,
  _getrevision,
  _setrevision,
  _getsubip,
  _setsubip,
  _getvendor,
  _setvendor,
  _getversion,
  _setversion,
  _node_dump,
};
