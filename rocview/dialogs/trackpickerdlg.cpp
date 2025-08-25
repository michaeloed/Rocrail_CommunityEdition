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

#include "trackpickerdlg.h"
#include "rocview/public/guiapp.h"
#include "rocview/public/cellrenderer.h"
#include "rocview/res/icons.hpp"
#include "rocview/symbols/sym.h"

#include "rocrail/wrapper/public/Track.h"
#include "rocrail/wrapper/public/Switch.h"
#include "rocrail/wrapper/public/Signal.h"
#include "rocrail/wrapper/public/Block.h"
#include "rocrail/wrapper/public/Stage.h"
#include "rocrail/wrapper/public/Feedback.h"
#include "rocrail/wrapper/public/Output.h"
#include "rocrail/wrapper/public/SelTab.h"
#include "rocrail/wrapper/public/Turntable.h"
#include "rocrail/wrapper/public/Text.h"

#include "rocview/wrapper/public/Gui.h"
#include "rocview/wrapper/public/Window.h"

#include "rocs/public/strtok.h"

#include <wx/dnd.h>
/* ToDo: Check this code in the TrackPickerDlgGen class and disable the last line:
 *
  #ifndef __WXGTK__ // Small icon style not supported in GTK
  wxListView* m_TrackBookListView = m_TrackBook->GetListView();
  long m_TrackBookFlags = m_TrackBookListView->GetWindowStyleFlag();
  m_TrackBookFlags = ( m_TrackBookFlags & ~wxLC_ICON ) | wxLC_SMALL_ICON;
  //m_TrackBookListView->SetWindowStyleFlag( m_TrackBookFlags ); // This will assert on Windows and OSX!
  #endif
 */


TrackPickerDlg::TrackPickerDlg( wxWindow* parent ):TrackPickerDlgGen( parent )
{

  m_GridTrack->EnableEditing(false);
  m_GridTrack->EnableDragGridSize(false);
  m_GridTrack->ClearGrid();
  m_GridTrack->DeleteRows( 0, m_GridTrack->GetNumberRows() );
  m_GridTrack->SetDefaultCellTextColour(*wxWHITE);

  int itemidps = 7;
  int textps =  m_GridTrack->GetDefaultCellFont().GetPointSize();
  m_Renderer = new SymbolRenderer( NULL, this, wxGetApp().getFrame()->getSymMap(), itemidps, textps, wxGetApp().getFrame()->getScale() );


  m_GridSwitch->EnableEditing(false);
  m_GridSwitch->EnableDragGridSize(false);
  m_GridSwitch->ClearGrid();
  m_GridSwitch->DeleteRows( 0, m_GridSwitch->GetNumberRows() );
  m_GridSwitch->SetDefaultCellTextColour(*wxWHITE);

  m_GridSignal->EnableEditing(false);
  m_GridSignal->EnableDragGridSize(false);
  m_GridSignal->ClearGrid();
  m_GridSignal->DeleteRows( 0, m_GridSignal->GetNumberRows() );
  m_GridSignal->SetDefaultCellTextColour(*wxWHITE);

  m_GridBlock->EnableEditing(false);
  m_GridBlock->EnableDragGridSize(false);
  m_GridBlock->ClearGrid();
  m_GridBlock->DeleteRows( 0, m_GridBlock->GetNumberRows() );
  m_GridBlock->SetDefaultCellTextColour(*wxWHITE);

  m_GridSensor->EnableEditing(false);
  m_GridSensor->EnableDragGridSize(false);
  m_GridSensor->ClearGrid();
  m_GridSensor->DeleteRows( 0, m_GridSensor->GetNumberRows() );
  m_GridSensor->SetDefaultCellTextColour(*wxWHITE);

  m_GridAccessory->EnableEditing(false);
  m_GridAccessory->EnableDragGridSize(false);
  m_GridAccessory->ClearGrid();
  m_GridAccessory->DeleteRows( 0, m_GridAccessory->GetNumberRows() );
  m_GridAccessory->SetDefaultCellTextColour(*wxWHITE);

  m_GridRoad->EnableEditing(false);
  m_GridRoad->EnableDragGridSize(false);
  m_GridRoad->ClearGrid();
  m_GridRoad->DeleteRows( 0, m_GridRoad->GetNumberRows() );
  m_GridRoad->SetDefaultCellTextColour(*wxWHITE);

  initSymbols();

  m_TrackBook->SetPageText( 0, wxGetApp().getMsg( "track" ) );
  m_TrackBook->SetPageText( 1, wxGetApp().getMsg( "turnout" ) );
  m_TrackBook->SetPageText( 2, wxGetApp().getMsg( "signal" ) );
  m_TrackBook->SetPageText( 3, wxGetApp().getMsg( "block" ) );
  m_TrackBook->SetPageText( 4, wxGetApp().getMsg( "sensor" ) );
  m_TrackBook->SetPageText( 5, wxGetApp().getMsg( "accessory" ) );
  m_TrackBook->SetPageText( 6, wxGetApp().getMsg( "road" ) );
  SetTitle( wxGetApp().getMsg("additem") );

  m_TrackBook->SetSelection(0);
  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);
}


