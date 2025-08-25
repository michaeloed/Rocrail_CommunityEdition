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
#pragma implementation "turntabledialog.h"
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

#include "turntabledialog.h"
#include "actionsctrldlg.h"
#include "basedlg.h"

////@begin XPM images
////@end XPM images

#include "rocrail/wrapper/public/Turntable.h"
#include "rocrail/wrapper/public/TTTrack.h"
#include "rocrail/wrapper/public/Item.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Plan.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocview/public/guiapp.h"
#include "rocview/dialogs/tttrackdialog.h"

/*!
 * TurntableDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( TurntableDialog, wxDialog )

/*!
 * TurntableDialog event table definition
 */

enum {
    // menu items
    ME_Props = 1,
    ME_TTTrackAdd,
    ME_TTTrackDelete,
};

BEGIN_EVENT_TABLE( TurntableDialog, wxDialog )

////@begin TurntableDialog event table entries
    EVT_CHECKBOX( ID_TT_MANAGER, TurntableDialog::OnManagerClick )
    EVT_BUTTON( ID_TT_ACTIONS, TurntableDialog::OnTtActionsClick )
    EVT_COMBOBOX( ID_COMBOBOX_TT_TYPE, TurntableDialog::OnTypeSelected )
    EVT_GRID_CELL_LEFT_CLICK( TurntableDialog::OnCellLeftClick )
    EVT_GRID_CELL_RIGHT_CLICK( TurntableDialog::OnCellRightClick )
    EVT_BUTTON( ID_BUTTON_TT_ADDTRACK, TurntableDialog::OnButtonTtAddtrackClick )
    EVT_BUTTON( ID_BUTTON_TT_DELTRACK, TurntableDialog::OnButtonTtDeltrackClick )
    EVT_BUTTON( ID_BUTTON_TT_MODIFYTRACK, TurntableDialog::OnButtonTtModifytrackClick )
    EVT_BUTTON( wxID_OK, TurntableDialog::OnOkClick )
    EVT_BUTTON( wxID_CANCEL, TurntableDialog::OnCancelClick )
    EVT_BUTTON( wxID_HELP, TurntableDialog::OnHelpClick )
////@end TurntableDialog event table entries
    EVT_MENU(ME_Props, TurntableDialog::OnProps)
    EVT_MENU(ME_TTTrackAdd, TurntableDialog::OnTTTrackAdd)
    EVT_MENU(ME_TTTrackDelete, TurntableDialog::OnTTTrackDelete)

END_EVENT_TABLE()

/*!
 * TurntableDialog constructors
 */

TurntableDialog::TurntableDialog( )
{
}

TurntableDialog::TurntableDialog( wxWindow* parent, iONode p_Props )
{
  m_TabAlign = wxGetApp().getTabAlign();
  Create(parent, -1, wxGetApp().getMsg("turntable") );

  wxFont* font = new wxFont( m_TracksGrid->GetDefaultCellFont() );
  font->SetPointSize( (int)(font->GetPointSize() - 1 ) );
  m_TracksGrid->SetDefaultCellFont( *font );
  m_TracksGrid->SetColLabelValue(0, wxGetApp().getMsg("track") );
  m_TracksGrid->SetColLabelValue(1, wxGetApp().getMsg("posfb") );
  m_TracksGrid->SetColLabelValue(2, wxGetApp().getMsg("description") );
  m_TracksGrid->SetColLabelValue(3, wxGetApp().getMsg("decoder") + _T(" ") + wxGetApp().getMsg("track") );
  m_TracksGrid->SetColLabelValue(4, wxGetApp().getMsg("opposite") + _T(" ") + wxGetApp().getMsg("track") );
  m_TracksGrid->SetColLabelValue(5, wxGetApp().getMsg("blockid") );
  m_TracksGrid->AutoSizeColumns();
  m_TracksGrid->AutoSizeRows();

  m_Props = p_Props;
  initLabels();
  if( m_Props != NULL ) {
    initValues();
    //m_Notebook->SetSelection( 1 );
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ID_PANEL_TT_GENERAL );
    wxPostEvent( this, event );
  }

  m_GeneralPanel->GetSizer()->Layout();
  m_LocationPanel->GetSizer()->Layout();
  m_Interface->GetSizer()->Layout();
  m_TracksPanel->GetSizer()->Layout();
  m_Notebook->Fit();
  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);
}

TurntableDialog::TurntableDialog( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, caption, pos, size, style);
}

void TurntableDialog::OnProps(wxCommandEvent& event) {
  int tracknr = atoi( m_TrackNr );
  TraceOp.trc( "ttdlg", TRCLEVEL_INFO, __LINE__, 9999, "Props for track %d (type=%s)",
      tracknr, (const char*)m_Type->GetStringSelection().mb_str(wxConvUTF8) );

  iONode track = wTurntable.gettrack( m_Props );
  while( track != NULL ) {
    if( tracknr == wTTTrack.getnr( track ) )
      break;
    track = wTurntable.nexttrack( m_Props, track );
  }

  if( track != NULL ) {
    int min = 0;
    int max = 47;
    if( StrOp.equals( wTurntable.f6915, m_Type->GetStringSelection().mb_str(wxConvUTF8) ) ) {
      min = 0;
      max = 511;
    }
    TTTrackDialog* dlg = new TTTrackDialog( this, track, min, max );
    if( wxID_OK == dlg->ShowModal() ) {
      initValues();
    }
  }
}


void TurntableDialog::OnTTTrackAdd(wxCommandEvent& event) {
  TraceOp.trc( "ttdlg", TRCLEVEL_INFO, __LINE__, 9999, "New for track" );

  iONode track = NodeOp.inst( wTTTrack.name(), NULL, ELEMENT_NODE );

  int min = 0;
  int max = 47;
  if( StrOp.equals( wTurntable.f6915, m_Type->GetStringSelection().mb_str(wxConvUTF8) ) ) {
    min = 0;
    max = 511;
  }
  TTTrackDialog* dlg = new TTTrackDialog( this, track, min, max );
  if( wxID_OK == dlg->ShowModal() ) {
    NodeOp.addChild( m_Props, track );
    initValues();
  }
  else
    NodeOp.base.del( track );
}



void TurntableDialog::OnTTTrackDelete(wxCommandEvent& event) {
  int tracknr = atoi( m_TrackNr );
  TraceOp.trc( "ttdlg", TRCLEVEL_INFO, __LINE__, 9999, "Props for track %d", tracknr );

  iONode track = wTurntable.gettrack( m_Props );
  while( track != NULL ) {
    if( tracknr == wTTTrack.getnr( track ) )
      break;
    track = wTurntable.nexttrack( m_Props, track );
  }

  if( track != NULL ) {
    NodeOp.removeChild( m_Props, track );
    NodeOp.base.del( track );
    initValues();
  }
}


/* comparator for sorting by id: */
static int __sortStr(obj* _a, obj* _b)
{
    const char* a = (const char*)*_a;
    const char* b = (const char*)*_b;
    return strcmp( a, b );
}

