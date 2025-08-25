/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_BoosterEvent_H
#define __WRAPPER_BoosterEvent_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wBoosterEvent {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getload)(iONode);
  void (*setload)(iONode,int);
  int (*gettemp)(iONode);
  void (*settemp)(iONode,int);
  long (*gettimestamp)(iONode);
  void (*settimestamp)(iONode,long);
  int (*getvolt)(iONode);
  void (*setvolt)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wBoosterEvent wBoosterEvent;

#ifdef __cplusplus
  }
#endif


#endif
