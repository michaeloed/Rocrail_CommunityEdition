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
#ifndef __ROCRAIL_rocgui_BASE_H
#define __ROCRAIL_rocgui_BASE_H


#include "wx/wx.h"


class Base
{
public:
  static wxColor getWhite ();
  static wxColor getBlack ();
  static wxColor getRed   ();
  static wxColor getOrange();
  static wxColor getTurquoise();
  static wxColor getYellow();
  static wxColor getYellow2();
  static wxColor getGreen ();
  static wxColor getBlue  ();
  static wxColor getGrey  ();
  static wxColor getDarkGrey  ();
  static wxColor getNoneActiveColor();
  static wxColor getResColor();
  static wxColor getRes2Color();
};

#endif
