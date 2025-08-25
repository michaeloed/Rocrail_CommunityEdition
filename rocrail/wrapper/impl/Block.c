/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/Block.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Block
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_bk = {
  "bk",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_bk.name;
}
static const char* _node_remark(void) {
  return RocsWgen_bk.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_bk.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_bk.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * acceptghost
 */
static struct __attrdef RocsWgen_acceptghost = {
  "acceptghost",  "accept a ghosttrain and signal the block occupied.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isacceptghost(iONode node) {
  Boolean defval = xBool( RocsWgen_acceptghost );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "acceptghost", defval );
}
static void _setacceptghost(iONode node, Boolean p_acceptghost) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "acceptghost", p_acceptghost );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * acceptident
 */
static struct __attrdef RocsWgen_acceptident = {
  "acceptident",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isacceptident(iONode node) {
  Boolean defval = xBool( RocsWgen_acceptident );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "acceptident", defval );
}
static void _setacceptident(iONode node, Boolean p_acceptident) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "acceptident", p_acceptident );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr
 */
static struct __attrdef RocsWgen_addr = {
  "addr",  "TD address",  "",  "int",  "0",  "0-*",  False,
};
static int _getaddr(iONode node) {
  int defval = xInt( RocsWgen_addr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "addr", defval );
}
static void _setaddr(iONode node, int p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setInt( node, "addr", p_addr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * allowbbt
 */
static struct __attrdef RocsWgen_allowbbt = {
  "allowbbt",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isallowbbt(iONode node) {
  Boolean defval = xBool( RocsWgen_allowbbt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "allowbbt", defval );
}
static void _setallowbbt(iONode node, Boolean p_allowbbt) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "allowbbt", p_allowbbt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * allowchgdir
 */
static struct __attrdef RocsWgen_allowchgdir = {
  "allowchgdir",  "Allow using a route in the opposite running direction.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isallowchgdir(iONode node) {
  Boolean defval = xBool( RocsWgen_allowchgdir );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "allowchgdir", defval );
}
static void _setallowchgdir(iONode node, Boolean p_allowchgdir) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "allowchgdir", p_allowchgdir );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blankatredsignal
 */
static struct __attrdef RocsWgen_blankatredsignal = {
  "blankatredsignal",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isblankatredsignal(iONode node) {
  Boolean defval = xBool( RocsWgen_blankatredsignal );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "blankatredsignal", defval );
}
static void _setblankatredsignal(iONode node, Boolean p_blankatredsignal) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "blankatredsignal", p_blankatredsignal );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blankatredsignalR
 */
static struct __attrdef RocsWgen_blankatredsignalR = {
  "blankatredsignalR",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isblankatredsignalR(iONode node) {
  Boolean defval = xBool( RocsWgen_blankatredsignalR );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "blankatredsignalR", defval );
}
static void _setblankatredsignalR(iONode node, Boolean p_blankatredsignalR) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "blankatredsignalR", p_blankatredsignalR );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * class
 */
static struct __attrdef RocsWgen_class = {
  "class",  "Comma separated list of permitted classes.",  "",  "string",  "",  "*",  False,
};
static const char* _getclass(iONode node) {
  const char* defval = xStr( RocsWgen_class );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "class", defval );
}
static void _setclass(iONode node, const char* p_class) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "class", p_class );
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
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * commuter
 */
static struct __attrdef RocsWgen_commuter = {
  "commuter",  "Are commuter trains allowed?",  "",  "string",  "yes",  "no,yes,only",  False,
};
static const char* _getcommuter(iONode node) {
  const char* defval = xStr( RocsWgen_commuter );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "commuter", defval );
}
static void _setcommuter(iONode node, const char* p_commuter) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "commuter", p_commuter );
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
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "departdelay", defval );
}
static void _setdepartdelay(iONode node, int p_departdelay) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setInt( node, "departdelay", p_departdelay );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * desc
 */
static struct __attrdef RocsWgen_desc = {
  "desc",  "Description of block.",  "",  "string",  "",  "*",  False,
};
static const char* _getdesc(iONode node) {
  const char* defval = xStr( RocsWgen_desc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * electrified
 */
static struct __attrdef RocsWgen_electrified = {
  "electrified",  "Block is open for electric locs.",  "",  "bool",  "false",  "",  False,
};
static Boolean _iselectrified(iONode node) {
  Boolean defval = xBool( RocsWgen_electrified );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "electrified", defval );
}
static void _setelectrified(iONode node, Boolean p_electrified) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
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
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "entering", defval );
}
static void _setentering(iONode node, Boolean p_entering) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "entering", p_entering );
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
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "evttimer", defval );
}
static void _setevttimer(iONode node, int p_evttimer) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setInt( node, "evttimer", p_evttimer );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * evttimer2
 */
