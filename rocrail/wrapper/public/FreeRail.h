/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Sep 16 2018 20:06:25)
  * Module: rocrail
  * Date: Sun Sep 16 20:06:26 2018
  */

#ifndef __WRAPPER_FreeRail_H
#define __WRAPPER_FreeRail_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wFreeRail {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isbackup)(iONode);
  void (*setbackup)(iONode,Boolean);
  const char* (*getbackuppath)(iONode);
  void (*setbackuppath)(iONode,const char*);
  Boolean (*iscreatemodplan)(iONode);
  void (*setcreatemodplan)(iONode,Boolean);
  const char* (*getdoneml)(iONode);
  void (*setdoneml)(iONode,const char*);
  const char* (*getdonkey)(iONode);
  void (*setdonkey)(iONode,const char*);
  const char* (*getdpiid)(iONode);
  void (*setdpiid)(iONode,const char*);
  const char* (*getfile)(iONode);
  void (*setfile)(iONode,const char*);
  Boolean (*isfsutf8)(iONode);
  void (*setfsutf8)(iONode,Boolean);
  const char* (*geticonpath)(iONode);
  void (*seticonpath)(iONode,const char*);
  const char* (*getimgpath)(iONode);
  void (*setimgpath)(iONode,const char*);
  const char* (*getissuepath)(iONode);
  void (*setissuepath)(iONode,const char*);
  const char* (*getkeypath)(iONode);
  void (*setkeypath)(iONode,const char*);
  const char* (*getlciid)(iONode);
  void (*setlciid)(iONode,const char*);
  const char* (*getlibpath)(iONode);
  void (*setlibpath)(iONode,const char*);
  const char* (*getlocs)(iONode);
  void (*setlocs)(iONode,const char*);
  Boolean (*isnodevcheck)(iONode);
  void (*setnodevcheck)(iONode,Boolean);
  const char* (*getoccupancy)(iONode);
  void (*setoccupancy)(iONode,const char*);
  const char* (*getplanfile)(iONode);
  void (*setplanfile)(iONode,const char*);
  Boolean (*ispoweroffonexit)(iONode);
  void (*setpoweroffonexit)(iONode,Boolean);
  Boolean (*ispoweronatinit)(iONode);
  void (*setpoweronatinit)(iONode,Boolean);
  const char* (*getptiid)(iONode);
  void (*setptiid)(iONode,const char*);
  Boolean (*isresetspfx)(iONode);
  void (*setresetspfx)(iONode,Boolean);
  Boolean (*isrunasroot)(iONode);
  void (*setrunasroot)(iONode,Boolean);
  const char* (*getsciid)(iONode);
  void (*setsciid)(iONode,const char*);
  const char* (*getscsensor)(iONode);
  void (*setscsensor)(iONode,const char*);
  Boolean (*isshutdownonexit)(iONode);
  void (*setshutdownonexit)(iONode,Boolean);
  const char* (*getsoundpath)(iONode);
  void (*setsoundpath)(iONode,const char*);
  const char* (*getsoundplayer)(iONode);
  void (*setsoundplayer)(iONode,const char*);
  Boolean (*issoundplayerlocation)(iONode);
  void (*setsoundplayerlocation)(iONode,Boolean);
  const char* (*getsviid)(iONode);
  void (*setsviid)(iONode,const char*);
  const char* (*getweatherid)(iONode);
  void (*setweatherid)(iONode,const char*);
  iONode (*getr2rnet)(iONode);
  iONode (*nextr2rnet)(iONode,iONode);
  void (*setr2rnet)(iONode,iONode);
  iONode (*getjsmap)(iONode);
  iONode (*nextjsmap)(iONode,iONode);
  void (*setjsmap)(iONode,iONode);
  iONode (*getclock)(iONode);
  iONode (*nextclock)(iONode,iONode);
  void (*setclock)(iONode,iONode);
  iONode (*getSnmpService)(iONode);
  iONode (*nextSnmpService)(iONode,iONode);
  void (*setSnmpService)(iONode,iONode);
  iONode (*gethttp)(iONode);
  iONode (*nexthttp)(iONode,iONode);
  void (*sethttp)(iONode,iONode);
  iONode (*getservice)(iONode);
  iONode (*nextservice)(iONode,iONode);
  void (*setservice)(iONode,iONode);
  iONode (*getdevices)(iONode);
  iONode (*nextdevices)(iONode,iONode);
  void (*setdevices)(iONode,iONode);
  iONode (*gettrace)(iONode);
  iONode (*nexttrace)(iONode,iONode);
  void (*settrace)(iONode,iONode);
  iONode (*getdigint)(iONode);
  iONode (*nextdigint)(iONode,iONode);
  void (*setdigint)(iONode,iONode);
  iONode (*gettcp)(iONode);
  iONode (*nexttcp)(iONode,iONode);
  void (*settcp)(iONode,iONode);
  iONode (*getsrcpcon)(iONode);
  iONode (*nextsrcpcon)(iONode,iONode);
  void (*setsrcpcon)(iONode,iONode);
  iONode (*getctrl)(iONode);
  iONode (*nextctrl)(iONode,iONode);
  void (*setctrl)(iONode,iONode);
  iONode (*getanaopt)(iONode);
  iONode (*nextanaopt)(iONode,iONode);
  void (*setanaopt)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wFreeRail wFreeRail;

#ifdef __cplusplus
  }
#endif


#endif
