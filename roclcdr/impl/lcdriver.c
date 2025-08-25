/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 


 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "roclcdr/impl/lcdriver_impl.h"

#include "roclcdr/impl/tools/tools.h"
#include "roclcdr/impl/events/events.h"
#include "roclcdr/impl/status/status.h"


#include "rocs/public/trace.h"
#include "rocs/public/node.h"
#include "rocs/public/attr.h"
#include "rocs/public/mem.h"
#include "rocs/public/str.h"
#include "rocs/public/system.h"
#include "rocs/public/strtok.h"

#include "rocrail/public/model.h"

#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/SelTab.h"
#include "rocrail/wrapper/public/Route.h"
#include "rocrail/wrapper/public/Schedule.h"
#include "rocrail/wrapper/public/ScheduleEntry.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/FunCmd.h"
#include "rocrail/wrapper/public/Link.h"
#include "rocrail/wrapper/public/Ctrl.h"
#include "rocrail/wrapper/public/Tour.h"
#include "rocrail/wrapper/public/FeedbackEvent.h"

static int instCnt = 0;

/*
 ***** OBase functions.
 */
static const char* __id( void* inst ) {
  return NULL;
}

static void* __event( void* inst, const void* evt ) {
  return NULL;
}

static const char* __name(void) {
  return name;
}
static unsigned char* __serialize(void* inst, long* size) {
  return NULL;
}
static void __deserialize(void* inst, unsigned char* a) {
}
static char* __toString(void* inst) {
  return "";
}
static void __del(void* inst) {
  iOLcDriverData data = Data(inst);
  freeMem( data );
  freeMem( inst );
  instCnt--;
}
static void* __properties(void* inst) {
  return NULL;
}
static struct OBase* __clone( void* inst ) {
  return NULL;
}
static Boolean __equals( void* inst1, void* inst2 ) {
  return False;
}
static int __count(void) {
  return instCnt;
}


/*
 ***** Public functions.
 */






/**
 * Event handling.
 */
/*
inblock  = speed==0 && fbA==False || speed > 0 && fbB==exit_block
outblock = exitblock_trig==True && fbB==False for more than X second
exit_block  -> ignore multiple within X second
enter_block -> ignore multiple within X second
*/
static void __blockEvent( iOLcDriver inst, obj emitter, int event ) {
  iOLcDriverData data = Data(inst);
  iIBlockBase   block = (iIBlockBase)emitter;

  const char*    blockId = block->base.id( block );
  const char* curBlockId = "";
  const char* dstBlockId = "";


  Boolean curBlockEvent = False;
  Boolean dstBlockEvent = False;

  if( data->curBlock != NULL ) {
    curBlockId = data->curBlock->base.id( data->curBlock  );
    if( data->curBlock == block )
      curBlockEvent = True;
  }

  if( data->next1Block != NULL ) {
    dstBlockId = data->next1Block->base.id( data->next1Block  );
    if( data->next1Block == block )
      dstBlockEvent = True;
  }

  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200,
                 "Block event[%d] from \"%s\". (cur=[%s,%s], dst=[%s,%s])",
                 event, blockId,
                 curBlockEvent?"True":"False", curBlockId,
                 dstBlockEvent?"True":"False", dstBlockId );

  switch( event ) {

  /*---------- TAKEOVER ----------*/
  case takeover_event:
    data->state = LC_MANAGED;
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200, "switch into managed mode");
    break;
  case release_event:
    data->state = LC_IDLE;
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200, "released from managed mode");
    break;


  /*---------- FREE ----------*/
  case free_event:
    eventFree( inst, blockId, block, curBlockEvent, dstBlockEvent );
    break;


  /*---------- ENTER ----------*/
  case enter_event:
    eventEnter( inst, blockId, block, curBlockEvent, dstBlockEvent );
    break;


  /*---------- PRE2IN ----------*/
  /*
    set velocity to V_mid
  */
  case pre2in_event:
    if( wLoc.isinatpre2in( data->loc->base.properties( data->loc ) ) ) {
      eventIn( inst, blockId, block, curBlockEvent, dstBlockEvent, False );
    }
    else
      eventPre2In( inst, blockId, curBlockEvent, dstBlockEvent );
    break;


  /*---------- IN ----------*/
  case shortin_event:
    eventIn( inst, blockId, block, curBlockEvent, dstBlockEvent, True );
    break;
  case in_event:
    eventIn( inst, blockId, block, curBlockEvent, dstBlockEvent, False );
    break;


  /*---------- EXIT ----------*/
  case exit_event:
    eventExit( inst, blockId, curBlockEvent, dstBlockEvent );
    break;



  }
}