static struct __attrdef RocsWgen_evttimer2 = {
  "evttimer2",  "event timer reverse direction; loc should wait this time before processing the event",  "ms",  "int",  "0",  "0-*",  False,
};
static int _getevttimer2(iONode node) {
  int defval = xInt( RocsWgen_evttimer2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "evttimer2", defval );
}
static void _setevttimer2(iONode node, int p_evttimer2) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setInt( node, "evttimer2", p_evttimer2 );
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
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "exitspeed", defval );
}
static void _setexitspeed(iONode node, const char* p_exitspeed) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
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
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "exitspeedpercent", defval );
}
static void _setexitspeedpercent(iONode node, int p_exitspeedpercent) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setInt( node, "exitspeedpercent", p_exitspeedpercent );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * extstop
 */
static struct __attrdef RocsWgen_extstop = {
  "extstop",  "An external stop module will take over the throttle. Use only with enter2in! (Lenz ABC.)",  "",  "bool",  "false",  "",  False,
};
static Boolean _isextstop(iONode node) {
  Boolean defval = xBool( RocsWgen_extstop );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "extstop", defval );
}
static void _setextstop(iONode node, Boolean p_extstop) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "extstop", p_extstop );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fifoids
 */
static struct __attrdef RocsWgen_fifoids = {
  "fifoids",  "CSV list of all FiFo IDs.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getfifoids(iONode node) {
  const char* defval = xStr( RocsWgen_fifoids );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "fifoids", defval );
}
static void _setfifoids(iONode node, const char* p_fifoids) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "fifoids", p_fifoids );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fifosize
 */
static struct __attrdef RocsWgen_fifosize = {
  "fifosize",  "FiFo size; Must be greater then 0 to be active.",  "",  "int",  "0",  "0-*",  False,
};
static int _getfifosize(iONode node) {
  int defval = xInt( RocsWgen_fifosize );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "fifosize", defval );
}
static void _setfifosize(iONode node, int p_fifosize) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setInt( node, "fifosize", p_fifosize );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * forceblocktimer
 */
static struct __attrdef RocsWgen_forceblocktimer = {
  "forceblocktimer",  "Force the block event timer to overrule the optional loco event timer.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isforceblocktimer(iONode node) {
  Boolean defval = xBool( RocsWgen_forceblocktimer );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "forceblocktimer", defval );
}
static void _setforceblocktimer(iONode node, Boolean p_forceblocktimer) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "forceblocktimer", p_forceblocktimer );
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
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "freeblockonenter", defval );
}
static void _setfreeblockonenter(iONode node, Boolean p_freeblockonenter) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "freeblockonenter", p_freeblockonenter );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gomanual
 */
static struct __attrdef RocsWgen_gomanual = {
  "gomanual",  "allow half-automatic mode",  "",  "bool",  "true",  "",  False,
};
static Boolean _isgomanual(iONode node) {
  Boolean defval = xBool( RocsWgen_gomanual );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "gomanual", defval );
}
static void _setgomanual(iONode node, Boolean p_gomanual) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "gomanual", p_gomanual );
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
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iid
 */
static struct __attrdef RocsWgen_iid = {
  "iid",  "TD interface id",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getiid(iONode node) {
  const char* defval = xStr( RocsWgen_iid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * incline
 */
static struct __attrdef RocsWgen_incline = {
  "incline",  "",  "",  "int",  "0",  "1,0,-1",  False,
};
static int _getincline(iONode node) {
  int defval = xInt( RocsWgen_incline );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "incline", defval );
}
static void _setincline(iONode node, int p_incline) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setInt( node, "incline", p_incline );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * len
 */
static struct __attrdef RocsWgen_len = {
  "len",  "Distance between enter and in event to check with train length.",  "cm",  "int",  "0",  "0-*",  False,
};
static int _getlen(iONode node) {
  int defval = xInt( RocsWgen_len );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "len", defval );
}
static void _setlen(iONode node, int p_len) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setInt( node, "len", p_len );
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
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "locid", defval );
}
static void _setlocid(iONode node, const char* p_locid) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "locid", p_locid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mainline
 */
