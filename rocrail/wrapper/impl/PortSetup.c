/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/PortSetup.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.PortSetup
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_portsetup = {
  "portsetup",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_portsetup.name;
}
static const char* _node_remark(void) {
  return RocsWgen_portsetup.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_portsetup.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_portsetup.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * delay
 */
static struct __attrdef RocsWgen_delay = {
  "delay",  "0=directly/continous",  "",  "int",  "0",  "0-*",  False,
};
static int _getdelay(iONode node) {
  int defval = xInt( RocsWgen_delay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_portsetup, node );
  return NodeOp.getInt( node, "delay", defval );
}
static void _setdelay(iONode node, int p_delay) {
  if( node == NULL ) return;
  xNode( RocsWgen_portsetup, node );
  NodeOp.setInt( node, "delay", p_delay );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * eventid
 */
static struct __attrdef RocsWgen_eventid = {
  "eventid",  "",  "",  "int",  "0",  "",  False,
};
static int _geteventid(iONode node) {
  int defval = xInt( RocsWgen_eventid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_portsetup, node );
  return NodeOp.getInt( node, "eventid", defval );
}
static void _seteventid(iONode node, int p_eventid) {
  if( node == NULL ) return;
  xNode( RocsWgen_portsetup, node );
  NodeOp.setInt( node, "eventid", p_eventid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * eventport
 */
static struct __attrdef RocsWgen_eventport = {
  "eventport",  "",  "",  "int",  "0",  "",  False,
};
static int _geteventport(iONode node) {
  int defval = xInt( RocsWgen_eventport );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_portsetup, node );
  return NodeOp.getInt( node, "eventport", defval );
}
static void _seteventport(iONode node, int p_eventport) {
  if( node == NULL ) return;
  xNode( RocsWgen_portsetup, node );
  NodeOp.setInt( node, "eventport", p_eventport );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "",  "",  "int",  "1",  "1-*",  False,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_portsetup, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_portsetup, node );
  NodeOp.setInt( node, "port", p_port );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * state
 */
static struct __attrdef RocsWgen_state = {
  "state",  "Saved output state.",  "",  "int",  "0",  "",  False,
};
static int _getstate(iONode node) {
  int defval = xInt( RocsWgen_state );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_portsetup, node );
  return NodeOp.getInt( node, "state", defval );
}
static void _setstate(iONode node, int p_state) {
  if( node == NULL ) return;
  xNode( RocsWgen_portsetup, node );
  NodeOp.setInt( node, "state", p_state );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * type
 */
static struct __attrdef RocsWgen_type = {
  "type",  "0=output, 1=input",  "",  "int",  "0",  "0-*",  False,
};
static int _gettype(iONode node) {
  int defval = xInt( RocsWgen_type );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_portsetup, node );
  return NodeOp.getInt( node, "type", defval );
}
static void _settype(iONode node, int p_type) {
  if( node == NULL ) return;
  xNode( RocsWgen_portsetup, node );
  NodeOp.setInt( node, "type", p_type );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[7] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_portsetup.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node portsetup not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node portsetup not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_delay;
  attrList[1] = &RocsWgen_eventid;
  attrList[2] = &RocsWgen_eventport;
  attrList[3] = &RocsWgen_port;
  attrList[4] = &RocsWgen_state;
  attrList[5] = &RocsWgen_type;
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


struct __wPortSetup wPortSetup = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getdelay,
  _setdelay,
  _geteventid,
  _seteventid,
  _geteventport,
  _seteventport,
  _getport,
  _setport,
  _getstate,
  _setstate,
  _gettype,
  _settype,
  _node_dump,
};
