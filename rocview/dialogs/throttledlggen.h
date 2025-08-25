///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __throttledlggen__
#define __throttledlggen__

#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/button.h>
#include "rocview/public/ledbutton.h"
#include "rocview/public/slider.h"
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class ThrottleDlgGen
///////////////////////////////////////////////////////////////////////////////
class ThrottleDlgGen : public wxFrame 
{
	private:
	
	protected:
		wxBitmapButton* m_LocoImage;
		LEDButton* m_Speed;
		Slider* m_SpeedSlider;
		LEDButton* m_SwitchAddr;
		wxTextCtrl* m_BinState;
		wxStaticLine* m_staticline5;
		LEDButton* m_F1;
		LEDButton* m_F2;
		LEDButton* m_F3;
		LEDButton* m_F4;
		LEDButton* m_F5;
		LEDButton* m_F6;
		LEDButton* m_F7;
		LEDButton* m_F8;
		LEDButton* m_F9;
		LEDButton* m_F10;
		LEDButton* m_F11;
		LEDButton* m_F12;
		LEDButton* m_F13;
		LEDButton* m_F14;
		LEDButton* m_F0;
		LEDButton* m_FG;
		LEDButton* m_Stop;
		LEDButton* m_Dir;
		LEDButton* m_Break;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void onBinStateKey( wxKeyEvent& event ) { event.Skip(); }
		
	
	public:
		
		ThrottleDlgGen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Throttle"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxCAPTION|wxCLOSE_BOX|wxFRAME_FLOAT_ON_PARENT|wxRESIZE_BORDER|wxTAB_TRAVERSAL );
		~ThrottleDlgGen();
	
};

#endif //__throttledlggen__
