/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/spl.h"


static const char* name = "OSPL";

typedef struct OSPLData {

    /**  */
  iONode ini;
    /**  */
  iONode splini;
    /**  */
  const char* iid;
    /**  */
  iOSerial serial;
    /**  */
  Boolean run;
    /**  */
  iOThread writer;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  Boolean connOK;
    /**  */
  unsigned char home[256];
    /**  */
  iOThread control;
    /**  */
  int fromAddr;
    /**  */
  int toAddr;
    /**  */
  int nrLEDs;

} *iOSPLData;

static iOSPLData Data( void* p ) { return (iOSPLData)((iOSPL)p)->base.data; }

