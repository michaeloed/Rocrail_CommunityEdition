/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/MacroLine.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.MacroLine
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_macroline = {
  "macroline",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_macroline.name;
}
static const char* _node_remark(void) {
  return RocsWgen_macroline.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_macroline.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_macroline.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blink
 */
static struct __attrdef RocsWgen_blink = {
  "blink",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isblink(iONode node) {
  Boolean defval = xBool( RocsWgen_blink );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_macroline, node );
  return NodeOp.getBool( node, "blink", defval );
}
static void _setblink(iONode node, Boolean p_blink) {
  if( node == NULL ) return;
  xNode( RocsWgen_macroline, node );
  NodeOp.setBool( node, "blink", p_blink );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * delay
 */
static struct __attrdef RocsWgen_delay = {
  "delay",  "",  "",  "int",  "0",  "",  False,
};
static int _getdelay(iONode node) {
  int defval = xInt( RocsWgen_delay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_macroline, node );
  return NodeOp.getInt( node, "delay", defval );
}
static void _setdelay(iONode node, int p_delay) {
  if( node == NULL ) return;
  xNode( RocsWgen_macroline, node );
  NodeOp.setInt( node, "delay", p_delay );
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
  xNode( RocsWgen_macroline, node );
  return NodeOp.getInt( node, "nr", defval );
}
static void _setnr(iONode node, int p_nr) {
  if( node == NULL ) return;
  xNode( RocsWgen_macroline, node );
  NodeOp.setInt( node, "nr", p_nr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "",  "",  "int",  "0",  "",  False,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_macroline, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_macroline, node );
  NodeOp.setInt( node, "port", p_port );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * porttype
 */
static struct __attrdef RocsWgen_porttype = {
  "porttype",  "",  "",  "int",  "0",  "",  False,
};
static int _getporttype(iONode node) {
  int defval = xInt( RocsWgen_porttype );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_macroline, node );
  return NodeOp.getInt( node, "porttype", defval );
}
static void _setporttype(iONode node, int p_porttype) {
  if( node == NULL ) return;
  xNode( RocsWgen_macroline, node );
  NodeOp.setInt( node, "porttype", p_porttype );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * status
 */
static struct __attrdef RocsWgen_status = {
  "status",  "",  "",  "int",  "0",  "",  False,
};
static int _getstatus(iONode node) {
  int defval = xInt( RocsWgen_status );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_macroline, node );
  return NodeOp.getInt( node, "status", defval );
}
static void _setstatus(iONode node, int p_status) {
  if( node == NULL ) return;
  xNode( RocsWgen_macroline, node );
  NodeOp.setInt( node, "status", p_status );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[7] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_macroline.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node macroline not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node macroline not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_blink;
  attrList[1] = &RocsWgen_delay;
  attrList[2] = &RocsWgen_nr;
  attrList[3] = &RocsWgen_port;
  attrList[4] = &RocsWgen_porttype;
  attrList[5] = &RocsWgen_status;
  attrList[6] = NULL;
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


struct __wMacroLine wMacroLine = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isblink,
  _setblink,
  _getdelay,
  _setdelay,
  _getnr,
  _setnr,
  _getport,
  _setport,
  _getporttype,
  _setporttype,
  _getstatus,
  _setstatus,
  _node_dump,
};
