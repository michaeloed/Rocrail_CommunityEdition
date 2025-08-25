/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D ! ! !
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#include "rocrail/wrapper/public/AnaOpt.h"
#include <stdarg.h>


/* ------------------------------------------------------------
 * WRAPPER: rocrail.AnaOpt
 * ------------------------------------------------------------
 */
static struct __nodedef RocsWgen_anaopt = {
  "anaopt",  "Analyser options.",  False,  "1",
};

static const char* _node_name(void) {
  return RocsWgen_anaopt.name;
}
static const char* _node_remark(void) {
  return RocsWgen_anaopt.remark;
}
static Boolean _node_required(void) {
  return RocsWgen_anaopt.required;
}
static const char* _node_cardinality(void) {
  return RocsWgen_anaopt.cardinality;
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * actionCheck
 */
static struct __attrdef RocsWgen_actionCheck = {
  "actionCheck",  "Check actions and conditions",  "",  "bool",  "true",  "",  False,
};
static Boolean _isactionCheck(iONode node) {
  Boolean defval = xBool( RocsWgen_actionCheck );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_anaopt, node );
  return NodeOp.getBool( node, "actionCheck", defval );
}
static void _setactionCheck(iONode node, Boolean p_actionCheck) {
  if( node == NULL ) return;
  xNode( RocsWgen_anaopt, node );
  NodeOp.setBool( node, "actionCheck", p_actionCheck );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * actionClean
 */
static struct __attrdef RocsWgen_actionClean = {
  "actionClean",  "Clean action and condition problems",  "",  "bool",  "false",  "",  False,
};
static Boolean _isactionClean(iONode node) {
  Boolean defval = xBool( RocsWgen_actionClean );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_anaopt, node );
  return NodeOp.getBool( node, "actionClean", defval );
}
static void _setactionClean(iONode node, Boolean p_actionClean) {
  if( node == NULL ) return;
  xNode( RocsWgen_anaopt, node );
  NodeOp.setBool( node, "actionClean", p_actionClean );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addFeedbackBlockAssignment
 */
static struct __attrdef RocsWgen_addFeedbackBlockAssignment = {
  "addFeedbackBlockAssignment",  "Assign feedbacks to blocks",  "",  "bool",  "false",  "",  False,
};
static Boolean _isaddFeedbackBlockAssignment(iONode node) {
  Boolean defval = xBool( RocsWgen_addFeedbackBlockAssignment );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_anaopt, node );
  return NodeOp.getBool( node, "addFeedbackBlockAssignment", defval );
}
static void _setaddFeedbackBlockAssignment(iONode node, Boolean p_addFeedbackBlockAssignment) {
  if( node == NULL ) return;
  xNode( RocsWgen_anaopt, node );
  NodeOp.setBool( node, "addFeedbackBlockAssignment", p_addFeedbackBlockAssignment );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * addSignalBlockAssignment
 */
static struct __attrdef RocsWgen_addSignalBlockAssignment = {
  "addSignalBlockAssignment",  "Assign signals to blocks",  "",  "bool",  "false",  "",  False,
};
static Boolean _isaddSignalBlockAssignment(iONode node) {
  Boolean defval = xBool( RocsWgen_addSignalBlockAssignment );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_anaopt, node );
  return NodeOp.getBool( node, "addSignalBlockAssignment", defval );
}
static void _setaddSignalBlockAssignment(iONode node, Boolean p_addSignalBlockAssignment) {
  if( node == NULL ) return;
  xNode( RocsWgen_anaopt, node );
  NodeOp.setBool( node, "addSignalBlockAssignment", p_addSignalBlockAssignment );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * basicCheck
 */
static struct __attrdef RocsWgen_basicCheck = {
  "basicCheck",  "Basic checks on all items",  "",  "bool",  "true",  "",  False,
};
static Boolean _isbasicCheck(iONode node) {
  Boolean defval = xBool( RocsWgen_basicCheck );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_anaopt, node );
  return NodeOp.getBool( node, "basicCheck", defval );
}
static void _setbasicCheck(iONode node, Boolean p_basicCheck) {
  if( node == NULL ) return;
  xNode( RocsWgen_anaopt, node );
  NodeOp.setBool( node, "basicCheck", p_basicCheck );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * basicClean
 */
static struct __attrdef RocsWgen_basicClean = {
  "basicClean",  "Clean basic problems on all items",  "",  "bool",  "false",  "",  False,
};
static Boolean _isbasicClean(iONode node) {
  Boolean defval = xBool( RocsWgen_basicClean );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_anaopt, node );
  return NodeOp.getBool( node, "basicClean", defval );
}
static void _setbasicClean(iONode node, Boolean p_basicClean) {
  if( node == NULL ) return;
  xNode( RocsWgen_anaopt, node );
  NodeOp.setBool( node, "basicClean", p_basicClean );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blockCheck
 */
static struct __attrdef RocsWgen_blockCheck = {
  "blockCheck",  "Checks concerning blocks",  "",  "bool",  "true",  "",  False,
};
static Boolean _isblockCheck(iONode node) {
  Boolean defval = xBool( RocsWgen_blockCheck );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_anaopt, node );
  return NodeOp.getBool( node, "blockCheck", defval );
}
static void _setblockCheck(iONode node, Boolean p_blockCheck) {
  if( node == NULL ) return;
  xNode( RocsWgen_anaopt, node );
  NodeOp.setBool( node, "blockCheck", p_blockCheck );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * blockClean
 */
static struct __attrdef RocsWgen_blockClean = {
  "blockClean",  "Clean block problems",  "",  "bool",  "false",  "",  False,
};
static Boolean _isblockClean(iONode node) {
  Boolean defval = xBool( RocsWgen_blockClean );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_anaopt, node );
  return NodeOp.getBool( node, "blockClean", defval );
}
static void _setblockClean(iONode node, Boolean p_blockClean) {
  if( node == NULL ) return;
  xNode( RocsWgen_anaopt, node );
  NodeOp.setBool( node, "blockClean", p_blockClean );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * cleanRouteId
 */
static struct __attrdef RocsWgen_cleanRouteId = {
  "cleanRouteId",  "Clean routeid of all automatic detected routes",  "",  "bool",  "true",  "",  False,
};
static Boolean _iscleanRouteId(iONode node) {
  Boolean defval = xBool( RocsWgen_cleanRouteId );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_anaopt, node );
  return NodeOp.getBool( node, "cleanRouteId", defval );
}
static void _setcleanRouteId(iONode node, Boolean p_cleanRouteId) {
  if( node == NULL ) return;
  xNode( RocsWgen_anaopt, node );
  NodeOp.setBool( node, "cleanRouteId", p_cleanRouteId );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * maxRecursionDepth
 */
static struct __attrdef RocsWgen_maxRecursionDepth = {
  "maxRecursionDepth",  "maximum recursion depth",  "",  "int",  "100",  "",  False,
};
static int _getmaxRecursionDepth(iONode node) {
  int defval = xInt( RocsWgen_maxRecursionDepth );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_anaopt, node );
  return NodeOp.getInt( node, "maxRecursionDepth", defval );
}
static void _setmaxRecursionDepth(iONode node, int p_maxRecursionDepth) {
  if( node == NULL ) return;
  xNode( RocsWgen_anaopt, node );
  NodeOp.setInt( node, "maxRecursionDepth", p_maxRecursionDepth );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * resetBlockId
 */
static struct __attrdef RocsWgen_resetBlockId = {
  "resetBlockId",  "Reset blockid in whole plan",  "",  "bool",  "true",  "",  False,
};
static Boolean _isresetBlockId(iONode node) {
  Boolean defval = xBool( RocsWgen_resetBlockId );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_anaopt, node );
  return NodeOp.getBool( node, "resetBlockId", defval );
}
static void _setresetBlockId(iONode node, Boolean p_resetBlockId) {
  if( node == NULL ) return;
  xNode( RocsWgen_anaopt, node );
  NodeOp.setBool( node, "resetBlockId", p_resetBlockId );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * resetFeedbackBlockAssignment
 */
static struct __attrdef RocsWgen_resetFeedbackBlockAssignment = {
  "resetFeedbackBlockAssignment",  "Reset feedback assignments in all blocks",  "",  "bool",  "false",  "",  False,
};
static Boolean _isresetFeedbackBlockAssignment(iONode node) {
  Boolean defval = xBool( RocsWgen_resetFeedbackBlockAssignment );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_anaopt, node );
  return NodeOp.getBool( node, "resetFeedbackBlockAssignment", defval );
}
static void _setresetFeedbackBlockAssignment(iONode node, Boolean p_resetFeedbackBlockAssignment) {
  if( node == NULL ) return;
  xNode( RocsWgen_anaopt, node );
  NodeOp.setBool( node, "resetFeedbackBlockAssignment", p_resetFeedbackBlockAssignment );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * resetSignalBlockAssignment
 */
static struct __attrdef RocsWgen_resetSignalBlockAssignment = {
  "resetSignalBlockAssignment",  "Reset signal assignments in all blocks",  "",  "bool",  "false",  "",  False,
};
static Boolean _isresetSignalBlockAssignment(iONode node) {
  Boolean defval = xBool( RocsWgen_resetSignalBlockAssignment );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_anaopt, node );
  return NodeOp.getBool( node, "resetSignalBlockAssignment", defval );
}
static void _setresetSignalBlockAssignment(iONode node, Boolean p_resetSignalBlockAssignment) {
  if( node == NULL ) return;
  xNode( RocsWgen_anaopt, node );
  NodeOp.setBool( node, "resetSignalBlockAssignment", p_resetSignalBlockAssignment );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * routeCheck
 */
static struct __attrdef RocsWgen_routeCheck = {
  "routeCheck",  "Checks concerning routes",  "",  "bool",  "true",  "",  False,
};
static Boolean _isrouteCheck(iONode node) {
  Boolean defval = xBool( RocsWgen_routeCheck );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_anaopt, node );
  return NodeOp.getBool( node, "routeCheck", defval );
}
static void _setrouteCheck(iONode node, Boolean p_routeCheck) {
  if( node == NULL ) return;
  xNode( RocsWgen_anaopt, node );
  NodeOp.setBool( node, "routeCheck", p_routeCheck );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * routeClean
 */
static struct __attrdef RocsWgen_routeClean = {
  "routeClean",  "Clean route problems",  "",  "bool",  "false",  "",  False,
};
static Boolean _isrouteClean(iONode node) {
  Boolean defval = xBool( RocsWgen_routeClean );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_anaopt, node );
  return NodeOp.getBool( node, "routeClean", defval );
}
static void _setrouteClean(iONode node, Boolean p_routeClean) {
  if( node == NULL ) return;
  xNode( RocsWgen_anaopt, node );
  NodeOp.setBool( node, "routeClean", p_routeClean );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * setBlockId
 */
static struct __attrdef RocsWgen_setBlockId = {
  "setBlockId",  "Set blockid for all blocks",  "",  "bool",  "true",  "",  False,
};
static Boolean _issetBlockId(iONode node) {
  Boolean defval = xBool( RocsWgen_setBlockId );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_anaopt, node );
  return NodeOp.getBool( node, "setBlockId", defval );
}
static void _setsetBlockId(iONode node, Boolean p_setBlockId) {
  if( node == NULL ) return;
  xNode( RocsWgen_anaopt, node );
  NodeOp.setBool( node, "setBlockId", p_setBlockId );
}


