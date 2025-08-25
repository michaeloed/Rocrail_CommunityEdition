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
#pragma implementation "rocguiinidlg.h"
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

#include "rocguiinidlg.h"

////@begin XPM images
////@end XPM images

#include "rocview/wrapper/public/Gui.h"
#include "rocview/wrapper/public/RRCon.h"
#include "rocview/wrapper/public/SplitPanel.h"
#include "rocview/wrapper/public/PlanPanel.h"
#include "rocview/wrapper/public/ModPanel.h"
#include "rocview/wrapper/public/MIC.h"
#include "rocview/wrapper/public/CVconf.h"
#include "rocview/wrapper/public/Accelerator.h"

#include "rocrail/wrapper/public/JsMap.h"
#include "rocrail/wrapper/public/Trace.h"

#include "rocview/public/guiapp.h"

/*!
 * RocguiIniDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( RocguiIniDialog, wxDialog )

/*!
 * RocguiIniDialog event table definition
 */

BEGIN_EVENT_TABLE( RocguiIniDialog, wxDialog )

////@begin RocguiIniDialog event table entries
    EVT_BUTTON( ID_WORKSPACE, RocguiIniDialog::OnWorkspaceClick )
    EVT_BUTTON( ID_IMAGEPATH_BUTTON, RocguiIniDialog::OnImagepathButtonClick )
    EVT_BUTTON( ID_UPDATESPATH_BUTTON, RocguiIniDialog::OnUpdatespathButtonClick )
    EVT_BUTTON( ID_XSLPATH_BUTTON, RocguiIniDialog::OnXslpathButtonClick )
    EVT_BUTTON( ID_DECPATH_BUTTON, RocguiIniDialog::OnDecpathButtonClick )
    EVT_BUTTON( ID_SVGPATH_BUTTON, RocguiIniDialog::OnSvgPath1Click )
    EVT_BUTTON( ID_SVGPATH2_BUTTON, RocguiIniDialog::OnSvgPath2Click )
    EVT_BUTTON( ID_SVGPATH3_BUTTON, RocguiIniDialog::OnSvgPath3Click )
    EVT_BUTTON( ID_SVGPATH4_BUTTON, RocguiIniDialog::OnSvgPath4Click )
    EVT_BUTTON( ID_SVGPATH5_BUTTON, RocguiIniDialog::OnSvgPath5Click )
    EVT_BUTTON( wxID_OK, RocguiIniDialog::OnOKClick )
    EVT_BUTTON( wxID_CANCEL, RocguiIniDialog::OnCANCELClick )
    EVT_BUTTON( wxID_HELP, RocguiIniDialog::OnHelpClick )
////@end RocguiIniDialog event table entries

END_EVENT_TABLE()

/*!
 * RocguiIniDialog constructors
 */

RocguiIniDialog::RocguiIniDialog( )
{
}

RocguiIniDialog::RocguiIniDialog( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, caption, pos, size, style);
}

RocguiIniDialog::RocguiIniDialog( wxWindow* parent, iONode ini )
{
  m_TabAlign = wxGetApp().getTabAlign();
  Create(parent, -1, _("Rocview"));
  initLabels();
  m_Ini = ini;

  m_GeneralTab->GetSizer()->Layout();
  m_TracePanel->GetSizer()->Layout();
  m_MICpanel->GetSizer()->Layout();
  m_PTpanel->GetSizer()->Layout();
  m_SVGpanel->GetSizer()->Layout();
  m_RICpanel->GetSizer()->Layout();

  m_Notebook->Fit();
  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);

  initValues();
}


void RocguiIniDialog::initLabels() {
  m_Notebook->SetPageText( 0, wxGetApp().getMsg( "general" ) );
  m_Notebook->SetPageText( 1, wxGetApp().getMsg( "trace" ) );
  m_Notebook->SetPageText( 2, wxGetApp().getMsg( "programming" ) );
  m_Notebook->SetPageText( 3, _T( "SVG" ) );
  m_Notebook->SetPageText( 4, wxGetApp().getMsg( "gamepad" ) );
  m_Notebook->SetPageText( 5, wxGetApp().getMsg( "mic" ) );
  m_Notebook->SetPageText( 6, wxGetApp().getMsg( "accelerators" ) );

    // Trace:
  m_TraceLevel->GetStaticBox()->SetLabel( wxGetApp().getMsg( "tracelevel" ) );
  m_Debug->SetLabel( wxGetApp().getMsg( "debug" ) );
  m_Info->SetLabel( wxGetApp().getMsg( "info" ) );
  m_HelpBox->SetLabel( wxGetApp().getMsg( "help" ) );
  m_labProtPath->SetLabel( wxGetApp().getMsg( "path" ) );
  m_labTraceFile->SetLabel( wxGetApp().getMsg( "tracefile" ) );

  m_RestrictEdit4Auto->SetLabel( wxGetApp().getMsg( "restrictedit4auto" ) );
  m_JsSupport->SetLabel( wxGetApp().getMsg( "gamepad" ) + _T(" support") );
  m_DispatchMode->SetLabel( wxGetApp().getMsg( "dispatchmode" ) );
  //m_Check4Updates->SetLabel( wxGetApp().getMsg( "softwareupdates" ) );

  m_labDecPath->SetLabel( wxGetApp().getMsg( "decpath" ) );
  m_JsSupport->SetLabel( wxGetApp().getMsg( "gamepadsupport" ) );

  // MIC:
  m_labMICStep->SetLabel( wxGetApp().getMsg( "speedsteps" ) );
  m_MICStopOnExit->SetLabel( wxGetApp().getMsg( "stoponexit" ) );

  // PT:
  m_labCVnrs->SetLabel( _("CV") );
  m_labTimeout->SetLabel( _("timeout") );
  m_UseDecSpec4All->SetLabel( wxGetApp().getMsg( "usedecspec4all" ) );

  // SVG:
  m_labTheme1->SetLabel( wxGetApp().getMsg( "theme" ) + _T(" 1") );
  m_labTheme2->SetLabel( wxGetApp().getMsg( "theme" ) + _T(" 2") );
  m_labTheme3->SetLabel( wxGetApp().getMsg( "theme" ) + _T(" 3") );
  m_labTheme4->SetLabel( wxGetApp().getMsg( "theme" ) + _T(" 4") );
  m_labTheme5->SetLabel( wxGetApp().getMsg( "theme" ) + _T(" 5") );
  m_labItemIDpointsize->SetLabel( wxGetApp().getMsg( "itemidps" ) );
  m_labTextPS->SetLabel( wxGetApp().getMsg( "textps" ) );
  m_ProcessRouteEvents->SetLabel( wxGetApp().getMsg( "processrouteevents" ) );
  m_ProcessBlockEvents->SetLabel( wxGetApp().getMsg( "processblockevents" ) );

  // RIC:
  m_labVelocity->GetStaticBox()->SetLabel( wxGetApp().getMsg( "speed" ) );
  m_labRepeat->SetLabel( wxGetApp().getMsg( "repeat" ) );
  m_labDir->SetLabel( wxGetApp().getMsg( "dir" ) );
  m_labStop->SetLabel( wxGetApp().getMsg( "stop" ) );
  m_labRICStep->SetLabel( wxGetApp().getMsg( "speedsteps" ) );

  m_FunctionsBox->GetStaticBox()->SetLabel( wxGetApp().getMsg( "functions" ) );
  m_labLights->SetLabel( wxGetApp().getMsg( "lights" ) );

  m_PowerBox->GetStaticBox()->SetLabel( wxGetApp().getMsg( "power" ) );
  m_labPowerOn->SetLabel( wxGetApp().getMsg( "on" ) );
  m_labPowerOff->SetLabel( wxGetApp().getMsg( "off" ) );
  m_labMonitorSize->SetLabel( wxGetApp().getMsg( "monitorsize" ) );

  m_ClockType->SetLabel( wxGetApp().getMsg( "clocktype" ) );
  m_ClockType->SetString( 0, wxGetApp().getMsg( "default" ) );
  m_ClockType->SetString( 3, wxGetApp().getMsg( "digital" ) );
  m_ClockType->SetString( 4, wxGetApp().getMsg( "none" ) );
  m_labImagePath->SetLabel( wxGetApp().getMsg( "imagepath" ) );
  m_labUpdatesPath->SetLabel( wxGetApp().getMsg( "updatespath" ) );
  m_labXSLPath->SetLabel( wxGetApp().getMsg( "xslpath" ) );
  m_labDecPath->SetLabel( wxGetApp().getMsg( "decpath" ) );
  m_labPanelSize->SetLabel( wxGetApp().getMsg( "panel" ) + _T(" ") + wxGetApp().getMsg( "size" ) );
  m_labModPlanSize->SetLabel( wxGetApp().getMsg( "modpanel" ) + _T(" ") + wxGetApp().getMsg( "size" ) );
  m_labWorkspace->SetLabel( wxGetApp().getMsg( "defaultworkspace" ) );
  m_Workspace->SetToolTip( wxGetApp().getMsg( "defaultworkspace" ) );
  m_StartDefaultWorkspace->SetLabel( wxGetApp().getMsg( "startdefaultworkspace" ) );
  m_RestoreLcCtrl->SetLabel( wxGetApp().getMsg( "restore" ) + _T(" ") + wxGetApp().getMsg( "locctrl" ) );
  m_Monitoring->SetLabel( wxGetApp().getMsg( "monitoring" ) );
  m_ShowOnlyStartSchedules->SetLabel( wxGetApp().getMsg( "showonlystartschedules" ) );
  m_ShowBlockID->SetLabel( wxGetApp().getMsg( "blockid" ) );
  m_ShowSecondhand->SetLabel( wxGetApp().getMsg( "showsecondhand" ) );
  m_ReconnectAfterServerShutdown->SetLabel( wxGetApp().getMsg( "reconnectafterservershutdown" ) );
  m_ResetSpeedDir->SetLabel( wxGetApp().getMsg( "resetspeeddir" ) );
  m_UseAllSpeedSteps->SetLabel( wxGetApp().getMsg( "useallspeedsteps" ) );
  m_RenderGC->SetLabel( wxGetApp().getMsg( "rendergc" ) );
  m_labDirImage->SetLabel( wxGetApp().getMsg( "dirimage" ) );
  m_Toolbar->SetLabel( wxGetApp().getMsg( "toolbar" ) );
  m_VerticalToolbar->SetLabel( wxGetApp().getMsg( "verticaltoolbar" ) );
  m_LocoImage->SetLabel( wxGetApp().getMsg( "locoimage" ) );
  m_ShowLocoImageInBlock->SetLabel( wxGetApp().getMsg( "showlocoimageinblock" ) );
  m_ShowTrainIdInBlock->SetLabel( wxGetApp().getMsg( "showtrainidinblock" ) );
  m_ShowRoute4Switch->SetLabel( wxGetApp().getMsg( "showroute4switch" ) );
  m_MonitorDontWrap->SetLabel( wxGetApp().getMsg( "monitordontwrap" ) );
  m_ShowSpeedOMeter->SetLabel( wxGetApp().getMsg( "speedometer" ) );
  m_LocoImageColumn->SetLabel( wxGetApp().getMsg( "locoimagecolumn" ) );
  m_GrayIcons->SetLabel( wxGetApp().getMsg( "grayicons" ) );
  m_labWidgetWidth->SetLabel( wxGetApp().getMsg( "widgetwidth" ) );
  m_labGridFontSizeAdjust->SetLabel( wxGetApp().getMsg( "gridfontsizeadjust" ) );
  m_SensorMonitorAuto->SetLabel( wxGetApp().getMsg( "sensormonitorauto" ) );

  m_labSpeak4Block->SetLabel( wxGetApp().getMsg( "speak4block" ) );
  m_labSpeakCmd->SetLabel( wxGetApp().getMsg( "speakcmd" ) );

  m_TabAlignType->SetLabel( wxGetApp().getMsg( "tabalign" ) );
  m_TabAlignType->SetString( 0, wxGetApp().getMsg( "default" ) );
  m_TabAlignType->SetString( 1, wxGetApp().getMsg( "left" ) );
  m_TabAlignType->SetString( 2, wxGetApp().getMsg( "multiline" ) );

  // Accelerators
  m_labAccelFunction->SetLabel( wxGetApp().getMsg( "function" ) );
  m_labAccelKeyCode->SetLabel( wxGetApp().getMsg( "keycode" ) );
  m_labAccelModifier->SetLabel( wxGetApp().getMsg( "modifier" ) );
  m_labEmergencyBreak->SetLabel( wxGetApp().getMsg( "ebreak" ) );
  m_EmergencyBreakModifier->SetString( 0, wxGetApp().getMsg( "none" ) );
  m_EmergencyBreakModifier->SetString( 1, wxGetApp().getMsg( "alt" ) );
  m_EmergencyBreakModifier->SetString( 2, wxGetApp().getMsg( "ctrl" ) );
  m_EmergencyBreakList->Append( wxT("") );
  m_EmergencyBreakList->Append( wxT("Pause") );
  m_EmergencyBreakList->Append( wxT("Space") );
  m_EmergencyBreakList->SetSelection(0);

  // Buttons
  m_OK->SetLabel( wxGetApp().getMsg( "ok" ) );
  m_Cancel->SetLabel( wxGetApp().getMsg( "cancel" ) );
  m_Help->SetLabel( wxGetApp().getMsg( "help" ) );
}


