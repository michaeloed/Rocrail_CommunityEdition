/*
 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 

 */
#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "selectdialog.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "selectdialog.h"

#include "rocview/public/guiapp.h"
#include "rocrail/wrapper/public/Plan.h"
#include "rocrail/wrapper/public/ZLevel.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Output.h"

////@begin XPM images
////@end XPM images


/*!
 * SelectDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( SelectDialog, wxDialog )


/*!
 * SelectDialog event table definition
 */

BEGIN_EVENT_TABLE( SelectDialog, wxDialog )

////@begin SelectDialog event table entries
    EVT_RADIOBOX( ID_SELECT_ACTION, SelectDialog::OnSelectActionSelected )
    EVT_BUTTON( wxID_CANCEL, SelectDialog::OnCancelClick )
    EVT_BUTTON( wxID_OK, SelectDialog::OnOkClick )
    EVT_BUTTON( wxID_HELP, SelectDialog::OnHelpClick )
////@end SelectDialog event table entries

END_EVENT_TABLE()


/*!
 * SelectDialog constructors
 */

SelectDialog::SelectDialog()
{
    Init();
}

SelectDialog::SelectDialog( wxWindow* parent, iONode sel )
{
    Init();
    Create(parent, -1, wxGetApp().getMsg("select"));
    initLabels();
    initValues(sel);

    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
}


/*!
 * SelectDialog creator
 */

bool SelectDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin SelectDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end SelectDialog creation
    return true;
}


/*!
 * SelectDialog destructor
 */

SelectDialog::~SelectDialog()
{
////@begin SelectDialog destruction
////@end SelectDialog destruction
}


/* comparator for sorting by id: */
static int __sortStr(obj* _a, obj* _b)
{
    const char* a = (const char*)*_a;
    const char* b = (const char*)*_b;
    return strcmp( a, b );
}


void SelectDialog::initLabels() {
  m_RangeBox->SetLabel( wxGetApp().getMsg( "range" ) );
  m_TargetBox->SetLabel( wxGetApp().getMsg( "target" ) );
  m_ActionBox->SetLabel( wxGetApp().getMsg( "action" ) );
  m_ActionBox->SetString( 0, wxGetApp().getMsg( "move" ) );
  m_ActionBox->SetString( 1, wxGetApp().getMsg( "copy" ) );
  m_ActionBox->SetString( 2, wxGetApp().getMsg( "delete" ) );
  m_ActionBox->SetString( 3, wxGetApp().getMsg( "routeids" ) );
  m_ActionBox->SetString( 4, wxGetApp().getMsg( "blockid" ) );
  
  m_labRangCX->SetLabel( wxGetApp().getMsg( "width" ) );
  m_labRangeCY->SetLabel( wxGetApp().getMsg( "height" ) );

  m_labLevel->SetLabel( wxGetApp().getMsg( "level" ) );

  m_labRouteIDs->SetLabel( wxGetApp().getMsg( "routeids" ) );
  m_MergeRouteIDs->SetLabel( wxGetApp().getMsg( "merge" ) );
  m_labBlockID->SetLabel( wxGetApp().getMsg( "blockid" ) );

  // Buttons
  m_OK->SetLabel( wxGetApp().getMsg( "ok" ) );
  m_Cancel->SetLabel( wxGetApp().getMsg( "cancel" ) );
  
  
  iONode zlevel = wPlan.getzlevel( wxGetApp().getModel() );

  while( zlevel != NULL ) {
    m_Level->Append( wxString(wZLevel.gettitle(zlevel),wxConvUTF8), (void*)zlevel);
    zlevel = wPlan.nextzlevel( wxGetApp().getModel(), zlevel );
  };
  
  m_BlockID->Append( _T("") );
  iONode model = wxGetApp().getModel();
  iOList list = ListOp.inst();

  if( model != NULL ) {
    iONode bklist = wPlan.getbklist( model );
    if( bklist != NULL ) {
      int cnt = NodeOp.getChildCnt( bklist );
      for( int i = 0; i < cnt; i++ ) {
        iONode bk = NodeOp.getChild( bklist, i );
        ListOp.add(list, (obj)wBlock.getid( bk ));
      }
    }
    iONode fblist = wPlan.getfblist( model );
    if( fblist != NULL ) {
      int cnt = NodeOp.getChildCnt( fblist );
      for( int i = 0; i < cnt; i++ ) {
        iONode fb = NodeOp.getChild( fblist, i );
        ListOp.add(list, (obj)wFeedback.getid( fb ));
      }
    }
    iONode colist = wPlan.getcolist( model );
    if( colist != NULL ) {
      int cnt = NodeOp.getChildCnt( colist );
      for( int i = 0; i < cnt; i++ ) {
        iONode co = NodeOp.getChild( colist, i );
        ListOp.add(list, (obj)wOutput.getid( co ));
      }
    }

    ListOp.sort(list, &__sortStr);
    int cnt = ListOp.size( list );
    for( int i = 0; i < cnt; i++ ) {
      const char* id = (const char*)ListOp.get( list, i );
      m_BlockID->Append( wxString(id,wxConvUTF8) );
    }
  }
  
}


