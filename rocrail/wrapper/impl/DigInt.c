/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/DigInt.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.DigInt
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_digint = {
  "digint",  "Digital Interface definition.",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_digint.name;
}
static const char* _node_remark(void) {
  return RocsWgen_digint.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_digint.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_digint.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * asciiprotocol
 */
static struct __attrdef RocsWgen_asciiprotocol = {
  "asciiprotocol",  "Use an ASCII protocol.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isasciiprotocol(iONode node) {
  Boolean defval = xBool( RocsWgen_asciiprotocol );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "asciiprotocol", defval );
}
static void _setasciiprotocol(iONode node, Boolean p_asciiprotocol) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "asciiprotocol", p_asciiprotocol );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bits
 */
static struct __attrdef RocsWgen_bits = {
  "bits",  "",  "",  "int",  "8",  "*",  False,
};
static int _getbits(iONode node) {
  int defval = xInt( RocsWgen_bits );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getInt( node, "bits", defval );
}
static void _setbits(iONode node, int p_bits) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setInt( node, "bits", p_bits );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bps
 */
static struct __attrdef RocsWgen_bps = {
  "bps",  "",  "bps",  "int",  "2400",  "1200,2400,4800,9600,19200,38400,57600",  False,
};
static int _getbps(iONode node) {
  int defval = xInt( RocsWgen_bps );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getInt( node, "bps", defval );
}
static void _setbps(iONode node, int p_bps) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setInt( node, "bps", p_bps );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ctsretry
 */
static struct __attrdef RocsWgen_ctsretry = {
  "ctsretry",  "wait for CTS line to come up.",  "ms",  "int",  "1000",  "*",  False,
};
static int _getctsretry(iONode node) {
  int defval = xInt( RocsWgen_ctsretry );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getInt( node, "ctsretry", defval );
}
static void _setctsretry(iONode node, int p_ctsretry) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setInt( node, "ctsretry", p_ctsretry );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * device
 */
static struct __attrdef RocsWgen_device = {
  "device",  "",  "",  "string",  "com1",  "",  False,
};
static const char* _getdevice(iONode node) {
  const char* defval = xStr( RocsWgen_device );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getStr( node, "device", defval );
}
static void _setdevice(iONode node, const char* p_device) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setStr( node, "device", p_device );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * dummyio
 */
static struct __attrdef RocsWgen_dummyio = {
  "dummyio",  "Do not use real I/O.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isdummyio(iONode node) {
  Boolean defval = xBool( RocsWgen_dummyio );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "dummyio", defval );
}
static void _setdummyio(iONode node, Boolean p_dummyio) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "dummyio", p_dummyio );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fastclock
 */
static struct __attrdef RocsWgen_fastclock = {
  "fastclock",  "send fast clock commands to the connected command station",  "",  "bool",  "false",  "",  False,
};
static Boolean _isfastclock(iONode node) {
  Boolean defval = xBool( RocsWgen_fastclock );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "fastclock", defval );
}
static void _setfastclock(iONode node, Boolean p_fastclock) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "fastclock", p_fastclock );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbmod
 */
static struct __attrdef RocsWgen_fbmod = {
  "fbmod",  "Number of connected feedback modules of 8 inputs.",  "",  "int",  "0",  "*",  False,
};
static int _getfbmod(iONode node) {
  int defval = xInt( RocsWgen_fbmod );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getInt( node, "fbmod", defval );
}
static void _setfbmod(iONode node, int p_fbmod) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setInt( node, "fbmod", p_fbmod );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fboffset
 */
static struct __attrdef RocsWgen_fboffset = {
  "fboffset",  "Offset for the feedback units.",  "",  "int",  "0",  "",  False,
};
static int _getfboffset(iONode node) {
  int defval = xInt( RocsWgen_fboffset );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getInt( node, "fboffset", defval );
}
static void _setfboffset(iONode node, int p_fboffset) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setInt( node, "fboffset", p_fboffset );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbpoll
 */
static struct __attrdef RocsWgen_fbpoll = {
  "fbpoll",  "Poll sensor events in p50x instead of xEvtSen.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isfbpoll(iONode node) {
  Boolean defval = xBool( RocsWgen_fbpoll );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "fbpoll", defval );
}
static void _setfbpoll(iONode node, Boolean p_fbpoll) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "fbpoll", p_fbpoll );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * fbreset
 */
