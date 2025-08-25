/*
 * This is part of FreeRail - Model Railway Software
 * 
 * Copyright: See AUTHORS at the top-level directory of this project and
 * at GitHub <https://github.com/michaeloed/FreeRail/>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------
#ifdef __GNUG__
    #pragma implementation "rocgui.cpp"
    #pragma interface "rocgui.cpp"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWindows headers)
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include <signal.h>

#ifdef __linux__
#include <sys/resource.h>
#endif

#include <wx/image.h>
#include <wx/filedlg.h>
#include <wx/splash.h>
#include <wx/fs_zip.h>
#include <wx/help.h>
#include <wx/cshelp.h>
#include "wx/notebook.h"


#include "rocs/public/str.h"
#include "rocs/public/file.h"
#include "rocs/public/doc.h"
#include "rocs/public/node.h"
#include "rocs/public/mem.h"
#include "rocs/public/res.h"
#include "rocs/public/wrpinf.h"
#include "rocs/public/system.h"
#include "rocs/public/strtok.h"

#include "rocview/public/guiapp.h"

#include "rocview/wrapper/public/Gui.h"
#include "rocview/wrapper/public/RRCon.h"
#include "rocview/wrapper/public/PlanPanel.h"
#include "rocview/wrapper/public/SplitPanel.h"
#include "rocview/wrapper/public/Window.h"
#include "rocview/wrapper/public/Cmdline.h"
#include "rocview/wrapper/public/LcCtrl.h"


#include "rocrail/wrapper/public/Trace.h"
#include "rocrail/wrapper/public/Plan.h"
#include "rocrail/wrapper/public/ModPlan.h"
#include "rocrail/wrapper/public/Module.h"
#include "rocrail/wrapper/public/TrackList.h"
#include "rocrail/wrapper/public/RouteList.h"
#include "rocrail/wrapper/public/BlockList.h"
#include "rocrail/wrapper/public/FeedbackList.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/SwitchList.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/SignalList.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/OutputList.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/TurntableList.h"
#include "rocrail/wrapper/public/LocList.h"
#include "rocrail/wrapper/public/DigInt.h"
#include "rocrail/wrapper/public/Exception.h"
#include "rocrail/wrapper/public/Response.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/Loc.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/AutoCmd.h"
#include "rocrail/wrapper/public/ZLevel.h"
#include "rocrail/wrapper/public/FreeRail.h"
#include "rocrail/wrapper/public/Program.h"
#include "rocrail/wrapper/public/Clock.h"
#include "rocrail/wrapper/public/State.h"
#include "rocrail/wrapper/public/Route.h"
#include "rocrail/wrapper/public/Schedule.h"
#include "rocrail/wrapper/public/Tour.h"
#include "rocrail/wrapper/public/Location.h"
#include "rocrail/wrapper/public/LocationList.h"
#include "rocrail/wrapper/public/ScheduleList.h"
#include "rocrail/wrapper/public/TourList.h"
#include "rocrail/wrapper/public/LocationList.h"
#include "rocrail/wrapper/public/LinkList.h"
#include "rocrail/wrapper/public/SvnLog.h"
#include "rocrail/wrapper/public/SvnLogEntry.h"
#include "rocrail/wrapper/public/DataReq.h"
#include "rocrail/wrapper/public/Item.h"
#include "rocrail/wrapper/public/CarList.h"
#include "rocrail/wrapper/public/OperatorList.h"
#include "rocrail/wrapper/public/Car.h"
#include "rocrail/wrapper/public/Operator.h"
#include "rocrail/wrapper/public/PwrEvent.h"
#include "rocrail/wrapper/public/FunCmd.h"
#include "rocrail/wrapper/public/SelTab.h"
#include "rocrail/wrapper/public/Turntable.h"
#include "rocrail/wrapper/public/Booster.h"
#include "rocrail/wrapper/public/Dec.h"
#include "rocrail/wrapper/public/DecList.h"
#include "rocrail/wrapper/public/Variable.h"
#include "rocrail/wrapper/public/VariableList.h"
#include "rocrail/wrapper/public/CVByte.h"

#include "rocview/res/icons.hpp"

#include "common/version.h"

// ----------------------------------------------------------------------------
// resources
// ----------------------------------------------------------------------------


IMPLEMENT_APP(RocGui)

RocGui::RocGui():wxApp() {
  wxSetEnv(wxT("UBUNTU_MENUPROXY"), wxT("0"));
}


static const int itemSize = 32;
int RocGui::getItemSize() {
  return itemSize;
}

int RocGui::getTabAlign() {
  int tabalign = wGui.gettabalign( m_Ini );
  switch( tabalign ){
    case 0:
      return wxNB_DEFAULT;
    case 1:
      return wxNB_LEFT;
    case 2:
      return wxNB_MULTILINE;
  }
  return wxNB_DEFAULT;
}

bool RocGui::isRestrictedEdit() {
  return wGui.isrestrictedit4auto( m_Ini );
}

static void rocrailCallback( obj me, iONode node );

// ============================================================================
// implementation
// ============================================================================

static void ExceptionCallback( int level, char* msg ) {
  /* Added check for VSC++ uninitialized pointer in debug mode */
  TraceOp.trc( "app", TRCLEVEL_DEBUG, __LINE__, 9999, "Got an info message: %s", msg );
  if ( ( wxGetApp().getFrame() != NULL ) && ( wxGetApp().getFrame() != (RocGuiFrame *)0xcdcdcdcd )) {
    if( wxGetApp().getFrame()->isInitialized() ) {
      wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ADDEXCEPTION_EVENT );
      // Make a copy of the node for using it out of this scope:
      iONode node = NodeOp.inst( wException.name(), NULL, ELEMENT_NODE );
      wException.settext( node, msg );
      event.SetClientData( node );
      wxPostEvent( wxGetApp().getFrame(), event );
    }
  }
}

// ----------------------------------------------------------------------------
// the application class
// ----------------------------------------------------------------------------

iONode RocGui::getModel(bool create) {
  if( m_Model == NULL && create) {
    TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999, "Creating Model..." );
    m_Frame->setLocalPlan( _T("") );
  }
  return m_Model;
}

bool RocGui::isModelSet() {
  return m_Model != NULL ? true:false;
}

void RocGui::disConnect() {
  if( m_RCon != NULL ) {
    RConOp.close( m_RCon );
    RConOp.base.del( m_RCon );
    m_RCon = NULL;
  }
  m_bStayOffline = true;
  m_bOffline = true;
}

