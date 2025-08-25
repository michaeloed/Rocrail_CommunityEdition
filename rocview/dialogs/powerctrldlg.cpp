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

#include "powerctrldlg.h"

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#include "wx/defs.h"
#endif

#include "rocview/public/guiapp.h"

#include "rocview/wrapper/public/Gui.h"
#include "rocview/wrapper/public/PowerCtrl.h"

#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/Plan.h"
#include "rocrail/wrapper/public/PwrCmd.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/Booster.h"
#include "rocrail/wrapper/public/BoosterList.h"
#include "rocrail/wrapper/public/BoosterEvent.h"

#include "rocs/public/trace.h"


static bool ms_SortInvert = false;

PowerCtrlDlg::PowerCtrlDlg( wxWindow* parent ):powerctrlgen( parent )
{
  m_SelBooster = NULL;
  m_BoosterMap = MapOp.inst();
  m_SelectedRow = -1;
  m_SortColumn = 0;
  initLabels();
  initValues(NULL);

  GetSizer()->Layout();
  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);

/*
  wxFont* font = new wxFont( m_TracksGrid->GetDefaultCellFont() );
  font->SetPointSize( (int)(font->GetPointSize() - 1 ) );
  m_Boosters->SetDefaultCellFont( *font );
*/
  m_Boosters->AutoSizeColumns();
  m_Boosters->AutoSizeRows();

  m_Boosters->AutoSizeColumns();
  m_Boosters->FitInside();
  GetSizer()->Layout();

  iONode ini = wxGetApp().getIni();
  iONode powerctrl = wGui.getpowerctrl(ini);
  if( powerctrl != NULL ) {
    if( wPowerCtrl.getcx(powerctrl) > 0 && wPowerCtrl.getcy(powerctrl) > 0 ) {
      SetSize(wPowerCtrl.getx(powerctrl), wPowerCtrl.gety(powerctrl), wPowerCtrl.getcx(powerctrl), wPowerCtrl.getcy(powerctrl));
      wPowerCtrl.setshow(powerctrl, True);
    }
    else
      SetSize(wPowerCtrl.getx(powerctrl), wPowerCtrl.gety(powerctrl));
  }

}


void PowerCtrlDlg::initLabels() {
  m_Boosters->AutoSizeColumns();
  m_Boosters->AutoSizeRows();

  m_Boosters->SetColLabelValue(0, wxGetApp().getMsg("boosterid") );
  m_Boosters->SetColLabelValue(1, wxGetApp().getMsg("overload") );
  m_Boosters->SetColLabelValue(2, wxGetApp().getMsg("trackpower") );
  m_Boosters->SetColLabelValue(3, wxGetApp().getMsg("powerdistrict") );
  m_Boosters->SetColLabelValue(4, wxT("mA") );
  m_Boosters->SetColLabelValue(5, wxT("max") );
  m_Boosters->SetColLabelValue(6, wxT("V") );
  m_Boosters->SetColLabelValue(7, wxT("min") );
  m_Boosters->SetColLabelValue(8, wxT("°C") );
  m_Boosters->SetColLabelValue(9, wxT("max") );

  m_On->SetLabel( wxGetApp().getMsg("on") );
  m_Off->SetLabel(wxGetApp().getMsg("off") );
  m_ResetStat->SetLabel(wxGetApp().getMsg("reset") );

  // Buttons
  m_stdButtonOK->SetLabel( wxGetApp().getMsg( "ok" ) );
  m_stdButtonHelp->SetLabel( wxGetApp().getMsg( "help" ) );
}


