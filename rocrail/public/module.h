/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Module_H
#define __object_Module_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OModule {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Module *****/
  /**  */
  void (*getRotationArea)( iONode module ,int* Xmax ,int* Ymax );
  /**  */
  struct OModule* (*inst)( iONode ini );
  /**  */
  void (*rotate180)( iONode item ,int cx ,int cy );
  /**  */
  void (*rotate270)( iONode item ,int cx ,int cy );
  /**  */
  void (*rotate90)( iONode item ,int cx ,int cy );
  /**  */
  void (*rotateModule)( iONode model ,iONode module ,int level ,int rotation );
} *iOModule;

extern struct OModule ModuleOp;

#ifdef __cplusplus
  }
#endif


#endif
