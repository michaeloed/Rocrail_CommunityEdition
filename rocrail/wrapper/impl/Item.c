/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Item.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Item
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_item = {
  "item",  "Message to change type, position and orientation of an item.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_item.name;
}
static const char* _node_remark(void) {
  return RocsWgen_item.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_item.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_item.cardinality;
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
  xNode( RocsWgen_item, node );
  return NodeOp.getInt( node, "addr", defval );
}
static void _setaddr(iONode node, int p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setInt( node, "addr", p_addr );
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
  xNode( RocsWgen_item, node );
  return NodeOp.getStr( node, "blockid", defval );
}
static void _setblockid(iONode node, const char* p_blockid) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setStr( node, "blockid", p_blockid );
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
  xNode( RocsWgen_item, node );
  return NodeOp.getInt( node, "bus", defval );
}
static void _setbus(iONode node, int p_bus) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setInt( node, "bus", p_bus );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * copy
 */
static struct __attrdef RocsWgen_copy = {
  "copy",  "Copy marker for clients.",  "",  "bool",  "false",  "",  False,
};
static Boolean _iscopy(iONode node) {
  Boolean defval = xBool( RocsWgen_copy );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_item, node );
  return NodeOp.getBool( node, "copy", defval );
}
static void _setcopy(iONode node, Boolean p_copy) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setBool( node, "copy", p_copy );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cx
 */
static struct __attrdef RocsWgen_cx = {
  "cx",  "Zero means not set; use default symbol size.",  "",  "int",  "0",  "0-*",  False,
};
static int _getcx(iONode node) {
  int defval = xInt( RocsWgen_cx );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_item, node );
  return NodeOp.getInt( node, "cx", defval );
}
static void _setcx(iONode node, int p_cx) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setInt( node, "cx", p_cx );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cy
 */
static struct __attrdef RocsWgen_cy = {
  "cy",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getcy(iONode node) {
  int defval = xInt( RocsWgen_cy );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_item, node );
  return NodeOp.getInt( node, "cy", defval );
}
static void _setcy(iONode node, int p_cy) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
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
  xNode( RocsWgen_item, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
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
  xNode( RocsWgen_item, node );
  return NodeOp.getBool( node, "dir", defval );
}
static void _setdir(iONode node, Boolean p_dir) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setBool( node, "dir", p_dir );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * generated
 */
static struct __attrdef RocsWgen_generated = {
  "generated",  "On the fly generated for an unknown address. Triggered by a client.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isgenerated(iONode node) {
  Boolean defval = xBool( RocsWgen_generated );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_item, node );
  return NodeOp.getBool( node, "generated", defval );
}
static void _setgenerated(iONode node, Boolean p_generated) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setBool( node, "generated", p_generated );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_item, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
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
  xNode( RocsWgen_item, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * len
 */
static struct __attrdef RocsWgen_len = {
  "len",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getlen(iONode node) {
  int defval = xInt( RocsWgen_len );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_item, node );
  return NodeOp.getInt( node, "len", defval );
}
static void _setlen(iONode node, int p_len) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setInt( node, "len", p_len );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * name
 */
static struct __attrdef RocsWgen_name = {
  "name",  "",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getname(iONode node) {
  const char* defval = xStr( RocsWgen_name );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_item, node );
  return NodeOp.getStr( node, "name", defval );
}
static void _setname(iONode node, const char* p_name) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setStr( node, "name", p_name );
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
  xNode( RocsWgen_item, node );
  return NodeOp.getStr( node, "oid", defval );
}
static void _setoid(iONode node, const char* p_oid) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
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
  xNode( RocsWgen_item, node );
  return NodeOp.getStr( node, "ori", defval );
}
static void _setori(iONode node, const char* p_ori) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setStr( node, "ori", p_ori );
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
  xNode( RocsWgen_item, node );
  return NodeOp.getStr( node, "prev_id", defval );
}
static void _setprev_id(iONode node, const char* p_prev_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setStr( node, "prev_id", p_prev_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * prev_ori
 */
static struct __attrdef RocsWgen_prev_ori = {
  "prev_ori",  "",  "",  "string",  "NULL",  "north,south,west,east",  False,
};
static const char* _getprev_ori(iONode node) {
  const char* defval = xStr( RocsWgen_prev_ori );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_item, node );
  return NodeOp.getStr( node, "prev_ori", defval );
}
static void _setprev_ori(iONode node, const char* p_prev_ori) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setStr( node, "prev_ori", p_prev_ori );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * prev_x
 */
static struct __attrdef RocsWgen_prev_x = {
  "prev_x",  "x position before rotation",  "",  "int",  "0",  "0-*",  False,
};
static int _getprev_x(iONode node) {
  int defval = xInt( RocsWgen_prev_x );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_item, node );
  return NodeOp.getInt( node, "prev_x", defval );
}
static void _setprev_x(iONode node, int p_prev_x) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setInt( node, "prev_x", p_prev_x );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * prev_y
 */
static struct __attrdef RocsWgen_prev_y = {
  "prev_y",  "y position before rotation",  "",  "int",  "0",  "0-*",  False,
};
static int _getprev_y(iONode node) {
  int defval = xInt( RocsWgen_prev_y );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_item, node );
  return NodeOp.getInt( node, "prev_y", defval );
}
static void _setprev_y(iONode node, int p_prev_y) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setInt( node, "prev_y", p_prev_y );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * road
 */
static struct __attrdef RocsWgen_road = {
  "road",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isroad(iONode node) {
  Boolean defval = xBool( RocsWgen_road );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_item, node );
  return NodeOp.getBool( node, "road", defval );
}
static void _setroad(iONode node, Boolean p_road) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setBool( node, "road", p_road );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * routeids
 */
