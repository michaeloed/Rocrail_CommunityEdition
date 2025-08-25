/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Feedback.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Feedback
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_fb = {
  "fb",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_fb.name;
}
static const char* _node_remark(void) {
  return RocsWgen_fb.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_fb.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_fb.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * accnr
 */
static struct __attrdef RocsWgen_accnr = {
  "accnr",  "Accessory number.",  "",  "int",  "0",  "0-*",  False,
};
static int _getaccnr(iONode node) {
  int defval = xInt( RocsWgen_accnr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "accnr", defval );
}
static void _setaccnr(iONode node, int p_accnr) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "accnr", p_accnr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * activelow
 */
static struct __attrdef RocsWgen_activelow = {
  "activelow",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isactivelow(iONode node) {
  Boolean defval = xBool( RocsWgen_activelow );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getBool( node, "activelow", defval );
}
static void _setactivelow(iONode node, Boolean p_activelow) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setBool( node, "activelow", p_activelow );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr
 */
static struct __attrdef RocsWgen_addr = {
  "addr",  "address",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr(iONode node) {
  int defval = xInt( RocsWgen_addr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "addr", defval );
}
static void _setaddr(iONode node, int p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "addr", p_addr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blockid
 */
static struct __attrdef RocsWgen_blockid = {
  "blockid",  "",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getblockid(iONode node) {
  const char* defval = xStr( RocsWgen_blockid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getStr( node, "blockid", defval );
}
static void _setblockid(iONode node, const char* p_blockid) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setStr( node, "blockid", p_blockid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bus
 */
static struct __attrdef RocsWgen_bus = {
  "bus",  "Some systems support more than one bus: SLX",  "",  "int",  "0",  "0-*",  False,
};
static int _getbus(iONode node) {
  int defval = xInt( RocsWgen_bus );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "bus", defval );
}
static void _setbus(iONode node, int p_bus) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "bus", p_bus );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * carcount
 */
static struct __attrdef RocsWgen_carcount = {
  "carcount",  "car counter (only for client info)",  "",  "int",  "0",  "",  False,
};
static int _getcarcount(iONode node) {
  int defval = xInt( RocsWgen_carcount );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "carcount", defval );
}
static void _setcarcount(iONode node, int p_carcount) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "carcount", p_carcount );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * category
 */
static struct __attrdef RocsWgen_category = {
  "category",  "Train category.",  "",  "int",  "0",  "",  False,
};
static int _getcategory(iONode node) {
  int defval = xInt( RocsWgen_category );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "category", defval );
}
static void _setcategory(iONode node, int p_category) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "category", p_category );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmd
 */
static struct __attrdef RocsWgen_cmd = {
  "cmd",  "",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getcmd(iONode node) {
  const char* defval = xStr( RocsWgen_cmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setStr( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * countedcars
 */
static struct __attrdef RocsWgen_countedcars = {
  "countedcars",  "number of cars to count before firing the event. (only for client info)",  "",  "int",  "0",  "",  False,
};
static int _getcountedcars(iONode node) {
  int defval = xInt( RocsWgen_countedcars );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "countedcars", defval );
}
static void _setcountedcars(iONode node, int p_countedcars) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "countedcars", p_countedcars );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * counter
 */
static struct __attrdef RocsWgen_counter = {
  "counter",  "occupied counter",  "",  "int",  "0",  "",  False,
};
static int _getcounter(iONode node) {
  int defval = xInt( RocsWgen_counter );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "counter", defval );
}
static void _setcounter(iONode node, int p_counter) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "counter", p_counter );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcaddr
 */
static struct __attrdef RocsWgen_ctcaddr = {
  "ctcaddr",  "address",  "",  "int",  "0",  "0-*",  True,
};
static int _getctcaddr(iONode node) {
  int defval = xInt( RocsWgen_ctcaddr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "ctcaddr", defval );
}
static void _setctcaddr(iONode node, int p_ctcaddr) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "ctcaddr", p_ctcaddr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcasswitch
 */
static struct __attrdef RocsWgen_ctcasswitch = {
  "ctcasswitch",  "send a switch command",  "",  "bool",  "false",  "",  False,
};
static Boolean _isctcasswitch(iONode node) {
  Boolean defval = xBool( RocsWgen_ctcasswitch );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getBool( node, "ctcasswitch", defval );
}
static void _setctcasswitch(iONode node, Boolean p_ctcasswitch) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setBool( node, "ctcasswitch", p_ctcasswitch );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcbus
 */
static struct __attrdef RocsWgen_ctcbus = {
  "ctcbus",  "Some systems support more than one bus: SLX",  "",  "int",  "0",  "0-*",  False,
};
static int _getctcbus(iONode node) {
  int defval = xInt( RocsWgen_ctcbus );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "ctcbus", defval );
}
static void _setctcbus(iONode node, int p_ctcbus) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "ctcbus", p_ctcbus );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcgate
 */
