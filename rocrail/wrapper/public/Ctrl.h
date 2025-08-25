/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Ctrl_H
#define __WRAPPER_Ctrl_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wCtrl {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isactiontimer60)(iONode);
  void (*setactiontimer60)(iONode,Boolean);
  Boolean (*isallowzerothrottleid)(iONode);
  void (*setallowzerothrottleid)(iONode,Boolean);
  int (*getblockinitpause)(iONode);
  void (*setblockinitpause)(iONode,int);
  Boolean (*isclosenoevents)(iONode);
  void (*setclosenoevents)(iONode,Boolean);
  Boolean (*iscloseonghost)(iONode);
  void (*setcloseonghost)(iONode,Boolean);
  Boolean (*iscreateguestonbidi)(iONode);
  void (*setcreateguestonbidi)(iONode,Boolean);
  const char* (*getdefaspect)(iONode);
  void (*setdefaspect)(iONode,const char*);
  Boolean (*isdisableblockwait4gomanual)(iONode);
  void (*setdisableblockwait4gomanual)(iONode,Boolean);
  Boolean (*isdisablerouteVreduce)(iONode);
  void (*setdisablerouteVreduce)(iONode,Boolean);
  Boolean (*isdisablesteal)(iONode);
  void (*setdisablesteal)(iONode,Boolean);
  Boolean (*isebreakatghost)(iONode);
  void (*setebreakatghost)(iONode,Boolean);
  Boolean (*isebreakforceunlock)(iONode);
  void (*setebreakforceunlock)(iONode,Boolean);
  Boolean (*isenableanalyzer)(iONode);
  void (*setenableanalyzer)(iONode,Boolean);
  Boolean (*isenableswfb)(iONode);
  void (*setenableswfb)(iONode,Boolean);
  int (*geteventtimeout)(iONode);
  void (*seteventtimeout)(iONode,int);
  Boolean (*isgreenaspect)(iONode);
  void (*setgreenaspect)(iONode,Boolean);
  int (*getignevt)(iONode);
  void (*setignevt)(iONode,int);
  int (*getinitfieldpause)(iONode);
  void (*setinitfieldpause)(iONode,int);
  Boolean (*isinitfieldpower)(iONode);
  void (*setinitfieldpower)(iONode,Boolean);
  Boolean (*iskeepghost)(iONode);
  void (*setkeepghost)(iONode,Boolean);
  Boolean (*isloccnfg)(iONode);
  void (*setloccnfg)(iONode,Boolean);
  int (*getlocostartgap)(iONode);
  void (*setlocostartgap)(iONode,int);
  int (*getminbklc)(iONode);
  void (*setminbklc)(iONode,int);
  Boolean (*ispoweroffatghost)(iONode);
  void (*setpoweroffatghost)(iONode,Boolean);
  Boolean (*ispoweroffatreset)(iONode);
  void (*setpoweroffatreset)(iONode,Boolean);
  Boolean (*ispoweroffonidentmismatch)(iONode);
  void (*setpoweroffonidentmismatch)(iONode,Boolean);
  Boolean (*isredirecttomaster)(iONode);
  void (*setredirecttomaster)(iONode,Boolean);
  Boolean (*isreleaseonidle)(iONode);
  void (*setreleaseonidle)(iONode,Boolean);
  Boolean (*isrestoreschedule)(iONode);
  void (*setrestoreschedule)(iONode,Boolean);
  int (*getrouteswtime)(iONode);
  void (*setrouteswtime)(iONode,int);
  int (*getsavepostime)(iONode);
  void (*setsavepostime)(iONode,int);
  Boolean (*issecondnextblock)(iONode);
  void (*setsecondnextblock)(iONode,Boolean);
  int (*getseed)(iONode);
  void (*setseed)(iONode,int);
  Boolean (*isselectshortestblock)(iONode);
  void (*setselectshortestblock)(iONode,Boolean);
  int (*getsemaphorewait)(iONode);
  void (*setsemaphorewait)(iONode,int);
  Boolean (*issgevents)(iONode);
  void (*setsgevents)(iONode,Boolean);
  int (*getsignalreset)(iONode);
  void (*setsignalreset)(iONode,int);
  int (*getsignalwait)(iONode);
  void (*setsignalwait)(iONode,int);
  Boolean (*isskipsetsg)(iONode);
  void (*setskipsetsg)(iONode,Boolean);
  Boolean (*isskipsetsw)(iONode);
  void (*setskipsetsw)(iONode,Boolean);
  Boolean (*isstopatin4gomanual)(iONode);
  void (*setstopatin4gomanual)(iONode,Boolean);
  Boolean (*isstopnonecommuter)(iONode);
  void (*setstopnonecommuter)(iONode,Boolean);
  int (*getswtimeout)(iONode);
  void (*setswtimeout)(iONode,int);
  Boolean (*issyncroutes)(iONode);
  void (*setsyncroutes)(iONode,Boolean);
  int (*getsyncroutetimeout)(iONode);
  void (*setsyncroutetimeout)(iONode,int);
  Boolean (*istimedsensors)(iONode);
  void (*settimedsensors)(iONode,Boolean);
  Boolean (*isusebicom)(iONode);
  void (*setusebicom)(iONode,Boolean);
  Boolean (*isusebididir)(iONode);
  void (*setusebididir)(iONode,Boolean);
  Boolean (*isuseident)(iONode);
  void (*setuseident)(iONode,Boolean);
  Boolean (*isuseonlyfirstident)(iONode);
  void (*setuseonlyfirstident)(iONode,Boolean);
  Boolean (*isuserandomrate)(iONode);
  void (*setuserandomrate)(iONode,Boolean);
  Boolean (*isv0atpoweron)(iONode);
  void (*setv0atpoweron)(iONode,Boolean);
  Boolean (*isv0onebreak)(iONode);
  void (*setv0onebreak)(iONode,Boolean);
  int (*getvirtualtimer)(iONode);
  void (*setvirtualtimer)(iONode,int);
  Boolean (*isweather)(iONode);
  void (*setweather)(iONode,Boolean);
  Boolean (*dump)(iONode node);
};

extern struct __wCtrl wCtrl;

#ifdef __cplusplus
  }
#endif


#endif
