/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/infracar.h"


static const char* name = "OInfracar";

typedef struct OInfracarData {

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
  iOThread writer;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  Boolean dummyio;

} *iOInfracarData;

static iOInfracarData Data( void* p ) { return (iOInfracarData)((iOInfracar)p)->base.data; }