void RocguiIniDialog::initValues() {
  if( m_Ini == NULL )
    return;

  // Trace
  iONode trace = wGui.gettrace( m_Ini );
  if( trace == NULL ) {
    trace = NodeOp.inst( wTrace.name(), m_Ini, ELEMENT_NODE );
    NodeOp.addChild( m_Ini, trace );
  }
  iONode planpanel = wGui.getplanpanel( m_Ini );
  if( planpanel == NULL ) {
    planpanel = NodeOp.inst( wPlanPanel.name(), m_Ini, ELEMENT_NODE );
    NodeOp.addChild( m_Ini, planpanel );
  }

  m_Debug->SetValue( wTrace.isdebug( trace ) ? true:false );
  m_Debug->Enable( wTrace.isdebug( trace ) ? true:false );

  m_Info->SetValue( wTrace.isinfo( trace ) ? true:false );
  m_TraceFile->SetValue( wxString(wTrace.getgfile( trace ),wxConvUTF8) );
  m_ProtPath->SetValue( wxString(wTrace.getprotpath( trace ),wxConvUTF8) );

  m_HelpURL->SetValue( wxString(wGui.gethelpurl( m_Ini ),wxConvUTF8) );

  m_RestrictEdit4Auto->SetValue( wGui.isrestrictedit4auto( m_Ini ) ? true:false );
  //m_Check4Updates->SetValue( wGui.ischeckupdates( m_Ini ) ? true:false );
  m_JsSupport->SetValue( wGui.isjssupport( m_Ini ) ? true:false );
  m_DispatchMode->SetValue( wGui.isdispatchmode( m_Ini ) ? true:false );
  m_StartDefaultWorkspace->SetValue( wGui.isstartdefaultworkspace( m_Ini ) ? true:false );
  m_FSUTF8->SetValue( wGui.isfsutf8( m_Ini ) ? true:false );
  m_RestoreLcCtrl->SetValue( wGui.isrestorelcctrl( m_Ini ) ? true:false );
  m_Monitoring->SetValue( wGui.ismonitoring( m_Ini ) ? true:false );
  m_ShowOnlyStartSchedules->SetValue( wGui.isshowonlystartschedules( m_Ini ) ? true:false );
  m_ShowBlockID->SetValue( wPlanPanel.isbktextid(planpanel) ? true:false );
  m_ShowSecondhand->SetValue( wGui.isshowsecondhand( m_Ini ) ? true:false );
  m_ReconnectAfterServerShutdown->SetValue( wGui.isreconnectafterservershutdown( m_Ini ) ? true:false );
  m_ResetSpeedDir->SetValue( wGui.isresetspeeddir( m_Ini ) ? true:false );
  m_UseAllSpeedSteps->SetValue( wGui.isuseallspeedsteps( m_Ini ) ? true:false );
  m_RenderGC->SetValue( wGui.isrendergc( m_Ini ) ? true:false );
  m_VerticalToolbar->SetValue( wGui.isverticaltoolbar( m_Ini ) ? true:false );
  m_Toolbar->SetValue( wGui.istoolbar( m_Ini ) ? true:false );
  m_LocoImage->SetValue( wGui.isshowlocoimage( m_Ini ) ? true:false );
  m_ShowLocoImageInBlock->SetValue( wGui.isshowlocoimageinblock( m_Ini ) ? true:false );
  m_ShowTrainIdInBlock->SetValue( wGui.isshowtrainidinblock( m_Ini ) ? true:false );
  m_ShowRoute4Switch->SetValue( wGui.isshowroute4switch( m_Ini ) ? true:false );
  m_GrayIcons->SetValue( wGui.isgrayicons( m_Ini ) ? true:false );
  m_SensorMonitorAuto->SetValue( wGui.issensormonitorauto( m_Ini ) ? true:false );

  if( wGui.getsplitpanel(m_Ini) == NULL ) {
    iONode node = NodeOp.inst( wSplitPanel.name(), m_Ini, ELEMENT_NODE );
    NodeOp.addChild( m_Ini, node );
  }
  m_MonitorDontWrap->SetValue( wSplitPanel.isdontwrap( wGui.getsplitpanel(m_Ini)) ? true:false );
  m_ShowSpeedOMeter->SetValue( wGui.isshowspeedometer(m_Ini) ? true:false );
  m_LocoImageColumn->SetValue( wGui.islocoimagecolumn(m_Ini) ? true:false );

  m_WidgetWidth->SetValue(wGui.getlocowidgetwidth( m_Ini ));
  m_GridFontSizeAdjust->SetValue(wGui.getgridfontsizeadjust( m_Ini ));
  m_MonitorSize->SetValue(wGui.getmonitorsize( m_Ini ));
  m_BoosterUID->SetValue(wxString::Format(wxT("%d"), wGui.getstatusboosteruid( m_Ini )));

  // MIC
  iONode mic = wGui.getmic( m_Ini );
  if( mic == NULL ) {
    mic = NodeOp.inst( wMIC.name(), m_Ini, ELEMENT_NODE );
    NodeOp.addChild( m_Ini, mic );
  }
  m_MICStep->SetValue( wMIC.getstep(mic) );
  m_MICStopOnExit->SetValue( wMIC.isexitstop(mic) ? true:false );


  // PT
  iONode cvconf = wGui.getcvconf( m_Ini );
  if( cvconf == NULL ) {
    cvconf = NodeOp.inst( wCVconf.name(), m_Ini, ELEMENT_NODE );
    NodeOp.addChild( m_Ini, cvconf );
  }
  m_CVnrs->SetValue( wxString(wCVconf.getnrs( cvconf ),wxConvUTF8) );
  char* val = StrOp.fmt( "%d", wCVconf.gettimeout(cvconf) );
  m_Timeout->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);
  m_Lissy->SetValue( wCVconf.islissy(cvconf) ? true:false );
  m_UseDecSpec4All->SetValue( wCVconf.isusedecspec4all(cvconf) ? true:false );
  m_SVtab->SetValue( wGui.islncvtab(m_Ini) ? true:false );


  // SVG
  m_CX->SetValue( wPlanPanel.getcx(planpanel) );
  m_CY->SetValue( wPlanPanel.getcy(planpanel) );

  m_ProcessRouteEvents->SetValue( wPlanPanel.isprocessrouteevents( planpanel ) ? true:false );
  m_ProcessBlockEvents->SetValue( wPlanPanel.isprocessblockevents( planpanel ) ? true:false );

  iONode modpanel = wGui.getmodpanel( m_Ini );
  if( modpanel == NULL ) {
    modpanel = NodeOp.inst( wModPanel.name(), m_Ini, ELEMENT_NODE );
    NodeOp.addChild( m_Ini, modpanel );
  }

  m_CXMod->SetValue( wModPanel.getcx(modpanel) );
  m_CYMod->SetValue( wModPanel.getcy(modpanel) );

  m_SVGPath->SetValue( wxString(wPlanPanel.getsvgpath( planpanel ),wxConvUTF8) );
  m_SVGPath2->SetValue( wxString(wPlanPanel.getsvgpath2( planpanel ),wxConvUTF8) );
  m_SVGPath3->SetValue( wxString(wPlanPanel.getsvgpath3( planpanel ),wxConvUTF8) );
  m_SVGPath4->SetValue( wxString(wPlanPanel.getsvgpath4( planpanel ),wxConvUTF8) );
  m_SVGPath5->SetValue( wxString(wPlanPanel.getsvgpath5( planpanel ),wxConvUTF8) );
  m_ItemIDpointsize->SetValue(wPlanPanel.getitemidps( planpanel ));
  m_TextPS->SetValue(wPlanPanel.gettextps( planpanel ));

  m_Speak4Block->SetValue( wxString(wGui.getspeak4block( m_Ini ),wxConvUTF8) );
  m_SpeakCmd->SetValue( wxString(wGui.getspeakcmd( m_Ini ),wxConvUTF8) );

  // RIC
  iONode jsmap = wGui.getjsmap( m_Ini );
  if( jsmap == NULL ) {
    jsmap = NodeOp.inst( wJsMap.name(), m_Ini, ELEMENT_NODE );
    NodeOp.addChild( m_Ini, jsmap );
  }
  m_RICStep->SetValue( wJsMap.getstep(jsmap) );

  val = StrOp.fmt( "%d", wJsMap.getupdown(jsmap) );
  m_Velocity->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);
  val = StrOp.fmt( "%d", wJsMap.getrepeat(jsmap) );
  m_Repeat->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);
  val = StrOp.fmt( "%d", wJsMap.getreverse(jsmap) );
  m_Dir->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);
  val = StrOp.fmt( "%d", wJsMap.getstop(jsmap) );
  m_Stop->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);
  val = StrOp.fmt( "%d", wJsMap.getlight(jsmap) );
  m_Lights->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);
  val = StrOp.fmt( "%d", wJsMap.getf1(jsmap) );
  m_F1->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);
  val = StrOp.fmt( "%d", wJsMap.getf2(jsmap) );
  m_F2->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);
  val = StrOp.fmt( "%d", wJsMap.getf3(jsmap) );
  m_F3->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);
  val = StrOp.fmt( "%d", wJsMap.getf4(jsmap) );
  m_F4->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);
  val = StrOp.fmt( "%d", wJsMap.getf5(jsmap) );
  m_F5->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);
  val = StrOp.fmt( "%d", wJsMap.getf6(jsmap) );
  m_F6->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);
  val = StrOp.fmt( "%d", wJsMap.getf7(jsmap) );
  m_F7->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);
  val = StrOp.fmt( "%d", wJsMap.getf8(jsmap) );
  m_F8->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);
  val = StrOp.fmt( "%d", wJsMap.getf9(jsmap) );
  m_F9->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);
  val = StrOp.fmt( "%d", wJsMap.getf10(jsmap) );
  m_F10->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);
  val = StrOp.fmt( "%d", wJsMap.getf11(jsmap) );
  m_F11->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);
  val = StrOp.fmt( "%d", wJsMap.getf12(jsmap) );
  m_F12->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);
  val = StrOp.fmt( "%d", wJsMap.getpoweron(jsmap) );
  m_PowerOn->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);
  val = StrOp.fmt( "%d", wJsMap.getpoweroff(jsmap) );
  m_PowerOff->SetValue( wxString(val,wxConvUTF8) );
  StrOp.free(val);

  // Clocktype
  const char* clocktype = wGui.getclocktype( m_Ini );
  int type = 0;
  if( StrOp.equals( wGui.clock_ampm, clocktype ) )
    type = 1;
  else if( StrOp.equals( wGui.clock_24h, clocktype ) )
    type = 2;
  else if( StrOp.equals( wGui.clock_digital, clocktype ) )
    type = 3;
  else if( StrOp.equals( wGui.clock_none, clocktype ) )
    type = 4;
  m_ClockType->SetSelection( type );

  m_TabAlignType->SetSelection( wGui.gettabalign( m_Ini ) );

  m_ImagePath->SetValue( wxString(wGui.getimagepath(m_Ini),wxConvUTF8) );
  m_UpdatesPath->SetValue( wxString(wGui.getupdatespath(m_Ini),wxConvUTF8) );
  m_XSLPath->SetValue( wxString(wGui.getxslpath(m_Ini),wxConvUTF8) );
  m_DecPath->SetValue( wxString(wGui.getdecpath(m_Ini),wxConvUTF8) );
  m_Workspace->SetValue( wxString(wGui.getdefaultworkspace(m_Ini),wxConvUTF8) );
  m_DirImageFwd->SetValue( wxString(wGui.getdirimagefwd(m_Ini),wxConvUTF8) );
  m_DirImageRev->SetValue( wxString(wGui.getdirimagerev(m_Ini),wxConvUTF8) );

  // Accelerators
  iONode accelerator = wGui.getaccelerator(m_Ini);
  while( accelerator != NULL ) {
    if( StrOp.equals( wAccelerator.ebreak, wAccelerator.getfunction(accelerator) ) ) {
      //wAccelerator.getmodifier(accelerator), wAccelerator.getkeycode(accelerator)
      if( wAccelerator.getkeycode(accelerator) == WXK_PAUSE )
        m_EmergencyBreakList->SetSelection(1);
      else if( wAccelerator.getkeycode(accelerator) == WXK_SPACE )
        m_EmergencyBreakList->SetSelection(2);
      else
        m_EmergencyBreakList->SetSelection(0);

      if( wAccelerator.getmodifier(accelerator) == wxACCEL_ALT )
        m_EmergencyBreakModifier->SetSelection(1);
      else if( wAccelerator.getmodifier(accelerator) == wxACCEL_CTRL )
        m_EmergencyBreakModifier->SetSelection(2);
      else // wxACCEL_NORMAL
        m_EmergencyBreakModifier->SetSelection(0);
    }
    accelerator = wGui.nextaccelerator(m_Ini, accelerator);
  }

}


