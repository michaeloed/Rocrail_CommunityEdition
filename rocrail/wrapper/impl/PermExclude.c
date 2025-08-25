/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/PermExclude.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.PermExclude
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_excl = {
  "excl",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_excl.name;
}
static const char* _node_remark(void) {
  return RocsWgen_excl.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_excl.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_excl.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "Loc ID.",  "",  "string",  "",  "*",  True,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_excl, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_excl, node );
  NodeOp.setStr( node, "id", p_id );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[2] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_excl.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node excl not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node excl not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_id;
  attrList[1] = NULL;
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


struct __wPermExclude wPermExclude = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getid,
  _setid,
  _node_dump,
};
