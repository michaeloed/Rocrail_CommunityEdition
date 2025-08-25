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
#ifndef _ROCRAILINIDIALOG_H_
#define _ROCRAILINIDIALOG_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "rocrailinidialog.cpp"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/notebook.h"
#include "wx/spinctrl.h"
#include "wx/statline.h"
////@end includes

#include "rocs/public/node.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxNotebook;
class wxSpinCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DIALOG_RR_INI 10090
#define ID_NOTEBOOK_RR 10091
#define ID_PANEL_RR_INI 10092
#define wxID_STATIC_RR_PLANFILE 10093
#define ID_TEXTCTRL_RR_PLANFILE 10094
#define ID_BUTTON_PLANFILE 10002
#define ID_BUTTON_OCCFILE 10420
#define ID_BUTTON_LOCOFILE 10419
#define ID_BUTTON_KEYPATH 10411
#define wxID_STATIC_RR_LIBPATH 10095
#define ID_TEXTCTRL_RR_LIBPATH 10096
#define ID_PANEL_RR_TRACE 10102
#define ID_CHECKBOX_RR_AUTO 10006
#define ID_CHECKBOX_RR_MONITOR 10232
#define ID_CHECKBOX_RR_BYTE 10007
#define ID_CHECKBOX_RR_DEBUG 10005
#define wxID_STATIC_RR_TRACEFILE 10097
#define ID_TEXTCTRL_RR_TRACEFILE 10101
#define ID_PANEL_RR_SERVICE 10107
#define wxID_STATIC_RR_HTTPPORT 10003
#define ID_TEXTCTRL_RR_HTTPPORT 10004
#define wxID_STATIC_RR_SEVICE_REFRESH 10319
#define ID_TEXTCTRL_RR_SERVICE_REFRESH 10320
#define wxID_STATIC_RR_CLOCK_DEVIDER 10103
#define ID_TEXTCTRL_RR_CLOCK_DEVIDER 10104
#define wxID_STATIC_RR_CLOCK_HOUR 10155
#define ID_TEXTCTRL_RR_CLOCK_HOUR 10157
#define wxID_STATIC_RR_CLOCK_MINUTE 10158
#define ID_TEXTCTRL_RR_CLOCK_MINUTE 10159
#define wxID_STATIC_RR_CLIENTPORT 10108
#define ID_TEXTCTRL_RR_CLIENTPORT 10109
#define wxID_STATIC_RR_MAXCON 10110
#define ID_TEXTCTRL_RR_MAXCONN 10111
#define ID_PANEL_RR_AUTO 10146
#define wxID_STATIC_RR_SWTIME 10147
#define ID_TEXTCTRL_RR_SWTIME 10148
#define wxID_STATIC__MINBKLEN 10149
#define ID_TEXTCTRL_RR_MINBKLEN 10150
#define wxID_STATIC_RR_IGNEVT 10151
#define ID_TEXTCTRL_RR_IGNEVT 10152
#define wxID_STATIC_RR_INITPAUSE 10311
#define ID_TEXTCTRL_RR_PAUSEINIT 10298
#define ID_PANEL_RR_CONTROLLERS 10153
#define ID_LISTBOX_RR_CONTROLLERS 10154
#define ID_BUTTON_RR_DELETE 10105
#define ID_BUTTON_RR_PROPS 10156
#define ID_BUTTON_RR_DEFAULT 10322
#define ID_COMBOBOX_RR_LIB 10001
#define ID_BUTTON_RR_ADD 10000
#define ID_PANEL_R2RNET 10281
#define ID_BUTTON_R2RNET_ROUTES 10327
#define ID_PANEL_ANALYSER 10416
#define ID_PANEL_ROCWEB 10479
#define ID_ROCWEB_WEB_BUTTON 10481
#define ID_ROCWEB_SVGPATH_BUTTON 10339
#define ID_ROCWEB_SVGPATH2_BUTTON 10480
#define ID_ROCWEB_SVGPATH3_BUTTON 10482
#define ID_ROCWEB_SVGPATH4_BUTTON 10483
#define ID_ROCWEB_SVGPATH5_BUTTON 10484
#define SYMBOL_ROCRAILINIDIALOG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_ROCRAILINIDIALOG_TITLE _("Rocrail Properties")
#define SYMBOL_ROCRAILINIDIALOG_IDNAME ID_DIALOG_RR_INI
#define SYMBOL_ROCRAILINIDIALOG_SIZE wxDefaultSize
#define SYMBOL_ROCRAILINIDIALOG_POSITION wxDefaultPosition
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif
#ifndef wxFIXED_MINSIZE
#define wxFIXED_MINSIZE 0
#endif

