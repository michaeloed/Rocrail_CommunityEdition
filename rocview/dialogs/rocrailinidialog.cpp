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
#pragma implementation "rocrailinidialog.h"
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

#include "rocrailinidialog.h"
#include "rocview/dialogs/controllers/gendlg.h"
#include "rocview/dialogs/controllers/ddxdlg.h"
#include "rocview/dialogs/controllers/hsi88dlg.h"
#include "rocview/dialogs/controllers/barjutdlg.h"
#include "rocview/dialogs/controllers/dinamodlg.h"
#include "rocview/dialogs/controllers/srcpdlg.h"
#include "rocview/dialogs/controllers/loconetdlg.h"
#include "rocview/dialogs/controllers/ecosdlg.h"
#include "rocview/dialogs/controllers/opendcc.h"
#include "rocview/dialogs/controllers/lenzdlg.h"
#include "rocview/dialogs/controllers/dcc232dlg.h"
#include "rocview/dialogs/controllers/bidibdlg.h"
#include "rocview/dialogs/controllers/rocnetdlg.h"
#include "rocview/dialogs/controllers/cbusdlg.h"
#include "rocview/dialogs/controllers/ucons88dlg.h"
#include "rocview/dialogs/controllers/spldlg.h"
#include "rocview/dialogs/controllers/dmxdlg.h"

#include "rocrail/wrapper/public/FreeRail.h"
#include "rocrail/wrapper/public/Plan.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Clock.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/Trace.h"
#include "rocrail/wrapper/public/HttpService.h"
#include "rocrail/wrapper/public/WebClient.h"
#include "rocrail/wrapper/public/DigInt.h"
#include "rocrail/wrapper/public/Tcp.h"
#include "rocrail/wrapper/public/SrcpCon.h"
#include "rocrail/wrapper/public/Ctrl.h"
#include "rocrail/wrapper/public/SysCmd.h"
#include "rocrail/wrapper/public/Program.h"
#include "rocrail/wrapper/public/R2RnetIni.h"
#include "rocrail/wrapper/public/SnmpService.h"
#include "rocrail/wrapper/public/Devices.h"
#include "rocrail/wrapper/public/AnaOpt.h"

#include "rocview/wrapper/public/Gui.h"

#include "rocview/public/guiapp.h"
#include "rocs/public/strtok.h"

////@begin XPM images
////@end XPM images

/*!
 * RocrailIniDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( RocrailIniDialog, wxDialog )

/*!
 * RocrailIniDialog event table definition
 */

BEGIN_EVENT_TABLE( RocrailIniDialog, wxDialog )

////@begin RocrailIniDialog event table entries
    EVT_NOTEBOOK_PAGE_CHANGED( ID_NOTEBOOK_RR, RocrailIniDialog::OnNotebookRrPageChanged )
    EVT_BUTTON( ID_BUTTON_PLANFILE, RocrailIniDialog::OnButtonPlanfileClick )
    EVT_BUTTON( ID_BUTTON_OCCFILE, RocrailIniDialog::OnButtonOccfileClick )
    EVT_BUTTON( ID_BUTTON_LOCOFILE, RocrailIniDialog::OnButtonLocofileClick )
    EVT_BUTTON( ID_BUTTON_KEYPATH, RocrailIniDialog::OnButtonKeypathClick )
    EVT_LISTBOX( ID_LISTBOX_RR_CONTROLLERS, RocrailIniDialog::OnListboxRrControllersSelected )
    EVT_LISTBOX_DCLICK( ID_LISTBOX_RR_CONTROLLERS, RocrailIniDialog::OnListboxRrControllersDoubleClicked )
    EVT_BUTTON( ID_BUTTON_RR_DELETE, RocrailIniDialog::OnButtonRrDeleteClick )
    EVT_BUTTON( ID_BUTTON_RR_PROPS, RocrailIniDialog::OnButtonRrPropsClick )
    EVT_BUTTON( ID_BUTTON_RR_DEFAULT, RocrailIniDialog::OnButtonRrDefaultClick )
    EVT_BUTTON( ID_BUTTON_RR_ADD, RocrailIniDialog::OnButtonRrAddClick )
    EVT_BUTTON( ID_BUTTON_R2RNET_ROUTES, RocrailIniDialog::OnButtonR2rnetRoutesClick )
    EVT_BUTTON( ID_ROCWEB_WEB_BUTTON, RocrailIniDialog::OnRocwebWebButtonClick )
    EVT_BUTTON( ID_ROCWEB_SVGPATH_BUTTON, RocrailIniDialog::OnSvgPath1Click )
    EVT_BUTTON( ID_ROCWEB_SVGPATH2_BUTTON, RocrailIniDialog::OnSvgPath2Click )
    EVT_BUTTON( ID_ROCWEB_SVGPATH3_BUTTON, RocrailIniDialog::OnSvgPath3Click )
    EVT_BUTTON( ID_ROCWEB_SVGPATH4_BUTTON, RocrailIniDialog::OnSvgPath4Click )
    EVT_BUTTON( ID_ROCWEB_SVGPATH5_BUTTON, RocrailIniDialog::OnSvgPath5Click )
    EVT_BUTTON( wxID_OK, RocrailIniDialog::OnOkClick )
    EVT_BUTTON( wxID_CANCEL, RocrailIniDialog::OnCancelClick )
    EVT_BUTTON( wxID_HELP, RocrailIniDialog::OnHelpClick )
////@end RocrailIniDialog event table entries

END_EVENT_TABLE()

/*!
 * RocrailIniDialog constructors
 */

RocrailIniDialog::RocrailIniDialog( )
{
}

RocrailIniDialog::RocrailIniDialog( wxWindow* parent, iONode props )
{
  m_TabAlign = wxGetApp().getTabAlign();
  Create(parent, -1, wxGetApp().getMsg( "rocrailini" ) );
  m_Props = props;
  m_CSDialog = NULL;
  initLabels();
  initValues();

  m_GeneralPanel->GetSizer()->Layout();
  m_TracePanel->GetSizer()->Layout();
  m_ServicePanel->GetSizer()->Layout();
  m_AtomatPanel->GetSizer()->Layout();
  m_ControllersPanel->GetSizer()->Layout();
  m_AnalyserPanel->GetSizer()->Layout();

  m_PlanType->Fit();

  m_RRNotebook->Fit();

  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);
}

/* comparator for sorting by id: */
static int __sortStr(obj* _a, obj* _b)
{
    const char* a = (const char*)*_a;
    const char* b = (const char*)*_b;
    return strcmp( a, b );
}

void RocrailIniDialog::initLabels() {
  m_RRNotebook->SetPageText( 0, wxGetApp().getMsg( "general" ) );
  m_RRNotebook->SetPageText( 1, wxGetApp().getMsg( "trace" ) );
  m_RRNotebook->SetPageText( 2, wxGetApp().getMsg( "service" ) );
  m_RRNotebook->SetPageText( 3, wxGetApp().getMsg( "auto" ) );
  m_RRNotebook->SetPageText( 4, wxGetApp().getMsg( "controller" ) );
  // 5 is R2RNet
  m_RRNotebook->SetPageText( 6, wxGetApp().getMsg( "analyser" ) );

  // General
  m_LabelPlanfile->SetLabel( wxGetApp().getMsg( "planfile" ) );
  m_labOccFile->SetLabel( wxGetApp().getMsg( "blockoccupancy" ) );
  m_labLocoFile->SetLabel( wxGetApp().getMsg( "loctable" ) );
  m_labPlanType->SetLabel( wxGetApp().getMsg( "type" ) );
  m_Backup->SetLabel( wxGetApp().getMsg( "backup" ) );
  m_labKeyPath->SetLabel( wxGetApp().getMsg( "keypath" ) );
  m_LabelLibPath->SetLabel( wxGetApp().getMsg( "libpath" ) );
  m_labImgPath->SetLabel( wxGetApp().getMsg( "imagepath" ) );
  m_labIconPath->SetLabel( wxGetApp().getMsg( "iconpath" ) );
  m_labIssuesPath->SetLabel( wxGetApp().getMsg( "issuepath" ) );
  m_labSoundPath->SetLabel( wxGetApp().getMsg( "soundpath" ) );
  m_labSoundPlayer->SetLabel( wxGetApp().getMsg( "soundplayer" ) );
  m_SoundPlayerLocation->SetLabel( wxGetApp().getMsg( "soundplayerlocation" ) );
  m_labProtPath->SetLabel( wxGetApp().getMsg( "path" ) );
  m_LabelTraceFile->SetLabel( wxGetApp().getMsg( "tracefile" ) );
  m_labPTIID->SetLabel( wxGetApp().getMsg( "ptiid" ) );
  m_PTIID->SetToolTip( wxGetApp().getTip( "ptiid" ) );
  m_labLCIID->SetLabel( wxGetApp().getMsg( "lciid" ) );
  m_LCIID->SetToolTip( wxGetApp().getTip( "lciid" ) );
  m_labDPIID->SetLabel( wxGetApp().getMsg( "dpiid" ) );
  m_DPIID->SetToolTip( wxGetApp().getTip( "dpiid" ) );
  m_labSVIID->SetLabel( wxGetApp().getMsg( "sviid" ) );
  m_SVIID->SetToolTip( wxGetApp().getTip( "sviid" ) );
  m_labScSensor->SetLabel( wxGetApp().getMsg( "sensor" ) );
  m_ScBox->SetLabel( wxGetApp().getMsg( "shortcut" ) );


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
        m_ScSensor->Append( wxString(id,wxConvUTF8) );
      }
    }
  }
  /* clean up the temp. list */
  ListOp.base.del(list);



  m_PlanType->SetString( 0, wxGetApp().getMsg( "default" ) );
  m_PlanType->SetString( 1, wxGetApp().getMsg( "modpanel" ) );


  // Trace
  m_TraceLevel->GetStaticBox()->SetLabel( _T("User ") + wxGetApp().getMsg( "tracelevel" ) );
  m_DevTraceLevel->SetLabel( _T("Developer ") + wxGetApp().getMsg( "tracelevel" ) );
  m_Debug->SetLabel( wxGetApp().getMsg( "debug" ) );
  m_Info->SetLabel( wxGetApp().getMsg( "info" ) );
  m_Auto->SetLabel( wxGetApp().getMsg( "auto" ) );
  m_Byte->SetLabel( wxGetApp().getMsg( "byte" ) );
  m_SendAllTraces->SetLabel( wxGetApp().getMsg( "sendalltraces" ) );
  //m_Parse->SetLabel( wxGetApp().getMsg( "parse" ) );
  m_Calc->SetLabel( wxGetApp().getMsg( "calc" ) );
  m_labNrTraceFiles->SetLabel( wxGetApp().getMsg( "nrtracefiles" ) );
  m_labTraceFileSize->SetLabel( wxGetApp().getMsg( "tracefilesize" ) );

  // Service
  m_LabelClientPort->SetLabel( wxGetApp().getMsg( "clientport" ) );
  m_LabelMaxCon->SetLabel( wxGetApp().getMsg( "maxclientcon" ) );
  m_labControlCode->SetLabel( wxGetApp().getMsg( "controlcode" ) );
  m_labSlaveCode->SetLabel( wxGetApp().getMsg( "slavecode" ) );
  m_HttpBox->GetStaticBox()->SetLabel( wxGetApp().getMsg( "http" ) );
  m_LabelHttpPort->SetLabel( wxGetApp().getMsg( "port" ) );
  m_LabServiceRefresh->SetLabel( wxGetApp().getMsg( "refresh" ) );
  m_OnlyFirstMaster->SetLabel( wxGetApp().getMsg( "onlyfirstmaster" ) );
  m_labSrcpPort->SetLabel( wxGetApp().getMsg( "port" ) );
  m_SrcpServiceActive->SetLabel( wxGetApp().getMsg( "enable" ) );
  m_labSnmpPort->SetLabel( wxGetApp().getMsg( "port" ) );
  m_SnmpServiceActive->SetLabel( wxGetApp().getMsg( "enable" ) );
  m_labSnmpTrapHost->SetLabel( wxGetApp().getMsg( "host" ) );
  m_labSnmpTrapPort->SetLabel( wxGetApp().getMsg( "port" ) );
  m_labSRCPDevice->SetLabel( wxGetApp().getMsg( "device" ) );
  m_labDevider->SetLabel( wxGetApp().getMsg( "divider" ) );
  m_labHour->SetLabel( wxGetApp().getMsg( "hour" ) );
  m_labMinute->SetLabel( wxGetApp().getMsg( "minute" ) );
  m_StopClockAtPowerOff->SetLabel( wxGetApp().getMsg( "stopclockatpoweroff" ) );
  m_SrcpService->SetLabel( wxT("SRCP") );
  m_SNMPBox->SetLabel( wxGetApp().getMsg( "snmp" ) );

  // WebService
  m_WebServiceBox->GetStaticBox()->SetLabel( wxGetApp().getMsg( "webclient" ) );
  m_LabWebServicePort->SetLabel( wxGetApp().getMsg( "port" ) );
  m_labWebPath->SetLabel( wxGetApp().getMsg( "path" ) );

  // Automat
  m_LabelSwTime->SetLabel( wxGetApp().getMsg( "switchtime" ) );
  m_LabelMinBKLen->SetLabel( wxGetApp().getMsg( "minblocklen" ) );
  m_LabelIgnEvt->SetLabel( wxGetApp().getMsg( "ignevent" ) );
  m_labInitPause->SetLabel( wxGetApp().getMsg( "initfieldpause" ) );
  m_labInitPower->SetLabel( wxGetApp().getMsg( "initfieldpower" ) );
  m_labSeed->SetLabel( wxGetApp().getMsg( "randomseed" ) );
  m_labSavePosTime->SetLabel( wxGetApp().getMsg( "savepostime" ) );
  m_secondNextBlock->SetLabel( wxGetApp().getMsg( "secondnextblock" ) );
  m_EnableSwFb->SetLabel( wxGetApp().getMsg( "enableswfb" ) );
  m_labEventTimeout->SetLabel( wxGetApp().getMsg( "eventtimeout" ) );
  m_labSignalReset->SetLabel( wxGetApp().getMsg( "signalreset" ) );
  m_labRouteSwTime->SetLabel( wxGetApp().getMsg( "routeswtime" ) );
  m_DisableRouteVreduce->SetLabel( wxGetApp().getMsg( "disablerouteVreduce" ) );
  m_DefAspect->SetLabel( wxGetApp().getMsg( "defaspect" ) );
  m_DefAspect->SetString( 0, wxGetApp().getMsg( "red" ) );
  m_DefAspect->SetString( 1, wxGetApp().getMsg( "green" ) );
  m_DefAspect->SetString( 2, wxGetApp().getMsg( "yellow" ) );
  m_DefAspect->SetString( 3, wxGetApp().getMsg( "white" ) );
  m_GreenAspect->SetLabel( wxGetApp().getMsg( "greenaspect" ) );
  m_SkipSetSw->SetLabel( wxGetApp().getMsg( "skipsetsw" ) );
  m_SkipSetSg->SetLabel(wxGetApp().getMsg( "skipsetsg" ));
  m_SkipSetSg->SetToolTip(wxGetApp().getTip( "skipsetsg" ));
  m_UseBiCom->SetLabel( wxGetApp().getMsg( "usebicom" ) );
  m_UseIdent->SetLabel( wxGetApp().getMsg( "useident" ) );
  m_labSemaphoreWait->SetLabel( wxGetApp().getMsg( "semaphorewait" ) );
  m_labSignalWait->SetLabel( wxGetApp().getMsg( "signalwait" ) );
  m_StopAtIdentMisMatch->SetLabel( wxGetApp().getMsg( "stopatidentmismatch" ) );
  m_PowerOffAtGhost->SetLabel( wxGetApp().getMsg( "poweroffatghost" ) );
  m_EBreakAtGhost->SetLabel( wxGetApp().getMsg( "ebreakatghost" ) );
  m_KeepGhost->SetLabel( wxGetApp().getMsg( "keepghost" ) );
  m_labLocoStartGap->SetLabel( wxGetApp().getMsg( "locostartgap" ) );
  m_DisableSteal->SetLabel( wxGetApp().getMsg( "disablesteal" ) );
  m_labBlockInitPause->SetLabel( wxGetApp().getMsg( "blockinitpause" ) );
  m_PowerOffAtReset->SetLabel( wxGetApp().getMsg( "poweroffatreset" ) );
  m_ZeroThrottleID->SetLabel( wxGetApp().getMsg( "allowzerothrottleid" ) );
  m_StopNoneCommuter->SetLabel( wxGetApp().getMsg( "stopnonecommuter" ) );
  m_SyncRoutes->SetLabel( wxGetApp().getMsg( "syncroutes" ) );
  m_labSyncRouteTimeout->SetLabel( wxGetApp().getMsg( "syncroutetimeout" ) );
  m_TimedSensors->SetLabel( wxGetApp().getMsg( "timedsensors" ) );
  m_EnableAnalyzer->SetLabel( wxGetApp().getMsg( "enableanalyzer" ) );
  m_ForceUnlock->SetLabel( wxGetApp().getMsg( "forceunlockatebreak" ) );
  m_ResetFxSp->SetLabel( wxGetApp().getMsg( "resetspfx" ) );
  m_ProcessSignalEvents->SetLabel( wxGetApp().getMsg( "processsignalevents" ) );
  m_ReleaseOnIdle->SetLabel( wxGetApp().getMsg( "releaseonidle" ) );
  m_CloseOnGhost->SetLabel( wxGetApp().getMsg( "closeonghost" ) );
  m_CloseNoEvents->SetLabel( wxGetApp().getMsg( "closenoevents" ) );
  m_SelectShortestBlock->SetLabel( wxGetApp().getMsg( "selectshortestblock" ) );
  m_RestoreSchedule->SetLabel( wxGetApp().getMsg( "restoreschedule" ) );
  m_ActionTimer60->SetLabel( wxGetApp().getMsg( "actiontimer60" ) );
  m_CreateGuestOnBiDi->SetLabel( wxGetApp().getMsg( "createguestonbidi" ) );
  m_UseBiDiDirection->SetLabel( wxGetApp().getMsg( "usebididir" ) );
  m_DisableBlockWait4GoManual->SetLabel( wxGetApp().getMsg( "disableblockwait4gomanual" ) );
  m_StopAtIn4GoManual->SetLabel( wxGetApp().getMsg( "stopatin4gomanual" ) );
  m_V0AtPowerOn->SetLabel( wxGetApp().getMsg( "v0atpoweron" ) );
  m_UseOnlyFirstIdent->SetLabel( wxGetApp().getMsg( "useonlyfirstident" ) );
  m_labVirtualTimer->SetLabel( wxGetApp().getMsg( "virtualtimer" ) );
  m_UseRandomRate->SetLabel( wxGetApp().getMsg( "userandomrate" ) );
  m_RedirectToMaster->SetLabel( wxGetApp().getMsg( "redirecttomaster" ) );
  m_Weather->SetLabel( wxGetApp().getMsg( "weather" ) );
  m_V0OnEbreak->SetLabel( wxGetApp().getMsg( "v0onebreak" ) );

  // Controller
  m_ControllerDelete->SetLabel( wxGetApp().getMsg( "delete" ) );
  m_ControllerProps->SetLabel( wxGetApp().getMsg( "properties" ) );
  m_ControllerAdd->SetLabel( wxGetApp().getMsg( "add" ) );
  m_AddControllerBox->GetStaticBox()->SetLabel( wxGetApp().getMsg( "new" ) );
  m_PowerOffOnExit->SetLabel( wxGetApp().getMsg( "poweroffonexit" ) );
  m_PowerOnAtInit->SetLabel( wxGetApp().getMsg( "poweronstartup" ) );
  m_Shutdown->SetLabel( wxGetApp().getMsg( "shutdownonexit" ) );
  m_NoDevCheck->SetLabel( wxGetApp().getMsg( "nodevcheck" ) );
  m_Default->SetLabel( wxGetApp().getMsg( "default" ) );


  // R2Rnet
  m_labR2RnetID->SetLabel( wxGetApp().getMsg( "id" ) );
  m_labR2RnetAddr->SetLabel( wxGetApp().getMsg( "address" ) );
  m_labR2RnetPort->SetLabel( wxGetApp().getMsg( "port" ) );
  m_labR2RnetRoutes->SetLabel( wxGetApp().getMsg( "netroutes" ) );
  m_R2RnetEnable->SetLabel( wxGetApp().getMsg( "enable" ) );

  // Analyser
  m_AnaGenerate->SetLabel( wxGetApp().getMsg( "analyze" ) );
  m_AnaClean->SetLabel( wxGetApp().getMsg( "ana_clean" ) );
  m_AnaCheck->SetLabel( wxGetApp().getMsg( "extendedcheck" ) );
  m_AnaReset->SetLabel( wxGetApp().getMsg( "extendedclean" ) );

  m_SetRouteId->SetLabel( wxGetApp().getMsg( "ana_setRouteId" ) );
  m_CleanRouteId->SetLabel( wxGetApp().getMsg( "ana_cleanRouteId" ) );
  m_SetBlockId->SetLabel( wxGetApp().getMsg( "ana_setBlockId" ) );
  m_ResetBlockId->SetLabel( wxGetApp().getMsg( "ana_resetBlockId" ) );
  m_AddSignalBlockAssignment->SetLabel( wxGetApp().getMsg( "ana_addSignalBlockAssignment" ) );
  m_ResetSignalBlockAssignment->SetLabel( wxGetApp().getMsg( "ana_resetSignalBlockAssignment" ) );
  m_AddFeedbackBlockAssignment->SetLabel( wxGetApp().getMsg( "ana_addFeedbackBlockAssignment" ) );
  m_ResetFeedbackBlockAssignment->SetLabel( wxGetApp().getMsg( "ana_resetFeedbackBlockAssignment" ) );
  m_BasicCheck->SetLabel( wxGetApp().getMsg( "ana_basicCheck" ) );
  m_BasicClean->SetLabel( wxGetApp().getMsg( "ana_basicClean" ) );
  m_BlockCheck->SetLabel( wxGetApp().getMsg( "ana_blockCheck" ) );
  m_BlockClean->SetLabel( wxGetApp().getMsg( "ana_blockClean" ) );
  m_RouteCheck->SetLabel( wxGetApp().getMsg( "ana_routeCheck" ) );
  m_RouteClean->SetLabel( wxGetApp().getMsg( "ana_routeClean" ) );
  m_ActionCheck->SetLabel( wxGetApp().getMsg( "ana_actionCheck" ) );
  m_ActionClean->SetLabel( wxGetApp().getMsg( "ana_actionClean" ) );

  // Buttons
  m_OK->SetLabel( wxGetApp().getMsg( "ok" ) );
  m_Cancel->SetLabel( wxGetApp().getMsg( "cancel" ) );
}


