/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_Location_H
#define __WRAPPER_Location_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wLocation {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* cmd_fifo;
  const char* cmd_minocc;
  const char* (*getblocks)(iONode);
  void (*setblocks)(iONode,const char*);
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  Boolean (*isfifo)(iONode);
  void (*setfifo)(iONode,Boolean);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  int (*getminocc)(iONode);
  void (*setminocc)(iONode,int);
  int (*getvalue)(iONode);
  void (*setvalue)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wLocation wLocation;

#ifdef __cplusplus
  }
#endif


#endif
