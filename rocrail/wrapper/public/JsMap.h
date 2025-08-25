/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_JsMap_H
#define __WRAPPER_JsMap_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wJsMap {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getf1)(iONode);
  void (*setf1)(iONode,int);
  int (*getf10)(iONode);
  void (*setf10)(iONode,int);
  int (*getf11)(iONode);
  void (*setf11)(iONode,int);
  int (*getf12)(iONode);
  void (*setf12)(iONode,int);
  int (*getf2)(iONode);
  void (*setf2)(iONode,int);
  int (*getf3)(iONode);
  void (*setf3)(iONode,int);
  int (*getf4)(iONode);
  void (*setf4)(iONode,int);
  int (*getf5)(iONode);
  void (*setf5)(iONode,int);
  int (*getf6)(iONode);
  void (*setf6)(iONode,int);
  int (*getf7)(iONode);
  void (*setf7)(iONode,int);
  int (*getf8)(iONode);
  void (*setf8)(iONode,int);
  int (*getf9)(iONode);
  void (*setf9)(iONode,int);
  int (*getleftright)(iONode);
  void (*setleftright)(iONode,int);
  int (*getlight)(iONode);
  void (*setlight)(iONode,int);
  int (*getpoweroff)(iONode);
  void (*setpoweroff)(iONode,int);
  int (*getpoweron)(iONode);
  void (*setpoweron)(iONode,int);
  int (*getrepeat)(iONode);
  void (*setrepeat)(iONode,int);
  int (*getreverse)(iONode);
  void (*setreverse)(iONode,int);
  int (*getselect)(iONode);
  void (*setselect)(iONode,int);
  int (*getstep)(iONode);
  void (*setstep)(iONode,int);
  int (*getstop)(iONode);
  void (*setstop)(iONode,int);
  int (*getupdown)(iONode);
  void (*setupdown)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wJsMap wJsMap;

#ifdef __cplusplus
  }
#endif


#endif
