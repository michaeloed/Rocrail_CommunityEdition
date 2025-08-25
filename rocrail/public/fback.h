/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_FBack_H
#define __object_FBack_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/list.h"

/* RocRail and system includes: */
#include "rocrail/public/htmlint.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef void (*fback_listener)(obj,Boolean,const char*,const char*,const char*,const char*,const char*,int,int,Boolean);



typedef struct OFBack {
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

  /***** Object: FBack *****/
  /**  */
  Boolean (*addListener)( struct OFBack* inst ,obj listener );
  /**  */
  Boolean (*cmd)( struct OFBack* inst ,iONode cmd ,Boolean update );
  /**  */
  char* (*createAddrKey)( int bus ,int addr ,const char* iid );
  /**  */
  void (*doTimedOff)( struct OFBack* inst );
  /**  */
  void (*event)( struct OFBack* inst ,iONode evt );
  /**  */
  const char* (*getAddrKey)( struct OFBack* inst );
  /**  */
  int (*getCounter)( struct OFBack* inst );
  /**  */
  const char* (*getId)( struct OFBack* inst );
  /**  */
  const char* (*getIdentifier)( struct OFBack* inst );
  /**  */
  Boolean (*getState)( struct OFBack* inst );
  /**  */
  Boolean (*hasShortcut)( struct OFBack* inst );
  /**  */
  struct OFBack* (*inst)( iONode ini );
  /**  */
  Boolean (*isAtGPSPos)( struct OFBack* inst ,int sid ,int x ,int y ,int z ,Boolean* state );
  /**  */
  Boolean (*isState)( struct OFBack* inst ,const char* state );
  /**  */
  void (*modify)( struct OFBack* inst ,iONode fb );
  /**  */
  Boolean (*removeListener)( struct OFBack* inst ,obj listener );
  /**  */
  void (*resetCounter)( struct OFBack* inst );
  /**  */
  void (*resetWheelCount)( struct OFBack* inst );
  /**  */
  void (*setCarCount)( struct OFBack* inst ,int count );
  /**  */
  Boolean (*setListener)( struct OFBack* inst ,obj listenerObj ,const fback_listener listenerFun );
  /**  */
  void (*setState)( struct OFBack* inst ,Boolean state );
} *iOFBack;

extern struct OFBack FBackOp;

#ifdef __cplusplus
  }
#endif


#endif
