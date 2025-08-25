/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_WeatherColor_H
#define __WRAPPER_WeatherColor_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wWeatherColor {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getblue)(iONode);
  void (*setblue)(iONode,int);
  int (*getbri)(iONode);
  void (*setbri)(iONode,int);
  int (*getgreen)(iONode);
  void (*setgreen)(iONode,int);
  int (*gethour)(iONode);
  void (*sethour)(iONode,int);
  int (*getminute)(iONode);
  void (*setminute)(iONode,int);
  int (*getred)(iONode);
  void (*setred)(iONode,int);
  int (*getsat)(iONode);
  void (*setsat)(iONode,int);
  int (*getwhite)(iONode);
  void (*setwhite)(iONode,int);
  int (*getwhite2)(iONode);
  void (*setwhite2)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wWeatherColor wWeatherColor;

#ifdef __cplusplus
  }
#endif


#endif
