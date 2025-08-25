/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/WebClient.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.WebClient
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_webclient = {
  "webclient",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_webclient.name;
}
static const char* _node_remark(void) {
  return RocsWgen_webclient.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_webclient.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_webclient.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * imgpath
 */
static struct __attrdef RocsWgen_imgpath = {
  "imgpath",  "Location of (loco)images.",  "",  "string",  "images",  "*",  False,
};
static const char* _getimgpath(iONode node) {
  const char* defval = xStr( RocsWgen_imgpath );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_webclient, node );
  return NodeOp.getStr( node, "imgpath", defval );
}
static void _setimgpath(iONode node, const char* p_imgpath) {
  if( node == NULL ) return;
  xNode( RocsWgen_webclient, node );
  NodeOp.setStr( node, "imgpath", p_imgpath );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "Port number server socket for webclients. Deactivated when 0.",  "",  "int",  "0",  "0-65535",  False,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_webclient, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_webclient, node );
  NodeOp.setInt( node, "port", p_port );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * svgpath1
 */
static struct __attrdef RocsWgen_svgpath1 = {
  "svgpath1",  "scan this path for svg symbols",  "",  "string",  "svg/themes/SpDrS60",  "",  False,
};
static const char* _getsvgpath1(iONode node) {
  const char* defval = xStr( RocsWgen_svgpath1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_webclient, node );
  return NodeOp.getStr( node, "svgpath1", defval );
}
static void _setsvgpath1(iONode node, const char* p_svgpath1) {
  if( node == NULL ) return;
  xNode( RocsWgen_webclient, node );
  NodeOp.setStr( node, "svgpath1", p_svgpath1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * svgpath2
 */
static struct __attrdef RocsWgen_svgpath2 = {
  "svgpath2",  "scan this path for svg symbols",  "",  "string",  "svg/themes/Accessories",  "",  False,
};
static const char* _getsvgpath2(iONode node) {
  const char* defval = xStr( RocsWgen_svgpath2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_webclient, node );
  return NodeOp.getStr( node, "svgpath2", defval );
}
static void _setsvgpath2(iONode node, const char* p_svgpath2) {
  if( node == NULL ) return;
  xNode( RocsWgen_webclient, node );
  NodeOp.setStr( node, "svgpath2", p_svgpath2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * svgpath3
 */
static struct __attrdef RocsWgen_svgpath3 = {
  "svgpath3",  "scan this path for svg symbols",  "",  "string",  "svg/themes/Roads",  "",  False,
};
static const char* _getsvgpath3(iONode node) {
  const char* defval = xStr( RocsWgen_svgpath3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_webclient, node );
  return NodeOp.getStr( node, "svgpath3", defval );
}
static void _setsvgpath3(iONode node, const char* p_svgpath3) {
  if( node == NULL ) return;
  xNode( RocsWgen_webclient, node );
  NodeOp.setStr( node, "svgpath3", p_svgpath3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * svgpath4
 */
static struct __attrdef RocsWgen_svgpath4 = {
  "svgpath4",  "scan this path for svg symbols",  "",  "string",  ".",  "",  False,
};
static const char* _getsvgpath4(iONode node) {
  const char* defval = xStr( RocsWgen_svgpath4 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_webclient, node );
  return NodeOp.getStr( node, "svgpath4", defval );
}
static void _setsvgpath4(iONode node, const char* p_svgpath4) {
  if( node == NULL ) return;
  xNode( RocsWgen_webclient, node );
  NodeOp.setStr( node, "svgpath4", p_svgpath4 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * svgpath5
 */
static struct __attrdef RocsWgen_svgpath5 = {
  "svgpath5",  "scan this path for svg symbols",  "",  "string",  ".",  "",  False,
};
static const char* _getsvgpath5(iONode node) {
  const char* defval = xStr( RocsWgen_svgpath5 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_webclient, node );
  return NodeOp.getStr( node, "svgpath5", defval );
}
static void _setsvgpath5(iONode node, const char* p_svgpath5) {
  if( node == NULL ) return;
  xNode( RocsWgen_webclient, node );
  NodeOp.setStr( node, "svgpath5", p_svgpath5 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * webpath
 */
static struct __attrdef RocsWgen_webpath = {
  "webpath",  "Location of the web files.",  "",  "string",  "web",  "*",  False,
};
static const char* _getwebpath(iONode node) {
  const char* defval = xStr( RocsWgen_webpath );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_webclient, node );
  return NodeOp.getStr( node, "webpath", defval );
}
static void _setwebpath(iONode node, const char* p_webpath) {
  if( node == NULL ) return;
  xNode( RocsWgen_webclient, node );
  NodeOp.setStr( node, "webpath", p_webpath );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[9] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_webclient.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node webclient not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node webclient not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_imgpath;
  attrList[1] = &RocsWgen_port;
  attrList[2] = &RocsWgen_svgpath1;
  attrList[3] = &RocsWgen_svgpath2;
  attrList[4] = &RocsWgen_svgpath3;
  attrList[5] = &RocsWgen_svgpath4;
  attrList[6] = &RocsWgen_svgpath5;
  attrList[7] = &RocsWgen_webpath;
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


struct __wWebClient wWebClient = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getimgpath,
  _setimgpath,
  _getport,
  _setport,
  _getsvgpath1,
  _setsvgpath1,
  _getsvgpath2,
  _setsvgpath2,
  _getsvgpath3,
  _setsvgpath3,
  _getsvgpath4,
  _setsvgpath4,
  _getsvgpath5,
  _setsvgpath5,
  _getwebpath,
  _setwebpath,
  _node_dump,
};
