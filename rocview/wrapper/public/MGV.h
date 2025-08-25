/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:52 2018
  */

#ifndef __WRAPPER_MGV_H
#define __WRAPPER_MGV_H

#include "rocview/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wMGV {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getaddr1)(iONode);
  void (*setaddr1)(iONode,int);
  int (*getaddr2)(iONode);
  void (*setaddr2)(iONode,int);
  int (*getaddr3)(iONode);
  void (*setaddr3)(iONode,int);
  int (*getaddr4)(iONode);
  void (*setaddr4)(iONode,int);
  int (*getbus)(iONode);
  void (*setbus)(iONode,int);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  int (*getport1)(iONode);
  void (*setport1)(iONode,int);
  int (*getport2)(iONode);
  void (*setport2)(iONode,int);
  int (*getport3)(iONode);
  void (*setport3)(iONode,int);
  int (*getport4)(iONode);
  void (*setport4)(iONode,int);
  Boolean (*issinglegate)(iONode);
  void (*setsinglegate)(iONode,Boolean);
  iONode (*getmgvservo)(iONode);
  iONode (*nextmgvservo)(iONode,iONode);
  void (*setmgvservo)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wMGV wMGV;

#ifdef __cplusplus
  }
#endif


#endif