void RocrailIniDialog::initValues() {
  // General
  m_PlanFile->SetValue( wxString(wFreeRail.getplanfile( m_Props ),wxConvUTF8) );
  m_OccFile->SetValue( wxString( wFreeRail.getoccupancy( m_Props ),wxConvUTF8 ) );
  m_LocoFile->SetValue( wxString( wFreeRail.getlocs( m_Props ),wxConvUTF8 ) );
  m_Backup->SetValue( wFreeRail.isbackup( m_Props )?true:false );
  m_BackupPath->SetValue( wxString(wFreeRail.getbackuppath( m_Props ),wxConvUTF8) );
  m_KeyPath->SetValue( wxString(wFreeRail.getkeypath( m_Props ),wxConvUTF8) );
  m_LibPath->SetValue( wxString(wFreeRail.getlibpath( m_Props ),wxConvUTF8) );
  m_ImgPath->SetValue( wxString(wFreeRail.getimgpath( m_Props ),wxConvUTF8) );
  m_IconPath->SetValue( wxString(wFreeRail.geticonpath( m_Props ),wxConvUTF8) );
  m_IssuePath->SetValue( wxString(wFreeRail.getissuepath( m_Props ),wxConvUTF8) );
  m_SoundPath->SetValue( wxString(wFreeRail.getsoundpath( m_Props ),wxConvUTF8) );
  m_SoundPlayer->SetValue( wxString(wFreeRail.getsoundplayer( m_Props ),wxConvUTF8) );
  m_SoundPlayerLocation->SetValue( wFreeRail.issoundplayerlocation( m_Props ) );
  iONode trace = wFreeRail.gettrace( m_Props );
  if( trace == NULL ) {
    trace = NodeOp.inst( wTrace.name(), m_Props, ELEMENT_NODE );
    NodeOp.addChild( m_Props, trace );
  }
  m_TraceFile->SetValue( wxString(wTrace.getrfile( trace ),wxConvUTF8) );
  m_ProtPath->SetValue( wxString(wTrace.getprotpath( trace ),wxConvUTF8) );
  m_NrTraceFiles->SetValue( wTrace.getnr( trace ) );
  m_TraceFileSize->SetValue( wTrace.getsize( trace ) );
  m_PTIID->SetValue( wxString(wFreeRail.getptiid( m_Props ),wxConvUTF8) );
  m_LCIID->SetValue( wxString(wFreeRail.getlciid( m_Props ),wxConvUTF8) );
  m_DPIID->SetValue( wxString(wFreeRail.getdpiid( m_Props ),wxConvUTF8) );
  m_SVIID->SetValue( wxString(wFreeRail.getsviid( m_Props ),wxConvUTF8) );

  m_FSUTF8->SetValue( wFreeRail.isfsutf8( m_Props )?true:false );

  if( wFreeRail.getscsensor( m_Props ) != NULL && StrOp.len( wFreeRail.getscsensor( m_Props ) ) > 0 )
      m_ScSensor->SetStringSelection( wxString(wFreeRail.getscsensor( m_Props ),wxConvUTF8) );
  else
    m_ScSensor->SetStringSelection( wxString("-",wxConvUTF8) );

  m_ScIID->SetValue( wxString(wFreeRail.getsciid( m_Props ),wxConvUTF8) );

  m_PlanType->SetSelection( wFreeRail.iscreatemodplan( m_Props ) ? 1:0 );

  // Service
  iONode tcp = wFreeRail.gettcp( m_Props );
  if( tcp == NULL ) {
    tcp = NodeOp.inst( wTcp.name(), m_Props, ELEMENT_NODE );
    NodeOp.addChild( m_Props, tcp );
  }
  char* val = StrOp.fmt( "%d", wTcp.getport( tcp ) );
  m_ClientPort->SetValue( wxString( val,wxConvUTF8) );
  StrOp.free( val );
  val = StrOp.fmt( "%d", wTcp.getmaxcon( tcp ) );
  m_MaxCon->SetValue( wxString( val,wxConvUTF8) );
  StrOp.free( val );
  m_ControlCode->SetValue( wxString( wTcp.getcontrolcode(tcp),wxConvUTF8) );
  m_SlaveCode->SetValue( wxString( wTcp.getslavecode(tcp),wxConvUTF8) );

  m_OnlyFirstMaster->SetValue( wTcp.isonlyfirstmaster( tcp ) ? true:false );

  iONode srcpcon = wFreeRail.getsrcpcon( m_Props );
  if( srcpcon == NULL ) {
    srcpcon = NodeOp.inst( wSrcpCon.name(), m_Props, ELEMENT_NODE );
    NodeOp.addChild( m_Props, srcpcon );
  }
  m_SrcpPort->SetValue(wSrcpCon.getport(srcpcon));
  m_SrcpServiceActive->SetValue(wSrcpCon.isactive(srcpcon)?true:false);
  m_SRCPDevice->SetValue( wxString( wSrcpCon.getdevice( srcpcon ), wxConvUTF8 ) );
  const char* devices = NULL;
  if( wFreeRail.getdevices(m_Props) != NULL ) {
    devices = wDevices.getserial(wFreeRail.getdevices(m_Props));
  }
  if( devices != NULL ) {
    iOStrTok tok = StrTokOp.inst(devices, ',');
    while( StrTokOp.hasMoreTokens(tok) ) {
      m_SRCPDevice->Append( wxString( StrTokOp.nextToken(tok), wxConvUTF8 ) );
    }
    StrTokOp.base.del(tok);
  }


  iONode snmp = wFreeRail.getSnmpService( m_Props );
  if( snmp == NULL ) {
    snmp = NodeOp.inst( wSnmpService.name(), m_Props, ELEMENT_NODE );
    NodeOp.addChild( m_Props, snmp );
  }
  m_SnmpPort->SetValue(wSnmpService.getport(snmp));
  m_SnmpServiceActive->SetValue(wSnmpService.isactive(snmp)?true:false);
  m_SnmpTrapHost->SetValue( wxString( wSnmpService.gettraphost(snmp), wxConvUTF8) );
  m_SnmpTrapPort->SetValue(wSnmpService.gettrapport(snmp));


  iONode http = wFreeRail.gethttp( m_Props );
  if( http == NULL ) {
    val = StrOp.fmt( "%d", 0 );
    m_HttpPort->SetValue( wxString( val,wxConvUTF8) );
    StrOp.free( val );
    val = StrOp.fmt( "%d", 0 );
    m_ServiceRefresh->SetValue( wxString( val,wxConvUTF8) );
    StrOp.free( val );
  }
  else {
    val = StrOp.fmt( "%d", wHttpService.getport( http ) );
    m_HttpPort->SetValue( wxString( val,wxConvUTF8) );
    StrOp.free( val );
    val = StrOp.fmt( "%d", wHttpService.getrefresh( http ) );
    m_ServiceRefresh->SetValue( wxString( val,wxConvUTF8) );
    StrOp.free( val );

    iONode web = wHttpService.getwebclient( http );
    if( web != NULL ) {
      m_WebServicePort->SetValue( wWebClient.getport( web ) );

      // RocWeb
      m_WebPath->SetValue( wxString(wWebClient.getwebpath( web ),wxConvUTF8) );
      m_SVGPath->SetValue( wxString(wWebClient.getsvgpath1( web ),wxConvUTF8) );
      m_SVGPath2->SetValue( wxString(wWebClient.getsvgpath2( web ),wxConvUTF8) );
      m_SVGPath3->SetValue( wxString(wWebClient.getsvgpath3( web ),wxConvUTF8) );
      m_SVGPath4->SetValue( wxString(wWebClient.getsvgpath4( web ),wxConvUTF8) );
      m_SVGPath5->SetValue( wxString(wWebClient.getsvgpath5( web ),wxConvUTF8) );
    }
  }

  // Clock Service
  iONode clock = wFreeRail.getclock( m_Props );
  if( clock == NULL ) {
    clock = NodeOp.inst( wClock.name(), m_Props, ELEMENT_NODE );
    NodeOp.addChild( m_Props, clock );
  }
  val = StrOp.fmt( "%d", wClock.getdivider( clock ) );
  m_Divider->SetValue( wxString( val,wxConvUTF8) );
  StrOp.free( val );
  val = StrOp.fmt( "%d", wClock.getupdate( clock ) );
  m_ClockUpdate->SetValue( wxString( val,wxConvUTF8) );
  StrOp.free( val );
  val = StrOp.fmt( "%d", wClock.gethour( clock ) );
  m_Hour->SetValue( wxString( val,wxConvUTF8) );
  StrOp.free( val );
  val = StrOp.fmt( "%d", wClock.getminute( clock ) );
  m_Minute->SetValue( wxString( val,wxConvUTF8) );
  StrOp.free( val );
  m_StopClockAtPowerOff->SetValue(wClock.isstopclockatpoweroff( clock )?true:false);


  // Trace
  m_Debug->SetValue( wTrace.isdebug( trace ) );
  m_Debug->Enable( wTrace.isdebug( trace ) ? true:false );
  m_Info->SetValue( wTrace.isinfo( trace ) );
  m_Calc->SetValue( wTrace.iscalc( trace ) );
  m_Byte->SetValue( wTrace.isbyte( trace ) );
  //m_Parse->SetValue( wTrace.isparse( trace ) );
  m_Auto->SetValue( wTrace.isautomatic( trace ) );
  m_Monitor->SetValue( wTrace.ismonitor( trace ) );
  m_SendAllTraces->SetValue( wTrace.islisten2all( trace ) );

  // Automat
  iONode ctrl = wFreeRail.getctrl( m_Props );
  if( ctrl == NULL ) {
    ctrl = NodeOp.inst( wCtrl.name(), m_Props, ELEMENT_NODE );
    NodeOp.addChild( m_Props, ctrl );
  }
  val = StrOp.fmt( "%d", wCtrl.getswtimeout( ctrl ) );
  m_SwTime->SetValue( wxString( val,wxConvUTF8) );
  StrOp.free( val );
  val = StrOp.fmt( "%d", wCtrl.getminbklc( ctrl ) );
  m_MinBKLen->SetValue( wxString( val,wxConvUTF8) );
  StrOp.free( val );
  val = StrOp.fmt( "%d", wCtrl.getignevt( ctrl ) );
  m_IgnEvt->SetValue( wxString( val,wxConvUTF8) );
  StrOp.free( val );
  val = StrOp.fmt( "%d", wCtrl.getinitfieldpause( ctrl ) );
  m_PauseInit->SetValue( wxString( val,wxConvUTF8) );
  StrOp.free( val );
  m_Seed->SetValue( wCtrl.getseed( ctrl ) );
  m_SavePosTime->SetValue( wCtrl.getsavepostime( ctrl ) );
  m_secondNextBlock->SetValue( wCtrl.issecondnextblock( ctrl ) );
  m_InitfieldPower->SetValue( wCtrl.isinitfieldpower( ctrl ) );
  m_EnableSwFb->SetValue( wCtrl.isenableswfb( ctrl ) );
  m_EventTimeout->SetValue( wCtrl.geteventtimeout( ctrl ) );
  m_SignalReset->SetValue( wCtrl.getsignalreset( ctrl ) );
  m_RouteSwTime->SetValue( wCtrl.getrouteswtime( ctrl ) );
  m_DisableRouteVreduce->SetValue( wCtrl.isdisablerouteVreduce( ctrl ) );
  m_SkipSetSw->SetValue( wCtrl.isskipsetsw( ctrl ) );
  m_SkipSetSg->SetValue( wCtrl.isskipsetsg( ctrl ) );
  m_UseBiCom->SetValue( wCtrl.isusebicom( ctrl ) );
  m_UseIdent->SetValue( wCtrl.isuseident( ctrl ) );
  m_SemaphoreWait->SetValue( wCtrl.getsemaphorewait( ctrl ) );
  m_SignalWait->SetValue( wCtrl.getsignalwait( ctrl ) );
  m_StopAtIdentMisMatch->SetValue( wCtrl.ispoweroffonidentmismatch( ctrl ) );
  m_PowerOffAtGhost->SetValue( wCtrl.ispoweroffatghost( ctrl ) );
  m_EBreakAtGhost->SetValue( wCtrl.isebreakatghost( ctrl ) );
  m_KeepGhost->SetValue( wCtrl.iskeepghost( ctrl ) );
  m_LocoStartGap->SetValue( wCtrl.getlocostartgap( ctrl ) );
  m_DisableSteal->SetValue( wCtrl.isdisablesteal( ctrl ) );
  m_BlockInitPause->SetValue( wCtrl.getblockinitpause( ctrl ) );
  m_PowerOffAtReset->SetValue( wCtrl.ispoweroffatreset( ctrl ) );
  m_ZeroThrottleID->SetValue( wCtrl.isallowzerothrottleid( ctrl ) );

  m_StopNoneCommuter->SetValue( wCtrl.isstopnonecommuter( ctrl ) ? true:false );
  m_SyncRoutes->SetValue( wCtrl.issyncroutes( ctrl ) ? true:false );
  m_SyncRouteTimeout->SetValue( wCtrl.getsyncroutetimeout( ctrl ) );
  m_TimedSensors->SetValue( wCtrl.istimedsensors( ctrl ) ? true:false );
  m_EnableAnalyzer->SetValue( wCtrl.isenableanalyzer( ctrl ) ? true:false );
  m_ForceUnlock->SetValue( wCtrl.isebreakforceunlock( ctrl ) ? true:false );
  //m_ForceUnlock->Enable(m_ForceUnlock->IsChecked());
  m_ResetFxSp->SetValue( wFreeRail.isresetspfx( m_Props ) ? true:false );
  m_ProcessSignalEvents->SetValue( wCtrl.issgevents( ctrl ) ? true:false );
  m_ReleaseOnIdle->SetValue( wCtrl.isreleaseonidle( ctrl ) ? true:false );
  m_CloseOnGhost->SetValue( wCtrl.iscloseonghost( ctrl ) ? true:false );
  m_CloseNoEvents->SetValue( wCtrl.isclosenoevents( ctrl ) ? true:false );
  m_SelectShortestBlock->SetValue( wCtrl.isselectshortestblock( ctrl ) ? true:false );
  m_RestoreSchedule->SetValue( wCtrl.isrestoreschedule( ctrl ) ? true:false );
  m_ActionTimer60->SetValue( wCtrl.isactiontimer60( ctrl ) ? true:false );
  m_CreateGuestOnBiDi->SetValue( wCtrl.iscreateguestonbidi( ctrl ) ? true:false );
  m_UseBiDiDirection->SetValue( wCtrl.isusebididir( ctrl ) ? true:false );
  m_DisableBlockWait4GoManual->SetValue( wCtrl.isdisableblockwait4gomanual( ctrl ) ? true:false );
  m_StopAtIn4GoManual->SetValue( wCtrl.isstopatin4gomanual( ctrl ) ? true:false );
  m_V0AtPowerOn->SetValue( wCtrl.isv0atpoweron( ctrl ) ? true:false );
  m_UseOnlyFirstIdent->SetValue( wCtrl.isuseonlyfirstident( ctrl ) ? true:false );
  m_UseRandomRate->SetValue( wCtrl.isuserandomrate( ctrl ) ? true:false );
  m_VirtualTimer->SetValue( wCtrl.getvirtualtimer( ctrl ) );
  m_RedirectToMaster->SetValue( wCtrl.isredirecttomaster( ctrl ) ? true:false );
  m_Weather->SetValue( wCtrl.isweather( ctrl ) ? true:false );
  m_V0OnEbreak->SetValue( wCtrl.isv0onebreak( ctrl ) ? true:false );

  if( StrOp.equals( wSignal.red, wCtrl.getdefaspect( ctrl ) ) )
    m_DefAspect->SetSelection(0);
  else if( StrOp.equals( wSignal.green, wCtrl.getdefaspect( ctrl ) ) )
    m_DefAspect->SetSelection(1);
  else if( StrOp.equals( wSignal.yellow, wCtrl.getdefaspect( ctrl ) ) )
    m_DefAspect->SetSelection(2);
  else if( StrOp.equals( wSignal.white, wCtrl.getdefaspect( ctrl ) ) )
    m_DefAspect->SetSelection(3);

  m_GreenAspect->SetValue( wCtrl.isgreenaspect( ctrl ) );


  // Controllers
  initControllerList();
  m_PowerOffOnExit->SetValue(wFreeRail.ispoweroffonexit(m_Props)?true:false);
  m_PowerOnAtInit->SetValue(wFreeRail.ispoweronatinit(m_Props)?true:false);
  m_Shutdown->SetValue(wFreeRail.isshutdownonexit(m_Props)?true:false);
  m_NoDevCheck->SetValue(wFreeRail.isnodevcheck(m_Props)?true:false);

  m_Lib->Append( wxString( wDigInt.barjut, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.bidib, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.cbus, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.clock, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.cti, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.dcc232, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.dccar, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.ddx, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.dinamo, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.dmx4all, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.dmxartnet, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.dmxeurolite, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.easydcc, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.ecos, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.editspro, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.esunavi, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.got, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.hsi88, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.hue, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.infracar, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.inter10, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.loconet, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.lrc135, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.massoth, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.mcs2, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.mgbox, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.mttmfcc, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.muet, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.nce, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.om32, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.opendcc, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.p50, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.p50x, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.perir, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.raptor, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.rclink, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.rfid12, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.rmx, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.rocnet, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.roco, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.rocomp, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.slx, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.spl, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.sprog, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.srcp, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.tamsmc, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.ucons88, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.vcs, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.xnmm, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.xpressnet, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.z21, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.zimo, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.zimobin, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.zimocan, wxConvUTF8 ) );
  m_Lib->Append( wxString( wDigInt.zs2, wxConvUTF8 ) );

  m_Lib->SetSelection( 0 );
  m_Controller = NULL;

  // R2Rnet
  iONode r2rnet = wFreeRail.getr2rnet( m_Props );
  if( r2rnet == NULL ) {
    r2rnet = NodeOp.inst( wR2RnetIni.name(), m_Props, ELEMENT_NODE );
    NodeOp.addChild( m_Props, r2rnet );
  }
  m_R2RnetID->SetValue( wxString( wR2RnetIni.getid(r2rnet),wxConvUTF8) );
  m_R2RnetAddr->SetValue( wxString( wR2RnetIni.getaddr(r2rnet),wxConvUTF8) );
  m_R2RnetPort->SetValue( wR2RnetIni.getport(r2rnet) );
  m_R2RnetRoutes->SetValue( wxString( wR2RnetIni.getroutes(r2rnet),wxConvUTF8) );
  m_R2RnetEnable->SetValue( wR2RnetIni.isenable(r2rnet) ? true:false );


  // Analyser
  iONode anaopt = wFreeRail.getanaopt( m_Props );
  if( anaopt == NULL ) {
    anaopt = NodeOp.inst( wAnaOpt.name(), m_Props, ELEMENT_NODE );
    NodeOp.addChild( m_Props, anaopt );
  }
  m_SetRouteId->SetValue( wAnaOpt.issetRouteId(anaopt)?true:false );
  m_CleanRouteId->SetValue( wAnaOpt.iscleanRouteId(anaopt)?true:false );
  m_SetBlockId->SetValue( wAnaOpt.issetBlockId(anaopt)?true:false );
  m_ResetBlockId->SetValue( wAnaOpt.isresetBlockId(anaopt)?true:false );
  m_AddSignalBlockAssignment->SetValue( wAnaOpt.isaddSignalBlockAssignment(anaopt)?true:false );
  m_ResetSignalBlockAssignment->SetValue( wAnaOpt.isresetSignalBlockAssignment(anaopt)?true:false );
  m_AddFeedbackBlockAssignment->SetValue( wAnaOpt.isaddFeedbackBlockAssignment(anaopt)?true:false );
  m_ResetFeedbackBlockAssignment->SetValue( wAnaOpt.isresetFeedbackBlockAssignment(anaopt)?true:false );
  m_BasicCheck->SetValue( wAnaOpt.isbasicCheck(anaopt)?true:false );
  m_BasicClean->SetValue( wAnaOpt.isbasicClean(anaopt)?true:false );
  m_BlockCheck->SetValue( wAnaOpt.isblockCheck(anaopt)?true:false );
  m_BlockClean->SetValue( wAnaOpt.isblockClean(anaopt)?true:false );
  m_RouteCheck->SetValue( wAnaOpt.isrouteCheck(anaopt)?true:false );
  m_RouteClean->SetValue( wAnaOpt.isrouteClean(anaopt)?true:false );
  m_ActionCheck->SetValue( wAnaOpt.isactionCheck(anaopt)?true:false );
  m_ActionClean->SetValue( wAnaOpt.isactionClean(anaopt)?true:false );

}

