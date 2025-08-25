/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 


 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include "rocrail/impl/car_impl.h"

#include "rocrail/public/app.h"
#include "rocrail/public/model.h"
#include "rocrail/public/operator.h"

#include "rocs/public/mem.h"

#include "rocrail/wrapper/public/Car.h"
#include "rocrail/wrapper/public/FunCmd.h"
#include "rocrail/wrapper/public/FunDef.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/CVByte.h"
#include "rocrail/wrapper/public/ModelCmd.h"

static int instCnt = 0;

/** ----- OBase ----- */
static void __del( void* inst ) {
  if( inst != NULL ) {
    iOCarData data = Data(inst);
    /* Cleanup data->xxx members...*/

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
  iOCarData data = Data((iOCar)inst);
  return data->props;
}

static const char* __id( void* inst ) {
  iOCarData data = Data((iOCar)inst);
  return wCar.getid(data->props);
}

static void* __event( void* inst, const void* evt ) {
  return NULL;
}

/** ----- OCar ----- */


/**  */
static char* _getForm( void* object ) {
  return 0;
}


/**  */
static char* _postForm( void* object ,const char* data ) {
  return 0;
}


/**  */
static const char* _tableHdr( void ) {
  return 0;
}


/**  */
static char* _toHtml( void* object ) {
  return 0;
}


/**  */
static void __initCVmap( iOCar car ) {
  iOCarData data = Data(car);
  iONode cv = NodeOp.findNode( data->props, wCVByte.name() );
  while( cv != NULL ) {
    char* key = StrOp.fmt( "%d", wCVByte.getnr( cv ) );
    MapOp.put( data->cvMap, key, (obj)cv );
    StrOp.free( key );
    cv = NodeOp.findNextNode( data->props, cv );
  };
}




static struct OCar* _inst( iONode ini ) {
  iOCar __Car = allocMem( sizeof( struct OCar ) );
  iOCarData data = allocMem( sizeof( struct OCarData ) );
  MemOp.basecpy( __Car, &CarOp, 0, sizeof( struct OCar ), data );

  /* Initialize data->xxx members... */
  data->props = ini;
  data->cvMap = MapOp.inst();

  if( StrOp.equals("freight", wCar.gettype(data->props)) ) {
    /* type value changed from freight to goods */
    wCar.settype(data->props, wCar.cartype_freight);
  }

  __initCVmap(__Car);

  instCnt++;
  return __Car;
}

static int __getFnAddr( iOCar inst, int function, int* mappedfn) {
  iOCarData    data = Data(inst);

  iONode fundef = wCar.getfundef( data->props );

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "looking up function %d...", function );


  while( fundef != NULL ) {
    if( wFunDef.getfn(fundef) == function ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
          "function address for %d = %d:%d", function, wFunDef.getaddr(fundef), wFunDef.getmappedfn(fundef) );
      if( mappedfn != NULL ) {
        if( wFunDef.getmappedfn(fundef) > 0 ) {
          *mappedfn = wFunDef.getmappedfn(fundef);
          TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "mapped function is %d", *mappedfn );
        }
        else
          *mappedfn = function;
      }

      return wFunDef.getaddr(fundef);
    }
    fundef = wCar.nextfundef( data->props, fundef );
  };
  if( mappedfn != NULL ) {
    *mappedfn = function;
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "function %d not defined", *mappedfn );
  }
  return 0;
}


static void __copyFx2Node( iOCar inst, iONode nodeA ) {
  iOCarData data = Data(inst);
  char fattr[32] = {'\0'};
  int i = 0;

  for( i = 1; i <= 28; i++ ) {
    StrOp.fmtb(fattr, "f%d", i);
    NodeOp.setBool(nodeA, fattr, data->fx[i]);
  }

}


