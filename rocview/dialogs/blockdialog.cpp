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
#pragma implementation "blockdialog.h"
#endif


#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#else
// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"
#endif

////@begin includes
#include "wx/imaglist.h"
////@end includes

#include "blockdialog.h"
#include "locdialog.h"
#include "feedbackdialog.h"
#include "switchdialog.h"
#include "routedialog.h"
#include "signaldialog.h"
#include "actionsctrldlg.h"

////@begin XPM images
////@end XPM images

#include "rocrail/wrapper/public/Plan.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/BlockList.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/Item.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/FunCmd.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/Route.h"
#include "rocrail/wrapper/public/FeedbackEvent.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/PermInclude.h"
#include "rocrail/wrapper/public/PermExclude.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/Turntable.h"
#include "rocrail/wrapper/public/ActionCtrl.h"
#include "rocrail/wrapper/public/Operator.h"

#include "rocview/public/guiapp.h"
#include "rocs/public/strtok.h"

/*!
 * BlockDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( BlockDialog, wxDialog )

/*!
 * BlockDialog event table definition
 */

BEGIN_EVENT_TABLE( BlockDialog, wxDialog )

////@begin BlockDialog event table entries
    EVT_LIST_ITEM_SELECTED( ID_LISTCTRLINDEX_BK, BlockDialog::OnListctrlindexBkSelected )
    EVT_LIST_COL_CLICK( ID_LISTCTRLINDEX_BK, BlockDialog::OnListctrlindexBkColLeftClick )
    EVT_BUTTON( ID_BUTTON_BLOCK_NEW, BlockDialog::OnButtonBlockNewClick )
    EVT_BUTTON( ID_BUTTON_BLOCK_DELETE, BlockDialog::OnButtonBlockDeleteClick )
    EVT_BUTTON( ID_BLOCK_DOC, BlockDialog::onDoc )
    EVT_BUTTON( ID_BUTTON_BK_LOCPROPS, BlockDialog::OnButtonBkLocpropsClick )
    EVT_CHECKBOX( wxID_BLOCK_WAIT, BlockDialog::OnBlockWaitClick )
    EVT_BUTTON( ID_BUTTON_BLOCK_ACTIONS, BlockDialog::OnButtonBlockActionsClick )
    EVT_BUTTON( ID_BUTTON_BK_SIGNAL, BlockDialog::OnButtonBkSignalClick )
    EVT_BUTTON( ID_BUTTON_BK_WSIGNAL, BlockDialog::OnButtonBkWsignalClick )
    EVT_BUTTON( ID_BUTTON_BK_SIGNAL_R, BlockDialog::OnButtonBkSignalRClick )
    EVT_BUTTON( ID_BUTTON_BK_WSIGNAL_R, BlockDialog::OnButtonBkWsignalRClick )
    EVT_BUTTON( ID_BK_STATESIGNAL_PROPS, BlockDialog::OnBkStatesignalPropsClick )
    EVT_RADIOBOX( ID_RADIOBOX_BK_WAIT, BlockDialog::OnRadioboxBkWaitSelected )
    EVT_LISTBOX( ID_LISTBOX_BK_ROUTES, BlockDialog::OnListboxBkRoutesSelected )
    EVT_COMBOBOX( ID_COMBOBOX_BLOCK_SENSOR_ID1, BlockDialog::OnBlockSensor )
    EVT_COMBOBOX( ID_COMBOBOX_BLOCK_SENSOR_ACTION1, BlockDialog::OnBlockSensor )
    EVT_CHECKBOX( ID_CHECKBOX_BLOCK_SENSOR_END1, BlockDialog::OnBlockSensor )
    EVT_CHECKBOX( ID_BLOCK_SENS1_T2, BlockDialog::OnBlockSensor )
    EVT_BUTTON( ID_BUTTON_BLOCKS_SENSOR_PROPS1, BlockDialog::OnSensorProps )
    EVT_COMBOBOX( ID_COMBOBOX_BLOCK_SENSOR_ID2, BlockDialog::OnBlockSensor )
    EVT_COMBOBOX( ID_COMBOBOX_BLOCK_SENSOR_ACTION2, BlockDialog::OnBlockSensor )
    EVT_CHECKBOX( ID_CHECKBOX_BLOCK_SENSOR_END2, BlockDialog::OnBlockSensor )
    EVT_CHECKBOX( ID_BLOCK_SENS2_T2, BlockDialog::OnBlockSensor )
    EVT_BUTTON( ID_BUTTON_BLOCK_SENSOR_PROPS2, BlockDialog::OnSensorProps )
    EVT_COMBOBOX( ID_COMBOBOX_BLOCK_SENSOR_ID3, BlockDialog::OnBlockSensor )
    EVT_COMBOBOX( ID_COMBOBOX_BLOCK_SENSOR_ACTION3, BlockDialog::OnBlockSensor )
    EVT_CHECKBOX( ID_CHECKBOX_BLOCK_SENSOR_END3, BlockDialog::OnBlockSensor )
    EVT_CHECKBOX( ID_BLOCK_SENS3_T2, BlockDialog::OnBlockSensor )
    EVT_BUTTON( ID_BUTTON_BLOCKS_SENSOR_PROPS3, BlockDialog::OnSensorProps )
    EVT_COMBOBOX( ID_COMBOBOX_BLOCK_SENSOR_ID4, BlockDialog::OnBlockSensor )
    EVT_COMBOBOX( ID_COMBOBOX_BLOCK_SENSOR_ACTION4, BlockDialog::OnBlockSensor )
    EVT_CHECKBOX( ID_CHECKBOX_BLOCK_SENSOR_END4, BlockDialog::OnBlockSensor )
    EVT_CHECKBOX( ID_BLOCK_SENS4_T2, BlockDialog::OnBlockSensor )
    EVT_BUTTON( ID_BUTTON_BLOCKS_SENSOR_PROPS4, BlockDialog::OnSensorProps )
    EVT_COMBOBOX( ID_COMBOBOX_BLOCK_SENSOR_ID5, BlockDialog::OnBlockSensor )
    EVT_COMBOBOX( ID_COMBOBOX_BLOCK_SENSOR_ACTION5, BlockDialog::OnBlockSensor )
    EVT_CHECKBOX( ID_CHECKBOX_BLOCK_SENSOR_END5, BlockDialog::OnBlockSensor )
    EVT_CHECKBOX( ID_BLOCK_SENS5_T2, BlockDialog::OnBlockSensor )
    EVT_BUTTON( ID_BUTTON_BLOCKS_SENSOR_PROPS5, BlockDialog::OnSensorProps )
    EVT_BUTTON( ID_BUTTON1, BlockDialog::OnButtonBkRoutePropsClick )
    EVT_BUTTON( ID_BUTTON2, BlockDialog::OnButtonBkRouteTestClick )
    EVT_BUTTON( ID_ADD_INCLUDE, BlockDialog::OnAddIncludeClick )
    EVT_BUTTON( ID_ADD_EXCLUDE, BlockDialog::OnAddExcludeClick )
    EVT_LISTBOX( ID_INCLUDE_LIST, BlockDialog::OnIncludeListSelected )
    EVT_BUTTON( ID_REMOVE_INCLUDE, BlockDialog::OnRemoveIncludeClick )
    EVT_SPINCTRL( ID_INCLUDE_RANDOMRATE, BlockDialog::OnIncludeRandomrateUpdated )
    EVT_BUTTON( ID_REMOVE_EXCLUDE, BlockDialog::OnRemoveExcludeClick )
    EVT_BUTTON( wxID_CANCEL, BlockDialog::OnCancelClick )
    EVT_BUTTON( wxID_APPLY, BlockDialog::OnApplyClick )
    EVT_BUTTON( wxID_OK, BlockDialog::OnOkClick )
    EVT_BUTTON( wxID_HELP, BlockDialog::OnHelpClick )
////@end BlockDialog event table entries
    EVT_MENU( ID_PANEL_BK_GENERAL, BlockDialog::OnSelectPage )

END_EVENT_TABLE()

/*!
 * BlockDialog constructors
 */

BlockDialog::BlockDialog( )
{
}

BlockDialog::BlockDialog( wxWindow* parent, iONode p_Props, bool save )
{
  m_TabAlign = wxGetApp().getTabAlign();
  Create(parent, -1, wxGetApp().getMsg("blocktable") );
  m_Props = p_Props;
  m_bSave = save;
  m_iRouteSelection = 0;

  initLabels();

  m_IndexPanel->GetSizer()->Layout();
  m_General_Panel->GetSizer()->Layout();
  m_LocationPanel->GetSizer()->Layout();
  m_PanelWirering->GetSizer()->Layout();
  m_RoutesPanel->GetSizer()->Layout();
  m_PanelDetails->GetSizer()->Layout();
  m_Interface->GetSizer()->Layout();

  m_Notebook->Fit();

  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);

  // Initialize sorted Loco Permission List
  initLocPermissionList();

  if( initIndex() ) {
    initValues();
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ID_PANEL_BK_GENERAL );
    wxPostEvent( this, event );
  }

  if( wxGetApp().isModView() ) {
    m_RoutesPanel->Enable(False);
  }


}

void BlockDialog::OnSelectPage(wxCommandEvent& event) {
  m_Notebook->SetSelection( 1 );
}

/* comparator for sorting by id: */
static int __sortStr(obj* _a, obj* _b)
{
    const char* a = (const char*)*_a;
    const char* b = (const char*)*_b;
    return strcmp( a, b );
}

void BlockDialog::initSignalCombos() {
  m_Signal->Append( _T("-") );
  m_WSignal->Append( _T("-") );
  m_SignalR->Append( _T("-") );
  m_WSignalR->Append( _T("-") );
  m_StateSignal->Append( _T("-") );

  iONode model = wxGetApp().getModel();
  iOList list = ListOp.inst();

  if( model != NULL ) {
    iONode sglist = wPlan.getsglist( model );
    if( sglist != NULL ) {
      int cnt = NodeOp.getChildCnt( sglist );
      for( int i = 0; i < cnt; i++ ) {
        iONode sg = NodeOp.getChild( sglist, i );
        const char* id = wSignal.getid( sg );
        if( id != NULL ) {
          ListOp.add(list, (obj)id);
    }
    }
      ListOp.sort(list, &__sortStr);
      cnt = ListOp.size( list );
      for( int i = 0; i < cnt; i++ ) {
        const char* id = (const char*)ListOp.get( list, i );
          m_Signal->Append( wxString(id,wxConvUTF8) );
          m_WSignal->Append( wxString(id,wxConvUTF8) );
          m_SignalR->Append( wxString(id,wxConvUTF8) );
          m_WSignalR->Append( wxString(id,wxConvUTF8) );
          m_StateSignal->Append( wxString(id,wxConvUTF8) );
      }
    }
  }
  /* clean up the temp. list */
  ListOp.base.del(list);
}
void BlockDialog::initTurntableCombo() {
  iONode model = wxGetApp().getModel();
  iOList list = ListOp.inst();

  m_TurntableID->Append( _T("-") );

  if( model != NULL ) {
    iONode ttlist = wPlan.getttlist( model );
    if( ttlist != NULL ) {
      int cnt = NodeOp.getChildCnt( ttlist );
      for( int i = 0; i < cnt; i++ ) {
        iONode tt = NodeOp.getChild( ttlist, i );
        const char* id = wItem.getid( tt );
        if( id != NULL ) {
          ListOp.add(list, (obj)id);
    }
    }
      ListOp.sort(list, &__sortStr);
      cnt = ListOp.size( list );
      for( int i = 0; i < cnt; i++ ) {
        const char* id = (const char*)ListOp.get( list, i );
        m_TurntableID->Append( wxString(id,wxConvUTF8) );
      }
    }
  }
  /* clean up the temp. list */
  ListOp.base.del(list);
}

