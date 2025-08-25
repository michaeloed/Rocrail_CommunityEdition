/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#include "rocview/wrapper/public/SplitPanel.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.SplitPanel
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_splitpanel = {
  "splitpanel",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_splitpanel.name;
}
static const char* _node_remark(void) {
  return RocsWgen_splitpanel.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_splitpanel.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_splitpanel.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * dontwrap
 */
static struct __attrdef RocsWgen_dontwrap = {
  "dontwrap",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isdontwrap(iONode node) {
  Boolean defval = xBool( RocsWgen_dontwrap );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_splitpanel, node );
  return NodeOp.getBool( node, "dontwrap", defval );
}
static void _setdontwrap(iONode node, Boolean p_dontwrap) {
  if( node == NULL ) return;
  xNode( RocsWgen_splitpanel, node );
  NodeOp.setBool( node, "dontwrap", p_dontwrap );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * main
 */
static struct __attrdef RocsWgen_main = {
  "main",  "vertical plan/message split position",  "",  "int",  "455",  "",  False,
};
static int _getmain(iONode node) {
  int defval = xInt( RocsWgen_main );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_splitpanel, node );
  return NodeOp.getInt( node, "main", defval );
}
static void _setmain(iONode node, int p_main) {
  if( node == NULL ) return;
  xNode( RocsWgen_splitpanel, node );
  NodeOp.setInt( node, "main", p_main );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * msg
 */
static struct __attrdef RocsWgen_msg = {
  "msg",  "horizontal message/exception split position",  "",  "int",  "400",  "",  False,
};
static int _getmsg(iONode node) {
  int defval = xInt( RocsWgen_msg );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_splitpanel, node );
  return NodeOp.getInt( node, "msg", defval );
}
static void _setmsg(iONode node, int p_msg) {
  if( node == NULL ) return;
  xNode( RocsWgen_splitpanel, node );
  NodeOp.setInt( node, "msg", p_msg );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * plan
 */
static struct __attrdef RocsWgen_plan = {
  "plan",  "horizontal plan/plan split position",  "",  "int",  "360",  "",  False,
};
static int _getplan(iONode node) {
  int defval = xInt( RocsWgen_plan );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_splitpanel, node );
  return NodeOp.getInt( node, "plan", defval );
}
static void _setplan(iONode node, int p_plan) {
  if( node == NULL ) return;
  xNode( RocsWgen_splitpanel, node );
  NodeOp.setInt( node, "plan", p_plan );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[5] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_splitpanel.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node splitpanel not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node splitpanel not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_dontwrap;
  attrList[1] = &RocsWgen_main;
  attrList[2] = &RocsWgen_msg;
  attrList[3] = &RocsWgen_plan;
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


struct __wSplitPanel wSplitPanel = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isdontwrap,
  _setdontwrap,
  _getmain,
  _setmain,
  _getmsg,
  _setmsg,
  _getplan,
  _setplan,
  _node_dump,
};
