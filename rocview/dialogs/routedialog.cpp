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
#if defined(__GNUG__) && !defined(__APPLE__)
#pragma implementation "routedialog.h"
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

#include "routedialog.h"
#include "actionsctrldlg.h"

////@begin XPM images
////@end XPM images

#include "rocview/public/guiapp.h"
#include "rocrail/wrapper/public/Route.h"
#include "rocrail/wrapper/public/RouteList.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/SwitchCmd.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/Item.h"
#include "rocrail/wrapper/public/Plan.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/Turntable.h"
#include "rocrail/wrapper/public/SelTab.h"
#include "rocrail/wrapper/public/FeedbackEvent.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/PermInclude.h"
#include "rocrail/wrapper/public/PermExclude.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/RouteCondition.h"
#include "rocrail/wrapper/public/Stage.h"
#include "rocrail/wrapper/public/Operator.h"
#include "rocrail/wrapper/public/SpeedCondition.h"
#include "rocrail/wrapper/public/Variable.h"

#include "rocs/public/strtok.h"

/*!
 * RouteDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( RouteDialog, wxDialog )

/*!
 * RouteDialog event table definition
 */

BEGIN_EVENT_TABLE( RouteDialog, wxDialog )

////@begin RouteDialog event table entries
    EVT_LIST_ITEM_SELECTED( ID_LISTCTRLINDEX_ST, RouteDialog::OnListctrlindexStSelected )
    EVT_LIST_COL_CLICK( ID_LISTCTRLINDEX_ST, RouteDialog::OnListctrlindexStColLeftClick )

    EVT_BUTTON( ID_BUTTON_ST_NEW, RouteDialog::OnButtonStNewClick )

    EVT_BUTTON( ID_BUTTON_ST_DELETE_ROUTE, RouteDialog::OnButtonStDeleteRouteClick )

    EVT_BUTTON( ID_BUTTON_ST_TEST, RouteDialog::OnButtonStTestClick )

    EVT_BUTTON( ID_ROUTE_LOCK, RouteDialog::OnRouteLockClick )

    EVT_BUTTON( ID_RESET_ROUTE, RouteDialog::OnResetRouteClick )

    EVT_BUTTON( ID_BUTTON_ST_DOC, RouteDialog::OnButtonStDocClick )

    EVT_BUTTON( ID_BUTTON_ST_COPY, RouteDialog::OnButtonStCopyClick )

    EVT_BUTTON( ID_ROUTE_ACTIONS, RouteDialog::OnRouteActionsClick )

    EVT_RADIOBOX( ID_ROUTE_VELOCITY, RouteDialog::OnRouteVelocitySelected )

    EVT_LISTBOX( ID_SPEED_CONDITION_DESC, RouteDialog::OnSpeedConditionDescSelected )

    EVT_BUTTON( ID_SPEEDCOND_ADD, RouteDialog::OnSpeedcondAddClick )

    EVT_BUTTON( ID_SPEEDCOND_DEL, RouteDialog::OnSpeedcondDelClick )

    EVT_BUTTON( ID_SPEEDCOND_MODIFY, RouteDialog::OnSpeedcondModifyClick )

    EVT_BUTTON( ID_SPEEDCOND_IMPORT, RouteDialog::OnSpeedcondImportClick )

    EVT_LIST_ITEM_SELECTED( ID_LISTCTRL_COMMANDS, RouteDialog::OnListctrlCommandsSelected )

    EVT_BUTTON( ID_BUTTON_ST_DELETE, RouteDialog::OnButtonTurnoutDeleteClick )

    EVT_BUTTON( ID_BUTTON_ST_MODIFY, RouteDialog::OnButtonTurnoutModifyClick )

    EVT_BUTTON( ID_ROUTE_CMD_UP, RouteDialog::OnRouteCmdUpClick )

    EVT_BUTTON( ID_ROUTE_CMD_DOWN, RouteDialog::OnRouteCmdDownClick )

    EVT_COMBOBOX( ID_COMBOBOX_ST_SWITCH_ID, RouteDialog::OnComboboxStSwitchIdSelected )

    EVT_BUTTON( ID_BUTTON_ST_ADD, RouteDialog::OnButtonTurnoutAddClick )

    EVT_LISTBOX( ID_LIST_ROUTE_SENSORS, RouteDialog::OnListRouteSensorsSelected )

    EVT_BUTTON( ID_BUTTON_ROUTES_ADD_SENSOR, RouteDialog::OnButtonRoutesAddSensorClick )

    EVT_BUTTON( ID_BUTTON_ROUTES_DEL_SENSOR, RouteDialog::OnButtonRoutesDelSensorClick )

    EVT_BUTTON( ID_ADD_INCLUDE, RouteDialog::OnAddIncludeClick )

    EVT_BUTTON( ID_ADD_EXCLUDE, RouteDialog::OnAddExcludeClick )

    EVT_BUTTON( ID_REMOVE_INCLUDE, RouteDialog::OnRemoveIncludeClick )

    EVT_BUTTON( ID_REMOVE_EXCLUDE, RouteDialog::OnRemoveExcludeClick )

    EVT_GRID_CELL_LEFT_CLICK( RouteDialog::OnCondCellLeftClick )

    EVT_BUTTON( ID_ROUTE_CONDITION_ADD, RouteDialog::OnRouteConditionAddClick )

    EVT_BUTTON( ID_ROUTE_CONDITION_MODIFY, RouteDialog::OnRouteConditionModifyClick )

    EVT_BUTTON( ID_ROUTE_CONDITION_DEL, RouteDialog::OnRouteConditionDelClick )

    EVT_BUTTON( wxID_CANCEL, RouteDialog::OnCancelClick )

    EVT_BUTTON( wxID_OK, RouteDialog::OnOkClick )

    EVT_BUTTON( wxID_APPLY, RouteDialog::OnApplyClick )

    EVT_BUTTON( wxID_HELP, RouteDialog::OnHelpClick )

////@end RouteDialog event table entries
    EVT_MENU( ID_PANEL_ST_GENERAL, RouteDialog::OnSelectPage )

END_EVENT_TABLE()

/*!
 * RouteDialog constructors
 */


/* comparator for sorting by id: */
static int __sortStr(obj* _a, obj* _b)
{
    const char* a = (const char*)*_a;
    const char* b = (const char*)*_b;
    return strcmp( a, b );
}

/* comparator for sorting by id: */
static int __sortID(obj* _a, obj* _b)
{
    iONode a = (iONode)*_a;
    iONode b = (iONode)*_b;
    const char* idA = wItem.getid( a );
    const char* idB = wItem.getid( b );
    return strcmp( idA, idB );
}

RouteDialog::RouteDialog()
{
}

RouteDialog::RouteDialog( wxWindow* parent, iONode p_Props, bool readonly, bool standalone )
{
  m_TabAlign = wxGetApp().getTabAlign();
  Create(parent, -1, wxGetApp().getMsg("routes") );
  m_Props = p_Props;
  m_bReadOnly = readonly;
  m_bStandalone = standalone;
  m_CondNr = -1;

  initLabels();

  m_IndexPanel->GetSizer()->Layout();
  m_GeneralPanel->GetSizer()->Layout();
  m_SpeedPanel->GetSizer()->Layout();
  m_CommandPanel->GetSizer()->Layout();
  m_SensorPanel->GetSizer()->Layout();
  m_PermissionsPanel->GetSizer()->Layout();
  m_LocationPanel->GetSizer()->Layout();
  m_WiringPanel->GetSizer()->Layout();

  m_GeneralPanel->Enable(!m_bReadOnly);
  m_SpeedPanel->Enable(!m_bReadOnly);
  m_CommandPanel->Enable(!m_bReadOnly);
  m_SensorPanel->Enable(!m_bReadOnly);
  m_WiringPanel->Enable(!m_bReadOnly);

  m_Notebook->Fit();
  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);

  if( m_Props != NULL && standalone ) {
    m_IndexPanel->Show(false);
    m_Apply->Enable(false);
    initValues();
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ID_PANEL_ST_GENERAL );
    wxPostEvent( this, event );
  }
  else if( initIndex() ) {
    initValues();
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ID_PANEL_ST_GENERAL );
    wxPostEvent( this, event );
  }

}

void RouteDialog::OnSelectPage(wxCommandEvent& event) {
  m_Notebook->SetSelection( 1 );
}


