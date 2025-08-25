/*
 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 

 */
#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "actionsctrldlg.h"
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

#include <wx/clipbrd.h>
#include <wx/dataobj.h>

#include "actionsctrldlg.h"

////@begin XPM images
////@end XPM images

#include "rocrail/wrapper/public/Plan.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/Action.h"
#include "rocrail/wrapper/public/ActionList.h"
#include "rocrail/wrapper/public/Item.h"
#include "rocrail/wrapper/public/ActionCtrl.h"
#include "rocrail/wrapper/public/ActionCond.h"
#include "rocrail/wrapper/public/Route.h"
#include "rocrail/wrapper/public/Operator.h"
#include "rocrail/wrapper/public/Variable.h"
#include "rocrail/wrapper/public/Text.h"

#include "rocview/public/guiapp.h"

#include "rocs/public/node.h"
#include "rocs/public/list.h"
#include "rocs/public/strtok.h"



/*!
 * ActionsCtrlDlg type definition
 */

IMPLEMENT_DYNAMIC_CLASS( ActionsCtrlDlg, wxDialog )


/*!
 * ActionsCtrlDlg event table definition
 */

BEGIN_EVENT_TABLE( ActionsCtrlDlg, wxDialog )

////@begin ActionsCtrlDlg event table entries
    EVT_LISTBOX( ID_ACTIONCTRL_LIST, ActionsCtrlDlg::OnActionctrlListSelected )

    EVT_BUTTON( ID_ACTIONCTRL_UP, ActionsCtrlDlg::OnActionctrlUpClick )

    EVT_BUTTON( ID_ACTIONCTRL_DOWN, ActionsCtrlDlg::OnActionctrlDownClick )

    EVT_BUTTON( ID_ACTIONCTRL_COPY, ActionsCtrlDlg::OnActionctrlCopyClick )

    EVT_BUTTON( ID_ACTIONCTRL_PASTE, ActionsCtrlDlg::OnActionctrlPasteClick )

    EVT_BUTTON( ID_ACTIONCTRL_ADD, ActionsCtrlDlg::OnActionctrlAddClick )

    EVT_BUTTON( ID_ACTIONCTRL_DELETE, ActionsCtrlDlg::OnActionctrlDeleteClick )

    EVT_BUTTON( ID_ACTIONCTRL_MODIFY, ActionsCtrlDlg::OnActionctrlModifyClick )

    EVT_LIST_ITEM_SELECTED( ID_CONDITIONS, ActionsCtrlDlg::OnConditionsSelected )

    EVT_CHOICE( ID_ACTIONCTRL_COND_TYPE, ActionsCtrlDlg::OnActionctrlCondTypeSelected )

    EVT_BUTTON( ID_ACTIONCTRL_COND_ADD, ActionsCtrlDlg::OnActionctrlCondAddClick )

    EVT_BUTTON( ID_ACTIONCTRL_COND_DELETE, ActionsCtrlDlg::OnActionctrlCondDeleteClick )

    EVT_BUTTON( ID_ACTIONCTRL_COND_MODIFY, ActionsCtrlDlg::OnActionctrlCondModifyClick )

    EVT_BUTTON( wxID_OK, ActionsCtrlDlg::OnOkClick )

    EVT_BUTTON( wxID_CANCEL, ActionsCtrlDlg::OnCancelClick )

    EVT_BUTTON( wxID_APPLY, ActionsCtrlDlg::OnApplyClick )

    EVT_BUTTON( wxID_HELP, ActionsCtrlDlg::OnHelpClick )

////@end ActionsCtrlDlg event table entries

END_EVENT_TABLE()


/*!
 * ActionsCtrlDlg constructors
 */

ActionsCtrlDlg::ActionsCtrlDlg()
{
    Init();
}

ActionsCtrlDlg::ActionsCtrlDlg( wxWindow* parent, iONode node, const char* states, const char* substates )
{
  Init();
  Create(parent, -1, wxGetApp().getMsg("actionctrl"));

  m_Props = node;
  m_iCursel = wxNOT_FOUND;
  m_iCurCondsel = wxNOT_FOUND;

  initLabels();

  SetTitle(wxGetApp().getMsg("actionctrl") + wxT(": ") + wxString(wItem.getid(m_Props), wxConvUTF8));

  m_ConditionsPanel->Enable(false);

  initIndex(-1);
  initValues();

  m_IndexPanel->GetSizer()->Layout();
  m_ConditionsPanel->GetSizer()->Layout();

  m_Notebook->Fit();

  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);
  GetSizer()->Layout();

  if( states != NULL ) {
    iOStrTok tok = StrTokOp.inst(states, ',');
    while( StrTokOp.hasMoreTokens(tok) ) {
      m_State->Append( wxString( StrTokOp.nextToken(tok), wxConvUTF8 ) );
    }
    StrTokOp.base.del(tok);
  }
  if( substates != NULL ) {
    iOStrTok tok = StrTokOp.inst(substates, ',');
    while( StrTokOp.hasMoreTokens(tok) ) {
      m_SubState->Append( wxString( StrTokOp.nextToken(tok), wxConvUTF8 ) );
    }
    StrTokOp.base.del(tok);
  }
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


