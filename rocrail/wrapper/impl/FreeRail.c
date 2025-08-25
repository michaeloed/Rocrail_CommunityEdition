/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Sep 16 2018 20:06:25)
  * Module: rocrail
  * Date: Sun Sep 16 20:06:26 2018
  */

#include "rocrail/wrapper/public/FreeRail.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.FreeRail
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_rocrail = {
  "rocrail",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_rocrail.name;
}
static const char* _node_remark(void) {
  return RocsWgen_rocrail.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_rocrail.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_rocrail.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * backup
 */
static struct __attrdef RocsWgen_backup = {
  "backup",  "Activate backup for plan files.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isbackup(iONode node) {
  Boolean defval = xBool( RocsWgen_backup );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getBool( node, "backup", defval );
}
static void _setbackup(iONode node, Boolean p_backup) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setBool( node, "backup", p_backup );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * backuppath
 */
static struct __attrdef RocsWgen_backuppath = {
  "backuppath",  "Location of the plan file backups.",  "",  "string",  "backup",  "*",  False,
};
static const char* _getbackuppath(iONode node) {
  const char* defval = xStr( RocsWgen_backuppath );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "backuppath", defval );
}
static void _setbackuppath(iONode node, const char* p_backuppath) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "backuppath", p_backuppath );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * createmodplan
 */
static struct __attrdef RocsWgen_createmodplan = {
  "createmodplan",  "Create a modplan if the planfile does not jet exist.",  "",  "bool",  "false",  "",  False,
};
static Boolean _iscreatemodplan(iONode node) {
  Boolean defval = xBool( RocsWgen_createmodplan );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getBool( node, "createmodplan", defval );
}
static void _setcreatemodplan(iONode node, Boolean p_createmodplan) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setBool( node, "createmodplan", p_createmodplan );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * doneml
 */
static struct __attrdef RocsWgen_doneml = {
  "doneml",  "",  "",  "string",  "",  "",  False,
};
static const char* _getdoneml(iONode node) {
  const char* defval = xStr( RocsWgen_doneml );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "doneml", defval );
}
static void _setdoneml(iONode node, const char* p_doneml) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "doneml", p_doneml );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * donkey
 */
static struct __attrdef RocsWgen_donkey = {
  "donkey",  "",  "",  "string",  "",  "",  False,
};
static const char* _getdonkey(iONode node) {
  const char* defval = xStr( RocsWgen_donkey );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "donkey", defval );
}
static void _setdonkey(iONode node, const char* p_donkey) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "donkey", p_donkey );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * dpiid
 */
static struct __attrdef RocsWgen_dpiid = {
  "dpiid",  "IID to use for dispathing a loco; using default in case not set.",  "",  "string",  "",  "*",  False,
};
static const char* _getdpiid(iONode node) {
  const char* defval = xStr( RocsWgen_dpiid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "dpiid", defval );
}
static void _setdpiid(iONode node, const char* p_dpiid) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "dpiid", p_dpiid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * file
 */
static struct __attrdef RocsWgen_file = {
  "file",  "FreeRail ini-file.",  "",  "string",  "freerail.ini",  "",  False,
};
static const char* _getfile(iONode node) {
  const char* defval = xStr( RocsWgen_file );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "file", defval );
}
static void _setfile(iONode node, const char* p_file) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "file", p_file );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fsutf8
 */
static struct __attrdef RocsWgen_fsutf8 = {
  "fsutf8",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isfsutf8(iONode node) {
  Boolean defval = xBool( RocsWgen_fsutf8 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getBool( node, "fsutf8", defval );
}
static void _setfsutf8(iONode node, Boolean p_fsutf8) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setBool( node, "fsutf8", p_fsutf8 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iconpath
 */
static struct __attrdef RocsWgen_iconpath = {
  "iconpath",  "Location of (function)icons.",  "",  "string",  "icons",  "*",  False,
};
static const char* _geticonpath(iONode node) {
  const char* defval = xStr( RocsWgen_iconpath );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "iconpath", defval );
}
static void _seticonpath(iONode node, const char* p_iconpath) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "iconpath", p_iconpath );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * imgpath
 */
static struct __attrdef RocsWgen_imgpath = {
  "imgpath",  "Location of (loco)images.",  "",  "string",  "images",  "*",  False,
};
static const char* _getimgpath(iONode node) {
  const char* defval = xStr( RocsWgen_imgpath );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "imgpath", defval );
}
static void _setimgpath(iONode node, const char* p_imgpath) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "imgpath", p_imgpath );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * issuepath
 */
