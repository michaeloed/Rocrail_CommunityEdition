/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/CBus.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.CBus
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_cbus = {
  "cbus",  "CBUS options",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_cbus.name;
}
static const char* _node_remark(void) {
  return RocsWgen_cbus.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_cbus.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_cbus.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cid
 */
static struct __attrdef RocsWgen_cid = {
  "cid",  "CANID",  "",  "int",  "1",  "0-*",  False,
};
static int _getcid(iONode node) {
  int defval = xInt( RocsWgen_cid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbus, node );
  return NodeOp.getInt( node, "cid", defval );
}
static void _setcid(iONode node, int p_cid) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbus, node );
  NodeOp.setInt( node, "cid", p_cid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * commandack
 */
static struct __attrdef RocsWgen_commandack = {
  "commandack",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _iscommandack(iONode node) {
  Boolean defval = xBool( RocsWgen_commandack );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbus, node );
  return NodeOp.getBool( node, "commandack", defval );
}
static void _setcommandack(iONode node, Boolean p_commandack) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbus, node );
  NodeOp.setBool( node, "commandack", p_commandack );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fastclock
 */
static struct __attrdef RocsWgen_fastclock = {
  "fastclock",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isfastclock(iONode node) {
  Boolean defval = xBool( RocsWgen_fastclock );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbus, node );
  return NodeOp.getBool( node, "fastclock", defval );
}
static void _setfastclock(iONode node, Boolean p_fastclock) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbus, node );
  NodeOp.setBool( node, "fastclock", p_fastclock );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fcaddr
 */
static struct __attrdef RocsWgen_fcaddr = {
  "fcaddr",  "Fast clock event address.",  "",  "int",  "9999",  "0-*",  False,
};
static int _getfcaddr(iONode node) {
  int defval = xInt( RocsWgen_fcaddr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbus, node );
  return NodeOp.getInt( node, "fcaddr", defval );
}
static void _setfcaddr(iONode node, int p_fcaddr) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbus, node );
  NodeOp.setInt( node, "fcaddr", p_fcaddr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fcnode
 */
static struct __attrdef RocsWgen_fcnode = {
  "fcnode",  "Fast clock node number.",  "",  "int",  "0",  "0-*",  False,
};
static int _getfcnode(iONode node) {
  int defval = xInt( RocsWgen_fcnode );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbus, node );
  return NodeOp.getInt( node, "fcnode", defval );
}
static void _setfcnode(iONode node, int p_fcnode) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbus, node );
  NodeOp.setInt( node, "fcnode", p_fcnode );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fonfof
 */
static struct __attrdef RocsWgen_fonfof = {
  "fonfof",  "Use the new opcodes for controlling functions.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isfonfof(iONode node) {
  Boolean defval = xBool( RocsWgen_fonfof );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbus, node );
  return NodeOp.getBool( node, "fonfof", defval );
}
static void _setfonfof(iONode node, Boolean p_fonfof) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbus, node );
  NodeOp.setBool( node, "fonfof", p_fonfof );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * heartbeat
 */
static struct __attrdef RocsWgen_heartbeat = {
  "heartbeat",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isheartbeat(iONode node) {
  Boolean defval = xBool( RocsWgen_heartbeat );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbus, node );
  return NodeOp.getBool( node, "heartbeat", defval );
}
static void _setheartbeat(iONode node, Boolean p_heartbeat) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbus, node );
  NodeOp.setBool( node, "heartbeat", p_heartbeat );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * heartbeatevent
 */
static struct __attrdef RocsWgen_heartbeatevent = {
  "heartbeatevent",  "",  "",  "int",  "4712",  "",  False,
};
static int _getheartbeatevent(iONode node) {
  int defval = xInt( RocsWgen_heartbeatevent );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbus, node );
  return NodeOp.getInt( node, "heartbeatevent", defval );
}
static void _setheartbeatevent(iONode node, int p_heartbeatevent) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbus, node );
  NodeOp.setInt( node, "heartbeatevent", p_heartbeatevent );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * loadertime
 */
static struct __attrdef RocsWgen_loadertime = {
  "loadertime",  "Sleep time between boot loader lines.",  "",  "int",  "50",  "10-*",  False,
};
static int _getloadertime(iONode node) {
  int defval = xInt( RocsWgen_loadertime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbus, node );
  return NodeOp.getInt( node, "loadertime", defval );
}
static void _setloadertime(iONode node, int p_loadertime) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbus, node );
  NodeOp.setInt( node, "loadertime", p_loadertime );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * purgetime
 */
