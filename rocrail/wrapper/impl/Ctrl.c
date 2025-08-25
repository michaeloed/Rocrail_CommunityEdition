/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Ctrl.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Ctrl
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_ctrl = {
  "ctrl",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_ctrl.name;
}
static const char* _node_remark(void) {
  return RocsWgen_ctrl.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_ctrl.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_ctrl.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * actiontimer60
 */
static struct __attrdef RocsWgen_actiontimer60 = {
  "actiontimer60",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isactiontimer60(iONode node) {
  Boolean defval = xBool( RocsWgen_actiontimer60 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "actiontimer60", defval );
}
static void _setactiontimer60(iONode node, Boolean p_actiontimer60) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "actiontimer60", p_actiontimer60 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * allowzerothrottleid
 */
static struct __attrdef RocsWgen_allowzerothrottleid = {
  "allowzerothrottleid",  "Allow broadcasting event coming from zero throttle IDs.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isallowzerothrottleid(iONode node) {
  Boolean defval = xBool( RocsWgen_allowzerothrottleid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "allowzerothrottleid", defval );
}
static void _setallowzerothrottleid(iONode node, Boolean p_allowzerothrottleid) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "allowzerothrottleid", p_allowzerothrottleid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blockinitpause
 */
static struct __attrdef RocsWgen_blockinitpause = {
  "blockinitpause",  "Pause between the block init commands.",  "ms",  "int",  "0",  "0-5000",  False,
};
static int _getblockinitpause(iONode node) {
  int defval = xInt( RocsWgen_blockinitpause );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getInt( node, "blockinitpause", defval );
}
static void _setblockinitpause(iONode node, int p_blockinitpause) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setInt( node, "blockinitpause", p_blockinitpause );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * closenoevents
 */
static struct __attrdef RocsWgen_closenoevents = {
  "closenoevents",  "Close block if no event is defined.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isclosenoevents(iONode node) {
  Boolean defval = xBool( RocsWgen_closenoevents );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "closenoevents", defval );
}
static void _setclosenoevents(iONode node, Boolean p_closenoevents) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "closenoevents", p_closenoevents );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * closeonghost
 */
static struct __attrdef RocsWgen_closeonghost = {
  "closeonghost",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _iscloseonghost(iONode node) {
  Boolean defval = xBool( RocsWgen_closeonghost );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "closeonghost", defval );
}
static void _setcloseonghost(iONode node, Boolean p_closeonghost) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "closeonghost", p_closeonghost );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * createguestonbidi
 */
static struct __attrdef RocsWgen_createguestonbidi = {
  "createguestonbidi",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _iscreateguestonbidi(iONode node) {
  Boolean defval = xBool( RocsWgen_createguestonbidi );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "createguestonbidi", defval );
}
static void _setcreateguestonbidi(iONode node, Boolean p_createguestonbidi) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "createguestonbidi", p_createguestonbidi );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * defaspect
 */
static struct __attrdef RocsWgen_defaspect = {
  "defaspect",  "Default signal aspect.",  "",  "string",  "red",  "red,green,yellow,white",  False,
};
static const char* _getdefaspect(iONode node) {
  const char* defval = xStr( RocsWgen_defaspect );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getStr( node, "defaspect", defval );
}
static void _setdefaspect(iONode node, const char* p_defaspect) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setStr( node, "defaspect", p_defaspect );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * disableblockwait4gomanual
 */
static struct __attrdef RocsWgen_disableblockwait4gomanual = {
  "disableblockwait4gomanual",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isdisableblockwait4gomanual(iONode node) {
  Boolean defval = xBool( RocsWgen_disableblockwait4gomanual );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "disableblockwait4gomanual", defval );
}
static void _setdisableblockwait4gomanual(iONode node, Boolean p_disableblockwait4gomanual) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "disableblockwait4gomanual", p_disableblockwait4gomanual );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * disablerouteVreduce
 */
static struct __attrdef RocsWgen_disablerouteVreduce = {
  "disablerouteVreduce",  "Global disable route speed reducing by thrown switches.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isdisablerouteVreduce(iONode node) {
  Boolean defval = xBool( RocsWgen_disablerouteVreduce );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "disablerouteVreduce", defval );
}
static void _setdisablerouteVreduce(iONode node, Boolean p_disablerouteVreduce) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "disablerouteVreduce", p_disablerouteVreduce );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * disablesteal
 */
