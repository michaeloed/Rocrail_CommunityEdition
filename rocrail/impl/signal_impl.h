/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/signal.h"


static const char* name = "OSignal";

typedef struct OSignalData {

    /**  */
  iONode props;
    /**  */
  Boolean isStateInverted;

} *iOSignalData;

static iOSignalData Data( void* p ) { return (iOSignalData)((iOSignal)p)->base.data; }