static void __traceFunctions(iOCar inst, int fnchanged) {
  iOCarData data = Data(inst);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "car=%s [addr=%d] [fn=%d] lights=%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
      wCar.getid( data->props ), wCar.getaddr( data->props ), fnchanged,
      data->fx[0]  ? "on":"off",
      data->fx[1]  ? "01":"--", data->fx[2]  ? "02":"--", data->fx[3]  ? "03":"--", data->fx[4]  ? "04":"--",
      data->fx[5]  ? "05":"--", data->fx[6]  ? "06":"--", data->fx[7]  ? "07":"--", data->fx[8]  ? "08":"--",
      data->fx[9]  ? "09":"--", data->fx[10] ? "10":"--", data->fx[11] ? "11":"--", data->fx[12] ? "12":"--",
      data->fx[13] ? "13":"--", data->fx[14] ? "14":"--", data->fx[15] ? "15":"--", data->fx[16] ? "16":"--",
      data->fx[17] ? "17":"--", data->fx[18] ? "18":"--", data->fx[19] ? "19":"--", data->fx[20] ? "20":"--",
      data->fx[21] ? "21":"--", data->fx[22] ? "22":"--", data->fx[23] ? "23":"--", data->fx[24] ? "24":"--",
      data->fx[25] ? "25":"--", data->fx[26] ? "26":"--", data->fx[27] ? "27":"--", data->fx[28] ? "28":"--"
  );
}

static iONode _getFunctionStatus( iOCar car, iONode cmd ) {
  iOCarData data = Data(car);
  /* save the function status: */
  __copyFx2Node(car, cmd);

  return cmd;
}

