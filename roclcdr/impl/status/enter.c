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

#include "roclcdr/impl/lcdriver_impl.h"

#include "roclcdr/impl/tools/tools.h"
#include "rocs/public/strtok.h"
#include "rocs/public/system.h"



#include "rocrail/public/model.h"

#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/Route.h"
#include "rocrail/wrapper/public/Schedule.h"
#include "rocrail/wrapper/public/ScheduleEntry.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/FunCmd.h"
#include "rocrail/wrapper/public/Link.h"



void statusEnter( iILcDriverInt inst, Boolean re_enter ) {
  iOLcDriverData data = Data(inst);
  int indelay = 0;
  Boolean oppwait = True;

  /* Signal of destination block; wait or search for next destination? (_event) */
  iONode bkprops = NULL;
  iONode lcprops = (iONode)data->loc->base.properties( data->loc );
  if( data->curBlock == NULL ) {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 4001,
        "Unexpected enter event for \"%s\" state=%d run=%d", data->loc->getId( data->loc ), data->state, data->run );
    data->state = LC_IDLE;
    return;
  }
  bkprops = (iONode)data->curBlock->base.properties( data->curBlock );

  if( data->next1Block == NULL ) {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 4001,
        "Unexpected enter event for \"%s\" state=%d run=%d", data->loc->getId( data->loc ), data->state, data->run );
    data->state = LC_IDLE;
    data->loc->setMode(data->loc, wLoc.mode_idle, wLoc.modereason_unexpectedenter);
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201,
                   "Setting state for \"%s\" from %s to LC_IDLE.",
                   data->loc->getId( data->loc ), re_enter?"LC_RE_ENTERBLOCK":"LC_ENTERBLOCK" );
    return;
  }

  /*
  data->curBlock->red( data->curBlock, True, !data->next1RouteFromTo );
  data->curBlock->red( data->curBlock, False, !data->next1RouteFromTo );
  */

  /* Set the blockside before checking the block wait to get the right manual operated signal. (moved from line 392 on 03-09-2014) */
  if( !re_enter ) {
    if( data->next1Block != NULL ) {
      if( StrOp.equals(data->next1Block->base.id(data->next1Block), data->next1Route->getToBlock(data->next1Route)) )
        data->loc->setBlockEnterSide(data->loc, data->next1Route->getToBlockSide(data->next1Route), data->next1Route->getToBlock(data->next1Route));
      else
        data->loc->setBlockEnterSide(data->loc, data->next1Route->getFromBlockSide(data->next1Route), data->next1Route->getFromBlock(data->next1Route));
    }
    data->next1Block->enterBlock( data->next1Block, data->loc->getId( data->loc ) );
  }


  if( !data->next1Block->wait( data->next1Block, data->loc, !data->next1RouteFromTo, &oppwait ) &&
      data->run &&
      !data->reqstop &&
      !data->next1Block->isTerminalStation(data->next1Block) )
  {

    /* Find and lock next destination block and street... */
    if( data->schedule == NULL || StrOp.len( data->schedule ) == 0 ) {
      if( data->next2Block == NULL ) {
        data->loc->resetPrevBlock(data->loc);
        data->next2Block = data->model->findDest( data->model, data->next1Block->base.id( data->next1Block ),
                                              data->next1Route->base.id( data->next1Route ),
                                              data->loc, &data->next2Route, data->gotoBlock,
                                              data->next1Route->isSwapPost( data->next1Route ), False, False, False );
      }
      else {
        /* next2Block already locked */
      }
    }
    else {
      Boolean wait = False;
      int scheduleIdx = data->scheduleIdx;
      /* find destination using schedule */
      if( data->next2Route == NULL ) {
        data->next2Route = data->model->calcRouteFromCurBlock( data->model, (iOList)NULL,
                                                               data->schedule, &data->scheduleIdx,
                                                               data->next1Block->base.id( data->next1Block ),
                                                               data->next1Route != NULL ? data->next1Route->base.id( data->next1Route ):NULL,
                                                               data->loc,
                                                               data->next1Route->isSwapPost( data->next1Route ),
                                                               &indelay, False);
      }
      else {
        /* next2Route already locked by second next option; adjust the schedule index... */
        data->scheduleIdx += 1;
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201, "adjust the schedule index to %d for second next option", data->scheduleIdx );
      }

      if( wLoc.isusescheduletime( data->loc->base.properties( data->loc ) ) &&
          !checkScheduleTime( inst, data->schedule, scheduleIdx ) )
      {
        wait = True;

        if( scheduleIdx != data->scheduleIdx ) {
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201,
              "schedule index changed from %d to %d", scheduleIdx, data->scheduleIdx );
          data->prewaitScheduleIdx = scheduleIdx;
        }
      }
      else {
        data->prewaitScheduleIdx = -1;
      }

      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201, "checkScheduleEntryActions for entry %d...", scheduleIdx );
      if( checkScheduleEntryActions(inst, scheduleIdx, (wait || data->next2Route == NULL) ) ) {
        /* wait in block if we have to swap placing... */
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 4201, "Wait in block because the schedule entry wants a swap placing..." );
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201, "reset next2Block" );
        resetNext2( (iOLcDriver)inst, True );
        data->pendingSwap = True;
        wait = True;
      }

      if( !wait && data->next2Route != NULL ) {
        /* evaluate direction */
        if( StrOp.equals( data->next2Route->getToBlock( data->next2Route ), data->next1Block->base.id(data->next1Block) ) )
          data->next2Block = data->model->getBlock( data->model, data->next1Route->getFromBlock( data->next2Route ) );
        else
          data->next2Block = data->model->getBlock( data->model, data->next2Route->getToBlock( data->next2Route ) );
      }
      else if( wait ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201, "reset next2Block" );
        resetNext2( (iOLcDriver)inst, True );
      }
      else {
        if( isScheduleEnd(inst) ) {
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 4201, "End of schedule: STOP." );
          checkScheduleEntryActions(inst, -1, False);
          checkScheduleActions(inst, LC_ENTERBLOCK);
        }
        else {
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201, "reset next2Block" );
          resetNext2( (iOLcDriver)inst, True );
        }

      }
    }

    if( data->next2Block != NULL ) {
      /* fix: if a loc is running, and the new destination is opposite, the loc should reject the new destination and stop. */
      Boolean dir = data->next2Route->getDirection( data->next2Route,
                        data->next1Block->base.id(data->next1Block),
                &data->next2RouteFromTo );
      Boolean swapDir = False;
      Boolean dirOK = True;
      Boolean speedAdjusted = False;

      if(re_enter) {
        data->loc->resetBBT(data->loc);
      }

      if( data->next2RouteFromTo )
        swapDir = data->next2Route->isSwapPost( data->next2Route ) ? data->next2RouteFromTo : !data->next2RouteFromTo;
      else
        swapDir = data->next2Route->isSwapPost( data->next2Route ) ? !data->next2RouteFromTo : data->next2RouteFromTo;
      swapDir = dir ? swapDir:!swapDir;
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201,
          "loco direction for [%s] is [%s], route direction [%s]",
                     data->loc->getId( data->loc ), dir?"forwards":"reverse", data->next1RouteFromTo?"fromTo":"toFrom" );

      if( data->loc->getDir( data->loc ) != ( data->next1Route->isSwapPost( data->next1Route ) ? !dir : dir ) ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 4201, "Destination is in opposite direction while running: Reject and wait in block." );

        if( data->next2Route != NULL && data->scheduleIdx > 0 ) {
          /* go one move back in the schedule */
          data->scheduleIdx--;
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 4201, "Set schedule index back to [%d].", data->scheduleIdx );
        }

        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201, "reset next2Block  ***** test with unlock flag *****" );
        resetNext2( (iOLcDriver)inst, True );
        dirOK = False;
      }

      /* Adjust speed in case it should slow down. */
      if( !data->gomanual && !re_enter && data->loc->getV(data->loc) > 0 ) {
        iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
        if( wBlock.getincline( bkprops ) == wBlock.incline_up &&
            data->direction == LC_DIR_FORWARDS &&
            !wLoc.isregulated( data->loc->base.properties( data->loc ) ) ) {
          wLoc.setV_hint( cmd, wLoc.climb );
        }
        else {
          int maxkmh = 0;
          wLoc.setV_hint( cmd, getBlockV_hint(inst, data->next1Block, False, data->next1Route, !data->next1RouteFromTo, &maxkmh ) );
          wLoc.setV_maxkmh(cmd, maxkmh);
        }
        wLoc.setdir( cmd, wLoc.isdir( data->loc->base.properties( data->loc ) ) );

        if( data->loc->compareVhint(data->loc, wLoc.getV_hint(cmd) ) < 0 ) {
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201, "adjust loco speed before setting the route..." );
          data->loc->cmd( data->loc, cmd );
          speedAdjusted = True;
        }
        else {
          NodeOp.base.del(cmd);
        }
      }


      /* Initialize destination. */
      if( dirOK && initializeDestination( (iOLcDriver)inst,
                       data->next2Block,
                       data->next2Route,
                       data->next1Block,
                       swapDir, indelay ) )
      {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 4201,
            "Found destination for \"%s\": \"%s\" (from %s)",
            data->loc->getId( data->loc ), data->next2Block->base.id( data->next2Block ),
            data->next1Block->base.id( data->next1Block ) );
        data->loc->informBlock( data->loc, data->next2Block->base.id( data->next2Block ),
            data->next1Block->base.id( data->next1Block ) );
        data->state = LC_WAIT4EVENT;
        data->eventTimeout = 0;
        data->signalReset  = 0;

        data->loc->setMode(data->loc, wLoc.mode_auto, wLoc.modereason_destfound);
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201,
                       "Setting state for \"%s\" from %s to LC_WAIT4EVENT.",
                       data->loc->getId( data->loc ), re_enter?"LC_RE_ENTERBLOCK":"LC_ENTERBLOCK" );

        if( !data->gomanual && !re_enter && !speedAdjusted ) {
          iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
          if( wBlock.getincline( bkprops ) == wBlock.incline_up &&
              data->direction == LC_DIR_FORWARDS &&
              !wLoc.isregulated( data->loc->base.properties( data->loc ) ) ) {
            wLoc.setV_hint( cmd, wLoc.climb );
          }
          else {
            int maxkmh = 0;
            wLoc.setV_hint( cmd, getBlockV_hint(inst, data->next1Block, False, data->next1Route, !data->next1RouteFromTo, &maxkmh ) );
            wLoc.setV_maxkmh(cmd, maxkmh);

          }

          if( data->loc->isReduceSpeedAtEnter( data->loc) ) {
            if( !StrOp.equals( wLoc.getV_hint( cmd), wLoc.min ) && data->next2Route->hasThrownSwitch(data->next2Route) ) {
              TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "reduce speed at enter for thrown switches");
              if( data->loc->compareVhint( data->loc, wLoc.mid) <= 0 || data->loc->getV( data->loc ) == 0 ) {
                wLoc.setV_hint( cmd, wLoc.mid );
                data->didReduceSpeedAtEnter = True;
              }
            }
          }

          wLoc.setdir( cmd, wLoc.isdir( data->loc->base.properties( data->loc ) ) );
          data->loc->cmd( data->loc, cmd );
        }

      }
      else {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201, "reset next2Block" );
        resetNext2( (iOLcDriver)inst, False );
      }
    }
  }
  else {
    if( data->schedule != NULL && StrOp.len( data->schedule ) > 1 ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201, "checkScheduleEntryActions for entry %d...", data->scheduleIdx );
      if( checkScheduleEntryActions(inst, data->scheduleIdx, False) ) {
        /* wait in block if we have to swap placing... */
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 4201, "the schedule entry wants a swap placing..." );
        data->pendingSwap = True;
      }
    }
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201, "reset next2Block" );
    resetNext2( (iOLcDriver)inst, True );
  }

  /* Wait in block or no new destination found. */
  if( data->next2Block == NULL ) {

    data->state = LC_WAIT4EVENT;
    data->eventTimeout = 0;
    data->signalReset  = 0;
    data->loc->setMode(data->loc, wLoc.mode_wait, wLoc.modereason_waitforevent);
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201,
                   "Setting state for \"%s\" from %s to LC_WAIT4EVENT.",
                   data->loc->getId( data->loc ), re_enter?"LC_RE_ENTERBLOCK":"LC_ENTERBLOCK" );

    if( data->next1Block->hasExtStop(data->next1Block, NULL) ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 4201,
          "block %s has a stop module; not sending velocity hint to loco %s",
          data->next1Block->base.id(data->next1Block), data->loc->getId(data->loc));
    }
    else {
      iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
      /* set V_mid only if it is lower than the current velocity */
      int maxkmh = 0;
      const char* blockV_hint = getBlockV_hint(inst, data->next1Block, False, NULL, !data->next1RouteFromTo, &maxkmh );
      if( data->loc->compareVhint( data->loc, blockV_hint) == -1 )
        wLoc.setV_hint( cmd, blockV_hint );
        wLoc.setV_maxkmh(cmd, maxkmh);

      if( StrOp.equals(blockV_hint, wBlock.cruise) || StrOp.equals(blockV_hint, wBlock.max) ) {
        if( data->loc->compareVhint( data->loc, wBlock.mid) == -1 )
          wLoc.setV_hint( cmd, wBlock.mid );
      }

      if( data->next1Block != NULL ) {
        /* data->curBlock is set after event out_block:
           to be save we must check the data->next1Block here. */
        iONode destbkprops = (iONode)data->next1Block->base.properties( data->next1Block );

        /*
        data->next1Block->red( data->next1Block, True, !data->next2RouteFromTo );
        data->next1Block->red( data->next1Block, False, !data->next2RouteFromTo );
        */

        if( wBlock.getincline( destbkprops ) == wBlock.incline_up &&
            data->direction == LC_DIR_FORWARDS )
        {
          int maxkmh = 0;
          const char* blockV_hint = getBlockV_hint(inst, data->next1Block, False, NULL, !data->next1RouteFromTo, &maxkmh );
          if( data->loc->compareVhint( data->loc, blockV_hint) == -1 ) {
            wLoc.setV_hint( cmd, blockV_hint );
            wLoc.setV_maxkmh(cmd, maxkmh);
          }
        }
      }
      else
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 4101,
                     "destBlock for \"%s\" is not set!",
                     data->loc->getId( data->loc ) );

      wLoc.setdir( cmd, wLoc.isdir( data->loc->base.properties( data->loc ) ) );

      {
        Boolean bbt = wLoc.isusebbt(data->loc->base.properties( data->loc )) && data->next1Block->allowBBT(data->next1Block);
        if( !data->gomanual && !re_enter && !bbt ) {
          data->loc->cmd( data->loc, cmd );
        }
        else {
          /* delete un sended node */
          NodeOp.base.del(cmd);
        }
      }
    }

  }


  /* SECOND NEXT BLOCK */
  else if( data->secondnextblock || data->loc->trySecondNextBlock(data->loc) ) {
    /* try to reserve next3Block if the train does not have to wait in the next next2Block */
    reserveSecondNextBlock( (iOLcDriver)inst, data->gotoBlock, data->next2Block, data->next2Route,
                              &data->next3Block, &data->next3Route, !data->next2RouteFromTo, data->next1Route->isSwapPost( data->next1Route ) );

    if( data->next3Route != NULL ) {
      data->next3Route->getDirection( data->next3Route,
          data->next2Block->base.id(data->next2Block), &data->next3RouteFromTo );
    }
    /* if a second next block was found show the right signal aspect */
  }

  if( !re_enter || data->next2Block != NULL )
    setSignals((iOLcDriver)inst, True);

  if( re_enter && data->next2Block != NULL ) {
    iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    int maxkmh = 0;
    wLoc.setV_hint( cmd, getBlockV_hint(inst, data->next1Block, False, data->next1Route, !data->next1RouteFromTo, &maxkmh ) );
    wLoc.setV_maxkmh(cmd, maxkmh);
    data->loc->cmd( data->loc, cmd );
  }

  /* Previous place of the loco block enterside setting...  */

}
