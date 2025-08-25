/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/cbus.h"


static const char* name = "OCBUS";


/** Loco slot */
typedef struct slot {
    /**  */
  char* id;
    /**  */
  int session;
    /**  */
  int addr;
    /**  */
  int speed;
    /**  */
  int rawspeed;
    /**  */
  int steps;
    /**  */
  Boolean dir;
    /**  */
  Boolean lights;
    /**  */
  Boolean f[32];
    /**  */
  long lastkeep;
    /**  */
  Boolean releasereq;
} *iOSlot;

/** Queue command. */
typedef struct QCmd {
    /**  */
  byte out[32];
    /**  */
  unsigned long time;
    /**  */
  unsigned long delay;
    /**  */
  int wait4session;
    /**  */
  iOSlot slot;
} *iQCmd;
typedef struct OCBUSData {

    /**  */
  iONode ini;
    /**  */
  iONode cbusini;
    /**  */
  const char* iid;
    /**  */
  int cid;
    /**  */
  int sodaddr;
    /**  */
  Boolean shortevents;
    /**  */
  Boolean fonfof;
    /**  */
  Boolean power;
    /**  */
  Boolean buson;
    /**  */
  Boolean cts;
    /**  */
  Boolean dummyio;
    /**  */
  int ctsretry;
    /**  */
  iOThread reader;
    /**  */
  iOThread writer;
    /**  */
  iOThread keep;
    /**  */
  iOThread timedqueue;
    /**  */
  int swtime;
    /**  */
  int purgetime;
    /**  */
  const char* device;
    /**  */
  serial_bps bps;
    /**  */
  iOSerial serial;
    /**  */
  iOSocket socket;
    /**  */
  iOMutex mux;
    /** key=locoID, value=slot */
  iOMap lcmap;
    /**  */
  iOMutex lcmux;
    /**  */
  Boolean run;
    /**  */
  Boolean connOK;
    /**  */
  Boolean initOK;
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
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /** Current node number in setup mode. */
  int nnsetup;
    /**  */
  iOThread loader;
    /**  */
  iONode loaderNode;
    /**  */
  iOMutex loaderMux;
    /**  */
  Boolean stress;
    /**  */
  iOThread stressRunner;
    /**  */
  Boolean slotserver;
    /**  */
  Boolean bootmode;
    /**  */
  int cvnr;
    /**  */
  int cab[256];
    /**  */
  int fcnode;
    /**  */
  int fcaddr;
    /**  */
  Boolean fcsync;
    /**  */
  Boolean fastclock;
    /**  */
  iOThread watchdog;
    /**  */
  Boolean connectpending;
    /**  */
  unsigned long lastcmdtick;
    /**  */
  Boolean commandAck;
    /**  */
  Boolean wait4Ack;
    /**  */
  byte lastSendOPC;
    /**  */
  long time;
    /**  */
  iOThread heartbeat;
    /**  */
  Boolean heartbeaton;
    /**  */
  int heartbeatevent;
    /**  */
  Boolean enablecom;

} *iOCBUSData;

static iOCBUSData Data( void* p ) { return (iOCBUSData)((iOCBUS)p)->base.data; }

