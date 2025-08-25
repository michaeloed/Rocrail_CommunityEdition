/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/hclient.h"


static const char* name = "OHClient";

typedef struct OHClientData {

    /**  */
  long id;
    /** Client ID */
  char* cid;
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

} *iOHClientData;

static iOHClientData Data( void* p ) { return (iOHClientData)((iOHClient)p)->base.data; }

