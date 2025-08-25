/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_LocoSetup_H
#define __WRAPPER_LocoSetup_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wLocoSetup {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getacceleration)(iONode);
  void (*setacceleration)(iONode,int);
  int (*getdeceleration)(iONode);
  void (*setdeceleration)(iONode,int);
  int (*getnrpulses)(iONode);
  void (*setnrpulses)(iONode,int);
  double (*getscale)(iONode);
  void (*setscale)(iONode,double);
  double (*getwheeldiameter)(iONode);
  void (*setwheeldiameter)(iONode,double);
  Boolean (*dump)(iONode node);
};

extern struct __wLocoSetup wLocoSetup;

#ifdef __cplusplus
  }
#endif


#endif
