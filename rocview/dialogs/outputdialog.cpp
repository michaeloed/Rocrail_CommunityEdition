/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 


 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "outputdialog.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
#include "wx/imaglist.h"
////@end includes

#include "outputdialog.h"
#include "actionsctrldlg.h"

////@begin XPM images
////@end XPM images
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/OutputList.h"
#include "rocrail/wrapper/public/Plan.h"
#include "rocrail/wrapper/public/ModelCmd.h"
#include "rocrail/wrapper/public/Item.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Color.h"
#include "rocview/public/guiapp.h"

/*!
 * OutputDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( OutputDialog, wxDialog )

/*!
 * OutputDialog event table definition
 */

BEGIN_EVENT_TABLE( OutputDialog, wxDialog )

////@begin OutputDialog event table entries
    EVT_NOTEBOOK_PAGE_CHANGED( ID_NOTEBOOK_CO, OutputDialog::OnNotebookCoPageChanged )
    EVT_LIST_ITEM_SELECTED( ID_LISTCTRLINDEX_CO, OutputDialog::OnListctrlindexCoSelected )
    EVT_LIST_COL_CLICK( ID_LISTCTRLINDEX_CO, OutputDialog::OnListctrlindexCoColLeftClick )
    EVT_BUTTON( ID_BUTTON_CO_NEW, OutputDialog::OnButtonCoNewClick )
    EVT_BUTTON( ID_BUTTON_CO_DELETE, OutputDialog::OnButtonCoDeleteClick )
    EVT_BUTTON( ID_OUTPUT_DOC, OutputDialog::onDoc )
    EVT_BUTTON( ID_OUTPUT_ACTIONS, OutputDialog::OnOutputActionsClick )
    EVT_CHECKBOX( ID_OUTPUT_SWITCH, OutputDialog::OnOutputSwitchClick )
    EVT_CHECKBOX( ID_CO_ACCESSORY, OutputDialog::onAccessory )
    EVT_BUTTON( wxID_CANCEL, OutputDialog::OnCancelClick )
    EVT_BUTTON( wxID_OK, OutputDialog::OnOkClick )
    EVT_BUTTON( wxID_APPLY, OutputDialog::OnApplyClick )
    EVT_BUTTON( wxID_HELP, OutputDialog::OnHelpClick )
////@end OutputDialog event table entries
    EVT_MENU( ID_PANEL_CO_GENERAL, OutputDialog::OnSelectPage )

END_EVENT_TABLE()

/*!
 * OutputDialog constructors
 */

OutputDialog::OutputDialog( )
{
}

OutputDialog::OutputDialog( wxWindow* parent, iONode p_Props )
{
  m_TabAlign = wxGetApp().getTabAlign();
  Create(parent, -1, wxGetApp().getMsg("outputtable") );

  m_Props = p_Props;

  initLabels();

  m_IndexPanel->GetSizer()->Layout();
  m_GeneralPanel->GetSizer()->Layout();
  m_InterfacePanel->GetSizer()->Layout();
  m_Notebook->Fit();
  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);


  if( initIndex() ) {
    initValues();
    wxCommandEvent event( wxEVT_COMMAND_MENU_SELECTED, ID_PANEL_CO_GENERAL );
    wxPostEvent( this, event );
  }

}

static int __sortStr(obj* _a, obj* _b)
{
    const char* a = (const char*)*_a;
    const char* b = (const char*)*_b;
    return strcmp( a, b );
}

/* comparator for sorting by id: */
static int __sortID(obj* _a, obj* _b)
{
    iONode a = (iONode)*_a;
    iONode b = (iONode)*_b;
    const char* idA = wItem.getid( a );
    const char* idB = wItem.getid( b );
    return strcmp( idA, idB );
}



