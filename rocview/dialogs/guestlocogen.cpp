///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "guestlocogen.h"

///////////////////////////////////////////////////////////////////////////

GuestLocoGen::GuestLocoGen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labAddress = new wxStaticText( this, wxID_ANY, wxT("Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labAddress->Wrap( -1 );
	fgSizer1->Add( m_labAddress, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Address = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer1->Add( m_Address, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_labShortID = new wxStaticText( this, wxID_ANY, wxT("Short ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labShortID->Wrap( -1 );
	fgSizer1->Add( m_labShortID, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_ShortID = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_ShortID->SetMinSize( wxSize( 120,-1 ) );
	
	fgSizer1->Add( m_ShortID, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer1->Add( fgSizer1, 1, wxEXPAND, 5 );
	
	wxString m_SpeedstepsChoices[] = { wxT("14"), wxT("28"), wxT("128") };
	int m_SpeedstepsNChoices = sizeof( m_SpeedstepsChoices ) / sizeof( wxString );
	m_Speedsteps = new wxRadioBox( this, wxID_ANY, wxT("Speed steps"), wxDefaultPosition, wxDefaultSize, m_SpeedstepsNChoices, m_SpeedstepsChoices, 1, wxRA_SPECIFY_ROWS );
	m_Speedsteps->SetSelection( 2 );
	bSizer1->Add( m_Speedsteps, 0, wxALL, 5 );
	
	wxString m_ProtocolChoices[] = { wxT("Default"), wxT("DCC"), wxT("MM") };
	int m_ProtocolNChoices = sizeof( m_ProtocolChoices ) / sizeof( wxString );
	m_Protocol = new wxRadioBox( this, wxID_ANY, wxT("Protocol"), wxDefaultPosition, wxDefaultSize, m_ProtocolNChoices, m_ProtocolChoices, 1, wxRA_SPECIFY_ROWS );
	m_Protocol->SetSelection( 0 );
	bSizer1->Add( m_Protocol, 0, wxALL, 5 );
	
	m_StdButton = new wxStdDialogButtonSizer();
	m_StdButtonOK = new wxButton( this, wxID_OK );
	m_StdButton->AddButton( m_StdButtonOK );
	m_StdButtonCancel = new wxButton( this, wxID_CANCEL );
	m_StdButton->AddButton( m_StdButtonCancel );
	m_StdButtonHelp = new wxButton( this, wxID_HELP );
	m_StdButton->AddButton( m_StdButtonHelp );
	m_StdButton->Realize();
	bSizer1->Add( m_StdButton, 0, wxALL|wxALIGN_RIGHT|wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_StdButtonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GuestLocoGen::onCancel ), NULL, this );
	m_StdButtonHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GuestLocoGen::onHelp ), NULL, this );
	m_StdButtonOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GuestLocoGen::onOK ), NULL, this );
}

GuestLocoGen::~GuestLocoGen()
{
	// Disconnect Events
	m_StdButtonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GuestLocoGen::onCancel ), NULL, this );
	m_StdButtonHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GuestLocoGen::onHelp ), NULL, this );
	m_StdButtonOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GuestLocoGen::onOK ), NULL, this );
	
}
