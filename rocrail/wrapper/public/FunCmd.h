/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_FunCmd_H
#define __WRAPPER_FunCmd_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wFunCmd {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getaddr)(iONode);
  void (*setaddr)(iONode,int);
  int (*getbus)(iONode);
  void (*setbus)(iONode,int);
  const char* (*getevent)(iONode);
  void (*setevent)(iONode,const char*);
  const char* (*geteventblock)(iONode);
  void (*seteventblock)(iONode,const char*);
  Boolean (*isf0)(iONode);
  void (*setf0)(iONode,Boolean);
  Boolean (*isf1)(iONode);
  void (*setf1)(iONode,Boolean);
  Boolean (*isf10)(iONode);
  void (*setf10)(iONode,Boolean);
  Boolean (*isf11)(iONode);
  void (*setf11)(iONode,Boolean);
  Boolean (*isf12)(iONode);
  void (*setf12)(iONode,Boolean);
  Boolean (*isf13)(iONode);
  void (*setf13)(iONode,Boolean);
  Boolean (*isf14)(iONode);
  void (*setf14)(iONode,Boolean);
  Boolean (*isf15)(iONode);
  void (*setf15)(iONode,Boolean);
  Boolean (*isf16)(iONode);
  void (*setf16)(iONode,Boolean);
  Boolean (*isf17)(iONode);
  void (*setf17)(iONode,Boolean);
  Boolean (*isf18)(iONode);
  void (*setf18)(iONode,Boolean);
  Boolean (*isf19)(iONode);
  void (*setf19)(iONode,Boolean);
  Boolean (*isf2)(iONode);
  void (*setf2)(iONode,Boolean);
  Boolean (*isf20)(iONode);
  void (*setf20)(iONode,Boolean);
  Boolean (*isf21)(iONode);
  void (*setf21)(iONode,Boolean);
  Boolean (*isf22)(iONode);
  void (*setf22)(iONode,Boolean);
  Boolean (*isf23)(iONode);
  void (*setf23)(iONode,Boolean);
  Boolean (*isf24)(iONode);
  void (*setf24)(iONode,Boolean);
  Boolean (*isf25)(iONode);
  void (*setf25)(iONode,Boolean);
  Boolean (*isf26)(iONode);
  void (*setf26)(iONode,Boolean);
  Boolean (*isf27)(iONode);
  void (*setf27)(iONode,Boolean);
  Boolean (*isf28)(iONode);
  void (*setf28)(iONode,Boolean);
  Boolean (*isf3)(iONode);
  void (*setf3)(iONode,Boolean);
  Boolean (*isf4)(iONode);
  void (*setf4)(iONode,Boolean);
  Boolean (*isf5)(iONode);
  void (*setf5)(iONode,Boolean);
  Boolean (*isf6)(iONode);
  void (*setf6)(iONode,Boolean);
  Boolean (*isf7)(iONode);
  void (*setf7)(iONode,Boolean);
  Boolean (*isf8)(iONode);
  void (*setf8)(iONode,Boolean);
  Boolean (*isf9)(iONode);
  void (*setf9)(iONode,Boolean);
  int (*getfnchanged)(iONode);
  void (*setfnchanged)(iONode,int);
  Boolean (*isfnchangedstate)(iONode);
  void (*setfnchangedstate)(iONode,Boolean);
  int (*getfncnt)(iONode);
  void (*setfncnt)(iONode,int);
  int (*getgroup)(iONode);
  void (*setgroup)(iONode,int);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  int (*gettimedfn)(iONode);
  void (*settimedfn)(iONode,int);
  int (*gettimer)(iONode);
  void (*settimer)(iONode,int);
  int (*gettimerf0)(iONode);
  void (*settimerf0)(iONode,int);
  int (*gettimerf1)(iONode);
  void (*settimerf1)(iONode,int);
  int (*gettimerf10)(iONode);
  void (*settimerf10)(iONode,int);
  int (*gettimerf11)(iONode);
  void (*settimerf11)(iONode,int);
  int (*gettimerf12)(iONode);
  void (*settimerf12)(iONode,int);
  int (*gettimerf13)(iONode);
  void (*settimerf13)(iONode,int);
  int (*gettimerf14)(iONode);
  void (*settimerf14)(iONode,int);
  int (*gettimerf15)(iONode);
  void (*settimerf15)(iONode,int);
  int (*gettimerf16)(iONode);
  void (*settimerf16)(iONode,int);
  int (*gettimerf17)(iONode);
  void (*settimerf17)(iONode,int);
  int (*gettimerf18)(iONode);
  void (*settimerf18)(iONode,int);
  int (*gettimerf19)(iONode);
  void (*settimerf19)(iONode,int);
  int (*gettimerf2)(iONode);
  void (*settimerf2)(iONode,int);
  int (*gettimerf20)(iONode);
  void (*settimerf20)(iONode,int);
  int (*gettimerf21)(iONode);
  void (*settimerf21)(iONode,int);
  int (*gettimerf22)(iONode);
  void (*settimerf22)(iONode,int);
  int (*gettimerf23)(iONode);
  void (*settimerf23)(iONode,int);
  int (*gettimerf24)(iONode);
  void (*settimerf24)(iONode,int);
  int (*gettimerf25)(iONode);
  void (*settimerf25)(iONode,int);
  int (*gettimerf26)(iONode);
  void (*settimerf26)(iONode,int);
  int (*gettimerf27)(iONode);
  void (*settimerf27)(iONode,int);
  int (*gettimerf28)(iONode);
  void (*settimerf28)(iONode,int);
  int (*gettimerf3)(iONode);
  void (*settimerf3)(iONode,int);
  int (*gettimerf4)(iONode);
  void (*settimerf4)(iONode,int);
  int (*gettimerf5)(iONode);
  void (*settimerf5)(iONode,int);
  int (*gettimerf6)(iONode);
  void (*settimerf6)(iONode,int);
  int (*gettimerf7)(iONode);
  void (*settimerf7)(iONode,int);
  int (*gettimerf8)(iONode);
  void (*settimerf8)(iONode,int);
  int (*gettimerf9)(iONode);
  void (*settimerf9)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wFunCmd wFunCmd;

#ifdef __cplusplus
  }
#endif


#endif
