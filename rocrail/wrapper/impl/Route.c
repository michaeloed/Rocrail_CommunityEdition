/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/Route.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Route
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_st = {
  "st",  "A street defines a destination fromone block to another including switch positions.",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_st.name;
}
static const char* _node_remark(void) {
  return RocsWgen_st.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_st.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_st.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bka
 */
static struct __attrdef RocsWgen_bka = {
  "bka",  "From block ID: $ prefix is a NetRocrail ID.",  "",  "string",  "NULL",  "*",  True,
};
static const char* _getbka(iONode node) {
  const char* defval = xStr( RocsWgen_bka );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getStr( node, "bka", defval );
}
static void _setbka(iONode node, const char* p_bka) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setStr( node, "bka", p_bka );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bkaside
 */
static struct __attrdef RocsWgen_bkaside = {
  "bkaside",  "Block side connection; true=+, false=-",  "",  "bool",  "false",  "",  False,
};
static Boolean _isbkaside(iONode node) {
  Boolean defval = xBool( RocsWgen_bkaside );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getBool( node, "bkaside", defval );
}
static void _setbkaside(iONode node, Boolean p_bkaside) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setBool( node, "bkaside", p_bkaside );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bkb
 */
static struct __attrdef RocsWgen_bkb = {
  "bkb",  "To block ID: $ prefix is a NetRocrail ID.",  "",  "string",  "NULL",  "*",  True,
};
static const char* _getbkb(iONode node) {
  const char* defval = xStr( RocsWgen_bkb );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getStr( node, "bkb", defval );
}
static void _setbkb(iONode node, const char* p_bkb) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setStr( node, "bkb", p_bkb );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bkbside
 */
static struct __attrdef RocsWgen_bkbside = {
  "bkbside",  "Block side connection; true=+, false=-",  "",  "bool",  "true",  "",  False,
};
static Boolean _isbkbside(iONode node) {
  Boolean defval = xBool( RocsWgen_bkbside );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getBool( node, "bkbside", defval );
}
static void _setbkbside(iONode node, Boolean p_bkbside) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setBool( node, "bkbside", p_bkbside );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bkc
 */
static struct __attrdef RocsWgen_bkc = {
  "bkc",  "Crossing block: optional incase a block overlaps turnouts used by this route. This is a csv list of blocks.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getbkc(iONode node) {
  const char* defval = xStr( RocsWgen_bkc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getStr( node, "bkc", defval );
}
static void _setbkc(iONode node, const char* p_bkc) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setStr( node, "bkc", p_bkc );
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
  xNode( RocsWgen_st, node );
  return NodeOp.getStr( node, "class", defval );
}
static void _setclass(iONode node, const char* p_class) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
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
  xNode( RocsWgen_st, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setStr( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * commuter
 */
static struct __attrdef RocsWgen_commuter = {
  "commuter",  "Only allow commuter trains.",  "",  "bool",  "false",  "",  False,
};
static Boolean _iscommuter(iONode node) {
  Boolean defval = xBool( RocsWgen_commuter );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getBool( node, "commuter", defval );
}
static void _setcommuter(iONode node, Boolean p_commuter) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setBool( node, "commuter", p_commuter );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * countcars
 */
static struct __attrdef RocsWgen_countcars = {
  "countcars",  "Count number of cars before firing events.",  "",  "string",  "no",  "no,forwards,reverse",  False,
};
static const char* _getcountcars(iONode node) {
  const char* defval = xStr( RocsWgen_countcars );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getStr( node, "countcars", defval );
}
static void _setcountcars(iONode node, const char* p_countcars) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setStr( node, "countcars", p_countcars );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * crossingblocksignals
 */
static struct __attrdef RocsWgen_crossingblocksignals = {
  "crossingblocksignals",  "Set the signals in the crossing blocks according to the from block.",  "",  "bool",  "false",  "",  False,
};
static Boolean _iscrossingblocksignals(iONode node) {
  Boolean defval = xBool( RocsWgen_crossingblocksignals );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getBool( node, "crossingblocksignals", defval );
}
static void _setcrossingblocksignals(iONode node, Boolean p_crossingblocksignals) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setBool( node, "crossingblocksignals", p_crossingblocksignals );
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
  xNode( RocsWgen_st, node );
  return NodeOp.getInt( node, "ctcaddr1", defval );
}
static void _setctcaddr1(iONode node, int p_ctcaddr1) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
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
  xNode( RocsWgen_st, node );
  return NodeOp.getInt( node, "ctcaddr2", defval );
}
static void _setctcaddr2(iONode node, int p_ctcaddr2) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setInt( node, "ctcaddr2", p_ctcaddr2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcaddr3
 */
static struct __attrdef RocsWgen_ctcaddr3 = {
  "ctcaddr3",  "address",  "",  "int",  "0",  "0-*",  True,
};
static int _getctcaddr3(iONode node) {
  int defval = xInt( RocsWgen_ctcaddr3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getInt( node, "ctcaddr3", defval );
}
static void _setctcaddr3(iONode node, int p_ctcaddr3) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setInt( node, "ctcaddr3", p_ctcaddr3 );
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
  xNode( RocsWgen_st, node );
  return NodeOp.getInt( node, "ctcbus1", defval );
}
static void _setctcbus1(iONode node, int p_ctcbus1) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
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
  xNode( RocsWgen_st, node );
  return NodeOp.getInt( node, "ctcbus2", defval );
}
static void _setctcbus2(iONode node, int p_ctcbus2) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setInt( node, "ctcbus2", p_ctcbus2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcbus3
 */
static struct __attrdef RocsWgen_ctcbus3 = {
  "ctcbus3",  "Some systems support more than one bus: SLX",  "",  "int",  "0",  "0-*",  False,
};
static int _getctcbus3(iONode node) {
  int defval = xInt( RocsWgen_ctcbus3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getInt( node, "ctcbus3", defval );
}
static void _setctcbus3(iONode node, int p_ctcbus3) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setInt( node, "ctcbus3", p_ctcbus3 );
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
  xNode( RocsWgen_st, node );
  return NodeOp.getStr( node, "ctciid1", defval );
}
static void _setctciid1(iONode node, const char* p_ctciid1) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
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
  xNode( RocsWgen_st, node );
  return NodeOp.getStr( node, "ctciid2", defval );
}
static void _setctciid2(iONode node, const char* p_ctciid2) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setStr( node, "ctciid2", p_ctciid2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctciid3
 */
static struct __attrdef RocsWgen_ctciid3 = {
  "ctciid3",  "Interface ID.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getctciid3(iONode node) {
  const char* defval = xStr( RocsWgen_ctciid3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getStr( node, "ctciid3", defval );
}
static void _setctciid3(iONode node, const char* p_ctciid3) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setStr( node, "ctciid3", p_ctciid3 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcoutput1
 */
static struct __attrdef RocsWgen_ctcoutput1 = {
  "ctcoutput1",  "CTC Output1",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getctcoutput1(iONode node) {
  const char* defval = xStr( RocsWgen_ctcoutput1 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getStr( node, "ctcoutput1", defval );
}
static void _setctcoutput1(iONode node, const char* p_ctcoutput1) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setStr( node, "ctcoutput1", p_ctcoutput1 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcoutput2
 */
static struct __attrdef RocsWgen_ctcoutput2 = {
  "ctcoutput2",  "CTC Output2",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getctcoutput2(iONode node) {
  const char* defval = xStr( RocsWgen_ctcoutput2 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getStr( node, "ctcoutput2", defval );
}
static void _setctcoutput2(iONode node, const char* p_ctcoutput2) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setStr( node, "ctcoutput2", p_ctcoutput2 );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctcoutput3
 */
static struct __attrdef RocsWgen_ctcoutput3 = {
  "ctcoutput3",  "CTC Output3",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getctcoutput3(iONode node) {
  const char* defval = xStr( RocsWgen_ctcoutput3 );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getStr( node, "ctcoutput3", defval );
}
static void _setctcoutput3(iONode node, const char* p_ctcoutput3) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setStr( node, "ctcoutput3", p_ctcoutput3 );
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
  xNode( RocsWgen_st, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setStr( node, "desc", p_desc );
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
  xNode( RocsWgen_st, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * locid
 */
static struct __attrdef RocsWgen_locid = {
  "locid",  "The loco which has locked this route.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getlocid(iONode node) {
  const char* defval = xStr( RocsWgen_locid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getStr( node, "locid", defval );
}
static void _setlocid(iONode node, const char* p_locid) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setStr( node, "locid", p_locid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * manual
 */
static struct __attrdef RocsWgen_manual = {
  "manual",  "manual controlled route",  "",  "bool",  "false",  "",  False,
};
static Boolean _ismanual(iONode node) {
  Boolean defval = xBool( RocsWgen_manual );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getBool( node, "manual", defval );
}
static void _setmanual(iONode node, Boolean p_manual) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setBool( node, "manual", p_manual );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * maxkmh
 */
static struct __attrdef RocsWgen_maxkmh = {
  "maxkmh",  "Route max. speed in km/h or mph.",  "",  "int",  "0",  "0-*",  False,
};
static int _getmaxkmh(iONode node) {
  int defval = xInt( RocsWgen_maxkmh );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getInt( node, "maxkmh", defval );
}
static void _setmaxkmh(iONode node, int p_maxkmh) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setInt( node, "maxkmh", p_maxkmh );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * maxlen
 */
static struct __attrdef RocsWgen_maxlen = {
  "maxlen",  "Maximal train length allowed for this route.",  "",  "int",  "0",  "0-*",  False,
};
static int _getmaxlen(iONode node) {
  int defval = xInt( RocsWgen_maxlen );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getInt( node, "maxlen", defval );
}
static void _setmaxlen(iONode node, int p_maxlen) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setInt( node, "maxlen", p_maxlen );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * minlen
 */
static struct __attrdef RocsWgen_minlen = {
  "minlen",  "Minimal train length allowed for this route.",  "",  "int",  "0",  "0-*",  False,
};
static int _getminlen(iONode node) {
  int defval = xInt( RocsWgen_minlen );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getInt( node, "minlen", defval );
}
static void _setminlen(iONode node, int p_minlen) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setInt( node, "minlen", p_minlen );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * modid
 */
static struct __attrdef RocsWgen_modid = {
  "modid",  "module ID for internal use only",  "",  "string",  "",  "*",  False,
};
static const char* _getmodid(iONode node) {
  const char* defval = xStr( RocsWgen_modid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getStr( node, "modid", defval );
}
static void _setmodid(iONode node, const char* p_modid) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setStr( node, "modid", p_modid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nocommuter
 */
static struct __attrdef RocsWgen_nocommuter = {
  "nocommuter",  "Disallow commuter trains.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isnocommuter(iONode node) {
  Boolean defval = xBool( RocsWgen_nocommuter );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getBool( node, "nocommuter", defval );
}
static void _setnocommuter(iONode node, Boolean p_nocommuter) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setBool( node, "nocommuter", p_nocommuter );
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
  xNode( RocsWgen_st, node );
  return NodeOp.getStr( node, "ori", defval );
}
static void _setori(iONode node, const char* p_ori) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setStr( node, "ori", p_ori );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * placing
 */
static struct __attrdef RocsWgen_placing = {
  "placing",  "0=both, 1=default 2=swapped",  "",  "int",  "0",  "",  False,
};
static int _getplacing(iONode node) {
  int defval = xInt( RocsWgen_placing );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getInt( node, "placing", defval );
}
static void _setplacing(iONode node, int p_placing) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setInt( node, "placing", p_placing );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * reduceV
 */
static struct __attrdef RocsWgen_reduceV = {
  "reduceV",  "reduce speed by thrown switches",  "",  "bool",  "true",  "",  False,
};
static Boolean _isreduceV(iONode node) {
  Boolean defval = xBool( RocsWgen_reduceV );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getBool( node, "reduceV", defval );
}
static void _setreduceV(iONode node, Boolean p_reduceV) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setBool( node, "reduceV", p_reduceV );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sga
 */
static struct __attrdef RocsWgen_sga = {
  "sga",  "signal pair block a",  "",  "int",  "0",  "",  False,
};
static int _getsga(iONode node) {
  int defval = xInt( RocsWgen_sga );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getInt( node, "sga", defval );
}
static void _setsga(iONode node, int p_sga) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setInt( node, "sga", p_sga );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sgb
 */
static struct __attrdef RocsWgen_sgb = {
  "sgb",  "signal pair block b",  "",  "int",  "0",  "",  False,
};
static int _getsgb(iONode node) {
  int defval = xInt( RocsWgen_sgb );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getInt( node, "sgb", defval );
}
static void _setsgb(iONode node, int p_sgb) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setInt( node, "sgb", p_sgb );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * show
 */
static struct __attrdef RocsWgen_show = {
  "show",  "Visibility flag.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isshow(iONode node) {
  Boolean defval = xBool( RocsWgen_show );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getBool( node, "show", defval );
}
static void _setshow(iONode node, Boolean p_show) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setBool( node, "show", p_show );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * speed
 */
static struct __attrdef RocsWgen_speed = {
  "speed",  "Route speed on departure; overwrites block departure speed if set.",  "",  "string",  "none",  "none,min,cruise,max",  False,
};
static const char* _getspeed(iONode node) {
  const char* defval = xStr( RocsWgen_speed );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getStr( node, "speed", defval );
}
static void _setspeed(iONode node, const char* p_speed) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setStr( node, "speed", p_speed );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * speedpercent
 */
static struct __attrdef RocsWgen_speedpercent = {
  "speedpercent",  "Route speed in percent.",  "%",  "int",  "80",  "0-100",  False,
};
static int _getspeedpercent(iONode node) {
  int defval = xInt( RocsWgen_speedpercent );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getInt( node, "speedpercent", defval );
}
static void _setspeedpercent(iONode node, int p_speedpercent) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setInt( node, "speedpercent", p_speedpercent );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * status
 */
static struct __attrdef RocsWgen_status = {
  "status",  "route status",  "",  "int",  "0",  "",  False,
};
static int _getstatus(iONode node) {
  int defval = xInt( RocsWgen_status );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getInt( node, "status", defval );
}
static void _setstatus(iONode node, int p_status) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setInt( node, "status", p_status );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * swappost
 */
static struct __attrdef RocsWgen_swappost = {
  "swappost",  "swap loco placing at terminating this route",  "",  "bool",  "false",  "",  False,
};
static Boolean _isswappost(iONode node) {
  Boolean defval = xBool( RocsWgen_swappost );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getBool( node, "swappost", defval );
}
static void _setswappost(iONode node, Boolean p_swappost) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setBool( node, "swappost", p_swappost );
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
  xNode( RocsWgen_st, node );
  return NodeOp.getStr( node, "typeperm", defval );
}
static void _settypeperm(iONode node, const char* p_typeperm) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setStr( node, "typeperm", p_typeperm );
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
  xNode( RocsWgen_st, node );
  return NodeOp.getInt( node, "x", defval );
}
static void _setx(iONode node, int p_x) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
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
  xNode( RocsWgen_st, node );
  return NodeOp.getInt( node, "y", defval );
}
static void _sety(iONode node, int p_y) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setInt( node, "y", p_y );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * z
 */
static struct __attrdef RocsWgen_z = {
  "z",  "level for internal use only",  "",  "int",  "0",  "0-*",  False,
};
static int _getz(iONode node) {
  int defval = xInt( RocsWgen_z );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_st, node );
  return NodeOp.getInt( node, "z", defval );
}
static void _setz(iONode node, int p_z) {
  if( node == NULL ) return;
  xNode( RocsWgen_st, node );
  NodeOp.setInt( node, "z", p_z );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * swcmd
 */
static struct __nodedef RocsWgen_swcmd = {
  "swcmd",  "",  False,  "n",};
static iONode _getswcmd(iONode node) {
  xNode( RocsWgen_st, node );
  return NodeOp.findNode( node, "swcmd");
}


static iONode _nextswcmd(iONode node, iONode child) {
  xNode( RocsWgen_st, node );
  return NodeOp.findNextNode( node, child);
}
static void _setswcmd(iONode node, iONode p_swcmd) {
  xNode( RocsWgen_st, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * fbevent
 */
static struct __nodedef RocsWgen_fbevent = {
  "fbevent",  "",  False,  "n",};
static iONode _getfbevent(iONode node) {
  xNode( RocsWgen_st, node );
  return NodeOp.findNode( node, "fbevent");
}


static iONode _nextfbevent(iONode node, iONode child) {
  xNode( RocsWgen_st, node );
  return NodeOp.findNextNode( node, child);
}
static void _setfbevent(iONode node, iONode p_fbevent) {
  xNode( RocsWgen_st, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * actionctrl
 */
static struct __nodedef RocsWgen_actionctrl = {
  "actionctrl",  "",  False,  "n",};
static iONode _getactionctrl(iONode node) {
  xNode( RocsWgen_st, node );
  return NodeOp.findNode( node, "actionctrl");
}


static iONode _nextactionctrl(iONode node, iONode child) {
  xNode( RocsWgen_st, node );
  return NodeOp.findNextNode( node, child);
}
static void _setactionctrl(iONode node, iONode p_actionctrl) {
  xNode( RocsWgen_st, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * incl
 */
static struct __nodedef RocsWgen_incl = {
  "incl",  "",  False,  "n",};
static iONode _getincl(iONode node) {
  xNode( RocsWgen_st, node );
  return NodeOp.findNode( node, "incl");
}


static iONode _nextincl(iONode node, iONode child) {
  xNode( RocsWgen_st, node );
  return NodeOp.findNextNode( node, child);
}
static void _setincl(iONode node, iONode p_incl) {
  xNode( RocsWgen_st, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * excl
 */
static struct __nodedef RocsWgen_excl = {
  "excl",  "",  False,  "n",};
static iONode _getexcl(iONode node) {
  xNode( RocsWgen_st, node );
  return NodeOp.findNode( node, "excl");
}


static iONode _nextexcl(iONode node, iONode child) {
  xNode( RocsWgen_st, node );
  return NodeOp.findNextNode( node, child);
}
static void _setexcl(iONode node, iONode p_excl) {
  xNode( RocsWgen_st, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * stcondition
 */
static struct __nodedef RocsWgen_stcondition = {
  "stcondition",  "",  False,  "n",};
static iONode _getstcondition(iONode node) {
  xNode( RocsWgen_st, node );
  return NodeOp.findNode( node, "stcondition");
}


static iONode _nextstcondition(iONode node, iONode child) {
  xNode( RocsWgen_st, node );
  return NodeOp.findNextNode( node, child);
}
static void _setstcondition(iONode node, iONode p_stcondition) {
  xNode( RocsWgen_st, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * speedcondition
 */
static struct __nodedef RocsWgen_speedcondition = {
  "speedcondition",  "",  False,  "n",};
static iONode _getspeedcondition(iONode node) {
  xNode( RocsWgen_st, node );
  return NodeOp.findNode( node, "speedcondition");
}


static iONode _nextspeedcondition(iONode node, iONode child) {
  xNode( RocsWgen_st, node );
  return NodeOp.findNextNode( node, child);
}
static void _setspeedcondition(iONode node, iONode p_speedcondition) {
  xNode( RocsWgen_st, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[46] = {NULL};
static struct __nodedef* nodeList[8] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_st.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node st not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node st not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_bka;
  attrList[1] = &RocsWgen_bkaside;
  attrList[2] = &RocsWgen_bkb;
  attrList[3] = &RocsWgen_bkbside;
  attrList[4] = &RocsWgen_bkc;
  attrList[5] = &RocsWgen_class;
  attrList[6] = &RocsWgen_cmd;
  attrList[7] = &RocsWgen_commuter;
  attrList[8] = &RocsWgen_countcars;
  attrList[9] = &RocsWgen_crossingblocksignals;
  attrList[10] = &RocsWgen_ctcaddr1;
  attrList[11] = &RocsWgen_ctcaddr2;
  attrList[12] = &RocsWgen_ctcaddr3;
  attrList[13] = &RocsWgen_ctcbus1;
  attrList[14] = &RocsWgen_ctcbus2;
  attrList[15] = &RocsWgen_ctcbus3;
  attrList[16] = &RocsWgen_ctciid1;
  attrList[17] = &RocsWgen_ctciid2;
  attrList[18] = &RocsWgen_ctciid3;
  attrList[19] = &RocsWgen_ctcoutput1;
  attrList[20] = &RocsWgen_ctcoutput2;
  attrList[21] = &RocsWgen_ctcoutput3;
  attrList[22] = &RocsWgen_desc;
  attrList[23] = &RocsWgen_id;
  attrList[24] = &RocsWgen_locid;
  attrList[25] = &RocsWgen_manual;
  attrList[26] = &RocsWgen_maxkmh;
  attrList[27] = &RocsWgen_maxlen;
  attrList[28] = &RocsWgen_minlen;
  attrList[29] = &RocsWgen_modid;
  attrList[30] = &RocsWgen_nocommuter;
  attrList[31] = &RocsWgen_ori;
  attrList[32] = &RocsWgen_placing;
  attrList[33] = &RocsWgen_reduceV;
  attrList[34] = &RocsWgen_sga;
  attrList[35] = &RocsWgen_sgb;
  attrList[36] = &RocsWgen_show;
  attrList[37] = &RocsWgen_speed;
  attrList[38] = &RocsWgen_speedpercent;
  attrList[39] = &RocsWgen_status;
  attrList[40] = &RocsWgen_swappost;
  attrList[41] = &RocsWgen_typeperm;
  attrList[42] = &RocsWgen_x;
  attrList[43] = &RocsWgen_y;
  attrList[44] = &RocsWgen_z;
  attrList[45] = NULL;
  nodeList[0] = &RocsWgen_swcmd;
  nodeList[1] = &RocsWgen_fbevent;
  nodeList[2] = &RocsWgen_actionctrl;
  nodeList[3] = &RocsWgen_incl;
  nodeList[4] = &RocsWgen_excl;
  nodeList[5] = &RocsWgen_stcondition;
  nodeList[6] = &RocsWgen_speedcondition;
  nodeList[7] = NULL;
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


struct __wRoute wRoute = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "none",
  "classadd",
  "classdel",
  "classset",
  "force",
  "forwards",
  "go",
  "auto-generated",
  "no",
  "point-e",
  "point-en",
  "point-enn",
  "point-es",
  "point-ess",
  "point-n",
  "point-ne",
  "point-nee",
  "point-nw",
  "point-nww",
  "point-s",
  "point-se",
  "point-see",
  "point-sw",
  "point-sww",
  "point-w",
  "point-wn",
  "point-wnn",
  "point-ws",
  "point-wss",
  "reverse",
  "--routelock--",
  4,
  3,
  0,
  1,
  2,
  "test",
  _getbka,
  _setbka,
  _isbkaside,
  _setbkaside,
  _getbkb,
  _setbkb,
  _isbkbside,
  _setbkbside,
  _getbkc,
  _setbkc,
  _getclass,
  _setclass,
  _getcmd,
  _setcmd,
  _iscommuter,
  _setcommuter,
  _getcountcars,
  _setcountcars,
  _iscrossingblocksignals,
  _setcrossingblocksignals,
  _getctcaddr1,
  _setctcaddr1,
  _getctcaddr2,
  _setctcaddr2,
  _getctcaddr3,
  _setctcaddr3,
  _getctcbus1,
  _setctcbus1,
  _getctcbus2,
  _setctcbus2,
  _getctcbus3,
  _setctcbus3,
  _getctciid1,
  _setctciid1,
  _getctciid2,
  _setctciid2,
  _getctciid3,
  _setctciid3,
  _getctcoutput1,
  _setctcoutput1,
  _getctcoutput2,
  _setctcoutput2,
  _getctcoutput3,
  _setctcoutput3,
  _getdesc,
  _setdesc,
  _getid,
  _setid,
  _getlocid,
  _setlocid,
  _ismanual,
  _setmanual,
  _getmaxkmh,
  _setmaxkmh,
  _getmaxlen,
  _setmaxlen,
  _getminlen,
  _setminlen,
  _getmodid,
  _setmodid,
  _isnocommuter,
  _setnocommuter,
  _getori,
  _setori,
  _getplacing,
  _setplacing,
  _isreduceV,
  _setreduceV,
  _getsga,
  _setsga,
  _getsgb,
  _setsgb,
  _isshow,
  _setshow,
  _getspeed,
  _setspeed,
  _getspeedpercent,
  _setspeedpercent,
  _getstatus,
  _setstatus,
  _isswappost,
  _setswappost,
  _gettypeperm,
  _settypeperm,
  _getx,
  _setx,
  _gety,
  _sety,
  _getz,
  _setz,
  _getswcmd,
  _nextswcmd,
  _setswcmd,
  _getfbevent,
  _nextfbevent,
  _setfbevent,
  _getactionctrl,
  _nextactionctrl,
  _setactionctrl,
  _getincl,
  _nextincl,
  _setincl,
  _getexcl,
  _nextexcl,
  _setexcl,
  _getstcondition,
  _nextstcondition,
  _setstcondition,
  _getspeedcondition,
  _nextspeedcondition,
  _setspeedcondition,
  _node_dump,
};
