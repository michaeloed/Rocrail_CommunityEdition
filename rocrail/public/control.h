/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Control_H
#define __object_Control_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/map.h"
#include "rocs/public/thread.h"

/* RocRail and system includes: */
#include "rocrail/public/r2rnet.h"
#include "rocrail/public/clntcon.h"
#include "rocrail/public/powerman.h"
#include "rocint/public/digint.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef enum {CMD_OK=0,CMD_RETRY,CMD_ERROR} cmd_state;
typedef void(*control_callback)(obj,iONode);



typedef struct OControl {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Control *****/
  /**  */
  Boolean (*cmd)( struct OControl* inst ,iONode cmd ,int* error );
  /** The applications entry point */
  control_callback (*getCallback)( struct OControl* inst );
  /**  */
  const char* (*getIid)( struct OControl* inst );
  /**  */
  iOR2Rnet (*getR2Rnet)( struct OControl* inst );
  /**  */
  iONode (*getState)( struct OControl* inst );
  /**  */
  long (*getTime)( struct OControl* inst );
  /**  */
  void (*halt)( struct OControl* inst );
  /**  */
  Boolean (*hasBlockPower)( struct OControl* inst ,const char* blockid );
  /**  */
  struct OControl* (*inst)( Boolean nocom );
  /**  */
  Boolean (*power4Block)( struct OControl* inst ,const char* blockid ,Boolean power );
  /**  */
  void (*setBoosters)( struct OControl* inst ,iONode boosterlist );
} *iOControl;

extern struct OControl ControlOp;

#ifdef __cplusplus
  }
#endif


#endif
