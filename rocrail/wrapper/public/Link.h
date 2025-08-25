/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_Link_H
#define __WRAPPER_Link_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wLink {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int usage_critsect;
  int usage_manual;
  Boolean (*isactive)(iONode);
  void (*setactive)(iONode,Boolean);
  Boolean (*isallowfollowup)(iONode);
  void (*setallowfollowup)(iONode,Boolean);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  const char* (*getdst)(iONode);
  void (*setdst)(iONode,const char*);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  int (*getmaxfollowup)(iONode);
  void (*setmaxfollowup)(iONode,int);
  const char* (*getsrc)(iONode);
  void (*setsrc)(iONode,const char*);
  int (*getusage)(iONode);
  void (*setusage)(iONode,int);
  iONode (*getlinkcond)(iONode);
  iONode (*nextlinkcond)(iONode,iONode);
  void (*setlinkcond)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wLink wLink;

#ifdef __cplusplus
  }
#endif


#endif
