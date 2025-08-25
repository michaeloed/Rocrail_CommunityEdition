/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_Tour_H
#define __WRAPPER_Tour_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wTour {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  Boolean (*isrecycle)(iONode);
  void (*setrecycle)(iONode,Boolean);
  const char* (*getschedules)(iONode);
  void (*setschedules)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wTour wTour;

#ifdef __cplusplus
  }
#endif


#endif
