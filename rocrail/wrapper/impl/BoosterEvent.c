/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/BoosterEvent.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.BoosterEvent
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_boosterevent = {
  "boosterevent",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_boosterevent.name;
}
static const char* _node_remark(void) {
  return RocsWgen_boosterevent.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_boosterevent.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_boosterevent.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * load
 */
static struct __attrdef RocsWgen_load = {
  "load",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getload(iONode node) {
  int defval = xInt( RocsWgen_load );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_boosterevent, node );
  return NodeOp.getInt( node, "load", defval );
}
static void _setload(iONode node, int p_load) {
  if( node == NULL ) return;
  xNode( RocsWgen_boosterevent, node );
  NodeOp.setInt( node, "load", p_load );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * temp
 */
static struct __attrdef RocsWgen_temp = {
  "temp",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _gettemp(iONode node) {
  int defval = xInt( RocsWgen_temp );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_boosterevent, node );
  return NodeOp.getInt( node, "temp", defval );
}
static void _settemp(iONode node, int p_temp) {
  if( node == NULL ) return;
  xNode( RocsWgen_boosterevent, node );
  NodeOp.setInt( node, "temp", p_temp );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timestamp
 */
static struct __attrdef RocsWgen_timestamp = {
  "timestamp",  "",  "",  "long",  "0",  "",  False,
};
static long _gettimestamp(iONode node) {
  long defval = xLong( RocsWgen_timestamp );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_boosterevent, node );
  return NodeOp.getLong( node, "timestamp", defval );
}
static void _settimestamp(iONode node, long p_timestamp) {
  if( node == NULL ) return;
  xNode( RocsWgen_boosterevent, node );
  NodeOp.setLong( node, "timestamp", p_timestamp );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * volt
 */
static struct __attrdef RocsWgen_volt = {
  "volt",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getvolt(iONode node) {
  int defval = xInt( RocsWgen_volt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_boosterevent, node );
  return NodeOp.getInt( node, "volt", defval );
}
static void _setvolt(iONode node, int p_volt) {
  if( node == NULL ) return;
  xNode( RocsWgen_boosterevent, node );
  NodeOp.setInt( node, "volt", p_volt );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[5] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_boosterevent.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node boosterevent not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node boosterevent not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_load;
  attrList[1] = &RocsWgen_temp;
  attrList[2] = &RocsWgen_timestamp;
  attrList[3] = &RocsWgen_volt;
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


struct __wBoosterEvent wBoosterEvent = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getload,
  _setload,
  _gettemp,
  _settemp,
  _gettimestamp,
  _settimestamp,
  _getvolt,
  _setvolt,
  _node_dump,
};