void SelectDialog::initValues(iONode sel) {
  if( sel != NULL ) {
    m_RangeX->SetValue( wxString(NodeOp.getStr( sel, "x", 0 ),wxConvUTF8) );
    m_RangeY->SetValue( wxString(NodeOp.getStr( sel, "y", 0 ),wxConvUTF8) );
    m_RangeCX->SetValue( NodeOp.getInt( sel, "cx", 0 ) );
    m_RangeCY->SetValue( NodeOp.getInt( sel, "cy", 0 ) );
    m_TargetX->SetValue( NodeOp.getInt( sel, "x", 0 ) );
    m_TargetY->SetValue( NodeOp.getInt( sel, "y", 0 ) );
    m_destZ = NodeOp.getInt( sel, "z", 0 );
    if( NodeOp.getStr( sel, "title", NULL ) != NULL )
      m_Level->SetStringSelection( wxString(NodeOp.getStr( sel, "title", "" ),wxConvUTF8) );
    else {
      iONode zlevel = wPlan.getzlevel( wxGetApp().getModel() );

      while( zlevel != NULL ) {
        if(wZLevel.getz(zlevel) == m_destZ ) {
          m_Level->SetStringSelection( wxString(wZLevel.gettitle(zlevel),wxConvUTF8) );
          break;
        }
        zlevel = wPlan.nextzlevel( wxGetApp().getModel(), zlevel );
      };
    }
  }
}


void SelectDialog::evaluate() {
  long val;
  m_RangeX->GetValue().ToLong(&val);
  m_X = (int)val;
  m_RangeY->GetValue().ToLong(&val);
  m_Y = (int)val;
  m_CX = m_RangeCX->GetValue();
  m_CY = m_RangeCY->GetValue();
  m_destX = m_TargetX->GetValue();
  m_destY = m_TargetY->GetValue();
  m_action = m_ActionBox->GetSelection();
  if( wxNOT_FOUND != m_Level->GetSelection() ) {
    iONode zlevel = (iONode)m_Level->GetClientData(m_Level->GetSelection());
    m_destZ = wZLevel.getz(zlevel);
    m_destTitle = wZLevel.gettitle(zlevel);
    TraceOp.trc( "seldlg", TRCLEVEL_INFO, __LINE__, 9999, "zlevel[%d] %s selected", m_destZ, m_destTitle );
  }
  else {
    TraceOp.trc( "seldlg", TRCLEVEL_INFO, __LINE__, 9999, "no zlevel selected" );
    m_destTitle = "";
  }
}


iONode SelectDialog::getSelection() {
  iONode sel = NodeOp.inst( "selection", NULL, ELEMENT_NODE );
  NodeOp.setInt( sel, "x", m_X );
  NodeOp.setInt( sel, "y", m_Y );
  NodeOp.setInt( sel, "cx", m_CX );
  NodeOp.setInt( sel, "cy", m_CY );
  NodeOp.setInt( sel, "destx", m_destX );
  NodeOp.setInt( sel, "desty", m_destY );
  NodeOp.setInt( sel, "destz", m_destZ );
  NodeOp.setStr( sel, "desttitle", m_destTitle );
  NodeOp.setInt( sel, "action", m_action );
  NodeOp.setStr( sel, "routeids", m_RouteIDs->GetValue().mb_str(wxConvUTF8) );
  NodeOp.setBool( sel, "mergerouteids", m_MergeRouteIDs->IsChecked()?True:False );
  NodeOp.setStr( sel, "blockid", m_BlockID->GetStringSelection().mb_str(wxConvUTF8) );
  return sel;
}


