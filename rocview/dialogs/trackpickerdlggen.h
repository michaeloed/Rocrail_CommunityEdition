///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __trackpickerdlggen__
#define __trackpickerdlggen__

#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/font.h>
#include <wx/grid.h>
#include <wx/gdicmn.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/listbook.h>
#include <wx/listctrl.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class TrackPickerDlgGen
///////////////////////////////////////////////////////////////////////////////
class TrackPickerDlgGen : public wxFrame 
{
	private:
	
	protected:
		wxListbook* m_TrackBook;
		wxPanel* m_PageTrack;
		wxGrid* m_GridTrack;
		wxPanel* m_PageSwitch;
		wxGrid* m_GridSwitch;
		wxPanel* m_PageSignal;
		wxGrid* m_GridSignal;
		wxPanel* m_PageBlock;
		wxGrid* m_GridBlock;
		wxPanel* m_PageSensor;
		wxGrid* m_GridSensor;
		wxPanel* m_PageAccessory;
		wxGrid* m_GridAccessory;
		wxPanel* m_PageRoad;
		wxGrid* m_GridRoad;
		wxButton* m_Help;
		wxTextCtrl* m_Tip;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void onPageChanged( wxListbookEvent& event ) { event.Skip(); }
		virtual void onTrackCellLeftClick( wxGridEvent& event ) { event.Skip(); }
		virtual void onHelp( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		TrackPickerDlgGen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxCAPTION|wxCLOSE_BOX|wxFRAME_FLOAT_ON_PARENT|wxRESIZE_BORDER|wxTAB_TRAVERSAL );
		~TrackPickerDlgGen();
	
};

#endif //__trackpickerdlggen__
