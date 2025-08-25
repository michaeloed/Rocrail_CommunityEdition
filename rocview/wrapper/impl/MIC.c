/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#include "rocview/wrapper/public/MIC.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.MIC
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_mic = {
  "mic",  "Mouse Integrated Controller",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_mic.name;
}
static const char* _node_remark(void) {
  return RocsWgen_mic.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_mic.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_mic.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * exitstop
 */
static struct __attrdef RocsWgen_exitstop = {
  "exitstop",  "stops train after exit MIC mode",  "",  "bool",  "true",  "",  False,
};
static Boolean _isexitstop(iONode node) {
  Boolean defval = xBool( RocsWgen_exitstop );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mic, node );
  return NodeOp.getBool( node, "exitstop", defval );
}
static void _setexitstop(iONode node, Boolean p_exitstop) {
  if( node == NULL ) return;
  xNode( RocsWgen_mic, node );
  NodeOp.setBool( node, "exitstop", p_exitstop );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * step
 */
static struct __attrdef RocsWgen_step = {
  "step",  "speed step per mousewheel notch",  "",  "int",  "1",  "1-9",  False,
};
static int _getstep(iONode node) {
  int defval = xInt( RocsWgen_step );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_mic, node );
  return NodeOp.getInt( node, "step", defval );
}
static void _setstep(iONode node, int p_step) {
  if( node == NULL ) return;
  xNode( RocsWgen_mic, node );
  NodeOp.setInt( node, "step", p_step );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[3] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_mic.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node mic not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node mic not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_exitstop;
  attrList[1] = &RocsWgen_step;
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


struct __wMIC wMIC = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isexitstop,
  _setexitstop,
  _getstep,
  _setstep,
  _node_dump,
};
