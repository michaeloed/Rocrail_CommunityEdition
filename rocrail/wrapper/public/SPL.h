/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_SPL_H
#define __WRAPPER_SPL_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wSPL {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getfromaddr)(iONode);
  void (*setfromaddr)(iONode,int);
  int (*getnrleds)(iONode);
  void (*setnrleds)(iONode,int);
  int (*gettoaddr)(iONode);
  void (*settoaddr)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wSPL wSPL;

#ifdef __cplusplus
  }
#endif


#endif
