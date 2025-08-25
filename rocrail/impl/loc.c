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

#include "rocrail/impl/loc_impl.h"
#include "rocrail/public/block.h"
#include "rocrail/public/app.h"
#include "rocrail/public/model.h"
#include "rocrail/public/control.h"
#include "rocrail/public/http.h"
#include "rocrail/public/operator.h"

#include "rocint/public/lcdriverint.h"

#include "rocs/public/doc.h"
#include "rocs/public/trace.h"
#include "rocs/public/node.h"
#include "rocs/public/mem.h"
#include "rocs/public/str.h"
#include "rocs/public/strtok.h"
#include "rocs/public/msg.h"
#include "rocs/public/lib.h"
#include "rocs/public/system.h"

#include "rocrail/wrapper/public/FreeRail.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/Ctrl.h"
#include "rocrail/wrapper/public/FunDef.h"
#include "rocrail/wrapper/public/FunCmd.h"
#include "rocrail/wrapper/public/CVByte.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/FeedbackEvent.h"
#include "rocrail/wrapper/public/Schedule.h"
#include "rocrail/wrapper/public/Tour.h"
#include "rocrail/wrapper/public/ActionCtrl.h"
#include "rocrail/wrapper/public/Stage.h"
#include "rocrail/wrapper/public/BBT.h"
#include "rocrail/wrapper/public/SBT.h"
#include "rocrail/wrapper/public/Program.h"
#include "rocrail/wrapper/public/Action.h"
#include "rocrail/wrapper/public/BinStateCmd.h"

static int instCnt = 0;

static iONode __resetTimedFunction(iOLoc loc, iONode cmd, int function);
static void __checkConsist( iOLoc inst, iONode nodeA, Boolean byEvent );
static void __funEvent( iOLoc inst, const char* blockid, int evt, int timer );
static void __swapConsist( iOLoc inst, iONode cmd );
static int __getFnAddr( iOLoc inst, int function, int* mappedfn);
static void __doSound(iOLoc inst, iONode cmd);
static void __initBBTmap( iOLoc loc );
static void __initSBTmap( iOLoc loc );
static void __initCVmap( iOLoc loc );
static Boolean __loadDriver( iOLoc inst );

/*
 ***** OBase functions.
 */
static const char* __id( void* inst ) {
  iOLocData data     = Data(inst);
  return wLoc.getid( data->props );
}

static void __checkAction( iOLoc inst, const char* state, const char* substate ) {

  iOLocData data     = Data(inst);
  iOModel   model    = AppOp.getModel();
  iONode    lcaction = wLoc.getactionctrl( data->props );

  while( lcaction != NULL) {
      if( StrOp.equals(wActionCtrl.getstate(lcaction), state ) && StrOp.equals(wActionCtrl.getsubstate(lcaction), substate ) )
      {

        iOAction action = ModelOp.getAction( AppOp.getModel(), wActionCtrl.getid( lcaction ));
        if( action != NULL ) {
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "loco action: %s", wActionCtrl.getid( lcaction ));
          ActionOp.exec(action, lcaction);
        }
      }
      else {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "%s action state does not match: [%s-%s] sub[%s-%s]",
            wLoc.getid(data->props), wActionCtrl.getstate( lcaction ), state, wActionCtrl.getsubstate( lcaction ), substate );
      }
    lcaction = wLoc.nextactionctrl( data->props, lcaction );
  }

}



static void __FnOnOff(iOLoc inst, int fn, Boolean OnOff, iONode cmd, Boolean save) {
  iOLocData data = Data(inst);
  int fgroup = 0;

  switch( fn ) {
    case  0: wFunCmd.setf0 ( cmd, OnOff ); if(save) data->fn0  = OnOff; fgroup = 0; break;
    case  1: wFunCmd.setf1 ( cmd, OnOff ); if(save) data->fn1  = OnOff; fgroup = 1; break;
    case  2: wFunCmd.setf2 ( cmd, OnOff ); if(save) data->fn2  = OnOff; fgroup = 1; break;
    case  3: wFunCmd.setf3 ( cmd, OnOff ); if(save) data->fn3  = OnOff; fgroup = 1; break;
    case  4: wFunCmd.setf4 ( cmd, OnOff ); if(save) data->fn4  = OnOff; fgroup = 1; break;
    case  5: wFunCmd.setf5 ( cmd, OnOff ); if(save) data->fn5  = OnOff; fgroup = 2; break;
    case  6: wFunCmd.setf6 ( cmd, OnOff ); if(save) data->fn6  = OnOff; fgroup = 2; break;
    case  7: wFunCmd.setf7 ( cmd, OnOff ); if(save) data->fn7  = OnOff; fgroup = 2; break;
    case  8: wFunCmd.setf8 ( cmd, OnOff ); if(save) data->fn8  = OnOff; fgroup = 2; break;
    case  9: wFunCmd.setf9 ( cmd, OnOff ); if(save) data->fn9  = OnOff; fgroup = 3; break;
    case 10: wFunCmd.setf10( cmd, OnOff ); if(save) data->fn10 = OnOff; fgroup = 3; break;
    case 11: wFunCmd.setf11( cmd, OnOff ); if(save) data->fn11 = OnOff; fgroup = 3; break;
    case 12: wFunCmd.setf12( cmd, OnOff ); if(save) data->fn12 = OnOff; fgroup = 3; break;
    case 13: wFunCmd.setf13( cmd, OnOff ); if(save) data->fn13 = OnOff; fgroup = 4; break;
    case 14: wFunCmd.setf14( cmd, OnOff ); if(save) data->fn14 = OnOff; fgroup = 4; break;
    case 15: wFunCmd.setf15( cmd, OnOff ); if(save) data->fn15 = OnOff; fgroup = 4; break;
    case 16: wFunCmd.setf16( cmd, OnOff ); if(save) data->fn16 = OnOff; fgroup = 4; break;
    case 17: wFunCmd.setf17( cmd, OnOff ); if(save) data->fn17 = OnOff; fgroup = 5; break;
    case 18: wFunCmd.setf18( cmd, OnOff ); if(save) data->fn18 = OnOff; fgroup = 5; break;
    case 19: wFunCmd.setf19( cmd, OnOff ); if(save) data->fn19 = OnOff; fgroup = 5; break;
    case 20: wFunCmd.setf20( cmd, OnOff ); if(save) data->fn20 = OnOff; fgroup = 5; break;
    case 21: wFunCmd.setf21( cmd, OnOff ); if(save) data->fn21 = OnOff; fgroup = 6; break;
    case 22: wFunCmd.setf22( cmd, OnOff ); if(save) data->fn22 = OnOff; fgroup = 6; break;
    case 23: wFunCmd.setf23( cmd, OnOff ); if(save) data->fn23 = OnOff; fgroup = 6; break;
    case 24: wFunCmd.setf24( cmd, OnOff ); if(save) data->fn24 = OnOff; fgroup = 6; break;
    case 25: wFunCmd.setf25( cmd, OnOff ); if(save) data->fn25 = OnOff; fgroup = 7; break;
    case 26: wFunCmd.setf26( cmd, OnOff ); if(save) data->fn26 = OnOff; fgroup = 7; break;
    case 27: wFunCmd.setf27( cmd, OnOff ); if(save) data->fn27 = OnOff; fgroup = 7; break;
    case 28: wFunCmd.setf28( cmd, OnOff ); if(save) data->fn28 = OnOff; fgroup = 7; break;
  }
  wFunCmd.setfncnt( cmd, wLoc.getfncnt( data->props ) );
  if( save ) {
    wFunCmd.setgroup( cmd, fgroup );
    wFunCmd.setfnchanged( cmd, fn );
  }
}


static void __cpFn2Node(iOLoc inst, iONode cmd, int fn, int addr) {
  iOLocData data = Data(inst);
  int mappedfn = fn;
  wFunCmd.setfncnt( cmd, wLoc.getfncnt( data->props ) );

  if( addr == 0 || __getFnAddr(inst, 1, &mappedfn) == addr )
    if( fn == -1 || fn != 0 ) __FnOnOff(inst, 0, data->fn0, cmd, False);

  if( addr == 0 || __getFnAddr(inst, 1, &mappedfn) == addr )
    if( fn == -1 || fn != 1 ) __FnOnOff(inst, mappedfn==-1?1:mappedfn, data->fn1, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 2, &mappedfn) == addr )
    if( fn == -1 || fn != 2 ) __FnOnOff(inst, mappedfn==-1?2:mappedfn, data->fn2, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 3, &mappedfn) == addr )
    if( fn == -1 || fn != 3 ) __FnOnOff(inst, mappedfn==-1?3:mappedfn, data->fn3, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 4, &mappedfn) == addr )
    if( fn == -1 || fn != 4 ) __FnOnOff(inst, mappedfn==-1?4:mappedfn, data->fn4, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 5, &mappedfn) == addr )
    if( fn == -1 || fn != 5 ) __FnOnOff(inst, mappedfn==-1 ? 5:mappedfn, data->fn5, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 6, &mappedfn) == addr )
    if( fn == -1 || fn != 6 ) __FnOnOff(inst, mappedfn==-1?6:mappedfn, data->fn6, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 7, &mappedfn) == addr )
    if( fn == -1 || fn != 7 ) __FnOnOff(inst, mappedfn==-1?7:mappedfn, data->fn7, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 8, &mappedfn) == addr )
    if( fn == -1 || fn != 8 ) __FnOnOff(inst, mappedfn==-1?8:mappedfn, data->fn8, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 9, &mappedfn) == addr )
    if( fn == -1 || fn != 9 ) __FnOnOff(inst, mappedfn==-1?9:mappedfn, data->fn9, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 10, &mappedfn) == addr )
    if( fn == -1 || fn != 10 ) __FnOnOff(inst, mappedfn==-1?10:mappedfn, data->fn10, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 11, &mappedfn) == addr )
    if( fn == -1 || fn != 11 ) __FnOnOff(inst, mappedfn==-1?11:mappedfn, data->fn11, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 12, &mappedfn) == addr )
    if( fn == -1 || fn != 12 ) __FnOnOff(inst, mappedfn==-1?12:mappedfn, data->fn12, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 13, &mappedfn) == addr )
    if( fn == -1 || fn != 13 ) __FnOnOff(inst, mappedfn==-1?13:mappedfn, data->fn13, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 14, &mappedfn) == addr )
    if( fn == -1 || fn != 14 ) __FnOnOff(inst, mappedfn==-1?14:mappedfn, data->fn14, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 15, &mappedfn) == addr )
    if( fn == -1 || fn != 15 ) __FnOnOff(inst, mappedfn==-1?15:mappedfn, data->fn15, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 16, &mappedfn) == addr )
    if( fn == -1 || fn != 16 ) __FnOnOff(inst, mappedfn==-1?16:mappedfn, data->fn16, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 17, &mappedfn) == addr )
    if( fn == -1 || fn != 17 ) __FnOnOff(inst, mappedfn==-1?17:mappedfn, data->fn17, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 18, &mappedfn) == addr )
    if( fn == -1 || fn != 18 ) __FnOnOff(inst, mappedfn==-1?18:mappedfn, data->fn18, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 19, &mappedfn) == addr )
    if( fn == -1 || fn != 19 ) __FnOnOff(inst, mappedfn==-1?19:mappedfn, data->fn19, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 20, &mappedfn) == addr )
    if( fn == -1 || fn != 20 ) __FnOnOff(inst, mappedfn==-1?20:mappedfn, data->fn20, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 21, &mappedfn) == addr )
    if( fn == -1 || fn != 21 ) __FnOnOff(inst, mappedfn==-1?21:mappedfn, data->fn21, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 22, &mappedfn) == addr )
    if( fn == -1 || fn != 22 ) __FnOnOff(inst, mappedfn==-1?22:mappedfn, data->fn22, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 23, &mappedfn) == addr )
    if( fn == -1 || fn != 23 ) __FnOnOff(inst, mappedfn==-1?23:mappedfn, data->fn23, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 24, &mappedfn) == addr )
    if( fn == -1 || fn != 24 ) __FnOnOff(inst, mappedfn==-1?24:mappedfn, data->fn24, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 25, &mappedfn) == addr )
    if( fn == -1 || fn != 25 ) __FnOnOff(inst, mappedfn==-1?25:mappedfn, data->fn25, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 26, &mappedfn) == addr )
    if( fn == -1 || fn != 26 ) __FnOnOff(inst, mappedfn==-1?26:mappedfn, data->fn26, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 27, &mappedfn) == addr )
    if( fn == -1 || fn != 27 ) __FnOnOff(inst, mappedfn==-1?27:mappedfn, data->fn27, cmd, False);
  if( addr == 0 || __getFnAddr(inst, 28, &mappedfn) == addr )
    if( fn == -1 || fn != 28 ) __FnOnOff(inst, mappedfn==-1?28:mappedfn, data->fn28, cmd, False);
}


static void __saveFxState(iOLoc inst) {
  iOLocData data = Data(inst);
  int fx = 0;
  fx |= data->fn1  ? 0x0000001:0;
  fx |= data->fn2  ? 0x0000002:0;
  fx |= data->fn3  ? 0x0000004:0;
  fx |= data->fn4  ? 0x0000008:0;
  fx |= data->fn5  ? 0x0000010:0;
  fx |= data->fn6  ? 0x0000020:0;
  fx |= data->fn7  ? 0x0000040:0;
  fx |= data->fn8  ? 0x0000080:0;
  fx |= data->fn9  ? 0x0000100:0;
  fx |= data->fn10 ? 0x0000200:0;
  fx |= data->fn11 ? 0x0000400:0;
  fx |= data->fn12 ? 0x0000800:0;
  fx |= data->fn13 ? 0x0001000:0;
  fx |= data->fn14 ? 0x0002000:0;
  fx |= data->fn15 ? 0x0004000:0;
  fx |= data->fn16 ? 0x0008000:0;
  fx |= data->fn17 ? 0x0010000:0;
  fx |= data->fn18 ? 0x0020000:0;
  fx |= data->fn19 ? 0x0040000:0;
  fx |= data->fn20 ? 0x0080000:0;
  fx |= data->fn21 ? 0x0100000:0;
  fx |= data->fn22 ? 0x0200000:0;
  fx |= data->fn23 ? 0x0400000:0;
  fx |= data->fn24 ? 0x0800000:0;
  fx |= data->fn25 ? 0x1000000:0;
  fx |= data->fn26 ? 0x2000000:0;
  fx |= data->fn27 ? 0x4000000:0;
  fx |= data->fn28 ? 0x8000000:0;
  wLoc.setfx( data->props, fx );
}

static Boolean __cpNode2Fn(iOLoc inst, iONode cmd) {
  iOLocData data = Data(inst);
  int function = wFunCmd.getfnchanged(cmd);

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999,
      "copy node function status, fnchanged=%d group=%d", function,wFunCmd.getgroup(cmd));

  if( function != -1 || StrOp.equals( wLoc.function, wLoc.getcmd(cmd) ) ) {
    switch ( function ) {
      case 0 : data->fn0 = wFunCmd.isf0(cmd); return data->fn0;
      case 1 : data->fn1 = wFunCmd.isf1(cmd); return data->fn1;
      case 2 : data->fn2 = wFunCmd.isf2(cmd); return data->fn2;
      case 3 : data->fn3 = wFunCmd.isf3(cmd); return data->fn3;
      case 4 : data->fn4 = wFunCmd.isf4(cmd); return data->fn4;
      case 5 : data->fn5 = wFunCmd.isf5(cmd); return data->fn5;
      case 6 : data->fn6 = wFunCmd.isf6(cmd); return data->fn6;
      case 7 : data->fn7 = wFunCmd.isf7(cmd); return data->fn7;
      case 8 : data->fn8 = wFunCmd.isf8(cmd); return data->fn8;
      case 9 : data->fn9 = wFunCmd.isf9(cmd); return data->fn9;
      case 10 : data->fn10 = wFunCmd.isf10(cmd); return data->fn10;
      case 11 : data->fn11 = wFunCmd.isf11(cmd); return data->fn11;
      case 12 : data->fn12 = wFunCmd.isf12(cmd); return data->fn12;
      case 13 : data->fn13 = wFunCmd.isf13(cmd); return data->fn13;
      case 14 : data->fn14 = wFunCmd.isf14(cmd); return data->fn14;
      case 15 : data->fn15 = wFunCmd.isf15(cmd); return data->fn15;
      case 16 : data->fn16 = wFunCmd.isf16(cmd); return data->fn16;
      case 17 : data->fn17 = wFunCmd.isf17(cmd); return data->fn17;
      case 18 : data->fn18 = wFunCmd.isf18(cmd); return data->fn18;
      case 19 : data->fn19 = wFunCmd.isf19(cmd); return data->fn19;
      case 20 : data->fn20 = wFunCmd.isf20(cmd); return data->fn20;
      case 21 : data->fn21 = wFunCmd.isf21(cmd); return data->fn21;
      case 22 : data->fn22 = wFunCmd.isf22(cmd); return data->fn22;
      case 23 : data->fn23 = wFunCmd.isf23(cmd); return data->fn23;
      case 24 : data->fn24 = wFunCmd.isf24(cmd); return data->fn24;
      case 25 : data->fn25 = wFunCmd.isf25(cmd); return data->fn25;
      case 26 : data->fn26 = wFunCmd.isf26(cmd); return data->fn26;
      case 27 : data->fn27 = wFunCmd.isf27(cmd); return data->fn27;
      case 28 : data->fn28 = wFunCmd.isf28(cmd); return data->fn28;
    }
  } else {
    if( wFunCmd.getgroup(cmd) == 0 || wFunCmd.getgroup(cmd) == 1 ) {
      data->fn0  = wFunCmd.isf0 ( cmd );
    }
    if( wFunCmd.getgroup(cmd) == 0 || wFunCmd.getgroup(cmd) == 1 ) {
      if( data->fn1 != wFunCmd.isf1 ( cmd ) ) wFunCmd.setfnchanged(cmd, 1);
      if( data->fn2 != wFunCmd.isf2 ( cmd ) ) wFunCmd.setfnchanged(cmd, 2);
      if( data->fn3 != wFunCmd.isf3 ( cmd ) ) wFunCmd.setfnchanged(cmd, 3);
      if( data->fn4 != wFunCmd.isf4 ( cmd ) ) wFunCmd.setfnchanged(cmd, 4);
      data->fn1  = wFunCmd.isf1 ( cmd );
      data->fn2  = wFunCmd.isf2 ( cmd );
      data->fn3  = wFunCmd.isf3 ( cmd );
      data->fn4  = wFunCmd.isf4 ( cmd );
    }
    if( wFunCmd.getgroup(cmd) == 0 || wFunCmd.getgroup(cmd) == 2 ) {
      if( data->fn5 != wFunCmd.isf5 ( cmd ) ) wFunCmd.setfnchanged(cmd, 5);
      if( data->fn6 != wFunCmd.isf6 ( cmd ) ) wFunCmd.setfnchanged(cmd, 6);
      if( data->fn7 != wFunCmd.isf7 ( cmd ) ) wFunCmd.setfnchanged(cmd, 7);
      if( data->fn8 != wFunCmd.isf8 ( cmd ) ) wFunCmd.setfnchanged(cmd, 8);
      data->fn5  = wFunCmd.isf5 ( cmd );
      data->fn6  = wFunCmd.isf6 ( cmd );
      data->fn7  = wFunCmd.isf7 ( cmd );
      data->fn8  = wFunCmd.isf8 ( cmd );
    }
    if( wFunCmd.getgroup(cmd) == 0 || wFunCmd.getgroup(cmd) == 3 ) {
      if( data->fn9  != wFunCmd.isf9  ( cmd ) ) wFunCmd.setfnchanged(cmd, 9 );
      if( data->fn10 != wFunCmd.isf10 ( cmd ) ) wFunCmd.setfnchanged(cmd, 10);
      if( data->fn11 != wFunCmd.isf11 ( cmd ) ) wFunCmd.setfnchanged(cmd, 11);
      if( data->fn12 != wFunCmd.isf12 ( cmd ) ) wFunCmd.setfnchanged(cmd, 12);
      data->fn9  = wFunCmd.isf9 ( cmd );
      data->fn10 = wFunCmd.isf10( cmd );
      data->fn11 = wFunCmd.isf11( cmd );
      data->fn12 = wFunCmd.isf12( cmd );
    }
    if( wFunCmd.getgroup(cmd) == 0 || wFunCmd.getgroup(cmd) == 4 ) {
      if( data->fn13 != wFunCmd.isf13 ( cmd ) ) wFunCmd.setfnchanged(cmd, 13);
      if( data->fn14 != wFunCmd.isf14 ( cmd ) ) wFunCmd.setfnchanged(cmd, 14);
      if( data->fn15 != wFunCmd.isf15 ( cmd ) ) wFunCmd.setfnchanged(cmd, 15);
      if( data->fn16 != wFunCmd.isf16 ( cmd ) ) wFunCmd.setfnchanged(cmd, 16);
      data->fn13 = wFunCmd.isf13( cmd );
      data->fn14 = wFunCmd.isf14( cmd );
      data->fn15 = wFunCmd.isf15( cmd );
      data->fn16 = wFunCmd.isf16( cmd );
    }
    if( wFunCmd.getgroup(cmd) == 0 || wFunCmd.getgroup(cmd) == 5 ) {
      if( data->fn17 != wFunCmd.isf17 ( cmd ) ) wFunCmd.setfnchanged(cmd, 17);
      if( data->fn18 != wFunCmd.isf18 ( cmd ) ) wFunCmd.setfnchanged(cmd, 18);
      if( data->fn19 != wFunCmd.isf19 ( cmd ) ) wFunCmd.setfnchanged(cmd, 19);
      if( data->fn20 != wFunCmd.isf20 ( cmd ) ) wFunCmd.setfnchanged(cmd, 20);
      data->fn17 = wFunCmd.isf17( cmd );
      data->fn18 = wFunCmd.isf18( cmd );
      data->fn19 = wFunCmd.isf19( cmd );
      data->fn20 = wFunCmd.isf20( cmd );
    }
    if( wFunCmd.getgroup(cmd) == 0 || wFunCmd.getgroup(cmd) == 6 ) {
      if( data->fn21 != wFunCmd.isf21 ( cmd ) ) wFunCmd.setfnchanged(cmd, 21);
      if( data->fn22 != wFunCmd.isf22 ( cmd ) ) wFunCmd.setfnchanged(cmd, 22);
      if( data->fn23 != wFunCmd.isf23 ( cmd ) ) wFunCmd.setfnchanged(cmd, 23);
      if( data->fn24 != wFunCmd.isf24 ( cmd ) ) wFunCmd.setfnchanged(cmd, 24);
      data->fn21 = wFunCmd.isf21( cmd );
      data->fn22 = wFunCmd.isf22( cmd );
      data->fn23 = wFunCmd.isf23( cmd );
      data->fn24 = wFunCmd.isf24( cmd );
    }
    if( wFunCmd.getgroup(cmd) == 0 || wFunCmd.getgroup(cmd) == 7 ) {
      if( data->fn25 != wFunCmd.isf25 ( cmd ) ) wFunCmd.setfnchanged(cmd, 25);
      if( data->fn26 != wFunCmd.isf26 ( cmd ) ) wFunCmd.setfnchanged(cmd, 26);
      if( data->fn27 != wFunCmd.isf27 ( cmd ) ) wFunCmd.setfnchanged(cmd, 27);
      if( data->fn28 != wFunCmd.isf28 ( cmd ) ) wFunCmd.setfnchanged(cmd, 28);
      data->fn25 = wFunCmd.isf25( cmd );
      data->fn26 = wFunCmd.isf26( cmd );
      data->fn27 = wFunCmd.isf27( cmd );
      data->fn28 = wFunCmd.isf28( cmd );
    }
  }
  return False;
}


