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
#pragma implementation "tttrackdialog.h"
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
////@end includes

#include "tttrackdialog.h"

#include "rocs/public/str.h"
#include "rocrail/wrapper/public/TTTrack.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Plan.h"
#include "rocview/public/guiapp.h"

////@begin XPM images
////@end XPM images

/*!
 * TTTrackDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( TTTrackDialog, wxDialog )

/*!
 * TTTrackDialog event table definition
 */

BEGIN_EVENT_TABLE( TTTrackDialog, wxDialog )

////@begin TTTrackDialog event table entries
    EVT_BUTTON( wxID_OK, TTTrackDialog::OnOkClick )
    EVT_BUTTON( wxID_CANCEL, TTTrackDialog::OnCancelClick )
    EVT_BUTTON( wxID_HELP, TTTrackDialog::OnHelpClick )
////@end TTTrackDialog event table entries

END_EVENT_TABLE()

/*!
 * TTTrackDialog constructors
 */

TTTrackDialog::TTTrackDialog( )
{
}


TTTrackDialog::TTTrackDialog( wxWindow* parent, iONode p_Props, int min, int max )
{
  Create(parent, -1, wxGetApp().getMsg("turntabletrack") );
  m_Props = p_Props;
  if( min > 0 ) {
    m_TrackNr->SetRange(min, max);
    m_DecTrackNr->SetRange(min, max);
    m_OppTrackNr->SetRange(min, max);
  }
  initLabels();
  initValues();
  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);
}

TTTrackDialog::TTTrackDialog( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
  Create(parent, id, caption, pos, size, style);
}


/* comparator for sorting by id: */
static int __sortStr(obj* _a, obj* _b)
{
    const char* a = (const char*)*_a;
    const char* b = (const char*)*_b;
    return strcmp( a, b );
}

void TTTrackDialog::initLabels() {
  m_LabelTrackNr->SetLabel( wxGetApp().getMsg( "tracknr" ) );
  m_labDecoder->SetLabel( wxGetApp().getMsg("decoder") + _T(" ") + wxGetApp().getMsg("tracknr") );
  m_labOppTrackNr->SetLabel( wxGetApp().getMsg("opposite") + _T(" ") + wxGetApp().getMsg("tracknr") );
  m_LabelDesc->SetLabel( wxGetApp().getMsg( "description" ) );
  m_LabelPosFB->SetLabel( wxGetApp().getMsg( "posfb" ) );
  m_Polarization->SetLabel( wxGetApp().getMsg( "ttbridgepolarization" ) );
  m_Show->SetLabel( wxGetApp().getMsg( "visible" ) );
  m_labBlockID->SetLabel( wxGetApp().getMsg( "blockid" ) );

  // Buttons
  m_OK->SetLabel( wxGetApp().getMsg( "ok" ) );
  m_Cancel->SetLabel( wxGetApp().getMsg( "cancel" ) );

  iONode model = wxGetApp().getModel();
  iOList list = ListOp.inst();

  if( model != NULL ) {
    iONode bklist = wPlan.getbklist( model );
    if( bklist != NULL ) {
      int cnt = NodeOp.getChildCnt( bklist );
      for( int i = 0; i < cnt; i++ ) {
        iONode bk = NodeOp.getChild( bklist, i );
        const char* id = wBlock.getid( bk );
        if( id != NULL ) {
          ListOp.add(list, (obj)id);
        }
      }
      ListOp.sort(list, &__sortStr);
      cnt = ListOp.size( list );
      for( int i = 0; i < cnt; i++ ) {
        const char* id = (const char*)ListOp.get( list, i );
        m_BlockID->Append( wxString(id,wxConvUTF8) );
      }
    }
  }
  /* clean up the temp. list */
  ListOp.base.del(list);


}


void TTTrackDialog::initValues() {
  if( m_Props == NULL )
    return;
  // General
  m_TrackNr->SetValue( wTTTrack.getnr( m_Props ) );
  m_DecTrackNr->SetValue( wTTTrack.getdecnr( m_Props ) );
  m_OppTrackNr->SetValue( wTTTrack.getoppositetrack( m_Props ) );
  m_Desc->SetValue( wxString( wTTTrack.getdesc( m_Props ),wxConvUTF8) );

  iONode model = wxGetApp().getModel();

  if( model != NULL ) {
    m_PosFB->Append( _T("") );
    iONode fblist = wPlan.getfblist( model );
    if( fblist != NULL ) {
      int cnt = NodeOp.getChildCnt( fblist );
      for( int i = 0; i < cnt; i++ ) {
        iONode fb = NodeOp.getChild( fblist, i );
        const char* id = wFeedback.getid( fb );
        m_PosFB->Append( wxString(id,wxConvUTF8) );
      }
      m_PosFB->SetStringSelection( wxString(wTTTrack.getposfb(m_Props),wxConvUTF8) );

    }
  }

  m_Polarization->SetValue(wTTTrack.ispolarization( m_Props ));
  m_Show->SetValue(wTTTrack.isshow( m_Props ));
  m_BlockID->SetStringSelection( wxString(wTTTrack.getbkid(m_Props),wxConvUTF8) );

}

