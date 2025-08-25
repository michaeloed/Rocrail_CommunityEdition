/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/ActionCond.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.ActionCond
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_actioncond = {
  "actioncond",  "Optional condition.",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_actioncond.name;
}
static const char* _node_remark(void) {
  return RocsWgen_actioncond.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_actioncond.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_actioncond.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "",  "",  "string",  "",  "*",  True,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actioncond, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_actioncond, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mustbetrue
 */
static struct __attrdef RocsWgen_mustbetrue = {
  "mustbetrue",  "This condition must be true, also in case allconditions is false.",  "",  "bool",  "false",  "",  False,
};
static Boolean _ismustbetrue(iONode node) {
  Boolean defval = xBool( RocsWgen_mustbetrue );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actioncond, node );
  return NodeOp.getBool( node, "mustbetrue", defval );
}
static void _setmustbetrue(iONode node, Boolean p_mustbetrue) {
  if( node == NULL ) return;
  xNode( RocsWgen_actioncond, node );
  NodeOp.setBool( node, "mustbetrue", p_mustbetrue );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * state
 */
static struct __attrdef RocsWgen_state = {
  "state",  "Activation state, empty is always.",  "",  "string",  "",  "*",  False,
};
static const char* _getstate(iONode node) {
  const char* defval = xStr( RocsWgen_state );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actioncond, node );
  return NodeOp.getStr( node, "state", defval );
}
static void _setstate(iONode node, const char* p_state) {
  if( node == NULL ) return;
  xNode( RocsWgen_actioncond, node );
  NodeOp.setStr( node, "state", p_state );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * subid
 */
static struct __attrdef RocsWgen_subid = {
  "subid",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getsubid(iONode node) {
  const char* defval = xStr( RocsWgen_subid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actioncond, node );
  return NodeOp.getStr( node, "subid", defval );
}
static void _setsubid(iONode node, const char* p_subid) {
  if( node == NULL ) return;
  xNode( RocsWgen_actioncond, node );
  NodeOp.setStr( node, "subid", p_subid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * type
 */
static struct __attrdef RocsWgen_type = {
  "type",  "",  "",  "string",  "",  "co,sw,sg,fb,lc,bk",  True,
};
static const char* _gettype(iONode node) {
  const char* defval = xStr( RocsWgen_type );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actioncond, node );
  return NodeOp.getStr( node, "type", defval );
}
static void _settype(iONode node, const char* p_type) {
  if( node == NULL ) return;
  xNode( RocsWgen_actioncond, node );
  NodeOp.setStr( node, "type", p_type );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[6] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_actioncond.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node actioncond not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node actioncond not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_id;
  attrList[1] = &RocsWgen_mustbetrue;
  attrList[2] = &RocsWgen_state;
  attrList[3] = &RocsWgen_subid;
  attrList[4] = &RocsWgen_type;
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


struct __wActionCond wActionCond = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getid,
  _setid,
  _ismustbetrue,
  _setmustbetrue,
  _getstate,
  _setstate,
  _getsubid,
  _setsubid,
  _gettype,
  _settype,
  _node_dump,
};
