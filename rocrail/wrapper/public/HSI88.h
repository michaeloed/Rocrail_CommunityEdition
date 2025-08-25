/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_HSI88_H
#define __WRAPPER_HSI88_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wHSI88 {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getfbleft)(iONode);
  void (*setfbleft)(iONode,int);
  int (*getfbmiddle)(iONode);
  void (*setfbmiddle)(iONode,int);
  int (*getfbright)(iONode);
  void (*setfbright)(iONode,int);
  Boolean (*issmooth)(iONode);
  void (*setsmooth)(iONode,Boolean);
  int (*gettriggertime)(iONode);
  void (*settriggertime)(iONode,int);
  Boolean (*isusb)(iONode);
  void (*setusb)(iONode,Boolean);
  Boolean (*dump)(iONode node);
};

extern struct __wHSI88 wHSI88;

#ifdef __cplusplus
  }
#endif


#endif
