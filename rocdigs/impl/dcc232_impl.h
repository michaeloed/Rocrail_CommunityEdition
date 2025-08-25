/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/dcc232.h"


static const char* name = "ODCC232";


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
    /**  */
  int refreshcnt;
    /**  */
  byte lcstream[64];
    /**  */
  byte fnstream[64];
} *iOSlot;
typedef struct ODCC232Data {

    /**  */
  iONode ini;
    /**  */
  iONode dcc232;
    /**  */
  const char* iid;
    /**  */
  const char* device;
    /**  */
  int portbase;
    /**  */
  iOSerial serial;
    /**  */
  iOMutex mux;
    /**  */
  iOMutex slotmux;
    /**  */
  Boolean run;
    /**  */
  Boolean comOK;
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
  iOThread watchdog;
    /**  */
  Boolean purge;
    /**  */
  int purgetime;
    /**  */
  Boolean shortcut;
    /**  */
  int shortcutdelay;
    /**  */
  Boolean ptflag;
    /**  */
  Boolean fastcvget;

} *iODCC232Data;

static iODCC232Data Data( void* p ) { return (iODCC232Data)((iODCC232)p)->base.data; }

