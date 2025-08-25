/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/fback.h"


static const char* name = "OFBack";

typedef struct OFBackData {

    /** Feedback properties */
  iONode props;
    /** Current state */
  Boolean state;
    /** Address key */
  char* addrKey;
    /** Address key */
  char* cutoutAddrKey;
    /** Feedback listener object */
  obj listenerObj;
    /** Feedback listener function */
  fback_listener listenerFun;
    /** Feedback listeners */
  iOList listeners;
    /** occupied counter */
  int counter;
    /**  */
  int carcount;
    /**  */
  int countedcars;
    /**  */
  int wheelcount;
    /**  */
  int timer;
    /**  */
  int timedoff;
    /**  */
  Boolean shortcut;

} *iOFBackData;

static iOFBackData Data( void* p ) { return (iOFBackData)((iOFBack)p)->base.data; }

