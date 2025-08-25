/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_Dec_H
#define __WRAPPER_Dec_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wDec {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getaddr)(iONode);
  void (*setaddr)(iONode,int);
  int (*getbus)(iONode);
  void (*setbus)(iONode,int);
  const char* (*getcatnr)(iONode);
  void (*setcatnr)(iONode,const char*);
  const char* (*getdecfile)(iONode);
  void (*setdecfile)(iONode,const char*);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  const char* (*getdocu)(iONode);
  void (*setdocu)(iONode,const char*);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  const char* (*getimage)(iONode);
  void (*setimage)(iONode,const char*);
  const char* (*getmanu)(iONode);
  void (*setmanu)(iONode,const char*);
  const char* (*getprev_id)(iONode);
  void (*setprev_id)(iONode,const char*);
  const char* (*getprot)(iONode);
  void (*setprot)(iONode,const char*);
  int (*getprotver)(iONode);
  void (*setprotver)(iONode,int);
  iONode (*getcvbyte)(iONode);
  iONode (*nextcvbyte)(iONode,iONode);
  void (*setcvbyte)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wDec wDec;

#ifdef __cplusplus
  }
#endif


#endif
