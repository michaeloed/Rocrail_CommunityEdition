/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/State.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.State
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_state = {
  "state",  "State wrapper",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_state.name;
}
static const char* _node_remark(void) {
  return RocsWgen_state.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_state.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_state.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * accessorybus
 */
static struct __attrdef RocsWgen_accessorybus = {
  "accessorybus",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isaccessorybus(iONode node) {
  Boolean defval = xBool( RocsWgen_accessorybus );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getBool( node, "accessorybus", defval );
}
static void _setaccessorybus(iONode node, Boolean p_accessorybus) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setBool( node, "accessorybus", p_accessorybus );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * consolemode
 */
static struct __attrdef RocsWgen_consolemode = {
  "consolemode",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isconsolemode(iONode node) {
  Boolean defval = xBool( RocsWgen_consolemode );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getBool( node, "consolemode", defval );
}
static void _setconsolemode(iONode node, Boolean p_consolemode) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setBool( node, "consolemode", p_consolemode );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * emergency
 */
static struct __attrdef RocsWgen_emergency = {
  "emergency",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isemergency(iONode node) {
  Boolean defval = xBool( RocsWgen_emergency );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getBool( node, "emergency", defval );
}
static void _setemergency(iONode node, Boolean p_emergency) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setBool( node, "emergency", p_emergency );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * enablecom
 */
static struct __attrdef RocsWgen_enablecom = {
  "enablecom",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isenablecom(iONode node) {
  Boolean defval = xBool( RocsWgen_enablecom );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getBool( node, "enablecom", defval );
}
static void _setenablecom(iONode node, Boolean p_enablecom) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setBool( node, "enablecom", p_enablecom );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * healthy
 */
static struct __attrdef RocsWgen_healthy = {
  "healthy",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _ishealthy(iONode node) {
  Boolean defval = xBool( RocsWgen_healthy );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getBool( node, "healthy", defval );
}
static void _sethealthy(iONode node, Boolean p_healthy) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setBool( node, "healthy", p_healthy );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iid
 */
static struct __attrdef RocsWgen_iid = {
  "iid",  "",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getiid(iONode node) {
  const char* defval = xStr( RocsWgen_iid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * load
 */
static struct __attrdef RocsWgen_load = {
  "load",  "Load of CS in mA.",  "",  "int",  "0",  "",  False,
};
static int _getload(iONode node) {
  int defval = xInt( RocsWgen_load );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getInt( node, "load", defval );
}
static void _setload(iONode node, int p_load) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setInt( node, "load", p_load );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * loadmax
 */
static struct __attrdef RocsWgen_loadmax = {
  "loadmax",  "Load of CS in mA.",  "",  "int",  "0",  "",  False,
};
static int _getloadmax(iONode node) {
  int defval = xInt( RocsWgen_loadmax );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getInt( node, "loadmax", defval );
}
static void _setloadmax(iONode node, int p_loadmax) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setInt( node, "loadmax", p_loadmax );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * needkey4loconet
 */
static struct __attrdef RocsWgen_needkey4loconet = {
  "needkey4loconet",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isneedkey4loconet(iONode node) {
  Boolean defval = xBool( RocsWgen_needkey4loconet );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getBool( node, "needkey4loconet", defval );
}
static void _setneedkey4loconet(iONode node, Boolean p_needkey4loconet) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setBool( node, "needkey4loconet", p_needkey4loconet );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * power
 */
static struct __attrdef RocsWgen_power = {
  "power",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _ispower(iONode node) {
  Boolean defval = xBool( RocsWgen_power );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getBool( node, "power", defval );
}
static void _setpower(iONode node, Boolean p_power) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setBool( node, "power", p_power );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * programming
 */
static struct __attrdef RocsWgen_programming = {
  "programming",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isprogramming(iONode node) {
  Boolean defval = xBool( RocsWgen_programming );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getBool( node, "programming", defval );
}
static void _setprogramming(iONode node, Boolean p_programming) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setBool( node, "programming", p_programming );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ptload
 */
static struct __attrdef RocsWgen_ptload = {
  "ptload",  "Load of PT in mA.",  "",  "int",  "0",  "",  False,
};
static int _getptload(iONode node) {
  int defval = xInt( RocsWgen_ptload );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getInt( node, "ptload", defval );
}
static void _setptload(iONode node, int p_ptload) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setInt( node, "ptload", p_ptload );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sensorbus
 */
static struct __attrdef RocsWgen_sensorbus = {
  "sensorbus",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _issensorbus(iONode node) {
  Boolean defval = xBool( RocsWgen_sensorbus );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getBool( node, "sensorbus", defval );
}
static void _setsensorbus(iONode node, Boolean p_sensorbus) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setBool( node, "sensorbus", p_sensorbus );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * shortcut
 */
static struct __attrdef RocsWgen_shortcut = {
  "shortcut",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isshortcut(iONode node) {
  Boolean defval = xBool( RocsWgen_shortcut );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getBool( node, "shortcut", defval );
}
static void _setshortcut(iONode node, Boolean p_shortcut) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setBool( node, "shortcut", p_shortcut );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * temp
 */
static struct __attrdef RocsWgen_temp = {
  "temp",  "Temp of CS in C.",  "",  "int",  "0",  "",  False,
};
static int _gettemp(iONode node) {
  int defval = xInt( RocsWgen_temp );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getInt( node, "temp", defval );
}
static void _settemp(iONode node, int p_temp) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setInt( node, "temp", p_temp );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * tempmax
 */
static struct __attrdef RocsWgen_tempmax = {
  "tempmax",  "Temp of CS in C.",  "",  "int",  "0",  "",  False,
};
static int _gettempmax(iONode node) {
  int defval = xInt( RocsWgen_tempmax );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getInt( node, "tempmax", defval );
}
static void _settempmax(iONode node, int p_tempmax) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setInt( node, "tempmax", p_tempmax );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * trackbus
 */
static struct __attrdef RocsWgen_trackbus = {
  "trackbus",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _istrackbus(iONode node) {
  Boolean defval = xBool( RocsWgen_trackbus );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getBool( node, "trackbus", defval );
}
static void _settrackbus(iONode node, Boolean p_trackbus) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setBool( node, "trackbus", p_trackbus );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * uid
 */
static struct __attrdef RocsWgen_uid = {
  "uid",  "Unique-ID of reporter.",  "",  "int",  "0",  "",  False,
};
static int _getuid(iONode node) {
  int defval = xInt( RocsWgen_uid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getInt( node, "uid", defval );
}
static void _setuid(iONode node, int p_uid) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setInt( node, "uid", p_uid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * volt
 */
static struct __attrdef RocsWgen_volt = {
  "volt",  "Track voltage in mV.",  "",  "int",  "0",  "",  False,
};
static int _getvolt(iONode node) {
  int defval = xInt( RocsWgen_volt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getInt( node, "volt", defval );
}
static void _setvolt(iONode node, int p_volt) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setInt( node, "volt", p_volt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * voltmin
 */
static struct __attrdef RocsWgen_voltmin = {
  "voltmin",  "Track voltage in mV.",  "",  "int",  "0",  "",  False,
};
static int _getvoltmin(iONode node) {
  int defval = xInt( RocsWgen_voltmin );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_state, node );
  return NodeOp.getInt( node, "voltmin", defval );
}
static void _setvoltmin(iONode node, int p_voltmin) {
  if( node == NULL ) return;
  xNode( RocsWgen_state, node );
  NodeOp.setInt( node, "voltmin", p_voltmin );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[21] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_state.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node state not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node state not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_accessorybus;
  attrList[1] = &RocsWgen_consolemode;
  attrList[2] = &RocsWgen_emergency;
  attrList[3] = &RocsWgen_enablecom;
  attrList[4] = &RocsWgen_healthy;
  attrList[5] = &RocsWgen_iid;
  attrList[6] = &RocsWgen_load;
  attrList[7] = &RocsWgen_loadmax;
  attrList[8] = &RocsWgen_needkey4loconet;
  attrList[9] = &RocsWgen_power;
  attrList[10] = &RocsWgen_programming;
  attrList[11] = &RocsWgen_ptload;
  attrList[12] = &RocsWgen_sensorbus;
  attrList[13] = &RocsWgen_shortcut;
  attrList[14] = &RocsWgen_temp;
  attrList[15] = &RocsWgen_tempmax;
  attrList[16] = &RocsWgen_trackbus;
  attrList[17] = &RocsWgen_uid;
  attrList[18] = &RocsWgen_volt;
  attrList[19] = &RocsWgen_voltmin;
  attrList[20] = NULL;
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


struct __wState wState = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isaccessorybus,
  _setaccessorybus,
  _isconsolemode,
  _setconsolemode,
  _isemergency,
  _setemergency,
  _isenablecom,
  _setenablecom,
  _ishealthy,
  _sethealthy,
  _getiid,
  _setiid,
  _getload,
  _setload,
  _getloadmax,
  _setloadmax,
  _isneedkey4loconet,
  _setneedkey4loconet,
  _ispower,
  _setpower,
  _isprogramming,
  _setprogramming,
  _getptload,
  _setptload,
  _issensorbus,
  _setsensorbus,
  _isshortcut,
  _setshortcut,
  _gettemp,
  _settemp,
  _gettempmax,
  _settempmax,
  _istrackbus,
  _settrackbus,
  _getuid,
  _setuid,
  _getvolt,
  _setvolt,
  _getvoltmin,
  _setvoltmin,
  _node_dump,
};
