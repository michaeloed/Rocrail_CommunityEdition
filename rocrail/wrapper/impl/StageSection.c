/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/StageSection.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.StageSection
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_section = {
  "section",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_section.name;
}
static const char* _node_remark(void) {
  return RocsWgen_section.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_section.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_section.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * action
 */
static struct __attrdef RocsWgen_action = {
  "action",  "",  "",  "string",  "",  "",  False,
};
static const char* _getaction(iONode node) {
  const char* defval = xStr( RocsWgen_action );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_section, node );
  return NodeOp.getStr( node, "action", defval );
}
static void _setaction(iONode node, const char* p_action) {
  if( node == NULL ) return;
  xNode( RocsWgen_section, node );
  NodeOp.setStr( node, "action", p_action );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbid
 */
static struct __attrdef RocsWgen_fbid = {
  "fbid",  "feedback ID",  "",  "string",  "",  "*",  True,
};
static const char* _getfbid(iONode node) {
  const char* defval = xStr( RocsWgen_fbid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_section, node );
  return NodeOp.getStr( node, "fbid", defval );
}
static void _setfbid(iONode node, const char* p_fbid) {
  if( node == NULL ) return;
  xNode( RocsWgen_section, node );
  NodeOp.setStr( node, "fbid", p_fbid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbidocc
 */
static struct __attrdef RocsWgen_fbidocc = {
  "fbidocc",  "feedback ID of section body.",  "",  "string",  "",  "*",  True,
};
static const char* _getfbidocc(iONode node) {
  const char* defval = xStr( RocsWgen_fbidocc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_section, node );
  return NodeOp.getStr( node, "fbidocc", defval );
}
static void _setfbidocc(iONode node, const char* p_fbidocc) {
  if( node == NULL ) return;
  xNode( RocsWgen_section, node );
  NodeOp.setStr( node, "fbidocc", p_fbidocc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "",  "",  "string",  "?",  "*",  True,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_section, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_section, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * idx
 */
static struct __attrdef RocsWgen_idx = {
  "idx",  "",  "",  "int",  "0",  "",  False,
};
static int _getidx(iONode node) {
  int defval = xInt( RocsWgen_idx );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_section, node );
  return NodeOp.getInt( node, "idx", defval );
}
static void _setidx(iONode node, int p_idx) {
  if( node == NULL ) return;
  xNode( RocsWgen_section, node );
  NodeOp.setInt( node, "idx", p_idx );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lcid
 */
static struct __attrdef RocsWgen_lcid = {
  "lcid",  "",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getlcid(iONode node) {
  const char* defval = xStr( RocsWgen_lcid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_section, node );
  return NodeOp.getStr( node, "lcid", defval );
}
static void _setlcid(iONode node, const char* p_lcid) {
  if( node == NULL ) return;
  xNode( RocsWgen_section, node );
  NodeOp.setStr( node, "lcid", p_lcid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * len
 */
static struct __attrdef RocsWgen_len = {
  "len",  "Section length.",  "cm",  "int",  "0",  "0-*",  False,
};
static int _getlen(iONode node) {
  int defval = xInt( RocsWgen_len );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_section, node );
  return NodeOp.getInt( node, "len", defval );
}
static void _setlen(iONode node, int p_len) {
  if( node == NULL ) return;
  xNode( RocsWgen_section, node );
  NodeOp.setInt( node, "len", p_len );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nr
 */
static struct __attrdef RocsWgen_nr = {
  "nr",  "",  "",  "int",  "0",  "",  False,
};
static int _getnr(iONode node) {
  int defval = xInt( RocsWgen_nr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_section, node );
  return NodeOp.getInt( node, "nr", defval );
}
static void _setnr(iONode node, int p_nr) {
  if( node == NULL ) return;
  xNode( RocsWgen_section, node );
  NodeOp.setInt( node, "nr", p_nr );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[9] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_section.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node section not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node section not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_action;
  attrList[1] = &RocsWgen_fbid;
  attrList[2] = &RocsWgen_fbidocc;
  attrList[3] = &RocsWgen_id;
  attrList[4] = &RocsWgen_idx;
  attrList[5] = &RocsWgen_lcid;
  attrList[6] = &RocsWgen_len;
  attrList[7] = &RocsWgen_nr;
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


struct __wStageSection wStageSection = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getaction,
  _setaction,
  _getfbid,
  _setfbid,
  _getfbidocc,
  _setfbidocc,
  _getid,
  _setid,
  _getidx,
  _setidx,
  _getlcid,
  _setlcid,
  _getlen,
  _setlen,
  _getnr,
  _setnr,
  _node_dump,
};
