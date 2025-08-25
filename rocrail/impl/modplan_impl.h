/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/modplan.h"


static const char* name = "OModPlan";

typedef struct OModPlanData {

    /**  */
  iONode model;
    /**  */
  iONode modplan;
    /**  */
  iOList modList;
    /**  */
  iOList modconList;
    /**  */
  iOList unresolvedRouteList;
    /**  */
  iOMap fbeventMap;
    /**  */
  iOMap blockMap;
    /**  */
  iOMap routeIdMap;
    /**  */
  iOMap mod2routeIdMap;
    /**  */
  const char* endmodid;

} *iOModPlanData;

static iOModPlanData Data( void* p ) { return (iOModPlanData)((iOModPlan)p)->base.data; }

