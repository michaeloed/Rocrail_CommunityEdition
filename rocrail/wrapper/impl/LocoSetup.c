/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/LocoSetup.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.LocoSetup
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_locosetup = {
  "locosetup",  "",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_locosetup.name;
}
static const char* _node_remark(void) {
  return RocsWgen_locosetup.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_locosetup.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_locosetup.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * acceleration
 */
static struct __attrdef RocsWgen_acceleration = {
  "acceleration",  "",  "",  "int",  "10",  "",  False,
};
static int _getacceleration(iONode node) {
  int defval = xInt( RocsWgen_acceleration );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_locosetup, node );
  return NodeOp.getInt( node, "acceleration", defval );
}
static void _setacceleration(iONode node, int p_acceleration) {
  if( node == NULL ) return;
  xNode( RocsWgen_locosetup, node );
  NodeOp.setInt( node, "acceleration", p_acceleration );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * deceleration
 */
static struct __attrdef RocsWgen_deceleration = {
  "deceleration",  "",  "",  "int",  "10",  "",  False,
};
static int _getdeceleration(iONode node) {
  int defval = xInt( RocsWgen_deceleration );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_locosetup, node );
  return NodeOp.getInt( node, "deceleration", defval );
}
static void _setdeceleration(iONode node, int p_deceleration) {
  if( node == NULL ) return;
  xNode( RocsWgen_locosetup, node );
  NodeOp.setInt( node, "deceleration", p_deceleration );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * nrpulses
 */
static struct __attrdef RocsWgen_nrpulses = {
  "nrpulses",  "Number of sensor pulses per wheel rotation.",  "",  "int",  "3",  "",  False,
};
static int _getnrpulses(iONode node) {
  int defval = xInt( RocsWgen_nrpulses );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_locosetup, node );
  return NodeOp.getInt( node, "nrpulses", defval );
}
static void _setnrpulses(iONode node, int p_nrpulses) {
  if( node == NULL ) return;
  xNode( RocsWgen_locosetup, node );
  NodeOp.setInt( node, "nrpulses", p_nrpulses );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * scale
 */
static struct __attrdef RocsWgen_scale = {
  "scale",  "G scale",  "",  "float",  "29.0",  "",  False,
};
static double _getscale(iONode node) {
  double defval = xFloat( RocsWgen_scale );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_locosetup, node );
  return NodeOp.getFloat( node, "scale", defval );
}
static void _setscale(iONode node, double p_scale) {
  if( node == NULL ) return;
  xNode( RocsWgen_locosetup, node );
  NodeOp.setFloat( node, "scale", p_scale );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * wheeldiameter
 */
static struct __attrdef RocsWgen_wheeldiameter = {
  "wheeldiameter",  "Diameter of driving wheel.",  "",  "float",  "28.0",  "",  False,
};
static double _getwheeldiameter(iONode node) {
  double defval = xFloat( RocsWgen_wheeldiameter );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_locosetup, node );
  return NodeOp.getFloat( node, "wheeldiameter", defval );
}
static void _setwheeldiameter(iONode node, double p_wheeldiameter) {
  if( node == NULL ) return;
  xNode( RocsWgen_locosetup, node );
  NodeOp.setFloat( node, "wheeldiameter", p_wheeldiameter );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[6] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_locosetup.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node locosetup not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node locosetup not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_acceleration;
  attrList[1] = &RocsWgen_deceleration;
  attrList[2] = &RocsWgen_nrpulses;
  attrList[3] = &RocsWgen_scale;
  attrList[4] = &RocsWgen_wheeldiameter;
  attrList[5] = NULL;
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


struct __wLocoSetup wLocoSetup = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _getacceleration,
  _setacceleration,
  _getdeceleration,
  _setdeceleration,
  _getnrpulses,
  _setnrpulses,
  _getscale,
  _setscale,
  _getwheeldiameter,
  _setwheeldiameter,
  _node_dump,
};
