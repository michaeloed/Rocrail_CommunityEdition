/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_ChannelSetup_H
#define __WRAPPER_ChannelSetup_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wChannelSetup {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getchannel)(iONode);
  void (*setchannel)(iONode,int);
  int (*getdelay)(iONode);
  void (*setdelay)(iONode,int);
  int (*getoffpos)(iONode);
  void (*setoffpos)(iONode,int);
  int (*getoffsteps)(iONode);
  void (*setoffsteps)(iONode,int);
  int (*getonpos)(iONode);
  void (*setonpos)(iONode,int);
  int (*getonsteps)(iONode);
  void (*setonsteps)(iONode,int);
  int (*getoptions)(iONode);
  void (*setoptions)(iONode,int);
  int (*getstate)(iONode);
  void (*setstate)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wChannelSetup wChannelSetup;

#ifdef __cplusplus
  }
#endif


#endif
