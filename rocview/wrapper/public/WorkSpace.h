/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:52 2018
  */

#ifndef __WRAPPER_WorkSpace_H
#define __WRAPPER_WorkSpace_H

#include "rocview/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wWorkSpace {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getpath)(iONode);
  void (*setpath)(iONode,const char*);
  const char* (*gettitle)(iONode);
  void (*settitle)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wWorkSpace wWorkSpace;

#ifdef __cplusplus
  }
#endif


#endif
