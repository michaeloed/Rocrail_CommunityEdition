/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/DIP.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.DIP
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_adip = {
  "adip",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_adip.name;
}
static const char* _node_remark(void) {
  return RocsWgen_adip.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_adip.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_adip.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_adip, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_adip, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * title
 */
static struct __attrdef RocsWgen_title = {
  "title",  "",  "",  "string",  "Dinamic Input Panel",  "*",  False,
};
static const char* _gettitle(iONode node) {
  const char* defval = xStr( RocsWgen_title );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_adip, node );
  return NodeOp.getStr( node, "title", defval );
}
static void _settitle(iONode node, const char* p_title) {
  if( node == NULL ) return;
  xNode( RocsWgen_adip, node );
  NodeOp.setStr( node, "title", p_title );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * dipgroup
 */
static struct __nodedef RocsWgen_dipgroup = {
  "dipgroup",  "",  False,  "n",};
static iONode _getdipgroup(iONode node) {
  xNode( RocsWgen_adip, node );
  return NodeOp.findNode( node, "dipgroup");
}


static iONode _nextdipgroup(iONode node, iONode child) {
  xNode( RocsWgen_adip, node );
  return NodeOp.findNextNode( node, child);
}
static void _setdipgroup(iONode node, iONode p_dipgroup) {
  xNode( RocsWgen_adip, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[3] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_adip.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node adip not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node adip not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_id;
  attrList[1] = &RocsWgen_title;
  attrList[2] = NULL;
  nodeList[0] = &RocsWgen_dipgroup;
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


struct __wDIP wDIP = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getid,
  _setid,
  _gettitle,
  _settitle,
  _getdipgroup,
  _nextdipgroup,
  _setdipgroup,
  _node_dump,
};
