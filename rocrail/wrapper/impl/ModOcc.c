/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/ModOcc.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.ModOcc
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_modocc = {
  "modocc",  "Root node of the block occupancy.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_modocc.name;
}
static const char* _node_remark(void) {
  return RocsWgen_modocc.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_modocc.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_modocc.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * title
 */
static struct __attrdef RocsWgen_title = {
  "title",  "Title of associated plan.",  "",  "string",  "Modular Track Layout",  "*",  False,
};
static const char* _gettitle(iONode node) {
  const char* defval = xStr( RocsWgen_title );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_modocc, node );
  return NodeOp.getStr( node, "title", defval );
}
static void _settitle(iONode node, const char* p_title) {
  if( node == NULL ) return;
  xNode( RocsWgen_modocc, node );
  NodeOp.setStr( node, "title", p_title );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * occ
 */
static struct __nodedef RocsWgen_occ = {
  "occ",  "Occupancy entry",  False,  "n",};
static iONode _getocc(iONode node) {
  xNode( RocsWgen_modocc, node );
  return NodeOp.findNode( node, "occ");
}


static iONode _nextocc(iONode node, iONode child) {
  xNode( RocsWgen_modocc, node );
  return NodeOp.findNextNode( node, child);
}
static void _setocc(iONode node, iONode p_occ) {
  xNode( RocsWgen_modocc, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[2] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_modocc.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node modocc not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node modocc not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_title;
  attrList[1] = NULL;
  nodeList[0] = &RocsWgen_occ;
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


struct __wModOcc wModOcc = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _gettitle,
  _settitle,
  _getocc,
  _nextocc,
  _setocc,
  _node_dump,
};
