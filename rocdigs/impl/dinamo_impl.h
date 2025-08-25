/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/dinamo.h"


static const char* name = "ODINAMO";

typedef struct ODINAMOData {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  iOSerial serial;
    /**  */
  iOThread transactor;
    /**  */
  Boolean run;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  Boolean header;
    /**  */
  Boolean fault;
    /**  */
  Boolean hold;
    /**  */
  int psleep;
    /**  */
  int swtime;
    /**  */
  Boolean dummyio;
    /**  */
  iOMap blockMap;
    /**  */
  Boolean stress;

} *iODINAMOData;

static iODINAMOData Data( void* p ) { return (iODINAMOData)((iODINAMO)p)->base.data; }

