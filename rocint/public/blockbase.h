/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocInt
  * XML: $Source: /cvsroot/rojav/rocint/rocint.xml,v $
  * XML: $Revision: 1.4 $
  * Date: Fri Aug  3 14:03:34 2018
  */

#ifndef __object_BlockBase_H
#define __object_BlockBase_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"

/* RocInt and system includes: */
#include "rocrail/public/loc.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct IBlockBase {
  /***** Base *****/
  struct OBase  base;

  /***** Object: BlockBase *****/
  /**  */
  void (*acceptIdent)( struct IBlockBase* inst ,Boolean accept );
  /**  */
  Boolean (*allowBBT)( struct IBlockBase* inst );
  /**  */
  Boolean (*cmd)( struct IBlockBase* inst ,iONode cmd );
  /**  */
  void (*depart)( struct IBlockBase* inst );
  /**  */
  void (*didNotDepart)( struct IBlockBase* inst ,const char* LocoId );
  /**  */
  void (*enterBlock)( struct IBlockBase* inst ,const char* locid );
  /**  */
  Boolean (*event)( struct IBlockBase* inst ,Boolean puls ,const char* id ,const char* ident1 ,const char* ident2 ,const char* ident3 ,const char* ident4 ,int val ,int wheelcount ,iONode evtDescr ,Boolean dir );
  /**  */
  void (*exitBlock)( struct IBlockBase* inst ,const char* locid ,Boolean unexpected );
  /**  */
  int (*getDepartDelay)( struct IBlockBase* inst );
  /**  */
  const char* (*getFromBlockId)( struct IBlockBase* inst );
  /**  */
  const char* (*getInLoc)( struct IBlockBase* inst );
  /**  */
  const char* (*getLoc)( struct IBlockBase* inst );
  /**  */
  struct IBlockBase* (*getManager)( struct IBlockBase* inst );
  /**  */
  int (*getMaxKmh)( struct IBlockBase* inst );
  /**  */
  int (*getOccTime)( struct IBlockBase* inst );
  /**  */
  int (*getRandomRate)( struct IBlockBase* inst ,const char* lcid );
  /**  */
  const char* (*getState)( struct IBlockBase* inst );
  /**  */
  int (*getTDaddress)( struct IBlockBase* inst );
  /**  */
  const char* (*getTDiid)( struct IBlockBase* inst );
  /**  */
  int (*getTDport)( struct IBlockBase* inst );
  /**  */
  const char* (*getVelocity)( struct IBlockBase* inst ,int* percent ,Boolean onexit ,Boolean reverse ,Boolean onstop );
  /**  */
  int (*getVisitCnt)( struct IBlockBase* inst ,const char* locid );
  /**  */
  int (*getWait)( struct IBlockBase* inst ,iOLoc loc ,Boolean reverse ,int* oppwait );
  /**  */
  int (*getWheelCount)( struct IBlockBase* inst );
  /**  */
  float (*getmvspeed)( struct IBlockBase* inst );
  /**  */
  Boolean (*green)( struct IBlockBase* inst ,Boolean distant ,Boolean reverse );
  /**  */
  Boolean (*hasClass)( struct IBlockBase* inst ,const char* class );
  /**  */
  Boolean (*hasEnter2Route)( struct IBlockBase* inst ,const char* fromBlockId );
  /**  */
  Boolean (*hasExtStop)( struct IBlockBase* inst ,const char* locoid );
  /**  */
  obj (*hasManualSignal)( struct IBlockBase* inst ,Boolean distant ,Boolean reverse );
  /**  */
  Boolean (*hasPre2In)( struct IBlockBase* inst ,const char* fromBlockId );
  /**  */
  void (*inBlock)( struct IBlockBase* inst ,const char* locid );
  /**  */
  void (*init)( struct IBlockBase* inst );
  /**  */
  Boolean (*isDepartureAllowed)( struct IBlockBase* inst ,const char* LocoId ,Boolean force );
  /**  */
  Boolean (*isFree)( struct IBlockBase* inst ,const char* locid );
  /**  */
  Boolean (*isFreeBlockOnEnter)( struct IBlockBase* inst );
  /**  */
  Boolean (*isLinked)( struct IBlockBase* inst );
  /**  */
  Boolean (*isReady)( struct IBlockBase* inst );
  /**  */
  Boolean (*isState)( struct IBlockBase* inst ,const char* state );
  /**  */
  int (*isSuited)( struct IBlockBase* inst ,iOLoc loc ,int* restlen ,Boolean checkprev );
  /**  */
  Boolean (*isTD)( struct IBlockBase* inst );
  /**  */
  Boolean (*isTTBlock)( struct IBlockBase* inst );
  /**  */
  Boolean (*isTerminalStation)( struct IBlockBase* inst );
  /**  */
  Boolean (*link)( struct IBlockBase* inst ,struct IBlockBase* linkto );
  /**  */
  Boolean (*lock)( struct IBlockBase* inst ,const char* locid ,const char* blockid ,const char* routeid ,Boolean crossing ,Boolean reset ,Boolean reverse ,int indelay ,const char* masterId ,Boolean force );
  /**  */
  Boolean (*lockForGroup)( struct IBlockBase* inst ,const char* locid );
  /**  */
  Boolean (*red)( struct IBlockBase* inst ,Boolean distant ,Boolean reverse );
  /**  */
  void (*reset)( struct IBlockBase* inst ,Boolean saveCurBlock );
  /**  */
  void (*resetTD)( struct IBlockBase* inst );
  /**  */
  void (*resetTrigs)( struct IBlockBase* inst );
  /**  */
  void (*setAnalog)( struct IBlockBase* inst ,Boolean analog );
  /**  */
  void (*setCarCount)( struct IBlockBase* inst ,int count );
  /**  */
  void (*setClass)( struct IBlockBase* inst ,const char* class );
  /**  */
  void (*setDefaultAspect)( struct IBlockBase* inst ,Boolean signalpair );
  /**  */
  void (*setGhostDetected)( struct IBlockBase* inst ,const char* key ,const char* ident );
  /**  */
  void (*setGroup)( struct IBlockBase* inst ,const char* group );
  /**  */
  Boolean (*setLocSchedule)( struct IBlockBase* inst ,const char* scid ,Boolean manual );
  /**  */
  Boolean (*setLocTour)( struct IBlockBase* inst ,const char* tourid ,Boolean manual );
  /**  */
  void (*setManager)( struct IBlockBase* inst ,struct IBlockBase* manager );
  /**  */
  void (*setMasterID)( struct IBlockBase* inst ,const char* masterid );
  /**  */
  void (*setTempWait)( struct IBlockBase* inst ,Boolean wait );
  /**  */
  Boolean (*unLink)( struct IBlockBase* inst );
  /**  */
  Boolean (*unLock)( struct IBlockBase* inst ,const char* locid ,const char* routeid );
  /**  */
  Boolean (*unLockForGroup)( struct IBlockBase* inst ,const char* locid );
  /**  */
  Boolean (*wait)( struct IBlockBase* inst ,iOLoc loc ,Boolean reverse ,Boolean* oppwait );
  /**  */
  Boolean (*white)( struct IBlockBase* inst ,Boolean distant ,Boolean reverse );
  /**  */
  Boolean (*yellow)( struct IBlockBase* inst ,Boolean distant ,Boolean reverse );
} *iIBlockBase;


#ifdef __cplusplus
  }
#endif


#endif