static struct __attrdef RocsWgen_mainline = {
  "mainline",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _ismainline(iONode node) {
  Boolean defval = xBool( RocsWgen_mainline );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "mainline", defval );
}
static void _setmainline(iONode node, Boolean p_mainline) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "mainline", p_mainline );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * managerid
 */
static struct __attrdef RocsWgen_managerid = {
  "managerid",  "ID of the manager object like FY or TT.",  "",  "string",  "",  "*",  False,
};
static const char* _getmanagerid(iONode node) {
  const char* defval = xStr( RocsWgen_managerid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "managerid", defval );
}
static void _setmanagerid(iONode node, const char* p_managerid) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "managerid", p_managerid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * manual
 */
static struct __attrdef RocsWgen_manual = {
  "manual",  "Block not chooseable for locs in auto-mode if set to true.",  "",  "bool",  "false",  "",  False,
};
static Boolean _ismanual(iONode node) {
  Boolean defval = xBool( RocsWgen_manual );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "manual", defval );
}
static void _setmanual(iONode node, Boolean p_manual) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "manual", p_manual );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mastercmd
 */
static struct __attrdef RocsWgen_mastercmd = {
  "mastercmd",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _ismastercmd(iONode node) {
  Boolean defval = xBool( RocsWgen_mastercmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "mastercmd", defval );
}
static void _setmastercmd(iONode node, Boolean p_mastercmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "mastercmd", p_mastercmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * masterid
 */
static struct __attrdef RocsWgen_masterid = {
  "masterid",  "ID of the master block.",  "",  "string",  "",  "*",  False,
};
static const char* _getmasterid(iONode node) {
  const char* defval = xStr( RocsWgen_masterid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "masterid", defval );
}
static void _setmasterid(iONode node, const char* p_masterid) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "masterid", p_masterid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * maxkmh
 */
static struct __attrdef RocsWgen_maxkmh = {
  "maxkmh",  "Block max. speed in km/h or mph.",  "",  "int",  "0",  "0-*",  False,
};
static int _getmaxkmh(iONode node) {
  int defval = xInt( RocsWgen_maxkmh );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "maxkmh", defval );
}
static void _setmaxkmh(iONode node, int p_maxkmh) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setInt( node, "maxkmh", p_maxkmh );
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
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "maxwaittime", defval );
}
static void _setmaxwaittime(iONode node, int p_maxwaittime) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setInt( node, "maxwaittime", p_maxwaittime );
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
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "minwaittime", defval );
}
static void _setminwaittime(iONode node, int p_minwaittime) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setInt( node, "minwaittime", p_minwaittime );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mvdistance
 */
static struct __attrdef RocsWgen_mvdistance = {
  "mvdistance",  "Distance between the enter and in event.",  "",  "int",  "0",  "",  False,
};
static int _getmvdistance(iONode node) {
  int defval = xInt( RocsWgen_mvdistance );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "mvdistance", defval );
}
static void _setmvdistance(iONode node, int p_mvdistance) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setInt( node, "mvdistance", p_mvdistance );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mvmph
 */
static struct __attrdef RocsWgen_mvmph = {
  "mvmph",  "convert to MPH",  "",  "bool",  "false",  "",  False,
};
static Boolean _ismvmph(iONode node) {
  Boolean defval = xBool( RocsWgen_mvmph );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "mvmph", defval );
}
static void _setmvmph(iONode node, Boolean p_mvmph) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "mvmph", p_mvmph );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mvscale
 */
static struct __attrdef RocsWgen_mvscale = {
  "mvscale",  "Scale of locomotives.",  "",  "int",  "0",  "",  False,
};
static int _getmvscale(iONode node) {
  int defval = xInt( RocsWgen_mvscale );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "mvscale", defval );
}
static void _setmvscale(iONode node, int p_mvscale) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setInt( node, "mvscale", p_mvscale );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "TD output port",  "",  "int",  "0",  "0-*",  False,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setInt( node, "port", p_port );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * power
 */
static struct __attrdef RocsWgen_power = {
  "power",  "block power",  "",  "bool",  "true",  "",  False,
};
static Boolean _ispower(iONode node) {
  Boolean defval = xBool( RocsWgen_power );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "power", defval );
}
static void _setpower(iONode node, Boolean p_power) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "power", p_power );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * prevstate
 */
