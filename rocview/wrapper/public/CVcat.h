/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#ifndef __WRAPPER_CVcat_H
#define __WRAPPER_CVcat_H

#include "rocview/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wCVcat {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getname)(iONode);
  void (*setname)(iONode,const char*);
  const char* (*getnrs)(iONode);
  void (*setnrs)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wCVcat wCVcat;

#ifdef __cplusplus
  }
#endif


#endif
