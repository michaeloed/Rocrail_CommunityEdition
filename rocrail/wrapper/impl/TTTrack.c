/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#include "rocrail/wrapper/public/TTTrack.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.TTTrack
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_track = {
  "track",  "Turntable track.",  False,  "n",
};

static const char* _node_name(void) {
  return RocsWgen_track.name;
}
static const char* _node_remark(void) {
  return RocsWgen_track.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_track.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_track.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * bkid
 */
static struct __attrdef RocsWgen_bkid = {
  "bkid",  "block id",  "",  "string",  "NULL",  "*",  False,
};
static const char* _getbkid(iONode node) {
  const char* defval = xStr( RocsWgen_bkid );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_track, node );
  return NodeOp.getStr( node, "bkid", defval );
}
static void _setbkid(iONode node, const char* p_bkid) {
  if( node == NULL ) return;
  xNode( RocsWgen_track, node );
  NodeOp.setStr( node, "bkid", p_bkid );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * decnr
 */
static struct __attrdef RocsWgen_decnr = {
  "decnr",  "Decoder track number.",  "",  "int",  "-1",  "*",  False,
};
static int _getdecnr(iONode node) {
  int defval = xInt( RocsWgen_decnr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_track, node );
  return NodeOp.getInt( node, "decnr", defval );
}
static void _setdecnr(iONode node, int p_decnr) {
  if( node == NULL ) return;
  xNode( RocsWgen_track, node );
  NodeOp.setInt( node, "decnr", p_decnr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * desc
 */
static struct __attrdef RocsWgen_desc = {
  "desc",  "description",  "",  "string",  "",  "*",  False,
};
static const char* _getdesc(iONode node) {
  const char* defval = xStr( RocsWgen_desc );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_track, node );
  return NodeOp.getStr( node, "desc", defval );
}
static void _setdesc(iONode node, const char* p_desc) {
  if( node == NULL ) return;
  xNode( RocsWgen_track, node );
  NodeOp.setStr( node, "desc", p_desc );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nr
 */
static struct __attrdef RocsWgen_nr = {
  "nr",  "Track number.",  "",  "int",  "0",  "0-48*",  True,
};
static int _getnr(iONode node) {
  int defval = xInt( RocsWgen_nr );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_track, node );
  return NodeOp.getInt( node, "nr", defval );
}
static void _setnr(iONode node, int p_nr) {
  if( node == NULL ) return;
  xNode( RocsWgen_track, node );
  NodeOp.setInt( node, "nr", p_nr );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * oppositetrack
 */
static struct __attrdef RocsWgen_oppositetrack = {
  "oppositetrack",  "Opposite track to do a 180 degree turn.",  "",  "int",  "-1",  "*",  False,
};
static int _getoppositetrack(iONode node) {
  int defval = xInt( RocsWgen_oppositetrack );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_track, node );
  return NodeOp.getInt( node, "oppositetrack", defval );
}
static void _setoppositetrack(iONode node, int p_oppositetrack) {
  if( node == NULL ) return;
  xNode( RocsWgen_track, node );
  NodeOp.setInt( node, "oppositetrack", p_oppositetrack );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * polarization
 */
static struct __attrdef RocsWgen_polarization = {
  "polarization",  "Flip bridge polarization when entering this track.",  "",  "bool",  "false",  "",  False,
};
static Boolean _ispolarization(iONode node) {
  Boolean defval = xBool( RocsWgen_polarization );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_track, node );
  return NodeOp.getBool( node, "polarization", defval );
}
static void _setpolarization(iONode node, Boolean p_polarization) {
  if( node == NULL ) return;
  xNode( RocsWgen_track, node );
  NodeOp.setBool( node, "polarization", p_polarization );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * posfb
 */
static struct __attrdef RocsWgen_posfb = {
  "posfb",  "Feedback ID for positioning the TT.",  "",  "string",  "",  "*",  True,
};
static const char* _getposfb(iONode node) {
  const char* defval = xStr( RocsWgen_posfb );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_track, node );
  return NodeOp.getStr( node, "posfb", defval );
}
static void _setposfb(iONode node, const char* p_posfb) {
  if( node == NULL ) return;
  xNode( RocsWgen_track, node );
  NodeOp.setStr( node, "posfb", p_posfb );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * show
 */
static struct __attrdef RocsWgen_show = {
  "show",  "Visibility flag.",  "",  "bool",  "true",  "",  False,
};
static Boolean _isshow(iONode node) {
  Boolean defval = xBool( RocsWgen_show );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_track, node );
  return NodeOp.getBool( node, "show", defval );
}
static void _setshow(iONode node, Boolean p_show) {
  if( node == NULL ) return;
  xNode( RocsWgen_track, node );
  NodeOp.setBool( node, "show", p_show );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * state
 */
static struct __attrdef RocsWgen_state = {
  "state",  "pos feedback state.",  "",  "bool",  "false",  "",  False,
};
static Boolean _isstate(iONode node) {
  Boolean defval = xBool( RocsWgen_state );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_track, node );
  return NodeOp.getBool( node, "state", defval );
}
static void _setstate(iONode node, Boolean p_state) {
  if( node == NULL ) return;
  xNode( RocsWgen_track, node );
  NodeOp.setBool( node, "state", p_state );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[10] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_track.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node track not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node track not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_bkid;
  attrList[1] = &RocsWgen_decnr;
  attrList[2] = &RocsWgen_desc;
  attrList[3] = &RocsWgen_nr;
  attrList[4] = &RocsWgen_oppositetrack;
  attrList[5] = &RocsWgen_polarization;
  attrList[6] = &RocsWgen_posfb;
  attrList[7] = &RocsWgen_show;
  attrList[8] = &RocsWgen_state;
  attrList[9] = NULL;
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


struct __wTTTrack wTTTrack = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getbkid,
  _setbkid,
  _getdecnr,
  _setdecnr,
  _getdesc,
  _setdesc,
  _getnr,
  _setnr,
  _getoppositetrack,
  _setoppositetrack,
  _ispolarization,
  _setpolarization,
  _getposfb,
  _setposfb,
  _isshow,
  _setshow,
  _isstate,
  _setstate,
  _node_dump,
};
