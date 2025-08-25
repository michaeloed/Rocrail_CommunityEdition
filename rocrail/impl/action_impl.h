/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/action.h"


static const char* name = "OAction";

typedef struct OActionData {

    /**  */
  iONode action;
    /**  */
  iOThread timerthread;
    /**  */
  iONode actionctrl;
    /**  */
  int timer;
    /**  */
  int randomsecs;
    /**  */
  int ticker;
    /**  */
  int lastacthour;
    /**  */
  int lastactmin;
    /**  */
  int lastactsec;
    /**  */
  Boolean enabled;

} *iOActionData;

static iOActionData Data( void* p ) { return (iOActionData)((iOAction)p)->base.data; }

