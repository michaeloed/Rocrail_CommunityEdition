/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/Text.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Text
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_tx = {
  "tx",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_tx.name;
}
static const char* _node_remark(void) {
  return RocsWgen_tx.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_tx.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_tx.cardinality;
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
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "addr", defval );
}
static void _setaddr(iONode node, int p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "addr", p_addr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * backblue
 */
static struct __attrdef RocsWgen_backblue = {
  "backblue",  "",  "",  "int",  "-1",  "0-255",  False,
};
static int _getbackblue(iONode node) {
  int defval = xInt( RocsWgen_backblue );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "backblue", defval );
}
static void _setbackblue(iONode node, int p_backblue) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "backblue", p_backblue );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * backgreen
 */
static struct __attrdef RocsWgen_backgreen = {
  "backgreen",  "",  "",  "int",  "-1",  "0-255",  False,
};
static int _getbackgreen(iONode node) {
  int defval = xInt( RocsWgen_backgreen );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "backgreen", defval );
}
static void _setbackgreen(iONode node, int p_backgreen) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "backgreen", p_backgreen );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * backred
 */
static struct __attrdef RocsWgen_backred = {
  "backred",  "",  "",  "int",  "-1",  "0-255",  False,
};
static int _getbackred(iONode node) {
  int defval = xInt( RocsWgen_backred );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "backred", defval );
}
static void _setbackred(iONode node, int p_backred) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "backred", p_backred );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * block
 */
static struct __attrdef RocsWgen_block = {
  "block",  "Block ID from update event.",  "",  "string",  "",  "*",  False,
};
static const char* _getblock(iONode node) {
  const char* defval = xStr( RocsWgen_block );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getStr( node, "block", defval );
}
static void _setblock(iONode node, const char* p_block) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setStr( node, "block", p_block );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blue
 */
static struct __attrdef RocsWgen_blue = {
  "blue",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getblue(iONode node) {
  int defval = xInt( RocsWgen_blue );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "blue", defval );
}
static void _setblue(iONode node, int p_blue) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "blue", p_blue );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bold
 */
static struct __attrdef RocsWgen_bold = {
  "bold",  "",  "",  "bool",  "False",  "",  False,
};
static Boolean _isbold(iONode node) {
  Boolean defval = xBool( RocsWgen_bold );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getBool( node, "bold", defval );
}
static void _setbold(iONode node, Boolean p_bold) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setBool( node, "bold", p_bold );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * border
 */
static struct __attrdef RocsWgen_border = {
  "border",  "",  "",  "bool",  "False",  "",  False,
};
static Boolean _isborder(iONode node) {
  Boolean defval = xBool( RocsWgen_border );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getBool( node, "border", defval );
}
static void _setborder(iONode node, Boolean p_border) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setBool( node, "border", p_border );
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
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "bus", defval );
}
static void _setbus(iONode node, int p_bus) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "bus", p_bus );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * carcount
 */
static struct __attrdef RocsWgen_carcount = {
  "carcount",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getcarcount(iONode node) {
  int defval = xInt( RocsWgen_carcount );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "carcount", defval );
}
static void _setcarcount(iONode node, int p_carcount) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "carcount", p_carcount );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * clock
 */
static struct __attrdef RocsWgen_clock = {
  "clock",  "Is used to show the model time.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isclock(iONode node) {
  Boolean defval = xBool( RocsWgen_clock );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getBool( node, "clock", defval );
}
static void _setclock(iONode node, Boolean p_clock) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setBool( node, "clock", p_clock );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmd
 */
static struct __attrdef RocsWgen_cmd = {
  "cmd",  "update",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getcmd(iONode node) {
  const char* defval = xStr( RocsWgen_cmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setStr( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * countedcars
 */
static struct __attrdef RocsWgen_countedcars = {
  "countedcars",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getcountedcars(iONode node) {
  int defval = xInt( RocsWgen_countedcars );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "countedcars", defval );
}
static void _setcountedcars(iONode node, int p_countedcars) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "countedcars", p_countedcars );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * counter
 */
static struct __attrdef RocsWgen_counter = {
  "counter",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getcounter(iONode node) {
  int defval = xInt( RocsWgen_counter );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "counter", defval );
}
static void _setcounter(iONode node, int p_counter) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "counter", p_counter );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cx
 */
static struct __attrdef RocsWgen_cx = {
  "cx",  "",  "",  "int",  "3",  "1-*",  False,
};
static int _getcx(iONode node) {
  int defval = xInt( RocsWgen_cx );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "cx", defval );
}
static void _setcx(iONode node, int p_cx) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "cx", p_cx );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cy
 */
