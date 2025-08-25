/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_CVByte_H
#define __WRAPPER_CVByte_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wCVByte {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getcat)(iONode);
  void (*setcat)(iONode,const char*);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  const char* (*getdipid)(iONode);
  void (*setdipid)(iONode,const char*);
  const char* (*getinfo)(iONode);
  void (*setinfo)(iONode,const char*);
  int (*getnr)(iONode);
  void (*setnr)(iONode,int);
  Boolean (*isreadonly)(iONode);
  void (*setreadonly)(iONode,Boolean);
  const char* (*geturl)(iONode);
  void (*seturl)(iONode,const char*);
  int (*getvalue)(iONode);
  void (*setvalue)(iONode,int);
  Boolean (*isword)(iONode);
  void (*setword)(iONode,Boolean);
  iONode (*getadip)(iONode);
  iONode (*nextadip)(iONode,iONode);
  void (*setadip)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wCVByte wCVByte;

#ifdef __cplusplus
  }
#endif


#endif
