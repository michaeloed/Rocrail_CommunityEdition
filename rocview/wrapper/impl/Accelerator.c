/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:52 2018
  */

#include "rocview/wrapper/public/Accelerator.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.Accelerator
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_accelerator = {
  "accelerator",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_accelerator.name;
}
static const char* _node_remark(void) {
  return RocsWgen_accelerator.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_accelerator.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_accelerator.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * function
 */
static struct __attrdef RocsWgen_function = {
  "function",  "",  "",  "string",  "",  "",  False,
};
static const char* _getfunction(iONode node) {
  const char* defval = xStr( RocsWgen_function );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_accelerator, node );
  return NodeOp.getStr( node, "function", defval );
}
static void _setfunction(iONode node, const char* p_function) {
  if( node == NULL ) return;
  xNode( RocsWgen_accelerator, node );
  NodeOp.setStr( node, "function", p_function );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * keycode
 */
static struct __attrdef RocsWgen_keycode = {
  "keycode",  "WXK_*",  "",  "int",  "0",  "",  False,
};
static int _getkeycode(iONode node) {
  int defval = xInt( RocsWgen_keycode );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_accelerator, node );
  return NodeOp.getInt( node, "keycode", defval );
}
static void _setkeycode(iONode node, int p_keycode) {
  if( node == NULL ) return;
  xNode( RocsWgen_accelerator, node );
  NodeOp.setInt( node, "keycode", p_keycode );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * modifier
 */
static struct __attrdef RocsWgen_modifier = {
  "modifier",  "0=none 1=alt 2=ctrl",  "",  "int",  "0",  "",  False,
};
static int _getmodifier(iONode node) {
  int defval = xInt( RocsWgen_modifier );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_accelerator, node );
  return NodeOp.getInt( node, "modifier", defval );
}
static void _setmodifier(iONode node, int p_modifier) {
  if( node == NULL ) return;
  xNode( RocsWgen_accelerator, node );
  NodeOp.setInt( node, "modifier", p_modifier );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[4] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_accelerator.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node accelerator not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node accelerator not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_function;
  attrList[1] = &RocsWgen_keycode;
  attrList[2] = &RocsWgen_modifier;
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


struct __wAccelerator wAccelerator = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "ebreak",
  _getfunction,
  _setfunction,
  _getkeycode,
  _setkeycode,
  _getmodifier,
  _setmodifier,
  _node_dump,
};
