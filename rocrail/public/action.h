/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Action_H
#define __object_Action_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/thread.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OAction {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Action *****/
  /**  */
  Boolean (*cmd)( struct OAction* inst ,iONode cmd );
  /**  */
  void (*exec)( struct OAction* inst ,iONode ctrl );
  /**  */
  struct OAction* (*inst)( iONode ini );
  /**  */
  void (*modify)( struct OAction* inst ,iONode modification );
  /**  */
  void (*tick)( struct OAction* inst ,int seconds );
} *iOAction;

extern struct OAction ActionOp;

#ifdef __cplusplus
  }
#endif


#endif
