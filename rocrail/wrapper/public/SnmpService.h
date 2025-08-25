/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_SnmpService_H
#define __WRAPPER_SnmpService_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wSnmpService {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* privBuildTime;
  const char* privConnectionCnt;
  const char* privLastExc;
  const char* privMemStats;
  const char* privThreadCnt;
  const char* privTrapException;
  const char* privTrapShutDown;
  const char* privateList;
  const char* sysContact;
  const char* sysDescr;
  const char* sysLocation;
  const char* sysName;
  const char* sysObjectID;
  const char* sysServices;
  const char* sysUpTime;
  const char* systemList;
  const char* trapColdStart;
  const char* trapLinkDown;
  const char* trapLinkUp;
  Boolean (*isactive)(iONode);
  void (*setactive)(iONode,Boolean);
  const char* (*getcommunity)(iONode);
  void (*setcommunity)(iONode,const char*);
  const char* (*getcontact)(iONode);
  void (*setcontact)(iONode,const char*);
  const char* (*getdescription)(iONode);
  void (*setdescription)(iONode,const char*);
  int (*getenterprise)(iONode);
  void (*setenterprise)(iONode,int);
  int (*getfamily)(iONode);
  void (*setfamily)(iONode,int);
  const char* (*getlocation)(iONode);
  void (*setlocation)(iONode,const char*);
  int (*getport)(iONode);
  void (*setport)(iONode,int);
  int (*getproduct)(iONode);
  void (*setproduct)(iONode,int);
  const char* (*gettraphost)(iONode);
  void (*settraphost)(iONode,const char*);
  int (*gettrapport)(iONode);
  void (*settrapport)(iONode,int);
  int (*getversion)(iONode);
  void (*setversion)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wSnmpService wSnmpService;

#ifdef __cplusplus
  }
#endif


#endif