static struct __attrdef RocsWgen_ctcgate = {
  "ctcgate",  "gate of port.",  "",  "int",  "0",  "0-1",  True,
};
static int _getctcgate(iONode node) {
  int defval = xInt( RocsWgen_ctcgate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "ctcgate", defval );
}
static void _setctcgate(iONode node, int p_ctcgate) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "ctcgate", p_ctcgate );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctciid
 */
static struct __attrdef RocsWgen_ctciid = {
  "ctciid",  "Interface ID.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getctciid(iONode node) {
  const char* defval = xStr( RocsWgen_ctciid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getStr( node, "ctciid", defval );
}
static void _setctciid(iONode node, const char* p_ctciid) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setStr( node, "ctciid", p_ctciid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcport
 */
static struct __attrdef RocsWgen_ctcport = {
  "ctcport",  "port of decoder module: 0 = not used.",  "",  "int",  "0",  "0-4",  True,
};
static int _getctcport(iONode node) {
  int defval = xInt( RocsWgen_ctcport );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "ctcport", defval );
}
static void _setctcport(iONode node, int p_ctcport) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "ctcport", p_ctcport );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * curve
 */
static struct __attrdef RocsWgen_curve = {
  "curve",  "Curved feedback track.",  "",  "bool",  "false",  "",  False,
};
static Boolean _iscurve(iONode node) {
  Boolean defval = xBool( RocsWgen_curve );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getBool( node, "curve", defval );
}
static void _setcurve(iONode node, Boolean p_curve) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setBool( node, "curve", p_curve );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cutoutaddr
 */
static struct __attrdef RocsWgen_cutoutaddr = {
  "cutoutaddr",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getcutoutaddr(iONode node) {
  int defval = xInt( RocsWgen_cutoutaddr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "cutoutaddr", defval );
}
static void _setcutoutaddr(iONode node, int p_cutoutaddr) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "cutoutaddr", p_cutoutaddr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cutoutbus
 */
static struct __attrdef RocsWgen_cutoutbus = {
  "cutoutbus",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getcutoutbus(iONode node) {
  int defval = xInt( RocsWgen_cutoutbus );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "cutoutbus", defval );
}
static void _setcutoutbus(iONode node, int p_cutoutbus) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "cutoutbus", p_cutoutbus );
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
  xNode( RocsWgen_fb, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * direction
 */
static struct __attrdef RocsWgen_direction = {
  "direction",  "Loc identifier direction",  "",  "bool",  "true",  "",  False,
};
static Boolean _isdirection(iONode node) {
  Boolean defval = xBool( RocsWgen_direction );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getBool( node, "direction", defval );
}
static void _setdirection(iONode node, Boolean p_direction) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setBool( node, "direction", p_direction );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbtype
 */
static struct __attrdef RocsWgen_fbtype = {
  "fbtype",  "feedback type reported by the device",  "",  "int",  "0",  "",  False,
};
static int _getfbtype(iONode node) {
  int defval = xInt( RocsWgen_fbtype );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "fbtype", defval );
}
static void _setfbtype(iONode node, int p_fbtype) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "fbtype", p_fbtype );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gpssid
 */
static struct __attrdef RocsWgen_gpssid = {
  "gpssid",  "SendID.",  "",  "int",  "0",  "0-*",  False,
};
static int _getgpssid(iONode node) {
  int defval = xInt( RocsWgen_gpssid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "gpssid", defval );
}
static void _setgpssid(iONode node, int p_gpssid) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "gpssid", p_gpssid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gpstime
 */
static struct __attrdef RocsWgen_gpstime = {
  "gpstime",  "Time in ms.",  "",  "int",  "0",  "0-*",  False,
};
static int _getgpstime(iONode node) {
  int defval = xInt( RocsWgen_gpstime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "gpstime", defval );
}
static void _setgpstime(iONode node, int p_gpstime) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "gpstime", p_gpstime );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gpstolx
 */
