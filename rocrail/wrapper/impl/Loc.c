/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/Loc.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Loc
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_lc = {
  "lc",  "Loc definition.",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_lc.name;
}
static const char* _node_remark(void) {
  return RocsWgen_lc.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_lc.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_lc.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V
 */
static struct __attrdef RocsWgen_V = {
  "V",  "Loc speed in kmh.",  "kmh",  "int",  "-1",  "*",  False,
};
static int _getV(iONode node) {
  int defval = xInt( RocsWgen_V );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "V", defval );
}
static void _setV(iONode node, int p_V) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "V", p_V );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V_Rcru
 */
static struct __attrdef RocsWgen_V_Rcru = {
  "V_Rcru",  "Cruise reverse speed.(not used when 0)",  "",  "int",  "0",  "*",  False,
};
static int _getV_Rcru(iONode node) {
  int defval = xInt( RocsWgen_V_Rcru );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "V_Rcru", defval );
}
static void _setV_Rcru(iONode node, int p_V_Rcru) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "V_Rcru", p_V_Rcru );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V_Rmax
 */
static struct __attrdef RocsWgen_V_Rmax = {
  "V_Rmax",  "Maximal reverse speed.(not used when 0)",  "",  "int",  "0",  "*",  False,
};
static int _getV_Rmax(iONode node) {
  int defval = xInt( RocsWgen_V_Rmax );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "V_Rmax", defval );
}
static void _setV_Rmax(iONode node, int p_V_Rmax) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "V_Rmax", p_V_Rmax );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V_Rmid
 */
static struct __attrdef RocsWgen_V_Rmid = {
  "V_Rmid",  "Middle reverse speed.(not used when 0)",  "",  "int",  "0",  "*",  False,
};
static int _getV_Rmid(iONode node) {
  int defval = xInt( RocsWgen_V_Rmid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "V_Rmid", defval );
}
static void _setV_Rmid(iONode node, int p_V_Rmid) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "V_Rmid", p_V_Rmid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V_Rmin
 */
static struct __attrdef RocsWgen_V_Rmin = {
  "V_Rmin",  "Minimal reverse speed.(not used when 0)",  "",  "int",  "0",  "*",  False,
};
static int _getV_Rmin(iONode node) {
  int defval = xInt( RocsWgen_V_Rmin );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "V_Rmin", defval );
}
static void _setV_Rmin(iONode node, int p_V_Rmin) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "V_Rmin", p_V_Rmin );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V_cru
 */
static struct __attrdef RocsWgen_V_cru = {
  "V_cru",  "Cruise speed.(not used when 0)",  "",  "int",  "0",  "*",  False,
};
static int _getV_cru(iONode node) {
  int defval = xInt( RocsWgen_V_cru );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "V_cru", defval );
}
static void _setV_cru(iONode node, int p_V_cru) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "V_cru", p_V_cru );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V_hint
 */
static struct __attrdef RocsWgen_V_hint = {
  "V_hint",  "Loc speed in word hints.",  "",  "string",  "NULL",  "min,mid,max,cruise,climb",  False,
};
static const char* _getV_hint(iONode node) {
  const char* defval = xStr( RocsWgen_V_hint );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "V_hint", defval );
}
static void _setV_hint(iONode node, const char* p_V_hint) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "V_hint", p_V_hint );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V_max
 */
static struct __attrdef RocsWgen_V_max = {
  "V_max",  "Maximal speed.",  "",  "int",  "100",  "*",  False,
};
static int _getV_max(iONode node) {
  int defval = xInt( RocsWgen_V_max );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "V_max", defval );
}
static void _setV_max(iONode node, int p_V_max) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "V_max", p_V_max );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V_maxkmh
 */
static struct __attrdef RocsWgen_V_maxkmh = {
  "V_maxkmh",  "Maximal block speed in kmh",  "kmh",  "int",  "0",  "0-*",  False,
};
static int _getV_maxkmh(iONode node) {
  int defval = xInt( RocsWgen_V_maxkmh );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "V_maxkmh", defval );
}
static void _setV_maxkmh(iONode node, int p_V_maxkmh) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "V_maxkmh", p_V_maxkmh );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V_maxsec
 */
static struct __attrdef RocsWgen_V_maxsec = {
  "V_maxsec",  "Maximal speed for secondary address.",  "",  "int",  "14",  "*",  False,
};
static int _getV_maxsec(iONode node) {
  int defval = xInt( RocsWgen_V_maxsec );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "V_maxsec", defval );
}
static void _setV_maxsec(iONode node, int p_V_maxsec) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "V_maxsec", p_V_maxsec );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V_mid
 */
static struct __attrdef RocsWgen_V_mid = {
  "V_mid",  "Middle speed.",  "",  "int",  "50",  "*",  False,
};
static int _getV_mid(iONode node) {
  int defval = xInt( RocsWgen_V_mid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "V_mid", defval );
}
static void _setV_mid(iONode node, int p_V_mid) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "V_mid", p_V_mid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V_min
 */
static struct __attrdef RocsWgen_V_min = {
  "V_min",  "Minimal speed.",  "",  "int",  "10",  "*",  False,
};
static int _getV_min(iONode node) {
  int defval = xInt( RocsWgen_V_min );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "V_min", defval );
}
static void _setV_min(iONode node, int p_V_min) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "V_min", p_V_min );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V_mode
 */
static struct __attrdef RocsWgen_V_mode = {
  "V_mode",  "How the V values should be interpreted by the digint: percent is used for decoders without max speed tuning.(Delta...)",  "",  "string",  "percent",  "kmh,percent",  False,
};
static const char* _getV_mode(iONode node) {
  const char* defval = xStr( RocsWgen_V_mode );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "V_mode", defval );
}
static void _setV_mode(iONode node, const char* p_V_mode) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "V_mode", p_V_mode );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V_raw
 */
static struct __attrdef RocsWgen_V_raw = {
  "V_raw",  "Loc speed in CS speed steps.",  "",  "int",  "-1",  "*",  False,
};
static int _getV_raw(iONode node) {
  int defval = xInt( RocsWgen_V_raw );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "V_raw", defval );
}
static void _setV_raw(iONode node, int p_V_raw) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "V_raw", p_V_raw );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V_rawMax
 */
static struct __attrdef RocsWgen_V_rawMax = {
  "V_rawMax",  "Max loc speed in CS speed steps.",  "",  "int",  "-1",  "*",  False,
};
static int _getV_rawMax(iONode node) {
  int defval = xInt( RocsWgen_V_rawMax );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "V_rawMax", defval );
}
static void _setV_rawMax(iONode node, int p_V_rawMax) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "V_rawMax", p_V_rawMax );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V_realkmh
 */
static struct __attrdef RocsWgen_V_realkmh = {
  "V_realkmh",  "Reported speed in kmh.",  "kmh",  "int",  "0",  "0-*",  False,
};
static int _getV_realkmh(iONode node) {
  int defval = xInt( RocsWgen_V_realkmh );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "V_realkmh", defval );
}
static void _setV_realkmh(iONode node, int p_V_realkmh) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "V_realkmh", p_V_realkmh );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V_step
 */
static struct __attrdef RocsWgen_V_step = {
  "V_step",  "Time between next decoder speed.(used only incase of V_mode_percent)",  "tenth of sec.",  "int",  "0",  "0-9",  False,
};
static int _getV_step(iONode node) {
  int defval = xInt( RocsWgen_V_step );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "V_step", defval );
}
static void _setV_step(iONode node, int p_V_step) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "V_step", p_V_step );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * accelmax
 */
static struct __attrdef RocsWgen_accelmax = {
  "accelmax",  "Maximal acceleration CV3 value.",  "",  "int",  "0",  "0-255",  False,
};
static int _getaccelmax(iONode node) {
  int defval = xInt( RocsWgen_accelmax );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "accelmax", defval );
}
static void _setaccelmax(iONode node, int p_accelmax) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "accelmax", p_accelmax );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * accelmin
 */
static struct __attrdef RocsWgen_accelmin = {
  "accelmin",  "Minimal acceleration CV3 value.",  "",  "int",  "0",  "0-255",  False,
};
static int _getaccelmin(iONode node) {
  int defval = xInt( RocsWgen_accelmin );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "accelmin", defval );
}
static void _setaccelmin(iONode node, int p_accelmin) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "accelmin", p_accelmin );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * active
 */
static struct __attrdef RocsWgen_active = {
  "active",  "Active for running in auto mode.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isactive(iONode node) {
  Boolean defval = xBool( RocsWgen_active );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "active", defval );
}
static void _setactive(iONode node, Boolean p_active) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "active", p_active );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr
 */
