/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/PwrCmd.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.PwrCmd
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_powercmd = {
  "powercmd",  "Power Manager command.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_powercmd.name;
}
static const char* _node_remark(void) {
  return RocsWgen_powercmd.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_powercmd.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_powercmd.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blockid
 */
static struct __attrdef RocsWgen_blockid = {
  "blockid",  "Block ID.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getblockid(iONode node) {
  const char* defval = xStr( RocsWgen_blockid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_powercmd, node );
  return NodeOp.getStr( node, "blockid", defval );
}
static void _setblockid(iONode node, const char* p_blockid) {
  if( node == NULL ) return;
  xNode( RocsWgen_powercmd, node );
  NodeOp.setStr( node, "blockid", p_blockid );
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
  xNode( RocsWgen_powercmd, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_powercmd, node );
  NodeOp.setStr( node, "cmd", p_cmd );
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
  xNode( RocsWgen_powercmd, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_powercmd, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iid
 */
static struct __attrdef RocsWgen_iid = {
  "iid",  "Interface ID",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getiid(iONode node) {
  const char* defval = xStr( RocsWgen_iid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_powercmd, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_powercmd, node );
  NodeOp.setStr( node, "iid", p_iid );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[5] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_powercmd.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node powercmd not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node powercmd not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_blockid;
  attrList[1] = &RocsWgen_cmd;
  attrList[2] = &RocsWgen_id;
  attrList[3] = &RocsWgen_iid;
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


struct __wPwrCmd wPwrCmd = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "off",
  "on",
  _getblockid,
  _setblockid,
  _getcmd,
  _setcmd,
  _getid,
  _setid,
  _getiid,
  _setiid,
  _node_dump,
};
