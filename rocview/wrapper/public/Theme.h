/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocview
  * Date: Fri Aug  3 14:03:53 2018
  */

#ifndef __WRAPPER_Theme_H
#define __WRAPPER_Theme_H

#include "rocview/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wTheme {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  iONode (*getpanel)(iONode);
  iONode (*nextpanel)(iONode,iONode);
  void (*setpanel)(iONode,iONode);
  iONode (*getthemeblock)(iONode);
  iONode (*nextthemeblock)(iONode,iONode);
  void (*setthemeblock)(iONode,iONode);
  iONode (*getshortcut)(iONode);
  iONode (*nextshortcut)(iONode,iONode);
  void (*setshortcut)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wTheme wTheme;

#ifdef __cplusplus
  }
#endif


#endif
