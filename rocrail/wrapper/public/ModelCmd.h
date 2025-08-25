/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_ModelCmd_H
#define __WRAPPER_ModelCmd_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wModelCmd {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* add;
  const char* addmodule;
  const char* bklist;
  const char* dontsaveonexit;
  const char* fstat;
  const char* initfield;
  const char* lclist;
  const char* lcprops;
  const char* merge;
  const char* modify;
  const char* move;
  const char* plan;
  const char* plantitle;
  const char* remove;
  const char* save;
  const char* sclist;
  const char* stlist;
  const char* swlist;
  const char* themes;
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  const char* (*getcmdfrom)(iONode);
  void (*setcmdfrom)(iONode,const char*);
  const char* (*getcontrolcode)(iONode);
  void (*setcontrolcode)(iONode,const char*);
  Boolean (*isdisablemonitor)(iONode);
  void (*setdisablemonitor)(iONode,Boolean);
  const char* (*getval)(iONode);
  void (*setval)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wModelCmd wModelCmd;

#ifdef __cplusplus
  }
#endif


#endif
