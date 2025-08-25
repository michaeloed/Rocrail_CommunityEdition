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
#include "operatordlg.h"

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#include "wx/defs.h"
#endif

#include "rocview/public/guiapp.h"

#include "rocview/dialogs/locdialog.h"
#include "rocview/dialogs/cardlg.h"
#include "rocview/dialogs/waybilldlg.h"

#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/Plan.h"
#include "rocrail/wrapper/public/Item.h"
#include "rocrail/wrapper/public/Car.h"
#include "rocrail/wrapper/public/CarList.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/LocList.h"
#include "rocrail/wrapper/public/Operator.h"
#include "rocrail/wrapper/public/OperatorList.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/Location.h"
#include "rocrail/wrapper/public/LocationList.h"
#include "rocrail/wrapper/public/Waybill.h"

#include "rocview/wrapper/public/Gui.h"

#include "rocs/public/trace.h"
#include "rocs/public/strtok.h"
#include "rocs/public/system.h"

#include "rocview/xpm/nopict.xpm"


OperatorDlg::OperatorDlg( wxWindow* parent, iONode p_Props, bool save, const char* blockid )
  :operatordlggen( parent )
{
  TraceOp.trc( "opdlg", TRCLEVEL_INFO, __LINE__, 9999, "cardlg" );
  m_TabAlign = wxGetApp().getTabAlign();
  m_Props    = p_Props;
  m_bSave    = save;
  m_CarProps = NULL;
  m_BlockID  = blockid;

  initLabels();

  m_IndexPanel->GetSizer()->Layout();
  m_ControlPanel->GetSizer()->Layout();
  m_ConsistPanel->GetSizer()->Layout();

  m_OperatorBook->Fit();

  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);

  initIndex();

  m_OperatorList->SetFocus();

  m_OperatorBook->Connect( wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OperatorDlg::onSetPage ), NULL, this );
  m_SetPage = 0;

  m_ControlPanel->Enable(false);
  m_ConsistPanel->Enable(false);

  m_StdButtonApply->Enable(m_bSave);

  if( m_Props != NULL ) {
    initValues();
    m_SetPage = 1;
  }
  wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, -1 );
  wxPostEvent( m_OperatorBook, event );

  if( m_BlockID == NULL ) {
    m_ShowAllOperators->SetValue(true);
    m_ShowAllOperators->Enable(false);
  }

}


iONode OperatorDlg::getSelected() {
  return m_Props;
}



/* comparator for sorting by id: */
static int __sortID(obj* _a, obj* _b)
{
    iONode a = (iONode)*_a;
    iONode b = (iONode)*_b;
    const char* idA = wItem.getid( a );
    const char* idB = wItem.getid( b );
    return strcmp( idA, idB );
}


void OperatorDlg::onSetPage(wxCommandEvent& event) {
  TraceOp.trc( "opdlg", TRCLEVEL_INFO, __LINE__, 9999, "set page to %d", m_SetPage );
  m_OperatorBook->SetSelection( m_SetPage );
}


void OperatorDlg::initLocos() {
  m_LocoID->Clear();

  iONode model = wxGetApp().getModel();
  if( model != NULL ) {
    iONode lclist = wPlan.getlclist( model );
    if( lclist != NULL ) {
      iOList list = ListOp.inst();
      int cnt = NodeOp.getChildCnt( lclist );
      for( int i = 0; i < cnt; i++ ) {
        iONode lc = NodeOp.getChild( lclist, i );
        const char* id = wLoc.getid( lc );
        if( id != NULL ) {
          ListOp.add(list, (obj)lc);
        }
      }

      m_LocoID->Append( wxString("",wxConvUTF8) );

      ListOp.sort(list, &__sortID);
      cnt = ListOp.size( list );
      for( int i = 0; i < cnt; i++ ) {
        iONode lc = (iONode)ListOp.get( list, i );
        const char* id = wLoc.getid( lc );
        m_LocoID->Append( wxString(id,wxConvUTF8), lc );
      }
      /* clean up the temp. list */
      ListOp.base.del(list);

      if( m_Props != NULL ) {
        m_LocoID->SetStringSelection( wxString(wOperator.getlcid( m_Props ),wxConvUTF8) );
        iONode lc = wxGetApp().getFrame()->findLoc(wOperator.getlcid( m_Props ));
        if( lc != NULL ) {
          iONode bk = wxGetApp().getFrame()->findBlock4Loc(wOperator.getlcid( m_Props ), NULL);
          if( bk != NULL ) {
            m_Location->SetStringSelection( wxString(wBlock.getid( bk ),wxConvUTF8) );
          }
          else {
            m_Location->SetStringSelection( wxString(wLoc.getblockid( lc ),wxConvUTF8) );
          }
        }
        else {
          m_Location->SetStringSelection( wxString(wOperator.getlocation( m_Props ),wxConvUTF8) );
        }
      }
      else
        TraceOp.trc( "opdlg", TRCLEVEL_INFO, __LINE__, 9999, "no selection" );
    }

  }

  wxCommandEvent event( 0, 0 );
  onLocomotiveCombo(event);

}