int RocGui::OnExit() {
  if( !m_bOnExit ) {
    TraceOp.setExceptionListener( m_Trace, NULL, False, False );

    RConOp.close( m_RCon );

    wxPoint point = this->getFrame()->GetPosition();
    if( wGui.getwindow( m_Ini ) == NULL ) {
      iONode node = NodeOp.inst( wWindow.name(), m_Ini, ELEMENT_NODE );
      NodeOp.addChild( m_Ini, node );
    }
    wWindow.setx( wGui.getwindow( m_Ini ), point.x );
    wWindow.sety( wGui.getwindow( m_Ini ), point.y );

    wxSize size = this->getFrame()->GetSize();
    if( size.GetWidth() > 100 && size.GetHeight() > 100 ) {
      wWindow.setcx( wGui.getwindow( m_Ini ), size.GetWidth() );
      wWindow.setcy( wGui.getwindow( m_Ini ), size.GetHeight() );
    }

#ifdef __APPLE__
    if( !wGui.isverticaltoolbar( m_Ini ) )
      wWindow.setcy( wGui.getwindow( m_Ini ), size.GetHeight() - 35 ); // hard coded work around for increasing height.
#endif

    if( wGui.getrrcon( m_Ini ) == NULL ) {
      iONode node = NodeOp.inst( wRRCon.name(), m_Ini, ELEMENT_NODE );
      NodeOp.addChild( m_Ini, node );
    }
    wRRCon.sethost( wGui.getrrcon( m_Ini ), m_Host );
    wRRCon.setport( wGui.getrrcon( m_Ini ), m_Port );

    if( wGui.getplanpanel( m_Ini ) == NULL ) {
      iONode node = NodeOp.inst( wPlanPanel.name(), m_Ini, ELEMENT_NODE );
      NodeOp.addChild( m_Ini, node );
    }

    wPlanPanel.setlocobook( wGui.getplanpanel( m_Ini ), m_Frame->isLocoBook() ? True:False );
    wPlanPanel.setplanbook( wGui.getplanpanel( m_Ini ), m_Frame->isPlanBook() ? True:False );
    wPlanPanel.settracewindow( wGui.getplanpanel( m_Ini ), m_Frame->isTraceWindow() ? True:False );
    wPlanPanel.setscale( wGui.getplanpanel( m_Ini ), m_Frame->getScale() );
    wPlanPanel.setshowid( wGui.getplanpanel( m_Ini ), m_Frame->isShowID() ? True:False );
    wPlanPanel.setshowcounters( wGui.getplanpanel( m_Ini ), m_Frame->isShowCounters() ? True:False );
    wPlanPanel.setraster( wGui.getplanpanel( m_Ini ), m_Frame->isRaster() ? True:False );
    wPlanPanel.settooltip( wGui.getplanpanel( m_Ini ), m_Frame->isTooltip() ? True:False );
    wPlanPanel.setshowlocked( wGui.getplanpanel( m_Ini ), m_Frame->isShowLocked() ? True:False );
    wPlanPanel.setshowpending( wGui.getplanpanel( m_Ini ), m_Frame->isShowPending() ? True:False );

    if( wGui.getsplitpanel( m_Ini ) == NULL ) {
      iONode node = NodeOp.inst( wSplitPanel.name(), m_Ini, ELEMENT_NODE );
      NodeOp.addChild( m_Ini, node );
    }
    wSplitPanel.setmain( wGui.getsplitpanel( m_Ini ), m_Frame->getSplitter()->GetSashPosition() );
    wSplitPanel.setmsg( wGui.getsplitpanel( m_Ini ), m_Frame->getTraceSplitter()->GetSashPosition() );

    if( m_Frame->getPlanSplitter()->GetSashPosition() > 1 )
      wSplitPanel.setplan( wGui.getsplitpanel( m_Ini ), m_Frame->getPlanSplitter()->GetSashPosition() );


    // Save LocControlDialog positions:

    // remove previous list:
    iONode lcctrl = wGui.getlcctrl(m_Ini);
    while( lcctrl != NULL ) {
      NodeOp.removeChild( m_Ini, lcctrl);
      lcctrl->base.del(lcctrl);
      lcctrl = wGui.getlcctrl(m_Ini);
    };


    if( m_Model != NULL ) {
      iONode lclist = wPlan.getlclist( m_Model );
      if( lclist != NULL ) {
        int i;
        int cnt = NodeOp.getChildCnt( lclist );
        for( i = 0; i < cnt; i++ ) {
          iONode lc = NodeOp.getChild( lclist, i );
          char* pos = (char*)MapOp.get( m_Frame->getLocDlgMap(), wLoc.getid(lc) );
          if( pos != NULL ) {
            TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999, "dialog position [%s] for [%s]", pos, wLoc.getid(lc) );

            iOStrTok tok = StrTokOp.inst( pos, ',' );
            int x = atoi( StrTokOp.nextToken(tok) );
            int y = atoi( StrTokOp.nextToken(tok) );
            StrTokOp.base.del(tok);
            lcctrl = NodeOp.inst( wLcCtrl.name(), m_Ini, ELEMENT_NODE );
            wLcCtrl.setid(lcctrl, wLoc.getid(lc));
            wLcCtrl.setx(lcctrl, x);
            wLcCtrl.sety(lcctrl, y);
            NodeOp.addChild( m_Ini, lcctrl);
          }
        }
      }
    }

    char* l_Ini = NodeOp.toEscString( m_Ini );
    printf( "ini=%s\n", l_Ini );
    m_IniFileName = CmdLnOp.getStrDef( m_CmdLn,"-i", wGui.inifile );
    iOFile iniFile = FileOp.inst( m_IniFileName, False );
    if( iniFile != NULL ) {
      FileOp.write( iniFile, l_Ini, StrOp.len( l_Ini ) );
      FileOp.close( iniFile );
    }
    StrOp.free( l_Ini );
    m_bOnExit = true;
  }
  return 0;
}

// Resource messages:
extern "C" {
  const char svnLog[] = "";
  extern const char messages[];
  extern const char wrapperinfo[];
  extern const char guiwrapperinfo[];
}

iONode RocGui::getWrpInf( const char* wrpname ) {
  return WrpInfOp.getWrapper( m_WrpInf, wrpname );
}
wxString RocGui::getMsg( const char* key ) {
  return wxString(ResOp.getMsg( m_Res, key ),wxConvUTF8);
}
const char* RocGui::getCMsg( const char* key ) {
  return ResOp.getMsg( m_Res, key );
}
wxString RocGui::getMenu( const char* key ) {
  wxString s = wxString(ResOp.getMenu( m_Res, key, False ),wxConvUTF8);
  //return s.Capitalize(); // wxWidgets 2.9+
  return s;
}
wxString RocGui::getTip( const char* key ) {
  return wxString(ResOp.getTip( m_Res, key ),wxConvUTF8);
}
void RocGui::openLink( const char* pagename, const char* section ) {
  const char* lang      = wGui.lang_english;
  const char* locallang = wGui.getlang(wxGetApp().getIni());
  const char* url       = wGui.gethelpurl(wxGetApp().getIni());
  char* pagefilename    = NULL;

  // allow local wiki translations
  if( StrOp.equals( wGui.lang_german, locallang ) || StrOp.equals( wGui.lang_italien, locallang ) ||
      StrOp.equals( wGui.lang_french, locallang ) || StrOp.equals( wGui.lang_dutch, locallang ) )
  {
    lang = locallang;
  }

  if( section == NULL )
    pagefilename = StrOp.fmt("%s/doku.php?id=%s-%s", url, pagename, lang);
  else
    pagefilename = StrOp.fmt("%s/doku.php?id=%s-%s#%s", url, pagename, lang, section);

  wxLaunchDefaultBrowser(wxString(pagefilename,wxConvUTF8 ), wxBROWSER_NEW_WINDOW );
  StrOp.free(pagefilename);
}


void RocGui::readArgs(const char* langfile) {
  // Read in all commandline filenames:
  for( int i = 1; i < argc; i++ ) {
    if( StrOp.endsWith( (const char*)wxString(argv[i]).mb_str(wxConvUTF8), ".rrp" ) ||
        StrOp.endsWith( (const char*)wxString(argv[i]).mb_str(wxConvUTF8), ".xml" ) )
    {
      // do not snap the alternative translations file
      if( langfile == NULL || !StrOp.equals( langfile, (const char*)wxString(argv[i]).mb_str(wxConvUTF8) ) ) {
        m_LocalPlan = argv[i];
        m_bStayOffline = true;
        break;
      }
    }
  }
}


void RocGui::pushUndoItem( iONode item ) {
   ListOp.insert(m_UndoItems, 0, (obj)item);
   if( ListOp.size(m_UndoItems) == 1 && wxGetApp().getFrame()->GetToolBar() != NULL)
     wxGetApp().getFrame()->GetToolBar()->EnableTool(ME_Undo, true );
}

iONode RocGui::popUndoItem() {
  if( ListOp.size( m_UndoItems ) > 0 ) {
    iONode item = (iONode)ListOp.get( m_UndoItems, 0 );
    ListOp.remove( m_UndoItems, 0 );
    if(  wxGetApp().getFrame()->GetToolBar() != NULL )
      wxGetApp().getFrame()->GetToolBar()->EnableTool(ME_Undo, ListOp.size( m_UndoItems ) > 0 );
    return item;
  }
  else
    return NULL;
}


static void reconThread( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  RocGui* o = (RocGui*)ThreadOp.getParm( th );

  TraceOp.trc( "reconthread", TRCLEVEL_INFO, __LINE__, 9999, "reconThread started" );
  ThreadOp.sleep(1000);
  o->setModel(NULL);
  o->setStayOffline(false);
  bool connected = false;
  do {
    connected = o->getFrame()->Connect(o->m_Host, o->m_Port, false, false);
    if(!connected)
      ThreadOp.sleep(1000);
  } while(!connected);
  TraceOp.trc( "conthread", TRCLEVEL_INFO, __LINE__, 9999, "conThread ended" );

}


