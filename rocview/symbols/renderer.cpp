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

#include "renderer.h"
#include "sym.h"

#include "rocview/public/guiapp.h"
#include "rocview/public/base.h"

#include "rocrail/wrapper/public/Item.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/Stage.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/Route.h"
#include "rocrail/wrapper/public/Track.h"
#include "rocrail/wrapper/public/Turntable.h"
#include "rocrail/wrapper/public/TTTrack.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Text.h"
#include "rocrail/wrapper/public/SelTab.h"
#include "rocrail/wrapper/public/SelTabPos.h"
#include "rocrail/wrapper/public/DataReq.h"
#include "rocrail/wrapper/public/Program.h"
#include "rocrail/wrapper/public/Color.h"

#include "rocs/public/system.h"

#include "rocview/wrapper/public/Gui.h"
#include "rocview/wrapper/public/PlanPanel.h"

//#include "staticsymbols.h"


static double PI25DT = 3.141592653589793238462643;


SymbolRenderer::SymbolRenderer( iONode props, wxWindow* parent, iOMap symmap, int itemidps, int textps, double scale ) {
  m_Props = props;
  m_Parent = parent;
  m_SymMap = symmap;
  m_bRotateable = true;
  m_bShowID = false;
  m_bShowCounters = false;
  m_iOccupied = 0;
  m_Bitmap = NULL;
  m_Scale = scale;
  TraceOp.trc( "render", TRCLEVEL_DEBUG, __LINE__, 9999, "symbol map size = %d", symmap == NULL ? 0:MapOp.size(symmap) );
  if( m_Props != NULL )
    initSym();
  m_Label = StrOp.dup("-");
  m_iItemIDps = itemidps;
  m_iTextps = textps;
  m_DC = NULL;
  m_LocoImage = "";
  m_bLocoPlacing = true;
  m_bLocoManual = false;
}


bool SymbolRenderer::hasSVG(const char* svgname) {
  if( StrOp.equals( seltabtype::seltab, svgname) || StrOp.equals( turntabletype::turntable, svgname) ) {
    // internal symbols
    return true;
  }
  svgSymbol* SvgSym = (svgSymbol*)MapOp.get( m_SymMap, svgname );
  if( SvgSym != NULL )
    return true;
  return false;
}


/**
 * determine symbol type and subtype
 */
