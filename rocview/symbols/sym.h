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
#ifndef SYM_H_
#define SYM_H_

namespace symtype {
  static const int i_track      = 1;
  static const int i_switch     = 2;
  static const int i_signal     = 3;
  static const int i_output     = 4;
  static const int i_block      = 5;
  static const int i_text       = 6;
  static const int i_feedback   = 7;
  static const int i_turntable  = 8;
  static const int i_selecttable= 9;
  static const int i_route      = 10;
  static const int i_stage      = 11;
  static const int i_traverser  = 12;
}

namespace tracktype {
  static const char* straight        = "straight.svg";
  static const char* straight_occ    = "straight-occ.svg";
  static const char* straight_route  = "straight-route.svg";
  static const char* straight_occroute = "straight-occroute.svg";
  static const char* curve           = "curve.svg";
  static const char* curve_occ       = "curve-occ.svg";
  static const char* curve_route     = "curve-route.svg";
  static const char* curve_occroute  = "curve-occroute.svg";
  static const char* dcurve          = "dcurve.svg";
  static const char* dcurve_occ      = "dcurve-occ.svg";
  static const char* dcurve_route    = "dcurve-route.svg";
  static const char* dcurve_occroute = "dcurve-occroute.svg";
  static const char* buffer          = "buffer.svg";
  static const char* buffer_occ      = "buffer-occ.svg";
  static const char* buffer_route    = "buffer-route.svg";
  static const char* dir             = "dir.svg";
  static const char* dir_occ         = "dir-occ.svg";
  static const char* dir_route       = "dir-route.svg";
  static const char* dirall          = "dirall.svg";
  static const char* dirall_occ      = "dirall-occ.svg";
  static const char* dirall_route    = "dirall-route.svg";
  static const char* connector       = "connector.svg";
  static const char* connector_occ   = "connector-occ.svg";
  static const char* connector_route = "connector-route.svg";
  static const char* connector_curve_right       = "connector-curve-right.svg";
  static const char* connector_curve_right_occ   = "connector-curve-right-occ.svg";
  static const char* connector_curve_right_route = "connector-curve-right-route.svg";
  static const char* connector_curve_left        = "connector-curve-left.svg";
  static const char* connector_curve_left_occ    = "connector-curve-left-occ.svg";
  static const char* connector_curve_left_route  = "connector-curve-left-route.svg";

  static const char* road_straight      = "road-straight.svg";
  static const char* road_straight_occ  = "road-straight-occ.svg";
  static const char* road_curve         = "road-curve.svg";
  static const char* road_curve_occ     = "road-curve-occ.svg";
  static const char* road_curve_90      = "road-curve-90.svg";
  static const char* road_curve_occ_90  = "road-curve-occ-90.svg";
  static const char* road_dcurve        = "road-dcurve.svg";
  static const char* road_dcurve_occ    = "road-dcurve-occ.svg";
  static const char* road_dir           = "road-dir.svg";
  static const char* road_dir_occ       = "road-dir-occ.svg";
  static const char* road_dirall        = "road-dirall.svg";

  static const char* tracknr       = "track-%d.svg";
  static const char* tracknr_occ   = "track-%d-occ.svg";
  static const char* tracknr_route = "track-%d-route.svg";

  static const char* curvenr       = "curve-%d.svg";
  static const char* curvenr_occ   = "curve-%d-occ.svg";
  static const char* curvenr_route = "curve-%d-route.svg";

  static const int i_straight    = 1;
  static const int i_curve       = 2;
  static const int i_buffer      = 3;
  static const int i_dir         = 4;
  static const int i_dirall      = 5;
  static const int i_connector   = 6;
  static const int i_tracknr     = 7;
  static const int i_curvenr     = 8;
}

