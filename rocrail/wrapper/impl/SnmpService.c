/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/SnmpService.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.SnmpService
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_SnmpService = {
  "SnmpService",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_SnmpService.name;
}
static const char* _node_remark(void) {
  return RocsWgen_SnmpService.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_SnmpService.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_SnmpService.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * active
 */
static struct __attrdef RocsWgen_active = {
  "active",  "Activate snmp service.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isactive(iONode node) {
  Boolean defval = xBool( RocsWgen_active );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_SnmpService, node );
  return NodeOp.getBool( node, "active", defval );
}
static void _setactive(iONode node, Boolean p_active) {
  if( node == NULL ) return;
  xNode( RocsWgen_SnmpService, node );
  NodeOp.setBool( node, "active", p_active );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * community
 */
static struct __attrdef RocsWgen_community = {
  "community",  "",  "",  "string",  "public",  "*",  False,
};
static const char* _getcommunity(iONode node) {
  const char* defval = xStr( RocsWgen_community );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_SnmpService, node );
  return NodeOp.getStr( node, "community", defval );
}
static void _setcommunity(iONode node, const char* p_community) {
  if( node == NULL ) return;
  xNode( RocsWgen_SnmpService, node );
  NodeOp.setStr( node, "community", p_community );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * contact
 */
static struct __attrdef RocsWgen_contact = {
  "contact",  "Contact address.",  "",  "string",  "support@rocrail.net",  "*",  False,
};
static const char* _getcontact(iONode node) {
  const char* defval = xStr( RocsWgen_contact );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_SnmpService, node );
  return NodeOp.getStr( node, "contact", defval );
}
static void _setcontact(iONode node, const char* p_contact) {
  if( node == NULL ) return;
  xNode( RocsWgen_SnmpService, node );
  NodeOp.setStr( node, "contact", p_contact );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * description
 */
static struct __attrdef RocsWgen_description = {
  "description",  "Rocrail server description.",  "",  "string",  "Model Railroad Control System",  "*",  False,
};
static const char* _getdescription(iONode node) {
  const char* defval = xStr( RocsWgen_description );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_SnmpService, node );
  return NodeOp.getStr( node, "description", defval );
}
static void _setdescription(iONode node, const char* p_description) {
  if( node == NULL ) return;
  xNode( RocsWgen_SnmpService, node );
  NodeOp.setStr( node, "description", p_description );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * enterprise
 */
static struct __attrdef RocsWgen_enterprise = {
  "enterprise",  "http://www.iana.org/assignments/enterprise-numbers",  "",  "int",  "37707",  "0-*",  False,
};
static int _getenterprise(iONode node) {
  int defval = xInt( RocsWgen_enterprise );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_SnmpService, node );
  return NodeOp.getInt( node, "enterprise", defval );
}
static void _setenterprise(iONode node, int p_enterprise) {
  if( node == NULL ) return;
  xNode( RocsWgen_SnmpService, node );
  NodeOp.setInt( node, "enterprise", p_enterprise );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * family
 */
static struct __attrdef RocsWgen_family = {
  "family",  "Product family; Default Rocrail=1.",  "",  "int",  "1",  "0-65535",  False,
};
static int _getfamily(iONode node) {
  int defval = xInt( RocsWgen_family );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_SnmpService, node );
  return NodeOp.getInt( node, "family", defval );
}
static void _setfamily(iONode node, int p_family) {
  if( node == NULL ) return;
  xNode( RocsWgen_SnmpService, node );
  NodeOp.setInt( node, "family", p_family );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * location
 */
static struct __attrdef RocsWgen_location = {
  "location",  "Rocrail physical location.",  "",  "string",  "local",  "*",  False,
};
static const char* _getlocation(iONode node) {
  const char* defval = xStr( RocsWgen_location );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_SnmpService, node );
  return NodeOp.getStr( node, "location", defval );
}
static void _setlocation(iONode node, const char* p_location) {
  if( node == NULL ) return;
  xNode( RocsWgen_SnmpService, node );
  NodeOp.setStr( node, "location", p_location );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "Port number for server socket.",  "",  "int",  "161",  "0-65535",  False,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_SnmpService, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_SnmpService, node );
  NodeOp.setInt( node, "port", p_port );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * product
 */
