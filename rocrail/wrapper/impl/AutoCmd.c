/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/AutoCmd.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.AutoCmd
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_auto = {
  "auto",  "Auto command.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_auto.name;
}
static const char* _node_remark(void) {
  return RocsWgen_auto.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_auto.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_auto.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmd
 */
static struct __attrdef RocsWgen_cmd = {
  "cmd",  "",  "",  "string",  "",  "on,off,start,stop,reset",  False,
};
static const char* _getcmd(iONode node) {
  const char* defval = xStr( RocsWgen_cmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_auto, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_auto, node );
  NodeOp.setStr( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * era
 */
static struct __attrdef RocsWgen_era = {
  "era",  "",  "",  "int",  "0",  "0-6",  False,
};
static int _getera(iONode node) {
  int defval = xInt( RocsWgen_era );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_auto, node );
  return NodeOp.getInt( node, "era", defval );
}
static void _setera(iONode node, int p_era) {
  if( node == NULL ) return;
  xNode( RocsWgen_auto, node );
  NodeOp.setInt( node, "era", p_era );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * reset
 */
static struct __attrdef RocsWgen_reset = {
  "reset",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isreset(iONode node) {
  Boolean defval = xBool( RocsWgen_reset );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_auto, node );
  return NodeOp.getBool( node, "reset", defval );
}
static void _setreset(iONode node, Boolean p_reset) {
  if( node == NULL ) return;
  xNode( RocsWgen_auto, node );
  NodeOp.setBool( node, "reset", p_reset );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[4] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_auto.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node auto not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node auto not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_cmd;
  attrList[1] = &RocsWgen_era;
  attrList[2] = &RocsWgen_reset;
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


struct __wAutoCmd wAutoCmd = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "off",
  "on",
  "reset",
  "resume",
  "softreset",
  "start",
  "startvirtual",
  "stop",
  "v0locos",
  "vrestorelocos",
  _getcmd,
  _setcmd,
  _getera,
  _setera,
  _isreset,
  _setreset,
  _node_dump,
};
