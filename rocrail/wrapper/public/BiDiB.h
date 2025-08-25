/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_BiDiB_H
#define __WRAPPER_BiDiB_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wBiDiB {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*ismanual2bidib)(iONode);
  void (*setmanual2bidib)(iONode,Boolean);
  Boolean (*issecAck)(iONode);
  void (*setsecAck)(iONode,Boolean);
  int (*getsecAckInt)(iONode);
  void (*setsecAckInt)(iONode,int);
  Boolean (*iswatchdog)(iONode);
  void (*setwatchdog)(iONode,Boolean);
  int (*getwatchdogInt)(iONode);
  void (*setwatchdogInt)(iONode,int);
  iONode (*getbidibnode)(iONode);
  iONode (*nextbidibnode)(iONode,iONode);
  void (*setbidibnode)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wBiDiB wBiDiB;

#ifdef __cplusplus
  }
#endif


#endif
