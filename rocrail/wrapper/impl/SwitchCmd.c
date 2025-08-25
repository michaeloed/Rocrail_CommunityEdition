/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/SwitchCmd.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.SwitchCmd
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_swcmd = {
  "swcmd",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_swcmd.name;
}
static const char* _node_remark(void) {
  return RocsWgen_swcmd.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_swcmd.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_swcmd.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * atfree
 */
static struct __attrdef RocsWgen_atfree = {
  "atfree",  "command should be fired at a free event",  "",  "bool",  "false",  "",  False,
};
static Boolean _isatfree(iONode node) {
  Boolean defval = xBool( RocsWgen_atfree );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_swcmd, node );
  return NodeOp.getBool( node, "atfree", defval );
}
static void _setatfree(iONode node, Boolean p_atfree) {
  if( node == NULL ) return;
  xNode( RocsWgen_swcmd, node );
  NodeOp.setBool( node, "atfree", p_atfree );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmd
 */
static struct __attrdef RocsWgen_cmd = {
  "cmd",  "",  "",  "string",  "straight",  "straight,turnout,left,right,green,red,yellow,white,track",  False,
};
static const char* _getcmd(iONode node) {
  const char* defval = xStr( RocsWgen_cmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_swcmd, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_swcmd, node );
  NodeOp.setStr( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "Switch ID.",  "",  "string",  "",  "*",  True,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_swcmd, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_swcmd, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lock
 */
static struct __attrdef RocsWgen_lock = {
  "lock",  "lock the switch for exclusive use",  "",  "bool",  "true",  "",  False,
};
static Boolean _islock(iONode node) {
  Boolean defval = xBool( RocsWgen_lock );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_swcmd, node );
  return NodeOp.getBool( node, "lock", defval );
}
static void _setlock(iONode node, Boolean p_lock) {
  if( node == NULL ) return;
  xNode( RocsWgen_swcmd, node );
  NodeOp.setBool( node, "lock", p_lock );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * reduceV
 */
static struct __attrdef RocsWgen_reduceV = {
  "reduceV",  "reduce speed by thrown status",  "",  "bool",  "true",  "",  False,
};
static Boolean _isreduceV(iONode node) {
  Boolean defval = xBool( RocsWgen_reduceV );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_swcmd, node );
  return NodeOp.getBool( node, "reduceV", defval );
}
static void _setreduceV(iONode node, Boolean p_reduceV) {
  if( node == NULL ) return;
  xNode( RocsWgen_swcmd, node );
  NodeOp.setBool( node, "reduceV", p_reduceV );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * track
 */
static struct __attrdef RocsWgen_track = {
  "track",  "turntable track",  "",  "int",  "0",  "0-*",  False,
};
static int _gettrack(iONode node) {
  int defval = xInt( RocsWgen_track );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_swcmd, node );
  return NodeOp.getInt( node, "track", defval );
}
static void _settrack(iONode node, int p_track) {
  if( node == NULL ) return;
  xNode( RocsWgen_swcmd, node );
  NodeOp.setInt( node, "track", p_track );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[7] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_swcmd.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node swcmd not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node swcmd not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_atfree;
  attrList[1] = &RocsWgen_cmd;
  attrList[2] = &RocsWgen_id;
  attrList[3] = &RocsWgen_lock;
  attrList[4] = &RocsWgen_reduceV;
  attrList[5] = &RocsWgen_track;
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


struct __wSwitchCmd wSwitchCmd = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "track",
  _isatfree,
  _setatfree,
  _getcmd,
  _setcmd,
  _getid,
  _setid,
  _islock,
  _setlock,
  _isreduceV,
  _setreduceV,
  _gettrack,
  _settrack,
  _node_dump,
};
