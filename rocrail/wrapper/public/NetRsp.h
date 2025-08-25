/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_NetRsp_H
#define __WRAPPER_NetRsp_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wNetRsp {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* rsp_block;
  const char* rsp_clientconn;
  const char* rsp_isfree;
  const char* rsp_occupied;
  const char* rsp_reserved;
  const char* rsp_unlocked;
  const char* (*gethost)(iONode);
  void (*sethost)(iONode,const char*);
  const char* (*getlocalbk)(iONode);
  void (*setlocalbk)(iONode,const char*);
  const char* (*getlocalid)(iONode);
  void (*setlocalid)(iONode,const char*);
  const char* (*getplan)(iONode);
  void (*setplan)(iONode,const char*);
  int (*getport)(iONode);
  void (*setport)(iONode,int);
  const char* (*getremotebk)(iONode);
  void (*setremotebk)(iONode,const char*);
  const char* (*getremoteid)(iONode);
  void (*setremoteid)(iONode,const char*);
  const char* (*getrsp)(iONode);
  void (*setrsp)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wNetRsp wNetRsp;

#ifdef __cplusplus
  }
#endif


#endif