void BlockDialog::initLocPermissionList() {
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


void BlockDialog::initLabels() {
  m_Notebook->SetPageText( 0, wxGetApp().getMsg( "index" ) );
  m_Notebook->SetPageText( 1, wxGetApp().getMsg( "general" ) );
  m_Notebook->SetPageText( 2, wxGetApp().getMsg( "position" ) );
  m_Notebook->SetPageText( 3, wxGetApp().getMsg( "signals" ) );
  m_Notebook->SetPageText( 4, wxGetApp().getMsg( "details" ) );
  m_Notebook->SetPageText( 5, wxGetApp().getMsg( "routes" ) );
  m_Notebook->SetPageText( 6, wxGetApp().getMsg( "trackdriver" ) );
  m_Notebook->SetPageText( 7, wxGetApp().getMsg( "permissions" ) );

  // Index
  initList(m_List2, this, true, true, true, true);
  m_New->SetLabel( wxGetApp().getMsg( "new" ) );
  m_Delete->SetLabel( wxGetApp().getMsg( "delete" ) );
  m_Doc->SetLabel( wxGetApp().getMsg( "doc_report" ) );

  // General
  m_label_ID->SetLabel( wxGetApp().getMsg( "id" ) );
  m_Label_Description->SetLabel( wxGetApp().getMsg( "description" ) );
  m_Label_Length->SetLabel( wxGetApp().getMsg( "length" ) );
  m_labDepartDelay->SetLabel( wxGetApp().getMsg( "departdelay" ) );
  m_labFifoSize->SetLabel( wxGetApp().getMsg( "fifosize" ) );
  m_labFifoSizeAutomobiles->SetLabel( wxT("(") + wxGetApp().getMsg( "automobile" ) + wxT(")") );
  m_LabelLocID->SetLabel( wxGetApp().getMsg( "locid" ) );
  m_labTurntableID->SetLabel( wxGetApp().getMsg( "turntableid" ) );
  m_Commuter->SetLabel( wxGetApp().getMsg( "commuter" ) );
  m_Commuter->SetString( 0, wxGetApp().getMsg( "no" ) );
  m_Commuter->SetString( 1, wxGetApp().getMsg( "yes" ) );
  m_Commuter->SetString( 2, wxGetApp().getMsg( "only" ) );
  m_Configuration->GetStaticBox()->SetLabel( wxGetApp().getMsg( "configuration" ) );
  m_Electrified->SetLabel( wxGetApp().getMsg( "electrified" ) );
  m_Closed->SetLabel( wxGetApp().getMsg( "outoforder" ) );
  //m_Critical->SetLabel( wxGetApp().getMsg( "criticalsection" ) );
  m_GoManual->SetLabel( wxGetApp().getMsg( "gomanual" ) );
  m_AcceptGhost->SetLabel( wxGetApp().getMsg( "acceptghost" ) );
  m_Swapplacing->SetLabel( wxGetApp().getMsg( "terminalstation" ) );
  m_WaitFlag->SetLabel( wxGetApp().getMsg( "wait" ) );
  m_Road->SetLabel( wxGetApp().getMsg( "road" ) );
  m_AllowChgDir->SetLabel( wxGetApp().getMsg( "allowchgdir" ) );
  m_SmallSymbol->SetLabel( wxGetApp().getMsg( "smallsymbol" ) );
  m_ExtStop->SetLabel( wxGetApp().getMsg( "extstop" ) );
  m_AcceptIdent->SetLabel( wxGetApp().getMsg( "acceptident" ) );
  m_MainLine->SetLabel( wxGetApp().getMsg( "mainline" ) );
  m_SleepOnClosed->SetLabel( wxGetApp().getMsg( "sleeponclosed" ) );
  m_FreeBlockOnEnter->SetLabel( wxGetApp().getMsg( "freeblockonenter" ) );
  m_labRandomRate->SetLabel( wxGetApp().getMsg( "randomrate" ) );
  m_BlockActions->SetLabel( wxGetApp().getMsg( "actions" ) + _T("...") );
  m_Show->SetLabel( wxGetApp().getMsg( "show" ) );

  m_VirtualBox->SetLabel( wxGetApp().getMsg( "virtual" ) );
  m_labSlaveBlocks->SetLabel( wxGetApp().getMsg( "slaveblocks" ) );
  m_Virtual->SetLabel( wxGetApp().getMsg( "virtual" ) );

  initTurntableCombo();

  // Location
  m_LabelX->SetLabel( wxGetApp().getMsg( "x" ) );
  m_LabelY->SetLabel( wxGetApp().getMsg( "y" ) );
  m_LabelZ->SetLabel( wxGetApp().getMsg( "z" ) );
  m_Location->SetLabel( wxGetApp().getMsg( "position" ) );

  /*
  m_ori->SetLabel( wxGetApp().getMsg( "orientation" ) );
  m_ori->SetString( 0, wxGetApp().getMsg( "north" ) );
  m_ori->SetString( 1, wxGetApp().getMsg( "east" ) );
  m_ori->SetString( 2, wxGetApp().getMsg( "south" ) );
  m_ori->SetString( 3, wxGetApp().getMsg( "west" ) );
  */

  // Signals
  m_ForwardSignalsBox->SetLabel( wxGetApp().getMsg( "minsidesignals" ) );
  m_ReverseSignalsBox->SetLabel( wxGetApp().getMsg( "plussidesignals" ) );
  m_LabelSignal->SetLabel( wxGetApp().getMsg( "signal" ) );
  m_LabelWSignal->SetLabel( wxGetApp().getMsg( "distant_signal" ) );
  m_BlankAtRedSignal->SetLabel( wxGetApp().getMsg( "blankatredsignal" ) );
  m_LabelSignalR->SetLabel( wxGetApp().getMsg( "signal" ) );
  m_LabelWSignalR->SetLabel( wxGetApp().getMsg( "distant_signal" ) );
  m_BlankAtRedSignalR->SetLabel( wxGetApp().getMsg( "blankatredsignal" ) );
  m_labStateSignal->SetLabel( wxGetApp().getMsg( "statesignal" ) );

  // Initialize sorted Signal Combos
  initSignalCombos();

  // Details
  m_SpeedBox->SetLabel( wxGetApp().getMsg( "speed" ) );
  m_Speed->SetLabel( wxGetApp().getMsg( "arrive" ) );
  m_Speed->SetString( 0, wxGetApp().getMsg( "min" ) );
  m_Speed->SetString( 1, wxGetApp().getMsg( "mid" ) );
  m_Speed->SetString( 2, wxGetApp().getMsg( "cruise" ) );
  m_Speed->SetString( 3, wxGetApp().getMsg( "max" ) );
  m_Speed->SetString( 4, _T("%") );
  m_ExitSpeed->SetLabel( wxGetApp().getMsg( "departure" ) );
  m_ExitSpeed->SetString( 0, wxGetApp().getMsg( "min" ) );
  m_ExitSpeed->SetString( 1, wxGetApp().getMsg( "mid" ) );
  m_ExitSpeed->SetString( 2, wxGetApp().getMsg( "cruise" ) );
  m_ExitSpeed->SetString( 3, wxGetApp().getMsg( "max" ) );
  m_StopSpeed->SetLabel( wxGetApp().getMsg( "stop" ) );
  m_StopSpeed->SetString( 0, wxGetApp().getMsg( "min" ) );
  m_StopSpeed->SetString( 1, wxGetApp().getMsg( "mid" ) );
  m_StopSpeed->SetString( 2, _T("%") );
  m_labMaxKmH->SetLabel( wxGetApp().getMsg( "maxkmh" ) );

  m_Type->SetLabel( wxGetApp().getMsg( "type" ) );
  m_Type->SetString( 0, wxGetApp().getMsg( "others" ) );
  m_Type->SetString( 1, wxGetApp().getMsg( "local" ) );
  m_Type->SetString( 2, wxGetApp().getMsg( "ice" ) );
  m_Type->SetString( 3, wxGetApp().getMsg( "goods" ) );
  m_Type->SetString( 4, wxGetApp().getMsg( "shunting" ) );
  m_Type->SetString( 5, wxGetApp().getMsg( "turntable" ) );
  m_Type->SetString( 6, wxGetApp().getMsg( "regional" ) );
  m_Type->SetString( 7, wxGetApp().getMsg( "light" ) );
  m_Type->SetString( 8, wxGetApp().getMsg( "lightgoods" ) );
  m_Type->SetString( 9, wxGetApp().getMsg( "post" ) );
  m_Incline->SetLabel( wxGetApp().getMsg( "incline" ) );
  m_Incline->SetString( 0, wxGetApp().getMsg( "none" ) );
  m_Incline->SetString( 1, wxGetApp().getMsg( "up" ) );
  m_Incline->SetString( 2, wxGetApp().getMsg( "down" ) );
  m_Wait->SetLabel( wxGetApp().getMsg( "wait" ) );
  m_Wait->SetString( 0, wxGetApp().getMsg( "random" ) );
  m_Wait->SetString( 1, wxGetApp().getMsg( "fixed" ) );
  m_Wait->SetString( 2, wxGetApp().getMsg( "loc" ) );
  m_Wait->SetString( 3, wxGetApp().getMsg( "no" ) );
  m_WaitDetails->GetStaticBox()->SetLabel( wxGetApp().getMsg( "waitdetails" ) );
  m_LabelRandomMin->SetLabel( wxGetApp().getMsg( "randommin" ) );
  m_LabelRandomMax->SetLabel( wxGetApp().getMsg( "randommax" ) );
  m_LabelFixed->SetLabel( wxGetApp().getMsg( "fixed" ) );

  m_Measurement->SetLabel( wxGetApp().getMsg( "measurement" ) );
  m_labScale->SetLabel( wxGetApp().getMsg( "scale" ) );
  m_labDistance->SetLabel( wxGetApp().getMsg( "distance" ) );

  // Routes
  m_RouteProps->SetLabel( wxGetApp().getMsg( "properties" ) );
  m_RouteTest->SetLabel( wxGetApp().getMsg( "test" ) );

  // Route Sensors
  m_LabelSensorIDs->SetLabel( wxGetApp().getMsg( "id" ) );
  m_LabelSensorActions->SetLabel( wxGetApp().getMsg( "event" ) );
  m_LabelSensorEnd->SetLabel( wxGetApp().getMsg( "endpulse" ) );
  m_labTimer->SetLabel( wxGetApp().getMsg( "eventtimer" )+_T(" 1") );
  m_labTimerMS->SetLabel( wxGetApp().getMsg( "milliseconds" ) );
  m_labTimer2->SetLabel( wxGetApp().getMsg( "eventtimer" )+_T(" 2") );
  m_labTimer2MS->SetLabel( wxGetApp().getMsg( "milliseconds" ) );
  m_ForceBlockTimer->SetLabel( wxGetApp().getMsg( "forceblocktimer" ) );
  m_SelectShortestBlock->SetLabel( wxGetApp().getMsg( "selectshortestblock" ) );
  initSensorCombos();

  // Interface
  BaseDialog::addIIDs(m_iid);

  m_Labeliid->SetLabel( wxGetApp().getMsg( "iid" ) );
  m_LabelAddress->SetLabel( wxGetApp().getMsg( "address" ) );
  m_LabelPort->SetLabel( wxGetApp().getMsg( "port" ) );
  m_TD->SetLabel( wxGetApp().getTip( "trackdriver" ) );

  // Permissions
  m_labInclude->SetLabel( wxGetApp().getMsg( "include" ) );
  m_labExclude->SetLabel( wxGetApp().getMsg( "exclude" ) );
  m_IncludeRandomRate->SetToolTip( wxGetApp().getMsg( "randomrate" ) );
  m_AddInclude->SetLabel( wxGetApp().getMsg( "include" ) );
  m_AddExclude->SetLabel( wxGetApp().getMsg( "exclude" ) );
  m_RemoveInclude->SetLabel( wxGetApp().getMsg( "delete" ) );
  m_RemoveExclude->SetLabel( wxGetApp().getMsg( "delete" ) );

  m_PermType->SetLabel( wxGetApp().getMsg( "type" ) );
  m_PermTypeNone->SetLabel( wxGetApp().getMsg( "others" ) );
  m_PermTypeGoods->SetLabel( wxGetApp().getMsg( "goods" ) );
  m_PermTypeLocal->SetLabel( wxGetApp().getMsg( "regional" ) );
  m_PermTypePerson->SetLabel( wxGetApp().getMsg( "local" ) );
  m_PermTypeMixed->SetLabel( wxGetApp().getMsg( "mixed" ) );
  m_PermTypeCleaning->SetLabel( wxGetApp().getMsg( "cleaning" ) );
  m_PermTypeICE->SetLabel( wxGetApp().getMsg( "ice" ) );
  m_PermTypePost->SetLabel( wxGetApp().getMsg( "post" ) );
  m_PermTypeLight->SetLabel( wxGetApp().getMsg( "light" ) );
  m_PermTypeLightGoods->SetLabel( wxGetApp().getMsg( "lightgoods" ) );

  m_labClass->SetLabel( wxGetApp().getMsg( "class" ) );

  // Buttons
  m_OK->SetLabel( wxGetApp().getMsg( "ok" ) );
  m_Cancel->SetLabel( wxGetApp().getMsg( "cancel" ) );
  m_Apply->SetLabel( wxGetApp().getMsg( "apply" ) );
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


bool BlockDialog::initIndex() {
  TraceOp.trc( "blockdlg", TRCLEVEL_INFO, __LINE__, 9999, "InitIndex" );
  iONode model = wxGetApp().getModel();
  if( model != NULL ) {
    iONode bklist = wPlan.getbklist( model );
    if( bklist != NULL ) {
      fillIndex(bklist);

      if( m_Props != NULL ) {
        setIDSelection(wBlock.getid( m_Props ));
        return true;
      }
      else {
        m_Props = setSelection(0);
      }

    }
  }
  return false;
}


void BlockDialog::initValues() {
  char* title = StrOp.fmt( "%s %s", (const char*)wxGetApp().getMsg("block").mb_str(wxConvUTF8), wBlock.getid( m_Props ) );
  SetTitle( wxString(title,wxConvUTF8) );
  TraceOp.trc( "blockdlg", TRCLEVEL_INFO, __LINE__, 9999, "initValues: %s", title );
  StrOp.free( title );

  // General
  m_ID->SetValue( wxString(wBlock.getid( m_Props ),wxConvUTF8) );
  m_Description->SetValue( wxString(wBlock.getdesc( m_Props ),wxConvUTF8) );
  char* str = StrOp.fmt( "%d", wBlock.getlen( m_Props ) );
  m_Length->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );


  m_DepartDelay->SetValue( wBlock.getdepartdelay( m_Props ) );
  m_FifoSize->SetValue( wBlock.getfifosize( m_Props ) );
  m_RandomRate->SetValue( wBlock.getrandomrate( m_Props ) );
  m_LocID->Disable();
  if( wBlock.getlocid( m_Props ) != NULL )
    m_LocID->SetValue( wxString(wBlock.getlocid( m_Props ),wxConvUTF8) );
  else
    m_LocID->SetValue( _T("") );

  if( wBlock.getttid( m_Props ) != NULL && StrOp.len(wBlock.getttid( m_Props )) > 0 )
    m_TurntableID->SetStringSelection( wxString(wBlock.getttid( m_Props ),wxConvUTF8) );
  else
    m_TurntableID->SetSelection(0);

  if( StrOp.equals( wBlock.commuter_no, wBlock.getcommuter( m_Props ) ) )
    m_Commuter->SetSelection(0);
  else if( StrOp.equals( wBlock.commuter_yes, wBlock.getcommuter( m_Props ) ) )
    m_Commuter->SetSelection(1);
  else if( StrOp.equals( wBlock.commuter_only, wBlock.getcommuter( m_Props ) ) )
    m_Commuter->SetSelection(2);
  else
    m_Commuter->SetSelection(0);

  m_Electrified->SetValue( wBlock.iselectrified(m_Props) );
  if( StrOp.equals( wBlock.closed, wBlock.getstate( m_Props ) ) )
    m_Closed->SetValue( true );
  else
    m_Closed->SetValue( false );
  //m_Critical->SetValue( wBlock.iscritical(m_Props) );
  m_GoManual->SetValue( wBlock.isgomanual(m_Props) );
  m_AcceptGhost->SetValue( wBlock.isacceptghost(m_Props) );
  m_AcceptIdent->SetValue( wBlock.isacceptident(m_Props) );
  m_Swapplacing->SetValue( wBlock.isterminalstation(m_Props) );
  m_WaitFlag->SetValue( wBlock.iswait(m_Props) );
  m_Road->SetValue( wItem.isroad(m_Props) );
  m_AllowChgDir->SetValue( wBlock.isallowchgdir(m_Props) );
  m_SmallSymbol->SetValue( wBlock.issmallsymbol(m_Props) );
  m_ExtStop->SetValue( wBlock.isextstop( m_Props ) ? true:false);
  m_AllowBBT->SetValue( wBlock.isallowbbt( m_Props ) ? true:false);
  m_MainLine->SetValue( wBlock.ismainline( m_Props ) ? true:false);
  m_SleepOnClosed->SetValue( wBlock.issleeponclosed( m_Props ) ? true:false);
  m_FreeBlockOnEnter->SetValue( wBlock.isfreeblockonenter( m_Props ) ? true:false);

  m_Show->SetValue( wItem.isshow( m_Props ) ? true:false);
  m_Virtual->SetValue( wBlock.isvirtual( m_Props ) ? true:false);
  m_SlaveBlocks->SetValue( wxString(wBlock.getslaveblocks( m_Props ),wxConvUTF8) );

  // Location
  char* cval = StrOp.fmt( "%d", wBlock.getx( m_Props ) );
  m_x->SetValue( wxString(cval,wxConvUTF8) ); StrOp.free( cval );
  cval = StrOp.fmt( "%d", wBlock.gety( m_Props ) );
  m_y->SetValue( wxString(cval,wxConvUTF8) ); StrOp.free( cval );
  cval = StrOp.fmt( "%d", wBlock.getz( m_Props ) );
  m_z->SetValue( wxString(cval,wxConvUTF8) ); StrOp.free( cval );
  m_Ori->SetValue( wxString(wItem.getori( m_Props ),wxConvUTF8) );

  /*
  if( StrOp.equals( wItem.north, wBlock.getori( m_Props ) ) )
    m_ori->SetSelection( 0 );
  else if( StrOp.equals( wItem.east, wBlock.getori( m_Props ) ) || wBlock.getori( m_Props ) == NULL )
    m_ori->SetSelection( 1 );
  else if( StrOp.equals( wItem.south, wBlock.getori( m_Props ) ) )
    m_ori->SetSelection( 2 );
  else if( StrOp.equals( wItem.west, wBlock.getori( m_Props ) ) )
    m_ori->SetSelection( 3 );
  */

  // Signals
  m_Signal->SetSelection(0);
  m_WSignal->SetSelection(0);
  m_SignalR->SetSelection(0);
  m_WSignalR->SetSelection(0);
  m_StateSignal->SetSelection(0);

  if( wBlock.getsignal( m_Props ) != NULL && StrOp.len( wBlock.getsignal( m_Props ) ) > 0 )
    m_Signal->SetStringSelection( wxString(wBlock.getsignal(m_Props),wxConvUTF8) );
  if( wBlock.getwsignal( m_Props ) != NULL && StrOp.len( wBlock.getwsignal( m_Props ) ) > 0 )
    m_WSignal->SetStringSelection( wxString(wBlock.getwsignal(m_Props),wxConvUTF8) );

  if( wBlock.getsignalR( m_Props ) != NULL && StrOp.len( wBlock.getsignalR( m_Props ) ) > 0 )
    m_SignalR->SetStringSelection( wxString(wBlock.getsignalR(m_Props),wxConvUTF8) );
  if( wBlock.getwsignalR( m_Props ) != NULL && StrOp.len( wBlock.getwsignalR( m_Props ) ) > 0 )
    m_WSignalR->SetStringSelection( wxString(wBlock.getwsignalR(m_Props),wxConvUTF8) );

  if( wBlock.getstatesignal( m_Props ) != NULL && StrOp.len( wBlock.getstatesignal( m_Props ) ) > 0 )
    m_StateSignal->SetStringSelection( wxString(wBlock.getstatesignal(m_Props),wxConvUTF8) );

  m_BlankAtRedSignal->SetValue(wBlock.isblankatredsignal(m_Props)?true:false);
  m_BlankAtRedSignalR->SetValue(wBlock.isblankatredsignalR(m_Props)?true:false);

  // Details
  int speed = 0;
  if( StrOp.equals( wBlock.min, wBlock.getspeed( m_Props ) ) )
    speed = 0;
  else if( StrOp.equals( wBlock.mid, wBlock.getspeed( m_Props ) ) )
    speed = 1;
  else if( StrOp.equals( wBlock.cruise, wBlock.getspeed( m_Props ) ) )
    speed = 2;
  else if( StrOp.equals( wBlock.max, wBlock.getspeed( m_Props ) ) )
    speed = 3;
  else if( StrOp.equals( wBlock.percent, wBlock.getspeed( m_Props ) ) )
    speed = 4;
  m_Speed->SetSelection( speed );

  speed = 0;
  if( StrOp.equals( wBlock.min, wBlock.getstopspeed( m_Props ) ) )
    speed = 0;
  else if( StrOp.equals( wBlock.mid, wBlock.getstopspeed( m_Props ) ) )
    speed = 1;
  else if( StrOp.equals( wBlock.percent, wBlock.getstopspeed( m_Props ) ) )
    speed = 2;
  m_StopSpeed->SetSelection( speed );

  speed = 0;
  if( StrOp.equals( wBlock.min, wBlock.getexitspeed( m_Props ) ) )
    speed = 0;
  else if( StrOp.equals( wBlock.mid, wBlock.getexitspeed( m_Props ) ) )
    speed = 1;
  else if( StrOp.equals( wBlock.cruise, wBlock.getexitspeed( m_Props ) ) )
    speed = 2;
  else if( StrOp.equals( wBlock.max, wBlock.getexitspeed( m_Props ) ) )
    speed = 3;
  else if( StrOp.equals( wBlock.percent, wBlock.getexitspeed( m_Props ) ) )
    speed = 4;
  m_ExitSpeed->SetSelection( speed );

  str = StrOp.fmt( "%d", wBlock.getspeedpercent(m_Props) );
  m_SpeedPercent->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wBlock.getexitspeedpercent(m_Props) );
  m_ExitSpeedPercent->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );

  m_MaxKmH->SetValue(wBlock.getmaxkmh(m_Props));

  int type = 0;
  if( StrOp.equals( wBlock.type_none, wBlock.gettype( m_Props ) ) )
    type = 0;
  else if( StrOp.equals( wBlock.type_local, wBlock.gettype( m_Props ) ) )
    type = 1;
  else if( StrOp.equals( wBlock.type_ice, wBlock.gettype( m_Props ) ) )
    type = 2;
  else if( StrOp.equals( wBlock.type_goods, wBlock.gettype( m_Props ) ) )
    type = 3;
  else if( StrOp.equals( wBlock.type_shunting, wBlock.gettype( m_Props ) ) )
    type = 4;
  else if( StrOp.equals( wBlock.type_turntable, wBlock.gettype( m_Props ) ) )
    type = 5;
  else if( StrOp.equals( wBlock.type_regional, wBlock.gettype( m_Props ) ) )
    type = 6;
  else if( StrOp.equals( wBlock.type_light, wBlock.gettype( m_Props ) ) )
    type = 7;
  else if( StrOp.equals( wBlock.type_lightgoods, wBlock.gettype( m_Props ) ) )
    type = 8;
  else if( StrOp.equals( wBlock.type_post, wBlock.gettype( m_Props ) ) )
    type = 9;
  m_Type->SetSelection( type );

  int incline = 0;
  if( wBlock.incline_none == wBlock.getincline( m_Props ) )
    incline = 0;
  else if( wBlock.incline_up == wBlock.getincline( m_Props ) )
    incline = 1;
  else if( wBlock.incline_down == wBlock.getincline( m_Props ) )
    incline = 2;
  m_Incline->SetSelection( incline );

  int wait = 0;
  if( StrOp.equals( wBlock.wait_random, wBlock.getwaitmode( m_Props ) ) )
    wait = 0;
  else if( StrOp.equals( wBlock.wait_fixed, wBlock.getwaitmode( m_Props ) ) )
    wait = 1;
  else if( StrOp.equals( wBlock.wait_loc, wBlock.getwaitmode( m_Props ) ) )
    wait = 2;
  if( !wBlock.iswait(m_Props) )
    wait = 3;
  m_Wait->SetSelection( wait );

  wxString val;
  val.Printf( _T("%d"), wBlock.getminwaittime( m_Props ) );
  m_RandomMin->SetValue( val );
  val.Printf( _T("%d"), wBlock.getmaxwaittime( m_Props ) );
  m_RandomMax->SetValue( val );
  val.Printf( _T("%d"), wBlock.getwaittime( m_Props ) );
  m_Fixed->SetValue( val );

  val.Printf( _T("%d"), wBlock.getmvscale( m_Props ) );
  m_Scale->SetValue( val );
  val.Printf( _T("%d"), wBlock.getmvdistance( m_Props ) );
  m_Distance->SetValue( val );
  m_MPH->SetValue(wBlock.ismvmph( m_Props ));


  val.Printf( _T("%d"), wBlock.getevttimer( m_Props ) );
  m_Timer->SetValue( val );
  val.Printf( _T("%d"), wBlock.getevttimer2( m_Props ) );
  m_Timer2->SetValue( val );
  m_ForceBlockTimer->SetValue( wBlock.isforceblocktimer( m_Props ) ? true:false );
  m_SelectShortestBlock->SetValue( wBlock.isselectshortestblock( m_Props ) ? true:false );

  // Routes
  m_Routes->Clear();
  m_Routes->Append( wxString(ROUTE_ALL,wxConvUTF8), (void*)NULL );
  m_Routes->Append( wxString(ROUTE_ALL_REVERSE,wxConvUTF8), (void*)NULL );
  iONode model = wxGetApp().getModel();
  if( model != NULL ) {
    iONode stlist = wPlan.getstlist( model );
    if( stlist != NULL ) {
      iOList list = ListOp.inst();
      int cnt = NodeOp.getChildCnt( stlist );
      for( int i = 0; i < cnt; i++ ) {
        iONode st = NodeOp.getChild( stlist, i );
        if( (wRoute.getbkb( st ) != NULL && StrOp.equals( wRoute.getbkb( st ), wBlock.getid( m_Props ) ))) {
          ListOp.add(list, (obj) st);
        }
      }

      ListOp.sort(list, &__sortID);
      for( int i = 0; i < ListOp.size(list); i++ ) {
        iONode st = (iONode)ListOp.get( list, i );
        const char* id = wRoute.getid( st );
        const char* bka = wRoute.getbka( st );
        const char* bkb = wRoute.getbkb( st );
        char* str = StrOp.fmt( "%s = from \"%s\" to \"%s\"", id, bka, bkb );
        m_Routes->Append( wxString(str,wxConvUTF8), st );
        StrOp.free( str );
      }
      ListOp.base.del(list);

    }
  }

  if(m_Routes->GetCount() > m_iRouteSelection) {
    m_Routes->SetSelection(m_iRouteSelection);
    TraceOp.trc( "blockdlg", TRCLEVEL_INFO, __LINE__, 9999, "RouteSelection=%d", m_iRouteSelection );
    initSensors();
  }

  // Interface
  m_iid->SetValue( wBlock.getiid( m_Props )==NULL?_T(""):wxString(wBlock.getiid( m_Props ),wxConvUTF8) );
  str = StrOp.fmt( "%d", wBlock.getaddr(m_Props) );
  m_Address->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wBlock.getport(m_Props) );
  m_Port->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );
  m_TD->SetValue( wBlock.istd(m_Props) );

  // Permissions

  // remove selections:
  m_ExcludeList->Clear();
  m_IncludeList->Clear();
  m_IncludeRandomRate->SetValue(0);

  // set selections:
  iONode excl = wBlock.getexcl( m_Props );
  while( excl != NULL ) {
    m_ExcludeList->Append(wxString(wPermExclude.getid(excl),wxConvUTF8), excl);
    excl = wBlock.nextexcl( m_Props, excl );
  };

  iONode incl = wBlock.getincl( m_Props );
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

  iOStrTok tok = StrTokOp.inst( wBlock.gettypeperm( m_Props ), ',' );
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
  }
  StrTokOp.base.del(tok);

  m_Class->SetValue(wxString(wBlock.getclass(m_Props),wxConvUTF8));

}

