/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Cmdline.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Cmdline
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_Cmdline = {
  "Cmdline",  "Commands are listed in column --Default--.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_Cmdline.name;
}
static const char* _node_remark(void) {
  return RocsWgen_Cmdline.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_Cmdline.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_Cmdline.cardinality;
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_Cmdline.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node Cmdline not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node Cmdline not found!" );
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


struct __wCmdline wCmdline = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "-auto",
  "-byte",
  "-console",
  "-debug",
  "-deleteservice",
  "-doc",
  "--help",
  "-http",
  "-img",
  "-info",
  "-i",
  "-f",
  "-installservice",
  "-lcd",
  "-l",
  "-lf",
  "-modplan",
  "-monitor",
  "-nocom",
  "-nodevcheck",
  "-parse",
  "-x",
  "-p",
  "-resume",
  "-run",
  "-service",
  "-stress",
  "-t",
  "-version",
  "-w",
  _node_dump,
};