static void conThread( void* threadinst ) {
  iOThread th = (iOThread)threadinst;
  RocGui* o = (RocGui*)ThreadOp.getParm( th );

  TraceOp.trc( "conthread", TRCLEVEL_INFO, __LINE__, 9999, "conThread started" );
  ThreadOp.sleep(100);

  char* val = StrOp.fmt( "connecting %s:%d...", o->m_Host, o->m_Port );
  wxCommandEvent* evt = new wxCommandEvent( wxEVT_COMMAND_MENU_SELECTED, ME_SetStatusText );
  evt->SetString(wxString(val,wxConvUTF8));
  evt->SetExtraLong(status_rcon);
  wxPostEvent( o->m_Frame, *evt );
  StrOp.free(val);
  ThreadOp.sleep(10);

  // connect to the rocrail daemon:
  int tries = 0;
  int retry = wRRCon.getretry( wGui.getrrcon( o->m_Ini ) );
  int sleep = wRRCon.getretryinterval( wGui.getrrcon( o->m_Ini ) );
  int retryinterval = wRRCon.getretryinterval( wGui.getrrcon( o->m_Ini ) );

  do {
    TraceOp.trc( "conthread", TRCLEVEL_INFO, __LINE__, 9999,
      "Try[%d] connecting to rocrail at %s:%d...",tries+1, o->m_Host, o->m_Port );
    TraceOp.trc( "conthread", TRCLEVEL_INFO, __LINE__, 9999, "1");
    o->m_RCon = RConOp.inst( o->m_Host, o->m_Port );
    tries++;

    TraceOp.trc( "conthread", TRCLEVEL_INFO, __LINE__, 9999, "2");

    if( o->m_RCon == NULL && tries < retry )
      ThreadOp.sleep( retryinterval );
    else if( o->m_RCon != NULL ) {
      TraceOp.trc( "conthread", TRCLEVEL_INFO, __LINE__, 9999, "3");
      RConOp.setCallback( o->m_RCon, &rocrailCallback, (obj)o );
      TraceOp.trc( "conthread", TRCLEVEL_INFO, __LINE__, 9999, "4");
    }

    if( o->m_RCon == NULL && tries < retry) {
      TraceOp.trc( "conthread", TRCLEVEL_INFO, __LINE__, 9999, "sleep %dms tries=%d retry=%d", sleep, tries, retry);
      ThreadOp.sleep(sleep);
    }

  } while( o->m_RCon == NULL && tries < retry );

  wRRCon.setretry( wGui.getrrcon(o->m_Ini), 1 );

  TraceOp.trc( "conthread", TRCLEVEL_INFO, __LINE__, 9999, "5");

  if( o->m_RCon != NULL ) {
    o->m_bOffline = false;
    val = StrOp.fmt( "%s:%d", o->m_Host, o->m_Port );
    wxCommandEvent* evt = new wxCommandEvent( wxEVT_COMMAND_MENU_SELECTED, ME_SetStatusText );
    evt->SetString(wxString(val,wxConvUTF8));
    evt->SetExtraLong(status_rcon);
    wxPostEvent( o->m_Frame, *evt );
    StrOp.free(val);


    o->m_Frame->setOnline(true);
    o->m_Frame->setOffline(false);
    o->m_bOffline = false;

    // Initial connection.
    iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
    wModelCmd.setcmd( cmd, wModelCmd.plan );
    wModelCmd.setcontrolcode( cmd, o->m_Frame->m_ControlCode );
    wModelCmd.setdisablemonitor(cmd, wGui.ismonitoring(o->m_Ini) ? False:True);
    char* guiid = StrOp.fmt( "%s,%d,%d", wGui.getid(o->m_Ini),
        SocketOp.getMAC(NULL)!=NULL?SocketOp.getMAC(NULL):0, SystemOp.getpid() );
    wModelCmd.setcmdfrom( cmd, guiid );
    o->sendToRocrail( cmd );
    StrOp.free(guiid);
    cmd->base.del( cmd );
  }
  else {
    wxCommandEvent* evt = new wxCommandEvent( wxEVT_COMMAND_MENU_SELECTED, ME_SetStatusText );
    evt->SetString(_T("Offline"));
    evt->SetExtraLong(status_rcon);
    wxPostEvent( o->m_Frame, *evt );
    o->m_Frame->setOnline(false);
    o->m_Frame->setOffline(true);
    o->m_bOffline = true;
  }


  if( o->m_bOffline ) {
    wxCommandEvent* evt = new wxCommandEvent( wxEVT_COMMAND_MENU_SELECTED, ME_OpenWorkspace );
    evt->SetExtraLong(4711);
    wxPostEvent( o->m_Frame, *evt );
  }

  TraceOp.trc( "conthread", TRCLEVEL_INFO, __LINE__, 9999, "conThread ended" );
}

static void __signalHandler( int sig ) {
  const char* sigName = "";

  switch( sig ) {
  case SIGSEGV:
    sigName = "Segment violation.";
    break;
  case SIGTERM:
    sigName = "Software termination signal from kill.";
    break;
#ifdef SIGKILL
  case SIGKILL:
    sigName = "Software termination.";
    break;
#endif
  case SIGINT:
    sigName = "Interrupt.";
    break;
  case SIGABRT:
    sigName = "Abnormal termination triggered by abort call.";
    break;
  case SIGFPE:
    sigName = "Floating point exception.";
    break;
  case SIGILL:
    sigName = "Illegal instruction - invalid function image.";
    break;
#ifdef SIGPIPE
  case SIGPIPE:
    sigName = "Broken pipe.";
    return;
#endif
  }

  printf( "__signalHandler: %d %s\n", sig, sigName );

  printf( "__signalHandler: shutdown...\n" );
  /* Reactivate default handling. */
  printf( "__signalHandler: Reactivate default handling...\n" );
  signal( sig, SIG_DFL );
  printf( "__signalHandler: Raise signal...\n" );
  raise( sig );

  printf( "__signalHandler: exit...\n" );
}




