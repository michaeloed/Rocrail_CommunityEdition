/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_BinCmd_H
#define __WRAPPER_BinCmd_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wBinCmd {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  int (*getinendbyte)(iONode);
  void (*setinendbyte)(iONode,int);
  int (*getinlen)(iONode);
  void (*setinlen)(iONode,int);
  const char* (*getout)(iONode);
  void (*setout)(iONode,const char*);
  int (*getoutlen)(iONode);
  void (*setoutlen)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wBinCmd wBinCmd;

#ifdef __cplusplus
  }
#endif


#endif
