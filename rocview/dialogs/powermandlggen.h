///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __powermandlggen__
#define __powermandlggen__

class basenotebook;

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
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/statbox.h>
#include <wx/listbox.h>
#include <wx/checkbox.h>
#include <wx/notebook.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define ID_BOOSTERBOOK 1000
#define ID_POWERMANAGER_LIST 1001

///////////////////////////////////////////////////////////////////////////////
/// Class powermandlggen
///////////////////////////////////////////////////////////////////////////////
class powermandlggen : public wxDialog 
{
	private:
	
	protected:
		basenotebook* m_BoosterBook;
		wxPanel* m_IndexPanel;
		wxListCtrl* m_BoosterList;
		wxButton* m_AddBooster;
		wxButton* m_DelBooster;
		wxPanel* m_GeneralPanel;
		wxStaticText* m_labID;
		wxTextCtrl* m_ID;
		wxStaticText* m_labIID;
		wxComboBox* m_IID;
		wxStaticText* m_labDistrict;
		wxTextCtrl* m_District;
		wxStaticText* m_labShortcutSensor;
		wxComboBox* m_ShortcutSensor;
		wxStaticText* m_labPowerSensor;
		wxComboBox* m_PowerSensor;
		wxStaticText* m_labPowerOutput;
		wxComboBox* m_PowerOutput;
		wxStaticText* m_labUID;
		wxTextCtrl* m_UID;
		wxPanel* m_ModulesPanel;
		wxListBox* m_ModuleList;
		wxStaticText* m_labModuleID;
		wxTextCtrl* m_ModuleID;
		wxButton* m_AddModule;
		wxButton* m_DelModule;
		wxPanel* m_BlocksPanel;
		wxListBox* m_BlockList;
		wxComboBox* m_BlocksCombo;
		wxButton* m_AddBlock;
		wxButton* m_DelBlock;
		wxPanel* m_DetailsPanel;
		wxCheckBox* m_StopDistrictLocos;
		wxCheckBox* m_PowerOffAll;
		wxCheckBox* m_RetryPowerOn;
		wxCheckBox* m_DoesReport;
		wxButton* m_Actions;
		wxStdDialogButtonSizer* m_stdButton;
		wxButton* m_stdButtonOK;
		wxButton* m_stdButtonApply;
		wxButton* m_stdButtonCancel;
		wxButton* m_stdButtonHelp;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onBoosterListColumn( wxListEvent& event ) { event.Skip(); }
		virtual void onBoosterSelect( wxListEvent& event ) { event.Skip(); }
		virtual void OnAddBooster( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelBooster( wxCommandEvent& event ) { event.Skip(); }
		virtual void onModuleSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddModule( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelModule( wxCommandEvent& event ) { event.Skip(); }
		virtual void onBlockSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddBlock( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelBlock( wxCommandEvent& event ) { event.Skip(); }
		virtual void onActions( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnApply( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHelp( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		powermandlggen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Power districts setup"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~powermandlggen();
	
};

#endif //__powermandlggen__