void RocrailIniDialog::initControllerList() {
  // Controllers
  m_Controllers->Clear();
  iONode controller = wFreeRail.getdigint( m_Props );
  while( controller != NULL ) {
    char* val = StrOp.fmt( "%s - %s", wDigInt.getiid( controller ), wDigInt.getlib( controller ) );
    m_Controllers->Append( wxString( val, wxConvUTF8 ), (void*)controller );
    StrOp.free( val );

    controller = wFreeRail.nextdigint( m_Props, controller );
  };
}

void RocrailIniDialog::event( iONode node ) {
  int cv       = wProgram.getcv (node);
  int val      = wProgram.getvalue(node);

  TraceOp.trc( "rocrailini", TRCLEVEL_INFO, __LINE__, 9999, "SO event %d=%d", cv, val );

  if( m_CSDialog != NULL ) {
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, PT_EVENT );
    // Make a copy of the node for using it out of this scope:
    event.SetClientData( node );
    wxPostEvent( m_CSDialog, event );
  }
}



void RocrailIniDialog::evaluate() {
  if( m_Props == NULL )
    return;
  // General
  wFreeRail.setplanfile( m_Props, m_PlanFile->GetValue().mb_str(wxConvUTF8) );
  wFreeRail.setoccupancy( m_Props, m_OccFile->GetValue().mb_str(wxConvUTF8) );
  wFreeRail.setlocs( m_Props, m_LocoFile->GetValue().mb_str(wxConvUTF8) );
  wFreeRail.setbackup( m_Props, m_Backup->IsChecked()?True:False );
  wFreeRail.setbackuppath( m_Props, m_BackupPath->GetValue().mb_str(wxConvUTF8) );
  wFreeRail.setkeypath( m_Props, m_KeyPath->GetValue().mb_str(wxConvUTF8) );
  wFreeRail.setlibpath( m_Props, m_LibPath->GetValue().mb_str(wxConvUTF8) );
  wFreeRail.setimgpath( m_Props, m_ImgPath->GetValue().mb_str(wxConvUTF8) );
  wFreeRail.seticonpath( m_Props, m_IconPath->GetValue().mb_str(wxConvUTF8) );
  wFreeRail.setissuepath( m_Props, m_IssuePath->GetValue().mb_str(wxConvUTF8) );
  wFreeRail.setsoundpath( m_Props, m_SoundPath->GetValue().mb_str(wxConvUTF8) );
  wFreeRail.setsoundplayer( m_Props, m_SoundPlayer->GetValue().mb_str(wxConvUTF8) );
  wFreeRail.setsoundplayerlocation( m_Props, m_SoundPlayerLocation->IsChecked()?True:False );
  iONode trace = wFreeRail.gettrace( m_Props );
  wTrace.setrfile( trace, m_TraceFile->GetValue().mb_str(wxConvUTF8) );
  wTrace.setprotpath( trace, m_ProtPath->GetValue().mb_str(wxConvUTF8) );
  wTrace.setnr( trace, m_NrTraceFiles->GetValue() );
  wTrace.setsize( trace, m_TraceFileSize->GetValue() );

  wFreeRail.setptiid( m_Props, m_PTIID->GetValue().mb_str(wxConvUTF8) );
  wFreeRail.setlciid( m_Props, m_LCIID->GetValue().mb_str(wxConvUTF8) );
  wFreeRail.setdpiid( m_Props, m_DPIID->GetValue().mb_str(wxConvUTF8) );
  wFreeRail.setsviid( m_Props, m_SVIID->GetValue().mb_str(wxConvUTF8) );

  wFreeRail.setsciid( m_Props, m_ScIID->GetValue().mb_str(wxConvUTF8) );

  wFreeRail.setfsutf8( m_Props, m_FSUTF8->IsChecked()?True:False );

  if( StrOp.equals( "-", m_ScSensor->GetValue().mb_str(wxConvUTF8) ) )
    wFreeRail.setscsensor( m_Props, "" );
  else
    wFreeRail.setscsensor( m_Props, m_ScSensor->GetValue().mb_str(wxConvUTF8) );

  wFreeRail.setcreatemodplan( m_Props, m_PlanType->GetSelection() == 1 ? True:False );
  wFreeRail.setresetspfx( m_Props, m_ResetFxSp->IsChecked() ? True:False );

  // Service
  iONode tcp = wFreeRail.gettcp( m_Props );
  wTcp.setport( tcp, atoi( m_ClientPort->GetValue().mb_str(wxConvUTF8) ) );
  wTcp.setmaxcon( tcp, atoi( m_MaxCon->GetValue().mb_str(wxConvUTF8) ) );
  wTcp.setcontrolcode( tcp, m_ControlCode->GetValue().mb_str(wxConvUTF8) );
  wTcp.setslavecode( tcp, m_SlaveCode->GetValue().mb_str(wxConvUTF8) );
  wTcp.setonlyfirstmaster( tcp, m_OnlyFirstMaster->IsChecked() ? True:False );
  iONode srcpcon = wFreeRail.getsrcpcon( m_Props );
  wSrcpCon.setport( srcpcon, m_SrcpPort->GetValue() );
  wSrcpCon.setactive( srcpcon, m_SrcpServiceActive->IsChecked()?True:False);
  wSrcpCon.setdevice( srcpcon, m_SRCPDevice->GetValue().mb_str(wxConvUTF8) );

  iONode snmp = wFreeRail.getSnmpService( m_Props );
  wSnmpService.setport( snmp, m_SnmpPort->GetValue() );
  wSnmpService.setactive( snmp, m_SnmpServiceActive->IsChecked()?True:False);
  wSnmpService.settraphost(snmp, m_SnmpTrapHost->GetValue().mb_str(wxConvUTF8) );
  wSnmpService.settrapport(snmp, m_SnmpTrapPort->GetValue());


  iONode http = wFreeRail.gethttp( m_Props );
  if( http == NULL ) {
    // add node:
    http = NodeOp.inst( wHttpService.name(), m_Props, ELEMENT_NODE );
    NodeOp.addChild( m_Props, http );
  }
  wHttpService.setport( http, atoi( m_HttpPort->GetValue().mb_str(wxConvUTF8) ) );
  wHttpService.setrefresh( http, atoi( m_ServiceRefresh->GetValue().mb_str(wxConvUTF8) ) );

  iONode web = wHttpService.getwebclient( http );
  if( web == NULL ) {
    // add node:
    web = NodeOp.inst( wWebClient.name(), http, ELEMENT_NODE );
    NodeOp.addChild( http, web );
  }

  wWebClient.setport( web, m_WebServicePort->GetValue() );
  wWebClient.setwebpath( web, m_WebPath->GetValue().mb_str(wxConvUTF8) );
  wWebClient.setsvgpath1( web, m_SVGPath->GetValue().mb_str(wxConvUTF8) );
  wWebClient.setsvgpath2( web, m_SVGPath2->GetValue().mb_str(wxConvUTF8) );
  wWebClient.setsvgpath3( web, m_SVGPath3->GetValue().mb_str(wxConvUTF8) );
  wWebClient.setsvgpath4( web, m_SVGPath4->GetValue().mb_str(wxConvUTF8) );
  wWebClient.setsvgpath5( web, m_SVGPath5->GetValue().mb_str(wxConvUTF8) );


  iONode clock = wFreeRail.getclock( m_Props );
  if( clock == NULL ) {
    // add node:
    clock = NodeOp.inst( wClock.name(), m_Props, ELEMENT_NODE );
    NodeOp.addChild( m_Props, clock );
  }
  wClock.setdivider( clock, atoi( m_Divider->GetValue().mb_str(wxConvUTF8) ) );
  wClock.setupdate( clock, atoi( m_ClockUpdate->GetValue().mb_str(wxConvUTF8) ) );
  wClock.sethour( clock, atoi( m_Hour->GetValue().mb_str(wxConvUTF8) ) );
  wClock.setminute( clock, atoi( m_Minute->GetValue().mb_str(wxConvUTF8) ) );
  wClock.setstopclockatpoweroff( clock, m_StopClockAtPowerOff->IsChecked()?True:False);

  // Trace
  trace = wFreeRail.gettrace( m_Props );
  wTrace.setdebug( trace, m_Debug->IsChecked() ? True:False );
  wTrace.setinfo( trace, m_Info->IsChecked() ? True:False );
  wTrace.setcalc( trace, m_Calc->IsChecked() ? True:False );
  wTrace.setbyte( trace, m_Byte->IsChecked() ? True:False );
  //wTrace.setparse( trace, m_Parse->IsChecked() ? True:False );
  wTrace.setautomatic( trace, m_Auto->IsChecked() ? True:False );
  wTrace.setmonitor( trace, m_Monitor->IsChecked() ? True:False );
  wTrace.setlisten2all( trace, m_SendAllTraces->IsChecked() ? True:False );

  // Controllers
  wFreeRail.setpoweroffonexit(m_Props, m_PowerOffOnExit->IsChecked() ? True:False);
  wFreeRail.setpoweronatinit(m_Props, m_PowerOnAtInit->IsChecked() ? True:False);
  wFreeRail.setshutdownonexit(m_Props, m_Shutdown->IsChecked() ? True:False);
  wFreeRail.setnodevcheck(m_Props, m_NoDevCheck->IsChecked() ? True:False);

  // Automat
  iONode ctrl = wFreeRail.getctrl( m_Props );
  wCtrl.setsgevents( ctrl, m_ProcessSignalEvents->IsChecked() ? True:False );
  wCtrl.setswtimeout( ctrl, atoi( m_SwTime->GetValue().mb_str(wxConvUTF8) ) );
  wCtrl.setminbklc( ctrl, atoi( m_MinBKLen->GetValue().mb_str(wxConvUTF8) ) );
  wCtrl.setignevt( ctrl, atoi( m_IgnEvt->GetValue().mb_str(wxConvUTF8) ) );
  wCtrl.setinitfieldpause( ctrl, atoi( m_PauseInit->GetValue().mb_str(wxConvUTF8) ) );
  wCtrl.setseed( ctrl, m_Seed->GetValue() );
  wCtrl.setsavepostime( ctrl, m_SavePosTime->GetValue() );
  wCtrl.setsecondnextblock( ctrl, m_secondNextBlock->IsChecked() ? True:False );
  wCtrl.setinitfieldpower( ctrl, m_InitfieldPower->IsChecked() ? True:False );
  wCtrl.setenableswfb( ctrl, m_EnableSwFb->IsChecked() ? True:False );
  wCtrl.seteventtimeout( ctrl, m_EventTimeout->GetValue() );
  wCtrl.setsignalreset( ctrl, m_SignalReset->GetValue() );
  wCtrl.setrouteswtime( ctrl, m_RouteSwTime->GetValue() );
  wCtrl.setdisablerouteVreduce( ctrl, m_DisableRouteVreduce->IsChecked() ? True:False  );
  wCtrl.setgreenaspect( ctrl, m_GreenAspect->IsChecked() ? True:False );
  wCtrl.setsemaphorewait( ctrl, m_SemaphoreWait->GetValue() );
  wCtrl.setsignalwait( ctrl, m_SignalWait->GetValue() );
  wCtrl.setlocostartgap( ctrl, m_LocoStartGap->GetValue() );
  wCtrl.setblockinitpause( ctrl, m_BlockInitPause->GetValue() );
  wCtrl.setstopnonecommuter( ctrl, m_StopNoneCommuter->GetValue() ? True:False );
  wCtrl.setsyncroutes( ctrl, m_SyncRoutes->GetValue() ? True:False );
  wCtrl.setsyncroutetimeout( ctrl, m_SyncRouteTimeout->GetValue() );
  wCtrl.settimedsensors( ctrl, m_TimedSensors->GetValue() ? True:False );
  wCtrl.setenableanalyzer( ctrl, m_EnableAnalyzer->GetValue() ? True:False );
  wCtrl.setebreakforceunlock( ctrl, m_ForceUnlock->GetValue() ? True:False );

  const char* defaspect[] = {wSignal.red,wSignal.green,wSignal.yellow,wSignal.white};
  wCtrl.setdefaspect( ctrl, defaspect[m_DefAspect->GetSelection()] );
  wCtrl.setskipsetsw( ctrl, m_SkipSetSw->IsChecked() ? True:False );
  wCtrl.setskipsetsg( ctrl, m_SkipSetSg->IsChecked() ? True:False );
  wCtrl.setusebicom( ctrl, m_UseBiCom->IsChecked() ? True:False );
  wCtrl.setuseident( ctrl, m_UseIdent->IsChecked() ? True:False );
  wCtrl.setpoweroffonidentmismatch( ctrl, m_StopAtIdentMisMatch->IsChecked() ? True:False );
  wCtrl.setpoweroffatghost( ctrl, m_PowerOffAtGhost->IsChecked() ? True:False );
  wCtrl.setebreakatghost( ctrl, m_EBreakAtGhost->IsChecked() ? True:False );
  wCtrl.setkeepghost( ctrl, m_KeepGhost->IsChecked() ? True:False );
  wCtrl.setdisablesteal( ctrl, m_DisableSteal->IsChecked() ? True:False );
  wCtrl.setpoweroffatreset( ctrl, m_PowerOffAtReset->IsChecked() ? True:False );
  wCtrl.setallowzerothrottleid( ctrl, m_ZeroThrottleID->IsChecked() ? True:False );
  wCtrl.setreleaseonidle( ctrl, m_ReleaseOnIdle->IsChecked() ? True:False );
  wCtrl.setcloseonghost( ctrl, m_CloseOnGhost->IsChecked() ? True:False );
  wCtrl.setclosenoevents( ctrl, m_CloseNoEvents->IsChecked() ? True:False );
  wCtrl.setselectshortestblock( ctrl, m_SelectShortestBlock->IsChecked() ? True:False );
  wCtrl.setrestoreschedule( ctrl, m_RestoreSchedule->IsChecked() ? True:False );
  wCtrl.setactiontimer60( ctrl, m_ActionTimer60->IsChecked() ? True:False );
  wCtrl.setcreateguestonbidi( ctrl, m_CreateGuestOnBiDi->IsChecked() ? True:False );
  wCtrl.setusebididir( ctrl, m_UseBiDiDirection->IsChecked() ? True:False );
  wCtrl.setdisableblockwait4gomanual( ctrl, m_DisableBlockWait4GoManual->IsChecked() ? True:False );
  wCtrl.setstopatin4gomanual( ctrl, m_StopAtIn4GoManual->IsChecked() ? True:False );
  wCtrl.setv0atpoweron( ctrl, m_V0AtPowerOn->IsChecked() ? True:False );
  wCtrl.setuseonlyfirstident( ctrl, m_UseOnlyFirstIdent->IsChecked() ? True:False );
  wCtrl.setuserandomrate( ctrl, m_UseRandomRate->IsChecked() ? True:False );
  wCtrl.setvirtualtimer( ctrl, m_VirtualTimer->GetValue() );
  wCtrl.setredirecttomaster( ctrl, m_RedirectToMaster->IsChecked() ? True:False );
  wCtrl.setweather( ctrl, m_Weather->IsChecked() ? True:False );
  wCtrl.setv0onebreak( ctrl, m_V0OnEbreak->IsChecked() ? True:False );

  // R2Rnet
  iONode r2rnet = wFreeRail.getr2rnet(m_Props);
  wR2RnetIni.setid( r2rnet, m_R2RnetID->GetValue().mb_str(wxConvUTF8) );
  wR2RnetIni.setaddr( r2rnet, m_R2RnetAddr->GetValue().mb_str(wxConvUTF8) );
  wR2RnetIni.setport( r2rnet, m_R2RnetPort->GetValue() );
  wR2RnetIni.setroutes( r2rnet, m_R2RnetRoutes->GetValue().mb_str(wxConvUTF8) );
  wR2RnetIni.setenable( r2rnet, m_R2RnetEnable->IsChecked() ? True:False );

  // Analyser
  iONode anaopt = wFreeRail.getanaopt(m_Props);
  wAnaOpt.setsetRouteId(anaopt, m_SetRouteId->IsChecked()?True:False );
  wAnaOpt.setcleanRouteId(anaopt, m_CleanRouteId->IsChecked()?True:False );
  wAnaOpt.setsetBlockId(anaopt, m_SetBlockId->IsChecked()?True:False );
  wAnaOpt.setresetBlockId(anaopt, m_ResetBlockId->IsChecked()?True:False );
  wAnaOpt.setaddSignalBlockAssignment(anaopt, m_AddSignalBlockAssignment->IsChecked()?True:False );
  wAnaOpt.setresetSignalBlockAssignment(anaopt, m_ResetSignalBlockAssignment->IsChecked()?True:False );
  wAnaOpt.setaddFeedbackBlockAssignment(anaopt, m_AddFeedbackBlockAssignment->IsChecked()?True:False );
  wAnaOpt.setresetFeedbackBlockAssignment(anaopt, m_ResetFeedbackBlockAssignment->IsChecked()?True:False );
  wAnaOpt.setbasicCheck(anaopt, m_BasicCheck->IsChecked()?True:False );
  wAnaOpt.setbasicClean(anaopt, m_BasicClean->IsChecked()?True:False );
  wAnaOpt.setblockCheck(anaopt, m_BlockCheck->IsChecked()?True:False );
  wAnaOpt.setblockClean(anaopt, m_BlockClean->IsChecked()?True:False );
  wAnaOpt.setrouteCheck(anaopt, m_RouteCheck->IsChecked()?True:False );
  wAnaOpt.setrouteClean(anaopt, m_RouteClean->IsChecked()?True:False );
  wAnaOpt.setactionCheck(anaopt, m_ActionCheck->IsChecked()?True:False );
  wAnaOpt.setactionClean(anaopt, m_ActionClean->IsChecked()?True:False );
}




