/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/ModelCmd.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.ModelCmd
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_model = {
  "model",  "Model command.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_model.name;
}
static const char* _node_remark(void) {
  return RocsWgen_model.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_model.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_model.cardinality;
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
  xNode( RocsWgen_model, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_model, node );
  NodeOp.setStr( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmdfrom
 */
static struct __attrdef RocsWgen_cmdfrom = {
  "cmdfrom",  "",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getcmdfrom(iONode node) {
  const char* defval = xStr( RocsWgen_cmdfrom );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_model, node );
  return NodeOp.getStr( node, "cmdfrom", defval );
}
static void _setcmdfrom(iONode node, const char* p_cmdfrom) {
  if( node == NULL ) return;
  xNode( RocsWgen_model, node );
  NodeOp.setStr( node, "cmdfrom", p_cmdfrom );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * controlcode
 */
static struct __attrdef RocsWgen_controlcode = {
  "controlcode",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getcontrolcode(iONode node) {
  const char* defval = xStr( RocsWgen_controlcode );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_model, node );
  return NodeOp.getStr( node, "controlcode", defval );
}
static void _setcontrolcode(iONode node, const char* p_controlcode) {
  if( node == NULL ) return;
  xNode( RocsWgen_model, node );
  NodeOp.setStr( node, "controlcode", p_controlcode );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * disablemonitor
 */
static struct __attrdef RocsWgen_disablemonitor = {
  "disablemonitor",  "Client do not want to receive monitor messages embeded in exception wrappers.(iRoc)",  "",  "bool",  "false",  "",  False,
};
static Boolean _isdisablemonitor(iONode node) {
  Boolean defval = xBool( RocsWgen_disablemonitor );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_model, node );
  return NodeOp.getBool( node, "disablemonitor", defval );
}
static void _setdisablemonitor(iONode node, Boolean p_disablemonitor) {
  if( node == NULL ) return;
  xNode( RocsWgen_model, node );
  NodeOp.setBool( node, "disablemonitor", p_disablemonitor );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val
 */
static struct __attrdef RocsWgen_val = {
  "val",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getval(iONode node) {
  const char* defval = xStr( RocsWgen_val );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_model, node );
  return NodeOp.getStr( node, "val", defval );
}
static void _setval(iONode node, const char* p_val) {
  if( node == NULL ) return;
  xNode( RocsWgen_model, node );
  NodeOp.setStr( node, "val", p_val );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[6] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_model.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node model not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node model not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_cmd;
  attrList[1] = &RocsWgen_cmdfrom;
  attrList[2] = &RocsWgen_controlcode;
  attrList[3] = &RocsWgen_disablemonitor;
  attrList[4] = &RocsWgen_val;
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


struct __wModelCmd wModelCmd = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "add",
  "addmodule",
  "bklist",
  "dontsaveonexit",
  "fstat",
  "initfield",
  "lclist",
  "lcprops",
  "merge",
  "modify",
  "move",
  "plan",
  "plantitle",
  "remove",
  "save",
  "sclist",
  "stlist",
  "swlist",
  "themes",
  _getcmd,
  _setcmd,
  _getcmdfrom,
  _setcmdfrom,
  _getcontrolcode,
  _setcontrolcode,
  _isdisablemonitor,
  _setdisablemonitor,
  _getval,
  _setval,
  _node_dump,
};
