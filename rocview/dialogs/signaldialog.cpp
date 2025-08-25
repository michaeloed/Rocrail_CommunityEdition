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
#if defined(__GNUG__) && !defined(__APPLE__)
#pragma implementation "signaldialog.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
#include "wx/imaglist.h"
////@end includes

#include "signaldialog.h"
#include "actionsctrldlg.h"

////@begin XPM images
////@end XPM images

#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/SignalList.h"
#include "rocrail/wrapper/public/Item.h"
#include "rocrail/wrapper/public/Plan.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/Item.h"
#include "rocview/public/guiapp.h"


/*!
 * SignalDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( SignalDialog, wxDialog )

/*!
 * SignalDialog event table definition
 */

BEGIN_EVENT_TABLE( SignalDialog, wxDialog )

////@begin SignalDialog event table entries
    EVT_LIST_ITEM_SELECTED( ID_LISTCTRLINDEX_SG, SignalDialog::OnListctrlindexSgSelected )
    EVT_LIST_COL_CLICK( ID_LISTCTRLINDEX_SG, SignalDialog::OnListctrlindexSgColLeftClick )
    EVT_BUTTON( ID_BUTTON_SG_NEW, SignalDialog::OnButtonSgNewClick )
    EVT_BUTTON( ID_BUTTON_SG_DELETE, SignalDialog::OnButtonSgDeleteClick )
    EVT_BUTTON( ID_BUTTON_SG_DOC, SignalDialog::OnButtonSgDocClick )
    EVT_CHECKBOX( ID_SIGNAL_MANUAL, SignalDialog::OnSignalManualClick )
    EVT_BUTTON( ID_SIGNAL_ACTIONS, SignalDialog::OnSignalActionsClick )
    EVT_RADIOBOX( ID_SIGNALCONTROL, SignalDialog::OnSignalcontrolSelected )
    EVT_CHECKBOX( wxID_ANY, SignalDialog::onAccessory )
    EVT_CHECKBOX( ID_CHECKBOX_SG_PAIRGATES, SignalDialog::OnCheckboxSgPairgatesClick )
    EVT_BUTTON( wxID_CANCEL, SignalDialog::OnCancelClick )
    EVT_BUTTON( wxID_OK, SignalDialog::OnOkClick )
    EVT_BUTTON( wxID_APPLY, SignalDialog::OnApplyClick )
    EVT_BUTTON( wxID_HELP, SignalDialog::OnHelpClick )
////@end SignalDialog event table entries
    EVT_MENU( ID_PANEL_SG_GENERAL, SignalDialog::OnSelectPage )

END_EVENT_TABLE()

/*!
 * SignalDialog constructors
 */

SignalDialog::SignalDialog( )
{
}

SignalDialog::SignalDialog( wxWindow* parent, iONode p_Props )
{
  m_TabAlign = wxGetApp().getTabAlign();
  Create(parent, -1, wxGetApp().getMsg("signaltable") );

  m_Props = p_Props;

  initLabels();
  m_IndexPanel->GetSizer()->Layout();
  m_GeneralPanel->GetSizer()->Layout();
  m_LocationPanel->GetSizer()->Layout();
  m_InterfacePanel->GetSizer()->Layout();
  m_InterfacePanel->GetSizer()->Fit(m_Notebook);
  m_PropsPanel->GetSizer()->Layout();
  m_Notebook->Fit();
  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);

  if( initIndex() ) {
    initValues();
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ID_PANEL_SG_GENERAL );
    wxPostEvent( this, event );
  }

}


/* comparator for sorting by id: */
static int __sortStr(obj* _a, obj* _b)
{
    const char* a = (const char*)*_a;
    const char* b = (const char*)*_b;
    return strcmp( a, b );
}


