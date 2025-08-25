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

static Boolean __checkSignalPair(iOLcDriver inst, iORoute route, iIBlockBase block, Boolean fromTo, Boolean *signalpair);


void resetSignals(iOLcDriver inst ) {
  iOLcDriverData data = Data(inst);
  Boolean reverse = False;
  Boolean signalpair = False; /* default false for the forwards signals */
  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "reset signals for [%s]...", data->curBlock->base.id(data->curBlock) );
  __checkSignalPair(inst, data->next1Route, data->curBlock, data->next1RouteFromTo, &signalpair);

  /* signal current block */
  if( data->curBlock != NULL ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202, "reset signals of current block..." );
    data->curBlock->red( data->curBlock, True, signalpair );
    data->curBlock->red( data->curBlock, False, signalpair );
  }
}


void setCrossingblockSignals(iOLcDriver inst, iORoute route, int aspect, Boolean routefromto) {
  iOLcDriverData data = Data(inst);
  /* iterate all crossing blocks */
  const char* bkc = wRoute.getbkc( route->base.properties(route) );
  if( bkc != NULL && StrOp.len( bkc ) > 0 ) {
    iOStrTok tok = StrTokOp.inst( bkc, ',' );

    while( StrTokOp.hasMoreTokens(tok) ) {
      const char* bk = StrTokOp.nextToken( tok );
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202, "crossing block signals for [%s]...", bk );
      iIBlockBase cblock = data->model->getBlock( data->model, bk );
      if( cblock != NULL ) {

        switch( aspect ) {
        case WHITE_ASPECT:
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202, "white aspect for %s", bk );
          cblock->white( cblock, True, routefromto );
          cblock->white( cblock, False, routefromto );
          break;
        case GREEN_ASPECT:
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202, "green aspect for %s", bk );
          cblock->green( cblock, True, routefromto );
          cblock->green( cblock, False, routefromto );
          break;
        case YELLOW_ASPECT:
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202, "yellow aspect for %s", bk );
          cblock->yellow( cblock, True, routefromto );
          cblock->yellow( cblock, False, routefromto );
          break;
        case RED_ASPECT:
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202, "red aspect for %s", bk );
          cblock->red( cblock, True, routefromto );
          cblock->red( cblock, False, routefromto );
          break;
        case DEFAULT_ASPECT:
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202, "red aspect for %s", bk );
          cblock->setDefaultAspect( cblock, routefromto );
          break;
        default:
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202, "unknown aspect: %d", aspect );
          break;
        }
      }
      else
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 4102, "crossing block [%s] does not exist!", bk );

    }
    StrTokOp.base.del(tok);

  }
}

/*
 * The route has signal pair information stored in sga(from) and sgb(to).
 * Zero value is default; Forwards signal pair if running fromto.
 * One value is revert; Revert signal pair if running fromto.
 * Two value is no signal pair
 */
static Boolean __checkSignalPair(iOLcDriver inst, iORoute route, iIBlockBase block, Boolean fromTo, Boolean *signalpair) {
  iOLcDriverData data = Data(inst);
  if( route != NULL && block != NULL ) {
    const char* blockid = block->base.id(block);
    int sgpair = 0;

    *signalpair = route->getBlockSignalSide(route, block->base.id(block));
    if( *signalpair )
      sgpair = wRoute.getsgb(route->base.properties(route));
    else
      sgpair = wRoute.getsga(route->base.properties(route));

    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "check signal pair: route=%s block=%s fromTo=%s signalpair=%s sgpair=%d",
        route->getId(route), blockid, fromTo?"true":"false", *signalpair?"true":"false", sgpair);

    return sgpair == 2 ? False:True;

  }

  *signalpair = !fromTo;

  return True;
}


