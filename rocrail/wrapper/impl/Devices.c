/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Devices.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Devices
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_devices = {
  "devices",  "List of available server devices.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_devices.name;
}
static const char* _node_remark(void) {
  return RocsWgen_devices.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_devices.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_devices.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * serial
 */
static struct __attrdef RocsWgen_serial = {
  "serial",  "CSV list of serial devices.",  "",  "string",  "",  "*",  False,
};
static const char* _getserial(iONode node) {
  const char* defval = xStr( RocsWgen_serial );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_devices, node );
  return NodeOp.getStr( node, "serial", defval );
}
static void _setserial(iONode node, const char* p_serial) {
  if( node == NULL ) return;
  xNode( RocsWgen_devices, node );
  NodeOp.setStr( node, "serial", p_serial );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[2] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_devices.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node devices not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node devices not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_serial;
  attrList[1] = NULL;
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


struct __wDevices wDevices = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getserial,
  _setserial,
  _node_dump,
};
