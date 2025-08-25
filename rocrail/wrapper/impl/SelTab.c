/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/SelTab.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.SelTab
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_seltab = {
  "seltab",  "Selection Table",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_seltab.name;
}
static const char* _node_remark(void) {
  return RocsWgen_seltab.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_seltab.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_seltab.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr0
 */
static struct __attrdef RocsWgen_addr0 = {
  "addr0",  "decoder address",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr0(iONode node) {
  int defval = xInt( RocsWgen_addr0 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "addr0", defval );
}
static void _setaddr0(iONode node, int p_addr0) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "addr0", p_addr0 );
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
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "addr1", defval );
}
static void _setaddr1(iONode node, int p_addr1) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "addr1", p_addr1 );
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
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "addr2", defval );
}
static void _setaddr2(iONode node, int p_addr2) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
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
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "addr3", defval );
}
static void _setaddr3(iONode node, int p_addr3) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "addr3", p_addr3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr4
 */
static struct __attrdef RocsWgen_addr4 = {
  "addr4",  "decoder address to signal new position",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr4(iONode node) {
  int defval = xInt( RocsWgen_addr4 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "addr4", defval );
}
static void _setaddr4(iONode node, int p_addr4) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "addr4", p_addr4 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr5
 */
static struct __attrdef RocsWgen_addr5 = {
  "addr5",  "decoder address",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr5(iONode node) {
  int defval = xInt( RocsWgen_addr5 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "addr5", defval );
}
static void _setaddr5(iONode node, int p_addr5) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "addr5", p_addr5 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr6
 */
static struct __attrdef RocsWgen_addr6 = {
  "addr6",  "decoder address",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr6(iONode node) {
  int defval = xInt( RocsWgen_addr6 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "addr6", defval );
}
static void _setaddr6(iONode node, int p_addr6) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "addr6", p_addr6 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr7
 */
static struct __attrdef RocsWgen_addr7 = {
  "addr7",  "decoder address",  "",  "int",  "0",  "0-*",  True,
};
static int _getaddr7(iONode node) {
  int defval = xInt( RocsWgen_addr7 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "addr7", defval );
}
static void _setaddr7(iONode node, int p_addr7) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "addr7", p_addr7 );
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
  xNode( RocsWgen_seltab, node );
  return NodeOp.getStr( node, "b0sen", defval );
}
static void _setb0sen(iONode node, const char* p_b0sen) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
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
  xNode( RocsWgen_seltab, node );
  return NodeOp.getStr( node, "b1sen", defval );
}
static void _setb1sen(iONode node, const char* p_b1sen) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
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
  xNode( RocsWgen_seltab, node );
  return NodeOp.getStr( node, "b2sen", defval );
}
static void _setb2sen(iONode node, const char* p_b2sen) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
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
  xNode( RocsWgen_seltab, node );
  return NodeOp.getStr( node, "b3sen", defval );
}
static void _setb3sen(iONode node, const char* p_b3sen) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setStr( node, "b3sen", p_b3sen );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * b4sen
 */
