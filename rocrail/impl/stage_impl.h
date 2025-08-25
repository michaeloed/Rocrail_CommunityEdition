/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/stage.h"


static const char* name = "OStage";

typedef struct OStageData {

    /**  */
  const char* id;
    /**  */
  const char* locId;
    /**  */
  int targetSection;
    /**  */
  int pendingSection;
    /**  */
  Boolean pendingFree;
    /**  */
  Boolean pendingMove;
    /** Stage properties */
  iONode props;
    /**  */
  iOList sectionList;
    /**  */
  iOMap fbMap;
    /**  */
  int sectionCount;
    /**  */
  int freeSections;
    /**  */
  int sectionLength;
    /**  */
  int trainGap;
    /**  */
  iIBlockBase linkto;
    /**  */
  Boolean closereq;
    /**  */
  const char* fromBlockId;
    /**  */
  const char* byRouteId;
    /**  */
  Boolean trig_enter;
    /**  */
  Boolean trig_in;
    /**  */
  Boolean trig_exit;
    /**  */
  Boolean trig_out;
    /**  */
  Boolean trig_enter_mid;
    /**  */
  Boolean trig_exit_mid;
    /** reverse enter */
  Boolean trig_renter_mid;
    /** reverse exit */
  Boolean trig_rexit_mid;
    /**  */
  iOMutex mapMux;
    /**  */
  Boolean wait4enter;
    /**  */
  Boolean early2in;
    /**  */
  iOMutex moveMux;
    /**  */
  iOThread watchdog;
    /**  */
  Boolean run;
    /**  */
  Boolean wdrun;
    /**  */
  Boolean ghost;

} *iOStageData;

static iOStageData Data( void* p ) { return (iOStageData)((iOStage)p)->base.data; }

