/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/Variable.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Variable
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_vr = {
  "vr",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_vr.name;
}
static const char* _node_remark(void) {
  return RocsWgen_vr.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_vr.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_vr.cardinality;
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
  xNode( RocsWgen_vr, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_vr, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * group
 */
static struct __attrdef RocsWgen_group = {
  "group",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getgroup(iONode node) {
  const char* defval = xStr( RocsWgen_group );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_vr, node );
  return NodeOp.getStr( node, "group", defval );
}
static void _setgroup(iONode node, const char* p_group) {
  if( node == NULL ) return;
  xNode( RocsWgen_vr, node );
  NodeOp.setStr( node, "group", p_group );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "object id",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_vr, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_vr, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * max
 */
static struct __attrdef RocsWgen_max = {
  "max",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getmax(iONode node) {
  int defval = xInt( RocsWgen_max );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_vr, node );
  return NodeOp.getInt( node, "max", defval );
}
static void _setmax(iONode node, int p_max) {
  if( node == NULL ) return;
  xNode( RocsWgen_vr, node );
  NodeOp.setInt( node, "max", p_max );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * min
 */
static struct __attrdef RocsWgen_min = {
  "min",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getmin(iONode node) {
  int defval = xInt( RocsWgen_min );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_vr, node );
  return NodeOp.getInt( node, "min", defval );
}
static void _setmin(iONode node, int p_min) {
  if( node == NULL ) return;
  xNode( RocsWgen_vr, node );
  NodeOp.setInt( node, "min", p_min );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * text
 */
static struct __attrdef RocsWgen_text = {
  "text",  "",  "",  "string",  "",  "*",  False,
};
static const char* _gettext(iONode node) {
  const char* defval = xStr( RocsWgen_text );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_vr, node );
  return NodeOp.getStr( node, "text", defval );
}
static void _settext(iONode node, const char* p_text) {
  if( node == NULL ) return;
  xNode( RocsWgen_vr, node );
  NodeOp.setStr( node, "text", p_text );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timer
 */
static struct __attrdef RocsWgen_timer = {
  "timer",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _istimer(iONode node) {
  Boolean defval = xBool( RocsWgen_timer );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_vr, node );
  return NodeOp.getBool( node, "timer", defval );
}
static void _settimer(iONode node, Boolean p_timer) {
  if( node == NULL ) return;
  xNode( RocsWgen_vr, node );
  NodeOp.setBool( node, "timer", p_timer );
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
  xNode( RocsWgen_vr, node );
  return NodeOp.getInt( node, "type", defval );
}
static void _settype(iONode node, int p_type) {
  if( node == NULL ) return;
  xNode( RocsWgen_vr, node );
  NodeOp.setInt( node, "type", p_type );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * valstr
 */
static struct __attrdef RocsWgen_valstr = {
  "valstr",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getvalstr(iONode node) {
  const char* defval = xStr( RocsWgen_valstr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_vr, node );
  return NodeOp.getStr( node, "valstr", defval );
}
static void _setvalstr(iONode node, const char* p_valstr) {
  if( node == NULL ) return;
  xNode( RocsWgen_vr, node );
  NodeOp.setStr( node, "valstr", p_valstr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * value
 */
static struct __attrdef RocsWgen_value = {
  "value",  "",  "",  "int",  "0",  "*",  False,
};
static int _getvalue(iONode node) {
  int defval = xInt( RocsWgen_value );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_vr, node );
  return NodeOp.getInt( node, "value", defval );
}
static void _setvalue(iONode node, int p_value) {
  if( node == NULL ) return;
  xNode( RocsWgen_vr, node );
  NodeOp.setInt( node, "value", p_value );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * actionctrl
 */
static struct __nodedef RocsWgen_actionctrl = {
  "actionctrl",  "",  False,  "n",};
static iONode _getactionctrl(iONode node) {
  xNode( RocsWgen_vr, node );
  return NodeOp.findNode( node, "actionctrl");
}


static iONode _nextactionctrl(iONode node, iONode child) {
  xNode( RocsWgen_vr, node );
  return NodeOp.findNextNode( node, child);
}
static void _setactionctrl(iONode node, iONode p_actionctrl) {
  xNode( RocsWgen_vr, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[11] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_vr.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node vr not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node vr not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_desc;
  attrList[1] = &RocsWgen_group;
  attrList[2] = &RocsWgen_id;
  attrList[3] = &RocsWgen_max;
  attrList[4] = &RocsWgen_min;
  attrList[5] = &RocsWgen_text;
  attrList[6] = &RocsWgen_timer;
  attrList[7] = &RocsWgen_type;
  attrList[8] = &RocsWgen_valstr;
  attrList[9] = &RocsWgen_value;
  attrList[10] = NULL;
  nodeList[0] = &RocsWgen_actionctrl;
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


struct __wVariable wVariable = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "add",
  "max",
  "min",
  "random",
  "start",
  "stop",
  "subtract",
  "text",
  "value",
  0,
  1,
  _getdesc,
  _setdesc,
  _getgroup,
  _setgroup,
  _getid,
  _setid,
  _getmax,
  _setmax,
  _getmin,
  _setmin,
  _gettext,
  _settext,
  _istimer,
  _settimer,
  _gettype,
  _settype,
  _getvalstr,
  _setvalstr,
  _getvalue,
  _setvalue,
  _getactionctrl,
  _nextactionctrl,
  _setactionctrl,
  _node_dump,
};
