/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/SvnLog.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.SvnLog
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_log = {
  "log",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_log.name;
}
static const char* _node_remark(void) {
  return RocsWgen_log.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_log.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_log.cardinality;
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * logentry
 */
static struct __nodedef RocsWgen_logentry = {
  "logentry",  "",  False,  "1",};
static iONode _getlogentry(iONode node) {
  xNode( RocsWgen_log, node );
  return NodeOp.findNode( node, "logentry");
}


static iONode _nextlogentry(iONode node, iONode child) {
  xNode( RocsWgen_log, node );
  return NodeOp.findNextNode( node, child);
}
static void _setlogentry(iONode node, iONode p_logentry) {
  xNode( RocsWgen_log, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[1] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_log.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node log not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node log not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = NULL;
  nodeList[0] = &RocsWgen_logentry;
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


struct __wSvnLog wSvnLog = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getlogentry,
  _nextlogentry,
  _setlogentry,
  _node_dump,
};
