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
#ifndef _FEEDBACKDIALOG_H_
#define _FEEDBACKDIALOG_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "feedbackdialog.cpp"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/notebook.h"
#include "wx/listctrl.h"
#include "wx/spinctrl.h"
#include "wx/grid.h"
////@end includes

#include "basedlg.h"


#include "rocs/public/node.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxNotebook;
class wxListCtrl;
class wxSpinCtrl;
class wxGrid;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DIALOG_FEEDBACK 10084
#define ID_NOTEBOOK_FEEDBACK 10085
#define ID_PANEL_FB_INDEX 10013
#define ID_LISTCTRLINDEX_FB 10407
#define ID_BUTTON_FB_NEW 10015
#define ID_BUTTON_FB_DELETE 10016
#define ID_BUTTON_FB_AUTOADDR 10442
#define ID_BUTTON_FB_DOC 10353
#define ID_PANEL_FB_GENERAL 10017
#define wxID_STATIC_FB_ID 10018
#define ID_TEXTCTRL_FB_ID 10019
#define ID_COMBOBOX_FB_BLOCKID 10004
#define wxID_STATIC_FB_DESC 10226
#define ID_TEXTCTRL_FB_DESC 10225
#define ID_CHECKBOX_FB_STATE 10021
#define ID_CHECKBOX_FB_SHOW 10023
#define ID_FEEDBACK_ACTIONS 10196
#define ID_PANEL_FB_LOCATION 10024
#define wxID_STATIC_FB_X 10025
#define ID_TEXTCTRL_FB_X 10006
#define wxID_STATIC_FB_Y 10007
#define ID_TEXTCTRL_FB_Y 10008
#define wxID_STATIC_FB_Z 10009
#define ID_TEXTCTRL_FB_Z 10010
#define ID_RADIOBOX_FB_ORI 10011
#define ID_PANEL_FB_INTERFACE 10012
#define wxID_STATIC_FB_IID 10000
#define ID_TEXTCTRL_FB_IID 10001
#define wxID_STATIC_FB_ADDRESS1 10002
#define ID_FB_TYPE 10396
#define ID_PANEL_FB_WIRING 10334
#define ID_PANEL_FB_GPS 10444
#define ID_PANEL_FB_STATISTICS 10475
#define ID_FEEDBACK_STATISTIC_GRIG 10476
#define ID_STATISTIC_DELETE 10477
#define ID_STATISTIC_SHOW_ALL 10478
#define SYMBOL_FEEDBACKDIALOG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_FEEDBACKDIALOG_TITLE _("Sensors")
#define SYMBOL_FEEDBACKDIALOG_IDNAME ID_DIALOG_FEEDBACK
#define SYMBOL_FEEDBACKDIALOG_SIZE wxDefaultSize
#define SYMBOL_FEEDBACKDIALOG_POSITION wxDefaultPosition
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
 * FeedbackDialog class declaration
 */

class FeedbackDialog: public wxDialog, public BaseDialog
{
  DECLARE_DYNAMIC_CLASS( FeedbackDialog )
  DECLARE_EVENT_TABLE()

  void initLabels();
  bool initIndex();
  void initValues();
  bool evaluate();
  void doStatistic(iONode l_Props);
  int findStatisticCol( wxString lcid);
  void StatisticDeleteAll();

  int m_TabAlign;
  bool m_bStatisticShowAll;

public:
    /// Constructors
    FeedbackDialog( wxWindow* parent, iONode m_Props );
    FeedbackDialog();

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_FEEDBACKDIALOG_IDNAME, const wxString& caption = SYMBOL_FEEDBACKDIALOG_TITLE, const wxPoint& pos = SYMBOL_FEEDBACKDIALOG_POSITION, const wxSize& size = SYMBOL_FEEDBACKDIALOG_SIZE, long style = SYMBOL_FEEDBACKDIALOG_STYLE );

    /// Creates the controls and sizers
    void CreateControls();
    iONode getProperties(){ return m_Props;}
    void OnSelectPage( wxCommandEvent& event );

