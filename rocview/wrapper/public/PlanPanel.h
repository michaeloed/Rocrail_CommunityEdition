/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#ifndef __WRAPPER_PlanPanel_H
#define __WRAPPER_PlanPanel_H

#include "rocview/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wPlanPanel {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  double (*getbktext)(iONode);
  void (*setbktext)(iONode,double);
  int (*getbktext_blue)(iONode);
  void (*setbktext_blue)(iONode,int);
  int (*getbktext_green)(iONode);
  void (*setbktext_green)(iONode,int);
  int (*getbktext_red)(iONode);
  void (*setbktext_red)(iONode,int);
  Boolean (*isbktextid)(iONode);
  void (*setbktextid)(iONode,Boolean);
  int (*getblue)(iONode);
  void (*setblue)(iONode,int);
  int (*getcx)(iONode);
  void (*setcx)(iONode,int);
  int (*getcy)(iONode);
  void (*setcy)(iONode,int);
  Boolean (*isfill)(iONode);
  void (*setfill)(iONode,Boolean);
  int (*getgreen)(iONode);
  void (*setgreen)(iONode,int);
  int (*getitemidps)(iONode);
  void (*setitemidps)(iONode,int);
  Boolean (*islocobook)(iONode);
  void (*setlocobook)(iONode,Boolean);
  Boolean (*isplanbook)(iONode);
  void (*setplanbook)(iONode,Boolean);
  Boolean (*isprocessblockevents)(iONode);
  void (*setprocessblockevents)(iONode,Boolean);
  Boolean (*isprocessrouteevents)(iONode);
  void (*setprocessrouteevents)(iONode,Boolean);
  Boolean (*israster)(iONode);
  void (*setraster)(iONode,Boolean);
  int (*getred)(iONode);
  void (*setred)(iONode,int);
  double (*getscale)(iONode);
  void (*setscale)(iONode,double);
  int (*getscblue)(iONode);
  void (*setscblue)(iONode,int);
  int (*getscgreen)(iONode);
  void (*setscgreen)(iONode,int);
  int (*getscred)(iONode);
  void (*setscred)(iONode,int);
  Boolean (*isshowborder)(iONode);
  void (*setshowborder)(iONode,Boolean);
  Boolean (*isshowcounters)(iONode);
  void (*setshowcounters)(iONode,Boolean);
  Boolean (*isshowid)(iONode);
  void (*setshowid)(iONode,Boolean);
  Boolean (*isshowlocked)(iONode);
  void (*setshowlocked)(iONode,Boolean);
  Boolean (*isshowpending)(iONode);
  void (*setshowpending)(iONode,Boolean);
  Boolean (*isshowsc)(iONode);
  void (*setshowsc)(iONode,Boolean);
  const char* (*getsvgpath)(iONode);
  void (*setsvgpath)(iONode,const char*);
  const char* (*getsvgpath2)(iONode);
  void (*setsvgpath2)(iONode,const char*);
  const char* (*getsvgpath3)(iONode);
  void (*setsvgpath3)(iONode,const char*);
  const char* (*getsvgpath4)(iONode);
  void (*setsvgpath4)(iONode,const char*);
  const char* (*getsvgpath5)(iONode);
  void (*setsvgpath5)(iONode,const char*);
  int (*gettextps)(iONode);
  void (*settextps)(iONode,int);
  Boolean (*istooltip)(iONode);
  void (*settooltip)(iONode,Boolean);
  Boolean (*istracewindow)(iONode);
  void (*settracewindow)(iONode,Boolean);
  Boolean (*dump)(iONode node);
};

extern struct __wPlanPanel wPlanPanel;

#ifdef __cplusplus
  }
#endif


#endif
