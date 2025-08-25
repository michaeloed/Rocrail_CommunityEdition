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
#include "roclcdr/impl/events/events.h"
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


void eventEnter( iOLcDriver inst, const char* blockId, iIBlockBase block, Boolean curBlockEvent, Boolean dstBlockEvent ) {
  iOLcDriverData data = Data(inst);

  Boolean newEnterEvent = False;
  if( data->preventer + data->ignevt < SystemOp.getTick() && StrOp.equals( blockId, data->preventerbkid ) ) {
    data->preventer = SystemOp.getTick();
    data->preventerbkid = blockId;
    newEnterEvent = True;
  }
  else if( !StrOp.equals( blockId, data->preventerbkid ) ) {
    data->preventer = SystemOp.getTick();
    data->preventerbkid = blockId;
    newEnterEvent = True;
  }
  else {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4101,
                   "Ignoring enter_block event from %s; it came within %d ticks!", blockId, data->ignevt );
  }

  /* Train could have contacted both feedbacks. */
  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201,
                 "enter_block event for \"%s\" from \"%s\"...",
                 data->loc->getId( data->loc ), blockId );

  if( newEnterEvent ) {/* check if the exitblock or outblock state are able to get active: */
    Boolean dontcare = False;
    if( data->state == LC_GO || data->state == LC_PRE2GO ) /* || data->state == LC_CHECKROUTE ) */
      dontcare = True;

    if( (dstBlockEvent && data->state == LC_EXITBLOCK) ||
        (dstBlockEvent && data->state == LC_OUTBLOCK) ||
        (dstBlockEvent && dontcare) )
    {
      data->state = LC_ENTERBLOCK;
      data->loc->setMode(data->loc, wLoc.mode_auto, "");
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201,
                     "Setting state for \"%s\" to LC_ENTERBLOCK.",
                     data->loc->getId( data->loc ) );
    }
    else if( dstBlockEvent && data->state != LC_IDLE ) {
      /* Could be dirty wheels or a big gap between wheels. */
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4201,
                     "Unexpected enter_block event for [%s] in [%s] with state [%d]...",
                     data->loc->getId( data->loc ), blockId, data->state );
    }

    /**********************************************/
    /* inserted to free previous block on enter   */
    if (data->state == LC_ENTERBLOCK && wLoc.isfreeblockonenter(data->loc->base.properties(data->loc)) &&
        data->next1Block->isFreeBlockOnEnter(data->next1Block) )
    {
      data->useCurBlock4Signals = True;
      data->curBlock4Signals = data->curBlock;
      if( !data->didFree ) {
        TraceOp.trc(name, TRCLEVEL_USER1, __LINE__, 4201,
            "Free previous block on enter for [%s] in [%s] with state [%d]", data->loc->getId(data->loc), blockId, data->state);

        freePrevBlock(inst, block);
      }
      else {
        /* Reset trigger */
        data->didFree = False;
      }
    }
    else {
      data->useCurBlock4Signals = False;
    }

    /* end insert to free previous block          */
    /**********************************************/
  }
  else {
    /* Exception! */
    /* ToDo: Could also happen when wagon wheels are dirty. */
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 4101,
                   "Unexpected (state=%d) enter_block event for \"%s\" from \"%s\"...",
                   data->state, data->loc->getId( data->loc ), blockId );

    if( curBlockEvent ) {
      /* An unknown loc is comming in!!! (Or train too long??!!)*/
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 4101,
                     "Unexpected enter_block event for \"%s\" from \"%s\"...",
                     data->loc->getId( data->loc ), blockId );
      if( newEnterEvent ) {
        TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 4001,
                       "Stopping because a new enter_block event came after more than a second! loc=\"%s\" block=\"%s\"...",
                       data->loc->getId( data->loc ), blockId );
        data->model->stop( data->model );
      }
      else {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 4101,
                       "Not Stopping because a new enter_block event came within a second! loc=\"%s\" block=\"%s\"...",
                       data->loc->getId( data->loc ), blockId );
      }
    }
  }

}

