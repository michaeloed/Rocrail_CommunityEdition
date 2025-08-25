/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Switch.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Switch
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_sw = {
  "sw",  "Switch definition.",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_sw.name;
}
static const char* _node_remark(void) {
  return RocsWgen_sw.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_sw.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_sw.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * accessory
 */
static struct __attrdef RocsWgen_accessory = {
  "accessory",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isaccessory(iONode node) {
  Boolean defval = xBool( RocsWgen_accessory );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "accessory", defval );
}
static void _setaccessory(iONode node, Boolean p_accessory) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "accessory", p_accessory );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * accnr
 */
static struct __attrdef RocsWgen_accnr = {
  "accnr",  "Accessory number.",  "",  "int",  "0",  "0-*",  False,
};
static int _getaccnr(iONode node) {
  int defval = xInt( RocsWgen_accnr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "accnr", defval );
}
static void _setaccnr(iONode node, int p_accnr) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "accnr", p_accnr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * actdelay
 */
static struct __attrdef RocsWgen_actdelay = {
  "actdelay",  "if false: delay is programmed in central unit or module",  "",  "bool",  "false",  "",  False,
};
static Boolean _isactdelay(iONode node) {
  Boolean defval = xBool( RocsWgen_actdelay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "actdelay", defval );
}
static void _setactdelay(iONode node, Boolean p_actdelay) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "actdelay", p_actdelay );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * activate
 */
static struct __attrdef RocsWgen_activate = {
  "activate",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isactivate(iONode node) {
  Boolean defval = xBool( RocsWgen_activate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "activate", defval );
}
static void _setactivate(iONode node, Boolean p_activate) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "activate", p_activate );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr0pol1
 */
static struct __attrdef RocsWgen_addr0pol1 = {
  "addr0pol1",  "decoder address of the polarisation",  "",  "int",  "0",  "0-*",  False,
};
static int _getaddr0pol1(iONode node) {
  int defval = xInt( RocsWgen_addr0pol1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "addr0pol1", defval );
}
static void _setaddr0pol1(iONode node, int p_addr0pol1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "addr0pol1", p_addr0pol1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr0pol2
 */
static struct __attrdef RocsWgen_addr0pol2 = {
  "addr0pol2",  "decoder address of the polarisation",  "",  "int",  "0",  "0-*",  False,
};
static int _getaddr0pol2(iONode node) {
  int defval = xInt( RocsWgen_addr0pol2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "addr0pol2", defval );
}
static void _setaddr0pol2(iONode node, int p_addr0pol2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "addr0pol2", p_addr0pol2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr1
 */
static struct __attrdef RocsWgen_addr1 = {
  "addr1",  "decoder address",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr1(iONode node) {
  int defval = xInt( RocsWgen_addr1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "addr1", defval );
}
static void _setaddr1(iONode node, int p_addr1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "addr1", p_addr1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr1pol1
 */
static struct __attrdef RocsWgen_addr1pol1 = {
  "addr1pol1",  "decoder address of the polarisation",  "",  "int",  "0",  "0-*",  False,
};
static int _getaddr1pol1(iONode node) {
  int defval = xInt( RocsWgen_addr1pol1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "addr1pol1", defval );
}
static void _setaddr1pol1(iONode node, int p_addr1pol1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "addr1pol1", p_addr1pol1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr1pol2
 */
static struct __attrdef RocsWgen_addr1pol2 = {
  "addr1pol2",  "decoder address of the polarisation",  "",  "int",  "0",  "0-*",  False,
};
static int _getaddr1pol2(iONode node) {
  int defval = xInt( RocsWgen_addr1pol2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "addr1pol2", defval );
}
static void _setaddr1pol2(iONode node, int p_addr1pol2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "addr1pol2", p_addr1pol2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr2
 */
static struct __attrdef RocsWgen_addr2 = {
  "addr2",  "decoder address in case of type 3way",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr2(iONode node) {
  int defval = xInt( RocsWgen_addr2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "addr2", defval );
}
static void _setaddr2(iONode node, int p_addr2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "addr2", p_addr2 );
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
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "blockid", defval );
}
static void _setblockid(iONode node, const char* p_blockid) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
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
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "bus", defval );
}
static void _setbus(iONode node, int p_bus) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "bus", p_bus );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * buspol
 */
static struct __attrdef RocsWgen_buspol = {
  "buspol",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getbuspol(iONode node) {
  int defval = xInt( RocsWgen_buspol );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "buspol", defval );
}
static void _setbuspol(iONode node, int p_buspol) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "buspol", p_buspol );
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
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmd_extra
 */
static struct __attrdef RocsWgen_cmd_extra = {
  "cmd_extra",  "",  "",  "int",  "0",  "",  False,
};
static int _getcmd_extra(iONode node) {
  int defval = xInt( RocsWgen_cmd_extra );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "cmd_extra", defval );
}
static void _setcmd_extra(iONode node, int p_cmd_extra) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "cmd_extra", p_cmd_extra );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmd_lcid
 */
static struct __attrdef RocsWgen_cmd_lcid = {
  "cmd_lcid",  "",  "",  "const char*",  "NULL",  "",  False,
};
static const char* _getcmd_lcid(iONode node) {
  const char* defval = xStr( RocsWgen_cmd_lcid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "cmd_lcid", defval );
}
static void _setcmd_lcid(iONode node, const char* p_cmd_lcid) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "cmd_lcid", p_cmd_lcid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmd_update
 */
static struct __attrdef RocsWgen_cmd_update = {
  "cmd_update",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _iscmd_update(iONode node) {
  Boolean defval = xBool( RocsWgen_cmd_update );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "cmd_update", defval );
}
static void _setcmd_update(iONode node, Boolean p_cmd_update) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "cmd_update", p_cmd_update );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcaddr1
 */
