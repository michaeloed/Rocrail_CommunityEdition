/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/hue.h"


static const char* name = "OHUE";


/** Hue command. */
typedef struct HueCmd {
    /**  */
  char* methode;
    /**  */
  char* request;
    /**  */
  int cmd;
    /**  */
  int addr;
} *iHueCmd;
typedef struct OHUEData {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  iOSocket socket;
    /**  */
  Boolean run;
    /**  */
  iOThread transactor;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  iONode config;

} *iOHUEData;

static iOHUEData Data( void* p ) { return (iOHUEData)((iOHUE)p)->base.data; }

