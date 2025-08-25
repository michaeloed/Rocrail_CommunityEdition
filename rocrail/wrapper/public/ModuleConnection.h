/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_ModuleConnection_H
#define __WRAPPER_ModuleConnection_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wModuleConnection {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* point_e;
  const char* point_n;
  const char* point_s;
  const char* point_w;
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getmodid)(iONode);
  void (*setmodid)(iONode,const char*);
  const char* (*getside)(iONode);
  void (*setside)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wModuleConnection wModuleConnection;

#ifdef __cplusplus
  }
#endif


#endif