static Boolean _cmd( iOCar inst, iONode nodeA ) {
  iOCarData data = Data(inst);
  iOControl control = AppOp.getControl();

  const char* nodename = NodeOp.getName( nodeA );
  const char* cmd      = wCar.getcmd( nodeA );

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "command %s:%s for car %s",
      nodename, (cmd==NULL?"-":cmd), wCar.getid( data->props ) );

  /* car command */
  if( StrOp.equals(wCar.name(), nodename ) ) {
    if( StrOp.equals(wCar.status_empty, cmd ) || StrOp.equals(wCar.status_loaded, cmd ) || StrOp.equals(wCar.status_maintenance, cmd ) ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "set car [%s] status to [%s]", wCar.getid( data->props ), cmd);
      wCar.setstatus(data->props, cmd);
      /* Broadcast to clients. */
      {
        iONode clone = (iONode)NodeOp.base.clone( data->props );
        AppOp.broadcastEvent( clone );
      }
    }
  }

  /* loco or function command in case the address > 0 */
  else if( wCar.getaddr(data->props) > 0 ) {
    if( StrOp.equals(wLoc.name(), nodename ) ) {
      Boolean dir = wCar.isinvdir(data->props) ? !wLoc.isdir(nodeA):wLoc.isdir(nodeA);
      Boolean lights = wLoc.isfn(nodeA);
      Boolean broadcast = False;

      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
          "car %s (%d) V=%d usedir=%d uselights=%d", wCar.getid(data->props), wCar.getaddr(data->props),
          wLoc.getV(nodeA),  wCar.isusedir(data->props), wCar.isuselights(data->props) );

      if( wCar.isusedir(data->props) ) {
        wCar.setid( nodeA, wCar.getid(data->props) );
        wLoc.setdir( nodeA, wCar.isplacing(data->props)?dir:!dir );
        if( wCar.getiid(data->props) != NULL )
          wCar.setiid( nodeA, wCar.getiid(data->props) );
        wCar.setaddr( nodeA, wCar.getaddr(data->props) );
        wCar.setprot( nodeA, wCar.getprot( data->props ) );
        wCar.setprotver( nodeA, wCar.getprotver( data->props ) );
        wLoc.setspcnt( nodeA, wLoc.getspcnt(data->props) );
        ControlOp.cmd( control, (iONode)NodeOp.base.clone(nodeA), NULL );
        broadcast = True;
      }

      if( wCar.isuselights(data->props) ) {
        char fattr[32] = {'\0'};
        StrOp.fmtb(fattr, "f%d", wCar.getfnlights(data->props));
        NodeOp.setName(nodeA, wFunCmd.name());

        /* use mapped function */
        wFunCmd.setfnchanged(nodeA, wCar.getfnlights(data->props));
        NodeOp.setBool(nodeA, fattr, lights);
        data->fx[0] = lights;
        __copyFx2Node(inst, nodeA);
        __traceFunctions(inst, wFunCmd.getfnchanged(nodeA) );

        wFunCmd.setf0(nodeA, lights); /**/
        wLoc.setdir( nodeA, wCar.isplacing(data->props)?dir:!dir );
        wCar.setid( nodeA, wCar.getid(data->props) );
        if( wCar.getiid(data->props) != NULL )
          wCar.setiid( nodeA, wCar.getiid(data->props) );
        wCar.setaddr( nodeA, wCar.getaddr(data->props) );
        wCar.setprot( nodeA, wCar.getprot( data->props ) );
        wCar.setprotver( nodeA, wCar.getprotver( data->props ) );
        wLoc.setspcnt( nodeA, wLoc.getspcnt(data->props) );
        ControlOp.cmd( control, (iONode)NodeOp.base.clone(nodeA), NULL );
        broadcast = True;
      }

      /* Broadcast to clients. */
      if( broadcast ) {
        iONode clone = (iONode)NodeOp.base.clone( nodeA );
        AppOp.broadcastEvent( clone );
      }

    }
    else if( StrOp.equals(wFunCmd.name(), nodename) ) {
      int mappedfn  = 0;
      int i         = 0;
      int fnchanged = wFunCmd.getfnchanged(nodeA);
      int fngrp     = wFunCmd.getgroup(nodeA);
      char fattr[32] = {'\0'};
      int decaddr   = __getFnAddr(inst, wFunCmd.getfnchanged(nodeA), &mappedfn );
      StrOp.fmtb(fattr, "f%d", fnchanged);
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
          "car %s (%d) function group=%d %d:%s address=%d:%d", wCar.getid(data->props), wCar.getaddr(data->props), fngrp, fnchanged,
          NodeOp.getBool(nodeA, fattr, False)?"ON":"OFF", decaddr, mappedfn );

      if( wCar.getiid(data->props) != NULL )
        wCar.setiid( nodeA, wCar.getiid(data->props) );
      wCar.setid( nodeA, wCar.getid(data->props) );
      wCar.setaddr( nodeA, wCar.getaddr(data->props) );
      wCar.setprot( nodeA, wCar.getprot( data->props ) );
      wCar.setprotver( nodeA, wCar.getprotver( data->props ) );
      wLoc.setspcnt( nodeA, wLoc.getspcnt(data->props) );

      if(fnchanged != -1) {
        if(mappedfn != fnchanged) {
          Boolean fon = False;
          fon = NodeOp.getBool(nodeA, fattr, False);
          NodeOp.setBool(nodeA, fattr, False);
          StrOp.fmtb(fattr, "f%d", mappedfn);
          NodeOp.setBool(nodeA, fattr, fon);
          wFunCmd.setfnchanged( nodeA, mappedfn );
          data->fx[mappedfn] = fon;
        }
        else {
          data->fx[fnchanged] = NodeOp.getBool(nodeA, fattr, False);
        }
      }
      else if( fngrp >= 0 ) {
        int i = 0;
        int from = 0;
        int to = 0;
        if( fngrp == 0 ) {
          from = 1; to = 28;
        }
        else if( fngrp == 1 ) {
          from = 1; to = 4;
        }
        else if( fngrp == 2 ) {
          from = 5; to = 8;
        }
        else if( fngrp == 3 ) {
          from = 9; to = 12;
        }
        else if( fngrp == 4 ) {
          from = 13; to = 16;
        }
        else if( fngrp == 5 ) {
          from = 17; to = 20;
        }
        else if( fngrp == 6 ) {
          from = 21; to = 24;
        }
        else if( fngrp == 7 ) {
          from = 25; to = 28;
        }
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "copy function range %d-%d", from, to);
        for( i = from; i <= to; i++ ) {
          StrOp.fmtb(fattr, "f%d", i);
          if( data->fx[i] != NodeOp.getBool(nodeA, fattr, data->fx[i]) ) {
            fnchanged = i;
          }
          data->fx[i] = NodeOp.getBool(nodeA, fattr, data->fx[i]);
        }
        if(fnchanged != -1 && fnchanged > 0 && fnchanged < 29 ) {
          wFunCmd.setfnchanged(nodeA, fnchanged);
          wFunCmd.setgroup(nodeA, (fnchanged / 4) + 1);
        }
      }

      if( fnchanged == 0 && wCar.isf0vcmd(data->props) ) {
        NodeOp.setName( nodeA, wLoc.name() );
        wLoc.setfn(nodeA, wFunCmd.isf0(nodeA) );
        data->fx[0] = wFunCmd.isf0(nodeA);
      }
      else {
        wFunCmd.setf0(nodeA, data->fx[0] );
      }

      for( i = 1; i < 29; i++ ) {
        StrOp.fmtb(fattr, "f%d", i);
        NodeOp.setBool(nodeA, fattr, data->fx[i]);
      }

      __traceFunctions(inst, fnchanged);

      /* Broadcast to clients. */
      AppOp.broadcastEvent( (iONode)NodeOp.base.clone( nodeA ) );
      ControlOp.cmd( control, (iONode)NodeOp.base.clone( nodeA ), NULL );
    }
  }

  NodeOp.base.del(nodeA);

  return True;
}