void RouteDialog::initLabels() {
  m_Notebook->SetPageText( 0, wxGetApp().getMsg( "index" ) );
  m_Notebook->SetPageText( 1, wxGetApp().getMsg( "general" ) );
  m_Notebook->SetPageText( 2, wxGetApp().getMsg( "speed" ) );
  m_Notebook->SetPageText( 3, wxGetApp().getMsg( "commands" ) );
  m_Notebook->SetPageText( 4, wxGetApp().getMsg( "sensors" ) );
  m_Notebook->SetPageText( 5, wxGetApp().getMsg( "permissions" ) );
  m_Notebook->SetPageText( 6, wxGetApp().getMsg( "conditions" ) );
  m_Notebook->SetPageText( 7, wxGetApp().getMsg( "position" ) );
  m_Notebook->SetPageText( 8, wxGetApp().getMsg( "wiring" ) );

  // Index
  initList(m_List2, this, true, false);
  m_New->SetLabel( wxGetApp().getMsg( "new" ) );
  m_DeleteRoute->SetLabel( wxGetApp().getMsg( "delete" ) );
  m_Test->SetLabel( wxGetApp().getMsg( "test" ) );
  m_TestLock->SetLabel( wxGetApp().getMsg( "lock" ) );
  m_Doc->SetLabel( wxGetApp().getMsg( "doc_report" ) );
  m_CopyRoute->SetLabel( wxGetApp().getMsg( "copy" ) );
  m_ResetRoute->SetLabel( wxGetApp().getMsg( "reset" ) );

  m_New->Enable(!m_bReadOnly);
  m_DeleteRoute->Enable(!m_bReadOnly);
  m_Test->Enable(!m_bReadOnly);
  m_CopyRoute->Enable(!m_bReadOnly);


  // General
  m_LabelId->SetLabel( wxGetApp().getMsg( "id" ) );
  m_labDescription->SetLabel( wxGetApp().getMsg( "description" ) );
  m_LabelBlockA->SetLabel( wxGetApp().getMsg( "fromblock" ) );
  m_LabelBlockB->SetLabel( wxGetApp().getMsg( "toblock" ) );
  m_labCrossingBlock->SetLabel( wxGetApp().getMsg( "crossingblocks" ) );
  m_BlockC->SetToolTip( wxGetApp().getTip( "crossingblocks" ) );
  m_labModID->SetLabel( wxGetApp().getMsg( "modid" ) );

  m_FromSignals->SetLabel( wxGetApp().getMsg( "fromsignals" ) );
  m_FromSignals->SetString( 0, wxT("+") );
  m_FromSignals->SetString( 1, wxT("-") );
  m_FromSignals->SetString( 2, wxGetApp().getMsg( "none" ) );
  m_ToSignals->SetLabel( wxGetApp().getMsg( "tosignals" ) );
  m_ToSignals->SetString( 0, wxT("+") );
  m_ToSignals->SetString( 1, wxT("-") );
  m_ToSignals->SetString( 2, wxGetApp().getMsg( "none" ) );

  m_CountCars->SetLabel( wxGetApp().getMsg( "countcars" ) );
  m_CountCars->SetString( 0, wxGetApp().getMsg( "none" ) );
  m_CountCars->SetString( 1, wxT("+") );
  m_CountCars->SetString( 2, wxT("-") );

  m_DetailsBox->SetLabel( wxGetApp().getMsg( "options" ) );
  m_SwapPost->SetLabel( wxGetApp().getMsg( "swapplacingpost" ) );
  m_Actions->SetLabel( wxGetApp().getMsg( "actions" )+_T("...") );
  m_Show->SetLabel( wxGetApp().getMsg( "show" ) );
  m_Manual->SetLabel( wxGetApp().getMsg( "manually" ) );

  m_Status->SetLabel( wxGetApp().getMsg( "status" ) );
  m_Status->SetString( 0, wxGetApp().getMsg( "free" ) );
  m_Status->SetString( 1, wxGetApp().getMsg( "locked" ) );
  m_Status->SetString( 2, wxGetApp().getMsg( "selected" ) );
  m_Status->SetString( 3, wxGetApp().getMsg( "deselected" ) );
  m_Status->SetString( 4, wxGetApp().getMsg( "closed" ) );

  // Speed
  m_Speed->SetLabel( wxGetApp().getMsg( "speed" ) );
  m_Speed->SetString( 0, wxGetApp().getMsg( "block" ) );
  m_Speed->SetString( 1, wxGetApp().getMsg( "min" ) );
  m_Speed->SetString( 2, wxGetApp().getMsg( "mid" ) );
  m_Speed->SetString( 3, wxGetApp().getMsg( "cruise" ) );
  m_Speed->SetString( 4, wxGetApp().getMsg( "max" ) );
  m_Speed->SetString( 5, _T("%") );
  m_labSpeedPercent->SetLabel( wxGetApp().getMsg( "percent" ) );
  m_labMaxKmH->SetLabel( wxGetApp().getMsg( "maxkmh" ) );

  m_SpeedOptionsBox->SetLabel( wxGetApp().getMsg( "options" ) );
  m_ReduceV->SetLabel( wxGetApp().getMsg( "reducespeed" ) );

  m_SpeedConditionsBox->SetLabel( wxGetApp().getMsg( "conditions" ) );
  m_labSpeedCondDesc->SetLabel( wxGetApp().getMsg( "description" ) );
  m_labSpeedCondType->SetLabel( wxGetApp().getMsg( "type" ) );
  m_labSpeedCondClass->SetLabel( wxGetApp().getMsg( "class" ) );
  m_labSpeedCondVariable->SetLabel( wxGetApp().getMsg( "variable" ) );
  m_labSpeedCondPercent->SetLabel( wxGetApp().getMsg( "percent" ) );
  m_SpeedCondAdd->SetLabel( wxGetApp().getMsg( "add" ) );
  m_SpeedCondDel->SetLabel( wxGetApp().getMsg( "delete" ) );
  m_SpeedCondModify->SetLabel( wxGetApp().getMsg( "modify" ) );
  m_SpeedCondImport->SetLabel( wxGetApp().getMsg( "import" ) );

  m_SpeedCondType->Append(wxT(""));
  m_SpeedCondType->Append( wxGetApp().getMsg( "others" ) );
  m_SpeedCondType->Append( wxGetApp().getMsg( "goods" ) );
  m_SpeedCondType->Append( wxGetApp().getMsg( "local" ) );
  m_SpeedCondType->Append( wxGetApp().getMsg( "mixed" ) );
  m_SpeedCondType->Append( wxGetApp().getMsg( "cleaning" ) );
  m_SpeedCondType->Append( wxGetApp().getMsg( "ice" ) );
  m_SpeedCondType->Append( wxGetApp().getMsg( "post" ) );
  m_SpeedCondType->Append( wxGetApp().getMsg( "light" ) );
  m_SpeedCondType->Append( wxGetApp().getMsg( "lightgoods" ) );
  m_SpeedCondType->Append( wxGetApp().getMsg( "regional" ) );
  m_SpeedCondType->Append( wxGetApp().getMsg( "shunting" ) );

  m_SpeedCondVariable->Append(wxT(""));
  iONode model = wxGetApp().getModel();
  iOList list = ListOp.inst();
  if( model != NULL ) {
    iONode vrlist = wPlan.getvrlist( model );
    if( vrlist != NULL ) {
      int cnt = NodeOp.getChildCnt( vrlist );
      for( int i = 0; i < cnt; i++ ) {
        iONode vr = NodeOp.getChild( vrlist, i );
        const char* id = wVariable.getid( vr );
        if( id != NULL ) {
          ListOp.add(list, (obj)id);
        }
      }
      ListOp.sort(list, &__sortStr);
      cnt = ListOp.size( list );
      for( int i = 0; i < cnt; i++ ) {
        const char* id = (const char*)ListOp.get( list, i );
        m_SpeedCondVariable->Append( wxString(id,wxConvUTF8) );
      }
    }
  }
  /* clean up the temp. list */
  ListOp.base.del(list);

  m_SpeedCondImportFrom->Append(wxT(""));
  model = wxGetApp().getModel();
  list = ListOp.inst();
  if( model != NULL ) {
    iONode stlist = wPlan.getstlist( model );
    if( stlist != NULL ) {
      int cnt = NodeOp.getChildCnt( stlist );
      for( int i = 0; i < cnt; i++ ) {
        iONode st = NodeOp.getChild( stlist, i );
        const char* id = wRoute.getid( st );
        if( id != NULL ) {
          ListOp.add(list, (obj)id);
        }
      }
      ListOp.sort(list, &__sortStr);
      cnt = ListOp.size( list );
      for( int i = 0; i < cnt; i++ ) {
        const char* id = (const char*)ListOp.get( list, i );
        m_SpeedCondImportFrom->Append( wxString(id,wxConvUTF8) );
      }
    }
  }
  /* clean up the temp. list */
  ListOp.base.del(list);

  // Commands
  m_Commands2->InsertColumn(0, wxGetApp().getMsg( "id" ), wxLIST_FORMAT_LEFT );
  m_Commands2->InsertColumn(1, wxGetApp().getMsg( "command" ), wxLIST_FORMAT_LEFT );
  m_Commands2->InsertColumn(2, wxGetApp().getMsg( "track" ), wxLIST_FORMAT_LEFT );
  m_Commands2->InsertColumn(3, wxGetApp().getMsg( "lock" ), wxLIST_FORMAT_LEFT );
  m_Commands2->InsertColumn(4, wxGetApp().getMsg( "reducespeed" ), wxLIST_FORMAT_LEFT );
  m_Commands2->InsertColumn(5, wxGetApp().getMsg( "atfree" ), wxLIST_FORMAT_LEFT );

  m_Add->SetLabel( wxGetApp().getMsg( "add" ) );
  m_Delete->SetLabel( wxGetApp().getMsg( "delete" ) );
  m_Modify->SetLabel( wxGetApp().getMsg( "modify" ) );
  m_CmdUp->SetLabel( wxGetApp().getMsg( "up" ) );
  m_CmdDown->SetLabel( wxGetApp().getMsg( "down" ) );
  m_LabelSwitchId->SetLabel( wxGetApp().getMsg( "id" ) );
  m_labTrackNumber->SetLabel( wxGetApp().getMsg( "tracknr" ) );
  m_SwitchCmd->SetLabel( wxGetApp().getMsg( "command" ) );
  m_SwitchCmd->SetString( 0, wxGetApp().getMsg( "straight" ) );
  m_SwitchCmd->SetString( 1, wxGetApp().getMsg( "thrown" ) );
  m_SwitchCmd->SetString( 2, wxGetApp().getMsg( "left" ) );
  m_SwitchCmd->SetString( 3, wxGetApp().getMsg( "right" ) );
  m_SwitchCmd->SetString( 4, wxGetApp().getMsg( "track" ) );
  m_SwitchCmd->SetString( 5, wxGetApp().getMsg( "red" ) );
  m_SwitchCmd->SetString( 6, wxGetApp().getMsg( "green" ) );
  m_SwitchCmd->SetString( 7, wxGetApp().getMsg( "yellow" ) );
  m_SwitchCmd->SetString( 8, wxGetApp().getMsg( "white" ) );
  m_SwitchCmd->SetString( 9, wxGetApp().getMsg( "on" ) );
  m_SwitchCmd->SetString( 10, wxGetApp().getMsg( "off" ) );
  m_SwitchCmd->SetString( 11, wxGetApp().getMsg( "aspect" ) );
  m_Lock->SetLabel( wxGetApp().getMsg( "lock" ) );
  m_SwReduceV->SetLabel( wxGetApp().getMsg( "reducespeed" ) );
  m_AtFree->SetLabel( wxGetApp().getMsg( "atfree" ) );

  // Sensors
  m_AddSensor->SetLabel( wxGetApp().getMsg( "add" ) );
  m_DelSensor->SetLabel( wxGetApp().getMsg( "delete" ) );

  model = wxGetApp().getModel();
  list = ListOp.inst();
  if( model != NULL ) {
    iONode fblist = wPlan.getfblist( model );
    if( fblist != NULL ) {
      int cnt = NodeOp.getChildCnt( fblist );
      for( int i = 0; i < cnt; i++ ) {
        iONode fb = NodeOp.getChild( fblist, i );
        const char* id = wFeedback.getid( fb );
        if( id != NULL ) {
          ListOp.add(list, (obj)id);
        }
      }
      ListOp.sort(list, &__sortStr);
      cnt = ListOp.size( list );
      for( int i = 0; i < cnt; i++ ) {
        const char* id = (const char*)ListOp.get( list, i );
        m_SensorCombo->Append( wxString(id,wxConvUTF8) );
      }
    }

    ListOp.clear(list);
    iONode colist = wPlan.getcolist( model );
    if( colist != NULL ) {
      int cnt = NodeOp.getChildCnt( colist );
      for( int i = 0; i < cnt; i++ ) {
        iONode co = NodeOp.getChild( colist, i );
        const char* id = wOutput.getid( co );
        if( id != NULL ) {
          ListOp.add(list, (obj)id);
        }
      }
      ListOp.sort(list, &__sortStr);
      cnt = ListOp.size( list );
      for( int i = 0; i < cnt; i++ ) {
        const char* id = (const char*)ListOp.get( list, i );
        m_SensorCombo->Append( wxString(id,wxConvUTF8) );
      }
    }
  }
  /* clean up the temp. list */
  ListOp.base.del(list);

  // Permissions
  m_labInclude->SetLabel( wxGetApp().getMsg( "include" ) );
  m_labExclude->SetLabel( wxGetApp().getMsg( "exclude" ) );
  m_labLocoListPerm->SetLabel( wxGetApp().getMsg( "loctable" ) );
  m_AddInclude->SetLabel( wxGetApp().getMsg( "include" ) );
  m_AddExclude->SetLabel( wxGetApp().getMsg( "exclude" ) );
  m_RemoveInclude->SetLabel( wxGetApp().getMsg( "delete" ) );
  m_RemoveExclude->SetLabel( wxGetApp().getMsg( "delete" ) );

  m_PermType->SetLabel( wxGetApp().getMsg( "type" ) );
  m_PermTypeNone->SetLabel( wxGetApp().getMsg( "others" ) );
  m_PermTypeGoods->SetLabel( wxGetApp().getMsg( "goods" ) );
  m_PermTypeLocal->SetLabel( wxGetApp().getMsg( "local" ) );
  m_PermTypeMixed->SetLabel( wxGetApp().getMsg( "mixed" ) );
  m_PermTypeCleaning->SetLabel( wxGetApp().getMsg( "cleaning" ) );
  m_PermTypeICE->SetLabel( wxGetApp().getMsg( "ice" ) );
  m_PermTypePost->SetLabel( wxGetApp().getMsg( "post" ) );
  m_PermTypeLight->SetLabel( wxGetApp().getMsg( "light" ) );
  m_PermTypeLightGoods->SetLabel( wxGetApp().getMsg( "lightgoods" ) );
  m_PermTypeLocal->SetLabel( wxGetApp().getMsg( "regional" ) );
  m_PermTypeShunting->SetLabel( wxGetApp().getMsg( "shunting" ) );

  m_labClass->SetLabel( wxGetApp().getMsg( "class" ) );

  // Initialize sorted Loco Permission List
  initLocPermissionList();

  m_labMaxLen->SetLabel( wxGetApp().getMsg( "maxtrainlen" ) );
  m_labMinLen->SetLabel( wxGetApp().getMsg( "mintrainlen" ) );
  m_Commuter->SetLabel( wxGetApp().getMsg( "commuter" ) );
  m_Commuter->SetString( 0, wxGetApp().getMsg( "yes" ) );
  m_Commuter->SetString( 1, wxGetApp().getMsg( "only" ) );
  m_Commuter->SetString( 2, wxGetApp().getMsg( "no" ) );

  m_Placing->SetLabel( wxGetApp().getMsg( "placing" ) );
  m_Placing->SetString( 0, wxGetApp().getMsg( "both" ) );
  m_Placing->SetString( 1, wxGetApp().getMsg( "default" ) );
  m_Placing->SetString( 2, wxGetApp().getMsg( "swapped" ) );

  // Conditions

  wxFont* font = new wxFont( m_CondGrid->GetDefaultCellFont() );
  font->SetPointSize( (int)(font->GetPointSize() - 1 ) );
  m_CondGrid->SetDefaultCellFont( *font );
  m_CondGrid->SetColLabelValue(0, wxGetApp().getMsg("not") );
  m_CondGrid->SetColLabelValue(1, wxGetApp().getMsg("fromblock") );
  m_CondGrid->SetColLabelValue(2, wxGetApp().getMsg("type") );
  m_CondGrid->SetColLabelValue(3, wxGetApp().getMsg("commuter") );
  m_CondGrid->SetColLabelValue(4, wxGetApp().getMsg("changedirection") );
  m_CondGrid->SetColLabelValue(5, wxGetApp().getMsg("allowschedules") );
  m_CondGrid->AutoSizeColumns();
  m_CondGrid->AutoSizeRows();



  m_CondNotFromBlock->SetLabel( wxGetApp().getMsg( "notfromblock" ) );
  m_CondCommuter->SetLabel( wxGetApp().getMsg( "commuter" ) );
  m_CondChangeDir->SetLabel( wxGetApp().getMsg( "changedirection" ) );
  m_CondAdd->SetLabel( wxGetApp().getMsg( "add" ) );
  m_CondModify->SetLabel( wxGetApp().getMsg( "modify" ) );
  m_CondDelete->SetLabel( wxGetApp().getMsg( "delete" ) );
  m_CondAllowSchedules->SetLabel( wxGetApp().getMsg( "allowschedules" ) );


  m_CondType->Clear();
  m_CondType->Append( _T(""), (void*)NULL );
  m_CondType->Append( wxGetApp().getMsg( wLoc.cargo_none ) );
  m_CondType->Append( wxGetApp().getMsg( wLoc.cargo_goods ) );
  m_CondType->Append( wxGetApp().getMsg( wLoc.cargo_regional ) );
  m_CondType->Append( wxGetApp().getMsg( wLoc.cargo_mixed ) );
  m_CondType->Append( wxGetApp().getMsg( wLoc.cargo_cleaning ) );
  m_CondType->Append( wxGetApp().getMsg( wLoc.cargo_ice ) );
  m_CondType->Append( wxGetApp().getMsg( wLoc.cargo_post ) );
  m_CondType->Append( wxGetApp().getMsg( wLoc.cargo_person ) );
  m_CondType->Append( wxGetApp().getMsg( wLoc.cargo_light ) );
  m_CondType->Append( wxGetApp().getMsg( wLoc.cargo_lightgoods ) );


  // Location
  m_LabelX->SetLabel( wxGetApp().getMsg( "x" ) );
  m_LabelY->SetLabel( wxGetApp().getMsg( "y" ) );
  m_LabelZ->SetLabel( wxGetApp().getMsg( "z" ) );
  m_ori->SetLabel( wxGetApp().getMsg( "orientation" ) );
  m_ori->SetString( 0, wxGetApp().getMsg( "north" ) );
  m_ori->SetString( 1, wxGetApp().getMsg( "east" ) );
  m_ori->SetString( 2, wxGetApp().getMsg( "south" ) );
  m_ori->SetString( 3, wxGetApp().getMsg( "west" ) );

  // Wiring
  m_CTCBox->SetLabel( wxGetApp().getMsg( "ctc" ) );
  m_labCTCbutton->SetLabel( wxGetApp().getMsg( "button" ) );
  m_labCTCIID->SetLabel( wxGetApp().getMsg( "iid" ) );
  m_labCTCBus->SetLabel( wxGetApp().getMsg( "bus" ) );
  m_labCTCAddr->SetLabel( wxGetApp().getMsg( "address" ) );
  m_labOutput->SetLabel( wxGetApp().getMsg( "output" ) );


  m_Output1->Append( _T("") );
  m_Output2->Append( _T("") );
  m_Output3->Append( _T("") );
  list = ListOp.inst();
  if( model != NULL ) {
    iONode colist = wPlan.getcolist( model );
    if( colist != NULL ) {
      int cnt = NodeOp.getChildCnt( colist );
      for( int i = 0; i < cnt; i++ ) {
        iONode co = NodeOp.getChild( colist, i );
        const char* id = wOutput.getid( co );
        if( id != NULL ) {
          ListOp.add(list, (obj)id);
        }
      }
      ListOp.sort(list, &__sortStr);
      cnt = ListOp.size( list );
      for( int i = 0; i < cnt; i++ ) {
        const char* id = (const char*)ListOp.get( list, i );
        m_Output1->Append( wxString(id,wxConvUTF8) );
        m_Output2->Append( wxString(id,wxConvUTF8) );
        m_Output3->Append( wxString(id,wxConvUTF8) );
      }
    }
  }
  /* clean up the temp. list */
  ListOp.base.del(list);



  // Buttons
  m_OK->SetLabel( wxGetApp().getMsg( "ok" ) );
  m_Cancel->SetLabel( wxGetApp().getMsg( "cancel" ) );
  m_Apply->SetLabel( wxGetApp().getMsg( "apply" ) );
  m_Help->SetLabel( wxGetApp().getMsg( "help" ) );

  m_OK->Enable(!m_bReadOnly);
  m_Apply->Enable(!m_bReadOnly);

}


void RouteDialog::initLocPermissionList() {
  iONode model = wxGetApp().getModel();
  iOList list = ListOp.inst();
  int cnt = 0;

  if( model != NULL ) {
    iONode lclist = wPlan.getlclist( model );
    iONode oplist = wPlan.getoperatorlist( model );
    if( lclist != NULL ) {
      cnt = NodeOp.getChildCnt( lclist );
      for( int i = 0; i < cnt; i++ ) {
        iONode lc = NodeOp.getChild( lclist, i );
        const char* id = wLoc.getid( lc );
        if( id != NULL ) {
          ListOp.add(list, (obj)id);
        }
      }
    }
    if( oplist != NULL ) {
      cnt = NodeOp.getChildCnt( oplist );
      for( int i = 0; i < cnt; i++ ) {
        iONode op = NodeOp.getChild( oplist, i );
        const char* id = wOperator.getid( op );
        if( id != NULL ) {
          ListOp.add(list, (obj)id);
        }
      }
    }


    ListOp.sort(list, &__sortStr);
    cnt = ListOp.size( list );
    for( int i = 0; i < cnt; i++ ) {
      const char* id = (const char*)ListOp.get( list, i );
      m_LocoListPerm->Append( wxString(id,wxConvUTF8) );
    }
  }
  /* clean up the temp. list */
  ListOp.base.del(list);
}



bool RouteDialog::initIndex() {
  TraceOp.trc( "routedlg", TRCLEVEL_INFO, __LINE__, 9999, "InitIndex" );
  iONode model = wxGetApp().getModel();
  if( model != NULL ) {
    iONode stlist = wPlan.getstlist( model );
    if( stlist != NULL ) {
      fillIndex(stlist);

      if( m_Props != NULL ) {
        setIDSelection(wItem.getid( m_Props ));
        char* title = StrOp.fmt( "%s %s", (const char*)wxGetApp().getMsg("route").mb_str(wxConvUTF8), wRoute.getid( m_Props ) );
        SetTitle( wxString(title,wxConvUTF8) );
        StrOp.free( title );
        return true;
      }
      else {
        m_Props = setSelection(0);
      }

    }
  }
  return false;
}


void RouteDialog::initBlockCombos() {
  m_BlockA->Clear();
  m_BlockB->Clear();
  m_CondFromBlock->Clear();
  m_BlockA->Append( _T("<undef>"), (void*)NULL );
  m_BlockB->Append( _T("<undef>"), (void*)NULL );
  m_CondFromBlock->Append( _T(""), (void*)NULL );

  iONode model = wxGetApp().getModel();
  iOList list = ListOp.inst();

  if( model != NULL ) {
    iONode bklist = wPlan.getbklist( model );
    iONode seltablist = wPlan.getseltablist( model );
    iONode ttlist = wPlan.getttlist( model );
    iONode sblist = wPlan.getsblist( model );

    if( bklist != NULL ) {
      int cnt = NodeOp.getChildCnt( bklist );
      for( int i = 0; i < cnt; i++ ) {
        iONode bk = NodeOp.getChild( bklist, i );
        const char* id = wBlock.getid( bk );
        if( id != NULL ) {
          ListOp.add(list, (obj)id);
        }
      }

      if(sblist != NULL) {
        cnt = NodeOp.getChildCnt( sblist );
        for( int i = 0; i < cnt; i++ ) {
          iONode stage = NodeOp.getChild( sblist, i );
          const char* id = wStage.getid( stage );
          if( id != NULL ) {
            ListOp.add(list, (obj)id);
          }
        }
      }

      if(seltablist != NULL) {
        cnt = NodeOp.getChildCnt( seltablist );
        for( int i = 0; i < cnt; i++ ) {
          iONode seltab = NodeOp.getChild( seltablist, i );
          const char* id = wSelTab.getid( seltab );
          if( id != NULL ) {
            ListOp.add(list, (obj)id);
          }
        }
      }

      if(ttlist != NULL) {
        cnt = NodeOp.getChildCnt( ttlist );
        for( int i = 0; i < cnt; i++ ) {
          iONode tt = NodeOp.getChild( ttlist, i );
          const char* id = wTurntable.getid( tt );
          if( id != NULL && wTurntable.isembeddedblock(tt) ) {
            ListOp.add(list, (obj)id);
          }
        }
      }

      ListOp.sort(list, &__sortStr);
      cnt = ListOp.size( list );
      for( int i = 0; i < cnt; i++ ) {
        const char* id = (const char*)ListOp.get( list, i );
        m_BlockA->Append( wxString(id,wxConvUTF8) );
        m_BlockB->Append( wxString(id,wxConvUTF8) );
        m_CondFromBlock->Append( wxString(id,wxConvUTF8) );
      }
    }

    TraceOp.trc( "routedlg", TRCLEVEL_INFO, __LINE__, 9999, "appending points for A" );
		m_BlockA->Append( wxString( wRoute.point_en,wxConvUTF8) );
		m_BlockA->Append( wxString( wRoute.point_es,wxConvUTF8) );
		m_BlockA->Append( wxString( wRoute.point_ne,wxConvUTF8) );
		m_BlockA->Append( wxString( wRoute.point_nw,wxConvUTF8) );
		m_BlockA->Append( wxString( wRoute.point_se,wxConvUTF8) );
		m_BlockA->Append( wxString( wRoute.point_sw,wxConvUTF8) );
		m_BlockA->Append( wxString( wRoute.point_wn,wxConvUTF8) );
		m_BlockA->Append( wxString( wRoute.point_ws,wxConvUTF8) );
    m_BlockA->Append( wxString( wRoute.point_enn,wxConvUTF8) );
    m_BlockA->Append( wxString( wRoute.point_ess,wxConvUTF8) );
    m_BlockA->Append( wxString( wRoute.point_nee,wxConvUTF8) );
    m_BlockA->Append( wxString( wRoute.point_nww,wxConvUTF8) );
    m_BlockA->Append( wxString( wRoute.point_see,wxConvUTF8) );
    m_BlockA->Append( wxString( wRoute.point_sww,wxConvUTF8) );
    m_BlockA->Append( wxString( wRoute.point_wnn,wxConvUTF8) );
    m_BlockA->Append( wxString( wRoute.point_wss,wxConvUTF8) );
		
		// for single track modules
		m_BlockA->Append( wxString( wRoute.point_e,wxConvUTF8) );
		m_BlockA->Append( wxString( wRoute.point_n,wxConvUTF8) );
		m_BlockA->Append( wxString( wRoute.point_s,wxConvUTF8) );
		m_BlockA->Append( wxString( wRoute.point_w,wxConvUTF8) );
		
    TraceOp.trc( "routedlg", TRCLEVEL_INFO, __LINE__, 9999, "appending points for B" );
		m_BlockB->Append( wxString( wRoute.point_en,wxConvUTF8) );
		m_BlockB->Append( wxString( wRoute.point_es,wxConvUTF8) );
		m_BlockB->Append( wxString( wRoute.point_ne,wxConvUTF8) );
		m_BlockB->Append( wxString( wRoute.point_nw,wxConvUTF8) );
		m_BlockB->Append( wxString( wRoute.point_se,wxConvUTF8) );
		m_BlockB->Append( wxString( wRoute.point_sw,wxConvUTF8) );
		m_BlockB->Append( wxString( wRoute.point_wn,wxConvUTF8) );
		m_BlockB->Append( wxString( wRoute.point_ws,wxConvUTF8) );
    m_BlockB->Append( wxString( wRoute.point_enn,wxConvUTF8) );
    m_BlockB->Append( wxString( wRoute.point_ess,wxConvUTF8) );
    m_BlockB->Append( wxString( wRoute.point_nee,wxConvUTF8) );
    m_BlockB->Append( wxString( wRoute.point_nww,wxConvUTF8) );
    m_BlockB->Append( wxString( wRoute.point_see,wxConvUTF8) );
    m_BlockB->Append( wxString( wRoute.point_sww,wxConvUTF8) );
    m_BlockB->Append( wxString( wRoute.point_wnn,wxConvUTF8) );
    m_BlockB->Append( wxString( wRoute.point_wss,wxConvUTF8) );
		
		// for single track modules
		m_BlockB->Append( wxString( wRoute.point_e,wxConvUTF8) );
		m_BlockB->Append( wxString( wRoute.point_n,wxConvUTF8) );
		m_BlockB->Append( wxString( wRoute.point_s,wxConvUTF8) );
		m_BlockB->Append( wxString( wRoute.point_w,wxConvUTF8) );
		
  }
  /* clean up the temp. list */
  ListOp.base.del(list);
}

