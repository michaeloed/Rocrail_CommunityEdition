/*
 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 

 */
#ifndef _OPENDCC_H_
#define _OPENDCC_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "opendcc.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/notebook.h"
#include "wx/spinctrl.h"
#include "wx/listctrl.h"
////@end includes
#include "wx/progdlg.h"

#include "rocs/public/node.h"
#include "rocs/public/mutex.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxNotebook;
class wxSpinCtrl;
class wxListCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_OPENDCCCTRLDLG 10016
#define ID_OPENDCCSUBLIB 10050
#define ID_READCVS 10042
#define ID_WRITECVS 10049
#define ID_LISTCTRL_DECEXCEPTIONS 10051
#define SYMBOL_OPENDCCCTRLDLG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_OPENDCCCTRLDLG_TITLE _("OpenDCC")
#define SYMBOL_OPENDCCCTRLDLG_IDNAME ID_OPENDCCCTRLDLG
#define SYMBOL_OPENDCCCTRLDLG_SIZE wxDefaultSize
#define SYMBOL_OPENDCCCTRLDLG_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * OpenDCCCtrlDlg class declaration
 */

enum {
  mode_type_xpr  = 0x01,
  mode_fastclock = 0x10,
};

enum {
  so_version = 0,
  so_bps = 1,
  so_mode = 2,
  so_dcc_format = 24,
  so_bidi = 25,
  so_loco_format_low = 40,
  so_loco_format_high = 41,
  so_s88_timing = 30,
  so_s88_bus1 = 9,
  so_s88_bus2 = 10,
  so_s88_bus3 = 11,
  so_s88_mode = 7,
  so_serial_number = 39,
  so_pt_resets = 18,
  so_pt_commands = 19,
  so_pt_pom = 20,
  so_scd_main = 34,
  so_scd_pt = 35,
  so_sw_invert = 12,
  so_sw_commands = 13,
  so_sw_time = 14,
  so_sw_sensor_offset = 16,
  so_sw_sensor_mode = 17,
  so_xpn_feedback_mapping = 29,
  so_xpn_sensors = 32,
};

#define ME_SOTimer 10003


class OpenDCCCtrlDlg: public wxDialog
{
    DECLARE_DYNAMIC_CLASS( OpenDCCCtrlDlg )
    DECLARE_EVENT_TABLE()

    void initLabels();
    void initValues();
    void evaluate();
    void sendGet( int so );
    void sendSet( int so, int value );
    void evaluateGet( int so, int value );
    void evaluateSet( int so, int value );

    int m_soValue[256];
    int m_soNewValue[256];

    bool m_bLenz;
    int m_OpenDCCmode;

    int m_TimerCount;
    bool m_bStartUpProgress;
    bool m_bCleanUpProgress;
    iOMutex m_TimerMutex;
    void OnTimer(wxTimerEvent& event);
    wxTimer* m_Timer;
    wxProgressDialog* m_Progress;
    Boolean m_Create;
    void startProgress();
    void stopProgress();
    void writeAll();

public:
    /// Constructors
    OpenDCCCtrlDlg();
    OpenDCCCtrlDlg( wxWindow* parent, iONode props, const char* devices=NULL );
    OpenDCCCtrlDlg( wxWindow* parent, wxWindowID id = SYMBOL_OPENDCCCTRLDLG_IDNAME, const wxString& caption = SYMBOL_OPENDCCCTRLDLG_TITLE, const wxPoint& pos = SYMBOL_OPENDCCCTRLDLG_POSITION, const wxSize& size = SYMBOL_OPENDCCCTRLDLG_SIZE, long style = SYMBOL_OPENDCCCTRLDLG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_OPENDCCCTRLDLG_IDNAME, const wxString& caption = SYMBOL_OPENDCCCTRLDLG_TITLE, const wxPoint& pos = SYMBOL_OPENDCCCTRLDLG_POSITION, const wxSize& size = SYMBOL_OPENDCCCTRLDLG_SIZE, long style = SYMBOL_OPENDCCCTRLDLG_STYLE );

