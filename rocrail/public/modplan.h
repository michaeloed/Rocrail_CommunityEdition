/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_ModPlan_H
#define __object_ModPlan_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/map.h"
#include "rocs/public/list.h"
#include "rocs/public/node.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OModPlan {
  /***** Base *****/
  struct OBase  base;

  /***** Object: ModPlan *****/
  /**  */
  void (*addModule)( struct OModPlan* inst ,iONode module );
  /**  */
  iOList (*getBlocks4Point)( struct OModPlan* inst ,const char* modid ,const char* point );
  /**  */
  iONode (*getEvent4Block)( struct OModPlan* inst ,const char* modid ,iONode block ,const char* comingfrom ,const char* eventid );
  /**  */
  iONode (*getModPlan)( struct OModPlan* inst );
  /**  */
  iONode (*getModule)( struct OModPlan* inst ,const char* modid );
  /**  */
  iOList (*getModuleRouteIDs)( struct OModPlan* inst ,const char* routeids );
  /**  */
  const char* (*getResolvedRouteID)( struct OModPlan* inst ,const char* routeid );
  /**  */
  struct OModPlan* (*inst)( iONode ini );
  /**  */
  void (*mergeList)( const char* listname ,iONode model ,iONode module ,int level ,int r ,int cx ,int cy ,Boolean broadcast );
  /**  */
  void (*mergeLocs)( iONode model ,const char* fname );
  /**  */
  Boolean (*modify)( struct OModPlan* inst ,iONode item );
  /**  */
  iONode (*parse)( struct OModPlan* inst );
  /**  */
  iONode (*parsePlan)( const char* filename );
  /**  */
  void (*resolveRoutes)( struct OModPlan* inst ,iONode model ,iONode module ,iONode moduleRoot ,int level );
  /**  */
  void (*save)( struct OModPlan* inst ,const char* filename );
  /**  */
  void (*saveLocs)( iONode model ,const char* fname );
  /**  */
  void (*setModPlan)( struct OModPlan* inst ,iONode modplan );
  /**  */
  iONode (*setModule)( struct OModPlan* inst ,iONode module );
} *iOModPlan;

extern struct OModPlan ModPlanOp;

#ifdef __cplusplus
  }
#endif


#endif
