/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_SrcpCon_H
#define __object_SrcpCon_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/map.h"
#include "rocs/public/socket.h"
#include "rocs/public/thread.h"
#include "rocs/public/mutex.h"
#include "rocs/public/serial.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef void(*srcpcon_callback)(obj,iONode);



typedef struct OSrcpCon {
  /***** Base *****/
  struct OBase  base;

  /***** Object: SrcpCon *****/
  /**  */
  void (*broadcastEvent)( struct OSrcpCon* inst ,iONode evt );
  /**  */
  int (*getClientCount)( struct OSrcpCon* inst );
  /**  */
  const char* (*getClientHost)( struct OSrcpCon* inst );
  /**  */
  int (*getClientPort)( struct OSrcpCon* inst );
  /**  */
  struct OSrcpCon* (*inst)( iONode ini ,srcpcon_callback callbackfun ,obj callbackobj );
  /**  */
  void (*postEvent)( struct OSrcpCon* inst ,iONode evt ,const char* iwname );
  /**  */
  void (*setCallback)( struct OSrcpCon* inst ,srcpcon_callback callbackfun ,obj callbackobj );
} *iOSrcpCon;

extern struct OSrcpCon SrcpConOp;

#ifdef __cplusplus
  }
#endif


#endif
