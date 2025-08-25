/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_HttpService_H
#define __WRAPPER_HttpService_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wHttpService {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isenable)(iONode);
  void (*setenable)(iONode,Boolean);
  const char* (*getpath)(iONode);
  void (*setpath)(iONode,const char*);
  int (*getport)(iONode);
  void (*setport)(iONode,int);
  int (*getrefresh)(iONode);
  void (*setrefresh)(iONode,int);
  iONode (*getwebclient)(iONode);
  iONode (*nextwebclient)(iONode,iONode);
  void (*setwebclient)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wHttpService wHttpService;

#ifdef __cplusplus
  }
#endif


#endif
