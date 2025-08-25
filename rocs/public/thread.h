/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Thread_H
#define __object_Thread_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/list.h"
#include "rocs/public/queue.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef void (*thread_run)(void*);



typedef struct OThread {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Thread *****/
  /** Find a thread by name. */
  struct OThread* (*find)( const char* name );
  /** Find a thread by id. */
  struct OThread* (*findById)( unsigned long id );
  /** Get a list of all threads. */
  iOList (*getAll)( void );
  /** Thread name. */
  const char* (*getName)( struct OThread* inst );
  /** Get parameter object. */
  void* (*getParm)( struct OThread* inst );
  /** Get post from the queue. (NULL if nothing is in queue.) */
  obj (*getPost)( struct OThread* inst );
  /** Check if there is post the queue. */
  Boolean (*hasPost)( struct OThread* inst );
  /** Get current thread id. */
  unsigned long (*id)( void );
  /** Object creator. */
  struct OThread* (*inst)( const char* name ,thread_run run ,void* parm );
  /** Pause signaled. */
  Boolean (*isPause)( struct OThread* inst );
  /** Quit signaled. */
  Boolean (*isQuit)( struct OThread* inst );
  /** Waits for thread termination and returns True if ok. */
  Boolean (*join)( struct OThread* inst );
  /** Kill a thread by reference. */
  void (*kill)( struct OThread* inst );
  /** set pause flag */
  void (*pause)( struct OThread* inst ,Boolean pause );
  /** Post a message into the queue. */
  Boolean (*post)( struct OThread* inst ,obj msg );
  /** Post a message into the queue. */
  Boolean (*prioPost)( struct OThread* inst ,obj msg ,int prio );
  /** Signals thread to stop as soon as possible. */
  void (*requestQuit)( struct OThread* inst );
  /** Signals all thread to stop as soon as possible. */
  void (*requestQuitAll)( void );
  /**  */
  void (*setDescription)( struct OThread* inst ,const char* desc );
  /** Sets the priority to high. */
  void (*setHigh)( struct OThread* inst );
  /** Change the default stacksize. */
  void (*setStacksize)( struct OThread* inst ,long size );
  /** Sleeps the current thread. */
  void (*sleep)( int time );
  /** Starts the thread runner. */
  Boolean (*start)( struct OThread* inst );
  /** Get post from the queue. (Wait until post comes in queue.) */
  obj (*waitPost)( struct OThread* inst );
} *iOThread;

extern struct OThread ThreadOp;

#ifdef __cplusplus
  }
#endif


#endif
