/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/Link.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Link
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_link = {
  "link",  "in case of critsect the src is ignored and all blocks listed in dst are group members",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_link.name;
}
static const char* _node_remark(void) {
  return RocsWgen_link.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_link.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_link.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * active
 */
static struct __attrdef RocsWgen_active = {
  "active",  "Activates links: all blocks are set to manual mode.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isactive(iONode node) {
  Boolean defval = xBool( RocsWgen_active );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_link, node );
  return NodeOp.getBool( node, "active", defval );
}
static void _setactive(iONode node, Boolean p_active) {
  if( node == NULL ) return;
  xNode( RocsWgen_link, node );
  NodeOp.setBool( node, "active", p_active );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * allowfollowup
 */
static struct __attrdef RocsWgen_allowfollowup = {
  "allowfollowup",  "Allow follow up in critsec for the same direction.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isallowfollowup(iONode node) {
  Boolean defval = xBool( RocsWgen_allowfollowup );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_link, node );
  return NodeOp.getBool( node, "allowfollowup", defval );
}
static void _setallowfollowup(iONode node, Boolean p_allowfollowup) {
  if( node == NULL ) return;
  xNode( RocsWgen_link, node );
  NodeOp.setBool( node, "allowfollowup", p_allowfollowup );
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
  xNode( RocsWgen_link, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_link, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * dst
 */
static struct __attrdef RocsWgen_dst = {
  "dst",  "destination blocks; id's in CSV format",  "",  "string",  "",  "*",  True,
};
static const char* _getdst(iONode node) {
  const char* defval = xStr( RocsWgen_dst );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_link, node );
  return NodeOp.getStr( node, "dst", defval );
}
static void _setdst(iONode node, const char* p_dst) {
  if( node == NULL ) return;
  xNode( RocsWgen_link, node );
  NodeOp.setStr( node, "dst", p_dst );
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
  xNode( RocsWgen_link, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_link, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * maxfollowup
 */
static struct __attrdef RocsWgen_maxfollowup = {
  "maxfollowup",  "Max. trains to follow up.",  "",  "int",  "0",  "",  False,
};
static int _getmaxfollowup(iONode node) {
  int defval = xInt( RocsWgen_maxfollowup );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_link, node );
  return NodeOp.getInt( node, "maxfollowup", defval );
}
static void _setmaxfollowup(iONode node, int p_maxfollowup) {
  if( node == NULL ) return;
  xNode( RocsWgen_link, node );
  NodeOp.setInt( node, "maxfollowup", p_maxfollowup );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * src
 */
static struct __attrdef RocsWgen_src = {
  "src",  "source block",  "",  "string",  "",  "*",  True,
};
static const char* _getsrc(iONode node) {
  const char* defval = xStr( RocsWgen_src );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_link, node );
  return NodeOp.getStr( node, "src", defval );
}
static void _setsrc(iONode node, const char* p_src) {
  if( node == NULL ) return;
  xNode( RocsWgen_link, node );
  NodeOp.setStr( node, "src", p_src );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usage
 */
static struct __attrdef RocsWgen_usage = {
  "usage",  "group usage",  "",  "int",  "0",  "*",  False,
};
static int _getusage(iONode node) {
  int defval = xInt( RocsWgen_usage );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_link, node );
  return NodeOp.getInt( node, "usage", defval );
}
static void _setusage(iONode node, int p_usage) {
  if( node == NULL ) return;
  xNode( RocsWgen_link, node );
  NodeOp.setInt( node, "usage", p_usage );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * linkcond
 */
static struct __nodedef RocsWgen_linkcond = {
  "linkcond",  "",  False,  "n",};
static iONode _getlinkcond(iONode node) {
  xNode( RocsWgen_link, node );
  return NodeOp.findNode( node, "linkcond");
}


static iONode _nextlinkcond(iONode node, iONode child) {
  xNode( RocsWgen_link, node );
  return NodeOp.findNextNode( node, child);
}
static void _setlinkcond(iONode node, iONode p_linkcond) {
  xNode( RocsWgen_link, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[9] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_link.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node link not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node link not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_active;
  attrList[1] = &RocsWgen_allowfollowup;
  attrList[2] = &RocsWgen_desc;
  attrList[3] = &RocsWgen_dst;
  attrList[4] = &RocsWgen_id;
  attrList[5] = &RocsWgen_maxfollowup;
  attrList[6] = &RocsWgen_src;
  attrList[7] = &RocsWgen_usage;
  attrList[8] = NULL;
  nodeList[0] = &RocsWgen_linkcond;
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


struct __wLink wLink = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  1,
  0,
  _isactive,
  _setactive,
  _isallowfollowup,
  _setallowfollowup,
  _getdesc,
  _setdesc,
  _getdst,
  _setdst,
  _getid,
  _setid,
  _getmaxfollowup,
  _setmaxfollowup,
  _getsrc,
  _setsrc,
  _getusage,
  _setusage,
  _getlinkcond,
  _nextlinkcond,
  _setlinkcond,
  _node_dump,
};
