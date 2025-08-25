/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/DDX.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.DDX
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_ddx = {
  "ddx",  "DDX init",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_ddx.name;
}
static const char* _node_remark(void) {
  return RocsWgen_ddx.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_ddx.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_ddx.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * dcc
 */
static struct __attrdef RocsWgen_dcc = {
  "dcc",  "generate the NMRA DCC protocol",  "",  "bool",  "true",  "",  False,
};
static Boolean _isdcc(iONode node) {
  Boolean defval = xBool( RocsWgen_dcc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getBool( node, "dcc", defval );
}
static void _setdcc(iONode node, Boolean p_dcc) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setBool( node, "dcc", p_dcc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fastcvget
 */
static struct __attrdef RocsWgen_fastcvget = {
  "fastcvget",  "Fast cv get for real rs232.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isfastcvget(iONode node) {
  Boolean defval = xBool( RocsWgen_fastcvget );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getBool( node, "fastcvget", defval );
}
static void _setfastcvget(iONode node, Boolean p_fastcvget) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setBool( node, "fastcvget", p_fastcvget );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * inversedsr
 */
static struct __attrdef RocsWgen_inversedsr = {
  "inversedsr",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isinversedsr(iONode node) {
  Boolean defval = xBool( RocsWgen_inversedsr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getBool( node, "inversedsr", defval );
}
static void _setinversedsr(iONode node, Boolean p_inversedsr) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setBool( node, "inversedsr", p_inversedsr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mmlongpause
 */
static struct __attrdef RocsWgen_mmlongpause = {
  "mmlongpause",  "Use long packet pause.",  "",  "bool",  "false",  "",  False,
};
static Boolean _ismmlongpause(iONode node) {
  Boolean defval = xBool( RocsWgen_mmlongpause );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getBool( node, "mmlongpause", defval );
}
static void _setmmlongpause(iONode node, Boolean p_mmlongpause) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setBool( node, "mmlongpause", p_mmlongpause );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * motorola
 */
static struct __attrdef RocsWgen_motorola = {
  "motorola",  "generate the motorola protocol",  "",  "bool",  "true",  "",  False,
};
static Boolean _ismotorola(iONode node) {
  Boolean defval = xBool( RocsWgen_motorola );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getBool( node, "motorola", defval );
}
static void _setmotorola(iONode node, Boolean p_motorola) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setBool( node, "motorola", p_motorola );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * motorolarefresh
 */
static struct __attrdef RocsWgen_motorolarefresh = {
  "motorolarefresh",  "set to false if no MM locdecoders are used and accessory are MM",  "",  "bool",  "true",  "",  False,
};
static Boolean _ismotorolarefresh(iONode node) {
  Boolean defval = xBool( RocsWgen_motorolarefresh );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getBool( node, "motorolarefresh", defval );
}
static void _setmotorolarefresh(iONode node, Boolean p_motorolarefresh) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setBool( node, "motorolarefresh", p_motorolarefresh );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "",  "",  "string",  "/dev/ttyS0",  "*",  False,
};
static const char* _getport(iONode node) {
  const char* defval = xStr( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getStr( node, "port", defval );
}
static void _setport(iONode node, const char* p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setStr( node, "port", p_port );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * portbase
 */
static struct __attrdef RocsWgen_portbase = {
  "portbase",  "",  "",  "string",  "0x0000",  "*",  False,
};
static const char* _getportbase(iONode node) {
  const char* defval = xStr( RocsWgen_portbase );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getStr( node, "portbase", defval );
}
static void _setportbase(iONode node, const char* p_portbase) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setStr( node, "portbase", p_portbase );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * queuecheck
 */
static struct __attrdef RocsWgen_queuecheck = {
  "queuecheck",  "Check if there are bytes left in the send queue and sleep.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isqueuecheck(iONode node) {
  Boolean defval = xBool( RocsWgen_queuecheck );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getBool( node, "queuecheck", defval );
}
static void _setqueuecheck(iONode node, Boolean p_queuecheck) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setBool( node, "queuecheck", p_queuecheck );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * realnmratiming
 */
static struct __attrdef RocsWgen_realnmratiming = {
  "realnmratiming",  "experimental: do not use",  "",  "bool",  "false",  "",  False,
};
static Boolean _isrealnmratiming(iONode node) {
  Boolean defval = xBool( RocsWgen_realnmratiming );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getBool( node, "realnmratiming", defval );
}
static void _setrealnmratiming(iONode node, Boolean p_realnmratiming) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setBool( node, "realnmratiming", p_realnmratiming );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * s88b0modcnt
 */
static struct __attrdef RocsWgen_s88b0modcnt = {
  "s88b0modcnt",  "one module represents 8 inputs (one byte)",  "",  "int",  "0",  "0-62",  False,
};
static int _gets88b0modcnt(iONode node) {
  int defval = xInt( RocsWgen_s88b0modcnt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getInt( node, "s88b0modcnt", defval );
}
static void _sets88b0modcnt(iONode node, int p_s88b0modcnt) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setInt( node, "s88b0modcnt", p_s88b0modcnt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * s88b1modcnt
 */
static struct __attrdef RocsWgen_s88b1modcnt = {
  "s88b1modcnt",  "one module represents 8 inputs (one byte)",  "",  "int",  "0",  "0-62",  False,
};
static int _gets88b1modcnt(iONode node) {
  int defval = xInt( RocsWgen_s88b1modcnt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getInt( node, "s88b1modcnt", defval );
}
static void _sets88b1modcnt(iONode node, int p_s88b1modcnt) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setInt( node, "s88b1modcnt", p_s88b1modcnt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * s88b2modcnt
 */
static struct __attrdef RocsWgen_s88b2modcnt = {
  "s88b2modcnt",  "one module represents 8 inputs (one byte)",  "",  "int",  "0",  "0-62",  False,
};
static int _gets88b2modcnt(iONode node) {
  int defval = xInt( RocsWgen_s88b2modcnt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getInt( node, "s88b2modcnt", defval );
}
static void _sets88b2modcnt(iONode node, int p_s88b2modcnt) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setInt( node, "s88b2modcnt", p_s88b2modcnt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * s88b3modcnt
 */
static struct __attrdef RocsWgen_s88b3modcnt = {
  "s88b3modcnt",  "one module represents 8 inputs (one byte)",  "",  "int",  "0",  "0-62",  False,
};
static int _gets88b3modcnt(iONode node) {
  int defval = xInt( RocsWgen_s88b3modcnt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getInt( node, "s88b3modcnt", defval );
}
static void _sets88b3modcnt(iONode node, int p_s88b3modcnt) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setInt( node, "s88b3modcnt", p_s88b3modcnt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * s88busses
 */
static struct __attrdef RocsWgen_s88busses = {
  "s88busses",  "",  "",  "int",  "1",  "1-4",  False,
};
static int _gets88busses(iONode node) {
  int defval = xInt( RocsWgen_s88busses );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getInt( node, "s88busses", defval );
}
static void _sets88busses(iONode node, int p_s88busses) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setInt( node, "s88busses", p_s88busses );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * s88clockscale
 */
static struct __attrdef RocsWgen_s88clockscale = {
  "s88clockscale",  "clock=166kHz divided by S88CLOCK_SCALE",  "",  "int",  "35",  "1-50",  False,
};
static int _gets88clockscale(iONode node) {
  int defval = xInt( RocsWgen_s88clockscale );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getInt( node, "s88clockscale", defval );
}
static void _sets88clockscale(iONode node, int p_s88clockscale) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setInt( node, "s88clockscale", p_s88clockscale );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * s88port
 */
static struct __attrdef RocsWgen_s88port = {
  "s88port",  "",  "",  "string",  "0x378",  "*",  False,
};
static const char* _gets88port(iONode node) {
  const char* defval = xStr( RocsWgen_s88port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getStr( node, "s88port", defval );
}
static void _sets88port(iONode node, const char* p_s88port) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setStr( node, "s88port", p_s88port );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * s88refresh
 */
static struct __attrdef RocsWgen_s88refresh = {
  "s88refresh",  "time between the bus polling",  "ms",  "int",  "100",  "50-250",  False,
};
static int _gets88refresh(iONode node) {
  int defval = xInt( RocsWgen_s88refresh );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getInt( node, "s88refresh", defval );
}
static void _sets88refresh(iONode node, int p_s88refresh) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setInt( node, "s88refresh", p_s88refresh );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * shortcutchecking
 */
static struct __attrdef RocsWgen_shortcutchecking = {
  "shortcutchecking",  "Use shortcut detection",  "",  "bool",  "false",  "",  False,
};
static Boolean _isshortcutchecking(iONode node) {
  Boolean defval = xBool( RocsWgen_shortcutchecking );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getBool( node, "shortcutchecking", defval );
}
static void _setshortcutchecking(iONode node, Boolean p_shortcutchecking) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setBool( node, "shortcutchecking", p_shortcutchecking );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * shortcutdelay
 */
static struct __attrdef RocsWgen_shortcutdelay = {
  "shortcutdelay",  "Shortcut events shorter than this time is ignored",  "us",  "int",  "1000",  "",  False,
};
static int _getshortcutdelay(iONode node) {
  int defval = xInt( RocsWgen_shortcutdelay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ddx, node );
  return NodeOp.getInt( node, "shortcutdelay", defval );
}
static void _setshortcutdelay(iONode node, int p_shortcutdelay) {
  if( node == NULL ) return;
  xNode( RocsWgen_ddx, node );
  NodeOp.setInt( node, "shortcutdelay", p_shortcutdelay );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[21] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_ddx.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node ddx not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node ddx not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_dcc;
  attrList[1] = &RocsWgen_fastcvget;
  attrList[2] = &RocsWgen_inversedsr;
  attrList[3] = &RocsWgen_mmlongpause;
  attrList[4] = &RocsWgen_motorola;
  attrList[5] = &RocsWgen_motorolarefresh;
  attrList[6] = &RocsWgen_port;
  attrList[7] = &RocsWgen_portbase;
  attrList[8] = &RocsWgen_queuecheck;
  attrList[9] = &RocsWgen_realnmratiming;
  attrList[10] = &RocsWgen_s88b0modcnt;
  attrList[11] = &RocsWgen_s88b1modcnt;
  attrList[12] = &RocsWgen_s88b2modcnt;
  attrList[13] = &RocsWgen_s88b3modcnt;
  attrList[14] = &RocsWgen_s88busses;
  attrList[15] = &RocsWgen_s88clockscale;
  attrList[16] = &RocsWgen_s88port;
  attrList[17] = &RocsWgen_s88refresh;
  attrList[18] = &RocsWgen_shortcutchecking;
  attrList[19] = &RocsWgen_shortcutdelay;
  attrList[20] = NULL;
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


struct __wDDX wDDX = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isdcc,
  _setdcc,
  _isfastcvget,
  _setfastcvget,
  _isinversedsr,
  _setinversedsr,
  _ismmlongpause,
  _setmmlongpause,
  _ismotorola,
  _setmotorola,
  _ismotorolarefresh,
  _setmotorolarefresh,
  _getport,
  _setport,
  _getportbase,
  _setportbase,
  _isqueuecheck,
  _setqueuecheck,
  _isrealnmratiming,
  _setrealnmratiming,
  _gets88b0modcnt,
  _sets88b0modcnt,
  _gets88b1modcnt,
  _sets88b1modcnt,
  _gets88b2modcnt,
  _sets88b2modcnt,
  _gets88b3modcnt,
  _sets88b3modcnt,
  _gets88busses,
  _sets88busses,
  _gets88clockscale,
  _sets88clockscale,
  _gets88port,
  _sets88port,
  _gets88refresh,
  _sets88refresh,
  _isshortcutchecking,
  _setshortcutchecking,
  _getshortcutdelay,
  _setshortcutdelay,
  _node_dump,
};
