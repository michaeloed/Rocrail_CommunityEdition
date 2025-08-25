/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/BinCmd.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.BinCmd
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_bincmd = {
  "bincmd",  "Binary command; the DigInt should send the bytes un-translated to the command station.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_bincmd.name;
}
static const char* _node_remark(void) {
  return RocsWgen_bincmd.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_bincmd.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_bincmd.cardinality;
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
  xNode( RocsWgen_bincmd, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_bincmd, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * inendbyte
 */
static struct __attrdef RocsWgen_inendbyte = {
  "inendbyte",  "Read response until detecting this byte within the inlen.",  "",  "int",  "-1",  "0-*",  False,
};
static int _getinendbyte(iONode node) {
  int defval = xInt( RocsWgen_inendbyte );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bincmd, node );
  return NodeOp.getInt( node, "inendbyte", defval );
}
static void _setinendbyte(iONode node, int p_inendbyte) {
  if( node == NULL ) return;
  xNode( RocsWgen_bincmd, node );
  NodeOp.setInt( node, "inendbyte", p_inendbyte );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * inlen
 */
static struct __attrdef RocsWgen_inlen = {
  "inlen",  "expected response length in bytes",  "",  "int",  "0",  "0-*",  False,
};
static int _getinlen(iONode node) {
  int defval = xInt( RocsWgen_inlen );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bincmd, node );
  return NodeOp.getInt( node, "inlen", defval );
}
static void _setinlen(iONode node, int p_inlen) {
  if( node == NULL ) return;
  xNode( RocsWgen_bincmd, node );
  NodeOp.setInt( node, "inlen", p_inlen );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * out
 */
static struct __attrdef RocsWgen_out = {
  "out",  "one byte represented by 2 ascii chars; StrOp.byteToStr()",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getout(iONode node) {
  const char* defval = xStr( RocsWgen_out );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bincmd, node );
  return NodeOp.getStr( node, "out", defval );
}
static void _setout(iONode node, const char* p_out) {
  if( node == NULL ) return;
  xNode( RocsWgen_bincmd, node );
  NodeOp.setStr( node, "out", p_out );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * outlen
 */
static struct __attrdef RocsWgen_outlen = {
  "outlen",  "out length in bytes",  "",  "int",  "0",  "0-*",  False,
};
static int _getoutlen(iONode node) {
  int defval = xInt( RocsWgen_outlen );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bincmd, node );
  return NodeOp.getInt( node, "outlen", defval );
}
static void _setoutlen(iONode node, int p_outlen) {
  if( node == NULL ) return;
  xNode( RocsWgen_bincmd, node );
  NodeOp.setInt( node, "outlen", p_outlen );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[6] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_bincmd.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node bincmd not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node bincmd not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_iid;
  attrList[1] = &RocsWgen_inendbyte;
  attrList[2] = &RocsWgen_inlen;
  attrList[3] = &RocsWgen_out;
  attrList[4] = &RocsWgen_outlen;
  attrList[5] = NULL;
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


struct __wBinCmd wBinCmd = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getiid,
  _setiid,
  _getinendbyte,
  _setinendbyte,
  _getinlen,
  _setinlen,
  _getout,
  _setout,
  _getoutlen,
  _setoutlen,
  _node_dump,
};
