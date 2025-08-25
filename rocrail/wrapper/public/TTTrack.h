/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_TTTrack_H
#define __WRAPPER_TTTrack_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wTTTrack {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getbkid)(iONode);
  void (*setbkid)(iONode,const char*);
  int (*getdecnr)(iONode);
  void (*setdecnr)(iONode,int);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  int (*getnr)(iONode);
  void (*setnr)(iONode,int);
  int (*getoppositetrack)(iONode);
  void (*setoppositetrack)(iONode,int);
  Boolean (*ispolarization)(iONode);
  void (*setpolarization)(iONode,Boolean);
  const char* (*getposfb)(iONode);
  void (*setposfb)(iONode,const char*);
  Boolean (*isshow)(iONode);
  void (*setshow)(iONode,Boolean);
  Boolean (*isstate)(iONode);
  void (*setstate)(iONode,Boolean);
  Boolean (*dump)(iONode node);
};

extern struct __wTTTrack wTTTrack;

#ifdef __cplusplus
  }
#endif


#endif
