/*
 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 

 */
#ifndef _ECOSDLG_H_
#define _ECOSDLG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "ecosdlg.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/spinctrl.h"
////@end includes
#include "rocs/public/node.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxSpinCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DIALOG_ECOS_CTRL 10043
#define ID_PANEL 10000
#define ID_SUBLIB 10052
#define ID_BUTTON_SET_FBADDR 10012
#define SYMBOL_ECOSCTRLDIALOG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_ECOSCTRLDIALOG_TITLE _("ECoS")
#define SYMBOL_ECOSCTRLDIALOG_IDNAME ID_DIALOG_ECOS_CTRL
#define SYMBOL_ECOSCTRLDIALOG_SIZE wxSize(400, 300)
#define SYMBOL_ECOSCTRLDIALOG_POSITION wxDefaultPosition
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * ECoSCtrlDialog class declaration
 */

class ECoSCtrlDialog: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( ECoSCtrlDialog )
    DECLARE_EVENT_TABLE()
  void initLabels();
  void initValues();
  void evaluate();
  iONode m_Props;
  const char* m_Devices;

public:
    /// Constructors
    ECoSCtrlDialog();
    ECoSCtrlDialog( wxWindow* parent, iONode props, const char* devices=NULL );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_ECOSCTRLDIALOG_IDNAME, const wxString& caption = SYMBOL_ECOSCTRLDIALOG_TITLE, const wxPoint& pos = SYMBOL_ECOSCTRLDIALOG_POSITION, const wxSize& size = SYMBOL_ECOSCTRLDIALOG_SIZE, long style = SYMBOL_ECOSCTRLDIALOG_STYLE );

    /// Destructor
    ~ECoSCtrlDialog();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin ECoSCtrlDialog event handler declarations

    /// wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_SUBLIB
    void OnSublibSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_SET_FBADDR
    void OnButtonSetFbaddrClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
    void OnOkClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
    void OnCancelClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
    void OnHelpClick( wxCommandEvent& event );

////@end ECoSCtrlDialog event handler declarations

////@begin ECoSCtrlDialog member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end ECoSCtrlDialog member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin ECoSCtrlDialog member variables
    wxStaticText* m_labIID;
    wxTextCtrl* m_IID;
    wxStaticText* m_labDevice;
    wxComboBox* m_Device;
    wxStaticText* m_labHost;
    wxTextCtrl* m_Host;
    wxStaticText* m_labPort;
    wxTextCtrl* m_Port;
    wxStaticText* m_labUserID;
    wxTextCtrl* m_UserID;
    wxStaticText* m_labUDPPorts;
    wxTextCtrl* m_PortTX;
    wxTextCtrl* m_PortRX;
    wxStaticText* m_labFBMod;
    wxSpinCtrl* m_FBMod;
    wxStaticText* m_labSensorRange;
    wxSpinCtrl* m_SensorBegin;
    wxSpinCtrl* m_SensorEnd;
    wxStaticText* m_labVersion;
    wxSpinCtrl* m_Version;
    wxRadioBox* m_SubLib;
    wxStaticBox* m_OptionsBox;
    wxCheckBox* m_SystemInfo;
    wxCheckBox* m_LocoList;
    wxCheckBox* m_CTS;
    wxCheckBox* m_SLCAN;
    wxCheckBox* m_Discovery;
    wxCheckBox* m_Bind;
    wxCheckBox* m_ReportState;
    wxCheckBox* m_V0onEbreak;
    wxButton* m_SertFbAddr;
    wxSpinCtrl* m_FbAddr;
    wxStaticText* m_labSwTime;
    wxSpinCtrl* m_SwTime;
    wxStaticText* m_labCmdPause;
    wxSpinCtrl* m_CmdPause;
    wxButton* m_OK;
    wxButton* m_Cancel;
////@end ECoSCtrlDialog member variables
    void SublibSelected();
};

#endif
    // _ECOSDLG_H_
