/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Sep 20 2018 19:13:20)
  * Module: rocview
  * Date: Thu Sep 20 19:13:31 2018
  */

#ifndef __WRAPPER_Gui_H
#define __WRAPPER_Gui_H

#include "rocview/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wGui {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* buildDate;
  const char* buildTime;
  const char* clock_24h;
  const char* clock_ampm;
  const char* clock_default;
  const char* clock_digital;
  const char* clock_none;
  const char* inifile;
  const char* lang_belarus;
  const char* lang_bosnian;
  const char* lang_bulgarian;
  const char* lang_catalan;
  const char* lang_chinese;
  const char* lang_chinesesimplified;
  const char* lang_czech;
  const char* lang_danish;
  const char* lang_dutch;
  const char* lang_english;
  const char* lang_englishAU;
  const char* lang_englishCA;
  const char* lang_englishGB;
  const char* lang_finnish;
  const char* lang_french;
  const char* lang_german;
  const char* lang_greek;
  const char* lang_hungarian;
  const char* lang_indonesian;
  const char* lang_italien;
  const char* lang_japanese;
  const char* lang_korean;
  const char* lang_norwegian;
  const char* lang_polish;
  const char* lang_portuguese;
  const char* lang_portuguesebr;
  const char* lang_romanian;
  const char* lang_russian;
  const char* lang_serbianlatin;
  const char* lang_slovene;
  const char* lang_spanish;
  const char* lang_swedisch;
  const char* lang_turkish;
  int patch;
  const char* previnifile;
  const char* productname;
  const char* releasename;
  const char* releasesuffix;
  int vmajor;
  int vminor;
  Boolean (*ischeckupdates)(iONode);
  void (*setcheckupdates)(iONode,Boolean);
  const char* (*getclocktype)(iONode);
  void (*setclocktype)(iONode,const char*);
  const char* (*getdecpath)(iONode);
  void (*setdecpath)(iONode,const char*);
  const char* (*getdefaultworkspace)(iONode);
  void (*setdefaultworkspace)(iONode,const char*);
  const char* (*getdirimagefwd)(iONode);
  void (*setdirimagefwd)(iONode,const char*);
  const char* (*getdirimagerev)(iONode);
  void (*setdirimagerev)(iONode,const char*);
  Boolean (*isdispatchmode)(iONode);
  void (*setdispatchmode)(iONode,Boolean);
  Boolean (*isfsutf8)(iONode);
  void (*setfsutf8)(iONode,Boolean);
  Boolean (*isgrayicons)(iONode);
  void (*setgrayicons)(iONode,Boolean);
  int (*getgridfontsizeadjust)(iONode);
  void (*setgridfontsizeadjust)(iONode,int);
  const char* (*gethelpurl)(iONode);
  void (*sethelpurl)(iONode,const char*);
  const char* (*gethost)(iONode);
  void (*sethost)(iONode,const char*);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getimagepath)(iONode);
  void (*setimagepath)(iONode,const char*);
  Boolean (*isjssupport)(iONode);
  void (*setjssupport)(iONode,Boolean);
  const char* (*getlang)(iONode);
  void (*setlang)(iONode,const char*);
  Boolean (*islncvtab)(iONode);
  void (*setlncvtab)(iONode,Boolean);
  Boolean (*islocoimagecolumn)(iONode);
  void (*setlocoimagecolumn)(iONode,Boolean);
  Boolean (*islocosortbyaddress)(iONode);
  void (*setlocosortbyaddress)(iONode,Boolean);
  Boolean (*islocowidgetstab)(iONode);
  void (*setlocowidgetstab)(iONode,Boolean);
  int (*getlocowidgetwidth)(iONode);
  void (*setlocowidgetwidth)(iONode,int);
  Boolean (*ismonitoring)(iONode);
  void (*setmonitoring)(iONode,Boolean);
  int (*getmonitorsize)(iONode);
  void (*setmonitorsize)(iONode,int);
  const char* (*getopenpath)(iONode);
  void (*setopenpath)(iONode,const char*);
  Boolean (*isreconnectafterservershutdown)(iONode);
  void (*setreconnectafterservershutdown)(iONode,Boolean);
  Boolean (*isrendergc)(iONode);
  void (*setrendergc)(iONode,Boolean);
  Boolean (*isresetspeeddir)(iONode);
  void (*setresetspeeddir)(iONode,Boolean);
  Boolean (*isrestorelcctrl)(iONode);
  void (*setrestorelcctrl)(iONode,Boolean);
  Boolean (*isrestrictedit4auto)(iONode);
  void (*setrestrictedit4auto)(iONode,Boolean);
  Boolean (*issensormonitorauto)(iONode);
  void (*setsensormonitorauto)(iONode,Boolean);
  Boolean (*isshowlocoimage)(iONode);
  void (*setshowlocoimage)(iONode,Boolean);
  Boolean (*isshowlocoimageinblock)(iONode);
  void (*setshowlocoimageinblock)(iONode,Boolean);
  Boolean (*isshowonlystartschedules)(iONode);
  void (*setshowonlystartschedules)(iONode,Boolean);
  Boolean (*isshowroute4switch)(iONode);
  void (*setshowroute4switch)(iONode,Boolean);
  Boolean (*isshowsecondhand)(iONode);
  void (*setshowsecondhand)(iONode,Boolean);
  Boolean (*isshowspeedometer)(iONode);
  void (*setshowspeedometer)(iONode,Boolean);
  Boolean (*isshowtrainidinblock)(iONode);
  void (*setshowtrainidinblock)(iONode,Boolean);
  Boolean (*issimulatesensors)(iONode);
  void (*setsimulatesensors)(iONode,Boolean);
  const char* (*getspeak4block)(iONode);
  void (*setspeak4block)(iONode,const char*);
  const char* (*getspeakcmd)(iONode);
  void (*setspeakcmd)(iONode,const char*);
  Boolean (*isstartdefaultworkspace)(iONode);
  void (*setstartdefaultworkspace)(iONode,Boolean);
  int (*getstatusboosteruid)(iONode);
  void (*setstatusboosteruid)(iONode,int);
  int (*gettabalign)(iONode);
  void (*settabalign)(iONode,int);
  Boolean (*istoolbar)(iONode);
  void (*settoolbar)(iONode,Boolean);
  const char* (*getupdatespath)(iONode);
  void (*setupdatespath)(iONode,const char*);
  const char* (*getupdatesserver)(iONode);
  void (*setupdatesserver)(iONode,const char*);
  long (*getupdatestimestamp)(iONode);
  void (*setupdatestimestamp)(iONode,long);
  Boolean (*isuseallspeedsteps)(iONode);
  void (*setuseallspeedsteps)(iONode,Boolean);
  Boolean (*isverticaltoolbar)(iONode);
  void (*setverticaltoolbar)(iONode,Boolean);
  const char* (*getxslpath)(iONode);
  void (*setxslpath)(iONode,const char*);
  iONode (*gettrace)(iONode);
  iONode (*nexttrace)(iONode,iONode);
  void (*settrace)(iONode,iONode);
  iONode (*getaccelerator)(iONode);
  iONode (*nextaccelerator)(iONode,iONode);
  void (*setaccelerator)(iONode,iONode);
  iONode (*getworkspaces)(iONode);
  iONode (*nextworkspaces)(iONode,iONode);
  void (*setworkspaces)(iONode,iONode);
  iONode (*getswctrl)(iONode);
  iONode (*nextswctrl)(iONode,iONode);
  void (*setswctrl)(iONode,iONode);
  iONode (*getmgv)(iONode);
  iONode (*nextmgv)(iONode,iONode);
  void (*setmgv)(iONode,iONode);
  iONode (*getrrcon)(iONode);
  iONode (*nextrrcon)(iONode,iONode);
  void (*setrrcon)(iONode,iONode);
  iONode (*getmodpanel)(iONode);
  iONode (*nextmodpanel)(iONode,iONode);
  void (*setmodpanel)(iONode,iONode);
  iONode (*getplanpanel)(iONode);
  iONode (*nextplanpanel)(iONode,iONode);
  void (*setplanpanel)(iONode,iONode);
  iONode (*gettab)(iONode);
  iONode (*nexttab)(iONode,iONode);
  void (*settab)(iONode,iONode);
  iONode (*getsplitpanel)(iONode);
  iONode (*nextsplitpanel)(iONode,iONode);
  void (*setsplitpanel)(iONode,iONode);
  iONode (*getwindow)(iONode);
  iONode (*nextwindow)(iONode,iONode);
  void (*setwindow)(iONode,iONode);
  iONode (*getjsmap)(iONode);
  iONode (*nextjsmap)(iONode,iONode);
  void (*setjsmap)(iONode,iONode);
  iONode (*getmic)(iONode);
  iONode (*nextmic)(iONode,iONode);
  void (*setmic)(iONode,iONode);
  iONode (*getcvconf)(iONode);
  iONode (*nextcvconf)(iONode,iONode);
  void (*setcvconf)(iONode,iONode);
  iONode (*getlcctrl)(iONode);
  iONode (*nextlcctrl)(iONode,iONode);
  void (*setlcctrl)(iONode,iONode);
  iONode (*getpowerctrl)(iONode);
  iONode (*nextpowerctrl)(iONode,iONode);
  void (*setpowerctrl)(iONode,iONode);
  iONode (*getsensormonitor)(iONode);
  iONode (*nextsensormonitor)(iONode,iONode);
  void (*setsensormonitor)(iONode,iONode);
  iONode (*getlocogrid)(iONode);
  iONode (*nextlocogrid)(iONode,iONode);
  void (*setlocogrid)(iONode,iONode);
  Boolean (*dump)(iONode node);
};

extern struct __wGui wGui;

#ifdef __cplusplus
  }
#endif


#endif
