/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: rocutils
  * XML: 
  * XML: 
  * Date: Fri Aug  3 14:01:51 2018
  */

#ifndef __object_CRC_H
#define __object_CRC_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/list.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OCRC {
  /***** Base *****/
  struct OBase  base;

  /***** Object: CRC *****/
  /**  */
  int (*checkSum16)( byte* packet ,int len );
} *iOCRC;

extern struct OCRC CRCOp;

#ifdef __cplusplus
  }
#endif


#endif
