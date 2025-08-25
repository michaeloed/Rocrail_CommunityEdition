/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:52 2018
  */

#include "rocview/wrapper/public/MGV.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.MGV
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_mgv = {
  "mgv",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_mgv.name;
}
static const char* _node_remark(void) {
  return RocsWgen_mgv.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_mgv.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_mgv.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr1
 */
static struct __attrdef RocsWgen_addr1 = {
  "addr1",  "",  "",  "int",  "0",  "",  False,
};
static int _getaddr1(iONode node) {
  int defval = xInt( RocsWgen_addr1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mgv, node );
  return NodeOp.getInt( node, "addr1", defval );
}
static void _setaddr1(iONode node, int p_addr1) {
  if( node == NULL ) return;
  xNode( RocsWgen_mgv, node );
  NodeOp.setInt( node, "addr1", p_addr1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr2
 */
static struct __attrdef RocsWgen_addr2 = {
  "addr2",  "",  "",  "int",  "0",  "",  False,
};
static int _getaddr2(iONode node) {
  int defval = xInt( RocsWgen_addr2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mgv, node );
  return NodeOp.getInt( node, "addr2", defval );
}
static void _setaddr2(iONode node, int p_addr2) {
  if( node == NULL ) return;
  xNode( RocsWgen_mgv, node );
  NodeOp.setInt( node, "addr2", p_addr2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr3
 */
static struct __attrdef RocsWgen_addr3 = {
  "addr3",  "",  "",  "int",  "0",  "",  False,
};
static int _getaddr3(iONode node) {
  int defval = xInt( RocsWgen_addr3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mgv, node );
  return NodeOp.getInt( node, "addr3", defval );
}
static void _setaddr3(iONode node, int p_addr3) {
  if( node == NULL ) return;
  xNode( RocsWgen_mgv, node );
  NodeOp.setInt( node, "addr3", p_addr3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr4
 */
static struct __attrdef RocsWgen_addr4 = {
  "addr4",  "",  "",  "int",  "0",  "",  False,
};
static int _getaddr4(iONode node) {
  int defval = xInt( RocsWgen_addr4 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mgv, node );
  return NodeOp.getInt( node, "addr4", defval );
}
static void _setaddr4(iONode node, int p_addr4) {
  if( node == NULL ) return;
  xNode( RocsWgen_mgv, node );
  NodeOp.setInt( node, "addr4", p_addr4 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bus
 */
static struct __attrdef RocsWgen_bus = {
  "bus",  "",  "",  "int",  "0",  "",  False,
};
static int _getbus(iONode node) {
  int defval = xInt( RocsWgen_bus );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mgv, node );
  return NodeOp.getInt( node, "bus", defval );
}
static void _setbus(iONode node, int p_bus) {
  if( node == NULL ) return;
  xNode( RocsWgen_mgv, node );
  NodeOp.setInt( node, "bus", p_bus );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iid
 */
static struct __attrdef RocsWgen_iid = {
  "iid",  "",  "",  "string",  "",  "",  False,
};
static const char* _getiid(iONode node) {
  const char* defval = xStr( RocsWgen_iid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mgv, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_mgv, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port1
 */
static struct __attrdef RocsWgen_port1 = {
  "port1",  "",  "",  "int",  "0",  "",  False,
};
static int _getport1(iONode node) {
  int defval = xInt( RocsWgen_port1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mgv, node );
  return NodeOp.getInt( node, "port1", defval );
}
static void _setport1(iONode node, int p_port1) {
  if( node == NULL ) return;
  xNode( RocsWgen_mgv, node );
  NodeOp.setInt( node, "port1", p_port1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port2
 */
static struct __attrdef RocsWgen_port2 = {
  "port2",  "",  "",  "int",  "0",  "",  False,
};
static int _getport2(iONode node) {
  int defval = xInt( RocsWgen_port2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mgv, node );
  return NodeOp.getInt( node, "port2", defval );
}
static void _setport2(iONode node, int p_port2) {
  if( node == NULL ) return;
  xNode( RocsWgen_mgv, node );
  NodeOp.setInt( node, "port2", p_port2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port3
 */
static struct __attrdef RocsWgen_port3 = {
  "port3",  "",  "",  "int",  "0",  "",  False,
};
static int _getport3(iONode node) {
  int defval = xInt( RocsWgen_port3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mgv, node );
  return NodeOp.getInt( node, "port3", defval );
}
static void _setport3(iONode node, int p_port3) {
  if( node == NULL ) return;
  xNode( RocsWgen_mgv, node );
  NodeOp.setInt( node, "port3", p_port3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port4
 */
static struct __attrdef RocsWgen_port4 = {
  "port4",  "",  "",  "int",  "0",  "",  False,
};
static int _getport4(iONode node) {
  int defval = xInt( RocsWgen_port4 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mgv, node );
  return NodeOp.getInt( node, "port4", defval );
}
static void _setport4(iONode node, int p_port4) {
  if( node == NULL ) return;
  xNode( RocsWgen_mgv, node );
  NodeOp.setInt( node, "port4", p_port4 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * singlegate
 */
static struct __attrdef RocsWgen_singlegate = {
  "singlegate",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _issinglegate(iONode node) {
  Boolean defval = xBool( RocsWgen_singlegate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mgv, node );
  return NodeOp.getBool( node, "singlegate", defval );
}
static void _setsinglegate(iONode node, Boolean p_singlegate) {
  if( node == NULL ) return;
  xNode( RocsWgen_mgv, node );
  NodeOp.setBool( node, "singlegate", p_singlegate );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * mgvservo
 */
static struct __nodedef RocsWgen_mgvservo = {
  "mgvservo",  "",  False,  "n",};
static iONode _getmgvservo(iONode node) {
  xNode( RocsWgen_mgv, node );
  return NodeOp.findNode( node, "mgvservo");
}


static iONode _nextmgvservo(iONode node, iONode child) {
  xNode( RocsWgen_mgv, node );
  return NodeOp.findNextNode( node, child);
}
static void _setmgvservo(iONode node, iONode p_mgvservo) {
  xNode( RocsWgen_mgv, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[12] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_mgv.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node mgv not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node mgv not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_addr1;
  attrList[1] = &RocsWgen_addr2;
  attrList[2] = &RocsWgen_addr3;
  attrList[3] = &RocsWgen_addr4;
  attrList[4] = &RocsWgen_bus;
  attrList[5] = &RocsWgen_iid;
  attrList[6] = &RocsWgen_port1;
  attrList[7] = &RocsWgen_port2;
  attrList[8] = &RocsWgen_port3;
  attrList[9] = &RocsWgen_port4;
  attrList[10] = &RocsWgen_singlegate;
  attrList[11] = NULL;
  nodeList[0] = &RocsWgen_mgvservo;
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


struct __wMGV wMGV = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getaddr1,
  _setaddr1,
  _getaddr2,
  _setaddr2,
  _getaddr3,
  _setaddr3,
  _getaddr4,
  _setaddr4,
  _getbus,
  _setbus,
  _getiid,
  _setiid,
  _getport1,
  _setport1,
  _getport2,
  _setport2,
  _getport3,
  _setport3,
  _getport4,
  _setport4,
  _issinglegate,
  _setsinglegate,
  _getmgvservo,
  _nextmgvservo,
  _setmgvservo,
  _node_dump,
};