void RocguiIniDialog::evaluate() {
  if( m_Ini == NULL )
    return;

  // Trace
  iONode trace = wGui.gettrace( m_Ini );
  if( trace == NULL ) {
    trace = NodeOp.inst( wTrace.name(), m_Ini, ELEMENT_NODE);
    NodeOp.addChild( m_Ini, trace );
  }

  wTrace.setdebug( trace, m_Debug->GetValue() ? True:False );
  wTrace.setinfo( trace, m_Info->GetValue() ? True:False );
  wTrace.setgfile( trace, m_TraceFile->GetValue().mb_str(wxConvUTF8) );
  wTrace.setprotpath( trace, m_ProtPath->GetValue().mb_str(wxConvUTF8) );
  wGui.sethelpurl( m_Ini, m_HelpURL->GetValue().mb_str(wxConvUTF8) );

  wGui.setrestrictedit4auto( m_Ini, m_RestrictEdit4Auto->GetValue() ? True:False );
  //wGui.setcheckupdates( m_Ini, m_Check4Updates->GetValue() ? True:False );
  wGui.setcheckupdates( m_Ini, False );
  wGui.setjssupport( m_Ini, m_JsSupport->GetValue() ? True:False );
  wGui.setdispatchmode( m_Ini, m_DispatchMode->GetValue() ? True:False );
  wGui.setstartdefaultworkspace( m_Ini, m_StartDefaultWorkspace->GetValue() ? True:False );
  wGui.setfsutf8( m_Ini, m_FSUTF8->GetValue() ? True:False );
  wGui.setrestorelcctrl( m_Ini, m_RestoreLcCtrl->GetValue() ? True:False );
  wGui.setmonitoring( m_Ini, m_Monitoring->GetValue() ? True:False );
  wGui.setshowonlystartschedules( m_Ini, m_ShowOnlyStartSchedules->GetValue() ? True:False );
  wGui.setshowsecondhand( m_Ini, m_ShowSecondhand->GetValue() ? True:False );
  wGui.setreconnectafterservershutdown( m_Ini, m_ReconnectAfterServerShutdown->IsChecked() ? True:False );
  wGui.setuseallspeedsteps( m_Ini, m_UseAllSpeedSteps->IsChecked() ? True:False );
  wGui.setrendergc( m_Ini, m_RenderGC->IsChecked() ? True:False );
  wGui.setlocowidgetwidth( m_Ini, m_WidgetWidth->GetValue());
  wGui.setgridfontsizeadjust( m_Ini, m_GridFontSizeAdjust->GetValue());
  wGui.setmonitorsize( m_Ini, m_MonitorSize->GetValue());
  wGui.setstatusboosteruid(m_Ini, atoi(m_BoosterUID->GetValue().mb_str(wxConvUTF8)));
  wGui.setverticaltoolbar( m_Ini, m_VerticalToolbar->IsChecked() ? True:False );
  wGui.settoolbar( m_Ini, m_Toolbar->IsChecked() ? True:False );
  wGui.setshowlocoimage( m_Ini, m_LocoImage->IsChecked() ? True:False );
  wGui.setshowlocoimageinblock( m_Ini, m_ShowLocoImageInBlock->IsChecked() ? True:False );
  wGui.setshowtrainidinblock( m_Ini, m_ShowTrainIdInBlock->IsChecked() ? True:False );
  wGui.setshowroute4switch( m_Ini, m_ShowRoute4Switch->IsChecked() ? True:False );
  wGui.setshowspeedometer( m_Ini, m_ShowSpeedOMeter->IsChecked() ? True:False );
  wGui.setlocoimagecolumn( m_Ini, m_LocoImageColumn->IsChecked() ? True:False );
  wGui.setgrayicons( m_Ini, m_GrayIcons->IsChecked() ? True:False );
  wGui.setsensormonitorauto( m_Ini, m_SensorMonitorAuto->IsChecked() ? True:False );
  wSplitPanel.setdontwrap( wGui.getsplitpanel(m_Ini), m_MonitorDontWrap->IsChecked( ) ? True:False );

  // MIC
  iONode mic = wGui.getmic( m_Ini );
  if( mic == NULL ) {
    mic = NodeOp.inst( wMIC.name(), m_Ini, ELEMENT_NODE);
    NodeOp.addChild( m_Ini, mic );
  }
  wMIC.setstep(mic, m_MICStep->GetValue());
  wMIC.setexitstop( mic, m_MICStopOnExit->GetValue() ? True:False );


  // PT
  iONode cvconf = wGui.getcvconf( m_Ini );
  if( cvconf == NULL ) {
    cvconf = NodeOp.inst( wCVconf.name(), m_Ini, ELEMENT_NODE);
    NodeOp.addChild( m_Ini, cvconf );
  }
  wCVconf.setnrs( cvconf, m_CVnrs->GetValue().mb_str(wxConvUTF8) );
  wCVconf.settimeout(cvconf, atoi(m_Timeout->GetValue().mb_str(wxConvUTF8)));
  wCVconf.setlissy( cvconf, m_Lissy->GetValue() ? True:False );
  wCVconf.setusedecspec4all( cvconf, m_UseDecSpec4All->GetValue() ? True:False );
  wGui.setlncvtab(m_Ini, m_SVtab->GetValue() ? True:False );

  // SVG
  iONode planpanel = wGui.getplanpanel( m_Ini );
  if( planpanel == NULL ) {
    planpanel = NodeOp.inst( wPlanPanel.name(), m_Ini, ELEMENT_NODE);
    NodeOp.addChild( m_Ini, planpanel );
  }
  wPlanPanel.setbktextid(planpanel, m_ShowBlockID->GetValue() ? True:False );
  wPlanPanel.setcx(planpanel, m_CX->GetValue() );
  wPlanPanel.setcy(planpanel, m_CY->GetValue() );
  wPlanPanel.setprocessrouteevents(planpanel, m_ProcessRouteEvents->GetValue() ? True:False );
  wPlanPanel.setprocessblockevents(planpanel, m_ProcessBlockEvents->GetValue() ? True:False );

  iONode modpanel = wGui.getmodpanel( m_Ini );
  if( modpanel == NULL ) {
    modpanel = NodeOp.inst( wModPanel.name(), m_Ini, ELEMENT_NODE);
    NodeOp.addChild( m_Ini, modpanel );
  }
  wModPanel.setcx(modpanel, m_CXMod->GetValue() );
  wModPanel.setcy(modpanel, m_CYMod->GetValue() );

  wPlanPanel.setsvgpath( planpanel, m_SVGPath->GetValue().mb_str(wxConvUTF8) );
  wPlanPanel.setsvgpath2( planpanel, m_SVGPath2->GetValue().mb_str(wxConvUTF8) );
  wPlanPanel.setsvgpath3( planpanel, m_SVGPath3->GetValue().mb_str(wxConvUTF8) );
  wPlanPanel.setsvgpath4( planpanel, m_SVGPath4->GetValue().mb_str(wxConvUTF8) );
  wPlanPanel.setsvgpath5( planpanel, m_SVGPath5->GetValue().mb_str(wxConvUTF8) );
  wPlanPanel.setitemidps( planpanel, m_ItemIDpointsize->GetValue());
  wPlanPanel.settextps( planpanel, m_TextPS->GetValue());

  wGui.setspeak4block( m_Ini, m_Speak4Block->GetValue().mb_str(wxConvUTF8) );
  wGui.setspeakcmd( m_Ini, m_SpeakCmd->GetValue().mb_str(wxConvUTF8) );

  // RIC
  iONode jsmap = wGui.getjsmap( m_Ini );
  if( jsmap == NULL ) {
    planpanel = NodeOp.inst( wJsMap.name(), m_Ini, ELEMENT_NODE);
    NodeOp.addChild( m_Ini, jsmap );
  }
  wJsMap.setstep(jsmap, m_RICStep->GetValue());
  wJsMap.setupdown(jsmap, atoi(m_Velocity->GetValue().mb_str(wxConvUTF8)));
  wJsMap.setrepeat(jsmap, atoi(m_Repeat->GetValue().mb_str(wxConvUTF8)));
  wJsMap.setreverse(jsmap, atoi(m_Dir->GetValue().mb_str(wxConvUTF8)));
  wJsMap.setstop(jsmap, atoi(m_Stop->GetValue().mb_str(wxConvUTF8)));
  wJsMap.setlight(jsmap, atoi(m_Lights->GetValue().mb_str(wxConvUTF8)));
  wJsMap.setf1(jsmap, atoi(m_F1->GetValue().mb_str(wxConvUTF8)));
  wJsMap.setf2(jsmap, atoi(m_F2->GetValue().mb_str(wxConvUTF8)));
  wJsMap.setf3(jsmap, atoi(m_F3->GetValue().mb_str(wxConvUTF8)));
  wJsMap.setf4(jsmap, atoi(m_F4->GetValue().mb_str(wxConvUTF8)));
  wJsMap.setf5(jsmap, atoi(m_F5->GetValue().mb_str(wxConvUTF8)));
  wJsMap.setf6(jsmap, atoi(m_F6->GetValue().mb_str(wxConvUTF8)));
  wJsMap.setf7(jsmap, atoi(m_F7->GetValue().mb_str(wxConvUTF8)));
  wJsMap.setf8(jsmap, atoi(m_F8->GetValue().mb_str(wxConvUTF8)));
  wJsMap.setf9(jsmap, atoi(m_F9->GetValue().mb_str(wxConvUTF8)));
  wJsMap.setf10(jsmap, atoi(m_F10->GetValue().mb_str(wxConvUTF8)));
  wJsMap.setf11(jsmap, atoi(m_F11->GetValue().mb_str(wxConvUTF8)));
  wJsMap.setf12(jsmap, atoi(m_F12->GetValue().mb_str(wxConvUTF8)));
  wJsMap.setpoweron(jsmap, atoi(m_PowerOn->GetValue().mb_str(wxConvUTF8)));
  wJsMap.setpoweroff(jsmap, atoi(m_PowerOff->GetValue().mb_str(wxConvUTF8)));

  // Clocktype
  int type = m_ClockType->GetSelection();
  if( type == 0 )
    wGui.setclocktype( m_Ini, wGui.clock_default );
  else if( type == 1 )
    wGui.setclocktype( m_Ini, wGui.clock_ampm );
  else if( type == 2 )
    wGui.setclocktype( m_Ini, wGui.clock_24h );
  else if( type == 3 )
    wGui.setclocktype( m_Ini, wGui.clock_digital );
  else if( type == 4 )
    wGui.setclocktype( m_Ini, wGui.clock_none );

  wGui.settabalign( m_Ini, m_TabAlignType->GetSelection() );

  wGui.setimagepath( m_Ini, m_ImagePath->GetValue().mb_str(wxConvUTF8) );
  wGui.setupdatespath( m_Ini, m_UpdatesPath->GetValue().mb_str(wxConvUTF8) );
  wGui.setxslpath( m_Ini, m_XSLPath->GetValue().mb_str(wxConvUTF8) );
  wGui.setdecpath( m_Ini, m_DecPath->GetValue().mb_str(wxConvUTF8) );
  wGui.setdefaultworkspace( m_Ini, m_Workspace->GetValue().mb_str(wxConvUTF8) );
  wGui.setdirimagefwd( m_Ini, m_DirImageFwd->GetValue().mb_str(wxConvUTF8) );
  wGui.setdirimagerev( m_Ini, m_DirImageRev->GetValue().mb_str(wxConvUTF8) );

  // Accelerators
  iONode accelerator = wGui.getaccelerator(m_Ini);
  iONode accelEBreak = NULL;
  while( accelerator != NULL ) {
    if( StrOp.equals( wAccelerator.ebreak, wAccelerator.getfunction(accelerator) ) ) {
      accelEBreak = accelerator;
      break;
    }
    accelerator = wGui.nextaccelerator(m_Ini, accelerator);
  }

  if( accelEBreak != NULL &&  m_EmergencyBreakList->GetSelection() == 0 ) {
    NodeOp.removeChild(m_Ini, accelEBreak );
    NodeOp.base.del(accelEBreak);
    accelEBreak = NULL;
  }

  if( m_EmergencyBreakList->GetSelection() > 0 ) {
    if( accelEBreak == NULL ) {
      accelEBreak = NodeOp.inst(wAccelerator.name(), m_Ini, ELEMENT_NODE);
      wAccelerator.setfunction(accelEBreak, wAccelerator.ebreak);
      NodeOp.addChild(m_Ini, accelEBreak);
    }
    if( m_EmergencyBreakList->GetSelection() == 1 )
      wAccelerator.setkeycode(accelEBreak, WXK_PAUSE) ;
    else if( m_EmergencyBreakList->GetSelection() == 2 )
      wAccelerator.setkeycode(accelEBreak, WXK_SPACE) ;
    if( m_EmergencyBreakModifier->GetSelection() == 1 )
      wAccelerator.setmodifier(accelEBreak, wxACCEL_ALT );
    else if( m_EmergencyBreakModifier->GetSelection() == 2 )
      wAccelerator.setmodifier(accelEBreak, wxACCEL_CTRL );
    else
      wAccelerator.setmodifier(accelEBreak, wxACCEL_NORMAL );
  }

}


