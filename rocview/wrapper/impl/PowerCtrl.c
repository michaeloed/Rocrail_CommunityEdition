/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#include "rocview/wrapper/public/PowerCtrl.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.PowerCtrl
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_powerctrl = {
  "powerctrl",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_powerctrl.name;
}
static const char* _node_remark(void) {
  return RocsWgen_powerctrl.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_powerctrl.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_powerctrl.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cx
 */
static struct __attrdef RocsWgen_cx = {
  "cx",  "Width of PowerControlDialog",  "",  "int",  "420",  "*",  False,
};
static int _getcx(iONode node) {
  int defval = xInt( RocsWgen_cx );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_powerctrl, node );
  return NodeOp.getInt( node, "cx", defval );
}
static void _setcx(iONode node, int p_cx) {
  if( node == NULL ) return;
  xNode( RocsWgen_powerctrl, node );
  NodeOp.setInt( node, "cx", p_cx );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cy
 */
static struct __attrdef RocsWgen_cy = {
  "cy",  "Height of PowerControlDialog",  "",  "int",  "120",  "*",  False,
};
static int _getcy(iONode node) {
  int defval = xInt( RocsWgen_cy );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_powerctrl, node );
  return NodeOp.getInt( node, "cy", defval );
}
static void _setcy(iONode node, int p_cy) {
  if( node == NULL ) return;
  xNode( RocsWgen_powerctrl, node );
  NodeOp.setInt( node, "cy", p_cy );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * show
 */
static struct __attrdef RocsWgen_show = {
  "show",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isshow(iONode node) {
  Boolean defval = xBool( RocsWgen_show );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_powerctrl, node );
  return NodeOp.getBool( node, "show", defval );
}
static void _setshow(iONode node, Boolean p_show) {
  if( node == NULL ) return;
  xNode( RocsWgen_powerctrl, node );
  NodeOp.setBool( node, "show", p_show );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * x
 */
static struct __attrdef RocsWgen_x = {
  "x",  "X position of PowerControlDialog",  "",  "int",  "0",  "*",  False,
};
static int _getx(iONode node) {
  int defval = xInt( RocsWgen_x );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_powerctrl, node );
  return NodeOp.getInt( node, "x", defval );
}
static void _setx(iONode node, int p_x) {
  if( node == NULL ) return;
  xNode( RocsWgen_powerctrl, node );
  NodeOp.setInt( node, "x", p_x );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * y
 */
static struct __attrdef RocsWgen_y = {
  "y",  "Y position of PowerControlDialog",  "",  "int",  "0",  "*",  False,
};
static int _gety(iONode node) {
  int defval = xInt( RocsWgen_y );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_powerctrl, node );
  return NodeOp.getInt( node, "y", defval );
}
static void _sety(iONode node, int p_y) {
  if( node == NULL ) return;
  xNode( RocsWgen_powerctrl, node );
  NodeOp.setInt( node, "y", p_y );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[6] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_powerctrl.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node powerctrl not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node powerctrl not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_cx;
  attrList[1] = &RocsWgen_cy;
  attrList[2] = &RocsWgen_show;
  attrList[3] = &RocsWgen_x;
  attrList[4] = &RocsWgen_y;
  attrList[5] = NULL;
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


struct __wPowerCtrl wPowerCtrl = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getcx,
  _setcx,
  _getcy,
  _setcy,
  _isshow,
  _setshow,
  _getx,
  _setx,
  _gety,
  _sety,
  _node_dump,
};
