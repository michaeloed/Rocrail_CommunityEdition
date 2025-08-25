/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/srcpcon.h"


static const char* name = "OSrcpCon";

typedef struct OSrcpConData {

    /**  */
  iONode ini;
    /**  */
  srcpcon_callback callback;
    /**  */
  obj callbackObj;
    /**  */
  iOSocket srvrsocket;
    /**  */
  iOThread manager;
    /**  */
  iOThread stress;
    /**  */
  iOMap infoWriters;
    /**  */
  iOMutex muxMap;
    /**  */
  iOThread broadcaster;
    /**  */
  int port;
    /**  */
  iOSerial serial;
    /**  */
  Boolean serialOK;

} *iOSrcpConData;

static iOSrcpConData Data( void* p ) { return (iOSrcpConData)((iOSrcpCon)p)->base.data; }

