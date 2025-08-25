/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_SpeedCondition_H
#define __WRAPPER_SpeedCondition_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wSpeedCondition {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getclass)(iONode);
  void (*setclass)(iONode,const char*);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  int (*getpercent)(iONode);
  void (*setpercent)(iONode,int);
  const char* (*gettype)(iONode);
  void (*settype)(iONode,const char*);
  const char* (*getvalue)(iONode);
  void (*setvalue)(iONode,const char*);
  const char* (*getvariable)(iONode);
  void (*setvariable)(iONode,const char*);
  const char* (*getvarsub)(iONode);
  void (*setvarsub)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wSpeedCondition wSpeedCondition;

#ifdef __cplusplus
  }
#endif


#endif
