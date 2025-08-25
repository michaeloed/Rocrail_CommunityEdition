/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_Variable_H
#define __WRAPPER_Variable_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wVariable {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* op_add;
  const char* op_max;
  const char* op_min;
  const char* op_random;
  const char* op_start;
  const char* op_stop;
  const char* op_subtract;
  const char* op_text;
  const char* op_value;
  int type_default;
  int type_timer;
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  const char* (*getgroup)(iONode);
  void (*setgroup)(iONode,const char*);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  int (*getmax)(iONode);
  void (*setmax)(iONode,int);
  int (*getmin)(iONode);
  void (*setmin)(iONode,int);
  const char* (*gettext)(iONode);
  void (*settext)(iONode,const char*);
  Boolean (*istimer)(iONode);
  void (*settimer)(iONode,Boolean);
  int (*gettype)(iONode);
  void (*settype)(iONode,int);
  const char* (*getvalstr)(iONode);
  void (*setvalstr)(iONode,const char*);
  int (*getvalue)(iONode);
  void (*setvalue)(iONode,int);
  iONode (*getactionctrl)(iONode);
  iONode (*nextactionctrl)(iONode,iONode);
  void (*setactionctrl)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wVariable wVariable;

#ifdef __cplusplus
  }
#endif


#endif
