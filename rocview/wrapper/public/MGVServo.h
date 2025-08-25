/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:52 2018
  */

#ifndef __WRAPPER_MGVServo_H
#define __WRAPPER_MGVServo_H

#include "rocview/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wMGVServo {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getaddr)(iONode);
  void (*setaddr)(iONode,int);
  int (*getbounce)(iONode);
  void (*setbounce)(iONode,int);
  int (*getleftangle)(iONode);
  void (*setleftangle)(iONode,int);
  int (*getport)(iONode);
  void (*setport)(iONode,int);
  Boolean (*isrelay)(iONode);
  void (*setrelay)(iONode,Boolean);
  int (*getrightangle)(iONode);
  void (*setrightangle)(iONode,int);
  int (*getspeed)(iONode);
  void (*setspeed)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wMGVServo wMGVServo;

#ifdef __cplusplus
  }
#endif


#endif
