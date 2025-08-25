/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Occupancy.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Occupancy
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_occ = {
  "occ",  "Occupancy entry",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_occ.name;
}
static const char* _node_remark(void) {
  return RocsWgen_occ.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_occ.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_occ.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * auto
 */
static struct __attrdef RocsWgen_auto = {
  "auto",  "The occupying loco is in automode.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isauto(iONode node) {
  Boolean defval = xBool( RocsWgen_auto );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_occ, node );
  return NodeOp.getBool( node, "auto", defval );
}
static void _setauto(iONode node, Boolean p_auto) {
  if( node == NULL ) return;
  xNode( RocsWgen_occ, node );
  NodeOp.setBool( node, "auto", p_auto );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bkid
 */
static struct __attrdef RocsWgen_bkid = {
  "bkid",  "",  "",  "string",  "",  "*",  True,
};
static const char* _getbkid(iONode node) {
  const char* defval = xStr( RocsWgen_bkid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_occ, node );
  return NodeOp.getStr( node, "bkid", defval );
}
static void _setbkid(iONode node, const char* p_bkid) {
  if( node == NULL ) return;
  xNode( RocsWgen_occ, node );
  NodeOp.setStr( node, "bkid", p_bkid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blockenterside
 */
static struct __attrdef RocsWgen_blockenterside = {
  "blockenterside",  "Block enter side: 0 = Not set, 1 = True, 2 = False",  "",  "int",  "0",  "",  False,
};
static int _getblockenterside(iONode node) {
  int defval = xInt( RocsWgen_blockenterside );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_occ, node );
  return NodeOp.getInt( node, "blockenterside", defval );
}
static void _setblockenterside(iONode node, int p_blockenterside) {
  if( node == NULL ) return;
  xNode( RocsWgen_occ, node );
  NodeOp.setInt( node, "blockenterside", p_blockenterside );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * closed
 */
static struct __attrdef RocsWgen_closed = {
  "closed",  "Signal this block as closed: Out of order.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isclosed(iONode node) {
  Boolean defval = xBool( RocsWgen_closed );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_occ, node );
  return NodeOp.getBool( node, "closed", defval );
}
static void _setclosed(iONode node, Boolean p_closed) {
  if( node == NULL ) return;
  xNode( RocsWgen_occ, node );
  NodeOp.setBool( node, "closed", p_closed );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lcid
 */
static struct __attrdef RocsWgen_lcid = {
  "lcid",  "",  "",  "string",  "",  "*",  True,
};
static const char* _getlcid(iONode node) {
  const char* defval = xStr( RocsWgen_lcid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_occ, node );
  return NodeOp.getStr( node, "lcid", defval );
}
static void _setlcid(iONode node, const char* p_lcid) {
  if( node == NULL ) return;
  xNode( RocsWgen_occ, node );
  NodeOp.setStr( node, "lcid", p_lcid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * placing
 */
static struct __attrdef RocsWgen_placing = {
  "placing",  "Loco placing: 0 = Not set, 1 = True, 2 = False",  "",  "int",  "0",  "",  False,
};
static int _getplacing(iONode node) {
  int defval = xInt( RocsWgen_placing );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_occ, node );
  return NodeOp.getInt( node, "placing", defval );
}
static void _setplacing(iONode node, int p_placing) {
  if( node == NULL ) return;
  xNode( RocsWgen_occ, node );
  NodeOp.setInt( node, "placing", p_placing );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * scid
 */
static struct __attrdef RocsWgen_scid = {
  "scid",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getscid(iONode node) {
  const char* defval = xStr( RocsWgen_scid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_occ, node );
  return NodeOp.getStr( node, "scid", defval );
}
static void _setscid(iONode node, const char* p_scid) {
  if( node == NULL ) return;
  xNode( RocsWgen_occ, node );
  NodeOp.setStr( node, "scid", p_scid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * secid
 */
static struct __attrdef RocsWgen_secid = {
  "secid",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getsecid(iONode node) {
  const char* defval = xStr( RocsWgen_secid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_occ, node );
  return NodeOp.getStr( node, "secid", defval );
}
static void _setsecid(iONode node, const char* p_secid) {
  if( node == NULL ) return;
  xNode( RocsWgen_occ, node );
  NodeOp.setStr( node, "secid", p_secid );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[9] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_occ.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node occ not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node occ not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_auto;
  attrList[1] = &RocsWgen_bkid;
  attrList[2] = &RocsWgen_blockenterside;
  attrList[3] = &RocsWgen_closed;
  attrList[4] = &RocsWgen_lcid;
  attrList[5] = &RocsWgen_placing;
  attrList[6] = &RocsWgen_scid;
  attrList[7] = &RocsWgen_secid;
  attrList[8] = NULL;
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


struct __wOccupancy wOccupancy = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isauto,
  _setauto,
  _getbkid,
  _setbkid,
  _getblockenterside,
  _setblockenterside,
  _isclosed,
  _setclosed,
  _getlcid,
  _setlcid,
  _getplacing,
  _setplacing,
  _getscid,
  _setscid,
  _getsecid,
  _setsecid,
  _node_dump,
};
