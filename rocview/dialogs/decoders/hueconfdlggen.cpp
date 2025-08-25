///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "hueconfdlggen.h"

///////////////////////////////////////////////////////////////////////////

HueConfDlgGen::HueConfDlgGen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer5->AddGrowableCol( 0 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer17;
	fgSizer17 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer17->AddGrowableCol( 1 );
	fgSizer17->SetFlexibleDirection( wxBOTH );
	fgSizer17->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labIID = new wxStaticText( this, wxID_ANY, wxT("IID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labIID->Wrap( -1 );
	fgSizer17->Add( m_labIID, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_IID = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer17->Add( m_IID, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	fgSizer5->Add( fgSizer17, 0, wxEXPAND, 5 );
	
	m_HueLogo = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer5->Add( m_HueLogo, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer9->Add( fgSizer5, 0, wxEXPAND, 5 );
	
	m_HueBook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_BridgePanel = new wxPanel( m_HueBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer18;
	fgSizer18 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer18->AddGrowableCol( 1 );
	fgSizer18->SetFlexibleDirection( wxBOTH );
	fgSizer18->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labBridgeName = new wxStaticText( m_BridgePanel, wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labBridgeName->Wrap( -1 );
	fgSizer18->Add( m_labBridgeName, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxFlexGridSizer* fgSizer19;
	fgSizer19 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer19->AddGrowableCol( 0 );
	fgSizer19->SetFlexibleDirection( wxBOTH );
	fgSizer19->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_BridgeName = new wxTextCtrl( m_BridgePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_BridgeName->SetMaxLength( 16 ); 
	fgSizer19->Add( m_BridgeName, 0, wxALL|wxEXPAND, 5 );
	
	m_SetBridgeName = new wxButton( m_BridgePanel, wxID_ANY, wxT("Set"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer19->Add( m_SetBridgeName, 0, wxALL, 5 );
	
	fgSizer18->Add( fgSizer19, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labBridgeIP = new wxStaticText( m_BridgePanel, wxID_ANY, wxT("IP"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labBridgeIP->Wrap( -1 );
	fgSizer18->Add( m_labBridgeIP, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_BridgeIP = new wxTextCtrl( m_BridgePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	fgSizer18->Add( m_BridgeIP, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labBridgeFirmware = new wxStaticText( m_BridgePanel, wxID_ANY, wxT("Firmware"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labBridgeFirmware->Wrap( -1 );
	fgSizer18->Add( m_labBridgeFirmware, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_BridgeFirmware = new wxTextCtrl( m_BridgePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	fgSizer18->Add( m_BridgeFirmware, 0, wxALL, 5 );
	
	m_labBridgeAPI = new wxStaticText( m_BridgePanel, wxID_ANY, wxT("API"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labBridgeAPI->Wrap( -1 );
	fgSizer18->Add( m_labBridgeAPI, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_BridgeAPI = new wxTextCtrl( m_BridgePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	fgSizer18->Add( m_BridgeAPI, 0, wxALL, 5 );
	
	m_labBridgeZigbee = new wxStaticText( m_BridgePanel, wxID_ANY, wxT("ZigBee"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labBridgeZigbee->Wrap( -1 );
	fgSizer18->Add( m_labBridgeZigbee, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_BridgeZigbee = new wxTextCtrl( m_BridgePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	fgSizer18->Add( m_BridgeZigbee, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labBridgeUserName = new wxStaticText( m_BridgePanel, wxID_ANY, wxT("User name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labBridgeUserName->Wrap( -1 );
	fgSizer18->Add( m_labBridgeUserName, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxFlexGridSizer* fgSizer20;
	fgSizer20 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer20->AddGrowableCol( 0 );
	fgSizer20->SetFlexibleDirection( wxBOTH );
	fgSizer20->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_BridgeUserName = new wxComboBox( m_BridgePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer20->Add( m_BridgeUserName, 0, wxRIGHT|wxLEFT|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_SetBridgeUserName = new wxButton( m_BridgePanel, wxID_ANY, wxT("Set"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer20->Add( m_SetBridgeUserName, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	fgSizer18->Add( fgSizer20, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer12->Add( fgSizer18, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	m_GetBridge = new wxButton( m_BridgePanel, wxID_ANY, wxT("Get"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_GetBridge, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer12->Add( bSizer13, 0, wxTOP, 5 );
	
	m_BridgePanel->SetSizer( bSizer12 );
	m_BridgePanel->Layout();
	bSizer12->Fit( m_BridgePanel );
	m_HueBook->AddPage( m_BridgePanel, wxT("Bridge"), false );
	m_LightsPanel = new wxPanel( m_HueBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	m_LightsGrid = new wxGrid( m_LightsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	
	// Grid
	m_LightsGrid->CreateGrid( 5, 5 );
	m_LightsGrid->EnableEditing( true );
	m_LightsGrid->EnableGridLines( true );
	m_LightsGrid->EnableDragGridSize( false );
	m_LightsGrid->SetMargins( 0, 0 );
	
	// Columns
	m_LightsGrid->EnableDragColMove( false );
	m_LightsGrid->EnableDragColSize( true );
	m_LightsGrid->SetColLabelSize( 30 );
	m_LightsGrid->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_LightsGrid->EnableDragRowSize( true );
	m_LightsGrid->SetRowLabelSize( 0 );
	m_LightsGrid->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_LightsGrid->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer10->Add( m_LightsGrid, 1, wxALL|wxEXPAND, 5 );
	
	m_labChangedLight = new wxStaticText( m_LightsPanel, wxID_ANY, wxT("..."), wxDefaultPosition, wxDefaultSize, 0 );
	m_labChangedLight->Wrap( -1 );
	bSizer10->Add( m_labChangedLight, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_GetLights = new wxButton( m_LightsPanel, wxID_ANY, wxT("Get"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_GetLights, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_FindLights = new wxButton( m_LightsPanel, wxID_ANY, wxT("Find"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_FindLights, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_SetLight = new wxButton( m_LightsPanel, wxID_ANY, wxT("Set"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_SetLight, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_LightOn = new wxButton( m_LightsPanel, wxID_ANY, wxT("On"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_LightOn, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_LightOff = new wxButton( m_LightsPanel, wxID_ANY, wxT("Off"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_LightOff, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer10->Add( bSizer11, 0, wxEXPAND, 5 );
	
	m_Brightness = new wxSlider( m_LightsPanel, wxID_ANY, 50, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_HORIZONTAL|wxSL_LABELS );
	bSizer10->Add( m_Brightness, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_LightsPanel->SetSizer( bSizer10 );
	m_LightsPanel->Layout();
	bSizer10->Fit( m_LightsPanel );
	m_HueBook->AddPage( m_LightsPanel, wxT("Lights"), false );
	
	bSizer9->Add( m_HueBook, 1, wxEXPAND | wxALL, 5 );
	
	m_stdButtons = new wxStdDialogButtonSizer();
	m_stdButtonsOK = new wxButton( this, wxID_OK );
	m_stdButtons->AddButton( m_stdButtonsOK );
	m_stdButtonsHelp = new wxButton( this, wxID_HELP );
	m_stdButtons->AddButton( m_stdButtonsHelp );
	m_stdButtons->Realize();
	bSizer9->Add( m_stdButtons, 0, wxEXPAND|wxALL, 5 );
	
	this->SetSizer( bSizer9 );
	this->Layout();
	bSizer9->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( HueConfDlgGen::onClose ) );
	m_SetBridgeName->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onBridgeNameSet ), NULL, this );
	m_SetBridgeUserName->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onSetBridgeUserName ), NULL, this );
	m_GetBridge->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onBridgeGet ), NULL, this );
	m_LightsGrid->Connect( wxEVT_GRID_CELL_CHANGED, wxGridEventHandler( HueConfDlgGen::onLightCellChange ), NULL, this );
	m_LightsGrid->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( HueConfDlgGen::onLightCellDClick ), NULL, this );
	m_LightsGrid->Connect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( HueConfDlgGen::onLightCellSelect ), NULL, this );
	m_GetLights->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onGetLights ), NULL, this );
	m_FindLights->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onFindLights ), NULL, this );
	m_SetLight->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onLightSet ), NULL, this );
	m_LightOn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onLightOn ), NULL, this );
	m_LightOff->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onLightOff ), NULL, this );
	m_Brightness->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( HueConfDlgGen::onBrightness ), NULL, this );
	m_Brightness->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( HueConfDlgGen::onBrightness ), NULL, this );
	m_Brightness->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( HueConfDlgGen::onBrightness ), NULL, this );
	m_Brightness->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( HueConfDlgGen::onBrightness ), NULL, this );
	m_Brightness->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( HueConfDlgGen::onBrightness ), NULL, this );
	m_Brightness->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( HueConfDlgGen::onBrightness ), NULL, this );
	m_Brightness->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( HueConfDlgGen::onBrightness ), NULL, this );
	m_Brightness->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( HueConfDlgGen::onBrightness ), NULL, this );
	m_Brightness->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( HueConfDlgGen::onBrightness ), NULL, this );
	m_Brightness->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( HueConfDlgGen::onBrightnessThumbRelease ), NULL, this );
	m_stdButtonsHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onHelp ), NULL, this );
	m_stdButtonsOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onOK ), NULL, this );
}

HueConfDlgGen::~HueConfDlgGen()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( HueConfDlgGen::onClose ) );
	m_SetBridgeName->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onBridgeNameSet ), NULL, this );
	m_SetBridgeUserName->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onSetBridgeUserName ), NULL, this );
	m_GetBridge->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onBridgeGet ), NULL, this );
	m_LightsGrid->Disconnect( wxEVT_GRID_CELL_CHANGED, wxGridEventHandler( HueConfDlgGen::onLightCellChange ), NULL, this );
	m_LightsGrid->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( HueConfDlgGen::onLightCellDClick ), NULL, this );
	m_LightsGrid->Disconnect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( HueConfDlgGen::onLightCellSelect ), NULL, this );
	m_GetLights->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onGetLights ), NULL, this );
	m_FindLights->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onFindLights ), NULL, this );
	m_SetLight->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onLightSet ), NULL, this );
	m_LightOn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onLightOn ), NULL, this );
	m_LightOff->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onLightOff ), NULL, this );
	m_Brightness->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( HueConfDlgGen::onBrightness ), NULL, this );
	m_Brightness->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( HueConfDlgGen::onBrightness ), NULL, this );
	m_Brightness->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( HueConfDlgGen::onBrightness ), NULL, this );
	m_Brightness->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( HueConfDlgGen::onBrightness ), NULL, this );
	m_Brightness->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( HueConfDlgGen::onBrightness ), NULL, this );
	m_Brightness->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( HueConfDlgGen::onBrightness ), NULL, this );
	m_Brightness->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( HueConfDlgGen::onBrightness ), NULL, this );
	m_Brightness->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( HueConfDlgGen::onBrightness ), NULL, this );
	m_Brightness->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( HueConfDlgGen::onBrightness ), NULL, this );
	m_Brightness->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( HueConfDlgGen::onBrightnessThumbRelease ), NULL, this );
	m_stdButtonsHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onHelp ), NULL, this );
	m_stdButtonsOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HueConfDlgGen::onOK ), NULL, this );
	
}
