/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_HClient_H
#define __object_HClient_H

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





typedef struct OHClient {
  /***** Base *****/
  struct OBase  base;

  /***** Object: HClient *****/
  /** HClient ID. */
  const char* (*getId)( struct OHClient* inst );
  /** Object creator. */
  struct OHClient* (*inst)( iOSocket socket ,const char* path ,int refresh );
  /** Work slice. */
  Boolean (*work)( struct OHClient* inst );
} *iOHClient;

extern struct OHClient HClientOp;

#ifdef __cplusplus
  }
#endif


#endif