static struct __attrdef RocsWgen_prevstate = {
  "prevstate",  "",  "",  "string",  "open",  "open,closed",  False,
};
static const char* _getprevstate(iONode node) {
  const char* defval = xStr( RocsWgen_prevstate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "prevstate", defval );
}
static void _setprevstate(iONode node, const char* p_prevstate) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "prevstate", p_prevstate );
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
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "randomrate", defval );
}
static void _setrandomrate(iONode node, int p_randomrate) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
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
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "remote", defval );
}
static void _setremote(iONode node, Boolean p_remote) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
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
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "reserved", defval );
}
static void _setreserved(iONode node, Boolean p_reserved) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
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
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "rrid", defval );
}
static void _setrrid(iONode node, const char* p_rrid) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "rrid", p_rrid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * selectshortestblock
 */
static struct __attrdef RocsWgen_selectshortestblock = {
  "selectshortestblock",  "Select shortest next block in case block and train length are set.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isselectshortestblock(iONode node) {
  Boolean defval = xBool( RocsWgen_selectshortestblock );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "selectshortestblock", defval );
}
static void _setselectshortestblock(iONode node, Boolean p_selectshortestblock) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "selectshortestblock", p_selectshortestblock );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * signal
 */
static struct __attrdef RocsWgen_signal = {
  "signal",  "Home Signal ID. (sw)",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getsignal(iONode node) {
  const char* defval = xStr( RocsWgen_signal );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "signal", defval );
}
static void _setsignal(iONode node, const char* p_signal) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "signal", p_signal );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * signalR
 */
static struct __attrdef RocsWgen_signalR = {
  "signalR",  "Home Signal ID for reverse direction. (sw)",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getsignalR(iONode node) {
  const char* defval = xStr( RocsWgen_signalR );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "signalR", defval );
}
static void _setsignalR(iONode node, const char* p_signalR) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "signalR", p_signalR );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * slaveblocks
 */
static struct __attrdef RocsWgen_slaveblocks = {
  "slaveblocks",  "Virtual slave blocks.",  "",  "string",  "",  "",  False,
};
static const char* _getslaveblocks(iONode node) {
  const char* defval = xStr( RocsWgen_slaveblocks );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "slaveblocks", defval );
}
static void _setslaveblocks(iONode node, const char* p_slaveblocks) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "slaveblocks", p_slaveblocks );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sleeponclosed
 */
static struct __attrdef RocsWgen_sleeponclosed = {
  "sleeponclosed",  "Ignore events in case of closed.",  "",  "bool",  "false",  "",  False,
};
static Boolean _issleeponclosed(iONode node) {
  Boolean defval = xBool( RocsWgen_sleeponclosed );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "sleeponclosed", defval );
}
static void _setsleeponclosed(iONode node, Boolean p_sleeponclosed) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "sleeponclosed", p_sleeponclosed );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * smallsymbol
 */
static struct __attrdef RocsWgen_smallsymbol = {
  "smallsymbol",  "Show this block with the small representation.",  "",  "bool",  "false",  "",  False,
};
static Boolean _issmallsymbol(iONode node) {
  Boolean defval = xBool( RocsWgen_smallsymbol );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "smallsymbol", defval );
}
static void _setsmallsymbol(iONode node, Boolean p_smallsymbol) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "smallsymbol", p_smallsymbol );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * speed
 */
static struct __attrdef RocsWgen_speed = {
  "speed",  "Block speed on arrive.",  "",  "string",  "cruise",  "*",  False,
};
static const char* _getspeed(iONode node) {
  const char* defval = xStr( RocsWgen_speed );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "speed", defval );
}
static void _setspeed(iONode node, const char* p_speed) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "speed", p_speed );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * speedpercent
 */
static struct __attrdef RocsWgen_speedpercent = {
  "speedpercent",  "Blockspeed in percent.",  "%",  "int",  "80",  "0-100",  False,
};
static int _getspeedpercent(iONode node) {
  int defval = xInt( RocsWgen_speedpercent );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "speedpercent", defval );
}
static void _setspeedpercent(iONode node, int p_speedpercent) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
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
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "state", defval );
}
static void _setstate(iONode node, const char* p_state) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "state", p_state );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * statesignal
 */
static struct __attrdef RocsWgen_statesignal = {
  "statesignal",  "State Signal ID for loco info.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getstatesignal(iONode node) {
  const char* defval = xStr( RocsWgen_statesignal );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "statesignal", defval );
}
static void _setstatesignal(iONode node, const char* p_statesignal) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "statesignal", p_statesignal );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * stopspeed
 */
