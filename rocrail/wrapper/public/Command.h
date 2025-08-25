/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Command_H
#define __WRAPPER_Command_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wCommand {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* fbmods;
  const char* (*getarg)(iONode);
  void (*setarg)(iONode,const char*);
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  const char* (*getserver)(iONode);
  void (*setserver)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wCommand wCommand;

#ifdef __cplusplus
  }
#endif


#endif
