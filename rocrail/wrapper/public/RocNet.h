/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_RocNet_H
#define __WRAPPER_RocNet_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wRocNet {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* (*getaddr)(iONode);
  void (*setaddr)(iONode,const char*);
  Boolean (*iscrc)(iONode);
  void (*setcrc)(iONode,Boolean);
  int (*getid)(iONode);
  void (*setid)(iONode,int);
  int (*getlcbus)(iONode);
  void (*setlcbus)(iONode,int);
  int (*getnet)(iONode);
  void (*setnet)(iONode,int);
  int (*getport)(iONode);
  void (*setport)(iONode,int);
  Boolean (*issack)(iONode);
  void (*setsack)(iONode,Boolean);
  Boolean (*isshutdownall)(iONode);
  void (*setshutdownall)(iONode,Boolean);
  Boolean (*iswatchnodes)(iONode);
  void (*setwatchnodes)(iONode,Boolean);
  Boolean (*iswd)(iONode);
  void (*setwd)(iONode,Boolean);
  iONode (*getrocnetnodeoptions)(iONode);
  iONode (*nextrocnetnodeoptions)(iONode,iONode);
  void (*setrocnetnodeoptions)(iONode,iONode);
  iONode (*getrocnetnode)(iONode);
  iONode (*nextrocnetnode)(iONode,iONode);
  void (*setrocnetnode)(iONode,iONode);
  iONode (*getportsetup)(iONode);
  iONode (*nextportsetup)(iONode,iONode);
  void (*setportsetup)(iONode,iONode);
  iONode (*getchannelsetup)(iONode);
  iONode (*nextchannelsetup)(iONode,iONode);
  void (*setchannelsetup)(iONode,iONode);
  iONode (*getmacro)(iONode);
  iONode (*nextmacro)(iONode,iONode);
  void (*setmacro)(iONode,iONode);
  iONode (*getlocosetup)(iONode);
  iONode (*nextlocosetup)(iONode,iONode);
  void (*setlocosetup)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wRocNet wRocNet;

#ifdef __cplusplus
  }
#endif


#endif