static struct __attrdef RocsWgen_stopspeed = {
  "stopspeed",  "Block speed on arrive and stop.",  "",  "string",  "mid",  "mid,min,percent",  False,
};
static const char* _getstopspeed(iONode node) {
  const char* defval = xStr( RocsWgen_stopspeed );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "stopspeed", defval );
}
static void _setstopspeed(iONode node, const char* p_stopspeed) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "stopspeed", p_stopspeed );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * td
 */
static struct __attrdef RocsWgen_td = {
  "td",  "trackdriver connected to this block",  "",  "bool",  "false",  "",  False,
};
static Boolean _istd(iONode node) {
  Boolean defval = xBool( RocsWgen_td );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "td", defval );
}
static void _settd(iONode node, Boolean p_td) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "td", p_td );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * terminalstation
 */
static struct __attrdef RocsWgen_terminalstation = {
  "terminalstation",  "swap placing of an incomming loc to get another default direction.(terminal station)",  "",  "bool",  "false",  "",  False,
};
static Boolean _isterminalstation(iONode node) {
  Boolean defval = xBool( RocsWgen_terminalstation );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "terminalstation", defval );
}
static void _setterminalstation(iONode node, Boolean p_terminalstation) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "terminalstation", p_terminalstation );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ttid
 */
static struct __attrdef RocsWgen_ttid = {
  "ttid",  "Turntable ID.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getttid(iONode node) {
  const char* defval = xStr( RocsWgen_ttid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "ttid", defval );
}
static void _setttid(iONode node, const char* p_ttid) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "ttid", p_ttid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * turnoutstolock
 */
static struct __attrdef RocsWgen_turnoutstolock = {
  "turnoutstolock",  "comma separated list of turnouts to lock with the block",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getturnoutstolock(iONode node) {
  const char* defval = xStr( RocsWgen_turnoutstolock );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "turnoutstolock", defval );
}
static void _setturnoutstolock(iONode node, const char* p_turnoutstolock) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "turnoutstolock", p_turnoutstolock );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * type
 */
static struct __attrdef RocsWgen_type = {
  "type",  "",  "",  "string",  "none",  "none,local,ice,shunting,goods",  False,
};
static const char* _gettype(iONode node) {
  const char* defval = xStr( RocsWgen_type );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "type", defval );
}
static void _settype(iONode node, const char* p_type) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "type", p_type );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * typeperm
 */
static struct __attrdef RocsWgen_typeperm = {
  "typeperm",  "Only allow this type of trains.",  "",  "string",  "",  "*",  False,
};
static const char* _gettypeperm(iONode node) {
  const char* defval = xStr( RocsWgen_typeperm );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "typeperm", defval );
}
static void _settypeperm(iONode node, const char* p_typeperm) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "typeperm", p_typeperm );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * updateenterside
 */
static struct __attrdef RocsWgen_updateenterside = {
  "updateenterside",  "For internal use only: Event for updating the loco block enter side only.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isupdateenterside(iONode node) {
  Boolean defval = xBool( RocsWgen_updateenterside );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "updateenterside", defval );
}
static void _setupdateenterside(iONode node, Boolean p_updateenterside) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "updateenterside", p_updateenterside );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * virtual
 */
static struct __attrdef RocsWgen_virtual = {
  "virtual",  "Virtual block.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isvirtual(iONode node) {
  Boolean defval = xBool( RocsWgen_virtual );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "virtual", defval );
}
static void _setvirtual(iONode node, Boolean p_virtual) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "virtual", p_virtual );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * wait
 */
static struct __attrdef RocsWgen_wait = {
  "wait",  "Should the loc wait in this block?",  "",  "bool",  "true",  "",  False,
};
static Boolean _iswait(iONode node) {
  Boolean defval = xBool( RocsWgen_wait );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getBool( node, "wait", defval );
}
static void _setwait(iONode node, Boolean p_wait) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setBool( node, "wait", p_wait );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * waitmode
 */
static struct __attrdef RocsWgen_waitmode = {
  "waitmode",  "",  "",  "string",  "none",  "random,fixed,loc,none",  False,
};
static const char* _getwaitmode(iONode node) {
  const char* defval = xStr( RocsWgen_waitmode );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "waitmode", defval );
}
static void _setwaitmode(iONode node, const char* p_waitmode) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "waitmode", p_waitmode );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * waittime
 */