static struct __attrdef RocsWgen_disablesteal = {
  "disablesteal",  "Disable throttle to steal loco control.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isdisablesteal(iONode node) {
  Boolean defval = xBool( RocsWgen_disablesteal );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "disablesteal", defval );
}
static void _setdisablesteal(iONode node, Boolean p_disablesteal) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "disablesteal", p_disablesteal );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ebreakatghost
 */
static struct __attrdef RocsWgen_ebreakatghost = {
  "ebreakatghost",  "Power off a ghost is detected when no ghost is accepted.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isebreakatghost(iONode node) {
  Boolean defval = xBool( RocsWgen_ebreakatghost );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "ebreakatghost", defval );
}
static void _setebreakatghost(iONode node, Boolean p_ebreakatghost) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "ebreakatghost", p_ebreakatghost );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ebreakforceunlock
 */
static struct __attrdef RocsWgen_ebreakforceunlock = {
  "ebreakforceunlock",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isebreakforceunlock(iONode node) {
  Boolean defval = xBool( RocsWgen_ebreakforceunlock );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "ebreakforceunlock", defval );
}
static void _setebreakforceunlock(iONode node, Boolean p_ebreakforceunlock) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "ebreakforceunlock", p_ebreakforceunlock );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * enableanalyzer
 */
static struct __attrdef RocsWgen_enableanalyzer = {
  "enableanalyzer",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isenableanalyzer(iONode node) {
  Boolean defval = xBool( RocsWgen_enableanalyzer );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "enableanalyzer", defval );
}
static void _setenableanalyzer(iONode node, Boolean p_enableanalyzer) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "enableanalyzer", p_enableanalyzer );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * enableswfb
 */
static struct __attrdef RocsWgen_enableswfb = {
  "enableswfb",  "Enable switch position feedbacks.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isenableswfb(iONode node) {
  Boolean defval = xBool( RocsWgen_enableswfb );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "enableswfb", defval );
}
static void _setenableswfb(iONode node, Boolean p_enableswfb) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "enableswfb", p_enableswfb );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * eventtimeout
 */
static struct __attrdef RocsWgen_eventtimeout = {
  "eventtimeout",  "Time to wait for a next event. Disabled when set to zero.",  "s",  "int",  "0",  "0-*",  False,
};
static int _geteventtimeout(iONode node) {
  int defval = xInt( RocsWgen_eventtimeout );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getInt( node, "eventtimeout", defval );
}
static void _seteventtimeout(iONode node, int p_eventtimeout) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setInt( node, "eventtimeout", p_eventtimeout );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * greenaspect
 */
static struct __attrdef RocsWgen_greenaspect = {
  "greenaspect",  "Use green aspect instead of yellow if next block has red.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isgreenaspect(iONode node) {
  Boolean defval = xBool( RocsWgen_greenaspect );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "greenaspect", defval );
}
static void _setgreenaspect(iONode node, Boolean p_greenaspect) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "greenaspect", p_greenaspect );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ignevt
 */
static struct __attrdef RocsWgen_ignevt = {
  "ignevt",  "Ignore multiple events for the same state if comming within this number of 10ms ticks.",  "10ms ticks",  "int",  "5",  "0-*",  False,
};
static int _getignevt(iONode node) {
  int defval = xInt( RocsWgen_ignevt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getInt( node, "ignevt", defval );
}
static void _setignevt(iONode node, int p_ignevt) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setInt( node, "ignevt", p_ignevt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * initfieldpause
 */
static struct __attrdef RocsWgen_initfieldpause = {
  "initfieldpause",  "Pause between the switch commands.",  "ms",  "int",  "500",  "100-5000",  False,
};
static int _getinitfieldpause(iONode node) {
  int defval = xInt( RocsWgen_initfieldpause );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getInt( node, "initfieldpause", defval );
}
static void _setinitfieldpause(iONode node, int p_initfieldpause) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setInt( node, "initfieldpause", p_initfieldpause );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * initfieldpower
 */
static struct __attrdef RocsWgen_initfieldpower = {
  "initfieldpower",  "Set global power on before init field.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isinitfieldpower(iONode node) {
  Boolean defval = xBool( RocsWgen_initfieldpower );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "initfieldpower", defval );
}
static void _setinitfieldpower(iONode node, Boolean p_initfieldpower) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "initfieldpower", p_initfieldpower );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * keepghost
 */
