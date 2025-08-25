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

#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
    #include "wx/log.h"
#endif

#include "wx/print.h"
#include <wx/graphics.h>

#include "rocs/public/trace.h"

#include "rocview/public/ledbutton.h"
#include "rocview/public/guiapp.h"
#include "rocview/public/base.h"
#include "rocview/wrapper/public/Gui.h"


BEGIN_EVENT_TABLE(LEDButton, wxPanel)

    EVT_MOTION(LEDButton::mouseMoved)
    EVT_LEFT_DOWN(LEDButton::mouseDown)
    EVT_LEFT_UP(LEDButton::mouseReleased)
    EVT_RIGHT_DOWN(LEDButton::rightClick)
    EVT_LEAVE_WINDOW(LEDButton::mouseLeftWindow)
    EVT_KEY_DOWN(LEDButton::keyPressed)
    EVT_KEY_UP(LEDButton::keyReleased)
    EVT_MOUSEWHEEL(LEDButton::mouseWheelMoved)

    // catch paint events
    EVT_PAINT(LEDButton::OnPaint)
    EVT_SIZE(LEDButton::OnSize)

END_EVENT_TABLE()


LEDButton::LEDButton(wxWindow* parent, wxString text, int width, int height, bool useLED, bool textOnly)
  :wxPanel(parent, -1,  wxDefaultPosition, wxSize(width,height), wxBORDER_NONE|wxWANTS_CHARS|wxGROW|wxFULL_REPAINT_ON_RESIZE)
{
  buttonWidth = width;
  buttonHeight = height;
  SetSize( wxSize(buttonWidth, buttonHeight) );
  this->text = text;
  pressedDown = false;
  ON = false;
  Parent = parent;
  this->useLED = useLED;
  this->textOnly = textOnly;
  this->icon = NULL;
  this->scaledIcon = NULL;
  SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
}

LEDButton::~LEDButton() {
  if( this->icon != NULL ) {
    delete this->icon;
    this->icon = NULL;
  }

  if( this->scaledIcon != NULL ) {
    delete this->scaledIcon;
    this->scaledIcon = NULL;
  }
}


void LEDButton::OnSize(wxSizeEvent& WXUNUSED(event)) {
  Refresh();
}

/*
 * Called by the system of by wxWidgets when the panel needs
 * to be redrawn. You can also trigger this call by
 * calling Refresh()/Update().
 */

