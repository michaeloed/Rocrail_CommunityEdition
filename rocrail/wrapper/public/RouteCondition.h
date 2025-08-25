/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_RouteCondition_H
#define __WRAPPER_RouteCondition_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wRouteCondition {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isallowschedules)(iONode);
  void (*setallowschedules)(iONode,Boolean);
  Boolean (*ischdir)(iONode);
  void (*setchdir)(iONode,Boolean);
  Boolean (*iscommuter)(iONode);
  void (*setcommuter)(iONode,Boolean);
  Boolean (*isnotprevbk)(iONode);
  void (*setnotprevbk)(iONode,Boolean);
  const char* (*getprevbkid)(iONode);
  void (*setprevbkid)(iONode,const char*);
  const char* (*gettype)(iONode);
  void (*settype)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wRouteCondition wRouteCondition;

#ifdef __cplusplus
  }
#endif


#endif