static struct __attrdef RocsWgen_keepghost = {
  "keepghost",  "Keep ghost state until manual reset.",  "",  "bool",  "false",  "",  False,
};
static Boolean _iskeepghost(iONode node) {
  Boolean defval = xBool( RocsWgen_keepghost );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "keepghost", defval );
}
static void _setkeepghost(iONode node, Boolean p_keepghost) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "keepghost", p_keepghost );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * loccnfg
 */
static struct __attrdef RocsWgen_loccnfg = {
  "loccnfg",  "send loco config commands to the CS",  "",  "bool",  "false",  "",  False,
};
static Boolean _isloccnfg(iONode node) {
  Boolean defval = xBool( RocsWgen_loccnfg );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "loccnfg", defval );
}
static void _setloccnfg(iONode node, Boolean p_loccnfg) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "loccnfg", p_loccnfg );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * locostartgap
 */
static struct __attrdef RocsWgen_locostartgap = {
  "locostartgap",  "Time between signalling loco's to start in auto mode.",  "s",  "int",  "0",  "0-*",  False,
};
static int _getlocostartgap(iONode node) {
  int defval = xInt( RocsWgen_locostartgap );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getInt( node, "locostartgap", defval );
}
static void _setlocostartgap(iONode node, int p_locostartgap) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setInt( node, "locostartgap", p_locostartgap );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * minbklc
 */
static struct __attrdef RocsWgen_minbklc = {
  "minbklc",  "Minimal blocklen - loclen.",  "cm",  "int",  "20",  "10-50",  False,
};
static int _getminbklc(iONode node) {
  int defval = xInt( RocsWgen_minbklc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getInt( node, "minbklc", defval );
}
static void _setminbklc(iONode node, int p_minbklc) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setInt( node, "minbklc", p_minbklc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * poweroffatghost
 */
static struct __attrdef RocsWgen_poweroffatghost = {
  "poweroffatghost",  "Power off a ghost is detected when no ghost is accepted.",  "",  "bool",  "true",  "",  False,
};
static Boolean _ispoweroffatghost(iONode node) {
  Boolean defval = xBool( RocsWgen_poweroffatghost );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "poweroffatghost", defval );
}
static void _setpoweroffatghost(iONode node, Boolean p_poweroffatghost) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "poweroffatghost", p_poweroffatghost );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * poweroffatreset
 */
static struct __attrdef RocsWgen_poweroffatreset = {
  "poweroffatreset",  "Power off at reset command.",  "",  "bool",  "true",  "",  False,
};
static Boolean _ispoweroffatreset(iONode node) {
  Boolean defval = xBool( RocsWgen_poweroffatreset );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "poweroffatreset", defval );
}
static void _setpoweroffatreset(iONode node, Boolean p_poweroffatreset) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "poweroffatreset", p_poweroffatreset );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * poweroffonidentmismatch
 */
static struct __attrdef RocsWgen_poweroffonidentmismatch = {
  "poweroffonidentmismatch",  "Power off if the ident code does not match.",  "",  "bool",  "false",  "",  False,
};
static Boolean _ispoweroffonidentmismatch(iONode node) {
  Boolean defval = xBool( RocsWgen_poweroffonidentmismatch );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "poweroffonidentmismatch", defval );
}
static void _setpoweroffonidentmismatch(iONode node, Boolean p_poweroffonidentmismatch) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "poweroffonidentmismatch", p_poweroffonidentmismatch );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * redirecttomaster
 */
static struct __attrdef RocsWgen_redirecttomaster = {
  "redirecttomaster",  "Redirect commands send to a slave consist member to the master loco.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isredirecttomaster(iONode node) {
  Boolean defval = xBool( RocsWgen_redirecttomaster );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "redirecttomaster", defval );
}
static void _setredirecttomaster(iONode node, Boolean p_redirecttomaster) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "redirecttomaster", p_redirecttomaster );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * releaseonidle
 */
static struct __attrdef RocsWgen_releaseonidle = {
  "releaseonidle",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isreleaseonidle(iONode node) {
  Boolean defval = xBool( RocsWgen_releaseonidle );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "releaseonidle", defval );
}
static void _setreleaseonidle(iONode node, Boolean p_releaseonidle) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "releaseonidle", p_releaseonidle );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * restoreschedule
 */