static void __checkEventTimeout( iILcDriverInt inst ) {
  iOLcDriverData data = Data(inst);
  if( data->eventTimeoutTime > 0 && data->eventTimeout < data->eventTimeoutTime ) {
    data->eventTimeout++;
    if( data->eventTimeout >= data->eventTimeoutTime ) {
      /* warning */
      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 4000,
                   "Event timeout for [%s]", data->loc->getId( data->loc ) );
      data->loc->event( data->loc, (obj)inst, 0, 0, False, "eventtimeout" );
      data->eventTimeout = 0;
    }
  }

}


static void __checkSignalReset( iILcDriverInt inst ) {
  iOLcDriverData data = Data(inst);
  if( data->signalResetTime > 0 && data->signalReset < data->signalResetTime ) {
    data->signalReset++;
    if( data->signalReset >= data->signalResetTime ) {
      /* TODO: reset signal to red */
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 4200,
                   "signalReset timeout for [%s]", data->loc->getId( data->loc ) );
      resetSignals((iOLcDriver)inst);
    }
  }

}


/**
 * Main entrypoint.
 * Called from iOLoc's run function.
 */
static void _drive( iILcDriverInt inst, obj emitter, int event ) {
  iOLcDriverData data = Data(inst);
  Boolean reverse = False; /* TODO: set the correct reverse value */

  if( event > 0 )
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200, "lcdriver event=%d", event );

  if( emitter != NULL ) {
    __blockEvent( (iOLcDriver)inst, emitter, event );
  }

  /* The state machine. */
  switch( data->state ) {

    case LC_MANAGED:
      break;

    case LC_PRE_WAITBLOCK:
      break;

    case LC_PAUSE:
      statusPause( inst, reverse );
      break;

    case LC_IDLE:
      statusIdle( inst, reverse );
      break;

    case LC_FINDDEST:
      statusFindDest( inst );
      break;


    case LC_INITDEST:
      statusInitDest( inst );
      break;


    case LC_CHECKROUTE:
      statusCheckRoute( inst );
      break;


    case LC_PRE2GO:
      __checkEventTimeout(inst);
      __checkSignalReset(inst);
      statusPre2Go( inst );
      break;


    case LC_GO:
      __checkEventTimeout(inst);
      __checkSignalReset(inst);
      statusGo( inst );
      break;


    case LC_EXITBLOCK:
      statusExit( inst );
      break;

    case LC_OUTBLOCK:
      statusOut( inst );
      break;

    case LC_FREE:
      break;

    case LC_ENTERBLOCK:
      statusEnter( inst, False );
      break;

    case LC_RE_ENTERBLOCK:
      if( data->reentertimer < 1 )
        statusEnter( inst, True );
      else
        data->reentertimer--;
      break;


    case LC_PRE2INBLOCK:
      statusPre2In( inst );
      break;


    case LC_INBLOCK:
      statusIn( inst );
      break;

    case LC_WAITBLOCK:
      statusWait( inst, reverse );
      break;

    case LC_TIMER:
      statusTimer( inst, reverse );
      break;

    case LC_WAIT4EVENT:
      __checkEventTimeout(inst);
      statusWait4Event( inst );
      break;

  }
}

static void _goNet( iILcDriverInt inst, Boolean gomanual, const char* curblock, const char* nextblock, const char* nextroute ) {
  iOLcDriverData data = Data(inst);
  data->gomanual = gomanual;
  data->brake = False;
  data->run = True;
  data->state = LC_INITDEST;
  data->scheduletime = data->model->getTime( data->model );
  data->curBlock   = data->model->getBlock( data->model, curblock );
  data->next1Block = data->model->getBlock( data->model, nextblock );
  data->next1Route = data->model->getRoute( data->model, nextroute );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 4200, "goNet: curblock=%s nextblock=%s nextroute=%s", curblock, nextblock, nextroute );
}


static Boolean __isVirtualSupported(iIBlockBase block) {
  iONode props = block->base.properties(block);
  if( props != NULL ) {
    if( StrOp.equals( wBlock.name(), NodeOp.getName(props) ) ) {
      return True;
    }
    if( StrOp.equals( wSelTab.name(), NodeOp.getName(props) ) ) {
      return True;
    }
  }
  return False;
}

