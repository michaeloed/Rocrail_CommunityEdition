/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_BlockGroup_H
#define __object_BlockGroup_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/map.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OBlockGroup {
  /***** Base *****/
  struct OBase  base;

  /***** Object: BlockGroup *****/
  /**  */
  Boolean (*cmd)( struct OBlockGroup* inst ,iONode cmd );
  /**  */
  struct OBlockGroup* (*inst)( iONode ini );
  /**  */
  Boolean (*isFree)( struct OBlockGroup* inst ,const char* BlockId ,const char* LocoId );
  /**  */
  Boolean (*isLockedForLoco)( struct OBlockGroup* inst ,const char* LocoId );
  /**  */
  Boolean (*lock)( struct OBlockGroup* inst ,const char* BlockId ,const char* LocoId );
  /**  */
  void (*modify)( struct OBlockGroup* inst ,iONode mod );
  /**  */
  void (*reset)( struct OBlockGroup* inst );
  /**  */
  Boolean (*unlock)( struct OBlockGroup* inst ,const char* LocoId );
} *iOBlockGroup;

extern struct OBlockGroup BlockGroupOp;

#ifdef __cplusplus
  }
#endif


#endif
