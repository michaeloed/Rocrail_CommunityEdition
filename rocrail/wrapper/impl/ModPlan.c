/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/ModPlan.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.ModPlan
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_modplan = {
  "modplan",  "Root node of the module master plan.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_modplan.name;
}
static const char* _node_remark(void) {
  return RocsWgen_modplan.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_modplan.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_modplan.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * initfield
 */
static struct __attrdef RocsWgen_initfield = {
  "initfield",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isinitfield(iONode node) {
  Boolean defval = xBool( RocsWgen_initfield );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_modplan, node );
  return NodeOp.getBool( node, "initfield", defval );
}
static void _setinitfield(iONode node, Boolean p_initfield) {
  if( node == NULL ) return;
  xNode( RocsWgen_modplan, node );
  NodeOp.setBool( node, "initfield", p_initfield );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * locs
 */
static struct __attrdef RocsWgen_locs = {
  "locs",  "File name of locomotive definitions.",  "",  "string",  "lc.xml",  "*",  False,
};
static const char* _getlocs(iONode node) {
  const char* defval = xStr( RocsWgen_locs );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_modplan, node );
  return NodeOp.getStr( node, "locs", defval );
}
static void _setlocs(iONode node, const char* p_locs) {
  if( node == NULL ) return;
  xNode( RocsWgen_modplan, node );
  NodeOp.setStr( node, "locs", p_locs );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * modified
 */
static struct __attrdef RocsWgen_modified = {
  "modified",  "Flags module as modified by the GUI. (Internal use only)",  "",  "bool",  "false",  "",  False,
};
static Boolean _ismodified(iONode node) {
  Boolean defval = xBool( RocsWgen_modified );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_modplan, node );
  return NodeOp.getBool( node, "modified", defval );
}
static void _setmodified(iONode node, Boolean p_modified) {
  if( node == NULL ) return;
  xNode( RocsWgen_modplan, node );
  NodeOp.setBool( node, "modified", p_modified );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * modroutes
 */
static struct __attrdef RocsWgen_modroutes = {
  "modroutes",  "Use internal module routes in conjunction with connections.",  "",  "bool",  "true",  "",  False,
};
static Boolean _ismodroutes(iONode node) {
  Boolean defval = xBool( RocsWgen_modroutes );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_modplan, node );
  return NodeOp.getBool( node, "modroutes", defval );
}
static void _setmodroutes(iONode node, Boolean p_modroutes) {
  if( node == NULL ) return;
  xNode( RocsWgen_modplan, node );
  NodeOp.setBool( node, "modroutes", p_modroutes );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * routes
 */
static struct __attrdef RocsWgen_routes = {
  "routes",  "File name of route and schedule definitions.",  "",  "string",  "rt.xml",  "*",  False,
};
static const char* _getroutes(iONode node) {
  const char* defval = xStr( RocsWgen_routes );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_modplan, node );
  return NodeOp.getStr( node, "routes", defval );
}
static void _setroutes(iONode node, const char* p_routes) {
  if( node == NULL ) return;
  xNode( RocsWgen_modplan, node );
  NodeOp.setStr( node, "routes", p_routes );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * savemodplan
 */
static struct __attrdef RocsWgen_savemodplan = {
  "savemodplan",  "Make sure locs and routes are in separate files and not part of a module!",  "",  "bool",  "true",  "",  False,
};
static Boolean _issavemodplan(iONode node) {
  Boolean defval = xBool( RocsWgen_savemodplan );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_modplan, node );
  return NodeOp.getBool( node, "savemodplan", defval );
}
static void _setsavemodplan(iONode node, Boolean p_savemodplan) {
  if( node == NULL ) return;
  xNode( RocsWgen_modplan, node );
  NodeOp.setBool( node, "savemodplan", p_savemodplan );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * savemodules
 */
static struct __attrdef RocsWgen_savemodules = {
  "savemodules",  "Leave modules un touched if set to false, but all changes are lost.",  "",  "bool",  "true",  "",  False,
};
static Boolean _issavemodules(iONode node) {
  Boolean defval = xBool( RocsWgen_savemodules );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_modplan, node );
  return NodeOp.getBool( node, "savemodules", defval );
}
static void _setsavemodules(iONode node, Boolean p_savemodules) {
  if( node == NULL ) return;
  xNode( RocsWgen_modplan, node );
  NodeOp.setBool( node, "savemodules", p_savemodules );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * subtitle
 */
static struct __attrdef RocsWgen_subtitle = {
  "subtitle",  "Sub title of plan.",  "",  "string",  "Modular Track Layout",  "*",  False,
};
static const char* _getsubtitle(iONode node) {
  const char* defval = xStr( RocsWgen_subtitle );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_modplan, node );
  return NodeOp.getStr( node, "subtitle", defval );
}
static void _setsubtitle(iONode node, const char* p_subtitle) {
  if( node == NULL ) return;
  xNode( RocsWgen_modplan, node );
  NodeOp.setStr( node, "subtitle", p_subtitle );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * title
 */
static struct __attrdef RocsWgen_title = {
  "title",  "Title of plan.",  "",  "string",  "Modular Track Layout",  "*",  False,
};
static const char* _gettitle(iONode node) {
  const char* defval = xStr( RocsWgen_title );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_modplan, node );
  return NodeOp.getStr( node, "title", defval );
}
static void _settitle(iONode node, const char* p_title) {
  if( node == NULL ) return;
  xNode( RocsWgen_modplan, node );
  NodeOp.setStr( node, "title", p_title );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * module
 */
static struct __nodedef RocsWgen_module = {
  "module",  "Module definition",  False,  "n",};
static iONode _getmodule(iONode node) {
  xNode( RocsWgen_modplan, node );
  return NodeOp.findNode( node, "module");
}


static iONode _nextmodule(iONode node, iONode child) {
  xNode( RocsWgen_modplan, node );
  return NodeOp.findNextNode( node, child);
}
static void _setmodule(iONode node, iONode p_module) {
  xNode( RocsWgen_modplan, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[10] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_modplan.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node modplan not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node modplan not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_initfield;
  attrList[1] = &RocsWgen_locs;
  attrList[2] = &RocsWgen_modified;
  attrList[3] = &RocsWgen_modroutes;
  attrList[4] = &RocsWgen_routes;
  attrList[5] = &RocsWgen_savemodplan;
  attrList[6] = &RocsWgen_savemodules;
  attrList[7] = &RocsWgen_subtitle;
  attrList[8] = &RocsWgen_title;
  attrList[9] = NULL;
  nodeList[0] = &RocsWgen_module;
  nodeList[1] = NULL;
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


struct __wModPlan wModPlan = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isinitfield,
  _setinitfield,
  _getlocs,
  _setlocs,
  _ismodified,
  _setmodified,
  _ismodroutes,
  _setmodroutes,
  _getroutes,
  _setroutes,
  _issavemodplan,
  _setsavemodplan,
  _issavemodules,
  _setsavemodules,
  _getsubtitle,
  _setsubtitle,
  _gettitle,
  _settitle,
  _getmodule,
  _nextmodule,
  _setmodule,
  _node_dump,
};
