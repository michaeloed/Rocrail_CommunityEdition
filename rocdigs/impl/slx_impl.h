/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/slx.h"


static const char* name = "OSLX";


/** Loco slot */
typedef struct slot {
    /**  */
  char* id;
    /**  */
  int bus;
    /**  */
  int addr;
    /**  */
  int speed;
    /**  */
  Boolean dir;
    /**  */
  Boolean lights;
    /**  */
  Boolean fn;
} *iOSlot;
typedef struct OSLXData {

    /** key=locoID, value=slot */
  iOMap lcmap;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  iOSerial serial;
    /**  */
  iOMutex mux;
    /**  */
  iOMutex lcmux;
    /**  */
  iOThread feedbackReader;
    /**  */
  iOThread swTimeWatcher;
    /**  */
  unsigned long lastSwCmd;
    /**  */
  const char* device;
    /**  */
  serial_bps bps;
    /**  */
  int timeout;
    /**  */
  int swtime;
    /**  */
  int psleep;
    /**  */
  slxstate state;
    /**  */
  const char* iid;
    /**  */
  Boolean run;
    /**  */
  Boolean serialOK;
    /**  */
  Boolean initOK;
    /**  */
  int activebus;
    /**  */
  byte sx1[2][128];
    /**  */
  byte swstate[2][256];
    /**  */
  byte fbstate[2][256];
    /**  */
  int fbmodcnt[2];
    /**  */
  byte fbmods[2][256];
    /**  */
  Boolean dummyio;

} *iOSLXData;

static iOSLXData Data( void* p ) { return (iOSLXData)((iOSLX)p)->base.data; }

