/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/sprog.h"


static const char* name = "OSprog";


/** Loco slot */
typedef struct slot {
    /**  */
  int addr;
    /**  */
  Boolean longaddr;
    /**  */
  int steps;
    /**  */
  Boolean lights;
    /**  */
  Boolean fn[29];
    /**  */
  int changedfgrp;
    /**  */
  int fgrp;
    /**  */
  int V;
    /**  */
  int V_prev;
    /**  */
  Boolean dir;
    /**  */
  unsigned long idle;
} *iOSlot;
typedef struct OSprogData {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  const char* device;
    /**  */
  iOSerial serial;
    /**  */
  iOMutex mux;
    /**  */
  iOMutex slotmux;
    /**  */
  Boolean run;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  iOThread reader;
    /**  */
  int lastcmd;
    /**  */
  int lastcv;
    /**  */
  int lastvalue;
    /**  */
  iOThread writer;
    /**  */
  struct slot slots[128];
    /**  */
  Boolean power;
    /**  */
  Boolean commOK;

} *iOSprogData;

static iOSprogData Data( void* p ) { return (iOSprogData)((iOSprog)p)->base.data; }