static struct __attrdef RocsWgen_fbreset = {
  "fbreset",  "Reset sensors automatically to low.",  "",  "bool",  "false",  "*",  False,
};
static Boolean _isfbreset(iONode node) {
  Boolean defval = xBool( RocsWgen_fbreset );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "fbreset", defval );
}
static void _setfbreset(iONode node, Boolean p_fbreset) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "fbreset", p_fbreset );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * flow
 */
static struct __attrdef RocsWgen_flow = {
  "flow",  "",  "",  "string",  "cts",  "cts,dsr,xon,no",  False,
};
static const char* _getflow(iONode node) {
  const char* defval = xStr( RocsWgen_flow );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getStr( node, "flow", defval );
}
static void _setflow(iONode node, const char* p_flow) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setStr( node, "flow", p_flow );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * host
 */
static struct __attrdef RocsWgen_host = {
  "host",  "hostname.",  "",  "string",  "",  "",  False,
};
static const char* _gethost(iONode node) {
  const char* defval = xStr( RocsWgen_host );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getStr( node, "host", defval );
}
static void _sethost(iONode node, const char* p_host) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setStr( node, "host", p_host );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * identdelay
 */
static struct __attrdef RocsWgen_identdelay = {
  "identdelay",  "Delay before sending a low sensor state for ident codes.",  "ms",  "int",  "2500",  "",  False,
};
static int _getidentdelay(iONode node) {
  int defval = xInt( RocsWgen_identdelay );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getInt( node, "identdelay", defval );
}
static void _setidentdelay(iONode node, int p_identdelay) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setInt( node, "identdelay", p_identdelay );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ignorebusy
 */
static struct __attrdef RocsWgen_ignorebusy = {
  "ignorebusy",  "ignore the busy message from command station",  "",  "bool",  "false",  "",  False,
};
static Boolean _isignorebusy(iONode node) {
  Boolean defval = xBool( RocsWgen_ignorebusy );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "ignorebusy", defval );
}
static void _setignorebusy(iONode node, Boolean p_ignorebusy) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "ignorebusy", p_ignorebusy );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iid
 */
static struct __attrdef RocsWgen_iid = {
  "iid",  "Interface ID.",  "",  "string",  "NULL",  "",  True,
};
static const char* _getiid(iONode node) {
  const char* defval = xStr( RocsWgen_iid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iid_master
 */
static struct __attrdef RocsWgen_iid_master = {
  "iid_master",  "Interface ID (loconet).",  "",  "string",  "NULL",  "",  False,
};
static const char* _getiid_master(iONode node) {
  const char* defval = xStr( RocsWgen_iid_master );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getStr( node, "iid_master", defval );
}
static void _setiid_master(iONode node, const char* p_iid_master) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setStr( node, "iid_master", p_iid_master );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iid_slave
 */
static struct __attrdef RocsWgen_iid_slave = {
  "iid_slave",  "Interface ID (ddl).",  "",  "string",  "NULL",  "",  False,
};
static const char* _getiid_slave(iONode node) {
  const char* defval = xStr( RocsWgen_iid_slave );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getStr( node, "iid_slave", defval );
}
static void _setiid_slave(iONode node, const char* p_iid_slave) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setStr( node, "iid_slave", p_iid_slave );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lib
 */
static struct __attrdef RocsWgen_lib = {
  "lib",  "",  "",  "string",  "virtual",  "",  False,
};
static const char* _getlib(iONode node) {
  const char* defval = xStr( RocsWgen_lib );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getStr( node, "lib", defval );
}
static void _setlib(iONode node, const char* p_lib) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setStr( node, "lib", p_lib );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * libpath
 */
static struct __attrdef RocsWgen_libpath = {
  "libpath",  "",  "",  "string",  ".",  "",  False,
};
static const char* _getlibpath(iONode node) {
  const char* defval = xStr( RocsWgen_libpath );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getStr( node, "libpath", defval );
}
static void _setlibpath(iONode node, const char* p_libpath) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setStr( node, "libpath", p_libpath );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * localip
 */
static struct __attrdef RocsWgen_localip = {
  "localip",  "Local interface IP.",  "",  "string",  "",  "",  False,
};
static const char* _getlocalip(iONode node) {
  const char* defval = xStr( RocsWgen_localip );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getStr( node, "localip", defval );
}
static void _setlocalip(iONode node, const char* p_localip) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setStr( node, "localip", p_localip );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * locolist
 */
static struct __attrdef RocsWgen_locolist = {
  "locolist",  "Initial send the digint the list of locos.",  "",  "bool",  "false",  "",  False,
};
static Boolean _islocolist(iONode node) {
  Boolean defval = xBool( RocsWgen_locolist );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "locolist", defval );
}
static void _setlocolist(iONode node, Boolean p_locolist) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "locolist", p_locolist );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * overrule
 */
