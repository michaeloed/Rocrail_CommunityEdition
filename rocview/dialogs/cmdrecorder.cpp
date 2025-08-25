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
#include "cmdrecorder.h"

#include "rocs/public/strtok.h"

#include "rocview/symbols/svg.h"
#include "rocview/public/base.h"
#include "rocview/res/icons.hpp"
#include "rocview/dialogs/routedialog.h"

#include "rocview/public/guiapp.h"
#include "rocrail/public/script.h"
#include "rocview/wrapper/public/Gui.h"
#include "rocrail/wrapper/public/Route.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/Stage.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/SwitchCmd.h"
#include "rocrail/wrapper/public/FeedbackEvent.h"


#define ME_CmdTimer 4711

CmdRecorder::CmdRecorder( wxWindow* parent )
  :CmdRecorderGen( parent )
{
  m_Me = NULL;
  m_Stop->SetBitmapLabel(*_img_stop);
  m_Pause->SetBitmapLabel(*_img_pause);
  m_Record->SetBitmapLabel(*_img_record);
  m_Play->SetBitmapLabel(*_img_play);
  m_Stop->Refresh();
  m_Pause->Refresh();
  m_Record->Refresh();
  m_Play->Refresh();

  initLabels();
  GetSizer()->Layout();
  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);

  Boolean recording = ScriptOp.isRecording(wxGetApp().getScript());
  Boolean playing   = ScriptOp.isPlaying(wxGetApp().getScript(), NULL);

  m_Record->Enable( recording?false:true );
  m_Play->Enable( recording?false:true );
  m_Pause->Enable( recording?false:true );

  m_Timer = new wxTimer( this, ME_CmdTimer );
  Connect( wxEVT_TIMER, wxTimerEventHandler( CmdRecorder::OnTimer ), NULL, this );

  initList();
}


void CmdRecorder::initLabels() {
  SetTitle(wxGetApp().getMsg( "cmdrecorder" ));
  m_Modify->SetLabel( wxGetApp().getMsg( "modify" ) );
  m_Insert->SetLabel( wxGetApp().getMsg( "insert" ) );
  m_Delete->SetLabel( wxGetApp().getMsg( "delete" ) );
  m_Export->SetLabel( wxGetApp().getMsg( "export" ) );
  m_Import->SetLabel( wxGetApp().getMsg( "import" ) );
  m_Stamp->SetLabel( wxGetApp().getMsg( "stamp" ) );
  m_Clear->SetLabel( wxGetApp().getMsg( "clearall" ) );
  m_CreateRoute->SetLabel( wxGetApp().getMsg( "route" ) + wxT("..."));
}


void CmdRecorder::onRecord( wxCommandEvent& event )
{
  if( !ScriptOp.isRecording(wxGetApp().getScript()) ) {
    ScriptOp.setRecording(wxGetApp().getScript(), True, m_Stamp->IsChecked()?True:False);
    m_Record->Enable( false );
    m_Play->Enable( false );
    m_Pause->Enable( false );
    m_labStatus->SetLabel( wxGetApp().getMsg( "recording" ) );
  }
}

void CmdRecorder::onStop( wxCommandEvent& event )
{
  if( ScriptOp.isRecording(wxGetApp().getScript()) ) {
    ScriptOp.setRecording(wxGetApp().getScript(), False, False);
    m_Record->Enable( true );
    m_Play->Enable( true );
    m_Pause->Enable( true );
    initList();
  }

  if( ScriptOp.isPlaying(wxGetApp().getScript(), NULL) ) {
    ScriptOp.Stop(wxGetApp().getScript());
  }
  m_labStatus->SetLabel( wxGetApp().getMsg( "stopped" ) );

}

void CmdRecorder::onPause( wxCommandEvent& event )
{
  int linenr = 0;
  if( ScriptOp.isPlaying(wxGetApp().getScript(), &linenr ) ) {
    ScriptOp.Pause(wxGetApp().getScript());
    m_labStatus->SetLabel( wxGetApp().getMsg( "paused" ) );
  }
  if( m_CmdList->GetCount() > linenr )
    m_CmdList->SetSelection(linenr);
}

void CmdRecorder::onPlay( wxCommandEvent& event )
{
  if( !ScriptOp.isRecording(wxGetApp().getScript()) ) {
    ScriptOp.Play(wxGetApp().getScript());
    m_labStatus->SetLabel( wxGetApp().getMsg( "playing" ) );
    m_Timer->Start( 1000, wxTIMER_ONE_SHOT );
  }
}

void CmdRecorder::onCmdSelected( wxCommandEvent& event )
{
  int sel = m_CmdList->GetSelection();
  if( sel != wxNOT_FOUND ) {
    m_Cmd->SetValue(m_CmdList->GetString(sel));
  }
}

