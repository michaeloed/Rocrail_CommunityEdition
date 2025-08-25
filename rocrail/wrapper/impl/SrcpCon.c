/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/SrcpCon.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.SrcpCon
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_srcpcon = {
  "srcpcon",  "SRCP client service port.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_srcpcon.name;
}
static const char* _node_remark(void) {
  return RocsWgen_srcpcon.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_srcpcon.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_srcpcon.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * active
 */
static struct __attrdef RocsWgen_active = {
  "active",  "Activate srcp service.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isactive(iONode node) {
  Boolean defval = xBool( RocsWgen_active );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_srcpcon, node );
  return NodeOp.getBool( node, "active", defval );
}
static void _setactive(iONode node, Boolean p_active) {
  if( node == NULL ) return;
  xNode( RocsWgen_srcpcon, node );
  NodeOp.setBool( node, "active", p_active );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * device
 */
static struct __attrdef RocsWgen_device = {
  "device",  "Optional serial device.",  "",  "string",  "",  "*",  False,
};
static const char* _getdevice(iONode node) {
  const char* defval = xStr( RocsWgen_device );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_srcpcon, node );
  return NodeOp.getStr( node, "device", defval );
}
static void _setdevice(iONode node, const char* p_device) {
  if( node == NULL ) return;
  xNode( RocsWgen_srcpcon, node );
  NodeOp.setStr( node, "device", p_device );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * maxcon
 */
static struct __attrdef RocsWgen_maxcon = {
  "maxcon",  "Max. concurrent connected clients.",  "",  "int",  "10",  "1-100",  False,
};
static int _getmaxcon(iONode node) {
  int defval = xInt( RocsWgen_maxcon );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_srcpcon, node );
  return NodeOp.getInt( node, "maxcon", defval );
}
static void _setmaxcon(iONode node, int p_maxcon) {
  if( node == NULL ) return;
  xNode( RocsWgen_srcpcon, node );
  NodeOp.setInt( node, "maxcon", p_maxcon );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "",  "",  "int",  "4303",  "1-65535",  False,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_srcpcon, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_srcpcon, node );
  NodeOp.setInt( node, "port", p_port );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * srcpbus
 */
static struct __nodedef RocsWgen_srcpbus = {
  "srcpbus",  "",  False,  "n",};
static iONode _getsrcpbus(iONode node) {
  xNode( RocsWgen_srcpcon, node );
  return NodeOp.findNode( node, "srcpbus");
}


static iONode _nextsrcpbus(iONode node, iONode child) {
  xNode( RocsWgen_srcpcon, node );
  return NodeOp.findNextNode( node, child);
}
static void _setsrcpbus(iONode node, iONode p_srcpbus) {
  xNode( RocsWgen_srcpcon, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[5] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_srcpcon.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node srcpcon not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node srcpcon not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_active;
  attrList[1] = &RocsWgen_device;
  attrList[2] = &RocsWgen_maxcon;
  attrList[3] = &RocsWgen_port;
  attrList[4] = NULL;
  nodeList[0] = &RocsWgen_srcpbus;
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


struct __wSrcpCon wSrcpCon = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isactive,
  _setactive,
  _getdevice,
  _setdevice,
  _getmaxcon,
  _setmaxcon,
  _getport,
  _setport,
  _getsrcpbus,
  _nextsrcpbus,
  _setsrcpbus,
  _node_dump,
};