static struct __attrdef RocsWgen_purgetime = {
  "purgetime",  "CS engine idle timeout.",  "s",  "int",  "10",  "0-*",  False,
};
static int _getpurgetime(iONode node) {
  int defval = xInt( RocsWgen_purgetime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbus, node );
  return NodeOp.getInt( node, "purgetime", defval );
}
static void _setpurgetime(iONode node, int p_purgetime) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbus, node );
  NodeOp.setInt( node, "purgetime", p_purgetime );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * shortevents
 */
static struct __attrdef RocsWgen_shortevents = {
  "shortevents",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isshortevents(iONode node) {
  Boolean defval = xBool( RocsWgen_shortevents );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbus, node );
  return NodeOp.getBool( node, "shortevents", defval );
}
static void _setshortevents(iONode node, Boolean p_shortevents) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbus, node );
  NodeOp.setBool( node, "shortevents", p_shortevents );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * slotserver
 */
static struct __attrdef RocsWgen_slotserver = {
  "slotserver",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isslotserver(iONode node) {
  Boolean defval = xBool( RocsWgen_slotserver );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbus, node );
  return NodeOp.getBool( node, "slotserver", defval );
}
static void _setslotserver(iONode node, Boolean p_slotserver) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbus, node );
  NodeOp.setBool( node, "slotserver", p_slotserver );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sodaddr
 */
static struct __attrdef RocsWgen_sodaddr = {
  "sodaddr",  "Start of Day input address.",  "",  "int",  "0",  "0-*",  False,
};
static int _getsodaddr(iONode node) {
  int defval = xInt( RocsWgen_sodaddr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_cbus, node );
  return NodeOp.getInt( node, "sodaddr", defval );
}
static void _setsodaddr(iONode node, int p_sodaddr) {
  if( node == NULL ) return;
  xNode( RocsWgen_cbus, node );
  NodeOp.setInt( node, "sodaddr", p_sodaddr );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * cbnode
 */
static struct __nodedef RocsWgen_cbnode = {
  "cbnode",  "",  False,  "n",};
static iONode _getcbnode(iONode node) {
  xNode( RocsWgen_cbus, node );
  return NodeOp.findNode( node, "cbnode");
}


static iONode _nextcbnode(iONode node, iONode child) {
  xNode( RocsWgen_cbus, node );
  return NodeOp.findNextNode( node, child);
}
static void _setcbnode(iONode node, iONode p_cbnode) {
  xNode( RocsWgen_cbus, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[14] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_cbus.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node cbus not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node cbus not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_cid;
  attrList[1] = &RocsWgen_commandack;
  attrList[2] = &RocsWgen_fastclock;
  attrList[3] = &RocsWgen_fcaddr;
  attrList[4] = &RocsWgen_fcnode;
  attrList[5] = &RocsWgen_fonfof;
  attrList[6] = &RocsWgen_heartbeat;
  attrList[7] = &RocsWgen_heartbeatevent;
  attrList[8] = &RocsWgen_loadertime;
  attrList[9] = &RocsWgen_purgetime;
  attrList[10] = &RocsWgen_shortevents;
  attrList[11] = &RocsWgen_slotserver;
  attrList[12] = &RocsWgen_sodaddr;
  attrList[13] = NULL;
  nodeList[0] = &RocsWgen_cbnode;
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


struct __wCBus wCBus = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getcid,
  _setcid,
  _iscommandack,
  _setcommandack,
  _isfastclock,
  _setfastclock,
  _getfcaddr,
  _setfcaddr,
  _getfcnode,
  _setfcnode,
  _isfonfof,
  _setfonfof,
  _isheartbeat,
  _setheartbeat,
  _getheartbeatevent,
  _setheartbeatevent,
  _getloadertime,
  _setloadertime,
  _getpurgetime,
  _setpurgetime,
  _isshortevents,
  _setshortevents,
  _isslotserver,
  _setslotserver,
  _getsodaddr,
  _setsodaddr,
  _getcbnode,
  _nextcbnode,
  _setcbnode,
  _node_dump,
};