void ActionsCtrlDlg::initLabels() {
  m_Notebook->SetPageText( 0, wxGetApp().getMsg( "index" ) );
  m_Notebook->SetPageText( 1, wxGetApp().getMsg( "conditions" ) );

  // Index
  m_labID->SetLabel( wxGetApp().getMsg( "id" ) );
  m_labState->SetLabel( wxGetApp().getMsg( "state" ) );
  m_labSubState->SetLabel( wxGetApp().getMsg( "substate" ) );
  m_labDuration->SetLabel( wxGetApp().getMsg( "duration" ) );
  m_labTimer->SetLabel( wxGetApp().getMsg( "timer" ) );
  m_labLocoID->SetLabel( wxGetApp().getMsg( "locomotive" ) );
  m_labDesc->SetLabel( wxGetApp().getMsg( "description" ) );
  m_labSubID->SetLabel( wxGetApp().getMsg( "subid" ) );

  m_Reset->SetLabel( wxGetApp().getMsg( "reset" ) );
  m_AllConditions->SetLabel( wxGetApp().getMsg( "allconditions" ) );
  m_AtCommand->SetLabel( wxGetApp().getMsg( "atcommand" ) );
  m_AtEvent->SetLabel( wxGetApp().getMsg( "atevent" ) );

  m_Auto->SetLabel( wxGetApp().getMsg( "mode" ) );
  m_Auto->SetString( 0, wxGetApp().getMsg( "auto" ) );
  m_Auto->SetString( 1, wxGetApp().getMsg( "manually" ) );
  m_Auto->SetString( 2, wxGetApp().getMsg( "both" ) );
  m_Auto->SetSelection(2);

  m_Up->SetLabel( wxGetApp().getMsg( "up" ) );
  m_Down->SetLabel( wxGetApp().getMsg( "down" ) );
  m_Copy->SetLabel( wxGetApp().getMsg( "copy" ) );
  m_Paste->SetLabel( wxGetApp().getMsg( "paste" ) );

  m_Add->SetLabel( wxGetApp().getMsg( "add" ) );
  m_Modify->SetLabel( wxGetApp().getMsg( "modify" ) );
  m_Delete->SetLabel( wxGetApp().getMsg( "delete" ) );

  // Conditions

  m_Conditions->InsertColumn(0, wxGetApp().getMsg( "id" ), wxLIST_FORMAT_LEFT );
  m_Conditions->InsertColumn(1, wxGetApp().getMsg( "subid" ), wxLIST_FORMAT_LEFT );
  m_Conditions->InsertColumn(2, wxGetApp().getMsg( "type" ), wxLIST_FORMAT_LEFT );
  m_Conditions->InsertColumn(3, wxGetApp().getMsg( "state" ), wxLIST_FORMAT_LEFT );

  m_labCondID->SetLabel( wxGetApp().getMsg( "id" ) );
  m_labCondType->SetLabel( wxGetApp().getMsg( "type" ) );
  m_labCondState->SetLabel( wxGetApp().getMsg( "state" ) );

  m_CondMust->SetLabel( wxGetApp().getMsg( "mustbetrue" ) );
  m_CondAdd->SetLabel( wxGetApp().getMsg( "add" ) );
  m_CondModify->SetLabel( wxGetApp().getMsg( "modify" ) );
  m_CondDelete->SetLabel( wxGetApp().getMsg( "delete" ) );

  m_CondType->Append(wxGetApp().getMsg( "turnout" ));
  m_CondType->Append(wxGetApp().getMsg( "signal" ));
  m_CondType->Append(wxGetApp().getMsg( "output" ));
  m_CondType->Append(wxGetApp().getMsg( "sensor" ));
  m_CondType->Append(wxGetApp().getMsg( "loc" ));
  m_CondType->Append(wxGetApp().getMsg( "block" ));
  m_CondType->Append(wxGetApp().getMsg( "system" ));
  m_CondType->Append(wxGetApp().getMsg( "route" ));
  m_CondType->Append(wxGetApp().getMsg( "train" ));
  m_CondType->Append(wxGetApp().getMsg( "variable" ));
  m_CondType->Append(wxGetApp().getMsg( "text" ));


  // Std buttons
  m_OK->SetLabel( wxGetApp().getMsg( "ok" ) );
  m_Cancel->SetLabel( wxGetApp().getMsg( "cancel" ) );
  m_Apply->SetLabel( wxGetApp().getMsg( "apply" ) );


  iONode model = wxGetApp().getModel();
  iOList list = ListOp.inst();

  if( model != NULL ) {
    iONode lclist = wPlan.getlclist( model );
    if( lclist != NULL ) {
      int cnt = NodeOp.getChildCnt( lclist );
      TraceOp.trc( "acdlg", TRCLEVEL_INFO, __LINE__, 9999, "%d locos...", cnt );
      for( int i = 0; i < cnt; i++ ) {
        iONode lc = NodeOp.getChild( lclist, i );
        const char* id = wItem.getid( lc );
        if( id != NULL ) {
          ListOp.add(list, (obj)lc);
        }
     }

      m_LocoID->Append( wxString("",wxConvUTF8) );

      ListOp.sort(list, &__sortID);
      cnt = ListOp.size( list );
      for( int i = 0; i < cnt; i++ ) {
        iONode lc = (iONode)ListOp.get( list, i );
        const char* id = wItem.getid(lc);
        m_LocoID->Append( wxString(id,wxConvUTF8) );
      }

    }
  }
  /* clean up the temp. list */
  ListOp.base.del(list);


}


void ActionsCtrlDlg::clearIndexSelection() {
  if(m_CtrlList->GetCount() > 0) {
    wxArrayInt ai;
    int cnt = m_CtrlList->GetSelections(ai);
    for( int i = 0; i < cnt; i++ ) {
      m_CtrlList->Deselect( ai.Item(i) );
    }
  }
}

void ActionsCtrlDlg::initIndex(int cursel) {
  TraceOp.trc( "scdlg", TRCLEVEL_INFO, __LINE__, 9999, "InitIndex" );
  m_ID->Clear();
  iONode model = wxGetApp().getModel();
  iOList list = ListOp.inst();

  if( model != NULL ) {
    iONode aclist = wPlan.getaclist( model );
    if( aclist != NULL ) {
      int cnt = NodeOp.getChildCnt( aclist );
      TraceOp.trc( "acdlg", TRCLEVEL_INFO, __LINE__, 9999, "%d actions...", cnt );
      for( int i = 0; i < cnt; i++ ) {
        iONode ac = NodeOp.getChild( aclist, i );
        const char* id = wAction.getid( ac );
        if( id != NULL ) {
          ListOp.add(list, (obj)ac);
        }
     }

      ListOp.sort(list, &__sortID);
      cnt = ListOp.size( list );
      for( int i = 0; i < cnt; i++ ) {
        iONode ac = (iONode)ListOp.get( list, i );
        const char* id = wAction.getid(ac);
        TraceOp.trc( "acctrldlg", TRCLEVEL_INFO, __LINE__, 9999, "timed action %s", id );
        m_ID->Append( wxString(id,wxConvUTF8), ac );
      }

    }
  }
  /* clean up the temp. list */
  ListOp.base.del(list);

  m_CtrlList->Clear();
  iONode actionctrl = NodeOp.findNode( m_Props, wActionCtrl.name() );
  while( actionctrl != NULL ) {
    m_CtrlList->Append( wxString(wActionCtrl.getid(actionctrl),wxConvUTF8), NodeOp.base.clone(actionctrl) );
    actionctrl = NodeOp.findNextNode( m_Props, actionctrl );
  };

  if(m_CtrlList->GetCount() > 0) {
    clearIndexSelection();
    m_iCursel = (cursel>=0?cursel:0);
    m_CtrlList->SetSelection(cursel>=0?cursel:0);
  }

}


