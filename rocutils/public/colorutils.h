/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: rocutils
  * XML: 
  * XML: 
  * Date: Fri Aug  3 14:01:51 2018
  */

#ifndef __object_ColorUtils_H
#define __object_ColorUtils_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/list.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OColorUtils {
  /***** Base *****/
  struct OBase  base;

  /***** Object: ColorUtils *****/
  /**  */
  void (*HSVtoRGB)( double h ,double s ,double v ,int* r ,int* g ,int* b );
  /**  */
  void (*RGBtoHSV)( int r ,int g ,int b ,double* h ,double* s ,double* v );
  /**  */
  void (*RGBtoXY)( int r ,int g ,int b ,float* x ,float* y );
} *iOColorUtils;

extern struct OColorUtils ColorUtilsOp;

#ifdef __cplusplus
  }
#endif


#endif
