/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Accessory.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Accessory
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_acc = {
  "acc",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_acc.name;
}
static const char* _node_remark(void) {
  return RocsWgen_acc.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_acc.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_acc.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * accevent
 */
static struct __attrdef RocsWgen_accevent = {
  "accevent",  "To check in the model if it was an accessory event.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isaccevent(iONode node) {
  Boolean defval = xBool( RocsWgen_accevent );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_acc, node );
  return NodeOp.getBool( node, "accevent", defval );
}
static void _setaccevent(iONode node, Boolean p_accevent) {
  if( node == NULL ) return;
  xNode( RocsWgen_acc, node );
  NodeOp.setBool( node, "accevent", p_accevent );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * devid
 */
static struct __attrdef RocsWgen_devid = {
  "devid",  "Device ID",  "",  "int",  "0",  "0-*",  True,
};
static int _getdevid(iONode node) {
  int defval = xInt( RocsWgen_devid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_acc, node );
  return NodeOp.getInt( node, "devid", defval );
}
static void _setdevid(iONode node, int p_devid) {
  if( node == NULL ) return;
  xNode( RocsWgen_acc, node );
  NodeOp.setInt( node, "devid", p_devid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iid
 */
static struct __attrdef RocsWgen_iid = {
  "iid",  "Interface ID",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getiid(iONode node) {
  const char* defval = xStr( RocsWgen_iid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_acc, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_acc, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nodenr
 */
static struct __attrdef RocsWgen_nodenr = {
  "nodenr",  "Node number",  "",  "int",  "0",  "0-*",  False,
};
static int _getnodenr(iONode node) {
  int defval = xInt( RocsWgen_nodenr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_acc, node );
  return NodeOp.getInt( node, "nodenr", defval );
}
static void _setnodenr(iONode node, int p_nodenr) {
  if( node == NULL ) return;
  xNode( RocsWgen_acc, node );
  NodeOp.setInt( node, "nodenr", p_nodenr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * state
 */
static struct __attrdef RocsWgen_state = {
  "state",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getstate(iONode node) {
  const char* defval = xStr( RocsWgen_state );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_acc, node );
  return NodeOp.getStr( node, "state", defval );
}
static void _setstate(iONode node, const char* p_state) {
  if( node == NULL ) return;
  xNode( RocsWgen_acc, node );
  NodeOp.setStr( node, "state", p_state );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val1
 */
static struct __attrdef RocsWgen_val1 = {
  "val1",  "Value",  "",  "int",  "0",  "0-*",  True,
};
static int _getval1(iONode node) {
  int defval = xInt( RocsWgen_val1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_acc, node );
  return NodeOp.getInt( node, "val1", defval );
}
static void _setval1(iONode node, int p_val1) {
  if( node == NULL ) return;
  xNode( RocsWgen_acc, node );
  NodeOp.setInt( node, "val1", p_val1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val2
 */
static struct __attrdef RocsWgen_val2 = {
  "val2",  "Value",  "",  "int",  "0",  "0-*",  True,
};
static int _getval2(iONode node) {
  int defval = xInt( RocsWgen_val2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_acc, node );
  return NodeOp.getInt( node, "val2", defval );
}
static void _setval2(iONode node, int p_val2) {
  if( node == NULL ) return;
  xNode( RocsWgen_acc, node );
  NodeOp.setInt( node, "val2", p_val2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val3
 */
static struct __attrdef RocsWgen_val3 = {
  "val3",  "Value",  "",  "int",  "0",  "0-*",  True,
};
static int _getval3(iONode node) {
  int defval = xInt( RocsWgen_val3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_acc, node );
  return NodeOp.getInt( node, "val3", defval );
}
static void _setval3(iONode node, int p_val3) {
  if( node == NULL ) return;
  xNode( RocsWgen_acc, node );
  NodeOp.setInt( node, "val3", p_val3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val4
 */
static struct __attrdef RocsWgen_val4 = {
  "val4",  "Value",  "",  "int",  "0",  "0-*",  True,
};
static int _getval4(iONode node) {
  int defval = xInt( RocsWgen_val4 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_acc, node );
  return NodeOp.getInt( node, "val4", defval );
}
static void _setval4(iONode node, int p_val4) {
  if( node == NULL ) return;
  xNode( RocsWgen_acc, node );
  NodeOp.setInt( node, "val4", p_val4 );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[10] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_acc.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node acc not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node acc not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_accevent;
  attrList[1] = &RocsWgen_devid;
  attrList[2] = &RocsWgen_iid;
  attrList[3] = &RocsWgen_nodenr;
  attrList[4] = &RocsWgen_state;
  attrList[5] = &RocsWgen_val1;
  attrList[6] = &RocsWgen_val2;
  attrList[7] = &RocsWgen_val3;
  attrList[8] = &RocsWgen_val4;
  attrList[9] = NULL;
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


struct __wAccessory wAccessory = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isaccevent,
  _setaccevent,
  _getdevid,
  _setdevid,
  _getiid,
  _setiid,
  _getnodenr,
  _setnodenr,
  _getstate,
  _setstate,
  _getval1,
  _setval1,
  _getval2,
  _setval2,
  _getval3,
  _setval3,
  _getval4,
  _setval4,
  _node_dump,
};