static void __resetFx( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOLoc loc = (iOLoc)ThreadOp.getParm( th );
  iOLocData data = Data(loc);
  iONode fcmd = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE );

  ThreadOp.sleep(100 + 200 * data->fxsleep );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "resetfx group %d for %s", data->fxgroup, wLoc.getid(data->props) );

  wFunCmd.setgroup(fcmd, data->fxgroup);
  __cpFn2Node(loc, fcmd, -1, 0);
  switch(data->fxgroup) {
  case 0:
    wLoc.setfn(fcmd, False);
    wFunCmd.setf0(fcmd, False);
    wFunCmd.setf1(fcmd, False);
    wFunCmd.setf2(fcmd, False);
    wFunCmd.setf3(fcmd, False);
    wFunCmd.setf4(fcmd, False);
    break;
  case 1:
    wFunCmd.setf5(fcmd, False);
    wFunCmd.setf6(fcmd, False);
    wFunCmd.setf7(fcmd, False);
    wFunCmd.setf8(fcmd, False);
    break;
  case 2:
    wFunCmd.setf9(fcmd, False);
    wFunCmd.setf10(fcmd, False);
    wFunCmd.setf11(fcmd, False);
    wFunCmd.setf12(fcmd, False);
    break;
  case 3:
    wFunCmd.setf13(fcmd, False);
    wFunCmd.setf14(fcmd, False);
    wFunCmd.setf15(fcmd, False);
    wFunCmd.setf16(fcmd, False);
    break;
  case 4:
    wFunCmd.setf17(fcmd, False);
    wFunCmd.setf18(fcmd, False);
    wFunCmd.setf19(fcmd, False);
    wFunCmd.setf20(fcmd, False);
    break;
  case 5:
    wFunCmd.setf21(fcmd, False);
    wFunCmd.setf22(fcmd, False);
    wFunCmd.setf23(fcmd, False);
    wFunCmd.setf24(fcmd, False);
    break;
  case 6:
    wFunCmd.setf25(fcmd, False);
    wFunCmd.setf26(fcmd, False);
    wFunCmd.setf27(fcmd, False);
    wFunCmd.setf28(fcmd, False);
    break;
  }
  __cpNode2Fn(loc, fcmd);

  wFunCmd.setid( fcmd, wLoc.getid( data->props ) );
  wFunCmd.setaddr( fcmd, wLoc.getaddr( data->props ) );
  wLoc.setfx( fcmd, wLoc.getfx( data->props ) );

  LocOp.cmd(loc, (iONode)NodeOp.base.clone(fcmd) );

  wLoc.setfx( fcmd, wLoc.getfx( data->props ) );
  AppOp.broadcastEvent( fcmd );

  data->fxresetpending = False;
  ThreadOp.base.del(th);
}


static void __restoreFx( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOLoc loc = (iOLoc)ThreadOp.getParm( th );
  iOLocData data = Data(loc);

  int fx = wLoc.getfx(data->props);
  int i = 0;

  ThreadOp.sleep(100 + 200 * data->fxsleep );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "restore started for %s", wLoc.getid(data->props) );

  if( wLoc.isrestorefx(data->props) ) {
    /* Test for restoring the lights function. */
    if( wLoc.isfn(data->props) ) {
      iONode vcmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "restoring lights for %s", wLoc.getid(data->props) );
      if ( wLoc.isrestorespeed(data->props) ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "restoring speed for %s to %d", wLoc.getid(data->props), wLoc.getV(data->props) );
        wLoc.setV( vcmd, wLoc.getV(data->props) );
      }
      else {
        wLoc.setV( vcmd, 0 );
      }
      wLoc.setfn( vcmd, wLoc.isfn(data->props) );
      LocOp.cmd(loc, vcmd);
      ThreadOp.sleep(500);
    }

    if( wLoc.isfn(data->props) ) {
      iONode fcmd = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE );
      wFunCmd.setgroup( fcmd, 1 );
      wFunCmd.setfnchanged( fcmd, 0 );
      wFunCmd.setf0(fcmd, True);
      wLoc.setfn(fcmd, True);
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "restoring lights for %s", wLoc.getid(data->props) );
      LocOp.cmd(loc, fcmd);
      ThreadOp.sleep(500);
    }

    for( i = 0; i < 28; i++ ) {
      int f = (1 << i);
      if( fx & f ) {
        int group = (i+1) / 4;
        if( (i+1) % 4 != 0 )
          group++;

        iONode fcmd = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE );
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "restoring function %d for %s fg=%d fx=%X", i+1, wLoc.getid(data->props), group, fx );
        wFunCmd.setf0 ( fcmd, wLoc.isfn(data->props));
        wFunCmd.setgroup ( fcmd, group );
        wFunCmd.setfnchanged( fcmd, i + 1);
        wFunCmd.setf1 ( fcmd, fx & 0x01);
        wFunCmd.setf2 ( fcmd, fx & 0x02);
        wFunCmd.setf3 ( fcmd, fx & 0x04);
        wFunCmd.setf4 ( fcmd, fx & 0x08);
        wFunCmd.setf5 ( fcmd, fx & 0x10);
        wFunCmd.setf6 ( fcmd, fx & 0x20);
        wFunCmd.setf7 ( fcmd, fx & 0x40);
        wFunCmd.setf8 ( fcmd, fx & 0x80);
        wFunCmd.setf9 ( fcmd, fx & 0x0100);
        wFunCmd.setf10( fcmd, fx & 0x0200);
        wFunCmd.setf11( fcmd, fx & 0x0400);
        wFunCmd.setf12( fcmd, fx & 0x0800);
        wFunCmd.setf13( fcmd, fx & 0x1000);
        wFunCmd.setf14( fcmd, fx & 0x2000);
        wFunCmd.setf15( fcmd, fx & 0x4000);
        wFunCmd.setf16( fcmd, fx & 0x8000);
        wFunCmd.setf17( fcmd, fx & 0x010000);
        wFunCmd.setf18( fcmd, fx & 0x020000);
        wFunCmd.setf19( fcmd, fx & 0x040000);
        wFunCmd.setf20( fcmd, fx & 0x080000);
        wFunCmd.setf21( fcmd, fx & 0x100000);
        wFunCmd.setf22( fcmd, fx & 0x200000);
        wFunCmd.setf23( fcmd, fx & 0x400000);
        wFunCmd.setf24( fcmd, fx & 0x800000);
        wFunCmd.setf25( fcmd, fx & 0x01000000);
        wFunCmd.setf26( fcmd, fx & 0x02000000);
        wFunCmd.setf27( fcmd, fx & 0x04000000);
        wFunCmd.setf28( fcmd, fx & 0x08000000);
        LocOp.cmd(loc, fcmd);
        ThreadOp.sleep(500);
      }
    }
    data->fxrestoredbythread = True;
  }

  if( wLoc.getV(data->props) > 0 && wLoc.isrestorespeed(data->props) ) {
    iONode vcmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "restoring speed for %s", wLoc.getid(data->props) );
    wLoc.setV( vcmd, wLoc.getV(data->props) );
    wLoc.setfn( vcmd, wLoc.isfn(data->props) );
    LocOp.cmd(loc, vcmd);
    data->speedrestoredbythread = True;
  }


  ThreadOp.base.del(th);
}



static void __V0AtPowerOn( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOLoc loc = (iOLoc)ThreadOp.getParm( th );
  iOLocData data = Data(loc);
  iONode node = NodeOp.inst(wLoc.name(), NULL, ELEMENT_NODE);

  ThreadOp.sleep(100 + 200 * data->fxsleep );

  wLoc.setV( node, 0 );
  wLoc.setfn( node, wLoc.isfn(data->props) );
  wLoc.setdir( node, wLoc.isdir(data->props) );
  LocOp.cmd(loc, node);

  data->v0pending = False;
  ThreadOp.base.del(th);
}


static void __sysEvent( obj inst, iONode evtNode ) {
  iOLocData data = Data(inst);
  const char* cmd = wSysCmd.getcmd(evtNode);

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "sysEvent [%s] for [%s]...", cmd, LocOp.getId((iOLoc)inst) );

  if( wLoc.isshow(data->props) && StrOp.equals( wSysCmd.go, cmd ) ) {
    if( !data->v0pending && data->drvSpeed == 0 && wCtrl.isv0atpoweron( AppOp.getIniNode(wCtrl.name())) ) {
      iOThread th = ThreadOp.inst( NULL, &__V0AtPowerOn, inst );
      data->v0sleep = wSysCmd.getval(evtNode);
      data->v0pending = True;
      ThreadOp.start(th);
    }
  }

  if( StrOp.equals( wSysCmd.resetfx, cmd ) ) {
    data->fxsleep = wSysCmd.getval(evtNode);
    {
      iOThread th = ThreadOp.inst( NULL, &__resetFx, inst );
      data->fxresetpending = True;
      data->fxgroup = wSysCmd.getvalA(evtNode);
      ThreadOp.start(th);
    }
  }
  else if( wLoc.isshow(data->props) && StrOp.equals( wSysCmd.go, cmd ) && (!data->fxrestored||wLoc.isrestorefxalways(data->props)) ) {
    /* restore fx */
    data->fxrestored = True;
    data->fxrestoredbythread = False;
    data->speedrestoredbythread = False;
    data->fxsleep = wSysCmd.getval(evtNode);
    if( wLoc.isrestorefx(data->props) || wLoc.isrestorespeed(data->props) ) {
      iOThread th = ThreadOp.inst( NULL, &__restoreFx, inst );
      ThreadOp.start(th);
    }
  }
}


static int __getVfromRaw(void* inst, iONode evtNode) {
  iOLocData data = Data(inst);

  int spcnt = wLoc.getspcnt( data->props );
  int V = 0;
  int V_raw = wLoc.getV_raw(evtNode);
  int V_rawMax = wLoc.getV_rawMax(evtNode);

  if( V_raw != -1 ) {
    float fV = wLoc.getV_max( data->props ) * V_raw;
    float div = (V_rawMax == -1 ? spcnt:V_rawMax);
    if( StrOp.equals( wLoc.getV_mode( data->props ), wLoc.V_mode_percent ) )
      fV = 100 * V_raw;
    fV = fV / div;
    V = (int)fV;
    if( fV - V >= 0.5 )
      V++;
  }
  else {
    V = wLoc.getV( data->props );
    if( data->curSpeed > V )
      V = data->curSpeed;
  }
  return V;
}


static void _depart(iOLoc inst) {
  iOLocData data = Data(inst);

  if( data->curBlock != NULL ) {
    iIBlockBase curblock  = ModelOp.getBlock( AppOp.getModel(), data->curBlock );
    if( curblock != NULL ) {
      curblock->depart(curblock);
    }
  }
}


static void __broadcastLocoProps( iOLoc inst, const char* cmd, iONode node, const char* blockId ) {
  iOLocData data = Data(inst);
  if( node == NULL )
    node = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( node, wLoc.getid( data->props ) );
  wLoc.setdir( node, wLoc.isdir( data->props ) );
  wLoc.setaddr( node, wLoc.getaddr( data->props ) );
  wLoc.setsecaddr( node, wLoc.getsecaddr( data->props ) );
  wLoc.setV( node, wLoc.getV( data->props ) );
  wLoc.setplacing( node, wLoc.isplacing( data->props ) );
  wLoc.setblockenterside( node, wLoc.isblockenterside( data->props ) );
  wLoc.setblockenterid( node, wLoc.getblockenterid( data->props ) );
  wLoc.setmode( node, wLoc.getmode( data->props ) );
  wLoc.setmodereason( node, wLoc.getmodereason( data->props ) );
  wLoc.setresumeauto( node, wLoc.isresumeauto(data->props) );
  wLoc.setmanual( node, data->gomanual );
  if( blockId != NULL )
    wLoc.setdestblockid(node, blockId );
  else
    wLoc.setdestblockid( node, data->destBlock );

  wLoc.setblockid( node, data->curBlock );
  if( (wLoc.getdestblockid(node) != NULL && StrOp.equals(wLoc.getdestblockid(node), wLoc.getblockid(node))) || wLoc.getdestblockid(node) == NULL )
    wLoc.setdestblockid( node, "" );
  wLoc.setfn( node, wLoc.isfn(data->props) );
  wLoc.setruntime( node, wLoc.getruntime(data->props) );
  wLoc.setmtime( node, wLoc.getmtime(data->props) );
  wLoc.setmint( node, wLoc.getmint(data->props) );
  wLoc.setthrottleid( node, wLoc.getthrottleid(data->props) );
  wLoc.setactive( node, wLoc.isactive(data->props) );
  if( data->driver != NULL ) {
    wLoc.setscidx( node, data->driver->getScheduleIdx( data->driver ) );
    wLoc.setscheduleid(node, LocOp.getSchedule(inst, NULL));
    wLoc.settourid(node, LocOp.getTour(inst));
  }
  wLoc.settrain( node, wLoc.gettrain(data->props) );
  wLoc.settrainlen( node, wLoc.gettrainlen(data->props) );
  wLoc.settrainweight( node, wLoc.gettrainweight(data->props) );
  wLoc.setV_realkmh( node, wLoc.getV_realkmh(data->props) );
  if( cmd != NULL )
    wLoc.setcmd( node, cmd );
  wLoc.setfifotop( node, wLoc.isfifotop( data->props ) );
  AppOp.broadcastEvent( node );
}

static void* __event( void* inst, const void* evt ) {
  iOLocData data = Data(inst);
  iONode evtNode = (iONode)evt;
  Boolean broadcast = False;

  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "event for loco %s: %s", wLoc.getid(data->props), NodeOp.getName(evtNode) );

  if( evtNode == NULL )
    return NULL;

  if( StrOp.equals( wLoc.name(), NodeOp.getName(evtNode) ) && StrOp.equals( wLoc.bidikmh, wLoc.getcmd(evtNode) ) ) {
    int kmh = wLoc.getV_realkmh(evtNode);
    wLoc.setV_realkmh( data->props, kmh );
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "reported speed for [%s] is %dkm/h", wLoc.getid(data->props), kmh );
    __broadcastLocoProps(inst, wLoc.bidikmh, NULL, NULL);
    return NULL;
  }

  if( data->go && !data->gomanual ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
        "ignore field event for [%s] while running in auto mode", wLoc.getid(data->props) );
    return NULL;
  }

  if( StrOp.equals( wLoc.name(), NodeOp.getName(evtNode) ) && StrOp.equals( wLoc.fieldcmd, wLoc.getcmd(evtNode) ) ) {
    int V = __getVfromRaw(inst, evtNode);
    int V_raw = wLoc.getV_raw(evtNode);
    int V_rawMax = wLoc.getV_rawMax(evtNode);
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "field command for [%s] V=%d V_raw=%d V_rawMax=%d lights=%d", wLoc.getid(data->props), V, V_raw, V_rawMax, wLoc.isfn(evtNode) );
    wLoc.setcmd(evtNode, wLoc.velocity );
    wLoc.setV(evtNode, V );
    wLoc.setfn( data->props, wLoc.isfn(evtNode) );
    data->fn0 = wLoc.isfn(evtNode);
    LocOp.cmd(inst, (iONode)NodeOp.base.clone(evtNode));
    return NULL;
  }

  if( StrOp.equals( wFunCmd.name(), NodeOp.getName(evtNode) ) && StrOp.equals( wLoc.fieldcmd, wLoc.getcmd(evtNode) ) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "field function command for [%s] fnchanged=%d", wLoc.getid(data->props), wFunCmd.getfnchanged(evtNode) );
    NodeOp.removeAttrByName(evtNode, "cmd");
    LocOp.cmd(inst, (iONode)NodeOp.base.clone(evtNode));
    return NULL;
  }

  if( StrOp.equals( wLoc.name(), NodeOp.getName(evtNode) ) || StrOp.equals( wFunCmd.name(), NodeOp.getName(evtNode) ) ) {
    if( wLoc.isrestorefx(data->props) && !data->fxrestoredbythread ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
          "ignore field event for [%s] while function restore is not ready", wLoc.getid(data->props) );
      return NULL;
    }
  }

  if( !MutexOp.trywait( data->muxEngine, 100 ) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "(event) loco %s engine lock timeout", wLoc.getid(data->props) );
    return NULL;
  }

  if( wLoc.getaddr(evtNode) == 0 ) {
    wLoc.setaddr(evtNode, wLoc.getaddr(data->props));
  }

  if( StrOp.equals( wLoc.name(), NodeOp.getName(evtNode) ) && wLoc.getaddr( evtNode ) != wLoc.getsecaddr( data->props ) ) {
    int V = __getVfromRaw(inst, evtNode);
    int spcnt = wLoc.getspcnt( data->props );
    int V_raw = wLoc.getV_raw(evtNode);
    int V_rawMax = wLoc.getV_rawMax(evtNode);

    if( StrOp.equals( wLoc.direction, wLoc.getcmd(evtNode) ) || StrOp.equals( wLoc.dirfun, wLoc.getcmd(evtNode) ) ) {
      /* function and dir update */
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "lc=%s dir=%d fn=%d",
          wLoc.getid(data->props), wLoc.isdir(evtNode), wLoc.isfn(evtNode) );
      if( !data->go ) {
        wLoc.setdir( data->props, wLoc.isplacing(data->props) ? wLoc.isdir(evtNode):!wLoc.isdir(evtNode) );
        if( StrOp.equals( wLoc.dirfun, wLoc.getcmd(evtNode) ) ) {
          wLoc.setfn( data->props, wLoc.isfn(evtNode) );
          data->fn0 = wLoc.isfn(evtNode);
        }
      }
    }

    if( !data->go || data->gomanual ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "lc=%s V=%d(%d)",
          wLoc.getid(data->props), V, wLoc.getV(data->props) );
      wLoc.setV( data->props, V);
      data->drvSpeed = V;
      if( StrOp.equals( wLoc.velocity, wLoc.getcmd(evtNode) ) ) {
        wLoc.setdir( data->props, wLoc.isplacing(data->props) ? wLoc.isdir(evtNode):!wLoc.isdir(evtNode) );
      }
    }
    else {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "not using the field velocity because loco %s is in auto mode", wLoc.getid(data->props));
    }

    if( wCtrl.isallowzerothrottleid( AppOp.getIniNode( wCtrl.name() ) ) ||
        (StrOp.len(wLoc.getthrottleid(evtNode)) > 0 && !StrOp.equals( "0", wLoc.getthrottleid(evtNode) ) ) ) {
      wLoc.setthrottleid( data->props, wLoc.getthrottleid(evtNode) );
      /* TODO: inform consist slaves */
      __checkConsist(inst, evtNode, True);
      broadcast = True;
    }
    else {
      /* this is an echo comming from the loconet reader; do not broadcast it */
      TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "ignoring field event for loco %s because its an echo or zero throttleID", wLoc.getid(data->props));
      broadcast = False;
    }

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "lc=%s V_raw=%d V=%d fn=%d dir=%s throttleID=%s",
        wLoc.getid(data->props), V_raw, V, wLoc.isfn(data->props), wLoc.isdir(data->props)?"Forwards":"Reverse",
        wLoc.getthrottleid(data->props)!=NULL?wLoc.getthrottleid(data->props):"-" );
    /* Broadcast to clients. */
    if( broadcast ) {
      __broadcastLocoProps(inst, NULL, NULL, NULL);
    }

  }
  else if( StrOp.equals( wFunCmd.name(), NodeOp.getName(evtNode) )) {
    /* TODO: the digint library should provide the function group to prevent overwriting not reported functions */
    __cpNode2Fn(inst, evtNode);
    wLoc.setfn( data->props, data->fn0);

    if( wCtrl.isallowzerothrottleid( AppOp.getIniNode( wCtrl.name() ) ) ||
        ( StrOp.len(wLoc.getthrottleid(evtNode)) > 0 && !StrOp.equals( "0", wLoc.getthrottleid(evtNode) ) ) )
    {
      wLoc.setthrottleid( data->props, wLoc.getthrottleid(evtNode) );
      if( SystemOp.getTick() - data->lastfncmd > 100 ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "trigger sound for external throttle lc=%s throttleid=%s",
            wLoc.getid( data->props ), wLoc.getthrottleid(data->props)!=NULL?wLoc.getthrottleid(data->props):"-");
        __doSound( inst, evtNode );
      }
      __checkConsist(inst, evtNode, True);
      broadcast = True;
    }
    else {
      /* this is an echo comming from the loconet reader; do not broadcast it */
      broadcast = False;
    }

    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
        "lc=%s throttleid=%s chfn=%d chgr=%d f0=%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
        wLoc.getid( data->props ),
        wLoc.getthrottleid( data->props)!=NULL?wLoc.getthrottleid( data->props):"-",
        wFunCmd.getfnchanged( evtNode),
        wFunCmd.getgroup( evtNode),
        wLoc.isfn(data->props) ? "on":"off",
        data->fn1  ? "01":"--", data->fn2  ? "02":"--", data->fn3  ? "03":"--", data->fn4  ? "04":"--",
        data->fn5  ? "05":"--", data->fn6  ? "06":"--", data->fn7  ? "07":"--", data->fn8  ? "08":"--",
        data->fn9  ? "09":"--", data->fn10 ? "10":"--", data->fn11 ? "11":"--", data->fn12 ? "12":"--",
        data->fn13 ? "13":"--", data->fn14 ? "14":"--", data->fn15 ? "15":"--", data->fn16 ? "16":"--",
        data->fn17 ? "17":"--", data->fn18 ? "18":"--", data->fn19 ? "19":"--", data->fn20 ? "20":"--",
        data->fn21 ? "21":"--", data->fn22 ? "22":"--", data->fn23 ? "23":"--", data->fn24 ? "24":"--",
        data->fn25 ? "25":"--", data->fn26 ? "26":"--", data->fn27 ? "27":"--", data->fn28 ? "28":"--"
    );
    /* Broadcast to clients. */
    if( broadcast ) {
      iONode node = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE );
      wFunCmd.setid( node, wLoc.getid( data->props ) );
      wFunCmd.setaddr( node, wLoc.getaddr( data->props ) );
      __cpFn2Node(inst, node, -1, 0);
      if( wLoc.getthrottleid( data->props) != NULL )
        wLoc.setthrottleid( node, wLoc.getthrottleid(data->props) );
      wFunCmd.setf0( node, wLoc.isfn(data->props) );
      wFunCmd.setgroup( node, wFunCmd.getgroup( evtNode)),
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "broadcasting function command %d...", wFunCmd.isf0( node));
      AppOp.broadcastEvent( node );
    }
  }
  else if( StrOp.equals( wSysCmd.name(), NodeOp.getName(evtNode) ) ) {
    __sysEvent( inst, evtNode );
  }

  MutexOp.post( data->muxEngine );

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
  return (char*)LocOp.getId( (iOLoc)inst );
}
static void __del(void* inst) {
  iOLocData data = Data(inst);
  int retry = 0;
  data->run = False;

  ModelOp.removeSysEventListener( AppOp.getModel(), (obj)inst );

  /* wait for thread to stop. */
  while( data->running && retry < 10 ) {
    ThreadOp.sleep( 100 );
    retry++;
  };
  if( data->runner != NULL )
    ThreadOp.base.del(data->runner);
  freeMem( data );
  freeMem( inst );
  instCnt--;
}
static void* __properties(void* inst) {
  iOLocData data = Data(inst);
  return data->props;
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


static int __translateVhint(iOLoc inst, const char* V_hint, int V_maxkmh ) {
  iOLocData data = Data(inst);
  int       V_new  = -1;

  int V_max = wLoc.getV_max( data->props );
  int V_mid = wLoc.getV_mid( data->props );
  int V_min = wLoc.getV_min( data->props );
  int V_cru = wLoc.getV_cru( data->props );

  if( wLoc.gettrain( data->props) != NULL && StrOp.len(wLoc.gettrain( data->props)) > 0 ) {
    iOOperator train = ModelOp.getOperator(AppOp.getModel(), wLoc.gettrain( data->props) );
    if( train != NULL ) {
      int V_max_train = OperatorOp.getVMax(train);
      if( (V_max_train > 0 && (V_max_train < V_maxkmh)) || V_maxkmh == 0 )
        V_maxkmh = V_max_train;
    }
  }

  /* inform all slave locos of the new maxkmh */
  if( wLoc.getconsist(data->props) != NULL && StrOp.len(wLoc.getconsist(data->props)) > 0) {
    iOStrTok  consist = StrTokOp.inst( wLoc.getconsist ( data->props ), ',' );
    while( StrTokOp.hasMoreTokens( consist ) ) {
      const char* tok = StrTokOp.nextToken( consist );
      iOLoc consistloc = ModelOp.getLoc( AppOp.getModel(), tok, NULL, False );
      if( consistloc != NULL ) {
        LocOp.setMaxKmh(consistloc, V_maxkmh);
      }
    }
    StrTokOp.base.del( consist );
  }

  /* use the maxkmh from master */
  if( ModelOp.getMasterLoc(AppOp.getModel(), wLoc.getid(data->props) ) != NULL ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "slave loco [%s] maxkmh=%d", wLoc.getid(data->props), data->maxkmh);
    V_maxkmh = data->maxkmh;
  }



  if( !wLoc.isdir(data->props) || (wLoc.isdir(data->props) && !wLoc.isplacing( data->props ) ) ){
    if( wLoc.getV_Rmax( data->props ) > 0 ) {
      V_max = wLoc.getV_Rmax( data->props );
    }
    if( wLoc.getV_Rmid( data->props ) > 0 ) {
      V_mid = wLoc.getV_Rmid( data->props );
    }
    if( wLoc.getV_Rmin( data->props ) > 0 ) {
      V_min = wLoc.getV_Rmin( data->props );
    }
    if( wLoc.getV_Rcru( data->props ) > 0 ) {
      V_cru = wLoc.getV_Rcru( data->props );
    }
  }

  if( StrOp.equals( wLoc.min, V_hint ) )
    V_new = V_min;

  else if( StrOp.equals( wLoc.mid, V_hint ) )
    V_new = V_mid;

  else if( StrOp.equals( wLoc.max, V_hint ) )
    V_new = V_max;

  else if( StrOp.equals( wLoc.cruise, V_hint ) ) {
    if( V_cru > 0 ) {
      V_new = V_cru;
    }
    else {
      V_new = V_max;
      V_new = (V_new * 80) / 100;
    }
  }

  else if( StrOp.equals( wLoc.climb, V_hint ) ) {
    V_new = V_max;
    V_new = (V_new * 90) / 100;
  }
  else {
    /* percent hint */
    int percent = atoi(V_hint);
    V_new = V_max;
    V_new = (V_new * percent) / 100;
    if( percent == 0 )
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "V_hint: \"%s\" = %d", V_hint, V_new );
  }
  
  if(StrOp.equals( wLoc.V_mode_kmh, wLoc.getV_mode(data->props) ) && V_maxkmh > 0 ) {
    int l_Vnew = V_new;
    if( V_new > V_maxkmh ) {
      V_new = V_maxkmh;
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "loco [%s] reduce max. speed from %dKmh to %dKmh", wLoc.getid(data->props), l_Vnew, V_maxkmh );
    }
  }

  return V_new;
}

