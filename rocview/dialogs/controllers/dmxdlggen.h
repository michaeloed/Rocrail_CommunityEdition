///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __dmxdlggen__
#define __dmxdlggen__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class dmxdlggen
///////////////////////////////////////////////////////////////////////////////
class dmxdlggen : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_labIID;
		wxTextCtrl* m_IID;
		wxStaticText* m_labHost;
		wxTextCtrl* m_Host;
		wxStaticText* m_labFrameRate;
		wxSpinCtrl* m_FrameRate;
		wxStaticText* m_labFrameRateMS;
		wxCheckBox* m_MapWhite;
		wxCheckBox* m_RestoreData;
		wxStdDialogButtonSizer* m_stdButtons;
		wxButton* m_stdButtonsOK;
		wxButton* m_stdButtonsCancel;
		wxButton* m_stdButtonsHelp;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void onHelp( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		dmxdlggen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("DMX"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~dmxdlggen();
	
};

#endif //__dmxdlggen__
