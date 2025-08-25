/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/R2RnetIni.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.R2RnetIni
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_r2rnet = {
  "r2rnet",  "Setup for the R2RNet.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_r2rnet.name;
}
static const char* _node_remark(void) {
  return RocsWgen_r2rnet.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_r2rnet.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_r2rnet.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr
 */
static struct __attrdef RocsWgen_addr = {
  "addr",  "multicast address",  "",  "string",  "224.0.0.1",  "*",  False,
};
static const char* _getaddr(iONode node) {
  const char* defval = xStr( RocsWgen_addr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_r2rnet, node );
  return NodeOp.getStr( node, "addr", defval );
}
static void _setaddr(iONode node, const char* p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_r2rnet, node );
  NodeOp.setStr( node, "addr", p_addr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * enable
 */
static struct __attrdef RocsWgen_enable = {
  "enable",  "Enable R2Rnet.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isenable(iONode node) {
  Boolean defval = xBool( RocsWgen_enable );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_r2rnet, node );
  return NodeOp.getBool( node, "enable", defval );
}
static void _setenable(iONode node, Boolean p_enable) {
  if( node == NULL ) return;
  xNode( RocsWgen_r2rnet, node );
  NodeOp.setBool( node, "enable", p_enable );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "R2Rnet ID.",  "",  "string",  "",  "",  False,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_r2rnet, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_r2rnet, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "multicast port",  "",  "int",  "1234",  "0-*",  False,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_r2rnet, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_r2rnet, node );
  NodeOp.setInt( node, "port", p_port );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * routes
 */
static struct __attrdef RocsWgen_routes = {
  "routes",  "R2Rnet routes file.",  "",  "string",  "netroutes.xml",  "",  False,
};
static const char* _getroutes(iONode node) {
  const char* defval = xStr( RocsWgen_routes );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_r2rnet, node );
  return NodeOp.getStr( node, "routes", defval );
}
static void _setroutes(iONode node, const char* p_routes) {
  if( node == NULL ) return;
  xNode( RocsWgen_r2rnet, node );
  NodeOp.setStr( node, "routes", p_routes );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[6] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_r2rnet.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node r2rnet not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node r2rnet not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_addr;
  attrList[1] = &RocsWgen_enable;
  attrList[2] = &RocsWgen_id;
  attrList[3] = &RocsWgen_port;
  attrList[4] = &RocsWgen_routes;
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


struct __wR2RnetIni wR2RnetIni = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getaddr,
  _setaddr,
  _isenable,
  _setenable,
  _getid,
  _setid,
  _getport,
  _setport,
  _getroutes,
  _setroutes,
  _node_dump,
};
