/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_ScheduleEntry_H
#define __WRAPPER_ScheduleEntry_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wScheduleEntry {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getblock)(iONode);
  void (*setblock)(iONode,const char*);
  Boolean (*isfree2go)(iONode);
  void (*setfree2go)(iONode,Boolean);
  int (*gethour)(iONode);
  void (*sethour)(iONode,int);
  int (*getindelay)(iONode);
  void (*setindelay)(iONode,int);
  const char* (*getlocation)(iONode);
  void (*setlocation)(iONode,const char*);
  int (*getminute)(iONode);
  void (*setminute)(iONode,int);
  Boolean (*isswap)(iONode);
  void (*setswap)(iONode,Boolean);
  iONode (*getactionctrl)(iONode);
  iONode (*nextactionctrl)(iONode,iONode);
  void (*setactionctrl)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wScheduleEntry wScheduleEntry;

#ifdef __cplusplus
  }
#endif


#endif