void SymbolRenderer::initSym() {
  m_SvgSym1  = NULL;
  m_SvgSym2  = NULL;
  m_SvgSym3  = NULL;
  m_SvgSym4  = NULL;
  m_SvgSym5  = NULL;
  m_SvgSym6  = NULL;
  m_SvgSym7  = NULL;
  m_SvgSym8  = NULL;
  m_SvgSym9  = NULL;
  m_SvgSym10 = NULL;
  m_SvgSym11 = NULL;
  m_SvgSym12 = NULL;
  m_SvgSym13 = NULL;
  m_SvgSym14 = NULL;
  m_SvgSym15 = NULL;
  m_SvgSym16 = NULL;


  // Aspect array
  for( int i = 0; i < 32; i++) {
    m_SvgSym[i] = NULL;
    m_SvgSymOcc[i] = NULL;
    m_SvgSymRoute[i] = NULL;
  }

  const char* nodeName = NodeOp.getName( m_Props );

  TraceOp.trc( "render", TRCLEVEL_DEBUG, __LINE__, 9999, "nodename=%s", nodeName );

  if( m_SymMap == NULL ) {
    TraceOp.trc( "render", TRCLEVEL_EXCEPTION, __LINE__, 9999, "Symbol map is not initialized." );
    return;
  }
  // TRACKS
  if( StrOp.equals( wTrack.name(), nodeName ) ) {
    m_iSymType = symtype::i_track;
    if( StrOp.equals( wTrack.curve, wTrack.gettype( m_Props ) ) ) {
      m_iSymSubType = tracktype::i_curve;
      if( m_SymMap != NULL ) {
        if( wItem.isroad( m_Props ) ) {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::road_curve );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::road_curve_occ );
        }
        else {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::curve );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::curve_occ );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::curve_route );
          m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::curve_occroute );
        }
      }
    }
    else if( StrOp.equals( wTrack.curve90, wTrack.gettype( m_Props ) ) ) {
      m_iSymSubType = tracktype::i_curve;
      if( m_SymMap != NULL ) {
        if( wItem.isroad( m_Props ) ) {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::road_curve_90 );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::road_curve_occ_90 );
        }
        else {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::curve );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::curve_occ );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::curve_route );
          m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::curve_occroute );
        }
      }
    }
    else if( StrOp.equals( wTrack.dcurve, wTrack.gettype( m_Props ) ) ) {
      m_iSymSubType = tracktype::i_curve;
      if( m_SymMap != NULL ) {
        if( wItem.isroad( m_Props ) ) {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::road_dcurve );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::road_dcurve_occ );
        }
        else {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::dcurve );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::dcurve_occ );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::dcurve_route );
          m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::dcurve_occroute );
        }
      }
    }
    else if( StrOp.equals( wTrack.buffer, wTrack.gettype( m_Props ) ) ) {
      m_iSymSubType = tracktype::i_buffer;
      if( m_SymMap != NULL ) {
        m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::buffer );
        m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::buffer_occ );
        m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::buffer_route );
      }
    }
    else if( StrOp.equals( wTrack.connector, wTrack.gettype( m_Props ) ) ) {
      m_iSymSubType = tracktype::i_connector;
      if( m_SymMap != NULL ) {
        m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::connector );
        m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::connector_occ );
        m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::connector_route );
      }
    }
    else if( StrOp.equals( wTrack.concurveright, wTrack.gettype( m_Props ) ) ) {
      m_iSymSubType = tracktype::i_connector;
      if( m_SymMap != NULL ) {
        m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::connector_curve_right );
        m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::connector_curve_right_occ );
        m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::connector_curve_right_route );
      }
    }
    else if( StrOp.equals( wTrack.concurveleft, wTrack.gettype( m_Props ) ) ) {
      m_iSymSubType = tracktype::i_connector;
      if( m_SymMap != NULL ) {
        m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::connector_curve_left );
        m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::connector_curve_left_occ );
        m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::connector_curve_left_route );
      }
    }
    else if( StrOp.equals( wTrack.dir, wTrack.gettype( m_Props ) ) ) {
      m_iSymSubType = tracktype::i_dir;
      if( m_SymMap != NULL ) {
        if( wItem.isroad( m_Props ) ) {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::road_dir );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::road_dir_occ );
        }
        else {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::dir );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::dir_occ );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::dir_route );
        }
      }
    }
    else if( StrOp.equals( wTrack.dirall, wTrack.gettype( m_Props ) ) ) {
      m_iSymSubType = tracktype::i_dirall;
      if( m_SymMap != NULL ) {
        if( wItem.isroad( m_Props ) ) {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::road_dirall );
        }
        else {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::dirall );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::dirall_occ );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::dirall_route );
        }
      }
    }
    else if( StrOp.equals( wTrack.tracknr, wTrack.gettype( m_Props ) ) ) {
      char key[256];
      m_iSymSubType = tracktype::i_tracknr;
      StrOp.fmtb( key, tracktype::tracknr, wTrack.gettknr( m_Props ) );
      m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, key );
      StrOp.fmtb( key, tracktype::tracknr_occ, wTrack.gettknr( m_Props ) );
      m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, key );
      StrOp.fmtb( key, tracktype::tracknr_route, wTrack.gettknr( m_Props ) );
      m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, key );
    }
    else if( StrOp.equals( wTrack.curvenr, wTrack.gettype( m_Props ) ) ) {
      char key[256];
      m_iSymSubType = tracktype::i_curvenr;
      StrOp.fmtb( key, tracktype::curvenr, wTrack.gettknr( m_Props ) );
      m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, key );
      StrOp.fmtb( key, tracktype::curvenr_occ, wTrack.gettknr( m_Props ) );
      m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, key );
      StrOp.fmtb( key, tracktype::curvenr_route, wTrack.gettknr( m_Props ) );
      m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, key );
    }
    else {
      m_iSymSubType = tracktype::i_straight;
      if( m_SymMap != NULL ) {
        if( wItem.isroad( m_Props ) ) {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::road_straight );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::road_straight_occ );
        }
        else {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::straight );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::straight_occ );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::straight_route );
          m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, tracktype::straight_occroute );
        }
      }
    }
  }

  // SWITCHES
  else if( StrOp.equals( wSwitch.name(), nodeName ) ) {
    Boolean raster = StrOp.equals( wSwitch.getswtype( m_Props ), wSwitch.swtype_raster );
    m_iSymType = symtype::i_switch;

    if( wSwitch.isvirtual( m_Props ) ) {
      m_iSymSubType = switchtype::i_turnoutleft;
      if( m_SymMap != NULL ) {
        m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::vturnout );
        m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::vturnout_t );
        m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::vturnout_t );
      }
    }
    else if( StrOp.equals( wSwitch.crossing, wSwitch.gettype( m_Props ) ) ) {
      m_iSymSubType = switchtype::i_crossing;
      if( m_SymMap != NULL ) {
        if( wItem.isroad( m_Props ) ) {
          if( wSwitch.isrectcrossing(m_Props) ) {
            m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_crossing90 );
            m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_crossing90_t );
            m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_crossing90_t );
          }
          else {
            m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_crossing );
            m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_crossing_t );
            m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_crossing_t );
          }
        }
        else {
          if( wSwitch.isrectcrossing(m_Props) ) {
            m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::crossing );
            m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::crossing_t );
            m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::crossing_occ );
            m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::crossing_t_occ );
            m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::crossing_route );
            m_SvgSym7 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::crossing_t_route );
            m_SvgSym8 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::crossing_route );
          }
          else if( wSwitch.getaddr1( m_Props ) == 0 && wSwitch.getport1( m_Props ) == 0 ) {
            if( raster ) {
              m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft_r_0m : switchtype::crossingright_r_0m );
              m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft_r_0m_occ : switchtype::crossingright_r_0m_occ );
            }
            else {
              m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft0m : switchtype::crossingright0m );
              m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft0m_occ : switchtype::crossingright0m_occ );
              m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft0m_route : switchtype::crossingright0m_route );
            }
            m_iSymSubType = wSwitch.isdir(m_Props) ? switchtype::i_crossingleft : switchtype::i_crossingright;
          }
          else if( raster ) {
            m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft_r:switchtype::crossingright_r );
            m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft_r_t:switchtype::crossingright_r_t );
            m_iSymSubType = wSwitch.isdir(m_Props) ? switchtype::i_crossingleft : switchtype::i_crossingright;
            m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft_r_occ:switchtype::crossingright_r_occ );
            m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft_r_t_occ:switchtype::crossingright_r_t_occ );
          }
          else {
            m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft : switchtype::crossingright );
            m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft_t : switchtype::crossingright_t );
            m_iSymSubType = wSwitch.isdir(m_Props) ? switchtype::i_crossingleft : switchtype::i_crossingright;
            m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft_occ : switchtype::crossingright_occ );
            m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft_t_occ : switchtype::crossingright_t_occ );
            m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft_route : switchtype::crossingright_route );
            m_SvgSym7 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft_t_route : switchtype::crossingright_t_route );
            m_SvgSym14 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft_l_occ : switchtype::crossingright_l_occ );
            m_SvgSym15 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft_t_l_occ : switchtype::crossingright_t_l_occ );
            m_SvgSym[16] = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft_b_route : switchtype::crossingright_b_route );
            m_SvgSym[17] = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft_t_b_route : switchtype::crossingright_t_b_route );
            m_SvgSym12 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft_l_route : switchtype::crossingright_l_route );
            m_SvgSym13 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft_t_l_route : switchtype::crossingright_t_l_route );
            m_SvgSym[18] = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft_lb_route : switchtype::crossingright_lb_route );
            m_SvgSym[19] = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::crossingleft_t_lb_route : switchtype::crossingright_t_lb_route );
          }
        }
      }
    }
    else if( StrOp.equals( wSwitch.ccrossing, wSwitch.gettype( m_Props ) ) ) {
      m_iSymSubType = switchtype::i_ccrossing;
      if( m_SymMap != NULL ) {
        if( wItem.isroad( m_Props ) ) {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_ccrossing );
        }
        else {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::ccrossing );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::ccrossing_occ );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::ccrossing_route );
        }
      }
    }
    else if( StrOp.equals( wSwitch.dcrossing, wSwitch.gettype( m_Props ) ) ) {
      m_iSymSubType = wSwitch.isdir(m_Props) ? switchtype::i_dcrossingleft:switchtype::i_dcrossingright;
      if( m_SymMap != NULL ) {
        if( wItem.isroad( m_Props ) ) {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_dcrossingright );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_dcrossingright_t );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_dcrossingright_tl );
          m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_dcrossingright_tr );
        }
        else if( raster ) {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_r:switchtype::dcrossingright_r );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_r_t:switchtype::dcrossingright_r_t );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_r_tl:switchtype::dcrossingright_r_tl );
          m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_r_tr:switchtype::dcrossingright_r_tr );
          m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_r_occ:switchtype::dcrossingright_r_occ );
          m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_r_t_occ:switchtype::dcrossingright_r_t_occ );
          m_SvgSym7 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_r_tl_occ:switchtype::dcrossingright_r_tl_occ );
          m_SvgSym8 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_r_tr_occ:switchtype::dcrossingright_r_tr_occ );
        }
        else {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft:switchtype::dcrossingright );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_t:switchtype::dcrossingright_t );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_tl:switchtype::dcrossingright_tl );
          m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_tr:switchtype::dcrossingright_tr );
          m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_occ:switchtype::dcrossingright_occ );
          m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_t_occ:switchtype::dcrossingright_t_occ );
          m_SvgSym7 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_tl_occ:switchtype::dcrossingright_tl_occ );
          m_SvgSym8 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_tr_occ:switchtype::dcrossingright_tr_occ );
          m_SvgSym9 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_route:switchtype::dcrossingright_route );
          m_SvgSym10 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_t_route:switchtype::dcrossingright_t_route );
          m_SvgSym11 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_tl_route:switchtype::dcrossingright_tl_route );
          m_SvgSym12 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_tr_route:switchtype::dcrossingright_tr_route );

          m_SvgSym13 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_l_occ:switchtype::dcrossingright_l_occ );
          m_SvgSym14 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_t_l_occ:switchtype::dcrossingright_t_l_occ );
          m_SvgSym15 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_tl_l_occ:switchtype::dcrossingright_tl_l_occ );
          m_SvgSym16 = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_tr_l_occ:switchtype::dcrossingright_tl_l_occ );
          m_SvgSym[17] = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_b_route:switchtype::dcrossingright_b_route );
          m_SvgSym[18] = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_l_route:switchtype::dcrossingright_l_route );
          m_SvgSym[19] = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_lb_route:switchtype::dcrossingright_lb_route );
          m_SvgSym[20] = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_t_b_route:switchtype::dcrossingright_t_b_route );
          m_SvgSym[21] = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_t_l_route:switchtype::dcrossingright_t_l_route );
          m_SvgSym[22] = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_t_lb_route:switchtype::dcrossingright_t_lb_route );
          m_SvgSym[23] = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_tl_b_route:switchtype::dcrossingright_tl_b_route );
          m_SvgSym[24] = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_tl_l_route:switchtype::dcrossingright_tl_l_route );
          m_SvgSym[25] = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_tl_lb_route:switchtype::dcrossingright_tl_lb_route );
          m_SvgSym[26] = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_tr_b_route:switchtype::dcrossingright_tr_b_route );
          m_SvgSym[27] = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_tr_l_route:switchtype::dcrossingright_tr_l_route );
          m_SvgSym[28] = (svgSymbol*)MapOp.get( m_SymMap, wSwitch.isdir(m_Props) ? switchtype::dcrossingleft_tr_lb_route:switchtype::dcrossingright_tr_lb_route );
        }
      }
    }
    else if( StrOp.equals( wSwitch.decoupler, wSwitch.gettype( m_Props ) ) ) {
      m_iSymSubType = switchtype::i_decoupler;
      if( m_SymMap != NULL ) {
        m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::decoupler );
        m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::decoupler_occ );
        m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::decoupler_on );
        m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::decoupler_on_occ );
        m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::decoupler_route );
        m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::decoupler_on_route );
        m_SvgSym7 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::decoupler_on_occ_route );
        m_SvgSym8 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::decoupler_occ_route );
      }
    }
    else if( StrOp.equals( wSwitch.threeway, wSwitch.gettype( m_Props ) ) ) {
      m_iSymSubType = switchtype::i_threeway;
      if( m_SymMap != NULL ) {
        if( wItem.isroad( m_Props ) ) {
          if( wSwitch.isrectcrossing(m_Props) ) {
            m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_rect_threeway );
            m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_rect_threeway_tl );
            m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_rect_threeway_tr );
          }
          else {
            m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_threeway );
            m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_threeway_tl );
            m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_threeway_tr );
          }
        }
        else if( raster ) {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::threeway_r );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::threeway_r_tl );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::threeway_r_tr );
          m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::threeway_r_occ );
          m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::threeway_r_tl_occ );
          m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::threeway_r_tr_occ );
        }
        else {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::threeway );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::threeway_tl );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::threeway_tr );
          m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::threeway_occ );
          m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::threeway_tl_occ );
          m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::threeway_tr_occ );
          m_SvgSym7 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::threeway_route );
          m_SvgSym8 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::threeway_tl_route );
          m_SvgSym9 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::threeway_tr_route );
        }
      }
    }
    else if( StrOp.equals( wSwitch.twoway, wSwitch.gettype( m_Props ) ) ) {
      m_iSymSubType = switchtype::i_twoway;
      if( m_SymMap != NULL ) {
        if( wItem.isroad( m_Props ) ) {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_twoway_tr );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_twoway_tl );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_twoway_tl );
        }
        else if( raster ) {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::twoway_r_tr );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::twoway_r_tl );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::twoway_r_tl );
          m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::twoway_r_tr_occ );
          m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::twoway_r_tl_occ );
        }
        else {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::twoway_tr );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::twoway_tl );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::twoway_tl );
          m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::twoway_tr_occ );
          m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::twoway_tl_occ );
          m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::twoway_tr_route );
          m_SvgSym7 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::twoway_tl_route );
        }
      }
    }
    else if( StrOp.equals( wSwitch.accessory, wSwitch.gettype( m_Props ) ) ) {
      m_iSymSubType = switchtype::i_accessory;
      if( m_SymMap != NULL ) {
        char key[256];
        StrOp.fmtb( key, switchtype::accessory_on, wSwitch.getaccnr( m_Props ) );
        m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, key );
        StrOp.fmtb( key, switchtype::accessory_off, wSwitch.getaccnr( m_Props ) );
        m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, key );
        StrOp.fmtb( key, switchtype::accessory_on_occ, wSwitch.getaccnr( m_Props ) );
        m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, key );
        StrOp.fmtb( key, switchtype::accessory_off_occ, wSwitch.getaccnr( m_Props ) );
        m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, key );
        StrOp.fmtb( key, switchtype::accessory_on_route, wSwitch.getaccnr( m_Props ) );
        m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, key );
        StrOp.fmtb( key, switchtype::accessory_off_route, wSwitch.getaccnr( m_Props ) );
        m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, key );
      }
    }
    else if( StrOp.equals( wSwitch.left, wSwitch.gettype( m_Props ) ) ) {
      // process raster flag
      m_iSymSubType = switchtype::i_turnoutleft;
      if( m_SymMap != NULL ) {
        if( raster ) {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_r );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_r_t );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_r_t );
          m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_r_occ );
          m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_r_t_occ );
          m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_r_route );
          m_SvgSym7 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_r_t_route );
          m_SvgSym11 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_r_b_route );
          m_SvgSym13 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_r_t_b_route );
          m_SvgSym14 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_r_l_occ );
          m_SvgSym15 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_r_t_l_occ );
          m_SvgSym16 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_r_l_route );
          m_SvgSym[17] = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_r_t_l_route );
          m_SvgSym[26] = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_r_lb_route );
          m_SvgSym[27] = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_r_t_lb_route );
        }
        else {
          if( wItem.isroad( m_Props ) ) {
            m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_turnoutleft );
            m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_turnoutleft_t );
            m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_turnoutleft_t );
          }
          else {
            if( wSwitch.getaccnr( m_Props ) > 1 ) {
              char key[256];
              StrOp.fmtb( key, switchtype::accessory_on, wSwitch.getaccnr( m_Props ) );
              m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, key );
              StrOp.fmtb( key, switchtype::accessory_off, wSwitch.getaccnr( m_Props ) );
              m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, key );
              StrOp.fmtb( key, switchtype::accessory_on_occ, wSwitch.getaccnr( m_Props ) );
              m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, key );
              StrOp.fmtb( key, switchtype::accessory_off_occ, wSwitch.getaccnr( m_Props ) );
              m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, key );
              StrOp.fmtb( key, switchtype::accessory_on_route, wSwitch.getaccnr( m_Props ) );
              m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, key );
              StrOp.fmtb( key, switchtype::accessory_off_route, wSwitch.getaccnr( m_Props ) );
              m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, key );
            }
            else {
              m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft );
              m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_t );
              m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_t );
              m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_occ );
              m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_t_occ );
              m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_route );
              m_SvgSym7 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_t_route );
              m_SvgSym11 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_b_route );
              m_SvgSym13 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_t_b_route );
              m_SvgSym14 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_l_occ );
              m_SvgSym15 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_t_l_occ );
              m_SvgSym16 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_l_route );
              m_SvgSym[17] = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_t_l_route );
              m_SvgSym[26] = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_lb_route );
              m_SvgSym[27] = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutleft_t_lb_route );
            }
          }
        }
      }
    }
    else {
      // process raster flag
      m_iSymSubType = switchtype::i_turnoutright;
      if( m_SymMap != NULL ) {
        if( raster ) {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_r );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_r_t );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_r_t );
          m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_r_occ );
          m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_r_t_occ );
          m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_r_route );
          m_SvgSym7 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_r_t_route );
          m_SvgSym11 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_r_b_route );
          m_SvgSym13 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_r_t_b_route );
          m_SvgSym14 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_r_l_occ );
          m_SvgSym15 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_r_t_l_occ );
          m_SvgSym16 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_r_l_route );
          m_SvgSym[17] = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_r_t_l_route );
          m_SvgSym[26] = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_r_lb_route );
          m_SvgSym[27] = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_r_t_lb_route );
        }
        else {
          if( wItem.isroad( m_Props ) ) {
            m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_turnoutright );
            m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_turnoutright_t );
            m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::road_turnoutright_t );
          }
          else {
            if( wSwitch.getaccnr( m_Props ) > 1 ) {
              char key[256];
              StrOp.fmtb( key, switchtype::accessory_on, wSwitch.getaccnr( m_Props ) );
              m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, key );
              StrOp.fmtb( key, switchtype::accessory_off, wSwitch.getaccnr( m_Props ) );
              m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, key );
              StrOp.fmtb( key, switchtype::accessory_on_occ, wSwitch.getaccnr( m_Props ) );
              m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, key );
              StrOp.fmtb( key, switchtype::accessory_off_occ, wSwitch.getaccnr( m_Props ) );
              m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, key );
              StrOp.fmtb( key, switchtype::accessory_on_route, wSwitch.getaccnr( m_Props ) );
              m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, key );
              StrOp.fmtb( key, switchtype::accessory_off_route, wSwitch.getaccnr( m_Props ) );
              m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, key );
            }
            else {
              m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright );
              m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_t );
              m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_t );
              m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_occ );
              m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_t_occ );
              m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_route );
              m_SvgSym7 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_t_route );
              m_SvgSym11 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_b_route );
              m_SvgSym13 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_t_b_route );
              m_SvgSym14 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_l_occ );
              m_SvgSym15 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_t_l_occ );
              m_SvgSym16 = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_l_route );
              m_SvgSym[17] = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_t_l_route );
              m_SvgSym[26] = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_lb_route );
              m_SvgSym[27] = (svgSymbol*)MapOp.get( m_SymMap, switchtype::turnoutright_t_lb_route );
            }
          }
        }
      }
    }
  }

  // SIGNALS
  else if( StrOp.equals( wSignal.name(), nodeName ) ) {
    int aspects = wSignal.getaspects( m_Props );
    Boolean dwarf = wSignal.isdwarf( m_Props );
    m_iSymType = symtype::i_signal;
    if( wSignal.getaspects( m_Props ) > 4 || wSignal.isusesymbolprefix( m_Props ) ) {
      m_iSymSubType = signaltype::i_signalaspect;
      if( m_SymMap != NULL ) {
        const char* prefix = wSignal.getsymbolprefix( m_Props );
        char key[256];
        for( int i = 0; i < wSignal.getaspects( m_Props ); i++ ) {
          StrOp.fmtb( key, signaltype::signalaspect, prefix, i );
          m_SvgSym[i] = (svgSymbol*)MapOp.get( m_SymMap, key );
          StrOp.fmtb( key, signaltype::signalaspect_occ, prefix, i );
          m_SvgSymOcc[i] = (svgSymbol*)MapOp.get( m_SymMap, key );
          StrOp.fmtb( key, signaltype::signalaspect_route, prefix, i );
          m_SvgSymRoute[i] = (svgSymbol*)MapOp.get( m_SymMap, key );
        }

      }
    }
    else if( StrOp.equals( wSignal.blockstate, wSignal.getsignal( m_Props ) ) ) {
      m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::blockstate );
    }
    else if( StrOp.equals( wSignal.semaphore, wSignal.gettype( m_Props ) ) ) {
      if( StrOp.equals( wSignal.main, wSignal.getsignal( m_Props ) ) ) {
        m_iSymSubType = signaltype::i_semaphoremain;
        if( m_SymMap != NULL ) {
          if( aspects == 2 ) {
            m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoremain_2_r );
            m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoremain_2_g );
            m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoremain_2_r_occ );
            m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoremain_2_g_occ );
            m_SvgSym9  = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoremain_2_r_route );
            m_SvgSym11 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoremain_2_g_route );
          }
          else {
            m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoremain_r );
            m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoremain_y );
            m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoremain_g );
            m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoremain_r_occ );
            m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoremain_y_occ );
            m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoremain_g_occ );
            m_SvgSym9  = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoremain_r_route );
            m_SvgSym10 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoremain_y_route );
            m_SvgSym11 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoremain_g_route );
            m_SvgSym7 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoremain_w );
            m_SvgSym8 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoremain_w_occ );
            m_SvgSym12 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoremain_w_route );
          }
        }
      }
      else if( StrOp.equals( wSignal.distant, wSignal.getsignal( m_Props ) ) ) {
        m_iSymSubType = signaltype::i_semaphoredistant;
        if( m_SymMap != NULL ) {
          if( aspects == 2 ) {
            m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoredistant_2_r );
            m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoredistant_2_g );
            m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoredistant_2_r_occ );
            m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoredistant_2_g_occ );
            m_SvgSym9  = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoredistant_2_r_route );
            m_SvgSym11 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoredistant_2_g_route );
          }
          else {
            m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoredistant_r );
            m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoredistant_y );
            m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoredistant_g );
            m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoredistant_r_occ );
            m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoredistant_y_occ );
            m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoredistant_g_occ );
            m_SvgSym9  = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoredistant_r_route );
            m_SvgSym10 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoredistant_y_route );
            m_SvgSym11 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoredistant_g_route );
            m_SvgSym7 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoredistant_w );
            m_SvgSym8 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoredistant_w_occ );
            m_SvgSym12 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoredistant_w_route );
          }
        }
      }
      else if( StrOp.equals( wSignal.shunting, wSignal.getsignal( m_Props ) ) ) {
        m_iSymSubType = signaltype::i_semaphoreshunting;
        if( m_SymMap != NULL ) {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoreshunting_2_r );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoreshunting_2_w );
          m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoreshunting_2_r_occ );
          m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoreshunting_2_w_occ );
          m_SvgSym9  = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoreshunting_2_r_route );
          m_SvgSym11 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::semaphoreshunting_2_w_route );
        }
      }
    }
    else if( StrOp.equals( wSignal.light, wSignal.gettype( m_Props ) ) ) {
      if( StrOp.equals( wSignal.main, wSignal.getsignal( m_Props ) ) ) {
        m_iSymSubType = signaltype::i_signalmain;
        if( m_SymMap != NULL ) {
          if( aspects == 2 && !wItem.isroad( m_Props ) ) {
            m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signalmain_2_r );
            m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signalmain_2_g );
            m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signalmain_2_r_occ );
            m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signalmain_2_g_occ );
            m_SvgSym9  = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signalmain_2_r_route );
            m_SvgSym11 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signalmain_2_g_route );
          }
          else {
            if( wItem.isroad( m_Props ) ) {
              m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, dwarf?signaltype::road_signalmain_dwarf_r:signaltype::road_signalmain_r );
              m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, dwarf?signaltype::road_signalmain_dwarf_y:signaltype::road_signalmain_y );
              m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, dwarf?signaltype::road_signalmain_dwarf_g:signaltype::road_signalmain_g );
            }
            else {
              m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, dwarf?signaltype::signalmain_dwarf_r:signaltype::signalmain_r );
              m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, dwarf?signaltype::signalmain_dwarf_y:signaltype::signalmain_y );
              m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, dwarf?signaltype::signalmain_dwarf_g:signaltype::signalmain_g );
              m_SvgSym7 = (svgSymbol*)MapOp.get( m_SymMap, dwarf?signaltype::signalmain_dwarf_w:signaltype::signalmain_w );
              m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, dwarf?signaltype::signalmain_dwarf_r_occ:signaltype::signalmain_r_occ );
              m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, dwarf?signaltype::signalmain_dwarf_y_occ:signaltype::signalmain_y_occ );
              m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, dwarf?signaltype::signalmain_dwarf_g_occ:signaltype::signalmain_g_occ );
              m_SvgSym8 = (svgSymbol*)MapOp.get( m_SymMap, dwarf?signaltype::signalmain_dwarf_w_occ:signaltype::signalmain_w_occ );
              m_SvgSym9  = (svgSymbol*)MapOp.get( m_SymMap, dwarf?signaltype::signalmain_dwarf_r_route:signaltype::signalmain_r_route );
              m_SvgSym10 = (svgSymbol*)MapOp.get( m_SymMap, dwarf?signaltype::signalmain_dwarf_y_route:signaltype::signalmain_y_route );
              m_SvgSym11 = (svgSymbol*)MapOp.get( m_SymMap, dwarf?signaltype::signalmain_dwarf_g_route:signaltype::signalmain_g_route );
              m_SvgSym12 = (svgSymbol*)MapOp.get( m_SymMap, dwarf?signaltype::signalmain_dwarf_w_route:signaltype::signalmain_w_route );
              m_SvgSym13 = (svgSymbol*)MapOp.get( m_SymMap, dwarf?signaltype::signalmain_dwarf_w:signaltype::signalmain_b );
              m_SvgSym14 = (svgSymbol*)MapOp.get( m_SymMap, dwarf?signaltype::signalmain_dwarf_w_occ:signaltype::signalmain_b_occ );
              m_SvgSym15 = (svgSymbol*)MapOp.get( m_SymMap, dwarf?signaltype::signalmain_dwarf_w_route:signaltype::signalmain_b_route );
            }
          }
        }
      }
      else if( StrOp.equals( wSignal.distant, wSignal.getsignal( m_Props ) ) ) {
        m_iSymSubType = signaltype::i_signaldistant;
        if( m_SymMap != NULL ) {
          if( aspects == 2 ) {
            m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_2_r );
            m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_2_g );
            m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_2_r_occ );
            m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_2_g_occ );
            m_SvgSym9  = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_2_r_route );
            m_SvgSym11 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_2_g_route );
          }
          else {
            m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_r );
            m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_y );
            m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_g );
            m_SvgSym7 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_w );
            m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_r_occ );
            m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_y_occ );
            m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_g_occ );
            m_SvgSym8 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_w_occ );
            m_SvgSym9  = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_r_route );
            m_SvgSym10 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_y_route );
            m_SvgSym11 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_g_route );
            m_SvgSym12 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_w_route );
            m_SvgSym13 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_b );
            m_SvgSym14 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_b_occ );
            m_SvgSym15 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signaldistant_b_route );
          }
        }
      }
      else if( StrOp.equals( wSignal.shunting, wSignal.getsignal( m_Props ) ) ) {
        m_iSymSubType = signaltype::i_signalshunting;
        if( m_SymMap != NULL ) {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signalshunting_2_r );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signalshunting_2_w );
          m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signalshunting_2_r_occ );
          m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signalshunting_2_w_occ );
          m_SvgSym9  = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signalshunting_2_r_route );
          m_SvgSym11 = (svgSymbol*)MapOp.get( m_SymMap, signaltype::signalshunting_2_w_route );
        }
      }
    }
  }
  else if( StrOp.equals( wOutput.name(), nodeName ) ) {
    m_iSymType = symtype::i_output;
    m_iSymSubType = outputtype::i_button;
    if( m_SymMap != NULL ) {
      char key[256];
      StrOp.fmtb( key, outputtype::button_off, wOutput.getsvgtype( m_Props ) );
      m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, key );
      StrOp.fmtb( key, outputtype::button_on, wOutput.getsvgtype( m_Props ) );
      m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, key );
      StrOp.fmtb( key, outputtype::button_active, wOutput.getsvgtype( m_Props ) );
      m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, key );

      StrOp.fmtb( key, outputtype::button_off_occ, wOutput.getsvgtype( m_Props ) );
      m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, key );
      StrOp.fmtb( key, outputtype::button_on_occ, wOutput.getsvgtype( m_Props ) );
      m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, key );
      StrOp.fmtb( key, outputtype::button_active_occ, wOutput.getsvgtype( m_Props ) );
      m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, key );

      StrOp.fmtb( key, outputtype::button_off_route, wOutput.getsvgtype( m_Props ) );
      m_SvgSym7 = (svgSymbol*)MapOp.get( m_SymMap, key );
      StrOp.fmtb( key, outputtype::button_on_route, wOutput.getsvgtype( m_Props ) );
      m_SvgSym8 = (svgSymbol*)MapOp.get( m_SymMap, key );
      StrOp.fmtb( key, outputtype::button_active_route, wOutput.getsvgtype( m_Props ) );
      m_SvgSym9 = (svgSymbol*)MapOp.get( m_SymMap, key );
    }
  }
  else if( StrOp.equals( wBlock.name(), nodeName ) ) {
    m_iSymType = symtype::i_block;
    m_iSymSubType = blocktype::i_block;
    if( m_SymMap != NULL ) {
      if( wItem.isroad( m_Props ) ) {
        m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, blocktype::road_block );
        m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, blocktype::road_block_occ );
        m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, blocktype::road_block_res );
        m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, blocktype::road_block_ent );
        m_SvgSym7  = (svgSymbol*)MapOp.get( m_SymMap, blocktype::road_block_s );
        m_SvgSym8  = (svgSymbol*)MapOp.get( m_SymMap, blocktype::road_block_occ_s );
        m_SvgSym9  = (svgSymbol*)MapOp.get( m_SymMap, blocktype::road_block_res_s );
        m_SvgSym10 = (svgSymbol*)MapOp.get( m_SymMap, blocktype::road_block_ent_s );
      }
      else {
        m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, blocktype::block );
        m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, blocktype::block_occ );
        m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, blocktype::block_res );
        m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, blocktype::block_ent );
        m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, blocktype::block_closed );
        m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, blocktype::block_ghost );
        m_SvgSym13 = (svgSymbol*)MapOp.get( m_SymMap, blocktype::block_sc );
        m_SvgSym15 = (svgSymbol*)MapOp.get( m_SymMap, blocktype::block_aident );

        m_SvgSym7  = (svgSymbol*)MapOp.get( m_SymMap, blocktype::block_s );
        m_SvgSym8  = (svgSymbol*)MapOp.get( m_SymMap, blocktype::block_occ_s );
        m_SvgSym9  = (svgSymbol*)MapOp.get( m_SymMap, blocktype::block_res_s );
        m_SvgSym10 = (svgSymbol*)MapOp.get( m_SymMap, blocktype::block_ent_s );
        m_SvgSym11 = (svgSymbol*)MapOp.get( m_SymMap, blocktype::block_closed_s );
        m_SvgSym12 = (svgSymbol*)MapOp.get( m_SymMap, blocktype::block_ghost_s );
        m_SvgSym14 = (svgSymbol*)MapOp.get( m_SymMap, blocktype::block_sc_s );
        m_SvgSym16 = (svgSymbol*)MapOp.get( m_SymMap, blocktype::block_aident_s );
      }
    }
  }
  else if( StrOp.equals( wStage.name(), nodeName ) ) {
    m_iSymType = symtype::i_stage;
    m_iSymSubType = stagetype::i_stage;
    if( m_SymMap != NULL ) {
      m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, stagetype::stage );
      m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, stagetype::stage_occ );
      m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, stagetype::stage_res );
      m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, stagetype::stage_ent );
      m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, stagetype::stage_closed );
      m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, stagetype::stage_ghost );
    }
  }
  else if( StrOp.equals( wSelTab.name(), nodeName ) ) {
    m_iSymType = symtype::i_selecttable;
    m_iSymSubType = seltabtype::i_seltab;
    if( m_SymMap != NULL ) {
      m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, seltabtype::seltab );
      m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, seltabtype::seltab_occ );
      m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, seltabtype::seltab_res );
    }
  }
  else if( StrOp.equals( wText.name(), nodeName ) ) {
    m_iSymType = symtype::i_text;
    m_iSymSubType = texttype::i_text;
  }
  else if( StrOp.equals( wFeedback.name(), nodeName ) ) {
    m_iSymType = symtype::i_feedback;
    m_iSymSubType = feedbacktype::i_sensor;
    if( m_SymMap != NULL ) {
      if( wItem.isroad( m_Props ) ) {
        m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, feedbacktype::road_sensor_off );
        m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, feedbacktype::road_sensor_on );
        m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, feedbacktype::road_sensor_off_occ );
        m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, feedbacktype::road_sensor_on_occ );
      }
      else {
        if( wFeedback.getaccnr(m_Props) > 0 ) {
          char key[256];
          StrOp.fmtb( key, feedbacktype::accessory_off, wFeedback.getaccnr( m_Props ) );
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, key );
          StrOp.fmtb( key, feedbacktype::accessory_on, wFeedback.getaccnr( m_Props ) );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, key );
          StrOp.fmtb( key, feedbacktype::accessory_off_occ, wFeedback.getaccnr( m_Props ) );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, key );
          StrOp.fmtb( key, feedbacktype::accessory_on_occ, wFeedback.getaccnr( m_Props ) );
          m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, key );
          StrOp.fmtb( key, feedbacktype::accessory_off_route, wFeedback.getaccnr( m_Props ) );
          m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, key );
          StrOp.fmtb( key, feedbacktype::accessory_on_route, wFeedback.getaccnr( m_Props ) );
          m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, key );
          m_iSymSubType = feedbacktype::i_accessory;
        }
        else if( wFeedback.iscurve(m_Props) ) {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, feedbacktype::curve_sensor_off );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, feedbacktype::curve_sensor_on );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, feedbacktype::curve_sensor_off_occ );
          m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, feedbacktype::curve_sensor_on_occ );
          m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, feedbacktype::curve_sensor_off_route );
          m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, feedbacktype::curve_sensor_on_route );
          m_SvgSym7 = (svgSymbol*)MapOp.get( m_SymMap, feedbacktype::curve_sensor_cnt );
        }
        else {
          m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, feedbacktype::sensor_off );
          m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, feedbacktype::sensor_on );
          m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, feedbacktype::sensor_off_occ );
          m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, feedbacktype::sensor_on_occ );
          m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, feedbacktype::sensor_off_route );
          m_SvgSym6 = (svgSymbol*)MapOp.get( m_SymMap, feedbacktype::sensor_on_route );
          m_SvgSym7 = (svgSymbol*)MapOp.get( m_SymMap, feedbacktype::sensor_cnt );
        }
      }
    }
  }
  else if( StrOp.equals( wRoute.name(), nodeName ) ) {
    m_iSymType = symtype::i_route;
    m_iSymSubType = routetype::i_route;
    if( m_SymMap != NULL ) {
      m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, routetype::route_free );
      m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, routetype::route_locked );
      m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, routetype::route_selected );
      m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, routetype::route_deselected );
      m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, routetype::route_closed );
    }
  }
  else if( StrOp.equals( wTurntable.name(), nodeName ) ) {
    m_iSymType = symtype::i_turntable;
    m_iSymSubType = 0;
    m_SvgSym1 = (svgSymbol*)MapOp.get( m_SymMap, traversertype::traverser );
    m_SvgSym2 = (svgSymbol*)MapOp.get( m_SymMap, traversertype::traverser_bridge );
    m_SvgSym3 = (svgSymbol*)MapOp.get( m_SymMap, traversertype::traverser_bridge_occ );
    m_SvgSym4 = (svgSymbol*)MapOp.get( m_SymMap, traversertype::traverser_bridge_res );
    m_SvgSym5 = (svgSymbol*)MapOp.get( m_SymMap, traversertype::traverser_bridge_ent );
  }
  else if( StrOp.equals( wSelTab.name(), nodeName ) ) {
    m_iSymType = symtype::i_selecttable;
    m_iSymSubType = 0;
  }
  else if( StrOp.equals( wSelTab.name(), nodeName ) ) {
    m_iSymType = symtype::i_selecttable;
    m_iSymSubType = 0;
  }

}



