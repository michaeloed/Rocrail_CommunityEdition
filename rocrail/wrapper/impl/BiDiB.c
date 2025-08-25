/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/BiDiB.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.BiDiB
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_bidib = {
  "bidib",  "BiDiB options",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_bidib.name;
}
static const char* _node_remark(void) {
  return RocsWgen_bidib.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_bidib.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_bidib.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * manual2bidib
 */
static struct __attrdef RocsWgen_manual2bidib = {
  "manual2bidib",  "Map MSG_CS_ACCESSORY_MANUAL messages to BiDiB commands.",  "",  "bool",  "false",  "",  False,
};
static Boolean _ismanual2bidib(iONode node) {
  Boolean defval = xBool( RocsWgen_manual2bidib );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidib, node );
  return NodeOp.getBool( node, "manual2bidib", defval );
}
static void _setmanual2bidib(iONode node, Boolean p_manual2bidib) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidib, node );
  NodeOp.setBool( node, "manual2bidib", p_manual2bidib );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * secAck
 */
static struct __attrdef RocsWgen_secAck = {
  "secAck",  "Enable secure acknowledge.",  "",  "bool",  "false",  "",  False,
};
static Boolean _issecAck(iONode node) {
  Boolean defval = xBool( RocsWgen_secAck );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidib, node );
  return NodeOp.getBool( node, "secAck", defval );
}
static void _setsecAck(iONode node, Boolean p_secAck) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidib, node );
  NodeOp.setBool( node, "secAck", p_secAck );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * secAckInt
 */
static struct __attrdef RocsWgen_secAckInt = {
  "secAckInt",  "Secure acknowledge interval in 10ms units.",  "",  "int",  "20",  "",  False,
};
static int _getsecAckInt(iONode node) {
  int defval = xInt( RocsWgen_secAckInt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidib, node );
  return NodeOp.getInt( node, "secAckInt", defval );
}
static void _setsecAckInt(iONode node, int p_secAckInt) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidib, node );
  NodeOp.setInt( node, "secAckInt", p_secAckInt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * watchdog
 */
static struct __attrdef RocsWgen_watchdog = {
  "watchdog",  "Enable watchdog.",  "",  "bool",  "false",  "",  False,
};
static Boolean _iswatchdog(iONode node) {
  Boolean defval = xBool( RocsWgen_watchdog );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidib, node );
  return NodeOp.getBool( node, "watchdog", defval );
}
static void _setwatchdog(iONode node, Boolean p_watchdog) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidib, node );
  NodeOp.setBool( node, "watchdog", p_watchdog );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * watchdogInt
 */
static struct __attrdef RocsWgen_watchdogInt = {
  "watchdogInt",  "Watchdog interval in 100ms units.",  "",  "int",  "20",  "",  False,
};
static int _getwatchdogInt(iONode node) {
  int defval = xInt( RocsWgen_watchdogInt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_bidib, node );
  return NodeOp.getInt( node, "watchdogInt", defval );
}
static void _setwatchdogInt(iONode node, int p_watchdogInt) {
  if( node == NULL ) return;
  xNode( RocsWgen_bidib, node );
  NodeOp.setInt( node, "watchdogInt", p_watchdogInt );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * bidibnode
 */
static struct __nodedef RocsWgen_bidibnode = {
  "bidibnode",  "BiDiB options",  False,  "n",};
static iONode _getbidibnode(iONode node) {
  xNode( RocsWgen_bidib, node );
  return NodeOp.findNode( node, "bidibnode");
}


static iONode _nextbidibnode(iONode node, iONode child) {
  xNode( RocsWgen_bidib, node );
  return NodeOp.findNextNode( node, child);
}
static void _setbidibnode(iONode node, iONode p_bidibnode) {
  xNode( RocsWgen_bidib, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[6] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_bidib.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node bidib not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node bidib not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_manual2bidib;
  attrList[1] = &RocsWgen_secAck;
  attrList[2] = &RocsWgen_secAckInt;
  attrList[3] = &RocsWgen_watchdog;
  attrList[4] = &RocsWgen_watchdogInt;
  attrList[5] = NULL;
  nodeList[0] = &RocsWgen_bidibnode;
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


struct __wBiDiB wBiDiB = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _ismanual2bidib,
  _setmanual2bidib,
  _issecAck,
  _setsecAck,
  _getsecAckInt,
  _setsecAckInt,
  _iswatchdog,
  _setwatchdog,
  _getwatchdogInt,
  _setwatchdogInt,
  _getbidibnode,
  _nextbidibnode,
  _setbidibnode,
  _node_dump,
};
