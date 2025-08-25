/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_RocNetNodeOptions_H
#define __WRAPPER_RocNetNodeOptions_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wRocNetNodeOptions {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int iotype_i2c0;
  int iotype_i2c1;
  Boolean (*isadcsensor)(iONode);
  void (*setadcsensor)(iONode,Boolean);
  int (*getadcthreshold)(iONode);
  void (*setadcthreshold)(iONode,int);
  int (*getiotype)(iONode);
  void (*setiotype)(iONode,int);
  Boolean (*ismobile)(iONode);
  void (*setmobile)(iONode,Boolean);
  const char* (*getnickname)(iONode);
  void (*setnickname)(iONode,const char*);
  Boolean (*isrfid)(iONode);
  void (*setrfid)(iONode,Boolean);
  Boolean (*issack)(iONode);
  void (*setsack)(iONode,Boolean);
  const char* (*getsoundpath)(iONode);
  void (*setsoundpath)(iONode,const char*);
  const char* (*getsoundplayer)(iONode);
  void (*setsoundplayer)(iONode,const char*);
  Boolean (*isusepb)(iONode);
  void (*setusepb)(iONode,Boolean);
  Boolean (*dump)(iONode node);
};

extern struct __wRocNetNodeOptions wRocNetNodeOptions;

#ifdef __cplusplus
  }
#endif


#endif
