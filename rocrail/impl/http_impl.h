/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/http.h"


static const char* name = "OHttp";

typedef struct OHttpData {

    /** Port to service. */
  int port;
    /** Port manager thread. */
  iOThread portmanager;
    /** Port server thread. */
  iOThread portserver;
    /** Server socket. */
  iOSocket srvrsocket;
    /** Port client map. */
  iOMap clientMap;
    /** Port to service. */
  int pport;
    /** Port manager thread. */
  iOThread pportmanager;
    /** Port server thread. */
  iOThread pportserver;
    /** Server socket. */
  iOSocket psrvrsocket;
    /** Port client map. */
  iOMap pclientMap;
    /** Port client map mutex. */
  iOMutex pclientmux;
    /**  */
  Boolean shutdown;
    /**  */
  iONode ini;
    /**  */
  iONode webclient;
    /**  */
  httpcon_callback callback;
    /**  */
  obj callbackObj;
    /**  */
  const char* controlcode;
    /**  */
  const char* slavecode;

} *iOHttpData;

static iOHttpData Data( void* p ) { return (iOHttpData)((iOHttp)p)->base.data; }

