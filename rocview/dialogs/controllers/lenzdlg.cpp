/*
 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 

 */
#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "lenzdlg.h"
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

#include "lenzdlg.h"

////@begin XPM images
////@end XPM images

#include "rocview/public/guiapp.h"
#include "rocrail/wrapper/public/DigInt.h"
#include "rocs/public/strtok.h"

/*!
 * LenzDlg type definition
 */

IMPLEMENT_DYNAMIC_CLASS( LenzDlg, wxDialog )


/*!
 * LenzDlg event table definition
 */

BEGIN_EVENT_TABLE( LenzDlg, wxDialog )

////@begin LenzDlg event table entries
    EVT_RADIOBOX( ID_LENZTYPE, LenzDlg::OnLenztypeSelected )
    EVT_BUTTON( wxID_OK, LenzDlg::OnOkClick )
    EVT_BUTTON( wxID_CANCEL, LenzDlg::OnCancelClick )
    EVT_BUTTON( wxID_HELP, LenzDlg::OnHelpClick )
////@end LenzDlg event table entries

END_EVENT_TABLE()


/*!
 * LenzDlg constructors
 */

LenzDlg::LenzDlg()
{
    Init();
}

LenzDlg::LenzDlg( wxWindow* parent, iONode props, const char* devices )
{
    Init();
    Create(parent, -1, _T("XpressNet"));

    m_Props = props;
    m_Devices = devices;
    initLabels();
    initValues();

    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);

    GetSizer()->Layout();
}

void LenzDlg::initLabels() {
  m_labIID->SetLabel( wxGetApp().getMsg( "iid" ) );
  m_labDevice->SetLabel( wxGetApp().getMsg( "device" ) );
  m_labHost->SetLabel( wxGetApp().getMsg( "host" ) );
  m_labPort->SetLabel( wxGetApp().getMsg( "port" ) );
  m_Type->SetLabel( wxGetApp().getMsg( "type" ) );
  m_BPS->SetLabel( wxGetApp().getMsg( "bps" ) );
  m_labSwitchTime->SetLabel( wxGetApp().getMsg( "switchtime" ) );
  m_labPower->SetLabel( wxGetApp().getMsg( "options" ) );
  m_PowerAtStartup->SetLabel( wxGetApp().getMsg( "poweronstartup" ) );
  m_FastClock->SetLabel( wxGetApp().getMsg( "fastclock" ) );
  m_HardwareFlow->SetLabel( wxGetApp().getMsg( "ctsflow" ) );
  m_AccPower->SetLabel( wxGetApp().getMsg( "power4acc" ) );
}

void LenzDlg::initValues() {
  m_IID->SetValue( wxString( wDigInt.getiid( m_Props ), wxConvUTF8 ) );
  m_Device->SetValue( wxString( wDigInt.getdevice( m_Props ), wxConvUTF8 ) );
  if( m_Devices != NULL ) {
    iOStrTok tok = StrTokOp.inst(m_Devices, ',');
    while( StrTokOp.hasMoreTokens(tok) ) {
      m_Device->Append( wxString( StrTokOp.nextToken(tok), wxConvUTF8 ) );
    }
    StrTokOp.base.del(tok);
  }

  m_Host->SetValue( wxString( wDigInt.gethost( m_Props ), wxConvUTF8 ) );
  m_Port->SetValue( wDigInt.getport(m_Props));

  if( StrOp.equals( wDigInt.sublib_usb, wDigInt.getsublib(m_Props) )) {
    m_Type->SetSelection(1);
    wDigInt.setbps( m_Props, 57600);
    m_BPS->Enable(false);
  }
  else if( StrOp.equals( wDigInt.sublib_lenz_elite, wDigInt.getsublib(m_Props) ))
    m_Type->SetSelection(2);
  else if( StrOp.equals( wDigInt.sublib_lenz_opendcc, wDigInt.getsublib(m_Props) ))
    m_Type->SetSelection(3);
  else if( StrOp.equals( wDigInt.sublib_lenz_xntcp, wDigInt.getsublib(m_Props) ))
    m_Type->SetSelection(4);
  else if( StrOp.equals( wDigInt.sublib_lenz_cttran, wDigInt.getsublib(m_Props) ))
    m_Type->SetSelection(5);
  else if( StrOp.equals( wDigInt.sublib_lenz_ethernet, wDigInt.getsublib(m_Props) ))
    m_Type->SetSelection(6);
  else
    m_Type->SetSelection(0);

  if( m_Type->GetSelection() == 4 || m_Type->GetSelection() == 6 ) {
    m_BPS->Enable(false);
    m_HardwareFlow->Enable(false);
  }


  m_SwitchTime->SetValue( wDigInt.getswtime(m_Props));
  m_PowerAtStartup->SetValue( wDigInt.isstartpwstate(m_Props)?true:false);
  m_FastClock->SetValue( wDigInt.isfastclock(m_Props)?true:false);
  m_AccPower->SetValue( wDigInt.ispw4acc(m_Props)?true:false);
  m_V2->SetValue( wDigInt.getprotver(m_Props) > 0 ? true:false);

  if( wDigInt.getbps( m_Props ) == 9600 )
    m_BPS->SetSelection(0);
  else if( wDigInt.getbps( m_Props ) == 19200 )
    m_BPS->SetSelection(1);
  else if( wDigInt.getbps( m_Props ) == 38400 )
    m_BPS->SetSelection(2);
  else if( wDigInt.getbps( m_Props ) == 57600 )
    m_BPS->SetSelection(3);
  else if( wDigInt.getbps( m_Props ) == 115200 )
    m_BPS->SetSelection(4);
  else
    m_BPS->SetSelection(1);

  if( StrOp.equals( wDigInt.cts, wDigInt.getflow(m_Props) ) )
    m_HardwareFlow->SetSelection(1);
  else
    m_HardwareFlow->SetSelection(0);

}