/*return equal=0, lower=-1, higher=1*/
int _compareVhint(iOLoc inst, const char* V_hint) {
  iOLocData data  = Data(inst);
  int       V_new = __translateVhint( inst, V_hint, 0 );

  if( V_new == data->drvSpeed )
    return 0;
  else if( V_new > data->drvSpeed )
    return 1;
  else
    return -1;
}


static int _getFnNrByDesc( iOLoc inst, const char* desc) {
  iOLocData    data = Data(inst);

  iONode fundef = wLoc.getfundef( data->props );
  while( fundef != NULL ) {
    if( wFunDef.gettext(fundef) != NULL && StrOp.equals(wFunDef.gettext(fundef), desc) ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "function number for [%s] = %d", desc, wFunDef.getfn(fundef) );
      return wFunDef.getfn(fundef);
    }
    fundef = wLoc.nextfundef( data->props, fundef );
  };

  if( StrOp.len(desc) > 0 && isdigit(desc[0]) )
    return atoi(desc);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "loco function [%s] not defined", desc );
  return -1;
}

static int __getFnTimer( iOLoc inst, int function) {
  iOLocData    data = Data(inst);

  iONode fundef = wLoc.getfundef( data->props );
  while( fundef != NULL ) {
    if( wFunDef.getfn(fundef) == function ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "function timer for %d = %d", function, wFunDef.gettimer(fundef) );
      return wFunDef.gettimer(fundef);
    }
    fundef = wLoc.nextfundef( data->props, fundef );
  };
  return 0;
}

static int __getFnAddr( iOLoc inst, int function, int* mappedfn) {
  iOLocData    data = Data(inst);

  iONode fundef = wLoc.getfundef( data->props );

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
    fundef = wLoc.nextfundef( data->props, fundef );
  };
  if( mappedfn != NULL ) {
    *mappedfn = function;
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "function %d not defined", *mappedfn );
  }
  return wLoc.getaddr( data->props );
}

static const char* __getFnSound( iOLoc inst, int function, int* addr) {
  iOLocData    data = Data(inst);

  iONode fundef = wLoc.getfundef( data->props );

  while( fundef != NULL ) {
    if( wFunDef.getfn(fundef) == function ) {
      *addr = wFunDef.getaddr(fundef);
      return wFunDef.getsound(fundef);
    }
    fundef = wLoc.nextfundef( data->props, fundef );
  };
  return NULL;
}

static void __doSound(iOLoc inst, iONode cmd) {
  iOLocData    data = Data(inst);

  if( wFunCmd.getfnchanged(cmd) != -1 ) {
    int fx = wLoc.getfx( data->props );
    if( fx & 1 << (wFunCmd.getfnchanged(cmd)-1) ) {
      int addr = 0;
      const char* sound = __getFnSound(inst, wFunCmd.getfnchanged(cmd), &addr );
      if( sound != NULL && StrOp.len(sound) > 0 ) {
        if( addr == 0 ) {
          /* play */
          char* s = NULL;
          if( wFreeRail.issoundplayerlocation(AppOp.getIni()) && data->curBlock != NULL && data->curSensor != NULL )
            s = StrOp.fmt("%s \"%s%c%s\" \"%s\" \"%s\"", wFreeRail.getsoundplayer(AppOp.getIni()),
                wFreeRail.getsoundpath(AppOp.getIni()), SystemOp.getFileSeparator(), sound, data->curBlock, data->curSensor );
          else if( wFreeRail.issoundplayerlocation(AppOp.getIni()) && data->curBlock != NULL )
            s = StrOp.fmt("%s \"%s%c%s\" \"%s\"", wFreeRail.getsoundplayer(AppOp.getIni()),
                wFreeRail.getsoundpath(AppOp.getIni()), SystemOp.getFileSeparator(), sound, data->curBlock );
          else
            s = StrOp.fmt("%s \"%s%c%s\"", wFreeRail.getsoundplayer(AppOp.getIni()),
                wFreeRail.getsoundpath(AppOp.getIni()), SystemOp.getFileSeparator(), sound );
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "executing [%s]", s );
          SystemOp.system( s, True, False );
          StrOp.free(s);
        }
        else {
          iONode cmd = NodeOp.inst( wAction.name(), NULL, ELEMENT_NODE );
          wAction.setcmd( cmd, wAction.sound_play );
          wAction.setiid( cmd, wLoc.getiid( data->props ) );
          wAction.setbus( cmd, wLoc.getaddr( data->props ) );
          wAction.setsndfile( cmd, sound );
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "sound action on bus %d [%s]", wLoc.getaddr( data->props ), sound );
          ControlOp.cmd( AppOp.getControl(), cmd, NULL );
        }
      }
    }
  }

}

/*
  Using the new V_* attributes for controlling loc speed.
*/
/*
   Called by the loc runner in a 100ms cycle or
   some object called it with a command node.
*/
static Boolean __engine( iOLoc inst, iONode cmd ) {
  iOLocData    data = Data(inst);
  iOControl control = AppOp.getControl();
  Boolean didPost = False;

  const char* V_hint   = NULL;
  int         V_maxkmh = 0;
  int         V_new    = -1;
  int         V_old    = wLoc.getV(data->props);
  iONode      cmdTD    = NULL;
  iONode      cmdFn    = NULL;
  int     fnchanged   = -1;
  Boolean useSecAddr = False;

  if( cmd != NULL )
  {
    V_new    = wLoc.getV( cmd );
    V_hint   = wLoc.getV_hint( cmd );
    V_maxkmh = wLoc.getV_maxkmh( cmd );
    useSecAddr = wLoc.isusesecaddr( cmd );

    if( wLoc.isconsistcmd( cmd ) ) {
      /* overwrite id and address */
      wLoc.setid(cmd, wLoc.getid(data->props) );
      wLoc.setaddr(cmd, wLoc.getaddr(data->props) );
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "loco %s cmd=\"%s\"", LocOp.getId(inst), wLoc.getcmd(cmd)==NULL?"-":wLoc.getcmd(cmd));
    }

    /* Workarounds for the P50 interface. */
    if( NodeOp.findAttr(cmd,"dir") && wLoc.isdir(cmd) != wLoc.isdir( data->props ) ) {
      /* Informing the P50 interface. */
      wLoc.setsw( cmd, True );
      wLoc.setdir( data->props, wLoc.isdir(cmd) );
      __checkAction(inst, "dirchange", "");
    }
    else if( wLoc.issw( cmd ) ) {
      /* Could be generated by the switch button of the locdlg. */
      wLoc.setdir( cmd, !wLoc.isdir( data->props ) );
      wLoc.setdir( data->props, wLoc.isdir(cmd) );
      __checkAction(inst, "dirchange", "");
    }

    if( NodeOp.findAttr(cmd,"fn") ) {
      wLoc.setfn( data->props, wLoc.isfn( cmd ) );
      if( data->fn0 != wLoc.isfn( cmd ) )
        wFunCmd.setfnchanged(cmd, 0);
      data->fn0 = wLoc.isfn( cmd );
      __checkAction(inst, "lights", "");
    }


    if( StrOp.equals( wFunCmd.name(), NodeOp.getName(cmd )) ) {

      wFunCmd.setaddr(cmd, wLoc.getaddr( data->props ));

      /* The fnchanged attribute is no longer optional and must be set in all cases. */
      fnchanged = wFunCmd.getfnchanged(cmd);

      /* when f0 is turned on, data->fn0 is set true above at informing the P50 interface,
         so if data->fn0 is true and f0changed is true, fn0 is turned on and we must check for the function timer */

      if( fnchanged == 0 ) {
        cmdFn = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
        wLoc.setdir( cmdFn, wLoc.isplacing(data->props) ? wLoc.isdir(data->props):!wLoc.isdir(data->props) );
        wLoc.setfn( cmdFn, wFunCmd.isf0( cmd ) );
        wFunCmd.setf0(cmdFn, wFunCmd.isf0( cmd ) );
        data->fn0 = wFunCmd.isf0( cmd );
        wLoc.setfn( data->props, wFunCmd.isf0( cmd ) );
        wLoc.setfncnt( cmdFn, wLoc.getfncnt( data->props ) );
        wLoc.setid( cmdFn, wLoc.getid(data->props) );
        wLoc.setoid( cmdFn, wLoc.getoid(data->props) );
        wLoc.setaddr( cmdFn, wLoc.getaddr(data->props) );
        wLoc.setiid( cmdFn, wLoc.getiid(data->props) );
        wLoc.setbus( cmdFn, wLoc.getbus(data->props) );
        wLoc.setV( cmdFn, wLoc.getV(data->props) );
        wLoc.setspcnt( cmdFn, wLoc.getspcnt( data->props ) );
        wLoc.setmass( cmdFn, wLoc.getmass( data->props ) );
        wLoc.setV_step( cmdFn, wLoc.getV_step( data->props ) );
        wLoc.setV_min( cmdFn, wLoc.getV_min( data->props ) );
        wLoc.setV_max( cmdFn, wLoc.getV_max( data->props ) );
        wLoc.setV_mode( cmdFn, wLoc.getV_mode( data->props ) );
        wLoc.setprot( cmdFn, wLoc.getprot( data->props ) );
        wLoc.setprotver( cmdFn, wLoc.getprotver( data->props ) );
        wLoc.setfncnt( cmdFn, wLoc.getfncnt( data->props ) );
        wFunCmd.setfnchanged(cmdFn, wFunCmd.getfnchanged(cmd));
      }

      /* function timers */
      if( fnchanged != -1 && fnchanged < 29 ) {
        data->fxtimer[fnchanged] = __getFnTimer( inst, fnchanged);
      }

      if( data->timedfn >= 0 && wFunCmd.gettimedfn( cmd ) >= 0 && wFunCmd.gettimer( cmd ) > 0) {
        /* reset previous timed function */
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "reset previous timed function");
        __resetTimedFunction(inst, cmd, -1);
      }
      if( wFunCmd.gettimedfn( cmd ) >= 0 && wFunCmd.gettimer( cmd ) > 0 ) {
        data->timedfn = wFunCmd.gettimedfn( cmd );
        data->fntimer = wFunCmd.gettimer( cmd );

        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
            "timedfn=%d fntimer=%d fnevent=%s", data->timedfn, data->fntimer, wFunCmd.getevent( cmd ) );

        if( StrOp.equals( wFeedbackEvent.enter_event, wFunCmd.getevent( cmd ) ) )
          data->fnevent = enter_event;
        else if( StrOp.equals( wFeedbackEvent.in_event, wFunCmd.getevent( cmd ) ) )
          data->fnevent = in_event;
        else
          data->fnevent = 0;

        data->fneventblock = StrOp.dup( wFunCmd.geteventblock( cmd ) );

      }

      /* save the function status: */
      Boolean fon = __cpNode2Fn(inst, cmd);
      __saveFxState(inst);

      if( fnchanged != -1 ) {
        char fstr[32] = {'\0'};
        StrOp.fmtb(fstr, "f%d", fnchanged );
        __checkAction(inst, fstr, fon?"":"off");
      }


      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "lc=%s [addr=%d] [fn=%d] lights=%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
          wLoc.getid( data->props ), cmdFn==NULL?wLoc.getaddr( cmd ):wFunCmd.getaddr(cmdFn), fnchanged,
          data->fn0  ? "on":"off",
          data->fn1  ? "01":"--", data->fn2  ? "02":"--", data->fn3  ? "03":"--", data->fn4  ? "04":"--",
          data->fn5  ? "05":"--", data->fn6  ? "06":"--", data->fn7  ? "07":"--", data->fn8  ? "08":"--",
          data->fn9  ? "09":"--", data->fn10 ? "10":"--", data->fn11 ? "11":"--", data->fn12 ? "12":"--",
          data->fn13 ? "13":"--", data->fn14 ? "14":"--", data->fn15 ? "15":"--", data->fn16 ? "16":"--",
          data->fn17 ? "17":"--", data->fn18 ? "18":"--", data->fn19 ? "19":"--", data->fn20 ? "20":"--",
          data->fn21 ? "21":"--", data->fn22 ? "22":"--", data->fn23 ? "23":"--", data->fn24 ? "24":"--",
          data->fn25 ? "25":"--", data->fn26 ? "26":"--", data->fn27 ? "27":"--", data->fn28 ? "28":"--"
      );

      /* secondary decoder check */
      if( wFunCmd.getfnchanged(cmd) != -1 ) {
        int locoAddr = cmdFn==NULL?wLoc.getaddr( cmd ):wFunCmd.getaddr(cmdFn);
        int mappedfn = 0;
        int decaddr = __getFnAddr(inst, wFunCmd.getfnchanged(cmd), &mappedfn );
        if( decaddr > 0 && decaddr!=locoAddr ) {
          int ifn = 0;
          wLoc.setaddr( cmdFn==NULL?cmd:cmdFn, decaddr > 0 ? decaddr:wLoc.getaddr(data->props) );
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
              "function %d address=%d:%d", wFunCmd.getfnchanged(cmd), decaddr, mappedfn );
          /* reset */
          for( ifn = 0; ifn < 29; ifn++ )
            __FnOnOff(inst, ifn, False, cmdFn==NULL?cmd:cmdFn, False);
          __cpFn2Node(inst, cmdFn==NULL?cmd:cmdFn, -1, decaddr);
          wFunCmd.setfnchanged(cmdFn==NULL?cmd:cmdFn, mappedfn);
          wFunCmd.setgroup(cmdFn==NULL?cmd:cmdFn, mappedfn/4 + ((mappedfn%4 > 0) ? 1:0) );
        }
        else {
          /* some controllers use this information because they make no diff between loc or fun cmd: */
          __cpFn2Node(inst, cmd, -1, 0);
        }
      }
      else {
        __cpFn2Node(inst, cmd, -1, 0);
      }

      /* sound */
      __doSound( inst, cmd );

    }
    else {
      /* copy functions */
      __cpFn2Node(inst, cmd, -1, 0);
    }


  }

  else if( !LocOp.isAutomode(inst) || data->gomanual ) {
    if( wLoc.isinfo4throttle(data->props ) ) {
      data->infocheck++;
      if( data->infocheck > 10 ) {
        if( cmd == NULL ) {
          cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
          wLoc.setaddr( cmd, wLoc.getaddr(data->props) );
        }
        wLoc.setcmd( cmd, wLoc.info );
        data->infocheck = 0;
      }
    }
  }



  /* New speed attributes: */
  if( V_hint != NULL ) {
    __checkAction(inst, V_hint, "");
    V_new = __translateVhint( inst, V_hint, V_maxkmh );

    if( data->drvSpeed != V_new || StrOp.equals( wFunCmd.name(), NodeOp.getName(cmd )) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "V_hint: [%s][%d maxkmh] = %d", V_hint, V_maxkmh, V_new );
      data->drvSpeed = V_new;
      wLoc.setV( data->props, V_new);
      wLoc.setV_hint( data->props, V_hint );
      if( cmd == NULL )
        cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
      wLoc.setV( cmd, V_new );
    }
    else {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "ignore cmd because there is no diff \"%s\" == %d", V_hint, V_new );
      if( cmd != NULL) {
        NodeOp.base.del(cmd);
        cmd = NULL;
      }
    }
  }
  else if( V_new != -1 ) {
    data->drvSpeed = V_new;
    wLoc.setV( data->props, V_new);
    if( cmd == NULL )
      cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    wLoc.setV( cmd, V_new );
  }


  /* check for run and stall event */
  if( !wLoc.isrestorespeed(data->props) || data->speedrestoredbythread ) {
    if( V_old != data->drvSpeed ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "check function event (curV=%d drvV=%d)", V_old, data->drvSpeed );
      if( V_old == 0 ) {
        __funEvent(inst, NULL, run_event, 0);
        __checkAction(inst, "run", "");
      }
      if( data->drvSpeed == 0 ) {
        __funEvent(inst, NULL, stall_event, 0);
        __checkAction(inst, "stall", "");
      }
      wLoc.setV(data->props, data->drvSpeed);
    }
  }

  /* Check for simple decoders like "Maerklin Delta": */
  if( StrOp.equals( wLoc.V_mode_percent, wLoc.getV_mode( data->props ) ) &&
      wLoc.getV_step( data->props ) > 0 && !wLoc.isregulated( data->props ) )
  {
    if( data->step >= wLoc.getV_step( data->props ) ) {
      data->step = 0;
      if( data->curSpeed != data->drvSpeed ) {
        if( data->curSpeed < data->drvSpeed ) {
          int dif = data->drvSpeed - data->curSpeed;
          data->curSpeed += (dif > 10 ? 10:dif);
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "V=%d dif=%d", data->curSpeed, dif );
        }
        else if( data->curSpeed > data->drvSpeed ) {
          int dif = data->curSpeed - data->drvSpeed;
          data->curSpeed -= (dif < 10 ? dif:10);
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "V=%d dif=%d", data->curSpeed, dif );
        }
        if( cmd == NULL )
          cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
        wLoc.setV( cmd, data->curSpeed );
      }
    }
    else if( cmd != NULL ) {
      /* Initial speed change. */
      wLoc.setV( cmd, data->curSpeed );
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "Initial V=%d", data->curSpeed );
    }
  }

  else if(wLoc.isregulated(data->props) && data->sbtDecelerate > 0 &&
      (StrOp.equals( wLoc.mode_auto, wLoc.getmode(data->props)) || ! wLoc.isusebbt(data->props) ) )
  {
    if( data->step >= data->sbtInterval ) {
      data->step = 0;
      if( data->curSpeed == 0 && data->drvSpeed )
        data->curSpeed = data->drvSpeed;

      if( data->curSpeed > data->drvSpeed && data->curSpeed > wLoc.getV_min(data->props) && data->drvSpeed > wLoc.getV_min(data->props) ) {
        data->curSpeed -= data->sbtDecelerate;
        if( data->curSpeed < data->drvSpeed )
          data->curSpeed = data->drvSpeed;
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "SBT Vcur=%d Vdrv=%d decelerate=%d", data->curSpeed, data->drvSpeed, data->sbtDecelerate );
        if( cmd == NULL )
          cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
        wLoc.setV( cmd, data->curSpeed );
      }
      else {
        data->curSpeed = data->drvSpeed;
      }
    }
  }

  else {
    if( cmd != NULL ) {
      if( wLoc.getV( cmd ) == -1 )
        data->curSpeed = data->drvSpeed;
      else
        data->curSpeed = wLoc.getV(cmd);
    }
  }

  /* Send the command to the controller with all mandatory attributes: */
  if( cmd != NULL && control != NULL )
  {
    iIBlockBase curblock  = NULL;
    iIBlockBase gotoblock = NULL;
    if( data->curBlock != NULL )
      curblock  = ModelOp.getBlock( AppOp.getModel(), data->curBlock );
    if( data->gotoBlock != NULL )
      gotoblock = ModelOp.getBlock( AppOp.getModel(), data->gotoBlock );

    wLoc.setmass( cmd, wLoc.getmass( data->props ) );
    wLoc.setV_step( cmd, wLoc.getV_step( data->props ) );
    wLoc.setV_min( cmd, wLoc.getV_min( data->props ) );
    wLoc.setV_max( cmd, wLoc.getV_max( data->props ) );
    wLoc.setV_mode( cmd, wLoc.getV_mode( data->props ) );
    wLoc.setbus( cmd, wLoc.getbus( data->props ) );
    wLoc.setprot( cmd, wLoc.getprot( data->props ) );
    wLoc.setprotver( cmd, wLoc.getprotver( data->props ) );
    wLoc.setspcnt( cmd, wLoc.getspcnt( data->props ) );
    wLoc.setfncnt( cmd, wLoc.getfncnt( data->props ) );
    wLoc.setdir( cmd, wLoc.isdir( data->props ) );
    wLoc.setfn( cmd, data->fn0 );
    wLoc.setoid( cmd, wLoc.getoid(data->props) );
    wLoc.setid( cmd, wLoc.getid(data->props) );


    if( wLoc.getV( cmd ) == -1 )
      wLoc.setV( cmd, data->drvSpeed );

    /* Flip direction incase of front to back placing: */
    if( !wLoc.isplacing( data->props ) )
      wLoc.setdir( cmd, wLoc.isdir( cmd )?False:True );

    /* Analog loc: */
    if( StrOp.equals( wLoc.prot_A, wLoc.getprot( data->props ) ) ) {
      /* Track Driver */
      const char* iid = NULL;

      if( curblock != NULL ) {
        curblock->setAnalog( curblock, True );
        iid = curblock->getTDiid( curblock );
        if( iid != NULL )
          wLoc.setiid( cmd, iid );
        wLoc.setaddr( cmd, curblock->getTDaddress( curblock ) );
        wBlock.setport( cmd, curblock->getTDport( curblock ) );
        cmdFn = (iONode)NodeOp.base.clone( cmd );
        NodeOp.setName( cmdFn, wFunCmd.name() );
      }

      if( gotoblock != NULL && !gotoblock->isLinked( gotoblock ) ) {
        gotoblock->setAnalog( gotoblock, True );
        iid = gotoblock->getTDiid( gotoblock );
        cmdTD = (iONode)NodeOp.base.clone( cmd );
        if( iid != NULL )
          wLoc.setiid( cmd, iid );
        wLoc.setaddr( cmd, gotoblock->getTDaddress( gotoblock ) );
        wBlock.setport( cmd, gotoblock->getTDport( gotoblock ) );
      }

    }
    else {
      const char* iid = wLoc.getiid( data->props );
      if( curblock != NULL )
        curblock->setAnalog( curblock, False );
      if( gotoblock != NULL )
        gotoblock->setAnalog( gotoblock, False );

      if( iid != NULL )
        wLoc.setiid( cmd, iid );

      /*wLoc.setaddr( cmd, wLoc.getaddr( data->props ) );*/

      if( curblock != NULL ) {
        wBlock.setport( cmd, curblock->getTDport( curblock ) );
        if( wBlock.istd( curblock->base.properties(curblock) ) ) {
          /* send functions in every block */
          cmdFn = (iONode)NodeOp.base.clone( cmd );
          NodeOp.setName( cmdFn, wFunCmd.name() );
        }
      }

    }

    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "Sending command...V=%d dir=%s secaddr=%s",
        wLoc.getV(cmd), wLoc.isdir(cmd)?"fwd":"rev", wLoc.isusesecaddr(cmd)?"true":"false" );

    if( cmdFn != NULL ) {
      wLoc.setimagenr( cmdFn, wLoc.getimagenr(data->props) );
      if( wLoc.getaddr( cmdFn ) == 0 && !StrOp.equals( wLoc.prot_A, wLoc.getprot( data->props ))) {
        wLoc.setaddr( cmdFn, wLoc.getaddr(data->props) );
      }
      ControlOp.cmd( control, cmdFn, NULL );
    }

    if( wLoc.getaddr( cmd ) == 0 && !StrOp.equals( wLoc.prot_A, wLoc.getprot( data->props ))) {
      wLoc.setaddr( cmd, wLoc.getaddr(data->props) );
    }

    if( useSecAddr && wLoc.getsecaddr(data->props) > 0  && !StrOp.equals( wLoc.prot_A, wLoc.getprot( data->props )) ) {
      wLoc.setaddr( cmd, wLoc.getsecaddr(data->props));
      wLoc.setspcnt( cmd, wLoc.getsecspcnt(data->props));
      wLoc.setV_mode( cmd, wLoc.V_mode_step);
    }
    wLoc.setimagenr( cmd, wLoc.getimagenr(data->props) );
    ControlOp.cmd( control, cmd, NULL );

    if( cmdTD != NULL ) {
      ControlOp.cmd( control, cmdTD, NULL );
    }
  }

  if( wCtrl.isreleaseonidle( AppOp.getIniNode( wCtrl.name() )) ) {
    if( cmd == NULL && wLoc.getV(data->props) == 0 && !data->go && !data->released ) {
      /* Release loco? */
      cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
      wLoc.setaddr(cmd, wLoc.getaddr(data->props));
      wLoc.setfn( cmd, wLoc.isfn(data->props));
      wLoc.setdir(cmd, wLoc.isdir(data->props));
      wLoc.setid(cmd, wLoc.getid(data->props));
      wLoc.setcmd(cmd, wLoc.release );
      ControlOp.cmd( control, cmd, NULL );
      data->released = True;
    }
  }

  data->step++;
  return True;
}


