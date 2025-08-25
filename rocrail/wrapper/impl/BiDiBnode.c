/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/BiDiBnode.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.BiDiBnode
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_bidibnode = {
  "bidibnode",  "BiDiB options",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_bidibnode.name;
}
static const char* _node_remark(void) {
  return RocsWgen_bidibnode.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_bidibnode.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_bidibnode.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * analogcnt
 */
static struct __attrdef RocsWgen_analogcnt = {
  "analogcnt",  "Number of ports.",  "",  "int",  "0",  "",  False,
};
static int _getanalogcnt(iONode node) {
  int defval = xInt( RocsWgen_analogcnt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getInt( node, "analogcnt", defval );
}
static void _setanalogcnt(iONode node, int p_analogcnt) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setInt( node, "analogcnt", p_analogcnt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * class
 */
static struct __attrdef RocsWgen_class = {
  "class",  "Class ID.",  "",  "string",  "sensor",  "",  False,
};
static const char* _getclass(iONode node) {
  const char* defval = xStr( RocsWgen_class );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getStr( node, "class", defval );
}
static void _setclass(iONode node, const char* p_class) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setStr( node, "class", p_class );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * classmnemonic
 */
static struct __attrdef RocsWgen_classmnemonic = {
  "classmnemonic",  "Class ID mnemonic.",  "",  "string",  "sensor",  "",  False,
};
static const char* _getclassmnemonic(iONode node) {
  const char* defval = xStr( RocsWgen_classmnemonic );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getStr( node, "classmnemonic", defval );
}
static void _setclassmnemonic(iONode node, const char* p_classmnemonic) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setStr( node, "classmnemonic", p_classmnemonic );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fwup
 */
static struct __attrdef RocsWgen_fwup = {
  "fwup",  "Firmware update flag.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isfwup(iONode node) {
  Boolean defval = xBool( RocsWgen_fwup );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getBool( node, "fwup", defval );
}
static void _setfwup(iONode node, Boolean p_fwup) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setBool( node, "fwup", p_fwup );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * inputcnt
 */
static struct __attrdef RocsWgen_inputcnt = {
  "inputcnt",  "Number of ports.",  "",  "int",  "0",  "",  False,
};
static int _getinputcnt(iONode node) {
  int defval = xInt( RocsWgen_inputcnt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getInt( node, "inputcnt", defval );
}
static void _setinputcnt(iONode node, int p_inputcnt) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setInt( node, "inputcnt", p_inputcnt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iocfg
 */
static struct __attrdef RocsWgen_iocfg = {
  "iocfg",  "Port config flag.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isiocfg(iONode node) {
  Boolean defval = xBool( RocsWgen_iocfg );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getBool( node, "iocfg", defval );
}
static void _setiocfg(iONode node, Boolean p_iocfg) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setBool( node, "iocfg", p_iocfg );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * key
 */
static struct __attrdef RocsWgen_key = {
  "key",  "",  "",  "string",  "",  "",  False,
};
static const char* _getkey(iONode node) {
  const char* defval = xStr( RocsWgen_key );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getStr( node, "key", defval );
}
static void _setkey(iONode node, const char* p_key) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setStr( node, "key", p_key );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lportcnt
 */
static struct __attrdef RocsWgen_lportcnt = {
  "lportcnt",  "Number of ports.",  "",  "int",  "0",  "",  False,
};
static int _getlportcnt(iONode node) {
  int defval = xInt( RocsWgen_lportcnt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getInt( node, "lportcnt", defval );
}
static void _setlportcnt(iONode node, int p_lportcnt) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setInt( node, "lportcnt", p_lportcnt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * motorcnt
 */
static struct __attrdef RocsWgen_motorcnt = {
  "motorcnt",  "Number of ports.",  "",  "int",  "0",  "",  False,
};
static int _getmotorcnt(iONode node) {
  int defval = xInt( RocsWgen_motorcnt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getInt( node, "motorcnt", defval );
}
static void _setmotorcnt(iONode node, int p_motorcnt) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setInt( node, "motorcnt", p_motorcnt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * parentkey
 */
static struct __attrdef RocsWgen_parentkey = {
  "parentkey",  "",  "",  "string",  "",  "",  False,
};
static const char* _getparentkey(iONode node) {
  const char* defval = xStr( RocsWgen_parentkey );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getStr( node, "parentkey", defval );
}
static void _setparentkey(iONode node, const char* p_parentkey) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setStr( node, "parentkey", p_parentkey );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * path
 */
static struct __attrdef RocsWgen_path = {
  "path",  "Local path.",  "",  "string",  "0.0.0.0",  "",  False,
};
static const char* _getpath(iONode node) {
  const char* defval = xStr( RocsWgen_path );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getStr( node, "path", defval );
}
static void _setpath(iONode node, const char* p_path) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setStr( node, "path", p_path );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * productname
 */
static struct __attrdef RocsWgen_productname = {
  "productname",  "",  "",  "string",  "",  "",  False,
};
static const char* _getproductname(iONode node) {
  const char* defval = xStr( RocsWgen_productname );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getStr( node, "productname", defval );
}
static void _setproductname(iONode node, const char* p_productname) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setStr( node, "productname", p_productname );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sensorcnt
 */
static struct __attrdef RocsWgen_sensorcnt = {
  "sensorcnt",  "Number of sensors.",  "",  "int",  "0",  "",  False,
};
static int _getsensorcnt(iONode node) {
  int defval = xInt( RocsWgen_sensorcnt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getInt( node, "sensorcnt", defval );
}
static void _setsensorcnt(iONode node, int p_sensorcnt) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setInt( node, "sensorcnt", p_sensorcnt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * servocnt
 */
static struct __attrdef RocsWgen_servocnt = {
  "servocnt",  "Number of ports.",  "",  "int",  "0",  "",  False,
};
static int _getservocnt(iONode node) {
  int defval = xInt( RocsWgen_servocnt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getInt( node, "servocnt", defval );
}
static void _setservocnt(iONode node, int p_servocnt) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setInt( node, "servocnt", p_servocnt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * soundcnt
 */
static struct __attrdef RocsWgen_soundcnt = {
  "soundcnt",  "Number of ports.",  "",  "int",  "0",  "",  False,
};
static int _getsoundcnt(iONode node) {
  int defval = xInt( RocsWgen_soundcnt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getInt( node, "soundcnt", defval );
}
static void _setsoundcnt(iONode node, int p_soundcnt) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setInt( node, "soundcnt", p_soundcnt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sportcnt
 */
static struct __attrdef RocsWgen_sportcnt = {
  "sportcnt",  "Number of ports.",  "",  "int",  "0",  "",  False,
};
static int _getsportcnt(iONode node) {
  int defval = xInt( RocsWgen_sportcnt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getInt( node, "sportcnt", defval );
}
static void _setsportcnt(iONode node, int p_sportcnt) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setInt( node, "sportcnt", p_sportcnt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * uid
 */
static struct __attrdef RocsWgen_uid = {
  "uid",  "Vendor product/serialnumber ID.",  "",  "int",  "0",  "",  False,
};
static int _getuid(iONode node) {
  int defval = xInt( RocsWgen_uid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getInt( node, "uid", defval );
}
static void _setuid(iONode node, int p_uid) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setInt( node, "uid", p_uid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * username
 */
static struct __attrdef RocsWgen_username = {
  "username",  "",  "",  "string",  "",  "",  False,
};
static const char* _getusername(iONode node) {
  const char* defval = xStr( RocsWgen_username );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getStr( node, "username", defval );
}
static void _setusername(iONode node, const char* p_username) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setStr( node, "username", p_username );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * vendor
 */
static struct __attrdef RocsWgen_vendor = {
  "vendor",  "DCC vendor ID.",  "",  "int",  "0",  "",  False,
};
static int _getvendor(iONode node) {
  int defval = xInt( RocsWgen_vendor );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getInt( node, "vendor", defval );
}
static void _setvendor(iONode node, int p_vendor) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setInt( node, "vendor", p_vendor );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * version
 */
static struct __attrdef RocsWgen_version = {
  "version",  "Software version.",  "",  "string",  "",  "",  False,
};
static const char* _getversion(iONode node) {
  const char* defval = xStr( RocsWgen_version );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidibnode, node );
  return NodeOp.getStr( node, "version", defval );
}
static void _setversion(iONode node, const char* p_version) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidibnode, node );
  NodeOp.setStr( node, "version", p_version );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[21] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_bidibnode.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node bidibnode not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node bidibnode not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_analogcnt;
  attrList[1] = &RocsWgen_class;
  attrList[2] = &RocsWgen_classmnemonic;
  attrList[3] = &RocsWgen_fwup;
  attrList[4] = &RocsWgen_inputcnt;
  attrList[5] = &RocsWgen_iocfg;
  attrList[6] = &RocsWgen_key;
  attrList[7] = &RocsWgen_lportcnt;
  attrList[8] = &RocsWgen_motorcnt;
  attrList[9] = &RocsWgen_parentkey;
  attrList[10] = &RocsWgen_path;
  attrList[11] = &RocsWgen_productname;
  attrList[12] = &RocsWgen_sensorcnt;
  attrList[13] = &RocsWgen_servocnt;
  attrList[14] = &RocsWgen_soundcnt;
  attrList[15] = &RocsWgen_sportcnt;
  attrList[16] = &RocsWgen_uid;
  attrList[17] = &RocsWgen_username;
  attrList[18] = &RocsWgen_vendor;
  attrList[19] = &RocsWgen_version;
  attrList[20] = NULL;
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


struct __wBiDiBnode wBiDiBnode = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "accessory",
  "booster",
  "bridge",
  "dcc_main",
  "dcc_prog",
  "sensor",
  "switch",
  "ui",
  _getanalogcnt,
  _setanalogcnt,
  _getclass,
  _setclass,
  _getclassmnemonic,
  _setclassmnemonic,
  _isfwup,
  _setfwup,
  _getinputcnt,
  _setinputcnt,
  _isiocfg,
  _setiocfg,
  _getkey,
  _setkey,
  _getlportcnt,
  _setlportcnt,
  _getmotorcnt,
  _setmotorcnt,
  _getparentkey,
  _setparentkey,
  _getpath,
  _setpath,
  _getproductname,
  _setproductname,
  _getsensorcnt,
  _setsensorcnt,
  _getservocnt,
  _setservocnt,
  _getsoundcnt,
  _setsoundcnt,
  _getsportcnt,
  _setsportcnt,
  _getuid,
  _setuid,
  _getusername,
  _setusername,
  _getvendor,
  _setvendor,
  _getversion,
  _setversion,
  _node_dump,
};