bool BlockDialog::evaluate() {
  if( m_Props == NULL )
    return false;

  iONode model  = wxGetApp().getModel();
  iONode bklist = wPlan.getbklist( model );

  if( existID( this, bklist, m_Props, m_ID->GetValue() ) ) {
    m_ID->SetValue( wxString(wItem.getid( m_Props ),wxConvUTF8) );
    return false;
  }
  // General
  wItem.setprev_id( m_Props, wItem.getid(m_Props) );
  wBlock.setid( m_Props, m_ID->GetValue().mb_str(wxConvUTF8) );
  wBlock.setdesc ( m_Props, m_Description->GetValue().mb_str(wxConvUTF8) );
  wBlock.setlen( m_Props, atoi( m_Length->GetValue().mb_str(wxConvUTF8) ) );
  wBlock.setdepartdelay( m_Props, m_DepartDelay->GetValue() );
  wBlock.setfifosize( m_Props, m_FifoSize->GetValue() );
  wBlock.setrandomrate( m_Props, m_RandomRate->GetValue() );

  wBlock.setelectrified( m_Props, m_Electrified->GetValue()?True:False );
  wBlock.setstate      ( m_Props, m_Closed->GetValue()?wBlock.closed:wBlock.open );
  //wBlock.setcritical   ( m_Props, m_Critical->GetValue()?True:False );
  wBlock.setgomanual   ( m_Props, m_GoManual->GetValue()?True:False );
  wBlock.setacceptghost( m_Props, m_AcceptGhost->GetValue()?True:False );
  wBlock.setacceptident( m_Props, m_AcceptIdent->GetValue()?True:False );
  wBlock.setterminalstation( m_Props, m_Swapplacing->GetValue()?True:False );
  wBlock.setwait( m_Props, m_WaitFlag->GetValue()?True:False );
  wItem.setroad( m_Props, m_Road->IsChecked()?True:False );
  wBlock.setallowchgdir( m_Props, m_AllowChgDir->GetValue()?True:False );
  wBlock.setsmallsymbol( m_Props, m_SmallSymbol->IsChecked()?True:False );
  wBlock.setextstop( m_Props , m_ExtStop->GetValue() ? True:False);
  wBlock.setallowbbt( m_Props , m_AllowBBT->GetValue() ? True:False);
  wBlock.setmainline( m_Props , m_MainLine->GetValue() ? True:False);
  wBlock.setsleeponclosed( m_Props , m_SleepOnClosed->GetValue() ? True:False);
  wBlock.setfreeblockonenter( m_Props , m_FreeBlockOnEnter->GetValue() ? True:False);

  if( m_Commuter->GetSelection() == 0 )
    wBlock.setcommuter( m_Props, wBlock.commuter_no );
  else if( m_Commuter->GetSelection() == 1 )
    wBlock.setcommuter( m_Props, wBlock.commuter_yes );
  else if( m_Commuter->GetSelection() == 2 )
    wBlock.setcommuter( m_Props, wBlock.commuter_only );

  wItem.setshow( m_Props, m_Show->IsChecked() ? True:False);
  wBlock.setvirtual( m_Props, m_Virtual->IsChecked() ? True:False);
  wBlock.setslaveblocks( m_Props, m_SlaveBlocks->GetValue().mb_str(wxConvUTF8) );


  // Location
  wBlock.setx( m_Props, atoi( m_x->GetValue().mb_str(wxConvUTF8) ) );
  wBlock.sety( m_Props, atoi( m_y->GetValue().mb_str(wxConvUTF8) ) );
  wBlock.setz( m_Props, atoi( m_z->GetValue().mb_str(wxConvUTF8) ) );

  /*
  int ori = m_ori->GetSelection();
  if( ori == 0 )
    wBlock.setori( m_Props, wItem.north );
  else if( ori == 1 )
    wBlock.setori( m_Props, wItem.east );
  else if( ori == 2 )
    wBlock.setori( m_Props, wItem.south );
  else if( ori == 3 )
    wBlock.setori( m_Props, wItem.west );
  */

  // Turntable
  if( StrOp.equals( "-", m_TurntableID->GetStringSelection().mb_str(wxConvUTF8) ) )
    wBlock.setttid( m_Props, "" );
  else
    wBlock.setttid( m_Props, m_TurntableID->GetStringSelection().mb_str(wxConvUTF8) );

  // Signals

  if( StrOp.equals( "-", m_Signal->GetStringSelection().mb_str(wxConvUTF8) ) )
    wBlock.setsignal( m_Props, "" );
  else
    wBlock.setsignal( m_Props, m_Signal->GetStringSelection().mb_str(wxConvUTF8) );

  if( StrOp.equals( "-", m_WSignal->GetStringSelection().mb_str(wxConvUTF8) ) )
    wBlock.setwsignal( m_Props, "" );
  else
    wBlock.setwsignal( m_Props, m_WSignal->GetStringSelection().mb_str(wxConvUTF8) );

  if( StrOp.equals( "-", m_SignalR->GetStringSelection().mb_str(wxConvUTF8) ) )
    wBlock.setsignalR( m_Props, "" );
  else
    wBlock.setsignalR( m_Props, m_SignalR->GetStringSelection().mb_str(wxConvUTF8) );

  if( StrOp.equals( "-", m_WSignalR->GetStringSelection().mb_str(wxConvUTF8) ) )
    wBlock.setwsignalR( m_Props, "" );
  else
    wBlock.setwsignalR( m_Props, m_WSignalR->GetStringSelection().mb_str(wxConvUTF8) );

  if( StrOp.equals( "-", m_StateSignal->GetStringSelection().mb_str(wxConvUTF8) ) )
    wBlock.setstatesignal( m_Props, "" );
  else
    wBlock.setstatesignal( m_Props, m_StateSignal->GetStringSelection().mb_str(wxConvUTF8) );

  wBlock.setblankatredsignal(m_Props, m_BlankAtRedSignal->IsChecked()?True:False);
  wBlock.setblankatredsignalR(m_Props, m_BlankAtRedSignal->IsChecked()?True:False);


  // Details
  if( m_Speed->GetSelection() == 0 )
    wBlock.setspeed( m_Props, wBlock.min );
  else if( m_Speed->GetSelection() == 1 )
    wBlock.setspeed( m_Props, wBlock.mid );
  else if( m_Speed->GetSelection() == 2 )
    wBlock.setspeed( m_Props, wBlock.cruise );
  else if( m_Speed->GetSelection() == 3 )
    wBlock.setspeed( m_Props, wBlock.max );
  else if( m_Speed->GetSelection() == 4 ) {
    wBlock.setspeed( m_Props, wBlock.percent );
    wBlock.setspeedpercent( m_Props, m_SpeedPercent->GetValue() );
  }
  if( m_ExitSpeed->GetSelection() == 0 )
    wBlock.setexitspeed( m_Props, wBlock.min );
  else if( m_ExitSpeed->GetSelection() == 1 )
    wBlock.setexitspeed( m_Props, wBlock.mid );
  else if( m_ExitSpeed->GetSelection() == 2 )
    wBlock.setexitspeed( m_Props, wBlock.cruise );
  else if( m_ExitSpeed->GetSelection() == 3 )
    wBlock.setexitspeed( m_Props, wBlock.max );
  else if( m_ExitSpeed->GetSelection() == 4 ) {
    wBlock.setexitspeed( m_Props, wBlock.percent );
    wBlock.setexitspeedpercent( m_Props, m_ExitSpeedPercent->GetValue() );
  }

  if( m_StopSpeed->GetSelection() == 0 )
    wBlock.setstopspeed( m_Props, wBlock.min );
  else if( m_StopSpeed->GetSelection() == 1 )
    wBlock.setstopspeed( m_Props, wBlock.mid );
  else if( m_StopSpeed->GetSelection() == 2 ) {
    wBlock.setstopspeed( m_Props, wBlock.percent );
    wBlock.setspeedpercent( m_Props, m_SpeedPercent->GetValue() );
  }

  if( m_Type->GetSelection() == 0 )
    wBlock.settype( m_Props, wBlock.type_none );
  else if( m_Type->GetSelection() == 1 )
    wBlock.settype( m_Props, wBlock.type_local );
  else if( m_Type->GetSelection() == 2 )
    wBlock.settype( m_Props, wBlock.type_ice );
  else if( m_Type->GetSelection() == 3 )
    wBlock.settype( m_Props, wBlock.type_goods );
  else if( m_Type->GetSelection() == 4 )
    wBlock.settype( m_Props, wBlock.type_shunting );
  else if( m_Type->GetSelection() == 5 )
    wBlock.settype( m_Props, wBlock.type_turntable );
  else if( m_Type->GetSelection() == 6 )
    wBlock.settype( m_Props, wBlock.type_regional );
  else if( m_Type->GetSelection() == 7 )
    wBlock.settype( m_Props, wBlock.type_light );
  else if( m_Type->GetSelection() == 8 )
    wBlock.settype( m_Props, wBlock.type_lightgoods );
  else if( m_Type->GetSelection() == 9 )
    wBlock.settype( m_Props, wBlock.type_post );

  if( m_Incline->GetSelection() == 0 )
    wBlock.setincline( m_Props, wBlock.incline_none );
  else if( m_Incline->GetSelection() == 1 )
    wBlock.setincline( m_Props, wBlock.incline_up );
  else if( m_Incline->GetSelection() == 2 )
    wBlock.setincline( m_Props, wBlock.incline_down );

  if( m_Wait->GetSelection() == 0 )
    wBlock.setwaitmode( m_Props, wBlock.wait_random );
  else if( m_Wait->GetSelection() == 1 )
    wBlock.setwaitmode( m_Props, wBlock.wait_fixed );
  else if( m_Wait->GetSelection() == 2 )
    wBlock.setwaitmode( m_Props, wBlock.wait_loc );
  else
    wBlock.setwait( m_Props, False );

  wBlock.setmaxkmh(m_Props, m_MaxKmH->GetValue());

  wBlock.setminwaittime( m_Props, atoi( m_RandomMin->GetValue().mb_str(wxConvUTF8) ) );
  wBlock.setmaxwaittime( m_Props, atoi( m_RandomMax->GetValue().mb_str(wxConvUTF8) ) );
  wBlock.setwaittime( m_Props, atoi( m_Fixed->GetValue().mb_str(wxConvUTF8) ) );

  wBlock.setmvscale( m_Props, atoi( m_Scale->GetValue().mb_str(wxConvUTF8) ) );
  wBlock.setmvdistance( m_Props, atoi( m_Distance->GetValue().mb_str(wxConvUTF8) ) );
  wBlock.setmvmph( m_Props, m_MPH->IsChecked()?True:False );

  wBlock.setevttimer( m_Props, atoi( m_Timer->GetValue().mb_str(wxConvUTF8) ) );
  wBlock.setevttimer2( m_Props, atoi( m_Timer2->GetValue().mb_str(wxConvUTF8) ) );
  wBlock.setforceblocktimer(m_Props, m_ForceBlockTimer->IsChecked()?True:False);
  wBlock.setselectshortestblock( m_Props, m_SelectShortestBlock->IsChecked() ? True:False );

  // Interface
  wBlock.setiid( m_Props, m_iid->GetValue().mb_str(wxConvUTF8) );
  wBlock.setaddr( m_Props, atoi( m_Address->GetValue().mb_str(wxConvUTF8) ) );
  wBlock.setport( m_Props, atoi( m_Port->GetValue().mb_str(wxConvUTF8) ) );
  wBlock.settd( m_Props, m_TD->GetValue()?True:False );

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

  if( permtype != NULL ) {
    wBlock.settypeperm( m_Props, permtype );
    StrOp.free(permtype);
  }
  else {
    wBlock.settypeperm( m_Props, "" );
  }

  wBlock.setclass(m_Props, m_Class->GetValue().mb_str(wxConvUTF8) );


  // remove un used events
  iONode fb = wBlock.getfbevent( m_Props );
  iOList delList = ListOp.inst();
  while( fb != NULL ) {
    TraceOp.trc( "blockdlg", TRCLEVEL_INFO, __LINE__, 9999, "check usaged of fbevent from %s...", wFeedbackEvent.getfrom( fb ) );
    bool hasRoute = false;

    int cnt = m_Routes->GetCount();
    for( int i = 0; i < cnt; i++ ) {
      iONode st = (iONode)m_Routes->GetClientData(i);
      if( st == NULL )
        continue;

      const char* fromID = wRoute.getbka( st );
      if( fromID == NULL )
        continue;

      TraceOp.trc( "blockdlg", TRCLEVEL_INFO, __LINE__, 9999, "fromID %s", fromID );
      if( StrOp.equals( wFeedbackEvent.from_all, wFeedbackEvent.getfrom( fb ) ) ||
          StrOp.equals( wFeedbackEvent.from_all_reverse, wFeedbackEvent.getfrom( fb ) ) ||
          StrOp.equals( fromID, wFeedbackEvent.getfrom( fb ) ) )
      {
        hasRoute = true;
        break;
      }
    }

    /*
      <fbevent id="RM_B5" action="enter2in" from="all-reverse" byroute="all-reverse" endpuls="false" use_timer2="false"/>
      <fbevent id="RM_B5" action="enter2in" from="all" byroute="all" endpuls="false" use_timer2="false"/>
      <fbevent id="RM_B5" action="enter2in" from="B4" byroute="autogen-[B4+]-[B5-]" endpuls="false" use_timer2="false"/>
      <fbevent id="RM_B5" action="enter2in" from="B4" byroute="autogen-[B4-]-[B5+]" endpuls="false" use_timer2="false"/>
     */
    const char* byroute = wFeedbackEvent.getbyroute(fb);
    if( byroute != NULL && StrOp.len(byroute) > 0 && !StrOp.equals("all", byroute) && !StrOp.equals("all-reverse", byroute)) {
      hasRoute = false;
      int cnt = m_Routes->GetCount();
      for( int i = 0; i < cnt; i++ ) {
        iONode st = (iONode)m_Routes->GetClientData(i);
        if( st == NULL )
          continue;
        if( StrOp.equals(wRoute.getid(st), wFeedbackEvent.getbyroute(fb) ) ) {
          hasRoute = true;
          break;
        }
      }
    }

    if( !hasRoute ) {
      char* msg = StrOp.fmt( wxGetApp().getMsg("unusedfbevent").mb_str(wxConvUTF8), wFeedbackEvent.getbyroute( fb ) );

      int rc = wxMessageDialog( this, wxString(msg,wxConvUTF8),
          wxGetApp().getMsg("blocktable"), wxYES_NO | wxICON_QUESTION ).ShowModal();
      StrOp.free(msg);
      if( rc == wxID_YES ) {
        // remove the fbevent
        ListOp.add( delList, (obj)fb );
      }
    }


    fb = wBlock.nextfbevent( m_Props, fb );
  };

  if( ListOp.size(delList) > 0 ) {
    fb = (iONode)ListOp.first( delList );
    while( fb != NULL ) {
      NodeOp.removeChild( m_Props, fb );
      NodeOp.base.del(fb);
      fb = (iONode)ListOp.next( delList );
    };
  }
  ListOp.base.del(delList);

  return true;
}

