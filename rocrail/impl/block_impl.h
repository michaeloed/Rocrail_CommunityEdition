/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/block.h"


static const char* name = "OBlock";

typedef struct OBlockData {

    /**  */
  const char* id;
    /**  */
  const char* locId;
    /**  */
  const char* locIdGroup;
    /**  */
  Boolean crossing;
    /**  */
  Boolean reverse;
    /**  */
  const char* group;
    /**  */
  const char* fromBlockId;
    /**  */
  const char* byRouteId;
    /**  */
  int prevLocIdCnt;
    /**  */
  const char* prevLocId;
    /**  */
  obj listenerObj;
    /**  */
  block_listener listenerFun;
    /**  */
  Boolean closereq;
    /**  */
  int minbklc;
    /**  */
  iIBlockBase linkto;
    /** Block properties */
  iONode props;
    /**  */
  iOMap fbEvents;
    /** event timer */
  int timer;
    /** event timer reverse direction */
  int timer2;
    /** in event delay timer */
  int indelay;
    /**  */
  iOMutex muxLock;
    /**  */
  int mvMillis;
    /**  */
  long mvTime;
    /**  */
  float mvspeed;
    /**  */
  iIBlockBase manager;
    /**  */
  long occtime;
    /**  */
  Boolean ghost;
    /**  */
  Boolean acceptident;
    /**  */
  int wheelcount;
    /**  */
  const char* wheelcounterId;
    /**  */
  Boolean forceblocktimer;
    /**  */
  Boolean pendingFree;
    /**  */
  Boolean tempwait;
    /**  */
  iOMutex muxFiFO;
    /**  */
  iOList fifoList;
    /**  */
  Boolean arrivalPending;
    /**  */
  Boolean inPending;
    /**  */
  Boolean fifo0departing;
    /**  */
  Boolean forcelock;

} *iOBlockData;

static iOBlockData Data( void* p ) { return (iOBlockData)((iOBlock)p)->base.data; }

