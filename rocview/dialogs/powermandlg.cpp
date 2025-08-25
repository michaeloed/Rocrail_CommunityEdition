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


#include "powermandlg.h"
#include "actionsctrldlg.h"

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#include "wx/defs.h"
#endif

#include "rocview/public/guiapp.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/Plan.h"
#include "rocrail/wrapper/public/Booster.h"
#include "rocrail/wrapper/public/BoosterList.h"
#include "rocrail/wrapper/public/Item.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/BlockList.h"
#include "rocrail/wrapper/public/StageList.h"
#include "rocrail/wrapper/public/TurntableList.h"
#include "rocrail/wrapper/public/SelTabList.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/OutputList.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/FeedbackList.h"

#include "rocs/public/trace.h"
#include "rocs/public/strtok.h"

#include "basedlg.h"


static bool m_bInvertSortOrder;


PowerManDlg::PowerManDlg( wxWindow* parent ):powermandlggen( parent )
{
  m_Props = NULL;
  m_SortCol  = 0;
  m_bInvertSortOrder = false;
  initLabels();

  m_IndexPanel->GetSizer()->Layout();
  m_GeneralPanel->GetSizer()->Layout();
  m_ModulesPanel->GetSizer()->Layout();
  m_BlocksPanel->GetSizer()->Layout();
  m_DetailsPanel->GetSizer()->Layout();

  m_BoosterBook->Fit();

  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);

  m_GeneralPanel->Enable(false);
  m_ModulesPanel->Enable(false);
  m_BlocksPanel->Enable(false);
  m_DetailsPanel->Enable(false);

  initIndex();

  // not jet supported
  m_StopDistrictLocos->Enable(false);

  m_BoosterList->SetFocus();

  m_BoosterBook->Connect( wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PowerManDlg::onSetPage ), NULL, this );
  m_SetPage = 0;

  wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ID_BOOSTERBOOK );
  wxPostEvent( m_BoosterBook, event );
}


void PowerManDlg::onSetPage(wxCommandEvent& event) {
  TraceOp.trc( "boosterdlg", TRCLEVEL_INFO, __LINE__, 9999, "set page to %d", m_SetPage );
  m_BoosterBook->SetSelection( m_SetPage );
}


/* comparator for sorting by id: */
static int __sortStr(obj* _a, obj* _b)
{
    const char* a = (const char*)*_a;
    const char* b = (const char*)*_b;
    return strcmp( a, b );
}

