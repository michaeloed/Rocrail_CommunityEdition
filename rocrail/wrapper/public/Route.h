/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_Route_H
#define __WRAPPER_Route_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wRoute {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* V_none;
  const char* classadd;
  const char* classdel;
  const char* classset;
  const char* force;
  const char* forwards;
  const char* go;
  const char* modid_auto_gen;
  const char* no;
  const char* point_e;
  const char* point_en;
  const char* point_enn;
  const char* point_es;
  const char* point_ess;
  const char* point_n;
  const char* point_ne;
  const char* point_nee;
  const char* point_nw;
  const char* point_nww;
  const char* point_s;
  const char* point_se;
  const char* point_see;
  const char* point_sw;
  const char* point_sww;
  const char* point_w;
  const char* point_wn;
  const char* point_wnn;
  const char* point_ws;
  const char* point_wss;
  const char* reverse;
  const char* routelock;
  int status_closed;
  int status_deselected;
  int status_free;
  int status_locked;
  int status_selected;
  const char* test;
  const char* (*getbka)(iONode);
  void (*setbka)(iONode,const char*);
  Boolean (*isbkaside)(iONode);
  void (*setbkaside)(iONode,Boolean);
  const char* (*getbkb)(iONode);
  void (*setbkb)(iONode,const char*);
  Boolean (*isbkbside)(iONode);
  void (*setbkbside)(iONode,Boolean);
  const char* (*getbkc)(iONode);
  void (*setbkc)(iONode,const char*);
  const char* (*getclass)(iONode);
  void (*setclass)(iONode,const char*);
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  Boolean (*iscommuter)(iONode);
  void (*setcommuter)(iONode,Boolean);
  const char* (*getcountcars)(iONode);
  void (*setcountcars)(iONode,const char*);
  Boolean (*iscrossingblocksignals)(iONode);
  void (*setcrossingblocksignals)(iONode,Boolean);
  int (*getctcaddr1)(iONode);
  void (*setctcaddr1)(iONode,int);
  int (*getctcaddr2)(iONode);
  void (*setctcaddr2)(iONode,int);
  int (*getctcaddr3)(iONode);
  void (*setctcaddr3)(iONode,int);
  int (*getctcbus1)(iONode);
  void (*setctcbus1)(iONode,int);
  int (*getctcbus2)(iONode);
  void (*setctcbus2)(iONode,int);
  int (*getctcbus3)(iONode);
  void (*setctcbus3)(iONode,int);
  const char* (*getctciid1)(iONode);
  void (*setctciid1)(iONode,const char*);
  const char* (*getctciid2)(iONode);
  void (*setctciid2)(iONode,const char*);
  const char* (*getctciid3)(iONode);
  void (*setctciid3)(iONode,const char*);
  const char* (*getctcoutput1)(iONode);
  void (*setctcoutput1)(iONode,const char*);
  const char* (*getctcoutput2)(iONode);
  void (*setctcoutput2)(iONode,const char*);
  const char* (*getctcoutput3)(iONode);
  void (*setctcoutput3)(iONode,const char*);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getlocid)(iONode);
  void (*setlocid)(iONode,const char*);
  Boolean (*ismanual)(iONode);
  void (*setmanual)(iONode,Boolean);
  int (*getmaxkmh)(iONode);
  void (*setmaxkmh)(iONode,int);
  int (*getmaxlen)(iONode);
  void (*setmaxlen)(iONode,int);
  int (*getminlen)(iONode);
  void (*setminlen)(iONode,int);
  const char* (*getmodid)(iONode);
  void (*setmodid)(iONode,const char*);
  Boolean (*isnocommuter)(iONode);
  void (*setnocommuter)(iONode,Boolean);
  const char* (*getori)(iONode);
  void (*setori)(iONode,const char*);
  int (*getplacing)(iONode);
  void (*setplacing)(iONode,int);
  Boolean (*isreduceV)(iONode);
  void (*setreduceV)(iONode,Boolean);
  int (*getsga)(iONode);
  void (*setsga)(iONode,int);
  int (*getsgb)(iONode);
  void (*setsgb)(iONode,int);
  Boolean (*isshow)(iONode);
  void (*setshow)(iONode,Boolean);
  const char* (*getspeed)(iONode);
  void (*setspeed)(iONode,const char*);
  int (*getspeedpercent)(iONode);
  void (*setspeedpercent)(iONode,int);
  int (*getstatus)(iONode);
  void (*setstatus)(iONode,int);
  Boolean (*isswappost)(iONode);
  void (*setswappost)(iONode,Boolean);
  const char* (*gettypeperm)(iONode);
  void (*settypeperm)(iONode,const char*);
  int (*getx)(iONode);
  void (*setx)(iONode,int);
  int (*gety)(iONode);
  void (*sety)(iONode,int);
  int (*getz)(iONode);
  void (*setz)(iONode,int);
  iONode (*getswcmd)(iONode);
  iONode (*nextswcmd)(iONode,iONode);
  void (*setswcmd)(iONode,iONode);
  iONode (*getfbevent)(iONode);
  iONode (*nextfbevent)(iONode,iONode);
  void (*setfbevent)(iONode,iONode);
  iONode (*getactionctrl)(iONode);
  iONode (*nextactionctrl)(iONode,iONode);
  void (*setactionctrl)(iONode,iONode);
  iONode (*getincl)(iONode);
  iONode (*nextincl)(iONode,iONode);
  void (*setincl)(iONode,iONode);
  iONode (*getexcl)(iONode);
  iONode (*nextexcl)(iONode,iONode);
  void (*setexcl)(iONode,iONode);
  iONode (*getstcondition)(iONode);
  iONode (*nextstcondition)(iONode,iONode);
  void (*setstcondition)(iONode,iONode);
  iONode (*getspeedcondition)(iONode);
  iONode (*nextspeedcondition)(iONode,iONode);
  void (*setspeedcondition)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wRoute wRoute;

#ifdef __cplusplus
  }
#endif


#endif
