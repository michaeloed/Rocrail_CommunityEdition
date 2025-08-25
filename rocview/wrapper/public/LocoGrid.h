/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#ifndef __WRAPPER_LocoGrid_H
#define __WRAPPER_LocoGrid_H

#include "rocview/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wLocoGrid {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getsortcol)(iONode);
  void (*setsortcol)(iONode,int);
  Boolean (*issortinv)(iONode);
  void (*setsortinv)(iONode,Boolean);
  iONode (*getcolpos)(iONode);
  iONode (*nextcolpos)(iONode,iONode);
  void (*setcolpos)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wLocoGrid wLocoGrid;

#ifdef __cplusplus
  }
#endif


#endif
