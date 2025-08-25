/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/ddx.h"


static const char* name = "ODDX";

typedef struct ODDXData {

    /**  */
  iONode ini;
    /**  */
  iOTrace trace;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  const char* iid;
    /**  */
  int swtime;
    /**  */
  iOSerial serial;
    /**  */
  iOThread cycleThread;
    /**  */
  iOThread s88pollt;
    /**  */
  iOThread swReset;
    /**  */
  const char* boosterport;
    /**  */
  int shortcutchecking;
    /**  */
  int shortcutdelay;
    /**  */
  int inversedsr;
    /**  */
  int dcc;
    /**  */
  int mm;
    /**  */
  int mma;
    /**  */
  int queuecheck;
    /**  */
  int portbase;
    /**  */
  const char* parport;
    /**  */
  int s88port;
    /**  */
  int s88buses;
    /**  */
  int s88b0modcnt;
    /**  */
  int s88b1modcnt;
    /**  */
  int s88b2modcnt;
    /**  */
  int s88b3modcnt;
    /**  */
  int s88refresh;
    /**  */
  int s88clockscale;
    /**  */
  int powerflag;
    /**  */
  int s88flag;
    /**  */
  int communicationflag;
    /**  */
  int ptflag;
    /**  */
  int fastcvget;

} *iODDXData;

static iODDXData Data( void* p ) { return (iODDXData)((iODDX)p)->base.data; }

