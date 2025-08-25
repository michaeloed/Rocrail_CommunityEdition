/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/CVByte.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.CVByte
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_cvbyte = {
  "cvbyte",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_cvbyte.name;
}
static const char* _node_remark(void) {
  return RocsWgen_cvbyte.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_cvbyte.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_cvbyte.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cat
 */
static struct __attrdef RocsWgen_cat = {
  "cat",  "Category",  "",  "string",  "general",  "*",  False,
};
static const char* _getcat(iONode node) {
  const char* defval = xStr( RocsWgen_cat );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cvbyte, node );
  return NodeOp.getStr( node, "cat", defval );
}
static void _setcat(iONode node, const char* p_cat) {
  if( node == NULL ) return;
  xNode( RocsWgen_cvbyte, node );
  NodeOp.setStr( node, "cat", p_cat );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * desc
 */
static struct __attrdef RocsWgen_desc = {
  "desc",  "CV-Description",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getdesc(iONode node) {
  const char* defval = xStr( RocsWgen_desc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cvbyte, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_cvbyte, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * dipid
 */
static struct __attrdef RocsWgen_dipid = {
  "dipid",  "Reference to an existing DIP definition.",  "",  "string",  "",  "*",  False,
};
static const char* _getdipid(iONode node) {
  const char* defval = xStr( RocsWgen_dipid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cvbyte, node );
  return NodeOp.getStr( node, "dipid", defval );
}
static void _setdipid(iONode node, const char* p_dipid) {
  if( node == NULL ) return;
  xNode( RocsWgen_cvbyte, node );
  NodeOp.setStr( node, "dipid", p_dipid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * info
 */
static struct __attrdef RocsWgen_info = {
  "info",  "Info",  "",  "string",  "",  "*",  False,
};
static const char* _getinfo(iONode node) {
  const char* defval = xStr( RocsWgen_info );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cvbyte, node );
  return NodeOp.getStr( node, "info", defval );
}
static void _setinfo(iONode node, const char* p_info) {
  if( node == NULL ) return;
  xNode( RocsWgen_cvbyte, node );
  NodeOp.setStr( node, "info", p_info );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nr
 */
static struct __attrdef RocsWgen_nr = {
  "nr",  "CV-Number",  "",  "int",  "0",  "0-*",  False,
};
static int _getnr(iONode node) {
  int defval = xInt( RocsWgen_nr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cvbyte, node );
  return NodeOp.getInt( node, "nr", defval );
}
static void _setnr(iONode node, int p_nr) {
  if( node == NULL ) return;
  xNode( RocsWgen_cvbyte, node );
  NodeOp.setInt( node, "nr", p_nr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * readonly
 */
static struct __attrdef RocsWgen_readonly = {
  "readonly",  "Disable write operations.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isreadonly(iONode node) {
  Boolean defval = xBool( RocsWgen_readonly );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cvbyte, node );
  return NodeOp.getBool( node, "readonly", defval );
}
static void _setreadonly(iONode node, Boolean p_readonly) {
  if( node == NULL ) return;
  xNode( RocsWgen_cvbyte, node );
  NodeOp.setBool( node, "readonly", p_readonly );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * url
 */
static struct __attrdef RocsWgen_url = {
  "url",  "CV-URL",  "",  "string",  "NULL",  "*",  False,
};
static const char* _geturl(iONode node) {
  const char* defval = xStr( RocsWgen_url );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cvbyte, node );
  return NodeOp.getStr( node, "url", defval );
}
static void _seturl(iONode node, const char* p_url) {
  if( node == NULL ) return;
  xNode( RocsWgen_cvbyte, node );
  NodeOp.setStr( node, "url", p_url );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * value
 */
static struct __attrdef RocsWgen_value = {
  "value",  "CV-Value",  "",  "int",  "0",  "0-*",  False,
};
static int _getvalue(iONode node) {
  int defval = xInt( RocsWgen_value );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cvbyte, node );
  return NodeOp.getInt( node, "value", defval );
}
static void _setvalue(iONode node, int p_value) {
  if( node == NULL ) return;
  xNode( RocsWgen_cvbyte, node );
  NodeOp.setInt( node, "value", p_value );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * word
 */
static struct __attrdef RocsWgen_word = {
  "word",  "16 bit word value",  "",  "bool",  "false",  "",  False,
};
static Boolean _isword(iONode node) {
  Boolean defval = xBool( RocsWgen_word );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cvbyte, node );
  return NodeOp.getBool( node, "word", defval );
}
static void _setword(iONode node, Boolean p_word) {
  if( node == NULL ) return;
  xNode( RocsWgen_cvbyte, node );
  NodeOp.setBool( node, "word", p_word );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * adip
 */
static struct __nodedef RocsWgen_adip = {
  "adip",  "",  False,  "1",};
static iONode _getadip(iONode node) {
  xNode( RocsWgen_cvbyte, node );
  return NodeOp.findNode( node, "adip");
}


static iONode _nextadip(iONode node, iONode child) {
  xNode( RocsWgen_cvbyte, node );
  return NodeOp.findNextNode( node, child);
}
static void _setadip(iONode node, iONode p_adip) {
  xNode( RocsWgen_cvbyte, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[10] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_cvbyte.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node cvbyte not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node cvbyte not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_cat;
  attrList[1] = &RocsWgen_desc;
  attrList[2] = &RocsWgen_dipid;
  attrList[3] = &RocsWgen_info;
  attrList[4] = &RocsWgen_nr;
  attrList[5] = &RocsWgen_readonly;
  attrList[6] = &RocsWgen_url;
  attrList[7] = &RocsWgen_value;
  attrList[8] = &RocsWgen_word;
  attrList[9] = NULL;
  nodeList[0] = &RocsWgen_adip;
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


struct __wCVByte wCVByte = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getcat,
  _setcat,
  _getdesc,
  _setdesc,
  _getdipid,
  _setdipid,
  _getinfo,
  _setinfo,
  _getnr,
  _setnr,
  _isreadonly,
  _setreadonly,
  _geturl,
  _seturl,
  _getvalue,
  _setvalue,
  _isword,
  _setword,
  _getadip,
  _nextadip,
  _setadip,
  _node_dump,
};
