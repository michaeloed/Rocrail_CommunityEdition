/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/ExtCmd.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.ExtCmd
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_ext = {
  "ext",  "External command.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_ext.name;
}
static const char* _node_remark(void) {
  return RocsWgen_ext.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_ext.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_ext.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmdline
 */
static struct __attrdef RocsWgen_cmdline = {
  "cmdline",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getcmdline(iONode node) {
  const char* defval = xStr( RocsWgen_cmdline );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ext, node );
  return NodeOp.getStr( node, "cmdline", defval );
}
static void _setcmdline(iONode node, const char* p_cmdline) {
  if( node == NULL ) return;
  xNode( RocsWgen_ext, node );
  NodeOp.setStr( node, "cmdline", p_cmdline );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[2] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_ext.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node ext not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node ext not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_cmdline;
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


struct __wExtCmd wExtCmd = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getcmdline,
  _setcmdline,
  _node_dump,
};