static const char* __getStateName(int state) {
  switch( state ) {
  case LC_IDLE:
    return "IDLE";
  case LC_FINDDEST:
    return "FINDDEST";
  case LC_INITDEST:
    return "INITDEST";
  case LC_CHECKROUTE:
    return "CHECKROUTE";
  case LC_PRE2GO:
    return "PRE2GO";
  case LC_GO:
    return "GO";
  case LC_EXITBLOCK:
    return "EXITBLOCK";
  case LC_OUTBLOCK:
    return "OUTBLOCK";
  case LC_ENTERBLOCK:
    return "ENTERBLOCK";
  case LC_RE_ENTERBLOCK:
    return "RE_ENTERBLOCK";
  case LC_PRE2INBLOCK:
    return "PRE2INBLOCK";
  case LC_INBLOCK:
    return "INBLOCK";
  case LC_PRE_WAITBLOCK:
    return "PRE_WAITBLOCK";
  case LC_WAITBLOCK:
    return "WAITBLOCK";
  case LC_TIMER:
    return "TIMER";
  case LC_WAIT4EVENT:
    return "WAIT4EVENT";
  case LC_PAUSE:
    return "PAUSE";
  case LC_MANAGED:
    return "MANAGED";
  }
  return "UNKNOWN";
}

static Boolean _stepvirtual( iILcDriverInt inst ) {
  iOLcDriverData data = Data(inst);
  Boolean rc = True;
  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200, "step virtual [%s] state=[%s]...", data->loc->getId(data->loc), __getStateName(data->state) );
  if( data->state == LC_GO ) {
    if( data->next1Block != NULL ) {
      if( __isVirtualSupported( data->next1Block) ) {
        iONode fbevt = NodeOp.inst(wFeedbackEvent.name(), NULL, ELEMENT_NODE );
        wFeedbackEvent.setid(fbevt, data->loc->getId(data->loc));
        wFeedbackEvent.setaction(fbevt, wFeedbackEvent.enter2in_event);
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200, "send virtual event to [%s][%s]", data->next1Block->base.name(), data->next1Block->base.id(data->next1Block) );
        data->next1Block->event(data->next1Block, True, "enter", NULL, NULL, NULL, NULL, 0, 0, fbevt, True );
        NodeOp.base.del(fbevt);
      }
      else {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200, "block type [%s][%s] is not supported in virtual mode", data->next1Block->base.name(), data->next1Block->base.id(data->next1Block) );
        rc = False;
      }
    }
  }
  return rc;
}


static void _gogo( iILcDriverInt inst ) {
  iOLcDriverData data = Data(inst);
  if( data->timer > 0 ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200, "reset wait timer for %s from %d to 0", data->loc->getId(data->loc), data->timer );
    data->timer = 0;
    data->forceDeparture = True;
  }
  if( data->reqstop ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200, "reset stop request for %s", data->loc->getId(data->loc) );
    data->reqstop = False;
  }
}

static void _go( iILcDriverInt inst, Boolean gomanual ) {
  iOLcDriverData data = Data(inst);
  data->gomanual = gomanual;
  if( data->brake )
    data->brake = False;
  if( !data->run && !data->pending ) {
    data->state = LC_IDLE;
    data->loc->setMode(data->loc, wLoc.mode_idle, "");
    data->run = True;
    data->scheduletime = data->model->getTime( data->model );
  }
  else if( data->run && !data->pending && !data->reqstop ) {
    data->state = LC_IDLE;
    data->loc->setMode(data->loc, wLoc.mode_idle, "");
  }
}

static void _stop( iILcDriverInt inst ) {
  iOLcDriverData data = Data(inst);
  if( data->run ) {
    data->reqstop = True;
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 4200,
                   "stop event for \"%s\"...",
                   data->loc->getId( data->loc ) );
  }
}

/**
 * The locomotive did caused an **in** event on the remote system.
 * Put the locomotive into the IDLE state.
 */
static void _stopNet( iILcDriverInt inst ) {
  iOLcDriverData data = Data(inst);
  data->state = LC_IDLE;
  data->run = False;
  data->loc->setMode(data->loc, wLoc.mode_idle, "");

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 4200,
                   "stopNet event for [%s]; **IDLE**",
                   data->loc->getId( data->loc ) );
}

static Boolean _isRun( iILcDriverInt inst ) {
  iOLcDriverData data = Data(inst);
  return data->run;
}

static void _brake( iILcDriverInt inst ) {
  iOLcDriverData data = Data(inst);
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  data->brake = True;
  wLoc.setV( cmd, 0 );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 4200, "brake event for \"%s\"...", data->loc->getId( data->loc ) );
  data->loc->cmd( data->loc, cmd );
}

