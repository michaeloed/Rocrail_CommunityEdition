/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Product.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Product
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_product = {
  "product",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_product.name;
}
static const char* _node_remark(void) {
  return RocsWgen_product.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_product.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_product.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cid
 */
static struct __attrdef RocsWgen_cid = {
  "cid",  "Class ID",  "",  "int",  "0",  "0-*",  False,
};
static int _getcid(iONode node) {
  int defval = xInt( RocsWgen_cid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_product, node );
  return NodeOp.getInt( node, "cid", defval );
}
static void _setcid(iONode node, int p_cid) {
  if( node == NULL ) return;
  xNode( RocsWgen_product, node );
  NodeOp.setInt( node, "cid", p_cid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cidext
 */
static struct __attrdef RocsWgen_cidext = {
  "cidext",  "Class ID extension",  "",  "int",  "0",  "0-*",  False,
};
static int _getcidext(iONode node) {
  int defval = xInt( RocsWgen_cidext );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_product, node );
  return NodeOp.getInt( node, "cidext", defval );
}
static void _setcidext(iONode node, int p_cidext) {
  if( node == NULL ) return;
  xNode( RocsWgen_product, node );
  NodeOp.setInt( node, "cidext", p_cidext );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * desc
 */
static struct __attrdef RocsWgen_desc = {
  "desc",  "Description",  "",  "string",  "",  "*",  False,
};
static const char* _getdesc(iONode node) {
  const char* defval = xStr( RocsWgen_desc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_product, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_product, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * pid
 */
static struct __attrdef RocsWgen_pid = {
  "pid",  "Product ID",  "",  "int",  "0",  "0-*",  False,
};
static int _getpid(iONode node) {
  int defval = xInt( RocsWgen_pid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_product, node );
  return NodeOp.getInt( node, "pid", defval );
}
static void _setpid(iONode node, int p_pid) {
  if( node == NULL ) return;
  xNode( RocsWgen_product, node );
  NodeOp.setInt( node, "pid", p_pid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sid
 */
static struct __attrdef RocsWgen_sid = {
  "sid",  "System ID",  "",  "int",  "0",  "0-*",  False,
};
static int _getsid(iONode node) {
  int defval = xInt( RocsWgen_sid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_product, node );
  return NodeOp.getInt( node, "sid", defval );
}
static void _setsid(iONode node, int p_sid) {
  if( node == NULL ) return;
  xNode( RocsWgen_product, node );
  NodeOp.setInt( node, "sid", p_sid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * url
 */
static struct __attrdef RocsWgen_url = {
  "url",  "Documentation URL",  "",  "string",  "",  "*",  False,
};
static const char* _geturl(iONode node) {
  const char* defval = xStr( RocsWgen_url );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_product, node );
  return NodeOp.getStr( node, "url", defval );
}
static void _seturl(iONode node, const char* p_url) {
  if( node == NULL ) return;
  xNode( RocsWgen_product, node );
  NodeOp.setStr( node, "url", p_url );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * vid
 */
static struct __attrdef RocsWgen_vid = {
  "vid",  "Vendor ID",  "",  "int",  "0",  "0-*",  False,
};
static int _getvid(iONode node) {
  int defval = xInt( RocsWgen_vid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_product, node );
  return NodeOp.getInt( node, "vid", defval );
}
static void _setvid(iONode node, int p_vid) {
  if( node == NULL ) return;
  xNode( RocsWgen_product, node );
  NodeOp.setInt( node, "vid", p_vid );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * description
 */
static struct __nodedef RocsWgen_description = {
  "description",  "",  False,  "n",};
static iONode _getdescription(iONode node) {
  xNode( RocsWgen_product, node );
  return NodeOp.findNode( node, "description");
}


static iONode _nextdescription(iONode node, iONode child) {
  xNode( RocsWgen_product, node );
  return NodeOp.findNextNode( node, child);
}
static void _setdescription(iONode node, iONode p_description) {
  xNode( RocsWgen_product, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[8] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_product.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node product not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node product not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_cid;
  attrList[1] = &RocsWgen_cidext;
  attrList[2] = &RocsWgen_desc;
  attrList[3] = &RocsWgen_pid;
  attrList[4] = &RocsWgen_sid;
  attrList[5] = &RocsWgen_url;
  attrList[6] = &RocsWgen_vid;
  attrList[7] = NULL;
  nodeList[0] = &RocsWgen_description;
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


struct __wProduct wProduct = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getcid,
  _setcid,
  _getcidext,
  _setcidext,
  _getdesc,
  _setdesc,
  _getpid,
  _setpid,
  _getsid,
  _setsid,
  _geturl,
  _seturl,
  _getvid,
  _setvid,
  _getdescription,
  _nextdescription,
  _setdescription,
  _node_dump,
};
