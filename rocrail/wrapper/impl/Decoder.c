/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Decoder.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Decoder
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_decoder = {
  "decoder",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_decoder.name;
}
static const char* _node_remark(void) {
  return RocsWgen_decoder.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_decoder.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_decoder.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * family
 */
static struct __nodedef RocsWgen_family = {
  "family",  "",  False,  "1",};
static iONode _getfamily(iONode node) {
  xNode( RocsWgen_decoder, node );
  return NodeOp.findNode( node, "family");
}


static iONode _nextfamily(iONode node, iONode child) {
  xNode( RocsWgen_decoder, node );
  return NodeOp.findNextNode( node, child);
}
static void _setfamily(iONode node, iONode p_family) {
  xNode( RocsWgen_decoder, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * variables
 */
static struct __nodedef RocsWgen_variables = {
  "variables",  "",  False,  "1",};
static iONode _getvariables(iONode node) {
  xNode( RocsWgen_decoder, node );
  return NodeOp.findNode( node, "variables");
}


static iONode _nextvariables(iONode node, iONode child) {
  xNode( RocsWgen_decoder, node );
  return NodeOp.findNextNode( node, child);
}
static void _setvariables(iONode node, iONode p_variables) {
  xNode( RocsWgen_decoder, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[3] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_decoder.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node decoder not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node decoder not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_family;
  nodeList[1] = &RocsWgen_variables;
  nodeList[2] = NULL;
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


struct __wDecoder wDecoder = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getfamily,
  _nextfamily,
  _setfamily,
  _getvariables,
  _nextvariables,
  _setvariables,
  _node_dump,
};
