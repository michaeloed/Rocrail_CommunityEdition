///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "tracedlggen.h"

///////////////////////////////////////////////////////////////////////////

TraceDlgGen::TraceDlgGen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_labHeader = new wxStaticText( this, wxID_ANY, wxT("yyyyMMDD.HHMMSS.mmm a ID l Thread   Object   Line Message"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labHeader->Wrap( -1 );
	m_labHeader->SetFont( wxFont( 9, 76, 90, 90, false, wxEmptyString ) );
	
	bSizer1->Add( m_labHeader, 0, wxLEFT|wxRIGHT|wxTOP, 9 );
	
	m_Trace = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTE_DONTWRAP|wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH2 );
	m_Trace->SetFont( wxFont( 9, 76, 90, 90, false, wxEmptyString ) );
	m_Trace->SetMinSize( wxSize( 800,400 ) );
	
	bSizer1->Add( m_Trace, 1, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 9, 0, 0 );
	fgSizer1->AddGrowableCol( 7 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labID = new wxStaticText( this, wxID_ANY, wxT("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labID->Wrap( -1 );
	fgSizer1->Add( m_labID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_ID = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_ID->SetMaxLength( 4 ); 
	m_ID->SetMinSize( wxSize( 80,-1 ) );
	
	fgSizer1->Add( m_ID, 0, wxALL, 5 );
	
	m_labLevel = new wxStaticText( this, wxID_ANY, wxT("Level"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labLevel->Wrap( -1 );
	fgSizer1->Add( m_labLevel, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_Level = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,-1 ), 0, NULL, wxCB_READONLY ); 
	m_Level->SetMinSize( wxSize( 100,-1 ) );
	
	fgSizer1->Add( m_Level, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_labType = new wxStaticText( this, wxID_ANY, wxT("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labType->Wrap( -1 );
	fgSizer1->Add( m_labType, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_ObjectType = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	m_ObjectType->SetMinSize( wxSize( 140,-1 ) );
	
	fgSizer1->Add( m_ObjectType, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_labSearchText = new wxStaticText( this, wxID_ANY, wxT("Text"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labSearchText->Wrap( -1 );
	fgSizer1->Add( m_labSearchText, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_SearchText = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	fgSizer1->Add( m_SearchText, 0, wxALL|wxEXPAND, 5 );
	
	m_Search = new wxButton( this, wxID_ANY, wxT("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_Search, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer2->AddGrowableCol( 2 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_Open = new wxButton( this, wxID_ANY, wxT("Open..."), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_Open, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labRemote = new wxStaticText( this, wxID_ANY, wxT("Remote"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labRemote->Wrap( -1 );
	fgSizer2->Add( m_labRemote, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	wxArrayString m_ServerTracesChoices;
	m_ServerTraces = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 260,-1 ), m_ServerTracesChoices, 0 );
	m_ServerTraces->SetSelection( 0 );
	fgSizer2->Add( m_ServerTraces, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_Save = new wxButton( this, wxID_ANY, wxT("Save..."), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_Save, 0, wxALL, 5 );
	
	bSizer1->Add( fgSizer2, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer3->AddGrowableCol( 1 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labStatus = new wxStaticText( this, wxID_ANY, wxT("Status"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labStatus->Wrap( -1 );
	m_labStatus->SetFont( wxFont( 10, 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer3->Add( m_labStatus, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxLEFT, 5 );
	
	m_Status = new wxStaticText( this, wxID_ANY, wxT("..."), wxDefaultPosition, wxDefaultSize, 0 );
	m_Status->Wrap( -1 );
	m_Status->SetFont( wxFont( 10, 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer3->Add( m_Status, 0, wxEXPAND|wxTOP|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( fgSizer3, 0, wxEXPAND, 5 );
	
	m_stdButton = new wxStdDialogButtonSizer();
	m_stdButtonOK = new wxButton( this, wxID_OK );
	m_stdButton->AddButton( m_stdButtonOK );
	m_stdButtonHelp = new wxButton( this, wxID_HELP );
	m_stdButton->AddButton( m_stdButtonHelp );
	m_stdButton->Realize();
	bSizer1->Add( m_stdButton, 0, wxEXPAND|wxALL, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( TraceDlgGen::onClose ) );
	m_ID->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( TraceDlgGen::onID ), NULL, this );
	m_Level->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( TraceDlgGen::onLevel ), NULL, this );
	m_ObjectType->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( TraceDlgGen::onObjectType ), NULL, this );
	m_SearchText->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( TraceDlgGen::onText ), NULL, this );
	m_Search->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TraceDlgGen::onSearch ), NULL, this );
	m_Open->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TraceDlgGen::onOpen ), NULL, this );
	m_ServerTraces->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( TraceDlgGen::onServerTraces ), NULL, this );
	m_Save->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TraceDlgGen::onSave ), NULL, this );
	m_stdButtonHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TraceDlgGen::onHelp ), NULL, this );
	m_stdButtonOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TraceDlgGen::onOK ), NULL, this );
}

TraceDlgGen::~TraceDlgGen()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( TraceDlgGen::onClose ) );
	m_ID->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( TraceDlgGen::onID ), NULL, this );
	m_Level->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( TraceDlgGen::onLevel ), NULL, this );
	m_ObjectType->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( TraceDlgGen::onObjectType ), NULL, this );
	m_SearchText->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( TraceDlgGen::onText ), NULL, this );
	m_Search->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TraceDlgGen::onSearch ), NULL, this );
	m_Open->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TraceDlgGen::onOpen ), NULL, this );
	m_ServerTraces->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( TraceDlgGen::onServerTraces ), NULL, this );
	m_Save->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TraceDlgGen::onSave ), NULL, this );
	m_stdButtonHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TraceDlgGen::onHelp ), NULL, this );
	m_stdButtonOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TraceDlgGen::onOK ), NULL, this );
	
}