void SymbolRenderer::setLabel( const char* label, int occupied ) {
  StrOp.free(m_Label);
  m_Label = StrOp.dup(label);
  m_iOccupied = occupied;
  m_bLabelChanged = true;
}

void SymbolRenderer::setLabel( const char* label, int occupied, bool rotate ) {
  StrOp.free(m_Label);
  m_Label = StrOp.dup(label);
  m_iOccupied = occupied == -1 ? m_iOccupied:occupied;
  m_bLabelChanged = true;
  m_rotate = rotate;
}


/**
 * prepare symbol size
 */
void SymbolRenderer::sizeToScale( double symsize, double scale, double bktext, int* cx, int* cy, const char* ori ) {
  *cx = 1;
  *cy = 1;
  m_fText = bktext;
  m_Scale = scale;

  if( StrOp.equals( wBlock.name(), NodeOp.getName( m_Props ) ) ) {

    if( StrOp.equals( ori, wItem.north ) || StrOp.equals( ori, wItem.south ) ) {
      // vertical
      *cx = 1;
      *cy = wBlock.issmallsymbol(m_Props) ? 2:4;
    }
    else { // horizontal
      *cx = wBlock.issmallsymbol(m_Props) ? 2:4;
      *cy = 1;
    }
    /*
      wxFont* font = new wxFont( m_BlockLabel->GetFont() );
      font->SetPointSize( (int)(font->GetPointSize() * scale * bktext ) );
    }
    */
  }
  else if( StrOp.equals( wSelTab.name(), NodeOp.getName( m_Props ) ) ) {

    if( StrOp.equals( ori, wItem.north ) || StrOp.equals( ori, wItem.south ) ) {
      // vertical
      *cx = 1;
      *cy = wSelTab.getnrtracks(m_Props);
      if( *cy > 32 )
        *cy = 32;
    }
    else { // horizontal
      *cx = wSelTab.getnrtracks(m_Props);
      *cy = 1;
      if( *cx > 32 )
        *cx = 32;
    }
    /*
      wxFont* font = new wxFont( m_BlockLabel->GetFont() );
      font->SetPointSize( (int)(font->GetPointSize() * scale * bktext ) );
    }
    */
  }
  else if( StrOp.equals( wTurntable.name(), NodeOp.getName( m_Props ) ) && !wTurntable.istraverser(m_Props) ) {
    int ttdiam = wTurntable.getsymbolsize( m_Props );

    if (ttdiam < 1)
      ttdiam = 1;

    if (ttdiam > 13)
      ttdiam = 13;

    *cx = ttdiam;
    *cy = ttdiam;
  }
  else if( StrOp.equals( wSwitch.name(), NodeOp.getName( m_Props ) ) &&
           StrOp.equals( wSwitch.dcrossing, wSwitch.gettype( m_Props ) ) ) {
    *cx = 2;
    *cy = 1;
  }
  else if( StrOp.equals( wText.name(), NodeOp.getName( m_Props ) ) ) {
    if( StrOp.equals( ori, wItem.north ) || StrOp.equals( ori, wItem.south ) ) {
      // vertical
      *cx = wText.getcy( m_Props );
      *cy = wText.getcx( m_Props );
    }
    else { // horizontal
    *cx = wText.getcx( m_Props );
    *cy = wText.getcy( m_Props );
    }
    setLabel( wText.gettext( m_Props ), false );
  }

  // use svg size

  if( StrOp.equals( wBlock.name(), NodeOp.getName( m_Props ) ) && wBlock.issmallsymbol(m_Props) && m_SvgSym7 != NULL ) {
    if( StrOp.equals( ori, wItem.north ) || StrOp.equals( ori, wItem.south ) ) {
      *cy = m_SvgSym7->width  / 32;
      *cx = m_SvgSym7->height / 32;
    }
    else {
      *cx = m_SvgSym7->width  / 32;
      *cy = m_SvgSym7->height / 32;
    }
  }
  else if( StrOp.equals( wTurntable.name(), NodeOp.getName( m_Props ) ) ) {
    if( wTurntable.istraverser(m_Props ) && m_SvgSym1 != NULL ) {
      if( StrOp.equals( ori, wItem.north ) || StrOp.equals( ori, wItem.south ) ) {
        *cy = m_SvgSym1->width  / 32;
        *cx = m_SvgSym1->height / 32;
      }
      else {
        *cx = m_SvgSym1->width  / 32;
        *cy = m_SvgSym1->height / 32;
      }
    }
  }
  else if( m_SvgSym1 != NULL ) {
    if( StrOp.equals( ori, wItem.north ) || StrOp.equals( ori, wItem.south ) ) {
      *cy = m_SvgSym1->width  / 32;
      *cx = m_SvgSym1->height / 32;
    }
    else {
      *cx = m_SvgSym1->width  / 32;
      *cy = m_SvgSym1->height / 32;
    }
  }

  m_cx = *cx;
  m_cy = *cy;
}


wxPen* SymbolRenderer::getPen( const char* stroke ) {
  if( stroke == NULL )
    return new wxPen(_T("black"));
  else
    return new wxPen(wxString(stroke,wxConvUTF8), 1, wxSOLID);
}

wxBrush* SymbolRenderer::getBrush( const char* fill, wxPaintDC& dc ) {
  if( fill == NULL || StrOp.equalsi( "none", fill ) )
    return new wxBrush(dc.GetBrush());
  else
    return new wxBrush(wxString(fill,wxConvUTF8), wxSOLID);
}


bool SymbolRenderer::sizeSvgSym( const char* symname, const char* ori, int* cx, int* cy ) {
  svgSymbol* svgsym = (svgSymbol*)MapOp.get( m_SymMap, symname );
  if( svgsym != NULL ) {
    *cx = svgsym->width  / 32;
    *cy = svgsym->height / 32;
    return true;
  }

  if( StrOp.equals( seltabtype::seltab, symname) || StrOp.equals( "text", symname) ) {
    *cx = 4;
    *cy = 1;
    return true;
  }

  if( StrOp.equals( turntabletype::turntable, symname) ) {
    *cx = 4;
    *cy = 4;
    return true;
  }

  return false;
}


void SymbolRenderer::drawSvgSym( wxPaintDC& dc, int x, int y, const char* symname, const char* ori, int* cx, int* cy, bool draw ) {
  m_GC = NULL;
  m_UseGC = false;
  m_DC = &dc;
  m_bAlt = false;
  svgSymbol* svgsym = (svgSymbol*)MapOp.get( m_SymMap, symname );
  if( svgsym != NULL ) {
    if( draw ) {
      drawSvgSym(dc, svgsym, ori, x, y, false);
    }
    *cx = svgsym->width  / 32;
    *cy = svgsym->height / 32;
  }
  else {
    if( StrOp.equals( seltabtype::seltab, symname) ) {
      if( draw ) {
        m_Props = NodeOp.inst( wSelTab.name(), NULL, ELEMENT_NODE );
        wSelTab.setnrtracks(m_Props, 4);
        drawSelTab( dc, false, ori );
        NodeOp.base.del(m_Props);
        m_Props = NULL;
      }
      *cx = 4;
      *cy = 1;
    }
    else if( StrOp.equals( turntabletype::turntable, symname) ) {
      if( draw ) {
        m_Props = NodeOp.inst( wTurntable.name(), NULL, ELEMENT_NODE );
        wTurntable.setsymbolsize( m_Props, 4 );
        double bridgepos = 0.0;
        drawTurntable( dc, false, &bridgepos, ori );
        NodeOp.base.del(m_Props);
        m_Props = NULL;
      }
      *cx = 4;
      *cy = 4;
    }
    else if( StrOp.equals( "text", symname) ) {
      if( draw ) {
        m_Props = NodeOp.inst( wText.name(), NULL, ELEMENT_NODE );
        //wText.setpointsize( m_Props, 13 );
        StrOp.free(m_Label);
        m_Label = StrOp.dup("Text");
        drawText( dc, false, ori );
        NodeOp.base.del(m_Props);
        m_Props = NULL;
      }
      *cx = 4;
      *cy = 1;
    }
    else
      TraceOp.trc( "render", TRCLEVEL_WARNING, __LINE__, 9999, "symbol [%s] is not in the map...", symname );
  }
}

