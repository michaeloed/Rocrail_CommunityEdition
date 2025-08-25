/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Occupancy_H
#define __WRAPPER_Occupancy_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wOccupancy {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isauto)(iONode);
  void (*setauto)(iONode,Boolean);
  const char* (*getbkid)(iONode);
  void (*setbkid)(iONode,const char*);
  int (*getblockenterside)(iONode);
  void (*setblockenterside)(iONode,int);
  Boolean (*isclosed)(iONode);
  void (*setclosed)(iONode,Boolean);
  const char* (*getlcid)(iONode);
  void (*setlcid)(iONode,const char*);
  int (*getplacing)(iONode);
  void (*setplacing)(iONode,int);
  const char* (*getscid)(iONode);
  void (*setscid)(iONode,const char*);
  const char* (*getsecid)(iONode);
  void (*setsecid)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wOccupancy wOccupancy;

#ifdef __cplusplus
  }
#endif


#endif
