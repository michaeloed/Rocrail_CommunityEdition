/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  2 2018 14:02:35)
  * Module: rocs
  * XML: $Source: /home/cvs/xspooler/rocs/rocs.xml,v $
  * XML: $Revision: 1.85 $
  * Date: Thu Aug  2 14:02:39 2018
  */

#ifndef __object_Msg_H
#define __object_Msg_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef enum {VOID_DATA, OBJ_DATA, STR_DATA } usrdatatype;



typedef struct OMsg {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Msg *****/
  /**  */
  int (*getEvent)( struct OMsg* inst );
  /**  */
  obj (*getSender)( struct OMsg* inst );
  /**  */
  int (*getTimer)( struct OMsg* inst );
  /**  */
  void* (*getUsrData)( struct OMsg* inst );
  /**  */
  usrdatatype (*getUsrDataType)( struct OMsg* inst );
  /** Object creator. */
  struct OMsg* (*inst)( obj sender ,int event );
  /**  */
  void (*setEvent)( struct OMsg* inst ,int event );
  /**  */
  void (*setTimer)( struct OMsg* inst ,int timer );
  /**  */
  void (*setUsrData)( struct OMsg* inst ,void* usrdata ,usrdatatype type );
} *iOMsg;

extern struct OMsg MsgOp;

#ifdef __cplusplus
  }
#endif


#endif
