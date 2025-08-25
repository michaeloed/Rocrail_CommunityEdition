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
// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------
#ifdef __GNUG__
    #pragma implementation "rocgui.cpp"
    #pragma interface "rocgui.cpp"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWindows headers)
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include <wx/clipbrd.h>
#include <wx/dataobj.h>
#include <wx/colordlg.h>


#include "rocs/public/node.h"
#include "rocs/public/str.h"
#include "rocs/public/strtok.h"
#include "rocs/public/trace.h"
#include "rocs/public/mem.h"
#include "rocs/public/system.h"
#include "rocview/public/guiapp.h"
#include "rocview/public/base.h"
#include "rocview/public/item.h"

#include "rocview/dialogs/switchdialog.h"
#include "rocview/dialogs/signaldialog.h"
#include "rocview/dialogs/outputdialog.h"
#include "rocview/dialogs/feedbackdialog.h"
#include "rocview/dialogs/locdialog.h"
#include "rocview/dialogs/blockdialog.h"
#include "rocview/dialogs/scheduledialog.h"
#include "rocview/dialogs/trackdialog.h"
#include "rocview/dialogs/turntabledialog.h"
#include "rocview/dialogs/textdialog.h"
#include "rocview/dialogs/locseldlg.h"
#include "rocview/dialogs/seltabdlg.h"
#include "rocview/dialogs/routedialog.h"
#include "rocview/dialogs/stagedlg.h"
#include "rocview/dialogs/toursdlg.h"
#include "rocview/dialogs/gotodlg.h"

#include "rocrail/wrapper/public/AutoCmd.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/Plan.h"
#include "rocrail/wrapper/public/Item.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/Stage.h"
#include "rocrail/wrapper/public/StageSection.h"
#include "rocrail/wrapper/public/Schedule.h"
#include "rocrail/wrapper/public/Tour.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/Track.h"
#include "rocrail/wrapper/public/Turntable.h"
#include "rocrail/wrapper/public/TTTrack.h"
#include "rocrail/wrapper/public/SelTab.h"
#include "rocrail/wrapper/public/SelTabPos.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/FeedbackStatistic.h"
#include "rocrail/wrapper/public/Text.h"
#include "rocrail/wrapper/public/ZLevel.h"
#include "rocrail/wrapper/public/Route.h"
#include "rocrail/wrapper/public/ScheduleEntry.h"
#include "rocrail/wrapper/public/Location.h"
#include "rocrail/wrapper/public/LocationList.h"
#include "rocrail/wrapper/public/ActionCtrl.h"
#include "rocrail/wrapper/public/Program.h"
#include "rocrail/wrapper/public/Color.h"

#include "rocview/wrapper/public/Gui.h"
#include "rocview/wrapper/public/PlanPanel.h"

#include <math.h>
#include <stdio.h>

#include <wx/dcbuffer.h>

static double PI25DT = 3.141592653589793238462643;

enum {
    // menu items
    ME_Props = 1,
    ME_ItemHelp,
    ME_Rotate,
    ME_North,
    ME_East,
    ME_South,
    ME_West,
    ME_Delete,
    ME_Copy,
    ME_Type,
    ME_CmdStraight,
    ME_CmdTurnout,
    ME_CmdLeft,
    ME_CmdRight,
    ME_CmdSignalManual,
    ME_CmdSignalAuto,
    ME_CmdSignalRed,
    ME_CmdSignalGreen,
    ME_CmdSignalYellow,
    ME_CmdSignalWhite,
    ME_Loc,
    ME_UnLoc,
    ME_LocGoTo,
    ME_LocSchedule,
    ME_LocTour,
    ME_LocGo,
    ME_LocSwap,
    ME_LocSwapBlockSide,
    ME_LocGoManual,
    ME_LocGoVirtual,
    ME_LocStop,
    ME_LocReset,
    ME_LocResetAll,
    ME_LocMIC,
    ME_LocActivate,
    ME_LocDeActivate,
    ME_CloseBlock,
    ME_OpenBlock,
    ME_ResetWC,
    ME_ResetFiFo,
    ME_CloseExitBlock,
    ME_OpenExitBlock,
    ME_AcceptIdent,
    ME_ResetWheelcounter,
    ME_ResetSensor,
    ME_SetSensorLoad,
    ME_IdentifierFwd,
    ME_IdentifierRev,
    ME_OutputColor,
    ME_Compress,
    ME_Info,
    ME_Timer,
    ME_TTLightOn,
    ME_TTLightOff,
    ME_TTNext,
    ME_TTPrev,
    ME_TTCalibrate,
    ME_TT180,
    ME_TTTrack, // Should be the last one in the enum list
               // because ME_TTTrack+0...ME_TTTrack+47 are also used!!!.
    ME_ScheduleGo = ME_TTTrack + 48,
    ME_FYGo = ME_ScheduleGo + 20,
    ME_TTGo = ME_FYGo + 10,
    ME_CmdSignalAspect = ME_TTGo + 10,
    ME_CmdAction = ME_CmdSignalAspect + 20, // 10 command actions
    ME_CmdSignalAspectName = ME_CmdAction + 10, // 16 aspect names

};

BEGIN_EVENT_TABLE(Symbol, wxWindow)
  EVT_PAINT        (Symbol::OnPaint     )
  EVT_LEFT_UP      (Symbol::OnLeftUp    )
  EVT_LEFT_DOWN    (Symbol::OnLeftDown  )
  EVT_MOTION       (Symbol::OnMotion    )
  EVT_RIGHT_UP     (Symbol::OnPopup     )
  EVT_RIGHT_DOWN   (Symbol::OnRightDown )
  EVT_ENTER_WINDOW (Symbol::OnMouseEnter)
  EVT_LEAVE_WINDOW (Symbol::OnMouseLeave)

  EVT_TIMER (ME_Timer, Symbol::OnTimer)

  EVT_LEFT_DCLICK(Symbol::OnLeftDClick  )

  EVT_MENU     (ME_Props  , Symbol::OnProps  )
  EVT_MENU     (ME_ItemHelp  , Symbol::OnHelp  )
  EVT_MENU     (ME_Loc    , Symbol::OnLoc    )
  EVT_MENU     (ME_UnLoc  , Symbol::OnUnLoc  )
  EVT_MENU     (ME_PanelSelect , Symbol::OnSelect )
  EVT_MENU     (ME_Rotate , Symbol::OnRotate )
  EVT_MENU     (ME_North , Symbol::OnRotate )
  EVT_MENU     (ME_East , Symbol::OnRotate )
  EVT_MENU     (ME_South , Symbol::OnRotate )
  EVT_MENU     (ME_West , Symbol::OnRotate )
  EVT_MENU     (ME_Delete , Symbol::OnDelete )
  EVT_MENU     (ME_Copy , Symbol::OnCopy )
  EVT_MENU     (ME_Type, Symbol::OnType)
  EVT_MENU     (ME_LocGoTo, Symbol::OnLocGoTo)
  EVT_MENU     (ME_LocSchedule, Symbol::OnLocSchedule)
  EVT_MENU     (ME_LocTour, Symbol::OnLocTour)
  EVT_MENU     (ME_LocGo  , Symbol::OnLocGo  )
  EVT_MENU     (ME_LocSwap  , Symbol::OnLocSwap  )
  EVT_MENU     (ME_LocSwapBlockSide  , Symbol::OnLocSwapBlockSide  )
  EVT_MENU     (ME_ScheduleGo, Symbol::OnScheduleGo)
  EVT_MENU     (ME_FYGo, Symbol::OnFYGo)
  EVT_MENU     (ME_TTGo, Symbol::OnTTGo)
  EVT_MENU     (ME_LocGoManual  , Symbol::OnLocGoManual  )
  EVT_MENU     (ME_LocGoVirtual  , Symbol::OnLocGoVirtual  )
  EVT_MENU     (ME_LocStop, Symbol::OnLocStop)
  EVT_MENU     (ME_LocReset, Symbol::OnLocReset)
  EVT_MENU     (ME_LocResetAll, Symbol::OnLocResetAll)
  EVT_MENU     (ME_LocMIC  , Symbol::OnLocMIC  )
  EVT_MENU     (ME_LocActivate, Symbol::OnLocActivate  )
  EVT_MENU     (ME_LocDeActivate, Symbol::OnLocDeActivate  )
  EVT_MENU     (ME_CloseBlock, Symbol::OnCloseBlock)
  EVT_MENU     (ME_CloseExitBlock, Symbol::OnCloseExitBlock)
  EVT_MENU     (ME_OpenBlock, Symbol::OnOpenBlock)
  EVT_MENU     (ME_ResetWC, Symbol::OnResetWC)
  EVT_MENU     (ME_ResetFiFo, Symbol::OnResetFiFo)
  EVT_MENU     (ME_OpenExitBlock, Symbol::OnOpenExitBlock)
  EVT_MENU     (ME_AcceptIdent, Symbol::OnAcceptIdent)

  EVT_MENU     (ME_CmdStraight, Symbol::OnCmdStraight )
  EVT_MENU     (ME_CmdTurnout, Symbol::OnCmdTurnout )
  EVT_MENU     (ME_CmdLeft, Symbol::OnCmdLeft )
  EVT_MENU     (ME_CmdRight, Symbol::OnCmdRight )
  EVT_MENU     (ME_CmdAction + 0, Symbol::OnCmdAction )
  EVT_MENU     (ME_CmdAction + 1, Symbol::OnCmdAction )
  EVT_MENU     (ME_CmdAction + 2, Symbol::OnCmdAction )
  EVT_MENU     (ME_CmdAction + 3, Symbol::OnCmdAction )
  EVT_MENU     (ME_CmdAction + 4, Symbol::OnCmdAction )
  EVT_MENU     (ME_CmdAction + 5, Symbol::OnCmdAction )
  EVT_MENU     (ME_CmdAction + 6, Symbol::OnCmdAction )
  EVT_MENU     (ME_CmdAction + 7, Symbol::OnCmdAction )
  EVT_MENU     (ME_CmdAction + 8, Symbol::OnCmdAction )
  EVT_MENU     (ME_CmdAction + 9, Symbol::OnCmdAction )

  EVT_MENU     (ME_CmdSignalAuto, Symbol::OnCmdSignalAuto )
  EVT_MENU     (ME_CmdSignalManual, Symbol::OnCmdSignalManual )
  EVT_MENU     (ME_CmdSignalRed, Symbol::OnCmdSignalRed )
  EVT_MENU     (ME_CmdSignalYellow, Symbol::OnCmdSignalYellow )
  EVT_MENU     (ME_CmdSignalGreen, Symbol::OnCmdSignalGreen )
  EVT_MENU     (ME_CmdSignalWhite, Symbol::OnCmdSignalWhite )
  EVT_MENU     (ME_CmdSignalAspect, Symbol::OnCmdSignalAspect )

  EVT_MENU     (ME_CmdSignalAspectName+0, Symbol::OnCmdSignalAspectName)
  EVT_MENU     (ME_CmdSignalAspectName+1, Symbol::OnCmdSignalAspectName)
  EVT_MENU     (ME_CmdSignalAspectName+2, Symbol::OnCmdSignalAspectName)
  EVT_MENU     (ME_CmdSignalAspectName+3, Symbol::OnCmdSignalAspectName)
  EVT_MENU     (ME_CmdSignalAspectName+4, Symbol::OnCmdSignalAspectName)
  EVT_MENU     (ME_CmdSignalAspectName+5, Symbol::OnCmdSignalAspectName)
  EVT_MENU     (ME_CmdSignalAspectName+6, Symbol::OnCmdSignalAspectName)
  EVT_MENU     (ME_CmdSignalAspectName+7, Symbol::OnCmdSignalAspectName)
  EVT_MENU     (ME_CmdSignalAspectName+8, Symbol::OnCmdSignalAspectName)
  EVT_MENU     (ME_CmdSignalAspectName+9, Symbol::OnCmdSignalAspectName)
  EVT_MENU     (ME_CmdSignalAspectName+10, Symbol::OnCmdSignalAspectName)
  EVT_MENU     (ME_CmdSignalAspectName+11, Symbol::OnCmdSignalAspectName)
  EVT_MENU     (ME_CmdSignalAspectName+12, Symbol::OnCmdSignalAspectName)
  EVT_MENU     (ME_CmdSignalAspectName+13, Symbol::OnCmdSignalAspectName)
  EVT_MENU     (ME_CmdSignalAspectName+14, Symbol::OnCmdSignalAspectName)
  EVT_MENU     (ME_CmdSignalAspectName+15, Symbol::OnCmdSignalAspectName)

  EVT_MENU     (ME_Info, Symbol::OnInfo)
  EVT_MENU     (ME_ResetWheelcounter, Symbol::OnResetWheelcounter)
  EVT_MENU     (ME_ResetSensor, Symbol::OnResetSensor)
  EVT_MENU     (ME_IdentifierFwd, Symbol::OnIdentifierFwd)
  EVT_MENU     (ME_IdentifierRev, Symbol::OnIdentifierRev)
  EVT_MENU     (ME_SetSensorLoad, Symbol::OnSetSensorLoad)
  EVT_MENU     (ME_Compress, Symbol::OnCompress)
  EVT_MENU     (ME_OutputColor, Symbol::OnOutputColor)

  EVT_MENU     (ME_FYGo+0, Symbol::OnFYGo)
  EVT_MENU     (ME_FYGo+1, Symbol::OnFYGo)
  EVT_MENU     (ME_FYGo+2, Symbol::OnFYGo)
  EVT_MENU     (ME_FYGo+3, Symbol::OnFYGo)

  EVT_MENU     (ME_TTGo+0, Symbol::OnTTGo)
  EVT_MENU     (ME_TTGo+1, Symbol::OnTTGo)
  EVT_MENU     (ME_TTGo+2, Symbol::OnTTGo)
  EVT_MENU     (ME_TTGo+3, Symbol::OnTTGo)

  EVT_MENU     (ME_ScheduleGo+0, Symbol::OnScheduleGo)
  EVT_MENU     (ME_ScheduleGo+1, Symbol::OnScheduleGo)
  EVT_MENU     (ME_ScheduleGo+2, Symbol::OnScheduleGo)
  EVT_MENU     (ME_ScheduleGo+3, Symbol::OnScheduleGo)
  EVT_MENU     (ME_ScheduleGo+4, Symbol::OnScheduleGo)
  EVT_MENU     (ME_ScheduleGo+5, Symbol::OnScheduleGo)
  EVT_MENU     (ME_ScheduleGo+6, Symbol::OnScheduleGo)
  EVT_MENU     (ME_ScheduleGo+7, Symbol::OnScheduleGo)
  EVT_MENU     (ME_ScheduleGo+8, Symbol::OnScheduleGo)
  EVT_MENU     (ME_ScheduleGo+9, Symbol::OnScheduleGo)
  EVT_MENU     (ME_ScheduleGo+10, Symbol::OnScheduleGo)
  EVT_MENU     (ME_ScheduleGo+11, Symbol::OnScheduleGo)
  EVT_MENU     (ME_ScheduleGo+12, Symbol::OnScheduleGo)
  EVT_MENU     (ME_ScheduleGo+13, Symbol::OnScheduleGo)
  EVT_MENU     (ME_ScheduleGo+14, Symbol::OnScheduleGo)
  EVT_MENU     (ME_ScheduleGo+15, Symbol::OnScheduleGo)
  EVT_MENU     (ME_ScheduleGo+16, Symbol::OnScheduleGo)
  EVT_MENU     (ME_ScheduleGo+17, Symbol::OnScheduleGo)
  EVT_MENU     (ME_ScheduleGo+18, Symbol::OnScheduleGo)
  EVT_MENU     (ME_ScheduleGo+19, Symbol::OnScheduleGo)

  EVT_MENU     (ME_TTLightOn, Symbol::OnTTLight)
  EVT_MENU     (ME_TTLightOff, Symbol::OnTTLight)
  EVT_MENU     (ME_TTNext, Symbol::OnTTNext)
  EVT_MENU     (ME_TTPrev, Symbol::OnTTPrev)
  EVT_MENU     (ME_TT180, Symbol::OnTT180)
  EVT_MENU     (ME_TTCalibrate, Symbol::OnTTCalibrate)

  EVT_MENU     (ME_TTTrack+0, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+1, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+2, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+3, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+4, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+5, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+6, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+7, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+8, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+9, Symbol::OnTTTrack)

  EVT_MENU     (ME_TTTrack+10, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+11, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+12, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+13, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+14, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+15, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+16, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+17, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+18, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+19, Symbol::OnTTTrack)

  EVT_MENU     (ME_TTTrack+20, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+21, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+22, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+23, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+24, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+25, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+26, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+27, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+28, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+29, Symbol::OnTTTrack)

  EVT_MENU     (ME_TTTrack+30, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+31, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+32, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+33, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+34, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+35, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+36, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+37, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+38, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+39, Symbol::OnTTTrack)

  EVT_MENU     (ME_TTTrack+40, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+41, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+42, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+43, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+44, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+45, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+46, Symbol::OnTTTrack)
  EVT_MENU     (ME_TTTrack+47, Symbol::OnTTTrack)
END_EVENT_TABLE()

// ----------------------------------------------------------------------------
// Item
// ----------------------------------------------------------------------------

