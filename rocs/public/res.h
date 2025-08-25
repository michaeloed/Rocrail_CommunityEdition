/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Res_H
#define __object_Res_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/map.h"
#include "rocs/public/node.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct ORes {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Res *****/
  /** Add translation. Existing IDs are overwritten. */
  void (*addTranslation)( struct ORes* inst ,const char* xml );
  /** Get a message by key. */
  const char* (*getMenu)( struct ORes* inst ,const char* key ,Boolean useAccel );
  /** Get a message by key. */
  const char* (*getMsg)( struct ORes* inst ,const char* key );
  /** Get a tooltip by key. */
  const char* (*getTip)( struct ORes* inst ,const char* key );
  /** Test if the given key is in the XML. */
  Boolean (*hasKey)( struct ORes* inst ,const char* key );
  /** Creates a resource object. */
  struct ORes* (*inst)( const char* xml ,const char* lang );
} *iORes;

extern struct ORes ResOp;

#ifdef __cplusplus
  }
#endif


#endif