static struct __attrdef RocsWgen_issuepath = {
  "issuepath",  "Location of the reported issues.",  "",  "string",  "issues",  "*",  False,
};
static const char* _getissuepath(iONode node) {
  const char* defval = xStr( RocsWgen_issuepath );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "issuepath", defval );
}
static void _setissuepath(iONode node, const char* p_issuepath) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "issuepath", p_issuepath );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * keypath
 */
static struct __attrdef RocsWgen_keypath = {
  "keypath",  "Location of the donation key file.",  "",  "string",  "lic.dat",  "*",  False,
};
static const char* _getkeypath(iONode node) {
  const char* defval = xStr( RocsWgen_keypath );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "keypath", defval );
}
static void _setkeypath(iONode node, const char* p_keypath) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "keypath", p_keypath );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lciid
 */
static struct __attrdef RocsWgen_lciid = {
  "lciid",  "IID to use for mobile decoders; using default in case not set.",  "",  "string",  "",  "*",  False,
};
static const char* _getlciid(iONode node) {
  const char* defval = xStr( RocsWgen_lciid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "lciid", defval );
}
static void _setlciid(iONode node, const char* p_lciid) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "lciid", p_lciid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * libpath
 */
static struct __attrdef RocsWgen_libpath = {
  "libpath",  "Location of the FreeRail libraries.",  "",  "string",  ".",  "*",  False,
};
static const char* _getlibpath(iONode node) {
  const char* defval = xStr( RocsWgen_libpath );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "libpath", defval );
}
static void _setlibpath(iONode node, const char* p_libpath) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "libpath", p_libpath );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * locs
 */
static struct __attrdef RocsWgen_locs = {
  "locs",  "File name of locomotive definitions.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getlocs(iONode node) {
  const char* defval = xStr( RocsWgen_locs );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "locs", defval );
}
static void _setlocs(iONode node, const char* p_locs) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "locs", p_locs );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nodevcheck
 */
static struct __attrdef RocsWgen_nodevcheck = {
  "nodevcheck",  "Do not check availability of serial devices.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isnodevcheck(iONode node) {
  Boolean defval = xBool( RocsWgen_nodevcheck );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getBool( node, "nodevcheck", defval );
}
static void _setnodevcheck(iONode node, Boolean p_nodevcheck) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setBool( node, "nodevcheck", p_nodevcheck );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * occupancy
 */
static struct __attrdef RocsWgen_occupancy = {
  "occupancy",  "File name of block occupancy.",  "",  "string",  "occ.xml",  "*",  False,
};
static const char* _getoccupancy(iONode node) {
  const char* defval = xStr( RocsWgen_occupancy );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "occupancy", defval );
}
static void _setoccupancy(iONode node, const char* p_occupancy) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "occupancy", p_occupancy );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * planfile
 */
static struct __attrdef RocsWgen_planfile = {
  "planfile",  "FreeRail plan-file.",  "",  "string",  "plan.xml",  "",  False,
};
static const char* _getplanfile(iONode node) {
  const char* defval = xStr( RocsWgen_planfile );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "planfile", defval );
}
static void _setplanfile(iONode node, const char* p_planfile) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "planfile", p_planfile );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * poweroffonexit
 */
