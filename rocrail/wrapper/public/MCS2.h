/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_MCS2_H
#define __WRAPPER_MCS2_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wMCS2 {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isbind)(iONode);
  void (*setbind)(iONode,Boolean);
  int (*getcmdpause)(iONode);
  void (*setcmdpause)(iONode,int);
  Boolean (*isdiscovery)(iONode);
  void (*setdiscovery)(iONode,Boolean);
  int (*getfbdevid)(iONode);
  void (*setfbdevid)(iONode,int);
  int (*getsensorbegin)(iONode);
  void (*setsensorbegin)(iONode,int);
  int (*getsensorend)(iONode);
  void (*setsensorend)(iONode,int);
  iONode (*getproduct)(iONode);
  iONode (*nextproduct)(iONode,iONode);
  void (*setproduct)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wMCS2 wMCS2;

#ifdef __cplusplus
  }
#endif


#endif
