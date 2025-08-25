/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_SwitchCmd_H
#define __WRAPPER_SwitchCmd_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wSwitchCmd {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* cmd_track;
  Boolean (*isatfree)(iONode);
  void (*setatfree)(iONode,Boolean);
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  Boolean (*islock)(iONode);
  void (*setlock)(iONode,Boolean);
  Boolean (*isreduceV)(iONode);
  void (*setreduceV)(iONode,Boolean);
  int (*gettrack)(iONode);
  void (*settrack)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wSwitchCmd wSwitchCmd;

#ifdef __cplusplus
  }
#endif


#endif
