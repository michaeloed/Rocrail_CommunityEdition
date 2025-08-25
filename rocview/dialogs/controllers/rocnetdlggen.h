///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __rocnetdlggen__
#define __rocnetdlggen__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/statbox.h>
#include <wx/statline.h>
#include <wx/combobox.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class rocnetdlggen
///////////////////////////////////////////////////////////////////////////////
class rocnetdlggen : public wxDialog 
{
	private:
	
	protected:
		wxNotebook* m_Nodebook;
		wxPanel* m_ConnectionPanel;
		wxStaticText* m_labIID;
		wxTextCtrl* m_IID;
		wxStaticText* m_labRocNetID;
		wxSpinCtrl* m_RNID;
		wxRadioBox* m_Sublib;
		wxStaticBoxSizer* m_OptionsBox;
		wxCheckBox* m_CRC;
		wxCheckBox* m_Watchdog;
		wxCheckBox* m_Sack;
		wxCheckBox* m_ShutdownAll;
		wxCheckBox* m_WatchNodes;
		wxStaticLine* m_staticline1;
		wxStaticText* m_labDevice;
		wxComboBox* m_Device;
		wxRadioBox* m_BPS;
		wxStaticLine* m_staticline2;
		wxStaticText* m_labAddress;
		wxTextCtrl* m_Address;
		wxStaticText* m_labPort;
		wxSpinCtrl* m_Port;
		wxStaticBoxSizer* m_LocoOptions;
		wxStaticText* m_labLocoBus;
		wxSpinCtrl* m_LocoBus;
		wxPanel* m_NodesPanel;
		wxListCtrl* m_NodeList;
		wxStdDialogButtonSizer* m_StdButton;
		wxButton* m_StdButtonOK;
		wxButton* m_StdButtonCancel;
		wxButton* m_StdButtonHelp;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSublib( wxCommandEvent& event ) { event.Skip(); }
		virtual void onNodeListSelected( wxListEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHelp( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		rocnetdlggen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("RocNet"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~rocnetdlggen();
	
};

#endif //__rocnetdlggen__