static iONode __resetTimedFunction(iOLoc loc, iONode cmd, int function) {
  iOLocData data = Data(loc);
  iONode fncmd = cmd==NULL?NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE ):cmd;
  int timedfn = data->timedfn;
  int newtimedfn = wFunCmd.gettimedfn( cmd );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "reset timed function %d,%d Lights=%d", timedfn, function, data->fn0 );

  if( function >= 0 ) {
    timedfn = function;
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "function [%d] deactivated", timedfn );
    wFunCmd.settimedfn( cmd, -1 );
  }

  if( timedfn == newtimedfn ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "keep state of function [%d]; is same as new", timedfn );
    timedfn = -1;
  }

  if( function != -1 )
    wFunCmd.setfnchanged( fncmd, function );
  else if( timedfn != -1 )
    wFunCmd.setfnchanged( fncmd, timedfn );

  wFunCmd.setid ( fncmd, wLoc.getid(data->props) );
  wFunCmd.setf0 ( fncmd, timedfn== 0?False:data->fn0 );
  wFunCmd.setf1 ( fncmd, timedfn== 1?False:data->fn1 );
  wFunCmd.setf2 ( fncmd, timedfn== 2?False:data->fn2 );
  wFunCmd.setf3 ( fncmd, timedfn== 3?False:data->fn3 );
  wFunCmd.setf4 ( fncmd, timedfn== 4?False:data->fn4 );
  wFunCmd.setf5 ( fncmd, timedfn== 5?False:data->fn5 );
  wFunCmd.setf6 ( fncmd, timedfn== 6?False:data->fn6 );
  wFunCmd.setf7 ( fncmd, timedfn== 7?False:data->fn7 );
  wFunCmd.setf8 ( fncmd, timedfn== 8?False:data->fn8 );
  wFunCmd.setf9 ( fncmd, timedfn== 9?False:data->fn9 );
  wFunCmd.setf10( fncmd, timedfn==10?False:data->fn10 );
  wFunCmd.setf11( fncmd, timedfn==11?False:data->fn11 );
  wFunCmd.setf12( fncmd, timedfn==12?False:data->fn12 );
  wFunCmd.setf13( fncmd, timedfn==13?False:data->fn13 );
  wFunCmd.setf14( fncmd, timedfn==14?False:data->fn14 );
  wFunCmd.setf15( fncmd, timedfn==15?False:data->fn15 );
  wFunCmd.setf16( fncmd, timedfn==16?False:data->fn16 );
  wFunCmd.setf17( fncmd, timedfn==17?False:data->fn17 );
  wFunCmd.setf18( fncmd, timedfn==18?False:data->fn18 );
  wFunCmd.setf19( fncmd, timedfn==19?False:data->fn19 );
  wFunCmd.setf20( fncmd, timedfn==20?False:data->fn20 );
  wFunCmd.setf21( fncmd, timedfn==21?False:data->fn21 );
  wFunCmd.setf22( fncmd, timedfn==22?False:data->fn22 );
  wFunCmd.setf23( fncmd, timedfn==23?False:data->fn23 );
  wFunCmd.setf24( fncmd, timedfn==24?False:data->fn24 );
  wFunCmd.setf25( fncmd, timedfn==25?False:data->fn25 );
  wFunCmd.setf26( fncmd, timedfn==26?False:data->fn26 );
  wFunCmd.setf27( fncmd, timedfn==27?False:data->fn27 );
  wFunCmd.setf28( fncmd, timedfn==28?False:data->fn28 );
  data->timedfn = -1;

  wFunCmd.setgroup( fncmd, timedfn/4 + ((timedfn%4 > 0) ? 1:0) );

  if( timedfn == 0 )
    wLoc.setfn(data->props, wFunCmd.isf0( fncmd ) );

  return fncmd;
}


#define RUNNERTICK 100
#define RUNNERBBTTICK 10

static iOMsg __getQueueMsg( iOLocData data, iOList list, iOMsg msg) {
  iOMsg qmsg = NULL;
  int size = 0;
  int i = 0;

  /* count down timers */
  size = ListOp.size(list);
  for( i = 0; i < size; i++ ) {
    iOMsg m = (iOMsg)ListOp.get(list, i);
    MsgOp.setTimer( m, MsgOp.getTimer( m ) - RUNNERTICK );
  }

  /* process the new message */
  if( msg != NULL ) {
    if( MsgOp.getTimer( msg ) == 0 )
      return msg;
    else {
      int event = MsgOp.getEvent( msg );
      int type  = MsgOp.getUsrDataType( msg );
      int timer = MsgOp.getTimer( msg );

      if( type == 0 && wLoc.getevttimer(data->props) > 0 ) {
        timer = wLoc.getevttimer(data->props);
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "loc evttimer %d ms", timer );
      }
      else if( event == in_event ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "loc evttimer %d ms * %d %%", timer, wLoc.getent2incorr(data->props) );
        timer = timer * wLoc.getent2incorr(data->props) / 100;
        if( timer < 1 )
          timer = 1;
      }
      else {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "loc evttimer %d ms", timer );
      }
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "timed event[%d] %d ms", event, timer );

      MsgOp.setTimer( msg, timer );

      if( timer < RUNNERTICK ) {
        /* blind for less then 100 ms */
        ThreadOp.sleep(timer);
        return msg;
      }

      ListOp.add(list, (obj)msg);
    }
  }

  /* check timers */
  size = ListOp.size(list);
  for( i = 0; i < size; i++ ) {
    iOMsg m = (iOMsg)ListOp.get(list, i);
    if( MsgOp.getTimer( m ) <= 0 ) {
      ListOp.remove( list, i);
      qmsg = m;
      break;
    }
  }

  return qmsg;
}


static void __theSwap(iOLoc loc, Boolean swap, Boolean consist, iONode cmd) {
  iOLocData data = Data(loc);
  /* The swap: */
  wLoc.setplacing( data->props, swap );
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "placing for [%s] set to [%s]", wLoc.getid(data->props), wLoc.isplacing( data->props )?"FWD":"REV" );
  /* inform model to keep this setting in the occupancy file */
  ModelOp.setBlockOccupancy( AppOp.getModel(), data->curBlock, wLoc.getid(data->props), False, wLoc.isplacing( data->props) ? 1:2, wLoc.isblockenterside( data->props) ? 1:2, NULL );

  /* swap the block enter side flag to be able to use other direction routes */
  LocOp.swapBlockEnterSide(loc, NULL);

  if( !consist ) {
    /* only swap if this command did not come from a multiple unit loop */
    __swapConsist(loc, cmd);
  }

  if( wLoc.isv0onswap(data->props) && LocOp.getV(loc) == 0 ) {
    iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    wLoc.setcmd(cmd, wLoc.velocity );
    wLoc.setV(cmd, 0 );
    wLoc.setfn( cmd, data->fn0 );
    wLoc.setdir( cmd, wLoc.isdir(data->props) );
    LocOp.cmd(loc, cmd);
  }
  __broadcastLocoProps( loc, NULL, NULL, NULL );
  __checkAction(loc, "dirchange", "");

}


static void _resetBBT(iOLoc loc) {
  iOLocData data = Data(loc);
  data->bbtEnterBlock = NULL;
  data->bbtInBlock    = NULL;
  data->bbtPrevBlock  = NULL;
  data->bbtRoute      = NULL;
  data->bbtEnterSpeed = 0;
  data->bbtCycleSpeed = 0;
  data->bbtEnter      = 0;
  data->bbtIn         = 0;
  data->bbtAtMinSpeed = False;
  data->bbtGenerateIn = False;
  data->bbtStepCount  = 0;
  data->bbtAtMin      = 0;
}

/**
 * Block Brake Timer
 */
static void __BBT(iOLoc loc) {
  iOLocData data = Data(loc);
  int bbtsteps      = wLoc.getbbtsteps(data->props);
  int bbtmaxdiff    = wLoc.getbbtmaxdiff(data->props);
  int bbtcorrection = wLoc.getbbtcorrection(data->props);

  if( data->bbtDelay > 0 ) {
    data->bbtDelay--;
    return;
  }

  if( bbtsteps < 4 || bbtsteps > 16 )
    bbtsteps = 10;
  if( bbtmaxdiff < 100 || bbtmaxdiff > 500 )
    bbtmaxdiff = 250;
  if( bbtcorrection < 10 || bbtcorrection > 100 )
    bbtcorrection = 25;

  bbtcorrection = 100 / bbtcorrection;

  if( data->bbtEnter != 0 && data->bbtIn == 0  && data->bbtEnterBlock != NULL ) {
    if( data->bbtInTimer > 0 ) {
      data->bbtInTimer--;
      if( data->bbtInTimer == 0 ) {
        data->bbtIn = SystemOp.getTick();
        data->bbtInBlock = data->bbtEnterBlock;
        data->bbtPrevBlock = data->driver->getCurblock(data->driver);
        data->bbtRoute = data->driver->getCurroute(data->driver);
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "BBT in=%ld block=%s", data->bbtIn, data->bbtInBlock );
      }
    }

    if( data->bbtCycleSpeed == 0 ) {
      const char* key  = NULL;
      char* key0 = NULL;
      char* keyV = NULL;
      iONode bbt  = NULL;
      iONode bbtV = NULL;
      int bbtkey = wLoc.getbbtkey(data->props);
      data->bbtPrevBlock = data->driver->getCurblock(data->driver);
      data->bbtRoute = data->driver->getCurroute(data->driver);
      if( bbtkey == 3) {
        key0 = StrOp.fmt("%s-%d", data->bbtEnterBlock, data->bbtEnterSpeed);
        keyV = StrOp.fmt("%s-%d", data->bbtEnterBlock, data->bbtEnterSpeed);
      }
      else if( bbtkey == 2 && data->bbtRoute != NULL) {
        key0 = StrOp.fmt("%s-%s", data->bbtEnterBlock, data->bbtRoute);
        keyV = StrOp.fmt("%s-%s-%d", data->bbtEnterBlock, data->bbtRoute, data->bbtEnterSpeed);
      }
      else if( bbtkey == 1 ) {
        key0 = StrOp.fmt("%s-%s", data->bbtEnterBlock, data->bbtPrevBlock);
        keyV = StrOp.fmt("%s-%s-%d", data->bbtEnterBlock, data->bbtPrevBlock, data->bbtEnterSpeed);
      }
      else {
        key0 = StrOp.fmt("%s", data->bbtEnterBlock);
        keyV = StrOp.fmt("%s-%d", data->bbtEnterBlock, data->bbtEnterSpeed);
      }

      bbt  = (iONode)MapOp.get( data->bbtMap, key0 );
      bbtV = (iONode)MapOp.get( data->bbtMap, keyV );

      if( bbtV != NULL ) {
        bbt = bbtV;
        key = keyV;
      }
      else {
        key = key0;
      }

      data->bbtCycleNr = 0;
      if( bbt != NULL ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "BBT-Record found: [%s] keytype=%d", key, bbtkey);
        data->bbtInterval = wBBT.getinterval(bbt) / bbtsteps;
        data->bbtGenerateIn = wBBT.isgeneratein(bbt);
        data->bbtDelay = wBBT.getdelay(bbt);
        if( wBBT.getinterval(bbt) % bbtsteps > 5 )
          data->bbtInterval++;
        wBBT.setsteps(bbt, 0 );
      }
      else {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "BBT-Record **not** found: [%s]", key);
        data->bbtInterval = wLoc.getbbtstartinterval(data->props);
      }
      StrOp.free(key0);
      StrOp.free(keyV);
      data->bbtSpeed = data->drvSpeed;
      data->curSpeed = data->drvSpeed;
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "BBT-ENTER interval=%d block=%s V_enter=%d",
          bbt != NULL ? wBBT.getinterval(bbt):100, data->bbtEnterBlock, data->bbtSpeed );
    }

    if( data->bbtInterval == 0 )
      data->bbtInterval = 10;

    if( data->drvSpeed > 0 && !data->bbtAtMinSpeed && data->bbtCycleSpeed >= 0 && (data->bbtCycleSpeed % data->bbtInterval) == 0 ) {
      iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
      int V_min = wLoc.getV_min( data->props );
      int speed = 0;
      data->bbtCycleNr++;
      /* Subtract the Min. speed from the calculation. */
      speed = data->bbtSpeed - (((data->bbtSpeed-V_min) * data->bbtCycleNr) / bbtsteps );
      if( speed <= V_min ) {
        speed = V_min;
        data->bbtAtMinSpeed = True;
        data->bbtAtMin = SystemOp.getTick();
        wLoc.setV_hint( data->props, wLoc.min );
      }
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "BBT-SPEED V=%d id=%s mode=%s atminspeed=%d",
          speed, wLoc.getid(data->props), wLoc.getmode(data->props), data->bbtAtMinSpeed  );

      data->curSpeed = speed;
      wLoc.setV( cmd, speed );
      wLoc.setdir( cmd, wLoc.isdir( data->props ) );
      LocOp.cmd( loc, cmd );
      data->bbtStepCount++;
    }
    data->bbtCycleSpeed++;
  }
  else if( data->bbtEnter != 0 && data->bbtIn == 0  && data->bbtEnterBlock == NULL ) {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "BBT-ENTER **block not set**" );
    data->bbtCycleSpeed = 0;
    data->bbtEnter      = 0;
    data->bbtIn         = 0;
    data->bbtAtMinSpeed = False;
  }

  if(data->bbtGenerateIn && data->bbtAtMinSpeed) {
    iIBlockBase block = ModelOp.getBlock( AppOp.getModel(), data->bbtEnterBlock );
    if( block != NULL ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "BBT-GENERATE-IN id=%s block=%s", wLoc.getid(data->props), data->bbtEnterBlock );
      LocOp.event(loc, (obj)block, in_event, 0, False, "BBT-IN-Event" );
    }
    else {
      TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999,
          "BBT-GENERATE-IN id=%s: Block [%s] does not exist; Stop loco", wLoc.getid(data->props), data->bbtEnterBlock );
      iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
      data->curSpeed = 0;
      wLoc.setV( cmd, 0 );
      wLoc.setdir( cmd, wLoc.isdir( data->props ) );
      LocOp.cmd( loc, cmd );
    }
  }

  if( data->bbtEnter != 0 && data->bbtIn != 0 && data->bbtEnterBlock != NULL && data->bbtInBlock != NULL ) {
    /*data->prevBlock*/
    int bbtkey = wLoc.getbbtkey(data->props);
    char* key  = NULL;
    char* keyV = NULL;
    if( bbtkey == 3 ) {
      key  = StrOp.fmt("%s-%d", data->bbtInBlock, data->bbtEnterSpeed);
      keyV = StrOp.fmt("%s-%d", data->bbtInBlock, data->bbtEnterSpeed);
    }
    else if( bbtkey == 2 && data->bbtRoute != NULL ) {
      key  = StrOp.fmt("%s-%s", data->bbtInBlock, data->bbtRoute);
      keyV = StrOp.fmt("%s-%s-%d", data->bbtInBlock, data->bbtRoute, data->bbtEnterSpeed);
    }
    else if( bbtkey == 1 ) {
      key  = StrOp.fmt("%s-%s", data->bbtInBlock, data->bbtPrevBlock);
      keyV = StrOp.fmt("%s-%s-%d", data->bbtInBlock, data->bbtPrevBlock, data->bbtEnterSpeed);
    }
    else {
      key  = StrOp.fmt("%s", data->bbtInBlock);
      keyV = StrOp.fmt("%s-%d", data->bbtInBlock, data->bbtEnterSpeed);
    }

    iONode bbt  = (iONode)MapOp.get( data->bbtMap, key );
    iONode bbtV = (iONode)MapOp.get( data->bbtMap, keyV );

    if( data->bbtIn >= data->bbtEnter && StrOp.equals(data->bbtEnterBlock, data->bbtInBlock) ) {
      Boolean newBBTRecord = False;
      int interval = (int)(data->bbtIn - data->bbtEnter);

      if( bbtV != NULL ) {
        bbt = bbtV;
      }
      else if( bbtV == NULL && bbt != NULL && wBBT.getspeed(bbt) == 0 ) {
        wBBT.setspeed(bbt, data->bbtEnterSpeed);
        MapOp.put(data->bbtMap, keyV, (obj)bbt);
      }

      if( bbt == NULL ) {
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "BBT creating node for block=%s from=%s route=%s with key=[%s] keytype=%d",
            data->bbtInBlock, data->bbtPrevBlock, data->bbtRoute!=NULL?data->bbtRoute:"", key, bbtkey );
        bbt = NodeOp.inst( wBBT.name(), data->props, ELEMENT_NODE );
        NodeOp.addChild(data->props, bbt);
        wBBT.setbk(bbt, data->bbtInBlock);
        wBBT.setfrombk(bbt, data->bbtPrevBlock);
        wBBT.setroute(bbt, data->bbtRoute);
        wBBT.setinterval(bbt, data->bbtInterval * data->bbtCycleNr);
        wBBT.setsteps(bbt, data->bbtCycleNr);
        wBBT.setspeed(bbt, data->bbtEnterSpeed);
        MapOp.put(data->bbtMap, key, (obj)bbt);
        MapOp.put(data->bbtMap, keyV, (obj)bbt);
        newBBTRecord = True;
      }

      int count        = wBBT.getcount(bbt);
      int oldinterval  = wBBT.getinterval(bbt);
      int diffinterval = abs(interval - oldinterval);

      if( diffinterval > bbtmaxdiff ) {
        diffinterval = bbtmaxdiff;
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "BBT interval difference %d exeeds the max. of %d", diffinterval, bbtmaxdiff );
      }

      if( newBBTRecord ) {
        bbtcorrection = 1.0;
      }

      if( interval > oldinterval ) {
        interval = oldinterval + (diffinterval / bbtcorrection);
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "BBT L-interval %d", interval );
      }
      else if( interval < oldinterval ) {
        interval = oldinterval - (diffinterval / bbtcorrection);
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "BBT S-interval %d", interval );
      }

      if( !wBBT.isfixed(bbt) )
        wBBT.setinterval(bbt, interval);

      wBBT.setcount(bbt, wBBT.getcount(bbt) + 1 );
      if( data->bbtCycleNr > 0 )
        wBBT.setsteps(bbt, data->bbtStepCount );

      {
        iONode broadcast = (iONode)NodeOp.base.clone(data->props);
        wLoc.setV( broadcast, data->drvSpeed );
        wLoc.setbbtevent(broadcast, True);
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "BBT-IN interval=%d block=%s bbtcorrection=%d count=%d (broadcast)",
            interval, data->bbtInBlock, bbtcorrection, wBBT.getcount(bbt) );
        AppOp.broadcastEvent( broadcast );
      }

    }
    else {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
          "BBT-IN interval error in=%d enter=%d enterBlock=%s inBlock=%s",
          data->bbtIn, data->bbtEnter,
          data->bbtEnterBlock != NULL ? data->bbtEnterBlock:"?", data->bbtInBlock != NULL ? data->bbtInBlock:"?" );
    }

    StrOp.free(key);
    StrOp.free(keyV);

    data->bbtEnterBlock = NULL;
    data->bbtInBlock    = NULL;
    data->bbtPrevBlock  = NULL;
    data->bbtRoute      = NULL;
    data->bbtEnterSpeed = 0;
    data->bbtCycleSpeed = 0;
    data->bbtEnter      = 0;
    data->bbtIn         = 0;
    data->bbtAtMinSpeed = False;
    data->bbtGenerateIn = False;
    data->bbtStepCount  = 0;
    data->bbtAtMin      = 0;
  }
  else if( data->bbtIn != 0 && data->bbtInBlock == NULL ) {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "BBT-IN **block not set**" );
    data->bbtCycleSpeed = 0;
    data->bbtEnter      = 0;
    data->bbtIn         = 0;
    data->bbtAtMin      = 0;
    data->bbtAtMinSpeed = False;
    data->bbtGenerateIn = False;
    data->bbtStepCount  = 0;
  }
}


