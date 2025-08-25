/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Clock.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Clock
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_clock = {
  "clock",  "clock synchronizer.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_clock.name;
}
static const char* _node_remark(void) {
  return RocsWgen_clock.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_clock.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_clock.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmd
 */
static struct __attrdef RocsWgen_cmd = {
  "cmd",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getcmd(iONode node) {
  const char* defval = xStr( RocsWgen_cmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_clock, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_clock, node );
  NodeOp.setStr( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * divider
 */
static struct __attrdef RocsWgen_divider = {
  "divider",  "time devider: 1 = realtime",  "",  "int",  "1",  "1-100",  False,
};
static int _getdivider(iONode node) {
  int defval = xInt( RocsWgen_divider );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_clock, node );
  return NodeOp.getInt( node, "divider", defval );
}
static void _setdivider(iONode node, int p_divider) {
  if( node == NULL ) return;
  xNode( RocsWgen_clock, node );
  NodeOp.setInt( node, "divider", p_divider );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * hour
 */
static struct __attrdef RocsWgen_hour = {
  "hour",  "start hour; 24 not used",  "",  "int",  "24",  "0-24",  False,
};
static int _gethour(iONode node) {
  int defval = xInt( RocsWgen_hour );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_clock, node );
  return NodeOp.getInt( node, "hour", defval );
}
static void _sethour(iONode node, int p_hour) {
  if( node == NULL ) return;
  xNode( RocsWgen_clock, node );
  NodeOp.setInt( node, "hour", p_hour );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * minute
 */
static struct __attrdef RocsWgen_minute = {
  "minute",  "start minute; 60 not used",  "",  "int",  "60",  "0-60",  False,
};
static int _getminute(iONode node) {
  int defval = xInt( RocsWgen_minute );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_clock, node );
  return NodeOp.getInt( node, "minute", defval );
}
static void _setminute(iONode node, int p_minute) {
  if( node == NULL ) return;
  xNode( RocsWgen_clock, node );
  NodeOp.setInt( node, "minute", p_minute );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * stopclockatpoweroff
 */
static struct __attrdef RocsWgen_stopclockatpoweroff = {
  "stopclockatpoweroff",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isstopclockatpoweroff(iONode node) {
  Boolean defval = xBool( RocsWgen_stopclockatpoweroff );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_clock, node );
  return NodeOp.getBool( node, "stopclockatpoweroff", defval );
}
static void _setstopclockatpoweroff(iONode node, Boolean p_stopclockatpoweroff) {
  if( node == NULL ) return;
  xNode( RocsWgen_clock, node );
  NodeOp.setBool( node, "stopclockatpoweroff", p_stopclockatpoweroff );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * temp
 */
static struct __attrdef RocsWgen_temp = {
  "temp",  "Model temperature.",  "",  "int",  "20",  "-127...127",  False,
};
static int _gettemp(iONode node) {
  int defval = xInt( RocsWgen_temp );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_clock, node );
  return NodeOp.getInt( node, "temp", defval );
}
static void _settemp(iONode node, int p_temp) {
  if( node == NULL ) return;
  xNode( RocsWgen_clock, node );
  NodeOp.setInt( node, "temp", p_temp );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * time
 */
static struct __attrdef RocsWgen_time = {
  "time",  "time in seconds",  "",  "long",  "0",  "*",  False,
};
static long _gettime(iONode node) {
  long defval = xLong( RocsWgen_time );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_clock, node );
  return NodeOp.getLong( node, "time", defval );
}
static void _settime(iONode node, long p_time) {
  if( node == NULL ) return;
  xNode( RocsWgen_clock, node );
  NodeOp.setLong( node, "time", p_time );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * update
 */
static struct __attrdef RocsWgen_update = {
  "update",  "update frequency in minutes",  "",  "int",  "1",  "1-60",  False,
};
static int _getupdate(iONode node) {
  int defval = xInt( RocsWgen_update );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_clock, node );
  return NodeOp.getInt( node, "update", defval );
}
static void _setupdate(iONode node, int p_update) {
  if( node == NULL ) return;
  xNode( RocsWgen_clock, node );
  NodeOp.setInt( node, "update", p_update );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[9] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_clock.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node clock not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node clock not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_cmd;
  attrList[1] = &RocsWgen_divider;
  attrList[2] = &RocsWgen_hour;
  attrList[3] = &RocsWgen_minute;
  attrList[4] = &RocsWgen_stopclockatpoweroff;
  attrList[5] = &RocsWgen_temp;
  attrList[6] = &RocsWgen_time;
  attrList[7] = &RocsWgen_update;
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


struct __wClock wClock = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "freeze",
  "go",
  "set",
  "sync",
  _getcmd,
  _setcmd,
  _getdivider,
  _setdivider,
  _gethour,
  _sethour,
  _getminute,
  _setminute,
  _isstopclockatpoweroff,
  _setstopclockatpoweroff,
  _gettemp,
  _settemp,
  _gettime,
  _settime,
  _getupdate,
  _setupdate,
  _node_dump,
};