void TTTrackDialog::evaluate() {
  if( m_Props == NULL )
    return;
  // General
  wTTTrack.setnr( m_Props, m_TrackNr->GetValue() );
  wTTTrack.setdecnr( m_Props, m_DecTrackNr->GetValue() );
  wTTTrack.setoppositetrack( m_Props, m_OppTrackNr->GetValue() );
  wTTTrack.setdesc( m_Props, m_Desc->GetValue().mb_str(wxConvUTF8) );
  wTTTrack.setposfb( m_Props, m_PosFB->GetStringSelection().mb_str(wxConvUTF8) );

  wTTTrack.setpolarization( m_Props, m_Polarization->IsChecked() ? True:False );
  wTTTrack.setshow( m_Props, m_Show->IsChecked() ? True:False );
  wTTTrack.setbkid( m_Props, m_BlockID->GetStringSelection().mb_str(wxConvUTF8) );

}

/*!
 * TTTrackDialog creator
 */

bool TTTrackDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin TTTrackDialog member initialisation
    m_Props = NULL;
    m_LabelTrackNr = NULL;
    m_TrackNr = NULL;
    m_labDecoder = NULL;
    m_DecTrackNr = NULL;
    m_labOppTrackNr = NULL;
    m_OppTrackNr = NULL;
    m_LabelDesc = NULL;
    m_Desc = NULL;
    m_labBlockID = NULL;
    m_BlockID = NULL;
    m_LabelPosFB = NULL;
    m_PosFB = NULL;
    m_Polarization = NULL;
    m_Show = NULL;
    m_OK = NULL;
    m_Cancel = NULL;
////@end TTTrackDialog member initialisation

////@begin TTTrackDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end TTTrackDialog creation
    return true;
}

/*!
 * Control creation for TTTrackDialog
 */

void TTTrackDialog::CreateControls()
{
////@begin TTTrackDialog content construction
    TTTrackDialog* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxFlexGridSizer* itemFlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer2->Add(itemFlexGridSizer3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_LabelTrackNr = new wxStaticText( itemDialog1, wxID_STATIC_TTT_NR, _("Track Nr."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer3->Add(m_LabelTrackNr, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_TrackNr = new wxSpinCtrl( itemDialog1, wxID_ANY, _T("0"), wxDefaultPosition, wxSize(70, -1), wxSP_ARROW_KEYS, 0, 47, 0 );
    itemFlexGridSizer3->Add(m_TrackNr, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labDecoder = new wxStaticText( itemDialog1, wxID_STATIC, _("Decoder Nr."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer3->Add(m_labDecoder, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_DecTrackNr = new wxSpinCtrl( itemDialog1, wxID_ANY, _T("-1"), wxDefaultPosition, wxSize(70, -1), wxSP_ARROW_KEYS, -1, 511, -1 );
    itemFlexGridSizer3->Add(m_DecTrackNr, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labOppTrackNr = new wxStaticText( itemDialog1, wxID_ANY, _("Opposite track Nr."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer3->Add(m_labOppTrackNr, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_OppTrackNr = new wxSpinCtrl( itemDialog1, wxID_ANY, _T("-1"), wxDefaultPosition, wxSize(70, -1), wxSP_ARROW_KEYS, -1, 47, -1 );
    itemFlexGridSizer3->Add(m_OppTrackNr, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelDesc = new wxStaticText( itemDialog1, wxID_STATIC_TTT_DESC, _("Description"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer3->Add(m_LabelDesc, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Desc = new wxTextCtrl( itemDialog1, ID_TEXTCTRL_TTT_DESC, wxEmptyString, wxDefaultPosition, wxSize(200, -1), 0 );
    itemFlexGridSizer3->Add(m_Desc, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labBlockID = new wxStaticText( itemDialog1, wxID_ANY, _("BlockID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer3->Add(m_labBlockID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_BlockIDStrings;
    m_BlockID = new wxComboBox( itemDialog1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_BlockIDStrings, wxCB_READONLY );
    itemFlexGridSizer3->Add(m_BlockID, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelPosFB = new wxStaticText( itemDialog1, wxID_STATIC_TTT_POSFB, _("PosFB"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer3->Add(m_LabelPosFB, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_PosFBStrings;
    m_PosFB = new wxComboBox( itemDialog1, ID_COMBOBOX_TTT_POSFB, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_PosFBStrings, wxCB_READONLY );
    itemFlexGridSizer3->Add(m_PosFB, 1, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer3->AddGrowableCol(1);

    m_Polarization = new wxCheckBox( itemDialog1, wxID_ANY, _("Flip bridge polarization"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Polarization->SetValue(false);
    itemBoxSizer2->Add(m_Polarization, 0, wxALIGN_LEFT|wxALL, 5);

    m_Show = new wxCheckBox( itemDialog1, wxID_ANY, _("Visible"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Show->SetValue(false);
    itemBoxSizer2->Add(m_Show, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer18 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer18, 0, wxGROW|wxALL, 5);
    m_OK = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    m_OK->SetDefault();
    itemStdDialogButtonSizer18->AddButton(m_OK);

    m_Cancel = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer18->AddButton(m_Cancel);

    wxButton* itemButton21 = new wxButton( itemDialog1, wxID_HELP, _("&Help"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer18->AddButton(itemButton21);

    itemStdDialogButtonSizer18->Realize();

////@end TTTrackDialog content construction
}

/*!
 * Should we show tooltips?
 */

bool TTTrackDialog::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap TTTrackDialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin TTTrackDialog bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end TTTrackDialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon TTTrackDialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin TTTrackDialog icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end TTTrackDialog icon retrieval
}
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void TTTrackDialog::OnOkClick( wxCommandEvent& event )
{
  evaluate();
  EndModal( wxID_OK );
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void TTTrackDialog::OnCancelClick( wxCommandEvent& event )
{
  EndModal( 0 );
}



/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
 */

void TTTrackDialog::OnHelpClick( wxCommandEvent& event )
{
  wxGetApp().openLink( "turntable-tracks" );
}

