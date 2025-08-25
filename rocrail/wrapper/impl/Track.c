/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/Track.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Track
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_tk = {
  "tk",  "None active piece of plan.",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_tk.name;
}
static const char* _node_remark(void) {
  return RocsWgen_tk.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_tk.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_tk.cardinality;
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
  xNode( RocsWgen_tk, node );
  return NodeOp.getStr( node, "blockid", defval );
}
static void _setblockid(iONode node, const char* p_blockid) {
  if( node == NULL ) return;
  xNode( RocsWgen_tk, node );
  NodeOp.setStr( node, "blockid", p_blockid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * counterpartid
 */
static struct __attrdef RocsWgen_counterpartid = {
  "counterpartid",  "",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getcounterpartid(iONode node) {
  const char* defval = xStr( RocsWgen_counterpartid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tk, node );
  return NodeOp.getStr( node, "counterpartid", defval );
}
static void _setcounterpartid(iONode node, const char* p_counterpartid) {
  if( node == NULL ) return;
  xNode( RocsWgen_tk, node );
  NodeOp.setStr( node, "counterpartid", p_counterpartid );
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
  xNode( RocsWgen_tk, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_tk, node );
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
  xNode( RocsWgen_tk, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_tk, node );
  NodeOp.setStr( node, "id", p_id );
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
  xNode( RocsWgen_tk, node );
  return NodeOp.getStr( node, "ori", defval );
}
static void _setori(iONode node, const char* p_ori) {
  if( node == NULL ) return;
  xNode( RocsWgen_tk, node );
  NodeOp.setStr( node, "ori", p_ori );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * tknr
 */
static struct __attrdef RocsWgen_tknr = {
  "tknr",  "Track number.",  "",  "int",  "1",  "0-*",  False,
};
static int _gettknr(iONode node) {
  int defval = xInt( RocsWgen_tknr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tk, node );
  return NodeOp.getInt( node, "tknr", defval );
}
static void _settknr(iONode node, int p_tknr) {
  if( node == NULL ) return;
  xNode( RocsWgen_tk, node );
  NodeOp.setInt( node, "tknr", p_tknr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * type
 */
static struct __attrdef RocsWgen_type = {
  "type",  "",  "",  "string",  "straight",  "straight,curve,dir,dirall,buffer,connector,curve90,concurveright,concurveleft",  False,
};
static const char* _gettype(iONode node) {
  const char* defval = xStr( RocsWgen_type );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tk, node );
  return NodeOp.getStr( node, "type", defval );
}
static void _settype(iONode node, const char* p_type) {
  if( node == NULL ) return;
  xNode( RocsWgen_tk, node );
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
  xNode( RocsWgen_tk, node );
  return NodeOp.getInt( node, "x", defval );
}
static void _setx(iONode node, int p_x) {
  if( node == NULL ) return;
  xNode( RocsWgen_tk, node );
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
  xNode( RocsWgen_tk, node );
  return NodeOp.getInt( node, "y", defval );
}
static void _sety(iONode node, int p_y) {
  if( node == NULL ) return;
  xNode( RocsWgen_tk, node );
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
  xNode( RocsWgen_tk, node );
  return NodeOp.getInt( node, "z", defval );
}
static void _setz(iONode node, int p_z) {
  if( node == NULL ) return;
  xNode( RocsWgen_tk, node );
  NodeOp.setInt( node, "z", p_z );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[11] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_tk.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node tk not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node tk not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_blockid;
  attrList[1] = &RocsWgen_counterpartid;
  attrList[2] = &RocsWgen_desc;
  attrList[3] = &RocsWgen_id;
  attrList[4] = &RocsWgen_ori;
  attrList[5] = &RocsWgen_tknr;
  attrList[6] = &RocsWgen_type;
  attrList[7] = &RocsWgen_x;
  attrList[8] = &RocsWgen_y;
  attrList[9] = &RocsWgen_z;
  attrList[10] = NULL;
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


struct __wTrack wTrack = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "buffer",
  "concurveleft",
  "concurveright",
  "connector",
  "curve",
  "curve90",
  "curvenr",
  "dcurve",
  "dir",
  "dirall",
  "straight",
  "tracknr",
  _getblockid,
  _setblockid,
  _getcounterpartid,
  _setcounterpartid,
  _getdesc,
  _setdesc,
  _getid,
  _setid,
  _getori,
  _setori,
  _gettknr,
  _settknr,
  _gettype,
  _settype,
  _getx,
  _setx,
  _gety,
  _sety,
  _getz,
  _setz,
  _node_dump,
};
