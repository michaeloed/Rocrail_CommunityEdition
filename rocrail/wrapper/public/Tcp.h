/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Tcp_H
#define __WRAPPER_Tcp_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wTcp {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getcontrolcode)(iONode);
  void (*setcontrolcode)(iONode,const char*);
  int (*getmaxcon)(iONode);
  void (*setmaxcon)(iONode,int);
  Boolean (*isonlyfirstmaster)(iONode);
  void (*setonlyfirstmaster)(iONode,Boolean);
  int (*getport)(iONode);
  void (*setport)(iONode,int);
  const char* (*getslavecode)(iONode);
  void (*setslavecode)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wTcp wTcp;

#ifdef __cplusplus
  }
#endif


#endif
