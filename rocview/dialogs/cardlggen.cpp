///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "basenotebook.h"

#include "cardlggen.h"

///////////////////////////////////////////////////////////////////////////

cardlggen::cardlggen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_CarImage = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( -1,90 ), wxBU_AUTODRAW );
	bSizer1->Add( m_CarImage, 0, wxTOP|wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	m_CarBook = new basenotebook( this, ID_CARBOOK, wxDefaultPosition, wxDefaultSize, 0 );
	m_IndexPanel = new wxPanel( m_CarBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_CarList2 = new wxListCtrl( m_IndexPanel, wxID_ANY, wxDefaultPosition, wxSize( -1,200 ), wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL|wxHSCROLL|wxSIMPLE_BORDER );
	bSizer2->Add( m_CarList2, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer9;
	fgSizer9 = new wxFlexGridSizer( 0, 6, 0, 0 );
	fgSizer9->SetFlexibleDirection( wxBOTH );
	fgSizer9->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_NewCar = new wxButton( m_IndexPanel, wxID_ANY, wxT("New"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_NewCar, 0, wxTOP|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_DeleteCar = new wxButton( m_IndexPanel, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_DeleteCar, 0, wxTOP|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Import = new wxButton( m_IndexPanel, wxID_ANY, wxT("Import..."), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_Import, 0, wxTOP|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Copy = new wxButton( m_IndexPanel, wxID_ANY, wxT("Copy"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_Copy, 0, wxTOP|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Doc = new wxButton( m_IndexPanel, wxID_ANY, wxT("Doc..."), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_Doc, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_Show = new wxCheckBox( m_IndexPanel, wxID_ANY, wxT("Show"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_Show, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	bSizer2->Add( fgSizer9, 0, 0, 5 );
	
	m_ShowAll = new wxCheckBox( m_IndexPanel, wxID_ANY, wxT("Show all"), wxDefaultPosition, wxDefaultSize, 0 );
	m_ShowAll->SetValue(true); 
	bSizer2->Add( m_ShowAll, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_IndexPanel->SetSizer( bSizer2 );
	m_IndexPanel->Layout();
	bSizer2->Fit( m_IndexPanel );
	m_CarBook->AddPage( m_IndexPanel, wxT("Index"), true );
	m_GeneralPanel = new wxPanel( m_CarBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labID = new wxStaticText( m_GeneralPanel, wxID_ANY, wxT("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labID->Wrap( -1 );
	fgSizer1->Add( m_labID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_ID = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_ID, 0, wxEXPAND|wxTOP|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labIdent = new wxStaticText( m_GeneralPanel, wxID_ANY, wxT("Ident"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labIdent->Wrap( -1 );
	fgSizer1->Add( m_labIdent, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_Ident = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_Ident, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_labLocation = new wxStaticText( m_GeneralPanel, wxID_ANY, wxT("Location"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labLocation->Wrap( -1 );
	fgSizer1->Add( m_labLocation, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_Location = new wxComboBox( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer1->Add( m_Location, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_labRoadname = new wxStaticText( m_GeneralPanel, wxID_ANY, wxT("Roadname"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labRoadname->Wrap( -1 );
	fgSizer1->Add( m_labRoadname, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT|wxALIGN_RIGHT, 5 );
	
	m_Roadname = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_Roadname, 0, wxEXPAND|wxTOP|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labNumber = new wxStaticText( m_GeneralPanel, wxID_ANY, wxT("Number"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labNumber->Wrap( -1 );
	fgSizer1->Add( m_labNumber, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_Number = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_Number, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_labColor = new wxStaticText( m_GeneralPanel, wxID_ANY, wxT("Color"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labColor->Wrap( -1 );
	fgSizer1->Add( m_labColor, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_Color = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_Color, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_labImageName = new wxStaticText( m_GeneralPanel, wxID_ANY, wxT("Image"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labImageName->Wrap( -1 );
	fgSizer1->Add( m_labImageName, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxFlexGridSizer* fgSizer10;
	fgSizer10 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer10->AddGrowableCol( 0 );
	fgSizer10->SetFlexibleDirection( wxBOTH );
	fgSizer10->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_ImageName = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer10->Add( m_ImageName, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_ImageChooser = new wxButton( m_GeneralPanel, wxID_ANY, wxT("..."), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	fgSizer10->Add( m_ImageChooser, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	fgSizer1->Add( fgSizer10, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labOwner = new wxStaticText( m_GeneralPanel, wxID_ANY, wxT("Owner"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labOwner->Wrap( -1 );
	fgSizer1->Add( m_labOwner, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_Owner = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_Owner, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	bSizer3->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( m_GeneralPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wxString m_StatusChoices[] = { wxT("empty"), wxT("loaded"), wxT("maintenance") };
	int m_StatusNChoices = sizeof( m_StatusChoices ) / sizeof( wxString );
	m_Status = new wxRadioBox( m_GeneralPanel, wxID_ANY, wxT("Status"), wxDefaultPosition, wxDefaultSize, m_StatusNChoices, m_StatusChoices, 1, wxRA_SPECIFY_ROWS );
	m_Status->SetSelection( 0 );
	bSizer3->Add( m_Status, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GeneralPanel->SetSizer( bSizer3 );
	m_GeneralPanel->Layout();
	bSizer3->Fit( m_GeneralPanel );
	m_CarBook->AddPage( m_GeneralPanel, wxT("General"), false );
	m_DetailsPanel = new wxPanel( m_CarBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxString m_TypeChoices[] = { wxT("Freight"), wxT("Passenger") };
	int m_TypeNChoices = sizeof( m_TypeChoices ) / sizeof( wxString );
	m_Type = new wxRadioBox( m_DetailsPanel, wxID_ANY, wxT("Type"), wxDefaultPosition, wxDefaultSize, m_TypeNChoices, m_TypeChoices, 1, wxRA_SPECIFY_ROWS );
	m_Type->SetSelection( 1 );
	fgSizer8->Add( m_Type, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_Commuter = new wxCheckBox( m_DetailsPanel, wxID_ANY, wxT("Commuter"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_Commuter, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer4->Add( fgSizer8, 0, 0, 5 );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer3->AddGrowableCol( 1 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labSubtype = new wxStaticText( m_DetailsPanel, wxID_ANY, wxT("Subtype"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labSubtype->Wrap( -1 );
	fgSizer3->Add( m_labSubtype, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_SubType = new wxComboBox( m_DetailsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer3->Add( m_SubType, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_labLength = new wxStaticText( m_DetailsPanel, wxID_ANY, wxT("Length"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labLength->Wrap( -1 );
	fgSizer3->Add( m_labLength, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_Length = new wxSpinCtrl( m_DetailsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 9999, 0 );
	fgSizer3->Add( m_Length, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labWeight = new wxStaticText( m_DetailsPanel, wxID_ANY, wxT("Weight"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labWeight->Wrap( -1 );
	fgSizer3->Add( m_labWeight, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_labWeightEmpty = new wxStaticText( m_DetailsPanel, wxID_ANY, wxT("Empty"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labWeightEmpty->Wrap( -1 );
	bSizer9->Add( m_labWeightEmpty, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT, 5 );
	
	m_WeightEmpty = new wxSpinCtrl( m_DetailsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 99999, 0 );
	bSizer9->Add( m_WeightEmpty, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labWeightLoaded = new wxStaticText( m_DetailsPanel, wxID_ANY, wxT("Loaded"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labWeightLoaded->Wrap( -1 );
	bSizer9->Add( m_labWeightLoaded, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT, 5 );
	
	m_WeightLoaded = new wxSpinCtrl( m_DetailsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 99999, 0 );
	bSizer9->Add( m_WeightLoaded, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	fgSizer3->Add( bSizer9, 0, 0, 5 );
	
	m_labManuId = new wxStaticText( m_DetailsPanel, wxID_ANY, wxT("Manufacturer ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labManuId->Wrap( -1 );
	fgSizer3->Add( m_labManuId, 0, wxALIGN_RIGHT|wxBOTTOM|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_ManuId = new wxTextCtrl( m_DetailsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_ManuId, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labVMax = new wxStaticText( m_DetailsPanel, wxID_ANY, wxT("V_max"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labVMax->Wrap( -1 );
	fgSizer3->Add( m_labVMax, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_VMax = new wxSpinCtrl( m_DetailsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 500, 0 );
	fgSizer3->Add( m_VMax, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	bSizer4->Add( fgSizer3, 0, wxEXPAND, 5 );
	
	wxString m_EraChoices[] = { wxT("I"), wxT("II"), wxT("III"), wxT("IV"), wxT("V"), wxT("VI") };
	int m_EraNChoices = sizeof( m_EraChoices ) / sizeof( wxString );
	m_Era = new wxRadioBox( m_DetailsPanel, wxID_ANY, wxT("Era"), wxDefaultPosition, wxDefaultSize, m_EraNChoices, m_EraChoices, 1, wxRA_SPECIFY_ROWS );
	m_Era->SetSelection( 0 );
	bSizer4->Add( m_Era, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_labRemark = new wxStaticText( m_DetailsPanel, wxID_ANY, wxT("Maintenance"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labRemark->Wrap( -1 );
	bSizer4->Add( m_labRemark, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_Remark = new wxTextCtrl( m_DetailsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	bSizer4->Add( m_Remark, 1, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_DetailsPanel->SetSizer( bSizer4 );
	m_DetailsPanel->Layout();
	bSizer4->Fit( m_DetailsPanel );
	m_CarBook->AddPage( m_DetailsPanel, wxT("Details"), false );
	m_InterfacePanel = new wxPanel( m_CarBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer31;
	fgSizer31 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer31->AddGrowableCol( 1 );
	fgSizer31->SetFlexibleDirection( wxBOTH );
	fgSizer31->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labBus = new wxStaticText( m_InterfacePanel, wxID_ANY, wxT("Bus"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labBus->Wrap( -1 );
	fgSizer31->Add( m_labBus, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_Bus = new wxTextCtrl( m_InterfacePanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer31->Add( m_Bus, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_labIID = new wxStaticText( m_InterfacePanel, wxID_ANY, wxT("IID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labIID->Wrap( -1 );
	fgSizer31->Add( m_labIID, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_IID = new wxComboBox( m_InterfacePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer31->Add( m_IID, 0, wxEXPAND|wxTOP|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labAddr = new wxStaticText( m_InterfacePanel, wxID_ANY, wxT("Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labAddr->Wrap( -1 );
	fgSizer31->Add( m_labAddr, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_Addr = new wxSpinCtrl( m_InterfacePanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer31->Add( m_Addr, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_labProtocol = new wxStaticText( m_InterfacePanel, wxID_ANY, wxT("Protocol"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labProtocol->Wrap( -1 );
	fgSizer31->Add( m_labProtocol, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_Protocol = new wxComboBox( m_InterfacePanel, wxID_ANY, wxT("ServerDefined"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN|wxCB_READONLY );
	m_Protocol->Append( wxT("ServerDefined") );
	m_Protocol->Append( wxT("Motorola") );
	m_Protocol->Append( wxT("NMRA-DCC") );
	m_Protocol->Append( wxT("NMRA-DCC long") );
	fgSizer31->Add( m_Protocol, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_labProtVersion = new wxStaticText( m_InterfacePanel, wxID_ANY, wxT("ProtVersion"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labProtVersion->Wrap( -1 );
	fgSizer31->Add( m_labProtVersion, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_ProtVersion = new wxTextCtrl( m_InterfacePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer31->Add( m_ProtVersion, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_labSteps = new wxStaticText( m_InterfacePanel, wxID_ANY, wxT("Speed steps"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labSteps->Wrap( -1 );
	fgSizer31->Add( m_labSteps, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_SpeedSteps = new wxSpinCtrl( m_InterfacePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 14, 128, 14 );
	fgSizer31->Add( m_SpeedSteps, 0, wxALL, 5 );
	
	bSizer6->Add( fgSizer31, 0, wxEXPAND, 5 );
	
	m_IntOptions = new wxStaticBoxSizer( new wxStaticBox( m_InterfacePanel, wxID_ANY, wxT("Options") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_UseDir = new wxCheckBox( m_InterfacePanel, wxID_ANY, wxT("Direction"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer6->Add( m_UseDir, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_InvDir = new wxCheckBox( m_InterfacePanel, wxID_ANY, wxT("Invert"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer6->Add( m_InvDir, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_Placing = new wxCheckBox( m_InterfacePanel, wxID_ANY, wxT("Placing"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer6->Add( m_Placing, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_IntOptions->Add( fgSizer6, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer61;
	fgSizer61 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer61->SetFlexibleDirection( wxBOTH );
	fgSizer61->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_UseLights = new wxCheckBox( m_InterfacePanel, wxID_ANY, wxT("Lights"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer61->Add( m_UseLights, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_FnLights = new wxSpinCtrl( m_InterfacePanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 28, 0 );
	fgSizer61->Add( m_FnLights, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_F0VCmd = new wxCheckBox( m_InterfacePanel, wxID_ANY, wxT("F0 Speed command"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer61->Add( m_F0VCmd, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_IntOptions->Add( fgSizer61, 0, 0, 5 );
	
	bSizer6->Add( m_IntOptions, 0, wxEXPAND|wxALL, 5 );
	
	m_InterfacePanel->SetSizer( bSizer6 );
	m_InterfacePanel->Layout();
	bSizer6->Fit( m_InterfacePanel );
	m_CarBook->AddPage( m_InterfacePanel, wxT("Interface"), false );
	m_FunctionPanel = new wxPanel( m_CarBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer4->AddGrowableCol( 1 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labFNumber = new wxStaticText( m_FunctionPanel, wxID_ANY, wxT("#"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labFNumber->Wrap( -1 );
	fgSizer4->Add( m_labFNumber, 0, wxTOP|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labFDesc = new wxStaticText( m_FunctionPanel, wxID_ANY, wxT("Description"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labFDesc->Wrap( -1 );
	fgSizer4->Add( m_labFDesc, 0, wxTOP|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labFx = new wxStaticText( m_FunctionPanel, wxID_ANY, wxT("Fx"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labFx->Wrap( -1 );
	fgSizer4->Add( m_labFx, 0, wxTOP|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labIcon = new wxStaticText( m_FunctionPanel, wxID_ANY, wxT("Icon"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labIcon->Wrap( -1 );
	fgSizer4->Add( m_labIcon, 0, wxTOP|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_F0 = new wxStaticText( m_FunctionPanel, wxID_ANY, wxT("F0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_F0->Wrap( -1 );
	fgSizer4->Add( m_F0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_F0Desc = new wxTextCtrl( m_FunctionPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_F0Desc, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_F0x = new wxSpinCtrl( m_FunctionPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 28, 0 );
	fgSizer4->Add( m_F0x, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_F0Icon = new wxTextCtrl( m_FunctionPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_F0Icon->SetMinSize( wxSize( 140,-1 ) );
	
	fgSizer4->Add( m_F0Icon, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_F1 = new wxStaticText( m_FunctionPanel, wxID_ANY, wxT("F1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_F1->Wrap( -1 );
	fgSizer4->Add( m_F1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_F1Desc = new wxTextCtrl( m_FunctionPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_F1Desc, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_F1x = new wxSpinCtrl( m_FunctionPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 28, 0 );
	fgSizer4->Add( m_F1x, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_F1Icon = new wxTextCtrl( m_FunctionPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_F1Icon->SetMinSize( wxSize( 140,-1 ) );
	
	fgSizer4->Add( m_F1Icon, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_F2 = new wxStaticText( m_FunctionPanel, wxID_ANY, wxT("F2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_F2->Wrap( -1 );
	fgSizer4->Add( m_F2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_F2Desc = new wxTextCtrl( m_FunctionPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_F2Desc, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_F2x = new wxSpinCtrl( m_FunctionPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 28, 0 );
	fgSizer4->Add( m_F2x, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_F2Icon = new wxTextCtrl( m_FunctionPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_F2Icon->SetMinSize( wxSize( 140,-1 ) );
	
	fgSizer4->Add( m_F2Icon, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_F3 = new wxStaticText( m_FunctionPanel, wxID_ANY, wxT("F3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_F3->Wrap( -1 );
	fgSizer4->Add( m_F3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_F3Desc = new wxTextCtrl( m_FunctionPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_F3Desc, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_F3x = new wxSpinCtrl( m_FunctionPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 28, 0 );
	fgSizer4->Add( m_F3x, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_F3Icon = new wxTextCtrl( m_FunctionPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_F3Icon->SetMinSize( wxSize( 140,-1 ) );
	
	fgSizer4->Add( m_F3Icon, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_F4 = new wxStaticText( m_FunctionPanel, wxID_ANY, wxT("F4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_F4->Wrap( -1 );
	fgSizer4->Add( m_F4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_F4Desc = new wxTextCtrl( m_FunctionPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_F4Desc, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_F4x = new wxSpinCtrl( m_FunctionPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 60,-1 ), wxSP_ARROW_KEYS, 0, 28, 0 );
	fgSizer4->Add( m_F4x, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_F4Icon = new wxTextCtrl( m_FunctionPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_F4Icon->SetMinSize( wxSize( 140,-1 ) );
	
	fgSizer4->Add( m_F4Icon, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer71->Add( fgSizer4, 0, wxEXPAND, 5 );
	
	m_FG = new wxButton( m_FunctionPanel, wxID_ANY, wxT("FG"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer71->Add( m_FG, 0, wxALL, 5 );
	
	m_FunctionPanel->SetSizer( bSizer71 );
	m_FunctionPanel->Layout();
	bSizer71->Fit( m_FunctionPanel );
	m_CarBook->AddPage( m_FunctionPanel, wxT("Functions"), false );
	m_CVPanel = new wxPanel( m_CarBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_CVList = new wxGrid( m_CVPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_CVList->CreateGrid( 0, 3 );
	m_CVList->EnableEditing( false );
	m_CVList->EnableGridLines( true );
	m_CVList->EnableDragGridSize( false );
	m_CVList->SetMargins( 0, 0 );
	
	// Columns
	m_CVList->AutoSizeColumns();
	m_CVList->EnableDragColMove( false );
	m_CVList->EnableDragColSize( true );
	m_CVList->SetColLabelSize( 30 );
	m_CVList->SetColLabelValue( 0, wxT("CV") );
	m_CVList->SetColLabelValue( 1, wxT("Value") );
	m_CVList->SetColLabelValue( 2, wxT("Remark") );
	m_CVList->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_CVList->EnableDragRowSize( true );
	m_CVList->SetRowLabelSize( 0 );
	m_CVList->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_CVList->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer5->Add( m_CVList, 1, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer41;
	fgSizer41 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer41->AddGrowableCol( 1 );
	fgSizer41->SetFlexibleDirection( wxBOTH );
	fgSizer41->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labCVDesc = new wxStaticText( m_CVPanel, wxID_ANY, wxT("Remark"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labCVDesc->Wrap( -1 );
	fgSizer41->Add( m_labCVDesc, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CVDescription = new wxTextCtrl( m_CVPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer41->Add( m_CVDescription, 0, wxALL|wxEXPAND, 5 );
	
	m_CVDescModify = new wxButton( m_CVPanel, wxID_ANY, wxT("Modify"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer41->Add( m_CVDescModify, 0, wxALL, 5 );
	
	bSizer5->Add( fgSizer41, 0, wxEXPAND, 5 );
	
	m_CVPanel->SetSizer( bSizer5 );
	m_CVPanel->Layout();
	bSizer5->Fit( m_CVPanel );
	m_CarBook->AddPage( m_CVPanel, wxT("CVs"), false );
	
	bSizer1->Add( m_CarBook, 1, wxEXPAND | wxALL, 5 );
	
	m_stdButton = new wxStdDialogButtonSizer();
	m_stdButtonOK = new wxButton( this, wxID_OK );
	m_stdButton->AddButton( m_stdButtonOK );
	m_stdButtonApply = new wxButton( this, wxID_APPLY );
	m_stdButton->AddButton( m_stdButtonApply );
	m_stdButtonCancel = new wxButton( this, wxID_CANCEL );
	m_stdButton->AddButton( m_stdButtonCancel );
	m_stdButtonHelp = new wxButton( this, wxID_HELP );
	m_stdButton->AddButton( m_stdButtonHelp );
	m_stdButton->Realize();
	bSizer1->Add( m_stdButton, 0, wxALIGN_RIGHT|wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_CarImage->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onCarImage ), NULL, this );
	m_CarList2->Connect( wxEVT_COMMAND_LIST_COL_CLICK, wxListEventHandler( cardlggen::onListColClick ), NULL, this );
	m_CarList2->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( cardlggen::onCarList2 ), NULL, this );
	m_NewCar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onNewCar ), NULL, this );
	m_DeleteCar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onDeleteCar ), NULL, this );
	m_Import->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onImport ), NULL, this );
	m_Copy->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::OnCopy ), NULL, this );
	m_Doc->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onDoc ), NULL, this );
	m_Show->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cardlggen::onShow ), NULL, this );
	m_ShowAll->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cardlggen::onListAvailableOnly ), NULL, this );
	m_ImageChooser->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onImageChooser ), NULL, this );
	m_Type->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cardlggen::onTypeSelect ), NULL, this );
	m_F0Icon->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( cardlggen::onF0Icon ), NULL, this );
	m_F1Icon->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( cardlggen::onF1Icon ), NULL, this );
	m_F2Icon->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( cardlggen::onF2Icon ), NULL, this );
	m_F3Icon->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( cardlggen::onF3Icon ), NULL, this );
	m_F4Icon->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( cardlggen::onF4Icon ), NULL, this );
	m_FG->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onFG ), NULL, this );
	m_CVList->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( cardlggen::onCVCell ), NULL, this );
	m_CVDescModify->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onCVModify ), NULL, this );
	m_stdButtonApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onApply ), NULL, this );
	m_stdButtonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onCancel ), NULL, this );
	m_stdButtonHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onHelp ), NULL, this );
	m_stdButtonOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onOK ), NULL, this );
}

cardlggen::~cardlggen()
{
	// Disconnect Events
	m_CarImage->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onCarImage ), NULL, this );
	m_CarList2->Disconnect( wxEVT_COMMAND_LIST_COL_CLICK, wxListEventHandler( cardlggen::onListColClick ), NULL, this );
	m_CarList2->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( cardlggen::onCarList2 ), NULL, this );
	m_NewCar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onNewCar ), NULL, this );
	m_DeleteCar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onDeleteCar ), NULL, this );
	m_Import->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onImport ), NULL, this );
	m_Copy->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::OnCopy ), NULL, this );
	m_Doc->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onDoc ), NULL, this );
	m_Show->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cardlggen::onShow ), NULL, this );
	m_ShowAll->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cardlggen::onListAvailableOnly ), NULL, this );
	m_ImageChooser->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onImageChooser ), NULL, this );
	m_Type->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cardlggen::onTypeSelect ), NULL, this );
	m_F0Icon->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( cardlggen::onF0Icon ), NULL, this );
	m_F1Icon->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( cardlggen::onF1Icon ), NULL, this );
	m_F2Icon->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( cardlggen::onF2Icon ), NULL, this );
	m_F3Icon->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( cardlggen::onF3Icon ), NULL, this );
	m_F4Icon->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( cardlggen::onF4Icon ), NULL, this );
	m_FG->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onFG ), NULL, this );
	m_CVList->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( cardlggen::onCVCell ), NULL, this );
	m_CVDescModify->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onCVModify ), NULL, this );
	m_stdButtonApply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onApply ), NULL, this );
	m_stdButtonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onCancel ), NULL, this );
	m_stdButtonHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onHelp ), NULL, this );
	m_stdButtonOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cardlggen::onOK ), NULL, this );
	
}
