/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/SvnLogEntry.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.SvnLogEntry
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_logentry = {
  "logentry",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_logentry.name;
}
static const char* _node_remark(void) {
  return RocsWgen_logentry.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_logentry.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_logentry.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * revision
 */
static struct __attrdef RocsWgen_revision = {
  "revision",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getrevision(iONode node) {
  int defval = xInt( RocsWgen_revision );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_logentry, node );
  return NodeOp.getInt( node, "revision", defval );
}
static void _setrevision(iONode node, int p_revision) {
  if( node == NULL ) return;
  xNode( RocsWgen_logentry, node );
  NodeOp.setInt( node, "revision", p_revision );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[2] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_logentry.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node logentry not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node logentry not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_revision;
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


struct __wSvnLogEntry wSvnLogEntry = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getrevision,
  _setrevision,
  _node_dump,
};
