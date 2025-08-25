/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_ModPlan_H
#define __WRAPPER_ModPlan_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wModPlan {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isinitfield)(iONode);
  void (*setinitfield)(iONode,Boolean);
  const char* (*getlocs)(iONode);
  void (*setlocs)(iONode,const char*);
  Boolean (*ismodified)(iONode);
  void (*setmodified)(iONode,Boolean);
  Boolean (*ismodroutes)(iONode);
  void (*setmodroutes)(iONode,Boolean);
  const char* (*getroutes)(iONode);
  void (*setroutes)(iONode,const char*);
  Boolean (*issavemodplan)(iONode);
  void (*setsavemodplan)(iONode,Boolean);
  Boolean (*issavemodules)(iONode);
  void (*setsavemodules)(iONode,Boolean);
  const char* (*getsubtitle)(iONode);
  void (*setsubtitle)(iONode,const char*);
  const char* (*gettitle)(iONode);
  void (*settitle)(iONode,const char*);
  iONode (*getmodule)(iONode);
  iONode (*nextmodule)(iONode,iONode);
  void (*setmodule)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wModPlan wModPlan;

#ifdef __cplusplus
  }
#endif


#endif
