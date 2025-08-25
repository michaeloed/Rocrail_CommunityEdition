///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __hueconfdlggen__
#define __hueconfdlggen__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/combobox.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/grid.h>
#include <wx/slider.h>
#include <wx/notebook.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class HueConfDlgGen
///////////////////////////////////////////////////////////////////////////////
class HueConfDlgGen : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_labIID;
		wxComboBox* m_IID;
		wxStaticBitmap* m_HueLogo;
		wxNotebook* m_HueBook;
		wxPanel* m_BridgePanel;
		wxStaticText* m_labBridgeName;
		wxTextCtrl* m_BridgeName;
		wxButton* m_SetBridgeName;
		wxStaticText* m_labBridgeIP;
		wxTextCtrl* m_BridgeIP;
		wxStaticText* m_labBridgeFirmware;
		wxTextCtrl* m_BridgeFirmware;
		wxStaticText* m_labBridgeAPI;
		wxTextCtrl* m_BridgeAPI;
		wxStaticText* m_labBridgeZigbee;
		wxTextCtrl* m_BridgeZigbee;
		wxStaticText* m_labBridgeUserName;
		wxComboBox* m_BridgeUserName;
		wxButton* m_SetBridgeUserName;
		wxButton* m_GetBridge;
		wxPanel* m_LightsPanel;
		wxGrid* m_LightsGrid;
		wxStaticText* m_labChangedLight;
		wxButton* m_GetLights;
		wxButton* m_FindLights;
		wxButton* m_SetLight;
		wxButton* m_LightOn;
		wxButton* m_LightOff;
		wxSlider* m_Brightness;
		wxStdDialogButtonSizer* m_stdButtons;
		wxButton* m_stdButtonsOK;
		wxButton* m_stdButtonsHelp;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void onBridgeNameSet( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSetBridgeUserName( wxCommandEvent& event ) { event.Skip(); }
		virtual void onBridgeGet( wxCommandEvent& event ) { event.Skip(); }
		virtual void onLightCellChange( wxGridEvent& event ) { event.Skip(); }
		virtual void onLightCellDClick( wxGridEvent& event ) { event.Skip(); }
		virtual void onLightCellSelect( wxGridEvent& event ) { event.Skip(); }
		virtual void onGetLights( wxCommandEvent& event ) { event.Skip(); }
		virtual void onFindLights( wxCommandEvent& event ) { event.Skip(); }
		virtual void onLightSet( wxCommandEvent& event ) { event.Skip(); }
		virtual void onLightOn( wxCommandEvent& event ) { event.Skip(); }
		virtual void onLightOff( wxCommandEvent& event ) { event.Skip(); }
		virtual void onBrightness( wxScrollEvent& event ) { event.Skip(); }
		virtual void onBrightnessThumbRelease( wxScrollEvent& event ) { event.Skip(); }
		virtual void onHelp( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		HueConfDlgGen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("HUE Config"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~HueConfDlgGen();
	
};

#endif //__hueconfdlggen__
