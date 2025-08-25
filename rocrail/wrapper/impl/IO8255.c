/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/IO8255.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.IO8255
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_io8255 = {
  "io8255",  "IO8255 options",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_io8255.name;
}
static const char* _node_remark(void) {
  return RocsWgen_io8255.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_io8255.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_io8255.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * io
 */
static struct __attrdef RocsWgen_io = {
  "io",  "A high bit means input port type.",  "",  "int",  "0",  "0-16777215",  False,
};
static int _getio(iONode node) {
  int defval = xInt( RocsWgen_io );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_io8255, node );
  return NodeOp.getInt( node, "io", defval );
}
static void _setio(iONode node, int p_io) {
  if( node == NULL ) return;
  xNode( RocsWgen_io8255, node );
  NodeOp.setInt( node, "io", p_io );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * portoffset
 */
static struct __attrdef RocsWgen_portoffset = {
  "portoffset",  "0x100 is the first board.",  "",  "int",  "256",  "*",  False,
};
static int _getportoffset(iONode node) {
  int defval = xInt( RocsWgen_portoffset );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_io8255, node );
  return NodeOp.getInt( node, "portoffset", defval );
}
static void _setportoffset(iONode node, int p_portoffset) {
  if( node == NULL ) return;
  xNode( RocsWgen_io8255, node );
  NodeOp.setInt( node, "portoffset", p_portoffset );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[3] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_io8255.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node io8255 not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node io8255 not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_io;
  attrList[1] = &RocsWgen_portoffset;
  attrList[2] = NULL;
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


struct __wIO8255 wIO8255 = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getio,
  _setio,
  _getportoffset,
  _setportoffset,
  _node_dump,
};
