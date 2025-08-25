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

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "dinamodlg.h"
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

#include "dinamodlg.h"

#include "rocrail/wrapper/public/DigInt.h"
#include "rocview/public/guiapp.h"
#include "rocs/public/strtok.h"

////@begin XPM images
////@end XPM images

/*!
 * DinamoCtrlDlg type definition
 */

IMPLEMENT_DYNAMIC_CLASS( DinamoCtrlDlg, wxDialog )

/*!
 * DinamoCtrlDlg event table definition
 */

BEGIN_EVENT_TABLE( DinamoCtrlDlg, wxDialog )

////@begin DinamoCtrlDlg event table entries
    EVT_BUTTON( wxID_OK, DinamoCtrlDlg::OnOkClick )
    EVT_BUTTON( wxID_CANCEL, DinamoCtrlDlg::OnCancelClick )
    EVT_BUTTON( wxID_HELP, DinamoCtrlDlg::OnHelpClick )
////@end DinamoCtrlDlg event table entries

END_EVENT_TABLE()

/*!
 * DinamoCtrlDlg constructors
 */

DinamoCtrlDlg::DinamoCtrlDlg( )
{
}

DinamoCtrlDlg::DinamoCtrlDlg( wxWindow* parent, iONode props, const char* devices )
{
  Create(parent, -1, wxT("Dinamo") );
  m_Props = props;
  m_Devices = devices;
  initLabels();
  initValues();

  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);

  GetSizer()->Layout();
}

void DinamoCtrlDlg::initLabels() {
  m_labIID->SetLabel( wxGetApp().getMsg( "iid" ) );
  m_labDevice->SetLabel( wxGetApp().getMsg( "port" ) );
}

void DinamoCtrlDlg::initValues() {
  if( m_Props == NULL )
    return;
    
  m_IID->SetValue( wxString( wDigInt.getiid( m_Props ), wxConvUTF8 ) );
  m_Device->SetValue( wxString( wDigInt.getdevice( m_Props ), wxConvUTF8 ) );
  if( m_Devices != NULL ) {
    iOStrTok tok = StrTokOp.inst(m_Devices, ',');
    while( StrTokOp.hasMoreTokens(tok) ) {
      m_Device->Append( wxString( StrTokOp.nextToken(tok), wxConvUTF8 ) );
    }
    StrTokOp.base.del(tok);
  }


  m_SwTime->SetValue( wDigInt.getswtime( m_Props ) );
  m_TxSleep->SetValue( wDigInt.getpsleep( m_Props ) );

  if( wDigInt.getbps( m_Props ) == 38400 )
    m_Baudrate->SetSelection(1);
  else
    m_Baudrate->SetSelection(0);
}


void DinamoCtrlDlg::evaluate() {
  if( m_Props == NULL )
    return;
  wDigInt.setiid( m_Props, m_IID->GetValue().mb_str(wxConvUTF8) );
  wDigInt.setdevice( m_Props, m_Device->GetValue().mb_str(wxConvUTF8) );
  wDigInt.setswtime( m_Props, m_SwTime->GetValue() );
  wDigInt.setpsleep( m_Props, m_TxSleep->GetValue() );

  if( m_Baudrate->GetSelection() == 1 )
    wDigInt.setbps( m_Props, 38400 );
  else
    wDigInt.setbps( m_Props, 19200 );
}


  
/*!
 * DinamoCtrlDlg creator
 */

bool DinamoCtrlDlg::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin DinamoCtrlDlg member initialisation
    m_labIID = NULL;
    m_IID = NULL;
    m_labDevice = NULL;
    m_Device = NULL;
    m_labSwTime = NULL;
    m_SwTime = NULL;
    m_Sleep = NULL;
    m_TxSleep = NULL;
    m_Baudrate = NULL;
    m_OK = NULL;
    m_Cancel = NULL;
////@end DinamoCtrlDlg member initialisation

////@begin DinamoCtrlDlg creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end DinamoCtrlDlg creation
    return true;
}

/*!
 * Control creation for DinamoCtrlDlg
 */

void DinamoCtrlDlg::CreateControls()
{    
////@begin DinamoCtrlDlg content construction
    DinamoCtrlDlg* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxPanel* itemPanel3 = new wxPanel( itemDialog1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    itemBoxSizer2->Add(itemPanel3, 1, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxVERTICAL);
    itemPanel3->SetSizer(itemBoxSizer4);

    wxFlexGridSizer* itemFlexGridSizer5 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer4->Add(itemFlexGridSizer5, 1, wxGROW|wxALL, 5);

    m_labIID = new wxStaticText( itemPanel3, ID_STATICTEXT_DINAMO_IID, _("IID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer5->Add(m_labIID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_IID = new wxTextCtrl( itemPanel3, ID_TEXTCTRL_DINAMO_IID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer5->Add(m_IID, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labDevice = new wxStaticText( itemPanel3, ID_STATICTEXT_DINAMO_DEV, _("Device"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer5->Add(m_labDevice, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_DeviceStrings;
    m_Device = new wxComboBox( itemPanel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_DeviceStrings, wxCB_DROPDOWN );
    itemFlexGridSizer5->Add(m_Device, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labSwTime = new wxStaticText( itemPanel3, ID_STATICTEXT_DINAMO_SWTIME, _("Switch time"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer5->Add(m_labSwTime, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SwTime = new wxSpinCtrl( itemPanel3, ID_STATICTEXT_DINAMO_SWTIME, _T("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 1000, 0 );
    itemFlexGridSizer5->Add(m_SwTime, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Sleep = new wxStaticText( itemPanel3, wxID_ANY, _("Tx pause"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer5->Add(m_Sleep, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_TxSleep = new wxSpinCtrl( itemPanel3, wxID_ANY, _T("10"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 10, 100, 10 );
    itemFlexGridSizer5->Add(m_TxSleep, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer5->AddGrowableCol(1);

    wxArrayString m_BaudrateStrings;
    m_BaudrateStrings.Add(_("&19200"));
    m_BaudrateStrings.Add(_("&38400"));
    m_Baudrate = new wxRadioBox( itemPanel3, ID_BAUDRATE, _("Baudrate"), wxDefaultPosition, wxDefaultSize, m_BaudrateStrings, 1, wxRA_SPECIFY_ROWS );
    m_Baudrate->SetSelection(0);
    itemBoxSizer4->Add(m_Baudrate, 0, wxALIGN_LEFT|wxALL, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer15 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer15, 0, wxGROW|wxALL, 5);
    m_OK = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    m_OK->SetDefault();
    itemStdDialogButtonSizer15->AddButton(m_OK);

    m_Cancel = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer15->AddButton(m_Cancel);

    wxButton* itemButton18 = new wxButton( itemDialog1, wxID_HELP, _("&Help"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer15->AddButton(itemButton18);

    itemStdDialogButtonSizer15->Realize();

////@end DinamoCtrlDlg content construction
}

/*!
 * Should we show tooltips?
 */

bool DinamoCtrlDlg::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap DinamoCtrlDlg::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin DinamoCtrlDlg bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end DinamoCtrlDlg bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon DinamoCtrlDlg::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin DinamoCtrlDlg icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end DinamoCtrlDlg icon retrieval
}
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void DinamoCtrlDlg::OnOkClick( wxCommandEvent& event )
{
  evaluate();
  EndModal( wxID_OK );
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void DinamoCtrlDlg::OnCancelClick( wxCommandEvent& event )
{
  EndModal( 0 );
}



/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
 */

void DinamoCtrlDlg::OnHelpClick( wxCommandEvent& event )
{
  wxGetApp().openLink( "dinamo" );
}

