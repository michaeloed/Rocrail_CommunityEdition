/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/RocNet.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.RocNet
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_rocnet = {
  "rocnet",  "RocNet options",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_rocnet.name;
}
static const char* _node_remark(void) {
  return RocsWgen_rocnet.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_rocnet.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_rocnet.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addr
 */
static struct __attrdef RocsWgen_addr = {
  "addr",  "multicast address",  "",  "string",  "224.0.0.1",  "*",  False,
};
static const char* _getaddr(iONode node) {
  const char* defval = xStr( RocsWgen_addr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnet, node );
  return NodeOp.getStr( node, "addr", defval );
}
static void _setaddr(iONode node, const char* p_addr) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnet, node );
  NodeOp.setStr( node, "addr", p_addr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * crc
 */
static struct __attrdef RocsWgen_crc = {
  "crc",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _iscrc(iONode node) {
  Boolean defval = xBool( RocsWgen_crc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnet, node );
  return NodeOp.getBool( node, "crc", defval );
}
static void _setcrc(iONode node, Boolean p_crc) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnet, node );
  NodeOp.setBool( node, "crc", p_crc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "RocNet sender ID, 1 is default for Rocrail.(Host)",  "",  "int",  "1",  "0-65535",  False,
};
static int _getid(iONode node) {
  int defval = xInt( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnet, node );
  return NodeOp.getInt( node, "id", defval );
}
static void _setid(iONode node, int p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnet, node );
  NodeOp.setInt( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lcbus
 */
static struct __attrdef RocsWgen_lcbus = {
  "lcbus",  "Default loco bus if greater then zero.",  "",  "int",  "0",  "0-*",  False,
};
static int _getlcbus(iONode node) {
  int defval = xInt( RocsWgen_lcbus );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnet, node );
  return NodeOp.getInt( node, "lcbus", defval );
}
static void _setlcbus(iONode node, int p_lcbus) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnet, node );
  NodeOp.setInt( node, "lcbus", p_lcbus );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * net
 */
static struct __attrdef RocsWgen_net = {
  "net",  "",  "",  "int",  "0",  "0-255",  False,
};
static int _getnet(iONode node) {
  int defval = xInt( RocsWgen_net );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnet, node );
  return NodeOp.getInt( node, "net", defval );
}
static void _setnet(iONode node, int p_net) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnet, node );
  NodeOp.setInt( node, "net", p_net );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "multicast port",  "",  "int",  "4321",  "0-*",  False,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnet, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnet, node );
  NodeOp.setInt( node, "port", p_port );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sack
 */
static struct __attrdef RocsWgen_sack = {
  "sack",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _issack(iONode node) {
  Boolean defval = xBool( RocsWgen_sack );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnet, node );
  return NodeOp.getBool( node, "sack", defval );
}
static void _setsack(iONode node, Boolean p_sack) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnet, node );
  NodeOp.setBool( node, "sack", p_sack );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * shutdownall
 */
static struct __attrdef RocsWgen_shutdownall = {
  "shutdownall",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isshutdownall(iONode node) {
  Boolean defval = xBool( RocsWgen_shutdownall );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnet, node );
  return NodeOp.getBool( node, "shutdownall", defval );
}
static void _setshutdownall(iONode node, Boolean p_shutdownall) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnet, node );
  NodeOp.setBool( node, "shutdownall", p_shutdownall );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * watchnodes
 */
static struct __attrdef RocsWgen_watchnodes = {
  "watchnodes",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _iswatchnodes(iONode node) {
  Boolean defval = xBool( RocsWgen_watchnodes );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnet, node );
  return NodeOp.getBool( node, "watchnodes", defval );
}
static void _setwatchnodes(iONode node, Boolean p_watchnodes) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnet, node );
  NodeOp.setBool( node, "watchnodes", p_watchnodes );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * wd
 */
static struct __attrdef RocsWgen_wd = {
  "wd",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _iswd(iONode node) {
  Boolean defval = xBool( RocsWgen_wd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnet, node );
  return NodeOp.getBool( node, "wd", defval );
}
static void _setwd(iONode node, Boolean p_wd) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnet, node );
  NodeOp.setBool( node, "wd", p_wd );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * rocnetnodeoptions
 */
static struct __nodedef RocsWgen_rocnetnodeoptions = {
  "rocnetnodeoptions",  "",  False,  "1",};
static iONode _getrocnetnodeoptions(iONode node) {
  xNode( RocsWgen_rocnet, node );
  return NodeOp.findNode( node, "rocnetnodeoptions");
}