void TurntableDialog::initLabels() {
  m_Notebook->SetPageText( 0, wxGetApp().getMsg( "general" ) );
  m_Notebook->SetPageText( 1, wxGetApp().getMsg( "position" ) );
  m_Notebook->SetPageText( 2, wxGetApp().getMsg( "interface" ) );
  m_Notebook->SetPageText( 3, wxGetApp().getMsg( "multiport" ) );
  m_Notebook->SetPageText( 4, wxGetApp().getMsg( "tracks" ) );

  // General
  m_LabelID->SetLabel( wxGetApp().getMsg( "id" ) );
  m_LabelDesc->SetLabel( wxGetApp().getMsg( "description" ) );
  m_Manager->SetLabel( wxGetApp().getMsg( "managetrackblocks" ) );
  m_EmbeddedBlock->SetLabel( wxGetApp().getMsg( "embeddedblock" ) );
  m_Traverser->SetLabel( wxGetApp().getMsg( "traverser" ) );
  //m_Manager->Enable(false);
  m_Actions->SetLabel( wxGetApp().getMsg( "actions" )+_T("...") );
  m_Move4Opp->SetLabel( wxGetApp().getMsg( "move4opp" ) );
  m_labRandomRate->SetLabel( wxGetApp().getMsg( "randomrate" ) );

  // Location
  m_LabelX->SetLabel( wxGetApp().getMsg( "x" ) );
  m_LabelY->SetLabel( wxGetApp().getMsg( "y" ) );
  m_LabelZ->SetLabel( wxGetApp().getMsg( "z" ) );
  m_labSize->SetLabel( wxGetApp().getMsg( "size" ) );

  // Interface
  BaseDialog::addIIDs(m_IID);

  m_Labeliid->SetLabel( wxGetApp().getMsg( "iid" ) );
  m_Label_Bus->SetLabel( wxGetApp().getMsg( "bus" ) );
  m_labUIDName->SetLabel(wxGetApp().getMsg( "uidname" ));
  m_LabelAddress->SetLabel( wxGetApp().getMsg( "address" ) );
  m_labPolAddr->SetLabel( wxGetApp().getMsg( "poladdr" ) );
  m_LabelType->SetLabel( wxGetApp().getMsg( "type" ) );
  m_labV->SetLabel( wxGetApp().getMsg( "rotationvelocity" ) );
  m_labBridgeSensor1->SetLabel( wxGetApp().getMsg( "sensor" ) + _T(" 1") );
  m_labBridgeSensor2->SetLabel( wxGetApp().getMsg( "sensor" ) + _T(" 2") );
  m_labBridgeSensorMid->SetLabel( wxGetApp().getMsg( "sensor" ) + _T(" 3") );
  m_labBridgeSensorMid2->SetLabel( wxGetApp().getMsg( "sensor" ) + _T(" 4") );
  m_labPSen->SetLabel( wxGetApp().getMsg( "position" ) +_T(" ") + wxGetApp().getMsg( "sensor" ) );
  m_labActFn->SetLabel( wxGetApp().getMsg( "function" ) );
  m_labLightsFn->SetLabel( wxGetApp().getMsg( "lights" ) );
  m_labMotorOffDelay->SetLabel( wxGetApp().getMsg( "motoroffdelay" ) );
  m_Inv->SetLabel( wxGetApp().getMsg( "invert" ) );

  m_Type->Append( wxString(wTurntable.locdec,wxConvUTF8 ) );
  m_Type->Append( wxString(wTurntable.digitalbahn,wxConvUTF8 ) );
  m_Type->Append( wxString(wTurntable.multiport,wxConvUTF8 ) );
  m_Type->Append( wxString(wTurntable.f6915,wxConvUTF8 ) );
  m_Type->Append( wxString(wTurntable.accdec,wxConvUTF8 ) );
  m_Type->Append( wxString(wTurntable.muet,wxConvUTF8 ) );
  m_Type->Append( wxString(wTurntable.slx815,wxConvUTF8 ) );
  m_Type->Append( wxString(wTurntable.ttdec,wxConvUTF8 ) );
  m_Type->Append( wxString(wTurntable.d15,wxConvUTF8 ) );
  m_Type->Append( wxString(wTurntable.dsm,wxConvUTF8 ) );
  m_labProt->SetLabel( wxGetApp().getMsg( "protocol" ) );
  m_labDelay->SetLabel( wxGetApp().getMsg( "delay" ) );
  m_labPause->SetLabel( wxGetApp().getMsg( "ttdirpause" ) );
  m_SwapRotation->SetLabel( wxGetApp().getMsg( "swaprotationdirection" ) );

  m_Prot->Clear();
  m_Prot->Append(_T("Default"));
  m_Prot->Append(_T("Motorola"));
  m_Prot->Append(_T("NMRA-DCC"));

  // multiport
  m_labAddr0->SetLabel( wxGetApp().getMsg( "address" ) + _T(" 0") );
  m_labAddr1->SetLabel( wxGetApp().getMsg( "address" ) + _T(" 1") );
  m_labAddr2->SetLabel( wxGetApp().getMsg( "address" ) + _T(" 2") );
  m_labAddr3->SetLabel( wxGetApp().getMsg( "address" ) + _T(" 3") );
  m_labAddr4->SetLabel( wxGetApp().getMsg( "address" ) + _T(" 4") );
  m_labAddr6->SetLabel( wxGetApp().getMsg( "address" ) + _T(" 5") );
  m_labAddr5->SetLabel( wxGetApp().getMsg( "address" ) );
  m_labResetAddr->SetLabel( wxGetApp().getMsg( "address" ) );
  m_labPort0->SetLabel( wxGetApp().getMsg( "port" ) );
  m_labPort1->SetLabel( wxGetApp().getMsg( "port" ) );
  m_labPort2->SetLabel( wxGetApp().getMsg( "port" ) );
  m_labPort3->SetLabel( wxGetApp().getMsg( "port" ) );
  m_labPort4->SetLabel( wxGetApp().getMsg( "port" ) );
  m_labPort5->SetLabel( wxGetApp().getMsg( "port" ) );
  m_labPort6->SetLabel( wxGetApp().getMsg( "port" ) );
  m_labResetPort->SetLabel( wxGetApp().getMsg( "port" ) );
  m_InvertPos->SetLabel( wxGetApp().getMsg( "invert" ) );
  m_InvertNew->SetLabel( wxGetApp().getMsg( "invert" ) );
  m_SingleGatePos->SetLabel( wxGetApp().getMsg( "singlegate" ) );
  m_SingleGateNew->SetLabel( wxGetApp().getMsg( "singlegate" ) );

  m_Bit0Cmd->SetString( 0, wxGetApp().getMsg( "red" ) );
  m_Bit0Cmd->SetString( 1, wxGetApp().getMsg( "green" ) );
  m_Bit1Cmd->SetString( 0, wxGetApp().getMsg( "red" ) );
  m_Bit1Cmd->SetString( 1, wxGetApp().getMsg( "green" ) );
  m_Bit2Cmd->SetString( 0, wxGetApp().getMsg( "red" ) );
  m_Bit2Cmd->SetString( 1, wxGetApp().getMsg( "green" ) );
  m_Bit3Cmd->SetString( 0, wxGetApp().getMsg( "red" ) );
  m_Bit3Cmd->SetString( 1, wxGetApp().getMsg( "green" ) );
  m_Bit4Cmd->SetString( 0, wxGetApp().getMsg( "red" ) );
  m_Bit4Cmd->SetString( 1, wxGetApp().getMsg( "green" ) );
  m_Bit5Cmd->SetString( 0, wxGetApp().getMsg( "red" ) );
  m_Bit5Cmd->SetString( 1, wxGetApp().getMsg( "green" ) );
  m_ResetCmd->SetString( 0, wxGetApp().getMsg( "red" ) );
  m_ResetCmd->SetString( 1, wxGetApp().getMsg( "green" ) );


  // Buttons
  m_DelTrack->SetLabel( wxGetApp().getMsg( "delete" ) );
  m_ModifyTrack->SetLabel( wxGetApp().getMsg( "edit" ) );
  m_AddTrack->SetLabel( wxGetApp().getMsg( "add" ) );

  m_OK->SetLabel( wxGetApp().getMsg( "ok" ) );
  m_Cancel->SetLabel( wxGetApp().getMsg( "cancel" ) );


  m_BridgeSensor1->Clear();
  m_BridgeSensor1->Append( wxString("-",wxConvUTF8) );
  m_BridgeSensor2->Clear();
  m_BridgeSensor2->Append( wxString("-",wxConvUTF8) );
  m_BridgeSensorMid->Clear();
  m_BridgeSensorMid->Append( wxString("-",wxConvUTF8) );
  m_BridgeSensorMid2->Clear();
  m_BridgeSensorMid2->Append( wxString("-",wxConvUTF8) );
  m_PSen->Clear();
  m_PSen->Append( wxString("-",wxConvUTF8) );

  iONode model = wxGetApp().getModel();
  iOList list = ListOp.inst();
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
      ListOp.sort(list, &__sortStr);
      cnt = ListOp.size( list );
      for( int i = 0; i < cnt; i++ ) {
        const char* id = (const char*)ListOp.get( list, i );
        m_BridgeSensor1->Append( wxString(id,wxConvUTF8) );
        m_BridgeSensor2->Append( wxString(id,wxConvUTF8) );
        m_BridgeSensorMid->Append( wxString(id,wxConvUTF8) );
        m_BridgeSensorMid2->Append( wxString(id,wxConvUTF8) );
        m_PSen->Append( wxString(id,wxConvUTF8) );
      }
    }
  }
  /* clean up the temp. list */
  ListOp.base.del(list);

}