static struct __attrdef RocsWgen_gpstolx = {
  "gpstolx",  "Tolerance.",  "",  "int",  "0",  "0-*",  False,
};
static int _getgpstolx(iONode node) {
  int defval = xInt( RocsWgen_gpstolx );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "gpstolx", defval );
}
static void _setgpstolx(iONode node, int p_gpstolx) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "gpstolx", p_gpstolx );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gpstoly
 */
static struct __attrdef RocsWgen_gpstoly = {
  "gpstoly",  "Tolerance.",  "",  "int",  "0",  "0-*",  False,
};
static int _getgpstoly(iONode node) {
  int defval = xInt( RocsWgen_gpstoly );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "gpstoly", defval );
}
static void _setgpstoly(iONode node, int p_gpstoly) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "gpstoly", p_gpstoly );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gpstolz
 */
static struct __attrdef RocsWgen_gpstolz = {
  "gpstolz",  "Tolerance.",  "",  "int",  "0",  "0-*",  False,
};
static int _getgpstolz(iONode node) {
  int defval = xInt( RocsWgen_gpstolz );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "gpstolz", defval );
}
static void _setgpstolz(iONode node, int p_gpstolz) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "gpstolz", p_gpstolz );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gpsx
 */
static struct __attrdef RocsWgen_gpsx = {
  "gpsx",  "X-Position in the plan.",  "",  "int",  "0",  "0-*",  False,
};
static int _getgpsx(iONode node) {
  int defval = xInt( RocsWgen_gpsx );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "gpsx", defval );
}
static void _setgpsx(iONode node, int p_gpsx) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "gpsx", p_gpsx );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gpsy
 */
static struct __attrdef RocsWgen_gpsy = {
  "gpsy",  "Y-Position in the plan.",  "",  "int",  "0",  "0-*",  False,
};
static int _getgpsy(iONode node) {
  int defval = xInt( RocsWgen_gpsy );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "gpsy", defval );
}
static void _setgpsy(iONode node, int p_gpsy) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "gpsy", p_gpsy );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gpsz
 */
