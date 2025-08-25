/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#ifndef __object_DINAMO_H
#define __object_DINAMO_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/serial.h"
#include "rocs/public/trace.h"
#include "rocs/public/thread.h"
#include "rocs/public/map.h"

/* RocDigs and system includes: */
#include "rocint/public/digint.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef enum {DATA_FLAG=0x80, TOGGLE_FLAG=0x40, FAULT_FLAG=0x20, HOLD_FLAG=0x10, VER3_FLAG=0x08, CNT_MASK=0x07} __dinamoheader;
typedef enum {SYS_CMD=0x01, SYS_RESET_FAULT=0x00, SYS_SET_HFI=0x01, SYS_GET_VER=0x02, SYS_GET_FIRMVER=0x0A, SYS_GET_INFO=0x03, SYS_SET_FLASH=0x04,
                        SYS_SET_EVENT=0x20} __dinamosyscmds;



typedef struct ODINAMO {
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

  /***** Object: DINAMO *****/
  /**  */
  struct ODINAMO* (*inst)( const iONode ini ,const iOTrace trc );
} *iODINAMO;

extern struct ODINAMO DINAMOOp;

#ifdef __cplusplus
  }
#endif


#endif
