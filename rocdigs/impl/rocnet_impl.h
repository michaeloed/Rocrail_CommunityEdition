/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/rocnet.h"


static const char* name = "OrocNet";


/**  */
typedef struct rnreq {
    /**  */
  byte* req;
    /**  */
  long timer;
    /**  */
  int retry;
    /**  */
  Boolean ack;
} *iORNreq;

/**  */
typedef struct mouse {
    /**  */
  int nodeid;
    /**  */
  int baseaddr;
    /**  */
  int lcaddr;
} *iOMouse;
typedef struct OrocNetData {

    /** DigInt Ini */
  iONode ini;
    /** RocNet Ini */
  iONode rnini;
    /** Trace pointer */
  iOTrace trace;
    /** Listener pointer */
  obj listenerObj;
    /** Listener Function pointer */
  digint_listener listenerFun;
    /** Interface ID */
  const char* iid;
    /**  */
  Boolean run;
    /**  */
  Boolean connected;
    /**  */
  sublib_connect rnConnect;
    /**  */
  sublib_disconnect rnDisconnect;
    /**  */
  sublib_read rnRead;
    /**  */
  sublib_write rnWrite;
    /**  */
  sublib_available rnAvailable;
    /**  */
  iOSocket readUDP;
    /**  */
  iOSocket writeUDP;
    /**  */
  iOSerial serialCon;
    /**  */
  Boolean cts;
    /**  */
  int ctsretry;
    /**  */
  iOThread reader;
    /**  */
  iOThread writer;
    /**  */
  iOThread watchdog;
    /**  */
  iOThread watchNodes;
    /**  */
  Boolean seven;
    /**  */
  Boolean crc;
    /**  */
  iOList AckList;
    /**  */
  iOMap nodemap;
    /**  */
  int highestID;
    /**  */
  Boolean shutdown;
    /**  */
  int dispatchAddr;
    /**  */
  iOMap mousemap;
    /**  */
  Boolean sack;
    /**  */
  Boolean power;
    /**  */
  Boolean sensor;
    /**  */
  int lcbus;

} *iOrocNetData;

static iOrocNetData Data( void* p ) { return (iOrocNetData)((iOrocNet)p)->base.data; }

