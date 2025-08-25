/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/hsi88.h"


static const char* name = "OHSI88";


/** Feedback state for triggering. */
typedef struct FBState {
    /**  */
  unsigned long hightime;
    /**  */
  unsigned long lowtime;
    /**  */
  Boolean state;
} *iOFBState;
typedef struct OHSI88Data {

    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  iOSerial serial;
    /**  */
  iOFile usbh;
    /**  */
  long devh;
    /**  */
  iOMutex mux;
    /**  */
  iOThread feedbackReader;
    /**  */
  iOThread delayedOffHandler;
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
  int ctsretry;
    /**  */
  HSI88state state;
    /**  */
  const char* iid;
    /**  */
  int fbright;
    /**  */
  int fbleft;
    /**  */
  int fbmiddle;
    /**  */
  Boolean run;
    /**  */
  Boolean smooth;
    /**  */
  int triggertime;
    /**  */
  iOFBState fbstate;
    /**  */
  Boolean serialOK;
    /**  */
  Boolean initOK;
    /**  */
  Boolean dummyio;
    /**  */
  Boolean usb;

} *iOHSI88Data;

static iOHSI88Data Data( void* p ) { return (iOHSI88Data)((iOHSI88)p)->base.data; }