void SymbolRenderer::drawSvgSym( wxPaintDC& dc, svgSymbol* svgsym, const char* ori, int xOff, int yOff, bool gridOffset ) {
  const wxBrush& b = dc.GetBrush();

  int xOffset = 0;
  int yOffset = 0;

  if( StrOp.equals( wItem.north, ori ) && m_cy > 1) {
    yOffset = 32 * (m_cy-1);
  }
  if( StrOp.equals( wItem.east, ori ) && m_cx > 1) {
    xOffset = 32 * (m_cx-1);
  }
  if( StrOp.equals( wItem.east, ori ) && m_cy > 1) {
    yOffset = 32 * (m_cy-1);
  }
  if( StrOp.equals( wItem.south, ori ) && m_cx > 1) {
    xOffset = 32 * (m_cx-1);
  }

  if( gridOffset ) {
    xOffset += xOff * 32;
    yOffset += yOff * 32;
  }
  else {
    xOffset += xOff;
    yOffset += yOff;
  }

  iOList polyList   = svgsym->polyList;
  iOList circleList = svgsym->circleList;
  if( m_bAlt && svgsym->polyListAlt != NULL )
    polyList = svgsym->polyListAlt;
  if( m_bAlt && svgsym->circleListAlt != NULL )
    circleList = svgsym->circleListAlt;

  if( svgsym->polyListAlt != NULL || svgsym->circleListAlt != NULL )
    m_bHasAlt = true;
  else
    m_bHasAlt = false;


  int cnt = ListOp.size( polyList );
  for( int i = 0; i < cnt; i++ ) {
    svgPoly* svgpoly = (svgPoly*)ListOp.get(polyList, i);
    wxPen* pen = getPen(svgpoly->stroke);
    pen->SetWidth(atoi(svgpoly->stroke_width));
    wxBrush* brush = getBrush(svgpoly->fill, dc );
    setPen( *pen );
    setBrush( *brush );
    if( svgpoly->arc ) {
      wxPoint* points = rotateShape( svgpoly->poly, svgpoly->cnt, ori );
      if( m_UseGC ) {
        TraceOp.trc( "render", TRCLEVEL_INFO, __LINE__, 9999, "TODO: Find a way to draw arcs in GC." );
      }
      else {
        dc.DrawArc( points[0].x, points[0].y, points[1].x, points[1].y, points[2].x, points[2].y );
      }
    }
    else {
      wxPoint* p = rotateShape( svgpoly->poly, svgpoly->cnt, ori );
      if( m_UseGC ) {
        wxGraphicsPath path = m_GC->CreatePath();
        path.MoveToPoint(p[0].x+xOffset, p[0].y+yOffset);
        for( int s = 1; s < svgpoly->cnt; s++ )
          path.AddLineToPoint(p[s].x+xOffset, p[s].y+yOffset);
        path.AddLineToPoint(p[0].x+xOffset, p[0].y+yOffset);
        m_GC->FillPath(path);
        m_GC->StrokePath(path);
      }
      else {
        dc.DrawPolygon( svgpoly->cnt, p, xOffset, yOffset );
      }
    }
    delete pen;
    delete brush;
  }

  if( circleList != NULL ) {
    cnt = ListOp.size( circleList );
    for( int i = 0; i < cnt; i++ ) {
      svgCircle* svgcircle = (svgCircle*)ListOp.get(circleList, i);
      wxPen* pen = getPen(svgcircle->stroke);
      pen->SetWidth(atoi(svgcircle->stroke_width));
      wxBrush* brush = getBrush(svgcircle->fill, dc );
      wxPoint point = wxPoint(svgcircle->cx, svgcircle->cy);
      wxPoint* points = rotateShape( &point, 1, ori );
      setPen( *pen );
      setBrush( *brush );
      if( m_UseGC ) {
        m_GC->DrawEllipse(points[0].x-svgcircle->r + xOffset, points[0].y-svgcircle->r + yOffset, svgcircle->r*2, svgcircle->r*2);
      }
      else {
        dc.DrawCircle( points[0].x + xOffset, points[0].y + yOffset, svgcircle->r );
      }
      delete pen;
      delete brush;
    }
  }

}


wxFont* SymbolRenderer::setFont(int pointsize, int red, int green, int blue, bool bold, bool italic, bool underlined)
{
  wxFont* font = new wxFont( m_DC->GetFont() );
  font->SetPointSize( pointsize > 0 ? pointsize:m_iItemIDps );

  if( bold )
    font->SetWeight(wxFONTWEIGHT_BOLD);
  if( italic )
    font->SetStyle(wxFONTSTYLE_ITALIC);

  font->SetUnderlined( underlined ? true:false);

  if( m_UseGC ) {
    m_GC->SetFont(*font, wxColour(red,green,blue));
  }
  else {
    m_DC->SetTextForeground(wxColour(red,green,blue));
    m_DC->SetFont(*font);
  }
  return font;
}

void SymbolRenderer::drawString(const wxString& text, int x, int y, double degrees, bool setfont)
{
  wxFont* font = NULL;
  if( setfont )
    font = setFont();

  if( m_UseGC ) {
    if( degrees > 0.0 )
      m_GC->DrawText( text, x, y, getRadians(degrees) );
    else
      m_GC->DrawText( text, x, y );
  }
  else {
    m_DC->DrawRotatedText( text, x, y, degrees );
  }

  if( setfont )
    delete font;
}

/**
 * Track object
 */
void SymbolRenderer::drawTrack( wxPaintDC& dc, bool occupied, bool actroute, const char* ori ) {
  // SVG Symbol:
  if( actroute && occupied && m_SvgSym4!=NULL ) {
    drawSvgSym(dc, m_SvgSym4, ori);
  }
  else if( occupied && m_SvgSym2!=NULL ) {
    drawSvgSym(dc, m_SvgSym2, ori);
  }
  else if( actroute && m_SvgSym3!=NULL ) {
    drawSvgSym(dc, m_SvgSym3, ori);
  }
  else if( actroute && m_SvgSym2!=NULL ) {
    drawSvgSym(dc, m_SvgSym2, ori);
  }
  else if( m_SvgSym1!=NULL ) {
    drawSvgSym(dc, m_SvgSym1, ori);
  }

  if( m_bShowID ) {
    if( StrOp.equals( wTrack.connector, wTrack.gettype( m_Props ) ) ) {

      if( StrOp.equals( ori, wItem.north ) ) {
        drawString(wxString::Format(_T("%d"),wTrack.gettknr(m_Props)), 10, 10, 270.0);
      }
      else if( StrOp.equals( ori, wItem.south ) ) {
        drawString(wxString::Format(_T("%d"),wTrack.gettknr(m_Props)), 20, 20, 90.0);
      }
      else if( StrOp.equals( ori, wItem.east ) ) {
        drawString(wxString::Format(_T("%d"),wTrack.gettknr(m_Props)), 10, 20, 0.0);
      }
      else
        drawString(wxString::Format(_T("%d"),wTrack.gettknr(m_Props)), 1, 1, 0.0);

    }

    else if( StrOp.equals( wTrack.concurveright, wTrack.gettype( m_Props ) ) || StrOp.equals( wTrack.concurveleft,  wTrack.gettype( m_Props ) ) ) {
      drawString( wxString::Format(_T("%d"),wTrack.gettknr(m_Props)), 10, 10, 0.0 );
    }
  }
}


void SymbolRenderer::drawCCrossing( wxPaintDC& dc, bool occupied, bool actroute, const char* ori ) {
  const char* state = wSwitch.getstate( m_Props );
  Boolean hasUnit = wSwitch.getaddr1( m_Props ) > 0 ? True:False;

  if( wSwitch.getaddr1( m_Props ) > 0 || wSwitch.getport1( m_Props ) > 0 )
    hasUnit = True;

  // SVG Symbol:
  if( occupied && m_SvgSym2 != NULL )
    drawSvgSym(dc, m_SvgSym2, ori);
  else if( actroute && m_SvgSym3 != NULL )
    drawSvgSym(dc, m_SvgSym3, ori);
  else if( m_SvgSym1 != NULL )
    drawSvgSym(dc, m_SvgSym1, ori);
}


/**
 * Crossing Switch object
 */
void SymbolRenderer::drawCrossing( wxPaintDC& dc, bool occupied, bool actroute, const char* ori ) {
  const char* state = wSwitch.getstate( m_Props );
  const char* savepos = wSwitch.getsavepos( m_Props );
  Boolean islocked = (wSwitch.getlocid( m_Props )==NULL)?False:True;
  Boolean isset = wSwitch.isset( m_Props );
  Boolean issavepos = (Boolean)( !StrOp.equals( savepos, wSwitch.none ) && !StrOp.equals( state, savepos ) );
  Boolean raster = StrOp.equals( wSwitch.getswtype( m_Props ), wSwitch.swtype_raster );

  TraceOp.trc( "render", TRCLEVEL_INFO, __LINE__, 9999, "Crossing %s occ=%d route=%d",
      wSwitch.getid( m_Props ), occupied, actroute );

  if( wSwitch.getlocid( m_Props )!=NULL && StrOp.equals( wSwitch.unlocked, wSwitch.getlocid( m_Props )) )
    islocked = False;

  if( islocked || issavepos || !isset || !wGui.isshowroute4switch(wxGetApp().getIni()) )
    actroute = !occupied;

  // SVG Symbol:
  if( m_SvgSym2!=NULL && StrOp.equals( state, wSwitch.turnout ) ) {
    if( occupied && m_SvgSym5 != NULL )
      if( islocked && m_SvgSym15 != NULL )
        drawSvgSym(dc, m_SvgSym15, ori);
      else
        drawSvgSym(dc, m_SvgSym5, ori);
    else if( actroute && m_SvgSym7 != NULL )
      if( !isset && m_SvgSym[17] != NULL )
        drawSvgSym(dc, m_SvgSym[17], ori);
      else if( islocked && m_SvgSym13 != NULL )
        drawSvgSym(dc, m_SvgSym13, ori);
      else if( issavepos && m_SvgSym[19] != NULL )
        drawSvgSym(dc, m_SvgSym[19], ori);
      else
        drawSvgSym(dc, m_SvgSym7, ori);
    else
      drawSvgSym(dc, m_SvgSym2, ori);
  }
  else if( m_SvgSym1!=NULL ) {
    if( occupied && m_SvgSym4 != NULL )
      if( islocked && m_SvgSym14 != NULL )
        drawSvgSym(dc, m_SvgSym14, ori);
      else
        drawSvgSym(dc, m_SvgSym4, ori);
    else if( actroute && m_SvgSym8 != NULL )
      drawSvgSym(dc, m_SvgSym8, ori);
    else if( actroute && m_SvgSym6 != NULL )
      if( !isset && m_SvgSym[16] != NULL )
        drawSvgSym(dc, m_SvgSym[16], ori);
      else if( islocked && m_SvgSym12 != NULL )
        drawSvgSym(dc, m_SvgSym12, ori);
      else if( issavepos && m_SvgSym[18] != NULL )
        drawSvgSym(dc, m_SvgSym[18], ori);
      else
        drawSvgSym(dc, m_SvgSym6, ori);
    else
      drawSvgSym(dc, m_SvgSym1, ori);
  }


  if( m_bShowID ) {
    if( m_iSymSubType == switchtype::i_crossingright ) {
      if( StrOp.equals( ori, wItem.south ) || StrOp.equals( ori, wItem.north ) ) {
        if( raster )
          drawString(wxString(wItem.getid(m_Props),wxConvUTF8), 0, 31, 90.0);
        else
          drawString(wxString(wItem.getid(m_Props),wxConvUTF8), 0, 63, 90.0);
      }
      else {
        drawString(wxString(wItem.getid(m_Props),wxConvUTF8), 0, 0, 0.0);
      }
    }
    else {
      if( StrOp.equals( ori, wItem.south ) || StrOp.equals( ori, wItem.north ) ) {
        if( raster )
          drawString(wxString(wItem.getid(m_Props),wxConvUTF8), 20, 31, 90.0);
        else
          drawString(wxString(wItem.getid(m_Props),wxConvUTF8), 20, 63, 90.0);
      }
      else {
        drawString(wxString(wItem.getid(m_Props),wxConvUTF8), 0, 21, 0.0);
      }
    }
  }

}


/**
 * DoubleCrossing Switch object
 */
void SymbolRenderer::drawDCrossing( wxPaintDC& dc, bool occupied, bool actroute, const char* ori ) {
  const char* state = wSwitch.getstate( m_Props );
  const char* savepos = wSwitch.getsavepos( m_Props );
  Boolean islocked = (wSwitch.getlocid( m_Props )==NULL)?False:True;
  Boolean isset = wSwitch.isset( m_Props );
  Boolean issavepos = (Boolean)( !StrOp.equals( savepos, wSwitch.none ) && !StrOp.equals( state, savepos ) );
  Boolean has2Units = ( wSwitch.getaddr2( m_Props ) > 0 || wSwitch.getport2( m_Props ) > 0 )  ? True:False;
  Boolean raster = StrOp.equals( wSwitch.getswtype( m_Props ), wSwitch.swtype_raster );

  TraceOp.trc( "render", TRCLEVEL_DEBUG, __LINE__, 9999, "drawDCrossing %s state=%s", wSwitch.getid( m_Props ), state );

  if( wSwitch.getlocid( m_Props )!=NULL && StrOp.equals( wSwitch.unlocked, wSwitch.getlocid( m_Props )) )
    islocked = False;

  if( islocked || issavepos || !isset || !wGui.isshowroute4switch(wxGetApp().getIni()) )
    actroute = !occupied;

  // SVG Symbol:
  if( has2Units ) {
    if( m_SvgSym3!=NULL && StrOp.equals( state, wSwitch.left ) ) {
      if( occupied && m_SvgSym7 != NULL )
        if( islocked && m_SvgSym15 != NULL )
          drawSvgSym(dc, m_SvgSym15, ori);
        else
          drawSvgSym(dc, m_SvgSym7, ori);
      else if( actroute && m_SvgSym11 != NULL )
        if( !isset && m_SvgSym[23] != NULL )
          drawSvgSym(dc, m_SvgSym[23], ori);
        else if( islocked && m_SvgSym[24] != NULL )
          drawSvgSym(dc, m_SvgSym[24], ori);
        else if( issavepos && m_SvgSym[25] != NULL )
          drawSvgSym(dc, m_SvgSym[25], ori);
        else
          drawSvgSym(dc, m_SvgSym11, ori);
      else
        drawSvgSym(dc, m_SvgSym3, ori);
    }
    else if( m_SvgSym4!=NULL && StrOp.equals( state, wSwitch.right ) ) {
      if( occupied && m_SvgSym8 != NULL )
        if( islocked && m_SvgSym16 != NULL )
          drawSvgSym(dc, m_SvgSym16, ori);
        else
          drawSvgSym(dc, m_SvgSym8, ori);
      else if( actroute && m_SvgSym12 != NULL )
        if( !isset && m_SvgSym[26] != NULL )
          drawSvgSym(dc, m_SvgSym[26], ori);
        else if( islocked && m_SvgSym[27] != NULL )
          drawSvgSym(dc, m_SvgSym[27], ori);
        else if( issavepos && m_SvgSym[28] != NULL )
          drawSvgSym(dc, m_SvgSym[28], ori);
        else
          drawSvgSym(dc, m_SvgSym12, ori);
      else
        drawSvgSym(dc, m_SvgSym4, ori);
    }
    else if( m_SvgSym2!=NULL && StrOp.equals( state, wSwitch.turnout ) ) {
      if( occupied && m_SvgSym6 != NULL )
        if( islocked && m_SvgSym14 != NULL )
          drawSvgSym(dc, m_SvgSym14, ori);
        else
          drawSvgSym(dc, m_SvgSym6, ori);
      else if( actroute && m_SvgSym10 != NULL )
        if( !isset && m_SvgSym[20] != NULL )
          drawSvgSym(dc, m_SvgSym[20], ori);
        else if( islocked && m_SvgSym[21] != NULL )
          drawSvgSym(dc, m_SvgSym[21], ori);
        else if( issavepos && m_SvgSym[22] != NULL )
          drawSvgSym(dc, m_SvgSym[22], ori);
        else
          drawSvgSym(dc, m_SvgSym10, ori);
      else
        drawSvgSym(dc, m_SvgSym2, ori);
    }
    else if( m_SvgSym1!=NULL ) {
      if( occupied && m_SvgSym5 != NULL )
        if( islocked && m_SvgSym13 != NULL )
          drawSvgSym(dc, m_SvgSym13, ori);
        else
          drawSvgSym(dc, m_SvgSym5, ori);
      else if( actroute && m_SvgSym9 != NULL )
        if( !isset && m_SvgSym[17] != NULL )
          drawSvgSym(dc, m_SvgSym[17], ori);
        else if( islocked && m_SvgSym[18] != NULL )
          drawSvgSym(dc, m_SvgSym[18], ori);
        else if( issavepos && m_SvgSym[19] != NULL )
          drawSvgSym(dc, m_SvgSym[19], ori);
        else
          drawSvgSym(dc, m_SvgSym9, ori);
      else
        drawSvgSym(dc, m_SvgSym1, ori);
    }
  }

  else if( m_SvgSym2!=NULL && StrOp.equals( state, wSwitch.turnout ) ) {
    if( occupied && m_SvgSym6 != NULL )
      if( islocked && m_SvgSym14 != NULL )
        drawSvgSym(dc, m_SvgSym14, ori);
      else
        drawSvgSym(dc, m_SvgSym6, ori);
    else if( actroute && m_SvgSym10 != NULL )
      if( !isset && m_SvgSym[20] != NULL )
        drawSvgSym(dc, m_SvgSym[20], ori);
      else if( islocked && m_SvgSym[21] != NULL )
        drawSvgSym(dc, m_SvgSym[21], ori);
      else if( issavepos && m_SvgSym[22] != NULL )
        drawSvgSym(dc, m_SvgSym[22], ori);
      else
        drawSvgSym(dc, m_SvgSym10, ori);
    else
      drawSvgSym(dc, m_SvgSym2, ori);
  }

  else if( m_SvgSym1!=NULL ) {
    if( occupied && m_SvgSym5 != NULL )
      if( islocked && m_SvgSym[13] != NULL )
        drawSvgSym(dc, m_SvgSym[13], ori);
      else
        drawSvgSym(dc, m_SvgSym5, ori);
    else if( actroute && m_SvgSym9 != NULL )
      if( !isset && m_SvgSym[17] != NULL )
        drawSvgSym(dc, m_SvgSym[17], ori);
      else if( islocked && m_SvgSym[18] != NULL )
        drawSvgSym(dc, m_SvgSym[18], ori);
      else if( issavepos && m_SvgSym[19] != NULL )
        drawSvgSym(dc, m_SvgSym[19], ori);
      else
        drawSvgSym(dc, m_SvgSym9, ori);
    else
      drawSvgSym(dc, m_SvgSym1, ori);
  }


  if( m_bShowID ) {
    if( m_iSymSubType == switchtype::i_dcrossingright ) {
      if( StrOp.equals( ori, wItem.south ) ) {
        drawString(wxString(wItem.getid(m_Props),wxConvUTF8), 32, 1, 270.0);
      }
      else if( StrOp.equals( ori, wItem.north ) ) {
        if( raster )
          drawString(wxString(wItem.getid(m_Props),wxConvUTF8), 1, 31, 90.0);
        else
          drawString(wxString(wItem.getid(m_Props),wxConvUTF8), 1, 63, 90.0);
      }
      else {
        drawString(wxString(wItem.getid(m_Props),wxConvUTF8), 0, 1, 0.0);
      }
    }
    else {
      if( StrOp.equals( ori, wItem.south ) ) {
        if( raster )
          drawString(wxString(wItem.getid(m_Props),wxConvUTF8), 10, 0, 270.0);
        else
          drawString(wxString(wItem.getid(m_Props),wxConvUTF8), 32, 32, 270.0);
      }
      else if( StrOp.equals( ori, wItem.north ) ) {
        if( raster )
          drawString(wxString(wItem.getid(m_Props),wxConvUTF8), 10, 0, 270.0);
        else
          drawString(wxString(wItem.getid(m_Props),wxConvUTF8), 1, 32, 90.0);
      }
      else {
        drawString(wxString(wItem.getid(m_Props),wxConvUTF8), 0, 20, 0.0);
      }
    }
  }


}