static struct __attrdef RocsWgen_addr = {
  "addr",  "Digital address. (0 == analog)",  "",  "int",  "0",  "0-255",  True,
};
static int _getaddr(iONode node) {
  int defval = xInt( RocsWgen_addr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "addr", defval );
}
static void _setaddr(iONode node, int p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "addr", p_addr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * adjustaccel
 */
static struct __attrdef RocsWgen_adjustaccel = {
  "adjustaccel",  "Adjust CV3 acceleration.",  "",  "bool",  "False",  "",  False,
};
static Boolean _isadjustaccel(iONode node) {
  Boolean defval = xBool( RocsWgen_adjustaccel );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "adjustaccel", defval );
}
static void _setadjustaccel(iONode node, Boolean p_adjustaccel) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "adjustaccel", p_adjustaccel );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bbtcorrection
 */
static struct __attrdef RocsWgen_bbtcorrection = {
  "bbtcorrection",  "",  "%",  "int",  "25",  "10-100",  False,
};
static int _getbbtcorrection(iONode node) {
  int defval = xInt( RocsWgen_bbtcorrection );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "bbtcorrection", defval );
}
static void _setbbtcorrection(iONode node, int p_bbtcorrection) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "bbtcorrection", p_bbtcorrection );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bbtevent
 */
static struct __attrdef RocsWgen_bbtevent = {
  "bbtevent",  "Flag for filter out at broadcast.",  "",  "bool",  "False",  "",  False,
};
static Boolean _isbbtevent(iONode node) {
  Boolean defval = xBool( RocsWgen_bbtevent );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "bbtevent", defval );
}
static void _setbbtevent(iONode node, Boolean p_bbtevent) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "bbtevent", p_bbtevent );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bbtkey
 */
static struct __attrdef RocsWgen_bbtkey = {
  "bbtkey",  "0=block, 1=block-fromblock, 2=block-route, 3=block-speed",  "",  "int",  "0",  "",  False,
};
static int _getbbtkey(iONode node) {
  int defval = xInt( RocsWgen_bbtkey );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "bbtkey", defval );
}
static void _setbbtkey(iONode node, int p_bbtkey) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "bbtkey", p_bbtkey );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bbtmaxdiff
 */
static struct __attrdef RocsWgen_bbtmaxdiff = {
  "bbtmaxdiff",  "",  "10ms",  "int",  "250",  "10-500",  False,
};
static int _getbbtmaxdiff(iONode node) {
  int defval = xInt( RocsWgen_bbtmaxdiff );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "bbtmaxdiff", defval );
}
static void _setbbtmaxdiff(iONode node, int p_bbtmaxdiff) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "bbtmaxdiff", p_bbtmaxdiff );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bbtstartinterval
 */
static struct __attrdef RocsWgen_bbtstartinterval = {
  "bbtstartinterval",  "",  "",  "int",  "10",  "10-50",  False,
};
static int _getbbtstartinterval(iONode node) {
  int defval = xInt( RocsWgen_bbtstartinterval );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "bbtstartinterval", defval );
}
static void _setbbtstartinterval(iONode node, int p_bbtstartinterval) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "bbtstartinterval", p_bbtstartinterval );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bbtsteps
 */
static struct __attrdef RocsWgen_bbtsteps = {
  "bbtsteps",  "",  "",  "int",  "10",  "4-16",  False,
};
static int _getbbtsteps(iONode node) {
  int defval = xInt( RocsWgen_bbtsteps );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "bbtsteps", defval );
}
static void _setbbtsteps(iONode node, int p_bbtsteps) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "bbtsteps", p_bbtsteps );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blockenterid
 */
static struct __attrdef RocsWgen_blockenterid = {
  "blockenterid",  "Block ID which has been entered. The blockid should be used if not set.",  "",  "string",  "",  "*",  False,
};
static const char* _getblockenterid(iONode node) {
  const char* defval = xStr( RocsWgen_blockenterid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "blockenterid", defval );
}
static void _setblockenterid(iONode node, const char* p_blockenterid) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "blockenterid", p_blockenterid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blockenterside
 */
static struct __attrdef RocsWgen_blockenterside = {
  "blockenterside",  "Block enter side.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isblockenterside(iONode node) {
  Boolean defval = xBool( RocsWgen_blockenterside );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "blockenterside", defval );
}
static void _setblockenterside(iONode node, Boolean p_blockenterside) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "blockenterside", p_blockenterside );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blockid
 */
static struct __attrdef RocsWgen_blockid = {
  "blockid",  "Current block ID.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getblockid(iONode node) {
  const char* defval = xStr( RocsWgen_blockid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "blockid", defval );
}
static void _setblockid(iONode node, const char* p_blockid) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "blockid", p_blockid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blockwaittime
 */
static struct __attrdef RocsWgen_blockwaittime = {
  "blockwaittime",  "Own wait time.",  "s",  "int",  "10",  "0-*",  False,
};
static int _getblockwaittime(iONode node) {
  int defval = xInt( RocsWgen_blockwaittime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "blockwaittime", defval );
}
static void _setblockwaittime(iONode node, int p_blockwaittime) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "blockwaittime", p_blockwaittime );
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
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "bus", defval );
}
static void _setbus(iONode node, int p_bus) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "bus", p_bus );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cargo
 */
static struct __attrdef RocsWgen_cargo = {
  "cargo",  "",  "",  "string",  "none",  "*",  False,
};
static const char* _getcargo(iONode node) {
  const char* defval = xStr( RocsWgen_cargo );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "cargo", defval );
}
static void _setcargo(iONode node, const char* p_cargo) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "cargo", p_cargo );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * catnr
 */
static struct __attrdef RocsWgen_catnr = {
  "catnr",  "Catalog number.",  "",  "string",  "",  "*",  False,
};
static const char* _getcatnr(iONode node) {
  const char* defval = xStr( RocsWgen_catnr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "catnr", defval );
}
static void _setcatnr(iONode node, const char* p_catnr) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "catnr", p_catnr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * check2in
 */
static struct __attrdef RocsWgen_check2in = {
  "check2in",  "Check for a free new destination between the enter and in event.",  "",  "bool",  "false",  "",  False,
};
static Boolean _ischeck2in(iONode node) {
  Boolean defval = xBool( RocsWgen_check2in );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "check2in", defval );
}
static void _setcheck2in(iONode node, Boolean p_check2in) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "check2in", p_check2in );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * class
 */
static struct __attrdef RocsWgen_class = {
  "class",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getclass(iONode node) {
  const char* defval = xStr( RocsWgen_class );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "class", defval );
}
static void _setclass(iONode node, const char* p_class) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "class", p_class );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmd
 */
static struct __attrdef RocsWgen_cmd = {
  "cmd",  "Loc command.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getcmd(iONode node) {
  const char* defval = xStr( RocsWgen_cmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmdDelay
 */
static struct __attrdef RocsWgen_cmdDelay = {
  "cmdDelay",  "Loc command delay.",  "",  "int",  "0",  "*",  False,
};
static int _getcmdDelay(iONode node) {
  int defval = xInt( RocsWgen_cmdDelay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "cmdDelay", defval );
}
static void _setcmdDelay(iONode node, int p_cmdDelay) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "cmdDelay", p_cmdDelay );
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
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "commuter", defval );
}
static void _setcommuter(iONode node, Boolean p_commuter) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "commuter", p_commuter );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * consist
 */
static struct __attrdef RocsWgen_consist = {
  "consist",  "Slave locomotives",  "",  "string",  "",  "*",  False,
};
static const char* _getconsist(iONode node) {
  const char* defval = xStr( RocsWgen_consist );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "consist", defval );
}
static void _setconsist(iONode node, const char* p_consist) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "consist", p_consist );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * consist_lightsoff
 */
static struct __attrdef RocsWgen_consist_lightsoff = {
  "consist_lightsoff",  "Keep lights turned off for all slave locos.",  "",  "bool",  "False",  "",  False,
};
static Boolean _isconsist_lightsoff(iONode node) {
  Boolean defval = xBool( RocsWgen_consist_lightsoff );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "consist_lightsoff", defval );
}
static void _setconsist_lightsoff(iONode node, Boolean p_consist_lightsoff) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "consist_lightsoff", p_consist_lightsoff );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * consist_syncfun
 */
static struct __attrdef RocsWgen_consist_syncfun = {
  "consist_syncfun",  "Synchronise functions for all slave locos.",  "",  "bool",  "False",  "",  False,
};
static Boolean _isconsist_syncfun(iONode node) {
  Boolean defval = xBool( RocsWgen_consist_syncfun );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "consist_syncfun", defval );
}
static void _setconsist_syncfun(iONode node, Boolean p_consist_syncfun) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "consist_syncfun", p_consist_syncfun );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * consist_syncfunmap
 */
