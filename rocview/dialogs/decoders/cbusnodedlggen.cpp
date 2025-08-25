///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "cbusnodedlggen.h"

///////////////////////////////////////////////////////////////////////////

cbusnodedlggen::cbusnodedlggen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_NoteBook = new wxNotebook( this, wxID_CBUSNODE_BOOK, wxDefaultPosition, wxDefaultSize, 0 );
	m_NodeNumberPanel = new wxPanel( m_NoteBook, wxID_CBUSNODE_NUMBER, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );
	
	m_CBusLogo = new wxStaticBitmap( m_NodeNumberPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( m_CBusLogo, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_GCALogo = new wxStaticBitmap( m_NodeNumberPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( m_GCALogo, 0, wxALL, 5 );
	
	bSizer3->Add( bSizer35, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer2->AddGrowableCol( 1 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labIID = new wxStaticText( m_NodeNumberPanel, wxID_ANY, wxT("IID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labIID->Wrap( -1 );
	fgSizer2->Add( m_labIID, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_IID = new wxTextCtrl( m_NodeNumberPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	fgSizer2->Add( m_IID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer3->Add( fgSizer2, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer11;
	sbSizer11 = new wxStaticBoxSizer( new wxStaticBox( m_NodeNumberPanel, wxID_ANY, wxT("Node Info") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer51;
	fgSizer51 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer51->AddGrowableCol( 1 );
	fgSizer51->SetFlexibleDirection( wxBOTH );
	fgSizer51->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labNodeType = new wxStaticText( m_NodeNumberPanel, wxID_ANY, wxT("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labNodeType->Wrap( -1 );
	fgSizer51->Add( m_labNodeType, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_NodeType = new wxTextCtrl( m_NodeNumberPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 160,-1 ), wxTE_READONLY );
	fgSizer51->Add( m_NodeType, 0, wxALL, 5 );
	
	m_labVersion = new wxStaticText( m_NodeNumberPanel, wxID_ANY, wxT("Version"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labVersion->Wrap( -1 );
	fgSizer51->Add( m_labVersion, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_Version = new wxTextCtrl( m_NodeNumberPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	m_Version->Enable( false );
	
	fgSizer51->Add( m_Version, 0, wxALL, 5 );
	
	m_labManu = new wxStaticText( m_NodeNumberPanel, wxID_ANY, wxT("ManuID:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labManu->Wrap( -1 );
	fgSizer51->Add( m_labManu, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_NodeManuNr = new wxSpinCtrl( m_NodeNumberPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	m_NodeManuNr->Enable( false );
	
	fgSizer51->Add( m_NodeManuNr, 0, wxALL, 5 );
	
	m_labModID = new wxStaticText( m_NodeNumberPanel, wxID_ANY, wxT("ModuleID:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labModID->Wrap( -1 );
	fgSizer51->Add( m_labModID, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_NodeTypeNr = new wxSpinCtrl( m_NodeNumberPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	m_NodeTypeNr->Enable( false );
	
	fgSizer51->Add( m_NodeTypeNr, 0, wxALL, 5 );
	
	sbSizer11->Add( fgSizer51, 0, 0, 5 );
	
	bSizer3->Add( sbSizer11, 0, wxALL, 5 );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labNumber = new wxStaticText( m_NodeNumberPanel, wxID_ANY, wxT("Node Number:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labNumber->Wrap( -1 );
	fgSizer1->Add( m_labNumber, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_NodeNumber = new wxSpinCtrl( m_NodeNumberPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer1->Add( m_NodeNumber, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_SetNodeNumber = new wxButton( m_NodeNumberPanel, wxID_ANY, wxT("Set"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_SetNodeNumber, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer3->Add( fgSizer1, 0, wxEXPAND|wxALL, 5 );
	
	m_NodeNumberPanel->SetSizer( bSizer3 );
	m_NodeNumberPanel->Layout();
	bSizer3->Fit( m_NodeNumberPanel );
	m_NoteBook->AddPage( m_NodeNumberPanel, wxT("Node"), false );
	m_IndexPanel = new wxPanel( m_NoteBook, wxID_CBUSNODE_INDEX, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_IndexList2 = new wxListCtrl( m_IndexPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL );
	bSizer5->Add( m_IndexList2, 1, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer29;
	fgSizer29 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer29->AddGrowableCol( 1 );
	fgSizer29->SetFlexibleDirection( wxBOTH );
	fgSizer29->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labIndexIID = new wxStaticText( m_IndexPanel, wxID_ANY, wxT("IID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labIndexIID->Wrap( -1 );
	fgSizer29->Add( m_labIndexIID, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_IndexIID = new wxTextCtrl( m_IndexPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	fgSizer29->Add( m_IndexIID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer5->Add( fgSizer29, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_QueryNN = new wxButton( m_IndexPanel, wxID_ANY, wxT("Query"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_QueryNN, 0, wxALL, 5 );
	
	m_Report = new wxButton( m_IndexPanel, wxID_ANY, wxT("Report..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_Report, 0, wxALL, 5 );
	
	bSizer5->Add( bSizer6, 0, wxEXPAND, 5 );
	
	m_IndexPanel->SetSizer( bSizer5 );
	m_IndexPanel->Layout();
	bSizer5->Fit( m_IndexPanel );
	m_NoteBook->AddPage( m_IndexPanel, wxT("Index"), false );
	m_VarPanel = new wxPanel( m_NoteBook, wxID_CBUS_VAR, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_VarList = new wxListBox( m_VarPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE ); 
	m_VarList->SetMinSize( wxSize( -1,150 ) );
	
	bSizer4->Add( m_VarList, 1, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labVarIndex = new wxStaticText( m_VarPanel, wxID_ANY, wxT("Index"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labVarIndex->Wrap( -1 );
	fgSizer5->Add( m_labVarIndex, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_labVarValue = new wxStaticText( m_VarPanel, wxID_ANY, wxT("Value"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labVarValue->Wrap( -1 );
	fgSizer5->Add( m_labVarValue, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_VarIndex = new wxSpinCtrl( m_VarPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer5->Add( m_VarIndex, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxVERTICAL );
	
	m_VarValue = new wxSpinCtrl( m_VarPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	bSizer121->Add( m_VarValue, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	m_VarBit7 = new wxCheckBox( m_VarPanel, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_VarBit7, 0, 0, 5 );
	
	m_VarBit6 = new wxCheckBox( m_VarPanel, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_VarBit6, 0, 0, 5 );
	
	m_VarBit5 = new wxCheckBox( m_VarPanel, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_VarBit5, 0, 0, 5 );
	
	m_VarBit4 = new wxCheckBox( m_VarPanel, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_VarBit4, 0, 0, 5 );
	
	m_VarBit3 = new wxCheckBox( m_VarPanel, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_VarBit3, 0, 0, 5 );
	
	m_VarBit2 = new wxCheckBox( m_VarPanel, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_VarBit2, 0, 0, 5 );
	
	m_VarBit1 = new wxCheckBox( m_VarPanel, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_VarBit1, 0, 0, 5 );
	
	m_VarBit0 = new wxCheckBox( m_VarPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_VarBit0, 0, 0, 5 );
	
	bSizer121->Add( bSizer8, 0, wxEXPAND, 5 );
	
	fgSizer5->Add( bSizer121, 1, wxEXPAND, 5 );
	
	bSizer4->Add( fgSizer5, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_VarGet = new wxButton( m_VarPanel, wxID_ANY, wxT("Get"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_VarGet, 0, wxALL, 5 );
	
	m_VarSet = new wxButton( m_VarPanel, wxID_ANY, wxT("Set"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_VarSet, 0, wxALL, 5 );
	
	bSizer4->Add( bSizer9, 0, wxEXPAND, 5 );
	
	m_VarPanel->SetSizer( bSizer4 );
	m_VarPanel->Layout();
	bSizer4->Fit( m_VarPanel );
	m_NoteBook->AddPage( m_VarPanel, wxT("Variables"), true );
	m_EventsPanel = new wxPanel( m_NoteBook, wxID_CBUS_EVENTSPANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	m_EventList = new wxListBox( m_EventsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_SINGLE ); 
	m_EventList->SetMinSize( wxSize( -1,150 ) );
	
	bSizer10->Add( m_EventList, 1, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labEventNode = new wxStaticText( m_EventsPanel, wxID_ANY, wxT("Node Nr."), wxDefaultPosition, wxDefaultSize, 0 );
	m_labEventNode->Wrap( -1 );
	fgSizer4->Add( m_labEventNode, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_labEventAddr = new wxStaticText( m_EventsPanel, wxID_ANY, wxT("Event Nr."), wxDefaultPosition, wxDefaultSize, 0 );
	m_labEventAddr->Wrap( -1 );
	fgSizer4->Add( m_labEventAddr, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_labEventIndex = new wxStaticText( m_EventsPanel, wxID_ANY, wxT("Index"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labEventIndex->Wrap( -1 );
	fgSizer4->Add( m_labEventIndex, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_labEventVar = new wxStaticText( m_EventsPanel, wxID_ANY, wxT("Variable"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labEventVar->Wrap( -1 );
	fgSizer4->Add( m_labEventVar, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_EventNodeNr = new wxSpinCtrl( m_EventsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer4->Add( m_EventNodeNr, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_EventAddress = new wxSpinCtrl( m_EventsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer4->Add( m_EventAddress, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_EventIndex = new wxSpinCtrl( m_EventsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 32, 0 );
	fgSizer4->Add( m_EventIndex, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_EventVar = new wxSpinCtrl( m_EventsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer6->Add( m_EventVar, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_EvtGetVar = new wxButton( m_EventsPanel, wxID_ANY, wxT("Get"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer6->Add( m_EvtGetVar, 0, wxRIGHT, 5 );
	
	bSizer12->Add( fgSizer6, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	m_EVBit7 = new wxCheckBox( m_EventsPanel, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_EVBit7, 0, 0, 5 );
	
	m_EVBit6 = new wxCheckBox( m_EventsPanel, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_EVBit6, 0, 0, 5 );
	
	m_EVBit5 = new wxCheckBox( m_EventsPanel, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_EVBit5, 0, 0, 5 );
	
	m_EVBit4 = new wxCheckBox( m_EventsPanel, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_EVBit4, 0, 0, 5 );
	
	m_EVBit3 = new wxCheckBox( m_EventsPanel, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_EVBit3, 0, 0, 5 );
	
	m_EVBit2 = new wxCheckBox( m_EventsPanel, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_EVBit2, 0, 0, 5 );
	
	m_EVBit1 = new wxCheckBox( m_EventsPanel, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_EVBit1, 0, 0, 5 );
	
	m_EVBit0 = new wxCheckBox( m_EventsPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_EVBit0, 0, 0, 5 );
	
	bSizer12->Add( bSizer13, 1, wxEXPAND, 5 );
	
	fgSizer4->Add( bSizer12, 0, wxEXPAND, 5 );
	
	bSizer10->Add( fgSizer4, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_EventGetAll = new wxButton( m_EventsPanel, wxID_ANY, wxT("Get all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_EventGetAll, 0, wxALL, 5 );
	
	m_EventAdd = new wxButton( m_EventsPanel, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_EventAdd, 0, wxALL, 5 );
	
	m_EventDelete = new wxButton( m_EventsPanel, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_EventDelete, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_EvtClearAll = new wxButton( m_EventsPanel, wxID_ANY, wxT("Clear all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_EvtClearAll, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_EvtLearn = new wxButton( m_EventsPanel, wxID_ANY, wxT("Learn"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_EvtLearn, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_EvtUnlearn = new wxButton( m_EventsPanel, wxID_ANY, wxT("Unlearn"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_EvtUnlearn, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	bSizer10->Add( bSizer11, 0, wxEXPAND, 5 );
	
	m_EventsPanel->SetSizer( bSizer10 );
	m_EventsPanel->Layout();
	bSizer10->Fit( m_EventsPanel );
	m_NoteBook->AddPage( m_EventsPanel, wxT("Events"), false );
	m_FirmwarePanel = new wxPanel( m_NoteBook, wxID_CBUS_NODEFIRMWAREPANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer131;
	bSizer131 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer7->AddGrowableCol( 1 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_HexFile = new wxButton( m_FirmwarePanel, wxID_ANY, wxT("HEX File..."), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer7->Add( m_HexFile, 0, wxALL, 5 );
	
	m_HEXFileName = new wxTextCtrl( m_FirmwarePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	fgSizer7->Add( m_HEXFileName, 0, wxALL|wxEXPAND, 5 );
	
	m_HEXFileSend = new wxButton( m_FirmwarePanel, wxID_ANY, wxT("Send"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer7->Add( m_HEXFileSend, 0, wxALL, 5 );
	
	bSizer131->Add( fgSizer7, 0, wxEXPAND, 5 );
	
	m_HEXFileText = new wxTextCtrl( m_FirmwarePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTE_MULTILINE|wxTE_READONLY );
	m_HEXFileText->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxT("Monospace") ) );
	
	bSizer131->Add( m_HEXFileText, 1, wxALL|wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( m_FirmwarePanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer131->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	m_BootMode = new wxButton( m_FirmwarePanel, wxID_ANY, wxT("Boot mode"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_BootMode, 0, wxALL, 5 );
	
	m_ResetBoot = new wxButton( m_FirmwarePanel, wxID_ANY, wxT("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_ResetBoot, 0, wxALL, 5 );
	
	m_WriteEEprom = new wxCheckBox( m_FirmwarePanel, wxID_ANY, wxT("Write EEPROM"), wxDefaultPosition, wxDefaultSize, 0 );
	m_WriteEEprom->SetValue(true); 
	bSizer15->Add( m_WriteEEprom, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer131->Add( bSizer15, 0, wxEXPAND, 5 );
	
	m_FirmwarePanel->SetSizer( bSizer131 );
	m_FirmwarePanel->Layout();
	bSizer131->Fit( m_FirmwarePanel );
	m_NoteBook->AddPage( m_FirmwarePanel, wxT("Firmware"), false );
	m_CANGC1ePanel = new wxPanel( m_NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* m_GC1eNetworkBox;
	m_GC1eNetworkBox = new wxStaticBoxSizer( new wxStaticBox( m_CANGC1ePanel, wxID_ANY, wxT("Ethernet") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer23;
	fgSizer23 = new wxFlexGridSizer( 0, 5, 0, 0 );
	fgSizer23->SetFlexibleDirection( wxBOTH );
	fgSizer23->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labGC1eIPAddress = new wxStaticText( m_CANGC1ePanel, wxID_ANY, wxT("IP Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC1eIPAddress->Wrap( -1 );
	fgSizer23->Add( m_labGC1eIPAddress, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC1eIP1 = new wxSpinCtrl( m_CANGC1ePanel, wxID_ANY, wxT("192"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 192 );
	fgSizer23->Add( m_GC1eIP1, 0, wxALL, 5 );
	
	m_GC1eIP2 = new wxSpinCtrl( m_CANGC1ePanel, wxID_ANY, wxT("168"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer23->Add( m_GC1eIP2, 0, wxALL, 5 );
	
	m_GC1eIP3 = new wxSpinCtrl( m_CANGC1ePanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer23->Add( m_GC1eIP3, 0, wxALL, 5 );
	
	m_GC1eIP4 = new wxSpinCtrl( m_CANGC1ePanel, wxID_ANY, wxT("200"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer23->Add( m_GC1eIP4, 0, wxALL, 5 );
	
	m_labGC1eNetmask = new wxStaticText( m_CANGC1ePanel, wxID_ANY, wxT("Netmask"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC1eNetmask->Wrap( -1 );
	fgSizer23->Add( m_labGC1eNetmask, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC1eNetmask1 = new wxSpinCtrl( m_CANGC1ePanel, wxID_ANY, wxT("255"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer23->Add( m_GC1eNetmask1, 0, wxALL, 5 );
	
	m_GC1eNetmask2 = new wxSpinCtrl( m_CANGC1ePanel, wxID_ANY, wxT("255"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer23->Add( m_GC1eNetmask2, 0, wxALL, 5 );
	
	m_GC1eNetmask3 = new wxSpinCtrl( m_CANGC1ePanel, wxID_ANY, wxT("255"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer23->Add( m_GC1eNetmask3, 0, wxALL, 5 );
	
	m_GC1eNetmask4 = new wxSpinCtrl( m_CANGC1ePanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer23->Add( m_GC1eNetmask4, 0, wxALL, 5 );
	
	m_GC1eNetworkBox->Add( fgSizer23, 0, 0, 5 );
	
	wxFlexGridSizer* fgSizer24;
	fgSizer24 = new wxFlexGridSizer( 0, 7, 0, 0 );
	fgSizer24->SetFlexibleDirection( wxBOTH );
	fgSizer24->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labGC1eMAC = new wxStaticText( m_CANGC1ePanel, wxID_ANY, wxT("MAC"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC1eMAC->Wrap( -1 );
	fgSizer24->Add( m_labGC1eMAC, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC1eMAC1 = new wxSpinCtrl( m_CANGC1ePanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 65,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer24->Add( m_GC1eMAC1, 0, wxALL, 5 );
	
	m_GC1eMAC2 = new wxSpinCtrl( m_CANGC1ePanel, wxID_ANY, wxT("4"), wxDefaultPosition, wxSize( 65,-1 ), wxSP_ARROW_KEYS, 0, 255, 4 );
	fgSizer24->Add( m_GC1eMAC2, 0, wxALL, 5 );
	
	m_GC1eMAC3 = new wxSpinCtrl( m_CANGC1ePanel, wxID_ANY, wxT("163"), wxDefaultPosition, wxSize( 65,-1 ), wxSP_ARROW_KEYS, 0, 255, 163 );
	fgSizer24->Add( m_GC1eMAC3, 0, wxALL, 5 );
	
	m_GC1eMAC4 = new wxSpinCtrl( m_CANGC1ePanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 65,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer24->Add( m_GC1eMAC4, 0, wxALL, 5 );
	
	m_GC1eMAC5 = new wxSpinCtrl( m_CANGC1ePanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 65,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer24->Add( m_GC1eMAC5, 0, wxALL, 5 );
	
	m_GC1eMAC6 = new wxSpinCtrl( m_CANGC1ePanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer24->Add( m_GC1eMAC6, 0, wxALL, 5 );
	
	m_GC1eNetworkBox->Add( fgSizer24, 0, 0, 5 );
	
	m_GC1eIdleWD = new wxCheckBox( m_CANGC1ePanel, wxID_ANY, wxT("Idle time watch dog"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC1eIdleWD->SetValue(true); 
	m_GC1eNetworkBox->Add( m_GC1eIdleWD, 0, wxALL, 5 );
	
	m_GC1ePowerOffAtIdle = new wxCheckBox( m_CANGC1ePanel, wxID_ANY, wxT("Track power off at idle"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC1eNetworkBox->Add( m_GC1ePowerOffAtIdle, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GC1eCommandAck = new wxCheckBox( m_CANGC1ePanel, wxID_ANY, wxT("Command Ack"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC1eNetworkBox->Add( m_GC1eCommandAck, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	wxFlexGridSizer* fgSizer26;
	fgSizer26 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer26->SetFlexibleDirection( wxBOTH );
	fgSizer26->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labGC1eIdleTime = new wxStaticText( m_CANGC1ePanel, wxID_ANY, wxT("Idle time in 500ms"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC1eIdleTime->Wrap( -1 );
	fgSizer26->Add( m_labGC1eIdleTime, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GC1eIdleTime = new wxSpinCtrl( m_CANGC1ePanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 5, 255, 0 );
	fgSizer26->Add( m_GC1eIdleTime, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GC1eNetworkBox->Add( fgSizer26, 1, wxEXPAND, 5 );
	
	bSizer28->Add( m_GC1eNetworkBox, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* m_GC1eCBusBox;
	m_GC1eCBusBox = new wxStaticBoxSizer( new wxStaticBox( m_CANGC1ePanel, wxID_ANY, wxT("CBUS") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer25;
	fgSizer25 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer25->SetFlexibleDirection( wxBOTH );
	fgSizer25->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labGC1eCanID = new wxStaticText( m_CANGC1ePanel, wxID_ANY, wxT("CANID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC1eCanID->Wrap( -1 );
	fgSizer25->Add( m_labGC1eCanID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC1eCanID = new wxSpinCtrl( m_CANGC1ePanel, wxID_ANY, wxT("11"), wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 127, 0 );
	fgSizer25->Add( m_GC1eCanID, 0, wxALL, 5 );
	
	m_GC1eCBusBox->Add( fgSizer25, 0, wxEXPAND, 5 );
	
	bSizer28->Add( m_GC1eCBusBox, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	m_GC1eGetAll = new wxButton( m_CANGC1ePanel, wxID_ANY, wxT("Get all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer29->Add( m_GC1eGetAll, 0, wxALL, 5 );
	
	m_GC1eSetAll = new wxButton( m_CANGC1ePanel, wxID_ANY, wxT("Set all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer29->Add( m_GC1eSetAll, 0, wxALL, 5 );
	
	bSizer28->Add( bSizer29, 0, wxEXPAND, 5 );
	
	m_CANGC1ePanel->SetSizer( bSizer28 );
	m_CANGC1ePanel->Layout();
	bSizer28->Fit( m_CANGC1ePanel );
	m_NoteBook->AddPage( m_CANGC1ePanel, wxT("GC1e"), false );
	m_CANGC2Panel = new wxPanel( m_NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer151;
	bSizer151 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 0, 6, 0, 0 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_lab1GC2Port = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("Port"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lab1GC2Port->Wrap( -1 );
	fgSizer8->Add( m_lab1GC2Port, 0, wxTOP|wxLEFT, 5 );
	
	m_lab1GC2EvtNN = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("Node Nr."), wxDefaultPosition, wxDefaultSize, 0 );
	m_lab1GC2EvtNN->Wrap( -1 );
	fgSizer8->Add( m_lab1GC2EvtNN, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_lab1GC2EvtAddr = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("Event Nr."), wxDefaultPosition, wxDefaultSize, 0 );
	m_lab1GC2EvtAddr->Wrap( -1 );
	fgSizer8->Add( m_lab1GC2EvtAddr, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 1, 4, 0, 0 );
	
	m_staticText107 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("IN"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText107->Wrap( -1 );
	gSizer1->Add( m_staticText107, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticText108 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("BK"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText108->Wrap( -1 );
	gSizer1->Add( m_staticText108, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticText109 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("SW"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText109->Wrap( -1 );
	gSizer1->Add( m_staticText109, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticText110 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("PU"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText110->Wrap( -1 );
	gSizer1->Add( m_staticText110, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	fgSizer8->Add( gSizer1, 0, wxEXPAND, 5 );
	
	m_lab1C2 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("Inv"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lab1C2->Wrap( -1 );
	fgSizer8->Add( m_lab1C2, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_lab1GC2Test = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("Test"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lab1GC2Test->Wrap( -1 );
	fgSizer8->Add( m_lab1GC2Test, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_labGC2Port1 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC2Port1->Wrap( -1 );
	fgSizer8->Add( m_labGC2Port1, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC2EvtNN1 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer8->Add( m_GC2EvtNN1, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2EvtAddr1 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer8->Add( m_GC2EvtAddr1, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_GC2Type1Choices[] = { wxT(" "), wxT(" "), wxT(" "), wxT(" ") };
	int m_GC2Type1NChoices = sizeof( m_GC2Type1Choices ) / sizeof( wxString );
	m_GC2Type1 = new wxRadioBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_GC2Type1NChoices, m_GC2Type1Choices, 1, wxRA_SPECIFY_ROWS );
	m_GC2Type1->SetSelection( 0 );
	fgSizer8->Add( m_GC2Type1, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 2 );
	
	m_GC2c21 = new wxCheckBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_GC2c21, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2Test1 = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer8->Add( m_GC2Test1, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labGC2Port2 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC2Port2->Wrap( -1 );
	fgSizer8->Add( m_labGC2Port2, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC2EvtNN2 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer8->Add( m_GC2EvtNN2, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2EvtAddr2 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer8->Add( m_GC2EvtAddr2, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_GC2Type2Choices[] = { wxT(" "), wxT(" "), wxT(" "), wxT(" ") };
	int m_GC2Type2NChoices = sizeof( m_GC2Type2Choices ) / sizeof( wxString );
	m_GC2Type2 = new wxRadioBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_GC2Type2NChoices, m_GC2Type2Choices, 1, wxRA_SPECIFY_ROWS );
	m_GC2Type2->SetSelection( 0 );
	fgSizer8->Add( m_GC2Type2, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 2 );
	
	m_GC2c22 = new wxCheckBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_GC2c22, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2Test2 = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer8->Add( m_GC2Test2, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labGC2Port3 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC2Port3->Wrap( -1 );
	fgSizer8->Add( m_labGC2Port3, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC2EvtNN3 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer8->Add( m_GC2EvtNN3, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2EvtAddr3 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer8->Add( m_GC2EvtAddr3, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_GC2Type3Choices[] = { wxT(" "), wxT(" "), wxT(" "), wxT(" ") };
	int m_GC2Type3NChoices = sizeof( m_GC2Type3Choices ) / sizeof( wxString );
	m_GC2Type3 = new wxRadioBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_GC2Type3NChoices, m_GC2Type3Choices, 1, wxRA_SPECIFY_ROWS );
	m_GC2Type3->SetSelection( 0 );
	fgSizer8->Add( m_GC2Type3, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 2 );
	
	m_GC2c23 = new wxCheckBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_GC2c23, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2Test3 = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer8->Add( m_GC2Test3, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labGC2Port4 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC2Port4->Wrap( -1 );
	fgSizer8->Add( m_labGC2Port4, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC2EvtNN4 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer8->Add( m_GC2EvtNN4, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2EvtAddr4 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer8->Add( m_GC2EvtAddr4, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_GC2Type4Choices[] = { wxT(" "), wxT(" "), wxT(" "), wxT(" ") };
	int m_GC2Type4NChoices = sizeof( m_GC2Type4Choices ) / sizeof( wxString );
	m_GC2Type4 = new wxRadioBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_GC2Type4NChoices, m_GC2Type4Choices, 1, wxRA_SPECIFY_ROWS );
	m_GC2Type4->SetSelection( 0 );
	fgSizer8->Add( m_GC2Type4, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 2 );
	
	m_GC2c24 = new wxCheckBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_GC2c24, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2Test4 = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer8->Add( m_GC2Test4, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labGC2Port5 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC2Port5->Wrap( -1 );
	fgSizer8->Add( m_labGC2Port5, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC2EvtNN5 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer8->Add( m_GC2EvtNN5, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2EvtAddr5 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer8->Add( m_GC2EvtAddr5, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_GC2Type5Choices[] = { wxT(" "), wxT(" "), wxT(" "), wxT(" ") };
	int m_GC2Type5NChoices = sizeof( m_GC2Type5Choices ) / sizeof( wxString );
	m_GC2Type5 = new wxRadioBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_GC2Type5NChoices, m_GC2Type5Choices, 1, wxRA_SPECIFY_ROWS );
	m_GC2Type5->SetSelection( 0 );
	fgSizer8->Add( m_GC2Type5, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 2 );
	
	m_GC2c25 = new wxCheckBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_GC2c25, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2Test5 = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer8->Add( m_GC2Test5, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labGC2Port6 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC2Port6->Wrap( -1 );
	fgSizer8->Add( m_labGC2Port6, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC2EvtNN6 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer8->Add( m_GC2EvtNN6, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2EvtAddr6 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer8->Add( m_GC2EvtAddr6, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_GC2Type6Choices[] = { wxT(" "), wxT(" "), wxT(" "), wxT(" ") };
	int m_GC2Type6NChoices = sizeof( m_GC2Type6Choices ) / sizeof( wxString );
	m_GC2Type6 = new wxRadioBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_GC2Type6NChoices, m_GC2Type6Choices, 1, wxRA_SPECIFY_ROWS );
	m_GC2Type6->SetSelection( 0 );
	fgSizer8->Add( m_GC2Type6, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 2 );
	
	m_GC2c26 = new wxCheckBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_GC2c26, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2Test6 = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer8->Add( m_GC2Test6, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labGC2Port7 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC2Port7->Wrap( -1 );
	fgSizer8->Add( m_labGC2Port7, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC2EvtNN7 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer8->Add( m_GC2EvtNN7, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2EvtAddr7 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer8->Add( m_GC2EvtAddr7, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_GC2Type7Choices[] = { wxT(" "), wxT(" "), wxT(" "), wxT(" ") };
	int m_GC2Type7NChoices = sizeof( m_GC2Type7Choices ) / sizeof( wxString );
	m_GC2Type7 = new wxRadioBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_GC2Type7NChoices, m_GC2Type7Choices, 1, wxRA_SPECIFY_ROWS );
	m_GC2Type7->SetSelection( 0 );
	fgSizer8->Add( m_GC2Type7, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 2 );
	
	m_GC2c27 = new wxCheckBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_GC2c27, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2Test7 = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer8->Add( m_GC2Test7, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labGC2Port8 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC2Port8->Wrap( -1 );
	fgSizer8->Add( m_labGC2Port8, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC2EvtNN8 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer8->Add( m_GC2EvtNN8, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2EvtAddr8 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer8->Add( m_GC2EvtAddr8, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_GC2Type8Choices[] = { wxT(" "), wxT(" "), wxT(" "), wxT(" ") };
	int m_GC2Type8NChoices = sizeof( m_GC2Type8Choices ) / sizeof( wxString );
	m_GC2Type8 = new wxRadioBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_GC2Type8NChoices, m_GC2Type8Choices, 1, wxRA_SPECIFY_ROWS );
	m_GC2Type8->SetSelection( 0 );
	fgSizer8->Add( m_GC2Type8, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 2 );
	
	m_GC2c28 = new wxCheckBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_GC2c28, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2Test8 = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer8->Add( m_GC2Test8, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer17->Add( fgSizer8, 0, 0, 5 );
	
	m_staticline2 = new wxStaticLine( m_CANGC2Panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer17->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	wxFlexGridSizer* fgSizer81;
	fgSizer81 = new wxFlexGridSizer( 0, 6, 0, 0 );
	fgSizer81->SetFlexibleDirection( wxBOTH );
	fgSizer81->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_lab2GC2Port = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("Port"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lab2GC2Port->Wrap( -1 );
	fgSizer81->Add( m_lab2GC2Port, 0, wxTOP|wxLEFT, 5 );
	
	m_lab2GC2EvtNN = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("Node Nr."), wxDefaultPosition, wxDefaultSize, 0 );
	m_lab2GC2EvtNN->Wrap( -1 );
	fgSizer81->Add( m_lab2GC2EvtNN, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_lab2GC2EvtAddr = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("Event Nr."), wxDefaultPosition, wxDefaultSize, 0 );
	m_lab2GC2EvtAddr->Wrap( -1 );
	fgSizer81->Add( m_lab2GC2EvtAddr, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxGridSizer* gSizer11;
	gSizer11 = new wxGridSizer( 1, 4, 0, 0 );
	
	m_staticText1071 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("IN"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1071->Wrap( -1 );
	gSizer11->Add( m_staticText1071, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticText1081 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("BK"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1081->Wrap( -1 );
	gSizer11->Add( m_staticText1081, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticText1091 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("SW"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1091->Wrap( -1 );
	gSizer11->Add( m_staticText1091, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticText1101 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("PU"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1101->Wrap( -1 );
	gSizer11->Add( m_staticText1101, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	fgSizer81->Add( gSizer11, 1, wxEXPAND, 5 );
	
	m_lab2C2 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("Inv"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lab2C2->Wrap( -1 );
	fgSizer81->Add( m_lab2C2, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_lab2GC2Test = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("Test"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lab2GC2Test->Wrap( -1 );
	fgSizer81->Add( m_lab2GC2Test, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_labGC2Port9 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("9"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC2Port9->Wrap( -1 );
	fgSizer81->Add( m_labGC2Port9, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC2EvtNN9 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer81->Add( m_GC2EvtNN9, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2EvtAddr9 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer81->Add( m_GC2EvtAddr9, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_GC2Type9Choices[] = { wxT(" "), wxT(" "), wxT(" "), wxT(" ") };
	int m_GC2Type9NChoices = sizeof( m_GC2Type9Choices ) / sizeof( wxString );
	m_GC2Type9 = new wxRadioBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_GC2Type9NChoices, m_GC2Type9Choices, 1, wxRA_SPECIFY_ROWS );
	m_GC2Type9->SetSelection( 0 );
	fgSizer81->Add( m_GC2Type9, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 2 );
	
	m_GC2c29 = new wxCheckBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer81->Add( m_GC2c29, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2Test9 = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer81->Add( m_GC2Test9, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labGC2Port10 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC2Port10->Wrap( -1 );
	fgSizer81->Add( m_labGC2Port10, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC2EvtNN10 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer81->Add( m_GC2EvtNN10, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2EvtAddr10 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer81->Add( m_GC2EvtAddr10, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_GC2Type10Choices[] = { wxT(" "), wxT(" "), wxT(" "), wxT(" ") };
	int m_GC2Type10NChoices = sizeof( m_GC2Type10Choices ) / sizeof( wxString );
	m_GC2Type10 = new wxRadioBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_GC2Type10NChoices, m_GC2Type10Choices, 1, wxRA_SPECIFY_ROWS );
	m_GC2Type10->SetSelection( 0 );
	fgSizer81->Add( m_GC2Type10, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 2 );
	
	m_GC2c210 = new wxCheckBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer81->Add( m_GC2c210, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2Test10 = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer81->Add( m_GC2Test10, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labGC2Port11 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("11"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC2Port11->Wrap( -1 );
	fgSizer81->Add( m_labGC2Port11, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC2EvtNN11 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer81->Add( m_GC2EvtNN11, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2EvtAddr11 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer81->Add( m_GC2EvtAddr11, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_GC2Type11Choices[] = { wxT(" "), wxT(" "), wxT(" "), wxT(" ") };
	int m_GC2Type11NChoices = sizeof( m_GC2Type11Choices ) / sizeof( wxString );
	m_GC2Type11 = new wxRadioBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_GC2Type11NChoices, m_GC2Type11Choices, 1, wxRA_SPECIFY_ROWS );
	m_GC2Type11->SetSelection( 0 );
	fgSizer81->Add( m_GC2Type11, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 2 );
	
	m_GC2c211 = new wxCheckBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer81->Add( m_GC2c211, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2Test11 = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer81->Add( m_GC2Test11, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labGC2Port12 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("12"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC2Port12->Wrap( -1 );
	fgSizer81->Add( m_labGC2Port12, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC2EvtNN12 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer81->Add( m_GC2EvtNN12, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2EvtAddr12 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer81->Add( m_GC2EvtAddr12, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_GC2Type12Choices[] = { wxT(" "), wxT(" "), wxT(" "), wxT(" ") };
	int m_GC2Type12NChoices = sizeof( m_GC2Type12Choices ) / sizeof( wxString );
	m_GC2Type12 = new wxRadioBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_GC2Type12NChoices, m_GC2Type12Choices, 1, wxRA_SPECIFY_ROWS );
	m_GC2Type12->SetSelection( 0 );
	fgSizer81->Add( m_GC2Type12, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 2 );
	
	m_GC2c212 = new wxCheckBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer81->Add( m_GC2c212, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2Test12 = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer81->Add( m_GC2Test12, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labGC2Port13 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("13"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC2Port13->Wrap( -1 );
	fgSizer81->Add( m_labGC2Port13, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC2EvtNN13 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer81->Add( m_GC2EvtNN13, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2EvtAddr13 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer81->Add( m_GC2EvtAddr13, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_GC2Type13Choices[] = { wxT(" "), wxT(" "), wxT(" "), wxT(" ") };
	int m_GC2Type13NChoices = sizeof( m_GC2Type13Choices ) / sizeof( wxString );
	m_GC2Type13 = new wxRadioBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_GC2Type13NChoices, m_GC2Type13Choices, 1, wxRA_SPECIFY_ROWS );
	m_GC2Type13->SetSelection( 0 );
	fgSizer81->Add( m_GC2Type13, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 2 );
	
	m_GC2c213 = new wxCheckBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer81->Add( m_GC2c213, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2Test13 = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer81->Add( m_GC2Test13, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labGC2Port14 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("14"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC2Port14->Wrap( -1 );
	fgSizer81->Add( m_labGC2Port14, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC2EvtNN14 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer81->Add( m_GC2EvtNN14, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2EvtAddr14 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer81->Add( m_GC2EvtAddr14, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_GC2Type14Choices[] = { wxT(" "), wxT(" "), wxT(" "), wxT(" ") };
	int m_GC2Type14NChoices = sizeof( m_GC2Type14Choices ) / sizeof( wxString );
	m_GC2Type14 = new wxRadioBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_GC2Type14NChoices, m_GC2Type14Choices, 1, wxRA_SPECIFY_ROWS );
	m_GC2Type14->SetSelection( 0 );
	fgSizer81->Add( m_GC2Type14, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 2 );
	
	m_GC2c214 = new wxCheckBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer81->Add( m_GC2c214, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2Test14 = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer81->Add( m_GC2Test14, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labGC2Port15 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("15"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC2Port15->Wrap( -1 );
	fgSizer81->Add( m_labGC2Port15, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC2EvtNN15 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer81->Add( m_GC2EvtNN15, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2EvtAddr15 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer81->Add( m_GC2EvtAddr15, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_GC2Type15Choices[] = { wxT(" "), wxT(" "), wxT(" "), wxT(" ") };
	int m_GC2Type15NChoices = sizeof( m_GC2Type15Choices ) / sizeof( wxString );
	m_GC2Type15 = new wxRadioBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_GC2Type15NChoices, m_GC2Type15Choices, 1, wxRA_SPECIFY_ROWS );
	m_GC2Type15->SetSelection( 0 );
	fgSizer81->Add( m_GC2Type15, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 2 );
	
	m_GC2c215 = new wxCheckBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer81->Add( m_GC2c215, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2Test15 = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer81->Add( m_GC2Test15, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labGC2Port16 = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("16"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC2Port16->Wrap( -1 );
	fgSizer81->Add( m_labGC2Port16, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC2EvtNN16 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer81->Add( m_GC2EvtNN16, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2EvtAddr16 = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer81->Add( m_GC2EvtAddr16, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_GC2Type16Choices[] = { wxT(" "), wxT(" "), wxT(" "), wxT(" ") };
	int m_GC2Type16NChoices = sizeof( m_GC2Type16Choices ) / sizeof( wxString );
	m_GC2Type16 = new wxRadioBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_GC2Type16NChoices, m_GC2Type16Choices, 1, wxRA_SPECIFY_ROWS );
	m_GC2Type16->SetSelection( 0 );
	fgSizer81->Add( m_GC2Type16, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 2 );
	
	m_GC2c216 = new wxCheckBox( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer81->Add( m_GC2c216, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC2Test16 = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer81->Add( m_GC2Test16, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer17->Add( fgSizer81, 0, 0, 5 );
	
	bSizer151->Add( bSizer17, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_GC2GetAll = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("Get all"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer11->Add( m_GC2GetAll, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_GC2SetAll = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("Set all"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer11->Add( m_GC2SetAll, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_GC2SaveOutput = new wxCheckBox( m_CANGC2Panel, wxID_ANY, wxT("Save output state"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer11->Add( m_GC2SaveOutput, 0, wxALL, 5 );
	
	m_GC2Set = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("Set"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer11->Add( m_GC2Set, 0, wxLEFT, 5 );
	
	m_GC2SoD = new wxButton( m_CANGC2Panel, wxID_ANY, wxT("SoD"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer11->Add( m_GC2SoD, 0, wxLEFT, 5 );
	
	m_GC2ShortEvents = new wxCheckBox( m_CANGC2Panel, wxID_ANY, wxT("Short events"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer11->Add( m_GC2ShortEvents, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	bSizer16->Add( fgSizer11, 0, 0, 5 );
	
	wxFlexGridSizer* fgSizer13;
	fgSizer13 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer13->AddGrowableCol( 1 );
	fgSizer13->SetFlexibleDirection( wxBOTH );
	fgSizer13->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labSOD = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("SoD:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_labSOD->Wrap( -1 );
	fgSizer13->Add( m_labSOD, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_GC2SOD = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer13->Add( m_GC2SOD, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_GC2SODAll = new wxCheckBox( m_CANGC2Panel, wxID_ANY, wxT("All"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer13->Add( m_GC2SODAll, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_labGC2CanID = new wxStaticText( m_CANGC2Panel, wxID_ANY, wxT("CAN ID:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC2CanID->Wrap( -1 );
	fgSizer13->Add( m_labGC2CanID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GC2CanID = new wxSpinCtrl( m_CANGC2Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer13->Add( m_GC2CanID, 0, wxBOTTOM|wxRIGHT, 5 );
	
	bSizer16->Add( fgSizer13, 1, wxRIGHT, 5 );
	
	wxString m_GC2PulseTimeChoices[] = { wxT("250ms"), wxT("500ms"), wxT("1 sec."), wxT("2 sec.") };
	int m_GC2PulseTimeNChoices = sizeof( m_GC2PulseTimeChoices ) / sizeof( wxString );
	m_GC2PulseTime = new wxRadioBox( m_CANGC2Panel, wxID_ANY, wxT("Pulse time"), wxDefaultPosition, wxDefaultSize, m_GC2PulseTimeNChoices, m_GC2PulseTimeChoices, 2, wxRA_SPECIFY_ROWS );
	m_GC2PulseTime->SetSelection( 0 );
	bSizer16->Add( m_GC2PulseTime, 0, wxALL, 5 );
	
	bSizer151->Add( bSizer16, 0, 0, 5 );
	
	m_CANGC2Panel->SetSizer( bSizer151 );
	m_CANGC2Panel->Layout();
	bSizer151->Fit( m_CANGC2Panel );
	m_NoteBook->AddPage( m_CANGC2Panel, wxT("GC2"), false );
	m_CANGC4Panel = new wxPanel( m_NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* m_GC4RFIDBox;
	m_GC4RFIDBox = new wxStaticBoxSizer( new wxStaticBox( m_CANGC4Panel, wxID_ANY, wxT("RFID Evenr Nr.") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer21;
	fgSizer21 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer21->SetFlexibleDirection( wxBOTH );
	fgSizer21->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labGC4RFID1 = new wxStaticText( m_CANGC4Panel, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC4RFID1->Wrap( -1 );
	fgSizer21->Add( m_labGC4RFID1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC4RFID1 = new wxSpinCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer21->Add( m_GC4RFID1, 0, wxALL, 5 );
	
	m_labGC4RFID2 = new wxStaticText( m_CANGC4Panel, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC4RFID2->Wrap( -1 );
	fgSizer21->Add( m_labGC4RFID2, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GC4RFID2 = new wxSpinCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer21->Add( m_GC4RFID2, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_labGC4RFID3 = new wxStaticText( m_CANGC4Panel, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC4RFID3->Wrap( -1 );
	fgSizer21->Add( m_labGC4RFID3, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GC4RFID3 = new wxSpinCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer21->Add( m_GC4RFID3, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_labGC4RFID4 = new wxStaticText( m_CANGC4Panel, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC4RFID4->Wrap( -1 );
	fgSizer21->Add( m_labGC4RFID4, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GC4RFID4 = new wxSpinCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer21->Add( m_GC4RFID4, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_labGC4RFID5 = new wxStaticText( m_CANGC4Panel, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC4RFID5->Wrap( -1 );
	fgSizer21->Add( m_labGC4RFID5, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC4RFID5 = new wxSpinCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer21->Add( m_GC4RFID5, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_labGC4RFID6 = new wxStaticText( m_CANGC4Panel, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC4RFID6->Wrap( -1 );
	fgSizer21->Add( m_labGC4RFID6, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GC4RFID6 = new wxSpinCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer21->Add( m_GC4RFID6, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_labGC4RFID7 = new wxStaticText( m_CANGC4Panel, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC4RFID7->Wrap( -1 );
	fgSizer21->Add( m_labGC4RFID7, 0, wxBOTTOM|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC4RFID7 = new wxSpinCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer21->Add( m_GC4RFID7, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_labGC4RFID8 = new wxStaticText( m_CANGC4Panel, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC4RFID8->Wrap( -1 );
	fgSizer21->Add( m_labGC4RFID8, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GC4RFID8 = new wxSpinCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer21->Add( m_GC4RFID8, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GC4RFIDBox->Add( fgSizer21, 1, wxEXPAND, 5 );
	
	bSizer25->Add( m_GC4RFIDBox, 0, wxALL, 5 );
	
	wxStaticBoxSizer* m_GC4BlockBox;
	m_GC4BlockBox = new wxStaticBoxSizer( new wxStaticBox( m_CANGC4Panel, wxID_ANY, wxT("Sensor Event Nr.") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer22;
	fgSizer22 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer22->SetFlexibleDirection( wxBOTH );
	fgSizer22->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labGC4BK1 = new wxStaticText( m_CANGC4Panel, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC4BK1->Wrap( -1 );
	fgSizer22->Add( m_labGC4BK1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC4BK1 = new wxSpinCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer22->Add( m_GC4BK1, 0, wxALL, 5 );
	
	m_labGC4BK2 = new wxStaticText( m_CANGC4Panel, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC4BK2->Wrap( -1 );
	fgSizer22->Add( m_labGC4BK2, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GC4BK2 = new wxSpinCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer22->Add( m_GC4BK2, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_labGC4BK3 = new wxStaticText( m_CANGC4Panel, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC4BK3->Wrap( -1 );
	fgSizer22->Add( m_labGC4BK3, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GC4BK3 = new wxSpinCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer22->Add( m_GC4BK3, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_labGC4BK4 = new wxStaticText( m_CANGC4Panel, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC4BK4->Wrap( -1 );
	fgSizer22->Add( m_labGC4BK4, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GC4BK4 = new wxSpinCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer22->Add( m_GC4BK4, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_labGC4BK5 = new wxStaticText( m_CANGC4Panel, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC4BK5->Wrap( -1 );
	fgSizer22->Add( m_labGC4BK5, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GC4BK5 = new wxSpinCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer22->Add( m_GC4BK5, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_labGC4BK6 = new wxStaticText( m_CANGC4Panel, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC4BK6->Wrap( -1 );
	fgSizer22->Add( m_labGC4BK6, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GC4BK6 = new wxSpinCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer22->Add( m_GC4BK6, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_labGC4BK7 = new wxStaticText( m_CANGC4Panel, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC4BK7->Wrap( -1 );
	fgSizer22->Add( m_labGC4BK7, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GC4BK7 = new wxSpinCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer22->Add( m_GC4BK7, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_labGC4BK8 = new wxStaticText( m_CANGC4Panel, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC4BK8->Wrap( -1 );
	fgSizer22->Add( m_labGC4BK8, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GC4BK8 = new wxSpinCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer22->Add( m_GC4BK8, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GC4BlockBox->Add( fgSizer22, 1, wxEXPAND, 5 );
	
	bSizer25->Add( m_GC4BlockBox, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer271;
	bSizer271 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* m_GC4AllowedRFIDBox;
	m_GC4AllowedRFIDBox = new wxStaticBoxSizer( new wxStaticBox( m_CANGC4Panel, wxID_ANY, wxT("Allowed RFIDs") ), wxVERTICAL );
	
	m_GC4AllowedRFID1 = new wxTextCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	m_GC4AllowedRFIDBox->Add( m_GC4AllowedRFID1, 0, wxALL, 5 );
	
	m_GC4AllowedRFID2 = new wxTextCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	m_GC4AllowedRFIDBox->Add( m_GC4AllowedRFID2, 0, wxALL, 5 );
	
	m_GC4AllowedRFID3 = new wxTextCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	m_GC4AllowedRFIDBox->Add( m_GC4AllowedRFID3, 0, wxALL, 5 );
	
	m_GC4AllowedRFID4 = new wxTextCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	m_GC4AllowedRFIDBox->Add( m_GC4AllowedRFID4, 0, wxALL, 5 );
	
	m_GC4AllowedRFID5 = new wxTextCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	m_GC4AllowedRFIDBox->Add( m_GC4AllowedRFID5, 0, wxALL, 5 );
	
	bSizer271->Add( m_GC4AllowedRFIDBox, 0, wxALL, 5 );
	
	wxStaticBoxSizer* m_GC4OptionBox;
	m_GC4OptionBox = new wxStaticBoxSizer( new wxStaticBox( m_CANGC4Panel, wxID_ANY, wxT("Options") ), wxVERTICAL );
	
	m_GC4SaveRFID = new wxCheckBox( m_CANGC4Panel, wxID_ANY, wxT("Save RFIDs"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC4OptionBox->Add( m_GC4SaveRFID, 0, wxRIGHT|wxLEFT, 5 );
	
	m_GC4CheckRFID = new wxCheckBox( m_CANGC4Panel, wxID_ANY, wxT("Check RFIDs"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC4OptionBox->Add( m_GC4CheckRFID, 0, wxRIGHT|wxLEFT, 5 );
	
	m_GC4ReleaseRFID = new wxCheckBox( m_CANGC4Panel, wxID_ANY, wxT("Release RFIDs"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC4OptionBox->Add( m_GC4ReleaseRFID, 0, wxRIGHT|wxLEFT, 5 );
	
	m_GC4Acc4RFID = new wxCheckBox( m_CANGC4Panel, wxID_ANY, wxT("Accessory events for RFIDs"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC4OptionBox->Add( m_GC4Acc4RFID, 0, wxRIGHT|wxLEFT, 5 );
	
	bSizer271->Add( m_GC4OptionBox, 0, wxEXPAND, 5 );
	
	bSizer25->Add( bSizer271, 1, wxEXPAND, 5 );
	
	bSizer24->Add( bSizer25, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer261;
	bSizer261 = new wxBoxSizer( wxHORIZONTAL );
	
	m_GC4GetAll = new wxButton( m_CANGC4Panel, wxID_ANY, wxT("Get all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer261->Add( m_GC4GetAll, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC4SetAll = new wxButton( m_CANGC4Panel, wxID_ANY, wxT("Set all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer261->Add( m_GC4SetAll, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticline8 = new wxStaticLine( m_CANGC4Panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer261->Add( m_staticline8, 0, wxEXPAND | wxALL, 5 );
	
	m_labGC4CANID = new wxStaticText( m_CANGC4Panel, wxID_ANY, wxT("CanID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC4CANID->Wrap( -1 );
	bSizer261->Add( m_labGC4CANID, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_GC4CANID = new wxSpinCtrl( m_CANGC4Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	bSizer261->Add( m_GC4CANID, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_labGC4SOD = new wxStaticText( m_CANGC4Panel, wxID_ANY, wxT("SOD"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC4SOD->Wrap( -1 );
	bSizer261->Add( m_labGC4SOD, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_GC4SOD = new wxSpinCtrl( m_CANGC4Panel, wxID_ANY, wxT("4711"), wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	bSizer261->Add( m_GC4SOD, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	bSizer24->Add( bSizer261, 0, 0, 5 );
	
	m_CANGC4Panel->SetSizer( bSizer24 );
	m_CANGC4Panel->Layout();
	bSizer24->Fit( m_CANGC4Panel );
	m_NoteBook->AddPage( m_CANGC4Panel, wxT("GC4"), false );
	m_CANGC6Panel = new wxPanel( m_NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* m_GC6Servo1;
	m_GC6Servo1 = new wxStaticBoxSizer( new wxStaticBox( m_CANGC6Panel, wxID_ANY, wxT("Servo 1") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer61;
	fgSizer61 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer61->AddGrowableRow( 1 );
	fgSizer61->SetFlexibleDirection( wxVERTICAL );
	fgSizer61->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_GC6Servo1LTest = new wxButton( m_CANGC6Panel, wxID_ANY, wxT("L"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer61->Add( m_GC6Servo1LTest, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_GC6Servo1RTest = new wxButton( m_CANGC6Panel, wxID_ANY, wxT("R"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer61->Add( m_GC6Servo1RTest, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_labGC6Servo1Speed = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("SpL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6Servo1Speed->Wrap( -1 );
	fgSizer61->Add( m_labGC6Servo1Speed, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labGC6Servo1SpeedR = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("SpR"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6Servo1SpeedR->Wrap( -1 );
	fgSizer61->Add( m_labGC6Servo1SpeedR, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_GC6Servo1LeftAng = new wxSlider( m_CANGC6Panel, wxID_ANY, 100, 50, 250, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_INVERSE|wxSL_VERTICAL );
	fgSizer61->Add( m_GC6Servo1LeftAng, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxALL, 5 );
	
	m_GC6Servo1RightAng = new wxSlider( m_CANGC6Panel, wxID_ANY, 200, 50, 250, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_INVERSE|wxSL_VERTICAL );
	fgSizer61->Add( m_GC6Servo1RightAng, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxALL, 5 );
	
	m_GC6Servo1Speed = new wxSlider( m_CANGC6Panel, wxID_ANY, 5, 1, 20, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_INVERSE|wxSL_VERTICAL );
	fgSizer61->Add( m_GC6Servo1Speed, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxALL, 5 );
	
	m_GC6Servo1SpeedR = new wxSlider( m_CANGC6Panel, wxID_ANY, 5, 1, 20, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_INVERSE|wxSL_VERTICAL );
	fgSizer61->Add( m_GC6Servo1SpeedR, 0, wxALL|wxEXPAND, 5 );
	
	m_GC6Servo1->Add( fgSizer61, 1, 0, 5 );
	
	m_staticline4 = new wxStaticLine( m_CANGC6Panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_GC6Servo1->Add( m_staticline4, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	m_GC6Servo1Relay = new wxCheckBox( m_CANGC6Panel, wxID_ANY, wxT("Polarisation relay"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC6Servo1->Add( m_GC6Servo1Relay, 0, wxRIGHT|wxLEFT, 5 );
	
	m_GC6Servo1ExtFb = new wxCheckBox( m_CANGC6Panel, wxID_ANY, wxT("External Sensors"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC6Servo1->Add( m_GC6Servo1ExtFb, 0, wxRIGHT|wxLEFT, 5 );
	
	m_GC6Servo1Bounce = new wxCheckBox( m_CANGC6Panel, wxID_ANY, wxT("Bounce"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC6Servo1->Add( m_GC6Servo1Bounce, 0, wxRIGHT|wxLEFT, 5 );
	
	wxFlexGridSizer* fgSizer20;
	fgSizer20 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer20->SetFlexibleDirection( wxBOTH );
	fgSizer20->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labGC6Servo1SwEvent = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("Node Nr."), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6Servo1SwEvent->Wrap( -1 );
	fgSizer20->Add( m_labGC6Servo1SwEvent, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_labGC6Servo1SwAddr = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("Event Nr."), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6Servo1SwAddr->Wrap( -1 );
	fgSizer20->Add( m_labGC6Servo1SwAddr, 0, wxLEFT, 5 );
	
	m_GC6Servo1SwNN = new wxSpinCtrl( m_CANGC6Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer20->Add( m_GC6Servo1SwNN, 0, 0, 5 );
	
	m_GC6Servo1SwEvent = new wxSpinCtrl( m_CANGC6Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer20->Add( m_GC6Servo1SwEvent, 0, 0, 5 );
	
	m_labGC6SensorEvent = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("Sensor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6SensorEvent->Wrap( -1 );
	fgSizer20->Add( m_labGC6SensorEvent, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC6Servo1FbEvent = new wxSpinCtrl( m_CANGC6Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer20->Add( m_GC6Servo1FbEvent, 0, 0, 5 );
	
	m_GC6Servo1->Add( fgSizer20, 0, 0, 5 );
	
	bSizer26->Add( m_GC6Servo1, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* m_GC6Servo2;
	m_GC6Servo2 = new wxStaticBoxSizer( new wxStaticBox( m_CANGC6Panel, wxID_ANY, wxT("Servo 2") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer611;
	fgSizer611 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer611->AddGrowableRow( 1 );
	fgSizer611->SetFlexibleDirection( wxVERTICAL );
	fgSizer611->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_GC6Servo2LTest = new wxButton( m_CANGC6Panel, wxID_ANY, wxT("L"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer611->Add( m_GC6Servo2LTest, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_GC6Servo2RTest = new wxButton( m_CANGC6Panel, wxID_ANY, wxT("R"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer611->Add( m_GC6Servo2RTest, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_labGC6Servo2Speed = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("SpL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6Servo2Speed->Wrap( -1 );
	fgSizer611->Add( m_labGC6Servo2Speed, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_labGC6Servo2SpeedR = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("SpR"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6Servo2SpeedR->Wrap( -1 );
	fgSizer611->Add( m_labGC6Servo2SpeedR, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_GC6Servo2LeftAng = new wxSlider( m_CANGC6Panel, wxID_ANY, 100, 50, 250, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_INVERSE|wxSL_VERTICAL );
	fgSizer611->Add( m_GC6Servo2LeftAng, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_GC6Servo2RightAng = new wxSlider( m_CANGC6Panel, wxID_ANY, 200, 50, 250, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_INVERSE|wxSL_VERTICAL );
	fgSizer611->Add( m_GC6Servo2RightAng, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_GC6Servo2Speed = new wxSlider( m_CANGC6Panel, wxID_ANY, 5, 1, 20, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_INVERSE|wxSL_VERTICAL );
	fgSizer611->Add( m_GC6Servo2Speed, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_GC6Servo2SpeedR = new wxSlider( m_CANGC6Panel, wxID_ANY, 5, 1, 20, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_INVERSE|wxSL_VERTICAL );
	fgSizer611->Add( m_GC6Servo2SpeedR, 0, wxALL|wxEXPAND, 5 );
	
	m_GC6Servo2->Add( fgSizer611, 1, 0, 5 );
	
	m_staticline41 = new wxStaticLine( m_CANGC6Panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_GC6Servo2->Add( m_staticline41, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	m_GC6Servo2Relay = new wxCheckBox( m_CANGC6Panel, wxID_ANY, wxT("Polarisation relay"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC6Servo2->Add( m_GC6Servo2Relay, 0, wxRIGHT|wxLEFT, 5 );
	
	m_GC6Servo2ExtFb = new wxCheckBox( m_CANGC6Panel, wxID_ANY, wxT("External Sensors"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC6Servo2->Add( m_GC6Servo2ExtFb, 0, wxRIGHT|wxLEFT, 5 );
	
	m_GC6Servo2Bounce = new wxCheckBox( m_CANGC6Panel, wxID_ANY, wxT("Bounce"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC6Servo2->Add( m_GC6Servo2Bounce, 0, wxRIGHT|wxLEFT, 5 );
	
	wxFlexGridSizer* fgSizer201;
	fgSizer201 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer201->SetFlexibleDirection( wxBOTH );
	fgSizer201->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labGC6Servo2SwEvent = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("Node Nr."), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6Servo2SwEvent->Wrap( -1 );
	fgSizer201->Add( m_labGC6Servo2SwEvent, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_labGC6Servo2SwAddr = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("Event Nr."), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6Servo2SwAddr->Wrap( -1 );
	fgSizer201->Add( m_labGC6Servo2SwAddr, 0, wxLEFT, 5 );
	
	m_GC6Servo2SwNN = new wxSpinCtrl( m_CANGC6Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer201->Add( m_GC6Servo2SwNN, 0, 0, 5 );
	
	m_GC6Servo2SwEvent = new wxSpinCtrl( m_CANGC6Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer201->Add( m_GC6Servo2SwEvent, 0, 0, 5 );
	
	m_labGC6Servo2FbEvent = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("Sensor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6Servo2FbEvent->Wrap( -1 );
	fgSizer201->Add( m_labGC6Servo2FbEvent, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC6Servo2FbEvent = new wxSpinCtrl( m_CANGC6Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer201->Add( m_GC6Servo2FbEvent, 0, 0, 5 );
	
	m_GC6Servo2->Add( fgSizer201, 0, 0, 5 );
	
	bSizer26->Add( m_GC6Servo2, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* m_GC6Servo3;
	m_GC6Servo3 = new wxStaticBoxSizer( new wxStaticBox( m_CANGC6Panel, wxID_ANY, wxT("Servo 3") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer612;
	fgSizer612 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer612->AddGrowableRow( 1 );
	fgSizer612->SetFlexibleDirection( wxVERTICAL );
	fgSizer612->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_GC6Servo3LTest = new wxButton( m_CANGC6Panel, wxID_ANY, wxT("L"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer612->Add( m_GC6Servo3LTest, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_GC6Servo3RTest = new wxButton( m_CANGC6Panel, wxID_ANY, wxT("R"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer612->Add( m_GC6Servo3RTest, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_labGC6Servo3Speed = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("SpL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6Servo3Speed->Wrap( -1 );
	fgSizer612->Add( m_labGC6Servo3Speed, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_labGC6Servo3SpeedR = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("SpR"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6Servo3SpeedR->Wrap( -1 );
	fgSizer612->Add( m_labGC6Servo3SpeedR, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_GC6Servo3LeftAng = new wxSlider( m_CANGC6Panel, wxID_ANY, 100, 50, 250, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_INVERSE|wxSL_VERTICAL );
	fgSizer612->Add( m_GC6Servo3LeftAng, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_GC6Servo3RightAng = new wxSlider( m_CANGC6Panel, wxID_ANY, 200, 50, 250, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_INVERSE|wxSL_VERTICAL );
	fgSizer612->Add( m_GC6Servo3RightAng, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_GC6Servo3Speed = new wxSlider( m_CANGC6Panel, wxID_ANY, 5, 1, 20, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_INVERSE|wxSL_VERTICAL );
	fgSizer612->Add( m_GC6Servo3Speed, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_GC6Servo3SpeedR = new wxSlider( m_CANGC6Panel, wxID_ANY, 5, 1, 20, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_INVERSE|wxSL_VERTICAL );
	fgSizer612->Add( m_GC6Servo3SpeedR, 0, wxALL|wxEXPAND, 5 );
	
	m_GC6Servo3->Add( fgSizer612, 1, 0, 5 );
	
	m_staticline42 = new wxStaticLine( m_CANGC6Panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_GC6Servo3->Add( m_staticline42, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	m_GC6Servo3Relay = new wxCheckBox( m_CANGC6Panel, wxID_ANY, wxT("Polarisation relay"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC6Servo3->Add( m_GC6Servo3Relay, 0, wxRIGHT|wxLEFT, 5 );
	
	m_GC6Servo3ExtFb = new wxCheckBox( m_CANGC6Panel, wxID_ANY, wxT("External Sensors"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC6Servo3->Add( m_GC6Servo3ExtFb, 0, wxRIGHT|wxLEFT, 5 );
	
	m_GC6Servo3Bounce = new wxCheckBox( m_CANGC6Panel, wxID_ANY, wxT("Bounce"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC6Servo3->Add( m_GC6Servo3Bounce, 0, wxRIGHT|wxLEFT, 5 );
	
	wxFlexGridSizer* fgSizer202;
	fgSizer202 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer202->SetFlexibleDirection( wxBOTH );
	fgSizer202->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labGC6Servo3SwEvent = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("Node Nr."), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6Servo3SwEvent->Wrap( -1 );
	fgSizer202->Add( m_labGC6Servo3SwEvent, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_labGC6Servo3SwAddr = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("Event Nr."), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6Servo3SwAddr->Wrap( -1 );
	fgSizer202->Add( m_labGC6Servo3SwAddr, 0, wxLEFT, 5 );
	
	m_GC6Servo3SwNN = new wxSpinCtrl( m_CANGC6Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer202->Add( m_GC6Servo3SwNN, 0, wxLEFT, 5 );
	
	m_GC6Servo3SwEvent = new wxSpinCtrl( m_CANGC6Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer202->Add( m_GC6Servo3SwEvent, 0, 0, 5 );
	
	m_labGC6Servo3FbEvent = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("Sensor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6Servo3FbEvent->Wrap( -1 );
	fgSizer202->Add( m_labGC6Servo3FbEvent, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC6Servo3FbEvent = new wxSpinCtrl( m_CANGC6Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer202->Add( m_GC6Servo3FbEvent, 0, 0, 5 );
	
	m_GC6Servo3->Add( fgSizer202, 0, 0, 5 );
	
	bSizer26->Add( m_GC6Servo3, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* m_GC6Servo4;
	m_GC6Servo4 = new wxStaticBoxSizer( new wxStaticBox( m_CANGC6Panel, wxID_ANY, wxT("Servo 4") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer613;
	fgSizer613 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer613->AddGrowableRow( 1 );
	fgSizer613->SetFlexibleDirection( wxVERTICAL );
	fgSizer613->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_GC6Servo4LTest = new wxButton( m_CANGC6Panel, wxID_ANY, wxT("L"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer613->Add( m_GC6Servo4LTest, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_GC6Servo4RTest = new wxButton( m_CANGC6Panel, wxID_ANY, wxT("R"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	fgSizer613->Add( m_GC6Servo4RTest, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_labGC6Servo4Speed = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("SpL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6Servo4Speed->Wrap( -1 );
	fgSizer613->Add( m_labGC6Servo4Speed, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_labGC6Servo4SpeedR = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("SpR"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6Servo4SpeedR->Wrap( -1 );
	fgSizer613->Add( m_labGC6Servo4SpeedR, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_GC6Servo4LeftAng = new wxSlider( m_CANGC6Panel, wxID_ANY, 100, 50, 250, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_INVERSE|wxSL_VERTICAL );
	fgSizer613->Add( m_GC6Servo4LeftAng, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_GC6Servo4RightAng = new wxSlider( m_CANGC6Panel, wxID_ANY, 200, 50, 250, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_INVERSE|wxSL_VERTICAL );
	fgSizer613->Add( m_GC6Servo4RightAng, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_GC6Servo4Speed = new wxSlider( m_CANGC6Panel, wxID_ANY, 5, 1, 20, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_INVERSE|wxSL_VERTICAL );
	fgSizer613->Add( m_GC6Servo4Speed, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_GC6Servo4SpeedR = new wxSlider( m_CANGC6Panel, wxID_ANY, 5, 1, 20, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_INVERSE|wxSL_VERTICAL );
	fgSizer613->Add( m_GC6Servo4SpeedR, 0, wxALL|wxEXPAND, 5 );
	
	m_GC6Servo4->Add( fgSizer613, 1, 0, 5 );
	
	m_staticline43 = new wxStaticLine( m_CANGC6Panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_GC6Servo4->Add( m_staticline43, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	m_GC6Servo4Relay = new wxCheckBox( m_CANGC6Panel, wxID_ANY, wxT("Polarisation relay"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC6Servo4->Add( m_GC6Servo4Relay, 0, wxRIGHT|wxLEFT, 5 );
	
	m_GC6Servo4ExtFb = new wxCheckBox( m_CANGC6Panel, wxID_ANY, wxT("External Sensors"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC6Servo4->Add( m_GC6Servo4ExtFb, 0, wxRIGHT|wxLEFT, 5 );
	
	m_GC6Servo4Bounce = new wxCheckBox( m_CANGC6Panel, wxID_ANY, wxT("Bounce"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC6Servo4->Add( m_GC6Servo4Bounce, 0, wxRIGHT|wxLEFT, 5 );
	
	wxFlexGridSizer* fgSizer203;
	fgSizer203 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer203->SetFlexibleDirection( wxBOTH );
	fgSizer203->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labGC6Servo4SwEvent = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("Node Nr."), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6Servo4SwEvent->Wrap( -1 );
	fgSizer203->Add( m_labGC6Servo4SwEvent, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_labGC6Servo4SwAddr = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("Event Nr."), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6Servo4SwAddr->Wrap( -1 );
	fgSizer203->Add( m_labGC6Servo4SwAddr, 0, wxLEFT, 5 );
	
	m_GC6Servo4SwNN = new wxSpinCtrl( m_CANGC6Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer203->Add( m_GC6Servo4SwNN, 0, 0, 5 );
	
	m_GC6Servo4SwEvent = new wxSpinCtrl( m_CANGC6Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer203->Add( m_GC6Servo4SwEvent, 0, 0, 5 );
	
	m_labGC6Servo4FbEvent = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("Sensor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6Servo4FbEvent->Wrap( -1 );
	fgSizer203->Add( m_labGC6Servo4FbEvent, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC6Servo4FbEvent = new wxSpinCtrl( m_CANGC6Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer203->Add( m_GC6Servo4FbEvent, 0, 0, 5 );
	
	m_GC6Servo4->Add( fgSizer203, 0, 0, 5 );
	
	bSizer26->Add( m_GC6Servo4, 0, wxEXPAND|wxALL, 5 );
	
	bSizer81->Add( bSizer26, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );
	
	m_GC6GetAll = new wxButton( m_CANGC6Panel, wxID_ANY, wxT("Get all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer27->Add( m_GC6GetAll, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	m_GC6SetAll = new wxButton( m_CANGC6Panel, wxID_ANY, wxT("Set all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer27->Add( m_GC6SetAll, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	m_staticline7 = new wxStaticLine( m_CANGC6Panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer27->Add( m_staticline7, 0, wxEXPAND | wxALL, 5 );
	
	m_labGC6CanID = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("CanID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6CanID->Wrap( -1 );
	bSizer27->Add( m_labGC6CanID, 0, wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC6CanID = new wxSpinCtrl( m_CANGC6Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	bSizer27->Add( m_GC6CanID, 0, wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labGC6SOD = new wxStaticText( m_CANGC6Panel, wxID_ANY, wxT("SOD"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC6SOD->Wrap( -1 );
	bSizer27->Add( m_labGC6SOD, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_GC6SOD = new wxSpinCtrl( m_CANGC6Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	bSizer27->Add( m_GC6SOD, 0, wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC6ShortEvents = new wxCheckBox( m_CANGC6Panel, wxID_ANY, wxT("Short events"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer27->Add( m_GC6ShortEvents, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC6SaveServoPos = new wxCheckBox( m_CANGC6Panel, wxID_ANY, wxT("Save position"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer27->Add( m_GC6SaveServoPos, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer81->Add( bSizer27, 0, 0, 5 );
	
	m_CANGC6Panel->SetSizer( bSizer81 );
	m_CANGC6Panel->Layout();
	bSizer81->Fit( m_CANGC6Panel );
	m_NoteBook->AddPage( m_CANGC6Panel, wxT("GC6"), false );
	m_CANGC7Panel = new wxPanel( m_NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* m_GC7Options;
	m_GC7Options = new wxStaticBoxSizer( new wxStaticBox( m_CANGC7Panel, wxID_ANY, wxT("Options") ), wxVERTICAL );
	
	m_GC7ShowDate = new wxCheckBox( m_CANGC7Panel, wxID_ANY, wxT("Show date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC7Options->Add( m_GC7ShowDate, 0, wxALL, 5 );
	
	m_GC7ShowTemp = new wxCheckBox( m_CANGC7Panel, wxID_ANY, wxT("Show temperature"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC7Options->Add( m_GC7ShowTemp, 0, wxALL, 5 );
	
	m_GC7PosDisplay = new wxCheckBox( m_CANGC7Panel, wxID_ANY, wxT("Positive display"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC7Options->Add( m_GC7PosDisplay, 0, wxALL, 5 );
	
	bSizer19->Add( m_GC7Options, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* m_GC7Intensity;
	m_GC7Intensity = new wxStaticBoxSizer( new wxStaticBox( m_CANGC7Panel, wxID_ANY, wxT("Intensity") ), wxVERTICAL );
	
	m_GC7IntensitySlider = new wxSlider( m_CANGC7Panel, wxID_ANY, 6, 1, 12, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_INVERSE|wxSL_LABELS|wxSL_VERTICAL );
	m_GC7Intensity->Add( m_GC7IntensitySlider, 1, wxALL|wxEXPAND, 5 );
	
	bSizer19->Add( m_GC7Intensity, 0, wxEXPAND|wxALL, 5 );
	
	bSizer18->Add( bSizer19, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_GC7CANID = new wxStaticText( m_CANGC7Panel, wxID_ANY, wxT("CAN ID:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC7CANID->Wrap( -1 );
	fgSizer12->Add( m_GC7CANID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC7CanID = new wxSpinCtrl( m_CANGC7Panel, wxID_ANY, wxT("111"), wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 1, 127, 111 );
	fgSizer12->Add( m_GC7CanID, 0, wxALL, 5 );
	
	m_GC7SetCanID = new wxButton( m_CANGC7Panel, wxID_ANY, wxT("Set"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer12->Add( m_GC7SetCanID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer18->Add( fgSizer12, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );
	
	m_GC7GetAll = new wxButton( m_CANGC7Panel, wxID_ANY, wxT("Get all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_GC7GetAll, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer18->Add( bSizer21, 0, 0, 5 );
	
	m_CANGC7Panel->SetSizer( bSizer18 );
	m_CANGC7Panel->Layout();
	bSizer18->Fit( m_CANGC7Panel );
	m_NoteBook->AddPage( m_CANGC7Panel, wxT("GC7"), false );
	m_CANGC8 = new wxPanel( m_NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* m_GC8Display1Box;
	m_GC8Display1Box = new wxStaticBoxSizer( new wxStaticBox( m_CANGC8, wxID_ANY, wxT("Display 1") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer30;
	fgSizer30 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer30->SetFlexibleDirection( wxBOTH );
	fgSizer30->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labGC8Display1Event = new wxStaticText( m_CANGC8, wxID_ANY, wxT("Event number"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC8Display1Event->Wrap( -1 );
	fgSizer30->Add( m_labGC8Display1Event, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_GC8Display1Event = new wxSpinCtrl( m_CANGC8, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer30->Add( m_GC8Display1Event, 0, wxALL, 5 );
	
	m_labGC8Display1Contrast = new wxStaticText( m_CANGC8, wxID_ANY, wxT("Contrast"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC8Display1Contrast->Wrap( -1 );
	fgSizer30->Add( m_labGC8Display1Contrast, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_GC8Display1Contrast = new wxSpinCtrl( m_CANGC8, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 15, 0 );
	fgSizer30->Add( m_GC8Display1Contrast, 0, wxALL, 5 );
	
	m_GC8Display1Box->Add( fgSizer30, 1, wxEXPAND, 5 );
	
	m_GC8Display1FirstDH = new wxCheckBox( m_CANGC8, wxID_ANY, wxT("First line double high"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC8Display1Box->Add( m_GC8Display1FirstDH, 0, wxALL, 5 );
	
	m_GC8Display1Clock = new wxCheckBox( m_CANGC8, wxID_ANY, wxT("Show clock"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC8Display1Box->Add( m_GC8Display1Clock, 0, wxALL, 5 );
	
	bSizer33->Add( m_GC8Display1Box, 0, wxALL, 5 );
	
	wxStaticBoxSizer* m_GC8Display2Box;
	m_GC8Display2Box = new wxStaticBoxSizer( new wxStaticBox( m_CANGC8, wxID_ANY, wxT("Display 2") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer301;
	fgSizer301 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer301->SetFlexibleDirection( wxBOTH );
	fgSizer301->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labGC8Display2Event = new wxStaticText( m_CANGC8, wxID_ANY, wxT("Event number"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC8Display2Event->Wrap( -1 );
	fgSizer301->Add( m_labGC8Display2Event, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_GC8Display2Event = new wxSpinCtrl( m_CANGC8, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 120,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer301->Add( m_GC8Display2Event, 0, wxALL, 5 );
	
	m_labGC8Display2Contrast = new wxStaticText( m_CANGC8, wxID_ANY, wxT("Contrast"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC8Display2Contrast->Wrap( -1 );
	fgSizer301->Add( m_labGC8Display2Contrast, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_GC8Display2Contrast = new wxSpinCtrl( m_CANGC8, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 15, 0 );
	fgSizer301->Add( m_GC8Display2Contrast, 0, wxALL, 5 );
	
	m_GC8Display2Box->Add( fgSizer301, 1, wxEXPAND, 5 );
	
	m_GC8Display2FirstDH = new wxCheckBox( m_CANGC8, wxID_ANY, wxT("First line double high"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC8Display2Box->Add( m_GC8Display2FirstDH, 0, wxALL, 5 );
	
	m_GC8Display2Clock = new wxCheckBox( m_CANGC8, wxID_ANY, wxT("Show clock"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GC8Display2Box->Add( m_GC8Display2Clock, 0, wxALL, 5 );
	
	bSizer33->Add( m_GC8Display2Box, 0, wxALL, 5 );
	
	bSizer32->Add( bSizer33, 0, 0, 5 );
	
	wxStaticBoxSizer* m_GC8CBus;
	m_GC8CBus = new wxStaticBoxSizer( new wxStaticBox( m_CANGC8, wxID_ANY, wxT("CBUS") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer33;
	fgSizer33 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer33->SetFlexibleDirection( wxBOTH );
	fgSizer33->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labGC8CANID = new wxStaticText( m_CANGC8, wxID_ANY, wxT("CANID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGC8CANID->Wrap( -1 );
	fgSizer33->Add( m_labGC8CANID, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GC8CANID = new wxSpinCtrl( m_CANGC8, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 127, 0 );
	fgSizer33->Add( m_GC8CANID, 0, wxALL, 5 );
	
	m_GC8CBus->Add( fgSizer33, 1, wxEXPAND, 5 );
	
	bSizer32->Add( m_GC8CBus, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );
	
	m_GC8GetAll = new wxButton( m_CANGC8, wxID_ANY, wxT("Get all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( m_GC8GetAll, 0, wxALL, 5 );
	
	m_GC8SetAll = new wxButton( m_CANGC8, wxID_ANY, wxT("Set all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( m_GC8SetAll, 0, wxALL, 5 );
	
	bSizer32->Add( bSizer34, 0, 0, 5 );
	
	m_CANGC8->SetSizer( bSizer32 );
	m_CANGC8->Layout();
	bSizer32->Fit( m_CANGC8 );
	m_NoteBook->AddPage( m_CANGC8, wxT("GC8"), false );
	m_CANGCLN = new wxPanel( m_NoteBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* m_GCLNLocoNetBox;
	m_GCLNLocoNetBox = new wxStaticBoxSizer( new wxStaticBox( m_CANGCLN, wxID_ANY, wxT("LocoNet") ), wxVERTICAL );
	
	m_GCLNReadOnly = new wxCheckBox( m_CANGCLN, wxID_ANY, wxT("Read only"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GCLNLocoNetBox->Add( m_GCLNReadOnly, 0, wxALL, 5 );
	
	m_GCLNCBusSensorEvents = new wxCheckBox( m_CANGCLN, wxID_ANY, wxT("CBUS sensor events"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GCLNLocoNetBox->Add( m_GCLNCBusSensorEvents, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GCLNSoD = new wxCheckBox( m_CANGCLN, wxID_ANY, wxT("Start of day"), wxDefaultPosition, wxDefaultSize, 0 );
	m_GCLNLocoNetBox->Add( m_GCLNSoD, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	bSizer30->Add( m_GCLNLocoNetBox, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* m_GCLNCBusBox;
	m_GCLNCBusBox = new wxStaticBoxSizer( new wxStaticBox( m_CANGCLN, wxID_ANY, wxT("CBUS") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer27;
	fgSizer27 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer27->AddGrowableCol( 1 );
	fgSizer27->SetFlexibleDirection( wxBOTH );
	fgSizer27->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labGCLNCanID = new wxStaticText( m_CANGCLN, wxID_ANY, wxT("CANID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGCLNCanID->Wrap( -1 );
	fgSizer27->Add( m_labGCLNCanID, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_GCLNCANID = new wxSpinCtrl( m_CANGCLN, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 127, 0 );
	fgSizer27->Add( m_GCLNCANID, 0, wxALL, 5 );
	
	m_labGCLNSoD = new wxStaticText( m_CANGCLN, wxID_ANY, wxT("SoD"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGCLNSoD->Wrap( -1 );
	fgSizer27->Add( m_labGCLNSoD, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GCLNSoDAddr = new wxSpinCtrl( m_CANGCLN, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer27->Add( m_GCLNSoDAddr, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GCLNCBusBox->Add( fgSizer27, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer28;
	fgSizer28 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer28->SetFlexibleDirection( wxBOTH );
	fgSizer28->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labGCLNSwitchFilter = new wxStaticText( m_CANGCLN, wxID_ANY, wxT("Switch filter"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGCLNSwitchFilter->Wrap( -1 );
	fgSizer28->Add( m_labGCLNSwitchFilter, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_GCLNSwitchFilterStart = new wxSpinCtrl( m_CANGCLN, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer28->Add( m_GCLNSwitchFilterStart, 0, wxALL, 5 );
	
	m_GCLNSwitchFilterEnd = new wxSpinCtrl( m_CANGCLN, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer28->Add( m_GCLNSwitchFilterEnd, 0, wxALL, 5 );
	
	m_labGCLNSensorFilter = new wxStaticText( m_CANGCLN, wxID_ANY, wxT("Sensor filter"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labGCLNSensorFilter->Wrap( -1 );
	fgSizer28->Add( m_labGCLNSensorFilter, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GCLNSensorFilterStart = new wxSpinCtrl( m_CANGCLN, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer28->Add( m_GCLNSensorFilterStart, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GCLNSensorFilterEnd = new wxSpinCtrl( m_CANGCLN, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer28->Add( m_GCLNSensorFilterEnd, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_GCLNCBusBox->Add( fgSizer28, 1, wxEXPAND, 5 );
	
	bSizer30->Add( m_GCLNCBusBox, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );
	
	m_GCLNGetAll = new wxButton( m_CANGCLN, wxID_ANY, wxT("Get all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( m_GCLNGetAll, 0, wxALL, 5 );
	
	m_GCLNSetAll = new wxButton( m_CANGCLN, wxID_ANY, wxT("Set all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( m_GCLNSetAll, 0, wxALL, 5 );
	
	bSizer30->Add( bSizer31, 0, wxEXPAND, 5 );
	
	m_CANGCLN->SetSizer( bSizer30 );
	m_CANGCLN->Layout();
	bSizer30->Fit( m_CANGCLN );
	m_NoteBook->AddPage( m_CANGCLN, wxT("GCLN"), false );
	
	bSizer1->Add( m_NoteBook, 1, wxEXPAND | wxALL, 5 );
	
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
	
	// Connect Events
	m_CBusLogo->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( cbusnodedlggen::onLogo ), NULL, this );
	m_GCALogo->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( cbusnodedlggen::onGCA ), NULL, this );
	m_SetNodeNumber->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onSetNodeNumber ), NULL, this );
	m_IndexList2->Connect( wxEVT_COMMAND_LIST_COL_CLICK, wxListEventHandler( cbusnodedlggen::onIndexLeftClick ), NULL, this );
	m_IndexList2->Connect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( cbusnodedlggen::onIndexActivated ), NULL, this );
	m_IndexList2->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( cbusnodedlggen::onIndexSelect2 ), NULL, this );
	m_QueryNN->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onQuery ), NULL, this );
	m_Report->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onReport ), NULL, this );
	m_VarList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onVarSelect ), NULL, this );
	m_VarValue->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onVarValue ), NULL, this );
	m_VarValue->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cbusnodedlggen::onVarValueText ), NULL, this );
	m_VarBit7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarBit ), NULL, this );
	m_VarBit6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarBit ), NULL, this );
	m_VarBit5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarBit ), NULL, this );
	m_VarBit4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarBit ), NULL, this );
	m_VarBit3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarBit ), NULL, this );
	m_VarBit2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarBit ), NULL, this );
	m_VarBit1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarBit ), NULL, this );
	m_VarBit0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarBit ), NULL, this );
	m_VarGet->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarGet ), NULL, this );
	m_VarSet->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarSet ), NULL, this );
	m_EventList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onEventSelect ), NULL, this );
	m_EventVar->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onEV ), NULL, this );
	m_EventVar->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cbusnodedlggen::onEVText ), NULL, this );
	m_EvtGetVar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEvtGetVar ), NULL, this );
	m_EVBit7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEVBit ), NULL, this );
	m_EVBit6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEVBit ), NULL, this );
	m_EVBit5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEVBit ), NULL, this );
	m_EVBit4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEVBit ), NULL, this );
	m_EVBit3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEVBit ), NULL, this );
	m_EVBit2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEVBit ), NULL, this );
	m_EVBit1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEVBit ), NULL, this );
	m_EVBit0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEVBit ), NULL, this );
	m_EventGetAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEventGetAll ), NULL, this );
	m_EventAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEventAdd ), NULL, this );
	m_EventDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEventDelete ), NULL, this );
	m_EvtClearAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEvtClearAll ), NULL, this );
	m_EvtLearn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onLearn ), NULL, this );
	m_EvtUnlearn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onUnlearn ), NULL, this );
	m_HexFile->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onHexFile ), NULL, this );
	m_HEXFileSend->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onHEXFileSend ), NULL, this );
	m_BootMode->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onBootmode ), NULL, this );
	m_ResetBoot->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onResetBoot ), NULL, this );
	m_GC1eIdleWD->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC1eIdleWatchDog ), NULL, this );
	m_GC1eGetAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC1eGetAll ), NULL, this );
	m_GC1eSetAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC1eSetAll ), NULL, this );
	m_GC2Type1->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType1 ), NULL, this );
	m_GC2Test1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type2->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType2 ), NULL, this );
	m_GC2Test2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type3->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType3 ), NULL, this );
	m_GC2Test3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type4->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType4 ), NULL, this );
	m_GC2Test4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type5->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType5 ), NULL, this );
	m_GC2Test5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type6->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType6 ), NULL, this );
	m_GC2Test6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type7->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType7 ), NULL, this );
	m_GC2Test7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type8->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType8 ), NULL, this );
	m_GC2Test8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type9->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType9 ), NULL, this );
	m_GC2Test9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type10->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType10 ), NULL, this );
	m_GC2Test10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type11->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType11 ), NULL, this );
	m_GC2Test11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type12->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType12 ), NULL, this );
	m_GC2Test12->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type13->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType13 ), NULL, this );
	m_GC2Test13->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type14->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType14 ), NULL, this );
	m_GC2Test14->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type15->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType15 ), NULL, this );
	m_GC2Test15->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type16->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType16 ), NULL, this );
	m_GC2Test16->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2GetAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2GetAll ), NULL, this );
	m_GC2SetAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2SetAll ), NULL, this );
	m_GC2Set->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Set ), NULL, this );
	m_GC2SoD->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onSoD ), NULL, this );
	m_GC4GetAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC4GetAll ), NULL, this );
	m_GC4SetAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC4SetAll ), NULL, this );
	m_GC6Servo1LTest->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6Servo1LTest ), NULL, this );
	m_GC6Servo1RTest->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6Servo1RTest ), NULL, this );
	m_GC6Servo1LeftAng->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoLeftAngle ), NULL, this );
	m_GC6Servo1RightAng->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoRightAngle ), NULL, this );
	m_GC6Servo1Speed->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoSpeed ), NULL, this );
	m_GC6Servo1SpeedR->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoSpeed ), NULL, this );
	m_GC6Servo1Relay->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnServoRelay ), NULL, this );
	m_GC6Servo1ExtFb->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnExtSensors ), NULL, this );
	m_GC6Servo1Bounce->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnBounce ), NULL, this );
	m_GC6Servo1SwEvent->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onGC6SwEvent ), NULL, this );
	m_GC6Servo1FbEvent->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onGC6FbEvent ), NULL, this );
	m_GC6Servo2LTest->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6Servo2LTest ), NULL, this );
	m_GC6Servo2RTest->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6Servo2RTest ), NULL, this );
	m_GC6Servo2LeftAng->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoLeftAngle ), NULL, this );
	m_GC6Servo2RightAng->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoRightAngle ), NULL, this );
	m_GC6Servo2Speed->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoSpeed ), NULL, this );
	m_GC6Servo2SpeedR->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoSpeed ), NULL, this );
	m_GC6Servo2Relay->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnServoRelay ), NULL, this );
	m_GC6Servo2ExtFb->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnExtSensors ), NULL, this );
	m_GC6Servo2Bounce->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnBounce ), NULL, this );
	m_GC6Servo2SwEvent->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onGC6SwEvent ), NULL, this );
	m_GC6Servo2FbEvent->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onGC6FbEvent ), NULL, this );
	m_GC6Servo3LTest->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6Servo3LTest ), NULL, this );
	m_GC6Servo3RTest->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6Servo3RTest ), NULL, this );
	m_GC6Servo3LeftAng->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoLeftAngle ), NULL, this );
	m_GC6Servo3RightAng->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoRightAngle ), NULL, this );
	m_GC6Servo3Speed->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoSpeed ), NULL, this );
	m_GC6Servo3SpeedR->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoSpeed ), NULL, this );
	m_GC6Servo3Relay->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnServoRelay ), NULL, this );
	m_GC6Servo3ExtFb->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnExtSensors ), NULL, this );
	m_GC6Servo3Bounce->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnBounce ), NULL, this );
	m_GC6Servo3SwEvent->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onGC6SwEvent ), NULL, this );
	m_GC6Servo3FbEvent->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onGC6FbEvent ), NULL, this );
	m_GC6Servo4LTest->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6Servo4LTest ), NULL, this );
	m_GC6Servo4RTest->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6Servo4RTest ), NULL, this );
	m_GC6Servo4LeftAng->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoLeftAngle ), NULL, this );
	m_GC6Servo4RightAng->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoRightAngle ), NULL, this );
	m_GC6Servo4Speed->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoSpeed ), NULL, this );
	m_GC6Servo4SpeedR->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoSpeed ), NULL, this );
	m_GC6Servo4Relay->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnServoRelay ), NULL, this );
	m_GC6Servo4ExtFb->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnExtSensors ), NULL, this );
	m_GC6Servo4Bounce->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnBounce ), NULL, this );
	m_GC6Servo4SwEvent->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onGC6SwEvent ), NULL, this );
	m_GC6Servo4FbEvent->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onGC6FbEvent ), NULL, this );
	m_GC6GetAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6GetAll ), NULL, this );
	m_GC6SetAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6SetAll ), NULL, this );
	m_GC7ShowDate->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC7ShowDate ), NULL, this );
	m_GC7ShowTemp->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC7ShowTemp ), NULL, this );
	m_GC7PosDisplay->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC7PosDisplay ), NULL, this );
	m_GC7IntensitySlider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::onGC7Intensity ), NULL, this );
	m_GC7SetCanID->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC7SetCanID ), NULL, this );
	m_GC7GetAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC7GetAll ), NULL, this );
	m_GC8GetAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC8GetAll ), NULL, this );
	m_GC8SetAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC8SetAll ), NULL, this );
	m_GCLNGetAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGCLNGetAll ), NULL, this );
	m_GCLNSetAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGCLNSetAll ), NULL, this );
	m_stdButtonHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onHelp ), NULL, this );
	m_stdButtonOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onOK ), NULL, this );
}

cbusnodedlggen::~cbusnodedlggen()
{
	// Disconnect Events
	m_CBusLogo->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( cbusnodedlggen::onLogo ), NULL, this );
	m_GCALogo->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( cbusnodedlggen::onGCA ), NULL, this );
	m_SetNodeNumber->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onSetNodeNumber ), NULL, this );
	m_IndexList2->Disconnect( wxEVT_COMMAND_LIST_COL_CLICK, wxListEventHandler( cbusnodedlggen::onIndexLeftClick ), NULL, this );
	m_IndexList2->Disconnect( wxEVT_COMMAND_LIST_ITEM_ACTIVATED, wxListEventHandler( cbusnodedlggen::onIndexActivated ), NULL, this );
	m_IndexList2->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( cbusnodedlggen::onIndexSelect2 ), NULL, this );
	m_QueryNN->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onQuery ), NULL, this );
	m_Report->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onReport ), NULL, this );
	m_VarList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onVarSelect ), NULL, this );
	m_VarValue->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onVarValue ), NULL, this );
	m_VarValue->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cbusnodedlggen::onVarValueText ), NULL, this );
	m_VarBit7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarBit ), NULL, this );
	m_VarBit6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarBit ), NULL, this );
	m_VarBit5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarBit ), NULL, this );
	m_VarBit4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarBit ), NULL, this );
	m_VarBit3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarBit ), NULL, this );
	m_VarBit2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarBit ), NULL, this );
	m_VarBit1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarBit ), NULL, this );
	m_VarBit0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarBit ), NULL, this );
	m_VarGet->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarGet ), NULL, this );
	m_VarSet->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onVarSet ), NULL, this );
	m_EventList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onEventSelect ), NULL, this );
	m_EventVar->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onEV ), NULL, this );
	m_EventVar->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cbusnodedlggen::onEVText ), NULL, this );
	m_EvtGetVar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEvtGetVar ), NULL, this );
	m_EVBit7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEVBit ), NULL, this );
	m_EVBit6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEVBit ), NULL, this );
	m_EVBit5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEVBit ), NULL, this );
	m_EVBit4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEVBit ), NULL, this );
	m_EVBit3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEVBit ), NULL, this );
	m_EVBit2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEVBit ), NULL, this );
	m_EVBit1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEVBit ), NULL, this );
	m_EVBit0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEVBit ), NULL, this );
	m_EventGetAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEventGetAll ), NULL, this );
	m_EventAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEventAdd ), NULL, this );
	m_EventDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEventDelete ), NULL, this );
	m_EvtClearAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onEvtClearAll ), NULL, this );
	m_EvtLearn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onLearn ), NULL, this );
	m_EvtUnlearn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onUnlearn ), NULL, this );
	m_HexFile->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onHexFile ), NULL, this );
	m_HEXFileSend->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onHEXFileSend ), NULL, this );
	m_BootMode->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onBootmode ), NULL, this );
	m_ResetBoot->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onResetBoot ), NULL, this );
	m_GC1eIdleWD->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC1eIdleWatchDog ), NULL, this );
	m_GC1eGetAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC1eGetAll ), NULL, this );
	m_GC1eSetAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC1eSetAll ), NULL, this );
	m_GC2Type1->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType1 ), NULL, this );
	m_GC2Test1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type2->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType2 ), NULL, this );
	m_GC2Test2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type3->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType3 ), NULL, this );
	m_GC2Test3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type4->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType4 ), NULL, this );
	m_GC2Test4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type5->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType5 ), NULL, this );
	m_GC2Test5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type6->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType6 ), NULL, this );
	m_GC2Test6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type7->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType7 ), NULL, this );
	m_GC2Test7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type8->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType8 ), NULL, this );
	m_GC2Test8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type9->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType9 ), NULL, this );
	m_GC2Test9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type10->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType10 ), NULL, this );
	m_GC2Test10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type11->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType11 ), NULL, this );
	m_GC2Test11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type12->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType12 ), NULL, this );
	m_GC2Test12->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type13->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType13 ), NULL, this );
	m_GC2Test13->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type14->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType14 ), NULL, this );
	m_GC2Test14->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type15->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType15 ), NULL, this );
	m_GC2Test15->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2Type16->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( cbusnodedlggen::onGC2PortType16 ), NULL, this );
	m_GC2Test16->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Test ), NULL, this );
	m_GC2GetAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2GetAll ), NULL, this );
	m_GC2SetAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2SetAll ), NULL, this );
	m_GC2Set->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC2Set ), NULL, this );
	m_GC2SoD->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onSoD ), NULL, this );
	m_GC4GetAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC4GetAll ), NULL, this );
	m_GC4SetAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC4SetAll ), NULL, this );
	m_GC6Servo1LTest->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6Servo1LTest ), NULL, this );
	m_GC6Servo1RTest->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6Servo1RTest ), NULL, this );
	m_GC6Servo1LeftAng->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoLeftAngle ), NULL, this );
	m_GC6Servo1RightAng->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoRightAngle ), NULL, this );
	m_GC6Servo1Speed->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoSpeed ), NULL, this );
	m_GC6Servo1SpeedR->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoSpeed ), NULL, this );
	m_GC6Servo1Relay->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnServoRelay ), NULL, this );
	m_GC6Servo1ExtFb->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnExtSensors ), NULL, this );
	m_GC6Servo1Bounce->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnBounce ), NULL, this );
	m_GC6Servo1SwEvent->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onGC6SwEvent ), NULL, this );
	m_GC6Servo1FbEvent->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onGC6FbEvent ), NULL, this );
	m_GC6Servo2LTest->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6Servo2LTest ), NULL, this );
	m_GC6Servo2RTest->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6Servo2RTest ), NULL, this );
	m_GC6Servo2LeftAng->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoLeftAngle ), NULL, this );
	m_GC6Servo2RightAng->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoRightAngle ), NULL, this );
	m_GC6Servo2Speed->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoSpeed ), NULL, this );
	m_GC6Servo2SpeedR->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoSpeed ), NULL, this );
	m_GC6Servo2Relay->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnServoRelay ), NULL, this );
	m_GC6Servo2ExtFb->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnExtSensors ), NULL, this );
	m_GC6Servo2Bounce->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnBounce ), NULL, this );
	m_GC6Servo2SwEvent->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onGC6SwEvent ), NULL, this );
	m_GC6Servo2FbEvent->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onGC6FbEvent ), NULL, this );
	m_GC6Servo3LTest->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6Servo3LTest ), NULL, this );
	m_GC6Servo3RTest->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6Servo3RTest ), NULL, this );
	m_GC6Servo3LeftAng->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoLeftAngle ), NULL, this );
	m_GC6Servo3RightAng->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoRightAngle ), NULL, this );
	m_GC6Servo3Speed->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoSpeed ), NULL, this );
	m_GC6Servo3SpeedR->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoSpeed ), NULL, this );
	m_GC6Servo3Relay->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnServoRelay ), NULL, this );
	m_GC6Servo3ExtFb->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnExtSensors ), NULL, this );
	m_GC6Servo3Bounce->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnBounce ), NULL, this );
	m_GC6Servo3SwEvent->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onGC6SwEvent ), NULL, this );
	m_GC6Servo3FbEvent->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onGC6FbEvent ), NULL, this );
	m_GC6Servo4LTest->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6Servo4LTest ), NULL, this );
	m_GC6Servo4RTest->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6Servo4RTest ), NULL, this );
	m_GC6Servo4LeftAng->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoLeftAngle ), NULL, this );
	m_GC6Servo4RightAng->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoRightAngle ), NULL, this );
	m_GC6Servo4Speed->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoSpeed ), NULL, this );
	m_GC6Servo4SpeedR->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::OnServoSpeed ), NULL, this );
	m_GC6Servo4Relay->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnServoRelay ), NULL, this );
	m_GC6Servo4ExtFb->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnExtSensors ), NULL, this );
	m_GC6Servo4Bounce->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::OnBounce ), NULL, this );
	m_GC6Servo4SwEvent->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onGC6SwEvent ), NULL, this );
	m_GC6Servo4FbEvent->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( cbusnodedlggen::onGC6FbEvent ), NULL, this );
	m_GC6GetAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6GetAll ), NULL, this );
	m_GC6SetAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC6SetAll ), NULL, this );
	m_GC7ShowDate->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC7ShowDate ), NULL, this );
	m_GC7ShowTemp->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC7ShowTemp ), NULL, this );
	m_GC7PosDisplay->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC7PosDisplay ), NULL, this );
	m_GC7IntensitySlider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( cbusnodedlggen::onGC7Intensity ), NULL, this );
	m_GC7SetCanID->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC7SetCanID ), NULL, this );
	m_GC7GetAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC7GetAll ), NULL, this );
	m_GC8GetAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC8GetAll ), NULL, this );
	m_GC8SetAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGC8SetAll ), NULL, this );
	m_GCLNGetAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGCLNGetAll ), NULL, this );
	m_GCLNSetAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onGCLNSetAll ), NULL, this );
	m_stdButtonHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onHelp ), NULL, this );
	m_stdButtonOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cbusnodedlggen::onOK ), NULL, this );
	
}
