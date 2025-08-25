/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/r2rnet.h"


static const char* name = "OR2Rnet";

typedef struct OR2RnetData {

    /**  */
  iONode props;
    /**  */
  iONode netroutes;
    /**  */
  iOList routelist;
    /**  */
  iOSocket readUDP;
    /**  */
  iOSocket writeUDP;
    /**  */
  iOThread reader;
    /**  */
  iOThread writer;
    /**  */
  Boolean run;
    /**  */
  Boolean gotnetroutes;
    /**  */
  Boolean netroutesprovider;
    /**  */
  iOMutex reqMux;
    /**  */
  iOEvent rspEvt;
    /**  */
  iONode openreq;
    /**  */
  iONode response;

} *iOR2RnetData;

static iOR2RnetData Data( void* p ) { return (iOR2RnetData)((iOR2Rnet)p)->base.data; }