static struct __attrdef RocsWgen_restoreschedule = {
  "restoreschedule",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isrestoreschedule(iONode node) {
  Boolean defval = xBool( RocsWgen_restoreschedule );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "restoreschedule", defval );
}
static void _setrestoreschedule(iONode node, Boolean p_restoreschedule) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "restoreschedule", p_restoreschedule );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * routeswtime
 */
static struct __attrdef RocsWgen_routeswtime = {
  "routeswtime",  "Time between switch commands in routes.",  "ms",  "int",  "10",  "10-10000",  False,
};
static int _getrouteswtime(iONode node) {
  int defval = xInt( RocsWgen_routeswtime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getInt( node, "routeswtime", defval );
}
static void _setrouteswtime(iONode node, int p_routeswtime) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setInt( node, "routeswtime", p_routeswtime );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * savepostime
 */
static struct __attrdef RocsWgen_savepostime = {
  "savepostime",  "save positio timer",  "s",  "int",  "10",  "0-100",  False,
};
static int _getsavepostime(iONode node) {
  int defval = xInt( RocsWgen_savepostime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getInt( node, "savepostime", defval );
}
static void _setsavepostime(iONode node, int p_savepostime) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setInt( node, "savepostime", p_savepostime );
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
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "secondnextblock", defval );
}
static void _setsecondnextblock(iONode node, Boolean p_secondnextblock) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "secondnextblock", p_secondnextblock );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * seed
 */
static struct __attrdef RocsWgen_seed = {
  "seed",  "random seed for block selection",  "",  "int",  "4711",  "0-65535",  False,
};
static int _getseed(iONode node) {
  int defval = xInt( RocsWgen_seed );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getInt( node, "seed", defval );
}
static void _setseed(iONode node, int p_seed) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setInt( node, "seed", p_seed );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * selectshortestblock
 */
static struct __attrdef RocsWgen_selectshortestblock = {
  "selectshortestblock",  "Select shortest block in case block and train length are set.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isselectshortestblock(iONode node) {
  Boolean defval = xBool( RocsWgen_selectshortestblock );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "selectshortestblock", defval );
}
static void _setselectshortestblock(iONode node, Boolean p_selectshortestblock) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "selectshortestblock", p_selectshortestblock );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * semaphorewait
 */
static struct __attrdef RocsWgen_semaphorewait = {
  "semaphorewait",  "Time needed by a semaphore to get in position.",  "s",  "int",  "1",  "0-*",  False,
};
static int _getsemaphorewait(iONode node) {
  int defval = xInt( RocsWgen_semaphorewait );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getInt( node, "semaphorewait", defval );
}
static void _setsemaphorewait(iONode node, int p_semaphorewait) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setInt( node, "semaphorewait", p_semaphorewait );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sgevents
 */
static struct __attrdef RocsWgen_sgevents = {
  "sgevents",  "Process field events for signals.",  "",  "bool",  "false",  "",  False,
};
static Boolean _issgevents(iONode node) {
  Boolean defval = xBool( RocsWgen_sgevents );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "sgevents", defval );
}
static void _setsgevents(iONode node, Boolean p_sgevents) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "sgevents", p_sgevents );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * signalreset
 */
static struct __attrdef RocsWgen_signalreset = {
  "signalreset",  "Time to wait for resetting the signals of previous block. Disabled when set to zero.",  "s",  "int",  "0",  "0-*",  False,
};
static int _getsignalreset(iONode node) {
  int defval = xInt( RocsWgen_signalreset );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getInt( node, "signalreset", defval );
}
static void _setsignalreset(iONode node, int p_signalreset) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setInt( node, "signalreset", p_signalreset );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * signalwait
 */
static struct __attrdef RocsWgen_signalwait = {
  "signalwait",  "Time needed by a signal to set another aspect.",  "s",  "int",  "0",  "0-*",  False,
};
static int _getsignalwait(iONode node) {
  int defval = xInt( RocsWgen_signalwait );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getInt( node, "signalwait", defval );
}
static void _setsignalwait(iONode node, int p_signalwait) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setInt( node, "signalwait", p_signalwait );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * skipsetsg
 */
static struct __attrdef RocsWgen_skipsetsg = {
  "skipsetsg",  "Skip signal commands for signals already in model position.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isskipsetsg(iONode node) {
  Boolean defval = xBool( RocsWgen_skipsetsg );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "skipsetsg", defval );
}
static void _setskipsetsg(iONode node, Boolean p_skipsetsg) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "skipsetsg", p_skipsetsg );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * skipsetsw
 */
