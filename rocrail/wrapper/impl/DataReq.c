/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/DataReq.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.DataReq
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_datareq = {
  "datareq",  "Data request",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_datareq.name;
}
static const char* _node_remark(void) {
  return RocsWgen_datareq.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_datareq.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_datareq.cardinality;
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
  xNode( RocsWgen_datareq, node );
  return NodeOp.getInt( node, "cmd", defval );
}
static void _setcmd(iONode node, int p_cmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_datareq, node );
  NodeOp.setInt( node, "cmd", p_cmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * data
 */
static struct __attrdef RocsWgen_data = {
  "data",  "one byte represented by 2 ascii chars; StrOp.byteToStr()",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getdata(iONode node) {
  const char* defval = xStr( RocsWgen_data );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_datareq, node );
  return NodeOp.getStr( node, "data", defval );
}
static void _setdata(iONode node, const char* p_data) {
  if( node == NULL ) return;
  xNode( RocsWgen_datareq, node );
  NodeOp.setStr( node, "data", p_data );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * filename
 */
static struct __attrdef RocsWgen_filename = {
  "filename",  "",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getfilename(iONode node) {
  const char* defval = xStr( RocsWgen_filename );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_datareq, node );
  return NodeOp.getStr( node, "filename", defval );
}
static void _setfilename(iONode node, const char* p_filename) {
  if( node == NULL ) return;
  xNode( RocsWgen_datareq, node );
  NodeOp.setStr( node, "filename", p_filename );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * function
 */
static struct __attrdef RocsWgen_function = {
  "function",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getfunction(iONode node) {
  int defval = xInt( RocsWgen_function );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_datareq, node );
  return NodeOp.getInt( node, "function", defval );
}
static void _setfunction(iONode node, int p_function) {
  if( node == NULL ) return;
  xNode( RocsWgen_datareq, node );
  NodeOp.setInt( node, "function", p_function );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "reference ID",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_datareq, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_datareq, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * type
 */
static struct __attrdef RocsWgen_type = {
  "type",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _gettype(iONode node) {
  int defval = xInt( RocsWgen_type );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_datareq, node );
  return NodeOp.getInt( node, "type", defval );
}
static void _settype(iONode node, int p_type) {
  if( node == NULL ) return;
  xNode( RocsWgen_datareq, node );
  NodeOp.setInt( node, "type", p_type );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * direntry
 */
static struct __nodedef RocsWgen_direntry = {
  "direntry",  "Directory",  False,  "1",};
static iONode _getdirentry(iONode node) {
  xNode( RocsWgen_datareq, node );
  return NodeOp.findNode( node, "direntry");
}


static iONode _nextdirentry(iONode node, iONode child) {
  xNode( RocsWgen_datareq, node );
  return NodeOp.findNextNode( node, child);
}
static void _setdirentry(iONode node, iONode p_direntry) {
  xNode( RocsWgen_datareq, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[7] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_datareq.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node datareq not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node datareq not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_cmd;
  attrList[1] = &RocsWgen_data;
  attrList[2] = &RocsWgen_filename;
  attrList[3] = &RocsWgen_function;
  attrList[4] = &RocsWgen_id;
  attrList[5] = &RocsWgen_type;
  attrList[6] = NULL;
  nodeList[0] = &RocsWgen_direntry;
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


struct __wDataReq wDataReq = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  0,
  1,
  2,
  0,
  1,
  _getcmd,
  _setcmd,
  _getdata,
  _setdata,
  _getfilename,
  _setfilename,
  _getfunction,
  _setfunction,
  _getid,
  _setid,
  _gettype,
  _settype,
  _getdirentry,
  _nextdirentry,
  _setdirentry,
  _node_dump,
};