/* -a-t-t-r-i-b-u-t-e------------------------------------------
 * setRouteId
 */
static struct __attrdef RocsWgen_setRouteId = {
  "setRouteId",  "Set routeid for all automatic detected routes",  "",  "bool",  "true",  "",  False,
};
static Boolean _issetRouteId(iONode node) {
  Boolean defval = xBool( RocsWgen_setRouteId );
  
  if( node == NULL ) {
    return defval;
  }
  xNode( RocsWgen_anaopt, node );
  return NodeOp.getBool( node, "setRouteId", defval );
}
static void _setsetRouteId(iONode node, Boolean p_setRouteId) {
  if( node == NULL ) return;
  xNode( RocsWgen_anaopt, node );
  NodeOp.setBool( node, "setRouteId", p_setRouteId );
}

/* -a-t-t-r-i-b-u-t-e-t-e-s-t----------------------------------

 * dump

 */
static struct __attrdef* attrList[18] = {NULL};
static struct __nodedef* nodeList[1] = {NULL};
static Boolean _node_dump(iONode node) {
  if( node == NULL && RocsWgen_anaopt.required ) {
    TraceOp.trc( "param", TRCLEVEL_EXCEPTION, __LINE__, 9999, ">>>>> Required node anaopt not found!" );
    return False;
  }
  else if( node == NULL ) {
    TraceOp.trc( "param", TRCLEVEL_WRAPPER, __LINE__, 9999, "Node anaopt not found!" );
    return True;
  }
  TraceOp.trc( "param", TRCLEVEL_PARAM, __LINE__, 9999, "" );
  attrList[0] = &RocsWgen_actionCheck;
  attrList[1] = &RocsWgen_actionClean;
  attrList[2] = &RocsWgen_addFeedbackBlockAssignment;
  attrList[3] = &RocsWgen_addSignalBlockAssignment;
  attrList[4] = &RocsWgen_basicCheck;
  attrList[5] = &RocsWgen_basicClean;
  attrList[6] = &RocsWgen_blockCheck;
  attrList[7] = &RocsWgen_blockClean;
  attrList[8] = &RocsWgen_cleanRouteId;
  attrList[9] = &RocsWgen_maxRecursionDepth;
  attrList[10] = &RocsWgen_resetBlockId;
  attrList[11] = &RocsWgen_resetFeedbackBlockAssignment;
  attrList[12] = &RocsWgen_resetSignalBlockAssignment;
  attrList[13] = &RocsWgen_routeCheck;
  attrList[14] = &RocsWgen_routeClean;
  attrList[15] = &RocsWgen_setBlockId;
  attrList[16] = &RocsWgen_setRouteId;
  attrList[17] = NULL;
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


struct __wAnaOpt wAnaOpt = {
  _node_name,
  _node_remark,
  _node_required,
  _node_cardinality,
  _isactionCheck,
  _setactionCheck,
  _isactionClean,
  _setactionClean,
  _isaddFeedbackBlockAssignment,
  _setaddFeedbackBlockAssignment,
  _isaddSignalBlockAssignment,
  _setaddSignalBlockAssignment,
  _isbasicCheck,
  _setbasicCheck,
  _isbasicClean,
  _setbasicClean,
  _isblockCheck,
  _setblockCheck,
  _isblockClean,
  _setblockClean,
  _iscleanRouteId,
  _setcleanRouteId,
  _getmaxRecursionDepth,
  _setmaxRecursionDepth,
  _isresetBlockId,
  _setresetBlockId,
  _isresetFeedbackBlockAssignment,
  _setresetFeedbackBlockAssignment,
  _isresetSignalBlockAssignment,
  _setresetSignalBlockAssignment,
  _isrouteCheck,
  _setrouteCheck,
  _isrouteClean,
  _setrouteClean,
  _issetBlockId,
  _setsetBlockId,
  _issetRouteId,
  _setsetRouteId,
  _node_dump,
};
