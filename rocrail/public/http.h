/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Http_H
#define __object_Http_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/thread.h"
#include "rocs/public/socket.h"
#include "rocs/public/map.h"
#include "rocs/public/mutex.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef void(*httpcon_callback)(obj,iONode);



typedef struct OHttp {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Http *****/
  /**  */
  void (*broadcastEvent)( struct OHttp* inst ,iONode evt );
  /** Parse and map the post data. */
  iOMap (*createPostDataMap)( const char* postdata );
  /**  */
  void (*deletePostDataMap)( iOMap postdatamap );
  /** Object creator. */
  struct OHttp* (*inst)( iONode ini ,httpcon_callback callbackfun ,obj callbackobj ,const char* imgpath ,const char* controlcode ,const char* slavecode );
  /**  */
  Boolean (*isEnded)( struct OHttp* inst );
  /**  */
  void (*setCallback)( struct OHttp* inst ,httpcon_callback callbackfun ,obj callbackobj );
  /** Shutdown Http. */
  void (*shutdown)( struct OHttp* inst );
} *iOHttp;

extern struct OHttp HttpOp;

#ifdef __cplusplus
  }
#endif


#endif
