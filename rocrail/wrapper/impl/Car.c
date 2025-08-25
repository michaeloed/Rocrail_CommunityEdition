/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/Car.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Car
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_car = {
  "car",  "Car definition.",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_car.name;
}
static const char* _node_remark(void) {
  return RocsWgen_car.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_car.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_car.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V_max
 */
static struct __attrdef RocsWgen_V_max = {
  "V_max",  "Maximal car speed.",  "",  "int",  "0",  "*",  False,
};
static int _getV_max(iONode node) {
  int defval = xInt( RocsWgen_V_max );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getInt( node, "V_max", defval );
}
static void _setV_max(iONode node, int p_V_max) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setInt( node, "V_max", p_V_max );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr
 */
static struct __attrdef RocsWgen_addr = {
  "addr",  "Digital address.",  "",  "int",  "0",  "0-*",  False,
};
static int _getaddr(iONode node) {
  int defval = xInt( RocsWgen_addr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getInt( node, "addr", defval );
}
static void _setaddr(iONode node, int p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setInt( node, "addr", p_addr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bus
 */
static struct __attrdef RocsWgen_bus = {
  "bus",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getbus(iONode node) {
  int defval = xInt( RocsWgen_bus );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getInt( node, "bus", defval );
}
static void _setbus(iONode node, int p_bus) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setInt( node, "bus", p_bus );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmd
 */
static struct __attrdef RocsWgen_cmd = {
  "cmd",  "Car command.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getcmd(iONode node) {
  const char* defval = xStr( RocsWgen_cmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * color
 */
static struct __attrdef RocsWgen_color = {
  "color",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getcolor(iONode node) {
  const char* defval = xStr( RocsWgen_color );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "color", defval );
}
static void _setcolor(iONode node, const char* p_color) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "color", p_color );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * commuter
 */
static struct __attrdef RocsWgen_commuter = {
  "commuter",  "Commuter train?",  "",  "bool",  "false",  "",  False,
};
static Boolean _iscommuter(iONode node) {
  Boolean defval = xBool( RocsWgen_commuter );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getBool( node, "commuter", defval );
}
static void _setcommuter(iONode node, Boolean p_commuter) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setBool( node, "commuter", p_commuter );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * decfile
 */
static struct __attrdef RocsWgen_decfile = {
  "decfile",  "Decoder definition file.",  "",  "string",  "nmra-rp922.xml",  "*",  False,
};
static const char* _getdecfile(iONode node) {
  const char* defval = xStr( RocsWgen_decfile );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "decfile", defval );
}
static void _setdecfile(iONode node, const char* p_decfile) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "decfile", p_decfile );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * era
 */
static struct __attrdef RocsWgen_era = {
  "era",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getera(iONode node) {
  int defval = xInt( RocsWgen_era );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getInt( node, "era", defval );
}
static void _setera(iONode node, int p_era) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setInt( node, "era", p_era );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * f0vcmd
 */
static struct __attrdef RocsWgen_f0vcmd = {
  "f0vcmd",  "Use a speed command for F0.",  "",  "bool",  "False",  "",  False,
};
static Boolean _isf0vcmd(iONode node) {
  Boolean defval = xBool( RocsWgen_f0vcmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getBool( node, "f0vcmd", defval );
}
static void _setf0vcmd(iONode node, Boolean p_f0vcmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setBool( node, "f0vcmd", p_f0vcmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fnlights
 */
static struct __attrdef RocsWgen_fnlights = {
  "fnlights",  "Lights function number.",  "",  "int",  "0",  "0-*",  False,
};
static int _getfnlights(iONode node) {
  int defval = xInt( RocsWgen_fnlights );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getInt( node, "fnlights", defval );
}
static void _setfnlights(iONode node, int p_fnlights) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setInt( node, "fnlights", p_fnlights );
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
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ident
 */
static struct __attrdef RocsWgen_ident = {
  "ident",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getident(iONode node) {
  const char* defval = xStr( RocsWgen_ident );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "ident", defval );
}
static void _setident(iONode node, const char* p_ident) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "ident", p_ident );
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
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * image
 */
static struct __attrdef RocsWgen_image = {
  "image",  "image file to show in dialogs",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getimage(iONode node) {
  const char* defval = xStr( RocsWgen_image );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "image", defval );
}
static void _setimage(iONode node, const char* p_image) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "image", p_image );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * invdir
 */
static struct __attrdef RocsWgen_invdir = {
  "invdir",  "Invert direction command.",  "",  "bool",  "False",  "",  False,
};
static Boolean _isinvdir(iONode node) {
  Boolean defval = xBool( RocsWgen_invdir );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getBool( node, "invdir", defval );
}
static void _setinvdir(iONode node, Boolean p_invdir) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setBool( node, "invdir", p_invdir );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * len
 */
static struct __attrdef RocsWgen_len = {
  "len",  "Car lenght.",  "cm",  "int",  "0",  "0-*",  False,
};
static int _getlen(iONode node) {
  int defval = xInt( RocsWgen_len );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getInt( node, "len", defval );
}
static void _setlen(iONode node, int p_len) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setInt( node, "len", p_len );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * location
 */
static struct __attrdef RocsWgen_location = {
  "location",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getlocation(iONode node) {
  const char* defval = xStr( RocsWgen_location );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "location", defval );
}
static void _setlocation(iONode node, const char* p_location) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "location", p_location );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * manuid
 */
static struct __attrdef RocsWgen_manuid = {
  "manuid",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getmanuid(iONode node) {
  const char* defval = xStr( RocsWgen_manuid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "manuid", defval );
}
static void _setmanuid(iONode node, const char* p_manuid) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "manuid", p_manuid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * number
 */
static struct __attrdef RocsWgen_number = {
  "number",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getnumber(iONode node) {
  const char* defval = xStr( RocsWgen_number );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "number", defval );
}
static void _setnumber(iONode node, const char* p_number) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "number", p_number );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * owner
 */
static struct __attrdef RocsWgen_owner = {
  "owner",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getowner(iONode node) {
  const char* defval = xStr( RocsWgen_owner );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "owner", defval );
}
static void _setowner(iONode node, const char* p_owner) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "owner", p_owner );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * placing
 */
static struct __attrdef RocsWgen_placing = {
  "placing",  "",  "",  "bool",  "True",  "",  False,
};
static Boolean _isplacing(iONode node) {
  Boolean defval = xBool( RocsWgen_placing );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getBool( node, "placing", defval );
}
static void _setplacing(iONode node, Boolean p_placing) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setBool( node, "placing", p_placing );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * prevlocation1
 */
static struct __attrdef RocsWgen_prevlocation1 = {
  "prevlocation1",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getprevlocation1(iONode node) {
  const char* defval = xStr( RocsWgen_prevlocation1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "prevlocation1", defval );
}
static void _setprevlocation1(iONode node, const char* p_prevlocation1) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "prevlocation1", p_prevlocation1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * prevlocation2
 */
static struct __attrdef RocsWgen_prevlocation2 = {
  "prevlocation2",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getprevlocation2(iONode node) {
  const char* defval = xStr( RocsWgen_prevlocation2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "prevlocation2", defval );
}
static void _setprevlocation2(iONode node, const char* p_prevlocation2) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "prevlocation2", p_prevlocation2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * prevlocation3
 */
static struct __attrdef RocsWgen_prevlocation3 = {
  "prevlocation3",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getprevlocation3(iONode node) {
  const char* defval = xStr( RocsWgen_prevlocation3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "prevlocation3", defval );
}
static void _setprevlocation3(iONode node, const char* p_prevlocation3) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "prevlocation3", p_prevlocation3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * prot
 */
static struct __attrdef RocsWgen_prot = {
  "prot",  "",  "",  "string",  "P",  "P,M,N,A,C",  False,
};
static const char* _getprot(iONode node) {
  const char* defval = xStr( RocsWgen_prot );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "prot", defval );
}
static void _setprot(iONode node, const char* p_prot) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "prot", p_prot );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * protver
 */
static struct __attrdef RocsWgen_protver = {
  "protver",  "Protocol version",  "",  "int",  "1",  "*",  False,
};
static int _getprotver(iONode node) {
  int defval = xInt( RocsWgen_protver );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getInt( node, "protver", defval );
}
static void _setprotver(iONode node, int p_protver) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setInt( node, "protver", p_protver );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * remark
 */
static struct __attrdef RocsWgen_remark = {
  "remark",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getremark(iONode node) {
  const char* defval = xStr( RocsWgen_remark );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "remark", defval );
}
static void _setremark(iONode node, const char* p_remark) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "remark", p_remark );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * roadname
 */
static struct __attrdef RocsWgen_roadname = {
  "roadname",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getroadname(iONode node) {
  const char* defval = xStr( RocsWgen_roadname );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "roadname", defval );
}
static void _setroadname(iONode node, const char* p_roadname) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "roadname", p_roadname );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * show
 */
static struct __attrdef RocsWgen_show = {
  "show",  "Show in loco table.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isshow(iONode node) {
  Boolean defval = xBool( RocsWgen_show );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getBool( node, "show", defval );
}
static void _setshow(iONode node, Boolean p_show) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setBool( node, "show", p_show );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * status
 */
static struct __attrdef RocsWgen_status = {
  "status",  "Car status.",  "",  "string",  "",  "*",  False,
};
static const char* _getstatus(iONode node) {
  const char* defval = xStr( RocsWgen_status );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "status", defval );
}
static void _setstatus(iONode node, const char* p_status) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "status", p_status );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * subtype
 */
static struct __attrdef RocsWgen_subtype = {
  "subtype",  "Car sub type like Boxcar or gondola.",  "",  "string",  "",  "*",  False,
};
static const char* _getsubtype(iONode node) {
  const char* defval = xStr( RocsWgen_subtype );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "subtype", defval );
}
static void _setsubtype(iONode node, const char* p_subtype) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "subtype", p_subtype );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * type
 */
