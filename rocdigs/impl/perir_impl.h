/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/perir.h"


static const char* name = "OPerIR";

typedef struct OPerIRData {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  iOSerial serial;
    /**  */
  Boolean run;
    /**  */
  Boolean serialOK;
    /**  */
  Boolean initOK;
    /**  */
  iOThread reader;
    /**  */
  iOThread ticker;
    /**  */
  const char* device;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  int fboffset;
    /**  */
  unsigned long readerTick[256];

} *iOPerIRData;

static iOPerIRData Data( void* p ) { return (iOPerIRData)((iOPerIR)p)->base.data; }

