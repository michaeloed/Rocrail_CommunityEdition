/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Issue.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Issue
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_issue = {
  "issue",  "Server issue report.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_issue.name;
}
static const char* _node_remark(void) {
  return RocsWgen_issue.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_issue.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_issue.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * currenttrc
 */
static struct __attrdef RocsWgen_currenttrc = {
  "currenttrc",  "Current trace only.",  "",  "bool",  "false",  "",  False,
};
static Boolean _iscurrenttrc(iONode node) {
  Boolean defval = xBool( RocsWgen_currenttrc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_issue, node );
  return NodeOp.getBool( node, "currenttrc", defval );
}
static void _setcurrenttrc(iONode node, Boolean p_currenttrc) {
  if( node == NULL ) return;
  xNode( RocsWgen_issue, node );
  NodeOp.setBool( node, "currenttrc", p_currenttrc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * desc
 */
static struct __attrdef RocsWgen_desc = {
  "desc",  "Description of the issue; UTF-8",  "",  "string",  "",  "",  False,
};
static const char* _getdesc(iONode node) {
  const char* defval = xStr( RocsWgen_desc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_issue, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_issue, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ini
 */
static struct __attrdef RocsWgen_ini = {
  "ini",  "Include rocrail.ini.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isini(iONode node) {
  Boolean defval = xBool( RocsWgen_ini );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_issue, node );
  return NodeOp.getBool( node, "ini", defval );
}
static void _setini(iONode node, Boolean p_ini) {
  if( node == NULL ) return;
  xNode( RocsWgen_issue, node );
  NodeOp.setBool( node, "ini", p_ini );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * stat
 */
static struct __attrdef RocsWgen_stat = {
  "stat",  "Include server statistics.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isstat(iONode node) {
  Boolean defval = xBool( RocsWgen_stat );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_issue, node );
  return NodeOp.getBool( node, "stat", defval );
}
static void _setstat(iONode node, Boolean p_stat) {
  if( node == NULL ) return;
  xNode( RocsWgen_issue, node );
  NodeOp.setBool( node, "stat", p_stat );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * subject
 */
static struct __attrdef RocsWgen_subject = {
  "subject",  "Subject of the issue; 7bit ASCII",  "",  "string",  "",  "",  False,
};
static const char* _getsubject(iONode node) {
  const char* defval = xStr( RocsWgen_subject );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_issue, node );
  return NodeOp.getStr( node, "subject", defval );
}
static void _setsubject(iONode node, const char* p_subject) {
  if( node == NULL ) return;
  xNode( RocsWgen_issue, node );
  NodeOp.setStr( node, "subject", p_subject );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * trc
 */
static struct __attrdef RocsWgen_trc = {
  "trc",  "Include all traces.",  "",  "bool",  "true",  "",  False,
};
static Boolean _istrc(iONode node) {
  Boolean defval = xBool( RocsWgen_trc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_issue, node );
  return NodeOp.getBool( node, "trc", defval );
}
static void _settrc(iONode node, Boolean p_trc) {
  if( node == NULL ) return;
  xNode( RocsWgen_issue, node );
  NodeOp.setBool( node, "trc", p_trc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * xml
 */
static struct __attrdef RocsWgen_xml = {
  "xml",  "Include all definitions.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isxml(iONode node) {
  Boolean defval = xBool( RocsWgen_xml );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_issue, node );
  return NodeOp.getBool( node, "xml", defval );
}
static void _setxml(iONode node, Boolean p_xml) {
  if( node == NULL ) return;
  xNode( RocsWgen_issue, node );
  NodeOp.setBool( node, "xml", p_xml );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[8] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_issue.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node issue not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node issue not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_currenttrc;
  attrList[1] = &RocsWgen_desc;
  attrList[2] = &RocsWgen_ini;
  attrList[3] = &RocsWgen_stat;
  attrList[4] = &RocsWgen_subject;
  attrList[5] = &RocsWgen_trc;
  attrList[6] = &RocsWgen_xml;
  attrList[7] = NULL;
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


struct __wIssue wIssue = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _iscurrenttrc,
  _setcurrenttrc,
  _getdesc,
  _setdesc,
  _isini,
  _setini,
  _isstat,
  _setstat,
  _getsubject,
  _setsubject,
  _istrc,
  _settrc,
  _isxml,
  _setxml,
  _node_dump,
};
