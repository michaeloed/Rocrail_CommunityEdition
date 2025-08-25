/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_Text_H
#define __WRAPPER_Text_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wText {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getaddr)(iONode);
  void (*setaddr)(iONode,int);
  int (*getbackblue)(iONode);
  void (*setbackblue)(iONode,int);
  int (*getbackgreen)(iONode);
  void (*setbackgreen)(iONode,int);
  int (*getbackred)(iONode);
  void (*setbackred)(iONode,int);
  const char* (*getblock)(iONode);
  void (*setblock)(iONode,const char*);
  int (*getblue)(iONode);
  void (*setblue)(iONode,int);
  Boolean (*isbold)(iONode);
  void (*setbold)(iONode,Boolean);
  Boolean (*isborder)(iONode);
  void (*setborder)(iONode,Boolean);
  int (*getbus)(iONode);
  void (*setbus)(iONode,int);
  int (*getcarcount)(iONode);
  void (*setcarcount)(iONode,int);
  Boolean (*isclock)(iONode);
  void (*setclock)(iONode,Boolean);
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  int (*getcountedcars)(iONode);
  void (*setcountedcars)(iONode,int);
  int (*getcounter)(iONode);
  void (*setcounter)(iONode,int);
  int (*getcx)(iONode);
  void (*setcx)(iONode,int);
  int (*getcy)(iONode);
  void (*setcy)(iONode,int);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  int (*getdisplay)(iONode);
  void (*setdisplay)(iONode,int);
  const char* (*getformat)(iONode);
  void (*setformat)(iONode,const char*);
  int (*getgreen)(iONode);
  void (*setgreen)(iONode,int);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  Boolean (*isitalic)(iONode);
  void (*setitalic)(iONode,Boolean);
  int (*getload)(iONode);
  void (*setload)(iONode,int);
  const char* (*getlocation)(iONode);
  void (*setlocation)(iONode,const char*);
  Boolean (*ismanualinput)(iONode);
  void (*setmanualinput)(iONode,Boolean);
  double (*getmvspeed)(iONode);
  void (*setmvspeed)(iONode,double);
  const char* (*getoid)(iONode);
  void (*setoid)(iONode,const char*);
  const char* (*getori)(iONode);
  void (*setori)(iONode,const char*);
  int (*getpointsize)(iONode);
  void (*setpointsize)(iONode,int);
  const char* (*getprev_id)(iONode);
  void (*setprev_id)(iONode,const char*);
  int (*getred)(iONode);
  void (*setred)(iONode,int);
  const char* (*getrefbkid)(iONode);
  void (*setrefbkid)(iONode,const char*);
  const char* (*getreflcid)(iONode);
  void (*setreflcid)(iONode,const char*);
  Boolean (*isreset)(iONode);
  void (*setreset)(iONode,Boolean);
  int (*gettemp)(iONode);
  void (*settemp)(iONode,int);
  const char* (*gettext)(iONode);
  void (*settext)(iONode,const char*);
  Boolean (*istransparent)(iONode);
  void (*settransparent)(iONode,Boolean);
  Boolean (*isunderlined)(iONode);
  void (*setunderlined)(iONode,Boolean);
  int (*getvolt)(iONode);
  void (*setvolt)(iONode,int);
  int (*getwheelcount)(iONode);
  void (*setwheelcount)(iONode,int);
  int (*getx)(iONode);
  void (*setx)(iONode,int);
  int (*gety)(iONode);
  void (*sety)(iONode,int);
  int (*getz)(iONode);
  void (*setz)(iONode,int);
  iONode (*getactionctrl)(iONode);
  iONode (*nextactionctrl)(iONode,iONode);
  void (*setactionctrl)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wText wText;

#ifdef __cplusplus
  }
#endif


#endif
