/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/tt.h"

/* RocRail and system includes: */
#include "rocrail/public/fback.h"
#include "rocrail/public/block.h"

static const char* name = "OTT";

typedef struct OTTData {

    /**  */
  const char* lockedId;
    /**  */
  iONode props;
    /**  */
  iOBlock ttBlock;
    /**  */
  Boolean dir;
    /**  */
  Boolean lcdir;
    /**  */
  Boolean light;
    /**  */
  Boolean triggerS1;
    /**  */
  Boolean triggerS2;
    /**  */
  Boolean triggerSmid1;
    /**  */
  Boolean triggerSmid2;
    /**  */
  Boolean hasMid2;
    /**  */
  int tablepos;
    /**  */
  int gotopos;
    /**  */
  unsigned long delaytick;
    /** pending move operation */
  Boolean pending;
    /** ignore posfb until an other got active */
  int skippos;
    /**  */
  iOMutex muxLock;
    /** Turntable listener object */
  obj listenerObj;
    /** Turntable listener function */
  tt_listener listenerFun;
    /**  */
  const char* locIdGroup;
    /**  */
  iONode selectedTrack;
    /**  */
  Boolean locoOnBridge;
    /**  */
  Boolean f[32];

} *iOTTData;

static iOTTData Data( void* p ) { return (iOTTData)((iOTT)p)->base.data; }