void PowerCtrlDlg::addRow(iONode booster) {
  m_Boosters->AppendRows();
  m_Boosters->SetCellValue(m_Boosters->GetNumberRows()-1, 0, wxString(wBooster.getid( booster ),wxConvUTF8) );
  m_Boosters->SetCellValue(m_Boosters->GetNumberRows()-1, 1, wBooster.isshortcut(booster)?wxGetApp().getMsg("yes"):wxGetApp().getMsg("no") );
  m_Boosters->SetCellValue(m_Boosters->GetNumberRows()-1, 2, wBooster.ispower(booster)?wxGetApp().getMsg("on"):wxGetApp().getMsg("off") );
  m_Boosters->SetCellValue(m_Boosters->GetNumberRows()-1, 3, wxString(wBooster.getdistrict( booster ),wxConvUTF8) );
  m_Boosters->SetCellValue(m_Boosters->GetNumberRows()-1, 4, wxString::Format(_T("%d"), wBooster.getload(booster)) );
  m_Boosters->SetCellValue(m_Boosters->GetNumberRows()-1, 5, wxString::Format(_T("%d"), wBooster.getloadmax(booster)) );
  m_Boosters->SetCellValue(m_Boosters->GetNumberRows()-1, 6, wxString::Format(_T("%d.%d"), wBooster.getvolt(booster)/1000, (wBooster.getvolt(booster)%1000)/100)  );
  m_Boosters->SetCellValue(m_Boosters->GetNumberRows()-1, 7, wxString::Format(_T("%d.%d"), wBooster.getvoltmin(booster)/1000, (wBooster.getvoltmin(booster)%1000)/100)  );
  m_Boosters->SetCellValue(m_Boosters->GetNumberRows()-1, 8, wxString::Format(_T("%d"), wBooster.gettemp(booster)) );
  m_Boosters->SetCellValue(m_Boosters->GetNumberRows()-1, 9, wxString::Format(_T("%d"), wBooster.gettempmax(booster)) );
  m_Boosters->SetReadOnly( m_Boosters->GetNumberRows()-1, 0, true );
  m_Boosters->SetReadOnly( m_Boosters->GetNumberRows()-1, 1, true );
  m_Boosters->SetReadOnly( m_Boosters->GetNumberRows()-1, 2, true );
  m_Boosters->SetReadOnly( m_Boosters->GetNumberRows()-1, 3, true );
  m_Boosters->SetReadOnly( m_Boosters->GetNumberRows()-1, 4, true );
  m_Boosters->SetReadOnly( m_Boosters->GetNumberRows()-1, 5, true );
  m_Boosters->SetReadOnly( m_Boosters->GetNumberRows()-1, 6, true );
  m_Boosters->SetReadOnly( m_Boosters->GetNumberRows()-1, 7, true );
  m_Boosters->SetReadOnly( m_Boosters->GetNumberRows()-1, 8, true );
  m_Boosters->SetReadOnly( m_Boosters->GetNumberRows()-1, 9, true );

  int row = m_Boosters->GetNumberRows()-1;
  m_Boosters->SetCellBackgroundColour( row, 1,
      wBooster.isshortcut(booster)?wxColour(240,200,200):wxColour(200,240,200));
  m_Boosters->SetCellBackgroundColour( row, 2,
      wBooster.ispower(booster)?wxColour(200,240,200):wxColour(240,200,200));

  m_Boosters->SetCellBackgroundColour( row, 8, wxColour(200,240,200));
  int temp = wBooster.gettemp(booster);
  if( temp >= 60 ) {
    if(temp > 127 )
      temp = 127;
    m_Boosters->SetCellBackgroundColour( row, 8, wxColour(255,255-temp*2,127-temp));
  }

}


static int boosterIDComparator(obj* o1, obj* o2) {
  if( *o1 == NULL || *o2 == NULL )
    return 0;
  if( ms_SortInvert )
    return strcmp( wBooster.getdistrict( (iONode)*o2 ), wBooster.getdistrict( (iONode)*o1 ) );
  else
    return strcmp( wBooster.getdistrict( (iONode)*o1 ), wBooster.getdistrict( (iONode)*o2 ) );
}

static int boosterDistrictComparator(obj* o1, obj* o2) {
  if( *o1 == NULL || *o2 == NULL )
    return 0;
  if( ms_SortInvert )
    return strcmp( wBooster.getid( (iONode)*o2 ), wBooster.getid( (iONode)*o1 ) );
  else
    return strcmp( wBooster.getid( (iONode)*o1 ), wBooster.getid( (iONode)*o2 ) );
}


