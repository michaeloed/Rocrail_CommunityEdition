/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/zimo.h"


static const char* name = "OZimo";

typedef struct OZimoData {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  iOSerial serial;
    /**  */
  int ctsretry;
    /**  */
  iOMutex mux;
    /**  */
  int fbmod;
    /**  */
  Boolean readfb;
    /**  */
  iOThread feedbackReader;
    /**  */
  iOThread swTimeWatcher;
    /**  */
  Boolean run;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  int swtime;
    /**  */
  int swTime0[256*4];
    /**  */
  int swTime1[256*4];
    /**  */
  Boolean fbState[128*8];

} *iOZimoData;

static iOZimoData Data( void* p ) { return (iOZimoData)((iOZimo)p)->base.data; }

