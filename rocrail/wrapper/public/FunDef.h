/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_FunDef_H
#define __WRAPPER_FunDef_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wFunDef {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* enter_block;
  const char* exit_block;
  const char* in_block;
  const char* run;
  const char* stall;
  int (*getaddr)(iONode);
  void (*setaddr)(iONode,int);
  int (*getfn)(iONode);
  void (*setfn)(iONode,int);
  const char* (*geticon)(iONode);
  void (*seticon)(iONode,const char*);
  int (*getmappedfn)(iONode);
  void (*setmappedfn)(iONode,int);
  const char* (*getoffblockid)(iONode);
  void (*setoffblockid)(iONode,const char*);
  const char* (*getoffevent)(iONode);
  void (*setoffevent)(iONode,const char*);
  Boolean (*ison)(iONode);
  void (*seton)(iONode,Boolean);
  const char* (*getonblockid)(iONode);
  void (*setonblockid)(iONode,const char*);
  const char* (*getonevent)(iONode);
  void (*setonevent)(iONode,const char*);
  const char* (*getsound)(iONode);
  void (*setsound)(iONode,const char*);
  const char* (*gettext)(iONode);
  void (*settext)(iONode,const char*);
  int (*gettimer)(iONode);
  void (*settimer)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wFunDef wFunDef;

#ifdef __cplusplus
  }
#endif


#endif
