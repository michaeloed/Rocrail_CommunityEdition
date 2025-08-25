/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/DecVariable.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.DecVariable
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_variable = {
  "variable",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_variable.name;
}
static const char* _node_remark(void) {
  return RocsWgen_variable.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_variable.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_variable.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * CV
 */
static struct __attrdef RocsWgen_CV = {
  "CV",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getCV(iONode node) {
  int defval = xInt( RocsWgen_CV );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_variable, node );
  return NodeOp.getInt( node, "CV", defval );
}
static void _setCV(iONode node, int p_CV) {
  if( node == NULL ) return;
  xNode( RocsWgen_variable, node );
  NodeOp.setInt( node, "CV", p_CV );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * comment
 */
static struct __attrdef RocsWgen_comment = {
  "comment",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getcomment(iONode node) {
  const char* defval = xStr( RocsWgen_comment );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_variable, node );
  return NodeOp.getStr( node, "comment", defval );
}
static void _setcomment(iONode node, const char* p_comment) {
  if( node == NULL ) return;
  xNode( RocsWgen_variable, node );
  NodeOp.setStr( node, "comment", p_comment );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * item
 */
static struct __attrdef RocsWgen_item = {
  "item",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getitem(iONode node) {
  const char* defval = xStr( RocsWgen_item );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_variable, node );
  return NodeOp.getStr( node, "item", defval );
}
static void _setitem(iONode node, const char* p_item) {
  if( node == NULL ) return;
  xNode( RocsWgen_variable, node );
  NodeOp.setStr( node, "item", p_item );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * label
 */
static struct __attrdef RocsWgen_label = {
  "label",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getlabel(iONode node) {
  const char* defval = xStr( RocsWgen_label );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_variable, node );
  return NodeOp.getStr( node, "label", defval );
}
static void _setlabel(iONode node, const char* p_label) {
  if( node == NULL ) return;
  xNode( RocsWgen_variable, node );
  NodeOp.setStr( node, "label", p_label );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mask
 */
static struct __attrdef RocsWgen_mask = {
  "mask",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getmask(iONode node) {
  const char* defval = xStr( RocsWgen_mask );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_variable, node );
  return NodeOp.getStr( node, "mask", defval );
}
static void _setmask(iONode node, const char* p_mask) {
  if( node == NULL ) return;
  xNode( RocsWgen_variable, node );
  NodeOp.setStr( node, "mask", p_mask );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * tooltip
 */
static struct __attrdef RocsWgen_tooltip = {
  "tooltip",  "",  "",  "string",  "",  "*",  False,
};
static const char* _gettooltip(iONode node) {
  const char* defval = xStr( RocsWgen_tooltip );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_variable, node );
  return NodeOp.getStr( node, "tooltip", defval );
}
static void _settooltip(iONode node, const char* p_tooltip) {
  if( node == NULL ) return;
  xNode( RocsWgen_variable, node );
  NodeOp.setStr( node, "tooltip", p_tooltip );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[7] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_variable.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node variable not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node variable not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_CV;
  attrList[1] = &RocsWgen_comment;
  attrList[2] = &RocsWgen_item;
  attrList[3] = &RocsWgen_label;
  attrList[4] = &RocsWgen_mask;
  attrList[5] = &RocsWgen_tooltip;
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


struct __wDecVariable wDecVariable = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getCV,
  _setCV,
  _getcomment,
  _setcomment,
  _getitem,
  _setitem,
  _getlabel,
  _setlabel,
  _getmask,
  _setmask,
  _gettooltip,
  _settooltip,
  _node_dump,
};