void TurntableDialog::initValues() {
  m_TrackNr = NULL;
  // General
  m_ID->SetValue( wxString( wTurntable.getid( m_Props ),wxConvUTF8 ) );
  m_Desc->SetValue( wxString(wTurntable.getdesc( m_Props ),wxConvUTF8 ) );
  m_Manager->SetValue(wTurntable.ismanager( m_Props ));
  m_EmbeddedBlock->SetValue(wTurntable.isembeddedblock( m_Props ));
  m_Traverser->SetValue(wTurntable.istraverser( m_Props ));
  m_Move4Opp->SetValue(wTurntable.ismove4opp( m_Props ));
  m_RandomRate->SetValue( wTurntable.getrandomrate( m_Props ) );

  wxCommandEvent dummyEvent(0, 0);
  OnManagerClick(dummyEvent);

  // Location
  char* str = StrOp.fmt( "%d", wTurntable.getx( m_Props ) );
  m_x->SetValue( wxString(str,wxConvUTF8 ) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wTurntable.gety( m_Props ) );
  m_y->SetValue( wxString(str,wxConvUTF8 ) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wTurntable.getz( m_Props ) );
  m_z->SetValue( wxString(str,wxConvUTF8 ) ); StrOp.free( str );
  m_Size->SetValue( wTurntable.getsymbolsize( m_Props ) );

  // Interface
  m_IID->SetValue( wxString(wTurntable.getiid( m_Props ),wxConvUTF8 ) );
  str = StrOp.fmt( "%d", wTurntable.getbus( m_Props ) );
  m_Bus->SetValue( wxString(str,wxConvUTF8 ) );
  StrOp.free( str );
  m_UIDName->SetValue( wxString(wItem.getuidname( m_Props ),wxConvUTF8) );

  str = StrOp.fmt( "%d", wTurntable.getaddr( m_Props ) );
  m_Address->SetValue( wxString(str,wxConvUTF8 ) );
  StrOp.free( str );
  str = StrOp.fmt( "%d", wTurntable.getdiraddr( m_Props ) );
  m_AddressDir->SetValue( wxString(str,wxConvUTF8 ) );
  StrOp.free( str );

  str = StrOp.fmt( "%d", wTurntable.getpoladdr( m_Props ) );
  m_PolAddr->SetValue( wxString(str,wxConvUTF8 ) );
  StrOp.free( str );
  m_Type->SetStringSelection( wxString(wTurntable.gettype( m_Props ),wxConvUTF8 ) );
  m_V->SetValue(wTurntable.getV( m_Props ));
  m_Delay->SetValue(wTurntable.getdelay( m_Props ));
  m_Pause->SetValue(wTurntable.getpause( m_Props ));
  m_ActFn->SetValue( wTurntable.getactfn( m_Props ) );
  m_LightsFn->SetValue( wTurntable.getlightsfn( m_Props ) );
  m_MotorOffDelay->SetValue(wTurntable.getmotoroffdelay( m_Props ));
  m_Inv->SetValue(wTurntable.isinv( m_Props )?true:false);

  if( StrOp.equals( wTurntable.prot_DEF, wTurntable.getprot( m_Props ) ) )
    m_Prot->SetSelection( 0 );
  else if( StrOp.equals( wTurntable.prot_M, wTurntable.getprot( m_Props ) ) )
    m_Prot->SetSelection( 1 );
  else if( StrOp.equals( wTurntable.prot_N, wTurntable.getprot( m_Props ) ) )
    m_Prot->SetSelection( 2 );

  m_BridgeSensor1->SetSelection(0);
  m_BridgeSensor2->SetSelection(0);
  m_BridgeSensorMid->SetSelection(0);
  m_BridgeSensorMid2->SetSelection(0);
  m_PSen->SetSelection(0);
  if( wTurntable.gets1( m_Props ) != NULL && StrOp.len( wTurntable.gets1( m_Props ) ) > 0 )
    m_BridgeSensor1->SetStringSelection( wxString(wTurntable.gets1(m_Props),wxConvUTF8) );
  if( wTurntable.gets2( m_Props ) != NULL && StrOp.len( wTurntable.gets2( m_Props ) ) > 0 )
    m_BridgeSensor2->SetStringSelection( wxString(wTurntable.gets2(m_Props),wxConvUTF8) );
  if( wTurntable.getsMid( m_Props ) != NULL && StrOp.len( wTurntable.getsMid( m_Props ) ) > 0 )
    m_BridgeSensorMid->SetStringSelection( wxString(wTurntable.getsMid(m_Props),wxConvUTF8) );
  if( wTurntable.getsMid2( m_Props ) != NULL && StrOp.len( wTurntable.getsMid2( m_Props ) ) > 0 )
    m_BridgeSensorMid2->SetStringSelection( wxString(wTurntable.getsMid2(m_Props),wxConvUTF8) );
  if( wTurntable.getpsen( m_Props ) != NULL && StrOp.len( wTurntable.getpsen( m_Props ) ) > 0 )
    m_PSen->SetStringSelection( wxString(wTurntable.getpsen(m_Props),wxConvUTF8) );

  m_SwapRotation->SetValue( wTurntable.isswaprotation( m_Props )?true:false );

  // multiport
  str = StrOp.fmt( "%d", wTurntable.getaddr0( m_Props ) );
  m_Addr0->SetValue( wxString(str,wxConvUTF8 ) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wTurntable.getaddr1( m_Props ) );
  m_Addr1->SetValue( wxString(str,wxConvUTF8 ) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wTurntable.getaddr2( m_Props ) );
  m_Addr2->SetValue( wxString(str,wxConvUTF8 ) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wTurntable.getaddr3( m_Props ) );
  m_Addr3->SetValue( wxString(str,wxConvUTF8 ) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wTurntable.getaddr4( m_Props ) );
  m_Addr4->SetValue( wxString(str,wxConvUTF8 ) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wTurntable.getaddr5( m_Props ) );
  m_Addr5->SetValue( wxString(str,wxConvUTF8 ) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wTurntable.getaddr6( m_Props ) );
  m_Addr6->SetValue( wxString(str,wxConvUTF8 ) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wTurntable.getresetaddr( m_Props ) );
  m_ResetAddr->SetValue( wxString(str,wxConvUTF8 ) ); StrOp.free( str );

  str = StrOp.fmt( "%d", wTurntable.getport0( m_Props ) );
  m_Port0->SetValue( wxString(str,wxConvUTF8 ) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wTurntable.getport1( m_Props ) );
  m_Port1->SetValue( wxString(str,wxConvUTF8 ) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wTurntable.getport2( m_Props ) );
  m_Port2->SetValue( wxString(str,wxConvUTF8 ) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wTurntable.getport3( m_Props ) );
  m_Port3->SetValue( wxString(str,wxConvUTF8 ) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wTurntable.getport4( m_Props ) );
  m_Port4->SetValue( wxString(str,wxConvUTF8 ) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wTurntable.getport5( m_Props ) );
  m_Port5->SetValue( wxString(str,wxConvUTF8 ) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wTurntable.getport6( m_Props ) );
  m_Port6->SetValue( wxString(str,wxConvUTF8 ) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wTurntable.getresetport( m_Props ) );
  m_ResetPort->SetValue( wxString(str,wxConvUTF8 ) ); StrOp.free( str );

  m_InvertPos->SetValue( wTurntable.isinvpos(m_Props)?true:false );
  m_InvertNew->SetValue( wTurntable.isinvnew(m_Props)?true:false );
  m_SingleGatePos->SetValue( wTurntable.issinglegatepos(m_Props)?true:false );
  m_SingleGateNew->SetValue( wTurntable.issinglegatenew(m_Props)?true:false );

  m_Bit0Cmd->SetSelection(wTurntable.getbit0cmd(m_Props));
  m_Bit1Cmd->SetSelection(wTurntable.getbit1cmd(m_Props));
  m_Bit2Cmd->SetSelection(wTurntable.getbit2cmd(m_Props));
  m_Bit3Cmd->SetSelection(wTurntable.getbit3cmd(m_Props));
  m_Bit4Cmd->SetSelection(wTurntable.getbit4cmd(m_Props));
  m_Bit5Cmd->SetSelection(wTurntable.getbit5cmd(m_Props));
  m_ResetCmd->SetSelection(wTurntable.getresetbitcmd(m_Props));

  // Tracks
  if( m_TracksGrid->GetNumberRows() > 0 )
    m_TracksGrid->DeleteRows(0,m_TracksGrid->GetNumberRows());

  iONode track = wTurntable.gettrack( m_Props );
  while( track != NULL ) {
    m_TracksGrid->AppendRows();
    char* nr = StrOp.fmt( "%d", wTTTrack.getnr( track ) );
    m_TracksGrid->SetCellValue(m_TracksGrid->GetNumberRows()-1, 0, wxString(nr,wxConvUTF8 ) );
    StrOp.free( nr );
    m_TracksGrid->SetCellValue(m_TracksGrid->GetNumberRows()-1, 1, wxString(wTTTrack.getposfb( track ),wxConvUTF8 ) );
    m_TracksGrid->SetCellValue(m_TracksGrid->GetNumberRows()-1, 2, wxString(wTTTrack.getdesc( track ),wxConvUTF8 ) );
    nr = StrOp.fmt( "%d", wTTTrack.getdecnr( track ) );
    m_TracksGrid->SetCellValue(m_TracksGrid->GetNumberRows()-1, 3, wxString(nr,wxConvUTF8 ) );
    StrOp.free( nr );
    nr = StrOp.fmt( "%d", wTTTrack.getoppositetrack( track ) );
    m_TracksGrid->SetCellValue(m_TracksGrid->GetNumberRows()-1, 4, wxString(nr,wxConvUTF8 ) );
    StrOp.free( nr );
    if( wTTTrack.getbkid( track ) != NULL )
      m_TracksGrid->SetCellValue(m_TracksGrid->GetNumberRows()-1, 5, wxString(wTTTrack.getbkid( track ),wxConvUTF8 ) );

    m_TracksGrid->SetReadOnly( m_TracksGrid->GetNumberRows()-1, 0, true );
    m_TracksGrid->SetReadOnly( m_TracksGrid->GetNumberRows()-1, 1, true );
    m_TracksGrid->SetReadOnly( m_TracksGrid->GetNumberRows()-1, 2, true );
    m_TracksGrid->SetReadOnly( m_TracksGrid->GetNumberRows()-1, 3, true );
    m_TracksGrid->SetReadOnly( m_TracksGrid->GetNumberRows()-1, 4, true );
    m_TracksGrid->SetReadOnly( m_TracksGrid->GetNumberRows()-1, 5, true );

    if( wTTTrack.isshow( track )) {
      m_TracksGrid->SetCellBackgroundColour( m_TracksGrid->GetNumberRows()-1, 0,
          m_TracksGrid->GetCellBackgroundColour(m_TracksGrid->GetNumberRows()-1, 0));
    }
    else {
      m_TracksGrid->SetCellBackgroundColour( m_TracksGrid->GetNumberRows()-1, 0, wxColour(255,200,200));
    }


    track = wTurntable.nexttrack( m_Props, track );
  };

  m_DelTrack->Enable( false );
  m_ModifyTrack->Enable( false );

  m_TracksGrid->AutoSizeColumns();
  m_TracksGrid->FitInside();
  m_TracksPanel->GetSizer()->Layout();

  wxCommandEvent event( wxEVT_COMMAND_COMBOBOX_SELECTED, ID_COMBOBOX_TT_TYPE );
  wxPostEvent( this, event );

}