static void _reset( iILcDriverInt inst, Boolean saveCurBlock ) {
  iOLcDriverData data = Data(inst);
  data->run = False;
  data->pending = False;
  data->reqstop = False;
  data->state = LC_IDLE;
  data->loc->setMode(data->loc, wLoc.mode_idle, "");
  LcDriverOp.brake( inst );
  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200,
                 "reset event for [%s], unlocking groups and routes...",
                 data->loc->getId( data->loc ) );
  /* unlock routes */
  if( data->blockgroup != NULL ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200, "unlocking blockgroup for %s...", data->loc->getId( data->loc ));
    unlockBlockGroup( (iOLcDriver)inst, data->blockgroup );
  }

  if( data->next1Route != NULL ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200, "unlocking next1Route for %s...", data->loc->getId( data->loc ));
    data->next1Route->unLock( data->next1Route, data->loc->getId( data->loc ), NULL, True, False );
  }
  if( data->next2Route != NULL ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200, "unlocking next2Route for %s...", data->loc->getId( data->loc ));
    data->next2Route->unLock( data->next2Route, data->loc->getId( data->loc ), NULL, True, False );
}
  if( data->next3Route != NULL ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200, "unlocking next3Route for %s...", data->loc->getId( data->loc ));
    data->next3Route->unLock( data->next3Route, data->loc->getId( data->loc ), NULL, True, False );
  }

  if( data->curBlock == NULL ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200, "getting curBlock for %s...", data->loc->getId( data->loc ));
    data->curBlock = data->model->getBlock( data->model, data->loc->getCurBlock( data->loc ) );
  }


  if( data->prevBlock != NULL && data->prevBlock != data->curBlock ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200, "unlocking prevBlock for %s...", data->loc->getId( data->loc ));
    data->prevBlock->unLock( data->prevBlock, data->loc->getId( data->loc ), NULL );
  }

  if( data->next1Block != NULL && data->next1Block != data->curBlock ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200, "unlocking next1Block for %s...", data->loc->getId( data->loc ));
    data->next1Block->unLock( data->next1Block, data->loc->getId( data->loc ), NULL );
  }
  if( data->next2Block != NULL && data->next2Block != data->curBlock ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200, "unlocking next2Block for %s...", data->loc->getId( data->loc ));
    data->next2Block->unLock( data->next2Block, data->loc->getId( data->loc ), NULL );
  }
  if( data->next3Block != NULL && data->next3Block != data->curBlock ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200, "unlocking next3Block for %s...", data->loc->getId( data->loc ));
    data->next3Block->unLock( data->next3Block, data->loc->getId( data->loc ), NULL );
  }

  data->next1Route = NULL;
  data->next2Route = NULL;
  data->next3Route = NULL;
  data->prevBlock  = NULL;
  data->next1Block = NULL;
  data->next2Block = NULL;
  data->next3Block = NULL;

  if( data->curBlock != NULL && !saveCurBlock ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4200, "unlocking curBlock for %s...", data->loc->getId( data->loc ));
    data->curBlock->unLock( data->curBlock, data->loc->getId( data->loc ), NULL );
    data->curBlock = NULL;
    data->loc->setCurBlock( data->loc, NULL );
  }

}

static void _info( iILcDriverInt inst, iONode info ) {
  iOLcDriverData data = Data(inst);
}

static void _curblock( iILcDriverInt inst, const char* blockid ) {
  iOLcDriverData data = Data(inst);
  data->prevBlock = NULL;
  data->curBlock  = data->model->getBlock( data->model, blockid );
}

static const char* _getCurblock( iILcDriverInt inst ) {
  iOLcDriverData data = Data(inst);
  if( data->curBlock!= NULL )
    return data->curBlock->base.id( data->curBlock );
  else
    return NULL;
}

static const char* _getCurroute( iILcDriverInt inst ) {
  iOLcDriverData data = Data(inst);
  if( data->next1Route!= NULL )
    return data->next1Route->base.id( data->next1Route );
  else
    return NULL;
}

static void _gotoblock( iILcDriverInt inst, const char* blockid ) {
  iOLcDriverData data = Data(inst);
  data->gotoBlock = blockid;
  data->schedule = NULL;
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 4200,
                 "gotoblock \"%s\" for \"%s\"...",
                 blockid,
                 data->loc->getId( data->loc ) );
}