static void __runner( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  iOLoc loc = (iOLoc)ThreadOp.getParm( th );
  iOLocData data = Data(loc);
  iOList queueList = ListOp.inst();
  int   tick = 0;
  int   virtualtick = 0;
  int extraTick = 0;
  int delay = 0;
  Boolean cnfgsend = False;
  Boolean loccnfg = wCtrl.isloccnfg( AppOp.getIniNode( wCtrl.name() ) );

  ThreadOp.sleep(500);
  ThreadOp.setDescription( th, wLoc.getdesc( data->props ) );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Runner for \"%s\" started.", LocOp.getId( loc ) );
  data->running = True;

  data->speedstep = wLoc.getV_step( data->props );

  data->runtime = wLoc.getruntime( data->props );

  if( wLoc.getstartuptourid(data->props) != NULL && StrOp.len(wLoc.getstartuptourid(data->props)) > 0 ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "startup tour: %s", wLoc.getstartuptourid(data->props) );
    LocOp.useTour( loc, wLoc.getstartuptourid(data->props) );
  }
  else if( wLoc.getstartupscid(data->props) != NULL && StrOp.len(wLoc.getstartupscid(data->props)) > 0 ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "startup schedule: %s", wLoc.getstartupscid(data->props) );
    LocOp.useSchedule( loc, wLoc.getstartupscid(data->props) );
  }

  do {
    iOMsg  msg       = NULL;
    obj    emitter   = NULL;
    iONode fncmd     = NULL;
    iONode broadcast = NULL;

    int   i     = 0;
    int   event = -1;
    int   timer = 0;
    int   type  = 0;
    int   fx    = 0;
    obj   udata = NULL;

    /* BBT 10ms cycle */
    if( !data->gomanual && wLoc.isusebbt(data->props) && data->drvSpeed > 0 && data->bbtEnterBlock != NULL) {
      if( StrOp.equals( wLoc.mode_wait, wLoc.getmode(data->props) )  && !data->bbtExternalStop ) {
        __BBT(loc);
      }
      ThreadOp.sleep( RUNNERBBTTICK );
      data->bbtCycle++;
      if( data->bbtCycle < 10 ) {
        continue;
      }
      data->bbtCycle = 0;
    }

    /* Normal 100ms cycle */
    msg = __getQueueMsg(data, queueList, (iOMsg)ThreadOp.getPost( th ) );

    data->nrruns++;

    if( msg != NULL ) {
      emitter = MsgOp.getSender( msg );
      event   = MsgOp.getEvent( msg );
      type    = MsgOp.getUsrDataType( msg );
      udata   = MsgOp.getUsrData(msg);
      msg->base.del( msg );
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "new message %d nrruns=%d", event, data->nrruns );
    }

    if( event == cmd_event ) {
      event = -1;
      iONode cmd = (iONode)udata;
      if( !MutexOp.trywait( data->muxEngine, 1000) ) {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "loco %s engine blocked...", LocOp.getId( loc ) );
      }
      else {
        iONode consistCmd = (iONode)NodeOp.base.clone(cmd);
        __engine( loc, cmd );
        MutexOp.post( data->muxEngine);
        __checkConsist(loc, consistCmd, False);
        __broadcastLocoProps( loc, NULL, consistCmd, NULL );
      }
    }

    if( data->driver != NULL ) {
      if( event == swap_event ) {
        iONode  cmd     = (iONode)udata;
        Boolean swap    = (type & 0x01 ? True:False);
        Boolean consist = (type & 0x02 ? True:False);
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "swap event" );
        __theSwap(loc, swap, consist, cmd);
      }
      else {
        if( event != -1 ) {
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "inform the driver of event=%d nrruns=%d", event, data->nrruns );
        }
        data->driver->drive( data->driver, emitter, event );
      }
    }

    if( ThreadOp.hasPost( th ) ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "more messages available..." );
      if( data->gomanual || !wLoc.isusebbt(data->props) || data->drvSpeed == 0 || data->bbtEnterBlock == NULL) {
        if( extraTick < 9 ) {
          ThreadOp.sleep( RUNNERBBTTICK );
          extraTick++;
          continue;
        }
      }
    }


    if( !cnfgsend && loccnfg ) {
      iOControl control = AppOp.getControl();
      if( control != NULL ) {
        iONode cmd = NodeOp.inst( wSysCmd.name(), NULL, ELEMENT_NODE );
        const char* prot = wLoc.getprot(data->props);
        int protver = wLoc.getprotver(data->props);
        wSysCmd.setcmd( cmd, wSysCmd.loccnfg );
        wSysCmd.setid( cmd, wLoc.getid(data->props) );

        /* supply object ID: */
        if( wLoc.getoid(data->props) != NULL )
          wSysCmd.setoid( cmd, wLoc.getoid(data->props) );

        wSysCmd.setval( cmd, wLoc.getaddr(data->props) );
        if( prot[0] == wLoc.prot_M[0] && protver == 1)
          wSysCmd.setvalA( cmd, 0 );
        else if( prot[0] == wLoc.prot_M[0] && protver == 2)
          wSysCmd.setvalA( cmd, 1 );
        else
          wSysCmd.setvalA( cmd, 2 );
        wSysCmd.setvalB( cmd, wLoc.getspcnt(data->props) );
        ControlOp.cmd( control, cmd, NULL );
        cnfgsend = True;
      }
    }

    /* this is approximately a second */
    if( tick % 10 == 0 && tick != 0 ) {
      if( data->drvSpeed > 0 || (!data->go && wLoc.getV(data->props) > 0) ) {
        if( !data->govirtual ) {
          data->runtime++;
          wLoc.setruntime( data->props, data->runtime );
        }
      }
      tick = 0;

      if( StrOp.equals( wLoc.mode_auto, wLoc.getmode(data->props) ) ) {
        if( data->govirtual && data->driver != NULL ) {
          virtualtick++;
          if( virtualtick >= wCtrl.getvirtualtimer( AppOp.getIniNode( wCtrl.name() ) ) ) {
            virtualtick = 0;
            if( !data->driver->stepvirtual(data->driver) ) {
              /* Block type not supported. */
              iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
              wLoc.setid( cmd, LocOp.getId(loc) );
              wLoc.setcmd( cmd, wLoc.stop );
              LocOp.cmd( loc, cmd );
            }
          }
        }
      }
    }


    fx = wLoc.getfx( data->props );
    for( i = 0; i < 28; i++ ) {
      if( ( i == 0 && data->fn0 && data->fxtimer[i] > 0 ) || ( i > 0 && (fx & (1 << (i-1))) && data->fxtimer[i] > 0 ) ) {
        data->fxtimer[i]--;
        if( data->fxtimer[i] == 0 ) {
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "reset timed function %d", i);
          fncmd = __resetTimedFunction(loc, NULL, i);
          break;
        }
      }
    }

    if( fncmd == NULL && data->timedfn >= 0 && data->fntimer >= 0 ) {
      data->fntimer--;
      if( data->fntimer == 0 ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "reset timed function %d", data->timedfn);
        fncmd = __resetTimedFunction(loc, NULL, -1);
      }
    }


    if( fncmd != NULL ) {
      wLoc.setV( fncmd, -1 );
      broadcast = (iONode)NodeOp.base.clone(fncmd);
      if( !MutexOp.trywait( data->muxEngine, 1000) ) {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "loco %s engine blocked...", LocOp.getId( loc ) );
        NodeOp.base.del(fncmd);
      }
      else {
        __engine( loc, fncmd );
        MutexOp.post(data->muxEngine);
      }

      /* Broadcast to clients. */
      __broadcastLocoProps( loc, NULL, broadcast, NULL );
    }
    else {
      /* call this function for updating velocity for unmanaged decoders */
      if( !MutexOp.trywait( data->muxEngine, 1000) ) {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "loco %s engine blocked...", LocOp.getId( loc ) );
      }
      else {
        __engine( loc, NULL );
        MutexOp.post( data->muxEngine);
      }
    }

    if( data->gomanual || !wLoc.isusebbt(data->props) || data->drvSpeed == 0 || data->bbtEnterBlock == NULL) {
      ThreadOp.sleep( RUNNERTICK - extraTick * RUNNERBBTTICK);
    }
    extraTick = 0;
    tick++;

  } while( data->run && !ThreadOp.isQuit(th) );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Runner for \"%s\" ended.", LocOp.getId( loc ) );
  data->running = False;
}



static void __funEvent( iOLoc inst, const char* blockid, int evt, int timer ) {
  iOLocData data = Data(inst);

  iONode fundef = wLoc.getfundef( data->props );

  while( fundef != NULL ) {
    const char* onevent = wFunDef.getonevent( fundef );
    const char* offevent = wFunDef.getoffevent( fundef );
    int fn = wFunDef.getfn( fundef );
    iOStrTok  onblocks = StrTokOp.inst( wFunDef.getonblockid ( fundef ), ',' );
    iOStrTok offblocks = StrTokOp.inst( wFunDef.getoffblockid( fundef ), ',' );
    Boolean  isonevent = False;
    Boolean isoffevent = False;

    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "checking event for function \"%s\"", wFunDef.gettext(fundef) );

    if( blockid != NULL ) {
      while( StrTokOp.hasMoreTokens( onblocks ) ) {
        const char* tok = StrTokOp.nextToken( onblocks );
        if( StrOp.equals( blockid, tok ) ) {
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "ON Event %d from \"%s\"", evt, blockid );
          isonevent = True;
          break;
        }
      };
      while( StrTokOp.hasMoreTokens( offblocks ) ) {
        const char* tok = StrTokOp.nextToken( offblocks );
        if( StrOp.equals( blockid, tok ) ) {
          TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 99949, "OFF Event %d from \"%s\"", evt, blockid );
          isoffevent = True;
          break;
        }
      };
    }
    else {
      isonevent = True;
      isoffevent = True;
    }

    if( isonevent ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "onevent[%s] evt[%d]", onevent, evt );
      if( (StrOp.equals( wFunDef.enter_block, onevent ) && evt == enter_event) ||
          (StrOp.equals( wFunDef.in_block   , onevent ) && evt == in_event)    ||
          (StrOp.equals( wFunDef.exit_block , onevent ) && evt == exit_event)  ||
          (StrOp.equals( wFunDef.run        , onevent ) && evt == run_event)
         ) {
        iONode cmd = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE );
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "On Event for funcion %d.", fn );
        wFunCmd.setid( cmd, LocOp.getId( inst ) );
        __cpFn2Node(inst, cmd, -1, 0);
        __FnOnOff(inst, fn, True, cmd, True);
        LocOp.cmd( inst, cmd );
      }
    }

    if( isoffevent ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "offevent[%s] evt[%d]", offevent, evt );
      if( (StrOp.equals( wFunDef.enter_block, offevent ) && evt == enter_event) ||
          (StrOp.equals( wFunDef.in_block   , offevent ) && evt == in_event)    ||
          (StrOp.equals( wFunDef.exit_block , offevent ) && evt == exit_event)  ||
          (StrOp.equals( wFunDef.stall      , offevent ) && evt == stall_event)
         ) {
        iONode cmd = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE );
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Off Event for funcion %d.", fn );
        wFunCmd.setid( cmd, LocOp.getId( inst ) );
        __cpFn2Node(inst, cmd, -1, 0);
        __FnOnOff(inst, fn, False, cmd, True);
        LocOp.cmd( inst, cmd );
      }
    }

    /* Cleanup */
    StrTokOp.base.del( onblocks );
    StrTokOp.base.del( offblocks );

    fundef = wLoc.nextfundef( data->props, fundef );
  }

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "timedfn=%d fnevent=%d fnblock=%s evt=%d",
      data->timedfn, data->fnevent, data->fneventblock, evt );
  if( data->timedfn >= 0 && data->fnevent > 0 && data->fneventblock != NULL ) {
    if( blockid != NULL && StrOp.equals(data->fneventblock, blockid)) {
      if( data->fnevent == evt || data->fnevent == evt ) {
        iONode cmd = NodeOp.inst( wFunCmd.name(), NULL, ELEMENT_NODE );
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Off Event for funcion %d.", data->timedfn );
        wFunCmd.setid( cmd, LocOp.getId( inst ) );
        __cpFn2Node(inst, cmd, -1, 0);
        __FnOnOff(inst, data->timedfn, False, cmd, True);
        LocOp.cmd( inst, cmd );
        StrOp.free( data->fneventblock );
        data->fneventblock = NULL;
        data->fnevent = 0;
      }
    }
  }
}

static void _event( iOLoc inst, obj emitter, int evt, int timer, Boolean forcewait, const char* id ) {
  iOLocData data = Data(inst);
  iOMsg msg = MsgOp.inst( emitter, evt );
  iIBlockBase block = (iIBlockBase)MsgOp.getSender(msg);
  const char* blockid = block!=NULL ? block->base.id( block ):"?";

  data->curSensor = id;

  if( emitter == (obj)data->driver ) {
    __checkAction(inst, id, "");
    return;
  }

  if( id != NULL && StrOp.len(id) > 0 && StrOp.equals("eventtimeout", id) ) {
    __checkAction(inst, "eventtimeout", "" );
  }

  if( evt == enter_event && block != NULL && !StrOp.equals(blockid, data->sbtEnterBlock) ) {
    iONode sbt = NULL;
    char* key = NULL;

    data->sbtEnterBlock = blockid;
    /* default SBT */
    data->sbtInterval   = wLoc.getV_step(data->props);
    data->sbtDecelerate = wLoc.getdecelerate(data->props);

    /* block/train related SBT */
    if( LocOp.getTrain(inst) != NULL && StrOp.len(LocOp.getTrain(inst)) > 0 ) {
      key = StrOp.fmt("%s-%s", blockid, LocOp.getTrain(inst));
      if( MapOp.haskey(data->sbtMap, key ) ) {
        sbt = (iONode)MapOp.get(data->sbtMap, key);
      }
    }

    /* block related SBT */
    if( sbt == NULL ) {
      key = StrOp.fmt("%s", blockid);
      if( MapOp.haskey(data->sbtMap, key ) ) {
        sbt = (iONode)MapOp.get(data->sbtMap, blockid);
      }
    }

    if( sbt != NULL ) {
      data->sbtInterval   = wSBT.getinterval(sbt);
      data->sbtDecelerate = wSBT.getdecelerate(sbt);
    }

    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "SBT enter block=%s interval=%d decelerate=%d key=%s train=%s",
        data->sbtEnterBlock, data->sbtInterval, data->sbtDecelerate, key, LocOp.getTrain(inst) );
    StrOp.free(key);
  }

  /* BBT timers */
  data->bbtExternalStop = block->hasExtStop(block, NULL);
  if( wLoc.isusebbt(data->props) && block != NULL && block->allowBBT(block) && !block->hasExtStop(block, NULL) ) {
    if( evt == enter_event && (data->bbtEnter == 0 || !StrOp.equals(blockid, data->bbtEnterBlock) ) ) {
      data->bbtEnterBlock = blockid;
      data->bbtInBlock    = NULL;
      data->bbtIn         = 0;
      data->bbtAtMin      = 0;
      data->bbtCycleSpeed = 0;
      data->bbtInTimer    = 0;
      data->bbtStepCount  = 0;
      data->bbtAtMinSpeed = False;
      data->bbtAtMin      = 0;
      data->bbtEnter      = SystemOp.getTick();
      data->bbtEnterSpeed = wLoc.getV( data->props );
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "BBT enter=%ld block=%s", data->bbtEnter, data->bbtEnterBlock );
    }
    else if( evt == pre2in_event && wLoc.isinatpre2in(data->props) && data->bbtIn == 0 && data->bbtEnter > 0 ) {
      data->bbtInBlock = blockid;
      data->bbtIn = SystemOp.getTick();
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "BBT pre2in=%ld block=%s", data->bbtIn, data->bbtInBlock );
    }
    else if( (evt == in_event || (evt == shortin_event && wLoc.isshortin(data->props) ) ) && data->bbtIn == 0 && data->bbtEnter > 0 && StrOp.equals(blockid, data->bbtEnterBlock) ) {
      if( timer == 0 ) {
        data->bbtInBlock = blockid;
        data->bbtIn = SystemOp.getTick();
        TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "BBT in=%ld block=%s", data->bbtIn, data->bbtInBlock );
      }
      else {
        data->bbtInTimer = timer / 10;
        if( data->bbtInTimer == 0 )
          data->bbtInTimer++;
      }
    }
  }
  else if(evt == enter_event && block != NULL && !block->allowBBT(block) ) {
    /* reset BBT */
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "BBT block=%s does not allow BBT", blockid );
    LocOp.resetBBT(inst);
  }

  if( data->runner != NULL ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
        "event %d from [%s], timer=%d, forcewait=%d nrruns=%d", evt, blockid, timer, forcewait, data->nrruns );
    MsgOp.setTimer( msg, timer );
    MsgOp.setUsrData( msg, NULL, forcewait ? 1000:0 );
    ThreadOp.post( data->runner, (obj)msg );
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "event posted");
    __funEvent(inst, blockid, evt, timer);
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "fun events checked");
  }
}


/*
 ***** _Public functions.
 */
static const char* _getId( iOLoc inst ) {
  iOLocData data = Data(inst);
  return wLoc.getid( data->props );
}

static const char* _getEngine( iOLoc inst ) {
  iOLocData data = Data(inst);
  return wLoc.getengine( data->props );
}


static const char* _getTrain( iOLoc inst ) {
  iOLocData data = Data(inst);
  return wLoc.gettrain(data->props);
}


static void _adjustAccel(iOLoc inst, int p_Accel, int weight) {
  iOLocData data = Data(inst);
  iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
  int accel = p_Accel;

  if( accel == -1 ) {
    float maxload = wLoc.getmaxload(data->props);
    int accelmin = wLoc.getaccelmin(data->props);
    int accelmax = wLoc.getaccelmax(data->props);
    if( weight > 0 && maxload > 0 && accelmin > 0 && accelmax > 0 ) {
      float faccel = accelmax - accelmin;
      faccel /= maxload;
      faccel *= weight;
      faccel += accelmin;
      accel = (int)faccel;
    }
    else {
      accel = accelmin;
    }
  }

  wProgram.setcmd( cmd, wProgram.set );
  wProgram.setiid( cmd, wLoc.getiid(data->props) );
  wProgram.setaddr( cmd, wLoc.getaddr(data->props) );
  wProgram.setlongaddr( cmd, (wLoc.getaddr(data->props) > 127) ? True:False );
  wProgram.setdecaddr( cmd, wLoc.getaddr(data->props) );
  wProgram.setcv( cmd, 3 );
  wProgram.setvalue( cmd, accel );
  wProgram.setpom( cmd, True );

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "loco [%s] adjust acceleration: CV3=%d",
      wLoc.getid(data->props), (int)accel );
  ControlOp.cmd( AppOp.getControl(), cmd, NULL );


  if( wLoc.getconsist(data->props) != NULL && StrOp.len(wLoc.getconsist(data->props)) > 0) {
    iOStrTok  consist = StrTokOp.inst( wLoc.getconsist ( data->props ), ',' );
    while( StrTokOp.hasMoreTokens( consist ) ) {
      const char* tok = StrTokOp.nextToken( consist );
      iOLoc consistloc = ModelOp.getLoc( AppOp.getModel(), tok, NULL, False );
      if( consistloc != NULL ) {
        if( wLoc.isadjustaccel(LocOp.base.properties(consistloc)) && weight != -1 ) {
          LocOp.adjustAccel(consistloc, -1, weight);
        }
      }
    }
    StrTokOp.base.del( consist );
  }

}


static void __setCurBlock4Train(iOLoc inst, const char* id) {
  iOLocData data = Data(inst);
  if( wLoc.gettrain( data->props) != NULL && StrOp.len(wLoc.gettrain( data->props)) > 0 ) {
    iOOperator train = ModelOp.getOperator(AppOp.getModel(), wLoc.gettrain( data->props) );
    if( train != NULL ) {
      OperatorOp.setLocality(train, id);
    }
  }
}


