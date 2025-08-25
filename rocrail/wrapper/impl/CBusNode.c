/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/CBusNode.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.CBusNode
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_cbnode = {
  "cbnode",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_cbnode.name;
}
static const char* _node_remark(void) {
  return RocsWgen_cbnode.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_cbnode.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_cbnode.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * canid
 */
static struct __attrdef RocsWgen_canid = {
  "canid",  "CANID",  "",  "int",  "0",  "0-127",  False,
};
static int _getcanid(iONode node) {
  int defval = xInt( RocsWgen_canid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbnode, node );
  return NodeOp.getInt( node, "canid", defval );
}
static void _setcanid(iONode node, int p_canid) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbnode, node );
  NodeOp.setInt( node, "canid", p_canid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * manuid
 */
static struct __attrdef RocsWgen_manuid = {
  "manuid",  "NMRA manufacturer ID.",  "",  "int",  "0",  "0-65535",  False,
};
static int _getmanuid(iONode node) {
  int defval = xInt( RocsWgen_manuid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbnode, node );
  return NodeOp.getInt( node, "manuid", defval );
}
static void _setmanuid(iONode node, int p_manuid) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbnode, node );
  NodeOp.setInt( node, "manuid", p_manuid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mtyp
 */
static struct __attrdef RocsWgen_mtyp = {
  "mtyp",  "Module type. See cbusdefs.h.",  "",  "int",  "0",  "0-65535",  False,
};
static int _getmtyp(iONode node) {
  int defval = xInt( RocsWgen_mtyp );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbnode, node );
  return NodeOp.getInt( node, "mtyp", defval );
}
static void _setmtyp(iONode node, int p_mtyp) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbnode, node );
  NodeOp.setInt( node, "mtyp", p_mtyp );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nr
 */
static struct __attrdef RocsWgen_nr = {
  "nr",  "NodeNumber",  "",  "int",  "0",  "0-65535",  False,
};
static int _getnr(iONode node) {
  int defval = xInt( RocsWgen_nr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbnode, node );
  return NodeOp.getInt( node, "nr", defval );
}
static void _setnr(iONode node, int p_nr) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbnode, node );
  NodeOp.setInt( node, "nr", p_nr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nrevt
 */
static struct __attrdef RocsWgen_nrevt = {
  "nrevt",  "Number of events allowed.",  "",  "int",  "0",  "0-65535",  False,
};
static int _getnrevt(iONode node) {
  int defval = xInt( RocsWgen_nrevt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbnode, node );
  return NodeOp.getInt( node, "nrevt", defval );
}
static void _setnrevt(iONode node, int p_nrevt) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbnode, node );
  NodeOp.setInt( node, "nrevt", p_nrevt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nrevtvar
 */
static struct __attrdef RocsWgen_nrevtvar = {
  "nrevtvar",  "Number of event variable per event.",  "",  "int",  "0",  "0-65535",  False,
};
static int _getnrevtvar(iONode node) {
  int defval = xInt( RocsWgen_nrevtvar );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbnode, node );
  return NodeOp.getInt( node, "nrevtvar", defval );
}
static void _setnrevtvar(iONode node, int p_nrevtvar) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbnode, node );
  NodeOp.setInt( node, "nrevtvar", p_nrevtvar );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nrvar
 */
static struct __attrdef RocsWgen_nrvar = {
  "nrvar",  "Number of node variables.",  "",  "int",  "0",  "0-65535",  False,
};
static int _getnrvar(iONode node) {
  int defval = xInt( RocsWgen_nrvar );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbnode, node );
  return NodeOp.getInt( node, "nrvar", defval );
}
static void _setnrvar(iONode node, int p_nrvar) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbnode, node );
  NodeOp.setInt( node, "nrvar", p_nrvar );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * version
 */
static struct __attrdef RocsWgen_version = {
  "version",  "Firmware version.",  "",  "string",  "",  "*",  False,
};
static const char* _getversion(iONode node) {
  const char* defval = xStr( RocsWgen_version );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbnode, node );
  return NodeOp.getStr( node, "version", defval );
}
static void _setversion(iONode node, const char* p_version) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbnode, node );
  NodeOp.setStr( node, "version", p_version );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * cbnodevar
 */
static struct __nodedef RocsWgen_cbnodevar = {
  "cbnodevar",  "",  False,  "n",};
static iONode _getcbnodevar(iONode node) {
  xNode( RocsWgen_cbnode, node );
  return NodeOp.findNode( node, "cbnodevar");
}


static iONode _nextcbnodevar(iONode node, iONode child) {
  xNode( RocsWgen_cbnode, node );
  return NodeOp.findNextNode( node, child);
}
static void _setcbnodevar(iONode node, iONode p_cbnodevar) {
  xNode( RocsWgen_cbnode, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * cbnodeevent
 */
static struct __nodedef RocsWgen_cbnodeevent = {
  "cbnodeevent",  "",  False,  "n",};
static iONode _getcbnodeevent(iONode node) {
  xNode( RocsWgen_cbnode, node );
  return NodeOp.findNode( node, "cbnodeevent");
}


static iONode _nextcbnodeevent(iONode node, iONode child) {
  xNode( RocsWgen_cbnode, node );
  return NodeOp.findNextNode( node, child);
}
static void _setcbnodeevent(iONode node, iONode p_cbnodeevent) {
  xNode( RocsWgen_cbnode, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[9] = {NULL};
static struct __nodedef* nodeList[3] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_cbnode.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node cbnode not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node cbnode not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_canid;
  attrList[1] = &RocsWgen_manuid;
  attrList[2] = &RocsWgen_mtyp;
  attrList[3] = &RocsWgen_nr;
  attrList[4] = &RocsWgen_nrevt;
  attrList[5] = &RocsWgen_nrevtvar;
  attrList[6] = &RocsWgen_nrvar;
  attrList[7] = &RocsWgen_version;
  attrList[8] = NULL;
  nodeList[0] = &RocsWgen_cbnodevar;
  nodeList[1] = &RocsWgen_cbnodeevent;
  nodeList[2] = NULL;
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


struct __wCBusNode wCBusNode = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  1,
  8,
  2,
  3,
  4,
  5,
  12,
  9,
  10,
  6,
  7,
  13,
  11,
  14,
  15,
  _getcanid,
  _setcanid,
  _getmanuid,
  _setmanuid,
  _getmtyp,
  _setmtyp,
  _getnr,
  _setnr,
  _getnrevt,
  _setnrevt,
  _getnrevtvar,
  _setnrevtvar,
  _getnrvar,
  _setnrvar,
  _getversion,
  _setversion,
  _getcbnodevar,
  _nextcbnodevar,
  _setcbnodevar,
  _getcbnodeevent,
  _nextcbnodeevent,
  _setcbnodeevent,
  _node_dump,
};
