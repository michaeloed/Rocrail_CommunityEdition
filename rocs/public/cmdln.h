/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_CmdLn_H
#define __object_CmdLn_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/map.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OCmdLn {
  /***** Base *****/
  struct OBase  base;

  /***** Object: CmdLn *****/
  /** Get an integer value by key. Returns given default value if not found. */
  int (*getIntDef)( struct OCmdLn* inst ,const char* key ,int defval );
  /** Get a string value by key. */
  const char* (*getStr)( struct OCmdLn* inst ,const char* key );
  /** Get a string value by key. Returns given default value if not found. */
  const char* (*getStrDef)( struct OCmdLn* inst ,const char* key ,const char* defval );
  /** Test if the given key was on the commandline. */
  Boolean (*hasKey)( struct OCmdLn* inst ,const char* key );
  /** Creates a commandline object. */
  struct OCmdLn* (*inst)( int argc ,const char** argv );
} *iOCmdLn;

extern struct OCmdLn CmdLnOp;

#ifdef __cplusplus
  }
#endif


#endif
