/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_WeatherTheme_H
#define __WRAPPER_WeatherTheme_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wWeatherTheme {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getdim)(iONode);
  void (*setdim)(iONode,int);
  int (*getduration)(iONode);
  void (*setduration)(iONode,int);
  int (*gethour)(iONode);
  void (*sethour)(iONode,int);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  int (*getminute)(iONode);
  void (*setminute)(iONode,int);
  const char* (*getoutputs)(iONode);
  void (*setoutputs)(iONode,const char*);
  Boolean (*israndom)(iONode);
  void (*setrandom)(iONode,Boolean);
  const char* (*getsound)(iONode);
  void (*setsound)(iONode,const char*);
  const char* (*getsoundoutput)(iONode);
  void (*setsoundoutput)(iONode,const char*);
  int (*getsoundrandomrate)(iONode);
  void (*setsoundrandomrate)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wWeatherTheme wWeatherTheme;

#ifdef __cplusplus
  }
#endif


#endif
