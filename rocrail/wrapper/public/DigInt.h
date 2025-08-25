/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_DigInt_H
#define __WRAPPER_DigInt_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wDigInt {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* barjut;
  const char* bidib;
  const char* cbus;
  const char* clock;
  const char* cti;
  const char* cts;
  const char* dcc232;
  const char* dccar;
  const char* ddx;
  const char* dinamo;
  const char* dmx4all;
  const char* dmxartnet;
  const char* dmxeurolite;
  const char* dsr;
  const char* easydcc;
  const char* ecos;
  const char* editspro;
  const char* esunavi;
  const char* even;
  const char* got;
  const char* hsi88;
  const char* hue;
  const char* infracar;
  const char* inter10;
  const char* lenz;
  const char* loconet;
  const char* lrc135;
  const char* massoth;
  const char* mcs2;
  const char* mgbox;
  const char* mttmfcc;
  const char* muet;
  const char* nce;
  const char* no;
  const char* none;
  const char* odd;
  const char* om32;
  const char* opendcc;
  const char* p50;
  const char* p50x;
  const char* perir;
  const char* raptor;
  const char* rclink;
  const char* rfid12;
  const char* rmx;
  const char* rocnet;
  const char* roco;
  const char* rocomp;
  const char* slx;
  const char* spl;
  const char* sprog;
  const char* srcp;
  const char* sublib_default;
  const char* sublib_digitrax_pr3;
  const char* sublib_lenz_atlas;
  const char* sublib_lenz_cttran;
  const char* sublib_lenz_elite;
  const char* sublib_lenz_ethernet;
  const char* sublib_lenz_opendcc;
  const char* sublib_lenz_xntcp;
  const char* sublib_native;
  const char* sublib_serial;
  const char* sublib_socket;
  const char* sublib_tcp;
  const char* sublib_udp;
  const char* sublib_ulni;
  const char* sublib_usb;
  const char* tamsmc;
  const char* ucons88;
  const char* vcs;
  const char* xnmm;
  const char* xon;
  const char* xpressnet;
  const char* z21;
  const char* zimo;
  const char* zimobin;
  const char* zimocan;
  const char* zs2;
  Boolean (*isasciiprotocol)(iONode);
  void (*setasciiprotocol)(iONode,Boolean);
  int (*getbits)(iONode);
  void (*setbits)(iONode,int);
  int (*getbps)(iONode);
  void (*setbps)(iONode,int);
  int (*getctsretry)(iONode);
  void (*setctsretry)(iONode,int);
  const char* (*getdevice)(iONode);
  void (*setdevice)(iONode,const char*);
  Boolean (*isdummyio)(iONode);
  void (*setdummyio)(iONode,Boolean);
  Boolean (*isfastclock)(iONode);
  void (*setfastclock)(iONode,Boolean);
  int (*getfbmod)(iONode);
  void (*setfbmod)(iONode,int);
  int (*getfboffset)(iONode);
  void (*setfboffset)(iONode,int);
  Boolean (*isfbpoll)(iONode);
  void (*setfbpoll)(iONode,Boolean);
  Boolean (*isfbreset)(iONode);
  void (*setfbreset)(iONode,Boolean);
  const char* (*getflow)(iONode);
  void (*setflow)(iONode,const char*);
  const char* (*gethost)(iONode);
  void (*sethost)(iONode,const char*);
  int (*getidentdelay)(iONode);
  void (*setidentdelay)(iONode,int);
  Boolean (*isignorebusy)(iONode);
  void (*setignorebusy)(iONode,Boolean);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  const char* (*getiid_master)(iONode);
  void (*setiid_master)(iONode,const char*);
  const char* (*getiid_slave)(iONode);
  void (*setiid_slave)(iONode,const char*);
  const char* (*getlib)(iONode);
  void (*setlib)(iONode,const char*);
  const char* (*getlibpath)(iONode);
  void (*setlibpath)(iONode,const char*);
  const char* (*getlocalip)(iONode);
  void (*setlocalip)(iONode,const char*);
  Boolean (*islocolist)(iONode);
  void (*setlocolist)(iONode,Boolean);
  Boolean (*isoverrule)(iONode);
  void (*setoverrule)(iONode,Boolean);
  const char* (*getparity)(iONode);
  void (*setparity)(iONode,const char*);
  int (*getport)(iONode);
  void (*setport)(iONode,int);
  Boolean (*ispoweratstartup)(iONode);
  void (*setpoweratstartup)(iONode,Boolean);
  Boolean (*ispoweroffexit)(iONode);
  void (*setpoweroffexit)(iONode,Boolean);
  int (*getprotver)(iONode);
  void (*setprotver)(iONode,int);
  int (*getpsleep)(iONode);
  void (*setpsleep)(iONode,int);
  Boolean (*isptsupport)(iONode);
  void (*setptsupport)(iONode,Boolean);
  Boolean (*ispw4acc)(iONode);
  void (*setpw4acc)(iONode,Boolean);
  Boolean (*isreadbidi)(iONode);
  void (*setreadbidi)(iONode,Boolean);
  Boolean (*isreadfb)(iONode);
  void (*setreadfb)(iONode,Boolean);
  Boolean (*isreportstate)(iONode);
  void (*setreportstate)(iONode,Boolean);
  Boolean (*isrestricted)(iONode);
  void (*setrestricted)(iONode,Boolean);
  Boolean (*isrtsdisabled)(iONode);
  void (*setrtsdisabled)(iONode,Boolean);
  Boolean (*isstartpwstate)(iONode);
  void (*setstartpwstate)(iONode,Boolean);
  int (*getstopbits)(iONode);
  void (*setstopbits)(iONode,int);
  Boolean (*isstress)(iONode);
  void (*setstress)(iONode,Boolean);
  const char* (*getsublib)(iONode);
  void (*setsublib)(iONode,const char*);
  Boolean (*isswinvert)(iONode);
  void (*setswinvert)(iONode,Boolean);
  Boolean (*isswitchlist)(iONode);
  void (*setswitchlist)(iONode,Boolean);
  int (*getswtime)(iONode);
  void (*setswtime)(iONode,int);
  Boolean (*issysteminfo)(iONode);
  void (*setsysteminfo)(iONode,Boolean);
  int (*gettimeout)(iONode);
  void (*settimeout)(iONode,int);
  int (*getudpportRX)(iONode);
  void (*setudpportRX)(iONode,int);
  int (*getudpportTX)(iONode);
  void (*setudpportTX)(iONode,int);
  const char* (*getuserid)(iONode);
  void (*setuserid)(iONode,const char*);
  Boolean (*isv0onebreak)(iONode);
  void (*setv0onebreak)(iONode,Boolean);
  iONode (*gethueconfig)(iONode);
  iONode (*nexthueconfig)(iONode,iONode);
  void (*sethueconfig)(iONode,iONode);
  iONode (*gethsi88)(iONode);
  iONode (*nexthsi88)(iONode,iONode);
  void (*sethsi88)(iONode,iONode);
  iONode (*getspl)(iONode);
  iONode (*nextspl)(iONode,iONode);
  void (*setspl)(iONode,iONode);
  iONode (*getopendcc)(iONode);
  iONode (*nextopendcc)(iONode,iONode);
  void (*setopendcc)(iONode,iONode);
  iONode (*getbidib)(iONode);
  iONode (*nextbidib)(iONode,iONode);
  void (*setbidib)(iONode,iONode);
  iONode (*getsrcp)(iONode);
  iONode (*nextsrcp)(iONode,iONode);
  void (*setsrcp)(iONode,iONode);
  iONode (*getddx)(iONode);
  iONode (*nextddx)(iONode,iONode);
  void (*setddx)(iONode,iONode);
  iONode (*getrocnet)(iONode);
  iONode (*nextrocnet)(iONode,iONode);
  void (*setrocnet)(iONode,iONode);
  iONode (*getmcs2)(iONode);
  iONode (*nextmcs2)(iONode,iONode);
  void (*setmcs2)(iONode,iONode);
  iONode (*getdmx)(iONode);
  iONode (*nextdmx)(iONode,iONode);
  void (*setdmx)(iONode,iONode);
  iONode (*getcbus)(iONode);
  iONode (*nextcbus)(iONode,iONode);
  void (*setcbus)(iONode,iONode);
  iONode (*getdcc232)(iONode);
  iONode (*nextdcc232)(iONode,iONode);
  void (*setdcc232)(iONode,iONode);
  iONode (*getloconet)(iONode);
  iONode (*nextloconet)(iONode,iONode);
  void (*setloconet)(iONode,iONode);
  iONode (*getio8255)(iONode);
  iONode (*nextio8255)(iONode,iONode);
  void (*setio8255)(iONode,iONode);
  iONode (*getucons88)(iONode);
  iONode (*nextucons88)(iONode,iONode);
  void (*setucons88)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wDigInt wDigInt;

#ifdef __cplusplus
  }
#endif


#endif
