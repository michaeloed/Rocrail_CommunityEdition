/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_DIPValue_H
#define __WRAPPER_DIPValue_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wDIPValue {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int valuetype_cv;
  int valuetype_value;
  const char* (*getinfo)(iONode);
  void (*setinfo)(iONode,const char*);
  const char* (*getname)(iONode);
  void (*setname)(iONode,const char*);
  int (*gettype)(iONode);
  void (*settype)(iONode,int);
  int (*getvalue)(iONode);
  void (*setvalue)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wDIPValue wDIPValue;

#ifdef __cplusplus
  }
#endif


#endif