/*!
 * Member initialisation
 */

void SelectDialog::Init()
{
////@begin SelectDialog member initialisation
    m_RangeBox = NULL;
    m_labRangeX = NULL;
    m_RangeX = NULL;
    m_labRangeY = NULL;
    m_RangeY = NULL;
    m_labRangCX = NULL;
    m_RangeCX = NULL;
    m_labRangeCY = NULL;
    m_RangeCY = NULL;
    m_TargetBox = NULL;
    m_labTargetX = NULL;
    m_TargetX = NULL;
    m_labTargetY = NULL;
    m_TargetY = NULL;
    m_labLevel = NULL;
    m_Level = NULL;
    m_ActionBox = NULL;
    m_labRouteIDs = NULL;
    m_RouteIDs = NULL;
    m_MergeRouteIDs = NULL;
    m_labBlockID = NULL;
    m_BlockID = NULL;
    m_Cancel = NULL;
    m_OK = NULL;
////@end SelectDialog member initialisation
}


/*!
 * Control creation for SelectDialog
 */

void SelectDialog::CreateControls()
{    
////@begin SelectDialog content construction
    SelectDialog* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    m_RangeBox = new wxStaticBox(itemDialog1, wxID_ANY, _("Range"));
    wxStaticBoxSizer* itemStaticBoxSizer3 = new wxStaticBoxSizer(m_RangeBox, wxVERTICAL);
    itemBoxSizer2->Add(itemStaticBoxSizer3, 0, wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer4 = new wxFlexGridSizer(2, 4, 0, 0);
    itemStaticBoxSizer3->Add(itemFlexGridSizer4, 1, wxGROW, 5);

    m_labRangeX = new wxStaticText( itemDialog1, wxID_ANY, _("x"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(m_labRangeX, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_RangeX = new wxTextCtrl( itemDialog1, wxID_ANY, _("0"), wxDefaultPosition, wxSize(50, -1), wxTE_CENTRE );
    itemFlexGridSizer4->Add(m_RangeX, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labRangeY = new wxStaticText( itemDialog1, wxID_ANY, _("y"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(m_labRangeY, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_RangeY = new wxTextCtrl( itemDialog1, wxID_ANY, _("0"), wxDefaultPosition, wxSize(50, -1), wxTE_CENTRE );
    itemFlexGridSizer4->Add(m_RangeY, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labRangCX = new wxStaticText( itemDialog1, wxID_ANY, _("width"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(m_labRangCX, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_RangeCX = new wxSpinCtrl( itemDialog1, wxID_ANY, _T("1"), wxDefaultPosition, wxSize(70, -1), wxSP_ARROW_KEYS, 1, 99, 1 );
    itemFlexGridSizer4->Add(m_RangeCX, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labRangeCY = new wxStaticText( itemDialog1, wxID_ANY, _("height"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer4->Add(m_labRangeCY, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_RangeCY = new wxSpinCtrl( itemDialog1, wxID_ANY, _T("1"), wxDefaultPosition, wxSize(70, -1), wxSP_ARROW_KEYS, 1, 99, 1 );
    itemFlexGridSizer4->Add(m_RangeCY, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_TargetBox = new wxStaticBox(itemDialog1, wxID_ANY, _("Target"));
    wxStaticBoxSizer* itemStaticBoxSizer13 = new wxStaticBoxSizer(m_TargetBox, wxVERTICAL);
    itemBoxSizer2->Add(itemStaticBoxSizer13, 0, wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer14 = new wxFlexGridSizer(1, 4, 0, 0);
    itemStaticBoxSizer13->Add(itemFlexGridSizer14, 0, wxGROW, 5);

    m_labTargetX = new wxStaticText( itemDialog1, wxID_ANY, _("x"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer14->Add(m_labTargetX, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_TargetX = new wxSpinCtrl( itemDialog1, wxID_ANY, _T("0"), wxDefaultPosition, wxSize(70, -1), wxSP_ARROW_KEYS, 0, 1000, 0 );
    itemFlexGridSizer14->Add(m_TargetX, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labTargetY = new wxStaticText( itemDialog1, wxID_ANY, _("y"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer14->Add(m_labTargetY, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_TargetY = new wxSpinCtrl( itemDialog1, wxID_ANY, _T("0"), wxDefaultPosition, wxSize(70, -1), wxSP_ARROW_KEYS, 0, 1000, 0 );
    itemFlexGridSizer14->Add(m_TargetY, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxFlexGridSizer* itemFlexGridSizer19 = new wxFlexGridSizer(1, 2, 0, 0);
    itemStaticBoxSizer13->Add(itemFlexGridSizer19, 0, wxGROW, 5);

    m_labLevel = new wxStaticText( itemDialog1, wxID_ANY, _("level"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer19->Add(m_labLevel, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxArrayString m_LevelStrings;
    m_Level = new wxChoice( itemDialog1, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_LevelStrings, 0 );
    itemFlexGridSizer19->Add(m_Level, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    itemFlexGridSizer19->AddGrowableCol(1);

    wxArrayString m_ActionBoxStrings;
    m_ActionBoxStrings.Add(_("&Move"));
    m_ActionBoxStrings.Add(_("&Copy"));
    m_ActionBoxStrings.Add(_("&Delete"));
    m_ActionBoxStrings.Add(_("&RouteID"));
    m_ActionBoxStrings.Add(_("&BlockID"));
    m_ActionBox = new wxRadioBox( itemDialog1, ID_SELECT_ACTION, _("Action"), wxDefaultPosition, wxDefaultSize, m_ActionBoxStrings, 1, wxRA_SPECIFY_ROWS );
    m_ActionBox->SetSelection(0);
    itemBoxSizer2->Add(m_ActionBox, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxFlexGridSizer* itemFlexGridSizer23 = new wxFlexGridSizer(0, 3, 0, 0);
    itemBoxSizer2->Add(itemFlexGridSizer23, 0, wxGROW|wxALL, 5);

    m_labRouteIDs = new wxStaticText( itemDialog1, wxID_ANY, _("Route IDs"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer23->Add(m_labRouteIDs, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_RouteIDs = new wxTextCtrl( itemDialog1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer23->Add(m_RouteIDs, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_MergeRouteIDs = new wxCheckBox( itemDialog1, wxID_ANY, _("Merge"), wxDefaultPosition, wxDefaultSize, 0 );
    m_MergeRouteIDs->SetValue(false);
    itemFlexGridSizer23->Add(m_MergeRouteIDs, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labBlockID = new wxStaticText( itemDialog1, wxID_ANY, _("BlockID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer23->Add(m_labBlockID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxArrayString m_BlockIDStrings;
    m_BlockID = new wxComboBox( itemDialog1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_BlockIDStrings, wxCB_DROPDOWN );
    itemFlexGridSizer23->Add(m_BlockID, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemFlexGridSizer23->AddGrowableCol(1);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer29 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer29, 0, wxGROW|wxALL, 5);
    m_Cancel = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer29->AddButton(m_Cancel);

    m_OK = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer29->AddButton(m_OK);

    wxButton* itemButton32 = new wxButton( itemDialog1, wxID_HELP, _("&Help"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer29->AddButton(itemButton32);

    itemStdDialogButtonSizer29->Realize();

////@end SelectDialog content construction
}


/*!
 * Should we show tooltips?
 */

bool SelectDialog::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap SelectDialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin SelectDialog bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end SelectDialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon SelectDialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin SelectDialog icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end SelectDialog icon retrieval
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void SelectDialog::OnCancelClick( wxCommandEvent& event )
{
  EndModal( 0 );
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void SelectDialog::OnOkClick( wxCommandEvent& event )
{
  evaluate();
  EndModal( wxID_OK );
  
}


/*!
 * wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_SELECT_ACTION
 */

void SelectDialog::OnSelectActionSelected( wxCommandEvent& event )
{
  if( m_ActionBox->GetSelection() == 2 ) {
    m_TargetX->Enable(false);
    m_TargetY->Enable(false);
    m_Level->Enable(false);
  }
  else {
    m_TargetX->Enable(true);
    m_TargetY->Enable(true);
    m_Level->Enable(true);
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
 */

void SelectDialog::OnHelpClick( wxCommandEvent& event )
{
  wxGetApp().openLink( "select" );
}

