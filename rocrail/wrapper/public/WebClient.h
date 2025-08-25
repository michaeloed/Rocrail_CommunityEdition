/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_WebClient_H
#define __WRAPPER_WebClient_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wWebClient {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getimgpath)(iONode);
  void (*setimgpath)(iONode,const char*);
  int (*getport)(iONode);
  void (*setport)(iONode,int);
  const char* (*getsvgpath1)(iONode);
  void (*setsvgpath1)(iONode,const char*);
  const char* (*getsvgpath2)(iONode);
  void (*setsvgpath2)(iONode,const char*);
  const char* (*getsvgpath3)(iONode);
  void (*setsvgpath3)(iONode,const char*);
  const char* (*getsvgpath4)(iONode);
  void (*setsvgpath4)(iONode,const char*);
  const char* (*getsvgpath5)(iONode);
  void (*setsvgpath5)(iONode,const char*);
  const char* (*getwebpath)(iONode);
  void (*setwebpath)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wWebClient wWebClient;

#ifdef __cplusplus
  }
#endif


#endif
