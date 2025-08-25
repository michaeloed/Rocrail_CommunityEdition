/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_JsEvent_H
#define __WRAPPER_JsEvent_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wJsEvent {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getdevice)(iONode);
  void (*setdevice)(iONode,int);
  int (*getmsec)(iONode);
  void (*setmsec)(iONode,int);
  int (*getnumber)(iONode);
  void (*setnumber)(iONode,int);
  int (*gettype)(iONode);
  void (*settype)(iONode,int);
  int (*getvalue)(iONode);
  void (*setvalue)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wJsEvent wJsEvent;

#ifdef __cplusplus
  }
#endif


#endif