/*!
 * Dialog creator
 */

bool RocguiIniDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin RocguiIniDialog member initialisation
    m_Notebook = NULL;
    m_GeneralTab = NULL;
    m_ClockType = NULL;
    m_TabAlignType = NULL;
    m_labWidgetWidth = NULL;
    m_WidgetWidth = NULL;
    m_labMonitorSize = NULL;
    m_MonitorSize = NULL;
    m_labGridFontSizeAdjust = NULL;
    m_GridFontSizeAdjust = NULL;
    m_labPanelSize = NULL;
    m_labCX = NULL;
    m_CX = NULL;
    m_labCY = NULL;
    m_CY = NULL;
    m_labModPlanSize = NULL;
    m_labCXMod = NULL;
    m_CXMod = NULL;
    m_labCYMod = NULL;
    m_CYMod = NULL;
    m_RestrictEdit4Auto = NULL;
    m_JsSupport = NULL;
    m_DispatchMode = NULL;
    m_RestoreLcCtrl = NULL;
    m_Monitoring = NULL;
    m_ShowOnlyStartSchedules = NULL;
    m_ShowBlockID = NULL;
    m_ShowSecondhand = NULL;
    m_ReconnectAfterServerShutdown = NULL;
    m_ResetSpeedDir = NULL;
    m_UseAllSpeedSteps = NULL;
    m_RenderGC = NULL;
    m_FSUTF8 = NULL;
    m_Toolbar = NULL;
    m_VerticalToolbar = NULL;
    m_LocoImage = NULL;
    m_MonitorDontWrap = NULL;
    m_ShowSpeedOMeter = NULL;
    m_LocoImageColumn = NULL;
    m_ShowLocoImageInBlock = NULL;
    m_ShowTrainIdInBlock = NULL;
    m_GrayIcons = NULL;
    m_SensorMonitorAuto = NULL;
    m_labWorkspace = NULL;
    m_Workspace = NULL;
    m_WorkspaceDlg = NULL;
    m_StartDefaultWorkspace = NULL;
    m_labImagePath = NULL;
    m_ImagePath = NULL;
    m_ImagePathDlg = NULL;
    m_labUpdatesPath = NULL;
    m_UpdatesPath = NULL;
    m_UpdatePathDlg = NULL;
    m_labXSLPath = NULL;
    m_XSLPath = NULL;
    m_XSLPathDlg = NULL;
    m_labDecPath = NULL;
    m_DecPath = NULL;
    m_DecPathDlg = NULL;
    m_labSpeak4Block = NULL;
    m_Speak4Block = NULL;
    m_labSpeakCmd = NULL;
    m_SpeakCmd = NULL;
    m_labDirImage = NULL;
    m_DirImageFwd = NULL;
    m_DirImageRev = NULL;
    m_labBoosterUID = NULL;
    m_BoosterUID = NULL;
    m_TracePanel = NULL;
    m_TraceLevel = NULL;
    m_Debug = NULL;
    m_Info = NULL;
    m_TraceFileBox = NULL;
    m_labTraceFile = NULL;
    m_TraceFile = NULL;
    m_labProtPath = NULL;
    m_ProtPath = NULL;
    m_HelpBox = NULL;
    m_HelpURL = NULL;
    m_PTpanel = NULL;
    m_labCVnrs = NULL;
    m_CVnrs = NULL;
    m_labTimeout = NULL;
    m_Timeout = NULL;
    m_Lissy = NULL;
    m_SVtab = NULL;
    m_UseDecSpec4All = NULL;
    m_SVGpanel = NULL;
    m_labTheme1 = NULL;
    m_SVGPath = NULL;
    m_SvgPathDlg = NULL;
    m_labTheme2 = NULL;
    m_SVGPath2 = NULL;
    m_SvgPath2Dlg = NULL;
    m_labTheme3 = NULL;
    m_SVGPath3 = NULL;
    m_SvgPath3Dlg = NULL;
    m_labTheme4 = NULL;
    m_SVGPath4 = NULL;
    m_SvgPath4Dlg = NULL;
    m_labTheme5 = NULL;
    m_SVGPath5 = NULL;
    m_SvgPath5Dlg = NULL;
    m_labItemIDpointsize = NULL;
    m_ItemIDpointsize = NULL;
    m_labTextPS = NULL;
    m_TextPS = NULL;
    m_ProcessRouteEvents = NULL;
    m_ProcessBlockEvents = NULL;
    m_ShowRoute4Switch = NULL;
    m_RICpanel = NULL;
    m_labVelocity = NULL;
    m_labY = NULL;
    m_Velocity = NULL;
    m_labRepeat = NULL;
    m_Repeat = NULL;
    m_labDir = NULL;
    m_Dir = NULL;
    m_labStop = NULL;
    m_Stop = NULL;
    m_labRICStep = NULL;
    m_RICStep = NULL;
    m_FunctionsBox = NULL;
    m_labLights = NULL;
    m_Lights = NULL;
    m_labF1 = NULL;
    m_F1 = NULL;
    m_labF2 = NULL;
    m_F2 = NULL;
    m_labF3 = NULL;
    m_F3 = NULL;
    m_labF4 = NULL;
    m_F4 = NULL;
    m_labF5 = NULL;
    m_F5 = NULL;
    m_labF6 = NULL;
    m_F6 = NULL;
    m_labF7 = NULL;
    m_F7 = NULL;
    m_labF8 = NULL;
    m_F8 = NULL;
    m_labF9 = NULL;
    m_F9 = NULL;
    m_labF10 = NULL;
    m_F10 = NULL;
    m_labF11 = NULL;
    m_F11 = NULL;
    m_labF12 = NULL;
    m_F12 = NULL;
    m_PowerBox = NULL;
    m_labPowerOn = NULL;
    m_PowerOn = NULL;
    m_labPowerOff = NULL;
    m_PowerOff = NULL;
    m_MICpanel = NULL;
    m_labMICStep = NULL;
    m_MICStep = NULL;
    m_MICStopOnExit = NULL;
    m_AcceleratorPanel = NULL;
    m_labAccelFunction = NULL;
    m_labAccelKeyCode = NULL;
    m_labAccelModifier = NULL;
    m_labEmergencyBreak = NULL;
    m_EmergencyBreakList = NULL;
    m_EmergencyBreakModifier = NULL;
    m_OK = NULL;
    m_Cancel = NULL;
    m_Help = NULL;
