/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/route.h"


static const char* name = "ORoute";

typedef struct ORouteData {

    /**  */
  const char* lockedId;
    /**  */
  const char* requestId;
    /**  */
  iONode props;
    /**  */
  Boolean reverse;
    /**  */
  char* routeLockId;
    /**  */
  Boolean ctc1;
    /**  */
  Boolean ctc2;
    /**  */
  Boolean ctc3;
    /**  */
  Boolean testlocked;

} *iORouteData;

static iORouteData Data( void* p ) { return (iORouteData)((iORoute)p)->base.data; }

