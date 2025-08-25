/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/esunavi.h"


static const char* name = "OESUNavi";


/** Loco slot */
typedef struct slot {
    /**  */
  char* id;
    /**  */
  int addr;
    /**  */
  int V;
    /**  */
  int Vraw;
    /**  */
  int steps;
    /**  */
  int prot;
    /**  */
  int fncnt;
    /**  */
  Boolean dir;
    /**  */
  int f0_12;
    /**  */
  int f13_20;
} *iOSlot;

/** Queue command. */
typedef struct QCmd {
    /**  */
  char msg[256];
    /**  */
  unsigned long time;
    /**  */
  unsigned long delay;
} *iQCmd;
typedef struct OESUNaviData {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  iOSerial serial;
    /**  */
  iOMutex mux;
    /**  */
  Boolean run;
    /**  */
  iOThread reader;
    /**  */
  iOThread writer;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  Boolean connOK;
    /**  */
  iOMutex lcmux;
    /**  */
  iOMap lcmap;
    /**  */
  iOThread timedQueue;
    /**  */
  int swtime;
    /**  */
  Boolean power;
    /**  */
  int A;
    /**  */
  int V;
    /**  */
  int T;

} *iOESUNaviData;

static iOESUNaviData Data( void* p ) { return (iOESUNaviData)((iOESUNavi)p)->base.data; }

