/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_ActionCtrl_H
#define __WRAPPER_ActionCtrl_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wActionCtrl {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isallconditions)(iONode);
  void (*setallconditions)(iONode,Boolean);
  Boolean (*isatcmd)(iONode);
  void (*setatcmd)(iONode,Boolean);
  Boolean (*isatevt)(iONode);
  void (*setatevt)(iONode,Boolean);
  Boolean (*isauto)(iONode);
  void (*setauto)(iONode,Boolean);
  const char* (*getbkid)(iONode);
  void (*setbkid)(iONode,const char*);
  int (*getcarcount)(iONode);
  void (*setcarcount)(iONode,int);
  int (*getcountedcars)(iONode);
  void (*setcountedcars)(iONode,int);
  int (*getcounter)(iONode);
  void (*setcounter)(iONode,int);
  const char* (*getdeact)(iONode);
  void (*setdeact)(iONode,const char*);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  int (*getduration)(iONode);
  void (*setduration)(iONode,int);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getlcclass)(iONode);
  void (*setlcclass)(iONode,const char*);
  const char* (*getlcid)(iONode);
  void (*setlcid)(iONode,const char*);
  int (*getload)(iONode);
  void (*setload)(iONode,int);
  Boolean (*ismanual)(iONode);
  void (*setmanual)(iONode,Boolean);
  double (*getmvspeed)(iONode);
  void (*setmvspeed)(iONode,double);
  const char* (*getparam)(iONode);
  void (*setparam)(iONode,const char*);
  Boolean (*isreset)(iONode);
  void (*setreset)(iONode,Boolean);
  const char* (*getstate)(iONode);
  void (*setstate)(iONode,const char*);
  const char* (*getstid)(iONode);
  void (*setstid)(iONode,const char*);
  const char* (*getsubstate)(iONode);
  void (*setsubstate)(iONode,const char*);
  int (*gettemp)(iONode);
  void (*settemp)(iONode,int);
  int (*gettimer)(iONode);
  void (*settimer)(iONode,int);
  int (*getvolt)(iONode);
  void (*setvolt)(iONode,int);
  int (*getwheelcount)(iONode);
  void (*setwheelcount)(iONode,int);
  iONode (*getactioncond)(iONode);
  iONode (*nextactioncond)(iONode,iONode);
  void (*setactioncond)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wActionCtrl wActionCtrl;

#ifdef __cplusplus
  }
#endif


#endif
