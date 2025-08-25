/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Service.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Service
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_service = {
  "service",  "Service for remote Rocrail to negotiate about a loc destination.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_service.name;
}
static const char* _node_remark(void) {
  return RocsWgen_service.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_service.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_service.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "Port number for server socket.",  "",  "int",  "0",  "0-65535",  False,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_service, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_service, node );
  NodeOp.setInt( node, "port", p_port );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sname
 */
static struct __attrdef RocsWgen_sname = {
  "sname",  "Servicer name to use in NetReq and NetRsp.",  "",  "string",  "",  "*",  False,
};
static const char* _getsname(iONode node) {
  const char* defval = xStr( RocsWgen_sname );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_service, node );
  return NodeOp.getStr( node, "sname", defval );
}
static void _setsname(iONode node, const char* p_sname) {
  if( node == NULL ) return;
  xNode( RocsWgen_service, node );
  NodeOp.setStr( node, "sname", p_sname );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[3] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_service.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node service not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node service not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_port;
  attrList[1] = &RocsWgen_sname;
  attrList[2] = NULL;
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


struct __wService wService = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getport,
  _setport,
  _getsname,
  _setsname,
  _node_dump,
};
