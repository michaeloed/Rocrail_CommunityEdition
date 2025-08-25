/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/uConS88.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.uConS88
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_ucons88 = {
  "ucons88",  "uConS88 init",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_ucons88.name;
}
static const char* _node_remark(void) {
  return RocsWgen_ucons88.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_ucons88.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_ucons88.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbB1
 */
static struct __attrdef RocsWgen_fbB1 = {
  "fbB1",  "µCon-S88-Master number of modules of 16 inputs on port 1",  "",  "int",  "5",  "",  False,
};
static int _getfbB1(iONode node) {
  int defval = xInt( RocsWgen_fbB1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ucons88, node );
  return NodeOp.getInt( node, "fbB1", defval );
}
static void _setfbB1(iONode node, int p_fbB1) {
  if( node == NULL ) return;
  xNode( RocsWgen_ucons88, node );
  NodeOp.setInt( node, "fbB1", p_fbB1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbB2
 */
static struct __attrdef RocsWgen_fbB2 = {
  "fbB2",  "µCon-S88-Master number of modules of 16 inputs on port 2",  "",  "int",  "0",  "",  False,
};
static int _getfbB2(iONode node) {
  int defval = xInt( RocsWgen_fbB2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ucons88, node );
  return NodeOp.getInt( node, "fbB2", defval );
}
static void _setfbB2(iONode node, int p_fbB2) {
  if( node == NULL ) return;
  xNode( RocsWgen_ucons88, node );
  NodeOp.setInt( node, "fbB2", p_fbB2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbB3
 */
static struct __attrdef RocsWgen_fbB3 = {
  "fbB3",  "µCon-S88-Master number of modules of 16 inputs on port 3",  "",  "int",  "0",  "",  False,
};
static int _getfbB3(iONode node) {
  int defval = xInt( RocsWgen_fbB3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ucons88, node );
  return NodeOp.getInt( node, "fbB3", defval );
}
static void _setfbB3(iONode node, int p_fbB3) {
  if( node == NULL ) return;
  xNode( RocsWgen_ucons88, node );
  NodeOp.setInt( node, "fbB3", p_fbB3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * host
 */
static struct __attrdef RocsWgen_host = {
  "host",  "µCon-S88-Master IP address",  "",  "string",  "192.168.1.88",  "",  False,
};
static const char* _gethost(iONode node) {
  const char* defval = xStr( RocsWgen_host );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ucons88, node );
  return NodeOp.getStr( node, "host", defval );
}
static void _sethost(iONode node, const char* p_host) {
  if( node == NULL ) return;
  xNode( RocsWgen_ucons88, node );
  NodeOp.setStr( node, "host", p_host );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "µCon-S88-Master port",  "",  "int",  "11082",  "",  False,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ucons88, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_ucons88, node );
  NodeOp.setInt( node, "port", p_port );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[6] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_ucons88.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node ucons88 not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node ucons88 not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_fbB1;
  attrList[1] = &RocsWgen_fbB2;
  attrList[2] = &RocsWgen_fbB3;
  attrList[3] = &RocsWgen_host;
  attrList[4] = &RocsWgen_port;
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


struct __wuConS88 wuConS88 = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getfbB1,
  _setfbB1,
  _getfbB2,
  _setfbB2,
  _getfbB3,
  _setfbB3,
  _gethost,
  _sethost,
  _getport,
  _setport,
  _node_dump,
};
