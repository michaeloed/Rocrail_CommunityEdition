/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Track_H
#define __object_Track_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OTrack {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Track *****/
  /**  */
  const char* (*getId)( struct OTrack* inst );
  /**  */
  struct OTrack* (*inst)( iONode ini );
  /**  */
  void (*modify)( struct OTrack* inst ,iONode mod );
} *iOTrack;

extern struct OTrack TrackOp;

#ifdef __cplusplus
  }
#endif


#endif
