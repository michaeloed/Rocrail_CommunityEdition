/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#ifndef __WRAPPER_PowerCtrl_H
#define __WRAPPER_PowerCtrl_H

#include "rocview/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wPowerCtrl {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getcx)(iONode);
  void (*setcx)(iONode,int);
  int (*getcy)(iONode);
  void (*setcy)(iONode,int);
  Boolean (*isshow)(iONode);
  void (*setshow)(iONode,Boolean);
  int (*getx)(iONode);
  void (*setx)(iONode,int);
  int (*gety)(iONode);
  void (*sety)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wPowerCtrl wPowerCtrl;

#ifdef __cplusplus
  }
#endif


#endif