void LenzDlg::evaluate() {
  if( m_Props == NULL )
    return;
  wDigInt.setiid( m_Props, m_IID->GetValue().mb_str(wxConvUTF8) );
  wDigInt.setdevice( m_Props, m_Device->GetValue().mb_str(wxConvUTF8) );
  wDigInt.sethost( m_Props, m_Host->GetValue().mb_str(wxConvUTF8) );
  wDigInt.setport( m_Props, m_Port->GetValue() );
  wDigInt.setswtime( m_Props, m_SwitchTime->GetValue() );
  wDigInt.setstartpwstate(m_Props, m_PowerAtStartup->IsChecked()?True:False);
  wDigInt.setfastclock(m_Props, m_FastClock->IsChecked()?True:False);
  wDigInt.setpw4acc(m_Props, m_AccPower->IsChecked()?True:False);

  if( m_Type->GetSelection() == 2 ) // Elite
    wDigInt.setprotver(m_Props, m_V2->IsChecked()?1:0);
  else
    wDigInt.setprotver(m_Props, m_V2->IsChecked()?2:0);

  if( m_Type->GetSelection() == 1 )
    wDigInt.setsublib(m_Props, wDigInt.sublib_usb );
  else if( m_Type->GetSelection() == 2 )
    wDigInt.setsublib(m_Props, wDigInt.sublib_lenz_elite );
  else if( m_Type->GetSelection() == 3 )
    wDigInt.setsublib(m_Props, wDigInt.sublib_lenz_opendcc );
  else if( m_Type->GetSelection() == 4 )
    wDigInt.setsublib(m_Props, wDigInt.sublib_lenz_xntcp );
  else if( m_Type->GetSelection() == 5 )
    wDigInt.setsublib(m_Props, wDigInt.sublib_lenz_cttran );
  else if( m_Type->GetSelection() == 6 )
    wDigInt.setsublib(m_Props, wDigInt.sublib_lenz_ethernet );
  else
    wDigInt.setsublib(m_Props, wDigInt.sublib_default );


  if( m_BPS->GetSelection() == 0 )
    wDigInt.setbps( m_Props, 9600 );
  else if( m_BPS->GetSelection() == 1 )
    wDigInt.setbps( m_Props, 19200 );
  else if( m_BPS->GetSelection() == 2 )
    wDigInt.setbps( m_Props, 38400 );
  else if( m_BPS->GetSelection() == 3 )
    wDigInt.setbps( m_Props, 57600 );
  else if( m_BPS->GetSelection() == 4 )
    wDigInt.setbps( m_Props, 115200 );

  if( m_HardwareFlow->GetSelection() == 0 )
    wDigInt.setflow(m_Props, wDigInt.none );
  else
    wDigInt.setflow(m_Props, wDigInt.cts );

}



/*!
 * LenzDlg creator
 */

