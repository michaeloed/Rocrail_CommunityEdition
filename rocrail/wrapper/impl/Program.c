/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Program.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Program
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_program = {
  "program",  "Program.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_program.name;
}
static const char* _node_remark(void) {
  return RocsWgen_program.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_program.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_program.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * acc
 */
static struct __attrdef RocsWgen_acc = {
  "acc",  "POM Program On the Main for accessory decoders",  "",  "bool",  "false",  "",  False,
};
static Boolean _isacc(iONode node) {
  Boolean defval = xBool( RocsWgen_acc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getBool( node, "acc", defval );
}
static void _setacc(iONode node, Boolean p_acc) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setBool( node, "acc", p_acc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr
 */
static struct __attrdef RocsWgen_addr = {
  "addr",  "loco address for POM",  "",  "int",  "0",  "*",  False,
};
static int _getaddr(iONode node) {
  int defval = xInt( RocsWgen_addr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "addr", defval );
}
static void _setaddr(iONode node, int p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "addr", p_addr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmd
 */
static struct __attrdef RocsWgen_cmd = {
  "cmd",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getcmd(iONode node) {
  int defval = xInt( RocsWgen_cmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "cmd", defval );
}
static void _setcmd(iONode node, int p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cv
 */
static struct __attrdef RocsWgen_cv = {
  "cv",  "CV number",  "",  "int",  "0",  "0-1023",  False,
};
static int _getcv(iONode node) {
  int defval = xInt( RocsWgen_cv );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "cv", defval );
}
static void _setcv(iONode node, int p_cv) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "cv", p_cv );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * decaddr
 */
static struct __attrdef RocsWgen_decaddr = {
  "decaddr",  "decoder address in case of POM",  "",  "int",  "0",  "*",  False,
};
static int _getdecaddr(iONode node) {
  int defval = xInt( RocsWgen_decaddr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "decaddr", defval );
}
static void _setdecaddr(iONode node, int p_decaddr) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "decaddr", p_decaddr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * eeprom
 */
static struct __attrdef RocsWgen_eeprom = {
  "eeprom",  "Write EEprom.",  "",  "bool",  "true",  "",  False,
};
static Boolean _iseeprom(iONode node) {
  Boolean defval = xBool( RocsWgen_eeprom );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getBool( node, "eeprom", defval );
}
static void _seteeprom(iONode node, Boolean p_eeprom) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setBool( node, "eeprom", p_eeprom );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * filename
 */
static struct __attrdef RocsWgen_filename = {
  "filename",  "",  "",  "string",  "",  "",  False,
};
static const char* _getfilename(iONode node) {
  const char* defval = xStr( RocsWgen_filename );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getStr( node, "filename", defval );
}
static void _setfilename(iONode node, const char* p_filename) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setStr( node, "filename", p_filename );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * identifier
 */
static struct __attrdef RocsWgen_identifier = {
  "identifier",  "Loc identifier",  "",  "string",  "",  "",  False,
};
static const char* _getidentifier(iONode node) {
  const char* defval = xStr( RocsWgen_identifier );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getStr( node, "identifier", defval );
}
static void _setidentifier(iONode node, const char* p_identifier) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setStr( node, "identifier", p_identifier );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iid
 */
static struct __attrdef RocsWgen_iid = {
  "iid",  "",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getiid(iONode node) {
  const char* defval = xStr( RocsWgen_iid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lncv
 */
static struct __attrdef RocsWgen_lncv = {
  "lncv",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _islncv(iONode node) {
  Boolean defval = xBool( RocsWgen_lncv );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getBool( node, "lncv", defval );
}
static void _setlncv(iONode node, Boolean p_lncv) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setBool( node, "lncv", p_lncv );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lncvcmd
 */
static struct __attrdef RocsWgen_lncvcmd = {
  "lncvcmd",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getlncvcmd(iONode node) {
  int defval = xInt( RocsWgen_lncvcmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "lncvcmd", defval );
}
static void _setlncvcmd(iONode node, int p_lncvcmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "lncvcmd", p_lncvcmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lntype
 */
static struct __attrdef RocsWgen_lntype = {
  "lntype",  "LNCV programming type",  "",  "int",  "0",  "",  False,
};
static int _getlntype(iONode node) {
  int defval = xInt( RocsWgen_lntype );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "lntype", defval );
}
static void _setlntype(iONode node, int p_lntype) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "lntype", p_lntype );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * longaddr
 */
static struct __attrdef RocsWgen_longaddr = {
  "longaddr",  "loco address for POM",  "",  "bool",  "false",  "",  False,
};
static Boolean _islongaddr(iONode node) {
  Boolean defval = xBool( RocsWgen_longaddr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getBool( node, "longaddr", defval );
}
static void _setlongaddr(iONode node, Boolean p_longaddr) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setBool( node, "longaddr", p_longaddr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * manu
 */
static struct __attrdef RocsWgen_manu = {
  "manu",  "manufacturer ID",  "",  "int",  "0",  "*",  False,
};
static int _getmanu(iONode node) {
  int defval = xInt( RocsWgen_manu );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "manu", defval );
}
static void _setmanu(iONode node, int p_manu) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "manu", p_manu );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mode
 */
static struct __attrdef RocsWgen_mode = {
  "mode",  "Programming mode.",  "",  "int",  "0",  "0-*",  False,
};
static int _getmode(iONode node) {
  int defval = xInt( RocsWgen_mode );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "mode", defval );
}
static void _setmode(iONode node, int p_mode) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "mode", p_mode );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * modid
 */
static struct __attrdef RocsWgen_modid = {
  "modid",  "module id for use with lncv",  "",  "int",  "0",  "*",  False,
};
static int _getmodid(iONode node) {
  int defval = xInt( RocsWgen_modid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "modid", defval );
}
static void _setmodid(iONode node, int p_modid) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "modid", p_modid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * pom
 */
static struct __attrdef RocsWgen_pom = {
  "pom",  "POM Program On the Main",  "",  "bool",  "false",  "",  False,
};
static Boolean _ispom(iONode node) {
  Boolean defval = xBool( RocsWgen_pom );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getBool( node, "pom", defval );
}
static void _setpom(iONode node, Boolean p_pom) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setBool( node, "pom", p_pom );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * porttype
 */
static struct __attrdef RocsWgen_porttype = {
  "porttype",  "Port type",  "",  "int",  "0",  "",  False,
};
static int _getporttype(iONode node) {
  int defval = xInt( RocsWgen_porttype );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "porttype", defval );
}
static void _setporttype(iONode node, int p_porttype) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "porttype", p_porttype );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * prod
 */
static struct __attrdef RocsWgen_prod = {
  "prod",  "product ID",  "",  "int",  "0",  "*",  False,
};
static int _getprod(iONode node) {
  int defval = xInt( RocsWgen_prod );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "prod", defval );
}
static void _setprod(iONode node, int p_prod) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "prod", p_prod );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * rc
 */
static struct __attrdef RocsWgen_rc = {
  "rc",  "return code",  "",  "int",  "0",  "0-*",  False,
};
static int _getrc(iONode node) {
  int defval = xInt( RocsWgen_rc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "rc", defval );
}
static void _setrc(iONode node, int p_rc) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "rc", p_rc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * rs
 */
static struct __attrdef RocsWgen_rs = {
  "rs",  "reason code",  "",  "int",  "0",  "0-*",  False,
};
static int _getrs(iONode node) {
  int defval = xInt( RocsWgen_rs );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "rs", defval );
}
static void _setrs(iONode node, int p_rs) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "rs", p_rs );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * strval1
 */
