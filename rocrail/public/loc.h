/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Loc_H
#define __object_Loc_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/thread.h"
#include "rocs/public/map.h"
#include "rocs/public/mutex.h"

/* RocRail and system includes: */
#include "rocrail/public/htmlint.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OLoc {
  /***** Base *****/
  struct OBase  base;

  /***** Interface: HtmlInt *****/
  /**  */
  char* (*getForm)( void* object );
  /**  */
  char* (*postForm)( void* object ,const char* data );
  /**  */
  const char* (*tableHdr)( void );
  /**  */
  char* (*toHtml)( void* object );

  /***** Object: Loc *****/
  /**  */
  void (*adjustAccel)( struct OLoc* inst ,int accel ,int weight );
  /**  */
  void (*brake)( struct OLoc* inst );
  /**  */
  Boolean (*cmd)( struct OLoc* inst ,iONode cmd );
  /** equal=0, lower=-1, higher=1 */
  int (*compareVhint)( struct OLoc* inst ,const char* V_hint );
  /**  */
  void (*depart)( struct OLoc* inst );
  /**  */
  void (*dispatch)( struct OLoc* inst );
  /**  */
  void (*event)( struct OLoc* inst ,obj emiter ,int event ,int wait ,Boolean forcewait ,const char* id );
  /**  */
  void (*fifoTop)( struct OLoc* inst );
  /**  */
  int (*getAddress)( struct OLoc* inst );
  /**  */
  Boolean (*getBlockEnterSide)( struct OLoc* inst );
  /**  */
  int (*getCV)( struct OLoc* inst ,int nr );
  /**  */
  int (*getCarCount)( struct OLoc* inst );
  /**  */
  const char* (*getCargo)( struct OLoc* inst );
  /**  */
  const char* (*getClass)( struct OLoc* inst );
  /**  */
  const char* (*getCurBlock)( struct OLoc* inst );
  /**  */
  const char* (*getDestination)( struct OLoc* inst );
  /**  */
  Boolean (*getDir)( struct OLoc* inst );
  /**  */
  const char* (*getEngine)( struct OLoc* inst );
  /**  */
  int (*getFnNrByDesc)( struct OLoc* inst ,const char* desc );
  /**  */
  iONode (*getFunctionStatus)( struct OLoc* inst ,iONode funcmd );
  /**  */
  const char* (*getId)( struct OLoc* inst );
  /**  */
  const char* (*getIdent)( struct OLoc* inst );
  /**  */
  int (*getLen)( struct OLoc* inst );
  /**  */
  const char* (*getNextGotoBlock)( struct OLoc* inst ,const char* prevblockid );
  /**  */
  Boolean (*getPlacing)( struct OLoc* inst );
  /**  */
  const char* (*getPrevBlock)( struct OLoc* inst );
  /**  */
  const char* (*getSchedule)( struct OLoc* inst ,int* index );
  /**  */
  int (*getSecAddress)( struct OLoc* inst );
  /**  */
  const char* (*getTour)( struct OLoc* inst );
  /**  */
  const char* (*getTrain)( struct OLoc* inst );
  /**  */
  int (*getV)( struct OLoc* inst );
  /**  */
  const char* (*getV_hint)( struct OLoc* inst );
  /**  */
  Boolean (*go)( struct OLoc* inst );
  /**  */
  void (*goNet)( struct OLoc* inst ,const char* curblock ,const char* nextblock ,const char* nextroute );
  /**  */
  Boolean (*gomanual)( struct OLoc* inst );
  /**  */
  void (*gotoBlock)( struct OLoc* inst ,const char* blockid );
  /**  */
  Boolean (*govirtual)( struct OLoc* inst );
  /**  */
  Boolean (*hasClass)( struct OLoc* inst ,const char* class );
  /**  */
  void (*informBlock)( struct OLoc* inst ,const char* destblockid ,const char* curblockid );
  /**  */
  struct OLoc* (*inst)( iONode ini );
  /**  */
  Boolean (*isAutomode)( struct OLoc* inst );
  /**  */
  Boolean (*isCheck2In)( struct OLoc* inst );
  /**  */
  Boolean (*isCommuter)( struct OLoc* inst );
  /**  */
  Boolean (*isGoManual)( struct OLoc* inst );
  /**  */
  Boolean (*isManually)( struct OLoc* inst );
  /**  */
  Boolean (*isReduceSpeedAtEnter)( struct OLoc* inst );
  /**  */
  Boolean (*isResumeAutomode)( struct OLoc* inst );
  /**  */
  Boolean (*isShortin)( struct OLoc* inst );
  /**  */
  Boolean (*isUseManualRoutes)( struct OLoc* inst );
  /**  */
  Boolean (*matchIdent)( struct OLoc* inst ,const char* ident1 ,const char* ident2 ,const char* ident3 ,const char* ident4 );
  /**  */
  void (*modify)( struct OLoc* inst ,iONode cmd );
  /**  */
  char* (*normalizeID)( const char* id );
  /**  */
  void (*reset)( struct OLoc* inst ,Boolean saveCurBlock );
  /**  */
  void (*resetBBT)( struct OLoc* inst );
  /**  */
  void (*resetPrevBlock)( struct OLoc* inst );
  /**  */
  int (*saveSpeed)( struct OLoc* inst ,Boolean reset );
  /**  */
  void (*setBlockEnterSide)( struct OLoc* inst ,Boolean enterside ,const char* blockId );
  /**  */
  void (*setCV)( struct OLoc* inst ,int nr ,int value );
  /**  */
  void (*setCarCount)( struct OLoc* inst ,int carcount );
  /**  */
  void (*setClass)( struct OLoc* inst ,const char* class );
  /**  */
  void (*setCurBlock)( struct OLoc* inst ,const char* blockid );
  /**  */
  void (*setMaxKmh)( struct OLoc* inst ,int maxkmh );
  /**  */
  void (*setMode)( struct OLoc* inst ,const char* mode ,const char* reason );
  /**  */
  void (*stop)( struct OLoc* inst ,Boolean resume );
  /**  */
  void (*stopNet)( struct OLoc* inst );
  /**  */
  void (*swapBlockEnterSide)( struct OLoc* inst ,const char* blockId );
  /**  */
  void (*swapPlacing)( struct OLoc* inst ,iONode cmd ,Boolean consist ,Boolean direct );
  /**  */
  Boolean (*trySecondNextBlock)( struct OLoc* inst );
  /**  */
  void (*useSchedule)( struct OLoc* inst ,const char* scheduleid );
  /**  */
  void (*useTour)( struct OLoc* inst ,const char* tourid );
} *iOLoc;

extern struct OLoc LocOp;

#ifdef __cplusplus
  }
#endif


#endif
