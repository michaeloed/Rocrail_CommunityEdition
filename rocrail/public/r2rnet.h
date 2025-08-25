/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_R2Rnet_H
#define __object_R2Rnet_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/map.h"
#include "rocs/public/event.h"
#include "rocs/public/mutex.h"
#include "rocs/public/list.h"
#include "rocs/public/thread.h"
#include "rocs/public/socket.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OR2Rnet {
  /***** Base *****/
  struct OBase  base;

  /***** Object: R2Rnet *****/
  /**  */
  Boolean (*cmd)( struct OR2Rnet* inst ,iONode cmd );
  /**  */
  Boolean (*compare)( const char* id1 ,const char* id2 );
  /**  */
  iONode (*getBlock)( struct OR2Rnet* inst ,const char* bkid );
  /**  */
  struct OR2Rnet* (*inst)( iONode ini );
  /**  */
  void (*locoIsIn)( struct OR2Rnet* inst ,const char* rrid ,const char* lcid ,const char* bkid );
  /**  */
  void (*quit)( struct OR2Rnet* inst );
  /**  */
  Boolean (*reserveBlock)( struct OR2Rnet* inst ,const char* rrid ,const char* bkid ,const char* stid ,iONode lc ,iONode bk ,Boolean check );
  /**  */
  Boolean (*unlockBlock)( struct OR2Rnet* inst ,const char* rrid ,const char* bkid ,const char* lcid );
} *iOR2Rnet;

extern struct OR2Rnet R2RnetOp;

#ifdef __cplusplus
  }
#endif


#endif