void OutputDialog::initLabels() {
  m_Notebook->SetPageText( 0, wxGetApp().getMsg( "index" ) );
  m_Notebook->SetPageText( 1, wxGetApp().getMsg( "general" ) );
  m_Notebook->SetPageText( 2, wxGetApp().getMsg( "interface" ) );
  m_Notebook->SetPageText( 3, wxGetApp().getMsg( "color" ) );
  m_Notebook->SetPageText( 4, wxGetApp().getMsg( "position" ) );

  // Index
  initList(m_List2, this);
  m_New->SetLabel( wxGetApp().getMsg( "new" ) );
  m_Delete->SetLabel( wxGetApp().getMsg( "delete" ) );
  m_Doc->SetLabel( wxGetApp().getMsg( "doc_report" ) );

  // General
  m_LabelID->SetLabel( wxGetApp().getMsg( "id" ) );
  m_LabelDescription->SetLabel( wxGetApp().getMsg( "description" ) );
  m_Show->SetLabel( wxGetApp().getMsg( "visible" ) );
  m_labSVG->SetLabel( wxGetApp().getMsg( "svg" ) );
  m_Actions->SetLabel( wxGetApp().getMsg( "actions" )+_T("...") );
  m_labRouteIDs->SetLabel( wxGetApp().getMsg( "routeids" ) );
  m_labBlockID->SetLabel( wxGetApp().getMsg( "blockid" ) );
  m_TriState->SetLabel( wxGetApp().getMsg( "tristate" ) );
  m_Type->SetLabel( wxGetApp().getMsg( "type" ) );
  m_Type->SetString( 0, wxGetApp().getMsg( "toggleswitch" ) );
  m_Type->SetString( 1, wxGetApp().getMsg( "pushbutton" ) );

  // Interface
  BaseDialog::addIIDs(m_iid);

  m_Labeliid->SetLabel( wxGetApp().getMsg( "iid" ) );
  m_Label_Bus->SetLabel( wxGetApp().getMsg( "bus" ) );
  m_labUIDName->SetLabel(wxGetApp().getMsg( "uidname" ));
  m_LabelAddress->SetLabel( wxGetApp().getMsg( "address" ) );
  m_LabelPort->SetLabel( wxGetApp().getMsg( "port" ) );
  m_labGate->SetLabel( wxGetApp().getMsg( "gate" ) );
  m_Gate->SetString( 0, wxGetApp().getMsg( "red" ) );
  m_Gate->SetString( 1, wxGetApp().getMsg( "green" ) );
  m_labGain->SetLabel( wxGetApp().getMsg( "parameter" ) );
  m_labValue->SetLabel( wxGetApp().getMsg( "value" ) );
  m_labDelay->SetLabel( wxGetApp().getMsg( "delay" ) );
  m_LabelProt->SetLabel( wxGetApp().getMsg( "protocol" ) );
  m_Prot->Clear();
  m_Prot->Append(_T("Default"));
  m_Prot->Append(_T("Motorola"));
  m_Prot->Append(_T("NMRA-DCC"));
  m_Prot->Append(_T("Dinamo MDD"));
  m_Prot->Append(_T("Dinamo OM32"));
  m_Prot->Append(_T("Dinamo DO"));
  m_Prot->Append(_T("Dinamo VO"));

  m_OptionsBox->SetLabel(wxGetApp().getMsg( "options"));

  m_Invert->SetLabel( wxGetApp().getMsg( "invert" ) );
  m_Blink->SetLabel( wxGetApp().getMsg( "blink" ) );
  m_ColorType->SetLabel( wxGetApp().getMsg( "color" ) );
  m_AsSwitch->SetLabel( wxGetApp().getMsg( "turnout" ) );
  m_Accessory->SetLabel( wxGetApp().getMsg( "accessory" ) );

  m_PortType->SetLabel( wxGetApp().getMsg( "type" ) );
  m_PortType->SetString( 0, wxGetApp().getMsg( "output" ) );
  m_PortType->SetString( 1, wxGetApp().getMsg( "lights" ) );
  m_PortType->SetString( 2, wxGetApp().getMsg( "servo" ) );
  m_PortType->SetString( 3, wxGetApp().getMsg( "sound" ) );
  m_PortType->SetString( 4, wxGetApp().getMsg( "motor" ) );
  m_PortType->SetString( 5, wxGetApp().getMsg( "analog" ) );
  m_PortType->SetString( 6, wxGetApp().getMsg( "macro" ) );
  m_PortType->SetString( 7, wxGetApp().getMsg( "backlight" ) );

  // Color
  m_ColorChannelBox->SetLabel(wxGetApp().getMsg( "channel"));
  m_labRedChannel->SetLabel(wxGetApp().getMsg( "red"));
  m_labGreenChannel->SetLabel(wxGetApp().getMsg( "green"));
  m_labBlueChannel->SetLabel(wxGetApp().getMsg( "blue"));
  m_labWhiteChannel->SetLabel(wxGetApp().getMsg( "white") + wxT(" 1"));
  m_labWhite2Channel->SetLabel(wxGetApp().getMsg( "white") + wxT(" 2"));
  m_labBrightnessChannel->SetLabel(wxGetApp().getMsg( "brightness"));
  m_ColorRGBBox->SetLabel(wxGetApp().getMsg( "rgb"));
  m_labRedColor->SetLabel(wxGetApp().getMsg( "red"));
  m_labGreenColor->SetLabel(wxGetApp().getMsg( "green"));
  m_labBlueColor->SetLabel(wxGetApp().getMsg( "blue"));
  m_labWhiteColor->SetLabel(wxGetApp().getMsg( "white") + wxT(" 1"));
  m_labWhite2Color->SetLabel(wxGetApp().getMsg( "white") + wxT(" 2"));
  m_labSaturationColor->SetLabel(wxGetApp().getMsg( "saturation"));

  // Location
  m_LabelX->SetLabel( wxGetApp().getMsg( "x" ) );
  m_LabelY->SetLabel( wxGetApp().getMsg( "y" ) );
  m_LabelZ->SetLabel( wxGetApp().getMsg( "z" ) );
  m_ori->SetLabel( wxGetApp().getMsg( "orientation" ) );
  m_ori->SetString( 0, wxGetApp().getMsg( "north" ) );
  m_ori->SetString( 1, wxGetApp().getMsg( "east" ) );
  m_ori->SetString( 2, wxGetApp().getMsg( "south" ) );
  m_ori->SetString( 3, wxGetApp().getMsg( "west" ) );

  // Buttons
  m_OK->SetLabel( wxGetApp().getMsg( "ok" ) );
  m_Cancel->SetLabel( wxGetApp().getMsg( "cancel" ) );
  m_Apply->SetLabel( wxGetApp().getMsg( "apply" ) );
  m_Help->SetLabel( wxGetApp().getMsg( "help" ) );

  m_BlockID->Append( _T("") );
  iOList list = ListOp.inst();
  iONode model = wxGetApp().getModel();

  if( model != NULL ) {
    iONode bklist = wPlan.getbklist( model );
    if( bklist != NULL ) {
      int cnt = NodeOp.getChildCnt( bklist );
      for( int i = 0; i < cnt; i++ ) {
        iONode bk = NodeOp.getChild( bklist, i );
        ListOp.add(list, (obj)wBlock.getid( bk ));
      }
    }
    iONode fblist = wPlan.getfblist( model );
    if( fblist != NULL ) {
      int cnt = NodeOp.getChildCnt( fblist );
      for( int i = 0; i < cnt; i++ ) {
        iONode fb = NodeOp.getChild( fblist, i );
        ListOp.add(list, (obj)wFeedback.getid( fb ));
      }
    }
    iONode colist = wPlan.getcolist( model );
    if( colist != NULL ) {
      int cnt = NodeOp.getChildCnt( colist );
      for( int i = 0; i < cnt; i++ ) {
        iONode co = NodeOp.getChild( colist, i );
        ListOp.add(list, (obj)wOutput.getid( co ));
      }
    }

    ListOp.sort(list, &__sortStr);
    int cnt = ListOp.size( list );
    for( int i = 0; i < cnt; i++ ) {
      const char* id = (const char*)ListOp.get( list, i );
      m_BlockID->Append( wxString(id,wxConvUTF8) );
    }


  }


}


void OutputDialog::OnSelectPage(wxCommandEvent& event) {
  m_Notebook->SetSelection( 1 );
}


bool OutputDialog::initIndex() {
  TraceOp.trc( "app", TRCLEVEL_INFO, __LINE__, 9999, "InitIndex" );
  iONode model = wxGetApp().getModel();
  if( model != NULL ) {
    iONode colist = wPlan.getcolist( model );
    if( colist != NULL ) {
      fillIndex(colist);

      if( m_Props != NULL ) {
        setIDSelection(wItem.getid( m_Props ));
        return true;
      }
      else {
        m_Props = setSelection(0);
      }
    }
  }
  return false;
}

