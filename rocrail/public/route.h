/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Route_H
#define __object_Route_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"

/* RocRail and system includes: */
#include "rocrail/public/loc.h"
#include "rocrail/public/htmlint.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct ORoute {
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

  /***** Object: Route *****/
  /**  */
  Boolean (*cmd)( struct ORoute* inst ,iONode cmd );
  /**  */
  Boolean (*getBlockSignalSide)( struct ORoute* inst ,const char* bkid );
  /**  */
  Boolean (*getDirection)( struct ORoute* inst ,const char* blockid ,Boolean* fromto );
  /**  */
  const char* (*getFromBlock)( struct ORoute* inst );
  /**  */
  Boolean (*getFromBlockSide)( struct ORoute* inst );
  /**  */
  const char* (*getId)( struct ORoute* inst );
  /**  */
  int (*getMaxKmh)( struct ORoute* inst );
  /**  */
  const char* (*getToBlock)( struct ORoute* inst );
  /**  */
  Boolean (*getToBlockSide)( struct ORoute* inst );
  /**  */
  const char* (*getVelocity)( struct ORoute* inst ,int* percent ,iOLoc loco );
  /**  */
  Boolean (*go)( struct ORoute* inst );
  /**  */
  Boolean (*hasPermission)( struct ORoute* inst ,iOLoc lc ,const char* prevBlockID ,Boolean mustChDir );
  /**  */
  Boolean (*hasSwitchCommands)( struct ORoute* inst );
  /**  */
  Boolean (*hasThrownSwitch)( struct ORoute* inst );
  /**  */
  struct ORoute* (*inst)( iONode ini );
  /**  */
  Boolean (*isClosed)( struct ORoute* inst );
  /**  */
  Boolean (*isFree)( struct ORoute* inst ,const char* locid );
  /**  */
  Boolean (*isLocked)( struct ORoute* inst );
  /**  */
  Boolean (*isManual)( struct ORoute* inst ,Boolean* isset );
  /** true if all turnouts are set */
  Boolean (*isSet)( struct ORoute* inst );
  /**  */
  Boolean (*isSetCrossingblockSignals)( struct ORoute* inst );
  /**  */
  Boolean (*isState)( struct ORoute* inst ,const char* state );
  /**  */
  Boolean (*isSwapPost)( struct ORoute* inst );
  /**  */
  Boolean (*link)( struct ORoute* inst ,int linkto );
  /**  */
  Boolean (*lock)( struct ORoute* inst ,const char* locid ,Boolean reverse ,Boolean lockswitches );
  /**  */
  void (*modify)( struct ORoute* inst ,iONode mod );
  /**  */
  void (*reset)( struct ORoute* inst );
  /**  */
  void (*setClass)( struct ORoute* inst ,const char* class );
  /**  */
  void (*setClosed)( struct ORoute* inst );
  /**  */
  Boolean (*unLink)( struct ORoute* inst );
  /**  */
  Boolean (*unLock)( struct ORoute* inst ,const char* locid ,const char** resblocks ,Boolean unlockswitches ,Boolean force );
} *iORoute;

extern struct ORoute RouteOp;

#ifdef __cplusplus
  }
#endif


#endif
