/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Switch_H
#define __WRAPPER_Switch_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wSwitch {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* accessory;
  const char* ccrossing;
  const char* crossing;
  const char* dcrossing;
  const char* decoupler;
  const char* flip;
  const char* left;
  const char* none;
  const char* prot_DEF;
  const char* prot_DO;
  const char* prot_M;
  const char* prot_MDD;
  const char* prot_N;
  const char* prot_OC32;
  const char* prot_OM32;
  const char* prot_VO;
  const char* right;
  const char* straight;
  const char* subleft;
  const char* subright;
  const char* swtype_default;
  const char* swtype_raster;
  const char* testoff;
  const char* teston;
  const char* threeway;
  const char* turnout;
  const char* twoway;
  const char* unlock;
  const char* unlocked;
  Boolean (*isaccessory)(iONode);
  void (*setaccessory)(iONode,Boolean);
  int (*getaccnr)(iONode);
  void (*setaccnr)(iONode,int);
  Boolean (*isactdelay)(iONode);
  void (*setactdelay)(iONode,Boolean);
  Boolean (*isactivate)(iONode);
  void (*setactivate)(iONode,Boolean);
  int (*getaddr0pol1)(iONode);
  void (*setaddr0pol1)(iONode,int);
  int (*getaddr0pol2)(iONode);
  void (*setaddr0pol2)(iONode,int);
  int (*getaddr1)(iONode);
  void (*setaddr1)(iONode,int);
  int (*getaddr1pol1)(iONode);
  void (*setaddr1pol1)(iONode,int);
  int (*getaddr1pol2)(iONode);
  void (*setaddr1pol2)(iONode,int);
  int (*getaddr2)(iONode);
  void (*setaddr2)(iONode,int);
  const char* (*getblockid)(iONode);
  void (*setblockid)(iONode,const char*);
  int (*getbus)(iONode);
  void (*setbus)(iONode,int);
  int (*getbuspol)(iONode);
  void (*setbuspol)(iONode,int);
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  int (*getcmd_extra)(iONode);
  void (*setcmd_extra)(iONode,int);
  const char* (*getcmd_lcid)(iONode);
  void (*setcmd_lcid)(iONode,const char*);
  Boolean (*iscmd_update)(iONode);
  void (*setcmd_update)(iONode,Boolean);
  int (*getctcaddr1)(iONode);
  void (*setctcaddr1)(iONode,int);
  int (*getctcaddr2)(iONode);
  void (*setctcaddr2)(iONode,int);
  int (*getctcaddrled1)(iONode);
  void (*setctcaddrled1)(iONode,int);
  int (*getctcaddrled2)(iONode);
  void (*setctcaddrled2)(iONode,int);
  Boolean (*isctcasswitchled1)(iONode);
  void (*setctcasswitchled1)(iONode,Boolean);
  Boolean (*isctcasswitchled2)(iONode);
  void (*setctcasswitchled2)(iONode,Boolean);
  int (*getctcbus1)(iONode);
  void (*setctcbus1)(iONode,int);
  int (*getctcbus2)(iONode);
  void (*setctcbus2)(iONode,int);
  int (*getctcbusled1)(iONode);
  void (*setctcbusled1)(iONode,int);
  int (*getctcbusled2)(iONode);
  void (*setctcbusled2)(iONode,int);
  Boolean (*isctccmdon1)(iONode);
  void (*setctccmdon1)(iONode,Boolean);
  Boolean (*isctccmdon2)(iONode);
  void (*setctccmdon2)(iONode,Boolean);
  Boolean (*isctcflip1)(iONode);
  void (*setctcflip1)(iONode,Boolean);
  Boolean (*isctcflip2)(iONode);
  void (*setctcflip2)(iONode,Boolean);
  int (*getctcgateled1)(iONode);
  void (*setctcgateled1)(iONode,int);
  int (*getctcgateled2)(iONode);
  void (*setctcgateled2)(iONode,int);
  const char* (*getctciid1)(iONode);
  void (*setctciid1)(iONode,const char*);
  const char* (*getctciid2)(iONode);
  void (*setctciid2)(iONode,const char*);
  const char* (*getctciidled1)(iONode);
  void (*setctciidled1)(iONode,const char*);
  const char* (*getctciidled2)(iONode);
  void (*setctciidled2)(iONode,const char*);
  int (*getctcportled1)(iONode);
  void (*setctcportled1)(iONode,int);
  int (*getctcportled2)(iONode);
  void (*setctcportled2)(iONode,int);
  int (*getdelay)(iONode);
  void (*setdelay)(iONode,int);
  long (*getdelaytime)(iONode);
  void (*setdelaytime)(iONode,long);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  Boolean (*isdir)(iONode);
  void (*setdir)(iONode,Boolean);
  const char* (*getfb2G)(iONode);
  void (*setfb2G)(iONode,const char*);
  Boolean (*isfb2Ginv)(iONode);
  void (*setfb2Ginv)(iONode,Boolean);
  const char* (*getfb2R)(iONode);
  void (*setfb2R)(iONode,const char*);
  Boolean (*isfb2Rinv)(iONode);
  void (*setfb2Rinv)(iONode,Boolean);
  const char* (*getfbG)(iONode);
  void (*setfbG)(iONode,const char*);
  Boolean (*isfbGinv)(iONode);
  void (*setfbGinv)(iONode,Boolean);
  const char* (*getfbOcc)(iONode);
  void (*setfbOcc)(iONode,const char*);
  const char* (*getfbOcc2)(iONode);
  void (*setfbOcc2)(iONode,const char*);
  const char* (*getfbR)(iONode);
  void (*setfbR)(iONode,const char*);
  Boolean (*isfbRinv)(iONode);
  void (*setfbRinv)(iONode,Boolean);
  Boolean (*isfbset)(iONode);
  void (*setfbset)(iONode,Boolean);
  Boolean (*isfbusefield)(iONode);
  void (*setfbusefield)(iONode,Boolean);
  const char* (*getfieldstate)(iONode);
  void (*setfieldstate)(iONode,const char*);
  Boolean (*isforcecmd)(iONode);
  void (*setforcecmd)(iONode,Boolean);
  Boolean (*isfrogaccessory)(iONode);
  void (*setfrogaccessory)(iONode,Boolean);
  const char* (*getfrogiid)(iONode);
  void (*setfrogiid)(iONode,const char*);
  int (*getfrogporttype)(iONode);
  void (*setfrogporttype)(iONode,int);
  Boolean (*isfrogswitch)(iONode);
  void (*setfrogswitch)(iONode,Boolean);
  int (*getfrogtimer)(iONode);
  void (*setfrogtimer)(iONode,int);
  int (*getgate0pol1)(iONode);
  void (*setgate0pol1)(iONode,int);
  int (*getgate0pol2)(iONode);
  void (*setgate0pol2)(iONode,int);
  int (*getgate1)(iONode);
  void (*setgate1)(iONode,int);
  int (*getgate1pol1)(iONode);
  void (*setgate1pol1)(iONode,int);
  int (*getgate1pol2)(iONode);
  void (*setgate1pol2)(iONode,int);
  int (*getgate2)(iONode);
  void (*setgate2)(iONode,int);
  int (*getgatevalue)(iONode);
  void (*setgatevalue)(iONode,int);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  Boolean (*isinitfield)(iONode);
  void (*setinitfield)(iONode,Boolean);
  Boolean (*isinv)(iONode);
  void (*setinv)(iONode,Boolean);
  Boolean (*isinv2)(iONode);
  void (*setinv2)(iONode,Boolean);
  const char* (*getlocid)(iONode);
  void (*setlocid)(iONode,const char*);
  Boolean (*ismanualcmd)(iONode);
  void (*setmanualcmd)(iONode,Boolean);
  const char* (*getoid)(iONode);
  void (*setoid)(iONode,const char*);
  const char* (*getori)(iONode);
  void (*setori)(iONode,const char*);
  int (*getparam1)(iONode);
  void (*setparam1)(iONode,int);
  int (*getparam2)(iONode);
  void (*setparam2)(iONode,int);
  int (*getpause)(iONode);
  void (*setpause)(iONode,int);
  int (*getport0pol1)(iONode);
  void (*setport0pol1)(iONode,int);
  int (*getport0pol2)(iONode);
  void (*setport0pol2)(iONode,int);
  int (*getport1)(iONode);
  void (*setport1)(iONode,int);
  int (*getport1pol1)(iONode);
  void (*setport1pol1)(iONode,int);
  int (*getport1pol2)(iONode);
  void (*setport1pol2)(iONode,int);
  int (*getport2)(iONode);
  void (*setport2)(iONode,int);
  int (*getporttype)(iONode);
  void (*setporttype)(iONode,int);
  const char* (*getprot)(iONode);
  void (*setprot)(iONode,const char*);
  Boolean (*isrectcrossing)(iONode);
  void (*setrectcrossing)(iONode,Boolean);
  const char* (*getsavepos)(iONode);
  void (*setsavepos)(iONode,const char*);
  Boolean (*isset)(iONode);
  void (*setset)(iONode,Boolean);
  Boolean (*isshow)(iONode);
  void (*setshow)(iONode,Boolean);
  Boolean (*issinglegate)(iONode);
  void (*setsinglegate)(iONode,Boolean);
  const char* (*getstate)(iONode);
  void (*setstate)(iONode,const char*);
  const char* (*getsubtype)(iONode);
  void (*setsubtype)(iONode,const char*);
  Boolean (*isswapstraight)(iONode);
  void (*setswapstraight)(iONode,Boolean);
  int (*getswitched)(iONode);
  void (*setswitched)(iONode,int);
  const char* (*getswtype)(iONode);
  void (*setswtype)(iONode,const char*);
  Boolean (*issyncdelay)(iONode);
  void (*setsyncdelay)(iONode,Boolean);
  Boolean (*istd)(iONode);
  void (*settd)(iONode,Boolean);
  int (*gettdaddr)(iONode);
  void (*settdaddr)(iONode,int);
  const char* (*gettdiid)(iONode);
  void (*settdiid)(iONode,const char*);
  int (*gettdport)(iONode);
  void (*settdport)(iONode,int);
  Boolean (*istesting)(iONode);
  void (*settesting)(iONode,Boolean);
  const char* (*gettype)(iONode);
  void (*settype)(iONode,const char*);
  int (*getvalue1)(iONode);
  void (*setvalue1)(iONode,int);
  int (*getvalue2)(iONode);
  void (*setvalue2)(iONode,int);
  Boolean (*isvirtual)(iONode);
  void (*setvirtual)(iONode,Boolean);
  const char* (*getwantedstate)(iONode);
  void (*setwantedstate)(iONode,const char*);
  int (*getx)(iONode);
  void (*setx)(iONode,int);
  int (*gety)(iONode);
  void (*sety)(iONode,int);
  int (*getz)(iONode);
  void (*setz)(iONode,int);
  iONode (*getactionctrl)(iONode);
  iONode (*nextactionctrl)(iONode,iONode);
  void (*setactionctrl)(iONode,iONode);
  iONode (*getaccessoryctrl)(iONode);
  iONode (*nextaccessoryctrl)(iONode,iONode);
  void (*setaccessoryctrl)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wSwitch wSwitch;

#ifdef __cplusplus
  }
#endif


#endif