void SignalDialog::initLabels() {
  m_Notebook->SetPageText( 0, wxGetApp().getMsg( "index" ) );
  m_Notebook->SetPageText( 1, wxGetApp().getMsg( "general" ) );
  m_Notebook->SetPageText( 2, wxGetApp().getMsg( "position" ) );
  m_Notebook->SetPageText( 3, wxGetApp().getMsg( "interface" ) );
  m_Notebook->SetPageText( 4, wxGetApp().getMsg( "details" ) );

  // Index
  initList(m_List2, this);
  m_New->SetLabel( wxGetApp().getMsg( "new" ) );
  m_Delete->SetLabel( wxGetApp().getMsg( "delete" ) );
  m_Doc->SetLabel( wxGetApp().getMsg( "doc_report" ) );

  // General
  m_LabelID->SetLabel( wxGetApp().getMsg( "id" ) );
  m_LabelState->SetLabel( wxGetApp().getMsg( "state" ) );
  m_Road->SetLabel( wxGetApp().getMsg( "road" ) );
  m_LabelDescription->SetLabel( wxGetApp().getMsg( "description" ) );
  m_LabelBlockID->SetLabel( wxGetApp().getMsg( "blockid" ) );
  m_Actions->SetLabel( wxGetApp().getMsg( "actions" )+_T("...") );
  m_labRouteIDs->SetLabel( wxGetApp().getMsg( "routeids" ) );
  m_Manual->SetLabel( wxGetApp().getMsg( "manualoperated" ) );
  m_ResetManual->SetLabel( wxGetApp().getMsg( "reset" ) );

  m_BlockID->Append( _T("") );
  iOList list = ListOp.inst();
  iONode model = wxGetApp().getModel();

  if( model != NULL ) {
    iONode bklist = wPlan.getbklist( model );
    if( bklist != NULL ) {
      int cnt = NodeOp.getChildCnt( bklist );
      for( int i = 0; i < cnt; i++ ) {
        iONode bk = NodeOp.getChild( bklist, i );
        ListOp.add(list, (obj)wBlock.getid( bk ));
      }
    }
    iONode fblist = wPlan.getfblist( model );
    if( fblist != NULL ) {
      int cnt = NodeOp.getChildCnt( fblist );
      for( int i = 0; i < cnt; i++ ) {
        iONode fb = NodeOp.getChild( fblist, i );
        ListOp.add(list, (obj)wFeedback.getid( fb ));
      }
    }
    iONode colist = wPlan.getcolist( model );
    if( colist != NULL ) {
      int cnt = NodeOp.getChildCnt( colist );
      for( int i = 0; i < cnt; i++ ) {
        iONode co = NodeOp.getChild( colist, i );
        ListOp.add(list, (obj)wOutput.getid( co ));
      }
    }

    ListOp.sort(list, &__sortStr);
    int cnt = ListOp.size( list );
    for( int i = 0; i < cnt; i++ ) {
      const char* id = (const char*)ListOp.get( list, i );
      m_BlockID->Append( wxString(id,wxConvUTF8) );
    }

  }


  // Location
  m_LabelX->SetLabel( wxGetApp().getMsg( "x" ) );
  m_LabelY->SetLabel( wxGetApp().getMsg( "y" ) );
  m_LabelZ->SetLabel( wxGetApp().getMsg( "z" ) );
  m_ori->SetLabel( wxGetApp().getMsg( "orientation" ) );
  m_ori->SetString( 0, wxGetApp().getMsg( "north" ) );
  m_ori->SetString( 1, wxGetApp().getMsg( "east" ) );
  m_ori->SetString( 2, wxGetApp().getMsg( "south" ) );
  m_ori->SetString( 3, wxGetApp().getMsg( "west" ) );

  // Interface
  BaseDialog::addIIDs(m_iid);

  m_Labeliid->SetLabel( wxGetApp().getMsg( "iid" ) );
  m_Label_Bus->SetLabel( wxGetApp().getMsg( "bus" ) );
  m_labUIDName->SetLabel(wxGetApp().getMsg( "uidname" ));

  m_labAddress->SetLabel(wxGetApp().getMsg( "address"));
  m_labPort->SetLabel(wxGetApp().getMsg( "port"));

  m_RedBox->SetLabel(wxGetApp().getMsg( "red").Upper());
  m_YellowBox->SetLabel(wxGetApp().getMsg( "yellow").Upper());
  m_GreenBox->SetLabel(wxGetApp().getMsg( "green").Upper());
  m_WhiteBox->SetLabel(wxGetApp().getMsg( "white").Upper());
  //m_Gate1->SetLabel( wxGetApp().getMsg( "gate" ) );
  m_Gate1->SetString( 0, wxGetApp().getMsg( "red" ) );
  m_Gate1->SetString( 1, wxGetApp().getMsg( "green" ) );

  //m_Gate2->SetLabel( wxGetApp().getMsg( "gate" ) );
  m_Gate2->SetString( 0, wxGetApp().getMsg( "red" ) );
  m_Gate2->SetString( 1, wxGetApp().getMsg( "green" ) );

  //m_Gate3->SetLabel( wxGetApp().getMsg( "gate" ) );
  m_Gate3->SetString( 0, wxGetApp().getMsg( "red" ) );
  m_Gate3->SetString( 1, wxGetApp().getMsg( "green" ) );

  //(m_Gate4->SetLabel( wxGetApp().getMsg( "gate" ) );
  m_Gate4->SetString( 0, wxGetApp().getMsg( "red" ) );
  m_Gate4->SetString( 1, wxGetApp().getMsg( "green" ) );

  m_LabelProt->SetLabel( wxGetApp().getMsg( "protocol" ) );
  m_SignalControl->SetLabel( wxGetApp().getMsg( "control" ) );
  m_SignalControl->SetString( 0, wxGetApp().getMsg( "default" ) );
  m_SignalControl->SetString( 1, wxGetApp().getMsg( "patterns" ) );
  m_SignalControl->SetString( 2, wxGetApp().getMsg( "aspectnr" ) );
  m_SignalControl->SetString( 3, wxGetApp().getMsg( "linear" ) );
  m_SignalControl->SetString( 4, wxGetApp().getMsg( "binary" ) );

  m_Invert->SetLabel( wxGetApp().getMsg( "invert" ) );
  m_PairGates->SetLabel( wxGetApp().getMsg( "pairgates" ) );
  m_AsSwitch->SetLabel( wxGetApp().getMsg( "turnout" ) );
  m_Accessory->SetLabel( wxGetApp().getMsg( "accessory" ) );
  m_labCmdTime->SetLabel( wxGetApp().getMsg( "cmdtime" ) );

  m_PortType->SetLabel( wxGetApp().getMsg( "type" ) );
  m_PortType->SetString( 0, wxGetApp().getMsg( "output" ) );
  m_PortType->SetString( 1, wxGetApp().getMsg( "lights" ) );
  m_PortType->SetString( 2, wxGetApp().getMsg( "servo" ) );
  m_PortType->SetString( 3, wxGetApp().getMsg( "sound" ) );
  m_PortType->SetString( 4, wxGetApp().getMsg( "motor" ) );
  m_PortType->SetString( 5, wxGetApp().getMsg( "analog" ) );
  m_PortType->SetString( 6, wxGetApp().getMsg( "macro" ) );

  m_Prot->Clear();
  m_Prot->Append(_T("Default"));
  m_Prot->Append(_T("Motorola"));
  m_Prot->Append(_T("NMRA-DCC"));


  // propeties
  m_Type->SetLabel( wxGetApp().getMsg( "signal_type" ) );
  m_Type->SetString( 0, wxGetApp().getMsg( "semaphore_signal" ) );
  m_Type->SetString( 1, wxGetApp().getMsg( "light_signal" ) );

  m_Signal->SetLabel( wxGetApp().getMsg( "signification" ) );
  m_Signal->SetString( 0, wxGetApp().getMsg( "distant_signal" ) );
  m_Signal->SetString( 1, wxGetApp().getMsg( "main_signal" ) );
  m_Signal->SetString( 2, wxGetApp().getMsg( "shunting_signal" ) );
  m_Signal->SetString( 3, wxGetApp().getMsg( "blockstate_signal" ) );

  m_labAspects->SetLabel( wxGetApp().getMsg( "aspects" ) );
  m_labSymbolPrefix->SetLabel( wxGetApp().getMsg( "prefix" ) );
  m_UseSymbolPrefix->SetLabel( wxGetApp().getMsg( "forcemultiaspects" ) );
  m_Dwarf->SetLabel( wxGetApp().getMsg( "dwarfsignal" ) );

  m_labAspect->SetLabel( wxGetApp().getMsg( "aspect" ) + _T(":") );
  m_labPatternAddr1->SetLabel( wxGetApp().getMsg( "red" ).Upper() + _T(" ") + wxGetApp().getMsg( "address" ) + _T(":") );
  m_labPatternAddr2->SetLabel( wxGetApp().getMsg( "green" ).Upper() + _T(" ") + wxGetApp().getMsg( "address" ) + _T(":") );
  m_labAspectNr->SetLabel( wxGetApp().getMsg( "number" ) + _T(":") );

  m_labSignalPatterns->SetLabel( wxGetApp().getMsg( "patterns" ) );
  m_labGreen->SetLabel( wxGetApp().getMsg( "green" ) );
  m_labRed->SetLabel( wxGetApp().getMsg( "red" ) );
  m_labYellow->SetLabel( wxGetApp().getMsg( "yellow" ) );
  m_labWhite->SetLabel( wxGetApp().getMsg( "white" ) );
  m_labBlank->SetLabel( wxGetApp().getMsg( "blank" ) );

  m_labAspectNames->SetLabel( wxGetApp().getMsg( "aspectnames" ) );

  // Buttons
  m_OK->SetLabel( wxGetApp().getMsg( "ok" ) );
  m_Cancel->SetLabel( wxGetApp().getMsg( "cancel" ) );
  m_Apply->SetLabel( wxGetApp().getMsg( "apply" ) );
}


void SignalDialog::OnSelectPage(wxCommandEvent& event) {
  m_Notebook->SetSelection( 1 );
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


bool SignalDialog::initIndex() {
  TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999, "InitIndex" );
  iONode model = wxGetApp().getModel();
  if( model != NULL ) {
    iONode sglist = wPlan.getsglist( model );

    if( sglist != NULL ) {
      fillIndex(sglist);

      if( m_Props != NULL ) {
        setIDSelection(wItem.getid( m_Props ));
        return true;
      }
      else {
        m_Props = setSelection(0);
      }

    }
  }
  return false;
}

