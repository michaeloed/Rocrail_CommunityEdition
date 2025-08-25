/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Model_H
#define __object_Model_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/list.h"
#include "rocs/public/map.h"
#include "rocs/public/doc.h"
#include "rocs/public/mutex.h"
#include "rocs/public/file.h"

/* RocRail and system includes: */
#include <stdio.h>
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


typedef void (*model_listener)(obj,iONode);



typedef struct OModel {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Model *****/
  /**  */
  void (*addCoKey)( struct OModel* inst ,const char* key ,iOOutput co );
  /**  */
  void (*addFbKey)( struct OModel* inst ,const char* key ,obj fb );
  /**  */
  Boolean (*addItem)( struct OModel* inst ,iONode props );
  /**  */
  void (*addListener)( struct OModel* inst ,model_listener listenerfun ,obj cargo );
  /**  */
  iIBlockBase (*addNetBlock)( struct OModel* inst ,iONode bkprops );
  /**  */
  iOLoc (*addNetLoc)( struct OModel* inst ,iONode lcprops );
  /**  */
  void (*addNetRoute)( struct OModel* inst ,iONode route );
  /**  */
  void (*addSwKey)( struct OModel* inst ,const char* key ,iOSwitch sw );
  /**  */
  void (*addSysEventListener)( struct OModel* inst ,obj listener );
  /**  */
  iONode (*addVariable)( struct OModel* inst ,const char* id );
  /**  */
  void (*analyse)( struct OModel* inst ,int mode );
  /** returns the route to start with */
  iORoute (*calcRoute)( struct OModel* inst ,iOList routeList ,const char* fromBlockId ,const char* toLocationId ,const char* toBlockId ,iOLoc loc ,Boolean swapPlacingInPrevRoute );
  /** returns the route to start with */
  iORoute (*calcRouteFromCurBlock)( struct OModel* inst ,iOList routeList ,const char* scheduleid ,int* scheduleIdx ,const char* curblockid ,const char* currouteid ,iOLoc loc ,Boolean swapPlacingInPrevRoute ,int* indelay ,Boolean secondnextblock );
  /**  */
  const char* (*checkForBlockGroup)( struct OModel* inst ,const char* BlockId );
  /**  */
  Boolean (*cmd)( struct OModel* inst ,iONode cmd );
  /**  */
  void (*event)( struct OModel* inst ,iONode evt );
  /**  */
  iIBlockBase (*findDest)( struct OModel* inst ,const char* fromBlockId ,const char* fromRouteId ,iOLoc loc ,iORoute* routeRef ,const char* gotoBlockId ,Boolean swapPlacingInPrevRoute ,Boolean forceOppDir ,Boolean schedule ,Boolean secondnextblock );
  /**  */
  void (*forceUnlock)( struct OModel* inst );
  /**  */
  iOAction (*getAction)( struct OModel* inst ,const char* id );
  /**  */
  iIBlockBase (*getBlock)( struct OModel* inst ,const char* id );
  /**  */
  iIBlockBase (*getBlock4Signal)( struct OModel* inst ,const char* id );
  /**  */
  iIBlockBase (*getBlockByAddr)( struct OModel* inst ,const char* iid ,int addr );
  /**  */
  iOLocation (*getBlockLocation)( struct OModel* inst ,const char* id );
  /**  */
  iOCar (*getCar)( struct OModel* inst ,const char* id );
  /**  */
  iOCar (*getCarByAddress)( struct OModel* inst ,int decaddr ,const char* iid );
  /**  */
  iOCar (*getCarByIdent)( struct OModel* inst ,const char* ident );
  /**  */
  iOOutput (*getCoByAddress)( struct OModel* inst ,const char* iid ,int bus ,int addr ,int port ,int type ,const char* uidname );
  /**  */
  iONode (*getDec)( struct OModel* inst ,const char* id );
  /**  */
  iOList (*getFBStat)( struct OModel* inst );
  /**  */
  iOFBack (*getFBack)( struct OModel* inst ,const char* id );
  /**  */
  iOMap (*getFeedbackMap)( struct OModel* inst );
  /**  */
  iOFBack (*getGPSSensor)( struct OModel* inst ,int sid ,int x ,int y ,int z ,Boolean* state );
  /**  */
  iOList (*getLevelItems)( struct OModel* inst ,int level ,int* cx ,int* cy ,Boolean forserefresh );
  /**  */
  iOLoc (*getLoc)( struct OModel* inst ,const char* id ,iONode props ,Boolean generate );
  /**  */
  iOLoc (*getLocByAddress)( struct OModel* inst ,int decaddr ,const char* iid );
  /**  */
  iOLoc (*getLocByIdent)( struct OModel* inst ,const char* ident1 ,const char* ident2 ,const char* ident3 ,const char* ident4 ,Boolean dir );
  /**  */
  iOList (*getLocIDs)( struct OModel* inst );
  /**  */
  iOLocation (*getLocation)( struct OModel* inst ,const char* id );
  /**  */
  iOMap (*getLocoMap)( struct OModel* inst );
  /**  */
  const char* (*getManagedID)( struct OModel* inst ,const char* blockid );
  /**  */
  iOLoc (*getMasterLoc)( struct OModel* inst ,const char* slaveID );
  /**  */
  const iONode (*getModPlan)( struct OModel* inst );
  /**  */
  const iONode (*getModel)( struct OModel* inst );
  /**  */
  const iONode (*getModule)( struct OModel* inst ,const char* modid );
  /**  */
  iOOperator (*getOperator)( struct OModel* inst ,const char* id );
  /**  */
  iOOperator (*getOperator4Car)( struct OModel* inst ,const char* id );
  /**  */
  iOOutput (*getOutput)( struct OModel* inst ,const char* id );
  /**  */
  iONode (*getResolveVariable)( struct OModel* inst ,const char* varid ,iOMap map );
  /**  */
  const char* (*getResolvedRouteID)( struct OModel* inst ,const char* id );
  /**  */
  iORoute (*getRoute)( struct OModel* inst ,const char* id );
  /**  */
  iOList (*getRouteAliases)( struct OModel* inst ,const char* routeIds );
  /**  */
  iONode (*getSchedule)( struct OModel* inst ,const char* id );
  /** returns the fitting route */
  int (*getScheduleIndex)( struct OModel* inst ,const char* scheduleid ,const char* curblockid ,iOLoc loc );
  /**  */
  iOSelTab (*getSelectiontable)( struct OModel* inst ,const char* id );
  /**  */
  iOList (*getSensorsByAddress)( struct OModel* inst ,const char* iid ,int bus ,int addr ,const char* uidname );
  /**  */
  iOSignal (*getSgByAddress)( struct OModel* inst ,const char* iid ,int bus ,int addr ,int port ,int type ,const char* uidname );
  /**  */
  iOSignal (*getSignal)( struct OModel* inst ,const char* id );
  /**  */
  iOMap (*getSignalMap)( struct OModel* inst );
  /**  */
  iOStage (*getStage)( struct OModel* inst ,const char* id );
  /**  */
  obj (*getSwByAddress)( struct OModel* inst ,const char* iid ,int bus ,int addr ,int port ,int gate ,int type ,const char* uidname ,obj offset );
  /**  */
  iOSwitch (*getSwitch)( struct OModel* inst ,const char* id );
  /**  */
  iOMap (*getSwitchMap)( struct OModel* inst );
  /**  */
  char* (*getSysVar)( struct OModel* inst ,const char* id );
  /**  */
  iOText (*getText)( struct OModel* inst ,const char* id );
  /**  */
  long (*getTime)( struct OModel* inst );
  /**  */
  const char* (*getTitle)( struct OModel* inst );
  /**  */
  iONode (*getTour)( struct OModel* inst ,const char* id );
  /**  */
  iOTrack (*getTrack)( struct OModel* inst ,const char* id );
  /**  */
  iOTT (*getTurntable)( struct OModel* inst ,const char* id );
  /**  */
  iONode (*getVariable)( struct OModel* inst ,const char* id );
  /**  */
  iONode (*getWeather)( struct OModel* inst ,const char* id );
  /**  */
  Boolean (*hasBlockCars)( struct OModel* inst ,const char* id );
  /**  */
  Boolean (*init)( struct OModel* inst );
  /**  */
  void (*initField)( struct OModel* inst ,Boolean full );
  /**  */
  void (*initMasterLocMap)( struct OModel* inst );
  /**  */
  struct OModel* (*inst)( const char* planfile ,const char* locofile );
  /**  */
  Boolean (*isAuto)( struct OModel* inst );
  /**  */
  Boolean (*isBlockGroupLockedForLoco)( struct OModel* inst ,const char* BlockId ,const char* LocoId );
  /**  */
  Boolean (*isEnableSwFb)( struct OModel* inst );
  /**  */
  Boolean (*isHealthy)( struct OModel* inst );
  /**  */
  Boolean (*isSaveOnShutdown)( struct OModel* inst );
  /**  */
  Boolean (*isScheduleFree)( struct OModel* inst ,const char* scid ,const char* lcid );
  /**  */
  void (*loadBlockOccupancy)( struct OModel* inst );
  /**  */
  Boolean (*lockBlockGroup)( struct OModel* inst ,const char* Group ,const char* BlockId ,const char* LocoId );
  /**  */
  Boolean (*modify)( struct OModel* inst ,iONode mod );
  /**  */
  Boolean (*modifyItem)( struct OModel* inst ,iONode mod );
  /**  */
  void (*printBlocks)( struct OModel* inst ,FILE * f );
  /**  */
  void (*printFBacks)( struct OModel* inst ,FILE * f );
  /**  */
  void (*printLocs)( struct OModel* inst ,FILE * f );
  /**  */
  void (*printRoutes)( struct OModel* inst ,FILE * f );
  /**  */
  void (*printSignals)( struct OModel* inst ,FILE * f );
  /**  */
  void (*printSwitches)( struct OModel* inst ,FILE * f );
  /**  */
  void (*removeCoKey)( struct OModel* inst ,const char* key );
  /**  */
  void (*removeFbKey)( struct OModel* inst ,const char* key ,obj fb );
  /**  */
  void (*removeSwKey)( struct OModel* inst ,const char* key );
  /**  */
  void (*removeSysEventListener)( struct OModel* inst ,obj listener );
  /**  */
  void (*save)( struct OModel* inst ,Boolean removeGen );
  /**  */
  void (*saveAs)( struct OModel* inst ,const char* filename );
  /**  */
  void (*saveBlockOccupancy)( struct OModel* inst ,const char* occfilename );
  /**  */
  void (*setBlockOccupancy)( struct OModel* inst ,const char* BlockId ,const char* LocId ,Boolean closed ,int placing ,int enterside ,const char* SectionId );
  /**  */
  void (*setModPlan)( struct OModel* inst ,iONode modplan );
  /**  */
  void (*setModel)( struct OModel* inst ,iONode model );
  /**  */
  void (*setModule)( struct OModel* inst ,iONode module );
  /**  */
  void (*stop)( struct OModel* inst );
  /**  */
  Boolean (*unlockBlockGroup)( struct OModel* inst ,const char* Group ,const char* LocoId );
  /**  */
  void (*updateFB)( struct OModel* inst );
} *iOModel;

extern struct OModel ModelOp;

#ifdef __cplusplus
  }
#endif


#endif
