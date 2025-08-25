/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/SelTabPos.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.SelTabPos
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_seltabpos = {
  "seltabpos",  "Selection Table Position",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_seltabpos.name;
}
static const char* _node_remark(void) {
  return RocsWgen_seltabpos.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_seltabpos.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_seltabpos.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bkid
 */
static struct __attrdef RocsWgen_bkid = {
  "bkid",  "block id",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getbkid(iONode node) {
  const char* defval = xStr( RocsWgen_bkid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltabpos, node );
  return NodeOp.getStr( node, "bkid", defval );
}
static void _setbkid(iONode node, const char* p_bkid) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltabpos, node );
  NodeOp.setStr( node, "bkid", p_bkid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * desc
 */
static struct __attrdef RocsWgen_desc = {
  "desc",  "description",  "",  "string",  "",  "*",  False,
};
static const char* _getdesc(iONode node) {
  const char* defval = xStr( RocsWgen_desc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltabpos, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltabpos, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nr
 */
static struct __attrdef RocsWgen_nr = {
  "nr",  "position",  "",  "int",  "0",  "*",  False,
};
static int _getnr(iONode node) {
  int defval = xInt( RocsWgen_nr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltabpos, node );
  return NodeOp.getInt( node, "nr", defval );
}
static void _setnr(iONode node, int p_nr) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltabpos, node );
  NodeOp.setInt( node, "nr", p_nr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * s1id
 */
static struct __attrdef RocsWgen_s1id = {
  "s1id",  "sensor 1 id for optical feedback of the selected position",  "",  "string",  "NULL",  "*",  False,
};
static const char* _gets1id(iONode node) {
  const char* defval = xStr( RocsWgen_s1id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltabpos, node );
  return NodeOp.getStr( node, "s1id", defval );
}
static void _sets1id(iONode node, const char* p_s1id) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltabpos, node );
  NodeOp.setStr( node, "s1id", p_s1id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * s2id
 */
static struct __attrdef RocsWgen_s2id = {
  "s2id",  "sensor 2 id for optical feedback of the selected position",  "",  "string",  "NULL",  "*",  False,
};
static const char* _gets2id(iONode node) {
  const char* defval = xStr( RocsWgen_s2id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltabpos, node );
  return NodeOp.getStr( node, "s2id", defval );
}
static void _sets2id(iONode node, const char* p_s2id) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltabpos, node );
  NodeOp.setStr( node, "s2id", p_s2id );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[6] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_seltabpos.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node seltabpos not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node seltabpos not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_bkid;
  attrList[1] = &RocsWgen_desc;
  attrList[2] = &RocsWgen_nr;
  attrList[3] = &RocsWgen_s1id;
  attrList[4] = &RocsWgen_s2id;
  attrList[5] = NULL;
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


struct __wSelTabPos wSelTabPos = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getbkid,
  _setbkid,
  _getdesc,
  _setdesc,
  _getnr,
  _setnr,
  _gets1id,
  _sets1id,
  _gets2id,
  _sets2id,
  _node_dump,
};