static Boolean __matchTrainIdent(iOLoc inst, const char* ident1, const char* ident2, const char* ident3, const char* ident4 ) {
  iOLocData data = Data(inst);
  Boolean match = False;

  if( wLoc.gettrain( data->props) != NULL && StrOp.len(wLoc.gettrain( data->props)) > 0 ) {
    iOOperator train = ModelOp.getOperator(AppOp.getModel(), wLoc.gettrain( data->props) );
    if( train != NULL ) {
      match = OperatorOp.matchIdent(train, ident1, ident2, ident3, ident4 );
    }
  }
  return match;
}


static void __calcTrainLen(iOLoc inst, Boolean adjust) {
  iOLocData data = Data(inst);
  Boolean report = False;
  int weight = -1;

  wLoc.settrainlen( data->props, wLoc.getlen(data->props));

  /* calculate train length */
  if( wLoc.gettrain( data->props) != NULL && StrOp.len(wLoc.gettrain( data->props)) > 0 ) {
    iOOperator train = ModelOp.getOperator(AppOp.getModel(), wLoc.gettrain( data->props) );
    if( train != NULL ) {
      wLoc.settrainlen( data->props, OperatorOp.getLen(train, &weight) + wLoc.getlen(data->props));
      wLoc.settrainweight( data->props, weight );
      report = True;

      if( wLoc.isadjustaccel(data->props) && adjust) {
        LocOp.adjustAccel(inst, -1, weight);
      }
    }
  }

  /* add consist locos */
  if( wLoc.getconsist(data->props) != NULL && StrOp.len(wLoc.getconsist(data->props)) > 0) {
    iOStrTok  consist = StrTokOp.inst( wLoc.getconsist ( data->props ), ',' );
    while( StrTokOp.hasMoreTokens( consist ) ) {
      const char* tok = StrTokOp.nextToken( consist );
      iOLoc consistloc = ModelOp.getLoc( AppOp.getModel(), tok, NULL, False );
      if( consistloc != NULL ) {
        wLoc.settrainlen( data->props, wLoc.gettrainlen(data->props) + LocOp.getLen(consistloc));
        report = True;
      }
    }
    StrTokOp.base.del( consist );
  }

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "loco [%s] train length=%d weight=%d",
      wLoc.getid(data->props), wLoc.gettrainlen(data->props), wLoc.gettrainweight(data->props) );
}


static int _getLen( iOLoc inst ) {
  iOLocData data = Data(inst);
  __calcTrainLen(inst, False);
  if( wLoc.gettrainlen( data->props ) > 0 )
    return wLoc.gettrainlen( data->props );
  return wLoc.getlen( data->props );
}


static Boolean _isCommuter( iOLoc inst ) {
  iOLocData data = Data(inst);
  Boolean commuter = wLoc.iscommuter(data->props);
  if( !commuter && wLoc.gettrain( data->props) != NULL && StrOp.len(wLoc.gettrain( data->props)) > 0 ) {
    iOOperator train = ModelOp.getOperator(AppOp.getModel(), wLoc.gettrain( data->props) );
    if( train != NULL ) {
      commuter = OperatorOp.isCommuter(train);
    }
  }
  return commuter;
}


static const char* _getCargo( iOLoc inst ) {
  iOLocData data = Data(inst);
  const char* cargo = wLoc.getcargo(data->props);
  if( wLoc.gettrain( data->props) != NULL && StrOp.len(wLoc.gettrain( data->props)) > 0 ) {
    iOOperator train = ModelOp.getOperator(AppOp.getModel(), wLoc.gettrain( data->props) );
    if( train != NULL ) {
      cargo = OperatorOp.getCargo(train);
    }
  }
  return cargo;
}


static const char* _getClass( iOLoc inst ) {
  iOLocData data = Data(inst);
  const char* l_class = wLoc.getclass(data->props);
  if( wLoc.gettrain( data->props) != NULL && StrOp.len(wLoc.gettrain( data->props)) > 0 ) {
    iOOperator train = ModelOp.getOperator(AppOp.getModel(), wLoc.gettrain( data->props) );
    if( train != NULL ) {
      const char* o_class = OperatorOp.getClass(train);
      if( o_class != NULL && StrOp.len(o_class) > 0 )
        l_class = o_class;
    }
  }
  return l_class;
}


static Boolean _hasClass( iOLoc inst, const char* class ) {
  iOLocData data = Data(inst);
  const char* l_class = wLoc.getclass(data->props);
  if( wLoc.gettrain( data->props) != NULL && StrOp.len(wLoc.gettrain( data->props)) > 0 ) {
    iOOperator train = ModelOp.getOperator(AppOp.getModel(), wLoc.gettrain( data->props) );
    if( train != NULL ) {
      l_class = OperatorOp.getClass(train);
    }
  }
  return StrOp.find(l_class, class) != NULL ? True:False;
}


static void* _getProperties( void* inst ) {
  iOLocData data = Data((iOLoc)inst);
  return data->props;
}

static const char* _getCurBlock( iOLoc inst ) {
  iOLocData data = Data(inst);
  return data->curBlock;
}


static const char* _getPrevBlock( iOLoc inst ) {
  iOLocData data = Data(inst);
  return data->prevBlock;
}


static const char* _getDestination( iOLoc inst ) {
  iOLocData data = Data(inst);
  return data->destBlock;
}


static void _setCarCount( iOLoc inst, int carcount ) {
  iOLocData data = Data(inst);
  wLoc.setnrcars(data->props, carcount);
}


static void _resetPrevBlock( iOLoc inst ) {
  iOLocData data = Data(inst);
  data->prevBlock = NULL;
}

/* CRjBlock calls this function.
 * Loc can't go in automatic when curBlock in not set.
 */
static void _setCurBlock( iOLoc inst, const char* id ) {
  iOLocData data = Data(inst);



  if( id == NULL || StrOp.len(id) == 0 ) {
    if( data->driver != NULL && data->driver->isRun( data->driver ) ) {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
          "Deny block reset in running mode! (%s)", LocOp.getId(inst) );
      return;
    }
  }

  if( (data->curBlock != NULL && StrOp.len(data->curBlock) > 0 && !StrOp.equals(id, data->curBlock)) || data->prevBlock == NULL ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
        "set previous block to [%s], new to [%s]", data->curBlock == NULL ? "-":data->curBlock, id==NULL ? "-":id );
    data->prevBlock = data->curBlock;
  }
  data->curBlock = id;
  __setCurBlock4Train(inst, data->curBlock);

  if( id != NULL && !StrOp.equals(id, wLoc.getblockid(data->props) ) )
    wLoc.setfifotop(data->props, False);

  wLoc.setblockid( data->props, id==NULL?"":id );
  wLoc.setblockenterid(data->props, "");

  if( data->driver != NULL )
    data->driver->curblock( data->driver, id );

  /* Broadcast to clients. */
  __broadcastLocoProps( inst, NULL, NULL, NULL );
}

static void _informBlock( iOLoc inst, const char* destid, const char* curid ) {
  iOLocData data = Data(inst);
  data->destBlock = destid;
  data->curBlock  = curid;
  __broadcastLocoProps( inst, NULL, NULL, NULL );
}

static void _gotoBlock( iOLoc inst, const char* id ) {
  iOLocData data = Data(inst);
  iIBlockBase block = ModelOp.getBlock( AppOp.getModel(), id );
  iOLocation location = ModelOp.getLocation( AppOp.getModel(), id );

  if( block != NULL ) {
    data->gotoBlock = block->base.id(block);
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "loco [%s] goto block [%s]", LocOp.getId(inst), data->gotoBlock );
    if( data->driver != NULL )
      data->driver->gotoblock( data->driver, data->gotoBlock );
  }
  else if( location != NULL ) {
    data->gotoBlock = location->base.id(location);
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "loco [%s] goto location [%s]", LocOp.getId(inst), data->gotoBlock );
    if( data->driver != NULL )
      data->driver->gotoblock( data->driver, data->gotoBlock );
  }
  else {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "loco [%s] goto block/location [%s] not found", LocOp.getId(inst), id );
  }
}


static const char* _getNextGotoBlock( iOLoc inst, const char* prevblockid ) {
  iOLocData data = Data(inst);
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "next goto block; prev=[%s]", prevblockid==NULL?"":prevblockid );
  if( data->blocktrip != NULL ) {
    iIBlockBase block = NULL;
    iOStrTok tok = StrTokOp.inst( data->blocktrip, ',' );
    while( StrTokOp.hasMoreTokens( tok ) ) {
      const char* bkid = StrTokOp.nextToken( tok );

      if( prevblockid == NULL ) {
        block = ModelOp.getBlock( AppOp.getModel(), bkid );
        if( block != NULL ) {
          data->gotoBlock = block->base.id(block);
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "first goto block [%s]", data->gotoBlock );
          return data->gotoBlock;
        }
        break;
      }
      else if( StrOp.equals(bkid, prevblockid) && StrTokOp.hasMoreTokens( tok ) ) {
        bkid = StrTokOp.nextToken( tok );
        block = ModelOp.getBlock( AppOp.getModel(), bkid );
        if( block != NULL ) {
          data->gotoBlock = block->base.id(block);
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "next goto block [%s] prev=[%s]", data->gotoBlock, prevblockid );
          return data->gotoBlock;
        }
        break;
      }
    }

    /* end of block trip */
    if( !StrTokOp.hasMoreTokens( tok ) ) {
      StrOp.free(data->blocktrip);
      data->blocktrip = NULL;
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "end of block trip" );
    }

    StrTokOp.base.del(tok);
  }
  return NULL;
}


static void _useSchedule( iOLoc inst, const char* id ) {
  iOLocData data = Data(inst);
  if( data->driver != NULL ) {
    iONode schedule = ModelOp.getSchedule( AppOp.getModel(), id );
    if( schedule != NULL )
      data->driver->useschedule( data->driver, wSchedule.getid(schedule) );
    else {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "Schedule [%s] not found; try for tour...", id );
      LocOp.useTour(inst, id);
    }
  }
}

static void _useTour( iOLoc inst, const char* id ) {
  iOLocData data = Data(inst);
  if( data->driver != NULL ) {
    iONode tour = ModelOp.getTour( AppOp.getModel(), id );
    if( tour != NULL )
      data->driver->usetour( data->driver, wTour.getid(tour) );
    else
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Tour [%s] not found!", id );
  }
}

static const char* _getSchedule( iOLoc inst, int* scidx ) {
  iOLocData data = Data(inst);
  if( data->driver != NULL ) {
    const char* schedule = data->driver->getschedule( data->driver );
    if( schedule != NULL ) {
      if( scidx != NULL )
        *scidx = data->driver->getScheduleIdx(data->driver);
      return schedule;
    }
  }
  return "";
}


static const char* _getTour( iOLoc inst ) {
  iOLocData data = Data(inst);
  if( data->driver != NULL ) {
    const char* tour = data->driver->gettour( data->driver );
    if( tour != NULL ) {
      return tour;
    }
  }
  return "";
}


static void _setMode( iOLoc inst, const char* mode, const char* reason ) {
  iOLocData data = Data(inst);

  /* Only take over the new mode if it is different; Broadcast to clients. */
  if( !StrOp.equals( wLoc.getmode(data->props), mode ) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999,
        "Loco [%s] mode=%s prevmode=%s reason=%s", LocOp.getId(inst), mode, wLoc.getmode(data->props), reason );
    wLoc.setmode(data->props, mode);
    wLoc.setmodereason(data->props, reason);

    __broadcastLocoProps( inst, NULL, NULL, NULL );
  }
}

static void _goNet( iOLoc inst, const char* curblock, const char* nextblock, const char* nextroute ) {
  iOLocData data = Data(inst);
  wLoc.setresumeauto( data->props, False);
  data->curBlock = StrOp.dup(curblock); /* make a copy before it is freed up */
  __setCurBlock4Train(inst, data->curBlock);
  data->goNet = True; /* signal that the current block is from the net */
  data->go = True;
  data->released = False;
  data->gomanual = (data->manual?True:False);
  if( data->driver != NULL )
    data->driver->goNet( data->driver, data->gomanual, curblock, nextblock, nextroute );
}

static Boolean _go( iOLoc inst ) {
  iOLocData data = Data(inst);
  iOModel model = AppOp.getModel(  );

  if( data->driver != NULL && data->driver->isRun( data->driver ) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "Loco [%s] is already running in auto mode; reset wait.", LocOp.getId(inst) );
    data->driver->gogo(data->driver);
    return False;
  }

  wLoc.setresumeauto( data->props, False);
  if( wLoc.isactive(data->props)) {
    if( data->curBlock != NULL && StrOp.len(data->curBlock) > 0 && ModelOp.isAuto( AppOp.getModel() ) ) {
      iIBlockBase block = ModelOp.getBlock( model, data->curBlock );
      if( block != NULL ) {
        if( StrOp.equals( wStage.name(), NodeOp.getName(block->base.properties(block)) ) &&
            !block->isDepartureAllowed( block, wLoc.getid(data->props), False ) )
        {
          /* Staging block will manage this loco. */
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
              "not starting loco [%s] because it is managed by staging block %s.", LocOp.getId(inst), data->curBlock );
          return False;
        }

        data->go = True;
        data->released = False;
        data->govirtual = False;
        data->gomanual = (data->manual?True:False);
        if( data->driver != NULL )
          data->driver->go( data->driver, data->gomanual );

      }
    }
    else {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
          "Loco [%s] cannot be started because %s.",
          LocOp.getId(inst), ModelOp.isAuto( AppOp.getModel() )?"it is not in a block":"auto mode is disabled" );
      return False;
    }
  }
  else {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Loco [%s] is deactivated.", LocOp.getId(inst) );
    return False;
  }
  LocOp.resetBBT(inst);
  return True;
}

static void _stop( iOLoc inst, Boolean resume ) {
  iOLocData data = Data(inst);
  if( resume && data->go ) {
    wLoc.setresumeauto( data->props, True);
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "resume flag set for [%s]", LocOp.getId(inst) );
  }

  data->go = False;
  data->released = False;

  if( data->driver != NULL )
    data->driver->stop( data->driver );

  __checkAction(inst, "stop", "");

}

static void _stopNet( iOLoc inst ) {
  iOLocData data = Data(inst);
  data->go = False;
  if( data->driver != NULL ) {
    iONode broadcast = NULL;
    data->driver->stopNet( data->driver );
    data->driver->brake( data->driver );

    /* Broadcast to clients. */
    broadcast = (iONode)NodeOp.base.clone(data->props);
    wLoc.setV( broadcast, data->drvSpeed );
    AppOp.broadcastEvent( broadcast );
  }
}

static void _dispatch( iOLoc inst ) {
  iOLocData data = Data(inst);
  iOControl control = AppOp.getControl();

  iONode cmd = (iONode)NodeOp.base.clone(data->props);
  wLoc.setcmd( cmd, wLoc.dispatch );
  ControlOp.cmd( control, cmd, NULL );

}

static void _release( iOLoc inst, iONode cmd ) {
  iOLocData data = Data(inst);
  if( wLoc.getthrottleid( data->props ) == NULL || StrOp.len(wLoc.getthrottleid( data->props )) == 0 )
    return;
  if( wLoc.getthrottleid( cmd ) == NULL || StrOp.len(wLoc.getthrottleid( cmd )) == 0 )
    return;

  if( StrOp.equals(wLoc.getthrottleid( data->props ), wLoc.getthrottleid( cmd ) ) ) {
    wLoc.setthrottleid( data->props, "" );
    TraceOp.trc( name, TRCLEVEL_MONITOR, __LINE__, 9999, "loco %s is released from throttle %s", wLoc.getid(data->props), wLoc.getthrottleid( cmd ) );
  }
}

static void _reset( iOLoc inst, Boolean saveCurBlock ) {
  iOLocData data = Data(inst);
  data->go    = False;
  data->enter = False;
  data->in    = False;
  data->exit  = False;
  data->out   = False;

  LocOp.resetBBT(inst);

  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999,
      "reset [%s] in current block [%s]%s",
      LocOp.getId(inst), data->curBlock==NULL?"?":data->curBlock, saveCurBlock?" (save current block)":"" );

  if( !saveCurBlock ) {
    wLoc.setblockid(data->props, "");
    wLoc.setscidx(data->props, -1);
    data->curBlock = NULL;
    __setCurBlock4Train(inst, data->curBlock);

    if( data->driver != NULL )
      data->driver->useschedule(data->driver, NULL);
  }

  if( data->blocktrip != NULL ) {
    StrOp.free(data->blocktrip);
    data->blocktrip = NULL;
  }

  data->destBlock = NULL;
  wLoc.setdestblockid(data->props, "");

  if( data->driver != NULL )
    data->driver->reset( data->driver, saveCurBlock );

  /* Broadcast to clients. */
  AppOp.broadcastEvent( (iONode)NodeOp.base.clone( data->props ) );

}

static void __stopgo( iOLoc inst ) {
  iOLocData data = Data(inst);
  data->go = !data->go;
  data->gomanual = (data->manual?True:False);
  data->govirtual = False;
  if( data->go )
    _go( inst );
  else
    _stop( inst, False );
}


static Boolean _gomanual( iOLoc inst ) {
  iOLocData data = Data(inst);
  iOModel model = AppOp.getModel();
  if( data->curBlock != NULL && StrOp.len(data->curBlock) > 0 && ModelOp.isAuto( AppOp.getModel() ) ) {
    iIBlockBase block = ModelOp.getBlock( model, data->curBlock );
    if( block != NULL ) {
      data->go = True;
      data->gomanual = True;
      data->govirtual = False;
      data->released = False;
      if( data->driver != NULL )
        data->driver->go( data->driver, data->gomanual );
      return True;
    }
  }
  else {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Loco [%s] cannot be started because it is not in a block.", LocOp.getId(inst) );
  }
  return False;
}


static Boolean _govirtual( iOLoc inst ) {
  iOLocData data = Data(inst);
  iOModel model = AppOp.getModel();
  if( data->curBlock != NULL && StrOp.len(data->curBlock) > 0 && ModelOp.isAuto( AppOp.getModel() ) ) {
    iIBlockBase block = ModelOp.getBlock( model, data->curBlock );
    if( block != NULL ) {
      TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Loco [%s] start virtual in block %s.", LocOp.getId(inst), block->base.id(block) );
      data->go = True;
      data->gomanual = (data->manual?True:False);
      data->govirtual = True;
      data->released = False;
      if( data->driver != NULL )
        data->driver->go( data->driver, data->gomanual );
      return True;
    }
  }
  else {
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "Loco [%s] cannot be started because it is not in a block.", LocOp.getId(inst) );
  }
  return False;
}


static void _brake( iOLoc inst ) {
  iOLocData data = Data(inst);
  data->brake = True;
  if( data->driver != NULL )
    data->driver->brake( data->driver );
}


static void __checkConsist( iOLoc inst, iONode nodeA, Boolean byEvent ) {
  iOLocData data = Data(inst);

  if( wLoc.isconsistcmd( nodeA ) ) {
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "skip check consist; command is issued from a consist context" );
    return;
  }

  /* check train and send a copy of the nodeA */
  if( nodeA != NULL && StrOp.len( wLoc.gettrain(data->props) ) > 0 ) {
    iOOperator opr = ModelOp.getOperator( AppOp.getModel(), wLoc.gettrain(data->props) );
    if( opr != NULL ) {
      iONode consistcmd = (iONode)NodeOp.base.clone( nodeA );
      wLoc.setconsistcmd( consistcmd, True );
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "send command to the operator" );
      OperatorOp.cmd(opr, (iONode)NodeOp.base.clone( consistcmd ));
    }
  }

  /* check consist and send a copy of the nodeA */
  if( nodeA != NULL && StrOp.len( wLoc.getconsist(data->props) ) > 0 ) {
    iOStrTok  consist = StrTokOp.inst( wLoc.getconsist ( data->props ), ',' );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "sending command to the consist member [%s]",
                   wLoc.getconsist(data->props) );

    while( StrTokOp.hasMoreTokens( consist ) ) {
      const char* tok = StrTokOp.nextToken( consist );
      iOLoc consistloc = ModelOp.getLoc( AppOp.getModel(), tok, NULL, False );
      if( consistloc != NULL && consistloc != inst ) {
        iONode consistcmd = (iONode)NodeOp.base.clone( nodeA );

        /* check consist details */
        if( wLoc.isconsist_lightsoff(data->props) ) {
          wLoc.setfn( consistcmd, False );
        }
        else {
          if( !wLoc.isconsist_synclights(data->props) )
            wLoc.setignorefn(consistcmd, True);
        }

        wLoc.setconsistcmd( consistcmd, True );

        if( byEvent ) {
          int V = __getVfromRaw(inst, consistcmd);
          wLoc.setV(consistcmd, V);
        }

        if( StrOp.equals(wFunCmd.name(), NodeOp.getName(consistcmd) ) ) {
          if( wLoc.isconsist_syncfun( data->props ) ) {
            int fchg = wFunCmd.getfnchanged( consistcmd );
            int fmap = wLoc.getconsist_syncfunmap( data->props );
            if( fchg > 0 && (fmap & 1 << (fchg-1) )  )
              LocOp.cmd( consistloc, consistcmd );
          }
        }
        else if( StrOp.equals(wLoc.name(), NodeOp.getName(consistcmd) ) ) {
          LocOp.cmd( consistloc, consistcmd );
        }

      }
      else {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "consist loco [%s] not found", tok );
      }
    };
    StrTokOp.base.del( consist );
  }

}

static void __swapConsist( iOLoc inst, iONode cmd ) {
  iOLocData data = Data(inst);

  /* swap consist */
  if( StrOp.len( wLoc.getconsist(data->props) ) > 0 ) {
    iOStrTok  consist = StrTokOp.inst( wLoc.getconsist ( data->props ), ',' );
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "swapping the consist member [%s]",
                   wLoc.getconsist(data->props) );

    while( StrTokOp.hasMoreTokens( consist ) ) {
      const char* tok = StrTokOp.nextToken( consist );
      iOLoc consistloc = ModelOp.getLoc( AppOp.getModel(), tok, NULL, False );
      if( consistloc != NULL ) {
        LocOp.swapPlacing( consistloc, cmd, True, False );
      }
      else {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "consist loco [%s] not found", tok );
      }
    };
    StrTokOp.base.del( consist );
  }

  /* check train and send a copy of the nodeA */
  if( StrOp.len( wLoc.gettrain(data->props) ) > 0 ) {
    iOOperator opr = ModelOp.getOperator( AppOp.getModel(), wLoc.gettrain(data->props) );
    if( opr != NULL ) {
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "send swap command to the operator" );
      OperatorOp.swapPlacing( opr, cmd );
    }
  }



}


