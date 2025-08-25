/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Location_H
#define __object_Location_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/map.h"
#include "rocs/public/list.h"
#include "rocs/public/mutex.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OLocation {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Location *****/
  /**  */
  Boolean (*cmd)( struct OLocation* inst ,iONode cmd );
  /**  */
  void (*didNotDepart)( struct OLocation* inst ,const char* LocoId );
  /**  */
  Boolean (*hasBlock)( struct OLocation* inst ,const char* BlockId );
  /**  */
  Boolean (*hasFreeBlock)( struct OLocation* inst ,const char* locoId );
  /**  */
  struct OLocation* (*inst)( iONode ini );
  /**  */
  Boolean (*isDepartureAllowed)( struct OLocation* inst ,const char* LocoId );
  /**  */
  void (*locoDidArrive)( struct OLocation* inst ,const char* LocoId );
  /**  */
  void (*locoDidDepart)( struct OLocation* inst ,const char* LocoId );
  /**  */
  void (*modify)( struct OLocation* inst ,iONode mod );
  /**  */
  void (*reset)( struct OLocation* inst );
} *iOLocation;

extern struct OLocation LocationOp;

#ifdef __cplusplus
  }
#endif


#endif
