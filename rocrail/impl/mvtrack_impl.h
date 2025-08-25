/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/mvtrack.h"


static const char* name = "OMVTrack";

typedef struct OMVTrackData {

    /**  */
  iONode props;
    /**  */
  Boolean s1State;
    /**  */
  Boolean s2State;
    /**  */
  Boolean triggerS1;
    /**  */
  Boolean triggerS2;
    /**  */
  int mvMillis;
    /**  */
  long mvTime;

} *iOMVTrackData;

static iOMVTrackData Data( void* p ) { return (iOMVTrackData)((iOMVTrack)p)->base.data; }