namespace switchtype {
  static const char* ccrossing       = "ccrossing.svg";
  static const char* ccrossing_occ   = "ccrossing-occ.svg";
  static const char* ccrossing_route = "ccrossing-route.svg";
  static const char* crossing       = "crossing.svg";
  static const char* crossing_occ   = "crossing-occ.svg";
  static const char* crossing_route = "crossing-route.svg";
  static const char* crossing_t     = "crossing-t.svg";
  static const char* crossing_t_occ = "crossing-t-occ.svg";
  static const char* crossing_t_route = "crossing-t-route.svg";
  static const char* crossingleft0m = "crossingleft0m.svg";
  static const char* crossingleft0m_occ = "crossingleft0m-occ.svg";
  static const char* crossingleft0m_route = "crossingleft0m-route.svg";
  static const char* crossingright0m = "crossingright0m.svg";
  static const char* crossingright0m_occ = "crossingright0m-occ.svg";
  static const char* crossingright0m_route = "crossingright0m-route.svg";
  static const char* crossingleft   = "crossingleft.svg";
  static const char* crossingleft_t = "crossingleft-t.svg";
  static const char* crossingleft_occ   = "crossingleft-occ.svg";
  static const char* crossingleft_l_occ = "crossingleft-l-occ.svg";
  static const char* crossingleft_route    = "crossingleft-route.svg";
  static const char* crossingleft_b_route  = "crossingleft-b-route.svg";
  static const char* crossingleft_l_route  = "crossingleft-l-route.svg";
  static const char* crossingleft_lb_route = "crossingleft-lb-route.svg";
  static const char* crossingleft_t_occ = "crossingleft-t-occ.svg";
  static const char* crossingleft_t_l_occ = "crossingleft-t-l-occ.svg";
  static const char* crossingleft_t_route = "crossingleft-t-route.svg";
  static const char* crossingleft_t_b_route = "crossingleft-t-b-route.svg";
  static const char* crossingleft_t_l_route = "crossingleft-t-l-route.svg";
  static const char* crossingleft_t_lb_route = "crossingleft-t-lb-route.svg";
  static const char* crossingright   = "crossingright.svg";
  static const char* crossingright_t = "crossingright-t.svg";
  static const char* crossingright_occ   = "crossingright-occ.svg";
  static const char* crossingright_l_occ = "crossingright-l-occ.svg";
  static const char* crossingright_route    = "crossingright-route.svg";
  static const char* crossingright_b_route  = "crossingright-b-route.svg";
  static const char* crossingright_l_route  = "crossingright-l-route.svg";
  static const char* crossingright_lb_route = "crossingright-lb-route.svg";
  static const char* crossingright_t_occ   = "crossingright-t-occ.svg";
  static const char* crossingright_t_l_occ = "crossingright-t-l-occ.svg";
  static const char* crossingright_t_route    = "crossingright-t-route.svg";
  static const char* crossingright_t_b_route  = "crossingright-t-b-route.svg";
  static const char* crossingright_t_l_route  = "crossingright-t-l-route.svg";
  static const char* crossingright_t_lb_route = "crossingright-t-lb-route.svg";

  // raster crossings
  static const char* crossingleft_r_0m = "crossingleft-r-0m.svg";
  static const char* crossingleft_r_0m_occ = "crossingleft-r-0m-occ.svg";
  static const char* crossingleft_r    = "crossingleft-r.svg";
  static const char* crossingleft_r_t  = "crossingleft-r-t.svg";
  static const char* crossingleft_r_occ    = "crossingleft-r-occ.svg";
  static const char* crossingleft_r_t_occ  = "crossingleft-r-t-occ.svg";

  static const char* crossingright_r_0m = "crossingright-r-0m.svg";
  static const char* crossingright_r_0m_occ = "crossingright-r-0m-occ.svg";
  static const char* crossingright_r    = "crossingright-r.svg";
  static const char* crossingright_r_t  = "crossingright-r-t.svg";
  static const char* crossingright_r_occ    = "crossingright-r-occ.svg";
  static const char* crossingright_r_t_occ  = "crossingright-r-t-occ.svg";

  static const char* road_crossing       = "road-crossing.svg";
  static const char* road_ccrossing      = "road-ccrossing.svg";
  static const char* road_crossing_t     = "road-crossing-t.svg";
  static const char* road_crossing90     = "road-crossing90.svg";
  static const char* road_crossing90_t   = "road-crossing90-t.svg";

  static const char* dcrossingleft             = "dcrossingleft.svg";
  static const char* dcrossingleft_t           = "dcrossingleft-t.svg";
  static const char* dcrossingleft_tl          = "dcrossingleft-tl.svg";
  static const char* dcrossingleft_tr          = "dcrossingleft-tr.svg";
  static const char* dcrossingleft_occ         = "dcrossingleft-occ.svg";
  static const char* dcrossingleft_l_occ       = "dcrossingleft-l-occ.svg";
  static const char* dcrossingleft_t_occ       = "dcrossingleft-t-occ.svg";
  static const char* dcrossingleft_t_l_occ     = "dcrossingleft-t-l-occ.svg";
  static const char* dcrossingleft_tl_occ      = "dcrossingleft-tl-occ.svg";
  static const char* dcrossingleft_tl_l_occ    = "dcrossingleft-tl-l-occ.svg";
  static const char* dcrossingleft_tr_occ      = "dcrossingleft-tr-occ.svg";
  static const char* dcrossingleft_tr_l_occ    = "dcrossingleft-tr-l-occ.svg";
  static const char* dcrossingleft_route       = "dcrossingleft-route.svg";
  static const char* dcrossingleft_b_route     = "dcrossingleft-b-route.svg";
  static const char* dcrossingleft_l_route     = "dcrossingleft-l-route.svg";
  static const char* dcrossingleft_lb_route    = "dcrossingleft-lb-route.svg";
  static const char* dcrossingleft_t_route     = "dcrossingleft-t-route.svg";
  static const char* dcrossingleft_t_b_route   = "dcrossingleft-t-b-route.svg";
  static const char* dcrossingleft_t_l_route   = "dcrossingleft-t-l-route.svg";
  static const char* dcrossingleft_t_lb_route  = "dcrossingleft-t-lb-route.svg";
  static const char* dcrossingleft_tl_route    = "dcrossingleft-tl-route.svg";
  static const char* dcrossingleft_tl_b_route  = "dcrossingleft-tl-b-route.svg";
  static const char* dcrossingleft_tl_l_route  = "dcrossingleft-tl-l-route.svg";
  static const char* dcrossingleft_tl_lb_route = "dcrossingleft-tl-lb-route.svg";
  static const char* dcrossingleft_tr_route    = "dcrossingleft-tr-route.svg";
  static const char* dcrossingleft_tr_b_route  = "dcrossingleft-tr-b-route.svg";
  static const char* dcrossingleft_tr_l_route  = "dcrossingleft-tr-l-route.svg";
  static const char* dcrossingleft_tr_lb_route = "dcrossingleft-tr-lb-route.svg";

