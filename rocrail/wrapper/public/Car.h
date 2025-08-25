/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_Car_H
#define __WRAPPER_Car_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wCar {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* cartype_freight;
  const char* cartype_passenger;
  const char* freight_autocarrier;
  const char* freight_autorack;
  const char* freight_boxcar;
  const char* freight_caboose;
  const char* freight_coilcar;
  const char* freight_flatcar;
  const char* freight_gondola;
  const char* freight_hopper;
  const char* freight_logdumpcar;
  const char* freight_reefer;
  const char* freight_stockcar;
  const char* freight_tankcar;
  const char* freight_wellcar;
  const char* passenger_baggage;
  const char* passenger_coach;
  const char* passenger_dinner;
  const char* passenger_dome;
  const char* passenger_express;
  const char* passenger_lounge;
  const char* passenger_postoffice;
  const char* passenger_sleeper;
  const char* status_empty;
  const char* status_loaded;
  const char* status_maintenance;
  int (*getV_max)(iONode);
  void (*setV_max)(iONode,int);
  int (*getaddr)(iONode);
  void (*setaddr)(iONode,int);
  int (*getbus)(iONode);
  void (*setbus)(iONode,int);
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  const char* (*getcolor)(iONode);
  void (*setcolor)(iONode,const char*);
  Boolean (*iscommuter)(iONode);
  void (*setcommuter)(iONode,Boolean);
  const char* (*getdecfile)(iONode);
  void (*setdecfile)(iONode,const char*);
  int (*getera)(iONode);
  void (*setera)(iONode,int);
  Boolean (*isf0vcmd)(iONode);
  void (*setf0vcmd)(iONode,Boolean);
  int (*getfnlights)(iONode);
  void (*setfnlights)(iONode,int);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getident)(iONode);
  void (*setident)(iONode,const char*);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  const char* (*getimage)(iONode);
  void (*setimage)(iONode,const char*);
  Boolean (*isinvdir)(iONode);
  void (*setinvdir)(iONode,Boolean);
  int (*getlen)(iONode);
  void (*setlen)(iONode,int);
  const char* (*getlocation)(iONode);
  void (*setlocation)(iONode,const char*);
  const char* (*getmanuid)(iONode);
  void (*setmanuid)(iONode,const char*);
  const char* (*getnumber)(iONode);
  void (*setnumber)(iONode,const char*);
  const char* (*getowner)(iONode);
  void (*setowner)(iONode,const char*);
  Boolean (*isplacing)(iONode);
  void (*setplacing)(iONode,Boolean);
  const char* (*getprevlocation1)(iONode);
  void (*setprevlocation1)(iONode,const char*);
  const char* (*getprevlocation2)(iONode);
  void (*setprevlocation2)(iONode,const char*);
  const char* (*getprevlocation3)(iONode);
  void (*setprevlocation3)(iONode,const char*);
  const char* (*getprot)(iONode);
  void (*setprot)(iONode,const char*);
  int (*getprotver)(iONode);
  void (*setprotver)(iONode,int);
  const char* (*getremark)(iONode);
  void (*setremark)(iONode,const char*);
  const char* (*getroadname)(iONode);
  void (*setroadname)(iONode,const char*);
  Boolean (*isshow)(iONode);
  void (*setshow)(iONode,Boolean);
  const char* (*getstatus)(iONode);
  void (*setstatus)(iONode,const char*);
  const char* (*getsubtype)(iONode);
  void (*setsubtype)(iONode,const char*);
  const char* (*gettype)(iONode);
  void (*settype)(iONode,const char*);
  Boolean (*isusedir)(iONode);
  void (*setusedir)(iONode,Boolean);
  Boolean (*isuselights)(iONode);
  void (*setuselights)(iONode,Boolean);
  const char* (*getwaybills)(iONode);
  void (*setwaybills)(iONode,const char*);
  int (*getweight_empty)(iONode);
  void (*setweight_empty)(iONode,int);
  int (*getweight_loaded)(iONode);
  void (*setweight_loaded)(iONode,int);
  iONode (*getcvbyte)(iONode);
  iONode (*nextcvbyte)(iONode,iONode);
  void (*setcvbyte)(iONode,iONode);
  iONode (*getfundef)(iONode);
  iONode (*nextfundef)(iONode,iONode);
  void (*setfundef)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wCar wCar;

#ifdef __cplusplus
  }
#endif


#endif
