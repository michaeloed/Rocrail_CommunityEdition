/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_PortSetup_H
#define __WRAPPER_PortSetup_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wPortSetup {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getdelay)(iONode);
  void (*setdelay)(iONode,int);
  int (*geteventid)(iONode);
  void (*seteventid)(iONode,int);
  int (*geteventport)(iONode);
  void (*seteventport)(iONode,int);
  int (*getport)(iONode);
  void (*setport)(iONode,int);
  int (*getstate)(iONode);
  void (*setstate)(iONode,int);
  int (*gettype)(iONode);
  void (*settype)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wPortSetup wPortSetup;

#ifdef __cplusplus
  }
#endif


#endif
