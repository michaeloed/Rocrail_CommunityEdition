/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/DMX.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.DMX
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_dmx = {
  "dmx",  "DMX Options",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_dmx.name;
}
static const char* _node_remark(void) {
  return RocsWgen_dmx.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_dmx.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_dmx.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * dmxdata
 */
static struct __attrdef RocsWgen_dmxdata = {
  "dmxdata",  "",  "",  "string",  "",  "",  False,
};
static const char* _getdmxdata(iONode node) {
  const char* defval = xStr( RocsWgen_dmxdata );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dmx, node );
  return NodeOp.getStr( node, "dmxdata", defval );
}
static void _setdmxdata(iONode node, const char* p_dmxdata) {
  if( node == NULL ) return;
  xNode( RocsWgen_dmx, node );
  NodeOp.setStr( node, "dmxdata", p_dmxdata );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * framerate
 */
static struct __attrdef RocsWgen_framerate = {
  "framerate",  "",  "",  "int",  "500",  "100-10000",  False,
};
static int _getframerate(iONode node) {
  int defval = xInt( RocsWgen_framerate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dmx, node );
  return NodeOp.getInt( node, "framerate", defval );
}
static void _setframerate(iONode node, int p_framerate) {
  if( node == NULL ) return;
  xNode( RocsWgen_dmx, node );
  NodeOp.setInt( node, "framerate", p_framerate );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mapwhite
 */
static struct __attrdef RocsWgen_mapwhite = {
  "mapwhite",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _ismapwhite(iONode node) {
  Boolean defval = xBool( RocsWgen_mapwhite );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dmx, node );
  return NodeOp.getBool( node, "mapwhite", defval );
}
static void _setmapwhite(iONode node, Boolean p_mapwhite) {
  if( node == NULL ) return;
  xNode( RocsWgen_dmx, node );
  NodeOp.setBool( node, "mapwhite", p_mapwhite );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * restoredata
 */
static struct __attrdef RocsWgen_restoredata = {
  "restoredata",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isrestoredata(iONode node) {
  Boolean defval = xBool( RocsWgen_restoredata );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dmx, node );
  return NodeOp.getBool( node, "restoredata", defval );
}
static void _setrestoredata(iONode node, Boolean p_restoredata) {
  if( node == NULL ) return;
  xNode( RocsWgen_dmx, node );
  NodeOp.setBool( node, "restoredata", p_restoredata );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[5] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_dmx.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node dmx not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node dmx not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_dmxdata;
  attrList[1] = &RocsWgen_framerate;
  attrList[2] = &RocsWgen_mapwhite;
  attrList[3] = &RocsWgen_restoredata;
  attrList[4] = NULL;
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


struct __wDMX wDMX = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getdmxdata,
  _setdmxdata,
  _getframerate,
  _setframerate,
  _ismapwhite,
  _setmapwhite,
  _isrestoredata,
  _setrestoredata,
  _node_dump,
};