static struct __attrdef RocsWgen_overrule = {
  "overrule",  "Overrule throttle commands.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isoverrule(iONode node) {
  Boolean defval = xBool( RocsWgen_overrule );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "overrule", defval );
}
static void _setoverrule(iONode node, Boolean p_overrule) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "overrule", p_overrule );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * parity
 */
static struct __attrdef RocsWgen_parity = {
  "parity",  "",  "",  "string",  "none",  "none,even,odd",  False,
};
static const char* _getparity(iONode node) {
  const char* defval = xStr( RocsWgen_parity );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getStr( node, "parity", defval );
}
static void _setparity(iONode node, const char* p_parity) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setStr( node, "parity", p_parity );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * port
 */
static struct __attrdef RocsWgen_port = {
  "port",  "command port.",  "",  "int",  "0",  "",  False,
};
static int _getport(iONode node) {
  int defval = xInt( RocsWgen_port );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getInt( node, "port", defval );
}
static void _setport(iONode node, int p_port) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setInt( node, "port", p_port );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * poweratstartup
 */
static struct __attrdef RocsWgen_poweratstartup = {
  "poweratstartup",  "Power on at startup.",  "",  "bool",  "false",  "",  False,
};
static Boolean _ispoweratstartup(iONode node) {
  Boolean defval = xBool( RocsWgen_poweratstartup );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "poweratstartup", defval );
}
static void _setpoweratstartup(iONode node, Boolean p_poweratstartup) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "poweratstartup", p_poweratstartup );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * poweroffexit
 */
static struct __attrdef RocsWgen_poweroffexit = {
  "poweroffexit",  "Power off at halt command.",  "",  "bool",  "true",  "",  False,
};
static Boolean _ispoweroffexit(iONode node) {
  Boolean defval = xBool( RocsWgen_poweroffexit );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "poweroffexit", defval );
}
static void _setpoweroffexit(iONode node, Boolean p_poweroffexit) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "poweroffexit", p_poweroffexit );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * protver
 */
static struct __attrdef RocsWgen_protver = {
  "protver",  "Protocol version. Default implementation is 0.",  "",  "int",  "0",  "",  False,
};
static int _getprotver(iONode node) {
  int defval = xInt( RocsWgen_protver );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getInt( node, "protver", defval );
}
static void _setprotver(iONode node, int p_protver) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setInt( node, "protver", p_protver );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * psleep
 */
static struct __attrdef RocsWgen_psleep = {
  "psleep",  "Sleep between polling of the feedback units.",  "ms",  "int",  "200",  "",  False,
};
static int _getpsleep(iONode node) {
  int defval = xInt( RocsWgen_psleep );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getInt( node, "psleep", defval );
}
static void _setpsleep(iONode node, int p_psleep) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setInt( node, "psleep", p_psleep );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * ptsupport
 */
static struct __attrdef RocsWgen_ptsupport = {
  "ptsupport",  "Check for PT events.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isptsupport(iONode node) {
  Boolean defval = xBool( RocsWgen_ptsupport );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "ptsupport", defval );
}
static void _setptsupport(iONode node, Boolean p_ptsupport) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "ptsupport", p_ptsupport );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * pw4acc
 */
static struct __attrdef RocsWgen_pw4acc = {
  "pw4acc",  "Power must be on for accessory commands.",  "",  "bool",  "true",  "",  False,
};
static Boolean _ispw4acc(iONode node) {
  Boolean defval = xBool( RocsWgen_pw4acc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "pw4acc", defval );
}
static void _setpw4acc(iONode node, Boolean p_pw4acc) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "pw4acc", p_pw4acc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * readbidi
 */