/**
 * Threeway Switch object
 */
void SymbolRenderer::drawThreeway( wxPaintDC& dc, bool occupied, bool actroute, const char* ori ) {
  const char* state = wSwitch.getstate( m_Props );
  Boolean raster = StrOp.equals( wSwitch.getswtype( m_Props ), wSwitch.swtype_raster );

  if( !wGui.isshowroute4switch(wxGetApp().getIni()) )
    actroute = !occupied;

  // SVG Symbol:
  if( m_SvgSym2!=NULL && StrOp.equals( state, wSwitch.left ) ) {
    if( occupied && m_SvgSym5 != NULL )
      drawSvgSym(dc, m_SvgSym5, ori);
    else if( actroute && m_SvgSym8 != NULL )
      drawSvgSym(dc, m_SvgSym8, ori);
    else
      drawSvgSym(dc, m_SvgSym2, ori);
  }
  else if( m_SvgSym3!=NULL && StrOp.equals( state, wSwitch.right ) ) {
    if( occupied && m_SvgSym6 != NULL )
      drawSvgSym(dc, m_SvgSym6, ori);
    else if( actroute && m_SvgSym9 != NULL )
      drawSvgSym(dc, m_SvgSym9, ori);
    else
      drawSvgSym(dc, m_SvgSym3, ori);
  }
  else if( m_SvgSym1!=NULL ) {
    if( occupied && m_SvgSym4 != NULL )
      drawSvgSym(dc, m_SvgSym4, ori);
    else if( actroute && m_SvgSym7 != NULL )
      drawSvgSym(dc, m_SvgSym7, ori);
    else
      drawSvgSym(dc, m_SvgSym1, ori);
  }

  if( m_bShowID ) {
    wxFont* font = setFont();
    double width = 0;
    double height = 0;
    double descent = 0;
    double externalLeading = 0;
    if( m_UseGC )
      m_GC->GetTextExtent( wxString(wItem.getid(m_Props),wxConvUTF8).Trim(), (wxDouble*)&width,(wxDouble*)&height,(wxDouble*)&descent,(wxDouble*)&externalLeading);
    else {
      wxCoord w;
      wxCoord h;
      dc.GetTextExtent(wxString(wItem.getid(m_Props),wxConvUTF8).Trim(), &w, &h, 0,0, font);
      width  = w;
      height = h;
    }


    if( raster ) {
      if( StrOp.equals( ori, wItem.south ) ) {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 1, 31, 90.0, false );
      }
      else if( StrOp.equals( ori, wItem.north ) ) {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 31, 1, 270.0, false );
      }
      else if( StrOp.equals( ori, wItem.east ) ) {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 0, 1, 0.0, false );
      }
      else {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 31 - width, 1, 0.0, false );
      }
    }
    else {
      if( StrOp.equals( ori, wItem.south ) ) {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 1, width, 90.0, false );
      }
      else if( StrOp.equals( ori, wItem.north ) ) {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 1, 32, 90.0, false );
      }
      else if( StrOp.equals( ori, wItem.east ) ) {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 32 - width, 1, 0.0, false );
      }
      else {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 0, 1, 0.0, false );
      }
    }
    delete font;
  }



}


/**
 * Accessory Switch object
 */
void SymbolRenderer::drawAccessory( wxPaintDC& dc, bool occupied, bool actroute, const char* ori ) {
  const char* state = wSwitch.getstate( m_Props );

  // SVG Symbol:
  if( StrOp.equals( state, wSwitch.turnout ) ) { // off
    if( occupied && m_SvgSym4!=NULL )
      drawSvgSym(dc, m_SvgSym4, ori);
    else if( actroute && m_SvgSym6!=NULL )
      drawSvgSym(dc, m_SvgSym6, ori);
    else if( m_SvgSym2!=NULL )
      drawSvgSym(dc, m_SvgSym2, ori);
  }
  else { // on
    if( occupied && m_SvgSym3!=NULL)
      drawSvgSym(dc, m_SvgSym3, ori);
    else if( actroute && m_SvgSym5!=NULL )
      drawSvgSym(dc, m_SvgSym5, ori);
    else if( m_SvgSym1!=NULL )
      drawSvgSym(dc, m_SvgSym1, ori);
  }
}


/**
 * Turnout Switch object
 */
void SymbolRenderer::drawTurnout( wxPaintDC& dc, bool occupied, bool actroute, const char* ori ) {
  const char* state = wSwitch.getstate( m_Props );
  const char* savepos = wSwitch.getsavepos( m_Props );
  Boolean islocked = (wSwitch.getlocid( m_Props )==NULL)?False:True;
  Boolean isset = wSwitch.isset( m_Props );
  Boolean issavepos = (Boolean)( !StrOp.equals( savepos, wSwitch.none ) && !StrOp.equals( state, savepos ) );
  Boolean raster = StrOp.equals( wSwitch.getswtype( m_Props ), wSwitch.swtype_raster );

  if( wSwitch.getlocid( m_Props )!=NULL && StrOp.equals( wSwitch.unlocked, wSwitch.getlocid( m_Props )) )
    islocked = False;

  if( islocked || issavepos || !isset || !wGui.isshowroute4switch(wxGetApp().getIni()) )
    actroute = !occupied;

  // SVG Symbol:
  if( m_SvgSym2!=NULL && StrOp.equals( state, wSwitch.turnout ) ) {
    if( occupied && m_SvgSym5 != NULL )
      if( islocked && m_SvgSym15 != NULL )
        drawSvgSym(dc, m_SvgSym15, ori);
      else
        drawSvgSym(dc, m_SvgSym5, ori);
    else if( actroute && m_SvgSym7 != NULL )
      if( !isset && m_SvgSym13 != NULL )
        drawSvgSym(dc, m_SvgSym13, ori);
      else if( islocked && m_SvgSym[17] != NULL )
        drawSvgSym(dc, m_SvgSym[17], ori);
      else if( issavepos && m_SvgSym[27] != NULL )
        drawSvgSym(dc, m_SvgSym[27], ori);
      else
        drawSvgSym(dc, m_SvgSym7, ori);
    else
      drawSvgSym(dc, m_SvgSym2, ori);
  }
  else if( m_SvgSym1!=NULL ) {
    if( occupied && m_SvgSym4 != NULL )
      if( islocked && m_SvgSym14 != NULL )
        drawSvgSym(dc, m_SvgSym14, ori);
      else
        drawSvgSym(dc, m_SvgSym4, ori);
    else if( actroute && m_SvgSym6 != NULL )
      if( !isset && m_SvgSym11 != NULL )
        drawSvgSym(dc, m_SvgSym11, ori);
      else if( islocked && m_SvgSym16 != NULL )
        drawSvgSym(dc, m_SvgSym16, ori);
      else if( issavepos && m_SvgSym[26] != NULL )
        drawSvgSym(dc, m_SvgSym[26], ori);
      else
        drawSvgSym(dc, m_SvgSym6, ori);
    else
      drawSvgSym(dc, m_SvgSym1, ori);
  }

  if( m_bShowID ) {
    /* twoway switch is different */
    if( m_iSymSubType == switchtype::i_twoway && raster ) {
      if( StrOp.equals( ori, wItem.south ) ) {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 1, 32, 90.0 );
      }
      else if( StrOp.equals( ori, wItem.north ) ) {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 32, 1, 270.0 );
      }
      else if( StrOp.equals( ori, wItem.east ) ) {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 0, 20, 0.0 );
      }
      else {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 13, 1, 0.0 );
      }
    }
    else if( m_iSymSubType == switchtype::i_twoway ) {
      if( StrOp.equals( ori, wItem.south ) ) {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 18, 1, 270.0 );
      }
      else if( StrOp.equals( ori, wItem.north ) ) {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 14, 32, 90.0 );
      }
      else if( StrOp.equals( ori, wItem.east ) ) {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 12, 12, 0.0 );
      }
      else {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 0, 12, 0.0 );
      }
    }
    else if( m_SvgSym16 != NULL ) {
      if( StrOp.equals( ori, wItem.south ) ) {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 32, 17, 270.0 );
      }
      else if( StrOp.equals( ori, wItem.north ) ) {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 1, 17, 90.0 );
      }
      else if( StrOp.equals( ori, wItem.east ) ) {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 0, 20, 0.0 );
      }
      else {
        drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 17, 1, 0.0 );
      }
    }
    /* standard switches non raster and raster */
    else if( StrOp.equals( ori, wItem.south ) ) {
      drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 32, 1, 270.0 );
    }
    else if( StrOp.equals( ori, wItem.north ) ) {
      drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 1, 32, 90.0 );
    }
    else if( StrOp.equals( ori, wItem.east ) ) {
      drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 0, 20, 0.0 );
    }
    else {
      drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 0, 1, 0.0 );
    }
  }

}

/**
 * Switch object
 */
void SymbolRenderer::drawSwitch( wxPaintDC& dc, bool occupied, bool actroute, const char* ori ) {
  const char* state = wSwitch.getstate( m_Props );

  TraceOp.trc( "render", TRCLEVEL_DEBUG, __LINE__, 9999, "Switch %s state=%s subtype=%d ori=%s occ=%d route=%d",
      wSwitch.getid( m_Props ), state, m_iSymSubType, ori, occupied, actroute );

  switch( m_iSymSubType ) {
    case switchtype::i_decoupler:
      drawDecoupler( dc, occupied, actroute, ori );
      break;

    case switchtype::i_ccrossing:
      drawCCrossing( dc, occupied, actroute, ori );
      break;

    case switchtype::i_crossing:
    case switchtype::i_crossingleft:
    case switchtype::i_crossingright:
      drawCrossing( dc, occupied, actroute, ori );
      break;

    case switchtype::i_dcrossingleft:
    case switchtype::i_dcrossingright:
      drawDCrossing( dc, occupied, actroute, ori );
      break;

    case switchtype::i_threeway:
      drawThreeway( dc, occupied, actroute, ori );
      break;

    case switchtype::i_accessory:
      drawAccessory( dc, occupied, actroute, ori );
      break;

    case switchtype::i_turnoutleft:
    case switchtype::i_turnoutright:
    case switchtype::i_twoway:
      drawTurnout( dc, occupied, actroute, ori );
      break;

  }
}


void SymbolRenderer::drawDecoupler( wxPaintDC& dc, bool occupied, bool actroute, const char* ori ) {
  const char* state = wSwitch.getstate( m_Props );

  // SVG Symbol:
  if( m_SvgSym3!=NULL && StrOp.equals( state, wSwitch.straight ) ) {
    if( occupied && m_SvgSym4 != NULL )
      drawSvgSym(dc, m_SvgSym4, ori);
    else if( occupied && actroute && m_SvgSym7 != NULL )
      drawSvgSym(dc, m_SvgSym7, ori);
    else if( occupied && actroute && m_SvgSym4 != NULL )
      drawSvgSym(dc, m_SvgSym4, ori);
    else if( !occupied && actroute && m_SvgSym6 != NULL )
      drawSvgSym(dc, m_SvgSym6, ori);
    else if( m_SvgSym3 != NULL )
      drawSvgSym(dc, m_SvgSym3, ori);
  }
  else if( m_SvgSym1!=NULL ) {
    if( occupied && m_SvgSym2 != NULL )
      drawSvgSym(dc, m_SvgSym2, ori);
    else if( occupied && actroute && m_SvgSym8 != NULL )
      drawSvgSym(dc, m_SvgSym8, ori);
    else if( occupied && actroute && m_SvgSym2 != NULL )
      drawSvgSym(dc, m_SvgSym2, ori);
    else if( !occupied && actroute && m_SvgSym5 != NULL )
      drawSvgSym(dc, m_SvgSym5, ori);
    else if( m_SvgSym1 != NULL )
      drawSvgSym(dc, m_SvgSym1, ori);
  }

  if( m_bShowID ) {
    if( StrOp.equals( ori, wItem.south ) ) {
      drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 32, 1, 270.0 );
    }
    else if( StrOp.equals( ori, wItem.north ) ) {
      drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 1, 32, 90.0 );
    }
    else
      drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 0, 1, 0.0 );
  }
}




/**
 * Signal object
 */
