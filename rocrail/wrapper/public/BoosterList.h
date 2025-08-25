/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_BoosterList_H
#define __WRAPPER_BoosterList_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wBoosterList {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  iONode (*getbooster)(iONode);
  iONode (*nextbooster)(iONode,iONode);
  void (*setbooster)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wBoosterList wBoosterList;

#ifdef __cplusplus
  }
#endif


#endif
