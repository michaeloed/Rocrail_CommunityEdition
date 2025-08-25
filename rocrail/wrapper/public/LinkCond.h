/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_LinkCond_H
#define __WRAPPER_LinkCond_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wLinkCond {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getfirst)(iONode);
  void (*setfirst)(iONode,const char*);
  const char* (*getfree)(iONode);
  void (*setfree)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wLinkCond wLinkCond;

#ifdef __cplusplus
  }
#endif


#endif
