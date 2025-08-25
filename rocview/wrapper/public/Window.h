/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#ifndef __WRAPPER_Window_H
#define __WRAPPER_Window_H

#include "rocview/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wWindow {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getcx)(iONode);
  void (*setcx)(iONode,int);
  int (*getcy)(iONode);
  void (*setcy)(iONode,int);
  int (*getx)(iONode);
  void (*setx)(iONode,int);
  int (*getxtp)(iONode);
  void (*setxtp)(iONode,int);
  int (*gety)(iONode);
  void (*sety)(iONode,int);
  int (*getytp)(iONode);
  void (*setytp)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wWindow wWindow;

#ifdef __cplusplus
  }
#endif


#endif
