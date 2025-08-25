/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Trace_H
#define __WRAPPER_Trace_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wTrace {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isautomatic)(iONode);
  void (*setautomatic)(iONode,Boolean);
  Boolean (*isbyte)(iONode);
  void (*setbyte)(iONode,Boolean);
  Boolean (*iscalc)(iONode);
  void (*setcalc)(iONode,Boolean);
  Boolean (*isdebug)(iONode);
  void (*setdebug)(iONode,Boolean);
  int (*getdumpsize)(iONode);
  void (*setdumpsize)(iONode,int);
  Boolean (*isexceptionfile)(iONode);
  void (*setexceptionfile)(iONode,Boolean);
  const char* (*getgfile)(iONode);
  void (*setgfile)(iONode,const char*);
  Boolean (*isinfo)(iONode);
  void (*setinfo)(iONode,Boolean);
  const char* (*getinvoke)(iONode);
  void (*setinvoke)(iONode,const char*);
  Boolean (*isinvokeasync)(iONode);
  void (*setinvokeasync)(iONode,Boolean);
  Boolean (*islisten2all)(iONode);
  void (*setlisten2all)(iONode,Boolean);
  Boolean (*ismeminfo)(iONode);
  void (*setmeminfo)(iONode,Boolean);
  Boolean (*ismonitor)(iONode);
  void (*setmonitor)(iONode,Boolean);
  int (*getnr)(iONode);
  void (*setnr)(iONode,int);
  Boolean (*isparse)(iONode);
  void (*setparse)(iONode,Boolean);
  const char* (*getprotpath)(iONode);
  void (*setprotpath)(iONode,const char*);
  const char* (*getrfile)(iONode);
  void (*setrfile)(iONode,const char*);
  int (*getsize)(iONode);
  void (*setsize)(iONode,int);
  Boolean (*isunique)(iONode);
  void (*setunique)(iONode,Boolean);
  Boolean (*dump)(iONode node);
};

extern struct __wTrace wTrace;

#ifdef __cplusplus
  }
#endif


#endif