/*!
 * RocrailIniDialog class declaration
 */

class RocrailIniDialog: public wxDialog
{
    DECLARE_DYNAMIC_CLASS( RocrailIniDialog )
    DECLARE_EVENT_TABLE()

    void initLabels();
    void initValues();
    void initControllerList();
    void evaluate();
    int m_TabAlign;
    wxDialog* m_CSDialog;

public:
    /// Constructors
    RocrailIniDialog( );
    RocrailIniDialog( wxWindow* parent, iONode props );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_ROCRAILINIDIALOG_IDNAME, const wxString& caption = SYMBOL_ROCRAILINIDIALOG_TITLE, const wxPoint& pos = SYMBOL_ROCRAILINIDIALOG_POSITION, const wxSize& size = SYMBOL_ROCRAILINIDIALOG_SIZE, long style = SYMBOL_ROCRAILINIDIALOG_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin RocrailIniDialog event handler declarations

    /// wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED event handler for ID_NOTEBOOK_RR
    void OnNotebookRrPageChanged( wxNotebookEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_PLANFILE
    void OnButtonPlanfileClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_OCCFILE
    void OnButtonOccfileClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_LOCOFILE
    void OnButtonLocofileClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_KEYPATH
    void OnButtonKeypathClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_LISTBOX_SELECTED event handler for ID_LISTBOX_RR_CONTROLLERS
    void OnListboxRrControllersSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_LISTBOX_DOUBLECLICKED event handler for ID_LISTBOX_RR_CONTROLLERS
    void OnListboxRrControllersDoubleClicked( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RR_DELETE
    void OnButtonRrDeleteClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RR_PROPS
    void OnButtonRrPropsClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RR_DEFAULT
    void OnButtonRrDefaultClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_RR_ADD
    void OnButtonRrAddClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_R2RNET_ROUTES
    void OnButtonR2rnetRoutesClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ROCWEB_WEB_BUTTON
    void OnRocwebWebButtonClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ROCWEB_SVGPATH_BUTTON
    void OnSvgPath1Click( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ROCWEB_SVGPATH2_BUTTON
    void OnSvgPath2Click( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ROCWEB_SVGPATH3_BUTTON
    void OnSvgPath3Click( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ROCWEB_SVGPATH4_BUTTON
    void OnSvgPath4Click( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ROCWEB_SVGPATH5_BUTTON
    void OnSvgPath5Click( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
    void OnOkClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
    void OnCancelClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
    void OnHelpClick( wxCommandEvent& event );

////@end RocrailIniDialog event handler declarations

////@begin RocrailIniDialog member function declarations

    iONode GetController() const { return m_Controller ; }
    void SetController(iONode value) { m_Controller = value ; }

    iONode GetProps() const { return m_Props ; }
    void SetProps(iONode value) { m_Props = value ; }

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end RocrailIniDialog member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin RocrailIniDialog member variables
    wxNotebook* m_RRNotebook;
    wxPanel* m_GeneralPanel;
    wxStaticText* m_LabelPlanfile;
    wxTextCtrl* m_PlanFile;
    wxButton* m_PlanFileDlg;
    wxStaticText* m_labOccFile;
    wxTextCtrl* m_OccFile;
    wxButton* m_OpenOccFile;
    wxStaticText* m_labLocoFile;
    wxTextCtrl* m_LocoFile;
    wxButton* m_LocoFileDlg;
    wxStaticText* m_labPlanType;
    wxRadioBox* m_PlanType;
    wxCheckBox* m_Backup;
    wxTextCtrl* m_BackupPath;
    wxStaticText* m_labKeyPath;
    wxTextCtrl* m_KeyPath;
    wxStaticText* m_LabelLibPath;
    wxTextCtrl* m_LibPath;
    wxStaticText* m_labImgPath;
    wxTextCtrl* m_ImgPath;
    wxStaticText* m_labIconPath;
    wxTextCtrl* m_IconPath;
    wxStaticText* m_labIssuesPath;
    wxTextCtrl* m_IssuePath;
    wxStaticText* m_labSoundPath;
    wxTextCtrl* m_SoundPath;
    wxStaticText* m_labSoundPlayer;
    wxTextCtrl* m_SoundPlayer;
    wxCheckBox* m_SoundPlayerLocation;
    wxStaticBox* m_ScBox;
    wxStaticText* m_labScSensor;
    wxComboBox* m_ScSensor;
    wxStaticText* m_labScIID;
    wxTextCtrl* m_ScIID;
    wxStaticText* m_labPTIID;
    wxTextCtrl* m_PTIID;
    wxStaticText* m_labLCIID;
    wxTextCtrl* m_LCIID;
    wxStaticText* m_labDPIID;
    wxTextCtrl* m_DPIID;
    wxStaticText* m_labSVIID;
    wxTextCtrl* m_SVIID;
    wxCheckBox* m_FSUTF8;
    wxPanel* m_TracePanel;
    wxStaticBoxSizer* m_TraceLevel;
    wxCheckBox* m_Auto;
    wxCheckBox* m_Monitor;
    wxCheckBox* m_Calc;
    wxStaticBox* m_DevTraceLevel;
    wxCheckBox* m_Byte;
    wxCheckBox* m_Info;
    wxCheckBox* m_Debug;
    wxStaticText* m_labNrTraceFiles;
    wxSpinCtrl* m_NrTraceFiles;
    wxStaticText* m_labTraceFileSize;
    wxSpinCtrl* m_TraceFileSize;
    wxCheckBox* m_SendAllTraces;
    wxStaticText* m_LabelTraceFile;
    wxTextCtrl* m_TraceFile;
    wxStaticText* m_labProtPath;
    wxTextCtrl* m_ProtPath;
    wxPanel* m_ServicePanel;
    wxStaticBoxSizer* m_HttpBox;
    wxStaticText* m_LabelHttpPort;
    wxTextCtrl* m_HttpPort;
    wxStaticText* m_LabServiceRefresh;
    wxTextCtrl* m_ServiceRefresh;
    wxStaticBoxSizer* m_ClockBox;
    wxStaticText* m_labDevider;
    wxTextCtrl* m_Divider;
    wxTextCtrl* m_ClockUpdate;
    wxStaticText* m_labHour;
    wxTextCtrl* m_Hour;
    wxStaticText* m_labMinute;
    wxTextCtrl* m_Minute;
    wxCheckBox* m_StopClockAtPowerOff;
    wxStaticBoxSizer* m_ClientBox;
    wxStaticText* m_LabelClientPort;
    wxTextCtrl* m_ClientPort;
    wxStaticText* m_LabelMaxCon;
    wxTextCtrl* m_MaxCon;
    wxStaticText* m_labControlCode;
    wxTextCtrl* m_ControlCode;
    wxStaticText* m_labSlaveCode;
    wxTextCtrl* m_SlaveCode;
    wxCheckBox* m_OnlyFirstMaster;
    wxStaticBox* m_SrcpService;
    wxStaticText* m_labSrcpPort;
    wxSpinCtrl* m_SrcpPort;
    wxCheckBox* m_SrcpServiceActive;
    wxStaticText* m_labSRCPDevice;
    wxComboBox* m_SRCPDevice;
    wxStaticBox* m_SNMPBox;
    wxStaticText* m_labSnmpPort;
    wxSpinCtrl* m_SnmpPort;
    wxCheckBox* m_SnmpServiceActive;
    wxStaticBox* m_SNMPTrapBox;
    wxStaticText* m_labSnmpTrapHost;
    wxTextCtrl* m_SnmpTrapHost;
    wxStaticText* m_labSnmpTrapPort;
    wxSpinCtrl* m_SnmpTrapPort;
    wxPanel* m_AtomatPanel;
    wxStaticText* m_LabelSwTime;
    wxTextCtrl* m_SwTime;
    wxStaticText* m_LabelMinBKLen;
    wxTextCtrl* m_MinBKLen;
    wxStaticText* m_LabelIgnEvt;
    wxTextCtrl* m_IgnEvt;
    wxStaticText* m_labInitPause;
    wxTextCtrl* m_PauseInit;
    wxStaticText* m_labInitPower;
    wxCheckBox* m_InitfieldPower;
    wxStaticText* m_labSeed;
    wxSpinCtrl* m_Seed;
    wxStaticText* m_labSavePosTime;
    wxSpinCtrl* m_SavePosTime;
    wxStaticText* m_labEventTimeout;
    wxSpinCtrl* m_EventTimeout;
    wxStaticText* m_labSignalReset;
    wxSpinCtrl* m_SignalReset;
    wxStaticText* m_labRouteSwTime;
    wxSpinCtrl* m_RouteSwTime;
    wxStaticText* m_labSemaphoreWait;
    wxSpinCtrl* m_SemaphoreWait;
    wxStaticText* m_labSignalWait;
    wxSpinCtrl* m_SignalWait;
    wxStaticText* m_labLocoStartGap;
    wxSpinCtrl* m_LocoStartGap;
    wxStaticText* m_labBlockInitPause;
    wxSpinCtrl* m_BlockInitPause;
    wxStaticText* m_labSyncRouteTimeout;
    wxSpinCtrl* m_SyncRouteTimeout;
    wxStaticText* m_labVirtualTimer;
    wxSpinCtrl* m_VirtualTimer;
    wxCheckBox* m_secondNextBlock;
    wxCheckBox* m_EnableSwFb;
    wxCheckBox* m_DisableRouteVreduce;
    wxCheckBox* m_SkipSetSw;
    wxCheckBox* m_SkipSetSg;
    wxCheckBox* m_UseBiCom;
    wxCheckBox* m_CreateGuestOnBiDi;
    wxCheckBox* m_UseBiDiDirection;
    wxCheckBox* m_UseIdent;
    wxCheckBox* m_StopAtIdentMisMatch;
    wxCheckBox* m_PowerOffAtGhost;
    wxCheckBox* m_EBreakAtGhost;
    wxCheckBox* m_KeepGhost;
    wxCheckBox* m_DisableSteal;
    wxCheckBox* m_PowerOffAtReset;
    wxCheckBox* m_ZeroThrottleID;
    wxCheckBox* m_StopNoneCommuter;
    wxCheckBox* m_SyncRoutes;
    wxCheckBox* m_TimedSensors;
    wxCheckBox* m_EnableAnalyzer;
    wxCheckBox* m_ForceUnlock;
    wxCheckBox* m_ReleaseOnIdle;
    wxCheckBox* m_CloseOnGhost;
    wxCheckBox* m_UseOnlyFirstIdent;
    wxCheckBox* m_ActionTimer60;
    wxCheckBox* m_RestoreSchedule;
    wxCheckBox* m_SelectShortestBlock;
    wxCheckBox* m_CloseNoEvents;
    wxCheckBox* m_DisableBlockWait4GoManual;
    wxCheckBox* m_StopAtIn4GoManual;
    wxCheckBox* m_V0AtPowerOn;
    wxCheckBox* m_GreenAspect;
    wxRadioBox* m_DefAspect;
    wxCheckBox* m_ResetFxSp;
    wxCheckBox* m_ProcessSignalEvents;
    wxCheckBox* m_UseRandomRate;
    wxCheckBox* m_RedirectToMaster;
    wxCheckBox* m_Weather;
    wxCheckBox* m_V0OnEbreak;
    wxPanel* m_ControllersPanel;
    wxListBox* m_Controllers;
    wxButton* m_ControllerDelete;
    wxButton* m_ControllerProps;
    wxButton* m_Default;
    wxStaticBoxSizer* m_AddControllerBox;
    wxComboBox* m_Lib;
    wxButton* m_ControllerAdd;
    wxStaticBox* m_ControllerOptionsBox;
    wxCheckBox* m_PowerOffOnExit;
    wxCheckBox* m_PowerOnAtInit;
    wxCheckBox* m_Shutdown;
    wxCheckBox* m_NoDevCheck;
    wxPanel* m_R2RnetPanel;
    wxStaticText* m_labR2RnetID;
    wxTextCtrl* m_R2RnetID;
    wxStaticText* m_labR2RnetAddr;
    wxTextCtrl* m_R2RnetAddr;
    wxStaticText* m_labR2RnetPort;
    wxSpinCtrl* m_R2RnetPort;
    wxStaticText* m_labR2RnetRoutes;
    wxTextCtrl* m_R2RnetRoutes;
    wxButton* m_R2RnetRoutesDlg;
    wxCheckBox* m_R2RnetEnable;
    wxPanel* m_AnalyserPanel;
    wxStaticBox* m_AnaGenerate;
    wxCheckBox* m_SetRouteId;
    wxCheckBox* m_SetBlockId;
    wxCheckBox* m_AddSignalBlockAssignment;
    wxCheckBox* m_AddFeedbackBlockAssignment;
    wxStaticBox* m_AnaClean;
    wxCheckBox* m_CleanRouteId;
    wxCheckBox* m_ResetBlockId;
    wxCheckBox* m_ResetSignalBlockAssignment;
    wxCheckBox* m_ResetFeedbackBlockAssignment;
    wxStaticBox* m_AnaCheck;
    wxCheckBox* m_BasicCheck;
    wxCheckBox* m_BlockCheck;
    wxCheckBox* m_RouteCheck;
    wxCheckBox* m_ActionCheck;
    wxStaticBox* m_AnaReset;
    wxCheckBox* m_BasicClean;
    wxCheckBox* m_BlockClean;
    wxCheckBox* m_RouteClean;
    wxCheckBox* m_ActionClean;
    wxPanel* m_RocWebPanel;
    wxStaticBoxSizer* m_WebServiceBox;
    wxStaticText* m_LabWebServicePort;
    wxSpinCtrl* m_WebServicePort;
    wxStaticText* m_labWebPath;
    wxTextCtrl* m_WebPath;
    wxButton* m_WebPathDlg;
    wxStaticText* m_labTheme1;
    wxTextCtrl* m_SVGPath;
    wxButton* m_SvgPathDlg;
    wxStaticText* m_labTheme2;
    wxTextCtrl* m_SVGPath2;
    wxButton* m_SvgPath2Dlg;
    wxStaticText* m_labTheme3;
    wxTextCtrl* m_SVGPath3;
    wxButton* m_SvgPath3Dlg;
    wxStaticText* m_labTheme4;
    wxTextCtrl* m_SVGPath4;
    wxButton* m_SvgPath4Dlg;
    wxStaticText* m_labTheme5;
    wxTextCtrl* m_SVGPath5;
    wxButton* m_SvgPath5Dlg;
    wxButton* m_OK;
    wxButton* m_Cancel;
    iONode m_Controller;
    iONode m_Props;
////@end RocrailIniDialog member variables
    void event( iONode event );

};

#endif
    // _ROCRAILINIDIALOG_H_
