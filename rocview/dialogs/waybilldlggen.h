///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __waybilldlggen__
#define __waybilldlggen__

class basenotebook;

#include <wx/string.h>
#include <wx/listbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/radiobox.h>
#include <wx/notebook.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class waybillgen
///////////////////////////////////////////////////////////////////////////////
class waybillgen : public wxDialog 
{
	private:
	
	protected:
		basenotebook* m_WaybillBook;
		wxPanel* m_IndexPanel;
		wxListBox* m_WaybillList;
		wxButton* m_NewWaybill;
		wxButton* m_DeleteWaybill;
		wxButton* m_Copy;
		wxPanel* m_GeneralPanel;
		wxStaticText* m_labID;
		wxTextCtrl* m_ID;
		wxStaticText* m_labShipper;
		wxTextCtrl* m_Shipper;
		wxStaticText* m_labOrigin;
		wxComboBox* m_Origin;
		wxStaticText* m_labConsignee;
		wxTextCtrl* m_Consignee;
		wxStaticText* m_labDestination;
		wxComboBox* m_Destination;
		wxStaticText* m_labCommodity;
		wxTextCtrl* m_Commodity;
		wxStaticText* m_labCartype;
		wxComboBox* m_Cartype;
		wxRadioBox* m_Status;
		wxPanel* m_RoutingPanel;
		wxTextCtrl* m_Routing;
		wxStdDialogButtonSizer* m_stdButton;
		wxButton* m_stdButtonOK;
		wxButton* m_stdButtonApply;
		wxButton* m_stdButtonCancel;
		wxButton* m_stdButtonHelp;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onWaybillList( wxCommandEvent& event ) { event.Skip(); }
		virtual void onNewWaybill( wxCommandEvent& event ) { event.Skip(); }
		virtual void onDeleteWaybill( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCopy( wxCommandEvent& event ) { event.Skip(); }
		virtual void onApply( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void onHelp( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		waybillgen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Waybill Table"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~waybillgen();
	
};

#endif //__waybilldlggen__
