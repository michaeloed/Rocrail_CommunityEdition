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
/** ------------------------------------------------------------
  * Module: rocgui/symbols
  * Object: renderer
  * ------------------------------------------------------------
  */
#ifndef _SYMBOL_RENDERER_H_
#define _SYMBOL_RENDERER_H_

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

/*!
 * Includes
 */
#include "rocs/public/node.h"
#include "rocs/public/map.h"

#include "svg.h"

class Symbol;

class SymbolRenderer {
  iONode m_Props;
  wxWindow* m_Parent;
  wxPoint* rotateShape( wxPoint* poly, int cnt, const char* oriStr );
  wxPoint* rotateBridge( double ori, double delta );
  wxPoint* rotateBridgeSensors( double ori, double delta );
  wxPoint* rotateBridgePlus( double ori, double delta );
  int m_cx;
  int m_cy;
  bool m_bShowID;
  bool m_bShowCounters;
  bool m_bRotateable;
  int m_iOccupied;
  bool m_bLabelChanged;
  const char* m_Ori;
  char* m_Label;
  double m_fText;
  double m_Scale;
  int m_iItemIDps;
  int m_iTextps;
  bool m_rotate;
  svgSymbol* m_SvgSym1; // straight, red
  svgSymbol* m_SvgSym2; // occupied, thrown, thrownleft, yellow
  svgSymbol* m_SvgSym3; // thrownright, green
  svgSymbol* m_SvgSym4; // thrownright, green
  svgSymbol* m_SvgSym5; // thrownright, green
  svgSymbol* m_SvgSym6; // thrownright, green
  svgSymbol* m_SvgSym7; // white
  svgSymbol* m_SvgSym8; // occupied white
  svgSymbol* m_SvgSym9 ; // route red (4 aspects)
  svgSymbol* m_SvgSym10; // route yellow (4 aspects)
  svgSymbol* m_SvgSym11; // route green (4 aspects)
  svgSymbol* m_SvgSym12; // route white (4 aspects)
  svgSymbol* m_SvgSym13;
  svgSymbol* m_SvgSym14;
  svgSymbol* m_SvgSym15;
  svgSymbol* m_SvgSym16;
  svgSymbol* m_SvgSym[32];
  svgSymbol* m_SvgSymOcc[32];
  svgSymbol* m_SvgSymRoute[32];

  int m_iSymType;
  int m_iSymSubType;
  iOMap m_SymMap;
  wxBitmap* m_Bitmap;
  wxGraphicsContext* m_GC;
  bool m_bAlt;
  bool m_bHasAlt;
  bool m_UseGC;
  wxPaintDC* m_DC;
  const char* m_LocoImage;
  bool m_bLocoPlacing;
  bool m_bLocoManual;


public:
  void initSym();
  SymbolRenderer( iONode props, wxWindow* parent, iOMap symmap, int itemidps, int textps, double scale=1.0 );
  void drawShape( wxPaintDC& dc, wxGraphicsContext* gc, bool occupied, bool actroute, double* bridgepos, bool showID, bool showCounters, const char* ori, int status=0, bool alt=false );
  void sizeToScale( double size, double scale, double bktext, int* cx, int* cy, const char* ori );
  void setLabel( const char* label, int occupied );
  void setLabel( const char* label, int occupied, bool rotate );
  void setLocoImage( const char* locoimage ) { m_LocoImage = locoimage;}
  void setLocoPlacing( bool locoplacing ) { m_bLocoPlacing = locoplacing;}
  void setLocoManual( bool locomanual ) { m_bLocoManual = locomanual;}
  int getcx() {return m_cx;}
  int getcy() {return m_cy;}
  bool isRotateable() { return m_bRotateable; }
  void drawString(const wxString& text, int x, int y, double degrees, bool setfont=true);
  void setPen(const wxPen& pen);
  void setBrush(const wxBrush& brush);
  void drawLine(int x, int y, int cx, int cy);
  wxFont* setFont(int pointsize=0, int red=0, int green=0, int blue=0, bool bold=false, bool italic=false, bool underlined=false);

  bool sizeSvgSym( const char* symname, const char* ori, int* cx, int* cy );
  void drawSvgSym( wxPaintDC& dc, int x, int y, const char* symname, const char* ori, int* cx, int* cy, bool draw=true );
  void drawSvgSym( wxPaintDC& dc, svgSymbol* svgsym, const char* ori, int xoff=0, int yoff=0, bool gridOffset=true );
  wxPen* getPen( const char* stroke );
  wxBrush* getBrush( const char* fill, wxPaintDC& dc );

  void drawTrack( wxPaintDC& dc, bool occupied, bool actroute, const char* ori );
  void drawSwitch( wxPaintDC& dc, bool occupied, bool actroute, const char* ori );
  void drawDecoupler( wxPaintDC& dc, bool occupied, bool actroute, const char* ori );
  void drawTurnout( wxPaintDC& dc, bool occupied, bool actroute, const char* ori );
  void drawCrossing( wxPaintDC& dc, bool occupied, bool actroute, const char* ori );
  void drawCCrossing( wxPaintDC& dc, bool occupied, bool actroute, const char* ori );
  void drawDCrossing( wxPaintDC& dc, bool occupied, bool actroute, const char* ori );
  void drawThreeway( wxPaintDC& dc, bool occupied, bool actroute, const char* ori );
  void drawSignal( wxPaintDC& dc, bool occupied, bool actroute, const char* ori );
  void drawOutput( wxPaintDC& dc, bool occupied, bool actroute, const char* ori );
  void drawSensor( wxPaintDC& dc, bool occupied, bool actroute, const char* ori );
  void drawRoute( wxPaintDC& dc, bool occupied, const char* ori, int status );
  void drawBlockTriangle( wxPaintDC& dc, const char* ori );
  void drawBlock( wxPaintDC& dc, bool occupied, const char* ori );
  void drawStage( wxPaintDC& dc, bool occupied, const char* ori );
  void drawSelTab( wxPaintDC& dc, bool occupied, const char* ori );
  void drawText( wxPaintDC& dc, bool occupied, const char* ori );
  void drawTurntable( wxPaintDC& dc, bool occupied, double* bridgepos, const char* ori );
  void drawAccessory( wxPaintDC& dc, bool occupied, bool actroute, const char* ori );
  double getRadians(double degrees);

  bool hasAlt() { return m_bHasAlt; }
  bool hasSVG(const char* svgname);

};

#endif