static struct __attrdef RocsWgen_consist_syncfunmap = {
  "consist_syncfunmap",  "Function map.",  "",  "int",  "0",  "",  False,
};
static int _getconsist_syncfunmap(iONode node) {
  int defval = xInt( RocsWgen_consist_syncfunmap );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "consist_syncfunmap", defval );
}
static void _setconsist_syncfunmap(iONode node, int p_consist_syncfunmap) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "consist_syncfunmap", p_consist_syncfunmap );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * consist_synclights
 */
static struct __attrdef RocsWgen_consist_synclights = {
  "consist_synclights",  "Synchronise lights for all slave locos.",  "",  "bool",  "False",  "",  False,
};
static Boolean _isconsist_synclights(iONode node) {
  Boolean defval = xBool( RocsWgen_consist_synclights );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "consist_synclights", defval );
}
static void _setconsist_synclights(iONode node, Boolean p_consist_synclights) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "consist_synclights", p_consist_synclights );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * consistcmd
 */
static struct __attrdef RocsWgen_consistcmd = {
  "consistcmd",  "Consist context command; Flag for preventing loops.",  "",  "bool",  "False",  "",  False,
};
static Boolean _isconsistcmd(iONode node) {
  Boolean defval = xBool( RocsWgen_consistcmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "consistcmd", defval );
}
static void _setconsistcmd(iONode node, Boolean p_consistcmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "consistcmd", p_consistcmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * decelerate
 */
static struct __attrdef RocsWgen_decelerate = {
  "decelerate",  "",  "",  "int",  "0",  "0-50",  False,
};
static int _getdecelerate(iONode node) {
  int defval = xInt( RocsWgen_decelerate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "decelerate", defval );
}
static void _setdecelerate(iONode node, int p_decelerate) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "decelerate", p_decelerate );
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
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "decfile", defval );
}
static void _setdecfile(iONode node, const char* p_decfile) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "decfile", p_decfile );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * decimage
 */
static struct __attrdef RocsWgen_decimage = {
  "decimage",  "decoder image file",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getdecimage(iONode node) {
  const char* defval = xStr( RocsWgen_decimage );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "decimage", defval );
}
static void _setdecimage(iONode node, const char* p_decimage) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "decimage", p_decimage );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * dectype
 */
static struct __attrdef RocsWgen_dectype = {
  "dectype",  "Decoder type. (CV8)",  "",  "string",  "",  "*",  False,
};
static const char* _getdectype(iONode node) {
  const char* defval = xStr( RocsWgen_dectype );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "dectype", defval );
}
static void _setdectype(iONode node, const char* p_dectype) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "dectype", p_dectype );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * desc
 */
static struct __attrdef RocsWgen_desc = {
  "desc",  "Description of loc.",  "",  "string",  "",  "*",  False,
};
static const char* _getdesc(iONode node) {
  const char* defval = xStr( RocsWgen_desc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * destblockid
 */
static struct __attrdef RocsWgen_destblockid = {
  "destblockid",  "Destination block ID. (info only)",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getdestblockid(iONode node) {
  const char* defval = xStr( RocsWgen_destblockid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "destblockid", defval );
}
static void _setdestblockid(iONode node, const char* p_destblockid) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "destblockid", p_destblockid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * dir
 */
static struct __attrdef RocsWgen_dir = {
  "dir",  "Direction; true is forwards.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isdir(iONode node) {
  Boolean defval = xBool( RocsWgen_dir );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "dir", defval );
}
static void _setdir(iONode node, Boolean p_dir) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "dir", p_dir );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * dirpause
 */
static struct __attrdef RocsWgen_dirpause = {
  "dirpause",  "pause after sending last turnout command and before sending the direction to the loc decoder",  "ms",  "int",  "0",  "0-999",  False,
};
static int _getdirpause(iONode node) {
  int defval = xInt( RocsWgen_dirpause );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "dirpause", defval );
}
static void _setdirpause(iONode node, int p_dirpause) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "dirpause", p_dirpause );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * docu
 */
static struct __attrdef RocsWgen_docu = {
  "docu",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getdocu(iONode node) {
  const char* defval = xStr( RocsWgen_docu );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "docu", defval );
}
static void _setdocu(iONode node, const char* p_docu) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "docu", p_docu );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * engine
 */
static struct __attrdef RocsWgen_engine = {
  "engine",  "",  "",  "string",  "diesel",  "diesel,electric,steam,automobile",  False,
};
static const char* _getengine(iONode node) {
  const char* defval = xStr( RocsWgen_engine );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "engine", defval );
}
static void _setengine(iONode node, const char* p_engine) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "engine", p_engine );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ent2incorr
 */
static struct __attrdef RocsWgen_ent2incorr = {
  "ent2incorr",  "Correction percentage for enter2in block timer",  "%",  "int",  "100",  "1-*",  False,
};
static int _getent2incorr(iONode node) {
  int defval = xInt( RocsWgen_ent2incorr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "ent2incorr", defval );
}
static void _setent2incorr(iONode node, int p_ent2incorr) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "ent2incorr", p_ent2incorr );
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
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "era", defval );
}
static void _setera(iONode node, int p_era) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "era", p_era );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * evttimer
 */
static struct __attrdef RocsWgen_evttimer = {
  "evttimer",  "event timer; loc should wait this time before processing the event",  "ms",  "int",  "0",  "0-*",  False,
};
static int _getevttimer(iONode node) {
  int defval = xInt( RocsWgen_evttimer );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "evttimer", defval );
}
static void _setevttimer(iONode node, int p_evttimer) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "evttimer", p_evttimer );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fifotop
 */
static struct __attrdef RocsWgen_fifotop = {
  "fifotop",  "Loco is on top of a location FiFo.",  "",  "bool",  "False",  "",  False,
};
static Boolean _isfifotop(iONode node) {
  Boolean defval = xBool( RocsWgen_fifotop );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "fifotop", defval );
}
static void _setfifotop(iONode node, Boolean p_fifotop) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "fifotop", p_fifotop );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fn
 */
static struct __attrdef RocsWgen_fn = {
  "fn",  "Function switch. (Lights)",  "",  "bool",  "true",  "",  False,
};
static Boolean _isfn(iONode node) {
  Boolean defval = xBool( RocsWgen_fn );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "fn", defval );
}
static void _setfn(iONode node, Boolean p_fn) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "fn", p_fn );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fncnt
 */
static struct __attrdef RocsWgen_fncnt = {
  "fncnt",  "number of decoder funktions",  "",  "int",  "4",  "0-*",  False,
};
static int _getfncnt(iONode node) {
  int defval = xInt( RocsWgen_fncnt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "fncnt", defval );
}
static void _setfncnt(iONode node, int p_fncnt) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "fncnt", p_fncnt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * freeblockonenter
 */
static struct __attrdef RocsWgen_freeblockonenter = {
  "freeblockonenter",  "Use the enter event to free previous block.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isfreeblockonenter(iONode node) {
  Boolean defval = xBool( RocsWgen_freeblockonenter );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "freeblockonenter", defval );
}
static void _setfreeblockonenter(iONode node, Boolean p_freeblockonenter) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "freeblockonenter", p_freeblockonenter );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fx
 */
static struct __attrdef RocsWgen_fx = {
  "fx",  "Function status bits for display only.",  "",  "int",  "0",  "",  False,
};
static int _getfx(iONode node) {
  int defval = xInt( RocsWgen_fx );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "fx", defval );
}
static void _setfx(iONode node, int p_fx) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "fx", p_fx );
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
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * identifier
 */
static struct __attrdef RocsWgen_identifier = {
  "identifier",  "Loc identifier incase of RFID, Lissy, Barcode...",  "",  "string",  "",  "",  False,
};
static const char* _getidentifier(iONode node) {
  const char* defval = xStr( RocsWgen_identifier );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "identifier", defval );
}
static void _setidentifier(iONode node, const char* p_identifier) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "identifier", p_identifier );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ignorefn
 */
static struct __attrdef RocsWgen_ignorefn = {
  "ignorefn",  "Ignore lights.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isignorefn(iONode node) {
  Boolean defval = xBool( RocsWgen_ignorefn );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "ignorefn", defval );
}
static void _setignorefn(iONode node, Boolean p_ignorefn) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "ignorefn", p_ignorefn );
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
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * image
 */
