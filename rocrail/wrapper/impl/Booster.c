/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Booster.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Booster
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_booster = {
  "booster",  "Booster definition",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_booster.name;
}
static const char* _node_remark(void) {
  return RocsWgen_booster.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_booster.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_booster.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blockids
 */
static struct __attrdef RocsWgen_blockids = {
  "blockids",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getblockids(iONode node) {
  const char* defval = xStr( RocsWgen_blockids );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_booster, node );
  return NodeOp.getStr( node, "blockids", defval );
}
static void _setblockids(iONode node, const char* p_blockids) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setStr( node, "blockids", p_blockids );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * district
 */
static struct __attrdef RocsWgen_district = {
  "district",  "Power district description.",  "",  "string",  "",  "*",  False,
};
static const char* _getdistrict(iONode node) {
  const char* defval = xStr( RocsWgen_district );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_booster, node );
  return NodeOp.getStr( node, "district", defval );
}
static void _setdistrict(iONode node, const char* p_district) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setStr( node, "district", p_district );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * doesreport
 */
static struct __attrdef RocsWgen_doesreport = {
  "doesreport",  "Booster report status.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isdoesreport(iONode node) {
  Boolean defval = xBool( RocsWgen_doesreport );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_booster, node );
  return NodeOp.getBool( node, "doesreport", defval );
}
static void _setdoesreport(iONode node, Boolean p_doesreport) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setBool( node, "doesreport", p_doesreport );
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
  xNode( RocsWgen_booster, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setStr( node, "id", p_id );
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
  xNode( RocsWgen_booster, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * load
 */
static struct __attrdef RocsWgen_load = {
  "load",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getload(iONode node) {
  int defval = xInt( RocsWgen_load );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_booster, node );
  return NodeOp.getInt( node, "load", defval );
}
static void _setload(iONode node, int p_load) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setInt( node, "load", p_load );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * loadmax
 */
static struct __attrdef RocsWgen_loadmax = {
  "loadmax",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getloadmax(iONode node) {
  int defval = xInt( RocsWgen_loadmax );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_booster, node );
  return NodeOp.getInt( node, "loadmax", defval );
}
static void _setloadmax(iONode node, int p_loadmax) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setInt( node, "loadmax", p_loadmax );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * modids
 */
static struct __attrdef RocsWgen_modids = {
  "modids",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getmodids(iONode node) {
  const char* defval = xStr( RocsWgen_modids );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_booster, node );
  return NodeOp.getStr( node, "modids", defval );
}
static void _setmodids(iONode node, const char* p_modids) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setStr( node, "modids", p_modids );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * power
 */
static struct __attrdef RocsWgen_power = {
  "power",  "Track power flag.",  "",  "bool",  "false",  "",  False,
};
static Boolean _ispower(iONode node) {
  Boolean defval = xBool( RocsWgen_power );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_booster, node );
  return NodeOp.getBool( node, "power", defval );
}
static void _setpower(iONode node, Boolean p_power) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setBool( node, "power", p_power );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * powerfb
 */
static struct __attrdef RocsWgen_powerfb = {
  "powerfb",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getpowerfb(iONode node) {
  const char* defval = xStr( RocsWgen_powerfb );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_booster, node );
  return NodeOp.getStr( node, "powerfb", defval );
}
static void _setpowerfb(iONode node, const char* p_powerfb) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setStr( node, "powerfb", p_powerfb );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * powersw
 */
static struct __attrdef RocsWgen_powersw = {
  "powersw",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getpowersw(iONode node) {
  const char* defval = xStr( RocsWgen_powersw );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_booster, node );
  return NodeOp.getStr( node, "powersw", defval );
}
static void _setpowersw(iONode node, const char* p_powersw) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setStr( node, "powersw", p_powersw );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * scfb
 */
static struct __attrdef RocsWgen_scfb = {
  "scfb",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getscfb(iONode node) {
  const char* defval = xStr( RocsWgen_scfb );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_booster, node );
  return NodeOp.getStr( node, "scfb", defval );
}
static void _setscfb(iONode node, const char* p_scfb) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setStr( node, "scfb", p_scfb );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * scopt_poweroffall
 */
static struct __attrdef RocsWgen_scopt_poweroffall = {
  "scopt_poweroffall",  "Power off all boosters at shortcut.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isscopt_poweroffall(iONode node) {
  Boolean defval = xBool( RocsWgen_scopt_poweroffall );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_booster, node );
  return NodeOp.getBool( node, "scopt_poweroffall", defval );
}
static void _setscopt_poweroffall(iONode node, Boolean p_scopt_poweroffall) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setBool( node, "scopt_poweroffall", p_scopt_poweroffall );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * scopt_repoweron
 */
