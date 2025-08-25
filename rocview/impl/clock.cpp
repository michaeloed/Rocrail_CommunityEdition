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

// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------
#ifdef __GNUG__
#pragma implementation "rocgui.cpp"
#pragma interface "rocgui.cpp"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWindows headers)
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <wx/dcbuffer.h>


#include "rocs/public/node.h"
#include "rocs/public/str.h"
#include "rocs/public/trace.h"
#include "rocs/public/file.h"

#include "rocrail/wrapper/public/Clock.h"

#include "rocview/public/clock.h"
#include "rocview/dialogs/clockdialog.h"
#include "rocview/public/guiapp.h"
#include "rocview/public/guiframe.h"
#include "rocview/res/icons.hpp"
#include "rocview/public/base.h"
#include "rocview/wrapper/public/Gui.h"


BEGIN_EVENT_TABLE(Clock, wxPanel)
EVT_PAINT(Clock::OnPaint)
EVT_TIMER(ID_WXTIMER, Clock::Timer)
EVT_RIGHT_UP(Clock::OnPopup)
EVT_MENU(ME_AdjustTime, Clock::OnAdjustTime)
EVT_MENU(ME_FreezeTime, Clock::OnFreezeTime)
EVT_MENU(ME_ResumeTime, Clock::OnResumeTime)
EVT_MENU(ME_ClockHelp, Clock::OnHelp)
END_EVENT_TABLE()

Clock::Clock(wxWindow *parent, wxWindowID id, int x, int y, int handwidth, int p_devider, int clocktype, bool showsecondhand)
    : wxPanel(parent, id, wxPoint(x, y), clocktype == 3 ? wxDefaultSize : wxSize(110, 110), wxBORDER_NONE)
{
    m_Parent = parent;
    start = true;
    run = true;
    second = true;
    deviderchanged = false;
    this->showsecondhand = showsecondhand;
    m_Logo = _img_logo;
    m_Temp = 20;

    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

    type = clocktype;

    devider = p_devider;
    if (devider <= 0)
        devider = 1;

    datetime = new wxDateTime();
    datetime->SetToCurrent();
    ltime = datetime->GetTimeNow();

    WxTimer = new wxTimer();
    WxTimer->SetOwner(this, ID_WXTIMER);
    WxTimer->Start(TIMER / devider);

    calculate();

    TraceOp.trc("clock", TRCLEVEL_INFO, __LINE__, 9999, "clock instantiated");
}

int modulal(int val)
{
    do {
        val += 360;
    } while (val < 0);
    return val;
}

int kactane(int x, int y)
{
    int times = 0;
    do {
        x -= y;
        times++;
    } while (x >= y);
    return times;
}

double sm_angle(int m)
{
    // Values of m must be minute or second.
    return ((modulal((90 - (m * 6))) * M_PI) / 180);
}

double h_angle(int m, int n)
{
    // Values of m must be hour, values of n must be minute.
    return ((modulal((90 - (m * 30) - (kactane(n, 6) * 3))) * M_PI) / 180);
}

void Clock::OnPopup(wxMouseEvent& event) {

    wxMenu menu(wxGetApp().getMenu("clock"));
    menu.Append(ME_AdjustTime, wxGetApp().getMenu("adjusttime"));
    menu.Append(ME_FreezeTime, wxGetApp().getMenu("freezetime"));
    menu.Append(ME_ResumeTime, wxGetApp().getMenu("resumetime"));
    menu.Append(ME_ClockHelp, wxGetApp().getMenu("help"));
    PopupMenu(&menu, event.GetX(), event.GetY());
}

void Clock::OnAdjustTime(wxCommandEvent& event) {
    ClockDialog* dlg = new ClockDialog(this);
    dlg->setClock(devider, datetime->GetHour(), datetime->GetMinute(), m_Temp);
    if (wxID_OK == dlg->ShowModal()) {
        int hour, minute;
        dlg->getClock(&devider, &hour, &minute, &m_Temp);

        datetime->SetHour(hour);
        datetime->SetMinute(minute);
        datetime->SetSecond(0);

        ltime = datetime->GetTicks();

        // send to rocrail
        iONode tick = NodeOp.inst(wClock.name(), NULL, ELEMENT_NODE);
        wClock.setdivider(tick, devider);
        wClock.settime(tick, ltime);
        wClock.settemp(tick, m_Temp);
        wxGetApp().sendToRocrail(tick, false);
    }
}


void Clock::OnFreezeTime(wxCommandEvent& event) {
    // send to rocrail
    iONode tick = NodeOp.inst(wClock.name(), NULL, ELEMENT_NODE);
    wClock.setcmd(tick, wClock.freeze);
    wxGetApp().sendToRocrail(tick, false);
}


void Clock::OnResumeTime(wxCommandEvent& event) {
    // send to rocrail
    iONode tick = NodeOp.inst(wClock.name(), NULL, ELEMENT_NODE);
    wClock.setcmd(tick, wClock.go);
    wxGetApp().sendToRocrail(tick, false);
}

