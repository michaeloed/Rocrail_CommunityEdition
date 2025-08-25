/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_System_H
#define __object_System_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef enum {OSTYPE_UNIX, OSTYPE_DOS} ostype;



typedef struct OSystem {
  /***** Base *****/
  struct OBase  base;

  /***** Object: System *****/
  int vmajor;
  int vminor;
  int patch;
  const char* builddate;
  const char* buildtime;
  /** check device access */
  Boolean (*accessDev)( const char* device ,Boolean readonly );
  /** try to get port access */
  Boolean (*accessPort)( int from ,int num );
  /** available from device */
  int (*availDevice)( long handle );
  /** Beeps. */
  void (*beep)( void );
  /** Translates Windows CP1252 into Latin 15. */
  char* (*cp1252toISO885915)( const char* str );
  /**  */
  char* (*decode)( const byte* b ,int len ,const char* k );
  /** Get the Rocs build string. */
  const char* (*getBuild)( void );
  /** Translates an error code into a string. */
  const char* (*getErrStr)( int error );
  /**  */
  const char* (*getEyecatcher)( void );
  /**  */
  char (*getFileSeparator)( void );
  /** Get global unique ID. (32 chars long) */
  char* (*getGUID)( const char* macdev );
  /**  */
  int (*getMillis)( void );
  /**  */
  ostype (*getOSType)( void );
  /**  */
  char (*getPathSeparator)( void );
  /** Path separator for a specific OS type. */
  char (*getPathSeparator4OS)( ostype type );
  /**  */
  const char* (*getPrgExt)( void );
  /** Reads an environment variable. */
  const char* (*getProperty)( const char* key );
  /** Translates an signal number into a string. */
  const char* (*getSigStr)( int sig );
  /** System tick in 10ms. */
  unsigned long (*getTick)( void );
  /** returns milliseconds */
  int (*getTime)( int* hours ,int* minutes ,int* seconds );
  /** Translates a local path into a UNC. */
  char* (*getUNC)( const char* filepath );
  /**  */
  const char* (*getUnlimEyecatcher)( void );
  /** Login username. */
  const char* (*getUserName)( void );
  /** Workstation name. */
  const char* (*getWSName)( void );
  /** Process ID. */
  int (*getpid)( void );
  /** Object creator. (Singleton) */
  struct OSystem* (*inst)( void );
  /**  */
  Boolean (*isExpired)( const char* s ,char** expdate ,long* expdays ,int vmajor ,int vminor );
  /**  */
  Boolean (*isUnix)( void );
  /**  */
  Boolean (*isWindows)( void );
  /** Translates Latin 15 into CP850. */
  char* (*latin2cp850)( const char* latinstr );
  /** Translates Latin 15 into UTF-8. */
  char* (*latin2utf)( const char* latinstr );
  /** open device access */
  long (*openDevice)( const char* device );
  /** read from device */
  Boolean (*readDevice)( long handle ,char* buffer ,int size );
  /** read a byte to the port */
  byte (*readPort)( int port );
  /** release the port access */
  Boolean (*releasePort)( int from ,int num );
  /**  */
  Boolean (*setAdmin)( void );
  /** Starts a system command. */
  int (*system)( const char* cmd ,Boolean async ,Boolean minimized );
  /**  */
  Boolean (*uBusyWait)( int us );
  /**  */
  Boolean (*usWait)( int us );
  /** Translates fitting UTF-8 encodings into Lantin 15. */
  char* (*utf2latin)( const char* utfstr );
  /** read from device */
  Boolean (*writeDevice)( long handle ,char* buffer ,int size );
  /** write a byte to the port */
  void (*writePort)( int port ,byte val );
} *iOSystem;

extern struct OSystem SystemOp;

#ifdef __cplusplus
  }
#endif


#endif
