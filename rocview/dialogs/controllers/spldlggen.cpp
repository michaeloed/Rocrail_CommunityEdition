///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "spldlggen.h"

///////////////////////////////////////////////////////////////////////////

SplDlgGen::SplDlgGen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer2->AddGrowableCol( 1 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labIID = new wxStaticText( this, wxID_ANY, wxT("IID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labIID->Wrap( -1 );
	fgSizer2->Add( m_labIID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_IID = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_IID, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( fgSizer2, 0, wxEXPAND, 5 );
	
	m_NoteBook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_SetupPanel = new wxPanel( m_NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer4->AddGrowableCol( 1 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labDevice = new wxStaticText( m_SetupPanel, wxID_ANY, wxT("Device"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labDevice->Wrap( -1 );
	fgSizer4->Add( m_labDevice, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Device = new wxComboBox( m_SetupPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, 0 ); 
	fgSizer4->Add( m_Device, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	bSizer7->Add( fgSizer4, 0, wxEXPAND, 5 );
	
	m_SetupPanel->SetSizer( bSizer7 );
	m_SetupPanel->Layout();
	bSizer7->Fit( m_SetupPanel );
	m_NoteBook->AddPage( m_SetupPanel, wxT("Setup"), false );
	m_ProgrammingPanel = new wxPanel( m_NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labAddress = new wxStaticText( m_ProgrammingPanel, wxID_ANY, wxT("Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labAddress->Wrap( -1 );
	fgSizer1->Add( m_labAddress, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_Address = new wxSpinCtrl( m_ProgrammingPanel, wxID_ANY, wxT("255"), wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 255, 255 );
	fgSizer1->Add( m_Address, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labNewAddress = new wxStaticText( m_ProgrammingPanel, wxID_ANY, wxT("New address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labNewAddress->Wrap( -1 );
	fgSizer1->Add( m_labNewAddress, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_NewAddress = new wxSpinCtrl( m_ProgrammingPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer1->Add( m_NewAddress, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer3->Add( fgSizer1, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_SetAddress = new wxButton( m_ProgrammingPanel, wxID_ANY, wxT("Set"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_SetAddress, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer3->Add( bSizer4, 0, wxALIGN_RIGHT, 5 );
	
	m_ProgrammingPanel->SetSizer( bSizer3 );
	m_ProgrammingPanel->Layout();
	bSizer3->Fit( m_ProgrammingPanel );
	m_NoteBook->AddPage( m_ProgrammingPanel, wxT("Programming"), false );
	m_ControlPanel = new wxPanel( m_NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_labAddressRange = new wxStaticText( m_ControlPanel, wxID_ANY, wxT("Address range"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labAddressRange->Wrap( -1 );
	bSizer5->Add( m_labAddressRange, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_FromAddress = new wxSpinCtrl( m_ControlPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer3->Add( m_FromAddress, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_ToAddress = new wxSpinCtrl( m_ControlPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer3->Add( m_ToAddress, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer5->Add( fgSizer3, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_8LEDs = new wxCheckBox( m_ControlPanel, wxID_ANY, wxT("8 LEDs"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_8LEDs, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_SetRange = new wxButton( m_ControlPanel, wxID_ANY, wxT("Set"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_SetRange, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer5->Add( bSizer6, 0, wxALIGN_RIGHT, 5 );
	
	m_ControlPanel->SetSizer( bSizer5 );
	m_ControlPanel->Layout();
	bSizer5->Fit( m_ControlPanel );
	m_NoteBook->AddPage( m_ControlPanel, wxT("Control"), false );
	
	bSizer1->Add( m_NoteBook, 1, wxEXPAND | wxALL, 5 );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1Help = new wxButton( this, wxID_HELP );
	m_sdbSizer1->AddButton( m_sdbSizer1Help );
	m_sdbSizer1->Realize();
	bSizer1->Add( m_sdbSizer1, 0, wxEXPAND|wxALL, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_SetAddress->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SplDlgGen::onSetAddress ), NULL, this );
	m_SetRange->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SplDlgGen::onSetRange ), NULL, this );
	m_sdbSizer1Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SplDlgGen::onCancel ), NULL, this );
	m_sdbSizer1Help->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SplDlgGen::onHelp ), NULL, this );
	m_sdbSizer1OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SplDlgGen::onOK ), NULL, this );
}

SplDlgGen::~SplDlgGen()
{
	// Disconnect Events
	m_SetAddress->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SplDlgGen::onSetAddress ), NULL, this );
	m_SetRange->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SplDlgGen::onSetRange ), NULL, this );
	m_sdbSizer1Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SplDlgGen::onCancel ), NULL, this );
	m_sdbSizer1Help->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SplDlgGen::onHelp ), NULL, this );
	m_sdbSizer1OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SplDlgGen::onOK ), NULL, this );
	
}