void CmdRecorder::onModify( wxCommandEvent& event )
{
  int sel = m_CmdList->GetSelection();
  if( sel != wxNOT_FOUND ) {
    m_CmdList->SetString(sel, m_Cmd->GetValue());
    int cnt = m_CmdList->GetCount();
    char* script = NULL;
    for( int i = 0; i < cnt; i++ ) {
      script = StrOp.cat( script, m_CmdList->GetString(i).mb_str(wxConvUTF8) );
      script = StrOp.cat( script, "\n" );
    }
    ScriptOp.setScript(wxGetApp().getScript(), script);
    initList();
  }
}

void CmdRecorder::onExport( wxCommandEvent& event )
{
  const char* l_openpath = wGui.getopenpath( wxGetApp().getIni() );
  wxString ms_FileExt = _T("Commands (*.txt)|*.txt");
  wxFileDialog* fdlg = new wxFileDialog(this, wxGetApp().getMenu("export"), wxString(l_openpath,wxConvUTF8), _T(""), ms_FileExt, wxFD_SAVE);
  if( fdlg->ShowModal() == wxID_OK ) {
    iONode model = wxGetApp().getModel();
    // Check for existence.
    wxString path = fdlg->GetPath();
    if( FileOp.exist( path.mb_str(wxConvUTF8) ) ) {
      int action = wxMessageDialog( this, wxGetApp().getMsg("fileexistwarning"), _T("Rocrail"), wxYES_NO | wxICON_EXCLAMATION ).ShowModal();
      if( action == wxID_NO ) {
        fdlg->Destroy();
        return;
      }
    }
    if( !path.Contains( _T(".txt") ) )
      path.Append( _T(".txt") );

    iOFile f = FileOp.inst( path.mb_str(wxConvUTF8), OPEN_WRITE );
    if( f != NULL ) {
      const char* cmds = ScriptOp.base.toString(wxGetApp().getScript());
      FileOp.writeStr(f, cmds);
      FileOp.base.del( f );
    }

  }

  fdlg->Destroy();
}

void CmdRecorder::initList() {
  m_CmdList->Clear();
  const char* cmds = ScriptOp.base.toString(wxGetApp().getScript());
  iOStrTok tok = StrTokOp.inst(cmds, '\n');
  while( StrTokOp.hasMoreTokens(tok)) {
    const char* cmd = StrTokOp.nextToken(tok);
    m_CmdList->Append(wxString(cmd,wxConvUTF8));
  }
  if( m_CmdList->GetCount() > 0 ) {
    m_CmdList->SetFirstItem(0);
  }
}

void CmdRecorder::onImport( wxCommandEvent& event )
{
  wxString ms_FileExt = _T("Commands (*.txt)|*.txt");
  const char* l_openpath = wGui.getopenpath( wxGetApp().getIni() );
  wxFileDialog* fdlg = new wxFileDialog(this, wxGetApp().getMenu("import"), wxString(l_openpath,wxConvUTF8) , _T(""), ms_FileExt, wxFD_OPEN);
  if( fdlg->ShowModal() == wxID_OK ) {

    if( fdlg->GetPath().Len() > 0 && FileOp.exist(fdlg->GetPath().mb_str(wxConvUTF8)) ) {
      iOFile f = FileOp.inst( fdlg->GetPath().mb_str(wxConvUTF8), OPEN_READONLY );
      char* buffer = (char*)allocMem( FileOp.size( f ) +1 );
      FileOp.read( f, buffer, FileOp.size( f ) );
      ScriptOp.setScript(wxGetApp().getScript(), buffer);
      FileOp.base.del( f );
      initList();
    }

  }
  fdlg->Destroy();
}

void CmdRecorder::onDelete( wxCommandEvent& event )
{
  int sel = m_CmdList->GetSelection();
  if( sel != wxNOT_FOUND ) {
    m_CmdList->Delete(sel);
    int cnt = m_CmdList->GetCount();
    char* script = NULL;
    for( int i = 0; i < cnt; i++ ) {
      script = StrOp.cat( script, m_CmdList->GetString(i).mb_str(wxConvUTF8) );
      script = StrOp.cat( script, "\n" );
    }
    ScriptOp.setScript(wxGetApp().getScript(), script);
    initList();
  }
}

void CmdRecorder::onInsert( wxCommandEvent& event )
{
  int sel = m_CmdList->GetSelection();
  if( sel != wxNOT_FOUND ) {
    m_CmdList->Insert(m_Cmd->GetValue(), sel);
  }
  else {
    m_CmdList->Append(m_Cmd->GetValue());
  }
  int cnt = m_CmdList->GetCount();
  char* script = NULL;
  for( int i = 0; i < cnt; i++ ) {
    script = StrOp.cat( script, m_CmdList->GetString(i).mb_str(wxConvUTF8) );
    script = StrOp.cat( script, "\n" );
  }
  ScriptOp.setScript(wxGetApp().getScript(), script);
  initList();
}

void CmdRecorder::onOK( wxCommandEvent& event )
{
  if( m_Me != NULL )
    *m_Me = NULL;
  Destroy();
}

void CmdRecorder::onClose( wxCloseEvent& event )
{
  if( m_Me != NULL )
    *m_Me = NULL;
  Destroy();
}