////@begin FeedbackDialog event handler declarations

    /// wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ID_LISTCTRLINDEX_FB
    void OnListctrlindexFbSelected( wxListEvent& event );

    /// wxEVT_COMMAND_LIST_COL_CLICK event handler for ID_LISTCTRLINDEX_FB
    void OnListctrlindexFbColLeftClick( wxListEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_FB_NEW
    void OnButtonFbNewClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_FB_DELETE
    void OnButtonFbDeleteClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_FB_AUTOADDR
    void OnButtonFbAutoaddrClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_FB_DOC
    void OnButtonFbDocClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_FEEDBACK_ACTIONS
    void OnFeedbackActionsClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_FB_TYPE
    void OnFbTypeSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_STATISTIC_DELETE
    void OnStatisticDeleteClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_STATISTIC_SHOW_ALL
    void OnStatisticShowAllClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
    void OnCancelClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
    void OnOkClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_APPLY
    void OnApplyClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
    void OnHelpClick( wxCommandEvent& event );

////@end FeedbackDialog event handler declarations

////@begin FeedbackDialog member function declarations

    iONode GetProps() const { return m_Props ; }
    void SetProps(iONode value) { m_Props = value ; }

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end FeedbackDialog member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin FeedbackDialog member variables
    wxNotebook* m_Notebook;
    wxPanel* m_IndexPanel;
    wxListCtrl* m_List2;
    wxButton* m_New;
    wxButton* m_Delete;
    wxButton* m_AutoAdressing;
    wxButton* m_Doc;
    wxPanel* m_General;
    wxStaticText* m_LabelId;
    wxTextCtrl* m_Id;
    wxStaticText* m_labBlockID;
    wxComboBox* m_BlockID;
    wxStaticText* m_labRouteIDs;
    wxTextCtrl* m_RouteIDs;
    wxStaticText* m_LabelDescription;
    wxTextCtrl* m_Description;
    wxStaticText* m_labAccNr;
    wxSpinCtrl* m_AccNr;
    wxStaticText* m_labTimer;
    wxSpinCtrl* m_Timer;
    wxStaticText* m_labTimerMS;
    wxStaticText* m_labMaxLoad;
    wxSpinCtrl* m_MaxLoad;
    wxCheckBox* m_State;
    wxCheckBox* m_Road;
    wxCheckBox* m_Show;
    wxCheckBox* m_Curved;
    wxButton* m_Actions;
    wxPanel* m_LocationPanel;
    wxStaticText* m_LabelX;
    wxTextCtrl* m_x;
    wxStaticText* m_LabelY;
    wxTextCtrl* m_y;
    wxStaticText* m_LabelZ;
    wxTextCtrl* m_z;
    wxRadioBox* m_ori;
    wxPanel* m_Interface;
    wxStaticText* m_Labeliid;
    wxComboBox* m_iid;
    wxStaticText* m_labUIDName;
    wxTextCtrl* m_UIDName;
    wxStaticBox* m_AddressBox;
    wxStaticText* m_labBusNr;
    wxTextCtrl* m_BusNr;
    wxStaticText* m_LabelAddress;
    wxSpinCtrl* m_Address;
    wxStaticBox* m_CutoutBox;
    wxStaticText* m_labCutoutBus;
    wxTextCtrl* m_CutoutBus;
    wxStaticText* m_labCutoutAddr;
    wxSpinCtrl* m_CutoutAddr;
    wxRadioBox* m_Type;
    wxStaticBox* m_OptionsBox;
    wxCheckBox* m_ActiveLow;
    wxCheckBox* m_ResetWC;
    wxPanel* m_Wiring;
    wxStaticBox* m_CTCBox;
    wxStaticText* m_labCTCIID;
    wxTextCtrl* m_CTCIID;
    wxStaticText* m_labCTCAddr;
    wxSpinCtrl* m_CTCAddr;
    wxStaticText* m_labCTCPort;
    wxSpinCtrl* m_CTCPort;
    wxStaticText* m_labCTCGate;
    wxRadioBox* m_CTCGate;
    wxCheckBox* m_AsSwitch;
    wxPanel* m_GPSTab;
    wxStaticBox* m_GPSCoordinates;
    wxStaticText* m_labGPSX;
    wxSpinCtrl* m_GPSX;
    wxStaticText* m_labGPSY;
    wxSpinCtrl* m_GPSY;
    wxStaticText* m_labGPSZ;
    wxSpinCtrl* m_GPSZ;
    wxStaticBox* m_GPSTolerance;
    wxStaticText* m_labGPSToleranceX;
    wxSpinCtrl* m_GPSToleranceX;
    wxStaticText* m_labGPSToleranceY;
    wxSpinCtrl* m_GPSToleranceY;
    wxStaticText* m_labGPSToleranceZ;
    wxSpinCtrl* m_GPSToleranceZ;
    wxPanel* m_StatisticsTab;
    wxGrid* m_StatisticGrid;
    wxButton* m_StatisticDelete;
    wxButton* m_StatisticShowAll;
    wxButton* m_Cancel;
    wxButton* m_OK;
    wxButton* m_Apply;
    iONode m_Props;
////@end FeedbackDialog member variables
};

#endif
    // _FEEDBACKDIALOG_H_
