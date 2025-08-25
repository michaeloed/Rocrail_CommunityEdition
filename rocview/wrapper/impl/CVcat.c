/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#include "rocview/wrapper/public/CVcat.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.CVcat
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_cvcat = {
  "cvcat",  "CV category definition",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_cvcat.name;
}
static const char* _node_remark(void) {
  return RocsWgen_cvcat.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_cvcat.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_cvcat.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * name
 */
static struct __attrdef RocsWgen_name = {
  "name",  "category name",  "",  "string",  "",  "*",  False,
};
static const char* _getname(iONode node) {
  const char* defval = xStr( RocsWgen_name );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cvcat, node );
  return NodeOp.getStr( node, "name", defval );
}
static void _setname(iONode node, const char* p_name) {
  if( node == NULL ) return;
  xNode( RocsWgen_cvcat, node );
  NodeOp.setStr( node, "name", p_name );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nrs
 */
static struct __attrdef RocsWgen_nrs = {
  "nrs",  "csv list of CV numbers belonging to this category",  "",  "string",  "",  "*",  False,
};
static const char* _getnrs(iONode node) {
  const char* defval = xStr( RocsWgen_nrs );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cvcat, node );
  return NodeOp.getStr( node, "nrs", defval );
}
static void _setnrs(iONode node, const char* p_nrs) {
  if( node == NULL ) return;
  xNode( RocsWgen_cvcat, node );
  NodeOp.setStr( node, "nrs", p_nrs );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[3] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_cvcat.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node cvcat not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node cvcat not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_name;
  attrList[1] = &RocsWgen_nrs;
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


struct __wCVcat wCVcat = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getname,
  _setname,
  _getnrs,
  _setnrs,
  _node_dump,
};
