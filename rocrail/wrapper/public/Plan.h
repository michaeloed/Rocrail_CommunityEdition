/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Plan_H
#define __WRAPPER_Plan_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wPlan {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isdonkey)(iONode);
  void (*setdonkey)(iONode,Boolean);
  Boolean (*ishealthy)(iONode);
  void (*sethealthy)(iONode,Boolean);
  Boolean (*ismodplan)(iONode);
  void (*setmodplan)(iONode,Boolean);
  const char* (*getmodtitle)(iONode);
  void (*setmodtitle)(iONode,const char*);
  const char* (*getname)(iONode);
  void (*setname)(iONode,const char*);
  const char* (*getrocguiversion)(iONode);
  void (*setrocguiversion)(iONode,const char*);
  const char* (*getrocrailpwd)(iONode);
  void (*setrocrailpwd)(iONode,const char*);
  const char* (*getrocrailversion)(iONode);
  void (*setrocrailversion)(iONode,const char*);
  const char* (*getthemes)(iONode);
  void (*setthemes)(iONode,const char*);
  const char* (*gettitle)(iONode);
  void (*settitle)(iONode,const char*);
  iONode (*getdigint)(iONode);
  iONode (*nextdigint)(iONode,iONode);
  void (*setdigint)(iONode,iONode);
  iONode (*getsystem)(iONode);
  iONode (*nextsystem)(iONode,iONode);
  void (*setsystem)(iONode,iONode);
  iONode (*getweatherlist)(iONode);
  iONode (*nextweatherlist)(iONode,iONode);
  void (*setweatherlist)(iONode,iONode);
  iONode (*getzlevel)(iONode);
  iONode (*nextzlevel)(iONode,iONode);
  void (*setzlevel)(iONode,iONode);
  iONode (*getboosterlist)(iONode);
  iONode (*nextboosterlist)(iONode,iONode);
  void (*setboosterlist)(iONode,iONode);
  iONode (*getmv)(iONode);
  iONode (*nextmv)(iONode,iONode);
  void (*setmv)(iONode,iONode);
  iONode (*getswlist)(iONode);
  iONode (*nextswlist)(iONode,iONode);
  void (*setswlist)(iONode,iONode);
  iONode (*getsglist)(iONode);
  iONode (*nextsglist)(iONode,iONode);
  void (*setsglist)(iONode,iONode);
  iONode (*getcolist)(iONode);
  iONode (*nextcolist)(iONode,iONode);
  void (*setcolist)(iONode,iONode);
  iONode (*getfblist)(iONode);
  iONode (*nextfblist)(iONode,iONode);
  void (*setfblist)(iONode,iONode);
  iONode (*getlocationlist)(iONode);
  iONode (*nextlocationlist)(iONode,iONode);
  void (*setlocationlist)(iONode,iONode);
  iONode (*getsclist)(iONode);
  iONode (*nextsclist)(iONode,iONode);
  void (*setsclist)(iONode,iONode);
  iONode (*gettourlist)(iONode);
  iONode (*nexttourlist)(iONode,iONode);
  void (*settourlist)(iONode,iONode);
  iONode (*getbklist)(iONode);
  iONode (*nextbklist)(iONode,iONode);
  void (*setbklist)(iONode,iONode);
  iONode (*getsblist)(iONode);
  iONode (*nextsblist)(iONode,iONode);
  void (*setsblist)(iONode,iONode);
  iONode (*getlinklist)(iONode);
  iONode (*nextlinklist)(iONode,iONode);
  void (*setlinklist)(iONode,iONode);
  iONode (*getstlist)(iONode);
  iONode (*nextstlist)(iONode,iONode);
  void (*setstlist)(iONode,iONode);
  iONode (*gettklist)(iONode);
  iONode (*nexttklist)(iONode,iONode);
  void (*settklist)(iONode,iONode);
  iONode (*getttlist)(iONode);
  iONode (*nextttlist)(iONode,iONode);
  void (*setttlist)(iONode,iONode);
  iONode (*getdeclist)(iONode);
  iONode (*nextdeclist)(iONode,iONode);
  void (*setdeclist)(iONode,iONode);
  iONode (*getlclist)(iONode);
  iONode (*nextlclist)(iONode,iONode);
  void (*setlclist)(iONode,iONode);
  iONode (*getoperatorlist)(iONode);
  iONode (*nextoperatorlist)(iONode,iONode);
  void (*setoperatorlist)(iONode,iONode);
  iONode (*getcarlist)(iONode);
  iONode (*nextcarlist)(iONode,iONode);
  void (*setcarlist)(iONode,iONode);
  iONode (*getwaybilllist)(iONode);
  iONode (*nextwaybilllist)(iONode,iONode);
  void (*setwaybilllist)(iONode,iONode);
  iONode (*gettxlist)(iONode);
  iONode (*nexttxlist)(iONode,iONode);
  void (*settxlist)(iONode,iONode);
  iONode (*getaclist)(iONode);
  iONode (*nextaclist)(iONode,iONode);
  void (*setaclist)(iONode,iONode);
  iONode (*getseltablist)(iONode);
  iONode (*nextseltablist)(iONode,iONode);
  void (*setseltablist)(iONode,iONode);
  iONode (*getvrlist)(iONode);
  iONode (*nextvrlist)(iONode,iONode);
  void (*setvrlist)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wPlan wPlan;

#ifdef __cplusplus
  }
#endif


#endif
