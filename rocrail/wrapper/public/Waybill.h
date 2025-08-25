/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_Waybill_H
#define __WRAPPER_Waybill_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wWaybill {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* status_delivered;
  const char* status_shipping;
  const char* status_waiting;
  const char* (*getcartype)(iONode);
  void (*setcartype)(iONode,const char*);
  const char* (*getcommodity)(iONode);
  void (*setcommodity)(iONode,const char*);
  const char* (*getconsignee)(iONode);
  void (*setconsignee)(iONode,const char*);
  const char* (*getdestination)(iONode);
  void (*setdestination)(iONode,const char*);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getorigin)(iONode);
  void (*setorigin)(iONode,const char*);
  const char* (*getrouting)(iONode);
  void (*setrouting)(iONode,const char*);
  const char* (*getshipper)(iONode);
  void (*setshipper)(iONode,const char*);
  const char* (*getstatus)(iONode);
  void (*setstatus)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wWaybill wWaybill;

#ifdef __cplusplus
  }
#endif


#endif
