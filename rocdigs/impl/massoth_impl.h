/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/massoth.h"


static const char* name = "OMassoth";


/** Loco slot */
typedef struct slot {
    /**  */
  char* id;
    /**  */
  int bus;
    /**  */
  int addr;
    /**  */
  int index;
    /**  */
  int protocol;
    /**  */
  int steps;
    /**  */
  int speed;
    /**  */
  Boolean ebreak;
    /**  */
  Boolean dir;
    /**  */
  Boolean lights;
    /**  */
  byte f1_8;
    /**  */
  byte f9_16;
    /**  */
  byte f17_32;
    /**  */
  long idle;
} *iOSlot;
typedef struct OMassothData {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  iOMutex mux;
    /**  */
  iOMutex lcmux;
    /**  */
  iOSerial serial;
    /**  */
  serial_flow flow;
    /**  */
  Boolean run;
    /**  */
  Boolean serialOK;
    /**  */
  Boolean initOK;
    /**  */
  iOThread transactor;
    /**  */
  iOThread poller;
    /**  */
  const char* device;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /** key=locoID, value=slot */
  iOMap lcmap;
    /**  */
  iOThread reader;
    /**  */
  Boolean dummyio;
    /**  */
  Boolean initialized;
    /**  */
  iOThread ticker;
    /**  */
  iOThread purger;
    /**  */
  Boolean fbreset;
    /**  */
  Boolean systeminfo;
    /**  */
  Boolean useParallelFunctions;
    /**  */
  int ptcv;
    /**  */
  int ptval;
    /**  */
  Boolean power;
    /**  */
  int load;
    /**  */
  int freeslots;
    /**  */
  Boolean shutdown;
    /**  */
  Boolean allPurged;
    /**  */
  iOThread stressRunner;
    /**  */
  Boolean didShowInfo;

} *iOMassothData;

static iOMassothData Data( void* p ) { return (iOMassothData)((iOMassoth)p)->base.data; }

