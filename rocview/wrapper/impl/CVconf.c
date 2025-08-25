/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#include "rocview/wrapper/public/CVconf.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.CVconf
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_cvconf = {
  "cvconf",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_cvconf.name;
}
static const char* _node_remark(void) {
  return RocsWgen_cvconf.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_cvconf.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_cvconf.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lissy
 */
static struct __attrdef RocsWgen_lissy = {
  "lissy",  "program the lissy address and config simultaneously",  "",  "bool",  "false",  "",  False,
};
static Boolean _islissy(iONode node) {
  Boolean defval = xBool( RocsWgen_lissy );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cvconf, node );
  return NodeOp.getBool( node, "lissy", defval );
}
static void _setlissy(iONode node, Boolean p_lissy) {
  if( node == NULL ) return;
  xNode( RocsWgen_cvconf, node );
  NodeOp.setBool( node, "lissy", p_lissy );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nrs
 */
static struct __attrdef RocsWgen_nrs = {
  "nrs",  "predefined CV's for read,write and copy all",  "",  "string",  "1,2,3,4,5,6,17,18,29",  "*",  False,
};
static const char* _getnrs(iONode node) {
  const char* defval = xStr( RocsWgen_nrs );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cvconf, node );
  return NodeOp.getStr( node, "nrs", defval );
}
static void _setnrs(iONode node, const char* p_nrs) {
  if( node == NULL ) return;
  xNode( RocsWgen_cvconf, node );
  NodeOp.setStr( node, "nrs", p_nrs );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * pom
 */
static struct __attrdef RocsWgen_pom = {
  "pom",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _ispom(iONode node) {
  Boolean defval = xBool( RocsWgen_pom );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cvconf, node );
  return NodeOp.getBool( node, "pom", defval );
}
static void _setpom(iONode node, Boolean p_pom) {
  if( node == NULL ) return;
  xNode( RocsWgen_cvconf, node );
  NodeOp.setBool( node, "pom", p_pom );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * save
 */
static struct __attrdef RocsWgen_save = {
  "save",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _issave(iONode node) {
  Boolean defval = xBool( RocsWgen_save );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cvconf, node );
  return NodeOp.getBool( node, "save", defval );
}
static void _setsave(iONode node, Boolean p_save) {
  if( node == NULL ) return;
  xNode( RocsWgen_cvconf, node );
  NodeOp.setBool( node, "save", p_save );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timeout
 */
static struct __attrdef RocsWgen_timeout = {
  "timeout",  "timeout on ack",  "s",  "int",  "30",  "*",  False,
};
static int _gettimeout(iONode node) {
  int defval = xInt( RocsWgen_timeout );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cvconf, node );
  return NodeOp.getInt( node, "timeout", defval );
}
static void _settimeout(iONode node, int p_timeout) {
  if( node == NULL ) return;
  xNode( RocsWgen_cvconf, node );
  NodeOp.setInt( node, "timeout", p_timeout );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usedecspec4all
 */
static struct __attrdef RocsWgen_usedecspec4all = {
  "usedecspec4all",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isusedecspec4all(iONode node) {
  Boolean defval = xBool( RocsWgen_usedecspec4all );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cvconf, node );
  return NodeOp.getBool( node, "usedecspec4all", defval );
}
static void _setusedecspec4all(iONode node, Boolean p_usedecspec4all) {
  if( node == NULL ) return;
  xNode( RocsWgen_cvconf, node );
  NodeOp.setBool( node, "usedecspec4all", p_usedecspec4all );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * cvcat
 */
static struct __nodedef RocsWgen_cvcat = {
  "cvcat",  "CV category definition",  False,  "n",};
static iONode _getcvcat(iONode node) {
  xNode( RocsWgen_cvconf, node );
  return NodeOp.findNode( node, "cvcat");
}


static iONode _nextcvcat(iONode node, iONode child) {
  xNode( RocsWgen_cvconf, node );
  return NodeOp.findNextNode( node, child);
}
static void _setcvcat(iONode node, iONode p_cvcat) {
  xNode( RocsWgen_cvconf, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[7] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_cvconf.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node cvconf not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node cvconf not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_lissy;
  attrList[1] = &RocsWgen_nrs;
  attrList[2] = &RocsWgen_pom;
  attrList[3] = &RocsWgen_save;
  attrList[4] = &RocsWgen_timeout;
  attrList[5] = &RocsWgen_usedecspec4all;
  attrList[6] = NULL;
  nodeList[0] = &RocsWgen_cvcat;
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


struct __wCVconf wCVconf = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _islissy,
  _setlissy,
  _getnrs,
  _setnrs,
  _ispom,
  _setpom,
  _issave,
  _setsave,
  _gettimeout,
  _settimeout,
  _isusedecspec4all,
  _setusedecspec4all,
  _getcvcat,
  _nextcvcat,
  _setcvcat,
  _node_dump,
};
