/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Color_H
#define __WRAPPER_Color_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wColor {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getblue)(iONode);
  void (*setblue)(iONode,int);
  int (*getbrightness)(iONode);
  void (*setbrightness)(iONode,int);
  int (*getgreen)(iONode);
  void (*setgreen)(iONode,int);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  int (*getred)(iONode);
  void (*setred)(iONode,int);
  int (*getsaturation)(iONode);
  void (*setsaturation)(iONode,int);
  int (*getwhite)(iONode);
  void (*setwhite)(iONode,int);
  int (*getwhite2)(iONode);
  void (*setwhite2)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wColor wColor;

#ifdef __cplusplus
  }
#endif


#endif