void SymbolRenderer::drawSignal( wxPaintDC& dc, bool occupied, bool actroute, const char* ori ) {
  const char* state = wSignal.getstate( m_Props );
  int aspects = wSignal.getaspects( m_Props );
  int nr = wSignal.getaspect(m_Props);
  TraceOp.trc( "render", TRCLEVEL_DEBUG, __LINE__, 9999, "setting %d aspect signal %s to %s (nr=%d)", aspects, wSignal.getid( m_Props ), state, nr );

  if( nr == -1 )
    nr = 0;

  if( nr >= 0 && nr < 5 && wSignal.getusepatterns( m_Props ) == wSignal.use_aspectnrs ) {
    if( wSignal.getgreennr(m_Props) == nr )
      state = wSignal.green;
    else if( wSignal.getrednr(m_Props) == nr )
      state = wSignal.red;
    else if( wSignal.getyellownr(m_Props) == nr )
      state = wSignal.yellow;
    else if( wSignal.getwhitenr(m_Props) == nr )
      state = wSignal.white;
    else if( wSignal.getblanknr(m_Props) == nr )
      state = wSignal.blank;
  }

  // SVG Symbol:
  if( nr >= 0 && nr < 32 && (aspects > 4 || wSignal.isusesymbolprefix(m_Props) ) && m_SvgSym[nr] != NULL) {
    if( occupied && m_SvgSymOcc[nr] != NULL)
      drawSvgSym(dc, m_SvgSymOcc[nr], ori);
    else if( actroute && m_SvgSymRoute[nr] != NULL)
      drawSvgSym(dc, m_SvgSymRoute[nr], ori);
    else
      drawSvgSym(dc, m_SvgSym[nr], ori);
  }
  else if( m_SvgSym2!=NULL && StrOp.equals( state, wSignal.yellow ) ) {
    if( occupied && m_SvgSym5 != NULL)
      drawSvgSym(dc, m_SvgSym5, ori);
    else if( actroute && m_SvgSym10 != NULL)
      drawSvgSym(dc, m_SvgSym10, ori);
    else
      drawSvgSym(dc, m_SvgSym2, ori);
  }
  else if( m_SvgSym3!=NULL && StrOp.equals( state, wSignal.green ) ) {
    if( occupied && m_SvgSym6 != NULL)
      drawSvgSym(dc, m_SvgSym6, ori);
    else if( actroute && m_SvgSym11 != NULL)
      drawSvgSym(dc, m_SvgSym11, ori);
    else
      drawSvgSym(dc, m_SvgSym3, ori);
  }
  else if( m_SvgSym7!=NULL && StrOp.equals( state, wSignal.white ) ) {
    if( occupied && m_SvgSym8 != NULL)
      drawSvgSym(dc, m_SvgSym8, ori);
    else if( actroute && m_SvgSym12 != NULL)
      drawSvgSym(dc, m_SvgSym12, ori);
    else
      drawSvgSym(dc, m_SvgSym7, ori);
  }
  else if( m_SvgSym13!=NULL && StrOp.equals( state, wSignal.blank ) ) {
    if( occupied && m_SvgSym14 != NULL)
      drawSvgSym(dc, m_SvgSym14, ori);
    else if( actroute && m_SvgSym15 != NULL)
      drawSvgSym(dc, m_SvgSym15, ori);
    else
      drawSvgSym(dc, m_SvgSym13, ori);
  }
  else if( m_SvgSym2!=NULL && ( StrOp.equals( state, wSignal.green ) || StrOp.equals( state, wSignal.white ) ) && aspects == 2 ) {
    /* default to yellow aspect */
    if( occupied && m_SvgSym5 != NULL)
      drawSvgSym(dc, m_SvgSym5, ori);
    else if( actroute && m_SvgSym11 != NULL)
      drawSvgSym(dc, m_SvgSym11, ori);
    else
      drawSvgSym(dc, m_SvgSym2, ori);
  }
  else if( m_SvgSym1!=NULL ) {
    if( occupied && m_SvgSym4 != NULL)
      drawSvgSym(dc, m_SvgSym4, ori);
    else if( actroute && m_SvgSym9 != NULL)
      drawSvgSym(dc, m_SvgSym9, ori);
    else
      drawSvgSym(dc, m_SvgSym1, ori);
  }

  if( StrOp.equals( wSignal.blockstate, wSignal.getsignal( m_Props ) ) && StrOp.len(m_Label) > 0 ) {
    int red    = 0;
    int green  = 0;
    int blue   = 0;
    bool underline = false;

    if( m_iOccupied == 1 ) {
      setPen( wxPen(Base::getGreen()));
      setBrush( wxBrush(Base::getGreen()));
    }
    else if( m_iOccupied == 2 ) {
      setPen( wxPen(Base::getRed()));
      setBrush( wxBrush(Base::getRed()));
    }
    else if( m_iOccupied == 3 ) {
      setPen( wxPen(Base::getBlue()));
      setBrush( wxBrush(Base::getBlue()));
    }
    else if( m_iOccupied == 4 ) {
      setPen( wxPen(Base::getYellow()));
      setBrush( wxBrush(Base::getYellow()));
    }
    else if( m_iOccupied == 5 ) {
      setPen( wxPen(Base::getGreen()));
      setBrush( wxBrush(Base::getGreen()));
      underline = true;
    }
    else if( m_iOccupied == 6 ) {
      setPen( wxPen(Base::getYellow()));
      setBrush( wxBrush(Base::getYellow()));
      underline = true;
    }
    else {
      setPen( wxPen(Base::getGrey()));
      setBrush( wxBrush(Base::getGrey()));
    }

    if( m_UseGC ) {
      m_GC->DrawRectangle(6,6,19,19);
    }
    else {
      dc.DrawRectangle(6,6,19,19);
    }

    wxFont* font = setFont(m_iTextps, red, green, blue, true, false, underline);
    /* center the text */
    double width = 0;
    double height = 0;
    double descent = 0;
    double externalLeading = 0;
    if( m_UseGC )
      m_GC->GetTextExtent( wxString(m_Label,wxConvUTF8).Trim(),(wxDouble*)&width,(wxDouble*)&height,(wxDouble*)&descent,(wxDouble*)&externalLeading);
    else {
      wxCoord w;
      wxCoord h;
      dc.GetTextExtent(wxString(m_Label,wxConvUTF8).Trim(), &w, &h, 0,0, font);
      width  = w;
      height = h;
    }

    drawString( wxString(m_Label,wxConvUTF8), (32-width)/2, (32-height)/2, 0.0, false );

    delete font;
  }

  if( m_bShowID && !StrOp.equals( wSignal.blockstate, wSignal.getsignal( m_Props ) ) ) {
    if( StrOp.equals( ori, wItem.north ) )
      drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 32, 1, 270.0 );
    else if( StrOp.equals( ori, wItem.south ) )
      drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 1, 32, 90.0 );
    else if( StrOp.equals( ori, wItem.east ) )
      drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 0, 1, 0.0 );
    else
      drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 0, 20, 0.0 );

  }
}


/**
 * Output object
 */
void SymbolRenderer::drawOutput( wxPaintDC& dc, bool occupied, bool actroute, const char* ori ) {
  const char* state = wOutput.getstate( m_Props );
  TraceOp.trc( "render", TRCLEVEL_DEBUG, __LINE__, 9999, "setting output %s to %s", wSignal.getid( m_Props ), state );

  if( m_UseGC && (wOutput.getporttype(m_Props) == wProgram.porttype_backlight || wOutput.getporttype(m_Props) == wProgram.porttype_light) ) {
    // Render light.
    wxPen* pen = (wxPen*)wxBLACK_PEN;
    pen->SetWidth(2);
    pen->SetStyle(wxSOLID);
    if( m_UseGC ) {
      int bri = wOutput.getvalue(m_Props);
      if( StrOp.equals( wOutput.off, state ) )
        bri = 0;
      float factor = (1.0 / 255.0) * (float)bri;
      setPen( *pen );
      setBrush( wxBrush(wxColour(bri, bri, bri)) );
      m_GC->DrawEllipse(6, 6, 20, 20);
      if( wOutput.getcolor(m_Props) != NULL && wOutput.iscolortype(m_Props) ) {
        iONode color = wOutput.getcolor(m_Props);
        TraceOp.trc( "render", TRCLEVEL_DEBUG, __LINE__, 9999, "setting output %s to brightness %d, factor=%.2f RGBW=%d,%d,%d,%d",
            wOutput.getid( m_Props ), bri, factor, wColor.getred(color), wColor.getgreen(color), wColor.getblue(color), wColor.getwhite(color) );
        int w = wColor.getwhite(color);
        int r = wColor.getred(color) + w;
        int g = wColor.getgreen(color) + w;
        int b = wColor.getblue(color) + w;
        if( r > 255 ) r = 255;
        if( g > 255 ) g = 255;
        if( b > 255 ) b = 255;
        setPen( wxPen(wxColour(r,g,b)));
        setBrush( wxBrush(wxColour(r,g,b)) );
      }
      else {
        TraceOp.trc( "render", TRCLEVEL_DEBUG, __LINE__, 9999, "setting output %s to brightness %d, factor=%.2f", wOutput.getid( m_Props ), bri, factor );
        setPen( wxPen(wxColour(255, 255, 0)));
        setBrush( wxBrush(wxColour(255, 255, 0)) );
      }
      m_GC->DrawEllipse(6.0 + (10.0 - 10.0 * factor), 6.0 + (10.0 - 10.0 * factor), 19.0 * factor, 19.0 * factor);
    }
  }
  // SVG Symbol:
  else if( m_SvgSym3!=NULL && StrOp.equals( state, wOutput.active ) ) {
    if(occupied && m_SvgSym6!= NULL)
      drawSvgSym(dc, m_SvgSym6, ori);
    else if(actroute && m_SvgSym9!= NULL)
      drawSvgSym(dc, m_SvgSym9, ori);
    else if(actroute && m_SvgSym6!= NULL)
      drawSvgSym(dc, m_SvgSym6, ori);
    else
      drawSvgSym(dc, m_SvgSym3, ori);
  }
  else if( m_SvgSym2!=NULL && StrOp.equals( state, wOutput.on ) ) {
    if(occupied && m_SvgSym5!= NULL)
      drawSvgSym(dc, m_SvgSym5, ori);
    else if(actroute && m_SvgSym8!= NULL)
      drawSvgSym(dc, m_SvgSym8, ori);
    else if(actroute && m_SvgSym5!= NULL)
      drawSvgSym(dc, m_SvgSym5, ori);
    else
      drawSvgSym(dc, m_SvgSym2, ori);
  }
  else if( m_SvgSym1!=NULL ) {
    if(occupied && m_SvgSym4!= NULL)
      drawSvgSym(dc, m_SvgSym4, ori);
    else if(actroute && m_SvgSym7!= NULL)
      drawSvgSym(dc, m_SvgSym7, ori);
    else if(actroute && m_SvgSym4!= NULL)
      drawSvgSym(dc, m_SvgSym4, ori);
    else
      drawSvgSym(dc, m_SvgSym1, ori);
  }

  if( m_bShowID ) {
    drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 0, 0, 0.0 );
  }
}

/**
 * Stage object
 */
void SymbolRenderer::drawStage( wxPaintDC& dc, bool occupied, const char* ori ) {
  m_bRotateable = true;
  int len = 4;

  if( m_SvgSym1 != NULL && m_iOccupied == 0 )
  {
    drawSvgSym(dc, m_SvgSym1, ori);
  }
  else if( m_SvgSym2!=NULL && m_iOccupied == 1 ) {
    // occupied
    drawSvgSym(dc, m_SvgSym2, ori);
  }
  else if( m_SvgSym3!=NULL && m_iOccupied == 2 ) {
    /* reserved state */
    drawSvgSym(dc, m_SvgSym3, ori);
  }
  else if( m_SvgSym4!=NULL && m_iOccupied == 3 ) {
    /* enter state */
    drawSvgSym(dc, m_SvgSym4, ori);
  }
  else if( m_SvgSym5!=NULL && m_iOccupied == 4 ) {
    /* closed state */
    drawSvgSym(dc, m_SvgSym5, ori);
  }
  else if( m_SvgSym6!=NULL && m_iOccupied == 5 ) {
    /* ghost state */
    drawSvgSym(dc, m_SvgSym6, ori);
  }

  if( StrOp.len(m_Label) > 0 ) {
    int red = 0;
    int green = 0;
    int blue = 0;


    iONode planpanelIni = wGui.getplanpanel(wxGetApp().getIni());
    if( planpanelIni != NULL ) {
      red   = wPlanPanel.getbktext_red(planpanelIni);
      green = wPlanPanel.getbktext_green(planpanelIni);
      blue  = wPlanPanel.getbktext_blue(planpanelIni);
    }

    wxFont* font = setFont(m_iTextps, red, green, blue);

    if( StrOp.equals( ori, wItem.south ) ) {
      drawString( wxString(m_Label,wxConvUTF8), 32-5, 3, 270.0, false );
    }
    else if( StrOp.equals( ori, wItem.north ) ) {
      drawString( wxString(m_Label,wxConvUTF8), 7, (32 * len)-3, 90.0, false );
    }
    else {
      drawString( wxString(m_Label,wxConvUTF8), 3, 5, 0.0, false );
    }

    delete font;
  }

}


double SymbolRenderer::getRadians( double degrees ) {
  static double PI= 3.14159265358979;
  return (degrees / 360) * (2.0 * PI);
}

/**
 * Block object
 */
void SymbolRenderer::drawBlockTriangle( wxPaintDC& dc, const char* ori ) {
  if( m_iOccupied == 0 || m_iOccupied == 2 || m_iOccupied == 4 || m_iOccupied == 6 || m_iOccupied == 7  )
    return;

  const wxBrush& b = dc.GetBrush();
  setBrush( *wxBLACK );
  setPen( wxPen( *wxBLACK, 1));
  static wxPoint p[4];
  int end ;

  if( StrOp.equals( wItem.west, ori ) || StrOp.equals( wItem.east, ori ) ) {
    // horizontal triangle
    if( m_cx <= 3 ) {
      p[0].x =  8; p[0].y =  8;
      p[1].x = 11; p[1].y = 11;
      p[2].x = 11; p[2].y =  5;
      p[3].x =  8; p[3].y =  8;
    }
    else {
      p[0].x = 3; p[0].y = 15;
      p[1].x = 6; p[1].y = 18;
      p[2].x = 6; p[2].y = 12;
      p[3].x = 3; p[3].y = 15;
    }

    if(  ( StrOp.equals( wItem.east, ori ) && ! m_rotate )
      || ( StrOp.equals( wItem.west, ori ) && m_rotate )
      ) {
      // mirror to other end
      end = (m_cx*32) - 1 ;
      p[0].x = end - p[0].x;
      p[1].x = end - p[1].x;
      p[2].x = end - p[2].x;
      p[3].x = end - p[3].x;
    }
  }
  else {
    // vertical triangle
    if( m_cy <= 3 ) {
      p[0].x =  8; p[0].y =  8;
      p[1].x = 11; p[1].y = 11;
      p[2].x =  5; p[2].y = 11;
      p[3].x =  8; p[3].y =  8;
    }
    else {
      p[0].x = 15; p[0].y = 3;
      p[1].x = 18; p[1].y = 6;
      p[2].x = 12; p[2].y = 6;
      p[3].x = 15; p[3].y = 3;
    }

    if(  ( StrOp.equals( wItem.north, ori ) && ! m_rotate )
      || ( StrOp.equals( wItem.south, ori ) && m_rotate )
      ) {
      // mirror to other end
      end = (m_cy*32) - 1 ;
      p[0].y = end - p[0].y;
      p[1].y = end - p[1].y;
      p[2].y = end - p[2].y;
      p[3].y = end - p[3].y;
    }
  }

  if( m_UseGC ) {
    wxGraphicsPath path = m_GC->CreatePath();
    path.MoveToPoint(p[0].x, p[0].y);
    path.AddLineToPoint(p[1].x, p[1].y);
    path.AddLineToPoint(p[2].x, p[2].y);
    path.AddLineToPoint(p[3].x, p[3].y);
    path.AddLineToPoint(p[4].x, p[4].y);
    m_GC->FillPath(path);
  }
  else {
    dc.DrawPolygon( 4, p, 0, 0 );
  }

}