/**  */
static void _addWaybill( struct OCar* inst ,iONode waybill ) {
  iOCarData data = Data(inst);
}

static int _getAddress( iOCar car ) {
  iOCarData data = Data(car);
  return wCar.getaddr( data->props );
}


/**  */
static const char* _getIdent( struct OCar* inst ) {
  iOCarData data = Data(inst);
  return wCar.getident(data->props);
}


static const char* _getLocality( struct OCar* inst ) {
  iOCarData data = Data(inst);
  return wCar.getlocation(data->props);
}


/**  */
static int _getLen( struct OCar* inst ) {
  iOCarData data = Data(inst);
  return wCar.getlen(data->props);
}


static int _getWeight( struct OCar* inst ) {
  iOCarData data = Data(inst);
  if( StrOp.equals( wCar.status_loaded, wCar.getstatus( data->props) ) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "car [%s] loaded weight [%d]", CarOp.base.id(inst), wCar.getweight_loaded(data->props) );
    return wCar.getweight_loaded(data->props);
  }
  else {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "car [%s] empty weight [%d]", CarOp.base.id(inst), wCar.getweight_empty(data->props) );
    return wCar.getweight_empty(data->props);
  }
}


/**  */
static void _setLocality( struct OCar* inst, const char* id ) {
  iOCarData data = Data(inst);

  wCar.setprevlocation3(data->props, wCar.getprevlocation2(data->props) );
  wCar.setprevlocation2(data->props, wCar.getprevlocation1(data->props) );
  wCar.setprevlocation1(data->props, wCar.getlocation(data->props) );
  wCar.setlocation(data->props, id);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "car [%s] arrived in block [%s]", CarOp.base.id(inst), id );
  /* Broadcast to clients. */
  {
    iONode clone = (iONode)NodeOp.base.clone( data->props );
    AppOp.broadcastEvent( clone );
  }
}


static int _getFnNrByDesc( iOCar inst, const char* desc) {
  iOCarData    data = Data(inst);

  iONode fundef = wCar.getfundef( data->props );
  while( fundef != NULL ) {
    if( wFunDef.gettext(fundef) != NULL && StrOp.equals(wFunDef.gettext(fundef), desc) ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "function number for [%s] = %d", desc, wFunDef.getfn(fundef) );
      return wFunDef.getfn(fundef);
    }
    fundef = wCar.nextfundef( data->props, fundef );
  };

  if( StrOp.len(desc) > 0 && isdigit(desc[0]) )
    return atoi(desc);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "car function [%s] not defined", desc );
  return -1;
}