  static const char* dcrossingright             = "dcrossingright.svg";
  static const char* dcrossingright_t           = "dcrossingright-t.svg";
  static const char* dcrossingright_tl          = "dcrossingright-tl.svg";
  static const char* dcrossingright_tr          = "dcrossingright-tr.svg";
  static const char* dcrossingright_occ         = "dcrossingright-occ.svg";
  static const char* dcrossingright_l_occ       = "dcrossingright-l-occ.svg";
  static const char* dcrossingright_t_occ       = "dcrossingright-t-occ.svg";
  static const char* dcrossingright_t_l_occ     = "dcrossingright-t-l-occ.svg";
  static const char* dcrossingright_tl_occ      = "dcrossingright-tl-occ.svg";
  static const char* dcrossingright_tl_l_occ    = "dcrossingright-tl-l-occ.svg";
  static const char* dcrossingright_tr_occ      = "dcrossingright-tr-occ.svg";
  static const char* dcrossingright_tr_l_occ    = "dcrossingright-tr-l-occ.svg";
  static const char* dcrossingright_route       = "dcrossingright-route.svg";
  static const char* dcrossingright_b_route     = "dcrossingright-b-route.svg";
  static const char* dcrossingright_l_route     = "dcrossingright-l-route.svg";
  static const char* dcrossingright_lb_route    = "dcrossingright-lb-route.svg";
  static const char* dcrossingright_t_route     = "dcrossingright-t-route.svg";
  static const char* dcrossingright_t_b_route   = "dcrossingright-t-b-route.svg";
  static const char* dcrossingright_t_l_route   = "dcrossingright-t-l-route.svg";
  static const char* dcrossingright_t_lb_route  = "dcrossingright-t-lb-route.svg";
  static const char* dcrossingright_tl_route    = "dcrossingright-tl-route.svg";
  static const char* dcrossingright_tl_b_route  = "dcrossingright-tl-b-route.svg";
  static const char* dcrossingright_tl_l_route  = "dcrossingright-tl-l-route.svg";
  static const char* dcrossingright_tl_lb_route = "dcrossingright-tl-lb-route.svg";
  static const char* dcrossingright_tr_route    = "dcrossingright-tr-route.svg";
  static const char* dcrossingright_tr_b_route  = "dcrossingright-tr-b-route.svg";
  static const char* dcrossingright_tr_l_route  = "dcrossingright-tr-l-route.svg";
  static const char* dcrossingright_tr_lb_route = "dcrossingright-tr-lb-route.svg";

  static const char* road_dcrossingright    = "road-dcrossingright.svg";
  static const char* road_dcrossingright_t  = "road-dcrossingright-t.svg";
  static const char* road_dcrossingright_tl = "road-dcrossingright-tl.svg";
  static const char* road_dcrossingright_tr = "road-dcrossingright-tr.svg";

  // raster dcrossings
  static const char* dcrossingleft_r    = "dcrossingleft-r.svg";
  static const char* dcrossingleft_r_t  = "dcrossingleft-r-t.svg";
  static const char* dcrossingleft_r_tl = "dcrossingleft-r-tl.svg";
  static const char* dcrossingleft_r_tr = "dcrossingleft-r-tr.svg";
  static const char* dcrossingleft_r_occ    = "dcrossingleft-r-occ.svg";
  static const char* dcrossingleft_r_t_occ  = "dcrossingleft-r-t-occ.svg";
  static const char* dcrossingleft_r_tl_occ = "dcrossingleft-r-tl-occ.svg";
  static const char* dcrossingleft_r_tr_occ = "dcrossingleft-r-tr-occ.svg";

  static const char* dcrossingright_r    = "dcrossingright-r.svg";
  static const char* dcrossingright_r_t  = "dcrossingright-r-t.svg";
  static const char* dcrossingright_r_tl = "dcrossingright-r-tl.svg";
  static const char* dcrossingright_r_tr = "dcrossingright-r-tr.svg";
  static const char* dcrossingright_r_occ    = "dcrossingright-r-occ.svg";
  static const char* dcrossingright_r_t_occ  = "dcrossingright-r-t-occ.svg";
  static const char* dcrossingright_r_tl_occ = "dcrossingright-r-tl-occ.svg";
  static const char* dcrossingright_r_tr_occ = "dcrossingright-r-tr-occ.svg";

