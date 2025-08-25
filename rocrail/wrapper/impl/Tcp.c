/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Tcp.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Tcp
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_tcp = {
  "tcp",  "Client service port.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_tcp.name;
}
static const char* _node_remark(void) {
  return RocsWgen_tcp.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_tcp.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_tcp.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * controlcode
 */
static struct __attrdef RocsWgen_controlcode = {
  "controlcode",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getcontrolcode(iONode node) {
  const char* defval = xStr( RocsWgen_controlcode );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tcp, node );
  return NodeOp.getStr( node, "controlcode", defval );
}
static void _setcontrolcode(iONode node, const char* p_controlcode) {
  if( node == NULL ) return;
  xNode( RocsWgen_tcp, node );
  NodeOp.setStr( node, "controlcode", p_controlcode );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * maxcon
 */
static struct __attrdef RocsWgen_maxcon = {
  "maxcon",  "Max. concurrent connected clients.",  "",  "int",  "10",  "1-100",  False,
};
static int _getmaxcon(iONode node) {
  int defval = xInt( RocsWgen_maxcon );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tcp, node );
  return NodeOp.getInt( node, "maxcon", defval );
}
static void _setmaxcon(iONode node, int p_maxcon) {
  if( node == NULL ) return;
  xNode( RocsWgen_tcp, node );
  NodeOp.setInt( node, "maxcon", p_maxcon );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * onlyfirstmaster
 */
static struct __attrdef RocsWgen_onlyfirstmaster = {
  "onlyfirstmaster",  "Only the first client is master.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isonlyfirstmaster(iONode node) {
  Boolean defval = xBool( RocsWgen_onlyfirstmaster );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tcp, node );
  return NodeOp.getBool( node, "onlyfirstmaster", defval );
}
static void _setonlyfirstmaster(iONode node, Boolean p_onlyfirstmaster) {
  if( node == NULL ) return;
  xNode( RocsWgen_tcp, node );
  NodeOp.setBool( node, "onlyfirstmaster", p_onlyfirstmaster );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "",  "",  "int",  "8051",  "1-65535",  False,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tcp, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_tcp, node );
  NodeOp.setInt( node, "port", p_port );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * slavecode
 */
static struct __attrdef RocsWgen_slavecode = {
  "slavecode",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getslavecode(iONode node) {
  const char* defval = xStr( RocsWgen_slavecode );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tcp, node );
  return NodeOp.getStr( node, "slavecode", defval );
}
static void _setslavecode(iONode node, const char* p_slavecode) {
  if( node == NULL ) return;
  xNode( RocsWgen_tcp, node );
  NodeOp.setStr( node, "slavecode", p_slavecode );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[6] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_tcp.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node tcp not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node tcp not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_controlcode;
  attrList[1] = &RocsWgen_maxcon;
  attrList[2] = &RocsWgen_onlyfirstmaster;
  attrList[3] = &RocsWgen_port;
  attrList[4] = &RocsWgen_slavecode;
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


struct __wTcp wTcp = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getcontrolcode,
  _setcontrolcode,
  _getmaxcon,
  _setmaxcon,
  _isonlyfirstmaster,
  _setonlyfirstmaster,
  _getport,
  _setport,
  _getslavecode,
  _setslavecode,
  _node_dump,
};
