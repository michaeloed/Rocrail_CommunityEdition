/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#include "rocdigs/public/dmxartnet.h"


static const char* name = "ODMXArtNet";

typedef struct ODMXArtNetData {

    /**  */
  iONode ini;
    /**  */
  iONode dmxini;
    /**  */
  const char* iid;
    /**  */
  iOSocket socket;
    /**  */
  Boolean run;
    /**  */
  iOThread reader;
    /**  */
  iOThread writer;
    /**  */
  iOMutex mux;
    /**  */
  Boolean mapwhite;
    /**  */
  int framerate;
    /**  */
  Boolean refresh;
    /**  */
  byte dmxchannel[513];
    /**  */
  iOThread transactor;
    /**  */
  obj listenerObj;
    /**  */
  digint_listener listenerFun;

} *iODMXArtNetData;

static iODMXArtNetData Data( void* p ) { return (iODMXArtNetData)((iODMXArtNet)p)->base.data; }

