/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/tamsmc.h"


static const char* name = "OTamsMC";

typedef struct OTamsMCData {

    /** DigInt Ini */
  iONode ini;
    /** Trace pointer */
  iOTrace trace;
    /** Listener pointer */
  obj listenerObj;
    /** Listener Function pointer */
  digint_listener listenerFun;
    /** Interface ID */
  const char* iid;
    /** Sub library p50x */
  iIDigInt sublib;
    /**  */
  Boolean run;

} *iOTamsMCData;

static iOTamsMCData Data( void* p ) { return (iOTamsMCData)((iOTamsMC)p)->base.data; }

