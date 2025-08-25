/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/CBusNodeVar.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.CBusNodeVar
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_cbnodevar = {
  "cbnodevar",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_cbnodevar.name;
}
static const char* _node_remark(void) {
  return RocsWgen_cbnodevar.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_cbnodevar.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_cbnodevar.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nr
 */
static struct __attrdef RocsWgen_nr = {
  "nr",  "Node variable index.",  "",  "int",  "1",  "1-255",  False,
};
static int _getnr(iONode node) {
  int defval = xInt( RocsWgen_nr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbnodevar, node );
  return NodeOp.getInt( node, "nr", defval );
}
static void _setnr(iONode node, int p_nr) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbnodevar, node );
  NodeOp.setInt( node, "nr", p_nr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val
 */
static struct __attrdef RocsWgen_val = {
  "val",  "Node variable value.",  "",  "int",  "0",  "0-255",  False,
};
static int _getval(iONode node) {
  int defval = xInt( RocsWgen_val );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbnodevar, node );
  return NodeOp.getInt( node, "val", defval );
}
static void _setval(iONode node, int p_val) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbnodevar, node );
  NodeOp.setInt( node, "val", p_val );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[3] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_cbnodevar.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node cbnodevar not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node cbnodevar not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_nr;
  attrList[1] = &RocsWgen_val;
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


struct __wCBusNodeVar wCBusNodeVar = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getnr,
  _setnr,
  _getval,
  _setval,
  _node_dump,
};
