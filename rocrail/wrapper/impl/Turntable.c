/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/Turntable.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Turntable
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_tt = {
  "tt",  "Turntable definition.",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_tt.name;
}
static const char* _node_remark(void) {
  return RocsWgen_tt.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_tt.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_tt.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * V
 */
static struct __attrdef RocsWgen_V = {
  "V",  "Rotation speed in percent.",  "",  "int",  "75",  "10-100",  True,
};
static int _getV(iONode node) {
  int defval = xInt( RocsWgen_V );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "V", defval );
}
static void _setV(iONode node, int p_V) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "V", p_V );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * actfn
 */
static struct __attrdef RocsWgen_actfn = {
  "actfn",  "Activation function for locdec type turntable drives.",  "",  "int",  "0",  "0-28",  False,
};
static int _getactfn(iONode node) {
  int defval = xInt( RocsWgen_actfn );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "actfn", defval );
}
static void _setactfn(iONode node, int p_actfn) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "actfn", p_actfn );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr
 */
static struct __attrdef RocsWgen_addr = {
  "addr",  "Turntable address.",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr(iONode node) {
  int defval = xInt( RocsWgen_addr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "addr", defval );
}
static void _setaddr(iONode node, int p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "addr", p_addr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr0
 */
static struct __attrdef RocsWgen_addr0 = {
  "addr0",  "bit 0 of track",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr0(iONode node) {
  int defval = xInt( RocsWgen_addr0 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "addr0", defval );
}
static void _setaddr0(iONode node, int p_addr0) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "addr0", p_addr0 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr1
 */
static struct __attrdef RocsWgen_addr1 = {
  "addr1",  "bit 1 of track",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr1(iONode node) {
  int defval = xInt( RocsWgen_addr1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "addr1", defval );
}
static void _setaddr1(iONode node, int p_addr1) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "addr1", p_addr1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr2
 */
static struct __attrdef RocsWgen_addr2 = {
  "addr2",  "bit 2 of track",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr2(iONode node) {
  int defval = xInt( RocsWgen_addr2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "addr2", defval );
}
static void _setaddr2(iONode node, int p_addr2) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "addr2", p_addr2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr3
 */
static struct __attrdef RocsWgen_addr3 = {
  "addr3",  "bit 3 of track",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr3(iONode node) {
  int defval = xInt( RocsWgen_addr3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "addr3", defval );
}
static void _setaddr3(iONode node, int p_addr3) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "addr3", p_addr3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr4
 */
static struct __attrdef RocsWgen_addr4 = {
  "addr4",  "bit 4 of track",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr4(iONode node) {
  int defval = xInt( RocsWgen_addr4 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "addr4", defval );
}
static void _setaddr4(iONode node, int p_addr4) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "addr4", p_addr4 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr5
 */
static struct __attrdef RocsWgen_addr5 = {
  "addr5",  "new position set flag address",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr5(iONode node) {
  int defval = xInt( RocsWgen_addr5 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "addr5", defval );
}
static void _setaddr5(iONode node, int p_addr5) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "addr5", p_addr5 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr6
 */
static struct __attrdef RocsWgen_addr6 = {
  "addr6",  "bit 5 of track",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr6(iONode node) {
  int defval = xInt( RocsWgen_addr6 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "addr6", defval );
}
static void _setaddr6(iONode node, int p_addr6) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "addr6", p_addr6 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * b0sen
 */
static struct __attrdef RocsWgen_b0sen = {
  "b0sen",  "ID bit 0 of position",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getb0sen(iONode node) {
  const char* defval = xStr( RocsWgen_b0sen );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getStr( node, "b0sen", defval );
}
static void _setb0sen(iONode node, const char* p_b0sen) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setStr( node, "b0sen", p_b0sen );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * b1sen
 */
static struct __attrdef RocsWgen_b1sen = {
  "b1sen",  "ID bit 1 of position",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getb1sen(iONode node) {
  const char* defval = xStr( RocsWgen_b1sen );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getStr( node, "b1sen", defval );
}
static void _setb1sen(iONode node, const char* p_b1sen) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setStr( node, "b1sen", p_b1sen );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * b2sen
 */
static struct __attrdef RocsWgen_b2sen = {
  "b2sen",  "ID bit 2 of position",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getb2sen(iONode node) {
  const char* defval = xStr( RocsWgen_b2sen );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getStr( node, "b2sen", defval );
}
static void _setb2sen(iONode node, const char* p_b2sen) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setStr( node, "b2sen", p_b2sen );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * b3sen
 */
static struct __attrdef RocsWgen_b3sen = {
  "b3sen",  "ID bit 3 of position",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getb3sen(iONode node) {
  const char* defval = xStr( RocsWgen_b3sen );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getStr( node, "b3sen", defval );
}
static void _setb3sen(iONode node, const char* p_b3sen) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setStr( node, "b3sen", p_b3sen );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bit0cmd
 */
static struct __attrdef RocsWgen_bit0cmd = {
  "bit0cmd",  "",  "",  "int",  "0",  "0,1",  False,
};
static int _getbit0cmd(iONode node) {
  int defval = xInt( RocsWgen_bit0cmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "bit0cmd", defval );
}
static void _setbit0cmd(iONode node, int p_bit0cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "bit0cmd", p_bit0cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bit1cmd
 */
static struct __attrdef RocsWgen_bit1cmd = {
  "bit1cmd",  "",  "",  "int",  "0",  "0,1",  False,
};
static int _getbit1cmd(iONode node) {
  int defval = xInt( RocsWgen_bit1cmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "bit1cmd", defval );
}
static void _setbit1cmd(iONode node, int p_bit1cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "bit1cmd", p_bit1cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bit2cmd
 */
static struct __attrdef RocsWgen_bit2cmd = {
  "bit2cmd",  "",  "",  "int",  "0",  "0,1",  False,
};
static int _getbit2cmd(iONode node) {
  int defval = xInt( RocsWgen_bit2cmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "bit2cmd", defval );
}
static void _setbit2cmd(iONode node, int p_bit2cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "bit2cmd", p_bit2cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bit3cmd
 */
static struct __attrdef RocsWgen_bit3cmd = {
  "bit3cmd",  "",  "",  "int",  "0",  "0,1",  False,
};
static int _getbit3cmd(iONode node) {
  int defval = xInt( RocsWgen_bit3cmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "bit3cmd", defval );
}
static void _setbit3cmd(iONode node, int p_bit3cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "bit3cmd", p_bit3cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bit4cmd
 */
static struct __attrdef RocsWgen_bit4cmd = {
  "bit4cmd",  "",  "",  "int",  "0",  "0,1",  False,
};
static int _getbit4cmd(iONode node) {
  int defval = xInt( RocsWgen_bit4cmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "bit4cmd", defval );
}
static void _setbit4cmd(iONode node, int p_bit4cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "bit4cmd", p_bit4cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bit5cmd
 */
static struct __attrdef RocsWgen_bit5cmd = {
  "bit5cmd",  "",  "",  "int",  "0",  "0,1",  False,
};
static int _getbit5cmd(iONode node) {
  int defval = xInt( RocsWgen_bit5cmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "bit5cmd", defval );
}
static void _setbit5cmd(iONode node, int p_bit5cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "bit5cmd", p_bit5cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bridgepos
 */
static struct __attrdef RocsWgen_bridgepos = {
  "bridgepos",  "",  "",  "int",  "0",  "0-47",  False,
};
static int _getbridgepos(iONode node) {
  int defval = xInt( RocsWgen_bridgepos );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "bridgepos", defval );
}
static void _setbridgepos(iONode node, int p_bridgepos) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "bridgepos", p_bridgepos );
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
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "bus", defval );
}
static void _setbus(iONode node, int p_bus) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
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
  xNode( RocsWgen_tt, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setStr( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmdbyroute
 */
static struct __attrdef RocsWgen_cmdbyroute = {
  "cmdbyroute",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _iscmdbyroute(iONode node) {
  Boolean defval = xBool( RocsWgen_cmdbyroute );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getBool( node, "cmdbyroute", defval );
}
static void _setcmdbyroute(iONode node, Boolean p_cmdbyroute) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setBool( node, "cmdbyroute", p_cmdbyroute );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * delay
 */
static struct __attrdef RocsWgen_delay = {
  "delay",  "",  "s",  "int",  "0",  "0-*",  False,
};
static int _getdelay(iONode node) {
  int defval = xInt( RocsWgen_delay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "delay", defval );
}
static void _setdelay(iONode node, int p_delay) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
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
  xNode( RocsWgen_tt, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * diraddr
 */
static struct __attrdef RocsWgen_diraddr = {
  "diraddr",  "Direction address.",  "",  "int",  "0",  "0-*",  True,
};
static int _getdiraddr(iONode node) {
  int defval = xInt( RocsWgen_diraddr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "diraddr", defval );
}
static void _setdiraddr(iONode node, int p_diraddr) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "diraddr", p_diraddr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * embeddedblock
 */
static struct __attrdef RocsWgen_embeddedblock = {
  "embeddedblock",  "TT is block.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isembeddedblock(iONode node) {
  Boolean defval = xBool( RocsWgen_embeddedblock );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getBool( node, "embeddedblock", defval );
}
static void _setembeddedblock(iONode node, Boolean p_embeddedblock) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setBool( node, "embeddedblock", p_embeddedblock );
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
  xNode( RocsWgen_tt, node );
  return NodeOp.getBool( node, "entering", defval );
}
static void _setentering(iONode node, Boolean p_entering) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setBool( node, "entering", p_entering );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fun
 */
static struct __attrdef RocsWgen_fun = {
  "fun",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getfun(iONode node) {
  int defval = xInt( RocsWgen_fun );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "fun", defval );
}
static void _setfun(iONode node, int p_fun) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "fun", p_fun );
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
  xNode( RocsWgen_tt, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setStr( node, "id", p_id );
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
  xNode( RocsWgen_tt, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * inv
 */
static struct __attrdef RocsWgen_inv = {
  "inv",  "invert the commands",  "",  "bool",  "false",  "",  False,
};
static Boolean _isinv(iONode node) {
  Boolean defval = xBool( RocsWgen_inv );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getBool( node, "inv", defval );
}
static void _setinv(iONode node, Boolean p_inv) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setBool( node, "inv", p_inv );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * invnew
 */
static struct __attrdef RocsWgen_invnew = {
  "invnew",  "invert position set flag command",  "",  "bool",  "false",  "",  False,
};
static Boolean _isinvnew(iONode node) {
  Boolean defval = xBool( RocsWgen_invnew );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getBool( node, "invnew", defval );
}
static void _setinvnew(iONode node, Boolean p_invnew) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setBool( node, "invnew", p_invnew );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * invpos
 */
static struct __attrdef RocsWgen_invpos = {
  "invpos",  "invert position commands",  "",  "bool",  "false",  "",  False,
};
static Boolean _isinvpos(iONode node) {
  Boolean defval = xBool( RocsWgen_invpos );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getBool( node, "invpos", defval );
}
static void _setinvpos(iONode node, Boolean p_invpos) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setBool( node, "invpos", p_invpos );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lightsfn
 */
static struct __attrdef RocsWgen_lightsfn = {
  "lightsfn",  "",  "",  "int",  "1",  "0-28",  False,
};
static int _getlightsfn(iONode node) {
  int defval = xInt( RocsWgen_lightsfn );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "lightsfn", defval );
}
static void _setlightsfn(iONode node, int p_lightsfn) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "lightsfn", p_lightsfn );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * locid
 */
static struct __attrdef RocsWgen_locid = {
  "locid",  "The loc who locked this turntable.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getlocid(iONode node) {
  const char* defval = xStr( RocsWgen_locid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getStr( node, "locid", defval );
}
static void _setlocid(iONode node, const char* p_locid) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setStr( node, "locid", p_locid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * manager
 */
static struct __attrdef RocsWgen_manager = {
  "manager",  "Manager mode: Act like a block and manage all sub blocks.(Tracks)",  "",  "bool",  "false",  "",  False,
};
static Boolean _ismanager(iONode node) {
  Boolean defval = xBool( RocsWgen_manager );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getBool( node, "manager", defval );
}
static void _setmanager(iONode node, Boolean p_manager) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setBool( node, "manager", p_manager );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * motoroffdelay
 */
static struct __attrdef RocsWgen_motoroffdelay = {
  "motoroffdelay",  "shut off delay for locdec motor",  "",  "int",  "1000",  "0-*",  False,
};
static int _getmotoroffdelay(iONode node) {
  int defval = xInt( RocsWgen_motoroffdelay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "motoroffdelay", defval );
}
static void _setmotoroffdelay(iONode node, int p_motoroffdelay) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "motoroffdelay", p_motoroffdelay );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * move4opp
 */
static struct __attrdef RocsWgen_move4opp = {
  "move4opp",  "Move bridge if the target track is opposite of the current position.",  "",  "bool",  "true",  "",  False,
};
static Boolean _ismove4opp(iONode node) {
  Boolean defval = xBool( RocsWgen_move4opp );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getBool( node, "move4opp", defval );
}
static void _setmove4opp(iONode node, Boolean p_move4opp) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setBool( node, "move4opp", p_move4opp );
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
  xNode( RocsWgen_tt, node );
  return NodeOp.getStr( node, "oid", defval );
}
static void _setoid(iONode node, const char* p_oid) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setStr( node, "oid", p_oid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * pause
 */
static struct __attrdef RocsWgen_pause = {
  "pause",  "pause between direction and position command",  "s",  "int",  "0",  "0-*",  False,
};
static int _getpause(iONode node) {
  int defval = xInt( RocsWgen_pause );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "pause", defval );
}
static void _setpause(iONode node, int p_pause) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "pause", p_pause );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * poladdr
 */
static struct __attrdef RocsWgen_poladdr = {
  "poladdr",  "Polarization relay address.",  "",  "int",  "0",  "0-*",  False,
};
static int _getpoladdr(iONode node) {
  int defval = xInt( RocsWgen_poladdr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "poladdr", defval );
}
static void _setpoladdr(iONode node, int p_poladdr) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "poladdr", p_poladdr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port0
 */
static struct __attrdef RocsWgen_port0 = {
  "port0",  "bit 0 of track",  "",  "int",  "0",  "0-4",  True,
};
static int _getport0(iONode node) {
  int defval = xInt( RocsWgen_port0 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "port0", defval );
}
static void _setport0(iONode node, int p_port0) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "port0", p_port0 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port1
 */
static struct __attrdef RocsWgen_port1 = {
  "port1",  "bit 1 of track",  "",  "int",  "0",  "0-4",  True,
};
static int _getport1(iONode node) {
  int defval = xInt( RocsWgen_port1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "port1", defval );
}
static void _setport1(iONode node, int p_port1) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "port1", p_port1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port2
 */
static struct __attrdef RocsWgen_port2 = {
  "port2",  "bit 2 of track",  "",  "int",  "0",  "0-4",  True,
};
static int _getport2(iONode node) {
  int defval = xInt( RocsWgen_port2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "port2", defval );
}
static void _setport2(iONode node, int p_port2) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "port2", p_port2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port3
 */
static struct __attrdef RocsWgen_port3 = {
  "port3",  "bit 3 of track",  "",  "int",  "0",  "0-4",  True,
};
static int _getport3(iONode node) {
  int defval = xInt( RocsWgen_port3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "port3", defval );
}
static void _setport3(iONode node, int p_port3) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "port3", p_port3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port4
 */
static struct __attrdef RocsWgen_port4 = {
  "port4",  "bit 4 of track",  "",  "int",  "0",  "0-4",  True,
};
static int _getport4(iONode node) {
  int defval = xInt( RocsWgen_port4 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "port4", defval );
}
static void _setport4(iONode node, int p_port4) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "port4", p_port4 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port5
 */
static struct __attrdef RocsWgen_port5 = {
  "port5",  "new position set flag port",  "",  "int",  "0",  "0-4",  True,
};
static int _getport5(iONode node) {
  int defval = xInt( RocsWgen_port5 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "port5", defval );
}
static void _setport5(iONode node, int p_port5) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "port5", p_port5 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port6
 */
static struct __attrdef RocsWgen_port6 = {
  "port6",  "bit 5 of track",  "",  "int",  "0",  "0-4",  True,
};
static int _getport6(iONode node) {
  int defval = xInt( RocsWgen_port6 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "port6", defval );
}
static void _setport6(iONode node, int p_port6) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "port6", p_port6 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * prot
 */
static struct __attrdef RocsWgen_prot = {
  "prot",  "Protocol to use.",  "",  "string",  "D",  "D,M,N",  False,
};
static const char* _getprot(iONode node) {
  const char* defval = xStr( RocsWgen_prot );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getStr( node, "prot", defval );
}
static void _setprot(iONode node, const char* p_prot) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setStr( node, "prot", p_prot );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * psen
 */
static struct __attrdef RocsWgen_psen = {
  "psen",  "ID of the position ready sensor",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getpsen(iONode node) {
  const char* defval = xStr( RocsWgen_psen );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getStr( node, "psen", defval );
}
static void _setpsen(iONode node, const char* p_psen) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setStr( node, "psen", p_psen );
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
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "randomrate", defval );
}
static void _setrandomrate(iONode node, int p_randomrate) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "randomrate", p_randomrate );
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
  xNode( RocsWgen_tt, node );
  return NodeOp.getBool( node, "reserved", defval );
}
static void _setreserved(iONode node, Boolean p_reserved) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setBool( node, "reserved", p_reserved );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * resetaddr
 */
static struct __attrdef RocsWgen_resetaddr = {
  "resetaddr",  "Reset bit address",  "",  "int",  "0",  "0-*",  True,
};
static int _getresetaddr(iONode node) {
  int defval = xInt( RocsWgen_resetaddr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "resetaddr", defval );
}
static void _setresetaddr(iONode node, int p_resetaddr) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "resetaddr", p_resetaddr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * resetbitcmd
 */
static struct __attrdef RocsWgen_resetbitcmd = {
  "resetbitcmd",  "",  "",  "int",  "0",  "0,1",  False,
};
static int _getresetbitcmd(iONode node) {
  int defval = xInt( RocsWgen_resetbitcmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "resetbitcmd", defval );
}
static void _setresetbitcmd(iONode node, int p_resetbitcmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "resetbitcmd", p_resetbitcmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * resetport
 */
static struct __attrdef RocsWgen_resetport = {
  "resetport",  "Reset bit port",  "",  "int",  "0",  "0-4",  True,
};
static int _getresetport(iONode node) {
  int defval = xInt( RocsWgen_resetport );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "resetport", defval );
}
static void _setresetport(iONode node, int p_resetport) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "resetport", p_resetport );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * s1
 */
static struct __attrdef RocsWgen_s1 = {
  "s1",  "Feedback ID for detection occupancy on the bridge.",  "",  "string",  "",  "*",  True,
};
static const char* _gets1(iONode node) {
  const char* defval = xStr( RocsWgen_s1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getStr( node, "s1", defval );
}
static void _sets1(iONode node, const char* p_s1) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setStr( node, "s1", p_s1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * s2
 */
static struct __attrdef RocsWgen_s2 = {
  "s2",  "Feedback ID for detection occupancy on the bridge.",  "",  "string",  "",  "*",  True,
};
static const char* _gets2(iONode node) {
  const char* defval = xStr( RocsWgen_s2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getStr( node, "s2", defval );
}
static void _sets2(iONode node, const char* p_s2) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setStr( node, "s2", p_s2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sMid
 */
static struct __attrdef RocsWgen_sMid = {
  "sMid",  "Feedback ID for detection occupancy on the bridge.",  "",  "string",  "",  "*",  True,
};
static const char* _getsMid(iONode node) {
  const char* defval = xStr( RocsWgen_sMid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getStr( node, "sMid", defval );
}
static void _setsMid(iONode node, const char* p_sMid) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setStr( node, "sMid", p_sMid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sMid2
 */
static struct __attrdef RocsWgen_sMid2 = {
  "sMid2",  "Feedback ID for detection occupancy on the bridge.",  "",  "string",  "",  "*",  True,
};
static const char* _getsMid2(iONode node) {
  const char* defval = xStr( RocsWgen_sMid2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getStr( node, "sMid2", defval );
}
static void _setsMid2(iONode node, const char* p_sMid2) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setStr( node, "sMid2", p_sMid2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * singlegatenew
 */
static struct __attrdef RocsWgen_singlegatenew = {
  "singlegatenew",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _issinglegatenew(iONode node) {
  Boolean defval = xBool( RocsWgen_singlegatenew );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getBool( node, "singlegatenew", defval );
}
static void _setsinglegatenew(iONode node, Boolean p_singlegatenew) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setBool( node, "singlegatenew", p_singlegatenew );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * singlegatepos
 */
static struct __attrdef RocsWgen_singlegatepos = {
  "singlegatepos",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _issinglegatepos(iONode node) {
  Boolean defval = xBool( RocsWgen_singlegatepos );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getBool( node, "singlegatepos", defval );
}
static void _setsinglegatepos(iONode node, Boolean p_singlegatepos) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setBool( node, "singlegatepos", p_singlegatepos );
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
  xNode( RocsWgen_tt, node );
  return NodeOp.getStr( node, "state", defval );
}
static void _setstate(iONode node, const char* p_state) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setStr( node, "state", p_state );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * state1
 */
static struct __attrdef RocsWgen_state1 = {
  "state1",  "Feedback state bridge sensor1.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isstate1(iONode node) {
  Boolean defval = xBool( RocsWgen_state1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getBool( node, "state1", defval );
}
static void _setstate1(iONode node, Boolean p_state1) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setBool( node, "state1", p_state1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * state2
 */
static struct __attrdef RocsWgen_state2 = {
  "state2",  "Feedback state bridge sensor2.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isstate2(iONode node) {
  Boolean defval = xBool( RocsWgen_state2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getBool( node, "state2", defval );
}
static void _setstate2(iONode node, Boolean p_state2) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setBool( node, "state2", p_state2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * stateMid
 */
static struct __attrdef RocsWgen_stateMid = {
  "stateMid",  "Feedback state bridge sensor3.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isstateMid(iONode node) {
  Boolean defval = xBool( RocsWgen_stateMid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getBool( node, "stateMid", defval );
}
static void _setstateMid(iONode node, Boolean p_stateMid) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setBool( node, "stateMid", p_stateMid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * stateMid2
 */
static struct __attrdef RocsWgen_stateMid2 = {
  "stateMid2",  "Feedback state bridge sensor4.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isstateMid2(iONode node) {
  Boolean defval = xBool( RocsWgen_stateMid2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getBool( node, "stateMid2", defval );
}
static void _setstateMid2(iONode node, Boolean p_stateMid2) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setBool( node, "stateMid2", p_stateMid2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * swaprotation
 */
static struct __attrdef RocsWgen_swaprotation = {
  "swaprotation",  "swap bridge rotation direction",  "",  "bool",  "false",  "",  False,
};
static Boolean _isswaprotation(iONode node) {
  Boolean defval = xBool( RocsWgen_swaprotation );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getBool( node, "swaprotation", defval );
}
static void _setswaprotation(iONode node, Boolean p_swaprotation) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setBool( node, "swaprotation", p_swaprotation );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * swcmd
 */
static struct __attrdef RocsWgen_swcmd = {
  "swcmd",  "use switch instead of output commands",  "",  "bool",  "false",  "",  False,
};
static Boolean _isswcmd(iONode node) {
  Boolean defval = xBool( RocsWgen_swcmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getBool( node, "swcmd", defval );
}
static void _setswcmd(iONode node, Boolean p_swcmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setBool( node, "swcmd", p_swcmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * symbolsize
 */
static struct __attrdef RocsWgen_symbolsize = {
  "symbolsize",  "",  "",  "int",  "5",  "2-5",  False,
};
static int _getsymbolsize(iONode node) {
  int defval = xInt( RocsWgen_symbolsize );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "symbolsize", defval );
}
static void _setsymbolsize(iONode node, int p_symbolsize) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "symbolsize", p_symbolsize );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * traverser
 */
static struct __attrdef RocsWgen_traverser = {
  "traverser",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _istraverser(iONode node) {
  Boolean defval = xBool( RocsWgen_traverser );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getBool( node, "traverser", defval );
}
static void _settraverser(iONode node, Boolean p_traverser) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setBool( node, "traverser", p_traverser );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * type
 */
static struct __attrdef RocsWgen_type = {
  "type",  "",  "",  "string",  "locdec",  "*",  False,
};
static const char* _gettype(iONode node) {
  const char* defval = xStr( RocsWgen_type );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getStr( node, "type", defval );
}
static void _settype(iONode node, const char* p_type) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setStr( node, "type", p_type );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * x
 */
static struct __attrdef RocsWgen_x = {
  "x",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getx(iONode node) {
  int defval = xInt( RocsWgen_x );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "x", defval );
}
static void _setx(iONode node, int p_x) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "x", p_x );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * y
 */
static struct __attrdef RocsWgen_y = {
  "y",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _gety(iONode node) {
  int defval = xInt( RocsWgen_y );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "y", defval );
}
static void _sety(iONode node, int p_y) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "y", p_y );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * z
 */
static struct __attrdef RocsWgen_z = {
  "z",  "",  "",  "int",  "0",  "0-9",  False,
};
static int _getz(iONode node) {
  int defval = xInt( RocsWgen_z );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tt, node );
  return NodeOp.getInt( node, "z", defval );
}
static void _setz(iONode node, int p_z) {
  if( node == NULL ) return;
  xNode( RocsWgen_tt, node );
  NodeOp.setInt( node, "z", p_z );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * track
 */
static struct __nodedef RocsWgen_track = {
  "track",  "Turntable track.",  False,  "n",};
static iONode _gettrack(iONode node) {
  xNode( RocsWgen_tt, node );
  return NodeOp.findNode( node, "track");
}


static iONode _nexttrack(iONode node, iONode child) {
  xNode( RocsWgen_tt, node );
  return NodeOp.findNextNode( node, child);
}
static void _settrack(iONode node, iONode p_track) {
  xNode( RocsWgen_tt, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * actionctrl
 */
static struct __nodedef RocsWgen_actionctrl = {
  "actionctrl",  "",  False,  "n",};
static iONode _getactionctrl(iONode node) {
  xNode( RocsWgen_tt, node );
  return NodeOp.findNode( node, "actionctrl");
}


static iONode _nextactionctrl(iONode node, iONode child) {
  xNode( RocsWgen_tt, node );
  return NodeOp.findNextNode( node, child);
}
static void _setactionctrl(iONode node, iONode p_actionctrl) {
  xNode( RocsWgen_tt, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[77] = {NULL};
static struct __nodedef* nodeList[3] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_tt.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node tt not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node tt not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_V;
  attrList[1] = &RocsWgen_actfn;
  attrList[2] = &RocsWgen_addr;
  attrList[3] = &RocsWgen_addr0;
  attrList[4] = &RocsWgen_addr1;
  attrList[5] = &RocsWgen_addr2;
  attrList[6] = &RocsWgen_addr3;
  attrList[7] = &RocsWgen_addr4;
  attrList[8] = &RocsWgen_addr5;
  attrList[9] = &RocsWgen_addr6;
  attrList[10] = &RocsWgen_b0sen;
  attrList[11] = &RocsWgen_b1sen;
  attrList[12] = &RocsWgen_b2sen;
  attrList[13] = &RocsWgen_b3sen;
  attrList[14] = &RocsWgen_bit0cmd;
  attrList[15] = &RocsWgen_bit1cmd;
  attrList[16] = &RocsWgen_bit2cmd;
  attrList[17] = &RocsWgen_bit3cmd;
  attrList[18] = &RocsWgen_bit4cmd;
  attrList[19] = &RocsWgen_bit5cmd;
  attrList[20] = &RocsWgen_bridgepos;
  attrList[21] = &RocsWgen_bus;
  attrList[22] = &RocsWgen_cmd;
  attrList[23] = &RocsWgen_cmdbyroute;
  attrList[24] = &RocsWgen_delay;
  attrList[25] = &RocsWgen_desc;
  attrList[26] = &RocsWgen_diraddr;
  attrList[27] = &RocsWgen_embeddedblock;
  attrList[28] = &RocsWgen_entering;
  attrList[29] = &RocsWgen_fun;
  attrList[30] = &RocsWgen_id;
  attrList[31] = &RocsWgen_iid;
  attrList[32] = &RocsWgen_inv;
  attrList[33] = &RocsWgen_invnew;
  attrList[34] = &RocsWgen_invpos;
  attrList[35] = &RocsWgen_lightsfn;
  attrList[36] = &RocsWgen_locid;
  attrList[37] = &RocsWgen_manager;
  attrList[38] = &RocsWgen_motoroffdelay;
  attrList[39] = &RocsWgen_move4opp;
  attrList[40] = &RocsWgen_oid;
  attrList[41] = &RocsWgen_pause;
  attrList[42] = &RocsWgen_poladdr;
  attrList[43] = &RocsWgen_port0;
  attrList[44] = &RocsWgen_port1;
  attrList[45] = &RocsWgen_port2;
  attrList[46] = &RocsWgen_port3;
  attrList[47] = &RocsWgen_port4;
  attrList[48] = &RocsWgen_port5;
  attrList[49] = &RocsWgen_port6;
  attrList[50] = &RocsWgen_prot;
  attrList[51] = &RocsWgen_psen;
  attrList[52] = &RocsWgen_randomrate;
  attrList[53] = &RocsWgen_reserved;
  attrList[54] = &RocsWgen_resetaddr;
  attrList[55] = &RocsWgen_resetbitcmd;
  attrList[56] = &RocsWgen_resetport;
  attrList[57] = &RocsWgen_s1;
  attrList[58] = &RocsWgen_s2;
  attrList[59] = &RocsWgen_sMid;
  attrList[60] = &RocsWgen_sMid2;
  attrList[61] = &RocsWgen_singlegatenew;
  attrList[62] = &RocsWgen_singlegatepos;
  attrList[63] = &RocsWgen_state;
  attrList[64] = &RocsWgen_state1;
  attrList[65] = &RocsWgen_state2;
  attrList[66] = &RocsWgen_stateMid;
  attrList[67] = &RocsWgen_stateMid2;
  attrList[68] = &RocsWgen_swaprotation;
  attrList[69] = &RocsWgen_swcmd;
  attrList[70] = &RocsWgen_symbolsize;
  attrList[71] = &RocsWgen_traverser;
  attrList[72] = &RocsWgen_type;
  attrList[73] = &RocsWgen_x;
  attrList[74] = &RocsWgen_y;
  attrList[75] = &RocsWgen_z;
  attrList[76] = NULL;
  nodeList[0] = &RocsWgen_track;
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


struct __wTurntable wTurntable = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "accdec",
  "calibrate",
  "d15",
  "digitalbahn",
  "dsm",
  "f6915",
  "off",
  "on",
  "lightoff",
  "lighton",
  "locdec",
  "muet",
  "multiport",
  "next",
  "prev",
  "D",
  "M",
  "MP",
  "N",
  "slx815",
  "ttdec",
  "180",
  "-unlocked-",
  _getV,
  _setV,
  _getactfn,
  _setactfn,
  _getaddr,
  _setaddr,
  _getaddr0,
  _setaddr0,
  _getaddr1,
  _setaddr1,
  _getaddr2,
  _setaddr2,
  _getaddr3,
  _setaddr3,
  _getaddr4,
  _setaddr4,
  _getaddr5,
  _setaddr5,
  _getaddr6,
  _setaddr6,
  _getb0sen,
  _setb0sen,
  _getb1sen,
  _setb1sen,
  _getb2sen,
  _setb2sen,
  _getb3sen,
  _setb3sen,
  _getbit0cmd,
  _setbit0cmd,
  _getbit1cmd,
  _setbit1cmd,
  _getbit2cmd,
  _setbit2cmd,
  _getbit3cmd,
  _setbit3cmd,
  _getbit4cmd,
  _setbit4cmd,
  _getbit5cmd,
  _setbit5cmd,
  _getbridgepos,
  _setbridgepos,
  _getbus,
  _setbus,
  _getcmd,
  _setcmd,
  _iscmdbyroute,
  _setcmdbyroute,
  _getdelay,
  _setdelay,
  _getdesc,
  _setdesc,
  _getdiraddr,
  _setdiraddr,
  _isembeddedblock,
  _setembeddedblock,
  _isentering,
  _setentering,
  _getfun,
  _setfun,
  _getid,
  _setid,
  _getiid,
  _setiid,
  _isinv,
  _setinv,
  _isinvnew,
  _setinvnew,
  _isinvpos,
  _setinvpos,
  _getlightsfn,
  _setlightsfn,
  _getlocid,
  _setlocid,
  _ismanager,
  _setmanager,
  _getmotoroffdelay,
  _setmotoroffdelay,
  _ismove4opp,
  _setmove4opp,
  _getoid,
  _setoid,
  _getpause,
  _setpause,
  _getpoladdr,
  _setpoladdr,
  _getport0,
  _setport0,
  _getport1,
  _setport1,
  _getport2,
  _setport2,
  _getport3,
  _setport3,
  _getport4,
  _setport4,
  _getport5,
  _setport5,
  _getport6,
  _setport6,
  _getprot,
  _setprot,
  _getpsen,
  _setpsen,
  _getrandomrate,
  _setrandomrate,
  _isreserved,
  _setreserved,
  _getresetaddr,
  _setresetaddr,
  _getresetbitcmd,
  _setresetbitcmd,
  _getresetport,
  _setresetport,
  _gets1,
  _sets1,
  _gets2,
  _sets2,
  _getsMid,
  _setsMid,
  _getsMid2,
  _setsMid2,
  _issinglegatenew,
  _setsinglegatenew,
  _issinglegatepos,
  _setsinglegatepos,
  _getstate,
  _setstate,
  _isstate1,
  _setstate1,
  _isstate2,
  _setstate2,
  _isstateMid,
  _setstateMid,
  _isstateMid2,
  _setstateMid2,
  _isswaprotation,
  _setswaprotation,
  _isswcmd,
  _setswcmd,
  _getsymbolsize,
  _setsymbolsize,
  _istraverser,
  _settraverser,
  _gettype,
  _settype,
  _getx,
  _setx,
  _gety,
  _sety,
  _getz,
  _setz,
  _gettrack,
  _nexttrack,
  _settrack,
  _getactionctrl,
  _nextactionctrl,
  _setactionctrl,
  _node_dump,
};
