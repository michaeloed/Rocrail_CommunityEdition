/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/HSI88.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.HSI88
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_hsi88 = {
  "hsi88",  "HSI88 init",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_hsi88.name;
}
static const char* _node_remark(void) {
  return RocsWgen_hsi88.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_hsi88.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_hsi88.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbleft
 */
static struct __attrdef RocsWgen_fbleft = {
  "fbleft",  "HSI-88 number of modules of 8 inputs on left port",  "",  "int",  "0",  "",  False,
};
static int _getfbleft(iONode node) {
  int defval = xInt( RocsWgen_fbleft );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_hsi88, node );
  return NodeOp.getInt( node, "fbleft", defval );
}
static void _setfbleft(iONode node, int p_fbleft) {
  if( node == NULL ) return;
  xNode( RocsWgen_hsi88, node );
  NodeOp.setInt( node, "fbleft", p_fbleft );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbmiddle
 */
static struct __attrdef RocsWgen_fbmiddle = {
  "fbmiddle",  "HSI-88 number of modules of 8 inputs on middle port",  "",  "int",  "0",  "",  False,
};
static int _getfbmiddle(iONode node) {
  int defval = xInt( RocsWgen_fbmiddle );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_hsi88, node );
  return NodeOp.getInt( node, "fbmiddle", defval );
}
static void _setfbmiddle(iONode node, int p_fbmiddle) {
  if( node == NULL ) return;
  xNode( RocsWgen_hsi88, node );
  NodeOp.setInt( node, "fbmiddle", p_fbmiddle );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbright
 */
static struct __attrdef RocsWgen_fbright = {
  "fbright",  "HSI-88 number of modules of 8 inputs on right port",  "",  "int",  "0",  "",  False,
};
static int _getfbright(iONode node) {
  int defval = xInt( RocsWgen_fbright );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_hsi88, node );
  return NodeOp.getInt( node, "fbright", defval );
}
static void _setfbright(iONode node, int p_fbright) {
  if( node == NULL ) return;
  xNode( RocsWgen_hsi88, node );
  NodeOp.setInt( node, "fbright", p_fbright );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * smooth
 */
static struct __attrdef RocsWgen_smooth = {
  "smooth",  "HSI-88 smooth out fb contact noice; fb must be at least 100ms low before sending event.",  "",  "bool",  "false",  "",  False,
};
static Boolean _issmooth(iONode node) {
  Boolean defval = xBool( RocsWgen_smooth );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_hsi88, node );
  return NodeOp.getBool( node, "smooth", defval );
}
static void _setsmooth(iONode node, Boolean p_smooth) {
  if( node == NULL ) return;
  xNode( RocsWgen_hsi88, node );
  NodeOp.setBool( node, "smooth", p_smooth );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * triggertime
 */
static struct __attrdef RocsWgen_triggertime = {
  "triggertime",  "",  "",  "int",  "100",  "100-2000",  False,
};
static int _gettriggertime(iONode node) {
  int defval = xInt( RocsWgen_triggertime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_hsi88, node );
  return NodeOp.getInt( node, "triggertime", defval );
}
static void _settriggertime(iONode node, int p_triggertime) {
  if( node == NULL ) return;
  xNode( RocsWgen_hsi88, node );
  NodeOp.setInt( node, "triggertime", p_triggertime );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usb
 */
static struct __attrdef RocsWgen_usb = {
  "usb",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isusb(iONode node) {
  Boolean defval = xBool( RocsWgen_usb );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_hsi88, node );
  return NodeOp.getBool( node, "usb", defval );
}
static void _setusb(iONode node, Boolean p_usb) {
  if( node == NULL ) return;
  xNode( RocsWgen_hsi88, node );
  NodeOp.setBool( node, "usb", p_usb );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[7] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_hsi88.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node hsi88 not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node hsi88 not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_fbleft;
  attrList[1] = &RocsWgen_fbmiddle;
  attrList[2] = &RocsWgen_fbright;
  attrList[3] = &RocsWgen_smooth;
  attrList[4] = &RocsWgen_triggertime;
  attrList[5] = &RocsWgen_usb;
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


struct __wHSI88 wHSI88 = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getfbleft,
  _setfbleft,
  _getfbmiddle,
  _setfbmiddle,
  _getfbright,
  _setfbright,
  _issmooth,
  _setsmooth,
  _gettriggertime,
  _settriggertime,
  _isusb,
  _setusb,
  _node_dump,
};
