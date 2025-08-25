/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/got.h"


static const char* name = "OGOT";


/** SID */
typedef struct sender {
    /**  */
  int sid;
    /**  */
  int x;
    /**  */
  int y;
    /**  */
  int z;
} *iOSender;
typedef struct OGOTData {

    /**  */
  iONode ini;
    /**  */
  const char* iid;
    /**  */
  const char* host;
    /**  */
  int port;
    /**  */
  iOSocket socket;
    /**  */
  iOSerial serial;
    /**  */
  Boolean run;
    /**  */
  iOThread reader;
    /**  */
  iOThread writer;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;
    /**  */
  Boolean connOK;
    /**  */
  iOMap sidMap;

} *iOGOTData;

static iOGOTData Data( void* p ) { return (iOGOTData)((iOGOT)p)->base.data; }

