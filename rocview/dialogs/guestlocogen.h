///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __guestlocogen__
#define __guestlocogen__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/spinctrl.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/radiobox.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class GuestLocoGen
///////////////////////////////////////////////////////////////////////////////
class GuestLocoGen : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_labAddress;
		wxSpinCtrl* m_Address;
		wxStaticText* m_labShortID;
		wxTextCtrl* m_ShortID;
		wxRadioBox* m_Speedsteps;
		wxRadioBox* m_Protocol;
		wxStdDialogButtonSizer* m_StdButton;
		wxButton* m_StdButtonOK;
		wxButton* m_StdButtonCancel;
		wxButton* m_StdButtonHelp;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void onHelp( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		GuestLocoGen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Guest Loco"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~GuestLocoGen();
	
};

#endif //__guestlocogen__
