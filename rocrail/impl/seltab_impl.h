/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#include "rocrail/public/seltab.h"

/* RocRail and system includes: */
#include "rocrail/public/fback.h"

static const char* name = "OSelTab";

typedef struct OSelTabData {

    /**  */
  const char* lockedId;
    /**  */
  Boolean lockedDir;
    /**  */
  iOList lockedRouteList;
    /**  */
  const char* blockId;
    /**  */
  iONode props;
    /**  */
  int tablepos;
    /**  */
  int gotopos;
    /** pending move operation */
  Boolean pending;
    /**  */
  iOMutex muxLock;
    /**  */
  int reportedPos;
    /**  */
  iOMap fbEvents;
    /** position sensor state */
  Boolean psenState;
    /**  */
  Boolean closereq;
    /**  */
  Boolean reverse;
    /**  */
  const char* fromBlockId;
    /**  */
  const char* byRouteId;
    /**  */
  long unlockTick;

} *iOSelTabData;

static iOSelTabData Data( void* p ) { return (iOSelTabData)((iOSelTab)p)->base.data; }