Symbol::Symbol( PlanPanel *parent, iONode props, int itemsize, int z, double scale, double bktext )
             : wxWindow(parent, -1, wxDefaultPosition, wxDefaultSize, 0 )
{
  m_Z = z;
  m_Scale = scale;
  m_Bktext = bktext;
  m_ItemSize = itemsize;
  m_PlanPanel = parent;
  m_Props = props;
  m_isDragged = false;
  m_locoIsDropped = false;
  //m_RouteID = NULL;
  m_locidStr = NULL;
  m_Timer = NULL;
  m_RotateSym = False;
  m_DandD = false;
  m_dragX = 0;
  m_dragY = 0;
  m_Tip = NULL;

  SetBackgroundStyle(wxBG_STYLE_CUSTOM);

  int itemidps = 7;
  int textps = 10;
  iONode planpanelIni = wGui.getplanpanel(wxGetApp().getIni());
  if( planpanelIni != NULL ) {
    itemidps = wPlanPanel.getitemidps(planpanelIni);
    textps = wPlanPanel.gettextps(planpanelIni);
  }

  m_Renderer = new SymbolRenderer( props, this, wxGetApp().getFrame()->getSymMap(), itemidps, textps );
  modelEvent(m_Props, true);

  if( StrOp.equals( wTurntable.name(), NodeOp.getName( m_Props ) ) ) {
    bridgepos = 0.0;
    iONode track = wTurntable.gettrack( m_Props );
    while( track != NULL ) {
      m_PlanPanel->addItem( NodeOp.getName(track), wTTTrack.getposfb( track ), this );
      track = wTurntable.nexttrack( m_Props, track );
    }
  }

  m_BlockDrop = new BlockDrop(m_Props, this);
  SetDropTarget(m_BlockDrop);

  // define accelerator keys for some frequently used functions

  wxAcceleratorEntry acc_entries[11];
  acc_entries[ 0].Set(wxACCEL_ALT, (int) 'R', ME_Rotate);
  acc_entries[ 1].Set(wxACCEL_ALT, (int) 'r', ME_Rotate);
  acc_entries[ 2].Set(wxACCEL_ALT, (int) 'D', ME_Delete);
  acc_entries[ 3].Set(wxACCEL_ALT, (int) 'd', ME_Delete);
  acc_entries[ 4].Set(wxACCEL_ALT, (int) 't', ME_Type);
  acc_entries[ 5].Set(wxACCEL_ALT, (int) 'T', ME_Type);
  acc_entries[ 6].Set(wxACCEL_NORMAL, (int) 't', ME_Type);
  acc_entries[ 7].Set(wxACCEL_NORMAL, (int) 'T', ME_Type);
  acc_entries[ 8].Set(wxACCEL_NORMAL, WXK_RIGHT, ME_Rotate);
  acc_entries[ 9].Set(wxACCEL_NORMAL, WXK_LEFT, ME_Rotate);
  acc_entries[10].Set(wxACCEL_NORMAL, WXK_DELETE, ME_Delete);
  wxAcceleratorTable m_accel(11, acc_entries);
  this->SetAcceleratorTable(m_accel);

}

void Symbol::setPanel(PlanPanel* panel){
  m_PlanPanel = panel;
  Reparent(panel);
  sizeToScale();

}


void Symbol::checkSpeakAction(iONode node) {
  const char* bklist = wGui.getspeak4block(wxGetApp().getIni());

  if( wText.getblock(node) == NULL || StrOp.len(wText.getblock(node)) == 0 ) {
    return;
  }

  TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "check speak action: is [%s] in [%s]", wText.getblock(node), bklist );

  iOStrTok tok = StrTokOp.inst( bklist, ',' );
  int idx = 0;
  const char* bk = StrTokOp.nextToken(tok);

  while( bk != NULL ) {
    if( StrOp.equals( "*", bk ) || StrOp.equals( wText.getblock(node), bk ) ) {
      const char* speak = wGui.getspeakcmd(wxGetApp().getIni());
      if( speak != NULL && StrOp.len( speak ) > 0 ) {
        char* s = StrOp.fmt("%s \"%s\"", speak, wText.gettext(node) );
        TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "executing [%s]", s );
        SystemOp.system( s, True, False );
        StrOp.free(s);
      }
      break;
    }
    bk = StrTokOp.nextToken(tok);
  };
  StrTokOp.base.del( tok );
}


bool BlockDrop::OnDropText(wxCoord x, wxCoord y, const wxString& data) {
  if( wxGetApp().isOffline() ) {
    TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "D&D is not supported in OFFLINE mode" );
    return false;
  }

  TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "D&D data [%s][%d]", (const char*)data.mb_str(wxConvUTF8), data.Len() );
  /* Inform RocRail... */
  iOStrTok tok = StrTokOp.inst((const char*)data.mb_str(wxConvUTF8), ':');
  const char* dropcmd = StrTokOp.nextToken(tok);
  const char* dropid  = StrTokOp.nextToken(tok);
  const char* fromid  = "";

  TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "D&D command [%s] for ID [%s]", dropcmd, dropid );

  if( StrTokOp.hasMoreTokens(tok) ) {
    fromid  = StrTokOp.nextToken(tok);

    if( StrOp.equals( wBlock.getid(m_Props), fromid) ) {
      TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "D&D on same block: %s", fromid );
      StrTokOp.base.del(tok); // Clean up.
      return false;
    }
  }

  bool ok = false;

  if( StrOp.equals( "bus", dropcmd ) ) {
    TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "D&D: set bus to %s", dropid );

    if( NodeOp.findAttr(m_Props, "addr") || NodeOp.findAttr(m_Props, "addr1") ||
        StrOp.equals(wSignal.name(), NodeOp.getName(m_Props) ) || StrOp.equals(wSwitch.name(), NodeOp.getName(m_Props) ) ||
        StrOp.equals(wTurntable.name(), NodeOp.getName(m_Props) ) || StrOp.equals(wSelTab.name(), NodeOp.getName(m_Props) ) ||
        StrOp.equals(wOutput.name(), NodeOp.getName(m_Props) ) || StrOp.equals(wFeedback.name(), NodeOp.getName(m_Props) )
        )
    {
      wItem.setbus(m_Props, atoi(dropid));

      if( StrOp.len(fromid) > 0 ) {
        TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "D&D: set address to %s", fromid );
        if( StrOp.equals(wSwitch.name(), NodeOp.getName(m_Props) ) )
          wSwitch.setaddr1(m_Props, atoi(fromid));
        else
          wItem.setaddr(m_Props, atoi(fromid));
      }

      if( StrTokOp.hasMoreTokens(tok) ) {
        const char* porttype  = StrTokOp.nextToken(tok);
        if( StrOp.len(porttype) > 0 ) {
          TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "D&D: set porttype to %s", porttype );
          wSwitch.setporttype(m_Props, atoi(porttype));
          wSwitch.setaccessory(m_Props, False);
          if( StrOp.equals(wSwitch.name(), NodeOp.getName(m_Props) ) && wSwitch.getporttype(m_Props) == wProgram.porttype_servo ) {
            wSwitch.setsinglegate(m_Props, True);
          }
        }
      }

      if( StrTokOp.hasMoreTokens(tok) ) {
        const char* iid  = StrTokOp.nextToken(tok);
        TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "D&D: set iid to %s", iid );
        wItem.setiid(m_Props, iid);
      }

      if( !wxGetApp().isStayOffline() ) {
        /* Notify RocRail. */
        iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
        wModelCmd.setcmd( cmd, wModelCmd.modify );
        NodeOp.addChild( cmd, (iONode)m_Props->base.clone( m_Props ) );
        wxGetApp().sendToRocrail( cmd );
        cmd->base.del(cmd);
      }
      else {
        wxGetApp().setLocalModelModified(true);
      }
    }
  }
  else if( StrOp.equals( "moveto", dropcmd ) ) {
    if( StrOp.equals( wBlock.name(), NodeOp.getName( m_Props ) ) ||
        (StrOp.equals( wTurntable.name(), NodeOp.getName( m_Props ) ) && wTurntable.isembeddedblock(m_Props)) )
    {
      TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "D&D: move from %s to %s", fromid, wBlock.getid(m_Props) );
      m_Parent->m_DandD = true;
      iONode cmd = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
      wBlock.setid( cmd, wBlock.getid( m_Props ) );
      wBlock.setlocid( cmd, "" );
      wBlock.setcmd( cmd, wBlock.loc );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);

      cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
      wLoc.setid( cmd, dropid );
      wLoc.setcmd( cmd, wLoc.block );
      wLoc.setblockid( cmd, wBlock.getid( m_Props ) );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
      ok = true;

    }
  }
  else if( StrOp.equals( "blocktrip", dropcmd ) ) {
    if( StrOp.equals( wBlock.name(), NodeOp.getName( m_Props ) ) ||
          (StrOp.equals( wTurntable.name(), NodeOp.getName( m_Props ) ) && wTurntable.isembeddedblock(m_Props)) )
    {
      iONode cmd = NULL;
      /* flash the block */
      const char* blockloc = wBlock.getlocid(m_Props);

      TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "D&D: go from %s to %s (blocktrip)", fromid, wBlock.getid(m_Props) );

      /* add block to trip */
      cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
      wLoc.setid( cmd, dropid );
      wLoc.setcmd( cmd, wLoc.addblock2trip );
      wLoc.setblockid( cmd, wBlock.getid( m_Props ) );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);

      ok = true;
    }
  }
  else if( StrOp.equals( wBlock.name(), NodeOp.getName( m_Props ) ) ||
        (StrOp.equals( wTurntable.name(), NodeOp.getName( m_Props ) ) && wTurntable.isembeddedblock(m_Props)) )
  {
    if( wxGetApp().getFrame()->isAutoMode() ) {
      iONode cmd = NULL;
      /* flash the block */
      const char* blockloc = wBlock.getlocid(m_Props);

      TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "D&D: go from %s to %s", fromid, wBlock.getid(m_Props) );

      /* go to block */
      cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
      wLoc.setid( cmd, dropid );
      wLoc.setcmd( cmd, wLoc.gotoblock );
      wLoc.setblockid( cmd, wBlock.getid( m_Props ) );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);

      /* loco go */
      cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
      wLoc.setid( cmd, dropid );
      wLoc.setcmd( cmd, wLoc.go );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
    }
    ok = true;

  }
  else {
    TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "D&Dis not possible" );
  }

  m_Parent->locoDropped();

  tok->base.del(tok);
  return ok;
}

void Symbol::sizeToScale() {
  int x_off, y_off;
  m_PlanPanel->GetViewStart( &x_off, &y_off );

  int z = wItem.getz( m_Props );

  const char* name = NodeOp.getName( m_Props );

  const char* mod_ori = wItem.getori(m_Props);
  const char* ori     = NodeOp.getStr(m_Props, "prev_ori", mod_ori);
  if( wxGetApp().isModView() || !wxGetApp().isForceTabView() || wxGetApp().isTabViewRotated() ) {
    ori = mod_ori;
  }

  if( m_Z != z ) {
    Show( false );
    TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "item %s, %s: z level does not match %d!=%d",
        name, wItem.getid( m_Props ), m_Z, z );
  }
  else if( StrOp.equals( wOutput.name(), name ) || StrOp.equals( wFeedback.name(), name ) ||
           StrOp.equals( wRoute.name(), name ) || StrOp.equals( wBlock.name(), name ) || StrOp.equals( wStage.name(), name ) ) {
    TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "set show to %d for %s, %s in level %d",
        wOutput.isshow(m_Props), name, wItem.getid( m_Props ), m_Z);
    Show(wItem.isshow(m_Props));
  }
  else {
    Show(true);
  }

  int cx = 1;
  int cy = 1;
  double c = getSize();
  m_Renderer->sizeToScale( c, m_Scale, m_Bktext, &cx, &cy, ori );

  SetSize( (int)(c*cx), (int)(c*cy) );
  setPosition();
}

void Symbol::blockEvent( const char* id ) {
  if( StrOp.equals( wTrack.name(), NodeOp.getName( m_Props ) ) ||
      StrOp.equals( wSignal.name(), NodeOp.getName( m_Props ) ) ||
      StrOp.equals( wSwitch.name(), NodeOp.getName( m_Props ) ) ||
      StrOp.equals( wOutput.name(), NodeOp.getName( m_Props ) ) ||
      StrOp.equals( wFeedback.name(), NodeOp.getName( m_Props ) )) {
    if( StrOp.equals( wTrack.getblockid( m_Props ), id ) ) {
      TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "block[%s] occ id=[%s]", id, wItem.getid(m_Props) );
      Refresh();
    }
  }
}

void Symbol::routeEvent( const char* id, bool locked ) {
  if( StrOp.len(wItem.getrouteids( m_Props )) > 0 && StrOp.find(wItem.getrouteids( m_Props ), id) != NULL ) {
    Refresh();
  }
}

void Symbol::updateLabel() {
  modelEvent(m_Props);
}


const char* Symbol::getId() {
  return wItem.getid( m_Props );
}

iONode Symbol::getProperties() {
  return m_Props;
}

void Symbol::reScale( double scale) {
  m_Scale = scale;
  sizeToScale();
}

void Symbol::disable() {
  m_Props = NULL;
}

void Symbol::OnPaint(wxPaintEvent& event)
{
  const char* name = NodeOp.getName( m_Props );

  wxPaintDC dc(this);
  dc.SetBackground(GetBackgroundColour());
  dc.Clear();

  if( m_Props == NULL )
    return;

  if( !wZLevel.isactive(m_PlanPanel->getZLevel()) && !m_PlanPanel->isModView() )
    return;

  int z = wItem.getz( m_Props );

  if( m_Z == z ) {
    if( StrOp.equals( wOutput.name(), name ) || StrOp.equals( wFeedback.name(), name ) ||
        StrOp.equals( wRoute.name(), name ) || StrOp.equals( wBlock.name(), name ) ) {
      TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "set show to %d for %s", wOutput.isshow(m_Props), name);
      Show(wOutput.isshow(m_Props));
    }

    int cx = m_Renderer->getcx();
    int cy = m_Renderer->getcy();
    bool occupied = false;
    bool actroute = false;
    int status = 0;

    iONode ini = wGui.getplanpanel(wxGetApp().getIni());
    if( wPlanPanel.isprocessrouteevents(ini) ) {
      TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "check actroute for %s...", wItem.getid(m_Props));
      if( StrOp.len( wItem.getrouteids( m_Props ) ) > 0 ) {
        iOStrTok tok = StrTokOp.inst( wItem.getrouteids( m_Props ), ',' );

        const char* routeid = StrTokOp.nextToken(tok);

        while( routeid != NULL ) {
          if( m_PlanPanel->isRouteLocked(routeid ) ) {
            actroute = true;
            break;
          }
          routeid = StrTokOp.nextToken(tok);
        };

        StrTokOp.base.del( tok );
      }
    }

    if( wPlanPanel.isprocessblockevents(ini) ) {
      if( StrOp.equals( NodeOp.getName(m_Props), wTrack.name() ) || StrOp.equals( NodeOp.getName(m_Props), wSignal.name() ) ||
          StrOp.equals( NodeOp.getName(m_Props), wFeedback.name() ) || StrOp.equals( NodeOp.getName(m_Props), wSwitch.name() )  ||
          StrOp.equals( NodeOp.getName(m_Props), wOutput.name() ) )
      {
        if( StrOp.len( wItem.getblockid( m_Props )) > 0 ) {
          occupied = m_PlanPanel->isBlockOccupied( wItem.getblockid( m_Props ) );
          bool isReserved = m_PlanPanel->isBlockReserved( wItem.getblockid( m_Props ) );
          if( occupied && !isReserved )
            TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "%s-%s is %soccupied by block %s",
              NodeOp.getName(m_Props), wItem.getid( m_Props ), occupied? "":"not ", wItem.getblockid( m_Props ));
          else if( isReserved ) {
            TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "%s-%s is reserved by block %s",
                NodeOp.getName(m_Props), wItem.getid( m_Props ), wItem.getblockid( m_Props ));
            occupied = false;
          }
        }
      }
    }

    if( StrOp.equals( wSelTab.name(), NodeOp.getName( m_Props ) ) ) {
      occupied = wSelTab.ispending(m_Props);
    }
    else if( StrOp.equals( wRoute.name(), NodeOp.getName( m_Props ) ) ) {
      status = wRoute.getstatus(m_Props);
    }

    wxGraphicsContext* gc = NULL;
    if( wGui.isrendergc(wxGetApp().getIni())) {
      gc = wxGraphicsContext::Create(this);
      wxGraphicsMatrix matrix = gc->CreateMatrix();
      matrix.Scale(m_Scale, m_Scale);
      gc->SetTransform(matrix);

  #ifdef wxANTIALIAS_DEFAULT
      gc->SetAntialiasMode(wxANTIALIAS_DEFAULT);
  #endif

      if( wxGetApp().getFrame()->isRaster() ) {
        gc->SetPen( *wxLIGHT_GREY_PEN );
        gc->StrokeLine( 0, 0, (int)(m_ItemSize*cx), 0 );
        gc->StrokeLine( 0, 0, 0, (int)(m_ItemSize*cy) );
      }
    }
    else {
      dc.SetUserScale( m_Scale, m_Scale );
      if( wxGetApp().getFrame()->isRaster() ) {
        dc.SetPen( *wxLIGHT_GREY_PEN );
        dc.DrawLine( 0, 0, (int)(m_ItemSize*cx), 0 );
        dc.DrawLine( 0, 0, 0, (int)(m_ItemSize*cy) );
      }
    }

    const char* mod_ori = wItem.getori(m_Props);
    const char* ori     = NodeOp.getStr(m_Props, "prev_ori", mod_ori);
    if( wxGetApp().isModView() || !wxGetApp().isForceTabView() || wxGetApp().isTabViewRotated() ) {
      ori = mod_ori;
    }

    m_Renderer->drawShape( (wxPaintDC&)dc, gc, occupied, actroute, &bridgepos, wxGetApp().getFrame()->isShowID(), wxGetApp().getFrame()->isShowCounters(), ori, status, m_PlanPanel->isAlt() );
    if( gc != NULL)
      delete gc;
  }
  else {
    Show( false );
  }
}

void Symbol::setPosition() {
  double c = getSize();
  wxSize s = GetSize();

  int x_off, y_off;
  m_PlanPanel->GetViewStart( &x_off, &y_off );

  int org_x = 0;
  int org_y = 0;

  int mod_x = wItem.getx( m_Props );
  int mod_y = wItem.gety( m_Props );

  int z = wItem.getz( m_Props );

  org_x = NodeOp.getInt(m_Props, "prev_x", mod_x);
  org_y = NodeOp.getInt(m_Props, "prev_y", mod_y);

  if( wxGetApp().isModView() || !wxGetApp().isForceTabView() || wxGetApp().isTabViewRotated() ) {
    org_x = mod_x;
    org_y = mod_y;
  }

  double x = org_x - x_off;
  double y = org_y - y_off;
  x = x * c;
  y = y * c;

  SetSize( (int)x, (int)y, s.GetWidth(), s.GetHeight() );
  TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "%s set size: x=%d, y=%d", wItem.getid(m_Props), (int)((double)x*c), (int)((double)y*c) );
}