static struct __attrdef RocsWgen_image = {
  "image",  "local image file to show in dialogs",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getimage(iONode node) {
  const char* defval = xStr( RocsWgen_image );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "image", defval );
}
static void _setimage(iONode node, const char* p_image) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "image", p_image );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * imagenr
 */
static struct __attrdef RocsWgen_imagenr = {
  "imagenr",  "throttle image number",  "",  "int",  "0",  "*",  False,
};
static int _getimagenr(iONode node) {
  int defval = xInt( RocsWgen_imagenr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "imagenr", defval );
}
static void _setimagenr(iONode node, int p_imagenr) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "imagenr", p_imagenr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * inatpre2in
 */
static struct __attrdef RocsWgen_inatpre2in = {
  "inatpre2in",  "Use pre2in event to stop in blocks.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isinatpre2in(iONode node) {
  Boolean defval = xBool( RocsWgen_inatpre2in );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "inatpre2in", defval );
}
static void _setinatpre2in(iONode node, Boolean p_inatpre2in) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "inatpre2in", p_inatpre2in );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * info4throttle
 */
static struct __attrdef RocsWgen_info4throttle = {
  "info4throttle",  "Get loco info if it is stalled and not in automode.",  "",  "bool",  "False",  "",  False,
};
static Boolean _isinfo4throttle(iONode node) {
  Boolean defval = xBool( RocsWgen_info4throttle );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "info4throttle", defval );
}
static void _setinfo4throttle(iONode node, Boolean p_info4throttle) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "info4throttle", p_info4throttle );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lclib
 */
static struct __attrdef RocsWgen_lclib = {
  "lclib",  "LocDriver library",  "",  "string",  "./lcdriver",  "",  False,
};
static const char* _getlclib(iONode node) {
  const char* defval = xStr( RocsWgen_lclib );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "lclib", defval );
}
static void _setlclib(iONode node, const char* p_lclib) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "lclib", p_lclib );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * len
 */
static struct __attrdef RocsWgen_len = {
  "len",  "Total length of loc with wagons to check with block length..",  "cm",  "int",  "0",  "0-*",  False,
};
static int _getlen(iONode node) {
  int defval = xInt( RocsWgen_len );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "len", defval );
}
static void _setlen(iONode node, int p_len) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "len", p_len );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * manual
 */
static struct __attrdef RocsWgen_manual = {
  "manual",  "Half auto mode flag.",  "",  "bool",  "false",  "",  False,
};
static Boolean _ismanual(iONode node) {
  Boolean defval = xBool( RocsWgen_manual );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "manual", defval );
}
static void _setmanual(iONode node, Boolean p_manual) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "manual", p_manual );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * manually
 */
static struct __attrdef RocsWgen_manually = {
  "manually",  "Manually started; Ignore start all locos.",  "",  "bool",  "false",  "",  False,
};
static Boolean _ismanually(iONode node) {
  Boolean defval = xBool( RocsWgen_manually );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "manually", defval );
}
static void _setmanually(iONode node, Boolean p_manually) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "manually", p_manually );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mass
 */
static struct __attrdef RocsWgen_mass = {
  "mass",  "Mass index for use with Dinamo.",  "",  "int",  "0",  "0-127",  False,
};
static int _getmass(iONode node) {
  int defval = xInt( RocsWgen_mass );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "mass", defval );
}
static void _setmass(iONode node, int p_mass) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "mass", p_mass );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * maxload
 */
static struct __attrdef RocsWgen_maxload = {
  "maxload",  "Maximal loco load",  "ton",  "int",  "0",  "0-*",  False,
};
static int _getmaxload(iONode node) {
  int defval = xInt( RocsWgen_maxload );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "maxload", defval );
}
static void _setmaxload(iONode node, int p_maxload) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "maxload", p_maxload );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * maxwaittime
 */
static struct __attrdef RocsWgen_maxwaittime = {
  "maxwaittime",  "Max. wait time in block by priority.",  "s",  "int",  "0",  "0-*",  False,
};
static int _getmaxwaittime(iONode node) {
  int defval = xInt( RocsWgen_maxwaittime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "maxwaittime", defval );
}
static void _setmaxwaittime(iONode node, int p_maxwaittime) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "maxwaittime", p_maxwaittime );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mdate
 */
static struct __attrdef RocsWgen_mdate = {
  "mdate",  "last maintenance date",  "",  "long",  "0",  "",  False,
};
static long _getmdate(iONode node) {
  long defval = xLong( RocsWgen_mdate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getLong( node, "mdate", defval );
}
static void _setmdate(iONode node, long p_mdate) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setLong( node, "mdate", p_mdate );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mint
 */
static struct __attrdef RocsWgen_mint = {
  "mint",  "maintenance interval in hours",  "",  "int",  "0",  "",  False,
};
static int _getmint(iONode node) {
  int defval = xInt( RocsWgen_mint );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "mint", defval );
}
static void _setmint(iONode node, int p_mint) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "mint", p_mint );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mode
 */
static struct __attrdef RocsWgen_mode = {
  "mode",  "Loc mode.",  "",  "string",  "",  "*",  False,
};
static const char* _getmode(iONode node) {
  const char* defval = xStr( RocsWgen_mode );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "mode", defval );
}
static void _setmode(iONode node, const char* p_mode) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "mode", p_mode );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * modereason
 */
static struct __attrdef RocsWgen_modereason = {
  "modereason",  "Loco mode reason.",  "",  "string",  "",  "*",  False,
};
static const char* _getmodereason(iONode node) {
  const char* defval = xStr( RocsWgen_modereason );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "modereason", defval );
}
static void _setmodereason(iONode node, const char* p_modereason) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "modereason", p_modereason );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mtime
 */
static struct __attrdef RocsWgen_mtime = {
  "mtime",  "last maintenance in seconds",  "",  "long",  "0",  "",  False,
};
static long _getmtime(iONode node) {
  long defval = xLong( RocsWgen_mtime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getLong( node, "mtime", defval );
}
static void _setmtime(iONode node, long p_mtime) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setLong( node, "mtime", p_mtime );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nrcars
 */
static struct __attrdef RocsWgen_nrcars = {
  "nrcars",  "Number of cars. Needed for counting in sensors.",  "",  "int",  "0",  "0-*",  False,
};
static int _getnrcars(iONode node) {
  int defval = xInt( RocsWgen_nrcars );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "nrcars", defval );
}
static void _setnrcars(iONode node, int p_nrcars) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "nrcars", p_nrcars );
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
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "number", defval );
}
static void _setnumber(iONode node, const char* p_number) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "number", p_number );
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
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "oid", defval );
}
static void _setoid(iONode node, const char* p_oid) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "oid", p_oid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * placing
 */
static struct __attrdef RocsWgen_placing = {
  "placing",  "If loc is placed back to front this should be set to false.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isplacing(iONode node) {
  Boolean defval = xBool( RocsWgen_placing );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "placing", defval );
}
static void _setplacing(iONode node, Boolean p_placing) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "placing", p_placing );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "Block number in the Dinamo system. (Block property)",  "",  "int",  "0",  "0-*",  False,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "port", p_port );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * prev_id
 */
static struct __attrdef RocsWgen_prev_id = {
  "prev_id",  "in case of an id change this should help to find the original in the loc table",  "",  "string",  "",  "*",  False,
};
static const char* _getprev_id(iONode node) {
  const char* defval = xStr( RocsWgen_prev_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "prev_id", defval );
}
static void _setprev_id(iONode node, const char* p_prev_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "prev_id", p_prev_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * priority
 */
static struct __attrdef RocsWgen_priority = {
  "priority",  "train priority used for multiplying the wait time if no destination is found",  "",  "int",  "10",  "1-100",  False,
};
static int _getpriority(iONode node) {
  int defval = xInt( RocsWgen_priority );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "priority", defval );
}
static void _setpriority(iONode node, int p_priority) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "priority", p_priority );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * prot
 */
static struct __attrdef RocsWgen_prot = {
  "prot",  "P = protocol by server, M = Marklin, N = NMRA-DCC, L = NMRA-DCC long addresses, A = Analog, C= Car Decoder",  "",  "string",  "P",  "P,M,N,A,C",  False,
};
static const char* _getprot(iONode node) {
  const char* defval = xStr( RocsWgen_prot );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "prot", defval );
}
static void _setprot(iONode node, const char* p_prot) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
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
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "protver", defval );
}
static void _setprotver(iONode node, int p_protver) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "protver", p_protver );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * purchased
 */
static struct __attrdef RocsWgen_purchased = {
  "purchased",  "Date of purchase",  "",  "string",  "",  "",  False,
};
static const char* _getpurchased(iONode node) {
  const char* defval = xStr( RocsWgen_purchased );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "purchased", defval );
}
static void _setpurchased(iONode node, const char* p_purchased) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "purchased", p_purchased );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * reducespeedatenter
 */
