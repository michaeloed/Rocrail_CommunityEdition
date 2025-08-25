/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_ClntCon_H
#define __object_ClntCon_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/map.h"
#include "rocs/public/socket.h"
#include "rocs/public/thread.h"
#include "rocs/public/mutex.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef void(*clntcon_callback)(obj,iONode);



typedef struct OClntCon {
  /***** Base *****/
  struct OBase  base;

  /***** Object: ClntCon *****/
  /**  */
  void (*broadcastEvent)( struct OClntCon* inst ,iONode evt );
  /**  */
  int (*getClientCount)( struct OClntCon* inst );
  /**  */
  const char* (*getClientHost)( struct OClntCon* inst );
  /**  */
  int (*getClientPort)( struct OClntCon* inst );
  /**  */
  int (*getConCount)( struct OClntCon* inst );
  /**  */
  struct OClntCon* (*inst)( iONode ini ,int port ,clntcon_callback callbackfun ,obj callbackobj );
  /**  */
  void (*postEvent)( struct OClntCon* inst ,iONode evt ,const char* iwname );
  /**  */
  void (*setCallback)( struct OClntCon* inst ,clntcon_callback callbackfun ,obj callbackobj );
} *iOClntCon;

extern struct OClntCon ClntConOp;

#ifdef __cplusplus
  }
#endif


#endif
