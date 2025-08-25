/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/rclink.h"


static const char* name = "ORcLink";

typedef struct ORcLinkData {

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
  serial_bps bps;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  int fboffset;
    /**  */
  int ident[24];

} *iORcLinkData;

static iORcLinkData Data( void* p ) { return (iORcLinkData)((iORcLink)p)->base.data; }

