/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Weather_H
#define __WRAPPER_Weather_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wWeather {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getcolorsliding)(iONode);
  void (*setcolorsliding)(iONode,int);
  Boolean (*iscolortable)(iONode);
  void (*setcolortable)(iONode,Boolean);
  const char* (*getdeactivate)(iONode);
  void (*setdeactivate)(iONode,const char*);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  int (*getmaxbri)(iONode);
  void (*setmaxbri)(iONode,int);
  int (*getminbri)(iONode);
  void (*setminbri)(iONode,int);
  int (*getnightsliding)(iONode);
  void (*setnightsliding)(iONode,int);
  Boolean (*isoffatshutdown)(iONode);
  void (*setoffatshutdown)(iONode,Boolean);
  const char* (*getoutputs)(iONode);
  void (*setoutputs)(iONode,const char*);
  Boolean (*isrelativetime)(iONode);
  void (*setrelativetime)(iONode,Boolean);
  Boolean (*isslidingdaylight)(iONode);
  void (*setslidingdaylight)(iONode,Boolean);
  Boolean (*isusebri)(iONode);
  void (*setusebri)(iONode,Boolean);
  Boolean (*isusesat)(iONode);
  void (*setusesat)(iONode,Boolean);
  Boolean (*isusewhite)(iONode);
  void (*setusewhite)(iONode,Boolean);
  Boolean (*isusewhite2)(iONode);
  void (*setusewhite2)(iONode,Boolean);
  iONode (*getsunrise)(iONode);
  iONode (*nextsunrise)(iONode,iONode);
  void (*setsunrise)(iONode,iONode);
  iONode (*getnoon)(iONode);
  iONode (*nextnoon)(iONode,iONode);
  void (*setnoon)(iONode,iONode);
  iONode (*getsunset)(iONode);
  iONode (*nextsunset)(iONode,iONode);
  void (*setsunset)(iONode,iONode);
  iONode (*getnight)(iONode);
  iONode (*nextnight)(iONode,iONode);
  void (*setnight)(iONode,iONode);
  iONode (*getweathercolor)(iONode);
  iONode (*nextweathercolor)(iONode,iONode);
  void (*setweathercolor)(iONode,iONode);
  iONode (*getweathertheme)(iONode);
  iONode (*nextweathertheme)(iONode,iONode);
  void (*setweathertheme)(iONode,iONode);
  iONode (*getactionctrl)(iONode);
  iONode (*nextactionctrl)(iONode,iONode);
  void (*setactionctrl)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wWeather wWeather;

#ifdef __cplusplus
  }
#endif


#endif
