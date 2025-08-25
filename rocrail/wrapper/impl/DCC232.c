/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/DCC232.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.DCC232
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_dcc232 = {
  "dcc232",  "DCC232 options",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_dcc232.name;
}
static const char* _node_remark(void) {
  return RocsWgen_dcc232.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_dcc232.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_dcc232.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fastcvget
 */
static struct __attrdef RocsWgen_fastcvget = {
  "fastcvget",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isfastcvget(iONode node) {
  Boolean defval = xBool( RocsWgen_fastcvget );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dcc232, node );
  return NodeOp.getBool( node, "fastcvget", defval );
}
static void _setfastcvget(iONode node, Boolean p_fastcvget) {
  if( node == NULL ) return;
  xNode( RocsWgen_dcc232, node );
  NodeOp.setBool( node, "fastcvget", p_fastcvget );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * inversedsr
 */
static struct __attrdef RocsWgen_inversedsr = {
  "inversedsr",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isinversedsr(iONode node) {
  Boolean defval = xBool( RocsWgen_inversedsr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dcc232, node );
  return NodeOp.getBool( node, "inversedsr", defval );
}
static void _setinversedsr(iONode node, Boolean p_inversedsr) {
  if( node == NULL ) return;
  xNode( RocsWgen_dcc232, node );
  NodeOp.setBool( node, "inversedsr", p_inversedsr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "",  "",  "string",  "com1",  "*",  False,
};
static const char* _getport(iONode node) {
  const char* defval = xStr( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dcc232, node );
  return NodeOp.getStr( node, "port", defval );
}
static void _setport(iONode node, const char* p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_dcc232, node );
  NodeOp.setStr( node, "port", p_port );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * purge
 */
static struct __attrdef RocsWgen_purge = {
  "purge",  "Activate purging.",  "",  "bool",  "true",  "",  False,
};
static Boolean _ispurge(iONode node) {
  Boolean defval = xBool( RocsWgen_purge );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dcc232, node );
  return NodeOp.getBool( node, "purge", defval );
}
static void _setpurge(iONode node, Boolean p_purge) {
  if( node == NULL ) return;
  xNode( RocsWgen_dcc232, node );
  NodeOp.setBool( node, "purge", p_purge );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * purgetime
 */
static struct __attrdef RocsWgen_purgetime = {
  "purgetime",  "Idle time for purg a slot.",  "s",  "int",  "60",  "0-*",  False,
};
static int _getpurgetime(iONode node) {
  int defval = xInt( RocsWgen_purgetime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dcc232, node );
  return NodeOp.getInt( node, "purgetime", defval );
}
static void _setpurgetime(iONode node, int p_purgetime) {
  if( node == NULL ) return;
  xNode( RocsWgen_dcc232, node );
  NodeOp.setInt( node, "purgetime", p_purgetime );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * shortcut
 */
static struct __attrdef RocsWgen_shortcut = {
  "shortcut",  "Use shortcut detection",  "",  "bool",  "true",  "",  False,
};
static Boolean _isshortcut(iONode node) {
  Boolean defval = xBool( RocsWgen_shortcut );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dcc232, node );
  return NodeOp.getBool( node, "shortcut", defval );
}
static void _setshortcut(iONode node, Boolean p_shortcut) {
  if( node == NULL ) return;
  xNode( RocsWgen_dcc232, node );
  NodeOp.setBool( node, "shortcut", p_shortcut );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * shortcutdelay
 */
static struct __attrdef RocsWgen_shortcutdelay = {
  "shortcutdelay",  "Shortcut events shorter than this time is ignored",  "ms",  "int",  "1000",  "",  False,
};
static int _getshortcutdelay(iONode node) {
  int defval = xInt( RocsWgen_shortcutdelay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dcc232, node );
  return NodeOp.getInt( node, "shortcutdelay", defval );
}
static void _setshortcutdelay(iONode node, int p_shortcutdelay) {
  if( node == NULL ) return;
  xNode( RocsWgen_dcc232, node );
  NodeOp.setInt( node, "shortcutdelay", p_shortcutdelay );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[8] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_dcc232.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node dcc232 not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node dcc232 not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_fastcvget;
  attrList[1] = &RocsWgen_inversedsr;
  attrList[2] = &RocsWgen_port;
  attrList[3] = &RocsWgen_purge;
  attrList[4] = &RocsWgen_purgetime;
  attrList[5] = &RocsWgen_shortcut;
  attrList[6] = &RocsWgen_shortcutdelay;
  attrList[7] = NULL;
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


struct __wDCC232 wDCC232 = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isfastcvget,
  _setfastcvget,
  _isinversedsr,
  _setinversedsr,
  _getport,
  _setport,
  _ispurge,
  _setpurge,
  _getpurgetime,
  _setpurgetime,
  _isshortcut,
  _setshortcut,
  _getshortcutdelay,
  _setshortcutdelay,
  _node_dump,
};
