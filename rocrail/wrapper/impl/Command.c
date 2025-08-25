/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Command.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Command
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_command = {
  "command",  "Command.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_command.name;
}
static const char* _node_remark(void) {
  return RocsWgen_command.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_command.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_command.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * arg
 */
static struct __attrdef RocsWgen_arg = {
  "arg",  "command arguments",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getarg(iONode node) {
  const char* defval = xStr( RocsWgen_arg );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_command, node );
  return NodeOp.getStr( node, "arg", defval );
}
static void _setarg(iONode node, const char* p_arg) {
  if( node == NULL ) return;
  xNode( RocsWgen_command, node );
  NodeOp.setStr( node, "arg", p_arg );
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
  xNode( RocsWgen_command, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_command, node );
  NodeOp.setStr( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_command, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_command, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iid
 */
static struct __attrdef RocsWgen_iid = {
  "iid",  "",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getiid(iONode node) {
  const char* defval = xStr( RocsWgen_iid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_command, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_command, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * server
 */
static struct __attrdef RocsWgen_server = {
  "server",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getserver(iONode node) {
  const char* defval = xStr( RocsWgen_server );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_command, node );
  return NodeOp.getStr( node, "server", defval );
}
static void _setserver(iONode node, const char* p_server) {
  if( node == NULL ) return;
  xNode( RocsWgen_command, node );
  NodeOp.setStr( node, "server", p_server );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[6] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_command.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node command not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node command not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_arg;
  attrList[1] = &RocsWgen_cmd;
  attrList[2] = &RocsWgen_id;
  attrList[3] = &RocsWgen_iid;
  attrList[4] = &RocsWgen_server;
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


struct __wCommand wCommand = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "fbmods",
  _getarg,
  _setarg,
  _getcmd,
  _setcmd,
  _getid,
  _setid,
  _getiid,
  _setiid,
  _getserver,
  _setserver,
  _node_dump,
};
