/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Output.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Output
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_co = {
  "co",  "Common Output definition.",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_co.name;
}
static const char* _node_remark(void) {
  return RocsWgen_co.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_co.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_co.cardinality;
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
  xNode( RocsWgen_co, node );
  return NodeOp.getBool( node, "accessory", defval );
}
static void _setaccessory(iONode node, Boolean p_accessory) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
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
  xNode( RocsWgen_co, node );
  return NodeOp.getInt( node, "addr", defval );
}
static void _setaddr(iONode node, int p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setInt( node, "addr", p_addr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * asswitch
 */
static struct __attrdef RocsWgen_asswitch = {
  "asswitch",  "send a switch command",  "",  "bool",  "false",  "",  False,
};
static Boolean _isasswitch(iONode node) {
  Boolean defval = xBool( RocsWgen_asswitch );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getBool( node, "asswitch", defval );
}
static void _setasswitch(iONode node, Boolean p_asswitch) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setBool( node, "asswitch", p_asswitch );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blink
 */
static struct __attrdef RocsWgen_blink = {
  "blink",  "Blink output.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isblink(iONode node) {
  Boolean defval = xBool( RocsWgen_blink );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getBool( node, "blink", defval );
}
static void _setblink(iONode node, Boolean p_blink) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setBool( node, "blink", p_blink );
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
  xNode( RocsWgen_co, node );
  return NodeOp.getStr( node, "blockid", defval );
}
static void _setblockid(iONode node, const char* p_blockid) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setStr( node, "blockid", p_blockid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blueChannel
 */
static struct __attrdef RocsWgen_blueChannel = {
  "blueChannel",  "Blue channel address",  "",  "int",  "0",  "0-*",  False,
};
static int _getblueChannel(iONode node) {
  int defval = xInt( RocsWgen_blueChannel );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getInt( node, "blueChannel", defval );
}
static void _setblueChannel(iONode node, int p_blueChannel) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setInt( node, "blueChannel", p_blueChannel );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * brightnessChannel
 */
static struct __attrdef RocsWgen_brightnessChannel = {
  "brightnessChannel",  "Brightnes channel address",  "",  "int",  "0",  "0-*",  False,
};
static int _getbrightnessChannel(iONode node) {
  int defval = xInt( RocsWgen_brightnessChannel );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getInt( node, "brightnessChannel", defval );
}
static void _setbrightnessChannel(iONode node, int p_brightnessChannel) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setInt( node, "brightnessChannel", p_brightnessChannel );
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
  xNode( RocsWgen_co, node );
  return NodeOp.getInt( node, "bus", defval );
}
static void _setbus(iONode node, int p_bus) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
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
  xNode( RocsWgen_co, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setStr( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * colortype
 */
static struct __attrdef RocsWgen_colortype = {
  "colortype",  "The output supports RGB color settings.",  "",  "bool",  "false",  "",  False,
};
static Boolean _iscolortype(iONode node) {
  Boolean defval = xBool( RocsWgen_colortype );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getBool( node, "colortype", defval );
}
static void _setcolortype(iONode node, Boolean p_colortype) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setBool( node, "colortype", p_colortype );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * delay
 */
static struct __attrdef RocsWgen_delay = {
  "delay",  "Turn off after x seconds if greater then 0",  "",  "int",  "0",  "0-*",  False,
};
static int _getdelay(iONode node) {
  int defval = xInt( RocsWgen_delay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getInt( node, "delay", defval );
}
static void _setdelay(iONode node, int p_delay) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setInt( node, "delay", p_delay );
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
  xNode( RocsWgen_co, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gate
 */
static struct __attrdef RocsWgen_gate = {
  "gate",  "gate of port.",  "",  "int",  "0",  "0-1",  True,
};
static int _getgate(iONode node) {
  int defval = xInt( RocsWgen_gate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getInt( node, "gate", defval );
}
static void _setgate(iONode node, int p_gate) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setInt( node, "gate", p_gate );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * greenChannel
 */
static struct __attrdef RocsWgen_greenChannel = {
  "greenChannel",  "Green channel address",  "",  "int",  "0",  "0-*",  False,
};
static int _getgreenChannel(iONode node) {
  int defval = xInt( RocsWgen_greenChannel );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getInt( node, "greenChannel", defval );
}
static void _setgreenChannel(iONode node, int p_greenChannel) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setInt( node, "greenChannel", p_greenChannel );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * grpid
 */
static struct __attrdef RocsWgen_grpid = {
  "grpid",  "Group ID; All buttons of this group must be true to trigger actions.",  "",  "string",  "",  "*",  False,
};
static const char* _getgrpid(iONode node) {
  const char* defval = xStr( RocsWgen_grpid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getStr( node, "grpid", defval );
}
static void _setgrpid(iONode node, const char* p_grpid) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setStr( node, "grpid", p_grpid );
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
  xNode( RocsWgen_co, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
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
  xNode( RocsWgen_co, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * inv
 */
static struct __attrdef RocsWgen_inv = {
  "inv",  "Output as switch inverted. (Software wiring correction)",  "",  "bool",  "false",  "",  False,
};
static Boolean _isinv(iONode node) {
  Boolean defval = xBool( RocsWgen_inv );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getBool( node, "inv", defval );
}
static void _setinv(iONode node, Boolean p_inv) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setBool( node, "inv", p_inv );
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
  xNode( RocsWgen_co, node );
  return NodeOp.getStr( node, "oid", defval );
}
static void _setoid(iONode node, const char* p_oid) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
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
  xNode( RocsWgen_co, node );
  return NodeOp.getStr( node, "ori", defval );
}
static void _setori(iONode node, const char* p_ori) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setStr( node, "ori", p_ori );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * param
 */
static struct __attrdef RocsWgen_param = {
  "param",  "output parameter",  "",  "int",  "0",  "0-*",  False,
};
static int _getparam(iONode node) {
  int defval = xInt( RocsWgen_param );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getInt( node, "param", defval );
}
static void _setparam(iONode node, int p_param) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setInt( node, "param", p_param );
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
  xNode( RocsWgen_co, node );
  return NodeOp.getInt( node, "pause", defval );
}
static void _setpause(iONode node, int p_pause) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setInt( node, "pause", p_pause );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "port of decoder module: 0 = not used.",  "",  "int",  "0",  "0-4",  True,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setInt( node, "port", p_port );
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
  xNode( RocsWgen_co, node );
  return NodeOp.getInt( node, "porttype", defval );
}
static void _setporttype(iONode node, int p_porttype) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setInt( node, "porttype", p_porttype );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * prot
 */
static struct __attrdef RocsWgen_prot = {
  "prot",  "Protocol to use for this output.",  "",  "string",  "D",  "M,N,D,mdd,om32,do,vo",  False,
};
static const char* _getprot(iONode node) {
  const char* defval = xStr( RocsWgen_prot );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getStr( node, "prot", defval );
}
static void _setprot(iONode node, const char* p_prot) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setStr( node, "prot", p_prot );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * redChannel
 */
static struct __attrdef RocsWgen_redChannel = {
  "redChannel",  "Red channel address",  "",  "int",  "0",  "0-*",  False,
};
static int _getredChannel(iONode node) {
  int defval = xInt( RocsWgen_redChannel );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getInt( node, "redChannel", defval );
}
static void _setredChannel(iONode node, int p_redChannel) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setInt( node, "redChannel", p_redChannel );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * show
 */
static struct __attrdef RocsWgen_show = {
  "show",  "Visibility flag.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isshow(iONode node) {
  Boolean defval = xBool( RocsWgen_show );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getBool( node, "show", defval );
}
static void _setshow(iONode node, Boolean p_show) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setBool( node, "show", p_show );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * state
 */
static struct __attrdef RocsWgen_state = {
  "state",  "Current state of output.",  "",  "string",  "NULL",  "on,off",  False,
};
static const char* _getstate(iONode node) {
  const char* defval = xStr( RocsWgen_state );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getStr( node, "state", defval );
}
static void _setstate(iONode node, const char* p_state) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setStr( node, "state", p_state );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * svgtype
 */
static struct __attrdef RocsWgen_svgtype = {
  "svgtype",  "Defines which SVG symbol should be used in case of show.",  "",  "int",  "0",  "0-*",  False,
};
static int _getsvgtype(iONode node) {
  int defval = xInt( RocsWgen_svgtype );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getInt( node, "svgtype", defval );
}
static void _setsvgtype(iONode node, int p_svgtype) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setInt( node, "svgtype", p_svgtype );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * toggleswitch
 */
static struct __attrdef RocsWgen_toggleswitch = {
  "toggleswitch",  "Toggle switch or push button.",  "",  "bool",  "true",  "",  False,
};
static Boolean _istoggleswitch(iONode node) {
  Boolean defval = xBool( RocsWgen_toggleswitch );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getBool( node, "toggleswitch", defval );
}
static void _settoggleswitch(iONode node, Boolean p_toggleswitch) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setBool( node, "toggleswitch", p_toggleswitch );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * tristate
 */
static struct __attrdef RocsWgen_tristate = {
  "tristate",  "Tri-state flag.",  "",  "bool",  "false",  "",  False,
};
static Boolean _istristate(iONode node) {
  Boolean defval = xBool( RocsWgen_tristate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getBool( node, "tristate", defval );
}
static void _settristate(iONode node, Boolean p_tristate) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setBool( node, "tristate", p_tristate );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * type
 */
static struct __attrdef RocsWgen_type = {
  "type",  "",  "",  "string",  "output",  "output,switch,button",  False,
};
static const char* _gettype(iONode node) {
  const char* defval = xStr( RocsWgen_type );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getStr( node, "type", defval );
}
static void _settype(iONode node, const char* p_type) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setStr( node, "type", p_type );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * value
 */
static struct __attrdef RocsWgen_value = {
  "value",  "output value",  "",  "int",  "1",  "0-*",  False,
};
static int _getvalue(iONode node) {
  int defval = xInt( RocsWgen_value );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getInt( node, "value", defval );
}
static void _setvalue(iONode node, int p_value) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setInt( node, "value", p_value );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * white2Channel
 */
static struct __attrdef RocsWgen_white2Channel = {
  "white2Channel",  "Second white channel address",  "",  "int",  "0",  "0-*",  False,
};
static int _getwhite2Channel(iONode node) {
  int defval = xInt( RocsWgen_white2Channel );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getInt( node, "white2Channel", defval );
}
static void _setwhite2Channel(iONode node, int p_white2Channel) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setInt( node, "white2Channel", p_white2Channel );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * whiteChannel
 */
static struct __attrdef RocsWgen_whiteChannel = {
  "whiteChannel",  "White channel address",  "",  "int",  "0",  "0-*",  False,
};
static int _getwhiteChannel(iONode node) {
  int defval = xInt( RocsWgen_whiteChannel );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_co, node );
  return NodeOp.getInt( node, "whiteChannel", defval );
}
static void _setwhiteChannel(iONode node, int p_whiteChannel) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setInt( node, "whiteChannel", p_whiteChannel );
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
  xNode( RocsWgen_co, node );
  return NodeOp.getInt( node, "x", defval );
}
static void _setx(iONode node, int p_x) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
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
  xNode( RocsWgen_co, node );
  return NodeOp.getInt( node, "y", defval );
}
static void _sety(iONode node, int p_y) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
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
  xNode( RocsWgen_co, node );
  return NodeOp.getInt( node, "z", defval );
}
static void _setz(iONode node, int p_z) {
  if( node == NULL ) return;
  xNode( RocsWgen_co, node );
  NodeOp.setInt( node, "z", p_z );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * actionctrl
 */
static struct __nodedef RocsWgen_actionctrl = {
  "actionctrl",  "",  False,  "n",};
static iONode _getactionctrl(iONode node) {
  xNode( RocsWgen_co, node );
  return NodeOp.findNode( node, "actionctrl");
}


static iONode _nextactionctrl(iONode node, iONode child) {
  xNode( RocsWgen_co, node );
  return NodeOp.findNextNode( node, child);
}
static void _setactionctrl(iONode node, iONode p_actionctrl) {
  xNode( RocsWgen_co, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * color
 */
static struct __nodedef RocsWgen_color = {
  "color",  "",  False,  "1",};
static iONode _getcolor(iONode node) {
  xNode( RocsWgen_co, node );
  return NodeOp.findNode( node, "color");
}


static iONode _nextcolor(iONode node, iONode child) {
  xNode( RocsWgen_co, node );
  return NodeOp.findNextNode( node, child);
}
static void _setcolor(iONode node, iONode p_color) {
  xNode( RocsWgen_co, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[39] = {NULL};
static struct __nodedef* nodeList[3] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_co.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node co not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node co not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_accessory;
  attrList[1] = &RocsWgen_addr;
  attrList[2] = &RocsWgen_asswitch;
  attrList[3] = &RocsWgen_blink;
  attrList[4] = &RocsWgen_blockid;
  attrList[5] = &RocsWgen_blueChannel;
  attrList[6] = &RocsWgen_brightnessChannel;
  attrList[7] = &RocsWgen_bus;
  attrList[8] = &RocsWgen_cmd;
  attrList[9] = &RocsWgen_colortype;
  attrList[10] = &RocsWgen_delay;
  attrList[11] = &RocsWgen_desc;
  attrList[12] = &RocsWgen_gate;
  attrList[13] = &RocsWgen_greenChannel;
  attrList[14] = &RocsWgen_grpid;
  attrList[15] = &RocsWgen_id;
  attrList[16] = &RocsWgen_iid;
  attrList[17] = &RocsWgen_inv;
  attrList[18] = &RocsWgen_oid;
  attrList[19] = &RocsWgen_ori;
  attrList[20] = &RocsWgen_param;
  attrList[21] = &RocsWgen_pause;
  attrList[22] = &RocsWgen_port;
  attrList[23] = &RocsWgen_porttype;
  attrList[24] = &RocsWgen_prot;
  attrList[25] = &RocsWgen_redChannel;
  attrList[26] = &RocsWgen_show;
  attrList[27] = &RocsWgen_state;
  attrList[28] = &RocsWgen_svgtype;
  attrList[29] = &RocsWgen_toggleswitch;
  attrList[30] = &RocsWgen_tristate;
  attrList[31] = &RocsWgen_type;
  attrList[32] = &RocsWgen_value;
  attrList[33] = &RocsWgen_white2Channel;
  attrList[34] = &RocsWgen_whiteChannel;
  attrList[35] = &RocsWgen_x;
  attrList[36] = &RocsWgen_y;
  attrList[37] = &RocsWgen_z;
  attrList[38] = NULL;
  nodeList[0] = &RocsWgen_actionctrl;
  nodeList[1] = &RocsWgen_color;
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


struct __wOutput wOutput = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "active",
  "flip",
  "off",
  "on",
  "D",
  "do",
  "M",
  "mdd",
  "N",
  "om32",
  "vo",
  "sod",
  "value",
  _isaccessory,
  _setaccessory,
  _getaddr,
  _setaddr,
  _isasswitch,
  _setasswitch,
  _isblink,
  _setblink,
  _getblockid,
  _setblockid,
  _getblueChannel,
  _setblueChannel,
  _getbrightnessChannel,
  _setbrightnessChannel,
  _getbus,
  _setbus,
  _getcmd,
  _setcmd,
  _iscolortype,
  _setcolortype,
  _getdelay,
  _setdelay,
  _getdesc,
  _setdesc,
  _getgate,
  _setgate,
  _getgreenChannel,
  _setgreenChannel,
  _getgrpid,
  _setgrpid,
  _getid,
  _setid,
  _getiid,
  _setiid,
  _isinv,
  _setinv,
  _getoid,
  _setoid,
  _getori,
  _setori,
  _getparam,
  _setparam,
  _getpause,
  _setpause,
  _getport,
  _setport,
  _getporttype,
  _setporttype,
  _getprot,
  _setprot,
  _getredChannel,
  _setredChannel,
  _isshow,
  _setshow,
  _getstate,
  _setstate,
  _getsvgtype,
  _setsvgtype,
  _istoggleswitch,
  _settoggleswitch,
  _istristate,
  _settristate,
  _gettype,
  _settype,
  _getvalue,
  _setvalue,
  _getwhite2Channel,
  _setwhite2Channel,
  _getwhiteChannel,
  _setwhiteChannel,
  _getx,
  _setx,
  _gety,
  _sety,
  _getz,
  _setz,
  _getactionctrl,
  _nextactionctrl,
  _setactionctrl,
  _getcolor,
  _nextcolor,
  _setcolor,
  _node_dump,
};
