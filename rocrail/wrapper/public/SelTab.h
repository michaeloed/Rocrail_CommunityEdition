/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_SelTab_H
#define __WRAPPER_SelTab_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wSelTab {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* gotopos;
  const char* next;
  const char* prev;
  const char* prot_DEF;
  const char* prot_M;
  const char* prot_MP;
  const char* prot_N;
  int (*getaddr0)(iONode);
  void (*setaddr0)(iONode,int);
  int (*getaddr1)(iONode);
  void (*setaddr1)(iONode,int);
  int (*getaddr2)(iONode);
  void (*setaddr2)(iONode,int);
  int (*getaddr3)(iONode);
  void (*setaddr3)(iONode,int);
  int (*getaddr4)(iONode);
  void (*setaddr4)(iONode,int);
  int (*getaddr5)(iONode);
  void (*setaddr5)(iONode,int);
  int (*getaddr6)(iONode);
  void (*setaddr6)(iONode,int);
  int (*getaddr7)(iONode);
  void (*setaddr7)(iONode,int);
  const char* (*getb0sen)(iONode);
  void (*setb0sen)(iONode,const char*);
  const char* (*getb1sen)(iONode);
  void (*setb1sen)(iONode,const char*);
  const char* (*getb2sen)(iONode);
  void (*setb2sen)(iONode,const char*);
  const char* (*getb3sen)(iONode);
  void (*setb3sen)(iONode,const char*);
  const char* (*getb4sen)(iONode);
  void (*setb4sen)(iONode,const char*);
  const char* (*getb5sen)(iONode);
  void (*setb5sen)(iONode,const char*);
  const char* (*getb6sen)(iONode);
  void (*setb6sen)(iONode,const char*);
  int (*getbus)(iONode);
  void (*setbus)(iONode,int);
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  Boolean (*isfifo)(iONode);
  void (*setfifo)(iONode,Boolean);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  Boolean (*isinv)(iONode);
  void (*setinv)(iONode,Boolean);
  Boolean (*isinvnew)(iONode);
  void (*setinvnew)(iONode,Boolean);
  const char* (*getlocid)(iONode);
  void (*setlocid)(iONode,const char*);
  Boolean (*ismanager)(iONode);
  void (*setmanager)(iONode,Boolean);
  int (*getminocc)(iONode);
  void (*setminocc)(iONode,int);
  int (*getmovedelay)(iONode);
  void (*setmovedelay)(iONode,int);
  int (*getnrtracks)(iONode);
  void (*setnrtracks)(iONode,int);
  int (*getoffpos)(iONode);
  void (*setoffpos)(iONode,int);
  const char* (*getori)(iONode);
  void (*setori)(iONode,const char*);
  Boolean (*ispending)(iONode);
  void (*setpending)(iONode,Boolean);
  int (*getport0)(iONode);
  void (*setport0)(iONode,int);
  int (*getport1)(iONode);
  void (*setport1)(iONode,int);
  int (*getport2)(iONode);
  void (*setport2)(iONode,int);
  int (*getport3)(iONode);
  void (*setport3)(iONode,int);
  int (*getport4)(iONode);
  void (*setport4)(iONode,int);
  int (*getport5)(iONode);
  void (*setport5)(iONode,int);
  int (*getport6)(iONode);
  void (*setport6)(iONode,int);
  int (*getport7)(iONode);
  void (*setport7)(iONode,int);
  int (*getpos)(iONode);
  void (*setpos)(iONode,int);
  const char* (*getprot)(iONode);
  void (*setprot)(iONode,const char*);
  const char* (*getpsen)(iONode);
  void (*setpsen)(iONode,const char*);
  int (*getrandomrate)(iONode);
  void (*setrandomrate)(iONode,int);
  Boolean (*issharedfb)(iONode);
  void (*setsharedfb)(iONode,Boolean);
  Boolean (*issinglegate)(iONode);
  void (*setsinglegate)(iONode,Boolean);
  const char* (*getstate)(iONode);
  void (*setstate)(iONode,const char*);
  int (*getx)(iONode);
  void (*setx)(iONode,int);
  int (*gety)(iONode);
  void (*sety)(iONode,int);
  int (*getz)(iONode);
  void (*setz)(iONode,int);
  iONode (*getseltabpos)(iONode);
  iONode (*nextseltabpos)(iONode,iONode);
  void (*setseltabpos)(iONode,iONode);
  iONode (*getfbevent)(iONode);
  iONode (*nextfbevent)(iONode,iONode);
  void (*setfbevent)(iONode,iONode);
  iONode (*getactionctrl)(iONode);
  iONode (*nextactionctrl)(iONode,iONode);
  void (*setactionctrl)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wSelTab wSelTab;

#ifdef __cplusplus
  }
#endif


#endif
