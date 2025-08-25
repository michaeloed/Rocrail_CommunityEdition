/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/analyse.h"


static const char* name = "OAnalyse";

typedef struct OAnalyseData {

    /**  */
  iOModel model;
    /**  */
  iONode plan;
    /**  */
  iOMap objectmap;
    /** minimum level number in plan */
  int minZlevel;
    /** maximum level number in plan */
  int maxZlevel;
    /** distance to search between 2 connectors */
  int maxConnectorDistance;
    /** maximum recursion depth */
  int maxRecursionDepth;
    /**  */
  iOList bklist;
    /**  */
  iOList preRTlist;
    /**  */
  iOList notRTlist;
    /** Set for all automatic detected routes */
  Boolean setRouteId;
    /** Set for all blocks */
  Boolean setBlockId;
    /** Assign signals to blocks */
  Boolean addSignalBlockAssignment;
    /** Assign feedbacks to blocks */
  Boolean addFeedbackBlockAssignment;
    /** Clean routeids of all automatic detected routes */
  Boolean cleanRouteId;
    /** Reset blockids in whole plan */
  Boolean resetBlockId;
    /** Reset sg assignments in all blocks */
  Boolean resetSignalBlockAssignment;
    /** Reset fb assignments in all blocks */
  Boolean resetFeedbackBlockAssignment;
    /** Basic checks on all items */
  Boolean basicCheck;
    /** Checks concerning blocks */
  Boolean blockCheck;
    /** Checks concerning routes */
  Boolean routeCheck;
    /** Check actions and conditions */
  Boolean actionCheck;
    /** Clean basic problems on all items */
  Boolean basicClean;
    /** Clean block problems */
  Boolean blockClean;
    /** Clean route problems */
  Boolean routeClean;
    /** Clean action and condition problems */
  Boolean actionClean;

} *iOAnalyseData;

static iOAnalyseData Data( void* p ) { return (iOAnalyseData)((iOAnalyse)p)->base.data; }