Boolean setSignals(iOLcDriver inst, Boolean onEnter ) {
  iOLcDriverData data = Data(inst);
  Boolean semaphore = False;
  Boolean reverse = False;
  Boolean signalpair = False; /* default false for the forwards signals */
  iIBlockBase curBlock = data->curBlock;

  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202, "setting signals...(useCurBlock4Signals=%d)", data->useCurBlock4Signals );
  listBlocks(inst);

  if( data->useCurBlock4Signals ) {
    /* fix for free prev block on enter */
    curBlock = data->curBlock4Signals;
    data->useCurBlock4Signals = False;
  }

  /* set signal current block on enter */
  if( onEnter && curBlock != NULL ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202, "setting signals for curBlock[%s] to default aspect", curBlock->base.id(curBlock) );
    if( data->next1Route != NULL ) {
      if( __checkSignalPair(inst, data->next1Route, curBlock, data->next1RouteFromTo, &signalpair) ) {
        data->curBlock->setDefaultAspect( curBlock, signalpair );
        /* crossing blocks ... */
        setCrossingblockSignals( inst, data->next1Route, DEFAULT_ASPECT, !signalpair );
        setCrossingblockSignals( inst, data->next1Route, DEFAULT_ASPECT, signalpair );
      }
    }
    else {
      curBlock->setDefaultAspect( data->curBlock, True );
      curBlock->setDefaultAspect( data->curBlock, False );
    }
  }

  /* set signal current block */
  else if( data->curBlock != NULL && data->next1Block != NULL && data->next2Block != NULL &&
      data->curBlock != data->next1Block && data->next1Block != data->next2Block )
  {
    if( data->next1Route != NULL && data->next1Route->hasThrownSwitch(data->next1Route) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202,
          "setting signals for curBlock to white: thrown switches in route [%s], reverse[%s]",
          data->next1Route->getId(data->next1Route), data->next1RouteFromTo?"false":"true" );
      if( __checkSignalPair(inst, data->next1Route, data->curBlock, data->next1RouteFromTo, &signalpair) ) {
        semaphore |= data->curBlock->white( data->curBlock, True, signalpair );
        semaphore |= data->curBlock->white( data->curBlock, False, signalpair );
      }

      if( data->next1Route != NULL && data->next1Route->isSetCrossingblockSignals(data->next1Route) ) {
        /* Set the crossing block signals */
        setCrossingblockSignals( inst, data->next1Route, WHITE_ASPECT, signalpair );
      }
      if( data->next2Route != NULL && data->next2Route->isSetCrossingblockSignals(data->next2Route) ) {
        /* Set the crossing block signals */
        if( __checkSignalPair(inst, data->next2Route, data->next2Block, data->next2RouteFromTo, &signalpair) )
          setCrossingblockSignals( inst, data->next2Route, WHITE_ASPECT, !data->next2RouteFromTo );
      }
    }
    else {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202,
          "setting signals for curBlock to green, reverse[%s]", data->next1RouteFromTo?"false":"true");
      if( __checkSignalPair(inst, data->next1Route, data->curBlock, data->next1RouteFromTo, &signalpair) ) {
        semaphore |= data->curBlock->green( data->curBlock, True, signalpair );
        semaphore |= data->curBlock->green( data->curBlock, False, signalpair );
      }

      if( data->next1Route != NULL && data->next1Route->isSetCrossingblockSignals(data->next1Route) ) {
        /* Set the crossing block signals */
        setCrossingblockSignals( inst, data->next1Route, GREEN_ASPECT, signalpair );
      }
      if( data->next2Route != NULL && data->next2Route->isSetCrossingblockSignals(data->next2Route) ) {
        /* Set the crossing block signals */
        if( __checkSignalPair(inst, data->next2Route, data->next2Block, data->next2RouteFromTo, &signalpair) )
          setCrossingblockSignals( inst, data->next2Route, GREEN_ASPECT, signalpair );
      }
    }
  }

  /* no second next block available: YELLOW */
  else if( data->curBlock != NULL && data->next1Block != NULL && data->next2Block == NULL &&
      data->curBlock != data->next1Block )
  {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "no second next block available: YELLOW" );
    if( __checkSignalPair(inst, data->next1Route, data->curBlock, data->next1RouteFromTo, &signalpair) ) {

      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202,
          "setting signalpair[%s] for curBlock", signalpair?"forwards":"reverse");

      if( data->next1Route != NULL && data->next1Route->hasThrownSwitch(data->next1Route) ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202,
            "setting signals for curBlock to white: thrown switches in route [%s], reverse[%s]",
            data->next1Route->getId(data->next1Route), data->next1RouteFromTo?"false":"true" );
        semaphore |= data->curBlock->white( data->curBlock, True, signalpair );
        semaphore |= data->curBlock->white( data->curBlock, False, signalpair );
        if( data->next1Route != NULL && data->next1Route->isSetCrossingblockSignals(data->next1Route) ) {
          /* Set the crossing block signals */
          setCrossingblockSignals( inst, data->next1Route, WHITE_ASPECT, signalpair );
        }
      }
      else if( data->greenaspect ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202,
            "setting signals for curBlock to green: Use green aspect instead of yellow if next block has red." );
        semaphore |= data->curBlock->green( data->curBlock, True, signalpair );
        semaphore |= data->curBlock->green( data->curBlock, False, signalpair );
        if( data->next1Route != NULL && data->next1Route->isSetCrossingblockSignals(data->next1Route) ) {
          /* Set the crossing block signals */
          setCrossingblockSignals( inst, data->next1Route, GREEN_ASPECT, signalpair );
        }
      }
      else {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202, "setting signals for curBlock to yellow." );
        semaphore |= data->curBlock->yellow( data->curBlock, True, signalpair );
        semaphore |= data->curBlock->yellow( data->curBlock, False, signalpair );
        if( data->next1Route != NULL && data->next1Route->isSetCrossingblockSignals(data->next1Route) ) {
          /* Set the crossing block signals */
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202, "setting signals for crossing to yellow." );
          setCrossingblockSignals( inst, data->next1Route, YELLOW_ASPECT, signalpair );
        }
        else {
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202, "**not** [%d] setting signals for crossing to yellow.", data->next1Route->isSetCrossingblockSignals(data->next1Route) );
        }
      }
    }
  }

  /* no next block available: RED */
  else if( data->curBlock != NULL )
  {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202,
        "setting signals for curBlock to red, reverse[%s]", data->next1RouteFromTo?"false":"true");
    semaphore |= data->curBlock->red( data->curBlock, True, False );
    semaphore |= data->curBlock->red( data->curBlock, False, False );
    semaphore |= data->curBlock->red( data->curBlock, True, True );
    semaphore |= data->curBlock->red( data->curBlock, False, True );
  }



  /* signal next1Block */
  if( data->next1Block != NULL && data->next2Block != NULL && data->next3Block != NULL &&
      data->next1Block != data->next2Block && data->next2Block != data->next3Block )
  {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "set signals in block [%s]", data->next1Block->base.id(data->next1Block) );

    if( data->next2Route != NULL && data->next2Route->hasThrownSwitch(data->next2Route) ) {
      if( __checkSignalPair(inst, data->next2Route, data->next1Block, data->next2RouteFromTo, &signalpair) ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202,
                   "setting signals for next1Block to white: thrown switches in route [%s]",
                   data->next2Route->getId(data->next2Route) );
        data->next1Block->white( data->next1Block, True, signalpair );
        data->next1Block->white( data->next1Block, False, signalpair );
        if( data->next2Route != NULL && data->next2Route->isSetCrossingblockSignals(data->next2Route) ) {
          /* Set the crossing block signals */
          setCrossingblockSignals( inst, data->next2Route, WHITE_ASPECT, signalpair );
        }
      }
    }
    else {
      if( __checkSignalPair(inst, data->next2Route, data->next1Block, data->next2RouteFromTo, &signalpair) ) {
        data->next1Block->green( data->next1Block, True, signalpair );
        data->next1Block->green( data->next1Block, False, signalpair );
        if( data->next2Route != NULL && data->next2Route->isSetCrossingblockSignals(data->next2Route) ) {
          /* Set the crossing block signals */
          setCrossingblockSignals( inst, data->next2Route, GREEN_ASPECT, signalpair );
        }
      }
    }
  }
  else if( data->next1Block != NULL && data->next2Block != NULL &&
      data->next1Block != data->next2Block )
  {
    Boolean hasThrownSwitches = False;

    if( data->next2Route != NULL && data->next2Route->hasThrownSwitch(data->next2Route) ) {
      hasThrownSwitches = True;
    }

    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "set signals in block [%s]", data->next1Block->base.id(data->next1Block) );
    if( __checkSignalPair(inst, data->next2Route, data->next1Block, data->next2RouteFromTo, &signalpair) ) {
      if( hasThrownSwitches ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202,
                     "setting signals for next1Block to white: thrown switches in route [%s]",
                     data->next2Route->getId(data->next2Route) );
        data->next1Block->white( data->next1Block, True, signalpair );
        data->next1Block->white( data->next1Block, False, signalpair );
      }
      else if( data->greenaspect ) {
        data->next1Block->green( data->next1Block, True, signalpair );
        data->next1Block->green( data->next1Block, False, signalpair );
        if( data->next2Route != NULL && data->next2Route->isSetCrossingblockSignals(data->next2Route) ) {
          /* Set the crossing block signals */
          setCrossingblockSignals( inst, data->next2Route, hasThrownSwitches?WHITE_ASPECT:GREEN_ASPECT, signalpair );
        }
      }
      else {
        data->next1Block->yellow( data->next1Block, True, signalpair );
        data->next1Block->yellow( data->next1Block, False, signalpair );
        if( data->next2Route != NULL && data->next2Route->isSetCrossingblockSignals(data->next2Route) ) {
          /* Set the crossing block signals */
          setCrossingblockSignals( inst, data->next2Route, YELLOW_ASPECT, signalpair );
        }
      }
    }
  }
  else if( data->next1Block != NULL )
  {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "set signals in block [%s]", data->next1Block->base.id(data->next1Block) );
    if( __checkSignalPair(inst, data->next1Route, data->next1Block, data->next1RouteFromTo, &signalpair) ) {
      if( data->model->getStage(data->model, data->next1Block->base.id(data->next1Block) ) == NULL ) {
        /* only set signals to red on non staging (real) blocks */
        data->next1Block->red( data->next1Block, True, signalpair );
        data->next1Block->red( data->next1Block, False, signalpair );
      }
      else {
        /* staging blocks handle setting to red internally */
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202, "setSignals[%s] blBaseName=%s name=%s SKIPPED",
            data->next1Block->base.id(data->next1Block), data->next1Block->base.name(), name );
      }
    }
  }

  /* signal next2Block */
  if( data->next2Block != NULL && data->next3Block != NULL &&
      data->next2Block != data->next3Block )
  {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "set signals in block [%s]", data->next2Block->base.id(data->next2Block) );
    if( __checkSignalPair(inst, data->next3Route, data->next2Block, data->next3RouteFromTo, &signalpair) ) {
      if( data->next3Route->hasThrownSwitch(data->next3Route) ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202,
                     "setting signals for next2Block to white: thrown switches in route [%s]",
                     data->next3Route->getId(data->next3Route) );
        data->next2Block->white( data->next2Block, True, signalpair );
        data->next2Block->white( data->next2Block, False, signalpair );
      }
      else if( data->greenaspect ) {
        data->next2Block->green( data->next2Block, True, signalpair );
        data->next2Block->green( data->next2Block, False, signalpair );
      }
      else {
        data->next2Block->yellow( data->next2Block, True, signalpair );
        data->next2Block->yellow( data->next2Block, False, signalpair );
      }
    }
  }
  else if( data->next2Block != NULL )
  {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "set signals in block [%s]", data->next2Block->base.id(data->next2Block) );
    if( data->model->getStage(data->model, data->next2Block->base.id(data->next2Block) ) == NULL ) {
      /* only set signals to red on non staging (real) blocks */
      if( __checkSignalPair(inst, data->next2Route, data->next2Block, data->next2RouteFromTo, &signalpair) ) {
        data->next2Block->red( data->next2Block, True, signalpair );
        data->next2Block->red( data->next2Block, False, signalpair );
      }
      else {
        /* staging blocks handle setting to red internally */
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 4202, "setSignals[%s] blBaseName=%s name=%s SKIPPED",
            data->next2Block->base.id(data->next2Block), data->next2Block->base.name(), name );
      }
    }
  }

  return semaphore;
}



