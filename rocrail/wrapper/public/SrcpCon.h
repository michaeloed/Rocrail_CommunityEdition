/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_SrcpCon_H
#define __WRAPPER_SrcpCon_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wSrcpCon {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isactive)(iONode);
  void (*setactive)(iONode,Boolean);
  const char* (*getdevice)(iONode);
  void (*setdevice)(iONode,const char*);
  int (*getmaxcon)(iONode);
  void (*setmaxcon)(iONode,int);
  int (*getport)(iONode);
  void (*setport)(iONode,int);
  iONode (*getsrcpbus)(iONode);
  iONode (*nextsrcpbus)(iONode,iONode);
  void (*setsrcpbus)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wSrcpCon wSrcpCon;

#ifdef __cplusplus
  }
#endif


#endif