void PowerManDlg::initLabels() {
  TraceOp.trc( "boosterdlg", TRCLEVEL_INFO, __LINE__, 9999, "initLabels" );
  SetTitle(wxGetApp().getMsg( "boostertable" ));
  m_BoosterBook->SetPageText( 0, wxGetApp().getMsg( "index" ) );
  m_BoosterBook->SetPageText( 1, wxGetApp().getMsg( "general" ) );
  m_BoosterBook->SetPageText( 2, wxGetApp().getMsg( "modules" ) );
  m_BoosterBook->SetPageText( 3, wxGetApp().getMsg( "blocks" ) );
  m_BoosterBook->SetPageText( 4, wxGetApp().getMsg( "details" ) );

  // Index
  m_AddBooster->SetLabel( wxGetApp().getMsg( "new" ) );
  m_DelBooster->SetLabel( wxGetApp().getMsg( "delete" ) );
  m_AddModule->SetLabel( wxGetApp().getMsg( "add" ) );
  m_DelModule->SetLabel( wxGetApp().getMsg( "delete" ) );
  m_AddBlock->SetLabel( wxGetApp().getMsg( "add" ) );
  m_DelBlock->SetLabel( wxGetApp().getMsg( "delete" ) );

  m_BoosterList->InsertColumn(0, wxGetApp().getMsg( "id" ), wxLIST_FORMAT_LEFT );
  m_BoosterList->InsertColumn(1, wxGetApp().getMsg( "powerdistrict" ), wxLIST_FORMAT_LEFT );
  m_BoosterList->InsertColumn(2, wxGetApp().getMsg( "uid" ), wxLIST_FORMAT_LEFT );

  // General
  BaseDialog::addIIDs(m_IID);
  m_labID->SetLabel( wxGetApp().getMsg( "id" ) );
  m_labIID->SetLabel( wxGetApp().getMsg( "iid" ) );
  m_labDistrict->SetLabel( wxGetApp().getMsg( "powerdistrict" ) );

  iONode model = wxGetApp().getModel();
  iOList list = ListOp.inst();
  if( model != NULL ) {
    int cnt = 0;
    iONode bklist = wPlan.getbklist( model );
    iONode sblist = wPlan.getsblist( model );
    iONode ttlist = wPlan.getttlist( model );
    iONode fylist = wPlan.getseltablist( model );
    if( bklist != NULL ) {
      cnt = NodeOp.getChildCnt( bklist );
      for( int i = 0; i < cnt; i++ ) {
        iONode bk = NodeOp.getChild( bklist, i );
        ListOp.add(list, (obj)wItem.getid( bk ));
      }
    }
    if( sblist != NULL ) {
      cnt = NodeOp.getChildCnt( sblist );
      for( int i = 0; i < cnt; i++ ) {
        iONode sb = NodeOp.getChild( sblist, i );
        ListOp.add(list, (obj)wItem.getid( sb ));
      }
    }
    if( ttlist != NULL ) {
      cnt = NodeOp.getChildCnt( ttlist );
      for( int i = 0; i < cnt; i++ ) {
        iONode tt = NodeOp.getChild( ttlist, i );
        ListOp.add(list, (obj)wItem.getid( tt ));
      }
    }
    if( fylist != NULL ) {
      cnt = NodeOp.getChildCnt( fylist );
      for( int i = 0; i < cnt; i++ ) {
        iONode fy = NodeOp.getChild( fylist, i );
        ListOp.add(list, (obj)wItem.getid( fy ));
      }
    }

    ListOp.sort(list, &__sortStr);
    cnt = ListOp.size( list );
    for( int i = 0; i < cnt; i++ ) {
      const char* id = (const char*)ListOp.get( list, i );
      m_BlocksCombo->Append( wxString(id,wxConvUTF8) );
    }

  }
  /* clean up the temp. list */
  ListOp.base.del(list);

  list = ListOp.inst();
  if( model != NULL ) {
    iONode fblist = wPlan.getfblist( model );
    if( fblist != NULL ) {
      int cnt = NodeOp.getChildCnt( fblist );
      for( int i = 0; i < cnt; i++ ) {
        iONode fb = NodeOp.getChild( fblist, i );
        const char* id = wFeedback.getid( fb );
        if( id != NULL ) {
          ListOp.add(list, (obj)id);
        }
      }
      m_ShortcutSensor->Append( _T("-") );
      m_PowerSensor->Append( _T("-") );
      ListOp.sort(list, &__sortStr);
      cnt = ListOp.size( list );
      for( int i = 0; i < cnt; i++ ) {
        const char* id = (const char*)ListOp.get( list, i );
        m_ShortcutSensor->Append( wxString(id,wxConvUTF8) );
        m_PowerSensor->Append( wxString(id,wxConvUTF8) );
      }
    }
  }
  /* clean up the temp. list */
  ListOp.base.del(list);


  list = ListOp.inst();
  if( model != NULL ) {
    iONode colist = wPlan.getcolist( model );
    if( colist != NULL ) {
      int cnt = NodeOp.getChildCnt( colist );
      for( int i = 0; i < cnt; i++ ) {
        iONode co = NodeOp.getChild( colist, i );
        const char* id = wOutput.getid( co );
        if( id != NULL ) {
          ListOp.add(list, (obj)id);
        }
      }
      m_PowerOutput->Append( _T("-") );
      ListOp.sort(list, &__sortStr);
      cnt = ListOp.size( list );
      for( int i = 0; i < cnt; i++ ) {
        const char* id = (const char*)ListOp.get( list, i );
        m_PowerOutput->Append( wxString(id,wxConvUTF8) );
      }
    }
  }
  /* clean up the temp. list */
  ListOp.base.del(list);

  m_labShortcutSensor->SetLabel( wxGetApp().getMsg( "shortcutsensor" ) );
  m_labPowerSensor->SetLabel( wxGetApp().getMsg( "powersensor" ) );
  m_labPowerOutput->SetLabel( wxGetApp().getMsg( "poweroutput" ) );
  m_labUID->SetLabel( wxGetApp().getMsg( "uid" ) );

  m_labModuleID->SetLabel( wxGetApp().getMsg( "modid" ) );

  // Options
  m_StopDistrictLocos->SetLabel( wxGetApp().getMsg( "scopt_stoplocos" ) );
  m_PowerOffAll->SetLabel( wxGetApp().getMsg( "scopt_poweroffall" ) );
  m_RetryPowerOn->SetLabel( wxGetApp().getMsg( "scopt_repoweron" ) );
  m_DoesReport->SetLabel( wxGetApp().getMsg( "reportstate" ) );

  m_Actions->SetLabel( wxGetApp().getMsg( "actions" )+_T("...") );

  // Buttons
  m_stdButtonOK->SetLabel( wxGetApp().getMsg( "ok" ) );
  m_stdButtonCancel->SetLabel( wxGetApp().getMsg( "cancel" ) );
  m_stdButtonApply->SetLabel( wxGetApp().getMsg( "apply" ) );
  m_stdButtonHelp->SetLabel( wxGetApp().getMsg( "help" ) );
}


