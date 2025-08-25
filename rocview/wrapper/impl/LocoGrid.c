/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#include "rocview/wrapper/public/LocoGrid.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.LocoGrid
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_locogrid = {
  "locogrid",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_locogrid.name;
}
static const char* _node_remark(void) {
  return RocsWgen_locogrid.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_locogrid.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_locogrid.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sortcol
 */
static struct __attrdef RocsWgen_sortcol = {
  "sortcol",  "",  "",  "int",  "0",  "",  False,
};
static int _getsortcol(iONode node) {
  int defval = xInt( RocsWgen_sortcol );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_locogrid, node );
  return NodeOp.getInt( node, "sortcol", defval );
}
static void _setsortcol(iONode node, int p_sortcol) {
  if( node == NULL ) return;
  xNode( RocsWgen_locogrid, node );
  NodeOp.setInt( node, "sortcol", p_sortcol );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sortinv
 */
static struct __attrdef RocsWgen_sortinv = {
  "sortinv",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _issortinv(iONode node) {
  Boolean defval = xBool( RocsWgen_sortinv );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_locogrid, node );
  return NodeOp.getBool( node, "sortinv", defval );
}
static void _setsortinv(iONode node, Boolean p_sortinv) {
  if( node == NULL ) return;
  xNode( RocsWgen_locogrid, node );
  NodeOp.setBool( node, "sortinv", p_sortinv );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * colpos
 */
static struct __nodedef RocsWgen_colpos = {
  "colpos",  "",  False,  "1",};
static iONode _getcolpos(iONode node) {
  xNode( RocsWgen_locogrid, node );
  return NodeOp.findNode( node, "colpos");
}


static iONode _nextcolpos(iONode node, iONode child) {
  xNode( RocsWgen_locogrid, node );
  return NodeOp.findNextNode( node, child);
}
static void _setcolpos(iONode node, iONode p_colpos) {
  xNode( RocsWgen_locogrid, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[3] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_locogrid.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node locogrid not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node locogrid not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_sortcol;
  attrList[1] = &RocsWgen_sortinv;
  attrList[2] = NULL;
  nodeList[0] = &RocsWgen_colpos;
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


struct __wLocoGrid wLocoGrid = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getsortcol,
  _setsortcol,
  _issortinv,
  _setsortinv,
  _getcolpos,
  _nextcolpos,
  _setcolpos,
  _node_dump,
};