bool RocGui::OnInit() {
  wxLog::EnableLogging(false);
  /* Initialize the signal handler. */
  /* Not all OS's support this signal. */
#ifdef SIGBREAK
  signal( SIGBREAK, &__signalHandler );   /* Ctrl-Break sequence */
#endif
  signal( SIGTERM , &__signalHandler );   /* Software termination signal from kill */
  signal( SIGINT  , &__signalHandler );   /* interrupt */
  signal( SIGABRT , &__signalHandler );   /* abnormal termination triggered by abort call */
  signal( SIGFPE  , &__signalHandler );   /* floating point exception */
  signal( SIGILL  , &__signalHandler );   /* illegal instruction - invalid function image */
  signal( SIGSEGV , &__signalHandler );   /* segment violation */
#ifdef SIGKILL
  signal( SIGKILL , &__signalHandler );   /* kill */
#endif
#ifdef SIGPIPE
  signal (SIGPIPE, &__signalHandler);
#endif

  #ifdef __linux__
  {
    struct rlimit rl;
    getrlimit( RLIMIT_CORE, &rl );
    rl.rlim_cur = 1024 * 1024 * 100;
    setrlimit( RLIMIT_CORE, &rl );
  }
#endif
  m_bInit = false;
  m_bOnExit = false;
  m_bOffline = false;
  m_bStayOffline = false;
  m_LocalModelModified = false;
  m_LocalPlan = _T("");
  m_Model = NULL;
  m_OldModel = NULL;
  m_UndoItems = ListOp.inst();
  m_InitialRocrailIni = false;
  m_FireBiDiB4RocrailIni = false;
  m_FireRocNet4RocrailIni = false;
  m_Script = ScriptOp.inst(NULL);
  m_SensorEvents = ListOp.inst();
  m_SensorEventListener = NULL;

  // we could need some of these:
  wxInitAllImageHandlers();

  // Required for advanced HTML help
  wxFileSystem::AddHandler(new wxZipFSHandler);

  // convert command line arguments to UTF8 strings:
  char** argv_c = (char**)allocMem( argc * sizeof( char* ) );
  for( int cnt = 0; cnt < argc; cnt++ ) {
    argv_c[cnt] = StrOp.dup( (const char*)wxString(argv[cnt]).mb_str(wxConvUTF8) );
  }
  m_CmdLn = CmdLnOp.inst( argc, (const char**)argv_c );


  tracelevel  debug   = CmdLnOp.hasKey( m_CmdLn, wCmdline.debug ) ? TRCLEVEL_DEBUG:(tracelevel)0;
  tracelevel  parse   = CmdLnOp.hasKey( m_CmdLn, wCmdline.parse ) ? TRCLEVEL_PARSE:(tracelevel)0;
  tracelevel  info    = CmdLnOp.hasKey( m_CmdLn, wCmdline.info  ) ? TRCLEVEL_INFO:(tracelevel)0;
  const char* tf      = CmdLnOp.getStr( m_CmdLn, wCmdline.trcfile );
  const char* theme   = CmdLnOp.getStr( m_CmdLn, wCmdline.theme );
  const char* sp      = CmdLnOp.getStr( m_CmdLn, wCmdline.serverpath );
  const char* tp      = CmdLnOp.getStr( m_CmdLn, wCmdline.themespath );
  const char* lang    = CmdLnOp.getStr( m_CmdLn, wCmdline.langfile );
  m_bForceTabView     = CmdLnOp.hasKey(m_CmdLn, wCmdline.tabview);
  m_bTabViewRotated   = CmdLnOp.hasKey(m_CmdLn, wCmdline.tabviewrotated);
  Boolean fs          = CmdLnOp.hasKey(m_CmdLn, wCmdline.fullscreen);

  if( m_bTabViewRotated ) {
    m_bForceTabView = true;
  }

  // check for plan file:
  readArgs(lang);

  // create a trace object:
  m_Trace = TraceOp.inst( (tracelevel)(debug | info | TRCLEVEL_WARNING), NULL, True );
  TraceOp.setAppID( m_Trace, "g" );

  // check for alternative ini file:
  m_IniFileName = CmdLnOp.getStrDef( m_CmdLn, wCmdline.inifile, wGui.inifile );

  // check for tab selection:
  m_TabSel = CmdLnOp.getIntDef( m_CmdLn, wCmdline.tabsel, -1 );
  m_LocoTabSel = CmdLnOp.getIntDef( m_CmdLn, wCmdline.locotabsel, -1 );

  // process inifile:
  iOFile iniFile = FileOp.inst( m_IniFileName, True );
  if( iniFile == NULL ) {
    iniFile = FileOp.inst( wGui.previnifile, True );
    if( iniFile != NULL ) {
      FileOp.rename( wGui.previnifile, wGui.inifile );
    }
  }

  char* iniXml = NULL;
  if( iniFile != NULL ) {
    iniXml = (char*)allocMem( FileOp.size( iniFile ) + 1 );
    FileOp.read( iniFile, iniXml, FileOp.size( iniFile ) );
    FileOp.close( iniFile );
    if( StrOp.len( iniXml ) == 0 )
      iniXml = NULL;
  }

  m_Ini = NULL;
  if( iniXml != NULL ) {
    iODoc doc = DocOp.parse( iniXml );
    if( doc != NULL )
      m_Ini = DocOp.getRootNode( doc );
  }

  if( m_Ini == NULL )
    m_Ini = NodeOp.inst( wGui.name(), NULL, ELEMENT_NODE );



  iONode trace = wGui.gettrace( m_Ini );
  if( trace == NULL ) {
    trace = NodeOp.inst( wTrace.name(), m_Ini, ELEMENT_NODE );
    NodeOp.addChild( m_Ini, trace );
  }

  if( wTrace.isdebug( trace ) || debug )
    TraceOp.setLevel( m_Trace, (tracelevel)(TraceOp.getLevel( m_Trace ) | TRCLEVEL_DEBUG) );
  if( wTrace.isparse( trace ) || parse )
    TraceOp.setLevel( m_Trace, (tracelevel)(TraceOp.getLevel( m_Trace ) | TRCLEVEL_PARSE) );
  if( wTrace.isinfo( trace ) || info )
    TraceOp.setLevel( m_Trace, (tracelevel)(TraceOp.getLevel( m_Trace ) | TRCLEVEL_INFO) );

  char*    tracefilename = NULL;
  const char*   protpath = wTrace.getprotpath( trace );
  Boolean        unique  = wTrace.isunique( trace );
  const char*        tf2 = wTrace.getgfile( trace );
  int               size = wTrace.getsize( trace );
  int                 nr = wTrace.getnr( trace );
  Boolean  exceptionfile = wTrace.isexceptionfile( trace );
  const char*     invoke = wTrace.getinvoke( trace );
  Boolean    invokeasync = wTrace.isinvokeasync( trace );
  int           dumpsize = wTrace.getdumpsize( trace );

  TraceOp.setFileSize( m_Trace, size );
  TraceOp.setNrFiles( m_Trace, nr );
  TraceOp.setExceptionFile( m_Trace, exceptionfile );
  TraceOp.setInvoke( m_Trace, invoke, invokeasync );
  TraceOp.setDumpsize( m_Trace, dumpsize );

  if( tf == NULL )
    tf = tf2;
  else {
    char* p = FileOp.getPath( tf );
    TraceOp.trc( "app", TRCLEVEL_DEBUG, __LINE__, 9999, "ProtPath set to [%s]. (tf=\"%s\")", p, tf );
    wTrace.setprotpath( trace, p );
    StrOp.free( p );
    protpath = wTrace.getprotpath( trace );
    wTrace.setgfile( trace, FileOp.ripPath( tf ) );
  }

  /* Check protpath. */
  if( protpath != NULL ) {
    if( !FileOp.access( protpath ) ) {
      if( FileOp.mkdir( protpath ) )
        TraceOp.trc( "app", TRCLEVEL_DEBUG, __LINE__, 9999, "ProtPath [%s] created.", protpath );
      else {
        TraceOp.trc( "app", TRCLEVEL_WARNING, __LINE__, 1002,
            "Protocol path [%s] invalid.(Using current folder.", protpath );
        protpath = NULL;
      }
    }
    else
      TraceOp.trc( "app", TRCLEVEL_DEBUG, __LINE__, 9999, "ProtPath [%s] OK.", protpath );
  }

  if( protpath != NULL && !FileOp.isAbsolute( tf ) ) {
    char* stamp = StrOp.createStamp();

    if( !FileOp.isAbsolute( protpath ) ) {
      char* wd = FileOp.pwd();
      tracefilename = StrOp.fmt( "%s%c%s%c%s%s",
                                 wd,
                                 SystemOp.getFileSeparator(),
                                 protpath,
                                 SystemOp.getFileSeparator(),
                                 tf,
                                 unique ? stamp:"" );
      StrOp.free( wd );
    }
    else {
      tracefilename = StrOp.fmt( "%s%c%s%s",
                                 protpath,
                                 SystemOp.getFileSeparator(),
                                 tf,
                                 unique ? stamp:"" );
    }

    StrOp.free( stamp );
  }
  else {
    char* stamp = StrOp.createStamp();
    tracefilename = StrOp.fmt( "%s%s", tf, unique ? stamp:"" );
    StrOp.free( stamp );
  }

  TraceOp.setFilename( m_Trace, tracefilename );

  StrOp.free( tracefilename );





  initialize_images();

  // show the splash screen:
  wxSplashScreen* splash = NULL;
  splash = new wxSplashScreen(*_img_rocrail_logo,
        wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
        3000, NULL, -1, wxDefaultPosition, wxDefaultSize,
        wxSUNKEN_BORDER|wxSTAY_ON_TOP);


  // prepare the rocrail connection:
  m_Host = wRRCon.gethost( wGui.getrrcon( m_Ini ) );
  m_Host = CmdLnOp.getStrDef( m_CmdLn,wCmdline.host, m_Host );

  m_Port = wRRCon.getport( wGui.getrrcon( m_Ini ) );
  m_Port = CmdLnOp.getIntDef( m_CmdLn,wCmdline.port, m_Port );


  // create the language object:
  m_Res = ResOp.inst( messages, wGui.getlang( m_Ini ) );

  if( lang != NULL ) {
    // add extra translation file
    iOFile langFile = FileOp.inst( lang, True );
    if( langFile != NULL ) {
      TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999," merging alternative translations file: %s", lang );
      char* langXml = (char*)allocMem( FileOp.size( langFile ) + 1 );
      FileOp.read( langFile, langXml, FileOp.size( langFile ) );
      FileOp.close( langFile );
      ResOp.addTranslation( m_Res, langXml );
    }
  }



  {
    const char* xmls[2] = {wrapperinfo,guiwrapperinfo};
    m_WrpInf = WrpInfOp.inst( xmls, 2 );
  }

  m_RCon  = NULL;
  m_Model = NULL;

  /* Logo. */
  TraceOp.println( "----------------------------------------------------------" );
  TraceOp.println( "  fffff                                             lll   " );
  TraceOp.println( " fff fff                                        iii lll   " );
  TraceOp.println( " fff                                                lll   " );
  TraceOp.println( "ffffff  rrrrrr   eeeee   eeeee  rrrrrr   aaaaaa iii lll   " );
  TraceOp.println( " fff    rrr rrr ee  eee ee  eee rrr rrr aaa aaa iii lll   " );
  TraceOp.println( " fff    rrr     eeee    eeee    rrr     aaa aaa iii lll   " );
  TraceOp.println( " fff    rrr      eeeee   eeeee  rrr      aaaaaa iii  lll  " );
  TraceOp.println( "----------------------------------------------------------" );
  TraceOp.println( " Copyright 2002-2015 Rob Versluis.\n"                       );
  TraceOp.println( " This program is free software: you can redistribute it "   );
  TraceOp.println( " and/or modify it under the terms of the GNU General "      );
  TraceOp.println( " Public License as published by the Free Software "         );
  TraceOp.println( " Foundation, either version 3 of the License, or (at your " );
  TraceOp.println( " option) any later version."                                );
  TraceOp.println( "----------------------------------------------------------" );
  TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999," pwd = [%s]", FileOp.pwd() );
  for( int x = 0; x < argc; x++ )
    TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999," command line arg%d = [%s]", x, (const char**)argv_c[x] );


  // trace version
  TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999, " %s %d [%s]", wGui.productname, revisionnr, commithash );
  TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999, " build %s %s",
      wGui.buildDate,
      wGui.buildTime );

  if( revisionnr > 0 ) {
    m_RevisionNr = revisionnr;
    m_CommitHash = commithash;
    /*TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999," bzr %d", m_Svn );*/
  }
  else {
    iODoc doc = NULL;
    if( doc != NULL ) {
      iONode log = DocOp.getRootNode(doc);
      DocOp.base.del(doc);
      if( log != NULL ) {
        m_RevisionNr = wSvnLogEntry.getrevision( wSvnLog.getlogentry(log) );
        TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999," svn %d", m_RevisionNr );
        NodeOp.base.del(log);
      }
    }
  }


  // create the frame:
  TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999, "Creating Frame..." );

  int iX = wWindow.getx( wGui.getwindow( m_Ini ) );
  int iY = wWindow.gety( wGui.getwindow( m_Ini ) );
  int iWidth  = wWindow.getcx( wGui.getwindow( m_Ini ) );
  int iHeight = wWindow.getcy( wGui.getwindow( m_Ini ) );

  if( iX < 0 )
    iX = 0;
  if( iY < 0 )
    iY = 0;
  if( iWidth < 200 )
    iWidth = 400;
  if( iHeight < 100 )
    iHeight = 200;

  m_Frame = new RocGuiFrame( _T("Rocrail"), wxPoint(iX, iY),
      wxDefaultSize, m_Ini, theme, sp, tp );
  m_Frame->SetSize(wxSize(iWidth, iHeight));
  m_Frame->initFrame();

  TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999,"control code %s", wRRCon.getcontrolcode( wGui.getrrcon( m_Ini ) ) );
  m_Frame->m_ControlCode = wRRCon.getcontrolcode( wGui.getrrcon( m_Ini ) );

  m_bInit = true;

  if( CmdLnOp.hasKey( m_CmdLn, wCmdline.offline ) || m_LocalPlan.Len() > 0 ) {
    m_Frame->setLocalPlan( m_LocalPlan );
    m_Frame->SetStatusText( getMsg("offline"), status_rcon );
    m_bOffline = true;
  }


  m_Frame->setOffline(true);

  TraceOp.setExceptionListener( m_Trace, ExceptionCallback, False, False );

  m_Frame->Raise();


  if( !m_bOffline ) {
    iOThread th = ThreadOp.inst( "conthread", &conThread, this );
    ThreadOp.start( th );
  }

  if( fs ) {
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ME_FullScreen );
    event.SetInt(4711);
    wxPostEvent( m_Frame, event );
  }

  return TRUE;
}

void RocGui::Callback( obj me, iONode node ) {
  rocrailCallback( me, node );
}

