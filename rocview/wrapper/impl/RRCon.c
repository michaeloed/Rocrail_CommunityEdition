/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:52 2018
  */

#include "rocview/wrapper/public/RRCon.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.RRCon
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_rrcon = {
  "rrcon",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_rrcon.name;
}
static const char* _node_remark(void) {
  return RocsWgen_rrcon.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_rrcon.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_rrcon.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * controlcode
 */
static struct __attrdef RocsWgen_controlcode = {
  "controlcode",  "",  "",  "string",  "",  "",  False,
};
static const char* _getcontrolcode(iONode node) {
  const char* defval = xStr( RocsWgen_controlcode );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rrcon, node );
  return NodeOp.getStr( node, "controlcode", defval );
}
static void _setcontrolcode(iONode node, const char* p_controlcode) {
  if( node == NULL ) return;
  xNode( RocsWgen_rrcon, node );
  NodeOp.setStr( node, "controlcode", p_controlcode );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * host
 */
static struct __attrdef RocsWgen_host = {
  "host",  "",  "",  "string",  "localhost",  "",  False,
};
static const char* _gethost(iONode node) {
  const char* defval = xStr( RocsWgen_host );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rrcon, node );
  return NodeOp.getStr( node, "host", defval );
}
static void _sethost(iONode node, const char* p_host) {
  if( node == NULL ) return;
  xNode( RocsWgen_rrcon, node );
  NodeOp.setStr( node, "host", p_host );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "",  "",  "int",  "8051",  "",  False,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rrcon, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_rrcon, node );
  NodeOp.setInt( node, "port", p_port );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * retry
 */
static struct __attrdef RocsWgen_retry = {
  "retry",  "",  "",  "int",  "1",  "",  False,
};
static int _getretry(iONode node) {
  int defval = xInt( RocsWgen_retry );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rrcon, node );
  return NodeOp.getInt( node, "retry", defval );
}
static void _setretry(iONode node, int p_retry) {
  if( node == NULL ) return;
  xNode( RocsWgen_rrcon, node );
  NodeOp.setInt( node, "retry", p_retry );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * retryinterval
 */
static struct __attrdef RocsWgen_retryinterval = {
  "retryinterval",  "In mS",  "",  "int",  "500",  "",  False,
};
static int _getretryinterval(iONode node) {
  int defval = xInt( RocsWgen_retryinterval );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rrcon, node );
  return NodeOp.getInt( node, "retryinterval", defval );
}
static void _setretryinterval(iONode node, int p_retryinterval) {
  if( node == NULL ) return;
  xNode( RocsWgen_rrcon, node );
  NodeOp.setInt( node, "retryinterval", p_retryinterval );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[6] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_rrcon.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node rrcon not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node rrcon not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_controlcode;
  attrList[1] = &RocsWgen_host;
  attrList[2] = &RocsWgen_port;
  attrList[3] = &RocsWgen_retry;
  attrList[4] = &RocsWgen_retryinterval;
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


struct __wRRCon wRRCon = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getcontrolcode,
  _setcontrolcode,
  _gethost,
  _sethost,
  _getport,
  _setport,
  _getretry,
  _setretry,
  _getretryinterval,
  _setretryinterval,
  _node_dump,
};
