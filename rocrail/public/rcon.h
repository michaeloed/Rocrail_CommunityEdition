/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_RCon_H
#define __object_RCon_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/thread.h"
#include "rocs/public/socket.h"

#ifdef __cplusplus
  extern "C" {
#endif


typedef void (*rcon_callback)(obj, iONode);



typedef struct ORCon {
  /***** Base *****/
  struct OBase  base;

  /***** Object: RCon *****/
  /**  */
  void (*close)( struct ORCon* inst );
  /**  */
  struct ORCon* (*inst)( const char* host ,int port );
  /**  */
  void (*setCallback)( struct ORCon* inst ,rcon_callback listenerfun ,obj cargo );
  /**  */
  Boolean (*write)( struct ORCon* inst ,char* cmd );
} *iORCon;

extern struct ORCon RConOp;

#ifdef __cplusplus
  }
#endif


#endif
