/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocInt
  * XML: $Source: /cvsroot/rojav/rocint/rocint.xml,v $
  * XML: $Revision: 1.4 $
  * Date: Fri Aug  3 14:03:34 2018
  */

#ifndef __object_DigInt_H
#define __object_DigInt_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef void (*digint_listener)(obj,iONode,int);
typedef void (*digint_rawlistener)(obj,byte*,int);
typedef iONode(*queryProperties)(obj,const char*,const char*);



typedef struct IDigInt {
  /***** Base *****/
  struct OBase  base;

  /***** Object: DigInt *****/
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
} *iIDigInt;


#ifdef __cplusplus
  }
#endif


#endif
