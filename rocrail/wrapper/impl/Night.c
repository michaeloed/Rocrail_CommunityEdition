/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Night.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Night
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_night = {
  "night",  "Night definition",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_night.name;
}
static const char* _node_remark(void) {
  return RocsWgen_night.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_night.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_night.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blue
 */
static struct __attrdef RocsWgen_blue = {
  "blue",  "",  "",  "int",  "255",  "0-255",  False,
};
static int _getblue(iONode node) {
  int defval = xInt( RocsWgen_blue );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_night, node );
  return NodeOp.getInt( node, "blue", defval );
}
static void _setblue(iONode node, int p_blue) {
  if( node == NULL ) return;
  xNode( RocsWgen_night, node );
  NodeOp.setInt( node, "blue", p_blue );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bri
 */
static struct __attrdef RocsWgen_bri = {
  "bri",  "brightness.",  "",  "int",  "5",  "0-255",  False,
};
static int _getbri(iONode node) {
  int defval = xInt( RocsWgen_bri );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_night, node );
  return NodeOp.getInt( node, "bri", defval );
}
static void _setbri(iONode node, int p_bri) {
  if( node == NULL ) return;
  xNode( RocsWgen_night, node );
  NodeOp.setInt( node, "bri", p_bri );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * green
 */
static struct __attrdef RocsWgen_green = {
  "green",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getgreen(iONode node) {
  int defval = xInt( RocsWgen_green );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_night, node );
  return NodeOp.getInt( node, "green", defval );
}
static void _setgreen(iONode node, int p_green) {
  if( node == NULL ) return;
  xNode( RocsWgen_night, node );
  NodeOp.setInt( node, "green", p_green );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * outputs
 */
static struct __attrdef RocsWgen_outputs = {
  "outputs",  "Comma separated list of outputs.",  "",  "string",  "",  "*",  False,
};
static const char* _getoutputs(iONode node) {
  const char* defval = xStr( RocsWgen_outputs );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_night, node );
  return NodeOp.getStr( node, "outputs", defval );
}
static void _setoutputs(iONode node, const char* p_outputs) {
  if( node == NULL ) return;
  xNode( RocsWgen_night, node );
  NodeOp.setStr( node, "outputs", p_outputs );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * red
 */
static struct __attrdef RocsWgen_red = {
  "red",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getred(iONode node) {
  int defval = xInt( RocsWgen_red );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_night, node );
  return NodeOp.getInt( node, "red", defval );
}
static void _setred(iONode node, int p_red) {
  if( node == NULL ) return;
  xNode( RocsWgen_night, node );
  NodeOp.setInt( node, "red", p_red );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * white
 */
static struct __attrdef RocsWgen_white = {
  "white",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getwhite(iONode node) {
  int defval = xInt( RocsWgen_white );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_night, node );
  return NodeOp.getInt( node, "white", defval );
}
static void _setwhite(iONode node, int p_white) {
  if( node == NULL ) return;
  xNode( RocsWgen_night, node );
  NodeOp.setInt( node, "white", p_white );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[7] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_night.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node night not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node night not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_blue;
  attrList[1] = &RocsWgen_bri;
  attrList[2] = &RocsWgen_green;
  attrList[3] = &RocsWgen_outputs;
  attrList[4] = &RocsWgen_red;
  attrList[5] = &RocsWgen_white;
  attrList[6] = NULL;
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


struct __wNight wNight = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getblue,
  _setblue,
  _getbri,
  _setbri,
  _getgreen,
  _setgreen,
  _getoutputs,
  _setoutputs,
  _getred,
  _setred,
  _getwhite,
  _setwhite,
  _node_dump,
};