  static const char* threeway          = "threeway.svg";
  static const char* threeway_tl       = "threeway-tl.svg";
  static const char* threeway_tr       = "threeway-tr.svg";
  static const char* threeway_occ      = "threeway-occ.svg";
  static const char* threeway_tl_occ   = "threeway-tl-occ.svg";
  static const char* threeway_tr_occ   = "threeway-tr-occ.svg";
  static const char* threeway_route    = "threeway-route.svg";
  static const char* threeway_tl_route = "threeway-tl-route.svg";
  static const char* threeway_tr_route = "threeway-tr-route.svg";

  static const char* threeway_r       = "threeway-r.svg";
  static const char* threeway_r_tl    = "threeway-r-tl.svg";
  static const char* threeway_r_tr    = "threeway-r-tr.svg";
  static const char* threeway_r_occ    = "threeway-r-occ.svg";
  static const char* threeway_r_tl_occ = "threeway-r-tl-occ.svg";
  static const char* threeway_r_tr_occ = "threeway-r-tr-occ.svg";

  static const char* road_threeway    = "road-threeway.svg";
  static const char* road_threeway_tl = "road-threeway-tl.svg";
  static const char* road_threeway_tr = "road-threeway-tr.svg";

  static const char* road_rect_threeway    = "road-rect-threeway.svg";
  static const char* road_rect_threeway_tl = "road-rect-threeway-tl.svg";
  static const char* road_rect_threeway_tr = "road-rect-threeway-tr.svg";

  static const char* twoway_tr     = "twoway-tr.svg";
  static const char* twoway_tl     = "twoway-tl.svg";
  static const char* twoway_tl_occ = "twoway-tl-occ.svg";
  static const char* twoway_tr_occ = "twoway-tr-occ.svg";
  static const char* twoway_tl_route = "twoway-tl-route.svg";
  static const char* twoway_tr_route = "twoway-tr-route.svg";

  static const char* twoway_r_tr     = "twoway-r-tr.svg";
  static const char* twoway_r_tl     = "twoway-r-tl.svg";
  static const char* twoway_r_tl_occ = "twoway-r-tl-occ.svg";
  static const char* twoway_r_tr_occ = "twoway-r-tr-occ.svg";

  static const char* road_twoway_tr = "road-twoway-tr.svg";
  static const char* road_twoway_tl = "road-twoway-tl.svg";

  static const char* decoupler        = "decoupler.svg";
  static const char* decoupler_on     = "decoupler-on.svg";
  static const char* decoupler_occ    = "decoupler-occ.svg";
  static const char* decoupler_on_occ = "decoupler-on-occ.svg";
  static const char* decoupler_route        = "decoupler-route.svg";
  static const char* decoupler_on_route     = "decoupler-on-route.svg";
  static const char* decoupler_occ_route    = "decoupler-occ-route.svg";
  static const char* decoupler_on_occ_route = "decoupler-on-occ-route.svg";

  static const char* vturnout    = "vturnout.svg";
  static const char* vturnout_t  = "vturnout-t.svg";

  static const char* turnoutleft            = "turnoutleft.svg";
  static const char* turnoutleft_t          = "turnoutleft-t.svg";
  static const char* turnoutleft_occ        = "turnoutleft-occ.svg";
  static const char* turnoutleft_l_occ      = "turnoutleft-l-occ.svg";
  static const char* turnoutleft_t_occ      = "turnoutleft-t-occ.svg";
  static const char* turnoutleft_t_l_occ    = "turnoutleft-t-l-occ.svg";
  static const char* turnoutleft_route      = "turnoutleft-route.svg";
  static const char* turnoutleft_b_route    = "turnoutleft-b-route.svg";
  static const char* turnoutleft_l_route    = "turnoutleft-l-route.svg";
  static const char* turnoutleft_lb_route   = "turnoutleft-lb-route.svg";
  static const char* turnoutleft_t_route    = "turnoutleft-t-route.svg";
  static const char* turnoutleft_t_b_route  = "turnoutleft-t-b-route.svg";
  static const char* turnoutleft_t_l_route  = "turnoutleft-t-l-route.svg";
  static const char* turnoutleft_t_lb_route = "turnoutleft-t-lb-route.svg";

