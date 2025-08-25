/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Event_H
#define __object_Event_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OEvent {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Event *****/
  /** Object creator. */
  struct OEvent* (*inst)( const char* name ,Boolean create );
  /** Reset the event. */
  Boolean (*reset)( struct OEvent* inst );
  /** Set the event. */
  Boolean (*set)( struct OEvent* inst );
  /** Wait a given time for event to become posted. */
  Boolean (*trywait)( struct OEvent* inst ,int time );
  /** Wait for event to become posted. */
  Boolean (*wait)( struct OEvent* inst );
} *iOEvent;

extern struct OEvent EventOp;

#ifdef __cplusplus
  }
#endif


#endif
