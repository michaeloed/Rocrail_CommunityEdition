/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#include "rocview/wrapper/public/ColPos.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.ColPos
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_colpos = {
  "colpos",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_colpos.name;
}
static const char* _node_remark(void) {
  return RocsWgen_colpos.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_colpos.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_colpos.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "",  "",  "int",  "0",  "",  False,
};
static int _getid(iONode node) {
  int defval = xInt( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_colpos, node );
  return NodeOp.getInt( node, "id", defval );
}
static void _setid(iONode node, int p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_colpos, node );
  NodeOp.setInt( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * pos
 */
static struct __attrdef RocsWgen_pos = {
  "pos",  "",  "",  "int",  "0",  "",  False,
};
static int _getpos(iONode node) {
  int defval = xInt( RocsWgen_pos );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_colpos, node );
  return NodeOp.getInt( node, "pos", defval );
}
static void _setpos(iONode node, int p_pos) {
  if( node == NULL ) return;
  xNode( RocsWgen_colpos, node );
  NodeOp.setInt( node, "pos", p_pos );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[3] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_colpos.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node colpos not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node colpos not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_id;
  attrList[1] = &RocsWgen_pos;
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


struct __wColPos wColPos = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getid,
  _setid,
  _getpos,
  _setpos,
  _node_dump,
};