static struct __attrdef RocsWgen_ctcaddr1 = {
  "ctcaddr1",  "address",  "",  "int",  "0",  "0-*",  True,
};
static int _getctcaddr1(iONode node) {
  int defval = xInt( RocsWgen_ctcaddr1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "ctcaddr1", defval );
}
static void _setctcaddr1(iONode node, int p_ctcaddr1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "ctcaddr1", p_ctcaddr1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcaddr2
 */
static struct __attrdef RocsWgen_ctcaddr2 = {
  "ctcaddr2",  "address",  "",  "int",  "0",  "0-*",  True,
};
static int _getctcaddr2(iONode node) {
  int defval = xInt( RocsWgen_ctcaddr2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "ctcaddr2", defval );
}
static void _setctcaddr2(iONode node, int p_ctcaddr2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "ctcaddr2", p_ctcaddr2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcaddrled1
 */
static struct __attrdef RocsWgen_ctcaddrled1 = {
  "ctcaddrled1",  "address",  "",  "int",  "0",  "0-*",  True,
};
static int _getctcaddrled1(iONode node) {
  int defval = xInt( RocsWgen_ctcaddrled1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "ctcaddrled1", defval );
}
static void _setctcaddrled1(iONode node, int p_ctcaddrled1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "ctcaddrled1", p_ctcaddrled1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcaddrled2
 */
static struct __attrdef RocsWgen_ctcaddrled2 = {
  "ctcaddrled2",  "address",  "",  "int",  "0",  "0-*",  True,
};
static int _getctcaddrled2(iONode node) {
  int defval = xInt( RocsWgen_ctcaddrled2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "ctcaddrled2", defval );
}
static void _setctcaddrled2(iONode node, int p_ctcaddrled2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "ctcaddrled2", p_ctcaddrled2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcasswitchled1
 */
static struct __attrdef RocsWgen_ctcasswitchled1 = {
  "ctcasswitchled1",  "send a switch command",  "",  "bool",  "false",  "",  False,
};
static Boolean _isctcasswitchled1(iONode node) {
  Boolean defval = xBool( RocsWgen_ctcasswitchled1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "ctcasswitchled1", defval );
}
static void _setctcasswitchled1(iONode node, Boolean p_ctcasswitchled1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "ctcasswitchled1", p_ctcasswitchled1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcasswitchled2
 */
static struct __attrdef RocsWgen_ctcasswitchled2 = {
  "ctcasswitchled2",  "send a switch command",  "",  "bool",  "false",  "",  False,
};
static Boolean _isctcasswitchled2(iONode node) {
  Boolean defval = xBool( RocsWgen_ctcasswitchled2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "ctcasswitchled2", defval );
}
static void _setctcasswitchled2(iONode node, Boolean p_ctcasswitchled2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "ctcasswitchled2", p_ctcasswitchled2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcbus1
 */
static struct __attrdef RocsWgen_ctcbus1 = {
  "ctcbus1",  "Some systems support more than one bus: SLX",  "",  "int",  "0",  "0-*",  False,
};
static int _getctcbus1(iONode node) {
  int defval = xInt( RocsWgen_ctcbus1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "ctcbus1", defval );
}
static void _setctcbus1(iONode node, int p_ctcbus1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "ctcbus1", p_ctcbus1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcbus2
 */
static struct __attrdef RocsWgen_ctcbus2 = {
  "ctcbus2",  "Some systems support more than one bus: SLX",  "",  "int",  "0",  "0-*",  False,
};
static int _getctcbus2(iONode node) {
  int defval = xInt( RocsWgen_ctcbus2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "ctcbus2", defval );
}
static void _setctcbus2(iONode node, int p_ctcbus2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "ctcbus2", p_ctcbus2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcbusled1
 */
static struct __attrdef RocsWgen_ctcbusled1 = {
  "ctcbusled1",  "Some systems support more than one bus: SLX",  "",  "int",  "0",  "0-*",  False,
};
static int _getctcbusled1(iONode node) {
  int defval = xInt( RocsWgen_ctcbusled1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "ctcbusled1", defval );
}
static void _setctcbusled1(iONode node, int p_ctcbusled1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "ctcbusled1", p_ctcbusled1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcbusled2
 */
static struct __attrdef RocsWgen_ctcbusled2 = {
  "ctcbusled2",  "Some systems support more than one bus: SLX",  "",  "int",  "0",  "0-*",  False,
};
static int _getctcbusled2(iONode node) {
  int defval = xInt( RocsWgen_ctcbusled2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "ctcbusled2", defval );
}
static void _setctcbusled2(iONode node, int p_ctcbusled2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "ctcbusled2", p_ctcbusled2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctccmdon1
 */
static struct __attrdef RocsWgen_ctccmdon1 = {
  "ctccmdon1",  "Straight command at ON.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isctccmdon1(iONode node) {
  Boolean defval = xBool( RocsWgen_ctccmdon1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "ctccmdon1", defval );
}
static void _setctccmdon1(iONode node, Boolean p_ctccmdon1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "ctccmdon1", p_ctccmdon1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctccmdon2
 */
static struct __attrdef RocsWgen_ctccmdon2 = {
  "ctccmdon2",  "Straight command at ON.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isctccmdon2(iONode node) {
  Boolean defval = xBool( RocsWgen_ctccmdon2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "ctccmdon2", defval );
}
static void _setctccmdon2(iONode node, Boolean p_ctccmdon2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "ctccmdon2", p_ctccmdon2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcflip1
 */
static struct __attrdef RocsWgen_ctcflip1 = {
  "ctcflip1",  "Straight command at ON.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isctcflip1(iONode node) {
  Boolean defval = xBool( RocsWgen_ctcflip1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "ctcflip1", defval );
}
static void _setctcflip1(iONode node, Boolean p_ctcflip1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "ctcflip1", p_ctcflip1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcflip2
 */
static struct __attrdef RocsWgen_ctcflip2 = {
  "ctcflip2",  "Straight command at ON.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isctcflip2(iONode node) {
  Boolean defval = xBool( RocsWgen_ctcflip2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "ctcflip2", defval );
}
static void _setctcflip2(iONode node, Boolean p_ctcflip2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "ctcflip2", p_ctcflip2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcgateled1
 */
static struct __attrdef RocsWgen_ctcgateled1 = {
  "ctcgateled1",  "gate of port.",  "",  "int",  "0",  "0-1",  True,
};
static int _getctcgateled1(iONode node) {
  int defval = xInt( RocsWgen_ctcgateled1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "ctcgateled1", defval );
}
static void _setctcgateled1(iONode node, int p_ctcgateled1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "ctcgateled1", p_ctcgateled1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcgateled2
 */
static struct __attrdef RocsWgen_ctcgateled2 = {
  "ctcgateled2",  "gate of port.",  "",  "int",  "0",  "0-1",  True,
};
static int _getctcgateled2(iONode node) {
  int defval = xInt( RocsWgen_ctcgateled2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "ctcgateled2", defval );
}
static void _setctcgateled2(iONode node, int p_ctcgateled2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "ctcgateled2", p_ctcgateled2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctciid1
 */
static struct __attrdef RocsWgen_ctciid1 = {
  "ctciid1",  "Interface ID.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getctciid1(iONode node) {
  const char* defval = xStr( RocsWgen_ctciid1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "ctciid1", defval );
}
static void _setctciid1(iONode node, const char* p_ctciid1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "ctciid1", p_ctciid1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctciid2
 */
static struct __attrdef RocsWgen_ctciid2 = {
  "ctciid2",  "Interface ID.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getctciid2(iONode node) {
  const char* defval = xStr( RocsWgen_ctciid2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "ctciid2", defval );
}
static void _setctciid2(iONode node, const char* p_ctciid2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "ctciid2", p_ctciid2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctciidled1
 */
static struct __attrdef RocsWgen_ctciidled1 = {
  "ctciidled1",  "Interface ID.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getctciidled1(iONode node) {
  const char* defval = xStr( RocsWgen_ctciidled1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "ctciidled1", defval );
}
static void _setctciidled1(iONode node, const char* p_ctciidled1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "ctciidled1", p_ctciidled1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctciidled2
 */
static struct __attrdef RocsWgen_ctciidled2 = {
  "ctciidled2",  "Interface ID.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getctciidled2(iONode node) {
  const char* defval = xStr( RocsWgen_ctciidled2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "ctciidled2", defval );
}
static void _setctciidled2(iONode node, const char* p_ctciidled2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "ctciidled2", p_ctciidled2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcportled1
 */
static struct __attrdef RocsWgen_ctcportled1 = {
  "ctcportled1",  "port of decoder module: 0 = not used.",  "",  "int",  "0",  "0-4",  True,
};
static int _getctcportled1(iONode node) {
  int defval = xInt( RocsWgen_ctcportled1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "ctcportled1", defval );
}
static void _setctcportled1(iONode node, int p_ctcportled1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "ctcportled1", p_ctcportled1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcportled2
 */
static struct __attrdef RocsWgen_ctcportled2 = {
  "ctcportled2",  "port of decoder module: 0 = not used.",  "",  "int",  "0",  "0-4",  True,
};
static int _getctcportled2(iONode node) {
  int defval = xInt( RocsWgen_ctcportled2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "ctcportled2", defval );
}
static void _setctcportled2(iONode node, int p_ctcportled2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "ctcportled2", p_ctcportled2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * delay
 */
static struct __attrdef RocsWgen_delay = {
  "delay",  "overwrites control.swtimeout if greater then 0",  "",  "int",  "0",  "0-*",  False,
};
static int _getdelay(iONode node) {
  int defval = xInt( RocsWgen_delay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "delay", defval );
}
static void _setdelay(iONode node, int p_delay) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "delay", p_delay );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * delaytime
 */
static struct __attrdef RocsWgen_delaytime = {
  "delaytime",  "Delay timer for internal use only.",  "",  "long",  "0",  "0-*",  False,
};
static long _getdelaytime(iONode node) {
  long defval = xLong( RocsWgen_delaytime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getLong( node, "delaytime", defval );
}
static void _setdelaytime(iONode node, long p_delaytime) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setLong( node, "delaytime", p_delaytime );
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
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * dir
 */
static struct __attrdef RocsWgen_dir = {
  "dir",  "false=left, true=right",  "",  "bool",  "false",  "",  False,
};
static Boolean _isdir(iONode node) {
  Boolean defval = xBool( RocsWgen_dir );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "dir", defval );
}
static void _setdir(iONode node, Boolean p_dir) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "dir", p_dir );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fb2G
 */
static struct __attrdef RocsWgen_fb2G = {
  "fb2G",  "Optional feedback for straigh(Green) state.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getfb2G(iONode node) {
  const char* defval = xStr( RocsWgen_fb2G );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "fb2G", defval );
}
static void _setfb2G(iONode node, const char* p_fb2G) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "fb2G", p_fb2G );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fb2Ginv
 */
static struct __attrdef RocsWgen_fb2Ginv = {
  "fb2Ginv",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isfb2Ginv(iONode node) {
  Boolean defval = xBool( RocsWgen_fb2Ginv );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "fb2Ginv", defval );
}
static void _setfb2Ginv(iONode node, Boolean p_fb2Ginv) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "fb2Ginv", p_fb2Ginv );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fb2R
 */
static struct __attrdef RocsWgen_fb2R = {
  "fb2R",  "Optional feedback for turnout(Red) state.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getfb2R(iONode node) {
  const char* defval = xStr( RocsWgen_fb2R );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "fb2R", defval );
}
static void _setfb2R(iONode node, const char* p_fb2R) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "fb2R", p_fb2R );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fb2Rinv
 */
static struct __attrdef RocsWgen_fb2Rinv = {
  "fb2Rinv",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isfb2Rinv(iONode node) {
  Boolean defval = xBool( RocsWgen_fb2Rinv );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "fb2Rinv", defval );
}
static void _setfb2Rinv(iONode node, Boolean p_fb2Rinv) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "fb2Rinv", p_fb2Rinv );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbG
 */
static struct __attrdef RocsWgen_fbG = {
  "fbG",  "Optional feedback for straigh(Green) state.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getfbG(iONode node) {
  const char* defval = xStr( RocsWgen_fbG );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "fbG", defval );
}
static void _setfbG(iONode node, const char* p_fbG) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "fbG", p_fbG );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbGinv
 */
static struct __attrdef RocsWgen_fbGinv = {
  "fbGinv",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isfbGinv(iONode node) {
  Boolean defval = xBool( RocsWgen_fbGinv );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "fbGinv", defval );
}
static void _setfbGinv(iONode node, Boolean p_fbGinv) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "fbGinv", p_fbGinv );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbOcc
 */
static struct __attrdef RocsWgen_fbOcc = {
  "fbOcc",  "Optional feedback for occupancy to block commands.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getfbOcc(iONode node) {
  const char* defval = xStr( RocsWgen_fbOcc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "fbOcc", defval );
}
static void _setfbOcc(iONode node, const char* p_fbOcc) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "fbOcc", p_fbOcc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbOcc2
 */
static struct __attrdef RocsWgen_fbOcc2 = {
  "fbOcc2",  "Optional feedback for occupancy to block commands.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getfbOcc2(iONode node) {
  const char* defval = xStr( RocsWgen_fbOcc2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "fbOcc2", defval );
}
static void _setfbOcc2(iONode node, const char* p_fbOcc2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "fbOcc2", p_fbOcc2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbR
 */
static struct __attrdef RocsWgen_fbR = {
  "fbR",  "Optional feedback for turnout(Red) state.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getfbR(iONode node) {
  const char* defval = xStr( RocsWgen_fbR );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "fbR", defval );
}
static void _setfbR(iONode node, const char* p_fbR) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "fbR", p_fbR );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbRinv
 */
static struct __attrdef RocsWgen_fbRinv = {
  "fbRinv",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isfbRinv(iONode node) {
  Boolean defval = xBool( RocsWgen_fbRinv );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "fbRinv", defval );
}
static void _setfbRinv(iONode node, Boolean p_fbRinv) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "fbRinv", p_fbRinv );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbset
 */
static struct __attrdef RocsWgen_fbset = {
  "fbset",  "Feedback sets the switch unconditional.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isfbset(iONode node) {
  Boolean defval = xBool( RocsWgen_fbset );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "fbset", defval );
}
static void _setfbset(iONode node, Boolean p_fbset) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "fbset", p_fbset );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbusefield
 */
static struct __attrdef RocsWgen_fbusefield = {
  "fbusefield",  "Use field events as feedback.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isfbusefield(iONode node) {
  Boolean defval = xBool( RocsWgen_fbusefield );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "fbusefield", defval );
}
static void _setfbusefield(iONode node, Boolean p_fbusefield) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "fbusefield", p_fbusefield );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fieldstate
 */
static struct __attrdef RocsWgen_fieldstate = {
  "fieldstate",  "Current reported state of switch.",  "",  "string",  "NULL",  "straight,turnout,red,green,left,right",  False,
};
static const char* _getfieldstate(iONode node) {
  const char* defval = xStr( RocsWgen_fieldstate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "fieldstate", defval );
}
static void _setfieldstate(iONode node, const char* p_fieldstate) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "fieldstate", p_fieldstate );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * forcecmd
 */
static struct __attrdef RocsWgen_forcecmd = {
  "forcecmd",  "Force command.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isforcecmd(iONode node) {
  Boolean defval = xBool( RocsWgen_forcecmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "forcecmd", defval );
}
static void _setforcecmd(iONode node, Boolean p_forcecmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "forcecmd", p_forcecmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * frogaccessory
 */
static struct __attrdef RocsWgen_frogaccessory = {
  "frogaccessory",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isfrogaccessory(iONode node) {
  Boolean defval = xBool( RocsWgen_frogaccessory );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "frogaccessory", defval );
}
static void _setfrogaccessory(iONode node, Boolean p_frogaccessory) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "frogaccessory", p_frogaccessory );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * frogiid
 */
static struct __attrdef RocsWgen_frogiid = {
  "frogiid",  "Interface ID",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getfrogiid(iONode node) {
  const char* defval = xStr( RocsWgen_frogiid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "frogiid", defval );
}
static void _setfrogiid(iONode node, const char* p_frogiid) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "frogiid", p_frogiid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * frogporttype
 */
static struct __attrdef RocsWgen_frogporttype = {
  "frogporttype",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getfrogporttype(iONode node) {
  int defval = xInt( RocsWgen_frogporttype );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "frogporttype", defval );
}
static void _setfrogporttype(iONode node, int p_frogporttype) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "frogporttype", p_frogporttype );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * frogswitch
 */
static struct __attrdef RocsWgen_frogswitch = {
  "frogswitch",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isfrogswitch(iONode node) {
  Boolean defval = xBool( RocsWgen_frogswitch );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "frogswitch", defval );
}
static void _setfrogswitch(iONode node, Boolean p_frogswitch) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "frogswitch", p_frogswitch );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * frogtimer
 */
static struct __attrdef RocsWgen_frogtimer = {
  "frogtimer",  "If set to zero the wiring event is used.",  "",  "int",  "0",  "0-1000",  False,
};
static int _getfrogtimer(iONode node) {
  int defval = xInt( RocsWgen_frogtimer );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "frogtimer", defval );
}
static void _setfrogtimer(iONode node, int p_frogtimer) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "frogtimer", p_frogtimer );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gate0pol1
 */
static struct __attrdef RocsWgen_gate0pol1 = {
  "gate0pol1",  "gate of port.",  "",  "int",  "0",  "0-1",  False,
};
static int _getgate0pol1(iONode node) {
  int defval = xInt( RocsWgen_gate0pol1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "gate0pol1", defval );
}
static void _setgate0pol1(iONode node, int p_gate0pol1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "gate0pol1", p_gate0pol1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gate0pol2
 */
static struct __attrdef RocsWgen_gate0pol2 = {
  "gate0pol2",  "gate of port.",  "",  "int",  "0",  "0-1",  False,
};
static int _getgate0pol2(iONode node) {
  int defval = xInt( RocsWgen_gate0pol2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "gate0pol2", defval );
}
static void _setgate0pol2(iONode node, int p_gate0pol2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "gate0pol2", p_gate0pol2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gate1
 */
static struct __attrdef RocsWgen_gate1 = {
  "gate1",  "gate of port.",  "",  "int",  "0",  "0-1",  True,
};
static int _getgate1(iONode node) {
  int defval = xInt( RocsWgen_gate1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "gate1", defval );
}
static void _setgate1(iONode node, int p_gate1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "gate1", p_gate1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gate1pol1
 */
static struct __attrdef RocsWgen_gate1pol1 = {
  "gate1pol1",  "gate of port.",  "",  "int",  "0",  "0-1",  False,
};
static int _getgate1pol1(iONode node) {
  int defval = xInt( RocsWgen_gate1pol1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "gate1pol1", defval );
}
static void _setgate1pol1(iONode node, int p_gate1pol1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "gate1pol1", p_gate1pol1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gate1pol2
 */
static struct __attrdef RocsWgen_gate1pol2 = {
  "gate1pol2",  "gate of port.",  "",  "int",  "0",  "0-1",  False,
};
static int _getgate1pol2(iONode node) {
  int defval = xInt( RocsWgen_gate1pol2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "gate1pol2", defval );
}
static void _setgate1pol2(iONode node, int p_gate1pol2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "gate1pol2", p_gate1pol2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gate2
 */
static struct __attrdef RocsWgen_gate2 = {
  "gate2",  "Only in case of type 3way.",  "",  "int",  "0",  "0-*",  False,
};
static int _getgate2(iONode node) {
  int defval = xInt( RocsWgen_gate2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "gate2", defval );
}
static void _setgate2(iONode node, int p_gate2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "gate2", p_gate2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * gatevalue
 */
static struct __attrdef RocsWgen_gatevalue = {
  "gatevalue",  "0=red 1=green 2=both",  "",  "int",  "2",  "0-2",  False,
};
static int _getgatevalue(iONode node) {
  int defval = xInt( RocsWgen_gatevalue );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "gatevalue", defval );
}
static void _setgatevalue(iONode node, int p_gatevalue) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "gatevalue", p_gatevalue );
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
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
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
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * initfield
 */
static struct __attrdef RocsWgen_initfield = {
  "initfield",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isinitfield(iONode node) {
  Boolean defval = xBool( RocsWgen_initfield );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "initfield", defval );
}
static void _setinitfield(iONode node, Boolean p_initfield) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "initfield", p_initfield );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * inv
 */
static struct __attrdef RocsWgen_inv = {
  "inv",  "Switch inverted. (Software wiring correction)",  "",  "bool",  "false",  "",  False,
};
static Boolean _isinv(iONode node) {
  Boolean defval = xBool( RocsWgen_inv );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "inv", defval );
}
static void _setinv(iONode node, Boolean p_inv) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "inv", p_inv );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * inv2
 */
static struct __attrdef RocsWgen_inv2 = {
  "inv2",  "Switch inverted. (Software wiring correction)",  "",  "bool",  "false",  "",  False,
};
static Boolean _isinv2(iONode node) {
  Boolean defval = xBool( RocsWgen_inv2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "inv2", defval );
}
static void _setinv2(iONode node, Boolean p_inv2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "inv2", p_inv2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * locid
 */
static struct __attrdef RocsWgen_locid = {
  "locid",  "The loc who locked this switch.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getlocid(iONode node) {
  const char* defval = xStr( RocsWgen_locid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "locid", defval );
}
static void _setlocid(iONode node, const char* p_locid) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "locid", p_locid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * manualcmd
 */
static struct __attrdef RocsWgen_manualcmd = {
  "manualcmd",  "Manual command issued from a client.",  "",  "bool",  "false",  "",  False,
};
static Boolean _ismanualcmd(iONode node) {
  Boolean defval = xBool( RocsWgen_manualcmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "manualcmd", defval );
}
static void _setmanualcmd(iONode node, Boolean p_manualcmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "manualcmd", p_manualcmd );
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
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "oid", defval );
}
static void _setoid(iONode node, const char* p_oid) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
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
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "ori", defval );
}
static void _setori(iONode node, const char* p_ori) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "ori", p_ori );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * param1
 */
