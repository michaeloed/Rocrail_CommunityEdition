/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_Block_H
#define __WRAPPER_Block_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wBlock {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* bsm;
  const char* bsp;
  const char* classadd;
  const char* classdel;
  const char* classset;
  const char* closed;
  const char* commuter_no;
  const char* commuter_only;
  const char* commuter_yes;
  const char* cruise;
  const char* ghost;
  int incline_down;
  int incline_none;
  int incline_up;
  const char* loc;
  const char* max;
  const char* mid;
  const char* min;
  const char* nop;
  const char* open;
  const char* percent;
  const char* resetfifo;
  const char* resetwc;
  const char* shortcut;
  const char* shortcutcleared;
  const char* type_goods;
  const char* type_ice;
  const char* type_light;
  const char* type_lightgoods;
  const char* type_local;
  const char* type_none;
  const char* type_post;
  const char* type_regional;
  const char* type_shunting;
  const char* type_turntable;
  const char* wait_fixed;
  const char* wait_loc;
  const char* wait_none;
  const char* wait_random;
  Boolean (*isacceptghost)(iONode);
  void (*setacceptghost)(iONode,Boolean);
  Boolean (*isacceptident)(iONode);
  void (*setacceptident)(iONode,Boolean);
  int (*getaddr)(iONode);
  void (*setaddr)(iONode,int);
  Boolean (*isallowbbt)(iONode);
  void (*setallowbbt)(iONode,Boolean);
  Boolean (*isallowchgdir)(iONode);
  void (*setallowchgdir)(iONode,Boolean);
  Boolean (*isblankatredsignal)(iONode);
  void (*setblankatredsignal)(iONode,Boolean);
  Boolean (*isblankatredsignalR)(iONode);
  void (*setblankatredsignalR)(iONode,Boolean);
  const char* (*getclass)(iONode);
  void (*setclass)(iONode,const char*);
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  const char* (*getcommuter)(iONode);
  void (*setcommuter)(iONode,const char*);
  int (*getdepartdelay)(iONode);
  void (*setdepartdelay)(iONode,int);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  Boolean (*iselectrified)(iONode);
  void (*setelectrified)(iONode,Boolean);
  Boolean (*isentering)(iONode);
  void (*setentering)(iONode,Boolean);
  int (*getevttimer)(iONode);
  void (*setevttimer)(iONode,int);
  int (*getevttimer2)(iONode);
  void (*setevttimer2)(iONode,int);
  const char* (*getexitspeed)(iONode);
  void (*setexitspeed)(iONode,const char*);
  int (*getexitspeedpercent)(iONode);
  void (*setexitspeedpercent)(iONode,int);
  Boolean (*isextstop)(iONode);
  void (*setextstop)(iONode,Boolean);
  const char* (*getfifoids)(iONode);
  void (*setfifoids)(iONode,const char*);
  int (*getfifosize)(iONode);
  void (*setfifosize)(iONode,int);
  Boolean (*isforceblocktimer)(iONode);
  void (*setforceblocktimer)(iONode,Boolean);
  Boolean (*isfreeblockonenter)(iONode);
  void (*setfreeblockonenter)(iONode,Boolean);
  Boolean (*isgomanual)(iONode);
  void (*setgomanual)(iONode,Boolean);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  int (*getincline)(iONode);
  void (*setincline)(iONode,int);
  int (*getlen)(iONode);
  void (*setlen)(iONode,int);
  const char* (*getlocid)(iONode);
  void (*setlocid)(iONode,const char*);
  Boolean (*ismainline)(iONode);
  void (*setmainline)(iONode,Boolean);
  const char* (*getmanagerid)(iONode);
  void (*setmanagerid)(iONode,const char*);
  Boolean (*ismanual)(iONode);
  void (*setmanual)(iONode,Boolean);
  Boolean (*ismastercmd)(iONode);
  void (*setmastercmd)(iONode,Boolean);
  const char* (*getmasterid)(iONode);
  void (*setmasterid)(iONode,const char*);
  int (*getmaxkmh)(iONode);
  void (*setmaxkmh)(iONode,int);
  int (*getmaxwaittime)(iONode);
  void (*setmaxwaittime)(iONode,int);
  int (*getminwaittime)(iONode);
  void (*setminwaittime)(iONode,int);
  int (*getmvdistance)(iONode);
  void (*setmvdistance)(iONode,int);
  Boolean (*ismvmph)(iONode);
  void (*setmvmph)(iONode,Boolean);
  int (*getmvscale)(iONode);
  void (*setmvscale)(iONode,int);
  int (*getport)(iONode);
  void (*setport)(iONode,int);
  Boolean (*ispower)(iONode);
  void (*setpower)(iONode,Boolean);
  const char* (*getprevstate)(iONode);
  void (*setprevstate)(iONode,const char*);
  int (*getrandomrate)(iONode);
  void (*setrandomrate)(iONode,int);
  Boolean (*isremote)(iONode);
  void (*setremote)(iONode,Boolean);
  Boolean (*isreserved)(iONode);
  void (*setreserved)(iONode,Boolean);
  const char* (*getrrid)(iONode);
  void (*setrrid)(iONode,const char*);
  Boolean (*isselectshortestblock)(iONode);
  void (*setselectshortestblock)(iONode,Boolean);
  const char* (*getsignal)(iONode);
  void (*setsignal)(iONode,const char*);
  const char* (*getsignalR)(iONode);
  void (*setsignalR)(iONode,const char*);
  const char* (*getslaveblocks)(iONode);
  void (*setslaveblocks)(iONode,const char*);
  Boolean (*issleeponclosed)(iONode);
  void (*setsleeponclosed)(iONode,Boolean);
  Boolean (*issmallsymbol)(iONode);
  void (*setsmallsymbol)(iONode,Boolean);
  const char* (*getspeed)(iONode);
  void (*setspeed)(iONode,const char*);
  int (*getspeedpercent)(iONode);
  void (*setspeedpercent)(iONode,int);
  const char* (*getstate)(iONode);
  void (*setstate)(iONode,const char*);
  const char* (*getstatesignal)(iONode);
  void (*setstatesignal)(iONode,const char*);
  const char* (*getstopspeed)(iONode);
  void (*setstopspeed)(iONode,const char*);
  Boolean (*istd)(iONode);
  void (*settd)(iONode,Boolean);
  Boolean (*isterminalstation)(iONode);
  void (*setterminalstation)(iONode,Boolean);
  const char* (*getttid)(iONode);
  void (*setttid)(iONode,const char*);
  const char* (*getturnoutstolock)(iONode);
  void (*setturnoutstolock)(iONode,const char*);
  const char* (*gettype)(iONode);
  void (*settype)(iONode,const char*);
  const char* (*gettypeperm)(iONode);
  void (*settypeperm)(iONode,const char*);
  Boolean (*isupdateenterside)(iONode);
  void (*setupdateenterside)(iONode,Boolean);
  Boolean (*isvirtual)(iONode);
  void (*setvirtual)(iONode,Boolean);
  Boolean (*iswait)(iONode);
  void (*setwait)(iONode,Boolean);
  const char* (*getwaitmode)(iONode);
  void (*setwaitmode)(iONode,const char*);
  int (*getwaittime)(iONode);
  void (*setwaittime)(iONode,int);
  const char* (*getwsignal)(iONode);
  void (*setwsignal)(iONode,const char*);
  const char* (*getwsignalR)(iONode);
  void (*setwsignalR)(iONode,const char*);
  int (*getx)(iONode);
  void (*setx)(iONode,int);
  int (*gety)(iONode);
  void (*sety)(iONode,int);
  int (*getz)(iONode);
  void (*setz)(iONode,int);
  iONode (*getincl)(iONode);
  iONode (*nextincl)(iONode,iONode);
  void (*setincl)(iONode,iONode);
  iONode (*getexcl)(iONode);
  iONode (*nextexcl)(iONode,iONode);
  void (*setexcl)(iONode,iONode);
  iONode (*getfbevent)(iONode);
  iONode (*nextfbevent)(iONode,iONode);
  void (*setfbevent)(iONode,iONode);
  iONode (*getactionctrl)(iONode);
  iONode (*nextactionctrl)(iONode,iONode);
  void (*setactionctrl)(iONode,iONode);
  iONode (*getspeedcondition)(iONode);
  iONode (*nextspeedcondition)(iONode,iONode);
  void (*setspeedcondition)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wBlock wBlock;

#ifdef __cplusplus
  }
#endif


#endif
