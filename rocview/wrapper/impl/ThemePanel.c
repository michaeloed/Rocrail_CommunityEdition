/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#include "rocview/wrapper/public/ThemePanel.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.ThemePanel
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_panel = {
  "panel",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_panel.name;
}
static const char* _node_remark(void) {
  return RocsWgen_panel.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_panel.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_panel.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blue
 */
static struct __attrdef RocsWgen_blue = {
  "blue",  "background color RGB blue value",  "",  "int",  "190",  "",  False,
};
static int _getblue(iONode node) {
  int defval = xInt( RocsWgen_blue );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_panel, node );
  return NodeOp.getInt( node, "blue", defval );
}
static void _setblue(iONode node, int p_blue) {
  if( node == NULL ) return;
  xNode( RocsWgen_panel, node );
  NodeOp.setInt( node, "blue", p_blue );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * border
 */
static struct __attrdef RocsWgen_border = {
  "border",  "show panel border",  "",  "bool",  "true",  "",  False,
};
static Boolean _isborder(iONode node) {
  Boolean defval = xBool( RocsWgen_border );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_panel, node );
  return NodeOp.getBool( node, "border", defval );
}
static void _setborder(iONode node, Boolean p_border) {
  if( node == NULL ) return;
  xNode( RocsWgen_panel, node );
  NodeOp.setBool( node, "border", p_border );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * green
 */
static struct __attrdef RocsWgen_green = {
  "green",  "background color RGB green value",  "",  "int",  "190",  "",  False,
};
static int _getgreen(iONode node) {
  int defval = xInt( RocsWgen_green );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_panel, node );
  return NodeOp.getInt( node, "green", defval );
}
static void _setgreen(iONode node, int p_green) {
  if( node == NULL ) return;
  xNode( RocsWgen_panel, node );
  NodeOp.setInt( node, "green", p_green );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * red
 */
static struct __attrdef RocsWgen_red = {
  "red",  "background color RGB red value",  "",  "int",  "190",  "",  False,
};
static int _getred(iONode node) {
  int defval = xInt( RocsWgen_red );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_panel, node );
  return NodeOp.getInt( node, "red", defval );
}
static void _setred(iONode node, int p_red) {
  if( node == NULL ) return;
  xNode( RocsWgen_panel, node );
  NodeOp.setInt( node, "red", p_red );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[5] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_panel.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node panel not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node panel not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_blue;
  attrList[1] = &RocsWgen_border;
  attrList[2] = &RocsWgen_green;
  attrList[3] = &RocsWgen_red;
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


struct __wThemePanel wThemePanel = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getblue,
  _setblue,
  _isborder,
  _setborder,
  _getgreen,
  _setgreen,
  _getred,
  _setred,
  _node_dump,
};
