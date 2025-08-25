/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/DIPValue.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.DIPValue
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_dipvalue = {
  "dipvalue",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_dipvalue.name;
}
static const char* _node_remark(void) {
  return RocsWgen_dipvalue.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_dipvalue.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_dipvalue.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * info
 */
static struct __attrdef RocsWgen_info = {
  "info",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getinfo(iONode node) {
  const char* defval = xStr( RocsWgen_info );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dipvalue, node );
  return NodeOp.getStr( node, "info", defval );
}
static void _setinfo(iONode node, const char* p_info) {
  if( node == NULL ) return;
  xNode( RocsWgen_dipvalue, node );
  NodeOp.setStr( node, "info", p_info );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * name
 */
static struct __attrdef RocsWgen_name = {
  "name",  "",  "",  "string",  "Value",  "*",  False,
};
static const char* _getname(iONode node) {
  const char* defval = xStr( RocsWgen_name );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dipvalue, node );
  return NodeOp.getStr( node, "name", defval );
}
static void _setname(iONode node, const char* p_name) {
  if( node == NULL ) return;
  xNode( RocsWgen_dipvalue, node );
  NodeOp.setStr( node, "name", p_name );
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
  xNode( RocsWgen_dipvalue, node );
  return NodeOp.getInt( node, "type", defval );
}
static void _settype(iONode node, int p_type) {
  if( node == NULL ) return;
  xNode( RocsWgen_dipvalue, node );
  NodeOp.setInt( node, "type", p_type );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * value
 */
static struct __attrdef RocsWgen_value = {
  "value",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getvalue(iONode node) {
  int defval = xInt( RocsWgen_value );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_dipvalue, node );
  return NodeOp.getInt( node, "value", defval );
}
static void _setvalue(iONode node, int p_value) {
  if( node == NULL ) return;
  xNode( RocsWgen_dipvalue, node );
  NodeOp.setInt( node, "value", p_value );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[5] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_dipvalue.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node dipvalue not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node dipvalue not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_info;
  attrList[1] = &RocsWgen_name;
  attrList[2] = &RocsWgen_type;
  attrList[3] = &RocsWgen_value;
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


struct __wDIPValue wDIPValue = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  1,
  0,
  _getinfo,
  _setinfo,
  _getname,
  _setname,
  _gettype,
  _settype,
  _getvalue,
  _setvalue,
  _node_dump,
};
