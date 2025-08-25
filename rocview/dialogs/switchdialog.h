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
#ifndef _SWITCHDIALOG_H_
#define _SWITCHDIALOG_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "switchdialog.cpp"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/notebook.h"
#include "wx/listctrl.h"
#include "wx/tglbtn.h"
#include "wx/spinctrl.h"
#include "wx/statline.h"
////@end includes

#include "basedlg.h"

#include "rocs/public/node.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxNotebook;
class wxListCtrl;
class wxToggleButton;
class wxSpinCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DIALOG_SW 10049
#define ID_NOTEBOOK_SW 10050
#define ID_PANEL_SW_INDEX 10005
#define ID_LISTCTRLINDEX_SW 10120
#define ID_BUTTON_SW_NEW 10007
#define ID_BUTTON_SW_DELETE 10008
#define ID_BUTTON_SW_DOC 10372
#define ID_TOGGLEBUTTON_TEST 10162
#define ID_PANEL_SW_GENERAL 10009
#define wxID_STATIC_SW_ID 10010
#define ID_TEXTCTRL_SW_ID 10011
#define ID_COMBOBOX_SW_BLOCKID 10028
#define wxID_STATIC_SW_LOCKED 10012
#define ID_TEXTCTRL_SW_LOCKED 10013
#define wxID_STATIC_SW_STATE 10014
#define ID_TEXTCTRL_SW_STATE 10015
#define ID_SW_RESET_SWITCHED 10069
#define wxID_STATIC_SW_TYPE 10016
#define ID_COMBOBOX_SW_TYPE 10017
#define wxID_STATIC_SW_DIR 10174
#define ID_RADIOBOX_SW_DIR 10173
#define ID_CHECKBOX_SW_SHOW 10023
#define ID_SWITCH_ACTIONS 10144
#define ID_PANEL_SW_LOCATION 10018
#define wxID_STATIC_SW_X 10019
#define ID_TEXTCTRL_SW_X 10000
#define wxID_STATIC_SW_Y 10001
#define ID_TEXTCTRL_SW_Y 10002
#define wxID_STATIC_SW_Z 10003
#define ID_TEXTCTRL_SW_Z 10004
#define ID_RADIOBOX_SW_ORI 10020
#define ID_PANEL_SW_INTERFACE 10021
#define wxID_STATIC_SW_IID 10022
#define ID_TEXTCTRL_SW_IID 10023
#define wxID_STATIC_SW_BUS 10252
#define ID_TEXTCTRL_SW_BUS 10251
#define wxID_STATIC_SW_PROT 10182
#define ID_CHOICE_SW_PROT 10181
#define wxID_STATIC_SW_ADDRESS1 10024
#define ID_TEXTCTRL_SW_ADDRESS1 10025
#define wxID_STATIC_SW_PORT1 10026
#define ID_TEXTCTRL_SW_PORT1 10027
#define ID_SWITCH_SINGLEGATE 10314
#define ID_CHECKBOX_SW_INVERT1 10029
#define wxID_STATIC_SW_ADDRESS2 10030
#define ID_TEXTCTRL_SW_ADDRESS2 10031
#define wxID_STATIC_SW_PORT2 10032
#define ID_TEXTCTRL_SW_PORT2 10033
#define wxID_STATIC_SW_INVERT2 10034
#define ID_CHECKBOX_SW_INVERT2 10035
#define ID_CHECKBOX_SW_DELAY 10236
#define ID_TEXTCTRL_SW_DELAY 10275
#define ID_ACCESSORY 10417
#define ID_SW_PORT_TYPE 10414
#define ID_PANEL_SW_WIRERING 10036
#define wxID_STATIC_SW_FB1R 10037
#define ID_COMBOBOX_SW_FB1R 10038
#define wxID_STATIC_SW_FB1G 10039
#define ID_COMBOBOX_SW_FB1G 10040
#define wxID_STATIC_SW_FB2R 10041
#define ID_COMBOBOX_SW_FB2R 10042
#define wxID_STATIC_SW_FB2G 10043
#define ID_COMBOBOX_SW_FB2G 10044
#define ID_SW_WIRING_USEFIELD 10413
#define ID_SPINCTRL 10333
#define ID_PANEL_SWITCH_CONTROL 10370
#define ID_PANEL_SWITCH_FROG 10244
#define ID_FROG_ACCESSORY 10049
#define ID_SW_TRACKDRIVER 10323
#define SYMBOL_SWITCHDIALOG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_SWITCHDIALOG_TITLE _("Turnouts")
#define SYMBOL_SWITCHDIALOG_IDNAME ID_DIALOG_SW
#define SYMBOL_SWITCHDIALOG_SIZE wxDefaultSize
#define SYMBOL_SWITCHDIALOG_POSITION wxDefaultPosition
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
 * SwitchDialog class declaration
 */

