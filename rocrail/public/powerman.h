/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_PowerMan_H
#define __object_PowerMan_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/map.h"
#include "rocs/public/thread.h"
#include "rocs/public/mutex.h"

/* RocRail and system includes: */
#include "rocrail/public/htmlint.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OPowerMan {
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

  /***** Object: PowerMan *****/
  /**  */
  Boolean (*cmd)( struct OPowerMan* inst ,iONode cmd );
  /**  */
  const char* (*getBooster4Block)( struct OPowerMan* inst ,const char* blockid );
  /**  */
  Boolean (*hasBlockPower)( struct OPowerMan* inst ,const char* blockid );
  /**  */
  struct OPowerMan* (*inst)( iONode ini );
  /**  */
  void (*modify)( struct OPowerMan* inst ,iONode mod );
} *iOPowerMan;

extern struct OPowerMan PowerManOp;

#ifdef __cplusplus
  }
#endif


#endif
