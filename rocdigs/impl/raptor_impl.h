/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/raptor.h"


static const char* name = "ORaptor";

typedef struct ORaptorData {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  iOSerial serial;
    /**  */
  Boolean serialOK;
    /**  */
  Boolean run;
    /**  */
  iOMutex mux;
    /**  */
  iOThread transactor;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;

} *iORaptorData;

static iORaptorData Data( void* p ) { return (iORaptorData)((iORaptor)p)->base.data; }

