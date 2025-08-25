/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/lrc135.h"


static const char* name = "OLRc135";

typedef struct OLRc135Data {

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
    /**  */
  Boolean run;
    /**  */
  iOSerial serial;
    /**  */
  iOThread reader;
    /**  */
  iOThread writer;

} *iOLRc135Data;

static iOLRc135Data Data( void* p ) { return (iOLRc135Data)((iOLRc135)p)->base.data; }

