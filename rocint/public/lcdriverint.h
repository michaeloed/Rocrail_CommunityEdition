/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocInt
  * XML: $Source: /cvsroot/rojav/rocint/rocint.xml,v $
  * XML: $Revision: 1.4 $
  * Date: Fri Aug  3 14:03:34 2018
  */

#ifndef __object_LcDriverInt_H
#define __object_LcDriverInt_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct ILcDriverInt {
  /***** Base *****/
  struct OBase  base;

  /***** Object: LcDriverInt *****/
  /**  */
  void (*brake)( struct ILcDriverInt* inst );
  /**  */
  void (*curblock)( struct ILcDriverInt* inst ,const char* blockid );
  /**  */
  void (*drive)( struct ILcDriverInt* inst ,obj emitter ,int event );
  /**  */
  const char* (*getCurblock)( struct ILcDriverInt* inst );
  /**  */
  const char* (*getCurroute)( struct ILcDriverInt* inst );
  /**  */
  const char* (*getGotoblock)( struct ILcDriverInt* inst );
  /**  */
  int (*getScheduleIdx)( struct ILcDriverInt* inst );
  /**  */
  const char* (*getschedule)( struct ILcDriverInt* inst );
  /**  */
  const char* (*gettour)( struct ILcDriverInt* inst );
  /**  */
  void (*go)( struct ILcDriverInt* inst ,Boolean gomanual );
  /**  */
  void (*goNet)( struct ILcDriverInt* inst ,Boolean gomanual ,const char* curblock ,const char* nextblock ,const char* nextroute );
  /**  */
  void (*gogo)( struct ILcDriverInt* inst );
  /**  */
  void (*gotoblock)( struct ILcDriverInt* inst ,const char* blockid );
  /**  */
  void (*info)( struct ILcDriverInt* inst ,iONode info );
  /**  */
  Boolean (*isRun)( struct ILcDriverInt* inst );
  /**  */
  void (*reset)( struct ILcDriverInt* inst ,Boolean saveCurBlock );
  /**  */
  Boolean (*stepvirtual)( struct ILcDriverInt* inst );
  /**  */
  void (*stop)( struct ILcDriverInt* inst );
  /**  */
  void (*stopNet)( struct ILcDriverInt* inst );
  /**  */
  void (*useschedule)( struct ILcDriverInt* inst ,const char* scheduleid );
  /**  */
  void (*usetour)( struct ILcDriverInt* inst ,const char* tourid );
  /** vmajor*1000 + vminor*100 + patch */
  int (*version)( obj inst );
} *iILcDriverInt;


#ifdef __cplusplus
  }
#endif


#endif