static struct __attrdef RocsWgen_cy = {
  "cy",  "",  "",  "int",  "1",  "1-*",  False,
};
static int _getcy(iONode node) {
  int defval = xInt( RocsWgen_cy );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "cy", defval );
}
static void _setcy(iONode node, int p_cy) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "cy", p_cy );
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
  xNode( RocsWgen_tx, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * display
 */
static struct __attrdef RocsWgen_display = {
  "display",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getdisplay(iONode node) {
  int defval = xInt( RocsWgen_display );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "display", defval );
}
static void _setdisplay(iONode node, int p_display) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "display", p_display );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * format
 */
static struct __attrdef RocsWgen_format = {
  "format",  "Format string.",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getformat(iONode node) {
  const char* defval = xStr( RocsWgen_format );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getStr( node, "format", defval );
}
static void _setformat(iONode node, const char* p_format) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setStr( node, "format", p_format );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * green
 */
static struct __attrdef RocsWgen_green = {
  "green",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getgreen(iONode node) {
  int defval = xInt( RocsWgen_green );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "green", defval );
}
static void _setgreen(iONode node, int p_green) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "green", p_green );
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
  xNode( RocsWgen_tx, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
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
  xNode( RocsWgen_tx, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * italic
 */
static struct __attrdef RocsWgen_italic = {
  "italic",  "",  "",  "bool",  "False",  "",  False,
};
static Boolean _isitalic(iONode node) {
  Boolean defval = xBool( RocsWgen_italic );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getBool( node, "italic", defval );
}
static void _setitalic(iONode node, Boolean p_italic) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setBool( node, "italic", p_italic );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * load
 */
static struct __attrdef RocsWgen_load = {
  "load",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getload(iONode node) {
  int defval = xInt( RocsWgen_load );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "load", defval );
}
static void _setload(iONode node, int p_load) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "load", p_load );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * location
 */
static struct __attrdef RocsWgen_location = {
  "location",  "Location from update event.",  "",  "string",  "",  "*",  False,
};
static const char* _getlocation(iONode node) {
  const char* defval = xStr( RocsWgen_location );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getStr( node, "location", defval );
}
static void _setlocation(iONode node, const char* p_location) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setStr( node, "location", p_location );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * manualinput
 */
static struct __attrdef RocsWgen_manualinput = {
  "manualinput",  "",  "",  "bool",  "False",  "",  False,
};
static Boolean _ismanualinput(iONode node) {
  Boolean defval = xBool( RocsWgen_manualinput );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getBool( node, "manualinput", defval );
}
static void _setmanualinput(iONode node, Boolean p_manualinput) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setBool( node, "manualinput", p_manualinput );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mvspeed
 */
static struct __attrdef RocsWgen_mvspeed = {
  "mvspeed",  "",  "",  "float",  "0.0",  "*",  False,
};
static double _getmvspeed(iONode node) {
  double defval = xFloat( RocsWgen_mvspeed );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getFloat( node, "mvspeed", defval );
}
static void _setmvspeed(iONode node, double p_mvspeed) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setFloat( node, "mvspeed", p_mvspeed );
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
  xNode( RocsWgen_tx, node );
  return NodeOp.getStr( node, "oid", defval );
}
static void _setoid(iONode node, const char* p_oid) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setStr( node, "oid", p_oid );
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
  xNode( RocsWgen_tx, node );
  return NodeOp.getStr( node, "ori", defval );
}
static void _setori(iONode node, const char* p_ori) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setStr( node, "ori", p_ori );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * pointsize
 */
static struct __attrdef RocsWgen_pointsize = {
  "pointsize",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getpointsize(iONode node) {
  int defval = xInt( RocsWgen_pointsize );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "pointsize", defval );
}
static void _setpointsize(iONode node, int p_pointsize) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "pointsize", p_pointsize );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * prev_id
 */
