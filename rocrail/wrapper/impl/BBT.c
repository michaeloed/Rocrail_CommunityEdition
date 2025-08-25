/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/BBT.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.BBT
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_bbt = {
  "bbt",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_bbt.name;
}
static const char* _node_remark(void) {
  return RocsWgen_bbt.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_bbt.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_bbt.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bk
 */
static struct __attrdef RocsWgen_bk = {
  "bk",  "Block ID.",  "",  "string",  "",  "*",  False,
};
static const char* _getbk(iONode node) {
  const char* defval = xStr( RocsWgen_bk );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bbt, node );
  return NodeOp.getStr( node, "bk", defval );
}
static void _setbk(iONode node, const char* p_bk) {
  if( node == NULL ) return;
  xNode( RocsWgen_bbt, node );
  NodeOp.setStr( node, "bk", p_bk );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * count
 */
static struct __attrdef RocsWgen_count = {
  "count",  "Counter for dynamically adjust the correction factor.",  "",  "int",  "0",  "",  False,
};
static int _getcount(iONode node) {
  int defval = xInt( RocsWgen_count );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bbt, node );
  return NodeOp.getInt( node, "count", defval );
}
static void _setcount(iONode node, int p_count) {
  if( node == NULL ) return;
  xNode( RocsWgen_bbt, node );
  NodeOp.setInt( node, "count", p_count );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * delay
 */
static struct __attrdef RocsWgen_delay = {
  "delay",  "",  "10ms",  "int",  "0",  "0-*",  False,
};
static int _getdelay(iONode node) {
  int defval = xInt( RocsWgen_delay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bbt, node );
  return NodeOp.getInt( node, "delay", defval );
}
static void _setdelay(iONode node, int p_delay) {
  if( node == NULL ) return;
  xNode( RocsWgen_bbt, node );
  NodeOp.setInt( node, "delay", p_delay );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fixed
 */
static struct __attrdef RocsWgen_fixed = {
  "fixed",  "Fixed block brake timer.",  "",  "bool",  "False",  "",  False,
};
static Boolean _isfixed(iONode node) {
  Boolean defval = xBool( RocsWgen_fixed );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bbt, node );
  return NodeOp.getBool( node, "fixed", defval );
}
static void _setfixed(iONode node, Boolean p_fixed) {
  if( node == NULL ) return;
  xNode( RocsWgen_bbt, node );
  NodeOp.setBool( node, "fixed", p_fixed );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * frombk
 */
static struct __attrdef RocsWgen_frombk = {
  "frombk",  "From block ID.",  "",  "string",  "",  "*",  False,
};
static const char* _getfrombk(iONode node) {
  const char* defval = xStr( RocsWgen_frombk );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bbt, node );
  return NodeOp.getStr( node, "frombk", defval );
}
static void _setfrombk(iONode node, const char* p_frombk) {
  if( node == NULL ) return;
  xNode( RocsWgen_bbt, node );
  NodeOp.setStr( node, "frombk", p_frombk );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * generatein
 */
static struct __attrdef RocsWgen_generatein = {
  "generatein",  "Generate an IN event at the last BBT step.",  "",  "bool",  "False",  "",  False,
};
static Boolean _isgeneratein(iONode node) {
  Boolean defval = xBool( RocsWgen_generatein );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bbt, node );
  return NodeOp.getBool( node, "generatein", defval );
}
static void _setgeneratein(iONode node, Boolean p_generatein) {
  if( node == NULL ) return;
  xNode( RocsWgen_bbt, node );
  NodeOp.setBool( node, "generatein", p_generatein );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * interval
 */
static struct __attrdef RocsWgen_interval = {
  "interval",  "Brake interval.",  "10ms",  "int",  "1",  "1-*",  False,
};
static int _getinterval(iONode node) {
  int defval = xInt( RocsWgen_interval );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bbt, node );
  return NodeOp.getInt( node, "interval", defval );
}
static void _setinterval(iONode node, int p_interval) {
  if( node == NULL ) return;
  xNode( RocsWgen_bbt, node );
  NodeOp.setInt( node, "interval", p_interval );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * route
 */
static struct __attrdef RocsWgen_route = {
  "route",  "Route ID.",  "",  "string",  "",  "*",  False,
};
static const char* _getroute(iONode node) {
  const char* defval = xStr( RocsWgen_route );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bbt, node );
  return NodeOp.getStr( node, "route", defval );
}
static void _setroute(iONode node, const char* p_route) {
  if( node == NULL ) return;
  xNode( RocsWgen_bbt, node );
  NodeOp.setStr( node, "route", p_route );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * speed
 */
static struct __attrdef RocsWgen_speed = {
  "speed",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getspeed(iONode node) {
  int defval = xInt( RocsWgen_speed );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bbt, node );
  return NodeOp.getInt( node, "speed", defval );
}
static void _setspeed(iONode node, int p_speed) {
  if( node == NULL ) return;
  xNode( RocsWgen_bbt, node );
  NodeOp.setInt( node, "speed", p_speed );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * steps
 */
static struct __attrdef RocsWgen_steps = {
  "steps",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getsteps(iONode node) {
  int defval = xInt( RocsWgen_steps );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bbt, node );
  return NodeOp.getInt( node, "steps", defval );
}
static void _setsteps(iONode node, int p_steps) {
  if( node == NULL ) return;
  xNode( RocsWgen_bbt, node );
  NodeOp.setInt( node, "steps", p_steps );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[11] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_bbt.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node bbt not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node bbt not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_bk;
  attrList[1] = &RocsWgen_count;
  attrList[2] = &RocsWgen_delay;
  attrList[3] = &RocsWgen_fixed;
  attrList[4] = &RocsWgen_frombk;
  attrList[5] = &RocsWgen_generatein;
  attrList[6] = &RocsWgen_interval;
  attrList[7] = &RocsWgen_route;
  attrList[8] = &RocsWgen_speed;
  attrList[9] = &RocsWgen_steps;
  attrList[10] = NULL;
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


struct __wBBT wBBT = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getbk,
  _setbk,
  _getcount,
  _setcount,
  _getdelay,
  _setdelay,
  _isfixed,
  _setfixed,
  _getfrombk,
  _setfrombk,
  _isgeneratein,
  _setgeneratein,
  _getinterval,
  _setinterval,
  _getroute,
  _setroute,
  _getspeed,
  _setspeed,
  _getsteps,
  _setsteps,
  _node_dump,
};
