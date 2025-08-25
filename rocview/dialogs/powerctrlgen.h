///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __powerctrlgen__
#define __powerctrlgen__

#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/font.h>
#include <wx/grid.h>
#include <wx/gdicmn.h>
#include <wx/stattext.h>
#include "rocview/dialogs/historypanel.h"
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class powerctrlgen
///////////////////////////////////////////////////////////////////////////////
class powerctrlgen : public wxFrame 
{
	private:
	
	protected:
		wxGrid* m_Boosters;
		wxStaticText* m_labHistory;
		HistoryPanel* m_HistoryPanel;
		wxButton* m_On;
		wxButton* m_Off;
		wxButton* m_ResetStat;
		wxStdDialogButtonSizer* m_stdButton;
		wxButton* m_stdButtonOK;
		wxButton* m_stdButtonHelp;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void onSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void onCellLeftClick( wxGridEvent& event ) { event.Skip(); }
		virtual void onCellRightClick( wxGridEvent& event ) { event.Skip(); }
		virtual void onLabelLeftClick( wxGridEvent& event ) { event.Skip(); }
		virtual void OnOn( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOff( wxCommandEvent& event ) { event.Skip(); }
		virtual void onResetStat( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHelp( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		powerctrlgen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Power Control"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxCAPTION|wxCLOSE_BOX|wxFRAME_FLOAT_ON_PARENT|wxRESIZE_BORDER|wxTAB_TRAVERSAL );
		~powerctrlgen();
	
};

#endif //__powerctrlgen__
