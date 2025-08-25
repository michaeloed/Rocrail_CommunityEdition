/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_Schedule_H
#define __WRAPPER_Schedule_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wSchedule {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int time_hourly;
  int time_real;
  int time_relative;
  const char* type_commuter;
  const char* type_cycle;
  int (*getcycles)(iONode);
  void (*setcycles)(iONode,int);
  int (*getfromhour)(iONode);
  void (*setfromhour)(iONode,int);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  int (*getmaxdelay)(iONode);
  void (*setmaxdelay)(iONode,int);
  const char* (*getscaction)(iONode);
  void (*setscaction)(iONode,const char*);
  int (*gettimeframe)(iONode);
  void (*settimeframe)(iONode,int);
  int (*gettimeprocessing)(iONode);
  void (*settimeprocessing)(iONode,int);
  int (*gettohour)(iONode);
  void (*settohour)(iONode,int);
  const char* (*gettype)(iONode);
  void (*settype)(iONode,const char*);
  iONode (*getscentry)(iONode);
  iONode (*nextscentry)(iONode,iONode);
  void (*setscentry)(iONode,iONode);
  iONode (*getactionctrl)(iONode);
  iONode (*nextactionctrl)(iONode,iONode);
  void (*setactionctrl)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wSchedule wSchedule;

#ifdef __cplusplus
  }
#endif


#endif