static Boolean _cmd( iOLoc inst, iONode nodeA ) {
  iOLocData data = Data(inst);
  iOControl control = AppOp.getControl(  );

  iOModel model = AppOp.getModel(  );

  const char* nodename = NodeOp.getName( nodeA );
  const char* cmd  = wLoc.getcmd( nodeA );

  if( !data->run ) {
    NodeOp.base.del(nodeA);
    return False;
  }

  if( !MutexOp.trywait( data->muxCmd, 100 ) ) {
    char* cmdStr = NodeOp.base.toString(nodeA);
    TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "timeout on loco command mutex: [%s] [%s:%s]\n%s", wLoc.getid(data->props), nodename, cmd, cmdStr );
    StrOp.free(cmdStr);
    NodeOp.base.del(nodeA);
    return False;
  }

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "%scommand %s:%s for loco %s",
      wLoc.isconsistcmd(nodeA)?"consist ":"", nodename, (cmd==NULL?"-":cmd), wLoc.getid( data->props ) );

  if( !wLoc.isconsistcmd( nodeA ) && wCtrl.isredirecttomaster(AppOp.getIniNode(wCtrl.name())) ) {
    iOLoc master = ModelOp.getMasterLoc(model, wLoc.getid( data->props ));

    if( master != NULL && StrOp.equals(wLoc.name(), nodename ) ) {
      iOLoc slave  = ModelOp.getMasterLoc(model, LocOp.getId(master) );
      if( slave != inst ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "redirecting command %s:%s from %s to master %s",
            nodename, (cmd==NULL?"-":cmd), wLoc.getid( data->props ), LocOp.getId(master) );
        wLoc.setignorefn(nodeA, True);
        MutexOp.post( data->muxCmd );
        LocOp.cmd(master, nodeA);
        return True;
      }
      else {
        TraceOp.trc( name, TRCLEVEL_EXCEPTION, __LINE__, 9999, "rejecting command %s:%s from %s to master %s -> master/slave loop!",
            nodename, (cmd==NULL?"-":cmd), wLoc.getid( data->props ), LocOp.getId(master) );
      }
    }
  }

  if( StrOp.equals(wBinStateCmd.name(), nodename ) ) {
    wBinStateCmd.setid(nodeA, wLoc.getid(data->props) );
    wBinStateCmd.setbus(nodeA, wLoc.getbus(data->props) );
    wBinStateCmd.setaddr(nodeA, wLoc.getaddr(data->props) );
    ControlOp.cmd( control, nodeA, NULL );
    MutexOp.post( data->muxCmd );
    return True;
  }

  if( StrOp.equals(wLoc.name(), nodename ) && wLoc.isignorefn(nodeA) ) {
    wLoc.setfn(nodeA, data->fn0);
  }

  if( wCtrl.isdisablesteal( AppOp.getIniNode( wCtrl.name() ) ) ) {
    if( wLoc.getthrottleid( nodeA ) != NULL && StrOp.len(wLoc.getthrottleid( nodeA)) > 0 ) {
      if( wLoc.getthrottleid( data->props ) != NULL && StrOp.len(wLoc.getthrottleid( data->props)) > 0 && !StrOp.equals(wLoc.getthrottleid( data->props), "0") ) {
        if( !StrOp.equals(wLoc.getthrottleid( data->props ), wLoc.getthrottleid( nodeA)) ) {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
              "cmd from %s rejected because this loco is already controlled by %s",
              wLoc.getthrottleid( nodeA),
              wLoc.getthrottleid( data->props )
              );
          NodeOp.base.del(nodeA);
          MutexOp.post( data->muxCmd );
          return False;
        }
      }
    }
  }

  if( StrOp.equals(wLoc.name(), nodename ) && wLoc.getthrottleid(nodeA) != NULL && StrOp.len(wLoc.getthrottleid(nodeA)) > 0 )
    wLoc.setthrottleid( data->props, wLoc.getthrottleid(nodeA) );
  else
    wLoc.setthrottleid( data->props, "" );


  if( TraceOp.getLevel(NULL) & TRCLEVEL_USER1 ) {
    char* cmdstr = NodeOp.base.toString( nodeA );
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, cmdstr );
    StrOp.free( cmdstr );
  }

  if( cmd != NULL && !StrOp.equals( wLoc.direction, cmd )  && !StrOp.equals( wLoc.velocity, cmd ) && !StrOp.equals( wLoc.dirfun, cmd ) ) {
    Boolean broadcast = False;
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "processing cmd=\"%s\" for [%s]",  cmd, LocOp.getId( inst ) );

    /* Reset saved speed. */
    data->savedSpeed = 0;

    if( ModelOp.isAuto( AppOp.getModel() ) ) {
      if( StrOp.equals( wLoc.go, cmd ) ) {
        _go( inst );
      }
      else if( StrOp.equals( wLoc.gomanual, cmd ) ) {
        _gomanual( inst );
      }
      else if( StrOp.equals( wLoc.govirtual, cmd ) ) {
        _govirtual( inst );
      }
      else if( StrOp.equals( wLoc.stopgo, cmd ) ) {
        __stopgo( inst );
        LocOp.resetPrevBlock(inst);
      }
    }
    else {
      if( StrOp.equals( wLoc.go, cmd ) || StrOp.equals( wLoc.stopgo, cmd ) ) {
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999,
                     "Ignoring go commands for %s when not in AutoMode!",
                      LocOp.getId( inst ) );
        nodeA->base.del(nodeA);
        MutexOp.post( data->muxCmd );
        return False;
      }
    }


    if( StrOp.equals( wLoc.stop, cmd ) ) {
      _stop( inst, False );
      LocOp.resetPrevBlock(inst);
    }
    else if( StrOp.equals( wLoc.reset, cmd ) ) {
      MutexOp.post( data->muxCmd );
      _reset( inst, False );
      LocOp.resetPrevBlock(inst);
      nodeA->base.del(nodeA);
      return True;
    }
    else if( StrOp.equals( wLoc.softreset, cmd ) ) {
      MutexOp.post( data->muxCmd );
      _reset( inst, True );
      LocOp.resetPrevBlock(inst);
      nodeA->base.del(nodeA);
      return True;
    }
    else if( StrOp.equals( wLoc.activate, cmd ) ) {
      wLoc.setactive(data->props, True);
      broadcast = True;
    }
    else if( StrOp.equals( wLoc.deactivate, cmd ) ) {
      wLoc.setactive(data->props, False);
      broadcast = True;
    }
    else if( StrOp.equals( wLoc.swap, cmd ) ) {
      LocOp.swapPlacing(inst, nodeA, False, False);
      broadcast = True;
    }
    else if( StrOp.equals( wLoc.blockside, cmd ) ) {
      LocOp.swapBlockEnterSide(inst, NULL);
      broadcast = True;
    }
    else if( StrOp.equals( wLoc.dispatch, cmd ) ) {
      _dispatch( inst );
    }
    else if( StrOp.equals( wLoc.release, cmd ) ) {
      _release(inst, nodeA);
      broadcast = True;
    }
    else if( StrOp.equals( wLoc.brake, cmd ) ) {
      _brake( inst );
    }
    else if( StrOp.equals( wLoc.classset, cmd ) ) {
      LocOp.setClass(inst, wLoc.getclass(nodeA));
    }
    else if( StrOp.equals( wLoc.classadd, cmd ) ) {
      char* newclass = NULL;
      Boolean isNew = True;

      iOStrTok tok = StrTokOp.inst(wLoc.getclass(data->props), ',');
      while( StrTokOp.hasMoreTokens(tok) ) {
        const char* c = StrTokOp.nextToken(tok);
        if( StrOp.equals(c, wLoc.getclass(nodeA)) ) {
          isNew = False;
          break;
        }
      }
      StrTokOp.base.del(tok);

      if( isNew ) {
        if( StrOp.len(wLoc.getclass(data->props)) > 0 )
          newclass = StrOp.fmt("%s,%s", wLoc.getclass(data->props), wBlock.getclass(nodeA));
        else
          newclass = StrOp.fmt("%s", wLoc.getclass(nodeA));
        LocOp.setClass(inst, newclass);
        StrOp.free(newclass);
      }
    }
    else if( StrOp.equals( wLoc.classdel, cmd ) ) {
      char* newclass = NULL;
      int idx = 0;
      iOStrTok tok = StrTokOp.inst(wLoc.getclass(data->props), ',');
      while( StrTokOp.hasMoreTokens(tok) ) {
        const char* c = StrTokOp.nextToken(tok);
        if( StrOp.equals(c, wLoc.getclass(nodeA)) )
          continue;
        if( idx > 0 )
          newclass = StrOp.cat(newclass, ",");
        newclass = StrOp.cat(newclass, c);
        idx++;
      }
      LocOp.setClass(inst, newclass);
      StrOp.free(newclass);
    }
    else if( StrOp.equals( wLoc.gotoblock, cmd ) ) {
      const char* blockid = wLoc.getblockid( nodeA );

      if( data->blocktrip != NULL ) {
        /* end of block trip */
        data->blocktrip = StrOp.cat(data->blocktrip, ",");
        data->blocktrip = StrOp.cat(data->blocktrip, blockid);
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "block trip end = [%s]", data->blocktrip);
        LocOp.gotoBlock( inst, LocOp.getNextGotoBlock(inst, NULL) );
      }
      else {
        LocOp.gotoBlock( inst, blockid );
      }
    }
    else if( StrOp.equals( wLoc.addblock2trip, cmd ) ) {
      const char* blockid = wLoc.getblockid( nodeA );
      if( data->blocktrip == NULL )
        data->blocktrip = StrOp.dup(blockid);
      else {
        data->blocktrip = StrOp.cat(data->blocktrip, ",");
        data->blocktrip = StrOp.cat(data->blocktrip, blockid);
      }
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "block trip = [%s]", data->blocktrip);
    }
    else if( StrOp.equals( wLoc.useschedule, cmd ) ) {
      const char* scheduleid = wLoc.getscheduleid( nodeA );
      LocOp.useSchedule( inst, scheduleid );
    }
    else if( StrOp.equals( wLoc.usetour, cmd ) ) {
      const char* tourid = wLoc.gettourid( nodeA );
      LocOp.useTour( inst, tourid );
    }
    else if( StrOp.equals( wLoc.shuntingon, cmd ) || StrOp.equals( wLoc.shuntingoff, cmd ) ) {
      iONode cmdNode = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
      wLoc.setid( cmdNode, wLoc.getid(data->props) );
      wLoc.setaddr( cmdNode, wLoc.getaddr(data->props) );
      wLoc.setprot( cmdNode, wLoc.getprot( data->props ) );
      wLoc.setprotver( cmdNode, wLoc.getprotver( data->props ) );
      wLoc.setspcnt( cmdNode, wLoc.getspcnt( data->props ) );
      wLoc.setfncnt( cmdNode, wLoc.getfncnt( data->props ) );
      wLoc.setcmd( cmdNode, cmd );
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "send %s", cmd );
      ControlOp.cmd( control, cmdNode, NULL );
    }
    else if( StrOp.equals( wLoc.manualon, cmd ) || StrOp.equals( wLoc.manualoff, cmd ) ) {
      iONode cmdNode = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
      wLoc.setid( cmdNode, wLoc.getid(data->props) );
      wLoc.setaddr( cmdNode, wLoc.getaddr(data->props) );
      wLoc.setprot( cmdNode, wLoc.getprot( data->props ) );
      wLoc.setprotver( cmdNode, wLoc.getprotver( data->props ) );
      wLoc.setspcnt( cmdNode, wLoc.getspcnt( data->props ) );
      wLoc.setfncnt( cmdNode, wLoc.getfncnt( data->props ) );
      wLoc.setcmd( cmdNode, cmd );
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "send %s", cmd );
      ControlOp.cmd( control, cmdNode, NULL );
    }
    else if( StrOp.equals( wLoc.shortid, cmd ) ) {
      /* send short ID to command station */
      if( wLoc.isuseshortid(data->props) )
      {
        iONode cmdNode = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
        wLoc.setid( cmdNode, wLoc.getid(data->props) );
        wLoc.setaddr( cmdNode, wLoc.getaddr(data->props) );
        if( wLoc.getshortid(data->props) != NULL && StrOp.len(wLoc.getshortid(data->props)) > 0 )
          wLoc.setshortid( cmdNode, wLoc.getshortid(data->props) );
        else
          wLoc.setshortid( cmdNode, wLoc.getid(data->props) );
        wLoc.setthrottlenr( cmdNode, wLoc.getthrottlenr(data->props) );
        wLoc.setprot( cmdNode, wLoc.getprot( data->props ) );
        wLoc.setprotver( cmdNode, wLoc.getprotver( data->props ) );
        wLoc.setspcnt( cmdNode, wLoc.getspcnt( data->props ) );
        wLoc.setfncnt( cmdNode, wLoc.getfncnt( data->props ) );
        wLoc.setcmd( cmdNode, wLoc.shortid );
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "send (short) ID: %s", wLoc.getshortid(cmdNode) );
        ControlOp.cmd( control, cmdNode, NULL );
      }
    }
    else if( StrOp.equals( wLoc.block, cmd ) ) {
      const char* blockid = wLoc.getblockid( nodeA );

      if( data->curBlock != NULL ) {
        if( blockid == NULL || !StrOp.equals(data->curBlock, blockid) ) {
          iIBlockBase block = ModelOp.getBlock( model, data->curBlock );
          if( block ) {
            iONode cmd = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
            wBlock.setid( cmd, data->curBlock );
            wBlock.setlocid( cmd, "" );
            block->cmd( block, cmd );
          }
        }
      }

      if( blockid != NULL ) {
        iIBlockBase block = ModelOp.getBlock( model, blockid );
        if( block ) {
          iONode cmd = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
          wBlock.setid( cmd, blockid );
          wBlock.setlocid( cmd, LocOp.getId( inst ) );
          block->cmd( block, cmd );
        }
      }
    }

    else if( StrOp.equals( wLoc.assigntrain, cmd ) ) {
      wLoc.settrain(data->props, wLoc.gettrain(nodeA));
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "consist [%s] assigned to loco [%s]", wLoc.gettrain(data->props), wLoc.getid( data->props ) );
      /* Update train length. */
      __calcTrainLen(inst, True);
      __setCurBlock4Train(inst, data->curBlock);
      broadcast = True;
    }

    else if( StrOp.equals( wLoc.releasetrain, cmd ) ) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "consist [%s] released from loco [%s]", wLoc.gettrain(data->props), wLoc.getid( data->props ) );
      wLoc.settrain(data->props, "");
      wLoc.settrainlen(data->props, 0);
      wLoc.settrainweight( data->props, 0 );
      if( wLoc.isadjustaccel(data->props) ) {
        LocOp.adjustAccel(inst, wLoc.getaccelmin(data->props), 0 );
      }
      broadcast = True;
    }
    else if( StrOp.equals( wLoc.setmanualmode, cmd ) ) {
      data->manual = True;
      data->gomanual = True;
      wLoc.setmanual(data->props, True);
      broadcast = True;
    }
    else if( StrOp.equals( wLoc.resetmanualmode, cmd ) ) {
      data->manual = False;
      data->gomanual = False;
      wLoc.setmanual(data->props, False);
      broadcast = True;
    }
    else if( StrOp.equals( wLoc.consist, cmd ) ) {
      wLoc.setconsist(data->props, wLoc.getconsist(nodeA));
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "loco %s consist=[%s]", LocOp.getId(inst), wLoc.getconsist(data->props));
      broadcast = True;
    }

    if(broadcast) {
      /* Broadcast to clients. */
      __broadcastLocoProps( inst, NULL, (iONode)NodeOp.base.clone( nodeA ), NULL );
    }

    nodeA->base.del(nodeA);

    MutexOp.post( data->muxCmd );
    return True;
  }
  else {
    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "processing cmd=\"%s\" for [%s]",  cmd==NULL?"-":cmd, LocOp.getId( inst ) );
  }

  if( StrOp.equals(wFunCmd.name(), NodeOp.getName(nodeA))) {
    data->lastfncmd = SystemOp.getTick();
  }

  /* Inform Driver. */
  if( data->driver != NULL )
    data->driver->info( data->driver, nodeA );

  /* release mutex to avoid blocking */
  MutexOp.post( data->muxCmd );

  if( nodeA != NULL ) {
    iOMsg msg = MsgOp.inst( NULL, cmd_event );
    MsgOp.setTimer( msg, wLoc.getcmdDelay(nodeA) );
    MsgOp.setEvent( msg, cmd_event );
    MsgOp.setUsrData(msg, nodeA, 0 );
    ThreadOp.post( data->runner, (obj)msg );
  }

  return True;
}

/**
 * Checks for property changes.
 * todo: Range checking?
 */
static void _modify( iOLoc inst, iONode props ) {
  iOLocData data = Data(inst);

  /* Do not replace all attributes and child nodes in auto mode! */

  if( LocOp.isAutomode( inst ) ) {
    /* only replace none destructive attributes */
    if(NodeOp.findAttr(props, "secondnextblock"))
      wLoc.setsecondnextblock( data->props, wLoc.issecondnextblock(props) );
    if(NodeOp.findAttr(props, "len"))
      wLoc.setlen( data->props, wLoc.getlen(props) );
    if(NodeOp.findAttr(props, "shortin"))
      wLoc.setshortin( data->props, wLoc.isshortin(props) );
    if(NodeOp.findAttr(props, "inatpre2in"))
      wLoc.setinatpre2in( data->props, wLoc.isinatpre2in(props) );
    if(NodeOp.findAttr(props, "V_max"))
      wLoc.setV_max( data->props, wLoc.getV_max(props) );
    if(NodeOp.findAttr(props, "V_mid"))
      wLoc.setV_mid( data->props, wLoc.getV_mid(props) );
    if(NodeOp.findAttr(props, "V_min"))
      wLoc.setV_min( data->props, wLoc.getV_min(props) );
    if(NodeOp.findAttr(props, "V_Rmax"))
      wLoc.setV_Rmax( data->props, wLoc.getV_Rmax(props) );
    if(NodeOp.findAttr(props, "V_Rmid"))
      wLoc.setV_Rmid( data->props, wLoc.getV_Rmid(props) );
    if(NodeOp.findAttr(props, "V_Rmin"))
      wLoc.setV_Rmin( data->props, wLoc.getV_Rmin(props) );
    if(NodeOp.findAttr(props, "desc"))
      wLoc.setdesc( data->props, wLoc.getdesc(props) );
    if(NodeOp.findAttr(props, "rmark"))
      wLoc.setremark( data->props, wLoc.getremark(props) );
    if(NodeOp.findAttr(props, "catnr"))
      wLoc.setcatnr( data->props, wLoc.getcatnr(props) );
    if(NodeOp.findAttr(props, "fncnt"))
      wLoc.setfncnt( data->props, wLoc.getfncnt(props) );
    if(NodeOp.findAttr(props, "cargo"))
      wLoc.setcargo( data->props, wLoc.getcargo(props) );
    if(NodeOp.findAttr(props, "engine"))
      wLoc.setengine( data->props, wLoc.getengine(props) );
    if(NodeOp.findAttr(props, "consist")) {
      if( StrOp.find( wLoc.getconsist(props), LocOp.getId(inst) ) == NULL ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "modify: %s consist=\"%s\"", LocOp.getId(inst), wLoc.getconsist(props));
        wLoc.setconsist( data->props, wLoc.getconsist(props) );
      }
      else
        TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "consist rejected: %s consist=\"%s\"", LocOp.getId(inst), wLoc.getconsist(props));
    }
  }
  else {
    int cnt = NodeOp.getAttrCnt( props );
    int i = 0;

    for( i = 0; i < cnt; i++ ) {
      iOAttr attr = NodeOp.getAttr( props, i );
      const char* attname  = AttrOp.getName( attr );
      const char* value = AttrOp.getVal( attr );

      if( StrOp.equals("id", attname) && StrOp.equals( value, wLoc.getid(data->props) ) )
        continue; /* skip to avoid making invalid pointers */


      if( StrOp.equals( "blockid", attname ) ) {
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "modify: %s blockid=\"%s\" (%s)",
            LocOp.getId(inst), value, wLoc.getblockid(data->props)!=NULL?wLoc.getblockid(data->props):"-" );
      }
      if( StrOp.equals( "destblockid", attname ) )
        TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "modify: %s destblockid=\"%s\"", LocOp.getId(inst), value );

      if( StrOp.equals( "consist", attname ) ) {
        if( StrOp.find( wLoc.getconsist(props), LocOp.getId(inst) ) == NULL ) {
          TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "modify: %s consist=\"%s\"", LocOp.getId(inst), wLoc.getconsist(props));
          wLoc.setconsist( data->props, wLoc.getconsist(props) );
        }
        else {
          TraceOp.trc( name, TRCLEVEL_WARNING, __LINE__, 9999, "consist rejected: %s consist=\"%s\"", LocOp.getId(inst), wLoc.getconsist(props));
          continue;
        }
      }

      if( !StrOp.equals( "runtime", attname ) )
        NodeOp.setStr( data->props, attname, value );

    }

    cnt = NodeOp.getChildCnt( data->props );
    while( cnt > 0 ) {
      iONode child = NodeOp.getChild( data->props, 0 );
      iONode removedChild = NodeOp.removeChild( data->props, child );
      if( removedChild != NULL) {
        TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "remove child node %s of %s", NodeOp.getName(removedChild), LocOp.getId(inst));
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

  data->secondnextblock = wLoc.issecondnextblock( data->props );

  __initBBTmap(inst);
  __initSBTmap(inst);

  __initCVmap(inst);

  if( wLoc.isshow(data->props) && data->runner == NULL && __loadDriver( inst ) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "loco [%s] enterside=[%c]", wLoc.getid(data->props), wLoc.isblockenterside(data->props)?'+':'-');
    data->runner = ThreadOp.inst( LocOp.getId(inst), &__runner, inst );
    data->run = True;
    ThreadOp.start( data->runner );
  }


  /* Broadcast to clients. */
  {
    iONode clone = (iONode)props->base.clone( props );
    wLoc.setid(clone, wLoc.getid( data->props ) );
    wLoc.setcmd(clone, wModelCmd.modify );
    AppOp.broadcastEvent( clone );
  }
  props->base.del(props);
}


static const char* _tableHdr(void) {
  return "<tr bgcolor=\"#CCCCCC\"><th>LocID</th><th>Addr</th><th>Remark</th><th>CatNr</th><th>f1</th><th>f2</th><th>f3</th><th>f4</th></tr>\n";
}


static char* _normalizeID( const char* id ) {
  char* nid = StrOp.dup( id );
  char* p = nid;
  int i = 0;
  while( *p != '\0' ) {
    if( *p == ' ' )
      *p = '_';
    p++;
  }
  return nid;
}

