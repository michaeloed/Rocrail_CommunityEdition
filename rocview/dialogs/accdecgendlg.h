///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __accdecgendlg__
#define __accdecgendlg__

#include <wx/listctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/stattext.h>
#include <wx/combobox.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/grid.h>
#include <wx/notebook.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class AccDecGenDlg
///////////////////////////////////////////////////////////////////////////////
class AccDecGenDlg : public wxDialog 
{
	private:
	
	protected:
		wxNotebook* m_Notebook;
		wxPanel* m_IndexPanel;
		wxListCtrl* m_IndexList;
		wxButton* m_Add;
		wxButton* m_Delete;
		wxButton* m_Doc;
		wxPanel* m_GeneralPanel;
		wxBitmapButton* m_Image;
		wxStaticText* m_labIID;
		wxComboBox* m_IID;
		wxStaticText* m_labID;
		wxTextCtrl* m_ID;
		wxStaticText* m_labImageFile;
		wxTextCtrl* m_ImageFile;
		wxStaticText* m_labBus;
		wxTextCtrl* m_Bus;
		wxStaticText* m_labAddr;
		wxSpinCtrl* m_Addr;
		wxStaticText* m_labProt;
		wxComboBox* m_Protocol;
		wxStaticText* m_labVersion;
		wxSpinCtrl* m_Version;
		wxStaticText* m_labManu;
		wxTextCtrl* m_Manu;
		wxStaticText* m_labCatNr;
		wxTextCtrl* m_CatNr;
		wxStaticText* m_labDesc;
		wxTextCtrl* m_Desc;
		wxPanel* m_CVPanel;
		wxGrid* m_CVList;
		wxStaticText* m_labCVDesc;
		wxTextCtrl* m_CVDescription;
		wxButton* m_CVDescModify;
		wxStdDialogButtonSizer* m_StdButton;
		wxButton* m_StdButtonOK;
		wxButton* m_StdButtonApply;
		wxButton* m_StdButtonCancel;
		wxButton* m_StdButtonHelp;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onColClick( wxListEvent& event ) { event.Skip(); }
		virtual void onSelected( wxListEvent& event ) { event.Skip(); }
		virtual void onAdd( wxCommandEvent& event ) { event.Skip(); }
		virtual void onDelete( wxCommandEvent& event ) { event.Skip(); }
		virtual void onDoc( wxCommandEvent& event ) { event.Skip(); }
		virtual void onImage( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCVCell( wxGridEvent& event ) { event.Skip(); }
		virtual void onCVModify( wxCommandEvent& event ) { event.Skip(); }
		virtual void onApply( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void onHelp( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AccDecGenDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Accessory Decoders"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~AccDecGenDlg();
	
};

#endif //__accdecgendlg__
