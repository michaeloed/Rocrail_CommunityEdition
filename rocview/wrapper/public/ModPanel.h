/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#ifndef __WRAPPER_ModPanel_H
#define __WRAPPER_ModPanel_H

#include "rocview/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wModPanel {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getblue)(iONode);
  void (*setblue)(iONode,int);
  int (*getcx)(iONode);
  void (*setcx)(iONode,int);
  int (*getcy)(iONode);
  void (*setcy)(iONode,int);
  int (*getgreen)(iONode);
  void (*setgreen)(iONode,int);
  int (*getred)(iONode);
  void (*setred)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wModPanel wModPanel;

#ifdef __cplusplus
  }
#endif


#endif