static char* _toHtml( void* inst ) {
  iOLocData data = Data((iOLoc)inst);
  char* hrefid = _normalizeID( wLoc.getid( data->props ) );
  char* html = NULL;
  const char* fn1 = "";
  const char* fn2 = "";
  const char* fn3 = "";
  const char* fn4 = "";

  iONode fundef = wLoc.getfundef( data->props );
  while( fundef != NULL ) {
    const char* fntxt = wFunDef.gettext( fundef );
    switch( wFunDef.getfn( fundef ) ) {
      case 1: fn1 = fntxt; break;
      case 2: fn2 = fntxt; break;
      case 3: fn3 = fntxt; break;
      case 4: fn4 = fntxt; break;
    }
    fundef = wLoc.nextfundef( data->props, fundef );
  }

  html = StrOp.fmt( "<tr><td><a href=\"%s%s\">%s</a></td><td align=\"right\">%d</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n",
      "loc?id=",
      hrefid,
      wLoc.getid( data->props ),
      wLoc.getaddr( data->props ),
      wLoc.getdesc( data->props ),
      wLoc.getcatnr( data->props ),
      fn1,
      fn2,
      fn3,
      fn4
      );
  StrOp.free( hrefid );
  return html;
}


static char* _getForm( void* inst ) {
  iOLocData data = Data((iOLoc)inst);
  char* hrefid = _normalizeID( wLoc.getid( data->props ) );
  char* form = StrOp.fmt( "<form method=\"post\" action=\"loc?id=%s\">\n"
                          "<table>\n"
                          "<tr><td>id</td><td><input name=\"id\" value=\"%s\" readonly></td></tr>\n"
                          "<tr><td>description</td><td><input name=\"desc\" value=\"%s\" readonly></td></tr>\n"
                          "<tr><td>address</td><td><input name=\"addr\" value=\"%d\"></td></tr>\n"
                          "<tr><td>train length</td><td><input name=\"len\" value=\"%d\"></td></tr>\n"
                          "<tr><td>min speed</td><td><input name=\"mins\" value=\"%d\"></td></tr>\n"
                          "<tr><td>max speed</td><td><input name=\"maxs\" value=\"%d\"></td></tr>\n"
                          "<tr><td>acceleration</td><td><input name=\"accel\" value=\"%d\"></td></tr>\n"
                          "</table>\n"
                          "<input type=\"submit\" value=\"Submit\"><br>\n"
                          "</form>\n",
                          hrefid,
                          wLoc.getid( data->props ),
                          wLoc.getdesc( data->props ),
                          wLoc.getaddr( data->props ),
                          wLoc.getlen( data->props ),
                          wLoc.getV_min( data->props ),
                          wLoc.getV_max( data->props ),
                          wLoc.getV_step( data->props )
                          );
  StrOp.free( hrefid );
  return form;
}


static char* _postForm( void* inst, const char* postdata ) {
  iOLocData data = Data((iOLoc)inst);
  char* reply = StrOp.fmt( "OK, properties changed for %s.<br>", wLoc.getid( data->props ) );
  iOMap map = HttpOp.createPostDataMap( postdata );

  char* val = (char*)MapOp.get( map, "addr" );
  if( val != NULL ) {
    int ival = atoi( val );
    if( ival != wLoc.getaddr( data->props ) )
      wLoc.setaddr( data->props, ival );
  }

  val = (char*)MapOp.get( map, "mins" );
  if( val != NULL ) {
    int ival = atoi( val );
    if( ival != wLoc.getV_min( data->props ) )
      wLoc.setV_min( data->props, ival );
  }

  val = (char*)MapOp.get( map, "maxs" );
  if( val != NULL ) {
    int ival = atoi( val );
    if( ival != wLoc.getV_max( data->props ) )
      wLoc.setV_max( data->props, ival );
  }

  val = (char*)MapOp.get( map, "accel" );
  if( val != NULL ) {
    int ival = atoi( val );
    if( ival != wLoc.getV_step( data->props ) )
      wLoc.setV_step( data->props, ival );
  }

  /* Cleanup map: */
  HttpOp.deletePostDataMap( map );
  return reply;
}


typedef iILcDriverInt (* LPFNGETLCDIRINT)( const iOLoc, const iOModel ,const iOTrace, iONode ctrl );

static Boolean __loadDriver( iOLoc inst ) {
  iOLocData data = Data(inst);
  int ignevt = wCtrl.getignevt( AppOp.getIniNode( wCtrl.name() ) );
  int eventtimeout = wCtrl.geteventtimeout( AppOp.getIniNode( wCtrl.name() ) );
  int signalreset  = wCtrl.getsignalreset( AppOp.getIniNode( wCtrl.name() ) );
  Boolean secondnextblock = wCtrl.issecondnextblock( AppOp.getIniNode( wCtrl.name() ) );

  iOLib    pLib = NULL;
  /*iILcDriverInt rocGetLcDrInt( const iOLoc loc, const iOModel model, const iOTrace trc )*/
  LPFNGETLCDIRINT pInitFun = (void *) NULL;

  data->ignevt = ignevt;

  TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "load LcDriver lib=\"%s\"", wLoc.getlclib( data->props ) );

  if( FileOp.isAbsolute( wLoc.getlclib( data->props ) ) ) {
    pLib = LibOp.inst(wLoc.getlclib( data->props ));
  }
  else {
    char* libpath = StrOp.fmt( "%s%c%s", AppOp.getLibPath(), SystemOp.getFileSeparator(), wLoc.getlclib( data->props ) );
    pLib = LibOp.inst( libpath );
    StrOp.free( libpath );
  }

  if (pLib == NULL)
    return False;
  pInitFun = (LPFNGETLCDIRINT)LibOp.getProc( pLib, "rocGetLcDrInt" );
  if (pInitFun == NULL)
    return False;

  data->driver = pInitFun( inst, AppOp.getModel(), TraceOp.get(), AppOp.getIniNode( wCtrl.name() ) );

  return True;
}


static int _getAddress( iOLoc loc ) {
  iOLocData data = Data(loc);
  return wLoc.getaddr( data->props );
}
static int _getSecAddress( iOLoc loc ) {
  iOLocData data = Data(loc);
  return wLoc.getsecaddr( data->props );
}
static const char* _getIdent( iOLoc loc ) {
  iOLocData data = Data(loc);
  return wLoc.getidentifier( data->props );
}


static void __initSBTmap( iOLoc loc ) {
  iOLocData data = Data(loc);
  iONode sbt = NodeOp.findNode( data->props, wSBT.name() );
  MapOp.clear(data->sbtMap);
  while( sbt != NULL ) {
    char* key  = NULL;
    if( wSBT.gettrain(sbt) != NULL && StrOp.len(wSBT.gettrain(sbt)) > 0 )
      key  = StrOp.fmt("%s-%s", wSBT.getbk(sbt), wSBT.gettrain(sbt));
    TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "add SBT record with keys [%s][%s]", wSBT.getbk(sbt), key==NULL?"":key);

    MapOp.put( data->sbtMap, wSBT.getbk(sbt), (obj)sbt );
    if( key != NULL ) {
      MapOp.put( data->sbtMap, key, (obj)sbt );
      StrOp.free(key);
    }
    sbt = NodeOp.findNextNode( data->props, sbt );
  };
}

static void __initBBTmap( iOLoc loc ) {
  iOLocData data = Data(loc);
  iONode bbt = NodeOp.findNode( data->props, wBBT.name() );
  int bbtkey = wLoc.getbbtkey(data->props);
  MapOp.clear(data->bbtMap);
  while( bbt != NULL ) {
    char* key  = NULL;
    char* keyV = NULL;
    if( bbtkey == 3 ) {
      key  = StrOp.fmt("%s-%d", wBBT.getbk(bbt), wBBT.getspeed(bbt));
      keyV = StrOp.fmt("%s-%d", wBBT.getbk(bbt), wBBT.getspeed(bbt));
    }
    else if( bbtkey == 2 ) {
      key  = StrOp.fmt("%s-%s", wBBT.getbk(bbt), wBBT.getroute(bbt));
      keyV = StrOp.fmt("%s-%s-%d", wBBT.getbk(bbt), wBBT.getroute(bbt), wBBT.getspeed(bbt));
    }
    else if( bbtkey == 1 ) {
      key  = StrOp.fmt("%s-%s", wBBT.getbk(bbt), wBBT.getfrombk(bbt));
      keyV = StrOp.fmt("%s-%s-%d", wBBT.getbk(bbt), wBBT.getfrombk(bbt), wBBT.getspeed(bbt));
    }
    else {
      key = StrOp.fmt("%s", wBBT.getbk(bbt));
      keyV = StrOp.fmt("%s-%d", wBBT.getbk(bbt), wBBT.getspeed(bbt));
    }

    TraceOp.trc( name, TRCLEVEL_DEBUG, __LINE__, 9999, "add BBT record with key [%s] keytype=%d", key, bbtkey);
    MapOp.put( data->bbtMap, key, (obj)bbt );
    if( wBBT.getspeed(bbt) > 0 )
      MapOp.put( data->bbtMap, keyV, (obj)bbt );
    StrOp.free(key);
    StrOp.free(keyV);
    bbt = NodeOp.findNextNode( data->props, bbt );
  };
  data->bbtEnterBlock = NULL;
  data->bbtInBlock    = NULL;
  data->bbtEnterSpeed = 0;
  data->bbtCycleSpeed = 0;
  data->bbtEnter      = 0;
  data->bbtIn         = 0;
  data->bbtAtMinSpeed = False;
}

static void __initCVmap( iOLoc loc ) {
  iOLocData data = Data(loc);
  iONode cv = NodeOp.findNode( data->props, wCVByte.name() );
  MapOp.clear(data->cvMap);
  while( cv != NULL ) {
    char* key = StrOp.fmt( "%d", wCVByte.getnr( cv ) );
    MapOp.put( data->cvMap, key, (obj)cv );
    StrOp.free( key );
    cv = NodeOp.findNextNode( data->props, cv );
  };
}

static int _getCV( iOLoc loc, int nr ) {
  iOLocData data = Data(loc);
  int val = -1;
  char* key = StrOp.fmt( "%d", nr );
  iONode cv = (iONode)MapOp.get( data->cvMap, key );
  StrOp.free( key );
  if( cv != NULL )
    val = wCVByte.getvalue( cv );
  return val;
}


static void _setCV( iOLoc loc, int nr, int value ) {
  iOLocData data = Data(loc);
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
    wLoc.setcmd( clone, wModelCmd.modify );
    AppOp.broadcastEvent( clone );
  }
}

/**
 * swap placing to run in defaults routes after reaching an terminal station
 */
static void _swapPlacing( iOLoc loc, iONode cmd, Boolean consist, Boolean direct ) {
  iOLocData data = Data(loc);
  Boolean swap = False;

  if( cmd != NULL )
    swap = wLoc.isplacing( cmd );

  if( cmd == NULL || !NodeOp.findAttr(cmd, "placing"))
    swap = !wLoc.isplacing( data->props );

  if( direct ) {
    __theSwap(loc, swap, consist, cmd);
  }
  else if( data->runner != NULL ) {
    iOMsg msg = MsgOp.inst( NULL, swap_event );
    if( wLoc.getswaptimer(data->props) > 0 ) {
      if( wLoc.getswaptimer(data->props) > 1000 )
        wLoc.setswaptimer(data->props, 1000 );
      TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "%s: sync swap sleep %d", wLoc.getid(data->props), wLoc.getswaptimer(data->props));
      ThreadOp.sleep(wLoc.getswaptimer(data->props));
    }
    MsgOp.setTimer( msg, 0 );
    MsgOp.setEvent( msg, swap_event );
    if( cmd == NULL )
      MsgOp.setUsrData(msg, NULL, (swap ? 0x01:0x00) | (consist ? 0x02:0x00) );
    else
      MsgOp.setUsrData(msg, (iONode)NodeOp.base.clone(cmd), (swap ? 0x01:0x00) | (consist ? 0x02:0x00) );

    ThreadOp.post( data->runner, (obj)msg );
  }
}


/**
 * get the direction regarding the placing of the locomotive
 */
static Boolean _getDir( iOLoc loc ) {
  iOLocData data = Data(loc);
  Boolean dir     = wLoc.isdir( data->props );
  Boolean placing = wLoc.isplacing( data->props );

  if( !placing ) {
    /* the placing flag is handled at engine level, so the logic does not care... */
    /* dir = !dir; */
  }

  return dir;
}


/**
 * get the placing of the locomotive
 */
static Boolean _getPlacing( iOLoc loc ) {
  iOLocData data = Data(loc);
  return wLoc.isplacing( data->props );
}


static int _getV( iOLoc loc ) {
  iOLocData data = Data(loc);
  return data->drvSpeed;
}


static int _saveSpeed( iOLoc loc, Boolean reset ) {
  iOLocData data = Data(loc);
  if( reset ) {
    int savedSpeed = data->savedSpeed;
    data->savedSpeed = 0;
    return savedSpeed;
  }
  data->savedSpeed = data->drvSpeed;
  return data->savedSpeed;
}

static void _fifoTop( iOLoc loc ) {
  iOLocData data = Data(loc);
  wLoc.setfifotop(data->props, True);
  __broadcastLocoProps( loc, NULL, NULL, NULL );
}

static const char* _getV_hint( iOLoc loc ) {
  iOLocData data = Data(loc);
  return wLoc.getV_hint( data->props );
}


static Boolean _isAutomode( iOLoc loc ) {
  iOLocData data = Data(loc);
  Boolean isRun = False;
  if( data->driver != NULL )
    isRun = data->driver->isRun( data->driver );
  return (data->go || isRun);
}


static Boolean _isResumeAutomode( iOLoc loc ) {
  iOLocData data = Data(loc);
  return wLoc.isresumeauto( data->props );
}


static Boolean _isShortin( iOLoc loc ) {
  iOLocData data = Data(loc);
  return wLoc.isshortin( data->props );
}


static Boolean _isUseManualRoutes( iOLoc loc ) {
  iOLocData data = Data(loc);
  return wLoc.isusemanualroutes( data->props );
}


static Boolean _isGoManual( iOLoc loc ) {
  iOLocData data = Data(loc);
  return data->gomanual;
}


static Boolean _isManually( iOLoc loc ) {
  iOLocData data = Data(loc);
  return wLoc.ismanually( data->props );
}


static Boolean _isReduceSpeedAtEnter( iOLoc loc ) {
  iOLocData data = Data(loc);
  return wLoc.isreducespeedatenter( data->props );
}


static Boolean _matchIdent( iOLoc loc, const char* ident, const char* ident2, const char* ident3, const char* ident4 ) {
  iOLocData data = Data(loc);
  Boolean match = False;

  if( ident != NULL && StrOp.len(ident) > 0 && StrOp.equals( wLoc.getidentifier( data->props ), ident) )
    match = True;
  else if( ident != NULL && StrOp.len(ident) > 0 && wLoc.getaddr(data->props) == atoi(ident) )
    match = True;
  else if( ident2 != NULL && StrOp.len(ident2) > 0 && StrOp.equals( wLoc.getidentifier( data->props ), ident2) )
    match = True;
  else if( ident2 != NULL && StrOp.len(ident2) > 0 && wLoc.getaddr(data->props) == atoi(ident2) )
    match = True;
  else if( ident3 != NULL && StrOp.len(ident3) > 0 && StrOp.equals( wLoc.getidentifier( data->props ), ident3) )
    match = True;
  else if( ident3 != NULL && StrOp.len(ident3) > 0 && wLoc.getaddr(data->props) == atoi(ident3) )
    match = True;
  else if( ident4 != NULL && StrOp.len(ident4) > 0 && StrOp.equals( wLoc.getidentifier( data->props ), ident4) )
    match = True;
  else if( ident4 != NULL && StrOp.len(ident4) > 0 && wLoc.getaddr(data->props) == atoi(ident4) )
    match = True;
  else {
    /* check consist */
    iOStrTok  consist = StrTokOp.inst( wLoc.getconsist ( data->props ), ',' );
    while( StrTokOp.hasMoreTokens( consist ) ) {
      const char* tok = StrTokOp.nextToken( consist );
      iOLoc consistloc = ModelOp.getLoc( AppOp.getModel(), tok, NULL, False );
      if( consistloc != NULL ) {
        if( ident != NULL && StrOp.len(ident) > 0 && StrOp.equals( ident, LocOp.getIdent(consistloc) ) ) {
          match = True;
          break;
        }
        else if( ident2 != NULL && StrOp.len(ident2) > 0 && StrOp.equals( ident2, LocOp.getIdent(consistloc) ) ) {
          match = True;
          break;
        }
        else if( ident3 != NULL && StrOp.len(ident3) > 0 && StrOp.equals( ident3, LocOp.getIdent(consistloc) ) ) {
          match = True;
          break;
        }
        else if( ident4 != NULL && StrOp.len(ident4) > 0 && StrOp.equals( ident4, LocOp.getIdent(consistloc) ) ) {
          match = True;
          break;
        }
      }
    };
    StrTokOp.base.del( consist );
  }

  if( !match )
    match = __matchTrainIdent(loc, ident, ident2, ident3, ident4);

  return match;
}


static iONode _getFunctionStatus( iOLoc loc, iONode cmd ) {
  iOLocData data = Data(loc);
  /* save the function status: */
  __cpFn2Node(loc, cmd, -1, 0);
  wFunCmd.setf0( cmd, wLoc.isfn(data->props) );
  return cmd;
}


static int _getCarCount( iOLoc loc ) {
  iOLocData data = Data(loc);
  /* save the function status: */
  return wLoc.getnrcars(data->props);
}


static Boolean _getBlockEnterSide( iOLoc loc ) {
  iOLocData data = Data(loc);
  return wLoc.isblockenterside(data->props);
}


static void _setBlockEnterSide( iOLoc loc, Boolean enterside, const char* blockId ) {
  iOLocData data = Data(loc);

  wLoc.setblockenterside(data->props, enterside);
  wLoc.setblockenterid(data->props, blockId!=NULL?blockId:"");
  TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "block[%s] enter side for [%s] set to [%s]",
      blockId!=NULL?blockId:"-", wLoc.getid(data->props), wLoc.isblockenterside( data->props )?"+":"-" );
  ModelOp.setBlockOccupancy( AppOp.getModel(), data->curBlock, wLoc.getid(data->props), False, wLoc.isplacing( data->props) ? 1:2, wLoc.isblockenterside( data->props) ? 1:2, NULL );

  /* Broadcast to clients. */
  if( blockId != NULL )
    __broadcastLocoProps( loc, NULL, NULL, blockId );
  else {
    /*__broadcastLocoProps( loc, NULL, NULL, NULL );*/
    __broadcastLocoProps( loc, NULL, NULL, data->curBlock );
  }
}


static void _swapBlockEnterSide( iOLoc loc, const char* blockId ) {
  iOLocData data = Data(loc);
  LocOp.setBlockEnterSide(loc, !wLoc.isblockenterside(data->props), blockId );
}


static Boolean _trySecondNextBlock( iOLoc inst ) {
  iOLocData data = Data(inst);

  return data->secondnextblock;
}

static Boolean _isCheck2In( iOLoc inst ) {
  iOLocData data = Data(inst);
  return data->check2in;
}

static void _setClass( iOLoc inst, const char* p_Class ) {
  iOLocData data = Data(inst);

  if( wLoc.gettrain( data->props) != NULL && StrOp.len(wLoc.gettrain( data->props)) > 0 ) {
    iOOperator train = ModelOp.getOperator(AppOp.getModel(), wLoc.gettrain( data->props) );
    if( train != NULL ) {
      OperatorOp.setClass(train, p_Class);
    }
  }
  else {
    wLoc.setclass(data->props, p_Class);
    /* Broadcast to clients. */
    AppOp.broadcastEvent( (iONode)NodeOp.base.clone( data->props ) );
  }
}

static void _setMaxKmh( iOLoc inst, int maxkmh ) {
  iOLocData data = Data(inst);
  TraceOp.trc( name, TRCLEVEL_USER1, __LINE__, 9999, "loco [%s] maxkmh=%d", wLoc.getid(data->props), maxkmh);
  data->maxkmh = maxkmh;
}


static iOLoc _inst( iONode props ) {
  iOLoc     loc  = allocMem( sizeof( struct OLoc ) );
  iOLocData data = allocMem( sizeof( struct OLocData ) );

  /* OBase operations */
  MemOp.basecpy( loc, &LocOp, 0, sizeof( struct OLoc ), data );

  data->props = props;
  data->cvMap = MapOp.inst();
  data->secondnextblock = wLoc.issecondnextblock( data->props );
  data->check2in = wLoc.ischeck2in( data->props );
  data->timedfn = -1; /* function 0 is also used */
  data->released = True;
  data->bbtMap = MapOp.inst();
  data->sbtMap = MapOp.inst();
  data->muxEngine = MutexOp.inst( NULL, True );
  data->muxCmd = MutexOp.inst( NULL, True );
  data->destBlock = NULL;

  wLoc.setdestblockid(data->props, "");

  wLoc.setmode(data->props, wLoc.mode_idle);

  wLoc.setfifotop(data->props, False);

  if( wFreeRail.isresetspfx(AppOp.getIni()) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "global reset speed and functions for loco [%s]", wLoc.getid(props));
    wLoc.setV( data->props, 0 );
    wLoc.setfx( data->props, 0 );
    wLoc.setfn( data->props, False );
  }
  else {
    /* reset velocity to zero */
    if( !wLoc.isrestorespeed(data->props)) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "no restore wanted: reset speed for loco [%s]", wLoc.getid(props));
      wLoc.setV( data->props, 0 );
    }
    if( !wLoc.isrestorefx(data->props)) {
      TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "no restore wanted: reset functions for loco [%s]", wLoc.getid(props));
      wLoc.setfx( data->props, 0 );
    }
  }

  if( wLoc.isresetplacing(data->props) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "reset placing and direction to default of loco [%s]", wLoc.getid(props));
    wLoc.setplacing( data->props, True );
    wLoc.setdir( data->props, True );
  }

  data->fn0 = wLoc.isfn(data->props);
  wLoc.setthrottleid( data->props, "" );

  data->manual   = wLoc.ismanual(data->props);
  data->gomanual = wLoc.ismanual(data->props);


  __initCVmap( loc );
  __initBBTmap( loc );
  __initSBTmap( loc );

  ModelOp.addSysEventListener( AppOp.getModel(), (obj)loc );

  /*data->driver = (iILcDriverInt)LcDriverOp.inst( loc );*/
  if( wLoc.isshow(data->props) && __loadDriver( loc ) ) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "loco [%s] enterside=[%c]", wLoc.getid(props), wLoc.isblockenterside(props)?'+':'-');
    data->runner = ThreadOp.inst( _getId(loc), &__runner, loc );
    data->run = True;
    ThreadOp.start( data->runner );
  }
  else if(!wLoc.isshow(data->props)) {
    TraceOp.trc( name, TRCLEVEL_INFO, __LINE__, 9999, "loco [%s][%d] is invisible; no runner started", wLoc.getid(props), wLoc.isblockenterside(props));
  }

  instCnt++;

  return loc;
}


/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
#include "rocrail/impl/loc.fm"
/* ----- DO NOT REMOVE OR EDIT THIS INCLUDE LINE! -----*/