void RouteDialog::initSwitchCombo() {
  m_SwitchId->Clear();
  m_SwitchId->Append( _T("<undef>"), (void*)NULL );

  iONode model = wxGetApp().getModel();
  iOList list = ListOp.inst();

  if( model != NULL ) {
    iONode swlist = wPlan.getswlist( model );
    if( swlist != NULL ) {
      int cnt = NodeOp.getChildCnt( swlist );
      for( int i = 0; i < cnt; i++ ) {
        iONode sw = NodeOp.getChild( swlist, i );
        const char* id = wSwitch.getid( sw );
        if( id != NULL ) {
          ListOp.add(list, (obj)sw);
		    }
	    }
    }
    iONode sglist = wPlan.getsglist( model );
    if( sglist != NULL ) {
      int cnt = NodeOp.getChildCnt( sglist );
      for( int i = 0; i < cnt; i++ ) {
        iONode sg = NodeOp.getChild( sglist, i );
        const char* id = wSignal.getid( sg );
        if( id != NULL ) {
          ListOp.add(list, (obj)sg);
        }
      }
    }
    iONode colist = wPlan.getcolist( model );
    if( colist != NULL ) {
      int cnt = NodeOp.getChildCnt( colist );
      for( int i = 0; i < cnt; i++ ) {
        iONode co = NodeOp.getChild( colist, i );
        const char* id = wOutput.getid( co );
        if( id != NULL ) {
          ListOp.add(list, (obj)co);
        }
      }
    }
    iONode ttlist = wPlan.getttlist( model );
    if( ttlist != NULL ) {
      int cnt = NodeOp.getChildCnt( ttlist );
      for( int i = 0; i < cnt; i++ ) {
        iONode tt = NodeOp.getChild( ttlist, i );
        const char* id = wItem.getid( tt );
        if( id != NULL ) {
          ListOp.add(list, (obj)tt);
        }
      }
    }
    iONode seltablist = wPlan.getseltablist( model );
    if( seltablist != NULL ) {
      int cnt = NodeOp.getChildCnt( seltablist );
      for( int i = 0; i < cnt; i++ ) {
        iONode seltab = NodeOp.getChild( seltablist, i );
        const char* id = wItem.getid( seltab );
        if( id != NULL ) {
          ListOp.add(list, (obj)seltab);
        }
      }
    }

    ListOp.sort(list, &__sortID);
    int cnt = ListOp.size( list );
    for( int i = 0; i < cnt; i++ ) {
      iONode sw = (iONode)ListOp.get( list, i );
      const char* id = wItem.getid(sw);
      m_SwitchId->Append( wxString(id,wxConvUTF8), sw );
    }

  }
  /* clean up the temp. list */
  ListOp.base.del(list);
}

void RouteDialog::initValues() {
  char* title = StrOp.fmt( "%s %s", (const char*)wxGetApp().getMsg("route").mb_str(wxConvUTF8), wRoute.getid( m_Props ) );
  SetTitle( wxString(title,wxConvUTF8) );
  StrOp.free( title );

  m_Id->SetValue( wxString(wRoute.getid( m_Props ),wxConvUTF8) );
  m_Description->SetValue( wxString(wItem.getdesc( m_Props ),wxConvUTF8) );

  // Initialize Block Comboboxes
  initBlockCombos();

//  iONode model = wxGetApp().getModel();

  m_BlockA->SetStringSelection( wRoute.getbka( m_Props ) == NULL ?
                                _T("<undef>"):wxString(wRoute.getbka( m_Props ),wxConvUTF8)  );
  m_BlockB->SetStringSelection( wRoute.getbkb( m_Props ) == NULL ?
                                _T("<undef>"):wxString(wRoute.getbkb( m_Props ),wxConvUTF8)  );
  m_BlockC->SetValue( wxString(wRoute.getbkc( m_Props ),wxConvUTF8)  );

  m_ModID->SetValue( wxString(wRoute.getmodid( m_Props ),wxConvUTF8)  );

  m_FromSide->SetValue( wRoute.isbkaside( m_Props ) ? true:false );
  m_ToSide->SetValue( wRoute.isbkbside( m_Props ) ? true:false );


  m_FromSignals->SetSelection(wRoute.getsga( m_Props ));
  m_ToSignals->SetSelection(wRoute.getsgb( m_Props ));

  int speed = 0; // none
  if( StrOp.equals( wBlock.min, wRoute.getspeed( m_Props ) ) )
    speed = 1;
  else if( StrOp.equals( wBlock.mid, wRoute.getspeed( m_Props ) ) )
    speed = 2;
  else if( StrOp.equals( wBlock.cruise, wRoute.getspeed( m_Props ) ) )
    speed = 3;
  else if( StrOp.equals( wBlock.max, wRoute.getspeed( m_Props ) ) )
    speed = 4;
  else if( StrOp.equals( wBlock.percent, wRoute.getspeed( m_Props ) ) )
    speed = 5;
  m_Speed->SetSelection( speed );
  char * str;
  str = StrOp.fmt( "%d", wRoute.getspeedpercent(m_Props) );
  m_SpeedPercent->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );

  m_ReduceV->SetValue(wRoute.isreduceV( m_Props ));
  m_MaxKmH->SetValue(wRoute.getmaxkmh(m_Props));

  m_SpeedConditionList->Clear();
  iONode spcond = wRoute.getspeedcondition(m_Props);
  while( spcond != NULL ) {
    m_SpeedConditionList->Append( wxString( wSpeedCondition.getdesc(spcond), wxConvUTF8));
    spcond = wRoute.nextspeedcondition(m_Props, spcond);
  }
  initSpeedCond();

  m_SwapPost->SetValue(wRoute.isswappost( m_Props ));
  m_Show->SetValue(wRoute.isshow( m_Props ));
  m_Manual->SetValue(wRoute.ismanual( m_Props ));

  m_Status->SetSelection( wRoute.getstatus(m_Props) );


  int countcars = 0; // no
  if( StrOp.equals( wRoute.forwards, wRoute.getcountcars( m_Props ) ) )
    countcars = 1;
  else if( StrOp.equals( wRoute.reverse, wRoute.getcountcars( m_Props ) ) )
    countcars = 2;
  m_CountCars->SetSelection( countcars );


  initCommands();

  // Initialize sorted Switch Combo
  initSwitchCombo();

  m_SwitchCmd->SetSelection(1);
  m_SwitchCmd->Enable( 2, false );
  m_SwitchCmd->Enable( 3, false );
  m_SwitchCmd->Enable( 4, false );
  m_SwitchCmd->Enable( 5, false );
  m_SwitchCmd->Enable( 6, false );
  m_SwitchCmd->Enable( 7, false );
  m_SwitchCmd->Enable( 8, false );
  m_SwitchCmd->Enable( 9, false );
  m_SwitchCmd->Enable( 10, false );
  m_SwitchCmd->Enable( 11, false );

  m_Lock->SetValue(true);
  m_SwReduceV->SetValue(true);
  m_AtFree->SetValue(false);

  // Sensors
  m_SensorList->Clear();
  iONode fb = wRoute.getfbevent( m_Props );
  while( fb != NULL ) {
    m_SensorList->Append( wxString(wFeedbackEvent.getid( fb ),wxConvUTF8), fb );
    fb = wRoute.nextfbevent( m_Props, fb );
  };

  // Permissions

  // remove selections:
  m_ExcludeList->Clear();
  m_IncludeList->Clear();

  // set selections:
  iONode excl = wRoute.getexcl( m_Props );
  while( excl != NULL ) {
    m_ExcludeList->Append(wxString(wPermExclude.getid(excl),wxConvUTF8), excl);
    excl = wBlock.nextexcl( m_Props, excl );
  };

  iONode incl = wRoute.getincl( m_Props );
  while( incl != NULL ) {
    m_IncludeList->Append( wxString(wPermInclude.getid(incl),wxConvUTF8), incl );
    incl = wBlock.nextincl( m_Props, incl );
  };

  m_PermTypeNone->SetValue( false );
  m_PermTypeGoods->SetValue( false );
  m_PermTypePerson->SetValue( false );
  m_PermTypeMixed->SetValue( false );
  m_PermTypeCleaning->SetValue( false );
  m_PermTypeICE->SetValue( false );
  m_PermTypePost->SetValue( false );
  m_PermTypeLight->SetValue( false );
  m_PermTypeLightGoods->SetValue( false );
  m_PermTypeLocal->SetValue( false );
  m_PermTypeShunting->SetValue( false );

  iOStrTok tok = StrTokOp.inst( wRoute.gettypeperm( m_Props ), ',' );
  while( StrTokOp.hasMoreTokens(tok) ) {
    const char* permsubtype = StrTokOp.nextToken( tok );

    if( StrOp.equals( permsubtype, wLoc.cargo_none  ) )
      m_PermTypeNone->SetValue( true );
    if( StrOp.equals( permsubtype, wLoc.cargo_goods  ) )
      m_PermTypeGoods->SetValue( true );
    if( StrOp.equals( permsubtype, wLoc.cargo_person  ) )
      m_PermTypePerson->SetValue( true );
    if( StrOp.equals( permsubtype, wLoc.cargo_mixed  ) )
      m_PermTypeMixed->SetValue( true );
    if( StrOp.equals( permsubtype, wLoc.cargo_cleaning  ) )
      m_PermTypeCleaning->SetValue( true );
    if( StrOp.equals( permsubtype, wLoc.cargo_ice  ) )
      m_PermTypeICE->SetValue( true );
    if( StrOp.equals( permsubtype, wLoc.cargo_post  ) )
      m_PermTypePost->SetValue( true );
    if( StrOp.equals( permsubtype, wLoc.cargo_light  ) )
      m_PermTypeLight->SetValue( true );
    if( StrOp.equals( permsubtype, wLoc.cargo_lightgoods  ) )
      m_PermTypeLightGoods->SetValue( true );
    if( StrOp.equals( permsubtype, wLoc.cargo_regional  ) )
      m_PermTypeLocal->SetValue( true );
    if( StrOp.equals( permsubtype, wLoc.cargo_shunting  ) )
      m_PermTypeShunting->SetValue( true );
  }
  StrTokOp.base.del(tok);

  m_Class->SetValue(wxString(wRoute.getclass(m_Props),wxConvUTF8));

  m_MaxLen->SetValue(wRoute.getmaxlen(m_Props));
  m_MinLen->SetValue(wRoute.getminlen(m_Props));
  m_Commuter->SetSelection(0);
  if(wRoute.iscommuter(m_Props))
    m_Commuter->SetSelection(1);
  else if(wRoute.isnocommuter(m_Props))
    m_Commuter->SetSelection(2);
  m_Placing->SetSelection(wRoute.getplacing(m_Props));
  
  // Location
  char* val = StrOp.fmt( "%d", wRoute.getx( m_Props ) );
  m_x->SetValue( wxString(val,wxConvUTF8) ); StrOp.free( val );
  val = StrOp.fmt( "%d", wRoute.gety( m_Props ) );
  m_y->SetValue( wxString(val,wxConvUTF8) ); StrOp.free( val );
  val = StrOp.fmt( "%d", wRoute.getz( m_Props ) );
  m_z->SetValue( wxString(val,wxConvUTF8) ); StrOp.free( val );
  if( StrOp.equals( wItem.north, wRoute.getori( m_Props ) ) )
    m_ori->SetSelection( 0 );
  else if( StrOp.equals( wItem.east, wRoute.getori( m_Props ) ) )
    m_ori->SetSelection( 1 );
  else if( StrOp.equals( wItem.south, wRoute.getori( m_Props ) ) )
    m_ori->SetSelection( 2 );
  else
    m_ori->SetSelection( 3 );
  

  // Conditions
  initCondList();


  // Wiring
  m_CTCIID1->SetValue( wxString(wRoute.getctciid1(m_Props),wxConvUTF8));
  m_CTCIID2->SetValue( wxString(wRoute.getctciid2(m_Props),wxConvUTF8));
  m_CTCIID3->SetValue( wxString(wRoute.getctciid3(m_Props),wxConvUTF8));
  m_CTCBus1->SetValue( wxString::Format( wxT("%d"), wRoute.getctcbus1(m_Props)));
  m_CTCBus2->SetValue( wxString::Format( wxT("%d"), wRoute.getctcbus2(m_Props)));
  m_CTCBus3->SetValue( wxString::Format( wxT("%d"), wRoute.getctcbus3(m_Props)));
  m_CTCAddr1->SetValue( wRoute.getctcaddr1(m_Props));
  m_CTCAddr2->SetValue( wRoute.getctcaddr2(m_Props));
  m_CTCAddr3->SetValue( wRoute.getctcaddr3(m_Props));

  m_Output1->SetStringSelection( wRoute.getctcoutput1( m_Props ) == NULL ?
                                _T(""):wxString(wRoute.getctcoutput1( m_Props ),wxConvUTF8)  );
  m_Output2->SetStringSelection( wRoute.getctcoutput2( m_Props ) == NULL ?
                                _T(""):wxString(wRoute.getctcoutput2( m_Props ),wxConvUTF8)  );
  m_Output3->SetStringSelection( wRoute.getctcoutput3( m_Props ) == NULL ?
                                _T(""):wxString(wRoute.getctcoutput3( m_Props ),wxConvUTF8)  );


}

void RouteDialog::initCondList() {
  // Conditions
  if( m_CondGrid->GetNumberRows() > 0 )
    m_CondGrid->DeleteRows(0,m_CondGrid->GetNumberRows());

  iONode cond = wRoute.getstcondition( m_Props );
  while( cond != NULL ) {
    m_CondGrid->AppendRows();
    m_CondGrid->SetCellValue(m_CondGrid->GetNumberRows()-1, 0,
        wRouteCondition.isnotprevbk(cond) ? wxGetApp().getMsg("yes"):wxGetApp().getMsg("no") );
    m_CondGrid->SetCellValue(m_CondGrid->GetNumberRows()-1, 1, wxString(wRouteCondition.getprevbkid(cond),wxConvUTF8 ) );
    m_CondGrid->SetCellValue(m_CondGrid->GetNumberRows()-1, 2, wxGetApp().getMsg(wRouteCondition.gettype(cond) ) );
    m_CondGrid->SetCellValue(m_CondGrid->GetNumberRows()-1, 3,
        wRouteCondition.iscommuter(cond) ? wxGetApp().getMsg("yes"):wxGetApp().getMsg("no") );
    m_CondGrid->SetCellValue(m_CondGrid->GetNumberRows()-1, 4,
        wRouteCondition.ischdir(cond) ? wxGetApp().getMsg("yes"):wxGetApp().getMsg("no") );
    m_CondGrid->SetCellValue(m_CondGrid->GetNumberRows()-1, 5,
        wRouteCondition.isallowschedules(cond) ? wxGetApp().getMsg("yes"):wxGetApp().getMsg("no") );

    m_CondGrid->SetReadOnly( m_CondGrid->GetNumberRows()-1, 0, true );
    m_CondGrid->SetReadOnly( m_CondGrid->GetNumberRows()-1, 1, true );
    m_CondGrid->SetReadOnly( m_CondGrid->GetNumberRows()-1, 2, true );
    m_CondGrid->SetReadOnly( m_CondGrid->GetNumberRows()-1, 3, true );
    m_CondGrid->SetReadOnly( m_CondGrid->GetNumberRows()-1, 4, true );
    m_CondGrid->SetReadOnly( m_CondGrid->GetNumberRows()-1, 5, true );
    cond = wRoute.nextstcondition( m_Props, cond );
  };

  m_CondGrid->AutoSizeColumns();
  m_CondGrid->FitInside();
  m_ConditionsPanel->GetSizer()->Layout();

  m_CondDelete->Enable( false );
  m_CondModify->Enable( false );



}



void RouteDialog::initCommands() {
  int idx = 0;
  m_Commands2->DeleteAllItems();
  m_SwCmd = NULL;

  iONode swcmd = wRoute.getswcmd( m_Props );
  while( swcmd != NULL ) {
    m_Commands2->InsertItem( idx, wxString(wSwitchCmd.getid( swcmd ),wxConvUTF8) );
    m_Commands2->SetItem( idx, 1, wxString(wSwitchCmd.getcmd( swcmd ),wxConvUTF8) );
    m_Commands2->SetItem( idx, 2, wxString::Format(wxT("%d"), wSwitchCmd.gettrack(swcmd)) );
    m_Commands2->SetItem( idx, 3, wxString(wSwitchCmd.islock(swcmd)?"X":"",wxConvUTF8) );
    m_Commands2->SetItem( idx, 4, wxString(wSwitchCmd.isreduceV(swcmd)?"X":"",wxConvUTF8) );
    m_Commands2->SetItem( idx, 5, wxString(wSwitchCmd.isatfree(swcmd)?"X":"",wxConvUTF8) );
    m_Commands2->SetItemPtrData(idx, (wxUIntPtr)swcmd);

    idx++;
    swcmd = wRoute.nextswcmd( m_Props, swcmd );
  }
  m_Delete->Enable( false );
  m_Modify->Enable( false );

  // resize
  for( int n = 0; n < 6; n++ ) {
    m_Commands2->SetColumnWidth(n, wxLIST_AUTOSIZE_USEHEADER);
    int autoheadersize = m_Commands2->GetColumnWidth(n);
    m_Commands2->SetColumnWidth(n, wxLIST_AUTOSIZE);
    int autosize = m_Commands2->GetColumnWidth(n);
    if(autoheadersize > autosize )
      m_Commands2->SetColumnWidth(n, wxLIST_AUTOSIZE_USEHEADER);
  }

}