static struct __attrdef RocsWgen_routeids = {
  "routeids",  "comma separated list of route ids used to show a special route representation",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getrouteids(iONode node) {
  const char* defval = xStr( RocsWgen_routeids );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_item, node );
  return NodeOp.getStr( node, "routeids", defval );
}
static void _setrouteids(iONode node, const char* p_routeids) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setStr( node, "routeids", p_routeids );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * show
 */
static struct __attrdef RocsWgen_show = {
  "show",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isshow(iONode node) {
  Boolean defval = xBool( RocsWgen_show );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_item, node );
  return NodeOp.getBool( node, "show", defval );
}
static void _setshow(iONode node, Boolean p_show) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setBool( node, "show", p_show );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * state
 */
static struct __attrdef RocsWgen_state = {
  "state",  "",  "",  "string",  "-",  "",  False,
};
static const char* _getstate(iONode node) {
  const char* defval = xStr( RocsWgen_state );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_item, node );
  return NodeOp.getStr( node, "state", defval );
}
static void _setstate(iONode node, const char* p_state) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setStr( node, "state", p_state );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * type
 */
static struct __attrdef RocsWgen_type = {
  "type",  "",  "",  "string",  "NULL",  "*",  False,
};
static const char* _gettype(iONode node) {
  const char* defval = xStr( RocsWgen_type );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_item, node );
  return NodeOp.getStr( node, "type", defval );
}
static void _settype(iONode node, const char* p_type) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setStr( node, "type", p_type );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * uidname
 */
static struct __attrdef RocsWgen_uidname = {
  "uidname",  "Alternative to the UID.(Bus)",  "",  "string",  "",  "*",  False,
};
static const char* _getuidname(iONode node) {
  const char* defval = xStr( RocsWgen_uidname );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_item, node );
  return NodeOp.getStr( node, "uidname", defval );
}
static void _setuidname(iONode node, const char* p_uidname) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setStr( node, "uidname", p_uidname );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * x
 */
static struct __attrdef RocsWgen_x = {
  "x",  "",  "",  "int",  "-1",  "0-*",  False,
};
static int _getx(iONode node) {
  int defval = xInt( RocsWgen_x );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_item, node );
  return NodeOp.getInt( node, "x", defval );
}
static void _setx(iONode node, int p_x) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setInt( node, "x", p_x );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * y
 */
static struct __attrdef RocsWgen_y = {
  "y",  "",  "",  "int",  "-1",  "0-*",  False,
};
static int _gety(iONode node) {
  int defval = xInt( RocsWgen_y );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_item, node );
  return NodeOp.getInt( node, "y", defval );
}
static void _sety(iONode node, int p_y) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
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
  xNode( RocsWgen_item, node );
  return NodeOp.getInt( node, "z", defval );
}
static void _setz(iONode node, int p_z) {
  if( node == NULL ) return;
  xNode( RocsWgen_item, node );
  NodeOp.setInt( node, "z", p_z );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[29] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_item.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node item not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node item not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_addr;
  attrList[1] = &RocsWgen_blockid;
  attrList[2] = &RocsWgen_bus;
  attrList[3] = &RocsWgen_copy;
  attrList[4] = &RocsWgen_cx;
  attrList[5] = &RocsWgen_cy;
  attrList[6] = &RocsWgen_desc;
  attrList[7] = &RocsWgen_dir;
  attrList[8] = &RocsWgen_generated;
  attrList[9] = &RocsWgen_id;
  attrList[10] = &RocsWgen_iid;
  attrList[11] = &RocsWgen_len;
  attrList[12] = &RocsWgen_name;
  attrList[13] = &RocsWgen_oid;
  attrList[14] = &RocsWgen_ori;
  attrList[15] = &RocsWgen_prev_id;
  attrList[16] = &RocsWgen_prev_ori;
  attrList[17] = &RocsWgen_prev_x;
  attrList[18] = &RocsWgen_prev_y;
  attrList[19] = &RocsWgen_road;
  attrList[20] = &RocsWgen_routeids;
  attrList[21] = &RocsWgen_show;
  attrList[22] = &RocsWgen_state;
  attrList[23] = &RocsWgen_type;
  attrList[24] = &RocsWgen_uidname;
  attrList[25] = &RocsWgen_x;
  attrList[26] = &RocsWgen_y;
  attrList[27] = &RocsWgen_z;
  attrList[28] = NULL;
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


struct __wItem wItem = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "east",
  "north",
  "south",
  "west",
  _getaddr,
  _setaddr,
  _getblockid,
  _setblockid,
  _getbus,
  _setbus,
  _iscopy,
  _setcopy,
  _getcx,
  _setcx,
  _getcy,
  _setcy,
  _getdesc,
  _setdesc,
  _isdir,
  _setdir,
  _isgenerated,
  _setgenerated,
  _getid,
  _setid,
  _getiid,
  _setiid,
  _getlen,
  _setlen,
  _getname,
  _setname,
  _getoid,
  _setoid,
  _getori,
  _setori,
  _getprev_id,
  _setprev_id,
  _getprev_ori,
  _setprev_ori,
  _getprev_x,
  _setprev_x,
  _getprev_y,
  _setprev_y,
  _isroad,
  _setroad,
  _getrouteids,
  _setrouteids,
  _isshow,
  _setshow,
  _getstate,
  _setstate,
  _gettype,
  _settype,
  _getuidname,
  _setuidname,
  _getx,
  _setx,
  _gety,
  _sety,
  _getz,
  _setz,
  _node_dump,
};