void OutputDialog::initValues() {
  char* title = StrOp.fmt( "%s %s", (const char*)wxGetApp().getMsg("output").mb_str(wxConvUTF8), wOutput.getid( m_Props ) );
  SetTitle( wxString(title,wxConvUTF8) );
  StrOp.free( title );

  // General
  m_ID->SetValue( wxString(wOutput.getid( m_Props ),wxConvUTF8) );
  m_Description->SetValue( wxString(wOutput.getdesc( m_Props ),wxConvUTF8) );
  m_Show->SetValue( wOutput.isshow( m_Props ) ? true:false);
  m_SVG->SetValue( wOutput.getsvgtype( m_Props ) );
  m_BlockID->SetStringSelection( wOutput.getblockid( m_Props ) == NULL ?
                                _T(""):wxString(wOutput.getblockid( m_Props ),wxConvUTF8)  );
  m_RouteIDs->SetValue( wxString(wItem.getrouteids( m_Props ),wxConvUTF8) );
  m_TriState->SetValue( wOutput.istristate( m_Props ) ? true:false);
  m_Type->SetSelection( wOutput.istoggleswitch(m_Props) ? 0:1);

  // Interface
  m_iid->SetValue( wxString(wOutput.getiid( m_Props ),wxConvUTF8) );
  m_UIDName->SetValue( wxString(wItem.getuidname( m_Props ),wxConvUTF8) );
  char* str = StrOp.fmt( "%d", wOutput.getaddr(m_Props) );
  m_Address->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wOutput.getbus(m_Props) );
  m_Bus->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );
  str = StrOp.fmt( "%d", wOutput.getport(m_Props) );
  m_Port->SetValue( wxString(str,wxConvUTF8) ); StrOp.free( str );
  m_Gate->SetSelection( wOutput.getgate(m_Props) );
  m_Gain->SetValue( wOutput.getparam(m_Props) );
  m_Value->SetValue( wOutput.getvalue(m_Props) );
  m_Delay->SetValue( wOutput.getdelay(m_Props) );

  if( StrOp.equals( wOutput.prot_M, wOutput.getprot( m_Props ) ) )
    m_Prot->SetSelection( 1 );
  else if( StrOp.equals( wOutput.prot_N, wOutput.getprot( m_Props ) ) )
    m_Prot->SetSelection( 2 );
  else if( StrOp.equals( wOutput.prot_MDD, wOutput.getprot( m_Props ) ) )
    m_Prot->SetSelection( 3 );
  else if( StrOp.equals( wOutput.prot_OM32, wOutput.getprot( m_Props ) ) )
    m_Prot->SetSelection( 4 );
  else if( StrOp.equals( wOutput.prot_DO, wOutput.getprot( m_Props ) ) )
    m_Prot->SetSelection( 5 );
  else if( StrOp.equals( wOutput.prot_VO, wOutput.getprot( m_Props ) ) )
    m_Prot->SetSelection( 6 );
  else
    m_Prot->SetSelection( 0 );

  m_Invert->SetValue( wOutput.isinv( m_Props )?true:false );
  m_Blink->SetValue( wOutput.isblink( m_Props )?true:false );
  m_ColorType->SetValue( wOutput.iscolortype( m_Props )?true:false );
  m_AsSwitch->SetValue( wOutput.isasswitch( m_Props )?true:false );
  m_Accessory->SetValue( wOutput.isaccessory( m_Props )?true:false );
  m_Gate->Enable(!m_AsSwitch->GetValue());
  m_PortType->Enable(!m_Accessory->IsChecked());

  if(wOutput.isaccessory(m_Props))
    wOutput.setporttype(m_Props, 0);

  m_PortType->SetSelection(wOutput.getporttype(m_Props));

  // Color
  m_RedChannel->SetValue(wOutput.getredChannel(m_Props));
  m_GreenChannel->SetValue(wOutput.getgreenChannel(m_Props));
  m_BlueChannel->SetValue(wOutput.getblueChannel(m_Props));
  m_WhiteChannel->SetValue(wOutput.getwhiteChannel(m_Props));
  m_White2Channel->SetValue(wOutput.getwhite2Channel(m_Props));
  m_BrightnessChannel->SetValue(wOutput.getbrightnessChannel(m_Props));
  iONode color = wOutput.getcolor(m_Props);
  if( color == NULL ) {
    color = NodeOp.inst(wColor.name(), m_Props, ELEMENT_NODE);
    NodeOp.addChild( m_Props, color);
  }
  m_RedColor->SetValue(wColor.getred(color));
  m_GreenColor->SetValue(wColor.getgreen(color));
  m_BlueColor->SetValue(wColor.getblue(color));
  m_WhiteColor->SetValue(wColor.getwhite(color));
  m_White2Color->SetValue(wColor.getwhite2(color));
  m_SaturationColor->SetValue(wColor.getsaturation(color));

  // Location
  char* val = StrOp.fmt( "%d", wOutput.getx( m_Props ) );
  m_x->SetValue( wxString(val,wxConvUTF8) ); StrOp.free( val );
  val = StrOp.fmt( "%d", wOutput.gety( m_Props ) );
  m_y->SetValue( wxString(val,wxConvUTF8) ); StrOp.free( val );
  val = StrOp.fmt( "%d", wOutput.getz( m_Props ) );
  m_z->SetValue( wxString(val,wxConvUTF8) ); StrOp.free( val );
  if( StrOp.equals( wItem.north, wOutput.getori( m_Props ) ) )
    m_ori->SetSelection( 0 );
  else if( StrOp.equals( wItem.east, wOutput.getori( m_Props ) ) )
    m_ori->SetSelection( 1 );
  else if( StrOp.equals( wItem.south, wOutput.getori( m_Props ) ) )
    m_ori->SetSelection( 2 );
  else
    m_ori->SetSelection( 3 );


}


