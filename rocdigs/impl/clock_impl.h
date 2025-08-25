/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/clock.h"


static const char* name = "OClock";

typedef struct OClockData {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  const char* device;
    /**  */
  iOSerial serial;
    /**  */
  iOMutex mux;
    /**  */
  Boolean run;
    /**  */
  Boolean tick;
    /**  */
  iOThread driver;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;

} *iOClockData;

static iOClockData Data( void* p ) { return (iOClockData)((iOClock)p)->base.data; }