static struct __attrdef RocsWgen_param1 = {
  "param1",  "parameter",  "",  "int",  "0",  "0-*",  False,
};
static int _getparam1(iONode node) {
  int defval = xInt( RocsWgen_param1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "param1", defval );
}
static void _setparam1(iONode node, int p_param1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "param1", p_param1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * param2
 */
static struct __attrdef RocsWgen_param2 = {
  "param2",  "parameter",  "",  "int",  "0",  "0-*",  False,
};
static int _getparam2(iONode node) {
  int defval = xInt( RocsWgen_param2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "param2", defval );
}
static void _setparam2(iONode node, int p_param2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "param2", p_param2 );
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
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "pause", defval );
}
static void _setpause(iONode node, int p_pause) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "pause", p_pause );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port0pol1
 */
static struct __attrdef RocsWgen_port0pol1 = {
  "port0pol1",  "port of decoder unit.",  "",  "int",  "0",  "0-*",  False,
};
static int _getport0pol1(iONode node) {
  int defval = xInt( RocsWgen_port0pol1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "port0pol1", defval );
}
static void _setport0pol1(iONode node, int p_port0pol1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "port0pol1", p_port0pol1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port0pol2
 */
static struct __attrdef RocsWgen_port0pol2 = {
  "port0pol2",  "port of decoder unit.",  "",  "int",  "0",  "0-*",  False,
};
static int _getport0pol2(iONode node) {
  int defval = xInt( RocsWgen_port0pol2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "port0pol2", defval );
}
static void _setport0pol2(iONode node, int p_port0pol2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "port0pol2", p_port0pol2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port1
 */
static struct __attrdef RocsWgen_port1 = {
  "port1",  "port of decoder unit.",  "",  "int",  "0",  "0-*",  True,
};
static int _getport1(iONode node) {
  int defval = xInt( RocsWgen_port1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "port1", defval );
}
static void _setport1(iONode node, int p_port1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "port1", p_port1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port1pol1
 */
static struct __attrdef RocsWgen_port1pol1 = {
  "port1pol1",  "port of decoder unit.",  "",  "int",  "0",  "0-*",  False,
};
static int _getport1pol1(iONode node) {
  int defval = xInt( RocsWgen_port1pol1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "port1pol1", defval );
}
static void _setport1pol1(iONode node, int p_port1pol1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "port1pol1", p_port1pol1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port1pol2
 */
static struct __attrdef RocsWgen_port1pol2 = {
  "port1pol2",  "port of decoder unit.",  "",  "int",  "0",  "0-*",  False,
};
static int _getport1pol2(iONode node) {
  int defval = xInt( RocsWgen_port1pol2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "port1pol2", defval );
}
static void _setport1pol2(iONode node, int p_port1pol2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "port1pol2", p_port1pol2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port2
 */
static struct __attrdef RocsWgen_port2 = {
  "port2",  "Only in case of type 3way.",  "",  "int",  "0",  "0-*",  False,
};
static int _getport2(iONode node) {
  int defval = xInt( RocsWgen_port2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "port2", defval );
}
static void _setport2(iONode node, int p_port2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "port2", p_port2 );
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
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "porttype", defval );
}
static void _setporttype(iONode node, int p_porttype) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
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
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "prot", defval );
}
static void _setprot(iONode node, const char* p_prot) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "prot", p_prot );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * rectcrossing
 */
