/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/pclient.h"


static const char* name = "OPClient";

typedef struct OPClientData {

    /**  */
  long id;
    /** Client ID */
  char* cid;
    /**  */
  iOThread websocketreader;
    /**  */
  unsigned char firstbyte;
    /**  */
  Boolean websocketavail;
    /**  */
  Boolean websocketerror;
    /**  */
  Boolean websocketrun;
    /**  */
  Boolean websocket;
    /**  */
  Boolean websocketmonitor;
    /** Client socket. */
  iOSocket socket;
    /** Receipt buffer. */
  char* rcptBuffer;
    /** Size of receipt. */
  int rcptSize;
    /** Scan path */
  const char* path;
    /** browser refresh time */
  int refresh;
    /** LocID's */
  iOList locIDs;
    /** webclient ini */
  iONode ini;

} *iOPClientData;

static iOPClientData Data( void* p ) { return (iOPClientData)((iOPClient)p)->base.data; }


/**  */
typedef struct extraItem {
    /**  */
  Boolean skip;
    /**  */
  char html[256];
} *iOExtraItem;
