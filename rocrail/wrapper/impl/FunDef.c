/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/FunDef.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.FunDef
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_fundef = {
  "fundef",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_fundef.name;
}
static const char* _node_remark(void) {
  return RocsWgen_fundef.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_fundef.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_fundef.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr
 */
static struct __attrdef RocsWgen_addr = {
  "addr",  "Function decoder address.",  "",  "int",  "0",  "0-*",  False,
};
static int _getaddr(iONode node) {
  int defval = xInt( RocsWgen_addr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fundef, node );
  return NodeOp.getInt( node, "addr", defval );
}
static void _setaddr(iONode node, int p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_fundef, node );
  NodeOp.setInt( node, "addr", p_addr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fn
 */
static struct __attrdef RocsWgen_fn = {
  "fn",  "function number",  "",  "int",  "1",  "1-*",  False,
};
static int _getfn(iONode node) {
  int defval = xInt( RocsWgen_fn );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fundef, node );
  return NodeOp.getInt( node, "fn", defval );
}
static void _setfn(iONode node, int p_fn) {
  if( node == NULL ) return;
  xNode( RocsWgen_fundef, node );
  NodeOp.setInt( node, "fn", p_fn );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * icon
 */
static struct __attrdef RocsWgen_icon = {
  "icon",  "icon file",  "",  "string",  "",  "*",  False,
};
static const char* _geticon(iONode node) {
  const char* defval = xStr( RocsWgen_icon );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fundef, node );
  return NodeOp.getStr( node, "icon", defval );
}
static void _seticon(iONode node, const char* p_icon) {
  if( node == NULL ) return;
  xNode( RocsWgen_fundef, node );
  NodeOp.setStr( node, "icon", p_icon );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mappedfn
 */
static struct __attrdef RocsWgen_mappedfn = {
  "mappedfn",  "Mapped function number in case of other address then main decodcer.",  "",  "int",  "0",  "0-*",  False,
};
static int _getmappedfn(iONode node) {
  int defval = xInt( RocsWgen_mappedfn );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fundef, node );
  return NodeOp.getInt( node, "mappedfn", defval );
}
static void _setmappedfn(iONode node, int p_mappedfn) {
  if( node == NULL ) return;
  xNode( RocsWgen_fundef, node );
  NodeOp.setInt( node, "mappedfn", p_mappedfn );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * offblockid
 */
static struct __attrdef RocsWgen_offblockid = {
  "offblockid",  "BlockID.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getoffblockid(iONode node) {
  const char* defval = xStr( RocsWgen_offblockid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fundef, node );
  return NodeOp.getStr( node, "offblockid", defval );
}
static void _setoffblockid(iONode node, const char* p_offblockid) {
  if( node == NULL ) return;
  xNode( RocsWgen_fundef, node );
  NodeOp.setStr( node, "offblockid", p_offblockid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * offevent
 */
static struct __attrdef RocsWgen_offevent = {
  "offevent",  "Deactivation event.",  "",  "string",  "in_block",  "enter_block,exit_block,in_block,out_block",  False,
};
static const char* _getoffevent(iONode node) {
  const char* defval = xStr( RocsWgen_offevent );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fundef, node );
  return NodeOp.getStr( node, "offevent", defval );
}
static void _setoffevent(iONode node, const char* p_offevent) {
  if( node == NULL ) return;
  xNode( RocsWgen_fundef, node );
  NodeOp.setStr( node, "offevent", p_offevent );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * on
 */
static struct __attrdef RocsWgen_on = {
  "on",  "activation",  "",  "bool",  "false",  "",  False,
};
static Boolean _ison(iONode node) {
  Boolean defval = xBool( RocsWgen_on );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fundef, node );
  return NodeOp.getBool( node, "on", defval );
}
static void _seton(iONode node, Boolean p_on) {
  if( node == NULL ) return;
  xNode( RocsWgen_fundef, node );
  NodeOp.setBool( node, "on", p_on );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * onblockid
 */
static struct __attrdef RocsWgen_onblockid = {
  "onblockid",  "BlockID.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getonblockid(iONode node) {
  const char* defval = xStr( RocsWgen_onblockid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fundef, node );
  return NodeOp.getStr( node, "onblockid", defval );
}
static void _setonblockid(iONode node, const char* p_onblockid) {
  if( node == NULL ) return;
  xNode( RocsWgen_fundef, node );
  NodeOp.setStr( node, "onblockid", p_onblockid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * onevent
 */
static struct __attrdef RocsWgen_onevent = {
  "onevent",  "Activation event.",  "",  "string",  "enter_block",  "enter_block,exit_block,in_block,out_block",  False,
};
static const char* _getonevent(iONode node) {
  const char* defval = xStr( RocsWgen_onevent );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fundef, node );
  return NodeOp.getStr( node, "onevent", defval );
}
static void _setonevent(iONode node, const char* p_onevent) {
  if( node == NULL ) return;
  xNode( RocsWgen_fundef, node );
  NodeOp.setStr( node, "onevent", p_onevent );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sound
 */
static struct __attrdef RocsWgen_sound = {
  "sound",  "sound file",  "",  "string",  "",  "*",  False,
};
static const char* _getsound(iONode node) {
  const char* defval = xStr( RocsWgen_sound );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fundef, node );
  return NodeOp.getStr( node, "sound", defval );
}
static void _setsound(iONode node, const char* p_sound) {
  if( node == NULL ) return;
  xNode( RocsWgen_fundef, node );
  NodeOp.setStr( node, "sound", p_sound );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * text
 */
static struct __attrdef RocsWgen_text = {
  "text",  "function label",  "",  "string",  "function",  "*",  False,
};
static const char* _gettext(iONode node) {
  const char* defval = xStr( RocsWgen_text );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fundef, node );
  return NodeOp.getStr( node, "text", defval );
}
static void _settext(iONode node, const char* p_text) {
  if( node == NULL ) return;
  xNode( RocsWgen_fundef, node );
  NodeOp.setStr( node, "text", p_text );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timer
 */
static struct __attrdef RocsWgen_timer = {
  "timer",  "function timer",  "s",  "int",  "0",  "0-99",  False,
};
static int _gettimer(iONode node) {
  int defval = xInt( RocsWgen_timer );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fundef, node );
  return NodeOp.getInt( node, "timer", defval );
}
static void _settimer(iONode node, int p_timer) {
  if( node == NULL ) return;
  xNode( RocsWgen_fundef, node );
  NodeOp.setInt( node, "timer", p_timer );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[13] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_fundef.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node fundef not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node fundef not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_addr;
  attrList[1] = &RocsWgen_fn;
  attrList[2] = &RocsWgen_icon;
  attrList[3] = &RocsWgen_mappedfn;
  attrList[4] = &RocsWgen_offblockid;
  attrList[5] = &RocsWgen_offevent;
  attrList[6] = &RocsWgen_on;
  attrList[7] = &RocsWgen_onblockid;
  attrList[8] = &RocsWgen_onevent;
  attrList[9] = &RocsWgen_sound;
  attrList[10] = &RocsWgen_text;
  attrList[11] = &RocsWgen_timer;
  attrList[12] = NULL;
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


struct __wFunDef wFunDef = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "enter_block",
  "exit_block",
  "in_block",
  "run",
  "stall",
  _getaddr,
  _setaddr,
  _getfn,
  _setfn,
  _geticon,
  _seticon,
  _getmappedfn,
  _setmappedfn,
  _getoffblockid,
  _setoffblockid,
  _getoffevent,
  _setoffevent,
  _ison,
  _seton,
  _getonblockid,
  _setonblockid,
  _getonevent,
  _setonevent,
  _getsound,
  _setsound,
  _gettext,
  _settext,
  _gettimer,
  _settimer,
  _node_dump,
};
