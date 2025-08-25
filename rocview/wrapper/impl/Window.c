/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#include "rocview/wrapper/public/Window.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.Window
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_window = {
  "window",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_window.name;
}
static const char* _node_remark(void) {
  return RocsWgen_window.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_window.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_window.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cx
 */
static struct __attrdef RocsWgen_cx = {
  "cx",  "",  "",  "int",  "900",  "",  False,
};
static int _getcx(iONode node) {
  int defval = xInt( RocsWgen_cx );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_window, node );
  return NodeOp.getInt( node, "cx", defval );
}
static void _setcx(iONode node, int p_cx) {
  if( node == NULL ) return;
  xNode( RocsWgen_window, node );
  NodeOp.setInt( node, "cx", p_cx );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cy
 */
static struct __attrdef RocsWgen_cy = {
  "cy",  "",  "",  "int",  "600",  "",  False,
};
static int _getcy(iONode node) {
  int defval = xInt( RocsWgen_cy );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_window, node );
  return NodeOp.getInt( node, "cy", defval );
}
static void _setcy(iONode node, int p_cy) {
  if( node == NULL ) return;
  xNode( RocsWgen_window, node );
  NodeOp.setInt( node, "cy", p_cy );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * x
 */
static struct __attrdef RocsWgen_x = {
  "x",  "",  "",  "int",  "50",  "",  False,
};
static int _getx(iONode node) {
  int defval = xInt( RocsWgen_x );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_window, node );
  return NodeOp.getInt( node, "x", defval );
}
static void _setx(iONode node, int p_x) {
  if( node == NULL ) return;
  xNode( RocsWgen_window, node );
  NodeOp.setInt( node, "x", p_x );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * xtp
 */
static struct __attrdef RocsWgen_xtp = {
  "xtp",  "trackpickerdlg",  "",  "int",  "50",  "",  False,
};
static int _getxtp(iONode node) {
  int defval = xInt( RocsWgen_xtp );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_window, node );
  return NodeOp.getInt( node, "xtp", defval );
}
static void _setxtp(iONode node, int p_xtp) {
  if( node == NULL ) return;
  xNode( RocsWgen_window, node );
  NodeOp.setInt( node, "xtp", p_xtp );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * y
 */
static struct __attrdef RocsWgen_y = {
  "y",  "",  "",  "int",  "50",  "",  False,
};
static int _gety(iONode node) {
  int defval = xInt( RocsWgen_y );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_window, node );
  return NodeOp.getInt( node, "y", defval );
}
static void _sety(iONode node, int p_y) {
  if( node == NULL ) return;
  xNode( RocsWgen_window, node );
  NodeOp.setInt( node, "y", p_y );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ytp
 */
static struct __attrdef RocsWgen_ytp = {
  "ytp",  "trackpickerdlg",  "",  "int",  "50",  "",  False,
};
static int _getytp(iONode node) {
  int defval = xInt( RocsWgen_ytp );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_window, node );
  return NodeOp.getInt( node, "ytp", defval );
}
static void _setytp(iONode node, int p_ytp) {
  if( node == NULL ) return;
  xNode( RocsWgen_window, node );
  NodeOp.setInt( node, "ytp", p_ytp );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[7] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_window.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node window not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node window not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_cx;
  attrList[1] = &RocsWgen_cy;
  attrList[2] = &RocsWgen_x;
  attrList[3] = &RocsWgen_xtp;
  attrList[4] = &RocsWgen_y;
  attrList[5] = &RocsWgen_ytp;
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


struct __wWindow wWindow = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getcx,
  _setcx,
  _getcy,
  _setcy,
  _getx,
  _setx,
  _getxtp,
  _setxtp,
  _gety,
  _sety,
  _getytp,
  _setytp,
  _node_dump,
};