void TrackPickerDlg::initGrid() {
  for( int i = 0; i < ListOp.size(m_SymbolList); i++) {
    char* symbol = (char*)ListOp.get(m_SymbolList, i);
    iOStrTok tok = StrTokOp.inst(symbol, ',');
    const char* symname = StrTokOp.nextToken(tok);
    const char* svg     = StrTokOp.nextToken(tok);
    const char* tip     = NULL;

    if( StrTokOp.hasMoreTokens(tok) )
      tip = StrTokOp.nextToken(tok);

    if( StrOp.find( symname, "road" ) != NULL ) {
      if( m_Renderer->hasSVG(svg ) ) {
        m_GridRoad->AppendRows();
        TraceOp.trc( "trackpicker", TRCLEVEL_DEBUG, __LINE__, 9999, "row: %d %s %s", m_GridRoad->GetNumberRows(), symname, svg );
        m_GridRoad->SetCellValue(m_GridRoad->GetNumberRows()-1, 0, wxString(symname,wxConvUTF8) );
        m_GridRoad->SetCellRenderer(m_GridRoad->GetNumberRows()-1, 0, new CellRenderer(svg, m_Renderer, wxGetApp().getFrame()->getScale(), tip) );
      }
    }
    else if( StrOp.startsWith( symname, wTrack.name() ) ) {
      if( m_Renderer->hasSVG(svg ) ) {
        m_GridTrack->AppendRows();
        TraceOp.trc( "trackpicker", TRCLEVEL_DEBUG, __LINE__, 9999, "row: %d %s %s", m_GridTrack->GetNumberRows(), symname, svg );
        m_GridTrack->SetCellValue(m_GridTrack->GetNumberRows()-1, 0, wxString(symname,wxConvUTF8) );
        m_GridTrack->SetCellRenderer(m_GridTrack->GetNumberRows()-1, 0, new CellRenderer(svg, m_Renderer, wxGetApp().getFrame()->getScale(), tip) );
      }
    }
    else if( StrOp.startsWith( symname, wSwitch.name() ) ) {
      if( StrOp.find( symname, wSwitch.accessory ) != NULL ) {
        if( m_Renderer->hasSVG(svg ) ) {
          m_GridAccessory->AppendRows();
          TraceOp.trc( "trackpicker", TRCLEVEL_DEBUG, __LINE__, 9999, "row: %d %s %s", m_GridAccessory->GetNumberRows(), symname, svg );
          m_GridAccessory->SetCellValue(m_GridAccessory->GetNumberRows()-1, 0, wxString(symname,wxConvUTF8) );
          m_GridAccessory->SetCellRenderer(m_GridAccessory->GetNumberRows()-1, 0, new CellRenderer(svg, m_Renderer, wxGetApp().getFrame()->getScale(), tip) );
        }
      }
      else {
        if( m_Renderer->hasSVG(svg ) ) {
          m_GridSwitch->AppendRows();
          TraceOp.trc( "trackpicker", TRCLEVEL_DEBUG, __LINE__, 9999, "row: %d %s %s", m_GridSwitch->GetNumberRows(), symname, svg );
          m_GridSwitch->SetCellValue(m_GridSwitch->GetNumberRows()-1, 0, wxString(symname,wxConvUTF8) );
          m_GridSwitch->SetCellRenderer(m_GridSwitch->GetNumberRows()-1, 0, new CellRenderer(svg, m_Renderer, wxGetApp().getFrame()->getScale(), tip) );
        }
      }
    }
    else if( StrOp.startsWith( symname, wSignal.name() ) ) {
      if( m_Renderer->hasSVG(svg ) ) {
        m_GridSignal->AppendRows();
        TraceOp.trc( "trackpicker", TRCLEVEL_DEBUG, __LINE__, 9999, "row: %d %s %s", m_GridSignal->GetNumberRows(), symname, svg );
        m_GridSignal->SetCellValue(m_GridSignal->GetNumberRows()-1, 0, wxString(symname,wxConvUTF8) );
        m_GridSignal->SetCellRenderer(m_GridSignal->GetNumberRows()-1, 0, new CellRenderer(svg, m_Renderer, wxGetApp().getFrame()->getScale(), tip) );
      }
    }
    else if( StrOp.startsWith( symname, wOutput.name() ) ) {
      if( m_Renderer->hasSVG(svg ) ) {
        m_GridAccessory->AppendRows();
        TraceOp.trc( "trackpicker", TRCLEVEL_DEBUG, __LINE__, 9999, "row: %d %s %s", m_GridAccessory->GetNumberRows(), symname, svg );
        m_GridAccessory->SetCellValue(m_GridAccessory->GetNumberRows()-1, 0, wxString(symname,wxConvUTF8) );
        m_GridAccessory->SetCellRenderer(m_GridAccessory->GetNumberRows()-1, 0, new CellRenderer(svg, m_Renderer, wxGetApp().getFrame()->getScale(), tip) );
      }
    }
    else if( StrOp.startsWith( symname, wText.name() ) ) {
      m_GridAccessory->AppendRows();
      TraceOp.trc( "trackpicker", TRCLEVEL_DEBUG, __LINE__, 9999, "row: %d %s %s", m_GridAccessory->GetNumberRows(), symname, svg );
      m_GridAccessory->SetCellValue(m_GridAccessory->GetNumberRows()-1, 0, wxString(symname,wxConvUTF8) );
      m_GridAccessory->SetCellRenderer(m_GridAccessory->GetNumberRows()-1, 0, new CellRenderer(svg, m_Renderer, wxGetApp().getFrame()->getScale(), tip) );
    }
    else if( StrOp.startsWith( symname, wBlock.name() ) || StrOp.startsWith( symname, wStage.name() ) ||
        StrOp.startsWith( symname, wSelTab.name() ) || StrOp.startsWith( symname, wTurntable.name() ) )
    {
      if( m_Renderer->hasSVG(svg ) ) {
        m_GridBlock->AppendRows();
        TraceOp.trc( "trackpicker", TRCLEVEL_DEBUG, __LINE__, 9999, "row: %d %s %s", m_GridBlock->GetNumberRows(), symname, svg );
        m_GridBlock->SetCellValue(m_GridBlock->GetNumberRows()-1, 0, wxString(symname,wxConvUTF8) );
        m_GridBlock->SetCellRenderer(m_GridBlock->GetNumberRows()-1, 0, new CellRenderer(svg, m_Renderer, wxGetApp().getFrame()->getScale(), tip) );
      }
    }
    else if( StrOp.startsWith( symname, wFeedback.name() ) )
    {
      if( m_Renderer->hasSVG(svg ) ) {
        m_GridSensor->AppendRows();
        TraceOp.trc( "trackpicker", TRCLEVEL_DEBUG, __LINE__, 9999, "row: %d %s %s", m_GridSensor->GetNumberRows(), symname, svg );
        m_GridSensor->SetCellValue(m_GridSensor->GetNumberRows()-1, 0, wxString(symname,wxConvUTF8) );
        m_GridSensor->SetCellRenderer(m_GridSensor->GetNumberRows()-1, 0, new CellRenderer(svg, m_Renderer, wxGetApp().getFrame()->getScale(), tip) );
      }
    }
    tok->base.del(tok);
  }

  m_GridTrack->AutoSizeColumns();
  m_GridTrack->AutoSizeRows();
  m_GridSwitch->AutoSizeColumns();
  m_GridSwitch->AutoSizeRows();
  m_GridSignal->AutoSizeColumns();
  m_GridSignal->AutoSizeRows();
  m_GridBlock->AutoSizeColumns();
  m_GridBlock->AutoSizeRows();
  m_GridSensor->AutoSizeColumns();
  m_GridSensor->AutoSizeRows();
  m_GridAccessory->AutoSizeColumns();
  m_GridAccessory->AutoSizeRows();
  m_GridRoad->AutoSizeColumns();
  m_GridRoad->AutoSizeRows();

  m_GridTrack->ForceRefresh();
  m_GridSwitch->ForceRefresh();
  m_GridSignal->ForceRefresh();
  m_GridBlock->ForceRefresh();
  m_GridSensor->ForceRefresh();
  m_GridAccessory->ForceRefresh();
  m_GridRoad->ForceRefresh();
}