static int __sortStr(obj* _a, obj* _b)
{
    const char* a = (const char*)*_a;
    const char* b = (const char*)*_b;
    return strcmp( a, b );
}

void OperatorDlg::initLocationCombo() {
  TraceOp.trc( "opdlg", TRCLEVEL_INFO, __LINE__, 9999, "init location combos" );
  m_Location->Clear();
  m_Location->Append( _T(""), (void*)NULL );
  m_Goto->Clear();
  m_Goto->Append( _T(""), (void*)NULL );

  iONode model = wxGetApp().getModel();
  iOList locations = ListOp.inst();
  iOList gotos     = ListOp.inst();

  if( model != NULL ) {
    iONode locationlist = wPlan.getlocationlist( model );
    if( locationlist != NULL ) {
      int cnt = NodeOp.getChildCnt( locationlist );
      for( int i = 0; i < cnt; i++ ) {
        iONode location = NodeOp.getChild( locationlist, i );
        const char* id = wLocation.getid( location );
        if( id != NULL ) {
          ListOp.add(gotos, (obj)id);
        }
      }
    }

    iONode bklist = wPlan.getbklist( model );
    if( bklist != NULL ) {
      int cnt = NodeOp.getChildCnt( bklist );
      for( int i = 0; i < cnt; i++ ) {
        iONode bk = NodeOp.getChild( bklist, i );
        const char* id = wBlock.getid( bk );
        if( id != NULL ) {
          ListOp.add(gotos, (obj)id);
          ListOp.add(locations, (obj)id);
        }
      }
    }

    if( ListOp.size(gotos) > 0 ) {
      ListOp.sort(gotos, &__sortStr);
      int cnt = ListOp.size( gotos );
      for( int i = 0; i < cnt; i++ ) {
        const char* id = (const char*)ListOp.get( gotos, i );
        m_Goto->Append( wxString(id,wxConvUTF8) );
      }
    }
    if( ListOp.size(locations) > 0 ) {
      ListOp.sort(locations, &__sortStr);
      int cnt = ListOp.size( locations );
      for( int i = 0; i < cnt; i++ ) {
        const char* id = (const char*)ListOp.get( locations, i );
        m_Location->Append( wxString(id,wxConvUTF8) );
      }
    }

  }
  /* clean up the temp. list */
  ListOp.base.del(gotos);
  ListOp.base.del(locations);
}


