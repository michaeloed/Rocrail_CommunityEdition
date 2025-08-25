/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_Turntable_H
#define __WRAPPER_Turntable_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wTurntable {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* accdec;
  const char* calibrate;
  const char* d15;
  const char* digitalbahn;
  const char* dsm;
  const char* f6915;
  const char* foff;
  const char* fon;
  const char* lightoff;
  const char* lighton;
  const char* locdec;
  const char* muet;
  const char* multiport;
  const char* next;
  const char* prev;
  const char* prot_DEF;
  const char* prot_M;
  const char* prot_MP;
  const char* prot_N;
  const char* slx815;
  const char* ttdec;
  const char* turn180;
  const char* unlocked;
  int (*getV)(iONode);
  void (*setV)(iONode,int);
  int (*getactfn)(iONode);
  void (*setactfn)(iONode,int);
  int (*getaddr)(iONode);
  void (*setaddr)(iONode,int);
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
  const char* (*getb0sen)(iONode);
  void (*setb0sen)(iONode,const char*);
  const char* (*getb1sen)(iONode);
  void (*setb1sen)(iONode,const char*);
  const char* (*getb2sen)(iONode);
  void (*setb2sen)(iONode,const char*);
  const char* (*getb3sen)(iONode);
  void (*setb3sen)(iONode,const char*);
  int (*getbit0cmd)(iONode);
  void (*setbit0cmd)(iONode,int);
  int (*getbit1cmd)(iONode);
  void (*setbit1cmd)(iONode,int);
  int (*getbit2cmd)(iONode);
  void (*setbit2cmd)(iONode,int);
  int (*getbit3cmd)(iONode);
  void (*setbit3cmd)(iONode,int);
  int (*getbit4cmd)(iONode);
  void (*setbit4cmd)(iONode,int);
  int (*getbit5cmd)(iONode);
  void (*setbit5cmd)(iONode,int);
  int (*getbridgepos)(iONode);
  void (*setbridgepos)(iONode,int);
  int (*getbus)(iONode);
  void (*setbus)(iONode,int);
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  Boolean (*iscmdbyroute)(iONode);
  void (*setcmdbyroute)(iONode,Boolean);
  int (*getdelay)(iONode);
  void (*setdelay)(iONode,int);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  int (*getdiraddr)(iONode);
  void (*setdiraddr)(iONode,int);
  Boolean (*isembeddedblock)(iONode);
  void (*setembeddedblock)(iONode,Boolean);
  Boolean (*isentering)(iONode);
  void (*setentering)(iONode,Boolean);
  int (*getfun)(iONode);
  void (*setfun)(iONode,int);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  Boolean (*isinv)(iONode);
  void (*setinv)(iONode,Boolean);
  Boolean (*isinvnew)(iONode);
  void (*setinvnew)(iONode,Boolean);
  Boolean (*isinvpos)(iONode);
  void (*setinvpos)(iONode,Boolean);
  int (*getlightsfn)(iONode);
  void (*setlightsfn)(iONode,int);
  const char* (*getlocid)(iONode);
  void (*setlocid)(iONode,const char*);
  Boolean (*ismanager)(iONode);
  void (*setmanager)(iONode,Boolean);
  int (*getmotoroffdelay)(iONode);
  void (*setmotoroffdelay)(iONode,int);
  Boolean (*ismove4opp)(iONode);
  void (*setmove4opp)(iONode,Boolean);
  const char* (*getoid)(iONode);
  void (*setoid)(iONode,const char*);
  int (*getpause)(iONode);
  void (*setpause)(iONode,int);
  int (*getpoladdr)(iONode);
  void (*setpoladdr)(iONode,int);
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
  const char* (*getprot)(iONode);
  void (*setprot)(iONode,const char*);
  const char* (*getpsen)(iONode);
  void (*setpsen)(iONode,const char*);
  int (*getrandomrate)(iONode);
  void (*setrandomrate)(iONode,int);
  Boolean (*isreserved)(iONode);
  void (*setreserved)(iONode,Boolean);
  int (*getresetaddr)(iONode);
  void (*setresetaddr)(iONode,int);
  int (*getresetbitcmd)(iONode);
  void (*setresetbitcmd)(iONode,int);
  int (*getresetport)(iONode);
  void (*setresetport)(iONode,int);
  const char* (*gets1)(iONode);
  void (*sets1)(iONode,const char*);
  const char* (*gets2)(iONode);
  void (*sets2)(iONode,const char*);
  const char* (*getsMid)(iONode);
  void (*setsMid)(iONode,const char*);
  const char* (*getsMid2)(iONode);
  void (*setsMid2)(iONode,const char*);
  Boolean (*issinglegatenew)(iONode);
  void (*setsinglegatenew)(iONode,Boolean);
  Boolean (*issinglegatepos)(iONode);
  void (*setsinglegatepos)(iONode,Boolean);
  const char* (*getstate)(iONode);
  void (*setstate)(iONode,const char*);
  Boolean (*isstate1)(iONode);
  void (*setstate1)(iONode,Boolean);
  Boolean (*isstate2)(iONode);
  void (*setstate2)(iONode,Boolean);
  Boolean (*isstateMid)(iONode);
  void (*setstateMid)(iONode,Boolean);
  Boolean (*isstateMid2)(iONode);
  void (*setstateMid2)(iONode,Boolean);
  Boolean (*isswaprotation)(iONode);
  void (*setswaprotation)(iONode,Boolean);
  Boolean (*isswcmd)(iONode);
  void (*setswcmd)(iONode,Boolean);
  int (*getsymbolsize)(iONode);
  void (*setsymbolsize)(iONode,int);
  Boolean (*istraverser)(iONode);
  void (*settraverser)(iONode,Boolean);
  const char* (*gettype)(iONode);
  void (*settype)(iONode,const char*);
  int (*getx)(iONode);
  void (*setx)(iONode,int);
  int (*gety)(iONode);
  void (*sety)(iONode,int);
  int (*getz)(iONode);
  void (*setz)(iONode,int);
  iONode (*gettrack)(iONode);
  iONode (*nexttrack)(iONode,iONode);
  void (*settrack)(iONode,iONode);
  iONode (*getactionctrl)(iONode);
  iONode (*nextactionctrl)(iONode,iONode);
  void (*setactionctrl)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wTurntable wTurntable;

#ifdef __cplusplus
  }
#endif


#endif
