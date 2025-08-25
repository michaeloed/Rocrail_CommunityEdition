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
#ifndef _ROCGUIINIDLG_H_
#define _ROCGUIINIDLG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "rocguiinidlg.h"
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
#define ID_DIALOG1 10166
#define ID_NOTEBOOK1 10167
#define ID_WORKSPACE 10005
#define ID_IMAGEPATH_BUTTON 10341
#define ID_UPDATESPATH_BUTTON 10000
#define ID_XSLPATH_BUTTON 10354
#define ID_DECPATH_BUTTON 10415
#define ID_TEXTCTRL_RG_TRACEFILE 10188
#define ID_SVGPATH_BUTTON 10339
#define ID_SVGPATH2_BUTTON 10001
#define ID_SVGPATH3_BUTTON 10002
#define ID_SVGPATH4_BUTTON 10003
#define ID_SVGPATH5_BUTTON 10004
#define SYMBOL_ROCGUIINIDIALOG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_ROCGUIINIDIALOG_TITLE _("RocGui Ini")
#define SYMBOL_ROCGUIINIDIALOG_IDNAME ID_DIALOG1
#define SYMBOL_ROCGUIINIDIALOG_SIZE wxDefaultSize
#define SYMBOL_ROCGUIINIDIALOG_POSITION wxDefaultPosition
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * RocguiIniDialog class declaration
 */

class RocguiIniDialog: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( RocguiIniDialog )
    DECLARE_EVENT_TABLE()
    iONode m_Ini;
    void initLabels();
    void initValues();
    void evaluate();
    int m_TabAlign;

