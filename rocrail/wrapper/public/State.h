/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_State_H
#define __WRAPPER_State_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wState {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isaccessorybus)(iONode);
  void (*setaccessorybus)(iONode,Boolean);
  Boolean (*isconsolemode)(iONode);
  void (*setconsolemode)(iONode,Boolean);
  Boolean (*isemergency)(iONode);
  void (*setemergency)(iONode,Boolean);
  Boolean (*isenablecom)(iONode);
  void (*setenablecom)(iONode,Boolean);
  Boolean (*ishealthy)(iONode);
  void (*sethealthy)(iONode,Boolean);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  int (*getload)(iONode);
  void (*setload)(iONode,int);
  int (*getloadmax)(iONode);
  void (*setloadmax)(iONode,int);
  Boolean (*isneedkey4loconet)(iONode);
  void (*setneedkey4loconet)(iONode,Boolean);
  Boolean (*ispower)(iONode);
  void (*setpower)(iONode,Boolean);
  Boolean (*isprogramming)(iONode);
  void (*setprogramming)(iONode,Boolean);
  int (*getptload)(iONode);
  void (*setptload)(iONode,int);
  Boolean (*issensorbus)(iONode);
  void (*setsensorbus)(iONode,Boolean);
  Boolean (*isshortcut)(iONode);
  void (*setshortcut)(iONode,Boolean);
  int (*gettemp)(iONode);
  void (*settemp)(iONode,int);
  int (*gettempmax)(iONode);
  void (*settempmax)(iONode,int);
  Boolean (*istrackbus)(iONode);
  void (*settrackbus)(iONode,Boolean);
  int (*getuid)(iONode);
  void (*setuid)(iONode,int);
  int (*getvolt)(iONode);
  void (*setvolt)(iONode,int);
  int (*getvoltmin)(iONode);
  void (*setvoltmin)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wState wState;

#ifdef __cplusplus
  }
#endif


#endif
