/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Mem_H
#define __object_Mem_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef enum {RocsAttrID=0, RocsCmdLnID, RocsDirID, RocsDocID, RocsEventID, RocsFileID, RocsLibID, RocsListID, RocsMapID, RocsMutexID, RocsNodeID, RocsQueueID, RocsSerialID, RocsSocketID, RocsStrID, RocsStringID, RocsSystemID, RocsThreadID, RocsTraceID, RocsEbcdicID, RocsMsgID, RocsStrTokID, RocsXmlHID, RocsLASTID} RocsMemID;

#define allocMem(size)MemOp.alloc(size,__FILE__,__LINE__)
#define reallocMem(p,size)MemOp.realloc(p,size,__FILE__,__LINE__)
#define freeMem(p)MemOp.free(p,__FILE__,__LINE__)
#define allocIDMem(size,id)MemOp.allocTID(size,id,__FILE__,__LINE__)
#define freeIDMem(p,id)MemOp.freeTID(p,id,__FILE__,__LINE__)


typedef struct OMem {

  /***** Object: Mem *****/
  /** Allocate memory and records sourcefile and line. (Use macro allocMem.) */
  void* (*alloc)( long size ,const char* file ,int line );
  /** Allocate memory and records sourcefile and line. (Use macro allocIDMem.) */
  void* (*allocTID)( long size ,int id ,const char* file ,int line );
  /** A special copy function for creating rocs-based objects. */
  void (*basecpy)( void* dst ,void* src ,int asize ,int tsize ,void* data );
  /** Find a char in memoryblock. */
  char* (*chr)( const void* buffer ,char c ,int size );
  /** Compairs two memory blocks. */
  Boolean (*cmp)( const void* dst ,const void* src ,int size );
  /** Copies a memory block. */
  void (*copy)( void* dst ,const void* src ,int size );
  /** Dumps allocation count by ID. */
  const long* (*dumpAllocCntID)( void );
  /** Print out all allocated strings. */
  void (*dumpStrings)( void );
  /** Free up memory and records sourcefile and line. (Use macro freeMem.) */
  void (*free)( void* p ,const char* file ,int line );
  /** Free up obj memory. */
  void (*freeObj)( void** p );
  /** Free up memory and records sourcefile and line. (Use macro freeIDMem.) */
  void (*freeTID)( void* p ,int id ,const char* file ,int line );
  /** Returns allocation count by ID. */
  long (*getAllocCntID)( int id );
  /** Returns number of allocated memory objects. */
  long (*getAllocCount)( void );
  /** Returns total allocated memory size. */
  long (*getAllocSize)( void );
  /**  */
  int (*getDumpSize)( void );
  /**  */
  const char* (*getLastOperation)( void );
  /**  */
  void (*init)( void );
  /** Re-Allocate memory and records sourcefile and line. (Use macro reallocMem.) */
  void* (*realloc)( void* p ,long size ,const char* file ,int line );
  /**  */
  void (*resetDump)( void );
  /** Initializes a memory block. */
  void (*set)( void* p ,int val ,int size );
  /** If set it prints for every allocation and free a line. */
  void (*setDebug)( Boolean debug );
} *iOMem;

extern struct OMem MemOp;

#ifdef __cplusplus
  }
#endif


#endif