  static const char* turnoutright            = "turnoutright.svg";
  static const char* turnoutright_t          = "turnoutright-t.svg";
  static const char* turnoutright_occ        = "turnoutright-occ.svg";
  static const char* turnoutright_l_occ      = "turnoutright-l-occ.svg";
  static const char* turnoutright_t_occ      = "turnoutright-t-occ.svg";
  static const char* turnoutright_t_l_occ    = "turnoutright-t-l-occ.svg";
  static const char* turnoutright_route      = "turnoutright-route.svg";
  static const char* turnoutright_b_route    = "turnoutright-b-route.svg";
  static const char* turnoutright_l_route    = "turnoutright-l-route.svg";
  static const char* turnoutright_lb_route   = "turnoutright-lb-route.svg";
  static const char* turnoutright_t_route    = "turnoutright-t-route.svg";
  static const char* turnoutright_t_b_route  = "turnoutright-t-b-route.svg";
  static const char* turnoutright_t_l_route  = "turnoutright-t-l-route.svg";
  static const char* turnoutright_t_lb_route = "turnoutright-t-lb-route.svg";

  static const char* road_turnoutleft    = "road-turnoutleft.svg";
  static const char* road_turnoutleft_t  = "road-turnoutleft-t.svg";

  static const char* road_turnoutright   = "road-turnoutright.svg";
  static const char* road_turnoutright_t = "road-turnoutright-t.svg";

  // Raster turnouts
  static const char* turnoutleft_r            = "turnoutleft-r.svg";
  static const char* turnoutleft_r_t          = "turnoutleft-r-t.svg";
  static const char* turnoutleft_r_occ        = "turnoutleft-r-occ.svg";
  static const char* turnoutleft_r_l_occ      = "turnoutleft-r-l-occ.svg";
  static const char* turnoutleft_r_t_occ      = "turnoutleft-r-t-occ.svg";
  static const char* turnoutleft_r_t_l_occ    = "turnoutleft-r-t-l-occ.svg";
  static const char* turnoutleft_r_route      = "turnoutleft-r-route.svg";
  static const char* turnoutleft_r_b_route    = "turnoutleft-r-b-route.svg";
  static const char* turnoutleft_r_l_route    = "turnoutleft-r-l-route.svg";
  static const char* turnoutleft_r_lb_route   = "turnoutleft-r-lb-route.svg";
  static const char* turnoutleft_r_t_route    = "turnoutleft-r-t-route.svg";
  static const char* turnoutleft_r_t_b_route  = "turnoutleft-r-t-b-route.svg";
  static const char* turnoutleft_r_t_l_route  = "turnoutleft-r-t-l-route.svg";
  static const char* turnoutleft_r_t_lb_route = "turnoutleft-r-t-lb-route.svg";

  static const char* turnoutright_r            = "turnoutright-r.svg";
  static const char* turnoutright_r_t          = "turnoutright-r-t.svg";
  static const char* turnoutright_r_occ        = "turnoutright-r-occ.svg";
  static const char* turnoutright_r_l_occ      = "turnoutright-r-l-occ.svg";
  static const char* turnoutright_r_t_occ      = "turnoutright-r-t-occ.svg";
  static const char* turnoutright_r_t_l_occ    = "turnoutright-r-t-l-occ.svg";
  static const char* turnoutright_r_route      = "turnoutright-r-route.svg";
  static const char* turnoutright_r_b_route    = "turnoutright-r-b-route.svg";
  static const char* turnoutright_r_l_route    = "turnoutright-r-l-route.svg";
  static const char* turnoutright_r_lb_route   = "turnoutright-r-lb-route.svg";
  static const char* turnoutright_r_t_route    = "turnoutright-r-t-route.svg";
  static const char* turnoutright_r_t_b_route  = "turnoutright-r-t-b-route.svg";
  static const char* turnoutright_r_t_l_route  = "turnoutright-r-t-l-route.svg";
  static const char* turnoutright_r_t_lb_route = "turnoutright-r-t-lb-route.svg";

  // Accessory
  static const char* accessory_on  = "accessory-%d-on.svg";
  static const char* accessory_off = "accessory-%d-off.svg";
  static const char* accessory_on_occ  = "accessory-%d-on-occ.svg";
  static const char* accessory_off_occ = "accessory-%d-off-occ.svg";
  static const char* accessory_on_route  = "accessory-%d-on-route.svg";
  static const char* accessory_off_route = "accessory-%d-off-route.svg";

  static const int i_crossing       = 1;
  static const int i_dcrossingleft  = 2;
  static const int i_dcrossingright = 3;
  static const int i_decoupler      = 4;
  static const int i_turnoutleft    = 5;
  static const int i_turnoutright   = 6;
  static const int i_threeway       = 7;
  static const int i_crossingleft   = 8;
  static const int i_crossingright  = 9;
  static const int i_ccrossing      = 10;
  static const int i_accessory      = 11;
  static const int i_twoway         = 12;
}

namespace signaltype {
  static const char* signalaspect       = "%ssignalaspect-%d.svg";
  static const char* signalaspect_occ   = "%ssignalaspect-%d-occ.svg";
  static const char* signalaspect_route = "%ssignalaspect-%d-route.svg";

  static const char* blockstate = "blockstate.svg";

