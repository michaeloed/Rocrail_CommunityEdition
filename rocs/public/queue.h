/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Queue_H
#define __object_Queue_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/event.h"
#include "rocs/public/mutex.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef enum {low=0,normal=1,high=2} q_prio;



typedef struct OQueue {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Queue *****/
  /** Number of messages in the queue. */
  int (*count)( struct OQueue* inst );
  /** Read a message. */
  obj (*get)( struct OQueue* inst );
  /** Object creator. */
  struct OQueue* (*inst)( int size );
  /** Are messages in the queue? */
  Boolean (*isEmpty)( struct OQueue* inst );
  /** Post a message. */
  Boolean (*post)( struct OQueue* inst ,obj object ,q_prio prio );
  /** Set the Queues description. */
  void (*setDesc)( struct OQueue* inst ,const char* desc );
  /** Wait for a messages. */
  obj (*waitPost)( struct OQueue* inst );
} *iOQueue;

extern struct OQueue QueueOp;

#ifdef __cplusplus
  }
#endif


#endif