void TrackPickerDlg::initSymbols() {
  m_SymbolList = ListOp.inst();

  // Track
  char* symname = StrOp.fmt("%s:%s::::,%s,%s", wTrack.name(), wTrack.straight, tracktype::straight, "track_straight" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s::::,%s,%s", wTrack.name(), wTrack.curve, tracktype::curve, "track_curve" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s::::,%s,%s", wTrack.name(), wTrack.dcurve, tracktype::dcurve, "track_dcurve" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s::::,%s,%s", wTrack.name(), wTrack.buffer, tracktype::buffer, "track_buffer" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s::::,%s,%s", wTrack.name(), wTrack.dir, tracktype::dir, "track_dir" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s::::,%s,%s", wTrack.name(), wTrack.dirall, tracktype::dirall, "track_dirall" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s::::,%s,%s", wTrack.name(), wTrack.connector, tracktype::connector, "track_connector" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s::::,%s,%s", wTrack.name(), wTrack.concurveright, tracktype::connector_curve_right, "track_connector_right" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s::::,%s,%s", wTrack.name(), wTrack.concurveleft, tracktype::connector_curve_left, "track_connector_left" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:2:::,%s,%s", wTrack.name(), wTrack.tracknr, "track-2.svg", "track_tunnel" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:3:::,%s,%s", wTrack.name(), wTrack.tracknr, "track-3.svg", "track_tunnel" );
  ListOp.add( m_SymbolList, (obj) symname );

  // Switch
  symname = StrOp.fmt("%s:%s::::,%s,%s", wSwitch.name(), wSwitch.left, switchtype::turnoutleft_route, "switch_left" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s::::,%s,%s", wSwitch.name(), wSwitch.right, switchtype::turnoutright_route, "switch_right" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s::::,%s,%s", wSwitch.name(), wSwitch.threeway, switchtype::threeway_route, "threeway" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s::::,%s,%s", wSwitch.name(), wSwitch.twoway, switchtype::twoway_tr_route, "twoway" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s::::,%s,%s", wSwitch.name(), wSwitch.ccrossing, switchtype::ccrossing, "ccrossing" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:rect:::,%s,%s", wSwitch.name(), wSwitch.crossing, switchtype::crossing, "crossing" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:left:::,%s,%s", wSwitch.name(), wSwitch.crossing, switchtype::crossingright0m, "crossing_right" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:right:::,%s,%s", wSwitch.name(), wSwitch.crossing, switchtype::crossingleft0m, "crossing_left" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:left:::,%s,%s", wSwitch.name(), wSwitch.dcrossing, switchtype::dcrossingright_route, "dcrossing_right" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:right:::,%s,%s", wSwitch.name(), wSwitch.dcrossing, switchtype::dcrossingleft_route, "dcrossing_left" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s::::,%s,%s", wSwitch.name(), wSwitch.decoupler, switchtype::decoupler, "decoupler" );
  ListOp.add( m_SymbolList, (obj) symname );

  // Signal
  symname = StrOp.fmt("%s:%s:%s:::,%s,%s", wSignal.name(), wSignal.light, wSignal.distant, signaltype::signaldistant_2_r, "distant_signal" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:%s:::,%s,%s", wSignal.name(), wSignal.light, wSignal.main, signaltype::signalmain_r, "main_signal" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:%s::2:,%s,%s", wSignal.name(), wSignal.light, wSignal.main, signaltype::signalmain_2_r, "main_signal" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:%s:%s::,%s,%s", wSignal.name(), wSignal.light, wSignal.main, "dwarf", signaltype::signalmain_dwarf_r, "dwarfsignal" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:%s:::,%s,%s", wSignal.name(), wSignal.light, wSignal.shunting, signaltype::signalshunting_2_r, "shunting_signal" );
  ListOp.add( m_SymbolList, (obj) symname );

  symname = StrOp.fmt("%s:%s:%s:::,%s,%s", wSignal.name(), wSignal.semaphore, wSignal.distant, signaltype::semaphoredistant_2_r, "semaphore_distant" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:%s:::,%s,%s", wSignal.name(), wSignal.semaphore, wSignal.main, signaltype::semaphoremain_r, "semaphore_main" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:%s::2:,%s,%s", wSignal.name(), wSignal.semaphore, wSignal.main, signaltype::semaphoremain_2_r, "semaphore_main" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:%s:::,%s,%s", wSignal.name(), wSignal.semaphore, wSignal.shunting, signaltype::semaphoreshunting_2_r, "semaphore_shunting" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:%s:::,%s,%s", wSignal.name(), wSignal.light, wSignal.blockstate, signaltype::blockstate, "blockstate_signal" );
  ListOp.add( m_SymbolList, (obj) symname );

  // Block
  symname = StrOp.fmt("%s:::::,%s,%s", wBlock.name(), blocktype::block, "block" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s::::,%s,%s", wBlock.name(), "smallsymbol", blocktype::block_s, "block_small" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:::::,%s,%s", wStage.name(), stagetype::stage, "stagingblock" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:::::,%s,%s", wSelTab.name(), seltabtype::seltab, "seltab" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:::::,%s,%s", wTurntable.name(), turntabletype::turntable, "turntable" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s::::,%s,%s", wTurntable.name(), "traverser", traversertype::traverser, "traverser" );
  ListOp.add( m_SymbolList, (obj) symname );

  // Sensor
  symname = StrOp.fmt("%s::::::,%s,%s", wFeedback.name(), feedbacktype::sensor_off, "sensor" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s::%s:::,%s,%s", wFeedback.name(), "curve", feedbacktype::curve_sensor_off, "sensor_curve" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s::4:::,%s,%s", wFeedback.name(), "accessory-4-off.svg", "sensor_notrack" );
  ListOp.add( m_SymbolList, (obj) symname );

  symname = StrOp.fmt("%s:::::,%s,%s", wOutput.name(), outputtype::button, "output" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s::1:::,%s,%s", wOutput.name(), "button-1-off.svg", "output" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s::4:::,%s,%s", wOutput.name(), "button-4-off.svg", "output" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s::5:::,%s,%s", wOutput.name(), "button-5-off.svg", "output" );
  ListOp.add( m_SymbolList, (obj) symname );

  // Accessory
  symname = StrOp.fmt("%s:::::,%s,%s", wText.name(), "text", "text" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:10:::,%s,%s", wSwitch.name(), wSwitch.accessory, "accessory-10-off.svg", "level_crossing" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:11:::,%s,%s", wSwitch.name(), wSwitch.accessory, "accessory-11-off.svg", "level_crossing" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:12:::,%s,%s", wSwitch.name(), wSwitch.accessory, "accessory-12-off.svg", "level_crossing" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:51:::,%s,%s", wSwitch.name(), wSwitch.accessory, "accessory-51-off.svg", "building" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:52:::,%s,%s", wSwitch.name(), wSwitch.accessory, "accessory-52-off.svg", "platform" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:53:::,%s,%s", wSwitch.name(), wSwitch.accessory, "accessory-53-off.svg", "building" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:54:::,%s,%s", wSwitch.name(), wSwitch.accessory, "accessory-54-off.svg", "industry" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:40:::,%s,%s", wSwitch.name(), wSwitch.accessory, "accessory-40-on.svg", "bascule_bridge" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:41:::,%s,%s", wSwitch.name(), wSwitch.accessory, "accessory-41-on.svg", "bascule_bridge" );
  ListOp.add( m_SymbolList, (obj) symname );

  // Road
  symname = StrOp.fmt("%s:%s:::road:,%s,%s", wTrack.name(), wTrack.straight, tracktype::road_straight, "road_straight" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:::road:,%s,%s", wTrack.name(), wTrack.curve, tracktype::road_curve, "road_curve" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:::road:,%s,%s", wTrack.name(), wTrack.dcurve, tracktype::road_dcurve, "road_dcurve" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:::road:,%s,%s", wTrack.name(), wTrack.dir, tracktype::road_dir, "road_dir" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:::road:,%s,%s", wTrack.name(), wTrack.dirall, tracktype::road_dirall, "road_dirall" );
  ListOp.add( m_SymbolList, (obj) symname );

  symname = StrOp.fmt("%s:%s:::road:,%s,%s", wSwitch.name(), wSwitch.left, switchtype::road_turnoutleft, "road_switch_left" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:::road:,%s,%s", wSwitch.name(), wSwitch.right, switchtype::road_turnoutright, "road_switch_right" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:::road:,%s,%s", wSwitch.name(), wSwitch.crossing, switchtype::road_crossing90, "road_crossing" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:::road:,%s,%s", wSwitch.name(), wSwitch.threeway, switchtype::road_rect_threeway, "road_threeway" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:::road:,%s,%s", wSwitch.name(), wSwitch.dcrossing, switchtype::road_dcrossingright, "road_dcrossing" );
  ListOp.add( m_SymbolList, (obj) symname );

  symname = StrOp.fmt("%s:%s:%s::road:,%s,%s", wSignal.name(), wSignal.light, wSignal.main, signaltype::road_signalmain_r, "road_signal_main" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s:%s:%s:%s:road:,%s,%s", wSignal.name(), wSignal.light, wSignal.main, "dwarf", signaltype::road_signalmain_dwarf_r, "road_signal_dwarf" );
  ListOp.add( m_SymbolList, (obj) symname );

  symname = StrOp.fmt("%s::::road:,%s,%s", wBlock.name(), blocktype::road_block, "road_block" );
  ListOp.add( m_SymbolList, (obj) symname );
  symname = StrOp.fmt("%s::::road:,%s,%s", wFeedback.name(), feedbacktype::road_sensor_off, "road_sensor" );
  ListOp.add( m_SymbolList, (obj) symname );


  initGrid();

  for( int i = 0; i < ListOp.size(m_SymbolList); i++) {
    StrOp.free((char*)ListOp.get(m_SymbolList, i));
  }
  ListOp.base.del(m_SymbolList);
}

void TrackPickerDlg::onTrackCellLeftClick( wxGridEvent& event ) {
  wxString str = ((wxGrid*)event.GetEventObject())->GetCellValue( event.GetRow(), 0 );
  ((wxGrid*)event.GetEventObject())->SetGridCursor(event.GetRow(), 0);

  CellRenderer* renderer = (CellRenderer*)((wxGrid*)event.GetEventObject())->GetCellRenderer(event.GetRow(),0);
  if( renderer->GetTip() != NULL) {
    TraceOp.trc( "trackpicker", TRCLEVEL_DEBUG, __LINE__, 9999, "cell tip is [%s] at row %d", renderer->GetTip(), event.GetRow());
    m_Tip->SetValue(wxGetApp().getMsg( renderer->GetTip() ));
  }
  else
    m_Tip->SetValue(str);

  wxString my_text = wxT("addsymbol:") + str;
  TraceOp.trc( "trackpicker", TRCLEVEL_DEBUG, __LINE__, 9999, "drag [%s]", (const char*)my_text.mb_str(wxConvUTF8) );
  wxTextDataObject my_data(my_text);
  wxDropSource dragSource( this );
  dragSource.SetData( my_data );
  wxDragResult result = dragSource.DoDragDrop(wxDrag_CopyOnly);
  Raise();
  event.Skip();
}

void TrackPickerDlg::onPageChanged( wxListbookEvent& event ) {
  int selpage = event.GetSelection();
  TraceOp.trc( "trackpicker", TRCLEVEL_DEBUG, __LINE__, 9999, "selected page %d", selpage );
  wxGrid* grid = NULL;
  switch( selpage ) {
  case 1: grid = m_GridSwitch; break;
  case 2: grid = m_GridSignal; break;
  case 3: grid = m_GridBlock; break;
  case 4: grid = m_GridSensor; break;
  case 5: grid = m_GridAccessory; break;
  case 6: grid = m_GridRoad; break;
  default: grid = m_GridTrack; break;
  }

  for( int i = 0; i < grid->GetNumberRows(); i++ ) {
    CellRenderer* renderer = (CellRenderer*)grid->GetCellRenderer(i,0);
    grid->SetRowSize(i,renderer->GetRowSize());
    TraceOp.trc( "trackpicker", TRCLEVEL_DEBUG, __LINE__, 9999, "rowsize=%d page=%d row=%d", renderer->GetRowSize(), selpage, i );
  }
  grid->ForceRefresh();
  m_Tip->SetValue(wxT(""));
}

void TrackPickerDlg::onClose( wxCloseEvent& event ) {
  iONode window = wGui.getwindow(wxGetApp().getFrame()->m_Ini);
  if( window == NULL ) {
    window = NodeOp.inst( wWindow.name(), wGui.getwindow(wxGetApp().getFrame()->m_Ini), ELEMENT_NODE);
    NodeOp.addChild( wGui.getwindow(wxGetApp().getFrame()->m_Ini), window );
  }
  int x,y;
  GetPosition(&x,&y);

  TraceOp.trc( "trackpicker", TRCLEVEL_DEBUG, __LINE__, 9999, "save position: x=%d, y=%d", x, y );
  wWindow.setxtp(window, x);
  wWindow.setytp(window, y);

  wxGetApp().getFrame()->resetTrackPickerRef();
  Destroy();
}


void TrackPickerDlg::onHelp( wxCommandEvent& event ) {
  wxGetApp().openLink( "rocgui-menu", "additem" );

}


