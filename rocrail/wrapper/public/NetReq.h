/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_NetReq_H
#define __WRAPPER_NetReq_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wNetReq {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* req_clientconn;
  const char* req_getblock;
  const char* req_isfree;
  const char* req_locoisin;
  const char* req_netroutes;
  const char* req_reserve;
  const char* req_unlock;
  const char* (*getlcid)(iONode);
  void (*setlcid)(iONode,const char*);
  const char* (*getlocalbk)(iONode);
  void (*setlocalbk)(iONode,const char*);
  const char* (*getlocalid)(iONode);
  void (*setlocalid)(iONode,const char*);
  const char* (*getremotebk)(iONode);
  void (*setremotebk)(iONode,const char*);
  const char* (*getremoteid)(iONode);
  void (*setremoteid)(iONode,const char*);
  const char* (*getreq)(iONode);
  void (*setreq)(iONode,const char*);
  const char* (*getrouteid)(iONode);
  void (*setrouteid)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wNetReq wNetReq;

#ifdef __cplusplus
  }
#endif


#endif