void ActionsCtrlDlg::initCondIndex(int cursel ) {
  m_iCurCondsel = wxNOT_FOUND;
  m_Conditions->DeleteAllItems();
  if( m_iCursel != wxNOT_FOUND ) {
    iONode actionctrl = (iONode)m_CtrlList->GetClientData(m_iCursel);
    int idx = 0;
    iONode actioncond = wActionCtrl.getactioncond(actionctrl);
    while( actioncond != NULL ) {
      m_Conditions->InsertItem( idx, wxString(wActionCond.getid(actioncond),wxConvUTF8) );
      m_Conditions->SetItem( idx, 1, wxString(wActionCond.getsubid(actioncond), wxConvUTF8) );
      m_Conditions->SetItem( idx, 2, wxString(wActionCond.gettype(actioncond), wxConvUTF8) );
      m_Conditions->SetItem( idx, 3, wxString(wActionCond.getstate(actioncond), wxConvUTF8) );
      m_Conditions->SetItemPtrData(idx, (wxUIntPtr)actioncond);
      idx++;
      actioncond = wActionCtrl.nextactioncond(actionctrl, actioncond);
    };

    // resize
    for( int n = 0; n < 4; n++ ) {
      m_Conditions->SetColumnWidth(n, wxLIST_AUTOSIZE_USEHEADER);
      int autoheadersize = m_Conditions->GetColumnWidth(n);
      m_Conditions->SetColumnWidth(n, wxLIST_AUTOSIZE);
      int autosize = m_Conditions->GetColumnWidth(n);
      if(autoheadersize > autosize )
        m_Conditions->SetColumnWidth(n, wxLIST_AUTOSIZE_USEHEADER);
    }


    if(m_Conditions->GetItemCount() > 0) {
      m_Conditions->SetItemState(cursel, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
      m_iCurCondsel = cursel;
      initCondValues();
    }
    else {
      m_CondID->SetStringSelection( _T("*") );
      m_CondState->SetValue( _T("") );
    }
  }
}

void ActionsCtrlDlg::initValues() {
  if( m_Props == NULL )
    return;


  if( m_iCursel != wxNOT_FOUND ) {
    iONode actionctrl = (iONode)m_CtrlList->GetClientData(m_iCursel);
    m_ID->SetStringSelection( wxString(wActionCtrl.getid(actionctrl),wxConvUTF8) );

    m_LocoID->SetSelection(0);
    if( wActionCtrl.getlcid(actionctrl) != NULL ) {
      m_LocoID->SetStringSelection(wxString(wActionCtrl.getlcid(actionctrl),wxConvUTF8));
    }
    m_Desc->SetValue(wxString(wActionCtrl.getdesc(actionctrl),wxConvUTF8));

    m_Reset->SetValue(wActionCtrl.isreset(actionctrl)?true:false);
    m_AllConditions->SetValue(wActionCtrl.isallconditions(actionctrl)?true:false);
    m_AtCommand->SetValue(wActionCtrl.isatcmd(actionctrl)?true:false);
    m_AtEvent->SetValue(wActionCtrl.isatevt(actionctrl)?true:false);

    if(wActionCtrl.isauto(actionctrl) && wActionCtrl.ismanual(actionctrl) )
      m_Auto->SetSelection(2);
    else if(wActionCtrl.isauto(actionctrl) )
      m_Auto->SetSelection(0);
    else if(wActionCtrl.ismanual(actionctrl) )
      m_Auto->SetSelection(1);

    m_State->SetValue( wxString(wActionCtrl.getstate(actionctrl),wxConvUTF8) );
    m_SubState->SetValue( wxString(wActionCtrl.getsubstate(actionctrl),wxConvUTF8) );
    m_Duration->SetValue( wActionCtrl.getduration(actionctrl) );
    m_Timer->SetValue( wActionCtrl.gettimer(actionctrl) );
    m_ConditionsPanel->Enable(true);

    initCondIndex();
  }
  else {
    m_ConditionsPanel->Enable(false);
  }

}


void ActionsCtrlDlg::initCondValues() {
  if( m_Props == NULL )
    return;

  if( m_iCurCondsel != wxNOT_FOUND ) {
    iONode actioncond = (iONode)m_Conditions->GetItemData(m_iCurCondsel);
    const char* type = wActionCond.gettype(actioncond);
    if( StrOp.equals( wSwitch.name(), type ) )
      m_CondType->SetSelection(0);
    else if( StrOp.equals( wSignal.name(), type ) )
      m_CondType->SetSelection(1);
    else if( StrOp.equals( wOutput.name(), type ) )
      m_CondType->SetSelection(2);
    else if( StrOp.equals( wFeedback.name(), type ) )
      m_CondType->SetSelection(3);
    else if( StrOp.equals( wLoc.name(), type ) )
      m_CondType->SetSelection(4);
    else if( StrOp.equals( wBlock.name(), type ) )
      m_CondType->SetSelection(5);
    else if( StrOp.equals( wSysCmd.name(), type ) )
      m_CondType->SetSelection(6);
    else if( StrOp.equals( wRoute.name(), type ) )
      m_CondType->SetSelection(7);
    else if( StrOp.equals( wOperator.name(), type ) )
      m_CondType->SetSelection(8);
    else if( StrOp.equals( wVariable.name(), type ) )
      m_CondType->SetSelection(9);
    else if( StrOp.equals( wText.name(), type ) )
      m_CondType->SetSelection(10);
    initCondIDs();
    m_CondID->SetStringSelection( wxString(wActionCond.getid(actioncond),wxConvUTF8) );
    m_SubID->SetValue( wxString(wActionCond.getsubid(actioncond),wxConvUTF8) );
    m_CondState->SetValue( wxString(wActionCond.getstate(actioncond),wxConvUTF8) );
    m_CondMust->SetValue( wActionCond.ismustbetrue(actioncond)?true:false );
  }
}


/* comparator for sorting by id: */
static int __sortStr(obj* _a, obj* _b)
{
    const char* a = (const char*)*_a;
    const char* b = (const char*)*_b;
    return strcmp( a, b );
}

void ActionsCtrlDlg::initCondIDs() {
  iONode model = wxGetApp().getModel();
  iOList list = ListOp.inst();

  m_CondID->Clear();
  m_CondID->Append( _T("*") );

  m_CondState->Clear();

  /*
    m_CondType->Append(wxGetApp().getMsg( "turnout" ));
    m_CondType->Append(wxGetApp().getMsg( "signal" ));
    m_CondType->Append(wxGetApp().getMsg( "output" ));
    m_CondType->Append(wxGetApp().getMsg( "sensor" ));
    m_CondType->Append(wxGetApp().getMsg( "loc" ));
    m_CondType->Append(wxGetApp().getMsg( "block" ));
    m_CondType->Append(wxGetApp().getMsg( "system" ));
    m_CondType->Append(wxGetApp().getMsg( "route" ));
   */

  if( model != NULL ) {
    const char* statelist = "";
    iONode colist = wPlan.getswlist( model );

    int typenr = m_CondType->GetSelection();

    switch( typenr ) {
      case 0: statelist = "straight,turnout,left,right"; break;
      case 1: statelist = "red,yellow,green,white,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15"; break;
      case 2: statelist = "on,off,active"; break;
      case 3: statelist = "true,false,identifier"; break;
      case 4: statelist = "forwards,reverse,diesel,steam,electric,min,mid,cruise,max,fon,foff,+,-,#,x,light,lightgoods,person,goods,post,ice,mixed,regional,class"; break;
      case 5: statelist = "free,!free,occupied,open,closed"; break;
      case 6: statelist = "go,stop,init"; break;
      case 7: statelist = "locked,unlocked,closed,open,="; break;
      case 8: statelist = "forwards,reverse,diesel,steam,electric,min,mid,cruise,max,fon,foff,+,-,#,x,light,lightgoods,person,goods,post,ice,mixed,regional,class"; break;
    }
    iOStrTok tok = StrTokOp.inst(statelist, ',');
    while( StrTokOp.hasMoreTokens(tok) ) {
      m_CondState->Append( wxString( StrTokOp.nextToken(tok), wxConvUTF8 ) );
    }
    StrTokOp.base.del(tok);




    switch( typenr ) {
      case 0: colist = wPlan.getswlist( model ); break;
      case 1: colist = wPlan.getsglist( model ); break;
      case 2: colist = wPlan.getcolist( model ); break;
      case 3: colist = wPlan.getfblist( model ); break;
      case 4: colist = wPlan.getlclist( model ); break;
      case 5: colist = wPlan.getbklist( model ); break;
      case 6: colist = NULL; break;
      case 7: colist = wPlan.getstlist( model ); break;
      case 8: colist = wPlan.getoperatorlist(model); break;
      case 9: colist = wPlan.getvrlist(model); break;
      case 10: colist = wPlan.gettxlist(model); break;
    }


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
          m_CondID->Append( wxString(id,wxConvUTF8) );
      }
    }
  }
  /* clean up the temp. list */
  ListOp.base.del(list);
}


