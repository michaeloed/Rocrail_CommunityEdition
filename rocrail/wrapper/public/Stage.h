/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_Stage_H
#define __WRAPPER_Stage_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wStage {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* closed;
  const char* compress;
  const char* exitclosed;
  const char* exitopen;
  const char* open;
  const char* startwd;
  const char* stopwd;
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  int (*getdepartdelay)(iONode);
  void (*setdepartdelay)(iONode,int);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  Boolean (*iselectrified)(iONode);
  void (*setelectrified)(iONode,Boolean);
  Boolean (*isentering)(iONode);
  void (*setentering)(iONode,Boolean);
  const char* (*getentersignal)(iONode);
  void (*setentersignal)(iONode,const char*);
  const char* (*getexitsignal)(iONode);
  void (*setexitsignal)(iONode,const char*);
  const char* (*getexitspeed)(iONode);
  void (*setexitspeed)(iONode,const char*);
  int (*getexitspeedpercent)(iONode);
  void (*setexitspeedpercent)(iONode,int);
  const char* (*getexitstate)(iONode);
  void (*setexitstate)(iONode,const char*);
  const char* (*getfbenterid)(iONode);
  void (*setfbenterid)(iONode,const char*);
  int (*getgap)(iONode);
  void (*setgap)(iONode,int);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  Boolean (*isinatlen)(iONode);
  void (*setinatlen)(iONode,Boolean);
  const char* (*getlocid)(iONode);
  void (*setlocid)(iONode,const char*);
  int (*getmaxwaittime)(iONode);
  void (*setmaxwaittime)(iONode,int);
  int (*getminocc)(iONode);
  void (*setminocc)(iONode,int);
  int (*getminwaittime)(iONode);
  void (*setminwaittime)(iONode,int);
  int (*getrandomrate)(iONode);
  void (*setrandomrate)(iONode,int);
  Boolean (*isremote)(iONode);
  void (*setremote)(iONode,Boolean);
  Boolean (*isreserved)(iONode);
  void (*setreserved)(iONode,Boolean);
  const char* (*getrrid)(iONode);
  void (*setrrid)(iONode,const char*);
  const char* (*getsecid)(iONode);
  void (*setsecid)(iONode,const char*);
  int (*getslen)(iONode);
  void (*setslen)(iONode,int);
  int (*getspeedpercent)(iONode);
  void (*setspeedpercent)(iONode,int);
  const char* (*getstate)(iONode);
  void (*setstate)(iONode,const char*);
  const char* (*getstopspeed)(iONode);
  void (*setstopspeed)(iONode,const char*);
  Boolean (*issuitswell)(iONode);
  void (*setsuitswell)(iONode,Boolean);
  int (*gettotallength)(iONode);
  void (*settotallength)(iONode,int);
  int (*gettotalsections)(iONode);
  void (*settotalsections)(iONode,int);
  Boolean (*isusewd)(iONode);
  void (*setusewd)(iONode,Boolean);
  const char* (*getwaitmode)(iONode);
  void (*setwaitmode)(iONode,const char*);
  int (*getwaittime)(iONode);
  void (*setwaittime)(iONode,int);
  int (*getx)(iONode);
  void (*setx)(iONode,int);
  int (*gety)(iONode);
  void (*sety)(iONode,int);
  int (*getz)(iONode);
  void (*setz)(iONode,int);
  iONode (*getsection)(iONode);
  iONode (*nextsection)(iONode,iONode);
  void (*setsection)(iONode,iONode);
  iONode (*getactionctrl)(iONode);
  iONode (*nextactionctrl)(iONode,iONode);
  void (*setactionctrl)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wStage wStage;

#ifdef __cplusplus
  }
#endif


#endif
