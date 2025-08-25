/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_ActionCond_H
#define __WRAPPER_ActionCond_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wActionCond {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  Boolean (*ismustbetrue)(iONode);
  void (*setmustbetrue)(iONode,Boolean);
  const char* (*getstate)(iONode);
  void (*setstate)(iONode,const char*);
  const char* (*getsubid)(iONode);
  void (*setsubid)(iONode,const char*);
  const char* (*gettype)(iONode);
  void (*settype)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wActionCond wActionCond;

#ifdef __cplusplus
  }
#endif


#endif
