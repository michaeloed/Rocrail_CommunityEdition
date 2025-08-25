/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/DIPGroup.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.DIPGroup
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_dipgroup = {
  "dipgroup",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_dipgroup.name;
}
static const char* _node_remark(void) {
  return RocsWgen_dipgroup.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_dipgroup.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_dipgroup.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * caption
 */
static struct __attrdef RocsWgen_caption = {
  "caption",  "",  "",  "string",  "DIP Group",  "*",  False,
};
static const char* _getcaption(iONode node) {
  const char* defval = xStr( RocsWgen_caption );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dipgroup, node );
  return NodeOp.getStr( node, "caption", defval );
}
static void _setcaption(iONode node, const char* p_caption) {
  if( node == NULL ) return;
  xNode( RocsWgen_dipgroup, node );
  NodeOp.setStr( node, "caption", p_caption );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mask
 */
static struct __attrdef RocsWgen_mask = {
  "mask",  "",  "",  "int",  "255",  "0-255",  False,
};
static int _getmask(iONode node) {
  int defval = xInt( RocsWgen_mask );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dipgroup, node );
  return NodeOp.getInt( node, "mask", defval );
}
static void _setmask(iONode node, int p_mask) {
  if( node == NULL ) return;
  xNode( RocsWgen_dipgroup, node );
  NodeOp.setInt( node, "mask", p_mask );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ori
 */
static struct __attrdef RocsWgen_ori = {
  "ori",  "",  "",  "int",  "0",  "0,1",  False,
};
static int _getori(iONode node) {
  int defval = xInt( RocsWgen_ori );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dipgroup, node );
  return NodeOp.getInt( node, "ori", defval );
}
static void _setori(iONode node, int p_ori) {
  if( node == NULL ) return;
  xNode( RocsWgen_dipgroup, node );
  NodeOp.setInt( node, "ori", p_ori );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * spacing
 */
static struct __attrdef RocsWgen_spacing = {
  "spacing",  "",  "",  "int",  "4",  "0-*",  False,
};
static int _getspacing(iONode node) {
  int defval = xInt( RocsWgen_spacing );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dipgroup, node );
  return NodeOp.getInt( node, "spacing", defval );
}
static void _setspacing(iONode node, int p_spacing) {
  if( node == NULL ) return;
  xNode( RocsWgen_dipgroup, node );
  NodeOp.setInt( node, "spacing", p_spacing );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * type
 */
static struct __attrdef RocsWgen_type = {
  "type",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _gettype(iONode node) {
  int defval = xInt( RocsWgen_type );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dipgroup, node );
  return NodeOp.getInt( node, "type", defval );
}
static void _settype(iONode node, int p_type) {
  if( node == NULL ) return;
  xNode( RocsWgen_dipgroup, node );
  NodeOp.setInt( node, "type", p_type );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * dipvalue
 */
static struct __nodedef RocsWgen_dipvalue = {
  "dipvalue",  "",  False,  "n",};
static iONode _getdipvalue(iONode node) {
  xNode( RocsWgen_dipgroup, node );
  return NodeOp.findNode( node, "dipvalue");
}


static iONode _nextdipvalue(iONode node, iONode child) {
  xNode( RocsWgen_dipgroup, node );
  return NodeOp.findNextNode( node, child);
}
static void _setdipvalue(iONode node, iONode p_dipvalue) {
  xNode( RocsWgen_dipgroup, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[6] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_dipgroup.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node dipgroup not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node dipgroup not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_caption;
  attrList[1] = &RocsWgen_mask;
  attrList[2] = &RocsWgen_ori;
  attrList[3] = &RocsWgen_spacing;
  attrList[4] = &RocsWgen_type;
  attrList[5] = NULL;
  nodeList[0] = &RocsWgen_dipvalue;
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


struct __wDIPGroup wDIPGroup = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  1,
  0,
  _getcaption,
  _setcaption,
  _getmask,
  _setmask,
  _getori,
  _setori,
  _getspacing,
  _setspacing,
  _gettype,
  _settype,
  _getdipvalue,
  _nextdipvalue,
  _setdipvalue,
  _node_dump,
};
