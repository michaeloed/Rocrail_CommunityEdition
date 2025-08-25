/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#ifndef __WRAPPER_Patch_H
#define __WRAPPER_Patch_H

#include "rocview/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wPatch {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isdownload)(iONode);
  void (*setdownload)(iONode,Boolean);
  const char* (*getfile)(iONode);
  void (*setfile)(iONode,const char*);
  int (*getnr)(iONode);
  void (*setnr)(iONode,int);
  const char* (*getos)(iONode);
  void (*setos)(iONode,const char*);
  const char* (*getremark)(iONode);
  void (*setremark)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wPatch wPatch;

#ifdef __cplusplus
  }
#endif


#endif
