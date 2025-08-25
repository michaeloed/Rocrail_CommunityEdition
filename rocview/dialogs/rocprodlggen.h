///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __rocprodlggen__
#define __rocprodlggen__

#include <wx/treectrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/combobox.h>
#include <wx/button.h>
#include <wx/spinctrl.h>
#include <wx/checkbox.h>
#include <wx/slider.h>
#include <wx/radiobox.h>
#include <wx/statbox.h>
#include <wx/tglbtn.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class RocProDlgGen
///////////////////////////////////////////////////////////////////////////////
class RocProDlgGen : public wxDialog 
{
	private:
	
	protected:
		wxTreeCtrl* m_DecTree;
		wxStaticText* m_labInfo;
		wxTextCtrl* m_Info;
		wxStaticLine* m_staticline2;
		wxBoxSizer* m_ImageSizer;
		wxStaticBitmap* m_LocoImage;
		wxStaticLine* m_staticline21;
		wxStaticBitmap* m_DecoderImage;
		wxStaticText* m_labIID;
		wxComboBox* m_IID;
		wxComboBox* m_LocoList;
		wxStaticText* m_labFile;
		wxTextCtrl* m_DecFile;
		wxButton* m_DecFileOpen;
		wxButton* m_SaveAs;
		wxStaticText* m_labImage;
		wxTextCtrl* m_Image;
		wxButton* m_ImgFileOpen;
		wxStaticText* m_labNr;
		wxStaticText* m_labValue;
		wxStaticText* m_labHexValue;
		wxStaticText* m_staticText4;
		wxStaticText* m_staticText5;
		wxStaticText* m_staticText6;
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText8;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText10;
		wxStaticText* m_staticText11;
		wxSpinCtrl* m_Nr;
		wxSpinCtrl* m_Value;
		wxTextCtrl* m_HexValue;
		wxCheckBox* m_Bit7;
		wxCheckBox* m_Bit6;
		wxCheckBox* m_Bit5;
		wxCheckBox* m_Bit4;
		wxCheckBox* m_Bit3;
		wxCheckBox* m_Bit2;
		wxCheckBox* m_Bit1;
		wxCheckBox* m_Bit0;
		wxSlider* m_ValueSlider;
		wxButton* m_ReadCV;
		wxButton* m_ReadAllCV;
		wxButton* m_WriteCV;
		wxCheckBox* m_POM;
		wxCheckBox* m_Accessory;
		wxCheckBox* m_SaveCV;
		wxRadioBox* m_Mode;
		wxSpinCtrl* m_ExtAddr;
		wxButton* m_ExtAddrRead;
		wxButton* m_ExtAddrWrite;
		wxCheckBox* m_ExtAddrBidi;
		wxButton* m_VCurve;
		wxButton* m_CVURL;
		wxButton* m_DIP;
		wxToggleButton* m_PT;
		wxStdDialogButtonSizer* m_sdbSizer2;
		wxButton* m_sdbSizer2OK;
		wxButton* m_sdbSizer2Help;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void onTreeDIP( wxTreeEvent& event ) { event.Skip(); }
		virtual void onTreeItemPopup( wxTreeEvent& event ) { event.Skip(); }
		virtual void onTreeSelChanged( wxTreeEvent& event ) { event.Skip(); }
		virtual void onCVInfoEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void onLocoList( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSaveAs( wxCommandEvent& event ) { event.Skip(); }
		virtual void onImgOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void onNr( wxSpinEvent& event ) { event.Skip(); }
		virtual void onNrText( wxCommandEvent& event ) { event.Skip(); }
		virtual void onValue( wxSpinEvent& event ) { event.Skip(); }
		virtual void onValueText( wxCommandEvent& event ) { event.Skip(); }
		virtual void onHexValue( wxCommandEvent& event ) { event.Skip(); }
		virtual void onBit( wxCommandEvent& event ) { event.Skip(); }
		virtual void onValueSlider( wxScrollEvent& event ) { event.Skip(); }
		virtual void onRead( wxCommandEvent& event ) { event.Skip(); }
		virtual void onReadAllCV( wxCommandEvent& event ) { event.Skip(); }
		virtual void onWrite( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSaveCV( wxCommandEvent& event ) { event.Skip(); }
		virtual void onExtAddrRead( wxCommandEvent& event ) { event.Skip(); }
		virtual void onExtAddrWrite( wxCommandEvent& event ) { event.Skip(); }
		virtual void onVCurve( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCVURL( wxCommandEvent& event ) { event.Skip(); }
		virtual void onDIP( wxCommandEvent& event ) { event.Skip(); }
		virtual void onPT( wxCommandEvent& event ) { event.Skip(); }
		virtual void onHelp( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		RocProDlgGen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("RocPro"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~RocProDlgGen();
	
};

#endif //__rocprodlggen__
