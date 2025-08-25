/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Sunrise.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Sunrise
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_sunrise = {
  "sunrise",  "Sunrise definition",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_sunrise.name;
}
static const char* _node_remark(void) {
  return RocsWgen_sunrise.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_sunrise.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_sunrise.cardinality;
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
  xNode( RocsWgen_sunrise, node );
  return NodeOp.getInt( node, "blue", defval );
}
static void _setblue(iONode node, int p_blue) {
  if( node == NULL ) return;
  xNode( RocsWgen_sunrise, node );
  NodeOp.setInt( node, "blue", p_blue );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * green
 */
static struct __attrdef RocsWgen_green = {
  "green",  "",  "",  "int",  "255",  "0-255",  False,
};
static int _getgreen(iONode node) {
  int defval = xInt( RocsWgen_green );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sunrise, node );
  return NodeOp.getInt( node, "green", defval );
}
static void _setgreen(iONode node, int p_green) {
  if( node == NULL ) return;
  xNode( RocsWgen_sunrise, node );
  NodeOp.setInt( node, "green", p_green );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * hour
 */
static struct __attrdef RocsWgen_hour = {
  "hour",  "",  "",  "int",  "6",  "0-23",  False,
};
static int _gethour(iONode node) {
  int defval = xInt( RocsWgen_hour );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sunrise, node );
  return NodeOp.getInt( node, "hour", defval );
}
static void _sethour(iONode node, int p_hour) {
  if( node == NULL ) return;
  xNode( RocsWgen_sunrise, node );
  NodeOp.setInt( node, "hour", p_hour );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * minute
 */
static struct __attrdef RocsWgen_minute = {
  "minute",  "",  "",  "int",  "0",  "0-59",  False,
};
static int _getminute(iONode node) {
  int defval = xInt( RocsWgen_minute );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sunrise, node );
  return NodeOp.getInt( node, "minute", defval );
}
static void _setminute(iONode node, int p_minute) {
  if( node == NULL ) return;
  xNode( RocsWgen_sunrise, node );
  NodeOp.setInt( node, "minute", p_minute );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * red
 */
static struct __attrdef RocsWgen_red = {
  "red",  "",  "",  "int",  "255",  "0-255",  False,
};
static int _getred(iONode node) {
  int defval = xInt( RocsWgen_red );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sunrise, node );
  return NodeOp.getInt( node, "red", defval );
}
static void _setred(iONode node, int p_red) {
  if( node == NULL ) return;
  xNode( RocsWgen_sunrise, node );
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
  xNode( RocsWgen_sunrise, node );
  return NodeOp.getInt( node, "white", defval );
}
static void _setwhite(iONode node, int p_white) {
  if( node == NULL ) return;
  xNode( RocsWgen_sunrise, node );
  NodeOp.setInt( node, "white", p_white );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[7] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_sunrise.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node sunrise not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node sunrise not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_blue;
  attrList[1] = &RocsWgen_green;
  attrList[2] = &RocsWgen_hour;
  attrList[3] = &RocsWgen_minute;
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


struct __wSunrise wSunrise = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getblue,
  _setblue,
  _getgreen,
  _setgreen,
  _gethour,
  _sethour,
  _getminute,
  _setminute,
  _getred,
  _setred,
  _getwhite,
  _setwhite,
  _node_dump,
};
