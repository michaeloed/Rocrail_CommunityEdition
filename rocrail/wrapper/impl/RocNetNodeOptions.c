/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/RocNetNodeOptions.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.RocNetNodeOptions
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_rocnetnodeoptions = {
  "rocnetnodeoptions",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_rocnetnodeoptions.name;
}
static const char* _node_remark(void) {
  return RocsWgen_rocnetnodeoptions.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_rocnetnodeoptions.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_rocnetnodeoptions.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * adcsensor
 */
static struct __attrdef RocsWgen_adcsensor = {
  "adcsensor",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isadcsensor(iONode node) {
  Boolean defval = xBool( RocsWgen_adcsensor );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnodeoptions, node );
  return NodeOp.getBool( node, "adcsensor", defval );
}
static void _setadcsensor(iONode node, Boolean p_adcsensor) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnodeoptions, node );
  NodeOp.setBool( node, "adcsensor", p_adcsensor );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * adcthreshold
 */
static struct __attrdef RocsWgen_adcthreshold = {
  "adcthreshold",  "",  "",  "int",  "15",  "",  False,
};
static int _getadcthreshold(iONode node) {
  int defval = xInt( RocsWgen_adcthreshold );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnodeoptions, node );
  return NodeOp.getInt( node, "adcthreshold", defval );
}
static void _setadcthreshold(iONode node, int p_adcthreshold) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnodeoptions, node );
  NodeOp.setInt( node, "adcthreshold", p_adcthreshold );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iotype
 */
static struct __attrdef RocsWgen_iotype = {
  "iotype",  "",  "",  "int",  "0",  "",  False,
};
static int _getiotype(iONode node) {
  int defval = xInt( RocsWgen_iotype );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnodeoptions, node );
  return NodeOp.getInt( node, "iotype", defval );
}
static void _setiotype(iONode node, int p_iotype) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnodeoptions, node );
  NodeOp.setInt( node, "iotype", p_iotype );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * mobile
 */
static struct __attrdef RocsWgen_mobile = {
  "mobile",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _ismobile(iONode node) {
  Boolean defval = xBool( RocsWgen_mobile );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnodeoptions, node );
  return NodeOp.getBool( node, "mobile", defval );
}
static void _setmobile(iONode node, Boolean p_mobile) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnodeoptions, node );
  NodeOp.setBool( node, "mobile", p_mobile );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nickname
 */
static struct __attrdef RocsWgen_nickname = {
  "nickname",  "",  "",  "string",  "New RocNetNode",  "",  False,
};
static const char* _getnickname(iONode node) {
  const char* defval = xStr( RocsWgen_nickname );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnodeoptions, node );
  return NodeOp.getStr( node, "nickname", defval );
}
static void _setnickname(iONode node, const char* p_nickname) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnodeoptions, node );
  NodeOp.setStr( node, "nickname", p_nickname );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * rfid
 */
static struct __attrdef RocsWgen_rfid = {
  "rfid",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isrfid(iONode node) {
  Boolean defval = xBool( RocsWgen_rfid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnodeoptions, node );
  return NodeOp.getBool( node, "rfid", defval );
}
static void _setrfid(iONode node, Boolean p_rfid) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnodeoptions, node );
  NodeOp.setBool( node, "rfid", p_rfid );
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
  xNode( RocsWgen_rocnetnodeoptions, node );
  return NodeOp.getBool( node, "sack", defval );
}
static void _setsack(iONode node, Boolean p_sack) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnodeoptions, node );
  NodeOp.setBool( node, "sack", p_sack );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * soundpath
 */
static struct __attrdef RocsWgen_soundpath = {
  "soundpath",  "",  "",  "string",  "sounds",  "",  False,
};
static const char* _getsoundpath(iONode node) {
  const char* defval = xStr( RocsWgen_soundpath );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnodeoptions, node );
  return NodeOp.getStr( node, "soundpath", defval );
}
static void _setsoundpath(iONode node, const char* p_soundpath) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnodeoptions, node );
  NodeOp.setStr( node, "soundpath", p_soundpath );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * soundplayer
 */
static struct __attrdef RocsWgen_soundplayer = {
  "soundplayer",  "",  "",  "string",  "mplayer",  "",  False,
};
static const char* _getsoundplayer(iONode node) {
  const char* defval = xStr( RocsWgen_soundplayer );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnodeoptions, node );
  return NodeOp.getStr( node, "soundplayer", defval );
}
static void _setsoundplayer(iONode node, const char* p_soundplayer) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnodeoptions, node );
  NodeOp.setStr( node, "soundplayer", p_soundplayer );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * usepb
 */
static struct __attrdef RocsWgen_usepb = {
  "usepb",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _isusepb(iONode node) {
  Boolean defval = xBool( RocsWgen_usepb );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_rocnetnodeoptions, node );
  return NodeOp.getBool( node, "usepb", defval );
}
static void _setusepb(iONode node, Boolean p_usepb) {
  if( node == NULL ) return;
  xNode( RocsWgen_rocnetnodeoptions, node );
  NodeOp.setBool( node, "usepb", p_usepb );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[11] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_rocnetnodeoptions.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node rocnetnodeoptions not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node rocnetnodeoptions not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_adcsensor;
  attrList[1] = &RocsWgen_adcthreshold;
  attrList[2] = &RocsWgen_iotype;
  attrList[3] = &RocsWgen_mobile;
  attrList[4] = &RocsWgen_nickname;
  attrList[5] = &RocsWgen_rfid;
  attrList[6] = &RocsWgen_sack;
  attrList[7] = &RocsWgen_soundpath;
  attrList[8] = &RocsWgen_soundplayer;
  attrList[9] = &RocsWgen_usepb;
  attrList[10] = NULL;
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


struct __wRocNetNodeOptions wRocNetNodeOptions = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  1,
  0,
  _isadcsensor,
  _setadcsensor,
  _getadcthreshold,
  _setadcthreshold,
  _getiotype,
  _setiotype,
  _ismobile,
  _setmobile,
  _getnickname,
  _setnickname,
  _isrfid,
  _setrfid,
  _issack,
  _setsack,
  _getsoundpath,
  _setsoundpath,
  _getsoundplayer,
  _setsoundplayer,
  _isusepb,
  _setusepb,
  _node_dump,
};
