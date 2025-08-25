/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/LocoNet.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.LocoNet
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_loconet = {
  "loconet",  "LocoNet options",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_loconet.name;
}
static const char* _node_remark(void) {
  return RocsWgen_loconet.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_loconet.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_loconet.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * GBM16xn
 */
static struct __attrdef RocsWgen_GBM16xn = {
  "GBM16xn",  "8 bit loco addressing and direction bit.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isGBM16xn(iONode node) {
  Boolean defval = xBool( RocsWgen_GBM16xn );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_loconet, node );
  return NodeOp.getBool( node, "GBM16xn", defval );
}
static void _setGBM16xn(iONode node, Boolean p_GBM16xn) {
  if( node == NULL ) return;
  xNode( RocsWgen_loconet, node );
  NodeOp.setBool( node, "GBM16xn", p_GBM16xn );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cmdstn
 */
static struct __attrdef RocsWgen_cmdstn = {
  "cmdstn",  "",  "",  "string",  "dcs100",  "dcs100,db150,dcs50,intellibox,rocrail,ibcom",  False,
};
static const char* _getcmdstn(iONode node) {
  const char* defval = xStr( RocsWgen_cmdstn );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_loconet, node );
  return NodeOp.getStr( node, "cmdstn", defval );
}
static void _setcmdstn(iONode node, const char* p_cmdstn) {
  if( node == NULL ) return;
  xNode( RocsWgen_loconet, node );
  NodeOp.setStr( node, "cmdstn", p_cmdstn );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ignorepowercmds
 */
static struct __attrdef RocsWgen_ignorepowercmds = {
  "ignorepowercmds",  "Ignore subsequetial power commands.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isignorepowercmds(iONode node) {
  Boolean defval = xBool( RocsWgen_ignorepowercmds );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_loconet, node );
  return NodeOp.getBool( node, "ignorepowercmds", defval );
}
static void _setignorepowercmds(iONode node, Boolean p_ignorepowercmds) {
  if( node == NULL ) return;
  xNode( RocsWgen_loconet, node );
  NodeOp.setBool( node, "ignorepowercmds", p_ignorepowercmds );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * monitor
 */
static struct __attrdef RocsWgen_monitor = {
  "monitor",  "Verbose monitor LocoNet.",  "",  "bool",  "false",  "",  False,
};
static Boolean _ismonitor(iONode node) {
  Boolean defval = xBool( RocsWgen_monitor );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_loconet, node );
  return NodeOp.getBool( node, "monitor", defval );
}
static void _setmonitor(iONode node, Boolean p_monitor) {
  if( node == NULL ) return;
  xNode( RocsWgen_loconet, node );
  NodeOp.setBool( node, "monitor", p_monitor );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * purgetime
 */
static struct __attrdef RocsWgen_purgetime = {
  "purgetime",  "set to zero if the command station does not purge",  "s",  "int",  "200",  "0-*",  False,
};
static int _getpurgetime(iONode node) {
  int defval = xInt( RocsWgen_purgetime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_loconet, node );
  return NodeOp.getInt( node, "purgetime", defval );
}
static void _setpurgetime(iONode node, int p_purgetime) {
  if( node == NULL ) return;
  xNode( RocsWgen_loconet, node );
  NodeOp.setInt( node, "purgetime", p_purgetime );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * reportaddr
 */
static struct __attrdef RocsWgen_reportaddr = {
  "reportaddr",  "global addres on which sensors are reported",  "",  "int",  "1017",  "0-*",  False,
};
static int _getreportaddr(iONode node) {
  int defval = xInt( RocsWgen_reportaddr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_loconet, node );
  return NodeOp.getInt( node, "reportaddr", defval );
}
static void _setreportaddr(iONode node, int p_reportaddr) {
  if( node == NULL ) return;
  xNode( RocsWgen_loconet, node );
  NodeOp.setInt( node, "reportaddr", p_reportaddr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * resetlissy
 */
static struct __attrdef RocsWgen_resetlissy = {
  "resetlissy",  "Reset Lissy events after 1 second.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isresetlissy(iONode node) {
  Boolean defval = xBool( RocsWgen_resetlissy );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_loconet, node );
  return NodeOp.getBool( node, "resetlissy", defval );
}
static void _setresetlissy(iONode node, Boolean p_resetlissy) {
  if( node == NULL ) return;
  xNode( RocsWgen_loconet, node );
  NodeOp.setBool( node, "resetlissy", p_resetlissy );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sensorquery
 */
static struct __attrdef RocsWgen_sensorquery = {
  "sensorquery",  "do sensor query at OPC_GPON",  "",  "bool",  "true",  "",  False,
};
static Boolean _issensorquery(iONode node) {
  Boolean defval = xBool( RocsWgen_sensorquery );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_loconet, node );
  return NodeOp.getBool( node, "sensorquery", defval );
}
static void _setsensorquery(iONode node, Boolean p_sensorquery) {
  if( node == NULL ) return;
  xNode( RocsWgen_loconet, node );
  NodeOp.setBool( node, "sensorquery", p_sensorquery );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * slotping
 */
static struct __attrdef RocsWgen_slotping = {
  "slotping",  "Enable slot ping if purge time is not zero.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isslotping(iONode node) {
  Boolean defval = xBool( RocsWgen_slotping );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_loconet, node );
  return NodeOp.getBool( node, "slotping", defval );
}
static void _setslotping(iONode node, Boolean p_slotping) {
  if( node == NULL ) return;
  xNode( RocsWgen_loconet, node );
  NodeOp.setBool( node, "slotping", p_slotping );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * slots
 */
static struct __attrdef RocsWgen_slots = {
  "slots",  "number of slots for loco's",  "",  "int",  "22",  "0-*",  False,
};
static int _getslots(iONode node) {
  int defval = xInt( RocsWgen_slots );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_loconet, node );
  return NodeOp.getInt( node, "slots", defval );
}
static void _setslots(iONode node, int p_slots) {
  if( node == NULL ) return;
  xNode( RocsWgen_loconet, node );
  NodeOp.setInt( node, "slots", p_slots );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * swack
 */
static struct __attrdef RocsWgen_swack = {
  "swack",  "Check long ack for switch commands.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isswack(iONode node) {
  Boolean defval = xBool( RocsWgen_swack );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_loconet, node );
  return NodeOp.getBool( node, "swack", defval );
}
static void _setswack(iONode node, Boolean p_swack) {
  if( node == NULL ) return;
  xNode( RocsWgen_loconet, node );
  NodeOp.setBool( node, "swack", p_swack );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * swretry
 */
static struct __attrdef RocsWgen_swretry = {
  "swretry",  "Number of switch command retries.",  "",  "int",  "10",  "1-*",  False,
};
static int _getswretry(iONode node) {
  int defval = xInt( RocsWgen_swretry );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_loconet, node );
  return NodeOp.getInt( node, "swretry", defval );
}
static void _setswretry(iONode node, int p_swretry) {
  if( node == NULL ) return;
  xNode( RocsWgen_loconet, node );
  NodeOp.setInt( node, "swretry", p_swretry );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * swsleep
 */
static struct __attrdef RocsWgen_swsleep = {
  "swsleep",  "Number of ms sleep between switch command retries.",  "",  "int",  "50",  "10-*",  False,
};
static int _getswsleep(iONode node) {
  int defval = xInt( RocsWgen_swsleep );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_loconet, node );
  return NodeOp.getInt( node, "swsleep", defval );
}
static void _setswsleep(iONode node, int p_swsleep) {
  if( node == NULL ) return;
  xNode( RocsWgen_loconet, node );
  NodeOp.setInt( node, "swsleep", p_swsleep );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * syncfc
 */
static struct __attrdef RocsWgen_syncfc = {
  "syncfc",  "synchronize fast clock",  "",  "bool",  "false",  "",  False,
};
static Boolean _issyncfc(iONode node) {
  Boolean defval = xBool( RocsWgen_syncfc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_loconet, node );
  return NodeOp.getBool( node, "syncfc", defval );
}
static void _setsyncfc(iONode node, Boolean p_syncfc) {
  if( node == NULL ) return;
  xNode( RocsWgen_loconet, node );
  NodeOp.setBool( node, "syncfc", p_syncfc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usedouble
 */
static struct __attrdef RocsWgen_usedouble = {
  "usedouble",  "Use double packets for lnudp.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isusedouble(iONode node) {
  Boolean defval = xBool( RocsWgen_usedouble );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_loconet, node );
  return NodeOp.getBool( node, "usedouble", defval );
}
static void _setusedouble(iONode node, Boolean p_usedouble) {
  if( node == NULL ) return;
  xNode( RocsWgen_loconet, node );
  NodeOp.setBool( node, "usedouble", p_usedouble );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usefc
 */
static struct __attrdef RocsWgen_usefc = {
  "usefc",  "enable fast clock",  "",  "bool",  "true",  "",  False,
};
static Boolean _isusefc(iONode node) {
  Boolean defval = xBool( RocsWgen_usefc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_loconet, node );
  return NodeOp.getBool( node, "usefc", defval );
}
static void _setusefc(iONode node, Boolean p_usefc) {
  if( node == NULL ) return;
  xNode( RocsWgen_loconet, node );
  NodeOp.setBool( node, "usefc", p_usefc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * useidle
 */
static struct __attrdef RocsWgen_useidle = {
  "useidle",  "use OPC_IDLE instead of OPC_GPOFF",  "",  "bool",  "false",  "",  False,
};
static Boolean _isuseidle(iONode node) {
  Boolean defval = xBool( RocsWgen_useidle );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_loconet, node );
  return NodeOp.getBool( node, "useidle", defval );
}
static void _setuseidle(iONode node, Boolean p_useidle) {
  if( node == NULL ) return;
  xNode( RocsWgen_loconet, node );
  NodeOp.setBool( node, "useidle", p_useidle );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * useseq
 */
static struct __attrdef RocsWgen_useseq = {
  "useseq",  "Use sequence counter for lnudp.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isuseseq(iONode node) {
  Boolean defval = xBool( RocsWgen_useseq );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_loconet, node );
  return NodeOp.getBool( node, "useseq", defval );
}
static void _setuseseq(iONode node, Boolean p_useseq) {
  if( node == NULL ) return;
  xNode( RocsWgen_loconet, node );
  NodeOp.setBool( node, "useseq", p_useseq );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * options
 */
static struct __nodedef RocsWgen_options = {
  "options",  "",  False,  "1",};
static iONode _getoptions(iONode node) {
  xNode( RocsWgen_loconet, node );
  return NodeOp.findNode( node, "options");
}


static iONode _nextoptions(iONode node, iONode child) {
  xNode( RocsWgen_loconet, node );
  return NodeOp.findNextNode( node, child);
}
static void _setoptions(iONode node, iONode p_options) {
  xNode( RocsWgen_loconet, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * slotserver
 */
static struct __nodedef RocsWgen_slotserver = {
  "slotserver",  "",  False,  "1",};
static iONode _getslotserver(iONode node) {
  xNode( RocsWgen_loconet, node );
  return NodeOp.findNode( node, "slotserver");
}


static iONode _nextslotserver(iONode node, iONode child) {
  xNode( RocsWgen_loconet, node );
  return NodeOp.findNextNode( node, child);
}
static void _setslotserver(iONode node, iONode p_slotserver) {
  xNode( RocsWgen_loconet, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[19] = {NULL};
static struct __nodedef* nodeList[3] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_loconet.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node loconet not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node loconet not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_GBM16xn;
  attrList[1] = &RocsWgen_cmdstn;
  attrList[2] = &RocsWgen_ignorepowercmds;
  attrList[3] = &RocsWgen_monitor;
  attrList[4] = &RocsWgen_purgetime;
  attrList[5] = &RocsWgen_reportaddr;
  attrList[6] = &RocsWgen_resetlissy;
  attrList[7] = &RocsWgen_sensorquery;
  attrList[8] = &RocsWgen_slotping;
  attrList[9] = &RocsWgen_slots;
  attrList[10] = &RocsWgen_swack;
  attrList[11] = &RocsWgen_swretry;
  attrList[12] = &RocsWgen_swsleep;
  attrList[13] = &RocsWgen_syncfc;
  attrList[14] = &RocsWgen_usedouble;
  attrList[15] = &RocsWgen_usefc;
  attrList[16] = &RocsWgen_useidle;
  attrList[17] = &RocsWgen_useseq;
  attrList[18] = NULL;
  nodeList[0] = &RocsWgen_options;
  nodeList[1] = &RocsWgen_slotserver;
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


struct __wLocoNet wLocoNet = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "db150",
  "dcs100",
  "dcs50",
  "ibcom",
  "intellibox",
  "rocrail",
  _isGBM16xn,
  _setGBM16xn,
  _getcmdstn,
  _setcmdstn,
  _isignorepowercmds,
  _setignorepowercmds,
  _ismonitor,
  _setmonitor,
  _getpurgetime,
  _setpurgetime,
  _getreportaddr,
  _setreportaddr,
  _isresetlissy,
  _setresetlissy,
  _issensorquery,
  _setsensorquery,
  _isslotping,
  _setslotping,
  _getslots,
  _setslots,
  _isswack,
  _setswack,
  _getswretry,
  _setswretry,
  _getswsleep,
  _setswsleep,
  _issyncfc,
  _setsyncfc,
  _isusedouble,
  _setusedouble,
  _isusefc,
  _setusefc,
  _isuseidle,
  _setuseidle,
  _isuseseq,
  _setuseseq,
  _getoptions,
  _nextoptions,
  _setoptions,
  _getslotserver,
  _nextslotserver,
  _setslotserver,
  _node_dump,
};
