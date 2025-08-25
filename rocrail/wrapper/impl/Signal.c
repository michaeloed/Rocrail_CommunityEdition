/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Signal.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Signal
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_sg = {
  "sg",  "Signal definition.",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_sg.name;
}
static const char* _node_remark(void) {
  return RocsWgen_sg.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_sg.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_sg.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * accessory
 */
static struct __attrdef RocsWgen_accessory = {
  "accessory",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isaccessory(iONode node) {
  Boolean defval = xBool( RocsWgen_accessory );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getBool( node, "accessory", defval );
}
static void _setaccessory(iONode node, Boolean p_accessory) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setBool( node, "accessory", p_accessory );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr
 */
static struct __attrdef RocsWgen_addr = {
  "addr",  "decoder address",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr(iONode node) {
  int defval = xInt( RocsWgen_addr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "addr", defval );
}
static void _setaddr(iONode node, int p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "addr", p_addr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr2
 */
static struct __attrdef RocsWgen_addr2 = {
  "addr2",  "decoder address",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr2(iONode node) {
  int defval = xInt( RocsWgen_addr2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "addr2", defval );
}
static void _setaddr2(iONode node, int p_addr2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "addr2", p_addr2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr3
 */
static struct __attrdef RocsWgen_addr3 = {
  "addr3",  "decoder address",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr3(iONode node) {
  int defval = xInt( RocsWgen_addr3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "addr3", defval );
}
static void _setaddr3(iONode node, int p_addr3) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "addr3", p_addr3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr4
 */
static struct __attrdef RocsWgen_addr4 = {
  "addr4",  "decoder address",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr4(iONode node) {
  int defval = xInt( RocsWgen_addr4 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "addr4", defval );
}
static void _setaddr4(iONode node, int p_addr4) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "addr4", p_addr4 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * aspect
 */
static struct __attrdef RocsWgen_aspect = {
  "aspect",  "Aspect to show: Extended DCC.",  "",  "int",  "0",  "0-15",  False,
};
static int _getaspect(iONode node) {
  int defval = xInt( RocsWgen_aspect );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "aspect", defval );
}
static void _setaspect(iONode node, int p_aspect) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "aspect", p_aspect );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * aspectnames
 */
static struct __attrdef RocsWgen_aspectnames = {
  "aspectnames",  "CSV list of aspect names",  "",  "string",  "",  "*",  False,
};
static const char* _getaspectnames(iONode node) {
  const char* defval = xStr( RocsWgen_aspectnames );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getStr( node, "aspectnames", defval );
}
static void _setaspectnames(iONode node, const char* p_aspectnames) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setStr( node, "aspectnames", p_aspectnames );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * aspects
 */
static struct __attrdef RocsWgen_aspects = {
  "aspects",  "number of aspects to show",  "",  "int",  "3",  "2-16",  False,
};
static int _getaspects(iONode node) {
  int defval = xInt( RocsWgen_aspects );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "aspects", defval );
}
static void _setaspects(iONode node, int p_aspects) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "aspects", p_aspects );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * asswitch
 */
static struct __attrdef RocsWgen_asswitch = {
  "asswitch",  "send a switch command incase of 2 aspects",  "",  "bool",  "false",  "",  False,
};
static Boolean _isasswitch(iONode node) {
  Boolean defval = xBool( RocsWgen_asswitch );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getBool( node, "asswitch", defval );
}
static void _setasswitch(iONode node, Boolean p_asswitch) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setBool( node, "asswitch", p_asswitch );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blank
 */
static struct __attrdef RocsWgen_blank = {
  "blank",  "pattern for blank",  "",  "int",  "0",  "0-3",  False,
};
static int _getblank(iONode node) {
  int defval = xInt( RocsWgen_blank );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "blank", defval );
}
static void _setblank(iONode node, int p_blank) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "blank", p_blank );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blanknr
 */
static struct __attrdef RocsWgen_blanknr = {
  "blanknr",  "pattern for blank",  "",  "int",  "0",  "0-31",  False,
};
static int _getblanknr(iONode node) {
  int defval = xInt( RocsWgen_blanknr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "blanknr", defval );
}
static void _setblanknr(iONode node, int p_blanknr) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "blanknr", p_blanknr );
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
  xNode( RocsWgen_sg, node );
  return NodeOp.getStr( node, "blockid", defval );
}
static void _setblockid(iONode node, const char* p_blockid) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
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
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "bus", defval );
}
static void _setbus(iONode node, int p_bus) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "bus", p_bus );
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
  xNode( RocsWgen_sg, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setStr( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmdtime
 */
static struct __attrdef RocsWgen_cmdtime = {
  "cmdtime",  "Time in ms between commands.",  "",  "int",  "0",  "0-*",  False,
};
static int _getcmdtime(iONode node) {
  int defval = xInt( RocsWgen_cmdtime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "cmdtime", defval );
}
static void _setcmdtime(iONode node, int p_cmdtime) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "cmdtime", p_cmdtime );
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
  xNode( RocsWgen_sg, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * dwarf
 */
static struct __attrdef RocsWgen_dwarf = {
  "dwarf",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isdwarf(iONode node) {
  Boolean defval = xBool( RocsWgen_dwarf );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getBool( node, "dwarf", defval );
}
static void _setdwarf(iONode node, Boolean p_dwarf) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setBool( node, "dwarf", p_dwarf );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gate1
 */
static struct __attrdef RocsWgen_gate1 = {
  "gate1",  "Output gate of port 1.",  "",  "int",  "0",  "0-1",  True,
};
static int _getgate1(iONode node) {
  int defval = xInt( RocsWgen_gate1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "gate1", defval );
}
static void _setgate1(iONode node, int p_gate1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "gate1", p_gate1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gate2
 */
static struct __attrdef RocsWgen_gate2 = {
  "gate2",  "Output gate of port 2.",  "",  "int",  "0",  "0-1",  True,
};
static int _getgate2(iONode node) {
  int defval = xInt( RocsWgen_gate2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "gate2", defval );
}
static void _setgate2(iONode node, int p_gate2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "gate2", p_gate2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gate3
 */
static struct __attrdef RocsWgen_gate3 = {
  "gate3",  "Output gate of port 3.",  "",  "int",  "0",  "0-1",  True,
};
static int _getgate3(iONode node) {
  int defval = xInt( RocsWgen_gate3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "gate3", defval );
}
static void _setgate3(iONode node, int p_gate3) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "gate3", p_gate3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gate4
 */
static struct __attrdef RocsWgen_gate4 = {
  "gate4",  "Output gate of port 4, white.",  "",  "int",  "0",  "0-1",  True,
};
static int _getgate4(iONode node) {
  int defval = xInt( RocsWgen_gate4 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "gate4", defval );
}
static void _setgate4(iONode node, int p_gate4) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "gate4", p_gate4 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * green
 */
static struct __attrdef RocsWgen_green = {
  "green",  "pattern for green",  "",  "int",  "0",  "0-3",  False,
};
static int _getgreen(iONode node) {
  int defval = xInt( RocsWgen_green );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "green", defval );
}
static void _setgreen(iONode node, int p_green) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "green", p_green );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * greennr
 */
static struct __attrdef RocsWgen_greennr = {
  "greennr",  "pattern for green",  "",  "int",  "0",  "0-31",  False,
};
static int _getgreennr(iONode node) {
  int defval = xInt( RocsWgen_greennr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "greennr", defval );
}
static void _setgreennr(iONode node, int p_greennr) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "greennr", p_greennr );
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
  xNode( RocsWgen_sg, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
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
  xNode( RocsWgen_sg, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * inv
 */
static struct __attrdef RocsWgen_inv = {
  "inv",  "Signal inverted. (Software wiring correction)",  "",  "bool",  "false",  "",  False,
};
static Boolean _isinv(iONode node) {
  Boolean defval = xBool( RocsWgen_inv );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getBool( node, "inv", defval );
}
static void _setinv(iONode node, Boolean p_inv) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setBool( node, "inv", p_inv );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * manual
 */
static struct __attrdef RocsWgen_manual = {
  "manual",  "operator controlled signal to influence auto mode",  "",  "bool",  "false",  "",  False,
};
static Boolean _ismanual(iONode node) {
  Boolean defval = xBool( RocsWgen_manual );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getBool( node, "manual", defval );
}
static void _setmanual(iONode node, Boolean p_manual) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setBool( node, "manual", p_manual );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * manualreset
 */
static struct __attrdef RocsWgen_manualreset = {
  "manualreset",  "operator controlled signal reset automatically to red",  "",  "bool",  "true",  "",  False,
};
static Boolean _ismanualreset(iONode node) {
  Boolean defval = xBool( RocsWgen_manualreset );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getBool( node, "manualreset", defval );
}
static void _setmanualreset(iONode node, Boolean p_manualreset) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setBool( node, "manualreset", p_manualreset );
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
  xNode( RocsWgen_sg, node );
  return NodeOp.getStr( node, "oid", defval );
}
static void _setoid(iONode node, const char* p_oid) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
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
  xNode( RocsWgen_sg, node );
  return NodeOp.getStr( node, "ori", defval );
}
static void _setori(iONode node, const char* p_ori) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setStr( node, "ori", p_ori );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * pair
 */
static struct __attrdef RocsWgen_pair = {
  "pair",  "both gates are used for on-off",  "",  "bool",  "false",  "",  False,
};
static Boolean _ispair(iONode node) {
  Boolean defval = xBool( RocsWgen_pair );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getBool( node, "pair", defval );
}
static void _setpair(iONode node, Boolean p_pair) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setBool( node, "pair", p_pair );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * pause
 */
static struct __attrdef RocsWgen_pause = {
  "pause",  "Pause ms before executing command.",  "",  "int",  "0",  "0-*",  False,
};
static int _getpause(iONode node) {
  int defval = xInt( RocsWgen_pause );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "pause", defval );
}
static void _setpause(iONode node, int p_pause) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "pause", p_pause );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port1
 */