static struct __attrdef RocsWgen_strval1 = {
  "strval1",  "",  "",  "string",  "",  "",  False,
};
static const char* _getstrval1(iONode node) {
  const char* defval = xStr( RocsWgen_strval1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getStr( node, "strval1", defval );
}
static void _setstrval1(iONode node, const char* p_strval1) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setStr( node, "strval1", p_strval1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * strval2
 */
static struct __attrdef RocsWgen_strval2 = {
  "strval2",  "",  "",  "string",  "",  "",  False,
};
static const char* _getstrval2(iONode node) {
  const char* defval = xStr( RocsWgen_strval2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getStr( node, "strval2", defval );
}
static void _setstrval2(iONode node, const char* p_strval2) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setStr( node, "strval2", p_strval2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * strval3
 */
static struct __attrdef RocsWgen_strval3 = {
  "strval3",  "",  "",  "string",  "",  "",  False,
};
static const char* _getstrval3(iONode node) {
  const char* defval = xStr( RocsWgen_strval3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getStr( node, "strval3", defval );
}
static void _setstrval3(iONode node, const char* p_strval3) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setStr( node, "strval3", p_strval3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val1
 */
static struct __attrdef RocsWgen_val1 = {
  "val1",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval1(iONode node) {
  int defval = xInt( RocsWgen_val1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val1", defval );
}
static void _setval1(iONode node, int p_val1) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val1", p_val1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val10
 */
static struct __attrdef RocsWgen_val10 = {
  "val10",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval10(iONode node) {
  int defval = xInt( RocsWgen_val10 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val10", defval );
}
static void _setval10(iONode node, int p_val10) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val10", p_val10 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val11
 */
static struct __attrdef RocsWgen_val11 = {
  "val11",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval11(iONode node) {
  int defval = xInt( RocsWgen_val11 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val11", defval );
}
static void _setval11(iONode node, int p_val11) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val11", p_val11 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val12
 */
static struct __attrdef RocsWgen_val12 = {
  "val12",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval12(iONode node) {
  int defval = xInt( RocsWgen_val12 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val12", defval );
}
static void _setval12(iONode node, int p_val12) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val12", p_val12 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val13
 */
static struct __attrdef RocsWgen_val13 = {
  "val13",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval13(iONode node) {
  int defval = xInt( RocsWgen_val13 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val13", defval );
}
static void _setval13(iONode node, int p_val13) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val13", p_val13 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val14
 */
static struct __attrdef RocsWgen_val14 = {
  "val14",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval14(iONode node) {
  int defval = xInt( RocsWgen_val14 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val14", defval );
}
static void _setval14(iONode node, int p_val14) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val14", p_val14 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val15
 */
static struct __attrdef RocsWgen_val15 = {
  "val15",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval15(iONode node) {
  int defval = xInt( RocsWgen_val15 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val15", defval );
}
static void _setval15(iONode node, int p_val15) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val15", p_val15 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val16
 */
static struct __attrdef RocsWgen_val16 = {
  "val16",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval16(iONode node) {
  int defval = xInt( RocsWgen_val16 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val16", defval );
}
static void _setval16(iONode node, int p_val16) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val16", p_val16 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val17
 */
static struct __attrdef RocsWgen_val17 = {
  "val17",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval17(iONode node) {
  int defval = xInt( RocsWgen_val17 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val17", defval );
}
static void _setval17(iONode node, int p_val17) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val17", p_val17 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val18
 */
static struct __attrdef RocsWgen_val18 = {
  "val18",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval18(iONode node) {
  int defval = xInt( RocsWgen_val18 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val18", defval );
}
static void _setval18(iONode node, int p_val18) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val18", p_val18 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val19
 */
static struct __attrdef RocsWgen_val19 = {
  "val19",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval19(iONode node) {
  int defval = xInt( RocsWgen_val19 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val19", defval );
}
static void _setval19(iONode node, int p_val19) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val19", p_val19 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val2
 */
static struct __attrdef RocsWgen_val2 = {
  "val2",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval2(iONode node) {
  int defval = xInt( RocsWgen_val2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val2", defval );
}
static void _setval2(iONode node, int p_val2) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val2", p_val2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val20
 */
static struct __attrdef RocsWgen_val20 = {
  "val20",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval20(iONode node) {
  int defval = xInt( RocsWgen_val20 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val20", defval );
}
static void _setval20(iONode node, int p_val20) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val20", p_val20 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val21
 */
static struct __attrdef RocsWgen_val21 = {
  "val21",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval21(iONode node) {
  int defval = xInt( RocsWgen_val21 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val21", defval );
}
static void _setval21(iONode node, int p_val21) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val21", p_val21 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val22
 */
static struct __attrdef RocsWgen_val22 = {
  "val22",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval22(iONode node) {
  int defval = xInt( RocsWgen_val22 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val22", defval );
}
static void _setval22(iONode node, int p_val22) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val22", p_val22 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val23
 */
static struct __attrdef RocsWgen_val23 = {
  "val23",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval23(iONode node) {
  int defval = xInt( RocsWgen_val23 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val23", defval );
}
static void _setval23(iONode node, int p_val23) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val23", p_val23 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val24
 */
static struct __attrdef RocsWgen_val24 = {
  "val24",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval24(iONode node) {
  int defval = xInt( RocsWgen_val24 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val24", defval );
}
static void _setval24(iONode node, int p_val24) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val24", p_val24 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val25
 */
static struct __attrdef RocsWgen_val25 = {
  "val25",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval25(iONode node) {
  int defval = xInt( RocsWgen_val25 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val25", defval );
}
static void _setval25(iONode node, int p_val25) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val25", p_val25 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val26
 */
static struct __attrdef RocsWgen_val26 = {
  "val26",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval26(iONode node) {
  int defval = xInt( RocsWgen_val26 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val26", defval );
}
static void _setval26(iONode node, int p_val26) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val26", p_val26 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val27
 */
static struct __attrdef RocsWgen_val27 = {
  "val27",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval27(iONode node) {
  int defval = xInt( RocsWgen_val27 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val27", defval );
}
static void _setval27(iONode node, int p_val27) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val27", p_val27 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val28
 */
static struct __attrdef RocsWgen_val28 = {
  "val28",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval28(iONode node) {
  int defval = xInt( RocsWgen_val28 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val28", defval );
}
static void _setval28(iONode node, int p_val28) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val28", p_val28 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val29
 */
static struct __attrdef RocsWgen_val29 = {
  "val29",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval29(iONode node) {
  int defval = xInt( RocsWgen_val29 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val29", defval );
}
static void _setval29(iONode node, int p_val29) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val29", p_val29 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val3
 */
static struct __attrdef RocsWgen_val3 = {
  "val3",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval3(iONode node) {
  int defval = xInt( RocsWgen_val3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val3", defval );
}
static void _setval3(iONode node, int p_val3) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val3", p_val3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val30
 */
static struct __attrdef RocsWgen_val30 = {
  "val30",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval30(iONode node) {
  int defval = xInt( RocsWgen_val30 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val30", defval );
}
static void _setval30(iONode node, int p_val30) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val30", p_val30 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val31
 */
static struct __attrdef RocsWgen_val31 = {
  "val31",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval31(iONode node) {
  int defval = xInt( RocsWgen_val31 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val31", defval );
}
static void _setval31(iONode node, int p_val31) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val31", p_val31 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val32
 */
static struct __attrdef RocsWgen_val32 = {
  "val32",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval32(iONode node) {
  int defval = xInt( RocsWgen_val32 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val32", defval );
}
static void _setval32(iONode node, int p_val32) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val32", p_val32 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val33
 */
static struct __attrdef RocsWgen_val33 = {
  "val33",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval33(iONode node) {
  int defval = xInt( RocsWgen_val33 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val33", defval );
}
static void _setval33(iONode node, int p_val33) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val33", p_val33 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val34
 */
static struct __attrdef RocsWgen_val34 = {
  "val34",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval34(iONode node) {
  int defval = xInt( RocsWgen_val34 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val34", defval );
}
static void _setval34(iONode node, int p_val34) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val34", p_val34 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val35
 */
static struct __attrdef RocsWgen_val35 = {
  "val35",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval35(iONode node) {
  int defval = xInt( RocsWgen_val35 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val35", defval );
}
static void _setval35(iONode node, int p_val35) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val35", p_val35 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val36
 */
static struct __attrdef RocsWgen_val36 = {
  "val36",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval36(iONode node) {
  int defval = xInt( RocsWgen_val36 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val36", defval );
}
static void _setval36(iONode node, int p_val36) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val36", p_val36 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val37
 */
static struct __attrdef RocsWgen_val37 = {
  "val37",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval37(iONode node) {
  int defval = xInt( RocsWgen_val37 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val37", defval );
}
static void _setval37(iONode node, int p_val37) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val37", p_val37 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val38
 */
static struct __attrdef RocsWgen_val38 = {
  "val38",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval38(iONode node) {
  int defval = xInt( RocsWgen_val38 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val38", defval );
}
static void _setval38(iONode node, int p_val38) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val38", p_val38 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val39
 */
static struct __attrdef RocsWgen_val39 = {
  "val39",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval39(iONode node) {
  int defval = xInt( RocsWgen_val39 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val39", defval );
}
static void _setval39(iONode node, int p_val39) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val39", p_val39 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val4
 */
static struct __attrdef RocsWgen_val4 = {
  "val4",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval4(iONode node) {
  int defval = xInt( RocsWgen_val4 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val4", defval );
}
static void _setval4(iONode node, int p_val4) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val4", p_val4 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val40
 */
static struct __attrdef RocsWgen_val40 = {
  "val40",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval40(iONode node) {
  int defval = xInt( RocsWgen_val40 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val40", defval );
}
static void _setval40(iONode node, int p_val40) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val40", p_val40 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val41
 */
static struct __attrdef RocsWgen_val41 = {
  "val41",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval41(iONode node) {
  int defval = xInt( RocsWgen_val41 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val41", defval );
}
static void _setval41(iONode node, int p_val41) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val41", p_val41 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val42
 */
static struct __attrdef RocsWgen_val42 = {
  "val42",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval42(iONode node) {
  int defval = xInt( RocsWgen_val42 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val42", defval );
}
static void _setval42(iONode node, int p_val42) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val42", p_val42 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val43
 */
static struct __attrdef RocsWgen_val43 = {
  "val43",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval43(iONode node) {
  int defval = xInt( RocsWgen_val43 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val43", defval );
}
static void _setval43(iONode node, int p_val43) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val43", p_val43 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val44
 */
static struct __attrdef RocsWgen_val44 = {
  "val44",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval44(iONode node) {
  int defval = xInt( RocsWgen_val44 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val44", defval );
}
static void _setval44(iONode node, int p_val44) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val44", p_val44 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val45
 */
static struct __attrdef RocsWgen_val45 = {
  "val45",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval45(iONode node) {
  int defval = xInt( RocsWgen_val45 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val45", defval );
}
static void _setval45(iONode node, int p_val45) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val45", p_val45 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val46
 */
static struct __attrdef RocsWgen_val46 = {
  "val46",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval46(iONode node) {
  int defval = xInt( RocsWgen_val46 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val46", defval );
}
static void _setval46(iONode node, int p_val46) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val46", p_val46 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val47
 */
static struct __attrdef RocsWgen_val47 = {
  "val47",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval47(iONode node) {
  int defval = xInt( RocsWgen_val47 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val47", defval );
}
static void _setval47(iONode node, int p_val47) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val47", p_val47 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val48
 */
static struct __attrdef RocsWgen_val48 = {
  "val48",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval48(iONode node) {
  int defval = xInt( RocsWgen_val48 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val48", defval );
}
static void _setval48(iONode node, int p_val48) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val48", p_val48 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val49
 */
static struct __attrdef RocsWgen_val49 = {
  "val49",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval49(iONode node) {
  int defval = xInt( RocsWgen_val49 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val49", defval );
}
static void _setval49(iONode node, int p_val49) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val49", p_val49 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val5
 */
static struct __attrdef RocsWgen_val5 = {
  "val5",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval5(iONode node) {
  int defval = xInt( RocsWgen_val5 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val5", defval );
}
static void _setval5(iONode node, int p_val5) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val5", p_val5 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val50
 */
static struct __attrdef RocsWgen_val50 = {
  "val50",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval50(iONode node) {
  int defval = xInt( RocsWgen_val50 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val50", defval );
}
static void _setval50(iONode node, int p_val50) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val50", p_val50 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val6
 */
static struct __attrdef RocsWgen_val6 = {
  "val6",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval6(iONode node) {
  int defval = xInt( RocsWgen_val6 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val6", defval );
}
static void _setval6(iONode node, int p_val6) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val6", p_val6 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val7
 */
static struct __attrdef RocsWgen_val7 = {
  "val7",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval7(iONode node) {
  int defval = xInt( RocsWgen_val7 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val7", defval );
}
static void _setval7(iONode node, int p_val7) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val7", p_val7 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val8
 */
static struct __attrdef RocsWgen_val8 = {
  "val8",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval8(iONode node) {
  int defval = xInt( RocsWgen_val8 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val8", defval );
}
static void _setval8(iONode node, int p_val8) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val8", p_val8 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * val9
 */
static struct __attrdef RocsWgen_val9 = {
  "val9",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getval9(iONode node) {
  int defval = xInt( RocsWgen_val9 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "val9", defval );
}
static void _setval9(iONode node, int p_val9) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "val9", p_val9 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * value
 */
static struct __attrdef RocsWgen_value = {
  "value",  "CV value",  "",  "int",  "0",  "0-255",  False,
};
static int _getvalue(iONode node) {
  int defval = xInt( RocsWgen_value );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "value", defval );
}
static void _setvalue(iONode node, int p_value) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "value", p_value );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * version
 */
static struct __attrdef RocsWgen_version = {
  "version",  "firmware version",  "",  "int",  "0",  "*",  False,
};
static int _getversion(iONode node) {
  int defval = xInt( RocsWgen_version );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_program, node );
  return NodeOp.getInt( node, "version", defval );
}
static void _setversion(iONode node, int p_version) {
  if( node == NULL ) return;
  xNode( RocsWgen_program, node );
  NodeOp.setInt( node, "version", p_version );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[77] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_program.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node program not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node program not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_acc;
  attrList[1] = &RocsWgen_addr;
  attrList[2] = &RocsWgen_cmd;
  attrList[3] = &RocsWgen_cv;
  attrList[4] = &RocsWgen_decaddr;
  attrList[5] = &RocsWgen_eeprom;
  attrList[6] = &RocsWgen_filename;
  attrList[7] = &RocsWgen_identifier;
  attrList[8] = &RocsWgen_iid;
  attrList[9] = &RocsWgen_lncv;
  attrList[10] = &RocsWgen_lncvcmd;
  attrList[11] = &RocsWgen_lntype;
  attrList[12] = &RocsWgen_longaddr;
  attrList[13] = &RocsWgen_manu;
  attrList[14] = &RocsWgen_mode;
  attrList[15] = &RocsWgen_modid;
  attrList[16] = &RocsWgen_pom;
  attrList[17] = &RocsWgen_porttype;
  attrList[18] = &RocsWgen_prod;
  attrList[19] = &RocsWgen_rc;
  attrList[20] = &RocsWgen_rs;
  attrList[21] = &RocsWgen_strval1;
  attrList[22] = &RocsWgen_strval2;
  attrList[23] = &RocsWgen_strval3;
  attrList[24] = &RocsWgen_val1;
  attrList[25] = &RocsWgen_val10;
  attrList[26] = &RocsWgen_val11;
  attrList[27] = &RocsWgen_val12;
  attrList[28] = &RocsWgen_val13;
  attrList[29] = &RocsWgen_val14;
  attrList[30] = &RocsWgen_val15;
  attrList[31] = &RocsWgen_val16;
  attrList[32] = &RocsWgen_val17;
  attrList[33] = &RocsWgen_val18;
  attrList[34] = &RocsWgen_val19;
  attrList[35] = &RocsWgen_val2;
  attrList[36] = &RocsWgen_val20;
  attrList[37] = &RocsWgen_val21;
  attrList[38] = &RocsWgen_val22;
  attrList[39] = &RocsWgen_val23;
  attrList[40] = &RocsWgen_val24;
  attrList[41] = &RocsWgen_val25;
  attrList[42] = &RocsWgen_val26;
  attrList[43] = &RocsWgen_val27;
  attrList[44] = &RocsWgen_val28;
  attrList[45] = &RocsWgen_val29;
  attrList[46] = &RocsWgen_val3;
  attrList[47] = &RocsWgen_val30;
  attrList[48] = &RocsWgen_val31;
  attrList[49] = &RocsWgen_val32;
  attrList[50] = &RocsWgen_val33;
  attrList[51] = &RocsWgen_val34;
  attrList[52] = &RocsWgen_val35;
  attrList[53] = &RocsWgen_val36;
  attrList[54] = &RocsWgen_val37;
  attrList[55] = &RocsWgen_val38;
  attrList[56] = &RocsWgen_val39;
  attrList[57] = &RocsWgen_val4;
  attrList[58] = &RocsWgen_val40;
  attrList[59] = &RocsWgen_val41;
  attrList[60] = &RocsWgen_val42;
  attrList[61] = &RocsWgen_val43;
  attrList[62] = &RocsWgen_val44;
  attrList[63] = &RocsWgen_val45;
  attrList[64] = &RocsWgen_val46;
  attrList[65] = &RocsWgen_val47;
  attrList[66] = &RocsWgen_val48;
  attrList[67] = &RocsWgen_val49;
  attrList[68] = &RocsWgen_val5;
  attrList[69] = &RocsWgen_val50;
  attrList[70] = &RocsWgen_val6;
  attrList[71] = &RocsWgen_val7;
  attrList[72] = &RocsWgen_val8;
  attrList[73] = &RocsWgen_val9;
  attrList[74] = &RocsWgen_value;
  attrList[75] = &RocsWgen_version;
  attrList[76] = NULL;
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


struct __wProgram wProgram = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  38,
  37,
  22,
  7,
  20,
  19,
  13,
  16,
  21,
  12,
  39,
  0,
  46,
  47,
  44,
  17,
  2,
  9,
  10,
  1,
  7,
  6,
  3,
  1,
  9,
  4,
  0,
  5,
  8,
  2,
  6,
  32,
  34,
  36,
  30,
  31,
  33,
  35,
  1,
  0,
  2,
  11,
  15,
  14,
  9,
  10,
  45,
  40,
  5,
  7,
  1,
  6,
  4,
  2,
  3,
  0,
  3,
  2,
  4,
  25,
  52,
  2,
  1,
  0,
  24,
  5,
  1,
  51,
  48,
  53,
  49,
  8,
  26,
  18,
  50,
  43,
  42,
  41,
  23,
  _isacc,
  _setacc,
  _getaddr,
  _setaddr,
  _getcmd,
  _setcmd,
  _getcv,
  _setcv,
  _getdecaddr,
  _setdecaddr,
  _iseeprom,
  _seteeprom,
  _getfilename,
  _setfilename,
  _getidentifier,
  _setidentifier,
  _getiid,
  _setiid,
  _islncv,
  _setlncv,
  _getlncvcmd,
  _setlncvcmd,
  _getlntype,
  _setlntype,
  _islongaddr,
  _setlongaddr,
  _getmanu,
  _setmanu,
  _getmode,
  _setmode,
  _getmodid,
  _setmodid,
  _ispom,
  _setpom,
  _getporttype,
  _setporttype,
  _getprod,
  _setprod,
  _getrc,
  _setrc,
  _getrs,
  _setrs,
  _getstrval1,
  _setstrval1,
  _getstrval2,
  _setstrval2,
  _getstrval3,
  _setstrval3,
  _getval1,
  _setval1,
  _getval10,
  _setval10,
  _getval11,
  _setval11,
  _getval12,
  _setval12,
  _getval13,
  _setval13,
  _getval14,
  _setval14,
  _getval15,
  _setval15,
  _getval16,
  _setval16,
  _getval17,
  _setval17,
  _getval18,
  _setval18,
  _getval19,
  _setval19,
  _getval2,
  _setval2,
  _getval20,
  _setval20,
  _getval21,
  _setval21,
  _getval22,
  _setval22,
  _getval23,
  _setval23,
  _getval24,
  _setval24,
  _getval25,
  _setval25,
  _getval26,
  _setval26,
  _getval27,
  _setval27,
  _getval28,
  _setval28,
  _getval29,
  _setval29,
  _getval3,
  _setval3,
  _getval30,
  _setval30,
  _getval31,
  _setval31,
  _getval32,
  _setval32,
  _getval33,
  _setval33,
  _getval34,
  _setval34,
  _getval35,
  _setval35,
  _getval36,
  _setval36,
  _getval37,
  _setval37,
  _getval38,
  _setval38,
  _getval39,
  _setval39,
  _getval4,
  _setval4,
  _getval40,
  _setval40,
  _getval41,
  _setval41,
  _getval42,
  _setval42,
  _getval43,
  _setval43,
  _getval44,
  _setval44,
  _getval45,
  _setval45,
  _getval46,
  _setval46,
  _getval47,
  _setval47,
  _getval48,
  _setval48,
  _getval49,
  _setval49,
  _getval5,
  _setval5,
  _getval50,
  _setval50,
  _getval6,
  _setval6,
  _getval7,
  _setval7,
  _getval8,
  _setval8,
  _getval9,
  _setval9,
  _getvalue,
  _setvalue,
  _getversion,
  _setversion,
  _node_dump,
};
