/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_DecVariable_H
#define __WRAPPER_DecVariable_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wDecVariable {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getCV)(iONode);
  void (*setCV)(iONode,int);
  const char* (*getcomment)(iONode);
  void (*setcomment)(iONode,const char*);
  const char* (*getitem)(iONode);
  void (*setitem)(iONode,const char*);
  const char* (*getlabel)(iONode);
  void (*setlabel)(iONode,const char*);
  const char* (*getmask)(iONode);
  void (*setmask)(iONode,const char*);
  const char* (*gettooltip)(iONode);
  void (*settooltip)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wDecVariable wDecVariable;

#ifdef __cplusplus
  }
#endif


#endif