bool RouteDialog::evaluate() {
  if( m_Props == NULL )
    return false;

  iONode model  = wxGetApp().getModel();
  iONode stlist = wPlan.getstlist( model );

  if( existID( this, stlist, m_Props, m_Id->GetValue() ) ) {
    m_Id->SetValue( wxString(wItem.getid( m_Props ),wxConvUTF8) );
    return false;
  }
  wItem.setdesc( m_Props, m_Description->GetValue().mb_str(wxConvUTF8) );

  wItem.setprev_id( m_Props, wItem.getid(m_Props) );
  wRoute.setid( m_Props, m_Id->GetValue().mb_str(wxConvUTF8) );
  if( StrOp.equals( "<undef>", m_BlockA->GetStringSelection().mb_str(wxConvUTF8) ) )
    wRoute.setbka( m_Props, "" );
  else
    wRoute.setbka( m_Props, m_BlockA->GetStringSelection().mb_str(wxConvUTF8) );

  if( StrOp.equals( "<undef>", m_BlockB->GetStringSelection().mb_str(wxConvUTF8) ) )
    wRoute.setbkb( m_Props, "" );
  else
    wRoute.setbkb( m_Props, m_BlockB->GetStringSelection().mb_str(wxConvUTF8) );

  wRoute.setbkc( m_Props, m_BlockC->GetValue().mb_str(wxConvUTF8) );

  wRoute.setmodid( m_Props, m_ModID->GetValue().mb_str(wxConvUTF8) );

  wRoute.setbkaside( m_Props, m_FromSide->GetValue() ? True:False );
  wRoute.setbkbside( m_Props, m_ToSide->GetValue() ? True:False );

  wRoute.setsga( m_Props, m_FromSignals->GetSelection() );
  wRoute.setsgb( m_Props, m_ToSignals->GetSelection() );


  if( m_Speed->GetSelection() == 1 )
    wRoute.setspeed( m_Props, wBlock.min );
  else if( m_Speed->GetSelection() == 2 )
    wRoute.setspeed( m_Props, wBlock.mid );
  else if( m_Speed->GetSelection() == 3 )
    wRoute.setspeed( m_Props, wBlock.cruise );
  else if( m_Speed->GetSelection() == 4 )
    wRoute.setspeed( m_Props, wBlock.max );
  else if( m_Speed->GetSelection() == 5 ) {
    wRoute.setspeed( m_Props, wBlock.percent );
    wRoute.setspeedpercent( m_Props, m_SpeedPercent->GetValue() );
  }
  else
    wRoute.setspeed( m_Props, wRoute.V_none );


  if( m_CountCars->GetSelection() == 1 )
    wRoute.setcountcars( m_Props, wRoute.forwards);
  else if( m_CountCars->GetSelection() == 2 )
    wRoute.setcountcars( m_Props, wRoute.reverse);
  else
    wRoute.setcountcars( m_Props, wRoute.no);



  wRoute.setreduceV( m_Props, m_ReduceV->IsChecked()?True:False);
  wRoute.setmaxkmh(m_Props, m_MaxKmH->GetValue());

  wRoute.setswappost( m_Props, m_SwapPost->IsChecked()?True:False);

  wRoute.setcrossingblocksignals( m_Props, False);
  wRoute.setshow( m_Props, m_Show->IsChecked()?True:False);
  wRoute.setmanual( m_Props, m_Manual->IsChecked()?True:False);
  wRoute.setstatus(m_Props, m_Status->GetSelection() );


  // Permissions
  char* permtype = NULL;

  if( m_PermTypeNone->IsChecked() ) {
    if( permtype != NULL )
      permtype = StrOp.cat( permtype, "," );
    permtype = StrOp.cat( permtype, wLoc.cargo_none );
  }
  if( m_PermTypeGoods->IsChecked() ) {
    if( permtype != NULL )
      permtype = StrOp.cat( permtype, "," );
    permtype = StrOp.cat( permtype, wLoc.cargo_goods );
  }
  if( m_PermTypePerson->IsChecked() ) {
    if( permtype != NULL )
      permtype = StrOp.cat( permtype, "," );
    permtype = StrOp.cat( permtype, wLoc.cargo_person );
  }
  if( m_PermTypeMixed->IsChecked() ) {
    if( permtype != NULL )
      permtype = StrOp.cat( permtype, "," );
    permtype = StrOp.cat( permtype, wLoc.cargo_mixed );
  }
  if( m_PermTypeCleaning->IsChecked() ) {
    if( permtype != NULL )
      permtype = StrOp.cat( permtype, "," );
    permtype = StrOp.cat( permtype, wLoc.cargo_cleaning );
  }
  if( m_PermTypeICE->IsChecked() ) {
    if( permtype != NULL )
      permtype = StrOp.cat( permtype, "," );
    permtype = StrOp.cat( permtype, wLoc.cargo_ice );
  }
  if( m_PermTypePost->IsChecked() ) {
    if( permtype != NULL )
      permtype = StrOp.cat( permtype, "," );
    permtype = StrOp.cat( permtype, wLoc.cargo_post );
  }
  if( m_PermTypeLight->IsChecked() ) {
    if( permtype != NULL )
      permtype = StrOp.cat( permtype, "," );
    permtype = StrOp.cat( permtype, wLoc.cargo_light );
  }
  if( m_PermTypeLightGoods->IsChecked() ) {
    if( permtype != NULL )
      permtype = StrOp.cat( permtype, "," );
    permtype = StrOp.cat( permtype, wLoc.cargo_lightgoods );
  }
  if( m_PermTypeLocal->IsChecked() ) {
    if( permtype != NULL )
      permtype = StrOp.cat( permtype, "," );
    permtype = StrOp.cat( permtype, wLoc.cargo_regional );
  }
  if( m_PermTypeShunting->IsChecked() ) {
    if( permtype != NULL )
      permtype = StrOp.cat( permtype, "," );
    permtype = StrOp.cat( permtype, wLoc.cargo_shunting );
  }


  if( permtype != NULL ) {
    wRoute.settypeperm( m_Props, permtype );
    StrOp.free(permtype);
  }
  else {
    wRoute.settypeperm( m_Props, "" );
  }

  wRoute.setclass(m_Props, m_Class->GetValue().mb_str(wxConvUTF8) );

  wRoute.setmaxlen(m_Props,m_MaxLen->GetValue());
  wRoute.setminlen(m_Props,m_MinLen->GetValue());
  wRoute.setcommuter(m_Props, False);
  wRoute.setnocommuter(m_Props, False);
  if(m_Commuter->GetSelection()==1)
    wRoute.setcommuter(m_Props, True);
  if(m_Commuter->GetSelection()==2)
    wRoute.setnocommuter(m_Props, True);
  wRoute.setplacing(m_Props, m_Placing->GetSelection());

  // Location
  wRoute.setx( m_Props, atoi( m_x->GetValue().mb_str(wxConvUTF8) ) );
  wRoute.sety( m_Props, atoi( m_y->GetValue().mb_str(wxConvUTF8) ) );
  wRoute.setz( m_Props, atoi( m_z->GetValue().mb_str(wxConvUTF8) ) );
  int ori = m_ori->GetSelection();
  if( ori == 0 )
    wRoute.setori( m_Props, wItem.north );
  else if( ori == 1 )
    wRoute.setori( m_Props, wItem.east );
  else if( ori == 2 )
    wRoute.setori( m_Props, wItem.south );
  else if( ori == 3 )
    wRoute.setori( m_Props, wItem.west );


  // Wiring
  wRoute.setctciid1(m_Props, m_CTCIID1->GetValue().mb_str(wxConvUTF8));
  wRoute.setctciid2(m_Props, m_CTCIID2->GetValue().mb_str(wxConvUTF8));
  wRoute.setctciid3(m_Props, m_CTCIID3->GetValue().mb_str(wxConvUTF8));
  wRoute.setctcbus1(m_Props, atoi(m_CTCBus1->GetValue().mb_str(wxConvUTF8)));
  wRoute.setctcbus2(m_Props, atoi(m_CTCBus2->GetValue().mb_str(wxConvUTF8)));
  wRoute.setctcbus3(m_Props, atoi(m_CTCBus3->GetValue().mb_str(wxConvUTF8)));
  wRoute.setctcaddr1(m_Props, m_CTCAddr1->GetValue());
  wRoute.setctcaddr2(m_Props, m_CTCAddr2->GetValue());
  wRoute.setctcaddr3(m_Props, m_CTCAddr3->GetValue());

  wRoute.setctcoutput1( m_Props, m_Output1->GetStringSelection().mb_str(wxConvUTF8) );
  wRoute.setctcoutput2( m_Props, m_Output2->GetStringSelection().mb_str(wxConvUTF8) );
  wRoute.setctcoutput3( m_Props, m_Output3->GetStringSelection().mb_str(wxConvUTF8) );

  // Speed
  wxCommandEvent evt;
  OnSpeedcondModifyClick(evt);

  return true;
}

/*!
 * RouteDialog creator
 */

bool RouteDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin RouteDialog member initialisation
    m_Notebook = NULL;
    m_IndexPanel = NULL;
    m_List2 = NULL;
    m_New = NULL;
    m_DeleteRoute = NULL;
    m_Test = NULL;
    m_TestLock = NULL;
    m_ResetRoute = NULL;
    m_Doc = NULL;
    m_CopyRoute = NULL;
    m_GeneralPanel = NULL;
    m_LabelId = NULL;
    m_Id = NULL;
    m_labModID = NULL;
    m_ModID = NULL;
    m_labDescription = NULL;
    m_Description = NULL;
    m_LabelBlockA = NULL;
    m_BlockA = NULL;
    m_FromSide = NULL;
    m_LabelBlockB = NULL;
    m_BlockB = NULL;
    m_ToSide = NULL;
    m_labCrossingBlock = NULL;
    m_BlockC = NULL;
    m_FromSignals = NULL;
    m_ToSignals = NULL;
    m_CountCars = NULL;
    m_DetailsBox = NULL;
    m_SwapPost = NULL;
    m_Manual = NULL;
    m_Actions = NULL;
    m_Show = NULL;
    m_Status = NULL;
    m_SpeedPanel = NULL;
    m_Speed = NULL;
    m_labSpeedPercent = NULL;
    m_SpeedPercent = NULL;
    m_labMaxKmH = NULL;
    m_MaxKmH = NULL;
    m_SpeedOptionsBox = NULL;
    m_ReduceV = NULL;
    m_SpeedConditionsBox = NULL;
    m_SpeedConditionList = NULL;
    m_labSpeedCondDesc = NULL;
    m_SpeedCondDesc = NULL;
    m_labSpeedCondType = NULL;
    m_SpeedCondType = NULL;
    m_labSpeedCondClass = NULL;
    m_SpeedCondClass = NULL;
    m_labSpeedCondVariable = NULL;
    m_SpeedCondVariable = NULL;
    m_SpeedCondVarSub = NULL;
    m_SpeedCondValue = NULL;
    m_labSpeedCondPercent = NULL;
    m_SpeedCondPercent = NULL;
    m_SpeedCondAdd = NULL;
    m_SpeedCondDel = NULL;
    m_SpeedCondModify = NULL;
    m_SpeedCondImport = NULL;
    m_SpeedCondImportFrom = NULL;
    m_CommandPanel = NULL;
    m_Commands2 = NULL;
    m_Delete = NULL;
    m_Modify = NULL;
    m_CmdUp = NULL;
    m_CmdDown = NULL;
    m_LabelSwitchId = NULL;
    m_SwitchId = NULL;
    m_labTrackNumber = NULL;
    m_TrackNumber = NULL;
    m_Add = NULL;
    m_SwitchCmd = NULL;
    m_Lock = NULL;
    m_SwReduceV = NULL;
    m_AtFree = NULL;
    m_SensorPanel = NULL;
    m_SensorList = NULL;
    m_SensorCombo = NULL;
    m_AddSensor = NULL;
    m_DelSensor = NULL;
    m_PermissionsPanel = NULL;
    m_labLocoListPerm = NULL;
    m_LocoListPerm = NULL;
    m_AddInclude = NULL;
    m_AddExclude = NULL;
    m_labInclude = NULL;
    m_IncludeList = NULL;
    m_RemoveInclude = NULL;
    m_labExclude = NULL;
    m_ExcludeList = NULL;
    m_RemoveExclude = NULL;
    m_PermType = NULL;
    m_PermTypeGoods = NULL;
    m_PermTypeMixed = NULL;
    m_PermTypeICE = NULL;
    m_PermTypePerson = NULL;
    m_PermTypeLightGoods = NULL;
    m_PermTypeNone = NULL;
    m_PermTypeLocal = NULL;
    m_PermTypeCleaning = NULL;
    m_PermTypePost = NULL;
    m_PermTypeLight = NULL;
    m_PermTypeShunting = NULL;
    m_labMaxLen = NULL;
    m_MaxLen = NULL;
    m_labMinLen = NULL;
    m_MinLen = NULL;
    m_Commuter = NULL;
    m_Placing = NULL;
    m_labClass = NULL;
    m_Class = NULL;
    m_ConditionsPanel = NULL;
    m_CondGrid = NULL;
    m_CondNotFromBlock = NULL;
    m_CondFromBlock = NULL;
    m_CondType = NULL;
    m_CondCommuter = NULL;
    m_CondChangeDir = NULL;
    m_CondAllowSchedules = NULL;
    m_CondAdd = NULL;
    m_CondModify = NULL;
    m_CondDelete = NULL;
    m_LocationPanel = NULL;
    m_LabelX = NULL;
    m_x = NULL;
    m_LabelY = NULL;
    m_y = NULL;
    m_LabelZ = NULL;
    m_z = NULL;
    m_ori = NULL;
    m_WiringPanel = NULL;
    m_CTCBox = NULL;
    m_labCTCbutton = NULL;
    m_labCTCIID = NULL;
    m_labCTCBus = NULL;
    m_labCTCAddr = NULL;
    m_labOutput = NULL;
    m_labCTCButton1 = NULL;
    m_CTCIID1 = NULL;
    m_CTCBus1 = NULL;
    m_CTCAddr1 = NULL;
    m_Output1 = NULL;
    m_labCTCButton2 = NULL;
    m_CTCIID2 = NULL;
    m_CTCBus2 = NULL;
    m_CTCAddr2 = NULL;
    m_Output2 = NULL;
    m_labCTCButton3 = NULL;
    m_CTCIID3 = NULL;
    m_CTCBus3 = NULL;
    m_CTCAddr3 = NULL;
    m_Output3 = NULL;
    m_Cancel = NULL;
    m_OK = NULL;
    m_Apply = NULL;
    m_Help = NULL;
////@end RouteDialog member initialisation

////@begin RouteDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end RouteDialog creation
    return true;
}

/*!
 * Control creation for RouteDialog
 */