////@end RocguiIniDialog member initialisation

////@begin RocguiIniDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end RocguiIniDialog creation
    return true;
}

/*!
 * Control creation for Dialog
 */

void RocguiIniDialog::CreateControls()
{
////@begin RocguiIniDialog content construction
    RocguiIniDialog* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    m_Notebook = new wxNotebook( itemDialog1, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, m_TabAlign );

    m_GeneralTab = new wxPanel( m_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    m_GeneralTab->SetSizer(itemBoxSizer5);

    wxBoxSizer* itemBoxSizer6 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer5->Add(itemBoxSizer6, 0, wxALIGN_TOP|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer7 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer6->Add(itemFlexGridSizer7, 0, wxGROW|wxALL, 5);
    wxArrayString m_ClockTypeStrings;
    m_ClockTypeStrings.Add(_("&Default"));
    m_ClockTypeStrings.Add(_("&AM/PM"));
    m_ClockTypeStrings.Add(_("&24h"));
    m_ClockTypeStrings.Add(_("&digital"));
    m_ClockTypeStrings.Add(_("&none"));
    m_ClockType = new wxRadioBox( m_GeneralTab, wxID_ANY, _("Clocktype"), wxDefaultPosition, wxDefaultSize, m_ClockTypeStrings, 1, wxRA_SPECIFY_COLS );
    m_ClockType->SetSelection(0);
    itemFlexGridSizer7->Add(m_ClockType, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_TOP|wxALL, 5);

    wxArrayString m_TabAlignTypeStrings;
    m_TabAlignTypeStrings.Add(_("&default"));
    m_TabAlignTypeStrings.Add(_("&left"));
    m_TabAlignTypeStrings.Add(_("&multiline"));
    m_TabAlignType = new wxRadioBox( m_GeneralTab, wxID_ANY, _("TabAlign"), wxDefaultPosition, wxDefaultSize, m_TabAlignTypeStrings, 1, wxRA_SPECIFY_COLS );
    m_TabAlignType->SetSelection(0);
    itemFlexGridSizer7->Add(m_TabAlignType, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_TOP|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer10 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer6->Add(itemFlexGridSizer10, 0, wxALIGN_LEFT, 5);
    m_labWidgetWidth = new wxStaticText( m_GeneralTab, wxID_ANY, _("Widget width"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer10->Add(m_labWidgetWidth, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_WidgetWidth = new wxSpinCtrl( m_GeneralTab, wxID_ANY, wxT("260"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 100, 350, 260 );
    itemFlexGridSizer10->Add(m_WidgetWidth, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labMonitorSize = new wxStaticText( m_GeneralTab, wxID_ANY, _("Monitor size"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer10->Add(m_labMonitorSize, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_MonitorSize = new wxSpinCtrl( m_GeneralTab, wxID_ANY, wxT("4"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 1, 16, 4 );
    itemFlexGridSizer10->Add(m_MonitorSize, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labGridFontSizeAdjust = new wxStaticText( m_GeneralTab, wxID_ANY, _("Grid fontsize adjust"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer10->Add(m_labGridFontSizeAdjust, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_GridFontSizeAdjust = new wxSpinCtrl( m_GeneralTab, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, -5, 5, 0 );
    itemFlexGridSizer10->Add(m_GridFontSizeAdjust, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer17 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer6->Add(itemBoxSizer17, 0, wxGROW, 5);
    m_labPanelSize = new wxStaticBox(m_GeneralTab, wxID_ANY, _("Planpanel size"));
    wxStaticBoxSizer* itemStaticBoxSizer18 = new wxStaticBoxSizer(m_labPanelSize, wxHORIZONTAL);
    itemBoxSizer17->Add(itemStaticBoxSizer18, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer19 = new wxFlexGridSizer(0, 2, 0, 0);
    itemStaticBoxSizer18->Add(itemFlexGridSizer19, 0, wxGROW, 5);
    m_labCX = new wxStaticText( m_GeneralTab, wxID_ANY, _("CX"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer19->Add(m_labCX, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_CX = new wxSpinCtrl( m_GeneralTab, wxID_ANY, wxT("64"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 256, 64 );
    itemFlexGridSizer19->Add(m_CX, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labCY = new wxStaticText( m_GeneralTab, wxID_ANY, _("CY"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer19->Add(m_labCY, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_CY = new wxSpinCtrl( m_GeneralTab, wxID_ANY, wxT("48"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 256, 48 );
    itemFlexGridSizer19->Add(m_CY, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labModPlanSize = new wxStaticBox(m_GeneralTab, wxID_ANY, _("ModPlan size"));
    wxStaticBoxSizer* itemStaticBoxSizer24 = new wxStaticBoxSizer(m_labModPlanSize, wxHORIZONTAL);
    itemBoxSizer17->Add(itemStaticBoxSizer24, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer25 = new wxFlexGridSizer(0, 2, 0, 0);
    itemStaticBoxSizer24->Add(itemFlexGridSizer25, 0, wxGROW, 5);
    m_labCXMod = new wxStaticText( m_GeneralTab, wxID_ANY, _("CX"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer25->Add(m_labCXMod, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_CXMod = new wxSpinCtrl( m_GeneralTab, wxID_ANY, wxT("128"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 256, 128 );
    itemFlexGridSizer25->Add(m_CXMod, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labCYMod = new wxStaticText( m_GeneralTab, wxID_ANY, _("CY"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer25->Add(m_labCYMod, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_CYMod = new wxSpinCtrl( m_GeneralTab, wxID_ANY, wxT("96"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 256, 96 );
    itemFlexGridSizer25->Add(m_CYMod, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxStaticLine* itemStaticLine30 = new wxStaticLine( m_GeneralTab, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    itemBoxSizer5->Add(itemStaticLine30, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer31 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer5->Add(itemBoxSizer31, 0, wxALIGN_TOP|wxALL, 5);
    m_RestrictEdit4Auto = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Restrict edit in automode"), wxDefaultPosition, wxDefaultSize, 0 );
    m_RestrictEdit4Auto->SetValue(false);
    itemBoxSizer31->Add(m_RestrictEdit4Auto, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 5);

    m_JsSupport = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Gamepad support"), wxDefaultPosition, wxDefaultSize, 0 );
    m_JsSupport->SetValue(false);
    itemBoxSizer31->Add(m_JsSupport, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_DispatchMode = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Use mode column to dispatch"), wxDefaultPosition, wxDefaultSize, 0 );
    m_DispatchMode->SetValue(false);
    itemBoxSizer31->Add(m_DispatchMode, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_RestoreLcCtrl = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Restore throttle"), wxDefaultPosition, wxDefaultSize, 0 );
    m_RestoreLcCtrl->SetValue(true);
    itemBoxSizer31->Add(m_RestoreLcCtrl, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_Monitoring = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Monitoring"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Monitoring->SetValue(false);
    itemBoxSizer31->Add(m_Monitoring, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_ShowOnlyStartSchedules = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Show only start schedules"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ShowOnlyStartSchedules->SetValue(false);
    itemBoxSizer31->Add(m_ShowOnlyStartSchedules, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_ShowBlockID = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Show block ID"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ShowBlockID->SetValue(false);
    itemBoxSizer31->Add(m_ShowBlockID, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_ShowSecondhand = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Show secondhand"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ShowSecondhand->SetValue(true);
    itemBoxSizer31->Add(m_ShowSecondhand, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_ReconnectAfterServerShutdown = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Reconnect after server shutdown"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ReconnectAfterServerShutdown->SetValue(false);
    itemBoxSizer31->Add(m_ReconnectAfterServerShutdown, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_ResetSpeedDir = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Reset speed at direction change"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ResetSpeedDir->SetValue(false);
    itemBoxSizer31->Add(m_ResetSpeedDir, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_UseAllSpeedSteps = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Use all speed steps"), wxDefaultPosition, wxDefaultSize, 0 );
    m_UseAllSpeedSteps->SetValue(false);
    itemBoxSizer31->Add(m_UseAllSpeedSteps, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_RenderGC = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Render GC"), wxDefaultPosition, wxDefaultSize, 0 );
    m_RenderGC->SetValue(false);
    itemBoxSizer31->Add(m_RenderGC, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_FSUTF8 = new wxCheckBox( m_GeneralTab, wxID_ANY, _("UTF-8"), wxDefaultPosition, wxDefaultSize, 0 );
    m_FSUTF8->SetValue(false);
    itemBoxSizer31->Add(m_FSUTF8, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_Toolbar = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Toolbar"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Toolbar->SetValue(false);
    itemBoxSizer31->Add(m_Toolbar, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_VerticalToolbar = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Vertical toolbar"), wxDefaultPosition, wxDefaultSize, 0 );
    m_VerticalToolbar->SetValue(false);
    itemBoxSizer31->Add(m_VerticalToolbar, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_LocoImage = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Loco image"), wxDefaultPosition, wxDefaultSize, 0 );
    m_LocoImage->SetValue(false);
    itemBoxSizer31->Add(m_LocoImage, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_MonitorDontWrap = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Don't wrap monitor"), wxDefaultPosition, wxDefaultSize, 0 );
    m_MonitorDontWrap->SetValue(false);
    itemBoxSizer31->Add(m_MonitorDontWrap, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_ShowSpeedOMeter = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Speedometer"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ShowSpeedOMeter->SetValue(false);
    itemBoxSizer31->Add(m_ShowSpeedOMeter, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_LocoImageColumn = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Loco image column"), wxDefaultPosition, wxDefaultSize, 0 );
    m_LocoImageColumn->SetValue(false);
    itemBoxSizer31->Add(m_LocoImageColumn, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_ShowLocoImageInBlock = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Show loco image in block"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ShowLocoImageInBlock->SetValue(false);
    itemBoxSizer31->Add(m_ShowLocoImageInBlock, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_ShowTrainIdInBlock = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Show train ID in block"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ShowTrainIdInBlock->SetValue(false);
    itemBoxSizer31->Add(m_ShowTrainIdInBlock, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_GrayIcons = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Gray icons"), wxDefaultPosition, wxDefaultSize, 0 );
    m_GrayIcons->SetValue(false);
    itemBoxSizer31->Add(m_GrayIcons, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_SensorMonitorAuto = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Sensor monitor in automatic mode"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SensorMonitorAuto->SetValue(false);
    itemBoxSizer31->Add(m_SensorMonitorAuto, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    wxStaticLine* itemStaticLine55 = new wxStaticLine( m_GeneralTab, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    itemBoxSizer5->Add(itemStaticLine55, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer56 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer5->Add(itemBoxSizer56, 0, wxALIGN_TOP|wxALL, 5);
    m_labWorkspace = new wxStaticBox(m_GeneralTab, wxID_ANY, _("Default Workspace"));
    wxStaticBoxSizer* itemStaticBoxSizer57 = new wxStaticBoxSizer(m_labWorkspace, wxHORIZONTAL);
    itemBoxSizer56->Add(itemStaticBoxSizer57, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 5);
    wxFlexGridSizer* itemFlexGridSizer58 = new wxFlexGridSizer(0, 2, 0, 0);
    itemStaticBoxSizer57->Add(itemFlexGridSizer58, 1, wxALIGN_CENTER_VERTICAL, 5);
    m_Workspace = new wxTextCtrl( m_GeneralTab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer58->Add(m_Workspace, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_WorkspaceDlg = new wxButton( m_GeneralTab, ID_WORKSPACE, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemFlexGridSizer58->Add(m_WorkspaceDlg, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    m_StartDefaultWorkspace = new wxCheckBox( m_GeneralTab, wxID_ANY, _("Use at startup"), wxDefaultPosition, wxDefaultSize, 0 );
    m_StartDefaultWorkspace->SetValue(false);
    itemFlexGridSizer58->Add(m_StartDefaultWorkspace, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    itemFlexGridSizer58->AddGrowableCol(0);

    m_labImagePath = new wxStaticBox(m_GeneralTab, wxID_ANY, _("Image Path"));
    wxStaticBoxSizer* itemStaticBoxSizer62 = new wxStaticBoxSizer(m_labImagePath, wxHORIZONTAL);
    itemBoxSizer56->Add(itemStaticBoxSizer62, 0, wxGROW|wxLEFT|wxRIGHT, 5);
    m_ImagePath = new wxTextCtrl( m_GeneralTab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1), 0 );
    itemStaticBoxSizer62->Add(m_ImagePath, 1, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_ImagePathDlg = new wxButton( m_GeneralTab, ID_IMAGEPATH_BUTTON, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemStaticBoxSizer62->Add(m_ImagePathDlg, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    m_labUpdatesPath = new wxStaticBox(m_GeneralTab, wxID_ANY, _("Updates Path"));
    wxStaticBoxSizer* itemStaticBoxSizer65 = new wxStaticBoxSizer(m_labUpdatesPath, wxHORIZONTAL);
    itemBoxSizer56->Add(itemStaticBoxSizer65, 0, wxGROW|wxLEFT|wxRIGHT, 5);
    m_UpdatesPath = new wxTextCtrl( m_GeneralTab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1), 0 );
    itemStaticBoxSizer65->Add(m_UpdatesPath, 1, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_UpdatePathDlg = new wxButton( m_GeneralTab, ID_UPDATESPATH_BUTTON, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemStaticBoxSizer65->Add(m_UpdatePathDlg, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    m_labXSLPath = new wxStaticBox(m_GeneralTab, wxID_ANY, _("Stylesheets Path"));
    wxStaticBoxSizer* itemStaticBoxSizer68 = new wxStaticBoxSizer(m_labXSLPath, wxHORIZONTAL);
    itemBoxSizer56->Add(itemStaticBoxSizer68, 0, wxGROW|wxLEFT|wxRIGHT, 5);
    m_XSLPath = new wxTextCtrl( m_GeneralTab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1), 0 );
    itemStaticBoxSizer68->Add(m_XSLPath, 1, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_XSLPathDlg = new wxButton( m_GeneralTab, ID_XSLPATH_BUTTON, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemStaticBoxSizer68->Add(m_XSLPathDlg, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    m_labDecPath = new wxStaticBox(m_GeneralTab, wxID_ANY, _("Decoder Path"));
    wxStaticBoxSizer* itemStaticBoxSizer71 = new wxStaticBoxSizer(m_labDecPath, wxHORIZONTAL);
    itemBoxSizer56->Add(itemStaticBoxSizer71, 0, wxGROW|wxLEFT|wxRIGHT, 5);
    m_DecPath = new wxTextCtrl( m_GeneralTab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticBoxSizer71->Add(m_DecPath, 1, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_DecPathDlg = new wxButton( m_GeneralTab, ID_DECPATH_BUTTON, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemStaticBoxSizer71->Add(m_DecPathDlg, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT, 5);

    wxFlexGridSizer* itemFlexGridSizer74 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer56->Add(itemFlexGridSizer74, 0, wxGROW, 5);
    m_labSpeak4Block = new wxStaticText( m_GeneralTab, wxID_ANY, _("Speak for block"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer74->Add(m_labSpeak4Block, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_Speak4Block = new wxTextCtrl( m_GeneralTab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer74->Add(m_Speak4Block, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_labSpeakCmd = new wxStaticText( m_GeneralTab, wxID_ANY, _("Speak command"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer74->Add(m_labSpeakCmd, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_SpeakCmd = new wxTextCtrl( m_GeneralTab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer74->Add(m_SpeakCmd, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_labDirImage = new wxStaticText( m_GeneralTab, wxID_ANY, _("Direction image"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer74->Add(m_labDirImage, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxFlexGridSizer* itemFlexGridSizer80 = new wxFlexGridSizer(0, 3, 0, 0);
    itemFlexGridSizer74->Add(itemFlexGridSizer80, 0, wxGROW|wxALIGN_CENTER_VERTICAL, 0);
    m_DirImageFwd = new wxTextCtrl( m_GeneralTab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer80->Add(m_DirImageFwd, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_DirImageRev = new wxTextCtrl( m_GeneralTab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer80->Add(m_DirImageRev, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_labBoosterUID = new wxStaticText( m_GeneralTab, wxID_ANY, _("Booster UID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer74->Add(m_labBoosterUID, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_BoosterUID = new wxTextCtrl( m_GeneralTab, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer74->Add(m_BoosterUID, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer74->AddGrowableCol(1);

    m_Notebook->AddPage(m_GeneralTab, _("General"));

    m_TracePanel = new wxPanel( m_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer86 = new wxBoxSizer(wxVERTICAL);
    m_TracePanel->SetSizer(itemBoxSizer86);

    wxStaticBox* itemStaticBoxSizer87Static = new wxStaticBox(m_TracePanel, wxID_ANY, _("Level"));
    m_TraceLevel = new wxStaticBoxSizer(itemStaticBoxSizer87Static, wxVERTICAL);
    itemBoxSizer86->Add(m_TraceLevel, 0, wxGROW|wxALL, 5);
    m_Debug = new wxCheckBox( m_TracePanel, wxID_ANY, _("Debug"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_Debug->SetValue(false);
    m_TraceLevel->Add(m_Debug, 0, wxALIGN_LEFT|wxALL, 5);

    m_Info = new wxCheckBox( m_TracePanel, wxID_ANY, _("Info"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Info->SetValue(false);
    m_TraceLevel->Add(m_Info, 0, wxALIGN_LEFT|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer90Static = new wxStaticBox(m_TracePanel, wxID_ANY, wxEmptyString);
    m_TraceFileBox = new wxStaticBoxSizer(itemStaticBoxSizer90Static, wxVERTICAL);
    itemBoxSizer86->Add(m_TraceFileBox, 0, wxGROW|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer91 = new wxFlexGridSizer(0, 2, 0, 0);
    m_TraceFileBox->Add(itemFlexGridSizer91, 0, wxGROW, 5);
    m_labTraceFile = new wxStaticText( m_TracePanel, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer91->Add(m_labTraceFile, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_TraceFile = new wxTextCtrl( m_TracePanel, ID_TEXTCTRL_RG_TRACEFILE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer91->Add(m_TraceFile, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labProtPath = new wxStaticText( m_TracePanel, wxID_ANY, _("Path"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer91->Add(m_labProtPath, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ProtPath = new wxTextCtrl( m_TracePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer91->Add(m_ProtPath, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer91->AddGrowableCol(1);

    m_HelpBox = new wxStaticBox(m_TracePanel, wxID_ANY, _("Help"));
    wxStaticBoxSizer* itemStaticBoxSizer96 = new wxStaticBoxSizer(m_HelpBox, wxVERTICAL);
    itemBoxSizer86->Add(itemStaticBoxSizer96, 0, wxGROW|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer97 = new wxFlexGridSizer(0, 2, 0, 0);
    itemStaticBoxSizer96->Add(itemFlexGridSizer97, 0, wxGROW, 5);
    wxStaticText* itemStaticText98 = new wxStaticText( m_TracePanel, wxID_ANY, _("URL:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer97->Add(itemStaticText98, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_HelpURL = new wxTextCtrl( m_TracePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer97->Add(m_HelpURL, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer97->AddGrowableCol(1);

    m_Notebook->AddPage(m_TracePanel, _("Trace"));

    m_PTpanel = new wxPanel( m_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer101 = new wxBoxSizer(wxVERTICAL);
    m_PTpanel->SetSizer(itemBoxSizer101);

    wxFlexGridSizer* itemFlexGridSizer102 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer101->Add(itemFlexGridSizer102, 0, wxGROW|wxALL, 5);
    m_labCVnrs = new wxStaticText( m_PTpanel, wxID_ANY, _("CV nrs"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer102->Add(m_labCVnrs, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_CVnrs = new wxTextCtrl( m_PTpanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer102->Add(m_CVnrs, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labTimeout = new wxStaticText( m_PTpanel, wxID_ANY, _("Timeout"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer102->Add(m_labTimeout, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Timeout = new wxTextCtrl( m_PTpanel, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer102->Add(m_Timeout, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer102->AddGrowableCol(1);

    m_Lissy = new wxCheckBox( m_PTpanel, wxID_ANY, _("Lissy addressing"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Lissy->SetValue(false);
    itemBoxSizer101->Add(m_Lissy, 0, wxALIGN_LEFT|wxALL, 5);

    m_SVtab = new wxCheckBox( m_PTpanel, wxID_ANY, _("LocoNet SV Tab"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SVtab->SetValue(false);
    itemBoxSizer101->Add(m_SVtab, 0, wxALIGN_LEFT|wxALL, 5);

    m_UseDecSpec4All = new wxCheckBox( m_PTpanel, wxID_ANY, _("Use decoder file for CV numbers"), wxDefaultPosition, wxDefaultSize, 0 );
    m_UseDecSpec4All->SetValue(false);
    itemBoxSizer101->Add(m_UseDecSpec4All, 0, wxALIGN_LEFT|wxALL, 5);

    m_Notebook->AddPage(m_PTpanel, _("PT"));

    m_SVGpanel = new wxPanel( m_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer111 = new wxBoxSizer(wxVERTICAL);
    m_SVGpanel->SetSizer(itemBoxSizer111);

    wxFlexGridSizer* itemFlexGridSizer112 = new wxFlexGridSizer(0, 3, 0, 0);
    itemBoxSizer111->Add(itemFlexGridSizer112, 0, wxGROW|wxALL, 5);
    m_labTheme1 = new wxStaticText( m_SVGpanel, wxID_ANY, _("Theme 1"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer112->Add(m_labTheme1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SVGPath = new wxTextCtrl( m_SVGpanel, wxID_ANY, _("."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer112->Add(m_SVGPath, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_SvgPathDlg = new wxButton( m_SVGpanel, ID_SVGPATH_BUTTON, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemFlexGridSizer112->Add(m_SvgPathDlg, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labTheme2 = new wxStaticText( m_SVGpanel, wxID_ANY, _("Theme 2"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer112->Add(m_labTheme2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SVGPath2 = new wxTextCtrl( m_SVGpanel, wxID_ANY, _("."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer112->Add(m_SVGPath2, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_SvgPath2Dlg = new wxButton( m_SVGpanel, ID_SVGPATH2_BUTTON, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemFlexGridSizer112->Add(m_SvgPath2Dlg, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labTheme3 = new wxStaticText( m_SVGpanel, wxID_ANY, _("Theme 3"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer112->Add(m_labTheme3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SVGPath3 = new wxTextCtrl( m_SVGpanel, wxID_ANY, _("."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer112->Add(m_SVGPath3, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_SvgPath3Dlg = new wxButton( m_SVGpanel, ID_SVGPATH3_BUTTON, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemFlexGridSizer112->Add(m_SvgPath3Dlg, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labTheme4 = new wxStaticText( m_SVGpanel, wxID_ANY, _("Theme 4"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer112->Add(m_labTheme4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SVGPath4 = new wxTextCtrl( m_SVGpanel, wxID_ANY, _("."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer112->Add(m_SVGPath4, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_SvgPath4Dlg = new wxButton( m_SVGpanel, ID_SVGPATH4_BUTTON, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemFlexGridSizer112->Add(m_SvgPath4Dlg, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labTheme5 = new wxStaticText( m_SVGpanel, wxID_ANY, _("Theme 5"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer112->Add(m_labTheme5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SVGPath5 = new wxTextCtrl( m_SVGpanel, wxID_ANY, _("."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer112->Add(m_SVGPath5, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_SvgPath5Dlg = new wxButton( m_SVGpanel, ID_SVGPATH5_BUTTON, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemFlexGridSizer112->Add(m_SvgPath5Dlg, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemFlexGridSizer112->AddGrowableCol(1);

    wxFlexGridSizer* itemFlexGridSizer128 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer111->Add(itemFlexGridSizer128, 0, wxGROW|wxLEFT|wxRIGHT, 5);
    m_labItemIDpointsize = new wxStaticText( m_SVGpanel, wxID_ANY, _("Item ID pointsize"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer128->Add(m_labItemIDpointsize, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ItemIDpointsize = new wxSpinCtrl( m_SVGpanel, wxID_ANY, wxT("7"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 5, 10, 7 );
    itemFlexGridSizer128->Add(m_ItemIDpointsize, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labTextPS = new wxStaticText( m_SVGpanel, wxID_ANY, _("Text pointsize"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer128->Add(m_labTextPS, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_TextPS = new wxSpinCtrl( m_SVGpanel, wxID_ANY, wxT("10"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 6, 15, 10 );
    itemFlexGridSizer128->Add(m_TextPS, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_ProcessRouteEvents = new wxCheckBox( m_SVGpanel, wxID_ANY, _("Process Route events"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ProcessRouteEvents->SetValue(false);
    itemBoxSizer111->Add(m_ProcessRouteEvents, 0, wxALIGN_LEFT|wxALL, 5);

    m_ProcessBlockEvents = new wxCheckBox( m_SVGpanel, wxID_ANY, _("Process Block events"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ProcessBlockEvents->SetValue(false);
    itemBoxSizer111->Add(m_ProcessBlockEvents, 0, wxALIGN_LEFT|wxALL, 5);

    m_ShowRoute4Switch = new wxCheckBox( m_SVGpanel, wxID_ANY, _("Show route over switch"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ShowRoute4Switch->SetValue(false);
    itemBoxSizer111->Add(m_ShowRoute4Switch, 0, wxALIGN_LEFT|wxALL, 5);

    m_Notebook->AddPage(m_SVGpanel, _("SVG"));

    m_RICpanel = new wxPanel( m_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer137 = new wxBoxSizer(wxVERTICAL);
    m_RICpanel->SetSizer(itemBoxSizer137);

    wxStaticBox* itemStaticBoxSizer138Static = new wxStaticBox(m_RICpanel, wxID_ANY, _("Velocity"));
    m_labVelocity = new wxStaticBoxSizer(itemStaticBoxSizer138Static, wxVERTICAL);
    itemBoxSizer137->Add(m_labVelocity, 0, wxALIGN_LEFT|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer139 = new wxFlexGridSizer(0, 4, 0, 0);
    m_labVelocity->Add(itemFlexGridSizer139, 0, wxGROW, 5);
    m_labY = new wxStaticText( m_RICpanel, wxID_ANY, _("V"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer139->Add(m_labY, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_Velocity = new wxTextCtrl( m_RICpanel, wxID_ANY, _("5"), wxDefaultPosition, wxSize(40, -1), wxTE_CENTRE );
    itemFlexGridSizer139->Add(m_Velocity, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labRepeat = new wxStaticText( m_RICpanel, wxID_ANY, _("repeat"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer139->Add(m_labRepeat, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_Repeat = new wxTextCtrl( m_RICpanel, wxID_ANY, _("500"), wxDefaultPosition, wxSize(50, -1), wxTE_CENTRE );
    itemFlexGridSizer139->Add(m_Repeat, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labDir = new wxStaticText( m_RICpanel, wxID_ANY, _("dir"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer139->Add(m_labDir, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT, 5);

    m_Dir = new wxTextCtrl( m_RICpanel, wxID_ANY, _("4"), wxDefaultPosition, wxSize(40, -1), wxTE_CENTRE );
    itemFlexGridSizer139->Add(m_Dir, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labStop = new wxStaticText( m_RICpanel, wxID_ANY, _("stop"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer139->Add(m_labStop, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT, 5);

    m_Stop = new wxTextCtrl( m_RICpanel, wxID_ANY, _("6"), wxDefaultPosition, wxSize(40, -1), wxTE_CENTRE );
    itemFlexGridSizer139->Add(m_Stop, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxFlexGridSizer* itemFlexGridSizer148 = new wxFlexGridSizer(0, 2, 0, 0);
    m_labVelocity->Add(itemFlexGridSizer148, 0, wxGROW, 5);
    m_labRICStep = new wxStaticText( m_RICpanel, wxID_ANY, _("step"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer148->Add(m_labRICStep, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_RICStep = new wxSpinCtrl( m_RICpanel, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize(70, -1), wxSP_ARROW_KEYS, 1, 9, 1 );
    itemFlexGridSizer148->Add(m_RICStep, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer151Static = new wxStaticBox(m_RICpanel, wxID_ANY, _("Functions"));
    m_FunctionsBox = new wxStaticBoxSizer(itemStaticBoxSizer151Static, wxVERTICAL);
    itemBoxSizer137->Add(m_FunctionsBox, 0, wxALIGN_LEFT|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer152 = new wxFlexGridSizer(0, 6, 0, 0);
    m_FunctionsBox->Add(itemFlexGridSizer152, 0, wxGROW, 5);
    m_labLights = new wxStaticText( m_RICpanel, wxID_ANY, _("lights"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer152->Add(m_labLights, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_Lights = new wxTextCtrl( m_RICpanel, wxID_ANY, _("5"), wxDefaultPosition, wxSize(40, -1), wxTE_CENTRE );
    itemFlexGridSizer152->Add(m_Lights, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labF1 = new wxStaticText( m_RICpanel, wxID_ANY, _("F1"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer152->Add(m_labF1, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_F1 = new wxTextCtrl( m_RICpanel, wxID_ANY, _("0"), wxDefaultPosition, wxSize(40, -1), wxTE_CENTRE );
    itemFlexGridSizer152->Add(m_F1, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labF2 = new wxStaticText( m_RICpanel, wxID_ANY, _("F2"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer152->Add(m_labF2, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_F2 = new wxTextCtrl( m_RICpanel, wxID_ANY, _("1"), wxDefaultPosition, wxSize(40, -1), wxTE_CENTRE );
    itemFlexGridSizer152->Add(m_F2, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labF3 = new wxStaticText( m_RICpanel, wxID_ANY, _("F3"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer152->Add(m_labF3, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_F3 = new wxTextCtrl( m_RICpanel, wxID_ANY, _("2"), wxDefaultPosition, wxSize(40, -1), wxTE_CENTRE );
    itemFlexGridSizer152->Add(m_F3, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labF4 = new wxStaticText( m_RICpanel, wxID_ANY, _("F4"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer152->Add(m_labF4, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_F4 = new wxTextCtrl( m_RICpanel, wxID_ANY, _("3"), wxDefaultPosition, wxSize(40, -1), wxTE_CENTRE );
    itemFlexGridSizer152->Add(m_F4, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labF5 = new wxStaticText( m_RICpanel, wxID_ANY, _("F5"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer152->Add(m_labF5, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_F5 = new wxTextCtrl( m_RICpanel, wxID_ANY, _("-1"), wxDefaultPosition, wxSize(40, -1), 0 );
    itemFlexGridSizer152->Add(m_F5, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labF6 = new wxStaticText( m_RICpanel, wxID_ANY, _("F6"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer152->Add(m_labF6, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_F6 = new wxTextCtrl( m_RICpanel, wxID_ANY, _("-1"), wxDefaultPosition, wxSize(40, -1), 0 );
    itemFlexGridSizer152->Add(m_F6, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labF7 = new wxStaticText( m_RICpanel, wxID_ANY, _("F7"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer152->Add(m_labF7, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_F7 = new wxTextCtrl( m_RICpanel, wxID_ANY, _("-1"), wxDefaultPosition, wxSize(40, -1), 0 );
    itemFlexGridSizer152->Add(m_F7, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labF8 = new wxStaticText( m_RICpanel, wxID_ANY, _("F8"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer152->Add(m_labF8, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_F8 = new wxTextCtrl( m_RICpanel, wxID_ANY, _("-1"), wxDefaultPosition, wxSize(40, -1), 0 );
    itemFlexGridSizer152->Add(m_F8, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labF9 = new wxStaticText( m_RICpanel, wxID_ANY, _("F9"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer152->Add(m_labF9, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_F9 = new wxTextCtrl( m_RICpanel, wxID_ANY, _("-1"), wxDefaultPosition, wxSize(40, -1), 0 );
    itemFlexGridSizer152->Add(m_F9, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labF10 = new wxStaticText( m_RICpanel, wxID_ANY, _("F10"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer152->Add(m_labF10, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_F10 = new wxTextCtrl( m_RICpanel, wxID_ANY, _("-1"), wxDefaultPosition, wxSize(40, -1), 0 );
    itemFlexGridSizer152->Add(m_F10, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labF11 = new wxStaticText( m_RICpanel, wxID_ANY, _("F11"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer152->Add(m_labF11, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_F11 = new wxTextCtrl( m_RICpanel, wxID_ANY, _("-1"), wxDefaultPosition, wxSize(40, -1), 0 );
    itemFlexGridSizer152->Add(m_F11, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labF12 = new wxStaticText( m_RICpanel, wxID_ANY, _("F12"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer152->Add(m_labF12, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT, 5);

    m_F12 = new wxTextCtrl( m_RICpanel, wxID_ANY, _("-1"), wxDefaultPosition, wxSize(40, -1), 0 );
    itemFlexGridSizer152->Add(m_F12, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxStaticBox* itemStaticBoxSizer179Static = new wxStaticBox(m_RICpanel, wxID_ANY, _("Power"));
    m_PowerBox = new wxStaticBoxSizer(itemStaticBoxSizer179Static, wxVERTICAL);
    itemBoxSizer137->Add(m_PowerBox, 0, wxALIGN_LEFT|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer180 = new wxFlexGridSizer(0, 4, 0, 0);
    m_PowerBox->Add(itemFlexGridSizer180, 0, wxGROW, 5);
    m_labPowerOn = new wxStaticText( m_RICpanel, wxID_ANY, _("on"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer180->Add(m_labPowerOn, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT, 5);

    m_PowerOn = new wxTextCtrl( m_RICpanel, wxID_ANY, _("8"), wxDefaultPosition, wxSize(40, -1), wxTE_CENTRE );
    itemFlexGridSizer180->Add(m_PowerOn, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labPowerOff = new wxStaticText( m_RICpanel, wxID_ANY, _("off"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer180->Add(m_labPowerOff, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT, 5);

    m_PowerOff = new wxTextCtrl( m_RICpanel, wxID_ANY, _("7"), wxDefaultPosition, wxSize(40, -1), wxTE_CENTRE );
    itemFlexGridSizer180->Add(m_PowerOff, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Notebook->AddPage(m_RICpanel, _("RIC"));

    m_MICpanel = new wxPanel( m_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer186 = new wxBoxSizer(wxVERTICAL);
    m_MICpanel->SetSizer(itemBoxSizer186);

    wxFlexGridSizer* itemFlexGridSizer187 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer186->Add(itemFlexGridSizer187, 0, wxGROW|wxALL, 5);
    m_labMICStep = new wxStaticText( m_MICpanel, wxID_ANY, _("step"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer187->Add(m_labMICStep, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_MICStep = new wxSpinCtrl( m_MICpanel, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 1, 9, 1 );
    itemFlexGridSizer187->Add(m_MICStep, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_MICStopOnExit = new wxCheckBox( m_MICpanel, wxID_ANY, _("stop on exit"), wxDefaultPosition, wxDefaultSize, 0 );
    m_MICStopOnExit->SetValue(true);
    itemBoxSizer186->Add(m_MICStopOnExit, 0, wxALIGN_LEFT|wxALL, 5);

    m_Notebook->AddPage(m_MICpanel, _("MIC"));

    m_AcceleratorPanel = new wxPanel( m_Notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer192 = new wxBoxSizer(wxVERTICAL);
    m_AcceleratorPanel->SetSizer(itemBoxSizer192);

    wxFlexGridSizer* itemFlexGridSizer193 = new wxFlexGridSizer(0, 3, 0, 0);
    itemBoxSizer192->Add(itemFlexGridSizer193, 0, wxALIGN_LEFT, 5);
    m_labAccelFunction = new wxStaticText( m_AcceleratorPanel, wxID_ANY, _("Function"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer193->Add(m_labAccelFunction, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labAccelKeyCode = new wxStaticText( m_AcceleratorPanel, wxID_ANY, _("Key code"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer193->Add(m_labAccelKeyCode, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labAccelModifier = new wxStaticText( m_AcceleratorPanel, wxID_ANY, _("Modifier"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer193->Add(m_labAccelModifier, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labEmergencyBreak = new wxStaticText( m_AcceleratorPanel, wxID_ANY, _("Emergencybreak"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer193->Add(m_labEmergencyBreak, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_EmergencyBreakListStrings;
    m_EmergencyBreakList = new wxComboBox( m_AcceleratorPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_EmergencyBreakListStrings, wxCB_READONLY );
    itemFlexGridSizer193->Add(m_EmergencyBreakList, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_EmergencyBreakModifierStrings;
    m_EmergencyBreakModifierStrings.Add(_("&Normal"));
    m_EmergencyBreakModifierStrings.Add(_("&Alt"));
    m_EmergencyBreakModifierStrings.Add(_("&Ctrl"));
    m_EmergencyBreakModifier = new wxRadioBox( m_AcceleratorPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_EmergencyBreakModifierStrings, 1, wxRA_SPECIFY_ROWS );
    m_EmergencyBreakModifier->SetSelection(0);
    itemFlexGridSizer193->Add(m_EmergencyBreakModifier, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Notebook->AddPage(m_AcceleratorPanel, _("Accelerators"));

    itemBoxSizer2->Add(m_Notebook, 1, wxGROW|wxALL, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer200 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer200, 0, wxGROW|wxALL, 5);
    m_OK = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    m_OK->SetDefault();
    itemStdDialogButtonSizer200->AddButton(m_OK);

    m_Cancel = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer200->AddButton(m_Cancel);

    m_Help = new wxButton( itemDialog1, wxID_HELP, _("&Help"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer200->AddButton(m_Help);

    itemStdDialogButtonSizer200->Realize();

////@end RocguiIniDialog content construction
}

/*!
 * Should we show tooltips?
 */

bool RocguiIniDialog::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap RocguiIniDialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin RocguiIniDialog bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end RocguiIniDialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon RocguiIniDialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin RocguiIniDialog icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end RocguiIniDialog icon retrieval
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void RocguiIniDialog::OnOKClick( wxCommandEvent& event )
{
  evaluate();
  EndModal( wxID_OK );
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void RocguiIniDialog::OnCANCELClick( wxCommandEvent& event )
{
  EndModal( 0 );
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_ANY
 */

void RocguiIniDialog::OnSvgPath2Click( wxCommandEvent& event )
{
  wxDirDialog* dlg = new wxDirDialog( this );
  dlg->SetPath(m_SVGPath2->GetValue());
  if( dlg->ShowModal() == wxID_OK ) {
    m_SVGPath2->SetValue( dlg->GetPath() );
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_IMAGEPATH_BUTTON
 */

void RocguiIniDialog::OnUpdatespathButtonClick( wxCommandEvent& event )
{
  wxDirDialog* dlg = new wxDirDialog( this );
  dlg->SetPath(m_UpdatesPath->GetValue());
  if( dlg->ShowModal() == wxID_OK ) {
    m_UpdatesPath->SetValue( dlg->GetPath() );
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_IMAGEPATH_BUTTON
 */

void RocguiIniDialog::OnImagepathButtonClick( wxCommandEvent& event )
{
  wxDirDialog* dlg = new wxDirDialog( this );
  dlg->SetPath(m_ImagePath->GetValue());
  if( dlg->ShowModal() == wxID_OK ) {
    m_ImagePath->SetValue( dlg->GetPath() );
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SVGPATH_BUTTON
 */

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SVGPATH_BUTTON
 */

void RocguiIniDialog::OnSvgPath5Click( wxCommandEvent& event )
{
  wxDirDialog* dlg = new wxDirDialog( this );
  dlg->SetPath(m_SVGPath5->GetValue());
  if( dlg->ShowModal() == wxID_OK ) {
    m_SVGPath5->SetValue( dlg->GetPath() );
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_XSLPATH_BUTTON
 */

void RocguiIniDialog::OnXslpathButtonClick( wxCommandEvent& event )
{
  wxDirDialog* dlg = new wxDirDialog( this );
  dlg->SetPath(m_XSLPath->GetValue());
  if( dlg->ShowModal() == wxID_OK ) {
    m_XSLPath->SetValue( dlg->GetPath() );
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SVGPATH3_BUTTON
 */

void RocguiIniDialog::OnSvgPath4Click( wxCommandEvent& event )
{
  wxDirDialog* dlg = new wxDirDialog( this );
  dlg->SetPath(m_SVGPath4->GetValue());
  if( dlg->ShowModal() == wxID_OK ) {
    m_SVGPath4->SetValue( dlg->GetPath() );
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SVGPATH_BUTTON
 */

void RocguiIniDialog::OnSvgPath1Click( wxCommandEvent& event )
{
  wxDirDialog* dlg = new wxDirDialog( this );
  dlg->SetPath(m_SVGPath->GetValue());
  if( dlg->ShowModal() == wxID_OK ) {
    m_SVGPath->SetValue( dlg->GetPath() );
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SVGPATH3_BUTTON
 */

void RocguiIniDialog::OnSvgPath3Click( wxCommandEvent& event )
{
  wxDirDialog* dlg = new wxDirDialog( this );
  dlg->SetPath(m_SVGPath3->GetValue());
  if( dlg->ShowModal() == wxID_OK ) {
    m_SVGPath3->SetValue( dlg->GetPath() );
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
 */

void RocguiIniDialog::OnWorkspaceClick( wxCommandEvent& event )
{
  wxDirDialog* dlg = new wxDirDialog( this );
  dlg->SetPath(m_Workspace->GetValue());
  if( dlg->ShowModal() == wxID_OK ) {
    m_Workspace->SetValue( dlg->GetPath() );
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DECPATH_BUTTON
 */

void RocguiIniDialog::OnDecpathButtonClick( wxCommandEvent& event )
{
  wxDirDialog* dlg = new wxDirDialog( this );
  dlg->SetPath(m_DecPath->GetValue());
  if( dlg->ShowModal() == wxID_OK ) {
    m_DecPath->SetValue( dlg->GetPath() );
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
 */

void RocguiIniDialog::OnHelpClick( wxCommandEvent& event )
{
  switch( m_Notebook->GetSelection() ) {
  case 0: wxGetApp().openLink( "rocgui-gen" ); break;
  case 1: wxGetApp().openLink( "rocgui-trace" ); break;
  case 2: wxGetApp().openLink( "rocgui-pt" ); break;
  case 3: wxGetApp().openLink( "symbols" ); break;
  case 4: wxGetApp().openLink( "rocgui-gamepad" ); break;
  case 5: wxGetApp().openLink( "mic" ); break;
  default: wxGetApp().openLink( "rocgui-gen" ); break;
  }
}

