///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "rocnetdlggen.h"

///////////////////////////////////////////////////////////////////////////

rocnetdlggen::rocnetdlggen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_Nodebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_ConnectionPanel = new wxPanel( m_Nodebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer4->AddGrowableCol( 1 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labIID = new wxStaticText( m_ConnectionPanel, wxID_ANY, wxT("IID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labIID->Wrap( -1 );
	fgSizer4->Add( m_labIID, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_IID = new wxTextCtrl( m_ConnectionPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_IID, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labRocNetID = new wxStaticText( m_ConnectionPanel, wxID_ANY, wxT("Rocnet ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labRocNetID->Wrap( -1 );
	fgSizer4->Add( m_labRocNetID, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_RNID = new wxSpinCtrl( m_ConnectionPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer4->Add( m_RNID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer8->Add( fgSizer4, 0, wxEXPAND, 5 );
	
	wxString m_SublibChoices[] = { wxT("UDP"), wxT("Serial"), wxT("TCP/IP") };
	int m_SublibNChoices = sizeof( m_SublibChoices ) / sizeof( wxString );
	m_Sublib = new wxRadioBox( m_ConnectionPanel, wxID_ANY, wxT("Type"), wxDefaultPosition, wxDefaultSize, m_SublibNChoices, m_SublibChoices, 1, wxRA_SPECIFY_COLS );
	m_Sublib->SetSelection( 0 );
	bSizer8->Add( m_Sublib, 0, wxALL, 5 );
	
	m_OptionsBox = new wxStaticBoxSizer( new wxStaticBox( m_ConnectionPanel, wxID_ANY, wxT("Options") ), wxVERTICAL );
	
	m_CRC = new wxCheckBox( m_ConnectionPanel, wxID_ANY, wxT("CRC"), wxDefaultPosition, wxDefaultSize, 0 );
	m_CRC->SetValue(true); 
	m_OptionsBox->Add( m_CRC, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_Watchdog = new wxCheckBox( m_ConnectionPanel, wxID_ANY, wxT("Watchdog"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Watchdog->SetValue(true); 
	m_OptionsBox->Add( m_Watchdog, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_Sack = new wxCheckBox( m_ConnectionPanel, wxID_ANY, wxT("Secure ack"), wxDefaultPosition, wxDefaultSize, 0 );
	m_OptionsBox->Add( m_Sack, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_ShutdownAll = new wxCheckBox( m_ConnectionPanel, wxID_ANY, wxT("Shutdown all"), wxDefaultPosition, wxDefaultSize, 0 );
	m_OptionsBox->Add( m_ShutdownAll, 0, wxRIGHT|wxLEFT, 5 );
	
	m_WatchNodes = new wxCheckBox( m_ConnectionPanel, wxID_ANY, wxT("Watch nodes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_OptionsBox->Add( m_WatchNodes, 0, wxALL, 5 );
	
	bSizer8->Add( m_OptionsBox, 0, wxEXPAND|wxALL, 5 );
	
	bSizer7->Add( bSizer8, 1, 0, 5 );
	
	m_staticline1 = new wxStaticLine( m_ConnectionPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer7->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer5->AddGrowableCol( 1 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labDevice = new wxStaticText( m_ConnectionPanel, wxID_ANY, wxT("Device"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labDevice->Wrap( -1 );
	fgSizer5->Add( m_labDevice, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Device = new wxComboBox( m_ConnectionPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer5->Add( m_Device, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer9->Add( fgSizer5, 1, wxEXPAND, 5 );
	
	wxString m_BPSChoices[] = { wxT("9600"), wxT("19200"), wxT("38400"), wxT("57600"), wxT("115200"), wxT("125000") };
	int m_BPSNChoices = sizeof( m_BPSChoices ) / sizeof( wxString );
	m_BPS = new wxRadioBox( m_ConnectionPanel, wxID_ANY, wxT("BPS"), wxDefaultPosition, wxDefaultSize, m_BPSNChoices, m_BPSChoices, 2, wxRA_SPECIFY_COLS );
	m_BPS->SetSelection( 2 );
	bSizer9->Add( m_BPS, 0, wxALL, 5 );
	
	m_staticline2 = new wxStaticLine( m_ConnectionPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer6->AddGrowableCol( 1 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labAddress = new wxStaticText( m_ConnectionPanel, wxID_ANY, wxT("Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labAddress->Wrap( -1 );
	fgSizer6->Add( m_labAddress, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_Address = new wxTextCtrl( m_ConnectionPanel, wxID_ANY, wxT("224.0.0.1"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer6->Add( m_Address, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_labPort = new wxStaticText( m_ConnectionPanel, wxID_ANY, wxT("Port"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labPort->Wrap( -1 );
	fgSizer6->Add( m_labPort, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_Port = new wxSpinCtrl( m_ConnectionPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 4321 );
	fgSizer6->Add( m_Port, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer9->Add( fgSizer6, 0, wxEXPAND, 5 );
	
	m_LocoOptions = new wxStaticBoxSizer( new wxStaticBox( m_ConnectionPanel, wxID_ANY, wxT("Loco options") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer41;
	fgSizer41 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer41->AddGrowableCol( 1 );
	fgSizer41->SetFlexibleDirection( wxBOTH );
	fgSizer41->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labLocoBus = new wxStaticText( m_ConnectionPanel, wxID_ANY, wxT("Bus"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labLocoBus->Wrap( -1 );
	fgSizer41->Add( m_labLocoBus, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxRIGHT|wxLEFT, 5 );
	
	m_LocoBus = new wxSpinCtrl( m_ConnectionPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer41->Add( m_LocoBus, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_LocoOptions->Add( fgSizer41, 1, wxEXPAND, 5 );
	
	bSizer9->Add( m_LocoOptions, 1, wxEXPAND, 5 );
	
	bSizer7->Add( bSizer9, 1, 0, 5 );
	
	m_ConnectionPanel->SetSizer( bSizer7 );
	m_ConnectionPanel->Layout();
	bSizer7->Fit( m_ConnectionPanel );
	m_Nodebook->AddPage( m_ConnectionPanel, wxT("Connection"), false );
	m_NodesPanel = new wxPanel( m_Nodebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxVERTICAL );
	
	m_NodeList = new wxListCtrl( m_NodesPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL );
	bSizer61->Add( m_NodeList, 1, wxALL|wxEXPAND, 5 );
	
	m_NodesPanel->SetSizer( bSizer61 );
	m_NodesPanel->Layout();
	bSizer61->Fit( m_NodesPanel );
	m_Nodebook->AddPage( m_NodesPanel, wxT("Nodes"), false );
	
	bSizer6->Add( m_Nodebook, 0, wxEXPAND | wxALL, 5 );
	
	m_StdButton = new wxStdDialogButtonSizer();
	m_StdButtonOK = new wxButton( this, wxID_OK );
	m_StdButton->AddButton( m_StdButtonOK );
	m_StdButtonCancel = new wxButton( this, wxID_CANCEL );
	m_StdButton->AddButton( m_StdButtonCancel );
	m_StdButtonHelp = new wxButton( this, wxID_HELP );
	m_StdButton->AddButton( m_StdButtonHelp );
	m_StdButton->Realize();
	bSizer6->Add( m_StdButton, 1, wxEXPAND|wxALL, 5 );
	
	this->SetSizer( bSizer6 );
	this->Layout();
	bSizer6->Fit( this );
	
	// Connect Events
	m_Sublib->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( rocnetdlggen::OnSublib ), NULL, this );
	m_NodeList->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( rocnetdlggen::onNodeListSelected ), NULL, this );
	m_StdButtonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( rocnetdlggen::OnCancel ), NULL, this );
	m_StdButtonHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( rocnetdlggen::OnHelp ), NULL, this );
	m_StdButtonOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( rocnetdlggen::OnOK ), NULL, this );
}

rocnetdlggen::~rocnetdlggen()
{
	// Disconnect Events
	m_Sublib->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( rocnetdlggen::OnSublib ), NULL, this );
	m_NodeList->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( rocnetdlggen::onNodeListSelected ), NULL, this );
	m_StdButtonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( rocnetdlggen::OnCancel ), NULL, this );
	m_StdButtonHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( rocnetdlggen::OnHelp ), NULL, this );
	m_StdButtonOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( rocnetdlggen::OnOK ), NULL, this );
	
}
