/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/xpressnet.h"


static const char* name = "OXpressNet";


/** Queue command. */
typedef struct QCmd {
    /**  */
  byte out[32];
    /**  */
  unsigned long time;
    /**  */
  unsigned long delay;
} *iQCmd;

/** Loco slot */
typedef struct slot {
    /**  */
  char* id;
    /**  */
  int addr;
    /**  */
  int protocol;
    /**  */
  int steps;
    /**  */
  int speed;
    /**  */
  Boolean dir;
    /**  */
  Boolean lights;
    /**  */
  int fn;
} *iOSlot;
typedef struct OXpressNetData {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  iOSerial serial;
    /**  */
  iOSocket socket;
    /**  */
  iOMutex serialmux;
    /**  */
  int fboffset;
    /**  */
  Boolean v2;
    /**  */
  Boolean dummyio;
    /**  */
  iOThread reader;
    /**  */
  iOThread initializer;
    /**  */
  iOThread transactor;
    /**  */
  iOThread timedQueue;
    /**  */
  long lastcmd;
    /**  */
  iOThread timeOutWD;
    /**  */
  iOThread availWD;
    /**  */
  Boolean availFlag;
    /**  */
  Boolean run;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  int swtime;
    /**  */
  Boolean startpwstate;
    /**  */
  Boolean fastclock;
    /**  */
  iOMap slotMap;
    /** TODO: Replace with slot map. */
  byte lcfn[10000];
    /**  */
  sublib_read subRead;
    /**  */
  sublib_write subWrite;
    /**  */
  sublib_init subInit;
    /**  */
  sublib_connect subConnect;
    /**  */
  sublib_disconnect subDisConn;
    /**  */
  sublib_available subAvail;
    /**  */
  sublib_translate subTranslate;
    /**  */
  int fbmod;
    /**  */
  Boolean readfb;
    /**  */
  Boolean fbState[128*8];
    /**  */
  int interfaceVersion;
    /**  */
  Boolean power;
    /**  */
  Boolean ignoreBusy;
    /**  */
  iOThread infoQueue;
    /**  */
  int infoaddr;
    /**  */
  Boolean connectpending;
    /**  */
  int fbmodcnt;
    /**  */
  byte fbmods[256];
    /**  */
  byte startbyte;
    /**  */
  Boolean enablecom;

} *iOXpressNetData;

static iOXpressNetData Data( void* p ) { return (iOXpressNetData)((iOXpressNet)p)->base.data; }

