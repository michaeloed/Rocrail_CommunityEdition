/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#include "rocview/wrapper/public/Tab.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocview.Tab
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_tab = {
  "tab",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_tab.name;
}
static const char* _node_remark(void) {
  return RocsWgen_tab.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_tab.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_tab.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blue
 */
static struct __attrdef RocsWgen_blue = {
  "blue",  "",  "",  "int",  "255",  "",  False,
};
static int _getblue(iONode node) {
  int defval = xInt( RocsWgen_blue );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tab, node );
  return NodeOp.getInt( node, "blue", defval );
}
static void _setblue(iONode node, int p_blue) {
  if( node == NULL ) return;
  xNode( RocsWgen_tab, node );
  NodeOp.setInt( node, "blue", p_blue );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * green
 */
static struct __attrdef RocsWgen_green = {
  "green",  "",  "",  "int",  "255",  "",  False,
};
static int _getgreen(iONode node) {
  int defval = xInt( RocsWgen_green );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tab, node );
  return NodeOp.getInt( node, "green", defval );
}
static void _setgreen(iONode node, int p_green) {
  if( node == NULL ) return;
  xNode( RocsWgen_tab, node );
  NodeOp.setInt( node, "green", p_green );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nr
 */
static struct __attrdef RocsWgen_nr = {
  "nr",  "",  "",  "int",  "0",  "",  False,
};
static int _getnr(iONode node) {
  int defval = xInt( RocsWgen_nr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tab, node );
  return NodeOp.getInt( node, "nr", defval );
}
static void _setnr(iONode node, int p_nr) {
  if( node == NULL ) return;
  xNode( RocsWgen_tab, node );
  NodeOp.setInt( node, "nr", p_nr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * red
 */
static struct __attrdef RocsWgen_red = {
  "red",  "",  "",  "int",  "255",  "",  False,
};
static int _getred(iONode node) {
  int defval = xInt( RocsWgen_red );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tab, node );
  return NodeOp.getInt( node, "red", defval );
}
static void _setred(iONode node, int p_red) {
  if( node == NULL ) return;
  xNode( RocsWgen_tab, node );
  NodeOp.setInt( node, "red", p_red );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[5] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_tab.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node tab not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node tab not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_blue;
  attrList[1] = &RocsWgen_green;
  attrList[2] = &RocsWgen_nr;
  attrList[3] = &RocsWgen_red;
  attrList[4] = NULL;
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


struct __wTab wTab = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getblue,
  _setblue,
  _getgreen,
  _setgreen,
  _getnr,
  _setnr,
  _getred,
  _setred,
  _node_dump,
};