static struct __attrdef RocsWgen_reducespeedatenter = {
  "reducespeedatenter",  "Reduce speed at enter if the next route has thrown switches.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isreducespeedatenter(iONode node) {
  Boolean defval = xBool( RocsWgen_reducespeedatenter );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "reducespeedatenter", defval );
}
static void _setreducespeedatenter(iONode node, Boolean p_reducespeedatenter) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "reducespeedatenter", p_reducespeedatenter );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * regulated
 */
static struct __attrdef RocsWgen_regulated = {
  "regulated",  "Decoder regulates the motor.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isregulated(iONode node) {
  Boolean defval = xBool( RocsWgen_regulated );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "regulated", defval );
}
static void _setregulated(iONode node, Boolean p_regulated) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "regulated", p_regulated );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * remark
 */
static struct __attrdef RocsWgen_remark = {
  "remark",  "optional remark",  "",  "string",  "",  "*",  False,
};
static const char* _getremark(iONode node) {
  const char* defval = xStr( RocsWgen_remark );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "remark", defval );
}
static void _setremark(iONode node, const char* p_remark) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "remark", p_remark );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * resetplacing
 */
static struct __attrdef RocsWgen_resetplacing = {
  "resetplacing",  "Reset placing and direction at server startup.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isresetplacing(iONode node) {
  Boolean defval = xBool( RocsWgen_resetplacing );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "resetplacing", defval );
}
static void _setresetplacing(iONode node, Boolean p_resetplacing) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "resetplacing", p_resetplacing );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * restorefx
 */
static struct __attrdef RocsWgen_restorefx = {
  "restorefx",  "Restore functions from previouse session.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isrestorefx(iONode node) {
  Boolean defval = xBool( RocsWgen_restorefx );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "restorefx", defval );
}
static void _setrestorefx(iONode node, Boolean p_restorefx) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "restorefx", p_restorefx );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * restorefxalways
 */
static struct __attrdef RocsWgen_restorefxalways = {
  "restorefxalways",  "Restore functions from previouse session at each power on command.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isrestorefxalways(iONode node) {
  Boolean defval = xBool( RocsWgen_restorefxalways );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "restorefxalways", defval );
}
static void _setrestorefxalways(iONode node, Boolean p_restorefxalways) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "restorefxalways", p_restorefxalways );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * restorespeed
 */
static struct __attrdef RocsWgen_restorespeed = {
  "restorespeed",  "Restore speed from previouse session.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isrestorespeed(iONode node) {
  Boolean defval = xBool( RocsWgen_restorespeed );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "restorespeed", defval );
}
static void _setrestorespeed(iONode node, Boolean p_restorespeed) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "restorespeed", p_restorespeed );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * resumeauto
 */
static struct __attrdef RocsWgen_resumeauto = {
  "resumeauto",  "Resume auto mode from previous session.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isresumeauto(iONode node) {
  Boolean defval = xBool( RocsWgen_resumeauto );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "resumeauto", defval );
}
static void _setresumeauto(iONode node, Boolean p_resumeauto) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "resumeauto", p_resumeauto );
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
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "roadname", defval );
}
static void _setroadname(iONode node, const char* p_roadname) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "roadname", p_roadname );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * roaming
 */
static struct __attrdef RocsWgen_roaming = {
  "roaming",  "The roaming flag allows a loc traveling to other systems.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isroaming(iONode node) {
  Boolean defval = xBool( RocsWgen_roaming );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "roaming", defval );
}
static void _setroaming(iONode node, Boolean p_roaming) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "roaming", p_roaming );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * runtime
 */
static struct __attrdef RocsWgen_runtime = {
  "runtime",  "Auto runtime in seconds",  "",  "long",  "0",  "",  False,
};
static long _getruntime(iONode node) {
  long defval = xLong( RocsWgen_runtime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getLong( node, "runtime", defval );
}
static void _setruntime(iONode node, long p_runtime) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setLong( node, "runtime", p_runtime );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * scheduleid
 */
static struct __attrdef RocsWgen_scheduleid = {
  "scheduleid",  "Current schedule ID.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getscheduleid(iONode node) {
  const char* defval = xStr( RocsWgen_scheduleid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "scheduleid", defval );
}
static void _setscheduleid(iONode node, const char* p_scheduleid) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "scheduleid", p_scheduleid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * scidx
 */
static struct __attrdef RocsWgen_scidx = {
  "scidx",  "Schedule index",  "",  "int",  "-1",  "*",  False,
};
static int _getscidx(iONode node) {
  int defval = xInt( RocsWgen_scidx );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "scidx", defval );
}
static void _setscidx(iONode node, int p_scidx) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "scidx", p_scidx );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * secaddr
 */
static struct __attrdef RocsWgen_secaddr = {
  "secaddr",  "Secondary address for coupler systems.",  "",  "int",  "0",  "0-255",  False,
};
static int _getsecaddr(iONode node) {
  int defval = xInt( RocsWgen_secaddr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "secaddr", defval );
}
static void _setsecaddr(iONode node, int p_secaddr) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "secaddr", p_secaddr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * secondnextblock
 */
static struct __attrdef RocsWgen_secondnextblock = {
  "secondnextblock",  "Try to reserve a second next block.",  "",  "bool",  "false",  "",  False,
};
static Boolean _issecondnextblock(iONode node) {
  Boolean defval = xBool( RocsWgen_secondnextblock );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "secondnextblock", defval );
}
static void _setsecondnextblock(iONode node, Boolean p_secondnextblock) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "secondnextblock", p_secondnextblock );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * secspcnt
 */
static struct __attrdef RocsWgen_secspcnt = {
  "secspcnt",  "Secondary speed steps count",  "",  "int",  "14",  "*",  False,
};
static int _getsecspcnt(iONode node) {
  int defval = xInt( RocsWgen_secspcnt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "secspcnt", defval );
}
static void _setsecspcnt(iONode node, int p_secspcnt) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "secspcnt", p_secspcnt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * shortid
 */
static struct __attrdef RocsWgen_shortid = {
  "shortid",  "Short IDs are used for throttle displays.",  "",  "string",  "",  "*",  False,
};
static const char* _getshortid(iONode node) {
  const char* defval = xStr( RocsWgen_shortid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "shortid", defval );
}
static void _setshortid(iONode node, const char* p_shortid) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "shortid", p_shortid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * shortin
 */
static struct __attrdef RocsWgen_shortin = {
  "shortin",  "Use shortin event to stop in blocks.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isshortin(iONode node) {
  Boolean defval = xBool( RocsWgen_shortin );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "shortin", defval );
}
static void _setshortin(iONode node, Boolean p_shortin) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "shortin", p_shortin );
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
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "show", defval );
}
static void _setshow(iONode node, Boolean p_show) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "show", p_show );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * shuntingdiv
 */
static struct __attrdef RocsWgen_shuntingdiv = {
  "shuntingdiv",  "Shunting divider",  "",  "int",  "1",  "1-4",  False,
};
static int _getshuntingdiv(iONode node) {
  int defval = xInt( RocsWgen_shuntingdiv );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "shuntingdiv", defval );
}
static void _setshuntingdiv(iONode node, int p_shuntingdiv) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "shuntingdiv", p_shuntingdiv );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * spcnt
 */
static struct __attrdef RocsWgen_spcnt = {
  "spcnt",  "Speed steps count",  "",  "int",  "14",  "*",  False,
};
static int _getspcnt(iONode node) {
  int defval = xInt( RocsWgen_spcnt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "spcnt", defval );
}
static void _setspcnt(iONode node, int p_spcnt) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "spcnt", p_spcnt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * startupscid
 */
static struct __attrdef RocsWgen_startupscid = {
  "startupscid",  "Startup schedule ID.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getstartupscid(iONode node) {
  const char* defval = xStr( RocsWgen_startupscid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "startupscid", defval );
}
static void _setstartupscid(iONode node, const char* p_startupscid) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "startupscid", p_startupscid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * startuptourid
 */
static struct __attrdef RocsWgen_startuptourid = {
  "startuptourid",  "Startup tour ID.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getstartuptourid(iONode node) {
  const char* defval = xStr( RocsWgen_startuptourid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "startuptourid", defval );
}
static void _setstartuptourid(iONode node, const char* p_startuptourid) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "startuptourid", p_startuptourid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sw
 */