static const char* _getGotoblock( iILcDriverInt inst ) {
  iOLcDriverData data = Data(inst);
  return data->gotoBlock;
}

static int _getScheduleIdx( iILcDriverInt inst ) {
  iOLcDriverData data = Data(inst);
  if( data->schedule != NULL )
    return data->scheduleIdx;
  else
    return -1;
}

static void _useschedule( iILcDriverInt inst, const char* scheduleid ) {
  iOLcDriverData data = Data(inst);
  data->schedule = scheduleid;
  data->scheduleIdx = 0;
  data->scheduleCycle = 0;
  data->prewaitScheduleIdx = -1;
  data->entryActionsChecked = -1;

  /* init schedule index in case the train is not placed in the first entry: */
  data->scheduleIdx = data->model->getScheduleIndex( data->model, data->schedule, data->loc->getCurBlock( data->loc ), data->loc );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 4200,
                 "use schedule [%s] for [%s] with index=%d...",
                 scheduleid, data->loc->getId( data->loc ), data->scheduleIdx );
}

static void _usetour( iILcDriverInt inst, const char* tourid ) {
  iOLcDriverData data = Data(inst);
  data->tour = tourid;
  data->tourIdx = 0;

  iONode tour = data->model->getTour(data->model, data->tour);
  if( tour != NULL ) {
    iOStrTok tok = StrTokOp.inst(wTour.getschedules(tour), ',');
    while( StrTokOp.hasMoreTokens(tok) ) {
      int scheduleIdx = 0;
      iORoute route = NULL;
      const char* scid = StrTokOp.nextToken(tok);
      route = data->model->calcRouteFromCurBlock( data->model, (iOList)NULL, scid, &scheduleIdx,
                                                    data->loc->getCurBlock( data->loc ), NULL, data->loc, False, &data->indelay, False );
      if( route != NULL )
        break;
      data->tourIdx++;
    }
    StrTokOp.base.del(tok);
    if( data->tourIdx > 0 ) {
      data->scheduleended = True;
    }
  }
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 4200,
                 "use tour [%s][%d] for loco [%s]",
                 tourid, data->tourIdx, data->loc->getId( data->loc ) );
}

static const char* _getschedule( iILcDriverInt inst ) {
  iOLcDriverData data = Data(inst);
  return data->schedule;
}

static const char* _gettour( iILcDriverInt inst ) {
  iOLcDriverData data = Data(inst);
  return data->tour;
}

/* VERSION: */
static int vmajor = 2;
static int vminor = 0;
static int patch  = 0;
static int _version( obj inst ) {
  iOLcDriverData data = Data(inst);
  return vmajor*10000 + vminor*100 + patch;
}

static iOLcDriver _inst( const iOLoc loc, const iOModel model, const iOTrace trace, iONode ctrl  ) {
  iOLcDriver     lcdriver = allocMem( sizeof( struct OLcDriver ) );
  iOLcDriverData data     = allocMem( sizeof( struct OLcDriverData ) );

  /* OBase operations */
  MemOp.basecpy( lcdriver, &LcDriverOp, 0, sizeof( struct OLcDriver ), data );

  TraceOp.set( trace );

  data->loc               = loc;
  data->state             = LC_IDLE;
  data->model             = model;
  data->ignevt            = wCtrl.getignevt(ctrl);
  data->secondnextblock   = wCtrl.issecondnextblock(ctrl);
  data->eventTimeoutTime  = wCtrl.geteventtimeout(ctrl) * 10;
  data->signalResetTime   = wCtrl.getsignalreset(ctrl) * 10;
  data->greenaspect       = wCtrl.isgreenaspect(ctrl);
  data->semaphoreWait     = wCtrl.getsemaphorewait(ctrl) * 1000;
  data->signalWait        = wCtrl.getsignalwait(ctrl) * 1000;
  data->stopnonecommuter  = wCtrl.isstopnonecommuter(ctrl);
  data->stopatin4gomanual = wCtrl.isstopatin4gomanual(ctrl);

  instCnt++;

  SystemOp.inst();

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "LcDriver %d.%d.%d loaded for %s", vmajor, vminor, patch, loc->getId( loc ) );

  return lcdriver;
}

/* Support for dynamic Loading */
iILcDriverInt rocGetLcDrInt( const iOLoc loc, const iOModel model, const iOTrace trc, iONode ctrl )
{
	return (iILcDriverInt)_inst( loc, model, trc, ctrl );
}

/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "roclcdr/impl/lcdriver.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
