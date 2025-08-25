/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/xnmm.h"


static const char* name = "OXNMM";

typedef struct OXNMMData {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  Boolean run;
    /**  */
  const char* device;
    /**  */
  iOSerial serial;
    /**  */
  Boolean commOK;
    /**  */
  iOMutex mux;
    /**  */
  iOThread reader;
    /**  */
  iOThread writer;
    /**  */
  Boolean useHeader;

} *iOXNMMData;

static iOXNMMData Data( void* p ) { return (iOXNMMData)((iOXNMM)p)->base.data; }

