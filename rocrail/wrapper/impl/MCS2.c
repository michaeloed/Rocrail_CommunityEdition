/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/MCS2.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.MCS2
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_mcs2 = {
  "mcs2",  "CS2 options",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_mcs2.name;
}
static const char* _node_remark(void) {
  return RocsWgen_mcs2.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_mcs2.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_mcs2.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bind
 */
static struct __attrdef RocsWgen_bind = {
  "bind",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isbind(iONode node) {
  Boolean defval = xBool( RocsWgen_bind );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mcs2, node );
  return NodeOp.getBool( node, "bind", defval );
}
static void _setbind(iONode node, Boolean p_bind) {
  if( node == NULL ) return;
  xNode( RocsWgen_mcs2, node );
  NodeOp.setBool( node, "bind", p_bind );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmdpause
 */
static struct __attrdef RocsWgen_cmdpause = {
  "cmdpause",  "",  "",  "int",  "10",  "10-500",  False,
};
static int _getcmdpause(iONode node) {
  int defval = xInt( RocsWgen_cmdpause );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mcs2, node );
  return NodeOp.getInt( node, "cmdpause", defval );
}
static void _setcmdpause(iONode node, int p_cmdpause) {
  if( node == NULL ) return;
  xNode( RocsWgen_mcs2, node );
  NodeOp.setInt( node, "cmdpause", p_cmdpause );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * discovery
 */
static struct __attrdef RocsWgen_discovery = {
  "discovery",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isdiscovery(iONode node) {
  Boolean defval = xBool( RocsWgen_discovery );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mcs2, node );
  return NodeOp.getBool( node, "discovery", defval );
}
static void _setdiscovery(iONode node, Boolean p_discovery) {
  if( node == NULL ) return;
  xNode( RocsWgen_mcs2, node );
  NodeOp.setBool( node, "discovery", p_discovery );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbdevid
 */
static struct __attrdef RocsWgen_fbdevid = {
  "fbdevid",  "Sensor device ID",  "",  "int",  "0",  "0-*",  False,
};
static int _getfbdevid(iONode node) {
  int defval = xInt( RocsWgen_fbdevid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mcs2, node );
  return NodeOp.getInt( node, "fbdevid", defval );
}
static void _setfbdevid(iONode node, int p_fbdevid) {
  if( node == NULL ) return;
  xNode( RocsWgen_mcs2, node );
  NodeOp.setInt( node, "fbdevid", p_fbdevid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sensorbegin
 */
static struct __attrdef RocsWgen_sensorbegin = {
  "sensorbegin",  "",  "",  "int",  "0",  "0-16000",  False,
};
static int _getsensorbegin(iONode node) {
  int defval = xInt( RocsWgen_sensorbegin );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mcs2, node );
  return NodeOp.getInt( node, "sensorbegin", defval );
}
static void _setsensorbegin(iONode node, int p_sensorbegin) {
  if( node == NULL ) return;
  xNode( RocsWgen_mcs2, node );
  NodeOp.setInt( node, "sensorbegin", p_sensorbegin );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sensorend
 */
static struct __attrdef RocsWgen_sensorend = {
  "sensorend",  "",  "",  "int",  "0",  "0-16000",  False,
};
static int _getsensorend(iONode node) {
  int defval = xInt( RocsWgen_sensorend );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mcs2, node );
  return NodeOp.getInt( node, "sensorend", defval );
}
static void _setsensorend(iONode node, int p_sensorend) {
  if( node == NULL ) return;
  xNode( RocsWgen_mcs2, node );
  NodeOp.setInt( node, "sensorend", p_sensorend );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * product
 */
static struct __nodedef RocsWgen_product = {
  "product",  "",  False,  "n",};
static iONode _getproduct(iONode node) {
  xNode( RocsWgen_mcs2, node );
  return NodeOp.findNode( node, "product");
}


static iONode _nextproduct(iONode node, iONode child) {
  xNode( RocsWgen_mcs2, node );
  return NodeOp.findNextNode( node, child);
}
static void _setproduct(iONode node, iONode p_product) {
  xNode( RocsWgen_mcs2, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[7] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_mcs2.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node mcs2 not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node mcs2 not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_bind;
  attrList[1] = &RocsWgen_cmdpause;
  attrList[2] = &RocsWgen_discovery;
  attrList[3] = &RocsWgen_fbdevid;
  attrList[4] = &RocsWgen_sensorbegin;
  attrList[5] = &RocsWgen_sensorend;
  attrList[6] = NULL;
  nodeList[0] = &RocsWgen_product;
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


struct __wMCS2 wMCS2 = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isbind,
  _setbind,
  _getcmdpause,
  _setcmdpause,
  _isdiscovery,
  _setdiscovery,
  _getfbdevid,
  _setfbdevid,
  _getsensorbegin,
  _setsensorbegin,
  _getsensorend,
  _setsensorend,
  _getproduct,
  _nextproduct,
  _setproduct,
  _node_dump,
};