/**  */
static void _modify( struct OCar* inst ,iONode props ) {
  iOCarData data = Data(inst);
  int cnt = NodeOp.getAttrCnt( props );
  int i = 0;
  for( i = 0; i < cnt; i++ ) {
    iOAttr attr = NodeOp.getAttr( props, i );
    const char* name  = AttrOp.getName( attr );
    const char* value = AttrOp.getVal( attr );

    if( StrOp.equals("id", name) && StrOp.equals( value, wCar.getid(data->props) ) )
      continue; /* skip to avoid making invalid pointers */

    NodeOp.setStr( data->props, name, value );
  }

  /* Leave the childs if no new are comming */
  if( NodeOp.getChildCnt( props ) > 0 ) {
    cnt = NodeOp.getChildCnt( data->props );
    while( cnt > 0 ) {
      iONode child = NodeOp.getChild( data->props, 0 );
      iONode removedChild = NodeOp.removeChild( data->props, child );
      if( removedChild != NULL) {
        NodeOp.base.del(removedChild);
      }
      cnt = NodeOp.getChildCnt( data->props );
    }
    cnt = NodeOp.getChildCnt( props );
    for( i = 0; i < cnt; i++ ) {
      iONode child = NodeOp.getChild( props, i );
      NodeOp.addChild( data->props, (iONode)NodeOp.base.clone(child) );
    }
  }


  /* Broadcast to clients. */
  {
    iONode clone = (iONode)NodeOp.base.clone( data->props );
    AppOp.broadcastEvent( clone );
  }
  props->base.del(props);

  /* Inform the operator */
  {
    iOOperator operator = ModelOp.getOperator4Car(AppOp.getModel(), wCar.getid(data->props) );
    if( operator != NULL ) {
      OperatorOp.modify( operator, NULL );
    }
  }
}


static void _swapPlacing( iOCar car, iONode cmd ) {
  iOCarData data = Data(car);
  if( cmd != NULL )
    wCar.setplacing(data->props, wLoc.isplacing(cmd));
  else
    wCar.setplacing(data->props, !wCar.isplacing(data->props));
}



static int _getCV( iOCar car, int nr ) {
  iOCarData data = Data(car);
  int val = -1;
  char* key = StrOp.fmt( "%d", nr );
  iONode cv = (iONode)MapOp.get( data->cvMap, key );
  StrOp.free( key );
  if( cv != NULL )
    val = wCVByte.getvalue( cv );
  return val;
}


static void _setCV( iOCar car, int nr, int value ) {
  iOCarData data = Data(car);
  char* key = StrOp.fmt( "%d", nr );
  iONode cv = (iONode)MapOp.get( data->cvMap, key );

  if( cv != NULL )
    wCVByte.setvalue( cv, value );
  else {
    cv = NodeOp.inst( wCVByte.name(), data->props, ELEMENT_NODE );
    wCVByte.setnr( cv, nr );
    wCVByte.setvalue( cv, value );
    NodeOp.addChild( data->props, cv );
    MapOp.put( data->cvMap, key, (obj)cv );
  }
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "%s: set cv %d to %d", wLoc.getid(data->props), nr, value);

  StrOp.free( key );

  /* Broadcast to clients. */
  {
    iONode clone = (iONode)data->props->base.clone( data->props );
    wCar.setcmd( clone, wModelCmd.modify );
    AppOp.broadcastEvent( clone );
  }
}

static Boolean _isCommuter( iOCar inst ) {
  iOCarData data = Data(inst);
  return wCar.iscommuter(data->props);
}

static int _getVMax( iOCar inst ) {
  iOCarData data = Data(inst);
  return wCar.getV_max(data->props);
}

/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocrail/impl/car.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