static Boolean __hasIDinList(iONode list, const char* newid ) {
  if( list != NULL && newid != NULL ) {
    int cnt = NodeOp.getChildCnt( list );
    for( int i = 0; i < cnt; i++ ) {
      iONode item = NodeOp.getChild( list, i );
      const char* id = wItem.getid( item );

      if( newid != NULL && StrOp.equals( id, newid ) ) {
        return True;
      }
    }
  }
  return False;
}

static void rocrailCallback( obj me, iONode node ) {
  RocGui* guiApp = (RocGui*)me;

  if( (TraceOp.getLevel(NULL) & TRCLEVEL_DEBUG) == TRCLEVEL_DEBUG ) {
    if( !StrOp.equals( NodeOp.getName(node), wPlan.name()) ) {
      char* xmlStr = NodeOp.base.toString(node);
      TraceOp.trc( "app", TRCLEVEL_DEBUG, __LINE__, 9999, "rocrailCallback %.500s", xmlStr );
      StrOp.free(xmlStr);
    }
  }

  /* Plan */
  if( StrOp.equals( wPlan.name(), NodeOp.getName( node ) ) ) {
    TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999, "guiApp->setModel( %s )", NodeOp.getName( node ) );

    wxGetApp().getFrame()->setEditMode(false);

    if( guiApp->getFrame()->getNotebook() != NULL ) {
      if( !guiApp->isModelSet() || guiApp->isOffline() || (guiApp->getModel(false) != NULL && NodeOp.getChildCnt(guiApp->getModel(false)) == 0) ) {
        TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999,
            "isModelSet=%d stayOffline=%d", guiApp->isModelSet(), guiApp->isStayOffline() );
        guiApp->setModel( node );
        wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, INIT_NOTEBOOK );
        wxPostEvent( guiApp->getFrame(), event );
      }
      else {
        TraceOp.trc( "app", TRCLEVEL_WARNING, __LINE__, 9999,
            "***** already had the plan model: modelset=%d offline=%d", guiApp->isModelSet(), guiApp->isOffline() );
      }
    }
    else {
      TraceOp.trc( "app", TRCLEVEL_WARNING, __LINE__, 9999, "notebook not yet initialized" );
      guiApp->getFrame()->getPlanPanel()->clean();
      guiApp->getFrame()->getPlanPanel()->init();
    }

    ThreadOp.sleep(100); // give up some time slices to start the init plan process.
    if( !guiApp->isStayOffline() ) {
      // Get the rocrail setup.
      TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999,"get the rocrail.ini...");
      guiApp->m_InitialRocrailIni = true;
      iONode cmd = NodeOp.inst( wSysCmd.name(), NULL, ELEMENT_NODE );
      wSysCmd.setcmd( cmd, wSysCmd.getini );
      wxGetApp().sendToRocrail( cmd, false );
      cmd->base.del(cmd);
    }

    return;
  }

  /* Capture all feedback events for visualisation. */
  if( (!wxGetApp().getFrame()->isAutoMode() || wGui.issensormonitorauto(guiApp->getIni()) ) && StrOp.equals( wFeedback.name(), NodeOp.getName( node ) ) ) {
    bool FoundEvent = false;
    const char* fbiid = wFeedback.getiid(node);

    for( int i = 0; i < ListOp.size(guiApp->getSensorEvents()); i++ ) {
      iONode fbevent = (iONode)ListOp.get( guiApp->getSensorEvents(), i);
      if( wFeedback.getbus(node) == wFeedback.getbus(fbevent) && wFeedback.getaddr(node) == wFeedback.getaddr(fbevent) ) {
        if( fbiid != NULL && StrOp.len(fbiid) > 0 ) {
          if( !StrOp.equals(fbiid, wFeedback.getiid(fbevent) ) )
            continue;
        }
        TraceOp.trc( "app", TRCLEVEL_DEBUG, __LINE__, 9999, "update sensor event [%s] %d:%d", fbiid!=NULL?fbiid:"", wFeedback.getbus(node), wFeedback.getaddr(node) );
        wFeedback.setstate(fbevent, wFeedback.isstate(node));
        wFeedback.setidentifier(fbevent, wFeedback.getidentifier(node));
        wFeedback.setcounter(fbevent, wFeedback.getcounter(node));
        wFeedback.setwheelcount(fbevent, wFeedback.getwheelcount(node));
        wFeedback.setcountedcars(fbevent, wFeedback.getcountedcars(node));
        wFeedback.setload(fbevent, wFeedback.getload(node));
        char* stamp = StrOp.createStamp();
        NodeOp.setStr( fbevent, "stamp", stamp);
        StrOp.free(stamp);
        FoundEvent = true;
        guiApp->sensorEvent(fbevent);
        break;
      }
    }
    if( !FoundEvent ) {
      TraceOp.trc( "app", TRCLEVEL_DEBUG, __LINE__, 9999, "add sensor event [%s] %d:%d", fbiid!=NULL?fbiid:"", wFeedback.getbus(node), wFeedback.getaddr(node) );
      iONode fbevent = (iONode)NodeOp.base.clone(node);
      char* stamp = StrOp.createStamp();
      NodeOp.setStr( fbevent, "stamp", stamp);
      StrOp.free(stamp);
      ListOp.add( guiApp->getSensorEvents(), (obj)fbevent);
      guiApp->sensorEvent(fbevent);
    }
  }

  /* State */
  if( StrOp.equals( wState.name(), NodeOp.getName( node ) ) ) {
    wxGetApp().setConsoleMode( wState.isconsolemode( node )?true:false );
    TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999, "console mode is %s", wxGetApp().isConsoleMode()?"on":"off" );
    if(guiApp->isInit()) {
      wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, STATE_EVENT );
      // Make a copy of the node for using it out of this scope:
      event.SetClientData( node->base.clone( node ) );
      wxPostEvent( guiApp->getFrame(), event );
    }
    return;
  }
  /* Booster */
  else if( StrOp.equals( wBooster.name(), NodeOp.getName( node ) ) && guiApp->isInit() ) {
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, STATE_EVENT );
    // Make a copy of the node for using it out of this scope:
    event.SetClientData( node->base.clone( node ) );
    wxPostEvent( guiApp->getFrame(), event );
    return;
  }
  /* Auto */
  else if( StrOp.equals( wAutoCmd.name(), NodeOp.getName( node ) ) && guiApp->isInit() ) {
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, AUTO_EVENT );
    // Make a copy of the node for using it out of this scope:
    event.SetClientData( node->base.clone( node ) );
    wxPostEvent( guiApp->getFrame(), event );
    return;
  }


  /* do not process server messages before the plan panels are initialized */
  if( !wxGetApp().getFrame()->isInitialized() ) {
    return;
  }


  /* rocrail.ini */
  if( StrOp.equals( wFreeRail.name(), NodeOp.getName( node ) ) ) {
    if( guiApp->m_InitialRocrailIni ) {
      guiApp->getFrame()->setRocrailIni((iONode)node->base.clone( node ));
    }

    if(guiApp->m_FireBiDiB4RocrailIni) {
      wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ME_BiDiB );
      event.SetInt(4712);
      guiApp->m_FireBiDiB4RocrailIni = false;
      wxPostEvent( guiApp->getFrame(), event );
    }
    else if(guiApp->m_FireRocNet4RocrailIni) {
      wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ME_RocNet );
      event.SetInt(4711);
      guiApp->m_FireRocNet4RocrailIni = false;
      wxPostEvent( guiApp->getFrame(), event );
    }
    else if( !guiApp->m_InitialRocrailIni ) {
      wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ME_RocrailIni );
      // Make a copy of the node for using it out of this scope:
      event.SetClientData( node->base.clone( node ) );
      wxPostEvent( guiApp->getFrame(), event );
    }
    guiApp->m_InitialRocrailIni = false;

  }
  else if( StrOp.equals( wPwrEvent.name(), NodeOp.getName( node ) ) ) {
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ME_PowerEvent );
    // Make a copy of the node for using it out of this scope:
    event.SetClientData( node->base.clone( node ) );
    wxPostEvent( guiApp->getFrame(), event );
  }
  /* modplan */
  else if( StrOp.equals( wModPlan.name(), NodeOp.getName( node ) ) ) {
    if( guiApp->getFrame()->getModPanel() != NULL ) {
      wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ME_ModPlanProperties );
      // Make a copy of the node for using it out of this scope:
      event.SetClientData( node->base.clone( node ) );
      wxPostEvent( guiApp->getFrame()->getModPanel(), event );
    }
  }
  /* module */
  else if( StrOp.equals( wModule.name(), NodeOp.getName( node ) ) ) {
    if( guiApp->getFrame()->getModPanel() != NULL ) {
      wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ME_ModuleProperties );
      // Make a copy of the node for using it out of this scope:
      event.SetClientData( node->base.clone( node ) );
      wxPostEvent( guiApp->getFrame()->getModPanel(), event );
    }
  }
  /* Controller */
  else if( StrOp.equals( wDigInt.name(), NodeOp.getName( node ) ) ) {
    char* msg = StrOp.fmt( "%s:%s", wResponse.getsender( node ), wResponse.getmsg( node ) );
    // TODO: send an event to update a status field
    //wxGetApp().getFrame()->SetStatusText( wxString(msg,wxConvUTF8), status_digint );
    wxCommandEvent* evt = new wxCommandEvent( wxEVT_COMMAND_MENU_SELECTED, ME_SetStatusText );
    evt->SetString(wxString(msg,wxConvUTF8));
    evt->SetExtraLong(status_digint);
    wxPostEvent( wxGetApp().getFrame(), *evt );
    StrOp.free( msg );
  }
  /* Clock */
  else if( StrOp.equals( wClock.name(), NodeOp.getName( node ) ) && wxGetApp().getFrame() != NULL && guiApp->isInit()) {
    wxGetApp().getFrame()->SyncClock( node );
  }
  /* PT */
  else if( StrOp.equals( wProgram.name(), NodeOp.getName( node ) ) ) {
    char* msg = StrOp.fmt( "CV value=%d", wProgram.getvalue( node ) );
    StrOp.free( msg );
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, CV_EVENT );
    // Make a copy of the node for using it out of this scope:
    event.SetClientData( node->base.clone( node ) );
    wxPostEvent( guiApp->getFrame(), event );
  }
  /* Exception */
  else if( StrOp.equals( wException.name(), NodeOp.getName( node ) ) ) {
    TraceOp.trc( "app", TRCLEVEL_DEBUG, __LINE__, 9999, "rocrailCallback: got exception" );
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ADDEXCEPTION_EVENT );
    // Make a copy of the node for using it out of this scope:
    event.SetClientData( node->base.clone( node ) );
    wxPostEvent( guiApp->getFrame(), event );
  }
  /* Loc */
  else if( StrOp.equals( wLoc.name(), NodeOp.getName( node ) ) ||
           StrOp.equals( wFunCmd.name(), NodeOp.getName( node ) ) ) {
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, LOC_EVENT );
    // Make a copy of the node for using it out of this scope:
    event.SetClientData( node->base.clone( node ) );
    wxPostEvent( guiApp->getFrame(), event );
  }
  else if( StrOp.equals( wCar.name(), NodeOp.getName( node ) ) ) {
    iONode car = wxGetApp().getFrame()->findCar(wItem.getid(node));
    if( car != NULL ) {
      TraceOp.trc( "app", TRCLEVEL_DEBUG, __LINE__, 9999, "update car=%s", wItem.getid(car) );
      NodeOp.mergeNode( car, node, True, True, True ); // Update Car
      wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, CAR_EVENT );
      event.SetClientData( node->base.clone( node ) );
      wxPostEvent( guiApp->getFrame(), event );
    }
  }
  else if( StrOp.equals( wOperator.name(), NodeOp.getName( node ) ) ) {
    iONode opr = wxGetApp().getFrame()->findOperator(wItem.getid(node));
    if( opr != NULL ) {
      TraceOp.trc( "app", TRCLEVEL_DEBUG, __LINE__, 9999, "update operator=%s", wItem.getid(opr) );
      NodeOp.mergeNode( opr, node, True, True, True ); // Update Operator
    }
  }
  /* DataReq (loco image?) */
  else if( StrOp.equals( wDataReq.name(), NodeOp.getName( node ) ) ) {
    if( wDataReq.getcmd(node) == wDataReq.get ) {
      wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, UPDATE_ACTIVELOCS_EVENT );
      // Make a copy of the node for using it out of this scope:
      event.SetClientData( node->base.clone( node ) );
      wxPostEvent( guiApp->getFrame(), event );
    }
    else if( wDataReq.getcmd(node) == wDataReq.gettracedir || wDataReq.getcmd(node) == wDataReq.gettracefile ) {
      wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, SERVER_TRACE_EVENT );
      // Make a copy of the node for using it out of this scope:
      event.SetClientData( node->base.clone( node ) );
      wxPostEvent( guiApp->getFrame(), event );
    }
  }
  /* System on/off */
  else if( StrOp.equals( wSysCmd.name(), NodeOp.getName( node ) ) ) {
    if( StrOp.equals( wSysCmd.shutdown, wSysCmd.getcmd(node) ) ) {
      if( wGui.isreconnectafterservershutdown(guiApp->getIni()) && !guiApp->getFrame()->isPendingOpenWorkspace() ) {
        TraceOp.trc( "app", TRCLEVEL_WARNING , __LINE__, 9999, "SHUTDOWN -> reconnect after shutdown...");
        iOThread th = ThreadOp.inst( NULL, &reconThread, guiApp );
        ThreadOp.start( th );
        wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ME_GoOffline );
        wxPostEvent( guiApp->getFrame(), event );
      }
      else if( !guiApp->getFrame()->isPendingOpenWorkspace() ) {
        TraceOp.trc( "app", TRCLEVEL_EXCEPTION, __LINE__, 9999, "SHUTDOWN");
        wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, wxID_EXIT );
        wxPostEvent( guiApp->getFrame(), event );
      }
    }
    else {
      wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, SYSTEM_EVENT );
      // Make a copy of the node for using it out of this scope:
      event.SetClientData( node->base.clone( node ) );
      wxPostEvent( guiApp->getFrame(), event );
    }
  }
  /* ZLevel */
  else if( StrOp.equals( wZLevel.name(), NodeOp.getName( node ) ) ) {
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ZLEVEL_EVENT_ADD );
    // Make a copy of the node for using it out of this scope:
    event.SetClientData( node->base.clone( node ) );
    wxPostEvent( guiApp->getFrame(), event );
  }

  else if( StrOp.equals( wModelCmd.name(), NodeOp.getName( node ) ) &&
           StrOp.equals( wModelCmd.getcmd( node ), wModelCmd.themes ) ) {
    // TODO: Themes reload.
  }

  /* Model remove: */
  else if( StrOp.equals( wModelCmd.name(), NodeOp.getName( node ) ) &&
           StrOp.equals( wModelCmd.getcmd( node ), wModelCmd.remove ) ) {
    int childCnt = NodeOp.getChildCnt( node );
    Boolean hadZLevel = False;
    int i = 0;
    for( i = 0; i < childCnt; i++ ) {
      iONode child = NodeOp.getChild( node, i );
      if( StrOp.equals( wZLevel.name(), NodeOp.getName( child ) ) ) {
        wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ZLEVEL_EVENT_REMOVE );
        // Make a copy of the node for using it out of this scope:
        event.SetClientData( node->base.clone( child ) );
        wxPostEvent( guiApp->getFrame(), event );
        hadZLevel = True;
      }
      // lp:1027064 Deleted routes.
      else if( StrOp.equals( wRoute.name(), NodeOp.getName( child ) ) ) {
        iONode model = wxGetApp().getModel();
        iONode stlist = wPlan.getstlist(model);
        if( stlist != NULL ) {
          int stcnt = NodeOp.getChildCnt(stlist);
          for( int i = 0; i < stcnt; i++ ) {
            iONode st = NodeOp.getChild( stlist, i);
            if( StrOp.equals( wRoute.getid(st), wRoute.getid(child)) && !wRoute.isshow(st) ) {
              // If the route is visible it must be deleted from the plan panel.
              NodeOp.removeChild(stlist, st);
              break;
            }
          }
        }
      }
    }
    if( !hadZLevel ) {
      int pagecnt = guiApp->getFrame()->getNotebook()->GetPageCount();
      for( int i = 0; i < pagecnt; i++ ) {
        PlanPanel* p = (PlanPanel*)guiApp->getFrame()->getNotebook()->GetPage(i);
        wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, UPDATEITEM_EVENT );
        if( StrOp.equals(wBlock.name(), NodeOp.getName(node)))
          wBlock.setdesc(node, "guiapp");
        event.SetClientData( node->base.clone( node ) );
        wxPostEvent( p, event );

        //p->modelEvent( node );
      }
    }
  }
  /* default */
  else if(wxGetApp().getFrame() != NULL && guiApp->isInit() && guiApp->isModelSet() ){
    const char* nodeName = NodeOp.getName( node );
    TraceOp.trc( "app", TRCLEVEL_DEBUG, __LINE__, 9999, "rocrailCallback node=%s", nodeName );

    iONode model = wxGetApp().getModel();
    bool planItems = true;
    int childCnt = NodeOp.getChildCnt( node );
    int i = 0;
    for( i = 0; i < childCnt && model != NULL; i++ ) {
      iONode child = NodeOp.getChild( node, i );
      const char* childName = NodeOp.getName( child );

      if( StrOp.equals( childName, wLoc.name() ) ) {
        iONode lclist = wPlan.getlclist( model );
        if( lclist == NULL ) {
          lclist = NodeOp.inst( wLocList.name(), model, ELEMENT_NODE );
          NodeOp.addChild( model, lclist );
        }
        if( lclist != NULL ) {
          /* check if a loco already exist with this ID */
          iONode lc = wxGetApp().getFrame()->findLoc(wLoc.getid(child));
          wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ME_INITACTIVELOCS );
          if(lc == NULL ) {
            NodeOp.addChild( lclist, (iONode)NodeOp.base.clone(child) );
          }
          else {
            /* update existing */
            event.SetClientData( NodeOp.base.clone( lc ) );
          }
          wxPostEvent( wxGetApp().getFrame(), event );

        }
        planItems = false;
      }
      else if( StrOp.equals( childName, wCar.name() ) ) {
        iONode carlist = wPlan.getcarlist( model );
        if( carlist == NULL ) {
          carlist = NodeOp.inst( wCarList.name(), model, ELEMENT_NODE );
          NodeOp.addChild(model, carlist );
        }
        if( !__hasIDinList(carlist, wItem.getid(child)) )
          NodeOp.addChild( carlist, (iONode)NodeOp.base.clone(child) );
        planItems = false;
      }
      else if( StrOp.equals( childName, wOperator.name() ) ) {
        iONode oplist = wPlan.getoperatorlist( model );
        if( oplist == NULL ) {
          oplist = NodeOp.inst( wOperatorList.name(), model, ELEMENT_NODE );
          NodeOp.addChild(model, oplist );
        }
        if( !__hasIDinList(oplist, wItem.getid(child)) )
          NodeOp.addChild( oplist, (iONode)NodeOp.base.clone(child) );
        planItems = false;
      }
      else if( StrOp.equals( childName, wRoute.name() ) ) {
        iONode stlist = wPlan.getstlist( model );
        if( stlist == NULL ) {
          stlist = NodeOp.inst( wRouteList.name(), model, ELEMENT_NODE );
          NodeOp.addChild(model, stlist );
        }
        if( !__hasIDinList(stlist, wItem.getid(child)) )
          NodeOp.addChild( stlist, (iONode)NodeOp.base.clone(child) );
      }
      else if( StrOp.equals( childName, wSchedule.name() ) ) {
        iONode sclist = wPlan.getsclist( model );
        if( sclist == NULL ) {
          sclist = NodeOp.inst( wScheduleList.name(), model, ELEMENT_NODE );
          NodeOp.addChild(model, sclist );
        }
        if( !__hasIDinList(sclist, wItem.getid(child))  )
          NodeOp.addChild( sclist, (iONode)NodeOp.base.clone(child) );
        planItems = false;
      }
      else if( StrOp.equals( childName, wTour.name() ) ) {
        iONode tourlist = wPlan.gettourlist( model );
        if( tourlist == NULL ) {
          tourlist = NodeOp.inst( wTourList.name(), model, ELEMENT_NODE );
          NodeOp.addChild(model, tourlist );
        }
        if( !__hasIDinList(tourlist, wItem.getid(child))  )
          NodeOp.addChild( tourlist, (iONode)NodeOp.base.clone(child) );
        planItems = false;
      }
      else if( StrOp.equals( childName, wLocation.name() ) ) {
        iONode locationlist = wPlan.getlocationlist( model );
        if( locationlist == NULL ) {
          locationlist = NodeOp.inst( wLocationList.name(), model, ELEMENT_NODE );
          NodeOp.addChild(model, locationlist );
        }
        if( !__hasIDinList(locationlist, wItem.getid(child))  )
          NodeOp.addChild( locationlist, (iONode)NodeOp.base.clone(child) );
        planItems = false;
      }
      else if( StrOp.equals( childName, wLinkList.name() ) ) {
        iONode linklist = wPlan.getlinklist( model );
        if( linklist == NULL ) {
          linklist = NodeOp.inst( wLinkList.name(), model, ELEMENT_NODE );
          NodeOp.addChild(model, linklist );
        }
        if( !__hasIDinList(linklist, wItem.getid(child))  )
          NodeOp.addChild( linklist, (iONode)NodeOp.base.clone(child) );
        planItems = false;
      }
      /* ZLevel */
      else if( StrOp.equals( childName, wZLevel.name() ) ) {
        wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ZLEVEL_EVENT_ADD );
        // Make a copy of the node for using it out of this scope:
        event.SetClientData( node->base.clone( child ) );
        wxPostEvent( guiApp->getFrame(), event );
        planItems = false;
      }
    }

    if(planItems) {
      if( StrOp.equals( wModelCmd.name(), NodeOp.getName( node ) ) &&
          StrOp.equals( wModelCmd.getcmd( node ), wModelCmd.merge ) )
      {
        for( i = 0; i < childCnt && model != NULL; i++ ) {
          iONode child = NodeOp.getChild( node, i );
          const char* childName = NodeOp.getName( child );
          iONode list = NULL;
          char* listname = StrOp.fmt( "%slist", childName );

          list = NodeOp.findNode( model, listname );

          if( list != NULL ) {
            NodeOp.addChild( list, (iONode)NodeOp.base.clone(child) );
          }

          StrOp.free(listname);
        }

      }
      else if( guiApp->isInit() ) {
        if( StrOp.equals( wDec.name(), NodeOp.getName(node) ) ) {
          /* ToDo: Change it for general use. (Tours, Schedules...) */
          TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999, "Decoder %s", wDec.getid(node) );
          iONode db = NodeOp.findNode( guiApp->getModel(), wDecList.name() );
          if( db != NULL ) {
            int cnt = NodeOp.getChildCnt( db );
            for( int i = 0; i < cnt; i++ ) {
              iONode child = NodeOp.getChild( db, i );
              if( StrOp.equals( wDec.getid(node), wItem.getid(child) ) ) {
                NodeOp.setBool(child, "replacechilds", True);
                NodeOp.mergeNode(child, node, True, True, True);
                NodeOp.setBool(child, "replacechilds", False);
                break;
              }
            }
          }
        }
        else if( StrOp.equals( wVariable.name(), NodeOp.getName(node) ) ) {
          TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999, "Variable %s", wDec.getid(node) );
          iONode db = NodeOp.findNode( guiApp->getModel(), wVariableList.name() );
          if( db != NULL ) {
            Boolean found = False;
            int cnt = NodeOp.getChildCnt( db );
            for( int i = 0; i < cnt; i++ ) {
              iONode child = NodeOp.getChild( db, i );
              if( StrOp.equals( wVariable.getid(node), wItem.getid(child) ) ) {
                found = True;
                NodeOp.mergeNode(child, node, True, True, True);
                break;
              }
            }
            if( !found ) {
              NodeOp.addChild( db, (iONode)NodeOp.base.clone(node));
            }
          }
        }

        else if( StrOp.equals( wLocation.name(), NodeOp.getName(node) ) ) {
          TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999, "Location %s", wLocation.getid(node) );
          iONode db = NodeOp.findNode( guiApp->getModel(), wLocationList.name() );
          if( db != NULL ) {
            Boolean found = False;
            int cnt = NodeOp.getChildCnt( db );
            for( int i = 0; i < cnt; i++ ) {
              iONode child = NodeOp.getChild( db, i );
              if( StrOp.equals( wLocation.getid(node), wItem.getid(child) ) ) {
                found = True;
                NodeOp.mergeNode(child, node, True, True, True);
                break;
              }
            }
            if( !found ) {
              NodeOp.addChild( db, (iONode)NodeOp.base.clone(node));
            }
          }
        }

        else {
          int pagecnt = guiApp->getFrame()->getNotebook()->GetPageCount();
          const char* nodeName = NodeOp.getName(node);
          for( int i = 0; i < pagecnt; i++ ) {
            PlanPanel* p = (PlanPanel*)guiApp->getFrame()->getNotebook()->GetPage(i);
            // ToDo: Item Z must be set for this to function...
            /*
            if( StrOp.equals( wRoute.name(), nodeName ) )
              p->modelEvent( node );
            else if( StrOp.equals( wFeedback.name(), nodeName ) && !wFeedback.isshow(node) )
              p->modelEvent( node );
            else if( p->getZ() == wItem.getz(node))
            */
              p->modelEvent( node );
          }

          /* Update the loco grid? */
          if( StrOp.equals( wLoc.name(), NodeOp.getName(node) ) || StrOp.equals( wFunCmd.name(), NodeOp.getName(node) ) ||
              StrOp.equals( wBlock.name(), NodeOp.getName(node) ) )
          {
            TraceOp.trc( "app", TRCLEVEL_DEBUG, __LINE__, 9999, "UPDATE_ACTIVELOCS_EVENT for [%s]", NodeOp.getName(node) );
            wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, UPDATE_ACTIVELOCS_EVENT );
            event.SetClientData( node->base.clone( node ) );
            wxPostEvent( guiApp->getFrame(), event );
          }
        }
      }
    }
  }
}


