/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/switch.h"

/* RocRail and system includes: */
#include "rocrail/public/fback.h"

static const char* name = "OSwitch";

typedef struct OSwitchData {

    /**  */
  const char* id;
    /**  */
  const char* lockedId;
    /**  */
  iORoute route;
    /**  */
  int savepostimer;
    /**  */
  iONode props;
    /**  */
  iONode accctrl;
    /**  */
  Boolean isStateInverted;
    /**  */
  sw_state fbstate;
    /**  */
  sw_state fb2state;
    /**  */
  Boolean hasFbSignal;
    /**  */
  iOFBack fbR;
    /**  */
  iOFBack fbG;
    /**  */
  iOFBack fb2R;
    /**  */
  iOFBack fb2G;
    /**  */
  iOFBack fbOcc;
    /**  */
  iOFBack fbOcc2;
    /**  */
  Boolean fbRinv;
    /**  */
  Boolean fbGinv;
    /**  */
  Boolean fb2Rinv;
    /**  */
  Boolean fb2Ginv;
    /** Address key */
  char* addrKey;
    /** Address key */
  char* addrKey2;
    /**  */
  iOMutex muxLock;
    /**  */
  iOMutex muxCmd;
    /**  */
  Boolean activated;
    /**  */
  int fieldState1;
    /**  */
  int fieldState2;
    /**  */
  iOThread accThread;
    /**  */
  Boolean accrun;
    /**  */
  Boolean run;
    /**  */
  Boolean ctc1;
    /**  */
  Boolean ctc2;
    /**  */
  Boolean pendingflip;
    /**  */
  iOList listeners;
    /**  */
  iOThread testThread;
    /**  */
  Boolean testRun;
    /**  */
  Boolean pendingSet;

} *iOSwitchData;

static iOSwitchData Data( void* p ) { return (iOSwitchData)((iOSwitch)p)->base.data; }

