/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/inter10.h"


static const char* name = "OInter10";

typedef struct OInter10Data {

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
  const char* device;
    /**  */
  serial_bps bps;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;

} *iOInter10Data;

static iOInter10Data Data( void* p ) { return (iOInter10Data)((iOInter10)p)->base.data; }

