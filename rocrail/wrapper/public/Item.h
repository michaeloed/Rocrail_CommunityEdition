/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Item_H
#define __WRAPPER_Item_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wItem {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* east;
  const char* north;
  const char* south;
  const char* west;
  int (*getaddr)(iONode);
  void (*setaddr)(iONode,int);
  const char* (*getblockid)(iONode);
  void (*setblockid)(iONode,const char*);
  int (*getbus)(iONode);
  void (*setbus)(iONode,int);
  Boolean (*iscopy)(iONode);
  void (*setcopy)(iONode,Boolean);
  int (*getcx)(iONode);
  void (*setcx)(iONode,int);
  int (*getcy)(iONode);
  void (*setcy)(iONode,int);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  Boolean (*isdir)(iONode);
  void (*setdir)(iONode,Boolean);
  Boolean (*isgenerated)(iONode);
  void (*setgenerated)(iONode,Boolean);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  int (*getlen)(iONode);
  void (*setlen)(iONode,int);
  const char* (*getname)(iONode);
  void (*setname)(iONode,const char*);
  const char* (*getoid)(iONode);
  void (*setoid)(iONode,const char*);
  const char* (*getori)(iONode);
  void (*setori)(iONode,const char*);
  const char* (*getprev_id)(iONode);
  void (*setprev_id)(iONode,const char*);
  const char* (*getprev_ori)(iONode);
  void (*setprev_ori)(iONode,const char*);
  int (*getprev_x)(iONode);
  void (*setprev_x)(iONode,int);
  int (*getprev_y)(iONode);
  void (*setprev_y)(iONode,int);
  Boolean (*isroad)(iONode);
  void (*setroad)(iONode,Boolean);
  const char* (*getrouteids)(iONode);
  void (*setrouteids)(iONode,const char*);
  Boolean (*isshow)(iONode);
  void (*setshow)(iONode,Boolean);
  const char* (*getstate)(iONode);
  void (*setstate)(iONode,const char*);
  const char* (*gettype)(iONode);
  void (*settype)(iONode,const char*);
  const char* (*getuidname)(iONode);
  void (*setuidname)(iONode,const char*);
  int (*getx)(iONode);
  void (*setx)(iONode,int);
  int (*gety)(iONode);
  void (*sety)(iONode,int);
  int (*getz)(iONode);
  void (*setz)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wItem wItem;

#ifdef __cplusplus
  }
#endif


#endif