void RocGui::sensorEvent(iONode event) {
  // Inform listener.
  if( m_SensorEventListener != NULL )
    m_SensorEventListener->Validate();
}


void RocGui::setModel( iONode node ) {
  if( m_Model != NULL && !isOffline() ) {
    // Delete the old model node:
    m_Model->base.del( m_Model );
  }
  else if( m_Model != NULL && isOffline() ) {
    m_OldModel = m_Model;
  }
  m_Model = NULL;
  // Save a copy of the node:
  if( node != NULL )
    m_Model = (iONode)node->base.clone( node );
}

const char* RocGui::findID( bool output, int addr, int bus, int porttype, const char** type ) {
  // TODO: Lookup ID in model.
  if( m_Model != NULL ) {
    if( output ) {
      iONode swlist = wPlan.getswlist( m_Model );
      if( swlist != NULL ) {
        int cnt = NodeOp.getChildCnt( swlist );
        if( type != NULL ) *type="switch";
        for( int i = 0; i < cnt; i++ ) {
          iONode sw = NodeOp.getChild( swlist, i );
          if( addr == wSwitch.getport1( sw ) || addr == wSwitch.getaddr1( sw ) ) {
            if( wSwitch.getporttype(sw) == porttype && wSwitch.getbus(sw) == bus )
              return wSwitch.getid( sw );
          }
          if( addr == wSwitch.getport2( sw ) || addr == wSwitch.getaddr2( sw ) ) {
            if( wSwitch.getporttype(sw) == porttype && wSwitch.getbus(sw) == bus  )
              return wSwitch.getid( sw );
          }
        }
      }
      iONode sglist = wPlan.getsglist( m_Model );
      if( sglist != NULL ) {
        int cnt = NodeOp.getChildCnt( sglist );
        if( type != NULL ) *type="signal";
        for( int i = 0; i < cnt; i++ ) {
          iONode sg = NodeOp.getChild( sglist, i );
          if( addr == wSignal.getport1( sg ) || addr == wSignal.getaddr( sg ) ) {
            if( wSignal.getporttype(sg) == porttype && wSignal.getbus(sg) == bus  )
              return wSignal.getid( sg );
          }
          if( addr == wSignal.getport2( sg ) || addr == wSignal.getaddr2( sg ) ) {
            if( wSignal.getporttype(sg) == porttype && wSignal.getbus(sg) == bus )
              return wSignal.getid( sg );
          }
          if( addr == wSignal.getport3( sg ) || addr == wSignal.getaddr3( sg ) ) {
            if( wSignal.getporttype(sg) == porttype && wSignal.getbus(sg) == bus )
              return wSignal.getid( sg );
          }
          if( addr == wSignal.getport4( sg ) || addr == wSignal.getaddr4( sg ) ) {
            if( wSignal.getporttype(sg) == porttype && wSignal.getbus(sg) == bus )
              return wSignal.getid( sg );
          }
        }
      }

      iONode colist = wPlan.getcolist( m_Model );
      if( colist != NULL ) {
        int cnt = NodeOp.getChildCnt( colist );
        if( type != NULL ) *type="output";
        for( int i = 0; i < cnt; i++ ) {
          iONode co = NodeOp.getChild( colist, i );
          if( addr == wOutput.getport( co ) || addr == wOutput.getaddr( co ) ) {
            if( wOutput.getporttype(co) == porttype && wOutput.getbus(co) == bus )
              return wOutput.getid( co );
          }
        }
      }

      iONode ttlist = wPlan.getttlist( m_Model );
      if( ttlist != NULL ) {
        int cnt = NodeOp.getChildCnt( ttlist );
        if( type != NULL ) *type="turntable";
        for( int i = 0; i < cnt; i++ ) {
          iONode tt = NodeOp.getChild( ttlist, i );
          if( addr == wTurntable.getport0( tt ) ) {
            return wTurntable.getid( tt );
          }
          if( addr == wTurntable.getport1( tt ) ) {
            return wTurntable.getid( tt );
          }
          if( addr == wTurntable.getport2( tt ) ) {
            return wTurntable.getid( tt );
          }
          if( addr == wTurntable.getport3( tt ) ) {
            return wTurntable.getid( tt );
          }
          if( addr == wTurntable.getport4( tt ) ) {
            return wTurntable.getid( tt );
          }
          if( addr == wTurntable.getport5( tt ) ) {
            return wTurntable.getid( tt );
          }
          if( addr == wTurntable.getport6( tt ) ) {
            return wTurntable.getid( tt );
          }
        }
      }

      iONode seltablist = wPlan.getseltablist( m_Model );
      if( seltablist != NULL ) {
        int cnt = NodeOp.getChildCnt( seltablist );
        if( type != NULL ) *type="fiddleyard";
        for( int i = 0; i < cnt; i++ ) {
          iONode seltab = NodeOp.getChild( seltablist, i );
          if( addr == wSelTab.getport0( seltab ) ) {
            return wSelTab.getid( seltab );
          }
          if( addr == wSelTab.getport1( seltab ) ) {
            return wSelTab.getid( seltab );
          }
          if( addr == wSelTab.getport2( seltab ) ) {
            return wSelTab.getid( seltab );
          }
          if( addr == wSelTab.getport3( seltab ) ) {
            return wSelTab.getid( seltab );
          }
          if( addr == wSelTab.getport4( seltab ) ) {
            return wSelTab.getid( seltab );
          }
        }
      }


    }
    else {
      iONode fblist = wPlan.getfblist( m_Model );
      if( fblist != NULL ) {
        int cnt = NodeOp.getChildCnt( fblist );
        if( type != NULL ) *type="sensor";
        for( int i = 0; i < cnt; i++ ) {
          iONode fb = NodeOp.getChild( fblist, i );
          if( addr == wFeedback.getaddr( fb ) && wFeedback.getbus(fb) == bus ) {
            return wFeedback.getid( fb );
          }
        }
      }
    }
  }
  return "not used";
}

