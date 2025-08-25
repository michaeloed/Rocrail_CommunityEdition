///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "dtopswdlggen.h"

///////////////////////////////////////////////////////////////////////////

dtopswdlg::dtopswdlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Board") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer2->AddGrowableCol( 1 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labIID = new wxStaticText( this, wxID_ANY, wxT("IID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labIID->Wrap( -1 );
	fgSizer2->Add( m_labIID, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_IID = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_IID, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_labBoardNumber = new wxStaticText( this, wxID_ANY, wxT("Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labBoardNumber->Wrap( -1 );
	fgSizer2->Add( m_labBoardNumber, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_BoardNumber = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 65,-1 ), wxSP_ARROW_KEYS, 1, 999, 0 );
	fgSizer2->Add( m_BoardNumber, 0, wxALL, 5 );
	
	m_labBoardType = new wxStaticText( this, wxID_ANY, wxT("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labBoardType->Wrap( -1 );
	fgSizer2->Add( m_labBoardType, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_BoardType = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer2->Add( m_BoardType, 0, wxALL, 5 );
	
	sbSizer1->Add( fgSizer2, 0, wxEXPAND, 5 );
	
	bSizer1->Add( sbSizer1, 0, wxEXPAND|wxALL, 5 );
	
	m_labOpSw = new wxStaticText( this, wxID_ANY, wxT("Option Switches"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labOpSw->Wrap( -1 );
	bSizer1->Add( m_labOpSw, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxString m_OpSwListChoices[] = { wxT("No Option Switches available") };
	int m_OpSwListNChoices = sizeof( m_OpSwListChoices ) / sizeof( wxString );
	m_OpSwList = new wxCheckListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 400,250 ), m_OpSwListNChoices, m_OpSwListChoices, wxLB_NEEDED_SB );
	bSizer1->Add( m_OpSwList, 1, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_ReadAll = new wxButton( this, wxID_ANY, wxT("Read All"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_ReadAll, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_WriteAll = new wxButton( this, wxID_ANY, wxT("Write All"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_WriteAll, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	bSizer1->Add( fgSizer1, 0, wxALIGN_RIGHT, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( this, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Help = new wxButton( this, wxID_HELP );
	m_sdbSizer1->AddButton( m_sdbSizer1Help );
	m_sdbSizer1->Realize();
	bSizer1->Add( m_sdbSizer1, 0, wxALL|wxALIGN_RIGHT|wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_BoardType->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( dtopswdlg::onBoardType ), NULL, this );
	m_ReadAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dtopswdlg::onReadAll ), NULL, this );
	m_WriteAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dtopswdlg::onWriteAll ), NULL, this );
	m_sdbSizer1Help->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dtopswdlg::onHelp ), NULL, this );
	m_sdbSizer1OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dtopswdlg::onOK ), NULL, this );
}

dtopswdlg::~dtopswdlg()
{
	// Disconnect Events
	m_BoardType->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( dtopswdlg::onBoardType ), NULL, this );
	m_ReadAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dtopswdlg::onReadAll ), NULL, this );
	m_WriteAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dtopswdlg::onWriteAll ), NULL, this );
	m_sdbSizer1Help->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dtopswdlg::onHelp ), NULL, this );
	m_sdbSizer1OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( dtopswdlg::onOK ), NULL, this );
	
}
