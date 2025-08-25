/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:52 2018
  */

#include "rocview/wrapper/public/MGVServo.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.MGVServo
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_mgvservo = {
  "mgvservo",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_mgvservo.name;
}
static const char* _node_remark(void) {
  return RocsWgen_mgvservo.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_mgvservo.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_mgvservo.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr
 */
static struct __attrdef RocsWgen_addr = {
  "addr",  "",  "",  "int",  "0",  "",  False,
};
static int _getaddr(iONode node) {
  int defval = xInt( RocsWgen_addr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mgvservo, node );
  return NodeOp.getInt( node, "addr", defval );
}
static void _setaddr(iONode node, int p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_mgvservo, node );
  NodeOp.setInt( node, "addr", p_addr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bounce
 */
static struct __attrdef RocsWgen_bounce = {
  "bounce",  "",  "",  "int",  "0",  "",  False,
};
static int _getbounce(iONode node) {
  int defval = xInt( RocsWgen_bounce );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mgvservo, node );
  return NodeOp.getInt( node, "bounce", defval );
}
static void _setbounce(iONode node, int p_bounce) {
  if( node == NULL ) return;
  xNode( RocsWgen_mgvservo, node );
  NodeOp.setInt( node, "bounce", p_bounce );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * leftangle
 */
static struct __attrdef RocsWgen_leftangle = {
  "leftangle",  "",  "",  "int",  "0",  "",  False,
};
static int _getleftangle(iONode node) {
  int defval = xInt( RocsWgen_leftangle );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mgvservo, node );
  return NodeOp.getInt( node, "leftangle", defval );
}
static void _setleftangle(iONode node, int p_leftangle) {
  if( node == NULL ) return;
  xNode( RocsWgen_mgvservo, node );
  NodeOp.setInt( node, "leftangle", p_leftangle );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "",  "",  "int",  "0",  "",  False,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mgvservo, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_mgvservo, node );
  NodeOp.setInt( node, "port", p_port );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * relay
 */
static struct __attrdef RocsWgen_relay = {
  "relay",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isrelay(iONode node) {
  Boolean defval = xBool( RocsWgen_relay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mgvservo, node );
  return NodeOp.getBool( node, "relay", defval );
}
static void _setrelay(iONode node, Boolean p_relay) {
  if( node == NULL ) return;
  xNode( RocsWgen_mgvservo, node );
  NodeOp.setBool( node, "relay", p_relay );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * rightangle
 */
static struct __attrdef RocsWgen_rightangle = {
  "rightangle",  "",  "",  "int",  "0",  "",  False,
};
static int _getrightangle(iONode node) {
  int defval = xInt( RocsWgen_rightangle );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mgvservo, node );
  return NodeOp.getInt( node, "rightangle", defval );
}
static void _setrightangle(iONode node, int p_rightangle) {
  if( node == NULL ) return;
  xNode( RocsWgen_mgvservo, node );
  NodeOp.setInt( node, "rightangle", p_rightangle );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * speed
 */
static struct __attrdef RocsWgen_speed = {
  "speed",  "",  "",  "int",  "0",  "",  False,
};
static int _getspeed(iONode node) {
  int defval = xInt( RocsWgen_speed );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mgvservo, node );
  return NodeOp.getInt( node, "speed", defval );
}
static void _setspeed(iONode node, int p_speed) {
  if( node == NULL ) return;
  xNode( RocsWgen_mgvservo, node );
  NodeOp.setInt( node, "speed", p_speed );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[8] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_mgvservo.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node mgvservo not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node mgvservo not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_addr;
  attrList[1] = &RocsWgen_bounce;
  attrList[2] = &RocsWgen_leftangle;
  attrList[3] = &RocsWgen_port;
  attrList[4] = &RocsWgen_relay;
  attrList[5] = &RocsWgen_rightangle;
  attrList[6] = &RocsWgen_speed;
  attrList[7] = NULL;
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


struct __wMGVServo wMGVServo = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getaddr,
  _setaddr,
  _getbounce,
  _setbounce,
  _getleftangle,
  _setleftangle,
  _getport,
  _setport,
  _isrelay,
  _setrelay,
  _getrightangle,
  _setrightangle,
  _getspeed,
  _setspeed,
  _node_dump,
};
