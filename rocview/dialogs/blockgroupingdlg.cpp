/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 


 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "blockgroupingdlg.h"
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
#include "wx/imaglist.h"
////@end includes

#include "blockgroupingdlg.h"

////@begin XPM images
////@end XPM images

#include "rocrail/wrapper/public/Plan.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/BlockList.h"
#include "rocrail/wrapper/public/Link.h"
#include "rocrail/wrapper/public/LinkList.h"
#include "rocrail/wrapper/public/LinkCond.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/SysCmd.h"

#include "rocview/public/guiapp.h"

#include "rocs/public/strtok.h"

/*!
 * BlockGroupingDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( BlockGroupingDialog, wxDialog )

/*!
 * BlockGroupingDialog event table definition
 */

BEGIN_EVENT_TABLE( BlockGroupingDialog, wxDialog )

////@begin BlockGroupingDialog event table entries
    EVT_NOTEBOOK_PAGE_CHANGED( ID_NOTEBOOK_LINK, BlockGroupingDialog::OnNotebookLinkPageChanged )
    EVT_LISTBOX( ID_LISTBOX_LINK, BlockGroupingDialog::OnListboxLinkSelected )
    EVT_BUTTON( ID_BUTTON_LINK_NEW, BlockGroupingDialog::OnButtonLinkNewClick )
    EVT_BUTTON( ID_BUTTON_LINK_DELETE, BlockGroupingDialog::OnButtonLinkDeleteClick )
    EVT_BUTTON( ID_BUTTON_LINK_ACTIVATE, BlockGroupingDialog::OnButtonLinkActivateClick )
    EVT_BUTTON( ID_BUTTON_LINK_DEACTIVATE, BlockGroupingDialog::OnButtonLinkDeactivateClick )
    EVT_COMBOBOX( ID_COMBOBOX_LINK_MAIN, BlockGroupingDialog::OnComboboxLinkMainSelected )
    EVT_LISTBOX( ID_LISTBOX_LINK_LIST, BlockGroupingDialog::OnListboxLinkListSelected )
    EVT_BUTTON( ID_BUTTON_LINK_ADD, BlockGroupingDialog::OnButtonLinkAddClick )
    EVT_BUTTON( ID_BUTTON_LINK_REMOVE, BlockGroupingDialog::OnButtonLinkRemoveClick )
    EVT_CHECKBOX( ID_CHECKBOX, BlockGroupingDialog::OnCheckboxClick )
    EVT_LIST_ITEM_SELECTED( ID_LINK_COND_LIST2, BlockGroupingDialog::OnLinkCondList2Selected )
    EVT_BUTTON( ID_BUTTON_LINK_ADD_COND, BlockGroupingDialog::OnButtonLinkAddCondClick )
    EVT_BUTTON( ID_BUTTON_LINK_MOD_COND, BlockGroupingDialog::OnButtonLinkModCondClick )
    EVT_BUTTON( ID_BUTTON_LINK_DEL_COND, BlockGroupingDialog::OnButtonLinkDelCondClick )
    EVT_BUTTON( wxID_CANCEL, BlockGroupingDialog::OnCancelClick )
    EVT_BUTTON( wxID_OK, BlockGroupingDialog::OnOkClick )
    EVT_BUTTON( wxID_APPLY, BlockGroupingDialog::OnApplyClick )
    EVT_BUTTON( wxID_HELP, BlockGroupingDialog::OnHelpClick )
////@end BlockGroupingDialog event table entries
    EVT_MENU( ID_PANEL_LINK_GENERAL, BlockGroupingDialog::OnSelectPage )

END_EVENT_TABLE()

/*!
 * BlockGroupingDialog constructors
 */

BlockGroupingDialog::BlockGroupingDialog()
{
}

BlockGroupingDialog::BlockGroupingDialog( wxWindow* parent, iONode props, bool save )
{
  m_TabAlign = wxGetApp().getTabAlign();
  m_CondSel = wxNOT_FOUND;
  Create(parent, -1, wxGetApp().getMsg("blockgrouptable") );
  m_Props = props;
  m_bSave = save;
  initLabels();

  initIndex();
  if( m_Props != NULL ) {
    initValues();
    //m_Notebook->SetSelection( 1 );
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ID_PANEL_LINK_GENERAL );
    wxPostEvent( this, event );
  }

  m_IndexPanel->GetSizer()->Layout();
  m_GeneralPanel->GetSizer()->Layout();
  m_PropertiesPanel->GetSizer()->Layout();
  m_ConditionsPanel->GetSizer()->Layout();
  m_Notebook->Fit();
  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);
}

