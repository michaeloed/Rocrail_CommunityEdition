/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/opendcc.h"


static const char* name = "OOpenDCC";

typedef struct OOpenDCCData {

    /** DigInt Ini */
  iONode ini;
    /** OpenDCC Ini */
  iONode opendccini;
    /** Trace pointer */
  iOTrace trace;
    /** Listener pointer */
  obj listenerObj;
    /** Listener Function pointer */
  digint_listener listenerFun;
    /** Interface ID */
  const char* iid;
    /** Sub library, p50x or lenz */
  iIDigInt sublib;
    /** Name of the sub library */
  const char* sublibname;
    /**  */
  iOThread swdelay;
    /**  */
  Boolean run;

} *iOOpenDCCData;

static iOOpenDCCData Data( void* p ) { return (iOOpenDCCData)((iOOpenDCC)p)->base.data; }

