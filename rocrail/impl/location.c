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

#include "rocrail/impl/location_impl.h"

#include "rocs/public/mem.h"
#include "rocs/public/strtok.h"

#include "rocrail/public/app.h"
#include "rocrail/public/model.h"
#include "rocint/public/blockbase.h"

#include "rocrail/wrapper/public/Location.h"

static int instCnt = 0;

static void __initArriveList( iOLocation inst );
static void __dumpOcc(iOLocation inst);


/** ----- OBase ----- */
static void __del( void* inst ) {
  if( inst != NULL ) {
    iOLocationData data = Data(inst);
    /* Cleanup data->xxx members...*/
    ListOp.base.del(data->arriveList);
    freeMem( data );
    freeMem( inst );
    instCnt--;
  }
  return;
}

static const char* __name( void ) {
  return name;
}

static unsigned char* __serialize( void* inst, long* size ) {
  return NULL;
}

static void __deserialize( void* inst,unsigned char* bytestream ) {
  return;
}

static char* __toString( void* inst ) {
  return NULL;
}

static int __count( void ) {
  return instCnt;
}

static struct OBase* __clone( void* inst ) {
  return NULL;
}

static Boolean __equals( void* inst1, void* inst2 ) {
  return False;
}

static void* __properties( void* inst ) {
  iOLocationData data = Data(inst);
  return data->props;
}

static const char* __id( void* inst ) {
  iOLocationData data = Data(inst);
  return wLocation.getid(data->props);
}

static void* __event( void* inst, const void* evt ) {
  return NULL;
}

/** ----- OLocation ----- */


/**  */
static struct OLocation* _inst( iONode ini ) {
  iOLocation __Location = allocMem( sizeof( struct OLocation ) );
  iOLocationData data = allocMem( sizeof( struct OLocationData ) );
  MemOp.basecpy( __Location, &LocationOp, 0, sizeof( struct OLocation ), data );

  /* Initialize data->xxx members... */
  data->props  = ini;
  data->minocc = wLocation.getminocc(ini);
  data->fifo   = wLocation.isfifo(ini);
  data->arriveList = ListOp.inst();
  data->locoPending = False;
  data->locoPendingID = NULL;
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
      "location %s: MinOcc=%d Fifo=%d", wLocation.getid(ini), data->minocc, data->fifo );

  data->listmux = MutexOp.inst( NULL, True );

  __initArriveList(__Location);

  instCnt++;
  return __Location;
}


static void __informLocoFiFoTop( iOLocation inst ) {
  iOLocationData data = Data(inst);
  if( data->fifo && ListOp.size(data->arriveList) > 0 ) {
    /* Inform the loco. */
    const char* locoid = (const char*)ListOp.get( data->arriveList, 0);
    if( locoid != NULL ) {
      iOLoc lc = ModelOp.getLoc( AppOp.getModel(), locoid, NULL, False);
      if( lc != NULL ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "inform loco %s that its on FiFo top in location %s", locoid, wLocation.getid(data->props) );
        LocOp.fifoTop(lc);
      }
    }
  }
}

static void __initArriveList( iOLocation inst ) {
  iOLocationData data = Data(inst);
  /* iterrate location: */

  if( MutexOp.trywait( data->listmux, 100 ) ) {
    iOStrTok blocks = StrTokOp.inst( wLocation.getblocks( data->props ), ',' );

    while( StrTokOp.hasMoreTokens( blocks ) ) {
      const char* locationBlock = StrTokOp.nextToken( blocks );
      iIBlockBase block = ModelOp.getBlock( AppOp.getModel(), locationBlock );
      if( block != NULL && block->getLoc(block) != NULL && StrOp.len(block->getLoc(block)) > 0 ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "cold start; add [%s] to the arrived list", block->getLoc(block) );
        ListOp.add( data->arriveList, (obj)StrOp.dup(block->getLoc(block)) );
      }
    }
    StrTokOp.base.del( blocks );
    MutexOp.post( data->listmux );
  }
  __dumpOcc(inst);
  __informLocoFiFoTop(inst);
}


static void __dumpOcc(iOLocation inst) {
  iOLocationData data = Data(inst);
  int i = 0;
  int size = ListOp.size(data->arriveList);
  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "----- dump occ list [%s] -----", wLocation.getid( data->props ) );
  for( i = 0; i < size; i++ ) {
    const char* arrLoco = (const char*)ListOp.get( data->arriveList, i );
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "loco %s is nr %d in the list of %d [%s]", arrLoco, i, size, wLocation.getid( data->props ) );
  }
}

