/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/rci.h"


static const char* name = "ORCI";

typedef struct ORCIData {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  iOSerial serial;
    /**  */
  iOMutex mux;
    /**  */
  iOThread feedbackReader;
    /**  */
  Boolean run;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;

} *iORCIData;

static iORCIData Data( void* p ) { return (iORCIData)((iORCI)p)->base.data; }