void RocGui::cleanupOldModel() {
  if( m_OldModel != NULL ) {
    // Delete the old model node:
    m_OldModel->base.del( m_OldModel );
    m_OldModel = NULL;
  }
}


void RocGui::sendToRocrail( iONode cmd, bool disconnect ) {
  char* strCmd = NodeOp.base.toString( cmd );
  sendToRocrail( strCmd, false, disconnect, false );
  StrOp.free( strCmd );

  if( m_RCon != NULL ) {
    ScriptOp.setCallback(m_Script, (obj)m_RCon);
  }
  ScriptOp.recordNode(m_Script, cmd);

  if( m_bOffline ) {
    if( StrOp.equals( wProgram.name(), NodeOp.getName( cmd ) ) ) {
      return;
    }
    TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999,
        "Bounce to add to local model: %s:%s", NodeOp.getName( cmd ), wModelCmd.getcmd( cmd ) );

    // Bounce to add to local model...
    if( StrOp.equals( wModelCmd.name(), NodeOp.getName( cmd ) ) ) {
      if( StrOp.equals( wModelCmd.modify, wModelCmd.getcmd( cmd ) ) )
        wxGetApp().setLocalModelModified(true);
      else if( StrOp.equals( wModelCmd.remove, wModelCmd.getcmd( cmd ) ) )
        wxGetApp().setLocalModelModified(true);
      else if( StrOp.equals( wModelCmd.add, wModelCmd.getcmd( cmd ) ) )
        wxGetApp().setLocalModelModified(true);
      else if( StrOp.equals( wModelCmd.plantitle, wModelCmd.getcmd( cmd ) ) )
        wxGetApp().setLocalModelModified(true);
    }
    Callback( (obj)&wxGetApp(), cmd );
  }
}

