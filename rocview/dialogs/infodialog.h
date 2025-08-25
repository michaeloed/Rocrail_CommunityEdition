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
#ifndef _INFODIALOG_H_
#define _INFODIALOG_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "infodialog.cpp"
#endif

/*!
 * Includes
 */
#include <wx/wx.h>
#include <wx/dialog.h>
#include <wx/windowid.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>

////@begin includes
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations
/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DIALOG 10115
#define wxID_STATIC_INFO_BUILD 10002
#define wxID_STATIC_INFO_HOME 10003
#define wxID_STATIC_INFO_SUPPORT 10004
#define wxID_STATIC_INFO_COPYRIGHT 10005
#define WX_STATICTEXT_INFO_THANKS 10289
#define ID_TEXTCTRL_INFO_THANKS 10273
#define SYMBOL_INFODIALOG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_INFODIALOG_TITLE _("Info")
#define SYMBOL_INFODIALOG_IDNAME ID_DIALOG
#define SYMBOL_INFODIALOG_SIZE wxDefaultSize
#define SYMBOL_INFODIALOG_POSITION wxDefaultPosition
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * InfoDialog class declaration
 */

class InfoDialog: public wxDialog {
    DECLARE_DYNAMIC_CLASS( InfoDialog )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    InfoDialog();
    InfoDialog(wxWindow* parent, wxWindowID id = SYMBOL_INFODIALOG_IDNAME,
            const wxString& caption = SYMBOL_INFODIALOG_TITLE,
            const wxPoint& pos = SYMBOL_INFODIALOG_POSITION,
            const wxSize& size = SYMBOL_INFODIALOG_SIZE,
            long style = SYMBOL_INFODIALOG_STYLE);

    /// Creation
    bool Create(wxWindow* parent, wxWindowID id = SYMBOL_INFODIALOG_IDNAME,
            const wxString& caption = SYMBOL_INFODIALOG_TITLE,
            const wxPoint& pos = SYMBOL_INFODIALOG_POSITION,
            const wxSize& size = SYMBOL_INFODIALOG_SIZE,
            long style = SYMBOL_INFODIALOG_STYLE);

    /// Creates the controls and sizers
    void CreateControls();

////@begin InfoDialog event handler declarations

    /// wxEVT_LEFT_UP event handler for wxID_STATIC_INFO_BUILD
    void onBuildRevision(wxMouseEvent& event);

////@end InfoDialog event handler declarations

////@begin InfoDialog member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource(const wxString& name);

    /// Retrieves icon resources
    wxIcon GetIconResource(const wxString& name);
////@end InfoDialog member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin InfoDialog member variables
    wxStaticBitmap* m_Splash;
    wxStaticText* m_Build;
    wxStaticText* m_RocrailVersion;
    wxStaticText* m_RocrailPwd;
    wxStaticText* m_Home;
    wxStaticText* m_Support;
    wxStaticText* m_labLic;
    wxTextCtrl* m_Thanks;
////@end InfoDialog member variables
    ~InfoDialog();
    void OnSplash(wxMouseEvent& event);
};

#endif // _INFODIALOG_H_