static struct __attrdef RocsWgen_port1 = {
  "port1",  "Output port 1.",  "",  "int",  "0",  "0-*",  True,
};
static int _getport1(iONode node) {
  int defval = xInt( RocsWgen_port1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "port1", defval );
}
static void _setport1(iONode node, int p_port1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "port1", p_port1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port2
 */
static struct __attrdef RocsWgen_port2 = {
  "port2",  "Output port 2.",  "",  "int",  "0",  "0-*",  True,
};
static int _getport2(iONode node) {
  int defval = xInt( RocsWgen_port2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "port2", defval );
}
static void _setport2(iONode node, int p_port2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "port2", p_port2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port3
 */
static struct __attrdef RocsWgen_port3 = {
  "port3",  "Output port 3.",  "",  "int",  "0",  "0-*",  True,
};
static int _getport3(iONode node) {
  int defval = xInt( RocsWgen_port3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "port3", defval );
}
static void _setport3(iONode node, int p_port3) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "port3", p_port3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port4
 */
static struct __attrdef RocsWgen_port4 = {
  "port4",  "Output port 4, white.",  "",  "int",  "0",  "0-*",  True,
};
static int _getport4(iONode node) {
  int defval = xInt( RocsWgen_port4 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "port4", defval );
}
static void _setport4(iONode node, int p_port4) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "port4", p_port4 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * porttype
 */
static struct __attrdef RocsWgen_porttype = {
  "porttype",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getporttype(iONode node) {
  int defval = xInt( RocsWgen_porttype );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "porttype", defval );
}
static void _setporttype(iONode node, int p_porttype) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "porttype", p_porttype );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * prot
 */
static struct __attrdef RocsWgen_prot = {
  "prot",  "Protocol to use for this output.",  "",  "string",  "D",  "M,N,D,mdd,om32",  False,
};
static const char* _getprot(iONode node) {
  const char* defval = xStr( RocsWgen_prot );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getStr( node, "prot", defval );
}
static void _setprot(iONode node, const char* p_prot) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setStr( node, "prot", p_prot );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * red
 */
static struct __attrdef RocsWgen_red = {
  "red",  "pattern for red",  "",  "int",  "0",  "0-3",  False,
};
static int _getred(iONode node) {
  int defval = xInt( RocsWgen_red );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "red", defval );
}
static void _setred(iONode node, int p_red) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "red", p_red );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * rednr
 */
