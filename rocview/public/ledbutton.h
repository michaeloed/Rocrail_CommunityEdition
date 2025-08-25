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

#ifndef LEDBUTTON_H_
#define LEDBUTTON_H_

#include <wx/graphics.h>
#include <wx/panel.h>

class LEDButton : public wxPanel
{
    wxWindow* Parent;
    bool pressedDown;
    bool useLED;
    bool textOnly;
    wxString text;

    int buttonWidth;
    int buttonHeight;

    wxBitmap* icon;
    wxBitmap* scaledIcon;


public:
    bool ON;
    LEDButton(wxWindow* parent, wxString text, int width, int height, bool useLED=true, bool textOnly=false);
    ~LEDButton();

    void OnPaint(wxPaintEvent& event);
    void OnSize(wxSizeEvent& event);

    void setLED(bool ON);
    void SetLabel(const wxString &text);
    void SetIcon(wxBitmap* icon);
    void SetValue(const wxString& value);
    bool SetBackgroundColour(const wxColour& colour);
    void Display7Segement(wxGraphicsContext* gc);
    void draw7Segement(wxGraphicsContext* gc, int val, int offset);

    // some useful events
    void mouseMoved(wxMouseEvent& event);
    void mouseDown(wxMouseEvent& event);
    void mouseWheelMoved(wxMouseEvent& event);
    void mouseReleased(wxMouseEvent& event);
    void rightClick(wxMouseEvent& event);
    void mouseLeftWindow(wxMouseEvent& event);
    void keyPressed(wxKeyEvent& event);
    void keyReleased(wxKeyEvent& event);

    DECLARE_EVENT_TABLE()
};





#endif /* LEDBUTTON_H_ */