bool OutputDialog::evaluate() {
  if( m_Props == NULL )
    return false;

  iONode model  = wxGetApp().getModel();
  iONode colist = wPlan.getcolist( model );

  if( existID( this, colist, m_Props, m_ID->GetValue() ) ) {
    m_ID->SetValue( wxString(wItem.getid( m_Props ),wxConvUTF8) );
    return false;
  }
  // General
  wItem.setprev_id( m_Props, wItem.getid(m_Props) );
  wOutput.setid( m_Props, m_ID->GetValue().mb_str(wxConvUTF8) );
  wOutput.setdesc( m_Props, m_Description->GetValue().mb_str(wxConvUTF8) );
  wOutput.setshow( m_Props , m_Show->GetValue() ? True:False);
  wOutput.setsvgtype( m_Props , m_SVG->GetValue());
  wOutput.setblockid( m_Props, m_BlockID->GetStringSelection().mb_str(wxConvUTF8) );
  wItem.setrouteids( m_Props, m_RouteIDs->GetValue().mb_str(wxConvUTF8) );
  wOutput.settristate( m_Props , m_TriState->GetValue() ? True:False);
  wOutput.settoggleswitch( m_Props , m_Type->GetSelection() == 0 ? True:False);

  // Interface
  wOutput.setiid( m_Props, m_iid->GetValue().mb_str(wxConvUTF8) );
  wOutput.setbus( m_Props, atoi( m_Bus->GetValue().mb_str(wxConvUTF8) ) );
  wItem.setuidname( m_Props, m_UIDName->GetValue().mb_str(wxConvUTF8) );
  wOutput.setaddr( m_Props, atoi( m_Address->GetValue().mb_str(wxConvUTF8) ) );
  wOutput.setport( m_Props, atoi( m_Port->GetValue().mb_str(wxConvUTF8) ) );
  wOutput.setgate( m_Props, m_Gate->GetSelection() );
  wOutput.setparam( m_Props, m_Gain->GetValue() );
  wOutput.setvalue( m_Props, m_Value->GetValue() );
  wOutput.setdelay( m_Props, m_Delay->GetValue() );

  if( m_Prot->GetSelection() == 1 )
    wOutput.setprot( m_Props, wOutput.prot_M );
  else if( m_Prot->GetSelection() == 2 )
    wOutput.setprot( m_Props, wOutput.prot_N );
  else if( m_Prot->GetSelection() == 3 )
    wOutput.setprot( m_Props, wOutput.prot_MDD );
  else if( m_Prot->GetSelection() == 4 )
    wOutput.setprot( m_Props, wOutput.prot_OM32 );
  else if( m_Prot->GetSelection() == 5 )
    wOutput.setprot( m_Props, wOutput.prot_DO );
  else if( m_Prot->GetSelection() == 6 )
    wOutput.setprot( m_Props, wOutput.prot_VO );
  else
    wOutput.setprot( m_Props, wOutput.prot_DEF );

  wOutput.setinv( m_Props, m_Invert->GetValue()?True:False);
  wOutput.setblink( m_Props, m_Blink->IsChecked()?True:False);
  wOutput.setcolortype( m_Props, m_ColorType->IsChecked()?True:False);
  wOutput.setasswitch( m_Props, m_AsSwitch->GetValue()?True:False);
  wOutput.setaccessory( m_Props, m_Accessory->GetValue()?True:False);

  wOutput.setporttype(m_Props, m_PortType->GetSelection());

  // Color
  wOutput.setredChannel(m_Props, m_RedChannel->GetValue());
  wOutput.setgreenChannel(m_Props, m_GreenChannel->GetValue());
  wOutput.setblueChannel(m_Props, m_BlueChannel->GetValue());
  wOutput.setwhiteChannel(m_Props, m_WhiteChannel->GetValue());
  wOutput.setwhite2Channel(m_Props, m_White2Channel->GetValue());
  wOutput.setbrightnessChannel(m_Props, m_BrightnessChannel->GetValue());
  iONode color = wOutput.getcolor(m_Props);
  wColor.setred(color, m_RedColor->GetValue());
  wColor.setgreen(color, m_GreenColor->GetValue());
  wColor.setblue(color, m_BlueColor->GetValue());
  wColor.setwhite(color, m_WhiteColor->GetValue());
  wColor.setwhite2(color, m_White2Color->GetValue());
  wColor.setsaturation(color, m_SaturationColor->GetValue());

  // Location
  wOutput.setx( m_Props, atoi( m_x->GetValue().mb_str(wxConvUTF8) ) );
  wOutput.sety( m_Props, atoi( m_y->GetValue().mb_str(wxConvUTF8) ) );
  wOutput.setz( m_Props, atoi( m_z->GetValue().mb_str(wxConvUTF8) ) );
  int ori = m_ori->GetSelection();
  if( ori == 0 )
    wOutput.setori( m_Props, wItem.north );
  else if( ori == 1 )
    wOutput.setori( m_Props, wItem.east );
  else if( ori == 2 )
    wOutput.setori( m_Props, wItem.south );
  else if( ori == 3 )
    wOutput.setori( m_Props, wItem.west );

  return true;

}




/*!
 * OutputDialog creator
 */

bool OutputDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin OutputDialog member initialisation
    m_Notebook = NULL;
    m_IndexPanel = NULL;
    m_List2 = NULL;
    m_New = NULL;
    m_Delete = NULL;
    m_Doc = NULL;
    m_GeneralPanel = NULL;
    m_LabelID = NULL;
    m_ID = NULL;
    m_LabelDescription = NULL;
    m_Description = NULL;
    m_labSVG = NULL;
    m_SVG = NULL;
    m_labBlockID = NULL;
    m_BlockID = NULL;
    m_labRouteIDs = NULL;
    m_RouteIDs = NULL;
    m_Show = NULL;
    m_TriState = NULL;
    m_Type = NULL;
    m_Actions = NULL;
    m_InterfacePanel = NULL;
    m_Labeliid = NULL;
    m_iid = NULL;
    m_Label_Bus = NULL;
    m_Bus = NULL;
    m_labUIDName = NULL;
    m_UIDName = NULL;
    m_LabelProt = NULL;
    m_Prot = NULL;
    m_LabelAddress = NULL;
    m_Address = NULL;
    m_LabelPort = NULL;
    m_Port = NULL;
    m_labGate = NULL;
    m_Gate = NULL;
    m_labGain = NULL;
    m_Gain = NULL;
    m_labValue = NULL;
    m_Value = NULL;
    m_labDelay = NULL;
    m_Delay = NULL;
    m_OptionsBox = NULL;
    m_AsSwitch = NULL;
    m_Invert = NULL;
    m_Blink = NULL;
    m_ColorType = NULL;
    m_Accessory = NULL;
    m_PortType = NULL;
    m_ColorChannelBox = NULL;
    m_labRedChannel = NULL;
    m_RedChannel = NULL;
    m_labGreenChannel = NULL;
    m_GreenChannel = NULL;
    m_labBlueChannel = NULL;
    m_BlueChannel = NULL;
    m_labWhiteChannel = NULL;
    m_WhiteChannel = NULL;
    m_labWhite2Channel = NULL;
    m_White2Channel = NULL;
    m_labBrightnessChannel = NULL;
    m_BrightnessChannel = NULL;
    m_ColorRGBBox = NULL;
    m_labRedColor = NULL;
    m_RedColor = NULL;
    m_labGreenColor = NULL;
    m_GreenColor = NULL;
    m_labBlueColor = NULL;
    m_BlueColor = NULL;
    m_labWhiteColor = NULL;
    m_WhiteColor = NULL;
    m_labWhite2Color = NULL;
    m_White2Color = NULL;
    m_labSaturationColor = NULL;
    m_SaturationColor = NULL;
    m_LocationPanel = NULL;
    m_LabelX = NULL;
    m_x = NULL;
    m_LabelY = NULL;
    m_y = NULL;
    m_LabelZ = NULL;
    m_z = NULL;
    m_ori = NULL;
    m_Cancel = NULL;
    m_OK = NULL;
    m_Apply = NULL;
    m_Help = NULL;
