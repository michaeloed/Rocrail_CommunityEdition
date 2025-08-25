/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_AnaOpt_H
#define __WRAPPER_AnaOpt_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wAnaOpt {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*isactionCheck)(iONode);
  void (*setactionCheck)(iONode,Boolean);
  Boolean (*isactionClean)(iONode);
  void (*setactionClean)(iONode,Boolean);
  Boolean (*isaddFeedbackBlockAssignment)(iONode);
  void (*setaddFeedbackBlockAssignment)(iONode,Boolean);
  Boolean (*isaddSignalBlockAssignment)(iONode);
  void (*setaddSignalBlockAssignment)(iONode,Boolean);
  Boolean (*isbasicCheck)(iONode);
  void (*setbasicCheck)(iONode,Boolean);
  Boolean (*isbasicClean)(iONode);
  void (*setbasicClean)(iONode,Boolean);
  Boolean (*isblockCheck)(iONode);
  void (*setblockCheck)(iONode,Boolean);
  Boolean (*isblockClean)(iONode);
  void (*setblockClean)(iONode,Boolean);
  Boolean (*iscleanRouteId)(iONode);
  void (*setcleanRouteId)(iONode,Boolean);
  int (*getmaxRecursionDepth)(iONode);
  void (*setmaxRecursionDepth)(iONode,int);
  Boolean (*isresetBlockId)(iONode);
  void (*setresetBlockId)(iONode,Boolean);
  Boolean (*isresetFeedbackBlockAssignment)(iONode);
  void (*setresetFeedbackBlockAssignment)(iONode,Boolean);
  Boolean (*isresetSignalBlockAssignment)(iONode);
  void (*setresetSignalBlockAssignment)(iONode,Boolean);
  Boolean (*isrouteCheck)(iONode);
  void (*setrouteCheck)(iONode,Boolean);
  Boolean (*isrouteClean)(iONode);
  void (*setrouteClean)(iONode,Boolean);
  Boolean (*issetBlockId)(iONode);
  void (*setsetBlockId)(iONode,Boolean);
  Boolean (*issetRouteId)(iONode);
  void (*setsetRouteId)(iONode,Boolean);
  Boolean (*dump)(iONode node);
};

extern struct __wAnaOpt wAnaOpt;

#ifdef __cplusplus
  }
#endif


#endif
