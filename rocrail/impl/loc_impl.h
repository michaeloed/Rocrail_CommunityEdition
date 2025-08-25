/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/loc.h"

/* RocRail and system includes: */
#include "rocint/public/lcdriverint.h"

static const char* name = "OLoc";

typedef struct OLocData {

    /**  */
  iONode props;
    /**  */
  iOMap cvMap;
    /**  */
  iOThread runner;
    /**  */
  Boolean run;
    /**  */
  Boolean running;
    /**  */
  Boolean go;
    /**  */
  Boolean goNet;
    /**  */
  Boolean brake;
    /**  */
  Boolean check2in;
    /**  */
  const char* curGroup;
    /**  */
  const char* prevBlock;
    /**  */
  const char* curBlock;
    /**  */
  const char* curSensor;
    /**  */
  const char* destBlock;
    /** goto this block if found */
  const char* gotoBlock;
    /**  */
  iILcDriverInt driver;
    /**  */
  int curSpeed;
    /**  */
  int drvSpeed;
    /**  */
  int step;
    /**  */
  int speedstep;
    /**  */
  Boolean fn0;
    /**  */
  Boolean fn1;
    /**  */
  Boolean fn2;
    /**  */
  Boolean fn3;
    /**  */
  Boolean fn4;
    /**  */
  Boolean fn5;
    /**  */
  Boolean fn6;
    /**  */
  Boolean fn7;
    /**  */
  Boolean fn8;
    /**  */
  Boolean fn9;
    /**  */
  Boolean fn10;
    /**  */
  Boolean fn11;
    /**  */
  Boolean fn12;
    /**  */
  Boolean fn13;
    /**  */
  Boolean fn14;
    /**  */
  Boolean fn15;
    /**  */
  Boolean fn16;
    /**  */
  Boolean fn17;
    /**  */
  Boolean fn18;
    /**  */
  Boolean fn19;
    /**  */
  Boolean fn20;
    /**  */
  Boolean fn21;
    /**  */
  Boolean fn22;
    /**  */
  Boolean fn23;
    /**  */
  Boolean fn24;
    /**  */
  Boolean fn25;
    /**  */
  Boolean fn26;
    /**  */
  Boolean fn27;
    /**  */
  Boolean fn28;
    /**  */
  int timedfn;
    /**  */
  int fntimer;
    /**  */
  int fxtimer[32];
    /**  */
  int fnevent;
    /**  */
  char* fneventblock;
    /**  */
  int ignevt;
    /**  */
  Boolean fxrestored;
    /**  */
  Boolean fxrestoredbythread;
    /**  */
  Boolean speedrestoredbythread;
    /**  */
  int fxsleep;
    /**  */
  int fxgroup;
    /**  */
  Boolean fxresetpending;
    /**  */
  Boolean enter;
    /**  */
  const char* enterId;
    /**  */
  int enterTick;
    /**  */
  obj enterEmitter;
    /**  */
  Boolean in;
    /**  */
  const char* inId;
    /**  */
  int inTick;
    /**  */
  obj exitEmitter;
    /**  */
  Boolean exit;
    /**  */
  const char* exitId;
    /**  */
  int exitTick;
    /**  */
  Boolean out;
    /**  */
  const char* outId;
    /**  */
  int outTick;
    /**  */
  Boolean gomanual;
    /**  */
  Boolean manual;
    /**  */
  long runtime;
    /**  */
  Boolean secondnextblock;
    /**  */
  Boolean usemanualroutes;
    /**  */
  int infocheck;
    /**  */
  Boolean released;
    /**  */
  int nrruns;
    /**  */
  char* blocktrip;
    /**  */
  Boolean bbt;
    /**  */
  iOMap bbtMap;
    /**  */
  int bbtCycle;
    /**  */
  int bbtCycleSpeed;
    /**  */
  int bbtCycleNr;
    /**  */
  unsigned long bbtEnter;
    /**  */
  unsigned long bbtIn;
    /**  */
  const char* bbtEnterBlock;
    /**  */
  const char* bbtInBlock;
    /**  */
  const char* bbtPrevBlock;
    /**  */
  const char* bbtRoute;
    /**  */
  int bbtEnterSpeed;
    /**  */
  int bbtSpeed;
    /**  */
  int bbtSpeedInterval;
    /**  */
  int bbtInterval;
    /**  */
  Boolean bbtAtMinSpeed;
    /**  */
  unsigned long bbtAtMin;
    /**  */
  int bbtInTimer;
    /**  */
  int bbtStepCount;
    /**  */
  Boolean bbtExternalStop;
    /**  */
  Boolean bbtGenerateIn;
    /**  */
  int bbtDelay;
    /**  */
  iOMap sbtMap;
    /**  */
  const char* sbtEnterBlock;
    /**  */
  int sbtInterval;
    /**  */
  int sbtDecelerate;
    /**  */
  long lastfncmd;
    /**  */
  Boolean govirtual;
    /**  */
  iOMutex muxEngine;
    /**  */
  iOMutex muxCmd;
    /**  */
  int savedSpeed;
    /**  */
  int v0sleep;
    /**  */
  Boolean v0pending;
    /**  */
  int maxkmh;

} *iOLocData;

static iOLocData Data( void* p ) { return (iOLocData)((iOLoc)p)->base.data; }