static struct __attrdef RocsWgen_b4sen = {
  "b4sen",  "ID bit 4 of position",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getb4sen(iONode node) {
  const char* defval = xStr( RocsWgen_b4sen );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getStr( node, "b4sen", defval );
}
static void _setb4sen(iONode node, const char* p_b4sen) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setStr( node, "b4sen", p_b4sen );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * b5sen
 */
static struct __attrdef RocsWgen_b5sen = {
  "b5sen",  "ID bit 5 of position",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getb5sen(iONode node) {
  const char* defval = xStr( RocsWgen_b5sen );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getStr( node, "b5sen", defval );
}
static void _setb5sen(iONode node, const char* p_b5sen) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setStr( node, "b5sen", p_b5sen );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * b6sen
 */
static struct __attrdef RocsWgen_b6sen = {
  "b6sen",  "ID bit 6 of position",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getb6sen(iONode node) {
  const char* defval = xStr( RocsWgen_b6sen );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getStr( node, "b6sen", defval );
}
static void _setb6sen(iONode node, const char* p_b6sen) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setStr( node, "b6sen", p_b6sen );
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
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "bus", defval );
}
static void _setbus(iONode node, int p_bus) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
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
  xNode( RocsWgen_seltab, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
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
  xNode( RocsWgen_seltab, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fifo
 */
static struct __attrdef RocsWgen_fifo = {
  "fifo",  "Firts in, First out",  "",  "bool",  "true",  "",  False,
};
static Boolean _isfifo(iONode node) {
  Boolean defval = xBool( RocsWgen_fifo );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getBool( node, "fifo", defval );
}
static void _setfifo(iONode node, Boolean p_fifo) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setBool( node, "fifo", p_fifo );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "object id",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iid
 */
static struct __attrdef RocsWgen_iid = {
  "iid",  "interfaced id",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getiid(iONode node) {
  const char* defval = xStr( RocsWgen_iid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * inv
 */
static struct __attrdef RocsWgen_inv = {
  "inv",  "invert the switch commands 0 to 3",  "",  "bool",  "false",  "",  False,
};
static Boolean _isinv(iONode node) {
  Boolean defval = xBool( RocsWgen_inv );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getBool( node, "inv", defval );
}
static void _setinv(iONode node, Boolean p_inv) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setBool( node, "inv", p_inv );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * invnew
 */
static struct __attrdef RocsWgen_invnew = {
  "invnew",  "invert the switch command 4",  "",  "bool",  "false",  "",  False,
};
static Boolean _isinvnew(iONode node) {
  Boolean defval = xBool( RocsWgen_invnew );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getBool( node, "invnew", defval );
}
static void _setinvnew(iONode node, Boolean p_invnew) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setBool( node, "invnew", p_invnew );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * locid
 */
static struct __attrdef RocsWgen_locid = {
  "locid",  "loc id",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getlocid(iONode node) {
  const char* defval = xStr( RocsWgen_locid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getStr( node, "locid", defval );
}
static void _setlocid(iONode node, const char* p_locid) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
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
  xNode( RocsWgen_seltab, node );
  return NodeOp.getBool( node, "manager", defval );
}
static void _setmanager(iONode node, Boolean p_manager) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setBool( node, "manager", p_manager );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * minocc
 */
static struct __attrdef RocsWgen_minocc = {
  "minocc",  "minimal tracks to be occupied before leaving the fiddle yard",  "",  "int",  "0",  "0-*",  False,
};
static int _getminocc(iONode node) {
  int defval = xInt( RocsWgen_minocc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "minocc", defval );
}
static void _setminocc(iONode node, int p_minocc) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "minocc", p_minocc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * movedelay
 */
static struct __attrdef RocsWgen_movedelay = {
  "movedelay",  "delay in seconds after an IN event before processing a new move",  "",  "int",  "0",  "0-*",  False,
};
static int _getmovedelay(iONode node) {
  int defval = xInt( RocsWgen_movedelay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "movedelay", defval );
}
static void _setmovedelay(iONode node, int p_movedelay) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "movedelay", p_movedelay );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nrtracks
 */
static struct __attrdef RocsWgen_nrtracks = {
  "nrtracks",  "",  "",  "int",  "12",  "4-128",  True,
};
static int _getnrtracks(iONode node) {
  int defval = xInt( RocsWgen_nrtracks );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "nrtracks", defval );
}
static void _setnrtracks(iONode node, int p_nrtracks) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "nrtracks", p_nrtracks );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * offpos
 */
static struct __attrdef RocsWgen_offpos = {
  "offpos",  "Goto position at power off.",  "",  "int",  "0",  "0-*",  False,
};
static int _getoffpos(iONode node) {
  int defval = xInt( RocsWgen_offpos );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "offpos", defval );
}
static void _setoffpos(iONode node, int p_offpos) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "offpos", p_offpos );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ori
 */
static struct __attrdef RocsWgen_ori = {
  "ori",  "",  "",  "string",  "NULL",  "north,south,west,east",  False,
};
static const char* _getori(iONode node) {
  const char* defval = xStr( RocsWgen_ori );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getStr( node, "ori", defval );
}
static void _setori(iONode node, const char* p_ori) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setStr( node, "ori", p_ori );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * pending
 */
static struct __attrdef RocsWgen_pending = {
  "pending",  "",  "",  "bool",  "false",  "*",  False,
};
static Boolean _ispending(iONode node) {
  Boolean defval = xBool( RocsWgen_pending );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getBool( node, "pending", defval );
}
static void _setpending(iONode node, Boolean p_pending) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setBool( node, "pending", p_pending );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port0
 */
static struct __attrdef RocsWgen_port0 = {
  "port0",  "port of decoder unit.",  "",  "int",  "0",  "0-4",  True,
};
static int _getport0(iONode node) {
  int defval = xInt( RocsWgen_port0 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "port0", defval );
}
static void _setport0(iONode node, int p_port0) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "port0", p_port0 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port1
 */
static struct __attrdef RocsWgen_port1 = {
  "port1",  "port of decoder unit.",  "",  "int",  "0",  "0-4",  True,
};
static int _getport1(iONode node) {
  int defval = xInt( RocsWgen_port1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "port1", defval );
}
static void _setport1(iONode node, int p_port1) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "port1", p_port1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port2
 */
static struct __attrdef RocsWgen_port2 = {
  "port2",  "port of decoder unit.",  "",  "int",  "0",  "0-4",  True,
};
static int _getport2(iONode node) {
  int defval = xInt( RocsWgen_port2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "port2", defval );
}
static void _setport2(iONode node, int p_port2) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "port2", p_port2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port3
 */
static struct __attrdef RocsWgen_port3 = {
  "port3",  "port of decoder unit.",  "",  "int",  "0",  "0-4",  True,
};
static int _getport3(iONode node) {
  int defval = xInt( RocsWgen_port3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "port3", defval );
}
static void _setport3(iONode node, int p_port3) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "port3", p_port3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port4
 */
static struct __attrdef RocsWgen_port4 = {
  "port4",  "port of decoder unit to signal new position.",  "",  "int",  "0",  "0-4",  True,
};
static int _getport4(iONode node) {
  int defval = xInt( RocsWgen_port4 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "port4", defval );
}
static void _setport4(iONode node, int p_port4) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "port4", p_port4 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port5
 */
static struct __attrdef RocsWgen_port5 = {
  "port5",  "port of decoder unit.",  "",  "int",  "0",  "0-4",  True,
};
static int _getport5(iONode node) {
  int defval = xInt( RocsWgen_port5 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "port5", defval );
}
static void _setport5(iONode node, int p_port5) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "port5", p_port5 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port6
 */
static struct __attrdef RocsWgen_port6 = {
  "port6",  "port of decoder unit.",  "",  "int",  "0",  "0-4",  True,
};
static int _getport6(iONode node) {
  int defval = xInt( RocsWgen_port6 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "port6", defval );
}
static void _setport6(iONode node, int p_port6) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "port6", p_port6 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port7
 */
static struct __attrdef RocsWgen_port7 = {
  "port7",  "port of decoder unit.",  "",  "int",  "0",  "0-4",  True,
};
static int _getport7(iONode node) {
  int defval = xInt( RocsWgen_port7 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "port7", defval );
}
static void _setport7(iONode node, int p_port7) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "port7", p_port7 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * pos
 */
static struct __attrdef RocsWgen_pos = {
  "pos",  "position of table",  "",  "int",  "0",  "*",  False,
};
static int _getpos(iONode node) {
  int defval = xInt( RocsWgen_pos );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "pos", defval );
}
static void _setpos(iONode node, int p_pos) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "pos", p_pos );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * prot
 */
