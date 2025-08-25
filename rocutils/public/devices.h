/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: rocutils
  * XML: 
  * XML: 
  * Date: Fri Aug  3 14:01:51 2018
  */

#ifndef __object_Devices_H
#define __object_Devices_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/list.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct ODevices {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Devices *****/
  /**  */
  void (*freeList)( iOList list );
  /**  */
  iOList (*getDevices)( void );
  /**  */
  char* (*getDevicesStr)( void );
} *iODevices;

extern struct ODevices DevicesOp;

#ifdef __cplusplus
  }
#endif


#endif
