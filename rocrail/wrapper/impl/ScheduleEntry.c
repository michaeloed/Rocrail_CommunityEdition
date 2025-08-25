/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/ScheduleEntry.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.ScheduleEntry
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_scentry = {
  "scentry",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_scentry.name;
}
static const char* _node_remark(void) {
  return RocsWgen_scentry.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_scentry.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_scentry.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * block
 */
static struct __attrdef RocsWgen_block = {
  "block",  "Block from the blocklist",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getblock(iONode node) {
  const char* defval = xStr( RocsWgen_block );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_scentry, node );
  return NodeOp.getStr( node, "block", defval );
}
static void _setblock(iONode node, const char* p_block) {
  if( node == NULL ) return;
  xNode( RocsWgen_scentry, node );
  NodeOp.setStr( node, "block", p_block );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * free2go
 */
static struct __attrdef RocsWgen_free2go = {
  "free2go",  "Block or location must be free before the schedule can start.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isfree2go(iONode node) {
  Boolean defval = xBool( RocsWgen_free2go );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_scentry, node );
  return NodeOp.getBool( node, "free2go", defval );
}
static void _setfree2go(iONode node, Boolean p_free2go) {
  if( node == NULL ) return;
  xNode( RocsWgen_scentry, node );
  NodeOp.setBool( node, "free2go", p_free2go );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * hour
 */
static struct __attrdef RocsWgen_hour = {
  "hour",  "Departure hour",  "",  "int",  "0",  "",  False,
};
static int _gethour(iONode node) {
  int defval = xInt( RocsWgen_hour );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_scentry, node );
  return NodeOp.getInt( node, "hour", defval );
}
static void _sethour(iONode node, int p_hour) {
  if( node == NULL ) return;
  xNode( RocsWgen_scentry, node );
  NodeOp.setInt( node, "hour", p_hour );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * indelay
 */
static struct __attrdef RocsWgen_indelay = {
  "indelay",  "in event delay timer",  "",  "int",  "0",  "",  False,
};
static int _getindelay(iONode node) {
  int defval = xInt( RocsWgen_indelay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_scentry, node );
  return NodeOp.getInt( node, "indelay", defval );
}
static void _setindelay(iONode node, int p_indelay) {
  if( node == NULL ) return;
  xNode( RocsWgen_scentry, node );
  NodeOp.setInt( node, "indelay", p_indelay );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * location
 */
static struct __attrdef RocsWgen_location = {
  "location",  "Location from the locationlist",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getlocation(iONode node) {
  const char* defval = xStr( RocsWgen_location );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_scentry, node );
  return NodeOp.getStr( node, "location", defval );
}
static void _setlocation(iONode node, const char* p_location) {
  if( node == NULL ) return;
  xNode( RocsWgen_scentry, node );
  NodeOp.setStr( node, "location", p_location );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * minute
 */
static struct __attrdef RocsWgen_minute = {
  "minute",  "Departure minute",  "",  "int",  "0",  "",  False,
};
static int _getminute(iONode node) {
  int defval = xInt( RocsWgen_minute );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_scentry, node );
  return NodeOp.getInt( node, "minute", defval );
}
static void _setminute(iONode node, int p_minute) {
  if( node == NULL ) return;
  xNode( RocsWgen_scentry, node );
  NodeOp.setInt( node, "minute", p_minute );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * swap
 */
static struct __attrdef RocsWgen_swap = {
  "swap",  "swap the loc placing before traveling to this destination",  "",  "bool",  "false",  "",  False,
};
static Boolean _isswap(iONode node) {
  Boolean defval = xBool( RocsWgen_swap );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_scentry, node );
  return NodeOp.getBool( node, "swap", defval );
}
static void _setswap(iONode node, Boolean p_swap) {
  if( node == NULL ) return;
  xNode( RocsWgen_scentry, node );
  NodeOp.setBool( node, "swap", p_swap );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * actionctrl
 */
static struct __nodedef RocsWgen_actionctrl = {
  "actionctrl",  "",  False,  "n",};
static iONode _getactionctrl(iONode node) {
  xNode( RocsWgen_scentry, node );
  return NodeOp.findNode( node, "actionctrl");
}


static iONode _nextactionctrl(iONode node, iONode child) {
  xNode( RocsWgen_scentry, node );
  return NodeOp.findNextNode( node, child);
}
static void _setactionctrl(iONode node, iONode p_actionctrl) {
  xNode( RocsWgen_scentry, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[8] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_scentry.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node scentry not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node scentry not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_block;
  attrList[1] = &RocsWgen_free2go;
  attrList[2] = &RocsWgen_hour;
  attrList[3] = &RocsWgen_indelay;
  attrList[4] = &RocsWgen_location;
  attrList[5] = &RocsWgen_minute;
  attrList[6] = &RocsWgen_swap;
  attrList[7] = NULL;
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


struct __wScheduleEntry wScheduleEntry = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getblock,
  _setblock,
  _isfree2go,
  _setfree2go,
  _gethour,
  _sethour,
  _getindelay,
  _setindelay,
  _getlocation,
  _setlocation,
  _getminute,
  _setminute,
  _isswap,
  _setswap,
  _getactionctrl,
  _nextactionctrl,
  _setactionctrl,
  _node_dump,
};
