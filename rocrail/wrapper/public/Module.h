/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Module_H
#define __WRAPPER_Module_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wModule {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* cmd_connect;
  const char* cmd_east;
  const char* cmd_move;
  const char* cmd_north;
  const char* cmd_south;
  const char* cmd_state;
  const char* cmd_west;
  const char* state_normal;
  const char* state_shortcut;
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  int (*getcx)(iONode);
  void (*setcx)(iONode,int);
  int (*getcy)(iONode);
  void (*setcy)(iONode,int);
  const char* (*getfilename)(iONode);
  void (*setfilename)(iONode,const char*);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getidprefix)(iONode);
  void (*setidprefix)(iONode,const char*);
  int (*getnr)(iONode);
  void (*setnr)(iONode,int);
  int (*getrotation)(iONode);
  void (*setrotation)(iONode,int);
  const char* (*getstate)(iONode);
  void (*setstate)(iONode,const char*);
  const char* (*gettitle)(iONode);
  void (*settitle)(iONode,const char*);
  int (*getx)(iONode);
  void (*setx)(iONode,int);
  int (*gety)(iONode);
  void (*sety)(iONode,int);
  iONode (*getconnection)(iONode);
  iONode (*nextconnection)(iONode,iONode);
  void (*setconnection)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wModule wModule;

#ifdef __cplusplus
  }
#endif


#endif