  static const char* signalmain_r = "signalmain-r.svg";
  static const char* signalmain_y = "signalmain-y.svg";
  static const char* signalmain_g = "signalmain-g.svg";
  static const char* signalmain_w = "signalmain-w.svg";
  static const char* signalmain_b = "signalmain-b.svg";
  static const char* signalmain_r_occ = "signalmain-r-occ.svg";
  static const char* signalmain_y_occ = "signalmain-y-occ.svg";
  static const char* signalmain_g_occ = "signalmain-g-occ.svg";
  static const char* signalmain_w_occ = "signalmain-w-occ.svg";
  static const char* signalmain_b_occ = "signalmain-b-occ.svg";
  static const char* signalmain_r_route = "signalmain-r-route.svg";
  static const char* signalmain_y_route = "signalmain-y-route.svg";
  static const char* signalmain_g_route = "signalmain-g-route.svg";
  static const char* signalmain_w_route = "signalmain-w-route.svg";
  static const char* signalmain_b_route = "signalmain-b-route.svg";

  static const char* road_signalmain_r = "road-signalmain-r.svg";
  static const char* road_signalmain_y = "road-signalmain-y.svg";
  static const char* road_signalmain_g = "road-signalmain-g.svg";
  static const char* road_signalmain_r_occ = "road-signalmain-r-occ.svg";
  static const char* road_signalmain_y_occ = "road-signalmain-y-occ.svg";
  static const char* road_signalmain_g_occ = "road-signalmain-g-occ.svg";

  static const char* signalmain_dwarf_r = "signalmain-dwarf-r.svg";
  static const char* signalmain_dwarf_y = "signalmain-dwarf-y.svg";
  static const char* signalmain_dwarf_g = "signalmain-dwarf-g.svg";
  static const char* signalmain_dwarf_w = "signalmain-dwarf-w.svg";
  static const char* signalmain_dwarf_r_occ = "signalmain-dwarf-r-occ.svg";
  static const char* signalmain_dwarf_y_occ = "signalmain-dwarf-y-occ.svg";
  static const char* signalmain_dwarf_g_occ = "signalmain-dwarf-g-occ.svg";
  static const char* signalmain_dwarf_w_occ = "signalmain-dwarf-w-occ.svg";
  static const char* signalmain_dwarf_r_route = "signalmain-dwarf-r-route.svg";
  static const char* signalmain_dwarf_y_route = "signalmain-dwarf-y-route.svg";
  static const char* signalmain_dwarf_g_route = "signalmain-dwarf-g-route.svg";
  static const char* signalmain_dwarf_w_route = "signalmain-dwarf-w-route.svg";

  static const char* road_signalmain_dwarf_r = "road-signalmain-dwarf-r.svg";
  static const char* road_signalmain_dwarf_y = "road-signalmain-dwarf-y.svg";
  static const char* road_signalmain_dwarf_g = "road-signalmain-dwarf-g.svg";

  static const char* signaldistant_r = "signaldistant-r.svg";
  static const char* signaldistant_y = "signaldistant-y.svg";
  static const char* signaldistant_g = "signaldistant-g.svg";
  static const char* signaldistant_w = "signaldistant-w.svg";
  static const char* signaldistant_b = "signaldistant-b.svg";
  static const char* signaldistant_r_occ = "signaldistant-r-occ.svg";
  static const char* signaldistant_y_occ = "signaldistant-y-occ.svg";
  static const char* signaldistant_g_occ = "signaldistant-g-occ.svg";
  static const char* signaldistant_w_occ = "signaldistant-w-occ.svg";
  static const char* signaldistant_b_occ = "signaldistant-b-occ.svg";
  static const char* signaldistant_r_route = "signaldistant-r-route.svg";
  static const char* signaldistant_y_route = "signaldistant-y-route.svg";
  static const char* signaldistant_g_route = "signaldistant-g-route.svg";
  static const char* signaldistant_w_route = "signaldistant-w-route.svg";
  static const char* signaldistant_b_route = "signaldistant-b-route.svg";

  static const char* semaphoremain_r = "semaphoremain-r.svg";
  static const char* semaphoremain_y = "semaphoremain-y.svg";
  static const char* semaphoremain_g = "semaphoremain-g.svg";
  static const char* semaphoremain_w = "semaphoremain-w.svg";
  static const char* semaphoremain_r_occ = "semaphoremain-r-occ.svg";
  static const char* semaphoremain_y_occ = "semaphoremain-y-occ.svg";
  static const char* semaphoremain_g_occ = "semaphoremain-g-occ.svg";
  static const char* semaphoremain_w_occ = "semaphoremain-w-occ.svg";
  static const char* semaphoremain_r_route = "semaphoremain-r-route.svg";
  static const char* semaphoremain_y_route = "semaphoremain-y-route.svg";
  static const char* semaphoremain_g_route = "semaphoremain-g-route.svg";
  static const char* semaphoremain_w_route = "semaphoremain-w-route.svg";

