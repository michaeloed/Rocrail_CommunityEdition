/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/p50.h"


static const char* name = "OP50";

typedef struct OP50Data {

    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  iOSerial serial;
    /**  */
  iOMutex mux;
    /**  */
  iOThread feedbackReader;
    /**  */
  iOThread swTimeWatcher;
    /**  */
  unsigned long lastSwCmd;
    /**  */
  const char* device;
    /**  */
  serial_bps bps;
    /**  */
  serial_databits bits;
    /**  */
  serial_stopbits stopBits;
    /**  */
  serial_parity parity;
    /**  */
  serial_flow flow;
    /**  */
  int timeout;
    /**  */
  int fbmod;
    /**  */
  int swtime;
    /**  */
  int psleep;
    /**  */
  Boolean dummyio;
    /**  */
  int ctsretry;
    /**  */
  p50state state;
    /**  */
  const char* iid;
    /**  */
  Boolean readfb;
    /**  */
  Boolean run;
    /**  */
  Boolean serialOK;
    /**  */
  Boolean initOK;
    /**  */
  iONode ini;

} *iOP50Data;

static iOP50Data Data( void* p ) { return (iOP50Data)((iOP50)p)->base.data; }

