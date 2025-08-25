/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_WrpInf_H
#define __object_WrpInf_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/map.h"
#include "rocs/public/node.h"
#include "rocs/public/list.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OWrpInf {
  /***** Base *****/
  struct OBase  base;

  /***** Object: WrpInf *****/
  /** Get all var nodes. */
  iOList (*getVars)( iONode wrp );
  /** Get a wrapper by key. */
  iONode (*getWrapper)( struct OWrpInf* inst ,const char* wrpname );
  /** Creates a resource object. */
  struct OWrpInf* (*inst)( const char** xmls ,int cnt );
} *iOWrpInf;

extern struct OWrpInf WrpInfOp;

#ifdef __cplusplus
  }
#endif


#endif
