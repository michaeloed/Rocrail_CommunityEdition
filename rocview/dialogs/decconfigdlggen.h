///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __decconfigdlggen__
#define __decconfigdlggen__

#include <wx/string.h>
#include <wx/checkbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class decconfigdlggen
///////////////////////////////////////////////////////////////////////////////
class decconfigdlggen : public wxDialog 
{
	private:
	
	protected:
		wxCheckBox* m_Direction;
		wxCheckBox* m_SpeedSteps;
		wxCheckBox* m_DCOperation;
		wxCheckBox* m_UserSpeedCurve;
		wxCheckBox* m_ExtAddressing;
		wxCheckBox* m_RailCom;
		wxStdDialogButtonSizer* m_stdButton;
		wxButton* m_stdButtonOK;
		wxButton* m_stdButtonCancel;
		wxButton* m_stdButtonHelp;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void onHelp( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		decconfigdlggen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Decoder Configuration"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~decconfigdlggen();
	
};

#endif //__decconfigdlggen__