static struct __attrdef RocsWgen_rectcrossing = {
  "rectcrossing",  "Rectangular crossing.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isrectcrossing(iONode node) {
  Boolean defval = xBool( RocsWgen_rectcrossing );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "rectcrossing", defval );
}
static void _setrectcrossing(iONode node, Boolean p_rectcrossing) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "rectcrossing", p_rectcrossing );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * savepos
 */
static struct __attrdef RocsWgen_savepos = {
  "savepos",  "save position of switch",  "",  "string",  "none",  "none,straight,turnout,left,right",  False,
};
static const char* _getsavepos(iONode node) {
  const char* defval = xStr( RocsWgen_savepos );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "savepos", defval );
}
static void _setsavepos(iONode node, const char* p_savepos) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "savepos", p_savepos );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * set
 */
static struct __attrdef RocsWgen_set = {
  "set",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isset(iONode node) {
  Boolean defval = xBool( RocsWgen_set );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "set", defval );
}
static void _setset(iONode node, Boolean p_set) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "set", p_set );
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
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "show", defval );
}
static void _setshow(iONode node, Boolean p_show) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "show", p_show );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * singlegate
 */
static struct __attrdef RocsWgen_singlegate = {
  "singlegate",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _issinglegate(iONode node) {
  Boolean defval = xBool( RocsWgen_singlegate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "singlegate", defval );
}
static void _setsinglegate(iONode node, Boolean p_singlegate) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "singlegate", p_singlegate );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * state
 */