static struct __attrdef RocsWgen_rednr = {
  "rednr",  "pattern for red",  "",  "int",  "0",  "0-31",  False,
};
static int _getrednr(iONode node) {
  int defval = xInt( RocsWgen_rednr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "rednr", defval );
}
static void _setrednr(iONode node, int p_rednr) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "rednr", p_rednr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * signal
 */
static struct __attrdef RocsWgen_signal = {
  "signal",  "",  "",  "string",  "main",  "main,distant,shunting,blockstate",  False,
};
static const char* _getsignal(iONode node) {
  const char* defval = xStr( RocsWgen_signal );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getStr( node, "signal", defval );
}
static void _setsignal(iONode node, const char* p_signal) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setStr( node, "signal", p_signal );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * state
 */
static struct __attrdef RocsWgen_state = {
  "state",  "Current state of signal.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getstate(iONode node) {
  const char* defval = xStr( RocsWgen_state );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getStr( node, "state", defval );
}
static void _setstate(iONode node, const char* p_state) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setStr( node, "state", p_state );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * symbolprefix
 */
static struct __attrdef RocsWgen_symbolprefix = {
  "symbolprefix",  "Optional symbol name prefix for multiaspect signals.",  "",  "string",  "",  "*",  False,
};
static const char* _getsymbolprefix(iONode node) {
  const char* defval = xStr( RocsWgen_symbolprefix );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getStr( node, "symbolprefix", defval );
}
static void _setsymbolprefix(iONode node, const char* p_symbolprefix) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setStr( node, "symbolprefix", p_symbolprefix );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * type
 */
