/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Dir_H
#define __object_Dir_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/list.h"

/* rocs and system includes: */
#include <time.h>

#ifdef __cplusplus
  extern "C" {
#endif


typedef enum {SORT_NAME=0, SORT_OLDEST=1, SORT_NEWEST=2} sortmode;



/** Container for a direntry. */
typedef struct DirEntry {
    /**  */
  time_t mtime;
    /**  */
  char* name;
} *iDirEntry;

typedef struct ODir {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Dir *****/
  /** free all memory allocated by listdir() */
  void (*cleandirlist)( iOList list );
  /** Closes the direntry. */
  void (*close)( struct ODir* inst );
  /** Get the last error. */
  int (*getRc)( struct ODir* inst );
  /** Creates a directory object. */
  struct ODir* (*inst)( const char* path );
  /** Scans the directory for entries with given ending. */
  iOList (*listdir)( const char* path ,const char* ext ,sortmode sort );
  /** Opens the directory for reading. */
  Boolean (*open)( struct ODir* inst );
  /** Reads an direntry. */
  const char* (*read)( struct ODir* inst );
  /** Scans the directory for entries with given ending. */
  int (*scandir)( const char* path ,const char* ext );
} *iODir;

extern struct ODir DirOp;

#ifdef __cplusplus
  }
#endif


#endif
