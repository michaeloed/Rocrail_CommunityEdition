/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/JsEvent.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.JsEvent
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_jsevent = {
  "jsevent",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_jsevent.name;
}
static const char* _node_remark(void) {
  return RocsWgen_jsevent.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_jsevent.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_jsevent.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * device
 */
static struct __attrdef RocsWgen_device = {
  "device",  "",  "",  "int",  "0",  "*",  False,
};
static int _getdevice(iONode node) {
  int defval = xInt( RocsWgen_device );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_jsevent, node );
  return NodeOp.getInt( node, "device", defval );
}
static void _setdevice(iONode node, int p_device) {
  if( node == NULL ) return;
  xNode( RocsWgen_jsevent, node );
  NodeOp.setInt( node, "device", p_device );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * msec
 */
static struct __attrdef RocsWgen_msec = {
  "msec",  "",  "",  "int",  "0",  "*",  False,
};
static int _getmsec(iONode node) {
  int defval = xInt( RocsWgen_msec );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_jsevent, node );
  return NodeOp.getInt( node, "msec", defval );
}
static void _setmsec(iONode node, int p_msec) {
  if( node == NULL ) return;
  xNode( RocsWgen_jsevent, node );
  NodeOp.setInt( node, "msec", p_msec );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * number
 */
static struct __attrdef RocsWgen_number = {
  "number",  "",  "",  "int",  "0",  "*",  False,
};
static int _getnumber(iONode node) {
  int defval = xInt( RocsWgen_number );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_jsevent, node );
  return NodeOp.getInt( node, "number", defval );
}
static void _setnumber(iONode node, int p_number) {
  if( node == NULL ) return;
  xNode( RocsWgen_jsevent, node );
  NodeOp.setInt( node, "number", p_number );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * type
 */
static struct __attrdef RocsWgen_type = {
  "type",  "",  "",  "int",  "0",  "*",  False,
};
static int _gettype(iONode node) {
  int defval = xInt( RocsWgen_type );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_jsevent, node );
  return NodeOp.getInt( node, "type", defval );
}
static void _settype(iONode node, int p_type) {
  if( node == NULL ) return;
  xNode( RocsWgen_jsevent, node );
  NodeOp.setInt( node, "type", p_type );
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
  xNode( RocsWgen_jsevent, node );
  return NodeOp.getInt( node, "value", defval );
}
static void _setvalue(iONode node, int p_value) {
  if( node == NULL ) return;
  xNode( RocsWgen_jsevent, node );
  NodeOp.setInt( node, "value", p_value );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[6] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_jsevent.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node jsevent not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node jsevent not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_device;
  attrList[1] = &RocsWgen_msec;
  attrList[2] = &RocsWgen_number;
  attrList[3] = &RocsWgen_type;
  attrList[4] = &RocsWgen_value;
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


struct __wJsEvent wJsEvent = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getdevice,
  _setdevice,
  _getmsec,
  _setmsec,
  _getnumber,
  _setnumber,
  _gettype,
  _settype,
  _getvalue,
  _setvalue,
  _node_dump,
};
