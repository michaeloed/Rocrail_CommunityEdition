/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/roco.h"


static const char* name = "ORoco";

typedef struct ORocoData {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  iOSerial serial;
    /**  */
  iOMutex mux;
    /**  */
  int fbmod;
    /**  */
  int fbnum;
    /**  */
  Boolean readfb;
    /**  */
  Boolean dummyio;
    /**  */
  iOThread responseReader;
    /**  */
  iOThread initializer;
    /**  */
  iOThread transactor;
    /**  */
  Boolean run;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  Boolean fbState[128*8];
    /**  */
  byte lcfn[10000];
    /**  */
  Boolean power;

} *iORocoData;

static iORocoData Data( void* p ) { return (iORocoData)((iORoco)p)->base.data; }

