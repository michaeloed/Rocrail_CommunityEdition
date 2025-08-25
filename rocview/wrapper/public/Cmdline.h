/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:52 2018
  */

#ifndef __WRAPPER_Cmdline_H
#define __WRAPPER_Cmdline_H

#include "rocview/wrapper/public/wrapper.h"
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
  const char* debug;
  const char* fullscreen;
  const char* host;
  const char* info;
  const char* inifile;
  const char* langfile;
  const char* locotabsel;
  const char* offline;
  const char* parse;
  const char* port;
  const char* serverpath;
  const char* tabsel;
  const char* tabview;
  const char* tabviewrotated;
  const char* theme;
  const char* themespath;
  const char* trcfile;
  Boolean (*dump)(iONode node);
};

extern struct __wCmdline wCmdline;

#ifdef __cplusplus
  }
#endif


#endif
