///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __bidibdlggen__
#define __bidibdlggen__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/listbox.h>
#include <wx/button.h>
#include <wx/notebook.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class bidibdlggen
///////////////////////////////////////////////////////////////////////////////
class bidibdlggen : public wxDialog 
{
	private:
	
	protected:
		wxNotebook* m_Notebook;
		wxPanel* m_General;
		wxStaticText* m_labIID;
		wxTextCtrl* m_IID;
		wxStaticText* m_labDevice;
		wxComboBox* m_Device;
		wxStaticText* m_labHost;
		wxTextCtrl* m_Host;
		wxStaticText* m_labPort;
		wxSpinCtrl* m_Port;
		wxRadioBox* m_BPS;
		wxCheckBox* m_CTS;
		wxRadioBox* m_SubLib;
		wxPanel* m_Options;
		wxCheckBox* m_SecAck;
		wxStaticText* m_labSecAckInt;
		wxSpinCtrl* m_SecAckInt;
		wxStaticText* m_labMs10;
		wxPanel* m_Nodes;
		wxListBox* m_NodeList;
		wxButton* m_ConfigureNodes;
		wxStdDialogButtonSizer* m_StdButton;
		wxButton* m_StdButtonOK;
		wxButton* m_StdButtonCancel;
		wxButton* m_StdButtonHelp;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onSubLib( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNodeList( wxCommandEvent& event ) { event.Skip(); }
		virtual void onConfigureNodes( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHelp( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		bidibdlggen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("BiDiB Setup"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~bidibdlggen();
	
};

#endif //__bidibdlggen__
