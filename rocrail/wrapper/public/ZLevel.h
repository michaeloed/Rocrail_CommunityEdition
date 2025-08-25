/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_ZLevel_H
#define __WRAPPER_ZLevel_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wZLevel {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isactive)(iONode);
  void (*setactive)(iONode,Boolean);
  const char* (*getmodid)(iONode);
  void (*setmodid)(iONode,const char*);
  int (*getmodnr)(iONode);
  void (*setmodnr)(iONode,int);
  int (*getmodviewcx)(iONode);
  void (*setmodviewcx)(iONode,int);
  int (*getmodviewcy)(iONode);
  void (*setmodviewcy)(iONode,int);
  int (*getmodviewx)(iONode);
  void (*setmodviewx)(iONode,int);
  int (*getmodviewy)(iONode);
  void (*setmodviewy)(iONode,int);
  const char* (*gettitle)(iONode);
  void (*settitle)(iONode,const char*);
  int (*getz)(iONode);
  void (*setz)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wZLevel wZLevel;

#ifdef __cplusplus
  }
#endif


#endif
