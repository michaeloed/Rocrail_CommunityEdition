/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Sep 20 2018 14:23:23)
  * Module: RocLcDr
  * XML: $Source: /cvsroot/rojav/roclcdr/roclcdr.xml,v $
  * XML: $Revision: 1.6 $
  * Date: Thu Sep 20 14:23:25 2018
  */

#include "roclcdr/public/lcdriver.h"


static const char* name = "OLcDriver";

typedef struct OLcDriverData {

    /** Loc object instance */
  iOLoc loc;
    /** Model object instance */
  iOModel model;
    /**  */
  lc_state state;
    /**  */
  lc_state prevState;
    /**  */
  int ignevt;
    /**  */
  int timer;
    /**  */
  Boolean run;
    /**  */
  Boolean reqstop;
    /**  */
  Boolean gomanual;
    /** Fase between running and idle */
  Boolean pending;
    /**  */
  Boolean stop;
    /**  */
  Boolean brake;
    /**  */
  lc_direction direction;
    /**  */
  iIBlockBase prevBlock;
    /**  */
  Boolean useCurBlock4Signals;
    /**  */
  iIBlockBase curBlock4Signals;
    /**  */
  iIBlockBase curBlock;
    /**  */
  iIBlockBase next1Block;
    /**  */
  iIBlockBase next2Block;
    /**  */
  iIBlockBase next3Block;
    /**  */
  iORoute next1Route;
    /**  */
  Boolean next1RouteFromTo;
    /**  */
  iORoute next2Route;
    /**  */
  Boolean next2RouteFromTo;
    /**  */
  iORoute next3Route;
    /**  */
  Boolean next3RouteFromTo;
    /**  */
  int pause;
    /** Previous enter block event in ticks. */
  int preventer;
    /** Previous in block event in ticks. */
  int prevpre2in;
    /** Previous in block event in ticks. */
  int previn;
    /** Previous exit block event in ticks. */
  int prevexit;
    /** Previous out block event in ticks. */
  int prevout;
    /**  */
  const char* preventerbkid;
    /**  */
  const char* prevpre2inbkid;
    /**  */
  const char* previnbkid;
    /**  */
  const char* prevexitbkid;
    /**  */
  const char* prevoutbkid;
    /**  */
  const char* gotoBlock;
    /**  */
  Boolean scheduleended;
    /**  */
  const char* schedule;
    /**  */
  int scheduleIdx;
    /**  */
  int scheduleCycle;
    /**  */
  int prewaitScheduleIdx;
    /**  */
  long scheduletime;
    /**  */
  const char* tour;
    /**  */
  int tourIdx;
    /**  */
  char V_hint[32];
    /**  */
  const char* blockgroup;
    /**  */
  Boolean slowdown4route;
    /**  */
  Boolean secondnextblock;
    /**  */
  Boolean warningnodestfound;
    /**  */
  int eventTimeout;
    /**  */
  int eventTimeoutTime;
    /**  */
  int signalReset;
    /**  */
  int signalResetTime;
    /**  */
  Boolean greenaspect;
    /**  */
  int semaphoreWait;
    /**  */
  int signalWait;
    /**  */
  int indelay;
    /**  */
  Boolean stopnonecommuter;
    /**  */
  Boolean opponly;
    /**  */
  int reentertimer;
    /**  */
  Boolean pendingSwap;
    /**  */
  int entryActionsChecked;
    /**  */
  Boolean stopatin4gomanual;
    /**  */
  Boolean forceDeparture;
    /**  */
  Boolean didFree;
    /**  */
  Boolean didReduceSpeedAtEnter;

} *iOLcDriverData;

static iOLcDriverData Data( void* p ) { return (iOLcDriverData)((iOLcDriver)p)->base.data; }