static struct __attrdef RocsWgen_skipsetsw = {
  "skipsetsw",  "Skip switch commands in routes for switches already in model position.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isskipsetsw(iONode node) {
  Boolean defval = xBool( RocsWgen_skipsetsw );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "skipsetsw", defval );
}
static void _setskipsetsw(iONode node, Boolean p_skipsetsw) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "skipsetsw", p_skipsetsw );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * stopatin4gomanual
 */
static struct __attrdef RocsWgen_stopatin4gomanual = {
  "stopatin4gomanual",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isstopatin4gomanual(iONode node) {
  Boolean defval = xBool( RocsWgen_stopatin4gomanual );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "stopatin4gomanual", defval );
}
static void _setstopatin4gomanual(iONode node, Boolean p_stopatin4gomanual) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "stopatin4gomanual", p_stopatin4gomanual );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * stopnonecommuter
 */
static struct __attrdef RocsWgen_stopnonecommuter = {
  "stopnonecommuter",  "Stop auto mode for none commuter trains in terminal stations.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isstopnonecommuter(iONode node) {
  Boolean defval = xBool( RocsWgen_stopnonecommuter );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "stopnonecommuter", defval );
}
static void _setstopnonecommuter(iONode node, Boolean p_stopnonecommuter) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "stopnonecommuter", p_stopnonecommuter );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * swtimeout
 */
static struct __attrdef RocsWgen_swtimeout = {
  "swtimeout",  "Switch activation time.",  "ms",  "int",  "250",  "100-1000",  False,
};
static int _getswtimeout(iONode node) {
  int defval = xInt( RocsWgen_swtimeout );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getInt( node, "swtimeout", defval );
}
static void _setswtimeout(iONode node, int p_swtimeout) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setInt( node, "swtimeout", p_swtimeout );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * syncroutes
 */
static struct __attrdef RocsWgen_syncroutes = {
  "syncroutes",  "Synchronize routes.",  "",  "bool",  "false",  "",  False,
};
static Boolean _issyncroutes(iONode node) {
  Boolean defval = xBool( RocsWgen_syncroutes );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "syncroutes", defval );
}
static void _setsyncroutes(iONode node, Boolean p_syncroutes) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "syncroutes", p_syncroutes );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * syncroutetimeout
 */
static struct __attrdef RocsWgen_syncroutetimeout = {
  "syncroutetimeout",  "Timeout in ms for synchronizing routes.",  "",  "int",  "2500",  "",  False,
};
static int _getsyncroutetimeout(iONode node) {
  int defval = xInt( RocsWgen_syncroutetimeout );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getInt( node, "syncroutetimeout", defval );
}
static void _setsyncroutetimeout(iONode node, int p_syncroutetimeout) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setInt( node, "syncroutetimeout", p_syncroutetimeout );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timedsensors
 */
static struct __attrdef RocsWgen_timedsensors = {
  "timedsensors",  "Activate timed sensors.",  "",  "bool",  "false",  "",  False,
};
static Boolean _istimedsensors(iONode node) {
  Boolean defval = xBool( RocsWgen_timedsensors );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "timedsensors", defval );
}
static void _settimedsensors(iONode node, Boolean p_timedsensors) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "timedsensors", p_timedsensors );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usebicom
 */
static struct __attrdef RocsWgen_usebicom = {
  "usebicom",  "Use bi-directional communication.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isusebicom(iONode node) {
  Boolean defval = xBool( RocsWgen_usebicom );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "usebicom", defval );
}
static void _setusebicom(iONode node, Boolean p_usebicom) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "usebicom", p_usebicom );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usebididir
 */
static struct __attrdef RocsWgen_usebididir = {
  "usebididir",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isusebididir(iONode node) {
  Boolean defval = xBool( RocsWgen_usebididir );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "usebididir", defval );
}
static void _setusebididir(iONode node, Boolean p_usebididir) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "usebididir", p_usebididir );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * useident
 */
static struct __attrdef RocsWgen_useident = {
  "useident",  "Use bi-directional identifier for set in block.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isuseident(iONode node) {
  Boolean defval = xBool( RocsWgen_useident );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "useident", defval );
}
static void _setuseident(iONode node, Boolean p_useident) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "useident", p_useident );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * useonlyfirstident
 */