void RouteDialog::CreateControls()
{
////@begin RouteDialog content construction
    RouteDialog* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    m_Notebook = new wxNotebook( itemDialog1, ID_NOTEBOOK_STREET, wxDefaultPosition, wxDefaultSize, m_TabAlign );

    m_IndexPanel = new wxPanel( m_Notebook, ID_PANEL_ST_INDEX, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxVERTICAL);
    m_IndexPanel->SetSizer(itemBoxSizer5);

    m_List2 = new wxListCtrl( m_IndexPanel, ID_LISTCTRLINDEX_ST, wxDefaultPosition, wxSize(100, 100), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES );
    itemBoxSizer5->Add(m_List2, 1, wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer7 = new wxFlexGridSizer(0, 7, 0, 0);
    itemBoxSizer5->Add(itemFlexGridSizer7, 0, wxGROW|wxALL, 5);
    m_New = new wxButton( m_IndexPanel, ID_BUTTON_ST_NEW, _("New"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_New, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5);

    m_DeleteRoute = new wxButton( m_IndexPanel, ID_BUTTON_ST_DELETE_ROUTE, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_DeleteRoute, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5);

    m_Test = new wxButton( m_IndexPanel, ID_BUTTON_ST_TEST, _("Test"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_Test, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5);

    m_TestLock = new wxButton( m_IndexPanel, ID_ROUTE_LOCK, _("Lock"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_TestLock, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5);

    m_ResetRoute = new wxButton( m_IndexPanel, ID_RESET_ROUTE, _("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_ResetRoute, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5);

    m_Doc = new wxButton( m_IndexPanel, ID_BUTTON_ST_DOC, _("Doc"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_Doc, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5);

    m_CopyRoute = new wxButton( m_IndexPanel, ID_BUTTON_ST_COPY, _("Copy"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_CopyRoute, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5);

    m_Notebook->AddPage(m_IndexPanel, _("Index"));

    m_GeneralPanel = new wxPanel( m_Notebook, ID_PANEL_ST_GENERAL, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer16 = new wxBoxSizer(wxVERTICAL);
    m_GeneralPanel->SetSizer(itemBoxSizer16);

    wxBoxSizer* itemBoxSizer17 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer16->Add(itemBoxSizer17, 0, wxGROW|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer18 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer17->Add(itemFlexGridSizer18, 0, wxGROW|wxALL, 5);
    m_LabelId = new wxStaticText( m_GeneralPanel, wxID_STATIC_ST_ID, _("Id"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer18->Add(m_LabelId, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Id = new wxTextCtrl( m_GeneralPanel, ID_TEXTCTRL_ST_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer18->Add(m_Id, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labModID = new wxStaticText( m_GeneralPanel, wxID_ANY, _("Module ID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer18->Add(m_labModID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ModID = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer18->Add(m_ModID, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labDescription = new wxStaticText( m_GeneralPanel, wxID_ANY, _("Description"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer18->Add(m_labDescription, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Description = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer18->Add(m_Description, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer18->AddGrowableCol(1);

    wxFlexGridSizer* itemFlexGridSizer25 = new wxFlexGridSizer(0, 3, 0, 0);
    itemBoxSizer17->Add(itemFlexGridSizer25, 0, wxGROW, 5);
    m_LabelBlockA = new wxStaticText( m_GeneralPanel, wxID_STATIC_ST_BLOCKA, _("from block"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer25->Add(m_LabelBlockA, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_BlockAStrings;
    m_BlockA = new wxComboBox( m_GeneralPanel, ID_COMBOBOX_ST_BLOCKA, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_BlockAStrings, wxCB_READONLY );
    itemFlexGridSizer25->Add(m_BlockA, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_FromSide = new wxCheckBox( m_GeneralPanel, wxID_ANY, _("+"), wxDefaultPosition, wxDefaultSize, 0 );
    m_FromSide->SetValue(false);
    itemFlexGridSizer25->Add(m_FromSide, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelBlockB = new wxStaticText( m_GeneralPanel, wxID_STATIC_BLOCKB, _("to block"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer25->Add(m_LabelBlockB, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_BlockBStrings;
    m_BlockB = new wxComboBox( m_GeneralPanel, ID_COMBOBOX_ST_BLOCKB, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_BlockBStrings, wxCB_READONLY );
    itemFlexGridSizer25->Add(m_BlockB, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ToSide = new wxCheckBox( m_GeneralPanel, wxID_ANY, _("+"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ToSide->SetValue(false);
    itemFlexGridSizer25->Add(m_ToSide, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer25->AddGrowableCol(1);

    wxFlexGridSizer* itemFlexGridSizer32 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer17->Add(itemFlexGridSizer32, 0, wxGROW, 5);
    m_labCrossingBlock = new wxStaticText( m_GeneralPanel, wxID_STATIC_BLOCKC, _("crossing block"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer32->Add(m_labCrossingBlock, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_BlockC = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer32->Add(m_BlockC, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer32->AddGrowableCol(1);

    wxBoxSizer* itemBoxSizer35 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer16->Add(itemBoxSizer35, 0, wxGROW|wxRIGHT, 5);
    wxFlexGridSizer* itemFlexGridSizer36 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer35->Add(itemFlexGridSizer36, 0, wxGROW|wxLEFT|wxRIGHT, 5);
    wxArrayString m_FromSignalsStrings;
    m_FromSignalsStrings.Add(_("&forward"));
    m_FromSignalsStrings.Add(_("&reverse"));
    m_FromSignalsStrings.Add(_("&none"));
    m_FromSignals = new wxRadioBox( m_GeneralPanel, wxID_ANY, _("From signal pair"), wxDefaultPosition, wxDefaultSize, m_FromSignalsStrings, 1, wxRA_SPECIFY_ROWS );
    m_FromSignals->SetSelection(0);
    itemFlexGridSizer36->Add(m_FromSignals, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_ToSignalsStrings;
    m_ToSignalsStrings.Add(_("&forward"));
    m_ToSignalsStrings.Add(_("&reverse"));
    m_ToSignalsStrings.Add(_("&none"));
    m_ToSignals = new wxRadioBox( m_GeneralPanel, wxID_ANY, _("To signal pair"), wxDefaultPosition, wxDefaultSize, m_ToSignalsStrings, 1, wxRA_SPECIFY_ROWS );
    m_ToSignals->SetSelection(0);
    itemFlexGridSizer36->Add(m_ToSignals, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_CountCarsStrings;
    m_CountCarsStrings.Add(_("&no"));
    m_CountCarsStrings.Add(_("&forwards"));
    m_CountCarsStrings.Add(_("&reverse"));
    m_CountCars = new wxRadioBox( m_GeneralPanel, wxID_ANY, _("Count cars before firing events"), wxDefaultPosition, wxDefaultSize, m_CountCarsStrings, 1, wxRA_SPECIFY_ROWS );
    m_CountCars->SetSelection(0);
    itemFlexGridSizer36->Add(m_CountCars, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer40 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer35->Add(itemBoxSizer40, 0, wxGROW, 5);
    m_DetailsBox = new wxStaticBox(m_GeneralPanel, wxID_ANY, _("Details"));
    wxStaticBoxSizer* itemStaticBoxSizer41 = new wxStaticBoxSizer(m_DetailsBox, wxHORIZONTAL);
    itemBoxSizer40->Add(itemStaticBoxSizer41, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer42 = new wxFlexGridSizer(0, 2, 0, 0);
    itemStaticBoxSizer41->Add(itemFlexGridSizer42, 1, wxGROW, 5);
    m_SwapPost = new wxCheckBox( m_GeneralPanel, wxID_ANY, _("Swap post"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SwapPost->SetValue(false);
    itemFlexGridSizer42->Add(m_SwapPost, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Manual = new wxCheckBox( m_GeneralPanel, wxID_ANY, _("Manual controlled"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Manual->SetValue(false);
    itemFlexGridSizer42->Add(m_Manual, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Actions = new wxButton( m_GeneralPanel, ID_ROUTE_ACTIONS, _("Actions..."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer42->Add(m_Actions, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Show = new wxCheckBox( m_GeneralPanel, wxID_ANY, _("Visible"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Show->SetValue(false);
    itemFlexGridSizer42->Add(m_Show, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_StatusStrings;
    m_StatusStrings.Add(_("&free"));
    m_StatusStrings.Add(_("&locked"));
    m_StatusStrings.Add(_("&selected"));
    m_StatusStrings.Add(_("&deselected"));
    m_StatusStrings.Add(_("&closed"));
    m_Status = new wxRadioBox( m_GeneralPanel, wxID_ANY, _("Status"), wxDefaultPosition, wxDefaultSize, m_StatusStrings, 2, wxRA_SPECIFY_ROWS );
    m_Status->SetSelection(0);
    itemBoxSizer40->Add(m_Status, 0, wxALIGN_TOP|wxALL, 5);

    m_Notebook->AddPage(m_GeneralPanel, _("General"));

    m_SpeedPanel = new wxPanel( m_Notebook, ID_PANEL_ST_SPEED, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer49 = new wxBoxSizer(wxVERTICAL);
    m_SpeedPanel->SetSizer(itemBoxSizer49);

    wxArrayString m_SpeedStrings;
    m_SpeedStrings.Add(_("&None"));
    m_SpeedStrings.Add(_("&Min"));
    m_SpeedStrings.Add(_("&Mid"));
    m_SpeedStrings.Add(_("&Cruise"));
    m_SpeedStrings.Add(_("&Max"));
    m_SpeedStrings.Add(_("&%"));
    m_Speed = new wxRadioBox( m_SpeedPanel, ID_ROUTE_VELOCITY, _("Speed"), wxDefaultPosition, wxDefaultSize, m_SpeedStrings, 1, wxRA_SPECIFY_ROWS );
    m_Speed->SetSelection(0);
    itemBoxSizer49->Add(m_Speed, 0, wxALIGN_LEFT|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer51 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer49->Add(itemFlexGridSizer51, 0, wxGROW|wxLEFT|wxRIGHT, 5);
    m_labSpeedPercent = new wxStaticText( m_SpeedPanel, wxID_ANY, _("Percent"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer51->Add(m_labSpeedPercent, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM, 5);

    m_SpeedPercent = new wxSpinCtrl( m_SpeedPanel, wxID_ANY, _T("80"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 100, 80 );
    itemFlexGridSizer51->Add(m_SpeedPercent, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_BOTTOM|wxALL, 5);

    m_labMaxKmH = new wxStaticText( m_SpeedPanel, wxID_ANY, _("Max. KmH"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer51->Add(m_labMaxKmH, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_MaxKmH = new wxSpinCtrl( m_SpeedPanel, wxID_ANY, _T("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 500, 0 );
    itemFlexGridSizer51->Add(m_MaxKmH, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_SpeedOptionsBox = new wxStaticBox(m_SpeedPanel, wxID_ANY, _("Options"));
    wxStaticBoxSizer* itemStaticBoxSizer56 = new wxStaticBoxSizer(m_SpeedOptionsBox, wxVERTICAL);
    itemBoxSizer49->Add(itemStaticBoxSizer56, 0, wxGROW|wxALL, 5);
    m_ReduceV = new wxCheckBox( m_SpeedPanel, wxID_ANY, _("Reduce speed"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ReduceV->SetValue(false);
    itemStaticBoxSizer56->Add(m_ReduceV, 0, wxALIGN_LEFT|wxALL, 5);

    m_SpeedConditionsBox = new wxStaticBox(m_SpeedPanel, wxID_ANY, _("Conditions"));
    wxStaticBoxSizer* itemStaticBoxSizer58 = new wxStaticBoxSizer(m_SpeedConditionsBox, wxVERTICAL);
    itemBoxSizer49->Add(itemStaticBoxSizer58, 0, wxGROW|wxALL, 5);
    wxBoxSizer* itemBoxSizer59 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer58->Add(itemBoxSizer59, 0, wxGROW, 5);
    wxArrayString m_SpeedConditionListStrings;
    m_SpeedConditionList = new wxListBox( m_SpeedPanel, ID_SPEED_CONDITION_DESC, wxDefaultPosition, wxDefaultSize, m_SpeedConditionListStrings, wxLB_SINGLE );
    itemBoxSizer59->Add(m_SpeedConditionList, 1, wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer61 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer59->Add(itemFlexGridSizer61, 0, wxGROW, 5);
    m_labSpeedCondDesc = new wxStaticText( m_SpeedPanel, wxID_ANY, _("Description"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer61->Add(m_labSpeedCondDesc, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SpeedCondDesc = new wxTextCtrl( m_SpeedPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer61->Add(m_SpeedCondDesc, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labSpeedCondType = new wxStaticText( m_SpeedPanel, wxID_ANY, _("Type"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer61->Add(m_labSpeedCondType, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxArrayString m_SpeedCondTypeStrings;
    m_SpeedCondType = new wxComboBox( m_SpeedPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_SpeedCondTypeStrings, wxCB_DROPDOWN );
    itemFlexGridSizer61->Add(m_SpeedCondType, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labSpeedCondClass = new wxStaticText( m_SpeedPanel, wxID_ANY, _("Class"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer61->Add(m_labSpeedCondClass, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_SpeedCondClass = new wxTextCtrl( m_SpeedPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer61->Add(m_SpeedCondClass, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labSpeedCondVariable = new wxStaticText( m_SpeedPanel, wxID_ANY, _("Variable"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer61->Add(m_labSpeedCondVariable, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxFlexGridSizer* itemFlexGridSizer69 = new wxFlexGridSizer(0, 5, 0, 0);
    itemFlexGridSizer61->Add(itemFlexGridSizer69, 0, wxGROW|wxALIGN_CENTER_VERTICAL, 5);
    wxArrayString m_SpeedCondVariableStrings;
    m_SpeedCondVariable = new wxComboBox( m_SpeedPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_SpeedCondVariableStrings, wxCB_DROPDOWN );
    itemFlexGridSizer69->Add(m_SpeedCondVariable, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    wxStaticText* itemStaticText71 = new wxStaticText( m_SpeedPanel, wxID_ANY, _("-"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer69->Add(itemStaticText71, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxBOTTOM, 5);

    m_SpeedCondVarSub = new wxTextCtrl( m_SpeedPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(60, -1), wxTE_CENTRE );
    itemFlexGridSizer69->Add(m_SpeedCondVarSub, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxRIGHT|wxBOTTOM, 5);

    m_SpeedCondValue = new wxTextCtrl( m_SpeedPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(60, -1), wxTE_LEFT );
    itemFlexGridSizer69->Add(m_SpeedCondValue, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labSpeedCondPercent = new wxStaticText( m_SpeedPanel, wxID_ANY, _("Percent"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer61->Add(m_labSpeedCondPercent, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_SpeedCondPercent = new wxSpinCtrl( m_SpeedPanel, wxID_ANY, _T("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 100, 0 );
    itemFlexGridSizer61->Add(m_SpeedCondPercent, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemFlexGridSizer61->AddGrowableCol(1);

    wxFlexGridSizer* itemFlexGridSizer76 = new wxFlexGridSizer(0, 5, 0, 0);
    itemStaticBoxSizer58->Add(itemFlexGridSizer76, 0, wxGROW, 5);
    m_SpeedCondAdd = new wxButton( m_SpeedPanel, ID_SPEEDCOND_ADD, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer76->Add(m_SpeedCondAdd, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SpeedCondDel = new wxButton( m_SpeedPanel, ID_SPEEDCOND_DEL, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer76->Add(m_SpeedCondDel, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SpeedCondModify = new wxButton( m_SpeedPanel, ID_SPEEDCOND_MODIFY, _("Modify"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer76->Add(m_SpeedCondModify, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SpeedCondImport = new wxButton( m_SpeedPanel, ID_SPEEDCOND_IMPORT, _("Import"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer76->Add(m_SpeedCondImport, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_SpeedCondImportFromStrings;
    m_SpeedCondImportFrom = new wxComboBox( m_SpeedPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_SpeedCondImportFromStrings, wxCB_DROPDOWN );
    itemFlexGridSizer76->Add(m_SpeedCondImportFrom, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxRIGHT|wxTOP|wxBOTTOM, 5);

    itemFlexGridSizer76->AddGrowableCol(4);

    m_Notebook->AddPage(m_SpeedPanel, _("Speed"));

    m_CommandPanel = new wxPanel( m_Notebook, ID_PANEL_ST_COMMANDS, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer83 = new wxBoxSizer(wxVERTICAL);
    m_CommandPanel->SetSizer(itemBoxSizer83);

    m_Commands2 = new wxListCtrl( m_CommandPanel, ID_LISTCTRL_COMMANDS, wxDefaultPosition, wxSize(100, 100), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES );
    itemBoxSizer83->Add(m_Commands2, 1, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer85 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer83->Add(itemBoxSizer85, 0, wxGROW|wxALL, 5);
    m_Delete = new wxButton( m_CommandPanel, ID_BUTTON_ST_DELETE, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer85->Add(m_Delete, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Modify = new wxButton( m_CommandPanel, ID_BUTTON_ST_MODIFY, _("Modify"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer85->Add(m_Modify, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CmdUp = new wxButton( m_CommandPanel, ID_ROUTE_CMD_UP, _("Up"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer85->Add(m_CmdUp, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CmdDown = new wxButton( m_CommandPanel, ID_ROUTE_CMD_DOWN, _("Down"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer85->Add(m_CmdDown, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer90 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer83->Add(itemFlexGridSizer90, 1, wxGROW|wxALL, 5);
    wxBoxSizer* itemBoxSizer91 = new wxBoxSizer(wxVERTICAL);
    itemFlexGridSizer90->Add(itemBoxSizer91, 1, wxGROW|wxALIGN_TOP|wxALL, 5);
    m_LabelSwitchId = new wxStaticText( m_CommandPanel, wxID_STATIC, _("turnoutID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer91->Add(m_LabelSwitchId, 0, wxALIGN_LEFT|wxALL, 5);

    wxArrayString m_SwitchIdStrings;
    m_SwitchId = new wxComboBox( m_CommandPanel, ID_COMBOBOX_ST_SWITCH_ID, wxEmptyString, wxDefaultPosition, wxSize(120, -1), m_SwitchIdStrings, wxCB_READONLY );
    itemBoxSizer91->Add(m_SwitchId, 0, wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer94 = new wxFlexGridSizer(1, 2, 0, 0);
    itemBoxSizer91->Add(itemFlexGridSizer94, 0, wxGROW|wxBOTTOM, 5);
    m_labTrackNumber = new wxStaticText( m_CommandPanel, wxID_ANY, _("Track number"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer94->Add(m_labTrackNumber, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_TrackNumber = new wxSpinCtrl( m_CommandPanel, wxID_ANY, _T("0"), wxDefaultPosition, wxSize(70, -1), wxSP_ARROW_KEYS, 0, 255, 0 );
    itemFlexGridSizer94->Add(m_TrackNumber, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Add = new wxButton( m_CommandPanel, ID_BUTTON_ST_ADD, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer91->Add(m_Add, 0, wxALIGN_LEFT|wxALL, 5);

    wxBoxSizer* itemBoxSizer98 = new wxBoxSizer(wxVERTICAL);
    itemFlexGridSizer90->Add(itemBoxSizer98, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_TOP, 5);
    wxArrayString m_SwitchCmdStrings;
    m_SwitchCmdStrings.Add(_("&straight"));
    m_SwitchCmdStrings.Add(_("&turnout(left)"));
    m_SwitchCmdStrings.Add(_("&right(3-way)"));
    m_SwitchCmdStrings.Add(_("&crossing"));
    m_SwitchCmdStrings.Add(_("&track"));
    m_SwitchCmdStrings.Add(_("&red"));
    m_SwitchCmdStrings.Add(_("&green"));
    m_SwitchCmdStrings.Add(_("&yellow"));
    m_SwitchCmdStrings.Add(_("&white"));
    m_SwitchCmdStrings.Add(_("&on"));
    m_SwitchCmdStrings.Add(_("&off"));
    m_SwitchCmdStrings.Add(_("&aspect"));
    m_SwitchCmd = new wxRadioBox( m_CommandPanel, ID_RADIOBOX_ST_SW_CMD, _("Command"), wxDefaultPosition, wxDefaultSize, m_SwitchCmdStrings, 2, wxRA_SPECIFY_COLS );
    m_SwitchCmd->SetSelection(0);
    itemBoxSizer98->Add(m_SwitchCmd, 0, wxALIGN_LEFT|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer100 = new wxFlexGridSizer(0, 3, 0, 0);
    itemBoxSizer98->Add(itemFlexGridSizer100, 0, wxALIGN_LEFT, 5);
    m_Lock = new wxCheckBox( m_CommandPanel, wxID_ANY, _("Lock"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Lock->SetValue(false);
    itemFlexGridSizer100->Add(m_Lock, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_SwReduceV = new wxCheckBox( m_CommandPanel, wxID_ANY, _("Reduce speed"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SwReduceV->SetValue(true);
    itemFlexGridSizer100->Add(m_SwReduceV, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_AtFree = new wxCheckBox( m_CommandPanel, wxID_ANY, _("At free"), wxDefaultPosition, wxDefaultSize, 0 );
    m_AtFree->SetValue(false);
    itemFlexGridSizer100->Add(m_AtFree, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemFlexGridSizer90->AddGrowableCol(0);

    m_Notebook->AddPage(m_CommandPanel, _("Turnouts"));

    m_SensorPanel = new wxPanel( m_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer105 = new wxBoxSizer(wxVERTICAL);
    m_SensorPanel->SetSizer(itemBoxSizer105);

    wxArrayString m_SensorListStrings;
    m_SensorList = new wxListBox( m_SensorPanel, ID_LIST_ROUTE_SENSORS, wxDefaultPosition, wxDefaultSize, m_SensorListStrings, wxLB_SINGLE|wxLB_ALWAYS_SB );
    itemBoxSizer105->Add(m_SensorList, 1, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer107 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer105->Add(itemBoxSizer107, 0, wxGROW|wxALL, 5);
    wxArrayString m_SensorComboStrings;
    m_SensorCombo = new wxComboBox( m_SensorPanel, ID_COMBOBOX_ROUTES_SENSORS, wxEmptyString, wxDefaultPosition, wxSize(140, -1), m_SensorComboStrings, wxCB_DROPDOWN );
    itemBoxSizer107->Add(m_SensorCombo, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxTOP|wxBOTTOM, 5);

    m_AddSensor = new wxButton( m_SensorPanel, ID_BUTTON_ROUTES_ADD_SENSOR, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer107->Add(m_AddSensor, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5);

    m_DelSensor = new wxButton( m_SensorPanel, ID_BUTTON_ROUTES_DEL_SENSOR, _("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer107->Add(m_DelSensor, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5);

    m_Notebook->AddPage(m_SensorPanel, _("Sensors"));

    m_PermissionsPanel = new wxPanel( m_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer112 = new wxBoxSizer(wxVERTICAL);
    m_PermissionsPanel->SetSizer(itemBoxSizer112);

    wxBoxSizer* itemBoxSizer113 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer112->Add(itemBoxSizer113, 1, wxGROW, 5);
    wxFlexGridSizer* itemFlexGridSizer114 = new wxFlexGridSizer(0, 1, 0, 0);
    itemBoxSizer113->Add(itemFlexGridSizer114, 1, wxGROW, 5);
    m_labLocoListPerm = new wxStaticText( m_PermissionsPanel, wxID_ANY, _("Locos"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer114->Add(m_labLocoListPerm, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxArrayString m_LocoListPermStrings;
    m_LocoListPerm = new wxListBox( m_PermissionsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_LocoListPermStrings, wxLB_SINGLE );
    itemFlexGridSizer114->Add(m_LocoListPerm, 0, wxGROW|wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer117 = new wxFlexGridSizer(0, 2, 0, 0);
    itemFlexGridSizer114->Add(itemFlexGridSizer117, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    m_AddInclude = new wxButton( m_PermissionsPanel, ID_ADD_INCLUDE, _("Include"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer117->Add(m_AddInclude, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_AddExclude = new wxButton( m_PermissionsPanel, ID_ADD_EXCLUDE, _("exclude"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer117->Add(m_AddExclude, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer114->AddGrowableRow(1);
    itemFlexGridSizer114->AddGrowableCol(0);

    wxFlexGridSizer* itemFlexGridSizer120 = new wxFlexGridSizer(0, 1, 0, 0);
    itemBoxSizer113->Add(itemFlexGridSizer120, 1, wxGROW, 5);
    m_labInclude = new wxStaticText( m_PermissionsPanel, wxID_ANY, _("Include"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer120->Add(m_labInclude, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxArrayString m_IncludeListStrings;
    m_IncludeList = new wxListBox( m_PermissionsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_IncludeListStrings, wxLB_SINGLE );
    itemFlexGridSizer120->Add(m_IncludeList, 0, wxGROW|wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer123 = new wxFlexGridSizer(0, 2, 0, 0);
    itemFlexGridSizer120->Add(itemFlexGridSizer123, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    m_RemoveInclude = new wxButton( m_PermissionsPanel, ID_REMOVE_INCLUDE, _("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer123->Add(m_RemoveInclude, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer120->AddGrowableRow(1);
    itemFlexGridSizer120->AddGrowableCol(0);

    wxFlexGridSizer* itemFlexGridSizer125 = new wxFlexGridSizer(0, 1, 0, 0);
    itemBoxSizer113->Add(itemFlexGridSizer125, 1, wxGROW, 5);
    m_labExclude = new wxStaticText( m_PermissionsPanel, wxID_ANY, _("Exclude"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer125->Add(m_labExclude, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxArrayString m_ExcludeListStrings;
    m_ExcludeList = new wxListBox( m_PermissionsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_ExcludeListStrings, wxLB_SINGLE );
    itemFlexGridSizer125->Add(m_ExcludeList, 0, wxGROW|wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer128 = new wxFlexGridSizer(0, 2, 0, 0);
    itemFlexGridSizer125->Add(itemFlexGridSizer128, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    m_RemoveExclude = new wxButton( m_PermissionsPanel, ID_REMOVE_EXCLUDE, _("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer128->Add(m_RemoveExclude, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer125->AddGrowableRow(1);
    itemFlexGridSizer125->AddGrowableCol(0);

    m_PermType = new wxStaticBox(m_PermissionsPanel, wxID_ANY, _("Type"));
    wxStaticBoxSizer* itemStaticBoxSizer130 = new wxStaticBoxSizer(m_PermType, wxVERTICAL);
    itemBoxSizer112->Add(itemStaticBoxSizer130, 0, wxGROW|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer131 = new wxFlexGridSizer(0, 6, 0, 0);
    itemStaticBoxSizer130->Add(itemFlexGridSizer131, 0, wxGROW, 5);
    m_PermTypeGoods = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("Goods"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypeGoods->SetValue(false);
    itemFlexGridSizer131->Add(m_PermTypeGoods, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_PermTypeMixed = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("Mixed"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypeMixed->SetValue(false);
    itemFlexGridSizer131->Add(m_PermTypeMixed, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_PermTypeICE = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("ICE"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypeICE->SetValue(false);
    itemFlexGridSizer131->Add(m_PermTypeICE, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_PermTypePerson = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("Person"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypePerson->SetValue(false);
    itemFlexGridSizer131->Add(m_PermTypePerson, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_PermTypeLightGoods = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("Light Goods"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypeLightGoods->SetValue(false);
    itemFlexGridSizer131->Add(m_PermTypeLightGoods, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_PermTypeNone = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("None"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypeNone->SetValue(false);
    itemFlexGridSizer131->Add(m_PermTypeNone, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_PermTypeLocal = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("Local"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypeLocal->SetValue(false);
    itemFlexGridSizer131->Add(m_PermTypeLocal, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_PermTypeCleaning = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("Cleaning"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypeCleaning->SetValue(false);
    itemFlexGridSizer131->Add(m_PermTypeCleaning, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_PermTypePost = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("Post"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypePost->SetValue(false);
    itemFlexGridSizer131->Add(m_PermTypePost, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_PermTypeLight = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("Light"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypeLight->SetValue(false);
    itemFlexGridSizer131->Add(m_PermTypeLight, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_PermTypeShunting = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("Shunting"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypeShunting->SetValue(false);
    itemFlexGridSizer131->Add(m_PermTypeShunting, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer143 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer112->Add(itemBoxSizer143, 0, wxALIGN_LEFT, 5);
    wxBoxSizer* itemBoxSizer144 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer143->Add(itemBoxSizer144, 0, wxALIGN_TOP, 5);
    wxFlexGridSizer* itemFlexGridSizer145 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer144->Add(itemFlexGridSizer145, 0, wxGROW|wxALL, 5);
    m_labMaxLen = new wxStaticText( m_PermissionsPanel, wxID_ANY, _("Max. train length"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer145->Add(m_labMaxLen, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_MaxLen = new wxSpinCtrl( m_PermissionsPanel, wxID_ANY, _T("0"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 0, 10000, 0 );
    itemFlexGridSizer145->Add(m_MaxLen, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labMinLen = new wxStaticText( m_PermissionsPanel, wxID_ANY, _("Min. train length"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer145->Add(m_labMinLen, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_MinLen = new wxSpinCtrl( m_PermissionsPanel, wxID_ANY, _T("0"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 0, 10000, 0 );
    itemFlexGridSizer145->Add(m_MinLen, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer145->AddGrowableCol(1);

    wxStaticLine* itemStaticLine150 = new wxStaticLine( m_PermissionsPanel, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    itemBoxSizer143->Add(itemStaticLine150, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer151 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer143->Add(itemBoxSizer151, 0, wxALIGN_TOP, 5);
    wxArrayString m_CommuterStrings;
    m_CommuterStrings.Add(_("&allow"));
    m_CommuterStrings.Add(_("&only"));
    m_CommuterStrings.Add(_("&disallow"));
    m_Commuter = new wxRadioBox( m_PermissionsPanel, wxID_ANY, _("Commuter train"), wxDefaultPosition, wxDefaultSize, m_CommuterStrings, 1, wxRA_SPECIFY_ROWS );
    m_Commuter->SetSelection(0);
    itemBoxSizer151->Add(m_Commuter, 0, wxALIGN_LEFT|wxALL, 5);

    wxArrayString m_PlacingStrings;
    m_PlacingStrings.Add(_("&Both"));
    m_PlacingStrings.Add(_("&Default"));
    m_PlacingStrings.Add(_("&Swapped"));
    m_Placing = new wxRadioBox( m_PermissionsPanel, wxID_ANY, _("Placing"), wxDefaultPosition, wxDefaultSize, m_PlacingStrings, 1, wxRA_SPECIFY_ROWS );
    m_Placing->SetSelection(0);
    itemBoxSizer151->Add(m_Placing, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxFlexGridSizer* itemFlexGridSizer154 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer112->Add(itemFlexGridSizer154, 0, wxGROW, 5);
    m_labClass = new wxStaticText( m_PermissionsPanel, wxID_ANY, _("Class"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer154->Add(m_labClass, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Class = new wxTextCtrl( m_PermissionsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer154->Add(m_Class, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer154->AddGrowableCol(1);

    m_Notebook->AddPage(m_PermissionsPanel, _("Persmissions"));

    m_ConditionsPanel = new wxPanel( m_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer158 = new wxBoxSizer(wxVERTICAL);
    m_ConditionsPanel->SetSizer(itemBoxSizer158);

    m_CondGrid = new wxGrid( m_ConditionsPanel, ID_COND_GRID, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxHSCROLL|wxVSCROLL );
    m_CondGrid->SetDefaultColSize(50);
    m_CondGrid->SetDefaultRowSize(25);
    m_CondGrid->SetColLabelSize(25);
    m_CondGrid->SetRowLabelSize(0);
    m_CondGrid->CreateGrid(1, 6, wxGrid::wxGridSelectCells);
    itemBoxSizer158->Add(m_CondGrid, 1, wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer160 = new wxFlexGridSizer(0, 3, 0, 0);
    itemBoxSizer158->Add(itemFlexGridSizer160, 0, wxGROW|wxALL, 5);
    m_CondNotFromBlock = new wxCheckBox( m_ConditionsPanel, wxID_ANY, _("Not from"), wxDefaultPosition, wxDefaultSize, 0 );
    m_CondNotFromBlock->SetValue(false);
    itemFlexGridSizer160->Add(m_CondNotFromBlock, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM, 5);

    wxArrayString m_CondFromBlockStrings;
    m_CondFromBlock = new wxComboBox( m_ConditionsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(160, -1), m_CondFromBlockStrings, wxCB_DROPDOWN );
    itemFlexGridSizer160->Add(m_CondFromBlock, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_CondTypeStrings;
    m_CondType = new wxComboBox( m_ConditionsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(120, -1), m_CondTypeStrings, wxCB_DROPDOWN );
    itemFlexGridSizer160->Add(m_CondType, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CondCommuter = new wxCheckBox( m_ConditionsPanel, wxID_ANY, _("Commuter"), wxDefaultPosition, wxDefaultSize, 0 );
    m_CondCommuter->SetValue(false);
    itemFlexGridSizer160->Add(m_CondCommuter, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CondChangeDir = new wxCheckBox( m_ConditionsPanel, wxID_ANY, _("Change dir"), wxDefaultPosition, wxDefaultSize, 0 );
    m_CondChangeDir->SetValue(false);
    itemFlexGridSizer160->Add(m_CondChangeDir, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CondAllowSchedules = new wxCheckBox( m_ConditionsPanel, wxID_ANY, _("Allow schedules"), wxDefaultPosition, wxDefaultSize, 0 );
    m_CondAllowSchedules->SetValue(true);
    itemFlexGridSizer160->Add(m_CondAllowSchedules, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer167 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer158->Add(itemBoxSizer167, 0, wxGROW|wxALL, 5);
    m_CondAdd = new wxButton( m_ConditionsPanel, ID_ROUTE_CONDITION_ADD, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer167->Add(m_CondAdd, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CondModify = new wxButton( m_ConditionsPanel, ID_ROUTE_CONDITION_MODIFY, _("Modify"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer167->Add(m_CondModify, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CondDelete = new wxButton( m_ConditionsPanel, ID_ROUTE_CONDITION_DEL, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer167->Add(m_CondDelete, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Notebook->AddPage(m_ConditionsPanel, _("Conditions"));

    m_LocationPanel = new wxPanel( m_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer172 = new wxBoxSizer(wxHORIZONTAL);
    m_LocationPanel->SetSizer(itemBoxSizer172);

    wxFlexGridSizer* itemFlexGridSizer173 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer172->Add(itemFlexGridSizer173, 0, wxALIGN_TOP|wxALL, 5);
    m_LabelX = new wxStaticText( m_LocationPanel, wxID_ANY, _("x"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer173->Add(m_LabelX, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_x = new wxTextCtrl( m_LocationPanel, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer173->Add(m_x, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelY = new wxStaticText( m_LocationPanel, wxID_ANY, _("y"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer173->Add(m_LabelY, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_y = new wxTextCtrl( m_LocationPanel, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer173->Add(m_y, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelZ = new wxStaticText( m_LocationPanel, wxID_ANY, _("z"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer173->Add(m_LabelZ, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_z = new wxTextCtrl( m_LocationPanel, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer173->Add(m_z, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_oriStrings;
    m_oriStrings.Add(_("&north"));
    m_oriStrings.Add(_("&east"));
    m_oriStrings.Add(_("&south"));
    m_oriStrings.Add(_("&west"));
    m_ori = new wxRadioBox( m_LocationPanel, wxID_ANY, _("Orientation"), wxDefaultPosition, wxDefaultSize, m_oriStrings, 1, wxRA_SPECIFY_COLS );
    m_ori->SetSelection(0);
    itemBoxSizer172->Add(m_ori, 0, wxALIGN_TOP|wxALL, 5);

    m_Notebook->AddPage(m_LocationPanel, _("Location"));

    m_WiringPanel = new wxPanel( m_Notebook, ID_ROUTE_WIRING, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer182 = new wxBoxSizer(wxVERTICAL);
    m_WiringPanel->SetSizer(itemBoxSizer182);

    m_CTCBox = new wxStaticBox(m_WiringPanel, wxID_ANY, _("CTC"));
    wxStaticBoxSizer* itemStaticBoxSizer183 = new wxStaticBoxSizer(m_CTCBox, wxVERTICAL);
    itemBoxSizer182->Add(itemStaticBoxSizer183, 0, wxGROW|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer184 = new wxFlexGridSizer(0, 5, 0, 0);
    itemStaticBoxSizer183->Add(itemFlexGridSizer184, 0, wxGROW|wxALL, 5);
    m_labCTCbutton = new wxStaticText( m_WiringPanel, wxID_ANY, _("Button"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer184->Add(m_labCTCbutton, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labCTCIID = new wxStaticText( m_WiringPanel, wxID_ANY, _("IID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer184->Add(m_labCTCIID, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labCTCBus = new wxStaticText( m_WiringPanel, wxID_ANY, _("Bus"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer184->Add(m_labCTCBus, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labCTCAddr = new wxStaticText( m_WiringPanel, wxID_ANY, _("Address"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer184->Add(m_labCTCAddr, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labOutput = new wxStaticText( m_WiringPanel, wxID_ANY, _("Output"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer184->Add(m_labOutput, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labCTCButton1 = new wxStaticText( m_WiringPanel, wxID_STATIC, _("1"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer184->Add(m_labCTCButton1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CTCIID1 = new wxTextCtrl( m_WiringPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer184->Add(m_CTCIID1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CTCBus1 = new wxTextCtrl( m_WiringPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer184->Add(m_CTCBus1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CTCAddr1 = new wxSpinCtrl( m_WiringPanel, wxID_ANY, _T("0"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 0, 10000, 0 );
    itemFlexGridSizer184->Add(m_CTCAddr1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_Output1Strings;
    m_Output1 = new wxComboBox( m_WiringPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Output1Strings, wxCB_DROPDOWN );
    itemFlexGridSizer184->Add(m_Output1, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labCTCButton2 = new wxStaticText( m_WiringPanel, wxID_ANY, _("2"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer184->Add(m_labCTCButton2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CTCIID2 = new wxTextCtrl( m_WiringPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer184->Add(m_CTCIID2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CTCBus2 = new wxTextCtrl( m_WiringPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer184->Add(m_CTCBus2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CTCAddr2 = new wxSpinCtrl( m_WiringPanel, wxID_ANY, _T("0"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 0, 10000, 0 );
    itemFlexGridSizer184->Add(m_CTCAddr2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_Output2Strings;
    m_Output2 = new wxComboBox( m_WiringPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Output2Strings, wxCB_DROPDOWN );
    itemFlexGridSizer184->Add(m_Output2, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labCTCButton3 = new wxStaticText( m_WiringPanel, wxID_ANY, _("3"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer184->Add(m_labCTCButton3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CTCIID3 = new wxTextCtrl( m_WiringPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer184->Add(m_CTCIID3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CTCBus3 = new wxTextCtrl( m_WiringPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer184->Add(m_CTCBus3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CTCAddr3 = new wxSpinCtrl( m_WiringPanel, wxID_ANY, _T("0"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 0, 10000, 0 );
    itemFlexGridSizer184->Add(m_CTCAddr3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_Output3Strings;
    m_Output3 = new wxComboBox( m_WiringPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_Output3Strings, wxCB_DROPDOWN );
    itemFlexGridSizer184->Add(m_Output3, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer184->AddGrowableCol(0);

    m_Notebook->AddPage(m_WiringPanel, _("Wiring"));

    itemBoxSizer2->Add(m_Notebook, 1, wxGROW|wxALL, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer205 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer205, 0, wxGROW|wxALL, 5);
    m_Cancel = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer205->AddButton(m_Cancel);

    m_OK = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    m_OK->SetDefault();
    itemStdDialogButtonSizer205->AddButton(m_OK);

    m_Apply = new wxButton( itemDialog1, wxID_APPLY, _("&Apply"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer205->AddButton(m_Apply);

    m_Help = new wxButton( itemDialog1, wxID_HELP, _("&Help"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer205->AddButton(m_Help);

    itemStdDialogButtonSizer205->Realize();

////@end RouteDialog content construction
}

/*!
 * Should we show tooltips?
 */

bool RouteDialog::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap RouteDialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin RouteDialog bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end RouteDialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon RouteDialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin RouteDialog icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end RouteDialog icon retrieval
}


void RouteDialog::setSwCmd( iONode swcmd ) {
  int dir = m_SwitchCmd->GetSelection();
  switch( dir ) {
    case 0:
      wSwitchCmd.setcmd( swcmd, wSwitch.straight );
      break;
    case 1:
      wSwitchCmd.setcmd( swcmd, wSwitch.turnout );
      break;
    case 2:
      wSwitchCmd.setcmd( swcmd, wSwitch.left );
      break;
    case 3:
      wSwitchCmd.setcmd( swcmd, wSwitch.right );
      break;
    case 4:
      wSwitchCmd.setcmd( swcmd, wSwitchCmd.cmd_track );
      wSwitchCmd.settrack( swcmd, m_TrackNumber->GetValue() );
      break;
    case 5:
        wSwitchCmd.setcmd( swcmd, wSignal.red );
        break;
    case 6:
        wSwitchCmd.setcmd( swcmd, wSignal.green );
        break;
    case 7:
        wSwitchCmd.setcmd( swcmd, wSignal.yellow );
        break;
    case 8:
        wSwitchCmd.setcmd( swcmd, wSignal.white );
        break;
    case 9:
        wSwitchCmd.setcmd( swcmd, wOutput.on );
        break;
    case 10:
        wSwitchCmd.setcmd( swcmd, wOutput.off );
        break;
    case 11:
      wSwitchCmd.setcmd( swcmd, wSignal.aspect );
      wSwitchCmd.settrack( swcmd, m_TrackNumber->GetValue() );
      break;
    }

  wSwitchCmd.setlock( swcmd, m_Lock->IsChecked() ? True:False );
  wSwitchCmd.setreduceV( swcmd, m_SwReduceV->IsChecked() ? True:False );
  wSwitchCmd.setatfree( swcmd, m_AtFree->IsChecked() ? True:False );
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_ST_ADD
 */

void RouteDialog::OnButtonTurnoutAddClick( wxCommandEvent& event )
{
  iONode swcmd = NodeOp.inst( wSwitchCmd.name(), m_Props, ELEMENT_NODE );

  wSwitchCmd.setid(swcmd, m_SwitchId->GetStringSelection().mb_str(wxConvUTF8) );

  setSwCmd(swcmd);

  NodeOp.addChild( m_Props, swcmd );

  initCommands();
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_ST_DELETE
 */

void RouteDialog::OnButtonTurnoutDeleteClick( wxCommandEvent& event )
{
  if( m_SwCmd != NULL ) {
    NodeOp.removeChild( m_Props, m_SwCmd );
    initCommands();
  }
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void RouteDialog::OnCancelClick( wxCommandEvent& event )
{
  EndModal( 0 );
}

/*!
 * wxEVT_COMMAND_LISTBOX_SELECTED event handler for ID_LISTBOX_COMMANDS
 */

void RouteDialog::CommandsSelected( iONode swcmd )
{
  m_TrackNumber->Enable(false);
  if( swcmd != NULL ) {
    m_SwitchId->SetStringSelection( wxString(wSwitchCmd.getid(swcmd),wxConvUTF8));
    int dir = 0;
    if( StrOp.equals( wSwitch.straight, wSwitchCmd.getcmd(swcmd) ) )
      dir = 0;
    else if( StrOp.equals( wSwitch.turnout, wSwitchCmd.getcmd(swcmd) ) )
      dir = 1;
    else if( StrOp.equals( wSwitch.left, wSwitchCmd.getcmd(swcmd) ) )
      dir = 2;
    else if( StrOp.equals( wSwitch.right, wSwitchCmd.getcmd(swcmd) ) )
      dir = 3;
    else if( StrOp.equals( wSwitchCmd.cmd_track, wSwitchCmd.getcmd(swcmd) ) ) {
      dir = 4;
      m_TrackNumber->SetValue(wSwitchCmd.gettrack(swcmd));
      m_TrackNumber->Enable(true);
    }
    else if( StrOp.equals( wSignal.red, wSwitchCmd.getcmd(swcmd) ) )
      dir = 5;
    else if( StrOp.equals( wSignal.green, wSwitchCmd.getcmd(swcmd) ) )
      dir = 6;
    else if( StrOp.equals( wSignal.yellow, wSwitchCmd.getcmd(swcmd) ) )
      dir = 7;
    else if( StrOp.equals( wSignal.white, wSwitchCmd.getcmd(swcmd) ) )
      dir = 8;
    else if( StrOp.equals( wOutput.on, wSwitchCmd.getcmd(swcmd) ) )
      dir = 9;
    else if( StrOp.equals( wOutput.off, wSwitchCmd.getcmd(swcmd) ) )
      dir = 10;
    else if( StrOp.equals( wSignal.aspect, wSwitchCmd.getcmd(swcmd) ) ) {
      dir = 11;
      m_TrackNumber->SetValue(wSwitchCmd.gettrack(swcmd));
      m_TrackNumber->Enable(true);
    }
    m_SwitchCmd->SetSelection(dir);

    m_Lock->Enable(true);
    m_AtFree->Enable(true);
    m_Lock->SetValue(wSwitchCmd.islock( swcmd )?true:false);
    m_AtFree->SetValue(wSwitchCmd.isatfree( swcmd )?true:false);
    m_SwReduceV->Enable(true);
    m_SwReduceV->SetValue(wSwitchCmd.isreduceV( swcmd )?true:false);

    m_SwitchCmd->Enable( 0, false );
    m_SwitchCmd->Enable( 1, false );
    m_SwitchCmd->Enable( 2, false );
    m_SwitchCmd->Enable( 3, false );
    m_SwitchCmd->Enable( 4, false );
    m_SwitchCmd->Enable( 5, false );
    m_SwitchCmd->Enable( 6, false );
    m_SwitchCmd->Enable( 7, false );
    m_SwitchCmd->Enable( 8, false );
    m_SwitchCmd->Enable( 9, false );
    m_SwitchCmd->Enable( 10, false );
    m_SwitchCmd->Enable( 11, false );

    int swidx = m_SwitchId->FindString( wxString(wSwitchCmd.getid(swcmd),wxConvUTF8) );
    if( swidx != wxNOT_FOUND ) {
      iONode sw = (iONode)((wxItemContainer*)m_SwitchId)->GetClientData( swidx );
      if( StrOp.equals( wSwitch.threeway, wSwitch.gettype( sw ) ) ) {
        m_SwitchCmd->Enable( 0, true );
        m_SwitchCmd->Enable( 2, true );
        m_SwitchCmd->Enable( 3, true );
      }
      else if( StrOp.equals( wSwitch.dcrossing, wSwitch.gettype( sw ) ) ) {
        m_SwitchCmd->Enable( 0, true );
        m_SwitchCmd->Enable( 1, true );
        m_SwitchCmd->Enable( 2, true );
        m_SwitchCmd->Enable( 3, true );
      }
      else if( StrOp.equals( wTurntable.name(), NodeOp.getName( sw ) ) ||
               StrOp.equals( wSelTab.name(), NodeOp.getName( sw ) ) ) {
        m_SwitchCmd->Enable( 4, true );
        m_Lock->Enable(false);
        m_Lock->SetValue(false);
        m_SwReduceV->Enable(false);
        m_SwReduceV->SetValue(false);
      }
      else if( StrOp.equals( wSignal.name(), NodeOp.getName( sw ) ) ) {
        m_SwitchCmd->Enable( 5, true );
        m_SwitchCmd->Enable( 6, true );
        m_SwitchCmd->Enable( 7, true );
        m_SwitchCmd->Enable( 8, true );
        m_SwitchCmd->Enable( 11, true );
        m_Lock->Enable(false);
        m_Lock->SetValue(false);
        m_SwReduceV->Enable(false);
        m_SwReduceV->SetValue(false);
      }
      else if( StrOp.equals( wOutput.name(), NodeOp.getName( sw ) ) ) {
        m_SwitchCmd->Enable( 9, true );
        m_SwitchCmd->Enable( 10, true );
        m_Lock->Enable(false);
        m_Lock->SetValue(false);
        m_SwReduceV->Enable(false);
        m_SwReduceV->SetValue(false);
      }
      else {
        m_SwitchCmd->Enable( 0, true );
        m_SwitchCmd->Enable( 1, true );
      }
    }

    m_Delete->Enable( true );
    m_Modify->Enable( true );

  }
  else {
    m_SwitchId->SetSelection(0);
  }
}


void RouteDialog::OnOkClick( wxCommandEvent& event )
{
  if( m_bStandalone ) {
    if( !evaluate() )
      return;
  }
  else {
    OnApplyClick(event);
  }
  EndModal( wxID_OK );
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_FB_NEW
 */

void RouteDialog::OnButtonStNewClick( wxCommandEvent& event )
{
  int i = findID("NEW");
  if( i == wxNOT_FOUND ) {
    iONode model = wxGetApp().getModel();
    if( model != NULL ) {
      iONode stlist = wPlan.getstlist( model );
      if( stlist == NULL ) {
        stlist = NodeOp.inst( wRouteList.name(), model, ELEMENT_NODE );
        NodeOp.addChild( model, stlist );
      }

      if( stlist != NULL ) {
        iONode st = NodeOp.inst( wRoute.name(), stlist, ELEMENT_NODE );
        NodeOp.addChild( stlist, st );
        wRoute.setid( st, "NEW" );
        appendItem(st);
        setIDSelection(wItem.getid(st));
        m_Props = st;
        initValues();
      }
    }
  }
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_FB_DELETE
 */

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_ST_DELETE_ROUTE
 */

void RouteDialog::OnButtonStDeleteRouteClick( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

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
    iONode stlist = wPlan.getstlist( model );
    if( stlist != NULL ) {
      NodeOp.removeChild( stlist, m_Props );
      m_Props = selectPrev();
    }
  }

  initIndex();
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_APPLY
 */

void RouteDialog::OnApplyClick( wxCommandEvent& event )
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
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_ST_MODIFY
 */

void RouteDialog::OnButtonTurnoutModifyClick( wxCommandEvent& event )
{
  iONode swcmd = m_SwCmd;
  if( swcmd != NULL ) {
    wSwitchCmd.setid(swcmd, m_SwitchId->GetStringSelection().mb_str(wxConvUTF8) );
    wSwitchCmd.setlock( swcmd, m_Lock->IsChecked() ? True:False );
    wSwitchCmd.setreduceV( swcmd, m_SwReduceV->IsChecked() ? True:False );
    wSwitchCmd.setatfree( swcmd, m_AtFree->IsChecked() ? True:False );

    setSwCmd(swcmd);

    initCommands();
  }
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_ST_TEST
 */

void RouteDialog::OnButtonStTestClick( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  iONode cmd = NodeOp.inst( wRoute.name(), NULL, ELEMENT_NODE );
  wRoute.setcmd( cmd, wRoute.test );
  wRoute.setid( cmd, wRoute.getid( m_Props ) );
  wRoute.setstatus( cmd, wRoute.status_free);
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}



/*!
 * wxEVT_COMMAND_COMBOBOX_SELECTED event handler for ID_COMBOBOX_ST_SWITCH_ID
 */

void RouteDialog::OnComboboxStSwitchIdSelected( wxCommandEvent& event )
{
  int swidx = m_SwitchId->GetSelection();
  if( swidx != wxNOT_FOUND ) {
    iONode sw = (iONode)((wxItemContainer*)m_SwitchId)->GetClientData( swidx );
    if( sw == NULL ) {
      m_Add->Enable( false );
      return;
    }
    m_Lock->Enable(true);
    m_AtFree->Enable(true);
    m_SwReduceV->Enable(true);
    m_Add->Enable( true );
    m_SwitchCmd->SetSelection(0);
    m_SwitchCmd->Enable( 0, false );
    m_SwitchCmd->Enable( 1, false );
    m_SwitchCmd->Enable( 2, false );
    m_SwitchCmd->Enable( 3, false );
    m_SwitchCmd->Enable( 4, false );
    m_SwitchCmd->Enable( 5, false );
    m_SwitchCmd->Enable( 6, false );
    m_SwitchCmd->Enable( 7, false );
    m_SwitchCmd->Enable( 8, false );
    m_SwitchCmd->Enable( 9, false );
    m_SwitchCmd->Enable( 10, false );
    m_SwitchCmd->Enable( 11, false );
    m_TrackNumber->Enable(false);
    if( StrOp.equals( wTurntable.name(), NodeOp.getName( sw ) ) ||
        StrOp.equals( wSelTab.name(), NodeOp.getName( sw ) )) {
      m_SwitchCmd->Enable( 4, true );
      m_SwitchCmd->SetSelection(4);
      m_TrackNumber->Enable(true);
    }
    else if( StrOp.equals( wSignal.name(), NodeOp.getName( sw ) ) ) {
      m_SwitchCmd->Enable( 5, true );
      m_SwitchCmd->Enable( 6, true );
      m_SwitchCmd->Enable( 7, true );
      m_SwitchCmd->Enable( 8, true );
      m_SwitchCmd->Enable( 11, true );
      m_SwitchCmd->SetSelection(5);
      m_Lock->Enable(false);
      m_Lock->SetValue(false);
      m_TrackNumber->Enable(true);
    }
    else if( StrOp.equals( wOutput.name(), NodeOp.getName( sw ) ) ) {
      m_SwitchCmd->Enable( 9, true );
      m_SwitchCmd->Enable( 10, true );
      m_SwitchCmd->SetSelection(9);
      m_Lock->Enable(false);
      m_Lock->SetValue(false);
    }
    else if( StrOp.equals( wSwitch.threeway, wSwitch.gettype( sw ) ) ) {
      m_SwitchCmd->Enable( 0, true );
      m_SwitchCmd->Enable( 1, true );
      m_SwitchCmd->Enable( 2, true );
    }
    else if( StrOp.equals( wSwitch.dcrossing, wSwitch.gettype( sw ) ) ) {
      m_SwitchCmd->Enable( 0, true );
      m_SwitchCmd->Enable( 1, true );
      m_SwitchCmd->Enable( 2, true );
      m_SwitchCmd->Enable( 3, true );
    }
    else {
      m_SwitchCmd->Enable( 0, true );
      m_SwitchCmd->Enable( 1, true );
    }

  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_ST_DOC
 */

void RouteDialog::OnButtonStDocClick( wxCommandEvent& event )
{
  doDoc( event, "streets");
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_ROUTES_ADD_SENSOR
 */

void RouteDialog::OnButtonRoutesAddSensorClick( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  iONode fb = wRoute.getfbevent( m_Props );
  while( fb != NULL ) {
    if( StrOp.equals( wFeedbackEvent.getid(fb), m_SensorCombo->GetStringSelection().mb_str(wxConvUTF8) ) ) {
      // allready in list...
      return;
    }

    fb = wRoute.nextfbevent( m_Props, fb );
  };
  m_SensorList->Append( m_SensorCombo->GetStringSelection() );
  iONode fbevent = NodeOp.inst( wFeedbackEvent.name(), m_Props, ELEMENT_NODE );
  wFeedbackEvent.setid( fbevent, m_SensorCombo->GetStringSelection().mb_str(wxConvUTF8) );
  NodeOp.addChild( m_Props, fbevent );
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_ROUTES_DEL_SENSOR
 */

void RouteDialog::OnButtonRoutesDelSensorClick( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  iONode fb = wRoute.getfbevent( m_Props );
  while( fb != NULL ) {
    if( StrOp.equals( wFeedbackEvent.getid(fb), m_SensorList->GetStringSelection().mb_str(wxConvUTF8) ) ) {
      // in list...
      break;
    }

    fb = wRoute.nextfbevent( m_Props, fb );
  };

  if( fb != NULL ) {
    NodeOp.removeChild( m_Props, fb );
  }

  m_SensorList->Delete( m_SensorList->GetSelection() );
}


/*!
 * wxEVT_COMMAND_LISTBOX_SELECTED event handler for ID_LIST_ROUTE_SENSORS
 */

void RouteDialog::OnListRouteSensorsSelected( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_LISTBOX_SELECTED event handler for ID_LIST_ROUTE_SENSORS in RouteDialog.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_LISTBOX_SELECTED event handler for ID_LIST_ROUTE_SENSORS in RouteDialog.
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ROUTE_ACTIONS
 */

void RouteDialog::OnRouteActionsClick( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  ActionsCtrlDlg*  dlg = new ActionsCtrlDlg(this, m_Props, "go,lock,unlock" );

  if( wxID_OK == dlg->ShowModal() ) {
    // TODO: inform
  }

  dlg->Destroy();
}


/*!
 * wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_ROUTE_VELOCITY
 */

void RouteDialog::OnRouteVelocitySelected( wxCommandEvent& event )
{
  if( m_Speed->GetSelection() == 5 ) {
    // V_%
    m_ReduceV->SetValue(false);
    m_ReduceV->Enable(false);
  }
  else {
    m_ReduceV->Enable(true);
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ROUTE_CONDITION_ADD
 */

void RouteDialog::OnRouteConditionAddClick( wxCommandEvent& event )
{
  iONode cond = NodeOp.inst(wRouteCondition.name(), m_Props, ELEMENT_NODE);
  wRouteCondition.setnotprevbk(cond, m_CondNotFromBlock->IsChecked() ?True:False);
  wRouteCondition.setprevbkid(cond, m_CondFromBlock->GetStringSelection().mb_str(wxConvUTF8));
  int typesel = m_CondType->GetSelection();

  switch(typesel) {
  case 0: wRouteCondition.settype(cond, wLoc.cargo_all); break;
  case 1: wRouteCondition.settype(cond, wLoc.cargo_none); break;
  case 2: wRouteCondition.settype(cond, wLoc.cargo_goods); break;
  case 3: wRouteCondition.settype(cond, wLoc.cargo_regional); break;
  case 4: wRouteCondition.settype(cond, wLoc.cargo_mixed); break;
  case 5: wRouteCondition.settype(cond, wLoc.cargo_cleaning); break;
  case 6: wRouteCondition.settype(cond, wLoc.cargo_ice); break;
  case 7: wRouteCondition.settype(cond, wLoc.cargo_post); break;
  case 8: wRouteCondition.settype(cond, wLoc.cargo_person); break;
  case 9: wRouteCondition.settype(cond, wLoc.cargo_light); break;
  case 10: wRouteCondition.settype(cond, wLoc.cargo_lightgoods); break;
  }

  wRouteCondition.setcommuter(cond, m_CondCommuter->IsChecked() ? True:False);
  wRouteCondition.setchdir(cond, m_CondChangeDir->IsChecked() ? True:False);
  wRouteCondition.setallowschedules(cond, m_CondAllowSchedules->IsChecked() ? True:False);
  NodeOp.addChild( m_Props, cond);

  initCondList();
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ROUTE_CONDITION_MODIFY
 */

void RouteDialog::OnRouteConditionModifyClick( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  int idx = 0;
  iONode cond = wRoute.getstcondition( m_Props );
  while( cond != NULL ) {
    if( m_CondNr == idx )
      break;
    idx++;
    cond = wRoute.nextstcondition( m_Props, cond );
  }

  if( cond != NULL ) {
    wRouteCondition.setnotprevbk(cond, m_CondNotFromBlock->IsChecked() ?True:False);
    wRouteCondition.setprevbkid(cond, m_CondFromBlock->GetStringSelection().mb_str(wxConvUTF8));
    int typesel = m_CondType->GetSelection();
    switch(typesel) {
    case 0: wRouteCondition.settype(cond, wLoc.cargo_all); break;
    case 1: wRouteCondition.settype(cond, wLoc.cargo_none); break;
    case 2: wRouteCondition.settype(cond, wLoc.cargo_goods); break;
    case 3: wRouteCondition.settype(cond, wLoc.cargo_regional); break;
    case 4: wRouteCondition.settype(cond, wLoc.cargo_mixed); break;
    case 5: wRouteCondition.settype(cond, wLoc.cargo_cleaning); break;
    case 6: wRouteCondition.settype(cond, wLoc.cargo_ice); break;
    case 7: wRouteCondition.settype(cond, wLoc.cargo_post); break;
    case 8: wRouteCondition.settype(cond, wLoc.cargo_person); break;
    case 9: wRouteCondition.settype(cond, wLoc.cargo_light); break;
    case 10: wRouteCondition.settype(cond, wLoc.cargo_lightgoods); break;
    }
    wRouteCondition.setcommuter(cond, m_CondCommuter->IsChecked() ? True:False);
    wRouteCondition.setchdir(cond, m_CondChangeDir->IsChecked() ? True:False);
    wRouteCondition.setallowschedules(cond, m_CondAllowSchedules->IsChecked() ? True:False);
    initCondList();
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ROUTE_CONDITION_DEL
 */

void RouteDialog::OnRouteConditionDelClick( wxCommandEvent& event )
{
  int idx = 0;
  iONode cond = wRoute.getstcondition( m_Props );
  while( cond != NULL ) {
    if( m_CondNr == idx )
      break;
    idx++;
    cond = wRoute.nextstcondition( m_Props, cond );
  }

  if( cond != NULL ) {
    NodeOp.removeChild( m_Props, cond );
    NodeOp.base.del( cond );
    initCondList();
  }

}


/*!
 * wxEVT_GRID_CELL_LEFT_CLICK event handler for ID_COND_GRID
 */

void RouteDialog::OnCondCellLeftClick( wxGridEvent& event )
{
  m_CondGrid->SelectRow(event.GetRow());
  m_CondDelete->Enable( true );
  m_CondModify->Enable( true );

  wxString str = m_CondGrid->GetCellValue( event.GetRow(), 0 );
  m_CondNr = event.GetRow();


  int idx = 0;
  iONode cond = wRoute.getstcondition( m_Props );
  while( cond != NULL ) {
    if( m_CondNr == idx )
      break;
    idx++;
    cond = wRoute.nextstcondition( m_Props, cond );
  }

  if( cond != NULL ) {
    m_CondNotFromBlock->SetValue(wRouteCondition.isnotprevbk(cond) ?true:false);
    m_CondFromBlock->SetValue( wxString(wRouteCondition.getprevbkid(cond),wxConvUTF8));
    m_CondType->SetStringSelection( wxGetApp().getMsg(wRouteCondition.gettype(cond)));

    m_CondCommuter->SetValue(wRouteCondition.iscommuter(cond) ?true:false);
    m_CondChangeDir->SetValue(wRouteCondition.ischdir(cond) ?true:false);
    m_CondAllowSchedules->SetValue(wRouteCondition.isallowschedules(cond) ?true:false);
  }

}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_ST_COPY
 */

void RouteDialog::OnButtonStCopyClick( wxCommandEvent& event )
{
  if( m_Props != NULL ) {
    iONode model = wxGetApp().getModel();
    if( model != NULL ) {
      iONode stlist = wPlan.getstlist( model );
      if( stlist == NULL ) {
        stlist = NodeOp.inst( wRouteList.name(), model, ELEMENT_NODE );
        NodeOp.addChild( model, stlist );
      }

      if( stlist != NULL ) {
        iONode stcopy = (iONode)NodeOp.base.clone( m_Props );
        char* id = StrOp.fmt( "%s (copy)", wRoute.getid(stcopy));
        wRoute.setid(stcopy, id);
        StrOp.free(id);
        NodeOp.addChild( stlist, stcopy );
        initIndex();
      }

    }
  }
}


/*!
 * wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ID_LISTCTRLINDEX_ST
 */

void RouteDialog::OnListctrlindexStSelected( wxListEvent& event )
{
  m_Props = getSelection(event.GetIndex());
  initValues();
  m_Delete->Enable( true );
}


/*!
 * wxEVT_COMMAND_LIST_COL_CLICK event handler for ID_LISTCTRLINDEX_ST
 */

void RouteDialog::OnListctrlindexStColLeftClick( wxListEvent& event )
{
  sortOnColumn(event.GetColumn());
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_RESET_ROUTE
 */

void RouteDialog::OnResetRouteClick( wxCommandEvent& event ) {
  if( m_Props == NULL )
    return;

  iONode cmd = NodeOp.inst( wRoute.name(), NULL, ELEMENT_NODE );
  wRoute.setcmd( cmd, wSwitch.unlock );
  wRoute.setid( cmd, wRoute.getid( m_Props ) );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
 */

void RouteDialog::OnHelpClick( wxCommandEvent& event )
{
  switch( m_Notebook->GetSelection() ) {
  case 0: wxGetApp().openLink( "route-index" ); break;
  case 1: wxGetApp().openLink( "route-gen" ); break;
  case 2: wxGetApp().openLink( "route-speed" ); break;
  case 3: wxGetApp().openLink( "route-turnouts" ); break;
  case 4: wxGetApp().openLink( "route-sensors" ); break;
  case 5: wxGetApp().openLink( "route-perm" ); break;
  case 6: wxGetApp().openLink( "route-cond" ); break;
  case 7: wxGetApp().openLink( "route" ); break; // Position
  case 8: wxGetApp().openLink( "route-wiring" ); break;
  default: wxGetApp().openLink( "route-index" ); break;
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ADD_EXCLUDE
 */

void RouteDialog::OnAddExcludeClick( wxCommandEvent& event )
{
  wxString id = m_LocoListPerm->GetStringSelection();
  if( m_ExcludeList->FindString(id) == wxNOT_FOUND ) {
    iONode excl = NodeOp.inst( wPermExclude.name(), m_Props, ELEMENT_NODE );
    wPermExclude.setid( excl, id.mb_str(wxConvUTF8) );
    NodeOp.addChild( m_Props, excl );
    m_ExcludeList->Append(id);
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_REMOVE_INCLUDE
 */

void RouteDialog::OnRemoveIncludeClick( wxCommandEvent& event )
{
  if( m_IncludeList->GetSelection() != wxNOT_FOUND ) {
    iONode incl = (iONode)m_IncludeList->GetClientData(m_IncludeList->GetSelection());
    NodeOp.removeChild( m_Props, incl );
    NodeOp.base.del(incl);
    m_IncludeList->Delete(m_IncludeList->GetSelection());
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_REMOVE_EXCLUDE
 */

void RouteDialog::OnRemoveExcludeClick( wxCommandEvent& event )
{
  if( m_ExcludeList->GetSelection() != wxNOT_FOUND ) {
    iONode excl = (iONode)m_ExcludeList->GetClientData(m_ExcludeList->GetSelection());
    NodeOp.removeChild( m_Props, excl );
    NodeOp.base.del(excl);
    m_ExcludeList->Delete(m_ExcludeList->GetSelection());
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ADD_INCLUDE
 */

void RouteDialog::OnAddIncludeClick( wxCommandEvent& event )
{
  wxString id = m_LocoListPerm->GetStringSelection();
  if( m_IncludeList->FindString(id) == wxNOT_FOUND ) {
    iONode incl = NodeOp.inst( wPermInclude.name(), m_Props, ELEMENT_NODE );
    wPermInclude.setid( incl, id.mb_str(wxConvUTF8) );
    NodeOp.addChild( m_Props, incl );
    m_IncludeList->Append(id, incl);
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ROUTE_LOCK
 */

void RouteDialog::OnRouteLockClick( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  iONode cmd = NodeOp.inst( wRoute.name(), NULL, ELEMENT_NODE );
  wRoute.setcmd( cmd, wRoute.test );
  wRoute.setid( cmd, wRoute.getid( m_Props ) );
  wRoute.setstatus( cmd, wRoute.status_locked);
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}


/*!
 * wxEVT_COMMAND_LISTBOX_SELECTED event handler for ID_SPEED_CONDITION_DESC
 */

void RouteDialog::OnSpeedConditionDescSelected( wxCommandEvent& event )
{
  initSpeedCond();
}


iONode RouteDialog::findSpeedCond(const char* desc) {
  iONode spcond = wRoute.getspeedcondition(m_Props);
  while( spcond != NULL ) {
    if( StrOp.equals(desc, wSpeedCondition.getdesc(spcond)) ) {
      return spcond;
    }
    spcond = wRoute.nextspeedcondition(m_Props, spcond);
  }
  return NULL;
}


void RouteDialog::initSpeedCond() {
  int sel = m_SpeedConditionList->GetSelection();
  if( sel != wxNOT_FOUND ) {
    iONode spcond = findSpeedCond(m_SpeedConditionList->GetString(sel).mb_str(wxConvUTF8));
    if( spcond != NULL ) {
      m_SpeedCondDesc->SetValue(wxString(wSpeedCondition.getdesc(spcond),wxConvUTF8));
      setSpeedCondType(wSpeedCondition.gettype(spcond));
      m_SpeedCondClass->SetValue(wxString(wSpeedCondition.getclass(spcond),wxConvUTF8));
      m_SpeedCondVariable->SetStringSelection(wxString(wSpeedCondition.getvariable(spcond),wxConvUTF8));
      m_SpeedCondVarSub->SetValue(wxString(wSpeedCondition.getvarsub(spcond),wxConvUTF8));
      m_SpeedCondValue->SetValue(wxString(wSpeedCondition.getvalue(spcond),wxConvUTF8));
      m_SpeedCondPercent->SetValue(wSpeedCondition.getpercent(spcond));
    }
  }
  else {
    m_SpeedCondDesc->SetValue(wxT(""));
    m_SpeedCondType->SetSelection(0);
    m_SpeedCondClass->SetValue(wxT(""));
    m_SpeedCondVariable->SetSelection(0);
    m_SpeedCondValue->SetValue(wxT(""));
    m_SpeedCondPercent->SetValue(0);
  }
}

void RouteDialog::OnSpeedcondAddClick( wxCommandEvent& event )
{
  if( m_SpeedConditionList->FindString(wxT("New")) == wxNOT_FOUND ) {
    m_SpeedConditionList->Append( wxT("New") );
    m_SpeedConditionList->SetStringSelection( wxT("New") );
    iONode spcond = NodeOp.inst(wSpeedCondition.name(), m_Props, ELEMENT_NODE);
    wSpeedCondition.setdesc( spcond, "New");
    NodeOp.addChild(m_Props, spcond);
    initSpeedCond();
  }
}


void RouteDialog::OnSpeedcondDelClick( wxCommandEvent& event )
{
  int action = wxMessageDialog( this, wxGetApp().getMsg("removewarning"), _T("Rocrail"), wxYES_NO | wxICON_EXCLAMATION ).ShowModal();
  if( action == wxID_NO )
    return;

  int sel = m_SpeedConditionList->GetSelection();
  if( sel != wxNOT_FOUND ) {
    iONode spcond = findSpeedCond(m_SpeedConditionList->GetString(sel).mb_str(wxConvUTF8));
    if( spcond != NULL ) {
      NodeOp.removeChild( m_Props, spcond );
      NodeOp.base.del(spcond);
      m_SpeedConditionList->Delete(sel);
      initSpeedCond();
    }
  }
}


void RouteDialog::setSpeedCondType(const char* condtype) {
  m_SpeedCondType->SetSelection(0);
  if( StrOp.equals( condtype, wLoc.cargo_none  ) )
    m_SpeedCondType->SetSelection(1);
  if( StrOp.equals( condtype, wLoc.cargo_goods  ) )
    m_SpeedCondType->SetSelection(2);
  if( StrOp.equals( condtype, wLoc.cargo_person  ) )
    m_SpeedCondType->SetSelection(3);
  if( StrOp.equals( condtype, wLoc.cargo_mixed  ) )
    m_SpeedCondType->SetSelection(4);
  if( StrOp.equals( condtype, wLoc.cargo_cleaning  ) )
    m_SpeedCondType->SetSelection(5);
  if( StrOp.equals( condtype, wLoc.cargo_ice  ) )
    m_SpeedCondType->SetSelection(6);
  if( StrOp.equals( condtype, wLoc.cargo_post  ) )
    m_SpeedCondType->SetSelection(7);
  if( StrOp.equals( condtype, wLoc.cargo_light  ) )
    m_SpeedCondType->SetSelection(8);
  if( StrOp.equals( condtype, wLoc.cargo_lightgoods  ) )
    m_SpeedCondType->SetSelection(9);
  if( StrOp.equals( condtype, wLoc.cargo_regional  ) )
    m_SpeedCondType->SetSelection(10);
  if( StrOp.equals( condtype, wLoc.cargo_shunting  ) )
    m_SpeedCondType->SetSelection(11);

}

const char* RouteDialog::getSpeedCondType() {
  int sel = m_SpeedCondType->GetSelection();

  if( sel ==  1 ) return wLoc.cargo_none;
  if( sel ==  2 ) return wLoc.cargo_goods;
  if( sel ==  3 ) return wLoc.cargo_person;
  if( sel ==  4 ) return wLoc.cargo_mixed;
  if( sel ==  5 ) return wLoc.cargo_cleaning;
  if( sel ==  6 ) return wLoc.cargo_ice;
  if( sel ==  7 ) return wLoc.cargo_post;
  if( sel ==  8 ) return wLoc.cargo_light;
  if( sel ==  9 ) return wLoc.cargo_lightgoods;
  if( sel == 10 ) return wLoc.cargo_regional;
  if( sel == 11 ) return wLoc.cargo_shunting;
  return "";
}

void RouteDialog::OnSpeedcondModifyClick( wxCommandEvent& event )
{
  int sel = m_SpeedConditionList->GetSelection();
  if( sel != wxNOT_FOUND ) {
    iONode spcond = findSpeedCond(m_SpeedConditionList->GetString(sel).mb_str(wxConvUTF8));
    if( spcond != NULL ) {
      wSpeedCondition.setdesc(spcond, m_SpeedCondDesc->GetValue().mb_str(wxConvUTF8));
      wSpeedCondition.settype(spcond, getSpeedCondType());
      wSpeedCondition.setclass(spcond, m_SpeedCondClass->GetValue().mb_str(wxConvUTF8));
      wSpeedCondition.setvariable(spcond, m_SpeedCondVariable->GetStringSelection().mb_str(wxConvUTF8));
      wSpeedCondition.setvarsub(spcond, m_SpeedCondVarSub->GetValue().mb_str(wxConvUTF8));
      wSpeedCondition.setvalue(spcond, m_SpeedCondValue->GetValue().mb_str(wxConvUTF8));
      wSpeedCondition.setpercent(spcond, m_SpeedCondPercent->GetValue());
      m_SpeedConditionList->SetString(sel, m_SpeedCondDesc->GetValue());
    }
  }
}


void RouteDialog::OnSpeedcondImportClick( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  int sel = m_SpeedCondImportFrom->GetSelection();
  if( sel > 0 ) {
    int idx = findID(m_SpeedCondImportFrom->GetStringSelection().mb_str(wxConvUTF8));
    if( idx != wxNOT_FOUND ) {
      iONode props = getSelection(idx);
      if( props != NULL ) {
        iONode spcond = wRoute.getspeedcondition(props);
        while( spcond != NULL ) {
          NodeOp.addChild( m_Props, (iONode)NodeOp.base.clone(spcond));
          spcond = wRoute.nextspeedcondition(props, spcond);
        }
        initValues();
      }
    }
  }
}


void RouteDialog::OnListctrlCommandsSelected( wxListEvent& event )
{
  int index = event.GetIndex();
  m_SwCmd = (iONode)m_Commands2->GetItemData(index);
  m_SwCmdIdx = index;
  if( m_SwCmd != NULL ) {
    CommandsSelected(m_SwCmd);
  }
  m_CmdUp->Enable(index > 0 ? true:false);
  m_CmdDown->Enable( index == m_Commands2->GetItemCount()-1 ? false:true);

}


void RouteDialog::OnRouteCmdUpClick( wxCommandEvent& event )
{
  if( m_SwCmdIdx > 0 ) {
    iOList cmds = ListOp.inst();
    iONode swcmd = wRoute.getswcmd( m_Props );
    while( swcmd != NULL ) {
      ListOp.add(cmds, NodeOp.base.clone(swcmd));
      swcmd = wRoute.nextswcmd( m_Props, swcmd );
    }
    swcmd = wRoute.getswcmd( m_Props );
    while( swcmd != NULL ) {
      NodeOp.removeChild(m_Props, swcmd );
      swcmd = wRoute.getswcmd( m_Props );
    }
    for( int i = 0; i < ListOp.size(cmds); i++) {
      if( i+1 == m_SwCmdIdx ) {
        NodeOp.addChild(m_Props, (iONode)ListOp.get(cmds, i+1) );
        NodeOp.addChild(m_Props, (iONode)ListOp.get(cmds, i) );
        i++;
      }
      else {
        NodeOp.addChild(m_Props, (iONode)ListOp.get(cmds, i) );
      }
    }
    ListOp.base.del(cmds);
    initCommands();
  }
}


void RouteDialog::OnRouteCmdDownClick( wxCommandEvent& event )
{
  if( m_SwCmdIdx < (m_Commands2->GetItemCount()-1) ) {
    iOList cmds = ListOp.inst();
    iONode swcmd = wRoute.getswcmd( m_Props );
    while( swcmd != NULL ) {
      ListOp.add(cmds, NodeOp.base.clone(swcmd));
      swcmd = wRoute.nextswcmd( m_Props, swcmd );
    }
    swcmd = wRoute.getswcmd( m_Props );
    while( swcmd != NULL ) {
      NodeOp.removeChild(m_Props, swcmd );
      swcmd = wRoute.getswcmd( m_Props );
    }
    for( int i = 0; i < ListOp.size(cmds); i++) {
      if( i == m_SwCmdIdx ) {
        NodeOp.addChild(m_Props, (iONode)ListOp.get(cmds, i+1) );
        NodeOp.addChild(m_Props, (iONode)ListOp.get(cmds, i) );
        i++;
      }
      else {
        NodeOp.addChild(m_Props, (iONode)ListOp.get(cmds, i) );
      }
    }
    ListOp.base.del(cmds);
    initCommands();
  }
}