  static const char* semaphoredistant_r = "semaphoredistant-r.svg";
  static const char* semaphoredistant_y = "semaphoredistant-y.svg";
  static const char* semaphoredistant_g = "semaphoredistant-g.svg";
  static const char* semaphoredistant_w = "semaphoredistant-w.svg";
  static const char* semaphoredistant_r_occ = "semaphoredistant-r-occ.svg";
  static const char* semaphoredistant_y_occ = "semaphoredistant-y-occ.svg";
  static const char* semaphoredistant_g_occ = "semaphoredistant-g-occ.svg";
  static const char* semaphoredistant_w_occ = "semaphoredistant-w-occ.svg";
  static const char* semaphoredistant_r_route = "semaphoredistant-r-route.svg";
  static const char* semaphoredistant_y_route = "semaphoredistant-y-route.svg";
  static const char* semaphoredistant_g_route = "semaphoredistant-g-route.svg";
  static const char* semaphoredistant_w_route = "semaphoredistant-w-route.svg";

  // two aspects
  static const char* signalmain_2_r = "signalmain-2-r.svg";
  static const char* signalmain_2_g = "signalmain-2-g.svg";
  static const char* signalmain_2_r_occ = "signalmain-2-r-occ.svg";
  static const char* signalmain_2_g_occ = "signalmain-2-g-occ.svg";
  static const char* signalmain_2_r_route = "signalmain-2-r-route.svg";
  static const char* signalmain_2_g_route = "signalmain-2-g-route.svg";

  static const char* signaldistant_2_r = "signaldistant-2-r.svg";
  static const char* signaldistant_2_g = "signaldistant-2-g.svg";
  static const char* signaldistant_2_r_occ = "signaldistant-2-r-occ.svg";
  static const char* signaldistant_2_g_occ = "signaldistant-2-g-occ.svg";
  static const char* signaldistant_2_r_route = "signaldistant-2-r-route.svg";
  static const char* signaldistant_2_g_route = "signaldistant-2-g-route.svg";

  static const char* signalshunting_2_r = "signalshunting-2-r.svg";
  static const char* signalshunting_2_w = "signalshunting-2-w.svg";
  static const char* signalshunting_2_r_occ = "signalshunting-2-r-occ.svg";
  static const char* signalshunting_2_w_occ = "signalshunting-2-w-occ.svg";
  static const char* signalshunting_2_r_route = "signalshunting-2-r-route.svg";
  static const char* signalshunting_2_w_route = "signalshunting-2-w-route.svg";

  static const char* semaphoremain_2_r = "semaphoremain-2-r.svg";
  static const char* semaphoremain_2_g = "semaphoremain-2-g.svg";
  static const char* semaphoremain_2_r_occ = "semaphoremain-2-r-occ.svg";
  static const char* semaphoremain_2_g_occ = "semaphoremain-2-g-occ.svg";
  static const char* semaphoremain_2_r_route = "semaphoremain-2-r-route.svg";
  static const char* semaphoremain_2_g_route = "semaphoremain-2-g-route.svg";

  static const char* semaphoredistant_2_r = "semaphoredistant-2-r.svg";
  static const char* semaphoredistant_2_g = "semaphoredistant-2-g.svg";
  static const char* semaphoredistant_2_r_occ = "semaphoredistant-2-r-occ.svg";
  static const char* semaphoredistant_2_g_occ = "semaphoredistant-2-g-occ.svg";
  static const char* semaphoredistant_2_r_route = "semaphoredistant-2-r-route.svg";
  static const char* semaphoredistant_2_g_route = "semaphoredistant-2-g-route.svg";

  static const char* semaphoreshunting_2_r = "semaphoreshunting-2-r.svg";
  static const char* semaphoreshunting_2_w = "semaphoreshunting-2-w.svg";
  static const char* semaphoreshunting_2_r_occ = "semaphoreshunting-2-r-occ.svg";
  static const char* semaphoreshunting_2_w_occ = "semaphoreshunting-2-w-occ.svg";
  static const char* semaphoreshunting_2_r_route = "semaphoreshunting-2-r-route.svg";
  static const char* semaphoreshunting_2_w_route = "semaphoreshunting-2-w-route.svg";

  static const int i_signalmain        = 1;
  static const int i_signaldistant     = 2;
  static const int i_semaphoremain     = 3;
  static const int i_semaphoredistant  = 4;
  static const int i_signalshunting    = 5;
  static const int i_semaphoreshunting = 6;
  static const int i_signalaspect      = 7;
}

namespace outputtype {
  static const char* button  = "button-0-off.svg";
  static const char* button_on  = "button-%d-on.svg";
  static const char* button_off = "button-%d-off.svg";
  static const char* button_active = "button-%d-active.svg";
  static const char* button_on_occ  = "button-%d-on-occ.svg";
  static const char* button_off_occ = "button-%d-off-occ.svg";
  static const char* button_active_occ = "button-%d-active-occ.svg";
  static const char* button_on_route  = "button-%d-on-route.svg";
  static const char* button_off_route = "button-%d-off-route.svg";
  static const char* button_active_route = "button-%d-active-route.svg";

