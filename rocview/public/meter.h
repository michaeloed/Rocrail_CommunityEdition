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

#ifndef __Meter_H__
#define __Meter_H__

#define ID_METERTIMER  998
#define TIMER   1000

#include <wx/datetime.h>
#include <wx/image.h>
#include <wx/math.h>
#include <wx/timer.h>
#include <wx/panel.h>

class Meter : public wxPanel{
  public:
    Meter(wxWindow *parent, wxWindowID id, int x, int y, int p_devider=1);
    void OnPaint(wxPaintEvent& event);
    void OnPopup(wxMouseEvent& event);
    void setSpeed(int speed, int maxspeed=0, int runtime=0);
    void Timer(wxTimerEvent& event);
    void OnMenu( wxCommandEvent& event );
    void SyncClock( iONode node );
    int GetHour();
    void SetDevider(int devider);
    void SetTime(long rocrailtime);
    void stopTimer();

  private:
    void drawNeedle(wxGraphicsContext* gc, double c, bool erase=false);
    void calculate();

    wxWindow* m_Parent;
    wxTimer *WxTimer;
    int m_iRunTime;
    int m_iSpeed;
    int m_iMaxSpeed;
    double speed;
    bool second;
    wxDateTime* datetime;
    time_t ltime;
    int devider;
    bool deviderchanged;
    bool run;
    int hours, minutes;
    int m_Temp;

};

enum {
  ME_MeterAdjustTime = 201,
  ME_MeterFreezeTime,
  ME_MeterResumeTime,
  ME_MeterHelp
};


#endif
