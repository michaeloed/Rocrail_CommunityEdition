/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 


 This program is free software; you can redistribute it and/or
 as published by the Free Software Foundation; either version 2
 modify it under the terms of the GNU General Public License
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include "issuedlg.h"

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#include "wx/defs.h"
#endif

#include "rocs/public/trace.h"
#include "rocs/public/str.h"
#include "rocview/public/guiapp.h"

#include "rocrail/wrapper/public/Issue.h"

IssueDlg::IssueDlg( wxWindow* parent ):IssueDlgGen( parent )
{
  m_Issue = NULL;
  SetTitle(wxGetApp().getMsg( "issue" ));
  m_labSubject->SetLabel( wxGetApp().getMsg( "subject" ) );
  // Buttons
  m_StdButtonOK->SetLabel( wxGetApp().getMsg( "ok" ) );
  m_StdButtonCancel->SetLabel( wxGetApp().getMsg( "cancel" ) );

  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);
}

void IssueDlg::onCancel( wxCommandEvent& event )
{
  EndModal( 0 );
}

void IssueDlg::onOK( wxCommandEvent& event )
{
  m_Issue = NodeOp.inst( wIssue.name(), NULL, ELEMENT_NODE );
  wIssue.setsubject(m_Issue, m_Subject->GetValue().mb_str(wxConvUTF8));
  wIssue.setdesc(m_Issue, m_Description->GetValue().mb_str(wxConvUTF8));
  /*
  wIssue.setini(m_Issue, m_InclIni->IsChecked() ? True:False);
  wIssue.settrc(m_Issue, m_InclTrc->IsChecked() ? True:False);
  wIssue.setstat(m_Issue, m_InclStat->IsChecked() ? True:False);
  wIssue.setxml(m_Issue, m_InclXML->IsChecked() ? True:False);
  */
  EndModal( wxID_OK );
}

void IssueDlg::onHelp( wxCommandEvent& event ) {
  wxGetApp().openLink( "issue" );
}
