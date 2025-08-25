/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_CustomCmd_H
#define __WRAPPER_CustomCmd_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wCustomCmd {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getarg1)(iONode);
  void (*setarg1)(iONode,const char*);
  const char* (*getarg2)(iONode);
  void (*setarg2)(iONode,const char*);
  const char* (*getarg3)(iONode);
  void (*setarg3)(iONode,const char*);
  const char* (*getarg4)(iONode);
  void (*setarg4)(iONode,const char*);
  const char* (*getarg5)(iONode);
  void (*setarg5)(iONode,const char*);
  const char* (*getarg6)(iONode);
  void (*setarg6)(iONode,const char*);
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wCustomCmd wCustomCmd;

#ifdef __cplusplus
  }
#endif


#endif
