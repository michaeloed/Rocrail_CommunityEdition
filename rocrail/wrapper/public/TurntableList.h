/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_TurntableList_H
#define __WRAPPER_TurntableList_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wTurntableList {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  iONode (*gettt)(iONode);
  iONode (*nexttt)(iONode,iONode);
  void (*settt)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wTurntableList wTurntableList;

#ifdef __cplusplus
  }
#endif


#endif