static struct __attrdef RocsWgen_prev_id = {
  "prev_id",  "in case of an id change this should help to find the original in the table",  "",  "string",  "",  "*",  False,
};
static const char* _getprev_id(iONode node) {
  const char* defval = xStr( RocsWgen_prev_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getStr( node, "prev_id", defval );
}
static void _setprev_id(iONode node, const char* p_prev_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setStr( node, "prev_id", p_prev_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * red
 */
static struct __attrdef RocsWgen_red = {
  "red",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getred(iONode node) {
  int defval = xInt( RocsWgen_red );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "red", defval );
}
static void _setred(iONode node, int p_red) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "red", p_red );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * refbkid
 */
static struct __attrdef RocsWgen_refbkid = {
  "refbkid",  "Reference ID.",  "",  "string",  "",  "*",  False,
};
static const char* _getrefbkid(iONode node) {
  const char* defval = xStr( RocsWgen_refbkid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getStr( node, "refbkid", defval );
}
static void _setrefbkid(iONode node, const char* p_refbkid) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setStr( node, "refbkid", p_refbkid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * reflcid
 */
static struct __attrdef RocsWgen_reflcid = {
  "reflcid",  "Reference ID.",  "",  "string",  "",  "*",  False,
};
static const char* _getreflcid(iONode node) {
  const char* defval = xStr( RocsWgen_reflcid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getStr( node, "reflcid", defval );
}
static void _setreflcid(iONode node, const char* p_reflcid) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setStr( node, "reflcid", p_reflcid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * reset
 */
static struct __attrdef RocsWgen_reset = {
  "reset",  "",  "",  "bool",  "False",  "",  False,
};
static Boolean _isreset(iONode node) {
  Boolean defval = xBool( RocsWgen_reset );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getBool( node, "reset", defval );
}
static void _setreset(iONode node, Boolean p_reset) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setBool( node, "reset", p_reset );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * temp
 */
static struct __attrdef RocsWgen_temp = {
  "temp",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _gettemp(iONode node) {
  int defval = xInt( RocsWgen_temp );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "temp", defval );
}
static void _settemp(iONode node, int p_temp) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "temp", p_temp );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * text
 */
static struct __attrdef RocsWgen_text = {
  "text",  "Text or Image (if ending on .png) to be displayed.",  "",  "string",  "",  "*",  True,
};
static const char* _gettext(iONode node) {
  const char* defval = xStr( RocsWgen_text );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getStr( node, "text", defval );
}
static void _settext(iONode node, const char* p_text) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setStr( node, "text", p_text );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * transparent
 */
static struct __attrdef RocsWgen_transparent = {
  "transparent",  "",  "",  "bool",  "True",  "",  False,
};
static Boolean _istransparent(iONode node) {
  Boolean defval = xBool( RocsWgen_transparent );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getBool( node, "transparent", defval );
}
static void _settransparent(iONode node, Boolean p_transparent) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setBool( node, "transparent", p_transparent );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * underlined
 */
static struct __attrdef RocsWgen_underlined = {
  "underlined",  "",  "",  "bool",  "False",  "",  False,
};
static Boolean _isunderlined(iONode node) {
  Boolean defval = xBool( RocsWgen_underlined );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getBool( node, "underlined", defval );
}
static void _setunderlined(iONode node, Boolean p_underlined) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setBool( node, "underlined", p_underlined );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * volt
 */
static struct __attrdef RocsWgen_volt = {
  "volt",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getvolt(iONode node) {
  int defval = xInt( RocsWgen_volt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "volt", defval );
}
static void _setvolt(iONode node, int p_volt) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "volt", p_volt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * wheelcount
 */
static struct __attrdef RocsWgen_wheelcount = {
  "wheelcount",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getwheelcount(iONode node) {
  int defval = xInt( RocsWgen_wheelcount );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "wheelcount", defval );
}
static void _setwheelcount(iONode node, int p_wheelcount) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "wheelcount", p_wheelcount );
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
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "x", defval );
}
static void _setx(iONode node, int p_x) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
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
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "y", defval );
}
static void _sety(iONode node, int p_y) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
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
  xNode( RocsWgen_tx, node );
  return NodeOp.getInt( node, "z", defval );
}
static void _setz(iONode node, int p_z) {
  if( node == NULL ) return;
  xNode( RocsWgen_tx, node );
  NodeOp.setInt( node, "z", p_z );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * actionctrl
 */
static struct __nodedef RocsWgen_actionctrl = {
  "actionctrl",  "",  False,  "n",};
static iONode _getactionctrl(iONode node) {
  xNode( RocsWgen_tx, node );
  return NodeOp.findNode( node, "actionctrl");
}


static iONode _nextactionctrl(iONode node, iONode child) {
  xNode( RocsWgen_tx, node );
  return NodeOp.findNextNode( node, child);
}
static void _setactionctrl(iONode node, iONode p_actionctrl) {
  xNode( RocsWgen_tx, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[45] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_tx.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node tx not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node tx not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_addr;
  attrList[1] = &RocsWgen_backblue;
  attrList[2] = &RocsWgen_backgreen;
  attrList[3] = &RocsWgen_backred;
  attrList[4] = &RocsWgen_block;
  attrList[5] = &RocsWgen_blue;
  attrList[6] = &RocsWgen_bold;
  attrList[7] = &RocsWgen_border;
  attrList[8] = &RocsWgen_bus;
  attrList[9] = &RocsWgen_carcount;
  attrList[10] = &RocsWgen_clock;
  attrList[11] = &RocsWgen_cmd;
  attrList[12] = &RocsWgen_countedcars;
  attrList[13] = &RocsWgen_counter;
  attrList[14] = &RocsWgen_cx;
  attrList[15] = &RocsWgen_cy;
  attrList[16] = &RocsWgen_desc;
  attrList[17] = &RocsWgen_display;
  attrList[18] = &RocsWgen_format;
  attrList[19] = &RocsWgen_green;
  attrList[20] = &RocsWgen_id;
  attrList[21] = &RocsWgen_iid;
  attrList[22] = &RocsWgen_italic;
  attrList[23] = &RocsWgen_load;
  attrList[24] = &RocsWgen_location;
  attrList[25] = &RocsWgen_manualinput;
  attrList[26] = &RocsWgen_mvspeed;
  attrList[27] = &RocsWgen_oid;
  attrList[28] = &RocsWgen_ori;
  attrList[29] = &RocsWgen_pointsize;
  attrList[30] = &RocsWgen_prev_id;
  attrList[31] = &RocsWgen_red;
  attrList[32] = &RocsWgen_refbkid;
  attrList[33] = &RocsWgen_reflcid;
  attrList[34] = &RocsWgen_reset;
  attrList[35] = &RocsWgen_temp;
  attrList[36] = &RocsWgen_text;
  attrList[37] = &RocsWgen_transparent;
  attrList[38] = &RocsWgen_underlined;
  attrList[39] = &RocsWgen_volt;
  attrList[40] = &RocsWgen_wheelcount;
  attrList[41] = &RocsWgen_x;
  attrList[42] = &RocsWgen_y;
  attrList[43] = &RocsWgen_z;
  attrList[44] = NULL;
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


struct __wText wText = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getaddr,
  _setaddr,
  _getbackblue,
  _setbackblue,
  _getbackgreen,
  _setbackgreen,
  _getbackred,
  _setbackred,
  _getblock,
  _setblock,
  _getblue,
  _setblue,
  _isbold,
  _setbold,
  _isborder,
  _setborder,
  _getbus,
  _setbus,
  _getcarcount,
  _setcarcount,
  _isclock,
  _setclock,
  _getcmd,
  _setcmd,
  _getcountedcars,
  _setcountedcars,
  _getcounter,
  _setcounter,
  _getcx,
  _setcx,
  _getcy,
  _setcy,
  _getdesc,
  _setdesc,
  _getdisplay,
  _setdisplay,
  _getformat,
  _setformat,
  _getgreen,
  _setgreen,
  _getid,
  _setid,
  _getiid,
  _setiid,
  _isitalic,
  _setitalic,
  _getload,
  _setload,
  _getlocation,
  _setlocation,
  _ismanualinput,
  _setmanualinput,
  _getmvspeed,
  _setmvspeed,
  _getoid,
  _setoid,
  _getori,
  _setori,
  _getpointsize,
  _setpointsize,
  _getprev_id,
  _setprev_id,
  _getred,
  _setred,
  _getrefbkid,
  _setrefbkid,
  _getreflcid,
  _setreflcid,
  _isreset,
  _setreset,
  _gettemp,
  _settemp,
  _gettext,
  _settext,
  _istransparent,
  _settransparent,
  _isunderlined,
  _setunderlined,
  _getvolt,
  _setvolt,
  _getwheelcount,
  _setwheelcount,
  _getx,
  _setx,
  _gety,
  _sety,
  _getz,
  _setz,
  _getactionctrl,
  _nextactionctrl,
  _setactionctrl,
  _node_dump,
};
