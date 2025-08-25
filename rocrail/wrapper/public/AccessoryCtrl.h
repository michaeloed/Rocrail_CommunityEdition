/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_AccessoryCtrl_H
#define __WRAPPER_AccessoryCtrl_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wAccessoryCtrl {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isactive)(iONode);
  void (*setactive)(iONode,Boolean);
  int (*getdelay)(iONode);
  void (*setdelay)(iONode,int);
  const char* (*getfreeblocks)(iONode);
  void (*setfreeblocks)(iONode,const char*);
  int (*getinterval)(iONode);
  void (*setinterval)(iONode,int);
  const char* (*getlockroutes)(iONode);
  void (*setlockroutes)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wAccessoryCtrl wAccessoryCtrl;

#ifdef __cplusplus
  }
#endif


#endif