static struct __attrdef RocsWgen_prot = {
  "prot",  "protocol to use for this seltab",  "",  "string",  "D",  "D,M,N",  False,
};
static const char* _getprot(iONode node) {
  const char* defval = xStr( RocsWgen_prot );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getStr( node, "prot", defval );
}
static void _setprot(iONode node, const char* p_prot) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
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
  xNode( RocsWgen_seltab, node );
  return NodeOp.getStr( node, "psen", defval );
}
static void _setpsen(iONode node, const char* p_psen) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
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
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "randomrate", defval );
}
static void _setrandomrate(iONode node, int p_randomrate) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "randomrate", p_randomrate );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sharedfb
 */
static struct __attrdef RocsWgen_sharedfb = {
  "sharedfb",  "Use one set of sensors for all blocks.",  "",  "bool",  "false",  "",  False,
};
static Boolean _issharedfb(iONode node) {
  Boolean defval = xBool( RocsWgen_sharedfb );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_seltab, node );
  return NodeOp.getBool( node, "sharedfb", defval );
}
static void _setsharedfb(iONode node, Boolean p_sharedfb) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setBool( node, "sharedfb", p_sharedfb );
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
  xNode( RocsWgen_seltab, node );
  return NodeOp.getBool( node, "singlegate", defval );
}
static void _setsinglegate(iONode node, Boolean p_singlegate) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setBool( node, "singlegate", p_singlegate );
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
  xNode( RocsWgen_seltab, node );
  return NodeOp.getStr( node, "state", defval );
}
static void _setstate(iONode node, const char* p_state) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setStr( node, "state", p_state );
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
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "x", defval );
}
static void _setx(iONode node, int p_x) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
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
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "y", defval );
}
static void _sety(iONode node, int p_y) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
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
  xNode( RocsWgen_seltab, node );
  return NodeOp.getInt( node, "z", defval );
}
static void _setz(iONode node, int p_z) {
  if( node == NULL ) return;
  xNode( RocsWgen_seltab, node );
  NodeOp.setInt( node, "z", p_z );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * seltabpos
 */
static struct __nodedef RocsWgen_seltabpos = {
  "seltabpos",  "Selection Table Position",  False,  "n",};
static iONode _getseltabpos(iONode node) {
  xNode( RocsWgen_seltab, node );
  return NodeOp.findNode( node, "seltabpos");
}


static iONode _nextseltabpos(iONode node, iONode child) {
  xNode( RocsWgen_seltab, node );
  return NodeOp.findNextNode( node, child);
}
static void _setseltabpos(iONode node, iONode p_seltabpos) {
  xNode( RocsWgen_seltab, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * fbevent
 */
static struct __nodedef RocsWgen_fbevent = {
  "fbevent",  "",  False,  "n",};
static iONode _getfbevent(iONode node) {
  xNode( RocsWgen_seltab, node );
  return NodeOp.findNode( node, "fbevent");
}


static iONode _nextfbevent(iONode node, iONode child) {
  xNode( RocsWgen_seltab, node );
  return NodeOp.findNextNode( node, child);
}
static void _setfbevent(iONode node, iONode p_fbevent) {
  xNode( RocsWgen_seltab, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * actionctrl
 */
static struct __nodedef RocsWgen_actionctrl = {
  "actionctrl",  "",  False,  "n",};
static iONode _getactionctrl(iONode node) {
  xNode( RocsWgen_seltab, node );
  return NodeOp.findNode( node, "actionctrl");
}


static iONode _nextactionctrl(iONode node, iONode child) {
  xNode( RocsWgen_seltab, node );
  return NodeOp.findNextNode( node, child);
}
static void _setactionctrl(iONode node, iONode p_actionctrl) {
  xNode( RocsWgen_seltab, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[50] = {NULL};
static struct __nodedef* nodeList[4] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_seltab.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node seltab not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node seltab not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_addr0;
  attrList[1] = &RocsWgen_addr1;
  attrList[2] = &RocsWgen_addr2;
  attrList[3] = &RocsWgen_addr3;
  attrList[4] = &RocsWgen_addr4;
  attrList[5] = &RocsWgen_addr5;
  attrList[6] = &RocsWgen_addr6;
  attrList[7] = &RocsWgen_addr7;
  attrList[8] = &RocsWgen_b0sen;
  attrList[9] = &RocsWgen_b1sen;
  attrList[10] = &RocsWgen_b2sen;
  attrList[11] = &RocsWgen_b3sen;
  attrList[12] = &RocsWgen_b4sen;
  attrList[13] = &RocsWgen_b5sen;
  attrList[14] = &RocsWgen_b6sen;
  attrList[15] = &RocsWgen_bus;
  attrList[16] = &RocsWgen_cmd;
  attrList[17] = &RocsWgen_desc;
  attrList[18] = &RocsWgen_fifo;
  attrList[19] = &RocsWgen_id;
  attrList[20] = &RocsWgen_iid;
  attrList[21] = &RocsWgen_inv;
  attrList[22] = &RocsWgen_invnew;
  attrList[23] = &RocsWgen_locid;
  attrList[24] = &RocsWgen_manager;
  attrList[25] = &RocsWgen_minocc;
  attrList[26] = &RocsWgen_movedelay;
  attrList[27] = &RocsWgen_nrtracks;
  attrList[28] = &RocsWgen_offpos;
  attrList[29] = &RocsWgen_ori;
  attrList[30] = &RocsWgen_pending;
  attrList[31] = &RocsWgen_port0;
  attrList[32] = &RocsWgen_port1;
  attrList[33] = &RocsWgen_port2;
  attrList[34] = &RocsWgen_port3;
  attrList[35] = &RocsWgen_port4;
  attrList[36] = &RocsWgen_port5;
  attrList[37] = &RocsWgen_port6;
  attrList[38] = &RocsWgen_port7;
  attrList[39] = &RocsWgen_pos;
  attrList[40] = &RocsWgen_prot;
  attrList[41] = &RocsWgen_psen;
  attrList[42] = &RocsWgen_randomrate;
  attrList[43] = &RocsWgen_sharedfb;
  attrList[44] = &RocsWgen_singlegate;
  attrList[45] = &RocsWgen_state;
  attrList[46] = &RocsWgen_x;
  attrList[47] = &RocsWgen_y;
  attrList[48] = &RocsWgen_z;
  attrList[49] = NULL;
  nodeList[0] = &RocsWgen_seltabpos;
  nodeList[1] = &RocsWgen_fbevent;
  nodeList[2] = &RocsWgen_actionctrl;
  nodeList[3] = NULL;
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


struct __wSelTab wSelTab = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "gotopos",
  "next",
  "prev",
  "D",
  "M",
  "MP",
  "N",
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
  _getaddr7,
  _setaddr7,
  _getb0sen,
  _setb0sen,
  _getb1sen,
  _setb1sen,
  _getb2sen,
  _setb2sen,
  _getb3sen,
  _setb3sen,
  _getb4sen,
  _setb4sen,
  _getb5sen,
  _setb5sen,
  _getb6sen,
  _setb6sen,
  _getbus,
  _setbus,
  _getcmd,
  _setcmd,
  _getdesc,
  _setdesc,
  _isfifo,
  _setfifo,
  _getid,
  _setid,
  _getiid,
  _setiid,
  _isinv,
  _setinv,
  _isinvnew,
  _setinvnew,
  _getlocid,
  _setlocid,
  _ismanager,
  _setmanager,
  _getminocc,
  _setminocc,
  _getmovedelay,
  _setmovedelay,
  _getnrtracks,
  _setnrtracks,
  _getoffpos,
  _setoffpos,
  _getori,
  _setori,
  _ispending,
  _setpending,
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
  _getport7,
  _setport7,
  _getpos,
  _setpos,
  _getprot,
  _setprot,
  _getpsen,
  _setpsen,
  _getrandomrate,
  _setrandomrate,
  _issharedfb,
  _setsharedfb,
  _issinglegate,
  _setsinglegate,
  _getstate,
  _setstate,
  _getx,
  _setx,
  _gety,
  _sety,
  _getz,
  _setz,
  _getseltabpos,
  _nextseltabpos,
  _setseltabpos,
  _getfbevent,
  _nextfbevent,
  _setfbevent,
  _getactionctrl,
  _nextactionctrl,
  _setactionctrl,
  _node_dump,
};
