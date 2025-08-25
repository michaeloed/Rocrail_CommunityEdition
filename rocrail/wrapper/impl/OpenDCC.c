/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/OpenDCC.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.OpenDCC
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_opendcc = {
  "opendcc",  "OpenDCC options",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_opendcc.name;
}
static const char* _node_remark(void) {
  return RocsWgen_opendcc.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_opendcc.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_opendcc.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bidi
 */
static struct __attrdef RocsWgen_bidi = {
  "bidi",  "Activate BiDi support.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isbidi(iONode node) {
  Boolean defval = xBool( RocsWgen_bidi );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_opendcc, node );
  return NodeOp.getBool( node, "bidi", defval );
}
static void _setbidi(iONode node, Boolean p_bidi) {
  if( node == NULL ) return;
  xNode( RocsWgen_opendcc, node );
  NodeOp.setBool( node, "bidi", p_bidi );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fastclock
 */
static struct __attrdef RocsWgen_fastclock = {
  "fastclock",  "Fast clock flag read from SO 2.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isfastclock(iONode node) {
  Boolean defval = xBool( RocsWgen_fastclock );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_opendcc, node );
  return NodeOp.getBool( node, "fastclock", defval );
}
static void _setfastclock(iONode node, Boolean p_fastclock) {
  if( node == NULL ) return;
  xNode( RocsWgen_opendcc, node );
  NodeOp.setBool( node, "fastclock", p_fastclock );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lib
 */
static struct __attrdef RocsWgen_lib = {
  "lib",  "",  "",  "string",  "p50x",  "",  False,
};
static const char* _getlib(iONode node) {
  const char* defval = xStr( RocsWgen_lib );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_opendcc, node );
  return NodeOp.getStr( node, "lib", defval );
}
static void _setlib(iONode node, const char* p_lib) {
  if( node == NULL ) return;
  xNode( RocsWgen_opendcc, node );
  NodeOp.setStr( node, "lib", p_lib );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * loccnfg
 */
static struct __attrdef RocsWgen_loccnfg = {
  "loccnfg",  "send loco config commands",  "",  "bool",  "false",  "",  False,
};
static Boolean _isloccnfg(iONode node) {
  Boolean defval = xBool( RocsWgen_loccnfg );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_opendcc, node );
  return NodeOp.getBool( node, "loccnfg", defval );
}
static void _setloccnfg(iONode node, Boolean p_loccnfg) {
  if( node == NULL ) return;
  xNode( RocsWgen_opendcc, node );
  NodeOp.setBool( node, "loccnfg", p_loccnfg );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[5] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_opendcc.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node opendcc not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node opendcc not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_bidi;
  attrList[1] = &RocsWgen_fastclock;
  attrList[2] = &RocsWgen_lib;
  attrList[3] = &RocsWgen_loccnfg;
  attrList[4] = NULL;
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


struct __wOpenDCC wOpenDCC = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isbidi,
  _setbidi,
  _isfastclock,
  _setfastclock,
  _getlib,
  _setlib,
  _isloccnfg,
  _setloccnfg,
  _node_dump,
};
