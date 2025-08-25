/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/DecFamily.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.DecFamily
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_family = {
  "family",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_family.name;
}
static const char* _node_remark(void) {
  return RocsWgen_family.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_family.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_family.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mfg
 */
static struct __attrdef RocsWgen_mfg = {
  "mfg",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getmfg(iONode node) {
  const char* defval = xStr( RocsWgen_mfg );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_family, node );
  return NodeOp.getStr( node, "mfg", defval );
}
static void _setmfg(iONode node, const char* p_mfg) {
  if( node == NULL ) return;
  xNode( RocsWgen_family, node );
  NodeOp.setStr( node, "mfg", p_mfg );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * name
 */
static struct __attrdef RocsWgen_name = {
  "name",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getname(iONode node) {
  const char* defval = xStr( RocsWgen_name );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_family, node );
  return NodeOp.getStr( node, "name", defval );
}
static void _setname(iONode node, const char* p_name) {
  if( node == NULL ) return;
  xNode( RocsWgen_family, node );
  NodeOp.setStr( node, "name", p_name );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[3] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_family.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node family not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node family not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_mfg;
  attrList[1] = &RocsWgen_name;
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


struct __wDecFamily wDecFamily = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getmfg,
  _setmfg,
  _getname,
  _setname,
  _node_dump,
};