class SwitchDialog: public wxDialog, public BaseDialog
{
    DECLARE_DYNAMIC_CLASS( SwitchDialog )
    DECLARE_EVENT_TABLE()

  void initLabels();
  bool initIndex();
  void initValues();
  bool evaluate();
  int m_TabAlign;

public:
    /// Constructors
    SwitchDialog( wxWindow* parent, iONode p_Props );
    SwitchDialog( );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_SWITCHDIALOG_IDNAME, const wxString& caption = SYMBOL_SWITCHDIALOG_TITLE, const wxPoint& pos = SYMBOL_SWITCHDIALOG_POSITION, const wxSize& size = SYMBOL_SWITCHDIALOG_SIZE, long style = SYMBOL_SWITCHDIALOG_STYLE );

    /// Creates the controls and sizers
    void CreateControls();
    iONode getProperties(){ return m_Props;}
    void OnSelectPage( wxCommandEvent& event );

////@begin SwitchDialog event handler declarations

    /// wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ID_LISTCTRLINDEX_SW
    void OnListctrlindexSwSelected( wxListEvent& event );

    /// wxEVT_COMMAND_LIST_COL_CLICK event handler for ID_LISTCTRLINDEX_SW
    void OnListctrlindexSwColLeftClick( wxListEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_SW_NEW
    void OnButtonSwNewClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_SW_DELETE
    void OnButtonSwDeleteClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_SW_DOC
    void OnButtonSwDocClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_TOGGLEBUTTON_TEST
    void OnTogglebuttonTestClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SW_RESET_SWITCHED
    void OnSwResetSwitchedClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_COMBOBOX_SELECTED event handler for ID_COMBOBOX_SW_TYPE
    void OnComboboxSwTypeSelected( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SWITCH_ACTIONS
    void OnSwitchActionsClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_SWITCH_SINGLEGATE
    void OnSwitchSinglegateClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKBOX_SW_DELAY
    void OnCheckboxSwDelayClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_ACCESSORY
    void onAccessory( wxCommandEvent& event );

    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_FROG_ACCESSORY
    void onFrogAccessory( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
    void OnCancelClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
    void OnOkClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_APPLY
    void OnApplyClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
    void OnHelpClick( wxCommandEvent& event );

////@end SwitchDialog event handler declarations

////@begin SwitchDialog member function declarations

    iONode GetProps() const { return m_Props ; }
    void SetProps(iONode value) { m_Props = value ; }

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end SwitchDialog member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin SwitchDialog member variables
    wxNotebook* m_Notebook;
    wxPanel* m_IndexPanel;
    wxListCtrl* m_List2;
    wxButton* m_New;
    wxButton* m_Delete;
    wxButton* m_Doc;
    wxToggleButton* m_Test;
    wxPanel* m_GeneralPanel;
    wxStaticText* m_LabelID;
    wxTextCtrl* m_ID;
    wxStaticText* m_labDesc;
    wxTextCtrl* m_Desc;
    wxStaticText* m_labBlockID;
    wxComboBox* m_BlockID;
    wxStaticText* m_labRouteIDs;
    wxTextCtrl* m_RouteIDs;
    wxStaticText* m_LabelLocked;
    wxTextCtrl* m_Locked;
    wxStaticText* m_LabelState;
    wxTextCtrl* m_State;
    wxStaticText* m_labSwitched;
    wxTextCtrl* m_Switched;
    wxButton* m_ResetSwitched;
    wxStaticText* m_LabelType;
    wxComboBox* m_Type;
    wxStaticText* m_labSubType;
    wxRadioBox* m_SubType;
    wxStaticText* m_labAccNr;
    wxSpinCtrl* m_AccNr;
    wxStaticText* m_LabelDir;
    wxRadioBox* m_Dir;
    wxRadioBox* m_SavePosBox;
    wxStaticBox* m_OptionsBox;
    wxCheckBox* m_Raster;
    wxCheckBox* m_Road;
    wxCheckBox* m_Show;
    wxCheckBox* m_RectCrossing;
    wxCheckBox* m_SwapStraight;
    wxButton* m_Actions;
    wxPanel* m_LocationPanel;
    wxStaticText* m_LabelX;
    wxTextCtrl* m_x;
    wxStaticText* m_LabelY;
    wxTextCtrl* m_y;
    wxStaticText* m_LabelZ;
    wxTextCtrl* m_z;
    wxRadioBox* m_ori;
    wxPanel* m_InterfacePanel;
    wxStaticText* m_Labeliid;
    wxComboBox* m_iid;
    wxStaticText* m_Label_Bus;
    wxTextCtrl* m_Bus;
    wxStaticText* m_labUIDName;
    wxTextCtrl* m_UIDName;
    wxStaticText* m_LabelProt;
    wxChoice* m_Prot;
    wxStaticText* m_LabelAddress1;
    wxTextCtrl* m_Address1;
    wxStaticText* m_LabelPort1;
    wxTextCtrl* m_Port1;
    wxStaticText* m_labParam1;
    wxSpinCtrl* m_Param1;
    wxStaticText* m_labValue1;
    wxSpinCtrl* m_Value1;
    wxStaticText* m_labGate;
    wxRadioBox* m_Gate;
    wxCheckBox* m_SingleGate;
    wxCheckBox* m_Invert1;
    wxStaticText* m_LabelAddress2;
    wxTextCtrl* m_Address2;
    wxStaticText* m_LabelPort2;
    wxTextCtrl* m_Port2;
    wxStaticText* m_labParam2;
    wxSpinCtrl* m_Param2;
    wxStaticText* m_labValue2;
    wxSpinCtrl* m_Value2;
    wxStaticText* m_labGate2;
    wxRadioBox* m_Gate2;
    wxCheckBox* m_Invert2;
    wxCheckBox* m_ActDelay;
    wxTextCtrl* m_Delay;
    wxCheckBox* m_SyncDelay;
    wxCheckBox* m_Accessory;
    wxRadioBox* m_PortType;
    wxPanel* m_WireringPanel;
    wxStaticBox* m_WiringBox;
    wxStaticText* m_LabelFb1R;
    wxComboBox* m_Fb1R;
    wxCheckBox* m_Fb1Rinvert;
    wxStaticText* m_LabelFb1G;
    wxComboBox* m_Fb1G;
    wxCheckBox* m_Fb1Ginvert;
    wxStaticText* m_LabelFb2R;
    wxComboBox* m_Fb2R;
    wxCheckBox* m_Fb2Rinvert;
    wxStaticText* m_LabelFb2G;
    wxComboBox* m_Fb2G;
    wxCheckBox* m_Fb2Ginvert;
    wxStaticText* m_labFbOcc;
    wxComboBox* m_FbOcc;
    wxStaticText* m_labFbOcc2;
    wxComboBox* m_FbOcc2;
    wxCheckBox* m_FbSet;
    wxCheckBox* m_FbUseField;
    wxStaticBox* m_CTCBox;
    wxStaticText* m_labCTCMotor;
    wxStaticText* m_labCTCIID;
    wxStaticText* m_labCTCBus;
    wxStaticText* m_labCTCAddress;
    wxStaticText* m_labCTCCmdAtOn;
    wxStaticText* m_labCTCAddr1;
    wxTextCtrl* m_CTCIID1;
    wxTextCtrl* m_CTCBus1;
    wxSpinCtrl* m_CTCAddr1;
    wxRadioBox* m_CTCOn1;
    wxStaticText* m_labCTCAddr2;
    wxTextCtrl* m_CTCIID2;
    wxTextCtrl* m_CTCBus2;
    wxSpinCtrl* m_CTCAddr2;
    wxRadioBox* m_CTCOn2;
    wxStaticText* m_labCTCLED;
    wxStaticText* m_labCTCIIDLED;
    wxStaticText* m_labCTCBusLED;
    wxStaticText* m_labCTCAddrLED;
    wxStaticText* m_labCTCPortLED;
    wxStaticText* m_labCTCGateLED;
    wxStaticText* m_labCTCSwitchLED;
    wxStaticText* m_labCTCLED1;
    wxTextCtrl* m_CTCIIDLED1;
    wxTextCtrl* m_CTCLEDBus1;
    wxSpinCtrl* m_CTCAddrLED1;
    wxSpinCtrl* m_CTCPortLED1;
    wxSpinCtrl* m_CTCGateLED1;
    wxCheckBox* m_CTCAsSwitchLED1;
    wxStaticText* m_labCTCLED2;
    wxTextCtrl* m_CTCIIDLED2;
    wxTextCtrl* m_CTCLEDBus2;
    wxSpinCtrl* m_CTCAddrLED2;
    wxSpinCtrl* m_CTCPortLED2;
    wxSpinCtrl* m_CTCGateLED2;
    wxCheckBox* m_CTCAsSwitchLED2;
    wxPanel* m_ControlPanel;
    wxCheckBox* m_ActivateCtrl;
    wxStaticText* m_labCtrlInterval;
    wxSpinCtrl* m_CtrlInterval;
    wxStaticText* m_labCtrlIntervalSec;
    wxStaticText* m_labCtrlDelay;
    wxSpinCtrl* m_CtrlDelay;
    wxStaticText* m_labCtrlDelaySec;
    wxStaticText* m_labCtrlRoutes;
    wxTextCtrl* m_CtrlRoutes;
    wxStaticText* m_labCtrlBlocks;
    wxTextCtrl* m_CtrlBlocks;
    wxPanel* m_FrogPanel;
    wxStaticText* m_labFrogIID;
    wxTextCtrl* m_FrogIID;
    wxStaticText* m_labBusPol;
    wxTextCtrl* m_BusPol;
    wxStaticText* m_labFrogTimer;
    wxSpinCtrl* m_FrogTimer;
    wxStaticBox* m_Frog1Box;
    wxStaticText* m_labRelayFrog2;
    wxStaticText* m_labAddressFrog2;
    wxStaticText* m_labPortFrog2;
    wxStaticText* m_labGateFrog2;
    wxStaticText* m_labRelay1Pol1;
    wxSpinCtrl* m_Addr0Pol1;
    wxSpinCtrl* m_Port0Pol1;
    wxRadioBox* m_Gate0Pol1;
    wxStaticText* m_labRelay1Pol2;
    wxSpinCtrl* m_Addr0Pol2;
    wxSpinCtrl* m_Port0Pol2;
    wxRadioBox* m_Gate0Pol2;
    wxStaticBox* m_Frog2Box;
    wxStaticText* m_labRelayFrog1;
    wxStaticText* m_labAddressFrog1;
    wxStaticText* m_labPortFrog1;
    wxStaticText* m_labGateFrog1;
    wxStaticText* m_labRelay0Pol1;
    wxSpinCtrl* m_Addr1Pol1;
    wxSpinCtrl* m_Port1Pol1;
    wxRadioBox* m_Gate1Pol1;
    wxStaticText* m_labRelay0Pol2;
    wxSpinCtrl* m_Addr1Pol2;
    wxSpinCtrl* m_Port1Pol2;
    wxRadioBox* m_Gate1Pol2;
    wxCheckBox* m_FrogAsSwitch;
    wxCheckBox* m_FrogAccessory;
    wxRadioBox* m_FrogPortType;
    wxPanel* m_TrackdriverPanel;
    wxStaticText* m_labTrackDriverIID;
    wxComboBox* m_TrackDriverIID;
    wxStaticText* m_labTrackDriverAddr;
    wxTextCtrl* m_TrackDriverAddr;
    wxStaticText* m_labTrackDriverPort;
    wxTextCtrl* m_TrackDriverPort;
    wxCheckBox* m_TrackDriverEnable;
    wxButton* m_Cancel;
    wxButton* m_OK;
    wxButton* m_Apply;
    iONode m_Props;
////@end SwitchDialog member variables
};

#endif
    // _SWITCHDIALOG_H_
