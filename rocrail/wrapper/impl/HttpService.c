/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/HttpService.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.HttpService
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_http = {
  "http",  "Http interface for configure the xspooler.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_http.name;
}
static const char* _node_remark(void) {
  return RocsWgen_http.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_http.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_http.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * enable
 */
static struct __attrdef RocsWgen_enable = {
  "enable",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isenable(iONode node) {
  Boolean defval = xBool( RocsWgen_enable );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_http, node );
  return NodeOp.getBool( node, "enable", defval );
}
static void _setenable(iONode node, Boolean p_enable) {
  if( node == NULL ) return;
  xNode( RocsWgen_http, node );
  NodeOp.setBool( node, "enable", p_enable );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * path
 */
static struct __attrdef RocsWgen_path = {
  "path",  "Path where to look for external HTML documents.",  "",  "string",  ".",  "*",  False,
};
static const char* _getpath(iONode node) {
  const char* defval = xStr( RocsWgen_path );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_http, node );
  return NodeOp.getStr( node, "path", defval );
}
static void _setpath(iONode node, const char* p_path) {
  if( node == NULL ) return;
  xNode( RocsWgen_http, node );
  NodeOp.setStr( node, "path", p_path );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "Port number for server socket. Deactivated when 0.",  "",  "int",  "0",  "0-65535",  False,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_http, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_http, node );
  NodeOp.setInt( node, "port", p_port );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * refresh
 */
static struct __attrdef RocsWgen_refresh = {
  "refresh",  "browser refresh time: 0=no refresh",  "s",  "int",  "10",  "0-*",  False,
};
static int _getrefresh(iONode node) {
  int defval = xInt( RocsWgen_refresh );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_http, node );
  return NodeOp.getInt( node, "refresh", defval );
}
static void _setrefresh(iONode node, int p_refresh) {
  if( node == NULL ) return;
  xNode( RocsWgen_http, node );
  NodeOp.setInt( node, "refresh", p_refresh );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * webclient
 */
static struct __nodedef RocsWgen_webclient = {
  "webclient",  "",  False,  "1",};
static iONode _getwebclient(iONode node) {
  xNode( RocsWgen_http, node );
  return NodeOp.findNode( node, "webclient");
}


static iONode _nextwebclient(iONode node, iONode child) {
  xNode( RocsWgen_http, node );
  return NodeOp.findNextNode( node, child);
}
static void _setwebclient(iONode node, iONode p_webclient) {
  xNode( RocsWgen_http, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[5] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_http.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node http not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node http not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_enable;
  attrList[1] = &RocsWgen_path;
  attrList[2] = &RocsWgen_port;
  attrList[3] = &RocsWgen_refresh;
  attrList[4] = NULL;
  nodeList[0] = &RocsWgen_webclient;
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


struct __wHttpService wHttpService = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isenable,
  _setenable,
  _getpath,
  _setpath,
  _getport,
  _setport,
  _getrefresh,
  _setrefresh,
  _getwebclient,
  _nextwebclient,
  _setwebclient,
  _node_dump,
};