static struct __attrdef RocsWgen_poweroffonexit = {
  "poweroffonexit",  "Turn track power off on server exit.",  "",  "bool",  "true",  "",  False,
};
static Boolean _ispoweroffonexit(iONode node) {
  Boolean defval = xBool( RocsWgen_poweroffonexit );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getBool( node, "poweroffonexit", defval );
}
static void _setpoweroffonexit(iONode node, Boolean p_poweroffonexit) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setBool( node, "poweroffonexit", p_poweroffonexit );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * poweronatinit
 */
static struct __attrdef RocsWgen_poweronatinit = {
  "poweronatinit",  "Turn track power on at server init.",  "",  "bool",  "false",  "",  False,
};
static Boolean _ispoweronatinit(iONode node) {
  Boolean defval = xBool( RocsWgen_poweronatinit );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getBool( node, "poweronatinit", defval );
}
static void _setpoweronatinit(iONode node, Boolean p_poweronatinit) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setBool( node, "poweronatinit", p_poweronatinit );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ptiid
 */
static struct __attrdef RocsWgen_ptiid = {
  "ptiid",  "IID to use with programming; using default in case not set.",  "",  "string",  "",  "*",  False,
};
static const char* _getptiid(iONode node) {
  const char* defval = xStr( RocsWgen_ptiid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "ptiid", defval );
}
static void _setptiid(iONode node, const char* p_ptiid) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "ptiid", p_ptiid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * resetspfx
 */
static struct __attrdef RocsWgen_resetspfx = {
  "resetspfx",  "Reset all loco functions and speed at startup.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isresetspfx(iONode node) {
  Boolean defval = xBool( RocsWgen_resetspfx );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getBool( node, "resetspfx", defval );
}
static void _setresetspfx(iONode node, Boolean p_resetspfx) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setBool( node, "resetspfx", p_resetspfx );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * runasroot
 */
static struct __attrdef RocsWgen_runasroot = {
  "runasroot",  "Force FreeRail to run as root.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isrunasroot(iONode node) {
  Boolean defval = xBool( RocsWgen_runasroot );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getBool( node, "runasroot", defval );
}
static void _setrunasroot(iONode node, Boolean p_runasroot) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setBool( node, "runasroot", p_runasroot );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sciid
 */
static struct __attrdef RocsWgen_sciid = {
  "sciid",  "Shortcut command station IID",  "",  "string",  "",  "0-*",  False,
};
static const char* _getsciid(iONode node) {
  const char* defval = xStr( RocsWgen_sciid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "sciid", defval );
}
static void _setsciid(iONode node, const char* p_sciid) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "sciid", p_sciid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * scsensor
 */
static struct __attrdef RocsWgen_scsensor = {
  "scsensor",  "Shortcut sensor ID.",  "",  "string",  "",  "0-*",  False,
};
static const char* _getscsensor(iONode node) {
  const char* defval = xStr( RocsWgen_scsensor );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "scsensor", defval );
}
static void _setscsensor(iONode node, const char* p_scsensor) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "scsensor", p_scsensor );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * shutdownonexit
 */
static struct __attrdef RocsWgen_shutdownonexit = {
  "shutdownonexit",  "Shutdown command station on server exit.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isshutdownonexit(iONode node) {
  Boolean defval = xBool( RocsWgen_shutdownonexit );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getBool( node, "shutdownonexit", defval );
}
static void _setshutdownonexit(iONode node, Boolean p_shutdownonexit) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setBool( node, "shutdownonexit", p_shutdownonexit );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * soundpath
 */
static struct __attrdef RocsWgen_soundpath = {
  "soundpath",  "Location of (loco)sounds.",  "",  "string",  "sounds",  "*",  False,
};
static const char* _getsoundpath(iONode node) {
  const char* defval = xStr( RocsWgen_soundpath );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "soundpath", defval );
}
static void _setsoundpath(iONode node, const char* p_soundpath) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "soundpath", p_soundpath );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * soundplayer
 */
static struct __attrdef RocsWgen_soundplayer = {
  "soundplayer",  "Sound player program.",  "",  "string",  "",  "*",  False,
};
static const char* _getsoundplayer(iONode node) {
  const char* defval = xStr( RocsWgen_soundplayer );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "soundplayer", defval );
}
static void _setsoundplayer(iONode node, const char* p_soundplayer) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "soundplayer", p_soundplayer );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * soundplayerlocation
 */
