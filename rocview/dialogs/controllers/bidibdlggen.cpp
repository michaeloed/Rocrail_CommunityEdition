///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "bidibdlggen.h"

///////////////////////////////////////////////////////////////////////////

bidibdlggen::bidibdlggen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_Notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_General = new wxPanel( m_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer5->AddGrowableCol( 1 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labIID = new wxStaticText( m_General, wxID_ANY, wxT("IID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labIID->Wrap( -1 );
	fgSizer5->Add( m_labIID, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_IID = new wxTextCtrl( m_General, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer5->Add( m_IID, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_labDevice = new wxStaticText( m_General, wxID_ANY, wxT("Device"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labDevice->Wrap( -1 );
	fgSizer5->Add( m_labDevice, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_Device = new wxComboBox( m_General, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer5->Add( m_Device, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_labHost = new wxStaticText( m_General, wxID_ANY, wxT("Host"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labHost->Wrap( -1 );
	fgSizer5->Add( m_labHost, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_Host = new wxTextCtrl( m_General, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer5->Add( m_Host, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_labPort = new wxStaticText( m_General, wxID_ANY, wxT("Port"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labPort->Wrap( -1 );
	fgSizer5->Add( m_labPort, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_Port = new wxSpinCtrl( m_General, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer5->Add( m_Port, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	bSizer6->Add( fgSizer5, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* m_SerialBox;
	m_SerialBox = new wxStaticBoxSizer( new wxStaticBox( m_General, wxID_ANY, wxT("Serial") ), wxHORIZONTAL );
	
	wxString m_BPSChoices[] = { wxT("19600"), wxT("115200"), wxT("1M") };
	int m_BPSNChoices = sizeof( m_BPSChoices ) / sizeof( wxString );
	m_BPS = new wxRadioBox( m_General, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_BPSNChoices, m_BPSChoices, 1, wxRA_SPECIFY_ROWS );
	m_BPS->SetSelection( 0 );
	m_SerialBox->Add( m_BPS, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CTS = new wxCheckBox( m_General, wxID_ANY, wxT("CTS"), wxDefaultPosition, wxDefaultSize, 0 );
	m_SerialBox->Add( m_CTS, 0, wxALIGN_BOTTOM|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	bSizer6->Add( m_SerialBox, 0, wxALL, 5 );
	
	wxString m_SubLibChoices[] = { wxT("Serial"), wxT("UDP") };
	int m_SubLibNChoices = sizeof( m_SubLibChoices ) / sizeof( wxString );
	m_SubLib = new wxRadioBox( m_General, wxID_ANY, wxT("Sub Library"), wxDefaultPosition, wxDefaultSize, m_SubLibNChoices, m_SubLibChoices, 1, wxRA_SPECIFY_ROWS );
	m_SubLib->SetSelection( 0 );
	bSizer6->Add( m_SubLib, 0, wxALL, 5 );
	
	m_General->SetSizer( bSizer6 );
	m_General->Layout();
	bSizer6->Fit( m_General );
	m_Notebook->AddPage( m_General, wxT("General"), true );
	m_Options = new wxPanel( m_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* m_SecAckBox;
	m_SecAckBox = new wxStaticBoxSizer( new wxStaticBox( m_Options, wxID_ANY, wxT("Secure ACK") ), wxVERTICAL );
	
	m_SecAck = new wxCheckBox( m_Options, wxID_ANY, wxT("Enable"), wxDefaultPosition, wxDefaultSize, 0 );
	m_SecAckBox->Add( m_SecAck, 0, wxALL, 5 );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labSecAckInt = new wxStaticText( m_Options, wxID_ANY, wxT("Interval"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labSecAckInt->Wrap( -1 );
	fgSizer6->Add( m_labSecAckInt, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_SecAckInt = new wxSpinCtrl( m_Options, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 100, 20 );
	fgSizer6->Add( m_SecAckInt, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labMs10 = new wxStaticText( m_Options, wxID_ANY, wxT("* 10ms"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labMs10->Wrap( -1 );
	fgSizer6->Add( m_labMs10, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_SecAckBox->Add( fgSizer6, 0, wxEXPAND, 5 );
	
	bSizer7->Add( m_SecAckBox, 0, wxEXPAND, 5 );
	
	m_Options->SetSizer( bSizer7 );
	m_Options->Layout();
	bSizer7->Fit( m_Options );
	m_Notebook->AddPage( m_Options, wxT("Options"), false );
	m_Nodes = new wxPanel( m_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	m_NodeList = new wxListBox( m_Nodes, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0, NULL, wxLB_SINGLE ); 
	bSizer8->Add( m_NodeList, 1, wxALL|wxEXPAND, 5 );
	
	m_ConfigureNodes = new wxButton( m_Nodes, wxID_ANY, wxT("Configure..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_ConfigureNodes, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	m_Nodes->SetSizer( bSizer8 );
	m_Nodes->Layout();
	bSizer8->Fit( m_Nodes );
	m_Notebook->AddPage( m_Nodes, wxT("Nodes"), false );
	
	bSizer5->Add( m_Notebook, 1, wxEXPAND | wxALL, 5 );
	
	m_StdButton = new wxStdDialogButtonSizer();
	m_StdButtonOK = new wxButton( this, wxID_OK );
	m_StdButton->AddButton( m_StdButtonOK );
	m_StdButtonCancel = new wxButton( this, wxID_CANCEL );
	m_StdButton->AddButton( m_StdButtonCancel );
	m_StdButtonHelp = new wxButton( this, wxID_HELP );
	m_StdButton->AddButton( m_StdButtonHelp );
	m_StdButton->Realize();
	bSizer5->Add( m_StdButton, 0, wxALL|wxALIGN_RIGHT|wxEXPAND, 5 );
	
	this->SetSizer( bSizer5 );
	this->Layout();
	bSizer5->Fit( this );
	
	// Connect Events
	m_SubLib->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( bidibdlggen::onSubLib ), NULL, this );
	m_NodeList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( bidibdlggen::OnNodeList ), NULL, this );
	m_ConfigureNodes->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( bidibdlggen::onConfigureNodes ), NULL, this );
	m_StdButtonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( bidibdlggen::OnCancel ), NULL, this );
	m_StdButtonHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( bidibdlggen::OnHelp ), NULL, this );
	m_StdButtonOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( bidibdlggen::OnOK ), NULL, this );
}

bidibdlggen::~bidibdlggen()
{
	// Disconnect Events
	m_SubLib->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( bidibdlggen::onSubLib ), NULL, this );
	m_NodeList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( bidibdlggen::OnNodeList ), NULL, this );
	m_ConfigureNodes->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( bidibdlggen::onConfigureNodes ), NULL, this );
	m_StdButtonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( bidibdlggen::OnCancel ), NULL, this );
	m_StdButtonHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( bidibdlggen::OnHelp ), NULL, this );
	m_StdButtonOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( bidibdlggen::OnOK ), NULL, this );
	
}