static struct __attrdef RocsWgen_useonlyfirstident = {
  "useonlyfirstident",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isuseonlyfirstident(iONode node) {
  Boolean defval = xBool( RocsWgen_useonlyfirstident );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "useonlyfirstident", defval );
}
static void _setuseonlyfirstident(iONode node, Boolean p_useonlyfirstident) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "useonlyfirstident", p_useonlyfirstident );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * userandomrate
 */
static struct __attrdef RocsWgen_userandomrate = {
  "userandomrate",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isuserandomrate(iONode node) {
  Boolean defval = xBool( RocsWgen_userandomrate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "userandomrate", defval );
}
static void _setuserandomrate(iONode node, Boolean p_userandomrate) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "userandomrate", p_userandomrate );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * v0atpoweron
 */
static struct __attrdef RocsWgen_v0atpoweron = {
  "v0atpoweron",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isv0atpoweron(iONode node) {
  Boolean defval = xBool( RocsWgen_v0atpoweron );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "v0atpoweron", defval );
}
static void _setv0atpoweron(iONode node, Boolean p_v0atpoweron) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "v0atpoweron", p_v0atpoweron );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * v0onebreak
 */
static struct __attrdef RocsWgen_v0onebreak = {
  "v0onebreak",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isv0onebreak(iONode node) {
  Boolean defval = xBool( RocsWgen_v0onebreak );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "v0onebreak", defval );
}
static void _setv0onebreak(iONode node, Boolean p_v0onebreak) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "v0onebreak", p_v0onebreak );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * virtualtimer
 */
static struct __attrdef RocsWgen_virtualtimer = {
  "virtualtimer",  "Virtual step time.",  "s",  "int",  "1",  "1-*",  False,
};
static int _getvirtualtimer(iONode node) {
  int defval = xInt( RocsWgen_virtualtimer );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getInt( node, "virtualtimer", defval );
}
static void _setvirtualtimer(iONode node, int p_virtualtimer) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setInt( node, "virtualtimer", p_virtualtimer );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * weather
 */
