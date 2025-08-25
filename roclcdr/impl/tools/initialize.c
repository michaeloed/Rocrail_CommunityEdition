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


/**
 * Initialize routes and block groups for the next block.
 *
 * @param inst       LcDiver instance
 * @param block      destination block
 * @param curBlock   current block
 */
Boolean initializeDestination( iOLcDriver inst, iIBlockBase block, iORoute street, iIBlockBase curBlock, Boolean reverse, int indelay ) {
  iOLcDriverData data = Data(inst);
  Boolean grouplocked = initializeGroup(inst, block, curBlock);

  if( !grouplocked ) {
    return False;
  }

  if( street->isFree(street, data->loc->getId( data->loc )) ) {
    /* TODO: curBlock can be NULL in case of R2Rnet */
    if( block->lock( block, data->loc->getId( data->loc ),
        curBlock->base.id( curBlock ), street->base.id(street), False, True, reverse, indelay, NULL, False ) )
    {
      if( street->lock( street, data->loc->getId( data->loc ), reverse, True ) ) {
        if( street->go( street ) ) {

          if( data->gotoBlock != NULL && StrOp.equals( data->gotoBlock, block->base.id( block ) ) ) {
            TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 4205,
                           "GotoBlock %s found for \"%s\"",
                           data->gotoBlock, data->loc->getId( data->loc ) );

            data->gotoBlock = data->loc->getNextGotoBlock( data->loc, data->gotoBlock );
            if( data->gotoBlock == NULL) {
              /* stop after reaching the last gotoBlock */
              TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 4205, "stop after reaching the last gotoBlock");
              data->run = False;
            }
          }

          data->slowdown4route = False;

          return True;
        }
        else {
          block->unLock( block, data->loc->getId( data->loc ), NULL );
          street->unLock( street, data->loc->getId( data->loc ), NULL, True, False );
          if(grouplocked) {
            unlockBlockGroup(inst, data->blockgroup);
          }
          TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 4004, "Could not switch street \"%s\", for \"%s\"...",
              street->getId( street ), data->loc->getId( data->loc ) );
        }
      }
      else {
        block->unLock( block, data->loc->getId( data->loc ), NULL );
        if(grouplocked) {
          unlockBlockGroup(inst, data->blockgroup);
        }
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 4104, "Could not lock route \"%s\", for \"%s\"...",
            street->getId( street ), data->loc->getId( data->loc ) );
      }

    }
    else {
      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 4004, "Could not lock block \"%s\", for \"%s\"...",
          block->base.id( block ), data->loc->getId( data->loc ) );
      if(grouplocked) {
        unlockBlockGroup(inst, data->blockgroup);
      }
    }
  }
  else {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 4004, "Could not lock route \"%s\", for \"%s\"...",
        street->base.id( street ), data->loc->getId( data->loc ) );
    if(grouplocked) {
      unlockBlockGroup(inst, data->blockgroup);
    }
  }

  return False;
}


/**
 * Initialize block groups and swapping.
 *
 * @param inst       LcDiver instance
 * @param block      destination block
 */
Boolean initializeGroup( iOLcDriver inst, iIBlockBase block, iIBlockBase curBlock ) {
  iOLcDriverData data = Data(inst);
  Boolean grouplocked = False;

  /* check if this block belongs to a group: */
  const char* group    = NULL;
  const char* curgroup = NULL;

  if( curBlock != NULL)
    curgroup = data->model->checkForBlockGroup( data->model, curBlock->base.id(curBlock) );
  if( curgroup == NULL && data->next1Block != NULL )
    curgroup = data->model->checkForBlockGroup( data->model, data->next1Block->base.id(data->next1Block) );
  if( curgroup == NULL && data->next2Block != NULL )
    curgroup = data->model->checkForBlockGroup( data->model, data->next2Block->base.id(data->next2Block) );

  if( block != NULL ) {
    group = data->model->checkForBlockGroup( data->model, block->base.id(block) );
  }

  /* unlock only for init a next block */
  if( (group != NULL && data->blockgroup != NULL && group != data->blockgroup) ||
      (group == NULL && data->blockgroup != NULL && curgroup != data->blockgroup) ) {
    /* unlock previous group; entering another one */
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 4205, "unlock previous blockgroup %s (curgroup=%s group=%s)",
        data->blockgroup, curgroup!=NULL?curgroup:"-", group!=NULL?group:"-" );
    unlockBlockGroup(inst, data->blockgroup );
    data->blockgroup = NULL;
  }

  /* FollowUp in critical sections will only partly work if the next destination belongs to another group. */
  if( group != NULL ) {
    grouplocked = data->model->lockBlockGroup(data->model, group, block->base.id(block), data->loc->getId( data->loc ) );

    if(!grouplocked) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 4205, "unlock blockgroup %s", group );
      unlockBlockGroup(inst, group);
      return False;
    }
    data->blockgroup = group;
  }

  return True;
}



/**
 * create a block speed hint
 *
 */
const char* getBlockV_hint( iILcDriverInt inst, iIBlockBase block, Boolean onexit, iORoute street, Boolean reverse, int* maxkmh ) {
  iOLcDriverData data = Data(inst);
  int percent = 0;
  Boolean reduceSpeed = False;
  int routeMaxKmh = 0;

  /* the route velocity has a higher priority, so check first: */
  if( street != NULL ) {
    const char* V_hint_route = street->getVelocity( street, &percent, data->loc );
    *maxkmh = street->getMaxKmh(street);
    routeMaxKmh = street->getMaxKmh(street);
    reduceSpeed = street->hasThrownSwitch(street);
    if( !StrOp.equals( V_hint_route, wRoute.V_none ) ) {
      StrOp.copy( data->V_hint, V_hint_route );
      if( StrOp.equals( wBlock.percent, data->V_hint ) ) {
        StrOp.fmtb( data->V_hint, "%d", percent );
      }
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4205, "Route[%s] V_hint [%s]", street->getId(street), data->V_hint );
      return data->V_hint;
    }
  }
  /* OK, no valid route hint: get it from the block: */
  StrOp.copy( data->V_hint, block->getVelocity( block, &percent, onexit, reverse, street==NULL?True:False ) );
  if( StrOp.equals( wBlock.percent, data->V_hint ) ) {
    StrOp.fmtb( data->V_hint, "%d", percent );
  }

  /* check for route maxkmh */
  if(routeMaxKmh == 0)
    *maxkmh = block->getMaxKmh(block);

  /* check for thrown switches in route */
  if( !StrOp.equals( data->V_hint, wLoc.min ) && (reduceSpeed && onexit) ) {
    StrOp.copy( data->V_hint, wLoc.mid );
  }


  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4205, "Block[%s] V_hint [%s] (%s) %s",
      block->base.id(block), data->V_hint, onexit?"on exit":"on enter", reduceSpeed?"(reduced)":"" );
  return data->V_hint;
}



