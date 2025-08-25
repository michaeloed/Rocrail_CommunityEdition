/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_StageSection_H
#define __WRAPPER_StageSection_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wStageSection {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getaction)(iONode);
  void (*setaction)(iONode,const char*);
  const char* (*getfbid)(iONode);
  void (*setfbid)(iONode,const char*);
  const char* (*getfbidocc)(iONode);
  void (*setfbidocc)(iONode,const char*);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  int (*getidx)(iONode);
  void (*setidx)(iONode,int);
  const char* (*getlcid)(iONode);
  void (*setlcid)(iONode,const char*);
  int (*getlen)(iONode);
  void (*setlen)(iONode,int);
  int (*getnr)(iONode);
  void (*setnr)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wStageSection wStageSection;

#ifdef __cplusplus
  }
#endif


#endif
