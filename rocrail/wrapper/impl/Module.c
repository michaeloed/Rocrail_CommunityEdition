/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Module.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Module
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_module = {
  "module",  "Module definition",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_module.name;
}
static const char* _node_remark(void) {
  return RocsWgen_module.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_module.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_module.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmd
 */
static struct __attrdef RocsWgen_cmd = {
  "cmd",  "module command from rocgui",  "",  "string",  "",  "*",  False,
};
static const char* _getcmd(iONode node) {
  const char* defval = xStr( RocsWgen_cmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_module, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_module, node );
  NodeOp.setStr( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cx
 */
static struct __attrdef RocsWgen_cx = {
  "cx",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getcx(iONode node) {
  int defval = xInt( RocsWgen_cx );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_module, node );
  return NodeOp.getInt( node, "cx", defval );
}
static void _setcx(iONode node, int p_cx) {
  if( node == NULL ) return;
  xNode( RocsWgen_module, node );
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
  xNode( RocsWgen_module, node );
  return NodeOp.getInt( node, "cy", defval );
}
static void _setcy(iONode node, int p_cy) {
  if( node == NULL ) return;
  xNode( RocsWgen_module, node );
  NodeOp.setInt( node, "cy", p_cy );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * filename
 */
static struct __attrdef RocsWgen_filename = {
  "filename",  "File name of module track plan.",  "",  "string",  "m1.xml",  "*",  False,
};
static const char* _getfilename(iONode node) {
  const char* defval = xStr( RocsWgen_filename );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_module, node );
  return NodeOp.getStr( node, "filename", defval );
}
static void _setfilename(iONode node, const char* p_filename) {
  if( node == NULL ) return;
  xNode( RocsWgen_module, node );
  NodeOp.setStr( node, "filename", p_filename );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "Module ID.",  "",  "string",  "",  "*",  True,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_module, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_module, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * idprefix
 */
static struct __attrdef RocsWgen_idprefix = {
  "idprefix",  "Add a prefix to all objects to make them unique.",  "",  "string",  "",  "*",  False,
};
static const char* _getidprefix(iONode node) {
  const char* defval = xStr( RocsWgen_idprefix );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_module, node );
  return NodeOp.getStr( node, "idprefix", defval );
}
static void _setidprefix(iONode node, const char* p_idprefix) {
  if( node == NULL ) return;
  xNode( RocsWgen_module, node );
  NodeOp.setStr( node, "idprefix", p_idprefix );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nr
 */
static struct __attrdef RocsWgen_nr = {
  "nr",  "Module number.",  "",  "int",  "0",  "0-*",  False,
};
static int _getnr(iONode node) {
  int defval = xInt( RocsWgen_nr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_module, node );
  return NodeOp.getInt( node, "nr", defval );
}
static void _setnr(iONode node, int p_nr) {
  if( node == NULL ) return;
  xNode( RocsWgen_module, node );
  NodeOp.setInt( node, "nr", p_nr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * rotation
 */
static struct __attrdef RocsWgen_rotation = {
  "rotation",  "rotation angle in degrees",  "",  "int",  "0",  "0,90,180,270",  False,
};
static int _getrotation(iONode node) {
  int defval = xInt( RocsWgen_rotation );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_module, node );
  return NodeOp.getInt( node, "rotation", defval );
}
static void _setrotation(iONode node, int p_rotation) {
  if( node == NULL ) return;
  xNode( RocsWgen_module, node );
  NodeOp.setInt( node, "rotation", p_rotation );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * state
 */
static struct __attrdef RocsWgen_state = {
  "state",  "module state",  "",  "string",  "",  "*",  False,
};
static const char* _getstate(iONode node) {
  const char* defval = xStr( RocsWgen_state );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_module, node );
  return NodeOp.getStr( node, "state", defval );
}
static void _setstate(iONode node, const char* p_state) {
  if( node == NULL ) return;
  xNode( RocsWgen_module, node );
  NodeOp.setStr( node, "state", p_state );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * title
 */
static struct __attrdef RocsWgen_title = {
  "title",  "Text to show in the tab.",  "",  "string",  "Rename me!",  "*",  True,
};
static const char* _gettitle(iONode node) {
  const char* defval = xStr( RocsWgen_title );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_module, node );
  return NodeOp.getStr( node, "title", defval );
}
static void _settitle(iONode node, const char* p_title) {
  if( node == NULL ) return;
  xNode( RocsWgen_module, node );
  NodeOp.setStr( node, "title", p_title );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * x
 */
static struct __attrdef RocsWgen_x = {
  "x",  "x position on an overview panel",  "",  "int",  "0",  "0-*",  False,
};
static int _getx(iONode node) {
  int defval = xInt( RocsWgen_x );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_module, node );
  return NodeOp.getInt( node, "x", defval );
}
static void _setx(iONode node, int p_x) {
  if( node == NULL ) return;
  xNode( RocsWgen_module, node );
  NodeOp.setInt( node, "x", p_x );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * y
 */
static struct __attrdef RocsWgen_y = {
  "y",  "y position on an overview panel",  "",  "int",  "0",  "0-*",  False,
};
static int _gety(iONode node) {
  int defval = xInt( RocsWgen_y );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_module, node );
  return NodeOp.getInt( node, "y", defval );
}
static void _sety(iONode node, int p_y) {
  if( node == NULL ) return;
  xNode( RocsWgen_module, node );
  NodeOp.setInt( node, "y", p_y );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * connection
 */
static struct __nodedef RocsWgen_connection = {
  "connection",  "Connection specification",  False,  "n",};
static iONode _getconnection(iONode node) {
  xNode( RocsWgen_module, node );
  return NodeOp.findNode( node, "connection");
}


static iONode _nextconnection(iONode node, iONode child) {
  xNode( RocsWgen_module, node );
  return NodeOp.findNextNode( node, child);
}
static void _setconnection(iONode node, iONode p_connection) {
  xNode( RocsWgen_module, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[13] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_module.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node module not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node module not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_cmd;
  attrList[1] = &RocsWgen_cx;
  attrList[2] = &RocsWgen_cy;
  attrList[3] = &RocsWgen_filename;
  attrList[4] = &RocsWgen_id;
  attrList[5] = &RocsWgen_idprefix;
  attrList[6] = &RocsWgen_nr;
  attrList[7] = &RocsWgen_rotation;
  attrList[8] = &RocsWgen_state;
  attrList[9] = &RocsWgen_title;
  attrList[10] = &RocsWgen_x;
  attrList[11] = &RocsWgen_y;
  attrList[12] = NULL;
  nodeList[0] = &RocsWgen_connection;
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


struct __wModule wModule = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "connect",
  "east",
  "move",
  "north",
  "south",
  "state",
  "west",
  "normal",
  "shortcut",
  _getcmd,
  _setcmd,
  _getcx,
  _setcx,
  _getcy,
  _setcy,
  _getfilename,
  _setfilename,
  _getid,
  _setid,
  _getidprefix,
  _setidprefix,
  _getnr,
  _setnr,
  _getrotation,
  _setrotation,
  _getstate,
  _setstate,
  _gettitle,
  _settitle,
  _getx,
  _setx,
  _gety,
  _sety,
  _getconnection,
  _nextconnection,
  _setconnection,
  _node_dump,
};