static struct __attrdef RocsWgen_gpsz = {
  "gpsz",  "Z-Position in the plan.",  "",  "int",  "0",  "0-*",  False,
};
static int _getgpsz(iONode node) {
  int defval = xInt( RocsWgen_gpsz );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "gpsz", defval );
}
static void _setgpsz(iONode node, int p_gpsz) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "gpsz", p_gpsz );
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
  xNode( RocsWgen_fb, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * identifier
 */
static struct __attrdef RocsWgen_identifier = {
  "identifier",  "Loc identifier 1",  "",  "string",  "",  "",  False,
};
static const char* _getidentifier(iONode node) {
  const char* defval = xStr( RocsWgen_identifier );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getStr( node, "identifier", defval );
}
static void _setidentifier(iONode node, const char* p_identifier) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setStr( node, "identifier", p_identifier );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * identifier2
 */
static struct __attrdef RocsWgen_identifier2 = {
  "identifier2",  "Loc identifier 2",  "",  "string",  "",  "",  False,
};
static const char* _getidentifier2(iONode node) {
  const char* defval = xStr( RocsWgen_identifier2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getStr( node, "identifier2", defval );
}
static void _setidentifier2(iONode node, const char* p_identifier2) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setStr( node, "identifier2", p_identifier2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * identifier3
 */
static struct __attrdef RocsWgen_identifier3 = {
  "identifier3",  "Loc identifier 3",  "",  "string",  "",  "",  False,
};
static const char* _getidentifier3(iONode node) {
  const char* defval = xStr( RocsWgen_identifier3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getStr( node, "identifier3", defval );
}
static void _setidentifier3(iONode node, const char* p_identifier3) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setStr( node, "identifier3", p_identifier3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * identifier4
 */
static struct __attrdef RocsWgen_identifier4 = {
  "identifier4",  "Loc identifier 4",  "",  "string",  "",  "",  False,
};
static const char* _getidentifier4(iONode node) {
  const char* defval = xStr( RocsWgen_identifier4 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getStr( node, "identifier4", defval );
}
static void _setidentifier4(iONode node, const char* p_identifier4) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setStr( node, "identifier4", p_identifier4 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iid
 */
static struct __attrdef RocsWgen_iid = {
  "iid",  "Interface ID.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getiid(iONode node) {
  const char* defval = xStr( RocsWgen_iid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * info
 */
static struct __attrdef RocsWgen_info = {
  "info",  "extra information",  "",  "string",  "",  "",  False,
};
static const char* _getinfo(iONode node) {
  const char* defval = xStr( RocsWgen_info );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getStr( node, "info", defval );
}
static void _setinfo(iONode node, const char* p_info) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setStr( node, "info", p_info );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * load
 */
static struct __attrdef RocsWgen_load = {
  "load",  "current",  "",  "int",  "0",  "",  False,
};
static int _getload(iONode node) {
  int defval = xInt( RocsWgen_load );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "load", defval );
}
static void _setload(iONode node, int p_load) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "load", p_load );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * locoid
 */
static struct __attrdef RocsWgen_locoid = {
  "locoid",  "",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getlocoid(iONode node) {
  const char* defval = xStr( RocsWgen_locoid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getStr( node, "locoid", defval );
}
static void _setlocoid(iONode node, const char* p_locoid) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setStr( node, "locoid", p_locoid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * maxload
 */
static struct __attrdef RocsWgen_maxload = {
  "maxload",  "",  "",  "int",  "0",  "",  False,
};
static int _getmaxload(iONode node) {
  int defval = xInt( RocsWgen_maxload );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "maxload", defval );
}
static void _setmaxload(iONode node, int p_maxload) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "maxload", p_maxload );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * oid
 */
static struct __attrdef RocsWgen_oid = {
  "oid",  "object ID",  "",  "string",  "",  "*",  False,
};
static const char* _getoid(iONode node) {
  const char* defval = xStr( RocsWgen_oid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getStr( node, "oid", defval );
}
static void _setoid(iONode node, const char* p_oid) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setStr( node, "oid", p_oid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ori
 */
static struct __attrdef RocsWgen_ori = {
  "ori",  "Orientation in the plan.",  "",  "string",  "NULL",  "north,south,west,east",  False,
};
static const char* _getori(iONode node) {
  const char* defval = xStr( RocsWgen_ori );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getStr( node, "ori", defval );
}
static void _setori(iONode node, const char* p_ori) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setStr( node, "ori", p_ori );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * resetwc
 */
static struct __attrdef RocsWgen_resetwc = {
  "resetwc",  "Send a reset commando in case of a wheel counter type.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isresetwc(iONode node) {
  Boolean defval = xBool( RocsWgen_resetwc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getBool( node, "resetwc", defval );
}
static void _setresetwc(iONode node, Boolean p_resetwc) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setBool( node, "resetwc", p_resetwc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * shortcut
 */
static struct __attrdef RocsWgen_shortcut = {
  "shortcut",  "Shortcut reported by the cutout sensor; Red background in Rocview.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isshortcut(iONode node) {
  Boolean defval = xBool( RocsWgen_shortcut );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getBool( node, "shortcut", defval );
}
static void _setshortcut(iONode node, Boolean p_shortcut) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setBool( node, "shortcut", p_shortcut );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * show
 */
static struct __attrdef RocsWgen_show = {
  "show",  "Visibility flag.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isshow(iONode node) {
  Boolean defval = xBool( RocsWgen_show );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getBool( node, "show", defval );
}
static void _setshow(iONode node, Boolean p_show) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setBool( node, "show", p_show );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * signal
 */
static struct __attrdef RocsWgen_signal = {
  "signal",  "signal quality: 0=OK",  "",  "int",  "0",  "",  False,
};
static int _getsignal(iONode node) {
  int defval = xInt( RocsWgen_signal );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "signal", defval );
}
static void _setsignal(iONode node, int p_signal) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "signal", p_signal );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * state
 */
static struct __attrdef RocsWgen_state = {
  "state",  "Current feedback state.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isstate(iONode node) {
  Boolean defval = xBool( RocsWgen_state );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getBool( node, "state", defval );
}
static void _setstate(iONode node, Boolean p_state) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setBool( node, "state", p_state );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timer
 */
static struct __attrdef RocsWgen_timer = {
  "timer",  "Delayed off timer in 100ms units.",  "",  "int",  "0",  "0-100",  False,
};
static int _gettimer(iONode node) {
  int defval = xInt( RocsWgen_timer );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "timer", defval );
}
static void _settimer(iONode node, int p_timer) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "timer", p_timer );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val
 */
static struct __attrdef RocsWgen_val = {
  "val",  "multiple port value",  "",  "int",  "0",  "",  False,
};
static int _getval(iONode node) {
  int defval = xInt( RocsWgen_val );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "val", defval );
}
static void _setval(iONode node, int p_val) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "val", p_val );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * wheelcount
 */
static struct __attrdef RocsWgen_wheelcount = {
  "wheelcount",  "counted wheels; sofar",  "",  "int",  "0",  "",  False,
};
static int _getwheelcount(iONode node) {
  int defval = xInt( RocsWgen_wheelcount );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "wheelcount", defval );
}
static void _setwheelcount(iONode node, int p_wheelcount) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "wheelcount", p_wheelcount );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * x
 */
static struct __attrdef RocsWgen_x = {
  "x",  "X-Position in the plan.",  "",  "int",  "0",  "0-*",  False,
};
static int _getx(iONode node) {
  int defval = xInt( RocsWgen_x );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "x", defval );
}
static void _setx(iONode node, int p_x) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "x", p_x );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * y
 */
static struct __attrdef RocsWgen_y = {
  "y",  "Y-Position in the plan.",  "",  "int",  "0",  "0-*",  False,
};
static int _gety(iONode node) {
  int defval = xInt( RocsWgen_y );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "y", defval );
}
static void _sety(iONode node, int p_y) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "y", p_y );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * z
 */
