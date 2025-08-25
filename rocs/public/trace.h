/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Trace_H
#define __object_Trace_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/file.h"
#include "rocs/public/mutex.h"
#include "rocs/public/ebcdic.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef void(*trcListener )(int level, char* module, char* msg, int rc, Boolean dump);
typedef void(*ExceptionListener )(int level, char* msg);
typedef enum {TRCLEVEL_EXCEPTION=0x0001,TRCLEVEL_INFO  =0x0002,TRCLEVEL_WARNING=0x0004,TRCLEVEL_DEBUG  =0x0008,
                        TRCLEVEL_BYTE     =0x0010,TRCLEVEL_METHOD=0x0020,TRCLEVEL_MEMORY =0x0040,TRCLEVEL_PARAM  =0x0080,
                        TRCLEVEL_PROTOCOL =0x0100,TRCLEVEL_ERROR =0x0200,TRCLEVEL_PARSE  =0x0400,TRCLEVEL_WRAPPER=0x0800,
                        TRCLEVEL_USER1    =0x1000,TRCLEVEL_USER2 =0x2000,TRCLEVEL_MONITOR=0x4000,TRCLEVEL_XMLH   =0x8000,
                        TRCLEVEL_USER     =0xF000,TRCLEVEL_CALC  =0x10000,TRCLEVEL_STATUS=0x20000,TRCLEVEL_ALL   =0xFFFFFF} tracelevel;



typedef struct OTrace {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Trace *****/
  /** Trace a binary buffer. */
  void (*dmp)( const void* cargo ,tracelevel level ,int id ,const char* buffer ,int size );
  /** Trace a binary buffer. */
  void (*dump)( const void* cargo ,tracelevel level ,const char* buffer ,int size );
  /** Get's the trace object. */
  struct OTrace* (*get)( void );
  /** Get the current trace filename. */
  const char* (*getCurrentFilename)( struct OTrace* inst );
  /** Get trace dumpsize. */
  int (*getDumpsize)( struct OTrace* inst );
  /** Get the current trace FILE object. */
  const FILE* (*getF)( struct OTrace* inst );
  /** Get the trace filename. */
  const char* (*getFilename)( struct OTrace* inst );
  /** Get the trace level(s). */
  tracelevel (*getLevel)( struct OTrace* inst );
  /** Get the current operating system. */
  const char* (*getOS)( void );
  /** Object creator. */
  struct OTrace* (*inst)( tracelevel level ,const char* filename ,Boolean toStdErr );
  /** Get trace to stderr. */
  Boolean (*isStdErr)( struct OTrace* inst );
  /** Prints the trace header. */
  void (*printHeader)( void );
  /** Prints one line into the trace. */
  void (*println)( const char* fmt ,...  );
  /** Replace or set the singleton with this one. */
  void (*set)( struct OTrace* inst );
  /** Sets the application id to use in the trace. */
  void (*setAppID)( struct OTrace* inst ,const char* id );
  /** Set trace dumpsize. */
  void (*setDumpsize)( struct OTrace* inst ,int size );
  /** Dump also an ebcdic column. */
  void (*setEbcdicDump)( struct OTrace* inst ,Boolean ebcdic );
  /** If set, exceptions are also traced in a separate file. */
  void (*setExceptionFile)( struct OTrace* inst ,Boolean useexceptionfile );
  /** Set an exceptionlistener. */
  void (*setExceptionListener)( struct OTrace* inst ,ExceptionListener listener ,Boolean timestamp ,Boolean all );
  /** Change the trace max. filesize. */
  void (*setFileSize)( struct OTrace* inst ,int size );
  /** Change the trace filename. */
  void (*setFilename)( struct OTrace* inst ,const char* filename );
  /** Command to invoke when writing a new exception file. */
  void (*setInvoke)( struct OTrace* inst ,const char* cmd ,Boolean async );
  /** Change the trace level(s). */
  void (*setLevel)( struct OTrace* inst ,tracelevel level );
  /** Set the thread id for main. */
  void (*setMainThreadId)( unsigned long id );
  /** Change the number of files before recycling the oldest. */
  void (*setNrFiles)( struct OTrace* inst ,int cnt );
  /** Set trace to stderr. */
  void (*setStdErr)( struct OTrace* inst ,Boolean tostderr );
  /** Trace. */
  void (*terrno)( const char* objectname ,tracelevel level ,int line ,int id ,int error ,const char* fmt ,...  );
  /** Trace. */
  void (*trace)( const void* cargo ,tracelevel level ,int id ,const char* fmt ,...  );
  /** Trace. */
  void (*trc)( const char* objectname ,tracelevel level ,int line ,int id ,const char* fmt ,...  );
} *iOTrace;

extern struct OTrace TraceOp;

#ifdef __cplusplus
  }
#endif


#endif