static struct __attrdef RocsWgen_product = {
  "product",  "Product; Default Server=1.",  "",  "int",  "1",  "0-65535",  False,
};
static int _getproduct(iONode node) {
  int defval = xInt( RocsWgen_product );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_SnmpService, node );
  return NodeOp.getInt( node, "product", defval );
}
static void _setproduct(iONode node, int p_product) {
  if( node == NULL ) return;
  xNode( RocsWgen_SnmpService, node );
  NodeOp.setInt( node, "product", p_product );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * traphost
 */
static struct __attrdef RocsWgen_traphost = {
  "traphost",  "Trap host.",  "",  "string",  "localhost",  "*",  False,
};
static const char* _gettraphost(iONode node) {
  const char* defval = xStr( RocsWgen_traphost );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_SnmpService, node );
  return NodeOp.getStr( node, "traphost", defval );
}
static void _settraphost(iONode node, const char* p_traphost) {
  if( node == NULL ) return;
  xNode( RocsWgen_SnmpService, node );
  NodeOp.setStr( node, "traphost", p_traphost );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * trapport
 */
static struct __attrdef RocsWgen_trapport = {
  "trapport",  "Trap port number.",  "",  "int",  "0",  "0-65535",  False,
};
static int _gettrapport(iONode node) {
  int defval = xInt( RocsWgen_trapport );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_SnmpService, node );
  return NodeOp.getInt( node, "trapport", defval );
}
static void _settrapport(iONode node, int p_trapport) {
  if( node == NULL ) return;
  xNode( RocsWgen_SnmpService, node );
  NodeOp.setInt( node, "trapport", p_trapport );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * version
 */
static struct __attrdef RocsWgen_version = {
  "version",  "SNMP version.",  "",  "int",  "1",  "0-65535",  False,
};
static int _getversion(iONode node) {
  int defval = xInt( RocsWgen_version );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_SnmpService, node );
  return NodeOp.getInt( node, "version", defval );
}
static void _setversion(iONode node, int p_version) {
  if( node == NULL ) return;
  xNode( RocsWgen_SnmpService, node );
  NodeOp.setInt( node, "version", p_version );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[13] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_SnmpService.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node SnmpService not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node SnmpService not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_active;
  attrList[1] = &RocsWgen_community;
  attrList[2] = &RocsWgen_contact;
  attrList[3] = &RocsWgen_description;
  attrList[4] = &RocsWgen_enterprise;
  attrList[5] = &RocsWgen_family;
  attrList[6] = &RocsWgen_location;
  attrList[7] = &RocsWgen_port;
  attrList[8] = &RocsWgen_product;
  attrList[9] = &RocsWgen_traphost;
  attrList[10] = &RocsWgen_trapport;
  attrList[11] = &RocsWgen_version;
  attrList[12] = NULL;
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


struct __wSnmpService wSnmpService = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "1.3.6.1.4.1.37707.1.1.1.0",
  "1.3.6.1.4.1.37707.1.1.3.0",
  "1.3.6.1.4.1.37707.1.1.5.0",
  "1.3.6.1.4.1.37707.1.1.4.0",
  "1.3.6.1.4.1.37707.1.1.2.0",
  "1.3.6.1.4.1.37707.1.1.10.1.0",
  "1.3.6.1.4.1.37707.1.1.10.2.0",
  "1.3.6.1.4.1.37707.1.1",
  "1.3.6.1.2.1.1.4.0",
  "1.3.6.1.2.1.1.1.0",
  "1.3.6.1.2.1.1.6.0",
  "1.3.6.1.2.1.1.5.0",
  "1.3.6.1.2.1.1.2.0",
  "1.3.6.1.2.1.1.7.0",
  "1.3.6.1.2.1.1.3.0",
  "1.3.6.1.2.1.1",
  "1.3.6.1.6.3.1.1.5.1.0",
  "1.3.6.1.6.3.1.1.5.3.0",
  "1.3.6.1.6.3.1.1.5.4.0",
  _isactive,
  _setactive,
  _getcommunity,
  _setcommunity,
  _getcontact,
  _setcontact,
  _getdescription,
  _setdescription,
  _getenterprise,
  _setenterprise,
  _getfamily,
  _setfamily,
  _getlocation,
  _setlocation,
  _getport,
  _setport,
  _getproduct,
  _setproduct,
  _gettraphost,
  _settraphost,
  _gettrapport,
  _settrapport,
  _getversion,
  _setversion,
  _node_dump,
};