static struct __attrdef RocsWgen_type = {
  "type",  "",  "",  "string",  "light",  "light,semaphore",  False,
};
static const char* _gettype(iONode node) {
  const char* defval = xStr( RocsWgen_type );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getStr( node, "type", defval );
}
static void _settype(iONode node, const char* p_type) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setStr( node, "type", p_type );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usepatterns
 */
static struct __attrdef RocsWgen_usepatterns = {
  "usepatterns",  "0=no, 1=patterns, 2=aspectnrs, 3=linear",  "",  "int",  "0",  "",  False,
};
static int _getusepatterns(iONode node) {
  int defval = xInt( RocsWgen_usepatterns );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "usepatterns", defval );
}
static void _setusepatterns(iONode node, int p_usepatterns) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "usepatterns", p_usepatterns );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usesymbolprefix
 */
static struct __attrdef RocsWgen_usesymbolprefix = {
  "usesymbolprefix",  "Use symbol prefix for aspects less then 5.",  "",  "bool",  "flase",  "",  False,
};
static Boolean _isusesymbolprefix(iONode node) {
  Boolean defval = xBool( RocsWgen_usesymbolprefix );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getBool( node, "usesymbolprefix", defval );
}
static void _setusesymbolprefix(iONode node, Boolean p_usesymbolprefix) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setBool( node, "usesymbolprefix", p_usesymbolprefix );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * white
 */
static struct __attrdef RocsWgen_white = {
  "white",  "pattern for white",  "",  "int",  "0",  "0-3",  False,
};
static int _getwhite(iONode node) {
  int defval = xInt( RocsWgen_white );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "white", defval );
}
static void _setwhite(iONode node, int p_white) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "white", p_white );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * whitenr
 */
