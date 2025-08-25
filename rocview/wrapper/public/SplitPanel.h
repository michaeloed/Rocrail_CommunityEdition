/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#ifndef __WRAPPER_SplitPanel_H
#define __WRAPPER_SplitPanel_H

#include "rocview/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wSplitPanel {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isdontwrap)(iONode);
  void (*setdontwrap)(iONode,Boolean);
  int (*getmain)(iONode);
  void (*setmain)(iONode,int);
  int (*getmsg)(iONode);
  void (*setmsg)(iONode,int);
  int (*getplan)(iONode);
  void (*setplan)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wSplitPanel wSplitPanel;

#ifdef __cplusplus
  }
#endif


#endif
