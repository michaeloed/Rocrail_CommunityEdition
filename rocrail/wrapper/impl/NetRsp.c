/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/NetRsp.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.NetRsp
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_netrsp = {
  "netrsp",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_netrsp.name;
}
static const char* _node_remark(void) {
  return RocsWgen_netrsp.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_netrsp.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_netrsp.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * host
 */
static struct __attrdef RocsWgen_host = {
  "host",  "Server client service.",  "",  "string",  "",  "",  False,
};
static const char* _gethost(iONode node) {
  const char* defval = xStr( RocsWgen_host );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_netrsp, node );
  return NodeOp.getStr( node, "host", defval );
}
static void _sethost(iONode node, const char* p_host) {
  if( node == NULL ) return;
  xNode( RocsWgen_netrsp, node );
  NodeOp.setStr( node, "host", p_host );
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
  xNode( RocsWgen_netrsp, node );
  return NodeOp.getStr( node, "localbk", defval );
}
static void _setlocalbk(iONode node, const char* p_localbk) {
  if( node == NULL ) return;
  xNode( RocsWgen_netrsp, node );
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
  xNode( RocsWgen_netrsp, node );
  return NodeOp.getStr( node, "localid", defval );
}
static void _setlocalid(iONode node, const char* p_localid) {
  if( node == NULL ) return;
  xNode( RocsWgen_netrsp, node );
  NodeOp.setStr( node, "localid", p_localid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * plan
 */
static struct __attrdef RocsWgen_plan = {
  "plan",  "Plan title.",  "",  "string",  "",  "",  False,
};
static const char* _getplan(iONode node) {
  const char* defval = xStr( RocsWgen_plan );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_netrsp, node );
  return NodeOp.getStr( node, "plan", defval );
}
static void _setplan(iONode node, const char* p_plan) {
  if( node == NULL ) return;
  xNode( RocsWgen_netrsp, node );
  NodeOp.setStr( node, "plan", p_plan );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "Rocrail Client Service.",  "",  "int",  "8051",  "",  False,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_netrsp, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_netrsp, node );
  NodeOp.setInt( node, "port", p_port );
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
  xNode( RocsWgen_netrsp, node );
  return NodeOp.getStr( node, "remotebk", defval );
}
static void _setremotebk(iONode node, const char* p_remotebk) {
  if( node == NULL ) return;
  xNode( RocsWgen_netrsp, node );
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
  xNode( RocsWgen_netrsp, node );
  return NodeOp.getStr( node, "remoteid", defval );
}
static void _setremoteid(iONode node, const char* p_remoteid) {
  if( node == NULL ) return;
  xNode( RocsWgen_netrsp, node );
  NodeOp.setStr( node, "remoteid", p_remoteid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * rsp
 */
static struct __attrdef RocsWgen_rsp = {
  "rsp",  "",  "",  "string",  "",  "occupied,reserved,block,isfree,unlocked",  False,
};
static const char* _getrsp(iONode node) {
  const char* defval = xStr( RocsWgen_rsp );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_netrsp, node );
  return NodeOp.getStr( node, "rsp", defval );
}
static void _setrsp(iONode node, const char* p_rsp) {
  if( node == NULL ) return;
  xNode( RocsWgen_netrsp, node );
  NodeOp.setStr( node, "rsp", p_rsp );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[9] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_netrsp.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node netrsp not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node netrsp not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_host;
  attrList[1] = &RocsWgen_localbk;
  attrList[2] = &RocsWgen_localid;
  attrList[3] = &RocsWgen_plan;
  attrList[4] = &RocsWgen_port;
  attrList[5] = &RocsWgen_remotebk;
  attrList[6] = &RocsWgen_remoteid;
  attrList[7] = &RocsWgen_rsp;
  attrList[8] = NULL;
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


struct __wNetRsp wNetRsp = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "block",
  "clientconn",
  "isfree",
  "occupied",
  "reserved",
  "unlocked",
  _gethost,
  _sethost,
  _getlocalbk,
  _setlocalbk,
  _getlocalid,
  _setlocalid,
  _getplan,
  _setplan,
  _getport,
  _setport,
  _getremotebk,
  _setremotebk,
  _getremoteid,
  _setremoteid,
  _getrsp,
  _setrsp,
  _node_dump,
};
