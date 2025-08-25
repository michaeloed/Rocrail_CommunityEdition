/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/location.h"


static const char* name = "OLocation";

typedef struct OLocationData {

    /**  */
  iONode props;
    /**  */
  int minocc;
    /**  */
  Boolean fifo;
    /**  */
  iOList arriveList;
    /**  */
  Boolean locoPending;
    /**  */
  const char* locoPendingID;
    /**  */
  iOMutex listmux;

} *iOLocationData;

static iOLocationData Data( void* p ) { return (iOLocationData)((iOLocation)p)->base.data; }

