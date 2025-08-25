/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Lib_H
#define __object_Lib_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OLib {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Lib *****/
  /** Get a library procedure. */
  const void* (*getProc)( struct OLib* inst ,const char* procname );
  /** Object creator. */
  struct OLib* (*inst)( const char* name );
} *iOLib;

extern struct OLib LibOp;

#ifdef __cplusplus
  }
#endif


#endif
