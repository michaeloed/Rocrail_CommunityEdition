/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Exception.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Exception
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_exception = {
  "exception",  "Exception wrapper",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_exception.name;
}
static const char* _node_remark(void) {
  return RocsWgen_exception.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_exception.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_exception.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * level
 */
static struct __attrdef RocsWgen_level = {
  "level",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getlevel(iONode node) {
  int defval = xInt( RocsWgen_level );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_exception, node );
  return NodeOp.getInt( node, "level", defval );
}
static void _setlevel(iONode node, int p_level) {
  if( node == NULL ) return;
  xNode( RocsWgen_exception, node );
  NodeOp.setInt( node, "level", p_level );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * text
 */
static struct __attrdef RocsWgen_text = {
  "text",  "",  "",  "string",  "",  "*",  False,
};
static const char* _gettext(iONode node) {
  const char* defval = xStr( RocsWgen_text );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_exception, node );
  return NodeOp.getStr( node, "text", defval );
}
static void _settext(iONode node, const char* p_text) {
  if( node == NULL ) return;
  xNode( RocsWgen_exception, node );
  NodeOp.setStr( node, "text", p_text );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[3] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_exception.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node exception not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node exception not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_level;
  attrList[1] = &RocsWgen_text;
  attrList[2] = NULL;
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


struct __wException wException = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getlevel,
  _setlevel,
  _gettext,
  _settext,
  _node_dump,
};
