/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_SelTabPos_H
#define __WRAPPER_SelTabPos_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wSelTabPos {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getbkid)(iONode);
  void (*setbkid)(iONode,const char*);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  int (*getnr)(iONode);
  void (*setnr)(iONode,int);
  const char* (*gets1id)(iONode);
  void (*sets1id)(iONode,const char*);
  const char* (*gets2id)(iONode);
  void (*sets2id)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wSelTabPos wSelTabPos;

#ifdef __cplusplus
  }
#endif


#endif