    /// Destructor
    ~OpenDCCCtrlDlg();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin OpenDCCCtrlDlg event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_READCVS
    void OnReadcvsClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_WRITECVS
    void OnWritecvsClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
    void OnOkClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
    void OnCancelClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_APPLY
    void OnApplyClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
    void OnHelpClick( wxCommandEvent& event );

////@end OpenDCCCtrlDlg event handler declarations

////@begin OpenDCCCtrlDlg member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end OpenDCCCtrlDlg member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin OpenDCCCtrlDlg member variables
    wxNotebook* m_Notebook;
    wxPanel* m_GeneralPanel;
    wxStaticText* m_labIID;
    wxTextCtrl* m_IID;
    wxStaticText* m_labDevice;
    wxComboBox* m_Device;
    wxStaticText* m_labVersion;
    wxTextCtrl* m_Version;
    wxTextCtrl* m_Mode;
    wxStaticText* m_labSerialNumber;
    wxSpinCtrl* m_SerialNumber;
    wxRadioBox* m_SubLib;
    wxRadioBox* m_Baudrate;
    wxStaticBox* m_labSpecials;
    wxCheckBox* m_Clock;
    wxCheckBox* m_Bidi;
    wxCheckBox* m_PowerAtStartup;
    wxStaticBox* m_BiDiBox;
    wxCheckBox* m_BiDiCutOut;
    wxCheckBox* m_BiDiIdNotify;
    wxCheckBox* m_BiDiAccQuery;
    wxButton* m_ReadCVs;
    wxButton* m_WriteCVs;
    wxPanel* m_DecoderPanel;
    wxRadioBox* m_DecSpeedSteps;
    wxStaticBox* m_DecExceptionBox;
    wxListCtrl* m_DecExceptions;
    wxPanel* m_S88Panel;
    wxStaticText* m_labS88Timing;
    wxSpinCtrl* m_S88Timing;
    wxStaticBox* m_S88BusBox;
    wxStaticText* m_labS88Bus1;
    wxSpinCtrl* m_S88Bus1;
    wxStaticText* m_labS88Bus2;
    wxSpinCtrl* m_S88Bus2;
    wxStaticText* m_labS88Bus3;
    wxSpinCtrl* m_S88Bus3;
    wxStaticText* m_labXpressNetSensors;
    wxSpinCtrl* m_XpressNetSensors;
    wxStaticBox* m_S88SettingsBox;
    wxCheckBox* m_S88Active;
    wxCheckBox* m_S88TurnoutSensors;
    wxRadioBox* m_SwitchSensorMode;
    wxStaticText* m_labSwitchSensorOffset;
    wxSpinCtrl* m_SwitchSensorOffset;
    wxRadioBox* m_XpnFeedbackMapping;
    wxPanel* m_ProgrammingTab;
    wxStaticText* m_labPTResets;
    wxSpinCtrl* m_PTResets;
    wxStaticText* m_labPTCommands;
    wxSpinCtrl* m_PTCommands;
    wxStaticText* m_labPTPOMrepeat;
    wxSpinCtrl* m_PTPOMrepeat;
    wxPanel* m_SCDPanel;
    wxStaticText* m_LabSCtimeMain;
    wxSpinCtrl* m_SCTimeMain;
    wxStaticText* m_labSCTimePT;
    wxSpinCtrl* m_SCTimePT;
    wxPanel* m_SwitchPanel;
    wxStaticText* m_labSwitchCommands;
    wxSpinCtrl* m_SwitchCommands;
    wxStaticText* m_labSwitchTime;
    wxSpinCtrl* m_SwitchTime;
    wxCheckBox* m_SwitchInvert;
    wxButton* m_OK;
    wxButton* m_Cancel;
    wxButton* m_Apply;
////@end OpenDCCCtrlDlg member variables
    iONode m_Props;
    const char* m_Devices;
    int m_TabAlign;
    void OnPTEvent(wxCommandEvent& event);
};

#endif
    // _OPENDCC_H_
