/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/NetReq.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.NetReq
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_netreq = {
  "netreq",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_netreq.name;
}
static const char* _node_remark(void) {
  return RocsWgen_netreq.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_netreq.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_netreq.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lcid
 */
static struct __attrdef RocsWgen_lcid = {
  "lcid",  "Loc ID.",  "",  "string",  "",  "",  False,
};
static const char* _getlcid(iONode node) {
  const char* defval = xStr( RocsWgen_lcid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_netreq, node );
  return NodeOp.getStr( node, "lcid", defval );
}
static void _setlcid(iONode node, const char* p_lcid) {
  if( node == NULL ) return;
  xNode( RocsWgen_netreq, node );
  NodeOp.setStr( node, "lcid", p_lcid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * localbk
 */
static struct __attrdef RocsWgen_localbk = {
  "localbk",  "Local block ID; rrid::bkid",  "",  "string",  "NULL",  "*",  True,
};
static const char* _getlocalbk(iONode node) {
  const char* defval = xStr( RocsWgen_localbk );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_netreq, node );
  return NodeOp.getStr( node, "localbk", defval );
}
static void _setlocalbk(iONode node, const char* p_localbk) {
  if( node == NULL ) return;
  xNode( RocsWgen_netreq, node );
  NodeOp.setStr( node, "localbk", p_localbk );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * localid
 */
static struct __attrdef RocsWgen_localid = {
  "localid",  "Local server name.",  "",  "string",  "",  "",  False,
};
static const char* _getlocalid(iONode node) {
  const char* defval = xStr( RocsWgen_localid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_netreq, node );
  return NodeOp.getStr( node, "localid", defval );
}
static void _setlocalid(iONode node, const char* p_localid) {
  if( node == NULL ) return;
  xNode( RocsWgen_netreq, node );
  NodeOp.setStr( node, "localid", p_localid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * remotebk
 */
static struct __attrdef RocsWgen_remotebk = {
  "remotebk",  "Remote block ID; rrid::bkid",  "",  "string",  "NULL",  "*",  True,
};
static const char* _getremotebk(iONode node) {
  const char* defval = xStr( RocsWgen_remotebk );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_netreq, node );
  return NodeOp.getStr( node, "remotebk", defval );
}
static void _setremotebk(iONode node, const char* p_remotebk) {
  if( node == NULL ) return;
  xNode( RocsWgen_netreq, node );
  NodeOp.setStr( node, "remotebk", p_remotebk );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * remoteid
 */
static struct __attrdef RocsWgen_remoteid = {
  "remoteid",  "Remote server name.",  "",  "string",  "*",  "",  False,
};
static const char* _getremoteid(iONode node) {
  const char* defval = xStr( RocsWgen_remoteid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_netreq, node );
  return NodeOp.getStr( node, "remoteid", defval );
}
static void _setremoteid(iONode node, const char* p_remoteid) {
  if( node == NULL ) return;
  xNode( RocsWgen_netreq, node );
  NodeOp.setStr( node, "remoteid", p_remoteid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * req
 */
static struct __attrdef RocsWgen_req = {
  "req",  "Request type.",  "",  "string",  "",  "",  False,
};
static const char* _getreq(iONode node) {
  const char* defval = xStr( RocsWgen_req );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_netreq, node );
  return NodeOp.getStr( node, "req", defval );
}
static void _setreq(iONode node, const char* p_req) {
  if( node == NULL ) return;
  xNode( RocsWgen_netreq, node );
  NodeOp.setStr( node, "req", p_req );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * routeid
 */
static struct __attrdef RocsWgen_routeid = {
  "routeid",  "Route ID.",  "",  "string",  "",  "",  False,
};
static const char* _getrouteid(iONode node) {
  const char* defval = xStr( RocsWgen_routeid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_netreq, node );
  return NodeOp.getStr( node, "routeid", defval );
}
static void _setrouteid(iONode node, const char* p_routeid) {
  if( node == NULL ) return;
  xNode( RocsWgen_netreq, node );
  NodeOp.setStr( node, "routeid", p_routeid );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[8] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_netreq.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node netreq not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node netreq not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_lcid;
  attrList[1] = &RocsWgen_localbk;
  attrList[2] = &RocsWgen_localid;
  attrList[3] = &RocsWgen_remotebk;
  attrList[4] = &RocsWgen_remoteid;
  attrList[5] = &RocsWgen_req;
  attrList[6] = &RocsWgen_routeid;
  attrList[7] = NULL;
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


struct __wNetReq wNetReq = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "clientconn",
  "getblock",
  "isfree",
  "locoisin",
  "netroutes",
  "reserve",
  "unlock",
  _getlcid,
  _setlcid,
  _getlocalbk,
  _setlocalbk,
  _getlocalid,
  _setlocalid,
  _getremotebk,
  _setremotebk,
  _getremoteid,
  _setremoteid,
  _getreq,
  _setreq,
  _getrouteid,
  _setrouteid,
  _node_dump,
};
