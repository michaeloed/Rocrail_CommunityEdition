/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#ifndef __object_SRCP_H
#define __object_SRCP_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/trace.h"
#include "rocs/public/socket.h"
#include "rocs/public/thread.h"
#include "rocs/public/map.h"
#include "rocs/public/serial.h"
#include "rocs/public/mutex.h"

/* RocDigs and system includes: */
#include "rocint/public/digint.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef enum {SRCP_STATE_OK=1, SRCP_STATE_ERROR} srcpstate;
typedef Boolean(*sublib_init)(obj);
typedef int(*sublib_connect)(obj,Boolean);
typedef void(*sublib_disconnect)(obj,Boolean);
typedef int(*sublib_read)(obj,char*,Boolean);
typedef int(*sublib_write)(obj,const char*,char*,Boolean);
typedef Boolean(*sublib_available)(obj);



typedef struct OSRCP {
  /***** Base *****/
  struct OBase  base;

  /***** Interface: DigInt *****/
  /**  */
  iONode (*cmd)( obj inst ,const iONode cmd );
  /**  */
  byte* (*cmdRaw)( obj inst ,const byte* cmd );
  /**  */
  void (*halt)( obj inst ,Boolean poweroff ,Boolean shutdown );
  /**  */
  Boolean (*setListener)( obj inst ,obj listenerObj ,const digint_listener listenerFun );
  /**  */
  Boolean (*setRawListener)( obj inst ,obj listenerObj ,const digint_rawlistener listenerRawFun );
  /** external shortcut event */
  void (*shortcut)( obj inst );
  /** bit0=power, bit1=programming, bit2=connection */
  int (*state)( obj inst );
  /**  */
  Boolean (*supportPT)( obj inst );
  /** vmajor*1000 + vminor*100 + patch */
  int (*version)( obj inst );

  /***** Object: SRCP *****/
  /**  */
  struct OSRCP* (*inst)( const iONode ini ,const iOTrace trc );
} *iOSRCP;

extern struct OSRCP SRCPOp;

#ifdef __cplusplus
  }
#endif


#endif