static struct __attrdef RocsWgen_soundplayerlocation = {
  "soundplayerlocation",  "Add loco location as second parameter.",  "",  "bool",  "false",  "",  False,
};
static Boolean _issoundplayerlocation(iONode node) {
  Boolean defval = xBool( RocsWgen_soundplayerlocation );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getBool( node, "soundplayerlocation", defval );
}
static void _setsoundplayerlocation(iONode node, Boolean p_soundplayerlocation) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setBool( node, "soundplayerlocation", p_soundplayerlocation );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sviid
 */
static struct __attrdef RocsWgen_sviid = {
  "sviid",  "IID to use with LN SV programming; using default in case not set.",  "",  "string",  "",  "*",  False,
};
static const char* _getsviid(iONode node) {
  const char* defval = xStr( RocsWgen_sviid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "sviid", defval );
}
static void _setsviid(iONode node, const char* p_sviid) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "sviid", p_sviid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * weatherid
 */
static struct __attrdef RocsWgen_weatherid = {
  "weatherid",  "Default weather ID.",  "",  "string",  "default",  "*",  False,
};
static const char* _getweatherid(iONode node) {
  const char* defval = xStr( RocsWgen_weatherid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocrail, node );
  return NodeOp.getStr( node, "weatherid", defval );
}
static void _setweatherid(iONode node, const char* p_weatherid) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocrail, node );
  NodeOp.setStr( node, "weatherid", p_weatherid );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * r2rnet
 */
static struct __nodedef RocsWgen_r2rnet = {
  "r2rnet",  "Setup for the R2RNet.",  False,  "1",};
static iONode _getr2rnet(iONode node) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNode( node, "r2rnet");
}