static struct __attrdef RocsWgen_whitenr = {
  "whitenr",  "pattern for white",  "",  "int",  "0",  "0-31",  False,
};
static int _getwhitenr(iONode node) {
  int defval = xInt( RocsWgen_whitenr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "whitenr", defval );
}
static void _setwhitenr(iONode node, int p_whitenr) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "whitenr", p_whitenr );
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
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "x", defval );
}
static void _setx(iONode node, int p_x) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
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
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "y", defval );
}
static void _sety(iONode node, int p_y) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "y", p_y );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * yellow
 */
static struct __attrdef RocsWgen_yellow = {
  "yellow",  "pattern for yellow",  "",  "int",  "0",  "0-3",  False,
};
static int _getyellow(iONode node) {
  int defval = xInt( RocsWgen_yellow );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "yellow", defval );
}
static void _setyellow(iONode node, int p_yellow) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "yellow", p_yellow );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * yellownr
 */
static struct __attrdef RocsWgen_yellownr = {
  "yellownr",  "pattern for yellow",  "",  "int",  "0",  "0-31",  False,
};
static int _getyellownr(iONode node) {
  int defval = xInt( RocsWgen_yellownr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "yellownr", defval );
}
static void _setyellownr(iONode node, int p_yellownr) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "yellownr", p_yellownr );
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
  xNode( RocsWgen_sg, node );
  return NodeOp.getInt( node, "z", defval );
}
static void _setz(iONode node, int p_z) {
  if( node == NULL ) return;
  xNode( RocsWgen_sg, node );
  NodeOp.setInt( node, "z", p_z );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * actionctrl
 */
static struct __nodedef RocsWgen_actionctrl = {
  "actionctrl",  "",  False,  "n",};
static iONode _getactionctrl(iONode node) {
  xNode( RocsWgen_sg, node );
  return NodeOp.findNode( node, "actionctrl");
}


static iONode _nextactionctrl(iONode node, iONode child) {
  xNode( RocsWgen_sg, node );
  return NodeOp.findNextNode( node, child);
}
static void _setactionctrl(iONode node, iONode p_actionctrl) {
  xNode( RocsWgen_sg, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[54] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_sg.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node sg not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node sg not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_accessory;
  attrList[1] = &RocsWgen_addr;
  attrList[2] = &RocsWgen_addr2;
  attrList[3] = &RocsWgen_addr3;
  attrList[4] = &RocsWgen_addr4;
  attrList[5] = &RocsWgen_aspect;
  attrList[6] = &RocsWgen_aspectnames;
  attrList[7] = &RocsWgen_aspects;
  attrList[8] = &RocsWgen_asswitch;
  attrList[9] = &RocsWgen_blank;
  attrList[10] = &RocsWgen_blanknr;
  attrList[11] = &RocsWgen_blockid;
  attrList[12] = &RocsWgen_bus;
  attrList[13] = &RocsWgen_cmd;
  attrList[14] = &RocsWgen_cmdtime;
  attrList[15] = &RocsWgen_desc;
  attrList[16] = &RocsWgen_dwarf;
  attrList[17] = &RocsWgen_gate1;
  attrList[18] = &RocsWgen_gate2;
  attrList[19] = &RocsWgen_gate3;
  attrList[20] = &RocsWgen_gate4;
  attrList[21] = &RocsWgen_green;
  attrList[22] = &RocsWgen_greennr;
  attrList[23] = &RocsWgen_id;
  attrList[24] = &RocsWgen_iid;
  attrList[25] = &RocsWgen_inv;
  attrList[26] = &RocsWgen_manual;
  attrList[27] = &RocsWgen_manualreset;
  attrList[28] = &RocsWgen_oid;
  attrList[29] = &RocsWgen_ori;
  attrList[30] = &RocsWgen_pair;
  attrList[31] = &RocsWgen_pause;
  attrList[32] = &RocsWgen_port1;
  attrList[33] = &RocsWgen_port2;
  attrList[34] = &RocsWgen_port3;
  attrList[35] = &RocsWgen_port4;
  attrList[36] = &RocsWgen_porttype;
  attrList[37] = &RocsWgen_prot;
  attrList[38] = &RocsWgen_red;
  attrList[39] = &RocsWgen_rednr;
  attrList[40] = &RocsWgen_signal;
  attrList[41] = &RocsWgen_state;
  attrList[42] = &RocsWgen_symbolprefix;
  attrList[43] = &RocsWgen_type;
  attrList[44] = &RocsWgen_usepatterns;
  attrList[45] = &RocsWgen_usesymbolprefix;
  attrList[46] = &RocsWgen_white;
  attrList[47] = &RocsWgen_whitenr;
  attrList[48] = &RocsWgen_x;
  attrList[49] = &RocsWgen_y;
  attrList[50] = &RocsWgen_yellow;
  attrList[51] = &RocsWgen_yellownr;
  attrList[52] = &RocsWgen_z;
  attrList[53] = NULL;
  nodeList[0] = &RocsWgen_actionctrl;
  nodeList[1] = NULL;
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


struct __wSignal wSignal = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "aspect",
  "autooperated",
  "blank",
  "blockstate",
  "distant",
  "flip",
  "green",
  "light",
  "main",
  "manualoperated",
  "D",
  "M",
  "mdd",
  "N",
  "om32",
  "red",
  "semaphore",
  "shunting",
  2,
  4,
  3,
  1,
  "white",
  "yellow",
  _isaccessory,
  _setaccessory,
  _getaddr,
  _setaddr,
  _getaddr2,
  _setaddr2,
  _getaddr3,
  _setaddr3,
  _getaddr4,
  _setaddr4,
  _getaspect,
  _setaspect,
  _getaspectnames,
  _setaspectnames,
  _getaspects,
  _setaspects,
  _isasswitch,
  _setasswitch,
  _getblank,
  _setblank,
  _getblanknr,
  _setblanknr,
  _getblockid,
  _setblockid,
  _getbus,
  _setbus,
  _getcmd,
  _setcmd,
  _getcmdtime,
  _setcmdtime,
  _getdesc,
  _setdesc,
  _isdwarf,
  _setdwarf,
  _getgate1,
  _setgate1,
  _getgate2,
  _setgate2,
  _getgate3,
  _setgate3,
  _getgate4,
  _setgate4,
  _getgreen,
  _setgreen,
  _getgreennr,
  _setgreennr,
  _getid,
  _setid,
  _getiid,
  _setiid,
  _isinv,
  _setinv,
  _ismanual,
  _setmanual,
  _ismanualreset,
  _setmanualreset,
  _getoid,
  _setoid,
  _getori,
  _setori,
  _ispair,
  _setpair,
  _getpause,
  _setpause,
  _getport1,
  _setport1,
  _getport2,
  _setport2,
  _getport3,
  _setport3,
  _getport4,
  _setport4,
  _getporttype,
  _setporttype,
  _getprot,
  _setprot,
  _getred,
  _setred,
  _getrednr,
  _setrednr,
  _getsignal,
  _setsignal,
  _getstate,
  _setstate,
  _getsymbolprefix,
  _setsymbolprefix,
  _gettype,
  _settype,
  _getusepatterns,
  _setusepatterns,
  _isusesymbolprefix,
  _setusesymbolprefix,
  _getwhite,
  _setwhite,
  _getwhitenr,
  _setwhitenr,
  _getx,
  _setx,
  _gety,
  _sety,
  _getyellow,
  _setyellow,
  _getyellownr,
  _setyellownr,
  _getz,
  _setz,
  _getactionctrl,
  _nextactionctrl,
  _setactionctrl,
  _node_dump,
};