void PowerCtrlDlg::initValues(iONode event) {
  m_Boosters->DeleteRows(0,m_Boosters->GetNumberRows());
  MapOp.clear(m_BoosterMap);

  if( event != NULL ) {
    TraceOp.trc( "pwrctrl", TRCLEVEL_INFO, __LINE__, 9999, "event from booster %08X", wBooster.getuid(event) );
  }

  iOList list = ListOp.inst();
  iONode model = wxGetApp().getModel();
  if( model != NULL ) {
    iONode boosterlist = wPlan.getboosterlist( model );
    if( boosterlist != NULL ) {
      iONode booster = wBoosterList.getbooster( boosterlist );
      while( booster != NULL ) {
        if( event != NULL && StrOp.equals( wBooster.name(), NodeOp.getName(event))) {
          if( wBooster.getuid(booster) > 0 && wBooster.getuid(event) > 0 && wBooster.getuid(booster) == wBooster.getuid(event) ) {
            wBooster.setload(booster, wBooster.getload(event));
            wBooster.setvolt(booster, wBooster.getvolt(event));
            wBooster.settemp(booster, wBooster.gettemp(event));
            wBooster.setloadmax(booster, wBooster.getloadmax(event));
            wBooster.setvoltmin(booster, wBooster.getvoltmin(event));
            wBooster.settempmax(booster, wBooster.gettempmax(event));
            wBooster.setpower(booster, wBooster.ispower(event));

            iONode boosterevent = NodeOp.inst(wBoosterEvent.name(), booster, ELEMENT_NODE);
            NodeOp.addChild( booster, boosterevent);
            long t = time(NULL);
            wBoosterEvent.settimestamp( boosterevent, t);
            wBoosterEvent.setload(boosterevent, wBooster.getload(event));
            wBoosterEvent.setvolt(boosterevent, wBooster.getvolt(event));
            wBoosterEvent.settemp(boosterevent, wBooster.gettemp(event));

            boosterevent = wBooster.getboosterevent(booster);
            while( boosterevent != NULL ) {
              if( wBoosterEvent.gettimestamp(boosterevent)+300 < t ) {
                // older then 5 minutes
                TraceOp.trc( "pwrctrl", TRCLEVEL_INFO, __LINE__, 9999, "remove booster event of %s", wBooster.getid(m_SelBooster) );
                NodeOp.removeChild( booster, boosterevent);
                NodeOp.base.del(boosterevent);
                boosterevent = wBooster.getboosterevent(booster);
                continue;
              }
              boosterevent = wBooster.nextboosterevent( booster, boosterevent );
            }
          }
        }


        MapOp.put(m_BoosterMap, wBooster.getid( booster ), (obj)booster );

        ListOp.add(list, (obj)booster);

        booster = wBoosterList.nextbooster( boosterlist, booster );
      };
    }
  }

  if( m_SortColumn == 3 )
    ListOp.sort( list, boosterDistrictComparator );
  else
    ListOp.sort( list, boosterIDComparator );

  for( int i = 0; i < ListOp.size( list ); i++ ) {
    iONode booster = (iONode)ListOp.get( list, i );
    addRow(booster);
    if(m_SelBooster == NULL) {
      m_SelBooster = booster;
      m_HistoryPanel->setBooster(m_SelBooster);
      m_labHistory->SetLabel(wxString(wBooster.getid(m_SelBooster), wxConvUTF8 ));
    }
    if( m_SelBooster == booster )
      m_SelectedRow = i;
  }
  ListOp.base.del(list);


  m_Boosters->AutoSizeColumns();

  if( m_SelectedRow != -1 ) {
    m_Boosters->SelectRow(m_SelectedRow);
  }
  else {
    m_On->Enable( false );
    m_Off->Enable( false );
    m_ResetStat->Enable( false );
  }
}


void PowerCtrlDlg::onCellLeftClick( wxGridEvent& event ) {
  m_SelectedRow = event.GetRow();
  m_Boosters->SelectRow(event.GetRow());
  m_On->Enable( true );
  m_Off->Enable( true );
  m_ResetStat->Enable( true );

  wxString str = m_Boosters->GetCellValue( event.GetRow(), 0 );
  m_SelBooster = (iONode)MapOp.get(m_BoosterMap, (const char*)str.mb_str(wxConvUTF8) );
  if( m_SelBooster != NULL ) {
    TraceOp.trc( "pwrctrl", TRCLEVEL_INFO, __LINE__, 9999, "booster %s selected", wBooster.getid(m_SelBooster) );
    m_HistoryPanel->setBooster(m_SelBooster);
    //SetTitle( wxString(wBooster.getid(m_SelBooster), wxConvUTF8 ));
    m_labHistory->SetLabel(wxString(wBooster.getid(m_SelBooster), wxConvUTF8 ));
  }
}