void OperatorDlg::initLabels() {
  SetTitle(wxGetApp().getMsg( "operatortable" ));
  m_OperatorBook->SetPageText( 0, wxGetApp().getMsg( "index" ) );
  m_OperatorBook->SetPageText( 1, wxGetApp().getMsg( "ctrlmode" ) );
  m_OperatorBook->SetPageText( 2, wxGetApp().getMsg( "train" ) );
  m_NewOperator->SetLabel( wxGetApp().getMsg( "new" ) );
  m_DelOperator->SetLabel( wxGetApp().getMsg( "delete" ) );
  m_Copy->SetLabel( wxGetApp().getMsg( "copy" ) );
  m_ShowAllOperators->SetLabel( wxGetApp().getMsg( "showall" ) );

  m_labOperator->SetLabel( wxGetApp().getMsg( "name" ) );
  m_labLocoID->SetLabel( wxGetApp().getMsg( "locomotive" ) );
  m_labLocation->GetStaticBox()->SetLabel( wxGetApp().getMsg( "place" ) );
  m_Reserve->SetLabel( wxGetApp().getMsg( "reserve" ) );
  m_SetLocation->SetLabel( wxGetApp().getMsg( "set" ) );
  m_labGoto->GetStaticBox()->SetLabel( wxGetApp().getMsg( "goto" ) );
  m_Run->SetLabel( wxGetApp().getMsg( "run" ) );
  m_GotoMan->SetLabel( wxGetApp().getMsg( "manually" ) );
  m_AddCar->SetLabel( wxGetApp().getMsg( "add" ) );
  m_LeaveCar->SetLabel( wxGetApp().getMsg( "leave" ) );
  m_ShowCar->SetLabel( wxGetApp().getMsg( "carcard" ) );
  m_ShowWaybill->SetLabel( wxGetApp().getMsg( "waybill" ) );

  m_labCargo->SetLabel( wxGetApp().getMsg( "cargo" ) );
  m_Cargo->Append(wxGetApp().getMsg( wLoc.cargo_none ));
  m_Cargo->Append( wxGetApp().getMsg( wLoc.cargo_goods ) );
  m_Cargo->Append( wxGetApp().getMsg( "local" ) ); // wLoc.cargo_person
  m_Cargo->Append( wxGetApp().getMsg( wLoc.cargo_mixed ) );
  m_Cargo->Append( wxGetApp().getMsg( wLoc.cargo_cleaning ) );
  m_Cargo->Append( wxGetApp().getMsg( wLoc.cargo_ice ) );
  m_Cargo->Append( wxGetApp().getMsg( wLoc.cargo_post ) );
  m_Cargo->Append( wxGetApp().getMsg( wLoc.cargo_light ) );
  m_Cargo->Append( wxGetApp().getMsg( wLoc.cargo_lightgoods ) );
  m_Cargo->Append( wxGetApp().getMsg( wLoc.cargo_regional ) );

  m_labClass->SetLabel( wxGetApp().getMsg( "class" ) );
  m_labVMax->SetLabel( wxGetApp().getMsg( "maxkmh" ) );

  m_OperatorList->InsertColumn(0, wxGetApp().getMsg( "id" ), wxLIST_FORMAT_LEFT );
  m_OperatorList->InsertColumn(1, wxGetApp().getMsg( "place" ), wxLIST_FORMAT_LEFT );
  m_OperatorList->InsertColumn(2, wxGetApp().getMsg( "locomotive" ), wxLIST_FORMAT_LEFT );
  m_OperatorList->InsertColumn(3, wxGetApp().getMsg( "maxkmh" ), wxLIST_FORMAT_RIGHT );
  m_OperatorList->InsertColumn(4, wxGetApp().getMsg( "cargo" ), wxLIST_FORMAT_LEFT );

  m_CarList->InsertColumn(0, wxGetApp().getMsg( "id" ), wxLIST_FORMAT_LEFT );
  m_CarList->InsertColumn(1, wxGetApp().getMsg( "waybill" ), wxLIST_FORMAT_LEFT );
  m_CarList->InsertColumn(2, wxGetApp().getMsg( "place" ), wxLIST_FORMAT_LEFT );
  m_CarList->InsertColumn(3, wxGetApp().getMsg( "destination" ), wxLIST_FORMAT_LEFT );
  m_CarList->InsertColumn(4, wxGetApp().getMsg( "maxkmh" ), wxLIST_FORMAT_RIGHT );

  // Buttons
  m_StdButtonOK->SetLabel( wxGetApp().getMsg( "ok" ) );
  m_StdButtonCancel->SetLabel( wxGetApp().getMsg( "cancel" ) );
  m_StdButtonApply->SetLabel( wxGetApp().getMsg( "apply" ) );

  initLocationCombo();
}


void OperatorDlg::onOperatorlist( wxListEvent& event ) {
  int index = event.GetIndex();
  if( index != wxNOT_FOUND ) {
    m_Props = (iONode)m_OperatorList->GetItemData( index );
    if( m_Props != NULL )
      initValues();
    else
      TraceOp.trc( "opdlg", TRCLEVEL_INFO, __LINE__, 9999, "no selection..." );
  }
}


void OperatorDlg::evaluate() {
  if( m_Props == NULL )
    return;

  TraceOp.trc( "opdlg", TRCLEVEL_INFO, __LINE__, 9999, "Evaluate %s", wOperator.getid( m_Props ) );

  // evaluate General
  wItem.setprev_id( m_Props, wItem.getid(m_Props) );
  wOperator.setid( m_Props, m_Operator->GetValue().mb_str(wxConvUTF8) );
  wOperator.setlcid( m_Props, m_LocoID->GetStringSelection().mb_str(wxConvUTF8) );

  int carcnt = m_CarList->GetItemCount();
  char* consist = NULL;
  TraceOp.trc( "opdlg", TRCLEVEL_INFO, __LINE__, 9999, "carids[%d]", carcnt );
  for( int i = 0; i < carcnt; i++ ) {
    iONode car = (iONode)m_CarList->GetItemData(i);

    TraceOp.trc( "opdlg", TRCLEVEL_INFO, __LINE__, 9999, "adding carid [%s]", wCar.getid(car) );
    if( consist == NULL ) {
      consist = StrOp.cat(consist, wCar.getid(car));
    }
    else {
      consist = StrOp.cat(consist, ",");
      consist = StrOp.cat(consist, wCar.getid(car));
    }
  }
  if( consist == NULL )
    wOperator.setcarids(m_Props, "");
  else
    wOperator.setcarids(m_Props, consist);

  TraceOp.trc( "opdlg", TRCLEVEL_INFO, __LINE__, 9999, "carids: [%s]", wOperator.getcarids(m_Props) );

  int cargo = m_Cargo->GetSelection();
  if( cargo == 0 )
    wOperator.setcargo( m_Props, wLoc.cargo_none );
  else if( cargo == 1 )
    wOperator.setcargo( m_Props, wLoc.cargo_goods );
  else if( cargo == 2 )
    wOperator.setcargo( m_Props, wLoc.cargo_person );
  else if( cargo == 3 )
    wOperator.setcargo( m_Props, wLoc.cargo_mixed );
  else if( cargo == 4 )
    wOperator.setcargo( m_Props, wLoc.cargo_cleaning );
  else if( cargo == 5 )
    wOperator.setcargo( m_Props, wLoc.cargo_ice );
  else if( cargo == 6 )
    wOperator.setcargo( m_Props, wLoc.cargo_post );
  else if( cargo == 7 )
    wOperator.setcargo( m_Props, wLoc.cargo_light );
  else if( cargo == 8 )
    wOperator.setcargo( m_Props, wLoc.cargo_lightgoods );
  else if( cargo == 9 )
    wOperator.setcargo( m_Props, wLoc.cargo_regional );

  wOperator.setclass( m_Props, m_Class->GetValue().mb_str(wxConvUTF8) );
  wOperator.setV_max( m_Props, m_VMax->GetValue() );

}