static struct __attrdef RocsWgen_state = {
  "state",  "Current state of switch.",  "",  "string",  "NULL",  "straight,turnout,red,green,left,right",  False,
};
static const char* _getstate(iONode node) {
  const char* defval = xStr( RocsWgen_state );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "state", defval );
}
static void _setstate(iONode node, const char* p_state) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "state", p_state );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * subtype
 */
static struct __attrdef RocsWgen_subtype = {
  "subtype",  "",  "",  "string",  "default",  "default,subleft,subright",  False,
};
static const char* _getsubtype(iONode node) {
  const char* defval = xStr( RocsWgen_subtype );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "subtype", defval );
}
static void _setsubtype(iONode node, const char* p_subtype) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "subtype", p_subtype );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * swapstraight
 */
static struct __attrdef RocsWgen_swapstraight = {
  "swapstraight",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isswapstraight(iONode node) {
  Boolean defval = xBool( RocsWgen_swapstraight );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "swapstraight", defval );
}
static void _setswapstraight(iONode node, Boolean p_swapstraight) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "swapstraight", p_swapstraight );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * switched
 */
static struct __attrdef RocsWgen_switched = {
  "switched",  "Number of switch commands.",  "",  "int",  "0",  "0-*",  False,
};
static int _getswitched(iONode node) {
  int defval = xInt( RocsWgen_switched );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "switched", defval );
}
static void _setswitched(iONode node, int p_switched) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "switched", p_switched );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * swtype
 */