static struct __attrdef RocsWgen_readbidi = {
  "readbidi",  "Poll the bidi units.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isreadbidi(iONode node) {
  Boolean defval = xBool( RocsWgen_readbidi );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "readbidi", defval );
}
static void _setreadbidi(iONode node, Boolean p_readbidi) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "readbidi", p_readbidi );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * readfb
 */
static struct __attrdef RocsWgen_readfb = {
  "readfb",  "Poll the feedback units.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isreadfb(iONode node) {
  Boolean defval = xBool( RocsWgen_readfb );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "readfb", defval );
}
static void _setreadfb(iONode node, Boolean p_readfb) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "readfb", p_readfb );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * reportstate
 */
static struct __attrdef RocsWgen_reportstate = {
  "reportstate",  "",  "",  "bool",  "true",  "",  False,
};
static Boolean _isreportstate(iONode node) {
  Boolean defval = xBool( RocsWgen_reportstate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "reportstate", defval );
}
static void _setreportstate(iONode node, Boolean p_reportstate) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "reportstate", p_reportstate );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * restricted
 */
static struct __attrdef RocsWgen_restricted = {
  "restricted",  "Restricted functionality due to missing support key.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isrestricted(iONode node) {
  Boolean defval = xBool( RocsWgen_restricted );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "restricted", defval );
}
static void _setrestricted(iONode node, Boolean p_restricted) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "restricted", p_restricted );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * rtsdisabled
 */
static struct __attrdef RocsWgen_rtsdisabled = {
  "rtsdisabled",  "Disables RTS line for USB converters. (Depends on type if this is needed.)",  "",  "bool",  "false",  "",  False,
};
static Boolean _isrtsdisabled(iONode node) {
  Boolean defval = xBool( RocsWgen_rtsdisabled );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "rtsdisabled", defval );
}
static void _setrtsdisabled(iONode node, Boolean p_rtsdisabled) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "rtsdisabled", p_rtsdisabled );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * startpwstate
 */
static struct __attrdef RocsWgen_startpwstate = {
  "startpwstate",  "Powerstate at startup.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isstartpwstate(iONode node) {
  Boolean defval = xBool( RocsWgen_startpwstate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "startpwstate", defval );
}
static void _setstartpwstate(iONode node, Boolean p_startpwstate) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "startpwstate", p_startpwstate );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * stopbits
 */
static struct __attrdef RocsWgen_stopbits = {
  "stopbits",  "",  "",  "int",  "2",  "*",  False,
};
static int _getstopbits(iONode node) {
  int defval = xInt( RocsWgen_stopbits );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getInt( node, "stopbits", defval );
}
static void _setstopbits(iONode node, int p_stopbits) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setInt( node, "stopbits", p_stopbits );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * stress
 */
static struct __attrdef RocsWgen_stress = {
  "stress",  "send every 10ms a loconet packet to stress the network",  "",  "bool",  "false",  "",  False,
};
static Boolean _isstress(iONode node) {
  Boolean defval = xBool( RocsWgen_stress );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "stress", defval );
}
static void _setstress(iONode node, Boolean p_stress) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "stress", p_stress );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sublib
 */
static struct __attrdef RocsWgen_sublib = {
  "sublib",  "",  "",  "string",  "default",  "",  False,
};
static const char* _getsublib(iONode node) {
  const char* defval = xStr( RocsWgen_sublib );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getStr( node, "sublib", defval );
}
static void _setsublib(iONode node, const char* p_sublib) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setStr( node, "sublib", p_sublib );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * swinvert
 */
static struct __attrdef RocsWgen_swinvert = {
  "swinvert",  "Invert all turnouts/switches.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isswinvert(iONode node) {
  Boolean defval = xBool( RocsWgen_swinvert );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "swinvert", defval );
}
static void _setswinvert(iONode node, Boolean p_swinvert) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "swinvert", p_swinvert );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * switchlist
 */
static struct __attrdef RocsWgen_switchlist = {
  "switchlist",  "Initial send the digint the list of switches.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isswitchlist(iONode node) {
  Boolean defval = xBool( RocsWgen_switchlist );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "switchlist", defval );
}
static void _setswitchlist(iONode node, Boolean p_switchlist) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "switchlist", p_switchlist );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * swtime
 */
