/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/DecVariables.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.DecVariables
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_variables = {
  "variables",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_variables.name;
}
static const char* _node_remark(void) {
  return RocsWgen_variables.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_variables.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_variables.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * variable
 */
static struct __nodedef RocsWgen_variable = {
  "variable",  "",  False,  "n",};
static iONode _getvariable(iONode node) {
  xNode( RocsWgen_variables, node );
  return NodeOp.findNode( node, "variable");
}


static iONode _nextvariable(iONode node, iONode child) {
  xNode( RocsWgen_variables, node );
  return NodeOp.findNextNode( node, child);
}
static void _setvariable(iONode node, iONode p_variable) {
  xNode( RocsWgen_variables, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_variables.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node variables not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node variables not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_variable;
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


struct __wDecVariables wDecVariables = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getvariable,
  _nextvariable,
  _setvariable,
  _node_dump,
};
