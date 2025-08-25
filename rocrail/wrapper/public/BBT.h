/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_BBT_H
#define __WRAPPER_BBT_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wBBT {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getbk)(iONode);
  void (*setbk)(iONode,const char*);
  int (*getcount)(iONode);
  void (*setcount)(iONode,int);
  int (*getdelay)(iONode);
  void (*setdelay)(iONode,int);
  Boolean (*isfixed)(iONode);
  void (*setfixed)(iONode,Boolean);
  const char* (*getfrombk)(iONode);
  void (*setfrombk)(iONode,const char*);
  Boolean (*isgeneratein)(iONode);
  void (*setgeneratein)(iONode,Boolean);
  int (*getinterval)(iONode);
  void (*setinterval)(iONode,int);
  const char* (*getroute)(iONode);
  void (*setroute)(iONode,const char*);
  int (*getspeed)(iONode);
  void (*setspeed)(iONode,int);
  int (*getsteps)(iONode);
  void (*setsteps)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wBBT wBBT;

#ifdef __cplusplus
  }
#endif


#endif
