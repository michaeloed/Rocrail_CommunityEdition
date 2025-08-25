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



#include "rocrail/public/model.h"

#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/Route.h"
#include "rocrail/wrapper/public/Schedule.h"
#include "rocrail/wrapper/public/ScheduleEntry.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/FunCmd.h"
#include "rocrail/wrapper/public/Link.h"



void unlockBlockGroup( iOLcDriver inst, const char* group) {
  iOLcDriverData data = Data(inst);
  data->model->unlockBlockGroup(data->model, group, data->loc->getId( data->loc ));
}



/**
 * Try to reserve a SECOND NEXT BLOCK if the train does not have to wait in the next block.
 *
 * @param inst      LcDriver instance
 * @param gotoBlock goto block ID
 */
void reserveSecondNextBlock( iOLcDriver inst, const char* gotoBlock, iIBlockBase fromBlock,
    iORoute fromRoute, iIBlockBase* toBlock, iORoute* toRoute, Boolean reverse, Boolean swapNext1Route ) {
  iOLcDriverData data = Data(inst);

  iORoute     nextRoute = NULL;
  iIBlockBase nextBlock = NULL;
  Boolean     fromto    = False;
  int         indelay   = 0;
  Boolean     oppwait   = True;

  /*Boolean direction = fromRoute->getDirection( fromRoute, fromBlock->getId(fromBlock), &fromto );*/
  /* TODO: use the right direction for finding the next block in the same direction */

  if( !fromBlock->wait( fromBlock, data->loc, reverse, &oppwait ) &&
      !fromBlock->isTerminalStation(fromBlock)  && data->run && !data->reqstop )
  {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4204,
                   "finding a second next block for [%s]", data->loc->getId( data->loc ) );

    if( data->schedule == NULL || StrOp.len( data->schedule ) == 0 ) {
      nextRoute = NULL;
      nextBlock = data->model->findDest( data->model, fromBlock->base.id(fromBlock), fromRoute->base.id(fromRoute),
                                         data->loc, &nextRoute, gotoBlock,
                                         fromRoute->isSwapPost( fromRoute ) ^ swapNext1Route, False, False, True );
    }
    else {
      /* find destination using schedule */
      int scheduleIdx = data->scheduleIdx;

      /* TODO: force same direction */
      nextRoute = data->model->calcRouteFromCurBlock( data->model,
          (iOList)NULL, data->schedule, &scheduleIdx,
          fromBlock->base.id(fromBlock), fromRoute->base.id(fromRoute), data->loc, fromRoute->isSwapPost( fromRoute ), &indelay, True );

      if( nextRoute != NULL ) {
        /* evaluate direction */
        if( StrOp.equals( nextRoute->getToBlock( nextRoute ), fromBlock->base.id(fromBlock) ) )
          nextBlock = data->model->getBlock( data->model, nextRoute->getFromBlock( nextRoute ) );
        else
          nextBlock = data->model->getBlock( data->model, nextRoute->getToBlock( nextRoute ) );
      }
    }

    if( nextBlock != NULL && nextRoute != NULL ) {
      if( data->curBlock == nextBlock || data->next1Block == nextBlock || data->next2Block == nextBlock || data->next3Block == nextBlock ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4204,
                       "ignoring second next block [%s] for [%s] because it is already reserved",
                       nextBlock->base.id(nextBlock), data->loc->getId( data->loc ) );
        nextBlock = NULL;
        *toBlock = NULL;
        *toRoute = NULL;
      }
    }

    if( nextBlock != NULL && nextRoute != NULL ) {
      Boolean fromto = True;
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4204,
                   "second next block/route for [%s] is [%s]/[%s]",
                   data->loc->getId( data->loc ),
                   nextBlock->base.id(nextBlock), nextRoute->getId(nextRoute) );

      nextRoute->getDirection( nextRoute, fromBlock->base.id(fromBlock), &fromto );
      /* lock second next destination */
      if( initializeGroup( inst, nextBlock, NULL ) &&
          nextBlock->lock( nextBlock, data->loc->getId( data->loc ), fromBlock->base.id(fromBlock), nextRoute->base.id(nextRoute), False, True, !fromto, indelay, NULL, False ) )
      {
        if( nextRoute->lock( nextRoute, data->loc->getId( data->loc ), !fromto, True ) ) {
          *toBlock = nextBlock;
          *toRoute = nextRoute;
          /* TODO: test if this will not hold other actions... */
          /* TODO: check if the destination is the same before fire a go command for the street */
          nextRoute->go(nextRoute);
        }
        else {
          nextBlock->unLock( nextBlock, data->loc->getId( data->loc ), NULL );
          *toBlock = NULL;
          *toRoute = NULL;
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4204,
                       "could not lock [%s]/[%s] for [%s]",
                       nextBlock->base.id(nextBlock), nextRoute->getId(nextRoute),
                       data->loc->getId( data->loc ) );
        }
      }

    }

  }
  else {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4204,
                 "second next block: wait in next block for [%s]", data->loc->getId( data->loc ) );
  }

}



