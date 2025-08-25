/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/zimocan.h"


static const char* name = "OZimoCAN";


/** Loco slot */
typedef struct slot {
    /**  */
  char* id;
    /**  */
  int addr;
    /**  */
  int nid;
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
  Boolean shunting;
    /**  */
  Boolean manual;
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
  int nid;
    /**  */
  int addr;
    /**  */
  int prot;
} *iOPoint;
typedef struct OZimoCANData {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
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
  iOSerial serial;
    /**  */
  iOSocket socket;
    /**  */
  iOMutex serialmux;
    /**  */
  sublib_connect subConnect;
    /**  */
  sublib_disconnect subDisconnect;
    /**  */
  sublib_read subRead;
    /**  */
  sublib_write subWrite;
    /**  */
  sublib_available subAvailable;
    /**  */
  Boolean connOK;
    /**  */
  Boolean connAck;
    /**  */
  Boolean power;
    /**  */
  int NID;
    /**  */
  int masterNID;
    /**  */
  iOMutex lcmux;
    /**  */
  iOMap lcmap;
    /**  */
  iOMutex swmux;
    /**  */
  iOMap swmap;

} *iOZimoCANData;

static iOZimoCANData Data( void* p ) { return (iOZimoCANData)((iOZimoCAN)p)->base.data; }

