/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/Tour.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.Tour
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_tour = {
  "tour",  "",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_tour.name;
}
static const char* _node_remark(void) {
  return RocsWgen_tour.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_tour.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_tour.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * id
 */
static struct __attrdef RocsWgen_id = {
  "id",  "tour name",  "",  "string",  "",  "*",  True,
};
static const char* _getid(iONode node) {
  const char* defval = xStr( RocsWgen_id );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tour, node );
  return NodeOp.getStr( node, "id", defval );
}
static void _setid(iONode node, const char* p_id) {
  if( node == NULL ) return;
  xNode( RocsWgen_tour, node );
  NodeOp.setStr( node, "id", p_id );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * recycle
 */
static struct __attrdef RocsWgen_recycle = {
  "recycle",  "Recycle this tour.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isrecycle(iONode node) {
  Boolean defval = xBool( RocsWgen_recycle );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tour, node );
  return NodeOp.getBool( node, "recycle", defval );
}
static void _setrecycle(iONode node, Boolean p_recycle) {
  if( node == NULL ) return;
  xNode( RocsWgen_tour, node );
  NodeOp.setBool( node, "recycle", p_recycle );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * schedules
 */
static struct __attrdef RocsWgen_schedules = {
  "schedules",  "csv list of schedules",  "",  "string",  "",  "*",  True,
};
static const char* _getschedules(iONode node) {
  const char* defval = xStr( RocsWgen_schedules );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_tour, node );
  return NodeOp.getStr( node, "schedules", defval );
}
static void _setschedules(iONode node, const char* p_schedules) {
  if( node == NULL ) return;
  xNode( RocsWgen_tour, node );
  NodeOp.setStr( node, "schedules", p_schedules );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[4] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_tour.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node tour not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node tour not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_id;
  attrList[1] = &RocsWgen_recycle;
  attrList[2] = &RocsWgen_schedules;
  attrList[3] = NULL;
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


struct __wTour wTour = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getid,
  _setid,
  _isrecycle,
  _setrecycle,
  _getschedules,
  _setschedules,
  _node_dump,
};
