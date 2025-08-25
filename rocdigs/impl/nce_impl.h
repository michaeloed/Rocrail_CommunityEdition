/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/nce.h"


static const char* name = "ONCE";

typedef struct ONCEData {

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
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  iOThread poller;
    /**  */
  int aiucnt;
    /**  */
  int aiuaddr;

} *iONCEData;

static iONCEData Data( void* p ) { return (iONCEData)((iONCE)p)->base.data; }

