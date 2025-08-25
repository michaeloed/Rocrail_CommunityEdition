/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_CBusNode_H
#define __WRAPPER_CBusNode_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wCBusNode {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int mtyp_canacc4;
  int mtyp_canacc4_2;
  int mtyp_canacc5;
  int mtyp_canacc8;
  int mtyp_canace3;
  int mtyp_canace8c;
  int mtyp_canbc;
  int mtyp_cancab;
  int mtyp_cancmd;
  int mtyp_canled;
  int mtyp_canled64;
  int mtyp_canrpi;
  int mtyp_canservo;
  int mtyp_canttca;
  int mtyp_canttcb;
  int (*getcanid)(iONode);
  void (*setcanid)(iONode,int);
  int (*getmanuid)(iONode);
  void (*setmanuid)(iONode,int);
  int (*getmtyp)(iONode);
  void (*setmtyp)(iONode,int);
  int (*getnr)(iONode);
  void (*setnr)(iONode,int);
  int (*getnrevt)(iONode);
  void (*setnrevt)(iONode,int);
  int (*getnrevtvar)(iONode);
  void (*setnrevtvar)(iONode,int);
  int (*getnrvar)(iONode);
  void (*setnrvar)(iONode,int);
  const char* (*getversion)(iONode);
  void (*setversion)(iONode,const char*);
  iONode (*getcbnodevar)(iONode);
  iONode (*nextcbnodevar)(iONode,iONode);
  void (*setcbnodevar)(iONode,iONode);
  iONode (*getcbnodeevent)(iONode);
  iONode (*nextcbnodeevent)(iONode,iONode);
  void (*setcbnodeevent)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wCBusNode wCBusNode;

#ifdef __cplusplus
  }
#endif


#endif
