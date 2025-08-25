/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_Track_H
#define __WRAPPER_Track_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wTrack {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* buffer;
  const char* concurveleft;
  const char* concurveright;
  const char* connector;
  const char* curve;
  const char* curve90;
  const char* curvenr;
  const char* dcurve;
  const char* dir;
  const char* dirall;
  const char* straight;
  const char* tracknr;
  const char* (*getblockid)(iONode);
  void (*setblockid)(iONode,const char*);
  const char* (*getcounterpartid)(iONode);
  void (*setcounterpartid)(iONode,const char*);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getori)(iONode);
  void (*setori)(iONode,const char*);
  int (*gettknr)(iONode);
  void (*settknr)(iONode,int);
  const char* (*gettype)(iONode);
  void (*settype)(iONode,const char*);
  int (*getx)(iONode);
  void (*setx)(iONode,int);
  int (*gety)(iONode);
  void (*sety)(iONode,int);
  int (*getz)(iONode);
  void (*setz)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wTrack wTrack;

#ifdef __cplusplus
  }
#endif


#endif
