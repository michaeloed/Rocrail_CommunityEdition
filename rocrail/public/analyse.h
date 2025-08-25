/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Analyse_H
#define __object_Analyse_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/trace.h"
#include "rocs/public/node.h"
#include "rocs/public/map.h"

/* RocRail and system includes: */
#include "rocrail/public/model.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef enum {AN_JOB=0,AN_CLEAN,AN_HEALTH,AN_EXTCHK,AN_EXTCLEAN} an_mode;



typedef struct OAnalyse {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Analyse *****/
  int MINIMAL_MAX_CONNECTOR_DISTANCE;
  /**  */
  int (*analyse)( struct OAnalyse* inst );
  /**  */
  Boolean (*checkExtended)( struct OAnalyse* inst );
  /**  */
  Boolean (*checkPlanHealth)( struct OAnalyse* inst );
  /**  */
  Boolean (*cleanExtended)( struct OAnalyse* inst );
  /**  */
  int (*cleanup)( struct OAnalyse* inst );
  /**  */
  struct OAnalyse* (*inst)( void );
} *iOAnalyse;

extern struct OAnalyse AnalyseOp;

#ifdef __cplusplus
  }
#endif


#endif
