/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_MVTrack_H
#define __object_MVTrack_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OMVTrack {
  /***** Base *****/
  struct OBase  base;

  /***** Object: MVTrack *****/
  /**  */
  struct OMVTrack* (*inst)( iONode props );
  /**  */
  void (*modify)( struct OMVTrack* inst ,iONode modification );
  /**  */
  void (*reset)( struct OMVTrack* inst );
} *iOMVTrack;

extern struct OMVTrack MVTrackOp;

#ifdef __cplusplus
  }
#endif


#endif
