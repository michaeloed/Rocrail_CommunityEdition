/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_CBusNodeEvent_H
#define __WRAPPER_CBusNodeEvent_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wCBusNodeEvent {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getaddr)(iONode);
  void (*setaddr)(iONode,int);
  int (*getevnr)(iONode);
  void (*setevnr)(iONode,int);
  int (*getevval)(iONode);
  void (*setevval)(iONode,int);
  int (*getnodenr)(iONode);
  void (*setnodenr)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wCBusNodeEvent wCBusNodeEvent;

#ifdef __cplusplus
  }
#endif


#endif