static iONode _nextrocnetnodeoptions(iONode node, iONode child) {
  xNode( RocsWgen_rocnet, node );
  return NodeOp.findNextNode( node, child);
}
static void _setrocnetnodeoptions(iONode node, iONode p_rocnetnodeoptions) {
  xNode( RocsWgen_rocnet, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * rocnetnode
 */
static struct __nodedef RocsWgen_rocnetnode = {
  "rocnetnode",  "",  False,  "n",};
static iONode _getrocnetnode(iONode node) {
  xNode( RocsWgen_rocnet, node );
  return NodeOp.findNode( node, "rocnetnode");
}


static iONode _nextrocnetnode(iONode node, iONode child) {
  xNode( RocsWgen_rocnet, node );
  return NodeOp.findNextNode( node, child);
}
static void _setrocnetnode(iONode node, iONode p_rocnetnode) {
  xNode( RocsWgen_rocnet, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * portsetup
 */
static struct __nodedef RocsWgen_portsetup = {
  "portsetup",  "",  False,  "n",};
static iONode _getportsetup(iONode node) {
  xNode( RocsWgen_rocnet, node );
  return NodeOp.findNode( node, "portsetup");
}


static iONode _nextportsetup(iONode node, iONode child) {
  xNode( RocsWgen_rocnet, node );
  return NodeOp.findNextNode( node, child);
}
static void _setportsetup(iONode node, iONode p_portsetup) {
  xNode( RocsWgen_rocnet, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * channelsetup
 */
static struct __nodedef RocsWgen_channelsetup = {
  "channelsetup",  "",  False,  "n",};
static iONode _getchannelsetup(iONode node) {
  xNode( RocsWgen_rocnet, node );
  return NodeOp.findNode( node, "channelsetup");
}


static iONode _nextchannelsetup(iONode node, iONode child) {
  xNode( RocsWgen_rocnet, node );
  return NodeOp.findNextNode( node, child);
}
static void _setchannelsetup(iONode node, iONode p_channelsetup) {
  xNode( RocsWgen_rocnet, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * macro
 */
static struct __nodedef RocsWgen_macro = {
  "macro",  "",  False,  "n",};
static iONode _getmacro(iONode node) {
  xNode( RocsWgen_rocnet, node );
  return NodeOp.findNode( node, "macro");
}


static iONode _nextmacro(iONode node, iONode child) {
  xNode( RocsWgen_rocnet, node );
  return NodeOp.findNextNode( node, child);
}
static void _setmacro(iONode node, iONode p_macro) {
  xNode( RocsWgen_rocnet, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * locosetup
 */
static struct __nodedef RocsWgen_locosetup = {
  "locosetup",  "",  False,  "1",};
static iONode _getlocosetup(iONode node) {
  xNode( RocsWgen_rocnet, node );
  return NodeOp.findNode( node, "locosetup");
}


static iONode _nextlocosetup(iONode node, iONode child) {
  xNode( RocsWgen_rocnet, node );
  return NodeOp.findNextNode( node, child);
}
static void _setlocosetup(iONode node, iONode p_locosetup) {
  xNode( RocsWgen_rocnet, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[11] = {NULL};
static struct __nodedef* nodeList[7] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_rocnet.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node rocnet not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node rocnet not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_addr;
  attrList[1] = &RocsWgen_crc;
  attrList[2] = &RocsWgen_id;
  attrList[3] = &RocsWgen_lcbus;
  attrList[4] = &RocsWgen_net;
  attrList[5] = &RocsWgen_port;
  attrList[6] = &RocsWgen_sack;
  attrList[7] = &RocsWgen_shutdownall;
  attrList[8] = &RocsWgen_watchnodes;
  attrList[9] = &RocsWgen_wd;
  attrList[10] = NULL;
  nodeList[0] = &RocsWgen_rocnetnodeoptions;
  nodeList[1] = &RocsWgen_rocnetnode;
  nodeList[2] = &RocsWgen_portsetup;
  nodeList[3] = &RocsWgen_channelsetup;
  nodeList[4] = &RocsWgen_macro;
  nodeList[5] = &RocsWgen_locosetup;
  nodeList[6] = NULL;
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


struct __wRocNet wRocNet = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getaddr,
  _setaddr,
  _iscrc,
  _setcrc,
  _getid,
  _setid,
  _getlcbus,
  _setlcbus,
  _getnet,
  _setnet,
  _getport,
  _setport,
  _issack,
  _setsack,
  _isshutdownall,
  _setshutdownall,
  _iswatchnodes,
  _setwatchnodes,
  _iswd,
  _setwd,
  _getrocnetnodeoptions,
  _nextrocnetnodeoptions,
  _setrocnetnodeoptions,
  _getrocnetnode,
  _nextrocnetnode,
  _setrocnetnode,
  _getportsetup,
  _nextportsetup,
  _setportsetup,
  _getchannelsetup,
  _nextchannelsetup,
  _setchannelsetup,
  _getmacro,
  _nextmacro,
  _setmacro,
  _getlocosetup,
  _nextlocosetup,
  _setlocosetup,
  _node_dump,
};