static struct __attrdef RocsWgen_swtime = {
  "swtime",  "Switch time.",  "ms",  "int",  "250",  "*",  False,
};
static int _getswtime(iONode node) {
  int defval = xInt( RocsWgen_swtime );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getInt( node, "swtime", defval );
}
static void _setswtime(iONode node, int p_swtime) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setInt( node, "swtime", p_swtime );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * systeminfo
 */
static struct __attrdef RocsWgen_systeminfo = {
  "systeminfo",  "Activate system info if available.",  "",  "bool",  "true",  "",  False,
};
static Boolean _issysteminfo(iONode node) {
  Boolean defval = xBool( RocsWgen_systeminfo );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "systeminfo", defval );
}
static void _setsysteminfo(iONode node, Boolean p_systeminfo) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "systeminfo", p_systeminfo );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timeout
 */
static struct __attrdef RocsWgen_timeout = {
  "timeout",  "",  "ms",  "int",  "1000",  "*",  False,
};
static int _gettimeout(iONode node) {
  int defval = xInt( RocsWgen_timeout );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getInt( node, "timeout", defval );
}
static void _settimeout(iONode node, int p_timeout) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setInt( node, "timeout", p_timeout );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * udpportRX
 */
static struct __attrdef RocsWgen_udpportRX = {
  "udpportRX",  "receive port.",  "",  "int",  "0",  "",  False,
};
static int _getudpportRX(iONode node) {
  int defval = xInt( RocsWgen_udpportRX );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getInt( node, "udpportRX", defval );
}
static void _setudpportRX(iONode node, int p_udpportRX) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setInt( node, "udpportRX", p_udpportRX );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * udpportTX
 */
static struct __attrdef RocsWgen_udpportTX = {
  "udpportTX",  "send port.",  "",  "int",  "0",  "",  False,
};
static int _getudpportTX(iONode node) {
  int defval = xInt( RocsWgen_udpportTX );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getInt( node, "udpportTX", defval );
}
static void _setudpportTX(iONode node, int p_udpportTX) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setInt( node, "udpportTX", p_udpportTX );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * userid
 */
