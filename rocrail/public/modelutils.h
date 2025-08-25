/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_ModelUtils_H
#define __object_ModelUtils_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/list.h"
#include "rocs/public/map.h"

/* RocRail and system includes: */
#include "rocrail/public/block.h"
#include "rocrail/public/loc.h"
#include "rocrail/public/car.h"
#include "rocrail/public/operator.h"
#include "rocrail/public/route.h"
#include "rocrail/public/fback.h"
#include "rocrail/public/switch.h"
#include "rocrail/public/track.h"
#include "rocrail/public/signal.h"
#include "rocrail/public/tt.h"
#include "rocrail/public/output.h"
#include "rocrail/public/text.h"
#include "rocrail/public/seltab.h"
#include "rocrail/public/stage.h"
#include "rocrail/public/action.h"
#include "rocrail/public/location.h"
#include "rocint/public/blockbase.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OModelUtils {
  /***** Base *****/
  struct OBase  base;

  /***** Object: ModelUtils *****/
  /**  */
  struct OModelUtils* (*inst)( iONode model );
  /**  */
  Boolean (*renameItemDependencies)( iONode model ,const char* id ,const char* previd ,iONode props );
  /**  */
  void (*setModel)( struct OModelUtils* inst ,iONode model );
} *iOModelUtils;

extern struct OModelUtils ModelUtilsOp;

#ifdef __cplusplus
  }
#endif


#endif