int OperatorDlg::getVMax( iONode props ) {
  int vmax = wOperator.getV_max(props);
  iOStrTok tok = StrTokOp.inst(wOperator.getcarids(props), ',');
  while( StrTokOp.hasMoreTokens(tok) ) {
    iONode car = wxGetApp().getFrame()->findCar( StrTokOp.nextToken(tok) );
    if( car != NULL ) {
      int vmaxcar = wCar.getV_max(car);
      if( vmaxcar > 0 ) {
        if( vmax == 0 || vmaxcar < vmax)
          vmax = vmaxcar;
      }
    }
  }
  StrTokOp.base.del(tok);

  return vmax;
}


void OperatorDlg::initIndex() {
  TraceOp.trc( "opdlg", TRCLEVEL_INFO, __LINE__, 9999, "initIndex" );

  SetTitle(wxGetApp().getMsg( "operatortable" ));

  m_OperatorList->DeleteAllItems();

  iONode model = wxGetApp().getModel();
  if( model != NULL ) {
    iONode operatorlist = wPlan.getoperatorlist( model );
    if( operatorlist != NULL ) {
      iOList list = ListOp.inst();
      int cnt = NodeOp.getChildCnt( operatorlist );
      for( int i = 0; i < cnt; i++ ) {
        iONode op = NodeOp.getChild( operatorlist, i );
        const char* id = wOperator.getid( op );
        if( id != NULL ) {
          ListOp.add(list, (obj)op);
        }
      }

      ListOp.sort(list, &__sortID);
      cnt = ListOp.size( list );
      int idx = 0;
      for( int i = 0; i < cnt; i++ ) {
        iONode op = (iONode)ListOp.get( list, i );
        if( !m_ShowAllOperators->IsChecked() && m_BlockID != NULL && StrOp.len(m_BlockID) > 0 ) {
          if( wOperator.getlocation(op) != NULL && StrOp.len(wOperator.getlocation(op)) && !StrOp.equals(m_BlockID, wOperator.getlocation(op)) ) {
            continue; // not in wanted block
          }
        }
        const char* id = wOperator.getid( op );
        m_OperatorList->InsertItem( idx, wxString(id,wxConvUTF8) );
        m_OperatorList->SetItem( idx, 1, wxString(wOperator.getlocation(op), wxConvUTF8) );
        m_OperatorList->SetItem( idx, 2, wxString(wOperator.getlcid(op), wxConvUTF8) );
        m_OperatorList->SetItem( idx, 3, wxString::Format(wxT("%d"), getVMax(op)) );
        m_OperatorList->SetItem( idx, 4, m_Cargo->GetString(getCargoNr(op)) );
        m_OperatorList->SetItemPtrData(idx, (wxUIntPtr)op);
        idx++;
      }
      /* clean up the temp. list */
      ListOp.base.del(list);

      for( int n = 0; n < 3; n++ ) {
        m_OperatorList->SetColumnWidth(n, wxLIST_AUTOSIZE_USEHEADER);
        int autoheadersize = m_OperatorList->GetColumnWidth(n);
        m_OperatorList->SetColumnWidth(n, wxLIST_AUTOSIZE);
        int autosize = m_OperatorList->GetColumnWidth(n);
        if(autoheadersize > autosize )
          m_OperatorList->SetColumnWidth(n, wxLIST_AUTOSIZE_USEHEADER);
      }

      if( m_Props != NULL ) {
        setSelection(wOperator.getid( m_Props ));
      }
      else if( m_OperatorList->GetItemCount() > 0 ) {
        TraceOp.trc( "opdlg", TRCLEVEL_INFO, __LINE__, 9999, "no selection" );
      }
    }

  }

}


