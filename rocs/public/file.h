/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_File_H
#define __object_File_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* rocs and system includes: */
#include <stdio.h>

#ifdef __cplusplus
  extern "C" {
#endif


typedef enum {OPEN_WRITE=0, OPEN_READONLY=1, OPEN_APPEND=2, OPEN_READWRITE=3, OPEN_RW=4, OPEN_RA=5, OPEN_R=6} openmode;



typedef struct OFile {
  /***** Base *****/
  struct OBase  base;

  /***** Object: File *****/
  const char* FUSER_RC;
  const char* FUSER_FILE;
  /** Test for read permission. */
  Boolean (*access)( const char* filename );
  /** Appends a buffer to the file. */
  Boolean (*append)( struct OFile* inst ,const char* buffer ,long size );
  /** Change the working directory. */
  Boolean (*cd)( const char* pathname );
  /** Closes the file. It does not cleanup this object. */
  Boolean (*close)( struct OFile* inst );
  /** Changes the separators according the OS. */
  void (*convertPath2OSType)( const char* pathname );
  /** Copies a file. */
  Boolean (*cp)( const char* src ,const char* dst );
  /** Checks for file or directory existence. */
  Boolean (*exist)( const char* name );
  /** Gets the filesize in bytes. */
  long (*fileSize)( const char* filename );
  /** Gets the modification time for the given file. */
  long (*fileTime)( const char* filename );
  /** Writes all buffered byte on disk. */
  Boolean (*flush)( struct OFile* inst );
  /** Writes a formatted string into the file. */
  Boolean (*fmt)( struct OFile* inst ,const char* fstr ,...  );
  /** Renames a file, target will be removed if the newname already exist. */
  Boolean (*forcerename)( const char* oldname ,const char* newname );
  /** Gets the filename used by this file object. */
  const char* (*getFilename)( struct OFile* inst );
  /** Returns a new allocated path string. */
  char* (*getPath)( const char* path );
  /** Get the latest error. */
  int (*getRc)( struct OFile* inst );
  /** Gets the count of the readed bytes. */
  long (*getReaded)( struct OFile* inst );
  /**  */
  FILE* (*getStream)( struct OFile* inst );
  /** Gets the count of the written bytes. */
  long (*getWritten)( struct OFile* inst );
  /** Gets the filepointer position. */
  long (*getpos)( struct OFile* inst );
  /** Object creator. */
  struct OFile* (*inst)( const char* path ,int openflag );
  /** Checks if given path is absolute. */
  Boolean (*isAbsolute)( const char* path );
  /** Checks with fuser if the file is accessed by another process. */
  Boolean (*isAccessed)( const char* filename );
  /** True if given name points to a directory. */
  Boolean (*isDirectory)( const char* filename );
  /** False if given name points not to a regular file. */
  Boolean (*isRegularFile)( const char* filename );
  /** Make directory. */
  Boolean (*mkdir)( const char* dirname );
  /** The process working directory. */
  char* (*pwd)( void );
  /** Reads from file; True if successful. */
  Boolean (*read)( struct OFile* inst ,char* buffer ,long size );
  /** Reads one line from file; True if successful. */
  Boolean (*readStr)( struct OFile* inst ,char* buffer );
  /** Removes the given file. */
  Boolean (*remove)( const char* filename );
  /** Renames a file. */
  Boolean (*rename)( const char* oldname ,const char* newname );
  /** Reopens this file. */
  Boolean (*reopen)( struct OFile* inst ,Boolean truncate );
  /** Sets the filepointer to the beginning of the file. */
  Boolean (*rewind)( struct OFile* inst );
  /** Returns a pointer to the filename. */
  const char* (*ripPath)( const char* filename );
  /** Removes given directory. */
  Boolean (*rmdir)( const char* path );
  /** Sets the filename to use with this object. */
  void (*setFilename)( struct OFile* inst ,const char* filename );
  /** Sets the fuser command to use for isAccessed. */
  void (*setFuser)( const char* filename );
  /** The Linux fuser returns a useable rc. With all other unixes we must use a temp file. */
  void (*setFuserUsage)( const char* usage );
  /** Sets the modification time for the given file. */
  Boolean (*setfileTime)( const char* filename ,long filetime );
  /** Sets the filepointer to the given offset. */
  Boolean (*setpos)( struct OFile* inst ,long offset );
  /** Get the filesize in bytes. */
  long (*size)( struct OFile* inst );
  /** Write to file; True if successful. */
  Boolean (*write)( struct OFile* inst ,const char* buffer ,long size );
  /** Appends a string to the file. */
  Boolean (*writeStr)( struct OFile* inst ,const char* str );
} *iOFile;

extern struct OFile FileOp;

#ifdef __cplusplus
  }
#endif


#endif