void CmdRecorder::onClear( wxCommandEvent& event ) {
  ScriptOp.setScript(wxGetApp().getScript(), "");
  initList();
}


void CmdRecorder::OnTimer(wxTimerEvent& event) {
  if( event.GetId() == ME_CmdTimer ) {
    if( ScriptOp.isPlaying(wxGetApp().getScript(), NULL) )
      m_Timer->Start( 1000, wxTIMER_ONE_SHOT );
    else
      m_labStatus->SetLabel( wxT("") );
  }
}

void CmdRecorder::onHelp( wxCommandEvent& event ) {
  wxGetApp().openLink( "rocview:cmdrecorder" );
}


void CmdRecorder::onCreateRoute( wxCommandEvent& event ) {
  iONode route = NodeOp.inst(wRoute.name(), NULL, ELEMENT_NODE);
  iONode node = ScriptOp.nextLine(wxGetApp().getScript(), False);
  while(node != NULL) {
    TraceOp.trc( "cmdrecorder", TRCLEVEL_INFO, __LINE__, 9999, "route element: %s", NodeOp.getName(node) );
    if( StrOp.equals(wBlock.name(), NodeOp.getName(node)) || StrOp.equals(wStage.name(), NodeOp.getName(node)) ) {
      if( wRoute.getbka(route) == NULL ) {
        wRoute.setbka(route, wBlock.getid(node));
        wRoute.setbkaside(route, True);
        if( StrOp.equals( wBlock.bsm, wBlock.getcmd(node) ) )
          wRoute.setbkaside(route, False);
      }
      else if( wRoute.getbkb(route) == NULL ) {
        char* routeid = NULL;
        wRoute.setbkb(route, wBlock.getid(node));
        wRoute.setbkbside(route, True);
        if( StrOp.equals( wBlock.bsm, wBlock.getcmd(node) ) )
          wRoute.setbkbside(route, False);

        routeid = StrOp.fmt("[%s%c]-[%s%c]", wRoute.getbka(route), wRoute.isbkaside(route)?'+':'-',
            wRoute.getbkb(route), wRoute.isbkbside(route)?'+':'-');
        wRoute.setid(route, routeid);
        StrOp.free(routeid);
      }
      else {
        // Crossing block?
        char* bkc = StrOp.dup(wRoute.getbkc(route));
        if( bkc == NULL || StrOp.len(bkc) == 0 )
          bkc = StrOp.cat(bkc, wBlock.getid(node) );
        else {
          bkc = StrOp.cat(bkc, "," );
          bkc = StrOp.cat(bkc, wBlock.getid(node) );
        }
        wRoute.setbkc(route, bkc);
        StrOp.free(bkc);
      }
    }

    else if( StrOp.equals(wSwitch.name(), NodeOp.getName(node)) ) {
      iONode swcmd = NodeOp.inst(wSwitchCmd.name(), route, ELEMENT_NODE );
      wSwitchCmd.setid(swcmd, wSwitch.getid(node));
      wSwitchCmd.setcmd(swcmd, wSwitch.getcmd(node));
      NodeOp.addChild(route, swcmd);
    }

    else if( StrOp.equals(wSignal.name(), NodeOp.getName(node)) ) {
      iONode swcmd = NodeOp.inst(wSwitchCmd.name(), route, ELEMENT_NODE );
      wSwitchCmd.setid(swcmd, wSignal.getid(node));
      wSwitchCmd.setcmd(swcmd, wSignal.getcmd(node));
      NodeOp.addChild(route, swcmd);
    }

    else if( StrOp.equals(wFeedback.name(), NodeOp.getName(node)) ) {
      iONode fbevent = NodeOp.inst(wFeedbackEvent.name(), route, ELEMENT_NODE );
      wFeedbackEvent.setid(fbevent, wFeedback.getid(node));
      NodeOp.addChild(route, fbevent);
    }

    NodeOp.base.del(node);

    node = ScriptOp.nextLine(wxGetApp().getScript(), False);
    if( node == NULL ) {
      // could be a pause...
      node = ScriptOp.nextLine(wxGetApp().getScript(), False);
    }
  }

  if( wRoute.getid(route) != NULL && StrOp.len(wRoute.getid(route)) > 0 ) {
    RouteDialog* dlg = new RouteDialog( this, route, false, true );
    if( wxID_OK == dlg->ShowModal() ) {
      if( !wxGetApp().isStayOffline() ) {
        /* Notify RocRail. */
        iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
        wModelCmd.setcmd( cmd, wModelCmd.modify );
        NodeOp.addChild( cmd, route );
        wxGetApp().sendToRocrail( cmd );
        cmd->base.del(cmd);
      }
    }
    dlg->Destroy();
  }
  else {
    char* str = NodeOp.base.toString(route);
    TraceOp.trc( "cmdrecorder", TRCLEVEL_INFO, __LINE__, 9999, "no valid route: %s", str );
    StrOp.free(str);
    NodeOp.base.del(route);
  }


}


