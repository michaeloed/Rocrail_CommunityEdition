/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/ActionCtrl.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.ActionCtrl
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_actionctrl = {
  "actionctrl",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_actionctrl.name;
}
static const char* _node_remark(void) {
  return RocsWgen_actionctrl.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_actionctrl.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_actionctrl.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * allconditions
 */
static struct __attrdef RocsWgen_allconditions = {
  "allconditions",  "All conditions must be true.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isallconditions(iONode node) {
  Boolean defval = xBool( RocsWgen_allconditions );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getBool( node, "allconditions", defval );
}
static void _setallconditions(iONode node, Boolean p_allconditions) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setBool( node, "allconditions", p_allconditions );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * atcmd
 */
static struct __attrdef RocsWgen_atcmd = {
  "atcmd",  "Activate at commands.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isatcmd(iONode node) {
  Boolean defval = xBool( RocsWgen_atcmd );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getBool( node, "atcmd", defval );
}
static void _setatcmd(iONode node, Boolean p_atcmd) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setBool( node, "atcmd", p_atcmd );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * atevt
 */
static struct __attrdef RocsWgen_atevt = {
  "atevt",  "Activate at events.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isatevt(iONode node) {
  Boolean defval = xBool( RocsWgen_atevt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getBool( node, "atevt", defval );
}
static void _setatevt(iONode node, Boolean p_atevt) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setBool( node, "atevt", p_atevt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * auto
 */
static struct __attrdef RocsWgen_auto = {
  "auto",  "Activate in auto mode.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isauto(iONode node) {
  Boolean defval = xBool( RocsWgen_auto );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getBool( node, "auto", defval );
}
static void _setauto(iONode node, Boolean p_auto) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setBool( node, "auto", p_auto );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bkid
 */
static struct __attrdef RocsWgen_bkid = {
  "bkid",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getbkid(iONode node) {
  const char* defval = xStr( RocsWgen_bkid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getStr( node, "bkid", defval );
}
static void _setbkid(iONode node, const char* p_bkid) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setStr( node, "bkid", p_bkid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * carcount
 */
static struct __attrdef RocsWgen_carcount = {
  "carcount",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getcarcount(iONode node) {
  int defval = xInt( RocsWgen_carcount );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getInt( node, "carcount", defval );
}
static void _setcarcount(iONode node, int p_carcount) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setInt( node, "carcount", p_carcount );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * countedcars
 */
static struct __attrdef RocsWgen_countedcars = {
  "countedcars",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getcountedcars(iONode node) {
  int defval = xInt( RocsWgen_countedcars );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getInt( node, "countedcars", defval );
}
static void _setcountedcars(iONode node, int p_countedcars) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setInt( node, "countedcars", p_countedcars );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * counter
 */
static struct __attrdef RocsWgen_counter = {
  "counter",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getcounter(iONode node) {
  int defval = xInt( RocsWgen_counter );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getInt( node, "counter", defval );
}
static void _setcounter(iONode node, int p_counter) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setInt( node, "counter", p_counter );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * deact
 */
static struct __attrdef RocsWgen_deact = {
  "deact",  "Deactivation event.",  "",  "string",  "none",  "none,enter,in",  False,
};
static const char* _getdeact(iONode node) {
  const char* defval = xStr( RocsWgen_deact );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getStr( node, "deact", defval );
}
static void _setdeact(iONode node, const char* p_deact) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setStr( node, "deact", p_deact );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * desc
 */
static struct __attrdef RocsWgen_desc = {
  "desc",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getdesc(iONode node) {
  const char* defval = xStr( RocsWgen_desc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * duration
 */
static struct __attrdef RocsWgen_duration = {
  "duration",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getduration(iONode node) {
  int defval = xInt( RocsWgen_duration );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getInt( node, "duration", defval );
}
static void _setduration(iONode node, int p_duration) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setInt( node, "duration", p_duration );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "",  "",  "string",  "",  "*",  True,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lcclass
 */
static struct __attrdef RocsWgen_lcclass = {
  "lcclass",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getlcclass(iONode node) {
  const char* defval = xStr( RocsWgen_lcclass );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getStr( node, "lcclass", defval );
}
static void _setlcclass(iONode node, const char* p_lcclass) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setStr( node, "lcclass", p_lcclass );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lcid
 */
static struct __attrdef RocsWgen_lcid = {
  "lcid",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getlcid(iONode node) {
  const char* defval = xStr( RocsWgen_lcid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getStr( node, "lcid", defval );
}
static void _setlcid(iONode node, const char* p_lcid) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setStr( node, "lcid", p_lcid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * load
 */
static struct __attrdef RocsWgen_load = {
  "load",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getload(iONode node) {
  int defval = xInt( RocsWgen_load );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getInt( node, "load", defval );
}
static void _setload(iONode node, int p_load) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setInt( node, "load", p_load );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * manual
 */
static struct __attrdef RocsWgen_manual = {
  "manual",  "Activate in manual mode.",  "",  "bool",  "true",  "",  False,
};
static Boolean _ismanual(iONode node) {
  Boolean defval = xBool( RocsWgen_manual );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getBool( node, "manual", defval );
}
static void _setmanual(iONode node, Boolean p_manual) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setBool( node, "manual", p_manual );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mvspeed
 */
static struct __attrdef RocsWgen_mvspeed = {
  "mvspeed",  "",  "",  "float",  "0.0",  "*",  False,
};
static double _getmvspeed(iONode node) {
  double defval = xFloat( RocsWgen_mvspeed );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getFloat( node, "mvspeed", defval );
}
static void _setmvspeed(iONode node, double p_mvspeed) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setFloat( node, "mvspeed", p_mvspeed );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * param
 */
static struct __attrdef RocsWgen_param = {
  "param",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getparam(iONode node) {
  const char* defval = xStr( RocsWgen_param );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getStr( node, "param", defval );
}
static void _setparam(iONode node, const char* p_param) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setStr( node, "param", p_param );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * reset
 */
static struct __attrdef RocsWgen_reset = {
  "reset",  "Reset counter.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isreset(iONode node) {
  Boolean defval = xBool( RocsWgen_reset );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getBool( node, "reset", defval );
}
static void _setreset(iONode node, Boolean p_reset) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setBool( node, "reset", p_reset );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * state
 */
static struct __attrdef RocsWgen_state = {
  "state",  "Activation state, empty is always.",  "",  "string",  "",  "*",  False,
};
static const char* _getstate(iONode node) {
  const char* defval = xStr( RocsWgen_state );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getStr( node, "state", defval );
}
static void _setstate(iONode node, const char* p_state) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setStr( node, "state", p_state );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * stid
 */
static struct __attrdef RocsWgen_stid = {
  "stid",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getstid(iONode node) {
  const char* defval = xStr( RocsWgen_stid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getStr( node, "stid", defval );
}
static void _setstid(iONode node, const char* p_stid) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setStr( node, "stid", p_stid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * substate
 */
static struct __attrdef RocsWgen_substate = {
  "substate",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getsubstate(iONode node) {
  const char* defval = xStr( RocsWgen_substate );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getStr( node, "substate", defval );
}
static void _setsubstate(iONode node, const char* p_substate) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setStr( node, "substate", p_substate );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * temp
 */
static struct __attrdef RocsWgen_temp = {
  "temp",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _gettemp(iONode node) {
  int defval = xInt( RocsWgen_temp );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getInt( node, "temp", defval );
}
static void _settemp(iONode node, int p_temp) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setInt( node, "temp", p_temp );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * timer
 */
static struct __attrdef RocsWgen_timer = {
  "timer",  "",  "",  "int",  "-1",  "0-*",  False,
};
static int _gettimer(iONode node) {
  int defval = xInt( RocsWgen_timer );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getInt( node, "timer", defval );
}
static void _settimer(iONode node, int p_timer) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setInt( node, "timer", p_timer );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * volt
 */
static struct __attrdef RocsWgen_volt = {
  "volt",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getvolt(iONode node) {
  int defval = xInt( RocsWgen_volt );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getInt( node, "volt", defval );
}
static void _setvolt(iONode node, int p_volt) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setInt( node, "volt", p_volt );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * wheelcount
 */
static struct __attrdef RocsWgen_wheelcount = {
  "wheelcount",  "",  "",  "int",  "0",  "0-*",  False,
};
static int _getwheelcount(iONode node) {
  int defval = xInt( RocsWgen_wheelcount );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.getInt( node, "wheelcount", defval );
}
static void _setwheelcount(iONode node, int p_wheelcount) {
  if( node == NULL ) return;
  xNode( RocsWgen_actionctrl, node );
  NodeOp.setInt( node, "wheelcount", p_wheelcount );
}


/* -c-h-i-l-d-n-o-d-e------------------------------------------
 * actioncond
 */
static struct __nodedef RocsWgen_actioncond = {
  "actioncond",  "Optional condition.",  False,  "n",};
static iONode _getactioncond(iONode node) {
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.findNode( node, "actioncond");
}


static iONode _nextactioncond(iONode node, iONode child) {
  xNode( RocsWgen_actionctrl, node );
  return NodeOp.findNextNode( node, child);
}
static void _setactioncond(iONode node, iONode p_actioncond) {
  xNode( RocsWgen_actionctrl, node );
  TraceOp.println( "!!!!!TODO!!!!! Wrapper setNode()" );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[27] = {NULL};
static struct __nodedef* nodeList[2] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_actionctrl.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node actionctrl not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node actionctrl not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_allconditions;
  attrList[1] = &RocsWgen_atcmd;
  attrList[2] = &RocsWgen_atevt;
  attrList[3] = &RocsWgen_auto;
  attrList[4] = &RocsWgen_bkid;
  attrList[5] = &RocsWgen_carcount;
  attrList[6] = &RocsWgen_countedcars;
  attrList[7] = &RocsWgen_counter;
  attrList[8] = &RocsWgen_deact;
  attrList[9] = &RocsWgen_desc;
  attrList[10] = &RocsWgen_duration;
  attrList[11] = &RocsWgen_id;
  attrList[12] = &RocsWgen_lcclass;
  attrList[13] = &RocsWgen_lcid;
  attrList[14] = &RocsWgen_load;
  attrList[15] = &RocsWgen_manual;
  attrList[16] = &RocsWgen_mvspeed;
  attrList[17] = &RocsWgen_param;
  attrList[18] = &RocsWgen_reset;
  attrList[19] = &RocsWgen_state;
  attrList[20] = &RocsWgen_stid;
  attrList[21] = &RocsWgen_substate;
  attrList[22] = &RocsWgen_temp;
  attrList[23] = &RocsWgen_timer;
  attrList[24] = &RocsWgen_volt;
  attrList[25] = &RocsWgen_wheelcount;
  attrList[26] = NULL;
  nodeList[0] = &RocsWgen_actioncond;
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


struct __wActionCtrl wActionCtrl = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isallconditions,
  _setallconditions,
  _isatcmd,
  _setatcmd,
  _isatevt,
  _setatevt,
  _isauto,
  _setauto,
  _getbkid,
  _setbkid,
  _getcarcount,
  _setcarcount,
  _getcountedcars,
  _setcountedcars,
  _getcounter,
  _setcounter,
  _getdeact,
  _setdeact,
  _getdesc,
  _setdesc,
  _getduration,
  _setduration,
  _getid,
  _setid,
  _getlcclass,
  _setlcclass,
  _getlcid,
  _setlcid,
  _getload,
  _setload,
  _ismanual,
  _setmanual,
  _getmvspeed,
  _setmvspeed,
  _getparam,
  _setparam,
  _isreset,
  _setreset,
  _getstate,
  _setstate,
  _getstid,
  _setstid,
  _getsubstate,
  _setsubstate,
  _gettemp,
  _settemp,
  _gettimer,
  _settimer,
  _getvolt,
  _setvolt,
  _getwheelcount,
  _setwheelcount,
  _getactioncond,
  _nextactioncond,
  _setactioncond,
  _node_dump,
};
