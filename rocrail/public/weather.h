/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs ogen (build Aug  3 2018 14:01:50)
  * Module: RocRail
  * XML: $Source: /cvsroot/rojav/rocrail/rocrail.xml,v $
  * XML: $Revision: 1.56 $
  * Date: Fri Aug  3 14:03:35 2018
  */

#ifndef __object_Weather_H
#define __object_Weather_H

#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"

/* Rocs includes: */
#include "rocs/public/node.h"
#include "rocs/public/map.h"
#include "rocs/public/list.h"
#include "rocs/public/mutex.h"
#include "rocs/public/thread.h"

#ifdef __cplusplus
  extern "C" {
#endif





typedef struct OWeather {
  /***** Base *****/
  struct OBase  base;

  /***** Object: Weather *****/
  /**  */
  void (*halt)( struct OWeather* inst );
  /**  */
  struct OWeather* (*inst)( iONode ini );
  /**  */
  Boolean (*isWeather)( struct OWeather* inst ,const char* id );
  /**  */
  void (*setTheme)( struct OWeather* inst ,const char* id );
  /**  */
  void (*setWeather)( struct OWeather* inst ,const char* id ,const char* param );
} *iOWeather;

extern struct OWeather WeatherOp;

#ifdef __cplusplus
  }
#endif


#endif