static iONode _nextr2rnet(iONode node, iONode child) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNextNode( node, child);
}
static void _setr2rnet(iONode node, iONode p_r2rnet) {
  xNode( RocsWgen_rocrail, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * jsmap
 */
static struct __nodedef RocsWgen_jsmap = {
  "jsmap",  "",  False,  "1",};
static iONode _getjsmap(iONode node) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNode( node, "jsmap");
}


static iONode _nextjsmap(iONode node, iONode child) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNextNode( node, child);
}
static void _setjsmap(iONode node, iONode p_jsmap) {
  xNode( RocsWgen_rocrail, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * clock
 */
static struct __nodedef RocsWgen_clock = {
  "clock",  "clock synchronizer.",  False,  "1",};
static iONode _getclock(iONode node) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNode( node, "clock");
}


static iONode _nextclock(iONode node, iONode child) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNextNode( node, child);
}
static void _setclock(iONode node, iONode p_clock) {
  xNode( RocsWgen_rocrail, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * SnmpService
 */
static struct __nodedef RocsWgen_SnmpService = {
  "SnmpService",  "",  False,  "1",};
static iONode _getSnmpService(iONode node) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNode( node, "SnmpService");
}


static iONode _nextSnmpService(iONode node, iONode child) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNextNode( node, child);
}
static void _setSnmpService(iONode node, iONode p_SnmpService) {
  xNode( RocsWgen_rocrail, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * http
 */
static struct __nodedef RocsWgen_http = {
  "http",  "Http interface for configure the xspooler.",  False,  "1",};
static iONode _gethttp(iONode node) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNode( node, "http");
}


static iONode _nexthttp(iONode node, iONode child) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNextNode( node, child);
}
static void _sethttp(iONode node, iONode p_http) {
  xNode( RocsWgen_rocrail, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * service
 */
static struct __nodedef RocsWgen_service = {
  "service",  "Service for remote FreeRail to negotiate about a loc destination.",  False,  "1",};
static iONode _getservice(iONode node) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNode( node, "service");
}


static iONode _nextservice(iONode node, iONode child) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNextNode( node, child);
}
static void _setservice(iONode node, iONode p_service) {
  xNode( RocsWgen_rocrail, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * devices
 */
static struct __nodedef RocsWgen_devices = {
  "devices",  "List of available server devices.",  False,  "1",};
static iONode _getdevices(iONode node) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNode( node, "devices");
}


static iONode _nextdevices(iONode node, iONode child) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNextNode( node, child);
}
static void _setdevices(iONode node, iONode p_devices) {
  xNode( RocsWgen_rocrail, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * trace
 */
static struct __nodedef RocsWgen_trace = {
  "trace",  "",  False,  "1",};
static iONode _gettrace(iONode node) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNode( node, "trace");
}


static iONode _nexttrace(iONode node, iONode child) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNextNode( node, child);
}
static void _settrace(iONode node, iONode p_trace) {
  xNode( RocsWgen_rocrail, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * digint
 */
static struct __nodedef RocsWgen_digint = {
  "digint",  "Digital Interface definition.",  False,  "n",};
static iONode _getdigint(iONode node) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNode( node, "digint");
}


static iONode _nextdigint(iONode node, iONode child) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNextNode( node, child);
}
static void _setdigint(iONode node, iONode p_digint) {
  xNode( RocsWgen_rocrail, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * tcp
 */
static struct __nodedef RocsWgen_tcp = {
  "tcp",  "Client service port.",  False,  "1",};
static iONode _gettcp(iONode node) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNode( node, "tcp");
}


static iONode _nexttcp(iONode node, iONode child) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNextNode( node, child);
}
static void _settcp(iONode node, iONode p_tcp) {
  xNode( RocsWgen_rocrail, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * srcpcon
 */
static struct __nodedef RocsWgen_srcpcon = {
  "srcpcon",  "SRCP client service port.",  False,  "1",};
static iONode _getsrcpcon(iONode node) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNode( node, "srcpcon");
}


static iONode _nextsrcpcon(iONode node, iONode child) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNextNode( node, child);
}
static void _setsrcpcon(iONode node, iONode p_srcpcon) {
  xNode( RocsWgen_rocrail, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * ctrl
 */
static struct __nodedef RocsWgen_ctrl = {
  "ctrl",  "",  False,  "1",};
static iONode _getctrl(iONode node) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNode( node, "ctrl");
}


static iONode _nextctrl(iONode node, iONode child) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNextNode( node, child);
}
static void _setctrl(iONode node, iONode p_ctrl) {
  xNode( RocsWgen_rocrail, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * anaopt
 */
static struct __nodedef RocsWgen_anaopt = {
  "anaopt",  "Analyser options.",  False,  "1",};
static iONode _getanaopt(iONode node) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNode( node, "anaopt");
}


static iONode _nextanaopt(iONode node, iONode child) {
  xNode( RocsWgen_rocrail, node );
  return NodeOp.findNextNode( node, child);
}
static void _setanaopt(iONode node, iONode p_anaopt) {
  xNode( RocsWgen_rocrail, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[32] = {NULL};
static struct __nodedef* nodeList[14] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_rocrail.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node rocrail not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node rocrail not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_backup;
  attrList[1] = &RocsWgen_backuppath;
  attrList[2] = &RocsWgen_createmodplan;
  attrList[3] = &RocsWgen_doneml;
  attrList[4] = &RocsWgen_donkey;
  attrList[5] = &RocsWgen_dpiid;
  attrList[6] = &RocsWgen_file;
  attrList[7] = &RocsWgen_fsutf8;
  attrList[8] = &RocsWgen_iconpath;
  attrList[9] = &RocsWgen_imgpath;
  attrList[10] = &RocsWgen_issuepath;
  attrList[11] = &RocsWgen_keypath;
  attrList[12] = &RocsWgen_lciid;
  attrList[13] = &RocsWgen_libpath;
  attrList[14] = &RocsWgen_locs;
  attrList[15] = &RocsWgen_nodevcheck;
  attrList[16] = &RocsWgen_occupancy;
  attrList[17] = &RocsWgen_planfile;
  attrList[18] = &RocsWgen_poweroffonexit;
  attrList[19] = &RocsWgen_poweronatinit;
  attrList[20] = &RocsWgen_ptiid;
  attrList[21] = &RocsWgen_resetspfx;
  attrList[22] = &RocsWgen_runasroot;
  attrList[23] = &RocsWgen_sciid;
  attrList[24] = &RocsWgen_scsensor;
  attrList[25] = &RocsWgen_shutdownonexit;
  attrList[26] = &RocsWgen_soundpath;
  attrList[27] = &RocsWgen_soundplayer;
  attrList[28] = &RocsWgen_soundplayerlocation;
  attrList[29] = &RocsWgen_sviid;
  attrList[30] = &RocsWgen_weatherid;
  attrList[31] = NULL;
  nodeList[0] = &RocsWgen_r2rnet;
  nodeList[1] = &RocsWgen_jsmap;
  nodeList[2] = &RocsWgen_clock;
  nodeList[3] = &RocsWgen_SnmpService;
  nodeList[4] = &RocsWgen_http;
  nodeList[5] = &RocsWgen_service;
  nodeList[6] = &RocsWgen_devices;
  nodeList[7] = &RocsWgen_trace;
  nodeList[8] = &RocsWgen_digint;
  nodeList[9] = &RocsWgen_tcp;
  nodeList[10] = &RocsWgen_srcpcon;
  nodeList[11] = &RocsWgen_ctrl;
  nodeList[12] = &RocsWgen_anaopt;
  nodeList[13] = NULL;
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


struct __wFreeRail wFreeRail = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isbackup,
  _setbackup,
  _getbackuppath,
  _setbackuppath,
  _iscreatemodplan,
  _setcreatemodplan,
  _getdoneml,
  _setdoneml,
  _getdonkey,
  _setdonkey,
  _getdpiid,
  _setdpiid,
  _getfile,
  _setfile,
  _isfsutf8,
  _setfsutf8,
  _geticonpath,
  _seticonpath,
  _getimgpath,
  _setimgpath,
  _getissuepath,
  _setissuepath,
  _getkeypath,
  _setkeypath,
  _getlciid,
  _setlciid,
  _getlibpath,
  _setlibpath,
  _getlocs,
  _setlocs,
  _isnodevcheck,
  _setnodevcheck,
  _getoccupancy,
  _setoccupancy,
  _getplanfile,
  _setplanfile,
  _ispoweroffonexit,
  _setpoweroffonexit,
  _ispoweronatinit,
  _setpoweronatinit,
  _getptiid,
  _setptiid,
  _isresetspfx,
  _setresetspfx,
  _isrunasroot,
  _setrunasroot,
  _getsciid,
  _setsciid,
  _getscsensor,
  _setscsensor,
  _isshutdownonexit,
  _setshutdownonexit,
  _getsoundpath,
  _setsoundpath,
  _getsoundplayer,
  _setsoundplayer,
  _issoundplayerlocation,
  _setsoundplayerlocation,
  _getsviid,
  _setsviid,
  _getweatherid,
  _setweatherid,
  _getr2rnet,
  _nextr2rnet,
  _setr2rnet,
  _getjsmap,
  _nextjsmap,
  _setjsmap,
  _getclock,
  _nextclock,
  _setclock,
  _getSnmpService,
  _nextSnmpService,
  _setSnmpService,
  _gethttp,
  _nexthttp,
  _sethttp,
  _getservice,
  _nextservice,
  _setservice,
  _getdevices,
  _nextdevices,
  _setdevices,
  _gettrace,
  _nexttrace,
  _settrace,
  _getdigint,
  _nextdigint,
  _setdigint,
  _gettcp,
  _nexttcp,
  _settcp,
  _getsrcpcon,
  _nextsrcpcon,
  _setsrcpcon,
  _getctrl,
  _nextctrl,
  _setctrl,
  _getanaopt,
  _nextanaopt,
  _setanaopt,
  _node_dump,
};
