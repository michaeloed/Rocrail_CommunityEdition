/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/model.h"

/* RocRail and system includes: */
#include "rocrail/public/mvtrack.h"
#include "rocrail/public/modplan.h"

static const char* name = "OModel";

typedef struct OModelData {

    /**  */
  model_listener callback;
    /**  */
  obj cbCargo;
    /**  */
  Boolean healthy;
    /**  */
  Boolean autoMode;
    /**  */
  const char* fileName;
    /**  */
  const char* locoFileName;
    /**  */
  const char* title;
    /**  */
  iOFile planFile;
    /**  */
  iODoc planDoc;
    /**  */
  iONode model;
    /**  */
  iOMap locMap;
    /**  */
  iOList locList;
    /**  */
  iOMap masterLocMap;
    /**  */
  iOMap carMap;
    /**  */
  iOMap operatorMap;
    /**  */
  iOMap switchMap;
    /**  */
  iOList switchList;
    /**  */
  iOMap signalMap;
    /**  */
  iOMap outputMap;
    /**  */
  iOMap feedbackMap;
    /**  */
  iOMap blockMap;
    /**  */
  iOMap blockGroupMap;
    /**  */
  iOMap routeMap;
    /**  */
  int routePicker;
    /**  */
  Boolean routeCheckDir[10];
    /**  */
  iOList routeList;
    /**  */
  iOMap trackMap;
    /**  */
  iOMap textMap;
    /**  */
  iOMap ttMap;
    /**  */
  iOMap seltabMap;
    /**  */
  iOMap stageMap;
    /**  */
  iOMap fbAddrMap;
    /**  */
  iOMap swAddrMap;
    /**  */
  iOMap coAddrMap;
    /**  */
  iOMap locationMap;
    /**  */
  iOMap scheduleMap;
    /**  */
  iOMap tourMap;
    /**  */
  iOMap weatherMap;
    /**  */
  iOMap actionMap;
    /**  */
  iOMap waybillMap;
    /**  */
  iOMutex muxFindDest;
    /** array of active feedback module addresses used to inform the digint */
  byte fbAddresses[32][256];
    /**  */
  iOMap levelItemsMap;
    /**  */
  iOMap occMap;
    /**  */
  iOMutex occMux;
    /**  */
  iOMVTrack mvtrack;
    /**  */
  Boolean enableswfb;
    /**  */
  iOModPlan moduleplan;
    /**  */
  iOList sysEventListeners;
    /**  */
  int startallera;
    /**  */
  Boolean pendinginitfield;
    /**  */
  Boolean pendingstartall;
    /**  */
  Boolean pendingstartallvirtual;
    /**  */
  iOMutex muxSysEvent;
    /**  */
  iOThread timedoff;
    /**  */
  iOMutex locationMux;
    /**  */
  Boolean saveonshutdown;

} *iOModelData;

static iOModelData Data( void* p ) { return (iOModelData)((iOModel)p)->base.data; }


/**  */
typedef struct LevelList {
    /**  */
  iOList list;
    /**  */
  int level;
    /**  */
  int cx;
    /**  */
  int cy;
} *iOLevelList;
