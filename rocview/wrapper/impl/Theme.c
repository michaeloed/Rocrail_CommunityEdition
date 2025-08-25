/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#include "rocview/wrapper/public/Theme.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.Theme
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_theme = {
  "theme",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_theme.name;
}
static const char* _node_remark(void) {
  return RocsWgen_theme.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_theme.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_theme.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "theme name",  "",  "string",  "",  "",  False,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_theme, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_theme, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * panel
 */
static struct __nodedef RocsWgen_panel = {
  "panel",  "",  False,  "1",};
static iONode _getpanel(iONode node) {
  xNode( RocsWgen_theme, node );
  return NodeOp.findNode( node, "panel");
}


static iONode _nextpanel(iONode node, iONode child) {
  xNode( RocsWgen_theme, node );
  return NodeOp.findNextNode( node, child);
}
static void _setpanel(iONode node, iONode p_panel) {
  xNode( RocsWgen_theme, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * themeblock
 */
static struct __nodedef RocsWgen_themeblock = {
  "themeblock",  "",  False,  "1",};
static iONode _getthemeblock(iONode node) {
  xNode( RocsWgen_theme, node );
  return NodeOp.findNode( node, "themeblock");
}


static iONode _nextthemeblock(iONode node, iONode child) {
  xNode( RocsWgen_theme, node );
  return NodeOp.findNextNode( node, child);
}
static void _setthemeblock(iONode node, iONode p_themeblock) {
  xNode( RocsWgen_theme, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * shortcut
 */
static struct __nodedef RocsWgen_shortcut = {
  "shortcut",  "",  False,  "1",};
static iONode _getshortcut(iONode node) {
  xNode( RocsWgen_theme, node );
  return NodeOp.findNode( node, "shortcut");
}


static iONode _nextshortcut(iONode node, iONode child) {
  xNode( RocsWgen_theme, node );
  return NodeOp.findNextNode( node, child);
}
static void _setshortcut(iONode node, iONode p_shortcut) {
  xNode( RocsWgen_theme, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[2] = {NULL};
static struct __nodedef* nodeList[4] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_theme.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node theme not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node theme not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_id;
  attrList[1] = NULL;
  nodeList[0] = &RocsWgen_panel;
  nodeList[1] = &RocsWgen_themeblock;
  nodeList[2] = &RocsWgen_shortcut;
  nodeList[3] = NULL;
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


struct __wTheme wTheme = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getid,
  _setid,
  _getpanel,
  _nextpanel,
  _setpanel,
  _getthemeblock,
  _nextthemeblock,
  _setthemeblock,
  _getshortcut,
  _nextshortcut,
  _setshortcut,
  _node_dump,
};
