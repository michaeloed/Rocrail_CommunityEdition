/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_SwitchList_H
#define __WRAPPER_SwitchList_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wSwitchList {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  iONode (*getsw)(iONode);
  iONode (*nextsw)(iONode,iONode);
  void (*setsw)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wSwitchList wSwitchList;

#ifdef __cplusplus
  }
#endif


#endif
