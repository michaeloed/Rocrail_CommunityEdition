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
#ifndef __locowidget__
#define __locowidget__

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#include "wx/event.h"
#endif

#include "locowidgetgen.h"
#include "rocs/public/node.h"

//// end generated include

/** Implementing LocoWidgetGen */
class LocoWidget : public LocoWidgetGen
{
  iONode m_Props;
  bool m_hasImageRequested;
  char m_Pixpath[256];
  wxBitmap scale(wxBitmap bmp, int max_width, int max_height);
  void InitLoco();

  void onMenuStart( wxCommandEvent& event );
  void onMenuStop( wxCommandEvent& event );
  void onMenuSoftReset( wxCommandEvent& event );
  void onMenuResetAll( wxCommandEvent& event );
  void onMenuSwap( wxCommandEvent& event );
  void onMenuSwapBlockSide( wxCommandEvent& event );
  void onMenuGoTo( wxCommandEvent& event );
  void onMenuSchedule( wxCommandEvent& event );
  void onMenuTour( wxCommandEvent& event );
  void onMenuProps( wxCommandEvent& event );

  void onThrottle( wxMouseEvent& event );
  void onPopUp( wxMouseEvent& event );
  void onStop( wxCommandEvent& event );
  void onImageLeftDown( wxMouseEvent& event );
  void onSpeedUp( wxMouseEvent& event );
  void onSpeedDown( wxMouseEvent& event );
  void onMouseWheel( wxMouseEvent& event );
  void onDirection( wxMouseEvent& event );
  void onDestination( wxMouseEvent& event );
  void onModeStart( wxMouseEvent& event );
  void onModeStop( wxMouseEvent& event );

public:
  /** Constructor */
  LocoWidget( wxWindow* parent, iONode props, int width );
  void UpdateLocoImg();
  void UpdateLoco(iONode props);
	//// end generated class members
	
};

#endif // __locowidget__
