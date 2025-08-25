/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#ifndef __WRAPPER_Release_H
#define __WRAPPER_Release_H

#include "rocview/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wRelease {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getalias)(iONode);
  void (*setalias)(iONode,const char*);
  const char* (*getremark)(iONode);
  void (*setremark)(iONode,const char*);
  long (*gettimestamp)(iONode);
  void (*settimestamp)(iONode,long);
  const char* (*getversion)(iONode);
  void (*setversion)(iONode,const char*);
  iONode (*getpatch)(iONode);
  iONode (*nextpatch)(iONode,iONode);
  void (*setpatch)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wRelease wRelease;

#ifdef __cplusplus
  }
#endif


#endif
