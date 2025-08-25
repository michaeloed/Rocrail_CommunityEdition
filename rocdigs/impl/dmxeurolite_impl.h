/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/dmxeurolite.h"


static const char* name = "ODMXEUROLITE";

typedef struct ODMXEUROLITEData {

    /**  */
  iONode ini;
    /**  */
  iONode dmxini;
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
  Boolean mapwhite;
    /**  */
  int framerate;
    /**  */
  Boolean refresh;
    /**  */
  byte dmxchannel[513];
    /**  */
  iOThread transactor;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;

} *iODMXEUROLITEData;

static iODMXEUROLITEData Data( void* p ) { return (iODMXEUROLITEData)((iODMXEUROLITE)p)->base.data; }