void Symbol::OnCmdStraight(wxCommandEvent& event) {
  iONode cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
  wSwitch.setid( cmd, wSwitch.getid( m_Props ) );
  wSwitch.setcmd( cmd, wSwitch.straight );
  wSwitch.setmanualcmd( cmd, True );
  wSwitch.setforcecmd( cmd, wxGetKeyState(WXK_CONTROL)?True:False);
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}
void Symbol::OnCmdTurnout(wxCommandEvent& event) {
  iONode cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
  wSwitch.setid( cmd, wSwitch.getid( m_Props ) );
  wSwitch.setcmd( cmd, wSwitch.turnout );
  wSwitch.setmanualcmd( cmd, True );
  wSwitch.setforcecmd( cmd, wxGetKeyState(WXK_CONTROL)?True:False);
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}
void Symbol::OnCmdLeft(wxCommandEvent& event) {
  iONode cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
  wSwitch.setid( cmd, wSwitch.getid( m_Props ) );
  wSwitch.setcmd( cmd, wSwitch.left );
  wSwitch.setmanualcmd( cmd, True );
  wSwitch.setforcecmd( cmd, wxGetKeyState(WXK_CONTROL)?True:False);
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}
void Symbol::OnCmdRight(wxCommandEvent& event) {
  iONode cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
  wSwitch.setid( cmd, wSwitch.getid( m_Props ) );
  wSwitch.setcmd( cmd, wSwitch.right );
  wSwitch.setmanualcmd( cmd, True );
  wSwitch.setforcecmd( cmd, wxGetKeyState(WXK_CONTROL)?True:False);
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnCmdAction(wxCommandEvent& event) {
  int id = event.GetId()-ME_CmdAction;
  iONode actionCtrl = (iONode)ListOp.get( m_actionlist, id );

  TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999,
      "action command: %d %s", id, wActionCtrl.getid(actionCtrl) );
  wxGetApp().sendToRocrail( actionCtrl );

  /* clean up the list */
  ListOp.base.del(m_actionlist);
}

