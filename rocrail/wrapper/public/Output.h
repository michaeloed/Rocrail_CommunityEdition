/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Output_H
#define __WRAPPER_Output_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wOutput {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* active;
  const char* flip;
  const char* off;
  const char* on;
  const char* prot_DEF;
  const char* prot_DO;
  const char* prot_M;
  const char* prot_MDD;
  const char* prot_N;
  const char* prot_OM32;
  const char* prot_VO;
  const char* sod;
  const char* value;
  Boolean (*isaccessory)(iONode);
  void (*setaccessory)(iONode,Boolean);
  int (*getaddr)(iONode);
  void (*setaddr)(iONode,int);
  Boolean (*isasswitch)(iONode);
  void (*setasswitch)(iONode,Boolean);
  Boolean (*isblink)(iONode);
  void (*setblink)(iONode,Boolean);
  const char* (*getblockid)(iONode);
  void (*setblockid)(iONode,const char*);
  int (*getblueChannel)(iONode);
  void (*setblueChannel)(iONode,int);
  int (*getbrightnessChannel)(iONode);
  void (*setbrightnessChannel)(iONode,int);
  int (*getbus)(iONode);
  void (*setbus)(iONode,int);
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  Boolean (*iscolortype)(iONode);
  void (*setcolortype)(iONode,Boolean);
  int (*getdelay)(iONode);
  void (*setdelay)(iONode,int);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  int (*getgate)(iONode);
  void (*setgate)(iONode,int);
  int (*getgreenChannel)(iONode);
  void (*setgreenChannel)(iONode,int);
  const char* (*getgrpid)(iONode);
  void (*setgrpid)(iONode,const char*);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  Boolean (*isinv)(iONode);
  void (*setinv)(iONode,Boolean);
  const char* (*getoid)(iONode);
  void (*setoid)(iONode,const char*);
  const char* (*getori)(iONode);
  void (*setori)(iONode,const char*);
  int (*getparam)(iONode);
  void (*setparam)(iONode,int);
  int (*getpause)(iONode);
  void (*setpause)(iONode,int);
  int (*getport)(iONode);
  void (*setport)(iONode,int);
  int (*getporttype)(iONode);
  void (*setporttype)(iONode,int);
  const char* (*getprot)(iONode);
  void (*setprot)(iONode,const char*);
  int (*getredChannel)(iONode);
  void (*setredChannel)(iONode,int);
  Boolean (*isshow)(iONode);
  void (*setshow)(iONode,Boolean);
  const char* (*getstate)(iONode);
  void (*setstate)(iONode,const char*);
  int (*getsvgtype)(iONode);
  void (*setsvgtype)(iONode,int);
  Boolean (*istoggleswitch)(iONode);
  void (*settoggleswitch)(iONode,Boolean);
  Boolean (*istristate)(iONode);
  void (*settristate)(iONode,Boolean);
  const char* (*gettype)(iONode);
  void (*settype)(iONode,const char*);
  int (*getvalue)(iONode);
  void (*setvalue)(iONode,int);
  int (*getwhite2Channel)(iONode);
  void (*setwhite2Channel)(iONode,int);
  int (*getwhiteChannel)(iONode);
  void (*setwhiteChannel)(iONode,int);
  int (*getx)(iONode);
  void (*setx)(iONode,int);
  int (*gety)(iONode);
  void (*sety)(iONode,int);
  int (*getz)(iONode);
  void (*setz)(iONode,int);
  iONode (*getactionctrl)(iONode);
  iONode (*nextactionctrl)(iONode,iONode);
  void (*setactionctrl)(iONode,iONode);
  iONode (*getcolor)(iONode);
  iONode (*nextcolor)(iONode,iONode);
  void (*setcolor)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wOutput wOutput;

#ifdef __cplusplus
  }
#endif


#endif