static struct __attrdef RocsWgen_sw = {
  "sw",  "Change direction in P50 protocol.(Use dir=true/false)",  "",  "bool",  "false",  "",  False,
};
static Boolean _issw(iONode node) {
  Boolean defval = xBool( RocsWgen_sw );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "sw", defval );
}
static void _setsw(iONode node, Boolean p_sw) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "sw", p_sw );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * swaptimer
 */
static struct __attrdef RocsWgen_swaptimer = {
  "swaptimer",  "Swap placing timer; Loco should wait this time before processing the swap.",  "ms",  "int",  "0",  "0-*",  False,
};
static int _getswaptimer(iONode node) {
  int defval = xInt( RocsWgen_swaptimer );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "swaptimer", defval );
}
static void _setswaptimer(iONode node, int p_swaptimer) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "swaptimer", p_swaptimer );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * throttleid
 */
static struct __attrdef RocsWgen_throttleid = {
  "throttleid",  "Throttle ID to which this loco is dispatched.",  "",  "char*",  "NULL",  "*",  False,
};
static const char* _getthrottleid(iONode node) {
  const char* defval = xStr( RocsWgen_throttleid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "throttleid", defval );
}
static void _setthrottleid(iONode node, const char* p_throttleid) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "throttleid", p_throttleid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * throttlenr
 */
static struct __attrdef RocsWgen_throttlenr = {
  "throttlenr",  "Throttle number for receiving the short id.",  "",  "int",  "0",  "0-255",  False,
};
static int _getthrottlenr(iONode node) {
  int defval = xInt( RocsWgen_throttlenr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "throttlenr", defval );
}
static void _setthrottlenr(iONode node, int p_throttlenr) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "throttlenr", p_throttlenr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * tourid
 */
static struct __attrdef RocsWgen_tourid = {
  "tourid",  "Current tour ID.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _gettourid(iONode node) {
  const char* defval = xStr( RocsWgen_tourid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "tourid", defval );
}
static void _settourid(iONode node, const char* p_tourid) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "tourid", p_tourid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * train
 */
static struct __attrdef RocsWgen_train = {
  "train",  "Operator consist ID",  "",  "string",  "",  "*",  False,
};
static const char* _gettrain(iONode node) {
  const char* defval = xStr( RocsWgen_train );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "train", defval );
}
static void _settrain(iONode node, const char* p_train) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "train", p_train );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * trainlen
 */
static struct __attrdef RocsWgen_trainlen = {
  "trainlen",  "Total train length",  "",  "int",  "0",  "0-*",  False,
};
static int _gettrainlen(iONode node) {
  int defval = xInt( RocsWgen_trainlen );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "trainlen", defval );
}
static void _settrainlen(iONode node, int p_trainlen) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "trainlen", p_trainlen );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * trainweight
 */
static struct __attrdef RocsWgen_trainweight = {
  "trainweight",  "Total train weight",  "ton",  "int",  "0",  "0-*",  False,
};
static int _gettrainweight(iONode node) {
  int defval = xInt( RocsWgen_trainweight );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getInt( node, "trainweight", defval );
}
static void _settrainweight(iONode node, int p_trainweight) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setInt( node, "trainweight", p_trainweight );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ttlib
 */
static struct __attrdef RocsWgen_ttlib = {
  "ttlib",  "TurntableDriver library",  "",  "string",  "./ttdriver",  "",  False,
};
static const char* _getttlib(iONode node) {
  const char* defval = xStr( RocsWgen_ttlib );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "ttlib", defval );
}
static void _setttlib(iONode node, const char* p_ttlib) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "ttlib", p_ttlib );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usebbt
 */
static struct __attrdef RocsWgen_usebbt = {
  "usebbt",  "Use block brake time.",  "",  "bool",  "False",  "",  False,
};
static Boolean _isusebbt(iONode node) {
  Boolean defval = xBool( RocsWgen_usebbt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "usebbt", defval );
}
static void _setusebbt(iONode node, Boolean p_usebbt) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "usebbt", p_usebbt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usedepartdelay
 */
static struct __attrdef RocsWgen_usedepartdelay = {
  "usedepartdelay",  "Use the depart delay defined in the current block.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isusedepartdelay(iONode node) {
  Boolean defval = xBool( RocsWgen_usedepartdelay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "usedepartdelay", defval );
}
static void _setusedepartdelay(iONode node, Boolean p_usedepartdelay) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "usedepartdelay", p_usedepartdelay );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usemanualroutes
 */
static struct __attrdef RocsWgen_usemanualroutes = {
  "usemanualroutes",  "Use manual set routes only.",  "",  "bool",  "False",  "",  False,
};
static Boolean _isusemanualroutes(iONode node) {
  Boolean defval = xBool( RocsWgen_usemanualroutes );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "usemanualroutes", defval );
}
static void _setusemanualroutes(iONode node, Boolean p_usemanualroutes) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "usemanualroutes", p_usemanualroutes );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * useownwaittime
 */
static struct __attrdef RocsWgen_useownwaittime = {
  "useownwaittime",  "Overwrites block wait settings.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isuseownwaittime(iONode node) {
  Boolean defval = xBool( RocsWgen_useownwaittime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "useownwaittime", defval );
}
static void _setuseownwaittime(iONode node, Boolean p_useownwaittime) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "useownwaittime", p_useownwaittime );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usescheduletime
 */
static struct __attrdef RocsWgen_usescheduletime = {
  "usescheduletime",  "Use departure time in schedules.",  "",  "bool",  "False",  "",  False,
};
static Boolean _isusescheduletime(iONode node) {
  Boolean defval = xBool( RocsWgen_usescheduletime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "usescheduletime", defval );
}
static void _setusescheduletime(iONode node, Boolean p_usescheduletime) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "usescheduletime", p_usescheduletime );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usesecaddr
 */
static struct __attrdef RocsWgen_usesecaddr = {
  "usesecaddr",  "Use secondary address for speed commands.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isusesecaddr(iONode node) {
  Boolean defval = xBool( RocsWgen_usesecaddr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "usesecaddr", defval );
}
static void _setusesecaddr(iONode node, Boolean p_usesecaddr) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "usesecaddr", p_usesecaddr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * useshortid
 */
static struct __attrdef RocsWgen_useshortid = {
  "useshortid",  "Use short ID to send to throttle.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isuseshortid(iONode node) {
  Boolean defval = xBool( RocsWgen_useshortid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "useshortid", defval );
}
static void _setuseshortid(iONode node, Boolean p_useshortid) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "useshortid", p_useshortid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * v0onswap
 */
static struct __attrdef RocsWgen_v0onswap = {
  "v0onswap",  "Command V0 on swap to inform the decoder.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isv0onswap(iONode node) {
  Boolean defval = xBool( RocsWgen_v0onswap );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getBool( node, "v0onswap", defval );
}
static void _setv0onswap(iONode node, Boolean p_v0onswap) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setBool( node, "v0onswap", p_v0onswap );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * value
 */