static struct __attrdef RocsWgen_swtype = {
  "swtype",  "",  "",  "string",  "default",  "default,raster",  False,
};
static const char* _getswtype(iONode node) {
  const char* defval = xStr( RocsWgen_swtype );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "swtype", defval );
}
static void _setswtype(iONode node, const char* p_swtype) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "swtype", p_swtype );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * syncdelay
 */
static struct __attrdef RocsWgen_syncdelay = {
  "syncdelay",  "Delay until is ready.",  "",  "bool",  "false",  "",  False,
};
static Boolean _issyncdelay(iONode node) {
  Boolean defval = xBool( RocsWgen_syncdelay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "syncdelay", defval );
}
static void _setsyncdelay(iONode node, Boolean p_syncdelay) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "syncdelay", p_syncdelay );
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
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "td", defval );
}
static void _settd(iONode node, Boolean p_td) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "td", p_td );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * tdaddr
 */
static struct __attrdef RocsWgen_tdaddr = {
  "tdaddr",  "TD address",  "",  "int",  "0",  "0-*",  False,
};
static int _gettdaddr(iONode node) {
  int defval = xInt( RocsWgen_tdaddr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "tdaddr", defval );
}
static void _settdaddr(iONode node, int p_tdaddr) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "tdaddr", p_tdaddr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * tdiid
 */
static struct __attrdef RocsWgen_tdiid = {
  "tdiid",  "TD interface id",  "",  "string",  "NULL",  "*",  False,
};
static const char* _gettdiid(iONode node) {
  const char* defval = xStr( RocsWgen_tdiid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "tdiid", defval );
}
static void _settdiid(iONode node, const char* p_tdiid) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "tdiid", p_tdiid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * tdport
 */
static struct __attrdef RocsWgen_tdport = {
  "tdport",  "TD output port",  "",  "int",  "0",  "0-*",  False,
};
static int _gettdport(iONode node) {
  int defval = xInt( RocsWgen_tdport );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "tdport", defval );
}
static void _settdport(iONode node, int p_tdport) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "tdport", p_tdport );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * testing
 */
static struct __attrdef RocsWgen_testing = {
  "testing",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _istesting(iONode node) {
  Boolean defval = xBool( RocsWgen_testing );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "testing", defval );
}
static void _settesting(iONode node, Boolean p_testing) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "testing", p_testing );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * type
 */
static struct __attrdef RocsWgen_type = {
  "type",  "",  "",  "string",  "right",  "right,left,turnout,crossing,ccrossing,dcrossing,threeway,decoupler",  False,
};
static const char* _gettype(iONode node) {
  const char* defval = xStr( RocsWgen_type );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "type", defval );
}
static void _settype(iONode node, const char* p_type) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "type", p_type );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * value1
 */
static struct __attrdef RocsWgen_value1 = {
  "value1",  "value",  "",  "int",  "1",  "0-*",  False,
};
static int _getvalue1(iONode node) {
  int defval = xInt( RocsWgen_value1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "value1", defval );
}
static void _setvalue1(iONode node, int p_value1) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "value1", p_value1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * value2
 */
static struct __attrdef RocsWgen_value2 = {
  "value2",  "value",  "",  "int",  "1",  "0-*",  False,
};
static int _getvalue2(iONode node) {
  int defval = xInt( RocsWgen_value2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "value2", defval );
}
static void _setvalue2(iONode node, int p_value2) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "value2", p_value2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * virtual
 */
static struct __attrdef RocsWgen_virtual = {
  "virtual",  "If this object is only used for dispatching commands.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isvirtual(iONode node) {
  Boolean defval = xBool( RocsWgen_virtual );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getBool( node, "virtual", defval );
}
static void _setvirtual(iONode node, Boolean p_virtual) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setBool( node, "virtual", p_virtual );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * wantedstate
 */
