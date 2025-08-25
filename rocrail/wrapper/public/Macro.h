/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Macro_H
#define __WRAPPER_Macro_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wMacro {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getclass)(iONode);
  void (*setclass)(iONode,int);
  int (*gethours)(iONode);
  void (*sethours)(iONode,int);
  int (*getminutes)(iONode);
  void (*setminutes)(iONode,int);
  int (*getnr)(iONode);
  void (*setnr)(iONode,int);
  int (*getrepeat)(iONode);
  void (*setrepeat)(iONode,int);
  int (*getslowdown)(iONode);
  void (*setslowdown)(iONode,int);
  int (*getuid)(iONode);
  void (*setuid)(iONode,int);
  int (*getwday)(iONode);
  void (*setwday)(iONode,int);
  iONode (*getmacroline)(iONode);
  iONode (*nextmacroline)(iONode,iONode);
  void (*setmacroline)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wMacro wMacro;

#ifdef __cplusplus
  }
#endif


#endif
