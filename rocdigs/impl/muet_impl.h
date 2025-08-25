/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/muet.h"


static const char* name = "OMuet";


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
typedef struct OMuetData {

    /** key=locoID, value=slot */
  iOMap lcmap;
    /** key=ID, value=point */
  iOMap pointmap;
    /** key=bus_addr, value=fbbyte */
  iOMap fbmap;
    /** key=bus_addr, value=fbbyte */
  iOMap identmap;
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
  byte sx1[2][128];
    /**  */
  byte fbstate[2][256];
    /**  */
  int fbmodcnt[2];
    /**  */
  byte fbmods[2][256];
    /**  */
  Boolean dummyio;

} *iOMuetData;

static iOMuetData Data( void* p ) { return (iOMuetData)((iOMuet)p)->base.data; }

