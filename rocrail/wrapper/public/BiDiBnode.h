/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_BiDiBnode_H
#define __WRAPPER_BiDiBnode_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wBiDiBnode {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* class_accessory;
  const char* class_booster;
  const char* class_bridge;
  const char* class_dcc_main;
  const char* class_dcc_prog;
  const char* class_sensor;
  const char* class_switch;
  const char* class_ui;
  int (*getanalogcnt)(iONode);
  void (*setanalogcnt)(iONode,int);
  const char* (*getclass)(iONode);
  void (*setclass)(iONode,const char*);
  const char* (*getclassmnemonic)(iONode);
  void (*setclassmnemonic)(iONode,const char*);
  Boolean (*isfwup)(iONode);
  void (*setfwup)(iONode,Boolean);
  int (*getinputcnt)(iONode);
  void (*setinputcnt)(iONode,int);
  Boolean (*isiocfg)(iONode);
  void (*setiocfg)(iONode,Boolean);
  const char* (*getkey)(iONode);
  void (*setkey)(iONode,const char*);
  int (*getlportcnt)(iONode);
  void (*setlportcnt)(iONode,int);
  int (*getmotorcnt)(iONode);
  void (*setmotorcnt)(iONode,int);
  const char* (*getparentkey)(iONode);
  void (*setparentkey)(iONode,const char*);
  const char* (*getpath)(iONode);
  void (*setpath)(iONode,const char*);
  const char* (*getproductname)(iONode);
  void (*setproductname)(iONode,const char*);
  int (*getsensorcnt)(iONode);
  void (*setsensorcnt)(iONode,int);
  int (*getservocnt)(iONode);
  void (*setservocnt)(iONode,int);
  int (*getsoundcnt)(iONode);
  void (*setsoundcnt)(iONode,int);
  int (*getsportcnt)(iONode);
  void (*setsportcnt)(iONode,int);
  int (*getuid)(iONode);
  void (*setuid)(iONode,int);
  const char* (*getusername)(iONode);
  void (*setusername)(iONode,const char*);
  int (*getvendor)(iONode);
  void (*setvendor)(iONode,int);
  const char* (*getversion)(iONode);
  void (*setversion)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wBiDiBnode wBiDiBnode;

#ifdef __cplusplus
  }
#endif


#endif
