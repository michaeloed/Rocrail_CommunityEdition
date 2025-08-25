/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/FunCmd.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.FunCmd
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_fn = {
  "fn",  "Function command.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_fn.name;
}
static const char* _node_remark(void) {
  return RocsWgen_fn.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_fn.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_fn.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr
 */
static struct __attrdef RocsWgen_addr = {
  "addr",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getaddr(iONode node) {
  int defval = xInt( RocsWgen_addr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "addr", defval );
}
static void _setaddr(iONode node, int p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "addr", p_addr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bus
 */
static struct __attrdef RocsWgen_bus = {
  "bus",  "Some systems support more than one bus: SLX",  "",  "int",  "0",  "0-*",  False,
};
static int _getbus(iONode node) {
  int defval = xInt( RocsWgen_bus );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "bus", defval );
}
static void _setbus(iONode node, int p_bus) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "bus", p_bus );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * event
 */
static struct __attrdef RocsWgen_event = {
  "event",  "function deactivation event",  "",  "const char*",  "none",  "*",  False,
};
static const char* _getevent(iONode node) {
  const char* defval = xStr( RocsWgen_event );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getStr( node, "event", defval );
}
static void _setevent(iONode node, const char* p_event) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setStr( node, "event", p_event );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * eventblock
 */
static struct __attrdef RocsWgen_eventblock = {
  "eventblock",  "function deactivation block",  "",  "char*",  "NULL",  "*",  False,
};
static const char* _geteventblock(iONode node) {
  const char* defval = xStr( RocsWgen_eventblock );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getStr( node, "eventblock", defval );
}
static void _seteventblock(iONode node, const char* p_eventblock) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setStr( node, "eventblock", p_eventblock );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f0
 */
static struct __attrdef RocsWgen_f0 = {
  "f0",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf0(iONode node) {
  Boolean defval = xBool( RocsWgen_f0 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f0", defval );
}
static void _setf0(iONode node, Boolean p_f0) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f0", p_f0 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f1
 */
static struct __attrdef RocsWgen_f1 = {
  "f1",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf1(iONode node) {
  Boolean defval = xBool( RocsWgen_f1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f1", defval );
}
static void _setf1(iONode node, Boolean p_f1) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f1", p_f1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f10
 */
static struct __attrdef RocsWgen_f10 = {
  "f10",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf10(iONode node) {
  Boolean defval = xBool( RocsWgen_f10 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f10", defval );
}
static void _setf10(iONode node, Boolean p_f10) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f10", p_f10 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f11
 */
static struct __attrdef RocsWgen_f11 = {
  "f11",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf11(iONode node) {
  Boolean defval = xBool( RocsWgen_f11 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f11", defval );
}
static void _setf11(iONode node, Boolean p_f11) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f11", p_f11 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f12
 */
static struct __attrdef RocsWgen_f12 = {
  "f12",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf12(iONode node) {
  Boolean defval = xBool( RocsWgen_f12 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f12", defval );
}
static void _setf12(iONode node, Boolean p_f12) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f12", p_f12 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f13
 */
static struct __attrdef RocsWgen_f13 = {
  "f13",  "",  "",  "bool",  "",  "",  False,
};
static Boolean _isf13(iONode node) {
  Boolean defval = xBool( RocsWgen_f13 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f13", defval );
}
static void _setf13(iONode node, Boolean p_f13) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f13", p_f13 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f14
 */
static struct __attrdef RocsWgen_f14 = {
  "f14",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf14(iONode node) {
  Boolean defval = xBool( RocsWgen_f14 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f14", defval );
}
static void _setf14(iONode node, Boolean p_f14) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f14", p_f14 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f15
 */
static struct __attrdef RocsWgen_f15 = {
  "f15",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf15(iONode node) {
  Boolean defval = xBool( RocsWgen_f15 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f15", defval );
}
static void _setf15(iONode node, Boolean p_f15) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f15", p_f15 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f16
 */
static struct __attrdef RocsWgen_f16 = {
  "f16",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf16(iONode node) {
  Boolean defval = xBool( RocsWgen_f16 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f16", defval );
}
static void _setf16(iONode node, Boolean p_f16) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f16", p_f16 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f17
 */
static struct __attrdef RocsWgen_f17 = {
  "f17",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf17(iONode node) {
  Boolean defval = xBool( RocsWgen_f17 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f17", defval );
}
static void _setf17(iONode node, Boolean p_f17) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f17", p_f17 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f18
 */
static struct __attrdef RocsWgen_f18 = {
  "f18",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf18(iONode node) {
  Boolean defval = xBool( RocsWgen_f18 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f18", defval );
}
static void _setf18(iONode node, Boolean p_f18) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f18", p_f18 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f19
 */
static struct __attrdef RocsWgen_f19 = {
  "f19",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf19(iONode node) {
  Boolean defval = xBool( RocsWgen_f19 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f19", defval );
}
static void _setf19(iONode node, Boolean p_f19) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f19", p_f19 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f2
 */
static struct __attrdef RocsWgen_f2 = {
  "f2",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf2(iONode node) {
  Boolean defval = xBool( RocsWgen_f2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f2", defval );
}
static void _setf2(iONode node, Boolean p_f2) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f2", p_f2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f20
 */
static struct __attrdef RocsWgen_f20 = {
  "f20",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf20(iONode node) {
  Boolean defval = xBool( RocsWgen_f20 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f20", defval );
}
static void _setf20(iONode node, Boolean p_f20) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f20", p_f20 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f21
 */
static struct __attrdef RocsWgen_f21 = {
  "f21",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf21(iONode node) {
  Boolean defval = xBool( RocsWgen_f21 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f21", defval );
}
static void _setf21(iONode node, Boolean p_f21) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f21", p_f21 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f22
 */
static struct __attrdef RocsWgen_f22 = {
  "f22",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf22(iONode node) {
  Boolean defval = xBool( RocsWgen_f22 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f22", defval );
}
static void _setf22(iONode node, Boolean p_f22) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f22", p_f22 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f23
 */
static struct __attrdef RocsWgen_f23 = {
  "f23",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf23(iONode node) {
  Boolean defval = xBool( RocsWgen_f23 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f23", defval );
}
static void _setf23(iONode node, Boolean p_f23) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f23", p_f23 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f24
 */
static struct __attrdef RocsWgen_f24 = {
  "f24",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf24(iONode node) {
  Boolean defval = xBool( RocsWgen_f24 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f24", defval );
}
static void _setf24(iONode node, Boolean p_f24) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f24", p_f24 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f25
 */
static struct __attrdef RocsWgen_f25 = {
  "f25",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf25(iONode node) {
  Boolean defval = xBool( RocsWgen_f25 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f25", defval );
}
static void _setf25(iONode node, Boolean p_f25) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f25", p_f25 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f26
 */
static struct __attrdef RocsWgen_f26 = {
  "f26",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf26(iONode node) {
  Boolean defval = xBool( RocsWgen_f26 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f26", defval );
}
static void _setf26(iONode node, Boolean p_f26) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f26", p_f26 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f27
 */
static struct __attrdef RocsWgen_f27 = {
  "f27",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf27(iONode node) {
  Boolean defval = xBool( RocsWgen_f27 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f27", defval );
}
static void _setf27(iONode node, Boolean p_f27) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f27", p_f27 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f28
 */
static struct __attrdef RocsWgen_f28 = {
  "f28",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf28(iONode node) {
  Boolean defval = xBool( RocsWgen_f28 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f28", defval );
}
static void _setf28(iONode node, Boolean p_f28) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f28", p_f28 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f3
 */
static struct __attrdef RocsWgen_f3 = {
  "f3",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf3(iONode node) {
  Boolean defval = xBool( RocsWgen_f3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f3", defval );
}
static void _setf3(iONode node, Boolean p_f3) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f3", p_f3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f4
 */
static struct __attrdef RocsWgen_f4 = {
  "f4",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf4(iONode node) {
  Boolean defval = xBool( RocsWgen_f4 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f4", defval );
}
static void _setf4(iONode node, Boolean p_f4) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f4", p_f4 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f5
 */
static struct __attrdef RocsWgen_f5 = {
  "f5",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf5(iONode node) {
  Boolean defval = xBool( RocsWgen_f5 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f5", defval );
}
static void _setf5(iONode node, Boolean p_f5) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f5", p_f5 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f6
 */
static struct __attrdef RocsWgen_f6 = {
  "f6",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf6(iONode node) {
  Boolean defval = xBool( RocsWgen_f6 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f6", defval );
}
static void _setf6(iONode node, Boolean p_f6) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f6", p_f6 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f7
 */
static struct __attrdef RocsWgen_f7 = {
  "f7",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf7(iONode node) {
  Boolean defval = xBool( RocsWgen_f7 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f7", defval );
}
static void _setf7(iONode node, Boolean p_f7) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f7", p_f7 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f8
 */
static struct __attrdef RocsWgen_f8 = {
  "f8",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf8(iONode node) {
  Boolean defval = xBool( RocsWgen_f8 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f8", defval );
}
static void _setf8(iONode node, Boolean p_f8) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f8", p_f8 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f9
 */
static struct __attrdef RocsWgen_f9 = {
  "f9",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isf9(iONode node) {
  Boolean defval = xBool( RocsWgen_f9 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "f9", defval );
}
static void _setf9(iONode node, Boolean p_f9) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "f9", p_f9 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fnchanged
 */
static struct __attrdef RocsWgen_fnchanged = {
  "fnchanged",  "actual changed function",  "",  "int",  "-1",  "",  False,
};
static int _getfnchanged(iONode node) {
  int defval = xInt( RocsWgen_fnchanged );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "fnchanged", defval );
}
static void _setfnchanged(iONode node, int p_fnchanged) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "fnchanged", p_fnchanged );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fnchangedstate
 */
static struct __attrdef RocsWgen_fnchangedstate = {
  "fnchangedstate",  "actual changed function state",  "",  "bool",  "false",  "",  False,
};
static Boolean _isfnchangedstate(iONode node) {
  Boolean defval = xBool( RocsWgen_fnchangedstate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getBool( node, "fnchangedstate", defval );
}
static void _setfnchangedstate(iONode node, Boolean p_fnchangedstate) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setBool( node, "fnchangedstate", p_fnchangedstate );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fncnt
 */
static struct __attrdef RocsWgen_fncnt = {
  "fncnt",  "number of decoder funktions",  "",  "int",  "4",  "0-*",  False,
};
static int _getfncnt(iONode node) {
  int defval = xInt( RocsWgen_fncnt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "fncnt", defval );
}
static void _setfncnt(iONode node, int p_fncnt) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "fncnt", p_fncnt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * group
 */
static struct __attrdef RocsWgen_group = {
  "group",  "0=all, 1=f1-f4, 2=f5-f8, 3=f9-f12, 4=f13-f16, 5=f17-f20, 6=f21-f24, 7=f25-f28",  "",  "int",  "0",  "0-*",  False,
};
static int _getgroup(iONode node) {
  int defval = xInt( RocsWgen_group );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "group", defval );
}
static void _setgroup(iONode node, int p_group) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "group", p_group );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timedfn
 */
static struct __attrdef RocsWgen_timedfn = {
  "timedfn",  "",  "",  "int",  "-1",  "0-*",  False,
};
static int _gettimedfn(iONode node) {
  int defval = xInt( RocsWgen_timedfn );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timedfn", defval );
}
static void _settimedfn(iONode node, int p_timedfn) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timedfn", p_timedfn );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timer
 */
static struct __attrdef RocsWgen_timer = {
  "timer",  "function activation timer",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimer(iONode node) {
  int defval = xInt( RocsWgen_timer );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timer", defval );
}
static void _settimer(iONode node, int p_timer) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timer", p_timer );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf0
 */
static struct __attrdef RocsWgen_timerf0 = {
  "timerf0",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf0(iONode node) {
  int defval = xInt( RocsWgen_timerf0 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf0", defval );
}
static void _settimerf0(iONode node, int p_timerf0) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf0", p_timerf0 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf1
 */
static struct __attrdef RocsWgen_timerf1 = {
  "timerf1",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf1(iONode node) {
  int defval = xInt( RocsWgen_timerf1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf1", defval );
}
static void _settimerf1(iONode node, int p_timerf1) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf1", p_timerf1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf10
 */
static struct __attrdef RocsWgen_timerf10 = {
  "timerf10",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf10(iONode node) {
  int defval = xInt( RocsWgen_timerf10 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf10", defval );
}
static void _settimerf10(iONode node, int p_timerf10) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf10", p_timerf10 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf11
 */
static struct __attrdef RocsWgen_timerf11 = {
  "timerf11",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf11(iONode node) {
  int defval = xInt( RocsWgen_timerf11 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf11", defval );
}
static void _settimerf11(iONode node, int p_timerf11) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf11", p_timerf11 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf12
 */
static struct __attrdef RocsWgen_timerf12 = {
  "timerf12",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf12(iONode node) {
  int defval = xInt( RocsWgen_timerf12 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf12", defval );
}
static void _settimerf12(iONode node, int p_timerf12) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf12", p_timerf12 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf13
 */
static struct __attrdef RocsWgen_timerf13 = {
  "timerf13",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf13(iONode node) {
  int defval = xInt( RocsWgen_timerf13 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf13", defval );
}
static void _settimerf13(iONode node, int p_timerf13) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf13", p_timerf13 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf14
 */
static struct __attrdef RocsWgen_timerf14 = {
  "timerf14",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf14(iONode node) {
  int defval = xInt( RocsWgen_timerf14 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf14", defval );
}
static void _settimerf14(iONode node, int p_timerf14) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf14", p_timerf14 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf15
 */
static struct __attrdef RocsWgen_timerf15 = {
  "timerf15",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf15(iONode node) {
  int defval = xInt( RocsWgen_timerf15 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf15", defval );
}
static void _settimerf15(iONode node, int p_timerf15) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf15", p_timerf15 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf16
 */
static struct __attrdef RocsWgen_timerf16 = {
  "timerf16",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf16(iONode node) {
  int defval = xInt( RocsWgen_timerf16 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf16", defval );
}
static void _settimerf16(iONode node, int p_timerf16) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf16", p_timerf16 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf17
 */
static struct __attrdef RocsWgen_timerf17 = {
  "timerf17",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf17(iONode node) {
  int defval = xInt( RocsWgen_timerf17 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf17", defval );
}
static void _settimerf17(iONode node, int p_timerf17) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf17", p_timerf17 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf18
 */
static struct __attrdef RocsWgen_timerf18 = {
  "timerf18",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf18(iONode node) {
  int defval = xInt( RocsWgen_timerf18 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf18", defval );
}
static void _settimerf18(iONode node, int p_timerf18) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf18", p_timerf18 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf19
 */
static struct __attrdef RocsWgen_timerf19 = {
  "timerf19",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf19(iONode node) {
  int defval = xInt( RocsWgen_timerf19 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf19", defval );
}
static void _settimerf19(iONode node, int p_timerf19) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf19", p_timerf19 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf2
 */
static struct __attrdef RocsWgen_timerf2 = {
  "timerf2",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf2(iONode node) {
  int defval = xInt( RocsWgen_timerf2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf2", defval );
}
static void _settimerf2(iONode node, int p_timerf2) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf2", p_timerf2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf20
 */
static struct __attrdef RocsWgen_timerf20 = {
  "timerf20",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf20(iONode node) {
  int defval = xInt( RocsWgen_timerf20 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf20", defval );
}
static void _settimerf20(iONode node, int p_timerf20) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf20", p_timerf20 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf21
 */
static struct __attrdef RocsWgen_timerf21 = {
  "timerf21",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf21(iONode node) {
  int defval = xInt( RocsWgen_timerf21 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf21", defval );
}
static void _settimerf21(iONode node, int p_timerf21) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf21", p_timerf21 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf22
 */
static struct __attrdef RocsWgen_timerf22 = {
  "timerf22",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf22(iONode node) {
  int defval = xInt( RocsWgen_timerf22 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf22", defval );
}
static void _settimerf22(iONode node, int p_timerf22) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf22", p_timerf22 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf23
 */
static struct __attrdef RocsWgen_timerf23 = {
  "timerf23",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf23(iONode node) {
  int defval = xInt( RocsWgen_timerf23 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf23", defval );
}
static void _settimerf23(iONode node, int p_timerf23) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf23", p_timerf23 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf24
 */
static struct __attrdef RocsWgen_timerf24 = {
  "timerf24",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf24(iONode node) {
  int defval = xInt( RocsWgen_timerf24 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf24", defval );
}
static void _settimerf24(iONode node, int p_timerf24) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf24", p_timerf24 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf25
 */
static struct __attrdef RocsWgen_timerf25 = {
  "timerf25",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf25(iONode node) {
  int defval = xInt( RocsWgen_timerf25 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf25", defval );
}
static void _settimerf25(iONode node, int p_timerf25) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf25", p_timerf25 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf26
 */
static struct __attrdef RocsWgen_timerf26 = {
  "timerf26",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf26(iONode node) {
  int defval = xInt( RocsWgen_timerf26 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf26", defval );
}
static void _settimerf26(iONode node, int p_timerf26) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf26", p_timerf26 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf27
 */
static struct __attrdef RocsWgen_timerf27 = {
  "timerf27",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf27(iONode node) {
  int defval = xInt( RocsWgen_timerf27 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf27", defval );
}
static void _settimerf27(iONode node, int p_timerf27) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf27", p_timerf27 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf28
 */
static struct __attrdef RocsWgen_timerf28 = {
  "timerf28",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf28(iONode node) {
  int defval = xInt( RocsWgen_timerf28 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf28", defval );
}
static void _settimerf28(iONode node, int p_timerf28) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf28", p_timerf28 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf3
 */
static struct __attrdef RocsWgen_timerf3 = {
  "timerf3",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf3(iONode node) {
  int defval = xInt( RocsWgen_timerf3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf3", defval );
}
static void _settimerf3(iONode node, int p_timerf3) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf3", p_timerf3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf4
 */
static struct __attrdef RocsWgen_timerf4 = {
  "timerf4",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf4(iONode node) {
  int defval = xInt( RocsWgen_timerf4 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf4", defval );
}
static void _settimerf4(iONode node, int p_timerf4) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf4", p_timerf4 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf5
 */
static struct __attrdef RocsWgen_timerf5 = {
  "timerf5",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf5(iONode node) {
  int defval = xInt( RocsWgen_timerf5 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf5", defval );
}
static void _settimerf5(iONode node, int p_timerf5) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf5", p_timerf5 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf6
 */
static struct __attrdef RocsWgen_timerf6 = {
  "timerf6",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf6(iONode node) {
  int defval = xInt( RocsWgen_timerf6 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf6", defval );
}
static void _settimerf6(iONode node, int p_timerf6) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf6", p_timerf6 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf7
 */
static struct __attrdef RocsWgen_timerf7 = {
  "timerf7",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf7(iONode node) {
  int defval = xInt( RocsWgen_timerf7 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf7", defval );
}
static void _settimerf7(iONode node, int p_timerf7) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf7", p_timerf7 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf8
 */
static struct __attrdef RocsWgen_timerf8 = {
  "timerf8",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf8(iONode node) {
  int defval = xInt( RocsWgen_timerf8 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf8", defval );
}
static void _settimerf8(iONode node, int p_timerf8) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf8", p_timerf8 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timerf9
 */
static struct __attrdef RocsWgen_timerf9 = {
  "timerf9",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _gettimerf9(iONode node) {
  int defval = xInt( RocsWgen_timerf9 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fn, node );
  return NodeOp.getInt( node, "timerf9", defval );
}
static void _settimerf9(iONode node, int p_timerf9) {
  if( node == NULL ) return;
  xNode( RocsWgen_fn, node );
  NodeOp.setInt( node, "timerf9", p_timerf9 );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[70] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_fn.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node fn not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node fn not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_addr;
  attrList[1] = &RocsWgen_bus;
  attrList[2] = &RocsWgen_event;
  attrList[3] = &RocsWgen_eventblock;
  attrList[4] = &RocsWgen_f0;
  attrList[5] = &RocsWgen_f1;
  attrList[6] = &RocsWgen_f10;
  attrList[7] = &RocsWgen_f11;
  attrList[8] = &RocsWgen_f12;
  attrList[9] = &RocsWgen_f13;
  attrList[10] = &RocsWgen_f14;
  attrList[11] = &RocsWgen_f15;
  attrList[12] = &RocsWgen_f16;
  attrList[13] = &RocsWgen_f17;
  attrList[14] = &RocsWgen_f18;
  attrList[15] = &RocsWgen_f19;
  attrList[16] = &RocsWgen_f2;
  attrList[17] = &RocsWgen_f20;
  attrList[18] = &RocsWgen_f21;
  attrList[19] = &RocsWgen_f22;
  attrList[20] = &RocsWgen_f23;
  attrList[21] = &RocsWgen_f24;
  attrList[22] = &RocsWgen_f25;
  attrList[23] = &RocsWgen_f26;
  attrList[24] = &RocsWgen_f27;
  attrList[25] = &RocsWgen_f28;
  attrList[26] = &RocsWgen_f3;
  attrList[27] = &RocsWgen_f4;
  attrList[28] = &RocsWgen_f5;
  attrList[29] = &RocsWgen_f6;
  attrList[30] = &RocsWgen_f7;
  attrList[31] = &RocsWgen_f8;
  attrList[32] = &RocsWgen_f9;
  attrList[33] = &RocsWgen_fnchanged;
  attrList[34] = &RocsWgen_fnchangedstate;
  attrList[35] = &RocsWgen_fncnt;
  attrList[36] = &RocsWgen_group;
  attrList[37] = &RocsWgen_id;
  attrList[38] = &RocsWgen_timedfn;
  attrList[39] = &RocsWgen_timer;
  attrList[40] = &RocsWgen_timerf0;
  attrList[41] = &RocsWgen_timerf1;
  attrList[42] = &RocsWgen_timerf10;
  attrList[43] = &RocsWgen_timerf11;
  attrList[44] = &RocsWgen_timerf12;
  attrList[45] = &RocsWgen_timerf13;
  attrList[46] = &RocsWgen_timerf14;
  attrList[47] = &RocsWgen_timerf15;
  attrList[48] = &RocsWgen_timerf16;
  attrList[49] = &RocsWgen_timerf17;
  attrList[50] = &RocsWgen_timerf18;
  attrList[51] = &RocsWgen_timerf19;
  attrList[52] = &RocsWgen_timerf2;
  attrList[53] = &RocsWgen_timerf20;
  attrList[54] = &RocsWgen_timerf21;
  attrList[55] = &RocsWgen_timerf22;
  attrList[56] = &RocsWgen_timerf23;
  attrList[57] = &RocsWgen_timerf24;
  attrList[58] = &RocsWgen_timerf25;
  attrList[59] = &RocsWgen_timerf26;
  attrList[60] = &RocsWgen_timerf27;
  attrList[61] = &RocsWgen_timerf28;
  attrList[62] = &RocsWgen_timerf3;
  attrList[63] = &RocsWgen_timerf4;
  attrList[64] = &RocsWgen_timerf5;
  attrList[65] = &RocsWgen_timerf6;
  attrList[66] = &RocsWgen_timerf7;
  attrList[67] = &RocsWgen_timerf8;
  attrList[68] = &RocsWgen_timerf9;
  attrList[69] = NULL;
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


struct __wFunCmd wFunCmd = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getaddr,
  _setaddr,
  _getbus,
  _setbus,
  _getevent,
  _setevent,
  _geteventblock,
  _seteventblock,
  _isf0,
  _setf0,
  _isf1,
  _setf1,
  _isf10,
  _setf10,
  _isf11,
  _setf11,
  _isf12,
  _setf12,
  _isf13,
  _setf13,
  _isf14,
  _setf14,
  _isf15,
  _setf15,
  _isf16,
  _setf16,
  _isf17,
  _setf17,
  _isf18,
  _setf18,
  _isf19,
  _setf19,
  _isf2,
  _setf2,
  _isf20,
  _setf20,
  _isf21,
  _setf21,
  _isf22,
  _setf22,
  _isf23,
  _setf23,
  _isf24,
  _setf24,
  _isf25,
  _setf25,
  _isf26,
  _setf26,
  _isf27,
  _setf27,
  _isf28,
  _setf28,
  _isf3,
  _setf3,
  _isf4,
  _setf4,
  _isf5,
  _setf5,
  _isf6,
  _setf6,
  _isf7,
  _setf7,
  _isf8,
  _setf8,
  _isf9,
  _setf9,
  _getfnchanged,
  _setfnchanged,
  _isfnchangedstate,
  _setfnchangedstate,
  _getfncnt,
  _setfncnt,
  _getgroup,
  _setgroup,
  _getid,
  _setid,
  _gettimedfn,
  _settimedfn,
  _gettimer,
  _settimer,
  _gettimerf0,
  _settimerf0,
  _gettimerf1,
  _settimerf1,
  _gettimerf10,
  _settimerf10,
  _gettimerf11,
  _settimerf11,
  _gettimerf12,
  _settimerf12,
  _gettimerf13,
  _settimerf13,
  _gettimerf14,
  _settimerf14,
  _gettimerf15,
  _settimerf15,
  _gettimerf16,
  _settimerf16,
  _gettimerf17,
  _settimerf17,
  _gettimerf18,
  _settimerf18,
  _gettimerf19,
  _settimerf19,
  _gettimerf2,
  _settimerf2,
  _gettimerf20,
  _settimerf20,
  _gettimerf21,
  _settimerf21,
  _gettimerf22,
  _settimerf22,
  _gettimerf23,
  _settimerf23,
  _gettimerf24,
  _settimerf24,
  _gettimerf25,
  _settimerf25,
  _gettimerf26,
  _settimerf26,
  _gettimerf27,
  _settimerf27,
  _gettimerf28,
  _settimerf28,
  _gettimerf3,
  _settimerf3,
  _gettimerf4,
  _settimerf4,
  _gettimerf5,
  _settimerf5,
  _gettimerf6,
  _settimerf6,
  _gettimerf7,
  _settimerf7,
  _gettimerf8,
  _settimerf8,
  _gettimerf9,
  _settimerf9,
  _node_dump,
};
