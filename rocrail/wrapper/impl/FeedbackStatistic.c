/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/FeedbackStatistic.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.FeedbackStatistic
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_fbstatistic = {
  "fbstatistic",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_fbstatistic.name;
}
static const char* _node_remark(void) {
  return RocsWgen_fbstatistic.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_fbstatistic.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_fbstatistic.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lcid
 */
static struct __attrdef RocsWgen_lcid = {
  "lcid",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getlcid(iONode node) {
  const char* defval = xStr( RocsWgen_lcid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fbstatistic, node );
  return NodeOp.getStr( node, "lcid", defval );
}
static void _setlcid(iONode node, const char* p_lcid) {
  if( node == NULL ) return;
  xNode( RocsWgen_fbstatistic, node );
  NodeOp.setStr( node, "lcid", p_lcid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * quality
 */
static struct __attrdef RocsWgen_quality = {
  "quality",  "Signal quality reported by loco over railcom.",  "",  "int",  "0",  "0-*",  False,
};
static int _getquality(iONode node) {
  int defval = xInt( RocsWgen_quality );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fbstatistic, node );
  return NodeOp.getInt( node, "quality", defval );
}
static void _setquality(iONode node, int p_quality) {
  if( node == NULL ) return;
  xNode( RocsWgen_fbstatistic, node );
  NodeOp.setInt( node, "quality", p_quality );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[3] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_fbstatistic.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node fbstatistic not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node fbstatistic not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_lcid;
  attrList[1] = &RocsWgen_quality;
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


struct __wFeedbackStatistic wFeedbackStatistic = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getlcid,
  _setlcid,
  _getquality,
  _setquality,
  _node_dump,
};