public:
    /// Constructors
    RocguiIniDialog( );
    RocguiIniDialog( wxWindow* parent, iONode ini );
    RocguiIniDialog( wxWindow* parent, wxWindowID id = SYMBOL_ROCGUIINIDIALOG_IDNAME, const wxString& caption = SYMBOL_ROCGUIINIDIALOG_TITLE, const wxPoint& pos = SYMBOL_ROCGUIINIDIALOG_POSITION, const wxSize& size = SYMBOL_ROCGUIINIDIALOG_SIZE, long style = SYMBOL_ROCGUIINIDIALOG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_ROCGUIINIDIALOG_IDNAME, const wxString& caption = SYMBOL_ROCGUIINIDIALOG_TITLE, const wxPoint& pos = SYMBOL_ROCGUIINIDIALOG_POSITION, const wxSize& size = SYMBOL_ROCGUIINIDIALOG_SIZE, long style = SYMBOL_ROCGUIINIDIALOG_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin RocguiIniDialog event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_WORKSPACE
    void OnWorkspaceClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_IMAGEPATH_BUTTON
    void OnImagepathButtonClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_UPDATESPATH_BUTTON
    void OnUpdatespathButtonClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_XSLPATH_BUTTON
    void OnXslpathButtonClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DECPATH_BUTTON
    void OnDecpathButtonClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SVGPATH_BUTTON
    void OnSvgPath1Click( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SVGPATH2_BUTTON
    void OnSvgPath2Click( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SVGPATH3_BUTTON
    void OnSvgPath3Click( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SVGPATH4_BUTTON
    void OnSvgPath4Click( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SVGPATH5_BUTTON
    void OnSvgPath5Click( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
    void OnOKClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
    void OnCANCELClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
    void OnHelpClick( wxCommandEvent& event );

////@end RocguiIniDialog event handler declarations

////@begin RocguiIniDialog member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end RocguiIniDialog member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin RocguiIniDialog member variables
    wxNotebook* m_Notebook;
    wxPanel* m_GeneralTab;
    wxRadioBox* m_ClockType;
    wxRadioBox* m_TabAlignType;
    wxStaticText* m_labWidgetWidth;
    wxSpinCtrl* m_WidgetWidth;
    wxStaticText* m_labMonitorSize;
    wxSpinCtrl* m_MonitorSize;
    wxStaticText* m_labGridFontSizeAdjust;
    wxSpinCtrl* m_GridFontSizeAdjust;
    wxStaticBox* m_labPanelSize;
    wxStaticText* m_labCX;
    wxSpinCtrl* m_CX;
    wxStaticText* m_labCY;
    wxSpinCtrl* m_CY;
    wxStaticBox* m_labModPlanSize;
    wxStaticText* m_labCXMod;
    wxSpinCtrl* m_CXMod;
    wxStaticText* m_labCYMod;
    wxSpinCtrl* m_CYMod;
    wxCheckBox* m_RestrictEdit4Auto;
    wxCheckBox* m_JsSupport;
    wxCheckBox* m_DispatchMode;
    wxCheckBox* m_RestoreLcCtrl;
    wxCheckBox* m_Monitoring;
    wxCheckBox* m_ShowOnlyStartSchedules;
    wxCheckBox* m_ShowBlockID;
    wxCheckBox* m_ShowSecondhand;
    wxCheckBox* m_ReconnectAfterServerShutdown;
    wxCheckBox* m_ResetSpeedDir;
    wxCheckBox* m_UseAllSpeedSteps;
    wxCheckBox* m_RenderGC;
    wxCheckBox* m_FSUTF8;
    wxCheckBox* m_Toolbar;
    wxCheckBox* m_VerticalToolbar;
    wxCheckBox* m_LocoImage;
    wxCheckBox* m_MonitorDontWrap;
    wxCheckBox* m_ShowSpeedOMeter;
    wxCheckBox* m_LocoImageColumn;
    wxCheckBox* m_ShowLocoImageInBlock;
    wxCheckBox* m_ShowTrainIdInBlock;
    wxCheckBox* m_GrayIcons;
    wxCheckBox* m_SensorMonitorAuto;
    wxStaticBox* m_labWorkspace;
    wxTextCtrl* m_Workspace;
    wxButton* m_WorkspaceDlg;
    wxCheckBox* m_StartDefaultWorkspace;
    wxStaticBox* m_labImagePath;
    wxTextCtrl* m_ImagePath;
    wxButton* m_ImagePathDlg;
    wxStaticBox* m_labUpdatesPath;
    wxTextCtrl* m_UpdatesPath;
    wxButton* m_UpdatePathDlg;
    wxStaticBox* m_labXSLPath;
    wxTextCtrl* m_XSLPath;
    wxButton* m_XSLPathDlg;
    wxStaticBox* m_labDecPath;
    wxTextCtrl* m_DecPath;
    wxButton* m_DecPathDlg;
    wxStaticText* m_labSpeak4Block;
    wxTextCtrl* m_Speak4Block;
    wxStaticText* m_labSpeakCmd;
    wxTextCtrl* m_SpeakCmd;
    wxStaticText* m_labDirImage;
    wxTextCtrl* m_DirImageFwd;
    wxTextCtrl* m_DirImageRev;
    wxStaticText* m_labBoosterUID;
    wxTextCtrl* m_BoosterUID;
    wxPanel* m_TracePanel;
    wxStaticBoxSizer* m_TraceLevel;
    wxCheckBox* m_Debug;
    wxCheckBox* m_Info;
    wxStaticBoxSizer* m_TraceFileBox;
    wxStaticText* m_labTraceFile;
    wxTextCtrl* m_TraceFile;
    wxStaticText* m_labProtPath;
    wxTextCtrl* m_ProtPath;
    wxStaticBox* m_HelpBox;
    wxTextCtrl* m_HelpURL;
    wxPanel* m_PTpanel;
    wxStaticText* m_labCVnrs;
    wxTextCtrl* m_CVnrs;
    wxStaticText* m_labTimeout;
    wxTextCtrl* m_Timeout;
    wxCheckBox* m_Lissy;
    wxCheckBox* m_SVtab;
    wxCheckBox* m_UseDecSpec4All;
    wxPanel* m_SVGpanel;
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
    wxStaticText* m_labItemIDpointsize;
    wxSpinCtrl* m_ItemIDpointsize;
    wxStaticText* m_labTextPS;
    wxSpinCtrl* m_TextPS;
    wxCheckBox* m_ProcessRouteEvents;
    wxCheckBox* m_ProcessBlockEvents;
    wxCheckBox* m_ShowRoute4Switch;
    wxPanel* m_RICpanel;
    wxStaticBoxSizer* m_labVelocity;
    wxStaticText* m_labY;
    wxTextCtrl* m_Velocity;
    wxStaticText* m_labRepeat;
    wxTextCtrl* m_Repeat;
    wxStaticText* m_labDir;
    wxTextCtrl* m_Dir;
    wxStaticText* m_labStop;
    wxTextCtrl* m_Stop;
    wxStaticText* m_labRICStep;
    wxSpinCtrl* m_RICStep;
    wxStaticBoxSizer* m_FunctionsBox;
    wxStaticText* m_labLights;
    wxTextCtrl* m_Lights;
    wxStaticText* m_labF1;
    wxTextCtrl* m_F1;
    wxStaticText* m_labF2;
    wxTextCtrl* m_F2;
    wxStaticText* m_labF3;
    wxTextCtrl* m_F3;
    wxStaticText* m_labF4;
    wxTextCtrl* m_F4;
    wxStaticText* m_labF5;
    wxTextCtrl* m_F5;
    wxStaticText* m_labF6;
    wxTextCtrl* m_F6;
    wxStaticText* m_labF7;
    wxTextCtrl* m_F7;
    wxStaticText* m_labF8;
    wxTextCtrl* m_F8;
    wxStaticText* m_labF9;
    wxTextCtrl* m_F9;
    wxStaticText* m_labF10;
    wxTextCtrl* m_F10;
    wxStaticText* m_labF11;
    wxTextCtrl* m_F11;
    wxStaticText* m_labF12;
    wxTextCtrl* m_F12;
    wxStaticBoxSizer* m_PowerBox;
    wxStaticText* m_labPowerOn;
    wxTextCtrl* m_PowerOn;
    wxStaticText* m_labPowerOff;
    wxTextCtrl* m_PowerOff;
    wxPanel* m_MICpanel;
    wxStaticText* m_labMICStep;
    wxSpinCtrl* m_MICStep;
    wxCheckBox* m_MICStopOnExit;
    wxPanel* m_AcceleratorPanel;
    wxStaticText* m_labAccelFunction;
    wxStaticText* m_labAccelKeyCode;
    wxStaticText* m_labAccelModifier;
    wxStaticText* m_labEmergencyBreak;
    wxComboBox* m_EmergencyBreakList;
    wxRadioBox* m_EmergencyBreakModifier;
    wxButton* m_OK;
    wxButton* m_Cancel;
    wxButton* m_Help;
////@end RocguiIniDialog member variables
};

#endif
    // _ROCGUIINIDLG_H_