void SymbolRenderer::drawBlock( wxPaintDC& dc, bool occupied, const char* ori ) {
  m_bRotateable = true;
  Boolean m_bSmall = wBlock.issmallsymbol(m_Props);
  const char* textOri = ori;

  svgSymbol* svgSym[9];

  svgSym[1] = (m_bSmall && m_SvgSym7  != NULL)?m_SvgSym7:m_SvgSym1;
  svgSym[2] = (m_bSmall && m_SvgSym8  != NULL)?m_SvgSym8:m_SvgSym2;
  svgSym[3] = (m_bSmall && m_SvgSym9  != NULL)?m_SvgSym9:m_SvgSym3;
  svgSym[4] = (m_bSmall && m_SvgSym10 != NULL)?m_SvgSym10:m_SvgSym4;
  svgSym[5] = (m_bSmall && m_SvgSym11 != NULL)?m_SvgSym11:m_SvgSym5;
  svgSym[6] = (m_bSmall && m_SvgSym12 != NULL)?m_SvgSym12:m_SvgSym6;
  svgSym[7] = (m_bSmall && m_SvgSym14 != NULL)?m_SvgSym14:m_SvgSym13;
  svgSym[8] = (m_bSmall && m_SvgSym16 != NULL)?m_SvgSym16:m_SvgSym15;

  // SVG Symbol:
  if( (svgSym[1]!=NULL && m_iOccupied == 0) ||
      (svgSym[1]!=NULL && svgSym[5]==NULL && m_iOccupied == 4) ||
      (svgSym[1]!=NULL && svgSym[6]==NULL && m_iOccupied == 5)  )
  {
    drawSvgSym(dc, svgSym[1], ori);
  }
  else if( svgSym[2]!=NULL && m_iOccupied == 1 ) {
    drawSvgSym(dc, svgSym[2], ori);
  }
  else if( (svgSym[3]!=NULL && m_iOccupied == 2) || (svgSym[3]!=NULL && svgSym[4]==NULL && m_iOccupied == 3) ) {
    /* reserved state */
    drawSvgSym(dc, svgSym[3], ori);
  }
  else if( svgSym[4]!=NULL && m_iOccupied == 3 ) {
    /* reserved state */
    drawSvgSym(dc, svgSym[4], ori);
  }
  else if( svgSym[5]!=NULL && m_iOccupied == 4 ) {
    /* reserved state */
    drawSvgSym(dc, svgSym[5], ori);
  }
  else if( svgSym[6]!=NULL && m_iOccupied == 5 ) {
    /* ghost */
    drawSvgSym(dc, svgSym[6], ori);
  }
  else if( svgSym[7]!=NULL && m_iOccupied == 6 ) {
    /* shortcut */
    drawSvgSym(dc, svgSym[7], ori);
  }
  else if( svgSym[8]!=NULL && m_iOccupied == 7 ) {
     /* aident */
    drawSvgSym(dc, svgSym[8], ori);
  }
  else if( svgSym[1]!=NULL ) {
    drawSvgSym(dc, svgSym[1], ori);
  }

  drawBlockTriangle( dc, ori );

  int labelOffset  = 0;
  int symbolLength = 128;
  int imageWidth   = 0;

  bool l_ImageOK = false;
  if( (m_iOccupied == 1 || m_iOccupied == 3) && m_LocoImage != NULL && StrOp.len(m_LocoImage) > 0 ) {
    // Show loco image.
    const char* imagepath = wGui.getimagepath(wxGetApp().getIni());
    static char pixpath[256];
    StrOp.fmtb( pixpath, "%s%c%s", imagepath, SystemOp.getFileSeparator(), FileOp.ripPath( m_LocoImage ) );

    if( FileOp.exist(pixpath) && StrOp.endsWithi( pixpath, ".png" ) ) {
      wxBitmap* imageBitmap = NULL;
      wxImage img(wxString(pixpath,wxConvUTF8), wxBITMAP_TYPE_PNG);
      int maxheight = 20;
      if( img.GetHeight() > maxheight ) {
        int h = img.GetHeight();
        int w = img.GetWidth();
        float scale = (float)h / (float)maxheight;
        float width = (float)w / scale;
        imageBitmap = new wxBitmap(img.Scale((int)width, maxheight, wxIMAGE_QUALITY_HIGH));
      }
      else {
        imageBitmap = new wxBitmap(img);
      }

      if( m_bSmall )
        symbolLength = 64;

      imageWidth = imageBitmap->GetWidth();

      int x = (symbolLength - imageBitmap->GetWidth()) / 2;
      if( (m_rotate && StrOp.equals(ori, wItem.west)) || (!m_rotate && StrOp.equals(ori, wItem.east)) ) {
        x = symbolLength - imageBitmap->GetWidth() - 10;
        if( m_rotate && StrOp.equals(ori, wItem.west) ) {
          wxImage img = imageBitmap->ConvertToImage();
          delete imageBitmap;
          img = img.Mirror(true);
          imageBitmap = new wxBitmap(img);
        }
      }
      else {
        x = 10;
        labelOffset = imageBitmap->GetWidth();
        if( !m_rotate && StrOp.equals(ori, wItem.west) ) {
          wxImage img = imageBitmap->ConvertToImage();
          delete imageBitmap;
          img = img.Mirror(true);
          imageBitmap = new wxBitmap(img);
        }
      }

      int y = (32-maxheight)/2;
      if( x < 10 )
        x = 10;

      if( (m_rotate && !(StrOp.equals( ori, wItem.north ) || StrOp.equals( ori, wItem.south ))) ||
          (!m_rotate && (StrOp.equals( ori, wItem.north ) || StrOp.equals( ori, wItem.south ))) )
      {
        wxImage img = imageBitmap->ConvertToImage();
        delete imageBitmap;
        img = img.Mirror();
        imageBitmap = new wxBitmap(img);
      }

      if( StrOp.equals( ori, wItem.north ) || StrOp.equals( ori, wItem.south ) ) {
        wxImage img = imageBitmap->ConvertToImage();
        delete imageBitmap;
        img = img.Rotate90( StrOp.equals( ori, wItem.north ) ? false:true );
        imageBitmap = new wxBitmap(img);
        x = (32-maxheight)/2;
        y = (symbolLength - imageBitmap->GetHeight()) / 2;
        labelOffset = 0;
        if( symbolLength - imageBitmap->GetHeight() >= 20 ) {
          if( (!m_rotate && StrOp.equals(ori, wItem.north)) || (m_rotate && StrOp.equals(ori, wItem.south)) ) {
            y = symbolLength - imageBitmap->GetHeight() - 10;
            if( StrOp.equals(ori, wItem.north) )
              labelOffset = imageBitmap->GetHeight();
            else
              labelOffset = 0;
          }
          else {
            y = 10;
            if( StrOp.equals(ori, wItem.north) )
              labelOffset = 0;
            else
              labelOffset = imageBitmap->GetHeight();
          }
        }
        if( y < 10 )
          y = 10;
      }

      if( m_UseGC )
        m_GC->DrawBitmap(*imageBitmap, x, y, imageBitmap->GetWidth(), imageBitmap->GetHeight());
      else
        dc.DrawBitmap(*imageBitmap, x, y);

      delete imageBitmap;

      l_ImageOK = true;
    }
  }


  if( (!l_ImageOK || !m_bSmall) && StrOp.len(m_Label) > 0 ) {
    int red = 0;
    int green = 0;
    int blue = 0;


    iONode planpanelIni = wGui.getplanpanel(wxGetApp().getIni());
    if( planpanelIni != NULL ) {
      red = wPlanPanel.getbktext_red(planpanelIni);
      green = wPlanPanel.getbktext_green(planpanelIni);
      blue = wPlanPanel.getbktext_blue(planpanelIni);
    }

    if( m_bLocoManual ) {
      red   = 0;
      green = 0;
      blue  = 200;
    }

    wxFont* font = setFont(m_iTextps, red, green, blue, m_bLocoManual);
    /* center the blocktext */
    double width = 0;
    double height = 0;
    double descent = 0;
    double externalLeading = 0;
    if( m_UseGC )
      m_GC->GetTextExtent( wxString(m_Label,wxConvUTF8).Trim(),(wxDouble*)&width,(wxDouble*)&height,(wxDouble*)&descent,(wxDouble*)&externalLeading);
    else {
      wxCoord w;
      wxCoord h;
      dc.GetTextExtent(wxString(m_Label,wxConvUTF8).Trim(), &w, &h, 0,0, font);
      width  = w;
      height = h;
    }

    if( imageWidth == 0 || (width <= (symbolLength - imageWidth - 20 )) ) {
      if( StrOp.equals( textOri, wItem.south ) ) {
        drawString( wxString(m_Label,wxConvUTF8), 32-5, 9 + labelOffset, 270.0, false );
      }
      else if( StrOp.equals( textOri, wItem.north ) ) {
        drawString( wxString(m_Label,wxConvUTF8), 7, (32 * m_cy) - 8 - labelOffset,  90.0, false );
      }
      else {
        drawString( wxString(m_Label,wxConvUTF8), 10 + labelOffset, (32-height)/2, 0.0, false );
      }
    }

    delete font;
  }

}


/**
 * SelTab object
 */
void SymbolRenderer::drawSelTab( wxPaintDC& dc, bool occupied, const char* ori ) {
  m_bRotateable = true;
  int nrtracks = wSelTab.getnrtracks(m_Props);
  if( nrtracks > 32 ) {
    nrtracks = 32;
  }

  const wxBrush& b = dc.GetBrush();
  if( m_iOccupied == 1 ) {
    setBrush( wxColour(255,200,200) );
  }
  else if( m_iOccupied == 2 ) {
    setBrush( wxColour(255,255,200) );
  }
  else {
    setBrush( *wxWHITE );
  }

  setPen( wxPen( wxColour(0,0,0), 2));

  if( StrOp.equals( wItem.west, ori ) || StrOp.equals( wItem.east, ori ) ) {
    if( m_UseGC )
      m_GC->DrawRoundedRectangle( 1, 3, (32 * nrtracks) - 1, 28, 10 );
    else
      dc.DrawRoundedRectangle( 1, 3, (32 * nrtracks) - 1, 28, 10 );
  }
  else {
    if( m_UseGC )
      m_GC->DrawRoundedRectangle( 3, 1, 28, (32 * nrtracks) - 1, 10 );
    else
      dc.DrawRoundedRectangle( 3, 1, 28, (32 * nrtracks) - 1, 10 );
  }

  setBrush( b );


  wxFont* font = setFont(m_iTextps);

  /* center the blocktext */
  double width = 0;
  double height = 0;
  double descent = 0;
  double externalLeading = 0;
  if( m_UseGC )
    m_GC->GetTextExtent( wxString(m_Label,wxConvUTF8).Trim(),(wxDouble*)&width,(wxDouble*)&height,(wxDouble*)&descent,(wxDouble*)&externalLeading);
  else {
    wxCoord w;
    wxCoord h;
    dc.GetTextExtent(wxString(m_Label,wxConvUTF8).Trim(), &w, &h, 0,0, font);
    width  = w;
    height = h;
  }

  if( StrOp.equals( ori, wItem.south ) ) {
    drawString( wxString(m_Label,wxConvUTF8), 32-5, 3, 270.0, false );
  }
  else if( StrOp.equals( ori, wItem.north ) ) {
    drawString( wxString(m_Label,wxConvUTF8), 5, (32 * nrtracks)-3, 90.0, false );
  }
  else {
#ifdef __WIN32__
      drawString( wxString(m_Label,wxConvUTF8), 9, 8, 0.0, false );
#else
      drawString( wxString(m_Label,wxConvUTF8), ((32*m_cx-width)/2), (32-height)/2, 0.0, false );
#endif
  }

  delete font;
}


/**
 * Text object
 */
void SymbolRenderer::drawText( wxPaintDC& dc, bool occupied, const char* ori ) {
  m_bRotateable = true;

  if( StrOp.endsWithi(m_Label, ".png") ) {
    if((m_bLabelChanged || !StrOp.equals( ori, m_Ori) )&& m_Bitmap != NULL ) {
      m_bLabelChanged = false;
      delete m_Bitmap;
      m_Bitmap = NULL;
    }
    if( m_Bitmap == NULL ) {
      const char* imagepath = wGui.getimagepath(wxGetApp().getIni());
      static char pixpath[256];
      StrOp.fmtb( pixpath, "%s%c%s", imagepath, SystemOp.getFileSeparator(), FileOp.ripPath( m_Label ) );

      if( FileOp.exist(pixpath)) {
        TraceOp.trc( "renderer", TRCLEVEL_DEBUG, __LINE__, 9999, "picture [%s]", pixpath );
        m_Bitmap = new wxBitmap(wxString(pixpath,wxConvUTF8), wxBITMAP_TYPE_PNG);

        float bmpW = m_Bitmap->GetWidth();
        float bmpH = m_Bitmap->GetHeight();
        float txtW = wText.getcx(m_Props) * 32;
        float txtH = wText.getcy(m_Props) * 32;
        float scaleW = bmpW / txtW;
        float scaleH = bmpH / txtH;
        float scale = 0;
        if( scaleW > scaleH ) {
          scale = scaleW;
        }
        else {
          scale = scaleH;
        }

        if( scale > .5 ) {
          wxImage img = m_Bitmap->ConvertToImage();
          delete m_Bitmap;
          img = img.Scale( (bmpW/scale), (bmpH/scale), wxIMAGE_QUALITY_HIGH );
          m_Bitmap = new wxBitmap(img);
        }

        if( StrOp.equals( ori, wItem.north ) || StrOp.equals( ori, wItem.south ) || StrOp.equals( ori, wItem.east ) ) {
          TraceOp.trc( "renderer", TRCLEVEL_INFO, __LINE__, 9999, "rotate [%s]", pixpath );
          wxImage img = m_Bitmap->ConvertToImage();
          delete m_Bitmap;
          img = img.Rotate90( StrOp.equals( ori, wItem.north ) ? true:false );
          if(StrOp.equals( ori, wItem.east ))
            img = img.Rotate90( StrOp.equals( ori, wItem.north ) ? true:false );
          m_Bitmap = new wxBitmap(img);
        }

      }
      else {
        TraceOp.trc( "locdialog", TRCLEVEL_WARNING, __LINE__, 9999, "picture [%s] not found", pixpath );
        // request the image from server:
        iONode node = NodeOp.inst( wDataReq.name(), NULL, ELEMENT_NODE );
        wDataReq.setcmd( node, wDataReq.get );
        wDataReq.settype( node, wDataReq.image );
        wDataReq.setfilename( node, FileOp.ripPath( m_Label ) );
        wxGetApp().sendToRocrail( node );
      }
    }
    m_Ori = ori;

    if( m_Bitmap != NULL ) {
      if( m_UseGC )
        m_GC->DrawBitmap(*m_Bitmap, 0, 0, m_Bitmap->GetWidth(), m_Bitmap->GetHeight());
      else
        dc.DrawBitmap(*m_Bitmap, 0, 0, true);
      return;
    }
  }

  int pointsize = wText.getpointsize(m_Props);
  if( pointsize == 0 )
    pointsize = m_iTextps;


  if( !wText.istransparent(m_Props) && wText.getbackred(m_Props) != -1 && wText.getbackgreen(m_Props) != -1 && wText.getbackblue(m_Props) != -1 ){
    wxColour color( wText.getbackred(m_Props), wText.getbackgreen(m_Props), wText.getbackblue(m_Props) );
    dc.SetBackground(wxBrush(color));
    dc.Clear();
  }

  wxFont* font = setFont(pointsize,
      wText.getred(m_Props), wText.getgreen(m_Props), wText.getblue(m_Props),
      wText.isbold(m_Props), wText.isitalic(m_Props), wText.isunderlined(m_Props));
  /* center the blocktext */
  double width = 0;
  double height = 0;
  double descent = 0;
  double externalLeading = 0;
  if( m_UseGC )
    m_GC->GetTextExtent( wxString(m_Label,wxConvUTF8).Trim(),(wxDouble*)&width,(wxDouble*)&height,(wxDouble*)&descent,(wxDouble*)&externalLeading);
  else {
    wxCoord w;
    wxCoord h;
    dc.GetTextExtent(wxString(m_Label,wxConvUTF8).Trim(), &w, &h, 0,0, font);
    width  = w;
    height = h;
  }


  double rotation = 0.0;
  int xoff = 3;
  int yoff = 5;
  int xinc = 0;
  int yinc = height;

  if( StrOp.equals( ori, wItem.south ) ) {
    xoff = (32 * wText.getcy( m_Props ))-5;
    yoff = 3;
    xinc = -height;
    yinc = 0;
    rotation = 270.0;
  }
  else if( StrOp.equals( ori, wItem.north ) ) {
    xoff = 5;
    yoff = (32 * wText.getcx( m_Props ))-3;
    xinc = height;
    yinc = 0;
    rotation = 90.0;
  }

  if( StrOp.find(m_Label, "|") ) {
    char s[256] = {'\0'};
    StrOp.copy( s, m_Label);
    char* p = s;
    char* ps = p;
    while( (p = StrOp.find(p, "|")) ) {
      p[0] = '\0';
      p++;
      //TraceOp.trc( "renderer", TRCLEVEL_INFO, __LINE__, 9999, "text %d,%d [%s] %s", xoff, yoff,  ps, ori );
      drawString(  wxString(ps,wxConvUTF8), xoff, yoff, rotation, false );
      yoff += yinc;
      xoff += xinc;
      ps = p;
    }
    //TraceOp.trc( "renderer", TRCLEVEL_INFO, __LINE__, 9999, "text %d,%d [%s] %s", xoff, yoff,  ps, ori );
    drawString(  wxString(ps,wxConvUTF8), xoff, yoff, rotation, false );
  }
  else {
    drawString(  wxString(m_Label,wxConvUTF8), xoff, yoff, rotation, false );
  }

  delete font;

  if( wText.isborder(m_Props) ) {
    wxPen* pen = getPen(NULL);
    pen->SetWidth(1);
    setPen( *pen );
    setBrush( *wxTRANSPARENT_BRUSH );
    if( m_UseGC ) {
      if( StrOp.equals( ori, wItem.south ) || StrOp.equals( ori, wItem.north ) )
        m_GC->DrawRectangle(0,0,(wText.getcy(m_Props) * 32)-1, (wText.getcx(m_Props) * 32)-1);
      else
        m_GC->DrawRectangle(0,0,(wText.getcx(m_Props) * 32)-1, (wText.getcy(m_Props) * 32)-1);
    }
    else {
      if( StrOp.equals( ori, wItem.south ) || StrOp.equals( ori, wItem.north ) )
        dc.DrawRectangle(0,0,(wText.getcy(m_Props) * 32)-1, (wText.getcx(m_Props) * 32)-1);
      else
        dc.DrawRectangle(0,0,(wText.getcx(m_Props) * 32)-1, (wText.getcy(m_Props) * 32)-1);
    }
  }


}


/**
 *
 */
void SymbolRenderer::drawSensor( wxPaintDC& dc, bool occupied, bool actroute, const char* ori ) {
  bool cnt = false;

  if(wFeedback.getcountedcars( m_Props ) != wFeedback.getcarcount( m_Props )) {
    cnt = true;
    TraceOp.trc( "render", TRCLEVEL_INFO, __LINE__, 9999, "sensor %s is counting cars %d/%d",
        wFeedback.getid( m_Props ), wFeedback.getcountedcars( m_Props ), wFeedback.getcarcount( m_Props ) );
  }

  // SVG Symbol:
  if( m_SvgSym7!=NULL && wFeedback.isstate( m_Props ) && cnt) {
    drawSvgSym(dc, m_SvgSym7, ori);
  }
  else if( m_SvgSym2!=NULL && wFeedback.isstate( m_Props ) ) {
    if(occupied && m_SvgSym4!= NULL)
      drawSvgSym(dc, m_SvgSym4, ori);
    else if(actroute && m_SvgSym6!= NULL)
      drawSvgSym(dc, m_SvgSym6, ori);
    else if(actroute && m_SvgSym4!= NULL)
      drawSvgSym(dc, m_SvgSym4, ori);
    else
      drawSvgSym(dc, m_SvgSym2, ori);
  }
  else if( m_SvgSym1!=NULL ) {
    if(occupied && m_SvgSym3!= NULL)
      drawSvgSym(dc, m_SvgSym3, ori);
    else if(actroute && m_SvgSym5!= NULL)
      drawSvgSym(dc, m_SvgSym5, ori);
    else if(actroute && m_SvgSym3!= NULL)
      drawSvgSym(dc, m_SvgSym3, ori);
    else
      drawSvgSym(dc, m_SvgSym1, ori);
  }

  char lab[128] = {'\0'};
  if( m_bShowCounters )
    StrOp.fmtb(lab, "%d,%d,%d", wFeedback.getcounter(m_Props), wFeedback.getcarcount(m_Props), wFeedback.getwheelcount(m_Props));
  else if( m_bShowID )
    StrOp.fmtb(lab, "%s", wItem.getid(m_Props));

  if( m_bShowCounters || m_bShowID ) {
    if( StrOp.equals( ori, wItem.south ) ) {
      drawString( wxString(lab,wxConvUTF8), 32, 1, 270.0 );
    }
    else if( StrOp.equals( ori, wItem.north ) ) {
      drawString( wxString(lab,wxConvUTF8), 1, 32, 90.0 );
    }
    else if(StrOp.equals( ori, wItem.east ) && wFeedback.iscurve( m_Props )) {
      drawString( wxString(lab,wxConvUTF8), 0, 22, 0.0 );
    }
    else {
      drawString( wxString(lab,wxConvUTF8), 0, 1, 0.0 );
    }
  }
}


