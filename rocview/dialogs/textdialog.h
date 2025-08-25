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
#ifndef _TEXTDIALOG_H_
#define _TEXTDIALOG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "textdialog.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/notebook.h"
#include "wx/listctrl.h"
#include "wx/spinctrl.h"
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
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DIALOG_TEXT_PROPS 10282
#define ID_NOTEBOOK_TEXT 10005
#define ID_INDEX_PANEL 10000
#define ID_INDEXLIST 10467
#define ID_NEWTEXT 10468
#define ID_DELETETEXT 10469
#define ID_GEN_PANEL 10006
#define ID_STATICTEXT_TEXT_ID 10007
#define ID_TEXTCTRL_TEXT_ID 10008
#define ID_STATICTEXT_TEXT_TEXT 10017
#define ID_TEXTCTRL_TEXT_TEXT 10283
#define ID_BUTTON_TXT_IMAGE 10348
#define ID_STATICTEXT_TEXT_TIP 10019
#define ID_TEXTCTRL_TEXT_TIP 10284
#define wxID_STATIC_TX_POINT 10160
#define ID_TEXTCTRL_TX_POINT 10161
#define ID_BUTTON_TEXT_COLOR 10220
#define ID_BUTTON_TEXT_BACKGROUND 10351
#define ID_TEXT_ACTIONS 10387
#define ID_INT_PANEL 10399
#define ID_LOC_PANEL 10021
#define ID_STATICTEXT_TEXT_X 10022
#define ID_TEXTCTRL_TEXT_X 10023
#define ID_STATICTEXT_TEXT_Y 10024
#define ID_TEXTCTRL_TEXT_Y 10025
#define ID_STATICTEXT_TEXT_Z 10026
#define ID_TEXTCTRL_TEXT_Z 10027
#define wxID_STATICTEXT_TEXT_CX 10287
#define ID_TEXTCTRL_TEXT_CX 10285
#define wxID_STATICTEXT_TEXT_CY 10288
#define ID_TEXTCTRL_TEXT_CY 10286
#define SYMBOL_TEXTDIALOG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_TEXTDIALOG_TITLE _("Text Properties")
#define SYMBOL_TEXTDIALOG_IDNAME ID_DIALOG_TEXT_PROPS
#define SYMBOL_TEXTDIALOG_SIZE wxDefaultSize
#define SYMBOL_TEXTDIALOG_POSITION wxDefaultPosition
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * TextDialog class declaration
 */

class TextDialog: public wxDialog, public BaseDialog
{
    DECLARE_DYNAMIC_CLASS( TextDialog )
    DECLARE_EVENT_TABLE()

  void initLabels();
  void initValues();
  bool evaluate();
  bool initIndex();
  int m_TabAlign;

public:
    /// Constructors
    TextDialog( );
    TextDialog( wxWindow* parent, iONode p_Props );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_TEXTDIALOG_IDNAME, const wxString& caption = SYMBOL_TEXTDIALOG_TITLE, const wxPoint& pos = SYMBOL_TEXTDIALOG_POSITION, const wxSize& size = SYMBOL_TEXTDIALOG_SIZE, long style = SYMBOL_TEXTDIALOG_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin TextDialog event handler declarations

    /// wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ID_INDEXLIST
    void OnIndexlistSelected( wxListEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_NEWTEXT
    void OnNewtextClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_DELETETEXT
    void OnDeletetextClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_TXT_IMAGE
    void OnButtonTxtImageClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_TEXT_COLOR
    void OnButtonTextColorClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_TEXT_BACKGROUND
    void OnButtonTextBackgroundClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_TEXT_ACTIONS
    void OnTextActionsClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
    void OnOkClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
    void OnCancelClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
    void OnHelpClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_APPLY
    void OnApplyClick( wxCommandEvent& event );

////@end TextDialog event handler declarations

////@begin TextDialog member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end TextDialog member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin TextDialog member variables
    wxNotebook* m_Notebook;
    wxPanel* m_IndexPanel;
    wxListCtrl* m_IndexList;
    wxButton* m_New;
    wxButton* m_Delete;
    wxPanel* m_GeneralPanel;
    wxStaticText* m_LabelID;
    wxTextCtrl* m_ID;
    wxStaticText* m_LabelText;
    wxTextCtrl* m_Text;
    wxStaticText* m_labImage;
    wxButton* m_ImageButton;
    wxStaticText* m_LabelTip;
    wxTextCtrl* m_Tip;
    wxStaticText* m_labPointsize;
    wxTextCtrl* m_Pointsize;
    wxStaticText* m_labColor;
    wxButton* m_Color;
    wxStaticText* m_labBackColor;
    wxButton* m_Background;
    wxStaticBox* m_AttributesBox;
    wxCheckBox* m_Bold;
    wxCheckBox* m_Underlined;
    wxCheckBox* m_Italic;
    wxCheckBox* m_Transparent;
    wxCheckBox* m_Input;
    wxCheckBox* m_Border;
    wxCheckBox* m_Clock;
    wxRadioBox* m_Ori;
    wxCheckBox* m_Reset;
    wxButton* m_Actions;
    wxPanel* m_InterfacePanel;
    wxStaticText* m_labIID;
    wxComboBox* m_IID;
    wxStaticText* m_labBus;
    wxTextCtrl* m_Bus;
    wxStaticText* m_labAddress;
    wxSpinCtrl* m_Address;
    wxStaticText* m_labDisplay;
    wxSpinCtrl* m_Display;
    wxPanel* m_LocationPanel;
    wxStaticText* m_LabelX;
    wxTextCtrl* m_x;
    wxStaticText* m_LabelY;
    wxTextCtrl* m_y;
    wxStaticText* m_LabelZ;
    wxTextCtrl* m_z;
    wxStaticText* m_LabelCx;
    wxTextCtrl* m_Cx;
    wxStaticText* m_LabelCy;
    wxTextCtrl* m_Cy;
    wxButton* m_OK;
    wxButton* m_Cancel;
    wxButton* m_Help;
    wxButton* m_Apply;
////@end TextDialog member variables
    iONode m_Props;
};

#endif
    // _TEXTDIALOG_H_