/*!
 * RocrailIniDialog creator
 */

bool RocrailIniDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin RocrailIniDialog member initialisation
    m_RRNotebook = NULL;
    m_GeneralPanel = NULL;
    m_LabelPlanfile = NULL;
    m_PlanFile = NULL;
    m_PlanFileDlg = NULL;
    m_labOccFile = NULL;
    m_OccFile = NULL;
    m_OpenOccFile = NULL;
    m_labLocoFile = NULL;
    m_LocoFile = NULL;
    m_LocoFileDlg = NULL;
    m_labPlanType = NULL;
    m_PlanType = NULL;
    m_Backup = NULL;
    m_BackupPath = NULL;
    m_labKeyPath = NULL;
    m_KeyPath = NULL;
    m_LabelLibPath = NULL;
    m_LibPath = NULL;
    m_labImgPath = NULL;
    m_ImgPath = NULL;
    m_labIconPath = NULL;
    m_IconPath = NULL;
    m_labIssuesPath = NULL;
    m_IssuePath = NULL;
    m_labSoundPath = NULL;
    m_SoundPath = NULL;
    m_labSoundPlayer = NULL;
    m_SoundPlayer = NULL;
    m_SoundPlayerLocation = NULL;
    m_ScBox = NULL;
    m_labScSensor = NULL;
    m_ScSensor = NULL;
    m_labScIID = NULL;
    m_ScIID = NULL;
    m_labPTIID = NULL;
    m_PTIID = NULL;
    m_labLCIID = NULL;
    m_LCIID = NULL;
    m_labDPIID = NULL;
    m_DPIID = NULL;
    m_labSVIID = NULL;
    m_SVIID = NULL;
    m_FSUTF8 = NULL;
    m_TracePanel = NULL;
    m_TraceLevel = NULL;
    m_Auto = NULL;
    m_Monitor = NULL;
    m_Calc = NULL;
    m_DevTraceLevel = NULL;
    m_Byte = NULL;
    m_Info = NULL;
    m_Debug = NULL;
    m_labNrTraceFiles = NULL;
    m_NrTraceFiles = NULL;
    m_labTraceFileSize = NULL;
    m_TraceFileSize = NULL;
    m_SendAllTraces = NULL;
    m_LabelTraceFile = NULL;
    m_TraceFile = NULL;
    m_labProtPath = NULL;
    m_ProtPath = NULL;
    m_ServicePanel = NULL;
    m_HttpBox = NULL;
    m_LabelHttpPort = NULL;
    m_HttpPort = NULL;
    m_LabServiceRefresh = NULL;
    m_ServiceRefresh = NULL;
    m_ClockBox = NULL;
    m_labDevider = NULL;
    m_Divider = NULL;
    m_ClockUpdate = NULL;
    m_labHour = NULL;
    m_Hour = NULL;
    m_labMinute = NULL;
    m_Minute = NULL;
    m_StopClockAtPowerOff = NULL;
    m_ClientBox = NULL;
    m_LabelClientPort = NULL;
    m_ClientPort = NULL;
    m_LabelMaxCon = NULL;
    m_MaxCon = NULL;
    m_labControlCode = NULL;
    m_ControlCode = NULL;
    m_labSlaveCode = NULL;
    m_SlaveCode = NULL;
    m_OnlyFirstMaster = NULL;
    m_SrcpService = NULL;
    m_labSrcpPort = NULL;
    m_SrcpPort = NULL;
    m_SrcpServiceActive = NULL;
    m_labSRCPDevice = NULL;
    m_SRCPDevice = NULL;
    m_SNMPBox = NULL;
    m_labSnmpPort = NULL;
    m_SnmpPort = NULL;
    m_SnmpServiceActive = NULL;
    m_SNMPTrapBox = NULL;
    m_labSnmpTrapHost = NULL;
    m_SnmpTrapHost = NULL;
    m_labSnmpTrapPort = NULL;
    m_SnmpTrapPort = NULL;
    m_AtomatPanel = NULL;
    m_LabelSwTime = NULL;
    m_SwTime = NULL;
    m_LabelMinBKLen = NULL;
    m_MinBKLen = NULL;
    m_LabelIgnEvt = NULL;
    m_IgnEvt = NULL;
    m_labInitPause = NULL;
    m_PauseInit = NULL;
    m_labInitPower = NULL;
    m_InitfieldPower = NULL;
    m_labSeed = NULL;
    m_Seed = NULL;
    m_labSavePosTime = NULL;
    m_SavePosTime = NULL;
    m_labEventTimeout = NULL;
    m_EventTimeout = NULL;
    m_labSignalReset = NULL;
    m_SignalReset = NULL;
    m_labRouteSwTime = NULL;
    m_RouteSwTime = NULL;
    m_labSemaphoreWait = NULL;
    m_SemaphoreWait = NULL;
    m_labSignalWait = NULL;
    m_SignalWait = NULL;
    m_labLocoStartGap = NULL;
    m_LocoStartGap = NULL;
    m_labBlockInitPause = NULL;
    m_BlockInitPause = NULL;
    m_labSyncRouteTimeout = NULL;
    m_SyncRouteTimeout = NULL;
    m_labVirtualTimer = NULL;
    m_VirtualTimer = NULL;
    m_secondNextBlock = NULL;
    m_EnableSwFb = NULL;
    m_DisableRouteVreduce = NULL;
    m_SkipSetSw = NULL;
    m_SkipSetSg = NULL;
    m_UseBiCom = NULL;
    m_CreateGuestOnBiDi = NULL;
    m_UseBiDiDirection = NULL;
    m_UseIdent = NULL;
    m_StopAtIdentMisMatch = NULL;
    m_PowerOffAtGhost = NULL;
    m_EBreakAtGhost = NULL;
    m_KeepGhost = NULL;
    m_DisableSteal = NULL;
    m_PowerOffAtReset = NULL;
    m_ZeroThrottleID = NULL;
    m_StopNoneCommuter = NULL;
    m_SyncRoutes = NULL;
    m_TimedSensors = NULL;
    m_EnableAnalyzer = NULL;
    m_ForceUnlock = NULL;
    m_ReleaseOnIdle = NULL;
    m_CloseOnGhost = NULL;
    m_UseOnlyFirstIdent = NULL;
    m_ActionTimer60 = NULL;
    m_RestoreSchedule = NULL;
    m_SelectShortestBlock = NULL;
    m_CloseNoEvents = NULL;
    m_DisableBlockWait4GoManual = NULL;
    m_StopAtIn4GoManual = NULL;
    m_V0AtPowerOn = NULL;
    m_GreenAspect = NULL;
    m_DefAspect = NULL;
    m_ResetFxSp = NULL;
    m_ProcessSignalEvents = NULL;
    m_UseRandomRate = NULL;
    m_RedirectToMaster = NULL;
    m_Weather = NULL;
    m_V0OnEbreak = NULL;
    m_ControllersPanel = NULL;
    m_Controllers = NULL;
    m_ControllerDelete = NULL;
    m_ControllerProps = NULL;
    m_Default = NULL;
    m_AddControllerBox = NULL;
    m_Lib = NULL;
    m_ControllerAdd = NULL;
    m_ControllerOptionsBox = NULL;
    m_PowerOffOnExit = NULL;
    m_PowerOnAtInit = NULL;
    m_Shutdown = NULL;
    m_NoDevCheck = NULL;
    m_R2RnetPanel = NULL;
    m_labR2RnetID = NULL;
    m_R2RnetID = NULL;
    m_labR2RnetAddr = NULL;
    m_R2RnetAddr = NULL;
    m_labR2RnetPort = NULL;
    m_R2RnetPort = NULL;
    m_labR2RnetRoutes = NULL;
    m_R2RnetRoutes = NULL;
    m_R2RnetRoutesDlg = NULL;
    m_R2RnetEnable = NULL;
    m_AnalyserPanel = NULL;
    m_AnaGenerate = NULL;
    m_SetRouteId = NULL;
    m_SetBlockId = NULL;
    m_AddSignalBlockAssignment = NULL;
    m_AddFeedbackBlockAssignment = NULL;
    m_AnaClean = NULL;
    m_CleanRouteId = NULL;
    m_ResetBlockId = NULL;
    m_ResetSignalBlockAssignment = NULL;
    m_ResetFeedbackBlockAssignment = NULL;
    m_AnaCheck = NULL;
    m_BasicCheck = NULL;
    m_BlockCheck = NULL;
    m_RouteCheck = NULL;
    m_ActionCheck = NULL;
    m_AnaReset = NULL;
    m_BasicClean = NULL;
    m_BlockClean = NULL;
    m_RouteClean = NULL;
    m_ActionClean = NULL;
    m_RocWebPanel = NULL;
    m_WebServiceBox = NULL;
    m_LabWebServicePort = NULL;
    m_WebServicePort = NULL;
    m_labWebPath = NULL;
    m_WebPath = NULL;
    m_WebPathDlg = NULL;
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
    m_OK = NULL;
    m_Cancel = NULL;
////@end RocrailIniDialog member initialisation

////@begin RocrailIniDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end RocrailIniDialog creation
    return true;
}

/*!
 * Control creation for RocrailIniDialog
 */