void OperatorDlg::setSelection(const char* ID) {
  int size = m_OperatorList->GetItemCount();
  for( int index = 0; index < size; index++ ) {
    iONode node = (iONode)m_OperatorList->GetItemData(index);
    if( StrOp.equals( ID, wOperator.getid(node) ) ) {
      m_OperatorList->SetItemState(index, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
      break;
    }
  }

}

int OperatorDlg::getCargoNr(iONode props) {
  int cargo = 0;
  if( StrOp.equals( wLoc.cargo_none, wOperator.getcargo( props ) ) )
    cargo = 0;
  else if( StrOp.equals( wLoc.cargo_goods, wOperator.getcargo( props ) ) )
    cargo = 1;
  else if( StrOp.equals( wLoc.cargo_person, wOperator.getcargo( props ) ) )
    cargo = 2;
  else if( StrOp.equals( wLoc.cargo_mixed, wOperator.getcargo( props ) ) )
    cargo = 3;
  else if( StrOp.equals( wLoc.cargo_cleaning, wOperator.getcargo( props ) ) )
    cargo = 4;
  else if( StrOp.equals( wLoc.cargo_ice, wOperator.getcargo( props ) ) )
    cargo = 5;
  else if( StrOp.equals( wLoc.cargo_post, wOperator.getcargo( props ) ) )
    cargo = 6;
  else if( StrOp.equals( wLoc.cargo_light, wOperator.getcargo( props ) ) )
    cargo = 7;
  else if( StrOp.equals( wLoc.cargo_lightgoods, wOperator.getcargo( props ) ) )
    cargo = 8;
  else if( StrOp.equals( wLoc.cargo_regional, wOperator.getcargo( props ) ) )
    cargo = 9;
  return cargo;
}

void OperatorDlg::initValues() {
  if( m_Props == NULL ) {
    TraceOp.trc( "opdlg", TRCLEVEL_DEBUG, __LINE__, 9999, "no operator selected" );
    return;
  }
  m_ControlPanel->Enable(true);
  m_ConsistPanel->Enable(true);

  char* title = StrOp.fmt( "%s %s", (const char*)wxGetApp().getMsg("operator").mb_str(wxConvUTF8), wOperator.getid( m_Props ) );
  SetTitle( wxString(title,wxConvUTF8) );
  StrOp.free( title );

  TraceOp.trc( "opdlg", TRCLEVEL_INFO, __LINE__, 9999, "initValues for operator [%s]", wOperator.getid( m_Props ) );

  m_Operator->SetValue( wxString(wOperator.getid( m_Props ),wxConvUTF8) );

  initLocos();
  initConsist();

  int cargo = getCargoNr(m_Props);
  m_Cargo->SetSelection( cargo );
  m_Class->SetValue( wxString(wOperator.getclass( m_Props ),wxConvUTF8) );
  m_VMax->SetValue( wOperator.getV_max( m_Props ) );

}


void OperatorDlg::onCarListSelected( wxListEvent& event ){
  int index = event.GetIndex();
  if( index != wxNOT_FOUND ) {
    iONode car = (iONode)m_CarList->GetItemData(index);
    m_CarProps = car;
    if( car != NULL && wCar.getimage( car ) != NULL && StrOp.len(wCar.getimage(car)) > 0 ) {
      wxBitmapType bmptype = wxBITMAP_TYPE_XPM;
      if( StrOp.endsWithi( wCar.getimage( car ), ".gif" ) )
        bmptype = wxBITMAP_TYPE_GIF;
      else if( StrOp.endsWithi( wCar.getimage( car ), ".png" ) )
        bmptype = wxBITMAP_TYPE_PNG;

      const char* imagepath = wGui.getimagepath(wxGetApp().getIni());
      static char pixpath[256];
      StrOp.fmtb( pixpath, "%s%c%s", imagepath, SystemOp.getFileSeparator(), FileOp.ripPath( wCar.getimage( car ) ) );

      if( FileOp.exist(pixpath)) {
        TraceOp.trc( "opdlg", TRCLEVEL_INFO, __LINE__, 9999, "picture [%s]", pixpath );
        m_CarImage->SetBitmapLabel( wxBitmap(wxString(pixpath,wxConvUTF8), bmptype) );
      }
      else {
        TraceOp.trc( "opdlg", TRCLEVEL_WARNING, __LINE__, 9999, "picture [%s] not found", pixpath );
        m_CarImage->SetBitmapLabel( wxBitmap(nopict_xpm) );
      }
      m_CarImage->SetToolTip(wxString(wCar.getroadname( car ),wxConvUTF8));


    }
    else {
      m_CarImage->SetBitmapLabel( wxBitmap(nopict_xpm) );
    }
    m_CarImage->Refresh();
  }
}

void OperatorDlg::initConsist() {
  m_CarList->DeleteAllItems();

  if( m_Props == NULL )
    return;

  m_CarProps = NULL;

  const char* carids = wOperator.getcarids(m_Props);
  iOStrTok strtok = StrTokOp.inst( carids, ',' );
  int i = 0;
  while( StrTokOp.hasMoreTokens( strtok ) ) {
    const char* carid  = StrTokOp.nextToken( strtok );
    iONode car = wxGetApp().getFrame()->findCar( carid );
    if( car != NULL ) {
      addCarToConsistList(i, car);
      i++;
    }
  }
  StrTokOp.base.del(strtok);

  resizeConsistColumns();

  if(m_CarList->GetItemCount() > 0 ) {
    m_CarList->SetItemState(0, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
    m_CarProps = (iONode)m_CarList->GetItemData(0);
  }


}


int OperatorDlg::findID( const char* ID ) {
  int size = m_OperatorList->GetItemCount();
  for( int index = 0; index < size; index++ ) {
    iONode node = (iONode)m_OperatorList->GetItemData(index);
    if( StrOp.equals( ID, wOperator.getid(node) ) ) {
      return index;
    }
  }
  return wxNOT_FOUND;
}




void OperatorDlg::onNewOperator( wxCommandEvent& event ) {
  int i = findID("NEW");
  if( i == wxNOT_FOUND ) {
    iONode model = wxGetApp().getModel();
    if( model != NULL ) {
      iONode operatorlist = wPlan.getoperatorlist( model );
      if( operatorlist == NULL ) {
        operatorlist = NodeOp.inst( wOperatorList.name(), model, ELEMENT_NODE );
        NodeOp.addChild( model, operatorlist );
      }
      if( operatorlist != NULL ) {
        iONode op = NodeOp.inst( wOperator.name(), operatorlist, ELEMENT_NODE );
        NodeOp.addChild( operatorlist, op );
        wOperator.setid( op, "NEW" );
        m_Props = op;
        initIndex();
        initValues();
        setSelection(wOperator.getid( op ));
      }
    }
  }
}


void OperatorDlg::onDelOperator( wxCommandEvent& event ) {
  if( m_Props == NULL )
    return;

  int action = wxMessageDialog( this, wxGetApp().getMsg("removewarning"), _T("Rocrail"), wxYES_NO | wxICON_EXCLAMATION ).ShowModal();
  if( action == wxID_NO )
    return;

  wxGetApp().pushUndoItem( (iONode)NodeOp.base.clone( m_Props ) );
  /* Notify RocRail. */
  iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
  wModelCmd.setcmd( cmd, wModelCmd.remove );
  NodeOp.addChild( cmd, (iONode)m_Props->base.clone( m_Props ) );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);

  iONode model = wxGetApp().getModel();
  if( model != NULL ) {
    iONode operatorlist = wPlan.getoperatorlist( model );
    if( operatorlist != NULL ) {
      NodeOp.removeChild( operatorlist, m_Props );
      m_Props = NULL;
    }
  }

  initIndex();
}


void OperatorDlg::OnCopy( wxCommandEvent& event ){
  if( m_Props != NULL ) {
    iONode model = wxGetApp().getModel();
    if( model != NULL ) {
      iONode operatorlist = wPlan.getoperatorlist( model );
      if( operatorlist == NULL ) {
        operatorlist = NodeOp.inst( wOperatorList.name(), model, ELEMENT_NODE );
        NodeOp.addChild( model, operatorlist );
      }

      if( operatorlist != NULL ) {
        iONode lccopy = (iONode)NodeOp.base.clone( m_Props );
        char* id = StrOp.fmt( "%s (copy)", wOperator.getid(lccopy));
        wOperator.setid(lccopy, id);
        StrOp.free(id);
        NodeOp.addChild( operatorlist, lccopy );
        initIndex();
      }

    }
  }
}


void OperatorDlg::onLocoImage( wxCommandEvent& event ) {
  if( m_LocoID->GetSelection() != wxNOT_FOUND ) {
    iONode lc = (iONode)((wxItemContainer*)m_LocoID)->GetClientData(m_LocoID->GetSelection());
    if( lc != NULL ) {
      LocDialog* dlg = new LocDialog(this, lc, false );
      if( wxID_OK == dlg->ShowModal() ) {
        /* Notify Notebook. */
      }
      dlg->Destroy();
      Raise();
    }
  }
}


void OperatorDlg::onLocomotiveCombo( wxCommandEvent& event ) {
  iONode lc = wxGetApp().getFrame()->findLoc( m_LocoID->GetStringSelection().mb_str(wxConvUTF8) );

  if( lc != NULL && wLoc.getimage( lc ) != NULL && StrOp.len(wLoc.getimage( lc )) > 0  ) {
    wxBitmapType bmptype = wxBITMAP_TYPE_XPM;
    if( StrOp.endsWithi( wLoc.getimage( lc ), ".gif" ) )
      bmptype = wxBITMAP_TYPE_GIF;
    else if( StrOp.endsWithi( wLoc.getimage( lc ), ".png" ) )
      bmptype = wxBITMAP_TYPE_PNG;
    else {
      m_LocoImage->SetBitmapLabel( wxBitmap(nopict_xpm) );
      m_LocoImage->Refresh();
      return;
    }

    const char* imagepath = wGui.getimagepath(wxGetApp().getIni());
    static char pixpath[256];
    StrOp.fmtb( pixpath, "%s%c%s", imagepath, SystemOp.getFileSeparator(), FileOp.ripPath( wLoc.getimage( lc ) ) );

    if( FileOp.exist(pixpath)) {
      TraceOp.trc( "opdlg", TRCLEVEL_INFO, __LINE__, 9999, "picture [%s]", pixpath );
      m_LocoImage->SetBitmapLabel( wxBitmap(wxString(pixpath,wxConvUTF8), bmptype) );
    }
    else {
      TraceOp.trc( "opdlg", TRCLEVEL_WARNING, __LINE__, 9999, "picture [%s] not found", pixpath );
      m_LocoImage->SetBitmapLabel( wxBitmap(nopict_xpm) );
    }
    m_LocoImage->SetToolTip(wxString(wLoc.getdesc( m_Props ),wxConvUTF8));


  }
  else {
    m_LocoImage->SetBitmapLabel( wxBitmap(nopict_xpm) );
  }
  m_LocoImage->Refresh();

}


void OperatorDlg::onReserve( wxCommandEvent& event ) {
  if( wOperator.getlcid( m_Props ) != NULL && StrOp.len(wOperator.getlcid( m_Props ) ) > 0 ) {
    /* Inform RocRail... */
    iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
    wLoc.setid( cmd, wOperator.getlcid( m_Props ) );
    wLoc.setcmd( cmd, wLoc.block );
    wLoc.setblockid( cmd, m_Location->GetStringSelection().mb_str(wxConvUTF8) );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


void OperatorDlg::onRun( wxCommandEvent& event ) {
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wOperator.getlcid( m_Props ) );
  wLoc.setcmd( cmd, wLoc.gotoblock );
  wLoc.setblockid( cmd, m_Goto->GetStringSelection().mb_str(wxConvUTF8) );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);

  cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wOperator.getlcid( m_Props ) );
  wLoc.setcmd( cmd, wLoc.go );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}


