///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "accdecgendlg.h"

///////////////////////////////////////////////////////////////////////////

AccDecGenDlg::AccDecGenDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_Notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_IndexPanel = new wxPanel( m_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_IndexList = new wxListCtrl( m_IndexPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_SINGLE_SEL );
	bSizer2->Add( m_IndexList, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Add = new wxButton( m_IndexPanel, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_Add, 0, wxALL, 5 );
	
	m_Delete = new wxButton( m_IndexPanel, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_Delete, 0, wxALL, 5 );
	
	m_Doc = new wxButton( m_IndexPanel, wxID_ANY, wxT("Documentation"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_Doc, 0, wxALL, 5 );
	
	bSizer2->Add( bSizer3, 0, 0, 5 );
	
	m_IndexPanel->SetSizer( bSizer2 );
	m_IndexPanel->Layout();
	bSizer2->Fit( m_IndexPanel );
	m_Notebook->AddPage( m_IndexPanel, wxT("Index"), false );
	m_GeneralPanel = new wxPanel( m_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_Image = new wxBitmapButton( m_GeneralPanel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer4->Add( m_Image, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labIID = new wxStaticText( m_GeneralPanel, wxID_ANY, wxT("IID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labIID->Wrap( -1 );
	fgSizer1->Add( m_labIID, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_IID = new wxComboBox( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer1->Add( m_IID, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labID = new wxStaticText( m_GeneralPanel, wxID_ANY, wxT("ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labID->Wrap( -1 );
	fgSizer1->Add( m_labID, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_ID = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_ID, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labImageFile = new wxStaticText( m_GeneralPanel, wxID_ANY, wxT("Image file"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labImageFile->Wrap( -1 );
	fgSizer1->Add( m_labImageFile, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_ImageFile = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_ImageFile, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer4->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labBus = new wxStaticText( m_GeneralPanel, wxID_ANY, wxT("Bus"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labBus->Wrap( -1 );
	fgSizer2->Add( m_labBus, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_Bus = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer2->Add( m_Bus, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labAddr = new wxStaticText( m_GeneralPanel, wxID_ANY, wxT("Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labAddr->Wrap( -1 );
	fgSizer2->Add( m_labAddr, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_Addr = new wxSpinCtrl( m_GeneralPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 0, 65535, 0 );
	fgSizer2->Add( m_Addr, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer4->Add( fgSizer2, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labProt = new wxStaticText( m_GeneralPanel, wxID_ANY, wxT("Protocol"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labProt->Wrap( -1 );
	fgSizer3->Add( m_labProt, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_Protocol = new wxComboBox( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_DROPDOWN|wxCB_READONLY|wxCB_SIMPLE ); 
	fgSizer3->Add( m_Protocol, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labVersion = new wxStaticText( m_GeneralPanel, wxID_ANY, wxT("Version"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labVersion->Wrap( -1 );
	fgSizer3->Add( m_labVersion, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_Version = new wxSpinCtrl( m_GeneralPanel, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize( -1,-1 ), wxSP_ARROW_KEYS, 0, 100, 0 );
	fgSizer3->Add( m_Version, 0, wxALL|wxEXPAND, 5 );
	
	m_labManu = new wxStaticText( m_GeneralPanel, wxID_ANY, wxT("Manu"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labManu->Wrap( -1 );
	fgSizer3->Add( m_labManu, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_Manu = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_Manu, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_labCatNr = new wxStaticText( m_GeneralPanel, wxID_ANY, wxT("CatNr"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labCatNr->Wrap( -1 );
	fgSizer3->Add( m_labCatNr, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_CatNr = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_CatNr, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer4->Add( fgSizer3, 0, wxEXPAND, 5 );
	
	m_labDesc = new wxStaticText( m_GeneralPanel, wxID_ANY, wxT("Description"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labDesc->Wrap( -1 );
	bSizer4->Add( m_labDesc, 0, wxALL, 5 );
	
	m_Desc = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	m_Desc->SetMinSize( wxSize( -1,80 ) );
	
	bSizer4->Add( m_Desc, 0, wxALL|wxEXPAND, 5 );
	
	m_GeneralPanel->SetSizer( bSizer4 );
	m_GeneralPanel->Layout();
	bSizer4->Fit( m_GeneralPanel );
	m_Notebook->AddPage( m_GeneralPanel, wxT("Generel"), false );
	m_CVPanel = new wxPanel( m_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
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
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer4->AddGrowableCol( 1 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labCVDesc = new wxStaticText( m_CVPanel, wxID_ANY, wxT("Remark"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labCVDesc->Wrap( -1 );
	fgSizer4->Add( m_labCVDesc, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_CVDescription = new wxTextCtrl( m_CVPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_CVDescription, 0, wxALL|wxEXPAND, 5 );
	
	m_CVDescModify = new wxButton( m_CVPanel, wxID_ANY, wxT("Modify"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer4->Add( m_CVDescModify, 0, wxALL, 5 );
	
	bSizer5->Add( fgSizer4, 0, wxEXPAND, 5 );
	
	m_CVPanel->SetSizer( bSizer5 );
	m_CVPanel->Layout();
	bSizer5->Fit( m_CVPanel );
	m_Notebook->AddPage( m_CVPanel, wxT("CV"), false );
	
	bSizer1->Add( m_Notebook, 1, wxEXPAND | wxALL, 5 );
	
	m_StdButton = new wxStdDialogButtonSizer();
	m_StdButtonOK = new wxButton( this, wxID_OK );
	m_StdButton->AddButton( m_StdButtonOK );
	m_StdButtonApply = new wxButton( this, wxID_APPLY );
	m_StdButton->AddButton( m_StdButtonApply );
	m_StdButtonCancel = new wxButton( this, wxID_CANCEL );
	m_StdButton->AddButton( m_StdButtonCancel );
	m_StdButtonHelp = new wxButton( this, wxID_HELP );
	m_StdButton->AddButton( m_StdButtonHelp );
	m_StdButton->Realize();
	bSizer1->Add( m_StdButton, 0, wxALL|wxALIGN_RIGHT|wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_IndexList->Connect( wxEVT_COMMAND_LIST_COL_CLICK, wxListEventHandler( AccDecGenDlg::onColClick ), NULL, this );
	m_IndexList->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( AccDecGenDlg::onSelected ), NULL, this );
	m_Add->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccDecGenDlg::onAdd ), NULL, this );
	m_Delete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccDecGenDlg::onDelete ), NULL, this );
	m_Doc->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccDecGenDlg::onDoc ), NULL, this );
	m_Image->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccDecGenDlg::onImage ), NULL, this );
	m_CVList->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( AccDecGenDlg::onCVCell ), NULL, this );
	m_CVDescModify->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccDecGenDlg::onCVModify ), NULL, this );
	m_StdButtonApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccDecGenDlg::onApply ), NULL, this );
	m_StdButtonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccDecGenDlg::onCancel ), NULL, this );
	m_StdButtonHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccDecGenDlg::onHelp ), NULL, this );
	m_StdButtonOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccDecGenDlg::onOK ), NULL, this );
}

AccDecGenDlg::~AccDecGenDlg()
{
	// Disconnect Events
	m_IndexList->Disconnect( wxEVT_COMMAND_LIST_COL_CLICK, wxListEventHandler( AccDecGenDlg::onColClick ), NULL, this );
	m_IndexList->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( AccDecGenDlg::onSelected ), NULL, this );
	m_Add->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccDecGenDlg::onAdd ), NULL, this );
	m_Delete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccDecGenDlg::onDelete ), NULL, this );
	m_Doc->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccDecGenDlg::onDoc ), NULL, this );
	m_Image->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccDecGenDlg::onImage ), NULL, this );
	m_CVList->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( AccDecGenDlg::onCVCell ), NULL, this );
	m_CVDescModify->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccDecGenDlg::onCVModify ), NULL, this );
	m_StdButtonApply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccDecGenDlg::onApply ), NULL, this );
	m_StdButtonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccDecGenDlg::onCancel ), NULL, this );
	m_StdButtonHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccDecGenDlg::onHelp ), NULL, this );
	m_StdButtonOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AccDecGenDlg::onOK ), NULL, this );
	
}
