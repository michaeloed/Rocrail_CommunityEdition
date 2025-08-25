/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/ZLevel.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.ZLevel
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_zlevel = {
  "zlevel",  "Z-Level description",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_zlevel.name;
}
static const char* _node_remark(void) {
  return RocsWgen_zlevel.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_zlevel.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_zlevel.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * active
 */
static struct __attrdef RocsWgen_active = {
  "active",  "active notebook page",  "",  "bool",  "false",  "",  False,
};
static Boolean _isactive(iONode node) {
  Boolean defval = xBool( RocsWgen_active );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_zlevel, node );
  return NodeOp.getBool( node, "active", defval );
}
static void _setactive(iONode node, Boolean p_active) {
  if( node == NULL ) return;
  xNode( RocsWgen_zlevel, node );
  NodeOp.setBool( node, "active", p_active );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * modid
 */
static struct __attrdef RocsWgen_modid = {
  "modid",  "module ID",  "",  "string",  "",  "*",  False,
};
static const char* _getmodid(iONode node) {
  const char* defval = xStr( RocsWgen_modid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_zlevel, node );
  return NodeOp.getStr( node, "modid", defval );
}
static void _setmodid(iONode node, const char* p_modid) {
  if( node == NULL ) return;
  xNode( RocsWgen_zlevel, node );
  NodeOp.setStr( node, "modid", p_modid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * modnr
 */
static struct __attrdef RocsWgen_modnr = {
  "modnr",  "module number",  "",  "int",  "0",  "0-*",  False,
};
static int _getmodnr(iONode node) {
  int defval = xInt( RocsWgen_modnr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_zlevel, node );
  return NodeOp.getInt( node, "modnr", defval );
}
static void _setmodnr(iONode node, int p_modnr) {
  if( node == NULL ) return;
  xNode( RocsWgen_zlevel, node );
  NodeOp.setInt( node, "modnr", p_modnr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * modviewcx
 */
static struct __attrdef RocsWgen_modviewcx = {
  "modviewcx",  "x size on an overview panel",  "",  "int",  "0",  "0-*",  False,
};
static int _getmodviewcx(iONode node) {
  int defval = xInt( RocsWgen_modviewcx );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_zlevel, node );
  return NodeOp.getInt( node, "modviewcx", defval );
}
static void _setmodviewcx(iONode node, int p_modviewcx) {
  if( node == NULL ) return;
  xNode( RocsWgen_zlevel, node );
  NodeOp.setInt( node, "modviewcx", p_modviewcx );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * modviewcy
 */
static struct __attrdef RocsWgen_modviewcy = {
  "modviewcy",  "y size on an overview panel",  "",  "int",  "0",  "0-*",  False,
};
static int _getmodviewcy(iONode node) {
  int defval = xInt( RocsWgen_modviewcy );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_zlevel, node );
  return NodeOp.getInt( node, "modviewcy", defval );
}
static void _setmodviewcy(iONode node, int p_modviewcy) {
  if( node == NULL ) return;
  xNode( RocsWgen_zlevel, node );
  NodeOp.setInt( node, "modviewcy", p_modviewcy );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * modviewx
 */
static struct __attrdef RocsWgen_modviewx = {
  "modviewx",  "x position on an overview panel",  "",  "int",  "0",  "0-*",  False,
};
static int _getmodviewx(iONode node) {
  int defval = xInt( RocsWgen_modviewx );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_zlevel, node );
  return NodeOp.getInt( node, "modviewx", defval );
}
static void _setmodviewx(iONode node, int p_modviewx) {
  if( node == NULL ) return;
  xNode( RocsWgen_zlevel, node );
  NodeOp.setInt( node, "modviewx", p_modviewx );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * modviewy
 */
static struct __attrdef RocsWgen_modviewy = {
  "modviewy",  "y position on an overview panel",  "",  "int",  "0",  "0-*",  False,
};
static int _getmodviewy(iONode node) {
  int defval = xInt( RocsWgen_modviewy );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_zlevel, node );
  return NodeOp.getInt( node, "modviewy", defval );
}
static void _setmodviewy(iONode node, int p_modviewy) {
  if( node == NULL ) return;
  xNode( RocsWgen_zlevel, node );
  NodeOp.setInt( node, "modviewy", p_modviewy );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * title
 */
static struct __attrdef RocsWgen_title = {
  "title",  "",  "",  "string",  "",  "*",  False,
};
static const char* _gettitle(iONode node) {
  const char* defval = xStr( RocsWgen_title );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_zlevel, node );
  return NodeOp.getStr( node, "title", defval );
}
static void _settitle(iONode node, const char* p_title) {
  if( node == NULL ) return;
  xNode( RocsWgen_zlevel, node );
  NodeOp.setStr( node, "title", p_title );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * z
 */
static struct __attrdef RocsWgen_z = {
  "z",  "",  "",  "int",  "0",  "0-9",  False,
};
static int _getz(iONode node) {
  int defval = xInt( RocsWgen_z );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_zlevel, node );
  return NodeOp.getInt( node, "z", defval );
}
static void _setz(iONode node, int p_z) {
  if( node == NULL ) return;
  xNode( RocsWgen_zlevel, node );
  NodeOp.setInt( node, "z", p_z );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[10] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_zlevel.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node zlevel not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node zlevel not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_active;
  attrList[1] = &RocsWgen_modid;
  attrList[2] = &RocsWgen_modnr;
  attrList[3] = &RocsWgen_modviewcx;
  attrList[4] = &RocsWgen_modviewcy;
  attrList[5] = &RocsWgen_modviewx;
  attrList[6] = &RocsWgen_modviewy;
  attrList[7] = &RocsWgen_title;
  attrList[8] = &RocsWgen_z;
  attrList[9] = NULL;
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


struct __wZLevel wZLevel = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isactive,
  _setactive,
  _getmodid,
  _setmodid,
  _getmodnr,
  _setmodnr,
  _getmodviewcx,
  _setmodviewcx,
  _getmodviewcy,
  _setmodviewcy,
  _getmodviewx,
  _setmodviewx,
  _getmodviewy,
  _setmodviewy,
  _gettitle,
  _settitle,
  _getz,
  _setz,
  _node_dump,
};
