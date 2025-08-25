/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_JSon_H
#define __object_JSon_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OJSon {
  /***** Base *****/
  struct OBase  base;

  /***** Object: JSon *****/
  /** Convert XML to a JSon string. */
  char* (*toJSon)( iONode xml );
  /** Convert a JSon string to XML. */
  iONode (*toXML)( const char* json );
} *iOJSon;

extern struct OJSon JSonOp;

#ifdef __cplusplus
  }
#endif


#endif