static struct __attrdef RocsWgen_type = {
  "type",  "Car main type.",  "",  "string",  "freight",  "freight,passenger",  False,
};
static const char* _gettype(iONode node) {
  const char* defval = xStr( RocsWgen_type );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "type", defval );
}
static void _settype(iONode node, const char* p_type) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "type", p_type );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usedir
 */
static struct __attrdef RocsWgen_usedir = {
  "usedir",  "Decoder can process direction command.",  "",  "bool",  "False",  "",  False,
};
static Boolean _isusedir(iONode node) {
  Boolean defval = xBool( RocsWgen_usedir );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getBool( node, "usedir", defval );
}
static void _setusedir(iONode node, Boolean p_usedir) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setBool( node, "usedir", p_usedir );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * uselights
 */
static struct __attrdef RocsWgen_uselights = {
  "uselights",  "Decoder can process direction command.",  "",  "bool",  "False",  "",  False,
};
static Boolean _isuselights(iONode node) {
  Boolean defval = xBool( RocsWgen_uselights );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getBool( node, "uselights", defval );
}
static void _setuselights(iONode node, Boolean p_uselights) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setBool( node, "uselights", p_uselights );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * waybills
 */
static struct __attrdef RocsWgen_waybills = {
  "waybills",  "Option for freight cars; where to go and what to load.",  "",  "string",  "",  "*",  False,
};
static const char* _getwaybills(iONode node) {
  const char* defval = xStr( RocsWgen_waybills );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getStr( node, "waybills", defval );
}
static void _setwaybills(iONode node, const char* p_waybills) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setStr( node, "waybills", p_waybills );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * weight_empty
 */
