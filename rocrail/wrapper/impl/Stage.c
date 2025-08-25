/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/Stage.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Stage
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_sb = {
  "sb",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_sb.name;
}
static const char* _node_remark(void) {
  return RocsWgen_sb.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_sb.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_sb.cardinality;
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
  xNode( RocsWgen_sb, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setStr( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * departdelay
 */
static struct __attrdef RocsWgen_departdelay = {
  "departdelay",  "delay time to wait before loco starts when depart is raised",  "s",  "int",  "0",  "0-*",  False,
};
static int _getdepartdelay(iONode node) {
  int defval = xInt( RocsWgen_departdelay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getInt( node, "departdelay", defval );
}
static void _setdepartdelay(iONode node, int p_departdelay) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setInt( node, "departdelay", p_departdelay );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * desc
 */
static struct __attrdef RocsWgen_desc = {
  "desc",  "Description of stage block.",  "",  "string",  "",  "*",  False,
};
static const char* _getdesc(iONode node) {
  const char* defval = xStr( RocsWgen_desc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * electrified
 */
static struct __attrdef RocsWgen_electrified = {
  "electrified",  "Stage is open for electric locs.",  "",  "bool",  "false",  "",  False,
};
static Boolean _iselectrified(iONode node) {
  Boolean defval = xBool( RocsWgen_electrified );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getBool( node, "electrified", defval );
}
static void _setelectrified(iONode node, Boolean p_electrified) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setBool( node, "electrified", p_electrified );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * entering
 */
static struct __attrdef RocsWgen_entering = {
  "entering",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isentering(iONode node) {
  Boolean defval = xBool( RocsWgen_entering );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getBool( node, "entering", defval );
}
static void _setentering(iONode node, Boolean p_entering) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setBool( node, "entering", p_entering );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * entersignal
 */
static struct __attrdef RocsWgen_entersignal = {
  "entersignal",  "",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getentersignal(iONode node) {
  const char* defval = xStr( RocsWgen_entersignal );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getStr( node, "entersignal", defval );
}
static void _setentersignal(iONode node, const char* p_entersignal) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setStr( node, "entersignal", p_entersignal );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * exitsignal
 */
static struct __attrdef RocsWgen_exitsignal = {
  "exitsignal",  "",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getexitsignal(iONode node) {
  const char* defval = xStr( RocsWgen_exitsignal );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getStr( node, "exitsignal", defval );
}
static void _setexitsignal(iONode node, const char* p_exitsignal) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setStr( node, "exitsignal", p_exitsignal );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * exitspeed
 */
static struct __attrdef RocsWgen_exitspeed = {
  "exitspeed",  "Block speed on departure.",  "",  "string",  "cruise",  "*",  False,
};
static const char* _getexitspeed(iONode node) {
  const char* defval = xStr( RocsWgen_exitspeed );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getStr( node, "exitspeed", defval );
}
static void _setexitspeed(iONode node, const char* p_exitspeed) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setStr( node, "exitspeed", p_exitspeed );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * exitspeedpercent
 */
static struct __attrdef RocsWgen_exitspeedpercent = {
  "exitspeedpercent",  "Block depart speed in percent.",  "%",  "int",  "80",  "0-100",  False,
};
static int _getexitspeedpercent(iONode node) {
  int defval = xInt( RocsWgen_exitspeedpercent );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getInt( node, "exitspeedpercent", defval );
}
static void _setexitspeedpercent(iONode node, int p_exitspeedpercent) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setInt( node, "exitspeedpercent", p_exitspeedpercent );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * exitstate
 */
static struct __attrdef RocsWgen_exitstate = {
  "exitstate",  "",  "",  "string",  "open",  "open,closed",  False,
};
static const char* _getexitstate(iONode node) {
  const char* defval = xStr( RocsWgen_exitstate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getStr( node, "exitstate", defval );
}
static void _setexitstate(iONode node, const char* p_exitstate) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setStr( node, "exitstate", p_exitstate );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbenterid
 */
static struct __attrdef RocsWgen_fbenterid = {
  "fbenterid",  "feedback ID",  "",  "string",  "",  "*",  True,
};
static const char* _getfbenterid(iONode node) {
  const char* defval = xStr( RocsWgen_fbenterid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getStr( node, "fbenterid", defval );
}
static void _setfbenterid(iONode node, const char* p_fbenterid) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setStr( node, "fbenterid", p_fbenterid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gap
 */
static struct __attrdef RocsWgen_gap = {
  "gap",  "Train gap.",  "cm",  "int",  "5",  "0-*",  False,
};
static int _getgap(iONode node) {
  int defval = xInt( RocsWgen_gap );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getInt( node, "gap", defval );
}
static void _setgap(iONode node, int p_gap) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setInt( node, "gap", p_gap );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "",  "",  "string",  "?",  "*",  True,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * inatlen
 */
static struct __attrdef RocsWgen_inatlen = {
  "inatlen",  "In event if train length fits in the current sections.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isinatlen(iONode node) {
  Boolean defval = xBool( RocsWgen_inatlen );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getBool( node, "inatlen", defval );
}
static void _setinatlen(iONode node, Boolean p_inatlen) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setBool( node, "inatlen", p_inatlen );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * locid
 */
static struct __attrdef RocsWgen_locid = {
  "locid",  "The loc which is actualy in the block or is comming or going.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getlocid(iONode node) {
  const char* defval = xStr( RocsWgen_locid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getStr( node, "locid", defval );
}
static void _setlocid(iONode node, const char* p_locid) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setStr( node, "locid", p_locid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * maxwaittime
 */
static struct __attrdef RocsWgen_maxwaittime = {
  "maxwaittime",  "Max. wait time in case of wait_random.",  "s",  "int",  "30",  "0-*",  False,
};
static int _getmaxwaittime(iONode node) {
  int defval = xInt( RocsWgen_maxwaittime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getInt( node, "maxwaittime", defval );
}
static void _setmaxwaittime(iONode node, int p_maxwaittime) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setInt( node, "maxwaittime", p_maxwaittime );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * minocc
 */
static struct __attrdef RocsWgen_minocc = {
  "minocc",  "Minimal occupation before exit block.",  "",  "int",  "0",  "0-*",  False,
};
static int _getminocc(iONode node) {
  int defval = xInt( RocsWgen_minocc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getInt( node, "minocc", defval );
}
static void _setminocc(iONode node, int p_minocc) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setInt( node, "minocc", p_minocc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * minwaittime
 */
static struct __attrdef RocsWgen_minwaittime = {
  "minwaittime",  "Min. wait time in case of wait_random.",  "s",  "int",  "1",  "0-*",  False,
};
static int _getminwaittime(iONode node) {
  int defval = xInt( RocsWgen_minwaittime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getInt( node, "minwaittime", defval );
}
static void _setminwaittime(iONode node, int p_minwaittime) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setInt( node, "minwaittime", p_minwaittime );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * randomrate
 */
static struct __attrdef RocsWgen_randomrate = {
  "randomrate",  "Rate of randomness. 0=Not used",  "",  "int",  "10",  "0-*",  False,
};
static int _getrandomrate(iONode node) {
  int defval = xInt( RocsWgen_randomrate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getInt( node, "randomrate", defval );
}
static void _setrandomrate(iONode node, int p_randomrate) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setInt( node, "randomrate", p_randomrate );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * remote
 */
static struct __attrdef RocsWgen_remote = {
  "remote",  "This flag is set by the R2Rnet object.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isremote(iONode node) {
  Boolean defval = xBool( RocsWgen_remote );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getBool( node, "remote", defval );
}
static void _setremote(iONode node, Boolean p_remote) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setBool( node, "remote", p_remote );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * reserved
 */
static struct __attrdef RocsWgen_reserved = {
  "reserved",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isreserved(iONode node) {
  Boolean defval = xBool( RocsWgen_reserved );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getBool( node, "reserved", defval );
}
static void _setreserved(iONode node, Boolean p_reserved) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setBool( node, "reserved", p_reserved );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * rrid
 */
static struct __attrdef RocsWgen_rrid = {
  "rrid",  "This id is set by the R2Rnet object.",  "",  "const char*",  "",  "",  False,
};
static const char* _getrrid(iONode node) {
  const char* defval = xStr( RocsWgen_rrid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getStr( node, "rrid", defval );
}
static void _setrrid(iONode node, const char* p_rrid) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setStr( node, "rrid", p_rrid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * secid
 */
static struct __attrdef RocsWgen_secid = {
  "secid",  "",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getsecid(iONode node) {
  const char* defval = xStr( RocsWgen_secid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getStr( node, "secid", defval );
}
static void _setsecid(iONode node, const char* p_secid) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setStr( node, "secid", p_secid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * slen
 */
static struct __attrdef RocsWgen_slen = {
  "slen",  "Section length.",  "cm",  "int",  "30",  "0-*",  False,
};
static int _getslen(iONode node) {
  int defval = xInt( RocsWgen_slen );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getInt( node, "slen", defval );
}
static void _setslen(iONode node, int p_slen) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setInt( node, "slen", p_slen );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * speedpercent
 */
static struct __attrdef RocsWgen_speedpercent = {
  "speedpercent",  "Block arrive speed in percent.",  "%",  "int",  "10",  "0-100",  False,
};
static int _getspeedpercent(iONode node) {
  int defval = xInt( RocsWgen_speedpercent );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getInt( node, "speedpercent", defval );
}
static void _setspeedpercent(iONode node, int p_speedpercent) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setInt( node, "speedpercent", p_speedpercent );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * state
 */
static struct __attrdef RocsWgen_state = {
  "state",  "",  "",  "string",  "open",  "open,closed",  False,
};
static const char* _getstate(iONode node) {
  const char* defval = xStr( RocsWgen_state );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getStr( node, "state", defval );
}
static void _setstate(iONode node, const char* p_state) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setStr( node, "state", p_state );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * stopspeed
 */
static struct __attrdef RocsWgen_stopspeed = {
  "stopspeed",  "Block speed on arrive and stop.",  "",  "string",  "min",  "min,percent",  False,
};
static const char* _getstopspeed(iONode node) {
  const char* defval = xStr( RocsWgen_stopspeed );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getStr( node, "stopspeed", defval );
}
static void _setstopspeed(iONode node, const char* p_stopspeed) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setStr( node, "stopspeed", p_stopspeed );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * suitswell
 */
static struct __attrdef RocsWgen_suitswell = {
  "suitswell",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _issuitswell(iONode node) {
  Boolean defval = xBool( RocsWgen_suitswell );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getBool( node, "suitswell", defval );
}
static void _setsuitswell(iONode node, Boolean p_suitswell) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setBool( node, "suitswell", p_suitswell );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * totallength
 */
static struct __attrdef RocsWgen_totallength = {
  "totallength",  "Temporary calculated stageblock length for viewing usage only. (Dialog)",  "",  "int",  "0",  "0-*",  False,
};
static int _gettotallength(iONode node) {
  int defval = xInt( RocsWgen_totallength );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getInt( node, "totallength", defval );
}
static void _settotallength(iONode node, int p_totallength) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setInt( node, "totallength", p_totallength );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * totalsections
 */
static struct __attrdef RocsWgen_totalsections = {
  "totalsections",  "Temporary calculated number of sections for viewing usage only. (Dialog)",  "",  "int",  "0",  "0-*",  False,
};
static int _gettotalsections(iONode node) {
  int defval = xInt( RocsWgen_totalsections );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getInt( node, "totalsections", defval );
}
static void _settotalsections(iONode node, int p_totalsections) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setInt( node, "totalsections", p_totalsections );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usewd
 */
static struct __attrdef RocsWgen_usewd = {
  "usewd",  "Use a watchdog for compressing when needed.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isusewd(iONode node) {
  Boolean defval = xBool( RocsWgen_usewd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getBool( node, "usewd", defval );
}
static void _setusewd(iONode node, Boolean p_usewd) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setBool( node, "usewd", p_usewd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * waitmode
 */
static struct __attrdef RocsWgen_waitmode = {
  "waitmode",  "",  "",  "string",  "random",  "random,fixed,loc,none",  False,
};
static const char* _getwaitmode(iONode node) {
  const char* defval = xStr( RocsWgen_waitmode );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getStr( node, "waitmode", defval );
}
static void _setwaitmode(iONode node, const char* p_waitmode) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setStr( node, "waitmode", p_waitmode );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * waittime
 */
static struct __attrdef RocsWgen_waittime = {
  "waittime",  "Wait time in case of wait_fixed.",  "s",  "int",  "1",  "0-*",  False,
};
static int _getwaittime(iONode node) {
  int defval = xInt( RocsWgen_waittime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sb, node );
  return NodeOp.getInt( node, "waittime", defval );
}
static void _setwaittime(iONode node, int p_waittime) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setInt( node, "waittime", p_waittime );
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
  xNode( RocsWgen_sb, node );
  return NodeOp.getInt( node, "x", defval );
}
static void _setx(iONode node, int p_x) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
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
  xNode( RocsWgen_sb, node );
  return NodeOp.getInt( node, "y", defval );
}
static void _sety(iONode node, int p_y) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
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
  xNode( RocsWgen_sb, node );
  return NodeOp.getInt( node, "z", defval );
}
static void _setz(iONode node, int p_z) {
  if( node == NULL ) return;
  xNode( RocsWgen_sb, node );
  NodeOp.setInt( node, "z", p_z );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * section
 */
static struct __nodedef RocsWgen_section = {
  "section",  "",  False,  "n",};
static iONode _getsection(iONode node) {
  xNode( RocsWgen_sb, node );
  return NodeOp.findNode( node, "section");
}


static iONode _nextsection(iONode node, iONode child) {
  xNode( RocsWgen_sb, node );
  return NodeOp.findNextNode( node, child);
}
static void _setsection(iONode node, iONode p_section) {
  xNode( RocsWgen_sb, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * actionctrl
 */
static struct __nodedef RocsWgen_actionctrl = {
  "actionctrl",  "",  False,  "n",};
static iONode _getactionctrl(iONode node) {
  xNode( RocsWgen_sb, node );
  return NodeOp.findNode( node, "actionctrl");
}


static iONode _nextactionctrl(iONode node, iONode child) {
  xNode( RocsWgen_sb, node );
  return NodeOp.findNextNode( node, child);
}
static void _setactionctrl(iONode node, iONode p_actionctrl) {
  xNode( RocsWgen_sb, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[37] = {NULL};
static struct __nodedef* nodeList[3] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_sb.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node sb not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node sb not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_cmd;
  attrList[1] = &RocsWgen_departdelay;
  attrList[2] = &RocsWgen_desc;
  attrList[3] = &RocsWgen_electrified;
  attrList[4] = &RocsWgen_entering;
  attrList[5] = &RocsWgen_entersignal;
  attrList[6] = &RocsWgen_exitsignal;
  attrList[7] = &RocsWgen_exitspeed;
  attrList[8] = &RocsWgen_exitspeedpercent;
  attrList[9] = &RocsWgen_exitstate;
  attrList[10] = &RocsWgen_fbenterid;
  attrList[11] = &RocsWgen_gap;
  attrList[12] = &RocsWgen_id;
  attrList[13] = &RocsWgen_inatlen;
  attrList[14] = &RocsWgen_locid;
  attrList[15] = &RocsWgen_maxwaittime;
  attrList[16] = &RocsWgen_minocc;
  attrList[17] = &RocsWgen_minwaittime;
  attrList[18] = &RocsWgen_randomrate;
  attrList[19] = &RocsWgen_remote;
  attrList[20] = &RocsWgen_reserved;
  attrList[21] = &RocsWgen_rrid;
  attrList[22] = &RocsWgen_secid;
  attrList[23] = &RocsWgen_slen;
  attrList[24] = &RocsWgen_speedpercent;
  attrList[25] = &RocsWgen_state;
  attrList[26] = &RocsWgen_stopspeed;
  attrList[27] = &RocsWgen_suitswell;
  attrList[28] = &RocsWgen_totallength;
  attrList[29] = &RocsWgen_totalsections;
  attrList[30] = &RocsWgen_usewd;
  attrList[31] = &RocsWgen_waitmode;
  attrList[32] = &RocsWgen_waittime;
  attrList[33] = &RocsWgen_x;
  attrList[34] = &RocsWgen_y;
  attrList[35] = &RocsWgen_z;
  attrList[36] = NULL;
  nodeList[0] = &RocsWgen_section;
  nodeList[1] = &RocsWgen_actionctrl;
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


struct __wStage wStage = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "closed",
  "compress",
  "exitclosed",
  "exitopen",
  "open",
  "startwd",
  "stopwd",
  _getcmd,
  _setcmd,
  _getdepartdelay,
  _setdepartdelay,
  _getdesc,
  _setdesc,
  _iselectrified,
  _setelectrified,
  _isentering,
  _setentering,
  _getentersignal,
  _setentersignal,
  _getexitsignal,
  _setexitsignal,
  _getexitspeed,
  _setexitspeed,
  _getexitspeedpercent,
  _setexitspeedpercent,
  _getexitstate,
  _setexitstate,
  _getfbenterid,
  _setfbenterid,
  _getgap,
  _setgap,
  _getid,
  _setid,
  _isinatlen,
  _setinatlen,
  _getlocid,
  _setlocid,
  _getmaxwaittime,
  _setmaxwaittime,
  _getminocc,
  _setminocc,
  _getminwaittime,
  _setminwaittime,
  _getrandomrate,
  _setrandomrate,
  _isremote,
  _setremote,
  _isreserved,
  _setreserved,
  _getrrid,
  _setrrid,
  _getsecid,
  _setsecid,
  _getslen,
  _setslen,
  _getspeedpercent,
  _setspeedpercent,
  _getstate,
  _setstate,
  _getstopspeed,
  _setstopspeed,
  _issuitswell,
  _setsuitswell,
  _gettotallength,
  _settotallength,
  _gettotalsections,
  _settotalsections,
  _isusewd,
  _setusewd,
  _getwaitmode,
  _setwaitmode,
  _getwaittime,
  _setwaittime,
  _getx,
  _setx,
  _gety,
  _sety,
  _getz,
  _setz,
  _getsection,
  _nextsection,
  _setsection,
  _getactionctrl,
  _nextactionctrl,
  _setactionctrl,
  _node_dump,
};
