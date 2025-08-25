/** ------------------------------------------------------------
  * A U T O   G E N E R A T E D
  * Generator: Rocs wgen (build Aug  3 2018 14:01:31)
  * Module: rocrail
  * Date: Fri Aug  3 14:01:35 2018
  */

#ifndef __WRAPPER_FeedbackEvent_H
#define __WRAPPER_FeedbackEvent_H

#include "rocrail/wrapper/public/wrapper.h"
#include "rocs/public/rocs.h"
#include "rocs/public/objbase.h"
#include "rocs/public/node.h"
#include "rocs/public/str.h"
#ifdef __cplusplus
  extern "C" {
#endif


struct __wFeedbackEvent {
  const char* (*name)(void);
  const char* (*remark)(void);
  Boolean (*required)(void);
  const char* (*cardinality)(void);
  const char* V_cruise_event;
  const char* V_max_event;
  const char* V_mid_event;
  const char* V_min_event;
  const char* enter2in_event;
  const char* enter2pre_event;
  const char* enter2route_event;
  const char* enter2shortin_event;
  const char* enter_event;
  const char* exit_event;
  const char* free_event;
  const char* from_all;
  const char* from_all_reverse;
  const char* ident_event;
  const char* in_event;
  const char* occupied_event;
  const char* pre2in_event;
  const char* section_event;
  const char* shortin_event;
  const char* (*getaction)(iONode);
  void (*setaction)(iONode,const char*);
  const char* (*getbyroute)(iONode);
  void (*setbyroute)(iONode,const char*);
  Boolean (*isendpuls)(iONode);
  void (*setendpuls)(iONode,Boolean);
  const char* (*getfrom)(iONode);
  void (*setfrom)(iONode,const char*);
  const char* (*getid)(iONode);
  void (*setid)(iONode,const char*);
  Boolean (*isuse_timer2)(iONode);
  void (*setuse_timer2)(iONode,Boolean);
  Boolean (*dump)(iONode node);
};

extern struct __wFeedbackEvent wFeedbackEvent;

#ifdef __cplusplus
  }
#endif


#endif
