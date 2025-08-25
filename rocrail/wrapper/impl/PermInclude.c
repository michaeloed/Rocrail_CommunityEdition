/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/PermInclude.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.PermInclude
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_incl = {
  "incl",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_incl.name;
}
static const char* _node_remark(void) {
  return RocsWgen_incl.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_incl.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_incl.cardinality;
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
  xNode( RocsWgen_incl, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_incl, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * randomrate
 */
static struct __attrdef RocsWgen_randomrate = {
  "randomrate",  "Rate of randomness. 0=Not used",  "",  "int",  "0",  "0-*",  False,
};
static int _getrandomrate(iONode node) {
  int defval = xInt( RocsWgen_randomrate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_incl, node );
  return NodeOp.getInt( node, "randomrate", defval );
}
static void _setrandomrate(iONode node, int p_randomrate) {
  if( node == NULL ) return;
  xNode( RocsWgen_incl, node );
  NodeOp.setInt( node, "randomrate", p_randomrate );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[3] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_incl.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node incl not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node incl not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_id;
  attrList[1] = &RocsWgen_randomrate;
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


struct __wPermInclude wPermInclude = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getid,
  _setid,
  _getrandomrate,
  _setrandomrate,
  _node_dump,
};
