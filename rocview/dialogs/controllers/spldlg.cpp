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

#include "spldlg.h"

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#include "wx/defs.h"
#endif

#include "rocview/public/guiapp.h"

#include "rocrail/wrapper/public/DigInt.h"
#include "rocrail/wrapper/public/Program.h"
#include "rocrail/wrapper/public/SPL.h"
#include "rocs/public/strtok.h"


SplDlg::SplDlg( wxWindow* parent, iONode props, const char* devices ):SplDlgGen( parent ) {
  m_Props = props;

  m_labIID->SetLabel(wxGetApp().getMsg( "iid" ));
  m_labDevice->SetLabel(wxGetApp().getMsg( "port" ));
  m_NoteBook->SetPageText( 0, wxGetApp().getMsg( "setup" ) );
  m_NoteBook->SetPageText( 1, wxGetApp().getMsg( "programming" ) );
  m_NoteBook->SetPageText( 2, wxGetApp().getMsg( "control" ) );
  m_labAddress->SetLabel(wxGetApp().getMsg( "address" ));
  m_labNewAddress->SetLabel(wxGetApp().getMsg( "newaddress" ));
  m_labAddressRange->SetLabel(wxGetApp().getMsg( "range" ));
  m_SetAddress->SetLabel(wxGetApp().getMsg( "set" ));
  m_SetRange->SetLabel(wxGetApp().getMsg( "set" ));
  // Resize
  GetSizer()->Layout();
  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);

  if( devices != NULL ) {
    iOStrTok tok = StrTokOp.inst(devices, ',');
    while( StrTokOp.hasMoreTokens(tok) ) {
      m_Device->Append( wxString( StrTokOp.nextToken(tok), wxConvUTF8 ) );
    }
    StrTokOp.base.del(tok);
  }

  m_IID->SetValue( wxString( wDigInt.getiid( m_Props ), wxConvUTF8 ) );
  m_Device->SetValue( wxString( wDigInt.getdevice( m_Props ), wxConvUTF8 ) );
  iONode splini = wDigInt.getspl( m_Props );
  if( splini == NULL ) {
    splini = NodeOp.inst( wSPL.name(), m_Props, ELEMENT_NODE );
    NodeOp.addChild(m_Props, splini);
  }

  m_FromAddress->SetValue( wSPL.getfromaddr(splini) );
  m_ToAddress->SetValue( wSPL.gettoaddr(splini) );
  m_8LEDs->SetValue( wSPL.getnrleds(splini) == 8 ? true:false);

}

void SplDlg::onHelp( wxCommandEvent& event )
{
  wxGetApp().openLink( "elektor-spl" );
}

void SplDlg::onSetAddress( wxCommandEvent& event )
{
  iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
  wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
  wProgram.setcmd( cmd, wProgram.set );
  wProgram.setaddr( cmd, m_Address->GetValue() );
  wProgram.setvalue( cmd, m_NewAddress->GetValue() );
  wProgram.setcv( cmd, wProgram.set );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}

void SplDlg::onSetRange( wxCommandEvent& event ) {
  iONode cmd = NodeOp.inst( wProgram.name(), NULL, ELEMENT_NODE );
  wProgram.setiid( cmd, m_IID->GetValue().mb_str(wxConvUTF8) );
  wProgram.setcmd( cmd, wProgram.nvset );
  wProgram.setval1( cmd, m_FromAddress->GetValue() );
  wProgram.setval2( cmd, m_ToAddress->GetValue() );
  wProgram.setval3( cmd, m_8LEDs->IsChecked()?8:5 );
  wProgram.setcv( cmd, 1 );
  wxGetApp().sendToRocrail( cmd );
  cmd->base.del(cmd);
}


void SplDlg::onOK( wxCommandEvent& event )
{
  wDigInt.setiid( m_Props, m_IID->GetValue().mb_str(wxConvUTF8) );
  wDigInt.setdevice( m_Props, m_Device->GetValue().mb_str(wxConvUTF8) );
  iONode splini = wDigInt.getspl( m_Props );
  wSPL.setfromaddr(splini, m_FromAddress->GetValue() );
  wSPL.settoaddr(splini, m_ToAddress->GetValue() );
  wSPL.setnrleds(splini, m_8LEDs->IsChecked() ? 8:5);

  EndModal( wxID_OK );
}

void SplDlg::onCancel( wxCommandEvent& event ) {
  EndModal(0);
}


