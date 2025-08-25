/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:34 2018
  */

#ifndef __WRAPPER_Program_H
#define __WRAPPER_Program_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wProgram {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  int acc_getparam;
  int acc_setparam;
  int bootmode;
  int datarsp;
  int evclrall;
  int evdelete;
  int evget;
  int evgetall;
  int evgetvar;
  int evset;
  int fb_setaddr;
  int get;
  int getlasterror;
  int getoptions;
  int identify;
  int learn;
  int lncvend;
  int lncvget;
  int lncvset;
  int lncvstart;
  int lntype_bidib;
  int lntype_cbus;
  int lntype_cs;
  int lntype_cv;
  int lntype_hue;
  int lntype_mp;
  int lntype_none;
  int lntype_opsw;
  int lntype_rocnet;
  int lntype_sv;
  int load;
  int macro_delete;
  int macro_get;
  int macro_getparams;
  int macro_restore;
  int macro_save;
  int macro_set;
  int macro_setparams;
  int mode_direct;
  int mode_page;
  int mode_register;
  int mprsp;
  int nnconf;
  int nnreq;
  int nvget;
  int nvset;
  int ping;
  int pomack;
  int porttype_analog;
  int porttype_backlight;
  int porttype_light;
  int porttype_macro;
  int porttype_motor;
  int porttype_servo;
  int porttype_sound;
  int porttype_switch;
  int ptoff;
  int pton;
  int ptstat;
  int query;
  int raw;
  int rc_error;
  int rc_notfwup;
  int rc_ok;
  int reset;
  int save;
  int set;
  int setchannel;
  int setoptions;
  int setstring;
  int show;
  int statusrsp;
  int type;
  int unlearn;
  int update;
  int vendorcvenable;
  int vendorcvget;
  int vendorcvset;
  int writehex;
  Boolean (*isacc)(iONode);
  void (*setacc)(iONode,Boolean);
  int (*getaddr)(iONode);
  void (*setaddr)(iONode,int);
  int (*getcmd)(iONode);
  void (*setcmd)(iONode,int);
  int (*getcv)(iONode);
  void (*setcv)(iONode,int);
  int (*getdecaddr)(iONode);
  void (*setdecaddr)(iONode,int);
  Boolean (*iseeprom)(iONode);
  void (*seteeprom)(iONode,Boolean);
  const char* (*getfilename)(iONode);
  void (*setfilename)(iONode,const char*);
  const char* (*getidentifier)(iONode);
  void (*setidentifier)(iONode,const char*);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  Boolean (*islncv)(iONode);
  void (*setlncv)(iONode,Boolean);
  int (*getlncvcmd)(iONode);
  void (*setlncvcmd)(iONode,int);
  int (*getlntype)(iONode);
  void (*setlntype)(iONode,int);
  Boolean (*islongaddr)(iONode);
  void (*setlongaddr)(iONode,Boolean);
  int (*getmanu)(iONode);
  void (*setmanu)(iONode,int);
  int (*getmode)(iONode);
  void (*setmode)(iONode,int);
  int (*getmodid)(iONode);
  void (*setmodid)(iONode,int);
  Boolean (*ispom)(iONode);
  void (*setpom)(iONode,Boolean);
  int (*getporttype)(iONode);
  void (*setporttype)(iONode,int);
  int (*getprod)(iONode);
  void (*setprod)(iONode,int);
  int (*getrc)(iONode);
  void (*setrc)(iONode,int);
  int (*getrs)(iONode);
  void (*setrs)(iONode,int);
  const char* (*getstrval1)(iONode);
  void (*setstrval1)(iONode,const char*);
  const char* (*getstrval2)(iONode);
  void (*setstrval2)(iONode,const char*);
  const char* (*getstrval3)(iONode);
  void (*setstrval3)(iONode,const char*);
  int (*getval1)(iONode);
  void (*setval1)(iONode,int);
  int (*getval10)(iONode);
  void (*setval10)(iONode,int);
  int (*getval11)(iONode);
  void (*setval11)(iONode,int);
  int (*getval12)(iONode);
  void (*setval12)(iONode,int);
  int (*getval13)(iONode);
  void (*setval13)(iONode,int);
  int (*getval14)(iONode);
  void (*setval14)(iONode,int);
  int (*getval15)(iONode);
  void (*setval15)(iONode,int);
  int (*getval16)(iONode);
  void (*setval16)(iONode,int);
  int (*getval17)(iONode);
  void (*setval17)(iONode,int);
  int (*getval18)(iONode);
  void (*setval18)(iONode,int);
  int (*getval19)(iONode);
  void (*setval19)(iONode,int);
  int (*getval2)(iONode);
  void (*setval2)(iONode,int);
  int (*getval20)(iONode);
  void (*setval20)(iONode,int);
  int (*getval21)(iONode);
  void (*setval21)(iONode,int);
  int (*getval22)(iONode);
  void (*setval22)(iONode,int);
  int (*getval23)(iONode);
  void (*setval23)(iONode,int);
  int (*getval24)(iONode);
  void (*setval24)(iONode,int);
  int (*getval25)(iONode);
  void (*setval25)(iONode,int);
  int (*getval26)(iONode);
  void (*setval26)(iONode,int);
  int (*getval27)(iONode);
  void (*setval27)(iONode,int);
  int (*getval28)(iONode);
  void (*setval28)(iONode,int);
  int (*getval29)(iONode);
  void (*setval29)(iONode,int);
  int (*getval3)(iONode);
  void (*setval3)(iONode,int);
  int (*getval30)(iONode);
  void (*setval30)(iONode,int);
  int (*getval31)(iONode);
  void (*setval31)(iONode,int);
  int (*getval32)(iONode);
  void (*setval32)(iONode,int);
  int (*getval33)(iONode);
  void (*setval33)(iONode,int);
  int (*getval34)(iONode);
  void (*setval34)(iONode,int);
  int (*getval35)(iONode);
  void (*setval35)(iONode,int);
  int (*getval36)(iONode);
  void (*setval36)(iONode,int);
  int (*getval37)(iONode);
  void (*setval37)(iONode,int);
  int (*getval38)(iONode);
  void (*setval38)(iONode,int);
  int (*getval39)(iONode);
  void (*setval39)(iONode,int);
  int (*getval4)(iONode);
  void (*setval4)(iONode,int);
  int (*getval40)(iONode);
  void (*setval40)(iONode,int);
  int (*getval41)(iONode);
  void (*setval41)(iONode,int);
  int (*getval42)(iONode);
  void (*setval42)(iONode,int);
  int (*getval43)(iONode);
  void (*setval43)(iONode,int);
  int (*getval44)(iONode);
  void (*setval44)(iONode,int);
  int (*getval45)(iONode);
  void (*setval45)(iONode,int);
  int (*getval46)(iONode);
  void (*setval46)(iONode,int);
  int (*getval47)(iONode);
  void (*setval47)(iONode,int);
  int (*getval48)(iONode);
  void (*setval48)(iONode,int);
  int (*getval49)(iONode);
  void (*setval49)(iONode,int);
  int (*getval5)(iONode);
  void (*setval5)(iONode,int);
  int (*getval50)(iONode);
  void (*setval50)(iONode,int);
  int (*getval6)(iONode);
  void (*setval6)(iONode,int);
  int (*getval7)(iONode);
  void (*setval7)(iONode,int);
  int (*getval8)(iONode);
  void (*setval8)(iONode,int);
  int (*getval9)(iONode);
  void (*setval9)(iONode,int);
  int (*getvalue)(iONode);
  void (*setvalue)(iONode,int);
  int (*getversion)(iONode);
  void (*setversion)(iONode,int);
  Boolean (*dump)(iONode node);
};

extern struct __wProgram wProgram;

#ifdef __cplusplus
  }
#endif


#endif
