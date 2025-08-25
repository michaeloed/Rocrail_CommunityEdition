/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Response_H
#define __WRAPPER_Response_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wResponse {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* ctserr;
  const char* ok;
  const char* rcverr;
  const char* snderr;
  const char* (*getdata)(iONode);
  void (*setdata)(iONode,const char*);
  Boolean (*iserror)(iONode);
  void (*seterror)(iONode,Boolean);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  const char* (*getmsg)(iONode);
  void (*setmsg)(iONode,const char*);
  int (*getrc)(iONode);
  void (*setrc)(iONode,int);
  Boolean (*isretry)(iONode);
  void (*setretry)(iONode,Boolean);
  const char* (*getsender)(iONode);
  void (*setsender)(iONode,const char*);
  const char* (*getstate)(iONode);
  void (*setstate)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wResponse wResponse;

#ifdef __cplusplus
  }
#endif


#endif