static int __sortID(obj* _a, obj* _b)
{
    iONode a = (iONode)*_a;
    iONode b = (iONode)*_b;
    const char* idA = wItem.getid( a );
    const char* idB = wItem.getid( b );
    return m_bInvertSortOrder ? strcmp( idB, idA ):strcmp( idA, idB );
}
static int __sortDistrict(obj* _a, obj* _b)
{
    iONode a = (iONode)*_a;
    iONode b = (iONode)*_b;
    const char* idA = wBooster.getdistrict( a );
    const char* idB = wBooster.getdistrict( b );
    return m_bInvertSortOrder ? strcmp( idB, idA ):strcmp( idA, idB );
}
static int __sortUID(obj* _a, obj* _b)
{
    iONode a = (iONode)*_a;
    iONode b = (iONode)*_b;
    if( wBooster.getuid(a) > wBooster.getuid(b) )
      return m_bInvertSortOrder ? -1:1;
    if( wBooster.getuid(a) < wBooster.getuid(b) )
      return m_bInvertSortOrder ? 1:-1;
    return 0;
}


void PowerManDlg::initIndex() {
  SetTitle(wxGetApp().getMsg( "boostertable" ));

  m_BoosterList->DeleteAllItems();

  iONode model = wxGetApp().getModel();
  if( model != NULL ) {
    iONode boosterlist = wPlan.getboosterlist( model );
    if( boosterlist == NULL ) {
      boosterlist = NodeOp.inst( wBoosterList.name(), model, ELEMENT_NODE );
      NodeOp.addChild( model, boosterlist );
    }

    if( boosterlist != NULL ) {
      int idx = 0;

      iOList list = ListOp.inst();
      int cnt = NodeOp.getChildCnt( boosterlist );
      for( int i = 0; i < cnt; i++ ) {
        iONode booster = NodeOp.getChild( boosterlist, i );
        const char* id = wBooster.getid( booster );
        if( id != NULL ) {
          ListOp.add(list, (obj)booster);
        }
      }

      if( m_SortCol == 1 ) {
        ListOp.sort(list, &__sortDistrict);
      }
      else if( m_SortCol == 2 ) {
        ListOp.sort(list, &__sortUID);
      }
      else {
        ListOp.sort(list, &__sortID);
      }

      cnt = ListOp.size( list );
      for( int idx = 0; idx < cnt; idx++ ) {
        iONode booster = (iONode)ListOp.get( list, idx );
        const char* id = wBooster.getid( booster );
        m_BoosterList->InsertItem( idx, wxString(id,wxConvUTF8) );
        m_BoosterList->SetItem( idx, 1, wxString(wBooster.getdistrict( booster ), wxConvUTF8) );
        m_BoosterList->SetItem( idx, 2, wxString::Format(wxT("%d"), wBooster.getuid( booster )) );
        m_BoosterList->SetItemPtrData(idx, (wxUIntPtr)booster);

      }

      // resize
      for( int n = 0; n < 3; n++ ) {
        m_BoosterList->SetColumnWidth(n, wxLIST_AUTOSIZE_USEHEADER);
        int autoheadersize = m_BoosterList->GetColumnWidth(n);
        m_BoosterList->SetColumnWidth(n, wxLIST_AUTOSIZE);
        int autosize = m_BoosterList->GetColumnWidth(n);
        if(autoheadersize > autosize )
          m_BoosterList->SetColumnWidth(n, wxLIST_AUTOSIZE_USEHEADER);
      }

      /* clean up the temp. list */
      ListOp.base.del(list);
    }

  }

  if( m_Props != NULL ) {
    setSelection(wBooster.getid( m_Props ));
    initValues();
  }
  else if(m_BoosterList->GetItemCount() > 0 ) {
    TraceOp.trc( "powermandlg", TRCLEVEL_INFO, __LINE__, 9999, "no selection" );
    m_BoosterList->SetItemState(0, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
    m_Props = (iONode)m_BoosterList->GetItemData(0);
    initValues();
  }

}


void PowerManDlg::onBoosterSelect( wxListEvent& event ){
  int index = event.GetIndex();
  m_Props = (iONode)m_BoosterList->GetItemData(index);
  if( m_Props != NULL ) {
    initValues();
  }
  else {
    TraceOp.trc( "boosterdlg", TRCLEVEL_INFO, __LINE__, 9999, "no selection..." );
    m_GeneralPanel->Enable(false);
    m_ModulesPanel->Enable(false);
    m_BlocksPanel->Enable(false);
    m_DetailsPanel->Enable(false);
  }

}


void PowerManDlg::onBoosterListColumn( wxListEvent& event ) {
  if( m_SortCol == event.GetColumn() )
    m_bInvertSortOrder = !m_bInvertSortOrder;
  else
    m_bInvertSortOrder = false;
  m_SortCol = event.GetColumn();
  initIndex();
}


void PowerManDlg::onModuleSelect( wxCommandEvent& event ){
  if( m_ModuleList->GetSelection() != wxNOT_FOUND ) {
    m_DelModule->Enable(true);
    m_ModuleID->SetValue(m_ModuleList->GetStringSelection());
  }
}



void PowerManDlg::onBlockSelect( wxCommandEvent& event ){
  if( m_BlockList->GetSelection() != wxNOT_FOUND ) {
    m_DelBlock->Enable(true);
  }
}



void PowerManDlg::initValues() {
  if( m_Props == NULL ) {
    TraceOp.trc( "boosterdlg", TRCLEVEL_DEBUG, __LINE__, 9999, "no booster selected" );
    return;
  }

  m_GeneralPanel->Enable(true);
  m_ModulesPanel->Enable(true);
  m_BlocksPanel->Enable(true);
  m_DetailsPanel->Enable(true);

  m_DelModule->Enable(false);
  m_DelBlock->Enable(false);

  char* title = StrOp.fmt( "%s %s", (const char*)wxGetApp().getMsg("booster").mb_str(wxConvUTF8), wBooster.getid( m_Props ) );
  SetTitle( wxString(title,wxConvUTF8) );
  StrOp.free( title );

  // init General
  m_ID->SetValue( wxString(wBooster.getid( m_Props ),wxConvUTF8) );
  m_IID->SetValue( wxString(wBooster.getiid( m_Props ),wxConvUTF8) );
  m_District->SetValue( wxString(wBooster.getdistrict( m_Props ),wxConvUTF8) );

  m_ShortcutSensor->SetStringSelection(wxT("-"));
  m_PowerSensor->SetStringSelection(wxT("-"));
  m_PowerOutput->SetStringSelection(wxT("-"));

  m_ShortcutSensor->SetStringSelection( wxString(wBooster.getscfb( m_Props ),wxConvUTF8) );
  m_PowerSensor->SetStringSelection( wxString(wBooster.getpowerfb( m_Props ),wxConvUTF8) );
  m_PowerOutput->SetStringSelection( wxString(wBooster.getpowersw( m_Props ),wxConvUTF8) );
  m_UID->SetValue( wxString::Format(wxT("%d"),wBooster.getuid( m_Props )) );


  m_ModuleList->Clear();
  iOStrTok tok = StrTokOp.inst( wBooster.getmodids( m_Props ), ',' );
  while( StrTokOp.hasMoreTokens( tok ) )  {
    const char* id = StrTokOp.nextToken( tok );
    if( StrOp.len( id ) > 0 )
      m_ModuleList->Append( wxString(id,wxConvUTF8) );
  }
  StrTokOp.base.del( tok );

  m_BlockList->Clear();
  tok = StrTokOp.inst( wBooster.getblockids( m_Props ), ',' );
  while( StrTokOp.hasMoreTokens( tok ) )  {
    const char* id = StrTokOp.nextToken( tok );
    if( StrOp.len( id ) > 0 )
      m_BlockList->Append( wxString(id,wxConvUTF8) );
  }
  StrTokOp.base.del( tok );

  m_ModuleID->SetValue(_T(""));


  m_StopDistrictLocos->SetValue( wBooster.isscopt_stoplocos( m_Props ) );
  m_PowerOffAll->SetValue( wBooster.isscopt_poweroffall( m_Props ) );
  m_RetryPowerOn->SetValue( wBooster.isscopt_repoweron( m_Props ) );
  m_DoesReport->SetValue( wBooster.isdoesreport( m_Props ) );

}


bool PowerManDlg::evaluate() {
  if( m_Props == NULL )
    return false;

  TraceOp.trc( "boosterdlg", TRCLEVEL_INFO, __LINE__, 9999, "Evaluate %s", wBooster.getid( m_Props ) );

  if( m_ID->GetValue().Len() == 0 ) {
    wxMessageDialog( this, wxGetApp().getMsg("invalidid"), _T("Rocrail"), wxOK | wxICON_ERROR ).ShowModal();
    m_ID->SetValue( wxString(wBooster.getid( m_Props ),wxConvUTF8) );
    return false;
  }
  // evaluate General
  wItem.setprev_id( m_Props, wItem.getid(m_Props) );
  wBooster.setid( m_Props, m_ID->GetValue().mb_str(wxConvUTF8) );
  wBooster.setiid( m_Props, m_IID->GetValue().mb_str(wxConvUTF8) );
  wBooster.setdistrict( m_Props, m_District->GetValue().mb_str(wxConvUTF8) );

  if( StrOp.equals( "-", m_ShortcutSensor->GetStringSelection().mb_str(wxConvUTF8) ) )
    wBooster.setscfb( m_Props, "" );
  else
    wBooster.setscfb( m_Props, m_ShortcutSensor->GetStringSelection().mb_str(wxConvUTF8) );

  if( StrOp.equals( "-", m_PowerSensor->GetStringSelection().mb_str(wxConvUTF8) ) )
    wBooster.setpowerfb( m_Props, "" );
  else
    wBooster.setpowerfb( m_Props, m_PowerSensor->GetStringSelection().mb_str(wxConvUTF8) );

  if( StrOp.equals( "-", m_PowerOutput->GetStringSelection().mb_str(wxConvUTF8) ) )
    wBooster.setpowersw( m_Props, "" );
  else
    wBooster.setpowersw( m_Props, m_PowerOutput->GetStringSelection().mb_str(wxConvUTF8) );

  wBooster.setuid( m_Props, atoi(m_UID->GetValue().mb_str(wxConvUTF8)) );


  int cnt = m_ModuleList->GetCount();
  char* modids = NULL;
  for( int i = 0; i < cnt; i++ ) {
    if( i > 0 )
      modids = StrOp.cat( modids, "," );
    modids = StrOp.cat( modids, m_ModuleList->GetString(i).mb_str(wxConvUTF8) );
  }
  wBooster.setmodids( m_Props, modids==NULL ? "":modids );
  StrOp.free(modids);

  cnt = m_BlockList->GetCount();
  char* blockids = NULL;
  for( int i = 0; i < cnt; i++ ) {
    if( i > 0 )
      blockids = StrOp.cat( blockids, "," );
    blockids = StrOp.cat( blockids, m_BlockList->GetString(i).mb_str(wxConvUTF8) );
  }
  wBooster.setblockids( m_Props, blockids==NULL ? "":blockids );
  StrOp.free(blockids);

  wBooster.setscopt_stoplocos( m_Props, m_StopDistrictLocos->IsChecked()?True:False );
  wBooster.setscopt_poweroffall( m_Props, m_PowerOffAll->IsChecked()?True:False );
  wBooster.setscopt_repoweron( m_Props, m_RetryPowerOn->IsChecked()?True:False );
  wBooster.setdoesreport( m_Props, m_DoesReport->IsChecked()?True:False );

  return true;
}


void PowerManDlg::OnAddBooster( wxCommandEvent& event )
{
  int i = findID("NEW");
  if( i == wxNOT_FOUND ) {
    iONode model = wxGetApp().getModel();
    iONode boosterlist = wPlan.getboosterlist( model );
    iONode booster = NodeOp.inst( wBooster.name(), boosterlist, ELEMENT_NODE );
    wBooster.setid(booster, "NEW");
    NodeOp.addChild( boosterlist, booster );

    m_Props = booster;
    initValues();
    initIndex();
    setSelection(wBooster.getid( booster ));
  }
}

void PowerManDlg::OnDelBooster( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  int action = wxMessageDialog( this, wxGetApp().getMsg("removewarning"), _T("Rocrail"), wxYES_NO | wxICON_EXCLAMATION ).ShowModal();
  if( action == wxID_NO )
    return;

  wxGetApp().pushUndoItem( (iONode)NodeOp.base.clone( m_Props ) );
  m_ID->SetValue(_T(""));
  m_District->SetValue(_T(""));
  m_GeneralPanel->Enable(false);
  m_ModulesPanel->Enable(false);
  m_BlocksPanel->Enable(false);
  m_DetailsPanel->Enable(false);
  m_ModuleList->Clear();
  m_BlockList->Clear();
  m_ModuleID->SetValue(_T(""));

  /* Notify RocRail. */
  iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
  wModelCmd.setcmd( cmd, wModelCmd.remove );
  NodeOp.addChild( cmd, (iONode)m_Props->base.clone( m_Props ) );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);


  iONode model = wxGetApp().getModel();
  iONode boosterlist = wPlan.getboosterlist( model );

  NodeOp.removeChild( boosterlist, m_Props );
  m_Props = NULL;

  initIndex();
}