void OperatorDlg::onGotoMan( wxCommandEvent& event ) {
  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wOperator.getlcid( m_Props ) );
  wLoc.setcmd( cmd, wLoc.gotoblock );
  wLoc.setblockid( cmd, m_Goto->GetStringSelection().mb_str(wxConvUTF8) );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);

  cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );
  wLoc.setid( cmd, wOperator.getlcid( m_Props ) );
  wLoc.setcmd( cmd, wLoc.gomanual );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}


void OperatorDlg::onCarImage( wxCommandEvent& event ) {
  onCarCard(event);
}


void OperatorDlg::addCarToConsistList( int idx, iONode car ) {
  const char* id = wCar.getid( car );
  TraceOp.trc( "opdlg", TRCLEVEL_INFO, __LINE__, 9999, "adding car [%s]", id );
  m_CarList->InsertItem( idx, wxString(id,wxConvUTF8) );
  m_CarList->SetItem( idx, 1, wxString(wCar.getwaybills(car), wxConvUTF8) );
  m_CarList->SetItem( idx, 2, wxString(wCar.getlocation(car), wxConvUTF8) );
  iONode waybill = wxGetApp().getFrame()->findWaybill( wCar.getwaybills(car) );
  if( waybill != NULL ) {
    m_CarList->SetItem( idx, 3, wxString(wWaybill.getdestination(waybill), wxConvUTF8) );
  }
  m_CarList->SetItem( idx, 4, wxString::Format(wxT("%d"), wCar.getV_max(car)) );
  m_CarList->SetItemPtrData(idx, (wxUIntPtr)car);
}


