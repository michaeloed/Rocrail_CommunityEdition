/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/SysCmd.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.SysCmd
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_sys = {
  "sys",  "System command.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_sys.name;
}
static const char* _node_remark(void) {
  return RocsWgen_sys.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_sys.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_sys.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr
 */
static struct __attrdef RocsWgen_addr = {
  "addr",  "Interface address",  "",  "int",  "0",  "0-*",  False,
};
static int _getaddr(iONode node) {
  int defval = xInt( RocsWgen_addr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sys, node );
  return NodeOp.getInt( node, "addr", defval );
}
static void _setaddr(iONode node, int p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_sys, node );
  NodeOp.setInt( node, "addr", p_addr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * arch
 */
static struct __attrdef RocsWgen_arch = {
  "arch",  "Hardware architecture",  "",  "string",  "i386",  "*",  False,
};
static const char* _getarch(iONode node) {
  const char* defval = xStr( RocsWgen_arch );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sys, node );
  return NodeOp.getStr( node, "arch", defval );
}
static void _setarch(iONode node, const char* p_arch) {
  if( node == NULL ) return;
  xNode( RocsWgen_sys, node );
  NodeOp.setStr( node, "arch", p_arch );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bus
 */
static struct __attrdef RocsWgen_bus = {
  "bus",  "Interface bus",  "",  "int",  "0",  "0-*",  False,
};
static int _getbus(iONode node) {
  int defval = xInt( RocsWgen_bus );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sys, node );
  return NodeOp.getInt( node, "bus", defval );
}
static void _setbus(iONode node, int p_bus) {
  if( node == NULL ) return;
  xNode( RocsWgen_sys, node );
  NodeOp.setInt( node, "bus", p_bus );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmd
 */
static struct __attrdef RocsWgen_cmd = {
  "cmd",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getcmd(iONode node) {
  const char* defval = xStr( RocsWgen_cmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sys, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_sys, node );
  NodeOp.setStr( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * dist
 */
static struct __attrdef RocsWgen_dist = {
  "dist",  "Distribution name",  "",  "string",  "debian6",  "*",  False,
};
static const char* _getdist(iONode node) {
  const char* defval = xStr( RocsWgen_dist );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sys, node );
  return NodeOp.getStr( node, "dist", defval );
}
static void _setdist(iONode node, const char* p_dist) {
  if( node == NULL ) return;
  xNode( RocsWgen_sys, node );
  NodeOp.setStr( node, "dist", p_dist );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "ID",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sys, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_sys, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iid
 */
static struct __attrdef RocsWgen_iid = {
  "iid",  "Interface ID",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getiid(iONode node) {
  const char* defval = xStr( RocsWgen_iid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sys, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_sys, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * informall
 */
static struct __attrdef RocsWgen_informall = {
  "informall",  "send command to all interfaces",  "",  "bool",  "false",  "",  False,
};
static Boolean _isinformall(iONode node) {
  Boolean defval = xBool( RocsWgen_informall );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sys, node );
  return NodeOp.getBool( node, "informall", defval );
}
static void _setinformall(iONode node, Boolean p_informall) {
  if( node == NULL ) return;
  xNode( RocsWgen_sys, node );
  NodeOp.setBool( node, "informall", p_informall );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * oid
 */
static struct __attrdef RocsWgen_oid = {
  "oid",  "Object ID",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getoid(iONode node) {
  const char* defval = xStr( RocsWgen_oid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sys, node );
  return NodeOp.getStr( node, "oid", defval );
}
static void _setoid(iONode node, const char* p_oid) {
  if( node == NULL ) return;
  xNode( RocsWgen_sys, node );
  NodeOp.setStr( node, "oid", p_oid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "Interface port",  "",  "int",  "0",  "0-*",  False,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sys, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_sys, node );
  NodeOp.setInt( node, "port", p_port );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val
 */
static struct __attrdef RocsWgen_val = {
  "val",  "optional value",  "",  "int",  "0",  "*",  False,
};
static int _getval(iONode node) {
  int defval = xInt( RocsWgen_val );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sys, node );
  return NodeOp.getInt( node, "val", defval );
}
static void _setval(iONode node, int p_val) {
  if( node == NULL ) return;
  xNode( RocsWgen_sys, node );
  NodeOp.setInt( node, "val", p_val );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * valA
 */
static struct __attrdef RocsWgen_valA = {
  "valA",  "optional value",  "",  "int",  "0",  "*",  False,
};
static int _getvalA(iONode node) {
  int defval = xInt( RocsWgen_valA );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sys, node );
  return NodeOp.getInt( node, "valA", defval );
}
static void _setvalA(iONode node, int p_valA) {
  if( node == NULL ) return;
  xNode( RocsWgen_sys, node );
  NodeOp.setInt( node, "valA", p_valA );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * valB
 */
static struct __attrdef RocsWgen_valB = {
  "valB",  "optional value",  "",  "int",  "0",  "*",  False,
};
static int _getvalB(iONode node) {
  int defval = xInt( RocsWgen_valB );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sys, node );
  return NodeOp.getInt( node, "valB", defval );
}
static void _setvalB(iONode node, int p_valB) {
  if( node == NULL ) return;
  xNode( RocsWgen_sys, node );
  NodeOp.setInt( node, "valB", p_valB );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[14] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_sys.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node sys not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node sys not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_addr;
  attrList[1] = &RocsWgen_arch;
  attrList[2] = &RocsWgen_bus;
  attrList[3] = &RocsWgen_cmd;
  attrList[4] = &RocsWgen_dist;
  attrList[5] = &RocsWgen_id;
  attrList[6] = &RocsWgen_iid;
  attrList[7] = &RocsWgen_informall;
  attrList[8] = &RocsWgen_oid;
  attrList[9] = &RocsWgen_port;
  attrList[10] = &RocsWgen_val;
  attrList[11] = &RocsWgen_valA;
  attrList[12] = &RocsWgen_valB;
  attrList[13] = NULL;
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


struct __wSysCmd wSysCmd = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "analog",
  "analyze",
  "clearshortids",
  "config",
  "dcc",
  "ebreak",
  "enablecom",
  "getini",
  "getmodplan",
  "getmodule",
  "getstate",
  "go",
  "grouplink",
  "hfi",
  "info",
  "init",
  "link",
  "loccnfg",
  "reset",
  "resetblock",
  "resetfx",
  "resetstat",
  "save",
  "setini",
  "setmodplan",
  "setmodule",
  "shutdown",
  "shutdownnode",
  "slots",
  "sod",
  "stop",
  "stoplocs",
  "swcnfg",
  "test",
  "txshortids",
  "ulink",
  "updateserver",
  "version",
  "weather",
  _getaddr,
  _setaddr,
  _getarch,
  _setarch,
  _getbus,
  _setbus,
  _getcmd,
  _setcmd,
  _getdist,
  _setdist,
  _getid,
  _setid,
  _getiid,
  _setiid,
  _isinformall,
  _setinformall,
  _getoid,
  _setoid,
  _getport,
  _setport,
  _getval,
  _setval,
  _getvalA,
  _setvalA,
  _getvalB,
  _setvalB,
  _node_dump,
};
