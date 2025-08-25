/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Signal_H
#define __WRAPPER_Signal_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wSignal {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* aspect;
  const char* autooperated;
  const char* blank;
  const char* blockstate;
  const char* distant;
  const char* flip;
  const char* green;
  const char* light;
  const char* main;
  const char* manualoperated;
  const char* prot_DEF;
  const char* prot_M;
  const char* prot_MDD;
  const char* prot_N;
  const char* prot_OM32;
  const char* red;
  const char* semaphore;
  const char* shunting;
  int use_aspectnrs;
  int use_binary;
  int use_linear;
  int use_patterns;
  const char* white;
  const char* yellow;
  Boolean (*isaccessory)(iONode);
  void (*setaccessory)(iONode,Boolean);
  int (*getaddr)(iONode);
  void (*setaddr)(iONode,int);
  int (*getaddr2)(iONode);
  void (*setaddr2)(iONode,int);
  int (*getaddr3)(iONode);
  void (*setaddr3)(iONode,int);
  int (*getaddr4)(iONode);
  void (*setaddr4)(iONode,int);
  int (*getaspect)(iONode);
  void (*setaspect)(iONode,int);
  const char* (*getaspectnames)(iONode);
  void (*setaspectnames)(iONode,const char*);
  int (*getaspects)(iONode);
  void (*setaspects)(iONode,int);
  Boolean (*isasswitch)(iONode);
  void (*setasswitch)(iONode,Boolean);
  int (*getblank)(iONode);
  void (*setblank)(iONode,int);
  int (*getblanknr)(iONode);
  void (*setblanknr)(iONode,int);
  const char* (*getblockid)(iONode);
  void (*setblockid)(iONode,const char*);
  int (*getbus)(iONode);
  void (*setbus)(iONode,int);
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  int (*getcmdtime)(iONode);
  void (*setcmdtime)(iONode,int);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  Boolean (*isdwarf)(iONode);
  void (*setdwarf)(iONode,Boolean);
  int (*getgate1)(iONode);
  void (*setgate1)(iONode,int);
  int (*getgate2)(iONode);
  void (*setgate2)(iONode,int);
  int (*getgate3)(iONode);
  void (*setgate3)(iONode,int);
  int (*getgate4)(iONode);
  void (*setgate4)(iONode,int);
  int (*getgreen)(iONode);
  void (*setgreen)(iONode,int);
  int (*getgreennr)(iONode);
  void (*setgreennr)(iONode,int);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  Boolean (*isinv)(iONode);
  void (*setinv)(iONode,Boolean);
  Boolean (*ismanual)(iONode);
  void (*setmanual)(iONode,Boolean);
  Boolean (*ismanualreset)(iONode);
  void (*setmanualreset)(iONode,Boolean);
  const char* (*getoid)(iONode);
  void (*setoid)(iONode,const char*);
  const char* (*getori)(iONode);
  void (*setori)(iONode,const char*);
  Boolean (*ispair)(iONode);
  void (*setpair)(iONode,Boolean);
  int (*getpause)(iONode);
  void (*setpause)(iONode,int);
  int (*getport1)(iONode);
  void (*setport1)(iONode,int);
  int (*getport2)(iONode);
  void (*setport2)(iONode,int);
  int (*getport3)(iONode);
  void (*setport3)(iONode,int);
  int (*getport4)(iONode);
  void (*setport4)(iONode,int);
  int (*getporttype)(iONode);
  void (*setporttype)(iONode,int);
  const char* (*getprot)(iONode);
  void (*setprot)(iONode,const char*);
  int (*getred)(iONode);
  void (*setred)(iONode,int);
  int (*getrednr)(iONode);
  void (*setrednr)(iONode,int);
  const char* (*getsignal)(iONode);
  void (*setsignal)(iONode,const char*);
  const char* (*getstate)(iONode);
  void (*setstate)(iONode,const char*);
  const char* (*getsymbolprefix)(iONode);
  void (*setsymbolprefix)(iONode,const char*);
  const char* (*gettype)(iONode);
  void (*settype)(iONode,const char*);
  int (*getusepatterns)(iONode);
  void (*setusepatterns)(iONode,int);
  Boolean (*isusesymbolprefix)(iONode);
  void (*setusesymbolprefix)(iONode,Boolean);
  int (*getwhite)(iONode);
  void (*setwhite)(iONode,int);
  int (*getwhitenr)(iONode);
  void (*setwhitenr)(iONode,int);
  int (*getx)(iONode);
  void (*setx)(iONode,int);
  int (*gety)(iONode);
  void (*sety)(iONode,int);
  int (*getyellow)(iONode);
  void (*setyellow)(iONode,int);
  int (*getyellownr)(iONode);
  void (*setyellownr)(iONode,int);
  int (*getz)(iONode);
  void (*setz)(iONode,int);
  iONode (*getactionctrl)(iONode);
  iONode (*nextactionctrl)(iONode,iONode);
  void (*setactionctrl)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wSignal wSignal;

#ifdef __cplusplus
  }
#endif


#endif
