/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/CBusNodeEvent.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.CBusNodeEvent
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_cbnodeevent = {
  "cbnodeevent",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_cbnodeevent.name;
}
static const char* _node_remark(void) {
  return RocsWgen_cbnodeevent.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_cbnodeevent.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_cbnodeevent.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr
 */
static struct __attrdef RocsWgen_addr = {
  "addr",  "Device address of producer.",  "",  "int",  "0",  "1-65535",  False,
};
static int _getaddr(iONode node) {
  int defval = xInt( RocsWgen_addr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbnodeevent, node );
  return NodeOp.getInt( node, "addr", defval );
}
static void _setaddr(iONode node, int p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbnodeevent, node );
  NodeOp.setInt( node, "addr", p_addr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * evnr
 */
static struct __attrdef RocsWgen_evnr = {
  "evnr",  "Event variable index.",  "",  "int",  "0",  "1-255",  False,
};
static int _getevnr(iONode node) {
  int defval = xInt( RocsWgen_evnr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbnodeevent, node );
  return NodeOp.getInt( node, "evnr", defval );
}
static void _setevnr(iONode node, int p_evnr) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbnodeevent, node );
  NodeOp.setInt( node, "evnr", p_evnr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * evval
 */
static struct __attrdef RocsWgen_evval = {
  "evval",  "Event variable value.",  "",  "int",  "0",  "0-255",  False,
};
static int _getevval(iONode node) {
  int defval = xInt( RocsWgen_evval );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbnodeevent, node );
  return NodeOp.getInt( node, "evval", defval );
}
static void _setevval(iONode node, int p_evval) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbnodeevent, node );
  NodeOp.setInt( node, "evval", p_evval );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nodenr
 */
static struct __attrdef RocsWgen_nodenr = {
  "nodenr",  "Node number of producer.",  "",  "int",  "0",  "1-65535",  False,
};
static int _getnodenr(iONode node) {
  int defval = xInt( RocsWgen_nodenr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbnodeevent, node );
  return NodeOp.getInt( node, "nodenr", defval );
}
static void _setnodenr(iONode node, int p_nodenr) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbnodeevent, node );
  NodeOp.setInt( node, "nodenr", p_nodenr );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[5] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_cbnodeevent.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node cbnodeevent not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node cbnodeevent not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_addr;
  attrList[1] = &RocsWgen_evnr;
  attrList[2] = &RocsWgen_evval;
  attrList[3] = &RocsWgen_nodenr;
  attrList[4] = NULL;
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


struct __wCBusNodeEvent wCBusNodeEvent = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getaddr,
  _setaddr,
  _getevnr,
  _setevnr,
  _getevval,
  _setevval,
  _getnodenr,
  _setnodenr,
  _node_dump,
};
