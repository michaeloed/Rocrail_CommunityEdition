/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/zs2.h"


static const char* name = "OZS2";


/** Loco slot */
typedef struct slot {
    /**  */
  char* id;
    /**  */
  int nr;
    /**  */
  int bus;
    /**  */
  int addr;
    /**  */
  int speed;
    /**  */
  int steps;
    /**  */
  Boolean sx2;
    /**  */
  Boolean dcc;
    /**  */
  Boolean dir;
    /**  */
  Boolean lights;
    /**  */
  int fcnt;
    /**  */
  Boolean fn;
    /**  */
  int fx1;
    /**  */
  int fx2;
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
typedef struct OZS2Data {

    /** key=locoID, value=slot */
  iOMap lcmap;
    /** key=ID, value=point */
  iOMap pointmap;
    /** key=bus_addr, value=fbbyte */
  iOMap fbmap;
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
  iOMutex pointmux;
    /**  */
  iOThread reader;
    /**  */
  iOThread writer;
    /**  */
  const char* device;
    /**  */
  serial_bps bps;
    /**  */
  int timeout;
    /**  */
  int swtime;
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
  byte sx[3][128];
    /**  */
  byte swstate[3][256];
    /**  */
  byte fbstate[3][256];
    /**  */
  int fbmodcnt[3];
    /**  */
  byte fbmods[3][256];
    /**  */
  Boolean dummyio;
    /**  */
  int sx2slotcnt;

} *iOZS2Data;

static iOZS2Data Data( void* p ) { return (iOZS2Data)((iOZS2)p)->base.data; }