void SymbolRenderer::drawRoute( wxPaintDC& dc, bool occupied, const char* ori, int status ) {
  TraceOp.trc( "render", TRCLEVEL_DEBUG, __LINE__, 9999, "set route %s to %d", wRoute.getid( m_Props ), status );

  // SVG Symbol:
  if( status == 0 && m_SvgSym1!=NULL ) {
    drawSvgSym(dc, m_SvgSym1, ori);
  }
  else if( status == 1 && m_SvgSym2!=NULL ) {
    drawSvgSym(dc, m_SvgSym2, ori);
  }
  else if( status == 2 && m_SvgSym3!=NULL ) {
    drawSvgSym(dc, m_SvgSym3, ori);
  }
  else if( status == 3 && m_SvgSym4!=NULL ) {
    drawSvgSym(dc, m_SvgSym4, ori);
  }
  else if( status == 4 && m_SvgSym5!=NULL ) {
    drawSvgSym(dc, m_SvgSym5, ori);
  }
  else if( m_SvgSym1!=NULL ) {
    drawSvgSym(dc, m_SvgSym1, ori);
  }

  if( m_bShowID ) {
    if( StrOp.equals( ori, wItem.south ) )
      drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 32, 1, 270.0 );
    else if( StrOp.equals( ori, wItem.north ) )
      drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 1, 32, 90.0 );
    else
      drawString( wxString(wItem.getid(m_Props),wxConvUTF8), 0, 1, 0.0 );
  }

}


void SymbolRenderer::setPen( const wxPen& pen ) {
  if( m_UseGC )
    m_GC->SetPen( pen );
  else
    m_DC->SetPen( pen );
}

void SymbolRenderer::setBrush( const wxBrush& brush ) {
  if( m_UseGC )
    m_GC->SetBrush( brush );
  else
    m_DC->SetBrush( brush );
}

void SymbolRenderer::drawLine(int x, int y, int cx, int cy) {
  if( m_UseGC ) {
    m_GC->StrokeLine( x, y, cx, cy );
  }
  else {
    m_DC->DrawLine( x, y, cx, cy );
  }

}


/**
 * Turntable object
 */
void SymbolRenderer::drawTurntable( wxPaintDC& dc, bool occupied, double* bridgepos, const char* ori ) {

  TraceOp.trc( "render", TRCLEVEL_DEBUG, __LINE__, 9999, "turntable with bridge pos=%f (%d)", *bridgepos, wTurntable.getbridgepos(m_Props) );
  
  // Traverser
  if( wTurntable.istraverser( m_Props ) ) {
    m_bRotateable = true;

    if( m_SvgSym1 != NULL && m_SvgSym2 != NULL && m_SvgSym3 != NULL && m_SvgSym5 != NULL ) {
      // traverser body
      drawSvgSym(dc, m_SvgSym1, ori);

      // bridge
      int pos  = wTurntable.getbridgepos( m_Props );
      int yoff = pos % 24;
      int xoff = 0;

      if( StrOp.equals( wItem.east, ori )) {
        yoff = yoff - 7;
      }
      else if( StrOp.equals( wItem.north, ori )) {
        xoff = yoff;
        yoff = 0;
      }
      else if( StrOp.equals( wItem.south, ori )) {
        xoff = yoff - 7;
        yoff = 0;
      }


      Boolean sensor1 = wTurntable.isstate1( m_Props );
      Boolean sensor2 = wTurntable.isstate2( m_Props );
      TraceOp.trc( "render", TRCLEVEL_INFO, __LINE__, 9999,
          "traverser with bridge pos=%d, yOffset=%d sen1=%d sen2=%d", pos, yoff, sensor1, sensor2 );
      if( sensor1 && sensor2 )
        drawSvgSym(dc, m_SvgSym3, ori, xoff, yoff);
      else if( sensor1 || sensor2 )
        drawSvgSym(dc, m_SvgSym5, ori, xoff, yoff);
      else
        drawSvgSym(dc, m_SvgSym2, ori, xoff, yoff);
    }
    return;
  }

  // Turntable
  wxPen* pen = (wxPen*)wxLIGHT_GREY_PEN;
  pen->SetStyle(wxSHORT_DASH);
  pen->SetWidth(1);

  int ttdiam = wTurntable.getsymbolsize( m_Props );

  if (ttdiam < 1)
    ttdiam = 1;

  if (ttdiam > 13)
    ttdiam = 13;

  double delta = (32 * ttdiam)/2;  /* 79.0; for the original one */

  if( m_UseGC ) {
    setPen( *pen );
    m_GC->DrawEllipse(0, 0, 32 * ttdiam, 32 * ttdiam);
  }
  else {
    setPen( *pen );
    dc.DrawCircle( delta, delta, delta );
  }

  pen->SetStyle(wxSOLID);

  bool matchingTrack = false;
  iONode track = wTurntable.gettrack( m_Props );
  while( track != NULL ) {
    double degr = 7.5 * wTTTrack.getnr( track );
    double a = (degr*2*PI25DT)/360;
    double xa = cos(a) * delta;
    double ya = sin(a) * delta;
    int x = delta + (int)xa;
    int y = delta - (int)ya;

    if( wTTTrack.isstate( track ) || wTurntable.getbridgepos(m_Props) == wTTTrack.getnr(track) ) {
      pen = (wxPen*)wxRED_PEN;
      pen->SetWidth(5);
      setPen( *pen );
      *bridgepos = degr;
      matchingTrack = true;
    }
    else {
      if( (wTurntable.getbridgepos(m_Props) +24) % 48 == wTTTrack.getnr(track) )  /* reb added, condition is true for track opposite of current track */
        pen = (wxPen*)wxGREEN_PEN;  /* reb added the opposite track will be drawn with green*/
      else  /* reb added others with grey*/
        pen = (wxPen*)wxGREY_PEN;
      pen->SetWidth(5);
      setPen( *pen );
    }

    if( wTTTrack.isshow( track ) ) {
      drawLine( delta, delta, x, y );
    }


    track = wTurntable.nexttrack( m_Props, track );
  }

  if( !matchingTrack ) {
    *bridgepos = 7.5 * (double)wTurntable.getbridgepos(m_Props);
  }

  pen = (wxPen*)wxBLACK_PEN;
  pen->SetWidth(2);
  setPen( *pen );

  setBrush(*wxWHITE_BRUSH);
  if( m_UseGC ) {
    m_GC->DrawEllipse(delta - 0.45*delta, delta - 0.45*delta, 0.45*(32*ttdiam), 0.45*(32*ttdiam));
    m_GC->DrawEllipse(delta - 0.40*delta, delta - 0.40*delta, 0.40*(32*ttdiam), 0.40*(32*ttdiam));
    wxPoint* p = rotateBridge( *bridgepos, delta );
    wxGraphicsPath path = m_GC->CreatePath();
    path.MoveToPoint(p[0].x, p[0].y);
    path.AddLineToPoint(p[1].x, p[1].y);
    path.AddLineToPoint(p[2].x, p[2].y);
    path.AddLineToPoint(p[3].x, p[3].y);
    path.AddLineToPoint(p[4].x, p[4].y);
    m_GC->StrokePath(path);
  }
  else {
    dc.DrawCircle( delta, delta, 0.45*delta);
    dc.DrawCircle( delta, delta, 0.40*delta);
    dc.DrawPolygon( 5, rotateBridge( *bridgepos, delta ) );
  }

  const wxBrush& b = dc.GetBrush();
  Boolean sensor1 = wTurntable.isstate1( m_Props );
  Boolean sensor2 = wTurntable.isstate2( m_Props );

  wxBrush* yellow = NULL;

  if( sensor1 && sensor2 ) {
    setBrush( *wxRED_BRUSH );
  }
  else if( sensor1 || sensor2 ) {
    yellow = new wxBrush( _T("yellow"), wxSOLID );
    setBrush( *yellow );
  }
  else {
    setBrush( *wxGREEN_BRUSH );
  }

  if( m_UseGC ) {
    wxPoint* p = rotateBridgeSensors( *bridgepos, delta );
    wxGraphicsPath path = m_GC->CreatePath();
    path.MoveToPoint(p[0].x, p[0].y);
    path.AddLineToPoint(p[1].x, p[1].y);
    path.AddLineToPoint(p[2].x, p[2].y);
    path.AddLineToPoint(p[3].x, p[3].y);
    path.AddLineToPoint(p[4].x, p[4].y);
    m_GC->FillPath(path);

    p = rotateBridgePlus(*bridgepos, delta);
    path = m_GC->CreatePath();
    path.MoveToPoint(p[0].x, p[0].y);
    path.AddLineToPoint(p[1].x, p[1].y);
    path.AddLineToPoint(p[2].x, p[2].y);
    path.AddLineToPoint(p[3].x, p[3].y);
    path.AddLineToPoint(p[4].x, p[4].y);
    pen->SetWidth(1);
    setPen( *pen );
    m_GC->StrokePath(path);
  }
  else {
    dc.DrawPolygon( 5, rotateBridgeSensors( *bridgepos, delta ) );
    pen->SetWidth(1);
    setPen( *pen );
    dc.DrawPolygon( 5, rotateBridgePlus( *bridgepos, delta ) );
    dc.SetBrush( b );
  }

  if( yellow != NULL )
    delete yellow;

  if( m_bShowID ) {
    if (ttdiam >= 5) {
      wxFont* font = setFont(m_iTextps);
      drawString( wxString(m_Label,wxConvUTF8), 5, 5, 0.0, false );
      delete font;
    }
  }
}


/**
 * Draw dispatcher
 */
void SymbolRenderer::drawShape( wxPaintDC& dc, wxGraphicsContext* gc, bool occupied, bool actroute,
    double* bridgepos, bool showID, bool showCounters, const char* ori, int status, bool alt )
{
  m_bShowID = showID;
  m_bShowCounters = showCounters;
  m_bAlt = alt;
  m_DC = &dc;
  const char* nodeName = NodeOp.getName( m_Props );
  m_UseGC = false;
  m_GC = gc;
  if( m_GC != NULL )
    m_UseGC = true;

  if( ori == NULL || StrOp.len( ori ) == 0 )
    ori = wItem.west;

  TraceOp.trc( "render", TRCLEVEL_DEBUG, __LINE__, 9999, "nodename=%s", nodeName );

  switch( m_iSymType ) {
    case symtype::i_track:
      drawTrack( dc, occupied, actroute, ori );
      break;
    case symtype::i_switch:
      drawSwitch( dc, occupied, actroute, ori );
      break;
    case symtype::i_signal:
      drawSignal( dc, occupied, actroute, ori );
      break;
    case symtype::i_output:
      drawOutput( dc, occupied, actroute, ori );
      break;
    case symtype::i_block:
      drawBlock( dc, occupied, ori );
      break;
    case symtype::i_stage:
      drawStage( dc, occupied, ori );
      break;
    case symtype::i_text:
      drawText( dc, occupied, ori );
      break;
    case symtype::i_feedback:
      drawSensor( dc, occupied, actroute, ori );
      break;
    case symtype::i_turntable:
      drawTurntable( dc, occupied, bridgepos, ori );
      break;
    case symtype::i_selecttable:
      drawSelTab( dc, occupied, ori );
      break;
    case symtype::i_route:
      drawRoute( dc, occupied, ori, status );
      break;
  }
}


/**
 * Rotate shape according its orientation
 */
wxPoint* SymbolRenderer::rotateShape( wxPoint* poly, int cnt, const char* oriStr ) {
  static wxPoint p[64];
  double __cos[3] = {0,-1,0};
  double __sin[3] = {1,0,-1};
  enum { north=0, east, south };
  int ori = east;

  if( StrOp.equals( wItem.north, oriStr ) ) {
    ori = north;
  }
  else if( StrOp.equals( wItem.east, oriStr ) ) {
    ori = east;
  }
  else if( StrOp.equals( wItem.south, oriStr ) ) {
    ori = south;
  }
  else {
    // Default ori = west
    return poly;
  }

  for( int i = 0; i < cnt; i++ ) {
    double x1 = 0;
    double y1 = 0;
    double x = poly[i].x;
    double y = poly[i].y;
    x = x - 15.5;
    y = 15.5 - y;
    x1 = (x * __cos[ori]) - (y * __sin[ori]);
    y1 = (x * __sin[ori]) + (y * __cos[ori]);
    p[i].x = (int)(x1 + 15.5);
    p[i].y = (int)(15.5 - y1);
  }

  return p;
}


wxPoint* SymbolRenderer::rotateBridge( double ori, double delta ) {
  TraceOp.trc( "render", TRCLEVEL_DEBUG, __LINE__, 9999, "rotate bridge pos=%f", ori );
  static wxPoint p[5];
  double bp[4] = { 10.0, 170.0, 190.0, 350.0 };

  for( int i = 0; i < 4; i++ ) {
    double angle = ori+bp[i];
    if( angle > 360.0 )
      angle = angle -360.0;
    double a = (angle*2*PI25DT)/360.0;
    double xa = cos(a) * delta*0.4;
    double ya = sin(a) * delta*0.4;
    p[i].x = delta + (int)xa;
    p[i].y = delta - (int)ya;
    if( i == 0 ) {
      // end point to close the polygon
      p[4].x = p[i].x;
      p[4].y = p[i].y;
    }
  }
  return p;
}


wxPoint* SymbolRenderer::rotateBridgeSensors( double ori, double delta ) {
  TraceOp.trc( "render", TRCLEVEL_DEBUG, __LINE__, 9999, "rotate bridge pos=%f", ori );
  static wxPoint p[5];
  double bp[4] = { 10.0, 170.0, 190.0, 350.0 };

  for( int i = 0; i < 4; i++ ) {
    double angle = ori+bp[i];
    if( angle > 360.0 )
      angle = angle -360.0;
    double a = (angle*2*PI25DT)/360.0;
    double xa = cos(a) * delta*0.25;//20.0;
    double ya = sin(a) * delta*0.25;
    p[i].x = delta + (int)xa;
    p[i].y = delta - (int)ya;
    if( i == 0 ) {
      // end point to close the polygon
      p[4].x = p[i].x;
      p[4].y = p[i].y;
    }
  }
  return p;
}


wxPoint* SymbolRenderer::rotateBridgePlus( double ori, double delta ) {
  TraceOp.trc( "render", TRCLEVEL_DEBUG, __LINE__, 9999, "rotate bridge plus ori=%f", ori );
  static wxPoint p[5];

  double xa;
  double ya;
  double xb;
  double yb;
  double xc;
  double yc;
  double yd;
  double xd;
  double xe;
  double ye;
  double xf;
  double yf;
  double alfa;
  double sinalfa;
  double cosalfa;

  ori = 360.0 - ori;

  double center = delta;
  double radius1 = 25.0;  //binnencirkel van vierkantje
  double radius2 = radius1 + 4.0;  //buitencirkel van vierkantje
  double rib = (radius2 - radius1) / 2.0;

  alfa = (ori * PI25DT) / 180.0;
  sinalfa = sin(alfa);
  cosalfa = cos(alfa);

  xa = radius1 * cosalfa;
  ya = radius1 * sinalfa;
  xb = radius2 * cosalfa;
  yb = radius2 * sinalfa;

  xd = xa - rib * sinalfa;
  yd = ya + rib * cosalfa;
  xc = xa + rib * sinalfa;
  yc = ya - rib * cosalfa;

  xe = xb - rib * sinalfa;
  ye = yb + rib * cosalfa;
  xf = xb + rib * sinalfa;
  yf = yb - rib * cosalfa;

  p[0].x = xd + center;
  p[0].y = yd + center;  //rib 1

  p[1].x = xe + center;
  p[1].y = ye + center;  //rib 2

  p[2].x = xf + center;
  p[2].y = yf + center;  //rib 3

  p[3].x = xc + center;
  p[3].y = yc + center;  //rib 4

  // end point to close the polygon
  p[4].x = p[0].x;
  p[4].y = p[0].y;

  return p;
}



