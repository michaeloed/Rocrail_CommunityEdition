/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:52 2018
  */

#ifndef __WRAPPER_Accelerator_H
#define __WRAPPER_Accelerator_H

#include "rocview/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wAccelerator {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* ebreak;
  const char* (*getfunction)(iONode);
  void (*setfunction)(iONode,const char*);
  int (*getkeycode)(iONode);
  void (*setkeycode)(iONode,int);
  int (*getmodifier)(iONode);
  void (*setmodifier)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wAccelerator wAccelerator;

#ifdef __cplusplus
  }
#endif


#endif
