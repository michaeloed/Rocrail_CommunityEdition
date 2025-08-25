/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/Response.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Response
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_response = {
  "response",  "Interface Response.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_response.name;
}
static const char* _node_remark(void) {
  return RocsWgen_response.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_response.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_response.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * data
 */
static struct __attrdef RocsWgen_data = {
  "data",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getdata(iONode node) {
  const char* defval = xStr( RocsWgen_data );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_response, node );
  return NodeOp.getStr( node, "data", defval );
}
static void _setdata(iONode node, const char* p_data) {
  if( node == NULL ) return;
  xNode( RocsWgen_response, node );
  NodeOp.setStr( node, "data", p_data );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * error
 */
static struct __attrdef RocsWgen_error = {
  "error",  "",  "",  "bool",  "false",  "",  False,
};
static Boolean _iserror(iONode node) {
  Boolean defval = xBool( RocsWgen_error );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_response, node );
  return NodeOp.getBool( node, "error", defval );
}
static void _seterror(iONode node, Boolean p_error) {
  if( node == NULL ) return;
  xNode( RocsWgen_response, node );
  NodeOp.setBool( node, "error", p_error );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iid
 */
static struct __attrdef RocsWgen_iid = {
  "iid",  "Interface ID",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getiid(iONode node) {
  const char* defval = xStr( RocsWgen_iid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_response, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_response, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * msg
 */
static struct __attrdef RocsWgen_msg = {
  "msg",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getmsg(iONode node) {
  const char* defval = xStr( RocsWgen_msg );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_response, node );
  return NodeOp.getStr( node, "msg", defval );
}
static void _setmsg(iONode node, const char* p_msg) {
  if( node == NULL ) return;
  xNode( RocsWgen_response, node );
  NodeOp.setStr( node, "msg", p_msg );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * rc
 */
static struct __attrdef RocsWgen_rc = {
  "rc",  "",  "",  "int",  "0",  "",  False,
};
static int _getrc(iONode node) {
  int defval = xInt( RocsWgen_rc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_response, node );
  return NodeOp.getInt( node, "rc", defval );
}
static void _setrc(iONode node, int p_rc) {
  if( node == NULL ) return;
  xNode( RocsWgen_response, node );
  NodeOp.setInt( node, "rc", p_rc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * retry
 */
static struct __attrdef RocsWgen_retry = {
  "retry",  "controller buffer full; try again.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isretry(iONode node) {
  Boolean defval = xBool( RocsWgen_retry );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_response, node );
  return NodeOp.getBool( node, "retry", defval );
}
static void _setretry(iONode node, Boolean p_retry) {
  if( node == NULL ) return;
  xNode( RocsWgen_response, node );
  NodeOp.setBool( node, "retry", p_retry );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * sender
 */
static struct __attrdef RocsWgen_sender = {
  "sender",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getsender(iONode node) {
  const char* defval = xStr( RocsWgen_sender );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_response, node );
  return NodeOp.getStr( node, "sender", defval );
}
static void _setsender(iONode node, const char* p_sender) {
  if( node == NULL ) return;
  xNode( RocsWgen_response, node );
  NodeOp.setStr( node, "sender", p_sender );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * state
 */
static struct __attrdef RocsWgen_state = {
  "state",  "",  "",  "string",  "",  "*",  False,
};
static const char* _getstate(iONode node) {
  const char* defval = xStr( RocsWgen_state );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_response, node );
  return NodeOp.getStr( node, "state", defval );
}
static void _setstate(iONode node, const char* p_state) {
  if( node == NULL ) return;
  xNode( RocsWgen_response, node );
  NodeOp.setStr( node, "state", p_state );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[9] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_response.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node response not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node response not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_data;
  attrList[1] = &RocsWgen_error;
  attrList[2] = &RocsWgen_iid;
  attrList[3] = &RocsWgen_msg;
  attrList[4] = &RocsWgen_rc;
  attrList[5] = &RocsWgen_retry;
  attrList[6] = &RocsWgen_sender;
  attrList[7] = &RocsWgen_state;
  attrList[8] = NULL;
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


struct __wResponse wResponse = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  "ctserr",
  "ok",
  "rcverr",
  "snderr",
  _getdata,
  _setdata,
  _iserror,
  _seterror,
  _getiid,
  _setiid,
  _getmsg,
  _setmsg,
  _getrc,
  _setrc,
  _isretry,
  _setretry,
  _getsender,
  _setsender,
  _getstate,
  _setstate,
  _node_dump,
};
