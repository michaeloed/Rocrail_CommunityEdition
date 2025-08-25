/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:52 2018
  */

#ifndef __WRAPPER_RRCon_H
#define __WRAPPER_RRCon_H

#include "rocview/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wRRCon {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getcontrolcode)(iONode);
  void (*setcontrolcode)(iONode,const char*);
  const char* (*gethost)(iONode);
  void (*sethost)(iONode,const char*);
  int (*getport)(iONode);
  void (*setport)(iONode,int);
  int (*getretry)(iONode);
  void (*setretry)(iONode,int);
  int (*getretryinterval)(iONode);
  void (*setretryinterval)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wRRCon wRRCon;

#ifdef __cplusplus
  }
#endif


#endif
