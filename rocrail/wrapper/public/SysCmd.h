/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_SysCmd_H
#define __WRAPPER_SysCmd_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wSysCmd {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* analog;
  const char* analyze;
  const char* clearshortids;
  const char* config;
  const char* dcc;
  const char* ebreak;
  const char* enablecom;
  const char* getini;
  const char* getmodplan;
  const char* getmodule;
  const char* getstate;
  const char* go;
  const char* grouplink;
  const char* hfi;
  const char* info;
  const char* init;
  const char* link;
  const char* loccnfg;
  const char* reset;
  const char* resetblock;
  const char* resetfx;
  const char* resetstat;
  const char* save;
  const char* setini;
  const char* setmodplan;
  const char* setmodule;
  const char* shutdown;
  const char* shutdownnode;
  const char* slots;
  const char* sod;
  const char* stop;
  const char* stoplocs;
  const char* swcnfg;
  const char* test;
  const char* txshortids;
  const char* ulink;
  const char* updateserver;
  const char* version;
  const char* weather;
  int (*getaddr)(iONode);
  void (*setaddr)(iONode,int);
  const char* (*getarch)(iONode);
  void (*setarch)(iONode,const char*);
  int (*getbus)(iONode);
  void (*setbus)(iONode,int);
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  const char* (*getdist)(iONode);
  void (*setdist)(iONode,const char*);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  Boolean (*isinformall)(iONode);
  void (*setinformall)(iONode,Boolean);
  const char* (*getoid)(iONode);
  void (*setoid)(iONode,const char*);
  int (*getport)(iONode);
  void (*setport)(iONode,int);
  int (*getval)(iONode);
  void (*setval)(iONode,int);
  int (*getvalA)(iONode);
  void (*setvalA)(iONode,int);
  int (*getvalB)(iONode);
  void (*setvalB)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wSysCmd wSysCmd;

#ifdef __cplusplus
  }
#endif


#endif
