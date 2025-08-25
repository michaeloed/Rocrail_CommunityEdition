///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "dcc232dlggen.h"

///////////////////////////////////////////////////////////////////////////

dcc232gen::dcc232gen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer2->AddGrowableCol( 1 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labIID = new wxStaticText( this, wxID_ANY, wxT("IID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labIID->Wrap( -1 );
	fgSizer2->Add( m_labIID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_IID = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	fgSizer2->Add( m_IID, 0, wxALL|wxEXPAND, 5 );
	
	bSizer2->Add( fgSizer2, 1, wxEXPAND|wxALL, 5 );
	
	m_PortBox = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Port") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labDevice = new wxStaticText( this, wxID_ANY, wxT("Device"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labDevice->Wrap( -1 );
	fgSizer1->Add( m_labDevice, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Device = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer1->Add( m_Device, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_PortBox->Add( fgSizer1, 1, wxEXPAND, 5 );
	
	bSizer2->Add( m_PortBox, 0, wxEXPAND|wxALL, 5 );
	
	m_SlotBox = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Slot Management") ), wxVERTICAL );
	
	m_AutoPurge = new wxCheckBox( this, wxID_ANY, wxT("Auto purging"), wxDefaultPosition, wxDefaultSize, 0 );
	m_SlotBox->Add( m_AutoPurge, 0, wxALL, 5 );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labPurgeTime = new wxStaticText( this, wxID_ANY, wxT("Purge time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labPurgeTime->Wrap( -1 );
	fgSizer3->Add( m_labPurgeTime, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_PurgeTime = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 1, 100, 10 );
	fgSizer3->Add( m_PurgeTime, 0, wxALL, 5 );
	
	m_SlotBox->Add( fgSizer3, 1, wxEXPAND, 5 );
	
	bSizer2->Add( m_SlotBox, 0, wxEXPAND|wxALL, 5 );
	
	bSizer4->Add( bSizer2, 1, wxEXPAND|wxBOTTOM, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer4->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_ShortCutBox = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Shortcut detection") ), wxVERTICAL );
	
	m_ShortcutDetection = new wxCheckBox( this, wxID_ANY, wxT("Activated"), wxDefaultPosition, wxDefaultSize, 0 );
	m_ShortCutBox->Add( m_ShortcutDetection, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_InverseDSR = new wxCheckBox( this, wxID_ANY, wxT("Inverse DSR"), wxDefaultPosition, wxDefaultSize, 0 );
	m_ShortCutBox->Add( m_InverseDSR, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labShortcutDelay = new wxStaticText( this, wxID_ANY, wxT("Delay"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labShortcutDelay->Wrap( -1 );
	fgSizer4->Add( m_labShortcutDelay, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_ShortcutDelay = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 10, 10000, 1000 );
	fgSizer4->Add( m_ShortcutDelay, 0, wxALL, 5 );
	
	m_labShortcutDelayMs = new wxStaticText( this, wxID_ANY, wxT("ms"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labShortcutDelayMs->Wrap( -1 );
	fgSizer4->Add( m_labShortcutDelayMs, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_ShortCutBox->Add( fgSizer4, 1, wxEXPAND, 5 );
	
	bSizer3->Add( m_ShortCutBox, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* m_PTBox;
	m_PTBox = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("PT") ), wxVERTICAL );
	
	m_FastCvGet = new wxCheckBox( this, wxID_ANY, wxT("Fast CV Get"), wxDefaultPosition, wxDefaultSize, 0 );
	m_PTBox->Add( m_FastCvGet, 0, wxALL, 5 );
	
	bSizer3->Add( m_PTBox, 0, wxEXPAND, 5 );
	
	bSizer4->Add( bSizer3, 1, wxEXPAND|wxBOTTOM, 5 );
	
	bSizer1->Add( bSizer4, 1, wxEXPAND, 5 );
	
	m_DefaultButtons = new wxStdDialogButtonSizer();
	m_DefaultButtonsOK = new wxButton( this, wxID_OK );
	m_DefaultButtons->AddButton( m_DefaultButtonsOK );
	m_DefaultButtonsCancel = new wxButton( this, wxID_CANCEL );
	m_DefaultButtons->AddButton( m_DefaultButtonsCancel );
	m_DefaultButtonsHelp = new wxButton( this, wxID_HELP );
	m_DefaultButtons->AddButton( m_DefaultButtonsHelp );
	m_DefaultButtons->Realize();
	bSizer1->Add( m_DefaultButtons, 0, wxALL|wxALIGN_RIGHT|wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	// Connect Events
	m_DefaultButtonsCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dcc232gen::onCancel ), NULL, this );
	m_DefaultButtonsHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dcc232gen::onHelp ), NULL, this );
	m_DefaultButtonsOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dcc232gen::onOK ), NULL, this );
}

dcc232gen::~dcc232gen()
{
	// Disconnect Events
	m_DefaultButtonsCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dcc232gen::onCancel ), NULL, this );
	m_DefaultButtonsHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dcc232gen::onHelp ), NULL, this );
	m_DefaultButtonsOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dcc232gen::onOK ), NULL, this );
	
}
