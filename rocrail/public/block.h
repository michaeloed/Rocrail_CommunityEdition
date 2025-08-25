/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Block_H
#define __object_Block_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/list.h"
#include "rocs/public/map.h"
#include "rocs/public/node.h"
#include "rocs/public/mutex.h"

/* RocRail and system includes: */
#include "rocrail/public/loc.h"
#include "rocrail/public/htmlint.h"
#include "rocint/public/blockbase.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef enum {enter_event=100,enter2pre_event,enter2in_event,in_event,exit_event,pre2in_event,ghost_event,occupied_event,ident_event,shortin_event,run_event,stall_event,takeover_event,release_event,swap_event,enter2shortin_event,free_event,cmd_event} block_fbevent;
typedef enum {suits_not=0,suits_well=1,suits_ok=2} block_suits;
typedef void (*block_listener)(obj,block_fbevent);



typedef struct OBlock {
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

  /***** Object: Block *****/
  /**  */
  int (*getEventCode)( struct OBlock* inst ,const char* evtname );
  /**  */
  const char* (*getGroup)( struct OBlock* inst );
  /**  */
  struct OBlock* (*inst)( iONode ini );
  /**  */
  void (*modify)( struct OBlock* inst ,iONode modification );
  /**  */
  Boolean (*setListener)( struct OBlock* inst ,obj listenerObj ,const block_listener listenerFun );
  /**  */
  Boolean (*setManual)( struct OBlock* inst ,Boolean manual );
} *iOBlock;

extern struct OBlock BlockOp;

#ifdef __cplusplus
  }
#endif


#endif
