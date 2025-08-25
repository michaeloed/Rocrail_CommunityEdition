/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/ConCmd.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.ConCmd
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_ConCmd = {
  "ConCmd",  "Commands are listed in column --Default--.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_ConCmd.name;
}
static const char* _node_remark(void) {
  return RocsWgen_ConCmd.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_ConCmd.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_ConCmd.cardinality;
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_ConCmd.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node ConCmd not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node ConCmd not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
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


struct __wConCmd wConCmd = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  'z',
  'l',
  'a',
  'b',
  'c',
  'd',
  'e',
  '?',
  'h',
  'n',
  'i',
  'm',
  'r',
  'o',
  'y',
  'p',
  '5',
  'q',
  'x',
  '8',
  's',
  't',
  _node_dump,
};
