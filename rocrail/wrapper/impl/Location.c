/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/Location.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Location
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_location = {
  "location",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_location.name;
}
static const char* _node_remark(void) {
  return RocsWgen_location.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_location.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_location.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blocks
 */
static struct __attrdef RocsWgen_blocks = {
  "blocks",  "location related blocks as csv",  "",  "string",  "",  "*",  True,
};
static const char* _getblocks(iONode node) {
  const char* defval = xStr( RocsWgen_blocks );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_location, node );
  return NodeOp.getStr( node, "blocks", defval );
}
static void _setblocks(iONode node, const char* p_blocks) {
  if( node == NULL ) return;
  xNode( RocsWgen_location, node );
  NodeOp.setStr( node, "blocks", p_blocks );
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
  xNode( RocsWgen_location, node );
  return NodeOp.getStr( node, "cmd", defval );
}
static void _setcmd(iONode node, const char* p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_location, node );
  NodeOp.setStr( node, "cmd", p_cmd );
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
  xNode( RocsWgen_location, node );
  return NodeOp.getBool( node, "fifo", defval );
}
static void _setfifo(iONode node, Boolean p_fifo) {
  if( node == NULL ) return;
  xNode( RocsWgen_location, node );
  NodeOp.setBool( node, "fifo", p_fifo );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "location name",  "",  "string",  "",  "*",  True,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_location, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_location, node );
  NodeOp.setStr( node, "id", p_id );
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
  xNode( RocsWgen_location, node );
  return NodeOp.getInt( node, "minocc", defval );
}
static void _setminocc(iONode node, int p_minocc) {
  if( node == NULL ) return;
  xNode( RocsWgen_location, node );
  NodeOp.setInt( node, "minocc", p_minocc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * value
 */
static struct __attrdef RocsWgen_value = {
  "value",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getvalue(iONode node) {
  int defval = xInt( RocsWgen_value );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_location, node );
  return NodeOp.getInt( node, "value", defval );
}
static void _setvalue(iONode node, int p_value) {
  if( node == NULL ) return;
  xNode( RocsWgen_location, node );
  NodeOp.setInt( node, "value", p_value );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[7] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_location.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node location not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node location not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_blocks;
  attrList[1] = &RocsWgen_cmd;
  attrList[2] = &RocsWgen_fifo;
  attrList[3] = &RocsWgen_id;
  attrList[4] = &RocsWgen_minocc;
  attrList[5] = &RocsWgen_value;
  attrList[6] = NULL;
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


struct __wLocation wLocation = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "fifo",
  "minocc",
  _getblocks,
  _setblocks,
  _getcmd,
  _setcmd,
  _isfifo,
  _setfifo,
  _getid,
  _setid,
  _getminocc,
  _setminocc,
  _getvalue,
  _setvalue,
  _node_dump,
};