/*!
 * BlockDialog creator
 */

bool BlockDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin BlockDialog member initialisation
    m_Notebook = NULL;
    m_IndexPanel = NULL;
    m_List2 = NULL;
    m_New = NULL;
    m_Delete = NULL;
    m_Doc = NULL;
    m_General_Panel = NULL;
    m_label_ID = NULL;
    m_ID = NULL;
    m_Label_Description = NULL;
    m_Description = NULL;
    m_Label_Length = NULL;
    m_Length = NULL;
    m_labDepartDelay = NULL;
    m_DepartDelay = NULL;
    m_labFifoSize = NULL;
    m_FifoSize = NULL;
    m_labFifoSizeAutomobiles = NULL;
    m_labRandomRate = NULL;
    m_RandomRate = NULL;
    m_LabelLocID = NULL;
    m_LocID = NULL;
    m_LocProps = NULL;
    m_labTurntableID = NULL;
    m_TurntableID = NULL;
    m_VirtualBox = NULL;
    m_Virtual = NULL;
    m_labSlaveBlocks = NULL;
    m_SlaveBlocks = NULL;
    m_Configuration = NULL;
    m_Electrified = NULL;
    m_Closed = NULL;
    m_WaitFlag = NULL;
    m_SmallSymbol = NULL;
    m_GoManual = NULL;
    m_AcceptGhost = NULL;
    m_Swapplacing = NULL;
    m_Road = NULL;
    m_AllowChgDir = NULL;
    m_ExtStop = NULL;
    m_AcceptIdent = NULL;
    m_AllowBBT = NULL;
    m_MainLine = NULL;
    m_SleepOnClosed = NULL;
    m_FreeBlockOnEnter = NULL;
    m_Show = NULL;
    m_BlockActions = NULL;
    m_LocationPanel = NULL;
    m_Location = NULL;
    m_LabelX = NULL;
    m_x = NULL;
    m_LabelY = NULL;
    m_y = NULL;
    m_LabelZ = NULL;
    m_z = NULL;
    m_Ori = NULL;
    m_PanelWirering = NULL;
    m_ForwardSignalsBox = NULL;
    m_LabelSignal = NULL;
    m_Signal = NULL;
    m_SignalProps = NULL;
    m_LabelWSignal = NULL;
    m_WSignal = NULL;
    m_WSignalProps = NULL;
    m_BlankAtRedSignal = NULL;
    m_ReverseSignalsBox = NULL;
    m_LabelSignalR = NULL;
    m_SignalR = NULL;
    m_SignalPropsR = NULL;
    m_LabelWSignalR = NULL;
    m_WSignalR = NULL;
    m_WSignalPropsR = NULL;
    m_BlankAtRedSignalR = NULL;
    m_SpecialSignalBox = NULL;
    m_labStateSignal = NULL;
    m_StateSignal = NULL;
    m_StateSignalProps = NULL;
    m_PanelDetails = NULL;
    m_Incline = NULL;
    m_Wait = NULL;
    m_WaitDetails = NULL;
    m_LabelRandomMin = NULL;
    m_RandomMin = NULL;
    m_LabelRandomMax = NULL;
    m_RandomMax = NULL;
    m_LabelFixed = NULL;
    m_Fixed = NULL;
    m_Measurement = NULL;
    m_labScale = NULL;
    m_Scale = NULL;
    m_labDistance = NULL;
    m_Distance = NULL;
    m_MPH = NULL;
    m_SpeedBox = NULL;
    m_Speed = NULL;
    m_SpeedPercent = NULL;
    m_ExitSpeed = NULL;
    m_ExitSpeedPercent = NULL;
    m_StopSpeed = NULL;
    m_labMaxKmH = NULL;
    m_MaxKmH = NULL;
    m_Type = NULL;
    m_RoutesPanel = NULL;
    m_Routes = NULL;
    m_LabelSensorsFromBlock = NULL;
    m_LabelSensorIDs = NULL;
    m_LabelSensorActions = NULL;
    m_LabelSensorEnd = NULL;
    m_labTim2 = NULL;
    m_LabelProps = NULL;
    m_SensorID1 = NULL;
    m_SensorAction1 = NULL;
    m_SensorEnd1 = NULL;
    m_Tim2_1 = NULL;
    m_SensorProps1 = NULL;
    m_SensorID2 = NULL;
    m_SensorAction2 = NULL;
    m_SensorEnd2 = NULL;
    m_Tim2_2 = NULL;
    m_SensorProps2 = NULL;
    m_SensorID3 = NULL;
    m_SensorAction3 = NULL;
    m_SensorEnd3 = NULL;
    m_Tim2_3 = NULL;
    m_SensorProps3 = NULL;
    m_SensorID4 = NULL;
    m_SensorAction4 = NULL;
    m_SensorEnd4 = NULL;
    m_Tim2_4 = NULL;
    m_SensorProps4 = NULL;
    m_SensorID5 = NULL;
    m_SensorAction5 = NULL;
    m_SensorEnd5 = NULL;
    m_Tim2_5 = NULL;
    m_SensorProps5 = NULL;
    m_labTimer = NULL;
    m_Timer = NULL;
    m_labTimerMS = NULL;
    m_labTimer2 = NULL;
    m_Timer2 = NULL;
    m_labTimer2MS = NULL;
    m_ForceBlockTimer = NULL;
    m_SelectShortestBlock = NULL;
    m_RouteProps = NULL;
    m_RouteTest = NULL;
    m_Interface = NULL;
    m_TD = NULL;
    m_Labeliid = NULL;
    m_iid = NULL;
    m_LabelAddress = NULL;
    m_Address = NULL;
    m_LabelPort = NULL;
    m_Port = NULL;
    m_PermissionsPanel = NULL;
    m_labLocoListPerm = NULL;
    m_LocoListPerm = NULL;
    m_AddInclude = NULL;
    m_AddExclude = NULL;
    m_labInclude = NULL;
    m_IncludeList = NULL;
    m_RemoveInclude = NULL;
    m_IncludeRandomRate = NULL;
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
    m_Commuter = NULL;
    m_labClass = NULL;
    m_Class = NULL;
    m_Cancel = NULL;
    m_Apply = NULL;
    m_OK = NULL;
////@end BlockDialog member initialisation

////@begin BlockDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end BlockDialog creation
    return true;
}

/*!
 * Control creation for BlockDialog
 */

