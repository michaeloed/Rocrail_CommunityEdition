/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/zimobin.h"


static const char* name = "OZimoBin";

typedef struct OZimoBinData {

    /**  */
  iONode ini;
    /**  */
  int protver;
    /**  */
  const char* iid;
    /**  */
  iOSerial serial;
    /**  */
  int ctsretry;
    /**  */
  iOMutex mux;
    /**  */
  Boolean dummyio;
    /**  */
  int fbmod;
    /**  */
  int fboffset;
    /**  */
  int swtime;
    /**  */
  int timeout;
    /**  */
  Boolean readfb;
    /**  */
  iOThread transactor;
    /**  */
  iOThread packethandler;
    /**  */
  iOQueue pqueue;
    /**  */
  iOMutex pmux;
    /**  */
  iOQueue tqueue;
    /**  */
  iOMutex tmux;
    /**  */
  Boolean run;
    /**  */
  int power;
    /**  */
  int halt;
    /**  */
  int ues;
    /**  */
  int volt;
    /**  */
  int pt;
    /**  */
  int comm;
    /**  */
  iONode locolist;
    /**  */
  iONode switchlist;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;

} *iOZimoBinData;

static iOZimoBinData Data( void* p ) { return (iOZimoBinData)((iOZimoBin)p)->base.data; }