void LEDButton::OnPaint(wxPaintEvent& WXUNUSED(event))
{
  wxPaintDC dc(this);

  if( !IsShownOnScreen() )
    return;
  TraceOp.trc( "clock", TRCLEVEL_DEBUG, __LINE__, 9999, "draw ledbutton" );

  wxGraphicsContext* gc = wxGraphicsContext::Create(this);

  if( gc == NULL )
    return;

  int w,h;
  GetSize(&w,&h);
  buttonWidth  = w;
  buttonHeight = h;

#ifdef wxANTIALIAS_DEFAULT
  gc->SetAntialiasMode(wxANTIALIAS_DEFAULT);
#endif
  // make a path that contains a circle and some lines
  if (pressedDown)
    gc->SetBrush( *wxGREY_BRUSH );
  else
    gc->SetBrush( *wxLIGHT_GREY_BRUSH );

  wxPen pen( wxColour(100, 100, 100), wxSOLID );
  pen.SetWidth(1);
  gc->SetPen( pen );

  if(textOnly)
    gc->SetBrush( *wxWHITE_BRUSH );
  else {
    if( wGui.isgrayicons(wxGetApp().getIni()) )
      gc->SetBrush( pressedDown ? *wxGREY_BRUSH:(ON?wxBrush(Base::getDarkGrey()):(useLED?wxBrush(Base::getGrey()):wxBrush(wxColour(230,230,230)))) );
    else
      gc->SetBrush( pressedDown ? *wxGREY_BRUSH:(ON?wxBrush(wxColour(255,200,200)):(useLED?wxBrush(wxColour(200,255,200)):wxBrush(wxColour(230,230,230)))) );
  }


  if( !IsEnabled() ) {
    gc->SetBrush(wxBrush(wxColour(230,230,230)));
  }
  //gc->DrawRoundedRectangle(1, 1, buttonWidth-2, buttonHeight-2, 5.0);
  gc->DrawRoundedRectangle(0, 0, buttonWidth-2, buttonHeight-2, 3.0);

  if( useLED && ON && wGui.isgrayicons(wxGetApp().getIni()) ) {
    wxPen pen( wxColour(200, 0, 0), wxSOLID );
    pen.SetWidth(1);
    gc->SetPen( pen );
    gc->SetBrush( wxBrush(wxColour(225,0,0)) );
    gc->DrawEllipse(2.5, 2.5, 3.0, 3.0);
  }

  if(textOnly) {
    wxFont font(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    gc->SetFont(font,*wxBLACK);
    //Display7Segement(gc);
    double width;
    double height;
    double descent;
    double externalLeading;
    gc->GetTextExtent( text,(wxDouble*)&width,(wxDouble*)&height,(wxDouble*)&descent,(wxDouble*)&externalLeading);
    gc->DrawText( text, (buttonWidth-width)/2, (buttonHeight-height)/2 );
  }
  else {
    wxFont font(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    gc->SetFont(font,IsEnabled()?*wxBLACK:*wxLIGHT_GREY);

    if( icon != NULL ) {
      wxBitmap* l_icon = icon;
      if( scaledIcon != NULL )
        l_icon = scaledIcon;
      dc.DrawBitmap(*l_icon, (buttonWidth - l_icon->GetWidth())/2, (buttonHeight - l_icon->GetHeight())/2, true);
    }
    else {
      double width;
      double height;
      double descent;
      double externalLeading;
      gc->Clip(0, 0, buttonWidth-4, buttonHeight-4);
      gc->GetTextExtent( text,(wxDouble*)&width,(wxDouble*)&height,(wxDouble*)&descent,(wxDouble*)&externalLeading);
      int border = (w*10)/100;
      if( width > (w-border) ) {
        wxFont font(7, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
        gc->SetFont(font,*wxBLACK);
        gc->GetTextExtent( text,(wxDouble*)&width,(wxDouble*)&height,(wxDouble*)&descent,(wxDouble*)&externalLeading);
        if( width > (w-border) ) {
          wxFont font(6, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
          gc->SetFont(font,*wxBLACK);
          gc->GetTextExtent( text,(wxDouble*)&width,(wxDouble*)&height,(wxDouble*)&descent,(wxDouble*)&externalLeading);
          if( width > (w-border) ) {
            wxFont font(5, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
            gc->SetFont(font,*wxBLACK);
            gc->GetTextExtent( text,(wxDouble*)&width,(wxDouble*)&height,(wxDouble*)&descent,(wxDouble*)&externalLeading);
          }
        }
      }
      gc->DrawText( text, (buttonWidth-width)/2, (buttonHeight-height)/2 );
      gc->ResetClip();
    }
  }
  delete gc;

}


void LEDButton::draw7Segement(wxGraphicsContext* gc, int segval, int segoff) {
  //int segwidth = (buttonWidth-12) / 4;
  int segheight = buttonHeight - 8;
  int segwidth  = segheight;
  // horizontal
  wxPen pen( wxColour(100, 100, 100), wxSOLID );
  pen.SetWidth(1);
  gc->SetPen( pen );
  gc->SetBrush( *wxBLACK_BRUSH );

  if( segval == 0 || segval == 2 || segval == 3 || segval == 5 || segval == 6 || segval == 7 || segval == 8 || segval == 9 )
    gc->DrawRectangle(segoff, 4, segwidth, 2 );

  if( segval == 2 || segval == 3 || segval == 4  || segval == 5 || segval == 6 || segval == 8 || segval == 9 )
    gc->DrawRectangle(segoff, 4 + segheight/2 - 1, segwidth, 2 );

  if( segval == 0 || segval == 2 || segval == 3 || segval == 5 || segval == 6 || segval == 8 || segval == 9 )
    gc->DrawRectangle(segoff, 4 + segheight - 2, segwidth, 2 );



  // vertical
  if( segval == 0 || segval == 4 || segval == 5 || segval == 6 || segval == 8 || segval == 9 )
    gc->DrawRectangle(segoff, 4, 2, segheight/2 );

  if( segval == 0 || segval == 2 || segval == 6 || segval == 8 )
    gc->DrawRectangle(segoff, 4 + segheight/2, 2, segheight/2 );

  if( segval == 0 || segval == 1 || segval == 2 || segval == 3 || segval == 4 || segval == 7 || segval == 8 || segval == 9 )
    gc->DrawRectangle(segoff+segwidth-2, 4, 2, segheight/2 );

  if( segval == 0 || segval == 1 || segval == 3 || segval == 4 || segval == 5 || segval == 6 || segval == 7 || segval == 8 || segval == 9 )
    gc->DrawRectangle(segoff+segwidth-2, 4 + segheight/2, 2, segheight/2 );
}


void LEDButton::Display7Segement(wxGraphicsContext* gc) {
  //int segwidth = (buttonWidth-12) / 4;
  int segheight = buttonHeight - 8;
  int segwidth  = segheight;
  int seggap = segwidth / 4;
  int segoffset = (buttonWidth - 3 * segwidth - 2 * seggap) / 2;
  int val = atoi(text.mb_str(wxConvUTF8));
  int val100 = val / 100;
  int val10 = (val % 100) / 10;
  int val1 = val % 10;


  if( val100 > 0 )
    draw7Segement(gc, val100, segoffset);
  if( val100 > 0 || val10 > 0 )
    draw7Segement(gc, val10, segoffset + seggap*1 + segwidth);
  draw7Segement(gc, val1, segoffset + seggap*2 + segwidth*2);
}


void LEDButton::setLED(bool ON) {
  this->ON = ON;
  Refresh();
}

void LEDButton::SetLabel(const wxString &text) {
  this->text = text;
  Refresh();
}

void LEDButton::SetIcon(wxBitmap* icon) {
  if( this->icon != NULL ) {
    delete this->icon;
    this->icon = NULL;
  }

  if( this->scaledIcon != NULL ) {
    delete this->scaledIcon;
    this->scaledIcon = NULL;
  }

  this->icon = icon;

  if( icon != NULL ) {
    float bmpW = icon->GetWidth();
    float bmpH = icon->GetHeight();
    float butW = buttonWidth-4;
    float butH = buttonHeight-4;
    float scaleW = bmpW / butW;
    float scaleH = bmpH / butH;
    float scale = 0;
    if( scaleW > scaleH ) {
      scale = scaleW;
    }
    else {
      scale = scaleH;
    }

    if( (int)scale != 0 && (bmpW/scale) > 0 && (bmpH/scale) > 0 ) {
      wxImage img = icon->ConvertToImage();
      img = img.Scale( (bmpW/scale), (bmpH/scale), wxIMAGE_QUALITY_HIGH );
      scaledIcon = new wxBitmap(img);
    }
  }

  Refresh();
}


void LEDButton::SetValue(const wxString& value) {
  SetLabel(value);
}

bool LEDButton::SetBackgroundColour(const wxColour& colour) {
  return true;
}


void LEDButton::mouseDown(wxMouseEvent& event)
{
  SetFocus();

  if( textOnly )
    return;

    pressedDown = true;
    Refresh();
}
void LEDButton::mouseReleased(wxMouseEvent& event)
{
  if( textOnly || !IsEnabled() )
    return;

    pressedDown = false;
    Refresh();

    wxCommandEvent bttn_event( wxEVT_COMMAND_BUTTON_CLICKED,-1 );
    bttn_event.SetId(-1);
    bttn_event.SetEventObject(this);
    wxPostEvent( Parent, bttn_event);
}
void LEDButton::mouseLeftWindow(wxMouseEvent& event)
{
    if (pressedDown)
    {
        pressedDown = false;
        Refresh();
    }
}

// currently unused events
void LEDButton::mouseMoved(wxMouseEvent& event) {}
void LEDButton::mouseWheelMoved(wxMouseEvent& event) {}
void LEDButton::rightClick(wxMouseEvent& event) {}
void LEDButton::keyPressed(wxKeyEvent& event) {
  event.Skip();
}
void LEDButton::keyReleased(wxKeyEvent& event) {
  event.Skip();
}

