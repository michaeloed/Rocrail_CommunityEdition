///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __cardlggen__
#define __cardlggen__

class basenotebook;

#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/listctrl.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/statline.h>
#include <wx/radiobox.h>
#include <wx/spinctrl.h>
#include <wx/statbox.h>
#include <wx/grid.h>
#include <wx/notebook.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

#define ID_CARBOOK 1000

///////////////////////////////////////////////////////////////////////////////
/// Class cardlggen
///////////////////////////////////////////////////////////////////////////////
class cardlggen : public wxDialog 
{
	private:
	
	protected:
		wxBitmapButton* m_CarImage;
		basenotebook* m_CarBook;
		wxPanel* m_IndexPanel;
		wxListCtrl* m_CarList2;
		wxButton* m_NewCar;
		wxButton* m_DeleteCar;
		wxButton* m_Import;
		wxButton* m_Copy;
		wxButton* m_Doc;
		wxCheckBox* m_Show;
		wxCheckBox* m_ShowAll;
		wxPanel* m_GeneralPanel;
		wxStaticText* m_labID;
		wxTextCtrl* m_ID;
		wxStaticText* m_labIdent;
		wxTextCtrl* m_Ident;
		wxStaticText* m_labLocation;
		wxComboBox* m_Location;
		wxStaticText* m_labRoadname;
		wxTextCtrl* m_Roadname;
		wxStaticText* m_labNumber;
		wxTextCtrl* m_Number;
		wxStaticText* m_labColor;
		wxTextCtrl* m_Color;
		wxStaticText* m_labImageName;
		wxTextCtrl* m_ImageName;
		wxButton* m_ImageChooser;
		wxStaticText* m_labOwner;
		wxTextCtrl* m_Owner;
		wxStaticLine* m_staticline1;
		wxRadioBox* m_Status;
		wxPanel* m_DetailsPanel;
		wxRadioBox* m_Type;
		wxCheckBox* m_Commuter;
		wxStaticText* m_labSubtype;
		wxComboBox* m_SubType;
		wxStaticText* m_labLength;
		wxSpinCtrl* m_Length;
		wxStaticText* m_labWeight;
		wxStaticText* m_labWeightEmpty;
		wxSpinCtrl* m_WeightEmpty;
		wxStaticText* m_labWeightLoaded;
		wxSpinCtrl* m_WeightLoaded;
		wxStaticText* m_labManuId;
		wxTextCtrl* m_ManuId;
		wxStaticText* m_labVMax;
		wxSpinCtrl* m_VMax;
		wxRadioBox* m_Era;
		wxStaticText* m_labRemark;
		wxTextCtrl* m_Remark;
		wxPanel* m_InterfacePanel;
		wxStaticText* m_labBus;
		wxTextCtrl* m_Bus;
		wxStaticText* m_labIID;
		wxComboBox* m_IID;
		wxStaticText* m_labAddr;
		wxSpinCtrl* m_Addr;
		wxStaticText* m_labProtocol;
		wxComboBox* m_Protocol;
		wxStaticText* m_labProtVersion;
		wxTextCtrl* m_ProtVersion;
		wxStaticText* m_labSteps;
		wxSpinCtrl* m_SpeedSteps;
		wxStaticBoxSizer* m_IntOptions;
		wxCheckBox* m_UseDir;
		wxCheckBox* m_InvDir;
		wxCheckBox* m_Placing;
		wxCheckBox* m_UseLights;
		wxSpinCtrl* m_FnLights;
		wxCheckBox* m_F0VCmd;
		wxPanel* m_FunctionPanel;
		wxStaticText* m_labFNumber;
		wxStaticText* m_labFDesc;
		wxStaticText* m_labFx;
		wxStaticText* m_labIcon;
		wxStaticText* m_F0;
		wxTextCtrl* m_F0Desc;
		wxSpinCtrl* m_F0x;
		wxTextCtrl* m_F0Icon;
		wxStaticText* m_F1;
		wxTextCtrl* m_F1Desc;
		wxSpinCtrl* m_F1x;
		wxTextCtrl* m_F1Icon;
		wxStaticText* m_F2;
		wxTextCtrl* m_F2Desc;
		wxSpinCtrl* m_F2x;
		wxTextCtrl* m_F2Icon;
		wxStaticText* m_F3;
		wxTextCtrl* m_F3Desc;
		wxSpinCtrl* m_F3x;
		wxTextCtrl* m_F3Icon;
		wxStaticText* m_F4;
		wxTextCtrl* m_F4Desc;
		wxSpinCtrl* m_F4x;
		wxTextCtrl* m_F4Icon;
		wxButton* m_FG;
		wxPanel* m_CVPanel;
		wxGrid* m_CVList;
		wxStaticText* m_labCVDesc;
		wxTextCtrl* m_CVDescription;
		wxButton* m_CVDescModify;
		wxStdDialogButtonSizer* m_stdButton;
		wxButton* m_stdButtonOK;
		wxButton* m_stdButtonApply;
		wxButton* m_stdButtonCancel;
		wxButton* m_stdButtonHelp;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onCarImage( wxCommandEvent& event ) { event.Skip(); }
		virtual void onListColClick( wxListEvent& event ) { event.Skip(); }
		virtual void onCarList2( wxListEvent& event ) { event.Skip(); }
		virtual void onNewCar( wxCommandEvent& event ) { event.Skip(); }
		virtual void onDeleteCar( wxCommandEvent& event ) { event.Skip(); }
		virtual void onImport( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCopy( wxCommandEvent& event ) { event.Skip(); }
		virtual void onDoc( wxCommandEvent& event ) { event.Skip(); }
		virtual void onShow( wxCommandEvent& event ) { event.Skip(); }
		virtual void onListAvailableOnly( wxCommandEvent& event ) { event.Skip(); }
		virtual void onImageChooser( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTypeSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void onF0Icon( wxMouseEvent& event ) { event.Skip(); }
		virtual void onF1Icon( wxMouseEvent& event ) { event.Skip(); }
		virtual void onF2Icon( wxMouseEvent& event ) { event.Skip(); }
		virtual void onF3Icon( wxMouseEvent& event ) { event.Skip(); }
		virtual void onF4Icon( wxMouseEvent& event ) { event.Skip(); }
		virtual void onFG( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCVCell( wxGridEvent& event ) { event.Skip(); }
		virtual void onCVModify( wxCommandEvent& event ) { event.Skip(); }
		virtual void onApply( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void onHelp( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		cardlggen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Car Table"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~cardlggen();
	
};

#endif //__cardlggen__