/**  */
static void _didNotDepart( struct OLocation* inst ,const char* LocoId ) {
  iOLocationData data = (inst == NULL ? NULL:Data(inst));

  if( inst == NULL || LocoId == NULL ) {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "NULL parameter" );
    return;
  }

  if( !MutexOp.trywait( data->listmux, 100 ) ) {
    return;
  }

  if( !data->fifo && data->locoPending ) {
    if( StrOp.equals( data->locoPendingID, LocoId ) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "loco %s did not depart from location [%s]", LocoId, wLocation.getid( data->props ) );
      data->locoPending = False;
      data->locoPendingID = NULL;
    }
  }

  MutexOp.post( data->listmux );

}


static Boolean _isDepartureAllowed( struct OLocation* inst ,const char* LocoId ) {
  iOLocationData data = (inst == NULL ? NULL:Data(inst));
  int i = 0;
  if( inst == NULL || LocoId == NULL ) {
    TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "NULL parameter" );
    return False;
  }
  if( !MutexOp.trywait( data->listmux, 100 ) ) {
    return False;
  }
  if( data->minocc > 0 ) {
    int size = ListOp.size(data->arriveList);
    for( i = 0; i < size; i++ ) {
      const char* arrLoco = (const char*)ListOp.get( data->arriveList, i );
      if( arrLoco != NULL ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
            "loco %s is nr %d in the list of %d from location %s", arrLoco, i, size, wLocation.getid( data->props ) );
        if( StrOp.equals( LocoId, arrLoco ) ) {
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
              "loco %s is nr %d in the list of %d from location %s", LocoId, i, size, wLocation.getid( data->props ) );

          if( ListOp.size(data->arriveList) >= data->minocc ) {
            if( data->fifo && i == 0 ) {
              TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                  "loco %s is first in the list for FiFo, departure is allowed from location [%s]", LocoId, wLocation.getid( data->props ) );
              __dumpOcc(inst);
              data->locoPending = True;
              data->locoPendingID = LocoId;
              MutexOp.post( data->listmux );
              return True;
            }
            else if( data->fifo && i > 0 ) {
              TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                  "loco %s is not first in the list for FiFo in location [%s]", LocoId, wLocation.getid( data->props ) );
              __dumpOcc(inst);
              MutexOp.post( data->listmux );
              return False;
            }
            else if(data->locoPending && !StrOp.equals(data->locoPendingID, LocoId) ) {
              TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                  "loco [%s] is pending to depart from location [%s]", data->locoPendingID==NULL?"?":data->locoPendingID, wLocation.getid( data->props ) );
              __dumpOcc(inst);
              MutexOp.post( data->listmux );
              return False;
            }
            else {
              TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "loco %s may depart from location [%s]", LocoId, wLocation.getid( data->props ) );
              __dumpOcc(inst);
              data->locoPending = True;
              data->locoPendingID = LocoId;
              MutexOp.post( data->listmux );
              return True;
            }
          }
          else {
            TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
                "loco %s must wait: MinOcc=%d Occ=%d Location=%s", LocoId, data->minocc, ListOp.size(data->arriveList), wLocation.getid( data->props ) );
            __dumpOcc(inst);
            MutexOp.post( data->listmux );
            return False;
          }
        }
      }
    }

    MutexOp.post( data->listmux );
    return False;

  }
  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "location [%s] has no flow management [%d,%d]",
      wLocation.getid(data->props), data->minocc, data->fifo );
  MutexOp.post( data->listmux );
  return True;
}


/**  */
static void _locoDidArrive( struct OLocation* inst ,const char* LocoId ) {
  iOLocationData data = Data(inst);
  if( LocoId != NULL && StrOp.len(LocoId) > 0 ) {
    int i = 0;
    if( MutexOp.trywait( data->listmux, 100 ) ) {
      for( i = 0; i < ListOp.size(data->arriveList); i++ ) {
        if( StrOp.equals( LocoId, (const char*)ListOp.get( data->arriveList, i ) ) ) {
          /* already in the list */
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "arriving loco %s is already in the list", LocoId );
          MutexOp.post( data->listmux );
          return;
        }
      }
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "arriving loco %s is added in the list[%d]", LocoId, ListOp.size( data->arriveList) );
      ListOp.add( data->arriveList, (obj)StrOp.dup(LocoId));
      MutexOp.post( data->listmux );
    }
  }
}