void Clock::OnHelp(wxCommandEvent& event) {
    wxGetApp().openLink("clock-adjust");
}

void Clock::OnPaint(wxPaintEvent& event)
{
    drawNewClock();
}

void Clock::stopTimer() {
    WxTimer->Stop();
}

void Clock::SyncClock(iONode node) {
    if (StrOp.equals(wClock.getcmd(node), wClock.freeze)) {
        run = false;
    }
    else if (StrOp.equals(wClock.getcmd(node), wClock.go)) {
        run = true;
        SetDevider(wClock.getdivider(node));
        SetTime(wClock.gettime(node));
    }
    else {
        SetDevider(wClock.getdivider(node));
        SetTime(wClock.gettime(node));
        m_Temp = wClock.gettemp(node);
    }
}


void Clock::SetDevider(int p_devider) {
    if (devider != p_devider) {
        devider = p_devider;
        TraceOp.trc("clock", TRCLEVEL_INFO, __LINE__, 9999, "devider set to %d.", devider);
    }
    deviderchanged = true;
}

void Clock::SetTime(long p_time) {
    //ltime = (p_time / 60) * 60; // Filter out the seconds.
    ltime = p_time; // Filter out the seconds.
    if (run) {
        calculate();
        Refresh(true);
    }
}

long Clock::GetTime() {
    return ltime;
}

int Clock::GetHour() {
    return hours;
}

void Clock::calculate() {
    if (1) {
        ltime++;
        datetime->Set(ltime);
    }
    else {
        ltime = wxDateTime::GetTimeNow();
        datetime->Set(ltime);
    }

    /*
    if ((datetime->GetSecond() == 0) || start)
      Refresh(true);
    start = false;
  */
    x = sm_angle(datetime->GetSecond());
    y = sm_angle(datetime->GetMinute());
    z = h_angle(datetime->GetHour(), datetime->GetMinute());
    hours = datetime->GetHour();
    minutes = datetime->GetMinute();
}

void Clock::Timer(wxTimerEvent& WXUNUSED(event))
{
    if (deviderchanged) {
        deviderchanged = false;
        if (this->devider <= 10 && showsecondhand) {
            WxTimer->Start(TIMER / devider);
        }
        else {
            WxTimer->Start((TIMER * 60) / devider);
        }
    }

    if (run) {
        calculate();
        Refresh(false);
    }
}