void ActionsCtrlDlg::evaluate() {
  int cursel = m_iCursel;

  if( cursel != wxNOT_FOUND ) {
    iONode node = (iONode)m_CtrlList->GetClientData(cursel);
    wActionCtrl.setid(node, m_ID->GetStringSelection().mb_str(wxConvUTF8) );
    wActionCtrl.setlcid(node, m_LocoID->GetStringSelection().mb_str(wxConvUTF8) );
    wActionCtrl.setreset(node, m_Reset->IsChecked()?True:False);
    wActionCtrl.setallconditions(node, m_AllConditions->IsChecked()?True:False);
    wActionCtrl.setdesc(node, m_Desc->GetValue().mb_str(wxConvUTF8));
    wActionCtrl.setatcmd(node, m_AtCommand->IsChecked()?True:False);
    wActionCtrl.setatevt(node, m_AtEvent->IsChecked()?True:False);

    if( m_Auto->GetSelection() == 2 ) {
      wActionCtrl.setauto(node, True );
      wActionCtrl.setmanual(node, True );
    }
    else if( m_Auto->GetSelection() == 0 ) {
      wActionCtrl.setauto(node, True );
      wActionCtrl.setmanual(node, False );
    }
    else if( m_Auto->GetSelection() == 1 ) {
      wActionCtrl.setauto(node, False );
      wActionCtrl.setmanual(node, True );
    }

    wActionCtrl.setstate(node, m_State->GetValue().mb_str(wxConvUTF8) );
    wActionCtrl.setsubstate(node, m_SubState->GetValue().mb_str(wxConvUTF8) );
    wActionCtrl.setduration(node, m_Duration->GetValue() );
    wActionCtrl.settimer(node, m_Timer->GetValue() );

    m_CtrlList->SetString(m_iCursel, m_ID->GetStringSelection() );
    m_ConditionsPanel->Enable(true);

  }
}


void ActionsCtrlDlg::evaluateCond(iONode node) {

    wActionCond.setid(node, m_CondID->GetStringSelection().mb_str(wxConvUTF8) );
    wActionCond.setsubid(node, m_SubID->GetValue().mb_str(wxConvUTF8) );
    wActionCond.setstate(node, m_CondState->GetValue().mb_str(wxConvUTF8) );
    wActionCond.setmustbetrue(node, m_CondMust->IsChecked()?True:False );

    int typenr = m_CondType->GetSelection();
    const char* type = wSwitch.name();
    switch( typenr ) {
      case 0: type = wSwitch.name(); break;
      case 1: type = wSignal.name(); break;
      case 2: type = wOutput.name(); break;
      case 3: type = wFeedback.name(); break;
      case 4: type = wLoc.name(); break;
      case 5: type = wBlock.name(); break;
      case 6: type = wSysCmd.name(); break;
      case 7: type = wRoute.name(); break;
      case 8: type = wOperator.name(); break;
      case 9: type = wVariable.name(); break;
      case 10: type = wText.name(); break;
    }
    wActionCond.settype(node, type);
}


void ActionsCtrlDlg::evaluateCond() {
  if( m_iCursel != wxNOT_FOUND ) {
    if( m_iCurCondsel != wxNOT_FOUND ) {
      iONode node = (iONode)m_Conditions->GetItemData(m_iCurCondsel);
      evaluateCond(node);
    }
  }
}