BlockGroupingDialog::BlockGroupingDialog( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, caption, pos, size, style);
}


void BlockGroupingDialog::initLabels() {
  SetTitle(wxGetApp().getMsg( "blockgrouptable" ));

  m_Notebook->SetPageText( 0, wxGetApp().getMsg( "index" ) );
  m_Notebook->SetPageText( 1, wxGetApp().getMsg( "general" ) );
  m_Notebook->SetPageText( 2, wxGetApp().getMsg( "properties" ) );
  m_Notebook->SetPageText( 3, wxGetApp().getMsg( "conditions" ) );

  // Index
  m_New->SetLabel( wxGetApp().getMsg( "new" ) );
  m_Delete->SetLabel( wxGetApp().getMsg( "delete" ) );
  m_Activate->SetLabel( wxGetApp().getMsg( "activate" ) );
  m_DeActivate->SetLabel( wxGetApp().getMsg( "deactivate" ) );

  // General
  m_LabelID->SetLabel( wxGetApp().getMsg( "id" ) );
  m_LabelDesc->SetLabel( wxGetApp().getMsg( "description" ) );
  m_Critical->SetLabel( wxGetApp().getMsg( "criticalsection" ) );
  m_AllowFollowUp->SetLabel( wxGetApp().getMsg( "allowfollowup" ) );

  // Properties
  m_LabelMainBlock->SetLabel( wxGetApp().getMsg( "sourceblock" ) );
  m_LabelLinked->SetLabel( wxGetApp().getMsg( "linkedblocks" ) );
  m_Add->SetLabel( wxGetApp().getMsg( "add" ) );
  m_Remove->SetLabel( wxGetApp().getMsg( "delete" ) );

  iONode model = wxGetApp().getModel();
  if( model != NULL ) {
    iONode bklist = wPlan.getbklist( model );
    if( bklist != NULL ) {
      int cnt = NodeOp.getChildCnt( bklist );
      for( int i = 0; i < cnt; i++ ) {
        iONode bk = NodeOp.getChild( bklist, i );
        const char* id = wBlock.getid( bk );
        if( id != NULL ) {
          m_MainBlock->Append( wxString(id,wxConvUTF8) );
          m_AddBlockList->Append( wxString(id,wxConvUTF8) );
        }
      }
    }
  }

  // Conditions
  m_labCondFrom->SetLabel( wxGetApp().getMsg( "fromblock" ) );
  m_labCondFree->SetLabel( wxGetApp().getMsg( "free" ) );
  m_CondAdd->SetLabel( wxGetApp().getMsg( "add" ) );
  m_CondModify->SetLabel( wxGetApp().getMsg( "modify" ) );
  m_CondDelete->SetLabel( wxGetApp().getMsg( "delete" ) );

  m_CondList2->InsertColumn(0, wxGetApp().getMsg( "fromblock" ), wxLIST_FORMAT_LEFT );
  m_CondList2->InsertColumn(1, wxGetApp().getMsg( "free" ), wxLIST_FORMAT_LEFT );

  // Buttons
  m_OK->SetLabel( wxGetApp().getMsg( "ok" ) );
  m_Cancel->SetLabel( wxGetApp().getMsg( "cancel" ) );
  m_Apply->SetLabel( wxGetApp().getMsg( "apply" ) );
}


void BlockGroupingDialog::initIndex() {
  TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999, "InitIndex" );
  m_List->Clear();

  iONode model = wxGetApp().getModel();
  if( model != NULL ) {
    iONode linklist = wPlan.getlinklist( model );
    if( linklist != NULL ) {
      int cnt = NodeOp.getChildCnt( linklist );
      for( int i = 0; i < cnt; i++ ) {
        iONode link = NodeOp.getChild( linklist, i );
        const char* id = wLink.getid( link );
        if( id != NULL ) {
          m_List->Append( wxString(id,wxConvUTF8) );
        }
      }
      if( m_Props != NULL ) {
        m_List->SetStringSelection( wxString(wLink.getid( m_Props ),wxConvUTF8) );
        m_List->SetFirstItem( wxString(wLink.getid( m_Props ),wxConvUTF8) );
        initValues();
      }

    }

  }
}