  static const int i_button = 1;
}

namespace routetype {
  static const char* route_free       = "route-free.svg";
  static const char* route_locked     = "route-locked.svg";
  static const char* route_selected   = "route-selected.svg";
  static const char* route_deselected = "route-deselected.svg";
  static const char* route_closed     = "route-closed.svg";

  static const int i_route = 1;
}

namespace blocktype {
  static const char* block        = "block.svg";
  static const char* block_occ    = "block-occ.svg";
  static const char* block_res    = "block-res.svg";
  static const char* block_ent    = "block-ent.svg";
  static const char* block_closed = "block-closed.svg";
  static const char* block_ghost  = "block-ghost.svg";
  static const char* block_sc     = "block-sc.svg";
  static const char* block_s        = "block-s.svg";
  static const char* block_occ_s    = "block-occ-s.svg";
  static const char* block_res_s    = "block-res-s.svg";
  static const char* block_ent_s    = "block-ent-s.svg";
  static const char* block_closed_s = "block-closed-s.svg";
  static const char* block_ghost_s  = "block-ghost-s.svg";
  static const char* block_sc_s     = "block-sc-s.svg";

  static const char* block_aident     = "block-aident.svg";
  static const char* block_aident_s   = "block-aident-s.svg";

  static const char* road_block     = "road-block.svg";
  static const char* road_block_occ = "road-block-occ.svg";
  static const char* road_block_res = "road-block-res.svg";
  static const char* road_block_ent = "road-block-ent.svg";
  static const char* road_block_s     = "road-block-s.svg";
  static const char* road_block_occ_s = "road-block-occ-s.svg";
  static const char* road_block_res_s = "road-block-res-s.svg";
  static const char* road_block_ent_s = "road-block-ent-s.svg";

  static const int i_block = 1;
}

namespace stagetype {
  static const char* stage     = "stage.svg";
  static const char* stage_occ = "stage-occ.svg";
  static const char* stage_res = "stage-res.svg";
  static const char* stage_ent = "stage-ent.svg";
  static const char* stage_closed = "stage-closed.svg";
  static const char* stage_ghost  = "stage-ghost.svg";

  static const int i_stage = 1;
}

namespace traversertype {
  static const char* traverser            = "traverser.svg";
  static const char* traverser_bridge     = "traverser-bridge.svg";
  static const char* traverser_bridge_occ = "traverser-bridge-occ.svg";
  static const char* traverser_bridge_res = "traverser-bridge-res.svg";
  static const char* traverser_bridge_ent = "traverser-bridge-ent.svg";

  static const int i_traverser = 1;
}

namespace seltabtype {
  static const char* seltab     = "seltab.svg";
  static const char* seltab_occ = "seltab-occ.svg";
  static const char* seltab_res = "seltab-res.svg";
  static const int i_seltab = 1;
}

namespace turntabletype {
  static const char* turntable = "turntable.svg";
  static const int i_turntable = 1;
}

namespace texttype {
  static const char* text = "text.svg";

  static const int i_text = 1;
}

namespace feedbacktype {
  static const char* sensor_on  = "sensor-on.svg";
  static const char* sensor_off = "sensor-off.svg";
  static const char* sensor_on_occ  = "sensor-on-occ.svg";
  static const char* sensor_off_occ = "sensor-off-occ.svg";
  static const char* sensor_on_route  = "sensor-on-route.svg";
  static const char* sensor_off_route = "sensor-off-route.svg";
  static const char* sensor_cnt  = "sensor-cnt.svg";

  static const char* road_sensor_on  = "road-sensor-on.svg";
  static const char* road_sensor_off = "road-sensor-off.svg";
  static const char* road_sensor_on_occ  = "road-sensor-on-occ.svg";
  static const char* road_sensor_off_occ = "road-sensor-off-occ.svg";

  static const char* curve_sensor_on  = "curve-sensor-on.svg";
  static const char* curve_sensor_off = "curve-sensor-off.svg";
  static const char* curve_sensor_on_occ  = "curve-sensor-on-occ.svg";
  static const char* curve_sensor_off_occ = "curve-sensor-off-occ.svg";
  static const char* curve_sensor_on_route  = "curve-sensor-on-route.svg";
  static const char* curve_sensor_off_route = "curve-sensor-off-route.svg";
  static const char* curve_sensor_cnt  = "curve-sensor-cnt.svg";
  // Accessory
  static const char* accessory_on  = "accessory-%d-on.svg";
  static const char* accessory_off = "accessory-%d-off.svg";
  static const char* accessory_on_occ  = "accessory-%d-on-occ.svg";
  static const char* accessory_off_occ = "accessory-%d-off-occ.svg";
  static const char* accessory_on_route  = "accessory-%d-on-route.svg";
  static const char* accessory_off_route = "accessory-%d-off-route.svg";


  static const int i_sensor = 1;
  static const int i_accessory = 2;
}


#endif /*SYM_H_*/
