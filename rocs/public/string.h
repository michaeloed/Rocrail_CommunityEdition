/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_String_H
#define __object_String_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/str.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OString {
  /***** Base *****/
  struct OBase  base;

  /***** Object: String *****/
  /** Object creator. */
  struct OString* (*inst)( const char* str );
  /** String length. */
  int (*len)( struct OString* inst );
  /** String value. */
  const char* (*str)( struct OString* inst );
} *iOString;

extern struct OString StringOp;

#ifdef __cplusplus
  }
#endif


#endif