static struct __attrdef RocsWgen_weather = {
  "weather",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isweather(iONode node) {
  Boolean defval = xBool( RocsWgen_weather );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ctrl, node );
  return NodeOp.getBool( node, "weather", defval );
}
static void _setweather(iONode node, Boolean p_weather) {
  if( node == NULL ) return;
  xNode( RocsWgen_ctrl, node );
  NodeOp.setBool( node, "weather", p_weather );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[56] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_ctrl.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node ctrl not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node ctrl not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_actiontimer60;
  attrList[1] = &RocsWgen_allowzerothrottleid;
  attrList[2] = &RocsWgen_blockinitpause;
  attrList[3] = &RocsWgen_closenoevents;
  attrList[4] = &RocsWgen_closeonghost;
  attrList[5] = &RocsWgen_createguestonbidi;
  attrList[6] = &RocsWgen_defaspect;
  attrList[7] = &RocsWgen_disableblockwait4gomanual;
  attrList[8] = &RocsWgen_disablerouteVreduce;
  attrList[9] = &RocsWgen_disablesteal;
  attrList[10] = &RocsWgen_ebreakatghost;
  attrList[11] = &RocsWgen_ebreakforceunlock;
  attrList[12] = &RocsWgen_enableanalyzer;
  attrList[13] = &RocsWgen_enableswfb;
  attrList[14] = &RocsWgen_eventtimeout;
  attrList[15] = &RocsWgen_greenaspect;
  attrList[16] = &RocsWgen_ignevt;
  attrList[17] = &RocsWgen_initfieldpause;
  attrList[18] = &RocsWgen_initfieldpower;
  attrList[19] = &RocsWgen_keepghost;
  attrList[20] = &RocsWgen_loccnfg;
  attrList[21] = &RocsWgen_locostartgap;
  attrList[22] = &RocsWgen_minbklc;
  attrList[23] = &RocsWgen_poweroffatghost;
  attrList[24] = &RocsWgen_poweroffatreset;
  attrList[25] = &RocsWgen_poweroffonidentmismatch;
  attrList[26] = &RocsWgen_redirecttomaster;
  attrList[27] = &RocsWgen_releaseonidle;
  attrList[28] = &RocsWgen_restoreschedule;
  attrList[29] = &RocsWgen_routeswtime;
  attrList[30] = &RocsWgen_savepostime;
  attrList[31] = &RocsWgen_secondnextblock;
  attrList[32] = &RocsWgen_seed;
  attrList[33] = &RocsWgen_selectshortestblock;
  attrList[34] = &RocsWgen_semaphorewait;
  attrList[35] = &RocsWgen_sgevents;
  attrList[36] = &RocsWgen_signalreset;
  attrList[37] = &RocsWgen_signalwait;
  attrList[38] = &RocsWgen_skipsetsg;
  attrList[39] = &RocsWgen_skipsetsw;
  attrList[40] = &RocsWgen_stopatin4gomanual;
  attrList[41] = &RocsWgen_stopnonecommuter;
  attrList[42] = &RocsWgen_swtimeout;
  attrList[43] = &RocsWgen_syncroutes;
  attrList[44] = &RocsWgen_syncroutetimeout;
  attrList[45] = &RocsWgen_timedsensors;
  attrList[46] = &RocsWgen_usebicom;
  attrList[47] = &RocsWgen_usebididir;
  attrList[48] = &RocsWgen_useident;
  attrList[49] = &RocsWgen_useonlyfirstident;
  attrList[50] = &RocsWgen_userandomrate;
  attrList[51] = &RocsWgen_v0atpoweron;
  attrList[52] = &RocsWgen_v0onebreak;
  attrList[53] = &RocsWgen_virtualtimer;
  attrList[54] = &RocsWgen_weather;
  attrList[55] = NULL;
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


struct __wCtrl wCtrl = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isactiontimer60,
  _setactiontimer60,
  _isallowzerothrottleid,
  _setallowzerothrottleid,
  _getblockinitpause,
  _setblockinitpause,
  _isclosenoevents,
  _setclosenoevents,
  _iscloseonghost,
  _setcloseonghost,
  _iscreateguestonbidi,
  _setcreateguestonbidi,
  _getdefaspect,
  _setdefaspect,
  _isdisableblockwait4gomanual,
  _setdisableblockwait4gomanual,
  _isdisablerouteVreduce,
  _setdisablerouteVreduce,
  _isdisablesteal,
  _setdisablesteal,
  _isebreakatghost,
  _setebreakatghost,
  _isebreakforceunlock,
  _setebreakforceunlock,
  _isenableanalyzer,
  _setenableanalyzer,
  _isenableswfb,
  _setenableswfb,
  _geteventtimeout,
  _seteventtimeout,
  _isgreenaspect,
  _setgreenaspect,
  _getignevt,
  _setignevt,
  _getinitfieldpause,
  _setinitfieldpause,
  _isinitfieldpower,
  _setinitfieldpower,
  _iskeepghost,
  _setkeepghost,
  _isloccnfg,
  _setloccnfg,
  _getlocostartgap,
  _setlocostartgap,
  _getminbklc,
  _setminbklc,
  _ispoweroffatghost,
  _setpoweroffatghost,
  _ispoweroffatreset,
  _setpoweroffatreset,
  _ispoweroffonidentmismatch,
  _setpoweroffonidentmismatch,
  _isredirecttomaster,
  _setredirecttomaster,
  _isreleaseonidle,
  _setreleaseonidle,
  _isrestoreschedule,
  _setrestoreschedule,
  _getrouteswtime,
  _setrouteswtime,
  _getsavepostime,
  _setsavepostime,
  _issecondnextblock,
  _setsecondnextblock,
  _getseed,
  _setseed,
  _isselectshortestblock,
  _setselectshortestblock,
  _getsemaphorewait,
  _setsemaphorewait,
  _issgevents,
  _setsgevents,
  _getsignalreset,
  _setsignalreset,
  _getsignalwait,
  _setsignalwait,
  _isskipsetsg,
  _setskipsetsg,
  _isskipsetsw,
  _setskipsetsw,
  _isstopatin4gomanual,
  _setstopatin4gomanual,
  _isstopnonecommuter,
  _setstopnonecommuter,
  _getswtimeout,
  _setswtimeout,
  _issyncroutes,
  _setsyncroutes,
  _getsyncroutetimeout,
  _setsyncroutetimeout,
  _istimedsensors,
  _settimedsensors,
  _isusebicom,
  _setusebicom,
  _isusebididir,
  _setusebididir,
  _isuseident,
  _setuseident,
  _isuseonlyfirstident,
  _setuseonlyfirstident,
  _isuserandomrate,
  _setuserandomrate,
  _isv0atpoweron,
  _setv0atpoweron,
  _isv0onebreak,
  _setv0onebreak,
  _getvirtualtimer,
  _setvirtualtimer,
  _isweather,
  _setweather,
  _node_dump,
};
