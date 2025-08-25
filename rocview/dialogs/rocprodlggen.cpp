///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "rocprodlggen.h"

///////////////////////////////////////////////////////////////////////////

RocProDlgGen::RocProDlgGen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	m_DecTree = new wxTreeCtrl( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTR_DEFAULT_STYLE|wxRAISED_BORDER );
	m_DecTree->SetMinSize( wxSize( 200,-1 ) );
	
	bSizer10->Add( m_DecTree, 1, wxALL|wxEXPAND, 5 );
	
	m_labInfo = new wxStaticText( this, wxID_ANY, wxT("CV Information:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labInfo->Wrap( -1 );
	bSizer10->Add( m_labInfo, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_Info = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,60 ), wxTE_MULTILINE|wxTE_PROCESS_ENTER );
	bSizer10->Add( m_Info, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	bSizer8->Add( bSizer10, 1, wxEXPAND, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer8->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	m_ImageSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_LocoImage = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( -1,80 ), wxFULL_REPAINT_ON_RESIZE );
	m_LocoImage->SetMaxSize( wxSize( -1,80 ) );
	
	m_ImageSizer->Add( m_LocoImage, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticline21 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	m_ImageSizer->Add( m_staticline21, 0, wxEXPAND | wxALL, 5 );
	
	m_DecoderImage = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxSize( -1,80 ), wxFULL_REPAINT_ON_RESIZE );
	m_DecoderImage->SetMaxSize( wxSize( -1,80 ) );
	
	m_ImageSizer->Add( m_DecoderImage, 0, wxALL, 5 );
	
	bSizer9->Add( m_ImageSizer, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer4->AddGrowableCol( 2 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labIID = new wxStaticText( this, wxID_ANY, wxT("IID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labIID->Wrap( -1 );
	fgSizer4->Add( m_labIID, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_IID = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	m_IID->SetMinSize( wxSize( 180,-1 ) );
	
	fgSizer4->Add( m_IID, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_LocoList = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,25 ), 0, NULL, wxCB_READONLY|wxCB_SIMPLE ); 
	fgSizer4->Add( m_LocoList, 0, wxEXPAND|wxTOP|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer9->Add( fgSizer4, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer8->AddGrowableCol( 1 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labFile = new wxStaticText( this, wxID_ANY, wxT("Decoder"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labFile->Wrap( -1 );
	fgSizer8->Add( m_labFile, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_DecFile = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 200,-1 ), 0 );
	fgSizer8->Add( m_DecFile, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxHORIZONTAL );
	
	m_DecFileOpen = new wxButton( this, wxID_ANY, wxT("Open..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer81->Add( m_DecFileOpen, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT, 5 );
	
	m_SaveAs = new wxButton( this, wxID_ANY, wxT("Save..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer81->Add( m_SaveAs, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT, 5 );
	
	fgSizer8->Add( bSizer81, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labImage = new wxStaticText( this, wxID_ANY, wxT("Image"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labImage->Wrap( -1 );
	fgSizer8->Add( m_labImage, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_Image = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_Image, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_ImgFileOpen = new wxButton( this, wxID_ANY, wxT("Open..."), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_ImgFileOpen, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT, 5 );
	
	bSizer9->Add( fgSizer8, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("CV") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer9;
	fgSizer9 = new wxFlexGridSizer( 0, 11, 0, 0 );
	fgSizer9->SetFlexibleDirection( wxBOTH );
	fgSizer9->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labNr = new wxStaticText( this, wxID_ANY, wxT("Nr"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labNr->Wrap( -1 );
	fgSizer9->Add( m_labNr, 0, wxRIGHT|wxLEFT, 5 );
	
	m_labValue = new wxStaticText( this, wxID_ANY, wxT("Value"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labValue->Wrap( -1 );
	fgSizer9->Add( m_labValue, 0, wxRIGHT|wxLEFT, 5 );
	
	m_labHexValue = new wxStaticText( this, wxID_ANY, wxT("Value (Hex)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labHexValue->Wrap( -1 );
	fgSizer9->Add( m_labHexValue, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer9->Add( m_staticText4, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxLEFT, 5 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	fgSizer9->Add( m_staticText5, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	fgSizer9->Add( m_staticText6, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer9->Add( m_staticText7, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer9->Add( m_staticText8, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	fgSizer9->Add( m_staticText9, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	fgSizer9->Add( m_staticText10, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	fgSizer9->Add( m_staticText11, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_Nr = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 1024, 1 );
	fgSizer9->Add( m_Nr, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_Value = new wxSpinCtrl( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS|wxSP_WRAP, 0, 65535, 0 );
	fgSizer9->Add( m_Value, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_HexValue = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxTE_PROCESS_ENTER );
	fgSizer9->Add( m_HexValue, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Bit7 = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_Bit7, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );
	
	m_Bit6 = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_Bit6, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Bit5 = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_Bit5, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Bit4 = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_Bit4, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Bit3 = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_Bit3, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Bit2 = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_Bit2, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Bit1 = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_Bit1, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Bit0 = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer9->Add( m_Bit0, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizer3->Add( fgSizer9, 0, 0, 5 );
	
	m_ValueSlider = new wxSlider( this, wxID_ANY, 0, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	sbSizer3->Add( m_ValueSlider, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_ReadCV = new wxButton( this, wxID_ANY, wxT("Read"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_ReadCV, 0, wxRIGHT|wxLEFT, 5 );
	
	m_ReadAllCV = new wxButton( this, wxID_ANY, wxT("Read All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_ReadAllCV, 0, wxRIGHT|wxLEFT, 5 );
	
	m_WriteCV = new wxButton( this, wxID_ANY, wxT("Write"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_WriteCV, 0, wxRIGHT|wxLEFT, 5 );
	
	m_POM = new wxCheckBox( this, wxID_ANY, wxT("PoM"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_POM, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_Accessory = new wxCheckBox( this, wxID_ANY, wxT("Accessory"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_Accessory, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_SaveCV = new wxCheckBox( this, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_SaveCV, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizer3->Add( bSizer5, 0, wxEXPAND, 5 );
	
	wxString m_ModeChoices[] = { wxT("page"), wxT("direct"), wxT("register") };
	int m_ModeNChoices = sizeof( m_ModeChoices ) / sizeof( wxString );
	m_Mode = new wxRadioBox( this, wxID_ANY, wxT("Mode"), wxDefaultPosition, wxDefaultSize, m_ModeNChoices, m_ModeChoices, 1, wxRA_SPECIFY_ROWS );
	m_Mode->SetSelection( 0 );
	sbSizer3->Add( m_Mode, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	bSizer9->Add( sbSizer3, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* sbSizer31;
	sbSizer31 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Extended Address") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_ExtAddr = new wxSpinCtrl( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 100,-1 ), wxSP_ARROW_KEYS, 1, 16383, 1 );
	fgSizer3->Add( m_ExtAddr, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_ExtAddrRead = new wxButton( this, wxID_ANY, wxT("Read"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_ExtAddrRead, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_ExtAddrWrite = new wxButton( this, wxID_ANY, wxT("Write"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_ExtAddrWrite, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_ExtAddrBidi = new wxCheckBox( this, wxID_ANY, wxT("CV117/118"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer3->Add( m_ExtAddrBidi, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	sbSizer31->Add( fgSizer3, 0, wxEXPAND, 5 );
	
	bSizer9->Add( sbSizer31, 0, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	wxStaticBoxSizer* m_Special;
	m_Special = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Special") ), wxVERTICAL );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_VCurve = new wxButton( this, wxID_ANY, wxT("V Curve..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_VCurve, 0, wxRIGHT|wxLEFT, 5 );
	
	m_CVURL = new wxButton( this, wxID_ANY, wxT("URL"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_CVURL, 0, wxRIGHT|wxLEFT, 5 );
	
	m_DIP = new wxButton( this, wxID_ANY, wxT("DIP..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_DIP, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );
	
	m_PT = new wxToggleButton( this, wxID_ANY, wxT("PT"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_PT, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Special->Add( bSizer6, 0, wxEXPAND|wxALIGN_RIGHT, 5 );
	
	bSizer9->Add( m_Special, 0, wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	bSizer8->Add( bSizer9, 0, wxEXPAND, 5 );
	
	bSizer7->Add( bSizer8, 1, wxEXPAND, 5 );
	
	m_sdbSizer2 = new wxStdDialogButtonSizer();
	m_sdbSizer2OK = new wxButton( this, wxID_OK );
	m_sdbSizer2->AddButton( m_sdbSizer2OK );
	m_sdbSizer2Help = new wxButton( this, wxID_HELP );
	m_sdbSizer2->AddButton( m_sdbSizer2Help );
	m_sdbSizer2->Realize();
	bSizer7->Add( m_sdbSizer2, 0, wxALL|wxALIGN_RIGHT|wxEXPAND, 5 );
	
	this->SetSizer( bSizer7 );
	this->Layout();
	bSizer7->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( RocProDlgGen::onClose ) );
	m_DecTree->Connect( wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler( RocProDlgGen::onTreeDIP ), NULL, this );
	m_DecTree->Connect( wxEVT_COMMAND_TREE_ITEM_MENU, wxTreeEventHandler( RocProDlgGen::onTreeItemPopup ), NULL, this );
	m_DecTree->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( RocProDlgGen::onTreeSelChanged ), NULL, this );
	m_Info->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( RocProDlgGen::onCVInfoEnter ), NULL, this );
	m_LocoList->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( RocProDlgGen::onLocoList ), NULL, this );
	m_DecFileOpen->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onOpen ), NULL, this );
	m_SaveAs->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onSaveAs ), NULL, this );
	m_ImgFileOpen->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onImgOpen ), NULL, this );
	m_Nr->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( RocProDlgGen::onNr ), NULL, this );
	m_Nr->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( RocProDlgGen::onNrText ), NULL, this );
	m_Value->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( RocProDlgGen::onValue ), NULL, this );
	m_Value->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( RocProDlgGen::onValueText ), NULL, this );
	m_HexValue->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( RocProDlgGen::onHexValue ), NULL, this );
	m_Bit7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( RocProDlgGen::onBit ), NULL, this );
	m_Bit6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( RocProDlgGen::onBit ), NULL, this );
	m_Bit5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( RocProDlgGen::onBit ), NULL, this );
	m_Bit4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( RocProDlgGen::onBit ), NULL, this );
	m_Bit3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( RocProDlgGen::onBit ), NULL, this );
	m_Bit2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( RocProDlgGen::onBit ), NULL, this );
	m_Bit1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( RocProDlgGen::onBit ), NULL, this );
	m_Bit0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( RocProDlgGen::onBit ), NULL, this );
	m_ValueSlider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( RocProDlgGen::onValueSlider ), NULL, this );
	m_ReadCV->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onRead ), NULL, this );
	m_ReadAllCV->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onReadAllCV ), NULL, this );
	m_WriteCV->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onWrite ), NULL, this );
	m_SaveCV->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( RocProDlgGen::onSaveCV ), NULL, this );
	m_ExtAddrRead->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onExtAddrRead ), NULL, this );
	m_ExtAddrWrite->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onExtAddrWrite ), NULL, this );
	m_VCurve->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onVCurve ), NULL, this );
	m_CVURL->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onCVURL ), NULL, this );
	m_DIP->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onDIP ), NULL, this );
	m_PT->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onPT ), NULL, this );
	m_sdbSizer2Help->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onHelp ), NULL, this );
	m_sdbSizer2OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onOK ), NULL, this );
}

RocProDlgGen::~RocProDlgGen()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( RocProDlgGen::onClose ) );
	m_DecTree->Disconnect( wxEVT_COMMAND_TREE_ITEM_ACTIVATED, wxTreeEventHandler( RocProDlgGen::onTreeDIP ), NULL, this );
	m_DecTree->Disconnect( wxEVT_COMMAND_TREE_ITEM_MENU, wxTreeEventHandler( RocProDlgGen::onTreeItemPopup ), NULL, this );
	m_DecTree->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( RocProDlgGen::onTreeSelChanged ), NULL, this );
	m_Info->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( RocProDlgGen::onCVInfoEnter ), NULL, this );
	m_LocoList->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( RocProDlgGen::onLocoList ), NULL, this );
	m_DecFileOpen->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onOpen ), NULL, this );
	m_SaveAs->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onSaveAs ), NULL, this );
	m_ImgFileOpen->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onImgOpen ), NULL, this );
	m_Nr->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( RocProDlgGen::onNr ), NULL, this );
	m_Nr->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( RocProDlgGen::onNrText ), NULL, this );
	m_Value->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( RocProDlgGen::onValue ), NULL, this );
	m_Value->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( RocProDlgGen::onValueText ), NULL, this );
	m_HexValue->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( RocProDlgGen::onHexValue ), NULL, this );
	m_Bit7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( RocProDlgGen::onBit ), NULL, this );
	m_Bit6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( RocProDlgGen::onBit ), NULL, this );
	m_Bit5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( RocProDlgGen::onBit ), NULL, this );
	m_Bit4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( RocProDlgGen::onBit ), NULL, this );
	m_Bit3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( RocProDlgGen::onBit ), NULL, this );
	m_Bit2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( RocProDlgGen::onBit ), NULL, this );
	m_Bit1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( RocProDlgGen::onBit ), NULL, this );
	m_Bit0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( RocProDlgGen::onBit ), NULL, this );
	m_ValueSlider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( RocProDlgGen::onValueSlider ), NULL, this );
	m_ReadCV->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onRead ), NULL, this );
	m_ReadAllCV->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onReadAllCV ), NULL, this );
	m_WriteCV->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onWrite ), NULL, this );
	m_SaveCV->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( RocProDlgGen::onSaveCV ), NULL, this );
	m_ExtAddrRead->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onExtAddrRead ), NULL, this );
	m_ExtAddrWrite->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onExtAddrWrite ), NULL, this );
	m_VCurve->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onVCurve ), NULL, this );
	m_CVURL->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onCVURL ), NULL, this );
	m_DIP->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onDIP ), NULL, this );
	m_PT->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onPT ), NULL, this );
	m_sdbSizer2Help->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onHelp ), NULL, this );
	m_sdbSizer2OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RocProDlgGen::onOK ), NULL, this );
	
}
