/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/RouteCondition.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.RouteCondition
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_stcondition = {
  "stcondition",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_stcondition.name;
}
static const char* _node_remark(void) {
  return RocsWgen_stcondition.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_stcondition.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_stcondition.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * allowschedules
 */
static struct __attrdef RocsWgen_allowschedules = {
  "allowschedules",  "Allow schedules to use this route.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isallowschedules(iONode node) {
  Boolean defval = xBool( RocsWgen_allowschedules );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_stcondition, node );
  return NodeOp.getBool( node, "allowschedules", defval );
}
static void _setallowschedules(iONode node, Boolean p_allowschedules) {
  if( node == NULL ) return;
  xNode( RocsWgen_stcondition, node );
  NodeOp.setBool( node, "allowschedules", p_allowschedules );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * chdir
 */
static struct __attrdef RocsWgen_chdir = {
  "chdir",  "Must change direction.",  "",  "bool",  "false",  "",  False,
};
static Boolean _ischdir(iONode node) {
  Boolean defval = xBool( RocsWgen_chdir );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_stcondition, node );
  return NodeOp.getBool( node, "chdir", defval );
}
static void _setchdir(iONode node, Boolean p_chdir) {
  if( node == NULL ) return;
  xNode( RocsWgen_stcondition, node );
  NodeOp.setBool( node, "chdir", p_chdir );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * commuter
 */
static struct __attrdef RocsWgen_commuter = {
  "commuter",  "Commuter train.",  "",  "bool",  "false",  "",  False,
};
static Boolean _iscommuter(iONode node) {
  Boolean defval = xBool( RocsWgen_commuter );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_stcondition, node );
  return NodeOp.getBool( node, "commuter", defval );
}
static void _setcommuter(iONode node, Boolean p_commuter) {
  if( node == NULL ) return;
  xNode( RocsWgen_stcondition, node );
  NodeOp.setBool( node, "commuter", p_commuter );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * notprevbk
 */
static struct __attrdef RocsWgen_notprevbk = {
  "notprevbk",  "Not from previous block X.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isnotprevbk(iONode node) {
  Boolean defval = xBool( RocsWgen_notprevbk );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_stcondition, node );
  return NodeOp.getBool( node, "notprevbk", defval );
}
static void _setnotprevbk(iONode node, Boolean p_notprevbk) {
  if( node == NULL ) return;
  xNode( RocsWgen_stcondition, node );
  NodeOp.setBool( node, "notprevbk", p_notprevbk );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * prevbkid
 */
static struct __attrdef RocsWgen_prevbkid = {
  "prevbkid",  "Previous block ID.",  "",  "string",  "",  "",  False,
};
static const char* _getprevbkid(iONode node) {
  const char* defval = xStr( RocsWgen_prevbkid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_stcondition, node );
  return NodeOp.getStr( node, "prevbkid", defval );
}
static void _setprevbkid(iONode node, const char* p_prevbkid) {
  if( node == NULL ) return;
  xNode( RocsWgen_stcondition, node );
  NodeOp.setStr( node, "prevbkid", p_prevbkid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * type
 */
static struct __attrdef RocsWgen_type = {
  "type",  "Train type",  "",  "string",  "",  "",  False,
};
static const char* _gettype(iONode node) {
  const char* defval = xStr( RocsWgen_type );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_stcondition, node );
  return NodeOp.getStr( node, "type", defval );
}
static void _settype(iONode node, const char* p_type) {
  if( node == NULL ) return;
  xNode( RocsWgen_stcondition, node );
  NodeOp.setStr( node, "type", p_type );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[7] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_stcondition.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node stcondition not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node stcondition not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_allowschedules;
  attrList[1] = &RocsWgen_chdir;
  attrList[2] = &RocsWgen_commuter;
  attrList[3] = &RocsWgen_notprevbk;
  attrList[4] = &RocsWgen_prevbkid;
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


struct __wRouteCondition wRouteCondition = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isallowschedules,
  _setallowschedules,
  _ischdir,
  _setchdir,
  _iscommuter,
  _setcommuter,
  _isnotprevbk,
  _setnotprevbk,
  _getprevbkid,
  _setprevbkid,
  _gettype,
  _settype,
  _node_dump,
};
