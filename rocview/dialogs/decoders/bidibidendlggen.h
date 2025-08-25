///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 12 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __bidibidendlggen__
#define __bidibidendlggen__

#include <wx/treectrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/statline.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/listbox.h>
#include <wx/spinctrl.h>
#include <wx/statbox.h>
#include <wx/checkbox.h>
#include <wx/slider.h>
#include <wx/radiobox.h>
#include <wx/grid.h>
#include <wx/combobox.h>
#include <wx/gauge.h>
#include <wx/notebook.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class BidibIdentDlgGen
///////////////////////////////////////////////////////////////////////////////
class BidibIdentDlgGen : public wxFrame 
{
	private:
	
	protected:
		wxNotebook* m_Notebook;
		wxPanel* m_IndexPanel;
		wxTreeCtrl* m_Tree;
		wxStaticLine* m_staticline1;
		wxStaticBitmap* m_BiDiBlogo;
		wxStaticText* m_labPath;
		wxTextCtrl* m_Path;
		wxStaticText* m_labVendor;
		wxTextCtrl* m_VID;
		wxTextCtrl* m_VIDD;
		wxTextCtrl* m_VendorName;
		wxStaticText* m_labProduct;
		wxTextCtrl* m_PID;
		wxTextCtrl* m_PIDD;
		wxTextCtrl* m_ProductName;
		wxStaticText* m_labClass;
		wxTextCtrl* m_Class;
		wxStaticText* m_labUsername;
		wxTextCtrl* m_Username;
		wxButton* m_UsernameSet;
		wxStaticText* m_labUID;
		wxTextCtrl* m_UIDX;
		wxTextCtrl* m_UID;
		wxStaticText* m_labVersion;
		wxTextCtrl* m_Version;
		wxStaticBitmap* m_Pict;
		wxButton* m_Report;
		wxPanel* m_FeaturesPanel;
		wxListBox* m_FeatureList;
		wxStaticLine* m_staticline2;
		wxStaticText* m_labIID;
		wxTextCtrl* m_IID;
		wxStaticLine* m_staticline4;
		wxStaticBoxSizer* m_FeatureBox;
		wxStaticText* m_labFeature;
		wxSpinCtrl* m_Feature;
		wxStaticText* m_labFeatureValue;
		wxSpinCtrl* m_FeatureValue;
		wxButton* m_FeaturesGet;
		wxButton* m_FeatureSet;
		wxStaticBoxSizer* m_VendorCVBox;
		wxStaticText* m_labVendorCVName;
		wxTextCtrl* m_VendorCVName;
		wxStaticText* m_labVendorCVValue;
		wxTextCtrl* m_VendorCVValue;
		wxButton* m_VendorCVEnable;
		wxButton* m_VendorCVDisable;
		wxButton* m_VendorCVGet;
		wxButton* m_VendorCVSet;
		wxPanel* m_AccessoryPanel;
		wxStaticBoxSizer* m_AccessoryPortBox;
		wxStaticText* m_labAccessoryPort;
		wxSpinCtrl* m_AccessoryPort;
		wxButton* m_AccessoryOn;
		wxButton* m_AccessoryOff;
		wxStaticBoxSizer* m_AccessoryOptionsBox;
		wxStaticText* m_labAccessorySwitchTime;
		wxSpinCtrl* m_AccessorySwitchTime;
		wxCheckBox* m_AccessorySwitchTimeSeconds;
		wxButton* m_AccessoryReadOptions;
		wxButton* m_AccessoryWriteOptions;
		wxStaticBoxSizer* m_AccessoryMacroMapBox;
		wxStaticText* m_staticText28;
		wxSpinCtrl* m_AccessoryMacro1;
		wxStaticText* m_staticText29;
		wxSpinCtrl* m_AccessoryMacro2;
		wxStaticText* m_staticText281;
		wxSpinCtrl* m_AccessoryMacro3;
		wxStaticText* m_staticText2811;
		wxSpinCtrl* m_AccessoryMacro4;
		wxStaticText* m_staticText28111;
		wxSpinCtrl* m_AccessoryMacro5;
		wxStaticText* m_staticText281111;
		wxSpinCtrl* m_AccessoryMacro6;
		wxStaticText* m_staticText282;
		wxSpinCtrl* m_AccessoryMacro7;
		wxStaticText* m_staticText283;
		wxSpinCtrl* m_AccessoryMacro8;
		wxStaticText* m_staticText284;
		wxSpinCtrl* m_AccessoryMacro9;
		wxStaticText* m_staticText285;
		wxSpinCtrl* m_AccessoryMacro10;
		wxStaticText* m_staticText286;
		wxSpinCtrl* m_AccessoryMacro11;
		wxStaticText* m_staticText287;
		wxSpinCtrl* m_AccessoryMacro12;
		wxStaticText* m_staticText288;
		wxSpinCtrl* m_AccessoryMacro13;
		wxStaticText* m_staticText289;
		wxSpinCtrl* m_AccessoryMacro14;
		wxStaticText* m_staticText2810;
		wxSpinCtrl* m_AccessoryMacro15;
		wxStaticText* m_staticText2812;
		wxSpinCtrl* m_AccessoryMacro16;
		wxButton* m_AccessoryReadMacroMap;
		wxButton* m_AccessoryWriteMacroMap;
		wxPanel* m_ServoPanel;
		wxStaticText* m_labServoLeft;
		wxStaticText* m_labServoRight;
		wxStaticText* m_labServoSpeed;
		wxStaticText* m_labServoReserved;
		wxSlider* m_ServoLeft;
		wxSlider* m_ServoRight;
		wxSlider* m_ServoSpeed;
		wxSlider* m_ServoReserved;
		wxSpinCtrl* m_ConfigL;
		wxSpinCtrl* m_ConfigR;
		wxSpinCtrl* m_ConfigV;
		wxSpinCtrl* m_ConfigS;
		wxRadioBox* m_PortType;
		wxStaticBoxSizer* m_ServoTestBox;
		wxButton* m_ServoLeftTest;
		wxButton* m_ServoRightTest;
		wxStaticBoxSizer* m_PortBox;
		wxStaticText* m_labPortNumber;
		wxSpinCtrl* m_ServoPort;
		wxStaticBoxSizer* m_PortIOConfigBox;
		wxRadioBox* m_PortIOSelection;
		wxStaticText* m_labPortTimer;
		wxSpinCtrl* m_PortTimer;
		wxButton* m_ServoGet;
		wxButton* m_PortSet;
		wxPanel* m_MacroPanel;
		wxStaticText* m_labMacroList;
		wxListBox* m_MacroList;
		wxStaticText* m_labMacroSlowdown;
		wxSpinCtrl* m_MacroSlowdown;
		wxStaticText* m_labCycles;
		wxSpinCtrl* m_MacroCycles;
		wxStaticText* m_labMacroTime;
		wxSpinCtrl* m_MacroHours;
		wxStaticText* m_staticText23;
		wxSpinCtrl* m_MacroMinutes;
		wxStaticText* m_staticText26;
		wxSpinCtrl* m_MacroWDay;
		wxGrid* m_MacroLines;
		wxStaticBoxSizer* m_MacroStartBox;
		wxCheckBox* m_MacroStartDaily;
		wxCheckBox* m_MacroStartHourly;
		wxCheckBox* m_MacroStart30;
		wxCheckBox* m_MacroStart15;
		wxCheckBox* m_MacroStart1;
		wxStaticText* m_labMacroDelay;
		wxSpinCtrl* m_MacroDelay;
		wxStaticText* m_labMacroType;
		wxComboBox* m_MacroType;
		wxStaticText* m_labMacroPort;
		wxSpinCtrl* m_MacroPort;
		wxStaticText* m_labMacroValue;
		wxSpinCtrl* m_MacroValue;
		wxButton* m_MacroApply;
		wxButton* m_MacroReload;
		wxButton* m_MacroSave;
		wxButton* m_MacroExport;
		wxButton* m_MacroImport;
		wxButton* m_MacroSaveMacro;
		wxButton* m_MacroDeleteMacro;
		wxButton* m_MacroRestoreMacro;
		wxButton* m_MacroTest;
		wxPanel* m_UpdatePanel;
		wxStaticText* m_labUpdateFile;
		wxTextCtrl* m_UpdateFile;
		wxButton* m_OpenUpdateFile;
		wxStaticText* m_labUpdateFilePreview;
		wxTextCtrl* m_HEXFileText;
		wxGauge* m_UpdateProgress;
		wxButton* m_UpdateStart;
		wxStdDialogButtonSizer* m_stdButtons;
		wxButton* m_stdButtonsOK;
		wxButton* m_stdButtonsCancel;
		wxButton* m_stdButtonsHelp;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void onPageChanged( wxNotebookEvent& event ) { event.Skip(); }
		virtual void onBeginDrag( wxTreeEvent& event ) { event.Skip(); }
		virtual void onItemActivated( wxTreeEvent& event ) { event.Skip(); }
		virtual void onItemRightClick( wxTreeEvent& event ) { event.Skip(); }
		virtual void onTreeSelChanged( wxTreeEvent& event ) { event.Skip(); }
		virtual void onLeftLogo( wxMouseEvent& event ) { event.Skip(); }
		virtual void onProductName( wxMouseEvent& event ) { event.Skip(); }
		virtual void onUsernameSet( wxCommandEvent& event ) { event.Skip(); }
		virtual void onReport( wxCommandEvent& event ) { event.Skip(); }
		virtual void onFeatureSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void onFeaturesGet( wxCommandEvent& event ) { event.Skip(); }
		virtual void onFeatureSet( wxCommandEvent& event ) { event.Skip(); }
		virtual void onVendorCVEnable( wxCommandEvent& event ) { event.Skip(); }
		virtual void onVendorCVDisable( wxCommandEvent& event ) { event.Skip(); }
		virtual void onVendorCVGet( wxCommandEvent& event ) { event.Skip(); }
		virtual void onVendorCVSet( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAccessoryOnTest( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAccessoryOffTest( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAccessoryReadOptions( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAccessoryWriteOptions( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAccessoryReadMacroMap( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAccessoryWriteMacroMap( wxCommandEvent& event ) { event.Skip(); }
		virtual void onServoLeft( wxScrollEvent& event ) { event.Skip(); }
		virtual void onServoRight( wxScrollEvent& event ) { event.Skip(); }
		virtual void onServoSpeed( wxScrollEvent& event ) { event.Skip(); }
		virtual void onServoReserved( wxScrollEvent& event ) { event.Skip(); }
		virtual void onConfigL( wxSpinEvent& event ) { event.Skip(); }
		virtual void onConfigLtxt( wxCommandEvent& event ) { event.Skip(); }
		virtual void onConfigR( wxSpinEvent& event ) { event.Skip(); }
		virtual void onConfigRtxt( wxCommandEvent& event ) { event.Skip(); }
		virtual void onConfigV( wxSpinEvent& event ) { event.Skip(); }
		virtual void onConfigVtxt( wxCommandEvent& event ) { event.Skip(); }
		virtual void onConfigS( wxSpinEvent& event ) { event.Skip(); }
		virtual void onConfigStxt( wxCommandEvent& event ) { event.Skip(); }
		virtual void onPortType( wxCommandEvent& event ) { event.Skip(); }
		virtual void onServoLeftTest( wxCommandEvent& event ) { event.Skip(); }
		virtual void onServoRightTest( wxCommandEvent& event ) { event.Skip(); }
		virtual void onServoPort( wxSpinEvent& event ) { event.Skip(); }
		virtual void onServoGet( wxCommandEvent& event ) { event.Skip(); }
		virtual void onPortSet( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMacroList( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMacroLineSelected( wxGridEvent& event ) { event.Skip(); }
		virtual void onMacroEveryMinute( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMacroApply( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMacroReload( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMacroSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMacroExport( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMacroImport( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMacroSaveMacro( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMacroDeleteMacro( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMacroRestoreMacro( wxCommandEvent& event ) { event.Skip(); }
		virtual void onMacroTest( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSelectUpdateFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void onUpdateStart( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void onHelp( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		BidibIdentDlgGen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("BiDiB Notifier"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxCAPTION|wxCLOSE_BOX|wxFRAME_FLOAT_ON_PARENT|wxRESIZE_BORDER|wxTAB_TRAVERSAL );
		~BidibIdentDlgGen();
	
};

#endif //__bidibidendlggen__
