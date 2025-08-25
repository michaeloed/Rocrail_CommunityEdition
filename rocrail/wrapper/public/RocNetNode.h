/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_RocNetNode_H
#define __WRAPPER_RocNetNode_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wRocNetNode {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getclass)(iONode);
  void (*setclass)(iONode,const char*);
  int (*getid)(iONode);
  void (*setid)(iONode,int);
  int (*getlocation)(iONode);
  void (*setlocation)(iONode,int);
  const char* (*getmnemonic)(iONode);
  void (*setmnemonic)(iONode,const char*);
  const char* (*getnickname)(iONode);
  void (*setnickname)(iONode,const char*);
  int (*getnrio)(iONode);
  void (*setnrio)(iONode,int);
  long (*getpingtick)(iONode);
  void (*setpingtick)(iONode,long);
  long (*getpongtick)(iONode);
  void (*setpongtick)(iONode,long);
  int (*getrevision)(iONode);
  void (*setrevision)(iONode,int);
  int (*getsubip)(iONode);
  void (*setsubip)(iONode,int);
  int (*getvendor)(iONode);
  void (*setvendor)(iONode,int);
  const char* (*getversion)(iONode);
  void (*setversion)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wRocNetNode wRocNetNode;

#ifdef __cplusplus
  }
#endif


#endif
