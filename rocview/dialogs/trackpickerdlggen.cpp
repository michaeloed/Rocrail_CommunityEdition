///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "trackpickerdlggen.h"

///////////////////////////////////////////////////////////////////////////

TrackPickerDlgGen::TrackPickerDlgGen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_TrackBook = new wxListbook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLB_LEFT );
	m_PageTrack = new wxPanel( m_TrackBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_GridTrack = new wxGrid( m_PageTrack, wxID_ANY, wxDefaultPosition, wxSize( 128,240 ), 0 );
	
	// Grid
	m_GridTrack->CreateGrid( 5, 1 );
	m_GridTrack->EnableEditing( false );
	m_GridTrack->EnableGridLines( false );
	m_GridTrack->EnableDragGridSize( false );
	m_GridTrack->SetMargins( 0, 0 );
	
	// Columns
	m_GridTrack->AutoSizeColumns();
	m_GridTrack->EnableDragColMove( false );
	m_GridTrack->EnableDragColSize( true );
	m_GridTrack->SetColLabelSize( 0 );
	m_GridTrack->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_GridTrack->AutoSizeRows();
	m_GridTrack->EnableDragRowSize( true );
	m_GridTrack->SetRowLabelSize( 0 );
	m_GridTrack->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_GridTrack->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	bSizer2->Add( m_GridTrack, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_PageTrack->SetSizer( bSizer2 );
	m_PageTrack->Layout();
	bSizer2->Fit( m_PageTrack );
	m_TrackBook->AddPage( m_PageTrack, wxT("Track"), true );
	m_PageSwitch = new wxPanel( m_TrackBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_GridSwitch = new wxGrid( m_PageSwitch, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	
	// Grid
	m_GridSwitch->CreateGrid( 5, 1 );
	m_GridSwitch->EnableEditing( false );
	m_GridSwitch->EnableGridLines( false );
	m_GridSwitch->EnableDragGridSize( false );
	m_GridSwitch->SetMargins( 0, 0 );
	
	// Columns
	m_GridSwitch->AutoSizeColumns();
	m_GridSwitch->EnableDragColMove( false );
	m_GridSwitch->EnableDragColSize( true );
	m_GridSwitch->SetColLabelSize( 0 );
	m_GridSwitch->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_GridSwitch->AutoSizeRows();
	m_GridSwitch->EnableDragRowSize( true );
	m_GridSwitch->SetRowLabelSize( 0 );
	m_GridSwitch->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_GridSwitch->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	bSizer3->Add( m_GridSwitch, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_PageSwitch->SetSizer( bSizer3 );
	m_PageSwitch->Layout();
	bSizer3->Fit( m_PageSwitch );
	m_TrackBook->AddPage( m_PageSwitch, wxT("Switch"), true );
	m_PageSignal = new wxPanel( m_TrackBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_GridSignal = new wxGrid( m_PageSignal, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	
	// Grid
	m_GridSignal->CreateGrid( 5, 1 );
	m_GridSignal->EnableEditing( false );
	m_GridSignal->EnableGridLines( false );
	m_GridSignal->EnableDragGridSize( false );
	m_GridSignal->SetMargins( 0, 0 );
	
	// Columns
	m_GridSignal->AutoSizeColumns();
	m_GridSignal->EnableDragColMove( false );
	m_GridSignal->EnableDragColSize( true );
	m_GridSignal->SetColLabelSize( 0 );
	m_GridSignal->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_GridSignal->AutoSizeRows();
	m_GridSignal->EnableDragRowSize( true );
	m_GridSignal->SetRowLabelSize( 0 );
	m_GridSignal->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_GridSignal->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	bSizer4->Add( m_GridSignal, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_PageSignal->SetSizer( bSizer4 );
	m_PageSignal->Layout();
	bSizer4->Fit( m_PageSignal );
	m_TrackBook->AddPage( m_PageSignal, wxT("Signal"), false );
	m_PageBlock = new wxPanel( m_TrackBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_GridBlock = new wxGrid( m_PageBlock, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	
	// Grid
	m_GridBlock->CreateGrid( 5, 1 );
	m_GridBlock->EnableEditing( false );
	m_GridBlock->EnableGridLines( false );
	m_GridBlock->EnableDragGridSize( false );
	m_GridBlock->SetMargins( 0, 0 );
	
	// Columns
	m_GridBlock->AutoSizeColumns();
	m_GridBlock->EnableDragColMove( false );
	m_GridBlock->EnableDragColSize( true );
	m_GridBlock->SetColLabelSize( 0 );
	m_GridBlock->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_GridBlock->AutoSizeRows();
	m_GridBlock->EnableDragRowSize( true );
	m_GridBlock->SetRowLabelSize( 0 );
	m_GridBlock->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_GridBlock->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	bSizer5->Add( m_GridBlock, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_PageBlock->SetSizer( bSizer5 );
	m_PageBlock->Layout();
	bSizer5->Fit( m_PageBlock );
	m_TrackBook->AddPage( m_PageBlock, wxT("Block"), false );
	m_PageSensor = new wxPanel( m_TrackBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	m_GridSensor = new wxGrid( m_PageSensor, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	
	// Grid
	m_GridSensor->CreateGrid( 5, 1 );
	m_GridSensor->EnableEditing( false );
	m_GridSensor->EnableGridLines( false );
	m_GridSensor->EnableDragGridSize( false );
	m_GridSensor->SetMargins( 0, 0 );
	
	// Columns
	m_GridSensor->AutoSizeColumns();
	m_GridSensor->EnableDragColMove( false );
	m_GridSensor->EnableDragColSize( true );
	m_GridSensor->SetColLabelSize( 0 );
	m_GridSensor->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_GridSensor->AutoSizeRows();
	m_GridSensor->EnableDragRowSize( true );
	m_GridSensor->SetRowLabelSize( 0 );
	m_GridSensor->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_GridSensor->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	bSizer8->Add( m_GridSensor, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_PageSensor->SetSizer( bSizer8 );
	m_PageSensor->Layout();
	bSizer8->Fit( m_PageSensor );
	m_TrackBook->AddPage( m_PageSensor, wxT("Sensor"), false );
	m_PageAccessory = new wxPanel( m_TrackBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_GridAccessory = new wxGrid( m_PageAccessory, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	
	// Grid
	m_GridAccessory->CreateGrid( 5, 1 );
	m_GridAccessory->EnableEditing( false );
	m_GridAccessory->EnableGridLines( false );
	m_GridAccessory->EnableDragGridSize( false );
	m_GridAccessory->SetMargins( 0, 0 );
	
	// Columns
	m_GridAccessory->AutoSizeColumns();
	m_GridAccessory->EnableDragColMove( false );
	m_GridAccessory->EnableDragColSize( true );
	m_GridAccessory->SetColLabelSize( 0 );
	m_GridAccessory->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_GridAccessory->AutoSizeRows();
	m_GridAccessory->EnableDragRowSize( true );
	m_GridAccessory->SetRowLabelSize( 0 );
	m_GridAccessory->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_GridAccessory->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	bSizer6->Add( m_GridAccessory, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_PageAccessory->SetSizer( bSizer6 );
	m_PageAccessory->Layout();
	bSizer6->Fit( m_PageAccessory );
	m_TrackBook->AddPage( m_PageAccessory, wxT("Accessory"), false );
	m_PageRoad = new wxPanel( m_TrackBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	m_GridRoad = new wxGrid( m_PageRoad, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	
	// Grid
	m_GridRoad->CreateGrid( 5, 1 );
	m_GridRoad->EnableEditing( false );
	m_GridRoad->EnableGridLines( false );
	m_GridRoad->EnableDragGridSize( false );
	m_GridRoad->SetMargins( 0, 0 );
	
	// Columns
	m_GridRoad->AutoSizeColumns();
	m_GridRoad->EnableDragColMove( false );
	m_GridRoad->EnableDragColSize( true );
	m_GridRoad->SetColLabelSize( 0 );
	m_GridRoad->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_GridRoad->AutoSizeRows();
	m_GridRoad->EnableDragRowSize( true );
	m_GridRoad->SetRowLabelSize( 0 );
	m_GridRoad->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_GridRoad->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	bSizer7->Add( m_GridRoad, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_PageRoad->SetSizer( bSizer7 );
	m_PageRoad->Layout();
	bSizer7->Fit( m_PageRoad );
	m_TrackBook->AddPage( m_PageRoad, wxT("Road"), false );
	#ifndef __WXGTK__ // Small icon style not supported in GTK
	wxListView* m_TrackBookListView = m_TrackBook->GetListView();
	long m_TrackBookFlags = m_TrackBookListView->GetWindowStyleFlag();
	m_TrackBookFlags = ( m_TrackBookFlags & ~wxLC_ICON ) | wxLC_SMALL_ICON;
	//m_TrackBookListView->SetWindowStyleFlag( m_TrackBookFlags );
	#endif
	
	bSizer1->Add( m_TrackBook, 1, wxEXPAND | wxALL, 5 );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_Help = new wxButton( this, wxID_ANY, wxT("?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_Help->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer1->Add( m_Help, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Tip = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	fgSizer1->Add( m_Tip, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	bSizer1->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( TrackPickerDlgGen::onClose ) );
	m_TrackBook->Connect( wxEVT_COMMAND_LISTBOOK_PAGE_CHANGED, wxListbookEventHandler( TrackPickerDlgGen::onPageChanged ), NULL, this );
	m_GridTrack->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( TrackPickerDlgGen::onTrackCellLeftClick ), NULL, this );
	m_GridSwitch->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( TrackPickerDlgGen::onTrackCellLeftClick ), NULL, this );
	m_GridSignal->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( TrackPickerDlgGen::onTrackCellLeftClick ), NULL, this );
	m_GridBlock->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( TrackPickerDlgGen::onTrackCellLeftClick ), NULL, this );
	m_GridSensor->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( TrackPickerDlgGen::onTrackCellLeftClick ), NULL, this );
	m_GridAccessory->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( TrackPickerDlgGen::onTrackCellLeftClick ), NULL, this );
	m_GridRoad->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( TrackPickerDlgGen::onTrackCellLeftClick ), NULL, this );
	m_Help->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrackPickerDlgGen::onHelp ), NULL, this );
}

TrackPickerDlgGen::~TrackPickerDlgGen()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( TrackPickerDlgGen::onClose ) );
	m_TrackBook->Disconnect( wxEVT_COMMAND_LISTBOOK_PAGE_CHANGED, wxListbookEventHandler( TrackPickerDlgGen::onPageChanged ), NULL, this );
	m_GridTrack->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( TrackPickerDlgGen::onTrackCellLeftClick ), NULL, this );
	m_GridSwitch->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( TrackPickerDlgGen::onTrackCellLeftClick ), NULL, this );
	m_GridSignal->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( TrackPickerDlgGen::onTrackCellLeftClick ), NULL, this );
	m_GridBlock->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( TrackPickerDlgGen::onTrackCellLeftClick ), NULL, this );
	m_GridSensor->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( TrackPickerDlgGen::onTrackCellLeftClick ), NULL, this );
	m_GridAccessory->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( TrackPickerDlgGen::onTrackCellLeftClick ), NULL, this );
	m_GridRoad->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( TrackPickerDlgGen::onTrackCellLeftClick ), NULL, this );
	m_Help->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TrackPickerDlgGen::onHelp ), NULL, this );
	
}
