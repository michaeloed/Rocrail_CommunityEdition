/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_JS_H
#define __object_JS_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/list.h"
#include "rocs/public/thread.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef void(*jsListener )( int dev, int type, int number, int value, unsigned long msec );



typedef struct OJS {
  /***** Base *****/
  struct OBase  base;

  /***** Object: JS *****/
  /**  */
  int (*init)( struct OJS* inst ,int* devicemap );
  /** Object creator. */
  struct OJS* (*inst)( void );
  /** Set an JS listener. */
  Boolean (*setListener)( struct OJS* inst ,jsListener listener ,int devnr );
  /**  */
  void (*start)( struct OJS* inst );
} *iOJS;

extern struct OJS JSOp;

#ifdef __cplusplus
  }
#endif


#endif
