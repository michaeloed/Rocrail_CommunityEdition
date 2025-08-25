/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_Operator_H
#define __WRAPPER_Operator_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wOperator {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* addcar;
  const char* emptycar;
  const char* loadcar;
  const char* removecar;
  int (*getV_max)(iONode);
  void (*setV_max)(iONode,int);
  const char* (*getcargo)(iONode);
  void (*setcargo)(iONode,const char*);
  const char* (*getcarids)(iONode);
  void (*setcarids)(iONode,const char*);
  const char* (*getclass)(iONode);
  void (*setclass)(iONode,const char*);
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getlcid)(iONode);
  void (*setlcid)(iONode,const char*);
  const char* (*getlocation)(iONode);
  void (*setlocation)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wOperator wOperator;

#ifdef __cplusplus
  }
#endif


#endif
