/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#ifndef __WRAPPER_CVconf_H
#define __WRAPPER_CVconf_H

#include "rocview/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wCVconf {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*islissy)(iONode);
  void (*setlissy)(iONode,Boolean);
  const char* (*getnrs)(iONode);
  void (*setnrs)(iONode,const char*);
  Boolean (*ispom)(iONode);
  void (*setpom)(iONode,Boolean);
  Boolean (*issave)(iONode);
  void (*setsave)(iONode,Boolean);
  int (*gettimeout)(iONode);
  void (*settimeout)(iONode,int);
  Boolean (*isusedecspec4all)(iONode);
  void (*setusedecspec4all)(iONode,Boolean);
  iONode (*getcvcat)(iONode);
  iONode (*nextcvcat)(iONode,iONode);
  void (*setcvcat)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wCVconf wCVconf;

#ifdef __cplusplus
  }
#endif


#endif
