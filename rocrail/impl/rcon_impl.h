/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/rcon.h"


static const char* name = "ORCon";

typedef struct ORConData {

    /**  */
  rcon_callback callback;
    /**  */
  obj cbCargo;
    /**  */
  iOSocket sh;
    /**  */
  iOThread infoReader;
    /**  */
  char* host;
    /**  */
  int port;
    /**  */
  Boolean run;

} *iORConData;

static iORConData Data( void* p ) { return (iORConData)((iORCon)p)->base.data; }

