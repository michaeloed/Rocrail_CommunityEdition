/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/rocomp.h"


static const char* name = "ORocoMP";

typedef struct ORocoMPData {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  Boolean run;
    /**  */
  iOThread transactor;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  iOUSB usb;
    /**  */
  Boolean usbOK;
    /**  */
  int timeout;
    /**  */
  byte sensor[256];
    /**  */
  int systemstate;
    /**  */
  Boolean power;
    /**  */
  int current;
    /**  */
  int temp;
    /**  */
  int state;

} *iORocoMPData;

static iORocoMPData Data( void* p ) { return (iORocoMPData)((iORocoMP)p)->base.data; }

