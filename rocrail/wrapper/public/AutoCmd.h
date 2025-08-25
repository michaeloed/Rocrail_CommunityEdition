/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_AutoCmd_H
#define __WRAPPER_AutoCmd_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wAutoCmd {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* off;
  const char* on;
  const char* reset;
  const char* resume;
  const char* softreset;
  const char* start;
  const char* startvirtual;
  const char* stop;
  const char* v0locos;
  const char* vrestorelocos;
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  int (*getera)(iONode);
  void (*setera)(iONode,int);
  Boolean (*isreset)(iONode);
  void (*setreset)(iONode,Boolean);
  Boolean (*dump)(iONode node);
};

extern struct __wAutoCmd wAutoCmd;

#ifdef __cplusplus
  }
#endif


#endif