void Symbol::OnResetWheelcounter(wxCommandEvent& event) {
  iONode cmd = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
  wFeedback.setid( cmd, wFeedback.getid( m_Props ) );
  wFeedback.setcmd( cmd, wFeedback.reset );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnResetSensor(wxCommandEvent& event) {
  iONode cmd = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
  wFeedback.setid( cmd, wFeedback.getid( m_Props ) );
  wFeedback.setcmd( cmd, wFeedback.resetstatus );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnIdentifierFwd(wxCommandEvent& event) {
  wxTextEntryDialog* dlg = new wxTextEntryDialog(m_PlanPanel, wxGetApp().getMenu("identifier") );
  if( wxID_OK == dlg->ShowModal() ) {
    iONode cmd = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
    wFeedback.setid( cmd, wFeedback.getid( m_Props ) );

    char* idents = StrOp.dup(dlg->GetValue().mb_str(wxConvUTF8));
    iOStrTok tok = StrTokOp.inst(idents, ',');
    int idx = 0;
    while( StrTokOp.hasMoreTokens(tok) && idx < 4 ) {
      if( idx == 0 ) wFeedback.setidentifier( cmd, StrTokOp.nextToken(tok) );
      if( idx == 1 ) wFeedback.setidentifier2( cmd, StrTokOp.nextToken(tok) );
      if( idx == 2 ) wFeedback.setidentifier3( cmd, StrTokOp.nextToken(tok) );
      if( idx == 3 ) wFeedback.setidentifier4( cmd, StrTokOp.nextToken(tok) );
      idx++;
    }
    StrTokOp.base.del(tok);
    StrOp.free(idents);

    wFeedback.setstate( cmd, True);
    wFeedback.setdirection( cmd, True);
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
  dlg->Destroy();
}

void Symbol::OnIdentifierRev(wxCommandEvent& event) {
  wxTextEntryDialog* dlg = new wxTextEntryDialog(m_PlanPanel, wxGetApp().getMenu("identifier") );
  if( wxID_OK == dlg->ShowModal() ) {
    iONode cmd = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
    wFeedback.setid( cmd, wFeedback.getid( m_Props ) );

    char* idents = StrOp.dup(dlg->GetValue().mb_str(wxConvUTF8));
    iOStrTok tok = StrTokOp.inst(idents, ',');
    int idx = 0;
    while( StrTokOp.hasMoreTokens(tok) && idx < 4 ) {
      if( idx == 0 ) wFeedback.setidentifier( cmd, StrTokOp.nextToken(tok) );
      if( idx == 1 ) wFeedback.setidentifier2( cmd, StrTokOp.nextToken(tok) );
      if( idx == 2 ) wFeedback.setidentifier3( cmd, StrTokOp.nextToken(tok) );
      if( idx == 3 ) wFeedback.setidentifier4( cmd, StrTokOp.nextToken(tok) );
      idx++;
    }
    StrTokOp.base.del(tok);
    StrOp.free(idents);

    wFeedback.setstate( cmd, True);
    wFeedback.setdirection( cmd, False);
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
  dlg->Destroy();
}

void Symbol::OnSetSensorLoad(wxCommandEvent& event) {
  wxTextEntryDialog* dlg = new wxTextEntryDialog(m_PlanPanel, wxGetApp().getMenu("load") );
  if( wxID_OK == dlg->ShowModal() ) {
    iONode cmd = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
    wFeedback.setid( cmd, wFeedback.getid( m_Props ) );
    wFeedback.setload( cmd, atoi(dlg->GetValue().mb_str(wxConvUTF8)) );
    wFeedback.setstate( cmd, True);
    wFeedback.setdirection( cmd, False);
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
  dlg->Destroy();
}

void Symbol::OnOutputColor(wxCommandEvent& event) {
  wxColourData ColourData;
  iONode color = wOutput.getcolor(m_Props);
  if( color != NULL )
    ColourData.SetColour(wxColour(wColor.getred(color),wColor.getgreen(color),wColor.getblue(color)));

  wxColourDialog* dlg = new wxColourDialog(this, &ColourData);
  if( wxID_OK == dlg->ShowModal() ) {
    wxColour &colour = dlg->GetColourData().GetColour();

    iONode cmd = NodeOp.inst( wOutput.name(), NULL, ELEMENT_NODE);
    iONode color = NodeOp.inst( wColor.name(), NULL, ELEMENT_NODE);
    NodeOp.addChild(cmd, color);
    wColor.setred(color, (int)colour.Red());
    wColor.setgreen(color, (int)colour.Green());
    wColor.setblue(color, (int)colour.Blue());
    wOutput.setid( cmd, wOutput.getid( m_Props ) );
    wOutput.setvalue(cmd, wOutput.getvalue( m_Props ));
    wOutput.setcmd(cmd, wOutput.value);
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
  dlg->Destroy();
}

void Symbol::OnCompress(wxCommandEvent& event) {
  iONode cmd = NodeOp.inst( wStage.name(), NULL, ELEMENT_NODE );
  wStage.setid( cmd, wStage.getid( m_Props ) );
  wStage.setcmd( cmd, wStage.compress );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnCmdSignalRed(wxCommandEvent& event) {
  iONode cmd = NodeOp.inst( wSignal.name(), NULL, ELEMENT_NODE );
  wSignal.setid( cmd, wSignal.getid( m_Props ) );
  wSignal.setcmd( cmd, wSignal.red );
  wSignal.setaspect( cmd, -1 );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnCmdSignalGreen(wxCommandEvent& event) {
  iONode cmd = NodeOp.inst( wSignal.name(), NULL, ELEMENT_NODE );
  wSignal.setid( cmd, wSignal.getid( m_Props ) );
  wSignal.setcmd( cmd, wSignal.green );
  wSignal.setaspect( cmd, -1 );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnCmdSignalYellow(wxCommandEvent& event) {
  iONode cmd = NodeOp.inst( wSignal.name(), NULL, ELEMENT_NODE );
  wSignal.setid( cmd, wSignal.getid( m_Props ) );
  wSignal.setcmd( cmd, wSignal.yellow );
  wSignal.setaspect( cmd, -1 );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnCmdSignalWhite(wxCommandEvent& event) {
  iONode cmd = NodeOp.inst( wSignal.name(), NULL, ELEMENT_NODE );
  wSignal.setid( cmd, wSignal.getid( m_Props ) );
  wSignal.setcmd( cmd, wSignal.white );
  wSignal.setaspect( cmd, -1 );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnCmdSignalAspectName(wxCommandEvent& event) {
  int aspect = event.GetId()-ME_CmdSignalAspectName;
  iONode cmd = NodeOp.inst( wSignal.name(), NULL, ELEMENT_NODE );
  wSignal.setid( cmd, wSignal.getid( m_Props ) );
  wSignal.setcmd( cmd, wSignal.aspect );
  wSignal.setaspect( cmd, aspect );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnCmdSignalAspect(wxCommandEvent& event) {
  wxTextEntryDialog* dlg = new wxTextEntryDialog(m_PlanPanel, wxGetApp().getMenu("aspect") );
  if( wxID_OK == dlg->ShowModal() ) {
    iONode cmd = NodeOp.inst( wSignal.name(), NULL, ELEMENT_NODE );
    wSignal.setid( cmd, wSignal.getid( m_Props ) );
    wSignal.setcmd( cmd, wSignal.aspect );
    wSignal.setaspect( cmd, atoi(dlg->GetValue().mb_str(wxConvUTF8)) );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
  dlg->Destroy();

}

void Symbol::OnCmdSignalAuto(wxCommandEvent& event) {
  iONode cmd = NodeOp.inst( wSignal.name(), NULL, ELEMENT_NODE );
  wSignal.setid( cmd, wSignal.getid( m_Props ) );
  wSignal.setcmd( cmd, wSignal.autooperated );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnCmdSignalManual(wxCommandEvent& event) {
  iONode cmd = NodeOp.inst( wSignal.name(), NULL, ELEMENT_NODE );
  wSignal.setid( cmd, wSignal.getid( m_Props ) );
  wSignal.setcmd( cmd, wSignal.manualoperated );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}




void Symbol::OnLeftDClick(wxMouseEvent& event) {
  if( wxGetApp().getFrame()->isEditMode() ) {
    wxCommandEvent cmd;
    OnProps(cmd);
  }
  else {
    const char* nodeName = NodeOp.getName( m_Props );
    if( StrOp.equals( wBlock.name(), nodeName ) ) {
      const char* locId = wBlock.getlocid( m_Props );
      Boolean hasLoc = StrOp.len( locId ) > 0 ? True:False;
      if( hasLoc  && wxGetApp().getFrame()->isAutoMode() ) {
        iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
        wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
        wLoc.setcmd( cmd, wLoc.stopgo );
        wxGetApp().sendToRocrail( cmd );
        cmd->base.del(cmd);
      }
    }
    else
      OnLeftUp(event);
  }
}

void Symbol::OnLeftUp(wxMouseEvent& event) {
  if( m_locoIsDropped ) {
    m_locoIsDropped = false;
    return;
  }

  if( m_isDragged ) {
    m_isDragged = false;
    ReleaseMouse();
    double c = getSize();
    wxPoint p = GetPosition();
    p.x = (int)((c/2+p.x) / c);
    p.y = (int)((c/2+p.y) / c);

    int x_off, y_off;
    m_PlanPanel->GetViewStart( &x_off, &y_off );

    // Check for invalid values:
    if( (p.x + x_off) >= 0 && (p.y + y_off) >= 0 && (p.x + x_off) <= 256 && (p.y + y_off) <= 256 ) {
      wItem.setx( m_Props, p.x + x_off );
      wItem.sety( m_Props, p.y + y_off );
      setPosition();

      /* Notify RocRail. */
      TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999,
          "Change position to %d,%d", wItem.getx(m_Props), wItem.gety(m_Props) );
      iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
      wModelCmd.setcmd( cmd, wModelCmd.modify );
      iONode item = (iONode)NodeOp.base.clone( m_Props );
      NodeOp.addChild( cmd, item );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
    }
    else {
      // Restore position
      setPosition();
    }
  }
  else if( wxGetApp().getFrame()->isEditMode() && event.ShiftDown() ) {
    TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "check clipboard...");
    // Read some text
    bool resetrouteids = false;
    wxClipboard* cb = wxTheClipboard;
    if( cb != NULL ) {
      if( cb->Open() ) {
        if( cb->IsSupported( wxDF_TEXT )) {
          wxTextDataObject data;
          cb->GetData( data );
          char* id = StrOp.dup(data.GetText().mb_str(wxConvUTF8) );
          TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "add id [%s] to %s", id, wItem.getid(m_Props) );
          if( id != NULL && StrOp.len(id) > 0 ) {
            if( wxGetApp().getFrame()->findRoute(id) != NULL && StrOp.find(wItem.getrouteids(m_Props ), id) == NULL ) {
              // route ID
              const char* oldroutes = wItem.getrouteids(m_Props );
              const char* newroutes = id;
              if( oldroutes != NULL && StrOp.len(oldroutes) > 0 ) {
                char* s = (char*)allocMem(StrOp.len(oldroutes) + StrOp.len(newroutes) + 10);
                StrOp.fmtb(s, "%s,%s", oldroutes, newroutes );
                wItem.setrouteids(m_Props, s );
                freeMem(s);
              }
              else
                wItem.setrouteids(m_Props, newroutes );
            }
            else {
              if( wxGetApp().getFrame()->findBlock(id) != NULL || wxGetApp().getFrame()->findSensor(id) != NULL ) {
                wItem.setblockid(m_Props, id );
              }
            }
            m_PlanPanel->m_OK2Clear = false;
          }
          else {
            resetrouteids = true;
          }
          StrOp.free(id);
        }
        else {
          resetrouteids = true;
        }
        cb->Close();

        if( resetrouteids ) {
          int action = wxID_YES;
          if( !m_PlanPanel->m_OK2Clear ) {
            action = wxMessageDialog( this, wxGetApp().getMsg("resetrouteidswarning"), _T("Rocrail"), wxYES_NO | wxICON_QUESTION ).ShowModal();
          }
          if( action == wxID_YES ) {
            m_PlanPanel->m_OK2Clear = true;
            TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "reset route IDs on item %s", wItem.getid(m_Props) );
            wItem.setrouteids(m_Props, "" );
          }
        }

        if( !wxGetApp().isStayOffline() ) {
          /* Notify RocRail. */
          iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
          wModelCmd.setcmd( cmd, wModelCmd.modify );
          NodeOp.addChild( cmd, (iONode)m_Props->base.clone( m_Props ) );
          wxGetApp().sendToRocrail( cmd );
          cmd->base.del(cmd);
        }
        else {
          wxGetApp().setLocalModelModified(true);
        }

      }
    }
  }
  else {
    const char* nodeName = NodeOp.getName( m_Props );
    if( StrOp.equals( wSwitch.name(), nodeName ) ) {
      iONode cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
      wSwitch.setid( cmd, wSwitch.getid( m_Props ) );
      wSwitch.setcmd( cmd, wSwitch.flip );
      wSwitch.setmanualcmd( cmd, True );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
    }
    else if( StrOp.equals( wText.name(), nodeName ) && wText.ismanualinput(m_Props) ) {
      wxTextEntryDialog* dlg = new wxTextEntryDialog(this, wxGetApp().getMenu("entertext"),
          wxString(wText.getid( m_Props ),wxConvUTF8), wxString(wText.gettext( m_Props ),wxConvUTF8) );
      if( wxID_OK == dlg->ShowModal() ) {
        wText.settext( m_Props, dlg->GetValue().mb_str(wxConvUTF8) );
        /* Notify RocRail. */
        if( !wxGetApp().isOffline() ) {
          iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
          wModelCmd.setcmd( cmd, wModelCmd.modify );
          iONode item = (iONode)NodeOp.base.clone( m_Props );
          NodeOp.addChild( cmd, item );
          wxGetApp().sendToRocrail( cmd );
          cmd->base.del(cmd);
        }
      }
      dlg->Destroy();
    }
    else if( StrOp.equals( wRoute.name(), nodeName ) ) {
      iONode cmd = NodeOp.inst( wRoute.name(), NULL, ELEMENT_NODE );
      wRoute.setcmd( cmd, wRoute.test );
      wRoute.setid( cmd, wRoute.getid( m_Props ) );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
    }
    else if( StrOp.equals( wBlock.name(), nodeName ) ) {
      iONode cmd = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
      wBlock.setcmd( cmd, event.ShiftDown() ? wBlock.bsp:wBlock.bsm );
      wBlock.setid( cmd, wBlock.getid( m_Props ) );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
    }
    else if( StrOp.equals( wStage.name(), nodeName ) ) {
      iONode cmd = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
      wStage.setcmd( cmd, event.ShiftDown() ? wBlock.bsp:wBlock.bsm );
      wStage.setid( cmd, wStage.getid( m_Props ) );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
    }
    else if( StrOp.equals( wSignal.name(), nodeName ) ) {
      iONode cmd = NodeOp.inst( wSignal.name(), NULL, ELEMENT_NODE );
      wSignal.setid( cmd, wSignal.getid( m_Props ) );
      wSignal.setcmd( cmd, wSignal.flip );
      wSignal.setaspect( cmd, -1 );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
    }
    else if( StrOp.equals( wOutput.name(), nodeName ) ) {
      iONode cmd = NodeOp.inst( wOutput.name(), NULL, ELEMENT_NODE );
      wOutput.setid( cmd, wOutput.getid( m_Props ) );
      wOutput.setvalue( cmd, wOutput.getvalue( m_Props ) );
      if( wOutput.getcolor(m_Props) != NULL ) {
        NodeOp.addChild( cmd, (iONode)NodeOp.base.clone(wOutput.getcolor(m_Props)) );
      }
      if( wOutput.istoggleswitch(m_Props) ) {
        wOutput.setcmd( cmd, wOutput.flip );
      }
      else
        wOutput.setcmd( cmd, wOutput.off );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
    }
    else if( StrOp.equals( wTurntable.name(), nodeName ) ) {
      const char* dir = wTurntable.next;
      if( event.ShiftDown() )
        dir = wTurntable.prev;
      iONode cmd = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
      wTurntable.setid( cmd, wTurntable.getid( m_Props ) );
      wTurntable.setcmd( cmd, dir );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
    }
    else if( StrOp.equals( wSelTab.name(), nodeName ) ) {
      const char* dir = wSelTab.next;
      if( event.ShiftDown() )
        dir = wSelTab.prev;
      iONode cmd = NodeOp.inst( wSelTab.name(), NULL, ELEMENT_NODE );
      wSelTab.setid( cmd, wSelTab.getid( m_Props ) );
      wSelTab.setcmd( cmd, dir );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
    }
    else if( StrOp.equals( wFeedback.name(), nodeName ) ) {
      if(event.ShiftDown()) {
        wxCommandEvent evt( wxEVT_COMMAND_MENU_SELECTED, ME_IdentifierFwd );
        OnIdentifierFwd(evt);
      }
      else if(wGui.issimulatesensors(wxGetApp().getIni()) ) {
        iONode cmd = NodeOp.inst( wFeedback.name(), NULL, ELEMENT_NODE );
        wFeedback.setid( cmd, wFeedback.getid( m_Props ) );
        // simulate the invert state:
        wFeedback.setstate( cmd, wFeedback.isstate(m_Props) ? False:True);
        wxGetApp().sendToRocrail( cmd );
        cmd->base.del(cmd);
      }
    }

  }
}

void Symbol::OnRightDown(wxMouseEvent& event) {
}

void Symbol::OnLeftDown(wxMouseEvent& event) {
  wxPoint p = GetPosition();
  int x = p.x;
  int y = p.y;
  
  SetFocus();

  if( !StrOp.equals( wText.name(), NodeOp.getName( m_Props ) ) )
    Raise();

  wxGetMousePosition( &x, &y );

  m_dragX = x;
  m_dragY = y;

  char* text = StrOp.fmt( "(%d,%d)", x, y );
  wxGetApp().getFrame()->setInfoText( text );
  StrOp.free( text );

  if( !wxGetApp().getFrame()->isEditMode() && StrOp.equals( wBlock.name(), NodeOp.getName(m_Props)) && wBlock.getlocid(m_Props) != NULL && StrOp.len(wBlock.getlocid(m_Props)) > 0 ) {
    if( (event.ControlDown() || event.CmdDown()) && !event.AltDown() ) {
      wxTextDataObject my_data(_T("moveto:") + wxString(wBlock.getlocid(m_Props),wxConvUTF8)+_T("::") );
      wxDropSource dragSource( this );
      dragSource.SetData( my_data );
      wxDragResult result = dragSource.DoDragDrop(wxDrag_CopyOnly);
    }
    else if( (event.ControlDown() || event.CmdDown()) && event.AltDown() ) {
      wxTextDataObject my_data(_T("blocktrip:") + wxString(wBlock.getlocid(m_Props),wxConvUTF8)+_T("::") );
      wxDropSource dragSource( this );
      dragSource.SetData( my_data );
      wxDragResult result = dragSource.DoDragDrop(wxDrag_CopyOnly);
    }
    else {
      wxTextDataObject my_data(wxT("goto:") + wxString(wBlock.getlocid(m_Props),wxConvUTF8) + wxT(":") + wxString(wBlock.getid(m_Props),wxConvUTF8) + wxT(":\0") );
      wxDropSource dragSource( this );
      dragSource.SetData( my_data );
      wxDragResult result = dragSource.DoDragDrop(wxDrag_CopyOnly);
    }
  }
  else if( !wxGetApp().getFrame()->isEditMode() && StrOp.equals( wOutput.name(), NodeOp.getName(m_Props)) ) {
    if( !wOutput.istoggleswitch(m_Props) ) {
      iONode cmd = NodeOp.inst( wOutput.name(), NULL, ELEMENT_NODE );
      wOutput.setid( cmd, wOutput.getid( m_Props ) );
      wOutput.setcmd( cmd, wOutput.on );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
    }
  }
  else if( wxGetApp().getFrame()->isEditMode() && event.CmdDown() ) {
    wxPoint p = GetPosition();
    m_PlanPanel->OnLeftDown(event);
  }

  /*
  m_X = (int)(m_mouseX / (itemSize*m_Scale));
  m_Y = (int)(m_mouseY / (itemSize*m_Scale));
  */

  /*
  if( event.ControlDown() ) {
    // group selection...
    SetBackgroundColour( Base::getYellow() );
    Refresh();
  }
  else {
    SetBackgroundColour( Base::getWhite() );
    Refresh();
  }
  */
}

void Symbol::OnTimer(wxTimerEvent& event) {
  const char* locId = wBlock.getlocid( m_Props );
  Boolean hasLoc = StrOp.len( locId ) > 0 ? True:False;
  if( hasLoc && m_hasMouse ) {
    wxGetApp().getFrame()->setLocID( locId );
  }
}

bool Symbol::isSignal() {
  if( m_Props != NULL && StrOp.equals( wSignal.name(), NodeOp.getName(m_Props)))
    return true;
  return false;
}

bool Symbol::isSwitch() {
  if( m_Props != NULL && StrOp.equals( wSwitch.name(), NodeOp.getName(m_Props)))
    return true;
  return false;
}

bool Symbol::hasAlt() {
  if( m_Renderer != NULL && m_Renderer->hasAlt() )
    return true;
  return false;
}

void Symbol::OnMouseEnter(wxMouseEvent& event) {
  if( wxGetApp().getFrame()->isEditMode() ) {
    SetBackgroundColour( Base::getYellow() );
    Refresh();
  }
  m_hasMouse = true;
  if( StrOp.equals( wSwitch.name(), NodeOp.getName( m_Props ) ) ||
      StrOp.equals( wSignal.name(), NodeOp.getName( m_Props ) ) ||
      StrOp.equals( wRoute.name(), NodeOp.getName( m_Props ) ) ||
      StrOp.equals( wOutput.name(), NodeOp.getName( m_Props ) ) ||
      StrOp.equals( wSelTab.name(), NodeOp.getName( m_Props ) ) ||
      StrOp.equals( wTurntable.name(), NodeOp.getName( m_Props ) )
      ) {
    wxCursor cursor = wxCursor(wxCURSOR_HAND);
    SetCursor( cursor );
  }
  else if( StrOp.equals( wBlock.name(), NodeOp.getName( m_Props ) ) ) {
    const char* locId = wBlock.getlocid( m_Props );
    const char* state = wBlock.getstate( m_Props );
    Boolean hasLoc = StrOp.len( locId ) > 0 ? True:False;
    if( hasLoc ) {
      if( m_Timer == NULL ) {
        m_Timer = new wxTimer( this, ME_Timer );
      }
      m_Timer->Start( 1000, true );
      //wxGetApp().getFrame()->setLocID( locId );
      if( wxGetApp().getFrame()->isAutoMode() ) {
        wxCursor cursor = wxCursor(wxCURSOR_HAND);
        SetCursor( cursor );
      }
    }
  }
}

void Symbol::OnMouseLeave(wxMouseEvent& event) {
  if( wxGetApp().getFrame()->isEditMode() ) {
    SetBackgroundColour( m_PlanPanel->GetBackgroundColour() );
    Refresh();
  }
  m_hasMouse = false;
  if( StrOp.equals( wSwitch.name(), NodeOp.getName( m_Props ) ) ||
      StrOp.equals( wSignal.name(), NodeOp.getName( m_Props ) ) ||
      StrOp.equals( wRoute.name(), NodeOp.getName( m_Props ) ) ||
      StrOp.equals( wOutput.name(), NodeOp.getName( m_Props ) ) ||
      StrOp.equals( wSelTab.name(), NodeOp.getName( m_Props ) ) ||
      StrOp.equals( wTurntable.name(), NodeOp.getName( m_Props ) )
      ) {
    wxCursor cursor = wxCursor(wxCURSOR_ARROW);
    SetCursor( cursor );
  }
  else if( StrOp.equals( wBlock.name(), NodeOp.getName( m_Props ) ) ) {
    wxCursor cursor = wxCursor(wxCURSOR_ARROW);
    SetCursor( cursor );
  }
}

void Symbol::OnMotion(wxMouseEvent& event) {
  if( m_Props == NULL)
    return;

  if( !wxGetApp().getFrame()->isEditMode() ) {
    m_hasMouse = true;
    if( StrOp.equals( wBlock.name(), NodeOp.getName( m_Props ) ) ) {
      const char* locId = wBlock.getlocid( m_Props );
      Boolean hasLoc = StrOp.len( locId ) > 0 ? True:False;
      if( hasLoc ) {
        if( wxGetApp().getFrame()->isAutoMode() ) {
          wxCursor cursor = wxCursor(wxCURSOR_HAND);
          SetCursor( cursor );
        }
      }
    }
    char* text = StrOp.fmt( "(%d,%d)", wItem.getx(m_Props), wItem.gety(m_Props) );
    wxGetApp().getFrame()->setInfoText( text );
    StrOp.free( text );
    return;
  }

  wxPoint p = GetPosition();
  int x = p.x;
  int y = p.y;

  wxGetMousePosition( &x, &y );

  bool dragging = event.Dragging();


  if( dragging && event.m_leftDown && !m_isDragged ) {
    m_isDragged = true;
    m_dragX = x;
    m_dragY = y;
    CaptureMouse();
  }

  if( dragging && event.m_leftDown ) {
    int cx = x - m_dragX;
    int cy = y - m_dragY;
    if( cx != 0 || cy != 0 ) {
      wxPoint p = GetPosition();
      wxSize s = GetSize();
      p.x = p.x + cx;
      p.y = p.y + cy;
      SetSize( p.x, p.y, s.GetWidth(), s.GetHeight() );
      m_dragX = x;
      m_dragY = y;
    }
  }

  char* text = StrOp.fmt( "%s(%d,%d)", dragging?"drag":"", wItem.getx(m_Props), wItem.gety(m_Props) );
  wxGetApp().getFrame()->setInfoText( text );
  StrOp.free( text );
}

/* comparator for sorting by id: */
static int __sortStr(obj* _a, obj* _b)
{
    const char* a = (const char*)*_a;
    const char* b = (const char*)*_b;
    return strcmp( a, b );
}

void Symbol::OnPopup(wxMouseEvent& event)
{
    wxMenu menu( wxString(wItem.getid( m_Props ),wxConvUTF8) );
    //SetBackgroundColour( Base::getYellow() );

    if( StrOp.equals( wBlock.name(), NodeOp.getName( m_Props ) ) ) {
      const char* locoId = wBlock.getlocid( m_Props );
      const char* state  = wBlock.getstate( m_Props );

      if( locoId != NULL && StrOp.len( locoId ) > 0 ) {
        iONode lc = wxGetApp().getFrame()->findLoc(locoId);
        Boolean active = wLoc.isactive(lc);
        menu.Append( ME_UnLoc, wxGetApp().getMenu("resetlocid") );
        menu.AppendSeparator();
        menu.Append( ME_LocGo, wxGetApp().getMenu("startloc") );
        menu.Append( ME_LocGoManual, wxGetApp().getMenu("gomanual") );
        menu.Append( ME_LocGoVirtual, wxGetApp().getMenu("govirtual") );
        menu.Append( ME_LocStop, wxGetApp().getMenu("stoploc") );
        menu.Append( ME_LocSwap, wxGetApp().getMenu("swapplacing"), wxGetApp().getTip("swapplacing") );
        menu.Append( ME_LocSwapBlockSide, wxGetApp().getMenu("swapblockenterside"), wxGetApp().getTip("swapblockenterside") );
        menu.Append( ME_LocMIC, wxGetApp().getMenu("mic") );
        menu.Append( ME_LocGoTo, wxGetApp().getMenu("gotoblock"), wxGetApp().getTip("gotoblock") );
        menu.Append( ME_LocTour, wxGetApp().getMenu("selecttour"), wxGetApp().getTip("selecttour") );
        menu.Append( ME_LocSchedule, wxGetApp().getMenu("selectschedule"), wxGetApp().getTip("selectschedule") );

        // FY to Go menu
        iONode model = wxGetApp().getModel();

         m_fylist = ListOp.inst();

         if( model != NULL ) {
           iONode fylist = wPlan.getseltablist( model );
           if( fylist != NULL ) {
             int cnt = NodeOp.getChildCnt( fylist );
             if( cnt > 0 ) {
               wxMenu* menuFy2go = new wxMenu();
               for( int i = 0; i < cnt; i++ ) {
                 iONode fy = NodeOp.getChild( fylist, i );
                 const char* id = wSelTab.getid( fy );
                 if( id != NULL ) {
                   ListOp.add(m_fylist, (obj)id);
                 }
               }
               ListOp.sort(m_fylist, &__sortStr);

               cnt = ListOp.size( m_fylist );

               if(cnt > 4) // MAX 4!
                 cnt = 4;

               for( int i = 0; i < cnt; i++ ) {
                 const char* id = (const char*)ListOp.get( m_fylist, i );
                 menuFy2go->Append( ME_FYGo+i, wxString(id,wxConvUTF8) );
               }
               menu.Append( ME_FYGo, wxGetApp().getMenu("fiddleyard2go"), menuFy2go );
             }
           }
         }



         // TT to Go menu
          m_ttlist = ListOp.inst();

          if( model != NULL ) {
            iONode ttlist = wPlan.getttlist( model );
            if( ttlist != NULL ) {
              int cnt = NodeOp.getChildCnt( ttlist );
              if( cnt > 0 ) {
                wxMenu* menuTT2go = new wxMenu();
                for( int i = 0; i < cnt; i++ ) {
                  iONode tt = NodeOp.getChild( ttlist, i );
                  const char* id = wTurntable.getid( tt );
                  if( id != NULL ) {
                    ListOp.add(m_ttlist, (obj)id);
                  }
                }
                ListOp.sort(m_ttlist, &__sortStr);

                cnt = ListOp.size( m_ttlist );

                if(cnt > 4) // MAX 4!
                  cnt = 4;

                for( int i = 0; i < cnt; i++ ) {
                  const char* id = (const char*)ListOp.get( m_ttlist, i );
                  menuTT2go->Append( ME_TTGo+i, wxString(id,wxConvUTF8) );
                }
                menu.Append( ME_TTGo, wxGetApp().getMenu("turntable2go"), menuTT2go );
              }
            }
          }


          if( model != NULL ) {
          m_sclist = ListOp.inst();
          Boolean addSc = False;
          Boolean onlyStartWith = wGui.isshowonlystartschedules(wxGetApp().getIni());
          wxMenu* menuSchd2go = NULL;

          iONode tourlist = wPlan.gettourlist( model );
          // Tours 2 Go
          if( tourlist != NULL ) {
            int cnt = NodeOp.getChildCnt( tourlist );
            if( cnt > 0 ) {
              for( int i = 0; i < cnt; i++ ) {
                iONode tour = NodeOp.getChild( tourlist, i );
                const char* id = wTour.getid( tour );
                if( !onlyStartWith || ToursDlg::isFirst(tour, wBlock.getid( m_Props )) ) {
                  addSc = True;
                  ListOp.add(m_sclist, (obj)id);
                  if( menuSchd2go == NULL ) {
                    menuSchd2go = new wxMenu();
                  }
                }
              }
            }
          }

        // Schedule 2 Go menu
           iONode sclist = wPlan.getsclist( model );
           if( sclist != NULL ) {
             int cnt = NodeOp.getChildCnt( sclist );
             if( cnt > 0 ) {
               if( menuSchd2go == NULL ) {
                 menuSchd2go = new wxMenu();
               }

               for( int i = 0; i < cnt; i++ ) {
                 iONode sc = NodeOp.getChild( sclist, i );
                 const char* id = wSchedule.getid( sc );
                 addSc = False;
                 iONode entry = wSchedule.getscentry( sc );
                 while( entry != NULL && !addSc ) {
                   const char* blockID    = wScheduleEntry.getblock( entry );
                   const char* locationID = wScheduleEntry.getlocation( entry );

                   if( blockID != NULL && StrOp.equals(blockID, wBlock.getid( m_Props ) )) {
                     TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "schedule %s found for %s", 
                         id, wBlock.getid( m_Props ));
                     addSc = True;
                   }
                   else if( blockID != NULL && wBlock.getmanagerid( m_Props ) != NULL && 
                            StrOp.len(wBlock.getmanagerid( m_Props )) > 0 && StrOp.equals(blockID, wBlock.getmanagerid( m_Props ) )) 
                   {
                     TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "schedule %s found for %s", 
                         id, wBlock.getmanagerid( m_Props ));
                     addSc = True;
                   }
                   else if( locationID != NULL ) {
                     iONode locationlist = wPlan.getlocationlist( model );
                     if( locationlist != NULL ) {
                       iONode location = wLocationList.getlocation( locationlist );
                       while( !addSc && location != NULL ) {
                         if( StrOp.equals(locationID, wLocation.getid( location ))) {
                           iOStrTok tok = StrTokOp.inst( wLocation.getblocks( location ), ',' );
                           while ( StrTokOp.hasMoreTokens( tok )) {
                             const char * token = StrTokOp.nextToken( tok );
                             if( StrOp.equals( token, wBlock.getid( m_Props )) || StrOp.equals( token, wBlock.getmanagerid( m_Props )) ) {
                               TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "location %s found for %s(%s)", 
                                   wLocation.getid( location ), wBlock.getid( m_Props ), wBlock.getmanagerid( m_Props ));
                               addSc = True;
                               break;
                             }
                           }
                           StrTokOp.base.del(tok);
                         }
                         location = wLocationList.nextlocation( locationlist, location );
                       }
                     }
                   }
                   entry = (onlyStartWith ? NULL:wSchedule.nextscentry( sc, entry ));
                 }

                 if( id != NULL && addSc) {
                  ListOp.add(m_sclist, (obj)id);
                 }

               }
               ListOp.sort(m_sclist, &__sortStr);

               cnt = ListOp.size( m_sclist );

               if(cnt > 20) // MAX 20!
                 cnt = 20;

               for( int i = 0; i < cnt; i++ ) {
                 const char* id = (const char*)ListOp.get( m_sclist, i );
                 menuSchd2go->Append( ME_ScheduleGo+i, wxString(id,wxConvUTF8) );
               }
               menu.Append( ME_ScheduleGo, wxGetApp().getMenu("schedule2go"), menuSchd2go );
             }
           }
         }


        wxMenuItem *mi = menu.FindItem( ME_LocGo );
        if( !wxGetApp().getFrame()->isAutoMode() )
          mi->Enable( false );
        mi = menu.FindItem( ME_LocGoManual );
        if( !wxGetApp().getFrame()->isAutoMode() )
          mi->Enable( false );
        mi = menu.FindItem( ME_LocGoVirtual );
        if( !wxGetApp().getFrame()->isAutoMode() )
          mi->Enable( false );
        mi = menu.FindItem( ME_ScheduleGo );
        if( mi != NULL && !wxGetApp().getFrame()->isAutoMode() )
          mi->Enable( false );
        mi = menu.FindItem( ME_FYGo );
        if( mi != NULL && !wxGetApp().getFrame()->isAutoMode() )
          mi->Enable( false );
        mi = menu.FindItem( ME_TTGo );
        if( mi != NULL && !wxGetApp().getFrame()->isAutoMode() )
          mi->Enable( false );
        mi = menu.FindItem( ME_UnLoc );
        //if( wxGetApp().getFrame()->isAutoMode() )
        //  mi->Enable( false );
        menu.AppendSeparator();
        menu.Append( ME_LocReset, wxGetApp().getMenu("softresetall") );
        menu.Append( ME_LocResetAll, wxGetApp().getMenu("resetall") );
        mi = menu.FindItem( ME_LocReset );
        //if( wxGetApp().getFrame()->isAutoMode() )
          //mi->Enable( false );
        menu.AppendSeparator();
        if( !active )
          menu.Append( ME_LocActivate, wxGetApp().getMenu("activate") );
        else
          menu.Append( ME_LocDeActivate, wxGetApp().getMenu("deactivate") );
        menu.AppendSeparator();
      }
      else if( StrOp.equals( wBlock.open, state ) ) {
        menu.Append( ME_Loc, wxGetApp().getMenu("setlocid") );
        menu.Append( ME_AcceptIdent, wxGetApp().getMenu("acceptident") );
        menu.AppendSeparator();
      }
      else if( StrOp.equals( wBlock.ghost, state ) ) {
        menu.Append( ME_UnLoc, wxGetApp().getMenu("resetlocid") );
        menu.AppendSeparator();
      }

      if( StrOp.equals( wBlock.open, state ) ) {
        menu.Append( ME_CloseBlock, wxGetApp().getMenu("outoforder") );
        wxMenuItem *mi_Close = menu.FindItem( ME_CloseBlock );
        //if( wxGetApp().getFrame()->isAutoMode() )
        //  mi_Close->Enable( false );
      }
      else {
        menu.Append( ME_OpenBlock, wxGetApp().getMenu("operational") );
      }
      menu.Append( ME_ResetWC, wxGetApp().getMenu("resetwc") );
      menu.Append( ME_ResetFiFo, wxGetApp().getMenu("resetfifo") );
    }
    else if( StrOp.equals( wSwitch.name(), NodeOp.getName( m_Props ) ) ) {
      //if( !wxGetApp().getFrame()->isAutoMode() )
      menu.Append( ME_UnLoc, wxGetApp().getMenu("resetlocid") );
      wxMenu* menuSwCmd = new wxMenu();
      menuSwCmd->Append( ME_CmdStraight, wxGetApp().getMenu("straight") );

      const char* type = wSwitch.gettype( m_Props );
      const char* subtype = wSwitch.getsubtype( m_Props );
      if( !StrOp.equals( wSwitch.decoupler, type ) ) {

        if( !StrOp.equals( wSwitch.threeway, type ) )
          menuSwCmd->Append( ME_CmdTurnout, wxGetApp().getMenu("thrown") );

        if( StrOp.equals( wSwitch.dcrossing, type ) || StrOp.equals( wSwitch.threeway, type ) ) {
          if( StrOp.equals( "default", subtype ) || StrOp.equals( wSwitch.subleft, subtype ) )
            menuSwCmd->Append( ME_CmdLeft, wxGetApp().getMenu("left") );
          if( StrOp.equals( "default", subtype ) || StrOp.equals( wSwitch.subright, subtype ) )
            menuSwCmd->Append( ME_CmdRight, wxGetApp().getMenu("right") );
        }

        if( StrOp.equals( wSwitch.accessory, type ) ) {
          iONode actionctrl = wSwitch.getactionctrl(m_Props);
          if( actionctrl != NULL ) {
            menuSwCmd->AppendSeparator();
            m_actionlist = ListOp.inst();
          }

          int actcnt = 0;
          while( actionctrl != NULL && actcnt < 10) {
            ListOp.add( m_actionlist, (obj)actionctrl );
            if( wActionCtrl.getdesc(actionctrl) != NULL && StrOp.len(wActionCtrl.getdesc(actionctrl)) > 0 )
              menuSwCmd->Append( ME_CmdAction+actcnt, wxString(wActionCtrl.getdesc(actionctrl),wxConvUTF8) );
            else
              menuSwCmd->Append( ME_CmdAction+actcnt, wxString(wActionCtrl.getid(actionctrl),wxConvUTF8) );
            actionctrl = wSwitch.nextactionctrl(m_Props, actionctrl);
            actcnt++;
          }
        }
      }
      menu.Append( -1, wxGetApp().getMenu("command"), menuSwCmd );
    }
    else if( StrOp.equals( wSignal.name(), NodeOp.getName( m_Props ) ) ) {
      wxMenu* menuSgCmd = new wxMenu();
      if( wSignal.ismanual( m_Props ) ) {
        menuSgCmd->Append( ME_CmdSignalAuto, wxGetApp().getMenu("autooperated") );
      }
      else {
        menuSgCmd->Append( ME_CmdSignalManual, wxGetApp().getMenu("manualoperated") );
      }
      const char* aspectnames = wSignal.getaspectnames(m_Props);
      if( wSignal.getaspects(m_Props) > 4 && aspectnames != NULL && StrOp.len(aspectnames) > 0 ) {
        iOStrTok tok = StrTokOp.inst( aspectnames, ',' );
        int aspect = 0;
        int idx = 0;
        const char* aspectname = StrTokOp.nextToken(tok);

        while( aspectname != NULL && idx < 16) {
          menuSgCmd->Append( ME_CmdSignalAspectName+idx, wxString(aspectname,wxConvUTF8) );
          idx++;
          aspectname = StrTokOp.nextToken(tok);
        };
        StrTokOp.base.del( tok );
      }
      else {
        menuSgCmd->Append( ME_CmdSignalRed, wxGetApp().getMenu("red") );
        menuSgCmd->Append( ME_CmdSignalGreen, wxGetApp().getMenu("green") );
        if( wSignal.getaspects( m_Props ) > 2 )
          menuSgCmd->Append( ME_CmdSignalYellow, wxGetApp().getMenu("yellow") );
        if( wSignal.getaspects( m_Props ) > 3 )
          menuSgCmd->Append( ME_CmdSignalWhite, wxGetApp().getMenu("white") );
        if( wSignal.getaspects( m_Props ) > 4 )
          menuSgCmd->Append( ME_CmdSignalAspect, wxGetApp().getMenu("aspect") );
        }
      menu.Append( -1, wxGetApp().getMenu("command"), menuSgCmd );
    }
    else if( StrOp.equals( wTurntable.name(), NodeOp.getName( m_Props ) ) ) {
      const char* locId = wTurntable.getlocid( m_Props );
      const char* state = wTurntable.getstate( m_Props );
      Boolean hasLoc = StrOp.len( locId ) > 0 ? True:False;
      if( wTurntable.isembeddedblock(m_Props) && hasLoc ) {
        menu.Append( ME_UnLoc, wxGetApp().getMenu("resetlocid") );
        menu.Append( ME_LocGo, wxGetApp().getMenu("startloc") );
        menu.Append( ME_LocStop, wxGetApp().getMenu("stoploc") );
        menu.AppendSeparator();
      }
      else if( wTurntable.isembeddedblock(m_Props) ) {
        menu.Append( ME_Loc, wxGetApp().getMenu("setlocid") );
        menu.AppendSeparator();
      }
      menu.Append( ME_TTLightOn, wxGetApp().getMenu("lights") + _T(" ") + wxGetApp().getMenu("on") );
      menu.Append( ME_TTLightOff, wxGetApp().getMenu("lights") + _T(" ") + wxGetApp().getMenu("off") );
      menu.Append( ME_TTNext, wxGetApp().getMenu("nexttrack") );
      menu.Append( ME_TTPrev, wxGetApp().getMenu("prevtrack") );
      menu.Append( ME_TT180, wxGetApp().getMenu("turn180") );
      menu.Append( ME_TTCalibrate, wxGetApp().getMenu("calibrate") );
      wxMenu* trackmenu = new wxMenu();

      iONode track = wTurntable.gettrack( m_Props );
      while( track != NULL ) {
        m_PlanPanel->addItem( NodeOp.getName(track), wTTTrack.getposfb( track ), this );
        int tracknr = wTTTrack.getnr( track );
        if( tracknr >=0 && tracknr < 48 && wTTTrack.isshow(track) ) {
          char* nrstr = StrOp.fmt( "%d %s", tracknr, wTTTrack.getdesc(track) );
          trackmenu->Append( ME_TTTrack+tracknr, wxString(nrstr,wxConvUTF8) );
          StrOp.free( nrstr );
        }
        track = wTurntable.nexttrack( m_Props, track );
      }
      menu.Append( -1, wxGetApp().getMenu("gototrack"), trackmenu);
      menu.AppendSeparator();
      menu.Append( ME_Info, wxGetApp().getMenu("info") );
      if( !wTurntable.isembeddedblock(m_Props) )
        menu.Append( ME_UnLoc, wxGetApp().getMenu("resetlocid") );
      if( StrOp.equals( wBlock.open, state ) )
        menu.Append( ME_CloseBlock, wxGetApp().getMenu("outoforder") );
      else
        menu.Append( ME_OpenBlock, wxGetApp().getMenu("operational") );
      menu.AppendSeparator();
    }
    else if( StrOp.equals( wSelTab.name(), NodeOp.getName( m_Props ) ) ) {
      menu.Append( ME_TTNext, wxGetApp().getMenu("nexttrack") );
      menu.Append( ME_TTPrev, wxGetApp().getMenu("prevtrack") );
      wxMenu* trackmenu = new wxMenu();

      iONode track = wSelTab.getseltabpos( m_Props );
      while( track != NULL ) {
        int tracknr = wSelTabPos.getnr( track );
        if( tracknr >=0 && tracknr < 64 ) {
          char* nrstr = StrOp.fmt( "%d %s", tracknr, wSelTabPos.getdesc(track) );
          trackmenu->Append( ME_TTTrack+tracknr, wxString(nrstr,wxConvUTF8) );
          StrOp.free( nrstr );
        }
        track = wSelTab.nextseltabpos( m_Props, track );
      }
      menu.Append( -1, wxGetApp().getMenu("gototrack"), trackmenu);
      menu.AppendSeparator();
      menu.Append( ME_UnLoc, wxGetApp().getMenu("resetlocid") );

      const char* state = wBlock.getstate( m_Props );
      if( StrOp.equals( wBlock.open, state ) ) {
        menu.Append( ME_CloseBlock, wxGetApp().getMenu("outoforder") );
        wxMenuItem *mi_Close = menu.FindItem( ME_CloseBlock );
        //if( wxGetApp().getFrame()->isAutoMode() )
        //  mi_Close->Enable( false );
      }
      else {
        menu.Append( ME_OpenBlock, wxGetApp().getMenu("operational") );
      }
      menu.AppendSeparator();
    }

    else if( StrOp.equals( wFeedback.name(), NodeOp.getName( m_Props ) ) ) {
      menu.Append( ME_ResetWheelcounter, wxGetApp().getMenu("resetcounters") );
      menu.Append( ME_ResetSensor, wxGetApp().getMenu("resetstatus") );
      menu.Append( ME_SetSensorLoad, wxGetApp().getMenu("load") );
      wxMenu* identifiermenu = new wxMenu();
      identifiermenu->Append( ME_IdentifierFwd, wxGetApp().getMenu("forwards")  );
      identifiermenu->Append( ME_IdentifierRev, wxGetApp().getMenu("reverse")  );
      menu.Append( -1, wxGetApp().getMenu("identifier"), identifiermenu);
    }

    else if( StrOp.equals( wStage.name(), NodeOp.getName( m_Props ) ) ) {
      menu.Append( ME_Compress, wxGetApp().getMenu("compress") );
      const char* state = wBlock.getstate( m_Props );
      if( StrOp.equals( wBlock.open, state ) ) {
        menu.Append( ME_CloseBlock, wxGetApp().getMenu("outoforder") );
      }
      else {
        menu.Append( ME_OpenBlock, wxGetApp().getMenu("operational") );
      }

      if( StrOp.equals( wBlock.open, wStage.getexitstate(m_Props) ) ) {
        menu.Append( ME_CloseExitBlock, wxGetApp().getMenu("closeexit") );
      }
      else {
        menu.Append( ME_OpenExitBlock, wxGetApp().getMenu("openexit") );
      }
    }

    else if( StrOp.equals( wRoute.name(), NodeOp.getName( m_Props ) ) ) {
      //if( !wxGetApp().getFrame()->isAutoMode() ) {
        menu.Append( ME_UnLoc, wxGetApp().getMenu("reset") );
        if( wRoute.getstatus(m_Props) == wRoute.status_free )
          menu.Append( ME_CloseBlock, wxGetApp().getMenu("outoforder") );
        if( wRoute.getstatus(m_Props) == wRoute.status_closed )
          menu.Append( ME_OpenBlock, wxGetApp().getMenu("operational") );
      //}
    }

    else if( StrOp.equals( wOutput.name(), NodeOp.getName( m_Props ) ) ) {
      if( wOutput.iscolortype(m_Props) ) {
        menu.Append( ME_OutputColor, wxGetApp().getMenu("color") + wxT("...") );
      }
    }

    //menu.AppendSeparator();
    wxMenuItem* mi = menu.Append( ME_Props , wxGetApp().getMenu("properties") );
    if( !StrOp.equals( wStage.name(), NodeOp.getName(m_Props) ))
      mi->Enable( !wxGetApp().getFrame()->isAutoMode() || !wxGetApp().isRestrictedEdit() );

    menu.Append( ME_ItemHelp , wxGetApp().getMenu("help") );

    if( wxGetApp().getFrame()->isEditMode() ) {
      menu.Append( ME_Copy, wxGetApp().getMenu("copy") );
      menu.Append( ME_Delete, wxGetApp().getMenu("delete") );

      if( m_Renderer->isRotateable() ) {
        wxMenu* menuOrientation = new wxMenu();
        menuOrientation->Append( ME_Rotate, wxGetApp().getMenu("rotate") );
        menuOrientation->AppendSeparator();
        menuOrientation->Append( ME_North, wxGetApp().getMenu("north") );
        menuOrientation->Append( ME_East, wxGetApp().getMenu("east") );
        menuOrientation->Append( ME_South, wxGetApp().getMenu("south") );
        menuOrientation->Append( ME_West, wxGetApp().getMenu("west") );
        menu.Append( -1, wxGetApp().getMenu("orientation"), menuOrientation );
        menu.AppendSeparator();
        menu.Append( ME_PanelSelect, wxGetApp().getMenu("select") );
      }

    }
    //SetFocus();
    PopupMenu(&menu );
}

void Symbol::OnLoc(wxCommandEvent& event) {
  iONode model = wxGetApp().getModel();
  if( model == NULL )
    return;

  //LocDialog*  dlg = new LocDialog(this, NULL, false );
  LocSelDlg*  dlg = new LocSelDlg(this, NULL, false );

  if( wxID_OK == dlg->ShowModal() ) {
    /* Notify RocRail. */
    iONode sel = dlg->getProperties();
    if( sel != NULL ) {
      const char* id = wLoc.getid( sel );
      if( id != NULL ) {
        m_DandD = true;
        /* Inform RocRail... */
        iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
        wLoc.setid( cmd, id );
        wLoc.setcmd( cmd, wLoc.block );
        wLoc.setblockid( cmd, wBlock.getid( m_Props ) );
        wxGetApp().sendToRocrail( cmd );
        cmd->base.del(cmd);
      }
    }
  }
  dlg->Destroy();

}

void Symbol::OnUnLoc(wxCommandEvent& event) {
  iONode model = wxGetApp().getModel();
  if( model == NULL )
    return;
  /* Inform RocRail... */
  if( StrOp.equals( wBlock.name(), NodeOp.getName( m_Props ) ) ) {
    iONode cmd = NodeOp.inst( wBlock.name(), NULL, ELEMENT_NODE );
    wBlock.setid( cmd, wBlock.getid( m_Props ) );
    wBlock.setlocid( cmd, "" );
    wBlock.setcmd( cmd, wBlock.loc );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
  else if( StrOp.equals( wSwitch.name(), NodeOp.getName( m_Props ) ) ) {
    iONode cmd = NodeOp.inst( wSwitch.name(), NULL, ELEMENT_NODE );
    wSwitch.setid( cmd, wSwitch.getid( m_Props ) );
    wSwitch.setcmd( cmd, wSwitch.unlock );
    wSwitch.setmanualcmd( cmd, True );
    wSwitch.setforcecmd( cmd, wxGetKeyState(WXK_CONTROL)?True:False);
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
  else if( StrOp.equals( wTurntable.name(), NodeOp.getName( m_Props ) ) ) {
    iONode cmd = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
    wTurntable.setid( cmd, wTurntable.getid( m_Props ) );
    wTurntable.setlocid( cmd, "" );
    wTurntable.setcmd( cmd, wSwitch.unlock );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
  else if( StrOp.equals( wSelTab.name(), NodeOp.getName( m_Props ) ) ) {
    iONode cmd = NodeOp.inst( wSelTab.name(), NULL, ELEMENT_NODE );
    wSelTab.setid( cmd, wSelTab.getid( m_Props ) );
    wSelTab.setcmd( cmd, wSwitch.unlock );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
  else if( StrOp.equals( wRoute.name(), NodeOp.getName( m_Props ) ) ) {
    iONode cmd = NodeOp.inst( wRoute.name(), NULL, ELEMENT_NODE );
    wRoute.setid( cmd, wRoute.getid( m_Props ) );
    wRoute.setcmd( cmd, wSwitch.unlock );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}

void Symbol::OnLocGoTo(wxCommandEvent& event) {
  GotoDlg* gotoDlg = new GotoDlg( this, wBlock.getlocid( m_Props ) );
  if( wxID_OK == gotoDlg->ShowModal() ) {
    iONode selection = gotoDlg->getSelected();
    if( selection != NULL ) {
      /* Inform RocRail... */
      iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
      wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
      wLoc.setcmd( cmd, wLoc.gotoblock );
      wLoc.setblockid( cmd, wItem.getid(selection) );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
    }
  }
  gotoDlg->Destroy();

/*
  BlockDialog* blockDlg = new BlockDialog( this, NULL, false );
  if( wxID_OK == blockDlg->ShowModal() ) {
    iONode sel = blockDlg->getProperties();
    if( sel != NULL ) {
      const char* id = wBlock.getid( sel );

      if( id != NULL ) {
        // Inform RocRail...
        iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
        wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
        wLoc.setcmd( cmd, wLoc.gotoblock );
        wLoc.setblockid( cmd, id );
        wxGetApp().sendToRocrail( cmd );
        cmd->base.del(cmd);
      }
    }
  }
  blockDlg->Destroy();
*/

}

void Symbol::OnLocSchedule(wxCommandEvent& event) {
  ScheduleDialog* dlg = new ScheduleDialog( this, (iONode)NULL, false, wBlock.getid(m_Props) );
  if( wxID_OK == dlg->ShowModal() ) {
    iONode sel = dlg->getProperties();
    if( sel != NULL ) {
      const char* id = wSchedule.getid( sel );

      if( id != NULL ) {
        /* Inform RocRail... */
        iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
        wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
        wLoc.setcmd( cmd, wLoc.useschedule );
        wLoc.setscheduleid( cmd, id );
        wxGetApp().sendToRocrail( cmd );
        cmd->base.del(cmd);
      }
    }
  }
  dlg->Destroy();
}

void Symbol::OnLocTour(wxCommandEvent& event) {
  ToursDlg* dlg = new ToursDlg( this, (iONode)NULL, false, wBlock.getid(m_Props) );
  if( wxID_OK == dlg->ShowModal() ) {
    iONode sel = dlg->getProperties();
    if( sel != NULL ) {
      const char* id = wTour.getid( sel );

      if( id != NULL ) {
        /* Inform RocRail... */
        iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
        wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
        wLoc.setcmd( cmd, wLoc.usetour );
        wLoc.settourid( cmd, id );
        wxGetApp().sendToRocrail( cmd );
        cmd->base.del(cmd);
      }
    }
  }
  dlg->Destroy();
}

void Symbol::OnLocGo(wxCommandEvent& event) {
  /* Inform RocRail... */
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
  wLoc.setcmd( cmd, wLoc.go );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnScheduleGo(wxCommandEvent& event) {

  const char* sid = (const char*)ListOp.get( m_sclist, event.GetId()-ME_ScheduleGo );

  if( sid != NULL && wBlock.getlocid( m_Props ) != NULL ) {
    /* Inform RocRail... */
    iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
    wLoc.setcmd( cmd, wLoc.useschedule );
    wLoc.setscheduleid( cmd, sid );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);

    cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
    wLoc.setcmd( cmd, wLoc.go );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }

  /* clean up the sclist */
  ListOp.base.del(m_sclist);
}

void Symbol::OnFYGo(wxCommandEvent& event) {

  const char* fyid = (const char*)ListOp.get( m_fylist, event.GetId()-ME_FYGo );

  if( fyid != NULL && wBlock.getlocid( m_Props ) != NULL ) {
    /* Inform RocRail... */
    iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
    wLoc.setcmd( cmd, wLoc.gotoblock );
    wLoc.setblockid( cmd, fyid );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);

    cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
    wLoc.setcmd( cmd, wLoc.go );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }

  /* clean up the sclist */
  ListOp.base.del(m_fylist);
}

void Symbol::OnTTGo(wxCommandEvent& event) {

  const char* ttid = (const char*)ListOp.get( m_ttlist, event.GetId()-ME_TTGo );

  if( ttid != NULL && wBlock.getlocid( m_Props ) != NULL ) {
    /* Inform RocRail... */
    iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
    wLoc.setcmd( cmd, wLoc.gotoblock );
    wLoc.setblockid( cmd, ttid );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);

    cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
    wLoc.setcmd( cmd, wLoc.go );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }

  /* clean up the sclist */
  ListOp.base.del(m_ttlist);
}

void Symbol::OnLocActivate(wxCommandEvent& event) {
  /* Inform RocRail... */
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
  wLoc.setcmd( cmd, wLoc.activate );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnLocDeActivate(wxCommandEvent& event) {
  /* Inform RocRail... */
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
  wLoc.setcmd( cmd, wLoc.deactivate );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnLocGoManual(wxCommandEvent& event) {
  /* Inform RocRail... */
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
  wLoc.setcmd( cmd, wLoc.gomanual );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}


void Symbol::OnLocGoVirtual(wxCommandEvent& event) {
  /* Inform RocRail... */
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
  wLoc.setcmd( cmd, wLoc.govirtual );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}


void Symbol::OnLocSwapBlockSide(wxCommandEvent& event) {
  /* Inform RocRail... */
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
  wLoc.setcmd( cmd, wLoc.blockside );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnLocSwap(wxCommandEvent& event) {
  /* Inform RocRail... */
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
  wLoc.setcmd( cmd, wLoc.swap );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}


void Symbol::OnLocStop(wxCommandEvent& event) {
  /* Inform RocRail... */
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
  wLoc.setcmd( cmd, wLoc.stop );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnLocReset(wxCommandEvent& event) {
  /* Inform RocRail... */
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
  wLoc.setcmd( cmd, wLoc.softreset );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnLocResetAll(wxCommandEvent& event) {
  /* Inform RocRail... */
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wBlock.getlocid( m_Props ) );
  wLoc.setcmd( cmd, wLoc.reset );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnLocMIC(wxCommandEvent& event) {
  LocSelDlg* dlg = new LocSelDlg(this, NULL, true, wBlock.getlocid( m_Props ) );
  dlg->ShowModal();
  dlg->Destroy();
}

void Symbol::OnCloseBlock(wxCommandEvent& event) {
  /* Inform RocRail... */
  iONode cmd = NodeOp.inst( NodeOp.getName(m_Props), NULL, ELEMENT_NODE );
  wBlock.setid( cmd, wBlock.getid( m_Props ) );
  wBlock.setstate( cmd, wBlock.closed );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnOpenBlock(wxCommandEvent& event) {
  /* Inform RocRail... */
  iONode cmd = NodeOp.inst( NodeOp.getName(m_Props), NULL, ELEMENT_NODE );
  wBlock.setid( cmd, wBlock.getid( m_Props ) );
  wBlock.setstate( cmd, wBlock.open );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnResetWC(wxCommandEvent& event) {
  /* Inform RocRail... */
  iONode cmd = NodeOp.inst( NodeOp.getName(m_Props), NULL, ELEMENT_NODE );
  wBlock.setid( cmd, wBlock.getid( m_Props ) );
  wBlock.setcmd( cmd, wBlock.resetwc );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnResetFiFo(wxCommandEvent& event) {
  /* Inform RocRail... */
  iONode cmd = NodeOp.inst( NodeOp.getName(m_Props), NULL, ELEMENT_NODE );
  wBlock.setid( cmd, wBlock.getid( m_Props ) );
  wBlock.setcmd( cmd, wBlock.resetfifo );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnCloseExitBlock(wxCommandEvent& event) {
  /* Inform RocRail... */
  iONode cmd = NodeOp.inst( NodeOp.getName(m_Props), NULL, ELEMENT_NODE );
  wStage.setid( cmd, wBlock.getid( m_Props ) );
  wStage.setexitstate( cmd, wBlock.closed );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnOpenExitBlock(wxCommandEvent& event) {
  /* Inform RocRail... */
  iONode cmd = NodeOp.inst( NodeOp.getName(m_Props), NULL, ELEMENT_NODE );
  wStage.setid( cmd, wBlock.getid( m_Props ) );
  wStage.setexitstate( cmd, wBlock.open );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnAcceptIdent(wxCommandEvent& event) {
  /* Inform RocRail... */
  iONode cmd = NodeOp.inst( NodeOp.getName(m_Props), NULL, ELEMENT_NODE );
  wBlock.setid( cmd, wBlock.getid( m_Props ) );
  wBlock.setacceptident( cmd, True );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnInfo(wxCommandEvent& event) {
  const char* name = NodeOp.getName( m_Props );
  if( StrOp.equals( wTurntable.name(), name ) ) {
    char* msg = NULL;

    iONode track = wTurntable.gettrack( m_Props );
    while( track != NULL ) {
      char* tmp = msg;
      if( SystemOp.isWindows() )
        msg = StrOp.fmt( "%s, %s", msg==NULL?"":msg, wTTTrack.getdesc( track ) );
      else
        msg = StrOp.fmt( "%s\n%s", msg==NULL?"":msg, wTTTrack.getdesc( track ) );
      StrOp.free(tmp);
      track = wTurntable.nexttrack( m_Props, track );
    }
    wxMessageBox( wxString(msg,wxConvUTF8), wxString(wTurntable.getdesc(m_Props),wxConvUTF8), wxOK, this);
    StrOp.free(msg);
  }
}

void Symbol::OnHelp(wxCommandEvent& event) {
  if( StrOp.equals( wBlock.name(), NodeOp.getName( m_Props ) ) )
    wxGetApp().openLink( "block" );
  else if( StrOp.equals( wSwitch.name(), NodeOp.getName( m_Props ) ) )
    wxGetApp().openLink( "switch" );
  else if( StrOp.equals( wSignal.name(), NodeOp.getName( m_Props ) ) )
    wxGetApp().openLink( "signal" );
  else if( StrOp.equals( wFeedback.name(), NodeOp.getName( m_Props ) ) )
    wxGetApp().openLink( "sensor" );
  else if( StrOp.equals( wTrack.name(), NodeOp.getName( m_Props ) ) )
    wxGetApp().openLink( "tracks" );
  else if( StrOp.equals( wStage.name(), NodeOp.getName( m_Props ) ) )
    wxGetApp().openLink( "stage" );
  else if( StrOp.equals( wTurntable.name(), NodeOp.getName( m_Props ) ) )
    wxGetApp().openLink( "turntable" );
  else if( StrOp.equals( wOutput.name(), NodeOp.getName( m_Props ) ) )
    wxGetApp().openLink( "output" );
  else if( StrOp.equals( wText.name(), NodeOp.getName( m_Props ) ) )
    wxGetApp().openLink( "text" );
  else if( StrOp.equals( wSelTab.name(), NodeOp.getName( m_Props ) ) )
    wxGetApp().openLink( "seltab" );
  else if( StrOp.equals( wRoute.name(), NodeOp.getName( m_Props ) ) )
    wxGetApp().openLink( "route" );
}


void Symbol::OnProps(wxCommandEvent& event) {
  bool refresh = true;
  const char* name = NodeOp.getName( m_Props );

  if( StrOp.equals( wBlock.name(), name ) ) {
    BlockDialog* blockDlg = NULL;
    blockDlg = new BlockDialog( this, m_Props );
    blockDlg->ShowModal();
    updateLabel();
    sizeToScale();
    blockDlg->Destroy();
  }
  else if( StrOp.equals( wSwitch.name(), name ) ) {
    SwitchDialog* swDlg = new SwitchDialog( this, m_Props );
    swDlg->ShowModal();
    sizeToScale();
    Show(wSwitch.isshow(m_Props));
    swDlg->Destroy();
  }
  else if( StrOp.equals( wSignal.name(), name ) ) {
    SignalDialog* sgDlg = new SignalDialog( this, m_Props );
    sgDlg->ShowModal();
    sgDlg->Destroy();
  }
  else if( StrOp.equals( wOutput.name(), name ) ) {
    OutputDialog* coDlg = new OutputDialog( this, m_Props );
    coDlg->ShowModal();
    Show(wOutput.isshow(m_Props));
    coDlg->Destroy();
  }
  else if( StrOp.equals( wFeedback.name(), name ) ) {
    FeedbackDialog* fbDlg = new FeedbackDialog( this, m_Props );
    fbDlg->ShowModal();
    Show(wFeedback.isshow(m_Props));
    fbDlg->Destroy();
  }
  else if( StrOp.equals( wRoute.name(), name ) ) {
    RouteDialog* dlg = new RouteDialog( this, m_Props );
    dlg->ShowModal();
    Show(wRoute.isshow(m_Props));
    dlg->Destroy();
  }
  else if( StrOp.equals( wTrack.name(), name ) ) {
    TrackDialog* tkDlg = new TrackDialog( this, m_Props );
    tkDlg->ShowModal();
    tkDlg->Destroy();
  }
  else if( StrOp.equals( wText.name(), name ) ) {
    TextDialog* txDlg = new TextDialog( this, m_Props );
    txDlg->ShowModal();
    txDlg->Destroy();
  }
  else if( StrOp.equals( wTurntable.name(), name ) ) {
    TurntableDialog* ttDlg = new TurntableDialog( this, m_Props );
    ttDlg->ShowModal();
    ttDlg->Destroy();
  }
  else if( StrOp.equals( wSelTab.name(), name ) ) {
    /* dialog for selection table */
    SelTabDialog* dlg = new SelTabDialog( this, m_Props );
    dlg->ShowModal();
    dlg->Destroy();
  }
  else if( StrOp.equals( wStage.name(), name ) ) {
    StageDlg* dlg = new StageDlg( this, m_Props );
    dlg->ShowModal();
    dlg->Destroy();
  }
  else {
    refresh = false;
  }

  if( refresh ) {
    Refresh();
    if( wxGetApp().isOffline() ) {
      char key[256];
      char prev_key[256];
      m_PlanPanel->itemKey( m_Props, key, prev_key );
      if( !StrOp.equals(key, prev_key) )
        m_PlanPanel->ChangeItemKey(key, prev_key);
      modelEvent(m_Props, False);
    }
  }

}


void Symbol::OnSelect(wxCommandEvent& event) {
  // inform parent panel of a select and position
  wxCommandEvent evt( wxEVT_COMMAND_MENU_SELECTED, ME_PanelSelect );
  iONode sel = NodeOp.inst( "selection", NULL, ELEMENT_NODE );
  NodeOp.setInt( sel, "x", wItem.getx(m_Props) );
  NodeOp.setInt( sel, "y", wItem.gety(m_Props) );
  NodeOp.setInt( sel, "z", wItem.getz(m_Props) );
  NodeOp.setInt( sel, "cx", 1 );
  NodeOp.setInt( sel, "cy", 1 );
  evt.SetClientData( sel );
  wxPostEvent( m_PlanPanel, evt );
}


void Symbol::OnRotate(wxCommandEvent& event) {
  if( !wxGetApp().getFrame()->isEditMode() )
    return;

  const char* ori = wItem.getori( m_Props );

  if( event.GetId() == ME_North )
    wItem.setori( m_Props, wItem.north );
  else if( event.GetId() == ME_East )
    wItem.setori( m_Props, wItem.east );
  else if( event.GetId() == ME_South )
    wItem.setori( m_Props, wItem.south );
  else if( event.GetId() == ME_West )
    wItem.setori( m_Props, wItem.west );
  else {

    if( ori == NULL || StrOp.len(ori) == 0 ) {
      ori = wItem.west;
      wItem.setori( m_Props, wItem.west );
    }

    if( StrOp.equals( wItem.west, ori ) )
      wItem.setori( m_Props, wItem.north );
    else if( StrOp.equals( wItem.north, ori ) )
      wItem.setori( m_Props, wItem.east );
    else if( StrOp.equals( wItem.east, ori ) )
      wItem.setori( m_Props, wItem.south );
    else if( StrOp.equals( wItem.south, ori ) )
      wItem.setori( m_Props, wItem.west );
  }

  if( StrOp.equals( wItem.west, wItem.getori(m_Props) ) )
    m_PlanPanel->m_Ori = wItem.west;
  else if( StrOp.equals( wItem.north, wItem.getori(m_Props) ) )
    m_PlanPanel->m_Ori = wItem.north;
  else if( StrOp.equals( wItem.east, wItem.getori(m_Props) ) )
    m_PlanPanel->m_Ori = wItem.east;
  else if( StrOp.equals( wItem.south, wItem.getori(m_Props) ) )
    m_PlanPanel->m_Ori = wItem.south;

  Refresh();

  if( !wxGetApp().isStayOffline() ) {
    /* Notify RocRail. */
    iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
    wModelCmd.setcmd( cmd, wModelCmd.modify );
    iONode item = (iONode)NodeOp.base.clone( m_Props );
    NodeOp.addChild( cmd, item );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del( cmd );
  }
  else {
    wxGetApp().setLocalModelModified(true);
  }

}

void Symbol::OnType(wxCommandEvent& event) {
  const char* name = NodeOp.getName( m_Props );

  if( StrOp.equals( wTrack.name(), name ) ) {
    const char* type = wTrack.gettype( m_Props );
    if( StrOp.equals( wTrack.straight, type ) )
      wTrack.settype( m_Props, wTrack.curve );
    else
      wTrack.settype( m_Props, wTrack.straight );
  }
  else if( StrOp.equals( wSwitch.name(), name ) ) {
    const char* type = wSwitch.gettype( m_Props );
    if( StrOp.equals( wSwitch.crossing, type ) )
      wSwitch.settype( m_Props, wSwitch.right );
    else if( StrOp.equals( wSwitch.right, type ) )
      wSwitch.settype( m_Props, wSwitch.left );
    else if( StrOp.equals( wSwitch.left, type ) )
      wSwitch.settype( m_Props, wSwitch.threeway );
    else
      wSwitch.settype( m_Props, wSwitch.crossing );
  }
  else
    return;

  Refresh();

  /* Notify RocRail. */
  iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
  wModelCmd.setcmd( cmd, wModelCmd.modify );
  iONode item = NodeOp.inst( NodeOp.getName( m_Props ), NULL, ELEMENT_NODE );
  wItem.setid( item, wItem.getid( m_Props ) );
  wItem.settype( item, wItem.gettype( m_Props ) );
  NodeOp.addChild( cmd, item );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del( cmd );
}

void Symbol::OnCopy(wxCommandEvent& event) {
  wxClipboard* cb = wxTheClipboard;
  if( cb != NULL ) {
    if( cb->Open() ) {
      iONode clone = (iONode)NodeOp.base.clone(m_Props);
      char* id = StrOp.fmt("%s-copy", wItem.getid(clone));
      wItem.setid(clone, id);
      StrOp.free(id);
      char* xmlStr = NodeOp.base.toString( clone );
      wxString text( xmlStr, wxConvUTF8 );
      wxTextDataObject *data = new wxTextDataObject( text );
      cb->SetData( data );
      cb->Close();
      StrOp.free(xmlStr);
    }
  }
}


void Symbol::OnDelete(wxCommandEvent& event) {
  if( !wxGetApp().getFrame()->isEditMode() )
    return;

  wxGetApp().pushUndoItem( (iONode)NodeOp.base.clone( m_Props ) );

  if( wxGetApp().isOffline() ) {
    m_PlanPanel->removeItemFromList( m_Props );
  }

  wxGetApp().setLocalModelModified(true);

  /* Notify RocRail. */
  iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
  wModelCmd.setcmd( cmd, wModelCmd.remove );
  iONode item = NodeOp.inst( NodeOp.getName( m_Props ), NULL, ELEMENT_NODE );
  wItem.setid( item, wItem.getid( m_Props ) );
  NodeOp.addChild( cmd, item );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del( cmd );

}

void Symbol::OnTTLight(wxCommandEvent& event) {
  iONode cmd = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
  wTurntable.setid( cmd, wTurntable.getid( m_Props ) );
  wTurntable.setcmd( cmd, (event.GetId()==ME_TTLightOn?wTurntable.lighton:wTurntable.lightoff) );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnTTNext(wxCommandEvent& event) {
  iONode cmd = NodeOp.inst( NodeOp.getName(m_Props), NULL, ELEMENT_NODE );
  wTurntable.setid( cmd, wTurntable.getid( m_Props ) );
  wTurntable.setcmd( cmd, wTurntable.next );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnTTPrev(wxCommandEvent& event) {
  iONode cmd = NodeOp.inst( NodeOp.getName(m_Props), NULL, ELEMENT_NODE );
  wTurntable.setid( cmd, wTurntable.getid( m_Props ) );
  wTurntable.setcmd( cmd, wTurntable.prev );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnTT180(wxCommandEvent& event) {
  iONode cmd = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
  wTurntable.setid( cmd, wTurntable.getid( m_Props ) );
  wTurntable.setcmd( cmd, wTurntable.turn180 );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnTTCalibrate(wxCommandEvent& event) {
  iONode cmd = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
  wTurntable.setid( cmd, wTurntable.getid( m_Props ) );
  wTurntable.setcmd( cmd, wTurntable.calibrate );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::OnTTTrack(wxCommandEvent& event) {
  iONode cmd = NodeOp.inst( NodeOp.getName(m_Props), NULL, ELEMENT_NODE );
  wTurntable.setid( cmd, wTurntable.getid( m_Props ) );
  char* tracknr = StrOp.fmt( "%d", event.GetId() - ME_TTTrack );
  wTurntable.setcmd( cmd, tracknr );
  StrOp.free( tracknr );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void Symbol::showTooltip(bool show) {
  if( !StrOp.equals( wTrack.name(), NodeOp.getName( m_Props ) ) && !StrOp.equals( wText.name(), NodeOp.getName( m_Props ) ) ) {
    if( wxGetApp().getFrame()->isTooltip() && m_Tip != NULL) {
      SetToolTip( wxString(m_Tip,wxConvUTF8) );
    }
    else {
      SetToolTip( wxString("",wxConvUTF8) );
    }
  }
}

void Symbol::modelEvent( iONode node, bool oncreate ) {
  bool refresh = false;
  const char* id = wItem.getid( node );

  TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999,
      "Symbol::modelEvent id=[%s] ori=%s state=%s", id, wItem.getori(node)!=NULL?wItem.getori(node):"-", wItem.getstate(node) );

  if( StrOp.equals( NodeOp.getName( node ), NodeOp.getName( m_Props ) ) ) {
    int x = wItem.getx( node );
    int y = wItem.gety( node );

    if( NodeOp.findAttr(node, "z") ) {
      int z = wItem.getz( node );
      wItem.setz( m_Props, z );
    }

    // ToDo: Merge Node!?
    if( !wBlock.isupdateenterside(node) ) {
      NodeOp.mergeNode( m_Props, node, True, False, True);

      // Process signal quality:
      if( StrOp.equals( wFeedback.name(), NodeOp.getName( m_Props ) ) &&
          StrOp.equals(wFeedback.getcmd(node), wFeedback.signalquality) )
      {
        // replace all child nodes...
        if( !oncreate && NodeOp.getChildCnt(node) > 0 && node != m_Props) {


          iONode fbstatistic = wFeedback.getfbstatistic( m_Props );
          while( fbstatistic != NULL ) {
            NodeOp.removeChild( m_Props, fbstatistic);
            NodeOp.base.del(fbstatistic);
            fbstatistic = wFeedback.getfbstatistic( m_Props );
          };

          fbstatistic = wFeedback.getfbstatistic(node);

          /* loop over all actions */
          while( fbstatistic != NULL ) {
            NodeOp.addChild( m_Props, (iONode)NodeOp.base.clone(fbstatistic) );
            fbstatistic = wFeedback.nextfbstatistic( node, fbstatistic );
          };
        }
      }


    }

    if( x != -1 && y != -1 ) {
      wItem.setx( m_Props, x );
      wItem.sety( m_Props, y );
      if( wItem.getori(node) != NULL && StrOp.len(wItem.getori(node)) > 0 ) {
        TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "%s set ori=%s", wItem.getid(node), wItem.getori(node) );
        wItem.setori( m_Props, wItem.getori( node ) );
      }
      if( !oncreate )
        setPosition();
    }

    if( !oncreate && !wxGetApp().getFrame()->isAutoMode() )
      m_Renderer->initSym();
    sizeToScale();
  }

  if( id != NULL && StrOp.len(id) > 0 && !StrOp.equals( id, wItem.getid( m_Props ) ) ) {
    if( StrOp.equals( wTurntable.name(), NodeOp.getName( m_Props ) ) ) {
      // Could be a turntable (invisible) feedback...
      iONode track = wTurntable.gettrack( m_Props );
      TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "sensor [%s] event for turntable", id );
      while( track != NULL ) {
        if( StrOp.len(wTTTrack.getposfb(track)) > 0 && StrOp.equals( id, wTTTrack.getposfb( track ) ) ) {
          TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "posfb \"%s\" for nr %d = %s",
                       id, wTTTrack.getnr( track ),
                       wFeedback.isstate( node ) ? "ON":"OFF" );
          wTTTrack.setstate( track, wFeedback.isstate( node ) );
          if( wFeedback.isstate( node ) )
            wTurntable.setbridgepos(m_Props, wTTTrack.getnr( track ));
        }
        track = wTurntable.nexttrack( m_Props, track );
      }
    }
    Refresh();
    return;
  }

  StrOp.free(m_Tip);
  if( StrOp.len( wItem.getdesc( m_Props ) ) > 0 )
    m_Tip = StrOp.dup(wItem.getdesc( m_Props ));
  else
    m_Tip = StrOp.dup(wItem.getid( m_Props ));

  showTooltip(wxGetApp().getFrame()->isTooltip());

  if( StrOp.equals( wSignal.name(), NodeOp.getName( m_Props ) ) ) {
    TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "signal %s set to %s, state=%s aspect=%d",
        wSignal.getid(node), wSignal.ismanual(node) ? "manual":"auto", wSignal.getstate(node) , wSignal.getaspect(node) );
    wSignal.setmanual( m_Props, wSignal.ismanual(node) );

    if( StrOp.equals( wSignal.blockstate, wSignal.getsignal( m_Props ) ) ) {
      TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "blockstate: [%s]", wSignal.getid( m_Props ));
      // ToDo: Change blockstate label?
    }
  }

  if( StrOp.equals( wTurntable.name(), NodeOp.getName( m_Props ) ) ) {
    if( StrOp.equals( wTurntable.name(), NodeOp.getName(node)) ) {
      // turntable bridge position
      int pos = wTurntable.getbridgepos( node );
      wTurntable.setbridgepos(m_Props, pos );
      wTurntable.setstate1(m_Props, wTurntable.isstate1( node ) );
      wTurntable.setstate2(m_Props, wTurntable.isstate2( node ) );
      wTurntable.setstateMid(m_Props, wTurntable.isstateMid( node ) );
      wTurntable.setlocid(m_Props, wTurntable.getlocid( node ) );
      TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "bridgepos=%d %s=%s", pos, NodeOp.getName(node), id==NULL?"-":id );
      refresh = true;
      iONode track = wTurntable.gettrack( m_Props );
      while( track != NULL ) {
        int tracknr = wTTTrack.getnr( track );
        wTTTrack.setstate( track, tracknr == pos ? True:False );
        track = wTurntable.nexttrack( m_Props, track );
      }
    }
  }

  const char* type = wItem.gettype( node );
  if( type != NULL ) {
    if( !StrOp.equals( type, wItem.gettype( m_Props ) ) ) {
      wItem.settype( m_Props, type );
      refresh = true;
    }
  }

  const char* ori = wItem.getori( node );
  if( ori != NULL && !StrOp.equals( wModelCmd.getcmd( node), wModelCmd.move) ) {
    if( !StrOp.equals( ori, wItem.getori( m_Props ) ) ) {
        wItem.setori( m_Props, ori );
      refresh = true;
    }
  }

  if( wItem.getstate( node ) != NULL && StrOp.len(wItem.getstate( node )) > 0 ) {
    if( !StrOp.equals( wItem.getstate( node ), wItem.getstate( m_Props ) ) ) {
      wItem.setstate( m_Props, wItem.getstate( node ) );
      refresh = true;
    }
  }


  if( StrOp.equals( wFeedback.name(), NodeOp.getName( m_Props ) ) ) {
    Boolean state = wFeedback.isstate( node );
    const char* ident = wFeedback.getidentifier( node );
    int counter = wFeedback.getcounter( node );
    int wheelcount = wFeedback.getwheelcount( node );
    int carcount = wFeedback.getcarcount( node );
    int countedcars = wFeedback.getcountedcars( node );
    int val = wFeedback.getval( node );
    int load = wFeedback.getload( node );
    int bus = wFeedback.getbus( m_Props );
    int addr = wFeedback.getaddr( m_Props );
    const char* info = wFeedback.getinfo( node );

    StrOp.free(m_Tip);
    m_Tip = StrOp.fmt( "%s addr=%d:%d ident=%s val=%d count=%d info=%s cars=%d/%d wheelcount=%d load=%d",
                           wFeedback.getid( node ), bus, addr, ident, val, counter, info, countedcars, carcount, wheelcount, load );

    showTooltip(wxGetApp().getFrame()->isTooltip());

    if( StrOp.len(ident) > 0 )
      wxGetApp().getFrame()->setInfoText( m_Tip );

    SetBackgroundColour( wFeedback.isshortcut(node) ? *wxRED:m_PlanPanel->GetBackgroundColour() );

    if( !wFeedback.isshortcut(node) ) {
      if( load > 0 && wFeedback.getmaxload(node) > 0 ) {
        wxColour color( m_PlanPanel->GetBackgroundColour());
        int maxload = wFeedback.getmaxload(node);
        int red = (load * 255) / maxload;
        if( red > 255 )
          red = 255;
        color.Set(255, 255-red, 255-red);
        SetBackgroundColour(color);
      }
    }

    wFeedback.setshortcut( m_Props, wFeedback.isshortcut(node) );
    wFeedback.setstate( m_Props, state );
    wFeedback.setcounter( m_Props, wFeedback.getcounter( node ) );
    wFeedback.setwheelcount( m_Props, wFeedback.getwheelcount( node ) );
    wFeedback.setcarcount( m_Props, wFeedback.getcarcount( node ) );
    wFeedback.setcountedcars( m_Props, wFeedback.getcountedcars( node ) );
    wFeedback.setidentifier( m_Props, wFeedback.getidentifier( node ) );
    wFeedback.setval( m_Props, wFeedback.getval( node ) );
    wFeedback.setload( m_Props, wFeedback.getload( node ) );
    wFeedback.setmaxload( m_Props, wFeedback.getmaxload( node ) );

    m_PlanPanel->blockEvent( wFeedback.getid( m_Props ) );
    refresh = true;
  }
  else if( StrOp.equals( wRoute.name(), NodeOp.getName( m_Props ) ) ) {
    int status = wRoute.getstatus( node );
    const char* locid = wRoute.getlocid( node );

    StrOp.free(m_Tip);
    m_Tip = StrOp.fmt( "%s lock=%s",
                           wRoute.getid( node ), locid == NULL ? "unlocked":locid );
    showTooltip(wxGetApp().getFrame()->isTooltip());

    wRoute.setstatus( m_Props, status );
  }
  else if( StrOp.equals( wSwitch.name(), NodeOp.getName( m_Props ) ) ) {
    const char* state = wSwitch.getstate( node );
    const char* wantedstate = wSwitch.getwantedstate( node );
    const char* fieldstate = wSwitch.getfieldstate( node );
    const char* savepos = wSwitch.getsavepos( node );
    const char* locid = wSwitch.getlocid( node );
    Boolean isSet = wSwitch.isset(node);
    Boolean isLocked = (wSwitch.getlocid( node )==NULL?False:True);
    int bus   = wSwitch.getbus( m_Props );
    int port  = wSwitch.getport1( m_Props );
    int addr  = wSwitch.getaddr1( m_Props );
    int gate  = wSwitch.getgate1( m_Props );
    int port2 = wSwitch.getport2( m_Props );
    int addr2 = wSwitch.getaddr2( m_Props );
    int gate2 = wSwitch.getgate2( m_Props );
    int pada  = 0;
    int pada2 = 0;

    char* l_locidStr = NULL;
    if( state != NULL ) {
      wSwitch.setstate( m_Props, state );
      refresh = true;
    }

    wSwitch.setswitched( m_Props, wSwitch.getswitched(node) );
    wSwitch.settesting( m_Props, wSwitch.istesting(node) );

    if( wSwitch.getlocid( node )!=NULL && StrOp.equals( wSwitch.unlocked, wSwitch.getlocid( node )) )
      isLocked = False;

    wxColor bgcolor = m_PlanPanel->GetBackgroundColour();
    if( (isLocked ) && wxGetApp().getFrame()->isShowLocked() ) {
      bgcolor = Base::getRed();
    }
    if( !isSet && wxGetApp().getFrame()->isShowPending() ) {
      bgcolor = *wxRED;
    }
    SetBackgroundColour( bgcolor );

    if( addr > 0 && port > 0 ) {
      pada = (addr-1) * 4 + port;
      addr = (addr-1) * 8 + (port-1) * 2 + gate;
    }
    else if( addr == 0 && port > 0 )
      addr = port;

    if( addr2 > 0 && port2 > 0 ) {
      pada2 = (addr2-1) * 4 + port2;
      addr2 = (addr2-1) * 8 + (port2-1) * 2 + gate2;
    }
    else if( addr2 == 0 && port2 > 0 )
      addr2 = port2;

    if( !StrOp.equals( wSwitch.decoupler, wSwitch.gettype( m_Props ) ) ) {
      if( addr2 > 0 || pada2 > 0 )
        l_locidStr = StrOp.fmt( "%s addr1=%d:%d(%d) addr2=%d(%d) lock=%s", wSwitch.getid( node ), bus, addr, pada, addr2, pada2,
                             wSwitch.getlocid( node )==NULL?"unlocked":wSwitch.getlocid( node ) );
      else
        l_locidStr = StrOp.fmt( "%s addr=%d:%d(%d) lock=%s", wSwitch.getid( node ), bus, addr, pada,
                             wSwitch.getlocid( node )==NULL?"unlocked":wSwitch.getlocid( node ) );
      StrOp.free(m_Tip);
      m_Tip = StrOp.dup(l_locidStr);
      StrOp.free( m_locidStr );
      m_locidStr = l_locidStr;
      showTooltip(wxGetApp().getFrame()->isTooltip());
    }

  }
  else if( StrOp.equals( wSignal.name(), NodeOp.getName( m_Props ) ) ) {
    const char* state = wSignal.getstate( node );
    wSignal.setaspect( m_Props, wSignal.getaspect( node ) );
    if( state != NULL ) {
      wSignal.setstate( m_Props, state );
      refresh = true;
    }

    int port = wSignal.getport1( m_Props );
    int bus  = wSignal.getbus( m_Props );
    int addr = wSignal.getaddr( m_Props );
    int gate = wSignal.getgate1( m_Props );
    int pada = 0;

    char* l_tipStr = NULL;

    if( addr > 0 && port > 0 ) {
      pada = (addr-1) * 4 + port;
      addr = (addr-1) * 8 + (port-1) * 2 + gate;
    }
    else if( addr == 0 && port > 0 )
      pada = port;

    l_tipStr = StrOp.fmt( "%s addr=%d:%d(%d)",
                           wSignal.getid( node ),
                           bus, addr, pada );

    StrOp.free( m_locidStr );
    m_locidStr = l_tipStr;
    StrOp.free(m_Tip);
    m_Tip = StrOp.dup(l_tipStr);

    showTooltip(wxGetApp().getFrame()->isTooltip());
  }
  else if( StrOp.equals( wOutput.name(), NodeOp.getName( m_Props ) ) ) {
    const char* state = wOutput.getstate( node );
    iONode color = wOutput.getcolor(node);
    int value = wOutput.getvalue( node );
    if( state != NULL ) {
      wOutput.setstate( m_Props, state );
      refresh = true;
    }
    if( wOutput.getvalue(m_Props) != value ) {
      wOutput.setvalue(m_Props, value);
      refresh = true;
    }
    if( color != NULL ) {
      iONode oldColor = wOutput.getcolor(m_Props);
      if( oldColor != NULL ) {
        NodeOp.removeChild( m_Props, oldColor);
      }
      NodeOp.addChild( m_Props, (iONode)NodeOp.base.clone(color));
      refresh = true;
    }
  }
  else if( StrOp.equals( wSelTab.name(), NodeOp.getName( m_Props ) ) || StrOp.equals( wTurntable.name(), NodeOp.getName( m_Props ) ) ) {
    char*  l_locidStr = NULL;
    Boolean updateEnterside = wBlock.isupdateenterside(node);
    const char* locId = wSelTab.getlocid( node );
    const char* state = wSelTab.getstate( node );
    Boolean   pending = wSelTab.ispending(node);

    if(updateEnterside) {
      // reset update flag
      wBlock.setupdateenterside(node, False);
      // preserve flags
      locId = wSelTab.getlocid( m_Props );
    }
    else {
      wSelTab.setlocid( m_Props, locId );
    }

    wSelTab.setstate( m_Props, state );
    if( StrOp.equals( wBlock.open, state ) ) {
      wSelTab.setpending( m_Props, pending );
      wSelTab.setlocid( m_Props, locId );

      int occupied = 0;
      int tablepos = wSelTab.getpos( node );
      if( tablepos != -1 )
        wSelTab.setpos( m_Props, wSelTab.getpos( node ));
      else
        tablepos = wSelTab.getpos( m_Props );

      l_locidStr = StrOp.fmt( "%s[%d] %s",
          wSelTab.getid( m_Props ), tablepos, locId==NULL?"unlocked":locId );
    }
    else {
      l_locidStr = StrOp.fmt( "%s: CLOSED", wSelTab.getid( m_Props ) );
    }

    StrOp.free(m_Tip);
    m_Tip = StrOp.dup( l_locidStr );

    showTooltip(wxGetApp().getFrame()->isTooltip());

    m_Renderer->setLabel( l_locidStr, pending );
    StrOp.free( m_locidStr );
    m_locidStr = l_locidStr;

    TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "id=[%s] pending=[%s] state=[%s] updateenter=%d %s",
        id, pending?"true":"false", state, updateEnterside, m_locidStr );

  }
  else if( StrOp.equals( wText.name(), NodeOp.getName( m_Props ) ) ) {
    if( wText.gettext(node) != NULL ) {
      wText.settext(m_Props, wText.gettext(node) );
      m_Renderer->setLabel(wText.gettext(node), 0);
      TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "new text %s", wText.gettext(node) );
      refresh = true;
      checkSpeakAction(node);
    }
  }

  else if( StrOp.equals( wStage.name(), NodeOp.getName( m_Props ) ) ) {
    char* l_locidStr = NULL;
    const char* locid = wStage.getlocid( node );
    int nrlocos = 0;
    int occupied = 0;
    Boolean isReserved    = wStage.isreserved( node );
    Boolean isEntering    = wStage.isentering( node );

    StrOp.free(m_Tip);
    m_Tip = StrOp.dup(wStage.getid( node ));

    wStage.setreserved( m_Props, isReserved );
    wStage.setlocid( m_Props, locid );

    // update sections
    iONode section = wStage.getsection(node);
    while( section != NULL ) {
      iONode l_section = wStage.getsection(m_Props);
      if(wStageSection.getlcid(section) != NULL && StrOp.len( wStageSection.getlcid(section) ) > 0 ) {
        char* formatS = NULL;
        if( SystemOp.isWindows() )
          formatS = StrOp.fmt(", %s: %s", wStageSection.getid(section), wStageSection.getlcid(section));
        else
          formatS = StrOp.fmt("\n%s: %s", wStageSection.getid(section), wStageSection.getlcid(section));
        nrlocos++;
        m_Tip = StrOp.cat( m_Tip, formatS);
        StrOp.free(formatS);
      }
      while( section != NULL ) {
        if( StrOp.equals( wStageSection.getid( section ), wStageSection.getid( l_section ) ) ) {
          wStageSection.setlcid( l_section, wStageSection.getlcid( section ) );
          break;
        }
        l_section = wStage.nextsection(m_Props, l_section);
      }

      section = wStage.nextsection(node, section);
    }

    if (locid!=NULL && StrOp.len(locid)>0) {
      occupied = isReserved ? 2:1;
      occupied = isEntering ? 3:occupied;
      occupied = StrOp.equals(wBlock.closed,wStage.getstate( node ))?4:occupied;
    }
    // Ghost
    else if( StrOp.equals( wBlock.ghost, wStage.getstate( node ) ) ) {
      wStage.setstate( m_Props, wStage.getstate( node ) );
      l_locidStr = StrOp.fmt( "%s GHOST", wStage.getid( m_Props ) );
      occupied = 5;
    }
    else {
      wStage.setstate( m_Props, wStage.getstate( node ) );
      occupied = StrOp.equals(wBlock.closed,wStage.getstate( node ))?4:occupied;
    }

    if( NodeOp.findAttr( node, "exitstate" ) ) {
      wStage.setexitstate( m_Props, wStage.getexitstate( node ) );
    }

    if( locid != NULL && StrOp.len( locid ) > 0 )
      l_locidStr = StrOp.fmt( "%s %s", wStage.getid( node ), locid );
    else if( nrlocos > 0 )
      l_locidStr = StrOp.fmt( "%s [%d]%s",
          wStage.getid( node ), nrlocos, StrOp.equals(wBlock.closed,wStage.getexitstate(m_Props))?"<":"" );
    else if( occupied != 5)
      l_locidStr = StrOp.fmt( "%s %s", wStage.getid( node ), StrOp.equals(wBlock.closed,wStage.getexitstate(m_Props))?"<":"" );

    m_Renderer->setLabel( l_locidStr, occupied, false );
    StrOp.free( m_locidStr );
    m_locidStr = l_locidStr;
    TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "%s, occupied=%d", m_locidStr, occupied );

    showTooltip(wxGetApp().getFrame()->isTooltip());
  }

  else if( StrOp.equals( wStage.name(), NodeOp.getName( m_Props ) ) ) {
  }

  else if( StrOp.equals( wBlock.name(), NodeOp.getName( m_Props ) ) ) {
    char* l_locidStr = NULL;
    Boolean updateEnterside = wBlock.isupdateenterside(node);
    const char* state   = wBlock.getstate( node );
    const char* locoid  = wBlock.getlocid( node );
    const char* trainid = "";
    int occupied = 0;
    Boolean showID = True;
    Symbol* StateSignal = NULL;

    m_Renderer->setLocoImage("");
    m_Renderer->setLocoPlacing(true);
    m_Renderer->setLocoManual(false);

    if(wBlock.getstatesignal(m_Props) != NULL && StrOp.len(wBlock.getstatesignal(m_Props)) > 0 ) {
      iONode sg = wxGetApp().getFrame()->findSignal( wBlock.getstatesignal(m_Props) );
      if( sg != NULL ) {
        char key[256];
        m_PlanPanel->itemKey( sg, key, NULL );
        StateSignal = wxGetApp().getFrame()->GetItem(key);
      }
    }


    if( locoid == NULL ) {
      locoid = "";
      if( StateSignal != NULL ) {
        TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "blockstate: [%s]", wBlock.getstatesignal(m_Props));
        StateSignal->Blockstate(m_Props, NULL);
      }
    }
    else {
      iONode loc = wxGetApp().getFrame()->findLoc( updateEnterside ? wBlock.getlocid(m_Props):locoid );
      if( loc != NULL ) {
        if( wGui.isshowlocoimageinblock(wxGetApp().getIni()) ) {
          m_Renderer->setLocoImage(wLoc.getimage(loc));
          m_Renderer->setLocoPlacing(wLoc.isplacing(loc)?true:false);
        }
        trainid = wLoc.gettrain(loc);
        if( StateSignal != NULL ) {
          TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "blockstate: [%s]", wBlock.getstatesignal(m_Props));
          StateSignal->Blockstate(m_Props, loc);
        }
      }
      else {
        if( StateSignal != NULL ) {
          TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "blockstate: [%s]", wBlock.getstatesignal(m_Props));
          StateSignal->Blockstate(m_Props, NULL);
        }
      }
    }

    const char* fifoids = wBlock.getfifoids(node);

    if( updateEnterside ) {
      // reset update flag
      wBlock.setupdateenterside(node, False);
      // preserve flags
      locoid  = wBlock.getlocid( m_Props );
      fifoids = wBlock.getfifoids(m_Props);
      wBlock.setreserved( node, wBlock.isreserved( m_Props ) );
      wBlock.setentering( node, wBlock.isentering( m_Props ) );
    }
    else {
      wBlock.setlocid( m_Props, locoid );
      wBlock.setfifoids( m_Props, fifoids );
    }

    iONode planpanelIni = wGui.getplanpanel(wxGetApp().getIni());
    if( planpanelIni != NULL ) {
      showID = wPlanPanel.isbktextid(planpanelIni);
    }

    Boolean isAcceptIdent = wBlock.isacceptident( node );
    TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999,
        "Block=%s locoID=%s State=%s updateEnterside=%d reserved=%d AcceptIdent=%d desc=%s",
        wBlock.getid( node ), locoid, state, updateEnterside, wBlock.isreserved( node ), isAcceptIdent, wBlock.getdesc(node) );

    wBlock.setstate( m_Props, state );

    char* carList = wxGetApp().getFrame()->listCars(wBlock.getid(m_Props));
    bool hasCars = (carList==NULL ? false:true);
    if( hasCars )
      TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "block %s has cars: %s", wBlock.getid(m_Props), carList);
    // Open block
    if( StrOp.equals( wBlock.open, state ) ) {
      Boolean isReserved    = wBlock.isreserved( node );
      Boolean isEntering    = wBlock.isentering( node );

      if( fifoids != NULL && StrOp.len(fifoids) == 0 )
        fifoids = NULL;

      wBlock.setreserved( m_Props, isReserved );

      Boolean showLocoImage = wGui.isshowlocoimageinblock(wxGetApp().getIni());
      Boolean smallSymbol   = wBlock.issmallsymbol(m_Props);

      if( (smallSymbol || showLocoImage) && StrOp.len(locoid) > 0 )
        l_locidStr = StrOp.fmt( "%s%s", fifoids!=NULL?fifoids:locoid, hasCars?"#":"" );
      else if( showID && (smallSymbol || showLocoImage) )
        l_locidStr = StrOp.fmt( "%s%s", wBlock.getid( node ), hasCars?"#":"" );
      else {
        if(showID && fifoids == NULL) {
          if( wGui.isshowtrainidinblock(wxGetApp().getIni()) && trainid != NULL && StrOp.len(trainid) > 0 )
            l_locidStr = StrOp.fmt( "%s%s%s_%s", wBlock.getid( node ), hasCars?"#":" ", locoid, trainid );
          else
            l_locidStr = StrOp.fmt( "%s%s%s", wBlock.getid( node ), hasCars?"#":" ", locoid );
        }
        else
          l_locidStr = StrOp.fmt( "%s%s", fifoids!=NULL?fifoids:locoid, hasCars?"#":"" );
      }

      // compose the ToolTip and update occupied state
      if( StrOp.len( locoid ) > 0 ) {
        char* tip = NULL;
        if( hasCars )
          tip = StrOp.fmt( "%s#%s", fifoids!=NULL?fifoids:locoid, carList );
        else
          tip = StrOp.fmt( wxGetApp().getMsg("clickblock").mb_str(wxConvUTF8), fifoids!=NULL?fifoids:locoid );

        StrOp.free(m_Tip);
        m_Tip = StrOp.fmt("%s: %s", wBlock.getid( node ), tip);
        StrOp.free(tip);
        showTooltip(wxGetApp().getFrame()->isTooltip());

        occupied = isReserved ? 2:1;
        occupied = isEntering ? 3:occupied;
        occupied = StrOp.equals(wBlock.closed,wBlock.getstate( node ))?4:occupied;
      }
      else {
        char* tip = NULL;
        if( hasCars )
          tip = StrOp.fmt( "%s: %s", wBlock.getid( node ), carList );
        else
          tip = StrOp.fmt( "%s", wBlock.getid( node ) );
        occupied = isAcceptIdent ? 7:occupied;
        StrOp.free(m_Tip);
        m_Tip = tip;
        showTooltip(wxGetApp().getFrame()->isTooltip());
      }

      // Check block enterside
      // ToDo: Update enterside on D&D...
      if( m_DandD && StrOp.len(locoid) > 0) {
        TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "D&D updateEnterside=%d locoid=%s blockid=%s occupied=%d m_RotateSym=%d",
            updateEnterside, locoid, wBlock.getid( node ), occupied, m_RotateSym );
        m_DandD = false;
        oncreate = true;
      }

      if( updateEnterside || oncreate ) {
        if( StrOp.len(locoid) > 0 ) {
          iONode loc = wxGetApp().getFrame()->findLoc( locoid );
          if( loc != NULL ) {
            m_Renderer->setLocoManual(wLoc.ismanual(loc));
            // adjust destination block enterside on update
            if( (occupied == 1 || occupied == 3) && StrOp.equals( wBlock.getid( m_Props ), wLoc.getdestblockid(loc) ) ) {
              m_RotateSym = wLoc.isblockenterside( loc);
              TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "(update) locoid=[%s] enterside=[%c]", locoid, m_RotateSym?'+':'-' );
            }

            // adjust destination block enterside on update
            else if( (occupied == 1 || occupied == 3) && (wLoc.getdestblockid(loc) == NULL || StrOp.len(wLoc.getdestblockid(loc)) == 0) ) {
              m_RotateSym = wLoc.isblockenterside( loc);
              TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "(update) locoid=[%s] enterside=[%c]", locoid, m_RotateSym?'+':'-' );
            }

            // loco is set manually in this block
            else if( wBlock.getcmd(node) != NULL && StrOp.equals(wBlock.loc, wBlock.getcmd(node) ) ) {
              m_RotateSym = wLoc.isblockenterside( loc);
              TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "(set) locoid=[%s] enterside=[%c]", locoid, m_RotateSym?'+':'-' );
            }

            // adjust source block enterside onreate
            if( oncreate && StrOp.equals( wBlock.getid( m_Props ), wLoc.getblockid(loc) ) ) {
              m_RotateSym = wLoc.isblockenterside( loc);
              TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "(oncreate) locoid=[%s] enterside=[%c]", locoid, m_RotateSym?'+':'-' );
            }
          }
        }
      }

    }

    // All other block states
    else {
      // Accept
      if( !StrOp.equals( wBlock.closed, state ) && isAcceptIdent) {
        l_locidStr = StrOp.fmt( "%s Accepting", wBlock.getid( node ) );
        occupied = isAcceptIdent ? 7:occupied;
      }
      // Closed
      else if( StrOp.equals( wBlock.closed, state ) ) {
        if( !wBlock.issmallsymbol(m_Props) ) {
          l_locidStr = StrOp.fmt( "%s%sCLOSED %s", wBlock.getid( node ), hasCars?"#":" ", hasCars?carList:"" );
        }
        else {
          l_locidStr = StrOp.fmt( "%s%s%s", wBlock.getid( node ), hasCars?"#":" ", hasCars?carList:"" );
        }
        occupied = 4;
      }
      // Ghost
      else if( StrOp.equals( wBlock.ghost, state ) ) {
        l_locidStr = StrOp.fmt( "%s GHOST", wBlock.getid( node ) );
        occupied = 5;
      }
      // Shortcut
      else if( StrOp.equals( wBlock.shortcut, state ) ) {
        if(showID)
          l_locidStr = StrOp.fmt( "%s %s", wBlock.getid( node ), locoid );
        else
          l_locidStr = StrOp.fmt( "%s", StrOp.len(locoid) > 0 ? wBlock.getid( node ):locoid );
        occupied = 6;
      }
      // Other
      else {
        if( wBlock.issmallsymbol(m_Props) && StrOp.len(locoid) > 0 )
          l_locidStr = StrOp.fmt( "%s", locoid );
        else if( showID && wBlock.issmallsymbol(m_Props) )
          l_locidStr = StrOp.fmt( "%s", wBlock.getid( node ) );
        else {
          if(showID)
            l_locidStr = StrOp.fmt( "%s %s", wBlock.getid( node ), locoid );
          else
            l_locidStr = StrOp.fmt( "%s", StrOp.len(locoid) > 0 ? wBlock.getid( node ):locoid );
        }
      }

      // Tooltip for other state
      StrOp.free(m_Tip);
      m_Tip = StrOp.dup(l_locidStr);
      showTooltip(wxGetApp().getFrame()->isTooltip());

    }

    if( carList != NULL )
      StrOp.free(carList);

    TraceOp.trc( "item", TRCLEVEL_DEBUG, __LINE__, 9999, "id=[%s] occupied=[%d] rotate=[%d] state=[%s] locoid=[%s] updateenterside=%d",
        id, occupied, m_RotateSym, state, locoid, updateEnterside );

    m_Renderer->setLabel( l_locidStr, (updateEnterside && !oncreate) ? -1:occupied, m_RotateSym );
    // Free previous string.
    StrOp.free( m_locidStr );
    // Save current string in member.
    m_locidStr = l_locidStr;

    m_PlanPanel->blockEvent( wBlock.getid( m_Props ) );

  }

  Refresh();

}


double Symbol::getSize() {
  double itemSize = m_ItemSize;
  return (double)(itemSize * m_Scale);
}

void Symbol::Blockstate(iONode bk, iONode lc) {
  if( StrOp.equals(wSignal.name(), NodeOp.getName(m_Props) ) ) {
    if( lc != NULL ) {
      const char* mode = wLoc.getmode(lc);
      const char* modereason = wLoc.getmodereason(lc);
      int scidx = wLoc.getscidx(lc);
      Boolean schedule = False;
      if( wLoc.getscheduleid(lc) != NULL && StrOp.len(wLoc.getscheduleid(lc)) > 0 ) {
        schedule = (scidx == -1)?False:True;
      }
      Boolean manual = wLoc.ismanual(lc);
      Boolean nodest = StrOp.equals( wLoc.modereason_nodest, modereason);
      TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "blockstate: [%s][%s]", mode, modereason );
      if( StrOp.equals( wLoc.mode_auto, mode) )
        m_Renderer->setLabel( "A", manual?3:(schedule?5:1) );
      else if( StrOp.equals( wLoc.mode_idle, mode) )
        m_Renderer->setLabel( "O", 0 );
      else if( StrOp.equals( wLoc.mode_wait, mode) )
        m_Renderer->setLabel( "W", nodest ? (schedule?6:4):(manual?3:(schedule?5:1)) );
      else if( StrOp.equals( wLoc.mode_halfauto, mode) )
        m_Renderer->setLabel( "H", 3 );
    }
    else {
      TraceOp.trc( "item", TRCLEVEL_INFO, __LINE__, 9999, "blockstate: [%s]", "-");
      m_Renderer->setLabel( "-", 0 );
    }
    Refresh();
  }
}