void SignalDialog::initValues() {
  char* title = StrOp.fmt( "%s %s", (const char*)wxGetApp().getMsg("signal").mb_str(wxConvUTF8), wSignal.getid( m_Props ) );
  SetTitle( wxString(title,wxConvUTF8) );
  StrOp.free( title );

  // General
  m_ID->SetValue( wxString(wSignal.getid( m_Props ),wxConvUTF8) );
  m_Description->SetValue( wxString(wSignal.getdesc( m_Props ),wxConvUTF8) );
  m_State->SetValue( wSignal.getstate( m_Props )==NULL ?_T("<undef>"):wxString(wSignal.getstate( m_Props ),wxConvUTF8)  );
  m_Road->SetValue( wItem.isroad( m_Props )?true:false );
  m_BlockID->SetStringSelection( wSignal.getblockid( m_Props ) == NULL ?
                                _T(""):wxString(wSignal.getblockid( m_Props ),wxConvUTF8)  );
  m_RouteIDs->SetValue( wxString(wItem.getrouteids( m_Props ),wxConvUTF8) );
  m_Manual->SetValue( wSignal.ismanual( m_Props )?true:false );
  m_ResetManual->SetValue( wSignal.ismanualreset( m_Props )?true:false );
  wxCommandEvent eventManual;
  OnSignalManualClick( eventManual );

  // Location
  char* str = StrOp.fmt( "%d", wSignal.getx( m_Props ) );
  m_x->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wSignal.gety( m_Props ) );
  m_y->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wSignal.getz( m_Props ) );
  m_z->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );
  if( StrOp.equals( wItem.north, wSignal.getori( m_Props ) ) )
    m_ori->SetSelection( 0 );
  else if( StrOp.equals( wItem.east, wSignal.getori( m_Props ) ) )
    m_ori->SetSelection( 1 );
  else if( StrOp.equals( wItem.south, wSignal.getori( m_Props ) ) )
    m_ori->SetSelection( 2 );
  else
    m_ori->SetSelection( 3 );

  // Interface
  m_UIDName->SetValue( wxString(wItem.getuidname( m_Props ),wxConvUTF8) );
  m_iid->SetValue( wxString(wSignal.getiid( m_Props ),wxConvUTF8) );
  str = StrOp.fmt( "%d", wSignal.getbus(m_Props) );
  m_Bus->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wSignal.getaddr(m_Props) );
  m_Address->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wSignal.getaddr2(m_Props) );
  m_Address2->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wSignal.getaddr3(m_Props) );
  m_Address3->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wSignal.getaddr4(m_Props) );
  m_Address4->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );

  str = StrOp.fmt( "%d", wSignal.getport1(m_Props) );
  m_Port->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wSignal.getport2(m_Props) );
  m_Port2->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wSignal.getport3(m_Props) );
  m_Port3->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wSignal.getport4(m_Props) );
  m_Port4->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );

  m_Gate1->SetSelection( wSignal.getgate1(m_Props) );
  m_Gate2->SetSelection( wSignal.getgate2(m_Props) );
  m_Gate3->SetSelection( wSignal.getgate3(m_Props) );
  m_Gate4->SetSelection( wSignal.getgate4(m_Props) );

  if( StrOp.equals( wSignal.prot_DEF, wSignal.getprot( m_Props ) ) )
    m_Prot->SetSelection( 0 );
  else if( StrOp.equals( wSignal.prot_M, wSignal.getprot( m_Props ) ) )
    m_Prot->SetSelection( 1 );
  else if( StrOp.equals( wSignal.prot_N, wSignal.getprot( m_Props ) ) )
    m_Prot->SetSelection( 2 );

  m_CmdTime->SetValue( wSignal.getcmdtime(m_Props) );

  // properties
  if( StrOp.equals( wSignal.semaphore, wSignal.gettype( m_Props ) ) )
    m_Type->SetSelection( 0 );
  else if( StrOp.equals( wSignal.light, wSignal.gettype( m_Props ) ) )
    m_Type->SetSelection( 1 );

  if( StrOp.equals( wSignal.distant, wSignal.getsignal( m_Props ) ) )
    m_Signal->SetSelection( 0 );
  else if( StrOp.equals( wSignal.main, wSignal.getsignal( m_Props ) ) )
    m_Signal->SetSelection( 1 );
  else if( StrOp.equals( wSignal.shunting, wSignal.getsignal( m_Props ) ) )
    m_Signal->SetSelection( 2 );
  else if( StrOp.equals( wSignal.blockstate, wSignal.getsignal( m_Props ) ) )
    m_Signal->SetSelection( 3 );

  m_Aspects->SetValue( wSignal.getaspects( m_Props ) );
  m_SymbolPrefix->SetValue( wxString(wSignal.getsymbolprefix( m_Props ),wxConvUTF8) );
  m_Dwarf->SetValue( wSignal.isdwarf( m_Props ) );
  m_UseSymbolPrefix->SetValue( wSignal.isusesymbolprefix( m_Props ) );

  m_SignalControl->SetSelection( wSignal.getusepatterns( m_Props ) );

  wxCommandEvent event( -1, -1 );
  OnSignalcontrolSelected( event );


  m_Invert->SetValue( wSignal.isinv( m_Props )?true:false );
  m_PairGates->SetValue( wSignal.ispair( m_Props )?true:false );
  m_AsSwitch->SetValue( wSignal.isasswitch( m_Props )?true:false );
  m_Accessory->SetValue( wSignal.isaccessory( m_Props )?true:false );
  m_PortType->Enable(!m_Accessory->IsChecked());
  if(wSignal.isaccessory(m_Props))
    wSignal.setporttype(m_Props, 0);

  if( wSignal.ispair( m_Props ) ) {
    m_Gate1->Enable(false);
    m_Gate2->Enable(false);
    m_Gate3->Enable(false);
    m_Gate4->Enable(false);
  }

  m_PortType->SetSelection(wSignal.getporttype(m_Props));

  /* patterns */
  m_Green1->SetSelection( wSignal.getgreen( m_Props ) & 0x0F );
  m_Green2->SetSelection( (wSignal.getgreen( m_Props ) & 0xF0) >> 4 );

  m_Red1->SetSelection( wSignal.getred( m_Props ) & 0x0F );
  m_Red2->SetSelection( (wSignal.getred( m_Props ) & 0xF0) >> 4 );

  m_Yellow1->SetSelection( wSignal.getyellow( m_Props ) & 0x0F );
  m_Yellow2->SetSelection( (wSignal.getyellow( m_Props ) & 0xF0) >> 4 );

  m_White1->SetSelection( wSignal.getwhite( m_Props ) & 0x0F );
  m_White2->SetSelection( (wSignal.getwhite( m_Props ) & 0xF0) >> 4 );

  m_Blank1->SetSelection( wSignal.getblank( m_Props ) & 0x0F );
  m_Blank2->SetSelection( (wSignal.getblank( m_Props ) & 0xF0) >> 4 );

  /* Aspect numbers */
  m_GreenNr->SetValue( wSignal.getgreennr( m_Props) );
  m_RedNr->SetValue( wSignal.getrednr( m_Props) );
  m_YellowNr->SetValue( wSignal.getyellownr( m_Props) );
  m_WhiteNr->SetValue(wSignal.getwhitenr( m_Props) );
  m_BlankNr->SetValue(wSignal.getblanknr( m_Props) );

  m_AspectNames->SetValue( wxString(wSignal.getaspectnames( m_Props ),wxConvUTF8) );
}


bool SignalDialog::evaluate() {
  if( m_Props == NULL )
    return false;

  iONode model  = wxGetApp().getModel();
  iONode sglist = wPlan.getsglist( model );

  if( existID( this, sglist, m_Props, m_ID->GetValue() ) ) {
    m_ID->SetValue( wxString(wItem.getid( m_Props ),wxConvUTF8) );
    return false;
  }

  // General
  wItem.setprev_id( m_Props, wItem.getid(m_Props) );
  wSignal.setid( m_Props, m_ID->GetValue().mb_str(wxConvUTF8) );
  wSignal.setdesc( m_Props, m_Description->GetValue().mb_str(wxConvUTF8) );
  wSignal.setblockid( m_Props, m_BlockID->GetStringSelection().mb_str(wxConvUTF8) );
  wItem.setroad( m_Props, m_Road->IsChecked()?True:False );
  wItem.setrouteids( m_Props, m_RouteIDs->GetValue().mb_str(wxConvUTF8) );
  wSignal.setmanual( m_Props, m_Manual->IsChecked()?True:False );
  wSignal.setmanualreset( m_Props, m_ResetManual->IsChecked()?True:False );

  // Location
  wSignal.setx( m_Props, atoi( m_x->GetValue().mb_str(wxConvUTF8) ) );
  wSignal.sety( m_Props, atoi( m_y->GetValue().mb_str(wxConvUTF8) ) );
  wSignal.setz( m_Props, atoi( m_z->GetValue().mb_str(wxConvUTF8) ) );
  int ori = m_ori->GetSelection();
  if( ori == 0 )
    wSignal.setori( m_Props, wItem.north );
  else if( ori == 1 )
    wSignal.setori( m_Props, wItem.east );
  else if( ori == 2 )
    wSignal.setori( m_Props, wItem.south );
  else if( ori == 3 )
    wSignal.setori( m_Props, wItem.west );

  // Interface
  wSignal.setiid( m_Props, m_iid->GetValue().mb_str(wxConvUTF8) );
  wItem.setuidname( m_Props, m_UIDName->GetValue().mb_str(wxConvUTF8) );
  wSignal.setbus( m_Props, atoi( m_Bus->GetValue().mb_str(wxConvUTF8) ) );
  wSignal.setaddr( m_Props, atoi( m_Address->GetValue().mb_str(wxConvUTF8) ) );
  wSignal.setaddr2( m_Props, atoi( m_Address2->GetValue().mb_str(wxConvUTF8) ) );
  wSignal.setaddr3( m_Props, atoi( m_Address3->GetValue().mb_str(wxConvUTF8) ) );
  wSignal.setaddr4( m_Props, atoi( m_Address4->GetValue().mb_str(wxConvUTF8) ) );

  wSignal.setport1( m_Props, atoi( m_Port->GetValue().mb_str(wxConvUTF8) ) );
  wSignal.setport2( m_Props, atoi( m_Port2->GetValue().mb_str(wxConvUTF8) ) );
  wSignal.setport3( m_Props, atoi( m_Port3->GetValue().mb_str(wxConvUTF8) ) );
  wSignal.setport4( m_Props, atoi( m_Port4->GetValue().mb_str(wxConvUTF8) ) );

  wSignal.setgate1( m_Props, m_Gate1->GetSelection() );
  wSignal.setgate2( m_Props, m_Gate2->GetSelection() );
  wSignal.setgate3( m_Props, m_Gate3->GetSelection() );
  wSignal.setgate4( m_Props, m_Gate4->GetSelection() );

  if( m_Prot->GetSelection() == 0 )
    wSignal.setprot( m_Props, wSignal.prot_DEF );
  else if( m_Prot->GetSelection() == 1 )
    wSignal.setprot( m_Props, wSignal.prot_M );
  else if( m_Prot->GetSelection() == 2 )
    wSignal.setprot( m_Props, wSignal.prot_N );

  int type = m_Type->GetSelection();
  if( type == 0 )
    wSignal.settype( m_Props, wSignal.semaphore );
  else if( type == 1 )
    wSignal.settype( m_Props, wSignal.light );

  int signal = m_Signal->GetSelection();
  if( signal == 0 )
    wSignal.setsignal( m_Props, wSignal.distant );
  else if( signal == 1 )
    wSignal.setsignal( m_Props, wSignal.main );
  else if( signal == 2 )
    wSignal.setsignal( m_Props, wSignal.shunting );
  else if( signal == 3 )
    wSignal.setsignal( m_Props, wSignal.blockstate );

  wSignal.setaspects( m_Props, m_Aspects->GetValue() );
  wSignal.setsymbolprefix( m_Props, m_SymbolPrefix->GetValue().mb_str(wxConvUTF8) );
  wSignal.setdwarf( m_Props, m_Dwarf->IsChecked()?True:False );
  wSignal.setusesymbolprefix( m_Props, m_UseSymbolPrefix->IsChecked()?True:False );


  wSignal.setusepatterns( m_Props, m_SignalControl->GetSelection() );

  wSignal.setinv( m_Props, m_Invert->GetValue()?True:False);
  wSignal.setpair( m_Props, m_PairGates->GetValue()?True:False);
  wSignal.setasswitch( m_Props, m_AsSwitch->GetValue()?True:False);
  wSignal.setaccessory( m_Props, m_Accessory->GetValue()?True:False);

  wSignal.setcmdtime(m_Props, m_CmdTime->GetValue() );

  wSignal.setporttype(m_Props, m_PortType->GetSelection());

  /* Patterns */
  wSignal.setgreen ( m_Props, m_Green1->GetSelection()  + (m_Green2->GetSelection()  << 4) );
  wSignal.setred   ( m_Props, m_Red1->GetSelection()    + (m_Red2->GetSelection()    << 4) );
  wSignal.setyellow( m_Props, m_Yellow1->GetSelection() + (m_Yellow2->GetSelection() << 4) );
  wSignal.setwhite ( m_Props, m_White1->GetSelection()  + (m_White2->GetSelection()  << 4) );
  wSignal.setblank ( m_Props, m_Blank1->GetSelection()  + (m_Blank2->GetSelection()  << 4) );

  /* Aspect numbers */
  wSignal.setgreennr ( m_Props, m_GreenNr->GetValue() );
  wSignal.setrednr   ( m_Props, m_RedNr->GetValue() );
  wSignal.setyellownr( m_Props, m_YellowNr->GetValue() );
  wSignal.setwhitenr ( m_Props, m_WhiteNr->GetValue() );
  wSignal.setblanknr ( m_Props, m_BlankNr->GetValue() );

  wSignal.setaspectnames( m_Props, m_AspectNames->GetValue().mb_str(wxConvUTF8) );

  return true;
}




