/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_CBus_H
#define __WRAPPER_CBus_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wCBus {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getcid)(iONode);
  void (*setcid)(iONode,int);
  Boolean (*iscommandack)(iONode);
  void (*setcommandack)(iONode,Boolean);
  Boolean (*isfastclock)(iONode);
  void (*setfastclock)(iONode,Boolean);
  int (*getfcaddr)(iONode);
  void (*setfcaddr)(iONode,int);
  int (*getfcnode)(iONode);
  void (*setfcnode)(iONode,int);
  Boolean (*isfonfof)(iONode);
  void (*setfonfof)(iONode,Boolean);
  Boolean (*isheartbeat)(iONode);
  void (*setheartbeat)(iONode,Boolean);
  int (*getheartbeatevent)(iONode);
  void (*setheartbeatevent)(iONode,int);
  int (*getloadertime)(iONode);
  void (*setloadertime)(iONode,int);
  int (*getpurgetime)(iONode);
  void (*setpurgetime)(iONode,int);
  Boolean (*isshortevents)(iONode);
  void (*setshortevents)(iONode,Boolean);
  Boolean (*isslotserver)(iONode);
  void (*setslotserver)(iONode,Boolean);
  int (*getsodaddr)(iONode);
  void (*setsodaddr)(iONode,int);
  iONode (*getcbnode)(iONode);
  iONode (*nextcbnode)(iONode,iONode);
  void (*setcbnode)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wCBus wCBus;

#ifdef __cplusplus
  }
#endif


#endif
