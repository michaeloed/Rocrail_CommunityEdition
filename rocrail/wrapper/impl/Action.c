/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/Action.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Action
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_ac = {
  "ac",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_ac.name;
}
static const char* _node_remark(void) {
  return RocsWgen_ac.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_ac.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_ac.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * actiontime
 */
static struct __attrdef RocsWgen_actiontime = {
  "actiontime",  "function activation time",  "s",  "int",  "0",  "",  False,
};
static int _getactiontime(iONode node) {
  int defval = xInt( RocsWgen_actiontime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getInt( node, "actiontime", defval );
}
static void _setactiontime(iONode node, int p_actiontime) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setInt( node, "actiontime", p_actiontime );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * activate
 */
static struct __attrdef RocsWgen_activate = {
  "activate",  "action activation at state ON or OFF: default is ON(true)",  "",  "bool",  "true",  "",  False,
};
static Boolean _isactivate(iONode node) {
  Boolean defval = xBool( RocsWgen_activate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getBool( node, "activate", defval );
}
static void _setactivate(iONode node, Boolean p_activate) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setBool( node, "activate", p_activate );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * activated
 */
static struct __attrdef RocsWgen_activated = {
  "activated",  "Pre defined activation.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isactivated(iONode node) {
  Boolean defval = xBool( RocsWgen_activated );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getBool( node, "activated", defval );
}
static void _setactivated(iONode node, Boolean p_activated) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setBool( node, "activated", p_activated );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr
 */
static struct __attrdef RocsWgen_addr = {
  "addr",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getaddr(iONode node) {
  int defval = xInt( RocsWgen_addr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getInt( node, "addr", defval );
}
static void _setaddr(iONode node, int p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
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
  xNode( RocsWgen_ac, node );
  return NodeOp.getInt( node, "bus", defval );
}
static void _setbus(iONode node, int p_bus) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setInt( node, "bus", p_bus );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmd
 */
static struct __attrdef RocsWgen_cmd = {
  "cmd",  "on, off or an external program or script to be executed",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getcmd(iONode node) {
  const char* defval = xStr( RocsWgen_cmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setStr( node, "cmd", p_cmd );
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
  xNode( RocsWgen_ac, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * doublequote
 */
static struct __attrdef RocsWgen_doublequote = {
  "doublequote",  "Double quote under Windows.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isdoublequote(iONode node) {
  Boolean defval = xBool( RocsWgen_doublequote );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getBool( node, "doublequote", defval );
}
static void _setdoublequote(iONode node, Boolean p_doublequote) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setBool( node, "doublequote", p_doublequote );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * every
 */
static struct __attrdef RocsWgen_every = {
  "every",  "Activate every hour:min.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isevery(iONode node) {
  Boolean defval = xBool( RocsWgen_every );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getBool( node, "every", defval );
}
static void _setevery(iONode node, Boolean p_every) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setBool( node, "every", p_every );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * group
 */
static struct __attrdef RocsWgen_group = {
  "group",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getgroup(iONode node) {
  const char* defval = xStr( RocsWgen_group );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getStr( node, "group", defval );
}
static void _setgroup(iONode node, const char* p_group) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setStr( node, "group", p_group );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * hour
 */
static struct __attrdef RocsWgen_hour = {
  "hour",  "action hour",  "",  "int",  "0",  "0-23",  False,
};
static int _gethour(iONode node) {
  int defval = xInt( RocsWgen_hour );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getInt( node, "hour", defval );
}
static void _sethour(iONode node, int p_hour) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setInt( node, "hour", p_hour );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "action id",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iid
 */
static struct __attrdef RocsWgen_iid = {
  "iid",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getiid(iONode node) {
  const char* defval = xStr( RocsWgen_iid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * min
 */
static struct __attrdef RocsWgen_min = {
  "min",  "action minute",  "",  "int",  "0",  "0-59",  False,
};
static int _getmin(iONode node) {
  int defval = xInt( RocsWgen_min );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getInt( node, "min", defval );
}
static void _setmin(iONode node, int p_min) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setInt( node, "min", p_min );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * oid
 */
static struct __attrdef RocsWgen_oid = {
  "oid",  "output id",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getoid(iONode node) {
  const char* defval = xStr( RocsWgen_oid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getStr( node, "oid", defval );
}
static void _setoid(iONode node, const char* p_oid) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setStr( node, "oid", p_oid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * param
 */
static struct __attrdef RocsWgen_param = {
  "param",  "command parameter like schedule id for lc",  "",  "string",  "",  "*",  False,
};
static const char* _getparam(iONode node) {
  const char* defval = xStr( RocsWgen_param );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getStr( node, "param", defval );
}
static void _setparam(iONode node, const char* p_param) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setStr( node, "param", p_param );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setInt( node, "port", p_port );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * random
 */
static struct __attrdef RocsWgen_random = {
  "random",  "Use time for random activation.",  "",  "bool",  "false",  "",  False,
};
static Boolean _israndom(iONode node) {
  Boolean defval = xBool( RocsWgen_random );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getBool( node, "random", defval );
}
static void _setrandom(iONode node, Boolean p_random) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setBool( node, "random", p_random );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * refid
 */
static struct __attrdef RocsWgen_refid = {
  "refid",  "Reference ID for getting more information for this action.",  "",  "string",  "",  "*",  False,
};
static const char* _getrefid(iONode node) {
  const char* defval = xStr( RocsWgen_refid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getStr( node, "refid", defval );
}
static void _setrefid(iONode node, const char* p_refid) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setStr( node, "refid", p_refid );
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
  xNode( RocsWgen_ac, node );
  return NodeOp.getStr( node, "remark", defval );
}
static void _setremark(iONode node, const char* p_remark) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setStr( node, "remark", p_remark );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sec
 */
static struct __attrdef RocsWgen_sec = {
  "sec",  "action second",  "",  "int",  "0",  "0-59",  False,
};
static int _getsec(iONode node) {
  int defval = xInt( RocsWgen_sec );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getInt( node, "sec", defval );
}
static void _setsec(iONode node, int p_sec) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setInt( node, "sec", p_sec );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sndfile
 */
static struct __attrdef RocsWgen_sndfile = {
  "sndfile",  "",  "",  "string",  "",  "*",  True,
};
static const char* _getsndfile(iONode node) {
  const char* defval = xStr( RocsWgen_sndfile );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getStr( node, "sndfile", defval );
}
static void _setsndfile(iONode node, const char* p_sndfile) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setStr( node, "sndfile", p_sndfile );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sndvolume
 */
static struct __attrdef RocsWgen_sndvolume = {
  "sndvolume",  "",  "",  "int",  "10",  "0-*",  False,
};
static int _getsndvolume(iONode node) {
  int defval = xInt( RocsWgen_sndvolume );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getInt( node, "sndvolume", defval );
}
static void _setsndvolume(iONode node, int p_sndvolume) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setInt( node, "sndvolume", p_sndvolume );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * suboid
 */
static struct __attrdef RocsWgen_suboid = {
  "suboid",  "action id",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getsuboid(iONode node) {
  const char* defval = xStr( RocsWgen_suboid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getStr( node, "suboid", defval );
}
static void _setsuboid(iONode node, const char* p_suboid) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setStr( node, "suboid", p_suboid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timed
 */
static struct __attrdef RocsWgen_timed = {
  "timed",  "Use time for activation.",  "",  "bool",  "false",  "",  False,
};
static Boolean _istimed(iONode node) {
  Boolean defval = xBool( RocsWgen_timed );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getBool( node, "timed", defval );
}
static void _settimed(iONode node, Boolean p_timed) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setBool( node, "timed", p_timed );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timer
 */
static struct __attrdef RocsWgen_timer = {
  "timer",  "Timer in ms before activation this action.",  "",  "int",  "0",  "",  False,
};
static int _gettimer(iONode node) {
  int defval = xInt( RocsWgen_timer );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getInt( node, "timer", defval );
}
static void _settimer(iONode node, int p_timer) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setInt( node, "timer", p_timer );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * type
 */
static struct __attrdef RocsWgen_type = {
  "type",  "type [ext] is an external program or script to be executed",  "",  "string",  "co",  "co,sw,st,sys,ext,sg,bk,lc,fn,tt,seltab,tx,sound",  True,
};
static const char* _gettype(iONode node) {
  const char* defval = xStr( RocsWgen_type );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_ac, node );
  return NodeOp.getStr( node, "type", defval );
}
static void _settype(iONode node, const char* p_type) {
  if( node == NULL ) return;
  xNode( RocsWgen_ac, node );
  NodeOp.setStr( node, "type", p_type );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[28] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_ac.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node ac not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node ac not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_actiontime;
  attrList[1] = &RocsWgen_activate;
  attrList[2] = &RocsWgen_activated;
  attrList[3] = &RocsWgen_addr;
  attrList[4] = &RocsWgen_bus;
  attrList[5] = &RocsWgen_cmd;
  attrList[6] = &RocsWgen_desc;
  attrList[7] = &RocsWgen_doublequote;
  attrList[8] = &RocsWgen_every;
  attrList[9] = &RocsWgen_group;
  attrList[10] = &RocsWgen_hour;
  attrList[11] = &RocsWgen_id;
  attrList[12] = &RocsWgen_iid;
  attrList[13] = &RocsWgen_min;
  attrList[14] = &RocsWgen_oid;
  attrList[15] = &RocsWgen_param;
  attrList[16] = &RocsWgen_port;
  attrList[17] = &RocsWgen_random;
  attrList[18] = &RocsWgen_refid;
  attrList[19] = &RocsWgen_remark;
  attrList[20] = &RocsWgen_sec;
  attrList[21] = &RocsWgen_sndfile;
  attrList[22] = &RocsWgen_sndvolume;
  attrList[23] = &RocsWgen_suboid;
  attrList[24] = &RocsWgen_timed;
  attrList[25] = &RocsWgen_timer;
  attrList[26] = &RocsWgen_type;
  attrList[27] = NULL;
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


struct __wAction wAction = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "acceptident",
  "class",
  "event",
  "reserve",
  "schedule",
  "schedule_manual",
  "setloco",
  "unlock",
  "off",
  "on",
  "binstate_off",
  "binstate_on",
  "carcount",
  "class",
  "dispatch",
  "go",
  "percent",
  "stop",
  "swap",
  "velocity",
  "velocity2",
  "x-go",
  "active",
  "off",
  "on",
  "lock",
  "lockset",
  "set",
  "unlock",
  "green",
  "red",
  "white",
  "yellow",
  "play",
  "flip",
  "left",
  "right",
  "straight",
  "turnout",
  "go",
  "shutdown",
  "stop",
  "stoplocs",
  "test",
  "update",
  "value",
  "goto",
  "180",
  "sound",
  "setweather",
  "weathertheme",
  _getactiontime,
  _setactiontime,
  _isactivate,
  _setactivate,
  _isactivated,
  _setactivated,
  _getaddr,
  _setaddr,
  _getbus,
  _setbus,
  _getcmd,
  _setcmd,
  _getdesc,
  _setdesc,
  _isdoublequote,
  _setdoublequote,
  _isevery,
  _setevery,
  _getgroup,
  _setgroup,
  _gethour,
  _sethour,
  _getid,
  _setid,
  _getiid,
  _setiid,
  _getmin,
  _setmin,
  _getoid,
  _setoid,
  _getparam,
  _setparam,
  _getport,
  _setport,
  _israndom,
  _setrandom,
  _getrefid,
  _setrefid,
  _getremark,
  _setremark,
  _getsec,
  _setsec,
  _getsndfile,
  _setsndfile,
  _getsndvolume,
  _setsndvolume,
  _getsuboid,
  _setsuboid,
  _istimed,
  _settimed,
  _gettimer,
  _settimer,
  _gettype,
  _settype,
  _node_dump,
};
