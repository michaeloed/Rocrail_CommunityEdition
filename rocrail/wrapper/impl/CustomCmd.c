/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/CustomCmd.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.CustomCmd
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_custom = {
  "custom",  "Custom Command for interfaces",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_custom.name;
}
static const char* _node_remark(void) {
  return RocsWgen_custom.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_custom.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_custom.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * arg1
 */
static struct __attrdef RocsWgen_arg1 = {
  "arg1",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getarg1(iONode node) {
  const char* defval = xStr( RocsWgen_arg1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_custom, node );
  return NodeOp.getStr( node, "arg1", defval );
}
static void _setarg1(iONode node, const char* p_arg1) {
  if( node == NULL ) return;
  xNode( RocsWgen_custom, node );
  NodeOp.setStr( node, "arg1", p_arg1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * arg2
 */
static struct __attrdef RocsWgen_arg2 = {
  "arg2",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getarg2(iONode node) {
  const char* defval = xStr( RocsWgen_arg2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_custom, node );
  return NodeOp.getStr( node, "arg2", defval );
}
static void _setarg2(iONode node, const char* p_arg2) {
  if( node == NULL ) return;
  xNode( RocsWgen_custom, node );
  NodeOp.setStr( node, "arg2", p_arg2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * arg3
 */
static struct __attrdef RocsWgen_arg3 = {
  "arg3",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getarg3(iONode node) {
  const char* defval = xStr( RocsWgen_arg3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_custom, node );
  return NodeOp.getStr( node, "arg3", defval );
}
static void _setarg3(iONode node, const char* p_arg3) {
  if( node == NULL ) return;
  xNode( RocsWgen_custom, node );
  NodeOp.setStr( node, "arg3", p_arg3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * arg4
 */
static struct __attrdef RocsWgen_arg4 = {
  "arg4",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getarg4(iONode node) {
  const char* defval = xStr( RocsWgen_arg4 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_custom, node );
  return NodeOp.getStr( node, "arg4", defval );
}
static void _setarg4(iONode node, const char* p_arg4) {
  if( node == NULL ) return;
  xNode( RocsWgen_custom, node );
  NodeOp.setStr( node, "arg4", p_arg4 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * arg5
 */
static struct __attrdef RocsWgen_arg5 = {
  "arg5",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getarg5(iONode node) {
  const char* defval = xStr( RocsWgen_arg5 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_custom, node );
  return NodeOp.getStr( node, "arg5", defval );
}
static void _setarg5(iONode node, const char* p_arg5) {
  if( node == NULL ) return;
  xNode( RocsWgen_custom, node );
  NodeOp.setStr( node, "arg5", p_arg5 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * arg6
 */
static struct __attrdef RocsWgen_arg6 = {
  "arg6",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getarg6(iONode node) {
  const char* defval = xStr( RocsWgen_arg6 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_custom, node );
  return NodeOp.getStr( node, "arg6", defval );
}
static void _setarg6(iONode node, const char* p_arg6) {
  if( node == NULL ) return;
  xNode( RocsWgen_custom, node );
  NodeOp.setStr( node, "arg6", p_arg6 );
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
  xNode( RocsWgen_custom, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_custom, node );
  NodeOp.setStr( node, "cmd", p_cmd );
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
  xNode( RocsWgen_custom, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_custom, node );
  NodeOp.setStr( node, "iid", p_iid );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[9] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_custom.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node custom not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node custom not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_arg1;
  attrList[1] = &RocsWgen_arg2;
  attrList[2] = &RocsWgen_arg3;
  attrList[3] = &RocsWgen_arg4;
  attrList[4] = &RocsWgen_arg5;
  attrList[5] = &RocsWgen_arg6;
  attrList[6] = &RocsWgen_cmd;
  attrList[7] = &RocsWgen_iid;
  attrList[8] = NULL;
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


struct __wCustomCmd wCustomCmd = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getarg1,
  _setarg1,
  _getarg2,
  _setarg2,
  _getarg3,
  _setarg3,
  _getarg4,
  _setarg4,
  _getarg5,
  _setarg5,
  _getarg6,
  _setarg6,
  _getcmd,
  _setcmd,
  _getiid,
  _setiid,
  _node_dump,
};
