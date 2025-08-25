/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/Waybill.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Waybill
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_waybill = {
  "waybill",  "Waybill definition.",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_waybill.name;
}
static const char* _node_remark(void) {
  return RocsWgen_waybill.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_waybill.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_waybill.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cartype
 */
static struct __attrdef RocsWgen_cartype = {
  "cartype",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getcartype(iONode node) {
  const char* defval = xStr( RocsWgen_cartype );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_waybill, node );
  return NodeOp.getStr( node, "cartype", defval );
}
static void _setcartype(iONode node, const char* p_cartype) {
  if( node == NULL ) return;
  xNode( RocsWgen_waybill, node );
  NodeOp.setStr( node, "cartype", p_cartype );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * commodity
 */
static struct __attrdef RocsWgen_commodity = {
  "commodity",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getcommodity(iONode node) {
  const char* defval = xStr( RocsWgen_commodity );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_waybill, node );
  return NodeOp.getStr( node, "commodity", defval );
}
static void _setcommodity(iONode node, const char* p_commodity) {
  if( node == NULL ) return;
  xNode( RocsWgen_waybill, node );
  NodeOp.setStr( node, "commodity", p_commodity );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * consignee
 */
static struct __attrdef RocsWgen_consignee = {
  "consignee",  "",  "",  "string",  "",  "*",  True,
};
static const char* _getconsignee(iONode node) {
  const char* defval = xStr( RocsWgen_consignee );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_waybill, node );
  return NodeOp.getStr( node, "consignee", defval );
}
static void _setconsignee(iONode node, const char* p_consignee) {
  if( node == NULL ) return;
  xNode( RocsWgen_waybill, node );
  NodeOp.setStr( node, "consignee", p_consignee );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * destination
 */
static struct __attrdef RocsWgen_destination = {
  "destination",  "Consignee (local) block.",  "",  "string",  "",  "*",  True,
};
static const char* _getdestination(iONode node) {
  const char* defval = xStr( RocsWgen_destination );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_waybill, node );
  return NodeOp.getStr( node, "destination", defval );
}
static void _setdestination(iONode node, const char* p_destination) {
  if( node == NULL ) return;
  xNode( RocsWgen_waybill, node );
  NodeOp.setStr( node, "destination", p_destination );
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
  xNode( RocsWgen_waybill, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_waybill, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * origin
 */
static struct __attrdef RocsWgen_origin = {
  "origin",  "Shipper (local) block.",  "",  "string",  "",  "*",  True,
};
static const char* _getorigin(iONode node) {
  const char* defval = xStr( RocsWgen_origin );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_waybill, node );
  return NodeOp.getStr( node, "origin", defval );
}
static void _setorigin(iONode node, const char* p_origin) {
  if( node == NULL ) return;
  xNode( RocsWgen_waybill, node );
  NodeOp.setStr( node, "origin", p_origin );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * routing
 */
static struct __attrdef RocsWgen_routing = {
  "routing",  "",  "",  "string",  "",  "*",  True,
};
static const char* _getrouting(iONode node) {
  const char* defval = xStr( RocsWgen_routing );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_waybill, node );
  return NodeOp.getStr( node, "routing", defval );
}
static void _setrouting(iONode node, const char* p_routing) {
  if( node == NULL ) return;
  xNode( RocsWgen_waybill, node );
  NodeOp.setStr( node, "routing", p_routing );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * shipper
 */
static struct __attrdef RocsWgen_shipper = {
  "shipper",  "",  "",  "string",  "",  "*",  True,
};
static const char* _getshipper(iONode node) {
  const char* defval = xStr( RocsWgen_shipper );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_waybill, node );
  return NodeOp.getStr( node, "shipper", defval );
}
static void _setshipper(iONode node, const char* p_shipper) {
  if( node == NULL ) return;
  xNode( RocsWgen_waybill, node );
  NodeOp.setStr( node, "shipper", p_shipper );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * status
 */
static struct __attrdef RocsWgen_status = {
  "status",  "Waybill status.",  "",  "string",  "waiting",  "*",  False,
};
static const char* _getstatus(iONode node) {
  const char* defval = xStr( RocsWgen_status );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_waybill, node );
  return NodeOp.getStr( node, "status", defval );
}
static void _setstatus(iONode node, const char* p_status) {
  if( node == NULL ) return;
  xNode( RocsWgen_waybill, node );
  NodeOp.setStr( node, "status", p_status );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[10] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_waybill.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node waybill not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node waybill not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_cartype;
  attrList[1] = &RocsWgen_commodity;
  attrList[2] = &RocsWgen_consignee;
  attrList[3] = &RocsWgen_destination;
  attrList[4] = &RocsWgen_id;
  attrList[5] = &RocsWgen_origin;
  attrList[6] = &RocsWgen_routing;
  attrList[7] = &RocsWgen_shipper;
  attrList[8] = &RocsWgen_status;
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


struct __wWaybill wWaybill = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "delivered",
  "shipping",
  "waiting",
  _getcartype,
  _setcartype,
  _getcommodity,
  _setcommodity,
  _getconsignee,
  _setconsignee,
  _getdestination,
  _setdestination,
  _getid,
  _setid,
  _getorigin,
  _setorigin,
  _getrouting,
  _setrouting,
  _getshipper,
  _setshipper,
  _getstatus,
  _setstatus,
  _node_dump,
};
