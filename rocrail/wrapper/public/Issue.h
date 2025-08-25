/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Issue_H
#define __WRAPPER_Issue_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wIssue {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  Boolean (*iscurrenttrc)(iONode);
  void (*setcurrenttrc)(iONode,Boolean);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  Boolean (*isini)(iONode);
  void (*setini)(iONode,Boolean);
  Boolean (*isstat)(iONode);
  void (*setstat)(iONode,Boolean);
  const char* (*getsubject)(iONode);
  void (*setsubject)(iONode,const char*);
  Boolean (*istrc)(iONode);
  void (*settrc)(iONode,Boolean);
  Boolean (*isxml)(iONode);
  void (*setxml)(iONode,Boolean);
  Boolean (*dump)(iONode node);
};

extern struct __wIssue wIssue;

#ifdef __cplusplus
  }
#endif


#endif
