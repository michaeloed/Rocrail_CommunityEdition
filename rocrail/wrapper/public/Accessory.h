/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Accessory_H
#define __WRAPPER_Accessory_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wAccessory {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isaccevent)(iONode);
  void (*setaccevent)(iONode,Boolean);
  int (*getdevid)(iONode);
  void (*setdevid)(iONode,int);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  int (*getnodenr)(iONode);
  void (*setnodenr)(iONode,int);
  const char* (*getstate)(iONode);
  void (*setstate)(iONode,const char*);
  int (*getval1)(iONode);
  void (*setval1)(iONode,int);
  int (*getval2)(iONode);
  void (*setval2)(iONode,int);
  int (*getval3)(iONode);
  void (*setval3)(iONode,int);
  int (*getval4)(iONode);
  void (*setval4)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wAccessory wAccessory;

#ifdef __cplusplus
  }
#endif


#endif
