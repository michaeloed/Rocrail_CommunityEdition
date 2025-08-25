/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocDigs
  * XML: $Source: /cvsroot/rojav/rocdigs/rocdigs.xml,v $
  * XML: $Revision: 1.14 $
  * Date: Fri Aug  3 14:03:49 2018
  */

#ifndef __object_OM32_H
#define __object_OM32_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/serial.h"
#include "rocs/public/trace.h"
#include "rocs/public/thread.h"

/* RocDigs and system includes: */
#include "rocint/public/digint.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef enum {DATA_FLAG=0x80, RETRANSMIT_FLAG=0x40, FIXED_FLAG=0x03, ADDR_MASK=0x1C} __om32header;



typedef struct OOM32 {
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

  /***** Object: OM32 *****/
  /**  */
  struct OOM32* (*inst)( const iONode ini ,const iOTrace trc );
} *iOOM32;

extern struct OOM32 OM32Op;

#ifdef __cplusplus
  }
#endif


#endif
