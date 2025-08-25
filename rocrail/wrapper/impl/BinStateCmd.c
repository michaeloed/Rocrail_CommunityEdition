/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/BinStateCmd.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.BinStateCmd
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_binstate = {
  "binstate",  "Binary state command",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_binstate.name;
}
static const char* _node_remark(void) {
  return RocsWgen_binstate.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_binstate.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_binstate.cardinality;
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
  xNode( RocsWgen_binstate, node );
  return NodeOp.getInt( node, "addr", defval );
}
static void _setaddr(iONode node, int p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_binstate, node );
  NodeOp.setInt( node, "addr", p_addr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bus
 */
static struct __attrdef RocsWgen_bus = {
  "bus",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getbus(iONode node) {
  int defval = xInt( RocsWgen_bus );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_binstate, node );
  return NodeOp.getInt( node, "bus", defval );
}
static void _setbus(iONode node, int p_bus) {
  if( node == NULL ) return;
  xNode( RocsWgen_binstate, node );
  NodeOp.setInt( node, "bus", p_bus );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * data
 */
static struct __attrdef RocsWgen_data = {
  "data",  "state data",  "",  "int",  "0-1",  "",  False,
};
static int _getdata(iONode node) {
  int defval = xInt( RocsWgen_data );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_binstate, node );
  return NodeOp.getInt( node, "data", defval );
}
static void _setdata(iONode node, int p_data) {
  if( node == NULL ) return;
  xNode( RocsWgen_binstate, node );
  NodeOp.setInt( node, "data", p_data );
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
  xNode( RocsWgen_binstate, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_binstate, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nr
 */
static struct __attrdef RocsWgen_nr = {
  "nr",  "state number",  "",  "int",  "0-*",  "",  False,
};
static int _getnr(iONode node) {
  int defval = xInt( RocsWgen_nr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_binstate, node );
  return NodeOp.getInt( node, "nr", defval );
}
static void _setnr(iONode node, int p_nr) {
  if( node == NULL ) return;
  xNode( RocsWgen_binstate, node );
  NodeOp.setInt( node, "nr", p_nr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timer
 */
static struct __attrdef RocsWgen_timer = {
  "timer",  "timer to reset state",  "",  "int",  "0-*",  "",  False,
};
static int _gettimer(iONode node) {
  int defval = xInt( RocsWgen_timer );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_binstate, node );
  return NodeOp.getInt( node, "timer", defval );
}
static void _settimer(iONode node, int p_timer) {
  if( node == NULL ) return;
  xNode( RocsWgen_binstate, node );
  NodeOp.setInt( node, "timer", p_timer );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[7] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_binstate.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node binstate not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node binstate not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_addr;
  attrList[1] = &RocsWgen_bus;
  attrList[2] = &RocsWgen_data;
  attrList[3] = &RocsWgen_id;
  attrList[4] = &RocsWgen_nr;
  attrList[5] = &RocsWgen_timer;
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


struct __wBinStateCmd wBinStateCmd = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getaddr,
  _setaddr,
  _getbus,
  _setbus,
  _getdata,
  _setdata,
  _getid,
  _setid,
  _getnr,
  _setnr,
  _gettimer,
  _settimer,
  _node_dump,
};
