/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#include "rocs/public/mem.h"


static const char* name = "OMem";

typedef enum {MEMTYPE_ALLOC=0,MEMTYPE_REALLOC,MEMTYPE_CHECK,MEMTYPE_FREE} memOpType;
/*  */
#define __magic "#@librocs@#\0"
/*  */
#define MAGIC_SIZE 12

/** Memory allocation record. */
typedef struct __OMemAlloc {
    /** Eyecacher. */
  char magic[MAGIC_SIZE];
    /** Size of the allocated memory block. */
  long size;
    /**  */
  RocsMemID id;
} *__iOMemAlloc;

/** Memory trace record. */
typedef struct __OMemTrace {
    /** Operation type. */
  memOpType type;
    /** Object. */
  void* p;
    /** Object size. */
  long size;
    /** Sourcecode filename. */
  const char* file;
    /** Sourcecode line number. */
  int line;
} *__iOMemTrace;
