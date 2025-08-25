///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __fxdlggen__
#define __fxdlggen__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/radiobox.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class fxdlggen
///////////////////////////////////////////////////////////////////////////////
class fxdlggen : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_labCVNr;
		wxSpinCtrl* m_CVNumber;
		wxStaticText* m_labCVValue;
		wxSpinCtrl* m_CVValue;
		wxRadioBox* m_Function;
		wxRadioBox* m_Generation;
		wxRadioBox* m_Work;
		wxStdDialogButtonSizer* m_sdButtons;
		wxButton* m_sdButtonsOK;
		wxButton* m_sdButtonsCancel;
		wxButton* m_sdButtonsHelp;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onFunction( wxCommandEvent& event ) { event.Skip(); }
		virtual void onGeneration( wxCommandEvent& event ) { event.Skip(); }
		virtual void onActivation( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void onHelp( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		fxdlggen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("FX Setup"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~fxdlggen();
	
};

#endif //__fxdlggen__
