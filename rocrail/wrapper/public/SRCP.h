/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_SRCP_H
#define __WRAPPER_SRCP_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wSRCP {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int (*getcmdport)(iONode);
  void (*setcmdport)(iONode,int);
  int (*getsrcpbusFB_i8255)(iONode);
  void (*setsrcpbusFB_i8255)(iONode,int);
  int (*getsrcpbusFB_m6051)(iONode);
  void (*setsrcpbusFB_m6051)(iONode,int);
  int (*getsrcpbusFB_s88)(iONode);
  void (*setsrcpbusFB_s88)(iONode,int);
  int (*getsrcpbusGA_m)(iONode);
  void (*setsrcpbusGA_m)(iONode,int);
  int (*getsrcpbusGA_n)(iONode);
  void (*setsrcpbusGA_n)(iONode,int);
  int (*getsrcpbusGA_ps)(iONode);
  void (*setsrcpbusGA_ps)(iONode,int);
  int (*getsrcpbusGL_m)(iONode);
  void (*setsrcpbusGL_m)(iONode,int);
  int (*getsrcpbusGL_nl)(iONode);
  void (*setsrcpbusGL_nl)(iONode,int);
  int (*getsrcpbusGL_ns)(iONode);
  void (*setsrcpbusGL_ns)(iONode,int);
  int (*getsrcpbusGL_ps)(iONode);
  void (*setsrcpbusGL_ps)(iONode,int);
  int (*getsrcpbus_server)(iONode);
  void (*setsrcpbus_server)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wSRCP wSRCP;

#ifdef __cplusplus
  }
#endif


#endif
