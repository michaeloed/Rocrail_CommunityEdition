/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_MVTrack_H
#define __WRAPPER_MVTrack_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wMVTrack {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getdistance)(iONode);
  void (*setdistance)(iONode,int);
  Boolean (*ismph)(iONode);
  void (*setmph)(iONode,Boolean);
  const char* (*gets1)(iONode);
  void (*sets1)(iONode,const char*);
  const char* (*gets2)(iONode);
  void (*sets2)(iONode,const char*);
  int (*getscale)(iONode);
  void (*setscale)(iONode,int);
  iONode (*getactionctrl)(iONode);
  iONode (*nextactionctrl)(iONode,iONode);
  void (*setactionctrl)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wMVTrack wMVTrack;

#ifdef __cplusplus
  }
#endif


#endif