void RocrailIniDialog::CreateControls()
{
////@begin RocrailIniDialog content construction
    RocrailIniDialog* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    m_RRNotebook = new wxNotebook( itemDialog1, ID_NOTEBOOK_RR, wxDefaultPosition, wxDefaultSize, m_TabAlign );

    m_GeneralPanel = new wxPanel( m_RRNotebook, ID_PANEL_RR_INI, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxVERTICAL);
    m_GeneralPanel->SetSizer(itemBoxSizer5);

    wxFlexGridSizer* itemFlexGridSizer6 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer5->Add(itemFlexGridSizer6, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 5);
    m_LabelPlanfile = new wxStaticText( m_GeneralPanel, wxID_STATIC_RR_PLANFILE, _("PlanFile"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_LabelPlanfile, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer8 = new wxFlexGridSizer(0, 2, 0, 0);
    itemFlexGridSizer6->Add(itemFlexGridSizer8, 0, wxGROW|wxALIGN_CENTER_VERTICAL, 5);
    m_PlanFile = new wxTextCtrl( m_GeneralPanel, ID_TEXTCTRL_RR_PLANFILE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer8->Add(m_PlanFile, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_PlanFileDlg = new wxButton( m_GeneralPanel, ID_BUTTON_PLANFILE, _("..."), wxDefaultPosition, wxSize(50, -1), 0 );
    itemFlexGridSizer8->Add(m_PlanFileDlg, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemFlexGridSizer8->AddGrowableCol(0);

    m_labOccFile = new wxStaticText( m_GeneralPanel, wxID_ANY, _("Occupation file"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_labOccFile, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxFlexGridSizer* itemFlexGridSizer12 = new wxFlexGridSizer(0, 2, 0, 0);
    itemFlexGridSizer6->Add(itemFlexGridSizer12, 0, wxGROW|wxALIGN_CENTER_VERTICAL, 5);
    m_OccFile = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer12->Add(m_OccFile, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_OpenOccFile = new wxButton( m_GeneralPanel, ID_BUTTON_OCCFILE, _("..."), wxDefaultPosition, wxSize(50, -1), 0 );
    itemFlexGridSizer12->Add(m_OpenOccFile, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemFlexGridSizer12->AddGrowableCol(0);

    m_labLocoFile = new wxStaticText( m_GeneralPanel, wxID_ANY, _("LocoFile"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_labLocoFile, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxFlexGridSizer* itemFlexGridSizer16 = new wxFlexGridSizer(0, 2, 0, 0);
    itemFlexGridSizer6->Add(itemFlexGridSizer16, 0, wxGROW|wxALIGN_CENTER_VERTICAL, 5);
    m_LocoFile = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer16->Add(m_LocoFile, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_LocoFileDlg = new wxButton( m_GeneralPanel, ID_BUTTON_LOCOFILE, _("..."), wxDefaultPosition, wxSize(50, -1), 0 );
    itemFlexGridSizer16->Add(m_LocoFileDlg, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemFlexGridSizer16->AddGrowableCol(0);

    m_labPlanType = new wxStaticText( m_GeneralPanel, wxID_ANY, _("Plan type"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_labPlanType, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_PlanTypeStrings;
    m_PlanTypeStrings.Add(_("&Standard"));
    m_PlanTypeStrings.Add(_("&Modules"));
    m_PlanType = new wxRadioBox( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_PlanTypeStrings, 1, wxRA_SPECIFY_ROWS );
    m_PlanType->SetSelection(0);
    itemFlexGridSizer6->Add(m_PlanType, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Backup = new wxCheckBox( m_GeneralPanel, wxID_ANY, _("Backup"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Backup->SetValue(false);
    itemFlexGridSizer6->Add(m_Backup, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_BackupPath = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_BackupPath, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labKeyPath = new wxStaticText( m_GeneralPanel, wxID_ANY, _("KeyPath"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_labKeyPath, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxFlexGridSizer* itemFlexGridSizer24 = new wxFlexGridSizer(0, 2, 0, 0);
    itemFlexGridSizer6->Add(itemFlexGridSizer24, 1, wxGROW|wxALIGN_CENTER_VERTICAL, 5);
    m_KeyPath = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer24->Add(m_KeyPath, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxButton* itemButton26 = new wxButton( m_GeneralPanel, ID_BUTTON_KEYPATH, _("..."), wxDefaultPosition, wxSize(50, -1), 0 );
    itemFlexGridSizer24->Add(itemButton26, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemFlexGridSizer24->AddGrowableCol(0);

    m_LabelLibPath = new wxStaticText( m_GeneralPanel, wxID_STATIC_RR_LIBPATH, _("LibPath"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_LabelLibPath, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_LibPath = new wxTextCtrl( m_GeneralPanel, ID_TEXTCTRL_RR_LIBPATH, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_LibPath, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labImgPath = new wxStaticText( m_GeneralPanel, wxID_ANY, _("ImgPath"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_labImgPath, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_ImgPath = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_ImgPath, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labIconPath = new wxStaticText( m_GeneralPanel, wxID_ANY, _("Icon path"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_labIconPath, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_IconPath = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_IconPath, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labIssuesPath = new wxStaticText( m_GeneralPanel, wxID_ANY, _("IssuesPath"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_labIssuesPath, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_IssuePath = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_IssuePath, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labSoundPath = new wxStaticText( m_GeneralPanel, wxID_ANY, _("SoundPath"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_labSoundPath, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_SoundPath = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_SoundPath, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labSoundPlayer = new wxStaticText( m_GeneralPanel, wxID_ANY, _("SoundPlayer"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(m_labSoundPlayer, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxFlexGridSizer* itemFlexGridSizer38 = new wxFlexGridSizer(0, 2, 0, 0);
    itemFlexGridSizer6->Add(itemFlexGridSizer38, 0, wxGROW|wxALIGN_CENTER_VERTICAL, 5);
    m_SoundPlayer = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer38->Add(m_SoundPlayer, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_SoundPlayerLocation = new wxCheckBox( m_GeneralPanel, wxID_ANY, _("Add location parameter"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SoundPlayerLocation->SetValue(false);
    itemFlexGridSizer38->Add(m_SoundPlayerLocation, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemFlexGridSizer38->AddGrowableCol(0);

    itemFlexGridSizer6->AddGrowableCol(1);

    m_ScBox = new wxStaticBox(m_GeneralPanel, wxID_ANY, _("Shortcut"));
    wxStaticBoxSizer* itemStaticBoxSizer41 = new wxStaticBoxSizer(m_ScBox, wxVERTICAL);
    itemBoxSizer5->Add(itemStaticBoxSizer41, 0, wxGROW|wxLEFT|wxRIGHT, 5);
    wxFlexGridSizer* itemFlexGridSizer42 = new wxFlexGridSizer(0, 4, 0, 0);
    itemStaticBoxSizer41->Add(itemFlexGridSizer42, 0, wxGROW, 5);
    m_labScSensor = new wxStaticText( m_GeneralPanel, wxID_ANY, _("Shortcut"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer42->Add(m_labScSensor, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxArrayString m_ScSensorStrings;
    m_ScSensor = new wxComboBox( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_ScSensorStrings, wxCB_DROPDOWN );
    itemFlexGridSizer42->Add(m_ScSensor, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labScIID = new wxStaticText( m_GeneralPanel, wxID_ANY, _("IID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer42->Add(m_labScIID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_ScIID = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer42->Add(m_ScIID, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    itemFlexGridSizer42->AddGrowableCol(1);

    wxBoxSizer* itemBoxSizer47 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer5->Add(itemBoxSizer47, 0, wxALIGN_LEFT|wxTOP, 5);
    wxFlexGridSizer* itemFlexGridSizer48 = new wxFlexGridSizer(0, 8, 0, 0);
    itemBoxSizer47->Add(itemFlexGridSizer48, 0, wxALIGN_CENTER_VERTICAL, 5);
    m_labPTIID = new wxStaticText( m_GeneralPanel, wxID_ANY, _("PT IID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer48->Add(m_labPTIID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_PTIID = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer48->Add(m_PTIID, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labLCIID = new wxStaticText( m_GeneralPanel, wxID_ANY, _("LC IID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer48->Add(m_labLCIID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_LCIID = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer48->Add(m_LCIID, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labDPIID = new wxStaticText( m_GeneralPanel, wxID_ANY, _("DP IID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer48->Add(m_labDPIID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_DPIID = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer48->Add(m_DPIID, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labSVIID = new wxStaticText( m_GeneralPanel, wxID_ANY, _("SV IID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer48->Add(m_labSVIID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_SVIID = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer48->Add(m_SVIID, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_FSUTF8 = new wxCheckBox( m_GeneralPanel, wxID_ANY, _("UTF-8"), wxDefaultPosition, wxDefaultSize, 0 );
    m_FSUTF8->SetValue(false);
    itemBoxSizer47->Add(m_FSUTF8, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_RRNotebook->AddPage(m_GeneralPanel, _("General"));

    m_TracePanel = new wxPanel( m_RRNotebook, ID_PANEL_RR_TRACE, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer59 = new wxBoxSizer(wxVERTICAL);
    m_TracePanel->SetSizer(itemBoxSizer59);

    wxStaticBox* itemStaticBoxSizer60Static = new wxStaticBox(m_TracePanel, wxID_ANY, _("User Levels"));
    m_TraceLevel = new wxStaticBoxSizer(itemStaticBoxSizer60Static, wxVERTICAL);
    itemBoxSizer59->Add(m_TraceLevel, 0, wxGROW|wxALL, 5);
    m_Auto = new wxCheckBox( m_TracePanel, ID_CHECKBOX_RR_AUTO, _("Automatic"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_Auto->SetValue(false);
    m_TraceLevel->Add(m_Auto, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_Monitor = new wxCheckBox( m_TracePanel, ID_CHECKBOX_RR_MONITOR, _("Monitor"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Monitor->SetValue(false);
    m_TraceLevel->Add(m_Monitor, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 5);

    m_Calc = new wxCheckBox( m_TracePanel, wxID_ANY, _("Calc"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Calc->SetValue(false);
    m_TraceLevel->Add(m_Calc, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 5);

    m_DevTraceLevel = new wxStaticBox(m_TracePanel, wxID_ANY, _("Developer Levels"));
    wxStaticBoxSizer* itemStaticBoxSizer64 = new wxStaticBoxSizer(m_DevTraceLevel, wxVERTICAL);
    itemBoxSizer59->Add(itemStaticBoxSizer64, 0, wxGROW|wxALL, 5);
    m_Byte = new wxCheckBox( m_TracePanel, ID_CHECKBOX_RR_BYTE, _("Byte"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_Byte->SetValue(false);
    itemStaticBoxSizer64->Add(m_Byte, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 5);

    m_Info = new wxCheckBox( m_TracePanel, wxID_ANY, _("Info"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Info->SetValue(false);
    itemStaticBoxSizer64->Add(m_Info, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 5);

    m_Debug = new wxCheckBox( m_TracePanel, ID_CHECKBOX_RR_DEBUG, _("Debug"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_Debug->SetValue(false);
    itemStaticBoxSizer64->Add(m_Debug, 0, wxALIGN_LEFT|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer68 = new wxFlexGridSizer(0, 2, 0, 0);
    itemStaticBoxSizer64->Add(itemFlexGridSizer68, 0, wxALIGN_LEFT, 5);
    m_labNrTraceFiles = new wxStaticText( m_TracePanel, wxID_ANY, _("Number of files"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer68->Add(m_labNrTraceFiles, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_NrTraceFiles = new wxSpinCtrl( m_TracePanel, wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 10 );
    itemFlexGridSizer68->Add(m_NrTraceFiles, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_labTraceFileSize = new wxStaticText( m_TracePanel, wxID_ANY, _("File size"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer68->Add(m_labTraceFileSize, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_TraceFileSize = new wxSpinCtrl( m_TracePanel, wxID_ANY, wxT("100"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 10, 10000, 100 );
    itemFlexGridSizer68->Add(m_TraceFileSize, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemFlexGridSizer68->AddGrowableCol(1);

    wxStaticLine* itemStaticLine73 = new wxStaticLine( m_TracePanel, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemStaticBoxSizer64->Add(itemStaticLine73, 0, wxGROW|wxALL, 5);

    m_SendAllTraces = new wxCheckBox( m_TracePanel, wxID_ANY, _("Send all traces to the clients"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SendAllTraces->SetValue(false);
    itemStaticBoxSizer64->Add(m_SendAllTraces, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 5);

    wxFlexGridSizer* itemFlexGridSizer75 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer59->Add(itemFlexGridSizer75, 0, wxGROW|wxALL, 5);
    m_LabelTraceFile = new wxStaticText( m_TracePanel, wxID_STATIC_RR_TRACEFILE, _("TraceFile"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer75->Add(m_LabelTraceFile, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_TraceFile = new wxTextCtrl( m_TracePanel, ID_TEXTCTRL_RR_TRACEFILE, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer75->Add(m_TraceFile, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_labProtPath = new wxStaticText( m_TracePanel, wxID_ANY, _("Path"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer75->Add(m_labProtPath, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_ProtPath = new wxTextCtrl( m_TracePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer75->Add(m_ProtPath, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    itemFlexGridSizer75->AddGrowableCol(1);

    m_RRNotebook->AddPage(m_TracePanel, _("Trace"));

    m_ServicePanel = new wxPanel( m_RRNotebook, ID_PANEL_RR_SERVICE, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer81 = new wxBoxSizer(wxHORIZONTAL);
    m_ServicePanel->SetSizer(itemBoxSizer81);

    wxBoxSizer* itemBoxSizer82 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer81->Add(itemBoxSizer82, 0, wxALIGN_TOP|wxALL, 5);
    wxStaticBox* itemStaticBoxSizer83Static = new wxStaticBox(m_ServicePanel, wxID_ANY, _("HTTP Service"));
    m_HttpBox = new wxStaticBoxSizer(itemStaticBoxSizer83Static, wxHORIZONTAL);
    itemBoxSizer82->Add(m_HttpBox, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 5);
    m_LabelHttpPort = new wxStaticText( m_ServicePanel, wxID_STATIC_RR_HTTPPORT, _("Port"), wxDefaultPosition, wxDefaultSize, 0 );
    m_HttpBox->Add(m_LabelHttpPort, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_HttpPort = new wxTextCtrl( m_ServicePanel, ID_TEXTCTRL_RR_HTTPPORT, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    m_HttpPort->SetMaxLength(5);
    m_HttpBox->Add(m_HttpPort, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabServiceRefresh = new wxStaticText( m_ServicePanel, wxID_STATIC_RR_SEVICE_REFRESH, _("Refresh"), wxDefaultPosition, wxDefaultSize, 0 );
    m_HttpBox->Add(m_LabServiceRefresh, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ServiceRefresh = new wxTextCtrl( m_ServicePanel, ID_TEXTCTRL_RR_SERVICE_REFRESH, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    m_HttpBox->Add(m_ServiceRefresh, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer88Static = new wxStaticBox(m_ServicePanel, wxID_ANY, _("Clock Service"));
    m_ClockBox = new wxStaticBoxSizer(itemStaticBoxSizer88Static, wxVERTICAL);
    itemBoxSizer82->Add(m_ClockBox, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 5);
    wxFlexGridSizer* itemFlexGridSizer89 = new wxFlexGridSizer(0, 7, 0, 0);
    m_ClockBox->Add(itemFlexGridSizer89, 0, wxALIGN_CENTER_HORIZONTAL, 5);
    m_labDevider = new wxStaticText( m_ServicePanel, wxID_STATIC_RR_CLOCK_DEVIDER, _("divider"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer89->Add(m_labDevider, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM, 5);

    m_Divider = new wxTextCtrl( m_ServicePanel, ID_TEXTCTRL_RR_CLOCK_DEVIDER, _("1"), wxDefaultPosition, wxSize(40, -1), wxTE_CENTRE );
    m_Divider->SetMaxLength(2);
    itemFlexGridSizer89->Add(m_Divider, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM, 5);

    m_ClockUpdate = new wxTextCtrl( m_ServicePanel, wxID_ANY, _("1"), wxDefaultPosition, wxSize(40, -1), wxTE_CENTRE );
    m_ClockUpdate->SetMaxLength(2);
    itemFlexGridSizer89->Add(m_ClockUpdate, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labHour = new wxStaticText( m_ServicePanel, wxID_STATIC_RR_CLOCK_HOUR, _("hour"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer89->Add(m_labHour, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM, 5);

    m_Hour = new wxTextCtrl( m_ServicePanel, ID_TEXTCTRL_RR_CLOCK_HOUR, _("24"), wxDefaultPosition, wxSize(40, -1), wxTE_CENTRE );
    m_Hour->SetMaxLength(2);
    if (RocrailIniDialog::ShowToolTips())
        m_Hour->SetToolTip(_("24 disabled the start setting"));
    itemFlexGridSizer89->Add(m_Hour, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labMinute = new wxStaticText( m_ServicePanel, wxID_STATIC_RR_CLOCK_MINUTE, _("minute"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer89->Add(m_labMinute, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM, 5);

    m_Minute = new wxTextCtrl( m_ServicePanel, ID_TEXTCTRL_RR_CLOCK_MINUTE, _("60"), wxDefaultPosition, wxSize(40, -1), wxTE_CENTRE );
    m_Minute->SetMaxLength(2);
    if (RocrailIniDialog::ShowToolTips())
        m_Minute->SetToolTip(_("60 disabled the start setting"));
    itemFlexGridSizer89->Add(m_Minute, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer97 = new wxFlexGridSizer(0, 2, 0, 0);
    m_ClockBox->Add(itemFlexGridSizer97, 0, wxALIGN_LEFT, 5);
    m_StopClockAtPowerOff = new wxCheckBox( m_ServicePanel, wxID_ANY, _("Stop clock at power off"), wxDefaultPosition, wxDefaultSize, 0 );
    m_StopClockAtPowerOff->SetValue(true);
    itemFlexGridSizer97->Add(m_StopClockAtPowerOff, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer99Static = new wxStaticBox(m_ServicePanel, wxID_ANY, _("Client Service"));
    m_ClientBox = new wxStaticBoxSizer(itemStaticBoxSizer99Static, wxVERTICAL);
    itemBoxSizer82->Add(m_ClientBox, 0, wxGROW|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer100 = new wxFlexGridSizer(0, 2, 0, 0);
    m_ClientBox->Add(itemFlexGridSizer100, 1, wxGROW, 5);
    m_LabelClientPort = new wxStaticText( m_ServicePanel, wxID_STATIC_RR_CLIENTPORT, _("port"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer100->Add(m_LabelClientPort, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ClientPort = new wxTextCtrl( m_ServicePanel, ID_TEXTCTRL_RR_CLIENTPORT, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    m_ClientPort->SetMaxLength(5);
    itemFlexGridSizer100->Add(m_ClientPort, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelMaxCon = new wxStaticText( m_ServicePanel, wxID_STATIC_RR_MAXCON, _("max."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer100->Add(m_LabelMaxCon, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_MaxCon = new wxTextCtrl( m_ServicePanel, ID_TEXTCTRL_RR_MAXCONN, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    m_MaxCon->SetMaxLength(2);
    itemFlexGridSizer100->Add(m_MaxCon, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labControlCode = new wxStaticText( m_ServicePanel, wxID_ANY, _("Control code"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer100->Add(m_labControlCode, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_ControlCode = new wxTextCtrl( m_ServicePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer100->Add(m_ControlCode, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labSlaveCode = new wxStaticText( m_ServicePanel, wxID_ANY, _("Slave code"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer100->Add(m_labSlaveCode, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_SlaveCode = new wxTextCtrl( m_ServicePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer100->Add(m_SlaveCode, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemFlexGridSizer100->AddGrowableCol(1);

    wxFlexGridSizer* itemFlexGridSizer109 = new wxFlexGridSizer(0, 1, 0, 0);
    m_ClientBox->Add(itemFlexGridSizer109, 0, wxGROW, 5);
    m_OnlyFirstMaster = new wxCheckBox( m_ServicePanel, wxID_ANY, _("Only first is master"), wxDefaultPosition, wxDefaultSize, 0 );
    m_OnlyFirstMaster->SetValue(false);
    itemFlexGridSizer109->Add(m_OnlyFirstMaster, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxStaticLine* itemStaticLine111 = new wxStaticLine( m_ServicePanel, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    itemBoxSizer81->Add(itemStaticLine111, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer112 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer81->Add(itemBoxSizer112, 0, wxALIGN_TOP|wxALL, 5);
    m_SrcpService = new wxStaticBox(m_ServicePanel, wxID_ANY, _("SRCP Service"));
    wxStaticBoxSizer* itemStaticBoxSizer113 = new wxStaticBoxSizer(m_SrcpService, wxVERTICAL);
    itemBoxSizer112->Add(itemStaticBoxSizer113, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 5);
    wxFlexGridSizer* itemFlexGridSizer114 = new wxFlexGridSizer(0, 3, 0, 0);
    itemStaticBoxSizer113->Add(itemFlexGridSizer114, 0, wxGROW, 5);
    m_labSrcpPort = new wxStaticText( m_ServicePanel, wxID_ANY, _("port"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer114->Add(m_labSrcpPort, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SrcpPort = new wxSpinCtrl( m_ServicePanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 0, 65536, 0 );
    itemFlexGridSizer114->Add(m_SrcpPort, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SrcpServiceActive = new wxCheckBox( m_ServicePanel, wxID_ANY, _("Active"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SrcpServiceActive->SetValue(false);
    itemFlexGridSizer114->Add(m_SrcpServiceActive, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer118 = new wxFlexGridSizer(0, 2, 0, 0);
    itemStaticBoxSizer113->Add(itemFlexGridSizer118, 0, wxGROW, 5);
    m_labSRCPDevice = new wxStaticText( m_ServicePanel, wxID_ANY, _("device"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer118->Add(m_labSRCPDevice, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_SRCPDeviceStrings;
    m_SRCPDevice = new wxComboBox( m_ServicePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_SRCPDeviceStrings, wxCB_DROPDOWN );
    itemFlexGridSizer118->Add(m_SRCPDevice, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer118->AddGrowableCol(1);

    m_SNMPBox = new wxStaticBox(m_ServicePanel, wxID_ANY, _("SNMP Service"));
    wxStaticBoxSizer* itemStaticBoxSizer121 = new wxStaticBoxSizer(m_SNMPBox, wxVERTICAL);
    itemBoxSizer112->Add(itemStaticBoxSizer121, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 5);
    wxFlexGridSizer* itemFlexGridSizer122 = new wxFlexGridSizer(0, 3, 0, 0);
    itemStaticBoxSizer121->Add(itemFlexGridSizer122, 0, wxGROW, 5);
    m_labSnmpPort = new wxStaticText( m_ServicePanel, wxID_ANY, _("port"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer122->Add(m_labSnmpPort, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SnmpPort = new wxSpinCtrl( m_ServicePanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 0, 65536, 0 );
    itemFlexGridSizer122->Add(m_SnmpPort, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SnmpServiceActive = new wxCheckBox( m_ServicePanel, wxID_ANY, _("Active"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SnmpServiceActive->SetValue(false);
    itemFlexGridSizer122->Add(m_SnmpServiceActive, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SNMPTrapBox = new wxStaticBox(m_ServicePanel, wxID_ANY, _("Trap"));
    wxStaticBoxSizer* itemStaticBoxSizer126 = new wxStaticBoxSizer(m_SNMPTrapBox, wxVERTICAL);
    itemStaticBoxSizer121->Add(itemStaticBoxSizer126, 0, wxGROW|wxLEFT|wxRIGHT|wxBOTTOM, 5);
    wxFlexGridSizer* itemFlexGridSizer127 = new wxFlexGridSizer(0, 4, 0, 0);
    itemStaticBoxSizer126->Add(itemFlexGridSizer127, 0, wxGROW, 5);
    m_labSnmpTrapHost = new wxStaticText( m_ServicePanel, wxID_ANY, _("Host"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer127->Add(m_labSnmpTrapHost, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SnmpTrapHost = new wxTextCtrl( m_ServicePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(160, -1), 0 );
    itemFlexGridSizer127->Add(m_SnmpTrapHost, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labSnmpTrapPort = new wxStaticText( m_ServicePanel, wxID_ANY, _("Port"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer127->Add(m_labSnmpTrapPort, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SnmpTrapPort = new wxSpinCtrl( m_ServicePanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 0, 65536, 0 );
    itemFlexGridSizer127->Add(m_SnmpTrapPort, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_RRNotebook->AddPage(m_ServicePanel, _("Service"));

    m_AtomatPanel = new wxPanel( m_RRNotebook, ID_PANEL_RR_AUTO, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer133 = new wxBoxSizer(wxHORIZONTAL);
    m_AtomatPanel->SetSizer(itemBoxSizer133);

    wxBoxSizer* itemBoxSizer134 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer133->Add(itemBoxSizer134, 0, wxALIGN_TOP|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer135 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer134->Add(itemFlexGridSizer135, 0, wxGROW, 5);
    m_LabelSwTime = new wxStaticText( m_AtomatPanel, wxID_STATIC_RR_SWTIME, _("Switch time"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer135->Add(m_LabelSwTime, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_SwTime = new wxTextCtrl( m_AtomatPanel, ID_TEXTCTRL_RR_SWTIME, _("0"), wxDefaultPosition, wxSize(80, -1), wxTE_CENTRE );
    itemFlexGridSizer135->Add(m_SwTime, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_LabelMinBKLen = new wxStaticText( m_AtomatPanel, wxID_STATIC__MINBKLEN, _("Min Block length"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer135->Add(m_LabelMinBKLen, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_MinBKLen = new wxTextCtrl( m_AtomatPanel, ID_TEXTCTRL_RR_MINBKLEN, _("0"), wxDefaultPosition, wxSize(80, -1), wxTE_CENTRE );
    itemFlexGridSizer135->Add(m_MinBKLen, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_LabelIgnEvt = new wxStaticText( m_AtomatPanel, wxID_STATIC_RR_IGNEVT, _("Ignore dup. sensor events"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer135->Add(m_LabelIgnEvt, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_IgnEvt = new wxTextCtrl( m_AtomatPanel, ID_TEXTCTRL_RR_IGNEVT, _("0"), wxDefaultPosition, wxSize(80, -1), wxTE_CENTRE );
    itemFlexGridSizer135->Add(m_IgnEvt, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_labInitPause = new wxStaticText( m_AtomatPanel, wxID_STATIC_RR_INITPAUSE, _("Initfield pause"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer135->Add(m_labInitPause, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_PauseInit = new wxTextCtrl( m_AtomatPanel, ID_TEXTCTRL_RR_PAUSEINIT, _("0"), wxDefaultPosition, wxSize(80, -1), wxTE_CENTRE );
    itemFlexGridSizer135->Add(m_PauseInit, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_labInitPower = new wxStaticText( m_AtomatPanel, wxID_ANY, _("Initfield power on"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer135->Add(m_labInitPower, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_InitfieldPower = new wxCheckBox( m_AtomatPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_InitfieldPower->SetValue(false);
    itemFlexGridSizer135->Add(m_InitfieldPower, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labSeed = new wxStaticText( m_AtomatPanel, wxID_ANY, _("Random seed"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer135->Add(m_labSeed, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_Seed = new wxSpinCtrl( m_AtomatPanel, wxID_ANY, wxT("4711"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 65535, 4711 );
    itemFlexGridSizer135->Add(m_Seed, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labSavePosTime = new wxStaticText( m_AtomatPanel, wxID_ANY, _("Save position time"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer135->Add(m_labSavePosTime, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_SavePosTime = new wxSpinCtrl( m_AtomatPanel, wxID_ANY, wxT("10"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 100, 10 );
    itemFlexGridSizer135->Add(m_SavePosTime, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labEventTimeout = new wxStaticText( m_AtomatPanel, wxID_ANY, _("Event timeout"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer135->Add(m_labEventTimeout, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_EventTimeout = new wxSpinCtrl( m_AtomatPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 65535, 0 );
    itemFlexGridSizer135->Add(m_EventTimeout, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labSignalReset = new wxStaticText( m_AtomatPanel, wxID_ANY, _("Signal reset"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer135->Add(m_labSignalReset, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_SignalReset = new wxSpinCtrl( m_AtomatPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 30, 0 );
    itemFlexGridSizer135->Add(m_SignalReset, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labRouteSwTime = new wxStaticText( m_AtomatPanel, wxID_ANY, _("Route switch time"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer135->Add(m_labRouteSwTime, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_RouteSwTime = new wxSpinCtrl( m_AtomatPanel, wxID_ANY, wxT("10"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 10, 10000, 10 );
    itemFlexGridSizer135->Add(m_RouteSwTime, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labSemaphoreWait = new wxStaticText( m_AtomatPanel, wxID_ANY, _("Semaphore wait"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer135->Add(m_labSemaphoreWait, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_SemaphoreWait = new wxSpinCtrl( m_AtomatPanel, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 30, 1 );
    itemFlexGridSizer135->Add(m_SemaphoreWait, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labSignalWait = new wxStaticText( m_AtomatPanel, wxID_ANY, _("Signal wait"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer135->Add(m_labSignalWait, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_SignalWait = new wxSpinCtrl( m_AtomatPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 30, 0 );
    itemFlexGridSizer135->Add(m_SignalWait, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labLocoStartGap = new wxStaticText( m_AtomatPanel, wxID_ANY, _("Loco start gap"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer135->Add(m_labLocoStartGap, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_LocoStartGap = new wxSpinCtrl( m_AtomatPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 100, 0 );
    itemFlexGridSizer135->Add(m_LocoStartGap, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labBlockInitPause = new wxStaticText( m_AtomatPanel, wxID_ANY, _("Block init pause"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer135->Add(m_labBlockInitPause, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_BlockInitPause = new wxSpinCtrl( m_AtomatPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 5000, 0 );
    itemFlexGridSizer135->Add(m_BlockInitPause, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labSyncRouteTimeout = new wxStaticText( m_AtomatPanel, wxID_ANY, _("Sync route timeout"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer135->Add(m_labSyncRouteTimeout, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_SyncRouteTimeout = new wxSpinCtrl( m_AtomatPanel, wxID_ANY, wxT("2500"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 100, 10000, 2500 );
    itemFlexGridSizer135->Add(m_SyncRouteTimeout, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labVirtualTimer = new wxStaticText( m_AtomatPanel, wxID_ANY, _("Virtual timer"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer135->Add(m_labVirtualTimer, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_VirtualTimer = new wxSpinCtrl( m_AtomatPanel, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 1, 60, 1 );
    itemFlexGridSizer135->Add(m_VirtualTimer, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    itemFlexGridSizer135->AddGrowableCol(1);

    wxStaticLine* itemStaticLine168 = new wxStaticLine( m_AtomatPanel, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    itemBoxSizer133->Add(itemStaticLine168, 0, wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer169 = new wxFlexGridSizer(0, 1, 0, 0);
    itemBoxSizer133->Add(itemFlexGridSizer169, 0, wxALIGN_TOP, 5);
    m_secondNextBlock = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Reserve second next block"), wxDefaultPosition, wxDefaultSize, 0 );
    m_secondNextBlock->SetValue(false);
    itemFlexGridSizer169->Add(m_secondNextBlock, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_EnableSwFb = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Enable Switch Feedback"), wxDefaultPosition, wxDefaultSize, 0 );
    m_EnableSwFb->SetValue(false);
    itemFlexGridSizer169->Add(m_EnableSwFb, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_DisableRouteVreduce = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Disable route speed reduce"), wxDefaultPosition, wxDefaultSize, 0 );
    m_DisableRouteVreduce->SetValue(false);
    itemFlexGridSizer169->Add(m_DisableRouteVreduce, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_SkipSetSw = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Skip switch commands in routes if already set"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SkipSetSw->SetValue(false);
    itemFlexGridSizer169->Add(m_SkipSetSw, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_SkipSetSg = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Skip signal commands if already set"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SkipSetSg->SetValue(false);
    itemFlexGridSizer169->Add(m_SkipSetSg, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_UseBiCom = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Use Bi-Directional Communication"), wxDefaultPosition, wxDefaultSize, 0 );
    m_UseBiCom->SetValue(false);
    itemFlexGridSizer169->Add(m_UseBiCom, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_CreateGuestOnBiDi = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Create guest on BiDi"), wxDefaultPosition, wxDefaultSize, 0 );
    m_CreateGuestOnBiDi->SetValue(false);
    itemFlexGridSizer169->Add(m_CreateGuestOnBiDi, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_UseBiDiDirection = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Use BiDi direction"), wxDefaultPosition, wxDefaultSize, 0 );
    m_UseBiDiDirection->SetValue(false);
    itemFlexGridSizer169->Add(m_UseBiDiDirection, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_UseIdent = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Use identifier to set in block"), wxDefaultPosition, wxDefaultSize, 0 );
    m_UseIdent->SetValue(false);
    itemFlexGridSizer169->Add(m_UseIdent, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_StopAtIdentMisMatch = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("power off at ident mismatch "), wxDefaultPosition, wxDefaultSize, 0 );
    m_StopAtIdentMisMatch->SetValue(false);
    itemFlexGridSizer169->Add(m_StopAtIdentMisMatch, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_PowerOffAtGhost = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Power off at ghost"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PowerOffAtGhost->SetValue(false);
    itemFlexGridSizer169->Add(m_PowerOffAtGhost, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_EBreakAtGhost = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("EBreak at ghost"), wxDefaultPosition, wxDefaultSize, 0 );
    m_EBreakAtGhost->SetValue(false);
    itemFlexGridSizer169->Add(m_EBreakAtGhost, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_KeepGhost = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Keep ghost state"), wxDefaultPosition, wxDefaultSize, 0 );
    m_KeepGhost->SetValue(false);
    itemFlexGridSizer169->Add(m_KeepGhost, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_DisableSteal = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Disable steal loco control"), wxDefaultPosition, wxDefaultSize, 0 );
    m_DisableSteal->SetValue(false);
    itemFlexGridSizer169->Add(m_DisableSteal, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_PowerOffAtReset = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("power off at reset"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PowerOffAtReset->SetValue(true);
    itemFlexGridSizer169->Add(m_PowerOffAtReset, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_ZeroThrottleID = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Allow zero throttle ID"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ZeroThrottleID->SetValue(false);
    itemFlexGridSizer169->Add(m_ZeroThrottleID, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_StopNoneCommuter = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Stop none commuter in terminal"), wxDefaultPosition, wxDefaultSize, 0 );
    m_StopNoneCommuter->SetValue(false);
    itemFlexGridSizer169->Add(m_StopNoneCommuter, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_SyncRoutes = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Synchronize routes"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SyncRoutes->SetValue(false);
    itemFlexGridSizer169->Add(m_SyncRoutes, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_TimedSensors = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Timed sensors"), wxDefaultPosition, wxDefaultSize, 0 );
    m_TimedSensors->SetValue(false);
    itemFlexGridSizer169->Add(m_TimedSensors, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_EnableAnalyzer = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Enable analyzer"), wxDefaultPosition, wxDefaultSize, 0 );
    m_EnableAnalyzer->SetValue(true);
    itemFlexGridSizer169->Add(m_EnableAnalyzer, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_ForceUnlock = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Force unlock at EBreak"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ForceUnlock->SetValue(false);
    itemFlexGridSizer169->Add(m_ForceUnlock, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_ReleaseOnIdle = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Release Loco on idle"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ReleaseOnIdle->SetValue(false);
    itemFlexGridSizer169->Add(m_ReleaseOnIdle, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_CloseOnGhost = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Close on ghost"), wxDefaultPosition, wxDefaultSize, 0 );
    m_CloseOnGhost->SetValue(false);
    itemFlexGridSizer169->Add(m_CloseOnGhost, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxStaticLine* itemStaticLine193 = new wxStaticLine( m_AtomatPanel, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
    itemBoxSizer133->Add(itemStaticLine193, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer194 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer133->Add(itemBoxSizer194, 0, wxALIGN_TOP|wxALL, 5);
    m_UseOnlyFirstIdent = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Use only the first identifier "), wxDefaultPosition, wxDefaultSize, 0 );
    m_UseOnlyFirstIdent->SetValue(false);
    itemBoxSizer194->Add(m_UseOnlyFirstIdent, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_ActionTimer60 = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Action timer 60 sec."), wxDefaultPosition, wxDefaultSize, 0 );
    m_ActionTimer60->SetValue(true);
    itemBoxSizer194->Add(m_ActionTimer60, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_RestoreSchedule = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Restore schedule"), wxDefaultPosition, wxDefaultSize, 0 );
    m_RestoreSchedule->SetValue(false);
    itemBoxSizer194->Add(m_RestoreSchedule, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_SelectShortestBlock = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Select shortest block"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SelectShortestBlock->SetValue(false);
    itemBoxSizer194->Add(m_SelectShortestBlock, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_CloseNoEvents = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Close on no events"), wxDefaultPosition, wxDefaultSize, 0 );
    m_CloseNoEvents->SetValue(true);
    itemBoxSizer194->Add(m_CloseNoEvents, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_DisableBlockWait4GoManual = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Disable block wait for half automatic mode"), wxDefaultPosition, wxDefaultSize, 0 );
    m_DisableBlockWait4GoManual->SetValue(false);
    itemBoxSizer194->Add(m_DisableBlockWait4GoManual, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_StopAtIn4GoManual = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Stop at IN for half automatic mode"), wxDefaultPosition, wxDefaultSize, 0 );
    m_StopAtIn4GoManual->SetValue(false);
    itemBoxSizer194->Add(m_StopAtIn4GoManual, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_V0AtPowerOn = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Send zero speed at power on"), wxDefaultPosition, wxDefaultSize, 0 );
    m_V0AtPowerOn->SetValue(false);
    itemBoxSizer194->Add(m_V0AtPowerOn, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_GreenAspect = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Green aspect if next is red"), wxDefaultPosition, wxDefaultSize, 0 );
    m_GreenAspect->SetValue(false);
    itemBoxSizer194->Add(m_GreenAspect, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    wxArrayString m_DefAspectStrings;
    m_DefAspectStrings.Add(_("&red"));
    m_DefAspectStrings.Add(_("&green"));
    m_DefAspectStrings.Add(_("&yellow"));
    m_DefAspectStrings.Add(_("&white"));
    m_DefAspect = new wxRadioBox( m_AtomatPanel, wxID_ANY, _("Default Signal Aspect"), wxDefaultPosition, wxDefaultSize, m_DefAspectStrings, 1, wxRA_SPECIFY_ROWS );
    m_DefAspect->SetSelection(0);
    itemBoxSizer194->Add(m_DefAspect, 0, wxALIGN_LEFT|wxALL, 5);

    m_ResetFxSp = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Reset Speed and Functions"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ResetFxSp->SetValue(false);
    itemBoxSizer194->Add(m_ResetFxSp, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_ProcessSignalEvents = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Process signal events"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ProcessSignalEvents->SetValue(false);
    itemBoxSizer194->Add(m_ProcessSignalEvents, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_UseRandomRate = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Use random block rate"), wxDefaultPosition, wxDefaultSize, 0 );
    m_UseRandomRate->SetValue(false);
    itemBoxSizer194->Add(m_UseRandomRate, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_RedirectToMaster = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Redirect commands to the master loco"), wxDefaultPosition, wxDefaultSize, 0 );
    m_RedirectToMaster->SetValue(true);
    itemBoxSizer194->Add(m_RedirectToMaster, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_Weather = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("Weather"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Weather->SetValue(true);
    itemBoxSizer194->Add(m_Weather, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_V0OnEbreak = new wxCheckBox( m_AtomatPanel, wxID_ANY, _("V 0 on emergency break"), wxDefaultPosition, wxDefaultSize, 0 );
    m_V0OnEbreak->SetValue(false);
    itemBoxSizer194->Add(m_V0OnEbreak, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_RRNotebook->AddPage(m_AtomatPanel, _("Automat"));

    m_ControllersPanel = new wxPanel( m_RRNotebook, ID_PANEL_RR_CONTROLLERS, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer212 = new wxBoxSizer(wxVERTICAL);
    m_ControllersPanel->SetSizer(itemBoxSizer212);

    wxArrayString m_ControllersStrings;
    m_Controllers = new wxListBox( m_ControllersPanel, ID_LISTBOX_RR_CONTROLLERS, wxDefaultPosition, wxDefaultSize, m_ControllersStrings, wxLB_SINGLE );
    itemBoxSizer212->Add(m_Controllers, 1, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer214 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer212->Add(itemBoxSizer214, 0, wxGROW|wxALL, 5);
    m_ControllerDelete = new wxButton( m_ControllersPanel, ID_BUTTON_RR_DELETE, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer214->Add(m_ControllerDelete, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ControllerProps = new wxButton( m_ControllersPanel, ID_BUTTON_RR_PROPS, _("Properties"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer214->Add(m_ControllerProps, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Default = new wxButton( m_ControllersPanel, ID_BUTTON_RR_DEFAULT, _("Default"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer214->Add(m_Default, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer218Static = new wxStaticBox(m_ControllersPanel, wxID_ANY, _("Add Controller"));
    m_AddControllerBox = new wxStaticBoxSizer(itemStaticBoxSizer218Static, wxHORIZONTAL);
    itemBoxSizer212->Add(m_AddControllerBox, 0, wxGROW|wxALL, 5);
    wxArrayString m_LibStrings;
    m_Lib = new wxComboBox( m_ControllersPanel, ID_COMBOBOX_RR_LIB, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_LibStrings, wxCB_DROPDOWN );
    m_AddControllerBox->Add(m_Lib, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ControllerAdd = new wxButton( m_ControllersPanel, ID_BUTTON_RR_ADD, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
    m_AddControllerBox->Add(m_ControllerAdd, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ControllerOptionsBox = new wxStaticBox(m_ControllersPanel, wxID_ANY, _("Options"));
    wxStaticBoxSizer* itemStaticBoxSizer221 = new wxStaticBoxSizer(m_ControllerOptionsBox, wxVERTICAL);
    itemBoxSizer212->Add(itemStaticBoxSizer221, 0, wxGROW|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer222 = new wxFlexGridSizer(0, 4, 0, 0);
    itemStaticBoxSizer221->Add(itemFlexGridSizer222, 0, wxGROW, 5);
    m_PowerOffOnExit = new wxCheckBox( m_ControllersPanel, wxID_ANY, _("Power off on exit"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PowerOffOnExit->SetValue(false);
    itemFlexGridSizer222->Add(m_PowerOffOnExit, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_PowerOnAtInit = new wxCheckBox( m_ControllersPanel, wxID_ANY, _("Power on at init"), wxDefaultPosition, wxDefaultSize, 0 );
    m_PowerOnAtInit->SetValue(false);
    itemFlexGridSizer222->Add(m_PowerOnAtInit, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Shutdown = new wxCheckBox( m_ControllersPanel, wxID_ANY, _("Shutdown on exit"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Shutdown->SetValue(false);
    itemFlexGridSizer222->Add(m_Shutdown, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_NoDevCheck = new wxCheckBox( m_ControllersPanel, wxID_ANY, _("No device check"), wxDefaultPosition, wxDefaultSize, 0 );
    m_NoDevCheck->SetValue(false);
    itemFlexGridSizer222->Add(m_NoDevCheck, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_RRNotebook->AddPage(m_ControllersPanel, _("Controllers"));

    m_R2RnetPanel = new wxPanel( m_RRNotebook, ID_PANEL_R2RNET, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer228 = new wxBoxSizer(wxVERTICAL);
    m_R2RnetPanel->SetSizer(itemBoxSizer228);

    wxFlexGridSizer* itemFlexGridSizer229 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer228->Add(itemFlexGridSizer229, 0, wxGROW|wxALL, 5);
    m_labR2RnetID = new wxStaticText( m_R2RnetPanel, wxID_ANY, _("ID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer229->Add(m_labR2RnetID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_R2RnetID = new wxTextCtrl( m_R2RnetPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer229->Add(m_R2RnetID, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labR2RnetAddr = new wxStaticText( m_R2RnetPanel, wxID_ANY, _("Address"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer229->Add(m_labR2RnetAddr, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_R2RnetAddr = new wxTextCtrl( m_R2RnetPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer229->Add(m_R2RnetAddr, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labR2RnetPort = new wxStaticText( m_R2RnetPanel, wxID_ANY, _("Port"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer229->Add(m_labR2RnetPort, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_R2RnetPort = new wxSpinCtrl( m_R2RnetPanel, wxID_ANY, wxT("1234"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 65535, 1234 );
    itemFlexGridSizer229->Add(m_R2RnetPort, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer229->AddGrowableCol(1);

    wxFlexGridSizer* itemFlexGridSizer236 = new wxFlexGridSizer(0, 3, 0, 0);
    itemBoxSizer228->Add(itemFlexGridSizer236, 0, wxGROW|wxALL, 5);
    m_labR2RnetRoutes = new wxStaticText( m_R2RnetPanel, wxID_ANY, _("Routes file"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer236->Add(m_labR2RnetRoutes, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_R2RnetRoutes = new wxTextCtrl( m_R2RnetPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer236->Add(m_R2RnetRoutes, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_R2RnetRoutesDlg = new wxButton( m_R2RnetPanel, ID_BUTTON_R2RNET_ROUTES, _("..."), wxDefaultPosition, wxSize(30, 25), 0 );
    itemFlexGridSizer236->Add(m_R2RnetRoutesDlg, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer236->AddGrowableCol(1);

    m_R2RnetEnable = new wxCheckBox( m_R2RnetPanel, wxID_ANY, _("Enable"), wxDefaultPosition, wxDefaultSize, 0 );
    m_R2RnetEnable->SetValue(false);
    itemBoxSizer228->Add(m_R2RnetEnable, 0, wxALIGN_LEFT|wxALL, 5);

    m_RRNotebook->AddPage(m_R2RnetPanel, _("R2Rnet"));

    m_AnalyserPanel = new wxPanel( m_RRNotebook, ID_PANEL_ANALYSER, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer242 = new wxBoxSizer(wxVERTICAL);
    m_AnalyserPanel->SetSizer(itemBoxSizer242);

    wxFlexGridSizer* itemFlexGridSizer243 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer242->Add(itemFlexGridSizer243, 0, wxGROW, 5);
    m_AnaGenerate = new wxStaticBox(m_AnalyserPanel, wxID_ANY, _("Analyze"));
    wxStaticBoxSizer* itemStaticBoxSizer244 = new wxStaticBoxSizer(m_AnaGenerate, wxVERTICAL);
    itemFlexGridSizer243->Add(itemStaticBoxSizer244, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);
    m_SetRouteId = new wxCheckBox( m_AnalyserPanel, wxID_ANY, _("Set routeid for all automatic detected routes"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SetRouteId->SetValue(false);
    itemStaticBoxSizer244->Add(m_SetRouteId, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_SetBlockId = new wxCheckBox( m_AnalyserPanel, wxID_ANY, _("Set blockid for all blocks"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SetBlockId->SetValue(false);
    itemStaticBoxSizer244->Add(m_SetBlockId, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_AddSignalBlockAssignment = new wxCheckBox( m_AnalyserPanel, wxID_ANY, _("Assign signals to blocks"), wxDefaultPosition, wxDefaultSize, 0 );
    m_AddSignalBlockAssignment->SetValue(false);
    itemStaticBoxSizer244->Add(m_AddSignalBlockAssignment, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_AddFeedbackBlockAssignment = new wxCheckBox( m_AnalyserPanel, wxID_ANY, _("Assign feedbacks to blocks"), wxDefaultPosition, wxDefaultSize, 0 );
    m_AddFeedbackBlockAssignment->SetValue(false);
    itemStaticBoxSizer244->Add(m_AddFeedbackBlockAssignment, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_AnaClean = new wxStaticBox(m_AnalyserPanel, wxID_ANY, _("Clean all Analyze"));
    wxStaticBoxSizer* itemStaticBoxSizer249 = new wxStaticBoxSizer(m_AnaClean, wxVERTICAL);
    itemFlexGridSizer243->Add(itemStaticBoxSizer249, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);
    m_CleanRouteId = new wxCheckBox( m_AnalyserPanel, wxID_ANY, _("Clean routeid of all automatic detected routes"), wxDefaultPosition, wxDefaultSize, 0 );
    m_CleanRouteId->SetValue(false);
    itemStaticBoxSizer249->Add(m_CleanRouteId, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_ResetBlockId = new wxCheckBox( m_AnalyserPanel, wxID_ANY, _("Reset blockid in whole plan"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ResetBlockId->SetValue(false);
    itemStaticBoxSizer249->Add(m_ResetBlockId, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_ResetSignalBlockAssignment = new wxCheckBox( m_AnalyserPanel, wxID_ANY, _("Reset signal assignments in all blocks"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ResetSignalBlockAssignment->SetValue(false);
    itemStaticBoxSizer249->Add(m_ResetSignalBlockAssignment, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_ResetFeedbackBlockAssignment = new wxCheckBox( m_AnalyserPanel, wxID_ANY, _("Reset feedback assignments in all blocks"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ResetFeedbackBlockAssignment->SetValue(false);
    itemStaticBoxSizer249->Add(m_ResetFeedbackBlockAssignment, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_AnaCheck = new wxStaticBox(m_AnalyserPanel, wxID_ANY, _("Extended plan check"));
    wxStaticBoxSizer* itemStaticBoxSizer254 = new wxStaticBoxSizer(m_AnaCheck, wxVERTICAL);
    itemFlexGridSizer243->Add(itemStaticBoxSizer254, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);
    m_BasicCheck = new wxCheckBox( m_AnalyserPanel, wxID_ANY, _("Basic checks on all items"), wxDefaultPosition, wxDefaultSize, 0 );
    m_BasicCheck->SetValue(false);
    itemStaticBoxSizer254->Add(m_BasicCheck, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_BlockCheck = new wxCheckBox( m_AnalyserPanel, wxID_ANY, _("Checks concerning blocks"), wxDefaultPosition, wxDefaultSize, 0 );
    m_BlockCheck->SetValue(false);
    itemStaticBoxSizer254->Add(m_BlockCheck, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_RouteCheck = new wxCheckBox( m_AnalyserPanel, wxID_ANY, _("Check concerning routes"), wxDefaultPosition, wxDefaultSize, 0 );
    m_RouteCheck->SetValue(false);
    itemStaticBoxSizer254->Add(m_RouteCheck, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_ActionCheck = new wxCheckBox( m_AnalyserPanel, wxID_ANY, _("Check actions and conditions"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ActionCheck->SetValue(false);
    itemStaticBoxSizer254->Add(m_ActionCheck, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_AnaReset = new wxStaticBox(m_AnalyserPanel, wxID_ANY, _("Extended plan clean"));
    wxStaticBoxSizer* itemStaticBoxSizer259 = new wxStaticBoxSizer(m_AnaReset, wxVERTICAL);
    itemFlexGridSizer243->Add(itemStaticBoxSizer259, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);
    m_BasicClean = new wxCheckBox( m_AnalyserPanel, wxID_ANY, _("Clean basic problems on all items"), wxDefaultPosition, wxDefaultSize, 0 );
    m_BasicClean->SetValue(false);
    itemStaticBoxSizer259->Add(m_BasicClean, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_BlockClean = new wxCheckBox( m_AnalyserPanel, wxID_ANY, _("Clean block problems"), wxDefaultPosition, wxDefaultSize, 0 );
    m_BlockClean->SetValue(false);
    itemStaticBoxSizer259->Add(m_BlockClean, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_RouteClean = new wxCheckBox( m_AnalyserPanel, wxID_ANY, _("Clean route problems"), wxDefaultPosition, wxDefaultSize, 0 );
    m_RouteClean->SetValue(false);
    itemStaticBoxSizer259->Add(m_RouteClean, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    m_ActionClean = new wxCheckBox( m_AnalyserPanel, wxID_ANY, _("Clean action and condition problems"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ActionClean->SetValue(false);
    itemStaticBoxSizer259->Add(m_ActionClean, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_RRNotebook->AddPage(m_AnalyserPanel, _("Analyser"));

    m_RocWebPanel = new wxPanel( m_RRNotebook, ID_PANEL_ROCWEB, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer265 = new wxBoxSizer(wxVERTICAL);
    m_RocWebPanel->SetSizer(itemBoxSizer265);

    wxStaticBox* itemStaticBoxSizer266Static = new wxStaticBox(m_RocWebPanel, wxID_ANY, _("Web Service"));
    m_WebServiceBox = new wxStaticBoxSizer(itemStaticBoxSizer266Static, wxVERTICAL);
    itemBoxSizer265->Add(m_WebServiceBox, 0, wxGROW|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer267 = new wxFlexGridSizer(0, 5, 0, 0);
    m_WebServiceBox->Add(itemFlexGridSizer267, 0, wxALIGN_LEFT, 5);
    m_LabWebServicePort = new wxStaticText( m_RocWebPanel, wxID_ANY, _("Port"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer267->Add(m_LabWebServicePort, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_WebServicePort = new wxSpinCtrl( m_RocWebPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(120, -1), wxSP_ARROW_KEYS, 0, 65535, 0 );
    itemFlexGridSizer267->Add(m_WebServicePort, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer270 = new wxFlexGridSizer(0, 3, 0, 0);
    m_WebServiceBox->Add(itemFlexGridSizer270, 0, wxGROW, 5);
    m_labWebPath = new wxStaticText( m_RocWebPanel, wxID_ANY, _("Path"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer270->Add(m_labWebPath, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_WebPath = new wxTextCtrl( m_RocWebPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer270->Add(m_WebPath, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM, 5);

    m_WebPathDlg = new wxButton( m_RocWebPanel, ID_ROCWEB_WEB_BUTTON, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemFlexGridSizer270->Add(m_WebPathDlg, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer270->AddGrowableCol(1);

    wxStaticBox* itemStaticBoxSizer274Static = new wxStaticBox(m_RocWebPanel, wxID_ANY, _("SVG"));
    wxStaticBoxSizer* itemStaticBoxSizer274 = new wxStaticBoxSizer(itemStaticBoxSizer274Static, wxVERTICAL);
    itemBoxSizer265->Add(itemStaticBoxSizer274, 0, wxGROW|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer275 = new wxFlexGridSizer(0, 3, 0, 0);
    itemStaticBoxSizer274->Add(itemFlexGridSizer275, 0, wxGROW|wxALL, 5);
    m_labTheme1 = new wxStaticText( m_RocWebPanel, wxID_ANY, _("Theme 1"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer275->Add(m_labTheme1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SVGPath = new wxTextCtrl( m_RocWebPanel, wxID_ANY, _("."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer275->Add(m_SVGPath, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_SvgPathDlg = new wxButton( m_RocWebPanel, ID_ROCWEB_SVGPATH_BUTTON, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemFlexGridSizer275->Add(m_SvgPathDlg, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labTheme2 = new wxStaticText( m_RocWebPanel, wxID_ANY, _("Theme 2"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer275->Add(m_labTheme2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SVGPath2 = new wxTextCtrl( m_RocWebPanel, wxID_ANY, _("."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer275->Add(m_SVGPath2, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_SvgPath2Dlg = new wxButton( m_RocWebPanel, ID_ROCWEB_SVGPATH2_BUTTON, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemFlexGridSizer275->Add(m_SvgPath2Dlg, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labTheme3 = new wxStaticText( m_RocWebPanel, wxID_ANY, _("Theme 3"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer275->Add(m_labTheme3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SVGPath3 = new wxTextCtrl( m_RocWebPanel, wxID_ANY, _("."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer275->Add(m_SVGPath3, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_SvgPath3Dlg = new wxButton( m_RocWebPanel, ID_ROCWEB_SVGPATH3_BUTTON, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemFlexGridSizer275->Add(m_SvgPath3Dlg, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labTheme4 = new wxStaticText( m_RocWebPanel, wxID_ANY, _("Theme 4"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer275->Add(m_labTheme4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SVGPath4 = new wxTextCtrl( m_RocWebPanel, wxID_ANY, _("."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer275->Add(m_SVGPath4, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_SvgPath4Dlg = new wxButton( m_RocWebPanel, ID_ROCWEB_SVGPATH4_BUTTON, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemFlexGridSizer275->Add(m_SvgPath4Dlg, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_labTheme5 = new wxStaticText( m_RocWebPanel, wxID_ANY, _("Theme 5"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer275->Add(m_labTheme5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SVGPath5 = new wxTextCtrl( m_RocWebPanel, wxID_ANY, _("."), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer275->Add(m_SVGPath5, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxBOTTOM, 5);

    m_SvgPath5Dlg = new wxButton( m_RocWebPanel, ID_ROCWEB_SVGPATH5_BUTTON, _("..."), wxDefaultPosition, wxSize(40, 25), 0 );
    itemFlexGridSizer275->Add(m_SvgPath5Dlg, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    itemFlexGridSizer275->AddGrowableCol(1);

    m_RRNotebook->AddPage(m_RocWebPanel, _("RocWeb"));

    itemBoxSizer2->Add(m_RRNotebook, 1, wxGROW|wxALL, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer291 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer291, 0, wxGROW|wxLEFT|wxRIGHT, 5);
    m_OK = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    m_OK->SetDefault();
    itemStdDialogButtonSizer291->AddButton(m_OK);

    m_Cancel = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer291->AddButton(m_Cancel);

    wxButton* itemButton294 = new wxButton( itemDialog1, wxID_HELP, _("&Help"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer291->AddButton(itemButton294);

    itemStdDialogButtonSizer291->Realize();

////@end RocrailIniDialog content construction
}

/*!
 * Should we show tooltips?
 */

bool RocrailIniDialog::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap RocrailIniDialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin RocrailIniDialog bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end RocrailIniDialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon RocrailIniDialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin RocrailIniDialog icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end RocrailIniDialog icon retrieval
}
/*!
 * wxEVT_COMMAND_LISTBOX_SELECTED event handler for ID_LISTBOX_RR_CONTROLLERS
 */

void RocrailIniDialog::OnListboxRrControllersSelected( wxCommandEvent& event )
{
  int sel = m_Controllers->GetSelection();
  if( sel != wxNOT_FOUND ) {
    m_Controller = (iONode)m_Controllers->GetClientData( sel );
  }
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RR_ADD
 */

void RocrailIniDialog::OnButtonRrAddClick( wxCommandEvent& event )
{
  iONode digint = NodeOp.inst( wDigInt.name(), m_Props, ELEMENT_NODE );
  NodeOp.addChild( m_Props, digint );
  wDigInt.setiid( digint, "NEW" );
  wDigInt.setlib( digint, m_Lib->GetStringSelection().mb_str(wxConvUTF8) );
  m_Controller = digint;
  char* val = StrOp.fmt( "%s - %s", wDigInt.getiid( digint ), wDigInt.getlib( digint ) );
  m_Controllers->Append( wxString( val, wxConvUTF8 ), (void*)digint );
  StrOp.free( val );
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RR_DELETE
 */

void RocrailIniDialog::OnButtonRrDeleteClick( wxCommandEvent& event )
{
  int sel = m_Controllers->GetSelection();
  if( sel != wxNOT_FOUND ) {
    m_Controller = (iONode)m_Controllers->GetClientData( sel );
    NodeOp.removeChild( m_Props, m_Controller );
    m_Controller = NULL;
    initControllerList();
  }
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RR_PROPS
 */

void RocrailIniDialog::OnButtonRrPropsClick( wxCommandEvent& event )
{
  m_CSDialog = NULL;
  if( m_Controller == NULL )
    return;

  const char* devices = NULL;
  if( wFreeRail.getdevices(m_Props) != NULL ) {
    devices = wDevices.getserial(wFreeRail.getdevices(m_Props));
  }

  if( StrOp.equals( wDigInt.ddx, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new DDXCtrlDlg(this,m_Controller,devices);
  else if( StrOp.equals( wDigInt.srcp, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new SRCPCtrlDlg(this,m_Controller,devices);
  else if( StrOp.equals( wDigInt.got, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new SRCPCtrlDlg(this,m_Controller,devices);
  else if( StrOp.equals( wDigInt.dinamo, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new DinamoCtrlDlg(this,m_Controller,devices);
  else if( StrOp.equals( wDigInt.hsi88, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new Hsi88CntrlDlg(this,m_Controller,devices);
  else if( StrOp.equals( wDigInt.barjut, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new BarJuTCntrlDlg(this,m_Controller,devices);
  else if( StrOp.equals( wDigInt.loconet, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new LocoNetCtrlDlg(this,m_Controller,devices);
  else if( StrOp.equals( wDigInt.ecos, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new ECoSCtrlDialog(this,m_Controller,devices);
  else if( StrOp.equals( wDigInt.zimocan, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new ECoSCtrlDialog(this,m_Controller,devices);
  else if( StrOp.equals( wDigInt.opendcc, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new OpenDCCCtrlDlg(this,m_Controller, devices);
  else if( StrOp.equals( wDigInt.mcs2, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new ECoSCtrlDialog(this,m_Controller,devices);
  else if( StrOp.equals( wDigInt.mgbox, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new ECoSCtrlDialog(this,m_Controller,devices);
  else if( StrOp.equals( wDigInt.lenz, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new LenzDlg(this,m_Controller, devices);
  else if( StrOp.equals( wDigInt.xpressnet, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new LenzDlg(this,m_Controller, devices);
  else if( StrOp.equals( wDigInt.roco, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new GenericCtrlDlg(this,m_Controller,wDigInt.getlib( m_Controller ), 0, NULL, devices);
  else if( StrOp.equals( wDigInt.sprog, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new BarJuTCntrlDlg(this,m_Controller, devices);
  else if( StrOp.equals( wDigInt.dcc232, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new DCC232Dlg(this,m_Controller, devices);
  else if( StrOp.equals( wDigInt.bidib, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new BidibDlg(this,m_Controller, devices);
  else if( StrOp.equals( wDigInt.cbus, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new CbusDlg(this,m_Controller, devices);
  else if( StrOp.equals( wDigInt.rocnet, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new RocNetDlg(this,m_Controller,devices);
  else if( StrOp.equals( wDigInt.massoth, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new GenericCtrlDlg(this,m_Controller,wDigInt.getlib( m_Controller ), 57600, wDigInt.cts, devices);
  else if( StrOp.equals( wDigInt.z21, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new ECoSCtrlDialog(this,m_Controller,devices);
  else if( StrOp.equals( wDigInt.ucons88, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new uConS88Dlg(this,m_Controller,devices);
  else if( StrOp.equals( wDigInt.spl, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new SplDlg(this,m_Controller, devices);
  else if( StrOp.equals( wDigInt.hue, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new ECoSCtrlDialog(this,m_Controller,devices);
  else if( StrOp.equals( wDigInt.dmxartnet, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new DmxDlg(this,m_Controller);
  else if( StrOp.equals( wDigInt.dmx4all, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new BarJuTCntrlDlg(this,m_Controller, devices);
  else if( StrOp.equals( wDigInt.raptor, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new BarJuTCntrlDlg(this,m_Controller, devices);
  else if( StrOp.equals( wDigInt.dmxeurolite, wDigInt.getlib( m_Controller ) ) )
    m_CSDialog = new BarJuTCntrlDlg(this,m_Controller, devices);
  else
    m_CSDialog = new GenericCtrlDlg(this,m_Controller,wDigInt.getlib( m_Controller ), 0, NULL, devices);

  if( wxID_OK == m_CSDialog->ShowModal() ) {
    initControllerList();
  }
  m_CSDialog->Destroy();
  m_CSDialog = NULL;

}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void RocrailIniDialog::OnOkClick( wxCommandEvent& event )
{
  evaluate();
  /* Notify RocRail. */
  iONode cmd = NodeOp.inst( wSysCmd.name(), NULL, ELEMENT_NODE );
  wSysCmd.setcmd( cmd, wSysCmd.setini );
  NodeOp.addChild( cmd, (iONode)m_Props->base.clone( m_Props ) );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);

  EndModal( wxID_OK );
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void RocrailIniDialog::OnCancelClick( wxCommandEvent& event )
{
  EndModal( 0 );
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_APPLY
 */

/*!
 * wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED event handler for ID_NOTEBOOK_RR
 */

void RocrailIniDialog::OnNotebookRrPageChanged( wxNotebookEvent& event )
{
}



/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_R2RNET_ROUTES
 */

void RocrailIniDialog::OnButtonR2rnetRoutesClick( wxCommandEvent& event )
{
  wxString ms_FileExt = _T("NetRoutes (*.xml)|*.xml");
  const char* l_openpath = ".";
  wxFileDialog* fdlg = new wxFileDialog(this, wxGetApp().getMenu("opennetroutesfile"), wxString(l_openpath,wxConvUTF8) , _T(""), ms_FileExt, wxFD_OPEN);
  if( fdlg->ShowModal() == wxID_OK ) {
    iONode r2rnet = wFreeRail.getr2rnet( m_Props );
    wR2RnetIni.setroutes( r2rnet, fdlg->GetPath().mb_str(wxConvUTF8) );
    m_R2RnetRoutes->SetValue( wxString( wR2RnetIni.getroutes(r2rnet),wxConvUTF8) );
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_KEYPATH
 */

void RocrailIniDialog::OnButtonKeypathClick( wxCommandEvent& event )
{
  wxString ms_FileExt = _T("Key (*.dat)|*.dat");
  const char* l_openpath = ".";
  wxFileDialog* fdlg = new wxFileDialog(this, wxGetApp().getMenu("openkeyfile"), wxString(l_openpath,wxConvUTF8) , _T(""), ms_FileExt, wxFD_OPEN);
  if( fdlg->ShowModal() == wxID_OK ) {
    iONode r2rnet = wFreeRail.getr2rnet( m_Props );
    wFreeRail.setkeypath(m_Props, fdlg->GetPath().mb_str(wxConvUTF8) );
    m_KeyPath->SetValue( wxString( wFreeRail.getkeypath(m_Props),wxConvUTF8) );
  }
}


/*!
 * wxEVT_COMMAND_LISTBOX_DOUBLECLICKED event handler for ID_LISTBOX_RR_CONTROLLERS
 */

void RocrailIniDialog::OnListboxRrControllersDoubleClicked( wxCommandEvent& event )
{
  int sel = m_Controllers->GetSelection();
  if( sel != wxNOT_FOUND ) {
    m_Controller = (iONode)m_Controllers->GetClientData( sel );
    OnButtonRrPropsClick(event);
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_PLANFILE
 */

void RocrailIniDialog::OnButtonPlanfileClick( wxCommandEvent& event )
{
  wxString ms_FileExt = _T("Plan (*.xml)|*.xml");
  const char* l_openpath = ".";
  wxFileDialog* fdlg = new wxFileDialog(this, wxGetApp().getMenu("openplanfile"), wxString(l_openpath,wxConvUTF8) , _T(""), ms_FileExt, wxFD_OPEN);
  if( fdlg->ShowModal() == wxID_OK ) {
    wFreeRail.setplanfile(m_Props, fdlg->GetPath().mb_str(wxConvUTF8) );
    m_PlanFile->SetValue( wxString( wFreeRail.getplanfile(m_Props),wxConvUTF8) );
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_LOCOFILE
 */

void RocrailIniDialog::OnButtonLocofileClick( wxCommandEvent& event )
{
  wxString ms_FileExt = _T("Locos (*.xml)|*.xml");
  const char* l_openpath = ".";
  wxFileDialog* fdlg = new wxFileDialog(this, wxGetApp().getMenu("openlocofile"), wxString(l_openpath,wxConvUTF8) , _T(""), ms_FileExt, wxFD_OPEN);
  if( fdlg->ShowModal() == wxID_OK ) {
    wFreeRail.setlocs(m_Props, fdlg->GetPath().mb_str(wxConvUTF8) );
    m_LocoFile->SetValue( wxString( wFreeRail.getlocs(m_Props),wxConvUTF8) );
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_OCCFILE
 */

void RocrailIniDialog::OnButtonOccfileClick( wxCommandEvent& event )
{
  wxString ms_FileExt = _T("Occ (*.xml)|*.xml");
  const char* l_openpath = ".";
  wxFileDialog* fdlg = new wxFileDialog(this, wxGetApp().getMenu("openoccfile"), wxString(l_openpath,wxConvUTF8) , _T(""), ms_FileExt, wxFD_OPEN);
  if( fdlg->ShowModal() == wxID_OK ) {
    wFreeRail.setoccupancy(m_Props, fdlg->GetPath().mb_str(wxConvUTF8) );
    m_OccFile->SetValue( wxString( wFreeRail.getoccupancy(m_Props),wxConvUTF8) );
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RR_DEFAULT
 */

void RocrailIniDialog::OnButtonRrDefaultClick( wxCommandEvent& event )
{
  if( m_Controllers->GetCount() > 1 ) {
    int sel = m_Controllers->GetSelection();
    if( sel != wxNOT_FOUND && sel > 0) {
      iOList list = ListOp.inst();
      iONode selCtrl = (iONode)m_Controllers->GetClientData( sel );
      ListOp.add(list, (obj)NodeOp.base.clone(selCtrl) );
      NodeOp.removeChild( m_Props, selCtrl );
      NodeOp.base.del(selCtrl);

      iONode controller = wFreeRail.getdigint( m_Props );
      while( controller != NULL ) {
        ListOp.add(list, (obj)NodeOp.base.clone(controller) );
        NodeOp.removeChild( m_Props, controller );
        NodeOp.base.del(controller);
        controller = wFreeRail.getdigint( m_Props );
      };

      for( int i = 0; i < ListOp.size(list); i++ )
        NodeOp.addChild( m_Props, (iONode)ListOp.get(list, i) );

      ListOp.base.del(list);

      m_Controller = NULL;
      initControllerList();
    }
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
 */

void RocrailIniDialog::OnHelpClick( wxCommandEvent& event )
{
  switch( m_RRNotebook->GetSelection() ) {
  case 0: wxGetApp().openLink( "rocrailini-gen" ); break;
  case 1: wxGetApp().openLink( "rocrailini-trace" ); break;
  case 2: wxGetApp().openLink( "rocrailini-service" ); break;
  case 3: wxGetApp().openLink( "rocrailini-automode" ); break;
  case 4: wxGetApp().openLink( "rocrailini-controller" ); break;
  case 5: wxGetApp().openLink( "networking" ); break;
  case 6: wxGetApp().openLink( "rocrailini-analyser" ); break;
  default: wxGetApp().openLink( "rocrailini-gen" ); break;
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SVGPATH2_BUTTON
 */

void RocrailIniDialog::OnSvgPath2Click( wxCommandEvent& event )
{
  wxDirDialog* dlg = new wxDirDialog( this );
  dlg->SetPath(m_SVGPath2->GetValue());
  if( dlg->ShowModal() == wxID_OK ) {
    m_SVGPath2->SetValue( dlg->GetPath() );
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SVGPATH_BUTTON
 */

void RocrailIniDialog::OnSvgPath1Click( wxCommandEvent& event )
{
  wxDirDialog* dlg = new wxDirDialog( this );
  dlg->SetPath(m_SVGPath->GetValue());
  if( dlg->ShowModal() == wxID_OK ) {
    m_SVGPath->SetValue( dlg->GetPath() );
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SVGPATH4_BUTTON
 */

void RocrailIniDialog::OnSvgPath4Click( wxCommandEvent& event )
{
  wxDirDialog* dlg = new wxDirDialog( this );
  dlg->SetPath(m_SVGPath4->GetValue());
  if( dlg->ShowModal() == wxID_OK ) {
    m_SVGPath4->SetValue( dlg->GetPath() );
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SVGPATH5_BUTTON
 */

void RocrailIniDialog::OnSvgPath5Click( wxCommandEvent& event )
{
  wxDirDialog* dlg = new wxDirDialog( this );
  dlg->SetPath(m_SVGPath5->GetValue());
  if( dlg->ShowModal() == wxID_OK ) {
    m_SVGPath5->SetValue( dlg->GetPath() );
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SVGPATH3_BUTTON
 */

void RocrailIniDialog::OnSvgPath3Click( wxCommandEvent& event )
{
  wxDirDialog* dlg = new wxDirDialog( this );
  dlg->SetPath(m_SVGPath3->GetValue());
  if( dlg->ShowModal() == wxID_OK ) {
    m_SVGPath3->SetValue( dlg->GetPath() );
  }
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ROCWEB_WEB_BUTTON
 */

void RocrailIniDialog::OnRocwebWebButtonClick( wxCommandEvent& event )
{
  wxDirDialog* dlg = new wxDirDialog( this );
  dlg->SetPath(m_WebPath->GetValue());
  if( dlg->ShowModal() == wxID_OK ) {
    m_WebPath->SetValue( dlg->GetPath() );
  }
}