void BlockDialog::CreateControls()
{
////@begin BlockDialog content construction
    BlockDialog* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    m_Notebook = new wxNotebook( itemDialog1, ID_NOTEBOOK_BLOCKS, wxDefaultPosition, wxDefaultSize, wxBK_DEFAULT|m_TabAlign );

    m_IndexPanel = new wxPanel( m_Notebook, ID_PANEL_INDEX_BLOCKS, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxVERTICAL);
    m_IndexPanel->SetSizer(itemBoxSizer5);

    m_List2 = new wxListCtrl( m_IndexPanel, ID_LISTCTRLINDEX_BK, wxDefaultPosition, wxSize(100, 100), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES );
    itemBoxSizer5->Add(m_List2, 1, wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer7 = new wxFlexGridSizer(0, 3, 0, 0);
    itemBoxSizer5->Add(itemFlexGridSizer7, 0, wxGROW|wxALL, 5);
    m_New = new wxButton( m_IndexPanel, ID_BUTTON_BLOCK_NEW, _("New"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_New, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Delete = new wxButton( m_IndexPanel, ID_BUTTON_BLOCK_DELETE, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_Delete, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Doc = new wxButton( m_IndexPanel, ID_BLOCK_DOC, _("Doc"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_Doc, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Notebook->AddPage(m_IndexPanel, _("Index"));

    m_General_Panel = new wxPanel( m_Notebook, ID_PANEL_BK_GENERAL, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
    m_General_Panel->SetSizer(itemBoxSizer12);

    wxBoxSizer* itemBoxSizer13 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer12->Add(itemBoxSizer13, 1, wxALIGN_TOP|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer14 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer13->Add(itemFlexGridSizer14, 0, wxGROW|wxALL, 5);
    m_label_ID = new wxStaticText( m_General_Panel, wxID_STATIC_ID_BLOCK, _("ID:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer14->Add(m_label_ID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ID = new wxTextCtrl( m_General_Panel, ID_TEXTCTRL_ID_BLOCK, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer14->Add(m_ID, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Label_Description = new wxStaticText( m_General_Panel, wxID_STATIC_DESCRIPTION_BLOCK, _("Description:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer14->Add(m_Label_Description, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Description = new wxTextCtrl( m_General_Panel, ID_TEXTCTRL_DESCRIPTION_BLOCK, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer14->Add(m_Description, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Label_Length = new wxStaticText( m_General_Panel, wxID_STATIC_LENGTH_BLOCK, _("Length:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer14->Add(m_Label_Length, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Length = new wxTextCtrl( m_General_Panel, ID_TEXTCTRL_LENGTH_BLOCK, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer14->Add(m_Length, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labDepartDelay = new wxStaticText( m_General_Panel, wxID_ANY, _("Depart delay:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer14->Add(m_labDepartDelay, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_DepartDelay = new wxSpinCtrl( m_General_Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 0, 60, 0 );
    itemFlexGridSizer14->Add(m_DepartDelay, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labFifoSize = new wxStaticText( m_General_Panel, wxID_ANY, _("FiFo size"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer14->Add(m_labFifoSize, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer24 = new wxFlexGridSizer(0, 2, 0, 0);
    itemFlexGridSizer14->Add(itemFlexGridSizer24, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    m_FifoSize = new wxSpinCtrl( m_General_Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 0, 100, 0 );
    itemFlexGridSizer24->Add(m_FifoSize, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labFifoSizeAutomobiles = new wxStaticText( m_General_Panel, wxID_ANY, _("Automibile"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer24->Add(m_labFifoSizeAutomobiles, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labRandomRate = new wxStaticText( m_General_Panel, wxID_ANY, _("Random rate"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer14->Add(m_labRandomRate, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_RandomRate = new wxSpinCtrl( m_General_Panel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 0, 1000, 0 );
    itemFlexGridSizer14->Add(m_RandomRate, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer14->AddGrowableCol(1);

    wxFlexGridSizer* itemFlexGridSizer29 = new wxFlexGridSizer(0, 3, 0, 0);
    itemBoxSizer13->Add(itemFlexGridSizer29, 0, wxGROW|wxALL, 5);
    m_LabelLocID = new wxStaticText( m_General_Panel, wxID_STATIC_BK_LOCID, _("LocID:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer29->Add(m_LabelLocID, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LocID = new wxTextCtrl( m_General_Panel, ID_TEXTCTRL_BK_LOCID, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemFlexGridSizer29->Add(m_LocID, 2, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LocProps = new wxButton( m_General_Panel, ID_BUTTON_BK_LOCPROPS, _("..."), wxDefaultPosition, wxSize(40, -1), 0 );
    itemFlexGridSizer29->Add(m_LocProps, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labTurntableID = new wxStaticText( m_General_Panel, wxID_ANY, _("Turntable ID:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer29->Add(m_labTurntableID, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_TurntableIDStrings;
    m_TurntableID = new wxChoice( m_General_Panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_TurntableIDStrings, 0 );
    itemFlexGridSizer29->Add(m_TurntableID, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer29->AddGrowableCol(1);

    m_VirtualBox = new wxStaticBox(m_General_Panel, wxID_ANY, _("Virtual"));
    wxStaticBoxSizer* itemStaticBoxSizer35 = new wxStaticBoxSizer(m_VirtualBox, wxVERTICAL);
    itemBoxSizer13->Add(itemStaticBoxSizer35, 0, wxGROW|wxALL, 5);
    m_Virtual = new wxCheckBox( m_General_Panel, wxID_ANY, _("Virtual"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Virtual->SetValue(false);
    itemStaticBoxSizer35->Add(m_Virtual, 0, wxALIGN_LEFT|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer37 = new wxFlexGridSizer(0, 2, 0, 0);
    itemStaticBoxSizer35->Add(itemFlexGridSizer37, 0, wxGROW, 5);
    m_labSlaveBlocks = new wxStaticText( m_General_Panel, wxID_ANY, _("Slave blocks"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer37->Add(m_labSlaveBlocks, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SlaveBlocks = new wxTextCtrl( m_General_Panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer37->Add(m_SlaveBlocks, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer37->AddGrowableCol(1);

    wxStaticLine* itemStaticLine40 = new wxStaticLine( m_General_Panel, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    itemBoxSizer12->Add(itemStaticLine40, 0, wxGROW|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer41Static = new wxStaticBox(m_General_Panel, wxID_ANY_BK_CONFIG, _("Configuration"));
    m_Configuration = new wxStaticBoxSizer(itemStaticBoxSizer41Static, wxVERTICAL);
    itemBoxSizer12->Add(m_Configuration, 0, wxALIGN_TOP|wxALL, 5);
    wxBoxSizer* itemBoxSizer42 = new wxBoxSizer(wxHORIZONTAL);
    m_Configuration->Add(itemBoxSizer42, 0, wxALIGN_LEFT|wxALL, 5);
    wxBoxSizer* itemBoxSizer43 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer42->Add(itemBoxSizer43, 0, wxGROW|wxALL, 5);
    m_Electrified = new wxCheckBox( m_General_Panel, ID_CHECKBOX_BK_ELECTRIFIED, _("Electrified"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_Electrified->SetValue(false);
    itemBoxSizer43->Add(m_Electrified, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_Closed = new wxCheckBox( m_General_Panel, ID_CHECKBOX_BK_CLOSED, _("Closed"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_Closed->SetValue(false);
    itemBoxSizer43->Add(m_Closed, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_WaitFlag = new wxCheckBox( m_General_Panel, wxID_BLOCK_WAIT, _("Wait"), wxDefaultPosition, wxDefaultSize, 0 );
    m_WaitFlag->SetValue(false);
    itemBoxSizer43->Add(m_WaitFlag, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_SmallSymbol = new wxCheckBox( m_General_Panel, wxID_ANY, _("Small symbol"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SmallSymbol->SetValue(false);
    itemBoxSizer43->Add(m_SmallSymbol, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_GoManual = new wxCheckBox( m_General_Panel, ID_CHECKBOX_BK_GOMANUAL, _("Allow half-automatic"), wxDefaultPosition, wxDefaultSize, 0 );
    m_GoManual->SetValue(false);
    itemBoxSizer43->Add(m_GoManual, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_AcceptGhost = new wxCheckBox( m_General_Panel, ID_CHECKBOX_BK_ACCGHOST, _("Accept Ghosttrain"), wxDefaultPosition, wxDefaultSize, 0 );
    m_AcceptGhost->SetValue(false);
    itemBoxSizer43->Add(m_AcceptGhost, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_Swapplacing = new wxCheckBox( m_General_Panel, wxID_ANY, _("Terminal station"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Swapplacing->SetValue(false);
    itemBoxSizer43->Add(m_Swapplacing, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_Road = new wxCheckBox( m_General_Panel, wxID_ANY, _("Road"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Road->SetValue(false);
    itemBoxSizer43->Add(m_Road, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_AllowChgDir = new wxCheckBox( m_General_Panel, wxID_ANY, _("allowchgdir"), wxDefaultPosition, wxDefaultSize, 0 );
    m_AllowChgDir->SetValue(false);
    itemBoxSizer43->Add(m_AllowChgDir, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_ExtStop = new wxCheckBox( m_General_Panel, wxID_ANY, _("Stop module"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ExtStop->SetValue(false);
    itemBoxSizer43->Add(m_ExtStop, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_AcceptIdent = new wxCheckBox( m_General_Panel, wxID_ANY, _("Accept Ident"), wxDefaultPosition, wxDefaultSize, 0 );
    m_AcceptIdent->SetValue(false);
    itemBoxSizer43->Add(m_AcceptIdent, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_AllowBBT = new wxCheckBox( m_General_Panel, wxID_ANY, _("BBT"), wxDefaultPosition, wxDefaultSize, 0 );
    m_AllowBBT->SetValue(false);
    itemBoxSizer43->Add(m_AllowBBT, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_MainLine = new wxCheckBox( m_General_Panel, wxID_ANY, _("Main line"), wxDefaultPosition, wxDefaultSize, 0 );
    m_MainLine->SetValue(false);
    itemBoxSizer43->Add(m_MainLine, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_SleepOnClosed = new wxCheckBox( m_General_Panel, wxID_ANY, _("Sleep on closed"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SleepOnClosed->SetValue(false);
    itemBoxSizer43->Add(m_SleepOnClosed, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_FreeBlockOnEnter = new wxCheckBox( m_General_Panel, wxID_ANY, _("Free previous block on enter"), wxDefaultPosition, wxDefaultSize, 0 );
    m_FreeBlockOnEnter->SetValue(false);
    itemBoxSizer43->Add(m_FreeBlockOnEnter, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_Show = new wxCheckBox( m_General_Panel, wxID_ANY, _("Show"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Show->SetValue(false);
    itemBoxSizer43->Add(m_Show, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_BlockActions = new wxButton( m_General_Panel, ID_BUTTON_BLOCK_ACTIONS, _("Actions..."), wxDefaultPosition, wxDefaultSize, 0 );
    m_Configuration->Add(m_BlockActions, 0, wxALIGN_LEFT|wxALL, 5);

    m_Notebook->AddPage(m_General_Panel, _("General"));

    m_LocationPanel = new wxPanel( m_Notebook, ID_PANEL_BK_LOCATION, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer62 = new wxBoxSizer(wxHORIZONTAL);
    m_LocationPanel->SetSizer(itemBoxSizer62);

    wxStaticLine* itemStaticLine63 = new wxStaticLine( m_LocationPanel, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    itemBoxSizer62->Add(itemStaticLine63, 0, wxGROW|wxALL, 5);

    m_Location = new wxStaticBox(m_LocationPanel, wxID_ANY, _("Location"));
    wxStaticBoxSizer* itemStaticBoxSizer64 = new wxStaticBoxSizer(m_Location, wxVERTICAL);
    itemBoxSizer62->Add(itemStaticBoxSizer64, 0, wxALIGN_TOP|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer65 = new wxFlexGridSizer(0, 4, 0, 0);
    itemStaticBoxSizer64->Add(itemFlexGridSizer65, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
    m_LabelX = new wxStaticText( m_LocationPanel, wxID_ANY, _("x"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer65->Add(m_LabelX, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_x = new wxTextCtrl( m_LocationPanel, ID_TEXTCTRL, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer65->Add(m_x, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelY = new wxStaticText( m_LocationPanel, wxID_ANY, _("y"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer65->Add(m_LabelY, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_y = new wxTextCtrl( m_LocationPanel, ID_TEXTCTRL1, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer65->Add(m_y, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelZ = new wxStaticText( m_LocationPanel, wxID_ANY, _("z"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer65->Add(m_LabelZ, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_z = new wxTextCtrl( m_LocationPanel, ID_TEXTCTRL2, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer65->Add(m_z, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText72 = new wxStaticText( m_LocationPanel, wxID_ANY, _("ori"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer65->Add(itemStaticText72, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Ori = new wxTextCtrl( m_LocationPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemFlexGridSizer65->Add(m_Ori, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Notebook->AddPage(m_LocationPanel, _("Location"));

    m_PanelWirering = new wxPanel( m_Notebook, ID_PANEL_BLOCK_WIRERING, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer75 = new wxBoxSizer(wxVERTICAL);
    m_PanelWirering->SetSizer(itemBoxSizer75);

    m_ForwardSignalsBox = new wxStaticBox(m_PanelWirering, wxID_ANY, _("Forward Signals"));
    wxStaticBoxSizer* itemStaticBoxSizer76 = new wxStaticBoxSizer(m_ForwardSignalsBox, wxVERTICAL);
    itemBoxSizer75->Add(itemStaticBoxSizer76, 0, wxGROW|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer77 = new wxFlexGridSizer(0, 3, 0, 0);
    itemStaticBoxSizer76->Add(itemFlexGridSizer77, 0, wxGROW, 5);
    m_LabelSignal = new wxStaticText( m_PanelWirering, ID_STATICTEXT_BK_SIGNAL, _("Signal"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer77->Add(m_LabelSignal, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_SignalStrings;
    m_Signal = new wxComboBox( m_PanelWirering, ID_COMBOBOX_BK_SIGNAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_SignalStrings, wxCB_READONLY );
    itemFlexGridSizer77->Add(m_Signal, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SignalProps = new wxButton( m_PanelWirering, ID_BUTTON_BK_SIGNAL, _("..."), wxDefaultPosition, wxSize(35, -1), 0 );
    itemFlexGridSizer77->Add(m_SignalProps, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelWSignal = new wxStaticText( m_PanelWirering, wxID_STATIC_BK_WSIGNAL, _("Warning Signal"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer77->Add(m_LabelWSignal, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_WSignalStrings;
    m_WSignal = new wxComboBox( m_PanelWirering, ID_COMBOBOX_BK_WSIGNAL, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_WSignalStrings, wxCB_READONLY );
    itemFlexGridSizer77->Add(m_WSignal, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_WSignalProps = new wxButton( m_PanelWirering, ID_BUTTON_BK_WSIGNAL, _("..."), wxDefaultPosition, wxSize(35, -1), 0 );
    itemFlexGridSizer77->Add(m_WSignalProps, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer77->AddGrowableCol(1);

    m_BlankAtRedSignal = new wxCheckBox( m_PanelWirering, wxID_ANY, _("Blank at red main signal"), wxDefaultPosition, wxDefaultSize, 0 );
    m_BlankAtRedSignal->SetValue(false);
    itemStaticBoxSizer76->Add(m_BlankAtRedSignal, 0, wxALIGN_LEFT|wxALL, 5);

    m_ReverseSignalsBox = new wxStaticBox(m_PanelWirering, wxID_ANY, _("Reverse Signals"));
    wxStaticBoxSizer* itemStaticBoxSizer85 = new wxStaticBoxSizer(m_ReverseSignalsBox, wxVERTICAL);
    itemBoxSizer75->Add(itemStaticBoxSizer85, 0, wxGROW|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer86 = new wxFlexGridSizer(0, 3, 0, 0);
    itemStaticBoxSizer85->Add(itemFlexGridSizer86, 0, wxGROW, 5);
    m_LabelSignalR = new wxStaticText( m_PanelWirering, wxID_ANY, _("Signal"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer86->Add(m_LabelSignalR, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_SignalRStrings;
    m_SignalR = new wxComboBox( m_PanelWirering, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_SignalRStrings, wxCB_READONLY );
    itemFlexGridSizer86->Add(m_SignalR, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SignalPropsR = new wxButton( m_PanelWirering, ID_BUTTON_BK_SIGNAL_R, _("..."), wxDefaultPosition, wxSize(35, -1), 0 );
    itemFlexGridSizer86->Add(m_SignalPropsR, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelWSignalR = new wxStaticText( m_PanelWirering, wxID_ANY, _("Warning Signal"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer86->Add(m_LabelWSignalR, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_WSignalRStrings;
    m_WSignalR = new wxComboBox( m_PanelWirering, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_WSignalRStrings, wxCB_READONLY );
    itemFlexGridSizer86->Add(m_WSignalR, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_WSignalPropsR = new wxButton( m_PanelWirering, ID_BUTTON_BK_WSIGNAL_R, _("..."), wxDefaultPosition, wxSize(35, -1), 0 );
    itemFlexGridSizer86->Add(m_WSignalPropsR, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer86->AddGrowableCol(1);

    m_BlankAtRedSignalR = new wxCheckBox( m_PanelWirering, ID_CHECKBOX1, _("Blank at red main signal"), wxDefaultPosition, wxDefaultSize, 0 );
    m_BlankAtRedSignalR->SetValue(false);
    itemStaticBoxSizer85->Add(m_BlankAtRedSignalR, 0, wxALIGN_LEFT|wxALL, 5);

    m_SpecialSignalBox = new wxStaticBox(m_PanelWirering, wxID_ANY, _("Special Signals"));
    wxStaticBoxSizer* itemStaticBoxSizer94 = new wxStaticBoxSizer(m_SpecialSignalBox, wxVERTICAL);
    itemBoxSizer75->Add(itemStaticBoxSizer94, 0, wxGROW|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer95 = new wxFlexGridSizer(0, 3, 0, 0);
    itemStaticBoxSizer94->Add(itemFlexGridSizer95, 0, wxGROW, 5);
    m_labStateSignal = new wxStaticText( m_PanelWirering, wxID_ANY, _("State Signal"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer95->Add(m_labStateSignal, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_StateSignalStrings;
    m_StateSignal = new wxComboBox( m_PanelWirering, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_StateSignalStrings, wxCB_READONLY );
    itemFlexGridSizer95->Add(m_StateSignal, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_StateSignalProps = new wxButton( m_PanelWirering, ID_BK_STATESIGNAL_PROPS, _("..."), wxDefaultPosition, wxSize(35, -1), 0 );
    itemFlexGridSizer95->Add(m_StateSignalProps, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer95->AddGrowableCol(1);

    m_Notebook->AddPage(m_PanelWirering, _("Signals"));

    m_PanelDetails = new wxPanel( m_Notebook, ID_PANEL_BK_DETAILS, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer100 = new wxBoxSizer(wxHORIZONTAL);
    m_PanelDetails->SetSizer(itemBoxSizer100);

    wxBoxSizer* itemBoxSizer101 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer100->Add(itemBoxSizer101, 0, wxALIGN_TOP, 5);
    wxFlexGridSizer* itemFlexGridSizer102 = new wxFlexGridSizer(0, 4, 0, 0);
    itemBoxSizer101->Add(itemFlexGridSizer102, 0, wxGROW, 5);
    wxArrayString m_InclineStrings;
    m_InclineStrings.Add(_("&none"));
    m_InclineStrings.Add(_("&up"));
    m_InclineStrings.Add(_("&down"));
    m_Incline = new wxRadioBox( m_PanelDetails, ID_RADIOBOX_BK_INCLINE, _("Incline"), wxDefaultPosition, wxDefaultSize, m_InclineStrings, 1, wxRA_SPECIFY_COLS );
    m_Incline->SetSelection(0);
    itemFlexGridSizer102->Add(m_Incline, 0, wxALIGN_LEFT|wxALIGN_TOP|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxArrayString m_WaitStrings;
    m_WaitStrings.Add(_("&random"));
    m_WaitStrings.Add(_("&fixed"));
    m_WaitStrings.Add(_("&loc"));
    m_WaitStrings.Add(_("&no"));
    m_Wait = new wxRadioBox( m_PanelDetails, ID_RADIOBOX_BK_WAIT, _("Wait"), wxDefaultPosition, wxDefaultSize, m_WaitStrings, 1, wxRA_SPECIFY_COLS );
    m_Wait->SetSelection(0);
    itemFlexGridSizer102->Add(m_Wait, 0, wxALIGN_LEFT|wxALIGN_TOP|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxBoxSizer* itemBoxSizer105 = new wxBoxSizer(wxHORIZONTAL);
    itemFlexGridSizer102->Add(itemBoxSizer105, 0, wxALIGN_LEFT|wxALIGN_TOP, 5);
    wxStaticBox* itemStaticBoxSizer106Static = new wxStaticBox(m_PanelDetails, wxID_ANY, _("Wait details"));
    m_WaitDetails = new wxStaticBoxSizer(itemStaticBoxSizer106Static, wxHORIZONTAL);
    itemBoxSizer105->Add(m_WaitDetails, 0, wxALIGN_CENTER_VERTICAL, 5);
    wxFlexGridSizer* itemFlexGridSizer107 = new wxFlexGridSizer(0, 2, 0, 0);
    m_WaitDetails->Add(itemFlexGridSizer107, 0, wxALIGN_CENTER_VERTICAL, 5);
    m_LabelRandomMin = new wxStaticText( m_PanelDetails, wxID_STATIC_BK_RANDOM_MIN, _("Radom min:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer107->Add(m_LabelRandomMin, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_RandomMin = new wxTextCtrl( m_PanelDetails, ID_TEXTCTRL_BK_RANDOM_MIN, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer107->Add(m_RandomMin, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_LabelRandomMax = new wxStaticText( m_PanelDetails, wxID_STATIC_BK_RANDOM_MAX, _("Random max:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer107->Add(m_LabelRandomMax, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_RandomMax = new wxTextCtrl( m_PanelDetails, ID_TEXTCTRL_BK_RANDOM_MAX, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer107->Add(m_RandomMax, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_LabelFixed = new wxStaticText( m_PanelDetails, wxID_STATIC_BK_FIXED, _("Fixed:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer107->Add(m_LabelFixed, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_Fixed = new wxTextCtrl( m_PanelDetails, ID_TEXTCTRL_BK_FIXED, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer107->Add(m_Fixed, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_Measurement = new wxStaticBox(m_PanelDetails, wxID_ANY, _("Measurement"));
    wxStaticBoxSizer* itemStaticBoxSizer114 = new wxStaticBoxSizer(m_Measurement, wxVERTICAL);
    itemBoxSizer105->Add(itemStaticBoxSizer114, 0, wxALIGN_TOP, 5);
    wxFlexGridSizer* itemFlexGridSizer115 = new wxFlexGridSizer(0, 2, 0, 0);
    itemStaticBoxSizer114->Add(itemFlexGridSizer115, 0, wxALIGN_CENTER_HORIZONTAL, 5);
    m_labScale = new wxStaticText( m_PanelDetails, wxID_ANY, _("Scale"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer115->Add(m_labScale, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Scale = new wxTextCtrl( m_PanelDetails, wxID_ANY, _("87"), wxDefaultPosition, wxSize(60, -1), wxTE_CENTRE );
    itemFlexGridSizer115->Add(m_Scale, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labDistance = new wxStaticText( m_PanelDetails, wxID_ANY, _("Distance"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer115->Add(m_labDistance, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_Distance = new wxTextCtrl( m_PanelDetails, wxID_ANY, _("0"), wxDefaultPosition, wxSize(60, -1), wxTE_CENTRE );
    itemFlexGridSizer115->Add(m_Distance, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_MPH = new wxCheckBox( m_PanelDetails, wxID_ANY, _("MPH"), wxDefaultPosition, wxDefaultSize, 0 );
    m_MPH->SetValue(false);
    itemStaticBoxSizer114->Add(m_MPH, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_SpeedBox = new wxStaticBox(m_PanelDetails, wxID_ANY, _("Speed"));
    wxStaticBoxSizer* itemStaticBoxSizer121 = new wxStaticBoxSizer(m_SpeedBox, wxHORIZONTAL);
    itemBoxSizer101->Add(itemStaticBoxSizer121, 0, wxALIGN_LEFT, 5);
    wxFlexGridSizer* itemFlexGridSizer122 = new wxFlexGridSizer(0, 2, 0, 0);
    itemStaticBoxSizer121->Add(itemFlexGridSizer122, 0, wxGROW, 5);
    wxArrayString m_SpeedStrings;
    m_SpeedStrings.Add(_("&min"));
    m_SpeedStrings.Add(_("&mid"));
    m_SpeedStrings.Add(_("cruise"));
    m_SpeedStrings.Add(_("&max"));
    m_SpeedStrings.Add(_("&%"));
    m_Speed = new wxRadioBox( m_PanelDetails, ID_RADIOBOX_BK_SPEED, _("enter"), wxDefaultPosition, wxDefaultSize, m_SpeedStrings, 1, wxRA_SPECIFY_ROWS );
    m_Speed->SetSelection(0);
    itemFlexGridSizer122->Add(m_Speed, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_SpeedPercent = new wxSpinCtrl( m_PanelDetails, ID_SPINCTRL1, wxT("80"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 100, 80 );
    itemFlexGridSizer122->Add(m_SpeedPercent, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxRIGHT|wxTOP, 5);

    wxArrayString m_ExitSpeedStrings;
    m_ExitSpeedStrings.Add(_("&min"));
    m_ExitSpeedStrings.Add(_("&mid"));
    m_ExitSpeedStrings.Add(_("&cruise"));
    m_ExitSpeedStrings.Add(_("&max"));
    m_ExitSpeedStrings.Add(_("&%"));
    m_ExitSpeed = new wxRadioBox( m_PanelDetails, wxID_ANY, _("exit"), wxDefaultPosition, wxDefaultSize, m_ExitSpeedStrings, 1, wxRA_SPECIFY_ROWS );
    m_ExitSpeed->SetSelection(0);
    itemFlexGridSizer122->Add(m_ExitSpeed, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_ExitSpeedPercent = new wxSpinCtrl( m_PanelDetails, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 100, 0 );
    itemFlexGridSizer122->Add(m_ExitSpeedPercent, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxRIGHT|wxTOP, 5);

    wxArrayString m_StopSpeedStrings;
    m_StopSpeedStrings.Add(_("&min"));
    m_StopSpeedStrings.Add(_("&mid"));
    m_StopSpeedStrings.Add(_("&%"));
    m_StopSpeed = new wxRadioBox( m_PanelDetails, wxID_ANY, _("stop"), wxDefaultPosition, wxDefaultSize, m_StopSpeedStrings, 1, wxRA_SPECIFY_ROWS );
    m_StopSpeed->SetSelection(0);
    itemFlexGridSizer122->Add(m_StopSpeed, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxFlexGridSizer* itemFlexGridSizer128 = new wxFlexGridSizer(0, 2, 0, 0);
    itemFlexGridSizer122->Add(itemFlexGridSizer128, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    m_labMaxKmH = new wxStaticText( m_PanelDetails, wxID_ANY, _("Max. KmH"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer128->Add(m_labMaxKmH, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_MaxKmH = new wxSpinCtrl( m_PanelDetails, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 0, 500, 0 );
    itemFlexGridSizer128->Add(m_MaxKmH, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxArrayString m_TypeStrings;
    m_TypeStrings.Add(_("&none"));
    m_TypeStrings.Add(_("&local"));
    m_TypeStrings.Add(_("&ice"));
    m_TypeStrings.Add(_("&goods"));
    m_TypeStrings.Add(_("&shunting"));
    m_TypeStrings.Add(_("&turntable"));
    m_TypeStrings.Add(_("&Regional"));
    m_TypeStrings.Add(_("&Light"));
    m_TypeStrings.Add(_("&Light freight"));
    m_TypeStrings.Add(_("&Post"));
    m_Type = new wxRadioBox( m_PanelDetails, ID_RADIOBOX_BK_TYPE, _("Type"), wxDefaultPosition, wxDefaultSize, m_TypeStrings, 4, wxRA_SPECIFY_COLS );
    m_Type->SetSelection(0);
    itemBoxSizer101->Add(m_Type, 0, wxGROW|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_Notebook->AddPage(m_PanelDetails, _("Details"));

    m_RoutesPanel = new wxPanel( m_Notebook, ID_PANEL_BK_ROUTES, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer133 = new wxBoxSizer(wxVERTICAL);
    m_RoutesPanel->SetSizer(itemBoxSizer133);

    wxBoxSizer* itemBoxSizer134 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer133->Add(itemBoxSizer134, 1, wxGROW|wxALL, 5);
    wxArrayString m_RoutesStrings;
    m_Routes = new wxListBox( m_RoutesPanel, ID_LISTBOX_BK_ROUTES, wxDefaultPosition, wxSize(-1, 100), m_RoutesStrings, wxLB_SINGLE|wxLB_ALWAYS_SB );
    itemBoxSizer134->Add(m_Routes, 1, wxGROW|wxLEFT|wxRIGHT|wxTOP, 5);

    m_LabelSensorsFromBlock = new wxStaticText( m_RoutesPanel, wxID_STATIC_SENSORS_TITLE, _("..."), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer134->Add(m_LabelSensorsFromBlock, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 5);

    wxFlexGridSizer* itemFlexGridSizer137 = new wxFlexGridSizer(0, 5, 0, 0);
    itemBoxSizer133->Add(itemFlexGridSizer137, 0, wxGROW, 5);
    m_LabelSensorIDs = new wxStaticText( m_RoutesPanel, ID_STATICTEXT_BLOCK_SENSORID, _("Sensor ID:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer137->Add(m_LabelSensorIDs, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxTOP, 2);

    m_LabelSensorActions = new wxStaticText( m_RoutesPanel, ID_STATICTEXT_BLOCK_SENSOR_ACTION, _("Event:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer137->Add(m_LabelSensorActions, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxTOP, 2);

    m_LabelSensorEnd = new wxStaticText( m_RoutesPanel, wxID_STATIC_BLOCK_SENSOR_END, _("End"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer137->Add(m_LabelSensorEnd, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    m_labTim2 = new wxStaticText( m_RoutesPanel, wxID_ANY, _("T2"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer137->Add(m_labTim2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelProps = new wxStaticText( m_RoutesPanel, ID_STATICTEXT_BLOCK_SENSOR_FREE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer137->Add(m_LabelProps, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxTOP, 5);

    wxArrayString m_SensorID1Strings;
    m_SensorID1 = new wxComboBox( m_RoutesPanel, ID_COMBOBOX_BLOCK_SENSOR_ID1, wxEmptyString, wxDefaultPosition, wxSize(120, -1), m_SensorID1Strings, wxCB_READONLY );
    itemFlexGridSizer137->Add(m_SensorID1, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    wxArrayString m_SensorAction1Strings;
    m_SensorAction1 = new wxComboBox( m_RoutesPanel, ID_COMBOBOX_BLOCK_SENSOR_ACTION1, wxEmptyString, wxDefaultPosition, wxSize(160, -1), m_SensorAction1Strings, wxCB_READONLY );
    itemFlexGridSizer137->Add(m_SensorAction1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    m_SensorEnd1 = new wxCheckBox( m_RoutesPanel, ID_CHECKBOX_BLOCK_SENSOR_END1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_SensorEnd1->SetValue(false);
    itemFlexGridSizer137->Add(m_SensorEnd1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    m_Tim2_1 = new wxCheckBox( m_RoutesPanel, ID_BLOCK_SENS1_T2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_Tim2_1->SetValue(false);
    itemFlexGridSizer137->Add(m_Tim2_1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_SensorProps1 = new wxButton( m_RoutesPanel, ID_BUTTON_BLOCKS_SENSOR_PROPS1, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemFlexGridSizer137->Add(m_SensorProps1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    wxArrayString m_SensorID2Strings;
    m_SensorID2 = new wxComboBox( m_RoutesPanel, ID_COMBOBOX_BLOCK_SENSOR_ID2, wxEmptyString, wxDefaultPosition, wxSize(120, -1), m_SensorID2Strings, wxCB_READONLY );
    itemFlexGridSizer137->Add(m_SensorID2, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    wxArrayString m_SensorAction2Strings;
    m_SensorAction2 = new wxComboBox( m_RoutesPanel, ID_COMBOBOX_BLOCK_SENSOR_ACTION2, wxEmptyString, wxDefaultPosition, wxSize(160, -1), m_SensorAction2Strings, wxCB_READONLY );
    itemFlexGridSizer137->Add(m_SensorAction2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    m_SensorEnd2 = new wxCheckBox( m_RoutesPanel, ID_CHECKBOX_BLOCK_SENSOR_END2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_SensorEnd2->SetValue(false);
    itemFlexGridSizer137->Add(m_SensorEnd2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    m_Tim2_2 = new wxCheckBox( m_RoutesPanel, ID_BLOCK_SENS2_T2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_Tim2_2->SetValue(false);
    itemFlexGridSizer137->Add(m_Tim2_2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_SensorProps2 = new wxButton( m_RoutesPanel, ID_BUTTON_BLOCK_SENSOR_PROPS2, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemFlexGridSizer137->Add(m_SensorProps2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    wxArrayString m_SensorID3Strings;
    m_SensorID3 = new wxComboBox( m_RoutesPanel, ID_COMBOBOX_BLOCK_SENSOR_ID3, wxEmptyString, wxDefaultPosition, wxSize(120, -1), m_SensorID3Strings, wxCB_READONLY );
    itemFlexGridSizer137->Add(m_SensorID3, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    wxArrayString m_SensorAction3Strings;
    m_SensorAction3 = new wxComboBox( m_RoutesPanel, ID_COMBOBOX_BLOCK_SENSOR_ACTION3, wxEmptyString, wxDefaultPosition, wxSize(160, -1), m_SensorAction3Strings, wxCB_READONLY );
    itemFlexGridSizer137->Add(m_SensorAction3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    m_SensorEnd3 = new wxCheckBox( m_RoutesPanel, ID_CHECKBOX_BLOCK_SENSOR_END3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_SensorEnd3->SetValue(false);
    itemFlexGridSizer137->Add(m_SensorEnd3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    m_Tim2_3 = new wxCheckBox( m_RoutesPanel, ID_BLOCK_SENS3_T2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_Tim2_3->SetValue(false);
    itemFlexGridSizer137->Add(m_Tim2_3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_SensorProps3 = new wxButton( m_RoutesPanel, ID_BUTTON_BLOCKS_SENSOR_PROPS3, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemFlexGridSizer137->Add(m_SensorProps3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    wxArrayString m_SensorID4Strings;
    m_SensorID4 = new wxComboBox( m_RoutesPanel, ID_COMBOBOX_BLOCK_SENSOR_ID4, wxEmptyString, wxDefaultPosition, wxSize(120, -1), m_SensorID4Strings, wxCB_READONLY );
    itemFlexGridSizer137->Add(m_SensorID4, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    wxArrayString m_SensorAction4Strings;
    m_SensorAction4 = new wxComboBox( m_RoutesPanel, ID_COMBOBOX_BLOCK_SENSOR_ACTION4, wxEmptyString, wxDefaultPosition, wxSize(160, -1), m_SensorAction4Strings, wxCB_READONLY );
    itemFlexGridSizer137->Add(m_SensorAction4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    m_SensorEnd4 = new wxCheckBox( m_RoutesPanel, ID_CHECKBOX_BLOCK_SENSOR_END4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_SensorEnd4->SetValue(false);
    itemFlexGridSizer137->Add(m_SensorEnd4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    m_Tim2_4 = new wxCheckBox( m_RoutesPanel, ID_BLOCK_SENS4_T2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_Tim2_4->SetValue(false);
    itemFlexGridSizer137->Add(m_Tim2_4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_SensorProps4 = new wxButton( m_RoutesPanel, ID_BUTTON_BLOCKS_SENSOR_PROPS4, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemFlexGridSizer137->Add(m_SensorProps4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    wxArrayString m_SensorID5Strings;
    m_SensorID5 = new wxComboBox( m_RoutesPanel, ID_COMBOBOX_BLOCK_SENSOR_ID5, wxEmptyString, wxDefaultPosition, wxSize(120, -1), m_SensorID5Strings, wxCB_READONLY );
    itemFlexGridSizer137->Add(m_SensorID5, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    wxArrayString m_SensorAction5Strings;
    m_SensorAction5 = new wxComboBox( m_RoutesPanel, ID_COMBOBOX_BLOCK_SENSOR_ACTION5, wxEmptyString, wxDefaultPosition, wxSize(160, -1), m_SensorAction5Strings, wxCB_READONLY );
    itemFlexGridSizer137->Add(m_SensorAction5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    m_SensorEnd5 = new wxCheckBox( m_RoutesPanel, ID_CHECKBOX_BLOCK_SENSOR_END5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_SensorEnd5->SetValue(false);
    itemFlexGridSizer137->Add(m_SensorEnd5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    m_Tim2_5 = new wxCheckBox( m_RoutesPanel, ID_BLOCK_SENS5_T2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_Tim2_5->SetValue(false);
    itemFlexGridSizer137->Add(m_Tim2_5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_SensorProps5 = new wxButton( m_RoutesPanel, ID_BUTTON_BLOCKS_SENSOR_PROPS5, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemFlexGridSizer137->Add(m_SensorProps5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 2);

    itemFlexGridSizer137->AddGrowableCol(0);

    wxBoxSizer* itemBoxSizer168 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer133->Add(itemBoxSizer168, 0, wxGROW|wxALL, 5);
    m_labTimer = new wxStaticText( m_RoutesPanel, wxID_STATIC_BK_TIMER, _("Event timer"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer168->Add(m_labTimer, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM, 5);

    m_Timer = new wxTextCtrl( m_RoutesPanel, ID_TEXTCTRL_BK_TIMER, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    m_Timer->SetMaxLength(5);
    itemBoxSizer168->Add(m_Timer, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM, 5);

    m_labTimerMS = new wxStaticText( m_RoutesPanel, wxID_ANY, _("ms"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer168->Add(m_labTimerMS, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxTOP|wxBOTTOM, 5);

    m_labTimer2 = new wxStaticText( m_RoutesPanel, wxID_ANY, _("Timer 2"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer168->Add(m_labTimer2, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM, 5);

    m_Timer2 = new wxTextCtrl( m_RoutesPanel, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    m_Timer2->SetMaxLength(5);
    itemBoxSizer168->Add(m_Timer2, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM, 5);

    m_labTimer2MS = new wxStaticText( m_RoutesPanel, wxID_ANY, _("ms"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer168->Add(m_labTimer2MS, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxTOP|wxBOTTOM, 5);

    wxStaticLine* itemStaticLine175 = new wxStaticLine( m_RoutesPanel, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    itemBoxSizer168->Add(itemStaticLine175, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer176 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer168->Add(itemBoxSizer176, 0, wxALIGN_CENTER_VERTICAL, 5);
    m_ForceBlockTimer = new wxCheckBox( m_RoutesPanel, wxID_ANY, _("Force block timer"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ForceBlockTimer->SetValue(false);
    itemBoxSizer176->Add(m_ForceBlockTimer, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_SelectShortestBlock = new wxCheckBox( m_RoutesPanel, wxID_ANY, _("Select shortest block"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SelectShortestBlock->SetValue(false);
    itemBoxSizer176->Add(m_SelectShortestBlock, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxFlexGridSizer* itemFlexGridSizer179 = new wxFlexGridSizer(0, 3, 0, 0);
    itemBoxSizer133->Add(itemFlexGridSizer179, 0, wxGROW|wxALL, 5);
    m_RouteProps = new wxButton( m_RoutesPanel, ID_BUTTON1, _("Properties..."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer179->Add(m_RouteProps, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_RouteTest = new wxButton( m_RoutesPanel, ID_BUTTON2, _("Test"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer179->Add(m_RouteTest, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer179->AddGrowableCol(0);

    m_Notebook->AddPage(m_RoutesPanel, _("Routes"));

    m_Interface = new wxPanel( m_Notebook, ID_PANEL_BK_INTERFACE, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer183 = new wxBoxSizer(wxVERTICAL);
    m_Interface->SetSizer(itemBoxSizer183);

    m_TD = new wxCheckBox( m_Interface, ID_CHECKBOX_BKTD, _("TrackDriver"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_TD->SetValue(false);
    itemBoxSizer183->Add(m_TD, 0, wxALIGN_LEFT|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer185 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer183->Add(itemFlexGridSizer185, 0, wxGROW|wxALL, 5);
    m_Labeliid = new wxStaticText( m_Interface, wxID_STATIC_BK_IID, _("iid"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer185->Add(m_Labeliid, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_iidStrings;
    m_iid = new wxComboBox( m_Interface, ID_TEXTCTRL_BK_IID, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_iidStrings, wxCB_DROPDOWN );
    itemFlexGridSizer185->Add(m_iid, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelAddress = new wxStaticText( m_Interface, wxID_STATIC_BK_ADDRESS, _("address"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer185->Add(m_LabelAddress, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Address = new wxTextCtrl( m_Interface, ID_TEXTCTRL_BK_ADDRESS, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer185->Add(m_Address, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelPort = new wxStaticText( m_Interface, wxID_STATIC_BK_PORT, _("port"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer185->Add(m_LabelPort, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Port = new wxTextCtrl( m_Interface, ID_TEXTCTRL_BK_PORT, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer185->Add(m_Port, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer185->AddGrowableCol(1);

    m_Notebook->AddPage(m_Interface, _("Interface"));

    m_PermissionsPanel = new wxPanel( m_Notebook, ID__PANEL_BK_PERMISSIONS, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer193 = new wxBoxSizer(wxVERTICAL);
    m_PermissionsPanel->SetSizer(itemBoxSizer193);

    wxBoxSizer* itemBoxSizer194 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer193->Add(itemBoxSizer194, 1, wxGROW|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer195 = new wxFlexGridSizer(0, 1, 0, 0);
    itemBoxSizer194->Add(itemFlexGridSizer195, 1, wxGROW, 5);
    m_labLocoListPerm = new wxStaticText( m_PermissionsPanel, wxID_ANY, _("Locos"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer195->Add(m_labLocoListPerm, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxArrayString m_LocoListPermStrings;
    m_LocoListPerm = new wxListBox( m_PermissionsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_LocoListPermStrings, wxLB_SINGLE );
    itemFlexGridSizer195->Add(m_LocoListPerm, 0, wxGROW|wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer198 = new wxFlexGridSizer(0, 2, 0, 0);
    itemFlexGridSizer195->Add(itemFlexGridSizer198, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    m_AddInclude = new wxButton( m_PermissionsPanel, ID_ADD_INCLUDE, _("Include"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer198->Add(m_AddInclude, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_AddExclude = new wxButton( m_PermissionsPanel, ID_ADD_EXCLUDE, _("exclude"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer198->Add(m_AddExclude, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer195->AddGrowableRow(1);
    itemFlexGridSizer195->AddGrowableCol(0);

    wxFlexGridSizer* itemFlexGridSizer201 = new wxFlexGridSizer(0, 1, 0, 0);
    itemBoxSizer194->Add(itemFlexGridSizer201, 1, wxGROW, 5);
    m_labInclude = new wxStaticText( m_PermissionsPanel, wxID_ANY, _("Include"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer201->Add(m_labInclude, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxArrayString m_IncludeListStrings;
    m_IncludeList = new wxListBox( m_PermissionsPanel, ID_INCLUDE_LIST, wxDefaultPosition, wxDefaultSize, m_IncludeListStrings, wxLB_SINGLE );
    itemFlexGridSizer201->Add(m_IncludeList, 0, wxGROW|wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer204 = new wxFlexGridSizer(0, 2, 0, 0);
    itemFlexGridSizer201->Add(itemFlexGridSizer204, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    m_RemoveInclude = new wxButton( m_PermissionsPanel, ID_REMOVE_INCLUDE, _("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer204->Add(m_RemoveInclude, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_IncludeRandomRate = new wxSpinCtrl( m_PermissionsPanel, ID_INCLUDE_RANDOMRATE, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100000, 0 );
    itemFlexGridSizer204->Add(m_IncludeRandomRate, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    itemFlexGridSizer201->AddGrowableRow(1);
    itemFlexGridSizer201->AddGrowableCol(0);

    wxFlexGridSizer* itemFlexGridSizer207 = new wxFlexGridSizer(0, 1, 0, 0);
    itemBoxSizer194->Add(itemFlexGridSizer207, 1, wxGROW, 5);
    m_labExclude = new wxStaticText( m_PermissionsPanel, wxID_ANY, _("Exclude"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer207->Add(m_labExclude, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxArrayString m_ExcludeListStrings;
    m_ExcludeList = new wxListBox( m_PermissionsPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_ExcludeListStrings, wxLB_SINGLE );
    itemFlexGridSizer207->Add(m_ExcludeList, 0, wxGROW|wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer210 = new wxFlexGridSizer(0, 2, 0, 0);
    itemFlexGridSizer207->Add(itemFlexGridSizer210, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    m_RemoveExclude = new wxButton( m_PermissionsPanel, ID_REMOVE_EXCLUDE, _("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer210->Add(m_RemoveExclude, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer207->AddGrowableRow(1);
    itemFlexGridSizer207->AddGrowableCol(0);

    m_PermType = new wxStaticBox(m_PermissionsPanel, wxID_ANY, _("Type"));
    wxStaticBoxSizer* itemStaticBoxSizer212 = new wxStaticBoxSizer(m_PermType, wxVERTICAL);
    itemBoxSizer193->Add(itemStaticBoxSizer212, 0, wxGROW|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer213 = new wxFlexGridSizer(0, 5, 0, 0);
    itemStaticBoxSizer212->Add(itemFlexGridSizer213, 0, wxGROW, 5);
    m_PermTypeGoods = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("Goods"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypeGoods->SetValue(false);
    itemFlexGridSizer213->Add(m_PermTypeGoods, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_PermTypeMixed = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("Mixed"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypeMixed->SetValue(false);
    itemFlexGridSizer213->Add(m_PermTypeMixed, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_PermTypeICE = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("ICE"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypeICE->SetValue(false);
    itemFlexGridSizer213->Add(m_PermTypeICE, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_PermTypePerson = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("Person"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypePerson->SetValue(false);
    itemFlexGridSizer213->Add(m_PermTypePerson, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_PermTypeLightGoods = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("Light Goods"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypeLightGoods->SetValue(false);
    itemFlexGridSizer213->Add(m_PermTypeLightGoods, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_PermTypeNone = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("None"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypeNone->SetValue(false);
    itemFlexGridSizer213->Add(m_PermTypeNone, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_PermTypeLocal = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("Local"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypeLocal->SetValue(false);
    itemFlexGridSizer213->Add(m_PermTypeLocal, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_PermTypeCleaning = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("Cleaning"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypeCleaning->SetValue(false);
    itemFlexGridSizer213->Add(m_PermTypeCleaning, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_PermTypePost = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("Post"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypePost->SetValue(false);
    itemFlexGridSizer213->Add(m_PermTypePost, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_PermTypeLight = new wxCheckBox( m_PermissionsPanel, wxID_ANY, _("Light"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PermTypeLight->SetValue(false);
    itemFlexGridSizer213->Add(m_PermTypeLight, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxArrayString m_CommuterStrings;
    m_CommuterStrings.Add(_("&no"));
    m_CommuterStrings.Add(_("&yes"));
    m_CommuterStrings.Add(_("&only"));
    m_Commuter = new wxRadioBox( m_PermissionsPanel, ID_RADIOBOX_BK_COMMUTER, _("Commuter train"), wxDefaultPosition, wxDefaultSize, m_CommuterStrings, 1, wxRA_SPECIFY_ROWS );
    m_Commuter->SetSelection(0);
    itemBoxSizer193->Add(m_Commuter, 0, wxALIGN_LEFT|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer225 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer193->Add(itemFlexGridSizer225, 0, wxGROW, 5);
    m_labClass = new wxStaticText( m_PermissionsPanel, wxID_ANY, _("Class"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer225->Add(m_labClass, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Class = new wxTextCtrl( m_PermissionsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer225->Add(m_Class, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer225->AddGrowableCol(1);

    m_Notebook->AddPage(m_PermissionsPanel, _("Persmissions"));

    itemBoxSizer2->Add(m_Notebook, 1, wxGROW|wxALL, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer228 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer228, 0, wxGROW|wxALL, 5);
    m_Cancel = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer228->AddButton(m_Cancel);

    m_Apply = new wxButton( itemDialog1, wxID_APPLY, _("&Apply"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer228->AddButton(m_Apply);

    m_OK = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    m_OK->SetDefault();
    itemStdDialogButtonSizer228->AddButton(m_OK);

    wxButton* itemButton232 = new wxButton( itemDialog1, wxID_HELP, _("&Help"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer228->AddButton(itemButton232);

    itemStdDialogButtonSizer228->Realize();

////@end BlockDialog content construction
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BLOCK_NEW
 */

void BlockDialog::OnButtonBlockNewClick( wxCommandEvent& event )
{
  int i = findID("NEW");
  if( i == wxNOT_FOUND ) {
    iONode model = wxGetApp().getModel();
    if( model != NULL ) {
      iONode bklist = wPlan.getbklist( model );
      if( bklist == NULL ) {
        bklist = NodeOp.inst( wBlockList.name(), model, ELEMENT_NODE );
        NodeOp.addChild( model, bklist );
      }
      if( bklist != NULL ) {
        iONode bk = NodeOp.inst( wBlock.name(), bklist, ELEMENT_NODE );
        NodeOp.addChild( bklist, bk );
        wBlock.setid( bk, "NEW" );
        m_Props = bk;
        appendItem(bk);
        setIDSelection(wItem.getid(bk));
        initValues();
      }
    }
  }
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BLOCK_DELETE
 */

void BlockDialog::OnButtonBlockDeleteClick( wxCommandEvent& event )
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
      iONode bklist = wPlan.getbklist( model );
      if( bklist != NULL ) {
        NodeOp.removeChild( bklist, m_Props );
        m_Props = selectPrev();
      }
    }

    initIndex();
  }
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void BlockDialog::OnCancelClick( wxCommandEvent& event )
{
  EndModal( 0 );
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_APPLY
 */

void BlockDialog::OnApplyClick( wxCommandEvent& event )
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
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void BlockDialog::OnOkClick( wxCommandEvent& event )
{
  if( m_bSave )
    OnApplyClick(event);
  EndModal( wxID_OK );
}

/*!
 * Should we show tooltips?
 */

bool BlockDialog::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap BlockDialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin BlockDialog bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end BlockDialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon BlockDialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin BlockDialog icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end BlockDialog icon retrieval
}
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BK_LOCPROPS
 */

void BlockDialog::OnButtonBkLocpropsClick( wxCommandEvent& event )
{
  const char* locid = wBlock.getlocid( m_Props );
  iONode model = wxGetApp().getModel();

  if( model != NULL ) {
    iONode lclist = wPlan.getlclist( model );
    if( lclist != NULL ) {
      int cnt = NodeOp.getChildCnt( lclist );
      for( int i = 0; i < cnt; i++ ) {
        iONode lc = NodeOp.getChild( lclist, i );
        const char* id = wLoc.getid( lc );

        if( id != NULL && StrOp.equals( locid, id ) ) {
          LocDialog*  propDlg = new LocDialog(this, lc );
          if( wxID_OK == propDlg->ShowModal() ) {
            /* Notify RocRail. */
            iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
            wModelCmd.setcmd( cmd, wModelCmd.modify );
            NodeOp.addChild( cmd, (iONode)lc->base.clone( lc ) );
            wxGetApp().sendToRocrail( cmd );
            cmd->base.del(cmd);
          }
          break;
        }
      }
    }
  }
}


void BlockDialog::fbProps( const char* fbid ) {
  iONode model = wxGetApp().getModel();

  if( model != NULL ) {
    iONode fblist = wPlan.getfblist( model );
    if( fblist != NULL ) {
      int cnt = NodeOp.getChildCnt( fblist );
      for( int i = 0; i < cnt; i++ ) {
        iONode fb = NodeOp.getChild( fblist, i );
        const char* id = wFeedback.getid( fb );

        if( id != NULL && StrOp.equals( fbid, id ) ) {
          FeedbackDialog* propDlg = new FeedbackDialog(this, fb );
          if( wxID_OK == propDlg->ShowModal() ) {
            /* Notify RocRail. */
            iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
            wModelCmd.setcmd( cmd, wModelCmd.modify );
            NodeOp.addChild( cmd, (iONode)NodeOp.base.clone( fb ) );
            wxGetApp().sendToRocrail( cmd );
            cmd->base.del(cmd);
          }
          break;
        }
      }
    }
  }
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BK_SIGNAL
 */

void BlockDialog::OnButtonBkSignalRClick( wxCommandEvent& event )
{
  const char* swid = wBlock.getsignal( m_Props );
  if( swid == NULL || StrOp.len( swid ) == 0 )
    return;

  iONode model = wxGetApp().getModel();

  if( model != NULL ) {
    iONode swlist = wPlan.getswlist( model );
    if( swlist != NULL ) {
      int cnt = NodeOp.getChildCnt( swlist );
      for( int i = 0; i < cnt; i++ ) {
        iONode sw = NodeOp.getChild( swlist, i );
        const char* id = wSwitch.getid( sw );

        if( id != NULL && StrOp.equals( swid, id ) ) {
          SwitchDialog* propDlg = new SwitchDialog(this, sw );
          if( wxID_OK == propDlg->ShowModal() ) {
            /* Notify RocRail. */
            iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
            wModelCmd.setcmd( cmd, wModelCmd.modify );
            NodeOp.addChild( cmd, (iONode)NodeOp.base.clone( sw ) );
            wxGetApp().sendToRocrail( cmd );
            cmd->base.del(cmd);
          }
          break;
        }
      }
    }
  }
}


/*!
 * wxEVT_COMMAND_LISTBOX_SELECTED event handler for ID_LISTBOX_COMMANDS
 */

void BlockDialog::OnListboxBkRoutesSelected( wxCommandEvent& event )
{
  m_iRouteSelection = m_Routes->GetSelection();
  TraceOp.trc( "blockdlg", TRCLEVEL_INFO, __LINE__, 9999, "RouteSelection=%d", m_iRouteSelection );
  initSensors();
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_ST_ADD
 */

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BK_ROUTE_PROPS
 */

void BlockDialog::OnButtonBkRoutePropsClick( wxCommandEvent& event )
{
  int idx = m_Routes->GetSelection();
  if( idx != wxNOT_FOUND ) {
    iONode st = (iONode)m_Routes->GetClientData(idx);
    if( st != NULL ) {
      RouteDialog* propDlg = new RouteDialog(this, st );
      if( wxID_OK == propDlg->ShowModal() ) {
        /* Notify RocRail. */
        iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
        wModelCmd.setcmd( cmd, wModelCmd.modify );
        NodeOp.addChild( cmd, (iONode)NodeOp.base.clone( st ) );
        wxGetApp().sendToRocrail( cmd );
        cmd->base.del(cmd);
      }
    }
  }
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BK_ROUTE_TEST
 */

void BlockDialog::OnButtonBkRouteTestClick( wxCommandEvent& event )
{
  int idx = m_Routes->GetSelection();
  if( idx != wxNOT_FOUND ) {
    iONode st = (iONode)m_Routes->GetClientData(idx);
    if( st != NULL ) {
      iONode cmd = NodeOp.inst( wRoute.name(), NULL, ELEMENT_NODE );
      wRoute.setcmd( cmd, wRoute.test );
      wRoute.setid( cmd, wRoute.getid( st ) );
      wxGetApp().sendToRocrail( cmd );
      cmd->base.del(cmd);
    }
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BK_WSIGNAL
 */

void BlockDialog::OnButtonBkWsignalRClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BK_WSIGNAL in BlockDialog.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BK_WSIGNAL in BlockDialog.
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BLOCK_FEEDBACKS
 */


void BlockDialog::initSensorCombos() {
  wxComboBox* ids[5] = {m_SensorID1,m_SensorID2,m_SensorID3,m_SensorID4,m_SensorID5};
  wxComboBox* acts[5] = {m_SensorAction1,m_SensorAction2,m_SensorAction3,m_SensorAction4,m_SensorAction5};
  wxCheckBox* end[5] = {m_SensorEnd1,m_SensorEnd2,m_SensorEnd3,m_SensorEnd4,m_SensorEnd5};
  wxCheckBox* t2[5] = {m_Tim2_1,m_Tim2_2,m_Tim2_3,m_Tim2_4,m_Tim2_5};

  for( int i = 0; i < 5; i++ ) {
    ids[i]->Clear();
    acts[i]->Clear();
    ids[i]->Append( wxString("-",wxConvUTF8) );
    acts[i]->Append( wxString("-",wxConvUTF8) );

    end[i]->SetValue( false );
    t2[i]->SetValue( false );

    acts[i]->Append( wxString(wFeedbackEvent.free_event,wxConvUTF8) );
    acts[i]->Append( wxString(wFeedbackEvent.enter_event,wxConvUTF8) );
    acts[i]->Append( wxString(wFeedbackEvent.enter2route_event,wxConvUTF8) );
    acts[i]->Append( wxString(wFeedbackEvent.enter2in_event,wxConvUTF8) );
    acts[i]->Append( wxString(wFeedbackEvent.enter2shortin_event,wxConvUTF8) );
    acts[i]->Append( wxString(wFeedbackEvent.enter2pre_event,wxConvUTF8) );
    acts[i]->Append( wxString(wFeedbackEvent.in_event,wxConvUTF8) );
    acts[i]->Append( wxString(wFeedbackEvent.exit_event,wxConvUTF8) );
    acts[i]->Append( wxString(wFeedbackEvent.pre2in_event,wxConvUTF8) );
    acts[i]->Append( wxString(wFeedbackEvent.occupied_event,wxConvUTF8) );
    acts[i]->Append( wxString(wFeedbackEvent.ident_event,wxConvUTF8) );
    acts[i]->Append( wxString(wFeedbackEvent.shortin_event,wxConvUTF8) );
  }

  iONode model = wxGetApp().getModel();
  iOList list = ListOp.inst();
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
        m_SensorID1->Append( wxString(id,wxConvUTF8) );
        m_SensorID2->Append( wxString(id,wxConvUTF8) );
        m_SensorID3->Append( wxString(id,wxConvUTF8) );
        m_SensorID4->Append( wxString(id,wxConvUTF8) );
        m_SensorID5->Append( wxString(id,wxConvUTF8) );
      }
    }
  }
  /* clean up the temp. list */
  ListOp.base.del(list);
}

void BlockDialog::initSensors() {
  TraceOp.trc( "blockdlg", TRCLEVEL_INFO, __LINE__, 9999, "initSensors" );

  wxComboBox* ids[5] = {m_SensorID1,m_SensorID2,m_SensorID3,m_SensorID4,m_SensorID5};
  wxComboBox* acts[5] = {m_SensorAction1,m_SensorAction2,m_SensorAction3,m_SensorAction4,m_SensorAction5};
  wxCheckBox* end[5] = {m_SensorEnd1,m_SensorEnd2,m_SensorEnd3,m_SensorEnd4,m_SensorEnd5};
  wxCheckBox* t2[5] = {m_Tim2_1,m_Tim2_2,m_Tim2_3,m_Tim2_4,m_Tim2_5};

  for( int i = 0; i < 5; i++ ) {
    ids[i]->SetStringSelection( wxString("-",wxConvUTF8) );
    acts[i]->SetStringSelection( wxString("-",wxConvUTF8) );
    end[i]->SetValue( false );
    t2[i]->SetValue( false );
    m_fbEvents[i] = NULL;
  }

  iONode st = NULL;
  const char* routeID = NULL;
  const char* enterSide = NULL;
  int idx = m_Routes->GetSelection();
  if( idx != wxNOT_FOUND ) {
    st = (iONode)m_Routes->GetClientData(idx);

    if( StrOp.equals( ROUTE_ALL, m_Routes->GetStringSelection().mb_str(wxConvUTF8) ) ) {
      m_FromBlockID = wFeedbackEvent.from_all;
      m_ByRouteID   = wFeedbackEvent.from_all;
      enterSide = "+ enter";
    }
    else if( StrOp.equals( ROUTE_ALL_REVERSE, m_Routes->GetStringSelection().mb_str(wxConvUTF8) ) ) {
      m_FromBlockID = wFeedbackEvent.from_all_reverse;
      m_ByRouteID   = wFeedbackEvent.from_all_reverse;
      enterSide = "- enter";
    }
    else if( st == NULL ) {
      TraceOp.trc( "blockdlg", TRCLEVEL_WARNING, __LINE__, 9999,
          "route [%s] has no properties...", (const char*)m_Routes->GetStringSelection().mb_str(wxConvUTF8) );
      return;
    }
    else {
      routeID = wRoute.getid(st);
    }
  }

  TraceOp.trc( "blockdlg", TRCLEVEL_INFO, __LINE__, 9999, "route [%s]", routeID );

  if( st == NULL ) {
    /* all */
  }
  else if( st != NULL && StrOp.equals( wBlock.getid( m_Props ), wRoute.getbkb( st ) ) ) {
    m_FromBlockID = wRoute.getbka( st );
    m_ByRouteID   = wRoute.getid(st);
  }
  else {
    m_LabelSensorsFromBlock->SetLabel( _T("") );
    return;
  }

  TraceOp.trc( "blockdlg", TRCLEVEL_INFO, __LINE__, 9999, "FromBlockID [%s]", m_FromBlockID );



  char* br = StrOp.fmt( "%s (%s)", m_FromBlockID, enterSide!=NULL?enterSide:m_ByRouteID );
  char* s = StrOp.fmt( wxGetApp().getMsg("sensorfromblock").mb_str(wxConvUTF8), br );
  m_LabelSensorsFromBlock->SetLabel( wxString( s ,wxConvUTF8) );
  StrOp.free(s);
  StrOp.free(br);

  iONode fb = wBlock.getfbevent( m_Props );
  idx = 0;
  while( fb != NULL && idx < 5 ) {
    TraceOp.trc( "blockdlg", TRCLEVEL_INFO, __LINE__, 9999, "fbIndex %d", idx );
    const char* byroute = wFeedbackEvent.getbyroute(fb);
    const char* fromblock = wFeedbackEvent.getfrom(fb);
    Boolean fitByRoute = True;
    if( byroute != NULL && StrOp.len(byroute) > 0 )
      fitByRoute = StrOp.equals( m_ByRouteID, byroute );

    if( StrOp.equals( m_FromBlockID, fromblock ) && fitByRoute ) {
      ids[idx]->SetStringSelection( wxString(wFeedbackEvent.getid( fb ),wxConvUTF8) );
      acts[idx]->SetStringSelection( wxString(wFeedbackEvent.getaction( fb ),wxConvUTF8) );
      end[idx]->SetValue( wFeedbackEvent.isendpuls( fb ) );
      t2[idx]->SetValue( wFeedbackEvent.isuse_timer2( fb ) );

      m_fbEvents[idx] = fb;
      idx++;
    }
    fb = wBlock.nextfbevent( m_Props, fb );
  };

}


void BlockDialog::evaluateSensors() {
  TraceOp.trc( "blockdlg", TRCLEVEL_INFO, __LINE__, 9999, "evaluateSensors" );
  if( m_Props == NULL || m_Routes->GetSelection()== wxNOT_FOUND )
    return;

  wxComboBox* ids[5] = {m_SensorID1,m_SensorID2,m_SensorID3,m_SensorID4,m_SensorID5};
  wxComboBox* acts[5] = {m_SensorAction1,m_SensorAction2,m_SensorAction3,m_SensorAction4,m_SensorAction5};
  wxCheckBox* end[5] = {m_SensorEnd1,m_SensorEnd2,m_SensorEnd3,m_SensorEnd4,m_SensorEnd5};
  wxCheckBox* t2[5] = {m_Tim2_1,m_Tim2_2,m_Tim2_3,m_Tim2_4,m_Tim2_5};

  for( int i = 0; i < 5; i++ ) {
    if( StrOp.equals( "-", ids[i]->GetValue().mb_str(wxConvUTF8) ) &&
        !StrOp.equals( wFeedbackEvent.enter2route_event, acts[i]->GetValue().mb_str(wxConvUTF8) ) &&
        m_fbEvents[i] != NULL )
      {
      NodeOp.removeChild( m_Props, m_fbEvents[i] );
      NodeOp.base.del( m_fbEvents[i] );
      m_fbEvents[i] = NULL;
    }
    else if( !StrOp.equals( "-", ids[i]->GetValue().mb_str(wxConvUTF8) ) ||
             StrOp.equals( wFeedbackEvent.enter2route_event, acts[i]->GetValue().mb_str(wxConvUTF8) ) )
      {
      if( m_fbEvents[i] == NULL ) {
        TraceOp.trc( "blockdlg", TRCLEVEL_INFO, __LINE__, 9999, "m_fbEvents[%d] == NULL", i );
        m_fbEvents[i] = NodeOp.inst( wFeedbackEvent.name(), m_Props, ELEMENT_NODE );
        NodeOp.addChild( m_Props, m_fbEvents[i] );
      }
      if( StrOp.equals( "-", ids[i]->GetValue().mb_str(wxConvUTF8) ) )
        wFeedbackEvent.setid( m_fbEvents[i], "" );
      else
        wFeedbackEvent.setid( m_fbEvents[i], ids[i]->GetValue().mb_str(wxConvUTF8) );

      wFeedbackEvent.setaction( m_fbEvents[i], acts[i]->GetValue().mb_str(wxConvUTF8) );
      wFeedbackEvent.setfrom( m_fbEvents[i], m_FromBlockID );
      wFeedbackEvent.setbyroute( m_fbEvents[i], m_ByRouteID );
      wFeedbackEvent.setendpuls( m_fbEvents[i], end[i]->GetValue()?True:False );
      wFeedbackEvent.setuse_timer2( m_fbEvents[i], t2[i]->GetValue()?True:False );
    }

  }
}

void BlockDialog::OnBlockSensor( wxCommandEvent& event )
{
  evaluateSensors();
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BLOCKS_SENSOR_PROPS1
 */

void BlockDialog::OnSensorProps( wxCommandEvent& event )
{
  TraceOp.trc( "blockdlg", TRCLEVEL_INFO, __LINE__, 9999, "OnSensorProps" );

  if( event.GetEventObject() == m_SensorProps1 ) {
    char* id = StrOp.dup( m_SensorID1->GetValue().mb_str(wxConvUTF8) );
    TraceOp.trc( "blockdlg", TRCLEVEL_INFO, __LINE__, 9999, "OnSensorProps id=%s", id );
    if( !StrOp.equals( "-", id ) )
      fbProps(id);
    StrOp.free( id );
  }
  else if( event.GetEventObject() == m_SensorProps2 ) {
    char* id = StrOp.dup( m_SensorID2->GetValue().mb_str(wxConvUTF8) );
    if( !StrOp.equals( "-", id ) )
      fbProps(id);
    StrOp.free( id );
  }
  else if( event.GetEventObject() == m_SensorProps3 ) {
    char* id = StrOp.dup( m_SensorID3->GetValue().mb_str(wxConvUTF8) );
    if( !StrOp.equals( "-", id ) )
      fbProps(id);
    StrOp.free( id );
  }
  else if( event.GetEventObject() == m_SensorProps4 ) {
    char* id = StrOp.dup( m_SensorID4->GetValue().mb_str(wxConvUTF8) );
    if( !StrOp.equals( "-", id ) )
      fbProps(id);
    StrOp.free( id );
  }
  else if( event.GetEventObject() == m_SensorProps5 ) {
    char* id = StrOp.dup( m_SensorID5->GetValue().mb_str(wxConvUTF8) );
    if( !StrOp.equals( "-", id ) )
      fbProps(id);
    StrOp.free( id );
  }
}




/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BK_SIGNAL
 */

void BlockDialog::OnButtonBkSignalClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BK_SIGNAL in BlockDialog.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BK_SIGNAL in BlockDialog.
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BK_WSIGNAL
 */

void BlockDialog::OnButtonBkWsignalClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BK_WSIGNAL in BlockDialog.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BK_WSIGNAL in BlockDialog.
}


/*!
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for wxID_BLOCK_WAIT
 */

void BlockDialog::OnBlockWaitClick( wxCommandEvent& event )
{
  int wait = 0;
  if( !m_WaitFlag->GetValue() )
    wait = 3;
  else {
    if( StrOp.equals( wBlock.wait_random, wBlock.getwaitmode( m_Props ) ) )
      wait = 0;
    else if( StrOp.equals( wBlock.wait_fixed, wBlock.getwaitmode( m_Props ) ) )
      wait = 1;
    else if( StrOp.equals( wBlock.wait_loc, wBlock.getwaitmode( m_Props ) ) )
      wait = 2;
  }
  m_Wait->SetSelection( wait );
}


/*!
 * wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_RADIOBOX_BK_WAIT
 */

void BlockDialog::OnRadioboxBkWaitSelected( wxCommandEvent& event )
{
  m_WaitFlag->SetValue(m_Wait->GetSelection() != 3);
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BLOCK_ACTIONS
 */

void BlockDialog::OnButtonBlockActionsClick( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  ActionsCtrlDlg*  dlg = new ActionsCtrlDlg(this, m_Props, "ghost,enter,occupied,reserved,free,closed,depart,acceptident,exit" );

  if( wxID_OK == dlg->ShowModal() ) {
    // TODO: inform
  }

  dlg->Destroy();
}


/*!
 * wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ID_LISTCTRL
 */

void BlockDialog::OnListctrlindexBkSelected( wxListEvent& event )
{
  if( m_Props != getSelection(event.GetIndex()) ) {
    m_iRouteSelection = 0;
    TraceOp.trc( "blockdlg", TRCLEVEL_INFO, __LINE__, 9999, "RouteSelection=%d", m_iRouteSelection );
  }
  m_Props = getSelection(event.GetIndex());
  initValues();
}






/*!
 * wxEVT_COMMAND_LIST_COL_CLICK event handler for ID_LISTCTRL
 */

void BlockDialog::OnListctrlindexBkColLeftClick( wxListEvent& event )
{
  sortOnColumn(event.GetColumn());
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_ANY
 */

void BlockDialog::onDoc( wxCommandEvent& event )
{
  doDoc( event, "blocks" );
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
 */

void BlockDialog::OnHelpClick( wxCommandEvent& event )
{
  switch( m_Notebook->GetSelection() ) {
  case 0: wxGetApp().openLink( "block-index" ); break;
  case 1: wxGetApp().openLink( "block-gen" ); break;
  case 2: wxGetApp().openLink( "block" ); break; // Position
  case 3: wxGetApp().openLink( "block-signals" ); break;
  case 4: wxGetApp().openLink( "block-details" ); break;
  case 5: wxGetApp().openLink( "block-routes" ); break;
  case 6: wxGetApp().openLink( "block-int" ); break;
  case 7: wxGetApp().openLink( "block-permissions" ); break;
  default: wxGetApp().openLink( "block" ); break;
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ADD_INCLUDE
 */

void BlockDialog::OnAddIncludeClick( wxCommandEvent& event )
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
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ADD_EXCLUDE
 */

void BlockDialog::OnAddExcludeClick( wxCommandEvent& event )
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

void BlockDialog::OnRemoveIncludeClick( wxCommandEvent& event )
{
  if( m_IncludeList->GetSelection() != wxNOT_FOUND ) {
    iONode incl = (iONode)m_IncludeList->GetClientData(m_IncludeList->GetSelection());
    NodeOp.removeChild( m_Props, incl );
    NodeOp.base.del(incl);
    m_IncludeList->Delete(m_IncludeList->GetSelection());
    OnIncludeListSelected(event);
  }
}


/*!
 * wxEVT_COMMAND_LISTBOX_SELECTED event handler for ID_INCLUDE_LIST
 */

void BlockDialog::OnIncludeListSelected( wxCommandEvent& event )
{
  if( m_IncludeList->GetSelection() != wxNOT_FOUND ) {
    iONode incl = (iONode)m_IncludeList->GetClientData(m_IncludeList->GetSelection());
    if( incl != NULL ) {
      m_IncludeRandomRate->SetValue( wPermInclude.getrandomrate(incl) );
    }
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_REMOVE_EXCLUDE
 */

void BlockDialog::OnRemoveExcludeClick( wxCommandEvent& event )
{
  if( m_ExcludeList->GetSelection() != wxNOT_FOUND ) {
    iONode excl = (iONode)m_ExcludeList->GetClientData(m_ExcludeList->GetSelection());
    NodeOp.removeChild( m_Props, excl );
    NodeOp.base.del(excl);
    m_ExcludeList->Delete(m_ExcludeList->GetSelection());
  }
}


/*!
 * wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_INCLUDE_RANDOMRATE
 */

void BlockDialog::OnIncludeRandomrateUpdated( wxSpinEvent& event )
{
  if( m_IncludeList->GetSelection() != wxNOT_FOUND ) {
    iONode incl = (iONode)m_IncludeList->GetClientData(m_IncludeList->GetSelection());
    if( incl != NULL ) {
      wPermInclude.setrandomrate(incl, m_IncludeRandomRate->GetValue() );
    }
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BK_STATESIGNAL_PROPS
 */

void BlockDialog::OnBkStatesignalPropsClick( wxCommandEvent& event )
{
  char* id = StrOp.dup( m_StateSignal->GetValue().mb_str(wxConvUTF8) );
  if( !StrOp.equals( "-", id ) )
    sgProps(id);
  StrOp.free( id );
}

void BlockDialog::sgProps( const char* sgid ) {
  iONode model = wxGetApp().getModel();

  if( model != NULL ) {
    iONode sglist = wPlan.getsglist( model );
    if( sglist != NULL ) {
      int cnt = NodeOp.getChildCnt( sglist );
      for( int i = 0; i < cnt; i++ ) {
        iONode sg = NodeOp.getChild( sglist, i );
        const char* id = wSignal.getid( sg );

        if( id != NULL && StrOp.equals( sgid, id ) ) {
          SignalDialog* propDlg = new SignalDialog(this, sg );
          if( wxID_OK == propDlg->ShowModal() ) {
            /* Notify RocRail. */
          }
          break;
        }
      }
    }
  }
}

