/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/Schedule.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Schedule
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_sc = {
  "sc",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_sc.name;
}
static const char* _node_remark(void) {
  return RocsWgen_sc.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_sc.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_sc.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cycles
 */
static struct __attrdef RocsWgen_cycles = {
  "cycles",  "number of runs in case of cycle type: 0 is just one run",  "",  "int",  "0",  "0-*",  False,
};
static int _getcycles(iONode node) {
  int defval = xInt( RocsWgen_cycles );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sc, node );
  return NodeOp.getInt( node, "cycles", defval );
}
static void _setcycles(iONode node, int p_cycles) {
  if( node == NULL ) return;
  xNode( RocsWgen_sc, node );
  NodeOp.setInt( node, "cycles", p_cycles );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fromhour
 */
static struct __attrdef RocsWgen_fromhour = {
  "fromhour",  "",  "",  "int",  "0",  "0-23*",  False,
};
static int _getfromhour(iONode node) {
  int defval = xInt( RocsWgen_fromhour );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sc, node );
  return NodeOp.getInt( node, "fromhour", defval );
}
static void _setfromhour(iONode node, int p_fromhour) {
  if( node == NULL ) return;
  xNode( RocsWgen_sc, node );
  NodeOp.setInt( node, "fromhour", p_fromhour );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "schedule name",  "",  "string",  "",  "*",  True,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sc, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_sc, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * maxdelay
 */
static struct __attrdef RocsWgen_maxdelay = {
  "maxdelay",  "Depart only if the time is not delayed more than this number of minutes.",  "",  "int",  "60",  "0-*",  False,
};
static int _getmaxdelay(iONode node) {
  int defval = xInt( RocsWgen_maxdelay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sc, node );
  return NodeOp.getInt( node, "maxdelay", defval );
}
static void _setmaxdelay(iONode node, int p_maxdelay) {
  if( node == NULL ) return;
  xNode( RocsWgen_sc, node );
  NodeOp.setInt( node, "maxdelay", p_maxdelay );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * scaction
 */
static struct __attrdef RocsWgen_scaction = {
  "scaction",  "schedule action id",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getscaction(iONode node) {
  const char* defval = xStr( RocsWgen_scaction );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sc, node );
  return NodeOp.getStr( node, "scaction", defval );
}
static void _setscaction(iONode node, const char* p_scaction) {
  if( node == NULL ) return;
  xNode( RocsWgen_sc, node );
  NodeOp.setStr( node, "scaction", p_scaction );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timeframe
 */
static struct __attrdef RocsWgen_timeframe = {
  "timeframe",  "time frame for accepting a delay",  "",  "int",  "1",  "0-*",  False,
};
static int _gettimeframe(iONode node) {
  int defval = xInt( RocsWgen_timeframe );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sc, node );
  return NodeOp.getInt( node, "timeframe", defval );
}
static void _settimeframe(iONode node, int p_timeframe) {
  if( node == NULL ) return;
  xNode( RocsWgen_sc, node );
  NodeOp.setInt( node, "timeframe", p_timeframe );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timeprocessing
 */
static struct __attrdef RocsWgen_timeprocessing = {
  "timeprocessing",  "0=real 1=relative 2=hourly",  "",  "int",  "0",  "",  False,
};
static int _gettimeprocessing(iONode node) {
  int defval = xInt( RocsWgen_timeprocessing );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sc, node );
  return NodeOp.getInt( node, "timeprocessing", defval );
}
static void _settimeprocessing(iONode node, int p_timeprocessing) {
  if( node == NULL ) return;
  xNode( RocsWgen_sc, node );
  NodeOp.setInt( node, "timeprocessing", p_timeprocessing );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * tohour
 */
static struct __attrdef RocsWgen_tohour = {
  "tohour",  "",  "",  "int",  "0",  "0-23*",  False,
};
static int _gettohour(iONode node) {
  int defval = xInt( RocsWgen_tohour );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sc, node );
  return NodeOp.getInt( node, "tohour", defval );
}
static void _settohour(iONode node, int p_tohour) {
  if( node == NULL ) return;
  xNode( RocsWgen_sc, node );
  NodeOp.setInt( node, "tohour", p_tohour );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * type
 */
static struct __attrdef RocsWgen_type = {
  "type",  "how the schedule should be used",  "",  "string",  "cycle",  "cycle,commuter",  True,
};
static const char* _gettype(iONode node) {
  const char* defval = xStr( RocsWgen_type );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sc, node );
  return NodeOp.getStr( node, "type", defval );
}
static void _settype(iONode node, const char* p_type) {
  if( node == NULL ) return;
  xNode( RocsWgen_sc, node );
  NodeOp.setStr( node, "type", p_type );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * scentry
 */
static struct __nodedef RocsWgen_scentry = {
  "scentry",  "",  False,  "n",};
static iONode _getscentry(iONode node) {
  xNode( RocsWgen_sc, node );
  return NodeOp.findNode( node, "scentry");
}


static iONode _nextscentry(iONode node, iONode child) {
  xNode( RocsWgen_sc, node );
  return NodeOp.findNextNode( node, child);
}
static void _setscentry(iONode node, iONode p_scentry) {
  xNode( RocsWgen_sc, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * actionctrl
 */
static struct __nodedef RocsWgen_actionctrl = {
  "actionctrl",  "",  False,  "n",};
static iONode _getactionctrl(iONode node) {
  xNode( RocsWgen_sc, node );
  return NodeOp.findNode( node, "actionctrl");
}


static iONode _nextactionctrl(iONode node, iONode child) {
  xNode( RocsWgen_sc, node );
  return NodeOp.findNextNode( node, child);
}
static void _setactionctrl(iONode node, iONode p_actionctrl) {
  xNode( RocsWgen_sc, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[10] = {NULL};
static struct __nodedef* nodeList[3] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_sc.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node sc not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node sc not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_cycles;
  attrList[1] = &RocsWgen_fromhour;
  attrList[2] = &RocsWgen_id;
  attrList[3] = &RocsWgen_maxdelay;
  attrList[4] = &RocsWgen_scaction;
  attrList[5] = &RocsWgen_timeframe;
  attrList[6] = &RocsWgen_timeprocessing;
  attrList[7] = &RocsWgen_tohour;
  attrList[8] = &RocsWgen_type;
  attrList[9] = NULL;
  nodeList[0] = &RocsWgen_scentry;
  nodeList[1] = &RocsWgen_actionctrl;
  nodeList[2] = NULL;
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


struct __wSchedule wSchedule = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  2,
  0,
  1,
  "commuter",
  "cycle",
  _getcycles,
  _setcycles,
  _getfromhour,
  _setfromhour,
  _getid,
  _setid,
  _getmaxdelay,
  _setmaxdelay,
  _getscaction,
  _setscaction,
  _gettimeframe,
  _settimeframe,
  _gettimeprocessing,
  _settimeprocessing,
  _gettohour,
  _settohour,
  _gettype,
  _settype,
  _getscentry,
  _nextscentry,
  _setscentry,
  _getactionctrl,
  _nextactionctrl,
  _setactionctrl,
  _node_dump,
};