/*!
 * SignalDialog creator
 */

bool SignalDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin SignalDialog member initialisation
    m_Notebook = NULL;
    m_IndexPanel = NULL;
    m_List2 = NULL;
    m_New = NULL;
    m_Delete = NULL;
    m_Doc = NULL;
    m_GeneralPanel = NULL;
    m_LabelID = NULL;
    m_ID = NULL;
    m_LabelDescription = NULL;
    m_Description = NULL;
    m_LabelBlockID = NULL;
    m_BlockID = NULL;
    m_labRouteIDs = NULL;
    m_RouteIDs = NULL;
    m_LabelState = NULL;
    m_State = NULL;
    m_Manual = NULL;
    m_ResetManual = NULL;
    m_Road = NULL;
    m_Actions = NULL;
    m_LocationPanel = NULL;
    m_LabelX = NULL;
    m_x = NULL;
    m_LabelY = NULL;
    m_y = NULL;
    m_LabelZ = NULL;
    m_z = NULL;
    m_ori = NULL;
    m_InterfacePanel = NULL;
    m_Labeliid = NULL;
    m_iid = NULL;
    m_Label_Bus = NULL;
    m_Bus = NULL;
    m_labUIDName = NULL;
    m_UIDName = NULL;
    m_RedBox = NULL;
    m_labAddress = NULL;
    m_labPort = NULL;
    m_Address = NULL;
    m_Port = NULL;
    m_Gate1 = NULL;
    m_GreenBox = NULL;
    m_Address2 = NULL;
    m_Port2 = NULL;
    m_Gate2 = NULL;
    m_YellowBox = NULL;
    m_Address3 = NULL;
    m_Port3 = NULL;
    m_Gate3 = NULL;
    m_WhiteBox = NULL;
    m_Address4 = NULL;
    m_Port4 = NULL;
    m_Gate4 = NULL;
    m_LabelProt = NULL;
    m_Prot = NULL;
    m_SignalControl = NULL;
    m_Accessory = NULL;
    m_PortType = NULL;
    m_Invert = NULL;
    m_PairGates = NULL;
    m_AsSwitch = NULL;
    m_labCmdTime = NULL;
    m_CmdTime = NULL;
    m_PropsPanel = NULL;
    m_Type = NULL;
    m_Signal = NULL;
    m_labAspects = NULL;
    m_Aspects = NULL;
    m_labSymbolPrefix = NULL;
    m_SymbolPrefix = NULL;
    m_Dwarf = NULL;
    m_UseSymbolPrefix = NULL;
    m_labSignalPatterns = NULL;
    m_labAspect = NULL;
    m_labPatternAddr1 = NULL;
    m_labPatternAddr2 = NULL;
    m_labAspectNr = NULL;
    m_labGreen = NULL;
    m_Green1 = NULL;
    m_Green2 = NULL;
    m_GreenNr = NULL;
    m_labRed = NULL;
    m_Red1 = NULL;
    m_Red2 = NULL;
    m_RedNr = NULL;
    m_labYellow = NULL;
    m_Yellow1 = NULL;
    m_Yellow2 = NULL;
    m_YellowNr = NULL;
    m_labWhite = NULL;
    m_White1 = NULL;
    m_White2 = NULL;
    m_WhiteNr = NULL;
    m_labBlank = NULL;
    m_Blank1 = NULL;
    m_Blank2 = NULL;
    m_BlankNr = NULL;
    m_labAspectNames = NULL;
    m_AspectNames = NULL;
    m_Cancel = NULL;
    m_OK = NULL;
    m_Apply = NULL;
////@end SignalDialog member initialisation

////@begin SignalDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end SignalDialog creation
    return true;
}

/*!
 * Control creation for SignalDialog
 */

