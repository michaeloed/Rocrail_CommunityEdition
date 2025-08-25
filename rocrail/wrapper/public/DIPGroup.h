/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_DIPGroup_H
#define __WRAPPER_DIPGroup_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wDIPGroup {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int grouptype_box;
  int grouptype_radiobox;
  const char* (*getcaption)(iONode);
  void (*setcaption)(iONode,const char*);
  int (*getmask)(iONode);
  void (*setmask)(iONode,int);
  int (*getori)(iONode);
  void (*setori)(iONode,int);
  int (*getspacing)(iONode);
  void (*setspacing)(iONode,int);
  int (*gettype)(iONode);
  void (*settype)(iONode,int);
  iONode (*getdipvalue)(iONode);
  iONode (*nextdipvalue)(iONode,iONode);
  void (*setdipvalue)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wDIPGroup wDIPGroup;

#ifdef __cplusplus
  }
#endif


#endif