static struct __attrdef RocsWgen_waittime = {
  "waittime",  "Wait time in case of wait_fixed.",  "s",  "int",  "10",  "0-*",  False,
};
static int _getwaittime(iONode node) {
  int defval = xInt( RocsWgen_waittime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "waittime", defval );
}
static void _setwaittime(iONode node, int p_waittime) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setInt( node, "waittime", p_waittime );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * wsignal
 */
static struct __attrdef RocsWgen_wsignal = {
  "wsignal",  "Warning Signal ID. (sw)",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getwsignal(iONode node) {
  const char* defval = xStr( RocsWgen_wsignal );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "wsignal", defval );
}
static void _setwsignal(iONode node, const char* p_wsignal) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "wsignal", p_wsignal );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * wsignalR
 */
static struct __attrdef RocsWgen_wsignalR = {
  "wsignalR",  "Warning Signal ID for reverse direction. (sw)",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getwsignalR(iONode node) {
  const char* defval = xStr( RocsWgen_wsignalR );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bk, node );
  return NodeOp.getStr( node, "wsignalR", defval );
}
static void _setwsignalR(iONode node, const char* p_wsignalR) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setStr( node, "wsignalR", p_wsignalR );
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
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "x", defval );
}
static void _setx(iONode node, int p_x) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
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
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "y", defval );
}
static void _sety(iONode node, int p_y) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
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
  xNode( RocsWgen_bk, node );
  return NodeOp.getInt( node, "z", defval );
}
static void _setz(iONode node, int p_z) {
  if( node == NULL ) return;
  xNode( RocsWgen_bk, node );
  NodeOp.setInt( node, "z", p_z );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * incl
 */
static struct __nodedef RocsWgen_incl = {
  "incl",  "",  False,  "n",};
static iONode _getincl(iONode node) {
  xNode( RocsWgen_bk, node );
  return NodeOp.findNode( node, "incl");
}


static iONode _nextincl(iONode node, iONode child) {
  xNode( RocsWgen_bk, node );
  return NodeOp.findNextNode( node, child);
}
static void _setincl(iONode node, iONode p_incl) {
  xNode( RocsWgen_bk, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * excl
 */
static struct __nodedef RocsWgen_excl = {
  "excl",  "",  False,  "n",};
static iONode _getexcl(iONode node) {
  xNode( RocsWgen_bk, node );
  return NodeOp.findNode( node, "excl");
}


static iONode _nextexcl(iONode node, iONode child) {
  xNode( RocsWgen_bk, node );
  return NodeOp.findNextNode( node, child);
}
static void _setexcl(iONode node, iONode p_excl) {
  xNode( RocsWgen_bk, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * fbevent
 */
static struct __nodedef RocsWgen_fbevent = {
  "fbevent",  "",  False,  "n",};
static iONode _getfbevent(iONode node) {
  xNode( RocsWgen_bk, node );
  return NodeOp.findNode( node, "fbevent");
}


static iONode _nextfbevent(iONode node, iONode child) {
  xNode( RocsWgen_bk, node );
  return NodeOp.findNextNode( node, child);
}
static void _setfbevent(iONode node, iONode p_fbevent) {
  xNode( RocsWgen_bk, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * actionctrl
 */
static struct __nodedef RocsWgen_actionctrl = {
  "actionctrl",  "",  False,  "n",};
static iONode _getactionctrl(iONode node) {
  xNode( RocsWgen_bk, node );
  return NodeOp.findNode( node, "actionctrl");
}


static iONode _nextactionctrl(iONode node, iONode child) {
  xNode( RocsWgen_bk, node );
  return NodeOp.findNextNode( node, child);
}
static void _setactionctrl(iONode node, iONode p_actionctrl) {
  xNode( RocsWgen_bk, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * speedcondition
 */
static struct __nodedef RocsWgen_speedcondition = {
  "speedcondition",  "",  False,  "n",};
static iONode _getspeedcondition(iONode node) {
  xNode( RocsWgen_bk, node );
  return NodeOp.findNode( node, "speedcondition");
}


static iONode _nextspeedcondition(iONode node, iONode child) {
  xNode( RocsWgen_bk, node );
  return NodeOp.findNextNode( node, child);
}
static void _setspeedcondition(iONode node, iONode p_speedcondition) {
  xNode( RocsWgen_bk, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[75] = {NULL};
static struct __nodedef* nodeList[6] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_bk.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node bk not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node bk not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_acceptghost;
  attrList[1] = &RocsWgen_acceptident;
  attrList[2] = &RocsWgen_addr;
  attrList[3] = &RocsWgen_allowbbt;
  attrList[4] = &RocsWgen_allowchgdir;
  attrList[5] = &RocsWgen_blankatredsignal;
  attrList[6] = &RocsWgen_blankatredsignalR;
  attrList[7] = &RocsWgen_class;
  attrList[8] = &RocsWgen_cmd;
  attrList[9] = &RocsWgen_commuter;
  attrList[10] = &RocsWgen_departdelay;
  attrList[11] = &RocsWgen_desc;
  attrList[12] = &RocsWgen_electrified;
  attrList[13] = &RocsWgen_entering;
  attrList[14] = &RocsWgen_evttimer;
  attrList[15] = &RocsWgen_evttimer2;
  attrList[16] = &RocsWgen_exitspeed;
  attrList[17] = &RocsWgen_exitspeedpercent;
  attrList[18] = &RocsWgen_extstop;
  attrList[19] = &RocsWgen_fifoids;
  attrList[20] = &RocsWgen_fifosize;
  attrList[21] = &RocsWgen_forceblocktimer;
  attrList[22] = &RocsWgen_freeblockonenter;
  attrList[23] = &RocsWgen_gomanual;
  attrList[24] = &RocsWgen_id;
  attrList[25] = &RocsWgen_iid;
  attrList[26] = &RocsWgen_incline;
  attrList[27] = &RocsWgen_len;
  attrList[28] = &RocsWgen_locid;
  attrList[29] = &RocsWgen_mainline;
  attrList[30] = &RocsWgen_managerid;
  attrList[31] = &RocsWgen_manual;
  attrList[32] = &RocsWgen_mastercmd;
  attrList[33] = &RocsWgen_masterid;
  attrList[34] = &RocsWgen_maxkmh;
  attrList[35] = &RocsWgen_maxwaittime;
  attrList[36] = &RocsWgen_minwaittime;
  attrList[37] = &RocsWgen_mvdistance;
  attrList[38] = &RocsWgen_mvmph;
  attrList[39] = &RocsWgen_mvscale;
  attrList[40] = &RocsWgen_port;
  attrList[41] = &RocsWgen_power;
  attrList[42] = &RocsWgen_prevstate;
  attrList[43] = &RocsWgen_randomrate;
  attrList[44] = &RocsWgen_remote;
  attrList[45] = &RocsWgen_reserved;
  attrList[46] = &RocsWgen_rrid;
  attrList[47] = &RocsWgen_selectshortestblock;
  attrList[48] = &RocsWgen_signal;
  attrList[49] = &RocsWgen_signalR;
  attrList[50] = &RocsWgen_slaveblocks;
  attrList[51] = &RocsWgen_sleeponclosed;
  attrList[52] = &RocsWgen_smallsymbol;
  attrList[53] = &RocsWgen_speed;
  attrList[54] = &RocsWgen_speedpercent;
  attrList[55] = &RocsWgen_state;
  attrList[56] = &RocsWgen_statesignal;
  attrList[57] = &RocsWgen_stopspeed;
  attrList[58] = &RocsWgen_td;
  attrList[59] = &RocsWgen_terminalstation;
  attrList[60] = &RocsWgen_ttid;
  attrList[61] = &RocsWgen_turnoutstolock;
  attrList[62] = &RocsWgen_type;
  attrList[63] = &RocsWgen_typeperm;
  attrList[64] = &RocsWgen_updateenterside;
  attrList[65] = &RocsWgen_virtual;
  attrList[66] = &RocsWgen_wait;
  attrList[67] = &RocsWgen_waitmode;
  attrList[68] = &RocsWgen_waittime;
  attrList[69] = &RocsWgen_wsignal;
  attrList[70] = &RocsWgen_wsignalR;
  attrList[71] = &RocsWgen_x;
  attrList[72] = &RocsWgen_y;
  attrList[73] = &RocsWgen_z;
  attrList[74] = NULL;
  nodeList[0] = &RocsWgen_incl;
  nodeList[1] = &RocsWgen_excl;
  nodeList[2] = &RocsWgen_fbevent;
  nodeList[3] = &RocsWgen_actionctrl;
  nodeList[4] = &RocsWgen_speedcondition;
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


struct __wBlock wBlock = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "bsm",
  "bsp",
  "classadd",
  "classdel",
  "classset",
  "closed",
  "no",
  "only",
  "yes",
  "cruise",
  "ghost",
  -1,
  0,
  1,
  "loc",
  "max",
  "mid",
  "min",
  "nop",
  "open",
  "percent",
  "resetfifo",
  "resetwc",
  "shortcut",
  "shortcutcleared",
  "goods",
  "ice",
  "light",
  "lightgoods",
  "local",
  "none",
  "post",
  "regional",
  "shunting",
  "turntable",
  "fixed",
  "loc",
  "none",
  "random",
  _isacceptghost,
  _setacceptghost,
  _isacceptident,
  _setacceptident,
  _getaddr,
  _setaddr,
  _isallowbbt,
  _setallowbbt,
  _isallowchgdir,
  _setallowchgdir,
  _isblankatredsignal,
  _setblankatredsignal,
  _isblankatredsignalR,
  _setblankatredsignalR,
  _getclass,
  _setclass,
  _getcmd,
  _setcmd,
  _getcommuter,
  _setcommuter,
  _getdepartdelay,
  _setdepartdelay,
  _getdesc,
  _setdesc,
  _iselectrified,
  _setelectrified,
  _isentering,
  _setentering,
  _getevttimer,
  _setevttimer,
  _getevttimer2,
  _setevttimer2,
  _getexitspeed,
  _setexitspeed,
  _getexitspeedpercent,
  _setexitspeedpercent,
  _isextstop,
  _setextstop,
  _getfifoids,
  _setfifoids,
  _getfifosize,
  _setfifosize,
  _isforceblocktimer,
  _setforceblocktimer,
  _isfreeblockonenter,
  _setfreeblockonenter,
  _isgomanual,
  _setgomanual,
  _getid,
  _setid,
  _getiid,
  _setiid,
  _getincline,
  _setincline,
  _getlen,
  _setlen,
  _getlocid,
  _setlocid,
  _ismainline,
  _setmainline,
  _getmanagerid,
  _setmanagerid,
  _ismanual,
  _setmanual,
  _ismastercmd,
  _setmastercmd,
  _getmasterid,
  _setmasterid,
  _getmaxkmh,
  _setmaxkmh,
  _getmaxwaittime,
  _setmaxwaittime,
  _getminwaittime,
  _setminwaittime,
  _getmvdistance,
  _setmvdistance,
  _ismvmph,
  _setmvmph,
  _getmvscale,
  _setmvscale,
  _getport,
  _setport,
  _ispower,
  _setpower,
  _getprevstate,
  _setprevstate,
  _getrandomrate,
  _setrandomrate,
  _isremote,
  _setremote,
  _isreserved,
  _setreserved,
  _getrrid,
  _setrrid,
  _isselectshortestblock,
  _setselectshortestblock,
  _getsignal,
  _setsignal,
  _getsignalR,
  _setsignalR,
  _getslaveblocks,
  _setslaveblocks,
  _issleeponclosed,
  _setsleeponclosed,
  _issmallsymbol,
  _setsmallsymbol,
  _getspeed,
  _setspeed,
  _getspeedpercent,
  _setspeedpercent,
  _getstate,
  _setstate,
  _getstatesignal,
  _setstatesignal,
  _getstopspeed,
  _setstopspeed,
  _istd,
  _settd,
  _isterminalstation,
  _setterminalstation,
  _getttid,
  _setttid,
  _getturnoutstolock,
  _setturnoutstolock,
  _gettype,
  _settype,
  _gettypeperm,
  _settypeperm,
  _isupdateenterside,
  _setupdateenterside,
  _isvirtual,
  _setvirtual,
  _iswait,
  _setwait,
  _getwaitmode,
  _setwaitmode,
  _getwaittime,
  _setwaittime,
  _getwsignal,
  _setwsignal,
  _getwsignalR,
  _setwsignalR,
  _getx,
  _setx,
  _gety,
  _sety,
  _getz,
  _setz,
  _getincl,
  _nextincl,
  _setincl,
  _getexcl,
  _nextexcl,
  _setexcl,
  _getfbevent,
  _nextfbevent,
  _setfbevent,
  _getactionctrl,
  _nextactionctrl,
  _setactionctrl,
  _getspeedcondition,
  _nextspeedcondition,
  _setspeedcondition,
  _node_dump,
};
