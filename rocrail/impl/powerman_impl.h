/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/powerman.h"


static const char* name = "OPowerMan";

typedef struct OPowerManData {

    /**  */
  iONode props;
    /**  */
  iOMap boostermap;
    /**  */
  iOMutex boostermapmux;
    /**  */
  iOMap scmap;
    /**  */
  iOMap pwmap;

} *iOPowerManData;

static iOPowerManData Data( void* p ) { return (iOPowerManData)((iOPowerMan)p)->base.data; }