/**
 * Take over all changes and send to rocrail server.
 */
void ActionsCtrlDlg::apply() {
  // remove all child from original:
  iONode actionctrl = NodeOp.findNode( m_Props, wActionCtrl.name() );
  while( actionctrl != NULL ) {
    NodeOp.removeChild(m_Props, actionctrl);
    NodeOp.base.del(actionctrl);
    actionctrl = NodeOp.findNode( m_Props, wActionCtrl.name() );
  };

  // add all cloned childs to parent:
  int cnt = m_CtrlList->GetCount();
  for( int i = 0; i < cnt; i++ ) {
    iONode node = (iONode)m_CtrlList->GetClientData(i);
    NodeOp.addChild( m_Props, (iONode)NodeOp.base.clone(node) );
  }

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
}


/**
 * Remove selection.
 */
void ActionsCtrlDlg::deleteSelected() {

  if( m_iCursel != wxNOT_FOUND ) {
    int cursel = m_iCursel;
    iONode node = (iONode)m_CtrlList->GetClientData(cursel);
    NodeOp.base.del(node);
    m_CtrlList->Delete(cursel);
    clearIndexSelection();
    if( m_CtrlList->GetCount() > 0 ) {
      m_iCursel = (cursel>0 ? cursel-1 : 0);
      m_CtrlList->SetSelection(m_iCursel);
//      m_CtrlList->SetSelection(0);
      initValues();
    }
    else {
      m_iCursel = wxNOT_FOUND;
    }
  }
}


void ActionsCtrlDlg::deleteSelectedCond() {

  if( m_iCursel == wxNOT_FOUND )
    return;

  iONode actionctrl = (iONode)m_CtrlList->GetClientData(m_iCursel);

  if( m_iCurCondsel != wxNOT_FOUND ) {
    iONode node = (iONode)m_Conditions->GetItemData(m_iCurCondsel);
    NodeOp.removeChild(actionctrl, node);
    NodeOp.base.del(node);
    initValues();
    initCondValues();
  }
}


/**
 * Add a new entry to the list.
 */
void ActionsCtrlDlg::addActionCtrl() {
  if( m_ID->GetStringSelection().Len() == 0 )
    return;

  iONode node = NodeOp.inst( wActionCtrl.name(), NULL, ELEMENT_NODE);
  wActionCtrl.setid(node, m_ID->GetStringSelection().mb_str(wxConvUTF8) );
  m_CtrlList->Append( wxString( wActionCtrl.getid(node),wxConvUTF8 ), node );
  clearIndexSelection();
  m_CtrlList->SetSelection( m_CtrlList->GetCount()-1 );
  m_CtrlList->SetFirstItem( m_CtrlList->GetCount()-1 );
  m_iCursel = m_CtrlList->GetCount()-1;
  evaluate();
  initValues();
}


void ActionsCtrlDlg::setCondSelection(const char* ID) {
  int size = m_Conditions->GetItemCount();
  for( int index = 0; index < size; index++ ) {
    iONode node = (iONode)m_Conditions->GetItemData(index);
    if( StrOp.equals( ID, wActionCond.getid(node) ) ) {
      m_iCurCondsel = index;
      m_Conditions->SetItemState(index, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
      break;
    }
  }

}


void ActionsCtrlDlg::addActionCond() {
  if( m_CondID->GetStringSelection().Len() == 0 )
    return;

  if( m_iCursel == wxNOT_FOUND )
    return;

  iONode actionctrl = (iONode)m_CtrlList->GetClientData(m_iCursel);
  iONode node = NodeOp.inst( wActionCond.name(), actionctrl, ELEMENT_NODE);

  wActionCond.setid(node, m_CondID->GetStringSelection().mb_str(wxConvUTF8) );

  NodeOp.addChild( actionctrl, node );
  evaluateCond(node);
  initCondIndex();
  setCondSelection(wActionCond.getid(node));

}


/**
 * Delete all cloned nodes.
 */
void ActionsCtrlDlg::cleanUp() {
  int cnt = m_CtrlList->GetCount();
  for( int i = 0; i < cnt; i++ ) {
    iONode node = (iONode)m_CtrlList->GetClientData(i);
    NodeOp.base.del(node);
    m_CtrlList->SetClientData(NULL);
  }
}


/*!
 * ActionsCtrlDlg creator
 */

bool ActionsCtrlDlg::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin ActionsCtrlDlg creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end ActionsCtrlDlg creation
    return true;
}


/*!
 * ActionsCtrlDlg destructor
 */

ActionsCtrlDlg::~ActionsCtrlDlg()
{
////@begin ActionsCtrlDlg destruction
////@end ActionsCtrlDlg destruction
}


/*!
 * Member initialisation
 */

void ActionsCtrlDlg::Init()
{
////@begin ActionsCtrlDlg member initialisation
    m_Notebook = NULL;
    m_IndexPanel = NULL;
    m_CtrlList = NULL;
    m_Up = NULL;
    m_Down = NULL;
    m_Copy = NULL;
    m_Paste = NULL;
    m_labID = NULL;
    m_ID = NULL;
    m_labState = NULL;
    m_State = NULL;
    m_labSubState = NULL;
    m_SubState = NULL;
    m_labDuration = NULL;
    m_Duration = NULL;
    m_labTimer = NULL;
    m_Timer = NULL;
    m_labLocoID = NULL;
    m_LocoID = NULL;
    m_labDesc = NULL;
    m_Desc = NULL;
    m_Reset = NULL;
    m_AllConditions = NULL;
    m_AtCommand = NULL;
    m_AtEvent = NULL;
    m_Auto = NULL;
    m_Add = NULL;
    m_Delete = NULL;
    m_Modify = NULL;
    m_ConditionsPanel = NULL;
    m_Conditions = NULL;
    m_CondMust = NULL;
    m_labCondType = NULL;
    m_CondType = NULL;
    m_labCondID = NULL;
    m_CondID = NULL;
    m_labSubID = NULL;
    m_SubID = NULL;
    m_labCondState = NULL;
    m_CondState = NULL;
    m_CondAdd = NULL;
    m_CondDelete = NULL;
    m_CondModify = NULL;
    m_OK = NULL;
    m_Cancel = NULL;
    m_Apply = NULL;
////@end ActionsCtrlDlg member initialisation
}


