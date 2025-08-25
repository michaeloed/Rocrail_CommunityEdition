/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_TT_H
#define __object_TT_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/mutex.h"

/* RocRail and system includes: */
#include "rocrail/public/loc.h"
#include "rocint/public/blockbase.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef void (*tt_listener)(obj,const char*,const char*);



typedef struct OTT {
  /***** Base *****/
  struct OBase  base;

  /***** Interface: BlockBase *****/
  /**  */
  void (*acceptIdent)( iIBlockBase inst ,Boolean accept );
  /**  */
  Boolean (*allowBBT)( iIBlockBase inst );
  /**  */
  Boolean (*cmd)( iIBlockBase inst ,iONode cmd );
  /**  */
  void (*depart)( iIBlockBase inst );
  /**  */
  void (*didNotDepart)( iIBlockBase inst ,const char* LocoId );
  /**  */
  void (*enterBlock)( iIBlockBase inst ,const char* locid );
  /**  */
  Boolean (*event)( iIBlockBase inst ,Boolean puls ,const char* id ,const char* ident1 ,const char* ident2 ,const char* ident3 ,const char* ident4 ,int val ,int wheelcount ,iONode evtDescr ,Boolean dir );
  /**  */
  void (*exitBlock)( iIBlockBase inst ,const char* locid ,Boolean unexpected );
  /**  */
  int (*getDepartDelay)( iIBlockBase inst );
  /**  */
  const char* (*getFromBlockId)( iIBlockBase inst );
  /**  */
  const char* (*getInLoc)( iIBlockBase inst );
  /**  */
  const char* (*getLoc)( iIBlockBase inst );
  /**  */
  iIBlockBase (*getManager)( iIBlockBase inst );
  /**  */
  int (*getMaxKmh)( iIBlockBase inst );
  /**  */
  int (*getOccTime)( iIBlockBase inst );
  /**  */
  int (*getRandomRate)( iIBlockBase inst ,const char* lcid );
  /**  */
  const char* (*getState)( iIBlockBase inst );
  /**  */
  int (*getTDaddress)( iIBlockBase inst );
  /**  */
  const char* (*getTDiid)( iIBlockBase inst );
  /**  */
  int (*getTDport)( iIBlockBase inst );
  /**  */
  const char* (*getVelocity)( iIBlockBase inst ,int* percent ,Boolean onexit ,Boolean reverse ,Boolean onstop );
  /**  */
  int (*getVisitCnt)( iIBlockBase inst ,const char* locid );
  /**  */
  int (*getWait)( iIBlockBase inst ,iOLoc loc ,Boolean reverse ,int* oppwait );
  /**  */
  int (*getWheelCount)( iIBlockBase inst );
  /**  */
  float (*getmvspeed)( iIBlockBase inst );
  /**  */
  Boolean (*green)( iIBlockBase inst ,Boolean distant ,Boolean reverse );
  /**  */
  Boolean (*hasClass)( iIBlockBase inst ,const char* class );
  /**  */
  Boolean (*hasEnter2Route)( iIBlockBase inst ,const char* fromBlockId );
  /**  */
  Boolean (*hasExtStop)( iIBlockBase inst ,const char* locoid );
  /**  */
  obj (*hasManualSignal)( iIBlockBase inst ,Boolean distant ,Boolean reverse );
  /**  */
  Boolean (*hasPre2In)( iIBlockBase inst ,const char* fromBlockId );
  /**  */
  void (*inBlock)( iIBlockBase inst ,const char* locid );
  /**  */
  void (*init)( iIBlockBase inst );
  /**  */
  Boolean (*isDepartureAllowed)( iIBlockBase inst ,const char* LocoId ,Boolean force );
  /**  */
  Boolean (*isFree)( iIBlockBase inst ,const char* locid );
  /**  */
  Boolean (*isFreeBlockOnEnter)( iIBlockBase inst );
  /**  */
  Boolean (*isLinked)( iIBlockBase inst );
  /**  */
  Boolean (*isReady)( iIBlockBase inst );
  /**  */
  Boolean (*isState)( iIBlockBase inst ,const char* state );
  /**  */
  int (*isSuited)( iIBlockBase inst ,iOLoc loc ,int* restlen ,Boolean checkprev );
  /**  */
  Boolean (*isTD)( iIBlockBase inst );
  /**  */
  Boolean (*isTTBlock)( iIBlockBase inst );
  /**  */
  Boolean (*isTerminalStation)( iIBlockBase inst );
  /**  */
  Boolean (*link)( iIBlockBase inst ,iIBlockBase linkto );
  /**  */
  Boolean (*lock)( iIBlockBase inst ,const char* locid ,const char* blockid ,const char* routeid ,Boolean crossing ,Boolean reset ,Boolean reverse ,int indelay ,const char* masterId ,Boolean force );
  /**  */
  Boolean (*lockForGroup)( iIBlockBase inst ,const char* locid );
  /**  */
  Boolean (*red)( iIBlockBase inst ,Boolean distant ,Boolean reverse );
  /**  */
  void (*reset)( iIBlockBase inst ,Boolean saveCurBlock );
  /**  */
  void (*resetTD)( iIBlockBase inst );
  /**  */
  void (*resetTrigs)( iIBlockBase inst );
  /**  */
  void (*setAnalog)( iIBlockBase inst ,Boolean analog );
  /**  */
  void (*setCarCount)( iIBlockBase inst ,int count );
  /**  */
  void (*setClass)( iIBlockBase inst ,const char* class );
  /**  */
  void (*setDefaultAspect)( iIBlockBase inst ,Boolean signalpair );
  /**  */
  void (*setGhostDetected)( iIBlockBase inst ,const char* key ,const char* ident );
  /**  */
  void (*setGroup)( iIBlockBase inst ,const char* group );
  /**  */
  Boolean (*setLocSchedule)( iIBlockBase inst ,const char* scid ,Boolean manual );
  /**  */
  Boolean (*setLocTour)( iIBlockBase inst ,const char* tourid ,Boolean manual );
  /**  */
  void (*setManager)( iIBlockBase inst ,iIBlockBase manager );
  /**  */
  void (*setMasterID)( iIBlockBase inst ,const char* masterid );
  /**  */
  void (*setTempWait)( iIBlockBase inst ,Boolean wait );
  /**  */
  Boolean (*unLink)( iIBlockBase inst );
  /**  */
  Boolean (*unLock)( iIBlockBase inst ,const char* locid ,const char* routeid );
  /**  */
  Boolean (*unLockForGroup)( iIBlockBase inst ,const char* locid );
  /**  */
  Boolean (*wait)( iIBlockBase inst ,iOLoc loc ,Boolean reverse ,Boolean* oppwait );
  /**  */
  Boolean (*white)( iIBlockBase inst ,Boolean distant ,Boolean reverse );
  /**  */
  Boolean (*yellow)( iIBlockBase inst ,Boolean distant ,Boolean reverse );

  /***** Object: TT *****/
  /** true if the run direction is forwards */
  Boolean (*getRunDir)( struct OTT* inst );
  /**  */
  struct OTT* (*inst)( iONode ini );
  /**  */
  Boolean (*isLocked)( struct OTT* inst ,const char* locid );
  /** true if the sensor state matches the wanted state */
  Boolean (*isSet)( struct OTT* inst );
  /**  */
  void (*modify)( struct OTT* inst ,iONode mod );
  /**  */
  Boolean (*setListener)( struct OTT* inst ,obj listenerObj ,const tt_listener listenerFun );
} *iOTT;

extern struct OTT TTOp;

#ifdef __cplusplus
  }
#endif


#endif
