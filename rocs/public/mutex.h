/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Mutex_H
#define __object_Mutex_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OMutex {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Mutex *****/
  /** Get last error code. */
  int (*getRc)( struct OMutex* inst );
  /** Object creator */
  struct OMutex* (*inst)( const char* name ,Boolean create );
  /** Release the mutext. (release, unlock) */
  Boolean (*post)( struct OMutex* inst );
  /** Wait for the mutext. */
  Boolean (*trywait)( struct OMutex* inst ,int time );
  /** Wait for the mutext. (request, lock) */
  Boolean (*wait)( struct OMutex* inst );
} *iOMutex;

extern struct OMutex MutexOp;

#ifdef __cplusplus
  }
#endif


#endif
