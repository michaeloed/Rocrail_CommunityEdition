/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/dmx4all.h"


static const char* name = "ODMX4ALL";

typedef struct ODMX4ALLData {

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

} *iODMX4ALLData;

static iODMX4ALLData Data( void* p ) { return (iODMX4ALLData)((iODMX4ALL)p)->base.data; }

