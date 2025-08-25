/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Description_H
#define __WRAPPER_Description_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wDescription {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getlang)(iONode);
  void (*setlang)(iONode,const char*);
  const char* (*gettext)(iONode);
  void (*settext)(iONode,const char*);
  const char* (*geturl)(iONode);
  void (*seturl)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wDescription wDescription;

#ifdef __cplusplus
  }
#endif


#endif
