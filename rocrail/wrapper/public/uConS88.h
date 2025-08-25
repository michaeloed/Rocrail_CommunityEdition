/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_uConS88_H
#define __WRAPPER_uConS88_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wuConS88 {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getfbB1)(iONode);
  void (*setfbB1)(iONode,int);
  int (*getfbB2)(iONode);
  void (*setfbB2)(iONode,int);
  int (*getfbB3)(iONode);
  void (*setfbB3)(iONode,int);
  const char* (*gethost)(iONode);
  void (*sethost)(iONode,const char*);
  int (*getport)(iONode);
  void (*setport)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wuConS88 wuConS88;

#ifdef __cplusplus
  }
#endif


#endif