static struct __attrdef RocsWgen_userid = {
  "userid",  "user ID",  "",  "string",  "",  "",  False,
};
static const char* _getuserid(iONode node) {
  const char* defval = xStr( RocsWgen_userid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getStr( node, "userid", defval );
}
static void _setuserid(iONode node, const char* p_userid) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setStr( node, "userid", p_userid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * v0onebreak
 */
static struct __attrdef RocsWgen_v0onebreak = {
  "v0onebreak",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isv0onebreak(iONode node) {
  Boolean defval = xBool( RocsWgen_v0onebreak );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_digint, node );
  return NodeOp.getBool( node, "v0onebreak", defval );
}
static void _setv0onebreak(iONode node, Boolean p_v0onebreak) {
  if( node == NULL ) return;
  xNode( RocsWgen_digint, node );
  NodeOp.setBool( node, "v0onebreak", p_v0onebreak );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * hueconfig
 */
static struct __nodedef RocsWgen_hueconfig = {
  "hueconfig",  "Philips HUE",  False,  "1",};
static iONode _gethueconfig(iONode node) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNode( node, "hueconfig");
}


static iONode _nexthueconfig(iONode node, iONode child) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNextNode( node, child);
}
static void _sethueconfig(iONode node, iONode p_hueconfig) {
  xNode( RocsWgen_digint, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * hsi88
 */
static struct __nodedef RocsWgen_hsi88 = {
  "hsi88",  "HSI88 init",  False,  "1",};
static iONode _gethsi88(iONode node) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNode( node, "hsi88");
}


static iONode _nexthsi88(iONode node, iONode child) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNextNode( node, child);
}
static void _sethsi88(iONode node, iONode p_hsi88) {
  xNode( RocsWgen_digint, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * spl
 */
static struct __nodedef RocsWgen_spl = {
  "spl",  "SPL options",  False,  "1",};
static iONode _getspl(iONode node) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNode( node, "spl");
}


static iONode _nextspl(iONode node, iONode child) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNextNode( node, child);
}
static void _setspl(iONode node, iONode p_spl) {
  xNode( RocsWgen_digint, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * opendcc
 */
static struct __nodedef RocsWgen_opendcc = {
  "opendcc",  "OpenDCC options",  False,  "1",};
static iONode _getopendcc(iONode node) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNode( node, "opendcc");
}


static iONode _nextopendcc(iONode node, iONode child) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNextNode( node, child);
}
static void _setopendcc(iONode node, iONode p_opendcc) {
  xNode( RocsWgen_digint, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * bidib
 */
static struct __nodedef RocsWgen_bidib = {
  "bidib",  "BiDiB options",  False,  "1",};
static iONode _getbidib(iONode node) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNode( node, "bidib");
}


static iONode _nextbidib(iONode node, iONode child) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNextNode( node, child);
}
static void _setbidib(iONode node, iONode p_bidib) {
  xNode( RocsWgen_digint, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * srcp
 */
static struct __nodedef RocsWgen_srcp = {
  "srcp",  "SRCP init",  False,  "1",};
static iONode _getsrcp(iONode node) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNode( node, "srcp");
}


static iONode _nextsrcp(iONode node, iONode child) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNextNode( node, child);
}
static void _setsrcp(iONode node, iONode p_srcp) {
  xNode( RocsWgen_digint, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * ddx
 */
static struct __nodedef RocsWgen_ddx = {
  "ddx",  "DDX init",  False,  "1",};
static iONode _getddx(iONode node) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNode( node, "ddx");
}


static iONode _nextddx(iONode node, iONode child) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNextNode( node, child);
}
static void _setddx(iONode node, iONode p_ddx) {
  xNode( RocsWgen_digint, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * rocnet
 */
static struct __nodedef RocsWgen_rocnet = {
  "rocnet",  "RocNet options",  False,  "1",};
static iONode _getrocnet(iONode node) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNode( node, "rocnet");
}


static iONode _nextrocnet(iONode node, iONode child) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNextNode( node, child);
}
static void _setrocnet(iONode node, iONode p_rocnet) {
  xNode( RocsWgen_digint, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * mcs2
 */
static struct __nodedef RocsWgen_mcs2 = {
  "mcs2",  "CS2 options",  False,  "1",};
static iONode _getmcs2(iONode node) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNode( node, "mcs2");
}


static iONode _nextmcs2(iONode node, iONode child) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNextNode( node, child);
}
static void _setmcs2(iONode node, iONode p_mcs2) {
  xNode( RocsWgen_digint, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * dmx
 */
static struct __nodedef RocsWgen_dmx = {
  "dmx",  "DMX Options",  False,  "1",};
static iONode _getdmx(iONode node) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNode( node, "dmx");
}


static iONode _nextdmx(iONode node, iONode child) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNextNode( node, child);
}
static void _setdmx(iONode node, iONode p_dmx) {
  xNode( RocsWgen_digint, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * cbus
 */
static struct __nodedef RocsWgen_cbus = {
  "cbus",  "CBUS options",  False,  "1",};
static iONode _getcbus(iONode node) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNode( node, "cbus");
}


static iONode _nextcbus(iONode node, iONode child) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNextNode( node, child);
}
static void _setcbus(iONode node, iONode p_cbus) {
  xNode( RocsWgen_digint, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * dcc232
 */
static struct __nodedef RocsWgen_dcc232 = {
  "dcc232",  "DCC232 options",  False,  "1",};
static iONode _getdcc232(iONode node) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNode( node, "dcc232");
}


static iONode _nextdcc232(iONode node, iONode child) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNextNode( node, child);
}
static void _setdcc232(iONode node, iONode p_dcc232) {
  xNode( RocsWgen_digint, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * loconet
 */
static struct __nodedef RocsWgen_loconet = {
  "loconet",  "LocoNet options",  False,  "1",};
static iONode _getloconet(iONode node) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNode( node, "loconet");
}


static iONode _nextloconet(iONode node, iONode child) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNextNode( node, child);
}
static void _setloconet(iONode node, iONode p_loconet) {
  xNode( RocsWgen_digint, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * io8255
 */
static struct __nodedef RocsWgen_io8255 = {
  "io8255",  "IO8255 options",  False,  "1",};
static iONode _getio8255(iONode node) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNode( node, "io8255");
}


static iONode _nextio8255(iONode node, iONode child) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNextNode( node, child);
}
static void _setio8255(iONode node, iONode p_io8255) {
  xNode( RocsWgen_digint, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * ucons88
 */
static struct __nodedef RocsWgen_ucons88 = {
  "ucons88",  "uConS88 init",  False,  "1",};
static iONode _getucons88(iONode node) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNode( node, "ucons88");
}


static iONode _nextucons88(iONode node, iONode child) {
  xNode( RocsWgen_digint, node );
  return NodeOp.findNextNode( node, child);
}
static void _setucons88(iONode node, iONode p_ucons88) {
  xNode( RocsWgen_digint, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[50] = {NULL};
static struct __nodedef* nodeList[16] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_digint.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node digint not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node digint not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_asciiprotocol;
  attrList[1] = &RocsWgen_bits;
  attrList[2] = &RocsWgen_bps;
  attrList[3] = &RocsWgen_ctsretry;
  attrList[4] = &RocsWgen_device;
  attrList[5] = &RocsWgen_dummyio;
  attrList[6] = &RocsWgen_fastclock;
  attrList[7] = &RocsWgen_fbmod;
  attrList[8] = &RocsWgen_fboffset;
  attrList[9] = &RocsWgen_fbpoll;
  attrList[10] = &RocsWgen_fbreset;
  attrList[11] = &RocsWgen_flow;
  attrList[12] = &RocsWgen_host;
  attrList[13] = &RocsWgen_identdelay;
  attrList[14] = &RocsWgen_ignorebusy;
  attrList[15] = &RocsWgen_iid;
  attrList[16] = &RocsWgen_iid_master;
  attrList[17] = &RocsWgen_iid_slave;
  attrList[18] = &RocsWgen_lib;
  attrList[19] = &RocsWgen_libpath;
  attrList[20] = &RocsWgen_localip;
  attrList[21] = &RocsWgen_locolist;
  attrList[22] = &RocsWgen_overrule;
  attrList[23] = &RocsWgen_parity;
  attrList[24] = &RocsWgen_port;
  attrList[25] = &RocsWgen_poweratstartup;
  attrList[26] = &RocsWgen_poweroffexit;
  attrList[27] = &RocsWgen_protver;
  attrList[28] = &RocsWgen_psleep;
  attrList[29] = &RocsWgen_ptsupport;
  attrList[30] = &RocsWgen_pw4acc;
  attrList[31] = &RocsWgen_readbidi;
  attrList[32] = &RocsWgen_readfb;
  attrList[33] = &RocsWgen_reportstate;
  attrList[34] = &RocsWgen_restricted;
  attrList[35] = &RocsWgen_rtsdisabled;
  attrList[36] = &RocsWgen_startpwstate;
  attrList[37] = &RocsWgen_stopbits;
  attrList[38] = &RocsWgen_stress;
  attrList[39] = &RocsWgen_sublib;
  attrList[40] = &RocsWgen_swinvert;
  attrList[41] = &RocsWgen_switchlist;
  attrList[42] = &RocsWgen_swtime;
  attrList[43] = &RocsWgen_systeminfo;
  attrList[44] = &RocsWgen_timeout;
  attrList[45] = &RocsWgen_udpportRX;
  attrList[46] = &RocsWgen_udpportTX;
  attrList[47] = &RocsWgen_userid;
  attrList[48] = &RocsWgen_v0onebreak;
  attrList[49] = NULL;
  nodeList[0] = &RocsWgen_hueconfig;
  nodeList[1] = &RocsWgen_hsi88;
  nodeList[2] = &RocsWgen_spl;
  nodeList[3] = &RocsWgen_opendcc;
  nodeList[4] = &RocsWgen_bidib;
  nodeList[5] = &RocsWgen_srcp;
  nodeList[6] = &RocsWgen_ddx;
  nodeList[7] = &RocsWgen_rocnet;
  nodeList[8] = &RocsWgen_mcs2;
  nodeList[9] = &RocsWgen_dmx;
  nodeList[10] = &RocsWgen_cbus;
  nodeList[11] = &RocsWgen_dcc232;
  nodeList[12] = &RocsWgen_loconet;
  nodeList[13] = &RocsWgen_io8255;
  nodeList[14] = &RocsWgen_ucons88;
  nodeList[15] = NULL;
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


struct __wDigInt wDigInt = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "barjut",
  "bidib",
  "cbus",
  "clock",
  "cti",
  "cts",
  "dcc232",
  "dccar",
  "ddx",
  "dinamo",
  "dmx4all",
  "dmxartnet",
  "dmxeurolite",
  "dsr",
  "easydcc",
  "ecos",
  "editspro",
  "esunavi",
  "even",
  "got",
  "hsi88",
  "hue",
  "infracar",
  "inter10",
  "lenz",
  "loconet",
  "lrc135",
  "massoth",
  "mcs2",
  "mgbox",
  "mttmfcc",
  "muet",
  "nce",
  "no",
  "none",
  "odd",
  "om32",
  "opendcc",
  "p50",
  "p50x",
  "perir",
  "raptor",
  "rclink",
  "rfid12",
  "rmx",
  "rocnet",
  "roco",
  "rocomp",
  "slx",
  "spl",
  "sprog",
  "srcp",
  "default",
  "pr3",
  "atlas",
  "cttran",
  "elite",
  "ethernet",
  "opendcc",
  "xntcp",
  "native",
  "serial",
  "socket",
  "tcp",
  "udp",
  "ulni",
  "usb",
  "tamsmc",
  "ucons88",
  "virtual",
  "xnmm",
  "xon",
  "xpressnet",
  "z21",
  "zimo",
  "zimobin",
  "zimocan",
  "zs2",
  _isasciiprotocol,
  _setasciiprotocol,
  _getbits,
  _setbits,
  _getbps,
  _setbps,
  _getctsretry,
  _setctsretry,
  _getdevice,
  _setdevice,
  _isdummyio,
  _setdummyio,
  _isfastclock,
  _setfastclock,
  _getfbmod,
  _setfbmod,
  _getfboffset,
  _setfboffset,
  _isfbpoll,
  _setfbpoll,
  _isfbreset,
  _setfbreset,
  _getflow,
  _setflow,
  _gethost,
  _sethost,
  _getidentdelay,
  _setidentdelay,
  _isignorebusy,
  _setignorebusy,
  _getiid,
  _setiid,
  _getiid_master,
  _setiid_master,
  _getiid_slave,
  _setiid_slave,
  _getlib,
  _setlib,
  _getlibpath,
  _setlibpath,
  _getlocalip,
  _setlocalip,
  _islocolist,
  _setlocolist,
  _isoverrule,
  _setoverrule,
  _getparity,
  _setparity,
  _getport,
  _setport,
  _ispoweratstartup,
  _setpoweratstartup,
  _ispoweroffexit,
  _setpoweroffexit,
  _getprotver,
  _setprotver,
  _getpsleep,
  _setpsleep,
  _isptsupport,
  _setptsupport,
  _ispw4acc,
  _setpw4acc,
  _isreadbidi,
  _setreadbidi,
  _isreadfb,
  _setreadfb,
  _isreportstate,
  _setreportstate,
  _isrestricted,
  _setrestricted,
  _isrtsdisabled,
  _setrtsdisabled,
  _isstartpwstate,
  _setstartpwstate,
  _getstopbits,
  _setstopbits,
  _isstress,
  _setstress,
  _getsublib,
  _setsublib,
  _isswinvert,
  _setswinvert,
  _isswitchlist,
  _setswitchlist,
  _getswtime,
  _setswtime,
  _issysteminfo,
  _setsysteminfo,
  _gettimeout,
  _settimeout,
  _getudpportRX,
  _setudpportRX,
  _getudpportTX,
  _setudpportTX,
  _getuserid,
  _setuserid,
  _isv0onebreak,
  _setv0onebreak,
  _gethueconfig,
  _nexthueconfig,
  _sethueconfig,
  _gethsi88,
  _nexthsi88,
  _sethsi88,
  _getspl,
  _nextspl,
  _setspl,
  _getopendcc,
  _nextopendcc,
  _setopendcc,
  _getbidib,
  _nextbidib,
  _setbidib,
  _getsrcp,
  _nextsrcp,
  _setsrcp,
  _getddx,
  _nextddx,
  _setddx,
  _getrocnet,
  _nextrocnet,
  _setrocnet,
  _getmcs2,
  _nextmcs2,
  _setmcs2,
  _getdmx,
  _nextdmx,
  _setdmx,
  _getcbus,
  _nextcbus,
  _setcbus,
  _getdcc232,
  _nextdcc232,
  _setdcc232,
  _getloconet,
  _nextloconet,
  _setloconet,
  _getio8255,
  _nextio8255,
  _setio8255,
  _getucons88,
  _nextucons88,
  _setucons88,
  _node_dump,
};