void OperatorDlg::resizeConsistColumns() {
  // resize
  for( int n = 0; n < 4; n++ ) {
    m_CarList->SetColumnWidth(n, wxLIST_AUTOSIZE_USEHEADER);
    int autoheadersize = m_CarList->GetColumnWidth(n);
    m_CarList->SetColumnWidth(n, wxLIST_AUTOSIZE);
    int autosize = m_CarList->GetColumnWidth(n);
    if(autoheadersize > autosize )
      m_CarList->SetColumnWidth(n, wxLIST_AUTOSIZE_USEHEADER);
  }
}


void OperatorDlg::onAddCar( wxCommandEvent& event ) {
  if( m_Props != NULL ) {
    CarDlg* dlg = new CarDlg(this, NULL, false, wOperator.getid( m_Props ), wOperator.getcarids(m_Props), wOperator.getlocation(m_Props) );
    if( wxID_OK == dlg->ShowModal() ) {
      /* Notify Notebook. */
      iONode car = dlg->getSelectedCar();
      if( car != NULL ) {
        int carcnt = m_CarList->GetItemCount();
        addCarToConsistList(carcnt, car);
        resizeConsistColumns();
        evaluate();
      }
    }
    dlg->Destroy();
    Raise();
  }
}


int OperatorDlg::findCarID( const char* ID ) {
  int size = m_CarList->GetItemCount();
  for( int index = 0; index < size; index++ ) {
    iONode node = (iONode)m_CarList->GetItemData(index);
    if( StrOp.equals( ID, wCar.getid(node) ) ) {
      return index;
    }
  }
  return wxNOT_FOUND;
}


