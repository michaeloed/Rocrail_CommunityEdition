/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_StrTok_H
#define __object_StrTok_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/str.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OStrTok {
  /***** Base *****/
  struct OBase  base;

  /***** Object: StrTok *****/
  /** Get number of tokens. */
  int (*countTokens)( struct OStrTok* inst );
  /** There are more tokens left to read. */
  Boolean (*hasMoreTokens)( struct OStrTok* inst );
  /** Object creator. */
  struct OStrTok* (*inst)( const char* str ,char sep );
  /** A token. */
  const char* (*nextToken)( struct OStrTok* inst );
  /**  */
  char* (*replaceAll)( const char* str ,char sep ,const char* oldTok ,const char* newTok );
} *iOStrTok;

extern struct OStrTok StrTokOp;

#ifdef __cplusplus
  }
#endif


#endif
