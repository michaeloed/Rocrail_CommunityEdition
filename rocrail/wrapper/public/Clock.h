/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Clock_H
#define __WRAPPER_Clock_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wClock {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* freeze;
  const char* go;
  const char* set;
  const char* sync;
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  int (*getdivider)(iONode);
  void (*setdivider)(iONode,int);
  int (*gethour)(iONode);
  void (*sethour)(iONode,int);
  int (*getminute)(iONode);
  void (*setminute)(iONode,int);
  Boolean (*isstopclockatpoweroff)(iONode);
  void (*setstopclockatpoweroff)(iONode,Boolean);
  int (*gettemp)(iONode);
  void (*settemp)(iONode,int);
  long (*gettime)(iONode);
  void (*settime)(iONode,long);
  int (*getupdate)(iONode);
  void (*setupdate)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wClock wClock;

#ifdef __cplusplus
  }
#endif


#endif
