/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_PClient_H
#define __object_PClient_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/list.h"
#include "rocs/public/thread.h"
#include "rocs/public/socket.h"
#include "rocs/public/file.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OPClient {
  /***** Base *****/
  struct OBase  base;

  /***** Object: PClient *****/
  /** PClient ID. */
  const char* (*getId)( struct OPClient* inst );
  /** Object creator. */
  struct OPClient* (*inst)( iOSocket socket ,iONode ini );
  /** PClient ID. */
  void (*shutdown)( struct OPClient* inst );
  /** Work slice. */
  Boolean (*work)( struct OPClient* inst ,iONode event ,char** cmd );
} *iOPClient;

extern struct OPClient PClientOp;

#ifdef __cplusplus
  }
#endif


#endif