void BlockGroupingDialog::OnSelectPage(wxCommandEvent& event) {
  m_Notebook->SetSelection( 1 );
}

void BlockGroupingDialog::initValues() {
  char* title = StrOp.fmt( "%s %s", (const char*)wxGetApp().getMsg("blockgrouptable").mb_str(wxConvUTF8), wLink.getid( m_Props ) );
  SetTitle( wxString(title,wxConvUTF8) );
  StrOp.free( title );

  // General
  m_ID->SetValue( wxString(wLink.getid( m_Props ),wxConvUTF8) );
  m_Desc->SetValue( wxString(wLink.getdesc( m_Props ),wxConvUTF8) );
  m_Critical->SetValue( (wLink.getusage( m_Props ) == wLink.usage_critsect));
  m_AllowFollowUp->SetValue( wLink.isallowfollowup( m_Props ) ? true:false );
  m_MaxFollowUp->SetValue( wLink.getmaxfollowup( m_Props ) );

  // Properties
  m_MainBlock->SetStringSelection( wxString(wLink.getsrc( m_Props ),wxConvUTF8) );

  m_MainBlock->Enable(!m_Critical->IsChecked());
  m_Activate->Enable(!m_Critical->IsChecked());
  m_DeActivate->Enable(!m_Critical->IsChecked());

  m_BlockList->Clear();
  m_CondFrom->Clear();
  iOStrTok tok = StrTokOp.inst( wLink.getdst( m_Props ), ',' );
  while( StrTokOp.hasMoreTokens( tok ) )  {
    const char* id = StrTokOp.nextToken( tok );
    if( StrOp.len( id ) > 0 ) {
      m_BlockList->Append( wxString(id,wxConvUTF8) );
      m_CondFrom->Append( wxString(id,wxConvUTF8) );
    }
  }

  m_CondList2->DeleteAllItems();
  m_CondSel = wxNOT_FOUND;

  int idx = 0;
  iONode cond = wLink.getlinkcond(m_Props);
  while( cond != NULL ) {
    m_CondList2->InsertItem( idx, wxString(wLinkCond.getfirst(cond),wxConvUTF8) );
    m_CondList2->SetItem( idx, 1, wxString(wLinkCond.getfree(cond), wxConvUTF8) );
    m_CondList2->SetItemPtrData(idx, (wxUIntPtr)cond);
    idx++;
    cond = wLink.nextlinkcond(m_Props, cond);
  }

  // resize
  for( int n = 0; n < 2; n++ ) {
    m_CondList2->SetColumnWidth(n, wxLIST_AUTOSIZE_USEHEADER);
    int autoheadersize = m_CondList2->GetColumnWidth(n);
    m_CondList2->SetColumnWidth(n, wxLIST_AUTOSIZE);
    int autosize = m_CondList2->GetColumnWidth(n);
    if(autoheadersize > autosize )
      m_CondList2->SetColumnWidth(n, wxLIST_AUTOSIZE_USEHEADER);
  }

}

bool BlockGroupingDialog::evaluate() {
  if( m_Props == NULL )
    return false;

  if( m_ID->GetValue().Len() == 0 ) {
    wxMessageDialog( this, wxGetApp().getMsg("invalidid"), _T("Rocrail"), wxOK | wxICON_ERROR ).ShowModal();
    m_ID->SetValue( wxString(wLink.getid( m_Props ),wxConvUTF8) );
    return false;
  }
  // General
  wLink.setid( m_Props, m_ID->GetValue().mb_str(wxConvUTF8) );
  wLink.setdesc ( m_Props, m_Desc->GetValue().mb_str(wxConvUTF8) );

  // Properties
  wLink.setsrc( m_Props, m_MainBlock->GetValue().mb_str(wxConvUTF8) );

  wLink.setusage( m_Props, (m_Critical->IsChecked() ? wLink.usage_critsect : wLink.usage_manual ) );
  wLink.setallowfollowup( m_Props, m_AllowFollowUp->IsChecked() ? True:False );
  wLink.setmaxfollowup( m_Props, m_MaxFollowUp->GetValue() );


  int cnt = m_BlockList->GetCount();
  char* dst = NULL;
  for( int i = 0; i < cnt; i++ ) {
    if( i > 0 )
      dst = StrOp.cat( dst, "," );
    dst = StrOp.cat( dst, m_BlockList->GetString(i).mb_str(wxConvUTF8) );
  }
  if( dst != NULL ) {
    wLink.setdst( m_Props, dst );
    StrOp.free( dst );
  }

  return true;
}

