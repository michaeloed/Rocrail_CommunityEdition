/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/SBT.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.SBT
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_sbt = {
  "sbt",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_sbt.name;
}
static const char* _node_remark(void) {
  return RocsWgen_sbt.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_sbt.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_sbt.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bk
 */
static struct __attrdef RocsWgen_bk = {
  "bk",  "Block ID.",  "",  "string",  "",  "*",  False,
};
static const char* _getbk(iONode node) {
  const char* defval = xStr( RocsWgen_bk );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sbt, node );
  return NodeOp.getStr( node, "bk", defval );
}
static void _setbk(iONode node, const char* p_bk) {
  if( node == NULL ) return;
  xNode( RocsWgen_sbt, node );
  NodeOp.setStr( node, "bk", p_bk );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * decelerate
 */
static struct __attrdef RocsWgen_decelerate = {
  "decelerate",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getdecelerate(iONode node) {
  int defval = xInt( RocsWgen_decelerate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sbt, node );
  return NodeOp.getInt( node, "decelerate", defval );
}
static void _setdecelerate(iONode node, int p_decelerate) {
  if( node == NULL ) return;
  xNode( RocsWgen_sbt, node );
  NodeOp.setInt( node, "decelerate", p_decelerate );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * interval
 */
static struct __attrdef RocsWgen_interval = {
  "interval",  "Brake interval.",  "100ms",  "int",  "1",  "1-*",  False,
};
static int _getinterval(iONode node) {
  int defval = xInt( RocsWgen_interval );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sbt, node );
  return NodeOp.getInt( node, "interval", defval );
}
static void _setinterval(iONode node, int p_interval) {
  if( node == NULL ) return;
  xNode( RocsWgen_sbt, node );
  NodeOp.setInt( node, "interval", p_interval );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * train
 */
static struct __attrdef RocsWgen_train = {
  "train",  "Train ID.",  "",  "string",  "",  "*",  False,
};
static const char* _gettrain(iONode node) {
  const char* defval = xStr( RocsWgen_train );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sbt, node );
  return NodeOp.getStr( node, "train", defval );
}
static void _settrain(iONode node, const char* p_train) {
  if( node == NULL ) return;
  xNode( RocsWgen_sbt, node );
  NodeOp.setStr( node, "train", p_train );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[5] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_sbt.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node sbt not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node sbt not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_bk;
  attrList[1] = &RocsWgen_decelerate;
  attrList[2] = &RocsWgen_interval;
  attrList[3] = &RocsWgen_train;
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


struct __wSBT wSBT = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getbk,
  _setbk,
  _getdecelerate,
  _setdecelerate,
  _getinterval,
  _setinterval,
  _gettrain,
  _settrain,
  _node_dump,
};
