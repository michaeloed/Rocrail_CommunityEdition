/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/SRCP.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.SRCP
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_srcp = {
  "srcp",  "SRCP init",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_srcp.name;
}
static const char* _node_remark(void) {
  return RocsWgen_srcp.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_srcp.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_srcp.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmdport
 */
static struct __attrdef RocsWgen_cmdport = {
  "cmdport",  "SRCP command port.",  "",  "int",  "4303",  "",  False,
};
static int _getcmdport(iONode node) {
  int defval = xInt( RocsWgen_cmdport );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_srcp, node );
  return NodeOp.getInt( node, "cmdport", defval );
}
static void _setcmdport(iONode node, int p_cmdport) {
  if( node == NULL ) return;
  xNode( RocsWgen_srcp, node );
  NodeOp.setInt( node, "cmdport", p_cmdport );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * srcpbusFB_i8255
 */
static struct __attrdef RocsWgen_srcpbusFB_i8255 = {
  "srcpbusFB_i8255",  "i8255 feedback bus",  "",  "int",  "10",  "",  False,
};
static int _getsrcpbusFB_i8255(iONode node) {
  int defval = xInt( RocsWgen_srcpbusFB_i8255 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_srcp, node );
  return NodeOp.getInt( node, "srcpbusFB_i8255", defval );
}
static void _setsrcpbusFB_i8255(iONode node, int p_srcpbusFB_i8255) {
  if( node == NULL ) return;
  xNode( RocsWgen_srcp, node );
  NodeOp.setInt( node, "srcpbusFB_i8255", p_srcpbusFB_i8255 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * srcpbusFB_m6051
 */
static struct __attrdef RocsWgen_srcpbusFB_m6051 = {
  "srcpbusFB_m6051",  "m6051 feedback bus",  "",  "int",  "9",  "",  False,
};
static int _getsrcpbusFB_m6051(iONode node) {
  int defval = xInt( RocsWgen_srcpbusFB_m6051 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_srcp, node );
  return NodeOp.getInt( node, "srcpbusFB_m6051", defval );
}
static void _setsrcpbusFB_m6051(iONode node, int p_srcpbusFB_m6051) {
  if( node == NULL ) return;
  xNode( RocsWgen_srcp, node );
  NodeOp.setInt( node, "srcpbusFB_m6051", p_srcpbusFB_m6051 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * srcpbusFB_s88
 */
static struct __attrdef RocsWgen_srcpbusFB_s88 = {
  "srcpbusFB_s88",  "s88 feedback bus",  "",  "int",  "8",  "",  False,
};
static int _getsrcpbusFB_s88(iONode node) {
  int defval = xInt( RocsWgen_srcpbusFB_s88 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_srcp, node );
  return NodeOp.getInt( node, "srcpbusFB_s88", defval );
}
static void _setsrcpbusFB_s88(iONode node, int p_srcpbusFB_s88) {
  if( node == NULL ) return;
  xNode( RocsWgen_srcp, node );
  NodeOp.setInt( node, "srcpbusFB_s88", p_srcpbusFB_s88 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * srcpbusGA_m
 */
static struct __attrdef RocsWgen_srcpbusGA_m = {
  "srcpbusGA_m",  "marklin generic accessorie bus",  "",  "int",  "5",  "",  False,
};
static int _getsrcpbusGA_m(iONode node) {
  int defval = xInt( RocsWgen_srcpbusGA_m );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_srcp, node );
  return NodeOp.getInt( node, "srcpbusGA_m", defval );
}
static void _setsrcpbusGA_m(iONode node, int p_srcpbusGA_m) {
  if( node == NULL ) return;
  xNode( RocsWgen_srcp, node );
  NodeOp.setInt( node, "srcpbusGA_m", p_srcpbusGA_m );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * srcpbusGA_n
 */
static struct __attrdef RocsWgen_srcpbusGA_n = {
  "srcpbusGA_n",  "nmra dcc generic accessorie bus",  "",  "int",  "6",  "",  False,
};
static int _getsrcpbusGA_n(iONode node) {
  int defval = xInt( RocsWgen_srcpbusGA_n );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_srcp, node );
  return NodeOp.getInt( node, "srcpbusGA_n", defval );
}
static void _setsrcpbusGA_n(iONode node, int p_srcpbusGA_n) {
  if( node == NULL ) return;
  xNode( RocsWgen_srcp, node );
  NodeOp.setInt( node, "srcpbusGA_n", p_srcpbusGA_n );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * srcpbusGA_ps
 */
static struct __attrdef RocsWgen_srcpbusGA_ps = {
  "srcpbusGA_ps",  "protocol by server generic accessorie",  "",  "int",  "7",  "",  False,
};
static int _getsrcpbusGA_ps(iONode node) {
  int defval = xInt( RocsWgen_srcpbusGA_ps );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_srcp, node );
  return NodeOp.getInt( node, "srcpbusGA_ps", defval );
}
static void _setsrcpbusGA_ps(iONode node, int p_srcpbusGA_ps) {
  if( node == NULL ) return;
  xNode( RocsWgen_srcp, node );
  NodeOp.setInt( node, "srcpbusGA_ps", p_srcpbusGA_ps );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * srcpbusGL_m
 */
static struct __attrdef RocsWgen_srcpbusGL_m = {
  "srcpbusGL_m",  "maerklin generic loco bus",  "",  "int",  "1",  "",  False,
};
static int _getsrcpbusGL_m(iONode node) {
  int defval = xInt( RocsWgen_srcpbusGL_m );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_srcp, node );
  return NodeOp.getInt( node, "srcpbusGL_m", defval );
}
static void _setsrcpbusGL_m(iONode node, int p_srcpbusGL_m) {
  if( node == NULL ) return;
  xNode( RocsWgen_srcp, node );
  NodeOp.setInt( node, "srcpbusGL_m", p_srcpbusGL_m );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * srcpbusGL_nl
 */
static struct __attrdef RocsWgen_srcpbusGL_nl = {
  "srcpbusGL_nl",  "nmra dcc generic loco with long addr bus",  "",  "int",  "3",  "",  False,
};
static int _getsrcpbusGL_nl(iONode node) {
  int defval = xInt( RocsWgen_srcpbusGL_nl );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_srcp, node );
  return NodeOp.getInt( node, "srcpbusGL_nl", defval );
}
static void _setsrcpbusGL_nl(iONode node, int p_srcpbusGL_nl) {
  if( node == NULL ) return;
  xNode( RocsWgen_srcp, node );
  NodeOp.setInt( node, "srcpbusGL_nl", p_srcpbusGL_nl );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * srcpbusGL_ns
 */
static struct __attrdef RocsWgen_srcpbusGL_ns = {
  "srcpbusGL_ns",  "nmra dcc generic loco with short addr bus",  "",  "int",  "2",  "",  False,
};
static int _getsrcpbusGL_ns(iONode node) {
  int defval = xInt( RocsWgen_srcpbusGL_ns );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_srcp, node );
  return NodeOp.getInt( node, "srcpbusGL_ns", defval );
}
static void _setsrcpbusGL_ns(iONode node, int p_srcpbusGL_ns) {
  if( node == NULL ) return;
  xNode( RocsWgen_srcp, node );
  NodeOp.setInt( node, "srcpbusGL_ns", p_srcpbusGL_ns );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * srcpbusGL_ps
 */
static struct __attrdef RocsWgen_srcpbusGL_ps = {
  "srcpbusGL_ps",  "protocol by server generic loco",  "",  "int",  "4",  "",  False,
};
static int _getsrcpbusGL_ps(iONode node) {
  int defval = xInt( RocsWgen_srcpbusGL_ps );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_srcp, node );
  return NodeOp.getInt( node, "srcpbusGL_ps", defval );
}
static void _setsrcpbusGL_ps(iONode node, int p_srcpbusGL_ps) {
  if( node == NULL ) return;
  xNode( RocsWgen_srcp, node );
  NodeOp.setInt( node, "srcpbusGL_ps", p_srcpbusGL_ps );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * srcpbus_server
 */
static struct __attrdef RocsWgen_srcpbus_server = {
  "srcpbus_server",  "server bus",  "",  "int",  "0",  "",  False,
};
static int _getsrcpbus_server(iONode node) {
  int defval = xInt( RocsWgen_srcpbus_server );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_srcp, node );
  return NodeOp.getInt( node, "srcpbus_server", defval );
}
static void _setsrcpbus_server(iONode node, int p_srcpbus_server) {
  if( node == NULL ) return;
  xNode( RocsWgen_srcp, node );
  NodeOp.setInt( node, "srcpbus_server", p_srcpbus_server );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[13] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_srcp.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node srcp not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node srcp not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_cmdport;
  attrList[1] = &RocsWgen_srcpbusFB_i8255;
  attrList[2] = &RocsWgen_srcpbusFB_m6051;
  attrList[3] = &RocsWgen_srcpbusFB_s88;
  attrList[4] = &RocsWgen_srcpbusGA_m;
  attrList[5] = &RocsWgen_srcpbusGA_n;
  attrList[6] = &RocsWgen_srcpbusGA_ps;
  attrList[7] = &RocsWgen_srcpbusGL_m;
  attrList[8] = &RocsWgen_srcpbusGL_nl;
  attrList[9] = &RocsWgen_srcpbusGL_ns;
  attrList[10] = &RocsWgen_srcpbusGL_ps;
  attrList[11] = &RocsWgen_srcpbus_server;
  attrList[12] = NULL;
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


struct __wSRCP wSRCP = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getcmdport,
  _setcmdport,
  _getsrcpbusFB_i8255,
  _setsrcpbusFB_i8255,
  _getsrcpbusFB_m6051,
  _setsrcpbusFB_m6051,
  _getsrcpbusFB_s88,
  _setsrcpbusFB_s88,
  _getsrcpbusGA_m,
  _setsrcpbusGA_m,
  _getsrcpbusGA_n,
  _setsrcpbusGA_n,
  _getsrcpbusGA_ps,
  _setsrcpbusGA_ps,
  _getsrcpbusGL_m,
  _setsrcpbusGL_m,
  _getsrcpbusGL_nl,
  _setsrcpbusGL_nl,
  _getsrcpbusGL_ns,
  _setsrcpbusGL_ns,
  _getsrcpbusGL_ps,
  _setsrcpbusGL_ps,
  _getsrcpbus_server,
  _setsrcpbus_server,
  _node_dump,
};
