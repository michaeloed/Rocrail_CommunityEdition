/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/LNSlotServer.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.LNSlotServer
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_slotserver = {
  "slotserver",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_slotserver.name;
}
static const char* _node_remark(void) {
  return RocsWgen_slotserver.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_slotserver.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_slotserver.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * active
 */
static struct __attrdef RocsWgen_active = {
  "active",  "activate slot server support",  "",  "bool",  "false",  "",  False,
};
static Boolean _isactive(iONode node) {
  Boolean defval = xBool( RocsWgen_active );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_slotserver, node );
  return NodeOp.getBool( node, "active", defval );
}
static void _setactive(iONode node, Boolean p_active) {
  if( node == NULL ) return;
  xNode( RocsWgen_slotserver, node );
  NodeOp.setBool( node, "active", p_active );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * format
 */
static struct __attrdef RocsWgen_format = {
  "format",  "default decoder digital format",  "",  "string",  "dcc",  "dcc,mm",  False,
};
static const char* _getformat(iONode node) {
  const char* defval = xStr( RocsWgen_format );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_slotserver, node );
  return NodeOp.getStr( node, "format", defval );
}
static void _setformat(iONode node, const char* p_format) {
  if( node == NULL ) return;
  xNode( RocsWgen_slotserver, node );
  NodeOp.setStr( node, "format", p_format );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * iid
 */
static struct __attrdef RocsWgen_iid = {
  "iid",  "redirect commands to this interface ID",  "",  "string",  "",  "*",  False,
};
static const char* _getiid(iONode node) {
  const char* defval = xStr( RocsWgen_iid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_slotserver, node );
  return NodeOp.getStr( node, "iid", defval );
}
static void _setiid(iONode node, const char* p_iid) {
  if( node == NULL ) return;
  xNode( RocsWgen_slotserver, node );
  NodeOp.setStr( node, "iid", p_iid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * lconly
 */
static struct __attrdef RocsWgen_lconly = {
  "lconly",  "serve loco commands only",  "",  "bool",  "true",  "",  False,
};
static Boolean _islconly(iONode node) {
  Boolean defval = xBool( RocsWgen_lconly );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_slotserver, node );
  return NodeOp.getBool( node, "lconly", defval );
}
static void _setlconly(iONode node, Boolean p_lconly) {
  if( node == NULL ) return;
  xNode( RocsWgen_slotserver, node );
  NodeOp.setBool( node, "lconly", p_lconly );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * purge
 */
static struct __attrdef RocsWgen_purge = {
  "purge",  "activate slot purging (purgtime from parent node)",  "",  "bool",  "true",  "",  False,
};
static Boolean _ispurge(iONode node) {
  Boolean defval = xBool( RocsWgen_purge );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_slotserver, node );
  return NodeOp.getBool( node, "purge", defval );
}
static void _setpurge(iONode node, Boolean p_purge) {
  if( node == NULL ) return;
  xNode( RocsWgen_slotserver, node );
  NodeOp.setBool( node, "purge", p_purge );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * speedstep
 */
static struct __attrdef RocsWgen_speedstep = {
  "speedstep",  "default decoder speed steps",  "",  "int",  "128",  "14,28,128",  False,
};
static int _getspeedstep(iONode node) {
  int defval = xInt( RocsWgen_speedstep );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_slotserver, node );
  return NodeOp.getInt( node, "speedstep", defval );
}
static void _setspeedstep(iONode node, int p_speedstep) {
  if( node == NULL ) return;
  xNode( RocsWgen_slotserver, node );
  NodeOp.setInt( node, "speedstep", p_speedstep );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * stopatpurge
 */
static struct __attrdef RocsWgen_stopatpurge = {
  "stopatpurge",  "stop loc after purge",  "",  "bool",  "false",  "",  False,
};
static Boolean _isstopatpurge(iONode node) {
  Boolean defval = xBool( RocsWgen_stopatpurge );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_slotserver, node );
  return NodeOp.getBool( node, "stopatpurge", defval );
}
static void _setstopatpurge(iONode node, Boolean p_stopatpurge) {
  if( node == NULL ) return;
  xNode( RocsWgen_slotserver, node );
  NodeOp.setBool( node, "stopatpurge", p_stopatpurge );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[8] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_slotserver.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node slotserver not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node slotserver not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_active;
  attrList[1] = &RocsWgen_format;
  attrList[2] = &RocsWgen_iid;
  attrList[3] = &RocsWgen_lconly;
  attrList[4] = &RocsWgen_purge;
  attrList[5] = &RocsWgen_speedstep;
  attrList[6] = &RocsWgen_stopatpurge;
  attrList[7] = NULL;
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


struct __wLNSlotServer wLNSlotServer = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isactive,
  _setactive,
  _getformat,
  _setformat,
  _getiid,
  _setiid,
  _islconly,
  _setlconly,
  _ispurge,
  _setpurge,
  _getspeedstep,
  _setspeedstep,
  _isstopatpurge,
  _setstopatpurge,
  _node_dump,
};