static struct __attrdef RocsWgen_wantedstate = {
  "wantedstate",  "Wanted state of switch.",  "",  "string",  "NULL",  "straight,turnout,red,green,left,right",  False,
};
static const char* _getwantedstate(iONode node) {
  const char* defval = xStr( RocsWgen_wantedstate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_sw, node );
  return NodeOp.getStr( node, "wantedstate", defval );
}
static void _setwantedstate(iONode node, const char* p_wantedstate) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setStr( node, "wantedstate", p_wantedstate );
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
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "x", defval );
}
static void _setx(iONode node, int p_x) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
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
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "y", defval );
}
static void _sety(iONode node, int p_y) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
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
  xNode( RocsWgen_sw, node );
  return NodeOp.getInt( node, "z", defval );
}
static void _setz(iONode node, int p_z) {
  if( node == NULL ) return;
  xNode( RocsWgen_sw, node );
  NodeOp.setInt( node, "z", p_z );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * actionctrl
 */
static struct __nodedef RocsWgen_actionctrl = {
  "actionctrl",  "",  False,  "n",};
static iONode _getactionctrl(iONode node) {
  xNode( RocsWgen_sw, node );
  return NodeOp.findNode( node, "actionctrl");
}


static iONode _nextactionctrl(iONode node, iONode child) {
  xNode( RocsWgen_sw, node );
  return NodeOp.findNextNode( node, child);
}
static void _setactionctrl(iONode node, iONode p_actionctrl) {
  xNode( RocsWgen_sw, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * accessoryctrl
 */
static struct __nodedef RocsWgen_accessoryctrl = {
  "accessoryctrl",  "",  False,  "1",};
static iONode _getaccessoryctrl(iONode node) {
  xNode( RocsWgen_sw, node );
  return NodeOp.findNode( node, "accessoryctrl");
}


static iONode _nextaccessoryctrl(iONode node, iONode child) {
  xNode( RocsWgen_sw, node );
  return NodeOp.findNextNode( node, child);
}
static void _setaccessoryctrl(iONode node, iONode p_accessoryctrl) {
  xNode( RocsWgen_sw, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[114] = {NULL};
static struct __nodedef* nodeList[3] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_sw.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node sw not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node sw not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_accessory;
  attrList[1] = &RocsWgen_accnr;
  attrList[2] = &RocsWgen_actdelay;
  attrList[3] = &RocsWgen_activate;
  attrList[4] = &RocsWgen_addr0pol1;
  attrList[5] = &RocsWgen_addr0pol2;
  attrList[6] = &RocsWgen_addr1;
  attrList[7] = &RocsWgen_addr1pol1;
  attrList[8] = &RocsWgen_addr1pol2;
  attrList[9] = &RocsWgen_addr2;
  attrList[10] = &RocsWgen_blockid;
  attrList[11] = &RocsWgen_bus;
  attrList[12] = &RocsWgen_buspol;
  attrList[13] = &RocsWgen_cmd;
  attrList[14] = &RocsWgen_cmd_extra;
  attrList[15] = &RocsWgen_cmd_lcid;
  attrList[16] = &RocsWgen_cmd_update;
  attrList[17] = &RocsWgen_ctcaddr1;
  attrList[18] = &RocsWgen_ctcaddr2;
  attrList[19] = &RocsWgen_ctcaddrled1;
  attrList[20] = &RocsWgen_ctcaddrled2;
  attrList[21] = &RocsWgen_ctcasswitchled1;
  attrList[22] = &RocsWgen_ctcasswitchled2;
  attrList[23] = &RocsWgen_ctcbus1;
  attrList[24] = &RocsWgen_ctcbus2;
  attrList[25] = &RocsWgen_ctcbusled1;
  attrList[26] = &RocsWgen_ctcbusled2;
  attrList[27] = &RocsWgen_ctccmdon1;
  attrList[28] = &RocsWgen_ctccmdon2;
  attrList[29] = &RocsWgen_ctcflip1;
  attrList[30] = &RocsWgen_ctcflip2;
  attrList[31] = &RocsWgen_ctcgateled1;
  attrList[32] = &RocsWgen_ctcgateled2;
  attrList[33] = &RocsWgen_ctciid1;
  attrList[34] = &RocsWgen_ctciid2;
  attrList[35] = &RocsWgen_ctciidled1;
  attrList[36] = &RocsWgen_ctciidled2;
  attrList[37] = &RocsWgen_ctcportled1;
  attrList[38] = &RocsWgen_ctcportled2;
  attrList[39] = &RocsWgen_delay;
  attrList[40] = &RocsWgen_delaytime;
  attrList[41] = &RocsWgen_desc;
  attrList[42] = &RocsWgen_dir;
  attrList[43] = &RocsWgen_fb2G;
  attrList[44] = &RocsWgen_fb2Ginv;
  attrList[45] = &RocsWgen_fb2R;
  attrList[46] = &RocsWgen_fb2Rinv;
  attrList[47] = &RocsWgen_fbG;
  attrList[48] = &RocsWgen_fbGinv;
  attrList[49] = &RocsWgen_fbOcc;
  attrList[50] = &RocsWgen_fbOcc2;
  attrList[51] = &RocsWgen_fbR;
  attrList[52] = &RocsWgen_fbRinv;
  attrList[53] = &RocsWgen_fbset;
  attrList[54] = &RocsWgen_fbusefield;
  attrList[55] = &RocsWgen_fieldstate;
  attrList[56] = &RocsWgen_forcecmd;
  attrList[57] = &RocsWgen_frogaccessory;
  attrList[58] = &RocsWgen_frogiid;
  attrList[59] = &RocsWgen_frogporttype;
  attrList[60] = &RocsWgen_frogswitch;
  attrList[61] = &RocsWgen_frogtimer;
  attrList[62] = &RocsWgen_gate0pol1;
  attrList[63] = &RocsWgen_gate0pol2;
  attrList[64] = &RocsWgen_gate1;
  attrList[65] = &RocsWgen_gate1pol1;
  attrList[66] = &RocsWgen_gate1pol2;
  attrList[67] = &RocsWgen_gate2;
  attrList[68] = &RocsWgen_gatevalue;
  attrList[69] = &RocsWgen_id;
  attrList[70] = &RocsWgen_iid;
  attrList[71] = &RocsWgen_initfield;
  attrList[72] = &RocsWgen_inv;
  attrList[73] = &RocsWgen_inv2;
  attrList[74] = &RocsWgen_locid;
  attrList[75] = &RocsWgen_manualcmd;
  attrList[76] = &RocsWgen_oid;
  attrList[77] = &RocsWgen_ori;
  attrList[78] = &RocsWgen_param1;
  attrList[79] = &RocsWgen_param2;
  attrList[80] = &RocsWgen_pause;
  attrList[81] = &RocsWgen_port0pol1;
  attrList[82] = &RocsWgen_port0pol2;
  attrList[83] = &RocsWgen_port1;
  attrList[84] = &RocsWgen_port1pol1;
  attrList[85] = &RocsWgen_port1pol2;
  attrList[86] = &RocsWgen_port2;
  attrList[87] = &RocsWgen_porttype;
  attrList[88] = &RocsWgen_prot;
  attrList[89] = &RocsWgen_rectcrossing;
  attrList[90] = &RocsWgen_savepos;
  attrList[91] = &RocsWgen_set;
  attrList[92] = &RocsWgen_show;
  attrList[93] = &RocsWgen_singlegate;
  attrList[94] = &RocsWgen_state;
  attrList[95] = &RocsWgen_subtype;
  attrList[96] = &RocsWgen_swapstraight;
  attrList[97] = &RocsWgen_switched;
  attrList[98] = &RocsWgen_swtype;
  attrList[99] = &RocsWgen_syncdelay;
  attrList[100] = &RocsWgen_td;
  attrList[101] = &RocsWgen_tdaddr;
  attrList[102] = &RocsWgen_tdiid;
  attrList[103] = &RocsWgen_tdport;
  attrList[104] = &RocsWgen_testing;
  attrList[105] = &RocsWgen_type;
  attrList[106] = &RocsWgen_value1;
  attrList[107] = &RocsWgen_value2;
  attrList[108] = &RocsWgen_virtual;
  attrList[109] = &RocsWgen_wantedstate;
  attrList[110] = &RocsWgen_x;
  attrList[111] = &RocsWgen_y;
  attrList[112] = &RocsWgen_z;
  attrList[113] = NULL;
  nodeList[0] = &RocsWgen_actionctrl;
  nodeList[1] = &RocsWgen_accessoryctrl;
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


struct __wSwitch wSwitch = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "accessory",
  "ccrossing",
  "crossing",
  "dcrossing",
  "decoupler",
  "flip",
  "left",
  "none",
  "D",
  "do",
  "M",
  "mdd",
  "N",
  "oc32",
  "om32",
  "vo",
  "right",
  "straight",
  "subleft",
  "subright",
  "default",
  "raster",
  "testoff",
  "teston",
  "threeway",
  "turnout",
  "twoway",
  "unlock",
  "-unlocked-",
  _isaccessory,
  _setaccessory,
  _getaccnr,
  _setaccnr,
  _isactdelay,
  _setactdelay,
  _isactivate,
  _setactivate,
  _getaddr0pol1,
  _setaddr0pol1,
  _getaddr0pol2,
  _setaddr0pol2,
  _getaddr1,
  _setaddr1,
  _getaddr1pol1,
  _setaddr1pol1,
  _getaddr1pol2,
  _setaddr1pol2,
  _getaddr2,
  _setaddr2,
  _getblockid,
  _setblockid,
  _getbus,
  _setbus,
  _getbuspol,
  _setbuspol,
  _getcmd,
  _setcmd,
  _getcmd_extra,
  _setcmd_extra,
  _getcmd_lcid,
  _setcmd_lcid,
  _iscmd_update,
  _setcmd_update,
  _getctcaddr1,
  _setctcaddr1,
  _getctcaddr2,
  _setctcaddr2,
  _getctcaddrled1,
  _setctcaddrled1,
  _getctcaddrled2,
  _setctcaddrled2,
  _isctcasswitchled1,
  _setctcasswitchled1,
  _isctcasswitchled2,
  _setctcasswitchled2,
  _getctcbus1,
  _setctcbus1,
  _getctcbus2,
  _setctcbus2,
  _getctcbusled1,
  _setctcbusled1,
  _getctcbusled2,
  _setctcbusled2,
  _isctccmdon1,
  _setctccmdon1,
  _isctccmdon2,
  _setctccmdon2,
  _isctcflip1,
  _setctcflip1,
  _isctcflip2,
  _setctcflip2,
  _getctcgateled1,
  _setctcgateled1,
  _getctcgateled2,
  _setctcgateled2,
  _getctciid1,
  _setctciid1,
  _getctciid2,
  _setctciid2,
  _getctciidled1,
  _setctciidled1,
  _getctciidled2,
  _setctciidled2,
  _getctcportled1,
  _setctcportled1,
  _getctcportled2,
  _setctcportled2,
  _getdelay,
  _setdelay,
  _getdelaytime,
  _setdelaytime,
  _getdesc,
  _setdesc,
  _isdir,
  _setdir,
  _getfb2G,
  _setfb2G,
  _isfb2Ginv,
  _setfb2Ginv,
  _getfb2R,
  _setfb2R,
  _isfb2Rinv,
  _setfb2Rinv,
  _getfbG,
  _setfbG,
  _isfbGinv,
  _setfbGinv,
  _getfbOcc,
  _setfbOcc,
  _getfbOcc2,
  _setfbOcc2,
  _getfbR,
  _setfbR,
  _isfbRinv,
  _setfbRinv,
  _isfbset,
  _setfbset,
  _isfbusefield,
  _setfbusefield,
  _getfieldstate,
  _setfieldstate,
  _isforcecmd,
  _setforcecmd,
  _isfrogaccessory,
  _setfrogaccessory,
  _getfrogiid,
  _setfrogiid,
  _getfrogporttype,
  _setfrogporttype,
  _isfrogswitch,
  _setfrogswitch,
  _getfrogtimer,
  _setfrogtimer,
  _getgate0pol1,
  _setgate0pol1,
  _getgate0pol2,
  _setgate0pol2,
  _getgate1,
  _setgate1,
  _getgate1pol1,
  _setgate1pol1,
  _getgate1pol2,
  _setgate1pol2,
  _getgate2,
  _setgate2,
  _getgatevalue,
  _setgatevalue,
  _getid,
  _setid,
  _getiid,
  _setiid,
  _isinitfield,
  _setinitfield,
  _isinv,
  _setinv,
  _isinv2,
  _setinv2,
  _getlocid,
  _setlocid,
  _ismanualcmd,
  _setmanualcmd,
  _getoid,
  _setoid,
  _getori,
  _setori,
  _getparam1,
  _setparam1,
  _getparam2,
  _setparam2,
  _getpause,
  _setpause,
  _getport0pol1,
  _setport0pol1,
  _getport0pol2,
  _setport0pol2,
  _getport1,
  _setport1,
  _getport1pol1,
  _setport1pol1,
  _getport1pol2,
  _setport1pol2,
  _getport2,
  _setport2,
  _getporttype,
  _setporttype,
  _getprot,
  _setprot,
  _isrectcrossing,
  _setrectcrossing,
  _getsavepos,
  _setsavepos,
  _isset,
  _setset,
  _isshow,
  _setshow,
  _issinglegate,
  _setsinglegate,
  _getstate,
  _setstate,
  _getsubtype,
  _setsubtype,
  _isswapstraight,
  _setswapstraight,
  _getswitched,
  _setswitched,
  _getswtype,
  _setswtype,
  _issyncdelay,
  _setsyncdelay,
  _istd,
  _settd,
  _gettdaddr,
  _settdaddr,
  _gettdiid,
  _settdiid,
  _gettdport,
  _settdport,
  _istesting,
  _settesting,
  _gettype,
  _settype,
  _getvalue1,
  _setvalue1,
  _getvalue2,
  _setvalue2,
  _isvirtual,
  _setvirtual,
  _getwantedstate,
  _setwantedstate,
  _getx,
  _setx,
  _gety,
  _sety,
  _getz,
  _setz,
  _getactionctrl,
  _nextactionctrl,
  _setactionctrl,
  _getaccessoryctrl,
  _nextaccessoryctrl,
  _setaccessoryctrl,
  _node_dump,
};