void Clock::drawNewClock() {
    int width, height;

    if (!IsShownOnScreen())
        return;

    if (type == 3) {
        // digital clock
        wxPaintDC dc(this);
        wxGraphicsContext* gc = wxGraphicsContext::Create(dc);

        wxString timestring = wxString::Format(_T("%02d%c%02d"), hours, second ? ':' : ' ', minutes);
        second = !second;

        wxFont font(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
        gc->SetFont(font, *wxBLACK);

        double w;
        double h;
        double descent;
        double externalLeading;
        gc->GetTextExtent(timestring, (wxDouble*)&w, (wxDouble*)&h, (wxDouble*)&descent, (wxDouble*)&externalLeading);

        wxPen borderPen(wxColour(100, 100, 100), wxSOLID);
        borderPen.SetWidth(2);
        gc->SetPen(borderPen);
        gc->SetBrush(*wxWHITE_BRUSH);
        gc->DrawRoundedRectangle(1.0, 1.0, w + 8, h + 8, 5.0);
        gc->DrawText(timestring, 4, 4);

        SetSize(wxDefaultCoord, wxDefaultCoord, w + 10, h + 11, wxSIZE_FORCE);

        delete gc;

        return;
    }


#if defined _WIN32
    SetBackgroundStyle(wxBG_STYLE_CUSTOM);
    wxBufferedPaintDC dc(this);
    wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
#else
    wxPaintDC dc(this);
    wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
#endif

#ifdef wxANTIALIAS_DEFAULT
    gc->SetAntialiasMode(wxANTIALIAS_DEFAULT);
#endif

    GetSize(&width, &height);

#if defined _WIN32
    //Background workaround
    if (wGui.isgrayicons(wxGetApp().getIni()))
        gc->SetBrush(Base::getGrey());
    else
        gc->SetBrush(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    gc->DrawRectangle(0, 0, width, height);
#endif

    if (height < width)
        width = height;

    if (width < 110)
        width = 110;

    double c = width / 2;

    wxPen borderPen(wxColour(0, 0, 0), wxSOLID);
    borderPen.SetWidth(1);
    gc->SetPen(borderPen);
    gc->SetBrush(*wxWHITE_BRUSH);

    gc->DrawEllipse(0, 0, width - 1, width - 1);

    drawSecondHand(gc, c, true);


    int i;
    wxGraphicsPath platePath = gc->CreatePath();
    wxPen platePen(wxColour(0, 0, 0), wxSOLID);
    for (i = 0; i < 60; i++) {
        double k = sm_angle(i);

        platePath.MoveToPoint(c + 0.85 * c * cos(k), c - 0.85 * c * sin(k));
        platePath.AddLineToPoint(c + 0.90 * c * cos(k), c - 0.90 * c * sin(k));
        gc->StrokePath(platePath);

    }
    platePen.SetWidth(1);
    gc->SetPen(platePen);
    gc->StrokePath(platePath);

    platePath = gc->CreatePath();
    for (i = 0; i < 60; i++) {
        double k = sm_angle(i);

        if (i % 5 == 0) {
            platePath.MoveToPoint(c + 0.75 * c * cos(k), c - 0.75 * c * sin(k));
            platePath.AddLineToPoint(c + 0.90 * c * cos(k), c - 0.90 * c * sin(k));
        }
    }
    platePen.SetWidth(4);
    gc->SetPen(platePen);
    gc->StrokePath(platePath);

    gc->SetPen(*wxBLACK_PEN);

    if (type == 1 || type == 2) {
        wxString timestring;
        if (type == 1 && hours < 12)
            timestring = wxString::Format(_T("AM %d:%02d"), hours, minutes);
        else if (type == 1 && hours >= 12)
            timestring = wxString::Format(_T("PM %d:%02d"), hours - 12, minutes);
        else
            timestring = wxString::Format(_T("%02d:%02d"), hours, minutes);

        wxFont font(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
        gc->SetFont(font, *wxBLACK);

        double w;
        double h;
        double descent;
        double externalLeading;
        gc->GetTextExtent(timestring, (wxDouble*)&w, (wxDouble*)&h, (wxDouble*)&descent, (wxDouble*)&externalLeading);
        gc->DrawText(timestring, (width / 2) - (w / 2), width*0.6);


    }

    if (m_Logo != NULL && m_Logo->Ok()) {
        int w = m_Logo->GetWidth();
        int h = m_Logo->GetHeight();
        gc->DrawBitmap(wxBitmap(*m_Logo), (width / 2) - (w / 2), width*0.3, w, h);
    }


    // hour
    wxPen blackPen(wxColour(0, 0, 0), wxSOLID);
    blackPen.SetWidth(4);
    gc->SetPen(blackPen);
    wxGraphicsPath hpath = gc->CreatePath();
    hpath.MoveToPoint(c, c);
    hpath.AddLineToPoint(c + 0.6 * c * cos(z), c - 0.6  * c * sin(z));
    gc->StrokePath(hpath);


    // minute
    //dc.DrawLine((int)c, (int)c, (int)(c + 0.85 * c * cos(y)), (int)(c - 0.85  * c * sin(y))); // minute hand
    wxGraphicsPath mpath = gc->CreatePath();
    mpath.MoveToPoint(c, c);
    mpath.AddLineToPoint(c + 0.85 * c * cos(y), c - 0.85  * c * sin(y));
    gc->StrokePath(mpath);


    // second
    drawSecondHand(gc, c);

    gc->SetBrush(*wxRED_BRUSH);
    gc->DrawEllipse(c - 2, c - 2, 4, 4);


    delete gc;


}

void Clock::drawSecondHand(wxGraphicsContext* gc, double c, bool erase) {
    // second
    if (erase || (showsecondhand && this->devider <= 10)) {
        gc->SetBrush(erase ? *wxWHITE_BRUSH : wxColour(255, 0, 0));
        wxPen redPen(erase ? wxColour(255, 255, 255) : wxColour(255, 0, 0), wxSOLID);
        redPen.SetWidth(2);
        gc->SetPen(redPen);

        //dc.DrawLine((int)c, (int)c, (int)(c + 0.52 * c * cos(x)), (int)(c - 0.52 * c * sin(x))); // second hand
        wxGraphicsPath path = gc->CreatePath();
        path.MoveToPoint(c, c);
        path.AddLineToPoint(c + 0.52 * c * cos(x), c - 0.52 * c * sin(x));
        gc->StrokePath(path);


        gc->SetBrush(erase ? *wxWHITE_BRUSH : *wxTRANSPARENT_BRUSH);
        //dc.DrawCircle((int)(c + 0.60 * c * cos(x)), (int)(c - 0.60 * c * sin(x)), 4); // second hand
        gc->DrawEllipse(c - 4 + 0.60 * c * cos(x), c - 4 - 0.60 * c * sin(x), 8, 8);

        //dc.DrawLine((int)(c + 0.68 * c * cos(x)), (int)(c - 0.68 * c * sin(x)), (int)(c + 0.90 * c * cos(x)), (int)(c - 0.90 * c * sin(x))); // second hand
        path = gc->CreatePath();
        path.MoveToPoint(c + 0.68 * c * cos(x), c - 0.68 * c * sin(x));
        path.AddLineToPoint(c + 0.90 * c * cos(x), c - 0.90 * c * sin(x));
        gc->StrokePath(path);
    }
}



