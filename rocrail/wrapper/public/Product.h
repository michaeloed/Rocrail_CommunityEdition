/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Product_H
#define __WRAPPER_Product_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wProduct {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getcid)(iONode);
  void (*setcid)(iONode,int);
  int (*getcidext)(iONode);
  void (*setcidext)(iONode,int);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  int (*getpid)(iONode);
  void (*setpid)(iONode,int);
  int (*getsid)(iONode);
  void (*setsid)(iONode,int);
  const char* (*geturl)(iONode);
  void (*seturl)(iONode,const char*);
  int (*getvid)(iONode);
  void (*setvid)(iONode,int);
  iONode (*getdescription)(iONode);
  iONode (*nextdescription)(iONode,iONode);
  void (*setdescription)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wProduct wProduct;

#ifdef __cplusplus
  }
#endif


#endif