/**  */
static void _locoDidDepart( struct OLocation* inst ,const char* LocoId ) {
  iOLocationData data = Data(inst);
  int i = 0;
  if( MutexOp.trywait( data->listmux, 100 ) ) {
    for( i = 0; i < ListOp.size(data->arriveList); i++ ) {
      if( StrOp.equals( LocoId, (const char*)ListOp.get( data->arriveList, i ) ) ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "departing loco %s is removed from the list", LocoId );
        char* locoid = (char*)ListOp.remove( data->arriveList, i);
        if( locoid != NULL )
          StrOp.free(locoid);
        data->locoPending = False;
        data->locoPendingID = NULL;
        break;
      }
    }
    MutexOp.post( data->listmux );
  }

  __informLocoFiFoTop(inst);
}


static Boolean _cmd( struct OLocation* inst ,iONode node ) {
  iOLocationData data = Data(inst);
  const char* nodename = NodeOp.getName( node );
  const char* cmd      = wLocation.getcmd( node );

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "command %s:%s for location %s",
      nodename, (cmd==NULL?"-":cmd), wLocation.getid( data->props ) );

  /* location command */
  if( StrOp.equals(wLocation.name(), nodename ) ) {
    if( StrOp.equals(wLocation.cmd_minocc, cmd ) ) {
      int minocc = wLocation.getvalue(node);
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "set location [%s] minocc to [%d]", wLocation.getid( data->props ), minocc);
      wLocation.setminocc(data->props, minocc);
      data->minocc = minocc;
      /* Broadcast to clients. */
      {
        iONode clone = (iONode)NodeOp.base.clone( data->props );
        AppOp.broadcastEvent( clone );
      }
    }
    else if( StrOp.equals(wLocation.cmd_fifo, cmd ) ) {
      Boolean fifo = wLocation.getvalue(node) > 0 ? True:False;
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "set location [%s] fifo to [%d]", wLocation.getid( data->props ), fifo);
      wLocation.setfifo(data->props, fifo);
      data->fifo = wLocation.isfifo(data->props);
      /* Broadcast to clients. */
      {
        iONode clone = (iONode)NodeOp.base.clone( data->props );
        AppOp.broadcastEvent( clone );
      }
    }
  }

  return True;
}


/**  */
static void _modify( struct OLocation* inst ,iONode mod ) {
  iOLocationData data = Data(inst);
  data->minocc = wLocation.getminocc(mod);
  data->fifo   = wLocation.isfifo(mod);
  NodeOp.mergeNode( data->props, mod, True, True, False );
  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
      "modify location %s, minocc=%d fifo=%d", wLocation.getid(data->props), data->minocc, data->fifo );
}


/**  */
static void _reset( struct OLocation* inst ) {
  iOLocationData data = Data(inst);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "reset location %d", wLocation.getid(data->props));
  ListOp.clear(data->arriveList);
  __initArriveList(inst);
  return;
}



static Boolean _hasBlock( iOLocation inst, const char* blockid ) {
  iOLocationData data = Data(inst);
  /* iterrate location: */
  iOStrTok blocks = StrTokOp.inst( wLocation.getblocks( data->props ), ',' );
  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
      "check if block [%s] is in location [%s](%s)", blockid, wLocation.getid(data->props), wLocation.getblocks( data->props ));
  while( StrTokOp.hasMoreTokens( blocks ) ) {
    const char* locationBlock = StrTokOp.nextToken( blocks );
    if( StrOp.equals( blockid, locationBlock ) ) {
      StrTokOp.base.del( blocks );
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "block [%s] is in location [%s]", blockid, wLocation.getid(data->props));
      return True;
    }
  }
  StrTokOp.base.del( blocks );
  return False;
}



static Boolean _hasFreeBlock( iOLocation inst, const char* locoId ) {
  iOLocationData data = Data(inst);
  /* iterrate location: */
  iOStrTok blocks = StrTokOp.inst( wLocation.getblocks( data->props ), ',' );

  while( StrTokOp.hasMoreTokens( blocks ) ) {
    const char* locationBlock = StrTokOp.nextToken( blocks );
    iIBlockBase block = ModelOp.getBlock( AppOp.getModel(), locationBlock );

    if( block != NULL && block->isFree(block, locoId) ) {
      iOLoc loc = ModelOp.getLoc( AppOp.getModel(), locoId, NULL, False );
      if( loc != NULL && block->isSuited(block, loc, NULL, True ) != suits_not ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "location[%s] has a free block[%s]", wLocation.getid(data->props), block->base.id(block));
        StrTokOp.base.del( blocks );
        return True;
      }
    }
  }
  StrTokOp.base.del( blocks );
  return False;
}




/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocrail/impl/location.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