static struct __attrdef RocsWgen_value = {
  "value",  "Financial value of loco.",  "",  "string",  "",  "*",  False,
};
static const char* _getvalue(iONode node) {
  const char* defval = xStr( RocsWgen_value );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_lc, node );
  return NodeOp.getStr( node, "value", defval );
}
static void _setvalue(iONode node, const char* p_value) {
  if( node == NULL ) return;
  xNode( RocsWgen_lc, node );
  NodeOp.setStr( node, "value", p_value );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * fundef
 */
static struct __nodedef RocsWgen_fundef = {
  "fundef",  "",  False,  "n",};
static iONode _getfundef(iONode node) {
  xNode( RocsWgen_lc, node );
  return NodeOp.findNode( node, "fundef");
}


static iONode _nextfundef(iONode node, iONode child) {
  xNode( RocsWgen_lc, node );
  return NodeOp.findNextNode( node, child);
}
static void _setfundef(iONode node, iONode p_fundef) {
  xNode( RocsWgen_lc, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * cvbyte
 */
static struct __nodedef RocsWgen_cvbyte = {
  "cvbyte",  "",  False,  "n",};
static iONode _getcvbyte(iONode node) {
  xNode( RocsWgen_lc, node );
  return NodeOp.findNode( node, "cvbyte");
}


static iONode _nextcvbyte(iONode node, iONode child) {
  xNode( RocsWgen_lc, node );
  return NodeOp.findNextNode( node, child);
}
static void _setcvbyte(iONode node, iONode p_cvbyte) {
  xNode( RocsWgen_lc, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * actionctrl
 */
static struct __nodedef RocsWgen_actionctrl = {
  "actionctrl",  "",  False,  "n",};
static iONode _getactionctrl(iONode node) {
  xNode( RocsWgen_lc, node );
  return NodeOp.findNode( node, "actionctrl");
}


static iONode _nextactionctrl(iONode node, iONode child) {
  xNode( RocsWgen_lc, node );
  return NodeOp.findNextNode( node, child);
}
static void _setactionctrl(iONode node, iONode p_actionctrl) {
  xNode( RocsWgen_lc, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * bbt
 */
static struct __nodedef RocsWgen_bbt = {
  "bbt",  "",  False,  "n",};
static iONode _getbbt(iONode node) {
  xNode( RocsWgen_lc, node );
  return NodeOp.findNode( node, "bbt");
}


static iONode _nextbbt(iONode node, iONode child) {
  xNode( RocsWgen_lc, node );
  return NodeOp.findNextNode( node, child);
}
static void _setbbt(iONode node, iONode p_bbt) {
  xNode( RocsWgen_lc, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * sbt
 */
static struct __nodedef RocsWgen_sbt = {
  "sbt",  "",  False,  "n",};
static iONode _getsbt(iONode node) {
  xNode( RocsWgen_lc, node );
  return NodeOp.findNode( node, "sbt");
}


static iONode _nextsbt(iONode node, iONode child) {
  xNode( RocsWgen_lc, node );
  return NodeOp.findNextNode( node, child);
}
static void _setsbt(iONode node, iONode p_sbt) {
  xNode( RocsWgen_lc, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[136] = {NULL};
static struct __nodedef* nodeList[6] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_lc.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node lc not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node lc not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_V;
  attrList[1] = &RocsWgen_V_Rcru;
  attrList[2] = &RocsWgen_V_Rmax;
  attrList[3] = &RocsWgen_V_Rmid;
  attrList[4] = &RocsWgen_V_Rmin;
  attrList[5] = &RocsWgen_V_cru;
  attrList[6] = &RocsWgen_V_hint;
  attrList[7] = &RocsWgen_V_max;
  attrList[8] = &RocsWgen_V_maxkmh;
  attrList[9] = &RocsWgen_V_maxsec;
  attrList[10] = &RocsWgen_V_mid;
  attrList[11] = &RocsWgen_V_min;
  attrList[12] = &RocsWgen_V_mode;
  attrList[13] = &RocsWgen_V_raw;
  attrList[14] = &RocsWgen_V_rawMax;
  attrList[15] = &RocsWgen_V_realkmh;
  attrList[16] = &RocsWgen_V_step;
  attrList[17] = &RocsWgen_accelmax;
  attrList[18] = &RocsWgen_accelmin;
  attrList[19] = &RocsWgen_active;
  attrList[20] = &RocsWgen_addr;
  attrList[21] = &RocsWgen_adjustaccel;
  attrList[22] = &RocsWgen_bbtcorrection;
  attrList[23] = &RocsWgen_bbtevent;
  attrList[24] = &RocsWgen_bbtkey;
  attrList[25] = &RocsWgen_bbtmaxdiff;
  attrList[26] = &RocsWgen_bbtstartinterval;
  attrList[27] = &RocsWgen_bbtsteps;
  attrList[28] = &RocsWgen_blockenterid;
  attrList[29] = &RocsWgen_blockenterside;
  attrList[30] = &RocsWgen_blockid;
  attrList[31] = &RocsWgen_blockwaittime;
  attrList[32] = &RocsWgen_bus;
  attrList[33] = &RocsWgen_cargo;
  attrList[34] = &RocsWgen_catnr;
  attrList[35] = &RocsWgen_check2in;
  attrList[36] = &RocsWgen_class;
  attrList[37] = &RocsWgen_cmd;
  attrList[38] = &RocsWgen_cmdDelay;
  attrList[39] = &RocsWgen_commuter;
  attrList[40] = &RocsWgen_consist;
  attrList[41] = &RocsWgen_consist_lightsoff;
  attrList[42] = &RocsWgen_consist_syncfun;
  attrList[43] = &RocsWgen_consist_syncfunmap;
  attrList[44] = &RocsWgen_consist_synclights;
  attrList[45] = &RocsWgen_consistcmd;
  attrList[46] = &RocsWgen_decelerate;
  attrList[47] = &RocsWgen_decfile;
  attrList[48] = &RocsWgen_decimage;
  attrList[49] = &RocsWgen_dectype;
  attrList[50] = &RocsWgen_desc;
  attrList[51] = &RocsWgen_destblockid;
  attrList[52] = &RocsWgen_dir;
  attrList[53] = &RocsWgen_dirpause;
  attrList[54] = &RocsWgen_docu;
  attrList[55] = &RocsWgen_engine;
  attrList[56] = &RocsWgen_ent2incorr;
  attrList[57] = &RocsWgen_era;
  attrList[58] = &RocsWgen_evttimer;
  attrList[59] = &RocsWgen_fifotop;
  attrList[60] = &RocsWgen_fn;
  attrList[61] = &RocsWgen_fncnt;
  attrList[62] = &RocsWgen_freeblockonenter;
  attrList[63] = &RocsWgen_fx;
  attrList[64] = &RocsWgen_id;
  attrList[65] = &RocsWgen_identifier;
  attrList[66] = &RocsWgen_ignorefn;
  attrList[67] = &RocsWgen_iid;
  attrList[68] = &RocsWgen_image;
  attrList[69] = &RocsWgen_imagenr;
  attrList[70] = &RocsWgen_inatpre2in;
  attrList[71] = &RocsWgen_info4throttle;
  attrList[72] = &RocsWgen_lclib;
  attrList[73] = &RocsWgen_len;
  attrList[74] = &RocsWgen_manual;
  attrList[75] = &RocsWgen_manually;
  attrList[76] = &RocsWgen_mass;
  attrList[77] = &RocsWgen_maxload;
  attrList[78] = &RocsWgen_maxwaittime;
  attrList[79] = &RocsWgen_mdate;
  attrList[80] = &RocsWgen_mint;
  attrList[81] = &RocsWgen_mode;
  attrList[82] = &RocsWgen_modereason;
  attrList[83] = &RocsWgen_mtime;
  attrList[84] = &RocsWgen_nrcars;
  attrList[85] = &RocsWgen_number;
  attrList[86] = &RocsWgen_oid;
  attrList[87] = &RocsWgen_placing;
  attrList[88] = &RocsWgen_port;
  attrList[89] = &RocsWgen_prev_id;
  attrList[90] = &RocsWgen_priority;
  attrList[91] = &RocsWgen_prot;
  attrList[92] = &RocsWgen_protver;
  attrList[93] = &RocsWgen_purchased;
  attrList[94] = &RocsWgen_reducespeedatenter;
  attrList[95] = &RocsWgen_regulated;
  attrList[96] = &RocsWgen_remark;
  attrList[97] = &RocsWgen_resetplacing;
  attrList[98] = &RocsWgen_restorefx;
  attrList[99] = &RocsWgen_restorefxalways;
  attrList[100] = &RocsWgen_restorespeed;
  attrList[101] = &RocsWgen_resumeauto;
  attrList[102] = &RocsWgen_roadname;
  attrList[103] = &RocsWgen_roaming;
  attrList[104] = &RocsWgen_runtime;
  attrList[105] = &RocsWgen_scheduleid;
  attrList[106] = &RocsWgen_scidx;
  attrList[107] = &RocsWgen_secaddr;
  attrList[108] = &RocsWgen_secondnextblock;
  attrList[109] = &RocsWgen_secspcnt;
  attrList[110] = &RocsWgen_shortid;
  attrList[111] = &RocsWgen_shortin;
  attrList[112] = &RocsWgen_show;
  attrList[113] = &RocsWgen_shuntingdiv;
  attrList[114] = &RocsWgen_spcnt;
  attrList[115] = &RocsWgen_startupscid;
  attrList[116] = &RocsWgen_startuptourid;
  attrList[117] = &RocsWgen_sw;
  attrList[118] = &RocsWgen_swaptimer;
  attrList[119] = &RocsWgen_throttleid;
  attrList[120] = &RocsWgen_throttlenr;
  attrList[121] = &RocsWgen_tourid;
  attrList[122] = &RocsWgen_train;
  attrList[123] = &RocsWgen_trainlen;
  attrList[124] = &RocsWgen_trainweight;
  attrList[125] = &RocsWgen_ttlib;
  attrList[126] = &RocsWgen_usebbt;
  attrList[127] = &RocsWgen_usedepartdelay;
  attrList[128] = &RocsWgen_usemanualroutes;
  attrList[129] = &RocsWgen_useownwaittime;
  attrList[130] = &RocsWgen_usescheduletime;
  attrList[131] = &RocsWgen_usesecaddr;
  attrList[132] = &RocsWgen_useshortid;
  attrList[133] = &RocsWgen_v0onswap;
  attrList[134] = &RocsWgen_value;
  attrList[135] = NULL;
  nodeList[0] = &RocsWgen_fundef;
  nodeList[1] = &RocsWgen_cvbyte;
  nodeList[2] = &RocsWgen_actionctrl;
  nodeList[3] = &RocsWgen_bbt;
  nodeList[4] = &RocsWgen_sbt;
  nodeList[5] = NULL;
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


struct __wLoc wLoc = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "kmh",
  "percent",
  "step",
  "activate",
  "addblock2trip",
  "assigntrain",
  "bidikmh",
  "block",
  "blockside",
  "brake",
  "all",
  "cleaning",
  "goods",
  "ice",
  "light",
  "lightgoods",
  "mixed",
  "none",
  "person",
  "post",
  "regional",
  "shunting",
  "classadd",
  "classdel",
  "classset",
  "climb",
  "consist",
  "cruise",
  "deactivate",
  "direction",
  "dirfun",
  "discover",
  "dispatch",
  "automobile",
  "diesel",
  "electric",
  "steam",
  "fieldcmd",
  "function",
  "go",
  "gomanual",
  "gotoblock",
  "govirtual",
  "info",
  "manualoff",
  "manualon",
  "max",
  "mid",
  "min",
  "auto",
  "halfauto",
  "idle",
  "wait",
  "checkroute",
  "destfound",
  "initdest",
  "nodest",
  "unexpectedenter",
  "unexpectedexit",
  "unexpectedin",
  "waitforevent",
  "pomread",
  "pomwrite",
  "A",
  "C",
  "F",
  "L",
  "M",
  "N",
  "P",
  "S",
  "X",
  "release",
  "releasetrain",
  "reset",
  "resetmanualmode",
  "setmanualmode",
  "shortid",
  "shuntingoff",
  "shuntingon",
  "softreset",
  "stop",
  "stopgo",
  "swap",
  "useschedule",
  "usetour",
  "velocity",
  _getV,
  _setV,
  _getV_Rcru,
  _setV_Rcru,
  _getV_Rmax,
  _setV_Rmax,
  _getV_Rmid,
  _setV_Rmid,
  _getV_Rmin,
  _setV_Rmin,
  _getV_cru,
  _setV_cru,
  _getV_hint,
  _setV_hint,
  _getV_max,
  _setV_max,
  _getV_maxkmh,
  _setV_maxkmh,
  _getV_maxsec,
  _setV_maxsec,
  _getV_mid,
  _setV_mid,
  _getV_min,
  _setV_min,
  _getV_mode,
  _setV_mode,
  _getV_raw,
  _setV_raw,
  _getV_rawMax,
  _setV_rawMax,
  _getV_realkmh,
  _setV_realkmh,
  _getV_step,
  _setV_step,
  _getaccelmax,
  _setaccelmax,
  _getaccelmin,
  _setaccelmin,
  _isactive,
  _setactive,
  _getaddr,
  _setaddr,
  _isadjustaccel,
  _setadjustaccel,
  _getbbtcorrection,
  _setbbtcorrection,
  _isbbtevent,
  _setbbtevent,
  _getbbtkey,
  _setbbtkey,
  _getbbtmaxdiff,
  _setbbtmaxdiff,
  _getbbtstartinterval,
  _setbbtstartinterval,
  _getbbtsteps,
  _setbbtsteps,
  _getblockenterid,
  _setblockenterid,
  _isblockenterside,
  _setblockenterside,
  _getblockid,
  _setblockid,
  _getblockwaittime,
  _setblockwaittime,
  _getbus,
  _setbus,
  _getcargo,
  _setcargo,
  _getcatnr,
  _setcatnr,
  _ischeck2in,
  _setcheck2in,
  _getclass,
  _setclass,
  _getcmd,
  _setcmd,
  _getcmdDelay,
  _setcmdDelay,
  _iscommuter,
  _setcommuter,
  _getconsist,
  _setconsist,
  _isconsist_lightsoff,
  _setconsist_lightsoff,
  _isconsist_syncfun,
  _setconsist_syncfun,
  _getconsist_syncfunmap,
  _setconsist_syncfunmap,
  _isconsist_synclights,
  _setconsist_synclights,
  _isconsistcmd,
  _setconsistcmd,
  _getdecelerate,
  _setdecelerate,
  _getdecfile,
  _setdecfile,
  _getdecimage,
  _setdecimage,
  _getdectype,
  _setdectype,
  _getdesc,
  _setdesc,
  _getdestblockid,
  _setdestblockid,
  _isdir,
  _setdir,
  _getdirpause,
  _setdirpause,
  _getdocu,
  _setdocu,
  _getengine,
  _setengine,
  _getent2incorr,
  _setent2incorr,
  _getera,
  _setera,
  _getevttimer,
  _setevttimer,
  _isfifotop,
  _setfifotop,
  _isfn,
  _setfn,
  _getfncnt,
  _setfncnt,
  _isfreeblockonenter,
  _setfreeblockonenter,
  _getfx,
  _setfx,
  _getid,
  _setid,
  _getidentifier,
  _setidentifier,
  _isignorefn,
  _setignorefn,
  _getiid,
  _setiid,
  _getimage,
  _setimage,
  _getimagenr,
  _setimagenr,
  _isinatpre2in,
  _setinatpre2in,
  _isinfo4throttle,
  _setinfo4throttle,
  _getlclib,
  _setlclib,
  _getlen,
  _setlen,
  _ismanual,
  _setmanual,
  _ismanually,
  _setmanually,
  _getmass,
  _setmass,
  _getmaxload,
  _setmaxload,
  _getmaxwaittime,
  _setmaxwaittime,
  _getmdate,
  _setmdate,
  _getmint,
  _setmint,
  _getmode,
  _setmode,
  _getmodereason,
  _setmodereason,
  _getmtime,
  _setmtime,
  _getnrcars,
  _setnrcars,
  _getnumber,
  _setnumber,
  _getoid,
  _setoid,
  _isplacing,
  _setplacing,
  _getport,
  _setport,
  _getprev_id,
  _setprev_id,
  _getpriority,
  _setpriority,
  _getprot,
  _setprot,
  _getprotver,
  _setprotver,
  _getpurchased,
  _setpurchased,
  _isreducespeedatenter,
  _setreducespeedatenter,
  _isregulated,
  _setregulated,
  _getremark,
  _setremark,
  _isresetplacing,
  _setresetplacing,
  _isrestorefx,
  _setrestorefx,
  _isrestorefxalways,
  _setrestorefxalways,
  _isrestorespeed,
  _setrestorespeed,
  _isresumeauto,
  _setresumeauto,
  _getroadname,
  _setroadname,
  _isroaming,
  _setroaming,
  _getruntime,
  _setruntime,
  _getscheduleid,
  _setscheduleid,
  _getscidx,
  _setscidx,
  _getsecaddr,
  _setsecaddr,
  _issecondnextblock,
  _setsecondnextblock,
  _getsecspcnt,
  _setsecspcnt,
  _getshortid,
  _setshortid,
  _isshortin,
  _setshortin,
  _isshow,
  _setshow,
  _getshuntingdiv,
  _setshuntingdiv,
  _getspcnt,
  _setspcnt,
  _getstartupscid,
  _setstartupscid,
  _getstartuptourid,
  _setstartuptourid,
  _issw,
  _setsw,
  _getswaptimer,
  _setswaptimer,
  _getthrottleid,
  _setthrottleid,
  _getthrottlenr,
  _setthrottlenr,
  _gettourid,
  _settourid,
  _gettrain,
  _settrain,
  _gettrainlen,
  _settrainlen,
  _gettrainweight,
  _settrainweight,
  _getttlib,
  _setttlib,
  _isusebbt,
  _setusebbt,
  _isusedepartdelay,
  _setusedepartdelay,
  _isusemanualroutes,
  _setusemanualroutes,
  _isuseownwaittime,
  _setuseownwaittime,
  _isusescheduletime,
  _setusescheduletime,
  _isusesecaddr,
  _setusesecaddr,
  _isuseshortid,
  _setuseshortid,
  _isv0onswap,
  _setv0onswap,
  _getvalue,
  _setvalue,
  _getfundef,
  _nextfundef,
  _setfundef,
  _getcvbyte,
  _nextcvbyte,
  _setcvbyte,
  _getactionctrl,
  _nextactionctrl,
  _setactionctrl,
  _getbbt,
  _nextbbt,
  _setbbt,
  _getsbt,
  _nextsbt,
  _setsbt,
  _node_dump,
};