static struct __attrdef RocsWgen_weight_empty = {
  "weight_empty",  "Car weight empty.",  "ton",  "int",  "0",  "0-*",  False,
};
static int _getweight_empty(iONode node) {
  int defval = xInt( RocsWgen_weight_empty );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getInt( node, "weight_empty", defval );
}
static void _setweight_empty(iONode node, int p_weight_empty) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setInt( node, "weight_empty", p_weight_empty );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * weight_loaded
 */
static struct __attrdef RocsWgen_weight_loaded = {
  "weight_loaded",  "Car weight loaded.",  "ton",  "int",  "0",  "0-*",  False,
};
static int _getweight_loaded(iONode node) {
  int defval = xInt( RocsWgen_weight_loaded );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_car, node );
  return NodeOp.getInt( node, "weight_loaded", defval );
}
static void _setweight_loaded(iONode node, int p_weight_loaded) {
  if( node == NULL ) return;
  xNode( RocsWgen_car, node );
  NodeOp.setInt( node, "weight_loaded", p_weight_loaded );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * cvbyte
 */
static struct __nodedef RocsWgen_cvbyte = {
  "cvbyte",  "",  False,  "n",};
static iONode _getcvbyte(iONode node) {
  xNode( RocsWgen_car, node );
  return NodeOp.findNode( node, "cvbyte");
}


static iONode _nextcvbyte(iONode node, iONode child) {
  xNode( RocsWgen_car, node );
  return NodeOp.findNextNode( node, child);
}
static void _setcvbyte(iONode node, iONode p_cvbyte) {
  xNode( RocsWgen_car, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * fundef
 */
static struct __nodedef RocsWgen_fundef = {
  "fundef",  "",  False,  "n",};
static iONode _getfundef(iONode node) {
  xNode( RocsWgen_car, node );
  return NodeOp.findNode( node, "fundef");
}


static iONode _nextfundef(iONode node, iONode child) {
  xNode( RocsWgen_car, node );
  return NodeOp.findNextNode( node, child);
}
static void _setfundef(iONode node, iONode p_fundef) {
  xNode( RocsWgen_car, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[38] = {NULL};
static struct __nodedef* nodeList[3] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_car.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node car not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node car not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_V_max;
  attrList[1] = &RocsWgen_addr;
  attrList[2] = &RocsWgen_bus;
  attrList[3] = &RocsWgen_cmd;
  attrList[4] = &RocsWgen_color;
  attrList[5] = &RocsWgen_commuter;
  attrList[6] = &RocsWgen_decfile;
  attrList[7] = &RocsWgen_era;
  attrList[8] = &RocsWgen_f0vcmd;
  attrList[9] = &RocsWgen_fnlights;
  attrList[10] = &RocsWgen_id;
  attrList[11] = &RocsWgen_ident;
  attrList[12] = &RocsWgen_iid;
  attrList[13] = &RocsWgen_image;
  attrList[14] = &RocsWgen_invdir;
  attrList[15] = &RocsWgen_len;
  attrList[16] = &RocsWgen_location;
  attrList[17] = &RocsWgen_manuid;
  attrList[18] = &RocsWgen_number;
  attrList[19] = &RocsWgen_owner;
  attrList[20] = &RocsWgen_placing;
  attrList[21] = &RocsWgen_prevlocation1;
  attrList[22] = &RocsWgen_prevlocation2;
  attrList[23] = &RocsWgen_prevlocation3;
  attrList[24] = &RocsWgen_prot;
  attrList[25] = &RocsWgen_protver;
  attrList[26] = &RocsWgen_remark;
  attrList[27] = &RocsWgen_roadname;
  attrList[28] = &RocsWgen_show;
  attrList[29] = &RocsWgen_status;
  attrList[30] = &RocsWgen_subtype;
  attrList[31] = &RocsWgen_type;
  attrList[32] = &RocsWgen_usedir;
  attrList[33] = &RocsWgen_uselights;
  attrList[34] = &RocsWgen_waybills;
  attrList[35] = &RocsWgen_weight_empty;
  attrList[36] = &RocsWgen_weight_loaded;
  attrList[37] = NULL;
  nodeList[0] = &RocsWgen_cvbyte;
  nodeList[1] = &RocsWgen_fundef;
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


struct __wCar wCar = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "goods",
  "passenger",
  "autocarrier",
  "autorack",
  "boxcar",
  "caboose",
  "coilcar",
  "flatcar",
  "gondola",
  "hopper",
  "logdumpcar",
  "reefer",
  "stockcar",
  "tankcar",
  "wellcar",
  "baggage",
  "coach",
  "dinner",
  "dome",
  "express",
  "lounge",
  "postoffice",
  "sleeper",
  "empty",
  "loaded",
  "maintenance",
  _getV_max,
  _setV_max,
  _getaddr,
  _setaddr,
  _getbus,
  _setbus,
  _getcmd,
  _setcmd,
  _getcolor,
  _setcolor,
  _iscommuter,
  _setcommuter,
  _getdecfile,
  _setdecfile,
  _getera,
  _setera,
  _isf0vcmd,
  _setf0vcmd,
  _getfnlights,
  _setfnlights,
  _getid,
  _setid,
  _getident,
  _setident,
  _getiid,
  _setiid,
  _getimage,
  _setimage,
  _isinvdir,
  _setinvdir,
  _getlen,
  _setlen,
  _getlocation,
  _setlocation,
  _getmanuid,
  _setmanuid,
  _getnumber,
  _setnumber,
  _getowner,
  _setowner,
  _isplacing,
  _setplacing,
  _getprevlocation1,
  _setprevlocation1,
  _getprevlocation2,
  _setprevlocation2,
  _getprevlocation3,
  _setprevlocation3,
  _getprot,
  _setprot,
  _getprotver,
  _setprotver,
  _getremark,
  _setremark,
  _getroadname,
  _setroadname,
  _isshow,
  _setshow,
  _getstatus,
  _setstatus,
  _getsubtype,
  _setsubtype,
  _gettype,
  _settype,
  _isusedir,
  _setusedir,
  _isuselights,
  _setuselights,
  _getwaybills,
  _setwaybills,
  _getweight_empty,
  _setweight_empty,
  _getweight_loaded,
  _setweight_loaded,
  _getcvbyte,
  _nextcvbyte,
  _setcvbyte,
  _getfundef,
  _nextfundef,
  _setfundef,
  _node_dump,
};
