/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_DCC232_H
#define __WRAPPER_DCC232_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wDCC232 {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isfastcvget)(iONode);
  void (*setfastcvget)(iONode,Boolean);
  Boolean (*isinversedsr)(iONode);
  void (*setinversedsr)(iONode,Boolean);
  const char* (*getport)(iONode);
  void (*setport)(iONode,const char*);
  Boolean (*ispurge)(iONode);
  void (*setpurge)(iONode,Boolean);
  int (*getpurgetime)(iONode);
  void (*setpurgetime)(iONode,int);
  Boolean (*isshortcut)(iONode);
  void (*setshortcut)(iONode,Boolean);
  int (*getshortcutdelay)(iONode);
  void (*setshortcutdelay)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wDCC232 wDCC232;

#ifdef __cplusplus
  }
#endif


#endif
