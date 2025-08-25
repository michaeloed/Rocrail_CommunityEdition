/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/z21.h"


static const char* name = "OZ21";


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
  Boolean dir;
    /**  */
  Boolean lights;
    /**  */
  Boolean f[32];
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
  int gate;
    /**  */
  Boolean singlegate;
    /**  */
  Boolean timerpending;
} *iOPoint;

/** Queue command. */
typedef struct QCmd {
    /**  */
  byte out[32];
    /**  */
  unsigned long time;
    /**  */
  unsigned long delay;
    /**  */
  Boolean singlegate;
    /**  */
  int gate;
} *iQCmd;
typedef struct OZ21Data {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  Boolean run;
    /**  */
  Boolean serialOK;
    /**  */
  iOThread reader;
    /**  */
  iOThread writer;
    /**  */
  iOThread timedqueue;
    /**  */
  iOThread watchdog;
    /**  */
  iOSocket rwUDP;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  Boolean power;
    /**  */
  byte sensor[256];
    /**  */
  int load;
    /**  */
  int ptload;
    /**  */
  int temp;
    /**  */
  int volt;
    /**  */
  int swtime;
    /**  */
  long lastcmd;
    /**  */
  byte lcmode[256];
    /**  */
  byte swmode[256];
    /**  */
  iOMutex lcmux;
    /**  */
  iOMap lcmap;
    /**  */
  iOMutex swmux;
    /**  */
  iOMap swmap;
    /**  */
  iONode locolist;
    /**  */
  iONode switchlist;
    /**  */
  Boolean zerobased;

} *iOZ21Data;

static iOZ21Data Data( void* p ) { return (iOZ21Data)((iOZ21)p)->base.data; }