void SignalDialog::CreateControls()
{
////@begin SignalDialog content construction
    SignalDialog* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    m_Notebook = new wxNotebook( itemDialog1, ID_NOTEBOOK_SG, wxDefaultPosition, wxDefaultSize, m_TabAlign );

    m_IndexPanel = new wxPanel( m_Notebook, ID_PANEL_SG_INDEX, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxVERTICAL);
    m_IndexPanel->SetSizer(itemBoxSizer5);

    m_List2 = new wxListCtrl( m_IndexPanel, ID_LISTCTRLINDEX_SG, wxDefaultPosition, wxSize(100, 100), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES );
    itemBoxSizer5->Add(m_List2, 1, wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer7 = new wxFlexGridSizer(0, 3, 0, 0);
    itemBoxSizer5->Add(itemFlexGridSizer7, 0, wxGROW|wxALL, 5);
    m_New = new wxButton( m_IndexPanel, ID_BUTTON_SG_NEW, _("New"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_New, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Delete = new wxButton( m_IndexPanel, ID_BUTTON_SG_DELETE, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_Delete, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Doc = new wxButton( m_IndexPanel, ID_BUTTON_SG_DOC, _("Doc"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_Doc, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Notebook->AddPage(m_IndexPanel, _("Index"));

    m_GeneralPanel = new wxPanel( m_Notebook, ID_PANEL_SG_GENERAL, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer12 = new wxBoxSizer(wxVERTICAL);
    m_GeneralPanel->SetSizer(itemBoxSizer12);

    wxFlexGridSizer* itemFlexGridSizer13 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer12->Add(itemFlexGridSizer13, 0, wxGROW|wxALL, 5);
    m_LabelID = new wxStaticText( m_GeneralPanel, wxID_STATIC_SG_ID, _("id"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer13->Add(m_LabelID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ID = new wxTextCtrl( m_GeneralPanel, ID_TEXTCTRL_SG_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer13->Add(m_ID, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelDescription = new wxStaticText( m_GeneralPanel, wxID_STATICSG_DESC, _("description"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer13->Add(m_LabelDescription, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Description = new wxTextCtrl( m_GeneralPanel, ID_TEXTCTRL_SG_DESC, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer13->Add(m_Description, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelBlockID = new wxStaticText( m_GeneralPanel, wxID_STATIC_SG_BLOCKID, _("blockid"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer13->Add(m_LabelBlockID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_BlockIDStrings;
    m_BlockID = new wxComboBox( m_GeneralPanel, ID_COMBOBOX_SG_BLOCKID, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_BlockIDStrings, wxCB_READONLY );
    itemFlexGridSizer13->Add(m_BlockID, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labRouteIDs = new wxStaticText( m_GeneralPanel, wxID_ANY, _("Route IDs"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer13->Add(m_labRouteIDs, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_RouteIDs = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer13->Add(m_RouteIDs, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelState = new wxStaticText( m_GeneralPanel, wxID_STATIC_SG_STATE, _("state"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer13->Add(m_LabelState, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_State = new wxTextCtrl( m_GeneralPanel, ID_TEXTCTRL_SG_STATE, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    m_State->Enable(false);
    itemFlexGridSizer13->Add(m_State, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer13->AddGrowableCol(1);

    wxFlexGridSizer* itemFlexGridSizer24 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer12->Add(itemFlexGridSizer24, 0, wxGROW, 5);
    m_Manual = new wxCheckBox( m_GeneralPanel, ID_SIGNAL_MANUAL, _("Manual"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Manual->SetValue(false);
    itemFlexGridSizer24->Add(m_Manual, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ResetManual = new wxCheckBox( m_GeneralPanel, wxID_ANY, _("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ResetManual->SetValue(false);
    itemFlexGridSizer24->Add(m_ResetManual, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Road = new wxCheckBox( m_GeneralPanel, wxID_ANY, _("Road"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Road->SetValue(false);
    itemBoxSizer12->Add(m_Road, 0, wxALIGN_LEFT|wxALL, 5);

    m_Actions = new wxButton( m_GeneralPanel, ID_SIGNAL_ACTIONS, _("Actions..."), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer12->Add(m_Actions, 0, wxALIGN_LEFT|wxALL, 5);

    m_Notebook->AddPage(m_GeneralPanel, _("General"));

    m_LocationPanel = new wxPanel( m_Notebook, ID_PANEL_SG_LOCATION, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer30 = new wxBoxSizer(wxHORIZONTAL);
    m_LocationPanel->SetSizer(itemBoxSizer30);

    wxFlexGridSizer* itemFlexGridSizer31 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer30->Add(itemFlexGridSizer31, 0, wxALIGN_TOP|wxALL, 5);
    m_LabelX = new wxStaticText( m_LocationPanel, wxID_STATIC_SG_X, _("x"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer31->Add(m_LabelX, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_x = new wxTextCtrl( m_LocationPanel, ID_TEXTCTRL_SG_X, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer31->Add(m_x, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelY = new wxStaticText( m_LocationPanel, wxID_STATIC_SG_Y, _("y"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer31->Add(m_LabelY, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_y = new wxTextCtrl( m_LocationPanel, ID_TEXTCTRL_SG_Y, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer31->Add(m_y, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelZ = new wxStaticText( m_LocationPanel, wxID_STATIC_SG_Z, _("z"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer31->Add(m_LabelZ, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_z = new wxTextCtrl( m_LocationPanel, ID_TEXTCTRL_SG_Z, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer31->Add(m_z, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText38 = new wxStaticText( m_LocationPanel, wxID_STATIC_SG_SHOW, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer31->Add(itemStaticText38, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_oriStrings;
    m_oriStrings.Add(_("&north"));
    m_oriStrings.Add(_("&east"));
    m_oriStrings.Add(_("&south"));
    m_oriStrings.Add(_("&west"));
    m_ori = new wxRadioBox( m_LocationPanel, ID_RADIOBOX_SG_ORI, _("Orientation"), wxDefaultPosition, wxDefaultSize, m_oriStrings, 1, wxRA_SPECIFY_COLS );
    m_ori->SetSelection(0);
    itemBoxSizer30->Add(m_ori, 0, wxALIGN_TOP|wxALL, 5);

    m_Notebook->AddPage(m_LocationPanel, _("Location"));

    m_InterfacePanel = new wxPanel( m_Notebook, ID_PANEL_SG_INTERFACE, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer41 = new wxBoxSizer(wxVERTICAL);
    m_InterfacePanel->SetSizer(itemBoxSizer41);

    wxFlexGridSizer* itemFlexGridSizer42 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer41->Add(itemFlexGridSizer42, 0, wxGROW, 5);
    m_Labeliid = new wxStaticText( m_InterfacePanel, wxID_STATIC_SG_IID, _("iid"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer42->Add(m_Labeliid, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxArrayString m_iidStrings;
    m_iid = new wxComboBox( m_InterfacePanel, ID_TEXTCTRL_SG_IID, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_iidStrings, wxCB_DROPDOWN );
    itemFlexGridSizer42->Add(m_iid, 0, wxALIGN_CENTER_HORIZONTAL|wxGROW|wxLEFT|wxRIGHT|wxTOP, 5);

    itemFlexGridSizer42->AddGrowableCol(1);

    wxFlexGridSizer* itemFlexGridSizer45 = new wxFlexGridSizer(0, 4, 0, 0);
    itemBoxSizer41->Add(itemFlexGridSizer45, 0, wxGROW, 5);
    m_Label_Bus = new wxStaticText( m_InterfacePanel, wxID_STATIC_SG_BUS, _("Bus:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer45->Add(m_Label_Bus, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP, 5);

    m_Bus = new wxTextCtrl( m_InterfacePanel, ID_TEXTCTRL_SG_BUS, _("0"), wxDefaultPosition, wxSize(120, -1), wxTE_CENTRE );
    itemFlexGridSizer45->Add(m_Bus, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_labUIDName = new wxStaticText( m_InterfacePanel, wxID_ANY, _("UID-Name"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer45->Add(m_labUIDName, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP, 5);

    m_UIDName = new wxTextCtrl( m_InterfacePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_UIDName->SetMaxLength(60);
    itemFlexGridSizer45->Add(m_UIDName, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    itemFlexGridSizer45->AddGrowableCol(3);

    wxBoxSizer* itemBoxSizer50 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer41->Add(itemBoxSizer50, 0, wxGROW|wxALL, 5);
    wxBoxSizer* itemBoxSizer51 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer50->Add(itemBoxSizer51, 0, wxALIGN_TOP|wxALL, 5);
    m_RedBox = new wxStaticBox(m_InterfacePanel, wxID_ANY, _("Red"));
    wxStaticBoxSizer* itemStaticBoxSizer52 = new wxStaticBoxSizer(m_RedBox, wxHORIZONTAL);
    itemBoxSizer51->Add(itemStaticBoxSizer52, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);
    wxFlexGridSizer* itemFlexGridSizer53 = new wxFlexGridSizer(0, 2, 0, 0);
    itemStaticBoxSizer52->Add(itemFlexGridSizer53, 0, wxALIGN_CENTER_VERTICAL, 5);
    m_labAddress = new wxStaticText( m_InterfacePanel, wxID_ANY, _("address"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer53->Add(m_labAddress, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labPort = new wxStaticText( m_InterfacePanel, wxID_ANY, _("port"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer53->Add(m_labPort, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Address = new wxTextCtrl( m_InterfacePanel, wxID_ANY, _("0"), wxDefaultPosition, wxSize(70, -1), wxTE_CENTRE );
    itemFlexGridSizer53->Add(m_Address, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Port = new wxTextCtrl( m_InterfacePanel, wxID_ANY, _("0"), wxDefaultPosition, wxSize(60, -1), wxTE_CENTRE );
    itemFlexGridSizer53->Add(m_Port, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxArrayString m_Gate1Strings;
    m_Gate1Strings.Add(_("&Red"));
    m_Gate1Strings.Add(_("&Green"));
    m_Gate1 = new wxRadioBox( m_InterfacePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Gate1Strings, 1, wxRA_SPECIFY_ROWS );
    m_Gate1->SetSelection(0);
    itemStaticBoxSizer52->Add(m_Gate1, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_GreenBox = new wxStaticBox(m_InterfacePanel, wxID_ANY, _("Green"));
    wxStaticBoxSizer* itemStaticBoxSizer59 = new wxStaticBoxSizer(m_GreenBox, wxHORIZONTAL);
    itemBoxSizer51->Add(itemStaticBoxSizer59, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);
    m_Address2 = new wxTextCtrl( m_InterfacePanel, wxID_ANY, _("0"), wxDefaultPosition, wxSize(70, -1), wxTE_CENTRE );
    itemStaticBoxSizer59->Add(m_Address2, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Port2 = new wxTextCtrl( m_InterfacePanel, wxID_ANY, _("0"), wxDefaultPosition, wxSize(60, -1), wxTE_CENTRE );
    itemStaticBoxSizer59->Add(m_Port2, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxArrayString m_Gate2Strings;
    m_Gate2Strings.Add(_("&Red"));
    m_Gate2Strings.Add(_("&Green"));
    m_Gate2 = new wxRadioBox( m_InterfacePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Gate2Strings, 1, wxRA_SPECIFY_ROWS );
    m_Gate2->SetSelection(0);
    itemStaticBoxSizer59->Add(m_Gate2, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_YellowBox = new wxStaticBox(m_InterfacePanel, wxID_ANY, _("Yellow"));
    wxStaticBoxSizer* itemStaticBoxSizer63 = new wxStaticBoxSizer(m_YellowBox, wxHORIZONTAL);
    itemBoxSizer51->Add(itemStaticBoxSizer63, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);
    m_Address3 = new wxTextCtrl( m_InterfacePanel, wxID_ANY, _("0"), wxDefaultPosition, wxSize(70, -1), wxTE_CENTRE );
    itemStaticBoxSizer63->Add(m_Address3, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Port3 = new wxTextCtrl( m_InterfacePanel, wxID_ANY, _("0"), wxDefaultPosition, wxSize(60, -1), wxTE_CENTRE );
    itemStaticBoxSizer63->Add(m_Port3, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxArrayString m_Gate3Strings;
    m_Gate3Strings.Add(_("&Red"));
    m_Gate3Strings.Add(_("&Green"));
    m_Gate3 = new wxRadioBox( m_InterfacePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Gate3Strings, 1, wxRA_SPECIFY_ROWS );
    m_Gate3->SetSelection(0);
    itemStaticBoxSizer63->Add(m_Gate3, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_WhiteBox = new wxStaticBox(m_InterfacePanel, wxID_ANY, _("White"));
    wxStaticBoxSizer* itemStaticBoxSizer67 = new wxStaticBoxSizer(m_WhiteBox, wxHORIZONTAL);
    itemBoxSizer51->Add(itemStaticBoxSizer67, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);
    m_Address4 = new wxTextCtrl( m_InterfacePanel, wxID_ANY, _("0"), wxDefaultPosition, wxSize(70, -1), wxTE_CENTRE );
    itemStaticBoxSizer67->Add(m_Address4, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_Port4 = new wxTextCtrl( m_InterfacePanel, wxID_ANY, _("0"), wxDefaultPosition, wxSize(60, -1), wxTE_CENTRE );
    itemStaticBoxSizer67->Add(m_Port4, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxArrayString m_Gate4Strings;
    m_Gate4Strings.Add(_("&Red"));
    m_Gate4Strings.Add(_("&Green"));
    m_Gate4 = new wxRadioBox( m_InterfacePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Gate4Strings, 1, wxRA_SPECIFY_ROWS );
    m_Gate4->SetSelection(0);
    itemStaticBoxSizer67->Add(m_Gate4, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxFlexGridSizer* itemFlexGridSizer71 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer51->Add(itemFlexGridSizer71, 0, wxALIGN_LEFT, 5);
    m_LabelProt = new wxStaticText( m_InterfacePanel, wxID_STATIC_SG_PROT, _("Protocol"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer71->Add(m_LabelProt, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxArrayString m_ProtStrings;
    m_ProtStrings.Add(_("Motorola"));
    m_ProtStrings.Add(_("NMRA-DCC"));
    m_Prot = new wxChoice( m_InterfacePanel, ID_CHOICE_SG_PROT, wxDefaultPosition, wxDefaultSize, m_ProtStrings, 0 );
    m_Prot->SetStringSelection(_("Motorola"));
    itemFlexGridSizer71->Add(m_Prot, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    itemFlexGridSizer71->AddGrowableCol(1);

    wxBoxSizer* itemBoxSizer74 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer50->Add(itemBoxSizer74, 0, wxALIGN_TOP|wxALL, 5);
    wxArrayString m_SignalControlStrings;
    m_SignalControlStrings.Add(_("&default"));
    m_SignalControlStrings.Add(_("&patterns"));
    m_SignalControlStrings.Add(_("&aspect nr"));
    m_SignalControlStrings.Add(_("&linear"));
    m_SignalControlStrings.Add(_("&binary"));
    m_SignalControl = new wxRadioBox( m_InterfacePanel, ID_SIGNALCONTROL, _("Signal control"), wxDefaultPosition, wxDefaultSize, m_SignalControlStrings, 1, wxRA_SPECIFY_COLS );
    m_SignalControl->SetSelection(0);
    itemBoxSizer74->Add(m_SignalControl, 0, wxALIGN_LEFT|wxLEFT, 5);

    m_Accessory = new wxCheckBox( m_InterfacePanel, wxID_ANY, _("Accessory"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Accessory->SetValue(false);
    itemBoxSizer74->Add(m_Accessory, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    wxArrayString m_PortTypeStrings;
    m_PortTypeStrings.Add(_("&Standard"));
    m_PortTypeStrings.Add(_("&Light"));
    m_PortTypeStrings.Add(_("&Servo"));
    m_PortTypeStrings.Add(_("&Sound"));
    m_PortTypeStrings.Add(_("&Motor"));
    m_PortTypeStrings.Add(_("&Analog"));
    m_PortTypeStrings.Add(_("&Macro"));
    m_PortType = new wxRadioBox( m_InterfacePanel, wxID_ANY, _("Type"), wxDefaultPosition, wxDefaultSize, m_PortTypeStrings, 1, wxRA_SPECIFY_COLS );
    m_PortType->SetSelection(0);
    itemBoxSizer74->Add(m_PortType, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    wxFlexGridSizer* itemFlexGridSizer78 = new wxFlexGridSizer(0, 3, 0, 0);
    itemBoxSizer41->Add(itemFlexGridSizer78, 0, wxGROW|wxLEFT|wxRIGHT, 5);
    m_Invert = new wxCheckBox( m_InterfacePanel, wxID_ANY, _("invert"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Invert->SetValue(false);
    itemFlexGridSizer78->Add(m_Invert, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_PairGates = new wxCheckBox( m_InterfacePanel, ID_CHECKBOX_SG_PAIRGATES, _("Pair"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PairGates->SetValue(false);
    itemFlexGridSizer78->Add(m_PairGates, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_AsSwitch = new wxCheckBox( m_InterfacePanel, wxID_ANY, _("Switch"), wxDefaultPosition, wxDefaultSize, 0 );
    m_AsSwitch->SetValue(false);
    itemFlexGridSizer78->Add(m_AsSwitch, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labCmdTime = new wxStaticText( m_InterfacePanel, wxID_ANY, _("Command time"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer78->Add(m_labCmdTime, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_CmdTime = new wxSpinCtrl( m_InterfacePanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 1000, 0 );
    itemFlexGridSizer78->Add(m_CmdTime, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Notebook->AddPage(m_InterfacePanel, _("Interface"));

    m_PropsPanel = new wxPanel( m_Notebook, ID_PANEL_SG_PROPS, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer85 = new wxBoxSizer(wxVERTICAL);
    m_PropsPanel->SetSizer(itemBoxSizer85);

    wxFlexGridSizer* itemFlexGridSizer86 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer85->Add(itemFlexGridSizer86, 0, wxGROW, 5);
    wxArrayString m_TypeStrings;
    m_TypeStrings.Add(_("&semaphore"));
    m_TypeStrings.Add(_("&light"));
    m_Type = new wxRadioBox( m_PropsPanel, ID_RADIOBOX_SG_TYPE, _("Type"), wxDefaultPosition, wxDefaultSize, m_TypeStrings, 1, wxRA_SPECIFY_COLS );
    m_Type->SetSelection(0);
    itemFlexGridSizer86->Add(m_Type, 0, wxALIGN_LEFT|wxALIGN_TOP|wxALL, 5);

    wxArrayString m_SignalStrings;
    m_SignalStrings.Add(_("&distant"));
    m_SignalStrings.Add(_("&main"));
    m_SignalStrings.Add(_("&shunting"));
    m_SignalStrings.Add(_("&blockstate"));
    m_Signal = new wxRadioBox( m_PropsPanel, ID_RADIOBOX_SG_SGTYPE, _("Signal"), wxDefaultPosition, wxDefaultSize, m_SignalStrings, 2, wxRA_SPECIFY_COLS );
    m_Signal->SetSelection(0);
    itemFlexGridSizer86->Add(m_Signal, 0, wxALIGN_LEFT|wxALIGN_TOP|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer89 = new wxFlexGridSizer(0, 2, 0, 0);
    itemFlexGridSizer86->Add(itemFlexGridSizer89, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    m_labAspects = new wxStaticText( m_PropsPanel, wxID_ANY, _("Aspects"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer89->Add(m_labAspects, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Aspects = new wxSpinCtrl( m_PropsPanel, wxID_ANY, wxT("2"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 2, 32, 2 );
    itemFlexGridSizer89->Add(m_Aspects, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labSymbolPrefix = new wxStaticText( m_PropsPanel, wxID_ANY, _("Symbol prefix"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer89->Add(m_labSymbolPrefix, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_SymbolPrefix = new wxTextCtrl( m_PropsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer89->Add(m_SymbolPrefix, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxBoxSizer* itemBoxSizer94 = new wxBoxSizer(wxVERTICAL);
    itemFlexGridSizer86->Add(itemBoxSizer94, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    m_Dwarf = new wxCheckBox( m_PropsPanel, wxID_ANY, _("Dwarf"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Dwarf->SetValue(false);
    itemBoxSizer94->Add(m_Dwarf, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_UseSymbolPrefix = new wxCheckBox( m_PropsPanel, wxID_ANY, _("Use symbol prefix"), wxDefaultPosition, wxDefaultSize, 0 );
    m_UseSymbolPrefix->SetValue(false);
    itemBoxSizer94->Add(m_UseSymbolPrefix, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemFlexGridSizer86->AddGrowableCol(0);
    itemFlexGridSizer86->AddGrowableCol(1);

    wxStaticLine* itemStaticLine97 = new wxStaticLine( m_PropsPanel, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer85->Add(itemStaticLine97, 0, wxGROW|wxALL, 5);

    m_labSignalPatterns = new wxStaticText( m_PropsPanel, wxID_STATIC_SG_PATTERNS, _("Signal Patterns"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
    itemBoxSizer85->Add(m_labSignalPatterns, 0, wxGROW|wxLEFT|wxRIGHT, 5);

    wxFlexGridSizer* itemFlexGridSizer99 = new wxFlexGridSizer(0, 4, 0, 0);
    itemBoxSizer85->Add(itemFlexGridSizer99, 0, wxGROW|wxALL, 5);
    m_labAspect = new wxStaticText( m_PropsPanel, wxID_ANY, _("Aspect:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer99->Add(m_labAspect, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labPatternAddr1 = new wxStaticText( m_PropsPanel, wxID_ANY, _("Red address gate:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer99->Add(m_labPatternAddr1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labPatternAddr2 = new wxStaticText( m_PropsPanel, wxID_ANY, _("Yellow address gate:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer99->Add(m_labPatternAddr2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labAspectNr = new wxStaticText( m_PropsPanel, wxID_ANY, _("Nr."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer99->Add(m_labAspectNr, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labGreen = new wxStaticText( m_PropsPanel, ID_STATICTEXT_SG_GREEN, _("Green"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer99->Add(m_labGreen, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_Green1Strings;
    m_Green1Strings.Add(_("&R1"));
    m_Green1Strings.Add(_("&G1"));
    m_Green1Strings.Add(_("&N"));
    m_Green1 = new wxRadioBox( m_PropsPanel, ID_RADIOBOX_SG_GREEN1, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Green1Strings, 1, wxRA_SPECIFY_ROWS );
    m_Green1->SetSelection(0);
    itemFlexGridSizer99->Add(m_Green1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxArrayString m_Green2Strings;
    m_Green2Strings.Add(_("&R2"));
    m_Green2Strings.Add(_("&G2"));
    m_Green2Strings.Add(_("&N"));
    m_Green2 = new wxRadioBox( m_PropsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Green2Strings, 1, wxRA_SPECIFY_ROWS );
    m_Green2->SetSelection(0);
    itemFlexGridSizer99->Add(m_Green2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_GreenNr = new wxSpinCtrl( m_PropsPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(60, -1), wxSP_ARROW_KEYS, 0, 31, 0 );
    itemFlexGridSizer99->Add(m_GreenNr, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labRed = new wxStaticText( m_PropsPanel, ID_STATICTEXT_SG_RED, _("Red"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer99->Add(m_labRed, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_Red1Strings;
    m_Red1Strings.Add(_("&R1"));
    m_Red1Strings.Add(_("&G1"));
    m_Red1Strings.Add(_("&N"));
    m_Red1 = new wxRadioBox( m_PropsPanel, ID_RADIOBOX_SG_RED1, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Red1Strings, 1, wxRA_SPECIFY_ROWS );
    m_Red1->SetSelection(0);
    itemFlexGridSizer99->Add(m_Red1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxArrayString m_Red2Strings;
    m_Red2Strings.Add(_("&R2"));
    m_Red2Strings.Add(_("&G2"));
    m_Red2Strings.Add(_("&N"));
    m_Red2 = new wxRadioBox( m_PropsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Red2Strings, 1, wxRA_SPECIFY_ROWS );
    m_Red2->SetSelection(0);
    itemFlexGridSizer99->Add(m_Red2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_RedNr = new wxSpinCtrl( m_PropsPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(60, -1), wxSP_ARROW_KEYS, 0, 31, 0 );
    itemFlexGridSizer99->Add(m_RedNr, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labYellow = new wxStaticText( m_PropsPanel, ID_STATICTEXT_SG_YELLOW, _("Yellow"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer99->Add(m_labYellow, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_Yellow1Strings;
    m_Yellow1Strings.Add(_("&R1"));
    m_Yellow1Strings.Add(_("&G1"));
    m_Yellow1Strings.Add(_("&N"));
    m_Yellow1 = new wxRadioBox( m_PropsPanel, ID_RADIOBOX_SG_YELLOW1, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Yellow1Strings, 1, wxRA_SPECIFY_ROWS );
    m_Yellow1->SetSelection(0);
    itemFlexGridSizer99->Add(m_Yellow1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxArrayString m_Yellow2Strings;
    m_Yellow2Strings.Add(_("&R2"));
    m_Yellow2Strings.Add(_("&G2"));
    m_Yellow2Strings.Add(_("&N"));
    m_Yellow2 = new wxRadioBox( m_PropsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Yellow2Strings, 1, wxRA_SPECIFY_ROWS );
    m_Yellow2->SetSelection(0);
    itemFlexGridSizer99->Add(m_Yellow2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_YellowNr = new wxSpinCtrl( m_PropsPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(60, -1), wxSP_ARROW_KEYS, 0, 31, 0 );
    itemFlexGridSizer99->Add(m_YellowNr, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labWhite = new wxStaticText( m_PropsPanel, ID_STATICTEXT_SG_WHITE, _("White"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer99->Add(m_labWhite, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_White1Strings;
    m_White1Strings.Add(_("&R1"));
    m_White1Strings.Add(_("&G1"));
    m_White1Strings.Add(_("&N"));
    m_White1 = new wxRadioBox( m_PropsPanel, ID_RADIOBOX_SG_WHITE1, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_White1Strings, 1, wxRA_SPECIFY_ROWS );
    m_White1->SetSelection(0);
    itemFlexGridSizer99->Add(m_White1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxArrayString m_White2Strings;
    m_White2Strings.Add(_("&R2"));
    m_White2Strings.Add(_("&G2"));
    m_White2Strings.Add(_("&N"));
    m_White2 = new wxRadioBox( m_PropsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_White2Strings, 1, wxRA_SPECIFY_ROWS );
    m_White2->SetSelection(0);
    itemFlexGridSizer99->Add(m_White2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_WhiteNr = new wxSpinCtrl( m_PropsPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(60, -1), wxSP_ARROW_KEYS, 0, 31, 0 );
    itemFlexGridSizer99->Add(m_WhiteNr, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labBlank = new wxStaticText( m_PropsPanel, wxID_ANY, _("Blank"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer99->Add(m_labBlank, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_Blank1Strings;
    m_Blank1Strings.Add(_("&R1"));
    m_Blank1Strings.Add(_("&G1"));
    m_Blank1Strings.Add(_("&N"));
    m_Blank1 = new wxRadioBox( m_PropsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Blank1Strings, 1, wxRA_SPECIFY_ROWS );
    m_Blank1->SetSelection(0);
    itemFlexGridSizer99->Add(m_Blank1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxArrayString m_Blank2Strings;
    m_Blank2Strings.Add(_("&R1"));
    m_Blank2Strings.Add(_("&G1"));
    m_Blank2Strings.Add(_("&N"));
    m_Blank2 = new wxRadioBox( m_PropsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Blank2Strings, 1, wxRA_SPECIFY_ROWS );
    m_Blank2->SetSelection(0);
    itemFlexGridSizer99->Add(m_Blank2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_BlankNr = new wxSpinCtrl( m_PropsPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(60, -1), wxSP_ARROW_KEYS, 0, 31, 0 );
    itemFlexGridSizer99->Add(m_BlankNr, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer124 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer85->Add(itemFlexGridSizer124, 0, wxGROW, 5);
    m_labAspectNames = new wxStaticText( m_PropsPanel, wxID_ANY, _("Aspect names"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer124->Add(m_labAspectNames, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_AspectNames = new wxTextCtrl( m_PropsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer124->Add(m_AspectNames, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer124->AddGrowableCol(1);

    m_Notebook->AddPage(m_PropsPanel, _("Properties"));

    itemBoxSizer2->Add(m_Notebook, 1, wxGROW|wxALL, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer127 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer127, 0, wxGROW|wxALL, 5);
    m_Cancel = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer127->AddButton(m_Cancel);

    m_OK = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    m_OK->SetDefault();
    itemStdDialogButtonSizer127->AddButton(m_OK);

    m_Apply = new wxButton( itemDialog1, wxID_APPLY, _("&Apply"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer127->AddButton(m_Apply);

    wxButton* itemButton131 = new wxButton( itemDialog1, wxID_HELP, _("&Help"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer127->AddButton(itemButton131);

    itemStdDialogButtonSizer127->Realize();

////@end SignalDialog content construction
}

/*!
 * Should we show tooltips?
 */

bool SignalDialog::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap SignalDialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin SignalDialog bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end SignalDialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon SignalDialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin SignalDialog icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end SignalDialog icon retrieval
}
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_SW_NEW
 */

void SignalDialog::OnButtonSgNewClick( wxCommandEvent& event )
{
  int i = findID("NEW");
  if( i == wxNOT_FOUND ) {
    iONode model = wxGetApp().getModel();
    if( model != NULL ) {
      iONode sglist = wPlan.getsglist( model );
      if( sglist == NULL ) {
        sglist = NodeOp.inst( wSignalList.name(), model, ELEMENT_NODE );
        NodeOp.addChild( model, sglist );
      }
      if( sglist != NULL ) {
        iONode sg = NodeOp.inst( wSignal.name(), sglist, ELEMENT_NODE );
        NodeOp.addChild( sglist, sg );
        wSignal.setid( sg, "NEW" );
        appendItem(sg);
        setIDSelection(wItem.getid(sg));
        m_Props = sg;
        initValues();
      }
    }
  }
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_SW_DELETE
 */

void SignalDialog::OnButtonSgDeleteClick( wxCommandEvent& event )
{
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
    iONode sglist = wPlan.getsglist( model );
    if( sglist != NULL ) {
      NodeOp.removeChild( sglist, m_Props );
      m_Props = selectPrev();
    }
  }

  initIndex();
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void SignalDialog::OnCancelClick( wxCommandEvent& event )
{
  EndModal( 0 );
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void SignalDialog::OnOkClick( wxCommandEvent& event )
{
  OnApplyClick(event);
  EndModal( wxID_OK );
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_APPLY
 */

void SignalDialog::OnApplyClick( wxCommandEvent& event )
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
  else {
    wxGetApp().setLocalModelModified(true);
  }
  initIndex();
}



/*!
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKBOX_SG_PAIRGATES
 */

void SignalDialog::OnCheckboxSgPairgatesClick( wxCommandEvent& event )
{
  bool enable = m_PairGates->IsChecked();
  m_Gate1->Enable(!enable);
  m_Gate2->Enable(!enable);
  m_Gate3->Enable(!enable);
  m_Gate4->Enable(!enable);
}




/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SIGNAL_ACTIONS
 */

void SignalDialog::OnSignalActionsClick( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  ActionsCtrlDlg*  dlg = new ActionsCtrlDlg(this, m_Props, "red,yellow,green,white,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15" );

  if( wxID_OK == dlg->ShowModal() ) {
    // TODO: inform
  }

  dlg->Destroy();
}

void SignalDialog::OnButtonSgDocClick( wxCommandEvent& event )
{
  doDoc( event, "signals");
}


/*!
 * wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_SIGNALCONTROL
 */

void SignalDialog::OnSignalcontrolSelected( wxCommandEvent& event )
{
  int ctrl = m_SignalControl->GetSelection();
  TraceOp.trc( "signaldlg", TRCLEVEL_INFO, __LINE__, 9999, "Signal control = %d", ctrl );
  bool patterns = false;
  bool aspectnrs = false;
  if( ctrl == 0 ) {

  }
  else if( ctrl == 1 ) {
    /* patterns */
    patterns = true;
    aspectnrs = false;
  }
  else if( ctrl == 2 ) {
    /* Aspect numbers */
    patterns = true;
    aspectnrs = true;
  }
  else if( ctrl == 3 ) {
    /* Linear */
    patterns = true;
    aspectnrs = true;
  }
  else if( ctrl == 4 ) {
    /* binary */
    patterns = false;
    aspectnrs = false;
  }

  m_Gate1->Enable(!patterns);
  m_Gate2->Enable(!patterns);
  m_Gate3->Enable(!patterns);
  m_Gate4->Enable(!patterns);
  if( !patterns )
    OnCheckboxSgPairgatesClick(event);

  m_Address2->Enable(!aspectnrs);
  m_Port2->Enable(!aspectnrs);
  m_Address3->Enable(!patterns);
  m_Port3->Enable(!patterns);
  m_Address4->Enable(!patterns);
  m_Port4->Enable(!patterns);
  m_PairGates->Enable(!patterns);
}


/*!
 * wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ID_LISTCTRLINDEX_SG
 */

void SignalDialog::OnListctrlindexSgSelected( wxListEvent& event )
{
  m_Props = getSelection(event.GetIndex());
  initValues();
  m_Delete->Enable( true );
}


/*!
 * wxEVT_COMMAND_LIST_COL_CLICK event handler for ID_LISTCTRLINDEX_SG
 */

void SignalDialog::OnListctrlindexSgColLeftClick( wxListEvent& event )
{
  sortOnColumn(event.GetColumn());
}


/*!
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for wxID_ANY
 */

void SignalDialog::onAccessory( wxCommandEvent& event )
{
  m_PortType->SetSelection(0);
  m_PortType->Enable(!m_Accessory->IsChecked());
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
 */

void SignalDialog::OnHelpClick( wxCommandEvent& event )
{
  switch( m_Notebook->GetSelection() ) {
  case 0: wxGetApp().openLink( "signal" ); break;
  case 1: wxGetApp().openLink( "signal-gen" ); break;
  case 2: wxGetApp().openLink( "signal" ); break;
  case 3: wxGetApp().openLink( "signal-int" ); break;
  case 4: wxGetApp().openLink( "signal-props" ); break;
  default: wxGetApp().openLink( "signal" ); break;
  }
}


/*!
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_SIGNAL_MANUAL
 */

void SignalDialog::OnSignalManualClick( wxCommandEvent& event )
{
  m_ResetManual->Enable(m_Manual->IsChecked());
}