static struct __attrdef RocsWgen_scopt_repoweron = {
  "scopt_repoweron",  "Repower on incase the shortcut is cleared.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isscopt_repoweron(iONode node) {
  Boolean defval = xBool( RocsWgen_scopt_repoweron );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_booster, node );
  return NodeOp.getBool( node, "scopt_repoweron", defval );
}
static void _setscopt_repoweron(iONode node, Boolean p_scopt_repoweron) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setBool( node, "scopt_repoweron", p_scopt_repoweron );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * scopt_stoplocos
 */
static struct __attrdef RocsWgen_scopt_stoplocos = {
  "scopt_stoplocos",  "Stop all locos in the district at shortcut.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isscopt_stoplocos(iONode node) {
  Boolean defval = xBool( RocsWgen_scopt_stoplocos );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_booster, node );
  return NodeOp.getBool( node, "scopt_stoplocos", defval );
}
static void _setscopt_stoplocos(iONode node, Boolean p_scopt_stoplocos) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setBool( node, "scopt_stoplocos", p_scopt_stoplocos );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * shortcut
 */
static struct __attrdef RocsWgen_shortcut = {
  "shortcut",  "Shortcut flag.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isshortcut(iONode node) {
  Boolean defval = xBool( RocsWgen_shortcut );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_booster, node );
  return NodeOp.getBool( node, "shortcut", defval );
}
static void _setshortcut(iONode node, Boolean p_shortcut) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setBool( node, "shortcut", p_shortcut );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * temp
 */
static struct __attrdef RocsWgen_temp = {
  "temp",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _gettemp(iONode node) {
  int defval = xInt( RocsWgen_temp );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_booster, node );
  return NodeOp.getInt( node, "temp", defval );
}
static void _settemp(iONode node, int p_temp) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setInt( node, "temp", p_temp );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * tempmax
 */
static struct __attrdef RocsWgen_tempmax = {
  "tempmax",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _gettempmax(iONode node) {
  int defval = xInt( RocsWgen_tempmax );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_booster, node );
  return NodeOp.getInt( node, "tempmax", defval );
}
static void _settempmax(iONode node, int p_tempmax) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setInt( node, "tempmax", p_tempmax );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * uid
 */
