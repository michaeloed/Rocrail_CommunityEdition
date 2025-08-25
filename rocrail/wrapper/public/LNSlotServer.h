/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_LNSlotServer_H
#define __WRAPPER_LNSlotServer_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wLNSlotServer {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isactive)(iONode);
  void (*setactive)(iONode,Boolean);
  const char* (*getformat)(iONode);
  void (*setformat)(iONode,const char*);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  Boolean (*islconly)(iONode);
  void (*setlconly)(iONode,Boolean);
  Boolean (*ispurge)(iONode);
  void (*setpurge)(iONode,Boolean);
  int (*getspeedstep)(iONode);
  void (*setspeedstep)(iONode,int);
  Boolean (*isstopatpurge)(iONode);
  void (*setstopatpurge)(iONode,Boolean);
  Boolean (*dump)(iONode node);
};

extern struct __wLNSlotServer wLNSlotServer;

#ifdef __cplusplus
  }
#endif


#endif
