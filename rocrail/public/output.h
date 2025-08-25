/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Output_H
#define __object_Output_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/list.h"

/* RocRail and system includes: */
#include "rocrail/public/htmlint.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OOutput {
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

  /***** Object: Output *****/
  /**  */
  Boolean (*addListener)( struct OOutput* inst ,obj listener );
  /**  */
  Boolean (*cmd)( struct OOutput* inst ,iONode cmd ,Boolean update );
  /**  */
  char* (*createAddrKey)( int bus ,int addr ,int port ,int type ,const char* iid );
  /**  */
  void (*event)( struct OOutput* inst ,iONode evt );
  /**  */
  const char* (*getAddrKey)( struct OOutput* inst );
  /**  */
  const char* (*getId)( struct OOutput* inst );
  /**  */
  struct OOutput* (*inst)( iONode ini );
  /**  */
  Boolean (*isState)( struct OOutput* inst ,const char* state );
  /**  */
  void (*modify)( struct OOutput* inst ,iONode mod );
  /**  */
  void (*off)( struct OOutput* inst );
  /**  */
  void (*on)( struct OOutput* inst );
  /**  */
  Boolean (*removeListener)( struct OOutput* inst ,obj listener );
} *iOOutput;

extern struct OOutput OutputOp;

#ifdef __cplusplus
  }
#endif


#endif