////@end OutputDialog member initialisation

////@begin OutputDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end OutputDialog creation
    return true;
}

/*!
 * Control creation for OutputDialog
 */

void OutputDialog::CreateControls()
{
////@begin OutputDialog content construction
    OutputDialog* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    m_Notebook = new wxNotebook( itemDialog1, ID_NOTEBOOK_CO, wxDefaultPosition, wxDefaultSize, m_TabAlign );

    m_IndexPanel = new wxPanel( m_Notebook, ID_PANEL_CO_INDEX, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxVERTICAL);
    m_IndexPanel->SetSizer(itemBoxSizer5);

    m_List2 = new wxListCtrl( m_IndexPanel, ID_LISTCTRLINDEX_CO, wxDefaultPosition, wxSize(400, 100), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES );
    itemBoxSizer5->Add(m_List2, 1, wxGROW|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer7 = new wxFlexGridSizer(0, 3, 0, 0);
    itemBoxSizer5->Add(itemFlexGridSizer7, 0, wxGROW|wxALL, 5);
    m_New = new wxButton( m_IndexPanel, ID_BUTTON_CO_NEW, _("New"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_New, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Delete = new wxButton( m_IndexPanel, ID_BUTTON_CO_DELETE, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_Delete, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Doc = new wxButton( m_IndexPanel, ID_OUTPUT_DOC, _("Doc"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer7->Add(m_Doc, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Notebook->AddPage(m_IndexPanel, _("Index"));

    m_GeneralPanel = new wxPanel( m_Notebook, ID_PANEL_CO_GENERAL, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer12 = new wxBoxSizer(wxVERTICAL);
    m_GeneralPanel->SetSizer(itemBoxSizer12);

    wxFlexGridSizer* itemFlexGridSizer13 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer12->Add(itemFlexGridSizer13, 0, wxGROW|wxALL, 5);
    m_LabelID = new wxStaticText( m_GeneralPanel, wxID_STATIC_CO_ID, _("id"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer13->Add(m_LabelID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ID = new wxTextCtrl( m_GeneralPanel, ID_TEXTCTRL_CO_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer13->Add(m_ID, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelDescription = new wxStaticText( m_GeneralPanel, wxID_STATIC_CO_DESC, _("desrciption"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer13->Add(m_LabelDescription, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Description = new wxTextCtrl( m_GeneralPanel, ID_TEXTCTRL_CO_DESC, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer13->Add(m_Description, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labSVG = new wxStaticText( m_GeneralPanel, wxID_ANY, _("SVG"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer13->Add(m_labSVG, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SVG = new wxSpinCtrl( m_GeneralPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(70, -1), wxSP_ARROW_KEYS, 0, 99, 0 );
    itemFlexGridSizer13->Add(m_SVG, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labBlockID = new wxStaticText( m_GeneralPanel, wxID_ANY, _("Block ID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer13->Add(m_labBlockID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_BlockIDStrings;
    m_BlockID = new wxComboBox( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_BlockIDStrings, wxCB_DROPDOWN );
    itemFlexGridSizer13->Add(m_BlockID, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labRouteIDs = new wxStaticText( m_GeneralPanel, wxID_ANY, _("Route ID's"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer13->Add(m_labRouteIDs, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_RouteIDs = new wxTextCtrl( m_GeneralPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer13->Add(m_RouteIDs, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer13->AddGrowableCol(1);

    m_Show = new wxCheckBox( m_GeneralPanel, ID_CHECKBOX_CO_SHOW, _("visible"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    m_Show->SetValue(false);
    itemBoxSizer12->Add(m_Show, 0, wxALIGN_LEFT|wxALL, 5);

    m_TriState = new wxCheckBox( m_GeneralPanel, wxID_ANY, _("Tri-State"), wxDefaultPosition, wxDefaultSize, 0 );
    m_TriState->SetValue(false);
    itemBoxSizer12->Add(m_TriState, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxArrayString m_TypeStrings;
    m_TypeStrings.Add(_("&Toggle switch"));
    m_TypeStrings.Add(_("&Push button"));
    m_Type = new wxRadioBox( m_GeneralPanel, wxID_ANY, _("Type"), wxDefaultPosition, wxDefaultSize, m_TypeStrings, 1, wxRA_SPECIFY_ROWS );
    m_Type->SetSelection(0);
    itemBoxSizer12->Add(m_Type, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_Actions = new wxButton( m_GeneralPanel, ID_OUTPUT_ACTIONS, _("Actions..."), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer12->Add(m_Actions, 0, wxALIGN_LEFT|wxALL, 5);

    m_Notebook->AddPage(m_GeneralPanel, _("General"));

    m_InterfacePanel = new wxPanel( m_Notebook, ID_PANEL_CO_INTERFACE, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer29 = new wxBoxSizer(wxVERTICAL);
    m_InterfacePanel->SetSizer(itemBoxSizer29);

    wxFlexGridSizer* itemFlexGridSizer30 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer29->Add(itemFlexGridSizer30, 0, wxGROW|wxALL, 5);
    m_Labeliid = new wxStaticText( m_InterfacePanel, wxID_STATIC_CO_IID, _("iid"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer30->Add(m_Labeliid, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_iidStrings;
    m_iid = new wxComboBox( m_InterfacePanel, ID_TEXTCTRL_CO_IID, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_iidStrings, wxCB_DROPDOWN );
    itemFlexGridSizer30->Add(m_iid, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Label_Bus = new wxStaticText( m_InterfacePanel, wxID_STATIC_CO_BUS, _("Bus:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer30->Add(m_Label_Bus, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxFlexGridSizer* itemFlexGridSizer34 = new wxFlexGridSizer(0, 3, 0, 0);
    itemFlexGridSizer30->Add(itemFlexGridSizer34, 0, wxGROW|wxALIGN_CENTER_VERTICAL, 5);
    m_Bus = new wxTextCtrl( m_InterfacePanel, ID_TEXTCTRL_CO_BUS, _("0"), wxDefaultPosition, wxSize(120, -1), wxTE_CENTRE );
    itemFlexGridSizer34->Add(m_Bus, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_labUIDName = new wxStaticText( m_InterfacePanel, wxID_ANY, _("UID-Name"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer34->Add(m_labUIDName, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_UIDName = new wxTextCtrl( m_InterfacePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_UIDName->SetMaxLength(60);
    itemFlexGridSizer34->Add(m_UIDName, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    itemFlexGridSizer34->AddGrowableCol(2);

    m_LabelProt = new wxStaticText( m_InterfacePanel, wxID_STATIC_CO_PROT, _("Protocol"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer30->Add(m_LabelProt, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    wxArrayString m_ProtStrings;
    m_ProtStrings.Add(_("Motorola"));
    m_ProtStrings.Add(_("NMRA-DCC"));
    m_Prot = new wxChoice( m_InterfacePanel, ID_CHOICE_CO_PROT, wxDefaultPosition, wxDefaultSize, m_ProtStrings, 0 );
    m_Prot->SetStringSelection(_("Motorola"));
    itemFlexGridSizer30->Add(m_Prot, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_LabelAddress = new wxStaticText( m_InterfacePanel, wxID_STATIC_CO_ADDRESS, _("address"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer30->Add(m_LabelAddress, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_Address = new wxTextCtrl( m_InterfacePanel, ID_TEXTCTRL_CO_ADDRESS, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer30->Add(m_Address, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_LabelPort = new wxStaticText( m_InterfacePanel, wxID_STATIC_CO_PORT, _("port"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer30->Add(m_LabelPort, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Port = new wxTextCtrl( m_InterfacePanel, ID_TEXTCTRL_CO_PORT, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer30->Add(m_Port, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labGate = new wxStaticText( m_InterfacePanel, wxID_STATIC_CO_GATE, _("gate"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer30->Add(m_labGate, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_GateStrings;
    m_GateStrings.Add(_("&Red"));
    m_GateStrings.Add(_("&Green"));
    m_Gate = new wxRadioBox( m_InterfacePanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_GateStrings, 1, wxRA_SPECIFY_ROWS );
    m_Gate->SetSelection(0);
    itemFlexGridSizer30->Add(m_Gate, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labGain = new wxStaticText( m_InterfacePanel, wxID_ANY, _("gain"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer30->Add(m_labGain, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_Gain = new wxSpinCtrl( m_InterfacePanel, wxID_ANY, wxT("10"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 0, 65535, 10 );
    itemFlexGridSizer30->Add(m_Gain, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_labValue = new wxStaticText( m_InterfacePanel, wxID_ANY, _("value"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer30->Add(m_labValue, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_Value = new wxSpinCtrl( m_InterfacePanel, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 0, 65535, 1 );
    itemFlexGridSizer30->Add(m_Value, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_labDelay = new wxStaticText( m_InterfacePanel, wxID_ANY, _("Delay"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer30->Add(m_labDelay, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    m_Delay = new wxSpinCtrl( m_InterfacePanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(100, -1), wxSP_ARROW_KEYS, 0, 10000, 0 );
    itemFlexGridSizer30->Add(m_Delay, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5);

    itemFlexGridSizer30->AddGrowableCol(1);

    m_OptionsBox = new wxStaticBox(m_InterfacePanel, wxID_ANY, _("Options"));
    wxStaticBoxSizer* itemStaticBoxSizer52 = new wxStaticBoxSizer(m_OptionsBox, wxHORIZONTAL);
    itemBoxSizer29->Add(itemStaticBoxSizer52, 0, wxGROW|wxALL, 5);
    m_AsSwitch = new wxCheckBox( m_InterfacePanel, ID_OUTPUT_SWITCH, _("Switch"), wxDefaultPosition, wxDefaultSize, 0 );
    m_AsSwitch->SetValue(false);
    itemStaticBoxSizer52->Add(m_AsSwitch, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Invert = new wxCheckBox( m_InterfacePanel, wxID_ANY, _("Invert"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Invert->SetValue(false);
    itemStaticBoxSizer52->Add(m_Invert, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Blink = new wxCheckBox( m_InterfacePanel, wxID_ANY, _("Blink"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Blink->SetValue(false);
    itemStaticBoxSizer52->Add(m_Blink, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ColorType = new wxCheckBox( m_InterfacePanel, wxID_ANY, _("Color"), wxDefaultPosition, wxDefaultSize, 0 );
    m_ColorType->SetValue(false);
    itemStaticBoxSizer52->Add(m_ColorType, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Accessory = new wxCheckBox( m_InterfacePanel, ID_CO_ACCESSORY, _("Accessory"), wxDefaultPosition, wxDefaultSize, 0 );
    m_Accessory->SetValue(false);
    itemBoxSizer29->Add(m_Accessory, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    wxArrayString m_PortTypeStrings;
    m_PortTypeStrings.Add(_("&Standard"));
    m_PortTypeStrings.Add(_("&Light"));
    m_PortTypeStrings.Add(_("&Servo"));
    m_PortTypeStrings.Add(_("&Sound"));
    m_PortTypeStrings.Add(_("&Motor"));
    m_PortTypeStrings.Add(_("&Analog"));
    m_PortTypeStrings.Add(_("&Macro"));
    m_PortTypeStrings.Add(_("&Backlight"));
    m_PortType = new wxRadioBox( m_InterfacePanel, ID_CO_PORT_TYPE, _("Type"), wxDefaultPosition, wxDefaultSize, m_PortTypeStrings, 2, wxRA_SPECIFY_ROWS );
    m_PortType->SetSelection(0);
    itemBoxSizer29->Add(m_PortType, 0, wxALIGN_LEFT|wxALL, 5);

    m_Notebook->AddPage(m_InterfacePanel, _("Interface"));

    wxPanel* itemPanel59 = new wxPanel( m_Notebook, ID_PANEL_CO_COLOR, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer60 = new wxBoxSizer(wxVERTICAL);
    itemPanel59->SetSizer(itemBoxSizer60);

    m_ColorChannelBox = new wxStaticBox(itemPanel59, ID_CO_COLOR_CHANNEL_BOX, _("Channel"));
    wxStaticBoxSizer* itemStaticBoxSizer61 = new wxStaticBoxSizer(m_ColorChannelBox, wxVERTICAL);
    itemBoxSizer60->Add(itemStaticBoxSizer61, 0, wxALIGN_LEFT|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer62 = new wxFlexGridSizer(0, 2, 0, 0);
    itemStaticBoxSizer61->Add(itemFlexGridSizer62, 0, wxALIGN_LEFT, 5);
    m_labRedChannel = new wxStaticText( itemPanel59, wxID_ANY, _("Red"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer62->Add(m_labRedChannel, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_RedChannel = new wxSpinCtrl( itemPanel59, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(120, -1), wxSP_ARROW_KEYS, 0, 10000, 0 );
    itemFlexGridSizer62->Add(m_RedChannel, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labGreenChannel = new wxStaticText( itemPanel59, wxID_ANY, _("Green"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer62->Add(m_labGreenChannel, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_GreenChannel = new wxSpinCtrl( itemPanel59, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(120, -1), wxSP_ARROW_KEYS, 0, 10000, 0 );
    itemFlexGridSizer62->Add(m_GreenChannel, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labBlueChannel = new wxStaticText( itemPanel59, wxID_ANY, _("Blue"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer62->Add(m_labBlueChannel, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_BlueChannel = new wxSpinCtrl( itemPanel59, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(120, -1), wxSP_ARROW_KEYS, 0, 10000, 0 );
    itemFlexGridSizer62->Add(m_BlueChannel, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labWhiteChannel = new wxStaticText( itemPanel59, wxID_ANY, _("White 1"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer62->Add(m_labWhiteChannel, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_WhiteChannel = new wxSpinCtrl( itemPanel59, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(120, -1), wxSP_ARROW_KEYS, 0, 10000, 0 );
    itemFlexGridSizer62->Add(m_WhiteChannel, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labWhite2Channel = new wxStaticText( itemPanel59, wxID_ANY, _("White 2"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer62->Add(m_labWhite2Channel, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_White2Channel = new wxSpinCtrl( itemPanel59, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(120, -1), wxSP_ARROW_KEYS, 0, 10000, 0 );
    itemFlexGridSizer62->Add(m_White2Channel, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labBrightnessChannel = new wxStaticText( itemPanel59, wxID_ANY, _("Brightness"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer62->Add(m_labBrightnessChannel, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_BrightnessChannel = new wxSpinCtrl( itemPanel59, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(120, -1), wxSP_ARROW_KEYS, 0, 10000, 0 );
    itemFlexGridSizer62->Add(m_BrightnessChannel, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    itemFlexGridSizer62->AddGrowableCol(1);

    m_ColorRGBBox = new wxStaticBox(itemPanel59, ID_CO_COLOR_RGB_BOX, _("RGB"));
    wxStaticBoxSizer* itemStaticBoxSizer75 = new wxStaticBoxSizer(m_ColorRGBBox, wxVERTICAL);
    itemBoxSizer60->Add(itemStaticBoxSizer75, 0, wxALIGN_LEFT|wxALL, 5);
    wxFlexGridSizer* itemFlexGridSizer76 = new wxFlexGridSizer(0, 2, 0, 0);
    itemStaticBoxSizer75->Add(itemFlexGridSizer76, 0, wxALIGN_LEFT, 5);
    m_labRedColor = new wxStaticText( itemPanel59, wxID_ANY, _("Red"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer76->Add(m_labRedColor, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_RedColor = new wxSpinCtrl( itemPanel59, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 255, 0 );
    itemFlexGridSizer76->Add(m_RedColor, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labGreenColor = new wxStaticText( itemPanel59, wxID_ANY, _("Green"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer76->Add(m_labGreenColor, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_GreenColor = new wxSpinCtrl( itemPanel59, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 255, 0 );
    itemFlexGridSizer76->Add(m_GreenColor, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labBlueColor = new wxStaticText( itemPanel59, wxID_ANY, _("Blue"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer76->Add(m_labBlueColor, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_BlueColor = new wxSpinCtrl( itemPanel59, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 255, 0 );
    itemFlexGridSizer76->Add(m_BlueColor, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labWhiteColor = new wxStaticText( itemPanel59, wxID_ANY, _("White 1"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer76->Add(m_labWhiteColor, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_WhiteColor = new wxSpinCtrl( itemPanel59, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 255, 0 );
    itemFlexGridSizer76->Add(m_WhiteColor, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labWhite2Color = new wxStaticText( itemPanel59, wxID_ANY, _("White 2"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer76->Add(m_labWhite2Color, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_White2Color = new wxSpinCtrl( itemPanel59, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 255, 0 );
    itemFlexGridSizer76->Add(m_White2Color, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_labSaturationColor = new wxStaticText( itemPanel59, wxID_ANY, _("Saturation"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer76->Add(m_labSaturationColor, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_SaturationColor = new wxSpinCtrl( itemPanel59, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 254, 0 );
    itemFlexGridSizer76->Add(m_SaturationColor, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    itemFlexGridSizer76->AddGrowableCol(1);

    m_Notebook->AddPage(itemPanel59, _("Color"));

    m_LocationPanel = new wxPanel( m_Notebook, ID_PANEL_CO_LOCATION, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer90 = new wxBoxSizer(wxHORIZONTAL);
    m_LocationPanel->SetSizer(itemBoxSizer90);

    wxFlexGridSizer* itemFlexGridSizer91 = new wxFlexGridSizer(0, 2, 0, 0);
    itemBoxSizer90->Add(itemFlexGridSizer91, 0, wxALIGN_TOP|wxALL, 5);
    m_LabelX = new wxStaticText( m_LocationPanel, wxID_STATIC_CO_X, _("x"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer91->Add(m_LabelX, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_x = new wxTextCtrl( m_LocationPanel, ID_TEXTCTRL_CO_X, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer91->Add(m_x, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelY = new wxStaticText( m_LocationPanel, wxID_STATIC_CO_Y, _("y"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer91->Add(m_LabelY, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_y = new wxTextCtrl( m_LocationPanel, ID_TEXTCTRL_CO_Y, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer91->Add(m_y, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_LabelZ = new wxStaticText( m_LocationPanel, wxID_STATIC_CO_Z, _("z"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer91->Add(m_LabelZ, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_z = new wxTextCtrl( m_LocationPanel, ID_TEXTCTRL_CO_Z, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    itemFlexGridSizer91->Add(m_z, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_oriStrings;
    m_oriStrings.Add(_("&north"));
    m_oriStrings.Add(_("&east"));
    m_oriStrings.Add(_("&south"));
    m_oriStrings.Add(_("&west"));
    m_ori = new wxRadioBox( m_LocationPanel, ID_RADIOBOX_CO_ORI, _("Orientation"), wxDefaultPosition, wxDefaultSize, m_oriStrings, 1, wxRA_SPECIFY_COLS );
    m_ori->SetSelection(0);
    itemBoxSizer90->Add(m_ori, 0, wxALIGN_TOP|wxALL, 5);

    m_Notebook->AddPage(m_LocationPanel, _("Location"));

    itemBoxSizer2->Add(m_Notebook, 1, wxGROW|wxALL, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer99 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer99, 0, wxGROW|wxALL, 5);
    m_Cancel = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer99->AddButton(m_Cancel);

    m_OK = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    m_OK->SetDefault();
    itemStdDialogButtonSizer99->AddButton(m_OK);

    m_Apply = new wxButton( itemDialog1, wxID_APPLY, _("&Apply"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer99->AddButton(m_Apply);

    m_Help = new wxButton( itemDialog1, wxID_HELP, _("&Help"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer99->AddButton(m_Help);

    itemStdDialogButtonSizer99->Realize();

////@end OutputDialog content construction
}

/*!
 * Should we show tooltips?
 */

bool OutputDialog::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap OutputDialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin OutputDialog bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end OutputDialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon OutputDialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin OutputDialog icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end OutputDialog icon retrieval
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_CO_NEW
 */

void OutputDialog::OnButtonCoNewClick( wxCommandEvent& event )
{
  int i = findID("NEW");
  if( i == wxNOT_FOUND ) {
    iONode model = wxGetApp().getModel();
    if( model != NULL ) {
      iONode colist = wPlan.getcolist( model );
      if( colist == NULL ) {
        colist = NodeOp.inst( wOutputList.name(), model, ELEMENT_NODE );
        NodeOp.addChild( model, colist );
      }
      if( colist != NULL ) {
        iONode co = NodeOp.inst( wOutput.name(), colist, ELEMENT_NODE );
        NodeOp.addChild( colist, co );
        wOutput.setid( co, "NEW" );
        appendItem(co);
        setIDSelection(wItem.getid(co));
        m_Props = co;
        initValues();
      }
    }
  }
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_CO_DELETE
 */

void OutputDialog::OnButtonCoDeleteClick( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  int action = wxMessageDialog( this, wxGetApp().getMsg("removewarning"), _T("Rocrail"), wxYES_NO | wxICON_EXCLAMATION ).ShowModal();
  if( action == wxID_NO )
    return;

  wxGetApp().pushUndoItem( (iONode)NodeOp.base.clone( m_Props ) );

  /* Notify RocRail. */
  iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
  wModelCmd.setcmd( cmd, wModelCmd.remove );
  NodeOp.addChild( cmd, (iONode)m_Props->base.clone( m_Props ) );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);

  iONode model = wxGetApp().getModel();
  if( model != NULL ) {
    iONode colist = wPlan.getcolist( model );
    if( colist != NULL ) {
      NodeOp.removeChild( colist, m_Props );
      m_Props = NULL;
    }
  }

  initIndex();
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void OutputDialog::OnCancelClick( wxCommandEvent& event )
{
  EndModal( 0 );
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void OutputDialog::OnOkClick( wxCommandEvent& event )
{
  OnApplyClick(event);
  EndModal( wxID_OK );
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_APPLY
 */

void OutputDialog::OnApplyClick( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;
  if( !evaluate() )
    return;

  if( !wxGetApp().isStayOffline() ) {
    /* Notify RocRail. */
    iONode cmd = NodeOp.inst( wModelCmd.name(), NULL, ELEMENT_NODE );
    wModelCmd.setcmd( cmd, wModelCmd.modify );
    NodeOp.addChild( cmd, (iONode)m_Props->base.clone( m_Props ) );
    wxGetApp().sendToRocrail( cmd );
    cmd->base.del(cmd);
  }
  else {
    wxGetApp().setLocalModelModified(true);
  }
  initIndex();
}


/*!
 * wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED event handler for ID_NOTEBOOK_CO
 */

void OutputDialog::OnNotebookCoPageChanged( wxNotebookEvent& event )
{
////@begin wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED event handler for ID_NOTEBOOK_CO in OutputDialog.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED event handler for ID_NOTEBOOK_CO in OutputDialog.
}



/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_OUTPUT_ACTIONS
 */

void OutputDialog::OnOutputActionsClick( wxCommandEvent& event )
{
  if( m_Props == NULL )
    return;

  ActionsCtrlDlg*  dlg = new ActionsCtrlDlg(this, m_Props, "on,active,off" );

  if( wxID_OK == dlg->ShowModal() ) {
    // TODO: inform
  }

  dlg->Destroy();
}


/*!
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_OUTPUT_SWITCH
 */

void OutputDialog::OnOutputSwitchClick( wxCommandEvent& event )
{
  m_Gate->Enable(!m_AsSwitch->GetValue());
}


/*!
 * wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ID_LISTCTRLINDEX_CO
 */

void OutputDialog::OnListctrlindexCoSelected( wxListEvent& event )
{
  m_Props = getSelection(event.GetIndex());
  initValues();
  m_Delete->Enable( true );
}


/*!
 * wxEVT_COMMAND_LIST_COL_CLICK event handler for ID_LISTCTRLINDEX_CO
 */

void OutputDialog::OnListctrlindexCoColLeftClick( wxListEvent& event )
{
  sortOnColumn(event.GetColumn());
}


/*!
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for wxID_ANY
 */

void OutputDialog::onAccessory( wxCommandEvent& event )
{
  m_PortType->SetSelection(0);
  m_PortType->Enable(!m_Accessory->IsChecked());
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_OUTPUT_DOC
 */

void OutputDialog::onDoc( wxCommandEvent& event )
{
  doDoc( event, "outputs" );
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
 */

void OutputDialog::OnHelpClick( wxCommandEvent& event )
{
  switch( m_Notebook->GetSelection() ) {
  case 0: wxGetApp().openLink( "output" ); break; // index
  case 1: wxGetApp().openLink( "output-gen" ); break;
  case 2: wxGetApp().openLink( "output-int" ); break;
  case 3: wxGetApp().openLink( "output" ); break; // position
  default: wxGetApp().openLink( "output" ); break;
  }
}

