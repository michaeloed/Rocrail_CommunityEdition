/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Description.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Description
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_description = {
  "description",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_description.name;
}
static const char* _node_remark(void) {
  return RocsWgen_description.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_description.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_description.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lang
 */
static struct __attrdef RocsWgen_lang = {
  "lang",  "Language",  "",  "string",  "",  "*",  False,
};
static const char* _getlang(iONode node) {
  const char* defval = xStr( RocsWgen_lang );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_description, node );
  return NodeOp.getStr( node, "lang", defval );
}
static void _setlang(iONode node, const char* p_lang) {
  if( node == NULL ) return;
  xNode( RocsWgen_description, node );
  NodeOp.setStr( node, "lang", p_lang );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * text
 */
static struct __attrdef RocsWgen_text = {
  "text",  "Description",  "",  "string",  "",  "*",  False,
};
static const char* _gettext(iONode node) {
  const char* defval = xStr( RocsWgen_text );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_description, node );
  return NodeOp.getStr( node, "text", defval );
}
static void _settext(iONode node, const char* p_text) {
  if( node == NULL ) return;
  xNode( RocsWgen_description, node );
  NodeOp.setStr( node, "text", p_text );
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
  xNode( RocsWgen_description, node );
  return NodeOp.getStr( node, "url", defval );
}
static void _seturl(iONode node, const char* p_url) {
  if( node == NULL ) return;
  xNode( RocsWgen_description, node );
  NodeOp.setStr( node, "url", p_url );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[4] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_description.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node description not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node description not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_lang;
  attrList[1] = &RocsWgen_text;
  attrList[2] = &RocsWgen_url;
  attrList[3] = NULL;
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


struct __wDescription wDescription = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getlang,
  _setlang,
  _gettext,
  _settext,
  _geturl,
  _seturl,
  _node_dump,
};
