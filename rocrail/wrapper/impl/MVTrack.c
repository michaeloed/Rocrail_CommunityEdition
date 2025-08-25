/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/MVTrack.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.MVTrack
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_mv = {
  "mv",  "Measurement Velocity Track",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_mv.name;
}
static const char* _node_remark(void) {
  return RocsWgen_mv.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_mv.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_mv.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * distance
 */
static struct __attrdef RocsWgen_distance = {
  "distance",  "Distance between the two events.",  "",  "int",  "0",  "",  False,
};
static int _getdistance(iONode node) {
  int defval = xInt( RocsWgen_distance );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mv, node );
  return NodeOp.getInt( node, "distance", defval );
}
static void _setdistance(iONode node, int p_distance) {
  if( node == NULL ) return;
  xNode( RocsWgen_mv, node );
  NodeOp.setInt( node, "distance", p_distance );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mph
 */
static struct __attrdef RocsWgen_mph = {
  "mph",  "convert to MPH",  "",  "bool",  "false",  "",  False,
};
static Boolean _ismph(iONode node) {
  Boolean defval = xBool( RocsWgen_mph );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mv, node );
  return NodeOp.getBool( node, "mph", defval );
}
static void _setmph(iONode node, Boolean p_mph) {
  if( node == NULL ) return;
  xNode( RocsWgen_mv, node );
  NodeOp.setBool( node, "mph", p_mph );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * s1
 */
static struct __attrdef RocsWgen_s1 = {
  "s1",  "Feedback ID",  "",  "string",  "",  "*",  True,
};
static const char* _gets1(iONode node) {
  const char* defval = xStr( RocsWgen_s1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mv, node );
  return NodeOp.getStr( node, "s1", defval );
}
static void _sets1(iONode node, const char* p_s1) {
  if( node == NULL ) return;
  xNode( RocsWgen_mv, node );
  NodeOp.setStr( node, "s1", p_s1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * s2
 */
static struct __attrdef RocsWgen_s2 = {
  "s2",  "Feedback ID",  "",  "string",  "",  "*",  True,
};
static const char* _gets2(iONode node) {
  const char* defval = xStr( RocsWgen_s2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mv, node );
  return NodeOp.getStr( node, "s2", defval );
}
static void _sets2(iONode node, const char* p_s2) {
  if( node == NULL ) return;
  xNode( RocsWgen_mv, node );
  NodeOp.setStr( node, "s2", p_s2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * scale
 */
static struct __attrdef RocsWgen_scale = {
  "scale",  "Scale of locomotives.",  "",  "int",  "87",  "",  False,
};
static int _getscale(iONode node) {
  int defval = xInt( RocsWgen_scale );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mv, node );
  return NodeOp.getInt( node, "scale", defval );
}
static void _setscale(iONode node, int p_scale) {
  if( node == NULL ) return;
  xNode( RocsWgen_mv, node );
  NodeOp.setInt( node, "scale", p_scale );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * actionctrl
 */
static struct __nodedef RocsWgen_actionctrl = {
  "actionctrl",  "",  False,  "n",};
static iONode _getactionctrl(iONode node) {
  xNode( RocsWgen_mv, node );
  return NodeOp.findNode( node, "actionctrl");
}


static iONode _nextactionctrl(iONode node, iONode child) {
  xNode( RocsWgen_mv, node );
  return NodeOp.findNextNode( node, child);
}
static void _setactionctrl(iONode node, iONode p_actionctrl) {
  xNode( RocsWgen_mv, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[6] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_mv.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node mv not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node mv not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_distance;
  attrList[1] = &RocsWgen_mph;
  attrList[2] = &RocsWgen_s1;
  attrList[3] = &RocsWgen_s2;
  attrList[4] = &RocsWgen_scale;
  attrList[5] = NULL;
  nodeList[0] = &RocsWgen_actionctrl;
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


struct __wMVTrack wMVTrack = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getdistance,
  _setdistance,
  _ismph,
  _setmph,
  _gets1,
  _sets1,
  _gets2,
  _sets2,
  _getscale,
  _setscale,
  _getactionctrl,
  _nextactionctrl,
  _setactionctrl,
  _node_dump,
};
