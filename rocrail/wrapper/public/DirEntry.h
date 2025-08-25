/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_DirEntry_H
#define __WRAPPER_DirEntry_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wDirEntry {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getdir)(iONode);
  void (*setdir)(iONode,const char*);
  iONode (*getfileentry)(iONode);
  iONode (*nextfileentry)(iONode,iONode);
  void (*setfileentry)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wDirEntry wDirEntry;

#ifdef __cplusplus
  }
#endif


#endif
