/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/LinkCond.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.LinkCond
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_linkcond = {
  "linkcond",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_linkcond.name;
}
static const char* _node_remark(void) {
  return RocsWgen_linkcond.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_linkcond.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_linkcond.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * first
 */
static struct __attrdef RocsWgen_first = {
  "first",  "First lock block.",  "",  "string",  "",  "*",  False,
};
static const char* _getfirst(iONode node) {
  const char* defval = xStr( RocsWgen_first );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_linkcond, node );
  return NodeOp.getStr( node, "first", defval );
}
static void _setfirst(iONode node, const char* p_first) {
  if( node == NULL ) return;
  xNode( RocsWgen_linkcond, node );
  NodeOp.setStr( node, "first", p_first );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * free
 */
static struct __attrdef RocsWgen_free = {
  "free",  "One of this blocks must be free. (csv)",  "",  "string",  "",  "*",  False,
};
static const char* _getfree(iONode node) {
  const char* defval = xStr( RocsWgen_free );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_linkcond, node );
  return NodeOp.getStr( node, "free", defval );
}
static void _setfree(iONode node, const char* p_free) {
  if( node == NULL ) return;
  xNode( RocsWgen_linkcond, node );
  NodeOp.setStr( node, "free", p_free );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[3] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_linkcond.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node linkcond not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node linkcond not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_first;
  attrList[1] = &RocsWgen_free;
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


struct __wLinkCond wLinkCond = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getfirst,
  _setfirst,
  _getfree,
  _setfree,
  _node_dump,
};
