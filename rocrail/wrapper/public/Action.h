/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_Action_H
#define __WRAPPER_Action_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wAction {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* block_acceptident;
  const char* block_class;
  const char* block_event;
  const char* block_reserve;
  const char* block_schedule;
  const char* block_schedule_manual;
  const char* block_setloc;
  const char* block_unlock;
  const char* fun_off;
  const char* fun_on;
  const char* loco_binstate_off;
  const char* loco_binstate_on;
  const char* loco_carcount;
  const char* loco_class;
  const char* loco_dispatch;
  const char* loco_go;
  const char* loco_percent;
  const char* loco_stop;
  const char* loco_swap;
  const char* loco_velocity;
  const char* loco_velocity2;
  const char* loco_x_go;
  const char* output_active;
  const char* output_off;
  const char* output_on;
  const char* route_lock;
  const char* route_lockset;
  const char* route_set;
  const char* route_unlock;
  const char* signal_green;
  const char* signal_red;
  const char* signal_white;
  const char* signal_yellow;
  const char* sound_play;
  const char* switch_flip;
  const char* switch_left;
  const char* switch_right;
  const char* switch_straight;
  const char* switch_turnout;
  const char* system_go;
  const char* system_shutdown;
  const char* system_stop;
  const char* system_stoplocs;
  const char* test;
  const char* text_update;
  const char* text_value;
  const char* tt_goto;
  const char* tt_turn180;
  const char* type_sound;
  const char* weather_set;
  const char* weather_theme;
  int (*getactiontime)(iONode);
  void (*setactiontime)(iONode,int);
  Boolean (*isactivate)(iONode);
  void (*setactivate)(iONode,Boolean);
  Boolean (*isactivated)(iONode);
  void (*setactivated)(iONode,Boolean);
  int (*getaddr)(iONode);
  void (*setaddr)(iONode,int);
  int (*getbus)(iONode);
  void (*setbus)(iONode,int);
  const char* (*getcmd)(iONode);
  void (*setcmd)(iONode,const char*);
  const char* (*getdesc)(iONode);
  void (*setdesc)(iONode,const char*);
  Boolean (*isdoublequote)(iONode);
  void (*setdoublequote)(iONode,Boolean);
  Boolean (*isevery)(iONode);
  void (*setevery)(iONode,Boolean);
  const char* (*getgroup)(iONode);
  void (*setgroup)(iONode,const char*);
  int (*gethour)(iONode);
  void (*sethour)(iONode,int);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  const char* (*getiid)(iONode);
  void (*setiid)(iONode,const char*);
  int (*getmin)(iONode);
  void (*setmin)(iONode,int);
  const char* (*getoid)(iONode);
  void (*setoid)(iONode,const char*);
  const char* (*getparam)(iONode);
  void (*setparam)(iONode,const char*);
  int (*getport)(iONode);
  void (*setport)(iONode,int);
  Boolean (*israndom)(iONode);
  void (*setrandom)(iONode,Boolean);
  const char* (*getrefid)(iONode);
  void (*setrefid)(iONode,const char*);
  const char* (*getremark)(iONode);
  void (*setremark)(iONode,const char*);
  int (*getsec)(iONode);
  void (*setsec)(iONode,int);
  const char* (*getsndfile)(iONode);
  void (*setsndfile)(iONode,const char*);
  int (*getsndvolume)(iONode);
  void (*setsndvolume)(iONode,int);
  const char* (*getsuboid)(iONode);
  void (*setsuboid)(iONode,const char*);
  Boolean (*istimed)(iONode);
  void (*settimed)(iONode,Boolean);
  int (*gettimer)(iONode);
  void (*settimer)(iONode,int);
  const char* (*gettype)(iONode);
  void (*settype)(iONode,const char*);
  Boolean (*dump)(iONode node);
};

extern struct __wAction wAction;

#ifdef __cplusplus
  }
#endif


#endif
