///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "donkeygen.h"

///////////////////////////////////////////////////////////////////////////

DonKeyGen::DonKeyGen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_Splash = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( m_Splash, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_DonateText = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,100 ), wxTE_MULTILINE|wxTE_READONLY );
	bSizer1->Add( m_DonateText, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labEmail = new wxStaticText( this, wxID_ANY, wxT("Email:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labEmail->Wrap( -1 );
	fgSizer1->Add( m_labEmail, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Email = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	fgSizer1->Add( m_Email, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_labExpDate = new wxStaticText( this, wxID_ANY, wxT("Expiration date:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labExpDate->Wrap( -1 );
	fgSizer1->Add( m_labExpDate, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_ExpDate = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	fgSizer1->Add( m_ExpDate, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer1->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_LoadKey = new wxButton( this, wxID_ANY, wxT("Load Key..."), wxDefaultPosition, wxDefaultSize, 0 );
	m_LoadKey->SetDefault(); 
	bSizer2->Add( m_LoadKey, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Donate = new wxButton( this, wxID_ANY, wxT("Donate now..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_Donate, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_stdButton = new wxStdDialogButtonSizer();
	m_stdButtonOK = new wxButton( this, wxID_OK );
	m_stdButton->AddButton( m_stdButtonOK );
	m_stdButtonHelp = new wxButton( this, wxID_HELP );
	m_stdButton->AddButton( m_stdButtonHelp );
	m_stdButton->Realize();
	bSizer2->Add( m_stdButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer1->Add( bSizer2, 0, wxALIGN_RIGHT, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_Splash->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( DonKeyGen::OnSplash ), NULL, this );
	m_LoadKey->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DonKeyGen::OnLoadKey ), NULL, this );
	m_Donate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DonKeyGen::OnDonateNow ), NULL, this );
	m_stdButtonHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DonKeyGen::onHelp ), NULL, this );
	m_stdButtonOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DonKeyGen::OnOK ), NULL, this );
}

DonKeyGen::~DonKeyGen()
{
	// Disconnect Events
	m_Splash->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( DonKeyGen::OnSplash ), NULL, this );
	m_LoadKey->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DonKeyGen::OnLoadKey ), NULL, this );
	m_Donate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DonKeyGen::OnDonateNow ), NULL, this );
	m_stdButtonHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DonKeyGen::onHelp ), NULL, this );
	m_stdButtonOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DonKeyGen::OnOK ), NULL, this );
	
}
