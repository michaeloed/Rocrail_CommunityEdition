/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/virtual.h"


static const char* name = "OVirtual";


/** Queue command. */
typedef struct QCmd {
    /**  */
  iONode node;
    /**  */
  unsigned long time;
    /**  */
  unsigned long delay;
} *iQCmd;
typedef struct OVirtualData {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  iOMutex mux;
    /**  */
  int fbmod;
    /**  */
  int fboffset;
    /**  */
  int fbnum;
    /**  */
  Boolean power;
    /**  */
  Boolean enablecom;
    /**  */
  Boolean readfb;
    /**  */
  iOThread responseReader;
    /**  */
  iOThread transactor;
    /**  */
  iOThread commander;
    /**  */
  Boolean run;
    /**  */
  Boolean fbState[128*8];
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  byte cvval[1024];
    /**  */
  int boosteruid;

} *iOVirtualData;

static iOVirtualData Data( void* p ) { return (iOVirtualData)((iOVirtual)p)->base.data; }