void PowerCtrlDlg::onCellRightClick( wxGridEvent& event ) {
  onCellLeftClick(event);
}


void PowerCtrlDlg::powerEvent(iONode event) {
  initValues(event);
  paintHistory();
}

void PowerCtrlDlg::paintHistory() {
  if( m_SelBooster != NULL ) {
    const char* id = wBooster.getid(m_SelBooster);
    m_HistoryPanel->Refresh();
  }
}


void PowerCtrlDlg::OnOn( wxCommandEvent& event )
{
	if( m_SelBooster != NULL ) {
	  iONode pwrcmd = NodeOp.inst( wPwrCmd.name(), NULL, ELEMENT_NODE );
	  wPwrCmd.setid(pwrcmd, wBooster.getid(m_SelBooster));
    wPwrCmd.setcmd(pwrcmd, wPwrCmd.on);
    TraceOp.trc( "pwrctrl", TRCLEVEL_INFO, __LINE__, 9999, "sending on cmd for booster %s", wBooster.getid(m_SelBooster) );
    wxGetApp().sendToRocrail( pwrcmd );
    m_SelectedRow = -1;
	}
}

void PowerCtrlDlg::OnOff( wxCommandEvent& event )
{
  if( m_SelBooster != NULL ) {
    iONode pwrcmd = NodeOp.inst( wPwrCmd.name(), NULL, ELEMENT_NODE );
    wPwrCmd.setid(pwrcmd, wBooster.getid(m_SelBooster));
    wPwrCmd.setcmd(pwrcmd, wPwrCmd.off);
    TraceOp.trc( "pwrctrl", TRCLEVEL_INFO, __LINE__, 9999, "sending off cmd for booster %s", wBooster.getid(m_SelBooster) );
    wxGetApp().sendToRocrail( pwrcmd );
    m_SelectedRow = -1;
  }
}

void PowerCtrlDlg::OnOK( wxCommandEvent& event )
{
  //EndModal( wxID_OK );
  int x,y;
  GetPosition(&x,&y);
  int cx,cy;
  GetSize(&cx,&cy);

  iONode ini = wxGetApp().getIni();
  iONode powerctrl = wGui.getpowerctrl(ini);
  if( powerctrl == NULL ) {
    powerctrl = NodeOp.inst(wPowerCtrl.name(), ini, ELEMENT_NODE);
    NodeOp.addChild(ini, powerctrl);
  }
  wPowerCtrl.setx(powerctrl,x);
  wPowerCtrl.sety(powerctrl,y);
  wPowerCtrl.setcx(powerctrl,cx);
  wPowerCtrl.setcy(powerctrl,cy);
  wPowerCtrl.setshow(powerctrl, False);

  wxGetApp().getFrame()->resetPowerCtrlRef();
  Destroy();
}

void PowerCtrlDlg::onClose( wxCloseEvent& event ) {
  wxCommandEvent e;
  OnOK(e);
}


void PowerCtrlDlg::onSize( wxSizeEvent& event ) {
  powerctrlgen::OnSize( event );
}


void PowerCtrlDlg::onResetStat( wxCommandEvent& event ) {
  if( m_SelBooster != NULL ) {
    iONode pwrcmd = NodeOp.inst( wPwrCmd.name(), NULL, ELEMENT_NODE );
    wPwrCmd.setid(pwrcmd, wBooster.getid(m_SelBooster));
    wPwrCmd.setcmd(pwrcmd, wSysCmd.resetstat);
    TraceOp.trc( "pwrctrl", TRCLEVEL_INFO, __LINE__, 9999, "sending on cmd for booster %s", wBooster.getid(m_SelBooster) );
    wxGetApp().sendToRocrail( pwrcmd );
    m_SelectedRow = -1;
  }
}


void PowerCtrlDlg::OnHelp( wxCommandEvent& event ) {
  wxGetApp().openLink( "powerman" );
}

void PowerCtrlDlg::onLabelLeftClick( wxGridEvent& event ) {
  int column = event.GetCol();
  if( m_SortColumn == column )
    ms_SortInvert = !ms_SortInvert;
  else {
    ms_SortInvert = false;
    m_SortColumn = column;
  }
  TraceOp.trc( "pwrctrl", TRCLEVEL_INFO, __LINE__, 9999, "sorting on column %d", m_SortColumn );
  initValues(NULL);
}