bool TurntableDialog::evaluate() {
  if( m_Props == NULL )
    return false;

  if( m_ID->GetValue().Len() == 0 ) {
    wxMessageDialog( this, wxGetApp().getMsg("invalidid"), _T("Rocrail"), wxOK | wxICON_ERROR ).ShowModal();
    m_ID->SetValue( wxString(wItem.getid( m_Props ),wxConvUTF8) );
    return false;
  }

  // General
  wItem.setprev_id( m_Props, wItem.getid(m_Props) );
  wTurntable.setid( m_Props, m_ID->GetValue().mb_str(wxConvUTF8) );
  wTurntable.setdesc( m_Props, m_Desc->GetValue().mb_str(wxConvUTF8) );
  wTurntable.setmanager(m_Props, m_Manager->IsChecked()?True:False);
  wTurntable.setembeddedblock(m_Props, m_EmbeddedBlock->IsChecked()?True:False);
  wTurntable.settraverser(m_Props, m_Traverser->IsChecked()?True:False);
  wTurntable.setmove4opp(m_Props, m_Move4Opp->IsChecked()?True:False);
  wTurntable.setrandomrate( m_Props, m_RandomRate->GetValue() );

  // Location
  wTurntable.setx( m_Props, atoi( m_x->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.sety( m_Props, atoi( m_y->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.setz( m_Props, atoi( m_z->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.setsymbolsize( m_Props, m_Size->GetValue() );

  // Interface
  wTurntable.setiid( m_Props, m_IID->GetValue().mb_str(wxConvUTF8) );
  wTurntable.setbus( m_Props, atoi( m_Bus->GetValue().mb_str(wxConvUTF8) ) );
  wItem.setuidname( m_Props, m_UIDName->GetValue().mb_str(wxConvUTF8) );
  wTurntable.setaddr( m_Props, atoi( m_Address->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.setdiraddr( m_Props, atoi( m_AddressDir->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.setpoladdr( m_Props, atoi( m_PolAddr->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.settype( m_Props, m_Type->GetStringSelection().mb_str(wxConvUTF8) );
  wTurntable.setV( m_Props, m_V->GetValue() );
  wTurntable.setdelay( m_Props, m_Delay->GetValue() );
  wTurntable.setpause( m_Props, m_Pause->GetValue() );
  wTurntable.setactfn( m_Props, m_ActFn->GetValue() );
  wTurntable.setlightsfn( m_Props, m_LightsFn->GetValue() );
  wTurntable.setmotoroffdelay( m_Props, m_MotorOffDelay->GetValue() );
  wTurntable.setinv( m_Props, m_Inv->IsChecked()?True:False);

  if( m_Prot->GetSelection() == 0 )
    wTurntable.setprot( m_Props, wTurntable.prot_DEF );
  else if( m_Prot->GetSelection() == 1 )
    wTurntable.setprot( m_Props, wTurntable.prot_M );
  else if( m_Prot->GetSelection() == 2 )
    wTurntable.setprot( m_Props, wTurntable.prot_N );

  if( StrOp.equals( "-", m_BridgeSensor1->GetStringSelection().mb_str(wxConvUTF8) ) )
    wTurntable.sets1( m_Props, "" );
  else
    wTurntable.sets1( m_Props, m_BridgeSensor1->GetStringSelection().mb_str(wxConvUTF8) );

  if( StrOp.equals( "-", m_BridgeSensor2->GetStringSelection().mb_str(wxConvUTF8) ) )
    wTurntable.sets2( m_Props, "" );
  else
    wTurntable.sets2( m_Props, m_BridgeSensor2->GetStringSelection().mb_str(wxConvUTF8) );

  if( StrOp.equals( "-", m_BridgeSensorMid->GetStringSelection().mb_str(wxConvUTF8) ) )
    wTurntable.setsMid( m_Props, "" );
  else
    wTurntable.setsMid( m_Props, m_BridgeSensorMid->GetStringSelection().mb_str(wxConvUTF8) );

  if( StrOp.equals( "-", m_BridgeSensorMid2->GetStringSelection().mb_str(wxConvUTF8) ) )
    wTurntable.setsMid2( m_Props, "" );
  else
    wTurntable.setsMid2( m_Props, m_BridgeSensorMid2->GetStringSelection().mb_str(wxConvUTF8) );

  if( StrOp.equals( "-", m_PSen->GetStringSelection().mb_str(wxConvUTF8) ) )
    wTurntable.setpsen( m_Props, "" );
  else
    wTurntable.setpsen( m_Props, m_PSen->GetStringSelection().mb_str(wxConvUTF8) );

  wTurntable.setswaprotation( m_Props, m_SwapRotation->IsChecked()?True:False );

  // multiport
  wTurntable.setaddr0( m_Props, atoi( m_Addr0->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.setaddr1( m_Props, atoi( m_Addr1->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.setaddr2( m_Props, atoi( m_Addr2->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.setaddr3( m_Props, atoi( m_Addr3->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.setaddr4( m_Props, atoi( m_Addr4->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.setaddr5( m_Props, atoi( m_Addr5->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.setaddr6( m_Props, atoi( m_Addr6->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.setport0( m_Props, atoi( m_Port0->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.setport1( m_Props, atoi( m_Port1->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.setport2( m_Props, atoi( m_Port2->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.setport3( m_Props, atoi( m_Port3->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.setport4( m_Props, atoi( m_Port4->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.setport5( m_Props, atoi( m_Port5->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.setport6( m_Props, atoi( m_Port6->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.setinvpos(m_Props, m_InvertPos->IsChecked()?True:False);
  wTurntable.setinvnew(m_Props, m_InvertNew->IsChecked()?True:False);

  wTurntable.setsinglegatepos(m_Props, m_SingleGatePos->IsChecked()?True:False);
  wTurntable.setsinglegatenew(m_Props, m_SingleGateNew->IsChecked()?True:False);

  wTurntable.setresetaddr( m_Props, atoi( m_ResetAddr->GetValue().mb_str(wxConvUTF8) ) );
  wTurntable.setresetport( m_Props, atoi( m_ResetPort->GetValue().mb_str(wxConvUTF8) ) );

  wTurntable.setbit0cmd(m_Props, m_Bit0Cmd->GetSelection());
  wTurntable.setbit1cmd(m_Props, m_Bit1Cmd->GetSelection());
  wTurntable.setbit2cmd(m_Props, m_Bit2Cmd->GetSelection());
  wTurntable.setbit3cmd(m_Props, m_Bit3Cmd->GetSelection());
  wTurntable.setbit4cmd(m_Props, m_Bit4Cmd->GetSelection());
  wTurntable.setbit5cmd(m_Props, m_Bit5Cmd->GetSelection());
  wTurntable.setresetbitcmd(m_Props, m_ResetCmd->GetSelection());

  return true;
}


/*!
 * TurntableDialog creator
 */

bool TurntableDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin TurntableDialog member initialisation
    m_Notebook = NULL;
    m_GeneralPanel = NULL;
    m_LabelID = NULL;
    m_ID = NULL;
    m_LabelDesc = NULL;
    m_Desc = NULL;
    m_labRandomRate = NULL;
    m_RandomRate = NULL;
    m_OptionsBox = NULL;
    m_Manager = NULL;
    m_EmbeddedBlock = NULL;
    m_Traverser = NULL;
    m_Move4Opp = NULL;
    m_Actions = NULL;
    m_LocationPanel = NULL;
    m_LabelX = NULL;
    m_x = NULL;
    m_LabelY = NULL;
    m_y = NULL;
    m_LabelZ = NULL;
    m_z = NULL;
    m_labSize = NULL;
    m_Size = NULL;
    m_Interface = NULL;
    m_Labeliid = NULL;
    m_IID = NULL;
    m_Label_Bus = NULL;
    m_Bus = NULL;
    m_labUIDName = NULL;
    m_UIDName = NULL;
    m_LabelAddress = NULL;
    m_Address = NULL;
    m_AddressDir = NULL;
    m_labPolAddr = NULL;
    m_PolAddr = NULL;
    m_labActFn = NULL;
    m_ActFn = NULL;
    m_labLightsFn = NULL;
    m_LightsFn = NULL;
    m_labMotorOffDelay = NULL;
    m_MotorOffDelay = NULL;
    m_LabelType = NULL;
    m_Type = NULL;
    m_labV = NULL;
    m_V = NULL;
    m_labDelay = NULL;
    m_Delay = NULL;
    m_labPause = NULL;
    m_Pause = NULL;
    m_Inv = NULL;
    m_labProt = NULL;
    m_Prot = NULL;
    m_labBridgeSensor1 = NULL;
    m_BridgeSensor1 = NULL;
    m_labBridgeSensor2 = NULL;
    m_BridgeSensor2 = NULL;
    m_labBridgeSensorMid = NULL;
    m_BridgeSensorMid = NULL;
    m_labBridgeSensorMid2 = NULL;
    m_BridgeSensorMid2 = NULL;
    m_labPSen = NULL;
    m_PSen = NULL;
    m_SwapRotation = NULL;
    m_MultiPortPanel = NULL;
    m_PositionBox = NULL;
    m_labAddr0 = NULL;
    m_Addr0 = NULL;
    m_labPort0 = NULL;
    m_Port0 = NULL;
    m_Bit0Cmd = NULL;
    m_labAddr1 = NULL;
    m_Addr1 = NULL;
    m_labPort1 = NULL;
    m_Port1 = NULL;
    m_Bit1Cmd = NULL;
    m_labAddr2 = NULL;
    m_Addr2 = NULL;
    m_labPort2 = NULL;
    m_Port2 = NULL;
    m_Bit2Cmd = NULL;
    m_labAddr3 = NULL;
    m_Addr3 = NULL;
    m_labPort3 = NULL;
    m_Port3 = NULL;
    m_Bit3Cmd = NULL;
    m_labAddr4 = NULL;
    m_Addr4 = NULL;
    m_labPort4 = NULL;
    m_Port4 = NULL;
    m_Bit4Cmd = NULL;
    m_labAddr6 = NULL;
    m_Addr6 = NULL;
    m_labPort6 = NULL;
    m_Port6 = NULL;
    m_Bit5Cmd = NULL;
    m_InvertPos = NULL;
    m_SingleGatePos = NULL;
    m_NewPositionFlagBox = NULL;
    m_labAddr5 = NULL;
    m_Addr5 = NULL;
    m_labPort5 = NULL;
    m_Port5 = NULL;
    m_InvertNew = NULL;
    m_SingleGateNew = NULL;
    m_ResetFlagBox = NULL;
    m_labResetAddr = NULL;
    m_ResetAddr = NULL;
    m_labResetPort = NULL;
    m_ResetPort = NULL;
    m_ResetCmd = NULL;
    m_TracksPanel = NULL;
    m_TracksGrid = NULL;
    m_AddTrack = NULL;
    m_DelTrack = NULL;
    m_ModifyTrack = NULL;
    m_OK = NULL;
    m_Cancel = NULL;
////@end TurntableDialog member initialisation

////@begin TurntableDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end TurntableDialog creation
    return true;
}

/*!
 * Control creation for TurntableDialog
 */

void TurntableDialog::CreateControls()
{
////@begin TurntableDialog content construction
    TurntableDialog* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    m_Notebook = new wxNotebook( itemDialog1, ID_NOTEBOOK_TURNTABLE, wxDefaultPosition, wxDefaultSize, m_TabAlign );

    m_GeneralPanel = new wxPanel( m_Notebook, ID_PANEL_TT_GENERAL, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxVERTICAL);
    m_GeneralPanel->SetSizer(itemBoxSizer5);

    wxFlexGridSizer* itemFlexGridSizer6 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer5->Add(itemFlexGridSizer6, 0, wxGROW|wxALL, 5);
    m_LabelID = new wxStaticText( m_GeneralPanel, wxID_STATIC_TT_ID, _("id"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_LabelID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ID = new wxTextCtrl( m_GeneralPanel, ID_TEXTCTRL_TT_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_ID, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelDesc = new wxStaticText( m_GeneralPanel, wxID_STATIC_TT_DESC, _("Desc."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_LabelDesc, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Desc = new wxTextCtrl( m_GeneralPanel, ID_TEXTCTRL_TT_DESC, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_Desc, 0, wxALIGN_LEFT|wxGROW|wxALL, 5);

    m_labRandomRate = new wxStaticText( m_GeneralPanel, wxID_ANY, _("Random rate"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_labRandomRate, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_RandomRate = new wxSpinCtrl( m_GeneralPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1000, 0 );
    itemFlexGridSizer6->Add(m_RandomRate, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer6->AddGrowableCol(1);

    wxStaticBox* itemStaticBoxSizer13Static = new wxStaticBox(m_GeneralPanel, wxID_ANY, _("Options"));
    m_OptionsBox = new wxStaticBoxSizer(itemStaticBoxSizer13Static, wxVERTICAL);
    itemBoxSizer5->Add(m_OptionsBox, 0, wxGROW|wxALL, 5);
    m_Manager = new wxCheckBox( m_GeneralPanel, ID_TT_MANAGER, _("Manage Track Blocks"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Manager->SetValue(false);
    m_OptionsBox->Add(m_Manager, 0, wxALIGN_LEFT|wxALL, 5);

    m_EmbeddedBlock = new wxCheckBox( m_GeneralPanel, wxID_ANY, _("Embedded block"), wxDefaultPosition, wxDefaultSize, 0 );
    m_EmbeddedBlock->SetValue(false);
    m_OptionsBox->Add(m_EmbeddedBlock, 0, wxALIGN_LEFT|wxALL, 5);

    m_Traverser = new wxCheckBox( m_GeneralPanel, wxID_ANY, _("Traverser"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Traverser->SetValue(false);
    m_OptionsBox->Add(m_Traverser, 0, wxALIGN_LEFT|wxALL, 5);

    m_Move4Opp = new wxCheckBox( m_GeneralPanel, wxID_ANY, _("Move bridge in case target is opposite"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Move4Opp->SetValue(false);
    m_OptionsBox->Add(m_Move4Opp, 0, wxALIGN_LEFT|wxALL, 5);

    m_Actions = new wxButton( m_GeneralPanel, ID_TT_ACTIONS, _("Actions..."), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer5->Add(m_Actions, 0, wxALIGN_LEFT|wxALL, 5);

    m_Notebook->AddPage(m_GeneralPanel, _("General"));

    m_LocationPanel = new wxPanel( m_Notebook, ID_PANEL_TT_LOCATION, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer20 = new wxBoxSizer(wxHORIZONTAL);
    m_LocationPanel->SetSizer(itemBoxSizer20);

    wxFlexGridSizer* itemFlexGridSizer21 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer20->Add(itemFlexGridSizer21, 0, wxALIGN_TOP|wxALL, 5);
    m_LabelX = new wxStaticText( m_LocationPanel, wxID_STATIC_TT_X, _("x"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer21->Add(m_LabelX, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_x = new wxTextCtrl( m_LocationPanel, ID_TEXTCTRL_TT_X, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer21->Add(m_x, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_TOP|wxALL, 5);

    m_LabelY = new wxStaticText( m_LocationPanel, wxID_STATIC_TT_Y, _("y"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer21->Add(m_LabelY, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_y = new wxTextCtrl( m_LocationPanel, ID_TEXTCTRL_TT_Y, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer21->Add(m_y, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelZ = new wxStaticText( m_LocationPanel, wxID_STATIC_TT_Z, _("z"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer21->Add(m_LabelZ, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_z = new wxTextCtrl( m_LocationPanel, ID_TEXTCTRL_TT_Z, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer21->Add(m_z, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labSize = new wxStaticText( m_LocationPanel, wxID_ANY, _("Size"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer21->Add(m_labSize, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Size = new wxSpinCtrl( m_LocationPanel, wxID_ANY, wxT("5"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 2, 13, 5 );
    itemFlexGridSizer21->Add(m_Size, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Notebook->AddPage(m_LocationPanel, _("Location"));

    m_Interface = new wxPanel( m_Notebook, ID_PANEL_TT_INTERFACE, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer31 = new wxBoxSizer(wxHORIZONTAL);
    m_Interface->SetSizer(itemBoxSizer31);

    wxBoxSizer* itemBoxSizer32 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer31->Add(itemBoxSizer32, 0, wxGROW, 5);
    wxFlexGridSizer* itemFlexGridSizer33 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer32->Add(itemFlexGridSizer33, 0, wxGROW|wxALL, 5);
    m_Labeliid = new wxStaticText( m_Interface, wxID_STATIC_TT_IID, _("iid"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer33->Add(m_Labeliid, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_IIDStrings;
    m_IID = new wxComboBox( m_Interface, ID_TEXTCTRL_TT_IID, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_IIDStrings, wxCB_DROPDOWN );
    itemFlexGridSizer33->Add(m_IID, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Label_Bus = new wxStaticText( m_Interface, wxID_STATIC_TT_BUS, _("Bus:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer33->Add(m_Label_Bus, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_Bus = new wxTextCtrl( m_Interface, ID_TEXTCTRL_TT_BUS, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer33->Add(m_Bus, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labUIDName = new wxStaticText( m_Interface, wxID_ANY, _("UID-Name"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer33->Add(m_labUIDName, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_UIDName = new wxTextCtrl( m_Interface, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_UIDName->SetMaxLength(60);
    itemFlexGridSizer33->Add(m_UIDName, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_LabelAddress = new wxStaticText( m_Interface, wxID_STATIC_TT_ADDRESS, _("address"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer33->Add(m_LabelAddress, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxFlexGridSizer* itemFlexGridSizer41 = new wxFlexGridSizer(0, 2, 0, 0);
    itemFlexGridSizer33->Add(itemFlexGridSizer41, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    m_Address = new wxTextCtrl( m_Interface, ID_TEXTCTRL_TT_ADDRESS, _("0"), wxDefaultPosition, wxSize(70, -1), wxTE_CENTRE );
    itemFlexGridSizer41->Add(m_Address, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_AddressDir = new wxTextCtrl( m_Interface, wxID_ANY, _("0"), wxDefaultPosition, wxSize(70, -1), wxTE_CENTRE );
    itemFlexGridSizer41->Add(m_AddressDir, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labPolAddr = new wxStaticText( m_Interface, wxID_STATIC, _("pol. addr."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer33->Add(m_labPolAddr, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_PolAddr = new wxTextCtrl( m_Interface, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer33->Add(m_PolAddr, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labActFn = new wxStaticText( m_Interface, wxID_ANY, _("ActFn"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer33->Add(m_labActFn, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_ActFn = new wxSpinCtrl( m_Interface, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 28, 0 );
    itemFlexGridSizer33->Add(m_ActFn, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labLightsFn = new wxStaticText( m_Interface, wxID_STATIC, _("Lights Fn"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer33->Add(m_labLightsFn, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_LightsFn = new wxSpinCtrl( m_Interface, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 28, 0 );
    itemFlexGridSizer33->Add(m_LightsFn, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labMotorOffDelay = new wxStaticText( m_Interface, wxID_ANY, _("Motor off delay"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer33->Add(m_labMotorOffDelay, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_MotorOffDelay = new wxSpinCtrl( m_Interface, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 0, 5000, 0 );
    itemFlexGridSizer33->Add(m_MotorOffDelay, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_LabelType = new wxStaticText( m_Interface, wxID_STATIC_TT_TYPE, _("type"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer33->Add(m_LabelType, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_TypeStrings;
    m_Type = new wxComboBox( m_Interface, ID_COMBOBOX_TT_TYPE, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_TypeStrings, wxCB_READONLY );
    itemFlexGridSizer33->Add(m_Type, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labV = new wxStaticText( m_Interface, wxID_ANY, _("rotation velocity"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer33->Add(m_labV, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_V = new wxSpinCtrl( m_Interface, wxID_ANY, wxT("75"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 10, 100, 75 );
    itemFlexGridSizer33->Add(m_V, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_labDelay = new wxStaticText( m_Interface, wxID_STATIC, _("Delay"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer33->Add(m_labDelay, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Delay = new wxSpinCtrl( m_Interface, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 60, 0 );
    itemFlexGridSizer33->Add(m_Delay, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labPause = new wxStaticText( m_Interface, wxID_ANY, _("Pause"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer33->Add(m_labPause, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_Pause = new wxSpinCtrl( m_Interface, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 10, 0 );
    itemFlexGridSizer33->Add(m_Pause, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemFlexGridSizer33->AddGrowableCol(1);

    m_Inv = new wxCheckBox( m_Interface, wxID_ANY, _("Invert"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Inv->SetValue(false);
    itemBoxSizer32->Add(m_Inv, 0, wxALIGN_LEFT|wxALL, 5);

    wxStaticLine* itemStaticLine61 = new wxStaticLine( m_Interface, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    itemBoxSizer31->Add(itemStaticLine61, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer62 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer31->Add(itemBoxSizer62, 1, wxGROW|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer63 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer62->Add(itemFlexGridSizer63, 1, wxGROW|wxALL, 5);
    m_labProt = new wxStaticText( m_Interface, wxID_ANY, _("protocol"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer63->Add(m_labProt, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_ProtStrings;
    m_Prot = new wxComboBox( m_Interface, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_ProtStrings, wxCB_DROPDOWN );
    itemFlexGridSizer63->Add(m_Prot, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labBridgeSensor1 = new wxStaticText( m_Interface, wxID_ANY, _("Sensor 1"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer63->Add(m_labBridgeSensor1, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxArrayString m_BridgeSensor1Strings;
    m_BridgeSensor1 = new wxComboBox( m_Interface, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_BridgeSensor1Strings, wxCB_READONLY );
    itemFlexGridSizer63->Add(m_BridgeSensor1, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labBridgeSensor2 = new wxStaticText( m_Interface, wxID_ANY, _("Sensor 2"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer63->Add(m_labBridgeSensor2, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxArrayString m_BridgeSensor2Strings;
    m_BridgeSensor2 = new wxComboBox( m_Interface, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_BridgeSensor2Strings, wxCB_READONLY );
    itemFlexGridSizer63->Add(m_BridgeSensor2, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labBridgeSensorMid = new wxStaticText( m_Interface, wxID_ANY, _("Sensor Mid 1"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer63->Add(m_labBridgeSensorMid, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxArrayString m_BridgeSensorMidStrings;
    m_BridgeSensorMid = new wxComboBox( m_Interface, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_BridgeSensorMidStrings, wxCB_READONLY );
    itemFlexGridSizer63->Add(m_BridgeSensorMid, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labBridgeSensorMid2 = new wxStaticText( m_Interface, wxID_ANY, _("Sensor Mid 2"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer63->Add(m_labBridgeSensorMid2, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxArrayString m_BridgeSensorMid2Strings;
    m_BridgeSensorMid2 = new wxComboBox( m_Interface, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_BridgeSensorMid2Strings, wxCB_DROPDOWN );
    itemFlexGridSizer63->Add(m_BridgeSensorMid2, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labPSen = new wxStaticText( m_Interface, wxID_ANY, _("Position sensor"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer63->Add(m_labPSen, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxArrayString m_PSenStrings;
    m_PSen = new wxComboBox( m_Interface, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_PSenStrings, wxCB_DROPDOWN );
    itemFlexGridSizer63->Add(m_PSen, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemFlexGridSizer63->AddGrowableCol(1);

    m_SwapRotation = new wxCheckBox( m_Interface, wxID_ANY, _("Swap rotation direction"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SwapRotation->SetValue(false);
    itemBoxSizer62->Add(m_SwapRotation, 0, wxALIGN_LEFT|wxALL, 5);

    m_Notebook->AddPage(m_Interface, _("Interface"));

    m_MultiPortPanel = new wxPanel( m_Notebook, ID_MULTIPORTPANEL, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer78 = new wxBoxSizer(wxVERTICAL);
    m_MultiPortPanel->SetSizer(itemBoxSizer78);

    m_PositionBox = new wxStaticBox(m_MultiPortPanel, wxID_ANY, _("Position"));
    wxStaticBoxSizer* itemStaticBoxSizer79 = new wxStaticBoxSizer(m_PositionBox, wxVERTICAL);
    itemBoxSizer78->Add(itemStaticBoxSizer79, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 5);
    wxFlexGridSizer* itemFlexGridSizer80 = new wxFlexGridSizer(0, 5, 0, 0);
    itemStaticBoxSizer79->Add(itemFlexGridSizer80, 0, wxGROW|wxLEFT|wxRIGHT, 5);
    m_labAddr0 = new wxStaticText( m_MultiPortPanel, wxID_ANY, _("Address 0"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer80->Add(m_labAddr0, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_Addr0 = new wxTextCtrl( m_MultiPortPanel, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer80->Add(m_Addr0, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_labPort0 = new wxStaticText( m_MultiPortPanel, wxID_ANY, _("port"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer80->Add(m_labPort0, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_Port0 = new wxTextCtrl( m_MultiPortPanel, wxID_ANY, _("0"), wxDefaultPosition, wxSize(60, -1), wxTE_CENTRE );
    itemFlexGridSizer80->Add(m_Port0, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxArrayString m_Bit0CmdStrings;
    m_Bit0CmdStrings.Add(_("&straight"));
    m_Bit0CmdStrings.Add(_("&turnout"));
    m_Bit0Cmd = new wxRadioBox( m_MultiPortPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Bit0CmdStrings, 1, wxRA_SPECIFY_ROWS );
    m_Bit0Cmd->SetSelection(0);
    itemFlexGridSizer80->Add(m_Bit0Cmd, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labAddr1 = new wxStaticText( m_MultiPortPanel, wxID_ANY, _("Address 1"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer80->Add(m_labAddr1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Addr1 = new wxTextCtrl( m_MultiPortPanel, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer80->Add(m_Addr1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labPort1 = new wxStaticText( m_MultiPortPanel, wxID_ANY, _("port"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer80->Add(m_labPort1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Port1 = new wxTextCtrl( m_MultiPortPanel, wxID_ANY, _("0"), wxDefaultPosition, wxSize(60, -1), wxTE_CENTRE );
    itemFlexGridSizer80->Add(m_Port1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxArrayString m_Bit1CmdStrings;
    m_Bit1CmdStrings.Add(_("&straight"));
    m_Bit1CmdStrings.Add(_("&turnout"));
    m_Bit1Cmd = new wxRadioBox( m_MultiPortPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Bit1CmdStrings, 1, wxRA_SPECIFY_ROWS );
    m_Bit1Cmd->SetSelection(0);
    itemFlexGridSizer80->Add(m_Bit1Cmd, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labAddr2 = new wxStaticText( m_MultiPortPanel, wxID_ANY, _("Address 2"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer80->Add(m_labAddr2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Addr2 = new wxTextCtrl( m_MultiPortPanel, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer80->Add(m_Addr2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labPort2 = new wxStaticText( m_MultiPortPanel, wxID_ANY, _("port"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer80->Add(m_labPort2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Port2 = new wxTextCtrl( m_MultiPortPanel, wxID_ANY, _("0"), wxDefaultPosition, wxSize(60, -1), wxTE_CENTRE );
    itemFlexGridSizer80->Add(m_Port2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxArrayString m_Bit2CmdStrings;
    m_Bit2CmdStrings.Add(_("&straight"));
    m_Bit2CmdStrings.Add(_("&turnout"));
    m_Bit2Cmd = new wxRadioBox( m_MultiPortPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Bit2CmdStrings, 1, wxRA_SPECIFY_ROWS );
    m_Bit2Cmd->SetSelection(0);
    itemFlexGridSizer80->Add(m_Bit2Cmd, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labAddr3 = new wxStaticText( m_MultiPortPanel, wxID_ANY, _("Address 3"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer80->Add(m_labAddr3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Addr3 = new wxTextCtrl( m_MultiPortPanel, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer80->Add(m_Addr3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labPort3 = new wxStaticText( m_MultiPortPanel, wxID_ANY, _("port"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer80->Add(m_labPort3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Port3 = new wxTextCtrl( m_MultiPortPanel, wxID_ANY, _("0"), wxDefaultPosition, wxSize(60, -1), wxTE_CENTRE );
    itemFlexGridSizer80->Add(m_Port3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxArrayString m_Bit3CmdStrings;
    m_Bit3CmdStrings.Add(_("&straight"));
    m_Bit3CmdStrings.Add(_("&turnout"));
    m_Bit3Cmd = new wxRadioBox( m_MultiPortPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Bit3CmdStrings, 1, wxRA_SPECIFY_ROWS );
    m_Bit3Cmd->SetSelection(0);
    itemFlexGridSizer80->Add(m_Bit3Cmd, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labAddr4 = new wxStaticText( m_MultiPortPanel, wxID_ANY, _("Address 4"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer80->Add(m_labAddr4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Addr4 = new wxTextCtrl( m_MultiPortPanel, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer80->Add(m_Addr4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labPort4 = new wxStaticText( m_MultiPortPanel, wxID_ANY, _("port"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer80->Add(m_labPort4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Port4 = new wxTextCtrl( m_MultiPortPanel, wxID_ANY, _("0"), wxDefaultPosition, wxSize(60, -1), wxTE_CENTRE );
    itemFlexGridSizer80->Add(m_Port4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxArrayString m_Bit4CmdStrings;
    m_Bit4CmdStrings.Add(_("&straight"));
    m_Bit4CmdStrings.Add(_("&turnout"));
    m_Bit4Cmd = new wxRadioBox( m_MultiPortPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Bit4CmdStrings, 1, wxRA_SPECIFY_ROWS );
    m_Bit4Cmd->SetSelection(0);
    itemFlexGridSizer80->Add(m_Bit4Cmd, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labAddr6 = new wxStaticText( m_MultiPortPanel, wxID_ANY, _("Address 5"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer80->Add(m_labAddr6, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Addr6 = new wxTextCtrl( m_MultiPortPanel, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer80->Add(m_Addr6, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labPort6 = new wxStaticText( m_MultiPortPanel, wxID_ANY, _("port"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer80->Add(m_labPort6, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Port6 = new wxTextCtrl( m_MultiPortPanel, wxID_ANY, _("0"), wxDefaultPosition, wxSize(60, -1), wxTE_CENTRE );
    itemFlexGridSizer80->Add(m_Port6, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxArrayString m_Bit5CmdStrings;
    m_Bit5CmdStrings.Add(_("&straight"));
    m_Bit5CmdStrings.Add(_("&turnout"));
    m_Bit5Cmd = new wxRadioBox( m_MultiPortPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Bit5CmdStrings, 1, wxRA_SPECIFY_ROWS );
    m_Bit5Cmd->SetSelection(0);
    itemFlexGridSizer80->Add(m_Bit5Cmd, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxFlexGridSizer* itemFlexGridSizer111 = new wxFlexGridSizer(0, 2, 0, 0);
    itemStaticBoxSizer79->Add(itemFlexGridSizer111, 0, wxALIGN_LEFT, 5);
    m_InvertPos = new wxCheckBox( m_MultiPortPanel, wxID_ANY, _("Invert"), wxDefaultPosition, wxDefaultSize, 0 );
    m_InvertPos->SetValue(false);
    itemFlexGridSizer111->Add(m_InvertPos, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_SingleGatePos = new wxCheckBox( m_MultiPortPanel, wxID_ANY, _("Single gate"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SingleGatePos->SetValue(false);
    itemFlexGridSizer111->Add(m_SingleGatePos, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_NewPositionFlagBox = new wxStaticBox(m_MultiPortPanel, wxID_ANY, _("New Position Flag"));
    wxStaticBoxSizer* itemStaticBoxSizer114 = new wxStaticBoxSizer(m_NewPositionFlagBox, wxVERTICAL);
    itemBoxSizer78->Add(itemStaticBoxSizer114, 0, wxGROW|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer115 = new wxFlexGridSizer(0, 6, 0, 0);
    itemStaticBoxSizer114->Add(itemFlexGridSizer115, 0, wxGROW|wxALL, 5);
    m_labAddr5 = new wxStaticText( m_MultiPortPanel, wxID_ANY, _("Address"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer115->Add(m_labAddr5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Addr5 = new wxTextCtrl( m_MultiPortPanel, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer115->Add(m_Addr5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labPort5 = new wxStaticText( m_MultiPortPanel, wxID_ANY, _("port"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer115->Add(m_labPort5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Port5 = new wxTextCtrl( m_MultiPortPanel, wxID_ANY, _("0"), wxDefaultPosition, wxSize(60, -1), wxTE_CENTRE );
    itemFlexGridSizer115->Add(m_Port5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_InvertNew = new wxCheckBox( m_MultiPortPanel, wxID_ANY, _("Invert"), wxDefaultPosition, wxDefaultSize, 0 );
    m_InvertNew->SetValue(false);
    itemFlexGridSizer115->Add(m_InvertNew, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_SingleGateNew = new wxCheckBox( m_MultiPortPanel, wxID_ANY, _("Single gate"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SingleGateNew->SetValue(false);
    itemFlexGridSizer115->Add(m_SingleGateNew, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_ResetFlagBox = new wxStaticBox(m_MultiPortPanel, wxID_ANY, _("Reset Flag"));
    wxStaticBoxSizer* itemStaticBoxSizer122 = new wxStaticBoxSizer(m_ResetFlagBox, wxVERTICAL);
    itemBoxSizer78->Add(itemStaticBoxSizer122, 0, wxGROW|wxLEFT|wxRIGHT, 5);
    wxFlexGridSizer* itemFlexGridSizer123 = new wxFlexGridSizer(0, 5, 0, 0);
    itemStaticBoxSizer122->Add(itemFlexGridSizer123, 0, wxGROW|wxLEFT|wxRIGHT, 5);
    m_labResetAddr = new wxStaticText( m_MultiPortPanel, wxID_ANY, _("Address"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer123->Add(m_labResetAddr, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_ResetAddr = new wxTextCtrl( m_MultiPortPanel, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer123->Add(m_ResetAddr, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labResetPort = new wxStaticText( m_MultiPortPanel, wxID_ANY, _("port"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer123->Add(m_labResetPort, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_ResetPort = new wxTextCtrl( m_MultiPortPanel, wxID_ANY, _("0"), wxDefaultPosition, wxSize(60, -1), wxTE_CENTRE );
    itemFlexGridSizer123->Add(m_ResetPort, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxArrayString m_ResetCmdStrings;
    m_ResetCmdStrings.Add(_("&straight"));
    m_ResetCmdStrings.Add(_("&turnout"));
    m_ResetCmd = new wxRadioBox( m_MultiPortPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_ResetCmdStrings, 1, wxRA_SPECIFY_ROWS );
    m_ResetCmd->SetSelection(0);
    itemFlexGridSizer123->Add(m_ResetCmd, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Notebook->AddPage(m_MultiPortPanel, _("Multiport"));

    m_TracksPanel = new wxPanel( m_Notebook, ID_PANEL_TT_TRACKS, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer130 = new wxBoxSizer(wxVERTICAL);
    m_TracksPanel->SetSizer(itemBoxSizer130);

    m_TracksGrid = new wxGrid( m_TracksPanel, ID_GRID, wxDefaultPosition, wxSize(220, 200), wxSUNKEN_BORDER|wxHSCROLL|wxVSCROLL );
    m_TracksGrid->SetDefaultColSize(50);
    m_TracksGrid->SetDefaultRowSize(20);
    m_TracksGrid->SetColLabelSize(20);
    m_TracksGrid->SetRowLabelSize(0);
    m_TracksGrid->CreateGrid(1, 6, wxGrid::wxGridSelectRows);
    itemBoxSizer130->Add(m_TracksGrid, 2, wxGROW|wxALL, 2);

    wxBoxSizer* itemBoxSizer132 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer130->Add(itemBoxSizer132, 0, wxGROW|wxALL, 5);
    m_AddTrack = new wxButton( m_TracksPanel, ID_BUTTON_TT_ADDTRACK, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer132->Add(m_AddTrack, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_DelTrack = new wxButton( m_TracksPanel, ID_BUTTON_TT_DELTRACK, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer132->Add(m_DelTrack, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ModifyTrack = new wxButton( m_TracksPanel, ID_BUTTON_TT_MODIFYTRACK, _("Modify"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer132->Add(m_ModifyTrack, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Notebook->AddPage(m_TracksPanel, _("Tracks"));

    itemBoxSizer2->Add(m_Notebook, 1, wxGROW|wxALL, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer136 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer136, 0, wxGROW|wxALL, 5);
    m_OK = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    m_OK->SetDefault();
    itemStdDialogButtonSizer136->AddButton(m_OK);

    m_Cancel = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer136->AddButton(m_Cancel);

    wxButton* itemButton139 = new wxButton( itemDialog1, wxID_HELP, _("&Help"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer136->AddButton(itemButton139);

    itemStdDialogButtonSizer136->Realize();

////@end TurntableDialog content construction
}

/*!
 * Should we show tooltips?
 */

bool TurntableDialog::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap TurntableDialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin TurntableDialog bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end TurntableDialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon TurntableDialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin TurntableDialog icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end TurntableDialog icon retrieval
}
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void TurntableDialog::OnOkClick( wxCommandEvent& event )
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
  EndModal( wxID_OK );
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void TurntableDialog::OnCancelClick( wxCommandEvent& event )
{
  EndModal( 0 );
}


/*!
 * wxEVT_GRID_CELL_LEFT_CLICK event handler for ID_GRID
 */

void TurntableDialog::OnCellLeftClick( wxGridEvent& event )
{
  m_TracksGrid->SelectRow(event.GetRow());
  m_DelTrack->Enable( true );
  m_ModifyTrack->Enable( true );

  wxString str = m_TracksGrid->GetCellValue( event.GetRow(), 0 );
  StrOp.free(m_TrackNr);
  m_TrackNr = StrOp.dup((const char*)str.mb_str(wxConvUTF8));
  TraceOp.trc( "ttdlg", TRCLEVEL_INFO, __LINE__, 9999, "OnCellLeftClick %s", m_TrackNr );
  event.Skip(true);
}

/*!
 * wxEVT_GRID_CELL_RIGHT_CLICK event handler for ID_GRID
 */

void TurntableDialog::OnCellRightClick( wxGridEvent& event )
{
  m_TracksGrid->SelectRow(event.GetRow());
  wxString str = m_TracksGrid->GetCellValue( event.GetRow(), 0 );
  OnCellLeftClick(event);
  TraceOp.trc( "ttdlg", TRCLEVEL_INFO, __LINE__, 9999, "OnCellRightClick %s", m_TrackNr );
  wxMenu menu( str );
  menu.Append( ME_TTTrackAdd, wxGetApp().getMenu("add_track") );
  menu.Append( ME_TTTrackDelete, wxGetApp().getMenu("del_track") );
  menu.AppendSeparator();
  menu.Append( ME_Props, wxGetApp().getMenu("properties") );
  PopupMenu(&menu, event.GetPosition().x, event.GetPosition().y );
  event.Skip(true);
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_TT_ADDTRACK
 */

void TurntableDialog::OnButtonTtAddtrackClick( wxCommandEvent& event )
{
  OnTTTrackAdd(event);
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_TT_DELTRACK
 */

void TurntableDialog::OnButtonTtDeltrackClick( wxCommandEvent& event )
{
  OnTTTrackDelete(event);
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_TT_MODIFYTRACK
 */

void TurntableDialog::OnButtonTtModifytrackClick( wxCommandEvent& event )
{
  OnProps(event);
}



/*!
 * wxEVT_COMMAND_COMBOBOX_SELECTED event handler for ID_COMBOBOX_TT_TYPE
 */

void TurntableDialog::OnTypeSelected( wxCommandEvent& event )
{
  int type = m_Type->GetSelection();
  // 2 or 8
  bool mp = false;
  if( type == 2 || type == 8 )
    mp = true;
  m_MultiPortPanel->Enable( mp );
  m_Address->Enable( !mp );
  m_AddressDir->Enable( !mp );

  bool d15 = (type == 8);
  m_Bit0Cmd->Enable(d15);
  m_Bit1Cmd->Enable(d15);
  m_Bit2Cmd->Enable(d15);
  m_Bit3Cmd->Enable(d15);
  m_Bit4Cmd->Enable(d15);
  m_Bit5Cmd->Enable(d15);
  m_ResetCmd->Enable(d15);
  m_ResetAddr->Enable(d15);
  m_ResetPort->Enable(d15);
  m_InvertPos->Enable(!d15);
  m_InvertNew->Enable(!d15);
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_TT_ACTIONS
 */

void TurntableDialog::OnTtActionsClick( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  ActionsCtrlDlg*  dlg = new ActionsCtrlDlg(this, m_Props, "goto,next,prev,turn180,lighton,lightoff,calibrate,atposition" );

  if( wxID_OK == dlg->ShowModal() ) {
    // TODO: inform
  }

  dlg->Destroy();
}


/*!
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for wxID_ANY
 */

void TurntableDialog::OnManagerClick( wxCommandEvent& event )
{
  if(m_Manager->IsChecked())
    m_EmbeddedBlock->SetValue(true);
  m_EmbeddedBlock->Enable(!m_Manager->IsChecked());
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
 */

void TurntableDialog::OnHelpClick( wxCommandEvent& event )
{
  switch( m_Notebook->GetSelection() ) {
  case 0: wxGetApp().openLink( "turntable-gen" ); break;
  case 1: wxGetApp().openLink( "turntable-pos" ); break;
  case 2: wxGetApp().openLink( "turntable-int" ); break;
  case 3: wxGetApp().openLink( "tt-multiport" ); break;
  case 4: wxGetApp().openLink( "turntable-tracks" ); break;
  default: wxGetApp().openLink( "turntable-gen" ); break;
  }
}

