/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_ConCmd_H
#define __WRAPPER_ConCmd_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wConCmd {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  char analyse;
  char analyseclean;
  char automat;
  char byte;
  char config;
  char debug;
  char ebreak;
  char help;
  char http;
  char info;
  char initfield;
  char memory;
  char memtrc;
  char monitor;
  char poweroff;
  char poweron;
  char query;
  char quit;
  char slots;
  char sod;
  char stopautomode;
  char threads;
  Boolean (*dump)(iONode node);
};

extern struct __wConCmd wConCmd;

#ifdef __cplusplus
  }
#endif


#endif
