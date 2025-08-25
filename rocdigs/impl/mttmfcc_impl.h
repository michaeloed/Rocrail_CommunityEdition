/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/mttmfcc.h"


static const char* name = "OMttmFcc";


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
  Boolean sx1;
    /**  */
  Boolean dir;
    /**  */
  Boolean lights;
    /**  */
  byte f1_8;
    /**  */
  byte f9_16;
    /**  */
  int sx1aux1;
    /**  */
  int sx1aux2;
    /**  */
  long lastcmd;
} *iOSlot;

/**  */
typedef struct point {
    /**  */
  char* id;
    /**  */
  int bus;
    /**  */
  int addr;
    /**  */
  int port;
    /**  */
  int type;
    /**  */
  long lastcmd;
} *iOPoint;
typedef struct OMttmFccData {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  iOMutex mux;
    /**  */
  iOMutex lcmux;
    /**  */
  iOMutex pointmux;
    /**  */
  iOSerial serial;
    /**  */
  Boolean run;
    /**  */
  Boolean serialOK;
    /**  */
  Boolean initOK;
    /**  */
  Boolean swInited;
    /**  */
  Boolean fbInited;
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
  iOMap pointmap;
    /**  */
  byte sx1[2][128];
    /**  */
  byte sx2[2][128];
    /**  */
  iOThread sxReader;
    /**  */
  byte swstate[2][128];
    /**  */
  byte fbstate[2][128];
    /**  */
  int fbmodcnt[2];
    /**  */
  byte fbmods[2][128];
    /**  */
  Boolean dummyio;
    /**  */
  byte power;

} *iOMttmFccData;

static iOMttmFccData Data( void* p ) { return (iOMttmFccData)((iOMttmFcc)p)->base.data; }

