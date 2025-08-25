/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_LocoNet_H
#define __WRAPPER_LocoNet_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wLocoNet {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* cs_db150;
  const char* cs_dcs100;
  const char* cs_dcs50;
  const char* cs_ibcom;
  const char* cs_intellibox;
  const char* cs_rocrail;
  Boolean (*isGBM16xn)(iONode);
  void (*setGBM16xn)(iONode,Boolean);
  const char* (*getcmdstn)(iONode);
  void (*setcmdstn)(iONode,const char*);
  Boolean (*isignorepowercmds)(iONode);
  void (*setignorepowercmds)(iONode,Boolean);
  Boolean (*ismonitor)(iONode);
  void (*setmonitor)(iONode,Boolean);
  int (*getpurgetime)(iONode);
  void (*setpurgetime)(iONode,int);
  int (*getreportaddr)(iONode);
  void (*setreportaddr)(iONode,int);
  Boolean (*isresetlissy)(iONode);
  void (*setresetlissy)(iONode,Boolean);
  Boolean (*issensorquery)(iONode);
  void (*setsensorquery)(iONode,Boolean);
  Boolean (*isslotping)(iONode);
  void (*setslotping)(iONode,Boolean);
  int (*getslots)(iONode);
  void (*setslots)(iONode,int);
  Boolean (*isswack)(iONode);
  void (*setswack)(iONode,Boolean);
  int (*getswretry)(iONode);
  void (*setswretry)(iONode,int);
  int (*getswsleep)(iONode);
  void (*setswsleep)(iONode,int);
  Boolean (*issyncfc)(iONode);
  void (*setsyncfc)(iONode,Boolean);
  Boolean (*isusedouble)(iONode);
  void (*setusedouble)(iONode,Boolean);
  Boolean (*isusefc)(iONode);
  void (*setusefc)(iONode,Boolean);
  Boolean (*isuseidle)(iONode);
  void (*setuseidle)(iONode,Boolean);
  Boolean (*isuseseq)(iONode);
  void (*setuseseq)(iONode,Boolean);
  iONode (*getoptions)(iONode);
  iONode (*nextoptions)(iONode,iONode);
  void (*setoptions)(iONode,iONode);
  iONode (*getslotserver)(iONode);
  iONode (*nextslotserver)(iONode,iONode);
  void (*setslotserver)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wLocoNet wLocoNet;

#ifdef __cplusplus
  }
#endif


#endif
