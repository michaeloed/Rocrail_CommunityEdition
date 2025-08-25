/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/control.h"


static const char* name = "OControl";

typedef struct OControlData {

    /** Interface */
  iIDigInt pDi;
    /** Interface Id */
  const char* iid;
    /**  */
  iOMap diMap;
    /**  */
  iOThread clockticker;
    /**  */
  iOThread txshortids;
    /**  */
  int devider;
    /**  */
  long time;
    /**  */
  Boolean timeset;
    /**  */
  Boolean clockrun;
    /**  */
  int temp;
    /**  */
  Boolean txshortidsrun;
    /**  */
  Boolean power;
    /**  */
  Boolean enablecom;
    /**  */
  Boolean programming;
    /**  */
  Boolean trackbus;
    /**  */
  Boolean sensorbus;
    /**  */
  Boolean accessorybus;
    /**  */
  Boolean needkey4loconet;
    /**  */
  iOThread checker;
    /**  */
  iOPowerMan powerman;
    /**  */
  iOR2Rnet r2rnet;
    /**  */
  char* devlist;

} *iOControlData;

static iOControlData Data( void* p ) { return (iOControlData)((iOControl)p)->base.data; }

