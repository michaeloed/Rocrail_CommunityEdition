/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_DDX_H
#define __WRAPPER_DDX_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wDDX {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isdcc)(iONode);
  void (*setdcc)(iONode,Boolean);
  Boolean (*isfastcvget)(iONode);
  void (*setfastcvget)(iONode,Boolean);
  Boolean (*isinversedsr)(iONode);
  void (*setinversedsr)(iONode,Boolean);
  Boolean (*ismmlongpause)(iONode);
  void (*setmmlongpause)(iONode,Boolean);
  Boolean (*ismotorola)(iONode);
  void (*setmotorola)(iONode,Boolean);
  Boolean (*ismotorolarefresh)(iONode);
  void (*setmotorolarefresh)(iONode,Boolean);
  const char* (*getport)(iONode);
  void (*setport)(iONode,const char*);
  const char* (*getportbase)(iONode);
  void (*setportbase)(iONode,const char*);
  Boolean (*isqueuecheck)(iONode);
  void (*setqueuecheck)(iONode,Boolean);
  Boolean (*isrealnmratiming)(iONode);
  void (*setrealnmratiming)(iONode,Boolean);
  int (*gets88b0modcnt)(iONode);
  void (*sets88b0modcnt)(iONode,int);
  int (*gets88b1modcnt)(iONode);
  void (*sets88b1modcnt)(iONode,int);
  int (*gets88b2modcnt)(iONode);
  void (*sets88b2modcnt)(iONode,int);
  int (*gets88b3modcnt)(iONode);
  void (*sets88b3modcnt)(iONode,int);
  int (*gets88busses)(iONode);
  void (*sets88busses)(iONode,int);
  int (*gets88clockscale)(iONode);
  void (*sets88clockscale)(iONode,int);
  const char* (*gets88port)(iONode);
  void (*sets88port)(iONode,const char*);
  int (*gets88refresh)(iONode);
  void (*sets88refresh)(iONode,int);
  Boolean (*isshortcutchecking)(iONode);
  void (*setshortcutchecking)(iONode,Boolean);
  int (*getshortcutdelay)(iONode);
  void (*setshortcutdelay)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wDDX wDDX;

#ifdef __cplusplus
  }
#endif


#endif
