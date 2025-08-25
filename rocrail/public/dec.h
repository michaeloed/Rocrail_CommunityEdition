/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Dec_H
#define __object_Dec_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/map.h"

/* RocRail and system includes: */
#include "rocrail/public/htmlint.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct ODec {
  /***** Base *****/
  struct OBase  base;

  /***** Interface: HtmlInt *****/
  /**  */
  char* (*getForm)( void* object );
  /**  */
  char* (*postForm)( void* object ,const char* data );
  /**  */
  const char* (*tableHdr)( void );
  /**  */
  char* (*toHtml)( void* object );

  /***** Object: Dec *****/
  /**  */
  int (*getCV)( iONode props ,int nr );
  /**  */
  void (*setCV)( iONode props ,int nr ,int value );
} *iODec;

extern struct ODec DecOp;

#ifdef __cplusplus
  }
#endif


#endif
