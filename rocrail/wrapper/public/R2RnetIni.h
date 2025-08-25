/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_R2RnetIni_H
#define __WRAPPER_R2RnetIni_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wR2RnetIni {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getaddr)(iONode);
  void (*setaddr)(iONode,const char*);
  Boolean (*isenable)(iONode);
  void (*setenable)(iONode,Boolean);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  int (*getport)(iONode);
  void (*setport)(iONode,int);
  const char* (*getroutes)(iONode);
  void (*setroutes)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wR2RnetIni wR2RnetIni;

#ifdef __cplusplus
  }
#endif


#endif
