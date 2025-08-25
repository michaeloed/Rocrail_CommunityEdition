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
// ============================================================================
// declarations
// ============================================================================

// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
    #include "wx/event.h"
#endif

#include "rocview/public/guiapp.h"
#include "rocview/public/statbar.h"

#include "rocview/xpm/on.xpm"
#include "rocview/xpm/off.xpm"


BEGIN_EVENT_TABLE(StatusBar, wxStatusBar)
    EVT_SIZE(StatusBar::OnSize)
END_EVENT_TABLE()


// ----------------------------------------------------------------------------
// StatusBar
// ----------------------------------------------------------------------------

StatusBar::StatusBar(wxWindow *parent)
           : wxStatusBar(parent, wxID_ANY)
             
{
    static const int widths[status_max] = { -1, -1, -1, 160, BITMAP_SIZE_X*8 };


    SetFieldsCount(status_max);
    SetStatusWidths(status_max, widths);

    m_statbmpH = new wxStaticBitmap(this, wxID_ANY, wxIcon(off_xpm));
    m_statbmpP = new wxStaticBitmap(this, wxID_ANY, wxIcon(off_xpm));
    m_statbmpT = new wxStaticBitmap(this, wxID_ANY, wxIcon(off_xpm));
    m_statbmpS = new wxStaticBitmap(this, wxID_ANY, wxIcon(off_xpm));
    m_statbmpA = new wxStaticBitmap(this, wxID_ANY, wxIcon(off_xpm));
    m_statbmpR = new wxStaticBitmap(this, wxID_ANY, wxIcon(off_xpm));

    m_statbmpH->SetToolTip(wxGetApp().getMsg("planhealth"));
    m_statbmpP->SetToolTip(wxGetApp().getMsg("power"));
    m_statbmpT->SetToolTip(wxGetApp().getMsg("communication"));
    m_statbmpS->SetToolTip(wxGetApp().getMsg("sensors"));
    m_statbmpA->SetToolTip(wxGetApp().getMsg("accessory"));
    m_statbmpR->SetToolTip(wxGetApp().getMsg("automode"));
    SetMinHeight(BITMAP_SIZE_Y);

}

StatusBar::~StatusBar()
{
}


void StatusBar::OnSize(wxSizeEvent& event)
{
    wxRect rect;
    GetFieldRect(status_controller, rect);
    wxSize size = m_statbmpH->GetSize();

    m_statbmpH->Move(rect.x + (rect.width - size.x*5) / 2,
                    rect.y + (rect.height - size.y) / 2);
    m_statbmpP->Move(rect.x + size.x+ 1 + (rect.width - size.x*5) / 2,
                    rect.y + (rect.height - size.y) / 2);
    m_statbmpT->Move(rect.x + size.x*2+2+ (rect.width - size.x*5) / 2,
                    rect.y + (rect.height - size.y) / 2);
    m_statbmpS->Move(rect.x + size.x*3+ 3+(rect.width - size.x*5) / 2,
                    rect.y + (rect.height - size.y) / 2);
    m_statbmpA->Move(rect.x + size.x*4+ 4+(rect.width - size.x*5) / 2,
                    rect.y + (rect.height - size.y) / 2);
    m_statbmpR->Move(rect.x + size.x*5+ 5+(rect.width - size.x*5) / 2,
                    rect.y + (rect.height - size.y) / 2);

    event.Skip();
}

void StatusBar::Update( int flags)
{
    m_statbmpP->SetIcon(flags&0x01?wxIcon(on_xpm):wxIcon(off_xpm));
    m_statbmpT->SetIcon(flags&0x02?wxIcon(on_xpm):wxIcon(off_xpm));
    m_statbmpS->SetIcon(flags&0x04?wxIcon(on_xpm):wxIcon(off_xpm));
    m_statbmpA->SetIcon(flags&0x08?wxIcon(on_xpm):wxIcon(off_xpm));
}

void StatusBar::Health( bool health)
{
    m_statbmpH->SetIcon(health?wxIcon(on_xpm):wxIcon(off_xpm));
}

void StatusBar::Automode( bool automode)
{
    m_statbmpR->SetIcon(automode?wxIcon(on_xpm):wxIcon(off_xpm));
}