bool LenzDlg::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin LenzDlg creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end LenzDlg creation
    return true;
}


/*!
 * LenzDlg destructor
 */

LenzDlg::~LenzDlg()
{
////@begin LenzDlg destruction
////@end LenzDlg destruction
}


/*!
 * Member initialisation
 */

void LenzDlg::Init()
{
////@begin LenzDlg member initialisation
    m_MainPanel = NULL;
    m_labIID = NULL;
    m_IID = NULL;
    m_labDevice = NULL;
    m_Device = NULL;
    m_labHost = NULL;
    m_Host = NULL;
    m_labPort = NULL;
    m_Port = NULL;
    m_BPS = NULL;
    m_HardwareFlow = NULL;
    m_Type = NULL;
    m_labPower = NULL;
    m_PowerAtStartup = NULL;
    m_FastClock = NULL;
    m_AccPower = NULL;
    m_V2 = NULL;
    m_labSwitchTime = NULL;
    m_SwitchTime = NULL;
////@end LenzDlg member initialisation
}


/*!
 * Control creation for LenzDlg
 */

void LenzDlg::CreateControls()
{
////@begin LenzDlg content construction
    LenzDlg* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    m_MainPanel = new wxPanel( itemDialog1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    itemBoxSizer2->Add(m_MainPanel, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    m_MainPanel->SetSizer(itemBoxSizer4);

    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer4->Add(itemBoxSizer5, 0, wxALIGN_TOP|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer6 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer5->Add(itemFlexGridSizer6, 0, wxGROW, 5);

    m_labIID = new wxStaticText( m_MainPanel, wxID_ANY, _("IID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_labIID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_IID = new wxTextCtrl( m_MainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1), 0 );
    itemFlexGridSizer6->Add(m_IID, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labDevice = new wxStaticText( m_MainPanel, wxID_ANY, _("Device"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_labDevice, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxArrayString m_DeviceStrings;
    m_Device = new wxComboBox( m_MainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_DeviceStrings, wxCB_DROPDOWN );
    itemFlexGridSizer6->Add(m_Device, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labHost = new wxStaticText( m_MainPanel, wxID_ANY, _("Host"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_labHost, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_Host = new wxTextCtrl( m_MainPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1), 0 );
    itemFlexGridSizer6->Add(m_Host, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labPort = new wxStaticText( m_MainPanel, wxID_ANY, _("Port"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_labPort, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_Port = new wxSpinCtrl( m_MainPanel, wxID_ANY, _T("0"), wxDefaultPosition, wxSize(120, -1), wxSP_ARROW_KEYS, 0, 65535, 0 );
    itemFlexGridSizer6->Add(m_Port, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemFlexGridSizer6->AddGrowableCol(1);

    wxArrayString m_BPSStrings;
    m_BPSStrings.Add(_("&9600"));
    m_BPSStrings.Add(_("&19200"));
    m_BPSStrings.Add(_("&38400"));
    m_BPSStrings.Add(_("&57600"));
    m_BPSStrings.Add(_("&115200"));
    m_BPS = new wxRadioBox( m_MainPanel, wxID_ANY, _("BPS"), wxDefaultPosition, wxDefaultSize, m_BPSStrings, 2, wxRA_SPECIFY_ROWS );
    m_BPS->SetSelection(0);
    itemBoxSizer5->Add(m_BPS, 0, wxALIGN_LEFT|wxALL, 5);

    wxArrayString m_HardwareFlowStrings;
    m_HardwareFlowStrings.Add(_("&None"));
    m_HardwareFlowStrings.Add(_("&CTS"));
    m_HardwareFlow = new wxRadioBox( m_MainPanel, wxID_ANY, _("Hardware Flow"), wxDefaultPosition, wxDefaultSize, m_HardwareFlowStrings, 2, wxRA_SPECIFY_COLS );
    m_HardwareFlow->SetSelection(0);
    itemBoxSizer5->Add(m_HardwareFlow, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxBoxSizer* itemBoxSizer17 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer4->Add(itemBoxSizer17, 0, wxALIGN_TOP|wxALL, 5);

    wxArrayString m_TypeStrings;
    m_TypeStrings.Add(_("&LI101F"));
    m_TypeStrings.Add(_("&LI-USB"));
    m_TypeStrings.Add(_("&Elite"));
    m_TypeStrings.Add(_("&OpenDCC"));
    m_TypeStrings.Add(_("&XnTcp"));
    m_TypeStrings.Add(_("&CtTran"));
    m_TypeStrings.Add(_("&LI-ETH"));
    m_Type = new wxRadioBox( m_MainPanel, ID_LENZTYPE, _("SubType"), wxDefaultPosition, wxDefaultSize, m_TypeStrings, 2, wxRA_SPECIFY_ROWS );
    m_Type->SetSelection(0);
    itemBoxSizer17->Add(m_Type, 0, wxALIGN_LEFT|wxALL, 5);

    m_labPower = new wxStaticBox(m_MainPanel, wxID_ANY, _("Options"));
    wxStaticBoxSizer* itemStaticBoxSizer19 = new wxStaticBoxSizer(m_labPower, wxVERTICAL);
    itemBoxSizer17->Add(itemStaticBoxSizer19, 0, wxALIGN_LEFT|wxALL, 5);

    m_PowerAtStartup = new wxCheckBox( m_MainPanel, wxID_ANY, _("Power on at startup"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PowerAtStartup->SetValue(false);
    itemStaticBoxSizer19->Add(m_PowerAtStartup, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 5);

    m_FastClock = new wxCheckBox( m_MainPanel, wxID_ANY, _("Support fast clock"), wxDefaultPosition, wxDefaultSize, 0 );
    m_FastClock->SetValue(false);
    itemStaticBoxSizer19->Add(m_FastClock, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_AccPower = new wxCheckBox( m_MainPanel, wxID_ANY, _("Power on for accessors commands"), wxDefaultPosition, wxDefaultSize, 0 );
    m_AccPower->SetValue(true);
    itemStaticBoxSizer19->Add(m_AccPower, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_V2 = new wxCheckBox( m_MainPanel, wxID_ANY, _("V2"), wxDefaultPosition, wxDefaultSize, 0 );
    m_V2->SetValue(false);
    itemStaticBoxSizer19->Add(m_V2, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxFlexGridSizer* itemFlexGridSizer24 = new wxFlexGridSizer(0, 2, 0, 0);
    itemStaticBoxSizer19->Add(itemFlexGridSizer24, 0, wxALIGN_LEFT, 5);

    m_labSwitchTime = new wxStaticText( m_MainPanel, wxID_ANY, _("Switch time (ms)"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer24->Add(m_labSwitchTime, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_SwitchTime = new wxSpinCtrl( m_MainPanel, wxID_ANY, _T("250"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 0, 1000, 250 );
    itemFlexGridSizer24->Add(m_SwitchTime, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    itemFlexGridSizer24->AddGrowableCol(1);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer27 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer27, 0, wxGROW|wxALL, 5);
    wxButton* itemButton28 = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer27->AddButton(itemButton28);

    wxButton* itemButton29 = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer27->AddButton(itemButton29);

    wxButton* itemButton30 = new wxButton( itemDialog1, wxID_HELP, _("&Help"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer27->AddButton(itemButton30);

    itemStdDialogButtonSizer27->Realize();

////@end LenzDlg content construction
}


/*!
 * Should we show tooltips?
 */

bool LenzDlg::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap LenzDlg::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin LenzDlg bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end LenzDlg bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon LenzDlg::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin LenzDlg icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end LenzDlg icon retrieval
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void LenzDlg::OnOkClick( wxCommandEvent& event )
{
  evaluate();
  EndModal( wxID_OK );
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void LenzDlg::OnCancelClick( wxCommandEvent& event )
{
  EndModal( 0 );
}


/*!
 * wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_LENZTYPE
 */

void LenzDlg::OnLenztypeSelected( wxCommandEvent& event )
{
  if( m_Type->GetSelection() == 1 ) {
    m_BPS->SetSelection(3);
    m_BPS->Enable(false);
    m_HardwareFlow->Enable(true);
    return;
  }

  if( m_Type->GetSelection() == 4 || m_Type->GetSelection() == 6 ) {
    m_BPS->Enable(false);
    m_HardwareFlow->Enable(false);
    return;
  }

  m_BPS->Enable(true);
  m_HardwareFlow->Enable(true);
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
 */

void LenzDlg::OnHelpClick( wxCommandEvent& event )
{
  if( StrOp.equals( wDigInt.xpressnet, wDigInt.getlib( m_Props ) ) )
    wxGetApp().openLink( "xpressnet" );
}