static struct __attrdef RocsWgen_uid = {
  "uid",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getuid(iONode node) {
  int defval = xInt( RocsWgen_uid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_booster, node );
  return NodeOp.getInt( node, "uid", defval );
}
static void _setuid(iONode node, int p_uid) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setInt( node, "uid", p_uid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * volt
 */
static struct __attrdef RocsWgen_volt = {
  "volt",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getvolt(iONode node) {
  int defval = xInt( RocsWgen_volt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_booster, node );
  return NodeOp.getInt( node, "volt", defval );
}
static void _setvolt(iONode node, int p_volt) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setInt( node, "volt", p_volt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * voltmin
 */
static struct __attrdef RocsWgen_voltmin = {
  "voltmin",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getvoltmin(iONode node) {
  int defval = xInt( RocsWgen_voltmin );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_booster, node );
  return NodeOp.getInt( node, "voltmin", defval );
}
static void _setvoltmin(iONode node, int p_voltmin) {
  if( node == NULL ) return;
  xNode( RocsWgen_booster, node );
  NodeOp.setInt( node, "voltmin", p_voltmin );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * actionctrl
 */
static struct __nodedef RocsWgen_actionctrl = {
  "actionctrl",  "",  False,  "n",};
static iONode _getactionctrl(iONode node) {
  xNode( RocsWgen_booster, node );
  return NodeOp.findNode( node, "actionctrl");
}


static iONode _nextactionctrl(iONode node, iONode child) {
  xNode( RocsWgen_booster, node );
  return NodeOp.findNextNode( node, child);
}
static void _setactionctrl(iONode node, iONode p_actionctrl) {
  xNode( RocsWgen_booster, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * boosterevent
 */
static struct __nodedef RocsWgen_boosterevent = {
  "boosterevent",  "",  False,  "n",};
static iONode _getboosterevent(iONode node) {
  xNode( RocsWgen_booster, node );
  return NodeOp.findNode( node, "boosterevent");
}


static iONode _nextboosterevent(iONode node, iONode child) {
  xNode( RocsWgen_booster, node );
  return NodeOp.findNextNode( node, child);
}
static void _setboosterevent(iONode node, iONode p_boosterevent) {
  xNode( RocsWgen_booster, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[22] = {NULL};
static struct __nodedef* nodeList[3] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_booster.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node booster not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node booster not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_blockids;
  attrList[1] = &RocsWgen_district;
  attrList[2] = &RocsWgen_doesreport;
  attrList[3] = &RocsWgen_id;
  attrList[4] = &RocsWgen_iid;
  attrList[5] = &RocsWgen_load;
  attrList[6] = &RocsWgen_loadmax;
  attrList[7] = &RocsWgen_modids;
  attrList[8] = &RocsWgen_power;
  attrList[9] = &RocsWgen_powerfb;
  attrList[10] = &RocsWgen_powersw;
  attrList[11] = &RocsWgen_scfb;
  attrList[12] = &RocsWgen_scopt_poweroffall;
  attrList[13] = &RocsWgen_scopt_repoweron;
  attrList[14] = &RocsWgen_scopt_stoplocos;
  attrList[15] = &RocsWgen_shortcut;
  attrList[16] = &RocsWgen_temp;
  attrList[17] = &RocsWgen_tempmax;
  attrList[18] = &RocsWgen_uid;
  attrList[19] = &RocsWgen_volt;
  attrList[20] = &RocsWgen_voltmin;
  attrList[21] = NULL;
  nodeList[0] = &RocsWgen_actionctrl;
  nodeList[1] = &RocsWgen_boosterevent;
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


struct __wBooster wBooster = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getblockids,
  _setblockids,
  _getdistrict,
  _setdistrict,
  _isdoesreport,
  _setdoesreport,
  _getid,
  _setid,
  _getiid,
  _setiid,
  _getload,
  _setload,
  _getloadmax,
  _setloadmax,
  _getmodids,
  _setmodids,
  _ispower,
  _setpower,
  _getpowerfb,
  _setpowerfb,
  _getpowersw,
  _setpowersw,
  _getscfb,
  _setscfb,
  _isscopt_poweroffall,
  _setscopt_poweroffall,
  _isscopt_repoweron,
  _setscopt_repoweron,
  _isscopt_stoplocos,
  _setscopt_stoplocos,
  _isshortcut,
  _setshortcut,
  _gettemp,
  _settemp,
  _gettempmax,
  _settempmax,
  _getuid,
  _setuid,
  _getvolt,
  _setvolt,
  _getvoltmin,
  _setvoltmin,
  _getactionctrl,
  _nextactionctrl,
  _setactionctrl,
  _getboosterevent,
  _nextboosterevent,
  _setboosterevent,
  _node_dump,
};
