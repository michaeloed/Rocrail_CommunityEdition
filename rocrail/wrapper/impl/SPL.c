/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/SPL.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.SPL
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_spl = {
  "spl",  "SPL options",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_spl.name;
}
static const char* _node_remark(void) {
  return RocsWgen_spl.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_spl.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_spl.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fromaddr
 */
static struct __attrdef RocsWgen_fromaddr = {
  "fromaddr",  "",  "",  "int",  "0",  "",  False,
};
static int _getfromaddr(iONode node) {
  int defval = xInt( RocsWgen_fromaddr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_spl, node );
  return NodeOp.getInt( node, "fromaddr", defval );
}
static void _setfromaddr(iONode node, int p_fromaddr) {
  if( node == NULL ) return;
  xNode( RocsWgen_spl, node );
  NodeOp.setInt( node, "fromaddr", p_fromaddr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nrleds
 */
static struct __attrdef RocsWgen_nrleds = {
  "nrleds",  "",  "",  "int",  "5",  "",  False,
};
static int _getnrleds(iONode node) {
  int defval = xInt( RocsWgen_nrleds );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_spl, node );
  return NodeOp.getInt( node, "nrleds", defval );
}
static void _setnrleds(iONode node, int p_nrleds) {
  if( node == NULL ) return;
  xNode( RocsWgen_spl, node );
  NodeOp.setInt( node, "nrleds", p_nrleds );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * toaddr
 */
static struct __attrdef RocsWgen_toaddr = {
  "toaddr",  "",  "",  "int",  "0",  "",  False,
};
static int _gettoaddr(iONode node) {
  int defval = xInt( RocsWgen_toaddr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_spl, node );
  return NodeOp.getInt( node, "toaddr", defval );
}
static void _settoaddr(iONode node, int p_toaddr) {
  if( node == NULL ) return;
  xNode( RocsWgen_spl, node );
  NodeOp.setInt( node, "toaddr", p_toaddr );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[4] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_spl.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node spl not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node spl not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_fromaddr;
  attrList[1] = &RocsWgen_nrleds;
  attrList[2] = &RocsWgen_toaddr;
  attrList[3] = NULL;
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


struct __wSPL wSPL = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getfromaddr,
  _setfromaddr,
  _getnrleds,
  _setnrleds,
  _gettoaddr,
  _settoaddr,
  _node_dump,
};