/*!
 * BlockGroupingDialog creator
 */

bool BlockGroupingDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin BlockGroupingDialog member initialisation
    m_Notebook = NULL;
    m_IndexPanel = NULL;
    m_List = NULL;
    m_New = NULL;
    m_Delete = NULL;
    m_Activate = NULL;
    m_DeActivate = NULL;
    m_GeneralPanel = NULL;
    m_LabelID = NULL;
    m_ID = NULL;
    m_LabelDesc = NULL;
    m_Desc = NULL;
    m_PropertiesPanel = NULL;
    m_LabelMainBlock = NULL;
    m_MainBlock = NULL;
    m_LabelLinked = NULL;
    m_BlockList = NULL;
    m_AddBlockList = NULL;
    m_Add = NULL;
    m_Remove = NULL;
    m_Critical = NULL;
    m_AllowFollowUp = NULL;
    m_MaxFollowUp = NULL;
    m_ConditionsPanel = NULL;
    m_CondList2 = NULL;
    m_labCondFrom = NULL;
    m_CondFrom = NULL;
    m_labCondFree = NULL;
    m_CondFree = NULL;
    m_CondAdd = NULL;
    m_CondModify = NULL;
    m_CondDelete = NULL;
    m_Cancel = NULL;
    m_OK = NULL;
    m_Apply = NULL;
////@end BlockGroupingDialog member initialisation

////@begin BlockGroupingDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end BlockGroupingDialog creation
    return true;
}

/*!
 * Control creation for BlockGroupingDialog
 */

