/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/PwrEvent.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.PwrEvent
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_powerevent = {
  "powerevent",  "Power Manager event.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_powerevent.name;
}
static const char* _node_remark(void) {
  return RocsWgen_powerevent.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_powerevent.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_powerevent.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "Booster ID; command for all not set.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_powerevent, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_powerevent, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * power
 */
static struct __attrdef RocsWgen_power = {
  "power",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _ispower(iONode node) {
  Boolean defval = xBool( RocsWgen_power );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_powerevent, node );
  return NodeOp.getBool( node, "power", defval );
}
static void _setpower(iONode node, Boolean p_power) {
  if( node == NULL ) return;
  xNode( RocsWgen_powerevent, node );
  NodeOp.setBool( node, "power", p_power );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * shortcut
 */
static struct __attrdef RocsWgen_shortcut = {
  "shortcut",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isshortcut(iONode node) {
  Boolean defval = xBool( RocsWgen_shortcut );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_powerevent, node );
  return NodeOp.getBool( node, "shortcut", defval );
}
static void _setshortcut(iONode node, Boolean p_shortcut) {
  if( node == NULL ) return;
  xNode( RocsWgen_powerevent, node );
  NodeOp.setBool( node, "shortcut", p_shortcut );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[4] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_powerevent.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node powerevent not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node powerevent not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_id;
  attrList[1] = &RocsWgen_power;
  attrList[2] = &RocsWgen_shortcut;
  attrList[3] = NULL;
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


struct __wPwrEvent wPwrEvent = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getid,
  _setid,
  _ispower,
  _setpower,
  _isshortcut,
  _setshortcut,
  _node_dump,
};
