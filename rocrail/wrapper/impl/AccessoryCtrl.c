/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/AccessoryCtrl.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.AccessoryCtrl
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_accessoryctrl = {
  "accessoryctrl",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_accessoryctrl.name;
}
static const char* _node_remark(void) {
  return RocsWgen_accessoryctrl.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_accessoryctrl.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_accessoryctrl.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * active
 */
static struct __attrdef RocsWgen_active = {
  "active",  "Activate accessory control.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isactive(iONode node) {
  Boolean defval = xBool( RocsWgen_active );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_accessoryctrl, node );
  return NodeOp.getBool( node, "active", defval );
}
static void _setactive(iONode node, Boolean p_active) {
  if( node == NULL ) return;
  xNode( RocsWgen_accessoryctrl, node );
  NodeOp.setBool( node, "active", p_active );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * delay
 */
static struct __attrdef RocsWgen_delay = {
  "delay",  "Seconds to elaps to go back to the closed position.",  "",  "int",  "0",  "",  False,
};
static int _getdelay(iONode node) {
  int defval = xInt( RocsWgen_delay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_accessoryctrl, node );
  return NodeOp.getInt( node, "delay", defval );
}
static void _setdelay(iONode node, int p_delay) {
  if( node == NULL ) return;
  xNode( RocsWgen_accessoryctrl, node );
  NodeOp.setInt( node, "delay", p_delay );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * freeblocks
 */
static struct __attrdef RocsWgen_freeblocks = {
  "freeblocks",  "",  "",  "string",  "",  "Blocks which must be free at open and close.",  False,
};
static const char* _getfreeblocks(iONode node) {
  const char* defval = xStr( RocsWgen_freeblocks );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_accessoryctrl, node );
  return NodeOp.getStr( node, "freeblocks", defval );
}
static void _setfreeblocks(iONode node, const char* p_freeblocks) {
  if( node == NULL ) return;
  xNode( RocsWgen_accessoryctrl, node );
  NodeOp.setStr( node, "freeblocks", p_freeblocks );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * interval
 */
static struct __attrdef RocsWgen_interval = {
  "interval",  "Interval in seconds.",  "",  "int",  "0",  "",  False,
};
static int _getinterval(iONode node) {
  int defval = xInt( RocsWgen_interval );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_accessoryctrl, node );
  return NodeOp.getInt( node, "interval", defval );
}
static void _setinterval(iONode node, int p_interval) {
  if( node == NULL ) return;
  xNode( RocsWgen_accessoryctrl, node );
  NodeOp.setInt( node, "interval", p_interval );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lockroutes
 */
static struct __attrdef RocsWgen_lockroutes = {
  "lockroutes",  "",  "",  "string",  "",  "Routes to lock at open, and unlock at close.",  False,
};
static const char* _getlockroutes(iONode node) {
  const char* defval = xStr( RocsWgen_lockroutes );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_accessoryctrl, node );
  return NodeOp.getStr( node, "lockroutes", defval );
}
static void _setlockroutes(iONode node, const char* p_lockroutes) {
  if( node == NULL ) return;
  xNode( RocsWgen_accessoryctrl, node );
  NodeOp.setStr( node, "lockroutes", p_lockroutes );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[6] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_accessoryctrl.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node accessoryctrl not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node accessoryctrl not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_active;
  attrList[1] = &RocsWgen_delay;
  attrList[2] = &RocsWgen_freeblocks;
  attrList[3] = &RocsWgen_interval;
  attrList[4] = &RocsWgen_lockroutes;
  attrList[5] = NULL;
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


struct __wAccessoryCtrl wAccessoryCtrl = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isactive,
  _setactive,
  _getdelay,
  _setdelay,
  _getfreeblocks,
  _setfreeblocks,
  _getinterval,
  _setinterval,
  _getlockroutes,
  _setlockroutes,
  _node_dump,
};
