/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Service_H
#define __WRAPPER_Service_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wService {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getport)(iONode);
  void (*setport)(iONode,int);
  const char* (*getsname)(iONode);
  void (*setsname)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wService wService;

#ifdef __cplusplus
  }
#endif


#endif
