/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/FeedbackEvent.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.FeedbackEvent
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_fbevent = {
  "fbevent",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_fbevent.name;
}
static const char* _node_remark(void) {
  return RocsWgen_fbevent.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_fbevent.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_fbevent.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * action
 */
static struct __attrdef RocsWgen_action = {
  "action",  "",  "",  "string",  "",  "enter,enter2route,enter2pre,enter2in,enter2shortin,shortin,in,exit,occupied,V_min,V_mid,V_max,V_cruise",  False,
};
static const char* _getaction(iONode node) {
  const char* defval = xStr( RocsWgen_action );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fbevent, node );
  return NodeOp.getStr( node, "action", defval );
}
static void _setaction(iONode node, const char* p_action) {
  if( node == NULL ) return;
  xNode( RocsWgen_fbevent, node );
  NodeOp.setStr( node, "action", p_action );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * byroute
 */
static struct __attrdef RocsWgen_byroute = {
  "byroute",  "Comming from block x by route y. (optional)",  "",  "string",  "",  "*",  False,
};
static const char* _getbyroute(iONode node) {
  const char* defval = xStr( RocsWgen_byroute );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fbevent, node );
  return NodeOp.getStr( node, "byroute", defval );
}
static void _setbyroute(iONode node, const char* p_byroute) {
  if( node == NULL ) return;
  xNode( RocsWgen_fbevent, node );
  NodeOp.setStr( node, "byroute", p_byroute );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * endpuls
 */
static struct __attrdef RocsWgen_endpuls = {
  "endpuls",  "use the down flank of the puls",  "",  "bool",  "false",  "",  False,
};
static Boolean _isendpuls(iONode node) {
  Boolean defval = xBool( RocsWgen_endpuls );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fbevent, node );
  return NodeOp.getBool( node, "endpuls", defval );
}
static void _setendpuls(iONode node, Boolean p_endpuls) {
  if( node == NULL ) return;
  xNode( RocsWgen_fbevent, node );
  NodeOp.setBool( node, "endpuls", p_endpuls );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * from
 */
static struct __attrdef RocsWgen_from = {
  "from",  "from block id (csv list for more blocks)",  "",  "string",  "",  "*",  False,
};
static const char* _getfrom(iONode node) {
  const char* defval = xStr( RocsWgen_from );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fbevent, node );
  return NodeOp.getStr( node, "from", defval );
}
static void _setfrom(iONode node, const char* p_from) {
  if( node == NULL ) return;
  xNode( RocsWgen_fbevent, node );
  NodeOp.setStr( node, "from", p_from );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "feedback ID",  "",  "string",  "",  "*",  True,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fbevent, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_fbevent, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * use_timer2
 */
static struct __attrdef RocsWgen_use_timer2 = {
  "use_timer2",  "use reverse direction timer",  "",  "bool",  "false",  "",  False,
};
static Boolean _isuse_timer2(iONode node) {
  Boolean defval = xBool( RocsWgen_use_timer2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fbevent, node );
  return NodeOp.getBool( node, "use_timer2", defval );
}
static void _setuse_timer2(iONode node, Boolean p_use_timer2) {
  if( node == NULL ) return;
  xNode( RocsWgen_fbevent, node );
  NodeOp.setBool( node, "use_timer2", p_use_timer2 );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[7] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_fbevent.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node fbevent not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node fbevent not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_action;
  attrList[1] = &RocsWgen_byroute;
  attrList[2] = &RocsWgen_endpuls;
  attrList[3] = &RocsWgen_from;
  attrList[4] = &RocsWgen_id;
  attrList[5] = &RocsWgen_use_timer2;
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


struct __wFeedbackEvent wFeedbackEvent = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "V_cruise",
  "V_max",
  "V_mid",
  "V_min",
  "enter2in",
  "enter2pre",
  "enter2route",
  "enter2shortin",
  "enter",
  "exit",
  "free",
  "all",
  "all-reverse",
  "ident",
  "in",
  "occupied",
  "pre2in",
  "section",
  "shortin",
  _getaction,
  _setaction,
  _getbyroute,
  _setbyroute,
  _isendpuls,
  _setendpuls,
  _getfrom,
  _setfrom,
  _getid,
  _setid,
  _isuse_timer2,
  _setuse_timer2,
  _node_dump,
};
