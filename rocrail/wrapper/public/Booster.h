/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Booster_H
#define __WRAPPER_Booster_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wBooster {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getblockids)(iONode);
  void (*setblockids)(iONode,const char*);
  const char* (*getdistrict)(iONode);
  void (*setdistrict)(iONode,const char*);
  Boolean (*isdoesreport)(iONode);
  void (*setdoesreport)(iONode,Boolean);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  int (*getload)(iONode);
  void (*setload)(iONode,int);
  int (*getloadmax)(iONode);
  void (*setloadmax)(iONode,int);
  const char* (*getmodids)(iONode);
  void (*setmodids)(iONode,const char*);
  Boolean (*ispower)(iONode);
  void (*setpower)(iONode,Boolean);
  const char* (*getpowerfb)(iONode);
  void (*setpowerfb)(iONode,const char*);
  const char* (*getpowersw)(iONode);
  void (*setpowersw)(iONode,const char*);
  const char* (*getscfb)(iONode);
  void (*setscfb)(iONode,const char*);
  Boolean (*isscopt_poweroffall)(iONode);
  void (*setscopt_poweroffall)(iONode,Boolean);
  Boolean (*isscopt_repoweron)(iONode);
  void (*setscopt_repoweron)(iONode,Boolean);
  Boolean (*isscopt_stoplocos)(iONode);
  void (*setscopt_stoplocos)(iONode,Boolean);
  Boolean (*isshortcut)(iONode);
  void (*setshortcut)(iONode,Boolean);
  int (*gettemp)(iONode);
  void (*settemp)(iONode,int);
  int (*gettempmax)(iONode);
  void (*settempmax)(iONode,int);
  int (*getuid)(iONode);
  void (*setuid)(iONode,int);
  int (*getvolt)(iONode);
  void (*setvolt)(iONode,int);
  int (*getvoltmin)(iONode);
  void (*setvoltmin)(iONode,int);
  iONode (*getactionctrl)(iONode);
  iONode (*nextactionctrl)(iONode,iONode);
  void (*setactionctrl)(iONode,iONode);
  iONode (*getboosterevent)(iONode);
  iONode (*nextboosterevent)(iONode,iONode);
  void (*setboosterevent)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wBooster wBooster;

#ifdef __cplusplus
  }
#endif


#endif
