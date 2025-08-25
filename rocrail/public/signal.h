/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Signal_H
#define __object_Signal_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"

/* RocRail and system includes: */
#include "rocrail/public/htmlint.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OSignal {
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

  /***** Object: Signal *****/
  /**  */
  void (*aspect)( struct OSignal* inst ,int nr );
  /**  */
  void (*blank)( struct OSignal* inst );
  /**  */
  Boolean (*cmd)( struct OSignal* inst ,iONode cmd ,Boolean update );
  /**  */
  void (*event)( struct OSignal* inst ,iONode evt );
  /**  */
  const char* (*getId)( struct OSignal* inst );
  /**  */
  const char* (*getState)( struct OSignal* inst );
  /**  */
  void (*green)( struct OSignal* inst );
  /**  */
  struct OSignal* (*inst)( iONode ini );
  /**  */
  Boolean (*isManualOperated)( struct OSignal* inst );
  /**  */
  Boolean (*isResetManualOperated)( struct OSignal* inst );
  /**  */
  Boolean (*isState)( struct OSignal* inst ,const char* state );
  /**  */
  void (*modify)( struct OSignal* inst ,iONode mod );
  /**  */
  void (*red)( struct OSignal* inst );
  /**  */
  void (*white)( struct OSignal* inst );
  /**  */
  void (*yellow)( struct OSignal* inst );
} *iOSignal;

extern struct OSignal SignalOp;

#ifdef __cplusplus
  }
#endif


#endif
