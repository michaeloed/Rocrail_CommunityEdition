/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Cmdline_H
#define __WRAPPER_Cmdline_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wCmdline {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* automode;
  const char* byte;
  const char* console;
  const char* debug;
  const char* deleteservice;
  const char* doc;
  const char* help;
  const char* http;
  const char* imgpath;
  const char* info;
  const char* inifile;
  const char* initfield;
  const char* installservice;
  const char* lcd;
  const char* libpath;
  const char* locofile;
  const char* modplan;
  const char* monitor;
  const char* nocom;
  const char* nodevcheck;
  const char* parse;
  const char* planfile;
  const char* port;
  const char* resume;
  const char* run;
  const char* service;
  const char* stress;
  const char* trcfile;
  const char* version;
  const char* workdir;
  Boolean (*dump)(iONode node);
};

extern struct __wCmdline wCmdline;

#ifdef __cplusplus
  }
#endif


#endif
