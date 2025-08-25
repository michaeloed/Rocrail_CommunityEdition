/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Sep 20 2018 14:23:23)
  * Module: RocLcDr
  * XML: $Source: /cvsroot/rojav/roclcdr/roclcdr.xml,v $
  * XML: $Revision: 1.6 $
  * Date: Thu Sep 20 14:23:25 2018
  */

#ifndef __object_LcDriver_H
#define __object_LcDriver_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/trace.h"

/* RocLcDr and system includes: */
#include "rocrail/public/loc.h"
#include "rocrail/public/model.h"
#include "rocrail/public/route.h"
#include "rocint/public/lcdriverint.h"
#include "rocint/public/blockbase.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef enum {LC_IDLE=0,LC_FINDDEST,LC_INITDEST,LC_CHECKROUTE,LC_PRE2GO,LC_GO,LC_EXITBLOCK,LC_OUTBLOCK,
              LC_ENTERBLOCK,LC_RE_ENTERBLOCK,LC_PRE2INBLOCK,LC_INBLOCK,LC_PRE_WAITBLOCK,LC_WAITBLOCK,LC_TIMER,LC_WAIT4EVENT,
              LC_PAUSE,LC_MANAGED,LC_FREE} lc_state;
typedef enum {LC_DIR_FORWARDS=0,LC_DIR_BACKWARDS} lc_direction;



typedef struct OLcDriver {
  /***** Base *****/
  struct OBase  base;

  /***** Interface: LcDriverInt *****/
  /**  */
  void (*brake)( iILcDriverInt inst );
  /**  */
  void (*curblock)( iILcDriverInt inst ,const char* blockid );
  /**  */
  void (*drive)( iILcDriverInt inst ,obj emitter ,int event );
  /**  */
  const char* (*getCurblock)( iILcDriverInt inst );
  /**  */
  const char* (*getCurroute)( iILcDriverInt inst );
  /**  */
  const char* (*getGotoblock)( iILcDriverInt inst );
  /**  */
  int (*getScheduleIdx)( iILcDriverInt inst );
  /**  */
  const char* (*getschedule)( iILcDriverInt inst );
  /**  */
  const char* (*gettour)( iILcDriverInt inst );
  /**  */
  void (*go)( iILcDriverInt inst ,Boolean gomanual );
  /**  */
  void (*goNet)( iILcDriverInt inst ,Boolean gomanual ,const char* curblock ,const char* nextblock ,const char* nextroute );
  /**  */
  void (*gogo)( iILcDriverInt inst );
  /**  */
  void (*gotoblock)( iILcDriverInt inst ,const char* blockid );
  /**  */
  void (*info)( iILcDriverInt inst ,iONode info );
  /**  */
  Boolean (*isRun)( iILcDriverInt inst );
  /**  */
  void (*reset)( iILcDriverInt inst ,Boolean saveCurBlock );
  /**  */
  Boolean (*stepvirtual)( iILcDriverInt inst );
  /**  */
  void (*stop)( iILcDriverInt inst );
  /**  */
  void (*stopNet)( iILcDriverInt inst );
  /**  */
  void (*useschedule)( iILcDriverInt inst ,const char* scheduleid );
  /**  */
  void (*usetour)( iILcDriverInt inst ,const char* tourid );
  /** vmajor*1000 + vminor*100 + patch */
  int (*version)( obj inst );

  /***** Object: LcDriver *****/
  /**  */
  struct OLcDriver* (*inst)( const iOLoc loc ,const iOModel model ,const iOTrace trace ,iONode ctrl );
} *iOLcDriver;

extern struct OLcDriver LcDriverOp;

#ifdef __cplusplus
  }
#endif


#endif