static struct __attrdef RocsWgen_z = {
  "z",  "Z-Position in the plan. (level)",  "",  "int",  "0",  "0-9",  False,
};
static int _getz(iONode node) {
  int defval = xInt( RocsWgen_z );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getInt( node, "z", defval );
}
static void _setz(iONode node, int p_z) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setInt( node, "z", p_z );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * zone
 */
static struct __attrdef RocsWgen_zone = {
  "zone",  "transponder zone",  "",  "string",  "",  "",  False,
};
static const char* _getzone(iONode node) {
  const char* defval = xStr( RocsWgen_zone );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_fb, node );
  return NodeOp.getStr( node, "zone", defval );
}
static void _setzone(iONode node, const char* p_zone) {
  if( node == NULL ) return;
  xNode( RocsWgen_fb, node );
  NodeOp.setStr( node, "zone", p_zone );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * actionctrl
 */
static struct __nodedef RocsWgen_actionctrl = {
  "actionctrl",  "",  False,  "n",};
static iONode _getactionctrl(iONode node) {
  xNode( RocsWgen_fb, node );
  return NodeOp.findNode( node, "actionctrl");
}


static iONode _nextactionctrl(iONode node, iONode child) {
  xNode( RocsWgen_fb, node );
  return NodeOp.findNextNode( node, child);
}
static void _setactionctrl(iONode node, iONode p_actionctrl) {
  xNode( RocsWgen_fb, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * fbstatistic
 */
static struct __nodedef RocsWgen_fbstatistic = {
  "fbstatistic",  "",  False,  "n",};
static iONode _getfbstatistic(iONode node) {
  xNode( RocsWgen_fb, node );
  return NodeOp.findNode( node, "fbstatistic");
}


static iONode _nextfbstatistic(iONode node, iONode child) {
  xNode( RocsWgen_fb, node );
  return NodeOp.findNextNode( node, child);
}
static void _setfbstatistic(iONode node, iONode p_fbstatistic) {
  xNode( RocsWgen_fb, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[55] = {NULL};
static struct __nodedef* nodeList[3] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_fb.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node fb not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node fb not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_accnr;
  attrList[1] = &RocsWgen_activelow;
  attrList[2] = &RocsWgen_addr;
  attrList[3] = &RocsWgen_blockid;
  attrList[4] = &RocsWgen_bus;
  attrList[5] = &RocsWgen_carcount;
  attrList[6] = &RocsWgen_category;
  attrList[7] = &RocsWgen_cmd;
  attrList[8] = &RocsWgen_countedcars;
  attrList[9] = &RocsWgen_counter;
  attrList[10] = &RocsWgen_ctcaddr;
  attrList[11] = &RocsWgen_ctcasswitch;
  attrList[12] = &RocsWgen_ctcbus;
  attrList[13] = &RocsWgen_ctcgate;
  attrList[14] = &RocsWgen_ctciid;
  attrList[15] = &RocsWgen_ctcport;
  attrList[16] = &RocsWgen_curve;
  attrList[17] = &RocsWgen_cutoutaddr;
  attrList[18] = &RocsWgen_cutoutbus;
  attrList[19] = &RocsWgen_desc;
  attrList[20] = &RocsWgen_direction;
  attrList[21] = &RocsWgen_fbtype;
  attrList[22] = &RocsWgen_gpssid;
  attrList[23] = &RocsWgen_gpstime;
  attrList[24] = &RocsWgen_gpstolx;
  attrList[25] = &RocsWgen_gpstoly;
  attrList[26] = &RocsWgen_gpstolz;
  attrList[27] = &RocsWgen_gpsx;
  attrList[28] = &RocsWgen_gpsy;
  attrList[29] = &RocsWgen_gpsz;
  attrList[30] = &RocsWgen_id;
  attrList[31] = &RocsWgen_identifier;
  attrList[32] = &RocsWgen_identifier2;
  attrList[33] = &RocsWgen_identifier3;
  attrList[34] = &RocsWgen_identifier4;
  attrList[35] = &RocsWgen_iid;
  attrList[36] = &RocsWgen_info;
  attrList[37] = &RocsWgen_load;
  attrList[38] = &RocsWgen_locoid;
  attrList[39] = &RocsWgen_maxload;
  attrList[40] = &RocsWgen_oid;
  attrList[41] = &RocsWgen_ori;
  attrList[42] = &RocsWgen_resetwc;
  attrList[43] = &RocsWgen_shortcut;
  attrList[44] = &RocsWgen_show;
  attrList[45] = &RocsWgen_signal;
  attrList[46] = &RocsWgen_state;
  attrList[47] = &RocsWgen_timer;
  attrList[48] = &RocsWgen_val;
  attrList[49] = &RocsWgen_wheelcount;
  attrList[50] = &RocsWgen_x;
  attrList[51] = &RocsWgen_y;
  attrList[52] = &RocsWgen_z;
  attrList[53] = &RocsWgen_zone;
  attrList[54] = NULL;
  nodeList[0] = &RocsWgen_actionctrl;
  nodeList[1] = &RocsWgen_fbstatistic;
  nodeList[2] = NULL;
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


struct __wFeedback wFeedback = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  3,
  7,
  1,
  4,
  5,
  0,
  2,
  6,
  "reset",
  "resetstatus",
  "setcounterval",
  "signalquality",
  _getaccnr,
  _setaccnr,
  _isactivelow,
  _setactivelow,
  _getaddr,
  _setaddr,
  _getblockid,
  _setblockid,
  _getbus,
  _setbus,
  _getcarcount,
  _setcarcount,
  _getcategory,
  _setcategory,
  _getcmd,
  _setcmd,
  _getcountedcars,
  _setcountedcars,
  _getcounter,
  _setcounter,
  _getctcaddr,
  _setctcaddr,
  _isctcasswitch,
  _setctcasswitch,
  _getctcbus,
  _setctcbus,
  _getctcgate,
  _setctcgate,
  _getctciid,
  _setctciid,
  _getctcport,
  _setctcport,
  _iscurve,
  _setcurve,
  _getcutoutaddr,
  _setcutoutaddr,
  _getcutoutbus,
  _setcutoutbus,
  _getdesc,
  _setdesc,
  _isdirection,
  _setdirection,
  _getfbtype,
  _setfbtype,
  _getgpssid,
  _setgpssid,
  _getgpstime,
  _setgpstime,
  _getgpstolx,
  _setgpstolx,
  _getgpstoly,
  _setgpstoly,
  _getgpstolz,
  _setgpstolz,
  _getgpsx,
  _setgpsx,
  _getgpsy,
  _setgpsy,
  _getgpsz,
  _setgpsz,
  _getid,
  _setid,
  _getidentifier,
  _setidentifier,
  _getidentifier2,
  _setidentifier2,
  _getidentifier3,
  _setidentifier3,
  _getidentifier4,
  _setidentifier4,
  _getiid,
  _setiid,
  _getinfo,
  _setinfo,
  _getload,
  _setload,
  _getlocoid,
  _setlocoid,
  _getmaxload,
  _setmaxload,
  _getoid,
  _setoid,
  _getori,
  _setori,
  _isresetwc,
  _setresetwc,
  _isshortcut,
  _setshortcut,
  _isshow,
  _setshow,
  _getsignal,
  _setsignal,
  _isstate,
  _setstate,
  _gettimer,
  _settimer,
  _getval,
  _setval,
  _getwheelcount,
  _setwheelcount,
  _getx,
  _setx,
  _gety,
  _sety,
  _getz,
  _setz,
  _getzone,
  _setzone,
  _getactionctrl,
  _nextactionctrl,
  _setactionctrl,
  _getfbstatistic,
  _nextfbstatistic,
  _setfbstatistic,
  _node_dump,
};