void BlockGroupingDialog::CreateControls()
{
////@begin BlockGroupingDialog content construction
    BlockGroupingDialog* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    m_Notebook = new wxNotebook( itemDialog1, ID_NOTEBOOK_LINK, wxDefaultPosition, wxDefaultSize, m_TabAlign );

    m_IndexPanel = new wxPanel( m_Notebook, ID_PANEL_LINK_INDEX, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxVERTICAL);
    m_IndexPanel->SetSizer(itemBoxSizer5);

    wxArrayString m_ListStrings;
    m_List = new wxListBox( m_IndexPanel, ID_LISTBOX_LINK, wxDefaultPosition, wxDefaultSize, m_ListStrings, wxLB_SINGLE|wxLB_ALWAYS_SB );
    itemBoxSizer5->Add(m_List, 1, wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer7 = new wxFlexGridSizer(2, 2, 0, 0);
    itemBoxSizer5->Add(itemFlexGridSizer7, 0, wxGROW|wxALL, 5);
    m_New = new wxButton( m_IndexPanel, ID_BUTTON_LINK_NEW, _("New"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_New, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_Delete = new wxButton( m_IndexPanel, ID_BUTTON_LINK_DELETE, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_Delete, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_Activate = new wxButton( m_IndexPanel, ID_BUTTON_LINK_ACTIVATE, _("Activate"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_Activate, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_DeActivate = new wxButton( m_IndexPanel, ID_BUTTON_LINK_DEACTIVATE, _("DeActivate"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_DeActivate, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Notebook->AddPage(m_IndexPanel, _("Index"));

    m_GeneralPanel = new wxPanel( m_Notebook, ID_PANEL_LINK_GENERAL, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer13 = new wxBoxSizer(wxVERTICAL);
    m_GeneralPanel->SetSizer(itemBoxSizer13);

    wxFlexGridSizer* itemFlexGridSizer14 = new wxFlexGridSizer(1, 2, 0, 0);
    itemBoxSizer13->Add(itemFlexGridSizer14, 0, wxGROW|wxALL, 5);
    m_LabelID = new wxStaticText( m_GeneralPanel, wxID_STATIC_LINK_ID, _("ID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer14->Add(m_LabelID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ID = new wxTextCtrl( m_GeneralPanel, ID_TEXTCTRL_LINK_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer14->Add(m_ID, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer14->AddGrowableCol(1);

    m_LabelDesc = new wxStaticText( m_GeneralPanel, wxID_STATIC_LINK_DESC, _("description"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer13->Add(m_LabelDesc, 0, wxALIGN_LEFT|wxALL, 5);

    m_Desc = new wxTextCtrl( m_GeneralPanel, ID_TEXTCTRL_LINK_DESC, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer13->Add(m_Desc, 0, wxGROW|wxALL, 5);

    m_Notebook->AddPage(m_GeneralPanel, _("General"));

    m_PropertiesPanel = new wxPanel( m_Notebook, ID_PANEL_LINK_PROPS, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer20 = new wxBoxSizer(wxVERTICAL);
    m_PropertiesPanel->SetSizer(itemBoxSizer20);

    wxFlexGridSizer* itemFlexGridSizer21 = new wxFlexGridSizer(2, 2, 0, 0);
    itemBoxSizer20->Add(itemFlexGridSizer21, 0, wxGROW|wxALL, 5);
    m_LabelMainBlock = new wxStaticText( m_PropertiesPanel, wxID_STATIC_LINK_MAIN, _("source block"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer21->Add(m_LabelMainBlock, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_MainBlockStrings;
    m_MainBlock = new wxComboBox( m_PropertiesPanel, ID_COMBOBOX_LINK_MAIN, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_MainBlockStrings, wxCB_READONLY );
    itemFlexGridSizer21->Add(m_MainBlock, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer21->AddGrowableCol(1);

    wxBoxSizer* itemBoxSizer24 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer20->Add(itemBoxSizer24, 1, wxGROW|wxALL, 5);
    m_LabelLinked = new wxStaticText( m_PropertiesPanel, wxID_STATIC_LINK_LINKED, _("linked blocks"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer24->Add(m_LabelLinked, 0, wxALIGN_LEFT|wxALL, 5);

    wxArrayString m_BlockListStrings;
    m_BlockList = new wxListBox( m_PropertiesPanel, ID_LISTBOX_LINK_LIST, wxDefaultPosition, wxSize(-1, 140), m_BlockListStrings, wxLB_SINGLE );
    itemBoxSizer24->Add(m_BlockList, 1, wxGROW|wxALL, 5);

    wxArrayString m_AddBlockListStrings;
    m_AddBlockList = new wxComboBox( m_PropertiesPanel, ID_COMBOBOX_LINK_ADD_BLOCK, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_AddBlockListStrings, wxCB_DROPDOWN );
    itemBoxSizer24->Add(m_AddBlockList, 0, wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer28 = new wxFlexGridSizer(2, 2, 0, 0);
    itemBoxSizer20->Add(itemFlexGridSizer28, 0, wxGROW|wxALL, 5);
    m_Add = new wxButton( m_PropertiesPanel, ID_BUTTON_LINK_ADD, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer28->Add(m_Add, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Remove = new wxButton( m_PropertiesPanel, ID_BUTTON_LINK_REMOVE, _("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer28->Add(m_Remove, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer31 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer20->Add(itemBoxSizer31, 0, wxGROW, 5);
    m_Critical = new wxCheckBox( m_PropertiesPanel, ID_CHECKBOX, _("Critical Section"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Critical->SetValue(false);
    itemBoxSizer31->Add(m_Critical, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer33 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer20->Add(itemBoxSizer33, 0, wxGROW, 5);
    m_AllowFollowUp = new wxCheckBox( m_PropertiesPanel, wxID_ANY, _("Allow follow up"), wxDefaultPosition, wxDefaultSize, 0 );
    m_AllowFollowUp->SetValue(false);
    itemBoxSizer33->Add(m_AllowFollowUp, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_MaxFollowUp = new wxSpinCtrl( m_PropertiesPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 99, 0 );
    itemBoxSizer33->Add(m_MaxFollowUp, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_Notebook->AddPage(m_PropertiesPanel, _("Properties"));

    m_ConditionsPanel = new wxPanel( m_Notebook, ID_PANEL_LINK_CONDS, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer37 = new wxBoxSizer(wxVERTICAL);
    m_ConditionsPanel->SetSizer(itemBoxSizer37);

    m_CondList2 = new wxListCtrl( m_ConditionsPanel, ID_LINK_COND_LIST2, wxDefaultPosition, wxSize(100, 100), wxLC_REPORT );
    itemBoxSizer37->Add(m_CondList2, 1, wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer39 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer37->Add(itemFlexGridSizer39, 0, wxGROW|wxALL, 5);
    m_labCondFrom = new wxStaticText( m_ConditionsPanel, wxID_ANY, _("From"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer39->Add(m_labCondFrom, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_CondFromStrings;
    m_CondFrom = new wxComboBox( m_ConditionsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_CondFromStrings, wxCB_DROPDOWN );
    itemFlexGridSizer39->Add(m_CondFrom, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labCondFree = new wxStaticText( m_ConditionsPanel, wxID_ANY, _("Free"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer39->Add(m_labCondFree, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CondFree = new wxTextCtrl( m_ConditionsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer39->Add(m_CondFree, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer39->AddGrowableCol(1);

    wxBoxSizer* itemBoxSizer44 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer37->Add(itemBoxSizer44, 0, wxGROW|wxALL, 5);
    m_CondAdd = new wxButton( m_ConditionsPanel, ID_BUTTON_LINK_ADD_COND, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer44->Add(m_CondAdd, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CondModify = new wxButton( m_ConditionsPanel, ID_BUTTON_LINK_MOD_COND, _("Modify"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer44->Add(m_CondModify, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CondDelete = new wxButton( m_ConditionsPanel, ID_BUTTON_LINK_DEL_COND, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer44->Add(m_CondDelete, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Notebook->AddPage(m_ConditionsPanel, _("Conditions"));

    itemBoxSizer2->Add(m_Notebook, 1, wxGROW|wxALL, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer48 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer48, 0, wxGROW|wxALL, 5);
    m_Cancel = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer48->AddButton(m_Cancel);

    m_OK = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    m_OK->SetDefault();
    itemStdDialogButtonSizer48->AddButton(m_OK);

    m_Apply = new wxButton( itemDialog1, wxID_APPLY, _("&Apply"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer48->AddButton(m_Apply);

    wxButton* itemButton52 = new wxButton( itemDialog1, wxID_HELP, _("&Help"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer48->AddButton(itemButton52);

    itemStdDialogButtonSizer48->Realize();

////@end BlockGroupingDialog content construction
}

/*!
 * Should we show tooltips?
 */

bool BlockGroupingDialog::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap BlockGroupingDialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin BlockGroupingDialog bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end BlockGroupingDialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon BlockGroupingDialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin BlockGroupingDialog icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end BlockGroupingDialog icon retrieval
}
/*!
 * wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED event handler for ID_NOTEBOOK_CO
 */

void BlockGroupingDialog::OnNotebookLinkPageChanged( wxNotebookEvent& event )
{
////@begin wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED event handler for ID_NOTEBOOK_CO in BlockGroupingDialog.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED event handler for ID_NOTEBOOK_CO in BlockGroupingDialog.
}

/*!
 * wxEVT_COMMAND_LISTBOX_SELECTED event handler for ID_LISTBOX_CO
 */

void BlockGroupingDialog::OnListboxLinkSelected( wxCommandEvent& event )
{
  iONode model = wxGetApp().getModel();
  if( model != NULL ) {
    iONode linklist = wPlan.getlinklist( model );
    if( linklist != NULL ) {
      int cnt = NodeOp.getChildCnt( linklist );
      for( int i = 0; i < cnt; i++ ) {
        iONode link = NodeOp.getChild( linklist, i );
        const char* id = wLink.getid( link );
        if( id != NULL && StrOp.equals( id, m_List->GetStringSelection().mb_str(wxConvUTF8) ) ) {
          m_Props = link;
          initValues();
          break;
        }
      }
    }
  }
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_CO_NEW
 */

void BlockGroupingDialog::OnButtonLinkNewClick( wxCommandEvent& event )
{
  int i = m_List->FindString( _T("NEW") );
  if( i == wxNOT_FOUND ) {
    m_List->Append( _T("NEW") );
    iONode model = wxGetApp().getModel();
    if( model != NULL ) {
      iONode linklist = wPlan.getlinklist( model );
      if( linklist == NULL ) {
        linklist = NodeOp.inst( wLinkList.name(), model, ELEMENT_NODE );
        NodeOp.addChild( model, linklist );
      }
      if( linklist != NULL ) {
        iONode link = NodeOp.inst( wLink.name(), linklist, ELEMENT_NODE );
        NodeOp.addChild( linklist, link );
        wLink.setid( link, "NEW" );
        m_Props = link;
        initValues();
      }
    }
  }
  m_List->SetStringSelection( _T("NEW") );
  m_List->SetFirstItem( _T("NEW") );
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_CO_DELETE
 */

void BlockGroupingDialog::OnButtonLinkDeleteClick( wxCommandEvent& event )
{
  if( m_Props != NULL ) {
    int action = wxMessageDialog( this, wxGetApp().getMsg("removewarning"), _T("Rocrail"), wxYES_NO | wxICON_EXCLAMATION ).ShowModal();
    if( action == wxID_NO )
      return;

    wxGetApp().pushUndoItem( (iONode)NodeOp.base.clone( m_Props ) );

    /* Notify RocRail. */
    iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
    wModelCmd.setcmd( cmd, wModelCmd.remove );
    NodeOp.addChild( cmd, (iONode)m_Props->base.clone( m_Props ) );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);

    iONode model = wxGetApp().getModel();
    if( model != NULL ) {
      iONode linklist = wPlan.getlinklist( model );
      if( linklist != NULL ) {
        NodeOp.removeChild( linklist, m_Props );
        m_Props = NULL;
      }
    }

    initIndex();
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void BlockGroupingDialog::OnCancelClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL in BlockGroupingDialog.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL in BlockGroupingDialog.
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void BlockGroupingDialog::OnOkClick( wxCommandEvent& event )
{
  if( m_bSave )
    OnApplyClick(event);
  EndModal( wxID_OK );
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_APPLY
 */

void BlockGroupingDialog::OnApplyClick( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  if( !evaluate() )
    return;

  if( !wxGetApp().isStayOffline() ) {
    /* Notify RocRail. */
    iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
    wModelCmd.setcmd( cmd, wModelCmd.modify );
    NodeOp.addChild( cmd, (iONode)m_Props->base.clone( m_Props ) );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
  else {
    wxGetApp().setLocalModelModified(true);
  }
  initIndex();
}


/*!
 * wxEVT_COMMAND_LISTBOX_SELECTED event handler for ID_LISTBOX_LINK_LIST
 */

void BlockGroupingDialog::OnListboxLinkListSelected( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_LISTBOX_SELECTED event handler for ID_LISTBOX_LINK_LIST in BlockGroupingDialog.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_LISTBOX_SELECTED event handler for ID_LISTBOX_LINK_LIST in BlockGroupingDialog.
}


/*!
 * wxEVT_COMMAND_COMBOBOX_SELECTED event handler for ID_COMBOBOX_LINK_MAIN
 */

void BlockGroupingDialog::OnComboboxLinkMainSelected( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_COMBOBOX_SELECTED event handler for ID_COMBOBOX_LINK_MAIN in BlockGroupingDialog.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_COMBOBOX_SELECTED event handler for ID_COMBOBOX_LINK_MAIN in BlockGroupingDialog.
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_LINK_ADD
 */

void BlockGroupingDialog::OnButtonLinkAddClick( wxCommandEvent& event )
{
  if( !m_AddBlockList->GetStringSelection().IsEmpty() )
    m_BlockList->Append( m_AddBlockList->GetStringSelection() );
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_LINK_REMOVE
 */

void BlockGroupingDialog::OnButtonLinkRemoveClick( wxCommandEvent& event )
{
  int i = m_BlockList->GetSelection();
  if( i != wxNOT_FOUND )
    m_BlockList->Delete(i);
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_LINK_DEACTIVATE
 */

void BlockGroupingDialog::OnButtonLinkDeactivateClick( wxCommandEvent& event )
{
  if( m_Props != NULL ) {
    /* Notify RocRail. */
    iONode cmd = NodeOp.inst( wSysCmd.name(), NULL, ELEMENT_NODE );
    iONode clone = (iONode)m_Props->base.clone( m_Props );
    wSysCmd.setcmd( cmd, wSysCmd.grouplink );
    wLink.setactive( clone, False );
    NodeOp.addChild( cmd, clone );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_LINK_ACTIVATE
 */

void BlockGroupingDialog::OnButtonLinkActivateClick( wxCommandEvent& event )
{
  if( m_Props != NULL ) {
    /* Notify RocRail. */
    iONode cmd = NodeOp.inst( wSysCmd.name(), NULL, ELEMENT_NODE );
    iONode clone = (iONode)m_Props->base.clone( m_Props );
    wSysCmd.setcmd( cmd, wSysCmd.grouplink );
    wLink.setactive( clone, True );
    NodeOp.addChild( cmd, clone );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
}


/*!
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKBOX_BLOCKGROUP_CRITICAL
 */

void BlockGroupingDialog::OnCheckboxClick( wxCommandEvent& event )
{
  m_MainBlock->Enable(!m_Critical->IsChecked());
  m_Activate->Enable(!m_Critical->IsChecked());
  m_DeActivate->Enable(!m_Critical->IsChecked());
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_LINK_DEL_COND
 */

void BlockGroupingDialog::OnButtonLinkDelCondClick( wxCommandEvent& event )
{

  if( m_CondSel != wxNOT_FOUND ) {
    iONode node = (iONode)m_CondList2->GetItemData(m_CondSel);
    NodeOp.removeChild( m_Props, node );
    NodeOp.base.del(node);
    initValues();
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_LINK_MOD_COND
 */

void BlockGroupingDialog::OnButtonLinkModCondClick( wxCommandEvent& event )
{
  if( m_CondSel != wxNOT_FOUND ) {
    iONode cond = (iONode)m_CondList2->GetItemData(m_CondSel);
    wLinkCond.setfirst(cond, m_CondFrom->GetStringSelection().mb_str(wxConvUTF8));
    wLinkCond.setfree(cond, m_CondFree->GetValue().mb_str(wxConvUTF8));
    initValues();
  }
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_LINK_ADD_COND
 */
void BlockGroupingDialog::OnButtonLinkAddCondClick( wxCommandEvent& event )
{
  iONode cond = NodeOp.inst(wLinkCond.name(), m_Props, ELEMENT_NODE);
  NodeOp.addChild( m_Props, cond );
  wLinkCond.setfirst(cond, m_CondFrom->GetStringSelection().mb_str(wxConvUTF8));
  wLinkCond.setfree(cond, m_CondFree->GetValue().mb_str(wxConvUTF8));
  initValues();
}


void BlockGroupingDialog::OnHelpClick( wxCommandEvent& event )
{
  switch( m_Notebook->GetSelection() ) {
  case 0: wxGetApp().openLink( "blockgroups-index" ); break; // index
  case 1: wxGetApp().openLink( "blockgroups-gen" ); break;
  case 2: wxGetApp().openLink( "blockgroups-props" ); break;
  case 3: wxGetApp().openLink( "blockgroups-cond" ); break; // position
  default: wxGetApp().openLink( "blockgroups" ); break;
  }
}


/*!
 * wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ID_LINK_COND_LIST2
 */

void BlockGroupingDialog::OnLinkCondList2Selected( wxListEvent& event )
{
  m_CondSel = event.GetIndex();

  if( m_CondSel != wxNOT_FOUND ) {
    iONode cond = (iONode)m_CondList2->GetItemData(m_CondSel);
    m_CondFrom->SetStringSelection( wxString(wLinkCond.getfirst( cond ),wxConvUTF8) );
    m_CondFree->SetValue( wxString(wLinkCond.getfree( cond ),wxConvUTF8) );
  }
}