void PowerManDlg::OnAddModule( wxCommandEvent& event )
{
  if( m_ModuleID->GetValue().Len() > 0 )
    m_ModuleList->Append(m_ModuleID->GetValue());
}

void PowerManDlg::OnDelModule( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  if( m_ModuleList->GetSelection() != wxNOT_FOUND ) {
    m_ModuleList->Delete(m_ModuleList->GetSelection());
    m_ModuleID->SetValue(_T(""));
    m_DelModule->Enable(false);
  }
}

void PowerManDlg::OnAddBlock( wxCommandEvent& event )
{
  if( m_BlocksCombo->GetSelection() != wxNOT_FOUND ) {
    m_BlockList->Append(m_BlocksCombo->GetStringSelection());
  }
}

void PowerManDlg::OnDelBlock( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  if( m_BlockList->GetSelection() != wxNOT_FOUND ) {
    m_BlockList->Delete(m_BlockList->GetSelection());
    m_DelBlock->Enable(false);
  }
}

void PowerManDlg::OnApply( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  if( !evaluate() )
    return;

  if( !wxGetApp().isStayOffline() ) {
    /* Notify RocRail. */
    iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
    wModelCmd.setcmd( cmd, wModelCmd.modify );
    NodeOp.addChild( cmd, (iONode)m_Props->base.clone( m_Props ) );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
  initIndex();
}

void PowerManDlg::OnCancel( wxCommandEvent& event )
{
  EndModal( 0 );
}

void PowerManDlg::OnOK( wxCommandEvent& event )
{
  OnApply(event);
  EndModal( wxID_OK );
}


void PowerManDlg::onActions( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  ActionsCtrlDlg*  dlg = new ActionsCtrlDlg(this, m_Props, "load,shortcut " );

  if( wxID_OK == dlg->ShowModal() ) {
    // TODO: inform
  }

  dlg->Destroy();
}


void PowerManDlg::OnHelp( wxCommandEvent& event ) {
  switch( m_BoosterBook->GetSelection() ) {
  case 0: wxGetApp().openLink( "powerman", "index" ); break;
  case 1: wxGetApp().openLink( "powerman", "general" ); break;
  case 2: wxGetApp().openLink( "powerman", "modules" ); break;
  case 3: wxGetApp().openLink( "powerman", "blocks" ); break;
  case 4: wxGetApp().openLink( "powerman", "details" ); break;
  default: wxGetApp().openLink( "powerman" ); break;
  }
}

void PowerManDlg::setSelection(const char* ID) {
  int size = m_BoosterList->GetItemCount();
  for( int index = 0; index < size; index++ ) {
    iONode node = (iONode)m_BoosterList->GetItemData(index);
    if( StrOp.equals( ID, wBooster.getid(node) ) ) {
      m_BoosterList->SetItemState(index, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
      break;
    }
  }

}


int PowerManDlg::findID( const char* ID ) {
  int size = m_BoosterList->GetItemCount();
  for( int index = 0; index < size; index++ ) {
    iONode node = (iONode)m_BoosterList->GetItemData(index);
    if( StrOp.equals( ID, wBooster.getid(node) ) ) {
      return index;
    }
  }
  return wxNOT_FOUND;
}