/*!
 * Control creation for ActionsCtrlDlg
 */

void ActionsCtrlDlg::CreateControls()
{
////@begin ActionsCtrlDlg content construction
    ActionsCtrlDlg* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    m_Notebook = new wxNotebook( itemDialog1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBK_DEFAULT );

    m_IndexPanel = new wxPanel( m_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxVERTICAL);
    m_IndexPanel->SetSizer(itemBoxSizer5);

    wxArrayString m_CtrlListStrings;
    m_CtrlList = new wxListBox( m_IndexPanel, ID_ACTIONCTRL_LIST, wxDefaultPosition, wxSize(-1, 140), m_CtrlListStrings, wxLB_EXTENDED );
    itemBoxSizer5->Add(m_CtrlList, 1, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer5->Add(itemBoxSizer7, 0, wxALIGN_CENTER_HORIZONTAL, 5);
    m_Up = new wxButton( m_IndexPanel, ID_ACTIONCTRL_UP, _("Up"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer7->Add(m_Up, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Down = new wxButton( m_IndexPanel, ID_ACTIONCTRL_DOWN, _("Down"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer7->Add(m_Down, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    m_Copy = new wxButton( m_IndexPanel, ID_ACTIONCTRL_COPY, _("Copy"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer7->Add(m_Copy, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    m_Paste = new wxButton( m_IndexPanel, ID_ACTIONCTRL_PASTE, _("Paste"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer7->Add(m_Paste, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    wxFlexGridSizer* itemFlexGridSizer12 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer5->Add(itemFlexGridSizer12, 0, wxGROW|wxALL, 5);
    m_labID = new wxStaticText( m_IndexPanel, wxID_ANY, _("Action ID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer12->Add(m_labID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxArrayString m_IDStrings;
    m_ID = new wxChoice( m_IndexPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_IDStrings, 0 );
    itemFlexGridSizer12->Add(m_ID, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_labState = new wxStaticText( m_IndexPanel, wxID_ANY, _("State"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer12->Add(m_labState, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxArrayString m_StateStrings;
    m_State = new wxComboBox( m_IndexPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_StateStrings, wxCB_DROPDOWN );
    itemFlexGridSizer12->Add(m_State, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_labSubState = new wxStaticText( m_IndexPanel, wxID_ANY, _("Substate"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer12->Add(m_labSubState, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_SubStateStrings;
    m_SubState = new wxComboBox( m_IndexPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_SubStateStrings, wxCB_DROPDOWN );
    itemFlexGridSizer12->Add(m_SubState, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labDuration = new wxStaticText( m_IndexPanel, wxID_ANY, _("Duration"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer12->Add(m_labDuration, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxFlexGridSizer* itemFlexGridSizer20 = new wxFlexGridSizer(0, 4, 0, 0);
    itemFlexGridSizer12->Add(itemFlexGridSizer20, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    m_Duration = new wxSpinCtrl( m_IndexPanel, wxID_ANY, _T("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 0 );
    itemFlexGridSizer20->Add(m_Duration, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_labTimer = new wxStaticText( m_IndexPanel, wxID_ANY, _("Timer"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer20->Add(m_labTimer, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_Timer = new wxSpinCtrl( m_IndexPanel, wxID_ANY, _T("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10000, 0 );
    itemFlexGridSizer20->Add(m_Timer, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_labLocoID = new wxStaticText( m_IndexPanel, wxID_ANY, _("Loco ID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer12->Add(m_labLocoID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxArrayString m_LocoIDStrings;
    m_LocoID = new wxChoice( m_IndexPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_LocoIDStrings, 0 );
    itemFlexGridSizer12->Add(m_LocoID, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_labDesc = new wxStaticText( m_IndexPanel, wxID_ANY, _("Description"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer12->Add(m_labDesc, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Desc = new wxTextCtrl( m_IndexPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer12->Add(m_Desc, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer12->AddGrowableCol(1);

    wxFlexGridSizer* itemFlexGridSizer28 = new wxFlexGridSizer(0, 1, 0, 0);
    itemBoxSizer5->Add(itemFlexGridSizer28, 0, wxGROW, 5);
    wxFlexGridSizer* itemFlexGridSizer29 = new wxFlexGridSizer(0, 2, 0, 0);
    itemFlexGridSizer28->Add(itemFlexGridSizer29, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    m_Reset = new wxCheckBox( m_IndexPanel, wxID_ANY, _("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Reset->SetValue(true);
    itemFlexGridSizer29->Add(m_Reset, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_AllConditions = new wxCheckBox( m_IndexPanel, wxID_ANY, _("All conditions must be true"), wxDefaultPosition, wxDefaultSize, 0 );
    m_AllConditions->SetValue(true);
    itemFlexGridSizer29->Add(m_AllConditions, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_AtCommand = new wxCheckBox( m_IndexPanel, wxID_ANY, _("At command"), wxDefaultPosition, wxDefaultSize, 0 );
    m_AtCommand->SetValue(false);
    itemFlexGridSizer29->Add(m_AtCommand, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_AtEvent = new wxCheckBox( m_IndexPanel, wxID_ANY, _("At event"), wxDefaultPosition, wxDefaultSize, 0 );
    m_AtEvent->SetValue(false);
    itemFlexGridSizer29->Add(m_AtEvent, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxArrayString m_AutoStrings;
    m_AutoStrings.Add(_("&Auto"));
    m_AutoStrings.Add(_("&Manual"));
    m_AutoStrings.Add(_("&Both"));
    m_Auto = new wxRadioBox( m_IndexPanel, ID_RADIOBOX, _("Mode"), wxDefaultPosition, wxDefaultSize, m_AutoStrings, 1, wxRA_SPECIFY_ROWS );
    m_Auto->SetSelection(0);
    itemFlexGridSizer28->Add(m_Auto, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer35 = new wxFlexGridSizer(0, 3, 0, 0);
    itemBoxSizer5->Add(itemFlexGridSizer35, 0, wxGROW|wxALL, 5);
    m_Add = new wxButton( m_IndexPanel, ID_ACTIONCTRL_ADD, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer35->Add(m_Add, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Delete = new wxButton( m_IndexPanel, ID_ACTIONCTRL_DELETE, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer35->Add(m_Delete, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Modify = new wxButton( m_IndexPanel, ID_ACTIONCTRL_MODIFY, _("Modify"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer35->Add(m_Modify, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Notebook->AddPage(m_IndexPanel, _("Index"));

    m_ConditionsPanel = new wxPanel( m_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer40 = new wxBoxSizer(wxVERTICAL);
    m_ConditionsPanel->SetSizer(itemBoxSizer40);

    m_Conditions = new wxListCtrl( m_ConditionsPanel, ID_CONDITIONS, wxDefaultPosition, wxSize(100, 100), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES );
    itemBoxSizer40->Add(m_Conditions, 1, wxGROW|wxALL, 5);

    m_CondMust = new wxCheckBox( m_ConditionsPanel, wxID_ANY, _("Must be true"), wxDefaultPosition, wxDefaultSize, 0 );
    m_CondMust->SetValue(false);
    itemBoxSizer40->Add(m_CondMust, 0, wxALIGN_LEFT|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer43 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer40->Add(itemFlexGridSizer43, 0, wxGROW|wxALL, 5);
    m_labCondType = new wxStaticText( m_ConditionsPanel, wxID_ANY, _("Type"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer43->Add(m_labCondType, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_CondTypeStrings;
    m_CondType = new wxChoice( m_ConditionsPanel, ID_ACTIONCTRL_COND_TYPE, wxDefaultPosition, wxDefaultSize, m_CondTypeStrings, 0 );
    itemFlexGridSizer43->Add(m_CondType, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labCondID = new wxStaticText( m_ConditionsPanel, wxID_ANY, _("ID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer43->Add(m_labCondID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_CondIDStrings;
    m_CondID = new wxComboBox( m_ConditionsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_CondIDStrings, wxCB_DROPDOWN );
    itemFlexGridSizer43->Add(m_CondID, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labSubID = new wxStaticText( m_ConditionsPanel, wxID_ANY, _("Sub-ID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer43->Add(m_labSubID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SubID = new wxTextCtrl( m_ConditionsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer43->Add(m_SubID, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labCondState = new wxStaticText( m_ConditionsPanel, wxID_ANY, _("State"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer43->Add(m_labCondState, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_CondStateStrings;
    m_CondState = new wxComboBox( m_ConditionsPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_CondStateStrings, wxCB_DROPDOWN );
    itemFlexGridSizer43->Add(m_CondState, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer43->AddGrowableCol(1);

    wxBoxSizer* itemBoxSizer52 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer40->Add(itemBoxSizer52, 0, wxGROW|wxALL, 5);
    m_CondAdd = new wxButton( m_ConditionsPanel, ID_ACTIONCTRL_COND_ADD, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer52->Add(m_CondAdd, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CondDelete = new wxButton( m_ConditionsPanel, ID_ACTIONCTRL_COND_DELETE, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer52->Add(m_CondDelete, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CondModify = new wxButton( m_ConditionsPanel, ID_ACTIONCTRL_COND_MODIFY, _("Modify"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer52->Add(m_CondModify, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Notebook->AddPage(m_ConditionsPanel, _("Conditions"));

    itemBoxSizer2->Add(m_Notebook, 1, wxGROW|wxALL, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer56 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer56, 0, wxGROW|wxALL, 5);
    m_OK = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer56->AddButton(m_OK);

    m_Cancel = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer56->AddButton(m_Cancel);

    m_Apply = new wxButton( itemDialog1, wxID_APPLY, _("&Apply"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer56->AddButton(m_Apply);

    wxButton* itemButton60 = new wxButton( itemDialog1, wxID_HELP, _("&Help"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer56->AddButton(itemButton60);

    itemStdDialogButtonSizer56->Realize();

////@end ActionsCtrlDlg content construction
}


/*!
 * Should we show tooltips?
 */

bool ActionsCtrlDlg::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap ActionsCtrlDlg::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin ActionsCtrlDlg bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end ActionsCtrlDlg bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon ActionsCtrlDlg::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin ActionsCtrlDlg icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end ActionsCtrlDlg icon retrieval
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ACTIONCTRL_ADD
 */

void ActionsCtrlDlg::OnActionctrlAddClick( wxCommandEvent& event )
{
  addActionCtrl();
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ACTIONCTRL_DELETE
 */

void ActionsCtrlDlg::OnActionctrlDeleteClick( wxCommandEvent& event )
{
  deleteSelected();
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ACTIONCTRL_MODIFY
 */

void ActionsCtrlDlg::OnActionctrlModifyClick( wxCommandEvent& event )
{
  evaluate();
  //initIndex();
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void ActionsCtrlDlg::OnCancelClick( wxCommandEvent& event )
{
  cleanUp();
  EndModal( 0 );
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_APPLY
 */

void ActionsCtrlDlg::OnApplyClick( wxCommandEvent& event )
{
  evaluateCond();
  evaluate();
  apply();
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void ActionsCtrlDlg::OnOkClick( wxCommandEvent& event )
{
  OnApplyClick(event);
  EndModal( wxID_OK );
}


/*!
 * wxEVT_COMMAND_LISTBOX_SELECTED event handler for ID_ACTIONCTRL_LIST
 */

void ActionsCtrlDlg::OnActionctrlListSelected( wxCommandEvent& event )
{
  wxArrayInt ai;
  int cnt = m_CtrlList->GetSelections(ai);
  if( cnt == 0 ) {
    return;
  }
  m_Up->Enable(cnt==1);
  m_Down->Enable(cnt==1);
  m_Delete->Enable(cnt==1);
  m_Modify->Enable(cnt==1);
  m_ConditionsPanel->Enable(cnt==1);

  if( cnt == 1 ) {
    m_iCursel = ai.Item(0);
    initValues();
  }
  else {
    m_iCursel = wxNOT_FOUND;
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ACTIONCTRL_CONDITIONS
 */

void ActionsCtrlDlg::OnConditionsSelected( wxListEvent& event )
{
  m_iCurCondsel = event.GetIndex();
  initCondValues();
}


/*!
 * wxEVT_COMMAND_CHOICE_SELECTED event handler for ID_ACTIONCTRL_COND_TYPE
 */

void ActionsCtrlDlg::OnActionctrlCondTypeSelected( wxCommandEvent& event )
{
  initCondIDs();
}


void ActionsCtrlDlg::OnActionctrlCondAddClick( wxCommandEvent& event )
{
  addActionCond();
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ACTIONCTRL_COND_DELETE
 */

void ActionsCtrlDlg::OnActionctrlCondDeleteClick( wxCommandEvent& event )
{
  deleteSelectedCond();
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ACTIONCTRL_COND_MODIFY
 */

void ActionsCtrlDlg::OnActionctrlCondModifyClick( wxCommandEvent& event )
{
  evaluateCond();
  initValues();
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ACTIONCTRL_DOWN
 */

void ActionsCtrlDlg::OnActionctrlDownClick( wxCommandEvent& event )
{
  if( m_Props == NULL || m_iCursel == wxNOT_FOUND)
    return;

  int cursel = m_iCursel;
  int count  = m_CtrlList->GetCount();

  TraceOp.trc( "acdlg", TRCLEVEL_INFO, __LINE__, 9999, "down: cursel=%d count=%d", cursel, count );

  if( cursel != wxNOT_FOUND && cursel != (count-1) ) {
    iOList list = ListOp.inst();

    for( int i = 0; i < count; i++ ) {
      ListOp.add( list, (obj)m_CtrlList->GetClientData(i));
    }

    m_CtrlList->Clear();

    for( int i = 0; i < ListOp.size(list); i++ ) {
      if( i == cursel && (i+1 < ListOp.size(list)) ) {
        iONode actionctrl = (iONode)ListOp.get(list, i+1);
        m_CtrlList->Append( wxString(wActionCtrl.getid(actionctrl),wxConvUTF8), actionctrl );
        actionctrl = (iONode)ListOp.get(list, i);
        m_CtrlList->Append( wxString(wActionCtrl.getid(actionctrl),wxConvUTF8), actionctrl );
        i++;
      }
      else {
        iONode actionctrl = (iONode)ListOp.get(list, i);
        m_CtrlList->Append( wxString(wActionCtrl.getid(actionctrl),wxConvUTF8), actionctrl );
      }
    }

    ListOp.base.del(list);
    clearIndexSelection();
    m_iCursel = cursel+1;
    m_CtrlList->SetSelection(cursel+1);
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ACTIONCTRL_UP
 */

void ActionsCtrlDlg::OnActionctrlUpClick( wxCommandEvent& event )
{
  if( m_Props == NULL || m_iCursel == wxNOT_FOUND)
    return;
  int cursel = m_iCursel;
  int count  = m_CtrlList->GetCount();

  TraceOp.trc( "acdlg", TRCLEVEL_INFO, __LINE__, 9999, "down: cursel=%d count=%d", cursel, count );

  if( cursel != wxNOT_FOUND && cursel != 0 ) {
    iOList list = ListOp.inst();

    for( int i = 0; i < count; i++ ) {
      ListOp.add( list, (obj)m_CtrlList->GetClientData(i));
    }

    m_CtrlList->Clear();

    for( int i = 0; i < ListOp.size(list); i++ ) {
      if( i + 1 == cursel ) {
        iONode actionctrl = (iONode)ListOp.get(list, i+1);
        m_CtrlList->Append( wxString(wActionCtrl.getid(actionctrl),wxConvUTF8), actionctrl );
        actionctrl = (iONode)ListOp.get(list, i);
        m_CtrlList->Append( wxString(wActionCtrl.getid(actionctrl),wxConvUTF8), actionctrl );
        i++;
      }
      else {
        iONode actionctrl = (iONode)ListOp.get(list, i);
        m_CtrlList->Append( wxString(wActionCtrl.getid(actionctrl),wxConvUTF8), actionctrl );
      }
    }

    ListOp.base.del(list);
    clearIndexSelection();
    m_iCursel = cursel-1;
    m_CtrlList->SetSelection(cursel-1);
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ACTIONCTRL_COPY
 */

void ActionsCtrlDlg::OnActionctrlCopyClick( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  wxArrayInt ai;
  int cnt = m_CtrlList->GetSelections(ai);

  if( cnt == 0 )
    return;

  iONode container = NodeOp.inst(wItem.name(), NULL, ELEMENT_NODE);
  for( int i = 0; i < cnt; i++ ) {
    int idx = ai.Item(i);
    iONode actionctrl = (iONode)NodeOp.base.clone(m_CtrlList->GetClientData(idx));
    NodeOp.addChild( container, actionctrl);
  }

  char* str = NodeOp.toEscString(container);

  wxString text(str,wxConvUTF8);
  wxClipboard* cb = wxTheClipboard;
  if( cb != NULL ) {
    if( cb->Open() ) {
      if( !text.IsEmpty() ) {
        wxTextDataObject *data = new wxTextDataObject( text );
        cb->SetData( data );
      }
      cb->Close();
    }
  }

  StrOp.free(str);
  NodeOp.base.del(container);
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ACTIONCTRL_PASTE
 */

void ActionsCtrlDlg::OnActionctrlPasteClick( wxCommandEvent& event )
{
  wxClipboard* cb = wxTheClipboard;
  if( cb != NULL ) {
    if( cb->Open() ) {
      if( cb->IsSupported( wxDF_TEXT )) {
        wxTextDataObject data;
        cb->GetData( data );
        char* str = StrOp.dup(data.GetText().mb_str(wxConvUTF8) );
        iODoc doc = DocOp.parse(str);
        if( doc != NULL ) {
          iONode container = DocOp.getRootNode(doc);
          if( container != NULL ) {
            int cnt = NodeOp.getChildCnt(container);
            for( int i = 0; i < cnt; i++ ) {
              iONode actionctrl = NodeOp.getChild(container, i);
              if( StrOp.equals( wActionCtrl.name(), NodeOp.getName(actionctrl)))
                m_CtrlList->Append( wxString( wActionCtrl.getid(actionctrl),wxConvUTF8 ), NodeOp.base.clone(actionctrl) );
            }
            NodeOp.base.del(container);
          }
          DocOp.base.del(doc);
        }
      }
      cb->Close();
    }
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
 */

void ActionsCtrlDlg::OnHelpClick( wxCommandEvent& event )
{
  switch( m_Notebook->GetSelection() ) {
  case 0: wxGetApp().openLink( "actionctrl" ); break;
  case 1: wxGetApp().openLink( "actioncond" ); break;
  default: wxGetApp().openLink( "actionctrl" ); break;
  }

}