void listBlocks(iOLcDriver inst) {
  iOLcDriverData data = Data(inst);

  if( data->curBlock != NULL )
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4204, "curBlock         [%s]", data->curBlock->base.id(data->curBlock) );
  if( data->useCurBlock4Signals && data->curBlock4Signals != NULL )
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4204, "curBlock4Signals [%s]", data->curBlock4Signals->base.id(data->curBlock4Signals) );
  if( data->gotoBlock != NULL )
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4204, "gotoBlock        [%s]", data->gotoBlock );
  if( data->next1Block != NULL )
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4204, "next1Block       [%s]", data->next1Block->base.id(data->next1Block) );
  if( data->next2Block != NULL )
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4204, "next2Block       [%s]", data->next2Block->base.id(data->next2Block) );
  if( data->next3Block != NULL )
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4204, "next3Block       [%s]", data->next3Block->base.id(data->next3Block) );

}


void resetNext2( iOLcDriver inst, Boolean unLock ) {
  iOLcDriverData data = Data(inst);

  listBlocks(inst);

  if( data->next2Block != NULL && data->next1Block == data->next2Block ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4204,
        "setting next2Block [%s] to NULL",
        data->next2Block->base.id(data->next2Block) );
    data->next2Block = NULL;
    data->next2Route = NULL;
  }
  if( data->next3Block != NULL && data->next1Block == data->next3Block ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4204,
        "setting next3Block [%s] to NULL",
        data->next3Block->base.id(data->next3Block) );
    data->next3Block = NULL;
    data->next3Route = NULL;
  }



  if( data->next2Block != NULL ) {

    if( unLock ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4204, "reset next2Block [%s]", data->next2Block->base.id(data->next2Block) );
      if(data->curBlock != data->next2Block && data->next1Block != data->next2Block )
        data->next2Block->unLock(data->next2Block, data->loc->getId(data->loc), NULL);
    }
    data->next2Block = NULL;
    if( unLock ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4204, "reset next2Route [%s]", data->next2Route->getId(data->next2Route) );
      if( data->next2Route != NULL && data->next2Route != data->next1Route )
        data->next2Route->unLock(data->next2Route, data->loc->getId(data->loc), NULL, True, False);
      }
    data->next2Route = NULL;
  }

  /* most likely next3Block should be reseted too */
  if( data->next3Block != NULL ) {

    if( unLock ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4204, "reset next3Block [%s]", data->next3Block->base.id(data->next3Block) );
      if( data->curBlock != data->next3Block && data->next1Block != data->next3Block )
        data->next3Block->unLock(data->next3Block, data->loc->getId(data->loc), NULL);
    }
    data->next3Block = NULL;
    if( unLock ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4204, "reset next3Route [%s]", data->next3Route->getId(data->next3Route) );
      if( data->next3Route != NULL && data->next3Route != data->next1Route )
        data->next3Route->unLock(data->next3Route, data->loc->getId(data->loc), NULL, True, False);
    }
    data->next3Route = NULL;
  }

}