void OperatorDlg::onLeaveCar( wxCommandEvent& event ) {
  if( m_CarProps == NULL )
    return;

  int idx = findCarID(wCar.getid(m_CarProps));
  if( idx != wxNOT_FOUND ) {
    m_CarList->DeleteItem(idx);
    m_CarImage->SetBitmapLabel( wxBitmap(nopict_xpm) );
    m_CarImage->Refresh();
    evaluate();
    initConsist();
  }
}


void OperatorDlg::onCarCard( wxCommandEvent& event ) {
  if( m_CarProps == NULL )
    return;

  int idx = findCarID(wCar.getid(m_CarProps));
  if( idx != wxNOT_FOUND ) {
    iONode car = (iONode)m_CarList->GetItemData(idx);
    if( car != NULL ) {
      CarDlg* dlg = new CarDlg(this, car, false );
      if( wxID_OK == dlg->ShowModal() ) {
        /* Notify Notebook. */
      }
      dlg->Destroy();
      Raise();
    }
  }
}


void OperatorDlg::onWayBill( wxCommandEvent& event ) {
  if( m_CarProps == NULL )
    return;

  int idx = findCarID(wCar.getid(m_CarProps));
  if( idx != wxNOT_FOUND ) {
    iONode car = (iONode)m_CarList->GetItemData(idx);
    if( car != NULL ) {
      iONode waybill = NULL;
      const char* waybills = wCar.getwaybills(car);

      if( waybills != NULL && StrOp.len(waybills) > 0 ) {
        /* TODO: get waybill node for the first entry in the list */
        iOStrTok strtok = StrTokOp.inst( waybills, ',' );
        while( StrTokOp.hasMoreTokens( strtok ) ) {
          const char* billid  = StrTokOp.nextToken( strtok );
          waybill = wxGetApp().getFrame()->findWaybill( billid );
          break;
        }
      }

      WaybillDlg* dlg = new WaybillDlg(this, waybill, true );
      if( wxID_OK == dlg->ShowModal() ) {
        /* Notify Notebook. */
        iONode waybill = dlg->getSelectedWaybill();
        if( waybill != NULL ) {
          if( dlg->isDelivered() )
            wCar.setwaybills( car, "" );
          else
            wCar.setwaybills( car, wWaybill.getid(waybill) );

          if( !wxGetApp().isStayOffline() ) {
            /* Notify RocRail. */
            iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
            wModelCmd.setcmd( cmd, wModelCmd.modify );
            NodeOp.addChild( cmd, (iONode)m_Props->base.clone( m_CarProps ) );
            wxGetApp().sendToRocrail( cmd );
            cmd->base.del(cmd);
          }
          initConsist();
        }
      }
      dlg->Destroy();
      Raise();
    }
  }

}


void OperatorDlg::onApply( wxCommandEvent& event ) {
  if( m_Props == NULL || !m_bSave )
    return;

  evaluate();
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
  initIndex();
}


void OperatorDlg::onCancel( wxCommandEvent& event ) {
  if( m_bSave ) {
    Destroy();
  }
  else {
    EndModal( 0 );
  }
}


void OperatorDlg::onOK( wxCommandEvent& event ) {
  if( m_bSave ) {
    onApply(event);
    Destroy();
  }
  else {
    EndModal( wxID_OK );
  }
}


void OperatorDlg::onSetLocation( wxCommandEvent& event )  {
  iONode cmd = NodeOp.inst( wOperator.name(), NULL, ELEMENT_NODE );
  wOperator.setid( cmd, wOperator.getid( m_Props ) );
  wOperator.setcmd( cmd, wLoc.block );
  wOperator.setlocation( cmd, m_Location->GetStringSelection().mb_str(wxConvUTF8) );
  wOperator.setlocation( m_Props, wOperator.getlocation(cmd) );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
  initIndex();
}


void OperatorDlg::onTabChanged( wxNotebookEvent& event ) {
  if( event.GetSelection() == 2) {
    initConsist();
  }
  event.Skip();
}


void OperatorDlg::onShowAllOperators( wxCommandEvent& event ) {
  initIndex();
}

void OperatorDlg::onHelp( wxCommandEvent& event )  {
  switch( m_OperatorBook->GetSelection() ) {
  case 0: wxGetApp().openLink( "operator-index" ); break;
  case 1: wxGetApp().openLink( "operator-loco" ); break;
  case 2: wxGetApp().openLink( "operator-consist" ); break;
  default: wxGetApp().openLink( "operator-control" ); break;
  }
}