bool RocGui::sendToRocrail( char* szCmd, bool wait4rr, bool disconnect, bool showpopup ) {
  if( m_bStayOffline )
    return true;

  if( szCmd == NULL && m_RCon != NULL ) {
    // force disconnect:
    TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999,
        "sendToRocrail: force disconnect... szCmd=0x%08X wait4rr=%d", szCmd, wait4rr );
    RConOp.close( m_RCon );
    RConOp.base.del( m_RCon );
    m_RCon = NULL;
  }


  if( m_RCon == NULL ) {
    int waitloops = wait4rr?300:1;
    TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999, "connecting... waitloops=%d", waitloops);

    if( m_Frame != NULL ) {
      //wxCursor cursor = wxCursor(wxCURSOR_WAIT);
      //m_Frame->SetCursor( cursor );
    }

    while( m_RCon == NULL && waitloops > 0 ) {
      m_RCon = RConOp.inst( m_Host, m_Port );
      waitloops--;
      if( waitloops > 0 )
        ThreadOp.sleep(100);
    }

    if( m_Frame != NULL ) {
      //wxCursor cursor = wxCursor(wxCURSOR_ARROW);
      //m_Frame->SetCursor( cursor );
    }

    if( m_RCon != NULL ) {
      m_bOffline = false;
      RConOp.setCallback( m_RCon, &rocrailCallback, (obj)this );
      if( m_Frame != NULL ) {
        char* val = StrOp.fmt( "%s:%d", m_Host, m_Port );
        wxCommandEvent* evt = new wxCommandEvent( wxEVT_COMMAND_MENU_SELECTED, ME_SetStatusText );
        evt->SetString(wxString(val,wxConvUTF8));
        evt->SetExtraLong(status_rcon);
        wxPostEvent( m_Frame, *evt );
        StrOp.free(val);
      }
    }
    else {
      // show popup with message
      if( showpopup && m_Frame != NULL ) {
        char* val = StrOp.fmt( " (%s:%d)", m_Host, m_Port );
        wxMessageDialog( m_Frame,
            wxGetApp().getMsg("connectionwarning") +
            wxString(val,wxConvUTF8),
            _T("Rocrail"), wxOK | wxICON_EXCLAMATION ).ShowModal();
        StrOp.free(val);
        if( wait4rr ) {
          m_Frame->resetActiveWorkspace();
        }

      }
      return false;
    }
  }
  if( szCmd != NULL ) {
    TraceOp.trc( "app", TRCLEVEL_DEBUG, __LINE__, 9999, "sendToRocrail( %.1024s )", szCmd );
    if( m_RCon != NULL ) {
      RConOp.write( m_RCon, szCmd );
      if( disconnect ) {
        ThreadOp.sleep(100); // sleep some ms to make sure the last command is send
        RConOp.close( m_RCon );
      }
    }
  }

  return true;

}

#ifdef __APPLE__
void RocGui::MacOpenFile( const wxString& fileName) {
  TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999, "local file OSX: %s", (const char*)wxString(fileName).mb_str(wxConvUTF8) );
  m_LocalPlan = fileName;
  m_bStayOffline = true;
  m_Frame->setLocalPlan( m_LocalPlan );
  m_Frame->SetStatusText( getMsg("offline"), status_rcon );
  m_bOffline = true;
}
#endif


