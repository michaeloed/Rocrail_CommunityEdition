/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/editspro.h"


static const char* name = "OEditsPro";

typedef struct OEditsProData {

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
  iOMutex mux;
    /**  */
  iOThread swTimeWatcher;
    /**  */
  iOThread writer;
    /**  */
  iOThread poller;
    /**  */
  const char* device;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  int fbmod;
    /**  */
  int swtime;
    /**  */
  Boolean dummyio;
    /**  */
  Boolean readfb;
    /**  */
  unsigned char fb[65];
    /**  */
  int lastSwCmd;
    /**  */
  Boolean v10;
    /**  */
  unsigned char addr[81];
    /**  */
  unsigned char speed[2][16];
    /**  */
  unsigned char accgate[4][2];

} *iOEditsProData;

static iOEditsProData Data( void* p ) { return (iOEditsProData)((iOEditsPro)p)->base.data; }

