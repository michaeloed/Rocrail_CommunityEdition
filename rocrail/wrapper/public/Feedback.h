/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Feedback_H
#define __WRAPPER_Feedback_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wFeedback {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int fbtype_barcode;
  int fbtype_gps;
  int fbtype_lissy;
  int fbtype_railcom;
  int fbtype_rfid;
  int fbtype_sensor;
  int fbtype_transponder;
  int fbtype_wheelcounter;
  const char* reset;
  const char* resetstatus;
  const char* setcounterval;
  const char* signalquality;
  int (*getaccnr)(iONode);
  void (*setaccnr)(iONode,int);
  Boolean (*isactivelow)(iONode);
  void (*setactivelow)(iONode,Boolean);
  int (*getaddr)(iONode);
  void (*setaddr)(iONode,int);
  const char* (*getblockid)(iONode);
  void (*setblockid)(iONode,const char*);
  int (*getbus)(iONode);
  void (*setbus)(iONode,int);
  int (*getcarcount)(iONode);
  void (*setcarcount)(iONode,int);
  int (*getcategory)(iONode);
  void (*setcategory)(iONode,int);
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  int (*getcountedcars)(iONode);
  void (*setcountedcars)(iONode,int);
  int (*getcounter)(iONode);
  void (*setcounter)(iONode,int);
  int (*getctcaddr)(iONode);
  void (*setctcaddr)(iONode,int);
  Boolean (*isctcasswitch)(iONode);
  void (*setctcasswitch)(iONode,Boolean);
  int (*getctcbus)(iONode);
  void (*setctcbus)(iONode,int);
  int (*getctcgate)(iONode);
  void (*setctcgate)(iONode,int);
  const char* (*getctciid)(iONode);
  void (*setctciid)(iONode,const char*);
  int (*getctcport)(iONode);
  void (*setctcport)(iONode,int);
  Boolean (*iscurve)(iONode);
  void (*setcurve)(iONode,Boolean);
  int (*getcutoutaddr)(iONode);
  void (*setcutoutaddr)(iONode,int);
  int (*getcutoutbus)(iONode);
  void (*setcutoutbus)(iONode,int);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  Boolean (*isdirection)(iONode);
  void (*setdirection)(iONode,Boolean);
  int (*getfbtype)(iONode);
  void (*setfbtype)(iONode,int);
  int (*getgpssid)(iONode);
  void (*setgpssid)(iONode,int);
  int (*getgpstime)(iONode);
  void (*setgpstime)(iONode,int);
  int (*getgpstolx)(iONode);
  void (*setgpstolx)(iONode,int);
  int (*getgpstoly)(iONode);
  void (*setgpstoly)(iONode,int);
  int (*getgpstolz)(iONode);
  void (*setgpstolz)(iONode,int);
  int (*getgpsx)(iONode);
  void (*setgpsx)(iONode,int);
  int (*getgpsy)(iONode);
  void (*setgpsy)(iONode,int);
  int (*getgpsz)(iONode);
  void (*setgpsz)(iONode,int);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getidentifier)(iONode);
  void (*setidentifier)(iONode,const char*);
  const char* (*getidentifier2)(iONode);
  void (*setidentifier2)(iONode,const char*);
  const char* (*getidentifier3)(iONode);
  void (*setidentifier3)(iONode,const char*);
  const char* (*getidentifier4)(iONode);
  void (*setidentifier4)(iONode,const char*);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  const char* (*getinfo)(iONode);
  void (*setinfo)(iONode,const char*);
  int (*getload)(iONode);
  void (*setload)(iONode,int);
  const char* (*getlocoid)(iONode);
  void (*setlocoid)(iONode,const char*);
  int (*getmaxload)(iONode);
  void (*setmaxload)(iONode,int);
  const char* (*getoid)(iONode);
  void (*setoid)(iONode,const char*);
  const char* (*getori)(iONode);
  void (*setori)(iONode,const char*);
  Boolean (*isresetwc)(iONode);
  void (*setresetwc)(iONode,Boolean);
  Boolean (*isshortcut)(iONode);
  void (*setshortcut)(iONode,Boolean);
  Boolean (*isshow)(iONode);
  void (*setshow)(iONode,Boolean);
  int (*getsignal)(iONode);
  void (*setsignal)(iONode,int);
  Boolean (*isstate)(iONode);
  void (*setstate)(iONode,Boolean);
  int (*gettimer)(iONode);
  void (*settimer)(iONode,int);
  int (*getval)(iONode);
  void (*setval)(iONode,int);
  int (*getwheelcount)(iONode);
  void (*setwheelcount)(iONode,int);
  int (*getx)(iONode);
  void (*setx)(iONode,int);
  int (*gety)(iONode);
  void (*sety)(iONode,int);
  int (*getz)(iONode);
  void (*setz)(iONode,int);
  const char* (*getzone)(iONode);
  void (*setzone)(iONode,const char*);
  iONode (*getactionctrl)(iONode);
  iONode (*nextactionctrl)(iONode,iONode);
  void (*setactionctrl)(iONode,iONode);
  iONode (*getfbstatistic)(iONode);
  iONode (*nextfbstatistic)(iONode,iONode);
  void (*setfbstatistic)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wFeedback wFeedback;

#ifdef __cplusplus
  }
#endif


#endif
